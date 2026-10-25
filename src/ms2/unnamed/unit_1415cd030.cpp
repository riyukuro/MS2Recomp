// Recovered file download session request dispatch wrappers.
// MS2-UNIT: unit_1415cd030
// MS2-RANGE: 0x1415cd030-0x1415cd3e0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmobjects.h"
#include <cstring>
#include <vector>

static unsigned int nm_download_session_serial(const void* session)
{
    return *reinterpret_cast<const unsigned int*>(static_cast<const char*>(session) + 0x18c);
}

// MS2-FUNCTIONAL: dispatches the recovered download control type with the current session serial.
// @0x1415cd0a0
unsigned int FUN_1415cd0a0(void* session, unsigned int value)
{
    CNMFDSControlFunc request(nm_download_session_serial(session), 1, static_cast<int>(value));
    return static_cast<unsigned int>(CNMManager::GetInstance()->CallNMFunc(&request));
}

// MS2-FUNCTIONAL: dispatches the recovered download control type with the current session serial.
// @0x1415cd110
unsigned int FUN_1415cd110(void* session, unsigned int value)
{
    CNMFDSControlFunc request(nm_download_session_serial(session), 2, static_cast<int>(value));
    return static_cast<unsigned int>(CNMManager::GetInstance()->CallNMFunc(&request));
}

// MS2-FUNCTIONAL: dispatches the recovered download control type with the current session serial.
// @0x1415cd180
unsigned int FUN_1415cd180(void* session, unsigned int value)
{
    CNMFDSControlFunc request(nm_download_session_serial(session), 3, static_cast<int>(value));
    return static_cast<unsigned int>(CNMManager::GetInstance()->CallNMFunc(&request));
}

// MS2-FUNCTIONAL: returns the decoded file events when the request is delivered.
// @0x1415cd1f0
bool FUN_1415cd1f0(void* session, std::vector<CNMFileEvent>* events)
{
    CNMFUDSGetFileEventFunc request(nm_download_session_serial(session));
    const int delivered = CNMManager::GetInstance()->CallNMFunc(&request);
    if (delivered) *events = request.m_30;
    return delivered != 0;
}

// MS2-FUNCTIONAL: copies the decoded fixed-size download directory field to the caller's buffer.
// @0x1415cd290
unsigned int FUN_1415cd290(void* session, char* directory)
{
    CNMFDSGetDownloadDirFunc request(nm_download_session_serial(session));
    if (!CNMManager::GetInstance()->CallNMFunc(&request)) return 0;
    std::memcpy(directory, request.m_30, sizeof(request.m_30));
    return 1;
}

// MS2-FUNCTIONAL: sends the recovered set-download-directory request.
// @0x1415cd350
unsigned int FUN_1415cd350(void* session, const char* directory)
{
    CNMFDSSetDownloadDirFunc request(nm_download_session_serial(session), directory);
    return static_cast<unsigned int>(CNMManager::GetInstance()->CallNMFunc(&request));
}
