// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See avatarcube.h.
// MS2-UNIT: ?\avatarcube.cpp
// MS2-RANGE: 0x1409f2670-0x1409f3370 .text$mn
// MS2-RANGE: 0x1400c2300-0x1400c2440 .text$di
// MS2-PIN: ?vfunc_25@GameObject@@UEAAHXZ 0x1409f2fb0
// MS2-PIN: ?GetRefCount@GameObject@@UEBAIXZ 0x1409f2fc0
// MS2-PIN: ?IncRefCount@GameObject@@UEBAXXZ 0x1409f2fe0
// MS2-PIN: ?vfunc_45@GameObject@@UEAAXM@Z 0x1409f3000
// MS2-PIN: ?vfunc_24@GameObject@@UEAAXH@Z 0x1409f3020
// MS2-PIN: ?SetupClassInfo@GameObject@@SAXPEAVClassInfo@efd@@_K@Z 0x1409f3090
// MS2-PIN: ?SetupClassInfo@IBase@efd@@SAXPEAVClassInfo@2@_K@Z 0x1409f30f0
// MS2-PIN: ?TypeCast@AvatarCube@@UEBA_NIPEAPEAX@Z 0x1409f3130
// MS2-PIN: ?TypeCast@AvatarCube@@UEBA_NIPEAPEBX@Z 0x1409f3180
// MS2-PIN: ?TypeCast@ClassInfo@efd@@QEBAPEAXIPEBX@Z 0x1409f31d0
// MS2-PIN: ??_7AvatarCube@@6BIBase@efd@@@ 0x142dbfd68
// MS2-PIN: ??_7AvatarCube@@6BCallbackObject@NiActorManager@@@ 0x142dbff60
// MS2-FUNCTIONAL: the UGC cube manager / CUgcItemCube / attend-avatar manager are opaque FUN_ externs.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\avatarcube.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "avatarcube.h"
#include <io.h>
#include <efd/utf8string.h>
#include <egf/EntityID.h>
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"

// ---- unit-local views of exe objects ----

// The model key as the exe stack holds it: 8 bytes (GameObject::FUN_14123c460 fills it; the 16-byte Unk_GoModelKey of
// gameobject.h is only its out-parameter view).
struct Unk_AcKey { unsigned __int64 m_id; };
#define AC_KEY(k) reinterpret_cast<Unk_GoModelKey&>(k)

// The animation service (singleton behind FUN_141b6f910); same object as kfmmodel.cpp's view.
class Unk_AcAnimSvc
{
public:
    int FUN_140999490(const Unk_GoModelKey& id, const efd::utf8string& kName);                  // sequence id, -2 when absent
    void FUN_1409a1fc0(const Unk_GoModelKey& id, const efd::utf8string& kName, float fBlend, bool b);   // play
};
Unk_AcAnimSvc* FUN_141b6f910();
CString FUN_1409a2360(const char* psz, int n);

// CUgcItemCube (RTTI, unit not recovered): a UGC cube build request. ctor 0x14088fb30, dtor 0x14088fbb0.
struct Unk_UgcItemCube { char m_pad[0x58]; };
MS2_CHECK_SIZE(Unk_UgcItemCube, 0x58);
void FUN_14088fb30(Unk_UgcItemCube* pCube, CItem* pItem, Unk_GoModelKey& kKey);
void FUN_14088fbb0(Unk_UgcItemCube* pCube);

// The UGC cube manager (singleton behind FUN_14052d220).
class Unk_UgcCubeMgr
{
public:
    // Starts loading the cube from the cached file strFile; 0 on success.
    int FUN_141886cc0(Unk_UgcItemCube* pCube, CString strFile, unsigned __int64 nUgcUid);
    // Requests the cube download; spItem by value (callee-destroyed).
    void FUN_141883df0(MS2Ptr<CItem> spItem, Unk_GoModelKey& kKey);
};
Unk_UgcCubeMgr* FUN_14052d220();
CString FUN_1410280d0(int nKind, CString strName);

// The avatar-attend manager (singleton behind FUN_1403ed2d0): the avatar object registered under an id.
class Unk_AttendAvatarMgr
{
public:
    void* FUN_141bd1180(unsigned int nId);
};
Unk_AttendAvatarMgr* FUN_1403ed2d0();

EE_IMPLEMENT_CONCRETE_CLASS_INFO(AvatarCube);

// ---- header statics (the shared sort-type names, "skill", "stun"; header_statics_a.h minus the condition object) ----
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x1409f2670
AvatarCube* FUN_1409f2670(CItemData* pData)
{
    AvatarCube* pCube = new (efd::MemHint(efd::MemHint::NONE)) AvatarCube(pData);
    if (pCube == 0)
    {
        pCube = 0;
    }
    else
    {
        int nId = FUN_1409f2cd0();
        if (nId == 0)
        {
            pCube = 0;
        }
        else
        {
            pCube->vfunc_57();
            pCube->FUN_14123c5a0(nId);
            pCube->vfunc_19(NiPoint3::ZERO);
            pCube->vfunc_21(NiPoint3(0.0f, 0.0f, 90.0f));
        }
    }
    return pCube;
}

// @0x1409f27e0
AvatarCube::~AvatarCube()
{
}

// @0x1409f2820
void AvatarCube::vfunc_12()
{
    CloneCube::vfunc_12();
    if (m_unk_80 != 0)
    {
        efd::utf8string kIdle((const char*)FUN_1409a2360("Idle_A", 0));
        Unk_AcKey kId1;
        Unk_GoModelKey& rId1 = FUN_14123c460(AC_KEY(kId1));
        if (FUN_141b6f910()->FUN_140999490(rId1, kIdle) != -2)
        {
            Unk_AcKey kId2;
            Unk_GoModelKey& rId2 = FUN_14123c460(AC_KEY(kId2));
            FUN_141b6f910()->FUN_1409a1fc0(rId2, kIdle, 1.0f, true);
        }
    }
}

// @0x1409f2960
AvatarCube::AvatarCube(CItemData* pData)
    : CloneCube(MS2Ptr<CItemData>(pData), "urn:gamebryo-scenegraph:ugc_cube_A01")
{
}

// @0x1409f2a00
void AvatarCube::vfunc_59(MS2Ptr<CItem> spItem)
{
    if (spItem.get() && spItem->FUN_1405278d0())
    {
        CString strFile = FUN_1410280d0(2, spItem->FUN_1405278d0()->m_strName);
        if (_access(strFile, 0) == 0)
        {
            Unk_AcKey kKey1;
            Unk_UgcItemCube kCube;
            FUN_14088fb30(&kCube, spItem.get(), FUN_14123c460(AC_KEY(kKey1)));
            if (FUN_14052d220()->FUN_141886cc0(&kCube, CString(strFile), spItem->FUN_1405283d0()) == 0)
            {
                Unk_AcKey kKey2;
                Unk_GoModelKey& rKey2 = FUN_14123c460(AC_KEY(kKey2));
                FUN_14052d220()->FUN_141883df0(MS2Ptr<CItem>(spItem), rKey2);
            }
            FUN_14088fbb0(&kCube);
        }
        else
        {
            Unk_AcKey kKey3;
            Unk_GoModelKey& rKey3 = FUN_14123c460(AC_KEY(kKey3));
            FUN_14052d220()->FUN_141883df0(MS2Ptr<CItem>(spItem), rKey3);
        }
    }
}

// Finds a free object id for a new cube (ids 0x410..0x419); 0 when all are taken.
// @0x1409f2cd0
unsigned int FUN_1409f2cd0()
{
    for (unsigned int nId = 0x410; nId <= 0x419; nId++)
    {
        if (FUN_1403ed2d0()->FUN_141bd1180(nId) == 0)
            return nId;
    }
    return 0;
}

// @0x1409f3250
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9ea70-0x142c9eae0 .text$yd
