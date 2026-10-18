// StringIdInterfaceBase/Interface: layout from 14084ee20 and 141024e60.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
class CInPacket;
class StringIdInterfaceBase {
public:
    StringIdInterfaceBase();                           // 0x14084ee20 (empty, filled by the packet reader 0x14084f390)
    StringIdInterfaceBase(CStringW text);              // 0x14084f0e0 (formatted = false; the callee destroys `text`)
    StringIdInterfaceBase(int kind, int id);           // 0x14084ee90 (formatted = true)
    StringIdInterfaceBase(int kind, int id, const CStringW& argument);   // 0x14084ef10
    StringIdInterfaceBase(int kind, int id, const ATL::CAtlArray<CStringW>& args);   // 0x14084efb0
    StringIdInterfaceBase(int kind, CStringW text);    // 0x14084f050 (formatted = false)
    StringIdInterfaceBase(const StringIdInterfaceBase& other);   // 0x14084f170
    StringIdInterfaceBase& operator=(const StringIdInterfaceBase& other);   // 0x14084f1e0
    virtual ~StringIdInterfaceBase();
    int kind, id;
    ATL::CAtlArray<CStringW> arguments;
    bool formatted;
    CStringW text;
};
class StringIdInterface : public StringIdInterfaceBase {
public:
    StringIdInterface(const StringIdInterfaceBase& base); // 141024dc0
    explicit StringIdInterface(CInPacket&); // 141024e00
    virtual ~StringIdInterface(); // 1407ab030
    CStringW FUN_141024e60();
};
MS2_CHECK_SIZE(StringIdInterfaceBase, 0x40);
MS2_CHECK_SIZE(StringIdInterface, 0x40);
MS2_CHECK_OFFSET(StringIdInterfaceBase, arguments, 0x10);
MS2_CHECK_OFFSET(StringIdInterfaceBase, text, 0x38);
