// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UINpcControlDialog: see uinpccontroldialog.h.
// MS2-UNIT: ?\uinpccontroldialog.cpp
// MS2-RANGE: 0x141a623e0-0x141a6a470 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?get@?$MS2Ptr@VAiDebugDialog@@@@QEBAPEAVAiDebugDialog@@XZ 0x141a68560 ; order
// MS2-PIN: ?vfunc_48@UINpcControlDialog@@UEAAHXZ 0x141a68840 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_CtlSkill@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_CtlSkill@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@H@2@XZ 0x141a694a0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_CtlSkill@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_CtlSkill@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@H@2@XZ 0x141a694b0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@UUnk_CtlSkill@@@std@@V?$_Vector_val@U?$_Simple_types@UUnk_CtlSkill@@@std@@@2@$00@std@@QEBAAEBV?$allocator@UUnk_CtlSkill@@@2@XZ 0x141a694f0 ; unique
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VAiDebugDialog@@@@AEAAXPEAX@Z 0x141a69980 ; unique
// MS2-PIN: ??C?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_CtlSkill@@@std@@@std@@@std@@@std@@QEBAPEAU?$pair@$$CBHUUnk_CtlSkill@@@1@XZ 0x141a68570 ; manual
// MS2-PIN: ??D?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_CtlSkill@@@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBHUUnk_CtlSkill@@@1@XZ 0x141a685b0 ; manual
// MS2-PIN: ?pointer_to@?$pointer_traits@PEAU?$pair@$$CBHUUnk_CtlSkill@@@std@@@std@@SAPEAU?$pair@$$CBHUUnk_CtlSkill@@@2@AEAU32@@Z 0x141a6a2a0 ; manual
// MS2-PINS-END tplpin
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uinpccontroldialog.cpp"    // assumed
// The ASUIComponent slot list (validateNow = 24, ASCoreList's dataProvider setter = 25) for the list calls.
#define MS2_ASUICOMPONENT_SLOTS
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/ascorelist.h"

#include "uinpccontroldialog.h"

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

#include "uinpccreatedialog.h"
#include "aidebugdialog.h"
#include "pcbase.h"
#include "ms2/placeholder/fittingdollpc.h"  // C3: PC (efd::DynamicCast<PC, GameObject>)
#include "ms2/ms2format.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/ms2ptr_impl.h"

// MS2Ptr<AiDebugDialog>: CPtred is a secondary base (+0x130), so the exe's ctor / AddRef / Release go through the
// (null-checked) pointer conversions.
// @0x141a68850
template <> void MS2Ptr<AiDebugDialog>::AddRef() const
{
    if (m_p)
        AddRefImpl(static_cast<CPtred*>(static_cast<AiDebugDialog*>(0)));
}

// @0x141a69920
template <> void MS2Ptr<AiDebugDialog>::Release()
{
    if (m_p)
    {
        ReleaseImpl(static_cast<CPtred*>(static_cast<AiDebugDialog*>(0)));
        m_p = 0;
    }
}

// @0x141a67f30
template <> MS2Ptr<AiDebugDialog>::MS2Ptr(AiDebugDialog* p)
{
    m_p = static_cast<AiDebugDialog*>(static_cast<CPtred*>(p));
    AddRef();
}

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/placeholder/cnpc.h"
#include "ms2/client/ms2/worldservice.h"
#include <efd/Win32/Win32PlatformService.h>  // C3: efd::Win32PlatformService::GetWindowRef

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// The key input state (singleton).
class Unk_CtlKeys : public CInputKeyHandler {};
void* FUN_14025e7c0();   // C3: was FUN_14025e7c0

// The ui text service (singleton): the text of a "$s_..." key.
class GFxManager { public: CStringW Localize(const CString& strKey); };   // C3: the real member (0x1422b0570, a $-key's localized string)
class Unk_AltStringMgr* GetGFxManager();   // C3: the GFxManager (calls cast back)

// The game object of an object id (WorldService::FUN_141bd1180 / FUN_141bd1320 result).
class Unk_CtlObj;
// A game object that is an npc: the name of its data row.
class Unk_CtlNpc : public CNpc { };
class Unk_CameraTargetEntity* FUN_140a38a00(class Unk_BossObject*);   // C3: was FUN_140a38a00
CStringW FUN_1401aa6a0(int nNpc);                  // the name text of an npc id

// Formatters instantiated by other units.

// The key of a command group: str == psz.

class UIDailyMissionDialog { public: MS2Ptr<ASScrollingList> GetScrollingList(const CString& strName); };

// The main window.
void* FUN_140aadf80();   // C3: was FUN_140aadf80

void FUN_141632630(const CStringW& str, std::vector<int>& out, const wchar_t* szDelim);   // split into numbers


void FUN_140988d60(CStringW& str, std::vector<CStringW>& out, const wchar_t* szDelim);    // split a text
__int64 ParseInt64W(const CStringW& str);
int FUN_140718200(const CStringW& str);
unsigned ParseUIntW(const CStringW& str);
unsigned long ParseULongW(const CStringW& str);
CStringW GetFullPath(const CStringW& strDir);
CStringW FUN_141b6e360(const CStringW& strDir, const wchar_t* szFilter, const CStringW& strDefault);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// The UCRT's `static __inline memcpy_s` copy of this TU (kept alive by the pointer below).
// @0x141a6a350
#pragma function(memset, memcpy)
static __inline errno_t ms2_nc_memcpy_s(void* const d, size_t const dsz, void const* const s, size_t const ssz)
{
    if (ssz == 0) { return 0; }
    { int e = !!(d != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    { int e = !!(s != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    { int e = !!(dsz >= ssz); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
    memcpy(d, s, ssz);
    return 0;
}
#pragma intrinsic(memset, memcpy)
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnNcMemcpyS)(void*, size_t, const void*, size_t) = &ms2_nc_memcpy_s;

// @0x141a65420
static bool IsValidIndex(const std::vector<int>& v, int i)
{
    int n = (int)v.size();
    if (i < 0 || i > n - 1)
        return false;
    return true;
}

// @0x141a65c70
void ASObj::FUN_141a65c70(const char* szName, int n)
{
    ASData data;
    data.AddInt(n);
    ((Scaleform::GFx::Value*)(void*)(&m_value))->SetMember(szName, data.PopValue());
}

// @0x141a623e0
UINpcControlDialog::UINpcControlDialog()
{
    m_40 = 1;
    m_nNpcId = 0;
    FUN_1422dc3b0(1);
}

// @0x141a624b0
CString UINpcControlDialog::GetTypeName()
{
    return "NpcControlDialog";
}

// @0x141a62500
void UINpcControlDialog::vfunc_79(void* p)
{
    UIDialog::vfunc_79(p);
    int nOp = static_cast<CInPacket*>(p)->GetOpcode();
    if (nOp != 0x87)
        return;
    {
        int nKind = static_cast<CInPacket*>(p)->ReadUInt8();
        if (nKind == 6) {
            m_skills.clear();
            int nCount = static_cast<CInPacket*>(p)->ReadInt32();
            for (int i = 0; i < nCount; i++) {
                Unk_CtlSkill skill;
                skill.nId = static_cast<CInPacket*>(p)->ReadInt32();
                skill.nLevel = static_cast<CInPacket*>(p)->ReadInt32();
                int nKey = (int)(m_skills.size() + 1000);
                m_skills.insert(std::make_pair(nKey, skill));
            }
        } else if (nKind == 5) {
            if (m_30.IsNull())
                return;
            int nId = static_cast<CInPacket*>(p)->ReadInt32();
            if (nId != m_nNpcId)
                return;
            PCBase* pActor = reinterpret_cast<PCBase*>(WorldService::GetInstance()->FindNpcById(nId));
            if (pActor == 0)
                return;
            CString strNode = static_cast<CInPacket*>(p)->ReadUnicodeStringA();
            CString strAction = static_cast<CInPacket*>(p)->ReadUnicodeStringA();
            int nTarget = (int)static_cast<CInPacket*>(p)->ReadInt64();
            CStringW strExtra(L"ExtraData");
            bool bTracking = static_cast<CInPacket*>(p)->ReadBool();
            if (bTracking)
                strExtra += "(Tracking)";
            int nExtra = static_cast<CInPacket*>(p)->ReadInt32();
            for (int i = 0; i < nExtra; i++) {
                CString strKey = static_cast<CInPacket*>(p)->ReadUnicodeStringA();
                int nValue = static_cast<CInPacket*>(p)->ReadInt32();
                strExtra += StringFormat<CString, int>(L"\n{0} : {1}", strKey, nValue);
            }
            CStringW strTarget(L"");
            Unk_CtlObj* pObj = reinterpret_cast<Unk_CtlObj*>(WorldService::GetInstance()->FindObjectById(nTarget));
            if (pObj != 0) {
                PCBase* pPc = reinterpret_cast<PCBase*>(efd::DynamicCast<PC, GameObject>(reinterpret_cast<GameObject*>(pObj)));
                if (pPc != 0) {
                    strTarget = pPc->vfunc_77();
                } else {
                    Unk_CtlNpc* pNpc = ((class Unk_CtlNpc*)FUN_140a38a00((class Unk_BossObject*)(pObj)));
                    if (pNpc != 0)
                        strTarget = pNpc->GetName();
                }
            }
            __int64 nPap = static_cast<CInPacket*>(p)->ReadInt64();
            __int64 nMap = static_cast<CInPacket*>(p)->ReadInt64();
            __int64 nNdd = static_cast<CInPacket*>(p)->ReadInt64();
            __int64 nCap = static_cast<CInPacket*>(p)->ReadInt64();
            __int64 nHp = static_cast<CInPacket*>(p)->ReadInt64();
            __int64 nMhp = static_cast<CInPacket*>(p)->ReadInt64();
            if (m_strCurrent != strNode)
                m_strPrev = m_strCurrent;
            m_strCurrent = strNode;
            CStringW strInfo = StringFormat(L"{0}\n\nCurrent : {1}\nPrev : {2}\nTarget : {3}\n", strAction, m_strCurrent, m_strPrev, strTarget);
            int nZ = (int)pActor->vfunc_18().z;
            int nY = (int)pActor->vfunc_18().y;
            int nX = (int)pActor->vfunc_18().x;
            strInfo += StringFormat<int, int, int>(L"\nX: {0}\nY: {1}\nZ: {2}", nX, nY, nZ);
            strInfo += StringFormat<CStringW>(L"\n\n{0}", strExtra);
            CStringW strStat = StringFormat(L"Current Stat\nPAP : {0}\nMAP : {1}\nNDD : {2}\nCAP : {3}\nHP : {4}\nMHP : {5}", nPap, nMap, nNdd, nCap, nHp, nMhp);
            if (m_30.get() != 0) {
                m_30->Invoke("SetAiText", strInfo);
                m_30->Invoke("SetStatText", strStat);
            }
        } else if (nKind == 7) {
            CString strFile = static_cast<CInPacket*>(p)->ReadUnicodeStringA();
            int nId = static_cast<CInPacket*>(p)->ReadInt32();
            m_spAi.AssignRaw(new AiDebugDialog(0));
            m_spAi->SetTarget(strFile, nId);
            AiDebugDialog* pAi = m_spAi.operator->();
            pAi->Create(0xa5, CWnd::FromHandle(((efd::Win32PlatformService*)FUN_140aadf80())->GetWindowRef()));
        } else if (nKind == 8) {
            int nId = static_cast<CInPacket*>(p)->ReadInt32();
            int nLine = static_cast<CInPacket*>(p)->ReadInt32();
            PCBase* pActor = reinterpret_cast<PCBase*>(WorldService::GetInstance()->FindNpcById(nId));
            if (pActor == 0)
                return;
            if (m_spAi == 0)
                return;
            m_spAi->AddLine(nId, nLine);
        }
    }
}

// @0x141a63280
void UINpcControlDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    UpdateNpcName();
}

// @0x141a632b0
void UINpcControlDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (m_30.IsNull())
        return;
    ASObj obj(2);
    m_30->Invoke("initData", obj.GetValue());
}

// @0x141a63390
int UINpcControlDialog::vfunc_13()
{
    if (UIDialog::vfunc_13() != 0)
        return 1;
    if (((class Unk_CtlKeys*)FUN_14025e7c0())->WasKeyPressed(0x1c, 0, 0)) {
        if (m_30.get() != 0)
            m_30->Invoke("onEnterKey");
        return 1;
    } else if (((class Unk_CtlKeys*)FUN_14025e7c0())->WasKeyPressed(0xf, 0, 0)) {
        if (m_30.get() != 0)
            m_30->Invoke("onTabKey");
        return 1;
    } else if (((class Unk_CtlKeys*)FUN_14025e7c0())->IsEscapePressed()) {
        vfunc_67();
        return 1;
    }
    return 0;
}

// @0x141a634d0
int UINpcControlDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    UIDialog::vfunc_28(szMethod, pArgs, nArgs);
    ASData data;
    if (_stricmp("OnCommandChange", szMethod) == 0) {
        data.SetArgsIfAny(pArgs, nArgs);
        return 1;
    } else if (_stricmp("OnGroupChange", szMethod) == 0) {
        if (data.SetArgsIfAny(pArgs, nArgs) != 0) {
            FUN_141a63ce0(data.FUN_1422b8d30());
        }
        return 1;
    } else if (_stricmp("OnExecute", szMethod) == 0) {
        if (data.SetArgsIfAny(pArgs, nArgs) != 0) {
            int nCommand = data.PopUInt();
            CStringW strArg = data.FUN_1422b8f40();
            FUN_141a64ba0(nCommand, strArg);
        }
        return 1;
    } else if (_stricmp("OnStopSkill", szMethod) == 0) {
        COutPacket pkt(static_cast<int>(SendOp::SetDebugMode), 0);
        pkt.WriteUInt8(4);
        pkt.WriteInt32(m_nNpcId);
        pkt.WriteUInt8(9);
        FUN_140710590(pkt);
        return 1;
    }
    return 0;
}

// @0x141a63770
void UINpcControlDialog::UpdateNpcName()
{
    PCBase* pActor = reinterpret_cast<PCBase*>(WorldService::GetInstance()->FindNpcById(m_nNpcId));
    if (pActor == 0)
        return;
    CStringW strName = FUN_1401aa6a0(((class CNpc*)(class PCBase*)(pActor))->GetNpcId());
    int nNpc = ((class CNpc*)(class PCBase*)(pActor))->GetNpcId();
    CStringW strTitle = StringFormat<CStringW, unsigned, unsigned>(L"[{0}] [GameOID : {1}] [npcID : {2}]", strName, reinterpret_cast<const unsigned&>(m_nNpcId), reinterpret_cast<const unsigned&>(nNpc));
    if (MS2Ptr<ASTextField> spName = GetChild<ASTextField>("m_npcName"))
        spName->SetTextW(strTitle);
}

// @0x141a638c0
void UINpcControlDialog::SetNpcId(int nNpcId)
{
    m_nNpcId = nNpcId;
}

// @0x141a638e0
int UINpcControlDialog::GetLoopCount()
{
    if (m_30.IsNull())
        return 0;
    return ((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(m_30->Invoke("GetLoopCount")))->GetUInt();
}

// @0x141a63970
void UINpcControlDialog::SendNpcCommand(int nCmd, __int64 nValue)
{
    if (m_nNpcId == 0)
        return;
    COutPacket pkt(static_cast<int>(SendOp::SetDebugMode), 0);
    pkt.WriteUInt8(4);
    pkt.WriteInt32(m_nNpcId);
    pkt.WriteUInt8((unsigned char)nCmd);
    pkt.WriteInt64(nValue);
    FUN_140710590(pkt);
}

// @0x141a63a10
void UINpcControlDialog::FUN_141a63a10(int nCmd, const CStringW& strArgs)
{
    int nLoop = GetLoopCount();
    if (nLoop <= 0)
        return;
    std::vector<int> args;
    std::vector<Unk_CtlSkill> skills;
    do {
        FUN_141632630(strArgs, args, L",/[] ");
        int nArgs = (int)args.size();
        if (nArgs <= 0) {
            int nKey = nCmd;
            Unk_CtlSkill skill = m_skills[nKey];
            skills.push_back(skill);
            break;
        }
        for (int i = 0; i < nArgs; i += 2) {
            if (!IsValidIndex(args, i))
                break;
            if (!IsValidIndex(args, i + 1))
                break;
            int nId = args[i];
            unsigned short nLevel = *(unsigned short*)&args[i + 1];
            Unk_CtlSkill skill;
            skill.nId = nId;
            skill.nLevel = nLevel;
            skills.push_back(skill);
        }
    } while (0);
    int nSkills = (int)skills.size();
    if (nSkills <= 0)
        return;
    COutPacket pkt(static_cast<int>(SendOp::SetDebugMode), 0);
    pkt.WriteUInt8(4);
    pkt.WriteInt32(m_nNpcId);
    pkt.WriteUInt8(8);
    pkt.WriteInt16((short)nLoop);
    pkt.WriteInt16((short)nSkills);
    for (int j = 0; j < nSkills; j++) {
        pkt.WriteInt32(skills[j].nId);
        pkt.WriteInt32(skills[j].nLevel);
    }
    FUN_140710590(pkt);
}

// @0x141a63ce0
void UINpcControlDialog::FUN_141a63ce0(const CString& strGroup)
{
    MS2Ptr<ASScrollingList> spList = reinterpret_cast<UIDailyMissionDialog*>(this)->GetScrollingList("m_items");
    if (spList.IsNull())
        return;
    spList->FUN_1422dd1d0();
    if ((strGroup == "ALL") || (strGroup == "STAT")) {
        ASObj itemHpPercent(2);
        itemHpPercent.SetWStringMember("label", reinterpret_cast<GFxManager*>(GetGFxManager())->Localize("$s_npccontrol_dialog_msg_hp_percent_apply"));
        itemHpPercent.FUN_141a65c70("commandId", 1);
        spList->AddItem(itemHpPercent);
        ASObj itemHp(2);
        itemHp.SetWStringMember("label", reinterpret_cast<GFxManager*>(GetGFxManager())->Localize("$s_npccontrol_dialog_msg_hp_apply"));
        itemHp.FUN_141a65c70("commandId", 2);
        spList->AddItem(itemHp);
        ASObj itemDamage(2);
        itemDamage.SetWStringMember("label", reinterpret_cast<GFxManager*>(GetGFxManager())->Localize("$s_npccontrol_dialog_msg_fix_damage"));
        itemDamage.FUN_141a65c70("commandId", 10);
        spList->AddItem(itemDamage);
    }
    if ((strGroup == "ALL") || (strGroup == "AI")) {
        {
            ASObj itemAiOn(2);
            itemAiOn.SetWStringMember("label", reinterpret_cast<GFxManager*>(GetGFxManager())->Localize("$s_npccontrol_dialog_msg_ai_on"));
            itemAiOn.FUN_141a65c70("commandId", 3);
            spList->AddItem(itemAiOn);
        }
        {
            ASObj itemAiOff(2);
            itemAiOff.SetWStringMember("label", reinterpret_cast<GFxManager*>(GetGFxManager())->Localize("$s_npccontrol_dialog_msg_ai_off"));
            itemAiOff.FUN_141a65c70("commandId", 4);
            spList->AddItem(itemAiOff);
        }
        {
            ASObj itemTrace(2);
            itemTrace.SetWStringMember("label", reinterpret_cast<GFxManager*>(GetGFxManager())->Localize("$s_npccontrol_dialog_msg_trace_ai"));
            itemTrace.FUN_141a65c70("commandId", 5);
            spList->AddItem(itemTrace);
        }
        {
            ASObj itemTraceClient(2);
            itemTraceClient.SetWStringMember("label", reinterpret_cast<GFxManager*>(GetGFxManager())->Localize("$s_npccontrol_dialog_msg_trace_ai_client"));
            itemTraceClient.FUN_141a65c70("commandId", 6);
            spList->AddItem(itemTraceClient);
        }
        {
            ASObj itemBattle(2);
            itemBattle.SetWStringMember("label", reinterpret_cast<GFxManager*>(GetGFxManager())->Localize("$s_npccontrol_dialog_msg_battle_setting"));
            itemBattle.FUN_141a65c70("commandId", 7);
            spList->AddItem(itemBattle);
        }
        {
            ASObj itemFile(2);
            itemFile.SetWStringMember("label", reinterpret_cast<GFxManager*>(GetGFxManager())->Localize("$s_npccontrol_dialog_msg_change_ai_file"));
            itemFile.FUN_141a65c70("commandId", 0xb);
            spList->AddItem(itemFile);
        }
    }
    if ((strGroup == "ALL") || (strGroup == "ADDITIONAL")) {
        ASObj itemAdd(2);
        itemAdd.SetWStringMember("label", reinterpret_cast<GFxManager*>(GetGFxManager())->Localize("$s_npccontrol_dialog_msg_add_additional"));
        itemAdd.FUN_141a65c70("commandId", 0xc);
        spList->AddItem(itemAdd);
        ASObj itemRemove(2);
        itemRemove.SetWStringMember("label", reinterpret_cast<GFxManager*>(GetGFxManager())->Localize("$s_npccontrol_dialog_msg_remove_additional"));
        itemRemove.FUN_141a65c70("commandId", 0xd);
        spList->AddItem(itemRemove);
        ASObj itemCurrent(2);
        itemCurrent.SetWStringMember("label", reinterpret_cast<GFxManager*>(GetGFxManager())->Localize("$s_npccontrol_dialog_msg_current_additional"));
        itemCurrent.FUN_141a65c70("commandId", 0xe);
        spList->AddItem(itemCurrent);
    }
    if ((strGroup == "ALL") || (strGroup == "SKILL")) {
        std::map<int, Unk_CtlSkill>::iterator it = m_skills.begin();
        std::map<int, Unk_CtlSkill>::const_iterator itEnd = m_skills.end();
        for (; it != itEnd; ++it) {
            int nCommand = it->first;
            const Unk_CtlSkill* pSkill = &it->second;
            CStringW strLabel;
            strLabel.Format(L"[%d] [Lv. %d] [%s]", pSkill->nId, pSkill->nLevel,
                            (const wchar_t*)TSingleton<CStringTable>::GetInstance()->FUN_141811980(4, pSkill->nId));
            ASObj itemSkill(2);
            itemSkill.SetWStringMember("label", strLabel);
            itemSkill.SetIntMember("commandId", nCommand);
            spList->AddItem(itemSkill);
        }
    }
    if ((strGroup == "ALL") || (strGroup == "ETC")) {
        ASObj itemAssist(2);
        itemAssist.SetWStringMember("label", reinterpret_cast<GFxManager*>(GetGFxManager())->Localize("$s_npccontrol_dialog_msg_assist"));
        itemAssist.FUN_141a65c70("commandId", 8);
        spList->AddItem(itemAssist);
        ASObj itemExtra(2);
        itemExtra.SetWStringMember("label", reinterpret_cast<GFxManager*>(GetGFxManager())->Localize("$s_npccontrol_dialog_msg_extra"));
        itemExtra.FUN_141a65c70("commandId", 9);
        spList->AddItem(itemExtra);
    }
    spList->vfunc_24(true);
}

// @0x141a64ba0
void UINpcControlDialog::FUN_141a64ba0(int nCommand, const CStringW& strArg)
{
    __int64 nArg = ParseInt64W(strArg);
    if (nCommand == 1) {
        if (0 < nArg && nArg <= 0x64)
            SendNpcCommand(1, nArg);
    } else if (nCommand == 2) {
        if (0 < nArg)
            SendNpcCommand(2, nArg);
    } else if (nCommand == 3) {
        SendNpcCommand(4, 0);
    } else if (nCommand == 4) {
        SendNpcCommand(5, 0);
    } else if (nCommand == 5) {
        SendNpcCommand(6, 0);
    } else if (nCommand == 6) {
        if (m_spAi) {
            m_spAi->RequestTrace();
            SendMessageA(m_spAi->GetSafeHwnd(), 0x10, 0, 0);
            m_spAi.AssignRaw(0);
        }
        SendNpcCommand(7, 1);
    } else if (nCommand == 7) {
        SendNpcCommand(3, nArg);
    } else if (nCommand == 8) {
        SendNpcCommand(10, 0);
    } else if (nCommand == 9) {
        SendNpcCommand(0xb, 0);
    } else if (nCommand == 10) {
    } else if (nCommand == 0xc) {
        if (m_nNpcId == 0)
            return;
        std::vector<CStringW> parts;
        FUN_140988d60(const_cast<CStringW&>(strArg), parts, L",");
        int nAdditional;
        unsigned short nLevel;
        int nExtra;
        nAdditional = 0;
        nLevel = 1;
        nExtra = 0;
        if (parts.size() >= 1)
            nAdditional = FUN_140718200(parts[0]);
        if (parts.size() >= 2)
            nLevel = ParseUIntW(parts[1]);
        if (parts.size() >= 3)
            nExtra = ParseULongW(parts[2]);
        if (nAdditional == 0)
            return;
        COutPacket pkt(static_cast<int>(SendOp::SetDebugMode), 0);
        pkt.WriteUInt8(4);
        pkt.WriteInt32(m_nNpcId);
        pkt.WriteUInt8(0xe);
        pkt.WriteInt32(nAdditional);
        pkt.WriteInt32(nLevel);
        pkt.WriteInt32(nExtra);
        FUN_140710590(pkt);
    } else if (nCommand == 0xd) {
        SendNpcCommand(0xf, nArg);
    } else if (nCommand == 0xe) {
        SendNpcCommand(0x10, 0);
    } else if (nCommand == 0xb) {
        FUN_141a65000();
    } else if (nCommand / 1000 == 1) {
        FUN_141a63a10(nCommand, strArg);
    }
}

// @0x141a65000
void UINpcControlDialog::FUN_141a65000()
{
    if (PathIsDirectoryW(L"./Data/Xml/AI") == 0)
        CreateDirectoryW(L"./Data/Xml/AI", 0);
    CStringW strFile = FUN_141b6e360(GetFullPath(L"./Data/Xml/AI"), L"xml Files (*.xml)", L"");
    if (strFile.IsEmpty())
        return;
    if (m_nNpcId == 0)
        return;
    COutPacket pkt(static_cast<int>(SendOp::SetDebugMode), 0);
    pkt.WriteUInt8(4);
    pkt.WriteInt32(m_nNpcId);
    pkt.WriteUInt8(0xd);
    pkt.WriteUnicodeString(strFile);
    FUN_140710590(pkt);
}
