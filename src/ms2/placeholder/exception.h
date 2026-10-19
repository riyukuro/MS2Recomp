// Game Exception (not MFC CException). Name and 0x10 size from ThrowInfo 0x1439df1b0.
// CatchableType names .?AVException@@, with copy ctor 0x140203810.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
class Exception {
public:
    // @0x140203810
    Exception(const Exception& rhs):m_code(rhs.m_code),m_message(rhs.m_message){}
    // @0x140203860
    explicit Exception(int code):m_code(code){}
    // @0x1407131b0 (first instantiated by commonfiles\packet.cpp; the message is taken by value)
    Exception(CString message,int code):m_code(code),m_message(message){}
    // @0x14067b950 (first instantiated by commonfiles\luautil.cpp)
    explicit Exception(CString message):m_code(0),m_message(message){}
    // @0x140203af0
    ~Exception(){}
    // 0x140b700e0 (first instantiated by client\ms2\ugcmanager.cpp#1)
    // @0x14067bc30 (out of line in commonfiles\luautil.cpp)
    CString GetText();
    int GetCode() const { return m_code; }
private:
    MS2_LAYOUT_FRIEND;
    int m_code;
    CString m_message;
};
MS2_CHECK_SIZE(Exception,0x10);
MS2_CHECK_OFFSET(Exception,m_message,8);
