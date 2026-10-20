// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIMaidDialog ("MaidDialog", UI type 0x4e9d, 0x1f8 bytes) is the
// maid information window: portrait, affinity, mood, the profile texts and the editable profile. See uimaiddialog.h.
// MS2-UNIT: ?\uimaiddialog.cpp
// MS2-RANGE: 0x1400ee150-0x1400ee2f0 .text$di
// MS2-RANGE: 0x1412d7040-0x1412daa40 .text$mn
// MS2-GUESS-LOOKALIKES
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uimaiddialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uimaiddialog.h"

#include <atlcoll.h>

#include "ms2/client/ms2/uimessagebox.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/cnpc.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cusermaidmanager.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/commonfiles/npcdata.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

MS2_EMIT_CRT_MEMMOVE_S();

// ---- header statics (dynamic initializers 0x1400ee150..0x1400ee2c0) ----
#ifndef MS2_HOOK_DLL
static CString s_strSortNames7[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyInputController;
#endif

// ---- unit-local views of exe objects ----

class ASDialog : public ASDisplayObjectContainer
{
public:
    virtual void vfunc_2(int, int, int);                        // place the movie
    int FUN_1422c13b0();                                        // width
};

// The maid's record (CMaid, 0xf8 bytes; the shared header only declares the key and the level). View only.
class Unk_MaidView
{
public:
    int FUN_14067dca0();                                        // the affinity is at its maximum
    CStringW FUN_1409eeda0();                                   // the custom profile marker (empty: show the table profile)

    unsigned char m_pad_00[0x30];
    int m_nItemId;                                              // +0x30 the maid's item (its default rank is shown)
    int m_nMsgId;                                               // +0x34 the row key of the desc / info tables
    unsigned char m_pad_38[0x18];
    int m_nMood;                                                // +0x50
    int m_nLevel;                                               // +0x54 the affinity level
    unsigned char m_pad_58[8];
    int m_nExp;                                                 // +0x60 the affinity experience
    unsigned char m_pad_64[0x24];
    __int64 m_nExpireTime;                                      // +0x88 the contract end
    CStringW m_strTitle;                                        // +0x90
    unsigned char m_pad_98[8];
    CStringW m_strBirth;                                        // +0xa0
    CStringW m_strConstel;                                      // +0xa8
    CStringW m_strHeight;                                       // +0xb0
    CStringW m_strWeight;                                       // +0xb8
    unsigned char m_pad_c0[8];
    CStringW m_strSpecial;                                      // +0xc8
    CStringW m_strLike;                                         // +0xd0
    CStringW m_strHate;                                         // +0xd8
    CStringW m_strHobby;                                        // +0xe0
    CStringW m_strOwnerName;                                    // +0xe8
    CStringW m_strBelongTo;                                     // +0xf0
};
MS2_CHECK_SIZE(Unk_MaidView, 0xf8);
MS2_CHECK_OFFSET(Unk_MaidView, m_nItemId, 0x30);
MS2_CHECK_OFFSET(Unk_MaidView, m_nExp, 0x60);
MS2_CHECK_OFFSET(Unk_MaidView, m_nExpireTime, 0x88);
MS2_CHECK_OFFSET(Unk_MaidView, m_strTitle, 0x90);
MS2_CHECK_OFFSET(Unk_MaidView, m_strBelongTo, 0xf0);

// A row of the maid desc table (the table profile texts). View only.
class Unk_MaidDescRow
{
public:
    unsigned char m_pad_00[8];
    CStringW m_strTitle;                                        // +0x08
    CStringW m_strSpecialty;                                    // +0x10
    unsigned char m_pad_18[8];
    CStringW m_strBirth;                                        // +0x20
    CStringW m_strConstel;                                      // +0x28
    CStringW m_strHeight;                                       // +0x30
    CStringW m_strWeight;                                       // +0x38
    CStringW m_strSpecial;                                      // +0x40
    CStringW m_strLike;                                         // +0x48
    CStringW m_strHate;                                         // +0x50
    CStringW m_strHobby;                                        // +0x58
    CStringW m_strOwnerName;                                    // +0x60
    CStringW m_strBelongTo;                                     // +0x68
    CStringW m_strSpecialTitle;                                 // +0x70
    CStringW m_strBackground;                                   // +0x78
};
MS2_CHECK_OFFSET(Unk_MaidDescRow, m_strBelongTo, 0x68);
MS2_CHECK_OFFSET(Unk_MaidDescRow, m_strBackground, 0x78);

// A row of the maid info table (the salary). View only.
class Unk_MaidInfoRow
{
public:
    unsigned char m_pad_00[0xc];
    int m_nSalaryType;                                          // +0x0c
    int m_nSalary;                                              // +0x10
};
MS2_CHECK_OFFSET(Unk_MaidInfoRow, m_nSalary, 0x10);

// The 16 byte table handles (a pad and the pointer): the destructors / accessors are COMDATs of other units.
void FUN_14067e620(void* p);                                    // ~MS2Ptr<CMaid>
struct Unk_MaidRef
{
    ~Unk_MaidRef() { FUN_14067e620(this); }
    Unk_MaidView* FUN_14067e8c0() const;                        // operator->
    bool FUN_140d51d60() const;                                 // IsNull
    void* m_0; void* m_8;
};
void FUN_140680b50(void* p);
struct Unk_MaidDescRef
{
    ~Unk_MaidDescRef() { FUN_140680b50(this); }
    Unk_MaidDescRow* FUN_1406810d0() const;
    bool FUN_1409edcf0() const;                                 // IsNull
    void* m_0; void* m_8;
};
void FUN_140680b80(void* p);
struct Unk_MaidInfoRef
{
    ~Unk_MaidInfoRef() { FUN_140680b80(this); }
    Unk_MaidInfoRow* FUN_1406810e0() const;
    bool FUN_1409edd20() const;                                 // IsNull
    void* m_0; void* m_8;
};

class Unk_MaidDescTable { public: Unk_MaidDescRef FUN_14067f780(int nMsgId); };
class Unk_MaidInfoTable { public: Unk_MaidInfoRef FUN_14067f180(int nMsgId); };
class Unk_MaidExpTable { public: int FUN_14067ed30(int nLevel); };    // the experience of one affinity level
Unk_MaidDescTable* FUN_1409eed10();
Unk_MaidInfoTable* FUN_1409eed20();
Unk_MaidExpTable* FUN_14067e910();

// The maid npc (CNpc): the maid record and the name / title texts.
class Unk_MaidNpcView
{
public:
    Unk_MaidRef FUN_141093800();                                // the maid record
    CStringW FUN_141093310();                                   // the display name
    CStringW FUN_141093980();                                   // the title
};

class Unk_MaidWorld
{
public:
    void* FUN_141bd0cc0();                                      // the local player
    PCBase* FUN_141bd1320(int nActorId);                        // an actor by object id
};
Unk_MaidWorld* FUN_1403ed2d0();
CInputKeyHandler* FUN_14025e7c0();                              // the key handler singleton

class Unk_MaidBgSvc { public: void FUN_1416fb340(CStringW& strPath); };    // resolve a background path
Unk_MaidBgSvc* FUN_1403b4750();

// The game constants (0xa118: the maxChars1 limits, 0xa1c8: the maxChars2 limits). View only.
struct Unk_MaidLimitBox { unsigned char m[0xb0]; };
class Unk_MaidConsts
{
public:
    unsigned char m_pad_00[0xa118];
    Unk_MaidLimitBox m_maxChars1;                               // +0xa118
    Unk_MaidLimitBox m_maxChars2;                               // +0xa1c8
};
Unk_MaidConsts* FUN_1401d3200();
int* FUN_1402056b0(Unk_MaidLimitBox* pBox);

// The unit-local view of the profile edit buffer: the 13 texts.
struct Unk_MaidProfileFields
{
    CStringW m_str00, m_str08, m_str10, m_str18, m_str20, m_str28, m_str30, m_str38, m_str40, m_str48, m_str50, m_str58, m_str60;
};
MS2_CHECK_SIZE(Unk_MaidProfileFields, 0x68);

class Unk_MaidTextCheck { public: int FUN_140225470(const CStringW& str, CStringW& strOut); int FUN_140225550(const CStringW& str, CStringW& strOut); };
class Unk_MaidTextSvc { public: Unk_MaidTextCheck* FUN_140229a50(); };
Unk_MaidTextSvc* FUN_14025e7d0();

CStringW FUN_14028de60(int nStringId);                          // string table text by id
CStringW FUN_140656190(const wchar_t* pszFormat, const CStringW& strArg0, const CStringW& strArg1);
CStringW FUN_1408116a0(int nId, const int& nArg);               // formatted system text
CStringW FUN_140811740(int nId, const int& nArg1, const int& nArg2);
CStringW FUN_1409e90c0(int nId, const int& n1, const int& n2, const int& n3, const int& n4, const int& n5);
CStringW FUN_140763e10(int nNumber);                            // a number with digit grouping
const int& FUN_1404eb7e0(const int& a, const int& b);           // std::max<int>
int FUN_14053feb0(int nItemId);                                 // default rank of an item
__int64 FUN_140869440();                                        // the server time
void FUN_140d73bc0(int nStrId, int nType, void* pListener, CStringW strTag);   // pop the system message
void FUN_140d73aa0(CStringW text, int nA, int nB, CStringW strTag);     // pop the notice
int FUN_1418fc760(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned nArgs, int n);
void FUN_14151f200();
int FUN_1403b3c40(const CStringW& str, const wchar_t* psz);
void FUN_140710590(COutPacket& packet);                         // send
class Unk_MaidRefPos { public: int FUN_141b1d3d0(); int FUN_141b1d460(); };
Unk_MaidRefPos* FUN_140a7b2b0(int nId);                         // a dialog's position record

// The "int" setters of ASObj used here only exist in the shared header; the exe calls them from this unit.

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x1412d7040
UIMaidDialog::UIMaidDialog()
    : m_nMaidId(0), m_nMaidUid(0)
{
    m_2c = 0xc;
    FUN_1422dc3b0(1);
    FUN_141924170(1);
}

// @0x1412d7100
UIMaidDialog::~UIMaidDialog()
{
}

// @0x1412d7170
CString UIMaidDialog::vfunc_1()
{
    return "MaidDialog";
}

// @0x1412d71c0
int UIMaidDialog::vfunc_65()
{
    if (!UIDialog::vfunc_65())
        return 0;
    return 1;
}

// @0x1412d71f0
void UIMaidDialog::vfunc_67()
{
    m_nMaidId = 0;
    m_nMaidUid = 0;
    vfunc_47(1);
    UIDialog::vfunc_67();
}

// @0x1412d7250
int UIMaidDialog::vfunc_13()
{
    if (vfunc_55() != 0)
        return 0;
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
    {
        if (FUN_14025e7c0()->FUN_14116d9c0(0xf, 0, 0))
        {
            pDialog->Invoke("onTabKey");
            return 1;
        }
    }
    return 0;
}

// @0x1412d7310
// MS2-FUNCTIONAL: not byte-exact yet (call-result temporaries / frame-slot order differ)
void UIMaidDialog::vfunc_43()
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    Unk_MaidRefPos* pRef;
    if (pDialog != 0 && (pRef = FUN_140a7b2b0(0x4e40)) != 0)
    {
        int nX = pRef->FUN_141b1d3d0();
        int nY = pRef->FUN_141b1d460();
        if (nY - 0x14 != -1 && nX != -1)
        {
            pDialog->vfunc_2(5, nY - 0x14, nX - pDialog->FUN_1422c13b0() - 2);
            return;
        }
    }
    pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
        pDialog->vfunc_2(1, 0, 0);
}

// @0x1412d7450
void UIMaidDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_1412d7aa0();
}

// @0x1412d7480
// MS2-FUNCTIONAL: the exe returns a value (movzx eax,al after the null test); the shared base slot is void
void UIMaidDialog::vfunc_79(void* p)
{
    UIDialog::vfunc_79(p);
    int n = vfunc_55();
    if (n == 0)
        m_30.IsNull();
}

// @0x1412d74e0
void UIMaidDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    vfunc_47(0);
}

// @0x1412d7520
// MS2-FUNCTIONAL: not byte-exact yet (temporaries / call order differ)
int UIMaidDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (FUN_1418fc760(szMethod, pArgs, nArgs, 0) != 0)
        return 1;
    if (_stricmp("OnClose", szMethod) == 0)
    {
        vfunc_67();
        return 1;
    }
    if (_stricmp("OnSave", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            Unk_MaidProfile profile;
            for (unsigned i = 0; i < nArgs; i++)
            {
                CStringW strValue = data.FUN_1422b8f40();
                if (FUN_1412d8e10(i, CStringW(strValue), &profile) == 0)
                    return 0;
            }
            m_profile = profile;
            FUN_140d73bc0(0x79e, 1, static_cast<IMessageListener*>(this), CStringW(L"OnSave"));
            return 1;
        }
        return 0;
    }
    if (_stricmp("OnDebugAffinityGrade", szMethod) == 0)
    {
        CUserMaidManager::GetInstance()->SendRequest5(m_nMaidUid);
        return 1;
    }
    if (_stricmp("OnDebugAffinityUp", szMethod) == 0)
    {
        CUserMaidManager::GetInstance()->SendRequest6(m_nMaidUid);
        return 1;
    }
    if (_stricmp("OnDebugAffinityReset", szMethod) == 0)
    {
        CUserMaidManager::GetInstance()->SendRequest7(m_nMaidUid);
        return 1;
    }
    if (_stricmp("OnDebugMoodUp", szMethod) == 0)
    {
        CUserMaidManager::GetInstance()->SendRequest8(m_nMaidUid);
        return 1;
    }
    if (_stricmp("OnDebugMoodDown", szMethod) == 0)
    {
        CUserMaidManager::GetInstance()->SendRequest9(m_nMaidUid);
        return 1;
    }
    if (_stricmp("OnDebugExpiredDay", szMethod) == 0)
    {
        CUserMaidManager::GetInstance()->SendRequest10(m_nMaidUid, 0x15180, 0);
        return 1;
    }
    if (_stricmp("OnDebugExpiredHour", szMethod) == 0)
    {
        CUserMaidManager::GetInstance()->SendRequest10(m_nMaidUid, 0xe10, 0);
        return 1;
    }
    if (_stricmp("OnDebugExpiredMin", szMethod) == 0)
    {
        CUserMaidManager::GetInstance()->SendRequest10(m_nMaidUid, 0x3c, 0);
        return 1;
    }
    if (_stricmp("OnDebugExtendHour", szMethod) == 0)
    {
        CUserMaidManager::GetInstance()->SendRequest10(m_nMaidUid, 0xe10, 1);
        return 1;
    }
    if (_stricmp("onDebugExtendMin", szMethod) == 0)
    {
        CUserMaidManager::GetInstance()->SendRequest10(m_nMaidUid, 0x3c, 1);
        return 1;
    }
    return 0;
}

// @0x1412d7aa0
// MS2-FUNCTIONAL: not byte-exact yet (temporaries / call order differ)
void UIMaidDialog::FUN_1412d7aa0()
{
    void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0 || m_30.IsNull() || m_nMaidId == 0)
        return;
    PCBase* pActor = FUN_1403ed2d0()->FUN_141bd1320(m_nMaidId);
    if (pActor == 0)
        return;
    CNpc* pNpc = static_cast<CNpc*>(pActor);
    Unk_MaidNpcView* pView = reinterpret_cast<Unk_MaidNpcView*>(pActor);
    Unk_MaidRef spMaid = pView->FUN_141093800();
    if (spMaid.FUN_140d51d60())
        return;
    Unk_MaidDescRef spDesc = FUN_1409eed10()->FUN_14067f780(spMaid.FUN_14067e8c0()->m_nMsgId);
    if (spDesc.FUN_1409edcf0())
        return;
    Unk_MaidInfoRef spInfo = FUN_1409eed20()->FUN_14067f180(spMaid.FUN_14067e8c0()->m_nMsgId);
    if (spInfo.FUN_1409edd20())
        return;

    ASObj obj(2);
    m_strSpecialTitle = spDesc.FUN_1406810d0()->m_strSpecialTitle;
    if (pNpc->FUN_141093270().get() != 0)
    {
        CString strFace = pNpc->FUN_141093270()->m_strPortrait;
        if (strFace.GetLength() != 0)
            obj.FUN_1407cba60("maidFace", CString(strFace));
    }
    obj.FUN_1407cbb20("specialty", CStringW(spDesc.FUN_1406810d0()->m_strSpecialty));
    obj.FUN_1407cbb20("name", pView->FUN_141093310());
    obj.FUN_1407cbb20("title", pView->FUN_141093980());
    obj.FUN_1409adc90("rank", FUN_14053feb0(spMaid.FUN_14067e8c0()->m_nItemId));
    obj.FUN_1407cbb20("specialTitle", CStringW(m_strSpecialTitle));
    obj.FUN_1407cb9c0("salaryType", spInfo.FUN_1406810e0()->m_nSalaryType);
    obj.FUN_1407cbb20("salary", FUN_140656190(L"{0} {1}", FUN_14028de60(0x793), FUN_140763e10(spInfo.FUN_1406810e0()->m_nSalary)));
    obj.FUN_1407cbb20("endDate", FUN_1412da590());

    int nOne = 1;
    int nLevelExp = FUN_14067e910()->FUN_14067ed30(spMaid.FUN_14067e8c0()->m_nLevel);
    int nMaxExp = FUN_1404eb7e0(nOne, nLevelExp);
    int nGauge = spMaid.FUN_14067e8c0()->m_nExp * 100 / nMaxExp;
    CStringW strLevel = FUN_1408116a0(0x79a, spMaid.FUN_14067e8c0()->m_nLevel);
    if (spMaid.FUN_14067e8c0()->FUN_14067dca0() != 0)
        strLevel = FUN_140656190(L"{0} {1}", strLevel, FUN_14028de60(0x79b));
    obj.FUN_1407cbb20("affinityLevel", CStringW(strLevel));
    CStringW strTooltip = FUN_140811740(0x79c, spMaid.FUN_14067e8c0()->m_nExp, nMaxExp);
    if (spMaid.FUN_14067e8c0()->FUN_14067dca0() != 0)
        strTooltip = FUN_14028de60(0x79d);
    obj.FUN_1407cbb20("affinityTooltip", CStringW(strTooltip));
    obj.FUN_1407cb9c0("affinityGauge", nGauge);
    obj.FUN_1407cb9c0("mood", spMaid.FUN_14067e8c0()->m_nMood);
    CStringW strBackground(spDesc.FUN_1406810d0()->m_strBackground);
    FUN_1403b4750()->FUN_1416fb340(strBackground);
    obj.FUN_1407cbb20("background", CStringW(strBackground));
    unsigned nEditable = spMaid.FUN_14067e8c0()->FUN_1409eeda0().IsEmpty();
    if (FUN_14025e7c0()->IsDebugMode())
        nEditable = 1;
    obj.FUN_1407cb9c0("editable", nEditable);
    if (spMaid.FUN_14067e8c0()->FUN_1409eeda0().IsEmpty())
    {
        Unk_MaidDescRow* pRow = spDesc.FUN_1406810d0();
        obj.FUN_1407cbb20("title", CStringW(pRow->m_strTitle));
        obj.FUN_1407cbb20("birth", CStringW(pRow->m_strBirth));
        obj.FUN_1407cbb20("constel", CStringW(pRow->m_strConstel));
        obj.FUN_1407cbb20("height", CStringW(pRow->m_strHeight));
        obj.FUN_1407cbb20("weight", CStringW(pRow->m_strWeight));
        obj.FUN_1407cbb20("special", CStringW(pRow->m_strSpecial));
        obj.FUN_1407cbb20("like", CStringW(pRow->m_strLike));
        obj.FUN_1407cbb20("hate", CStringW(pRow->m_strHate));
        obj.FUN_1407cbb20("hobby", CStringW(pRow->m_strHobby));
        obj.FUN_1407cbb20("ownername", CStringW(pRow->m_strOwnerName));
        obj.FUN_1407cbb20("belongto", CStringW(pRow->m_strBelongTo));
    }
    else
    {
        obj.FUN_1407cbb20("title", CStringW(spMaid.FUN_14067e8c0()->m_strTitle));
        obj.FUN_1407cbb20("birth", CStringW(spMaid.FUN_14067e8c0()->m_strBirth));
        obj.FUN_1407cbb20("constel", CStringW(spMaid.FUN_14067e8c0()->m_strConstel));
        obj.FUN_1407cbb20("height", CStringW(spMaid.FUN_14067e8c0()->m_strHeight));
        obj.FUN_1407cbb20("weight", CStringW(spMaid.FUN_14067e8c0()->m_strWeight));
        obj.FUN_1407cbb20("special", CStringW(spMaid.FUN_14067e8c0()->m_strSpecial));
        obj.FUN_1407cbb20("like", CStringW(spMaid.FUN_14067e8c0()->m_strLike));
        obj.FUN_1407cbb20("hate", CStringW(spMaid.FUN_14067e8c0()->m_strHate));
        obj.FUN_1407cbb20("hobby", CStringW(spMaid.FUN_14067e8c0()->m_strHobby));
        obj.FUN_1407cbb20("ownername", CStringW(spMaid.FUN_14067e8c0()->m_strOwnerName));
        obj.FUN_1407cbb20("belongto", CStringW(spMaid.FUN_14067e8c0()->m_strBelongTo));
    }
    obj.FUN_1407cb9c0("maxChars1", *FUN_1402056b0(&FUN_1401d3200()->m_maxChars1));
    obj.FUN_1407cb9c0("maxChars2", *FUN_1402056b0(&FUN_1401d3200()->m_maxChars2));
    m_30->Invoke("setData", obj);
    if (FUN_14025e7c0()->IsDebugMode())
        m_30->Invoke("showDebugBtn", true);
}

// @0x1412d8c40
// MS2-FUNCTIONAL: not byte-exact yet (temporaries / call order differ)
int UIMaidDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) != 0)
        return 1;
    if (pMsg->FUN_1422e4520() == 0 && dynamic_cast<UIMessageBox*>(pSender) != 0)
    {
        int nResult = pMsg->FUN_1422b8a10();
        CStringW strTag = pMsg->FUN_1422b8f40();
        ATL::CAtlArray<void*> kArr;
        FUN_14151f200();
        if (nResult == 0 && FUN_1403b3c40(strTag, L"OnSave") != 0)
        {
            COutPacket packet(0x62, 0);
            packet.vfunc_o10_1(4);
            packet.vfunc_o10_4(m_nMaidUid);
            packet.vfunc_o10_3(m_nMaidId);
            FUN_14067c610(&m_profile, &packet);
            FUN_140710590(packet);
        }
        return 1;
    }
    return 0;
}

// @0x1412d8e10
// MS2-FUNCTIONAL: not byte-exact yet (temporaries / call order differ)
int UIMaidDialog::FUN_1412d8e10(int nField, CStringW strValue, Unk_MaidProfile* pProfile)
{
    Unk_MaidProfileFields* pFields = reinterpret_cast<Unk_MaidProfileFields*>(pProfile);
    CStringW strName(L"");
    switch (nField)
    {
    case 0:
        strName = FUN_14028de60(0x791);
        pFields->m_str08 = strValue;
        break;
    case 1:
        strName = FUN_14028de60(0x792);
        pFields->m_str00 = strValue;
        break;
    case 2:
        strName = FUN_14028de60(0x788);
        pFields->m_str10 = strValue;
        break;
    case 3:
        strName = FUN_14028de60(0x789);
        pFields->m_str18 = strValue;
        break;
    case 4:
        strName = FUN_14028de60(0x78a);
        pFields->m_str20 = strValue;
        break;
    case 5:
        strName = FUN_14028de60(0x78b);
        pFields->m_str28 = strValue;
        break;
    case 6:
        strName = m_strSpecialTitle;
        pFields->m_str38 = strValue;
        break;
    case 7:
        strName = FUN_14028de60(0x78c);
        pFields->m_str40 = strValue;
        break;
    case 8:
        strName = FUN_14028de60(0x78d);
        pFields->m_str48 = strValue;
        break;
    case 9:
        strName = FUN_14028de60(0x78e);
        pFields->m_str50 = strValue;
        break;
    case 10:
        strName = FUN_14028de60(0x78f);
        pFields->m_str58 = strValue;
        break;
    case 11:
        strName = FUN_14028de60(0x790);
        pFields->m_str60 = strValue;
    }
    Unk_MaidTextCheck* pCheck = FUN_14025e7d0()->FUN_140229a50();
    if (pCheck == 0)
        return 0;
    CStringW strBad;
    if (nField == 0 || nField == 1 || nField == 10)
    {
        if (pCheck->FUN_140225470(strValue, strBad) != 0)
        {
            FUN_140d73aa0(FUN_140656190(L"[ {0} ] {1}", strName, strBad), 0, 0, CStringW(L""));
            return 0;
        }
    }
    else
    {
        if (pCheck->FUN_140225550(strValue, strBad) != 0)
        {
            FUN_140d73aa0(FUN_140656190(L"[ {0} ] {1}", strName, strBad), 0, 0, CStringW(L""));
            return 0;
        }
    }
    return 1;
}

// @0x1412d9640
void UIMaidDialog::FUN_1412d9640(int nMaidId, unsigned __int64 nMaidUid)
{
    m_nMaidId = nMaidId;
    m_nMaidUid = nMaidUid;
}

// @0x1412d9680
// MS2-FUNCTIONAL: not byte-exact yet (temporaries / call order differ)
void UIMaidDialog::FUN_1412d9680()
{
    void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0 || m_30.IsNull() || m_nMaidId == 0)
        return;
    PCBase* pActor = FUN_1403ed2d0()->FUN_141bd1320(m_nMaidId);
    if (pActor == 0)
        return;
    Unk_MaidNpcView* pView = reinterpret_cast<Unk_MaidNpcView*>(pActor);
    Unk_MaidRef spMaid = pView->FUN_141093800();
    if (spMaid.FUN_140d51d60())
        return;
    Unk_MaidDescRef spDesc = FUN_1409eed10()->FUN_14067f780(spMaid.FUN_14067e8c0()->m_nMsgId);
    if (spDesc.FUN_1409edcf0())
        return;
    Unk_MaidInfoRef spInfo = FUN_1409eed20()->FUN_14067f180(spMaid.FUN_14067e8c0()->m_nMsgId);
    if (spInfo.FUN_1409edd20())
        return;

    ASObj obj(2);
    obj.FUN_1407cbb20("endDate", FUN_1412da590());
    int nOne = 1;
    int nLevelExp = FUN_14067e910()->FUN_14067ed30(spMaid.FUN_14067e8c0()->m_nLevel);
    int nMaxExp = FUN_1404eb7e0(nOne, nLevelExp);
    int nGauge = spMaid.FUN_14067e8c0()->m_nExp * 100 / nMaxExp;
    CStringW strLevel = FUN_1408116a0(0x79a, spMaid.FUN_14067e8c0()->m_nLevel);
    if (spMaid.FUN_14067e8c0()->FUN_14067dca0() != 0)
        strLevel = FUN_140656190(L"{0} {1}", strLevel, FUN_14028de60(0x79b));
    obj.FUN_1407cbb20("affinityLevel", CStringW(strLevel));
    CStringW strTooltip = FUN_140811740(0x79c, spMaid.FUN_14067e8c0()->m_nExp, nMaxExp);
    if (spMaid.FUN_14067e8c0()->FUN_14067dca0() != 0)
        strTooltip = FUN_14028de60(0x79d);
    obj.FUN_1407cbb20("affinityTooltip", CStringW(strTooltip));
    obj.FUN_1407cb9c0("affinityGauge", nGauge);
    obj.FUN_1407cb9c0("mood", spMaid.FUN_14067e8c0()->m_nMood);
    m_30->Invoke("updateStatus", obj);
}

// @0x1412d9b90
// MS2-FUNCTIONAL: not byte-exact yet (temporaries / call order differ)
void UIMaidDialog::FUN_1412d9b90()
{
    void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0 || m_30.IsNull() || m_nMaidId == 0)
        return;
    PCBase* pActor = FUN_1403ed2d0()->FUN_141bd1320(m_nMaidId);
    if (pActor == 0)
        return;
    Unk_MaidNpcView* pView = reinterpret_cast<Unk_MaidNpcView*>(pActor);
    Unk_MaidRef spMaid = pView->FUN_141093800();
    if (spMaid.FUN_140d51d60())
        return;
    Unk_MaidDescRef spDesc = FUN_1409eed10()->FUN_14067f780(spMaid.FUN_14067e8c0()->m_nMsgId);
    if (spDesc.FUN_1409edcf0())
        return;
    Unk_MaidInfoRef spInfo = FUN_1409eed20()->FUN_14067f180(spMaid.FUN_14067e8c0()->m_nMsgId);
    if (spInfo.FUN_1409edd20())
        return;

    ASObj obj(2);
    obj.FUN_1407cbb20("name", pView->FUN_141093310());
    obj.FUN_1407cbb20("title", pView->FUN_141093980());
    if (spMaid.FUN_14067e8c0()->FUN_1409eeda0().IsEmpty())
    {
        Unk_MaidDescRow* pRow = spDesc.FUN_1406810d0();
        obj.FUN_1407cbb20("title", CStringW(pRow->m_strTitle));
        obj.FUN_1407cbb20("birth", CStringW(pRow->m_strBirth));
        obj.FUN_1407cbb20("constel", CStringW(pRow->m_strConstel));
        obj.FUN_1407cbb20("height", CStringW(pRow->m_strHeight));
        obj.FUN_1407cbb20("weight", CStringW(pRow->m_strWeight));
        obj.FUN_1407cbb20("special", CStringW(pRow->m_strSpecial));
        obj.FUN_1407cbb20("like", CStringW(pRow->m_strLike));
        obj.FUN_1407cbb20("hate", CStringW(pRow->m_strHate));
        obj.FUN_1407cbb20("hobby", CStringW(pRow->m_strHobby));
        obj.FUN_1407cbb20("ownername", CStringW(pRow->m_strOwnerName));
        obj.FUN_1407cbb20("belongto", CStringW(pRow->m_strBelongTo));
    }
    else
    {
        obj.FUN_1407cbb20("title", CStringW(spMaid.FUN_14067e8c0()->m_strTitle));
        obj.FUN_1407cbb20("birth", CStringW(spMaid.FUN_14067e8c0()->m_strBirth));
        obj.FUN_1407cbb20("constel", CStringW(spMaid.FUN_14067e8c0()->m_strConstel));
        obj.FUN_1407cbb20("height", CStringW(spMaid.FUN_14067e8c0()->m_strHeight));
        obj.FUN_1407cbb20("weight", CStringW(spMaid.FUN_14067e8c0()->m_strWeight));
        obj.FUN_1407cbb20("special", CStringW(spMaid.FUN_14067e8c0()->m_strSpecial));
        obj.FUN_1407cbb20("like", CStringW(spMaid.FUN_14067e8c0()->m_strLike));
        obj.FUN_1407cbb20("hate", CStringW(spMaid.FUN_14067e8c0()->m_strHate));
        obj.FUN_1407cbb20("hobby", CStringW(spMaid.FUN_14067e8c0()->m_strHobby));
        obj.FUN_1407cbb20("ownername", CStringW(spMaid.FUN_14067e8c0()->m_strOwnerName));
        obj.FUN_1407cbb20("belongto", CStringW(spMaid.FUN_14067e8c0()->m_strBelongTo));
    }
    m_30->Invoke("updateProperty", obj);
}

// @0x1412da590
// MS2-FUNCTIONAL: not byte-exact yet (temporaries / call order differ)
CStringW UIMaidDialog::FUN_1412da590()
{
    CStringW strText(L"");
    void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0 || m_nMaidId == 0)
        return strText;
    PCBase* pActor = FUN_1403ed2d0()->FUN_141bd1320(m_nMaidId);
    if (pActor == 0)
        return strText;
    Unk_MaidNpcView* pView = reinterpret_cast<Unk_MaidNpcView*>(pActor);
    Unk_MaidRef spMaid = pView->FUN_141093800();
    if (spMaid.FUN_140d51d60())
        return strText;
    if (FUN_140869440() < spMaid.FUN_14067e8c0()->m_nExpireTime)
    {
        CMsTime kTime(spMaid.FUN_14067e8c0()->m_nExpireTime);
        int nYear = kTime.GetYear();
        int nMonth = kTime.GetMonth();
        int nDay = kTime.GetDay();
        int nHour = kTime.GetHour();
        int nMinute = kTime.GetMinute();
        strText = FUN_1409e90c0(0x795, nYear, nMonth, nDay, nHour, nMinute);
    }
    else
        strText = FUN_14028de60(0x794);
    return strText;
}

// @0x1412da910
int UIMaidDialog::vfunc_48()
{
    return 0x4e9d;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142caf6f0-0x142caf7a0 .text$yd
