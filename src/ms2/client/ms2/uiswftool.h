// uiswftool.h - UISwfTool (RTTI .?AVUISwfTool@@, 0x68 bytes: UIObject with no fields of its own), the swf debug
// tool object (class name "SwfTool", UI type id 0x4e54). Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13);
// the unit is `?\uiswftool.cpp` (0x141b127f0-0x141b12ad0 .text$mn, dir client\ms2). Header/unit name assumed; the
// class has no __FILE__ string.
//
// Bases: UIObject (src/ms2/client/ms2/uiobject.h) -> UISwfEntity -> CPtred, IMessageListener. Primary vftable
// 0x142fe67f8 (52 slots), IMessageListener-in-UISwfTool 0x142fe69a0. Overridden slots: 1 (class name), 43 (the
// tool arranges the loaded movie), 48 (UI type id).
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uiobject.h"

class UISwfTool : public UIObject
{
public:
    UISwfTool();                                        // @0x141b127f0
    virtual ~UISwfTool();                               // 0  @0x141b12840 (??_G 0x141b12960)
    virtual CString GetTypeName();                          // 1  @0x141b12880: "SwfTool"
    virtual void vfunc_43();                            // 43 @0x141b128d0 (the swf tool's debug arrangement)
    virtual int vfunc_48();                             // 48 @0x141b129a0: the UI type id, 0x4e54
};
MS2_CHECK_SIZE(UISwfTool, 0x68);
