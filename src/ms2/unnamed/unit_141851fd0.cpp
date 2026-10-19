// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CU name unknown: recursive Gamebryo scene-graph walkers that
// apply a per-controller operation (set time scale / read the longest controller / restart) to every node under a root.
// MS2-UNIT: unit_141851fd0
// MS2-RANGE: 0x141851fd0-0x1418529d0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\unknown_141851fd0.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "hook/ms2hook.h"

// ---- exe callees (types unrecovered; same helpers nifanimationcontroller.cpp uses) ----
void* FUN_14098dc80(void* pObj);                    // first controller of the object
void* FUN_14098de40(void* pCtrl);                   // next controller
char FUN_14098df90(const void* pRtti, void* pObj);  // IsKindOf
void* FUN_14127cc40(void* pObj);                    // property list
void* FUN_14098ddb0(void* pList);                   // list begin position
void* FUN_14098de00(void* pList, void** ppPos);     // slot at position, advances it
void* FUN_140993f00(void* pSlot);                   // slot -> property
unsigned int FUN_14098daf0(void* pObj);             // child count
void* FUN_14098db40(void* pObj, unsigned int i);    // child at
void* FUN_1413fc1d0(void* pObj);                    // child array
void* FUN_1413fc1f0(void* pArr);                    // array begin position
char FUN_141546cb0(void* pList);
char FUN_141546c80(void* pArr);
void* FUN_141546aa0(void* pArr, void** ppPos);      // element at position, advances it
float FUN_140af7f50(void* pCtrl);                   // controller end time
void FUN_14098e870(void* pCtrl, int nValue);
void FUN_14098e9e0(void* pCtrl, float fValue);   // exe takes the value in xmm1
void FUN_1416f18b0(void* pCtrl, unsigned int uValue);
void* FUN_14086d260();
float FUN_141473280(void* pHandle);
extern char DAT_143af8940;                          // NiRTTI: controller kind
extern char DAT_143afa458;                          // NiRTTI: NiAVObject
extern char DAT_143afa4d8;                          // NiRTTI: NiNode

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
    virtual char vfunc_22();  // MS2: slot 22 (0xb0) is the controller usable
};

// Small value holders (the exe builds them in 24-byte locals; names invented).
struct Unk_CtrlValue
{
    unsigned int m_uValue;
    Unk_CtrlValue(unsigned int uValue);     // 0x1418528d0
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
void FUN_141851fd0(void* pRoot, unsigned int uValue)
{
    Unk_CtrlValue kValue(uValue);
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
    if (pRoot != 0)
    {
        for (void* pCtrl = FUN_14098dc80(pRoot); pCtrl != 0; pCtrl = FUN_14098de40(pCtrl))
        {
            char cIsCtrl = FUN_14098df90(&DAT_143af8940, pCtrl);
            if (cIsCtrl != '\0')
                FUN_141852970(pArg, pCtrl);
        }
        char cIsNode = FUN_14098df90(&DAT_143afa458, pRoot);
        if (cIsNode != '\0')
        {
            void* pList = FUN_14127cc40(pRoot);
            void* pPos = FUN_14098ddb0(pList);
            while (pList != 0 && FUN_141546cb0(pList) == '\0' && pPos != 0)
            {
                void* pSlot = FUN_14098de00(pList, &pPos);
                void* pProp = FUN_140993f00(pSlot);
                if (pProp != 0)
                    FUN_141852690(pProp, pArg);
            }
        }
        char cIsGroup = FUN_14098df90(&DAT_143afa4d8, pRoot);
        if (cIsGroup != '\0')
        {
            for (unsigned int i = 0; i < FUN_14098daf0(pRoot); ++i)
            {
                void* pChild = FUN_14098db40(pRoot, i);
                FUN_141852690(pChild, pArg);
            }
            void* pArr = FUN_1413fc1d0(pRoot);
            void* pIter = FUN_1413fc1f0(pArr);
            while (pArr != 0 && FUN_141546c80(pArr) == '\0' && pIter != 0)
            {
                void** ppChild = (void**)FUN_141546aa0(pArr, &pIter);
                void* pChild = *ppChild;
                if (pChild != 0)
                    FUN_141852690(pChild, pArg);
            }
        }
    }
}

// @0x141852290
void FUN_141852290(void* pRoot, Unk_CtrlMax* pArg)
{
    if (pRoot != 0)
    {
        for (void* pCtrl = FUN_14098dc80(pRoot); pCtrl != 0; pCtrl = FUN_14098de40(pCtrl))
        {
            FUN_1418528f0(pArg, pCtrl);
        }
        char cIsNode = FUN_14098df90(&DAT_143afa458, pRoot);
        if (cIsNode != '\0')
        {
            void* pList = FUN_14127cc40(pRoot);
            void* pPos = FUN_14098ddb0(pList);
            while (pList != 0 && FUN_141546cb0(pList) == '\0' && pPos != 0)
            {
                void* pSlot = FUN_14098de00(pList, &pPos);
                void* pProp = FUN_140993f00(pSlot);
                if (pProp != 0)
                    FUN_141852290(pProp, pArg);
            }
        }
        char cIsGroup = FUN_14098df90(&DAT_143afa4d8, pRoot);
        if (cIsGroup != '\0')
        {
            for (unsigned int i = 0; i < FUN_14098daf0(pRoot); ++i)
            {
                void* pChild = FUN_14098db40(pRoot, i);
                FUN_141852290(pChild, pArg);
            }
            void* pArr = FUN_1413fc1d0(pRoot);
            void* pIter = FUN_1413fc1f0(pArr);
            while (pArr != 0 && FUN_141546c80(pArr) == '\0' && pIter != 0)
            {
                void** ppChild = (void**)FUN_141546aa0(pArr, &pIter);
                void* pChild = *ppChild;
                if (pChild != 0)
                    FUN_141852290(pChild, pArg);
            }
        }
    }
}

// @0x141852490
void FUN_141852490(void* pRoot, Unk_CtrlValueB* pArg)
{
    if (pRoot != 0)
    {
        for (void* pCtrl = FUN_14098dc80(pRoot); pCtrl != 0; pCtrl = FUN_14098de40(pCtrl))
        {
            FUN_141852930(pArg, pCtrl);
        }
        char cIsNode = FUN_14098df90(&DAT_143afa458, pRoot);
        if (cIsNode != '\0')
        {
            void* pList = FUN_14127cc40(pRoot);
            void* pPos = FUN_14098ddb0(pList);
            while (pList != 0 && FUN_141546cb0(pList) == '\0' && pPos != 0)
            {
                void* pSlot = FUN_14098de00(pList, &pPos);
                void* pProp = FUN_140993f00(pSlot);
                if (pProp != 0)
                    FUN_141852490(pProp, pArg);
            }
        }
        char cIsGroup = FUN_14098df90(&DAT_143afa4d8, pRoot);
        if (cIsGroup != '\0')
        {
            for (unsigned int i = 0; i < FUN_14098daf0(pRoot); ++i)
            {
                void* pChild = FUN_14098db40(pRoot, i);
                FUN_141852490(pChild, pArg);
            }
            void* pArr = FUN_1413fc1d0(pRoot);
            void* pIter = FUN_1413fc1f0(pArr);
            while (pArr != 0 && FUN_141546c80(pArr) == '\0' && pIter != 0)
            {
                void** ppChild = (void**)FUN_141546aa0(pArr, &pIter);
                void* pChild = *ppChild;
                if (pChild != 0)
                    FUN_141852490(pChild, pArg);
            }
        }
    }
}

// @0x141852690
void FUN_141852690(void* pRoot, Unk_CtrlValue* pArg)
{
    if (pRoot != 0)
    {
        for (void* pCtrl = FUN_14098dc80(pRoot); pCtrl != 0; pCtrl = FUN_14098de40(pCtrl))
        {
            FUN_141852970(pArg, pCtrl);
        }
        char cIsNode = FUN_14098df90(&DAT_143afa458, pRoot);
        if (cIsNode != '\0')
        {
            void* pList = FUN_14127cc40(pRoot);
            void* pPos = FUN_14098ddb0(pList);
            while (pList != 0 && FUN_141546cb0(pList) == '\0' && pPos != 0)
            {
                void* pSlot = FUN_14098de00(pList, &pPos);
                void* pProp = FUN_140993f00(pSlot);
                if (pProp != 0)
                    FUN_141852690(pProp, pArg);
            }
        }
        char cIsGroup = FUN_14098df90(&DAT_143afa4d8, pRoot);
        if (cIsGroup != '\0')
        {
            for (unsigned int i = 0; i < FUN_14098daf0(pRoot); ++i)
            {
                void* pChild = FUN_14098db40(pRoot, i);
                FUN_141852690(pChild, pArg);
            }
            void* pArr = FUN_1413fc1d0(pRoot);
            void* pIter = FUN_1413fc1f0(pArr);
            while (pArr != 0 && FUN_141546c80(pArr) == '\0' && pIter != 0)
            {
                void** ppChild = (void**)FUN_141546aa0(pArr, &pIter);
                void* pChild = *ppChild;
                if (pChild != 0)
                    FUN_141852690(pChild, pArg);
            }
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
Unk_CtrlValue::Unk_CtrlValue(unsigned int uValue)
{
    m_uValue = uValue;
}

// @0x1418528f0
void FUN_1418528f0(Unk_CtrlMax* pMax, void* pCtrl)
{
    float fEnd = FUN_140af7f50(pCtrl);
    if (pMax->m_fValue < fEnd)
    {
        fEnd = FUN_140af7f50(pCtrl);
        pMax->m_fValue = fEnd;
    }
}

// @0x141852930
void FUN_141852930(Unk_CtrlValueB* pArg, void* pCtrl)
{
    char cUsable = ((Unk_CtrlIface*)pCtrl)->vfunc_22();
    if (cUsable != '\0')
        FUN_1416f18b0(pCtrl, pArg->m_uValue);
}

// @0x141852970
void FUN_141852970(Unk_CtrlValue* pArg, void* pCtrl)
{
    FUN_14098e870(pCtrl, 1);
    void* pHandle = FUN_14086d260();
    float fScale = FUN_141473280(pHandle);
    ((Unk_CtrlIface*)pCtrl)->vfunc_18(fScale);
    FUN_14098e9e0(pCtrl, *reinterpret_cast<const float*>(&pArg->m_uValue));
}
