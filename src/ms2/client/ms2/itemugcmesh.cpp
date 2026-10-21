// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CItemUgcMesh / CItemUgcMeshContainer and the item-model
// helpers of the customize / UGC texture code (name builders, customize values, model pose, decal maps, colour slots).
// MS2-UNIT: ?\itemugcmesh.cpp
// MS2-RANGE: 0x141421ab0-0x1414286a0 .text$mn
// MS2-RANGE: 0x1400f6bf0-0x1400f6ce0 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?_Lmost@?$_Tree_val@U?$_Tree_simple_types@V?$SmartPointer@VNiAVObject@@@efd@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@V?$SmartPointer@VNiAVObject@@@efd@@PEAX@2@XZ 0x141427760 ; order
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVCItemExtraData@@P81@EAA_NAEBVItemColorEx@@V?$MS2Ptr@VCItemData@@@@@Z@std@@@?$Delegate@$$A6A_NAEBVItemColorEx@@V?$MS2Ptr@VCItemData@@@@@Z@@UEAA_NAEBVItemColorEx@@V?$MS2Ptr@VCItemData@@@@@Z 0x1414283c0 ; unique
// MS2-PIN: ??$Call@VCItemExtraData@@P81@EAA_NAEBVItemColorEx@@V?$MS2Ptr@VCItemData@@@@@Z@?$DelegateImpl@U?$pair@PEAVCItemExtraData@@P81@EAA_NAEBVItemColorEx@@V?$MS2Ptr@VCItemData@@@@@Z@std@@@?$Delegate@$$A6A_NAEBVItemColorEx@@V?$MS2Ptr@VCItemData@@@@@Z@@CA_NAEAU?$pair@PEAVCItemExtraData@@P81@EAA_NAEBVItemColorEx@@V?$MS2Ptr@VCItemData@@@@@Z@std@@AEBVItemColorEx@@V?$MS2Ptr@VCItemData@@@@@Z 0x141428430 ; unique
// MS2-PIN: ??0?$SmartPointer@VNiTexture@@@efd@@QEAA@PEAVNiTexture@@@Z 0x141427330 ; manual
// MS2-PIN: ??1?$SmartPointer@VNiTexture@@@efd@@QEAA@XZ 0x1414275c0 ; manual
// MS2-PIN: ??8?$MS2Ptr@VCItem@@@@QEBA_NPEAVCItem@@@Z 0x1414276c0 ; manual
// MS2-PIN: ??B?$SmartPointer@VNiTexture@@@efd@@QEBAPEAVNiTexture@@XZ 0x141427740 ; manual
// MS2-PIN: ??C?$MS2Ptr@VCItem@@@@QEBAPEAVCItem@@XZ 0x141427750 ; manual
// MS2-PIN: ?GetCount@?$CAtlArray@V?$MS2Ptr@UUnk_PickTarget@@@@V?$CElementTraits@V?$MS2Ptr@UUnk_PickTarget@@@@@ATL@@@ATL@@QEBA_KXZ 0x141427770 ; manual
// MS2-PIN: ??A?$CAtlArray@V?$MS2Ptr@VCItemUgcMesh@@@@V?$CElementTraits@V?$MS2Ptr@VCItemUgcMesh@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@VCItemUgcMesh@@@@_K@Z 0x141427a10 ; manual
// MS2-PIN: ??_GCItemUgcMesh@@UEAAPEAXI@Z 0x141427800 ; manual
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCItemUgcMesh@@@@AEBAXPEAX@Z 0x1414280a0 ; manual
// MS2-PIN: ?IsNull@?$MS2Ptr@VCItem@@@@QEBA_NXZ 0x141427d30 ; manual
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVCItemExtraData@@P81@EAA_NAEBVItemColorEx@@V?$MS2Ptr@VCItemData@@@@@Z@std@@@?$Delegate@$$A6A_NAEBVItemColorEx@@V?$MS2Ptr@VCItemData@@@@@Z@@UEAAPEAXI@Z 0x1414277c0 ; manual
// MS2-PIN: ??_GDelegateImplBase@?$Delegate@$$A6A_NAEBVItemColorEx@@V?$MS2Ptr@VCItemData@@@@@Z@@UEAAPEAXI@Z 0x141427840 ; manual
// MS2-PIN: ??_7DelegateImplBase@?$Delegate@$$A6A_NAEBVItemColorEx@@V?$MS2Ptr@VCItemData@@@@@Z@@6B@ 0x142F11A08 ; manual
// MS2-PIN: ??_7?$DelegateImpl@U?$pair@PEAVCItemExtraData@@P81@EAA_NAEBVItemColorEx@@V?$MS2Ptr@VCItemData@@@@@Z@std@@@?$Delegate@$$A6A_NAEBVItemColorEx@@V?$MS2Ptr@VCItemData@@@@@Z@@6B@ 0x142f11a30 ; manual
// MS2-PIN: ??1?$vector@V?$MS2Ptr@VCItemData@@@@V?$allocator@V?$MS2Ptr@VCItemData@@@@@std@@@std@@QEAA@XZ 0x1414275f0 ; manual
// MS2-PIN: ?_Tidy@?$vector@V?$MS2Ptr@VCItemData@@@@V?$allocator@V?$MS2Ptr@VCItemData@@@@@std@@@std@@AEAAXXZ 0x141428110 ; manual
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\itemugcmesh.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "itemugcmesh.h"
#include "itempickinghelper.h"
#include <map>
#include <vector>
#include <set>
#include <NiNode.h>
#include <NiMesh.h>
#include <NiSkinningMeshModifier.h>
#include <NiTexturingProperty.h>
#include <NiSourceTexture.h>
#include <NiSPWorkflowManager.h>
#include <NiCollisionTraversals.h>
#include <NiPick.h>
#include <NiFixedString.h>
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemextradata.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- statics (.text$di) ----

static CString s_strShopItemSell("shop_itemsell");
static CString s_aStrUgcTab[7] = { CString("None"), CString("Buy"), CString("Like"), CString("PriceLow"),
                                   CString("PriceHigh"), CString("Create"), CString("EnumEnd") };

// ---- out-of-unit callees ----

// The item data of an equip item (CItemData-like; only the kind tests this unit calls).
struct Unk_UgcItemData
{
    bool FUN_14053cfd0();                                           // kind test: has per-part customize floats
    int FUN_14053c620();                                            // item kind id
    bool FUN_14053d070();                                           // kind test: has the second float
    char FUN_14053d020();
    char FUN_14053cf00();                                           // kind test: customize-colour item
    int FUN_14053e260();                                            // item id
    int FUN_14053c5c0();                                            // item kind id
    unsigned FUN_14053dc60();                                       // linked item id
    int FUN_14053ec50();                                            // item category
    unsigned FUN_14053c510();                                       // name string id
    struct Unk_UgcDesc* FUN_14053eba0();                            // description text holder
    unsigned FUN_14053e310(int nIndex);
};

// The equipped item of a model part (CPtred, held in MS2Ptr; ?\equipitem.cpp). Only the members this unit calls.
class CEquipItem : public CPtred
{
public:
    Unk_UgcItemData* FUN_1411dc7f0();                               // the item's data
    MS2Ptr<CItem> FUN_1411dc7a0();                                  // the item object holding the proxy data
    void FUN_1411dd150();
    void FUN_1411dcd00();
    void FUN_1411dca30(int nSlot, CAtlArray<CString>& aParts);      // attach part names of an equip slot
    void FUN_1411dcc80(CAtlArray<MS2Ptr<Unk_PickTarget> >& aParts); // the item's model parts
};

// The proxy data record of an item (CItem::FUN_140527870, a CPtred; ?\\userproxy.cpp). Customize floats are read here.
struct Unk_UgcColorList
{
    bool FUN_141278a50() const;                                     // is empty
    unsigned __int64 FUN_14059d0e0() const;                         // element count
    unsigned* FUN_140ce98c0(unsigned __int64 nIndex) const;         // element
};
struct Unk_UgcExtra
{
    char m_pad[0x18];
    int m_nType;                                                    // +0x18
};
struct Unk_UgcProxy : public CItemExtraData
{
    void FUN_140599d10(const Unk_UgcColorList& kColors, int nIndex);
    void FUN_140599bc0(const Unk_UgcExtra& kExtra, bool bFlag, unsigned nValue, int nIndex);
    void FUN_140599ea0(int nIndex, void* pColor, int nValue);
    void FUN_140599ab0(Unk_UgcItemData* pData);
    int FUN_140599fd0(int nIndex);
    float m_afValue[3];                                             // +0x58 customize values (index 0/1, +0x60 for kind 2)
    char m_pad64[0x74 - 0x64];
    NiPoint3 m_aPose[4];                                            // +0x74 pose point per part index, euler at index + 1
};

// The facts of a model part: +0x118 renames part-name suffixes, +0x48 the pose slot.
struct Unk_UgcPartInfo
{
    char m_pad[0x48];
    int m_nSlot;                                                    // +0x48
    char m_pad4c[0x118 - 0x4c];
    std::map<CString, CString> m_names;                             // +0x118
};

CString FUN_141421740(const CString& strName, int* pnFlag);
CString FUN_1401d2b10(const CString& strLeft, const CString& strRight);    // a + b

// Model-root virtual 18 (look a scene node up by name).
struct Unk_UgcRoot
{
    virtual void vfunc_0();   virtual void vfunc_1();   virtual void vfunc_2();   virtual void vfunc_3();
    virtual void vfunc_4();   virtual void vfunc_5();   virtual void vfunc_6();   virtual void vfunc_7();
    virtual void vfunc_8();   virtual void vfunc_9();   virtual void vfunc_10();  virtual void vfunc_11();
    virtual void vfunc_12();  virtual void vfunc_13();  virtual void vfunc_14();  virtual void vfunc_15();
    virtual void vfunc_16();  virtual void vfunc_17();
    virtual NiAVObject* vfunc_18(const char* szName);
};

// Breadth-first queue of scene-graph nodes (0x30 bytes; alphaanimation.cpp defines the members).
class Unk_NodeQueue
{
public:
    Unk_NodeQueue(NiAVObject* pkRoot);                              // 0x14098cb80
    ~Unk_NodeQueue();                                               // 0x14098cf00
    NiAVObject* Next(bool bAddChildren);                            // 0x14098e0d0
    void SetRoot(NiAVObject* pkRoot);
    void AddChildren(NiNode* pkNode);

private:
    ATL::CAtlList<NiAVObject*> m_list;
};
MS2_CHECK_SIZE(Unk_NodeQueue, 0x30);

void FUN_141422660(MS2Ptr<CEquipItem> spItem, int nIndex, float fValue);
bool FUN_141424580(MS2Ptr<CEquipItem> spItem, unsigned* pOut, int nIndex);
void FUN_141422b30(Unk_PickTarget* pPart, std::set<NiAVObjectPtr>& kNodes, Unk_StreamPoint kPos, Unk_StreamPoint kEuler,
                   float fScale);
NiAVObjectPtr FUN_141423480(NiAVObjectPtr spRoot, const CString& strName);
bool FUN_141427d60(NiAVObject* pObj);                               // the object is a mesh-type leaf
int FUN_140f02bc0();
NiTimeController* FUN_14098dc80(NiObjectNET* pObj);                 // first controller
NiTimeController* FUN_14098de40(NiTimeController* pCtrl);           // next controller
NiObject* FUN_14098d8d0(const NiRTTI* pRTTI, NiObject* p);          // NiObject::DynamicCast
extern NiRTTI DAT_143af8a20;                                        // RTTI of the UGC controller type
extern char DAT_142f10fe4[];                                        // name tails of the model files
extern char DAT_142f10ff0[];
CString FUN_14038f6d0(const CString& strLeft, const char* szRight); // a + literal
void* FUN_1403ed280();                                              // the effect manager
void FUN_1411a4800(const CString& strFile, int nType);              // preload an effect file
char FUN_140998dc0(void* pName, const char* szText);                // string compare with a literal
unsigned FUN_141427ab0(void* pMesh);                                // material count of a mesh
void* FUN_141427ae0(void* pMesh, unsigned nIndex);                  // material slot
void* FUN_140a17de0(void* pSlot);
void* FUN_14106bd50(void* pMaterial);                               // material name

// Rows of the item-colour tables (a 16-byte handle; FUN_14056c2d0 releases it).
struct Unk_UgcRow
{
    char m_pad[0x38];
    int m_nValue;                                                   // +0x38
};
struct Unk_UgcRowPtr
{
    bool FUN_14056cf90(int) const;                                  // == 0
    Unk_UgcRow* FUN_14056d570() const;                              // operator->
    void FUN_14056c2d0();                                           // release
    ~Unk_UgcRowPtr() { FUN_14056c2d0(); }
    void* m_a[2];
};
struct Unk_UgcTable
{
    Unk_UgcRowPtr FUN_140558cc0(int nItemId, __int64 nKey);
    Unk_UgcRowPtr FUN_140558e80(int nItemId, MS2Ptr<CItemData> spData, Delegate<bool(const ItemColorEx&, MS2Ptr<CItemData>)> kFn);
    Unk_UgcRowPtr FUN_1405590e0(int nItemId, unsigned* pColor0, unsigned* pColor1);
};
Unk_UgcTable* FUN_140281980();
void* FUN_14059cf00(Unk_UgcRowPtr* pRow);
MS2Ptr<CItemData> FUN_14053f870(int nItemId);

struct Unk_UgcPlayer;
struct Unk_UgcDesc
{
    void FUN_14054b6e0(CStringW* pOut);                             // the text
};
struct Unk_UgcNames
{
    CStringW FUN_141811980(int nType, unsigned nId);                // string table lookup
};
Unk_UgcNames* FUN_1401a9d70();
struct Unk_UgcRow2
{
    char m_pad[0x18];
    int m_nType;                                                    // +0x18
};
struct Unk_UgcRow2Ptr
{
    bool FUN_14052cde0() const;                                     // is null
    Unk_UgcRow2* FUN_14052ceb0() const;                             // operator->
    void FUN_14052c420();                                           // release
    ~Unk_UgcRow2Ptr() { FUN_14052c420(); }
    void* m_a[2];
};
struct Unk_UgcTable2
{
    Unk_UgcRow2Ptr FUN_1407290f0(unsigned nId);
};
Unk_UgcTable2* FUN_14052d210();
CStringW FUN_14052bd00(int nStringId, CStringW& strArg);
void FUN_1405592e0(Unk_UgcTable* pTable, std::vector<MS2Ptr<CItemData> >* pOut);
void FUN_14054c030(void* pLogger, int nLevel, int nLine, const wchar_t* szFormat, const CString& str1, const CString& str2);
void* FUN_140166440();                                              // the logger
bool FUN_1411c9940(NiAVObject* pObj);                               // object is a node
int FUN_141676b00(Unk_UgcPlayer* pPlayer, __int64 nUid);
void FUN_140710590(COutPacket& kPacket);
extern char DAT_143adc208[];
void FUN_141276180(void* pObj, const CString& strArg);
void FUN_1412750f0(void* pCallback, int nCount, int nA, int nB);
void FUN_1412751b0(const CStringW& strText, int nType);
CStringW FUN_14028b8e0(const CStringW& str);

// The local player (a MyPC) and the world that owns it.
struct Unk_UgcColor
{
    __int64 m_a[4];                                                 // 32-byte colour value
};
void FUN_141b6dea0(Unk_UgcColor* pOut, unsigned nArgb);
unsigned FUN_141b6df90(Unk_UgcColor* pColor);
void* FUN_141b6efc0(void* pEntity);
void FUN_141b6f220(void* pObj, int nSlot, Unk_UgcColor* pColor);
void* FUN_140a6a840();                                              // the avatar-change service
struct Unk_UgcPlayer
{
    void FUN_1416591e0(int nSlot, Unk_UgcColor* pColor);
    void* FUN_14123c410();
    Unk_UgcColor* FUN_141659220(int nSlot);
    unsigned FUN_141658e60();
    MS2Ptr<CEquipItem> FUN_141655c30(__int64 nUid);
};
struct Unk_UgcWorld
{
    Unk_UgcPlayer* FUN_141bd0cc0();
};
Unk_UgcWorld* FUN_1403ed2d0();
#define UGC_VCALL(obj, off, type) ((type)(*(void***)(obj))[(off) / 8])

// ---- item-name builders ----

// @0x141421ab0
// MS2-FUNCTIONAL: logic recovered from the decomp; /Od codegen (local layout / temporaries) still differs from the exe
// name of a part model: the first attach-part name with a style suffix swapped in.
CString FUN_141421ab0(MS2Ptr<CEquipItem> spItem, const CString& strSuffix)
{
    if (spItem == 0)
        return "";
    if (!(strSuffix.GetLength() < 2))
        return "";
    CAtlArray<MS2Ptr<Unk_PickTarget> > aParts;
    spItem->FUN_1411dcc80(aParts);
    if (aParts.IsEmpty())
        return "";
    CAtlArray<CString> aNames;
    spItem->FUN_1411dca30(1, aNames);
    if (aNames.IsEmpty())
        return "";
    CString& strFirst = aNames[0];
    int nFlag = 0;
    FUN_141421740(strFirst, &nFlag);
    CString strMapped(strSuffix);
    Unk_UgcPartInfo* pInfo = (Unk_UgcPartInfo*)aParts[0]->FUN_141200ab0();
    std::map<CString, CString>::iterator it = pInfo->m_names.find(strSuffix);
    if (it != pInfo->m_names.end())
        strMapped = it->second;
    CString strOut;
    strOut = strFirst.Left(1);
    strOut = FUN_1401d2b10(strOut, strMapped);
    strOut = FUN_1401d2b10(strOut, strFirst.Right(strFirst.GetLength() - 1));
    return strOut;
}

// @0x141421f30
// re-targets the skin bones of a mesh to the same-named nodes of another model root.
void FUN_141421f30(NiMesh* pMesh, Unk_UgcRoot* pRoot)
{
    NiSkinningMeshModifier* pMod = (NiSkinningMeshModifier*)pMesh->GetModifierByType(&NiSkinningMeshModifier::ms_RTTI);
    if (pMod == 0)
        return;
    pMod->Detach(pMesh);
    NiFixedString kRootName = pMod->GetRootBoneParent()->GetName();
    NiAVObjectPtr spRoot = pRoot->vfunc_18((const char*)kRootName);
    spRoot.operator->();
    pMod->SetRootBoneParent(spRoot);
    NiAVObject** ppBones = pMod->GetBones();
    unsigned nCount = pMod->GetBoneCount();
    for (unsigned i = 0; i < nCount; i++)
    {
        NiFixedString kName = ppBones[i]->GetName();
        NiAVObject* pBone = pRoot->vfunc_18((const char*)kName);
        if (pBone != 0)
            ppBones[i] = pBone;
    }
    pMod->Attach(pMesh);
}

// @0x141422110
// MS2-FUNCTIONAL: logic recovered from the decomp; /Od codegen (local layout / temporaries) still differs from the exe
// collects the nodes of a model whose name starts with strPrefix into kSet; true when any was found.
unsigned FUN_141422110(NiNode* pRoot, const CString& strPrefix, std::set<NiAVObjectPtr>* pSet)
{
    if (pRoot == 0)
        return 0;
    NiAVObject* pFirst = pRoot->GetObjectByName(NiFixedString((const char*)strPrefix));
    if (pFirst != 0)
        pSet->insert(NiAVObjectPtr(pFirst));
    Unk_NodeQueue kQueue(pRoot);
    NiAVObject* pObject;
    while ((pObject = kQueue.Next(false)) != 0)
    {
        CString strName((const char*)pObject->GetName());
        if (strName.IsEmpty())
            continue;
        if (strName.Find((const char*)strPrefix, 0) == 0)
        {
            pSet->insert(NiAVObjectPtr(pObject));
        }
        else
        {
            NiNode* pNode = NiDynamicCast(NiNode, pObject);
            if (pNode != 0)
                kQueue.AddChildren(pNode);
        }
    }
    return !pSet->empty();
}

// @0x141422340
// MS2-FUNCTIONAL: logic recovered from the decomp; /Od codegen (local layout / temporaries) still differs from the exe
float FUN_141422340(Unk_PickTarget* pPart, int nIndex)
{
    if (pPart == 0)
        return 1.0f;
    MS2Ptr<CEquipItem> spItem = pPart->FUN_141200a40();
    if (spItem.IsNull())
        return 1.0f;
    if (spItem->FUN_1411dc7f0()->FUN_14053cfd0())
    {
        Unk_UgcProxy* pProxy = (Unk_UgcProxy*)spItem->FUN_1411dc7a0()->FUN_140527870();
        if (pProxy != 0)
            return pProxy->m_afValue[nIndex];
    }
    if (spItem->FUN_1411dc7f0()->FUN_14053c620() == 0xd)
    {
        Unk_UgcProxy* pProxy = (Unk_UgcProxy*)spItem->FUN_1411dc7a0()->FUN_140527870();
        if (pProxy != 0)
            return pProxy->m_afValue[0];
    }
    if (spItem->FUN_1411dc7f0()->FUN_14053d070())
    {
        Unk_UgcProxy* pProxy = (Unk_UgcProxy*)spItem->FUN_1411dc7a0()->FUN_140527870();
        if (pProxy != 0)
            return pProxy->m_afValue[2];
    }
    return 1.0f;
}

// @0x1414225d0
void FUN_1414225d0(MS2Ptr<Unk_PickTarget> spPart, int nIndex, float fValue)
{
    if (!spPart)
        return;
    FUN_141422660(spPart->FUN_141200a40(), nIndex, fValue);
}

// @0x141422660
// MS2-FUNCTIONAL: logic recovered from the decomp; /Od codegen (local layout / temporaries) still differs from the exe
void FUN_141422660(MS2Ptr<CEquipItem> spItem, int nIndex, float fValue)
{
    if (spItem.IsNull())
        return;
    if (spItem->FUN_1411dc7f0()->FUN_14053cfd0())
    {
        Unk_UgcProxy* pProxy = (Unk_UgcProxy*)spItem->FUN_1411dc7a0()->FUN_140527870();
        if (pProxy != 0)
            pProxy->m_afValue[nIndex] = fValue < 0.0f ? 0.0f : fValue;
    }
    if (spItem->FUN_1411dc7f0()->FUN_14053c620() == 0xd)
    {
        Unk_UgcProxy* pProxy = (Unk_UgcProxy*)spItem->FUN_1411dc7a0()->FUN_140527870();
        if (pProxy != 0 && nIndex == 0)
            pProxy->m_afValue[0] = fValue < 0.0f ? 0.0f : fValue;
    }
}

// @0x141422840
// MS2-FUNCTIONAL: logic recovered from the decomp; /Od codegen (local layout / temporaries) still differs from the exe
void FUN_141422840(Unk_PickTarget* pPart, Unk_StreamPoint kPos, Unk_StreamPoint kEuler, float fScale)
{
    if (pPart == 0)
        return;
    FUN_1414225d0(pPart->FUN_1411de2e0(), 0, fScale);
    FUN_1414225d0(pPart->FUN_1411de2e0(), 1, fScale);
    pPart->FUN_1412014f0(kPos);
    pPart->FUN_141201620(kEuler);
    FUN_141422b30(pPart, pPart->FUN_141201c90(), kPos, kEuler, fScale);
}

// @0x141422950 - transform -> euler angles in degrees
void FUN_141422950(const NiMatrix3& kRot, Unk_StreamPoint* pEuler)
{
    kRot.ToEulerAnglesXYZ(pEuler->x, pEuler->y, pEuler->z);
    pEuler->x = (pEuler->x * 180.0f) / 3.1415927f;
    pEuler->y = (pEuler->y * 180.0f) / 3.1415927f;
    pEuler->z = (pEuler->z * 180.0f) / 3.1415927f;
}

// @0x141422a00
// MS2-FUNCTIONAL: logic recovered from the decomp; /Od codegen (local layout / temporaries) still differs from the exe
void FUN_141422a00(Unk_PickTarget* pPart, Unk_StreamPoint kPos, const NiMatrix3& kRot, float fScale)
{
    if (pPart == 0)
        return;
    Unk_StreamPoint kEuler;
    FUN_141422950(kRot, &kEuler);
    FUN_1414225d0(pPart->FUN_1411de2e0(), 0, fScale);
    FUN_1414225d0(pPart->FUN_1411de2e0(), 1, fScale);
    pPart->FUN_1412014f0(kPos);
    pPart->FUN_141201620(kEuler);
    FUN_141422b30(pPart, pPart->FUN_141201c90(), kPos, kEuler, fScale);
}

// @0x141422b30 - applies a pose to every node of the part's node set
// MS2-FUNCTIONAL: logic recovered from the decomp; /Od codegen (local layout / temporaries) still differs from the exe
void FUN_141422b30(Unk_PickTarget* pPart, std::set<NiAVObjectPtr>& kNodes, Unk_StreamPoint kPos, Unk_StreamPoint kEuler,
                   float fScale)
{
    if (pPart == 0)
        return;
    MS2Ptr<CEquipItem> spItem = pPart->FUN_141200a40();
    if (spItem.IsNull())
        return;
    Unk_UgcPartInfo* pInfo = (Unk_UgcPartInfo*)pPart->FUN_141200ab0();
    if (pInfo == 0)
        return;
    Unk_StreamPoint kShift = kPos;
    NiMatrix3 kRot;
    kRot.FromEulerAnglesXYZ((kEuler.x * 3.1415927f) / 180.0f, (kEuler.y * 3.1415927f) / 180.0f,
                            (kEuler.z * 3.1415927f) / 180.0f);
    if (spItem->FUN_1411dc7f0()->FUN_14053c620() == 0xd)
    {
        Unk_UgcProxy* pProxy = (Unk_UgcProxy*)spItem->FUN_1411dc7a0()->FUN_140527870();
        if (pProxy != 0)
        {
            NiMatrix3 kBase;
            kBase.FromEulerAnglesXYZ((pProxy->m_aPose[pInfo->m_nSlot + 1].x * 3.1415927f) / 180.0f,
                                     (pProxy->m_aPose[pInfo->m_nSlot + 1].y * 3.1415927f) / 180.0f,
                                     (pProxy->m_aPose[pInfo->m_nSlot + 1].z * 3.1415927f) / 180.0f);
            kRot = kRot * kBase;
            kShift.x += pProxy->m_aPose[pInfo->m_nSlot].x;
            kShift.y += pProxy->m_aPose[pInfo->m_nSlot].y;
            kShift.z += pProxy->m_aPose[pInfo->m_nSlot].z;
        }
    }
    for (std::set<NiAVObjectPtr>::iterator it = kNodes.begin(); it != kNodes.end(); ++it)
    {
        NiAVObjectPtr spNode = *it;
        spNode->SetTranslate(kShift.x, kShift.y, kShift.z);
        spNode->SetRotate(kRot);
        spNode->SetScale(fScale);
    }
}

// @0x141422f30 - true when a mesh of the model has a non-skin-material texture
// MS2-FUNCTIONAL: logic recovered from the decomp; /Od codegen (local layout / temporaries) still differs from the exe
int FUN_141422f30(NiAVObject* pRoot)
{
    if (pRoot == 0)
        return 0;
    Unk_NodeQueue kQueue(pRoot);
    NiAVObject* pObject;
    while ((pObject = kQueue.Next(true)) != 0)
    {
        bool bSkin = false;
        NiMesh* pMesh = NiDynamicCast(NiMesh, pObject);
        if (pMesh != 0)
        {
            unsigned nCount = FUN_141427ab0(pMesh);
            for (unsigned i = 0; i < nCount; i++)
            {
                if (FUN_140998dc0(FUN_14106bd50(FUN_140a17de0(FUN_141427ae0(pMesh, i))), "MS2CharacterSkinMaterial"))
                    bSkin = true;
            }
        }
        if (bSkin)
            continue;
        NiTexturingProperty* pTex = NiDynamicCast(NiTexturingProperty, pObject->GetProperty(8));
        if (pTex == 0 || pTex->GetDecalArrayCount() == 0)
            continue;
        NiTexturingProperty::Map* pMap = pTex->GetDecalMap(0);
        if (pMap == 0)
            continue;
        NiSourceTexture* pSrc = NiDynamicCast(NiSourceTexture, pMap->GetTexture());
        if (pSrc == 0)
            continue;
        NiFixedString kName = pSrc->GetFilename();
        return 1;
    }
    return 0;
}

// @0x141423120
// MS2-FUNCTIONAL: logic recovered from the decomp; /Od codegen (local layout / temporaries) still differs from the exe
int FUN_141423120(const CString& strName, NiAVObjectPtr spRoot, NiAVObjectPtr* pspMesh, NiTexturePtr* pspTexture)
{
    if (spRoot == 0)
        return 0;
    NiAVObjectPtr spFound = FUN_141423480(spRoot, strName);
    if (spFound == 0)
        return 0;
    NiTexturingProperty* pTex = NiDynamicCast(NiTexturingProperty, spFound->GetProperty(8));
    if (pTex == 0)
        return 0;
    NiTexturingProperty::Map* pMap = pTex->GetDecalMap(0);
    NiTexturePtr spTexture = pMap != 0 ? pMap->GetTexture() : 0;
    *pspMesh = spFound;
    *pspTexture = spTexture;
    return 1;
}

// @0x1414232f0 - sets the UGC texture as the decal map of a mesh
int FUN_1414232f0(NiAVObjectPtr spMesh, NiTexturePtr spTexture)
{
    if (spMesh)
    {
        NiTexturingProperty* pTex = NiDynamicCast(NiTexturingProperty, spMesh->GetProperty(8));
        if (pTex != 0)
        {
            NiTexturingProperty::Map* pMap = NiNew NiTexturingProperty::Map;
            if (spTexture)
            {
                pMap->SetFilterMode(pTex->GetBaseMap()->GetFilterMode());
                pMap->SetTexture(spTexture);
            }
            pTex->SetDecalMap(0, pMap);
            spMesh->UpdateProperties();
            return 1;
        }
    }
    return 0;
}

// @0x141423480 - finds the named child of a model; a node without a mesh is resolved to its first child
// MS2-FUNCTIONAL: same calls/order; exe frame 0x78 vs 0x58: after the GetObjectByName result ctor the exe spills the
//   NiAVObjectPtr ctor's return through three stack slots (+0x48/+0x50/+0x60, a reference-binding chain) not reproduced
NiAVObjectPtr FUN_141423480(NiAVObjectPtr spRoot, const CString& strName)
{
    if (spRoot)
    {
        NiAVObjectPtr spObj = spRoot->GetObjectByName((const char*)strName);
        if (spObj)
        {
            if (!FUN_141427d60(spObj))
            {
                NiNodePtr spNode = NiDynamicCast(NiNode, spObj);
                if (spNode)
                    spObj = spNode->GetAt(0);
            }
            return spObj;
        }
    }
    return 0;
}

// @0x141423650
// MS2-FUNCTIONAL: logic recovered from the decomp; /Od codegen (local layout / temporaries) still differs from the exe
int FUN_141423650(unsigned* pArgb, int nSlot, Unk_UgcPlayer* pPlayer)
{
    if (!(nSlot < 2 && -1 < nSlot))
        return 0;
    if (pPlayer == 0)
    {
        pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPlayer == 0)
            return 0;
    }
    Unk_UgcColor kColor;
    FUN_141b6dea0(&kColor, *pArgb);
    pPlayer->FUN_1416591e0(nSlot != 0, &kColor);
    int nPart = nSlot == 0 ? 0 : 2;
    FUN_141b6f220(FUN_141b6efc0(pPlayer->FUN_14123c410()), nPart, &kColor);
    void* pService = FUN_140a6a840();
    UGC_VCALL(pService, 0xd0, void (*)(void*, unsigned))(pService, pPlayer->FUN_141658e60());
    return 1;
}

// A saved look record; only the two colour words are read.
struct Unk_UgcLook
{
    char m_pad[0x3c];
    unsigned m_aColor[2];                                           // +0x3c
};

// @0x141423760
// MS2-FUNCTIONAL: logic recovered from the decomp; /Od codegen (local layout / temporaries) still differs from the exe
int FUN_141423760(Unk_UgcLook* pLook, Unk_UgcPlayer* pPlayer)
{
    if (pPlayer == 0)
    {
        pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPlayer == 0)
            return 0;
    }
    for (unsigned __int64 i = 0; i < 2; i++)
    {
        Unk_UgcColor kColor;
        FUN_141b6dea0(&kColor, pLook->m_aColor[i]);
        pPlayer->FUN_1416591e0((int)i, &kColor);
        int nPart = i == 0 ? 0 : 2;
        FUN_141b6f220(FUN_141b6efc0(pPlayer->FUN_14123c410()), nPart, &kColor);
    }
    void* pService = FUN_140a6a840();
    UGC_VCALL(pService, 0xd0, void (*)(void*, unsigned))(pService, pPlayer->FUN_141658e60());
    return 1;
}

// @0x141423880
// MS2-FUNCTIONAL: logic recovered from the decomp; /Od codegen (local layout / temporaries) still differs from the exe
int FUN_141423880(const Unk_UgcColorList& kColors, Unk_UgcPlayer* pPlayer)
{
    if (kColors.FUN_141278a50())
        return 0;
    if (pPlayer == 0)
    {
        pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPlayer == 0)
            return 0;
    }
    unsigned __int64 nCount;
    if (kColors.FUN_14059d0e0() < 2)
        nCount = kColors.FUN_14059d0e0();
    else
        nCount = 2;
    for (unsigned __int64 i = 0; i < nCount; i++)
    {
        Unk_UgcColor kColor;
        FUN_141b6dea0(&kColor, *kColors.FUN_140ce98c0(i));
        pPlayer->FUN_1416591e0((int)i, &kColor);
        int nPart = i == 0 ? 0 : 2;
        FUN_141b6f220(FUN_141b6efc0(pPlayer->FUN_14123c410()), nPart, &kColor);
    }
    void* pService = FUN_140a6a840();
    UGC_VCALL(pService, 0xd0, void (*)(void*, unsigned))(pService, pPlayer->FUN_141658e60());
    return 1;
}

// @0x1414239e0
// MS2-FUNCTIONAL: logic recovered from the decomp; /Od codegen (local layout / temporaries) still differs from the exe
int FUN_1414239e0(unsigned* pOut, int nSlot, Unk_UgcPlayer* pPlayer)
{
    if (!(nSlot < 3))
        return 0;
    if (pPlayer == 0)
    {
        pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPlayer == 0)
            return 0;
    }
    *pOut = FUN_141b6df90(pPlayer->FUN_141659220(nSlot));
    return 1;
}

// @0x141423a70
// MS2-FUNCTIONAL: logic recovered from the decomp; /Od codegen (local layout / temporaries) still differs from the exe
int FUN_141423a70(__int64 nUid, const Unk_UgcColorList& kColors, Unk_UgcPlayer* pPlayer, int nIndex)
{
    if (nUid == 0 || kColors.FUN_141278a50())
        return 0;
    if (pPlayer == 0)
    {
        pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPlayer == 0)
            return 0;
    }
    MS2Ptr<CEquipItem> spItem = pPlayer->FUN_141655c30(nUid);
    if (spItem == 0 || spItem->FUN_1411dc7a0() == 0)
        return 0;
    MS2Ptr<Unk_UgcProxy> spProxy((Unk_UgcProxy*)spItem->FUN_1411dc7a0()->FUN_140527870());
    if (spProxy == 0)
        return 0;
    spProxy->FUN_140599d10(kColors, nIndex);
    spItem->FUN_1411dd150();
    spItem->FUN_1411dcd00();
    UGC_VCALL(pPlayer, 0x458, void (*)(void*))(pPlayer);
    return 1;
}

// @0x141423cf0
// MS2-FUNCTIONAL: logic recovered from the decomp; /Od codegen (local layout / temporaries) still differs from the exe
int FUN_141423cf0(__int64 nUid, const Unk_UgcExtra& kExtra, Unk_UgcPlayer* pPlayer, int nIndex)
{
    if (nUid == 0)
        return 0;
    if (pPlayer == 0)
    {
        pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPlayer == 0)
            return 0;
    }
    MS2Ptr<CEquipItem> spItem = pPlayer->FUN_141655c30(nUid);
    if (spItem == 0 || spItem->FUN_1411dc7a0() == 0)
        return 0;
    Unk_UgcProxy* pProxy = (Unk_UgcProxy*)spItem->FUN_1411dc7a0()->FUN_140527870();
    if (pProxy == 0)
        return 0;
    bool bFlag = false;
    if (kExtra.m_nType == FUN_140f02bc0())
        bFlag = spItem->FUN_1411dc7f0()->FUN_14053d020() == 1;
    pProxy->FUN_140599bc0(kExtra, bFlag, spItem->FUN_1411dc7f0()->FUN_14053e310(nIndex), nIndex);
    spItem->FUN_1411dd150();
    spItem->FUN_1411dcd00();
    UGC_VCALL(pPlayer, 0x458, void (*)(void*))(pPlayer);
    return 1;
}

// @0x141423fb0
// MS2-FUNCTIONAL: logic recovered from the decomp; /Od codegen (local layout / temporaries) still differs from the exe
int FUN_141423fb0(__int64 nUid, void* pColor, int nIndex, Unk_UgcPlayer* pPlayer, int nValue)
{
    if (2 < nIndex || nIndex < 0)
        return 0;
    if (pPlayer == 0)
    {
        pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPlayer == 0)
            return 0;
    }
    MS2Ptr<CEquipItem> spItem = pPlayer->FUN_141655c30(nUid);
    if (spItem == 0 || spItem->FUN_1411dc7a0() == 0)
        return 0;
    MS2Ptr<Unk_UgcProxy> spProxy((Unk_UgcProxy*)spItem->FUN_1411dc7a0()->FUN_140527870());
    if (spProxy == 0)
        return 0;
    spProxy->FUN_140599ea0(nIndex, pColor, nValue);
    spItem->FUN_1411dd150();
    spItem->FUN_1411dcd00();
    UGC_VCALL(pPlayer, 0x458, void (*)(void*))(pPlayer);
    return 1;
}

// @0x141424230
// MS2-FUNCTIONAL: logic recovered from the decomp; /Od codegen (local layout / temporaries) still differs from the exe
int FUN_141424230(__int64 nUid, Unk_UgcPlayer* pPlayer)
{
    if (nUid == 0)
        return 0;
    if (pPlayer == 0)
    {
        pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPlayer == 0)
            return 0;
    }
    MS2Ptr<CEquipItem> spItem = pPlayer->FUN_141655c30(nUid);
    if (spItem.IsNull() || spItem->FUN_1411dc7a0().IsNull() || spItem->FUN_1411dc7a0()->FUN_140527870() == 0)
        return 0;
    Unk_UgcItemData* pData = spItem->FUN_1411dc7f0();
    ((Unk_UgcProxy*)spItem->FUN_1411dc7a0()->FUN_140527870())->FUN_140599ab0(pData);
    spItem->FUN_1411dd150();
    spItem->FUN_1411dcd00();
    UGC_VCALL(pPlayer, 0x458, void (*)(void*))(pPlayer);
    return 1;
}

// @0x1414244b0
// MS2-FUNCTIONAL: logic recovered from the decomp; /Od codegen (local layout / temporaries) still differs from the exe
int FUN_1414244b0(__int64 nUid, unsigned* pOut, int nIndex, Unk_UgcPlayer* pPlayer)
{
    if (!(nIndex < 3))
        return 0;
    if (pPlayer == 0)
    {
        pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPlayer == 0)
            return 0;
    }
    MS2Ptr<CEquipItem> spItem = pPlayer->FUN_141655c30(nUid);
    return FUN_141424580(spItem, pOut, nIndex);
}

// @0x141424580
// MS2-FUNCTIONAL: logic recovered from the decomp; /Od codegen (local layout / temporaries) still differs from the exe
bool FUN_141424580(MS2Ptr<CEquipItem> spItem, unsigned* pOut, int nIndex)
{
    if (spItem == 0 || spItem->FUN_1411dc7a0() == 0 || spItem->FUN_1411dc7a0()->FUN_140527870() == 0)
        return false;
    *pOut = ((Unk_UgcProxy*)spItem->FUN_1411dc7a0()->FUN_140527870())->FUN_140599fd0(nIndex);
    return true;
}

// @0x141424760
// MS2-FUNCTIONAL: logic recovered from the decomp; /Od codegen (local layout / temporaries) still differs from the exe
int FUN_141424760(MS2Ptr<CItem> spItem, unsigned* pOut, int nIndex, Unk_UgcPlayer* pPlayer)
{
    if (!spItem.IsNull() && spItem->FUN_140527840() != 0)
    {
        if (!((Unk_UgcItemData*)spItem->FUN_140527840())->FUN_14053cf00())
        {
            *pOut = ((Unk_UgcProxy*)spItem->FUN_140527870())->FUN_140599fd0(nIndex);
            return 1;
        }
        if (pPlayer == 0)
        {
            pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
            if (pPlayer == 0)
                return 0;
        }
        FUN_1414239e0(pOut, nIndex, pPlayer);
        return 0;
    }
    return 0;
}

// @0x1414248a0
int FUN_1414248a0(Unk_UgcItemData* pData, __int64 nKey, int* pOut)
{
    if (pData == 0)
        return 0;
    int nItemId = pData->FUN_14053e260();
    if (nItemId == 0)
        return 0;
    Unk_UgcRowPtr kRow = FUN_140281980()->FUN_140558cc0(nItemId, nKey);
    if (kRow.FUN_14056cf90(0))
        return 0;
    *pOut = kRow.FUN_14056d570()->m_nValue;
    return 1;
}

// @0x141424970 - true when the item has a colour table row for the colours of the equipped item
// MS2-FUNCTIONAL: logic recovered from the decomp; /Od codegen (local layout / temporaries) still differs from the exe
int FUN_141424970(MS2Ptr<CItem> spItem, Unk_UgcPlayer* pPlayer)
{
    if (spItem == 0)
        return 0;
    MS2Ptr<CItemData> spData = FUN_14053f870(spItem->FUN_1405276c0());
    if (spData == 0)
        return 0;
    if (!((Unk_UgcItemData*)spData.get())->FUN_14053cf00())
    {
        int nItemId = ((Unk_UgcItemData*)spData.get())->FUN_14053e260();
        if (nItemId != 0)
        {
            CItemExtraData* pExtra = (Unk_UgcProxy*)spItem->FUN_140527870();
            Unk_UgcRowPtr kRow = FUN_140281980()->FUN_140558e80(
                nItemId, spData, Delegate<bool(const ItemColorEx&, MS2Ptr<CItemData>)>(pExtra, &CItemExtraData::FUN_140599480));
            if (FUN_14059cf00(&kRow) != 0)
                return 1;
        }
    }
    else
    {
        unsigned aColor[2];
        FUN_1414239e0(&aColor[0], 0, pPlayer);
        FUN_1414239e0(&aColor[1], 1, pPlayer);
        int nItemId = ((Unk_UgcItemData*)spData.get())->FUN_14053e260();
        if (nItemId != 0)
        {
            Unk_UgcRowPtr kRow = FUN_140281980()->FUN_1405590e0(nItemId, &aColor[0], &aColor[1]);
            if (FUN_14059cf00(&kRow) != 0)
                return 1;
        }
    }
    return 0;
}

// @0x141424d00 - ray-picks the item's mesh parts; *pbEmpty is set to 0 when any mesh was tested
// MS2-FUNCTIONAL: logic recovered from the decomp; /Od codegen (local layout / temporaries) still differs from the exe
bool FUN_141424d00(MS2Ptr<CEquipItem> spItem, NiPoint3* pOrigin, NiPoint3* pDir, NiPick* pPick, int* pbEmpty)
{
    pPick->SetFrontOnly(true);
    pPick->SetCoordinateType(NiPick::COORDINATES_WORLD);
    pPick->SetIntersectType(NiPick::INTERSECT_TRIANGLE);
    CAtlArray<MS2Ptr<Unk_PickTarget> > aParts;
    spItem->FUN_1411dcc80(aParts);
    *pbEmpty = 1;
    for (size_t i = 0; i < aParts.GetCount(); i++)
    {
        std::set<NiAVObjectPtr>& kSet = aParts[i]->FUN_141201c90();
        for (std::set<NiAVObjectPtr>::iterator it = kSet.begin(); it != kSet.end(); ++it)
        {
            NiAVObjectPtr spRoot = *it;
            Unk_NodeQueue kQueue(spRoot);
            NiAVObject* pObject;
            while ((pObject = kQueue.Next(true)) != 0)
            {
                NiMesh* pMesh = NiDynamicCast(NiMesh, pObject);
                if (pMesh != 0)
                {
                    *pbEmpty = 0;
                    NiSPWorkflowManagerPtr spWorkflow = NiNew NiSPWorkflowManager(0x40, NiStreamProcessor::MEDIUM, 3);
                    NiSyncArgs kComplete;
                    kComplete.m_uiSubmitPoint = 0x8000;
                    kComplete.m_uiCompletePoint = 0x8000;
                    pMesh->CompleteModifiers(&kComplete);
                    for (unsigned j = 0; j < pMesh->GetModifierCount(); j++)
                    {
                        NiMeshModifier* pModifier = pMesh->GetModifierAt(j);
                        if (pModifier->SupportsSubmitSyncPoint(0x8030))
                        {
                            NiSyncArgs kSubmit;
                            kSubmit.m_uiSubmitPoint = 0x8030;
                            kSubmit.m_uiCompletePoint = 0x8040;
                            pModifier->SubmitTasks(pMesh, &kSubmit, spWorkflow);
                        }
                    }
                    unsigned uiGroup = NiSyncArgs::GetTaskGroupID(0x8030, 0x8040);
                    spWorkflow->FlushTaskGroup(uiGroup, uiGroup);
                    NiCollisionTraversals::FindIntersections(*pOrigin, *pDir, *pPick, pMesh);
                }
            }
        }
    }
    return pPick->GetResults().GetSize() != 0;
}

// @0x141425130 - true when a mesh of the model has an animation controller of the UGC type
// MS2-FUNCTIONAL: logic recovered from the decomp; /Od codegen (local layout / temporaries) still differs from the exe
int FUN_141425130(NiAVObject* pRoot)
{
    Unk_NodeQueue kQueue(pRoot);
    NiAVObject* pObject;
    while ((pObject = kQueue.Next(true)) != 0)
    {
        NiMesh* pMesh = NiDynamicCast(NiMesh, pObject);
        if (pMesh == 0)
            continue;
        for (NiTimeController* pCtrl = FUN_14098dc80(pMesh); pCtrl != 0; pCtrl = FUN_14098de40(pCtrl))
        {
            if (FUN_14098d8d0(&DAT_143af8a20, pCtrl) != 0)
                return 1;
        }
    }
    return 0;
}

// ---- model file names ----

// @0x141425220 - strips the extension of a model path, adds the suffix and the ".nif"-style tail
// MS2-FUNCTIONAL: logic recovered from the decomp; /Od codegen (local layout / temporaries) still differs from the exe
CString FUN_141425220(const CString& strPath, int bDiffuse)
{
    CString strName(strPath);
    CString strSuffix(bDiffuse == 0 ? "" : "_D");
    strName = strName.Left(strName.ReverseFind('.'));
    strName = FUN_14038f6d0(FUN_1401d2b10(strName, strSuffix), DAT_142f10fe4);
    return strName;
}

// @0x1414253b0
// MS2-FUNCTIONAL: logic recovered from the decomp; /Od codegen (local layout / temporaries) still differs from the exe
CString FUN_1414253b0(const CString& strPath, int bDiffuse)
{
    CString strName(strPath);
    CString strSuffix(bDiffuse == 0 ? "" : "_D");
    strName = strName.Left(strName.ReverseFind('.'));
    strName = FUN_14038f6d0(FUN_1401d2b10(strName, strSuffix), DAT_142f10ff0);
    return strName;
}

// @0x141425540 - effect file of the swim tube (nGender 1 = female, nAction 0x30 = idle)
CString FUN_141425540(int nGender, int nAction)
{
    if (0x30 == nAction)
    {
        if (1 == nGender)
            return CString("CH/Common/Eff_Tube_F_SwimIdle_A.xml");
        else
        {
            return CString("CH/Common/Eff_Tube_M_SwimIdle_A.xml");
        }
    }
    else if (1 == nGender)
        return CString("CH/Common/Eff_Tube_F_SwimRun_A.xml");
    else
    {
        return CString("CH/Common/Eff_Tube_M_SwimRun_A.xml");
    }
}

// @0x141425610 - preloads the four swim tube effects
// MS2-FUNCTIONAL: logic recovered from the decomp; /Od codegen (local layout / temporaries) still differs from the exe
void FUN_141425610()
{
    if (FUN_1403ed280() != 0)
    {
        FUN_1411a4800(FUN_141425540(1, 0x30), 5);
        FUN_1411a4800(FUN_141425540(1, 0x31), 5);
        FUN_1411a4800(FUN_141425540(0, 0x30), 5);
        FUN_1411a4800(FUN_141425540(0, 0x31), 5);
    }
}

// ---- item lookup ----

struct Unk_UgcInventory
{
    MS2Ptr<CItem> FUN_140a5d680(__int64 nUid);                      // the inventory's item by uid
};
extern Unk_UgcInventory DAT_143ab2a90;

// @0x141425750 - an item by uid: from the inventory, else the one the player wears (*pbEquipped = true)
// MS2-FUNCTIONAL: logic recovered from the decomp; /Od codegen (local layout / temporaries) still differs from the exe
MS2Ptr<CItem> FUN_141425750(__int64 nUid, bool* pbEquipped)
{
    if (pbEquipped != 0)
        *pbEquipped = false;
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nUid);
    if (spItem.get() != 0)
        return spItem;
    Unk_UgcPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return MS2Ptr<CItem>(0);
    MS2Ptr<CEquipItem> spEquip = pPlayer->FUN_141655c30(nUid);
    if (spEquip.get() == 0)
        return MS2Ptr<CItem>(0);
    if (pbEquipped != 0)
        *pbEquipped = true;
    return spEquip->FUN_1411dc7a0();
}

// @0x1414258e0 - the inventory has the item
bool FUN_1414258e0(__int64 nUid)
{
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nUid);
    return spItem.get() != 0;
}

// ---- item names ----

// @0x141425950 - display name of an item; a linked item (kind 0xb) is shown through its link-kind string
// MS2-FUNCTIONAL: logic recovered from the decomp; /Od codegen (local layout / temporaries) still differs from the exe
CStringW FUN_141425950(unsigned nItemId)
{
    CStringW strName = FUN_1401a9d70()->FUN_141811980(1, nItemId);
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData == 0)
        return FUN_1401a9d70()->FUN_141811980(1, nItemId);
    if (((Unk_UgcItemData*)spData.get())->FUN_14053c5c0() != 0xb)
        return strName;
    CStringW strLinked = FUN_1401a9d70()->FUN_141811980(1, ((Unk_UgcItemData*)spData.get())->FUN_14053dc60());
    Unk_UgcRow2Ptr kRow = FUN_14052d210()->FUN_1407290f0(((Unk_UgcItemData*)spData.get())->FUN_14053dc60());
    if (kRow.FUN_14052cde0())
        return strLinked;
    if (kRow.FUN_14052ceb0()->m_nType == 1)
        return FUN_14052bd00(0xcd6, strLinked);
    return FUN_14052bd00(0xcd5, strLinked);
}

// @0x141425c00 - name of the first item of a category
// MS2-FUNCTIONAL: logic recovered from the decomp; /Od codegen (local layout / temporaries) still differs from the exe
CStringW FUN_141425c00(int nCategory)
{
    CStringW strName;
    std::vector<MS2Ptr<CItemData> > aItems;
    FUN_1405592e0(FUN_140281980(), &aItems);
    for (unsigned __int64 i = 0; i < aItems.size(); i++)
    {
        MS2Ptr<CItemData> spData = aItems[i];
        if (spData.get() != 0 && ((Unk_UgcItemData*)spData.get())->FUN_14053ec50() == nCategory)
        {
            strName = FUN_1401a9d70()->FUN_141811980(1, ((Unk_UgcItemData*)spData.get())->FUN_14053c510());
            if (!strName.IsEmpty())
                return strName;
            CStringW strDesc;
            ((Unk_UgcItemData*)spData.get())->FUN_14053eba0()->FUN_14054b6e0(&strDesc);
            return strDesc;
        }
    }
    return CStringW((const wchar_t*)0);
}

// @0x141425e40 - logs the scene graph below pObj, one tab per depth
// MS2-FUNCTIONAL: logic recovered from the decomp; /Od codegen (local layout / temporaries) still differs from the exe
void FUN_141425e40(NiAVObject* pObj, int nDepth)
{
    if (pObj == 0)
        return;
    CString strIndent;
    for (int i = 0; i < nDepth; i++)
        strIndent += "\t";
    CString strName((const char*)pObj->GetName());
    if (FUN_140166440() != 0)
        FUN_14054c030(FUN_140166440(), 0xb, 0x12d, L"{0}>({1})", strIndent, strName);
    if (FUN_1411c9940(pObj))
    {
        NiNode* pNode = NiDynamicCast(NiNode, pObj);
        if (pNode != 0)
        {
            int nCount = pNode->GetArrayCount();
            for (int i = 0; i < nCount; i++)
                FUN_141425e40(pNode->GetAt(i), nDepth + 1);
        }
    }
}

// @0x141425fc0 - sells nCount of a stack, unless the item is a summoned pet item
// MS2-FUNCTIONAL: logic recovered from the decomp; /Od codegen (local layout / temporaries) still differs from the exe
void FUN_141425fc0(__int64 nUid, int nCount, void* pCallback)
{
    if (0 < nCount)
    {
        Unk_UgcPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPlayer != 0)
        {
            if (FUN_141676b00(pPlayer, nUid) == 0)
            {
                COutPacket kPacket(0x28, 0);
                kPacket.vfunc_o10_1(5);
                kPacket.vfunc_o10_4(nUid);
                kPacket.vfunc_o10_3(nCount);
                FUN_140710590(kPacket);
                FUN_141276180(DAT_143adc208, CString(""));
                if (pCallback != 0)
                    FUN_1412750f0(pCallback, nCount, 0x28b, 0x28a);
            }
            else
            {
                FUN_1412751b0(FUN_14028b8e0(CStringW(L"s_err_cannot_sell_petitem_summon")), 0x14);
            }
        }
    }
}

// @0x141427580
template <> Delegate<bool(const ItemColorEx&, MS2Ptr<CItemData>)>::DelegateImplBase::DelegateImplBase()
{
}

// @0x141427670
template <> Delegate<bool(const ItemColorEx&, MS2Ptr<CItemData>)>::DelegateImplBase::~DelegateImplBase()
{
}

// ---- CItemUgcMesh / CItemUgcMeshContainer ----

extern char DAT_142f11044[];                                        // part-name separator
extern char DAT_142f1106c[];                                        // part-name suffix tested for the ankle part
void FUN_14015f050(const CString& strText, CAtlArray<CString>& aOut, const char* szSep);   // split
char FUN_140184310(const CString& strText, const char* szSuffix);   // ends with
bool FUN_14053d6f0(Unk_UgcItemData* pData);                         // the item has attach parts

// @0x141427500
CItemUgcMesh::CItemUgcMesh()
{
}

// @0x141427620
// MS2-FUNCTIONAL: logic recovered from the decomp; /Od codegen (local layout / temporaries) still differs from the exe
CItemUgcMesh::~CItemUgcMesh()
{
}

// @0x141426140
void CItemUgcMeshContainer::FUN_141426140()
{
    m_meshes.RemoveAll();
}

// @0x141426170
// MS2-FUNCTIONAL: the node-set iteration and the by-value MS2Ptr temporaries are laid out differently
bool CItemUgcMeshContainer::FUN_141426170(MS2Ptr<CEquipItem> spItem)
{
    if (spItem == 0)
        return false;
    Unk_UgcItemData* pData = spItem->FUN_1411dc7f0();
    if (pData == 0)
        return false;
    if (!FUN_14053d6f0(pData))
        return false;
    m_meshes.RemoveAll();
    CAtlArray<CString> aNames;
    FUN_141426750(aNames, pData);
    if (aNames.IsEmpty())
        return false;
    CAtlArray<MS2Ptr<Unk_PickTarget> > aParts;
    spItem->FUN_1411dcc80(aParts);
    for (size_t i = 0; i < aNames.GetCount(); i++)
    {
        CString& strName = aNames[i];
        for (unsigned j = 0; j < aParts.GetCount(); j++)
        {
            MS2Ptr<Unk_PickTarget> spPart = aParts[j];
            std::set<NiAVObjectPtr> kNodes;
            spPart->FUN_141201cb0(kNodes);
            for (std::set<NiAVObjectPtr>::iterator it = kNodes.begin(); it != kNodes.end(); ++it)
            {
                NiAVObjectPtr spNode = *it;
                if (spNode != 0)
                {
                    MS2Ptr<CItemUgcMesh> spMesh = FUN_141426af0(strName, spNode);
                    if (!(spMesh == 0))
                        m_meshes.Add(spMesh);
                }
            }
        }
    }
    return true;
}

// @0x141426540
// MS2-FUNCTIONAL: logic recovered from the decomp; /Od codegen (local layout / temporaries) still differs from the exe
bool CItemUgcMeshContainer::FUN_141426540(MS2Ptr<CItemData> spData, NiAVObjectPtr spRoot)
{
    if (!(spData == 0) && !(spRoot == 0))
    {
        m_meshes.RemoveAll();
        CAtlArray<CString> aNames;
        FUN_141426750(aNames, spData.get());
        if (aNames.IsEmpty())
            return false;
        for (size_t i = 0; i < aNames.GetCount(); i++)
        {
            MS2Ptr<CItemUgcMesh> spMesh = FUN_141426af0(aNames[i], spRoot);
            if (!(spMesh == 0))
                m_meshes.Add(spMesh);
        }
        return true;
    }
    return false;
}

// @0x141426750 - the attach-part names of an item (the comma list at +0x208), plus the ankle part of shoes
// MS2-FUNCTIONAL: logic recovered from the decomp; /Od codegen (local layout / temporaries) still differs from the exe
void CItemUgcMeshContainer::FUN_141426750(CAtlArray<CString>& aNames, void* pItemData)
{
    aNames.RemoveAll();
    CString strParts(*(CString*)((char*)pItemData + 0x208));
    FUN_14015f050(strParts, aNames, DAT_142f11044);
    if (FUN_140184310(strParts, DAT_142f1106c))
        aNames.Add(CString("SH_Ankle"));
}

// @0x141426810
void CItemUgcMeshContainer::FUN_141426810(NiTexture* pTexture)
{
    if (m_meshes.IsEmpty())
        return;
    size_t nCount = m_meshes.GetCount();
    for (size_t i = 0; i < nCount; i++)
    {
        MS2Ptr<CItemUgcMesh> spMesh = m_meshes[i];
        if (spMesh == 0 || spMesh->m_spObject == 0)
            continue;
        FUN_1414232f0(spMesh->m_spObject, pTexture);
    }
}

// @0x141426980
// MS2-FUNCTIONAL: logic recovered from the decomp; /Od codegen (local layout / temporaries) still differs from the exe
void CItemUgcMeshContainer::FUN_141426980()
{
    if (!m_meshes.IsEmpty())
    {
        size_t nCount = m_meshes.GetCount();
        for (size_t i = 0; i < nCount; i++)
        {
            MS2Ptr<CItemUgcMesh> spMesh = m_meshes[i];
            if (!(spMesh == 0) && !(spMesh->m_spObject == 0))
                FUN_1414232f0(spMesh->m_spObject, spMesh->m_spTexture);
        }
    }
}

// @0x141426af0 - one UGC mesh entry for the named node of a model
// MS2-FUNCTIONAL: logic recovered from the decomp; /Od codegen (local layout / temporaries) still differs from the exe
MS2Ptr<CItemUgcMesh> CItemUgcMeshContainer::FUN_141426af0(const CString& strName, NiAVObjectPtr spRoot)
{
    if (!(spRoot == 0))
    {
        NiAVObjectPtr spObject;
        NiTexturePtr spTexture;
        FUN_141423120(strName, spRoot, &spObject, &spTexture);
        if (!(spObject == 0))
        {
            MS2Ptr<CItemUgcMesh> spMesh(new CItemUgcMesh);
            spMesh->m_str18 = strName;
            spMesh->m_spObject = spObject;
            spMesh->m_spTexture = spTexture;
            m_meshes.Add(spMesh);
            return spMesh;
        }
    }
    return MS2Ptr<CItemUgcMesh>(0);
}

// @0x141426d40
// MS2-FUNCTIONAL: logic recovered from the decomp; /Od codegen (local layout / temporaries) still differs from the exe
NiTexturePtr CItemUgcMeshContainer::FUN_141426d40()
{
    if (!m_meshes.IsEmpty())
    {
        MS2Ptr<CItemUgcMesh> spMesh = m_meshes[0];
        if (!spMesh.IsNull())
            return spMesh->m_spTexture;
    }
    return NiTexturePtr(0);
}

// @0x141426e30
// MS2-FUNCTIONAL: logic recovered from the decomp; /Od codegen (local layout / temporaries) still differs from the exe
NiTexturePtr CItemUgcMeshContainer::FUN_141426e30()
{
    if (!m_meshes.IsEmpty())
    {
        MS2Ptr<CItemUgcMesh> spMesh = m_meshes[0];
        if (!spMesh.IsNull() && !(spMesh->m_spObject == 0))
        {
            NiTexturingProperty* pTex = NiDynamicCast(NiTexturingProperty, spMesh->m_spObject->GetProperty(8));
            if (pTex == 0)
                return NiTexturePtr(0);
            NiTexturingProperty::Map* pMap = pTex->GetBaseMap();
            if (pMap == 0)
                return NiTexturePtr(0);
            return NiTexturePtr(pMap->GetTexture());
        }
    }
    return NiTexturePtr(0);
}

// ---- raw glue of the node-set / material-slot / pick-mask helpers (no source-level owner is recovered for these) ----
unsigned FUN_140a17e90(void* pSlots);
bool FUN_14098dba0(void* pObj, unsigned short nMask);
unsigned FUN_141427b60(void* pArray);
void FUN_1414280a0(void* pPtr, void* pOld);
void FUN_141428560(void* pNode);
void* FUN_141427290(void* pMem, void* pArg);
void* FUN_141427210(void* pIter);
void* FUN_1412095f0(void* pSet);
void** FUN_140553e80(void* pSet);
void FUN_1405408b0(void* pOut, void* pNode, void* pTree);
void* FUN_141427160(void* pSet, void* pKey);
void* FUN_141428500(void* pSet, void* pOut, void* pKey);
void* FUN_141428280(void* pSet, void* pOut);
void FUN_141428070(void* pPtr);
bool FUN_1405411b0(void* pIterA, void* pIterB);
void* FUN_1405541f0(void* pSet, void* pNode);
void* FUN_140554040(void* pSet);
bool FUN_140552a70(void* pLess, void* pKey, void* pNode);

// @0x141427370
void* FUN_141427370(void* pDst, void* pSrc)     // MS2-FUNCTIONAL: raw move of the held pointer (tail of a smart pointer)
{
    ((void**)pDst)[1] = ((void**)pSrc)[1];
    ((void**)pSrc)[1] = 0;
    return pDst;
}

// @0x1414273e0
void* FUN_1414273e0(void* pDst, int)            // MS2-FUNCTIONAL: raw reset of the held pointer
{
    ((void**)pDst)[1] = 0;
    return pDst;
}

// @0x141427400
void* FUN_141427400(void* pDst, void* pObj)     // MS2-FUNCTIONAL: raw smart pointer attach
{
    ((void**)pDst)[1] = pObj;
    FUN_141428070(pDst);
    return pDst;
}

// @0x141428070
void FUN_141428070(void* pPtr)                  // MS2-FUNCTIONAL: raw AddRef of the held pointer
{
    if (((void**)pPtr)[1])
        FUN_1414280a0(pPtr, 0);
}

struct Unk_UgcRawHead { char* m_p; };

// @0x1414277a0
char* FUN_1414277a0(void* pNode)                // MS2-FUNCTIONAL: raw payload address of a tree node
{
    return ((Unk_UgcRawHead*)pNode)->m_p + 0x20;
}

// @0x141427780
void FUN_141427780(void* pNode)                 // MS2-FUNCTIONAL: raw node release
{
    FUN_141428560(FUN_1414277a0(pNode));
}

// @0x1414279b0
int FUN_1414279b0(void* pArray, unsigned short* pValue)    // MS2-FUNCTIONAL: raw CSimpleArray<unsigned short>::Find
{
    for (unsigned i = 0; i < ((unsigned*)pArray)[3]; ++i)
        if ((*(unsigned short**)pArray)[i] == *pValue)
            return (int)i;
    return -1;
}

// @0x141427a50
char* FUN_141427a50(void* pSlots, unsigned nIndex)         // MS2-FUNCTIONAL: raw element address of the 0x50 byte slot array
{
    return ((Unk_UgcRawHead*)pSlots)->m_p + (unsigned long long)nIndex * 0x50;
}

// @0x141427a70
void* FUN_141427a70(void* pObj)                 // MS2-FUNCTIONAL: raw second pointer field
{
    return ((void**)pObj)[1];
}

// @0x141427ab0
unsigned FUN_141427ab0(void* pMesh)             // MS2-FUNCTIONAL: raw material count
{
    return FUN_140a17e90((char*)pMesh + 0xf8);
}

// @0x141427ae0
void* FUN_141427ae0(void* pMesh, unsigned nIndex)          // MS2-FUNCTIONAL: raw material slot
{
    return FUN_141427a50((char*)pMesh + 0xf8, nIndex);
}

// @0x141427d60
bool FUN_141427d60(NiAVObject* pObj)            // MS2-FUNCTIONAL: raw flag test
{
    return !FUN_14098dba0(pObj, 0x100);
}

// @0x141427fb0
void FUN_141427fb0(void* pPick, bool bFront)    // MS2-FUNCTIONAL: raw NiPick::SetFrontOnly
{
    *((bool*)pPick + 0x50) = bFront;
}

// @0x141427fd0
void FUN_141427fd0(void* pPick, int nType)      // MS2-FUNCTIONAL: raw NiPick::SetIntersectType
{
    *(int*)((char*)pPick + 8) = nType;
}

// @0x141427ff0
bool FUN_141427ff0(void* pFilter, unsigned short nId)      // MS2-FUNCTIONAL: raw id filter test
{
    if (nId == 0x8000)
        return FUN_141427b60((char*)pFilter + 0x10) > 0;
    return FUN_1414279b0((char*)pFilter + 0x10, &nId) != -1;
}

// @0x1414281e0
void* FUN_1414281e0(void* pSelf, void* pArg)    // MS2-FUNCTIONAL: raw allocate + construct of a 0x18 byte node
{
    void* pMem = operator new(0x18);
    return pMem ? FUN_141427290(pMem, pArg) : 0;
}

// @0x141428240
bool FUN_141428240(void* pSet)                  // MS2-FUNCTIONAL: raw emptiness test
{
    return FUN_1412095f0(pSet) == 0;
}

// @0x141428280
void* FUN_141428280(void* pSet, void* pOut)     // MS2-FUNCTIONAL: raw end iterator
{
    void** pHead = FUN_140553e80(pSet);
    FUN_1405408b0(pOut, *pHead, FUN_141427210(pHead));
    return pOut;
}

// @0x1414282e0
void* FUN_1414282e0(void* pSet, void** pOut, void* pKey)   // MS2-FUNCTIONAL: raw set find
{
    void* itFound;
    FUN_141428500(pSet, &itFound, pKey);
    char itEnd[8];
    if (FUN_1405411b0(&itFound, FUN_141428280(pSet, itEnd)) ||
        FUN_140552a70(FUN_140554040(pSet), pKey, FUN_1405541f0(pSet, itFound)))
    {
        char itEnd2[8];
        *pOut = *(void**)FUN_141428280(pSet, itEnd2);
    }
    else
        *pOut = itFound;
    return pOut;
}

// @0x141428500
void* FUN_141428500(void* pSet, void* pOut, void* pKey) // MS2-FUNCTIONAL: raw lower_bound (iterator(_Lbound(key), _Get_scary()))
{
    FUN_1405408b0(pOut, FUN_141427160(pSet, pKey), FUN_141427210(FUN_140553e80(pSet)));
    return pOut;
}

// ---- hooks ----
MS2_REPLACE(0x141422340, FUN_141422340, 650, 0xACEEF5C4);
MS2_REPLACE(0x1414225D0, FUN_1414225d0, 131, 0xC95C0386);
MS2_REPLACE(0x141422660, FUN_141422660, 471, 0xF037BD35);
MS2_REPLACE(0x141422840, FUN_141422840, 259, 0xAF3D108C);
MS2_REPLACE(0x141422950, FUN_141422950, 164, 0x6F768EA3);
MS2_REPLACE(0x141422A00, FUN_141422a00, 287, 0x259B91DB);
MS2_REPLACE(0x141422B30, FUN_141422b30, 1011, 0x90C84991);
MS2_REPLACE(0x141422F30, FUN_141422f30, 485, 0xE30684FD);
MS2_REPLACE(0x141423120, FUN_141423120, 456, 0x62ABC47B);
MS2_REPLACE(0x1414232F0, FUN_1414232f0, 393, 0xD9B80474);
MS2_REPLACE(0x141423480, FUN_141423480, 443, 0x16EC5D6F);
MS2_REPLACE(0x141423650, FUN_141423650, 262, 0xE2249C38);
MS2_REPLACE(0x141423760, FUN_141423760, 270, 0xA6E5159E);
MS2_REPLACE(0x141423880, FUN_141423880, 340, 0x3C5229FE);
MS2_REPLACE(0x1414239E0, FUN_1414239e0, 131, 0x0C2F5269);
MS2_REPLACE(0x141423A70, FUN_141423a70, 623, 0x1CB9AF7D);
MS2_REPLACE(0x141423CF0, FUN_141423cf0, 688, 0x3C9238C7);
MS2_REPLACE(0x141423FB0, FUN_141423fb0, 619, 0x7C812A7C);
MS2_REPLACE(0x141424230, FUN_141424230, 622, 0x774A614B);
MS2_REPLACE(0x1414244B0, FUN_1414244b0, 197, 0xCEB3F2BD);
MS2_REPLACE(0x141424580, FUN_141424580, 466, 0xBA5F7F71);
MS2_REPLACE(0x141424760, FUN_141424760, 300, 0x090807C5);
MS2_REPLACE(0x1414248A0, FUN_1414248a0, 187, 0x5E3F8A34);
MS2_REPLACE(0x141424970, FUN_141424970, 892, 0x51F27444);
MS2_REPLACE(0x141424D00, FUN_141424d00, 1051, 0xD7487E34);
MS2_REPLACE(0x141425130, FUN_141425130, 228, 0x045E9E5B);
MS2_REPLACE(0x141425220, FUN_141425220, 383, 0x40E9CB45);
MS2_REPLACE(0x1414253B0, FUN_1414253b0, 383, 0xCD4D1901);
MS2_REPLACE(0x141425540, FUN_141425540, 194, 0xDAD8B5AA);
MS2_REPLACE(0x141425610, FUN_141425610, 301, 0x63D9CFC7);
MS2_REPLACE(0x141425750, FUN_141425750, 385, 0x1489E13A);
MS2_REPLACE(0x1414258E0, FUN_1414258e0, 103, 0xD2DD71BB);
MS2_REPLACE(0x141425950, FUN_141425950, 679, 0xA7CF1E8C);
MS2_REPLACE(0x141425C00, FUN_141425c00, 559, 0xC16BED4A);
MS2_REPLACE(0x141425E40, FUN_141425e40, 367, 0x07FC4250);
MS2_REPLACE(0x141425FC0, FUN_141425fc0, 377, 0xA4FE0BD1);
MS2_REPLACE_METHOD(0x141426140, CItemUgcMeshContainer, FUN_141426140, 31, 0x3504FA6E);
MS2_REPLACE_METHOD(0x141426540, CItemUgcMeshContainer, FUN_141426540, 517, 0xB00154AD);
MS2_REPLACE_METHOD(0x141426750, CItemUgcMeshContainer, FUN_141426750, 173, 0x4E7801C6);
MS2_REPLACE_METHOD(0x141426810, CItemUgcMeshContainer, FUN_141426810, 351, 0x90AA05A9);
MS2_REPLACE_METHOD(0x141426980, CItemUgcMeshContainer, FUN_141426980, 355, 0x097141C4);
MS2_REPLACE_METHOD(0x141426AF0, CItemUgcMeshContainer, FUN_141426af0, 574, 0x0C2F36BD);
MS2_REPLACE_METHOD(0x141426D40, CItemUgcMeshContainer, FUN_141426d40, 234, 0xA6B44080);
MS2_REPLACE_METHOD(0x141426E30, CItemUgcMeshContainer, FUN_141426e30, 476, 0x58A38968);

// Model path with its variant letter replaced (the letter FUN_141421740 finds); sits just before this TU's range start.
// MS2-RANGE: 0x1414218c0-0x141421ab0 .text$mn
CString FUN_141421740(const CString& strPath, int* pnFlag);            // the variant letter of a model path

// @0x1414218c0
CString FUN_1414218c0(const CString& strPath, const CString& strSuffix)
{
    int nIndex = 0;
    FUN_141421740(strPath, &nIndex);
    CString strLetter(strSuffix);
    CString strResult;
    strResult = strPath.Left(nIndex);
#ifdef __clang__
    // clang otherwise emits an unavailable CopyChars DLL import; bind the exe's operator+.
    strResult = FUN_1401d2b10(strResult, strLetter);
    strResult = FUN_1401d2b10(strResult, strPath.Right(strPath.GetLength() - nIndex - 1));
#else
    strResult = strResult + strLetter;
    strResult = strResult + strPath.Right(strPath.GetLength() - nIndex - 1);
#endif
    return strResult;
}
MS2_REPLACE(0x1414218C0, FUN_1414218c0, 477, 0x1EC93043);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb21e0-0x142cb2230 .text$yd
