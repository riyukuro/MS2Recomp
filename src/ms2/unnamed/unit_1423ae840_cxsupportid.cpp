// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The machine-id helpers CMachineIDManager::BuildID calls:
// the hardware/support id (GetAdaptersInfo, the volume serial, the CxSupportId registry value) and the PC-bang
// (internet cafe) program check. An /O2 obj of its own between the Gamebryo libraries' Lua and expat objs, so it is
// built with the gamebryo profile. Names invented.
// MS2-UNIT: unit_1423ae840
// MS2-RANGE: 0x1423ae840-0x1423ae958 .text$mn
// MS2-RANGE: 0x1423ae960-0x1423b1076 .text$mn
// MS2-RANGE: 0x1423b1080-0x1423b1479 .text$mn
// MS2-FLAGS: gamebryo
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/guess/machineidmanager.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

#include <iphlpapi.h>
// The exe calls GetAdaptersInfo through its import thunk (0x14280ef28): redeclare it without dllimport
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winconsistent-dllimport"
#else
#pragma warning(push)
#pragma warning(disable : 4273)  // inconsistent dll linkage: intended
#endif
extern "C" ULONG WINAPI GetAdaptersInfo(PIP_ADAPTER_INFO AdapterInfo, PULONG SizePointer);
#if defined(__clang__)
#pragma clang diagnostic pop
#else
#pragma warning(pop)
#endif
#include <tlhelp32.h>
#include <mbstring.h>
#pragma comment(lib, "iphlpapi.lib")

// The hardware id inside the working object.
// @0x1423b1080
void* FUN_1423b1080(Unk_MachineIDLocal* pLocal)
{
    return pLocal->m_data + 0x18;
}

// The machine id of the (otherwise unrecovered) CxSupport id object: the largest Ethernet MAC address, the serial of
// the Windows volume and a weighted sum of the two make the 16-byte hardware id at +0x18; the 16-byte support id at +8
// is a GUID kept in HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\CxSupportId (made and stored on first use), or
// the hardware id when the key cannot be opened.
// MS2-FUNCTIONAL: /O2 body, the exe's register and frame layout are not reproduced yet.
// @0x1423b10a0
void FUN_1423b10a0(Unk_MachineIDLocal* pLocal)
{
    unsigned char id[0x10] = {};
    ULONG adapterLen = 0;
    IP_ADAPTER_INFO* pAdapters = NULL;
    if (GetAdaptersInfo(NULL, &adapterLen) == ERROR_BUFFER_OVERFLOW && adapterLen != 0)
    {
        pAdapters = static_cast<IP_ADAPTER_INFO*>(malloc(adapterLen));
        if (GetAdaptersInfo(pAdapters, &adapterLen) != ERROR_SUCCESS)
        {
            free(pAdapters);
            pAdapters = NULL;
        }
    }
    if (pAdapters != NULL)
    {
        for (IP_ADAPTER_INFO* pAdapter = pAdapters; pAdapter != NULL; pAdapter = pAdapter->Next)
        {
            if (pAdapter->Type != MIB_IF_TYPE_ETHERNET)
                continue;
            const BYTE* mac = pAdapter->Address;
            // skip the RAS "DEST" pseudo adapter; keep the largest address
            bool take = !(mac[0] == 'D' && mac[1] == 'E' && mac[2] == 'S' && mac[3] == 'T' && mac[4] == 0 && mac[5] == 0);
            for (unsigned int i = 0; take && i < 6; ++i)
            {
                if (mac[i] > id[i])
                    break;
                take = mac[i] >= id[i];
            }
            if (take)
                memcpy(id, mac, 6);
        }
        free(pAdapters);
    }

    char windowsDir[0x200];
    char volumeName[0x200];
    char fileSystemName[0x200];
    DWORD serial, maxComponentLen, fsFlags;
    GetWindowsDirectoryA(windowsDir, 0x200);
    windowsDir[3] = 0;  // the drive root
    if (GetVolumeInformationA(windowsDir, volumeName, 0x200, &serial, &maxComponentLen, &fsFlags, fileSystemName, 0x200) == TRUE)
        memcpy(id + 6, &serial, 4);
    unsigned short sum = 0;
    for (unsigned int i = 0; i < 6; ++i)
    {
        unsigned short w;
        memcpy(&w, id + 2 * i, 2);
        sum = static_cast<unsigned short>(sum + (i + 3) * w);
    }
    memcpy(id + 0xe, &sum, 2);
    memcpy(pLocal->m_data + 0x18, id, 0x10);

    HKEY hKey = NULL;
    RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion", 0, KEY_QUERY_VALUE | KEY_SET_VALUE, &hKey);
    if (hKey == NULL)
    {
        memcpy(pLocal->m_data + 8, pLocal->m_data + 0x18, 0x10);
        return;
    }
    unsigned char value[0x200];
    DWORD type, valueLen = 0x100;
    if (RegQueryValueExA(hKey, "CxSupportId", NULL, &type, value, &valueLen) == ERROR_SUCCESS && valueLen == 0x10)
    {
        memcpy(pLocal->m_data + 8, value, 0x10);
    }
    else
    {
        CoCreateGuid(reinterpret_cast<GUID*>(id));
        RegSetValueExA(hKey, "CxSupportId", 0, REG_BINARY, id, 0x10);
        memcpy(pLocal->m_data + 8, id, 0x10);
    }
    RegCloseKey(hKey);
}

// The PC-bang (internet cafe) check: the known cafe management programs, each an exe name, a text its windows' titles
// contain and the 4-character code the check returns for it.
struct Unk_PcBangEntry
{
    unsigned int m_code;
    const char* m_exe;
    const char* m_title;
};

static const Unk_PcBangEntry s_pcBangTable[] =
{
    { 0x30304e42, "bluenetterm.exe", "_" },   // BN00
    { 0x30304243, "client.exe", "Cyberria" },   // CB00
    { 0x39394243, "client.exe", "\xc7\xf6\xc0\xe7\xbb\xe7\xbf\xeb\xba\xd0" },   // CB99 현재사용분
    { 0x30304e44, "imgsaver.exe", "\xb0\xd4\xc0\xd3\xbd\xc3\xb0\xa3" },   // DN00 게임시간
    { 0x53325444, "dreamto2000.exe", "DT2000" },   // DT2S
    { 0x38395444, "dttcli.exe", "DT2000" },   // DT98
    { 0x50585444, "svchost.exe", "DT2000" },   // DTXP
    { 0x30304145, "pcbangclient.ex", "PC" },   // EA00
    { 0x30304145, "pcbangclient.exe", "PC" },   // EA00
    { 0x30305045, "epclient.exe", "ePocket" },   // EP00
    { 0x53374247, "gb2001sp.exe", "Gb2001sp" },   // GB7S
    { 0x30304347, "gcsc.exe", "GCSS Client" },   // GC00
    { 0x30304447, "timechk.exe", "TimeCheck" },   // GD00
    { 0x31304447, "client.exe", "\xb0\xd4\xc0\xd3\xb5\xb9\xc0\xcc" },   // GD01 게임돌이
    { 0x30304d47, "peshell.exe", "PESHELLF" },   // GM00
    { 0x30304e47, "client.exe", "\xc1\xf6\xbe\xd8\xc6\xbc\xbe\xbe" },   // GN00 지앤티씨
    { 0x30305347, "gamstar.exe", "\xb0\xd7\xbd\xba\xc5\xb8" },   // GS00 겜스타
    { 0x31305347, "server.exe", "\xb0\xd7\xbd\xba\xc5\xb8" },   // GS01 겜스타
    { 0x32305347, "expl.exe", "\xb0\xd7\xbd\xba\xc5\xb8" },   // GS02 겜스타
    { 0x35325447, "report25.mod", "PC\xb9\xe6" },   // GT25 PC방
    { 0x30335447, "agent30.mod", "\xb0\xd4\xc5\xe4" },   // GT30 게토
    { 0x32335447, "agent32.mod", "\xb0\xd4\xc5\xe4" },   // GT32 게토
    { 0x33335447, "agent33.mod", "\xb0\xd4\xc5\xe4" },   // GT33 게토
    { 0x34335447, "agent34.mod", "\xb0\xd4\xc5\xe4" },   // GT34 게토
    { 0x38335447, "agent38.bin", "\xb0\xd4\xc5\xe4" },   // GT38 게토
    { 0x39335447, "agent391.bin", "\xb0\xd4\xc5\xe4" },   // GT39 게토
    { 0x39335447, "agent392.bin", "\xb0\xd4\xc5\xe4" },   // GT39 게토
    { 0x39335447, "agent39.bin", "\xb0\xd4\xc5\xe4" },   // GT39 게토
    { 0x39335447, "getoman.exe", "\xb0\xd4\xc5\xe4" },   // GT39 게토
    { 0x30345447, "agent40.bin", "\xb0\xd4\xc5\xe4" },   // GT40 게토
    { 0x53345247, "grms.exe", "Grms" },   // GR4S
    { 0x30345247, "gclient.exe", "GClient" },   // GR40
    { 0x30305749, "client.exe", "Main_f" },   // IW00
    { 0x31305749, "client.exe", "Info_f" },   // IW01
    { 0x32305749, "client.exe", "Sharky" },   // IW02
    { 0x33305749, "client.exe", "main_f" },   // IW03
    { 0x39395749, "client.exe", "\xb0\xa3\xb4\xdc\xc7\xd1 \xba\xbc\xb7\xfd\xc1\xb6\xc0\xfd\xb1\xe2" },   // IW99 간단한 볼륨조절기
    { 0x30305049, "ipoclient.exe", "Ipoclient" },   // IP00
    { 0x30305449, "run.exe", "(ITM)" },   // IT00
    { 0x5331474c, "igc_gglm.exe", "LoginGAME" },   // LG1S
    { 0x3631474c, "igc_gglc.exe", "LoginGAME" },   // LG16
    { 0x3030474c, "igc_gglc.exe", "GGLogin" },   // LG00
    { 0x3030594c, "ticclient.exe", "Ticclient" },   // LY00
    { 0x3130594c, "tmsclient.exe", "TMS Client" },   // LY01
    { 0x3037444d, "clmanager.exe", "CLManager" },   // MD70
    { 0x3136444d, "pbclient.exe", "MD CLIENT" },   // MD61
    { 0x3036444d, "pbclient.exe", "\xc5\xac\xb6\xf3\xc0\xcc\xbe\xf0\xc6\xae" },   // MD60 클라이언트
    { 0x3236444d, "pbclient.exe", "MDCLIENT" },   // MD62
    { 0x3336444d, "pbclient.exe", "MDClient" },   // MD63
    { 0x30304d4d, "ex.exe", "FormTime" },   // MM00
    { 0x30304e4d, "mnetc.exe", "\xbb\xe7\xbf\xeb\xc0\xda\xc8\xad\xb8\xe9" },   // MN00 사용자화면
    { 0x4c43434e, "ncclient.exe", "Commander" },   // NCCL
    { 0x4348434e, "ncclient.exe", "\xc4\xbf\xb8\xc7\xb4\xf5" },   // NCHC 커맨더
    { 0x3030434e, "ncclient.exe", "NCClient" },   // NC00
    { 0x4c43454e, "ntmcli.exe", "ntmcli" },   // NECL
    { 0x3130454e, "ismak32.exe", "ismak32" },   // NE01
    { 0x4b50454e, "pkcnt.exe", "Client" },   // NEPK
    { 0x5338544e, "??).exe", "NewTime" },   // NT8S
    { 0x3738544e, "game98c.exe", "NewTime" },   // NT87
    { 0x30304d50, "client.exe", "ITM" },   // PM00
    { 0x30304e53, "netmon.exe", "SmartNet" },   // SN00
    { 0x30304a53, "pcmanager.exe", "\xb0\xd4\xc0\xd3\xb9\xe6" },   // SJ00 게임방
    { 0x30305953, "pcagent.exe", "Synaps" },   // SY00
    { 0x31305953, "pcagent.exe", "PcAgent" },   // SY01
    { 0x30304359, "yecamanagerc.exe", "\xbf\xb9\xc4\xab" },   // YC00 예카
    { 0x3030305a, "gamec.exe", "\xb0\xd4\xc0\xd3\xb9\xe6\xb0\xfc\xb8\xae" },   // Z000 게임방관리
    { 0x3130305a, "pgb_client_mngr.exe", "ClientManager" },   // Z001
    { 0x3230305a, "easyclient.exe", "FormTime" },   // Z002
    { 0x3330305a, "systemcn.exe", "Client" },   // Z003
};

// The table as the exe builds it on the stack (passed to the window callback).
struct Unk_PcBangTable
{
    int m_count;
    unsigned int m_code[0x80];
    char m_exe[0x80][0x20];
    char m_title[0x80][0x20];
};

static const unsigned char* s_pcBangProcess;     // 0x143b103c0: the lower-case exe name of the window's process
static unsigned int s_pcBangCode;                // 0x143b103c8: the code found, 0 if none

// The EnumThreadWindows callback: a window of a known program whose title has the program's text ends the search with
// its code; so does a window titled with "게토" of a process named agent*.
// @0x1423ae840
BOOL CALLBACK FUN_1423ae840(HWND hWnd, LPARAM lParam)
{
    Unk_PcBangTable* pTable = reinterpret_cast<Unk_PcBangTable*>(lParam);
    unsigned char text[0x200];
    GetWindowTextA(hWnd, reinterpret_cast<char*>(text), 0x200);
    for (int i = 0; i < pTable->m_count; ++i)
    {
        if (pTable->m_title != NULL && text[0] != 0
            && _mbsicmp(s_pcBangProcess, reinterpret_cast<const unsigned char*>(pTable->m_exe[i])) == 0
            && _mbsstr(text, reinterpret_cast<const unsigned char*>(pTable->m_title[i])) != NULL)
        {
            s_pcBangCode = pTable->m_code[i];
            return FALSE;
        }
    }
    if (_mbsnbicmp(s_pcBangProcess, reinterpret_cast<const unsigned char*>("agent"), 5) == 0
        && _mbsstr(text, reinterpret_cast<const unsigned char*>("\xb0\xd4\xc5\xe4")) != NULL)
    {
        s_pcBangCode = 0x39395447;  // GT99
        return FALSE;
    }
    return TRUE;
}

// The PC-bang code of this computer: the code of the first known cafe program with a matching window, 0 if none.
// MS2-FUNCTIONAL: /O2 body, the exe inlines the window walk differently; the frame is not reproduced yet.
// @0x1423ae960
unsigned int FUN_1423ae960(Unk_MachineIDLocal* pLocal)
{
    Unk_PcBangTable table;
    table.m_count = 0;
    for (int i = 0; i < static_cast<int>(sizeof(s_pcBangTable) / sizeof(s_pcBangTable[0])) && table.m_count < 0x80; ++i)
    {
        const Unk_PcBangEntry& e = s_pcBangTable[i];
        table.m_code[table.m_count] = e.m_code;
        _mbsnbcpy(reinterpret_cast<unsigned char*>(table.m_exe[table.m_count]), reinterpret_cast<const unsigned char*>(e.m_exe), 0x1f);
        table.m_exe[table.m_count][0x1f] = 0;
        _mbsnbcpy(reinterpret_cast<unsigned char*>(table.m_title[table.m_count]), reinterpret_cast<const unsigned char*>(e.m_title), 0x1f);
        table.m_title[table.m_count][0x1f] = 0;
        ++table.m_count;
    }

    // the running processes: id and lower-case exe name
    int processCount = 0;
    DWORD processIds[0x100];
    unsigned char processNames[0x100][0x20];
    PROCESSENTRY32 process;
    memset(&process.cntUsage, 0, sizeof(process) - sizeof(process.dwSize));
    HANDLE hProcesses = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hProcesses == INVALID_HANDLE_VALUE)
        return 0;
    process.dwSize = sizeof(process);
    if (!Process32First(hProcesses, &process))
        return 0;
    do
    {
        unsigned char* name = _mbsrchr(reinterpret_cast<unsigned char*>(process.szExeFile), '\\');
        name = name != NULL ? name + 1 : reinterpret_cast<unsigned char*>(process.szExeFile);
        _mbslwr(name);
        if (processCount < 0x100)
        {
            processIds[processCount] = process.th32ProcessID;
            _mbsnbcpy(processNames[processCount], name, 0x1f);
            processNames[processCount][0x1f] = 0;
            ++processCount;
        }
    } while (Process32Next(hProcesses, &process));
    CloseHandle(hProcesses);

    // every thread's windows, with the name of the thread's process
    THREADENTRY32 thread;
    memset(&thread.cntUsage, 0, sizeof(thread) - sizeof(thread.dwSize));
    HANDLE hThreads = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
    if (hThreads == INVALID_HANDLE_VALUE)
        return 0;
    thread.dwSize = sizeof(thread);
    if (Thread32First(hThreads, &thread))
    {
        do
        {
            if (thread.th32ThreadID == 0)
                continue;
            const unsigned char* processName = NULL;
            for (int i = 0; i < processCount; ++i)
            {
                if (processIds[i] == thread.th32OwnerProcessID)
                {
                    processName = processNames[i];
                    break;
                }
            }
            s_pcBangProcess = processName;
            if (processName == NULL)
                continue;
            s_pcBangCode = 0;
            EnumThreadWindows(thread.th32ThreadID, FUN_1423ae840, reinterpret_cast<LPARAM>(&table));
            if (s_pcBangCode != 0)
                return s_pcBangCode;
        } while (Thread32Next(hThreads, &thread));
    }
    CloseHandle(hThreads);
    return 0;
}
