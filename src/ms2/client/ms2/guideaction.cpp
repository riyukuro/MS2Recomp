// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The guide-quest actions: the CGuideAction base, the action
// factory of an <action> element, the 22 action classes registered by name, the numbered / dialog-name limits the
// Limit actions hold, and the template glue (CAtlArray / MS2Ptr / Delegate instances). See ms2/placeholder/cguideaction.h.
// MS2-UNIT: client\ms2\guideaction.cpp
// MS2-RANGE: 0x1400f1f60-0x1400f27b0 .text$di
// MS2-RANGE: 0x141382b90-0x1413892f0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??1CGuideActionUITextBase@@UEAA@XZ 0x141387a10 ; unique
// MS2-PIN: ??_GCGuideActionLimitDialog@@UEAAPEAXI@Z 0x141387e90 ; prop
// MS2-PIN: ??_GCGuideActionMinimapMaximize@@UEAAPEAXI@Z 0x141387ed0 ; prop
// MS2-PIN: ??_GCGuideActionUISummary@@UEAAPEAXI@Z 0x141388150 ; prop
// MS2-PIN: ??_GCGuideActionUITextBase@@UEAAPEAXI@Z 0x141388190 ; prop
// MS2-PIN: ??_GCGuideActionUITextTip@@UEAAPEAXI@Z 0x1413881d0 ; prop
// MS2-PIN: ?CallDestructors@?$CAtlArray@UStep@CGuideActionUITutorial@@V?$CElementTraits@UStep@CGuideActionUITutorial@@@ATL@@@ATL@@CAXPEAUStep@CGuideActionUITutorial@@_K@Z 0x141388550 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??__Es_dialogLimits@@YAXXZ 0x1400f2640
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\guideaction.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include <new>
#include <exception>
#include <vector>

#include <egf/EntityID.h>

#include "ms2/placeholder/cguideaction.h"
#include "ms2/placeholder/cguidecondition.h"
#include "ms2/placeholder/cguidemanager.h"
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/placeholder/sidepopuptalkparam.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/client/ms2/effectparam.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/client/ms2/triggerservice.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/client/ms2/uiguideeventarrow.h"
#include "ms2/client/ms2/uicutscenecinematic.h"
#include "ms2/client/ms2/uigamemenudialog.h"
#include "ms2/client/ms2/uigamepadmenudialog.h"
#include "ms2/client/ms2/uismartrecommendbillingdialog.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of the exe objects and unrecovered callees --------------------------------------------------------

// The minimap dialog (ui class 0x4e29); only what the MinimapMaximize action calls.
class UIMinimapDialog : public UIDialog
{
public:
    // @0x1413886e0
    static eUIClassID GetUIClassID() { return (eUIClassID)0x4e29; }
    void FUN_141a3ad80(bool bMaximized);
    void FUN_141a3abd0();                                   // restore
    void FUN_141a3aca0();                                   // maximize
};

// The side popup talk window (ui class 0x4f57).
class UISidePopupTalk : public UIDialog
{
public:
    void FUN_140e879a0(MS2Ptr<SidePopupTalkParam> spParam); // show
};

// SidePopupTalkParam as the side NPC talk fills it (the shared placeholder pads +0x20, the script id list).
struct Unk_GaSidePopupView : public CPtred
{
    int m_nKind;                                            // +0x18 the ui type
    std::vector<unsigned> m_scriptIds;                      // +0x20
    CStringW m_strText;                                     // +0x38
    CStringA m_strIllust;                                   // +0x40
    CStringA m_strUsm;                                      // +0x48
    unsigned m_nDuration;                                   // +0x50
    int m_pad_54;
    CStringA m_strVoice;                                    // +0x58
    CStringA m_strSound;                                    // +0x60
};
MS2_CHECK_OFFSET(Unk_GaSidePopupView, m_strSound, 0x60);
#define GA_SIDEPOPUP(sp) reinterpret_cast<Unk_GaSidePopupView*>((sp).operator->())

// NiPoint3's assignment (0x14097faa0) of a point built by Unk_NiPoint3 (nipoint3.h), as the effect spawns use them.
void FUN_14097faa0(NiPoint3* pDst, const Unk_NiPoint3* pSrc);

class Unk_GaCamera { public: int FUN_140af7e30(); };       // CameraMgr: the kind of the active camera mode (2: trigger)
Unk_GaCamera* FUN_1409478c0();
class Unk_GaOption { public: const unsigned char* FUN_140a58500(); };   // CGameOption: the gamepad block (+0 the gamepad mode)
Unk_GaOption* FUN_1409a8b10();
class Unk_GaSound { public: void FUN_1422b9fd0(int nScene); };  // the sound scene manager
Unk_GaSound* FUN_1408e57f0();
class Unk_GaKeyTable { public: CStringW FUN_14142d760(int nBind, int n); };   // CKeyTable: the key name of a binding
Unk_GaKeyTable* FUN_1409331f0();

CTriggerService* FUN_140ad4b90();
CEffectService* FUN_1403ed280();
NotifySystem* FUN_140939a10();
UIGuideEvent* FUN_14136f3e0(int nId);                       // the guide event window
UICutSceneCinematic* FUN_14136f290(int nId);
UISmartRecommendNotifyDialog* FUN_14136f5c0(int nId);
UIGameMenuDialog* FUN_140938b90(int nId);
CStringW GetStringCommon(int nId);                            // a system string
void FUN_141999d20(int bUse);                               // the tutorial weapon of the main player info
void FUN_141a5d0a0(int bUse);                               // the tutorial weapon of the quick slots
unsigned FUN_140869420();                                   // millisecond clock

const char* FUN_14086f4b0(Unk_140165cf0* pElem, const char* pszName);   // attribute text (null = absent)
int FUN_140874670(Unk_140165cf0* pElem, const char* pszName, Unk_StreamPoint& ptOut);
int FUN_140e8ecb0(Unk_140165cf0* pElem, const char* pszName, int& nOut);   // the side popup ui type
unsigned FUN_141389420(const CStringA& strName, unsigned nDefault);      // the limit kind of a name
CGuideControllerType FUN_14021ade0(const CStringA& strName);
void FUN_140165270(ATL::CAtlArray<CStringA>& arr, const CStringA& str);   // append
CStringA FUN_140540050(const char* szFormat, const CStringA& strArg);    // StringFormat with one string
MS2Ptr<CGuideCondition> FUN_1413a52c0(Unk_140165cf0* pElem);              // the condition of a <condition> element
int FUN_1413a5570(CGuideCondition* pCond);                               // the condition passes

// The narrow formatter without arguments (FMT_VARIADIC's zero-argument form; its COMDAT is in this unit).
// @0x141388650
inline CString StringFormat(const char* format)
{
    return StringFormat(format, fmt::ArgList());
}

// The dialog of a ui class (the class's own id, or a given one) / of a name.
template <class T> T* Unk_GaGetUI()
{
    CUIService* pService = CUIService::GetInstance();
    if (pService == 0)
        return 0;
    MS2Ptr<UIObject> spObj = pService->FUN_141adcea0(T::GetUIClassID());
    if (spObj.IsNull())
        return 0;
    return dynamic_cast<T*>(spObj.operator->());
}
template <class T> T* Unk_GaGetUI(int nId)
{
    if (CUIService::GetInstance())
    {
        MS2Ptr<UIObject> spObj = CUIService::GetInstance()->FUN_141adcea0((eUIClassID)nId);
        if (spObj.get())
            return dynamic_cast<T*>(spObj.operator->());
    }
    return 0;
}
template <class T> T* Unk_GaGetUIByName(const CStringA& strName)
{
    if (CUIService::GetInstance())
    {
        MS2Ptr<UIObject> spObj = CUIService::GetInstance()->FUN_141adcf50(strName);
        if (spObj.get())
            return dynamic_cast<T*>(spObj.operator->());
    }
    return 0;
}

// tinyxmlhelper.h: the "v" attributes of the child elements `pszName` (1 when there is none).
// @0x141386ab0
inline int ReadValueList(Unk_140165cf0* pElem, const char* pszName, ATL::CAtlArray<int>& rOut)
{
    int nCount = 0;
    for (Unk_140165cf0* pChild = pElem->FUN_14086e8d0(pszName); pChild != 0; pChild = pChild->FUN_14086e7e0(pszName))
    {
        int nValue;
        FUN_1408731e0(pChild, "v", nValue);
        rOut.Add(nValue);
        nCount++;
    }
    return nCount > 0 ? 0 : 1;
}
// @0x141386b50
inline int ReadValueList(Unk_140165cf0* pElem, const char* pszName, ATL::CAtlArray<CStringA>& rOut)
{
    int nCount = 0;
    for (Unk_140165cf0* pChild = pElem->FUN_14086e8d0(pszName); pChild != 0; pChild = pChild->FUN_14086e7e0(pszName))
    {
        CStringA strValue;
        FUN_1408733e0(pChild, "v", strValue);
        FUN_140165270(rOut, strValue);
        nCount++;
    }
    return nCount > 0 ? 0 : 1;
}

// ---- unit statics ------------------------------------------------------------------------------------------------------

#ifndef MS2_HOOK_DLL   // registers into the exe's ClassObject registry at DllMain time, before the exe's CRT/locks exist
static ClassObjectRegistrar s_regClearTutorial(L"CGuideActionClearTutorial", CGuideActionClearTutorial::CreateObject);
static ClassObjectRegistrar s_regConditionAction(L"CGuideActionConditionAction", CGuideActionConditionAction::CreateObject);
static ClassObjectRegistrar s_regEffect(L"CGuideActionEffect", CGuideActionEffect::CreateObject);
static ClassObjectRegistrar s_regEquipWeaponTutorial(L"CGuideActionEquipWeaponTutorial", CGuideActionEquipWeaponTutorial::CreateObject);
static ClassObjectRegistrar s_regForceClear(L"CGuideActionForceClear", CGuideActionForceClear::CreateObject);
static ClassObjectRegistrar s_regGameMenuLimit(L"CGuideActionGameMenuLimit", CGuideActionGameMenuLimit::CreateObject);
static ClassObjectRegistrar s_regLimit(L"CGuideActionLimit", CGuideActionLimit::CreateObject);
static ClassObjectRegistrar s_regLimitDialog(L"CGuideActionLimitDialog", CGuideActionLimitDialog::CreateObject);
static ClassObjectRegistrar s_regMinimapMaximize(L"CGuideActionMinimapMaximize", CGuideActionMinimapMaximize::CreateObject);
static ClassObjectRegistrar s_regOpenDialog(L"CGuideActionOpenDialog", CGuideActionOpenDialog::CreateObject);
static ClassObjectRegistrar s_regRequestTutorialItem(L"CGuideActionRequestTutorialItem", CGuideActionRequestTutorialItem::CreateObject);
static ClassObjectRegistrar s_regSequenceCamera(L"CGuideActionSequenceCamera", CGuideActionSequenceCamera::CreateObject);
static ClassObjectRegistrar s_regServerTriggerEvent(L"CGuideActionServerTriggerEvent", CGuideActionServerTriggerEvent::CreateObject);
static ClassObjectRegistrar s_regSideNpcTalk(L"CGuideActionSideNpcTalk", CGuideActionSideNpcTalk::CreateObject);
static ClassObjectRegistrar s_regSmartRecommend(L"CGuideActionSmartRecommend", CGuideActionSmartRecommend::CreateObject);
static ClassObjectRegistrar s_regUIArrow(L"CGuideActionUIArrow", CGuideActionUIArrow::CreateObject);
static ClassObjectRegistrar s_regUIArrowClose(L"CGuideActionUIArrowClose", CGuideActionUIArrowClose::CreateObject);
static ClassObjectRegistrar s_regUIArrowDialog(L"CGuideActionUIArrowDialog", CGuideActionUIArrowDialog::CreateObject);
static ClassObjectRegistrar s_regUISummary(L"CGuideActionUISummary", CGuideActionUISummary::CreateObject);
static ClassObjectRegistrar s_regUITextBase(L"CGuideActionUITextBase", CGuideActionUITextBase::CreateObject);
static ClassObjectRegistrar s_regUITextTip(L"CGuideActionUITextTip", CGuideActionUITextTip::CreateObject);
static ClassObjectRegistrar s_regUITutorial(L"CGuideActionUITutorial", CGuideActionUITutorial::CreateObject);
#endif

// The use counts of the numbered limits and of the limited dialog names.
static unsigned s_limitCounts[25];
static ATL::CRBMap<CStringA, int> s_dialogLimits(10);

// The shared header statics (see ms2/placeholder/header_statics_a.h; this unit has no condition static after them).
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
// The last initializer is egf/EntityID.h's kENTITY_INVALID.

// ---- the action factory and CGuideAction --------------------------------------------------------------------------------

// @0x141382b90
MS2Ptr<CGuideAction> FUN_141382b90(Unk_140165cf0* pElem)
{
    CStringA strType(FUN_14086f4b0(pElem, "type"));
    CStringW strName = StringFormat(L"CGuideAction{0}", strType);
    MS2Ptr<CGuideAction> spAction(static_cast<CGuideAction*>(FUN_1401f7f50(CStringW(strName))));
    if (spAction.get())
        spAction->vfunc_2(pElem);
    else
        throw std::exception(FUN_140540050("Unknown Guide action Tag({0})", strType));
    return spAction;
}
MS2_REPLACE(0x141382B90, FUN_141382b90, 369, 0x6CC2AD9F);

// @0x141382d20
CGuideAction::CGuideAction()
{
}

// @0x141382d60
CGuideAction::~CGuideAction()
{
}

// @0x141382d90
void CGuideAction::vfunc_2(Unk_140165cf0* pElem)
{
}
MS2_REPLACE_METHOD(0x141382D90, CGuideAction, vfunc_2, 11, 0x02239C70);

// @0x141382db0
void CGuideAction::vfunc_3()
{
}
MS2_REPLACE_METHOD(0x141382DB0, CGuideAction, vfunc_3, 6, 0xA9AF6E37);

// @0x141382dc0
void CGuideAction::vfunc_4()
{
}
MS2_REPLACE_METHOD(0x141382DC0, CGuideAction, vfunc_4, 6, 0xA9AF6E37);

// @0x141382dd0
int CGuideAction::vfunc_5()
{
    return 1;
}
MS2_REPLACE_METHOD(0x141382DD0, CGuideAction, vfunc_5, 11, 0x30025ED0);

// ---- CGuideActionMinimapMaximize ----------------------------------------------------------------------------------------

// @0x141382df0
ClassObject* CGuideActionMinimapMaximize::CreateObject()
{
    return new CGuideActionMinimapMaximize;
}

// @0x141382e50
CStringW CGuideActionMinimapMaximize::GetTypeName()
{
    return L"CGuideActionMinimapMaximize";
}
MS2_REPLACE_METHOD(0x141382E50, CGuideActionMinimapMaximize, GetTypeName, 61, 0x88C3452E);

// @0x141382ea0
void CGuideActionMinimapMaximize::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideAction::vfunc_2(pElem);
    FUN_1408731e0(pElem, "isOn", m_isOn);
}
MS2_REPLACE_METHOD(0x141382EA0, CGuideActionMinimapMaximize, vfunc_2, 63, 0x5C324EC9);

// @0x141382ef0
void CGuideActionMinimapMaximize::vfunc_3()
{
    if (UIMinimapDialog* pDialog = Unk_GaGetUI<UIMinimapDialog>())
    {
        if (m_isOn != 0)
        {
            pDialog->FUN_141a3ad80(true);
            pDialog->FUN_141a3aca0();
        }
        else
        {
            pDialog->FUN_141a3ad80(false);
            pDialog->FUN_141a3abd0();
        }
    }
}
MS2_REPLACE_METHOD(0x141382EF0, CGuideActionMinimapMaximize, vfunc_3, 89, 0xAD68ED73);

// ---- CGuideActionOpenDialog ---------------------------------------------------------------------------------------------

// @0x141382f50
ClassObject* CGuideActionOpenDialog::CreateObject()
{
    return new CGuideActionOpenDialog;
}

// @0x141382fb0
CStringW CGuideActionOpenDialog::GetTypeName()
{
    return L"CGuideActionOpenDialog";
}
MS2_REPLACE_METHOD(0x141382FB0, CGuideActionOpenDialog, GetTypeName, 61, 0x37402A72);

// @0x141383000
void CGuideActionOpenDialog::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideAction::vfunc_2(pElem);
    m_dialogID = 0;
    FUN_140873220(pElem, "dialogID", m_dialogID);
    FUN_1408733e0(pElem, "dialogName", m_dialogName);
}
MS2_REPLACE_METHOD(0x141383000, CGuideActionOpenDialog, vfunc_2, 104, 0x10CFD07C);

// @0x141383070
void CGuideActionOpenDialog::vfunc_3()
{
    if (m_dialogID != 0)
    {
        CUIService::GetInstance()->OpenDialog((eUIClassID)m_dialogID);
    }
    else
    {
        if (!m_dialogName.IsEmpty())
        {
            UIDialog* pDialog = Unk_GaGetUIByName<UIDialog>(m_dialogName);
            if (pDialog != 0 && pDialog->FUN_141924630() == 0)
                pDialog->FUN_141924680();
        }
    }
}
MS2_REPLACE_METHOD(0x141383070, CGuideActionOpenDialog, vfunc_3, 127, 0xE52A6D7B);

// ---- CGuideActionEffect -------------------------------------------------------------------------------------------------

// @0x141383100
ClassObject* CGuideActionEffect::CreateObject()
{
    return new CGuideActionEffect;
}

// @0x141383160
CStringW CGuideActionEffect::GetTypeName()
{
    return L"CGuideActionEffect";
}
MS2_REPLACE_METHOD(0x141383160, CGuideActionEffect, GetTypeName, 61, 0x579BAC8D);

extern const Unk_StreamPoint DAT_143b01a60;                 // efd::Point3::ZERO

// @0x1413831b0
void CGuideActionEffect::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideAction::vfunc_2(pElem);
    FUN_1408733e0(pElem, "path", m_path);
    for (Unk_140165cf0* pCube = pElem->FUN_140165cf0("cube"); pCube != 0; pCube = pCube->FUN_140168650("cube"))
    {
        Cube cube;
        cube.m_pos = DAT_143b01a60;
        cube.m_rotate = DAT_143b01a60;
        cube.m_scale = 1.0f;
        cube.m_handle = 0;
        FUN_140874670(pCube, "pos", cube.m_pos);
        FUN_140874670(pCube, "rotate", cube.m_rotate);
        FUN_140873360(pCube, "scale", cube.m_scale);
        m_cubes.Add(cube);
    }
}
MS2_REPLACE_METHOD(0x1413831B0, CGuideActionEffect, vfunc_2, 280, 0x4A83608D);

// @0x1413832d0
// MS2-FUNCTIONAL: the NiPoint3 temp lands at rsp+0x38 instead of the exe's packed rsp+0x34 (3 frame-offset bytes)
void CGuideActionEffect::vfunc_3()
{
    for (unsigned __int64 i = 0; i < m_cubes.GetCount(); i++)
    {
        Cube& cube = m_cubes[i];
        NiTransform xf;
        Unk_NiPoint3 niPos(cube.m_pos);
        FUN_14097faa0(&xf.m_Translate, &niPos);
        xf.m_Rotate.FromEulerAnglesXYZ((cube.m_rotate.x * 3.1415927f) / 180.0f, (cube.m_rotate.y * 3.1415927f) / 180.0f, (cube.m_rotate.z * 3.1415927f) / 180.0f);
        xf.m_fScale = cube.m_scale;
        Unk_EffectTarget kTarget;
        kTarget.m_strName = m_path;
        kTarget.m_nKind = 0;
        kTarget.m_pXform = &xf;
        cube.m_handle = FUN_1403ed280()->FUN_1411a49c0(kTarget);
    }
}
MS2_REPLACE_METHOD(0x1413832D0, CGuideActionEffect, vfunc_3, 427, 0x74750A6C);

// @0x141383490
void CGuideActionEffect::vfunc_4()
{
    for (unsigned __int64 i = 0; i < m_cubes.GetCount(); i++)
    {
        if (m_cubes[i].m_handle != 0)
        {
            FUN_1403ed280()->FUN_1411a6060(m_cubes[i].m_handle);
            m_cubes[i].m_handle = 0;
        }
    }
}
MS2_REPLACE_METHOD(0x141383490, CGuideActionEffect, vfunc_4, 172, 0x6C5714C8);

// ---- CGuideActionLimit --------------------------------------------------------------------------------------------------

// @0x141383550
ClassObject* CGuideActionLimit::CreateObject()
{
    return new CGuideActionLimit;
}

// @0x1413835b0
CStringW CGuideActionLimit::GetTypeName()
{
    return L"CGuideActionLimit";
}
MS2_REPLACE_METHOD(0x1413835B0, CGuideActionLimit, GetTypeName, 61, 0xB20FF195);

// @0x141383600
void CGuideActionLimit::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideAction::vfunc_2(pElem);
    m_limit = 0;
    if (FUN_14086f4b0(pElem, "limit"))
    {
        CStringA strLimit(FUN_14086f4b0(pElem, "limit"));
        m_limit = FUN_141389420(strLimit, 0);
    }
    if (m_limit == 0)
        throw std::exception(StringFormat("limit Guide Unknown Type"));
}
MS2_REPLACE_METHOD(0x141383600, CGuideActionLimit, vfunc_2, 224, 0x3CC196F1);

// @0x141383700
void CGuideActionLimit::vfunc_3()
{
    FUN_1413837a0(m_limit);
}

// @0x141383730
void CGuideActionLimit::vfunc_4()
{
    FUN_1413837e0(m_limit);
}

// @0x141383760
int FUN_141383760(int nLimit)
{
    return s_limitCounts[nLimit] > 0;
}

// @0x1413837a0
void FUN_1413837a0(int nLimit)
{
    if (nLimit == 0)
        return;
    s_limitCounts[nLimit]++;
}

// @0x1413837e0
void FUN_1413837e0(int nLimit)
{
    if (nLimit == 0)
        return;
    if (s_limitCounts[nLimit] == 0)
    {
        MS2_ASSERT_AT(232, 0);
        return;
    }
    s_limitCounts[nLimit]--;
}

// ---- CGuideActionLimitDialog --------------------------------------------------------------------------------------------

// @0x141383860
ClassObject* CGuideActionLimitDialog::CreateObject()
{
    return new CGuideActionLimitDialog;
}

// @0x1413838c0
CStringW CGuideActionLimitDialog::GetTypeName()
{
    return L"CGuideActionLimitDialog";
}
MS2_REPLACE_METHOD(0x1413838C0, CGuideActionLimitDialog, GetTypeName, 61, 0xD709FCEC);

// @0x141383910
void CGuideActionLimitDialog::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideAction::vfunc_2(pElem);
    FUN_1408733e0(pElem, "dialogName", m_dialogName);
    if (m_dialogName.IsEmpty())
        throw std::exception(StringFormat("limitDialog Name is Empty"));
}
MS2_REPLACE_METHOD(0x141383910, CGuideActionLimitDialog, vfunc_2, 170, 0xBEF77954);

// @0x1413839d0
void CGuideActionLimitDialog::vfunc_3()
{
    FUN_141383b00(m_dialogName);
}

// @0x141383a20
void CGuideActionLimitDialog::vfunc_4()
{
    FUN_141383b90(m_dialogName);
}

// @0x141383a70
int FUN_141383a70(CStringA strName)
{
    int nCount = 0;
    if (s_dialogLimits.Lookup(strName, nCount))
        return nCount > 0;
    return 0;
}

// @0x141383b00
void FUN_141383b00(CStringA strName)
{
    int nCount = 0;
    if (s_dialogLimits.Lookup(strName, nCount))
        s_dialogLimits.SetAt(strName, nCount + 1);
    else
        s_dialogLimits.SetAt(strName, 1);
}

// @0x141383b90
void FUN_141383b90(CStringA strName)
{
    int nCount = 0;
    if (s_dialogLimits.Lookup(strName, nCount) && nCount > 0)
        s_dialogLimits.SetAt(strName, nCount - 1);
}

// ---- CGuideActionUITutorial ---------------------------------------------------------------------------------------------

// @0x141383c00
ClassObject* CGuideActionUITutorial::CreateObject()
{
    return new CGuideActionUITutorial;
}

// @0x141383c60
CStringW CGuideActionUITutorial::GetTypeName()
{
    return L"CGuideActionUITutorial";
}
MS2_REPLACE_METHOD(0x141383C60, CGuideActionUITutorial, GetTypeName, 61, 0x53FC09F5);

// @0x141383cb0
void CGuideActionUITutorial::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideAction::vfunc_2(pElem);
    m_index = 0;
    m_entityId = 1;
    FUN_1408731e0(pElem, "entityId", m_entityId);
    for (Unk_140165cf0* pText = pElem->FUN_140165cf0("text"); pText != 0; pText = pText->FUN_140168650("text"))
    {
        Step step;
        FUN_140873220(pText, "textId", step.m_textId);
        FUN_140873220(pText, "waitTick", step.m_waitTick);
        m_steps.Add(step);
    }
}
MS2_REPLACE_METHOD(0x141383CB0, CGuideActionUITutorial, vfunc_2, 209, 0x83DA2926);

// @0x141383d90
void CGuideActionUITutorial::vfunc_3()
{
    m_tick = 0;
    m_index = 0;
    if (m_steps.IsEmpty())
        return;
    if (UIGuideEvent* pEvent = FUN_14136f3e0(0x4e53))
        pEvent->FUN_14195a520(m_entityId, m_steps[m_index].m_textId, 1);
    FUN_1413837a0(0x15);
    FUN_1413837a0(0x13);
}

// @0x141383e40
void CGuideActionUITutorial::vfunc_4()
{
    FUN_1413837e0(0x15);
    FUN_1413837e0(0x13);
    if (UIGuideEvent* pEvent = FUN_14136f3e0(0x4e53))
        pEvent->FUN_14195b490(m_entityId);
}

// @0x141383ea0
int CGuideActionUITutorial::vfunc_5()
{
    UIGuideEvent* pEvent = FUN_14136f3e0(0x4e53);
    if (pEvent != 0 && pEvent->FUN_14195b760() != 0)
        return 0;
    if (m_index < m_steps.GetCount())
        FUN_141383f50();
    return m_index >= m_steps.GetCount();
}
MS2_REPLACE_METHOD(0x141383EA0, CGuideActionUITutorial, vfunc_5, 161, 0x17D9A10A);

// @0x141383f50
void CGuideActionUITutorial::FUN_141383f50()
{
    if (m_tick == 0)
        m_tick = FUN_140869420();
    if (FUN_140869420() - m_tick >= m_steps[m_index].m_waitTick
        || (CUIService::GetInstance()->FUN_141adbb00() == 0 && TSingleton<CInputKeyHandler>::GetInstance()->FUN_14116dcb0(0x493e2, false, 0)))
    {
        m_index++;
        m_tick = 0;
        UIGuideEvent* pEvent;
        if (m_index < m_steps.GetCount() && (pEvent = FUN_14136f3e0(0x4e53)) != 0)
            pEvent->FUN_14195a520(m_entityId, m_steps[m_index].m_textId, 0);
    }
}
MS2_REPLACE_METHOD(0x141383F50, CGuideActionUITutorial, FUN_141383f50, 292, 0x7731A2D4);

// ---- CGuideActionUITextBase ---------------------------------------------------------------------------------------------

// @0x141384080
ClassObject* CGuideActionUITextBase::CreateObject()
{
    return new CGuideActionUITextBase;
}

// @0x1413840e0
CStringW CGuideActionUITextBase::GetTypeName()
{
    return L"CGuideActionUITextBase";
}
MS2_REPLACE_METHOD(0x1413840E0, CGuideActionUITextBase, GetTypeName, 61, 0x48C1E305);

// @0x141384130
void CGuideActionUITextBase::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideAction::vfunc_2(pElem);
    m_entityId = 0;
    m_textId = 0;
    m_isNotClose = 0;
    m_controllerType = GuideController_Any;
    FUN_1408731e0(pElem, "entityId", m_entityId);
    FUN_140873220(pElem, "textId", m_textId);
    FUN_1408731e0(pElem, "isNotClose", m_isNotClose);
    XmlEnumName<CGuideControllerType, FUN_14021ade0>(pElem, "controllerType", m_controllerType);
}
MS2_REPLACE_METHOD(0x141384130, CGuideActionUITextBase, vfunc_2, 198, 0xED9DD14F);

// @0x141384200
bool CGuideActionUITextBase::FUN_141384200()
{
    if (m_controllerType == GuideController_Any)
        return true;
    switch (m_controllerType)
    {
    case GuideController_Keyboard:
        return *FUN_1409a8b10()->FUN_140a58500() == 0;
    case GuideController_GamePad:
        return *FUN_1409a8b10()->FUN_140a58500() == 1;
    }
    return true;
}
MS2_REPLACE_METHOD(0x141384200, CGuideActionUITextBase, FUN_141384200, 150, 0x9F09BED5);

// ---- CGuideActionUISummary ----------------------------------------------------------------------------------------------

// @0x1413842a0
ClassObject* CGuideActionUISummary::CreateObject()
{
    return new CGuideActionUISummary;
}

// @0x141384300
CStringW CGuideActionUISummary::GetTypeName()
{
    return L"CGuideActionUISummary";
}
MS2_REPLACE_METHOD(0x141384300, CGuideActionUISummary, GetTypeName, 61, 0x4F917D31);

// @0x141384350
void CGuideActionUISummary::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideActionUITextBase::vfunc_2(pElem);
    if (m_entityId == 0)
        m_entityId = 1;
}
MS2_REPLACE_METHOD(0x141384350, CGuideActionUISummary, vfunc_2, 57, 0x57474244);

// @0x141384390
void CGuideActionUISummary::vfunc_3()
{
    if (!FUN_141384200())
        return;
    if (UIGuideEvent* pEvent = FUN_14136f3e0(0x4e53))
        pEvent->FUN_14195ab40(m_entityId, m_textId, 0);
}
MS2_REPLACE_METHOD(0x141384390, CGuideActionUISummary, vfunc_3, 86, 0x962E91AC);

// @0x1413843f0
void CGuideActionUISummary::vfunc_4()
{
    if (!FUN_141384200())
        return;
    if (m_isNotClose != 0)
        return;
    if (UIGuideEvent* pEvent = FUN_14136f3e0(0x4e53))
        pEvent->FUN_14195b540(m_entityId);
}
MS2_REPLACE_METHOD(0x1413843F0, CGuideActionUISummary, vfunc_4, 87, 0x99CAFAB3);

// @0x141384450
int CGuideActionUISummary::vfunc_5()
{
    if (UIGuideEvent* pEvent = FUN_14136f3e0(0x4e53))
        return pEvent->FUN_14195b810() == 0;
    return true;
}
MS2_REPLACE_METHOD(0x141384450, CGuideActionUISummary, vfunc_5, 80, 0xD07FF9D9);

// ---- CGuideActionUIArrow ------------------------------------------------------------------------------------------------

// @0x1413844b0
ClassObject* CGuideActionUIArrow::CreateObject()
{
    return new CGuideActionUIArrow;
}

// @0x141384510
CStringW CGuideActionUIArrow::GetTypeName()
{
    return L"CGuideActionUIArrow";
}
MS2_REPLACE_METHOD(0x141384510, CGuideActionUIArrow, GetTypeName, 61, 0xFC2D0672);

// @0x141384560
void CGuideActionUIArrow::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideActionUITextBase::vfunc_2(pElem);
    m_offset = DAT_143b01a60;
    m_direction = 0;
    m_align = 1;
    FUN_140874670(pElem, "offset", m_offset);
    FUN_140873220(pElem, "direction", m_direction);
    FUN_140873220(pElem, "align", m_align);
    if (m_entityId == 0)
        throw std::exception(StringFormat("CGuideActionGuideTextTip Id is Zero"));
}
MS2_REPLACE_METHOD(0x141384560, CGuideActionUIArrow, vfunc_2, 262, 0x93FBEE59);

// @0x141384680
void CGuideActionUIArrow::vfunc_3()
{
    if (!FUN_141384200())
        return;
    MS2Ptr<UIGuideEventArrow> spArrow(new UIGuideEventArrow);
    spArrow->m_id = m_entityId;
    spArrow->m_pos = m_offset;
    spArrow->m_direction = m_direction;
    spArrow->m_align = m_align;
    spArrow->m_textId = m_textId;
    if (UIGuideEvent* pEvent = FUN_14136f3e0(0x4e53))
        pEvent->FUN_141959a60(spArrow);
}
MS2_REPLACE_METHOD(0x141384680, CGuideActionUIArrow, vfunc_3, 351, 0x530B5AE4);

// @0x1413847f0
void CGuideActionUIArrow::vfunc_4()
{
    if (!FUN_141384200())
        return;
    if (m_isNotClose != 0)
        return;
    if (UIGuideEvent* pEvent = FUN_14136f3e0(0x4e53))
        pEvent->FUN_14195a0c0(m_entityId);
}
MS2_REPLACE_METHOD(0x1413847F0, CGuideActionUIArrow, vfunc_4, 87, 0x06DC8ADB);

// ---- CGuideActionUITextTip ----------------------------------------------------------------------------------------------

// @0x141384850
ClassObject* CGuideActionUITextTip::CreateObject()
{
    return new CGuideActionUITextTip;
}

// @0x1413848b0
CStringW CGuideActionUITextTip::GetTypeName()
{
    return L"CGuideActionUITextTip";
}
MS2_REPLACE_METHOD(0x1413848B0, CGuideActionUITextTip, GetTypeName, 61, 0xD930FB3B);

// @0x141384900
void CGuideActionUITextTip::vfunc_3()
{
    if (!FUN_141384200())
        return;
    if (UIGuideEvent* pEvent = FUN_14136f3e0(0x4e53))
        pEvent->FUN_14195b330(m_entityId, m_textId);
}
MS2_REPLACE_METHOD(0x141384900, CGuideActionUITextTip, vfunc_3, 83, 0x64D30544);

// @0x141384960
void CGuideActionUITextTip::vfunc_4()
{
    if (!FUN_141384200())
        return;
    if (m_isNotClose != 0)
        return;
    if (UIGuideEvent* pEvent = FUN_14136f3e0(0x4e53))
        pEvent->FUN_14195b600(m_entityId);
}
MS2_REPLACE_METHOD(0x141384960, CGuideActionUITextTip, vfunc_4, 87, 0x053CEE13);

// ---- CGuideActionUIArrowDialog ------------------------------------------------------------------------------------------

// @0x1413849c0
ClassObject* CGuideActionUIArrowDialog::CreateObject()
{
    return new CGuideActionUIArrowDialog;
}

// @0x141384a20
CStringW CGuideActionUIArrowDialog::GetTypeName()
{
    return L"CGuideActionUIArrowDialog";
}
MS2_REPLACE_METHOD(0x141384A20, CGuideActionUIArrowDialog, GetTypeName, 61, 0x24292D51);

// @0x141384a70
void CGuideActionUIArrowDialog::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideActionUIArrow::vfunc_2(pElem);
    m_dialogID = 0;
    m_customPosValue = 0;
    m_childIndex = -1;
    FUN_140873220(pElem, "dialogID", m_dialogID);
    FUN_1408733e0(pElem, "dialogName", m_dialogName);
    ReadValueList(pElem, "focusDialogName", m_focusDialogName);
    FUN_1408733e0(pElem, "customPosType", m_customPosType);
    FUN_1408731e0(pElem, "customPosValue", m_customPosValue);
    CStringA strChildName;
    FUN_1408733e0(pElem, "childName", strChildName);
    FUN_14015f050(strChildName, m_childName, ".");
    FUN_1408731e0(pElem, "childIndex", m_childIndex);
}
MS2_REPLACE_METHOD(0x141384A70, CGuideActionUIArrowDialog, vfunc_2, 335, 0x65231710);

// @0x141384bd0
void CGuideActionUIArrowDialog::vfunc_3()
{
    if (!FUN_141384200())
        return;
    UIGuideEventArrowDialog* pArrow = new UIGuideEventArrowDialog;
    pArrow->m_id = m_entityId;
    pArrow->m_pos = m_offset;
    pArrow->m_direction = m_direction;
    pArrow->m_align = m_align;
    pArrow->m_textId = m_textId;
    pArrow->m_38 = m_dialogID;
    pArrow->m_name = m_dialogName;
    pArrow->m_48 = m_childIndex;
    pArrow->m_path.Copy(m_childName);
    pArrow->m_scenes.Copy(m_focusDialogName);
    pArrow->FUN_14195e2d0(m_customPosType);
    pArrow->m_param = m_customPosValue;
    if (UIGuideEvent* pEvent = FUN_14136f3e0(0x4e53))
        pEvent->FUN_141959a60(MS2Ptr<UIGuideEventArrow>(pArrow));
}
MS2_REPLACE_METHOD(0x141384BD0, CGuideActionUIArrowDialog, vfunc_3, 505, 0x9E3B41CF);

// ---- CGuideActionUIArrowClose -------------------------------------------------------------------------------------------

// @0x141384dd0
ClassObject* CGuideActionUIArrowClose::CreateObject()
{
    return new CGuideActionUIArrowClose;
}

// @0x141384e30
CStringW CGuideActionUIArrowClose::GetTypeName()
{
    return L"CGuideActionUIArrowClose";
}
MS2_REPLACE_METHOD(0x141384E30, CGuideActionUIArrowClose, GetTypeName, 61, 0xC25880EC);

// @0x141384e80
void CGuideActionUIArrowClose::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideAction::vfunc_2(pElem);
    m_entityId = 0;
    m_isAtOpen = 0;
    FUN_140873220(pElem, "entityId", m_entityId);
    FUN_1408731e0(pElem, "isAtOpen", m_isAtOpen);
}
MS2_REPLACE_METHOD(0x141384E80, CGuideActionUIArrowClose, vfunc_2, 116, 0x3A1B089C);

// @0x141384f00
void CGuideActionUIArrowClose::vfunc_3()
{
    if (m_isAtOpen != 0)
    {
        if (UIGuideEvent* pEvent = FUN_14136f3e0(0x4e53))
            pEvent->FUN_14195a0c0(m_entityId);
    }
}
MS2_REPLACE_METHOD(0x141384F00, CGuideActionUIArrowClose, vfunc_3, 66, 0xAE2972A5);

// @0x141384f50
void CGuideActionUIArrowClose::vfunc_4()
{
    if (m_isAtOpen == 0)
    {
        if (UIGuideEvent* pEvent = FUN_14136f3e0(0x4e53))
            pEvent->FUN_14195a0c0(m_entityId);
    }
}
MS2_REPLACE_METHOD(0x141384F50, CGuideActionUIArrowClose, vfunc_4, 66, 0xD424E1C8);

// ---- CGuideActionConditionAction ----------------------------------------------------------------------------------------

// @0x141384fa0
ClassObject* CGuideActionConditionAction::CreateObject()
{
    return new CGuideActionConditionAction;
}

// @0x141385000
CStringW CGuideActionConditionAction::GetTypeName()
{
    return L"CGuideActionConditionAction";
}
MS2_REPLACE_METHOD(0x141385000, CGuideActionConditionAction, GetTypeName, 61, 0x5646FED4);

// The exe builds every nested condition / action from the list element, not from the child it iterates.
// @0x141385050
void CGuideActionConditionAction::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideAction::vfunc_2(pElem);
    if (Unk_140165cf0* pConditions = pElem->FUN_140165cf0("conditions"))
    {
        for (Unk_140165cf0* pChild = pConditions->FUN_140165cf0("condition"); pChild != 0;
             pChild = pChild->FUN_140168650("condition"))
        {
            MS2Ptr<CGuideCondition> spCondition = FUN_1413a52c0(pConditions);
            if (spCondition.get())
                m_conditions.Add(spCondition);
        }
    }
    if (Unk_140165cf0* pActions = pElem->FUN_140165cf0("actions"))
    {
        for (Unk_140165cf0* pChild = pActions->FUN_140165cf0("action"); pChild != 0; pChild = pChild->FUN_140168650("action"))
        {
            MS2Ptr<CGuideAction> spAction = FUN_141382b90(pActions);
            m_actions.Add(spAction);
        }
    }
}
MS2_REPLACE_METHOD(0x141385050, CGuideActionConditionAction, vfunc_2, 346, 0xAB6C5F4B);

// @0x1413851b0
void CGuideActionConditionAction::vfunc_3()
{
    m_started = 0;
    for (unsigned i = 0; i < m_conditions.GetCount(); i++)
    {
        if (FUN_1413a5570(m_conditions[i].operator->()) == 0)
            return;
    }
    for (unsigned i = 0; i < m_actions.GetCount(); i++)
        m_actions[i]->vfunc_3();
    m_started = 1;
}
MS2_REPLACE_METHOD(0x1413851B0, CGuideActionConditionAction, vfunc_3, 239, 0x745884F6);

// @0x1413852b0
int CGuideActionConditionAction::vfunc_5()
{
    if (m_started == 0)
        return 1;
    for (unsigned i = 0; i < m_actions.GetCount(); i++)
    {
        if (m_actions[i]->vfunc_5() == 0)
            return 0;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1413852B0, CGuideActionConditionAction, vfunc_5, 149, 0xDBA5AB3C);

// ---- CGuideActionEquipWeaponTutorial ------------------------------------------------------------------------------------

// @0x141385350
ClassObject* CGuideActionEquipWeaponTutorial::CreateObject()
{
    return new CGuideActionEquipWeaponTutorial;
}

// @0x1413853b0
CStringW CGuideActionEquipWeaponTutorial::GetTypeName()
{
    return L"CGuideActionEquipWeaponTutorial";
}
MS2_REPLACE_METHOD(0x1413853B0, CGuideActionEquipWeaponTutorial, GetTypeName, 61, 0x0CFC6CFB);

// @0x141385400
void CGuideActionEquipWeaponTutorial::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideAction::vfunc_2(pElem);
    m_isUse = 0;
    FUN_1408731e0(pElem, "isUse", m_isUse);
}
MS2_REPLACE_METHOD(0x141385400, CGuideActionEquipWeaponTutorial, vfunc_2, 75, 0x63935927);

// @0x141385460
void CGuideActionEquipWeaponTutorial::vfunc_3()
{
    FUN_141999d20(m_isUse);
    FUN_141a5d0a0(m_isUse);
}
MS2_REPLACE_METHOD(0x141385460, CGuideActionEquipWeaponTutorial, vfunc_3, 40, 0x95E90B84);

// @0x141385490
void CGuideActionEquipWeaponTutorial::vfunc_4()
{
    FUN_141999d20(0);
    FUN_141a5d0a0(0);
}
MS2_REPLACE_METHOD(0x141385490, CGuideActionEquipWeaponTutorial, vfunc_4, 28, 0x8673086D);

// ---- CGuideActionForceClear ---------------------------------------------------------------------------------------------

// @0x1413854c0
ClassObject* CGuideActionForceClear::CreateObject()
{
    return new CGuideActionForceClear;
}

// @0x141385520
CStringW CGuideActionForceClear::GetTypeName()
{
    return L"CGuideActionForceClear";
}
MS2_REPLACE_METHOD(0x141385520, CGuideActionForceClear, GetTypeName, 61, 0x801B2F21);

// @0x141385570
void CGuideActionForceClear::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideAction::vfunc_2(pElem);
    m_id = 0;
    FUN_1408731e0(pElem, "id", m_id);
    if (m_id == 0)
        throw std::exception("forceClear id is Zero");
}
MS2_REPLACE_METHOD(0x141385570, CGuideActionForceClear, vfunc_2, 120, 0x8CEF9B0A);

// @0x1413855f0
void CGuideActionForceClear::vfunc_3()
{
    TSingleton<CGuideManager>::GetInstance()->FinishById(m_id);
}
MS2_REPLACE_METHOD(0x1413855F0, CGuideActionForceClear, vfunc_3, 35, 0xCF631F4F);

// ---- CGuideActionSequenceCamera -----------------------------------------------------------------------------------------

// @0x141385620
ClassObject* CGuideActionSequenceCamera::CreateObject()
{
    return new CGuideActionSequenceCamera;
}

// @0x141385680
CStringW CGuideActionSequenceCamera::GetTypeName()
{
    return L"CGuideActionSequenceCamera";
}
MS2_REPLACE_METHOD(0x141385680, CGuideActionSequenceCamera, GetTypeName, 61, 0x67A88BE6);

// @0x1413856d0
void CGuideActionSequenceCamera::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideAction::vfunc_2(pElem);
    m_isUseCinematicCutScene = 1;
    m_endInterpolationTime = 0;
    FUN_1408731e0(pElem, "isUseCinematicCutScene", m_isUseCinematicCutScene);
    FUN_140873360(pElem, "endInterpolationTime", m_endInterpolationTime);
    ReadValueList(pElem, "triggerCameraId", m_triggerCameraId);
}
MS2_REPLACE_METHOD(0x1413856D0, CGuideActionSequenceCamera, vfunc_2, 146, 0xFDC7C574);

// @0x141385770
void CGuideActionSequenceCamera::vfunc_3()
{
    m_skipped = 0;
    if (FUN_1409478c0()->FUN_140af7e30() != 2)
        FUN_140ad4b90()->FUN_141863460(0);
    FUN_140ad4b90()->FUN_141863340(m_triggerCameraId, 1);
    if (m_isUseCinematicCutScene != 0)
    {
        FUN_1408e57f0()->FUN_1422b9fd0(0x6200041);
        CStringW strEmpty;
        if (UICutSceneCinematic* pCinematic = FUN_14136f290(0x4e52))
        {
            CStringW strKey = GetStringCommon(0x666);
            if (*FUN_1409a8b10()->FUN_140a58500() != 0)
                strKey = FUN_1409331f0()->FUN_14142d760(0x49409, 2);
            pCinematic->FUN_141907f80(3, strEmpty);
            pCinematic->FUN_141907d60(3, strKey, GetStringCommon(0x667));
            FUN_140939a10()->RegisterNotify(L"NotifyCutSceneCinematicSkip",
                Delegate<void(NotifyObject*)>(this, &CGuideActionSequenceCamera::FUN_141385ba0));
        }
    }
    FUN_1413837a0(0x15);
    FUN_1413837a0(0x13);
}

// @0x141385a40
void CGuideActionSequenceCamera::vfunc_4()
{
    if (FUN_1409478c0()->FUN_140af7e30() != 2)
        FUN_140ad4b90()->FUN_141863460(m_endInterpolationTime);
    if (m_isUseCinematicCutScene != 0)
    {
        FUN_1408e57f0()->FUN_1422b9fd0(0x620001d);
        FUN_140939a10()->UnregisterNotify(L"NotifyCutSceneCinematicSkip",
            Delegate<void(NotifyObject*)>(this, &CGuideActionSequenceCamera::FUN_141385ba0));
    }
    FUN_1413837e0(0x15);
    FUN_1413837e0(0x13);
}

// @0x141385b50
int CGuideActionSequenceCamera::vfunc_5()
{
    if (m_skipped != 0)
        return 1;
    if (FUN_1409478c0()->FUN_140af7e30() != 2)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x141385B50, CGuideActionSequenceCamera, vfunc_5, 59, 0xD5163C2B);

// @0x141385ba0
void CGuideActionSequenceCamera::FUN_141385ba0(NotifyObject* pNotify)
{
    m_skipped = 1;
}
MS2_REPLACE_METHOD(0x141385BA0, CGuideActionSequenceCamera, FUN_141385ba0, 23, 0x3927F3CB);

// ---- CGuideActionSmartRecommend -----------------------------------------------------------------------------------------

// @0x141385bc0
ClassObject* CGuideActionSmartRecommend::CreateObject()
{
    return new CGuideActionSmartRecommend;
}

// @0x141385c20
CStringW CGuideActionSmartRecommend::GetTypeName()
{
    return L"CGuideActionSmartRecommend";
}
MS2_REPLACE_METHOD(0x141385C20, CGuideActionSmartRecommend, GetTypeName, 61, 0x1649ED31);

// @0x141385c70
void CGuideActionSmartRecommend::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideAction::vfunc_2(pElem);
    m_recommendCode = 0;
    FUN_140873220(pElem, "recommendCode", m_recommendCode);
}
MS2_REPLACE_METHOD(0x141385C70, CGuideActionSmartRecommend, vfunc_2, 75, 0xAB16872D);

// @0x141385cd0
void CGuideActionSmartRecommend::vfunc_3()
{
    if (UISmartRecommendNotifyDialog* pDialog = FUN_14136f5c0(0x4e9e))
        pDialog->FUN_14134dc50(m_recommendCode);
    if (CUIService::GetInstance()->FUN_141adc940((eUIClassID)0x4e9e) == 0)
        CUIService::GetInstance()->FUN_141adc5d0((eUIClassID)0x4e9e);
    CUIService::GetInstance()->OpenDialog((eUIClassID)0x4e9e);
}
MS2_REPLACE_METHOD(0x141385CD0, CGuideActionSmartRecommend, vfunc_3, 113, 0x6D6DCE77);

// ---- CGuideActionServerTriggerEvent -------------------------------------------------------------------------------------

// @0x141385d50
ClassObject* CGuideActionServerTriggerEvent::CreateObject()
{
    return new CGuideActionServerTriggerEvent;
}

// @0x141385db0
CStringW CGuideActionServerTriggerEvent::GetTypeName()
{
    return L"CGuideActionServerTriggerEvent";
}
MS2_REPLACE_METHOD(0x141385DB0, CGuideActionServerTriggerEvent, GetTypeName, 61, 0xA07207F4);

// @0x141385e00
void CGuideActionServerTriggerEvent::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideAction::vfunc_2(pElem);
    m_eventID = 0;
    FUN_140873220(pElem, "eventID", m_eventID);
}
MS2_REPLACE_METHOD(0x141385E00, CGuideActionServerTriggerEvent, vfunc_2, 75, 0xC65AB750);

// @0x141385e60
void CGuideActionServerTriggerEvent::vfunc_3()
{
    COutPacket packet(static_cast<int>(SendOp::Trigger), 0);
    packet.vfunc_o10_1(9);
    packet.vfunc_o10_1(1);
    packet.vfunc_o10_3(m_eventID);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x141385E60, CGuideActionServerTriggerEvent, vfunc_3, 105, 0xC92DFB3A);

// ---- CGuideActionGameMenuLimit ------------------------------------------------------------------------------------------

// @0x141385ed0
ClassObject* CGuideActionGameMenuLimit::CreateObject()
{
    return new CGuideActionGameMenuLimit;
}

// @0x141385f30
CStringW CGuideActionGameMenuLimit::GetTypeName()
{
    return L"CGuideActionGameMenuLimit";
}
MS2_REPLACE_METHOD(0x141385F30, CGuideActionGameMenuLimit, GetTypeName, 61, 0x0F931D7F);

// @0x141385f80
void CGuideActionGameMenuLimit::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideAction::vfunc_2(pElem);
    m_enabled = 0;
    FUN_140873220(pElem, "menuID", m_menuID);
    FUN_1408731e0(pElem, "enabled", m_enabled);
}
MS2_REPLACE_METHOD(0x141385F80, CGuideActionGameMenuLimit, vfunc_2, 104, 0xA1C6CDF7);

// @0x141385ff0
void CGuideActionGameMenuLimit::vfunc_3()
{
    if (UIGameMenuDialog* pMenu = FUN_140938b90(0x4e28))
        pMenu->FUN_141939770(m_menuID, m_enabled);
    if (UIGamePadMenuDialog* pPadMenu = Unk_GaGetUI<UIGamePadMenuDialog>(0x4f63))
        pPadMenu->FUN_140c1ba90(m_menuID, m_enabled);
}
MS2_REPLACE_METHOD(0x141385FF0, CGuideActionGameMenuLimit, vfunc_3, 114, 0x7666787D);

// ---- CGuideActionRequestTutorialItem ------------------------------------------------------------------------------------

// @0x141386070
ClassObject* CGuideActionRequestTutorialItem::CreateObject()
{
    return new CGuideActionRequestTutorialItem;
}

// @0x1413860d0
CStringW CGuideActionRequestTutorialItem::GetTypeName()
{
    return L"CGuideActionRequestTutorialItem";
}
MS2_REPLACE_METHOD(0x1413860D0, CGuideActionRequestTutorialItem, GetTypeName, 61, 0x9503A9F5);

// @0x141386120
void CGuideActionRequestTutorialItem::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideAction::vfunc_2(pElem);
}
MS2_REPLACE_METHOD(0x141386120, CGuideActionRequestTutorialItem, vfunc_2, 34, 0xBF94A485);

// @0x141386150
void CGuideActionRequestTutorialItem::vfunc_3()
{
    COutPacket packet(static_cast<int>(SendOp::RequestTutorialItem), 0);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x141386150, CGuideActionRequestTutorialItem, vfunc_3, 63, 0x01AEACBA);

// ---- CGuideActionSideNpcTalk --------------------------------------------------------------------------------------------

// @0x1413861a0
ClassObject* CGuideActionSideNpcTalk::CreateObject()
{
    return new CGuideActionSideNpcTalk;
}

// @0x141386200
CStringW CGuideActionSideNpcTalk::GetTypeName()
{
    return L"CGuideActionSideNpcTalk";
}
MS2_REPLACE_METHOD(0x141386200, CGuideActionSideNpcTalk, GetTypeName, 61, 0xA366769F);

// @0x141386250
void CGuideActionSideNpcTalk::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideAction::vfunc_2(pElem);
    m_uiType = 0;
    m_duration = 3000;
    FUN_140e8ecb0(pElem, "uiType", m_uiType);
    FUN_1408733e0(pElem, "usm", m_usm);
    FUN_140873220(pElem, "scriptID", m_scriptID);
    FUN_1408733e0(pElem, "illust", m_illust);
    FUN_1408732a0(pElem, "duration", m_duration);
    FUN_1408733e0(pElem, "voice", m_voice);
    FUN_1408733e0(pElem, "sound", m_sound);
}
MS2_REPLACE_METHOD(0x141386250, CGuideActionSideNpcTalk, vfunc_2, 261, 0x87AB5385);

// @0x141386360
void CGuideActionSideNpcTalk::vfunc_3()
{
    if (UISidePopupTalk* pTalk = Unk_GaGetUI<UISidePopupTalk>(0x4f57))
    {
        MS2Ptr<SidePopupTalkParam> spParam(new SidePopupTalkParam);
        GA_SIDEPOPUP(spParam)->m_nKind = m_uiType;
        GA_SIDEPOPUP(spParam)->m_strUsm = m_usm;
        GA_SIDEPOPUP(spParam)->m_scriptIds.push_back(m_scriptID);
        GA_SIDEPOPUP(spParam)->m_strIllust = m_illust;
        GA_SIDEPOPUP(spParam)->m_nDuration = m_duration;
        GA_SIDEPOPUP(spParam)->m_strVoice = m_voice;
        GA_SIDEPOPUP(spParam)->m_strSound = m_sound;
        pTalk->FUN_140e879a0(spParam);
    }
}
MS2_REPLACE_METHOD(0x141386360, CGuideActionSideNpcTalk, vfunc_3, 486, 0x654D8AF9);

// ---- CGuideActionClearTutorial ------------------------------------------------------------------------------------------

// @0x141386550
ClassObject* CGuideActionClearTutorial::CreateObject()
{
    return new CGuideActionClearTutorial;
}

// @0x1413865b0
CStringW CGuideActionClearTutorial::GetTypeName()
{
    return L"CGuideActionClearTutorial";
}
MS2_REPLACE_METHOD(0x1413865B0, CGuideActionClearTutorial, GetTypeName, 61, 0x90D80BF6);

// @0x141386600
void CGuideActionClearTutorial::vfunc_3()
{
    COutPacket packet(static_cast<int>(SendOp::Tutorial), 0);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x141386600, CGuideActionClearTutorial, vfunc_3, 63, 0x1975E45B);

// ---- template glue (the CAtlArray / MS2Ptr / Delegate instances pair through the symbol harvest) -------------------------
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb1040-0x142cb10d0 .text$yd
