// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIAchieveDialog (the trophy window) and the glue of its lists
// (vector / sort / CRBMap / CAtlMap). See uiachievedialog.h. w335.
// MS2-UNIT: ?\uiachievedialog.cpp
// MS2-RANGE: 0x1418a7310-0x1418b1520 .text$mn
// MS2-RANGE: 0x14010fa00-0x14010fbc0 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__EkTrophyRewardGet@@YAXXZ 0x14010fa00 ; probe
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x14010faf0 ; probe
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x14010fb20 ; probe
// MS2-PIN: ??$?0AEAHAEAH$0A@@?$pair@HH@std@@QEAA@AEAH0@Z 0x1418ade00 ; unique
// MS2-PIN: ??$make_pair@AEAHAEAH@std@@YA?AU?$pair@HH@0@AEAH0@Z 0x1418af680 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@UClearRecord@UIAchieveDialog@@@std@@V?$_Vector_val@U?$_Simple_types@UClearRecord@UIAchieveDialog@@@std@@@2@$00@std@@QEBAAEBV?$allocator@UClearRecord@UIAchieveDialog@@@2@XZ 0x1418b0f60 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@UClearRecord@UIAchieveDialog@@@std@@V?$_Vector_val@U?$_Simple_types@UClearRecord@UIAchieveDialog@@@std@@@2@$00@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@UClearRecord@UIAchieveDialog@@@std@@@2@XZ 0x1418b0f70 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@UClearRecord@UIAchieveDialog@@@std@@V?$_Vector_val@U?$_Simple_types@UClearRecord@UIAchieveDialog@@@std@@@2@$00@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@UClearRecord@UIAchieveDialog@@@std@@@2@XZ 0x1418b0f80 ; unique
// MS2-PINS-END tplpin
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiachievedialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uiachievedialog.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cconditioncommon.h"
#include "ms2/commonfiles/achievedata.h"
#include "ms2/commonfiles/achievecondition.h"
#include "ms2/client/ms2/achievemanager.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <vector>

// ---- unit-local views of exe types ----

// The list control of the movie (the AS tile list): clear / append / select.
class Unk_AcList : public ASDisplayObject
{
public:
    virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13();
    virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17();
    virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21();
    virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);
    void FUN_1422dd1d0();                                       // clear
    void FUN_1422dd230(const ASObj& row);                       // append a row
    void FUN_1422dcca0(int nIndex);                             // select
    int FUN_1422dccd0();                                        // selected index
};
class Unk_AcText : public ASDisplayObject
{
public:
    CStringW FUN_1422e0b00();                                   // text
    void FUN_1422e0ab0(const CStringW& str);                    // set the text
};
class Unk_AcDrop : public ASDisplayObject
{
public:
    void FUN_1422df690(int nIndex);                             // select
    int FUN_1422df6c0();                                        // selected index
};
// the "m_heroTrophy" / "m_summaryTrophy" component
class Unk_AcHero : public ASUIComponent
{
public:
    MS2Ptr<Unk_AcList> FUN_140bc7280(const CString& strName);
    MS2Ptr<Unk_AcText> FUN_140bbe880(const CString& strName);
    MS2Ptr<Unk_AcDrop> FUN_140bbe700(const CString& strName);
    Scaleform::GFx::Value FUN_1418adea0(const char* szMethod, unsigned char nIndex, const ASObj& row);
};
// the movie root: gotoAndPlay(label), the trophy index and the reward count calls
class Unk_AcRoot : public AScript
{
public:
    Scaleform::GFx::Value FUN_140e262c0(const char* szMethod, const char* szArg);
    Scaleform::GFx::Value FUN_1409ba030(const char* szMethod, int n);
    Scaleform::GFx::Value FUN_14129cce0(const char* szMethod, int n, CStringW str);
};
#define AC_ROOT(p) static_cast<Unk_AcRoot*>((p).operator->())

// the root pointer of the movie (m_30)
bool FUN_140a467d0(const MS2Ptr<AScript>* pAS);
AScript* FUN_1409ee290(MS2Ptr<AScript>* p);

// the local player and the client options
void* FUN_1403ed2d0();
void* FUN_141bd0cc0(void* pWorld);
void* FUN_14025e7c0();                                          // the text hook object
bool FUN_14116d720(void* p);
bool FUN_14116d840(void* p);
bool FUN_14116d9c0(void* p, int a1, int a2, int a3);
int FUN_14166ce30(void* pPlayer);
class Unk_AcOptions { public: bool FUN_14036d570(int nFlag); };
Unk_AcOptions* FUN_140166410();

// strings
class Unk_AcNames { public: CStringW FUN_141811980(int nTable, int nId); };
Unk_AcNames* FUN_1401a9d70();
CStringW FUN_1405c2690(CStringW strKey, const CStringW& a1);
CStringW FUN_1408f71a0(CStringW strKey, const CStringW& a1, const CStringW& a2);
CStringW FUN_14028de60(int nStringId);
CStringW FUN_1408116a0(int nStringId, const int& n);
CStringW FUN_1409eec40(int nStringId);
CStringW FUN_1416e4df0(int nId);
CStringW FUN_140cbf840(int nDungeonKind);
CString FUN_1402bad60(const char* szFormat, const int* pn);
CString FUN_14016a600(const wchar_t* sz, int nCodePage);
void FUN_14083d2b0(CStringW& str);
int FUN_14083fec0(CStringW strText, CStringW strSearch);
void FUN_141842290(CStringW& str);
void FUN_140d73aa0(CStringW strText, int nType, void* p, CStringW strTag);
int FUN_14053feb0(int nItemId);
void FUN_141275260(int nStringId, int nA, int nB);
void FUN_141276180(const CString& strName, const CString& strArg);
void FUN_140d2cca0(unsigned nId, unsigned nRank);
void FUN_14025a680(const CStringW& str, ATL::CAtlArray<CStringW>& rOut, const wchar_t* szDelim);
void FUN_140710590(COutPacket& packet);

// the xml persistence
void FUN_140873bc0(void* pNode, const char* szName, bool b);
void FUN_140873ca0(void* pNode, const char* szName, int n);
int FUN_1408730a0(void* pNode, const char* szName, bool& rOut);
int FUN_1408731e0(void* pNode, const char* szName, int& rOut);

// the unit's own setters of the Invoke argument lists and members
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, unsigned char n);
void FUN_1422bce40(Scaleform::GFx::Value* pValue, const AScript& obj);
void FUN_1407cd930(Scaleform::GFx::Value* pObject, const char* szName, const Scaleform::GFx::Value& v);
void FUN_1409b4bc0(Scaleform::GFx::Value* pOut, Scaleform::GFx::Value& v);
unsigned int FUN_1409c17e0(const Scaleform::GFx::Value& v);

// the platform: request answers
class Unk_AcPlatform
{
public:
#define AC_V(n) virtual void vfunc_##n();
    AC_V(0) AC_V(1) AC_V(2) AC_V(3) AC_V(4) AC_V(5) AC_V(6) AC_V(7) AC_V(8) AC_V(9)
    AC_V(10) AC_V(11) AC_V(12) AC_V(13) AC_V(14) AC_V(15) AC_V(16) AC_V(17) AC_V(18) AC_V(19)
    AC_V(20) AC_V(21) AC_V(22) AC_V(23) AC_V(24) AC_V(25) AC_V(26) AC_V(27) AC_V(28) AC_V(29)
    AC_V(30) AC_V(31) AC_V(32) AC_V(33) AC_V(34) AC_V(35) AC_V(36)
    virtual int vfunc_37(void* pRequest);
#undef AC_V
};
Unk_AcPlatform* FUN_140d86260();

// the request (search box) objects
class Unk_AcRequest
{
public:
    Unk_AcRequest(int nId);                                     // 0x1401baa00
    Unk_AcRequest(const void* pSource);                         // 0x1401baaa0
    ~Unk_AcRequest();                                           // 0x1401baaf0
    void FUN_1401bac80(const CString& strName, CStringW strValue, int n);
    int FUN_1401bab90(const CString& strName, void* pOut);
private:
    char m_pad[0x38];
};
struct Unk_AcRequestValue
{
    Unk_AcRequestValue();                                       // 0x1401ba840
    ~Unk_AcRequestValue();                                      // 0x1401ba940
    char m_pad_00[0x18];
    int m_code;                                                 // +0x18
    char m_pad_1c[0x1c];
};

// the coloring table: a row set of (achievement id, grade) -> colour (shared view with achievemanager.cpp)
struct Unk_AmColorEntry
{
    char m_pad_00[0x1c];
    int m_nSN;                                                  // +0x1c
    unsigned char m_bHasSecond;                                 // +0x20
    char m_pad_21[3];
    int m_nAchieveId;                                           // +0x24
    int m_nGrade;                                               // +0x28
    int m_nColorId;                                             // +0x2c
    char m_pad_30[8];
    unsigned m_visible;                                         // +0x38
    unsigned m_real;                                            // +0x3c
    int m_pad_40;
    unsigned m_ch2;                                             // +0x44
};
class Unk_AmColorElem
{
public:
    Unk_AmColorElem(Unk_AmColorEntry* pEntry);                  // 0x14056a550
    ~Unk_AmColorElem();                                         // 0x14056c2d0
    Unk_AmColorEntry* FUN_14056d570() const;                    // operator->
    void* m_pad_00;
    Unk_AmColorEntry* m_p;
};
class Unk_AmColorList { public: unsigned FUN_140570e10(); Unk_AmColorEntry* FUN_140570dd0(unsigned n); };
class Unk_AmColorSet
{
public:
    ~Unk_AmColorSet();                                          // 0x14056c240
    void* FUN_14056d460() const;
    Unk_AmColorList* FUN_14056d540() const;
    void* m_pad_00;
    void* m_p;
};
class Unk_AmIngTable
{
public:
    Unk_AmColorSet FUN_140558ad0(int nId);
    Unk_AmColorElem FUN_140558960(int nPaletteId, int nSN);
};
Unk_AmIngTable* FUN_140281980();

// collected ids: dungeons, fish, pets, quests, items
struct Unk_AcRoom : public CPtred { int m_pad_18; int m_1c; };
class Unk_AcRoomTable { public: MS2Ptr<Unk_AcRoom> FUN_1403206b0(int nRoomId); };
Unk_AcRoomTable* FUN_14031c2a0();
class Unk_AcDungeonMgr : public CPtred { public: int FUN_140b22890(int nId); };
MS2Ptr<Unk_AcDungeonMgr>* FUN_140931510();
class Unk_AcFishMgr { public: unsigned __int64 FUN_140cdc380(unsigned nId); };
Unk_AcFishMgr* FUN_140953f20();
class Unk_AcPetMgr { public: int FUN_140c8b220(int nId); };
Unk_AcPetMgr* FUN_140535320();
class Unk_AcQuestState { public: int FUN_140745590(int nQuest); };
struct Unk_AcQuestMgr { char m_pad_00[0x10]; Unk_AcQuestState m_10; };
Unk_AcQuestMgr* FUN_140764020();
extern ATL::CAtlMap<unsigned int, unsigned int> DAT_143ab30e0;        // achievement id -> grade

extern int DAT_143ab2914;                                       // the GM level

// the trophies updated by the server (refreshed per frame) and the claim sound
ATL::CAtlMap<unsigned int, int> DAT_143af0f30;
class Unk_Handle1401cd100 { public: Unk_Handle1401cd100(int nNull); void* m_p; };     // ctor 0x1401cd100
Unk_Handle1401cd100 DAT_143af0fc8(0);
static CString kTrophyRewardGet("system_Trophy_Reward_Get");

CAchieveManager* FUN_1406c7600();

// the summary page rows
struct Unk_AcCount { int m_id; int m_count; };

// the comparator of the summary sort: an empty functor (the exe passes it as a 1-byte value)
struct AcClearOrder { bool operator()(const UIAchieveDialog::ClearRecord& a, const UIAchieveDialog::ClearRecord& b) const; };
CStringW FUN_14093b970(int nId);
CStringW FUN_14093c320(CAchieve* pAchieve);
CStringW FUN_14093c8d0(int nId, int nGrade, int bRaw);
CStringW FUN_14093cdb0(int nId);
CStringW FUN_14093e330(CAchieve* pAchieve, int nKey);
CStringW FUN_14093bf10(CAchieve* pAchieve, int nGrade);
static void AcCollectClears(std::vector<UIAchieveDialog::ClearRecord>& rRecords);
#define FUN_1418adae0 AcCollectClears
static void FUN_1418ae010(ASObj& rObj, const char* szName, int n);
static void FUN_1418adf60(ASObj& rObj, const CString& strName, const AScript& v);

// @0x1418aff70
int CAchieve::GetBookmark() { return m_d8; }

// @0x1418aff90
int CAchieve::GetValue80() { return m_80; }

// @0x1418b0bc0
void CAchieve::SetBookmark(int bBookmark) { m_d8 = bBookmark; }

// @0x1418afce0
bool AcClearOrder::operator()(const UIAchieveDialog::ClearRecord& a, const UIAchieveDialog::ClearRecord& b) const
{
    if (a.m_time == b.m_time)
        return a.m_grade > b.m_grade;
    return a.m_time > b.m_time;
}

// ---- UIAchieveDialog ----

// @0x1418a7310
UIAchieveDialog::UIAchieveDialog()
{
    m_7c = 1;
    m_5c = 1;
    m_88 = 1;
    m_180 = 0;
    m_190 = true;
    FUN_141924170(1);
    CAchieveCategory::Load();
    m_178 = 0;
    m_17c = CAchieveCategory::FindIdByTab(1);
    for (int i = 0; i < 14; i++)
        m_198.SetAt(i, 1);
}

// @0x1418a74b0
UIAchieveDialog::~UIAchieveDialog()
{
}

// @0x1418a7530
CString UIAchieveDialog::vfunc_1()
{
    return "AchieveDialog";
}

// @0x1418a7580
void UIAchieveDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_1e0.RemoveAll();
    DAT_143af0f30.RemoveAll();
    FUN_1418aaee0(m_188);
    COutPacket packet(0x69, 0);
    packet.vfunc_o10_1(3);
    FUN_140710590(packet);
    FUN_1418ac5f0(m_180);
    FUN_1418a9360();
}

// @0x1418a7640
int UIAchieveDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp(szMethod, "onTabChange") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            m_178 = data.FUN_1422b8a10();
            m_17c = data.FUN_1422b8a10();
            FUN_1418a8ff0();
            m_1e0.RemoveAll();
            return 1;
        }
    }
    else if (_stricmp(szMethod, "onUpdateRenderer") == 0) {
        FUN_1418a9800();
        return 1;
    }
    else if (_stricmp(szMethod, "onReward") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            void* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
            if (pPlayer == 0)
                return 0;
            if (FUN_14166ce30(pPlayer) != 0) {
                FUN_141275260(0x80d, 1, 1);
                return 0;
            }
            unsigned nId = data.FUN_1422b8b10();
            COutPacket packet(0x46, 0);
            packet.vfunc_o10_1(3);
            packet.vfunc_o10_3(nId);
            FUN_140710590(packet);
            FUN_141276180(kTrophyRewardGet, CString(""));
            return 1;
        }
    }
    else if (_stricmp(szMethod, "OnUseLink") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            unsigned nId = data.FUN_1422b8b10();
            unsigned nRank = data.FUN_1422b8b10();
            FUN_140d2cca0(nId, nRank);
        }
        return 1;
    }
    else if (_stricmp(szMethod, "onDbgUp") == 0) {
        if (DAT_143ab2914 < 50)
            return 0;
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            unsigned nId = data.FUN_1422b8b10();
            if (FUN_1418acd10(nId) != 0) {
                COutPacket packet(0x46, 0);
                packet.vfunc_o10_1(5);
                packet.vfunc_o10_3(nId);
                packet.vfunc_o10_1(0);
                FUN_140710590(packet);
            }
        }
    }
    else if (_stricmp(szMethod, "onDbgDown") == 0) {
        if (DAT_143ab2914 < 50)
            return 0;
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            unsigned nId = data.FUN_1422b8b10();
            COutPacket packet(0x46, 0);
            packet.vfunc_o10_1(5);
            packet.vfunc_o10_3(nId);
            packet.vfunc_o10_1(1);
            FUN_140710590(packet);
        }
    }
    else if (_stricmp(szMethod, "onDbgUp30") == 0) {
        if (DAT_143ab2914 < 50)
            return 0;
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            unsigned nId = data.FUN_1422b8b10();
            if (FUN_1418acd10(nId) != 0) {
                COutPacket packet(0x46, 0);
                packet.vfunc_o10_1(5);
                packet.vfunc_o10_3(nId);
                packet.vfunc_o10_1(2);
                FUN_140710590(packet);
            }
        }
    }
    else if (_stricmp(szMethod, "onDbgUp99") == 0) {
        if (DAT_143ab2914 < 50)
            return 0;
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            unsigned nId = data.FUN_1422b8b10();
            if (FUN_1418acd10(nId) != 0) {
                COutPacket packet(0x46, 0);
                packet.vfunc_o10_1(5);
                packet.vfunc_o10_3(nId);
                packet.vfunc_o10_1(3);
                FUN_140710590(packet);
            }
        }
    }
    else if (_stricmp(szMethod, "onClickAchieveDetail") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            int nId = data.FUN_1422b8a10();
            FUN_1418aa9b0(nId);
        }
    }
    else if (_stricmp(szMethod, "onSearch") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_1418aa890();
    }
    else if (_stricmp(szMethod, "onBookmark") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            unsigned nId = data.FUN_1422b8b10();
            bool bBookmark = data.FUN_1422b8a90();
            MS2Ptr<CAchieve> spAchieve = FUN_1406c7600()->Find(nId);
            if (spAchieve.get() != 0) {
                spAchieve->SetBookmark(bBookmark);
                COutPacket packet(0x46, 0);
                packet.vfunc_o10_1(4);
                packet.vfunc_o10_3(spAchieve->GetId());
                packet.vfunc_o10_1(bBookmark);
                FUN_140710590(packet);
            }
        }
    }
    else if (_stricmp(szMethod, "onFilterChange") == 0) {
        FUN_1418a8ff0();
        return 1;
    }
    else if (_stricmp(szMethod, "onClickSummary") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            unsigned nId = data.FUN_1422b8b10();
            FUN_1418aa9b0(nId);
        }
        return 1;
    }
    else if (_stricmp(szMethod, "onExpand") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            unsigned nId = data.FUN_1422b8b10();
            bool bExpand = data.FUN_1422b8a90();
            m_1e0.SetAt(nId, bExpand);
        }
    }
    else if (_stricmp(szMethod, "onFilter") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            m_190 = data.FUN_1422b8a90();
            CStringW strKinds = data.FUN_1422b8f40();
            ATL::CAtlArray<CStringW> tokens;
            FUN_14025a680(strKinds, tokens, L",");
            POSITION pos = m_198.GetStartPosition();
            while (pos != 0) {
                int nKind = m_198.GetKeyAt(pos);
                m_198.SetAt(nKind, 0);
                m_198.GetNext(pos);
            }
            for (size_t i = 0; i < tokens.GetCount(); i++) {
                int nKind = CAchieveData::ParseRewardType(tokens[i]);
                m_198.SetAt(nKind, 1);
            }
            FUN_1418a8ff0();
        }
    }
    return 0;
}

// @0x1418a8310
int UIAchieveDialog::vfunc_65()
{
    return UIDialog::vfunc_65();
}

// @0x1418a8330
void UIAchieveDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    m_178 = 0;
    m_188.Empty();
    m_17c = CAchieveCategory::FindIdByTab(1);
}

// @0x1418a8390
void UIAchieveDialog::vfunc_15()
{
    if (DAT_143af0f30.GetCount() != 0 && vfunc_55() == 0) {
        POSITION pos = DAT_143af0f30.GetStartPosition();
        while (pos != 0) {
            unsigned nId = DAT_143af0f30.GetKeyAt(pos);
            FUN_1418aa660(nId);
            DAT_143af0f30.GetNext(pos);
        }
        DAT_143af0f30.RemoveAll();
    }
}

// @0x1418a8430
int UIAchieveDialog::vfunc_13()
{
    if (FUN_140a467d0(&m_30))
        return 0;
    if (FUN_14116d840(FUN_14025e7c0())) {
        bool bHandled = FUN_1409ee290(&m_30)->Invoke("closePopup").GetBool();
        if (!bHandled)
            vfunc_69();
        return 1;
    }
    if (FUN_14116d9c0(FUN_14025e7c0(), 0x1c, 0, 0))
        FUN_1418aa890();
    return 0;
}

// @0x1418a8530
void UIAchieveDialog::vfunc_80(void* pRequest)
{
    Unk_AcRequest request(pRequest);
    Unk_AcRequestValue value;
    if (request.FUN_1401bab90("m_searchInput", &value) == 1) {
        if (value.m_code == 0) {
            FUN_1418a8ff0();
        }
        else {
            FUN_140d73aa0(FUN_1409eec40(0x8b7), 0, 0, CStringW(L""));
            FUN_1418aaee0(CStringW(L""));
        }
    }
}

// @0x1418a8690
void UIAchieveDialog::vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
    UIObject::vfunc_49(pRetVal, pArgs);
    int nItemId = pArgs->FUN_1422b8b10();
    int nRank = FUN_14053feb0(nItemId);
    ASTooltip tip(FUN_141bd0cc0(FUN_1403ed2d0()), 0x20, 2);
    if (tip.FUN_1409e1770(nItemId, nRank) != 0)
        FUN_1409b4bc0(pRetVal, tip.FUN_1422bb870());
}

// @0x1418a8760
int UIAchieveDialog::vfunc_53(void* pCfg)
{
    if (UIDialog::vfunc_53(pCfg) == 0)
        return 0;
    FUN_140873bc0(pCfg, "all", m_190);
    POSITION pos = m_198.GetStartPosition();
    while (pos != 0) {
        CStringW strName = CAchieveData::GetRewardTypeName(m_198.GetKeyAt(pos));
        int nValue = m_198.GetValueAt(pos);
        CString strKey = FUN_14016a600(strName, 0);
        FUN_140873ca0(pCfg, strKey, nValue);
        m_198.GetNext(pos);
    }
    return 1;
}

// @0x1418a88b0
int UIAchieveDialog::vfunc_54(void* pCfg)
{
    if (UIDialog::vfunc_54(pCfg) == 0)
        return 0;
    FUN_1408730a0(pCfg, "all", m_190);
    for (int i = 0; i < 14; i++) {
        CStringW strName = CAchieveData::GetRewardTypeName(i);
        int nValue = 1;
        CString strKey = FUN_14016a600(strName, 0);
        FUN_1408731e0(pCfg, strKey, nValue);
        m_198.SetAt(i, nValue);
    }
    return 1;
}

// @0x1418a89d0
void UIAchieveDialog::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
    UIObject::vfunc_45(pRetVal, strMethod, pArgs);
    if (strMethod == "getFilter") {
        CStringW strKind = pArgs->FUN_1422b8f40();
        int nKind = CAchieveData::ParseRewardType(strKind);
        int bEnabled = 1;
        m_198.Lookup(nKind, bEnabled);
        Scaleform::GFx::Value value(bEnabled != 0);
        FUN_1409b4bc0(pRetVal, value);
    }
    else if (_stricmp("getTooltipColor", strMethod) == 0) {
        pArgs->FUN_1422b8b10();
        pArgs->FUN_1422b8b10();
        pArgs->FUN_1422b8b10();
        pArgs->FUN_1422b8b10();
        Scaleform::GFx::Value raw = pArgs->FUN_1422b9260();
        ASObj data(raw, 2);
        unsigned nPalette = FUN_1409c17e0(data.FUN_1422baa20("paletteID"));
        unsigned nSN = FUN_1409c17e0(data.FUN_1422baa20("colorSN"));
        Unk_AmColorElem elem = FUN_140281980()->FUN_140558960(nPalette, nSN);
        if (elem.m_p != 0) {
            CStringW strDesc;
            if (elem.FUN_14056d570()->m_nColorId != 0) {
                int nKey = elem.FUN_14056d570()->m_nColorId;
                CStringW strName = FUN_1401a9d70()->FUN_141811980(0x48, nKey);
                if (!strName.IsEmpty()) {
                    strDesc = FUN_1408f71a0(CStringW(L"s_beauty_tooltip_color_desc"), strName, FUN_1401a9d70()->FUN_141811980(0x49, nKey));
                    strDesc.Append(L"\n");
                }
                ASTooltip tip(1, 2);
                if (tip.FUN_1409e26b0(strDesc) != 0) {
                    tip.FUN_1409c6dc0(1);
                    FUN_1409b4bc0(pRetVal, tip.FUN_1422bb870());
                }
            }
        }
    }
    else if (_stricmp("getTooltipAchieve", strMethod) == 0) {
        void* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
        unsigned nId = pArgs->FUN_1422b8b10();
        unsigned nGrade = pArgs->FUN_1422b8b10();
        ASTooltip tip(pPlayer, 2, 2);
        if (tip.FUN_1409e21a0(nId, nGrade) != 0) {
            tip.FUN_1407cbb20("comment", FUN_14028de60(0x781));
            FUN_1409b4bc0(pRetVal, tip.FUN_1422bb870());
        }
    }
}

// @0x1418a8f80
void UIAchieveDialog::FUN_1418a8f80()
{
    if (FUN_140a467d0(&m_30))
        return;
    FUN_1418ac710(m_178);
    FUN_1418a8ff0();
    FUN_1418a9800();
    m_1e0.RemoveAll();
}

// @0x1418a8ff0
void UIAchieveDialog::FUN_1418a8ff0()
{
    if (FUN_140a467d0(&m_30))
        return;
    MS2Ptr<CAchieveCategory> spCategory = CAchieveCategory::FindById(m_17c);
    if (spCategory.IsNull())
        return;
    {
        MS2Ptr<Unk_AcHero> spHero = FUN_140ede180("m_heroTrophy");
        if (spHero.get() != 0) {
            if (spCategory->m_nTab == 0)
                spHero->vfunc_13("search_filter");
            else if (spCategory->m_nTab == 2)
                spHero->vfunc_13("search");
        }
    }
    FilterOptions options;
    switch (spCategory->m_nTab) {
    case 0:
        AC_ROOT(m_30)->FUN_140e262c0("gotoAndPlay", "hero");
        options.m_survival = 0;
        options.m_categoryTag = spCategory->m_strCategoryTag;
        options.m_contentsTag = spCategory->m_strContentsTag;
        options.m_filter = FUN_1418ac480();
        FUN_1418aa190(&options);
        break;
    case 1:
        AC_ROOT(m_30)->FUN_140e262c0("gotoAndPlay", "summary");
        FUN_1418a9c20();
        return;
    case 2:
        AC_ROOT(m_30)->FUN_140e262c0("gotoAndPlay", "hero");
        options.m_survival = 1;
        options.m_filter = FUN_1418ac480();
        FUN_1418aa190(&options);
        break;
    }
}

// @0x1418a9360
void UIAchieveDialog::FUN_1418a9360()
{
    if (FUN_140a467d0(&m_30))
        return;
    ASObj tree(2);
    ASArray nodes(2);
    tree.FUN_140e35d00("type", 1);
    tree.FUN_1409eb1d0("nodes", nodes);
    CAchieveCategory::List roots;
    CAchieveCategory::GetTabs(roots);
    for (size_t i = 0; i < roots.GetCount(); i++) {
        MS2Ptr<CAchieveCategory> spRoot = roots[i];
        ASObj node(2);
        node.FUN_1407cb9c0("id", spRoot->m_nId);
        node.FUN_1407cbb20("label", FUN_1401a9d70()->FUN_141811980(0x4a, spRoot->m_nId));
        node.FUN_1409c0dc0("rendererClassName", "export_renderer_category");
        FUN_1418ae010(node, "tabType", spRoot->m_nTab);
        node.FUN_1407cbbe0("alwaysOpen", spRoot->m_nTree == 2);
        node.FUN_140e35d00("type", spRoot->m_nTree == 1 ? 2 : 1);
        ASArray children(2);
        for (size_t j = 0; j < spRoot->m_aChildren.GetCount(); j++) {
            MS2Ptr<CAchieveCategory> spChild = spRoot->m_aChildren[j];
            ASObj row(2);
            row.FUN_1407cb9c0("id", spChild->m_nId);
            row.FUN_1407cbb20("label", FUN_1401a9d70()->FUN_141811980(0x4a, spChild->m_nId));
            row.FUN_1409c0dc0("rendererClassName", "export_renderer_category_low");
            FUN_1418ae010(row, "tabType", spChild->m_nTab);
            children.FUN_1422bbf00(row);
        }
        if (children.FUN_1422bc5d0() != 0)
            node.FUN_1409eb1d0("nodes", children);
        nodes.FUN_1422bbf00(node);
    }
    FUN_1409ee290(&m_30)->Invoke("setCategory", tree);
}

// @0x1418a9800
void UIAchieveDialog::FUN_1418a9800()
{
    if (FUN_140a467d0(&m_30))
        return;
    CAchieveList achieves;
    CAchieveCategory::List roots;
    CAchieveCategory::GetRows(roots);
    FUN_1406c7600()->GetList(achieves, 0, 0, 0, 0);
    std::vector<std::pair<int, int> > counts;
    for (size_t i = 0; i < roots.GetCount(); i++) {
        int nZero = 0;
        counts.push_back(std::make_pair(roots[i]->m_nId, nZero));
    }
    for (size_t i = 0; i < achieves.GetCount(); i++) {
        MS2Ptr<CAchieve> spAchieve = achieves[i];
        if (spAchieve->GetType() == 8)
            continue;
        int nRewards = spAchieve->GetRewardCount();
        if (nRewards == 0)
            continue;
        for (size_t j = 0; j < roots.GetCount(); j++) {
            unsigned nId = spAchieve->GetId();
            if (roots[j]->Matches(nId))
                counts[j].second += nRewards;
        }
    }
    for (size_t i = 0; i < counts.size(); i++) {
        CStringW strTitle = FUN_1401a9d70()->FUN_141811980(0x4a, counts[i].first);
        if (counts[i].second > 0)
            strTitle.Append(FUN_1408116a0(0x784, counts[i].second));
        AC_ROOT(m_30)->FUN_14129cce0("setRewardCount", counts[i].first, CStringW(strTitle));
    }
}

// @0x1418a9c20
void UIAchieveDialog::FUN_1418a9c20()
{
    MS2Ptr<Unk_AcHero> spSummary = FUN_140ede180("m_summaryTrophy");
    if (spSummary.get() == 0)
        return;
    spSummary->Invoke("removeAll");
    std::vector<ClearRecord> records;
    FUN_1418adae0(records);
    unsigned char nIndex = 0;
    for (std::vector<ClearRecord>::iterator it = records.begin(); it != records.end(); ++it) {
        ASObj row(2);
        MS2Ptr<CAchieve> spAchieve = FUN_1406c7600()->Find(it->m_id);
        MS2Ptr<CAchieveData> spData = spAchieve->GetDataRef();
        if (spData.IsNull())
            continue;
        if (!spData->IsAvailable())
            continue;
        CStringW strDesc = FUN_1418aac30(spAchieve, it->m_grade);
        FUN_141842290(strDesc);
        row.FUN_1409c0d20("id", spAchieve->GetId());
        row.FUN_1407cba60("icon", spAchieve->GetName(1));
        row.FUN_1407cb9c0("grade", it->m_grade);
        row.FUN_1407cbb20("date", FUN_14093e330(spAchieve, it->m_grade));
        row.FUN_1407cbb20("title", FUN_14093b970(spAchieve->GetId()));
        row.FUN_1407cbb20("desc", CStringW(strDesc));
        spSummary->FUN_1418adea0("setTrophy", nIndex, row);
        if (nIndex++ > 11)
            break;
    }
    Unk_AchieveTab* pTally = FUN_1406c7600()->GetTally();
    int nA = pTally->m_n[0];
    int nB = pTally->m_n[1];
    int nC = pTally->m_n[2];
    spSummary->Invoke("setScore", nA, nB, nC);
}

// @0x1418aa190
void UIAchieveDialog::FUN_1418aa190(const FilterOptions* pOptions)
{
    MS2Ptr<Unk_AcHero> spHero = FUN_140ede180("m_heroTrophy");
    if (spHero.IsNull())
        return;
    MS2Ptr<Unk_AcList> spList = spHero->FUN_140bc7280("m_list");
    if (spList.IsNull())
        return;
    spList->FUN_1422dd1d0();
    CStringW strSearch = FUN_1418aad60();
    int nSelected = 0;
    int nCount = 0;
    CAchieveList achieves;
    FUN_1406c7600()->GetListFromTable(achieves, 0, 0, 0, 0);
    if (achieves.GetCount() == 0) {
        ASObj row(2);
        row.FUN_1409c0dc0("state", "empty");
        spList->FUN_1422dd230(row);
    }
    else {
        ATL::CRBMap<unsigned __int64, MS2Ptr<CAchieve> > sorted(10);
        for (size_t i = 0; i < achieves.GetCount(); i++) {
            MS2Ptr<CAchieve> spAchieve = achieves[i];
            if (FUN_1418ace00(spAchieve, strSearch, pOptions) == 0)
                continue;
            int nState = FUN_1418ac8f0(spAchieve);
            unsigned nOrder = (unsigned)i;
            sorted.SetAt(((unsigned __int64)nState << 32) | nOrder, spAchieve);
        }
        POSITION pos = sorted.GetHeadPosition();
        while (pos != 0) {
            MS2Ptr<CAchieve> spAchieve = sorted.GetValueAt(pos);
            ASObj row(2);
            FUN_1418ab7e0(row, spAchieve);
            spList->FUN_1422dd230(row);
            nCount++;
            sorted.GetNext(pos);
        }
        if (nCount == 0) {
            ASObj row(2);
            row.FUN_1409c0dc0("state", "empty");
            row.FUN_1407cb9c0("search", 1);
            spList->FUN_1422dd230(row);
        }
    }
    spList->FUN_1422dcca0(nSelected);
    spList->vfunc_24(true);
    static_cast<ASObj*>(static_cast<AScript*>(spList.get()))->FUN_1407cb9c0("scrollPosition", 0);
}

// @0x1418aa660
void UIAchieveDialog::FUN_1418aa660(int nId)
{
    if (FUN_140a467d0(&m_30))
        return;
    MS2Ptr<CAchieve> spAchieve = FUN_1406c7600()->Find(nId);
    if (spAchieve.IsNull())
        return;
    FUN_1418a9800();
    MS2Ptr<CAchieveCategory> spCategory = CAchieveCategory::FindById(m_17c);
    if (spCategory.IsNull())
        return;
    int nTab = spCategory->m_nTab;
    if (nTab == 1) {
        FUN_1418a9c20();
        return;
    }
    if (nTab != 0 && nTab != 2)
        return;
    if (spCategory->Matches(nId)) {
        MS2Ptr<Unk_AcHero> spHero = FUN_140ede180("m_heroTrophy");
        if (spHero.get() != 0) {
            ASObj row(2);
            FUN_1418ab7e0(row, spAchieve);
            spHero->Invoke("updateAchieve", row);
        }
    }
}

// @0x1418aa890
void UIAchieveDialog::FUN_1418aa890()
{
    CStringW strSearch = FUN_1418aad60();
    if (strSearch.IsEmpty())
        return;
    Unk_AcRequest request(0x4e73);
    request.FUN_1401bac80("m_searchInput", CStringW(strSearch), 0);
    if (FUN_140d86260()->vfunc_37(&request) == 1)
        FUN_1418a8ff0();
}

// @0x1418aa9b0
void UIAchieveDialog::FUN_1418aa9b0(int nId)
{
    m_188 = FUN_14093b970(nId);
    m_178 = FUN_1418ac320(nId);
    MS2Ptr<CAchieveCategory> spCategory = CAchieveCategory::GetRow(m_178);
    if (spCategory)
        m_17c = spCategory->m_nId;
    if (vfunc_55()) {
        m_180 = 0;
        FUN_141924680();
    }
    else {
        FUN_1418ac5f0(0);
        FUN_1418aaee0(m_188);
        FUN_1418ac710(m_178);
        FUN_1418a8ff0();
    }
}

// @0x1418aaaf0
CStringW UIAchieveDialog::FUN_1418aaaf0(CAchieve* pAchieve)
{
    if (pAchieve == 0)
        return CStringW(L"");
    if (FUN_1418aca90(pAchieve) == 0)
        return CStringW(L"normal");
    return CStringW(L"complete");
}

// @0x1418aaba0
int UIAchieveDialog::FUN_1418aaba0(CAchieve* pAchieve)
{
    if (pAchieve == 0)
        return 0;
    return pAchieve->GetRewardCount();
}

// @0x1418aabd0
CStringW UIAchieveDialog::FUN_1418aabd0(CAchieve* pAchieve)
{
    return FUN_1418aac30(pAchieve, pAchieve->GetCurGrade());
}

// @0x1418aac30
CStringW UIAchieveDialog::FUN_1418aac30(CAchieve* pAchieve, int nGrade)
{
    bool bSecret = false;
    if (FUN_1418aca90(pAchieve) != 0) {
        MS2Ptr<CAchieveData> spData = pAchieve->GetDataRef();
        bSecret = nGrade == spData->m_nMaxGrade;
    }
    if (bSecret)
        return FUN_14093c320(pAchieve);
    return FUN_14093c8d0(pAchieve->GetId(), nGrade, 1);
}

// @0x1418aad60
CStringW UIAchieveDialog::FUN_1418aad60()
{
    MS2Ptr<Unk_AcHero> spHero = FUN_140ede180("m_heroTrophy");
    if (spHero.get() != 0) {
        MS2Ptr<Unk_AcText> spInput = spHero->FUN_140bbe880("m_searchInput");
        if (spInput.get() != 0)
            return spInput->FUN_1422e0b00();
    }
    return CStringW(L"");
}

// @0x1418aaee0
void UIAchieveDialog::FUN_1418aaee0(const CStringW& strText)
{
    MS2Ptr<Unk_AcHero> spHero = FUN_140ede180("m_heroTrophy");
    if (spHero.get() != 0) {
        MS2Ptr<Unk_AcText> spInput = spHero->FUN_140bbe880("m_searchInput");
        if (spInput.get() != 0)
            spInput->FUN_1422e0ab0(strText);
    }
}

// @0x1418ab000
void UIAchieveDialog::FUN_1418ab000(ASObj& rRow, CAchieve* pAchieve)
{
    CStringW strReward = FUN_14093cdb0(pAchieve->GetDataRef()->m_nId);
    if (strReward.GetLength() > 0) {
        strReward = FUN_1405c2690(CStringW(L"s_achieve_reward"), strReward);
        if (FUN_140166410()->FUN_14036d570(0xbb)) {
            Unk_AchieveReward* pReward = pAchieve->GetReward();
            if (pReward != 0 && pReward->m_nType == 8) {
                strReward = FUN_1405c2690(CStringW(L"s_achieve_reward_item_coloring"), strReward);
                int nPalette = pReward->m_nCode;
                Unk_AmColorSet set = FUN_140281980()->FUN_140558ad0(nPalette);
                if (set.FUN_14056d460() != 0) {
                    int nIndex = 0;
                    for (unsigned i = 0; i < set.FUN_14056d540()->FUN_140570e10(); i++) {
                        Unk_AmColorElem elem(set.FUN_14056d540()->FUN_140570dd0(i));
                        if (elem.FUN_14056d570()->m_nAchieveId == (int)pAchieve->GetId()) {
                            if (elem.FUN_14056d570()->m_nGrade == pAchieve->GetStartGrade()) {
                                ASObj palette(2);
                                palette.FUN_1409c0d20("paletteID", nPalette);
                                palette.FUN_1409c4990("realColor", elem.FUN_14056d570()->m_real);
                                palette.FUN_1409c4990("visibleColor", elem.FUN_14056d570()->m_visible);
                                palette.FUN_1409c4990("ch2Color", elem.FUN_14056d570()->m_ch2);
                                palette.FUN_1407cb9c0("colorSN", elem.FUN_14056d570()->m_nSN);
                                if (elem.FUN_14056d570()->m_bHasSecond != 0) {
                                    palette.FUN_1409c4990("realColor2", elem.FUN_14056d570()->m_ch2);
                                    palette.FUN_1409c4990("visibleColor2", elem.FUN_14056d570()->m_ch2);
                                }
                                int nSlot = nIndex++;
                                CString strName = FUN_1402bad60("palette{0}", &nSlot);
                                FUN_1418adf60(rRow, strName, AScript(palette));
                            }
                        }
                    }
                }
            }
        }
        rRow.FUN_1407cbb20("reward", CStringW(strReward));
    }
}

// @0x1418ab520
void UIAchieveDialog::FUN_1418ab520(ASObj& rRow, CAchieve* pAchieve)
{
    MS2Ptr<CAchieveData> spData = pAchieve->GetDataRef();
    if (spData.IsNull())
        return;
    int nGrade;
    if (pAchieve->GetState() == 3)
        nGrade = pAchieve->GetCurGrade();
    else if (FUN_1418ac870(pAchieve) == 0)
        nGrade = pAchieve->GetStartGrade();
    else
        nGrade = pAchieve->GetCurGrade() - 1;
    rRow.FUN_1409c0d20("id", pAchieve->GetId());
    rRow.FUN_1407cbb20("desc", FUN_1418aac30(pAchieve, nGrade));
    rRow.FUN_1407cbb20("name", FUN_14093b970(pAchieve->GetId()));
    if (FUN_1418aca90(pAchieve) == 0) {
        __int64 nCur = pAchieve->GetProgress();
        __int64 nMax = pAchieve->GetGradeGoal(nGrade);
        if (nMax < nCur)
            nCur = nMax;
        rRow.FUN_1409c1180("cur", nCur);
        rRow.FUN_1409c1180("max", nMax);
        rRow.FUN_1407cb9c0("grade", nGrade);
        rRow.FUN_1407cbb20("progress", FUN_14093bf10(pAchieve, nGrade));
        if (DAT_143ab2914 > 49)
            rRow.FUN_1407cbbe0("debug", FUN_14116d720(FUN_14025e7c0()));
    }
    else {
        rRow.FUN_1407cb9c0("grade", 11);
    }
}

// @0x1418ab7e0
void UIAchieveDialog::FUN_1418ab7e0(ASObj& rRow, CAchieve* pAchieve)
{
    if (FUN_141bd0cc0(FUN_1403ed2d0()) == 0)
        return;
    unsigned nItem = 0;
    Unk_AchieveReward* pReward = pAchieve->GetReward();
    if (pReward != 0 && pReward->m_nType == 1)
        nItem = pReward->m_nCode;
    FUN_1418ab520(rRow, pAchieve);
    FUN_1418ab000(rRow, pAchieve);
    rRow.FUN_1407cbb20("date", FUN_14093e330(pAchieve, pAchieve->GetCurGrade()));
    rRow.FUN_1407cbb20("state", FUN_1418aaaf0(pAchieve));
    rRow.FUN_1407cb9c0("count", FUN_1418aaba0(pAchieve));
    rRow.FUN_1407cba60("icon", pAchieve->GetName(0));
    rRow.FUN_1407cb9c0("bookmark", pAchieve->GetBookmark());
    rRow.FUN_1409c0d20("tooltipItem", nItem);
    rRow.FUN_1407cb9c0("expand", FUN_1418acca0(pAchieve->GetId()));
    rRow.FUN_1407cb9c0("expandAble", 1);
    rRow.FUN_1407cb9c0("disabled", FUN_1418acce0(pAchieve));
    FUN_1418abaa0(rRow, pAchieve);
    FUN_1418abc60(rRow, pAchieve);
    FUN_1418abfa0(rRow, pAchieve);
}

// the list of the collected ids of the grade the trophy is at
static ATL::CAtlArray<__int64>* AcCollectedIds(CAchieve* pAchieve);

// @0x1418abaa0
void UIAchieveDialog::FUN_1418abaa0(ASObj& rRow, CAchieve* pAchieve)
{
    int nType = pAchieve->GetCondType();
    if (FUN_1418ad560(nType) == 0)
        return;
    ATL::CAtlArray<__int64>* pIds = AcCollectedIds(pAchieve);
    if (pIds == 0 || pIds->GetCount() == 0)
        return;
    ASArray list(2);
    for (size_t i = 0; i < pIds->GetCount(); i++) {
        unsigned nId = (unsigned)pIds->GetAt(i);
        ASObj item(2);
        item.FUN_1407cbb20("condition", FUN_1418ad5d0(pAchieve->GetCondType(), nId));
        item.FUN_1407cb9c0("complete", FUN_1418ad960(pAchieve->GetCondType(), nId));
        list.FUN_1422bbf00(item);
    }
    rRow.FUN_1409eb1d0("reqCondition", list);
}

// @0x1418abc60
void UIAchieveDialog::FUN_1418abc60(ASObj& rRow, CAchieve* pAchieve)
{
    int nType = pAchieve->GetCondType();
    if (nType != 0x5e && nType != 0x61 && nType != 0x62 && nType != 0x60)
        return;
    int nGrade = pAchieve->GetCurGrade();
    MS2Ptr<CAchieveData> spData = pAchieve->GetDataRef();
    if (spData.IsNull())
        return;
    MS2Ptr<CAchieveGradeData> spGrade = spData->GetGrade(nGrade);
    if (spGrade.IsNull())
        return;
    int nWantGrade = (int)spGrade->m_pCondition->m_target.GetFirstValue();
    ATL::CAtlArray<__int64>* pIds = AcCollectedIds(pAchieve);
    if (pIds == 0)
        return;
    ASArray list(2);
    for (size_t i = 0; i < pIds->GetCount(); i++) {
        unsigned nId = (unsigned)pIds->GetAt(i);
        MS2Ptr<CAchieveData> spOther = GetAchieveData(nId);
        if (spOther.get() == 0)
            continue;
        int nReqGrade = nWantGrade;
        if (nWantGrade == 0)
            nReqGrade = spOther->m_nMaxGrade;
        ASObj item(2);
        item.FUN_1409c0d20("id", nId);
        item.FUN_1407cbb20("trophy", FUN_14093b970(nId));
        item.FUN_1407cb9c0("complete", FUN_1406c7600()->IsGradeCleared(nId, nReqGrade));
        item.FUN_1407cb9c0("grade", nReqGrade);
        list.FUN_1422bbf00(item);
    }
    rRow.FUN_1409eb1d0("reqAchieve", list);
}

// @0x1418abfa0
void UIAchieveDialog::FUN_1418abfa0(ASObj& rRow, CAchieve* pAchieve)
{
    if (FUN_141bd0cc0(FUN_1403ed2d0()) == 0)
        return;
    MS2Ptr<CAchieveData> spData = pAchieve->GetDataRef();
    if (spData.IsNull())
        return;
    int nFirst = spData->m_nFirstGrade;
    int nLast = spData->m_nMaxGrade;
    if (FUN_1418ac870(pAchieve) != 0 && pAchieve->GetState() != 3)
        nLast = pAchieve->GetCurGrade() - 1;
    ASArray list(2);
    for (int nGrade = nFirst; nGrade <= nLast; nGrade++) {
        int bComplete = pAchieve->GetValue(nGrade) != 0;
        ASObj item(2);
        item.FUN_1409c0d20("id", pAchieve->GetId());
        item.FUN_1407cb9c0("grade", nGrade);
        item.FUN_1407cba60("icon", pAchieve->GetName(0));
        item.FUN_1407cb9c0("complete", bComplete);
        MS2Ptr<CAchieveGradeData> spGrade = spData->GetGrade(nGrade);
        if (spGrade.get() != 0 && spGrade->m_reward.m_nType != 0 && !m_190) {
            int nChecked = 0;
            if (m_198.Lookup(spGrade->m_reward.m_nType, nChecked))
                item.FUN_1407cb9c0("checked", nChecked);
        }
        list.FUN_1422bbf00(item);
    }
    rRow.FUN_1409eb1d0("clearAchieve", list);
}

// @0x1418ac320
int UIAchieveDialog::FUN_1418ac320(int nId)
{
    MS2Ptr<CAchieveData> spData = GetAchieveData(nId);
    if (spData.IsNull())
        return -1;
    CAchieveCategory::List roots;
    CAchieveCategory::GetRows(roots);
    int nTab = 0;
    for (size_t i = 0; i < roots.GetCount(); i++) {
        MS2Ptr<CAchieveCategory> spRoot = roots[i];
        if (spRoot->Matches(nId))
            return nTab;
        nTab++;
    }
    return -1;
}

// @0x1418ac480
int UIAchieveDialog::FUN_1418ac480()
{
    MS2Ptr<Unk_AcHero> spHero = FUN_140ede180("m_heroTrophy");
    if (spHero.get() != 0) {
        MS2Ptr<Unk_AcDrop> spFilter = spHero->FUN_140bbe700("m_filter");
        if (spFilter.get() != 0) {
            if (!spFilter->FUN_1422bfca0())
                return 4;
            return spFilter->FUN_1422df6c0();
        }
    }
    return 4;
}

// @0x1418ac5f0
void UIAchieveDialog::FUN_1418ac5f0(int nIndex)
{
    MS2Ptr<Unk_AcHero> spHero = FUN_140ede180("m_heroTrophy");
    if (spHero.get() != 0) {
        MS2Ptr<Unk_AcDrop> spFilter = spHero->FUN_140bbe700("m_filter");
        if (spFilter.get() != 0)
            spFilter->FUN_1422df690(nIndex);
    }
}

// @0x1418ac710
void UIAchieveDialog::FUN_1418ac710(int nTab)
{
    if (!FUN_140a467d0(&m_30))
        AC_ROOT(m_30)->FUN_1409ba030("setTabIndex", m_178);
}

// @0x1418ac780
int UIAchieveDialog::FUN_1418ac780(CAchieve* pAchieve)
{
    if (FUN_14116d720(FUN_14025e7c0()))
        return 0;
    if (pAchieve == 0)
        return 0;
    MS2Ptr<CAchieveData> spData = pAchieve->GetDataRef();
    if (spData.IsNull())
        return 0;
    if (spData->m_nLocking != 0)
        return 1;
    if (pAchieve->CheckRequire() != 0)
        return 1;
    return 0;
}

// @0x1418ac870
int UIAchieveDialog::FUN_1418ac870(CAchieve* pAchieve)
{
    if (FUN_1418ac780(pAchieve) == 0)
        return 0;
    if (pAchieve->GetState() == 3)
        return 1;
    if (pAchieve->CanRewardData68() != 0)
        return 1;
    if (pAchieve->CanRewardRequire() != 0)
        return 1;
    return 0;
}

// @0x1418ac8f0
int UIAchieveDialog::FUN_1418ac8f0(CAchieve* pAchieve)
{
    MS2Ptr<CAchieveData> spData = pAchieve->GetDataRef();
    if (spData.IsNull())
        return 0;
    if (pAchieve->GetRewardCount() != 0)
        return 0;
    if (pAchieve->GetState() == 3)
        return 2;
    if (FUN_1418ac870(pAchieve) != 0)
        return 2;
    return 1;
}

// @0x1418ac9e0
int UIAchieveDialog::FUN_1418ac9e0()
{
    MS2Ptr<Unk_AcList> spTabs = FUN_140c02900("m_tabList");
    if (spTabs.get() == 0)
        return 0;
    return spTabs->FUN_1422dccd0();
}

// @0x1418aca90
int UIAchieveDialog::FUN_1418aca90(CAchieve* pAchieve)
{
    if (pAchieve->IsGradeReached() != 0)
        return 0;
    if (FUN_1418ac870(pAchieve) != 0)
        return 1;
    if (pAchieve->GetValue80() < 1)
        return 0;
    return 1;
}

// @0x1418acaf0
int UIAchieveDialog::FUN_1418acaf0()
{
    MS2Ptr<Unk_AcHero> spHero = FUN_140ede180("m_heroTrophy");
    if (spHero.get() != 0) {
        MS2Ptr<Unk_AcDrop> spFilter = spHero->FUN_140bbe700("m_filter");
        if (spFilter.get() != 0) {
            if (!spFilter->FUN_1422bfca0())
                return 0;
            if (spFilter->FUN_1422df6c0() != 0)
                return 0;
            return 1;
        }
    }
    return 0;
}

// @0x1418acca0
int UIAchieveDialog::FUN_1418acca0(int nId)
{
    int nExpanded = 0;
    m_1e0.Lookup(nId, nExpanded);
    return nExpanded;
}

// @0x1418acce0
int UIAchieveDialog::FUN_1418acce0(CAchieve* pAchieve)
{
    pAchieve->GetState();
    return 0;
}

// @0x1418acd10
int UIAchieveDialog::FUN_1418acd10(int nId)
{
    MS2Ptr<CAchieve> spAchieve = FUN_1406c7600()->Find(nId);
    if (spAchieve.IsNull())
        return 0;
    __int64 nProgress = spAchieve->GetProgress();
    __int64 nGoal = spAchieve->GetGradeGoal(spAchieve->GetStartGrade());
    if (nProgress < nGoal)
        return 1;
    return 0;
}

// @0x1418ace00
int UIAchieveDialog::FUN_1418ace00(CAchieve* pAchieve, const CStringW& strSearch, const FilterOptions* pOptions)
{
    if (pAchieve == 0)
        return 0;
    MS2Ptr<CAchieveData> spData = pAchieve->GetDataRef();
    if (spData.IsNull())
        return 0;
    int nState = pAchieve->GetState();
    if (FUN_1418ac870(pAchieve) != 0)
        nState = 3;
    if (pAchieve->GetType() == 8) {
        if (!FUN_14116d720(FUN_14025e7c0()))
            return 0;
    }
    if (!m_190) {
        int bAny = 0;
        for (int nGrade = spData->m_nFirstGrade; nGrade <= spData->m_nMaxGrade; nGrade++) {
            MS2Ptr<CAchieveGradeData> spGrade = spData->GetGrade(nGrade);
            if (spGrade.IsNull())
                continue;
            int bShown = 0;
            m_198.Lookup(spGrade->m_reward.m_nType, bShown);
            if (bShown != 0) {
                bAny = 1;
                break;
            }
        }
        if (bAny == 0)
            return 0;
    }
    if (pOptions->m_survival == 0) {
        if (spData->m_nType == 9)
            return 0;
    }
    else {
        if (spData->m_nType != 9)
            return 0;
        if (pAchieve->IsGradeReached() == 0 && nState != 3) {
            if (!FUN_14116d720(FUN_14025e7c0()))
                return 0;
        }
    }
    if (pOptions->m_categoryTag.GetLength() != 0) {
        if (spData->m_strCategoryTag.Find(pOptions->m_categoryTag, 0) == -1)
            return 0;
    }
    if (pOptions->m_contentsTag.GetLength() != 0) {
        if (spData->m_strContentsTag.Find(pOptions->m_contentsTag, 0) == -1)
            return 0;
    }
    switch (pOptions->m_filter) {
    case 1:
        if (nState != 2 || pAchieve->IsStarted() == 0)
            return 0;
        break;
    case 2:
        if (nState != 3)
            return 0;
        break;
    case 3:
        if (pAchieve->GetBookmark() == 0)
            return 0;
        break;
    }
    if (strSearch.GetLength() != 0) {
        CStringW strTitle = FUN_14093b970(pAchieve->GetId());
        CStringW strDesc = FUN_1418aabd0(pAchieve);
        CStringW strExtra = FUN_14093cdb0(pAchieve->GetId());
        FUN_14083d2b0(strTitle);
        FUN_14083d2b0(strDesc);
        FUN_14083d2b0(strExtra);
        if (FUN_14083fec0(strTitle, strSearch) == -1
            && FUN_14083fec0(strDesc, strSearch) == -1
            && FUN_14083fec0(strExtra, strSearch) == -1)
            return 0;
    }
    if (FUN_1418ac780(pAchieve) == 0 || FUN_1418ac870(pAchieve) != 0)
        return 1;
    return 0;
}

// @0x1418ad560
int UIAchieveDialog::FUN_1418ad560(int nCondType)
{
    if (nCondType < 0x3c) {
        if (nCondType == 0x3b || nCondType == 8 || nCondType == 10 || nCondType == 0x31)
            return 1;
    }
    else {
        if (nCondType == 0xc5)
            return 1;
        if (nCondType == 0xd1)
            return 1;
        if (nCondType == 0x10a)
            return 1;
    }
    return 0;
}

// @0x1418ad5d0
CStringW UIAchieveDialog::FUN_1418ad5d0(int nCondType, unsigned nId)
{
    if (nCondType < 0x3c) {
        if (nCondType != 0x3b) {
            if (nCondType == 8 || nCondType == 10)
                return FUN_1401a9d70()->FUN_141811980(1, nId);
            if (nCondType != 0x31)
                return CStringW(L"");
        }
        return FUN_1416e4df0(nId);
    }
    if (nCondType == 0xc5) {
        MS2Ptr<Unk_AcRoom> spRoom = FUN_14031c2a0()->FUN_1403206b0(nId);
        if (spRoom.get() != 0) {
            CStringW strName = FUN_1401a9d70()->FUN_141811980(0x14, nId);
            CStringW strKind = FUN_140cbf840(spRoom->m_1c);
            return FUN_1408f71a0(CStringW(L"s_achieve_collectiong_dungeon_clear"), strKind, strName);
        }
    }
    else if (nCondType == 0xd1) {
        return FUN_1405c2690(CStringW(L"s_achieve_collectiong_fish_collect"), FUN_1401a9d70()->FUN_141811980(0x1d, nId));
    }
    else if (nCondType == 0x10a) {
        return FUN_1405c2690(CStringW(L"s_achieve_collectiong_pet_collect"), FUN_1401a9d70()->FUN_141811980(0x3b, nId));
    }
    return CStringW(L"");
}

// @0x1418ad960
int UIAchieveDialog::FUN_1418ad960(int nCondType, unsigned nId)
{
    if (nCondType < 0x3c) {
        if (nCondType != 0x3b) {
            if (nCondType == 8 || nCondType == 10)
                return DAT_143ab30e0.Lookup(nId) != 0;
            if (nCondType != 0x31)
                return 0;
        }
        return FUN_140764020()->m_10.FUN_140745590(nId);
    }
    if (nCondType == 0xc5) {
        MS2Ptr<Unk_AcDungeonMgr> spMgr = *FUN_140931510();
        return spMgr->FUN_140b22890(nId) != 0;
    }
    if (nCondType == 0xd1)
        return (int)FUN_140953f20()->FUN_140cdc380(nId);
    if (nCondType == 0x10a)
        return FUN_140535320()->FUN_140c8b220(nId) != 0;
    return 0;
}

// @0x1418adae0
static void AcCollectClears(std::vector<UIAchieveDialog::ClearRecord>& rRecords)
{
    CAchieveList achieves;
    FUN_1406c7600()->GetFirstList(achieves);
    for (size_t i = 0; i < achieves.GetCount(); i++) {
        MS2Ptr<CAchieve> spAchieve = achieves[i];
        int nGrade = spAchieve->GetDataRef()->m_nFirstGrade;
        while (nGrade <= spAchieve->GetCurGrade()) {
            __int64 nTime = spAchieve->GetValue(nGrade);
            if (nTime != 0) {
                UIAchieveDialog::ClearRecord record;
                record.m_time = nTime;
                record.m_id = spAchieve->GetId();
                record.m_grade = nGrade;
                rRecords.push_back(record);
            }
            nGrade++;
        }
    }
    std::sort(rRecords.begin(), rRecords.end(), AcClearOrder());
}

// @0x1418adcd0
static ATL::CAtlArray<__int64>* AcCollectedIds(CAchieve* pAchieve)
{
    MS2Ptr<CAchieveData> spData = pAchieve->GetDataRef();
    if (spData.IsNull())
        return 0;
    MS2Ptr<CAchieveGradeData> spGrade = spData->GetGrade(pAchieve->GetCurGrade());
    if (spGrade.IsNull())
        return 0;
    return &spGrade->m_pCondition->m_code.m_ids;
}

// @0x1418adea0
Scaleform::GFx::Value Unk_AcHero::FUN_1418adea0(const char* szMethod, unsigned char nIndex, const ASObj& row)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bccb0(args.FUN_1409b1f70(0), nIndex);
    FUN_1422bce40(args.FUN_1409b1f70(1), row);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x1418ae010
static void FUN_1418ae010(ASObj& rObj, const char* szName, int n)
{
    Scaleform::GFx::Value value((double)n);
    rObj.FUN_1409adbe0(szName, value);
}

// @0x1418adf60
static void FUN_1418adf60(ASObj& rObj, const CString& strName, const AScript& v)
{
    rObj.FUN_1409eb270(strName, static_cast<const ASObj&>(v));
}
