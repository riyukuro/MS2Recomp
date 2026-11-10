// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CU name unknown: recursive Gamebryo scene-graph walkers that
// apply a per-controller operation (set time scale / read the longest controller / restart) to every node under a root.
// MS2-UNIT: unit_141851fd0
// MS2-RANGE: 0x141851fd0-0x1418529d0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\unknown_141851fd0.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cmainsystem.h"

// ---- exe callees (types unrecovered; same helpers nifanimationcontroller.cpp uses) ----
class NiObjectNET   // C3: member view for the former free stand-ins
{
public:
    class NiTimeController* GetControllers() const;
};
class NiTimeController   // C3: member view for the former free stand-ins
{
public:
    float GetEndKeyTime() const;
    class NiTimeController* GetNext() const;
    void SetPhase(float);
    enum CycleType { LOOP, REVERSE, CLAMP };
    void SetCycleType(CycleType eType);
    enum AnimType { APP_TIME, APP_INIT };
    void SetAnimType(AnimType eType);
};
#include <NiTPointerList.h>
#include <NiRefObject.h>
class NiProperty : public NiRefObject {};   // C3: view (real base NiObject); SmartPointer needs it complete
class NiDynamicEffect;
class NiObject   // C3: member view for the former free stand-ins
{
public:
    static bool IsKindOf(class NiRTTI const*, class NiObject const*);
};
class NiNode   // C3: member view for the former free stand-ins
{
public:
    static const class NiRTTI ms_RTTI;
    unsigned int GetArrayCount() const;
    class NiAVObject* GetAt(unsigned int) const;
    const NiTPointerList<NiDynamicEffect*>& GetEffectList() const;
};
class NiAVObject
{
public:
    static const class NiRTTI ms_RTTI;
    NiTPointerList<efd::SmartPointer<NiProperty> >& GetPropertyList();
};
class NiAlphaController
{
public:
    static const class NiRTTI ms_RTTI;
};

// Controller interface with the two virtual slots used here (the slots in between are unrecovered).
struct Unk_CtrlIface
{
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18(float fValue);  // MS2: slot 18 (0x90) set time scale
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual bool vfunc_22();  // MS2: slot 22 (0xb0) is the controller usable
};

// Small value holders (the exe builds them in 24-byte locals; names invented).
struct Unk_CtrlValue
{
    float m_fValue;
    Unk_CtrlValue(float fValue);            // 0x1418528d0
};
struct Unk_CtrlValueB
{
    unsigned int m_uValue;
    Unk_CtrlValueB(unsigned int uValue);    // 0x1418528b0
};
struct Unk_CtrlMax
{
    float m_fValue;
    Unk_CtrlMax();                          // 0x141852890
};

void FUN_141852080(void* pRoot, Unk_CtrlValue* pArg);
void FUN_141852290(void* pRoot, Unk_CtrlMax* pArg);
void FUN_141852490(void* pRoot, Unk_CtrlValueB* pArg);
void FUN_141852690(void* pRoot, Unk_CtrlValue* pArg);
void FUN_1418528f0(Unk_CtrlMax* pMax, void* pCtrl);
void FUN_141852930(Unk_CtrlValueB* pArg, void* pCtrl);
void FUN_141852970(Unk_CtrlValue* pArg, void* pCtrl);

// @0x141851fd0
void FUN_141851fd0(void* pRoot, float fValue)
{
    Unk_CtrlValue kValue(fValue);
    FUN_141852080(pRoot, &kValue);
}

// @0x141852010
float FUN_141852010(void* pRoot)
{
    Unk_CtrlMax kMax;
    FUN_141852290(pRoot, &kMax);
    return kMax.m_fValue;
}

// @0x141852050
void FUN_141852050(void* pRoot, unsigned int uValue)
{
    Unk_CtrlValueB kValue(uValue);
    FUN_141852490(pRoot, &kValue);
}

// @0x141852080
void FUN_141852080(void* pRoot, Unk_CtrlValue* pArg)
{
    if (pRoot == 0)
        return;
    void* pCtrl = ((void*)((class NiObjectNET*)(void*)(pRoot))->GetControllers());
    while (pCtrl != 0)
    {
        if (NiObject::IsKindOf(&NiAlphaController::ms_RTTI, (class NiObject const*)(pCtrl)))
            FUN_141852970(pArg, pCtrl);
        pCtrl = ((void*)((class NiTimeController*)(void*)(pCtrl))->GetNext());
    }
    if (NiObject::IsKindOf(&NiAVObject::ms_RTTI, (class NiObject const*)(pRoot)))
    {
        void* pObj = pRoot;
        void* pList = (void*)&reinterpret_cast<NiAVObject*>(pObj)->GetPropertyList();
        void* pPos = ((NiTPointerList<efd::SmartPointer<NiProperty> >*)pList)->GetHeadPos();
        while (pList != 0 && !((NiTPointerList<efd::SmartPointer<NiProperty> >*)pList)->IsEmpty() && pPos != 0)
        {
            void* pProp = (NiProperty*)((NiTPointerList<efd::SmartPointer<NiProperty> >*)pList)->GetNext(pPos);
            if (pProp != 0)
                FUN_141852690(pProp, pArg);
        }
    }
    if (NiObject::IsKindOf(&NiNode::ms_RTTI, (class NiObject const*)(pRoot)))
    {
        void* pNode = pRoot;
        for (unsigned int i = 0; i < ((class NiNode*)(void*)(pNode))->GetArrayCount(); ++i)
        {
            void* pChild = ((void*)((class NiNode*)(void*)(pNode))->GetAt(i));
            FUN_141852690(pChild, pArg);
        }
        void* pArr = (void*)&reinterpret_cast<NiNode*>(pNode)->GetEffectList();
        void* pIter = ((NiTPointerList<NiDynamicEffect*>*)pArr)->GetHeadPos();
        while (pArr != 0 && !((NiTPointerList<NiDynamicEffect*>*)pArr)->IsEmpty() && pIter != 0)
        {
            void* pChild = ((NiTPointerList<NiDynamicEffect*>*)pArr)->GetNext(pIter);
            if (pChild != 0)
                FUN_141852690(pChild, pArg);
        }
    }
}

// @0x141852290
void FUN_141852290(void* pRoot, Unk_CtrlMax* pArg)
{
    if (pRoot == 0)
        return;
    void* pCtrl = ((void*)((class NiObjectNET*)(void*)(pRoot))->GetControllers());
    while (pCtrl != 0)
    {
        FUN_1418528f0(pArg, pCtrl);
        pCtrl = ((void*)((class NiTimeController*)(void*)(pCtrl))->GetNext());
    }
    if (NiObject::IsKindOf(&NiAVObject::ms_RTTI, (class NiObject const*)(pRoot)))
    {
        void* pObj = pRoot;
        void* pList = (void*)&reinterpret_cast<NiAVObject*>(pObj)->GetPropertyList();
        void* pPos = ((NiTPointerList<efd::SmartPointer<NiProperty> >*)pList)->GetHeadPos();
        while (pList != 0 && !((NiTPointerList<efd::SmartPointer<NiProperty> >*)pList)->IsEmpty() && pPos != 0)
        {
            void* pProp = (NiProperty*)((NiTPointerList<efd::SmartPointer<NiProperty> >*)pList)->GetNext(pPos);
            if (pProp != 0)
                FUN_141852290(pProp, pArg);
        }
    }
    if (NiObject::IsKindOf(&NiNode::ms_RTTI, (class NiObject const*)(pRoot)))
    {
        void* pNode = pRoot;
        for (unsigned int i = 0; i < ((class NiNode*)(void*)(pNode))->GetArrayCount(); ++i)
        {
            void* pChild = ((void*)((class NiNode*)(void*)(pNode))->GetAt(i));
            FUN_141852290(pChild, pArg);
        }
        void* pArr = (void*)&reinterpret_cast<NiNode*>(pNode)->GetEffectList();
        void* pIter = ((NiTPointerList<NiDynamicEffect*>*)pArr)->GetHeadPos();
        while (pArr != 0 && !((NiTPointerList<NiDynamicEffect*>*)pArr)->IsEmpty() && pIter != 0)
        {
            void* pChild = ((NiTPointerList<NiDynamicEffect*>*)pArr)->GetNext(pIter);
            if (pChild != 0)
                FUN_141852290(pChild, pArg);
        }
    }
}

// @0x141852490
void FUN_141852490(void* pRoot, Unk_CtrlValueB* pArg)
{
    if (pRoot == 0)
        return;
    void* pCtrl = ((void*)((class NiObjectNET*)(void*)(pRoot))->GetControllers());
    while (pCtrl != 0)
    {
        FUN_141852930(pArg, pCtrl);
        pCtrl = ((void*)((class NiTimeController*)(void*)(pCtrl))->GetNext());
    }
    if (NiObject::IsKindOf(&NiAVObject::ms_RTTI, (class NiObject const*)(pRoot)))
    {
        void* pObj = pRoot;
        void* pList = (void*)&reinterpret_cast<NiAVObject*>(pObj)->GetPropertyList();
        void* pPos = ((NiTPointerList<efd::SmartPointer<NiProperty> >*)pList)->GetHeadPos();
        while (pList != 0 && !((NiTPointerList<efd::SmartPointer<NiProperty> >*)pList)->IsEmpty() && pPos != 0)
        {
            void* pProp = (NiProperty*)((NiTPointerList<efd::SmartPointer<NiProperty> >*)pList)->GetNext(pPos);
            if (pProp != 0)
                FUN_141852490(pProp, pArg);
        }
    }
    if (NiObject::IsKindOf(&NiNode::ms_RTTI, (class NiObject const*)(pRoot)))
    {
        void* pNode = pRoot;
        for (unsigned int i = 0; i < ((class NiNode*)(void*)(pNode))->GetArrayCount(); ++i)
        {
            void* pChild = ((void*)((class NiNode*)(void*)(pNode))->GetAt(i));
            FUN_141852490(pChild, pArg);
        }
        void* pArr = (void*)&reinterpret_cast<NiNode*>(pNode)->GetEffectList();
        void* pIter = ((NiTPointerList<NiDynamicEffect*>*)pArr)->GetHeadPos();
        while (pArr != 0 && !((NiTPointerList<NiDynamicEffect*>*)pArr)->IsEmpty() && pIter != 0)
        {
            void* pChild = ((NiTPointerList<NiDynamicEffect*>*)pArr)->GetNext(pIter);
            if (pChild != 0)
                FUN_141852490(pChild, pArg);
        }
    }
}

// @0x141852690
void FUN_141852690(void* pRoot, Unk_CtrlValue* pArg)
{
    if (pRoot == 0)
        return;
    void* pCtrl = ((void*)((class NiObjectNET*)(void*)(pRoot))->GetControllers());
    while (pCtrl != 0)
    {
        FUN_141852970(pArg, pCtrl);
        pCtrl = ((void*)((class NiTimeController*)(void*)(pCtrl))->GetNext());
    }
    if (NiObject::IsKindOf(&NiAVObject::ms_RTTI, (class NiObject const*)(pRoot)))
    {
        void* pObj = pRoot;
        void* pList = (void*)&reinterpret_cast<NiAVObject*>(pObj)->GetPropertyList();
        void* pPos = ((NiTPointerList<efd::SmartPointer<NiProperty> >*)pList)->GetHeadPos();
        while (pList != 0 && !((NiTPointerList<efd::SmartPointer<NiProperty> >*)pList)->IsEmpty() && pPos != 0)
        {
            void* pProp = (NiProperty*)((NiTPointerList<efd::SmartPointer<NiProperty> >*)pList)->GetNext(pPos);
            if (pProp != 0)
                FUN_141852690(pProp, pArg);
        }
    }
    if (NiObject::IsKindOf(&NiNode::ms_RTTI, (class NiObject const*)(pRoot)))
    {
        void* pNode = pRoot;
        for (unsigned int i = 0; i < ((class NiNode*)(void*)(pNode))->GetArrayCount(); ++i)
        {
            void* pChild = ((void*)((class NiNode*)(void*)(pNode))->GetAt(i));
            FUN_141852690(pChild, pArg);
        }
        void* pArr = (void*)&reinterpret_cast<NiNode*>(pNode)->GetEffectList();
        void* pIter = ((NiTPointerList<NiDynamicEffect*>*)pArr)->GetHeadPos();
        while (pArr != 0 && !((NiTPointerList<NiDynamicEffect*>*)pArr)->IsEmpty() && pIter != 0)
        {
            void* pChild = ((NiTPointerList<NiDynamicEffect*>*)pArr)->GetNext(pIter);
            if (pChild != 0)
                FUN_141852690(pChild, pArg);
        }
    }
}

// @0x141852890
Unk_CtrlMax::Unk_CtrlMax()
{
    m_fValue = 0;
}

// @0x1418528b0
Unk_CtrlValueB::Unk_CtrlValueB(unsigned int uValue)
{
    m_uValue = uValue;
}

// @0x1418528d0
Unk_CtrlValue::Unk_CtrlValue(float fValue)
{
    m_fValue = fValue;
}

// @0x1418528f0
void FUN_1418528f0(Unk_CtrlMax* pMax, void* pCtrl)
{
    if (((class NiTimeController*)(void*)(pCtrl))->GetEndKeyTime() > pMax->m_fValue)
        pMax->m_fValue = ((class NiTimeController*)(void*)(pCtrl))->GetEndKeyTime();
}

// @0x141852930
void FUN_141852930(Unk_CtrlValueB* pArg, void* pCtrl)
{
    if (((Unk_CtrlIface*)pCtrl)->vfunc_22())
        ((NiTimeController*)pCtrl)->SetCycleType((NiTimeController::CycleType)pArg->m_uValue);
}

// @0x141852970
void FUN_141852970(Unk_CtrlValue* pArg, void* pCtrl)
{
    ((NiTimeController*)pCtrl)->SetAnimType(NiTimeController::APP_INIT);
    ((Unk_CtrlIface*)pCtrl)->vfunc_18((float)TSingleton<CMainSystem>::GetInstance()->GetGameTime());
    ((class NiTimeController*)(void*)(pCtrl))->SetPhase(pArg->m_fValue);
}
