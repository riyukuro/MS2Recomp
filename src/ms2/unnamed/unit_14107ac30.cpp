// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). TCreateCharInfo: the character-create / lobby preview
// record (type, ids, name, job, two equip colours) and the functions that dress a PC from it (or from a user proxy),
// plus the neighbouring rim light / sun direction shader constants. The .text$di part is the animation key strings,
// the rim light colour, the sort names and two markers.
// MS2-UNIT: unit_14107ac30
// MS2-RANGE: 0x1400e4e20-0x1400e50a0 .text$di
// MS2-RANGE: 0x14107ac30-0x14107ce50 .text$mn
#define NOMINMAX                        // NxPhysics
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include <NiColor.h>
#include <NiFixedString.h>
#include <NiShaderFactory.h>
#include "ms2/placeholder/tcreatecharinfo.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/mypc.h"
#include "ms2/placeholder/pcgemequip.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/commonfiles/itemgem.h"
#include "ms2/commonfiles/itemdata.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/client/ms2/avatarpc.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/physxhelper.h"
#include "ms2/client/ms2/cameramode.h"
#include "ms2/commonfiles/userproxy.h"
#include "ms2/commonfiles/jobsystem.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

MS2_EMIT_CRT_MEMMOVE_S();

// ---- unit-local views of exe objects ----

// The pc record of avatar creation (the MS2Ptr<> argument of FUN_14107c030): the ids and the name of the described pc.
class Unk_PCArg125 : public CPtred
{
public:
    unsigned short m_nLevel;                                // +0x18
    unsigned char m_pad_1a[2];
    int m_nJob;                                             // +0x1c
    int m_nJob2;                                            // +0x20
    unsigned char m_pad_24[0x30 - 0x24];
    unsigned __int64 m_nPcId;                               // +0x30
    unsigned char m_pad_38[0x3c4 - 0x38];
    int m_nGender;                                          // +0x3c4
    unsigned char m_pad_3c8[0x3e8 - 0x3c8];
    CStringW m_strName;                                     // +0x3e8
};
MS2_CHECK_OFFSET(Unk_PCArg125, m_nPcId, 0x30);
MS2_CHECK_OFFSET(Unk_PCArg125, m_strName, 0x3e8);

// The equipment of a pc (PC::FUN_14165f460): the gem equipment.
class Unk_MyPCEquip : public PCGemEquip {};
int FUN_14123c580(PCBase* pPC);                                         // the object id
struct Unk_JobTable;
Unk_JobTable* FUN_1401d7a50();
int FUN_140644bb0(Unk_JobTable* p, int nClass);
bool FUN_1401c0050(MS2Ptr<CItem>& ref, int n);
int FUN_14107c2d0(int nId, unsigned nType, unsigned nSex, PC* pPC);

// The rim light settings (declared the same way by uirimlightdialog.cpp; the data is defined here).
struct Unk_Color3
{
    Unk_Color3();
    Unk_Color3(float r, float g, float b);                  // 0x14097f250
    float r, g, b;
};
class Unk_RimLight
{
public:
    static void FUN_14107b2a0(float fYaw, float fPitch);                 // s_fYaw = fYaw, s_fPitch = fPitch
    static void FUN_14107b320(const Unk_Color3& color, float fPower);    // s_sssColor = color, s_fSSSPower = fPower
    static float s_fPitch;              // 0x1439f6fec
    static float s_fYaw;                // 0x143acd4b0
    static Unk_Color3 s_sssColor;       // 0x143acd550
    static float s_fSSSPower;           // 0x1439f6ff0
};
float Unk_RimLight::s_fPitch = 30.0f;
float Unk_RimLight::s_fYaw;
Unk_Color3 Unk_RimLight::s_sssColor(1.0f, 0.2f, 0.2f);
float Unk_RimLight::s_fSSSPower = 1.0f;

// A shader constant key (a Gamebryo fixed string); the values are set by applyeffect.cpp's helpers.
extern NiFixedString DAT_143ae5388;
extern NiFixedString DAT_143ae5390;
extern NiFixedString DAT_143ae5398;
extern NiFixedString DAT_143ae53a0;

// The world service accessors this unit uses.
WorldService* FUN_1403ed2d0();
void FUN_1402a9d70(void*, int, float, float, float, int);
void FUN_1401cd100(void* pId, __int64 nId);
Unk_StreamPoint* FUN_14097f250(void* p, float x, float y, float z);
int FUN_140a18070(Unk_CameraManager*);
class Unk_PCLook;
Unk_PCLook* FUN_1416546d0(PC* pPC);
void FUN_140638200(Unk_PCLook* pLook, int nJob, int nJob2, short n);
CPhysXHelper* FUN_1409f7ca0();
bool FUN_1409a5770(const NiFixedString& kName, const float* pf, int n);
int FUN_140599fd0(void* pProxy, int n);

// Helpers of the exe used by this unit (declared by the units that recover them).
extern char DAT_143a09660;
Unk_CharEquip FUN_140a0a3a0(const void* pIn);               // the default appearance
Unk_CharEquip FUN_141b6dea0(unsigned nColor);     // Unk_CharEquip from a colour value
bool FUN_1402226b0(int nJob);
void FUN_140584ff0(TCreateCharInfo* pInfo, ATL::CAtlArray<int>* pItems);
unsigned FUN_140869420();
Unk_NiPoint3 FUN_14027dcf0(const Unk_StreamPoint& pt);
Unk_StreamPoint* FUN_14097faa0(Unk_StreamPoint* pDst, const Unk_NiPoint3& kSrc);
void FUN_140deec40(Unk_StreamPoint* p);
bool FUN_140a33ff0(const void* pf);
__declspec(noreturn) void FUN_140159b70(long hr);
void FUN_14107b050(const Unk_StreamPoint& kDir);
void FUN_14107b2d0();
void FUN_14097fad0(Unk_Color3* pDst, const Unk_Color3* pSrc);
void FUN_14107cad0(NiFixedString* pName, void* pData, int n);
bool FUN_14107cb00(NiFixedString* pName, void* pData, int n);
const NiColor* FUN_141659220(PC* pPC, int n);
int FUN_141658e60(PC* pPC);
int FUN_141654730(PC* pPC);
int FUN_141654700(PC* pPC);

class Unk_ColorTemp
{
private:
    int m_0, m_4, m_8, m_c, m_10, m_14, m_18;
};

// scene graph walker (0x40 bytes, unrecovered class): a one-slot header and the queue of nodes still to visit
class Unk_C930Walker
{
public:
    Unk_C930Walker(NiObject* pRoot);                // 0x14098cb80
    ~Unk_C930Walker();                              // 0x14098cf00
    void FUN_14098d6d0(NiObject* pNode);            // queue the children of a node
    void* m_p0;
    ATL::CAtlList<NiObject*> m_list;
    void* m_p38;
};
MS2_CHECK_SIZE(Unk_C930Walker, 0x40);
bool FUN_14098df00(Unk_C930Walker& rWalker);          // the queue is empty
NiObject* FUN_14098e5c0(Unk_C930Walker& rWalker);     // pop the next node
NiObject** FUN_14107cbe0(Unk_C930Walker& rWalker);
NiObject* FUN_14107cc90(Unk_C930Walker& rWalker, bool bDescend);
NiObject* FUN_14098d8d0(const NiRTTI* pRTTI, NiObject* pObject);
extern const NiRTTI DAT_143ad1588;
extern const NiRTTI DAT_143afbfb8;
extern const NiRTTI DAT_143afa4d8;

// An interned node name (8 bytes), compared with FUN_1409a7ff0.
class Unk_FixedName
{
public:
    Unk_FixedName(const char* psz);                 // 0x140984450
    ~Unk_FixedName();                               // 0x1409845a0
private:
    void* m_p;
};
const void* FUN_1409a8b90(NiObject* pNode);         // the node's name object
bool FUN_1409a7ff0(const void* pName, const Unk_FixedName& kName);

// ---- dynamic initializers (.text$di) ----

// @0x1400e4e20
static CString s_strAnimMale("urn:gamebryo-animation:Male");

// @0x1400e4e50
static CString s_strDollMale("urn:gamebryo-animation:FittingDoll_M_Default03");

// @0x1400e4e80
static CString s_strAnimFemale("urn:gamebryo-animation:Female");

// @0x1400e4eb0
static CString s_strDollFemale("urn:gamebryo-animation:FittingDoll_F_Default03");

// @0x1400e4f10
static CString s_sort7[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// @0x1400e4fd0
static CString s_skill("skill");

// @0x1400e5000
static CString s_stun("stun");

#ifndef MS2_HOOK_DLL
void FUN_142cabb00();
struct Unk_RegMarker {};
static char s_id[8];
// @0x1400e5030
static Unk_RegMarker s_initId = (FUN_1401cd100(&s_id, 0), Unk_RegMarker());
static char s_marker[0x48];
// @0x1400e5050
static Unk_RegMarker s_initMarker = (FUN_1402a9d70(&s_marker, 0x11, 0.75f, 0.25f, 2.25f, 10), atexit(FUN_142cabb00), Unk_RegMarker());
#endif

// ---- the functions ----

// @0x14107ac30
TCreateCharInfo::TCreateCharInfo()
{
    FUN_14107ad90();
}

// @0x14107acb0
TCreateCharInfo::TCreateCharInfo(int nType, int nGender)
{
    FUN_14107ad90();
    m_nType = nType;
    m_nGender = nGender;
}

// @0x14107ad50
TCreateCharInfo::~TCreateCharInfo()
{
}

// @0x14107ad90
void TCreateCharInfo::FUN_14107ad90()
{
    m_nType = 0;
    m_nGender = 0;
    m_nJobCode = 1;
    m_n30 = 10;
    m_n20 = 0;
    m_n34 = 1;
    m_b58 = false;
    FUN_14107afa0();
}

// @0x14107afa0
// MS2-FUNCTIONAL: the frame is 16 bytes larger than the exe's (copy temporary layout)
void TCreateCharInfo::FUN_14107afa0()
{
    for (int i = 0; i < 2; i++)
    {
        Unk_CharEquip kEquip = FUN_140a0a3a0(&DAT_143a09660);
        m_equip[i] = kEquip;
    }
}


// @0x14107ae00
void TCreateCharInfo::FUN_14107ae00()
{
    m_n20 = FUN_140869420();
    m_n34 = 1;
    m_nGender = (rand() % 2) != 0;
    m_nJobCode = 1;
    m_n30 = 10;
    MS2Ptr<CItem> spItem(new CItem);
    if (spItem.get() != 0)
    {
        if (spItem->FUN_140523c40(0x9a1d21, 1, 0))
        {
            Unk_UserProxyItemData* pData = spItem->FUN_140527870();
            if (pData != 0)
            {
                for (int i = 0; i < 2; i++)
                {
                    m_equip[i] = FUN_141b6dea0(FUN_140599fd0(pData, i));
                }
            }
        }
    }
}

// @0x14107b010
void FUN_14107b010()
{
    if (FUN_140a18070(Unk_CameraManager::FUN_1409478c0()) != 0)
        FUN_14107b050(Unk_CameraManager::FUN_1409478c0()->FUN_140af0250());
    FUN_14107b2d0();
}
MS2_REPLACE(0x14107b010, FUN_14107b010, 57, 0x7150A5CF);

// @0x14107b050
// MS2-FUNCTIONAL: temporary slot order of the point conversions differs
void FUN_14107b050(const Unk_StreamPoint& kDir)
{
    Unk_StreamPoint kRight = kDir;
    Unk_StreamPoint kFlat = kDir;
    kFlat.z = 0;
    FUN_140deec40(&kFlat);
    Unk_NiMatrix3 matRot;
    Unk_StreamPoint kAxis(0, 0, 1.0f);
    FUN_14097faa0(&kAxis, FUN_14027dcf0(kAxis.FUN_140a00e10(kRight)));
    matRot.FUN_14107cc40(-((Unk_RimLight::s_fPitch * 3.1415927f) / 180.0f), kAxis);
    FUN_14097faa0(&kRight, FUN_14027dcf0(matRot.FUN_140a00720(kRight)));
    FUN_14097faa0(&kFlat, FUN_14027dcf0(matRot.FUN_140a00720(kFlat)));
    matRot.FUN_142084c10((Unk_RimLight::s_fYaw * 3.1415927f) / 180.0f);
    FUN_14097faa0(&kRight, FUN_14027dcf0(matRot.FUN_140a00720(kRight)));
    FUN_14097faa0(&kFlat, FUN_14027dcf0(matRot.FUN_140a00720(kFlat)));
    FUN_14107cad0(&DAT_143ae5388, &kRight, 1);
    FUN_14107cad0(&DAT_143ae5390, &kFlat, 1);
}

// @0x14107b2a0
void Unk_RimLight::FUN_14107b2a0(float fYaw, float fPitch)
{
    s_fPitch = fPitch;
    s_fYaw = fYaw;
}

// @0x14107b2d0
void FUN_14107b2d0()
{
    FUN_14107cad0(&DAT_143ae5398, &Unk_RimLight::s_sssColor, 1);
    FUN_1409a5770(DAT_143ae53a0, &Unk_RimLight::s_fSSSPower, 1);
}
MS2_REPLACE(0x14107b2d0, FUN_14107b2d0, 59, 0x1F4B3C77);

// @0x14107b320
void Unk_RimLight::FUN_14107b320(const Unk_Color3& color, float fPower)
{
    FUN_14097fad0(&s_sssColor, &color);
    s_fSSSPower = fPower;
}

// @0x14107b360
CString FUN_14107b360(int nGender)
{
    if (nGender == 0)
        return s_strAnimMale;
    return s_strAnimFemale;
}
MS2_REPLACE(0x14107b360, FUN_14107b360, 103, 0x396FAFB6);

// @0x14107b3d0
CString FUN_14107b3d0(int nGender)
{
    if (nGender == 0)
        return s_strDollMale;
    return s_strDollFemale;
}
MS2_REPLACE(0x14107b3d0, FUN_14107b3d0, 103, 0xAA813896);

// @0x14107b440
int TCreateCharInfo::FUN_14107b440(PC* pPC)
{
    WorldService* pWorld = FUN_1403ed2d0();
    Unk_StreamPoint kDir;
    Unk_StreamPoint kPos;
    if (pWorld->FUN_141bd0dd0(&kPos, &kDir) == 0)
        return 0;
    pPC->FUN_14123c5a0(m_nType);
    pPC->FUN_141656a50(m_n20);
    int nGender = m_nGender;
    pPC->FUN_14123bb80(FUN_14107b360(nGender));
    pPC->vfunc_19(reinterpret_cast<efd::Point3&>(kPos));
    pPC->vfunc_21(reinterpret_cast<efd::Point3&>(kDir));
    pPC->vfunc_131((short)m_n34);
    pPC->vfunc_76(m_str38);
    pPC->FUN_141658e40(m_nGender);
    int nJob = 1;
    int nJob2 = 10;
    if (FUN_1402226b0(m_nJobCode))
    {
        nJob = m_nJobCode;
        nJob2 = m_n30;
    }
    FUN_140638200(FUN_1416546d0(pPC), nJob, nJob2, (short)m_n34);
    pPC->FUN_14166cce0(4);
    pPC->vfunc_59(1, 0, 0, 0);
    for (int i = 0; i < 2; i++)
        pPC->FUN_1416591e0(i, reinterpret_cast<const NiColor&>(m_equip[i]));
    Unk_StreamPoint kHit;
    if (FUN_1409f7ca0()->FUN_14168a310(kPos, kHit, 0, 0.0f, 0, 0) != 0)
    {
        kHit.z += 1.0f;
        pPC->vfunc_19(reinterpret_cast<efd::Point3&>(kHit));
    }
    if (pWorld->FUN_141bbb1e0(pPC, 0, 1) != 0)
        return 1;
    return 0;
}

// @0x14107b7e0
int FUN_14107b7e0(unsigned nSlot, const Unk_UserProxy* pState, PC* pPC)
{
    WorldService* pWorld = FUN_1403ed2d0();
    Unk_StreamPoint kDir;
    Unk_StreamPoint kPos;
    if (pWorld->FUN_141bd0dd0(&kPos, &kDir) == 0)
        return 0;
    pPC->FUN_14123c5a0(nSlot);
    pPC->FUN_141656a50(pState->m_8);
    int nGender = pState->m_14;
    pPC->FUN_14123bb80(FUN_14107b360(nGender));
    pPC->vfunc_19(reinterpret_cast<efd::Point3&>(kPos));
    pPC->vfunc_21(reinterpret_cast<efd::Point3&>(kDir));
    pPC->vfunc_131(pState->m_34);
    pPC->vfunc_76(const_cast<Unk_UserProxy*>(pState)->FUN_1408f19e0());
    pPC->FUN_141658e40(pState->m_14);
    FUN_140638200(FUN_1416546d0(pPC), pState->m_3c, pState->m_40, pState->m_34);
    pPC->FUN_14166cce0(4);
    pPC->vfunc_59(1, 0, 0, 0);
    Unk_CharEquip aEquip[2];
    aEquip[0] = FUN_141b6dea0(pState->m_58[0]);
    aEquip[1] = FUN_141b6dea0(pState->m_58[1]);
    pPC->FUN_1416591e0(0, reinterpret_cast<const NiColor&>(aEquip[0]));
    pPC->FUN_1416591e0(1, reinterpret_cast<const NiColor&>(aEquip[1]));
    Unk_StreamPoint kHit;
    if (FUN_1409f7ca0()->FUN_14168a310(kPos, kHit, 0, 0.0f, 0, 0) != 0)
    {
        kHit.z += 1.0f;
        pPC->vfunc_19(reinterpret_cast<efd::Point3&>(kHit));
    }
    if (pWorld->FUN_141bbb1e0(pPC, 0, 1) != 0)
    {
        pPC->vfunc_139();
        if (!pState->m_240.IsEmpty())
        {
            int nObjId = FUN_14123c580(pPC);
            pPC->FUN_14165f460()->FUN_141270f10(const_cast<ATL::CAtlArray<MS2Ptr<CItem> >&>(pState->m_240), nObjId);
            MS2Ptr<CGemBase> spGem = pPC->FUN_14165f460()->FUN_141270740(1);
            if (spGem.get() != 0)
                spGem->vfunc_6(pPC, pPC->FUN_14165f460()->FUN_141270140(1));
        }
        CMsTime kEnd(pState->m_288);
        CMsTime kStart(pState->m_280);
        pPC->FUN_1416561a0()->FUN_1411ea620(kStart, kEnd);
        if (!pState->m_260.IsEmpty())
        {
            size_t nCount = pState->m_260.GetCount();
            for (size_t i = 0; i < nCount; i++)
            {
                MS2Ptr<CItem> spItem = pState->m_260[i];
                if (spItem.get() != 0)
                {
                    spItem->FUN_140526b30(FUN_14123c580(pPC));
                    pPC->FUN_141653d10(spItem);
                }
            }
        }
        if (!pState->m_220.IsEmpty())
        {
                    ATL::CAtlArray<MS2Ptr<CItem> > kA;
        ATL::CAtlArray<MS2Ptr<CItem> > kB;
        size_t nCount = pState->m_220.GetCount();
            for (size_t i = 0; i < nCount; i++)
            {
                MS2Ptr<CItem> spItem = pState->m_220[i];
                if (FUN_1401c0050(spItem, 0) != 0)
                    continue;
                spItem->FUN_140526b30(FUN_14123c580(pPC));
                pPC->FUN_141653d10(spItem);
            }
        }
        return 1;
    }
    return 0;
}
MS2_REPLACE(0x14107b7e0, FUN_14107b7e0, 2116, 0xC603A912);

// @0x14107c030
bool FUN_14107c030(int nId, MS2Ptr<Unk_PCArg125> spSrc, PC* pPC)
{
    TCreateCharInfo kInfo;
    kInfo.m_nType = nId;
    kInfo.m_n20 = spSrc->m_nPcId;
    kInfo.m_nGender = spSrc->m_nGender;
    kInfo.m_nJobCode = spSrc->m_nJob;
    kInfo.m_n30 = spSrc->m_nJob2;
    kInfo.m_n34 = spSrc->m_nLevel;
    kInfo.m_str38 = spSrc->m_strName;
    {
        MS2Ptr<CItem> spItem(new CItem);
        if (spItem.get() != 0)
        {
            if (spItem->FUN_140523c40(0x9a1d21, 1, 0))
            {
                Unk_UserProxyItemData* pData = spItem->FUN_140527870();
                if (pData != 0)
                {
                    for (int i = 0; i < 2; i++)
                        kInfo.m_equip[i] = FUN_141b6dea0(FUN_140599fd0(pData, i));
                }
            }
        }
    }
    return kInfo.FUN_14107b440(pPC) == 1;
}
MS2_REPLACE(0x14107c030, FUN_14107c030, 602, 0x422EFE59);

// @0x14107c290
int FUN_14107c290(int nId, PC* pPC)
{
    return FUN_14107c2d0(nId, rand() % 2, 1, pPC);
}
MS2_REPLACE(0x14107c290, FUN_14107c290, 54, 0x683AD42B);

// @0x14107c2d0
int FUN_14107c2d0(int nId, unsigned nType, unsigned nSex, PC* pPC)
{
    TCreateCharInfo kInfo;
    kInfo.FUN_14107ae00();
    kInfo.m_nType = nId;
    kInfo.m_nGender = nType;
    kInfo.m_nJobCode = nSex;
    kInfo.m_n30 = FUN_140644bb0(FUN_1401d7a50(), nSex);
    return kInfo.FUN_14107c3a0(pPC);
}
MS2_REPLACE(0x14107c2d0, FUN_14107c2d0, 190, 0xB277E6A4);

// @0x14107c3a0
int TCreateCharInfo::FUN_14107c3a0(PC* pPC)
{
    if (FUN_14107b440(pPC) != 0)
    {
        ATL::CAtlArray<int> aItems;
        FUN_140584ff0(this, &aItems);
        size_t nCount = aItems.GetCount();
        for (size_t i = 0; i < nCount; i++)
        {
            int nItemId = aItems[i];
            if (nItemId == 0)
                continue;
            int nSlot;
            MS2Ptr<CItem> spItem(new CItem);
            if (spItem->FUN_140523c40(nItemId, 1, 0))
            {
                if (reinterpret_cast<CItemData*>(spItem->FUN_140527840())->FUN_14053d2f0())
                    nSlot = 5;
                else
                    nSlot = reinterpret_cast<CItemData*>(spItem->FUN_140527840())->FUN_14053eba0()->FUN_14054b400();
                spItem->FUN_140526c10(nSlot);
                spItem->FUN_140526a70(pPC->FUN_14123cec0());
                spItem->FUN_140526b30(m_nType);
                pPC->FUN_141653d10(spItem);
            }
        }
        return 1;
    }
    return 0;
}

// @0x14107c5f0
// MS2-FUNCTIONAL: frame/temporary layout of the Point3 copies differs
int FUN_14107c5f0(int nSlot, PC* pSrc, PC* pDst)
{
    int nId = nSlot;
    if (nId != 0)
    {
        pDst->FUN_14123c5a0(nId);
        pDst->FUN_141656a50(pSrc->FUN_141656a80());
        pDst->FUN_14123bb80(pSrc->FUN_14123bbd0());
        NiPoint3 kPos = pSrc->vfunc_18();
        pDst->vfunc_19(reinterpret_cast<efd::Point3&>(kPos));
        Unk_ColorTemp kTmp;
        Unk_StreamPoint kRot = *FUN_14097f250(&kTmp, 0.0f, 0.0f, 90.0f);
        pDst->vfunc_21(reinterpret_cast<efd::Point3&>(kRot));
        pDst->vfunc_131((short)pSrc->vfunc_78());
        pDst->vfunc_76(CStringW(L""));
        pDst->FUN_141658e40(FUN_141658e60(pSrc));
        pDst->vfunc_59(1, 0, 0, 0);
        pDst->FUN_14166cce0(4);
        pDst->FUN_1416591e0(0, *FUN_141659220(pSrc, 0));
        pDst->FUN_1416591e0(1, *FUN_141659220(pSrc, 1));
        FUN_140638200(FUN_1416546d0(pDst), FUN_141654700(pSrc), FUN_141654730(pSrc), (short)pSrc->vfunc_78());
        if (FUN_1403ed2d0()->FUN_141bbb1e0(pDst, 0, 1) != 0)
        {
            pDst->vfunc_139();
            return 1;
        }
    }
    return 0;
}

// @0x14107c930
// MS2-FUNCTIONAL: stack slot order and unwind states of the walker/name locals differ
NiObject* FUN_14107c930(NiObject* pRoot, const CString* pName)
{
    if (pRoot == 0)
        return 0;
    if (_stricmp((const char*)*pName, "Scene Root") == 0)
        return pRoot;
    NiObject* pFound = 0;
    Unk_C930Walker kWalker(pRoot);
    bool bDescend = true;
    Unk_FixedName kRoot("Scene Root");
    Unk_FixedName kName((const char*)*pName);
    NiObject* pNode;
    while ((pNode = FUN_14107cc90(kWalker, bDescend)) != 0)
    {
        if (FUN_14098d8d0(&DAT_143ad1588, pNode) == 0 && FUN_14098d8d0(&DAT_143afbfb8, pNode) == 0)
        {
            if (pNode == pRoot || FUN_1409a7ff0(FUN_1409a8b90(pNode), kRoot) == 0)
            {
                if (FUN_1409a7ff0(FUN_1409a8b90(pNode), kName) != 0)
                {
                    pFound = pNode;
                    break;
                }
                bDescend = true;
            }
            else
                bDescend = false;
        }
        else
            bDescend = false;
    }
    return pFound;
}

// @0x14107cad0
void FUN_14107cad0(NiFixedString* pName, void* pData, int n)
{
    FUN_14107cb00(pName, pData, n);
}
MS2_REPLACE(0x14107cad0, FUN_14107cad0, 44, 0x6803A96B);

// @0x14107cb00
bool FUN_14107cb00(NiFixedString* pName, void* pData, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (!FUN_140a33ff0((char*)pData + (__int64)i * 0xc))
            throw 13;
    }
    if (NiShaderFactory::UpdateGlobalShaderConstant(*pName, (unsigned int)((__int64)n * 0xc), pData))
        return true;
    return false;
}
MS2_REPLACE(0x14107cb00, FUN_14107cb00, 155, 0x76E1782A);

// @0x14107cbe0
NiObject** FUN_14107cbe0(Unk_C930Walker& rWalker)
{
    do
    {
        int bOk = !!(*(void**)((char*)&rWalker + 8) != 0);
        do { } while (0);
        if (!bOk)
            FUN_140159b70(E_FAIL);
    } while (0);
    return (NiObject**)((char*)*(void**)((char*)&rWalker + 8) + 0x10);
}

// @0x14107cc40
void Unk_EfdMatrix3::FUN_14107cc40(float fAngle, const Unk_StreamPoint& kAxis)
{
    reinterpret_cast<efd::Matrix3*>(this)->MakeRotation(fAngle, kAxis.x, kAxis.y, kAxis.z);
}

// @0x14107cc90
// MS2-FUNCTIONAL: call-through-this register shuffle (mov rax;mov rcx,rax) not reproduced
NiObject* FUN_14107cc90(Unk_C930Walker& rWalker, bool bDescend)
{
    if (FUN_14098df00(rWalker))
        return 0;
    NiObject* pObj = FUN_14098e5c0(rWalker);
    if (bDescend)
    {
        NiObject* pNode = FUN_14098d8d0(&DAT_143afa4d8, pObj);
        if (pNode != 0)
            rWalker.FUN_14098d6d0(pNode);
    }
    if (FUN_14098df00(rWalker))
        return 0;
    else
        return *FUN_14107cbe0(rWalker);
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142caba10-0x142cabb20 .text$yd
