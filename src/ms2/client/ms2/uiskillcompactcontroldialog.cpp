// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The compact skill control window ("SkillCompactControl", UI type
// 0x4ef6): up to three named tabs, each with the skills the player ticked and one hot key that triggers the whole set.
// The tabs come from the server (packet 0xd1) and go back on close (packet 0x7b); the skill system gets them as
// CSkillCompactControlConfig. See uiskillcompactcontroldialog.h.
// MS2-GUESS-LOOKALIKES
// MS2-UNIT: ?\uiskillcompactcontroldialog.cpp
// MS2-RANGE: 0x1400e1660-0x1400e18a0 .text$di
// MS2-RANGE: 0x140f9e200-0x140fa3b10 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?IsNull@?$MS2Ptr@VCSkillCompactControlConfig@@@@QEBA_NXZ 0x140fa3090 ; unique
// MS2-PIN: ?get@?$MS2Ptr@VCSkillCompactControlConfig@@@@QEBAPEAVCSkillCompactControlConfig@@XZ 0x140fa30c0 ; unique
// MS2-PIN: ?GetHeadPosition@?$CAtlList@V?$MS2Ptr@VCSkillCompactControlConfig@@@@V?$CElementTraits@V?$MS2Ptr@VCSkillCompactControlConfig@@@@@ATL@@@ATL@@QEBAPEAU__POSITION@@XZ 0x140fa34b0 ; unique
// MS2-PINS-END tplpin
//
// File name assumed (the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiskillcompactcontroldialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uiskillcompactcontroldialog.h"

#include <algorithm>
#include <set>

#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/skillsystem.h"
#include "ms2/client/ms2/uimessagebox.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/commonfiles/skillcompactcontroltable.h"
#include "ms2/commonfiles/skillconfig.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/iclientplatform.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/jobtable.h"
#include "ms2/client/ms2/skilldatatablecli.h"
#include "ms2/placeholder/asbutton.h"  // C3: ASButton::FUN_1422cdfb0
#include "ms2/placeholder/asbuttonbar.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/ckeytable.h"
#include "ms2/placeholder/formatstringid.h"
#include "ms2/placeholder/unk_blocklist.h"
#include "ms2/client/ms2/jobsystemcli.h"
#include "ms2/ms2format.h"   // C3: StringFormat<CStringW, CStringW> (was FUN_140656190)
#include "ms2/commonfiles/os.h"

// ---- header statics (dynamic initializers 0x1400e1660..0x1400e17d0; the same group as uiskillbookautodistributedialog.cpp) ----
#ifndef MS2_HOOK_DLL
static CString s_strSortNames7[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);
static CString s_strSortNames8[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
#endif

// The key being captured while the player presses a key for a tab (the second press is the confirm).
static int DAT_143acbd08;

// ---- unit-local views of exe objects ----

typedef Delegate<bool(int, const CMsgBoxData&)> ScBoxDelegate;

// The local player and the world (FUN_1403ed2d0 -> FUN_141bd0cc0).
class Unk_ScWorld { public: MyPC* FUN_141bd0cc0(); };
class WorldService   // C3: member view for the former free stand-ins
{
public:
    void* FUN_141bd0cc0();   // C3: the real member (0x141bd0cc0, the local player)
    static class WorldService* GetInstance();
};

  // the job level
class JobTable;

// The hot key label of the movie and the tab buttons.
class Unk_140acd6e0 : public ASButton {};
class Unk_ScButtonView : public AScript { public: MS2Ptr<Unk_140acd6e0> FUN_140acce30(const CString& strName); };
void FUN_140d01340(const Scaleform::GFx::Value& root, unsigned a, int b);

// The movie root of the dialog (RTTI .?AVASDialog@@).
class ASDialog : public ASDisplayObject {};

void* FUN_140d86260();   // C3: was FUN_140d86260
CStringW BlockFormat(int nStringId);
CStringW GetStringCommon(int nId);
CStringTable* GetStringTable();
void FUN_140d73aa0(CStringW text, int nType, void* pListener, CStringW tag);
void FUN_140d73bc0(int nStringId, int nType, void* pListener, CStringW tag);
MS2Ptr<CMsgBoxData> FUN_140d73e40(int nA, int nB, void* pListener, CStringW tag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
UIMessageBox* FUN_14151f890();
void FUN_14151f200();
void FUN_140710590(COutPacket& packet);
int FUN_1409e1b80(ASTooltip* p, int nId, int n);                    // the learned skill tooltip

// ---- the hot key state ----

Unk_ScHotKeyState::Unk_ScHotKeyState()
{
    Clear();
}

void Unk_ScHotKeyState::Clear()
{
    m_nKey = 0;
    m_nState = 0;
    m_strTab.Empty();
}

int Unk_ScHotKeyState::FUN_140fa35d0() const
{
    return !m_strTab.IsEmpty();
}

// ---- the dialog ----

// @0x140f9e200
UISkillCompactControlDialog::UISkillCompactControlDialog()
    : m_lstConfig(10)
{
    m_spButtonBar = 0;
    m_spAddButton = 0;
    m_bLoaded = 0;
    FUN_141924170(1);
}

// The destructor is implicit (the exe body at 0x140fa2f80 stores no vftable pointer).

// @0x140f9e330
CString UISkillCompactControlDialog::GetTypeName()
{
    return CString("SkillCompactControl");
}

// @0x140f9e380
int UISkillCompactControlDialog::vfunc_65()
{
    if (!UIDialog::vfunc_65())
        return 0;
    m_cur.Clear();
    return 1;
}

// @0x140f9e3c0
void UISkillCompactControlDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    MyPC* pPlayer = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer != 0)
        pPlayer->FUN_141523bc0()->FUN_141767df0(0);
    FUN_140fa1400();
    SendSkillMacroMode1();
    m_bLoaded = 0;
}

// @0x140f9e430
int UISkillCompactControlDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (pMsg->FUN_1422e4520() == 0 && pSender == dynamic_cast<UIMessageBox*>(pSender))
    {
        int nResult = pMsg->FUN_1422b8a10();
        FUN_14151f200();
        if (nResult == 0)
        {
            __int64 nId = FUN_140fa2520(CStringW(m_cur.m_strTab));
            FUN_140fa23f0(m_cur.m_nKey, nId);
            FUN_140fa2180(CStringW(m_cur.m_strTab));
        }
        else
        {
            __int64 nId = FUN_140fa2520(CStringW(m_prev.m_strTab));
            FUN_140fa23f0(m_prev.m_nKey, nId);
            FUN_140fa2180(CStringW(m_cur.m_strTab));
        }
        m_cur.Clear();
        MyPC* pPlayer = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
        if (pPlayer != 0)
            pPlayer->FUN_141523bc0()->FUN_141767df0(0);
    }
    return 1;
}

// @0x140f9e690
void UISkillCompactControlDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
}

// @0x140f9e6b0
void UISkillCompactControlDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_spButtonBar = 0;
    m_spAddButton = 0;
}

// The key capture: the pressed key is shown for the tab, a bound key asks first.
// @0x140f9e700
int UISkillCompactControlDialog::vfunc_13()
{
    if (vfunc_55() != 0)
        return 0;
    if (m_cur.m_nState != 0)
        return 0;
    if (m_cur.FUN_140fa35d0())
    {
        bool bGot = false;
        int nKey = 0;
        int nPressed = FUN_1409331f0()->FindActiveComboPrefixKey(0);
        if (nPressed != 0)
        {
            nKey = FUN_1409331f0()->FindActiveKey(0);
            if (nPressed != nKey)
            {
                if (FUN_1409331f0()->FUN_141430cb0(nKey) != 0)
                {
                    DAT_143acbd08 = 0;
                    bGot = false;
                    return 0;
                }
                if (nKey != 0)
                {
                    DAT_143acbd08 = 0;
                    bGot = true;
                }
                else
                {
                    if (nPressed != DAT_143acbd08)
                        DAT_143acbd08 = nPressed;
                    return 0;
                }
            }
            else
            {
                if (nPressed != DAT_143acbd08)
                    DAT_143acbd08 = nPressed;
                return 0;
            }
        }
        else
        {
            nKey = FUN_1409331f0()->FindActiveKey(0);
            if (nKey != 0)
            {
                DAT_143acbd08 = 0;
                bGot = true;
            }
            else if (DAT_143acbd08 != 0)
            {
                if (FUN_1409331f0()->FUN_141430b90(DAT_143acbd08) != 0)
                {
                    DAT_143acbd08 = 0;
                    bGot = false;
                    return 0;
                }
                nKey = DAT_143acbd08;
                DAT_143acbd08 = 0;
                bGot = true;
            }
        }
        if (bGot && nKey != 0)
        {
            int nSet = FUN_1409331f0()->FUN_1414319f0();
            if (nSet == 2)
            {
                if (nKey < 0x91)
                {
                    FUN_140d73aa0(BlockFormat(0x855), 0, static_cast<IMessageListener*>(this), CStringW(L""));
                    return 0;
                }
            }
            else if (0x91 < nKey)
            {
                FUN_140d73aa0(BlockFormat(0x854), 0, static_cast<IMessageListener*>(this), CStringW(L""));
                return 0;
            }
            if (FUN_1409331f0()->IsKeyRebindable(nKey) != 0)
            {
                if (FUN_140fa23a0(nKey) != 0)
                {
                    __int64 nId = FUN_140fa2520(CStringW(m_cur.m_strTab));
                    if (FUN_140fa23f0(nKey, nId) != 0)
                    {
                        FUN_140fa2180(CStringW(m_cur.m_strTab));
                        m_cur.Clear();
                    }
                }
                else
                {
                    m_cur.m_nState = 1;
                    m_cur.m_nKey = nKey;
                    unsigned __int64 nAction = FUN_1409331f0()->GetKeyAction(nKey);
                    CStringW strName;
                    if (FUN_1409331f0()->IsQuickSlotAction(nAction) != 0)
                        strName = StringFormat<CStringW, CStringW>(L"{0}[{1}]", GetStringTable()->FUN_1418125b0(FUN_1409331f0()->GetKeyAction(nKey)),
                                                FUN_1409331f0()->GetKeyName(nKey));
                    else
                        strName = GetStringTable()->FUN_1418125b0((unsigned)nAction);
                    if (FUN_1409331f0()->FUN_141430470(nAction) == 0)
                    {
                        FUN_140d73aa0(FormatStringId(0x84f, strName), 1, static_cast<IMessageListener*>(this), CStringW(L""));
                    }
                    else
                    {
                        __int64 nId = FUN_140fa2520(CStringW(m_cur.m_strTab));
                        if (FUN_140fa23f0(nKey, nId) != 0)
                        {
                            FUN_140fa2180(CStringW(m_cur.m_strTab));
                            m_cur.Clear();
                        }
                        MyPC* pPlayer = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
                        if (pPlayer != 0)
                            pPlayer->FUN_141523bc0()->FUN_141767df0(0);
                    }
                }
            }
            else
            {
                m_cur.Clear();
                FUN_140d73bc0(0x84c, 0, 0, CStringW(L""));
            }
            return 1;
        }
    }
    return UIDialog::vfunc_13();
}

// MS2-FUNCTIONAL: ops match the exe; only the rep movsb struct-copy encoding differs
// @0x140f9ef80
int UISkillCompactControlDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (m_bLoaded == 0)
        return 0;
    if (_stricmp(szMethod, "onChangeTab") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            m_strTab = data.FUN_1422b8f40();
            FUN_140fa16f0(CStringW(m_strTab));
            FUN_140fa2180(CStringW(m_strTab));
        }
    }
    else if (_stricmp(szMethod, "onClickCompactControlCheckbox") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            unsigned nSkillId = data.FUN_1422b8a10();
            int bOn = data.FUN_1422b8a90();
            MS2Ptr<CSkillCompactControlConfig> spConfig = FUN_140fa28b0(CStringW(m_strTab));
            if (spConfig.get() != 0)
            {
                if (bOn)
                    spConfig->m_skills.insert(nSkillId);
                else
                    spConfig->m_skills.erase(nSkillId);
            }
        }
        FUN_140fa1400();
    }
    else if (_stricmp(szMethod, "onRemoveTab") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            CStringW strName = data.FUN_1422b8f40();
            int nKey = FUN_1409331f0()->FUN_14142c940(FUN_140fa2520(CStringW(strName)), 0);
            FUN_140fa23f0(nKey, 0);
            FUN_140fa29f0(CStringW(strName));
        }
        FUN_140fa1400();
    }
    else if (_stricmp(szMethod, "onHotKeyFocusIn") == 0)
    {
        m_cur.Clear();
        m_cur.m_strTab = m_strTab;
        int nSet = FUN_1409331f0()->FUN_1414319f0();
        int nKey = FUN_1409331f0()->FUN_14142c940(FUN_140fa2520(CStringW(m_strTab)), nSet);
        m_prev.Clear();
        m_prev.m_nKey = nKey;
        m_prev.m_strTab = m_strTab;
        FUN_140fa23f0(nKey, 0);
        MyPC* pPlayer = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
        if (pPlayer != 0)
            pPlayer->FUN_141523bc0()->FUN_141767df0(1);
    }
    else if (_stricmp(szMethod, "onHotKeyFocusOut") == 0)
    {
        if (m_cur.m_nState == 0)
        {
            m_cur.Clear();
            MyPC* pPlayer = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
            if (pPlayer != 0)
                pPlayer->FUN_141523bc0()->FUN_141767df0(0);
        }
    }
    else if (_stricmp(szMethod, "onRenameTab") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            CStringW strName = data.FUN_1422b8f40();
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73e40(10, 0xc37, 0, CStringW(L""));
            if (spBox.get() != 0)
            {
                m_strRename = strName;
                spBox->FUN_141a01d30(0, strName, 5, 0, 0);
                spBox->FUN_141a027c0(ScBoxDelegate(this, &UISkillCompactControlDialog::FUN_140fa0820));
                FUN_140d73c60(spBox);
            }
        }
    }
    else if (_stricmp(szMethod, "onAddTab") == 0)
    {
        if (m_lstConfig.GetCount() < 3)
        {
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73e40(10, 0xc36, 0, CStringW(L""));
            if (spBox.get() != 0)
            {
                CStringW strName;
                spBox->FUN_141a01d30(0, strName, 5, 0, 0);
                spBox->FUN_141a027c0(ScBoxDelegate(this, &UISkillCompactControlDialog::FUN_140fa0d80));
                FUN_140d73c60(spBox);
            }
        }
    }
    else if (_stricmp(szMethod, "onResetHotKey") == 0)
    {
        MS2Ptr<CSkillCompactControlConfig> spConfig = FUN_140fa28b0(CStringW(m_strTab));
        if (spConfig.get() != 0)
        {
            spConfig->m_skills.clear();
            FUN_140fa16f0(CStringW(m_strTab));
        }
        m_cur.Clear();
        m_cur.m_strTab = m_strTab;
        int nKey = FUN_1409331f0()->FUN_14142c940(FUN_140fa2520(CStringW(m_strTab)), 0);
        FUN_140fa23f0(nKey, 0);
        FUN_140fa2180(CStringW(m_strTab));
        FUN_140fa1400();
    }
    else if (_stricmp(szMethod, "OnSelectAll") == 0)
    {
        MS2Ptr<CSkillCompactControlConfig> spConfig = FUN_140fa28b0(CStringW(m_strTab));
        if (spConfig.get() != 0)
        {
            spConfig->m_skills.clear();
            ATL::CAtlList<unsigned> lstSkills(10);
            FUN_140fa1460(&lstSkills);
            for (POSITION pos = lstSkills.GetHeadPosition(); pos != 0; lstSkills.GetNext(pos))
                spConfig->m_skills.insert(lstSkills.GetAt(pos));
            FUN_140fa16f0(CStringW(m_strTab));
        }
        FUN_140fa1400();
    }
    return 0;
}

// @0x140fa35c0
int UISkillCompactControlDialog::vfunc_48()
{
    return 0x4ef6;
}

// The tooltip of a skill row.
// @0x140f9fdb0
void UISkillCompactControlDialog::vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
    UIObject::vfunc_49(pRetVal, pArgs);
    MyPC* pPlayer = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return;
    CString strName = pArgs->FUN_1422b8d30();
    if (strName.Find("compactSkill", 0) != -1)
    {
        int nSkillId = pArgs->FUN_1422b8a10();
        ASTooltip tip(pPlayer, 0x10, 2);
        if (FUN_1409e1b80(&tip, nSkillId, 0) != 0)
        {
            *pRetVal = tip.FUN_1422bb870();
            return;
        }
    }
}

// The tabs from the server.
// @0x140f9fee0
void UISkillCompactControlDialog::vfunc_79(void* pPacket)
{
    UIDialog::vfunc_79(pPacket);
    if (static_cast<CInPacket*>(pPacket)->FUN_14070fe80() == 0xd1)
    {
        int nResult = static_cast<CInPacket*>(pPacket)->ReadUInt8();
        if (nResult == 0)
        {
            m_lstConfig.RemoveAll();
            CStringW strFirst;
            unsigned nTabs = static_cast<CInPacket*>(pPacket)->ReadInt32();
            for (unsigned i = 0; i < nTabs; i++)
            {
                MS2Ptr<CSkillCompactControlConfig> spConfig(new CSkillCompactControlConfig());
                spConfig->m_strName = static_cast<CInPacket*>(pPacket)->ReadUnicodeString();
                spConfig->m_30 = static_cast<CInPacket*>(pPacket)->ReadInt64();
                unsigned nSkills = static_cast<CInPacket*>(pPacket)->ReadInt32();
                for (unsigned j = 0; j < nSkills; j++)
                {
                    spConfig->m_skills.insert(static_cast<CInPacket*>(pPacket)->ReadInt32());
                }
                m_lstConfig.AddTail(spConfig);
                if (strFirst.IsEmpty())
                    strFirst = spConfig->m_strName;
            }
            if (m_lstConfig.IsEmpty())
            {
                strFirst = GetStringCommon(0xc39);
                FUN_140fa2720(CStringW(strFirst));
            }
            FUN_140fa1ff0();
            m_strTab = strFirst;
            if (m_30.get() != 0)
                m_30->Invoke("selectTab", CStringW(m_strTab));
            FUN_140fa16f0(CStringW(strFirst));
            FUN_140fa2180(CStringW(strFirst));
            m_bLoaded = 1;
        }
    }
}

// The platform answers of the web side tab requests.
// @0x140fa0420
void UISkillCompactControlDialog::vfunc_80(void* pRequest)
{
    Unk_BlockList req(*reinterpret_cast<CInPacket*>(pRequest));
    Unk_BlockEntry val;
    if (req.Find(CString("renameTab"), val) == 1)
    {
        if (val.m_nFlags == 0)
            FUN_140fa0a20(CStringW(val.m_strName));
        else
            FUN_140d73aa0(BlockFormat(0x8b7), 0, 0, CStringW(L""));
    }
    else if (req.Find(CString("AddTab"), val) == 1)
    {
        if (val.m_nFlags == 0)
            FUN_140fa0fa0(CStringW(val.m_strName));
        else
            FUN_140d73aa0(BlockFormat(0x8b7), 0, 0, CStringW(L""));
    }
}

// @0x140fa06a0
void UISkillCompactControlDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (m_30.get() != 0)
    {
        m_spButtonBar = m_30->FUN_140be23c0<ASButtonBar>("m_buttonBar");
        m_spAddButton = static_cast<Unk_ScButtonView*>(m_30.operator->())->FUN_140acce30("m_addButton");
    }
    COutPacket packet(static_cast<int>(SendOp::SkillMacro), 0);
    packet.Encode1(0);
    FUN_140710590(packet);
}

// The answer of the rename box: the new name travels to the platform first.
// @0x140fa0820
bool UISkillCompactControlDialog::FUN_140fa0820(int nResult, const CMsgBoxData& data)
{
    if (nResult == 0)
    {
        CStringW strText = data.FUN_141a02d50();
        strText = strText.Mid(strText.Find(L',', 0) + 1);
        if (strText.IsEmpty())
            return 0;
        Unk_BlockList req(0x4ef6);
        req.Add(CString("renameTab"), CStringW(strText), 0);
        req.SetEnabled(1);
        if (((class IClientPlatform*)FUN_140d86260())->vfunc_37(&req) == 1)
            return FUN_140fa0a20(CStringW(strText));
    }
    return 1;
}

// @0x140fa0a20
bool UISkillCompactControlDialog::FUN_140fa0a20(CStringW strName)
{
    if (strName.IsEmpty())
        return 0;
    MS2Ptr<CSkillCompactControlConfig> spConfig = FUN_140fa28b0(CStringW(strName));
    if (spConfig.get() != 0)
    {
        UIMessageBox* pBox = FUN_14151f890();
        if (pBox != 0)
            pBox->FUN_1419f82b0(GetStringCommon(0xc38));
        return 0;
    }
    FUN_14151f200();
    spConfig = FUN_140fa28b0(CStringW(m_strRename));
    if (spConfig.IsNull())
        return 0;
    spConfig->m_strName = strName;
    if (m_30.get() != 0)
        m_30->Invoke("renameTab", CStringW(m_strRename), CStringW(strName));
    FUN_140fa16f0(CStringW(strName));
    return 1;
}

// The answer of the add tab box.
// @0x140fa0d80
bool UISkillCompactControlDialog::FUN_140fa0d80(int nResult, const CMsgBoxData& data)
{
    if (nResult == 0)
    {
        if (m_lstConfig.GetCount() >= 3)
            return 0;
        CStringW strText = data.FUN_141a02d50();
        strText = strText.Mid(strText.Find(L',', 0) + 1);
        if (strText.IsEmpty())
            return 0;
        Unk_BlockList req(0x4ef6);
        req.Add(CString("AddTab"), CStringW(strText), 0);
        req.SetEnabled(1);
        if (((class IClientPlatform*)FUN_140d86260())->vfunc_37(&req) == 1)
            return FUN_140fa0fa0(CStringW(strText));
    }
    return 1;
}

// @0x140fa0fa0
bool UISkillCompactControlDialog::FUN_140fa0fa0(CStringW strName)
{
    if (strName.IsEmpty())
        return 0;
    {
        MS2Ptr<CSkillCompactControlConfig> spConfig = FUN_140fa28b0(CStringW(strName));
        if (spConfig.get() != 0)
        {
            UIMessageBox* pBox = FUN_14151f890();
            if (pBox != 0)
                pBox->FUN_1419f82b0(GetStringCommon(0xc38));
            return 0;
        }
    }
    FUN_14151f200();
    m_strTab = strName;
    FUN_140fa2720(CStringW(strName));
    FUN_140fa16f0(CStringW(strName));
    if (m_30.get() != 0)
        m_30->Invoke("AddTab", CStringW(strName), 1);
    return 1;
}

// The tabs back to the server.
// @0x140fa1240
void UISkillCompactControlDialog::SendSkillMacroMode1()
{
    COutPacket packet(static_cast<int>(SendOp::SkillMacro), 0);
    packet.Encode1(1);
    packet.Encode4(m_lstConfig.GetCount());
    for (POSITION pos = m_lstConfig.GetHeadPosition(); pos != 0; m_lstConfig.GetNext(pos))
    {
        MS2Ptr<CSkillCompactControlConfig> spConfig = m_lstConfig.GetAt(pos);
        packet.WriteUnicodeString(spConfig->m_strName);
        packet.Encode8(spConfig->m_30);
        packet.Encode4(spConfig->m_skills.size());
        for (std::set<unsigned>::iterator it = spConfig->m_skills.begin(); it != spConfig->m_skills.end(); ++it)
            packet.Encode4(*it);
    }
    FUN_140710590(packet);
}

// @0x140fa1400
void UISkillCompactControlDialog::FUN_140fa1400()
{
    MyPC* pPlayer = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer != 0)
        pPlayer->FUN_141523bc0()->SetCompactConfigs(&m_lstConfig);
}

// The exe's out-of-line IsNull COMDAT of the list pointer (0x140fa3060, shared by ICF).
static __declspec(noinline) bool Unk_CcSkillListIsNull(const Unk_CcSkillListPtr& sp)
{
    return sp.get() == 0;
}

// The skills of the player's job: the learnable ones first, then the others.
// @0x140fa1460
void UISkillCompactControlDialog::FUN_140fa1460(ATL::CAtlList<unsigned>* pList)
{
    MyPC* pPlayer = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return;
    Unk_CcSkillListPtr spSkills = CSkillCompactControlTable::GetJobSkills((Unk_CcJob)((class PC*)(class MyPC*)(pPlayer))->FUN_141654700());
    if (Unk_CcSkillListIsNull(spSkills))
        return;
    std::set<unsigned> setLearned;
    std::set<unsigned> setOther;
    for (POSITION pos = spSkills->GetHeadPosition(); pos != 0; spSkills->GetNext(pos))
    {
        Unk_CcSkillPtr spSkill = spSkills->GetAt(pos);
        int bLearned = pPlayer->FUN_1416546d0()->vfunc_2(spSkill->m_nSkillId);
        if (bLearned)
            setLearned.insert(spSkill->m_nSkillId);
        else
            setOther.insert(spSkill->m_nSkillId);
    }
    for (std::set<unsigned>::iterator it = setLearned.begin(); it != setLearned.end(); ++it)
        pList->AddTail(*it);
    for (std::set<unsigned>::iterator it = setOther.begin(); it != setOther.end(); ++it)
        pList->AddTail(*it);
}

// Rebuild the skill list of the movie for a tab.
// The job skills null test: the exe calls an out-of-line IsNull folded with MS2Ptr<JobSkill>::IsNull (0x140fa3060).
bool FUN_140fa3060(const Unk_CcSkillListPtr& sp);

// @0x140fa16f0
void UISkillCompactControlDialog::FUN_140fa16f0(CStringW strTab)
{
    MS2Ptr<CSkillCompactControlConfig> spConfig = FUN_140fa28b0(CStringW(strTab));
    if (spConfig.IsNull())
        spConfig = FUN_140fa2720(CStringW(strTab));
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
    {
        MyPC* pPlayer = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
        if (pPlayer == 0)
            return;
        Unk_CcSkillListPtr spSkills = CSkillCompactControlTable::GetJobSkills((Unk_CcJob)((class PC*)(class MyPC*)(pPlayer))->FUN_141654700());
        if (FUN_140fa3060(spSkills))
            return;
        ASArray arrSkills(2);
        std::set<unsigned> setLearned;
        std::set<unsigned> setOther;
        int nJobLevel = TSingleton<JobTable>::GetInstance()->GetJobRank(pPlayer->FUN_141654730());
        for (POSITION pos = spSkills->GetHeadPosition(); pos != 0; spSkills->GetNext(pos))
        {
            Unk_CcSkillPtr spSkill = spSkills->GetAt(pos);
            MS2Ptr<JobSkill> spLearned = pPlayer->FUN_1416546d0()->FindSkill(spSkill->m_nSkillId);
            if (spLearned == 0)
                continue;
            if (spLearned->GetJobLevel() > nJobLevel)
                continue;
            int bLearned = pPlayer->FUN_1416546d0()->vfunc_2(spSkill->m_nSkillId);
            if (bLearned != 0)
                setLearned.insert(spSkill->m_nSkillId);
            else
                setOther.insert(spSkill->m_nSkillId);
        }
        for (std::set<unsigned>::iterator it = setLearned.begin(); it != setLearned.end(); ++it)
        {
            unsigned nSkillId = *it;
            SkillData* pRow = reinterpret_cast<SkillDataTable*>(TSingleton<SkillDataTableCli>::GetInstance())->GetSkillData(nSkillId).get();
            if (pRow == 0)
                continue;
            int bSelected = spConfig->m_skills.find(nSkillId) != spConfig->m_skills.end();
            ASObj obj(2);
            obj.FUN_1407cb9c0("disable", 0);
            obj.FUN_1409c0d20("skillID", nSkillId);
            obj.FUN_1407cba60("iconPath", CString(pRow->m_strIcon));
            obj.FUN_1407cb9c0("selected", bSelected);
            arrSkills.FUN_1422bbf00(obj);
        }
        for (std::set<unsigned>::iterator it = setOther.begin(); it != setOther.end(); ++it)
        {
            unsigned nSkillId = *it;
            SkillData* pRow = reinterpret_cast<SkillDataTable*>(TSingleton<SkillDataTableCli>::GetInstance())->GetSkillData(nSkillId).get();
            if (pRow == 0)
                continue;
            int bSelected = spConfig->m_skills.find(nSkillId) != spConfig->m_skills.end();
            ASObj obj(2);
            obj.FUN_1407cb9c0("disable", 1);
            obj.FUN_1409c0d20("skillID", nSkillId);
            obj.FUN_1407cba60("iconPath", CString(pRow->m_strIcon));
            obj.FUN_1407cb9c0("selected", bSelected);
            arrSkills.FUN_1422bbf00(obj);
        }
        pDialog->FUN_140bd2cb0("buildSkills", arrSkills);
        pDialog->Invoke("selectTab", CStringW(strTab));
    }
}

// @0x140fa1ff0
void UISkillCompactControlDialog::FUN_140fa1ff0()
{
    if (m_lstConfig.IsEmpty())
        return;
    if (m_spButtonBar.IsNull())
        return;
    m_spButtonBar->FUN_1422e3400();
    int nIndex = 0;
    for (POSITION pos = m_lstConfig.GetHeadPosition(); pos != 0; m_lstConfig.GetNext(pos))
    {
        MS2Ptr<CSkillCompactControlConfig> spConfig = m_lstConfig.GetAt(pos);
        m_30->Invoke("AddTab", CStringW(spConfig->m_strName), nIndex);
        if (nIndex == 0)
            nIndex = 1;
    }
}

// The hot key label of the tab.
// @0x140fa2180
void UISkillCompactControlDialog::FUN_140fa2180(CStringW strTab)
{
    int nKey = FUN_1409331f0()->FUN_14142c940(FUN_140fa2520(CStringW(strTab)), FUN_1409331f0()->FUN_1414319f0());
    MS2Ptr<Unk_140acd6e0> spHotKey = static_cast<Unk_ScButtonView*>(m_30.operator->())->FUN_140acce30("m_hotKey");
    if (spHotKey)
    {
        CStringW strKey = FUN_1409331f0()->GetKeyName(nKey);
        spHotKey->FUN_1422cdfb0(strKey);
        spHotKey->SetFocused(0);
        if (nKey > 0x91)
            FUN_140d01340(spHotKey->FUN_1422ce400()->FUN_1422bb890(), 1, 2);
        else
            FUN_140d01340(spHotKey->FUN_1422ce400()->FUN_1422bb890(), 2, 2);
    }
}

// The key is not bound to an action yet.
// @0x140fa23a0
int UISkillCompactControlDialog::FUN_140fa23a0(int nKey)
{
    return FUN_1409331f0()->GetKeyAction(nKey) == 0;
}

// @0x140fa23f0
int UISkillCompactControlDialog::FUN_140fa23f0(int nKey, __int64 nId)
{
    int nSet = FUN_1409331f0()->FUN_1414319f0();
    if (FUN_1409331f0()->SetKeyBindingAndSync(nKey, 2, nId, 0, nSet) != 0)
    {
        MS2Ptr<CSkillCompactControlConfig> spConfig = FUN_140fa28b0(CStringW(m_cur.m_strTab));
        if (spConfig.IsNull() != 0)
            return 0;
        spConfig->m_30 = nId;
        FUN_1409331f0()->FUN_14142a8b0(nId);
        FUN_140fa1400();
        return 1;
    }
    return 0;
}

// The id of the tab's action: its own, else the first free one of the three.
// @0x140fa2520
__int64 UISkillCompactControlDialog::FUN_140fa2520(CStringW strTab)
{
    MS2Ptr<CSkillCompactControlConfig> spConfig = FUN_140fa28b0(CStringW(strTab));
    if (spConfig.IsNull() != 0)
        return 0;
    if (spConfig->m_30 != 0)
        return spConfig->m_30;
    for (unsigned nId = 0xaae61; nId <= 0xaae63; nId++)
    {
        BOOL bUsed = FALSE;
        for (POSITION pos = m_lstConfig.GetHeadPosition(); pos != 0; m_lstConfig.GetNext(pos))
        {
            spConfig = m_lstConfig.GetAt(pos);
            if (spConfig->m_30 == nId)
            {
                bUsed = TRUE;
                break;
            }
        }
        if (!bUsed)
            return nId;
    }
    return 0;
}

// @0x140fa2720
MS2Ptr<CSkillCompactControlConfig> UISkillCompactControlDialog::FUN_140fa2720(CStringW strName)
{
    MS2Ptr<CSkillCompactControlConfig> spConfig(new CSkillCompactControlConfig());
    spConfig->m_strName = strName;
    {
        ATL::CAtlList<unsigned> lstSkills(10);
        FUN_140fa1460(&lstSkills);
        for (POSITION pos = lstSkills.GetHeadPosition(); pos != 0; lstSkills.GetNext(pos))
            spConfig->m_skills.insert(lstSkills.GetAt(pos));
    }
    m_lstConfig.AddTail(spConfig);
    return spConfig;
}

// @0x140fa28b0
MS2Ptr<CSkillCompactControlConfig> UISkillCompactControlDialog::FUN_140fa28b0(CStringW strName)
{
    for (POSITION pos = m_lstConfig.GetHeadPosition(); pos != 0; m_lstConfig.GetNext(pos))
    {
        MS2Ptr<CSkillCompactControlConfig> spConfig = m_lstConfig.GetAt(pos);
        if (spConfig->m_strName.CompareNoCase(strName) == 0)
            return spConfig;
    }
    return MS2Ptr<CSkillCompactControlConfig>(0);
}

// @0x140fa29f0
void UISkillCompactControlDialog::FUN_140fa29f0(CStringW strName)
{
    for (POSITION pos = m_lstConfig.GetHeadPosition(); pos != 0; m_lstConfig.GetNext(pos))
    {
        MS2Ptr<CSkillCompactControlConfig> spConfig = m_lstConfig.GetAt(pos);
        if (spConfig->m_strName.CompareNoCase(strName) == 0)
        {
            m_lstConfig.RemoveAt(pos);
            return;
        }
    }
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142caa420-0x142caa4e0 .text$yd
