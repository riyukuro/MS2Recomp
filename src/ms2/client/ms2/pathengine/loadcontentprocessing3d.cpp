// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). PathEngine glue: loading ContentProcessing3D.dll (an
// older PathEngine loader than the SDK in third_party: loaddll.h helpers plus the sample error/assert handlers that
// report through message boxes). Nothing here is SDK text; see pathengineglue.h.
// MS2-UNIT: client\ms2\pathengine\loadcontentprocessing3d.cpp
// MS2-RANGE: 0x141641150-0x141642030 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\pathengine\\loadcontentprocessing3d.cpp"
#define NOMINMAX
#include "ms2/placeholder/ms2stdafx.h"
#include "pathengineglue.h"

#include <windows.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sstream>

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

bool HandleAssertion(const char* file, long line, const char* comment);

// The sample's assertD: reports once per site until the user answers No. The exe keeps the original build paths.
#define MS2_PE_ASSERTD(file, line, expr)                                                                             \
    {                                                                                                                \
        static bool reportThis = true;                                                                               \
        if (reportThis && !(expr))                                                                                   \
            reportThis = HandleAssertion(file, line, #expr);                                                         \
    }
#define MS2_PE_CPP_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\pathengine\\loadcontentprocessing3d.cpp"
#define MS2_PE_LOADDLL_H "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\pathengine\\loaddll.h"

static HMODULE gContentProcessing3DModule;

// The DLL's root export (ordinal 2): the first interface is only tested for null by the client.
typedef void (*tGetRootInterfaces)(iErrorHandler*, void*&, iContentProcessing3D*&);

bool LoadDLL(const char* fileName, HMODULE& module, std::string& errorInfo);
void GetRootInterfaces(HMODULE module, std::string& errorInfo, iErrorHandler* errorHandler, void*& root,
                       iContentProcessing3D*& contentProcessing);
void UnloadDLL(HMODULE module);
void ReleaseRootInterfaces(HMODULE module);
void Error(const char* errorType, const char* errorString, const char* const* attributes);

// @0x141641150
void LoadContentProcessing3D(const char* fileName, iErrorHandler* errorHandler, void*& root,
                             iContentProcessing3D*& contentProcessing)
{
    MS2_PE_ASSERTD(MS2_PE_CPP_FILE, 16, fileName);
    std::string errorInfo;
    const char* attributes[] = {"dllFileName", 0, "errorInfo", 0, 0};
    attributes[1] = fileName;
    bool loaded = LoadDLL(fileName, gContentProcessing3DModule, errorInfo);
    if (!loaded)
    {
        attributes[3] = errorInfo.c_str();
        Error("NonFatal", "Error: failed to load Content Processing 3D DLL", attributes);
        return;
    }
    GetRootInterfaces(gContentProcessing3DModule, errorInfo, errorHandler, root, contentProcessing);
    if (root == 0)
    {
        attributes[3] = errorInfo.c_str();
        Error("NonFatal", "Error: failed to get root interface from Content Processing 3D DLL", attributes);
        UnloadDLL(gContentProcessing3DModule);
        return;
    }
}

// @0x141641330
iContentProcessing3D* LoadContentProcessing3D(const char* fileName, iErrorHandler* errorHandler)
{
    void* root;
    iContentProcessing3D* result;
    LoadContentProcessing3D(fileName, errorHandler, root, result);
    return result;
}

// @0x141641370
void UnloadContentProcessing3D()
{
    ReleaseRootInterfaces(gContentProcessing3DModule);
    UnloadDLL(gContentProcessing3DModule);
}

// loaddll.h

// @0x1416413a0
void UnloadDLL(HMODULE module)
{
    BOOL result = FreeLibrary(module);
    MS2_PE_ASSERTD(MS2_PE_LOADDLL_H, 39, result != 0);
}

void FormatError(char* buffer, const char* format, ...);

// @0x1416413f0
void GetRootInterfaces(HMODULE module, std::string& errorInfo, iErrorHandler* errorHandler, void*& root,
                       iContentProcessing3D*& contentProcessing)
{
    root = 0;
    contentProcessing = 0;
    errorInfo.clear();
    SetLastError(0);
    FARPROC procAddress = GetProcAddress(module, (LPCSTR)2);
    if (procAddress == 0)
    {
        DWORD lastError = GetLastError();
        char buffer[100];
        FormatError(buffer, "GetLastError(): %d", lastError);
        errorInfo = buffer;
        return;
    }
    tGetRootInterfaces getRootInterfaces = (tGetRootInterfaces)procAddress;
    getRootInterfaces(errorHandler, root, contentProcessing);
}

// @0x1416414f0
bool LoadDLL(const char* fileName, HMODULE& module, std::string& errorInfo)
{
    errorInfo.clear();
    module = LoadLibraryA(fileName);
    if (module == 0)
    {
        DWORD lastError = GetLastError();
        char buffer[100];
        FormatError(buffer, "GetLastError(): %d", lastError);
        errorInfo = buffer;
        return false;
    }
    return true;
}

// @0x1416415a0
void FormatError(char* buffer, const char* format, ...)
{
    va_list args;
    va_start(args, format);
    _vsnprintf(buffer, 100, format, args);
}

// @0x1416415e0
void ReleaseRootInterfaces(HMODULE)
{
}

// Error/assert reporting

// @0x1416415f0
void ReportErrorMessage(const char* title, const char* text)
{
    MessageBoxA(0, text, title, MB_TASKMODAL);
}

// @0x141641630
bool AskYesNo(const char* title, const char* question, const char* detail)
{
    std::ostringstream os;
    os << question << std::endl;
    os << detail;
    int answer = MessageBoxA(0, os.str().c_str(), title, MB_TASKMODAL | MB_YESNO);
    return answer == IDYES;
}

// @0x141641b50
void Error(const char* errorType, const char* errorString, const char* const* attributes)
{
    std::ostringstream os;
    os << "Error type: " << errorType << std::endl;
    os << "Error string: " << errorString << std::endl;
    if (attributes && *attributes)
    {
        os << "Error attributes:" << std::endl;
        do
        {
            os << " " << attributes[0] << " = " << attributes[1] << std::endl;
            attributes += 2;
        } while (*attributes);
    }
    ReportErrorMessage("Error", os.str().c_str());
    if (strcmp(errorType, "Fatal") == 0)
    {
        exit(1);
    }
}

// @0x141641d90
void HandleTestFailure(const char* file, long line, const char* comment)
{
    std::ostringstream os;
    os << file << "(" << line << "): test(" << comment << ")";
    ReportErrorMessage("Test case failed, aborting.", os.str().c_str());
    exit(1);
}

// @0x141641ec0
bool HandleAssertion(const char* file, long line, const char* comment)
{
    std::ostringstream os;
    os << file << "(" << line << "): assertD(" << comment << ")" << std::endl;
    os << std::endl;
    os << "Application execution will continue, but this may result in a crash." << std::endl;
    bool result = AskYesNo("Assertion failed", os.str().c_str(),
                           "Select Yes to continue to report this assertion in the future, or No to stop checking this.");
    return result;
}

typedef void tLoadContentProcessing3D(const char*, iErrorHandler*, void*&, iContentProcessing3D*&);
typedef iContentProcessing3D* tLoadContentProcessing3DResult(const char*, iErrorHandler*);

MS2_REPLACE_OVERLOAD(0x141641150, tLoadContentProcessing3D, LoadContentProcessing3D, 462, 0xB36C5E8A);
MS2_REPLACE_OVERLOAD(0x141641330, tLoadContentProcessing3DResult, LoadContentProcessing3D, 49, 0x38DC2849);
MS2_REPLACE(0x141641370, UnloadContentProcessing3D, 33, 0xB3A17BD4);
MS2_REPLACE(0x1416413A0, UnloadDLL, 77, 0x51EF5CC6);
MS2_REPLACE(0x1416413F0, GetRootInterfaces, 242, 0xF31444C2);
MS2_REPLACE(0x1416414F0, LoadDLL, 172, 0x8A077F82);
MS2_REPLACE(0x1416415A0, FormatError, 64, 0xB9C01FD0);
MS2_REPLACE(0x1416415F0, ReportErrorMessage, 43, 0xF3221C58);
MS2_REPLACE(0x141641630, AskYesNo, 271, 0xFA4A8F83);
MS2_REPLACE(0x141641B50, Error, 562, 0x98BCBFE8);
MS2_REPLACE(0x141641D90, HandleTestFailure, 248, 0xC77A3E05);
MS2_REPLACE(0x141641EC0, HandleAssertion, 362, 0xBDE3EFEB);
