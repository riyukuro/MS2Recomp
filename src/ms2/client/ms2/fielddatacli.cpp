// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CFieldDataCli: client-side CFieldData (fieldData.xml + MapXblock xml: bgm, hdr, fog, camera, shadow, minimap).
// MS2-UNIT: ?\fielddatacli.cpp
// MS2-FUNCTIONAL: vfunc_1, FUN_140a55df0, LoadXBlock, Find, CMinimap::CMinimap/~CMinimap, FUN_140a56e70, FUN_140a55d20 differ from the exe in temp/EH layout only (extern-FUN style); behaviour identical
// MS2-RANGE: 0x1400c4040-0x1400c4100 .text$di
// MS2-RANGE: 0x140a54160-0x140a571b0 .text$mn
// MS2-PIN: ?get@?$MS2Ptr@VCMinimap@@@@QEBAPEAVCMinimap@@XZ 0x140a56f90
// MS2-PIN: ??C?$MS2Ptr@VCMinimap@@@@QEBAPEAVCMinimap@@XZ 0x140a56fa0
// MS2-PIN: ??_GCFieldDataCli@@UEAAPEAXI@Z 0x140a56fb0
// MS2-PIN: ??_GCMinimap@@UEAAPEAXI@Z 0x140a56ff0
// MS2-PIN: ??B?$MS2Ptr@VCFieldData@@@@QEBAPEAVCFieldData@@XZ 0x140a57030
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCFieldDataCli@@@@AEBAXPEAX@Z 0x140a570c0
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCMinimap@@@@AEBAXPEAX@Z 0x140a570f0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\fielddatacli.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "fielddatacli.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/ms2recover.h"
#include <new>

class Unk_140165cf0 { public: Unk_140165cf0* FUN_140165cf0(const char*); };

// ---- out-of-unit callees (bound to the exe by name) ----
const char* FUN_14086f4b0(Unk_140165cf0*, const char*);                  // Attribute(name)
int FUN_140873220(Unk_140165cf0*, const char*, unsigned&);
int FUN_1408731e0(Unk_140165cf0*, const char*, int&);
int FUN_140873260(Unk_140165cf0*, const char*, int&);
int FUN_140873360(Unk_140165cf0*, const char*, float&);
int FUN_1408730a0(Unk_140165cf0*, const char*, bool&);
int FUN_1408733e0(Unk_140165cf0*, const char*, CString&);
int FUN_140873890(Unk_140165cf0*, const char*, int&);
CString FUN_140188f50(Unk_140165cf0*, int);                              // node text
void FUN_141b6ed40(const CString&, Unk_GVec3*);                          // parse "x,y,z"
void FUN_14028d1a0(const CString&, int*);                                // parse int
void FUN_14028c2d0(CString, float*);
unsigned FUN_14028c0d0(const char*);                                     // parse colour
void FUN_140203800(float*);
void FUN_1408850f0(MS2Ptr<CFieldDataCli>*);                              // MS2Ptr<CFieldDataCli>::~MS2Ptr
CFieldDataCli* FUN_140885340(MS2Ptr<CFieldDataCli>*);                    // MS2Ptr<CFieldDataCli>::operator->
extern char DAT_143b01a60;
bool FUN_1401647e0(const CString&, const CString&);                      // CString != CString
bool FUN_140164830(const CStringW&, const CStringW&);
bool FUN_1401932b0(const std::vector<unsigned>&, const std::vector<unsigned>&);
bool FUN_1406cf9e0(const std::vector<short>&, const std::vector<short>&);
bool FUN_140552700(const Unk_GVec3&, const Unk_GVec3&);
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
bool FUN_140a56ee0(const Unk_Vec3Cli*, const Unk_Vec3Cli*);
bool FUN_140a56f50(const Unk_Vec3Cli*, const Unk_Vec3Cli*);
bool FUN_140a55df0(Unk_140165cf0* node, MS2Ptr<CFieldDataCli>* sp);
int FUN_140a56ad0(Unk_140165cf0* node, const char* name, int& out);
MS2Ptr<CMinimap>* FUN_140a56e70(MS2Ptr<CMinimap>* self, CMinimap* p);

// ---- static string table (the first static of header_statics_a.h), 0x1400c4040; atexit thunk 0x142c9f4f0 ----
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// @0x140a54160
CFieldDataCli::CFieldDataCli()
    : m_spMinimap(0), m_vecDummyTargetPos(0, 0, 0), m_vecUnk17c(0, 0, 0),
      m_nBgmId(0), m_nBgmParam(0), m_fBgmValue(0), m_nBossBgmId(0), m_nBossBgmParam(0), m_fBossBgmValue(0),
      m_nVScroll(1), m_nHScroll(1), m_nUseEffLight(0), m_nFieldName(1), m_nEffectLOD(1), m_nInstancingGrid(0),
      m_bFastGlow(true), m_nFastShimmer(1), m_nGlobalNameTag(0), m_nShowHitEffect(1), m_nApplyCameraOption(1),
      m_fCameraExtraDistance(0), m_bNoSkipFrame(false), m_fFov(40.0f), m_nUseDummyTarget(0), m_bUnk1fc(false),
      m_bFog(false), m_nFogColor(0), m_fFogNear(1000.0f), m_fFogFar(10000.0f), m_bHeightFog(false),
      m_nHeightFogColor(0), m_fHeightFogUpper(0), m_fHeightFogLower(-500.0f), m_fHeightFogPercentage(100.0f),
      m_bHdr(true), m_fHdrThreshold(0.27f), m_fHdrOffset(30.0f), m_fHdrMiddleGray(0.51f), m_fHdrBloomScale(2.0f),
      m_fHdrGlowScale(0.1f), m_bUnk238(false), m_fCameraDistance(1100.0f), m_fCameraVAngle(30.0f),
      m_fZoomOutHeightOffset(60.0f), m_fZoomInHeightOffset(95.0f), m_bUseFileSetting(false),
      m_fShadowIntensity(0.3f), m_fShadowSimple(0.5f), m_nShadowOptionHighLevel(0)
{
}

// @0x140a54540
CFieldDataCli::~CFieldDataCli()
{
}

// @0x140a545d0   nonzero when the two records differ
bool FUN_140a545d0(CFieldDataCli* a, CFieldDataCli* b)
{
    if (a->m_nFieldID != b->m_nFieldID) return true;
    if (FUN_140164830(a->m_strFeature, b->m_strFeature)) return true;
    if (FUN_1401647e0(a->m_strLocale, b->m_strLocale)) return true;
    if (FUN_1401647e0(a->m_strXBlock, b->m_strXBlock)) return true;
    if (a->m_nRevivalReturnId != b->m_nRevivalReturnId) return true;
    if (a->m_nEnterReturnId != b->m_nEnterReturnId) return true;
    if (a->m_nMapCategoryCode != b->m_nMapCategoryCode) return true;
    if (a->m_nContinentCode != b->m_nContinentCode) return true;
    if (a->m_nRegionCode != b->m_nRegionCode) return true;
    if (a->m_nMapType != b->m_nMapType) return true;
    if (a->m_nBigCity != b->m_nBigCity) return true;
    if (a->m_nGlobalSplit != b->m_nGlobalSplit) return true;
    if (a->m_nIndoorMask != b->m_nIndoorMask) return true;
    if (a->m_nHomeReturnable != b->m_nHomeReturnable) return true;
    if (a->m_nDeathPenalty != b->m_nDeathPenalty) return true;
    if (a->m_nMinimapInvisible != b->m_nMinimapInvisible) return true;
    if (a->m_nAutoRevivalType != b->m_nAutoRevivalType) return true;
    if (a->m_nAutoRevivalTime != b->m_nAutoRevivalTime) return true;
    if (a->m_nOnlyDarkTomb != b->m_nOnlyDarkTomb) return true;
    if (a->m_nMapLevel != b->m_nMapLevel) return true;
    if (a->m_nDropRank != b->m_nDropRank) return true;
    if (FUN_1401932b0(a->m_globalDropBoxIds, b->m_globalDropBoxIds)) return true;
    if (a->m_nLimitContent != b->m_nLimitContent) return true;
    if (a->m_bMapSearch != b->m_bMapSearch) return true;
    if (a->m_nFallDamage != b->m_nFallDamage) return true;
    if (a->m_nUseEPSkill != b->m_nUseEPSkill) return true;
    if (a->m_nUsePet != b->m_nUsePet) return true;
    if (a->m_nUseRidee != b->m_nUseRidee) return true;
    if (a->m_nUseOptimalHide != b->m_nUseOptimalHide) return true;
    if (a->m_nPkMode != b->m_nPkMode) return true;
    if (a->m_nAutoFindTaxiStation != b->m_nAutoFindTaxiStation) return true;
    if ((unsigned short)a->m_nEnterMinLevel != (unsigned short)b->m_nEnterMinLevel) return true;
    if ((unsigned short)a->m_nEnterMaxLevel != (unsigned short)b->m_nEnterMaxLevel) return true;
    if (a->m_nMassiveEventField != b->m_nMassiveEventField) return true;
    if (a->m_nRecoveryFullHP != b->m_nRecoveryFullHP) return true;
    if (FUN_1401932b0(a->m_enteranceBuffIds, b->m_enteranceBuffIds)) return true;
    if (FUN_1406cf9e0(a->m_enteranceBuffLevels, b->m_enteranceBuffLevels)) return true;
    if (a->m_nEnterAdminLevel != b->m_nEnterAdminLevel) return true;
    if (a->m_nChannelGroupId != b->m_nChannelGroupId) return true;
    if (a->m_nWebFinder != b->m_nWebFinder) return true;
    if (a->m_nCashTaxiNotDeparture != b->m_nCashTaxiNotDeparture) return true;
    if (a->m_nCashTaxiNotDestination != b->m_nCashTaxiNotDestination) return true;
    if (a->m_nCashCallMedicProhibit != b->m_nCashCallMedicProhibit) return true;
    if (a->m_nCashCallMarketProhibit != b->m_nCashCallMarketProhibit) return true;
    if (a->m_nRecallOtherUserProhibit != b->m_nRecallOtherUserProhibit) return true;
    if (a->m_nCheckFly != b->m_nCheckFly) return true;
    if (a->m_nCheckClimb != b->m_nCheckClimb) return true;
    if (a->m_nLimitMove != b->m_nLimitMove) return true;
    if (a->m_nCheckPartyObserve != b->m_nCheckPartyObserve) return true;
    if (a->m_nDoNotRevivalHere != b->m_nDoNotRevivalHere) return true;
    if (a->m_fCubeSkillIntervalTime != b->m_fCubeSkillIntervalTime) return true;
    if (a->m_nSkillUseDisableMask != b->m_nSkillUseDisableMask) return true;
    if (a->m_nInfinityMeratRevival != b->m_nInfinityMeratRevival) return true;
    if (a->m_nExploreType != b->m_nExploreType) return true;
    if (a->m_nTutorialType != b->m_nTutorialType) return true;
    if (a->m_unk_148 != b->m_unk_148) return true;
    if (a->m_nRequireQuest != b->m_nRequireQuest) return true;
    if (a->m_bMinimapPing != b->m_bMinimapPing) return true;
    if (a->m_bPopupMenu != b->m_bPopupMenu) return true;
    if (a->m_bGemSystem != b->m_bGemSystem) return true;
    if (a->m_fCameraHAngle != b->m_fCameraHAngle) return true;
    if (a->m_nCapacity != b->m_nCapacity) return true;
    if (FUN_140552700(a->m_vecDummyTargetPos, b->m_vecDummyTargetPos)) return true;
    if (FUN_140a56f50(&a->m_vecUnk17c, &b->m_vecUnk17c)) return true;
    if (a->m_nBgmId != b->m_nBgmId) return true;
    if (a->m_nBgmParam != b->m_nBgmParam) return true;
    if (a->m_fBgmValue != b->m_fBgmValue) return true;
    if (a->m_nBossBgmId != b->m_nBossBgmId) return true;
    if (a->m_nBossBgmParam != b->m_nBossBgmParam) return true;
    if (a->m_fBossBgmValue != b->m_fBossBgmValue) return true;
    if (FUN_1401647e0(a->m_strEnterSystemSound, b->m_strEnterSystemSound)) return true;
    if (FUN_1401647e0(a->m_strBgMask, b->m_strBgMask)) return true;
    if (FUN_1401647e0(a->m_strBgDay, b->m_strBgDay)) return true;
    if (a->m_nVScroll != b->m_nVScroll) return true;
    if (a->m_nHScroll != b->m_nHScroll) return true;
    if (a->m_nUseEffLight != b->m_nUseEffLight) return true;
    if (a->m_nFieldName != b->m_nFieldName) return true;
    if (a->m_nEffectLOD != b->m_nEffectLOD) return true;
    if (a->m_nInstancingGrid != b->m_nInstancingGrid) return true;
    if (FUN_1401647e0(a->m_strMapEffectId, b->m_strMapEffectId)) return true;
    if (a->m_bFastGlow != b->m_bFastGlow) return true;
    if (a->m_nFastShimmer != b->m_nFastShimmer) return true;
    if (a->m_nGlobalNameTag != b->m_nGlobalNameTag) return true;
    if (a->m_nShowHitEffect != b->m_nShowHitEffect) return true;
    if (a->m_nApplyCameraOption != b->m_nApplyCameraOption) return true;
    if (a->m_fCameraExtraDistance != b->m_fCameraExtraDistance) return true;
    if (a->m_bNoSkipFrame != b->m_bNoSkipFrame) return true;
    if (a->m_fFov != b->m_fFov) return true;
    if (a->m_nUseDummyTarget != b->m_nUseDummyTarget) return true;
    if (a->m_bUnk1fc != b->m_bUnk1fc) return true;
    if (a->m_bFog != b->m_bFog) return true;
    if (a->m_nFogColor != b->m_nFogColor) return true;
    if (a->m_fFogNear != b->m_fFogNear) return true;
    if (a->m_fFogFar != b->m_fFogFar) return true;
    if (a->m_bHeightFog != b->m_bHeightFog) return true;
    if (a->m_nHeightFogColor != b->m_nHeightFogColor) return true;
    if (a->m_fHeightFogUpper != b->m_fHeightFogUpper) return true;
    if (a->m_fHeightFogLower != b->m_fHeightFogLower) return true;
    if (a->m_fHeightFogPercentage != b->m_fHeightFogPercentage) return true;
    if (a->m_bHdr != b->m_bHdr) return true;
    if (a->m_fHdrThreshold != b->m_fHdrThreshold) return true;
    if (a->m_fHdrOffset != b->m_fHdrOffset) return true;
    if (a->m_fHdrMiddleGray != b->m_fHdrMiddleGray) return true;
    if (a->m_fHdrBloomScale != b->m_fHdrBloomScale) return true;
    if (a->m_fHdrGlowScale != b->m_fHdrGlowScale) return true;
    if (a->m_bUnk238 != b->m_bUnk238) return true;
    if (a->m_fCameraDistance != b->m_fCameraDistance) return true;
    if (a->m_fCameraVAngle != b->m_fCameraVAngle) return true;
    if (a->m_fZoomOutHeightOffset != b->m_fZoomOutHeightOffset) return true;
    if (a->m_fZoomInHeightOffset != b->m_fZoomInHeightOffset) return true;
    if (a->m_bUseFileSetting != b->m_bUseFileSetting) return true;
    if (a->m_fShadowIntensity != b->m_fShadowIntensity) return true;
    if (a->m_fShadowSimple != b->m_fShadowSimple) return true;
    if (a->m_nShadowOptionHighLevel != b->m_nShadowOptionHighLevel) return true;
    return false;
}

// @0x140a55460
MS2Ptr<CFieldDataCli> CFieldDataCli::Find(int fieldId)
{
    MS2Ptr<CFieldData> sp = CFieldData::FUN_140374140(fieldId);
    return MS2Ptr<CFieldDataCli>(dynamic_cast<CFieldDataCli*>((CFieldData*)sp));
}

// @0x140a55500
bool CFieldDataCli::vfunc_1(Unk_140165cf0* node)
{
    if (!CFieldData::vfunc_1(node))
        return false;
    Unk_140165cf0* e = node->FUN_140165cf0("ui");
    if (e) {
        FUN_1408733e0(e, "bgMask", m_strBgMask);
        FUN_1408731e0(e, "vscroll", m_nVScroll);
        FUN_1408731e0(e, "hscroll", m_nHScroll);
        FUN_1408731e0(e, "useEffLight", m_nUseEffLight);
        FUN_1408731e0(e, "fieldName", m_nFieldName);
        FUN_1408731e0(e, "effectLOD", m_nEffectLOD);
        FUN_140873260(e, "instancingGrid", m_nInstancingGrid);
        FUN_1408731e0(e, "fallDamage", m_nFallDamage);
        FUN_1408731e0(e, "useEPSkill", m_nUseEPSkill);
        FUN_1408731e0(e, "useRidee", m_nUseRidee);
        FUN_1408731e0(e, "usePet", m_nUsePet);
        FUN_1408731e0(e, "globalNameTag", m_nGlobalNameTag);
        FUN_1408731e0(e, "useOptimalHide", m_nUseOptimalHide);
        FUN_1408731e0(e, "showHitEffect", m_nShowHitEffect);
        FUN_1408731e0(e, "applyCameraOption", m_nApplyCameraOption);
        FUN_140873360(e, "cameraExtraDistance", m_fCameraExtraDistance);
        FUN_1408730a0(e, "isNoSkipFrame", m_bNoSkipFrame);
        FUN_1408731e0(e, "autoFindTaxiStation", m_nAutoFindTaxiStation);
        FUN_1408733e0(e, "mapEffectId", m_strMapEffectId);
    }
    e = node->FUN_140165cf0("bgm");
    if (e) {
        FUN_140873220(e, "id", m_nBgmId);
        FUN_140873220(e, "param", m_nBgmParam);
        FUN_140873360(e, "value", m_fBgmValue);
        FUN_140873220(e, "boss", m_nBossBgmId);
        FUN_140873220(e, "bossParam", m_nBossBgmParam);
        FUN_140873360(e, "bossValue", m_fBossBgmValue);
        FUN_1408733e0(e, "enterSystemSound", m_strEnterSystemSound);
    }
    e = node->FUN_140165cf0("hdr");
    if (e) {
        m_bHdr = true;
        FUN_140873360(e, "threshold", m_fHdrThreshold);
        FUN_140873360(e, "offset", m_fHdrOffset);
        FUN_140873360(e, "middlegray", m_fHdrMiddleGray);
        FUN_140873360(e, "bloomscale", m_fHdrBloomScale);
        FUN_140873360(e, "glowscale", m_fHdrGlowScale);
    }
    e = node->FUN_140165cf0("camera");
    if (e) {
        FUN_140873360(e, "distance", m_fCameraDistance);
        FUN_140873360(e, "hangle", m_fCameraHAngle);
        FUN_140873360(e, "vangle", m_fCameraVAngle);
        FUN_140873360(e, "zoomOutHeightOffset", m_fZoomOutHeightOffset);
        FUN_140873360(e, "zoomInHeightOffset", m_fZoomInHeightOffset);
        FUN_1408730a0(e, "useFileSetting", m_bUseFileSetting);
        Unk_140165cf0* t = (Unk_140165cf0*)FUN_14086f4b0(e, "dummyTargetPos");
        if (t) {
            FUN_141b6ed40(FUN_140188f50(t, 0), &m_vecDummyTargetPos);
        }
        t = (Unk_140165cf0*)FUN_14086f4b0(e, "usedummytarget");
        if (t) {
            FUN_14028d1a0(FUN_140188f50(t, 0), &m_nUseDummyTarget);
        }
    }
    e = node->FUN_140165cf0("shadow");
    if (e) {
        FUN_140873360(e, "intensity", m_fShadowIntensity);
        FUN_140873360(e, "simpleshadow", m_fShadowSimple);
        FUN_140a56ad0(e, "optionHighLevel", m_nShadowOptionHighLevel);
    }
    e = node->FUN_140165cf0("fov");
    if (e) {
        FUN_140873360(e, "value", m_fFov);
    }
    e = node->FUN_140165cf0("optimize");
    if (e) {
        FUN_1408730a0(e, "fastglow", m_bFastGlow);
        FUN_1408731e0(e, "fastshimmer", m_nFastShimmer);
    }
    LoadXBlock();
    return true;
}

// @0x140a55d20   (EH-less helper: fills a CStringW with the localized string 0x99d unless a flag is set)
bool FUN_140a55d20(CFieldDataCli* self, CStringW* out)
{
    extern void* FUN_14025e7c0();
    extern char FUN_14116d720(void*);
    extern CStringW FUN_14028de60(int id);
    extern CStringW FUN_1402a61e0(const wchar_t*);
    if (FUN_14116d720(FUN_14025e7c0()))
        return true;
    if (self->m_nEnterAdminLevel < 1)
        return true;
    *out = FUN_1402a61e0(FUN_14028de60(0x99d));
    return false;
}

// @0x140a55df0   loads <minimap> into a new CMinimap owned by the record (the pointer is consumed)
bool FUN_140a55df0(Unk_140165cf0* node, MS2Ptr<CFieldDataCli>* sp)
{
    if (node == 0) {
        FUN_1408850f0(sp);
        return false;
    }
    CMinimap* mm = new CMinimap();
    FUN_140a56e70(&FUN_140885340(sp)->m_spMinimap, mm);
    MS2Ptr<CMinimap> spMM(FUN_140885340(sp)->m_spMinimap);
    Unk_140165cf0* cam = node->FUN_140165cf0("camera");
    if (cam) {
        Unk_140165cf0* pos = (Unk_140165cf0*)FUN_14086f4b0(cam, "position");
        if (pos) {
            float v[3];
            FUN_140203800(v);
            FUN_14028c2d0(FUN_140188f50(pos, 0), v);
            spMM->m_vecCamPos = Unk_GVec3(v[0], v[1], v[2]);
        }
        Unk_140165cf0* rot = (Unk_140165cf0*)FUN_14086f4b0(cam, "rotation");
        if (rot) {
            float v[3];
            FUN_140203800(v);
            FUN_14028c2d0(FUN_140188f50(rot, 0), v);
            spMM->m_vecCamRot = Unk_GVec3(v[0], v[1], v[2]);
        }
    }
    Unk_140165cf0* fr = node->FUN_140165cf0("frustum");
    if (fr) {
        FUN_140873360(fr, "left", spMM->m_frustum.l);
        FUN_140873360(fr, "right", spMM->m_frustum.r);
        FUN_140873360(fr, "top", spMM->m_frustum.t);
        FUN_140873360(fr, "bottom", spMM->m_frustum.b);
        FUN_140873360(fr, "near", spMM->m_frustum.n);
        FUN_140873360(fr, "far", spMM->m_frustum.f);
        const char* s = FUN_14086f4b0(fr, "ortho");
        if (s) {
            if (strcmp(s, "true") == 0)
                spMM->m_frustum.ortho = true;
        }
    }
    Unk_140165cf0* sc = node->FUN_140165cf0("screen");
    if (sc) {
        FUN_140873360(sc, "left", spMM->m_rcScreen.l);
        FUN_140873360(sc, "right", spMM->m_rcScreen.r);
        FUN_140873360(sc, "top", spMM->m_rcScreen.t);
        FUN_140873360(sc, "bottom", spMM->m_rcScreen.b);
    }
    Unk_140165cf0* im = node->FUN_140165cf0("image");
    if (im) {
        if (spMM.get()) {
            const char* icon = FUN_14086f4b0(im, "icon");
            spMM->m_strImageIcon = icon;
            const char* nm = FUN_14086f4b0(im, "name");
            spMM->m_strImageName = nm;
        }
        FUN_140873360(im, "left", spMM->m_rcImage.l);
        FUN_140873360(im, "right", spMM->m_rcImage.r);
        FUN_140873360(im, "top", spMM->m_rcImage.t);
        FUN_140873360(im, "bottom", spMM->m_rcImage.b);
    }
    Unk_140165cf0* vis = node->FUN_140165cf0("visible");
    if (vis) {
        const char* s = FUN_14086f4b0(vis, "mypc");
        if (s) { if (strcmp(s, "false") == 0) spMM->m_bVisibleMyPC = 0; }
        s = FUN_14086f4b0(vis, "otherpc");
        if (s) { if (strcmp(s, "false") == 0) spMM->m_bVisibleOtherPC = 0; }
        s = FUN_14086f4b0(vis, "portal");
        if (s) { if (strcmp(s, "false") == 0) spMM->m_bVisiblePortal = 0; }
        s = FUN_14086f4b0(vis, "npc");
        if (s) { if (strcmp(s, "false") == 0) spMM->m_bVisibleNpc = 0; }
    }
    Unk_140165cf0* lim = node->FUN_140165cf0("limit");
    if (lim) {
        const char* s = FUN_14086f4b0(lim, "scale");
        if (s) { if (strcmp(s, "false") == 0) spMM->m_bLimitScale = 0; }
    }
    Unk_140165cf0* zm = node->FUN_140165cf0("edit");
    if (zm) {
        FUN_140873360(zm, "zoomfactor", spMM->m_fZoomFactor);
    }
    FUN_1408850f0(sp);
    return true;
}

// @0x140a56690   loads ./Data/Xml/MapXblock/<xblock>.xml (fog, heightfog, clientProperty, minimap)
bool CFieldDataCli::LoadXBlock()
{
    CString strPath;
    strPath.Format("./Data/Xml/MapXblock/%s.xml", (const char*)m_strXBlock);
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, (const char*)strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* root = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (root == 0)
        return false;
    Unk_140165cf0* fog = root->FUN_140165cf0("fog");
    if (fog) {
        m_bFog = true;
        const char* c = FUN_14086f4b0(fog, "color");
        if (c) {
            m_nFogColor = FUN_14028c0d0(CString(c));
        }
        FUN_140873360(fog, "near", m_fFogNear);
        FUN_140873360(fog, "far", m_fFogFar);
    }
    Unk_140165cf0* hf = root->FUN_140165cf0("heightfog");
    if (hf == 0) {
        m_bHeightFog = false;
        m_nHeightFogColor = 0;
        m_fHeightFogUpper = 0;
        m_fHeightFogLower = -500.0f;
        m_fHeightFogPercentage = 100.0f;
    } else {
        m_bHeightFog = true;
        const char* c = FUN_14086f4b0(hf, "color");
        if (c) {
            m_nHeightFogColor = FUN_14028c0d0(CString(c));
        }
        FUN_140873360(hf, "upper", m_fHeightFogUpper);
        FUN_140873360(hf, "lower", m_fHeightFogLower);
        FUN_140873360(hf, "percentage", m_fHeightFogPercentage);
    }
    Unk_140165cf0* cp = root->FUN_140165cf0("clientProperty");
    if (cp) {
        FUN_1408733e0(cp, "bgDay", m_strBgDay);
    }
    MS2Ptr<CFieldDataCli> self(this);
    FUN_140a55df0(root->FUN_140165cf0("minimap"), &self);
    return true;
}

// @0x140a56ad0
int FUN_140a56ad0(Unk_140165cf0* node, const char* name, int& out)
{
    int v = 0;
    int r = FUN_140873890(node, name, v);
    if (r == 0)
        out = v;
    return r;
}

// @0x140a56e70
MS2Ptr<CMinimap>* FUN_140a56e70(MS2Ptr<CMinimap>* self, CMinimap* p)
{
    struct Raw { void* u; CMinimap* p; };
    MS2Ptr<CMinimap> tmp(p);
    CMinimap* t = ((Raw*)&tmp)->p;
    ((Raw*)&tmp)->p = ((Raw*)self)->p;
    ((Raw*)self)->p = t;
    return self;
}

// @0x140a56c20
CMinimap::CMinimap()
    : m_rcImage(0, 0, 0, 0), m_rcScreen(0, 0, 0, 0), m_frustum(0)
{
    m_bVisibleMyPC = 1;
    m_bVisibleOtherPC = 1;
    m_bVisiblePortal = 1;
    m_bVisibleNpc = 1;
    m_bLimitScale = 1;
    m_fZoomFactor = 1.0f;
    m_vecCamPos = Unk_GVec3(*(Unk_GVec3*)&DAT_143b01a60);
    m_vecCamRot = Unk_GVec3(*(Unk_GVec3*)&DAT_143b01a60);
}

// @0x140a56db0
Unk_Vec3Cli::Unk_Vec3Cli(float x, float y, float z) : Unk_Vec3f(x, y, z) {}

// @0x140a56e30
CMinimap::~CMinimap()
{
}

// @0x140a56ee0
bool FUN_140a56ee0(const Unk_Vec3Cli* a, const Unk_Vec3Cli* b)
{
    bool r;
    if (b->x == a->x && b->y == a->y && b->z == a->z)
        r = true;
    else
        r = false;
    return r;
}

// @0x140a56f50
bool FUN_140a56f50(const Unk_Vec3Cli* a, const Unk_Vec3Cli* b)
{
    char r = FUN_140a56ee0(a, b);
    return r == 0;
}
// Atexit thunks of this unit's statics (gap2 yd sweep, yd2).
// MS2-RANGE: 0x142c9f4f0-0x142c9f520 .text$yd

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
#include "hook/ms2hook.h"
MS2_REPLACE(0x140a545d0, FUN_140a545d0, 3707, 0xDC1BDE1E);
MS2_REPLACE_METHOD(0x140a55500, CFieldDataCli, vfunc_1, 2065, 0x80291AF9);
MS2_REPLACE(0x140a55d20, FUN_140a55d20, 190, 0x3768CF2B);
MS2_REPLACE_METHOD(0x140a56690, CFieldDataCli, LoadXBlock, 1079, 0x996652D0);
MS2_REPLACE(0x140a56ad0, FUN_140a56ad0, 131, 0x79F34C34);
MS2_REPLACE(0x140a56e70, FUN_140a56e70, 97, 0x97AA0EFC);
MS2_REPLACE(0x140a56ee0, FUN_140a56ee0, 100, 0x40E619D7);
MS2_REPLACE(0x140a56f50, FUN_140a56f50, 64, 0xF740D9EC);

