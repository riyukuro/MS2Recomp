// CItemExtraData: RTTI table 0x142d61678, allocation size 0x58 in 0x14053e6c0. The per-item colouring state of an item
// instance: the equip colours (EquipColorInfo, 0x30 bytes) of its palette slots, plus the decal / hair / cap extras.
// Recovered from ?\itemextradata.cpp (commonfiles; 0x140598b80-0x14059dcd0).
#pragma once
#include <vector>
#include <atlcoll.h>
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/socketptr.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/commonfiles/stream.h"
class ItemColorEx;
class CItemData;
template <class T> class MS2Ptr;

// One colour slot: three palette values, the running palette index and the delay (ctor 0x140598b80).
class EquipColorInfo : public CPtred {
public:
    EquipColorInfo();                                            // 0x140598b80
    void FUN_140598bf0(COutputStream& os);                       // write the slot
    void FUN_140598c80(CInputStream& is);                        // read the slot
    void FUN_140598d10(Unk_SocketPtr<EquipColorInfo> spSrc);     // copy the slot of another (null: nothing)
    void FUN_140598de0(const ItemColorEx& kColor, int nDelay);   // take the values of a palette colour
    int m_aRgb[3];                                               // +0x18
    int m_n24;                                                   // +0x24 palette colour id (-1)
    int m_n28;                                                   // +0x28
    int m_n2c;                                                   // +0x2c
};
MS2_CHECK_SIZE(EquipColorInfo, 0x30);

class CItemExtraData:public CPtred {
public:
    typedef Unk_SocketPtr<EquipColorInfo> ColorPtr;
    CItemExtraData();                                            // 0x140598e60: inits +0x18..+0x28 and the containers from +0x30
                                                                 // (an implicit ctor left them garbage in DLL-allocated objects)
    bool FUN_140599480(const ItemColorEx&, MS2Ptr<CItemData>);   // 0x140599480 (itemugcmesh.cpp: bound into a Delegate)
    virtual ~CItemExtraData();
    virtual int vfunc_1(const CItemExtraData*);
    virtual int vfunc_2(const CItemExtraData*);
    virtual void vfunc_3(const CItemExtraData*);
    virtual void vfunc_4(CItemData*);
    virtual void vfunc_5(COutputStream&);
    virtual void vfunc_6(CInputStream&);
    virtual void vfunc_7(COutputStream&);
    virtual void vfunc_8(CInputStream&);
    int FUN_140599510(const ItemColorEx& kColor, MS2Ptr<CItemData> spData);
    void FUN_1405993b0(unsigned nCount);
    int FUN_140599830(const CItemExtraData* pOther);
    int FUN_140599970(const CItemExtraData* pOther);
    void FUN_140599ab0(CItemData* pData);
    void FUN_140599bc0(const ItemColorEx* pColor, bool bExtra, int nDelay, unsigned nSlot);
    void FUN_140599d10(ATL::CAtlArray<int>& aValues, unsigned nSlot);
    void FUN_140599ea0(int nIndex, const int& nValue, unsigned nSlot);
    int FUN_140599fd0(unsigned nIndex);
    int FUN_14059a040(unsigned nSlot);
    int FUN_14059a0b0(unsigned nSlot);
    int FUN_14059a120();
    int* FUN_14059a180(unsigned nSlot);
    void FUN_14059a1f0(int n);
    int FUN_14059a210();
    ColorPtr FUN_14059a230(unsigned nSlot) const;
    ColorPtr FUN_14059a2c0();
    bool FUN_14059a350();
    int FUN_14059d130() const;
    int FUN_14059d140() const;
protected:
    int m_nIndex;                                                // +0x18 the colour slot cycling now (m_bMulti)
    int m_nPick;                                                 // +0x1c the preset picked at random (-1)
    bool m_bMulti;                                               // +0x20 one colour slot per preset (m_colors)
    unsigned m_nNextTick;                                        // +0x24 the tick of the next cycle step
    int m_nKind;                                                 // +0x28 0 plain, 1 decal, 2 hair, 3 cap
    ColorPtr m_spColor;                                          // +0x30
    std::vector<ColorPtr> m_colors;                              // +0x40
};
MS2_CHECK_SIZE(CItemExtraData,0x58);

// The extra-data subclasses CItemData::FUN_14053e6c0 allocates per item kind.
class CDecalExtraData : public CItemExtraData {     // decal items, 0x68 bytes
public:
    CDecalExtraData();                              // 0x14059a400
    virtual int vfunc_2(const CItemExtraData*);
    virtual void vfunc_3(const CItemExtraData*);
    virtual void vfunc_4(CItemData*);
    virtual void vfunc_5(COutputStream&);
    virtual void vfunc_6(CInputStream&);
    float m_f58, m_f5c, m_f60, m_f64;               // +0x58 the decal block values (scale / offset)
};
MS2_CHECK_SIZE(CDecalExtraData,0x68);
class CHairExtraData : public CItemExtraData {      // hair items, 0xa0 bytes
public:
    CHairExtraData();                               // 0x14059a8a0
    virtual int vfunc_2(const CItemExtraData*);
    virtual void vfunc_3(const CItemExtraData*);
    virtual void vfunc_4(CItemData*);
    virtual void vfunc_5(COutputStream&);
    virtual void vfunc_6(CInputStream&);
    void FUN_14059aa20();                           // clamp the scales to >= 0
    float m_fScale[2];                              // +0x58
    Unk_StreamPoint m_aPt1[2];                      // +0x60
    Unk_StreamPoint m_aPt2[2];                      // +0x78
    int m_bUseScale, m_bUsePt2, m_bUsePt1;          // +0x90 +0x94 +0x98 which of the values the item lets the player override
};
MS2_CHECK_SIZE(CHairExtraData,0xa0);
class CCapExtraData : public CItemExtraData {       // cap items, 0x90 bytes
public:
    CCapExtraData();                                // 0x14059b350
    virtual int vfunc_2(const CItemExtraData*);
    virtual void vfunc_3(const CItemExtraData*);
    virtual void vfunc_4(CItemData*);
    virtual void vfunc_5(COutputStream&);
    virtual void vfunc_6(CInputStream&);
    float m_f58;                                    // +0x58
    Unk_StreamPoint m_aPt[4];                       // +0x5c +0x68 +0x74 +0x80
};
MS2_CHECK_SIZE(CCapExtraData,0x90);
