// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). SkillSlot and SkillSlotBag (the quick slot / skill window
// slots) and the CSkillSystem of the local player (cooldown table, skill sets, skill cast requests).
// MS2-UNIT: ?\skillslot.cpp
// MS2-RANGE: 0x14175c840-0x14176f2a0 .text$mn
// MS2-RANGE: 0x140100bf0-0x140101560 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__E?ms_ClassInfo@SkillSlot@@2VClassInfo@efd@@B@@YAXXZ 0x140100bf0 ; prop
// MS2-PIN: ??__Es_strButtonClickA@@YAXXZ 0x140100c10 ; probe
// MS2-PIN: ??__Es_strButtonClickB@@YAXXZ 0x140100c40 ; probe
// MS2-PIN: ??__Es_strDisableDrag@@YAXXZ 0x140100c70 ; probe
// MS2-PIN: ??__Es_strDropShadowDisable@@YAXXZ 0x140100ca0 ; probe
// MS2-PIN: ??__Es_strGrayColor@@YAXXZ 0x140100cd0 ; probe
// MS2-PIN: ??__Es_strIconPath@@YAXXZ 0x140100d00 ; probe
// MS2-PIN: ??__Es_strItemCount@@YAXXZ 0x140100d30 ; probe
// MS2-PIN: ??__Es_strItemGrade@@YAXXZ 0x140100d60 ; probe
// MS2-PIN: ??__Es_strItemLock@@YAXXZ 0x140100d90 ; probe
// MS2-PIN: ??__Es_strItemPcBang@@YAXXZ 0x140100dc0 ; probe
// MS2-PIN: ??__Es_strItemPet@@YAXXZ 0x140100df0 ; probe
// MS2-PIN: ??__Es_strItemPetRank@@YAXXZ 0x140100e20 ; probe
// MS2-PIN: ??__Es_strItemVIP@@YAXXZ 0x140100e50 ; probe
// MS2-PIN: ??__Es_strNoticeErrorEp@@YAXXZ 0x140100e80 ; probe
// MS2-PIN: ??__Es_strSortTypeNames2@@YAXXZ 0x140100eb0 ; probe
// MS2-PIN: ??__Es_strNoticeErrorNotThisPlace@@YAXXZ 0x140100f70 ; probe
// MS2-PIN: ??__Es_strNoticeErrorNotThisTime@@YAXXZ 0x140100fa0 ; probe
// MS2-PIN: ??__Es_unk1402a9d70@@YAXXZ 0x140100fd0 ; probe
// MS2-PIN: ??__Es_strNoticeErrorSp@@YAXXZ 0x140101020 ; probe
// MS2-PIN: ??__Es_strNoticeErrorWarningWeapon@@YAXXZ 0x140101050 ; probe
// MS2-PIN: ??__Es_strSortTypeNames3@@YAXXZ 0x1401010a0 ; probe
// MS2-PIN: ??__Es_strNoticeFailSkillIncorrectWeapon@@YAXXZ 0x140101160 ; probe
// MS2-PIN: ??__Es_strRechargeRemainCount@@YAXXZ 0x140101190 ; probe
// MS2-PIN: ??__Es_unk1402a9d70_2@@YAXXZ 0x1401011c0 ; probe
// MS2-PIN: ??__Es_strSortTypeNames4@@YAXXZ 0x140101210 ; probe
// MS2-PIN: ??__Es_strShortcutKey@@YAXXZ 0x1401012d0 ; probe
// MS2-PIN: ??__Es_strSkill2@@YAXXZ 0x140101300 ; probe
// MS2-PIN: ??__Es_unk1402a9d70_3@@YAXXZ 0x140101330 ; probe
// MS2-PIN: ??__Es_strSkill3@@YAXXZ 0x140101380 ; probe
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x1401013b0 ; probe
// MS2-PIN: ??__Es_strStun2@@YAXXZ 0x1401013e0 ; probe
// MS2-PIN: ??__Es_strStun3@@YAXXZ 0x140101410 ; probe
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x140101440 ; probe
// MS2-PIN: ??__Es_strUgcTag@@YAXXZ 0x140101470 ; probe
// MS2-PIN: ??__Es_strSortTypeNames@@YAXXZ 0x1401014a0 ; probe
// MS2-PIN: ??8?$MS2Ptr@VUnk_MyPCSkillSet@@@@QEBA_NPEAVUnk_MyPCSkillSet@@@Z 0x1417624d0 ; unique
// MS2-PIN: ?GetClassDesc@SkillSlot@@UEBAPEBVClassInfo@efd@@XZ 0x141762740 ; unique
// MS2-PIN: ?TypeCast@SkillSlot@@UEBA_NIPEAPEAX@Z 0x141763350 ; unique
// MS2-PIN: ?TypeCast@SkillSlot@@UEBA_NIPEAPEBX@Z 0x1417633a0 ; unique
// MS2-PIN: ??_ESkillSlotBag@@WII@EAAPEAXI@Z 0x141763cfc ; unique
// MS2-PIN: ??_GSkillSlotBag@@UEAAPEAXI@Z 0x141763d10 ; unique
// MS2-PIN: ?GetClassDesc@SkillSlotBag@@UEBAPEBVClassInfo@efd@@XZ 0x141763d70 ; unique
// MS2-PIN: ?TypeCast@SkillSlotBag@@UEBA_NIPEAPEAX@Z 0x141763de0 ; unique
// MS2-PIN: ?TypeCast@SkillSlotBag@@UEBA_NIPEAPEBX@Z 0x141763e30 ; unique
// MS2-PIN: memmove_s 0x141763e80 ; unique
// MS2-PIN: ??$Unk_SocketFormat@HH@@YA?AV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEBDAEBH1@Z 0x14176bb90 ; unique
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@AEBV?$MS2Ptr@VstEmotion@CSkillSystem@@@@@?$vector@V?$MS2Ptr@VstEmotion@CSkillSystem@@@@V?$allocator@V?$MS2Ptr@VstEmotion@CSkillSystem@@@@@std@@@std@@AEAAXAEBV?$MS2Ptr@VstEmotion@CSkillSystem@@@@@Z 0x14176c010 ; unique
// MS2-PIN: ??$_Emplace_reallocate@AEBV?$MS2Ptr@VstEmotion@CSkillSystem@@@@@?$vector@V?$MS2Ptr@VstEmotion@CSkillSystem@@@@V?$allocator@V?$MS2Ptr@VstEmotion@CSkillSystem@@@@@std@@@std@@QEAAPEAV?$MS2Ptr@VstEmotion@CSkillSystem@@@@QEAV2@AEBV2@@Z 0x14176c0d0 ; unique
// MS2-PIN: ??$construct@V?$MS2Ptr@VstEmotion@CSkillSystem@@@@AEAV1@@?$_Default_allocator_traits@V?$allocator@V?$MS2Ptr@VstEmotion@CSkillSystem@@@@@std@@@std@@SAXAEAV?$allocator@V?$MS2Ptr@VstEmotion@CSkillSystem@@@@@1@QEAV?$MS2Ptr@VstEmotion@CSkillSystem@@@@AEAV3@@Z 0x14176c6f0 ; unique
// MS2-PIN: ??$construct@V?$MS2Ptr@VstEmotion@CSkillSystem@@@@AEBV1@@?$_Default_allocator_traits@V?$allocator@V?$MS2Ptr@VstEmotion@CSkillSystem@@@@@std@@@std@@SAXAEAV?$allocator@V?$MS2Ptr@VstEmotion@CSkillSystem@@@@@1@QEAV?$MS2Ptr@VstEmotion@CSkillSystem@@@@AEBV3@@Z 0x14176c740 ; prop
// MS2-PIN: ??$construct@V?$MS2Ptr@VstEmotion@CSkillSystem@@@@V1@@?$_Default_allocator_traits@V?$allocator@V?$MS2Ptr@VstEmotion@CSkillSystem@@@@@std@@@std@@SAXAEAV?$allocator@V?$MS2Ptr@VstEmotion@CSkillSystem@@@@@1@QEAV?$MS2Ptr@VstEmotion@CSkillSystem@@@@$$QEAV3@@Z 0x14176c790 ; unique
// MS2-PIN: ??$emplace_back@AEBV?$MS2Ptr@VstEmotion@CSkillSystem@@@@@?$vector@V?$MS2Ptr@VstEmotion@CSkillSystem@@@@V?$allocator@V?$MS2Ptr@VstEmotion@CSkillSystem@@@@@std@@@std@@QEAAXAEBV?$MS2Ptr@VstEmotion@CSkillSystem@@@@@Z 0x14176c800 ; unique
// MS2-PIN: ??0?$MS2Ptr@VCSkillRecord@@@@QEAA@$$T@Z 0x14176ca00 ; unique
// MS2-PIN: ??0?$MS2Ptr@VSkillLevelData@@@@QEAA@$$T@Z 0x14176ca60 ; unique
// MS2-PIN: ??0?$MS2Ptr@VstEmotion@CSkillSystem@@@@QEAA@$$T@Z 0x14176ca80 ; prop
// MS2-PIN: ??8?$MS2Ptr@VCSkillCompactControlConfig@@@@QEBA_NPEAVCSkillCompactControlConfig@@@Z 0x14176ce10 ; unique
// MS2-PIN: ??8?$MS2Ptr@VstEmotion@CSkillSystem@@@@QEBA_NPEAVstEmotion@CSkillSystem@@@Z 0x14176ce90 ; order
// MS2-PIN: ??C?$MS2Ptr@VSkillData@@@@QEBAPEAVSkillData@@XZ 0x14176cf50 ; unique
// MS2-PIN: ?_Change_array@?$vector@V?$MS2Ptr@VstEmotion@CSkillSystem@@@@V?$allocator@V?$MS2Ptr@VstEmotion@CSkillSystem@@@@@std@@@std@@AEAAXQEAV?$MS2Ptr@VstEmotion@CSkillSystem@@@@_K1@Z 0x14176ea70 ; unique
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VstEmotion@CSkillSystem@@@@V?$allocator@V?$MS2Ptr@VstEmotion@CSkillSystem@@@@@std@@@std@@@std@@QEAAAEAPEAV?$MS2Ptr@VstEmotion@CSkillSystem@@@@XZ 0x14176ecd0 ; unique
// MS2-PIN: ?_Tidy@?$vector@V?$MS2Ptr@VstEmotion@CSkillSystem@@@@V?$allocator@V?$MS2Ptr@VstEmotion@CSkillSystem@@@@@std@@@std@@AEAAXXZ 0x14176ee70 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ?_Unchecked_begin@?$vector@V?$MS2Ptr@VstEmotion@CSkillSystem@@@@V?$allocator@V?$MS2Ptr@VstEmotion@CSkillSystem@@@@@std@@@std@@QEAAPEAV?$MS2Ptr@VstEmotion@CSkillSystem@@@@XZ 0x14176f020 ; hand
// MS2-PIN: ?_Unchecked_end@?$vector@V?$MS2Ptr@VstEmotion@CSkillSystem@@@@V?$allocator@V?$MS2Ptr@VstEmotion@CSkillSystem@@@@@std@@@std@@QEAAPEAV?$MS2Ptr@VstEmotion@CSkillSystem@@@@XZ 0x14176f040 ; hand
// MS2-PIN: ??_7SkillSlot@@6BBindData@NotifyContext@@@ 0x142f61f60 ; hand: primary vftable
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
#include "ms2/client/ms2/skillrecord.h"
#include "ms2/commonfiles/skillconfig.h"
#include "ms2/placeholder/cmainsystem.h"
#include "ms2/placeholder/cspecialeffectctx.h"
#include "hook/ms2hook.h"
#include "ms2/ms2format.h"
#include "ms2/commonfiles/fielddata.h"
#include "ms2/client/ms2/ridee.h"
#include "ms2/commonfiles/skillactionadditional.h"
#include <efd/MemHint.h>
#include <efd/MemObject.h>

// ---- out-of-unit callees ----
class Unk_ItemEquipData : public CItemData { };          // CItem::FUN_140527840's record

extern Unk_Inventory DAT_143ab2a90;                       // the player's inventory
extern bool DAT_143ae9750;                                // the debug switch "SkillSlotNotFind"

// Unk_SsQuickEntry (the quick slot entry of a slot index, the saved shortcut): placeholder/ssquickentry.h.
#include "ms2/placeholder/ssquickentry.h"

// The quick slot manager (0x1409331f0): the saved entries, the key bindings and the page.
class Unk_MyPCSkillSet;
class Unk_PCBaseComp_b18;
class Unk_SsHeldWeapon;
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
    __int64 FUN_14142ded0(int nSlot);                     // the item uid of a slot
    int FUN_14142e6f0(int nKey);                          // the key is not a quick slot key
    int FUN_14142dfb0(int nSlot);
    void FUN_14142f8b0(CString strName);                  // drop the skill set layout
    void FUN_14142e8c0(MS2Ptr<Unk_MyPCSkillSet> spSet);   // save the skill set
    void FUN_14142fc10(CString strName);                  // store the skill set layout
    void FUN_14142f700();                                 // forget the skill set
    void FUN_14142e2a0(int nSlot, Unk_SsQuickEntry* pEntry);   // save the entry of a slot
};
Unk_SsHud* FUN_1409331f0();

// The own player: the world's local player pointer.
class Unk_SsPc : public PC
{
public:
    class Unk_SsSkillBook* FUN_1416546d0();               // the learned skills
    int FUN_14165c570();                                  // the active stance skill
    MS2Ptr<Unk_SsHeldWeapon> FUN_14165c520();           // the held item record
    int FUN_14165f150();                                  // an item is held
    float FUN_1416628b0(int nKind, int nSkillId);         // a skill stat (rate)
    float FUN_1416628f0(int nKind, int nSkillId);         // a skill stat (flat)
};
class Unk_SsSkillBook
{
public:
    virtual void v0();
    virtual MS2Ptr<SkillLevelData> vfunc_1(int nSkillId);   // 1 the learned level of a skill
    virtual bool vfunc_2(int nSkillId);                     // 2 the skill is learned
    MS2Ptr<class Unk_SsLearned> FUN_1406394d0(int nSkillId);   // the learned record of a skill
};
class Unk_SsLearned : public CPtred { public: int FUN_140637e00(); };
class Unk_SsBuffs
{
public:
    int FUN_140970020(unsigned nEffectId, unsigned short nLevel, unsigned nOverlap, int n);   // the buff is on
    unsigned FUN_140970bf0();                             // the mask of the blocked skill types
    int FUN_140970a60(int nSkillId);                      // the skill is blocked
    void FUN_140972380(CSpecialEffectCtx* pCtx);          // run the special effects of the buffs
    float FUN_140970fd0();                                // the cooldown reduce of the buffs
    int FUN_140971260(unsigned nEffectId);                // the buff is on
    int FUN_1409702d0(unsigned nEffectId);                // the buff is on (b)
    char FUN_1409703d0(int nKind);                        // the buff kind is on
};
class Unk_SsMapInfo : public CPtred
{
public:
    int FUN_140375780();                                  // the map kind (3: ...)
    int FUN_1403754f0();                                  // the map is a shadow world
    unsigned char m_pad[0xa4 - sizeof(CPtred)];
    int m_nBlock;                                         // +0xa4 (0: no field effect allowed)
    int m_nField;                                         // +0xa8
    unsigned char m_pad2[0x120 - 0xac];
    int m_nFlyable;                                       // +0x120
    int m_nGlideable;                                     // +0x124
};
MS2_CHECK_OFFSET(Unk_SsMapInfo, m_nField, 0xa8);
MS2_CHECK_OFFSET(Unk_SsMapInfo, m_nGlideable, 0x124);
class Unk_SsWorld
{
public:
    Unk_SsPc* FUN_141bd0cc0();
    void FUN_141bc9fd0(int nSlot);                        // use the quick slot
    MS2Ptr<Unk_SsMapInfo> FUN_141bd30a0();                // the map info
    bool FUN_141bcb210();
    bool FUN_141bcb150();
    int FUN_141bdb660(int nFlag);                         // a world rule is on
    int FUN_141bd3060();                                  // the map id
    class Unk_SsFieldObj* FUN_141bd2bf0(const NiPoint3& kPos, int nObjectId);   // a field object near the position
};
Unk_SsWorld* FUN_1403ed2d0();

SkillDataTable* FUN_1401958b0();                          // the skill table
void FUN_14092f4e0(int nSkillId);                         // use a skill
int FUN_14092f690(int nSkillId, int nItemId, __int64 nItemUid, int nPage, int nSlot);   // put an entry on a quick slot
int SendKeyTableMode5(int nSkillId, int nItemId, __int64 nItemUid, int nPage, int nSlot);   // the entry may be put on a quick slot
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
    int m_nId;                                            // +0x18
    int m_nIndex;                                         // +0x1c
    int m_nKind;                                          // +0x20 (0: the skill set of the quick slots)
    unsigned char m_pad0[0x28 - 0x24];
    std::vector<unsigned> m_vSkills;                      // +0x28
    unsigned char m_pad1[0x88 - 0x28 - sizeof(std::vector<unsigned>)];
    std::vector<unsigned> m_vItems;                       // +0x88
};

class Unk_SsContentSwitch { public: bool FUN_14036d570(int nFeature); };
Unk_SsContentSwitch* FUN_140166410();
class Unk_SsDevice { public: bool FUN_14116d7a0(unsigned nMask); };
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
bool FUN_141404ce0(int nSkillId, void* p, Scaleform::GFx::Value* pValue);
bool FUN_1414050c0(int nSkillId, void* p, Scaleform::GFx::Value* pValue);
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
// The helpers below are members (rcx = the function object, rdx = the returned value).
class Unk_SsFn : public AScript
{
public:
    Scaleform::GFx::Value FUN_1422bb9f0(ASArgList& args);
    Scaleform::GFx::Value FUN_141761eb0(unsigned nElement, CString strIcon, int nGray, int nFlag);
    Scaleform::GFx::Value FUN_141761fc0(CString strIcon, int nGray, int nFlag);
    Scaleform::GFx::Value FUN_1417620b0(Scaleform::GFx::Value kArg);
    Scaleform::GFx::Value FUN_141762190(bool bShow, int nCount);
};
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


// @0x1417623e0
SkillSlot::~SkillSlot()
{
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
    if (FUN_141761990() != 0)
        return 0;
    FUN_14175f200();
    return vfunc_17();
}

// @0x14175d2b0
int SkillSlot::vfunc_17()
{
    if (FUN_141761990() == 0)
    {
        int nPage = FUN_1409331f0()->FUN_140a700b0();
        int nSlot = FUN_1422cc410();
        if (SendKeyTableMode5(m_nSkillId, m_nItemId, m_nItemUid, nPage, nSlot) == 0)
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
        static_cast<Unk_SsFn*>(m_spClear.operator->())->FUN_141761fc0(m_strIcon, 0, 1);
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
    {
        CString strArg("");
        FUN_141276180(s_strButtonClickB, strArg);
    }
    FUN_14140ea40()->vfunc_3(this);
    return 1;
}

// @0x14175de40
int SkillSlot::vfunc_21()
{
    {
        CString strArg("");
        FUN_141276180(s_strButtonClickA, strArg);
    }
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
    FUN_14092f690(nSkillId, 0, 0, nPage, FUN_1422cc410());
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
    if (FUN_141404ce0(FUN_141761d90(), p, &m_value18))
    {
        Unk_SsSkillUi* pUi = FUN_140a94350();
        float fRemain = FUN_141760b90();
        pUi->vfunc_16(m_nIndex, FUN_141761d90(), p, fRemain);
        FUN_1419f37f0(5);
    }
}

// @0x14175f180
void SkillSlot::vfunc_24(void* p)
{
    if (FUN_1414050c0(FUN_141761d90(), p, &m_value18))
    {
        Unk_SsSkillUi* pUi = FUN_140a94350();
        pUi->vfunc_17(m_nIndex);
        FUN_1419f37f0(5);
    }
}

// @0x14175f200
void SkillSlot::FUN_14175f200()
{
    if (FUN_14025e7c0()->FUN_14116d7a0(0xf))
        return;
    if (m_spTween.get() != 0)
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
            static_cast<Unk_SsFn*>(m_spUpdate.operator->())->FUN_1417620b0(obj.FUN_1422bb870());
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
                    static_cast<Unk_SsFn*>(m_spClear.operator->())->FUN_141761fc0(CString(strIcon), nDisabled, 1);
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
                    static_cast<Unk_SsFn*>(m_spSet.operator->())->FUN_141761eb0(spReplace->GetElement(), CString(strIcon), nDisabled, 1);
                m_bUsable = false;
                nKey = spReplace->GetCooldownKey();
            }
            else
            {
                if (m_spClear.get() != 0)
                    static_cast<Unk_SsFn*>(m_spClear.operator->())->FUN_141761fc0(CString(strIcon), nDisabled, 1);
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
                static_cast<Unk_SsFn*>(m_spRecharge.operator->())->FUN_141762190(0 < nMax, nRecharge);
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
    if (nSkillId == 0)
        return 0;
    MS2Ptr<SkillData> spSkill = FUN_1401958b0()->GetSkillData(nSkillId);
    if (spSkill.get() != 0 && spSkill->GetRechargeMaxCount() > 0)
    {
        PC* pPc = static_cast<PC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
        if (pPc == 0)
            return 0;
        return static_cast<MyPC*>(pPc)->FUN_141523bc0()->FUN_141768770(spSkill.get());
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
    if (spSkill.get() != 0)
        return spSkill->GetRechargeMaxCount();
    return 0;
}

// @0x141760590
int SkillSlot::FUN_141760590()
{
    {
        MS2Ptr<CItem> spItem = vfunc_25();
        if (spItem.get() != 0)
            return spItem->FUN_140525ca0();
    }
    return 0;
}

// @0x141760610
int SkillSlot::FUN_141760610()
{
    {
        MS2Ptr<CItem> spItem = vfunc_25();
        if (spItem.get() != 0)
            return spItem->FUN_140525db0();
    }
    return 0;
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
    unsigned nSkillId = *pSkillId;
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
    return m_nIndex + 0x7a121;
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
    if (nByItem != 0)
        return fTotal;
    return spLevel->FUN_140804660();
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
    if (FUN_14175cd90() != 0)
        return 1;
    return FUN_1417619d0();
}

// @0x1417619d0
int SkillSlot::FUN_1417619d0()
{
    if (m_kKeys.Lookup(m_nIndex) != 0)
        return 1;
    return 0;
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
    if (FUN_141761530(&spReplace) != 0)
        return spReplace->GetId();
    return m_nSkillId;
}

// @0x141761e10
BookSlot* FUN_141761e10(DragSlot* p)
{
    BookSlot* pSlot = 0;
    if (p != 0 && p->TypeCast(0x6200051, (void**)&pSlot))
        return pSlot;
    else
        return 0;
}

// @0x141761e60
SkillSlot* FUN_141761e60(DragSlot* p)
{
    SkillSlot* pSlot = 0;
    if (p != 0 && p->TypeCast(0x6200025, (void**)&pSlot))
        return pSlot;
    else
        return 0;
}

// @0x141761eb0
Scaleform::GFx::Value Unk_SsFn::FUN_141761eb0(unsigned nElement, CString strIcon, int nGray, int nFlag)
{
    ASArgList args;
    args.FUN_1409b2800(4);
    FUN_1422bcd10(args.FUN_1409b1f70(0), nElement);
    FUN_1422bce70(args.FUN_1409b1f70(1), (const char*)strIcon);
    FUN_1422bccb0(args.FUN_1409b1f70(2), nGray);
    FUN_1422bccb0(args.FUN_1409b1f70(3), nFlag);
    return FUN_1422bb9f0(args);
}

// @0x141761fc0
Scaleform::GFx::Value Unk_SsFn::FUN_141761fc0(CString strIcon, int nGray, int nFlag)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bce70(args.FUN_1409b1f70(0), (const char*)strIcon);
    FUN_1422bccb0(args.FUN_1409b1f70(1), nGray);
    FUN_1422bccb0(args.FUN_1409b1f70(2), nFlag);
    return FUN_1422bb9f0(args);
}

// @0x1417620b0
Scaleform::GFx::Value Unk_SsFn::FUN_1417620b0(Scaleform::GFx::Value kArg)
{
    ASArgList args;
    args.FUN_1409b2800(1);
    FUN_1422bcc70(args.FUN_1409b1f70(0), Scaleform::GFx::Value(kArg));
    return FUN_1422bb9f0(args);
}

// @0x141762190
Scaleform::GFx::Value Unk_SsFn::FUN_141762190(bool bShow, int nCount)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bcce0(args.FUN_1409b1f70(0), bShow);
    FUN_1422bccb0(args.FUN_1409b1f70(1), nCount);
    return FUN_1422bb9f0(args);
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
    for (std::pair<const int, CString> entry : m_slots)
    {
        SkillSlot* pSlot = FUN_141761e60(FUN_1422cd0f0(entry.second));
        if (pSlot != 0)
            pSlot->FUN_14175f280(nFlags);
    }
}

// @0x141763710
SkillSlot* SkillSlotBag::FUN_141763710(int nItemId)
{
    for (std::pair<const int, CString> entry : m_slots)
    {
        SkillSlot* pSlot = FUN_141761e60(FUN_1422cd0f0(entry.second));
        if (pSlot != 0 && pSlot->FUN_14175cc20() == nItemId)
            return pSlot;
    }
    return 0;
}

// @0x141763800
SkillSlot* SkillSlotBag::FUN_141763800(__int64 nItemUid)
{
    for (std::pair<const int, CString> entry : m_slots)
    {
        SkillSlot* pSlot = FUN_141761e60(FUN_1422cd0f0(entry.second));
        if (pSlot != 0 && pSlot->FUN_14175cbd0() == nItemUid)
            return pSlot;
    }
    return 0;
}

// @0x1417638f0 (UIUGCEventListener::vfunc_ugc_2)
void SkillSlotBag::vfunc_ugc_2(void* pUid, CString str)
{
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680((__int64)pUid);
    if (spItem == (CItem*)0)
        return;
    SkillSlot* pSlot = FUN_141763800((__int64)pUid);
    if (pSlot != 0)
        pSlot->vfunc_10();
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
    for (std::pair<const int, CString> entry : m_slots)
    {
        SkillSlot* pSlot = FUN_141761e60(FUN_1422cd0f0(entry.second));
        if (pSlot != 0)
            pSlot->FUN_14175e310(nFlags);
    }
}

// @0x141763bd0
void SkillSlotBag::FUN_141763bd0(int nSkillId, int nFlags)
{
    for (std::pair<const int, CString> entry : m_slots)
    {
        SkillSlot* pSlot = FUN_141761e60(FUN_1422cd0f0(entry.second));
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
    if (p != 0 && p->TypeCast(0x620002a, (void**)&pBag))
        return pBag;
    else
        return 0;
}

// ======================================================================================================
// CSkillSystem (MyPC +0x13d8)
// ======================================================================================================

// ---- out-of-unit callees of CSkillSystem ----
class Unk_PCBaseComp_b18 : public CPtred { };             // the record handed out by PCBase::vfunc_103 (a CSkillRecord)
static CSkillRecord* Unk_AsSkillRecord(const MS2Ptr<Unk_PCBaseComp_b18>& sp)
{
    return static_cast<CSkillRecord*>(static_cast<CPtred*>(sp.get()));
}
extern float DAT_143aea120;                               // the equip stat 0x23 of the player
unsigned FUN_141472bc0();                                 // the millisecond clock
int FUN_14028d260(float fTime);                           // seconds to milliseconds
float FUN_14028d280(unsigned uMilliseconds);              // milliseconds to seconds
bool FUN_14028d470(float a, float b);                     // a == b (within epsilon)
float FUN_1411e1110(Unk_PCEquipSet* pEquip, int nStat);   // an equip stat
CMainSystem* FUN_14086d260();
class Unk_SsBody
{
public:
    int FUN_141240780();
    int FUN_1412407a0();
};
class Unk_SsPhys { public: int FUN_14168a450(NiPoint3* pPos, float* pOut, float fRange); };
Unk_SsPhys* FUN_1409f7ca0();

// the comparators of the emotion list (uicoupleactiondialog.cpp sorts with them)
struct Unk_SsEmotionLess { bool operator()(const MS2Ptr<CSkillSystem::stEmotion>& a, const MS2Ptr<CSkillSystem::stEmotion>& b) const; };
struct Unk_SsEmotionGreater { bool operator()(const MS2Ptr<CSkillSystem::stEmotion>& a, const MS2Ptr<CSkillSystem::stEmotion>& b) const; };

// @0x141764080
Unk_SkillCooltime::Unk_SkillCooltime()
    : m_nKey(0), m_fCombo(0), m_bCombo(0), m_f10(0), m_f14(0), m_nStart(0), m_nEnd(0), m_nState(0)
{
}

// @0x141764100
Unk_SkillCooltime::Unk_SkillCooltime(unsigned nStart, float fDuration)
    : m_nKey(0), m_fCombo(0), m_bCombo(0), m_f10(0), m_f14(0), m_nStart(nStart)
{
    m_nEnd = FUN_14028d260(fDuration) + m_nStart;
    m_nState = 0;
}

// @0x1417641a0
float Unk_SkillCooltime::GetRemain()
{
    if (IsOver())
        return 0.0f;
    return FUN_14028d280(m_nEnd - FUN_141472bc0());
}

// @0x1417641e0
unsigned Unk_SkillCooltime::GetEnd()
{
    return m_nEnd;
}

// @0x141764200
float Unk_SkillCooltime::GetTotal()
{
    return FUN_14028d280(m_nEnd - m_nStart);
}

// @0x141764230
void Unk_SkillCooltime::Set(unsigned nStart, float fDuration)
{
    m_nStart = nStart;
    m_nEnd = FUN_14028d260(fDuration) + m_nStart;
}

// @0x141764280
void Unk_SkillCooltime::SetEnd(unsigned nEnd)
{
    m_nEnd = nEnd;
}

// @0x1417642a0
void Unk_SkillCooltime::ClearEnd()
{
    m_nEnd = 0;
}

// @0x1417642c0
int Unk_SkillCooltime::IsOver()
{
    return FUN_141472bc0() >= m_nEnd;
}

// @0x141764300
int Unk_SkillCooltime::GetState()
{
    return m_nState;
}

// @0x141764320
void Unk_SkillCooltime::SetState(int nState)
{
    m_nState = nState;
}

// @0x141764340
CSkillSystem::stEmotion::stEmotion()
    : m_isNew(0), m_id(0), m_level(1), m_nExpire(0), m_n30(0), m_bPermanent(false), m_bFavorite(false)
{
}

// @0x1417643d0
bool CSkillSystem::stEmotion::FUN_1417643d0(const __int64* pNow)
{
    if (m_nExpire == 0)
        return true;
    if (m_nExpire >= *pNow)
        return true;
    return false;
}

// @0x141764410
bool Unk_SsEmotionLess::operator()(const MS2Ptr<CSkillSystem::stEmotion>& a, const MS2Ptr<CSkillSystem::stEmotion>& b) const
{
    bool bRet;
    if (a->m_bPermanent == b->m_bPermanent)
    {
        if (!a->m_bPermanent)
        {
            if (a->m_n30 == b->m_n30)
                bRet = (unsigned)a->m_id < (unsigned)b->m_id;
            else
                bRet = a->m_n30 < b->m_n30;
        }
        else
            bRet = (unsigned)a->m_id < (unsigned)b->m_id;
    }
    else
    {
        if (!a->m_bPermanent)
            bRet = false;
        else
            bRet = true;
    }
    return bRet;
}

// @0x141764570
bool Unk_SsEmotionGreater::operator()(const MS2Ptr<CSkillSystem::stEmotion>& a, const MS2Ptr<CSkillSystem::stEmotion>& b) const
{
    bool bRet;
    if (a->m_bPermanent == b->m_bPermanent)
    {
        if (!a->m_bPermanent)
        {
            if (a->m_n30 == b->m_n30)
                bRet = (unsigned)b->m_id < (unsigned)a->m_id;
            else
                bRet = b->m_n30 < a->m_n30;
        }
        else
            bRet = (unsigned)b->m_id < (unsigned)a->m_id;
    }
    else
    {
        if (!a->m_bPermanent)
            bRet = true;
        else
            bRet = false;
    }
    return bRet;
}

// @0x1417646d0
CSkillSystem::CSkillSystem()
    : m_pOwner(0), m_fLastCastTime(0), m_nLastCastSkill(0), m_nShowError(1), m_mapCooltime(17, 0.75f, 0.25f, 2.25f, 10),
      m_nGroundState(0), m_fGroundDistance(0), m_nCastAllowed(0), m_lstLapenSkills(10), m_lstLapenChains(10), m_nLapenJob(1),
      m_nf4(0), m_lstCompact(10), m_spCompact(nullptr), m_nLapenTick(0), m_nLapenDirty(1), m_spSkillSet(0),
      m_mapUses(17, 0.75f, 0.25f, 2.25f, 10), m_mapRechargeTick(17, 0.75f, 0.25f, 2.25f, 10)
{
}

// @0x141764900
CSkillSystem::~CSkillSystem()
{
    std::list<unsigned> lstTemp(m_lstSkillSets);
    std::list<unsigned>::iterator it = lstTemp.begin();
    std::list<unsigned>::iterator itEnd = lstTemp.end();
    for (; it != itEnd; ++it)
        FUN_141768100(*it);
}

// @0x141764a80
bool CSkillSystem::FUN_141764a80(MyPC* pOwner)
{
    if (pOwner == 0)
        return false;
    m_pOwner = pOwner;
    FUN_1417683d0();
    return true;
}

// @0x141765cf0
int CSkillSystem::FUN_141765cf0(int n)
{
    int nOld = m_nShowError;
    m_nShowError = n;
    return nOld;
}

// @0x141765d30
int CSkillSystem::FUN_141765d30(int n)
{
    int nOld = m_nCastAllowed;
    m_nCastAllowed = n;
    return nOld;
}

// @0x141765d70
int CSkillSystem::FUN_141765d70()
{
    return m_nCastAllowed;
}

// @0x141765d90
int CSkillSystem::FUN_141765d90()
{
    return !m_mapCooltime.IsEmpty();
}

// @0x141765de0
void CSkillSystem::FUN_141765de0()
{
    for (POSITION pos = m_mapCooltime.GetStartPosition(); pos != 0; m_mapCooltime.GetNext(pos))
    {
        Unk_SkillCooltime& rCool = m_mapCooltime.GetValueAt(pos);
        rCool.ClearEnd();
    }
    m_mapUses.RemoveAll();
}

// @0x141765e70
void CSkillSystem::FUN_141765e70(int nSkillId)
{
    MS2Ptr<SkillData> spSkill = FUN_1401958b0()->GetSkillData(nSkillId);
    if (spSkill.IsNull())
        return;
    unsigned __int64 nKey = spSkill->GetCooldownKey();
    ATL::CAtlMap<unsigned __int64, Unk_SkillCooltime>::CPair* pPair = m_mapCooltime.Lookup(nKey);
    if (pPair != 0)
    {
        Unk_SkillCooltime& rCool = m_mapCooltime.GetValueAt((POSITION)pPair);
        if (FUN_140aa6d40() != 0)
            FUN_141b0e2f0(FUN_140aa6d40(), rCool.m_nKey);
        rCool.ClearEnd();
    }
}

// @0x141765f60
void CSkillSystem::FUN_141765f60(unsigned __int64 nKey)
{
    ATL::CAtlMap<unsigned __int64, Unk_SkillCooltime>::CPair* pPair = m_mapCooltime.Lookup(nKey);
    if (pPair != 0)
    {
        Unk_SkillCooltime& rCool = m_mapCooltime.GetValueAt((POSITION)pPair);
        if (FUN_140aa6d40() != 0)
            FUN_141b0e2f0(FUN_140aa6d40(), rCool.m_nKey);
        rCool.ClearEnd();
    }
}

// @0x141765fe0
float CSkillSystem::FUN_141765fe0(int nSkillId, int bIgnoreCombo)
{
    MS2Ptr<SkillData> spSkill = FUN_1401958b0()->GetSkillData(nSkillId);
    if (spSkill.IsNull())
        return 0.0f;
    ATL::CAtlMap<unsigned __int64, Unk_SkillCooltime>::CPair* pPair = m_mapCooltime.Lookup(spSkill->GetCooldownKey());
    if (pPair != 0)
    {
        Unk_SkillCooltime& rCool = m_mapCooltime.GetValueAt((POSITION)pPair);
        if (bIgnoreCombo == 0 || rCool.m_fCombo <= 0.0f)
        {
            float fRemain = rCool.GetRemain();
            if (!FUN_14028d470(fRemain, 0))
                return fRemain;
        }
    }
    if (spSkill->m_nCooldownGroupID != 0)
    {
        POSITION pos = m_mapCooltime.GetStartPosition();
        while (pos != 0)
        {
            Unk_SkillCooltime& rCool = m_mapCooltime.GetValueAt(pos);
            if (bIgnoreCombo == 0 || rCool.m_fCombo <= 0.0f)
            {
                unsigned __int64 nGroup = rCool.m_nKey >> 32;
                if (nGroup == spSkill->m_nCooldownGroupID)
                {
                    float fRemain = rCool.GetRemain();
                    if (!FUN_14028d470(fRemain, 0))
                        return fRemain;
                }
            }
            m_mapCooltime.GetNext(pos);
        }
    }
    return 0.0f;
}

// @0x141766230
int CSkillSystem::FUN_141766230(int nSkillId, float* pRemain, float* pTotal, int* pByGroup, int bIgnoreCombo)
{
    MS2Ptr<SkillData> spSkill = FUN_1401958b0()->GetSkillData(nSkillId);
    if (spSkill.IsNull())
        return 0;
    ATL::CAtlMap<unsigned __int64, Unk_SkillCooltime>::CPair* pPair = m_mapCooltime.Lookup(spSkill->GetCooldownKey());
    if (pPair != 0)
    {
        Unk_SkillCooltime& rCool = m_mapCooltime.GetValueAt((POSITION)pPair);
        if (bIgnoreCombo == 0 || rCool.m_fCombo <= 0.0f)
        {
            float fRemain = rCool.GetRemain();
            if (!FUN_14028d470(fRemain, 0))
            {
                *pRemain = fRemain;
                *pTotal = rCool.GetTotal();
                *pByGroup = 0;
                return 1;
            }
        }
    }
    if (spSkill->m_nCooldownGroupID != 0)
    {
        POSITION pos = m_mapCooltime.GetStartPosition();
        while (pos != 0)
        {
            Unk_SkillCooltime& rCool = m_mapCooltime.GetValueAt(pos);
            if (bIgnoreCombo == 0 || rCool.m_fCombo <= 0.0f)
            {
                unsigned __int64 nGroup = rCool.m_nKey >> 32;
                if (nGroup == spSkill->m_nCooldownGroupID)
                {
                    float fRemain = rCool.GetRemain();
                    if (!FUN_14028d470(fRemain, 0))
                    {
                        *pRemain = fRemain;
                        *pTotal = rCool.GetTotal();
                        *pByGroup = 1;
                        return 1;
                    }
                }
            }
            m_mapCooltime.GetNext(pos);
        }
    }
    return 0;
}

// @0x141766900
void CSkillSystem::FUN_141766900(unsigned __int64 nKey, unsigned nEnd)
{
    if (FUN_141472bc0() < nEnd)
    {
        if (m_mapCooltime.Lookup(nKey) != 0)
            m_mapCooltime.RemoveKey(nKey);
        Unk_SkillCooltime kCool;
        kCool.m_nKey = nKey;
        kCool.SetEnd(nEnd);
        m_mapCooltime.SetAt(nKey, kCool);
        if (FUN_140aa6d40() != 0)
            FUN_141b0e260(FUN_140aa6d40(), kCool.m_nKey);
    }
}

// @0x1417669c0
void CSkillSystem::FUN_1417669c0(int nStart, int nSkillId, float fDuration)
{
    MS2Ptr<SkillData> spSkill = FUN_1401958b0()->GetSkillData(nSkillId);
    if (spSkill.IsNull())
        return;
    if (m_mapCooltime.Lookup(spSkill->GetCooldownKey()) != 0)
        m_mapCooltime.RemoveKey(spSkill->GetCooldownKey());
    Unk_SkillCooltime kCool(nStart, fDuration);
    kCool.m_nKey = spSkill->GetCooldownKey();
    m_mapCooltime.SetAt(kCool.m_nKey, kCool);
    if (FUN_140aa6d40() != 0)
        FUN_141b0e260(FUN_140aa6d40(), kCool.m_nKey);
}

extern CString DAT_143aea1b8;                             // the ui sounds of the skill errors
extern CString DAT_143aea1c0;
extern CString DAT_143aea1c8;
extern CString DAT_143aea1d0;
extern CString DAT_143aea1d8;
extern CString DAT_143aea1e0;

// @0x141764ad0
int CSkillSystem::FUN_141764ad0(SkillData* pData)
{
    Unk_SsBody* pBody = reinterpret_cast<Unk_SsBody*>(m_pOwner->FUN_14166d220());
    Ridee* spRidee = m_pOwner->FUN_1416764a0();
    if (spRidee != 0)
    {
        Unk_SsBody* pRideeBody = reinterpret_cast<Unk_SsBody*>(spRidee->FUN_14166d220());
        if (pRideeBody != 0)
            pBody = pRideeBody;
    }
    if ((pBody == 0 || pBody->FUN_141240780() == 0 || pBody->FUN_1412407a0() == 0) && m_pOwner->vfunc_99(0) == 0)
        return pData->GetId();
    return pData->m_nJump;
}

// @0x141764be0
int CSkillSystem::FUN_141764be0(int nSkillId)
{
    {
        MS2Ptr<Unk_PCBaseComp_b18> spCast = m_pOwner->vfunc_103();
        if (spCast.get() != 0)
            return Unk_AsSkillRecord(spCast)->m_spSkill->m_blockA4.FUN_140802fc0(nSkillId);
    }
    return nSkillId;
}

// @0x141764c80
MS2Ptr<SkillLevelData> CSkillSystem::FUN_141764c80(int nSkillId)
{
    MS2Ptr<SkillData> spSkill = FUN_1401958b0()->GetSkillData(nSkillId);
    if (spSkill == 0)
        return MS2Ptr<SkillLevelData>(nullptr);
    if (!spSkill->FUN_1407e9d30())
        return reinterpret_cast<Unk_SsPc*>(m_pOwner)->FUN_1416546d0()->vfunc_1(nSkillId);
    MS2Ptr<stEmotion> spEmotion = FUN_14176ba90(nSkillId);
    if (spEmotion == 0)
        return MS2Ptr<SkillLevelData>(nullptr);
    return spSkill->FUN_1407e90a0(spEmotion->m_level);
}

// MS2-FUNCTIONAL: exe 1840 vs ours 1902 bytes: the MS2Ptr<CSkillRecord>(nullptr) error returns and CString temporaries are laid out differently (same callees/logic)
// @0x141764e30
MS2Ptr<CSkillRecord> CSkillSystem::FUN_141764e30(Unk_InventorySkillRequest& kReq)
{
    Unk_SsPc* pOwner = reinterpret_cast<Unk_SsPc*>(m_pOwner);
    if (!pOwner->FUN_1416546d0()->vfunc_2(kReq.m_nSkillId))
    {
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_err_not_learn_skill")), 1, 1);
        FUN_141276180(DAT_143aea1b8, CString(""));
        return MS2Ptr<CSkillRecord>(nullptr);
    }
    __int64 nItemUid = FUN_1409331f0()->FUN_14142ded0(kReq.m_n34);
    if (nItemUid != 0)
    {
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nItemUid);
        if (spItem == 0)
            return MS2Ptr<CSkillRecord>(nullptr);
        unsigned short nPcLevel = (unsigned short)pOwner->vfunc_78();
        if (FUN_140526810(spItem.operator->(), nPcLevel) == 0)
        {
            FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_err_not_enough_level")), 1, 1);
            return MS2Ptr<CSkillRecord>(nullptr);
        }
        kReq.m_n40 = nItemUid;
    }
    MS2Ptr<CSkillRecord> spRecord = FUN_141765570(kReq);
    if (spRecord.IsNull())
    {
        MS2Ptr<SkillLevelData> spLevel = FUN_141764c80(kReq.m_nSkillId);
        if (spLevel == 0)
            return MS2Ptr<CSkillRecord>(nullptr);
        if (spLevel->FUN_140803e10()->m_nUseDefaultSkillID == 0 && !spLevel->FUN_140803e10()->m_bUseDefaultSkill)
            return MS2Ptr<CSkillRecord>(nullptr);
        int nWhy = FUN_141769b70(spLevel, &kReq);
        if (nWhy == 0)
            return MS2Ptr<CSkillRecord>(nullptr);
        if (nWhy != 6 && nWhy != 7 && nWhy != 2)
            return MS2Ptr<CSkillRecord>(nullptr);
        int nOrigin = 0;
        int nDefaultId = spLevel->FUN_140803e10()->m_nUseDefaultSkillID;
        if (nDefaultId == 0 || nWhy == 2)
        {
            if (!spLevel->FUN_140803e10()->m_bUseDefaultSkill)
                return MS2Ptr<CSkillRecord>(nullptr);
            nDefaultId = pOwner->FUN_14165c570();
            nOrigin = kReq.m_nSkillId;
        }
        MS2Ptr<SkillData> spDefault = FUN_1401958b0()->GetSkillData(nDefaultId);
        MS2Ptr<SkillLevelData> spDefaultLevel = spDefault->FUN_1407e90a0(1);
        if (spDefaultLevel == 0)
            return MS2Ptr<CSkillRecord>(nullptr);
        kReq.m_nSkillId = nDefaultId;
        kReq.m_nLevel = spDefaultLevel->FUN_140803df0();
        kReq.m_b38 = spDefaultLevel->FUN_140804450();
        spRecord = FUN_141765570(kReq);
        if (spRecord.get() != 0)
            spRecord->m_nA8 = nOrigin;
    }
    return spRecord;
}

// MS2-FUNCTIONAL: exe 1268 vs ours 1285 bytes: MS2Ptr<SkillLevelData> operator-> temporaries are reused differently (one fewer exe call; same logic)
// @0x141765570
MS2Ptr<CSkillRecord> CSkillSystem::FUN_141765570(Unk_InventorySkillRequest& kReq)
{
    MS2Ptr<SkillLevelData> spLevel = FUN_1401958b0()->GetSkillLevelData(kReq.m_nSkillId, kReq.m_nLevel);
    if (spLevel.IsNull())
        return MS2Ptr<CSkillRecord>(nullptr);
    MS2Ptr<SkillLevelData> spCur = spLevel;
    if (kReq.m_b38)
    {
        int nBase = FUN_141764be0(spCur->FUN_140803e10()->GetId());
        if (nBase != spCur->FUN_140803dc0())
        {
            spCur = FUN_14176b7c0(nBase, spCur->FUN_140803df0());
            if (spCur == 0)
                return MS2Ptr<CSkillRecord>(nullptr);
        }
        int nJump = FUN_141764ad0(spCur->FUN_140803e10());
        if (nJump != spCur->FUN_140803dc0())
        {
            spCur = FUN_14176b7c0(nJump, spCur->FUN_140803df0());
            if (spCur == 0)
                return MS2Ptr<CSkillRecord>(nullptr);
        }
    }
    int nWhy = FUN_141769b70(spCur, &kReq);
    if (nWhy == 0)
    {
        kReq.m_nSkillId = spCur->FUN_140803dc0();
        kReq.m_nLevel = spCur->FUN_140803df0();
        MS2Ptr<CSkillRecord> spRecord(new CSkillRecord);
        if (!spRecord->Init(kReq))
            return MS2Ptr<CSkillRecord>(nullptr);
        if (!kReq.m_b39)
            m_pOwner->vfunc_100(spRecord, 1);
        return spRecord;
    }
    if (m_nShowError != 0)
        FUN_141769440(nWhy);
    return MS2Ptr<CSkillRecord>(nullptr);
}

// @0x141765a70
unsigned char CSkillSystem::FUN_141765a70(int nSkillId)
{
    MS2Ptr<SkillLevelData> spLevel = FUN_141764c80(nSkillId);
    if (spLevel.IsNull())
        return 0;
    Unk_InventorySkillRequest kReq(spLevel->FUN_140803dc0(), 1);
    int nWhy = FUN_14176a380(spLevel, &kReq);
    if (nWhy == 0)
        return 1;
    if (m_nShowError != 0)
        FUN_141769440(nWhy);
    return 0;
}

// @0x141765b80
bool CSkillSystem::FUN_141765b80(int nSkillId)
{
    MS2Ptr<SkillData> spSkill = FUN_1401958b0()->GetSkillData(nSkillId);
    if (spSkill.IsNull())
        return false;
    int nBase = FUN_141764be0(spSkill->GetId());
    if (nBase != 0 && nBase != (int)spSkill->GetId())
    {
        MS2Ptr<SkillData> spOther = FUN_1401958b0()->GetSkillData(nBase);
        if (spOther.get() != 0)
            spSkill = spOther;
    }
    Unk_InventorySkillRequest kReq(spSkill->GetId(), 1);
    int nWhy = FUN_14176a8c0(spSkill.get(), &kReq);
    return nWhy == 0;
}

// ---- out-of-unit callees of the cast checks ----
extern int DAT_143ab2898;                                 // the meso (or ep) of the player
extern int DAT_143ab2914;
extern int DAT_143ab287c;
CStringW FUN_1409eec40(int nStringId);                    // string table text by id
unsigned __int64 FUN_140869440();                         // the server time
unsigned FUN_140869420();                                 // millisecond clock
unsigned FUN_1417692f0(unsigned n);
bool FUN_141682fe0(void* pBuffMgr, int nBuffId);          // a buff is on

class Unk_SsValueI { public: int FUN_14025a620(); int m_n; };
class Unk_SsValueF { public: float FUN_1402bac70(); float m_f; };
// The global constants of the game (0x1401d3200).
class Unk_SsConst
{
public:
    unsigned char m_pad0[0x9a90];
    int m_nSkillItemA;                                    // +0x9a90
    int m_n9a94;
    int m_nSkillItemB;                                    // +0x9a98
    int m_nGlideSkill;                                    // +0x9a9c
    unsigned char m_pad1[0xa284 - 0x9aa0];
    int m_nSkillItemC;                                    // +0xa284
    unsigned char m_pad2[0xbdc0 - 0xa288];
    Unk_SsValueI m_kFlyCast;                              // +0xbdc0
    unsigned char m_pad3[0xbe18 - 0xbdc0 - sizeof(Unk_SsValueI)];
    Unk_SsValueF m_kCastReuse;                            // +0xbe18
    unsigned char m_pad4[0xbe70 - 0xbe18 - sizeof(Unk_SsValueF)];
    Unk_SsValueI m_kCastRepeat;                           // +0xbe70
};
MS2_CHECK_OFFSET(Unk_SsConst, m_nSkillItemA, 0x9a90);
MS2_CHECK_OFFSET(Unk_SsConst, m_nSkillItemC, 0xa284);
MS2_CHECK_OFFSET(Unk_SsConst, m_kFlyCast, 0xbdc0);
MS2_CHECK_OFFSET(Unk_SsConst, m_kCastReuse, 0xbe18);
MS2_CHECK_OFFSET(Unk_SsConst, m_kCastRepeat, 0xbe70);
Unk_SsConst* FUN_1401d3200();

class Unk_HsInfo : public CPtred { public: bool FUN_14050a4d0(); };
class Unk_SsHeldWeapon : public CPtred
{
public:
    int m_nRight;                                         // +0x18
    int m_nLeft;                                          // +0x1c
};
class Unk_SsEffectData : public CPtred
{
public:
    unsigned char m_pad[0x270 - sizeof(CPtred)];
    void* m_p270;                                         // +0x270 (first word of a container)
    void* m_p278;
    void* m_p280;
    float m_f288;
    float m_f28c;
    float m_f290;
};
MS2_CHECK_OFFSET(Unk_SsEffectData, m_f290, 0x290);
MS2Ptr<Unk_SsEffectData> FUN_140aafef0(SkillDataTable* pTable, int nEffectId, unsigned short nLevel);
class Unk_SsSkillSetTable { public: MS2Ptr<Unk_MyPCSkillSet> FUN_140809840(int nSetId); };
Unk_SsSkillSetTable* FUN_1414a57b0();

// the lapenshard skill table of a job
class Unk_SsLapenRow : public CPtred
{
public:
    unsigned m_nSkillId;                                  // +0x18
    unsigned m_nCount;                                    // +0x1c
};
class Unk_SsLapenSet
{
public:
    Unk_SsLapenSet(int nJob);                             // 0x140dcada0
    ~Unk_SsLapenSet();                                    // 0x140dcb780
    bool FUN_140fa3060();                                 // no set for the job
    ATL::CAtlList<MS2Ptr<Unk_SsLapenRow> >* FUN_140dcb990();   // the rows
private:
    void* m_p0;
    void* m_p1;
};

// The skill set of a ridee (CSkillSet): +0x18 id, +0x1c index, +0x20 kind (0: the skill set of the quick slots).

// MS2-FUNCTIONAL: exe 1042 vs ours 1024 bytes: exe goes through one more MS2Ptr<SkillData> operator-> temp (39 vs 38 calls; same logic)
// @0x1417664e0
void CSkillSystem::FUN_1417664e0(unsigned nStart, int nSkillId, float fCool, float fCombo, int bCombo)
{
    MS2Ptr<SkillData> spSkill = FUN_1401958b0()->GetSkillData(nSkillId);
    if (spSkill.IsNull())
        return;
    if (spSkill->GetRechargeMaxCount() != 0 && FUN_141765fe0(nSkillId, 0) > 0.0f)
        return;
    if (m_mapCooltime.Lookup(spSkill->GetCooldownKey()) != 0)
        m_mapCooltime.RemoveKey(spSkill->GetCooldownKey());
    float fExtra = 0.0f;
    float fFinal = fCool;
    if (bCombo == 0)
    {
        float fReduce = 0.0f;
        if (spSkill->m_nCooldownGroupID != 0)
        {
            MS2Ptr<CSEReduceSkillGroupCooltimeCtx> spCtx(new CSEReduceSkillGroupCooltimeCtx);
            spCtx->m_nGroupId = spSkill->m_nCooldownGroupID;
            reinterpret_cast<Unk_SsBuffs*>(m_pOwner->FUN_1416749a0())->FUN_140972380(spCtx.get());
            fReduce = spCtx->m_fReduceRate;
        }
        float fRate = fReduce;
        float fFlat = 0.0f;
        Unk_SsPc* pOwner = reinterpret_cast<Unk_SsPc*>(m_pOwner);
        if (!spSkill->m_bIgnoreReduceCooldown)
        {
            fFlat = pOwner->FUN_1416628f0(0x3ea, nSkillId);
            fFlat = fFlat + 0.0f;
            fRate = fRate + DAT_143aea120 + pOwner->FUN_1416628b0(0x3e9, nSkillId);
        }
        float fNew = (fCool - fFlat) - fCool * fRate;
        if (0.0f <= fNew)
            fFinal = fNew;
        else
            fFinal = 0.0f;
    }
    if (FUN_14028d470(0, fFinal))
        fExtra = fCombo;
    if (!FUN_14028d470(fFinal + fExtra, 0))
    {
        Unk_SkillCooltime kCool(nStart, fFinal + fExtra);
        kCool.m_nKey = spSkill->GetCooldownKey();
        kCool.m_fCombo = fExtra;
        kCool.m_bCombo = bCombo;
        m_mapCooltime.SetAt(kCool.m_nKey, kCool);
        if (bCombo == 0 && FUN_140aa6d40() != 0)
            FUN_141b0e260(FUN_140aa6d40(), kCool.m_nKey);
    }
}

// @0x141766af0
void CSkillSystem::FUN_141766af0(float fDelta)
{
    ATL::CAtlArray<Unk_SkillCooltime> arrOver;
    POSITION pos = m_mapCooltime.GetStartPosition();
    while (pos != 0)
    {
        POSITION posCur = pos;
        m_mapCooltime.GetNext(pos);
        Unk_SkillCooltime& rCool = m_mapCooltime.GetValueAt(posCur);
        if (rCool.GetState() == 0)
        {
            if (rCool.IsOver())
            {
                if (FUN_140aa6d40() != 0)
                    FUN_141b0e2f0(FUN_140aa6d40(), rCool.m_nKey);
                rCool.SetState(1);
                arrOver.Add(rCool);
            }
        }
        else if (rCool.GetEnd() + 10000 < FUN_141472bc0())
            m_mapCooltime.RemoveAtPos(posCur);
    }
    for (unsigned i = 0; i < arrOver.GetCount(); i = i + 1)
        FUN_1417687e0(&arrOver[i]);
    FUN_141768a50();
    FUN_141766d70();
    FUN_141766ec0(0);
}

// @0x141766cc0
void CSkillSystem::FUN_141766cc0(MS2Ptr<CSkillRecord> spRecord)
{
    if (!spRecord->m_spLevel->FUN_140804450())
    {
        m_fLastCastTime = (float)FUN_14086d260()->FUN_141473280();
        m_nLastCastSkill = spRecord->GetSkillId();
    }
    DAT_143aea120 = FUN_1411e1110(m_pOwner->FUN_1416561a0(), 0x23);
}

// @0x141766d70
void CSkillSystem::FUN_141766d70()
{
    int nState = m_pOwner->FUN_141671a30();
    if (nState == m_nGroundState)
    {
        NiPoint3 kPos = m_pOwner->vfunc_18();
        float fDist = 0.0f;
        if (FUN_1409f7ca0()->FUN_14168a450(&kPos, &fDist, 200.0f) == 0)
        {
            if (fDist != m_fGroundDistance)
                FUN_1419f37f0(1);
        }
        else
        {
            int bChanged = 0;
            if (m_fGroundDistance >= 100.0f || fDist < 100.0f)
            {
                if (m_fGroundDistance >= 100.0f && fDist < 100.0f)
                    bChanged = 1;
            }
            else
                bChanged = 1;
            if (bChanged != 0)
                FUN_1419f37f0(1);
        }
        m_fGroundDistance = fDist;
    }
    else
        FUN_1419f37f0(1);
    m_nGroundState = nState;
}

// @0x141766ec0
void CSkillSystem::FUN_141766ec0(int bForce)
{
    if (!FUN_140166410()->FUN_14036d570(0x10))
        return;
    MS2Ptr<CSkillCompactControlConfig> spOld = m_spCompact;
    POSITION pos = m_lstCompact.GetHeadPosition();
    while (pos != 0)
    {
        MS2Ptr<CSkillCompactControlConfig> spConfig = m_lstCompact.GetAt(pos);
        if (spConfig->m_30 == 0)
        {
        }
        else
        {
            CSkillCompactControlConfig* pConfig = spConfig.operator->();
            if (FUN_141682fe0(m_pOwner->FUN_14166d240(), (int)pConfig->m_30))
            {
                m_spCompact = spConfig;
                break;
            }
        }
        m_lstCompact.GetNext(pos);
    }
    int nJob = m_pOwner->FUN_141654700();
    if (m_nLapenJob == nJob && bForce == 0)
    {
        if (spOld.get() == m_spCompact.get())
            goto LAB_CHECK;
    }
    m_lstLapenSkills.RemoveAll();
    m_lstLapenChains.RemoveAll();
    m_nLapenJob = nJob;
LAB_CHECK:
    if (m_spCompact == 0)
        return;
    if (m_spCompact->m_skills.empty())
        return;
    Unk_SsLapenSet kSet(nJob);
    if (kSet.FUN_140fa3060())
        return;
    if (kSet.FUN_140dcb990()->IsEmpty())
        return;
    bool bSkillsEmpty = m_lstLapenSkills.IsEmpty();
    bool bChainsEmpty = m_lstLapenChains.IsEmpty();
    POSITION posRow = kSet.FUN_140dcb990()->GetHeadPosition();
    while (posRow != 0)
    {
        MS2Ptr<Unk_SsLapenRow> spRow = kSet.FUN_140dcb990()->GetAt(posRow);
        if (reinterpret_cast<Unk_SsPc*>(m_pOwner)->FUN_1416546d0()->vfunc_2(spRow->m_nSkillId))
        {
            if (m_spCompact->m_skills.find(spRow->m_nSkillId) == m_spCompact->m_skills.end())
            {
                unsigned nSkillId = spRow->m_nSkillId;
                unsigned short nLevel = m_pOwner->FUN_141528b80(nSkillId);
                MS2Ptr<SkillLevelData> spLevel = FUN_1401958b0()->GetSkillLevelData(nSkillId, nLevel);
                if (spLevel.IsNull())
                {
                }
                else if (spLevel->FUN_140803e10()->m_condition.m_nUseCoolDownShowUI == 0)
                {
                    if (bChainsEmpty && m_lstLapenChains.Find(nSkillId) == 0)
                    {
                        m_lstLapenChains.AddTail(nSkillId);
                        for (unsigned i = 0; i < spRow->m_nCount; i = i + 1)
                            m_lstLapenChains.AddTail(nSkillId);
                    }
                }
                else if (bSkillsEmpty)
                    m_lstLapenSkills.AddTail(nSkillId);
            }
        }
        kSet.FUN_140dcb990()->GetNext(posRow);
    }
}

// MS2-FUNCTIONAL: exe 1253 vs ours 1341 bytes: compact-config/level-data loop keeps different temporaries and branch layout (same callees/logic)
// @0x1417674a0
int CSkillSystem::FUN_1417674a0(int bAny)
{
    if (!FUN_140166410()->FUN_14036d570(0x10))
        return 0;
    if (FUN_140869420() < m_nLapenTick)
        return 0;
    if (m_spCompact == 0)
        return 0;
    if (!FUN_141682fe0(m_pOwner->FUN_14166d240(), (int)m_spCompact->m_30))
    {
        m_nLapenDirty = 1;
        return 0;
    }
    int nKey = FUN_1409331f0()->FUN_14142c940(m_spCompact->m_30, 0);
    if (FUN_1409331f0()->FUN_14142e6f0(nKey) != 0)
        return 0;
    ATL::CAtlList<unsigned> lstAll(10);
    lstAll.AddTailList(&m_lstLapenSkills);
    lstAll.AddTailList(&m_lstLapenChains);
    POSITION pos = lstAll.GetHeadPosition();
    while (pos != 0)
    {
        unsigned nSkillId = lstAll.GetAt(pos);
        MS2Ptr<SkillLevelData> spLevel = FUN_141764c80(nSkillId);
        if (spLevel.IsNull())
        {
        }
        else
        {
            bool bTry = true;
            if (bAny == 0)
            {
                float fCool = FUN_141765fe0(spLevel->FUN_140803dc0(), 0);
                int bRecharge = spLevel->FUN_140803e10()->GetRechargeMaxCount() != 0;
                bool bCooling;
                if (bRecharge != 0 || fCool <= 0.0f)
                {
                    bCooling = false;
                    if (bRecharge != 0 && FUN_1417686e0(spLevel->FUN_140803dc0()) == 0)
                        bCooling = true;
                }
                else
                    bCooling = true;
                if (bCooling)
                {
                    if (spLevel->FUN_140803e10()->m_condition.m_nUseCoolDownShowUI == 0 && m_nCastAllowed != 0)
                        bTry = true;
                    else
                        bTry = false;
                }
            }
            if (bTry)
            {
                unsigned nId = spLevel->FUN_140803dc0();
                unsigned short nLevel = spLevel->FUN_140803df0();
                m_pOwner->FUN_141526c80((int&)nId, nLevel);
                if (nId != spLevel->FUN_140803dc0() || nLevel != spLevel->FUN_140803df0())
                {
                    spLevel = FUN_141764c80(nId);
                    if (spLevel.IsNull())
                    {
                        lstAll.GetNext(pos);
                        continue;
                    }
                }
                Unk_InventorySkillRequest kReq(spLevel->FUN_140803dc0(), 1);
                int nWhy = FUN_14176a380(spLevel, &kReq);
                if (nWhy == 0)
                    return nSkillId;
                if (m_nLapenDirty != 0)
                {
                    FUN_141769440(nWhy);
                    m_nLapenDirty = 0;
                }
            }
        }
        lstAll.GetNext(pos);
    }
    return 0;
}

// MS2-FUNCTIONAL: exe CAtlList<unsigned>::Find takes the origin id by const& (element traits with a reference INARGTYPE); ours CElementTraits<unsigned> passes it by value
// @0x141767990
void CSkillSystem::FUN_141767990(int nSkillId, unsigned short nLevel)
{
    if (!FUN_140166410()->FUN_14036d570(0x10))
        return;
    MS2Ptr<SkillData> spSkill = FUN_1401958b0()->GetSkillData(nSkillId);
    if (spSkill.IsNull())
        return;
    MS2Ptr<SkillLevelData> spLevel = spSkill->FUN_1407e90a0(nLevel);
    if (spLevel.IsNull())
        return;
    POSITION pos = m_lstLapenChains.Find(spSkill->GetOriginId());
    if (pos == 0)
        return;
    m_lstLapenChains.RemoveAt(pos);
}

// @0x141767ae0
void CSkillSystem::FUN_141767ae0(CByteBuffer* pBuffer)
{
    CInputStream* pIn = pBuffer;
    if (pIn->vfunc_o8_1() == 2)
    {
        m_lstCompact.RemoveAll();
        unsigned nCount = pIn->vfunc_o8_3();
        for (unsigned i = 0; i < nCount; i = i + 1)
        {
            MS2Ptr<CSkillCompactControlConfig> spConfig(new CSkillCompactControlConfig);
            spConfig->m_strName = pIn->vfunc_o8_8();
            spConfig->m_30 = pIn->vfunc_o8_4();
            unsigned nSkills = pIn->vfunc_o8_3();
            for (unsigned j = 0; j < nSkills; j = j + 1)
            {
                unsigned nId = pIn->vfunc_o8_3();
                spConfig->m_skills.insert(nId);
            }
            m_lstCompact.AddTail(spConfig);
        }
    }
}

// @0x141767d90
void CSkillSystem::FUN_141767d90(ATL::CAtlList<MS2Ptr<CSkillCompactControlConfig> >* pList)
{
    m_lstCompact.RemoveAll();
    m_lstCompact.AddTailList(pList);
    FUN_141766ec0(1);
}

// @0x141767df0
void CSkillSystem::FUN_141767df0(int bOn)
{
    if (bOn == 0)
    {
        m_pOwner->FUN_14166cd70(0x80);
        m_nLapenTick = FUN_140869420() + 1000;
    }
    else
        m_pOwner->FUN_14166cce0(0x80);
}

// @0x141767e60
CStringW CSkillSystem::FUN_141767e60(unsigned __int64 nKey)
{
    POSITION pos = m_lstCompact.GetHeadPosition();
    while (true)
    {
        if (pos == 0)
            return CStringW();
        MS2Ptr<CSkillCompactControlConfig> spConfig = m_lstCompact.GetAt(pos);
        if (spConfig->m_30 != 0 && spConfig->m_30 == (__int64)nKey)
            return spConfig->m_strName;
        m_lstCompact.GetNext(pos);
    }
}

// @0x141767f80
void CSkillSystem::FUN_141767f80(int nSkillSetId)
{
    if (nSkillSetId == 0)
        return;
    if (m_spSkillSet.get() != 0 && m_spSkillSet->m_nKind == 0)
    {
        CString strName = Unk_SocketFormat("SkillSet{0}_{1}", m_spSkillSet->m_nId, m_spSkillSet->m_nIndex);
        FUN_1409331f0()->FUN_14142f8b0(strName);
    }
    m_lstSkillSets.push_back(*(const unsigned*)&nSkillSetId);
    m_spSkillSet = FUN_1414a57b0()->FUN_140809840(nSkillSetId);
}

// MS2-FUNCTIONAL: frame slots shifted by 8 and the exe copies the FUN_140809840 MS2Ptr result through one more temp before operator= (same callees/logic)
// @0x141768100
void CSkillSystem::FUN_141768100(int nSkillSetId)
{
    if (nSkillSetId == 0)
        return;
    if (m_spSkillSet.get() != 0 && m_spSkillSet->m_nKind == 0 && m_spSkillSet->m_nId == nSkillSetId)
    {
        CString strName = Unk_SocketFormat("SkillSet{0}_{1}", m_spSkillSet->m_nId, m_spSkillSet->m_nIndex);
        FUN_1409331f0()->FUN_14142f8b0(strName);
    }
    std::list<unsigned>::iterator it = m_lstSkillSets.begin();
    std::list<unsigned>::iterator itEnd = m_lstSkillSets.end();
    while (it != itEnd)
    {
        if (*it == nSkillSetId)
        {
            m_lstSkillSets.erase(it);
            break;
        }
        ++it;
    }
    if (!m_lstSkillSets.empty())
        m_spSkillSet = FUN_1414a57b0()->FUN_140809840(m_lstSkillSets.back());
    else
        m_spSkillSet = 0;
}

// @0x141768380
MS2Ptr<Unk_MyPCSkillSet> CSkillSystem::FUN_141768380()
{
    return m_spSkillSet;
}

// @0x1417683d0
void CSkillSystem::FUN_1417683d0()
{
    if (m_spSkillSet == 0)
        FUN_1409331f0()->FUN_14142f700();
    else
    {
        FUN_1409331f0()->FUN_14142e8c0(m_spSkillSet);
        if (m_spSkillSet->m_nKind == 0)
        {
            CString strName = Unk_SocketFormat("SkillSet{0}_{1}", m_spSkillSet->m_nId, m_spSkillSet->m_nIndex);
            FUN_1409331f0()->FUN_14142fc10(strName);
        }
    }
}

// @0x141768530
void CSkillSystem::FUN_141768530(int nSkillId, int nUses, int)
{
    MS2Ptr<SkillData> spSkill = FUN_1401958b0()->GetSkillData(nSkillId);
    if (spSkill == 0)
        return;
    FUN_1417685c0(spSkill.get(), nUses);
}

// @0x1417685c0
void CSkillSystem::FUN_1417685c0(SkillData* pData, int nUses)
{
    if (pData != 0)
        m_mapUses.SetAt(pData->GetRechargeId(), nUses);
}

// @0x141768610
int CSkillSystem::FUN_141768610(int nSkillId)
{
    MS2Ptr<SkillData> spSkill = FUN_1401958b0()->GetSkillData(nSkillId);
    return FUN_141768680(spSkill.get());
}

// @0x141768680
int CSkillSystem::FUN_141768680(SkillData* pData)
{
    int nUses;
    if (pData == 0)
        nUses = 0;
    else
    {
        nUses = 0;
        m_mapUses.Lookup(pData->GetRechargeId(), nUses);
    }
    return nUses;
}

// @0x1417686e0
int CSkillSystem::FUN_1417686e0(int nSkillId)
{
    MS2Ptr<SkillData> spSkill = FUN_1401958b0()->GetSkillData(nSkillId);
    if (spSkill == 0)
        return 0;
    return FUN_141768770(spSkill.get());
}

// @0x141768770
int CSkillSystem::FUN_141768770(SkillData* pData)
{
    if (pData == 0)
        return 0;
    unsigned nMax = pData->GetRechargeMaxCount();
    if (nMax == 0)
        return 0;
    unsigned nUsed = FUN_141768680(pData);
    if (nUsed < nMax)
        return nMax - nUsed;
    return 0;
}

// @0x1417687e0
void CSkillSystem::FUN_1417687e0(Unk_SkillCooltime* pCool)
{
    if (pCool->m_bCombo == 0)
    {
        unsigned nSkillId = FUN_1417692f0((unsigned)pCool->m_nKey);
        int nUses = FUN_141768610(nSkillId);
        if (nUses != 0)
        {
            nUses = nUses - 1;
            FUN_141768530(nSkillId, nUses, 0);
            if (nUses != 0)
            {
                MS2Ptr<SkillLevelData> spLevel = reinterpret_cast<Unk_SsPc*>(m_pOwner)->FUN_1416546d0()->vfunc_1(nSkillId);
                if (spLevel.get() != 0)
                    FUN_1417664e0(FUN_141472bc0(), nSkillId, spLevel->FUN_140804660(), pCool->m_fCombo, 0);
            }
        }
    }
}

// @0x141768900
void CSkillSystem::FUN_141768900(MS2Ptr<CSkillRecord> spRecord)
{
    if (spRecord == 0)
        return;
    if (spRecord->m_spSkill == 0)
        return;
    if (spRecord->m_spSkill->GetRechargeMaxCount() == 0)
        return;
    int nUsed = FUN_141768680(spRecord->m_spSkill.get());
    nUsed++;
    FUN_1417685c0(spRecord->m_spSkill.get(), nUsed);
    FUN_141768d40(spRecord->m_spSkill);
    FUN_1419f37f0(5);
}

// @0x141768a50
void CSkillSystem::FUN_141768a50()
{
    POSITION pos = m_mapUses.GetStartPosition();
    while (pos != 0)
    {
        if (m_mapUses.GetValueAt(pos) != 0)
        {
            unsigned nRechargeId = m_mapUses.GetKeyAt(pos);
            float fCool = FUN_141765fe0(nRechargeId, 0);
            if (FUN_14028d470(fCool, 0))
            {
                MS2Ptr<SkillLevelData> spLevel = reinterpret_cast<Unk_SsPc*>(m_pOwner)->FUN_1416546d0()->vfunc_1(nRechargeId);
                if (spLevel.get() != 0)
                    FUN_1417664e0(FUN_141472bc0(), nRechargeId, spLevel->FUN_140804660(), 0.1f, 0);
            }
        }
        m_mapUses.GetNext(pos);
    }
}

// @0x141768bd0
int CSkillSystem::FUN_141768bd0(MS2Ptr<CSkillRecord> spRecord)
{
    if (spRecord->m_spSkill->GetRechargeMaxCount() == 0)
        return 0;
    if (FUN_141768770(spRecord->m_spSkill.get()) == 0)
        return 0;
    unsigned nNow = FUN_141472bc0();
    int nLast = FUN_141768dd0(spRecord->m_spSkill);
    int nGap = FUN_14028d260(spRecord->m_spSkill->m_condition.m_fDefaultRechargingCooldownTime);
    if (nNow < (unsigned)(nLast + nGap))
        return 0;
    return 1;
}

// @0x141768d40
void CSkillSystem::FUN_141768d40(MS2Ptr<SkillData> spSkill)
{
    if (spSkill == 0)
        return;
    unsigned nNow = FUN_141472bc0();
    m_mapRechargeTick.SetAt(spSkill->GetRechargeId(), nNow);
}

// @0x141768dd0
int CSkillSystem::FUN_141768dd0(MS2Ptr<SkillData> spSkill)
{
    int nLast;
    if (!(spSkill == 0))
    {
        unsigned nValue = 0;
        m_mapRechargeTick.Lookup(spSkill->GetRechargeId(), nValue);
        nLast = nValue;
    }
    else
        nLast = 0;
    return nLast;
}

// @0x141768e70
void CSkillSystem::FUN_141768e70(int nId, unsigned short nLevel, __int64 nExpire, __int64 n30, bool bPermanent, bool bFavorite, int bNew)
{
    if (FUN_141768fb0(nId, nLevel) == 0)
    {
        MS2Ptr<stEmotion> spEmotion(new stEmotion);
        spEmotion->m_id = nId;
        spEmotion->m_level = nLevel;
        spEmotion->m_nExpire = nExpire;
        spEmotion->m_n30 = n30;
        spEmotion->m_bPermanent = bPermanent;
        spEmotion->m_bFavorite = bFavorite;
        spEmotion->m_isNew = bNew;
        m_vEmotions.push_back(spEmotion);
    }
}

// @0x141768fb0
int CSkillSystem::FUN_141768fb0(unsigned int nSkillId, unsigned short nLevel)
{
    if (!FUN_1403ed2d0()->FUN_141bcb150() || (nSkillId != 0x5607ed1 && nSkillId != 0x5607ed2))
    {
        MS2Ptr<Unk_HsInfo> spInfo = m_pOwner->FUN_141664200();
        if (spInfo.get() != 0)
        {
            if (spInfo->FUN_14050a4d0() && (nSkillId == 0x5607ed1 || nSkillId == 0x5607ed2))
                return 1;
        }
        unsigned __int64 nNow = FUN_140869440();
        for (size_t i = 0; i < m_vEmotions.size(); i = i + 1)
        {
            int nId = m_vEmotions[i]->m_id;
            short sLevel = m_vEmotions[i]->m_level;
            if (m_vEmotions[i]->FUN_1417643d0((const __int64*)&nNow) && nId == (int)nSkillId && sLevel == (short)nLevel)
                return 1;
        }
        return 0;
    }
    return 1;
}

// @0x1417691a0
void CSkillSystem::FUN_1417691a0(ATL::CAtlArray<MS2Ptr<stEmotion> >& arrOut)
{
    unsigned __int64 nNow = FUN_140869440();
    for (size_t i = 0; i < m_vEmotions.size(); i = i + 1)
    {
        if (m_vEmotions[i]->FUN_1417643d0((const __int64*)&nNow))
            arrOut.Add(m_vEmotions[i]);
    }
}

// @0x141769250
void CSkillSystem::FUN_141769250()
{
    m_vEmotions.clear();
}

// @0x141769280
void CSkillSystem::FUN_141769280()
{
    for (size_t i = 0; i < m_vEmotions.size(); i = i + 1)
        m_vEmotions[i]->m_isNew = 0;
}

// @0x1417692f0
unsigned FUN_1417692f0(unsigned n)
{
    return n;
}

// @0x141769320
int FUN_141769320(Unk_SsItemPtr kPtr)
{
    if (kPtr.FUN_1401b52a0()->FUN_14053cc80())
        return FUN_1401d3200()->m_nSkillItemA;
    else if (kPtr.FUN_1401b52a0()->FUN_14053cc40())
        return FUN_1401d3200()->m_nSkillItemC;
    else if (kPtr.FUN_1401b52a0()->FUN_14053c5c0() == 5)
        return FUN_1401d3200()->m_nSkillItemB;
    else
        return kPtr.FUN_1401b52a0()->FUN_14053dc20();
}

// @0x141769410
int CSkillSystem::FUN_141769410(SkillData* pData)
{
    if (pData == 0)
        return 0;
    return pData->m_nJump;
}

extern Unk_StreamPoint DAT_143b01a60;                     // the zero point
__int64 FUN_14028d0e0();                                  // the next cast id

// @0x141763fa0
Unk_InventorySkillRequest::Unk_InventorySkillRequest(int nSkillId, unsigned short nLevel)
    : m_nSkillId(nSkillId), m_nLevel(nLevel), m_nCastId(FUN_14028d0e0()), m_nTick(FUN_141472bc0()), m_nMotion(0),
      m_ptPos(*(const Unk_IsrPoint*)&DAT_143b01a60), m_ptDir(*(const Unk_IsrPoint*)&DAT_143b01a60)
{
    m_fRotZ = 0;
    m_n34 = 0;
    m_b38 = true;
    m_b39 = false;
    m_b3a = false;
    m_n40 = 0;
}

// @0x141769440
void CSkillSystem::FUN_141769440(int nError)
{
    switch (nError)
    {
    case 2:
        FUN_141275260(0x55, 1, 0);
        break;
    case 3:
        FUN_141275260(0x53, 1, 0);
        break;
    case 4:
        FUN_141275260(0x34, 1, 0);
        break;
    case 5:
        FUN_141275260(0x30, 1, 0);
        break;
    case 6:
        FUN_141275260(0x47, 1, 0);
        FUN_141276180(DAT_143aea1c0, CString(""));
        break;
    case 7:
        FUN_141275260(0x48, 1, 0);
        FUN_141276180(DAT_143aea1c8, CString(""));
        break;
    case 8:
        FUN_141275260(0x529, 1, 0);
        break;
    case 9:
        FUN_141275260(0x52a, 1, 0);
        break;
    case 10:
        FUN_141275260(0x52b, 1, 0);
        break;
    case 11:
        FUN_141275260(0x30, 1, 0);
        break;
    case 14:
        FUN_141275260(0x59, 1, 0);
        break;
    case 15:
        FUN_141275260(0x53, 1, 0);
        FUN_141276180(DAT_143aea1d0, CString(""));
        break;
    case 16:
        FUN_141275260(0x53, 1, 0);
        FUN_141276180(DAT_143aea1d0, CString(""));
        break;
    case 17:
        FUN_1412751f0(FUN_1409eec40(0x5f), 1, 0);
        FUN_141276180(DAT_143aea1d0, CString(""));
        break;
    case 18:
        FUN_141275260(0x528, 1, 0);
        break;
    case 19:
        FUN_1412751f0(FUN_1409eec40(0x61), 1, 0);
        FUN_141276180(DAT_143aea1d0, CString(""));
        break;
    case 20:
        FUN_141275260(0x57, 1, 0);
        break;
    case 21:
        FUN_141275260(0x56, 1, 0);
        break;
    case 22:
        FUN_141275260(0x53, 1, 0);
        break;
    case 23:
        FUN_141275260(0x53, 1, 0);
        FUN_141276180(DAT_143aea1d0, CString(""));
        break;
    case 24:
        FUN_141275260(0x59, 1, 0);
        break;
    case 25:
        FUN_141275260(0x59, 1, 0);
        break;
    case 26:
        FUN_141275260(0x59, 1, 0);
        break;
    case 27:
        FUN_141275260(0x53, 1, 0);
        FUN_141276180(DAT_143aea1d0, CString(""));
        break;
    case 28:
        FUN_141275260(0x45d, 1, 0);
        FUN_141276180(DAT_143aea1d8, CString(""));
        break;
    case 29:
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_err_cannot_use_here_pet_trap")), 1, 0);
        FUN_141276180(DAT_143aea1d0, CString(""));
        break;
    case 30:
        FUN_141275260(0x59, 1, 0);
        FUN_141276180(DAT_143aea1e0, CString(""));
        break;
    case 31:
        FUN_141275260(0x59, 1, 0);
        FUN_141276180(DAT_143aea1e0, CString(""));
        break;
    case 32:
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_err_not_allow_pvpField")), 1, 0);
        FUN_141276180(DAT_143aea1d0, CString(""));
        break;
    }
}

// @0x141769b70
int CSkillSystem::FUN_141769b70(MS2Ptr<SkillLevelData> spLevel, Unk_InventorySkillRequest* pReq)
{
    if ((unsigned)(unsigned char)pReq->m_b38 != spLevel->FUN_140804450())
        return 1;
    Unk_SsPc* pOwner = reinterpret_cast<Unk_SsPc*>(m_pOwner);
    if (!spLevel->FUN_140804450())
    {
        static float s_fCastReuse = FUN_1401d3200()->m_kCastReuse.FUN_1402bac70();
        double dLimit = (double)(m_fLastCastTime + s_fCastReuse);
        double dNow = FUN_14086d260()->FUN_141473280();
        if (dNow <= dLimit)
        {
            if (FUN_1401d3200()->m_kCastRepeat.FUN_14025a620() == 0)
                return 1;
            if (m_nLastCastSkill == (int)spLevel->FUN_140803dc0())
                return 1;
        }
    }
    else
    {
        Unk_SsBody* pBody = reinterpret_cast<Unk_SsBody*>(m_pOwner->FUN_14166d220());
        Ridee* spRidee = m_pOwner->FUN_1416764a0();
        if (spRidee != 0)
        {
            Unk_SsBody* pRideeBody = reinterpret_cast<Unk_SsBody*>(spRidee->FUN_14166d220());
            if (pRideeBody != 0)
                pBody = pRideeBody;
        }
        int nFlag = 0;
        if (pBody != 0)
        {
            if (pBody->FUN_141240780() == 0 || pBody->FUN_1412407a0() == 0)
                nFlag = 0;
            else
                nFlag = 1;
            static int s_nFlyCast = FUN_1401d3200()->m_kFlyCast.FUN_14025a620();
            if (s_nFlyCast != 0)
                nFlag = pBody->FUN_141240780();
        }
        if (nFlag == 0 && m_pOwner->vfunc_99(0) != 0)
        {
            int nMainType = spLevel->FUN_140803e10()->FUN_1407e9bd0();
            if (nMainType != 0x1e)
            {
                nMainType = spLevel->FUN_140803e10()->FUN_1407e9bd0();
                if (nMainType != 0x1d)
                {
                    nMainType = spLevel->FUN_140803e10()->FUN_1407e9bd0();
                    if (nMainType != 0x20)
                        return 1;
                }
            }
        }
    }
    if (spLevel->FUN_140803e10()->GetMainType() == 5)
    {
        if (FUN_1403ed2d0()->FUN_141bdb660(4) != 0)
            return 0x12;
    }
    if (spLevel->FUN_140803e10()->FUN_1407e9d70())
    {
        if (pReq->m_n34 != 0)
        {
            int nItemId = FUN_1409331f0()->FUN_14142dfb0(pReq->m_n34);
            if (DAT_143ab2a90.FUN_140a5ece0(nItemId, 1) == 0)
                return 1;
        }
        std::vector<MS2Ptr<SkillActionAdditional> >& vAdd = spLevel->m_vAdditional;
        for (std::vector<MS2Ptr<SkillActionAdditional> >::iterator it = vAdd.begin(); it != vAdd.end(); ++it)
        {
            MS2Ptr<Unk_SsEffectData> spEffect = FUN_140aafef0(FUN_1401958b0(), (*it)->m_nAdditionalID, (*it)->m_nLevel);
            if (!spEffect.IsNull())
            {
                Unk_SsEffectData* pEffect = spEffect.operator->();
                if (pEffect->m_p270 == 0 && pEffect->m_f288 == 0.0f)
                {
                    if (pEffect->m_p278 == 0 && pEffect->m_f28c == 0.0f)
                    {
                        if (pEffect->m_p280 != 0 || pEffect->m_f290 != 0.0f)
                        {
                            if (pOwner->FUN_141670a30(10) <= pOwner->FUN_141670a00(10))
                                return 10;
                        }
                    }
                    else
                    {
                        if (pOwner->FUN_141670a30(7) <= pOwner->FUN_141670a00(7))
                            return 9;
                    }
                }
                else
                {
                    if (pOwner->FUN_141670a30(4) <= pOwner->FUN_141670a00(4))
                        return 8;
                }
            }
        }
    }
    int nWhy = FUN_14176a380(spLevel, pReq);
    if (nWhy == 0)
        return 0;
    return nWhy;
}

// @0x14176a380
int CSkillSystem::FUN_14176a380(MS2Ptr<SkillLevelData> spLevel, Unk_InventorySkillRequest* pReq)
{
    int nBase = FUN_141764be0(spLevel->FUN_140803dc0());
    if (nBase != 0)
    {
        if (nBase != (int)spLevel->FUN_140803dc0())
        {
            MS2Ptr<SkillLevelData> spBase = reinterpret_cast<Unk_SsPc*>(m_pOwner)->FUN_1416546d0()->vfunc_1(nBase);
            if (spBase.get() != 0)
                spLevel = spBase;
        }
    }
    int nWhy = FUN_14176a8c0(spLevel->FUN_140803e10(), pReq);
    if (nWhy == 0)
    {
        nWhy = FUN_14176a530(spLevel);
        if (nWhy == 0)
            nWhy = 0;
    }
    return nWhy;
}

// @0x14176a530
int CSkillSystem::FUN_14176a530(MS2Ptr<SkillLevelData> spLevel)
{
    if (spLevel->m_nEp != 0)
    {
        MS2Ptr<Unk_SsMapInfo> spMap = FUN_1403ed2d0()->FUN_141bd30a0();
        int nBlock = spMap->m_nBlock;
        if (nBlock == 0)
            return 3;
    }
    if (DAT_143ab2898 < spLevel->m_nMeso)
        return 4;
    Unk_SsPc* pOwner = reinterpret_cast<Unk_SsPc*>(m_pOwner);
    if (0 < spLevel->m_nSp)
    {
        int nSp = spLevel->m_nSp;
        __int64 nCost = FUN_14176b960(spLevel->FUN_140803dc0(), nSp);
        if (pOwner->FUN_141670a00(7) < nCost)
            return 6;
    }
    if (0 < spLevel->m_nEp)
    {
        if (pOwner->FUN_141670a00(10) < spLevel->m_nEp)
            return 7;
    }
    float fCool = FUN_141765fe0(spLevel->FUN_140803dc0(), 0);
    int nRecharge = spLevel->FUN_140803e10()->GetRechargeMaxCount();
    if (nRecharge != 0 || fCool <= 0.0f)
    {
        if (nRecharge == 0)
            return 0;
        if (FUN_141768770(spLevel->FUN_140803e10()) != 0)
            return 0;
    }
    if (spLevel->FUN_140803e10()->m_condition.m_nUseCoolDownShowUI != 0)
    {
        fCool = FUN_141765fe0(spLevel->FUN_140803dc0(), 1);
        if (0.0f < fCool)
            return 2;
        return 0x22;
    }
    if (m_nCastAllowed == 0)
        return 0x23;
    return 0;
}

// @0x14176a8c0
int CSkillSystem::FUN_14176a8c0(SkillData* pData, Unk_InventorySkillRequest* pReq)
{
    Unk_SsPc* pOwner = reinterpret_cast<Unk_SsPc*>(m_pOwner);
    MS2Ptr<Unk_SsMapInfo> spMap = FUN_1403ed2d0()->FUN_141bd30a0();
    if (spMap.IsNull())
        return 0xd;
    SkillCondition& rCond = pData->m_condition;
    if (pData->FUN_1407e9bd0() == 0x1e)
    {
        int nGlideId = 0;
        if (pReq->m_n40 != 0)
        {
            MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(pReq->m_n40);
            if (spItem.get() != 0)
                nGlideId = spItem->FUN_140527840()->FUN_14053dde0();
        }
        MS2Ptr<SkillGlideData> spGlide = FUN_1401958b0()->GetGlideData(nGlideId);
        if (spGlide == 0)
            return 0xd;
        if (spGlide->m_bOnGroundDisable)
        {
            int bBlocked = 0;
            if (pOwner->FUN_141671a30() != 0)
                bBlocked = 1;
            NiPoint3 kPos = pOwner->vfunc_18();
            float fDist = 0.0f;
            if (FUN_1409f7ca0()->FUN_14168a450(&kPos, &fDist, 200.0f) != 0 && fDist < 100.0f)
                bBlocked = 1;
            if (bBlocked != 0)
                return 0xe;
        }
        if (DAT_143ab2914 < 0x32 || nGlideId != FUN_1401d3200()->m_nGlideSkill)
        {
            if (spMap->FUN_140375780() == 3)
            {
                if (FUN_1403ed2d0()->FUN_141bdb660(6) != 0)
                    return 0xf;
            }
            if (spMap->m_nFlyable == 0)
                return 0xf;
        }
    }
    else
    {
        if (pData->FUN_1407e9bd0() == 0x1d)
        {
            if (spMap->m_nGlideable == 0)
                return 0x10;
            if (FUN_1403ed2d0()->FUN_141bdb660(1) != 0)
                return 0x11;
        }
    }
    if (pData->FUN_1407e9f30())
    {
        if (FUN_1403ed2d0()->FUN_141bdb660(2) != 0)
            return 0x13;
    }
    ATL::CAtlArray<unsigned>& rRequire = rCond.m_arrRequireEffect;
    if (!rRequire.IsEmpty())
    {
        for (unsigned i = 0; i < rRequire.GetCount(); i = i + 1)
        {
            unsigned* pId = &rRequire[i];
            if (reinterpret_cast<Unk_SsBuffs*>(m_pOwner->FUN_1416749a0())->FUN_140971260(*pId) == 0)
                return 0x14;
        }
    }
    if (rCond.m_nOnlyShadowWorld != 0)
    {
        MS2Ptr<Unk_SsMapInfo> spShadow = FUN_1403ed2d0()->FUN_141bd30a0();
        bool bNotShadow = spShadow->FUN_1403754f0() == 0;
        if (bNotShadow)
            return 0x15;
    }
    if (rCond.m_nOnlyFlyableMap != 0)
    {
        MS2Ptr<Unk_SsMapInfo> spFly = FUN_1403ed2d0()->FUN_141bd30a0();
        bool bNotFly = spFly->m_nFlyable == 0;
        if (bNotFly)
            return 0x16;
    }
    if (!rCond.m_arrRequireMapCodes.IsEmpty())
    {
        int nMapId = FUN_1403ed2d0()->FUN_141bd3060();
        int bFound = 0;
        for (unsigned i = 0; i < rCond.m_arrRequireMapCodes.GetCount(); i = i + 1)
        {
            int nCode = rCond.m_arrRequireMapCodes[i];
            if (nCode != 0 && nMapId == nCode)
            {
                bFound = 1;
                break;
            }
        }
        if (bFound == 0)
            return 0x17;
    }
    if (!rCond.m_arrHasNotAdditionalEffectGroup.IsEmpty())
    {
        for (unsigned i = 0; i < rCond.m_arrHasNotAdditionalEffectGroup.GetCount(); i = i + 1)
        {
            int nGroup = rCond.m_arrHasNotAdditionalEffectGroup[i];
            if (reinterpret_cast<Unk_SsBuffs*>(m_pOwner->FUN_1416749a0())->FUN_1409702d0(nGroup) != 0)
                return 0x18;
        }
    }
    if (m_pOwner->FUN_141676500() == 0 || rCond.m_nAllowBattleRidingState != 0)
    {
        if (m_pOwner->FUN_141676500() == 0 && rCond.m_nOnlyBattleRidingState != 0)
            return 0x1a;
        if (pOwner->FUN_141670a00(4) < 1)
            return 5;
        __int64 nSp = rCond.m_nSp;
        __int64 nHaveSp = pOwner->FUN_141670a00(7);
        nSp = FUN_14176b960(pData->GetId(), nSp);
        if (1 <= nSp && nSp > nHaveSp)
            return 0xb;
        unsigned short nGrade = m_pOwner->FUN_14152fce0(pData->GetId());
        if (nGrade != 0)
        {
            if (CFieldData::FUN_1403744a0(FUN_1403ed2d0()->FUN_141bd3060()))
                return 0x1b;
        }
        ATL::CAtlArray<Unk_SkillWeapon>& rWeapons = rCond.m_arrWeapon;
        if (!rWeapons.IsEmpty())
        {
            int bMatch = 0;
            int bBlocked = 0;
            MS2Ptr<Unk_SsHeldWeapon> spHeld = pOwner->FUN_14165c520();
            for (unsigned i = 0; i < rWeapons.GetCount(); i = i + 1)
            {
                Unk_SkillWeapon* pWeapon = &rWeapons[i];
                if (spHeld.get() != 0
                    && (spHeld->m_nRight == pWeapon->m_nRightHand || pWeapon->m_nRightHand == 0)
                    && (spHeld->m_nLeft == pWeapon->m_nLeftHand || pWeapon->m_nLeftHand == 0))
                {
                    if (pWeapon->m_nRightHand != 0)
                    {
                        if (reinterpret_cast<Unk_SsBuffs*>(m_pOwner->FUN_1416749a0())->FUN_1409703d0(5))
                        {
                            bBlocked = 1;
                            continue;
                        }
                    }
                    if (pWeapon->m_nLeftHand != 0)
                    {
                        if (reinterpret_cast<Unk_SsBuffs*>(m_pOwner->FUN_1416749a0())->FUN_1409703d0(4))
                        {
                            bBlocked = 1;
                            continue;
                        }
                    }
                    bMatch = 1;
                    break;
                }
            }
            if (bMatch == 0)
                return 0x1c;
        }
        if (pData->GetMainType() == 0x11)
        {
            int nObjectId = static_cast<GameObject*>(m_pOwner)->FUN_14123c580();
            NiPoint3 kPos = pOwner->vfunc_18();
            if (FUN_1403ed2d0()->FUN_141bd2bf0(kPos, nObjectId) != 0)
                return 0x1d;
        }
        unsigned nMask = m_pOwner->FUN_141678680();
        if (nMask != 0)
        {
            int nType = pData->GetMainType();
            if ((nMask & (1 << ((unsigned char)nType & 0x1f))) != 0)
                return 0x1e;
        }
        if (reinterpret_cast<Unk_SsBuffs*>(m_pOwner->FUN_1416749a0())->FUN_140970a60(pData->GetId()) == 0)
        {
            MS2Ptr<Unk_SsLearned> spLearned = pOwner->FUN_1416546d0()->FUN_1406394d0(pReq->m_nSkillId);
            if (spLearned.get() != 0)
            {
                if (spLearned->FUN_140637e00() == 2 && DAT_143ab287c == 7)
                    return 0x20;
            }
            if (pData->GetMainType() == 4)
            {
                if (pOwner->FUN_14165f150() == 0)
                    return 0x21;
                CItem* pHeld = reinterpret_cast<CItem*>(pOwner->FUN_14165f100());
                if (pHeld == 0)
                    return 0x21;
                int nHeldSkill = pHeld->FUN_140527840()->FUN_14053dc90();
                if (nHeldSkill != (int)pData->GetId())
                    return 0x21;
            }
            if (m_pOwner->FUN_14166ce30() == 0)
                return 0;
            return 0xc;
        }
        return 0x1f;
    }
    return 0x19;
}

// @0x14176b7c0
MS2Ptr<SkillLevelData> CSkillSystem::FUN_14176b7c0(int nSkillId, unsigned short nLevel)
{
    MS2Ptr<SkillData> spSkill = FUN_1401958b0()->GetSkillData(nSkillId);
    if (spSkill == 0)
        return MS2Ptr<SkillLevelData>(0);
    MS2Ptr<SkillLevelData> spLevel(0);
    for (short n = nLevel; n != 0; n = n - 1)
    {
        spLevel = spSkill->FUN_1407e90a0(n);
        if (spLevel.get() != 0)
            return spLevel;
    }
    return MS2Ptr<SkillLevelData>(0);
}

// @0x14176b960
__int64 CSkillSystem::FUN_14176b960(int nSkillId, __int64 nBase)
{
    __int64 nRet;
    if (m_pOwner == 0)
        nRet = 0;
    else
    {
        float fA = reinterpret_cast<Unk_SsBuffs*>(m_pOwner->FUN_1416749a0())->FUN_140970fd0();
        Unk_SsPc* pOwner = reinterpret_cast<Unk_SsPc*>(m_pOwner);
        float fB = pOwner->FUN_1416628b0(0x3eb, nSkillId);
        fB = fA * -1.0f + fB;
        float fC = pOwner->FUN_1416628f0(0x3eb, nSkillId);
        if ((__int64)((float)(nBase - (__int64)fC) - (float)nBase * fB) < 0)
            nRet = 0;
        else
            nRet = (__int64)((float)(nBase - (__int64)fC) - (float)nBase * fB);
    }
    return nRet;
}

// @0x14176ba90
MS2Ptr<CSkillSystem::stEmotion> CSkillSystem::FUN_14176ba90(int nId)
{
    for (MS2Ptr<stEmotion>* it = m_vEmotions._Unchecked_begin(); ; ++it)
    {
        if (it == m_vEmotions._Unchecked_end())
            return MS2Ptr<stEmotion>(nullptr);
        if ((*it)->m_id == nId)
            return *it;
    }
}

// @0x14176cc40
CSEReduceSkillGroupCooltimeCtx::CSEReduceSkillGroupCooltimeCtx()
{
    m_fReduceRate = 0.0f;
    m_nGroupId = 0;
    m_nKind = 4;
}

// @0x14176cdb0
CSEReduceSkillGroupCooltimeCtx::~CSEReduceSkillGroupCooltimeCtx()
{
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb68d0-0x142cb6d70 .text$yd
