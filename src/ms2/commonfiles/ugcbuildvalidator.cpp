// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CUGCBuildValidator / CUGCBuildValidatorCli: the UGC cube
// placement validator (ugcbuildvalidator.h). The base class drives the checks of each build mode through virtual
// slots; the client class implements them against the cube service and the local player.
// MS2-UNIT: ?\ugcbuildvalidator.cpp
// MS2-RANGE: 0x1408806b0-0x140885f20 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$MS2Ptr@VUnk_BackUpItem@@@@QEAA@AEBV0@@Z 0x140884f30 ; unique
// MS2-PIN: ??R?$less@H@std@@QEBA_NAEBH0@Z 0x140885490 ; unique
// MS2-PIN: ?FreeNode@?$CAtlList@V?$MS2Ptr@VUnk_BackUpItem@@@@V?$CElementTraits@V?$MS2Ptr@VUnk_BackUpItem@@@@@ATL@@@ATL@@AEAAXPEAVCNode@12@@Z 0x140885590 ; unique
// MS2-PIN: ?GetAt@?$CAtlList@V?$MS2Ptr@VUnk_BackUpItem@@@@V?$CElementTraits@V?$MS2Ptr@VUnk_BackUpItem@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@VUnk_BackUpItem@@@@PEAU__POSITION@@@Z 0x140885600 ; unique
// MS2-PIN: ?GetNext@?$CAtlList@V?$MS2Ptr@VUnk_BackUpItem@@@@V?$CElementTraits@V?$MS2Ptr@VUnk_BackUpItem@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@VUnk_BackUpItem@@@@AEAPEAU__POSITION@@@Z 0x140885680 ; unique
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x1408858e0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@H@2@XZ 0x140885980 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@H@2@XZ 0x140885990 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@$0A@@std@@@std@@QEAAAEAU?$less@H@2@XZ 0x1408859e0 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@$0A@@std@@@std@@QEBAAEBU?$less@H@2@XZ 0x140885a00 ; prop
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@std@@@std@@@2@AEBH@Z 0x140885ca0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\ugcbuildvalidator.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <map>
#include <atlcoll.h>
#include <efd/ISystemService.h>
#include <efd/ServiceManager.h>
#include "ms2/commonfiles/ugcbuildvalidator.h"
#include "ms2/commonfiles/fielddata.h"
#include "ms2/client/ms2/fielddatacli.h"
#include "ms2/placeholder/mypc.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- externs used by the validator ----
class PCBase;
class Unk_CubeCraftCore;
class Unk_PCItems;
class Unk_IngItem;
class Unk_BackUpItem;
class Unk_ItemSub;

// The application service (class id 0x06100017): the cube service. The cube grid lives in it.
class Unk_Service6100017 : public efd::ISystemService
{
public:
    static const efd::ClassID CLASS_ID = 0x06100017;
    Cube* FUN_1410b8a60(Unk_CubePoint point);                        // the cube at a grid point
    Cube* FUN_1410b8b00(int nKey);
    Cube* FUN_1410b8790(Unk_CubePoint point);
    Unk_CubePoint FUN_1410bab50(Unk_CubePoint point, int nDirection);     // the neighbour of a point in a direction
    std::map<int, MS2Ptr<Cube> >* FUN_1410b7fe0(int nKey);      // the cubes stacked in one column
    bool FUN_1410b82c0(MS2Ptr<Cube> spCube);                    // by value: the callee releases it
    int FUN_1410b9b20(int nItemId);
    __int64 FUN_1410c8030(int x, int y);                        // the owner of the cube column
    bool FUN_1410c3600(int nRule);
    bool FUN_1410d55d0(int nMapId, int x);
    int FUN_1410d2590(Unk_CubePoint point, int x, int y);
    int FUN_1410d2730(Unk_CubePoint point);
    int FUN_1410d27c0(__int64 nOwner, int nKind, int* pA, int* pB);
    int FUN_1410d2da0(int x, Unk_CubePoint point);
    int FUN_1410d2f40(int nKey);
};
struct Unk_EntityAppFramework { efd::ServiceManagerPtr manager; };
extern Unk_EntityAppFramework DAT_143b059e8;
Unk_Service6100017* FUN_1401cd040(Unk_EntityAppFramework*);

class Unk_QueryObj { public: virtual ~Unk_QueryObj(); virtual void vf1(); virtual void vf2(); virtual void vf3(); virtual void vf4(); virtual bool FUN_x28(unsigned nId, void* pOut); };

// WorldService singleton (FUN_1403ed2d0): the current world, the local player and the current field.
class Unk_1403ed2d0
{
public:
    PCBase* FUN_141bd0cc0();                                    // the local player
    int FUN_141bd3060();                                        // the current map id
    MS2Ptr<CFieldDataCli> FUN_141bd30a0();                      // the current field data
    Unk_QueryObj* FUN_141bd1530(unsigned __int64 nEntityId);
};
Unk_1403ed2d0* FUN_1403ed2d0();
Unk_CubeCraftCore* FUN_141530290(PCBase*);
int FUN_1410a8a90(Unk_CubeCraftCore*);
int FUN_1410a8ab0(Unk_CubeCraftCore*);
bool FUN_1415302e0(PCBase*, int nItemId);
__int64 FUN_141656ad0(PCBase*);
bool FUN_140930d20(__int64 nOwner);
bool FUN_140930c90(__int64 nOwner);
bool FUN_14092f660();
bool FUN_1408a07b0(int nMapId, int a, __int64 b);
extern int DAT_143ae0fb4;
extern int DAT_1439f4a7c;
extern __int64 DAT_143ab2820;

// item / cube helpers
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
int FUN_14053c5e0(CItemData*);
bool FUN_14053d6f0(CItemData*);
unsigned FUN_140548cb0(ItemInstallData*);
unsigned FUN_1408a0190(int);
int FUN_1408a03c0(Unk_CubePoint point);
unsigned FUN_1408b4e90(Cube*);
int FUN_1408b4f20(Cube*);
int FUN_1407072e0(int);
int FUN_1407075a0(unsigned);
int FUN_1408b5620(int nItemId);
int FUN_1408b5820(int nItemId);
int FUN_1408b54c0(int nItemId);
int FUN_1408b5570(int nItemId);
int FUN_1408b5e10(int nItemId);
int FUN_1408b5ec0(int nItemId);
int FUN_1408b5f70(int nItemId);
int FUN_1408b5770(int nItemId);
int FUN_1408b53d0(int nItemId);
int FUN_1408b5480(int nItemId);
int FUN_1408b6120(int nItemId);
int FUN_1408b61c0(int nItemId);
int FUN_14053f9c0(int nItemId);

// the cube recipe tables
class Unk_IngItem : public CPtred { public: char unknown18[0x36]; unsigned char m_bFree; };    // +0x4e
class Unk_IngTable { public: MS2Ptr<Unk_IngItem> FUN_1405566e0(int nItemId); };
Unk_IngTable* FUN_140281980();
class Unk_CubeFallbackInventory { public: int FUN_1408fc1b0(int nItemId); };
extern Unk_CubeFallbackInventory DAT_143ab2e20;
class Unk_CubeStock { public: int FUN_140dfcb00(int nItemId); };
extern Unk_CubeStock DAT_143ab2e50;

// the backup item list of the local player
class Unk_ItemSub : public CPtred {};
class Unk_BackUpItem : public CPtred { public: MS2Ptr<Unk_ItemSub> FUN_1411dc7a0(); };
Unk_PCItems* FUN_1416561a0(MyPC*);
void FUN_1411e1b80(Unk_PCItems*, ATL::CAtlList<MS2Ptr<Unk_BackUpItem> >*);

// Template glue of the Cube map (std::map<int, MS2Ptr<Cube> > iterator/pointer helpers), spelled as plain functions.
typedef std::pair<const int, MS2Ptr<Cube> > Unk_CubeEntry;
void FUN_140885810(MS2Ptr<Cube>* pPtr);
Unk_CubeEntry* FUN_1408853a0(void* pIter);

// @0x140884eb0
Unk_CubeEntry* FUN_140884eb0(Unk_CubeEntry* pEntry)
{
    return pEntry;
}

// @0x140884f70
MS2Ptr<Cube>* FUN_140884f70(MS2Ptr<Cube>* pDst, const MS2Ptr<Cube>* pSrc)
{
    *(Cube**)((char*)pDst + 8) = *(Cube**)((char*)pSrc + 8);
    FUN_140885810(pDst);
    return pDst;
}

// @0x140885320
Cube* FUN_140885320(const MS2Ptr<Cube>* pPtr)
{
    return *(Cube**)((char*)pPtr + 8);
}

// @0x140885de0
Unk_CubeEntry* FUN_140885de0(Unk_CubeEntry* pEntry)
{
    return FUN_140884eb0(pEntry);
}

// @0x140885360
Unk_CubeEntry* FUN_140885360(void* pIter)
{
    return FUN_140885de0(FUN_1408853a0(pIter));
}

// @0x140885e00
// MS2-FUNCTIONAL: inlined CRT memcpy_s copy
errno_t FUN_140885e00(void* const d, size_t const dsz, void const* const s, size_t const ssz)
{
    if (ssz == 0) { return 0; }
    { int e = !!(d != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    if (s == NULL || dsz < ssz)
    {
        memset(d, 0, dsz);
        { int e = !!(s != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
        { int e = !!(dsz >= ssz); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
        return EINVAL;
    }
    memcpy(d, s, ssz);
    return 0;
}

// @0x140884db0
MyPC* FUN_140884db0(Unk_QueryObj* pObj)
{
    MyPC* pPC = 0;
    if (pObj != 0 && pObj->FUN_x28(0x6200046, &pPC))
        return pPC;
    else
        return 0;
}

// @0x1408850a0 is Unk_CubePoint::Unk_CubePoint (ugcbuildvalidator.h)

// @0x1408806b0
CUGCBuildValidator::CUGCBuildValidator(Unk_CubePoint point, CubeItemInfo* pItem, int nDirection)
{
    m_point = point;
    m_pItem = pItem;
    m_nDirection = nDirection;
    m_pCube = 0;
}

// @0x140880750
CUGCBuildValidator::~CUGCBuildValidator()
{
}

// @0x140880790
int CUGCBuildValidator::vfunc_1(int nMode, unsigned* pErr)
{
    m_nMode = nMode;
    if (FUN_140880890() == 0)
    {
        *pErr = 0x2a;
        return 0;
    }
    if (FUN_1408808d0() == 0)
    {
        *pErr = 3;
        return 0;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x140880790, CUGCBuildValidator, vfunc_1, 98, 0x853286E6);

// @0x140880800
int CUGCBuildValidator::vfunc_32(unsigned* pErr)
{
    *pErr = 0x62;
    if (m_itemData == 0 || m_pItem == 0)
        return 0;
    if (!FUN_14053d6f0(m_itemData.operator->()) || m_pItem->FUN_1408b3860() == 1)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x140880800, CUGCBuildValidator, vfunc_32, 132, 0xB67FF895);

// @0x140880890
int CUGCBuildValidator::FUN_140880890()
{
    if (m_nMode == 4 || m_nMode == 5)
        return 1;
    if (m_pItem == 0)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140880890, CUGCBuildValidator, FUN_140880890, 56, 0x794A9579);

// @0x1408808d0
int CUGCBuildValidator::FUN_1408808d0()
{
    if (m_nMode == 4 || m_nMode == 5)
        return 1;
    if (m_pItem == 0)
        return 0;
    m_itemData = FUN_14053f870(m_pItem->itemId);
    if (!m_itemData)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1408808d0, CUGCBuildValidator, FUN_1408808d0, 171, 0xD5C421FB);

// @0x140880990
int CUGCBuildValidator::FUN_140880990()
{
    Cube* pCube = vfunc_34();
    if (pCube == 0)
        return 0;
    if (pCube->field68 == 0)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140880990, CUGCBuildValidator, FUN_140880990, 70, 0x0A914660);

// @0x1408809e0
int CUGCBuildValidator::FUN_1408809e0()
{
    return m_nMode;
}
MS2_REPLACE_METHOD(0x1408809e0, CUGCBuildValidator, FUN_1408809e0, 14, 0xCAA08B3B);

// @0x140880a00 mode 1: build
int CUGCBuildValidator::vfunc_36(unsigned* pErr)
{
    if (vfunc_1(1, pErr) == 0)
        return 0;
    if (vfunc_33() != 0)
    {
        *pErr = 2;
        return 0;
    }
    m_pCube = vfunc_34();
    if (m_pCube == 0)
    {
        *pErr = 7;
        return 0;
    }
    if (vfunc_27(pErr) == 0) return 0;
    if (vfunc_10(pErr) == 0) return 0;
    if (vfunc_32(pErr) == 0) return 0;
    if (vfunc_3(pErr) == 0) return 0;
    if (vfunc_6(pErr) == 0) return 0;
    if (vfunc_4(pErr) == 0) return 0;
    if (vfunc_5(pErr) == 0) return 0;
    if (vfunc_8(pErr) == 0) return 0;
    if (vfunc_7(pErr) == 0) return 0;
    if (vfunc_29(pErr) == 0) return 0;
    if (vfunc_9(pErr) == 0) return 0;
    if (vfunc_25(pErr) == 0) return 0;
    if (vfunc_2(pErr) == 0) return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140880a00, CUGCBuildValidator, vfunc_36, 574, 0xFEFB3EBF);

// @0x140880c50 mode 3
int CUGCBuildValidator::vfunc_37(unsigned* pErr)
{
    if (vfunc_1(3, pErr) == 0)
        return 0;
    if (vfunc_33() != 0)
    {
        *pErr = 2;
        return 0;
    }
    if (vfunc_28(pErr) == 0) return 0;
    if (vfunc_3(pErr) == 0) return 0;
    if (vfunc_6(pErr) == 0) return 0;
    if (vfunc_4(pErr) == 0) return 0;
    if (vfunc_35() == 0)
    {
        *pErr = 0x10;
        return 0;
    }
    if (vfunc_17(pErr) == 0) return 0;
    if (vfunc_15(pErr) == 0) return 0;
    if (vfunc_12(pErr) == 0) return 0;
    if (vfunc_30(pErr) == 0) return 0;
    if (vfunc_26(pErr) == 0) return 0;
    if (vfunc_2(pErr) == 0) return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140880c50, CUGCBuildValidator, vfunc_37, 461, 0x95DB46A4);

// @0x140880e30 mode 2
int CUGCBuildValidator::vfunc_38(unsigned* pErr)
{
    if (vfunc_1(2, pErr) == 0)
        return 0;
    if (vfunc_33() == 0)
    {
        *pErr = 0x1c;
        return 0;
    }
    if (vfunc_8(pErr) == 0) return 0;
    if (vfunc_27(pErr) == 0) return 0;
    if (vfunc_32(pErr) == 0) return 0;
    if (vfunc_3(pErr) == 0) return 0;
    if (vfunc_6(pErr) == 0) return 0;
    if (vfunc_4(pErr) == 0) return 0;
    if (vfunc_35() != 0)
    {
        *pErr = 0x1d;
        return 0;
    }
    if (vfunc_11(pErr) == 0) return 0;
    if (vfunc_13(pErr) == 0) return 0;
    if (vfunc_31(pErr) == 0) return 0;
    if (vfunc_9(pErr) == 0) return 0;
    if (vfunc_25(pErr) == 0) return 0;
    if (vfunc_2(pErr) == 0) return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140880e30, CUGCBuildValidator, vfunc_38, 525, 0xCF6F0334);

// @0x140881050 mode 2 (move)
int CUGCBuildValidator::vfunc_39(unsigned* pErr)
{
    if (vfunc_1(2, pErr) == 0)
        return 0;
    if (vfunc_33() == 0)
    {
        *pErr = 0x1c;
        return 0;
    }
    if (vfunc_28(pErr) == 0) return 0;
    if (vfunc_3(pErr) == 0) return 0;
    if (vfunc_6(pErr) == 0) return 0;
    if (vfunc_4(pErr) == 0) return 0;
    if (vfunc_17(pErr) == 0) return 0;
    if (vfunc_35() == 0)
    {
        *pErr = 0x10;
        return 0;
    }
    if (vfunc_15(pErr) == 0) return 0;
    if (vfunc_11(pErr) == 0) return 0;
    if (vfunc_12(pErr) == 0) return 0;
    if (vfunc_14(pErr) == 0) return 0;
    if (vfunc_26(pErr) == 0) return 0;
    if (vfunc_2(pErr) == 0) return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140881050, CUGCBuildValidator, vfunc_39, 490, 0x10689660);

// @0x140881240 mode 4
int CUGCBuildValidator::vfunc_40(unsigned* pErr)
{
    if (vfunc_1(4, pErr) == 0)
        return 0;
    if (vfunc_33() == 0)
    {
        *pErr = 0x14;
        return 0;
    }
    if (vfunc_27(pErr) == 0) return 0;
    if (vfunc_11(pErr) == 0) return 0;
    if (vfunc_18(pErr) == 0) return 0;
    if (vfunc_19(pErr) == 0) return 0;
    if (vfunc_20(pErr) == 0) return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140881240, CUGCBuildValidator, vfunc_40, 263, 0xD15BD204);

// @0x140881350 mode 5
int CUGCBuildValidator::vfunc_41(unsigned* pErr)
{
    if (vfunc_1(5, pErr) == 0)
        return 0;
    if (vfunc_33() == 0)
    {
        *pErr = 0x14;
        return 0;
    }
    if (vfunc_28(pErr) == 0) return 0;
    if (vfunc_11(pErr) == 0) return 0;
    if (vfunc_22(pErr) == 0) return 0;
    if (vfunc_23(pErr) == 0) return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140881350, CUGCBuildValidator, vfunc_41, 228, 0xE21EE792);

// @0x140881440 mode 6
int CUGCBuildValidator::vfunc_42(unsigned* pErr)
{
    if (vfunc_18(pErr) == 0)
    {
        *pErr = 0x1b;
        return 0;
    }
    if (vfunc_1(6, pErr) == 0)
        return 0;
    if (vfunc_33() == 0)
    {
        *pErr = 0x1a;
        return 0;
    }
    if (vfunc_27(pErr) == 0) return 0;
    if (vfunc_11(pErr) == 0) return 0;
    if (vfunc_35() != 0)
    {
        *pErr = 0x3b;
        return 0;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x140881440, CUGCBuildValidator, vfunc_42, 245, 0x7D9E5EE4);

// ---- CUGCBuildValidatorCli ----

// @0x140881540
CUGCBuildValidatorCli::CUGCBuildValidatorCli(Unk_CubePoint point, CubeItemInfo* pItem)
    : CUGCBuildValidator(point, pItem, 0), m_pCubeService(0)
{
    m_pCubeService = FUN_1401cd040(&DAT_143b059e8);
}

// @0x1408815e0
CUGCBuildValidatorCli::CUGCBuildValidatorCli(Unk_CubePoint point, CubeItemInfo* pItem, int nDirection)
    : CUGCBuildValidator(point, pItem, nDirection), m_pCubeService(0)
{
    m_pCubeService = FUN_1401cd040(&DAT_143b059e8);
}

// @0x140881690
CUGCBuildValidatorCli::~CUGCBuildValidatorCli()
{
}

// @0x1408816d0
int CUGCBuildValidatorCli::vfunc_1(int nMode, unsigned* pErr)
{
    if (CUGCBuildValidator::vfunc_1(nMode, pErr) == 0)
        return 0;
    PCBase* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
    {
        *pErr = 0x33;
        return 0;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1408816d0, CUGCBuildValidatorCli, vfunc_1, 96, 0x9727CD25);

// @0x140881740
int CUGCBuildValidatorCli::vfunc_2(unsigned* pErr)
{
    *pErr = 4;
    if (m_pItem == 0)
        return 0;
    PCBase* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    if (FUN_141530290(pPC) == 0)
        return 0;
    Unk_CubeCraftCore* pCore = FUN_141530290(pPC);
    if (pCore != 0 && FUN_1410a8ab0(pCore) == 0 && FUN_1415302e0(pPC, m_pItem->itemId))
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140881740, CUGCBuildValidatorCli, vfunc_2, 170, 0x860C140F);

// @0x1408817f0
int CUGCBuildValidatorCli::vfunc_3(unsigned* pErr)
{
    *pErr = 0x5b;
    if (m_pItem == 0)
        return 0;
    PCBase* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    if (FUN_141530290(pPC) == 0)
        return 0;
    if (FUN_1410a8a90(FUN_141530290(pPC)) != 2)
    {
        MS2Ptr<CItemData> spData = FUN_14053f870(m_pItem->itemId);
        if (spData == 0)
            return 0;
        MS2Ptr<Unk_IngItem> spIng = FUN_140281980()->FUN_1405566e0(m_pItem->itemId);
        if (spIng == 0)
            return 0;
        if (spIng->m_bFree != 0)
            return 1;
        int nTotal = DAT_143ab2e20.FUN_1408fc1b0(m_pItem->itemId);
        nTotal += DAT_143ab2e50.FUN_140dfcb00(m_pItem->itemId);
        int nLimit = m_pCubeService->FUN_1410b9b20(m_pItem->itemId);
        if (nLimit >= nTotal)
            return 0;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1408817f0, CUGCBuildValidatorCli, vfunc_3, 577, 0xB012E282);

// @0x140881a40
int CUGCBuildValidatorCli::vfunc_4(unsigned* pErr)
{
    *pErr = 6;
    if (!m_itemData != 0)
        return 0;
    PCBase* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    if (FUN_141530290(pPC) == 0)
        return 0;
    int nMapId = FUN_1403ed2d0()->FUN_141bd3060();
    if (FUN_1410a8a90(FUN_141530290(pPC)) != 2 && FUN_14092f660() && !CFieldData::FUN_140374410(nMapId))
        return 0;
    MS2Ptr<CFieldDataCli> spField = FUN_1403ed2d0()->FUN_141bd30a0();
    if (!spField != 0 || spField->m_nIndoorMask != (spField->m_nIndoorMask & m_itemData->install.space))
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140881a40, CUGCBuildValidatorCli, vfunc_4, 354, 0x47396F7C);

// @0x140881bb0
int CUGCBuildValidatorCli::vfunc_5(unsigned* pErr)
{
    *pErr = 5;
    PCBase* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    if (FUN_141530290(pPC) == 0)
        return 0;
    if (FUN_1410a8a90(FUN_141530290(pPC)) == 2)
    {
        if ((m_itemData->install.placeable & m_pCube->field44) == 0)
            return 0;
        if ((FUN_1408b4e90(m_pCube) & FUN_1408a0190(FUN_14053c5e0(m_itemData.operator->()))) == 0)
            return 0;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x140881bb0, CUGCBuildValidatorCli, vfunc_5, 221, 0x5F32F258);

// @0x140881ca0
int CUGCBuildValidatorCli::vfunc_6(unsigned* pErr)
{
    *pErr = 0x5f;
    if (m_pItem == 0)
        return 0;
    int nX = 0;
    int nY = 0;
    Cube* pCube = vfunc_34();
    if (pCube == 0)
        pCube = vfunc_33();
    if (pCube != 0)
    {
        nX = pCube->field50;
        nY = pCube->field54;
    }
    int nMapId = FUN_1403ed2d0()->FUN_141bd3060();
    if (m_pCubeService->FUN_1410d55d0(nMapId, nX) || FUN_1408a07b0(nMapId, DAT_1439f4a7c, DAT_143ab2820))
    {
        if (FUN_1408b5620(m_pItem->itemId) != 0) return 0;
        if (FUN_1408b5820(m_pItem->itemId) != 0) return 0;
        if (FUN_1408b54c0(m_pItem->itemId) != 0) return 0;
        if (FUN_1408b5570(m_pItem->itemId) != 0) return 0;
        if (FUN_1408b5e10(m_pItem->itemId) != 0) return 0;
        if (FUN_1408b5ec0(m_pItem->itemId) != 0) return 0;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x140881ca0, CUGCBuildValidatorCli, vfunc_6, 402, 0x290CD813);

// @0x140881e40
int CUGCBuildValidatorCli::vfunc_7(unsigned* pErr)
{
    *pErr = 0x2b;
    if (m_pCube == 0)
        return 0;
    if (m_pCubeService->FUN_1410d2590(m_point, m_pCube->field50, m_pCube->field54) == 0)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140881e40, CUGCBuildValidatorCli, vfunc_7, 160, 0xAF8A819A);

// @0x140881ef0
int CUGCBuildValidatorCli::vfunc_8(unsigned* pErr)
{
    *pErr = 0x2c;
    if (m_pCubeService->FUN_1410d2730(m_point) == 0)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140881ef0, CUGCBuildValidatorCli, vfunc_8, 101, 0xD01F204A);

// @0x140881f60
// MS2-FUNCTIONAL: exe frame/early global check differs; branch layout not reproduced
int CUGCBuildValidatorCli::vfunc_9(unsigned* pErr)
{
    *pErr = 0x2d;
    if (m_pItem == 0)
        return 0;
    PCBase* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    if (DAT_143ae0fb4 != 0)
        return 1;
    int nA, nB;
    if (FUN_14053f9c0(m_pItem->itemId) != 0)
    {
        if (m_pCubeService->FUN_1410d27c0(FUN_141656ad0(pPC), 0, &nA, &nB) == 0)
            return 0;
    }
    if (FUN_1408b5820(m_pItem->itemId) != 0)
    {
        *pErr = 0x4b;
        if (m_pCubeService->FUN_1410d27c0(FUN_141656ad0(pPC), 2, &nA, &nB) == 0)
            return 0;
    }
    if (FUN_1408b5f70(m_pItem->itemId) != 0)
    {
        *pErr = 99;
        if (m_pCubeService->FUN_1410d27c0(FUN_141656ad0(pPC), 4, &nA, &nB) == 0)
            return 0;
    }
    if (m_pCubeService->FUN_1410c3600(1))
    {
        if (FUN_1408b5620(m_pItem->itemId) != 0)
        {
            *pErr = 0x5d;
            return 0;
        }
        if (FUN_1408b5770(m_pItem->itemId) != 0)
        {
            *pErr = 0x65;
            return 0;
        }
    }
    if (m_pCubeService->FUN_1410c3600(3))
    {
        if (FUN_1408b53d0(m_pItem->itemId) != 0)
        {
            *pErr = 0x5c;
            return 0;
        }
        if (FUN_1408b5480(m_pItem->itemId) == 0)
        {
            *pErr = 0x5c;
            return 0;
        }
        if (FUN_1408b6120(m_pItem->itemId) != 0)
        {
            *pErr = 0x6c;
            return 0;
        }
        if (FUN_1408b61c0(m_pItem->itemId) != 0)
        {
            *pErr = 0x6b;
            return 0;
        }
        if (m_pItem->FUN_1408b3860() != 0)
        {
            if (m_pCubeService->FUN_1410c3600(3) && m_pItem->look.get() != 0)
            {
                __int64 nLookOwner = m_pItem->look->m_n34;
                if (nLookOwner != FUN_141656ad0(pPC))
                {
                    *pErr = 0x6f;
                    return 0;
                }
            }
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x140881f60, CUGCBuildValidatorCli, vfunc_9, 963, 0x92D73043);

// @0x140882340
// MS2-FUNCTIONAL: the exe shares one 'return 1' block for the owner match and the tail; not reproduced
int CUGCBuildValidatorCli::vfunc_10(unsigned* pErr)
{
    *pErr = 8;
    MS2Ptr<Cube> spCube(vfunc_34());
    if (!spCube != 0)
        return 0;
    PCBase* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    if (DAT_143ae0fb4 != 0)
        return 1;
    int nMapId = FUN_1403ed2d0()->FUN_141bd3060();
    if (FUN_1408a07b0(nMapId, DAT_1439f4a7c, DAT_143ab2820))
        return 1;
    __int64 nOwner = m_pCubeService->FUN_1410c8030(spCube->field50, spCube->field54);
    if (nOwner == FUN_141656ad0(pPC))
        return 1;
    if (m_pCubeService->FUN_1410d55d0(nMapId, spCube->field50) && FUN_140930d20(nOwner))
        return 1;
    if (FUN_140930c90(nOwner) == 0)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140882340, CUGCBuildValidatorCli, vfunc_10, 582, 0x7BB7B380);

// @0x140882590
// MS2-FUNCTIONAL: the exe shares one 'return 1' block for the owner match and the tail; not reproduced
int CUGCBuildValidatorCli::vfunc_11(unsigned* pErr)
{
    *pErr = 8;
    MS2Ptr<Cube> spCube(m_pCubeService->FUN_1410b8a60(m_point));
    if (!spCube != 0)
        return 0;
    PCBase* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    if (DAT_143ae0fb4 != 0)
        return 1;
    int nMapId = FUN_1403ed2d0()->FUN_141bd3060();
    if (FUN_1408a07b0(nMapId, DAT_1439f4a7c, DAT_143ab2820))
        return 1;
    __int64 nOwner = m_pCubeService->FUN_1410c8030(spCube->field50, spCube->field54);
    if (nOwner == FUN_141656ad0(pPC))
        return 1;
    if (m_pCubeService->FUN_1410d55d0(nMapId, spCube->field50) && FUN_140930d20(nOwner))
        return 1;
    if (FUN_140930c90(nOwner) == 0)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140882590, CUGCBuildValidatorCli, vfunc_11, 627, 0x62E95A64);

// @0x140882810
int CUGCBuildValidatorCli::vfunc_12(unsigned* pErr)
{
    *pErr = 8;
    MS2Ptr<Cube> spCube(m_pCubeService->FUN_1410b8a60(m_pCubeService->FUN_1410bab50(m_point, m_nDirection)));
    if (!spCube != 0)
        return 0;
    PCBase* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    if (DAT_143ae0fb4 != 0)
        return 1;
    if (m_pCubeService->FUN_1410c8030(spCube->field50, spCube->field54) != FUN_141656ad0(pPC))
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140882810, CUGCBuildValidatorCli, vfunc_12, 482, 0xB355055B);

// @0x140882a00
// MS2-FUNCTIONAL: exe keeps an extra stack slot; local layout not reproduced
int CUGCBuildValidatorCli::vfunc_13(unsigned* pErr)
{
    *pErr = 0x1d;
    MS2Ptr<Cube> spCube(m_pCubeService->FUN_1410b8a60(m_point));
    if (!spCube != 0)
        return 0;
    int nCategory = FUN_1408a0190(FUN_14053c5e0(m_itemData.operator->()));
    if (nCategory != spCube->field44)
        return 0;
    if (spCube->field64 != 0 || m_itemData->install.unchangeable != 0)
    {
        *pErr = 0x3a;
        return 0;
    }
    m_pCube = vfunc_34();
    PCBase* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    if (FUN_141530290(pPC) == 0)
        return 0;
    if (FUN_1410a8a90(FUN_141530290(pPC)) == 2 && m_pCube != 0)
    {
        if ((m_itemData->install.placeable & m_pCube->field44) == 0)
            return 0;
        if ((FUN_1408b4e90(m_pCube) & FUN_1408a0190(FUN_14053c5e0(m_itemData.operator->()))) == 0)
            return 0;
    }
    if (spCube->field68 != 0)
    {
        if (m_pCubeService->FUN_1410b82c0(spCube))
        {
            if (m_itemData->install.wall == 0)
            {
                *pErr = 0x1e;
                return 0;
            }
            std::map<int, MS2Ptr<Cube> >* pColumn = m_pCubeService->FUN_1410b7fe0(FUN_1408a03c0((Unk_CubePoint&)spCube->position));
            for (std::map<int, MS2Ptr<Cube> >::iterator it = pColumn->begin(); it != pColumn->end(); ++it)
            {
                MS2Ptr<Cube> spOther = (*it).second;
                if ((spOther->field60 & FUN_1408a0190(FUN_14053c5e0(m_itemData.operator->()))) == 0)
                {
                    *pErr = 0x1e;
                    return 0;
                }
            }
        }
    }
    if (spCube->field48 != 0)
    {
        MS2Ptr<CItemData> spData = FUN_14053f870(FUN_1408b4f20(spCube.operator->()));
        if (spData.get() != 0 && spData->install.attachable != 0)
        {
            *pErr = 0x1d;
            return 0;
        }
    }
    Unk_CubePoint above = m_point;
    above.z = above.z + 1;
    MS2Ptr<Cube> spAbove(m_pCubeService->FUN_1410b8a60(above));
    if (spAbove.get() != 0)
    {
        if ((FUN_140548cb0(&m_itemData->install) & spAbove->field44) == 0)
        {
            *pErr = 0x1f;
            return 0;
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x140882a00, CUGCBuildValidatorCli, vfunc_13, 1727, 0x3788507E);

// @0x1408830d0
// MS2-FUNCTIONAL: exe keeps an extra stack slot; local layout not reproduced
int CUGCBuildValidatorCli::vfunc_14(unsigned* pErr)
{
    *pErr = 0x1d;
    MS2Ptr<CFieldDataCli> spField = FUN_1403ed2d0()->FUN_141bd30a0();
    if (!spField == 0)
        return 0;
    MS2Ptr<Cube> spCube(m_pCubeService->FUN_1410b8a60(m_point));
    if (!spCube == 0)
        return 0;
    int nCategory = FUN_1408a0190(FUN_14053c5e0(m_itemData.operator->()));
    if (nCategory != spCube->field44)
        return 0;
    if (spCube->field64 == 0 && m_itemData->install.unchangeable == 0)
    {
        if (spCube->field48 != 0)
        {
            MS2Ptr<CItemData> spData = FUN_14053f870(FUN_1408b4f20(spCube.operator->()));
            if (spData.get() != 0 && spData->install.attachable == 0)
            {
                *pErr = 0x1d;
                return 0;
            }
        }
        return 1;
    }
    *pErr = 0x3a;
    return 0;
}
MS2_REPLACE_METHOD(0x1408830d0, CUGCBuildValidatorCli, vfunc_14, 655, 0x9B822037);

// @0x140883370
int CUGCBuildValidatorCli::vfunc_15(unsigned* pErr)
{
    *pErr = 0x12;
    if (!m_itemData != 0)
        return 0;
    Unk_CubePoint next = m_pCubeService->FUN_1410bab50(m_point, m_nDirection);
    if (m_pCubeService->FUN_1410b8a60(next) == 0)
        return 0;
    if ((m_itemData->install.attachable & m_pCubeService->FUN_1410b8a60(next)->field44) == 0)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140883370, CUGCBuildValidatorCli, vfunc_15, 322, 0x0CDE86A6);

// @0x1408834c0
int CUGCBuildValidatorCli::vfunc_16(unsigned* pErr)
{
    *pErr = 0x13;
    if ((Unk_Service6100017*)m_pCubeService == 0)
        return 0;
    std::map<int, MS2Ptr<Cube> >* pColumn = m_pCubeService->FUN_1410b7fe0(FUN_1408a03c0(m_point));
    if (pColumn->find(m_nDirection) != pColumn->end())
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1408834c0, CUGCBuildValidatorCli, vfunc_16, 228, 0x5E3BDC67);

// @0x1408835b0
int CUGCBuildValidatorCli::vfunc_17(unsigned* pErr)
{
    *pErr = 0x11;
    if ((Unk_Service6100017*)m_pCubeService == 0)
        return 0;
    Cube* pCube = m_pCubeService->FUN_1410b8a60(m_pCubeService->FUN_1410bab50(m_point, m_nDirection));
    if (pCube == 0)
        return 0;
    if (pCube->field68 == 0)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1408835b0, CUGCBuildValidatorCli, vfunc_17, 234, 0xDB98255F);

// @0x1408836a0
int CUGCBuildValidatorCli::vfunc_18(unsigned* pErr)
{
    *pErr = 0x28;
    if ((Unk_Service6100017*)m_pCubeService == 0)
        return 0;
    Cube* pCube = m_pCubeService->FUN_1410b8a60(m_point);
    if (pCube == 0)
        return 0;
    if (FUN_1408b4f20(pCube) == 0)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1408836a0, CUGCBuildValidatorCli, vfunc_18, 154, 0x87F2E982);

// @0x140883740
// MS2-FUNCTIONAL: branch layout of the guard chain not reproduced
int CUGCBuildValidatorCli::vfunc_19(unsigned* pErr)
{
    *pErr = 0x29;
    if ((Unk_Service6100017*)m_pCubeService == 0)
        return 0;
    Cube* pCube = m_pCubeService->FUN_1410b8a60(m_point);
    if (pCube == 0)
        return 0;
    if (pCube->field68 != 0)
    {
        std::map<int, MS2Ptr<Cube> >* pColumn = m_pCubeService->FUN_1410b7fe0(FUN_1408a03c0(m_point));
        for (std::map<int, MS2Ptr<Cube> >::iterator it = pColumn->begin(); it != pColumn->end(); ++it)
        {
            Cube* pOther = (*it).second.get();
            if (pOther != 0)
                return 0;
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x140883740, CUGCBuildValidatorCli, vfunc_19, 349, 0xC2AD0930);

// @0x1408838b0
int CUGCBuildValidatorCli::vfunc_20(unsigned* pErr)
{
    *pErr = 0x16;
    if ((Unk_Service6100017*)m_pCubeService == 0)
        return 0;
    Cube* pCube = m_pCubeService->FUN_1410b8a60(m_point);
    if (pCube == 0)
        return 0;
    if (FUN_1408b4f20(pCube) != 0)
    {
        MS2Ptr<CItemData> spData = FUN_14053f870(FUN_1408b4f20(pCube));
        if (spData == 0)
        {
            *pErr = 3;
            return 0;
        }
        PCBase* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPC == 0)
            return 0;
        if (FUN_141530290(pPC) == 0)
            return 0;
        if (FUN_1410a8a90(FUN_141530290(pPC)) == 2)
        {
            MS2Ptr<CFieldDataCli> spField = FUN_1403ed2d0()->FUN_141bd30a0();
            if (!spField != 0)
                return 0;
            if (FUN_140548cb0(&spData->install) != 0)
            {
                if (m_pCubeService->FUN_1410d2f40(FUN_1408a03c0(m_point)) == 0)
                {
                    Unk_CubePoint above = m_point;
                    above.z = above.z + 1;
                    MS2Ptr<Cube> spAbove(m_pCubeService->FUN_1410b8a60(above));
                    if (spAbove.get() != 0 && spAbove->fieldD8 == 0)
                        return 0;
                }
            }
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1408838b0, CUGCBuildValidatorCli, vfunc_20, 818, 0x5B961768);

// @0x140883bf0
int CUGCBuildValidatorCli::vfunc_21(unsigned* pErr)
{
    *pErr = 0x18;
    MS2Ptr<Cube> spCube(m_pCubeService->FUN_1410b8a60(m_point));
    if (!spCube != 0)
        return 0;
    if (spCube->field68 == 0)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140883bf0, CUGCBuildValidatorCli, vfunc_21, 223, 0x2E8450B7);

// @0x140883ce0
int CUGCBuildValidatorCli::vfunc_22(unsigned* pErr)
{
    *pErr = 0x14;
    MS2Ptr<Cube> spCube(m_pCubeService->FUN_1410b8a60(m_point));
    if (!spCube != 0)
        return 0;
    if (spCube->field60 == 0)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140883ce0, CUGCBuildValidatorCli, vfunc_22, 223, 0xE3DEF2ED);

// @0x140883dd0
int CUGCBuildValidatorCli::vfunc_23(unsigned* pErr)
{
    *pErr = 0x19;
    MS2Ptr<Cube> spCube(m_pCubeService->FUN_1410b8a60(m_point));
    if (!spCube != 0)
        return 0;
    PCBase* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    if (m_pCubeService->FUN_1410c8030(spCube->field50, spCube->field54) != FUN_141656ad0(pPC))
    {
        *pErr = 8;
        return 0;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x140883dd0, CUGCBuildValidatorCli, vfunc_23, 380, 0xC9320BDB);

// @0x140883f60
// MS2-FUNCTIONAL: local/branch layout not reproduced
int CUGCBuildValidatorCli::vfunc_24(unsigned* pErr)
{
    *pErr = 0x34;
    MS2Ptr<Cube> spCube(m_pCubeService->FUN_1410b8a60(m_point));
    if (!spCube == 0)
    {
        if (FUN_1407072e0(spCube->fieldB4) == 0)
            return 1;
        MyPC* pMyPC = FUN_140884db0(FUN_1403ed2d0()->FUN_141bd1530(spCube->field18));
        if (pMyPC == 0)
            return 0;
        ATL::CAtlList<MS2Ptr<Unk_BackUpItem> > items(10);
        FUN_1411e1b80(FUN_1416561a0(pMyPC), &items);
        POSITION pos = items.GetHeadPosition();
        while (pos != 0)
        {
            MS2Ptr<Unk_BackUpItem> spItem = items.GetAt(pos);
            if (spItem->FUN_1411dc7a0().get() != 0)
                return 0;
            items.GetNext(pos);
        }
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140883f60, CUGCBuildValidatorCli, vfunc_24, 620, 0x6A0BF06D);

// @0x1408841e0
// MS2-FUNCTIONAL: local/branch layout not reproduced
int CUGCBuildValidatorCli::vfunc_25(unsigned* pErr)
{
    if (FUN_1407075a0(m_itemData->install.objCode) == 0)
        return 1;
    *pErr = 0x40;
    MS2Ptr<CFieldDataCli> spField = FUN_1403ed2d0()->FUN_141bd30a0();
    if (!spField == 0)
    {
        if (spField->FUN_140375130() == 0)
            return 0;
        if (m_pItem == 0)
            return 0;
        PCBase* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPC == 0)
            return 0;
        if (FUN_141530290(pPC) == 0)
            return 0;
        if (DAT_143ae0fb4 != 0)
            return 1;
        if (FUN_1408b5620(m_pItem->itemId) != 0)
        {
            int nA, nB;
            if (m_pCubeService->FUN_1410d27c0(FUN_141656ad0(pPC), 1, &nA, &nB) == 0)
                return 0;
            if (m_pCubeService->FUN_1410d2da0(m_pCube->field50, m_point) == 0)
            {
                *pErr = 0x41;
                return 0;
            }
        }
        if (FUN_1410a8a90(FUN_141530290(pPC)) == 2)
        {
            if (m_pCubeService->FUN_1410d2da0(m_pCube->field50, m_point) == 0)
            {
                *pErr = 0x41;
                return 0;
            }
        }
        if (CFieldData::FUN_140374410(FUN_1403ed2d0()->FUN_141bd3060()) == 0)
            return 0;
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1408841e0, CUGCBuildValidatorCli, vfunc_25, 903, 0x2AA1D42C);

// @0x140884570
// MS2-FUNCTIONAL: local/branch layout not reproduced
int CUGCBuildValidatorCli::vfunc_26(unsigned* pErr)
{
    if (FUN_1407075a0(m_itemData->install.objCode) == 0)
        return 1;
    *pErr = 0x40;
    MS2Ptr<CFieldDataCli> spField = FUN_1403ed2d0()->FUN_141bd30a0();
    if (!spField == 0)
    {
        if (spField->FUN_140375130() == 0)
            return 0;
        if (m_pItem == 0)
            return 0;
        Cube* pCube = m_pCubeService->FUN_1410b8a60(m_pCubeService->FUN_1410bab50(m_point, m_nDirection));
        if (pCube == 0)
            return 0;
        PCBase* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPC == 0)
            return 0;
        if (DAT_143ae0fb4 != 0)
            return 1;
        if (FUN_1408b5620(m_pItem->itemId) != 0)
        {
            int nA, nB;
            if (m_pCubeService->FUN_1410d27c0(FUN_141656ad0(pPC), 1, &nA, &nB) == 0)
                return 0;
        }
        if (m_pCubeService->FUN_1410d2da0(pCube->field50, m_point) == 0)
        {
            *pErr = 0x41;
            return 0;
        }
        if (CFieldData::FUN_140374410(FUN_1403ed2d0()->FUN_141bd3060()) == 0)
            return 0;
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140884570, CUGCBuildValidatorCli, vfunc_26, 860, 0x04B90095);

// @0x1408848e0
int CUGCBuildValidatorCli::vfunc_27(unsigned* pErr)
{
    return 1;
}

// @0x140884900
int CUGCBuildValidatorCli::vfunc_28(unsigned* pErr)
{
    return 1;
}

// @0x140884920
int CUGCBuildValidatorCli::vfunc_29(unsigned* pErr)
{
    *pErr = 0x3d;
    if (m_itemData->install.cannotStackAttach == 0)
        return 1;
    Unk_CubePoint above = m_point;
    above.z = above.z + 1;
    Cube* pCube = m_pCubeService->FUN_1410b8a60(above);
    if (pCube == 0)
        return 1;
    if (pCube->field60 != 0)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140884920, CUGCBuildValidatorCli, vfunc_29, 194, 0xB6302ED6);

// @0x1408849f0
int CUGCBuildValidatorCli::vfunc_30(unsigned* pErr)
{
    *pErr = 0x3e;
    Unk_CubePoint below = m_point;
    below.z = below.z - 1;
    Cube* pCube = m_pCubeService->FUN_1410b8a60(below);
    if (pCube == 0)
        return 1;
    if (pCube->field74 != 0)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1408849f0, CUGCBuildValidatorCli, vfunc_30, 161, 0x22F4CA2B);

// @0x140884aa0
int CUGCBuildValidatorCli::vfunc_31(unsigned* pErr)
{
    *pErr = 0x3f;
    if (m_itemData->install.cannotStackAttach == 0)
        return 1;
    Unk_CubePoint above = m_point;
    above.z = above.z + 1;
    Cube* pCube = m_pCubeService->FUN_1410b8a60(above);
    if (pCube == 0)
        return 1;
    if (pCube->field60 != 0)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140884aa0, CUGCBuildValidatorCli, vfunc_31, 194, 0x503836FA);

// @0x140884b70
Cube* CUGCBuildValidatorCli::vfunc_33()
{
    Cube* pCube = m_pCubeService->FUN_1410b8a60(m_point);
    if (pCube != 0)
        return pCube;
    return 0;
}
MS2_REPLACE_METHOD(0x140884b70, CUGCBuildValidatorCli, vfunc_33, 94, 0x896B62FD);

// @0x140884be0
Cube* CUGCBuildValidatorCli::vfunc_34()
{
    PCBase* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    if (FUN_141530290(pPC) == 0)
        return 0;
    if (FUN_1410a8a90(FUN_141530290(pPC)) != 2)
    {
        Cube* pCube = m_pCubeService->FUN_1410b8790(m_point);
        return pCube;
    }
    else
    {
        Unk_CubePoint below = m_point;
        below.z = below.z - 1;
        int nKey = FUN_1408a03c0(below);
        Cube* pCube = m_pCubeService->FUN_1410b8b00(nKey);
        return pCube;
    }
}
MS2_REPLACE_METHOD(0x140884be0, CUGCBuildValidatorCli, vfunc_34, 284, 0x0DBF730F);

// @0x140884d10
int CUGCBuildValidatorCli::vfunc_35()
{
    if (!m_itemData != 0)
        return 0;
    PCBase* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    if (FUN_141530290(pPC) == 0)
        return 0;
    if (FUN_1410a8a90(FUN_141530290(pPC)) == 2 && m_itemData->install.attachable != 0)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x140884d10, CUGCBuildValidatorCli, vfunc_35, 149, 0x436B4840);
// map<int,MS2Ptr<Cube>> iterator/tree glue: byte-identical to the table's CMIS copies (0x1411291d0/0x141129b50/0x141146820/
// 0x141148a10); the own-copy pass no longer pairs them (another look-alike name competes), so pin the unit's own copies
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1408853c0
// MS2-PIN: ??E?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1408853e0
// MS2-PIN: ?_Lmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@PEAX@2@XZ 0x140885a70
// MS2-PIN: ?_Min@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@PEAX@2@PEAU32@@Z 0x140885a80
