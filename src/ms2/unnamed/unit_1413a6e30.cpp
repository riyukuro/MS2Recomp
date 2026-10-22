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

#include <new>

#include "ms2/placeholder/cguidecondition.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of the exe objects and unrecovered callees --------------------------------------------------------

// The interactable world object (CInteractObject, client\\ms2\\interactobject.h): only slot 7 and the use checks.
class CInteractObject : public CPtred
{
public:
    virtual void Unk_Slot1(); virtual void Unk_Slot2(); virtual void Unk_Slot3(); virtual void Unk_Slot4();
    virtual void Unk_Slot5(); virtual void Unk_Slot6();
    virtual int vfunc_7();                                  // 0x141404070 state is the second one
    int FUN_1413fdd80();
    int FUN_1413fde40();
    int FUN_1413fdfc0();
    int FUN_1413fe220();
};

// The world manager (FUN_1403ed2d0).
class Unk_GcWorld
{
public:
    void* FUN_141bd0cc0();                                  // the local player
    MS2Ptr<CInteractObject> FUN_141bc6090(Unk_StreamPoint pt, int nSkipDisabled);   // the interactable object at a point
};
Unk_GcWorld* FUN_1403ed2d0();

// The local player: only the position getter (slot 18) is used here.
class Unk_GcPC
{
public:
    virtual void Unk_Slot0(); virtual void Unk_Slot1(); virtual void Unk_Slot2(); virtual void Unk_Slot3();
    virtual void Unk_Slot4(); virtual void Unk_Slot5(); virtual void Unk_Slot6(); virtual void Unk_Slot7();
    virtual void Unk_Slot8(); virtual void Unk_Slot9(); virtual void Unk_Slot10(); virtual void Unk_Slot11();
    virtual void Unk_Slot12(); virtual void Unk_Slot13(); virtual void Unk_Slot14(); virtual void Unk_Slot15();
    virtual void Unk_Slot16(); virtual void Unk_Slot17();
    virtual Unk_StreamPoint vfunc_18();                     // 0x90 the position
};
void* FUN_1416625b0(Unk_GcPC* pPC);
class Unk_GcCore { public: Unk_StreamPoint FUN_1410aa520(); };   // the cube-craft core: its position
Unk_GcCore* FUN_141530290(Unk_GcPC* pPC);                   // the cube-craft core of the player
int FUN_14166c930(Unk_GcPC* pPC);                           // the action id

// The class-object factory registrar (0x140316aa0, commonfiles\dungeonmissiondata.cpp); the factories not defined here belong
// to the other guide-condition code units.
void FUN_140316aa0(void* pSlot, CStringW strName, ClassObject* (*pfnFactory)());
ClassObject* FUN_1413a6010();
ClassObject* FUN_1413af980();
ClassObject* FUN_1413a8900();
ClassObject* FUN_1413a8370();
ClassObject* FUN_1413a9320();
ClassObject* FUN_1413aac80();
ClassObject* FUN_1413a58e0();
ClassObject* FUN_1413a9bc0();

// The initialized marker: no storage, so the dynamic initializer is the registration call and nothing else.
struct Unk_RegMarker {};

#ifndef MS2_HOOK_DLL   // registers into the exe's ClassObject registrar at DllInit time, before the exe's CRT/locks exist
// @0x1400f3420
static char s_regDialog;
static Unk_RegMarker s_initDialog =
    (FUN_140316aa0(&s_regDialog, CStringW(L"CGuideConditionDialog"), FUN_1413a6010), Unk_RegMarker());

// @0x1400f3470
static char s_regEnterDungeon;
static Unk_RegMarker s_initEnterDungeon =
    (FUN_140316aa0(&s_regEnterDungeon, CStringW(L"CGuideConditionEnterDungeon"), FUN_1413af980), Unk_RegMarker());

// @0x1400f34c0
static char s_regEquipItem;
static Unk_RegMarker s_initEquipItem =
    (FUN_140316aa0(&s_regEquipItem, CStringW(L"CGuideConditionEquipItem"), FUN_1413a8900), Unk_RegMarker());

// @0x1400f3510
static char s_regEquipSkill;
static Unk_RegMarker s_initEquipSkill =
    (FUN_140316aa0(&s_regEquipSkill, CStringW(L"CGuideConditionEquipSkill"), FUN_1413a8370), Unk_RegMarker());

// @0x1400f3560
static char s_regExistItem;
static Unk_RegMarker s_initExistItem =
    (FUN_140316aa0(&s_regExistItem, CStringW(L"CGuideConditionExistItem"), FUN_1413a9320), Unk_RegMarker());

// @0x1400f35b0
static char s_regExistShortcut;
static Unk_RegMarker s_initExistShortcut =
    (FUN_140316aa0(&s_regExistShortcut, CStringW(L"CGuideConditionExistShortcut"), FUN_1413aac80), Unk_RegMarker());

// @0x1400f3600
static char s_regFalse;
static Unk_RegMarker s_initFalse =
    (FUN_140316aa0(&s_regFalse, CStringW(L"CGuideConditionFalse"), FUN_1413a58e0), Unk_RegMarker());

// @0x1400f3650
static char s_regFieldId;
static Unk_RegMarker s_initFieldId =
    (FUN_140316aa0(&s_regFieldId, CStringW(L"CGuideConditionFieldId"), FUN_1413a9bc0), Unk_RegMarker());
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
void CGuideConditionPosition::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    for (Unk_140165cf0* pCube = pElem->FUN_140165cf0("cube"); pCube != 0; pCube = pCube->FUN_140168650("cube"))
    {
        float fRange = 75.0f;
        FUN_140873360(pCube, "range", fRange);
        CString strPos = FUN_14015f710(pCube, "pos", CString(""));
        ATL::CAtlArray<float> arrPos;
        XmlSplit(strPos, arrPos, ",");
        if (arrPos.GetCount() == 3)
        {
            Unk_GuideCube cube;
            cube.x = arrPos[0];
            cube.y = arrPos[1];
            cube.z = arrPos[2];
            cube.fRange = fRange;
            m_arrCube.Add(cube);
        }
    }
}
MS2_REPLACE_METHOD(0x1413A6F30, CGuideConditionPosition, vfunc_2, 412, 0x35406215);

// @0x1413a70e0
int CGuideConditionPosition::vfunc_3()
{
    Unk_GcPC* pPC = (Unk_GcPC*)FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    Unk_StreamPoint pos = pPC->vfunc_18();
    if (FUN_1416625b0(pPC) != 0 && FUN_141530290(pPC) != 0)
        pos = FUN_141530290(pPC)->FUN_1410aa520();
    for (size_t i = 0; i < m_arrCube.GetCount(); i++)
    {
        float fDist = pos.FUN_140965c40(m_arrCube.GetAt(i)).FUN_140967ac0();
        if (fDist < m_arrCube.GetAt(i).fRange)
            return FUN_1413a55a0(1);
    }
    return FUN_1413a55a0(0);
}
MS2_REPLACE_METHOD(0x1413A70E0, CGuideConditionPosition, vfunc_3, 307, 0xD9D4F299);

// @0x1413a7220
// MS2-FUNCTIONAL: the exe loads the first StringFormat argument (r8) before the stack arguments; same call sequence otherwise
CStringW CGuideConditionPosition::vfunc_7()
{
    CStringW strCubes;
    for (unsigned i = 0; i < m_arrCube.GetCount(); i++)
    {
        Unk_GuideCube& rPos = m_arrCube.GetAt(i);
        strCubes.Append(StringFormat(L"[Pos:({0},{1},{2}),Range:{3}]", rPos.x, rPos.y, rPos.z, m_arrCube.GetAt(i).fRange));
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
    Unk_GcPC* pPC = (Unk_GcPC*)FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    return FUN_1413a55a0(FUN_14166c930(pPC) == m_n20);
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
    Unk_GcPC* pPC = (Unk_GcPC*)FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    CInteractObject* pObject = FUN_1403ed2d0()->FUN_141bc6090(pPC->vfunc_18(), 1);
    if (pObject == 0)
        return 0;
    if (pObject->vfunc_7() == 0)
        return FUN_1413a55a0(0);
    if (pObject->FUN_1413fdfc0() == 0)
        return FUN_1413a55a0(0);
    if (pObject->FUN_1413fde40() == 0)
        return FUN_1413a55a0(0);
    if (pObject->FUN_1413fe220() == 0)
        return FUN_1413a55a0(0);
    if (pObject->FUN_1413fdd80() == 0)
        return FUN_1413a55a0(0);
    return FUN_1413a55a0(1);
}
MS2_REPLACE_METHOD(0x1413A7570, CGuideConditionInteractable, vfunc_3, 374, 0x026F4DDB);
