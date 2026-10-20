// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Quest event dispatcher and the quest guide HUD.
// MS2-UNIT: ?\uiquesteventlistener.cpp
// MS2-RANGE: 0x141aa86e0-0x141ab20e0 .text$mn
// MS2-RANGE: 0x14011b480-0x14011b620 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0VUIQuestGuideDialog@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@QEAA@AEBQEAVUIQuestGuideDialog@@AEBQ81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@Z 0x141aaf650 ; unique
// MS2-PIN: ??$?8PEAVUIQuestGuideDialog@@P80@EAAXAEAVCInPacket@@@Z@std@@YA_NAEBU?$pair@PEAVUIQuestGuideDialog@@P81@EAAXAEAVCInPacket@@@Z@0@0@Z 0x141aaf7b0 ; prop
// MS2-PIN: ??$?8PEAVUIQuestGuideDialog@@P80@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@YA_NAEBU?$pair@PEAVUIQuestGuideDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@0@0@Z 0x141aaf820 ; prop
// MS2-PIN: ??$?8PEAVUIQuestGuideDialog@@P80@EAAXPEAVNotifyObject@@@Z@std@@YA_NAEBU?$pair@PEAVUIQuestGuideDialog@@P81@EAAXPEAVNotifyObject@@@Z@0@0@Z 0x141aaf890 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIQuestGuideDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@QEAA@AEBV01@@Z 0x141ab1470 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIQuestGuideDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@QEAA@AEBV01@@Z 0x141ab15b0 ; prop
// MS2-PIN: ?vfunc_48@UIQuestGuideDialog@@UEAAHXZ 0x141ab1a20 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIQuestGuideDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x141ab1b80 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIQuestGuideDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x141ab1be0 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIQuestGuideDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x141ab1c40 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIQuestGuideDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEAAXAEAVCInPacket@@@Z 0x141ab1d50 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIQuestGuideDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x141ab1d80 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIQuestGuideDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAXPEAVNotifyObject@@@Z 0x141ab1db0 ; unique
// MS2-PIN: ??$Call@VUIQuestGuideDialog@@P81@EAAXAEAVCInPacket@@@Z@?$DelegateImpl@U?$pair@PEAVUIQuestGuideDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@CAXAEAU?$pair@PEAVUIQuestGuideDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@AEAVCInPacket@@@Z 0x141ab1de0 ; prop
// MS2-PIN: ??$Call@VUIQuestGuideDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@?$DelegateImpl@U?$pair@PEAVUIQuestGuideDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@CAXAEAU?$pair@PEAVUIQuestGuideDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@AEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x141ab1e20 ; prop
// MS2-PIN: ??$Call@VUIQuestGuideDialog@@P81@EAAXPEAVNotifyObject@@@Z@?$DelegateImpl@U?$pair@PEAVUIQuestGuideDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@CAXAEAU?$pair@PEAVUIQuestGuideDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@PEAVNotifyObject@@@Z 0x141ab1e60 ; prop
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIQuestGuideDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x141ab1ea0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIQuestGuideDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x141ab1f00 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIQuestGuideDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x141ab1f60 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiquesteventlistener.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uiquesteventlistener.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/questdata.h"
#include "ms2/placeholder/cconditioncommon.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/client/ms2/questmanager_1.h"
#include "ms2/client/ms2/questmanager_2.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

#include <algorithm>
#include <vector>

// Out-of-line instantiations (questmanager_2.cpp pattern): the exe calls these rather than inlining them.
template<> Unk_PayloadPtr<CQuest>::~Unk_PayloadPtr();
template<> CQuest* Unk_PayloadPtr<CQuest>::get() const;
template<> CQuest* Unk_PayloadPtr<CQuest>::operator->() const;
template<> Unk_PayloadPtr<CQuest>::Unk_PayloadPtr(const Unk_PayloadPtr&);
template<> CStringA StringFormat<int, unsigned int>(const char* format, const int& v0, const unsigned int& v1);   // 0x141aaf900 below

namespace UICommon {
class CAlignmentInfo : public CPtred {
public:
    CAlignmentInfo(int alignment, float x, float y);
    void FUN_14015b020();
    int FUN_140159bc0();
    void FUN_140159ba0();
    void FUN_1419015e0(void* pCfg);                                         // save
    bool FUN_141901660(void* pCfg);                                         // load
    void FUN_141901880(MS2Ptr<AScript> root, float w, float h, float x, float y);
    void FUN_141901c10(MS2Ptr<AScript> root, int w, int h);                 // apply
    void FUN_141901cd0();                                                   // reset
private:
    float m_x; float m_y; int m_align; float m_defaultX; float m_defaultY; int m_defaultAlign;
};
MS2_CHECK_SIZE(CAlignmentInfo, 0x30);
}

class ASDialog : public ASDisplayObject {
public:
    int FUN_1422c1500();                                                    // x
    int FUN_1422c1530();                                                    // y
};

// An AS function object calling back into C++ (ctor 0x1422c8430, dtor 0x1422c85b0).
class ASFunction : public AScript {
public:
    ASFunction(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, int nUser, int nMovieId);
    ~ASFunction();
private:
    void* m_40;
};
int FUN_1422db730();

class Unk_QgNotices {
public:
    void FUN_140da4e40(CStringW strName, Delegate<void(NotifyObject*)> handler);
    void FUN_140da4eb0(CStringW strName, Delegate<void(NotifyObject*)> handler);
};
Unk_QgNotices* FUN_140939a10();
class Unk_QgPackets {
public:
    void FUN_140da5180(int nOp, Delegate<void(CInPacket&)> handler);
    void FUN_140da51e0(int nOp, Delegate<void(CInPacket&)> handler);
};
Unk_QgPackets* FUN_140bccd50();

UIQuestEventDispatcher* FUN_140bfc4b0();
CQuestManager* FUN_140764020();
void FUN_1416cb8b0(CQuestManager* pMgr, ATL::CAtlArray<Unk_PayloadPtr<CQuest>>& out, int nState, int nType, int nChapter);
void FUN_1416cbb20(CQuestManager* pMgr, std::vector<Unk_PayloadPtr<CQuest>>& out, int nState, int nType, int nChapter);
void FUN_1416cf510(CQuestManager* pMgr, int nQuestId);                  // move to the field
void FUN_1416cf630(CQuestManager* pMgr, int nQuestId);                  // move to the dungeon
void FUN_1416cf750(CQuestManager* pMgr, int nQuestId);                  // re-entry
void FUN_1416cf870(CQuestManager* pMgr, int nQuestId);                  // dispatch
void FUN_1416cf980(CQuestManager* pMgr, int nQuestId, int bCancel);     // party find
int FUN_1416d2600(CQuestManager* pMgr, int nQuestId, int n);

struct Unk_QgCfgInt { int* FUN_1402056b0(); void* m_unknown; };
struct Unk_QgCfg {
    char m_pad_0[0x4078];
    Unk_QgCfgInt m_4078;                                                    // max tracked quests
    char m_pad_4088[0x40d0 - 0x4088];
    Unk_QgCfgInt m_40d0;                                                    // max tracked quests (second)
};
Unk_QgCfg* FUN_1401d3200();

// The map data kept behind the world service's counted pointer.
struct Unk_McMapData
{
    char m_pad_00[0x154];
    float m_fRotation;                                                      // +0x154 degrees around z
};
MS2_CHECK_OFFSET(Unk_McMapData, m_fRotation, 0x154);
class Unk_McMapPtr
{
public:
    ~Unk_McMapPtr();                                                        // 0x1408850f0
    bool FUN_1408851f0() const;                                             // is null
    Unk_McMapData* FUN_140885340() const;                                   // operator->
private:
    void* m_pad_00;
    Unk_McMapData* m_p;
};
class Unk_QgWorld { public: int FUN_141bd3060(); Unk_McMapPtr FUN_141bd30a0(); };
Unk_QgWorld* FUN_1403ed2d0();
PCBase* FUN_141bd0cc0(Unk_QgWorld* pWorld);                                 // the local player

namespace QuestNavigation {
struct TraceResult {
    TraceResult();                                                          // 0x140c90420
    ~TraceResult();                                                         // 0x140c90580
    char m_pad_00[0x18];
    int m_questId;                                                          // +0x18
    char m_pad_1c[0x18];
    float m_fRotation;                                                      // +0x34
    CStringW m_strDistance;                                                 // +0x38
};
MS2_CHECK_SIZE(TraceResult, 0x40);
}
class Unk_QgNavi {
public:
    int FUN_140c9a490(int nQuestId);                                        // the traced quest
    void FUN_140c9a420(int nQuestId);                                       // trace (0 = stop)
    int FUN_140c9a4c0(QuestNavigation::TraceResult& result);
};
Unk_QgNavi* FUN_140e7c990();

class Unk_RewardEntry {
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual CStringW vfunc_4();                                             // the goal text
};
class Unk_RewardEntryPtr {
public:
    Unk_RewardEntryPtr(const Unk_RewardEntryPtr&); ~Unk_RewardEntryPtr(); bool operator==(Unk_RewardEntry*) const; Unk_RewardEntry* operator->() const;
private:
    void* m_0; Unk_RewardEntry* m_p;
};
class Unk_RewardEntryList {
public:
    Unk_RewardEntryList(); ~Unk_RewardEntryList(); size_t FUN_140c9f760(); Unk_RewardEntryPtr& FUN_140c9eb50(size_t);
    Unk_RewardEntryPtr*& FUN_140c9f080(); Unk_RewardEntryPtr*& FUN_140c9f0c0();    // _Myfirst / _Mylast
    bool FUN_141ab1ca0();                                                   // empty (COMDAT below)
private:
    void* m_0; void* m_8; void* m_10;
};
class Unk_BattleRoom {
public:
    int FUN_14031ddd0();                                                    // dungeon id
    char m_pad_00[0x1c];
    int m_1c;
};
class Unk_BattleRoomPtr {
public:
    ~Unk_BattleRoomPtr(); bool operator==(Unk_BattleRoom*) const; Unk_BattleRoom* operator->() const;
    bool FUN_140e36ca0() const;                                             // is null
private:
    void* pad; Unk_BattleRoom* p;
};
MS2_CHECK_SIZE(Unk_BattleRoomPtr, 16);
class Unk_BattleRoomMgr { public: Unk_BattleRoomPtr FUN_1403206b0(int); };
Unk_BattleRoomMgr* FUN_14031c2a0();
class Unk_RewardMission { public: void FUN_140c9ce80(Unk_RewardEntryList& out); Unk_BattleRoomPtr FUN_140c9d070(); };
class Unk_RewardMissionPtr {
public:
    ~Unk_RewardMissionPtr(); bool operator==(Unk_RewardMission*) const; Unk_RewardMission* get() const; Unk_RewardMission* operator->() const;
private:
    void* m_0; Unk_RewardMission* m_p;
};
class Unk_RewardMissions { public: Unk_RewardMissionPtr FUN_140d9f4e0(); };
Unk_RewardMissions* FUN_140931510();

class Unk_QgQuestTable {
public:
    void FUN_14074cbf0(int nMapId, ATL::CAtlArray<unsigned>& out);         // field mission quests of the map
    void FUN_14074cfd0(int nChapter, ATL::CAtlArray<unsigned>& out);       // quests of the chapter
};
Unk_QgQuestTable* FUN_1407476c0();
class Unk_QgFieldMeta {
public:
    void FUN_1406fb2a0(unsigned nNpcId, ATL::CAtlArray<unsigned>& out);    // fields the npc stands in
    int FUN_1406fc110(unsigned nMapId, unsigned* pnParent);
};
Unk_QgFieldMeta* FUN_140700390();
class Unk_QgFieldPick { public: int FUN_140c915a0(ATL::CAtlArray<unsigned>& fields); };
Unk_QgFieldPick* FUN_140c9b8e0();
class Unk_QgGuideText { public: void FUN_1416fb380(CStringW& str); };
Unk_QgGuideText* FUN_1403b4750();
class Unk_QgStrings { public: CStringW FUN_141811980(int nTable, int nId); };
Unk_QgStrings* FUN_1401a9d70();

class UIQuestDialog : public UIDialog { public: void FUN_141a9bff0(int nQuestId); };
UIQuestDialog* FUN_14131f1e0(int nUIType);                                  // GetDialog<UIQuestDialog>
class Unk_140961730 : public UIDialog { public: void FUN_141b5c230(); };
Unk_140961730* FUN_140961730(int nUIType);

__int64 FUN_141aa4980(CQuest* pQuest);                                      // when the quest becomes available
CStringW FUN_1416e5210(int nQuestId, CStringW strKey);
CStringW FUN_1416e57d0(int nQuestId, int nCondition);
CStringW FUN_1416e55b0(int nQuestId);
CStringW FUN_1416e7fb0(int nChapter);
CString FUN_140762e90(int nAlliance);
char FUN_1407640c0(CQuestData* pData);
char FUN_14074b090(CQuestData* pData);
int FUN_14074b050(CQuestData* pData);
int FUN_14074b790(int nQuestId);
MS2Ptr<CQuestData> FUN_14074bc40(int nQuestId);
CString FUN_141082090(int nQuestId, const CString& strEpic, const CString& strSatisfied, const CString& strRepeat, const CString& strEvent);
CStringW FUN_14028b8e0(const CStringW& strKey);
CStringW FUN_14028de60(int nId);
CStringW FUN_1409e8ca0(CStringW strKey, const int& a1, const int& a2, const int& a3, const int& a4, const int& a5);
CStringW FUN_140938ae0(CStringW strKey, const int& a1);
CStringW FUN_1409e9890(CStringW strKey, const int& a1, const int& a2);
CStringW FUN_1409e8820(CStringW strKey, const short& a1);
CStringW FUN_140656190(const wchar_t* szFormat, const CStringW& a1, const CStringW& a2);
void FUN_141275260(int nId, int a2, int a3);                                // system message
__int64 FUN_140869440();
void* FUN_1408e57f0();
int FUN_1422b9e00(void* p);
bool FUN_14036d570(void* pFeatures, int nFeature);
void* FUN_140166410();
int FUN_140408410(ATL::CAtlArray<unsigned>* pArr, const unsigned* pValue);      // index or -1
int FUN_1402178b0(int n);
void* FUN_1409670d0();
bool FUN_14162ac00(void* pParty, int nDungeonId);
bool FUN_1409c1720(const Scaleform::GFx::Value& v);
void FUN_1422bce40(Scaleform::GFx::Value* pOut, const AScript& a);
void FUN_1422bce70(Scaleform::GFx::Value* pOut, const char* sz);
void FUN_1407cd930(Scaleform::GFx::Value* pObj, const char* szName, const Scaleform::GFx::Value& v);
extern __int64 DAT_143ab2828;                                               // the character id

#ifndef MS2_HOOK_DLL
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyInputController;
#endif

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x141aa86e0
UIQuestEventListener::UIQuestEventListener()
{
}

// @0x141aa8700
UIQuestEventListener::~UIQuestEventListener()
{
}

// @0x141aa8720
UIQuestEventDispatcher::UIQuestEventDispatcher()
{
}

// @0x141aa8770
UIQuestEventDispatcher::~UIQuestEventDispatcher()
{
    m_listeners.RemoveAll();
}

// @0x141aa87c0
void UIQuestEventDispatcher::FUN_141aa87c0(UIQuestEventListener* pListener)
{
    for (size_t i = 0; i < m_listeners.GetCount(); ++i) {
        if (pListener == m_listeners[i])
            return;
    }
    m_listeners.Add(pListener);
}
MS2_REPLACE_METHOD(0x141aa87c0, UIQuestEventDispatcher, FUN_141aa87c0, 125, 0xFDBEF879);

// @0x141aa8850
void UIQuestEventDispatcher::FUN_141aa8850(UIQuestEventListener* pListener)
{
    for (size_t i = 0; i < m_listeners.GetCount(); ++i) {
        if (pListener == m_listeners[i]) {
            m_listeners.RemoveAt(i, 1);
            return;
        }
    }
}
MS2_REPLACE_METHOD(0x141aa8850, UIQuestEventDispatcher, FUN_141aa8850, 131, 0x160D2C39);

// @0x141aa88e0
void UIQuestEventDispatcher::vfunc_1(CQuest* pQuest)
{
    int nType = pQuest->GetQuestType();
    for (size_t i = 0; i < m_listeners.GetCount(); ++i) {
        UIQuestEventListener* pListener = m_listeners[i];
        if (pListener) {
            switch (nType) {
            case 4: pListener->vfunc_o178_9(pQuest); break;
            case 3: pListener->vfunc_o178_8(pQuest); break;
            case 5: pListener->vfunc_o178_10(pQuest); break;
            case 7: pListener->vfunc_o178_11(pQuest); break;
            case 10: pListener->vfunc_o178_12(pQuest); break;
            default: pListener->vfunc_o178_1(pQuest); break;
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141aa88e0, UIQuestEventDispatcher, vfunc_1, 319, 0xEBAC09FF);

// @0x141aa8a30
void UIQuestEventDispatcher::vfunc_2(CQuest* pQuest)
{
    for (size_t i = 0; i < m_listeners.GetCount(); ++i) {
        UIQuestEventListener* pListener = m_listeners[i];
        if (pListener) {
            switch (pQuest->GetQuestType()) {
            case 4: pListener->vfunc_o178_9(pQuest); break;
            case 3: pListener->vfunc_o178_8(pQuest); break;
            case 5: pListener->vfunc_o178_10(pQuest); break;
            case 7: pListener->vfunc_o178_11(pQuest); break;
            case 10: pListener->vfunc_o178_12(pQuest); break;
            default: pListener->vfunc_o178_2(pQuest); break;
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141aa8a30, UIQuestEventDispatcher, vfunc_2, 311, 0x3C616733);

// @0x141aa8b70
void UIQuestEventDispatcher::vfunc_3(CQuest* pQuest)
{
    for (size_t i = 0; i < m_listeners.GetCount(); ++i) {
        UIQuestEventListener* pListener = m_listeners[i];
        if (pListener) {
            switch (pQuest->GetQuestType()) {
            case 4: pListener->vfunc_o178_9(pQuest); break;
            case 3: pListener->vfunc_o178_8(pQuest); break;
            case 5: pListener->vfunc_o178_10(pQuest); break;
            case 7: pListener->vfunc_o178_11(pQuest); break;
            case 10: pListener->vfunc_o178_12(pQuest); break;
            default: pListener->vfunc_o178_3(pQuest); break;
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141aa8b70, UIQuestEventDispatcher, vfunc_3, 311, 0xB811CBD9);

// @0x141aa8cb0
void UIQuestEventDispatcher::vfunc_4(void* p)
{
    for (size_t i = 0; i < m_listeners.GetCount(); ++i) {
        UIQuestEventListener* pListener = m_listeners[i];
        if (pListener)
            pListener->vfunc_o178_4(p);
    }
}
MS2_REPLACE_METHOD(0x141aa8cb0, UIQuestEventDispatcher, vfunc_4, 128, 0xB8A8E21E);

// @0x141aa8d40
void UIQuestEventDispatcher::vfunc_5(void* p)
{
    for (size_t i = 0; i < m_listeners.GetCount(); ++i) {
        UIQuestEventListener* pListener = m_listeners[i];
        if (pListener)
            pListener->vfunc_o178_5(p);
    }
}
MS2_REPLACE_METHOD(0x141aa8d40, UIQuestEventDispatcher, vfunc_5, 128, 0x346B812F);

// @0x141aa8dd0
void UIQuestEventDispatcher::vfunc_6(void* p)
{
    for (size_t i = 0; i < m_listeners.GetCount(); ++i) {
        UIQuestEventListener* pListener = m_listeners[i];
        if (pListener)
            pListener->vfunc_o178_6(p);
    }
}
MS2_REPLACE_METHOD(0x141aa8dd0, UIQuestEventDispatcher, vfunc_6, 128, 0xBB610682);

// @0x141aa8e60
void UIQuestEventDispatcher::vfunc_7(int a1, int a2)
{
    for (size_t i = 0; i < m_listeners.GetCount(); ++i) {
        UIQuestEventListener* pListener = m_listeners[i];
        if (pListener)
            pListener->vfunc_o178_7(a1, a2);
    }
}
MS2_REPLACE_METHOD(0x141aa8e60, UIQuestEventDispatcher, vfunc_7, 136, 0x952F862F);

MS2_EMIT_CRT_MEMMOVE_S();
// MS2-PIN: memmove_s 0x141aa96b0

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x141aa97d0
UIQuestGuideDialog::UIQuestGuideDialog()
{
    m_80 = 1;
    m_bMissionToggle = 0;
    m_bRebuild = 0;
    m_bRecommendDirty = 0;
    m_nRecommendQuest = 0;
    m_2c = 0xd;
    FUN_141925e70(0, 1);
    m_alignment = new UICommon::CAlignmentInfo(6, 0.0f, 330.0f);
}

// @0x141aa99c0
UIQuestGuideDialog::~UIQuestGuideDialog()
{
}

// @0x141aa9a90
CString UIQuestGuideDialog::vfunc_1()
{
    return "QuestGuideDialog";
}
MS2_REPLACE_METHOD(0x141aa9a90, UIQuestGuideDialog, vfunc_1, 61, 0x457BF7B6);

// @0x141aa9ae0
int UIQuestGuideDialog::vfunc_65()
{
    if (!UIDialog::vfunc_65())
        return 0;
    FUN_140bfc4b0()->FUN_141aa87c0(this);
    FUN_140939a10()->FUN_140da4e40(L"NotifyChangeMyLevel", Delegate<void(NotifyObject*)>(this, &UIQuestGuideDialog::FUN_141aab760));
    FUN_140bccd50()->FUN_140da5180(0x53, Delegate<void(CInPacket&)>(this, &UIQuestGuideDialog::FUN_141aab840));
    return 1;
}
MS2_REPLACE_METHOD(0x141aa9ae0, UIQuestGuideDialog, vfunc_65, 456, 0xAB811FEE);

// @0x141aa9cb0
void UIQuestGuideDialog::vfunc_67()
{
    if (m_30.get()) {
        int nPage = m_30->FUN_1422baa20("m_pageIndex").GetInt();
        m_pageIndex.SetAt(DAT_143ab2828, nPage);
    }
    UIDialog::vfunc_67();
    FUN_140bfc4b0()->FUN_141aa8850(this);
    FUN_140939a10()->FUN_140da4eb0(L"NotifyChangeMyLevel", Delegate<void(NotifyObject*)>(this, &UIQuestGuideDialog::FUN_141aab760));
    FUN_140bccd50()->FUN_140da51e0(0x53, Delegate<void(CInPacket&)>(this, &UIQuestGuideDialog::FUN_141aab840));
}
MS2_REPLACE_METHOD(0x141aa9cb0, UIQuestGuideDialog, vfunc_67, 602, 0x4D96E31B);

// @0x141aa9f10
void UIQuestGuideDialog::vfunc_43()
{
    UIDialog::vfunc_43();
    if (m_60)
        m_alignment->FUN_141901cd0();
    FUN_141aadc50();
}
MS2_REPLACE_METHOD(0x141aa9f10, UIQuestGuideDialog, vfunc_43, 72, 0x2D9B0606);

// @0x141aa9f60
// MS2-FUNCTIONAL: cl /Od stack-slot and temporary allocation differ
void UIQuestGuideDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    int nMax = *FUN_1401d3200()->m_4078.FUN_1402056b0();
    int nMax2 = *FUN_1401d3200()->m_40d0.FUN_1402056b0();
    m_30->FUN_1409ba0d0("setMaxEntity", nMax, nMax2);
    int nPage = 0;
    m_pageIndex.Lookup(DAT_143ab2828, nPage);
    static_cast<ASObj*>(m_30.operator->())->FUN_1407cb9c0("m_pageIndex", nPage);
    m_removeQueue.RemoveAll();
    m_addQueue.RemoveAll();
    m_bRecommendDirty = 0;
    m_nRecommendQuest = 0;
    if (FUN_14036d570(FUN_140166410(), 0x77)) {
        m_navigation.AssignRaw(new AScript(m_30->FUN_1422baa20("updateNavigation"), 2));
        ASFunction fn(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIQuestGuideDialog::FUN_141aaf150), 0, FUN_1422db730());
        static_cast<ASObj*>(m_30.operator->())->FUN_1409adbe0("m_funcGetNavigation", Scaleform::GFx::Value(fn.FUN_1422bb870()));
    }
    FUN_141aaba00();
    FUN_140bccd50()->FUN_140da5180(0x100, Delegate<void(CInPacket&)>(this, &UIQuestGuideDialog::FUN_141aab700));
}
MS2_REPLACE_METHOD(0x141aa9f60, UIQuestGuideDialog, OnLoadComplete, 1044, 0x27888106);

// @0x141aaa380
void UIQuestGuideDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    FUN_140bccd50()->FUN_140da51e0(0x100, Delegate<void(CInPacket&)>(this, &UIQuestGuideDialog::FUN_141aab700));
    m_navigation = 0;
}
MS2_REPLACE_METHOD(0x141aaa380, UIQuestGuideDialog, vfunc_26, 189, 0x676C2762);

// @0x141aaa450
// MS2-FUNCTIONAL: cl /Od stack-slot and temporary allocation differ (frame 0x10 larger in the exe)
void UIQuestGuideDialog::vfunc_15()
{
    if (FUN_1422b9e00(FUN_1408e57f0()) != 0x620001d)
        return;
    if (!m_30)
        return;
    if (m_removeQueue.GetCount()) {
        for (size_t i = 0; i < m_removeQueue.GetCount(); ++i)
            FUN_141aac360(m_removeQueue[i]);
        m_removeQueue.RemoveAll();
    }
    if (m_bRecommendDirty) {
        m_bRecommendDirty = 0;
        FUN_141aae5a0();
    }
    if (m_addQueue.GetCount()) {
        for (size_t i = 0; i < m_addQueue.GetCount(); ++i)
            FUN_141aac190(m_addQueue[i]);
        m_addQueue.RemoveAll();
    }
    if (m_bRebuild) {
        m_bRebuild = 0;
        FUN_141aaba00();
    }
    if (m_navigation.get() && m_navigationTick.FUN_140268870(0xf0))
        m_navigation->FUN_1422bb3c0();
}
MS2_REPLACE_METHOD(0x141aaa450, UIQuestGuideDialog, vfunc_15, 523, 0xF3015AD5);

// @0x141aaa670
// MS2-FUNCTIONAL: cl /Od stack-slot and temporary allocation differ across the ASData branches
int UIQuestGuideDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp(szMethod, "onClose") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            Unk_PayloadPtr<CQuest> spQuest = FUN_140764020()->vfunc_o10_3(data.FUN_1422b8a10());
            if (spQuest.get())
                spQuest->RequestTrackingState(0);
        }
    }
    else if (_stricmp(szMethod, "onTrace") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            int nQuestId = data.FUN_1422b8b10();
            bool bTrace = data.FUN_1422b8a90();
            bool bChanged;
            if (!bTrace) {
                bChanged = FUN_140e7c990()->FUN_140c9a490(nQuestId) != 0;
                if (bChanged)
                    FUN_140e7c990()->FUN_140c9a420(0);
            }
            else {
                FUN_140e7c990()->FUN_140c9a420(nQuestId);
                bChanged = true;
            }
            if (bChanged && m_30.get())
                m_30->FUN_140ed0fd0("setTracingEntity", nQuestId, bTrace);
        }
    }
    else if (_stricmp(szMethod, "onEntityOverflow") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            Unk_PayloadPtr<CQuest> spQuest = FUN_140764020()->vfunc_o10_3(data.FUN_1422b8a10());
            if (spQuest.get()) {
                spQuest->RequestTrackingState(0);
                FUN_141275260(0x5f1, 1, 1);
            }
        }
    }
    else if (_stricmp(szMethod, "onLinkQuestDialog") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            int nQuestId = data.FUN_1422b8b10();
            Unk_PayloadPtr<CQuest> spQuest = FUN_140764020()->vfunc_o10_3(nQuestId);
            if (!spQuest.get()) {
                if (!FUN_140764020()->vfunc_1(nQuestId, 0))
                    return 0;
            }
            else if (!spQuest->GetTrackingState()) {
                return 0;
            }
            if (UIQuestDialog* pDialog = FUN_14131f1e0(0x4e3e))
                pDialog->FUN_141a9bff0(nQuestId);
        }
    }
    else if (_stricmp(szMethod, "onMoveField") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_1416cf510(FUN_140764020(), data.FUN_1422b8b10());
    }
    else if (_stricmp(szMethod, "onMoveDungeon") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_1416cf630(FUN_140764020(), data.FUN_1422b8b10());
    }
    else if (_stricmp(szMethod, "onLinkFieldMission") == 0) {
        if (FUN_140931510()->FUN_140d9f4e0() == 0) {
            if (Unk_140961730* pDialog = FUN_140961730(0x4e42))
                pDialog->FUN_141b5c230();
        }
    }
    else if (_stricmp(szMethod, "onFieldMissionToggle") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            m_bMissionToggle = data.FUN_1422b8a90();
    }
    else if (_stricmp(szMethod, "onMoveReEntry") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_1416cf750(FUN_140764020(), data.FUN_1422b8b10());
    }
    else if (_stricmp(szMethod, "onClickDispatch") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_1416cf870(FUN_140764020(), data.FUN_1422b8b10());
    }
    else if (_stricmp(szMethod, "onClickPartyFind") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_1416cf980(FUN_140764020(), data.FUN_1422b8b10(), 0);
    }
    else if (_stricmp(szMethod, "onClickPartyFindCancel") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_1416cf980(FUN_140764020(), data.FUN_1422b8b10(), 1);
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141aaa670, UIQuestGuideDialog, vfunc_28, 2344, 0x603D95BB);

// @0x141aaafa0
int UIQuestGuideDialog::vfunc_52()
{
    return 1;
}
MS2_REPLACE_METHOD(0x141aaafa0, UIQuestGuideDialog, vfunc_52, 11, 0x30025ED0);

// @0x141aaafc0
// MS2-FUNCTIONAL: the exe calls SnowmanPtr get/-> out of line (0x140e97350/0x140e97360); the shared SnowmanPtr is inline
int UIQuestGuideDialog::vfunc_53(void* pCfg)
{
    if (!UIDialog::vfunc_53(pCfg))
        return 0;
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (m_alignment.get() && pDialog) {
        int y = pDialog->FUN_1422c1530();
        int x = pDialog->FUN_1422c1500();
        int h = pDialog->FUN_1422c13b0();
        int w = pDialog->FUN_1422c1340();
        m_alignment->FUN_141901880(m_30, (float)w, (float)h, (float)x, (float)y);
        m_alignment->FUN_1419015e0(pCfg);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x141aaafc0, UIQuestGuideDialog, vfunc_53, 439, 0xBC2384AF);

// @0x141aab180
// MS2-FUNCTIONAL: the exe calls SnowmanPtr get/-> out of line (0x140e97350/0x140e97360); the shared SnowmanPtr is inline
int UIQuestGuideDialog::vfunc_54(void* pCfg)
{
    if (!UIDialog::vfunc_54(pCfg))
        return 0;
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (m_alignment.get() && pDialog) {
        if (!m_alignment->FUN_141901660(pCfg)) {
            int y = pDialog->FUN_1422c1530();
            int x = pDialog->FUN_1422c1500();
            int h = pDialog->FUN_1422c13b0();
            int w = pDialog->FUN_1422c1340();
            m_alignment->FUN_141901880(m_30, (float)w, (float)h, (float)x, (float)y);
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x141aab180, UIQuestGuideDialog, vfunc_54, 450, 0xB9B45FE4);

// @0x141aab350
void UIQuestGuideDialog::vfunc_18()
{
    if ((bool)m_30.get())
    {
        if (FUN_1422dc430())
            FUN_141aadc50();
    }
}
MS2_REPLACE_METHOD(0x141aab350, UIQuestGuideDialog, vfunc_18, 81, 0x2DEC7D5B);

// @0x141aab3b0
void UIQuestGuideDialog::vfunc_o178_1(void* p)
{
    // The exe uses the parameter directly (no typed local).
    if (!static_cast<CQuest*>(p)->GetTrackingState())
        return;
    m_addQueue.Add(static_cast<CQuest*>(p)->FUN_140bfc580());
    if (static_cast<CQuest*>(p)->GetQuestType() == 0)
        m_bRecommendDirty = 1;
}
MS2_REPLACE_METHOD_VIA(0x141aab3b0, UIQuestGuideDialog, UIQuestEventListener, vfunc_o178_1, 99, 0x7C4739C4);

// @0x141aab420
void UIQuestGuideDialog::vfunc_o178_2(void* p)
{
    m_removeQueue.Add(static_cast<CQuest*>(p)->FUN_140bfc580());
    if (static_cast<CQuest*>(p)->GetQuestType() == 0)
        m_bRecommendDirty = 1;
}
MS2_REPLACE_METHOD_VIA(0x141aab420, UIQuestGuideDialog, UIQuestEventListener, vfunc_o178_2, 77, 0xE797C8E7);

// @0x141aab480
void UIQuestGuideDialog::vfunc_o178_3(void* p)
{
    if (!static_cast<CQuest*>(p)->GetTrackingState())
        return;
    FUN_141aabe50(static_cast<CQuest*>(p));
}
MS2_REPLACE_METHOD_VIA(0x141aab480, UIQuestGuideDialog, UIQuestEventListener, vfunc_o178_3, 65, 0x92310181);

// @0x141aab4d0
void UIQuestGuideDialog::vfunc_o178_7(int nQuestId, int a2)
{
    FUN_141aac190(nQuestId);
}
MS2_REPLACE_METHOD_VIA(0x141aab4d0, UIQuestGuideDialog, UIQuestEventListener, vfunc_o178_7, 46, 0x20252149);

// @0x141aab510
void UIQuestGuideDialog::vfunc_o178_5(void* p)
{
    FUN_141aac360(static_cast<CQuest*>(p)->FUN_140bfc580());
    if (static_cast<CQuest*>(p)->GetQuestType() == 0)
        m_bRecommendDirty = 1;
}
MS2_REPLACE_METHOD_VIA(0x141aab510, UIQuestGuideDialog, UIQuestEventListener, vfunc_o178_5, 80, 0xF3693812);

// @0x141aab570
void UIQuestGuideDialog::vfunc_o178_6(void* p)
{
    if (vfunc_55())
        return;
    if (static_cast<CQuest*>(p)->GetTrackingState())
        FUN_141aac190(static_cast<CQuest*>(p)->FUN_140bfc580());
    else
        FUN_141aac360(static_cast<CQuest*>(p)->FUN_140bfc580());
}
MS2_REPLACE_METHOD_VIA(0x141aab570, UIQuestGuideDialog, UIQuestEventListener, vfunc_o178_6, 147, 0xE25CA329);

// @0x141aab610
void UIQuestGuideDialog::vfunc_o178_9(void* p)
{
    Unk_RewardMission* pMission = FUN_140931510()->FUN_140d9f4e0().get();
    if (pMission)
        return;
    ASObj obj(2);
    if (FUN_141aaddb0(obj))
        m_30->Invoke("updateMission", obj);
}
MS2_REPLACE_METHOD_VIA(0x141aab610, UIQuestGuideDialog, UIQuestEventListener, vfunc_o178_9, 220, 0xC3C523A2);

// @0x141aab700
void UIQuestGuideDialog::FUN_141aab700(CInPacket& packet)
{
    // MS2-FUNCTIONAL: the exe widens the byte to an int switch temporary; cl folds the cast here
    switch ((int)packet.vfunc_o8_1()) {
    case 1:
        FUN_141aadbc0();
        break;
    }
}
MS2_REPLACE_METHOD(0x141aab700, UIQuestGuideDialog, FUN_141aab700, 77, 0x0446095D);

// @0x141aab760
void UIQuestGuideDialog::FUN_141aab760(NotifyObject* pObj)
{
    if (!m_30)
        return;
    if (!m_nRecommendQuest)
        return;
    ASObj obj(2);
    if (!FUN_141aae8d0(m_nRecommendQuest, obj))
        return;
    m_30->Invoke("updateEntity", obj);
}
MS2_REPLACE_METHOD(0x141aab760, UIQuestGuideDialog, FUN_141aab760, 218, 0x5B988BD4);

// @0x141aab840
void UIQuestGuideDialog::FUN_141aab840(CInPacket& packet)
{
    if (!FUN_141924630())
        return;
    int nMode = packet.vfunc_o8_1();
    switch (nMode) {
    case 2: case 3: case 7: case 8: case 9: case 0x1e: {
        ATL::CAtlArray<Unk_PayloadPtr<CQuest>> quests;
        FUN_1416cb8b0(FUN_140764020(), quests, 1, 0xb, -1);
        int nMapId = FUN_1403ed2d0()->FUN_141bd3060();
        for (size_t i = 0; i < quests.GetCount(); ++i) {
            Unk_PayloadPtr<CQuest> spQuest(quests[i]);
            if (!spQuest->GetTrackingState())
                continue;
            if (!spQuest->HasMultiUserRoom(nMapId))
                continue;
            FUN_141aabe50(spQuest.get());
        }
    }
    }
}
MS2_REPLACE_METHOD(0x141aab840, UIQuestGuideDialog, FUN_141aab840, 442, 0xDD2CE949);

// @0x141aaba00
void UIQuestGuideDialog::FUN_141aaba00()
{
    if (!m_30)
        return;
    m_30->Invoke("clearAll");
    FUN_141aabcb0();
    ATL::CAtlArray<Unk_PayloadPtr<CQuest>> quests;
    FUN_1416cb8b0(FUN_140764020(), quests, 1, 0xb, -1);
    ASArray list(2);
    for (size_t i = 0; i < quests.GetCount(); ++i) {
        Unk_PayloadPtr<CQuest> spQuest(quests[i]);
        if (!spQuest->GetTrackingState())
            continue;
        ASObj obj(2);
        if (!FUN_141aad6b0(spQuest.get(), obj))
            continue;
        list.FUN_1422bbf00(obj);
    }
    m_nRecommendQuest = FUN_141aae6d0();
    if (m_nRecommendQuest) {
        ASObj obj(2);
        if (FUN_141aae8d0(m_nRecommendQuest, obj))
            list.FUN_1422bbf00(obj);
    }
    m_30->FUN_140bd2cb0("buildAll", list);
}
MS2_REPLACE_METHOD(0x141aaba00, UIQuestGuideDialog, FUN_141aaba00, 682, 0x3B87845E);

// @0x141aabcb0
void UIQuestGuideDialog::FUN_141aabcb0()
{
    if (!m_30)
        return;
    Unk_RewardMissionPtr spMission = FUN_140931510()->FUN_140d9f4e0();
    if (spMission.get()) {
        if (FUN_14036d570(FUN_140166410(), 0x71)) {
            ASObj obj(2);
            if (FUN_141aae150(obj))
                m_30->Invoke("addMission", obj, "dungeon");
        }
    }
    else {
        ASObj obj(2);
        if (FUN_141aaddb0(obj))
            m_30->Invoke("addMission", obj, "field");
    }
}
MS2_REPLACE_METHOD(0x141aabcb0, UIQuestGuideDialog, FUN_141aabcb0, 406, 0x27D2F9B2);

// @0x141aabe50
// MS2-FUNCTIONAL: cl /Od stack-slot and temporary allocation differ
void UIQuestGuideDialog::FUN_141aabe50(CQuest* pQuest)
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (!pDialog)
        return;
    ASObj obj(2);
    obj.FUN_1409c0d20("id", pQuest->FUN_140bfc580());
    obj.FUN_1407cb9c0("satisfied", pQuest->IsComplete());
    obj.FUN_1407cb9c0("progress", 1);
    obj.FUN_1407cba60("icon", FUN_141aad550(pQuest));
    obj.FUN_1407cbb20("title", FUN_1416e5210(pQuest->FUN_140bfc580(), CStringW(L"s_quest_name_with_level")));
    int nAlliance = pQuest->GetData()->m_4c;
    if (nAlliance)
        obj.FUN_1407cba60("alliance", FUN_140762e90(nAlliance));
    FUN_141aaca80(obj, pQuest);
    FUN_141aac3e0(obj, pQuest);
    FUN_141aac6a0(obj, pQuest);
    FUN_141aac9b0(obj, pQuest);
    pDialog->Invoke("updateEntity", obj);
}
MS2_REPLACE_METHOD(0x141aabe50, UIQuestGuideDialog, FUN_141aabe50, 817, 0xC4BB9192);

// @0x141aac190
int UIQuestGuideDialog::FUN_141aac190(int nQuestId)
{
    CQuest* pQuest = FUN_140764020()->vfunc_o10_3(nQuestId).get();
    if (!pQuest)
        return 0;
    if (pQuest->IsRewarded())
        return 0;
    if (!FUN_141aacd70() && !FUN_14074b790(nQuestId)) {
        FUN_141275260(0x5f1, 1, 1);
        return 0;
    }
    if (ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30)) {
        ASObj obj(2);
        if (!FUN_141aad6b0(pQuest, obj))
            return 0;
        pDialog->Invoke("addEntity", obj);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x141aac190, UIQuestGuideDialog, FUN_141aac190, 450, 0x21A098E1);

// @0x141aac360
void UIQuestGuideDialog::FUN_141aac360(int nQuestId)
{
    if (ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30))
        pDialog->Invoke("removeEntity", (unsigned int)nQuestId);
}
MS2_REPLACE_METHOD(0x141aac360, UIQuestGuideDialog, FUN_141aac360, 117, 0x896E23E8);

// @0x141aac3e0
void UIQuestGuideDialog::FUN_141aac3e0(ASObj& obj, CQuest* pQuest)
{
    if (!pQuest)
        return;
    ASArray conditions(2);
    MS2Ptr<CQuestData> spData = pQuest->GetData();
    for (size_t i = 0; i < spData->m_conditions.GetCount(); ++i) {
        MS2Ptr<CConditionCommonData> spCond(spData->m_conditions[i]);
        ASObj entry(2);
        entry.FUN_1407cbb20("text", FUN_1416e57d0(pQuest->FUN_140bfc580(), (int)i));
        entry.FUN_1407cbbe0("satisfied", pQuest->GetProgress((int)i) >= spCond->m_nGoal);
        conditions.FUN_1422bbf00(entry);
    }
    if (pQuest->IsComplete()) {
        ASObj entry(2);
        entry.FUN_1407cbb20("text", FUN_1416e55b0(pQuest->FUN_140bfc580()));
        entry.FUN_1407cb9c0("satisfied", 0);
        conditions.FUN_1422bbf00(entry);
    }
    obj.FUN_1409eb1d0("conditions", conditions);
}
MS2_REPLACE_METHOD(0x141aac3e0, UIQuestGuideDialog, FUN_141aac3e0, 694, 0xF5A0FD2E);

// @0x141aac6a0
// MS2-FUNCTIONAL: cl /Od stack-slot and temporary allocation differ (CMsTime getters)
void UIQuestGuideDialog::FUN_141aac6a0(ASObj& obj, CQuest* pQuest)
{
    if (!pQuest)
        return;
    if (!FUN_14074b090(pQuest->GetData().operator->()))
        return;
    CStringW strPeriod;
    int bExpired = pQuest->FUN_1407447c0();
    if (!bExpired) {
        CMsTime end(pQuest->FUN_1407448a0());
        int nYear = end.GetYear();
        int nMonth = end.GetMonth();
        int nDay = end.GetDay();
        int nHour = end.GetHour();
        int nMinute = end.GetMinute();
        strPeriod = FUN_1409e8ca0(CStringW(L"s_quest_end_time"), nYear, nMonth, nDay, nHour, nMinute);
    }
    else {
        strPeriod = FUN_14028b8e0(CStringW(L"s_quest_end_time_expired"));
    }
    obj.FUN_1407cbb20("period", strPeriod);
    obj.FUN_1407cb9c0("expired", bExpired);
}
MS2_REPLACE_METHOD(0x141aac6a0, UIQuestGuideDialog, FUN_141aac6a0, 768, 0x9644C89D);

// @0x141aac9b0
void UIQuestGuideDialog::FUN_141aac9b0(ASObj& obj, CQuest* pQuest)
{
    int bNavi = 0;
    int nTracing = 0;
    if (FUN_14036d570(FUN_140166410(), 0x77)) {
        bNavi = pQuest->GetFlag() != 0;
        nTracing = FUN_140e7c990()->FUN_140c9a490(pQuest->FUN_140bfc580());
    }
    obj.FUN_1407cb9c0("navi", bNavi);
    obj.FUN_1407cb9c0("tracing", nTracing);
}
MS2_REPLACE_METHOD(0x141aac9b0, UIQuestGuideDialog, FUN_141aac9b0, 195, 0x42F7E3E5);

// @0x141aaca80
// MS2-FUNCTIONAL: cl /Od stack-slot and temporary allocation differ
void UIQuestGuideDialog::FUN_141aaca80(ASObj& obj, CQuest* pQuest)
{
    if (!pQuest)
        return;
    int nMapId = FUN_1403ed2d0()->FUN_141bd3060();
    ASArray buttons(2);
    CQuestCommon* pCommon = pQuest;
    if (pCommon->FUN_1407441f0(nMapId))
        buttons.FUN_1422bbf70("gotoNpc");
    if (pCommon->FUN_1407443e0(nMapId))
        buttons.FUN_1422bbf70("gotoDungeon");
    if (pCommon->FUN_140744670(nMapId))
        buttons.FUN_1422bbf70("gotoReEntry");
    if (pQuest->FUN_140d738d0() || pQuest->FUN_140d738c0())
        buttons.FUN_1422bbf70("gotoDispatch");
    if (pQuest->HasMultiUserRoom(nMapId)) {
        MS2Ptr<CQuestData> spData = pQuest->GetData();
        if (!spData)
            return;
        Unk_BattleRoomPtr spRoom = FUN_14031c2a0()->FUN_1403206b0(spData->m_30c.m_roomId);
        if (spRoom.FUN_140e36ca0())
            return;
        int nDungeonId = FUN_1402178b0(spRoom->m_1c);
        buttons.FUN_1422bbf70(FUN_14162ac00(FUN_1409670d0(), nDungeonId) ? "partyFindCancel" : "partyFind");
    }
    obj.FUN_1409eb1d0("gotoButton", buttons);
}
MS2_REPLACE_METHOD(0x141aaca80, UIQuestGuideDialog, FUN_141aaca80, 745, 0xC28CB79F);

// @0x141aacd70
bool UIQuestGuideDialog::FUN_141aacd70()
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (!pDialog)
        return false;
    return FUN_1409c1720(pDialog->Invoke("canAdd"));
}
MS2_REPLACE_METHOD(0x141aacd70, UIQuestGuideDialog, FUN_141aacd70, 164, 0xF38DCC4F);

// @0x141aace20
bool UIQuestGuideDialog::FUN_141aace20(int nQuestId)
{
    if (!FUN_14074b790(nQuestId))
        return false;
    MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuestId);
    if (!spData)
        return false;
    unsigned nMapId = FUN_1403ed2d0()->FUN_141bd3060();
    if (FUN_140408410(&spData->m_fields, &nMapId) == -1)
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x141aace20, UIQuestGuideDialog, FUN_141aace20, 194, 0xEB892225);

// @0x141aacef0
void UIQuestGuideDialog::FUN_141aacef0(int nQuestId)
{
    m_removeQueue.Add(nQuestId);
}
MS2_REPLACE_METHOD(0x141aacef0, UIQuestGuideDialog, FUN_141aacef0, 41, 0x196C403A);

// @0x141aacf20
void UIQuestGuideDialog::FUN_141aacf20()
{
    m_bRebuild = 1;
}
MS2_REPLACE_METHOD(0x141aacf20, UIQuestGuideDialog, FUN_141aacf20, 21, 0x0860DB21);

// @0x141aacf40
// MS2-FUNCTIONAL: cl /Od stack-slot and temporary allocation differ (switch temporaries)
CStringW UIQuestGuideDialog::FUN_141aacf40(int nQuestId)
{
    MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuestId);
    if (!spData)
        return L"";
    CStringW strKind = FUN_1401a9d70()->FUN_141811980(0x50, nQuestId);
    if (strKind.GetLength() == 0) {
        switch (FUN_14074b050(spData.operator->())) {
        case 0: strKind = FUN_14028de60(0x5dd); break;
        case 1: strKind = FUN_14028de60(0x5de); break;
        case 2: strKind = FUN_14028de60(0x5df); break;
        case 6: strKind = FUN_14028b8e0(CStringW(L"s_quest_guild_quest")); break;
        case 8: strKind = FUN_14028b8e0(CStringW(L"s_quest_field_quest")); break;
        case 9: strKind = FUN_14028b8e0(CStringW(L"s_quest_alliance_quest")); break;
        }
    }
    return FUN_140656190(L"[{0}] {1}", strKind, FUN_1416e7fb0(spData->m_28));
}
MS2_REPLACE_METHOD(0x141aacf40, UIQuestGuideDialog, FUN_141aacf40, 909, 0x310FE535);

// @0x141aad300
unsigned UIQuestGuideDialog::FUN_141aad300(int nChapter)
{
    ATL::CAtlArray<unsigned> quests;
    FUN_1407476c0()->FUN_14074cfd0(nChapter, quests);
    return (unsigned)quests.GetCount();
}
MS2_REPLACE_METHOD(0x141aad300, UIQuestGuideDialog, FUN_141aad300, 88, 0x5AE2D51B);

// @0x141aaf410
// The chapter sort: by start time.
static bool FUN_141aaf410(Unk_PayloadPtr<CQuest> a, Unk_PayloadPtr<CQuest> b)
{
    return a->GetStartTime() <= b->GetStartTime();
}

// @0x141aad360
int UIQuestGuideDialog::FUN_141aad360(int nChapter, int nQuestId)
{
    int nIndex = 0;
    std::vector<Unk_PayloadPtr<CQuest>> quests;
    FUN_1416cbb20(FUN_140764020(), quests, 4, 0xb, nChapter);
    std::sort(quests.begin(), quests.end(), FUN_141aaf410);
    for (std::vector<Unk_PayloadPtr<CQuest>>::iterator it = quests.begin(); it != quests.end(); ++it) {
        ++nIndex;
        Unk_PayloadPtr<CQuest> spQuest(*it);
        if (spQuest->FUN_140bfc580() == nQuestId)
            return nIndex;
    }
    return -1;
}
MS2_REPLACE_METHOD(0x141aad360, UIQuestGuideDialog, FUN_141aad360, 360, 0x580E58D0);

// @0x141aad4d0
CString UIQuestGuideDialog::FUN_141aad4d0(int nChapter, int nQuestId)
{
    unsigned nCount = FUN_141aad300(nChapter);
    int nIndex = FUN_141aad360(nChapter, nQuestId);
    return StringFormat("{0}/{1}", nIndex, nCount);
}
MS2_REPLACE_METHOD(0x141aad4d0, UIQuestGuideDialog, FUN_141aad4d0, 121, 0xE571E032);

// @0x141aad550
// MS2-FUNCTIONAL: the exe constructs the four CString temporaries in a different order/slots
CString UIQuestGuideDialog::FUN_141aad550(CQuest* pQuest)
{
    if (!pQuest->IsComplete())
        return "progress";
    return FUN_141082090(pQuest->FUN_140bfc580(), CString("epic"), CString("satisfied"), CString("repeat"), CString("event"));
}
MS2_REPLACE_METHOD(0x141aad550, UIQuestGuideDialog, FUN_141aad550, 331, 0x02400718);

// @0x141aad6b0
// MS2-FUNCTIONAL: cl /Od stack-slot and temporary allocation differ
int UIQuestGuideDialog::FUN_141aad6b0(CQuest* pQuest, ASObj& obj)
{
    int nQuestId = pQuest->FUN_140bfc580();
    obj.FUN_1409c0d20("id", nQuestId);
    obj.FUN_141aafcd0("type", pQuest->GetQuestType());
    obj.FUN_1407cb9c0("repeat", FUN_1407640c0(pQuest->GetData().operator->()) != 0);
    obj.FUN_1407cb9c0("satisfied", pQuest->IsComplete());
    obj.FUN_1407cb9c0("progress", 1);
    obj.FUN_1407cba60("icon", FUN_141aad550(pQuest));
    obj.FUN_1407cbb20("title", FUN_1416e5210(nQuestId, CStringW(L"s_quest_name_with_level")));
    obj.FUN_1407cbb20("chapterName", FUN_141aacf40(nQuestId));
    obj.FUN_1407cba60("questIndex", FUN_141aad4d0(pQuest->GetData()->m_28, nQuestId));
    obj.FUN_1409c1180("acceptedDate", pQuest->GetStartTime());
    obj.FUN_1407cbbe0("forceRegistGuide", FUN_141aace20(nQuestId));
    int nAlliance = pQuest->GetData()->m_4c;
    if (nAlliance)
        obj.FUN_1407cba60("alliance", FUN_140762e90(nAlliance));
    FUN_141aaca80(obj, pQuest);
    FUN_141aac3e0(obj, pQuest);
    FUN_141aac6a0(obj, pQuest);
    FUN_141aac9b0(obj, pQuest);
    return 1;
}
MS2_REPLACE_METHOD(0x141aad6b0, UIQuestGuideDialog, FUN_141aad6b0, 1287, 0xB67F5AA8);

// @0x141aadbc0
void UIQuestGuideDialog::FUN_141aadbc0()
{
    ASObj obj(2);
    if (FUN_141aae150(obj))
        m_30->Invoke("updateMission", obj);
}
MS2_REPLACE_METHOD(0x141aadbc0, UIQuestGuideDialog, FUN_141aadbc0, 136, 0xC6517290);

// @0x141aadc50
void UIQuestGuideDialog::FUN_141aadc50()
{
    if (m_alignment.get()) {
        int nWidth = 0, nHeight = 0;
        FUN_141aadd10(&nWidth, &nHeight);
        m_alignment->FUN_141901c10(m_30, nWidth, nHeight);
    }
}
MS2_REPLACE_METHOD(0x141aadc50, UIQuestGuideDialog, FUN_141aadc50, 173, 0xDF1191E2);

// @0x141aadd10
void UIQuestGuideDialog::FUN_141aadd10(int* pnWidth, int* pnHeight)
{
    if (m_30 == NULL)
        return;
    if (ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30)) {
        *pnWidth = pDialog->FUN_1422c1340();
        *pnHeight = pDialog->FUN_1422c13b0();
    }
}
MS2_REPLACE_METHOD(0x141aadd10, UIQuestGuideDialog, FUN_141aadd10, 148, 0xF2281377);

// @0x141aaddb0
// MS2-FUNCTIONAL: cl /Od stack-slot and temporary allocation differ (loop index slots)
bool UIQuestGuideDialog::FUN_141aaddb0(ASObj& obj)
{
    if (!m_30)
        return false;
    unsigned nMapId = FUN_1403ed2d0()->FUN_141bd3060();
    unsigned nParent = 0;
    if (FUN_140700390()->FUN_1406fc110(nMapId, &nParent))
        nMapId = nParent;
    ATL::CAtlArray<unsigned> quests;
    FUN_1407476c0()->FUN_14074cbf0(nMapId, quests);
    if (!quests.GetCount())
        return false;
    ASArray conditions(2);
    for (size_t i = 0; i < quests.GetCount(); ++i) {
        int nQuestId = quests[i];
        Unk_PayloadPtr<CQuest> spQuest = FUN_140764020()->vfunc_o10_3(nQuestId);
        MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuestId);
        for (size_t j = 0; j < spData->m_conditions.GetCount(); ++j) {
            MS2Ptr<CConditionCommonData> spCond(spData->m_conditions[j]);
            int bSatisfied = 0;
            if (spQuest.get()) {
                if (spQuest->IsRewarded() || spQuest->GetProgress((int)j) >= spCond->m_nGoal)
                    bSatisfied = 1;
                else
                    bSatisfied = 0;
            }
            ASObj entry(2);
            entry.FUN_1407cbb20("text", FUN_1416e57d0(nQuestId, (int)j));
            entry.FUN_1407cb9c0("satisfied", bSatisfied);
            conditions.FUN_1422bbf00(entry);
        }
    }
    obj.FUN_1409eb1d0("conditions", conditions);
    obj.FUN_1407cb9c0("toggle", m_bMissionToggle);
    return true;
}
MS2_REPLACE_METHOD(0x141aaddb0, UIQuestGuideDialog, FUN_141aaddb0, 910, 0x711502DA);

// @0x141aae150
bool UIQuestGuideDialog::FUN_141aae150(ASObj& obj)
{
    if (!m_30)
        return false;
    Unk_RewardMissionPtr spMission = FUN_140931510()->FUN_140d9f4e0();
    if (spMission == 0)
        return false;
    Unk_BattleRoomPtr spRoom = spMission->FUN_140c9d070();
    if (spRoom == 0)
        return false;
    Unk_RewardEntryList entries;
    spMission->FUN_140c9ce80(entries);
    if (entries.FUN_141ab1ca0())
        return false;
    CStringW strGoal = FUN_1401a9d70()->FUN_141811980(0x45, spRoom->FUN_14031ddd0());
    if (!strGoal.IsEmpty())
        obj.FUN_1407cbb20("dungeonGoal", strGoal);
    ASArray conditions(2);
    for (size_t i = 0; i < entries.FUN_140c9f760(); ++i) {
        Unk_RewardEntryPtr spEntry(entries.FUN_140c9eb50(i));
        ASObj entry(2);
        entry.FUN_1407cbb20("text", FUN_141aae4f0(spEntry));
        entry.FUN_1407cbbe0("satisfied", false);
        conditions.FUN_1422bbf00(entry);
    }
    obj.FUN_1409eb1d0("conditions", conditions);
    obj.FUN_1407cb9c0("toggle", m_bMissionToggle);
    return true;
}
MS2_REPLACE_METHOD(0x141aae150, UIQuestGuideDialog, FUN_141aae150, 913, 0x45911C36);

// @0x141aae4f0
CStringW UIQuestGuideDialog::FUN_141aae4f0(Unk_RewardEntryPtr spEntry)
{
    if (spEntry == 0)
        return L"";
    return spEntry->vfunc_4();
}
MS2_REPLACE_METHOD(0x141aae4f0, UIQuestGuideDialog, FUN_141aae4f0, 168, 0x5608B369);

// @0x141aae5a0
void UIQuestGuideDialog::FUN_141aae5a0()
{
    if (!m_30)
        return;
    int nQuestId = FUN_141aae6d0();
    if (nQuestId) {
        ASObj obj(2);
        if (!FUN_141aae8d0(nQuestId, obj))
            return;
        m_30->Invoke("addEntity", obj);
        m_nRecommendQuest = nQuestId;
    }
    else if (m_nRecommendQuest) {
        FUN_141aac360(m_nRecommendQuest);
        m_nRecommendQuest = 0;
    }
}
MS2_REPLACE_METHOD(0x141aae5a0, UIQuestGuideDialog, FUN_141aae5a0, 293, 0xF16BBB76);

// @0x141aae6d0
// MS2-FUNCTIONAL: cl /Od stack-slot and temporary allocation differ (loop index slots)
int UIQuestGuideDialog::FUN_141aae6d0()
{
    if (!FUN_14036d570(FUN_140166410(), 0xd0))
        return 0;
    PCBase* pActor = FUN_141bd0cc0(FUN_1403ed2d0());
    if (!pActor)
        return 0;
    ATL::CAtlArray<Unk_PayloadPtr<CQuest>> quests;
    FUN_1416cb8b0(FUN_140764020(), quests, 1, 0, -1);
    if (quests.GetCount())
        return 0;
    FUN_1416cb8b0(FUN_140764020(), quests, 2, 0, -1);
    if (!quests.GetCount())
        return 0;
    int nBest = 0;
    __int64 nBestTime = 0;
    __int64 nLimit = FUN_140869440() + 0x14;
    for (size_t i = 0; i < quests.GetCount(); ++i) {
        __int64 nTime = FUN_141aa4980(quests[i].operator->());
        if (nTime <= nLimit && nBestTime < nTime) {
            nBest = quests[i]->FUN_140bfc580();
            nBestTime = nTime;
        }
    }
    return FUN_1416d2600(FUN_140764020(), nBest, 1);
}
MS2_REPLACE_METHOD(0x141aae6d0, UIQuestGuideDialog, FUN_141aae6d0, 499, 0x25DB618B);

// @0x141aae8d0
// MS2-FUNCTIONAL: cl /Od stack-slot and temporary allocation differ
int UIQuestGuideDialog::FUN_141aae8d0(int nQuestId, ASObj& obj)
{
    MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuestId);
    if (!spData)
        return 0;
    PCBase* pActor = FUN_141bd0cc0(FUN_1403ed2d0());
    if (!pActor)
        return 0;
    obj.FUN_1409c0d20("id", nQuestId);
    obj.FUN_141aafcd0("type", 0);
    obj.FUN_1407cb9c0("repeat", FUN_1407640c0(spData.operator->()) != 0);
    obj.FUN_1407cb9c0("satisfied", 0);
    obj.FUN_1407cb9c0("progress", 0);
    obj.FUN_1409c0dc0("icon", FUN_140764020()->vfunc_1(nQuestId, 0) ? "able" : "init");
    obj.FUN_1407cbb20("title", FUN_1416e5210(nQuestId, CStringW(L"s_quest_name_with_level")));
    obj.FUN_1407cbb20("chapterName", FUN_141aacf40(nQuestId));
    obj.FUN_1407cb9c0("acceptedDate", 0);
    int nAlliance = spData->m_4c;
    if (nAlliance)
        obj.FUN_1407cba60("alliance", FUN_140762e90(nAlliance));
    ASArray conditions(2);
    ASObj entry(2);
    entry.FUN_1407cbb20("text", FUN_141aaedd0(nQuestId));
    entry.FUN_1407cb9c0("satisfied", 0);
    conditions.FUN_1422bbf00(entry);
    if ((int)(unsigned short)pActor->vfunc_78() < (int)(unsigned short)spData->m_require.m_level) {
        ASObj level(2);
        level.FUN_1407cbb20("text", FUN_1409e8820(CStringW(L"s_quest_condition_lack_level"), spData->m_require.m_level));
        level.FUN_1407cb9c0("satisfied", 0);
        conditions.FUN_1422bbf00(level);
    }
    obj.FUN_1409eb1d0("conditions", conditions);
    return 1;
}
MS2_REPLACE_METHOD(0x141aae8d0, UIQuestGuideDialog, FUN_141aae8d0, 1263, 0x5587EE01);

// @0x141aaedd0
CStringW UIQuestGuideDialog::FUN_141aaedd0(int nQuestId)
{
    MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuestId);
    if (!spData)
        return L"";
    ATL::CAtlArray<unsigned> fields;
    FUN_140700390()->FUN_1406fb2a0(spData->m_2e8, fields);
    int nField = 0;
    if (fields.GetCount() == 1)
        nField = fields[0];
    else if (fields.GetCount() > 1)
        nField = FUN_140c9b8e0()->FUN_140c915a0(fields);
    CStringW str;
    if (!nField)
        str = FUN_140938ae0(CStringW(L"s_quest_desc_beginable_invalid_field"), spData->m_2e8);
    else if (nField == FUN_1403ed2d0()->FUN_141bd3060())
        str = FUN_140938ae0(CStringW(L"s_quest_desc_beginable_current_field"), spData->m_2e8);
    else
        str = FUN_1409e9890(CStringW(L"s_quest_desc_beginable"), nField, spData->m_2e8);
    FUN_1403b4750()->FUN_1416fb380(str);
    return str;
}
MS2_REPLACE_METHOD(0x141aaedd0, UIQuestGuideDialog, FUN_141aaedd0, 883, 0xB5583F38);

// @0x141aaf150
// MS2-FUNCTIONAL: cl /Od stack-slot and temporary allocation differ (TraceResult / ASObj temporaries)
void UIQuestGuideDialog::FUN_141aaf150(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_30 == NULL || !params.ArgCount)
        return;
    ASData data;
    if (!data.FUN_1422b9620(params.pArgs, params.ArgCount))
        return;
    if (!FUN_141bd0cc0(FUN_1403ed2d0()))
        return;
    Unk_McMapPtr spMap = FUN_1403ed2d0()->FUN_141bd30a0();
    if (spMap.FUN_1408851f0())
        return;
    QuestNavigation::TraceResult result;
    result.m_questId = data.FUN_1422b8b10();
    ASObj obj(2);
    if (FUN_140e7c990()->FUN_140c9a4c0(result) == 1) {
        obj.FUN_1407cb9c0("tracing", 0);
        obj.FUN_1409c4a30("rotation", 0);
        obj.FUN_1407cbb20("distance", FUN_14028b8e0(CStringW(L"s_quest_navigation_none")));
    }
    else {
        obj.FUN_1407cb9c0("tracing", 1);
        obj.FUN_1409c4a30("rotation", result.m_fRotation + spMap.FUN_140885340()->m_fRotation);
        obj.FUN_1407cbb20("distance", result.m_strDistance);
    }
    *params.pRetVal = obj.FUN_1422bb870();
}
MS2_REPLACE_METHOD(0x141aaf150, UIQuestGuideDialog, FUN_141aaf150, 688, 0x5A6ACE16);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// COMDATs

CStringA FUN_1402bf9a0(const char* format, const fmt::ArgList& args);
// @0x141aaf900
template<> CStringA StringFormat<int, unsigned int>(const char* format, const int& v0, const unsigned int& v1)
{
    const fmt::internal::ArgArray<2>::Type array = {fmt::internal::MakeValue<fmt::BasicFormatter<char>>(v0),
                                                  fmt::internal::MakeValue<fmt::BasicFormatter<char>>(v1)};
    return FUN_1402bf9a0(format, fmt::ArgList(fmt::internal::make_type(v0, v1), array));
}

// @0x141aafc10
Scaleform::GFx::Value AScript::Invoke(const char* szMethod, const AScript& a1, const char* a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bce40(args.FUN_1409b1f70(0), a1);
    FUN_1422bce70(args.FUN_1409b1f70(1), a2);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x141aafcd0
void ASObj::FUN_141aafcd0(const char* szName, int n)
{
    ASData data;
    data.FUN_1422b7f70(n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}

// @0x141ab1ca0
inline bool Unk_RewardEntryList::FUN_141ab1ca0()
{
    return FUN_140c9f080() == FUN_140c9f0c0();
}

// @0x141ab1fc0
MS2_EMIT_CRT_MEMMOVE_S_COPY(2);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cc1a40-0x142cc1af0 .text$yd
