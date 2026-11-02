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
#include "ms2/placeholder/creservedwordtable.h"
#include "ms2/client/ms2/uitalkcinematic.h"
#include "ms2/commonfiles/commonstringtable.h"
#include "ms2/commonfiles/maid.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/clientconstants.h"  // C3: Common::Constants::Value<int>::Get
#include "ms2/ms2format.h"   // C3: fmt for BlockFormat<int>
#include "ms2/placeholder/formatstringid.h"
#include <algorithm>

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
};




    // the experience of one affinity level


class Unk_MaidWorld : public WorldService
{
public:
};
void* FUN_14025e7c0();   // C3: was FUN_14025e7c0

    // resolve a background path

// The game constants (0xa118: the maxChars1 limits, 0xa1c8: the maxChars2 limits). View only.
struct Unk_MaidLimitBox { unsigned char m[0xb0]; };
class Unk_MaidConsts
{
public:
    unsigned char m_pad_00[0xa118];
    Unk_MaidLimitBox m_maxChars1;                               // +0xa118
    Unk_MaidLimitBox m_maxChars2;                               // +0xa1c8
};
class Unk_SingletonObj1* FUN_1401d3200();   // C3: was FUN_1401d3200


CommonString* FUN_14025e7d0();                                  // the CommonString singleton
extern template class MS2Ptr<CBanTextChecker>;

CStringW GetStringCommon(int nStringId);                          // string table text by id
CStringW BlockFormat(int, const fmt::ArgList&);   // C3: BlockFormat<int> (0x1408116a0)
FMT_VARIADIC_W(CStringW, BlockFormat, int)
CStringW FUN_140763e10(int nNumber);                            // a number with digit grouping
int FUN_14053feb0(int nItemId);                                 // default rank of an item
__int64 GetServerTime();                                        // the server time
void FUN_140d73bc0(int nStrId, int nType, void* pListener, CStringW strTag);   // pop the system message
void FUN_140d73aa0(CStringW text, int nA, void* pListener, CStringW strTag);     // pop the notice
int FUN_1418fc760(const char* szMethod, void* pArgs, int nArgs, void* p);
void FUN_14151f200();
void FUN_140710590(COutPacket& packet);                         // send
UITalkCinematic* FUN_140a7b2b0(int nId);                         // a dialog's position record
class Unk_MaidUnused;                                            // element of an unused local array (its CAtlArray dtor COMDAT is 0x140164210, not the void* one)

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
CString UIMaidDialog::GetTypeName()
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
        if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116d9c0(0xf, 0, 0))
        {
            pDialog->Invoke("onTabKey");
            return 1;
        }
    }
    return 0;
}

// @0x1412d7310
void UIMaidDialog::vfunc_43()
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    UITalkCinematic* pRef;
    if (pDialog != 0 && (pRef = FUN_140a7b2b0(0x4e40)) != 0)
    {
        int nX = pRef->GetLowerCutGlobalY();
        int nY = pRef->GetIllustGlobalX() - 0x14;
        if (nX != -1 && nY != -1)
        {
            pDialog->vfunc_2(5, nY, nX - pDialog->GetHeightCeil() - 2);
            return;
        }
    }
    ASDialog* pDefault = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDefault != 0)
        pDefault->vfunc_2(1, 0, 0);
}

// @0x1412d7450
void UIMaidDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_1412d7aa0();
}

// @0x1412d7480
void UIMaidDialog::vfunc_79(void* p)
{
    UIDialog::vfunc_79(p);
    vfunc_55() == 0 && m_30.IsNull();      // an unused && expression: movzx eax,al after the null test
}

// @0x1412d74e0
void UIMaidDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    vfunc_47(0);
}

// @0x1412d7520
int UIMaidDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (FUN_1418fc760(szMethod, (void*)pArgs, nArgs, 0) != 0)
        return 1;
    if (_stricmp("OnClose", szMethod) == 0)
    {
        vfunc_67();
        return 1;
    }
    else if (_stricmp("OnSave", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            MaidProfile profile;
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
    }
    else if (_stricmp("OnDebugAffinityGrade", szMethod) == 0)
    {
        CUserMaidManager::GetInstance()->SendRequest5(m_nMaidUid);
        return 1;
    }
    else if (_stricmp("OnDebugAffinityUp", szMethod) == 0)
    {
        CUserMaidManager::GetInstance()->SendRequest6(m_nMaidUid);
        return 1;
    }
    else if (_stricmp("OnDebugAffinityReset", szMethod) == 0)
    {
        CUserMaidManager::GetInstance()->SendRequest7(m_nMaidUid);
        return 1;
    }
    else if (_stricmp("OnDebugMoodUp", szMethod) == 0)
    {
        CUserMaidManager::GetInstance()->SendRequest8(m_nMaidUid);
        return 1;
    }
    else if (_stricmp("OnDebugMoodDown", szMethod) == 0)
    {
        CUserMaidManager::GetInstance()->SendRequest9(m_nMaidUid);
        return 1;
    }
    else if (_stricmp("OnDebugExpiredDay", szMethod) == 0)
    {
        CUserMaidManager::GetInstance()->SendRequest10(m_nMaidUid, 0x15180, 0);
        return 1;
    }
    else if (_stricmp("OnDebugExpiredHour", szMethod) == 0)
    {
        CUserMaidManager::GetInstance()->SendRequest10(m_nMaidUid, 0xe10, 0);
        return 1;
    }
    else if (_stricmp("OnDebugExpiredMin", szMethod) == 0)
    {
        CUserMaidManager::GetInstance()->SendRequest10(m_nMaidUid, 0x3c, 0);
        return 1;
    }
    else if (_stricmp("OnDebugExtendHour", szMethod) == 0)
    {
        CUserMaidManager::GetInstance()->SendRequest10(m_nMaidUid, 0xe10, 1);
        return 1;
    }
    else if (_stricmp("onDebugExtendMin", szMethod) == 0)
    {
        CUserMaidManager::GetInstance()->SendRequest10(m_nMaidUid, 0x3c, 1);
        return 1;
    }
    return 0;
}

// @0x1412d7aa0
void UIMaidDialog::FUN_1412d7aa0()
{
    void* pPlayer = reinterpret_cast<Unk_MaidWorld*>(WorldService::GetInstance())->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    if (m_30.IsNull())
        return;
    if (m_nMaidId == 0)
        return;
    CNpc* pNpc = static_cast<CNpc*>(reinterpret_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd1320(m_nMaidId)));
    if (pNpc == 0)
        return;
    MS2Ptr<CMaid> spMaid = reinterpret_cast<CNpc*>(pNpc)->FUN_141093800();
    if (spMaid.IsNull())
        return;
    TPtrValue<MaidDesc> spDesc = TSingleton<CMaidDescTable>::GetInstance()->Find(spMaid->m_nMaidId);
    if (!spDesc)
        return;
    TPtrValue<MaidInfo> spInfo = TSingleton<CMaidInfoTable>::GetInstance()->Find(spMaid->m_nMaidId);
    if (!spInfo)
        return;

    ASObj obj(2);
    m_strSpecialTitle = spDesc->specialTitle;
    if (pNpc->GetNpcData().get())
    {
        CString strFace = pNpc->GetNpcData()->m_strPortrait;
        if (strFace.GetLength() != 0)
            obj.FUN_1407cba60("maidFace", CString(strFace));
    }
    obj.FUN_1407cbb20("specialty", CStringW(spDesc->specialty));
    obj.FUN_1407cbb20("name", reinterpret_cast<CNpc*>(pNpc)->FUN_141093310());
    obj.FUN_1407cbb20("title", reinterpret_cast<CNpc*>(pNpc)->FUN_141093980());
    obj.FUN_1409adc90("rank", FUN_14053feb0(spMaid->m_nItemId));
    obj.FUN_1407cbb20("specialTitle", CStringW(m_strSpecialTitle));
    obj.FUN_1407cb9c0("salaryType", spInfo->salaryType);
    obj.FUN_1407cbb20("salary", StringFormat(L"{0} {1}", GetStringCommon(0x793), FUN_140763e10(spInfo->salary)));
    obj.FUN_1407cbb20("endDate", FUN_1412da590());

    int nMaxExp = (std::max<int>)(1, TSingleton<CMaidExpTable>::GetInstance()->GetExp(spMaid->m_nOrder));
    int nGauge = spMaid->m_nExp * 100 / nMaxExp;
    CStringW strLevel = BlockFormat<int>(0x79a, spMaid->m_nOrder);
    if (spMaid->IsAffinityLevelAtMax() != 0)
        strLevel = StringFormat(L"{0} {1}", strLevel, GetStringCommon(0x79b));
    obj.FUN_1407cbb20("affinityLevel", CStringW(strLevel));
    CStringW strTooltip = FormatStringId(0x79c, spMaid->m_nExp, nMaxExp);
    if (spMaid->IsAffinityLevelAtMax() != 0)
        strTooltip = GetStringCommon(0x79d);
    obj.FUN_1407cbb20("affinityTooltip", CStringW(strTooltip));
    obj.FUN_1407cb9c0("affinityGauge", nGauge);
    obj.FUN_1407cb9c0("mood", spMaid->m_nMood);
    CStringW strBackground(spDesc->background);
    TSingleton<CReservedWordTable>::GetInstance()->FUN_1416fb340(strBackground);
    obj.FUN_1407cbb20("background", CStringW(strBackground));
    unsigned nEditable = spMaid->FUN_1409eeda0().IsEmpty();
    if (((class CInputKeyHandler*)FUN_14025e7c0())->IsDebugMode())
        nEditable = 1;
    obj.FUN_1407cb9c0("editable", nEditable);
    if (spMaid->FUN_1409eeda0().IsEmpty())
    {
        obj.FUN_1407cbb20("title", CStringW(spDesc->title));
        obj.FUN_1407cbb20("birth", CStringW(spDesc->birthDay));
        obj.FUN_1407cbb20("constel", CStringW(spDesc->constellation));
        obj.FUN_1407cbb20("height", CStringW(spDesc->height));
        obj.FUN_1407cbb20("weight", CStringW(spDesc->weight));
        obj.FUN_1407cbb20("special", CStringW(spDesc->specialDetail));
        obj.FUN_1407cbb20("like", CStringW(spDesc->like));
        obj.FUN_1407cbb20("hate", CStringW(spDesc->hate));
        obj.FUN_1407cbb20("hobby", CStringW(spDesc->hobby));
        obj.FUN_1407cbb20("ownername", CStringW(spDesc->ownerName));
        obj.FUN_1407cbb20("belongto", CStringW(spDesc->belongTo));
    }
    else
    {
        obj.FUN_1407cbb20("title", CStringW(spMaid->m_profile.title));
        obj.FUN_1407cbb20("birth", CStringW(spMaid->m_profile.birthDay));
        obj.FUN_1407cbb20("constel", CStringW(spMaid->m_profile.constellation));
        obj.FUN_1407cbb20("height", CStringW(spMaid->m_profile.height));
        obj.FUN_1407cbb20("weight", CStringW(spMaid->m_profile.weight));
        obj.FUN_1407cbb20("special", CStringW(spMaid->m_profile.specialDetail));
        obj.FUN_1407cbb20("like", CStringW(spMaid->m_profile.like));
        obj.FUN_1407cbb20("hate", CStringW(spMaid->m_profile.hate));
        obj.FUN_1407cbb20("hobby", CStringW(spMaid->m_profile.hobby));
        obj.FUN_1407cbb20("ownername", CStringW(spMaid->m_profile.ownerName));
        obj.FUN_1407cbb20("belongto", CStringW(spMaid->m_profile.belongTo));
    }
    obj.FUN_1407cb9c0("maxChars1", *reinterpret_cast<Common::Constants::Value<int>*>(&((class Unk_MaidConsts*)FUN_1401d3200())->m_maxChars1)->Get());
    obj.FUN_1407cb9c0("maxChars2", *reinterpret_cast<Common::Constants::Value<int>*>(&((class Unk_MaidConsts*)FUN_1401d3200())->m_maxChars2)->Get());
    m_30->Invoke("setData", obj);
    if (((class CInputKeyHandler*)FUN_14025e7c0())->IsDebugMode())
        m_30->Invoke("showDebugBtn", 1);           // an int, not a bool: the movie gets the Number 1
}

// @0x1412d8c40
int UIMaidDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) != 0)
        return 1;
    if (pMsg->FUN_1422e4520() == 0 && dynamic_cast<UIMessageBox*>(pSender) != 0)
    {
        int nResult = pMsg->FUN_1422b8a10();
        CStringW strTag = pMsg->FUN_1422b8f40();
        ATL::CAtlArray<Unk_MaidUnused*> kArr;
        FUN_14151f200();
        if (nResult == 0 && operator==(strTag, L"OnSave"))
        {
            COutPacket packet(static_cast<int>(SendOp::Maid), 0);
            packet.WriteUInt8(4);
            packet.WriteInt64(m_nMaidUid);
            packet.WriteInt32(m_nMaidId);
            m_profile.Write(&packet);
            FUN_140710590(packet);
            return 1;
        }
        return 1;
    }
    return 0;
}

// @0x1412d8e10
int UIMaidDialog::FUN_1412d8e10(int nField, CStringW strValue, MaidProfile* pProfile)
{
    CStringW strName(L"");
    switch (nField)
    {
    case 0:
        strName = GetStringCommon(0x791);
        pProfile->name = strValue;
        break;
    case 1:
        strName = GetStringCommon(0x792);
        pProfile->title = strValue;
        break;
    case 2:
        strName = GetStringCommon(0x788);
        pProfile->birthDay = strValue;
        break;
    case 3:
        strName = GetStringCommon(0x789);
        pProfile->constellation = strValue;
        break;
    case 4:
        strName = GetStringCommon(0x78a);
        pProfile->height = strValue;
        break;
    case 5:
        strName = GetStringCommon(0x78b);
        pProfile->weight = strValue;
        break;
    case 6:
        strName = m_strSpecialTitle;
        pProfile->specialDetail = strValue;
        break;
    case 7:
        strName = GetStringCommon(0x78c);
        pProfile->like = strValue;
        break;
    case 8:
        strName = GetStringCommon(0x78d);
        pProfile->hate = strValue;
        break;
    case 9:
        strName = GetStringCommon(0x78e);
        pProfile->hobby = strValue;
        break;
    case 10:
        strName = GetStringCommon(0x78f);
        pProfile->ownerName = strValue;
        break;
    case 11:
        strName = GetStringCommon(0x790);
        pProfile->belongTo = strValue;
    }
    if (CBanTextChecker* pCheck = FUN_14025e7d0()->GetChecker())
    {
        CStringW strBad;
        if (nField == 0 || nField == 1 || nField == 10)
        {
            if (pCheck->CheckMaidProfileField(strValue, strBad) != 0)
            {
                FUN_140d73aa0(StringFormat(L"[ {0} ] {1}", strName, strBad), 0, 0, CStringW(L""));
                return 0;
            }
        }
        else
        {
            if (pCheck->CheckMaidName(strValue, strBad) != 0)
            {
                FUN_140d73aa0(StringFormat(L"[ {0} ] {1}", strName, strBad), 0, 0, CStringW(L""));
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

// @0x1412d9640
void UIMaidDialog::FUN_1412d9640(int nMaidId, unsigned __int64 nMaidUid)
{
    m_nMaidId = nMaidId;
    m_nMaidUid = nMaidUid;
}

// @0x1412d9680
void UIMaidDialog::FUN_1412d9680()
{
    void* pPlayer = reinterpret_cast<Unk_MaidWorld*>(WorldService::GetInstance())->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    if (m_30.IsNull())
        return;
    if (m_nMaidId == 0)
        return;
    CNpc* pView = reinterpret_cast<CNpc*>(reinterpret_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd1320(m_nMaidId)));
    if (pView == 0)
        return;
    MS2Ptr<CMaid> spMaid = pView->FUN_141093800();
    if (spMaid.IsNull())
        return;
    TPtrValue<MaidDesc> spDesc = TSingleton<CMaidDescTable>::GetInstance()->Find(spMaid->m_nMaidId);
    if (!spDesc)
        return;
    TPtrValue<MaidInfo> spInfo = TSingleton<CMaidInfoTable>::GetInstance()->Find(spMaid->m_nMaidId);
    if (!spInfo)
        return;

    ASObj obj(2);
    obj.FUN_1407cbb20("endDate", FUN_1412da590());
    int nMaxExp = (std::max<int>)(1, TSingleton<CMaidExpTable>::GetInstance()->GetExp(spMaid->m_nOrder));
    int nGauge = spMaid->m_nExp * 100 / nMaxExp;
    CStringW strLevel = BlockFormat<int>(0x79a, spMaid->m_nOrder);
    if (spMaid->IsAffinityLevelAtMax() != 0)
        strLevel = StringFormat(L"{0} {1}", strLevel, GetStringCommon(0x79b));
    obj.FUN_1407cbb20("affinityLevel", CStringW(strLevel));
    CStringW strTooltip = FormatStringId(0x79c, spMaid->m_nExp, nMaxExp);
    if (spMaid->IsAffinityLevelAtMax() != 0)
        strTooltip = GetStringCommon(0x79d);
    obj.FUN_1407cbb20("affinityTooltip", CStringW(strTooltip));
    obj.FUN_1407cb9c0("affinityGauge", nGauge);
    obj.FUN_1407cb9c0("mood", spMaid->m_nMood);
    m_30->Invoke("updateStatus", obj);
}

// @0x1412d9b90
void UIMaidDialog::FUN_1412d9b90()
{
    void* pPlayer = reinterpret_cast<Unk_MaidWorld*>(WorldService::GetInstance())->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    if (m_30.IsNull())
        return;
    if (m_nMaidId == 0)
        return;
    CNpc* pView = reinterpret_cast<CNpc*>(reinterpret_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd1320(m_nMaidId)));
    if (pView == 0)
        return;
    MS2Ptr<CMaid> spMaid = pView->FUN_141093800();
    if (spMaid.IsNull())
        return;
    TPtrValue<MaidDesc> spDesc = TSingleton<CMaidDescTable>::GetInstance()->Find(spMaid->m_nMaidId);
    if (!spDesc)
        return;
    TPtrValue<MaidInfo> spInfo = TSingleton<CMaidInfoTable>::GetInstance()->Find(spMaid->m_nMaidId);
    if (!spInfo)
        return;

    ASObj obj(2);
    obj.FUN_1407cbb20("name", pView->FUN_141093310());
    obj.FUN_1407cbb20("title", pView->FUN_141093980());
    if (spMaid->FUN_1409eeda0().IsEmpty())
    {
        obj.FUN_1407cbb20("title", CStringW(spDesc->title));
        obj.FUN_1407cbb20("birth", CStringW(spDesc->birthDay));
        obj.FUN_1407cbb20("constel", CStringW(spDesc->constellation));
        obj.FUN_1407cbb20("height", CStringW(spDesc->height));
        obj.FUN_1407cbb20("weight", CStringW(spDesc->weight));
        obj.FUN_1407cbb20("special", CStringW(spDesc->specialDetail));
        obj.FUN_1407cbb20("like", CStringW(spDesc->like));
        obj.FUN_1407cbb20("hate", CStringW(spDesc->hate));
        obj.FUN_1407cbb20("hobby", CStringW(spDesc->hobby));
        obj.FUN_1407cbb20("ownername", CStringW(spDesc->ownerName));
        obj.FUN_1407cbb20("belongto", CStringW(spDesc->belongTo));
    }
    else
    {
        obj.FUN_1407cbb20("title", CStringW(spMaid->m_profile.title));
        obj.FUN_1407cbb20("birth", CStringW(spMaid->m_profile.birthDay));
        obj.FUN_1407cbb20("constel", CStringW(spMaid->m_profile.constellation));
        obj.FUN_1407cbb20("height", CStringW(spMaid->m_profile.height));
        obj.FUN_1407cbb20("weight", CStringW(spMaid->m_profile.weight));
        obj.FUN_1407cbb20("special", CStringW(spMaid->m_profile.specialDetail));
        obj.FUN_1407cbb20("like", CStringW(spMaid->m_profile.like));
        obj.FUN_1407cbb20("hate", CStringW(spMaid->m_profile.hate));
        obj.FUN_1407cbb20("hobby", CStringW(spMaid->m_profile.hobby));
        obj.FUN_1407cbb20("ownername", CStringW(spMaid->m_profile.ownerName));
        obj.FUN_1407cbb20("belongto", CStringW(spMaid->m_profile.belongTo));
    }
    m_30->Invoke("updateProperty", obj);
}

// @0x1412da590
CStringW UIMaidDialog::FUN_1412da590()
{
    CStringW strText(L"");
    void* pPlayer = reinterpret_cast<Unk_MaidWorld*>(WorldService::GetInstance())->FUN_141bd0cc0();
    if (pPlayer == 0)
        return strText;
    if (m_nMaidId == 0)
        return strText;
    CNpc* pView = reinterpret_cast<CNpc*>(reinterpret_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd1320(m_nMaidId)));
    if (pView == 0)
        return strText;
    MS2Ptr<CMaid> spMaid = pView->FUN_141093800();
    if (spMaid.IsNull())
        return strText;
    if (spMaid->m_nExpireTime <= GetServerTime())
        strText = GetStringCommon(0x794);
    else
    {
        CMsTime kTime(spMaid->m_nExpireTime);
        int nYear = kTime.GetYear();
        int nMonth = kTime.GetMonth();
        int nDay = kTime.GetDay();
        int nHour = kTime.GetHour();
        int nMinute = kTime.GetMinute();
        strText = BlockFormat(0x795, nYear, nMonth, nDay, nHour, nMinute);
    }
    return strText;
}

// @0x1412da910
int UIMaidDialog::vfunc_48()
{
    return 0x4e9d;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142caf6f0-0x142caf7a0 .text$yd
