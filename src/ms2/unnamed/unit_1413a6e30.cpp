// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The guide-condition classes Position, State and Interactable
// (factories, names, loaders and checks) and the dynamic initializers of eight conditions (Dialog .. FieldId) that
// register their factories with the ClassObject registry. See ms2/placeholder/cguidecondition.h.
// MS2-UNIT: unit_1413a6e30
// MS2-RANGE: 0x1413a6e30-0x1413a76f0 .text$mn
// MS2-RANGE: 0x1400f3420-0x1400f36a0 .text$di
// MS2-RANGE: 0x1413b50c0-0x1413b5100 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/classobject.h"   // C3: ClassObjectRegistrar (0x140316aa0)

#include <new>

#include "ms2/placeholder/cguidecondition.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/cubecraft_2.h"
#include "ms2/client/ms2/worldservice.h"
CString Unk_ReadString(class Unk_XmlNode*, char const*, CString);   // C3: was FUN_14015f710
class Unk_XmlNode   // C3: member view for the former element stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};

int XmlGetAttr(class TiXmlElement*, char const*, float&);   // C3: was FUN_140873360

// ---- unit-local views of the exe objects and unrecovered callees --------------------------------------------------------

// The interactable world object (CInteractObject, client\\ms2\\interactobject.h): only slot 7 and the use checks.
class CInteractObject : public CPtred
{
public:
    virtual void Unk_Slot1(); virtual void Unk_Slot2(); virtual void Unk_Slot3(); virtual void Unk_Slot4();
    virtual void Unk_Slot5(); virtual void Unk_Slot6();
    virtual int vfunc_7();                                  // 0x141404070 state is the second one
    int HasRequiredMastery();
    int CheckItemRequirement();
    int FUN_1413fdfc0();
    int HasAnyRequiredItem();
};

// The world manager (FUN_1403ed2d0).
class Unk_GcWorld : public WorldService
{
public:
    // (FUN_141bc6090, the interactable object at a point: WorldService's own member, point by value)
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
class PC   // C3: member view for the former free stand-ins
{
public:
    class CConstructionGuideObject* GetConstructionGuide();
};
class Unk_GcCore : public Unk_PCCubeCraft { };   // the cube-craft core: its position
class MyPC   // C3: member view for the former free stand-ins
{
public:
    class Unk_PCCubeCraft* GetActiveCubeCraft();
};
class PCBase   // C3: member view for the former free stand-ins
{
public:
    int GetCurStateId();
};

// The class-object factory registrar (0x140316aa0, commonfiles\dungeonmissiondata.cpp); the factories not defined here belong
// to the other guide-condition code units.

// The initialized marker: no storage, so the dynamic initializer is the registration call and nothing else.
struct Unk_RegMarker {};

#ifndef MS2_HOOK_DLL   // registers into the exe's ClassObject registrar at DllInit time, before the exe's CRT/locks exist
// @0x1400f3420
static char s_regDialog;
static Unk_RegMarker s_initDialog =
    (((ClassObjectRegistrar*)&s_regDialog)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionDialog"), &CGuideConditionDialog::CreateObject), Unk_RegMarker());

// @0x1400f3470
static char s_regEnterDungeon;
static Unk_RegMarker s_initEnterDungeon =
    (((ClassObjectRegistrar*)&s_regEnterDungeon)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionEnterDungeon"), &CGuideConditionEnterDungeon::CreateObject), Unk_RegMarker());

// @0x1400f34c0
static char s_regEquipItem;
static Unk_RegMarker s_initEquipItem =
    (((ClassObjectRegistrar*)&s_regEquipItem)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionEquipItem"), &CGuideConditionEquipItem::CreateObject), Unk_RegMarker());

// @0x1400f3510
static char s_regEquipSkill;
static Unk_RegMarker s_initEquipSkill =
    (((ClassObjectRegistrar*)&s_regEquipSkill)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionEquipSkill"), &CGuideConditionEquipSkill::CreateObject), Unk_RegMarker());

// @0x1400f3560
static char s_regExistItem;
static Unk_RegMarker s_initExistItem =
    (((ClassObjectRegistrar*)&s_regExistItem)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionExistItem"), &CGuideConditionExistItem::CreateObject), Unk_RegMarker());

// @0x1400f35b0
static char s_regExistShortcut;
static Unk_RegMarker s_initExistShortcut =
    (((ClassObjectRegistrar*)&s_regExistShortcut)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionExistShortcut"), &CGuideConditionExistShortcut::CreateObject), Unk_RegMarker());

// @0x1400f3600
static char s_regFalse;
static Unk_RegMarker s_initFalse =
    (((ClassObjectRegistrar*)&s_regFalse)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionFalse"), &CGuideConditionFalse::CreateObject), Unk_RegMarker());

// @0x1400f3650
static char s_regFieldId;
static Unk_RegMarker s_initFieldId =
    (((ClassObjectRegistrar*)&s_regFieldId)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionFieldId"), &CGuideConditionFieldId::CreateObject), Unk_RegMarker());
#endif

// ---- CGuideConditionPosition ----------------------------------------------------------------------------------------------

// @0x1413a6e30
ClassObject* CGuideConditionPosition::CreateObject()
{
    return new CGuideConditionPosition;
}

// @0x1413a6e90
CStringW CGuideConditionPosition::GetTypeName()
{
    return L"CGuideConditionPosition";
}
MS2_REPLACE_METHOD(0x1413A6E90, CGuideConditionPosition, GetTypeName, 61, 0x7DC5F128);

// @0x1413a6ee0
CGuideConditionPosition::CGuideConditionPosition()
{
}

// @0x1413a6f30
void CGuideConditionPosition::vfunc_2(TiXmlElement* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    for (TiXmlElement* pCube = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("cube")); pCube != 0; pCube = ((class TiXmlElement*)((class Unk_XmlNode*)(pCube))->NextSibling("cube")))
    {
        float fRange = 75.0f;
        XmlGetAttr((class TiXmlElement*)(pCube), "range", fRange);
        CString strPos = Unk_ReadString((class Unk_XmlNode*)(pCube), "pos", CString(""));
        ATL::CAtlArray<float> arrPos;
        XmlSplit(strPos, arrPos, ",");
        if (arrPos.GetCount() == 3)
        {
            Unk_GuideCube cube;
            cube.vPos.x = arrPos[0];
            cube.vPos.y = arrPos[1];
            cube.vPos.z = arrPos[2];
            cube.fRange = fRange;
            m_arrCube.Add(cube);
        }
    }
}
MS2_REPLACE_METHOD(0x1413A6F30, CGuideConditionPosition, vfunc_2, 412, 0x35406215);

// @0x1413a70e0
int CGuideConditionPosition::vfunc_3()
{
    Unk_GcPC* pPC = (Unk_GcPC*)((class Unk_GcWorld*)WorldService::GetInstance())->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    Vector3 pos = pPC->vfunc_18();
    if (((void*)((class PC*)(class Unk_GcPC*)(pPC))->GetConstructionGuide()) != 0 && ((class Unk_GcCore*)((class MyPC*)(class Unk_GcPC*)(pPC))->GetActiveCubeCraft()) != 0)
        pos = ((class Unk_GcCore*)((class MyPC*)(class Unk_GcPC*)(pPC))->GetActiveCubeCraft())->GetPtCell();
    for (size_t i = 0; i < m_arrCube.GetCount(); i++)
    {
        float fDist = (pos - m_arrCube.GetAt(i).vPos).Length();
        if (fDist < m_arrCube.GetAt(i).fRange)
            return ApplyNot(1);
    }
    return ApplyNot(0);
}
MS2_REPLACE_METHOD(0x1413A70E0, CGuideConditionPosition, vfunc_3, 307, 0xD9D4F299);

// @0x1413a7220
CStringW CGuideConditionPosition::vfunc_7()
{
    CStringW strCubes;
    for (unsigned i = 0; i < m_arrCube.GetCount(); i++)
    {
        Unk_GuideCube& rPos = m_arrCube.GetAt(i);
        strCubes.Append(StringFormat(L"[Pos:({0},{1},{2}),Range:{3}]", rPos.vPos.x, rPos.vPos.y, rPos.vPos.z, m_arrCube.GetAt(i).fRange));
    }
    CStringW str = FUN_1413a5820();
    str.Append(strCubes);
    return str;
}
MS2_REPLACE_METHOD(0x1413A7220, CGuideConditionPosition, vfunc_7, 366, 0x78D8B49A);

// ---- CGuideConditionState -------------------------------------------------------------------------------------------------

// @0x1413a73a0
ClassObject* CGuideConditionState::CreateObject()
{
    return new CGuideConditionState;
}

// @0x1413a7400
CStringW CGuideConditionState::GetTypeName()
{
    return L"CGuideConditionState";
}
MS2_REPLACE_METHOD(0x1413A7400, CGuideConditionState, GetTypeName, 61, 0xCF290588);

// @0x1413a7450
int CGuideConditionState::vfunc_3()
{
    Unk_GcPC* pPC = (Unk_GcPC*)((class Unk_GcWorld*)WorldService::GetInstance())->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    return ApplyNot(((class PCBase*)(class Unk_GcPC*)(pPC))->GetCurStateId() == m_n20);
}
MS2_REPLACE_METHOD(0x1413A7450, CGuideConditionState, vfunc_3, 96, 0xB70C5F8D);

// ---- CGuideConditionInteractable ------------------------------------------------------------------------------------------

// @0x1413a74c0
ClassObject* CGuideConditionInteractable::CreateObject()
{
    return new CGuideConditionInteractable;
}

// @0x1413a7520
CStringW CGuideConditionInteractable::GetTypeName()
{
    return L"CGuideConditionInteractable";
}
MS2_REPLACE_METHOD(0x1413A7520, CGuideConditionInteractable, GetTypeName, 61, 0x4EF3F619);

// @0x1413a7570
int CGuideConditionInteractable::vfunc_3()
{
    Unk_GcPC* pPC = (Unk_GcPC*)((class Unk_GcWorld*)WorldService::GetInstance())->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    CInteractObject* pObject = ((class Unk_GcWorld*)WorldService::GetInstance())->FUN_141bc6090(pPC->vfunc_18(), 1);
    if (pObject == 0)
        return 0;
    if (pObject->vfunc_7() == 0)
        return ApplyNot(0);
    if (pObject->FUN_1413fdfc0() == 0)
        return ApplyNot(0);
    if (pObject->CheckItemRequirement() == 0)
        return ApplyNot(0);
    if (pObject->HasAnyRequiredItem() == 0)
        return ApplyNot(0);
    if (pObject->HasRequiredMastery() == 0)
        return ApplyNot(0);
    return ApplyNot(1);
}
MS2_REPLACE_METHOD(0x1413A7570, CGuideConditionInteractable, vfunc_3, 374, 0x026F4DDB);
