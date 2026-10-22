// uicubeugchead.h - UICubeUGCHead (RTTI .?AVUICubeUGCHead@@, 0x90 bytes, UIObject): the "CubeUGCHead" label above a cube
// ("ID:<n>" plus the cube's name, ui id 0x4e63). Owning unit: ?\uicubeugchead.cpp (0x141906490-0x141906f30). Header name
// assumed from the unit path. Sibling of UIDebugTooltip (same swf). vftable 53 slots; 52 is its own virtual.
#pragma once
#include "ms2/placeholder/uiobject.h"
#include "ms2/placeholder/nipoint3.h"

struct Unk_UgcCell { int x, y, z; };                                // the integer cube point of a cell (0x1408a0400)

class UICubeUGCHead : public UIObject
{
public:
    UICubeUGCHead(Unk_UgcCell cell, CStringW strName, int nType);   // 0x141906490
    virtual ~UICubeUGCHead();                                       //  0 0x141906d90 (??_G 0x141906dc0)
    virtual CString GetTypeName();                                      //  1 0x1419065a0 "CubeUGCHead"
    virtual void vfunc_2();                                         //  2 0x141906730 show
    virtual void vfunc_3();                                         //  3 0x141906790 hide
    virtual void vfunc_15();                                        // 15 0x141906a80 per-frame update
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141906b10
    virtual void vfunc_41(const Scaleform::GFx::Value& root);       // 41 0x141906d20 movie loaded: m_30 = new ASGameEntity
    // @0x141906e00
    virtual int vfunc_48() { return 0x4e63; }                       // 48
    virtual void vfunc_52();                                        // 52 0x1419067d0 push the texts to the movie

    int FUN_1419065f0();                                            // m_80 (shown)
    void FUN_141906610(int nId);                                    // m_88 = nId; m_84 = m_80 = 1
    void FUN_141906650();                                           // m_84 = m_80 = 0
    void FUN_141906680();                                           // hide the movie and reset
    int FUN_1419066c0();                                           // the label is allowed to show
    void FUN_141906b60();                                           // project the cell to the screen and move the movie

private:
    MS2_LAYOUT_FRIEND;
    Unk_UgcCell m_68;                   // +0x68 the cell
    int m_pad_74;
    CStringW m_78;                      // +0x78 the cube's name
    int m_80;                           // +0x80 shown
    int m_84;                           // +0x84 texts dirty
    int m_88;                           // +0x88 cube id
    int m_8c;                           // +0x8c cube kind
};
MS2_CHECK_SIZE(UICubeUGCHead, 0x90);
MS2_CHECK_OFFSET(UICubeUGCHead, m_68, 0x68);
MS2_CHECK_OFFSET(UICubeUGCHead, m_78, 0x78);
MS2_CHECK_OFFSET(UICubeUGCHead, m_8c, 0x8c);
