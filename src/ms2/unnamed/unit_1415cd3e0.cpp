// Recovered file-upload session request dispatch wrappers.
// MS2-UNIT: unit_1415cd3e0
// MS2-RANGE: 0x1415cd3e0-0x1415cd6f0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmobjects.h"
#include <vector>

static unsigned int nm_general_session_serial(const void* session)
{
    return *reinterpret_cast<const unsigned int*>(static_cast<const char*>(session) + 0x18c);
}

// MS2-FUNCTIONAL: sends the recovered upload request and reads its reply result from the request object.
// @0x1415cd450
unsigned int FUN_1415cd450(void* session, const char* path)
{
    CNMFUSSendFileFunc request(nm_general_session_serial(session), path);
    const int delivered = CNMManager::GetInstance()->CallNMFunc(&request);
    if (!delivered) return 0;
    return *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(&request) + 0x134);
}

// MS2-FUNCTIONAL: dispatches upload control type 1 with the session's current serial.
// @0x1415cd500
unsigned int FUN_1415cd500(void* session, unsigned int value)
{
    CNMFUSControlFunc request(nm_general_session_serial(session), 1, static_cast<int>(value));
    return static_cast<unsigned int>(CNMManager::GetInstance()->CallNMFunc(&request));
}

// MS2-FUNCTIONAL: dispatches upload control type 2 with the session's current serial.
// @0x1415cd570
unsigned int FUN_1415cd570(void* session, unsigned int value)
{
    CNMFUSControlFunc request(nm_general_session_serial(session), 2, static_cast<int>(value));
    return static_cast<unsigned int>(CNMManager::GetInstance()->CallNMFunc(&request));
}

// MS2-FUNCTIONAL: dispatches upload control type 3 with the session's current serial.
// @0x1415cd5e0
unsigned int FUN_1415cd5e0(void* session, unsigned int value)
{
    CNMFUSControlFunc request(nm_general_session_serial(session), 3, static_cast<int>(value));
    return static_cast<unsigned int>(CNMManager::GetInstance()->CallNMFunc(&request));
}

// MS2-FUNCTIONAL: retrieves the decoded file-event vector when the request is delivered.
// @0x1415cd650
bool FUN_1415cd650(void* session, std::vector<CNMFileEvent>* events)
{
    CNMFUDSGetFileEventFunc request(nm_general_session_serial(session));
    const int delivered = CNMManager::GetInstance()->CallNMFunc(&request);
    if (delivered) *events = request.m_30;
    return delivered != 0;
}
