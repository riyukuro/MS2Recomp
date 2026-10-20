// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The pet info tab of the pet system dialog: see tabcontentspetinfo.h.
// MS2-UNIT: ?\tabcontentspetinfo.cpp
// MS2-RANGE: 0x1400cfde0-0x1400d0080 .text$di
// MS2-RANGE: 0x140cb87d0-0x140cbf600 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__E?ms_ClassInfo@EquipSlotBag@TabContentsPetInfo@@2VClassInfo@efd@@B@@YAXXZ 0x1400cfe00 ; prop
// MS2-PIN: ??__Es_cap@@YAXXZ 0x1400cfe20 ; probe
// MS2-PIN: ??__Es_dropShadowDisable@@YAXXZ 0x1400cfe50 ; probe
// MS2-PIN: ??__Es_iconPath@@YAXXZ 0x1400cfe80 ; probe
// MS2-PIN: ??__Es_itemLevel@@YAXXZ 0x1400cfeb0 ; probe
// MS2-PIN: ??__Es_itemPetRank@@YAXXZ 0x1400cffa0 ; probe
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x1400cffd0 ; probe
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x1400d0050 ; probe
// MS2-PIN: ??$FUN_14028dee0@_JV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HAEB_JAEBV01@@Z 0x140cbdeb0 ; unique
// MS2-PIN: ??0?$CAtlList@V?$MS2Ptr@VPetInfoBase@@@@V?$CElementTraits@V?$MS2Ptr@VPetInfoBase@@@@@ATL@@@ATL@@QEAA@I@Z 0x140cbe4b0 ; unique
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVPetInfoBasic@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBV01@@Z 0x140cbe510 ; unique
// MS2-PIN: ?GetAt@?$CAtlList@V?$MS2Ptr@VPetInfoBase@@@@V?$CElementTraits@V?$MS2Ptr@VPetInfoBase@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@VPetInfoBase@@@@PEAU__POSITION@@@Z 0x140cbed30 ; unique
// MS2-PIN: ?GetClassDesc@EquipSlot@TabContentsPetInfo@@UEBAPEBVClassInfo@efd@@XZ 0x140cbeda0 ; unique
// MS2-PIN: ?GetClassDesc@EquipSlotBag@TabContentsPetInfo@@UEBAPEBVClassInfo@efd@@XZ 0x140cbedb0 ; unique
// MS2-PIN: ?GetNext@?$CAtlList@V?$MS2Ptr@VPetInfoBase@@@@V?$CElementTraits@V?$MS2Ptr@VPetInfoBase@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@VPetInfoBase@@@@AEAPEAU__POSITION@@@Z 0x140cbeeb0 ; unique
// MS2-PIN: ?vfunc_6@PetInfoBase@@UEAAHPEBDPEBVValue@GFx@Scaleform@@I@Z 0x140cbf000 ; unique
// MS2-PIN: ?SetupClassInfo@EquipSlot@TabContentsPetInfo@@SAXPEAVClassInfo@efd@@_K@Z 0x140cbf190 ; unique
// MS2-PIN: ?SetupClassInfo@EquipSlotBag@TabContentsPetInfo@@SAXPEAVClassInfo@efd@@_K@Z 0x140cbf1f0 ; unique
// MS2-PIN: ?TypeCast@EquipSlot@TabContentsPetInfo@@UEBA_NIPEAPEAX@Z 0x140cbf250 ; unique
// MS2-PIN: ?TypeCast@EquipSlot@TabContentsPetInfo@@UEBA_NIPEAPEBX@Z 0x140cbf2a0 ; unique
// MS2-PIN: ?TypeCast@EquipSlotBag@TabContentsPetInfo@@UEBA_NIPEAPEAX@Z 0x140cbf2f0 ; unique
// MS2-PIN: ?TypeCast@EquipSlotBag@TabContentsPetInfo@@UEBA_NIPEAPEBX@Z 0x140cbf340 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVPetInfoBasic@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140cbf4a0 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVPetInfoBasic@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x140cbf500 ; unique
// MS2-PIN: ??$Call@VPetInfoBasic@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVPetInfoBasic@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVPetInfoBasic@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x140cbf540 ; unique
// MS2-PINS-END tplpin
//
// File name assumed (the old index called the unit petinfobasic.cpp).
// MS2-PIN: ?vfunc_1@PetInfoBase@@UEAAXXZ 0x140cbeff0 ; hand: empty slot bodies are byte-identical
// MS2-PIN: ?vfunc_2@PetInfoBase@@UEAAXXZ 0x140cbf020 ; hand
// MS2-PIN: ?vfunc_3@PetInfoBase@@UEAAXXZ 0x140cbecb0 ; hand
// MS2-PIN: ?vfunc_4@PetInfoBase@@UEAAXXZ 0x140cbeca0 ; hand
// MS2-PIN: ??_7EquipSlot@TabContentsPetInfo@@6BBindData@NotifyContext@@@ 0x142e19920 ; hand: primary vftable
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\tabcontentspetinfo.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"
#include <afxdialogex.h>
#include "tabcontentspetinfo.h"
#include "uimessageboxdata.h"
#include "uimessagebox.h"
#include "uiavatarbase.h"
#include "uidialog.h"
#include "ms2/commonfiles/gamerule.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asslot.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/fmt/format.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <efd/MemHint.h>
#include <efd/MemObject.h>

// ---- statics (the .di of this unit constructs them in this order) ----
EE_IMPLEMENT_CONCRETE_CLASS_INFO(TabContentsPetInfo::EquipSlot);
EE_IMPLEMENT_CONCRETE_CLASS_INFO(TabContentsPetInfo::EquipSlotBag);
static CString s_dropShadowDisable("dropShadowDisable");
static CString s_iconPath("iconPath");
static CString s_itemLevel("itemLevel");
static CString s_itemPetRank("itemPetRank");
#include "ms2/placeholder/header_statics_a.h"
static CString s_cap("Cap");

// MS2Ptr<ASUIComponent>: the exe shares every member of it (see tabcontentspetevolution.cpp).
extern template class MS2Ptr<ASUIComponent>;
extern template class MS2Ptr<ASMovieClip>;
extern template class MS2Ptr<ASTextField>;
extern template class MS2Ptr<CItem>;
extern template class MS2Ptr<CItemData>;
extern template class MS2Ptr<CMsgBoxData>;

// ---- unit-local views of exe objects (names invented; the FUN_ names are exe addresses) ----

class Unk_PetValueView { public: bool FUN_1409b4d40() const; };

// The pet menu button: a movie clip with a state frame and a label.
class Unk_PetButton : public ASMovieClip
{
public:
    Unk_PetButton(const Scaleform::GFx::Value& v, int nMovieId);        // 0x1422cdde0
    void FUN_1422c1fe0(unsigned int nFrame);                            // go to the state frame
    void FUN_1422cdfb0(const CStringW& strLabel);                       // set the label
private:
    unsigned char m_pad_80[8];
};
MS2_CHECK_SIZE(Unk_PetButton, 0x88);

// The item bag control of a section clip.
class Unk_PetItemBag : public ASMovieClip
{
public:
    Unk_PetItemBag(const Scaleform::GFx::Value& v, int nMovieId);       // 0x1422cf330
#define PB_V(n) virtual void vfunc_##n();
    PB_V(16) PB_V(17) PB_V(18) PB_V(19) PB_V(20) PB_V(21) PB_V(22) PB_V(23)
#undef PB_V
    virtual void vfunc_24(int nShow);                                   // 24 (+0xc0) refresh
    void FUN_1407cba60(const char* szName, CString str);                // set the bag id
private:
    unsigned char m_pad_80[8];
};
MS2_CHECK_SIZE(Unk_PetItemBag, 0x88);

// A scrolling list of the section clip (rows are AS objects).
class Unk_StatList : public ASMovieClip
{
public:
#define SL_V(n) virtual void vfunc_##n();
    SL_V(16) SL_V(17) SL_V(18) SL_V(19) SL_V(20) SL_V(21) SL_V(22) SL_V(23)
#undef SL_V
    virtual void vfunc_24(int nShow);                                   // 24 (+0xc0) refresh
    void FUN_1422dd1d0();                                               // clear the rows
    void FUN_1422dd230(ASObj& row);                                     // add a row
private:
    unsigned char m_pad_80[8];
};

// A component of the page with the helpers of this unit and the exe.
class Unk_PiComp : public ASUIComponent
{
public:
    void FUN_1422bb7e0(ASObj& obj);                                     // set the data
    MS2Ptr<Unk_StatList> FUN_140bc7280(const CString& strName);         // child list by name
    Scaleform::GFx::Value FUN_140caf230(const char* szMethod, int a1);  // Invoke(int) (a copy outside the unit)
    Scaleform::GFx::Value FUN_140cbe3a0(const char* szMethod, const wchar_t* a1);   // Invoke(wchar_t*), the unit's COMDAT
};
#define PI(p) static_cast<Unk_PiComp*>((p).operator->())

class Unk_PiText : public ASTextField
{
public:
    void FUN_1422c5910(int n);
};

// The skill map of a pet row: a position based map (position 0 = end).
class Unk_PiSkillMap
{
public:
    void* FUN_14063f420();                                              // first position
    unsigned short* FUN_14063f490(void* pos);                           // level
    unsigned* FUN_14063f360(void* pos);                                 // skill id
    void FUN_14063f3d0(void*& pos);                                     // next
};

// The pet record of the equip data table.
class Unk_PetRow : public CPtred
{
public:
    int m_nFlag;                                                        // +0x18 1 = the pet has levels
    unsigned char m_pad_1c[0x2c];
    Unk_PiSkillMap m_skills;                                            // +0x48
    unsigned char m_pad_49[0x57];
    unsigned m_nSlotMax;                                                // +0xa0 the other pet's inventory slots
};
MS2_CHECK_OFFSET(Unk_PetRow, m_skills, 0x48);
MS2_CHECK_OFFSET(Unk_PetRow, m_nSlotMax, 0xa0);
class Unk_PetRowTable { public: MS2Ptr<Unk_PetRow> FUN_1407290f0(int nKey); };
Unk_PetRowTable* FUN_14052d210();
class Unk_ItemEquipData : public CItemData { };

// The skill record of the skill table (the icon path at +0xc0).
class Unk_PiSkillRec : public CPtred
{
public:
    unsigned char m_pad_18[0xa8];
    CString m_strIcon;                                                  // +0xc0
};
MS2_CHECK_OFFSET(Unk_PiSkillRec, m_strIcon, 0xc0);
class Unk_PiSkillTable { public: MS2Ptr<Unk_PiSkillRec> FUN_140aafef0(unsigned nSkillId, unsigned short nLevel); };
Unk_PiSkillTable* FUN_1401958b0();

// The local player: FUN_14152b800 requests the pet inventory, FUN_14152b2d0 summons the pet of an item.
class Unk_PetPlayer
{
public:
    void FUN_14152b800(__int64 nItemUid);
    void FUN_14152b2d0(__int64 nItemUid);
};
class Unk_PetPlayerMgr { public: Unk_PetPlayer* FUN_141bd0cc0(); };
Unk_PetPlayerMgr* FUN_1403ed2d0();

// The UI manager: open a dialog / look one up.
class Unk_PiUIManager
{
public:
    void FUN_141adc530(int nId);
    MS2Ptr<UIObject> FUN_141adcea0(int nId);
};
Unk_PiUIManager* FUN_1403ed2b0();

// The dialogs the page talks to. The RTTI names must match the exe's.
class UIItemAutoUseOptionDialog : public UIDialog { };
class UIItemGetOptionDialog : public UIDialog { public: void FUN_1419da620(int nMode); };
class UIOtherPetSystemDialog : public UIDialog
{
public:
    virtual void vfunc_84();
    virtual MS2Ptr<CItem> vfunc_85();                                   // 85 0x2a8 the shown pet item
};
class Unk_PetDialog : public UIDialog
{
public:
    virtual void vfunc_84();
    virtual MS2Ptr<CItem> vfunc_85();                                   // 85 0x2a8 the shown pet item
};
Unk_PetDialog* FUN_140b99ba0(int nId);

// Client configuration: the pet class that may be levelled sits at +0x84c0, the name length limit at +0x9d08.
class Unk_PetUIntSlot { public: unsigned* FUN_1401d7c10(); };
class Unk_PetIntSlot { public: int* FUN_1402056b0(); };
class Unk_PetConfig
{
public:
    unsigned char m_pad[0x84c0];
    Unk_PetUIntSlot m_petClass;
    unsigned char m_pad_84c1[0x9d08 - 0x84c1];
    Unk_PetIntSlot m_nameLimit;
};
Unk_PetConfig* FUN_1401d3200();
unsigned* FUN_1401d7c10(Unk_PetUIntSlot* pSlot);
int* FUN_1402056b0(Unk_PetIntSlot* pSlot);

// The exp table: points an (pet class, rank, item class) needs for the next level.
class Unk_PetTable { public: __int64 FUN_140353930(unsigned short nPetClass, int nRank, unsigned short nItemClass); };
Unk_PetTable* FUN_1404a1bb0();

// The pet inventory dialog's selection: the other pet's record and the bag counters.
struct Unk_PiPetData
{
    unsigned char m_pad_00[0x18];
    CStringW m_strName;                                                 // +0x18
    unsigned char m_pad_20[0x14];
    int m_nState;                                                       // +0x34 0 = the pet is out
};
MS2_CHECK_OFFSET(Unk_PiPetData, m_nState, 0x34);
class Unk_PiBag { public: __int64 FUN_140c874f0(); __int64 FUN_140c875e0(); };
class Unk_PetSelected
{
public:
    Unk_PiPetData* FUN_140c8b450();
    Unk_PiBag* FUN_140c8b410();
};
Unk_PetSelected* FUN_140535320();

// The text filter (see unit_141274d10.cpp).
class Unk_TextFilter { public: };
int FUN_140225120(Unk_TextFilter*, const CStringW& str, CStringW& strOut);
class Unk_TextFilterPtr
{
public:
    ~Unk_TextFilterPtr();                                               // 0x14025c670
    Unk_TextFilter* FUN_14025cea0() const;
    Unk_TextFilter* FUN_14025cf10() const;
    void* m_00; void* m_08;
};
class Unk_TextFilterMgr { public: Unk_TextFilterPtr FUN_140229a50(); };
Unk_TextFilterMgr* FUN_14025e7d0();

// Strings and tables.
CStringW FUN_14028b8e0(const CStringW& str);
CStringW FUN_14028de60(int nStringId);
CStringW FUN_14052bd00(int nStringId, const CStringW& str);
CStringW FUN_14028dee0(int nStringId, const fmt::ArgList& args);        // the string table formatter
FMT_VARIADIC_W(CStringW, FUN_14028dee0, int)
CStringW FUN_140811740(int nStringId, const int& a, const int& b);
CStringW FUN_14062b4f0(CStringW fmt, const int& n);
CStringW FUN_1409404f0(__int64 n);                                      // number with separators
CStringW FUN_1408f71a0(CStringW fmt, const CStringW& a, const CStringW& b);
CStringW FUN_1409e8820(CStringW fmt, const unsigned short& n);
CStringW FUN_1409e34e0(MS2Ptr<CItem> item);                             // the item's option text
CString FUN_14038f6d0(const CString& a, const char* b);                 // a + b
CStringTable* FUN_1401a9d70();
bool FUN_140164830(const CStringW& a, const CStringW& b);
CGameRule* FUN_1401c0d90();
CStringW FUN_1401fedc0();                                               // the empty name
void FUN_1401fee50(const CStringW& str, COutPacket& packet);
void FUN_140710590(COutPacket& packet);                                 // send
UIMessageBox* FUN_14151f890();
void FUN_14151f200();
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW text, int nUnk, CStringW tag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
class Unk_PiNetwork
{
public:
#define NV(n) virtual void vfunc_##n();
    NV(0) NV(1) NV(2) NV(3) NV(4) NV(5) NV(6) NV(7) NV(8) NV(9) NV(10) NV(11) NV(12) NV(13) NV(14) NV(15) NV(16) NV(17) NV(18) NV(19)
    NV(20) NV(21) NV(22) NV(23) NV(24) NV(25) NV(26) NV(27) NV(28) NV(29) NV(30) NV(31) NV(32) NV(33) NV(34) NV(35) NV(36) NV(37) NV(38) NV(39)
    NV(40) NV(41) NV(42)
#undef NV
    virtual void vfunc_43(int a, int b, int c);
};
Unk_PiNetwork* FUN_140d86260();

// Bag registry (GFx bind data).
void FUN_1422c8f10(const CString& strName, NotifyContext::BindData* pBag);
NotifyContext::BindData* FUN_1422c8e90(const CString& strName);
void FUN_1422c8f70(const CString& strName);
void FUN_1422cc9e0(DragSlotBag* pBag);
void FUN_140dbc420(CString* pBag);                                      // release the inventory bag
void FUN_140dbc370(CString* pBag, __int64 nSlots);                      // fill the inventory bag
void* FUN_140a50b50(DragSlot* pSlot);                                   // the item slot behind a drag source
__int64 FUN_141405a10(void* pItemSlot);                                 // its item uid

// Camera of the pet preview (see uiitempetboxdialog.cpp).
struct Unk_PetBoxVector
{
    float x, y, z;
};
struct Unk_PetBoxCameraData
{
    Unk_PetBoxCameraData();                                             // 0x140cb13b0
    void FUN_141b48670();
    Unk_PetBoxVector eye, target;
    float f18, f1c, f20;
    int n24, n28, n2c;
};
MS2_CHECK_SIZE(Unk_PetBoxCameraData, 0x30);
class Unk_PetBoxActor
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4();
    virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14();
    virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17();
    virtual Unk_PetBoxVector vfunc_18();
};
class Unk_PetBoxCamera
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4();
    virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12();
    virtual void vfunc_13(const Unk_PetBoxCameraData&);
};
float FUN_141b48480(int a, int b);

// The Value setters the Invoke helpers use.
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);

typedef MS2Ptr<CItem> ItemPtr;

// ---- glue ----

// @0x140cbdde0 (MS2Ptr<ASMovieClip>(MS2Ptr<ASUIComponent>&&): takes the pointer over)
inline MS2Ptr<ASMovieClip> FUN_140cbdde0(MS2Ptr<ASUIComponent>&& o)
{
    MS2Ptr<ASMovieClip> r(0);
    reinterpret_cast<void**>(&r)[1] = reinterpret_cast<void**>(&o)[1];
    reinterpret_cast<void**>(&o)[1] = 0;
    return r;
}

// @0x140cbe3a0
inline Scaleform::GFx::Value Unk_PiComp::FUN_140cbe3a0(const char* szMethod, const wchar_t* a1)
{
    ASArgList args;
    args.FUN_1409b2800(1);
    FUN_1422bcea0(args.FUN_1409b1f70(0), a1);
    return FUN_1422bb8f0(szMethod, args);
}
MS2_REPLACE_METHOD(0x140cbe3a0, Unk_PiComp, FUN_140cbe3a0, 148, 0x74DC573F);

void FUN_140cbf150(PetInfoBase* p, MS2Ptr<ASUIComponent> ui);

// ---- helpers ----

UIItemAutoUseOptionDialog* FUN_140cbe1c0(int nId);
UIItemGetOptionDialog* FUN_140cbe260(int nId);
UIOtherPetSystemDialog* FUN_140cbe300(int nId);

// @0x140cbd900
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
MS2Ptr<CItem> FUN_140cbd900(int nPet)
{
    if (nPet == 0)
    {
        UIOtherPetSystemDialog* pDlg = FUN_140cbe300(0x4f41);
        if (pDlg != 0)
            return pDlg->vfunc_85();
    }
    else
    {
        Unk_PetDialog* pDlg = FUN_140b99ba0(0x4f38);
        if (pDlg != 0)
            return pDlg->vfunc_85();
    }
    return MS2Ptr<CItem>(0);
}

// @0x140cbd9d0
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
int FUN_140cbd9d0(int nPet)
{
    MS2Ptr<CItem> pet = FUN_140cbd900(nPet);
    if (pet == 0)
        return 0;
    if (pet->FUN_140526a50() == 0)
        return 0;
    return 1;
}

// @0x140cbda70
MS2Ptr<Unk_PetRow> FUN_140cbda70(int nPet)
{
    MS2Ptr<CItem> pet = FUN_140cbd900(nPet);
    if (pet == 0)
        return MS2Ptr<Unk_PetRow>(0);
    MS2Ptr<CItemData> data(pet->FUN_140527840());
    if (data == 0)
        return MS2Ptr<Unk_PetRow>(0);
    return FUN_14052d210()->FUN_1407290f0(data->FUN_14053dc60());
}

// @0x140cbdba0
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
Unk_PiPetData* FUN_140cbdba0(int nPet)
{
    MS2Ptr<CItem> pet = FUN_140cbd900(nPet);
    if (pet == 0)
        return 0;
    if (nPet == 0)
        return 0;
    return FUN_140535320()->FUN_140c8b450();
}

// @0x140cbdc40
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
__int64 FUN_140cbdc40(int nPet)
{
    if (nPet == 0)
        return 0;
    return FUN_140535320()->FUN_140c8b410()->FUN_140c874f0();
}

// @0x140cbdc80
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
unsigned __int64 FUN_140cbdc80(int nPet)
{
    if (nPet == 0)
    {
        MS2Ptr<Unk_PetRow> row = FUN_140cbda70(0);
        if (row == 0)
            return 0;
        return row->m_nSlotMax;
    }
    return FUN_140535320()->FUN_140c8b410()->FUN_140c875e0();
}

// @0x140cbe1c0
UIItemAutoUseOptionDialog* FUN_140cbe1c0(int nId)
{
    if (FUN_1403ed2b0() != 0)
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (p.get() != 0)
            return dynamic_cast<UIItemAutoUseOptionDialog*>((UIObject*)p);
    }
    return 0;
}

// @0x140cbe260
UIItemGetOptionDialog* FUN_140cbe260(int nId)
{
    if (FUN_1403ed2b0() != 0)
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (p.get() != 0)
            return dynamic_cast<UIItemGetOptionDialog*>((UIObject*)p);
    }
    return 0;
}

// @0x140cbe300
UIOtherPetSystemDialog* FUN_140cbe300(int nId)
{
    if (FUN_1403ed2b0() != 0)
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (p.get() != 0)
            return dynamic_cast<UIOtherPetSystemDialog*>((UIObject*)p);
    }
    return 0;
}

// @0x140cbde60
TabContentsPetInfo::EquipSlotBag* FUN_140cbde60(NotifyContext::BindData* p)
{
    TabContentsPetInfo::EquipSlotBag* pBag = 0;
    if (p != 0 && p->TypeCast(0x6200076, (void**)&pBag))
        return pBag;
    else
        return 0;
}

// @0x140cbcb90
void FUN_140cbcb90(const CString& strBag, int nCount, int nPet)
{
    TabContentsPetInfo::EquipSlotBag* pBag = new (efd::MemHint(efd::MemHint::NONE)) TabContentsPetInfo::EquipSlotBag(strBag, nPet);
    if (pBag)
    {
        static_cast<DragSlotBag*>(pBag)->vfunc_10(nCount);
        FUN_1422c8f10(strBag, pBag);
    }
}

// @0x140cbcc50
void FUN_140cbcc50(const CString& strBag)
{
    TabContentsPetInfo::EquipSlotBag* pBag = FUN_140cbde60(FUN_1422c8e90(strBag));
    if (pBag)
    {
        FUN_1422cc9e0(pBag);
        FUN_1422c8f70(strBag);
    }
}

// ---- PetInfoBasic ----

// @0x140cb87d0
PetInfoBasic::PetInfoBasic(int nPet)
    : PetInfoBase(nPet), m_strBag("PetInfoBasic")
{
    if (nPet == 0)
        m_strBag = "OtherPetInfoBasic";
}

// @0x140cb8850
void PetInfoBasic::vfunc_2()
{
    FUN_140cbcc50(m_strBag);
}
MS2_REPLACE_METHOD(0x140cb8850, PetInfoBasic, vfunc_2, 31, 0x2450BC85);

// @0x140cb8880
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
// MS2-FUNCTIONAL: exe call-result temporaries / frame-slot order differ (source form not found)
void PetInfoBasic::vfunc_3()
{
    MS2Ptr<CItem> pet = FUN_140cbd900(m_nPet);
    if (pet == 0)
        return;
    MS2Ptr<Unk_PetRow> row = FUN_140cbda70(m_nPet);
    if (row == 0)
        return;
    MS2Ptr<ASUIComponent> basic = m_ui->FUN_140accfb0<ASUIComponent>(CString("m_basic"));
    if (basic == 0)
        return;
    unsigned short nPetClass = pet->FUN_140528c20();
    int nRank = pet->FUN_140526bd0();
    MS2Ptr<ASTextField> name = basic->FUN_1409b4620(CString("m_name"));
    if (name.get() != 0)
    {
        name->FUN_1422c4cd0(pet->FUN_140527b10());
        static_cast<Unk_PiText*>(name.operator->())->FUN_1422c5910(1);
    }
    name = 0;
    MS2Ptr<Unk_PetButton> change = basic->FUN_140acce30<Unk_PetButton>(CString("m_changeName"));
    if (change.get() != 0)
    {
        change->FUN_1422cdfb0(FUN_14028b8e0(CStringW(L"s_pet_change_name")));
        change->FUN_1422c1fe0(FUN_140cba220());
    }
    change = 0;
    MS2Ptr<ASUIComponent> bar = basic->FUN_140accfb0<ASUIComponent>(CString("m_expBar"));
    if (bar.get() != 0)
    {
        unsigned nClass = nPetClass;
        if (nClass < *FUN_1401d7c10(&FUN_1401d3200()->m_petClass))
        {
            __int64 nExp = pet->FUN_140528b90();
            unsigned short nItemClass = pet->FUN_1405282d0();
            __int64 nMax = FUN_1404a1bb0()->FUN_140353930(nPetClass, nRank, nItemClass);
            if (row->m_nFlag == 1)
            {
                CStringW strExp;
                strExp.Format(L"%s", (const wchar_t*)FUN_1408f71a0(CStringW(L"s_word_exp_value"), FUN_1409404f0(nExp), FUN_1409404f0(nMax)));
                bar->Invoke("setText", CStringW(strExp));
            }
            else
            {
                bar->Invoke("setText", FUN_14028b8e0(CStringW(L"s_word_not_enchant")));
            }
            bar->Invoke("setPercent", nExp, nMax);
        }
        else
        {
            bar->Invoke("setMax");
        }
    }
    bar = 0;
    MS2Ptr<ASMovieClip> bg = basic->FUN_1409b4560(CString("m_slotBg"));
    if (bg.get() != 0)
        bg->vfunc_3(FUN_140cba1f0());
    bg = 0;
    ASObj obj(2);
    if (row->m_nFlag == 1)
        obj.FUN_1407cbb20(s_itemLevel, FUN_1409e8820(CStringW(L"s_word_petlevel"), nPetClass));
    else
        obj.FUN_1409c0dc0(s_itemLevel, "");
    obj.FUN_1409adc90(s_itemPetRank, nRank);
    obj.FUN_1407cb9c0(s_dropShadowDisable, 1);
    PI(basic)->FUN_1422bb7e0(obj);
}

// @0x140cb9240
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
// MS2-FUNCTIONAL: exe call-result temporaries / frame-slot order differ (source form not found)
void PetInfoBasic::vfunc_4()
{
    MS2Ptr<ASUIComponent> basic = m_ui->FUN_140accfb0<ASUIComponent>(CString("m_basic"));
    if (basic == 0)
        return;
    MS2Ptr<ASTextField> name = basic->FUN_1409b4620(CString("m_name"));
    if (name.get() != 0)
        name->FUN_1422c4cd0(CStringW(L""));
    name = 0;
    MS2Ptr<Unk_PetButton> change = basic->FUN_140acce30<Unk_PetButton>(CString("m_changeName"));
    if (change.get() != 0)
    {
        change->FUN_1422cdfb0(FUN_14028b8e0(CStringW(L"s_pet_change_name")));
        change->FUN_1422c1fe0(0);
    }
    change = 0;
    MS2Ptr<ASUIComponent> bar = basic->FUN_140accfb0<ASUIComponent>(CString("m_expBar"));
    if (bar.get() != 0)
    {
        PI(bar)->FUN_140cbe3a0("setText", L"");
        bar->FUN_1409ba0d0("setPercent", 0, 0);
    }
    bar = 0;
    MS2Ptr<ASMovieClip> bg = basic->FUN_1409b4560(CString("m_slotBg"));
    if (bg.get() != 0)
        bg->vfunc_3(1);
    bg = 0;
    FUN_140cbcb90(m_strBag, 1, m_nPet);
    ASObj obj(2);
    obj.FUN_1409c0dc0(s_itemLevel, "");
    obj.FUN_1409adc90(s_itemPetRank, 0);
    obj.FUN_1407cb9c0(s_dropShadowDisable, 1);
    PI(basic)->FUN_1422bb7e0(obj);
}

// @0x140cb9790
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
void PetInfoBasic::vfunc_5(int nTab)
{
    MS2Ptr<ASUIComponent> basic = m_ui->FUN_140accfb0<ASUIComponent>(CString("m_basic"));
    if (basic == 0)
    {
        if (-1 < nTab && (nTab < 3 || nTab == 6 || nTab == 9 || nTab == 0xd))
        {
            vfunc_4();
            vfunc_3();
        }
    }
}
MS2_REPLACE_METHOD(0x140cb9790, PetInfoBasic, vfunc_5, 212, 0xFCDD3E5A);

// @0x140cb9870
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
int PetInfoBasic::vfunc_6(const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned nArgs)
{
    ASData data;
    int nCmp = _stricmp("OnChangeName", szEvent);
    if (nCmp == 0)
        FUN_140cb9900();
    return nCmp == 0;
}
MS2_REPLACE_METHOD(0x140cb9870, PetInfoBasic, vfunc_6, 138, 0x1274197A);

// @0x140cb9900
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
void PetInfoBasic::FUN_140cb9900()
{
    UIItemAutoUseOptionDialog* pAuto = FUN_140cbe1c0(0x4ef4);
    if (pAuto == 0 || pAuto->vfunc_55() != 0)
    {
        int nLimit = *FUN_1402056b0(&FUN_1401d3200()->m_nameLimit);
        int nHalf = nLimit / 2;
        CStringW strText = FUN_140811740(0xc0a, nHalf, nLimit);
        MS2Ptr<CMsgBoxData> box = FUN_140d73d20(10, CStringW(strText), 0, CStringW(L""));
        if (box.get() != 0)
        {
            unsigned nMax = *FUN_1402056b0(&FUN_1401d3200()->m_nameLimit);
            box->FUN_141a01d30(2, CStringW(L""), nMax, 0, 0);
            box->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &PetInfoBasic::FUN_140cb9ba0));
            FUN_140d73c60(box);
        }
        FUN_140d86260()->vfunc_43(2, 0, 1000);
    }
}
MS2_REPLACE_METHOD(0x140cb9900, PetInfoBasic, FUN_140cb9900, 651, 0x675FFFB5);

// @0x140cb9ba0
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
// MS2-FUNCTIONAL: exe call-result temporaries / frame-slot order differ (source form not found)
bool PetInfoBasic::FUN_140cb9ba0(int nResult, const CMsgBoxData& box)
{
    Unk_PetPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return false;
    if (nResult == 0)
    {
        CStringW strErr;
        CStringW strName(box.FUN_141a02d50().Trim(L','));
        if (strName.IsEmpty() || strName.GetLength() > 31)
            return false;
        Unk_TextFilterPtr filter = FUN_14025e7d0()->FUN_140229a50();
        if (filter.FUN_14025cea0() != 0)
        {
            if (FUN_140225120(filter.FUN_14025cf10(), strName, strErr) == 0)
            {
                Unk_PiPetData* pData = FUN_140cbdba0(m_nPet);
                if (pData == 0)
                    return false;
                if (FUN_140164830(pData->m_strName, strName) == false)
                {
                    UIMessageBox* pBox = FUN_14151f890();
                    if (pBox != 0)
                        pBox->FUN_1419f82b0(FUN_14028de60(0xc1b));
                }
                else
                {
                    FUN_14151f200();
                    CStringW strText;
                    if (pData->m_nState == 0)
                        strText = FUN_14028dee0(0xc1a, FUN_1401c0d90()->FUN_140477330(), strName);
                    else
                        strText = FUN_14052bd00(0xc19, strName);
                    MS2Ptr<CMsgBoxData> confirm = FUN_140d73d20(1, CStringW(strText), 0, CStringW(L""));
                    if (confirm.get() != 0)
                    {
                        confirm->FUN_140b76940(CStringW(strName));
                        confirm->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &PetInfoBasic::FUN_140cba0f0));
                        FUN_140d73c60(confirm);
                    }
                }
            }
            else
            {
                UIMessageBox* pBox = FUN_14151f890();
                if (pBox != 0)
                    pBox->FUN_1419f82b0(strErr);
            }
            return false;
        }
    }
    return true;
}

// @0x140cba0f0
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
bool PetInfoBasic::FUN_140cba0f0(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0)
    {
        CStringW strName = FUN_1401fedc0();
        strName = box.FUN_141a02fd0(0, CStringW());
        COutPacket packet(0x78, 0);
        packet.vfunc_o10_1(4);
        FUN_1401fee50(strName, packet);
        FUN_140710590(packet);
    }
    return true;
}
MS2_REPLACE_METHOD(0x140cba0f0, PetInfoBasic, FUN_140cba0f0, 250, 0x9A9E6D77);

// @0x140cba1f0
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
int PetInfoBasic::FUN_140cba1f0()
{
    return FUN_140cbd9d0(m_nPet) == 0;
}
MS2_REPLACE_METHOD(0x140cba1f0, PetInfoBasic, FUN_140cba1f0, 40, 0x6D7EA769);

// @0x140cba220
int PetInfoBasic::FUN_140cba220()
{
    if (m_nPet == 0)
        return 0;
    return FUN_140cbd9d0(m_nPet);
}
MS2_REPLACE_METHOD(0x140cba220, PetInfoBasic, FUN_140cba220, 42, 0x711F43C3);

// ---- PetInfoInventory ----

// @0x140cba250
PetInfoInventory::PetInfoInventory(int nPet)
    : PetInfoBase(nPet), m_strBag("PetInfoInventory")
{
}

// @0x140cba2b0
void PetInfoInventory::vfunc_2()
{
    FUN_140dbc420(&m_strBag);
}
MS2_REPLACE_METHOD(0x140cba2b0, PetInfoInventory, vfunc_2, 31, 0xE2D21EC3);

// @0x140cba2e0
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
// MS2-FUNCTIONAL: exe call-result temporaries / frame-slot order differ (source form not found)
void PetInfoInventory::vfunc_3()
{
    MS2Ptr<ASUIComponent> inv = m_ui->FUN_140accfb0<ASUIComponent>(CString("m_inventory"));
    if (inv == 0)
        return;
    int nSlotUse = (int)FUN_140cbdc40(m_nPet);
    int nSlotMax = (int)FUN_140cbdc80(m_nPet);
    if (m_nPet == 0)
    {
        inv->vfunc_3(0);
        MS2Ptr<ASMovieClip> notInv = FUN_140cbdde0(m_ui->FUN_140accfb0<ASUIComponent>(CString("m_notInventory")));
        if (notInv.get() != 0)
        {
            MS2Ptr<ASTextField> text = notInv->FUN_1409b4620(CString("textField"));
            if (text.get() != 0)
            {
                if (nSlotMax < 1)
                    text->FUN_1422c4cd0(FUN_14028b8e0(CStringW(L"s_pet_otherpet_not_inventory")));
                else
                    text->FUN_1422c4cd0(FUN_14062b4f0(CStringW(L"s_pet_otherpet_inventory"), nSlotMax));
            }
            notInv->vfunc_3(1);
        }
    }
    else if (FUN_140cbd9d0(m_nPet) == 0 || nSlotMax < 1)
    {
        inv->vfunc_3(0);
        MS2Ptr<ASMovieClip> notInv = FUN_140cbdde0(m_ui->FUN_140accfb0<ASUIComponent>(CString("m_notInventory")));
        if (notInv.get() != 0)
        {
            MS2Ptr<ASTextField> text = notInv->FUN_1409b4620(CString("textField"));
            if (text.get() != 0)
                text->FUN_1422c4cd0(FUN_14028b8e0(CStringW(L"s_pet_not_inventory")));
            notInv->vfunc_3(1);
        }
    }
    else
    {
        inv->vfunc_3(1);
        MS2Ptr<ASMovieClip> notInv = FUN_140cbdde0(m_ui->FUN_140accfb0<ASUIComponent>(CString("m_notInventory")));
        if (notInv.get() != 0)
            notInv->vfunc_3(0);
    }
    MS2Ptr<ASTextField> count = inv->FUN_1409b4620(CString("m_slotUseCount"));
    if (count.get() != 0)
        count->FUN_1422c4cd0(FUN_140811740(0xc11, nSlotUse, nSlotMax));
}

// @0x140cbaa00
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
void PetInfoInventory::vfunc_4()
{
    MS2Ptr<ASUIComponent> inv = m_ui->FUN_140accfb0<ASUIComponent>(CString("m_inventory"));
    if (inv == 0)
        return;
    __int64 nSlots = FUN_140cbdc80(m_nPet);
    MS2Ptr<Unk_PetItemBag> bag = inv->FUN_140accef0<Unk_PetItemBag>(CString("m_itemBag"));
    if (bag.get() != 0)
    {
        FUN_140dbc370(&m_strBag, nSlots);
        bag->FUN_1407cba60("bagId", m_strBag);
        bag->vfunc_24(1);
    }
}
MS2_REPLACE_METHOD(0x140cbaa00, PetInfoInventory, vfunc_4, 433, 0xAE08D0A8);

// @0x140cbabc0
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
// MS2-FUNCTIONAL: exe call-result temporaries / frame-slot order differ (source form not found)
void PetInfoInventory::vfunc_5(int nTab)
{
    MS2Ptr<ASUIComponent> inv = m_ui->FUN_140accfb0<ASUIComponent>(CString("m_inventory"));
    if (inv == 0)
    {
        if (-1 < nTab)
        {
            if (nTab < 3)
            {
                vfunc_4();
                vfunc_3();
            }
            else if (2 < nTab && nTab < 6)
            {
                int nSlotUse = (int)FUN_140cbdc40(m_nPet);
                int nSlotMax = (int)FUN_140cbdc80(m_nPet);
                MS2Ptr<ASTextField> count = inv->FUN_1409b4620(CString("m_slotUseCount"));
                if (count.get() != 0)
                    count->FUN_1422c4cd0(FUN_140811740(0xc11, nSlotUse, nSlotMax));
            }
        }
    }
}

// ---- PetInfoSkill ----

// @0x140cbada0
PetInfoSkill::PetInfoSkill(int nPet)
    : PetInfoBase(nPet)
{
}

// @0x140cbade0
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
void PetInfoSkill::vfunc_3()
{
    MS2Ptr<ASUIComponent> skill = m_ui->FUN_140accfb0<ASUIComponent>(CString("m_skill"));
    if (skill == 0)
        return;
    skill->vfunc_3(FUN_140cbd9d0(m_nPet));
    MS2Ptr<Unk_StatList> list = PI(skill)->FUN_140bc7280(CString("m_scrollingList"));
    if (list.get() != 0)
    {
        list->FUN_1422dd1d0();
        FUN_140cbb060(list);
        list->vfunc_24(1);
    }
}
MS2_REPLACE_METHOD(0x140cbade0, PetInfoSkill, vfunc_3, 428, 0x4BEDBB40);

// @0x140cbafa0
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
void PetInfoSkill::vfunc_5(int nTab)
{
    if (-1 < nTab && nTab < 3)
        vfunc_3();
}
MS2_REPLACE_METHOD(0x140cbafa0, PetInfoSkill, vfunc_5, 58, 0x11111BFC);

// @0x140cbafe0
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
int PetInfoSkill::vfunc_6(const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned nArgs)
{
    if (_stricmp("OnAutoItemUse", szEvent) == 0)
    {
        FUN_140cbb720();
        return 1;
    }
    if (_stricmp("OnAutoItemPick", szEvent) == 0)
    {
        FUN_140cbb750();
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140cbafe0, PetInfoSkill, vfunc_6, 107, 0x987A440E);

// @0x140cbb060
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
// MS2-FUNCTIONAL: exe call-result temporaries / frame-slot order differ (source form not found)
void PetInfoSkill::FUN_140cbb060(MS2Ptr<Unk_StatList> list)
{
    MS2Ptr<Unk_PetRow> row = FUN_140cbda70(m_nPet);
    if (row == 0)
        return;
    CString strDir(".\\Data\\Resource\\Image\\skill\\icon\\");
    {
        ASObj obj(2);
        obj.FUN_1409c0dc0("buffName", "$s_petsetting_auto_revive");
        obj.FUN_1409c0dc0("buttonTooltip", "$s_petsetting_tooltip_revive");
        obj.FUN_1407cba60(s_iconPath, FUN_14038f6d0(strDir, "pet_Buff_Tombstone.png"));
        list->FUN_1422dd230(obj);
    }
    {
        ASObj obj(2);
        if (m_nPet != 0)
        {
            obj.FUN_1409c0dc0("button", "onAutoItemUse");
            obj.FUN_1409c0dc0("buttonTooltip", "$s_petsetting_tooltip_auto_itemuse");
        }
        obj.FUN_1409c0dc0("buffName", "$s_petsetting_auto_itemuse");
        obj.FUN_1409c0dc0("buffTooltip", "$s_petsetting_auto_itemuse_desc");
        obj.FUN_1407cba60(s_iconPath, FUN_14038f6d0(strDir, "pet_Buff_AutoPotion.png"));
        list->FUN_1422dd230(obj);
    }
    {
        ASObj obj(2);
        if (m_nPet != 0)
        {
            obj.FUN_1409c0dc0("button", "onAutoItemPick");
            obj.FUN_1409c0dc0("buttonTooltip", "$s_petsetting_tooltip_auto_itempick");
        }
        obj.FUN_1409c0dc0("buffName", "$s_petsetting_auto_itempick");
        obj.FUN_1409c0dc0("buffTooltip", "$s_petsetting_auto_itempick_desc");
        obj.FUN_1407cba60(s_iconPath, FUN_14038f6d0(strDir, "pet_Buff_ItemGet.png"));
        list->FUN_1422dd230(obj);
    }
    void* pos = row->m_skills.FUN_14063f420();
    while (pos != 0)
    {
        unsigned short nLevel = *row->m_skills.FUN_14063f490(pos);
        unsigned nSkillId = *row->m_skills.FUN_14063f360(pos);
        MS2Ptr<Unk_PiSkillRec> rec = FUN_1401958b0()->FUN_140aafef0(nSkillId, nLevel);
        if (rec == 0)
        {
            CStringW strName = FUN_14052bd00(0xc18, FUN_1401a9d70()->FUN_141812290(nSkillId, nLevel, CString("name")));
            CStringW strTip = FUN_1401a9d70()->FUN_141812290(nSkillId, nLevel, CString("tooltipDescription"));
            ASObj obj(2);
            obj.FUN_1407cbb20("buffName", CStringW(strName));
            obj.FUN_1407cbb20("buffTooltip", CStringW(strTip));
            obj.FUN_1407cba60(s_iconPath, CString(rec->m_strIcon));
            list->FUN_1422dd230(obj);
        }
        row->m_skills.FUN_14063f3d0(pos);
    }
}

// @0x140cbb720
void PetInfoSkill::FUN_140cbb720()
{
    FUN_1403ed2b0()->FUN_141adc530(0x4ef4);
}
MS2_REPLACE_METHOD(0x140cbb720, PetInfoSkill, FUN_140cbb720, 32, 0x17AA8321);

// @0x140cbb750
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
void PetInfoSkill::FUN_140cbb750()
{
    UIItemAutoUseOptionDialog* pAuto = FUN_140cbe1c0(0x4ef4);
    if (pAuto == 0 || pAuto->vfunc_55() != 0)
    {
        UIItemGetOptionDialog* pGet = FUN_140cbe260(0x4e6c);
        if (pGet != 0)
        {
            pGet->FUN_1419da620(0);
            FUN_1403ed2b0()->FUN_141adc530(0x4e6c);
        }
    }
}
MS2_REPLACE_METHOD(0x140cbb750, PetInfoSkill, FUN_140cbb750, 115, 0xF0ADC00D);

// ---- PetInfoStat ----

// @0x140cbb7d0
PetInfoStat::PetInfoStat(int nPet)
    : PetInfoBase(nPet)
{
}

// @0x140cbb810
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
// MS2-FUNCTIONAL: exe call-result temporaries / frame-slot order differ (source form not found)
void PetInfoStat::vfunc_3()
{
    MS2Ptr<ASUIComponent> stat = m_ui->FUN_140accfb0<ASUIComponent>(CString("m_stat"));
    if (stat == 0)
        return;
    stat->vfunc_3(FUN_140cbd9d0(m_nPet));
    MS2Ptr<CItem> pet = FUN_140cbd900(m_nPet);
    if (pet == 0)
        return;
    CStringW strText = FUN_1409e34e0(MS2Ptr<CItem>(pet));
    ASObj obj(2);
    if (strText.IsEmpty())
        obj.FUN_1407cbb20("itemGuideDescription", FUN_14028b8e0(CStringW(L"s_word_not_option")));
    else
        obj.FUN_1407cbb20("itemDescription", CStringW(strText));
    PI(stat)->FUN_1422bb7e0(obj);
}

// @0x140cbba70
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
void PetInfoStat::vfunc_5(int nTab)
{
    if (-1 < nTab && nTab < 3)
        vfunc_3();
}
MS2_REPLACE_METHOD(0x140cbba70, PetInfoStat, vfunc_5, 58, 0x11111BFC);

// ---- PetInfoPreview ----

// @0x140cbbab0
PetInfoPreview::PetInfoPreview(int nPet)
    : PetInfoBase(nPet)
{
}

// @0x140cbbb30
void PetInfoPreview::vfunc_2()
{
    FUN_140cbc3b0();
    m_avatar = 0;
}
MS2_REPLACE_METHOD(0x140cbbb30, PetInfoPreview, vfunc_2, 43, 0x23189DED);

// @0x140cbbb70
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
// MS2-FUNCTIONAL: exe call-result temporaries / frame-slot order differ (source form not found)
void PetInfoPreview::vfunc_3()
{
    MS2Ptr<ASUIComponent> preview = m_ui->FUN_140accfb0<ASUIComponent>(CString("m_preview"));
    if (preview == 0)
        return;
    MS2Ptr<CItem> pet = FUN_140cbd900(m_nPet);
    if (pet == 0)
        return;
    MS2Ptr<CItemData> data(pet->FUN_140527840());
    if (data == 0)
        return;
    if (m_avatar.get() == 0)
    {
        UIAvatarPet* pAvatar = new UIAvatarPet(data.get());
        m_avatar.AssignRaw(pAvatar);
        m_avatar->vfunc_1(static_cast<IUIAvatarEventListener*>(this));
    }
    else
    {
        m_avatar->FUN_1418bebd0(data.get());
    }
    PI(preview)->FUN_140caf230("setGrade", pet->FUN_140526bd0());
}

// @0x140cbbe20
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
void PetInfoPreview::vfunc_4()
{
    MS2Ptr<ASUIComponent> preview = m_ui->FUN_140accfb0<ASUIComponent>(CString("m_preview"));
    if (preview == 0)
    {
        preview->Invoke("setGrade", -1);
        FUN_140cbc3b0();
        m_avatar = 0;
    }
}
MS2_REPLACE_METHOD(0x140cbbe20, PetInfoPreview, vfunc_4, 206, 0xAB204F86);

// @0x140cbbf00
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
void PetInfoPreview::vfunc_5(int nTab)
{
    if (-1 < nTab)
    {
        if (nTab < 2)
        {
            vfunc_4();
            vfunc_3();
        }
        else if (nTab == 2)
        {
            vfunc_4();
        }
    }
}
MS2_REPLACE_METHOD(0x140cbbf00, PetInfoPreview, vfunc_5, 99, 0xF5492657);

// @0x140cbbf70
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
int PetInfoPreview::vfunc_6(const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned nArgs)
{
    if (m_avatar.get() != 0)
    {
        if (m_avatar->vfunc_27(szEvent, pArgs, nArgs) != 0)
            return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140cbbf70, PetInfoPreview, vfunc_6, 141, 0x2E16512C);

// @0x140cbc010
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
// MS2-FUNCTIONAL: camera data frame layout differs
void PetInfoPreview::vfunc_7(void* a1, TPtr<Unk_UISwfEntity_25> a2, void* a3, void* a4)
{
    if (a2.get() == 0 && a3 != 0)
    {
        if (!(m_avatar == 0))
        {
            Unk_PetBoxActor* actor = reinterpret_cast<Unk_PetBoxActor*>(m_avatar->vfunc_24());
            if (actor != 0)
            {
                m_avatar->vfunc_28(a1, a2, a3);
                Unk_PetBoxCameraData data;
                data.FUN_141b48670();
                data.n28 = 5;
                data.f20 = 100.0f;
                data.f1c = 500.0f;
                data.eye = actor->vfunc_18();
                reinterpret_cast<Unk_PetBoxCamera*>(m_avatar->m_spView.operator->())->vfunc_13(data);
                m_avatar->vfunc_19(FUN_141b48480(0xb, 0), 0);
            }
        }
    }
}

// @0x140cbc2b0
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
int PetInfoPreview::vfunc_o178_1(void* pAvatar)
{
    if (pAvatar != 0)
        FUN_140cbc2f0();
    return pAvatar != 0;
}
MS2_REPLACE_METHOD(0x140cbc2b0, PetInfoPreview, vfunc_o178_1, 53, 0x7BF5F3B7);

// @0x140cbc2f0
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
void PetInfoPreview::FUN_140cbc2f0()
{
    MS2Ptr<ASUIComponent> preview = m_ui->FUN_140accfb0<ASUIComponent>(CString("m_preview"));
    if (preview == 0)
    {
        preview->Invoke("loadRenderTarget");
    }
}
MS2_REPLACE_METHOD(0x140cbc2f0, PetInfoPreview, FUN_140cbc2f0, 171, 0xCB55F5EA);

// @0x140cbc3b0
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
void PetInfoPreview::FUN_140cbc3b0()
{
    MS2Ptr<ASUIComponent> preview = m_ui->FUN_140accfb0<ASUIComponent>(CString("m_preview"));
    if (preview == 0)
    {
        preview->Invoke("unloadRenderTarget");
    }
}
MS2_REPLACE_METHOD(0x140cbc3b0, PetInfoPreview, FUN_140cbc3b0, 171, 0xFA72F638);

// ---- TabContentsPetInfo::EquipSlot ----

// @0x140cbc470
TabContentsPetInfo::EquipSlot::EquipSlot(const CString& strName, int nIndex, int nPet)
    : MS2DragSlot(strName, nIndex)
{
    m_nPet = nPet;
}

// @0x140cbc4e0
TabContentsPetInfo::EquipSlot::~EquipSlot()
{
}

// @0x140cbc520
int TabContentsPetInfo::EquipSlot::vfunc_13()
{
    if (m_nPet == 0)
        return 0;
    Unk_PetPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    MS2Ptr<CItem> pet = FUN_140cbd900(m_nPet);
    if (pet == 0)
        return 0;
    pPlayer->FUN_14152b800(pet->FUN_140526a50());
    return 1;
}

// @0x140cbc5f0
int TabContentsPetInfo::EquipSlot::vfunc_14()
{
    if (m_nPet == 0)
        return 0;
    Unk_PetPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    MS2Ptr<CItem> pet = FUN_140cbd900(m_nPet);
    if (pet == 0)
        return 0;
    pPlayer->FUN_14152b800(pet->FUN_140526a50());
    return 1;
}

// @0x140cbc6c0
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
int TabContentsPetInfo::EquipSlot::vfunc_18(void* p)
{
    DragSlot* pDrag = static_cast<DragSlot*>(p);
    if (m_nPet == 0)
        return pDrag->vfunc_10();
    void* pItemSlot = FUN_140a50b50(pDrag);
    if (pItemSlot != 0)
    {
        Unk_PetPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPlayer == 0)
            return pDrag->vfunc_10();
        MS2Ptr<CItem> pet = FUN_140cbd900(m_nPet);
        if (!(pet == 0))
            return pDrag->vfunc_10();
        pPlayer->FUN_14152b2d0(FUN_141405a10(pItemSlot));
    }
    return pDrag->vfunc_10();
}

// @0x140cbc7d0 (ITooltip::vfunc_0)
int TabContentsPetInfo::EquipSlot::vfunc_0(void* p)
{
    Unk_PetPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    MS2Ptr<CItem> pet = FUN_140cbd900(m_nPet);
    if (pet == 0)
        return 0;
    ASTooltip tip(pPlayer, 0x100, 2);
    if (tip.FUN_1409e0d40(pet.get()) == 0)
        return 0;
    if (m_nPet != 0)
        tip.FUN_1409c69b0(vfunc_22());
    *static_cast<Scaleform::GFx::Value*>(p) = tip.FUN_1422bb870();
    return 1;
}

// @0x140cbc960
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
int TabContentsPetInfo::EquipSlot::vfunc_8(void* p)
{
    Unk_PetPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    MS2Ptr<CItem> pet = FUN_140cbd900(m_nPet);
    if (pet == 0)
        return 0;
    ASSlot slot(2);
    if (slot.FUN_1409c3860(pet.get(), pPlayer, 0x49) == 0)
        return 0;
    if (m_nPet != 0)
        slot.FUN_1409c3750(true);
    *static_cast<Scaleform::GFx::Value*>(p) = slot.FUN_1422bb870();
    return 1;
}

// @0x140cbcab0
MS2Ptr<CItem> TabContentsPetInfo::EquipSlot::vfunc_25()
{
    return FUN_140cbd900(m_nPet);
}

// @0x140cbcb00
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
int TabContentsPetInfo::EquipSlot::FUN_140cbcb00()
{
    MS2Ptr<CItem> pet = FUN_140cbd900(m_nPet);
    if (pet == 0)
        return 0;
    return (int)pet->FUN_140526a50();
}

// ---- TabContentsPetInfo::EquipSlotBag ----

// @0x140cbcca0
TabContentsPetInfo::EquipSlotBag::EquipSlotBag(const CString& strName, int nPet)
    : DragSlotBag(strName)
{
    m_nPet = nPet;
}

// @0x140cbccf0
TabContentsPetInfo::EquipSlotBag::~EquipSlotBag()
{
}

// @0x140cbcd20
CString TabContentsPetInfo::EquipSlotBag::vfunc_15(int nIndex)
{
    CString str;
    str.Format("%s.EQUIP%d", (const char*)FUN_1422c89f0(), nIndex);
    return str;
}

// @0x140cbcde0
DragSlot* TabContentsPetInfo::EquipSlotBag::vfunc_16(int nIndex)
{
    CString strName = vfunc_15(nIndex);
    return new (efd::MemHint(efd::MemHint::NONE)) EquipSlot(strName, nIndex, m_nPet);
}

// ---- TabContentsPetInfo ----

// @0x140cbcea0
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
TabContentsPetInfo::TabContentsPetInfo(int nPet)
    : m_nPet(nPet), m_parts(10), m_ui(0)
{
    m_parts.AddTail(MS2Ptr<PetInfoBase>(new PetInfoStat(nPet)));
    m_parts.AddTail(MS2Ptr<PetInfoBase>(new PetInfoSkill(nPet)));
    m_parts.AddTail(MS2Ptr<PetInfoBase>(new PetInfoBasic(nPet)));
    m_parts.AddTail(MS2Ptr<PetInfoBase>(new PetInfoInventory(nPet)));
    m_parts.AddTail(MS2Ptr<PetInfoBase>(new PetInfoPreview(nPet)));
}

// @0x140cbd1e0
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
void TabContentsPetInfo::vfunc_1()
{
    POSITION pos = m_parts.GetHeadPosition();
    while (pos != 0)
    {
        MS2Ptr<PetInfoBase> p = m_parts.GetAt(pos);
        if (!(p == 0))
            p->vfunc_1();
        m_parts.GetNext(pos);
    }
    m_ui = 0;
}
MS2_REPLACE_METHOD(0x140cbd1e0, TabContentsPetInfo, vfunc_1, 210, 0x17B51641);

// @0x140cbd2c0
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
void TabContentsPetInfo::vfunc_4()
{
    POSITION pos = m_parts.GetHeadPosition();
    while (pos != 0)
    {
        MS2Ptr<PetInfoBase> p = m_parts.GetAt(pos);
        if (!(p == 0))
            p->vfunc_2();
        m_parts.GetNext(pos);
    }
}
MS2_REPLACE_METHOD(0x140cbd2c0, TabContentsPetInfo, vfunc_4, 191, 0x7C10A29A);

// @0x140cbd390
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
void TabContentsPetInfo::vfunc_2(int nTab)
{
    if (m_ui == 0)
    {
        FUN_140cbd870();
        POSITION pos = m_parts.GetHeadPosition();
        while (pos != 0)
        {
            MS2Ptr<PetInfoBase> p = m_parts.GetAt(pos);
            if (!(p == 0))
                p->vfunc_5(nTab);
            m_parts.GetNext(pos);
        }
    }
}
MS2_REPLACE_METHOD(0x140cbd390, TabContentsPetInfo, vfunc_2, 240, 0x0D977286);

// @0x140cbd490
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
void TabContentsPetInfo::vfunc_3(MS2Ptr<ASUIComponent> ui)
{
    m_ui = ui;
    FUN_140cbd870();
    POSITION pos = m_parts.GetHeadPosition();
    while (pos != 0)
    {
        MS2Ptr<PetInfoBase> p = m_parts.GetAt(pos);
        if (!(p == 0))
        {
            FUN_140cbf150(p.operator->(), ui);
            p->vfunc_4();
            p->vfunc_3();
        }
        m_parts.GetNext(pos);
    }
}
MS2_REPLACE_METHOD(0x140cbd490, TabContentsPetInfo, vfunc_3, 367, 0x133CF189);

// @0x140cbd610
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
int TabContentsPetInfo::vfunc_6(const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned nArgs)
{
    POSITION pos = m_parts.GetHeadPosition();
    while (pos != 0)
    {
        MS2Ptr<PetInfoBase> p = m_parts.GetAt(pos);
        if (!(p == 0))
        {
            if (p->vfunc_6(szEvent, pArgs, nArgs) != 0)
                return 1;
        }
        m_parts.GetNext(pos);
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140cbd610, TabContentsPetInfo, vfunc_6, 254, 0x7C9509A4);

// @0x140cbd720
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
void TabContentsPetInfo::vfunc_7(void* a1, TPtr<Unk_UISwfEntity_25> a2, void* a3, void* a4)
{
    POSITION pos = m_parts.GetHeadPosition();
    while (pos != 0)
    {
        MS2Ptr<PetInfoBase> p = m_parts.GetAt(pos);
        if (!(p == 0))
            p->vfunc_7(a1, a2, a3, a4);
        m_parts.GetNext(pos);
    }
}
MS2_REPLACE_METHOD(0x140cbd720, TabContentsPetInfo, vfunc_7, 299, 0x5E0FE79E);

// @0x140cbd860
int TabContentsPetInfo::vfunc_8()
{
    return 0;
}
MS2_REPLACE_METHOD(0x140cbd860, TabContentsPetInfo, vfunc_8, 8, 0x7F371472);

// @0x140cbd870
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
void TabContentsPetInfo::FUN_140cbd870()
{
    if (m_ui.get() != 0)
        m_ui->Invoke("summon", FUN_140cbd9d0(m_nPet) != 0);
}
MS2_REPLACE_METHOD(0x140cbd870, TabContentsPetInfo, FUN_140cbd870, 127, 0x4557D135);

// ---- PetInfoBase ----

// @0x140cbf5d0
CRuntimeClass* FUN_140cbf5d0()
{
    return CDialogEx::GetThisClass();
}

// @0x140cbf150 (assigns the page's UI to a part)
void FUN_140cbf150(PetInfoBase* p, MS2Ptr<ASUIComponent> ui)
{
    p->m_ui = ui;
}

// @0x140cbe890
bool FUN_140cbe890(__int64* p, __int64 n)
{
    return *p == n;
}

// @0x140cbf030
void PetInfoBase::vfunc_7(void* a1, TPtr<Unk_UISwfEntity_25> a2, void* a3, void* a4)
{
}
MS2_REPLACE_METHOD(0x140cbf030, PetInfoBase, vfunc_7, 39, 0x545687CB);

// @0x140cbe780
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
PetInfoBasic::~PetInfoBasic() {}
// @0x140cbe7b0
PetInfoInventory::~PetInfoInventory() {}
// @0x140cbe7e0
PetInfoPreview::~PetInfoPreview() {}
// @0x140cbe810
PetInfoSkill::~PetInfoSkill() {}
// @0x140cbe830
PetInfoStat::~PetInfoStat() {}

// @0x140cbe650
inline PetInfoBase::PetInfoBase(int nPet)
    : m_nPet(nPet)
{
}

// @0x140cbe740
inline PetInfoBase::~PetInfoBase()
{
}

// @0x140cbe850
// MS2-FUNCTIONAL: not byte-exact yet (local slot order / branch layout differ)
inline TabContentsPetInfo::~TabContentsPetInfo()
{
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca3dc0-0x142ca3ef0 .text$yd
