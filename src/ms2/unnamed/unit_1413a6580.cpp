// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The guide-condition classes Input, ActionInput, ReturnPortal and
// PortalEnable (factories, names, loaders and checks). See ms2/placeholder/cguidecondition.h.
// MS2-UNIT: unit_1413a6580
// MS2-RANGE: 0x1413a6580-0x1413a6e30 .text$mn
// MS2-RANGE: 0x1400f2ed0-0x1400f2f20 .text$di
// MS2-RANGE: 0x1413b4b00-0x1413b4b40 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"

#include <new>

#include "ms2/placeholder/cguidecondition.h"
#include "ms2/placeholder/nipoint3.h"
#include <NiPoint3.h>                            // C3: WorldService::FUN_141bc2c90 takes a NiPoint3
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/portal.h"
#include "ms2/commonfiles/usermail.h"  // C3: CUserMail::FUN_1408e57f0 (the scene-service global)
int XmlGetAttr(class TiXmlElement*, char const*, unsigned int&);   // C3: was FUN_140873220

// return types of the getters this unit calls
class CUIService;
class Unk_SoundSink;

// ---- unit-local views of the exe objects and unrecovered callees --------------------------------------------------------

// The world manager (FUN_1403ed2d0).
class Unk_GcWorld : public WorldService
{
};

// The local player: only the position getter (slot 18) is used here.
class Unk_GcPC
{
public:
    virtual void Unk_Slot0(); virtual void Unk_Slot1(); virtual void Unk_Slot2(); virtual void Unk_Slot3();
    virtual void Unk_Slot4(); virtual void Unk_Slot5(); virtual void Unk_Slot6(); virtual void Unk_Slot7();
    virtual void Unk_Slot8(); virtual void Unk_Slot9(); virtual void Unk_Slot10(); virtual void Unk_Slot11();
    virtual void Unk_Slot12(); virtual void Unk_Slot13(); virtual void Unk_Slot14(); virtual void Unk_Slot15();
    virtual void Unk_Slot16(); virtual void Unk_Slot17();
    virtual Vector3 vfunc_18();                     // 0x90 the position
};

            // CUIService
class CInputKeyHandler { public: bool FUN_14116d950(int, bool, int); }; class Unk_GcKeyboard : public CInputKeyHandler {};
void* FUN_14025e7c0();
class Unk_GcKeyBinds
{
public:

};
Unk_SoundSink* FUN_1409331f0();
class CKeyTable   // C3: member view for the former free stand-ins
{
public: int GetPairKey(int nKey, int& rOut);
    int FUN_14142c940(__int64, int);
};
class GFxSceneService   // C3: member view for the former free stand-ins
{
public:
    int GetSubSceneId();
};
unsigned long GetTickCountMs2();   // C3: was FUN_140869420

#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regActionInput(L"CGuideConditionActionInput", CGuideConditionActionInput::CreateObject);   // .text$di 0x1400f2ed0
#endif

// ---- CGuideConditionInput -------------------------------------------------------------------------------------------------

// @0x1413a6580
ClassObject* CGuideConditionInput::CreateObject()
{
    return new CGuideConditionInput;
}

// @0x1413a65e0
CStringW CGuideConditionInput::GetTypeName()
{
    return L"CGuideConditionInput";
}
MS2_REPLACE_METHOD(0x1413A65E0, CGuideConditionInput, GetTypeName, 61, 0x1A5E73B2);

// @0x1413a6630
CGuideConditionInput::CGuideConditionInput()
{
    m_nTick = 0;
}

// @0x1413a6670
void CGuideConditionInput::vfunc_2(TiXmlElement* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    XmlGetAttr((class TiXmlElement*)(pElem), "tick", m_nTick);
}
MS2_REPLACE_METHOD(0x1413A6670, CGuideConditionInput, vfunc_2, 63, 0x3E7F60A9);

// @0x1413a66c0
int CGuideConditionInput::vfunc_3()
{
    if (((class GFxSceneService*)(void*)(((void*)CUserMail::FUN_1408e57f0())))->GetSubSceneId() == 0x6200031)
        return 0;
    int nHeld = (reinterpret_cast<Unk_GcKeyboard*>(FUN_14025e7c0())->FUN_14116d950(m_n20, false, 0) && TSingleton<CUIService>::GetInstance()->FUN_141adbb00() == 0) ? 1 : 0;
    if (m_nTick == 0)
        return FUN_1413a55a0(nHeld);
    if (nHeld == 0)
    {
        m_nDeadline = 0;
        return FUN_1413a55a0(0);
    }
    if (m_nDeadline == 0)
        m_nDeadline = GetTickCountMs2() + m_nTick;
    return FUN_1413a5600(GetTickCountMs2() >= (unsigned)m_nDeadline);
}
MS2_REPLACE_METHOD(0x1413A66C0, CGuideConditionInput, vfunc_3, 252, 0xEEAD86B3);

// @0x1413a67d0
void CGuideConditionInput::vfunc_4()
{
    CGuideCondition::vfunc_4();
    m_nDeadline = 0;
}
MS2_REPLACE_METHOD(0x1413A67D0, CGuideConditionInput, vfunc_4, 36, 0x0C16BB1F);

// @0x1413a6800
CStringW CGuideConditionInput::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    str.Append(StringFormat(L"tick({0})", m_nTick));
    return str;
}
MS2_REPLACE_METHOD(0x1413A6800, CGuideConditionInput, vfunc_7, 167, 0xFEF9E619);

// ---- CGuideConditionActionInput -------------------------------------------------------------------------------------------

// @0x1413a68b0
ClassObject* CGuideConditionActionInput::CreateObject()
{
    return new CGuideConditionActionInput;
}

// @0x1413a6910
CStringW CGuideConditionActionInput::GetTypeName()
{
    return L"CGuideConditionActionInput";
}
MS2_REPLACE_METHOD(0x1413A6910, CGuideConditionActionInput, GetTypeName, 61, 0x9F425B26);

// @0x1413a6960
int CGuideConditionActionInput::vfunc_3()
{
    int nKey = 0;
    int nAltKey0, nAltKey1, nAltKey2;
    nKey = ((class CKeyTable*)(class Unk_GcKeyBinds*)(reinterpret_cast<Unk_GcKeyBinds*>(FUN_1409331f0())))->FUN_14142c940(m_n20, 0);
    if (nKey != 0)
    {
        if (reinterpret_cast<Unk_GcKeyboard*>(FUN_14025e7c0())->FUN_14116d950(nKey, false, 0))
            return FUN_1413a55a0(1);
        nAltKey0 = 0;
        if (((class CKeyTable*)reinterpret_cast<Unk_GcKeyBinds*>(FUN_1409331f0()))->GetPairKey(nKey, nAltKey0) != 0 && reinterpret_cast<Unk_GcKeyboard*>(FUN_14025e7c0())->FUN_14116d950(nAltKey0, false, 0))
            return FUN_1413a55a0(1);
    }
    nKey = ((class CKeyTable*)(class Unk_GcKeyBinds*)(reinterpret_cast<Unk_GcKeyBinds*>(FUN_1409331f0())))->FUN_14142c940(m_n20, 1);
    if (nKey != 0)
    {
        if (reinterpret_cast<Unk_GcKeyboard*>(FUN_14025e7c0())->FUN_14116d950(nKey, false, 0))
            return FUN_1413a55a0(1);
        nAltKey1 = 0;
        if (((class CKeyTable*)reinterpret_cast<Unk_GcKeyBinds*>(FUN_1409331f0()))->GetPairKey(nKey, nAltKey1) != 0 && reinterpret_cast<Unk_GcKeyboard*>(FUN_14025e7c0())->FUN_14116d950(nAltKey1, false, 0))
            return FUN_1413a55a0(1);
    }
    nKey = ((class CKeyTable*)(class Unk_GcKeyBinds*)(reinterpret_cast<Unk_GcKeyBinds*>(FUN_1409331f0())))->FUN_14142c940(m_n20, 2);
    if (nKey != 0)
    {
        if (reinterpret_cast<Unk_GcKeyboard*>(FUN_14025e7c0())->FUN_14116d950(nKey, false, 0))
            return FUN_1413a55a0(1);
        nAltKey2 = 0;
        if (((class CKeyTable*)reinterpret_cast<Unk_GcKeyBinds*>(FUN_1409331f0()))->GetPairKey(nKey, nAltKey2) != 0 && reinterpret_cast<Unk_GcKeyboard*>(FUN_14025e7c0())->FUN_14116d950(nAltKey2, false, 0))
            return FUN_1413a55a0(1);
    }
    return FUN_1413a55a0(0);
}
MS2_REPLACE_METHOD(0x1413A6960, CGuideConditionActionInput, vfunc_3, 595, 0x47F42DA8);

// ---- CGuideConditionReturnPortal ------------------------------------------------------------------------------------------

// @0x1413a6bc0
ClassObject* CGuideConditionReturnPortal::CreateObject()
{
    return new CGuideConditionReturnPortal;
}

// @0x1413a6c20
CStringW CGuideConditionReturnPortal::GetTypeName()
{
    return L"CGuideConditionReturnPortal";
}
MS2_REPLACE_METHOD(0x1413A6C20, CGuideConditionReturnPortal, GetTypeName, 61, 0x52A2D98D);

// @0x1413a6c70
int CGuideConditionReturnPortal::vfunc_3()
{
    return ((class Unk_GcWorld*)WorldService::GetInstance())->FUN_141bc2f40();
}
MS2_REPLACE_METHOD(0x1413A6C70, CGuideConditionReturnPortal, vfunc_3, 27, 0xD322AAC2);

// ---- CGuideConditionPortalEnable ------------------------------------------------------------------------------------------

// @0x1413a6ca0
ClassObject* CGuideConditionPortalEnable::CreateObject()
{
    return new CGuideConditionPortalEnable;
}

// @0x1413a6d00
CStringW CGuideConditionPortalEnable::GetTypeName()
{
    return L"CGuideConditionPortalEnable";
}
MS2_REPLACE_METHOD(0x1413A6D00, CGuideConditionPortalEnable, GetTypeName, 61, 0x4519D41B);

// @0x1413a6d50
int CGuideConditionPortalEnable::vfunc_3()
{
    Unk_GcPC* pPC = (Unk_GcPC*)((class Unk_GcWorld*)WorldService::GetInstance())->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    ATL::CAtlArray<MS2Ptr<CPortal> > arrPortals;
    ((class Unk_GcWorld*)WorldService::GetInstance())->FUN_141bc2c90(reinterpret_cast<const NiPoint3&>(static_cast<const Vector3&>(pPC->vfunc_18())), &arrPortals);
    return FUN_1413a5600(arrPortals.GetCount() != 0);
}
MS2_REPLACE_METHOD(0x1413A6D50, CGuideConditionPortalEnable, vfunc_3, 205, 0x9D153889);
