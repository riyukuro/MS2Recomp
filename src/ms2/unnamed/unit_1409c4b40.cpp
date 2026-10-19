// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Writes a shell-open command registration for one
// key path: it opens the key and its "DefaultIcon"/"shell"/"open"/"command" subkeys, stores the description strings
// and finally the formatted command line, with a registry-key hand-holder whose destructor closes the handle.
// MS2-UNIT: unit_1409c4b40
// MS2-RANGE: 0x1409c4b40-0x1409c5210 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include <efd/StringUtilities.h>

static int s_flag_143ab4330;                                    // 0x143ab4330

// HKEY hand-holder (the exe's CRegKey-shaped helper): ctor zeroes the handle, dtor closes it.
class Unk_1409c4ef0
{
public:
    Unk_1409c4ef0();                                            // 0x1409c4ef0
    ~Unk_1409c4ef0();                                           // 0x1409c4f10
    operator PHKEY();                                           // 0x1409c4f40
    bool IsOpen();                                              // 0x1409c4f60
    bool Create(HKEY hKeyParent, LPCSTR lpszKeyName);           // 0x1409c4fa0
    bool SetStringValue(LPCSTR pszValueName, const char* pszValue);   // 0x1409c5040
    HKEY m_hKey;                                                // +0x00
};

// @0x1409c4b40
bool FUN_1409c4b40(LPCSTR pszKeyPath, LPCSTR pszExe, LPCSTR pszArgs, LPCSTR pszValue1, LPCSTR pszValue2,
                   LPCSTR pszValue3)
{
    Unk_1409c4ef0 key1;
    key1.Create(HKEY_CLASSES_ROOT, pszKeyPath);
    if (!key1.SetStringValue("", pszValue1)) {
        return false;
    }
    Unk_1409c4ef0 key2;
    key2.Create(HKEY_CLASSES_ROOT, pszValue1);
    if (!key2.SetStringValue("", pszValue2)) {
        return false;
    }
    Unk_1409c4ef0 key3;
    key3.Create(*key2, "DefaultIcon");
    if (!key3.SetStringValue("", pszValue3)) {
        return false;
    }
    Unk_1409c4ef0 key4;
    if (!key4.Create(*key2, "shell")) {
        return false;
    }
    Unk_1409c4ef0 key5;
    if (!key5.Create(*key4, "open")) {
        return false;
    }
    Unk_1409c4ef0 key6;
    if (!key6.Create(*key5, "command")) {
        return false;
    }
    char szCommand[1024];
    efd::Sprintf(szCommand, 0x400, "\"%s\" %s \"%%1\"", pszExe, pszArgs != NULL ? pszArgs : "");
    return key6.SetStringValue("", szCommand);
}

// @0x1409c4ef0
Unk_1409c4ef0::Unk_1409c4ef0()
{
    m_hKey = NULL;
}

// @0x1409c4f10
Unk_1409c4ef0::~Unk_1409c4ef0()
{
    RegCloseKey(m_hKey);
}

// @0x1409c4f40
Unk_1409c4ef0::operator PHKEY()
{
    return &m_hKey;
}

// @0x1409c4f60
bool Unk_1409c4ef0::IsOpen()
{
    return m_hKey != NULL;
}

// @0x1409c4fa0
bool Unk_1409c4ef0::Create(HKEY hKeyParent, LPCSTR lpszKeyName)
{
    if (IsOpen()) {
        RegCloseKey(m_hKey);
        m_hKey = NULL;
    }
    if (RegCreateKeyExA(hKeyParent, lpszKeyName, 0, NULL, 0, KEY_ALL_ACCESS, NULL, &m_hKey, NULL) ==
        ERROR_SUCCESS) {
        return true;
    }
    return false;
}

// @0x1409c5040
bool Unk_1409c4ef0::SetStringValue(LPCSTR pszValueName, const char* pszValue)
{
    if (!IsOpen()) {
        return false;
    }
    if (RegSetValueExA(m_hKey, pszValueName, 0, REG_SZ, (const BYTE*)pszValue, (DWORD)strlen(pszValue)) ==
        ERROR_SUCCESS) {
        return true;
    }
    return false;
}

// @0x1409c50d0
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);

void FUN_1409c51f0(void);
#ifndef MS2_HOOK_DLL
// @0x1409c51f0
void FUN_1409c51f0(void)
{
    s_flag_143ab4330 = 0;
}
#endif
