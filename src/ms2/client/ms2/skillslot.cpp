// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). SkillSlot and SkillSlotBag (the quick slot / skill window
// slots) and the CSkillSystem of the local player (cooldown table, skill sets, skill cast requests).
// MS2-UNIT: ?\skillslot.cpp
// MS2-RANGE: 0x14175c840-0x14176f2a0 .text$mn
// MS2-RANGE: 0x140100bf0-0x140101560 .text$di
// MS2-PIN: ??_7SkillSlot@@6BBindData@NotifyContext@@@ 0x14310c898 ; hand: primary vftable
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\skillslot.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "skillslot.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asslot.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/commonfiles/skilloverlapcompare.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/bookslot.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/inventory.h"
#include "hook/ms2hook.h"
#include <efd/MemHint.h>
#include <efd/MemObject.h>

// ---- out-of-unit callees ----
class Unk_ItemEquipData : public CItemData { };          // CItem::FUN_140527840's record

extern Unk_Inventory DAT_143ab2a90;                       // the player's inventory
extern bool DAT_143ae9750;                                // the debug switch "SkillSlotNotFind"

// The quick slot entry of a slot index (the saved shortcut): a skill, or an item id + uid.
struct Unk_SsQuickEntry
{
    int m_nSkillId;                                       // +0x00
    __int64 m_nItemUid;                                   // +0x08
    int m_nItemId;                                        // +0x10
    Unk_SsQuickEntry() : m_nSkillId(0), m_nItemUid(0), m_nItemId(0) {}   // 0x141253e20
};

// The quick slot manager (0x1409331f0): the saved entries, the key bindings and the page.
class Unk_SsHud
{
public:
    int FUN_140a700b0();                                  // the current page
    void FUN_14142b250(int nKey, int nFlag, __int64 nSlotKey, int nSkillId, int nMode);   // bind a skill to a key
    int FUN_14142c940(__int64 nAction, int nMode);        // the key bound to the action
    int FUN_14142cb40(int nSlot, int nMode);              // the key bound to the slot
    CStringW FUN_14142d220(int nKey);                     // the text of a key
    bool FUN_14142e030(int nSlot, Unk_SsQuickEntry* pOut);   // the saved entry of a slot
    int FUN_14142e150(int nSkillId, int nItemId, __int64 nItemUid);   // the slot of an entry (-1: none)
    void FUN_14142e2a0(int nSlot, Unk_SsQuickEntry* pEntry);   // save the entry of a slot
};
Unk_SsHud* FUN_1409331f0();

// The own player: the world's local player pointer.
class Unk_SsPc : public PC
{
public:
    class Unk_SsSkillBook* FUN_1416546d0();               // the learned skills
};
class Unk_SsSkillBook
{
public:
    virtual void v0();
    virtual MS2Ptr<SkillLevelData> vfunc_1(int nSkillId);   // 1 the learned level of a skill
    virtual bool vfunc_2(int nSkillId);                     // 2 the skill is learned
};
class Unk_SsBuffs
{
public:
    int FUN_140970020(unsigned nEffectId, unsigned short nLevel, unsigned nOverlap, int n);   // the buff is on
    unsigned FUN_140970bf0();                             // the mask of the blocked skill types
    int FUN_140970a60(int nSkillId);                      // the skill is blocked
};
class Unk_SsMapInfo : public CPtred
{
public:
    unsigned char m_pad[0xa8 - sizeof(CPtred)];
    int m_nField;                                         // +0xa8
};
class Unk_SsWorld
{
public:
    Unk_SsPc* FUN_141bd0cc0();
    void FUN_141bc9fd0(int nSlot);                        // use the quick slot
    MS2Ptr<Unk_SsMapInfo> FUN_141bd30a0();                // the map info
    bool FUN_141bcb210();
};
Unk_SsWorld* FUN_1403ed2d0();

SkillDataTable* FUN_1401958b0();                          // the skill table
void FUN_14092f4e0(int nSkillId);                         // use a skill
int FUN_14092f690(int nSkillId, int nItemId, __int64 nItemUid, int nPage, int nSlot);   // put an entry on a quick slot
int FUN_14092fef0(int nSkillId, int nItemId, __int64 nItemUid, int nPage, int nSlot);   // the entry may be put on a quick slot
bool FUN_140930d70();                                     // the quick slots are synced to the server
void FUN_141275260(int nNotice, int a, int b);            // a system notice by id
void FUN_1412751f0(const CStringW& strText, int a, int b);   // a system notice
void FUN_141276180(const CString& strSound, const CString& strArg);   // play a ui sound
CStringW FUN_14028b8e0(const CStringW& strKey);           // string table text
CStringW FUN_14028de60(int nStringId);                    // string table text by id
bool FUN_140614800(const Scaleform::GFx::Value& fn);
bool FUN_140ba28d0(const MS2Ptr<AScript>* pAS, int n);    // has the AS object been released
MS2Ptr<AScript> FUN_140d019b0(MS2Ptr<AScript> spObj, const CString& strName);   // the AS function of an AS object
Scaleform::GFx::Value FUN_1422bb3c0(AScript* pFn);

// The item data record pointer (ref-counted; dtor 0x1401b50d0).
class Unk_SsItemPtr
{
public:
    Unk_SsItemPtr(void* pData);                           // 0x1401bf970
    ~Unk_SsItemPtr();                                     // 0x1401b50d0
    bool FUN_1402ffd90() const;                           // is it null
    CItemData* FUN_1401b52a0() const;                     // get
private:
    void* m_pad;
    void* m_p;
};
Unk_SsItemPtr FUN_14053f870(unsigned __int64 nItemId);    // the item data record of an item id
int FUN_141769320(Unk_SsItemPtr kPtr);                    // the skill id of the item

// The skill set of a ridee (see CSkillSystem::FUN_141768380).
class Unk_MyPCSkillSet : public CPtred
{
public:
    unsigned char m_pad0[0x28 - sizeof(CPtred)];
    std::vector<unsigned> m_vSkills;                      // +0x28
    unsigned char m_pad1[0x88 - 0x28 - sizeof(std::vector<unsigned>)];
    std::vector<unsigned> m_vItems;                       // +0x88
};

class Unk_SsContentSwitch { public: char FUN_14036d570(int nFeature); };
Unk_SsContentSwitch* FUN_140166410();
class Unk_SsDevice { public: Unk_SsDevice* FUN_14116d7a0(int n); };
Unk_SsDevice* FUN_14025e7c0();
class Unk_SsStringTable { public: CStringW FUN_141811980(int nType, int nId); };
Unk_SsStringTable* FUN_1401a9d70();
class Unk_SsItemTable { public: int FUN_1405b5890(int nItemId); };
Unk_SsItemTable* FUN_1409c4b30();

class Unk_SsSkillUi
{
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void vfunc_16(int nIndex, int nSkillId, void* p, float fRemain);   // 16 start the cooldown tween
    virtual void vfunc_17(int nIndex);                                         // 17 stop it
};
Unk_SsSkillUi* FUN_140a94350();

class Unk_SsInvSlot : public MS2DragSlot { };
class Unk_SsItemSlot : public MS2DragSlot { };
Unk_SsInvSlot* FUN_140a50b50(DragSlot* p);
Unk_SsItemSlot* FUN_140a6fef0(DragSlot* p);
int FUN_140a6f880(Unk_SsItemSlot* p);
void FUN_1414058f0(Unk_SsInvSlot* p);
__int64 FUN_141405a10(Unk_SsInvSlot* p);
int FUN_141405980(Unk_SsInvSlot* p);
int FUN_141404ce0(int nSkillId, void* p, Scaleform::GFx::Value* pValue);
int FUN_1414050c0(int nSkillId, void* p, Scaleform::GFx::Value* pValue);
int FUN_141404ce0(int nSkillId, unsigned __int64 nKey, Scaleform::GFx::Value* pValue);
int FUN_1414050c0(int nSkillId, unsigned __int64 nKey, Scaleform::GFx::Value* pValue);
class Unk_SsUgcMgr
{
public:
    void FUN_141b38be0(UIUGCEventListener* p);
    void FUN_141b38c70(UIUGCEventListener* p);
};
Unk_SsUgcMgr* FUN_140bc09f0();
void FUN_1414049c0(void* p, int nSkillId);
void FUN_140165270(ATL::CAtlArray<CString>& arr, const CString& str);
CString FUN_140719190(int n);
CString FUN_140719530(__int64 n);
bool FUN_14028d780(int n);
bool FUN_140534e50(const MS2Ptr<CItem>& sp);
int FUN_14053feb0(int nItemId);
void FUN_1409b4bc0(void* pDst, const Scaleform::GFx::Value& v);
void FUN_140d73bc0(int nNoticeId, int a, int b, CStringW str);
int FUN_140526810(CItem* pItem, unsigned short nLevel);
MS2Ptr<SkillData> FUN_140639210(int nSkillId);

// AScript as the function object: invoke with an ASArgList.
class Unk_SsFn : public AScript
{
public:
    Scaleform::GFx::Value FUN_1422bb9f0(ASArgList& args);
};
Scaleform::GFx::Value FUN_141761eb0(AScript* pFn, unsigned nElement, CString strIcon, int nGray, int nFlag);
Scaleform::GFx::Value FUN_141761fc0(AScript* pFn, CString strIcon, int nGray, int nFlag);
Scaleform::GFx::Value FUN_1417620b0(AScript* pFn, Scaleform::GFx::Value kArg);
Scaleform::GFx::Value FUN_141762190(AScript* pFn, bool bShow, int nCount);
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
void FUN_1422bcd10(Scaleform::GFx::Value* pValue, unsigned n);
void FUN_1422bce70(Scaleform::GFx::Value* pValue, const char* sz);
void FUN_1422bcc70(Scaleform::GFx::Value* pValue, Scaleform::GFx::Value kValue);
void FUN_1422bcce0(Scaleform::GFx::Value* pValue, bool b);

class Unk_SsDragMgr
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3(SkillSlot* pSlot);               // 3 a drag starts on the slot
    virtual void vfunc_4(SkillSlot* pSlot);               // 4 the drag ends on the slot
};
Unk_SsDragMgr* FUN_14140ea40();

// Registry of named bags/slots (GFx bind data).
void FUN_1422c8f10(const CString& strName, NotifyContext::BindData* pBag);
NotifyContext::BindData* FUN_1422c8e90(const CString& strName);
void FUN_1422c8f70(const CString& strName);
void FUN_1422cc9e0(DragSlotBag* pBag);
DragSlot* FUN_1422cd0f0(DragSlotBag* pBag, const CString& strName);   // the slot of the bag by name
void* FUN_14208a860(unsigned __int64 nSize, unsigned nCategory);
void FUN_1419f37f0(int n);                                // refresh the skill ui
void* FUN_140aa6d40();                                    // the skill bar ui (or null)
void FUN_141b0e260(void* pBar, __int64 nKey);             // the skill bar: cooldown start
void FUN_141b0e2f0(void* pBar, __int64 nKey);             // the skill bar: cooldown end
bool FUN_1401647e0(const CString& a, const CString& b);   // the strings differ

SkillSlot* FUN_141761e60(DragSlot* p);
BookSlot* FUN_141761e10(DragSlot* p);
SkillSlotBag* FUN_141763cb0(NotifyContext::BindData* p);

EE_IMPLEMENT_CONCRETE_CLASS_INFO(SkillSlot);

static CString s_strDisableDrag = "disableDrag";
static CString s_strDropShadowDisable = "dropShadowDisable";
static CString s_strGrayColor = "grayColor";
static CString s_strIconPath = "iconPath";
static CString s_strItemCount = "itemCount";
static CString s_strItemGrade = "itemGrade";
static CString s_strItemLock = "itemLock";
static CString s_strItemPcBang = "itemPcBang";
static CString s_strItemPet = "itemPet";
static CString s_strItemVIP = "itemVIP";
static CString s_strItemPetRank = "itemPetRank";
static CString s_strRechargeRemainCount = "rechargeRemainCount";
static CString s_strShortcutKey = "shortcutKey";
static CString s_strUgcTag = "ugctag";

// Header-defined statics (same in every obj that includes the shared item header).
#include "ms2/placeholder/header_statics_a.h"

static CString s_strButtonClickA = "button_click";
static CString s_strButtonClickB = "button_click";

EE_IMPLEMENT_CONCRETE_CLASS_INFO(SkillSlotBag);

// The second and third copies of the header statics.
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_unk1402a9d70_2(17, 0.75f, 0.25f, 2.25f, 10);
static CString s_strSortTypeNames3[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill3 = "skill";
static CString s_strStun3 = "stun";
static Unk_1402a9d70 s_unk1402a9d70_3(17, 0.75f, 0.25f, 2.25f, 10);

static CString s_strNoticeFailSkillIncorrectWeapon = "notice_battle_failskill_incorect_weapon";
static CString s_strNoticeErrorEp = "system_notice_error_ep";
static CString s_strNoticeErrorSp = "system_notice_error_sp";
static CString s_strNoticeErrorNotThisPlace = "system_notice_error_warningNotThisPlace";
static CString s_strNoticeErrorWarningWeapon = "system_notice_error_warningWeapon";
static CString s_strNoticeErrorNotThisTime = "system_notice_error_warningNotThisTime";
static CString s_strSortTypeNames4[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// @0x14175c840
SkillSlot::SkillSlot(const CString& strName, int nIndex, int nSkillId, int nItemId, __int64 nItemUid)
    : MS2DragSlot(strName, nIndex), m_nDisabled(0), m_nItemCount(0), m_nRecharge(0), m_bUsable(false), m_bCooling(false),
      m_nSkillId(nSkillId), m_nItemUid(nItemUid), m_nItemId(nItemId), m_bFixed(0), m_kKeys(10)
{
    int nKey0 = 0x493e3;
    m_kKeys.SetAt(0x16, nKey0);
    int nKey1 = 0x49401;
    m_kKeys.SetAt(0x17, nKey1);
    int nKey2 = 0x493e1;
    m_kKeys.SetAt(0x18, nKey2);
}


// @0x14175ca40
void SkillSlot::vfunc_6(void* p)
{
    ATL::CAtlArray<CString>& arr = *static_cast<ATL::CAtlArray<CString>*>(p);
    FUN_140165270(arr, FUN_140719190(FUN_141760980(0)));
    FUN_140165270(arr, FUN_140719530(FUN_141760a10()));
    int nValue = 0;
    if (m_kKeys.Lookup(m_nIndex, nValue))
        FUN_140165270(arr, FUN_140719530(nValue));
    FUN_1414049c0(p, FUN_14175cb90());
}

// @0x14175cb90
int SkillSlot::FUN_14175cb90()
{
    return m_nSkillId;
}

// @0x14175cbb0
void SkillSlot::FUN_14175cbb0(int nSkillId)
{
    m_nSkillId = nSkillId;
}

// @0x14175cbd0
__int64 SkillSlot::FUN_14175cbd0()
{
    return m_nItemUid;
}

// @0x14175cbf0
void SkillSlot::FUN_14175cbf0(__int64 nItemUid)
{
    m_nItemUid = nItemUid;
}

// @0x14175cc20
int SkillSlot::FUN_14175cc20()
{
    return m_nItemId;
}

// @0x14175cc40
void SkillSlot::FUN_14175cc40(int nItemId)
{
    m_nItemId = nItemId;
}

// @0x14175cc60
int SkillSlot::FUN_14175cc60()
{
    return 0;
}

// @0x14175cc70
void SkillSlot::FUN_14175cc70()
{
    __int64 nSlotKey = FUN_141760a10();
    int nKey = FUN_141760980(0);
    FUN_1409331f0()->FUN_14142b250(nKey, 1, nSlotKey, m_nSkillId, 0);
    nSlotKey = FUN_141760a10();
    nKey = FUN_141760980(1);
    FUN_1409331f0()->FUN_14142b250(nKey, 1, nSlotKey, m_nSkillId, 1);
    nSlotKey = FUN_141760a10();
    nKey = FUN_141760980(2);
    FUN_1409331f0()->FUN_14142b250(nKey, 1, nSlotKey, m_nSkillId, 2);
}

// @0x14175cd90
int SkillSlot::FUN_14175cd90()
{
    return m_bFixed;
}

// @0x14175cdb0
void SkillSlot::FUN_14175cdb0(int bFixed)
{
    m_bFixed = bFixed;
}

// @0x14175cdd0
int SkillSlot::vfunc_13()
{
    FUN_14175f200();
    MS2Ptr<CItem> spItem = vfunc_25();
    if (!(spItem == 0))
    {
        PC* pPc = static_cast<PC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
        if (pPc != 0)
        {
            unsigned short nLevel = (unsigned short)pPc->vfunc_78();
            if (FUN_140526810(spItem.operator->(), nLevel) == 0)
            {
                FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_err_not_enough_level")), 1, 1);
                return vfunc_10();
            }
        }
    }
    else if (m_nItemId != 0 && m_nItemUid != 0)
    {
        FUN_141275260(0xe6, 1, 1);
        return 0;
    }
    int nKey = FUN_141760980(0);
    if (nKey == 0)
    {
        int nSkillId = FUN_141761d90();
        MS2Ptr<SkillData> spSkill = FUN_1401958b0()->GetSkillData(nSkillId);
        if (spSkill.IsNull())
            return 0;
        PC* pPc = static_cast<PC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
        if (pPc == 0)
            return 0;
        MS2Ptr<Unk_MyPCSkillSet> spSet = static_cast<MyPC*>(pPc)->FUN_141523bc0()->FUN_141768380();
        if (spSet == 0)
        {
            Unk_SsPc* pSsPc = static_cast<Unk_SsPc*>(pPc);
            MS2Ptr<SkillLevelData> spLevel = pSsPc->FUN_1416546d0()->vfunc_1(nSkillId);
            if (spLevel.IsNull())
                return 0;
            if (spLevel->FUN_140804450())
            {
                FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_err_invalid_shortkey_code")), 1, 1);
                return 0;
            }
        }
        FUN_14092f4e0(FUN_14175cb90());
    }
    else
    {
        FUN_1403ed2d0()->FUN_141bc9fd0(nKey);
    }
    return vfunc_10();
}

// @0x14175d260
int SkillSlot::vfunc_14()
{
    if (FUN_141761990() == 0)
    {
        FUN_14175f200();
        return vfunc_17();
    }
    return 0;
}

// @0x14175d2b0
int SkillSlot::vfunc_17()
{
    if (FUN_141761990() == 0)
    {
        int nPage = FUN_1409331f0()->FUN_140a700b0();
        int nSlot = FUN_1422cc410();
        if (FUN_14092fef0(m_nSkillId, m_nItemId, m_nItemUid, nPage, nSlot) == 0)
        {
            vfunc_12();
            return 0;
        }
        if (FUN_140930d70())
        {
            Unk_SsQuickEntry kEntry;
            int nFound = FUN_1409331f0()->FUN_14142e150(m_nSkillId, m_nItemId, m_nItemUid);
            if (nFound != -1)
            {
                if (FUN_1409331f0()->FUN_14142e030(nFound, &kEntry))
                {
                    kEntry.m_nSkillId = 0;
                    kEntry.m_nItemId = 0;
                    kEntry.m_nItemUid = 0;
                    FUN_1409331f0()->FUN_14142e2a0(nFound, &kEntry);
                }
            }
        }
        return vfunc_11();
    }
    return 0;
}

// @0x14175d3f0
int SkillSlot::vfunc_11()
{
    m_nSkillId = 0;
    m_nItemUid = 0;
    m_nItemId = 0;
    m_bFixed = 0;
    m_strIcon.Empty();
    FUN_14175cc70();
    if (m_spClear.get() != 0)
    {
        CString strIcon(m_strIcon);
        FUN_141761fc0(m_spClear.operator->(), strIcon, 0, 1);
    }
    m_bUsable = true;
    return DragSlot::vfunc_11();
}

// @0x14175d530
int SkillSlot::vfunc_18(void* p)
{
    DragSlot* pFrom = static_cast<DragSlot*>(p);
    if (FUN_141761990() == 0)
    {
        SkillSlot* pSkillSlot = FUN_141761e60(pFrom);
        if (pSkillSlot == 0)
        {
            BookSlot* pBookSlot = FUN_141761e10(pFrom);
            if (pBookSlot == 0)
            {
                Unk_SsInvSlot* pInvSlot = FUN_140a50b50(pFrom);
                if (pInvSlot == 0)
                {
                    Unk_SsItemSlot* pItemSlot = FUN_140a6fef0(pFrom);
                    if (pItemSlot != 0 && FUN_140a6f880(pItemSlot) == 1)
                    {
                        MS2Ptr<CItem> spItem = pItemSlot->vfunc_25();
                        if (!(spItem == 0))
                        {
                            int nItemId = spItem->FUN_1405276c0();
                            if (FUN_1409c4b30()->FUN_1405b5890(nItemId) == 1)
                            {
                                Unk_SsPc* pPc = static_cast<Unk_SsPc*>(FUN_1403ed2d0()->FUN_141bd0cc0());
                                if (pPc != 0)
                                {
                                    if (static_cast<MyPC*>(static_cast<PC*>(pPc))->FUN_14152f860(spItem->FUN_1405276c0()) != 0)
                                    {
                                        int nPage = FUN_1409331f0()->FUN_140a700b0();
                                        int nSkillId = spItem->FUN_140527840()->FUN_14053dc20();
                                        int nSlot = FUN_1422cc410();
                                        if (FUN_14092f690(nSkillId, 0, 0, nPage, nSlot) != 0)
                                        {
                                            FUN_14175cbb0(nSkillId);
                                            FUN_14175cbf0(0);
                                            FUN_14175cc40(0);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                else
                {
                    FUN_1414058f0(pInvSlot);
                    __int64 nItemUid = FUN_141405a10(pInvSlot);
                    int nItemId = FUN_141405980(pInvSlot);
                    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nItemUid);
                    if (spItem.get() != 0 && spItem->FUN_140527840()->FUN_14053e460())
                    {
                        bool bUsable = true;
                        int nSkillId = FUN_141769320(Unk_SsItemPtr(spItem->FUN_140527840()));
                        if (!spItem->FUN_140527840()->FUN_14053cc80())
                        {
                            if (spItem->FUN_140526100() != 0)
                            {
                                nItemId = 0;
                                nItemUid = 0;
                                Unk_SsPc* pPc = static_cast<Unk_SsPc*>(FUN_1403ed2d0()->FUN_141bd0cc0());
                                if (pPc != 0)
                                {
                                    bUsable = static_cast<MyPC*>(static_cast<PC*>(pPc))->FUN_14152f860(spItem->FUN_1405276c0()) != 0;
                                    int nKey = spItem->FUN_1405276c0();
                                    if (FUN_1409c4b30()->FUN_1405b5890(nKey) != 1)
                                        bUsable = false;
                                }
                            }
                        }
                        else if (spItem->FUN_140525f10() != 0)
                        {
                            if (spItem->FUN_140525f60() == 0)
                            {
                                bUsable = false;
                                FUN_140d73bc0(0x2e8, 0, 0, CStringW(L""));
                            }
                        }
                        int nPage = FUN_1409331f0()->FUN_140a700b0();
                        if (bUsable)
                        {
                            int nSlot = FUN_1422cc410();
                            if (FUN_14092f690(nSkillId, nItemId, nItemUid, nPage, nSlot) != 0)
                            {
                                FUN_14175cbb0(nSkillId);
                                FUN_14175cbf0(nItemUid);
                                FUN_14175cc40(nItemId);
                                if (FUN_140930d70())
                                {
                                    Unk_SsQuickEntry kEntry;
                                    kEntry.m_nSkillId = nSkillId;
                                    kEntry.m_nItemUid = nItemUid;
                                    kEntry.m_nItemId = nItemId;
                                    int nSlotIdx = FUN_1422cc410();
                                    FUN_1409331f0()->FUN_14142e2a0(nSlotIdx, &kEntry);
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                int nPage = FUN_1409331f0()->FUN_140a700b0();
                int nSkillId = pBookSlot->FUN_140a366a0();
                int nSlot = FUN_1422cc410();
                if (FUN_14092f690(nSkillId, 0, 0, nPage, nSlot) != 0)
                {
                    FUN_14175cbb0(nSkillId);
                    FUN_14175cbf0(0);
                    FUN_14175cc40(0);
                }
            }
        }
        else
        {
            int nPage = FUN_1409331f0()->FUN_140a700b0();
            int nSkillId = pSkillSlot->FUN_14175cb90();
            __int64 nItemUid = pSkillSlot->FUN_14175cbd0();
            int nItemId = pSkillSlot->FUN_14175cc20();
            int nSlot = FUN_1422cc410();
            if (FUN_14092f690(nSkillId, nItemId, nItemUid, nPage, nSlot) != 0)
            {
                pSkillSlot->FUN_14175cbb0(m_nSkillId);
                pSkillSlot->FUN_14175cbf0(m_nItemUid);
                pSkillSlot->FUN_14175cc40(m_nItemId);
                if (FUN_140930d70())
                {
                    Unk_SsQuickEntry kEntry;
                    kEntry.m_nSkillId = nSkillId;
                    kEntry.m_nItemUid = nItemUid;
                    kEntry.m_nItemId = nItemId;
                    int nIdx = FUN_1422cc410();
                    FUN_1409331f0()->FUN_14142e2a0(nIdx, &kEntry);
                    Unk_SsQuickEntry kOther;
                    kOther.m_nSkillId = m_nSkillId;
                    kOther.m_nItemUid = m_nItemUid;
                    kOther.m_nItemId = m_nItemId;
                    int nOtherIdx = pSkillSlot->FUN_1422cc410();
                    FUN_1409331f0()->FUN_14142e2a0(nOtherIdx, &kOther);
                }
                FUN_14175cbb0(nSkillId);
                FUN_14175cc40(nItemId);
                FUN_14175cbf0(nItemUid);
            }
        }
        if (pFrom != 0)
            pFrom->vfunc_10();
        return vfunc_10();
    }
    if (pFrom != 0)
        pFrom->vfunc_10();
    return vfunc_10();
}

// @0x14175ddc0
int SkillSlot::vfunc_20()
{
    FUN_141276180(s_strButtonClickB, CString(""));
    FUN_14140ea40()->vfunc_3(this);
    return 1;
}

// @0x14175de40
int SkillSlot::vfunc_21()
{
    FUN_141276180(s_strButtonClickA, CString(""));
    FUN_14140ea40()->vfunc_4(this);
    return 1;
}

// @0x14175dec0
void SkillSlot::vfunc_9()
{
    AScript* pRoot = new AScript(m_value18, 2);
    m_spRoot.AssignRaw(pRoot);
    if (FUN_140ba28d0(&m_spRoot, 0) && m_spRoot->FUN_1422ba9a0())
        return;
    m_spTween = FUN_140d019b0(m_spRoot, CString("startIconTween"));
    m_spUpdate = FUN_140d019b0(m_spRoot, CString("updateData"));
    m_spClear = FUN_140d019b0(m_spRoot, CString("clearElementEffectV2"));
    m_spSet = FUN_140d019b0(m_spRoot, CString("setElementEffectV2"));
    m_spRecharge = FUN_140d019b0(m_spRoot, CString("setRechargeRemainCount"));
}

// @0x14175e310
void SkillSlot::FUN_14175e310(int nSkillId)
{
    if (nSkillId != 0)
    {
        if (FUN_141761d90() == nSkillId)
            FUN_14175f280(7);
    }
}

// @0x14175e350
void SkillSlot::FUN_14175e350(int nSkillId)
{
    int nPage = FUN_1409331f0()->FUN_140a700b0();
    int nSlot = FUN_1422cc410();
    FUN_14092f690(nSkillId, 0, 0, nPage, nSlot);
    FUN_14175cbb0(nSkillId);
    vfunc_10();
}

// @0x14175e3c0 (ITooltip::vfunc_0)
int SkillSlot::vfunc_0(void* p)
{
    MS2Ptr<CItem> spItem = vfunc_25();
    int nSkillId = FUN_141761d90();
    if (FUN_140534e50(spItem) && m_nItemId != 0)
    {
        int nRarity = FUN_14053feb0(m_nItemId);
        ASTooltip tip(static_cast<PC*>(FUN_1403ed2d0()->FUN_141bd0cc0()), 0x40, 2);
        if (tip.FUN_1409e1770(m_nItemId, nRarity) != 0)
        {
            if (FUN_14175cd90() == 0)
                tip.FUN_1409c69b0(FUN_14028de60(0x759));
            FUN_1409b4bc0(p, tip.FUN_1422bb870());
            return 1;
        }
        return 0;
    }
    if (spItem.get() != 0 && spItem->FUN_140527840()->FUN_14053e460())
    {
        if (FUN_1403ed2d0()->FUN_141bd0cc0() != 0)
        {
            ASTooltip tip(static_cast<PC*>(FUN_1403ed2d0()->FUN_141bd0cc0()), 0x40, 2);
            if (tip.FUN_1409e0d40(spItem.get()) != 0)
            {
                if (FUN_14175cd90() == 0)
                    tip.FUN_1409c69b0(FUN_14028de60(0x759));
                FUN_1409b4bc0(p, tip.FUN_1422bb870());
                return 1;
            }
        }
        return 0;
    }
    MS2Ptr<SkillData> spSkill = FUN_1401958b0()->GetSkillData(nSkillId);
    if (spSkill.get() == 0 || !spSkill->FUN_1407e9d70())
    {
        if (FUN_1417619d0() == 0)
        {
            PC* pPc = static_cast<PC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
            if (pPc != 0)
            {
                unsigned short nLevel = 1;
                MS2Ptr<SkillLevelData> spLevel = static_cast<Unk_SsPc*>(pPc)->FUN_1416546d0()->vfunc_1(nSkillId);
                if (spLevel.get() != 0)
                    nLevel = spLevel->FUN_140803df0();
                ASTooltip tip(pPc, 0x40, 2);
                if (tip.FUN_1409e1c50(nSkillId, nLevel, 0) != 0)
                {
                    if (FUN_14175cd90() == 0)
                        tip.FUN_1409c69b0(FUN_14028de60(0x759));
                    FUN_1409b4bc0(p, tip.FUN_1422bb870());
                    return 1;
                }
            }
        }
        else
        {
            ASTooltip tip(1, 2);
            int nOk = tip.FUN_1409e26b0(FUN_141761c30());
            if (nOk != 0)
            {
                tip.FUN_1409c6dc0(5);
                FUN_1409b4bc0(p, tip.FUN_1422bb870());
            }
        }
    }
    return 0;
}

// @0x14175e9e0
int SkillSlot::vfunc_8(void* p)
{
    float fTotal = FUN_141760a30();
    float fRemain = FUN_141760b90();
    PC* pPc = static_cast<PC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPc != 0 && m_nSkillId != 0)
    {
        MS2Ptr<SkillData> spSkill = FUN_1401958b0()->GetSkillData(m_nSkillId);
        if (spSkill.get() != 0 && spSkill->m_condition.m_nUseCoolDownShowUI == 0)
        {
            fTotal = 0;
            fRemain = 0.0f;
        }
    }
    ASSlot slot(2);
    MS2Ptr<CItem> spItem = vfunc_25();
    if (spItem.get() != 0)
    {
        int nUgcTag = spItem->FUN_140528840();
        if (nUgcTag != 0)
            slot.FUN_1407cb9c0(s_strUgcTag, nUgcTag);
        int nGrade = spItem->FUN_140526bd0();
        slot.FUN_1409adc90(s_strItemGrade, nGrade);
    }
    CString strIcon = FUN_141760690();
    m_strIcon = strIcon;
    m_nDisabled = FUN_141760c00();
    m_nItemCount = (int)FUN_141760220(0);
    MS2Ptr<SkillData> spReplace;
    if (FUN_141761530(&spReplace) != 0)
    {
        CString strReplaceIcon(spReplace->m_strIcon);
        if (!strReplaceIcon.IsEmpty())
            strIcon = strReplaceIcon;
    }
    if (FUN_140166410()->FUN_14036d570(0x8c) == 0)
    {
        slot.FUN_1407cb9c0(s_strItemPet, FUN_141760190());
    }
    else if (spItem.get() != 0)
    {
        if (spItem->FUN_140525640() != 0)
        {
            slot.FUN_1409adc90(s_strItemPetRank, spItem->FUN_140526bd0());
            slot.FUN_1407cb9c0(s_strDropShadowDisable, 1);
        }
    }
    slot.FUN_1407cba60(s_strIconPath, CString(strIcon));
    slot.FUN_1407cb9c0(s_strGrayColor, m_nDisabled);
    slot.FUN_1407cb9c0(s_strItemCount, m_nItemCount);
    slot.FUN_1407cb9c0(s_strItemPcBang, FUN_141760590());
    slot.FUN_1407cb9c0(s_strItemLock, FUN_14175cc60());
    slot.FUN_1407cbb20(s_strShortcutKey, CStringW(FUN_141760920()));
    slot.FUN_1407cb9c0(s_strItemVIP, FUN_141760610());
    slot.FUN_1407cbbe0(s_strDisableDrag, FUN_14028d780(FUN_141761990()));
    if (FUN_1417604f0() < 1)
    {
        m_nRecharge = 0;
    }
    else
    {
        m_nRecharge = FUN_1417603f0();
        slot.FUN_1407cb9c0(s_strRechargeRemainCount, m_nRecharge);
    }
    slot.FUN_1409c2e00(fTotal);
    slot.FUN_1409c2dc0(fRemain);
    slot.FUN_1409c2e40();
    if (fRemain <= 0.0f)
        m_bCooling = false;
    else
        m_bCooling = true;
    *static_cast<Scaleform::GFx::Value*>(p) = slot.FUN_1422bb870();
    FUN_14175cc70();
    if (FUN_140aa6d40() != 0 && 0.0f < fRemain)
        FUN_141b0e260(FUN_140aa6d40(), 0);
    FUN_14175f510();
    return 1;
}

// @0x14175f080
CStringW SkillSlot::vfunc_22()
{
    return FUN_14028de60(0x759);
}

// @0x14175f0c0
void SkillSlot::vfunc_23(void* p)
{
    int nSkillId = FUN_141761d90();
    if (FUN_141404ce0(nSkillId, p, &m_value18))
    {
        Unk_SsSkillUi* pUi = FUN_140a94350();
        float fRemain = FUN_141760b90();
        int nEffective = FUN_141761d90();
        pUi->vfunc_16(m_nIndex, nEffective, p, fRemain);
        FUN_1419f37f0(5);
    }
}

// @0x14175f180
void SkillSlot::vfunc_24(void* p)
{
    int nSkillId = FUN_141761d90();
    if (FUN_1414050c0(nSkillId, p, &m_value18))
    {
        Unk_SsSkillUi* pUi = FUN_140a94350();
        pUi->vfunc_17(m_nIndex);
        FUN_1419f37f0(5);
    }
}

// @0x14175f200
void SkillSlot::FUN_14175f200()
{
    if (FUN_14025e7c0()->FUN_14116d7a0(0xf) == 0 && m_spTween.get() != 0)
        m_spTween->FUN_1422bb3c0();
}

// @0x14175f280
void SkillSlot::FUN_14175f280(unsigned nFlags)
{
    if (FUN_140ba28d0(&m_spRoot, 0) == 0)
    {
        ASArray arr(2);
        ASObj obj(2);
        bool bChanged = false;
        int nValue;
        if ((nFlags & 1) != 0 && m_nDisabled != (nValue = FUN_141760c00()))
        {
            obj.FUN_1407cbbe0("gray", nValue == 1);
            m_nDisabled = nValue;
            bChanged = true;
        }
        if ((nFlags & 2) != 0 && m_nItemCount != (nValue = (int)FUN_141760220(0)))
        {
            obj.FUN_1407cb9c0("itemCount", nValue);
            m_nItemCount = nValue;
            bChanged = true;
        }
        if ((nFlags & 4) != 0 && m_nRecharge != (nValue = FUN_1417603f0()))
        {
            obj.FUN_1407cb9c0("rechargeRemainCount", nValue);
            m_nRecharge = nValue;
            bChanged = true;
        }
        if (bChanged && m_spUpdate.get() != 0)
            FUN_1417620b0(m_spUpdate.operator->(), obj.FUN_1422bb870());
        if ((nFlags & 8) != 0)
            FUN_14175f510();
    }
}

// @0x14175f510
void SkillSlot::FUN_14175f510()
{
    if (FUN_140ba28d0(&m_spRoot, 0) == 0)
    {
        int nDisabled = FUN_141760c00();
        bool bChanged = m_nDisabled != nDisabled;
        if (bChanged)
            m_nDisabled = nDisabled;
        int nSkillId = m_nSkillId;
        unsigned __int64 nKey = (unsigned)m_nSkillId;
        MS2Ptr<SkillData> spReplace(0);
        CString strIcon(m_strIcon);
        if (FUN_141761530(&spReplace) == 0)
        {
            strIcon = FUN_1417607f0(&m_nSkillId);
            bool bIconChanged = FUN_1401647e0(m_strIcon, strIcon);
            if (bIconChanged)
                m_strIcon = strIcon;
            bChanged = bIconChanged || bChanged;
            if (bChanged || !m_bUsable)
            {
                if (m_spClear.get() != 0)
                    FUN_141761fc0(m_spClear.operator->(), CString(strIcon), nDisabled, 1);
                m_bUsable = true;
            }
            if (m_nSkillId != 0)
            {
                MS2Ptr<SkillData> spSkill = FUN_1401958b0()->GetSkillData(m_nSkillId);
                if (spSkill.get() != 0)
                    nKey = spSkill->GetCooldownKey();
            }
        }
        else
        {
            nSkillId = spReplace->GetId();
            bChanged = true;
            strIcon = FUN_1417607f0(&nSkillId);
            if (!spReplace->m_bDisableChangeSkillIconEffect)
            {
                if (m_spSet.get() != 0)
                    FUN_141761eb0(m_spSet.operator->(), spReplace->GetElement(), CString(strIcon), nDisabled, 1);
                m_bUsable = false;
                nKey = spReplace->GetCooldownKey();
            }
            else
            {
                if (m_spClear.get() != 0)
                    FUN_141761fc0(m_spClear.operator->(), CString(strIcon), nDisabled, 1);
                m_bUsable = true;
                MS2Ptr<SkillData> spSkill = FUN_1401958b0()->GetSkillData(m_nSkillId);
                if (spSkill.get() != 0)
                    nKey = spSkill->GetCooldownKey();
            }
        }
        if (!FUN_141404ce0(nSkillId, nKey, &m_value18))
        {
            if (bChanged || m_bCooling == true)
                FUN_1414050c0(nSkillId, nKey, &m_value18);
            m_bCooling = false;
        }
        else
        {
            m_bCooling = true;
        }
        int nRecharge = FUN_1417603f0();
        if (nRecharge != m_nRecharge)
        {
            if (m_spRecharge.get() != 0)
            {
                int nMax = FUN_1417604f0();
                FUN_141762190(m_spRecharge.operator->(), 0 < nMax, nRecharge);
            }
            m_nRecharge = nRecharge;
        }
    }
}

// @0x14175fbf0 (slot 25)
MS2Ptr<CItem> SkillSlot::vfunc_25()
{
    MS2Ptr<CItem> spItem(0);
    int nSkillId = FUN_141761d90();
    if (m_nItemId == 0)
    {
        if (nSkillId != 0)
        {
            if (DAT_143ae9750 == false)
                spItem = DAT_143ab2a90.FUN_140a5d760(nSkillId, 0);
            else
                spItem = 0;
            if (spItem.get() != 0)
            {
                CItem* pItem = spItem.operator->();
                if (pItem->FUN_140525f10() != 0 || pItem->FUN_140526010() != 0)
                    spItem = DAT_143ab2a90.FUN_140a5d680(m_nItemUid);
            }
        }
    }
    else
    {
        if (m_nItemUid != 0)
            spItem = DAT_143ab2a90.FUN_140a5d680(m_nItemUid);
        if (FUN_140534e50(spItem))
            spItem = DAT_143ab2a90.FUN_140a5e2e0(m_nItemId);
    }
    return spItem;
}

// @0x14175fe60
CStringW SkillSlot::FUN_14175fe60()
{
    CStringW str(L"");
    MS2Ptr<CItem> spItem = vfunc_25();
    if (!FUN_140534e50(spItem) || m_nItemId == 0)
    {
        if (spItem.get() != 0 && spItem->FUN_140527840()->FUN_14053e460())
        {
            str = FUN_1401a9d70()->FUN_141811980(1, m_nItemId);
        }
        else
        {
            str = FUN_1401a9d70()->FUN_141811980(4, m_nSkillId);
        }
    }
    else
    {
        str = FUN_1401a9d70()->FUN_141811980(1, m_nItemId);
    }
    if (str.IsEmpty())
    {
        if (spItem.get() == 0)
            str = CStringW(L"");
        else
            str = spItem->FUN_140527b10();
    }
    return str;
}

// @0x141760190
bool SkillSlot::FUN_141760190()
{
    Unk_SsItemPtr spData = FUN_14053f870(m_nItemId);
    if (spData.FUN_1402ffd90())
        return false;
    return spData.FUN_1401b52a0()->FUN_14053cc40();
}

// @0x141760220
unsigned SkillSlot::FUN_141760220(int n)
{
    bool bFlag = false;
    if (m_nSkillId != 0)
    {
        MS2Ptr<SkillData> spSkill = FUN_1401958b0()->GetSkillData(m_nSkillId);
        if (spSkill.get() != 0)
            bFlag = spSkill->FUN_1407e9ea0();
    }
    if (m_nItemId == 0 && m_nSkillId != 0 && !bFlag)
    {
        if (DAT_143ae9750 == false)
            return DAT_143ab2a90.FUN_140a5fbd0(m_nSkillId, n);
        return 0;
    }
    Unk_SsItemPtr spData = FUN_14053f870(m_nItemId);
    if (spData.FUN_1402ffd90())
        return 0;
    if (!spData.FUN_1401b52a0()->FUN_14053c7c0())
        return 0;
    if (!spData.FUN_1401b52a0()->FUN_14053d270() || bFlag)
        return DAT_143ab2a90.FUN_140a5f180(m_nItemId, 0);
    return DAT_143ab2a90.FUN_140a5fbd0(m_nSkillId, n);
}

// @0x1417603f0
int SkillSlot::FUN_1417603f0()
{
    int nSkillId = FUN_141761d90();
    if (nSkillId != 0)
    {
        MS2Ptr<SkillData> spSkill = FUN_1401958b0()->GetSkillData(nSkillId);
        if (spSkill.get() != 0 && spSkill->GetRechargeMaxCount() != 0)
        {
            PC* pPc = static_cast<PC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
            if (pPc != 0)
                return static_cast<MyPC*>(pPc)->FUN_141523bc0()->FUN_141768770(spSkill.get());
            return 0;
        }
    }
    return 0;
}

// @0x1417604f0
int SkillSlot::FUN_1417604f0()
{
    int nSkillId = FUN_141761d90();
    if (nSkillId == 0)
        return 0;
    MS2Ptr<SkillData> spSkill = FUN_1401958b0()->GetSkillData(nSkillId);
    if (spSkill.get() == 0)
        return 0;
    return spSkill->GetRechargeMaxCount();
}

// @0x141760590
int SkillSlot::FUN_141760590()
{
    MS2Ptr<CItem> spItem = vfunc_25();
    if (spItem.get() == 0)
        return 0;
    return spItem->FUN_140525ca0();
}

// @0x141760610
int SkillSlot::FUN_141760610()
{
    MS2Ptr<CItem> spItem = vfunc_25();
    if (spItem.get() == 0)
        return 0;
    return spItem->FUN_140525db0();
}

// @0x141760690
CString SkillSlot::FUN_141760690()
{
    MS2Ptr<CItem> spItem = vfunc_25();
    if (spItem.get() == 0)
    {
        if (m_nItemId == 0)
        {
            int nSkillId = 0;
            return FUN_1417607f0(&nSkillId);
        }
        Unk_SsItemPtr spData = FUN_14053f870(m_nItemId);
        if (spData.FUN_1402ffd90())
            return CString("");
        return spData.FUN_1401b52a0()->FUN_14053fdd0();
    }
    return spItem->FUN_140528590();
}

// @0x1417607f0
CString SkillSlot::FUN_1417607f0(int* pSkillId)
{
    CString strIcon;
    int nSkillId = *pSkillId;
    if (*pSkillId == 0)
        nSkillId = FUN_141761d90();
    MS2Ptr<SkillData> spSkill(0);
    if (nSkillId != 0)
        spSkill = FUN_1401958b0()->GetSkillData(nSkillId);
    if (spSkill.get() != 0)
        strIcon = spSkill->m_strIcon;
    return strIcon;
}

// @0x141760920
CStringW SkillSlot::FUN_141760920()
{
    int nKey = FUN_141760980(0);
    return FUN_1409331f0()->FUN_14142d220(nKey);
}

// @0x141760980
int SkillSlot::FUN_141760980(int nMode)
{
    int nAction = 0;
    if (m_kKeys.Lookup(m_nIndex, nAction))
        return FUN_1409331f0()->FUN_14142c940((__int64)nAction, nMode);
    return FUN_1409331f0()->FUN_14142cb40(m_nIndex, nMode);
}

// @0x141760a10
__int64 SkillSlot::FUN_141760a10()
{
    return (__int64)(m_nIndex + 0x7a121);
}

// @0x141760a30
float SkillSlot::FUN_141760a30()
{
    PC* pPc = static_cast<PC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPc == 0)
        return 0;
    int nSkillId = FUN_141761d90();
    if (nSkillId == 0)
        return 0;
    MS2Ptr<SkillLevelData> spLevel = static_cast<Unk_SsPc*>(pPc)->FUN_1416546d0()->vfunc_1(nSkillId);
    if (spLevel.IsNull())
        return 0;
    float fRemain = 0;
    float fTotal = 0;
    int nByItem = 0;
    static_cast<MyPC*>(pPc)->FUN_141523bc0()->FUN_141766230(nSkillId, &fRemain, &fTotal, &nByItem, 1);
    if (nByItem == 0)
        return spLevel->FUN_140804660();
    return fTotal;
}

// @0x141760b90
float SkillSlot::FUN_141760b90()
{
    PC* pPc = static_cast<PC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPc == 0)
        return 0;
    int nSkillId = FUN_141761d90();
    if (nSkillId == 0)
        return 0;
    return static_cast<MyPC*>(pPc)->FUN_141523bc0()->FUN_141765fe0(nSkillId, 1);
}

// @0x141760c00
int SkillSlot::FUN_141760c00()
{
    PC* pPc = static_cast<PC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPc == 0)
        return 1;
    if (m_nItemId == 0)
    {
        int nSkillId = FUN_141761d90();
        if (nSkillId == 0)
            return 1;
        MS2Ptr<SkillData> spSkill = FUN_1401958b0()->GetSkillData(nSkillId);
        if (spSkill.IsNull())
            return 1;
        MS2Ptr<SkillLevelData> spLevel = static_cast<Unk_SsPc*>(pPc)->FUN_1416546d0()->vfunc_1(nSkillId);
        if (spLevel.IsNull())
            return 1;
        float fRemain = FUN_141760b90();
        if (0.0f < fRemain && spSkill->m_condition.m_nUseCoolDownShowUI != 0)
        {
            if (static_cast<MyPC*>(pPc)->FUN_141523bc0()->FUN_141768770(spSkill.get()) == 0)
                return 1;
        }
        int nKey = FUN_141760980(0);
        if (nKey == 0)
        {
            if (static_cast<MyPC*>(pPc)->FUN_141523bc0()->FUN_141768380().IsNull())
            {
                if (spLevel->FUN_140804450())
                    return 1;
            }
        }
        if (!spSkill->FUN_1407e9d70())
        {
            if (!static_cast<Unk_SsPc*>(pPc)->FUN_1416546d0()->vfunc_2(m_nSkillId))
                return 1;
            CSkillSystem* pSys = static_cast<MyPC*>(pPc)->FUN_141523bc0();
            int nOld18 = pSys->FUN_141765cf0(0);
            int nOld88 = pSys->FUN_141765d30(1);
            unsigned char bOk = pSys->FUN_141765a70(nSkillId);
            pSys->FUN_141765cf0(nOld18);
            pSys->FUN_141765d30(nOld88);
            return bOk == 0;
        }
        MS2Ptr<CItem> spItem = vfunc_25();
        if (spItem.get() == 0)
        {
            if (FUN_141760220(0) < 1)
                return 1;
        }
        else
        {
            Unk_ItemEquipData* pData = spItem->FUN_140527840();
            if (!pData->FUN_14053cc80())
            {
                if (pData->FUN_14053cc40())
                {
                    bool bNoField = FUN_1403ed2d0()->FUN_141bd30a0()->m_nField == 0;
                    if (bNoField)
                        return 1;
                    if (FUN_141760220(1) < 1)
                        return 1;
                }
            }
            else
            {
                if (!FUN_1403ed2d0()->FUN_141bcb210())
                    return 1;
                if (FUN_141760220(1) < 1)
                    return 1;
            }
        }
        unsigned nMask = reinterpret_cast<Unk_SsBuffs*>(pPc->FUN_1416749a0())->FUN_140970bf0();
        if (nMask != 0)
        {
            int nMainType = spSkill->GetMainType();
            if ((nMask & (1 << ((unsigned char)nMainType & 0x1f))) != 0)
                return 1;
        }
        if (reinterpret_cast<Unk_SsBuffs*>(pPc->FUN_1416749a0())->FUN_140970a60(nSkillId) == 0)
            return 0;
        return 1;
    }
    MS2Ptr<CItem> spItem = vfunc_25();
    if (FUN_140534e50(spItem))
    {
        Unk_SsItemPtr spData = FUN_14053f870(m_nItemId);
        if (!spData.FUN_1402ffd90() && spData.FUN_1401b52a0()->FUN_14053c6f0() == 0xd9)
            return 0;
        return 1;
    }
    if (pPc->FUN_141662eb0(spItem.get()) == 0)
        return 1;
    unsigned short nLevel = (unsigned short)pPc->vfunc_78();
    if (FUN_140526810(spItem.operator->(), nLevel) == 0)
        return 1;
    if (!spItem->FUN_140527840()->FUN_14053e460())
        return 1;
    return 0;
}

// @0x141761530
int SkillSlot::FUN_141761530(MS2Ptr<SkillData>* pOut)
{
    Unk_SsPc* pPc = static_cast<Unk_SsPc*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPc == 0)
        return 0;
    if (m_nSkillId == 0)
        return 0;
    MS2Ptr<SkillLevelData> spLevel(0);
    if (pPc->FUN_1416764d0() == 0)
        spLevel = pPc->FUN_1416546d0()->vfunc_1(m_nSkillId);
    else
        spLevel = FUN_1401958b0()->GetSkillLevelData(m_nSkillId, 1);
    if (spLevel.IsNull())
        return 0;
    SkillData* pData = spLevel->FUN_140803e10();
    int nReplace = 0;
    ATL::CAtlArray<unsigned>& arrEffect = pData->m_blockB0.m_arrCheckEffectID;
    ATL::CAtlArray<unsigned short>& arrLevel = pData->m_blockB0.m_arrCheckEffectLevel;
    ATL::CAtlArray<unsigned>& arrOverlap = pData->m_blockB0.m_arrCheckEffectOverlapCount;
    for (unsigned i = 0; i < arrEffect.GetCount(); ++i)
    {
        unsigned nOverlap = arrOverlap[i];
        unsigned short nLevel = arrLevel[i];
        unsigned nEffect = arrEffect[i];
        if (reinterpret_cast<Unk_SsBuffs*>(pPc->FUN_1416749a0())->FUN_140970020(nEffect, nLevel, nOverlap, 1) != 0)
        {
            nReplace = pData->m_blockB0.m_arrChangeSkillID[i];
            spLevel->FUN_140803df0();
            break;
        }
    }
    if (nReplace == 0)
        return 0;
    if (nReplace == m_nSkillId)
        return 0;
    pPc->FUN_1416546d0();
    *pOut = FUN_140639210(nReplace);
    if (pOut->IsNull())
        return 0;
    return 1;
}

// @0x141761900
bool SkillSlot::FUN_141761900()
{
    Unk_SsItemPtr spData = FUN_14053f870(m_nItemId);
    if (spData.FUN_1402ffd90())
        return false;
    return spData.FUN_1401b52a0()->FUN_14053cd90();
}

// @0x141761990
int SkillSlot::FUN_141761990()
{
    if (FUN_14175cd90() == 0)
        return FUN_1417619d0();
    return 1;
}

// @0x1417619d0
int SkillSlot::FUN_1417619d0()
{
    return m_kKeys.Lookup(m_nIndex) != 0;
}

// @0x141761a10
int SkillSlot::FUN_141761a10()
{
    PC* pPc = static_cast<PC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPc == 0)
        return 0;
    MS2Ptr<Unk_MyPCSkillSet> spSet = static_cast<MyPC*>(pPc)->FUN_141523bc0()->FUN_141768380();
    if (spSet.IsNull())
        return 0;
    std::vector<unsigned>& vItems = spSet->m_vItems;
    if (std::find(vItems.begin(), vItems.end(), (unsigned)m_nItemId) != vItems.end())
        return 1;
    std::vector<unsigned>& vSkills = spSet->m_vSkills;
    if (std::find(vSkills.begin(), vSkills.end(), (unsigned)m_nSkillId) != vSkills.end())
        return 1;
    return 0;
}

// @0x141761c30
CStringW SkillSlot::FUN_141761c30()
{
    int nAction = 0;
    if (m_kKeys.Lookup(m_nIndex, nAction))
    {
        if (nAction == 0x493e3)
            return FUN_14028b8e0(CStringW(L"s_quick_slot_item_get"));
        if (nAction == 0x49401)
            return FUN_14028b8e0(CStringW(L"s_quick_slot_attack"));
        if (nAction == 0x493e1)
            return FUN_14028b8e0(CStringW(L"s_quick_slot_jump"));
    }
    return CStringW(L"");
}

// @0x141761d90
int SkillSlot::FUN_141761d90()
{
    MS2Ptr<SkillData> spReplace;
    if (FUN_141761530(&spReplace) == 0)
        return m_nSkillId;
    return spReplace->GetId();
}

// @0x141761e10
BookSlot* FUN_141761e10(DragSlot* p)
{
    BookSlot* pSlot = 0;
    if (p == 0 || !p->TypeCast(0x6200051, (void**)&pSlot))
        pSlot = 0;
    return pSlot;
}

// @0x141761e60
SkillSlot* FUN_141761e60(DragSlot* p)
{
    SkillSlot* pSlot = 0;
    if (p == 0 || !p->TypeCast(0x6200025, (void**)&pSlot))
        pSlot = 0;
    return pSlot;
}

// @0x141761eb0
Scaleform::GFx::Value FUN_141761eb0(AScript* pFn, unsigned nElement, CString strIcon, int nGray, int nFlag)
{
    ASArgList args;
    args.FUN_1409b2800(4);
    FUN_1422bcd10(args.FUN_1409b1f70(0), nElement);
    FUN_1422bce70(args.FUN_1409b1f70(1), (const char*)strIcon);
    FUN_1422bccb0(args.FUN_1409b1f70(2), nGray);
    FUN_1422bccb0(args.FUN_1409b1f70(3), nFlag);
    return static_cast<Unk_SsFn*>(pFn)->FUN_1422bb9f0(args);
}

// @0x141761fc0
Scaleform::GFx::Value FUN_141761fc0(AScript* pFn, CString strIcon, int nGray, int nFlag)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bce70(args.FUN_1409b1f70(0), (const char*)strIcon);
    FUN_1422bccb0(args.FUN_1409b1f70(1), nGray);
    FUN_1422bccb0(args.FUN_1409b1f70(2), nFlag);
    return static_cast<Unk_SsFn*>(pFn)->FUN_1422bb9f0(args);
}

// @0x1417620b0
Scaleform::GFx::Value FUN_1417620b0(AScript* pFn, Scaleform::GFx::Value kArg)
{
    ASArgList args;
    args.FUN_1409b2800(1);
    FUN_1422bcc70(args.FUN_1409b1f70(0), Scaleform::GFx::Value(kArg));
    return static_cast<Unk_SsFn*>(pFn)->FUN_1422bb9f0(args);
}

// @0x141762190
Scaleform::GFx::Value FUN_141762190(AScript* pFn, bool bShow, int nCount)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bcce0(args.FUN_1409b1f70(0), bShow);
    FUN_1422bccb0(args.FUN_1409b1f70(1), nCount);
    return static_cast<Unk_SsFn*>(pFn)->FUN_1422bb9f0(args);
}

// @0x1417633f0
void FUN_1417633f0(const CString& strName, int nCount)
{
    SkillSlotBag* pBag = new (efd::MemHint(efd::MemHint::NONE)) SkillSlotBag(strName);
    if (pBag)
    {
        static_cast<DragSlotBag*>(pBag)->vfunc_10(nCount);
        FUN_1422c8f10(strName, pBag);
    }
}

// @0x1417634a0
void FUN_1417634a0(const CString& strName)
{
    SkillSlotBag* pBag = FUN_141763cb0(FUN_1422c8e90(strName));
    if (pBag)
    {
        FUN_1422cc9e0(pBag);
        FUN_1422c8f70(strName);
    }
}

// @0x1417634f0
SkillSlotBag::SkillSlotBag(const CString& strName)
    : DragSlotBag(strName)
{
    FUN_140bc09f0()->FUN_141b38be0(static_cast<UIUGCEventListener*>(this));
}

// @0x1417635a0
SkillSlotBag::~SkillSlotBag()
{
    FUN_140bc09f0()->FUN_141b38c70(static_cast<UIUGCEventListener*>(this));
}

// @0x141763640
void SkillSlotBag::FUN_141763640(int nFlags)
{
    for (std::map<int, CString>::iterator it = m_slots.begin(); it != m_slots.end(); ++it)
    {
        std::pair<const int, CString> entry = *it;
        SkillSlot* pSlot = FUN_141761e60(FUN_1422cd0f0(this, entry.second));
        if (pSlot != 0)
            pSlot->FUN_14175f280(nFlags);
    }
}

// @0x141763710
SkillSlot* SkillSlotBag::FUN_141763710(int nItemId)
{
    for (std::map<int, CString>::iterator it = m_slots.begin(); it != m_slots.end(); ++it)
    {
        std::pair<const int, CString> entry = *it;
        SkillSlot* pSlot = FUN_141761e60(FUN_1422cd0f0(this, entry.second));
        if (pSlot != 0 && pSlot->FUN_14175cc20() == nItemId)
            return pSlot;
    }
    return 0;
}

// @0x141763800
SkillSlot* SkillSlotBag::FUN_141763800(__int64 nItemUid)
{
    for (std::map<int, CString>::iterator it = m_slots.begin(); it != m_slots.end(); ++it)
    {
        std::pair<const int, CString> entry = *it;
        SkillSlot* pSlot = FUN_141761e60(FUN_1422cd0f0(this, entry.second));
        if (pSlot != 0 && pSlot->FUN_14175cbd0() == nItemUid)
            return pSlot;
    }
    return 0;
}

// @0x1417638f0 (UIUGCEventListener::vfunc_ugc_2)
void SkillSlotBag::vfunc_ugc_2(void* pUid, CString str)
{
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680((__int64)pUid);
    if (spItem == 0)
    {
        SkillSlot* pSlot = FUN_141763800((__int64)pUid);
        if (pSlot != 0)
            pSlot->vfunc_10();
    }
}

// @0x1417639b0
DragSlot* SkillSlotBag::vfunc_16(int nIndex)
{
    Unk_SsQuickEntry kEntry;
    FUN_1409331f0()->FUN_14142e030(nIndex, &kEntry);
    return new (efd::MemHint(efd::MemHint::NONE)) SkillSlot(vfunc_15(nIndex), nIndex, kEntry.m_nSkillId, kEntry.m_nItemId, kEntry.m_nItemUid);
}

// @0x141763b00
void SkillSlotBag::FUN_141763b00(int nFlags)
{
    for (std::map<int, CString>::iterator it = m_slots.begin(); it != m_slots.end(); ++it)
    {
        std::pair<const int, CString> entry = *it;
        SkillSlot* pSlot = FUN_141761e60(FUN_1422cd0f0(this, entry.second));
        if (pSlot != 0)
            pSlot->FUN_14175e310(nFlags);
    }
}

// @0x141763bd0
void SkillSlotBag::FUN_141763bd0(int nSkillId, int nFlags)
{
    for (std::map<int, CString>::iterator it = m_slots.begin(); it != m_slots.end(); ++it)
    {
        std::pair<const int, CString> entry = *it;
        SkillSlot* pSlot = FUN_141761e60(FUN_1422cd0f0(this, entry.second));
        if (pSlot != 0)
        {
            if (pSlot->FUN_14175cb90() == nSkillId)
                pSlot->FUN_14175e350(nFlags);
        }
    }
}

// @0x141763cb0
SkillSlotBag* FUN_141763cb0(NotifyContext::BindData* p)
{
    SkillSlotBag* pBag = 0;
    if (p == 0 || !p->TypeCast(0x620002a, (void**)&pBag))
        pBag = 0;
    return pBag;
}
