// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The rain effect over the cube terrain.
// MS2-UNIT: ?\raindroponcubeemitter.cpp
// MS2-RANGE: 0x1400fed80-0x1400fedb0 .text$di
// MS2-RANGE: 0x1416ec580-0x1416f44e0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$CustomAllocator@U?$_List_node@UUnk_RainDrop@@PEAX@std@@@efd@@V?$_List_val@U?$_List_simple_types@UUnk_RainDrop@@@std@@@std@@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x1416ee0f0 ; unique
// MS2-PIN: ??$?0AEBV?$CustomAllocator@U?$pair@$$CBII@std@@@efd@@$$V@?$_Compressed_pair@V?$CustomAllocator@U?$_List_node@U?$pair@$$CBII@std@@PEAX@std@@@efd@@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBII@std@@@std@@@std@@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBV?$CustomAllocator@U?$pair@$$CBII@std@@@efd@@@Z 0x1416ee130 ; unique
// MS2-PIN: ??$?0II$0A@@?$pair@II@std@@QEAA@AEBI0@Z 0x1416ee2c0 ; unique
// MS2-PIN: ??$_Buynode@AEBUUnk_RainDrop@@@?$_List_buy@UUnk_RainDrop@@V?$CustomAllocator@UUnk_RainDrop@@@efd@@@std@@QEAAPEAU?$_List_node@UUnk_RainDrop@@PEAX@1@PEAU21@0AEBUUnk_RainDrop@@@Z 0x1416ee420 ; unique
// MS2-PIN: ??$_Buynode@U?$pair@II@std@@@?$_List_buy@U?$pair@$$CBII@std@@V?$CustomAllocator@U?$pair@$$CBII@std@@@efd@@@std@@QEAAPEAU?$_List_node@U?$pair@$$CBII@std@@PEAX@1@PEAU21@0$$QEAU?$pair@II@1@@Z 0x1416ee4b0 ; prop
// MS2-PIN: ??$_Buynode@UUnk_RainDrop@@@?$_List_buy@UUnk_RainDrop@@V?$CustomAllocator@UUnk_RainDrop@@@efd@@@std@@QEAAPEAU?$_List_node@UUnk_RainDrop@@PEAX@1@PEAU21@0$$QEAUUnk_RainDrop@@@Z 0x1416ee540 ; unique
// MS2-PIN: ??$_Construct1@U?$pair@$$CBII@std@@U?$pair@II@2@@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_List_node@U?$pair@$$CBII@std@@PEAX@std@@@efd@@@std@@SAXU?$integral_constant@_N$00@1@AEAV?$CustomAllocator@U?$_List_node@U?$pair@$$CBII@std@@PEAX@std@@@efd@@PEAU?$pair@$$CBII@1@$$QEAU?$pair@II@1@@Z 0x1416ee670 ; unique
// MS2-PIN: ??$_Construct1@UUnk_RainDrop@@AEBU1@@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_List_node@UUnk_RainDrop@@PEAX@std@@@efd@@@std@@SAXU?$integral_constant@_N$00@1@AEAV?$CustomAllocator@U?$_List_node@UUnk_RainDrop@@PEAX@std@@@efd@@PEAUUnk_RainDrop@@AEBU5@@Z 0x1416ee740 ; prop
// MS2-PIN: ??$_Construct1@UUnk_RainDrop@@U1@@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_List_node@UUnk_RainDrop@@PEAX@std@@@efd@@@std@@SAXU?$integral_constant@_N$00@1@AEAV?$CustomAllocator@U?$_List_node@UUnk_RainDrop@@PEAX@std@@@efd@@PEAUUnk_RainDrop@@$$QEAU5@@Z 0x1416ee790 ; prop
// MS2-PIN: ??$_Destroy1@UUnk_RainDrop@@@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_List_node@UUnk_RainDrop@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_List_node@UUnk_RainDrop@@PEAX@std@@@efd@@PEAUUnk_RainDrop@@U?$integral_constant@_N$00@1@@Z 0x1416ee800 ; unique
// MS2-PIN: ??$_Insert@U?$pair@II@std@@@?$list@U?$pair@$$CBII@std@@V?$CustomAllocator@U?$pair@$$CBII@std@@@efd@@@std@@QEAAXV?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBII@std@@@std@@@std@@U_Iterator_base0@2@@1@$$QEAU?$pair@II@1@@Z 0x1416eefb0 ; unique
// MS2-PIN: ??$_Uninitialized_move@PEAV?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@PEAV12@V?$CustomAllocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@@efd@@@std@@YAPEAV?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@0@QEAV10@0PEAV10@AEAV?$CustomAllocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@@efd@@@Z 0x1416ef200 ; unique
// MS2-PIN: ??$construct@UUnk_RainDrop@@AEBU1@@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_List_node@UUnk_RainDrop@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_List_node@UUnk_RainDrop@@PEAX@std@@@efd@@PEAUUnk_RainDrop@@AEBU4@@Z 0x1416ef520 ; prop
// MS2-PIN: ??$construct@UUnk_RainDrop@@U1@@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_List_node@UUnk_RainDrop@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_List_node@UUnk_RainDrop@@PEAX@std@@@efd@@PEAUUnk_RainDrop@@$$QEAU4@@Z 0x1416ef560 ; prop
// MS2-PIN: ??$emplace@U?$pair@II@std@@@?$_Hash@V?$_Umap_traits@IIV?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$CustomAllocator@U?$pair@$$CBII@std@@@efd@@$0A@@std@@@std@@QEAA?AU?$pair@V?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@II@1@@Z 0x1416ef690 ; unique
// MS2-PIN: ??$emplace_front@U?$pair@II@std@@@?$list@U?$pair@$$CBII@std@@V?$CustomAllocator@U?$pair@$$CBII@std@@@efd@@@std@@QEAAX$$QEAU?$pair@II@1@@Z 0x1416ef710 ; unique
// MS2-PIN: ??$insert@U?$pair@II@std@@X@?$unordered_map@IIU?$hash@I@std@@U?$equal_to@I@2@V?$CustomAllocator@U?$pair@$$CBII@std@@@efd@@@std@@QEAA?AU?$pair@V?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@II@1@@Z 0x1416ef830 ; unique
// MS2-PIN: ??$make_pair@AEBIAEBI@std@@YA?AU?$pair@II@0@AEBI0@Z 0x1416ef870 ; unique
// MS2-PIN: ?Add@?$CAtlArray@UUnk_Int3@@V?$CElementTraits@UUnk_Int3@@@ATL@@@ATL@@QEAA_KAEBUUnk_Int3@@@Z 0x1416f0eb0 ; unique
// MS2-PIN: ?Add@?$CAtlArray@V?$SmartPointer@VNiTexture@@@efd@@V?$CElementTraits@V?$SmartPointer@VNiTexture@@@efd@@@ATL@@@ATL@@QEAA_KAEBV?$SmartPointer@VNiTexture@@@efd@@@Z 0x1416f0f60 ; unique
// MS2-PIN: ?Add@?$NiTSet@V?$SmartPointer@VNiPSEmitter@@@efd@@V?$NiTNewInterface@V?$SmartPointer@VNiPSEmitter@@@efd@@@@@@QEAAIAEBV?$SmartPointer@VNiPSEmitter@@@efd@@@Z 0x1416f1010 ; unique
// MS2-PIN: ?AddEmitter@NiPSParticleSystem@@QEAAXPEAVNiPSEmitter@@@Z 0x1416f10b0 ; unique
// MS2-PIN: ?_Freenode@?$_List_buy@U?$pair@$$CBII@std@@V?$CustomAllocator@U?$pair@$$CBII@std@@@efd@@@std@@QEAAXPEAU?$_List_node@U?$pair@$$CBII@std@@PEAX@2@@Z 0x1416f2230 ; unique
// MS2-PIN: ?_Freenode@?$_List_buy@UUnk_RainDrop@@V?$CustomAllocator@UUnk_RainDrop@@@efd@@@std@@QEAAXPEAU?$_List_node@UUnk_RainDrop@@PEAX@2@@Z 0x1416f2280 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??1?$unordered_map@IIU?$hash@I@std@@U?$equal_to@I@2@V?$CustomAllocator@U?$pair@$$CBII@std@@@efd@@@std@@QEAA@XZ 0x1416f0510
// MS2-PIN: ??1ColumnMap@@QEAA@XZ 0x1416f0470
// MS2-PIN: ??1DropList@@QEAA@XZ 0x1416f04c0
// MS2-PIN: ??1?$SmartPointer@VSemanticRequirement@NiMeshRequirements@@@efd@@QEAA@XZ 0x1416f0200
// MS2-PIN: ??0DropList@@QEAA@XZ 0x1416f0030
// MS2-PIN: ??0?$_List_alloc@U?$_List_base_types@UUnk_RainDrop@@V?$CustomAllocator@UUnk_RainDrop@@@efd@@@std@@@std@@QEAA@XZ 0x1416efc30
// MS2-PIN: ??1?$SmartPointer@VStreamMetaDataObject@NiStream@@@efd@@QEAA@XZ 0x1416f0290
// MS2-PIN: ??0?$SmartPointer@VNiProperty@@@efd@@QEAA@PEAVNiProperty@@@Z 0x1416efb00
// MS2-PIN: ??0?$_List_val@U?$_List_simple_types@UUnk_RainDrop@@@std@@@std@@QEAA@XZ 0x1416efee0
// MS2-PIN: ??1?$SmartPointer@VNiProperty@@@efd@@QEAA@XZ 0x1416f0260
// MS2-PIN: ??0?$SmartPointer@VNiPSParticleSystem@@@efd@@QEAA@PEAVNiPSParticleSystem@@@Z 0x1416efa80
// MS2-PIN: ??1?$list@UUnk_RainDrop@@V?$CustomAllocator@UUnk_RainDrop@@@efd@@@std@@QEAA@XZ 0x1416f04e0
// MS2-PIN: ??0?$_List_val@U?$_List_simple_types@U?$pair@$$CBII@std@@@std@@@std@@QEAA@XZ 0x1416eff10
// MS2-PIN: ??0?$CAtlArray@UUnk_Int3@@V?$CElementTraits@UUnk_Int3@@@ATL@@@ATL@@QEAA@XZ 0x1416ef9c0
// MS2-PIN: ??0ColumnMap@@QEAA@XZ 0x1416effe0
// MS2-PIN: ??$destroy@U?$pair@$$CBII@std@@@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_List_node@U?$pair@$$CBII@std@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_List_node@U?$pair@$$CBII@std@@PEAX@std@@@efd@@PEAU?$pair@$$CBII@1@@Z 0x1416ef660
// MS2-PIN: ??$destroy@UUnk_RainDrop@@@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_List_node@UUnk_RainDrop@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_List_node@UUnk_RainDrop@@PEAX@std@@@efd@@PEAUUnk_RainDrop@@@Z 0x1416ef600
// MS2-PIN: ??$construct@U?$pair@$$CBII@std@@U?$pair@II@2@@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_List_node@U?$pair@$$CBII@std@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_List_node@U?$pair@$$CBII@std@@PEAX@std@@@efd@@PEAU?$pair@$$CBII@1@$$QEAU?$pair@II@1@@Z 0x1416ef460
// MS2-PIN: ??$_Construct1@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@V12@@?$_Normal_allocator_traits@V?$CustomAllocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@@efd@@@std@@SAXU?$integral_constant@_N$0A@@1@AEAV?$CustomAllocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@@efd@@PEAV?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@1@$$QEAV51@@Z 0x1416ee700
// MS2-PIN: ??$?0U?$integral_constant@_N$0A@@std@@@_Unused_parameter@std@@QEAA@$$QEAU?$integral_constant@_N$0A@@1@@Z 0x1416ee2a0
// MS2-PIN: ??0?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@QEAA@XZ 0x1416ef980
// MS2-PIN: ??0?$SmartPointer@VNiAlphaProperty@@@efd@@QEAA@PEAVNiAlphaProperty@@@Z 0x1416efa40
// MS2-PIN: ??1?$SmartPointer@VNiAlphaProperty@@@efd@@QEAA@XZ 0x1416f01d0
// MS2-PIN: ??1?$SmartPointer@VNiAVObject@@@efd@@QEAA@XZ 0x1416f0230
// MS2-PIN: ??4?$SmartPointer@VNiTexture@@@efd@@QEAAAEAV01@PEAVNiTexture@@@Z 0x1416f0740
// MS2-PIN: ??B?$SmartPointer@VNiAlphaProperty@@@efd@@QEBAPEAVNiAlphaProperty@@XZ 0x1416f0950
// MS2-PIN: ??B?$SmartPointer@VNiBoolInterpolator@@@efd@@QEBAPEAVNiBoolInterpolator@@XZ 0x1416f0980
// MS2-PIN: ??B?$SmartPointer@VNiFloatInterpolator@@@efd@@QEBAPEAVNiFloatInterpolator@@XZ 0x1416f0990
// MS2-PIN: ??_E?$SmartPointer@VNiAVObject@@@efd@@QEAAPEAXI@Z 0x1416f0c70
// MS2-PIN: ??$addressof@U?$pair@$$CBII@std@@@std@@YAPEAU?$pair@$$CBII@0@AEAU10@@Z 0x1416f23a0
// MS2-PIN: ??A?$CAtlArray@UUnk_Int3@@V?$CElementTraits@UUnk_Int3@@@ATL@@@ATL@@QEAAAEAUUnk_Int3@@_K@Z 0x1416f08b0
// MS2-PIN: ?lower_bound@?$_Hash@V?$_Umap_traits@IIV?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$CustomAllocator@U?$pair@$$CBII@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@2@AEBI@Z 0x1416f3f60
// MS2-PIN: ??$swap@UUnk_Int3@@X@std@@YAXAEAUUnk_Int3@@0@Z 0x1416ef8e0
// MS2-PIN: ??$_Destroy1@U?$pair@$$CBII@std@@@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_List_node@U?$pair@$$CBII@std@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_List_node@U?$pair@$$CBII@std@@PEAX@std@@@efd@@PEAU?$pair@$$CBII@1@U?$integral_constant@_N$00@1@@Z 0x1416ee840
// MS2-PIN: ??_GRainDropOnCubeEmitter@@UEAAPEAXI@Z 0x1416f0df0
// MS2-PIN: ??_GRainDropSystem@@UEAAPEAXI@Z 0x1416f0e50
// MS2-PIN: ??A?$CAtlArray@UUnk_Int3@@V?$CElementTraits@UUnk_Int3@@@ATL@@@ATL@@QEAAAEAUUnk_Int3@@_K@Z 0x1416f1300
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "raindroponcubeemitter.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

#include <stdlib.h>
#include <NiAlphaProperty.h>
#include <NiMaterialProperty.h>
#include <NiTexturingProperty.h>
#include <NiVertexColorProperty.h>
#include <NiZBufferProperty.h>
#include <NiPSAlignedQuadGenerator.h>
#include <NiFloatInterpolator.h>
#include <NiBoolInterpolator.h>

// ---- unit-local placeholders ----

extern const Vector3 g_143a08cf8;   // NiPoint3::UNIT_Z
extern const Vector3 g_143a08ce8;   // NiPoint3::ZERO
extern const Vector3 g_143b01a60;   // the zero point
extern const NiColor g_143a09660;
extern const NiColor g_143b01ef0;

// The local player, as far as this unit reads it.
class Unk_RainActor
{
public:
    virtual void vfunc_0();   virtual void vfunc_1();   virtual void vfunc_2();   virtual void vfunc_3();
    virtual void vfunc_4();   virtual void vfunc_5();   virtual void vfunc_6();   virtual void vfunc_7();
    virtual void vfunc_8();   virtual void vfunc_9();   virtual void vfunc_10();  virtual void vfunc_11();
    virtual void vfunc_12();  virtual void vfunc_13();  virtual void vfunc_14();  virtual void vfunc_15();
    virtual void vfunc_16();  virtual void vfunc_17();
    virtual Vector3 GetPosition();                          // MS2: slot 18
};
class Unk_RainContext
{
public:
    Unk_RainActor* FUN_141bd0cc0();                                 // the local player
};
Unk_RainContext* FUN_1403ed2d0();

class Unk_Clock;
Unk_Clock* FUN_14086d260();
double FUN_141473280(Unk_Clock* pClock);                            // seconds

// The cube terrain: the height of a column (INT_MIN when empty).
class Unk_CubeWorld
{
public:
    int FUN_1410b24b0(int nX, int nY);
};
class Unk_CubeService;
Unk_CubeService* FUN_1410b27c0();
Unk_CubeWorld* FUN_1410b9e70(Unk_CubeService* pService);

int FUN_1408a13d0(Vector3 kPos);                            // column key of a position
void FUN_1408a1430(int* pXY, Vector3 kPos);                 // column (x, y) of a position
Vector3 FUN_1408a15b0(Unk_Int3 kCube, Vector3* pOut);   // position of a column (also in pOut)
unsigned int FUN_1408a03c0(Unk_Int3 kCube);                      // key of a column

// The client paths (texture directory at +0x100) and the texture factory.
struct Unk_RainPaths
{
    char m_pad_0000[0x100];
    CString m_strTexture;
};
Unk_RainPaths* FUN_1401d31f0();
class Unk_RainTextureFactory
{
public:
    NiTexturePtr FUN_141552f90(CString strName, int nFlags);
};
Unk_RainTextureFactory* FUN_140a0afd0();

// The scene registry: takes the list of nodes to draw, returns a handle.
struct Unk_RainAVPtr
{
    Unk_RainAVPtr(void* pObject);                                   // 0x1411aedc0
    ~Unk_RainAVPtr();                                               // 0x1410471c0
    void* m_pObject;
};
class Unk_RainNodeList
{
public:
    Unk_RainNodeList();                                             // 0x1411af860
    ~Unk_RainNodeList();                                            // 0x1411b00f0
    void FUN_1411b83f0(Unk_RainAVPtr& spNode);
    char m_pad_00[0x18];
};
class Unk_RainScene
{
public:
    unsigned int FUN_141ffaa20(Unk_RainNodeList& kList, bool bA, bool bB);
    void FUN_142003af0(unsigned int nHandle);
};
Unk_RainScene* FUN_1413f98b0();
NiObject* FUN_14098d8d0(const NiRTTI* pRTTI, NiObject* pObject);    // dynamic cast (NULL-safe)

#define AsPoint(kPoint) reinterpret_cast<const efd::Point3&>(kPoint)

#ifndef MS2_HOOK_DLL
const NiRTTI RainDropOnCubeEmitter::ms_RTTI("RainDropOnCubeEmitter", &NiPSVolumeEmitter::ms_RTTI);   // @0x1400fed80
#else
const NiRTTI RainDropOnCubeEmitter::ms_RTTI("RainDropOnCubeEmitter", &NiPSVolumeEmitter::ms_RTTI);
#endif

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x1416ec580
double Unk_RainDrop::GetTime() const
{
    return m_dTime;
}

// @0x1416ec5a0
const Unk_Int3& Unk_RainDrop::GetPos() const
{
    return m_kPos;
}

// @0x1416ec5c0
Unk_RainDrop::Unk_RainDrop()
{
}

// @0x1416ec5f0
Unk_RainDrop::Unk_RainDrop(double dTime, const Unk_Int3& kPos)
{
    m_dTime = dTime;
    static_cast<Unk_Int3&>(m_kPos) = kPos;
}

// Fills the columns around a position (a 20 x 20 window) that have a surface.
// @0x1416edfd0
// MS2-FUNCTIONAL: cube column walk: register allocation / loop layout differs
static void FillColumns(const Vector3& kPos, ATL::CAtlArray<Unk_Int3>& arrCube)
{
    Unk_CubeWorld* pWorld = FUN_1410b9e70(FUN_1410b27c0());
    int arrXY[2];
    FUN_1408a1430(arrXY, kPos);
    for (int dx = -10; dx < 10; dx++)
    {
        for (int dy = -10; dy < 10; dy++)
        {
            int x = arrXY[0] + dx;
            int y = arrXY[1] + dy;
            int z = pWorld->FUN_1410b24b0(x, y);
            if (z != INT_MIN)
            {
                Unk_Int3 kCube(x, y, z + 1);
                arrCube.Add(kCube);
            }
        }
    }
}

float FUN_14029d430(float fX, float fY);                            // fmodf

// @0x1416f12d0
static float Fmod(float fX, float fY)
{
    return FUN_14029d430(fX, fY);
}

// @0x1416ee350
// MS2-FUNCTIONAL: swap helper inlining and loop layout differ
static void ShuffleColumns(ATL::CAtlArray<Unk_Int3>& arrCube)
{
    int n = (int)arrCube.GetCount();
    int i;
    while (i = n - 1, 0 < i)
    {
        int r = rand() % n;
        n = i;
        if (i != r)
            std::swap(arrCube[r], arrCube[i]);
    }
}

// The value of a key, if present.
// @0x1416f3e20
template <class Map>
static bool FindColumn(const Map& map, const typename Map::key_type& kKey, typename Map::mapped_type& nValue)
{
    typename Map::const_iterator it = map.find(kKey);
    if (it != map.end())
    {
        nValue = it->second;
        return true;
    }
    return false;
}

// @0x1416ec650
// MS2-FUNCTIONAL: ctor: member init order and frame slots differ
RainDropOnCubeEmitter::RainDropOnCubeEmitter(const NiFixedString& kName, NiAVObject* pkEmitterObj, float fSize,
                                             float fSizeVar, float fLifeSpan, float fLifeSpanVar)
    : NiPSVolumeEmitter(kName, pkEmitterObj, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, fSize, fSizeVar, fLifeSpan,
                        fLifeSpanVar, 0.0f, 6.2831855f, 0.0f, 0.0f, false, NiPoint3(AsPoint(g_143a08cf8)), false)
{
    m_fCooldown = fLifeSpan;
    Vector3 kPos = g_143b01a60;
    Unk_RainActor* pActor = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pActor)
        kPos = pActor->GetPosition();
    m_nCenterKey = FUN_1408a13d0(kPos);

    ATL::CAtlArray<Unk_Int3> arrCube;
    FillColumns(kPos, arrCube);
    ShuffleColumns(arrCube);
    double dNow = FUN_141473280(FUN_14086d260());
    for (unsigned int i = 0; i < arrCube.GetCount(); i++)
    {
        const Unk_Int3& kCube = static_cast<const ATL::CAtlArray<Unk_Int3>&>(arrCube)[i];
        m_lstDrops.push_front(Unk_RainDrop(dNow, kCube));
        const unsigned int nKey = FUN_1408a03c0(kCube);
        m_mapColumns.insert(std::make_pair(nKey, nKey));
    }
    m_bDirty = false;
}

// @0x1416f17e0
void RainDropOnCubeEmitter::MarkDirty()
{
    m_bDirty = true;
}

// @0x1416eca00
// MS2-FUNCTIONAL: temporaries of the column walk are laid out differently
void RainDropOnCubeEmitter::Refresh()
{
    Unk_RainActor* pActor = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pActor)
    {
        Vector3 kPos = pActor->GetPosition();
        int nKey = FUN_1408a13d0(kPos);
        if (!m_bDirty)
        {
            if ((int)m_nCenterKey == nKey)
                return;
        }
        else
        {
            m_bDirty = false;
        }
        m_nCenterKey = nKey;

        ATL::CAtlArray<Unk_Int3> arrCube;
        FillColumns(kPos, arrCube);
        ShuffleColumns(arrCube);
        double dNow = FUN_141473280(FUN_14086d260());
        ATL::CAtlArray<unsigned int> arrKey;
        for (unsigned int i = 0; i < arrCube.GetCount(); i++)
        {
            const Unk_Int3& kCube = static_cast<const ATL::CAtlArray<Unk_Int3>&>(arrCube)[i];
            unsigned int nColumn = FUN_1408a03c0(kCube);
            arrKey.Add(nColumn);
            if (!FindColumn(m_mapColumns, nColumn, nColumn))
                m_lstDrops.push_front(Unk_RainDrop(dNow, kCube));
        }
        m_mapColumns.clear();
        for (unsigned int i = 0; i < arrKey.GetCount(); i++)
        {
            const unsigned int nColumn = arrKey[i];
            m_mapColumns.insert(std::make_pair(nColumn, nColumn));
        }
    }
}

// @0x1416eccc0
// MS2-FUNCTIONAL: list/double temporaries differ in frame order
bool RainDropOnCubeEmitter::ComputeVolumeInitialPositionAndVelocity(NiQuatTransform& kEmitterToPSys,
                                                                    NiPoint3& kPosition, NiPoint3& kVelocity)
{
    if (m_lstDrops.empty())
        return false;

    Unk_RainDrop& kDrop = m_lstDrops.front();
    double dNow = FUN_141473280(FUN_14086d260());
    if (kDrop.GetTime() > dNow)
        return false;

    Vector3 kLocal;
    FUN_1408a15b0(kDrop.GetPos(), &kLocal);
    kLocal.z = kLocal.z + 3.0f;
    kPosition = kEmitterToPSys * NiPoint3(AsPoint(kLocal));
    kVelocity = NiPoint3(AsPoint(g_143b01a60));
    unsigned int nKey = FUN_1408a03c0(kDrop.GetPos());
    if (FindColumn(m_mapColumns, nKey, nKey))
    {
        Unk_RainDrop kNext(dNow + (double)m_fCooldown, kDrop.GetPos());
        m_lstDrops.push_back(kNext);
    }
    m_lstDrops.pop_front();
    return true;
}

// @0x1416f05b0
// MS2-FUNCTIONAL: dtor: exe has no vptr store before the member dtors
RainDropOnCubeEmitter::~RainDropOnCubeEmitter()
{
}

// @0x1416eced0
// MS2-FUNCTIONAL: ctor: member init order differs
RainDropSystem::RainDropSystem()
    : m_spSystem(NULL), m_spNode(NULL), m_spEmitter(NULL), m_spCtlr(NULL)
{
    m_spSystem = NULL;
    FUN_1409f76f0(&m_spNode, NULL);
    m_nHandle = 0;
    m_nTexture = 0;
}

// @0x1416ecfb0
// MS2-FUNCTIONAL: dtor: frame slot order differs
RainDropSystem::~RainDropSystem()
{
    if (m_nHandle != 0)
    {
        Unk_RainScene* pScene = FUN_1413f98b0();
        if (pScene)
            pScene->FUN_142003af0(m_nHandle);
    }
}

// @0x1416ed080
// MS2-FUNCTIONAL: smart pointer temporaries are laid out differently
void RainDropSystem::Create()
{
    m_nTexture = 0;
    for (unsigned int i = 0; i < 16; i++)
    {
        CString strName;
        strName.Format("%sRainDrop%d.dds", (const char*)FUN_1401d31f0()->m_strTexture, (unsigned __int64)i);
        NiTexturePtr spTexture = FUN_140a0afd0()->FUN_141552f90(strName, 5);
        m_arrTexture.Add(spTexture);
    }

    NiPoint3 kUp(AsPoint(g_143a08ce8));
    NiPoint3 kAxis(AsPoint(g_143a08cf8));
    m_spSystem = NiPSParticleSystem::Create(0x200, (NiPSParticleSystem::AlignMethod)2, kAxis,
                                            (NiPSParticleSystem::AlignMethod)2, kUp, false, true, true, false, true,
                                            false, false, true);
    NiPSAlignedQuadGenerator* pGenerator = NiNew NiPSAlignedQuadGenerator;
    m_spSystem->AddModifier(pGenerator, true);
    m_spSystem->SetName(NiFixedString("RainDropParticle"));
    NiNode* pNode = NiNew NiNode(0);
    FUN_1409f76f0(&m_spNode, pNode);
    static_cast<NiNode*>(FUN_1409475f0(&m_spNode))->SetTranslate(0.0f, 0.0f, 0.0f);
    static_cast<NiNode*>(FUN_1409475f0(&m_spNode))->AttachChild(m_spSystem, false);
    NiBound kBound;
    kBound.SetCenterAndRadius(NiPoint3(AsPoint(g_143b01a60)), 3000.0f);
    m_spSystem->SetModelBound(kBound);

    Unk_RainNodeList kList;
    {
        Unk_RainAVPtr spObject(FUN_14098d8d0(&NiObject::ms_RTTI, static_cast<NiNode*>(FUN_1409475d0(&m_spNode))));
        kList.FUN_1411b83f0(spObject);
    }
    m_nHandle = FUN_1413f98b0()->FUN_141ffaa20(kList, true, true);

    SetupProperties();
    NiFixedString kEmitterName("RainDropOnCubeEmitter");
    m_spEmitter = NiNew RainDropOnCubeEmitter(kEmitterName, static_cast<NiNode*>(FUN_1409475d0(&m_spNode)), 80.0f,
                                              0.0f, 1.0f, 0.0f);
    m_spSystem->AddEmitter(m_spEmitter);

    NiFloatInterpolatorPtr spBirth = NiNew NiFloatInterpolator(512.0f);
    NiBoolInterpolatorPtr spActive = NiNew NiBoolInterpolator(true);
    m_spCtlr = NiNew NiPSEmitParticlesCtlr(kEmitterName);
    m_spCtlr->SetBirthRateInterpolator(spBirth);
    m_spCtlr->SetEmitterActiveInterpolator(spActive);
    m_spCtlr->SetBeginKeyTime(0.0f);
    m_spCtlr->SetEndKeyTime(1.0f);
    m_spCtlr->SetCycleType((NiTimeController::CycleType)0);
    m_spCtlr->SetTarget(m_spSystem);
}

// @0x1416ed980
void RainDropSystem::Update()
{
    SelectTexture();
    m_spEmitter->Refresh();
}

// @0x1416ed9c0
void RainDropSystem::Destroy()
{
    if (m_spEmitter)
        m_spEmitter->MarkDirty();
}

// @0x1416eda10
// MS2-FUNCTIONAL: property smart pointer temporaries differ in frame order
void RainDropSystem::SetupProperties()
{
    NiVertexColorPropertyPtr spColor = NiNew NiVertexColorProperty;
    spColor->SetSourceMode(NiVertexColorProperty::SOURCE_IGNORE);
    spColor->SetLightingMode(NiVertexColorProperty::LIGHTING_E_A_D);
    m_spSystem->AttachProperty(spColor);

    NiAlphaPropertyPtr spAlpha = NiNew NiAlphaProperty;
    spAlpha->SetAlphaBlending(true);
    spAlpha->SetAlphaTesting(true);
    spAlpha->SetSrcBlendMode((NiAlphaProperty::AlphaFunction)4);
    spAlpha->SetDestBlendMode((NiAlphaProperty::AlphaFunction)0);
    m_spSystem->AttachProperty(spAlpha);

    NiTexturingPropertyPtr spTexturing = NiNew NiTexturingProperty;
    m_spSystem->AttachProperty(spTexturing);

    NiMaterialPropertyPtr spMaterial = NiNew NiMaterialProperty;
    spMaterial->SetAmbientColor(NiColor(g_143a09660));
    spMaterial->SetDiffuseColor(NiColor(g_143b01ef0));
    m_spSystem->AttachProperty(spMaterial);

    NiZBufferPropertyPtr spZBuffer = NiNew NiZBufferProperty;
    spZBuffer->SetZBufferWrite(false);
    m_spSystem->AttachProperty(spZBuffer);

    SelectTexture();
}

// @0x1416eded0
// MS2-FUNCTIONAL: texture array access differs in register choice
void RainDropSystem::SelectTexture()
{
    float fRatio = Fmod((float)FUN_141473280(FUN_14086d260()), 1.0f);
    NiTexturingProperty* pTexturing = (NiTexturingProperty*)m_spSystem->GetProperty(NiProperty::TEXTURING);
    pTexturing->SetBaseTexture(m_arrTexture[(unsigned int)((float)m_arrTexture.GetCount() * fRatio / 1.0f)]);
    m_spSystem->UpdateProperties();
}

// ---- hooks ----
MS2_REPLACE_METHOD(0x1416ECA00, RainDropOnCubeEmitter, Refresh, 687, 0x58671C2C);
MS2_REPLACE_METHOD(0x1416ECCC0, RainDropOnCubeEmitter, ComputeVolumeInitialPositionAndVelocity, 518, 0x54E2AE4D);
MS2_REPLACE_METHOD(0x1416ED080, RainDropSystem, Create, 2289, 0xB9EA79DF);
MS2_REPLACE_METHOD(0x1416EDA10, RainDropSystem, SetupProperties, 1205, 0xCE697E93);
MS2_REPLACE_METHOD(0x1416EDED0, RainDropSystem, SelectTexture, 235, 0xF59B2BD0);
