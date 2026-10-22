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
#include "ms2/placeholder/ms2stdafx.h"

#include "uinpccontroldialog.h"

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

#include "uinpccreatedialog.h"
#include "aidebugdialog.h"
#include "pcbase.h"
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

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// The list control of the movie (the AS list with clear / append / refresh).
class Unk_CtlList : public AScript
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);
    void FUN_1422dd1d0();                               // clear
    void FUN_1422dd230(const ASObj& row);               // append a row
};

// The key input state (singleton).
class Unk_CtlKeys { public: bool FUN_14116d9c0(int nKey, int a, int b); bool FUN_14116d840(); };
Unk_CtlKeys* FUN_14025e7c0();

// The ui text service (singleton): the text of a "$s_..." key.
class Unk_CtlText { public: CStringW FUN_1422b0570(const CString& strKey); };
Unk_CtlText* FUN_14025e7a0();

// The world: the actor / game object of an object id.
class Unk_CtlObj;
class Unk_CtlWorld
{
public:
    PCBase* FUN_141bd1320(int nId);                     // the actor of an object id
    Unk_CtlObj* FUN_141bd1180(int nId);                 // the game object of an object id
};
Unk_CtlWorld* FUN_1403ed2d0();

// A game object that is an npc: the name of its data row.
class Unk_CtlNpc { public: CStringW FUN_141093310(); };
PCBase* FUN_14099eef0(Unk_CtlObj* pObj);                // efd::DynamicCast<PC>
Unk_CtlNpc* FUN_140a38a00(Unk_CtlObj* pObj);
int FUN_141092fa0(PCBase* pActor);                      // the npc id of an actor
CStringW FUN_1401aa6a0(unsigned nNpc);                  // the name text of an npc id

// Formatters instantiated by other units.
CStringW FUN_1409e8180(const wchar_t* szFormat, const CStringW& a, const int& b, const int& c);
CStringW FUN_14136e740(const wchar_t* szFormat, const CString& a, const int& b);
CStringW FUN_1406a7830(const wchar_t* szFormat, const int& a, const int& b, const int& c);
CStringW FUN_1401e8510(const wchar_t* szFormat, const CStringW& a);
bool FUN_1401647e0(const CString& a, const CString& b);     // differs

// The key of a command group: str == psz.
bool FUN_140184310(const CString& str, const char* psz);

// The main window.
class Unk_CtlScreen;
Unk_CtlScreen* FUN_140aadf80();
HWND FUN_14209c720(Unk_CtlScreen* pScreen);

// std::vector<int> as the exe's helper units instantiate it.
class Unk_CtlIntVec
{
public:
    Unk_CtlIntVec();                                    // 0x140182ea0
    ~Unk_CtlIntVec();                                   // 0x140183b60
    unsigned __int64 FUN_1401910d0() const;             // count
    int& FUN_1404f0a10(unsigned __int64 i);             // operator[]
private:
    void* m_0; void* m_8; void* m_10;
};
MS2_CHECK_SIZE(Unk_CtlIntVec, 0x18);
void FUN_141632630(const CStringW& str, Unk_CtlIntVec& out, const wchar_t* szDelim);   // split into numbers

void FUN_1407cd930(Scaleform::GFx::Value* pObject, const char* szName, const Scaleform::GFx::Value& v);   // set a member
int FUN_1409c17e0(const Scaleform::GFx::Value& v);
CStringTable* GetStringTable();

void FUN_140988d60(CStringW& str, Unk_NpcFileList& out, const wchar_t* szDelim);    // split a text
__int64 FUN_140718320(const CStringW& str);
unsigned short FUN_140718200(const CStringW& str);
unsigned FUN_140718140(const CStringW& str);
unsigned long FUN_1407182c0(const CStringW& str);
CStringW FUN_1418fe4e0(const CStringW& strDir);
CStringW FUN_141b6e360(const CStringW& strDir, const wchar_t* szFilter, const CStringW& strDefault);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// The UCRT's `static __inline memcpy_s` copy of this TU (kept alive by the pointer below).
// @0x141a6a350
// MS2-FUNCTIONAL: CRT memcpy_s copy: source spelling differs
static __inline errno_t ms2_nc_memcpy_s(void* const d, size_t const dsz, void const* const s, size_t const ssz)
{
    if (ssz == 0) { return 0; }
    { int e = !!(d != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    { int e = !!(s != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    { int e = !!(dsz >= ssz); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
    memcpy(d, s, ssz);
    return 0;
}
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnNcMemcpyS)(void*, size_t, const void*, size_t) = &ms2_nc_memcpy_s;

// @0x141a65420
static bool FUN_141a65420(const Unk_CtlIntVec& v, int i)
{
    int n = (int)v.FUN_1401910d0() - 1;
    return i >= 0 && i <= n;
}

// @0x141a65c70
void ASObj::FUN_141a65c70(const char* szName, int n)
{
    ASData data;
    data.FUN_1422b7f70(n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}

// @0x141a68340
UINpcControlDialog::~UINpcControlDialog()
{
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
    CInPacket* pPkt = static_cast<CInPacket*>(p);
    UIDialog::vfunc_79(p);
    if (pPkt->FUN_14070fe80() == 0x87) {
        char nKind = pPkt->vfunc_o8_1();
        if (nKind == 6) {
            m_skills.clear();
            int nCount = pPkt->vfunc_o8_3();
            for (int i = 0; i < nCount; i++) {
                Unk_CtlSkill skill;
                skill.nId = pPkt->vfunc_o8_3();
                skill.nLevel = pPkt->vfunc_o8_3();
                int nKey = (int)m_skills.size();
                nKey = nKey + 1000;
                m_skills.insert(std::make_pair(nKey, skill));
            }
        } else if (nKind == 5) {
            if (m_30.IsNull() == 0) {
                int nId = pPkt->vfunc_o8_3();
                if (nId == m_nNpcId) {
                    PCBase* pActor = FUN_1403ed2d0()->FUN_141bd1320(nId);
                    if (pActor != 0) {
                        CString strNode = pPkt->vfunc_o8_6();
                        CString strAction = pPkt->vfunc_o8_6();
                        int nTarget = (int)pPkt->vfunc_o8_4();
                        CStringW strExtra(L"ExtraData");
                        if (pPkt->vfunc_o8_0())
                            strExtra += "(Tracking)";
                        int nExtra = pPkt->vfunc_o8_3();
                        for (int i = 0; i < nExtra; i++) {
                            CString strKey = pPkt->vfunc_o8_6();
                            int nValue = pPkt->vfunc_o8_3();
                            strExtra += FUN_14136e740(L"\n{0} : {1}", strKey, nValue);
                        }
                        CStringW strTarget(L"");
                        Unk_CtlObj* pObj = FUN_1403ed2d0()->FUN_141bd1180(nTarget);
                        if (pObj != 0) {
                            PCBase* pPc = FUN_14099eef0(pObj);
                            if (pPc == 0) {
                                Unk_CtlNpc* pNpc = FUN_140a38a00(pObj);
                                if (pNpc != 0)
                                    strTarget = pNpc->FUN_141093310();
                            } else {
                                strTarget = pPc->vfunc_77();
                            }
                        }
                        __int64 nPap = pPkt->vfunc_o8_4();
                        __int64 nMap = pPkt->vfunc_o8_4();
                        __int64 nNdd = pPkt->vfunc_o8_4();
                        __int64 nCap = pPkt->vfunc_o8_4();
                        __int64 nHp = pPkt->vfunc_o8_4();
                        __int64 nMhp = pPkt->vfunc_o8_4();
                        if (FUN_1401647e0(m_strCurrent, strNode))
                            m_strPrev = m_strCurrent;
                        m_strCurrent = strNode;
                        CStringW strInfo = StringFormat(L"{0}\n\nCurrent : {1}\nPrev : {2}\nTarget : {3}\n", strAction, m_strCurrent, m_strPrev, strTarget);
                        int nZ = (int)pActor->vfunc_18().z;
                        int nY = (int)pActor->vfunc_18().y;
                        int nX = (int)pActor->vfunc_18().x;
                        strInfo += FUN_1406a7830(L"\nX: {0}\nY: {1}\nZ: {2}", nX, nY, nZ);
                        strInfo += FUN_1401e8510(L"\n\n{0}", strExtra);
                        CStringW strStat = StringFormat(L"Current Stat\nPAP : {0}\nMAP : {1}\nNDD : {2}\nCAP : {3}\nHP : {4}\nMHP : {5}", nPap, nMap, nNdd, nCap, nHp, nMhp);
                        if (m_30.get() != 0) {
                            m_30->Invoke("SetAiText", strInfo);
                            m_30->Invoke("SetStatText", strStat);
                        }
                    }
                }
            }
        } else if (nKind == 7) {
            CString strFile = pPkt->vfunc_o8_6();
            int nId = pPkt->vfunc_o8_3();
            AiDebugDialog* pDlg = new AiDebugDialog(0);
            m_spAi.AssignRaw(pDlg);
            m_spAi->SetTarget(strFile, nId);
            AiDebugDialog* pAi = m_spAi.operator->();
            pAi->Create(0xa5, CWnd::FromHandle(FUN_14209c720(FUN_140aadf80())));
        } else if (nKind == 8) {
            int nId = pPkt->vfunc_o8_3();
            int nLine = pPkt->vfunc_o8_3();
            if (FUN_1403ed2d0()->FUN_141bd1320(nId) != 0 && !(m_spAi == 0))
                m_spAi->AddLine(nId, nLine);
        }
    }
}

// @0x141a63280
void UINpcControlDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    FUN_141a63770();
}

// @0x141a632b0
void UINpcControlDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (m_30.IsNull() == 0) {
        ASObj obj(2);
        m_30->Invoke("initData", obj.FUN_1422bb870());
    }
}

// @0x141a63390
int UINpcControlDialog::vfunc_13()
{
    if (UIDialog::vfunc_13() == 0) {
        if (FUN_14025e7c0()->FUN_14116d9c0(0x1c, 0, 0) == 0) {
            if (FUN_14025e7c0()->FUN_14116d9c0(0xf, 0, 0) == 0) {
                if (FUN_14025e7c0()->FUN_14116d840() == 0)
                    return 0;
                vfunc_67();
                return 1;
            }
            if (m_30.get() != 0)
                m_30->Invoke("onTabKey");
            return 1;
        }
        if (m_30.get() != 0)
            m_30->Invoke("onEnterKey");
        return 1;
    }
    return 1;
}

// @0x141a634d0
int UINpcControlDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    UIDialog::vfunc_28(szMethod, pArgs, nArgs);
    ASData data;
    if (_stricmp("OnCommandChange", szMethod) == 0) {
        data.FUN_1422b9620(pArgs, nArgs);
        return 1;
    }
    if (_stricmp("OnGroupChange", szMethod) == 0) {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0) {
            CString strGroup = data.FUN_1422b8d30();
            FUN_141a63ce0(strGroup);
        }
        return 1;
    }
    if (_stricmp("OnExecute", szMethod) == 0) {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0) {
            int nCommand = data.FUN_1422b8b10();
            CStringW strArg = data.FUN_1422b8f40();
            FUN_141a64ba0(nCommand, strArg);
        }
        return 1;
    }
    if (_stricmp("OnStopSkill", szMethod) == 0) {
        COutPacket pkt(0x50, 0);
        pkt.vfunc_o10_1(4);
        pkt.vfunc_o10_3(m_nNpcId);
        pkt.vfunc_o10_1(9);
        FUN_140710590(pkt);
        return 1;
    }
    return 0;
}

// @0x141a63770
void UINpcControlDialog::FUN_141a63770()
{
    PCBase* pActor = FUN_1403ed2d0()->FUN_141bd1320(m_nNpcId);
    if (pActor != 0) {
        CStringW strName = FUN_1401aa6a0(FUN_141092fa0(pActor));
        int nNpc = FUN_141092fa0(pActor);
        CStringW strTitle = FUN_1409e8180(L"[{0}] [GameOID : {1}] [npcID : {2}]", strName, m_nNpcId, nNpc);
        MS2Ptr<ASTextField> spName = FUN_140bb4cf0("m_npcName");
        if (spName.get() != 0)
            spName->FUN_1422c4cd0(strTitle);
    }
}

// @0x141a638c0
void UINpcControlDialog::SetNpcId(int nNpcId)
{
    m_nNpcId = nNpcId;
}

// @0x141a638e0
int UINpcControlDialog::FUN_141a638e0()
{
    if (m_30.IsNull() == 0)
        return FUN_1409c17e0(m_30->Invoke("GetLoopCount"));
    return 0;
}

// @0x141a63970
void UINpcControlDialog::FUN_141a63970(unsigned char nCmd, __int64 nValue)
{
    if (m_nNpcId != 0) {
        COutPacket pkt(0x50, 0);
        pkt.vfunc_o10_1(4);
        pkt.vfunc_o10_3(m_nNpcId);
        pkt.vfunc_o10_1(nCmd);
        pkt.vfunc_o10_4(nValue);
        FUN_140710590(pkt);
    }
}

// @0x141a63a10
void UINpcControlDialog::FUN_141a63a10(int nCmd, const CStringW& strArgs)
{
    int nLoop = FUN_141a638e0();
    if (0 < nLoop) {
        Unk_CtlIntVec args;
        std::vector<Unk_CtlSkill> skills;
        FUN_141632630(strArgs, args, L",/[] ");
        int nArgs = (int)args.FUN_1401910d0();
        if (nArgs < 1) {
            int nKey = nCmd;
            Unk_CtlSkill skill = m_skills[nKey];
            skills.push_back(skill);
        } else {
            int i = 0;
            while (i < nArgs && FUN_141a65420(args, i) && FUN_141a65420(args, i + 1)) {
                int nId = args.FUN_1404f0a10(i);
                unsigned short nLevel = *(unsigned short*)&args.FUN_1404f0a10(i + 1);
                Unk_CtlSkill skill;
                skill.nId = nId;
                skill.nLevel = nLevel;
                skills.push_back(skill);
                i += 2;
            }
        }
        int nSkills = (int)skills.size();
        if (nSkills < 1)
            return;
        COutPacket pkt(0x50, 0);
        pkt.vfunc_o10_1(4);
        pkt.vfunc_o10_3(m_nNpcId);
        pkt.vfunc_o10_1(8);
        short nLoopShort = (short)nLoop;
        pkt.vfunc_o10_2(nLoopShort);
        short nCountShort = (short)nSkills;
        pkt.vfunc_o10_2(nCountShort);
        for (int j = 0; j < nSkills; j++) {
            pkt.vfunc_o10_3(skills[j].nId);
            pkt.vfunc_o10_3(skills[j].nLevel);
        }
        FUN_140710590(pkt);
    }
}

// @0x141a63ce0
void UINpcControlDialog::FUN_141a63ce0(const CString& strGroup)
{
    MS2Ptr<Unk_CtlList> spList = FUN_140c02900("m_items");
    if (spList.IsNull())
        return;
    spList->FUN_1422dd1d0();
    if (FUN_140184310(strGroup, "ALL") || FUN_140184310(strGroup, "STAT")) {
        ASObj itemHpPercent(2);
        itemHpPercent.FUN_1407cbb20("label", FUN_14025e7a0()->FUN_1422b0570(CString("$s_npccontrol_dialog_msg_hp_percent_apply")));
        itemHpPercent.FUN_141a65c70("commandId", 1);
        spList->FUN_1422dd230(itemHpPercent);
        ASObj itemHp(2);
        itemHp.FUN_1407cbb20("label", FUN_14025e7a0()->FUN_1422b0570(CString("$s_npccontrol_dialog_msg_hp_apply")));
        itemHp.FUN_141a65c70("commandId", 2);
        spList->FUN_1422dd230(itemHp);
        ASObj itemDamage(2);
        itemDamage.FUN_1407cbb20("label", FUN_14025e7a0()->FUN_1422b0570(CString("$s_npccontrol_dialog_msg_fix_damage")));
        itemDamage.FUN_141a65c70("commandId", 10);
        spList->FUN_1422dd230(itemDamage);
    }
    if (FUN_140184310(strGroup, "ALL") || FUN_140184310(strGroup, "AI")) {
        ASObj itemAiOn(2);
        itemAiOn.FUN_1407cbb20("label", FUN_14025e7a0()->FUN_1422b0570(CString("$s_npccontrol_dialog_msg_ai_on")));
        itemAiOn.FUN_141a65c70("commandId", 3);
        spList->FUN_1422dd230(itemAiOn);
        ASObj itemAiOff(2);
        itemAiOff.FUN_1407cbb20("label", FUN_14025e7a0()->FUN_1422b0570(CString("$s_npccontrol_dialog_msg_ai_off")));
        itemAiOff.FUN_141a65c70("commandId", 4);
        spList->FUN_1422dd230(itemAiOff);
        ASObj itemTrace(2);
        itemTrace.FUN_1407cbb20("label", FUN_14025e7a0()->FUN_1422b0570(CString("$s_npccontrol_dialog_msg_trace_ai")));
        itemTrace.FUN_141a65c70("commandId", 5);
        spList->FUN_1422dd230(itemTrace);
        ASObj itemTraceClient(2);
        itemTraceClient.FUN_1407cbb20("label", FUN_14025e7a0()->FUN_1422b0570(CString("$s_npccontrol_dialog_msg_trace_ai_client")));
        itemTraceClient.FUN_141a65c70("commandId", 6);
        spList->FUN_1422dd230(itemTraceClient);
        ASObj itemBattle(2);
        itemBattle.FUN_1407cbb20("label", FUN_14025e7a0()->FUN_1422b0570(CString("$s_npccontrol_dialog_msg_battle_setting")));
        itemBattle.FUN_141a65c70("commandId", 7);
        spList->FUN_1422dd230(itemBattle);
        ASObj itemFile(2);
        itemFile.FUN_1407cbb20("label", FUN_14025e7a0()->FUN_1422b0570(CString("$s_npccontrol_dialog_msg_change_ai_file")));
        itemFile.FUN_141a65c70("commandId", 0xb);
        spList->FUN_1422dd230(itemFile);
    }
    if (FUN_140184310(strGroup, "ALL") || FUN_140184310(strGroup, "ADDITIONAL")) {
        ASObj itemAdd(2);
        itemAdd.FUN_1407cbb20("label", FUN_14025e7a0()->FUN_1422b0570(CString("$s_npccontrol_dialog_msg_add_additional")));
        itemAdd.FUN_141a65c70("commandId", 0xc);
        spList->FUN_1422dd230(itemAdd);
        ASObj itemRemove(2);
        itemRemove.FUN_1407cbb20("label", FUN_14025e7a0()->FUN_1422b0570(CString("$s_npccontrol_dialog_msg_remove_additional")));
        itemRemove.FUN_141a65c70("commandId", 0xd);
        spList->FUN_1422dd230(itemRemove);
        ASObj itemCurrent(2);
        itemCurrent.FUN_1407cbb20("label", FUN_14025e7a0()->FUN_1422b0570(CString("$s_npccontrol_dialog_msg_current_additional")));
        itemCurrent.FUN_141a65c70("commandId", 0xe);
        spList->FUN_1422dd230(itemCurrent);
    }
    if (FUN_140184310(strGroup, "ALL") || FUN_140184310(strGroup, "SKILL")) {
        std::map<int, Unk_CtlSkill>::iterator it = m_skills.begin();
        std::map<int, Unk_CtlSkill>::iterator itEnd = m_skills.end();
        for (; it != itEnd; ++it) {
            int nCommand = it->first;
            const Unk_CtlSkill* pSkill = &it->second;
            CStringW strLabel;
            strLabel.Format(L"[%d] [Lv. %d] [%s]", pSkill->nId, pSkill->nLevel,
                            (const wchar_t*)GetStringTable()->FUN_141811980(4, pSkill->nId));
            ASObj itemSkill(2);
            itemSkill.FUN_1407cbb20("label", strLabel);
            itemSkill.FUN_1407cb9c0("commandId", nCommand);
            spList->FUN_1422dd230(itemSkill);
        }
    }
    if (FUN_140184310(strGroup, "ALL") || FUN_140184310(strGroup, "ETC")) {
        ASObj itemAssist(2);
        itemAssist.FUN_1407cbb20("label", FUN_14025e7a0()->FUN_1422b0570(CString("$s_npccontrol_dialog_msg_assist")));
        itemAssist.FUN_141a65c70("commandId", 8);
        spList->FUN_1422dd230(itemAssist);
        ASObj itemExtra(2);
        itemExtra.FUN_1407cbb20("label", FUN_14025e7a0()->FUN_1422b0570(CString("$s_npccontrol_dialog_msg_extra")));
        itemExtra.FUN_141a65c70("commandId", 9);
        spList->FUN_1422dd230(itemExtra);
    }
    spList->vfunc_24(true);
}

// @0x141a64ba0
void UINpcControlDialog::FUN_141a64ba0(int nCommand, const CStringW& strArg)
{
    __int64 nArg = FUN_140718320(strArg);
    if (nCommand == 1) {
        if (0 < nArg && nArg < 0x65)
            FUN_141a63970(1, nArg);
    } else if (nCommand == 2) {
        if (0 < nArg)
            FUN_141a63970(2, nArg);
    } else if (nCommand == 3) {
        FUN_141a63970(4, 0);
    } else if (nCommand == 4) {
        FUN_141a63970(5, 0);
    } else if (nCommand == 5) {
        FUN_141a63970(6, 0);
    } else if (nCommand == 6) {
        if (m_spAi.get() != 0) {
            m_spAi->RequestTrace();
            HWND hWnd = m_spAi->GetSafeHwnd();
            SendMessageA(hWnd, 0x10, 0, 0);
            m_spAi.AssignRaw(0);
        }
        FUN_141a63970(7, 1);
    } else if (nCommand == 7) {
        FUN_141a63970(3, nArg);
    } else if (nCommand == 8) {
        FUN_141a63970(10, 0);
    } else if (nCommand == 9) {
        FUN_141a63970(0xb, 0);
    } else if (nCommand != 10) {
        if (nCommand == 0xc) {
            if (m_nNpcId != 0) {
                Unk_NpcFileList parts;
                CStringW strText(strArg);
                FUN_140988d60(strText, parts, L",");
                int nAdditional;
                short nLevel;
                int nExtra;
                nAdditional = 0;
                nLevel = 1;
                nExtra = 0;
                if (parts.FUN_14041af10() != 0)
                    nAdditional = FUN_140718200(parts.FUN_1405e99b0(0));
                if (1 < parts.FUN_14041af10())
                    nLevel = FUN_140718140(parts.FUN_1405e99b0(1));
                if (2 < parts.FUN_14041af10())
                    nExtra = FUN_1407182c0(parts.FUN_1405e99b0(2));
                if (nAdditional == 0)
                    return;
                COutPacket pkt(0x50, 0);
                pkt.vfunc_o10_1(4);
                pkt.vfunc_o10_3(m_nNpcId);
                pkt.vfunc_o10_1(0xe);
                pkt.vfunc_o10_3(nAdditional);
                pkt.vfunc_o10_3(nLevel);
                pkt.vfunc_o10_3(nExtra);
                FUN_140710590(pkt);
            }
        } else if (nCommand == 0xd) {
            FUN_141a63970(0xf, nArg);
        } else if (nCommand == 0xe) {
            FUN_141a63970(0x10, 0);
        } else if (nCommand == 0xb) {
            FUN_141a65000();
        } else if (nCommand / 1000 == 1) {
            FUN_141a63a10(nCommand, strArg);
        }
    }
}

// @0x141a65000
void UINpcControlDialog::FUN_141a65000()
{
    if (PathIsDirectoryW(L"./Data/Xml/AI") == 0)
        CreateDirectoryW(L"./Data/Xml/AI", 0);
    CStringW strEmpty(L"");
    CStringW strDir(L"./Data/Xml/AI");
    CStringW strFile = FUN_141b6e360(FUN_1418fe4e0(strDir), L"xml Files (*.xml)", strEmpty);
    if (strFile.IsEmpty())
        return;
    if (m_nNpcId == 0)
        return;
    COutPacket pkt(0x50, 0);
    pkt.vfunc_o10_1(4);
    pkt.vfunc_o10_3(m_nNpcId);
    pkt.vfunc_o10_1(0xd);
    pkt.vfunc_o10_8(strFile);
    FUN_140710590(pkt);
}
