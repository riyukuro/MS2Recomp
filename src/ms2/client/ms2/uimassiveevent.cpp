// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIMassiveEvent, the HUD popup of the massive event.
// MS2-UNIT: ?\uimassiveevent.cpp
// MS2-RANGE: 0x1419f55d0-0x1419f71e0 .text$mn
// MS2-RANGE: 0x1401166e0-0x1401167a0 .text$di
// MS2-RANGE: 0x142cbf550-0x142cbf5d0 .text$yd
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "uimassiveevent.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/stringidinterface.h"
#include "ms2/client/ms2/uieventintroduce.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <errno.h>
#include <string.h>

// ---- unit-local views of exe objects ----

class Unk_140a94350                                                 // the scene sound/cinematic manager
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(int n);
};
Unk_140a94350* FUN_140a94350();

class Unk_140a87690 { public: CStringW FUN_14087ede0(const CStringW& str); };      // the text filter
class Unk_140a87680 { public: Unk_140a87690* FUN_140a87690(); };
Unk_140a87680* FUN_140a87680();

class Unk_ExpUiScale { public: float FUN_1422afec0(int nUiId); };
Unk_ExpUiScale* FUN_14025e7a0();
struct Unk_JcInvoke4 { Scaleform::GFx::Value FUN_14190b490(const char* szMethod, unsigned nW, unsigned nH, float fScale); };

int FUN_1412755a0();
unsigned int FUN_140869420();                                       // the tick
int FUN_141276180(const CString& strSound, const CString& strArg);  // play a sound
CString FUN_140513200(const char* szFormat, const unsigned int& n); // "{0}" substitution
void FUN_1412751b0(const CStringW& strText, int nKind);             // chat/system message
CStringW FUN_14028de60(int nStringId);                              // string table text by id
CStringW FUN_14062b4f0(CStringW strKey, const int& nValue);         // string table text with one argument
void FUN_140cffde0(const Scaleform::GFx::Value& root, CString strName, int nValue);   // set an int member of a clip
UIEventIntroduce* FUN_140dbf520(int nUiId);                         // a UI by its type id
template <> MS2Ptr<ASMovieClip> UISwfEntity::GetChild<ASMovieClip>(const CString& strName);

static CString s_strFail("massive_fail");                            // 0x143af3aa8
static CString s_strSuccess("massive_success");                     // 0x143af3b00
static CString s_strBattleWin("BattleField_Win");                   // 0x143af3b08
static CString s_strPcWin("PC_win_game");                           // 0x143af3af8
extern unsigned int DAT_143af62d4;                                  // client area width
extern unsigned int DAT_143af62d8;                                  // client area height

// @0x1419f55d0
UIMassiveEvent::UIMassiveEvent() : m_nRemain(0), m_nType(0), m_80(0), m_bStage(0)
{
    m_58 = 0;
    m_2c = 0x1e;
}

// @0x1419f56b0
UIMassiveEvent::~UIMassiveEvent()
{
}

// @0x1419f5740
CString UIMassiveEvent::vfunc_1()
{
    return "MassiveEvent";
}

// @0x1419f5790
void UIMassiveEvent::vfunc_2()
{
    if (FUN_1412755a0())
        return;
    FUN_1422dbf00(0x1e, 0, 0);
}

// @0x1419f57d0
void UIMassiveEvent::vfunc_3()
{
    if (FUN_1412755a0())
        return;
    FUN_1422dc080();
}

// @0x1419f5800
void UIMassiveEvent::OnLoadComplete()
{
    UIObject::OnLoadComplete();
    m_spCounter = GetChild<ASMovieClip>("m_counter");
    m_spTime = m_spCounter->FUN_1409b4560("time");
}

// @0x1419f5920
void UIMassiveEvent::vfunc_43()
{
    MS2Ptr<ASDisplayObject> spRoot = FUN_1422dba50();
    if (spRoot.get())
    {
        spRoot->vfunc_2(5, 0, 0);
        float fScale = FUN_14025e7a0()->FUN_1422afec0(m_28);
        reinterpret_cast<Unk_JcInvoke4*>(spRoot.operator->())->FUN_14190b490("setStageSize", DAT_143af62d4, DAT_143af62d8, fScale);
        spRoot->vfunc_3(1);
    }
}

// @0x1419f5a30
void UIMassiveEvent::vfunc_15()
{
    if (!FUN_1422dc2d0())
        return;
    FUN_1419f5dd0();
}

// @0x1419f5a60
void UIMassiveEvent::vfunc_26()
{
    UIObject::vfunc_26();
    m_spCounter = 0;
    m_spTime = 0;
}

// @0x1419f5ab0
void UIMassiveEvent::FUN_1419f5ab0()
{
    FUN_1419f6df0(0, 0, 0, 0);
}

// @0x1419f5ae0
void UIMassiveEvent::FUN_1419f5ae0(int nSeconds)
{
    m_nRemain = nSeconds;
    m_nDeadline = FUN_140869420() + m_nRemain * 1000;
    FUN_1419f5b30();
}

// @0x1419f5b30
void UIMassiveEvent::FUN_1419f5b30()
{
    const unsigned int nMax = 9;
    if (m_nRemain > nMax)
        return;
    unsigned int nDigit = nMax - m_nRemain + 1;
    FUN_140cffde0((*m_spTime).FUN_1422bb890(), "m_number", nDigit);
    FUN_140cffde0((*m_spTime).FUN_1422bb890(), "m_numberOutline", nDigit);
    m_spTime->vfunc_12(1);
    FUN_1419f5c80();
}

// @0x1419f5c80
void UIMassiveEvent::FUN_1419f5c80()
{
    switch (m_nType)
    {
    case 1:
        FUN_141276180(FUN_140513200("Count0{0}", m_nRemain), "");
        FUN_141276180("Count_NumEffect", "");
        break;
    case 2:
        FUN_141276180("Count_NumEffect", "");
        break;
    }
}

// @0x1419f5dd0
void UIMassiveEvent::FUN_1419f5dd0()
{
    if (m_nRemain == 0)
        return;
    unsigned int nNow = FUN_140869420();
    if (m_nDeadline <= nNow)
    {
        m_nRemain = 0;
        m_30->Invoke("endCount");
        return;
    }
    int nSec = (m_nDeadline - nNow) / 1000 + 1;
    if (m_nRemain != nSec)
    {
        m_nRemain = nSec;
        FUN_1419f5b30();
    }
}

// @0x1419f5e90
void UIMassiveEvent::FUN_1419f5e90(CInPacket* pPacket)
{
    int nKind = pPacket->vfunc_o8_1();
    switch (nKind)
    {
    case 0:
        FUN_1419f5fc0(pPacket);
        break;
    case 1:
        FUN_1419f6240(pPacket);
        break;
    case 2:
        FUN_1419f66a0(pPacket);
        break;
    case 3:
        FUN_1419f6180(pPacket);
        break;
    case 4:
        FUN_1419f63d0(pPacket);
        break;
    case 5:
        FUN_1419f6520(pPacket);
        break;
    case 6:
        FUN_1419f65e0(pPacket);
        break;
    case 7:
        FUN_1419f60a0(pPacket);
        break;
    case 8:
        FUN_1419f6790(pPacket);
    }
}

// @0x1419f5fc0
void UIMassiveEvent::FUN_1419f5fc0(CInPacket* pPacket)
{
    int nStage = pPacket->vfunc_o8_3();
    int nA = pPacket->vfunc_o8_3();
    int nB = pPacket->vfunc_o8_3();
    int nC = pPacket->vfunc_o8_3();
    FUN_1419f6df0(nStage, nA, nB, nC);
}

// @0x1419f60a0
void UIMassiveEvent::FUN_1419f60a0(CInPacket* pPacket)
{
    int nRound = pPacket->vfunc_o8_3();
    bool bFinal = pPacket->vfunc_o8_0();
    int nGoal = pPacket->vfunc_o8_3();
    if (0 < nGoal)
    {
        UIEventIntroduce* pUI = FUN_140dbf520(0x4f06);
        if (pUI == 0)
            return;
        if (bFinal)
            pUI->FUN_140f41120(nGoal);
        else
            pUI->FUN_140f41190(nRound, nGoal);
    }
}

// @0x1419f6180
void UIMassiveEvent::FUN_1419f6180(CInPacket* pPacket)
{
    CStringW strText = StringIdInterface(*pPacket).FUN_141024e60();
    int nDuration = pPacket->vfunc_o8_3();
    FUN_1419f6810(6, strText, nDuration);
}

// @0x1419f6240
void UIMassiveEvent::FUN_1419f6240(CInPacket* pPacket)
{
    CStringW strText = pPacket->vfunc_o8_8();
    strText = FUN_140a87680()->FUN_140a87690()->FUN_14087ede0(strText);
    int nStep = pPacket->vfunc_o8_3();
    int nDuration = pPacket->vfunc_o8_3();
    int nType = pPacket->vfunc_o8_3();
    FUN_1419f6bc0(CStringW(strText), nStep, nDuration, nType);
}

// @0x1419f63d0
void UIMassiveEvent::FUN_1419f63d0(CInPacket* pPacket)
{
    CStringW strText = StringIdInterface(*pPacket).FUN_141024e60();
    int nStep = pPacket->vfunc_o8_3();
    int nDuration = pPacket->vfunc_o8_3();
    int nType = pPacket->vfunc_o8_3();
    FUN_1419f6bc0(CStringW(strText), nStep, nDuration, nType);
}

// @0x1419f6520
void UIMassiveEvent::FUN_1419f6520(CInPacket* pPacket)
{
    CStringW strText = StringIdInterface(*pPacket).FUN_141024e60();
    int nDuration = pPacket->vfunc_o8_3();
    FUN_1419f6810(2, strText, nDuration);
}

// @0x1419f65e0
void UIMassiveEvent::FUN_1419f65e0(CInPacket* pPacket)
{
    CStringW strText = StringIdInterface(*pPacket).FUN_141024e60();
    int nDuration = pPacket->vfunc_o8_3();
    FUN_1419f6810(1, strText, nDuration);
}

// @0x1419f66a0
void UIMassiveEvent::FUN_1419f66a0(CInPacket* pPacket)
{
    int nSubType = pPacket->vfunc_o8_1();
    CStringW strRaw = pPacket->vfunc_o8_8();
    CStringW strText = FUN_140a87680()->FUN_140a87690()->FUN_14087ede0(strRaw);
    int nDuration = pPacket->vfunc_o8_3();
    FUN_1419f6810(nSubType, strText, nDuration);
}

// @0x1419f6790
void UIMassiveEvent::FUN_1419f6790(CInPacket* pPacket)
{
    int nDuration = pPacket->vfunc_o8_3();
    FUN_1419f6bc0(FUN_14028de60(0x974), 0, nDuration, 2);
}

// MS2-FUNCTIONAL: the exe's case 2 arm ends in two jmps (+10 bytes); no source form found
// @0x1419f6810
void UIMassiveEvent::FUN_1419f6810(int nSubType, CStringW& strText, int nDuration)
{
    FUN_1419f6a70(nSubType, strText, nDuration);
    switch (nSubType)
    {
    case 0:
        FUN_141276180(s_strFail, "");
        break;
    case 1:
        FUN_141276180(s_strFail, "");
        break;
    case 2:
        FUN_141276180(s_strPcWin, "");
        FUN_141276180(s_strSuccess, "");
        FUN_141276180(s_strBattleWin, "");
        FUN_140a94350()->vfunc_10(9);
        break;
    case 5:
        FUN_141276180(s_strBattleWin, "");
        FUN_140a94350()->vfunc_10(9);
        break;
    case 6:
        strText.Replace(L"\\n", L"\n");
        FUN_1412751b0(strText, 0x13);
        break;
    }
}

// MS2-FUNCTIONAL: the exe copies the text before evaluating m_30.operator->() for the member call; mine evaluates the object first
// @0x1419f6a70
void UIMassiveEvent::FUN_1419f6a70(int nSubType, CStringW strText, int nDuration)
{
    if (m_30.get() != 0)
    {
        strText.Replace(L"\\n", L"\n");
        ASObj* pObj = static_cast<ASObj*>(m_30.operator->());
        pObj->FUN_1407cb9c0("m_subType", nSubType);
        static_cast<ASObj*>(m_30.operator->())->FUN_1407cbb20("m_text", CStringW(strText));
        static_cast<ASObj*>(m_30.operator->())->FUN_1407cb9c0("m_duration", nDuration);
        m_30->Invoke("clearAndSetPanel");
    }
}

// @0x1419f6bc0
void UIMassiveEvent::FUN_1419f6bc0(CStringW strText, int nStep, int nDuration, int nType)
{
    if (m_30.get() != 0)
    {
        m_nType = nType;
        strText.Replace(L"\\n", L"\n");
        static_cast<ASObj*>(m_30.operator->())->FUN_1407cb9c0("m_subType", 8);
        static_cast<ASObj*>(m_30.operator->())->FUN_1407cbb20("m_text", CStringW(strText));
        static_cast<ASObj*>(m_30.operator->())->FUN_1407cb9c0("m_stepNum", nStep);
        static_cast<ASObj*>(m_30.operator->())->FUN_1407cbb20("m_strStepNum", FUN_14062b4f0(CStringW(L"s_massive_event_message_start"), nStep));
        static_cast<ASObj*>(m_30.operator->())->FUN_1407cbbe0("m_centerAlign", 0);
        m_30->Invoke("clearAndSetPanel");
        FUN_1419f5ae0(nDuration);
    }
}

// @0x1419f6df0
void UIMassiveEvent::FUN_1419f6df0(int nStage, int nA, int nB, int nC)
{
    if (m_30.get() != 0)
    {
        m_30->Invoke("setStage", nStage, nA, nB, nC);
        if (nA == 0)
            m_bStage = 0;
        else
            m_bStage = 1;
    }
}

// @0x1419f6eb0
void UIMassiveEvent::FUN_1419f6eb0()
{
    if (m_30 == 0)
        return;
    m_30->Invoke("onHidePanel");
}

// @0x1419f6f70
// memcpy_s (the CRT's _VALIDATE_RETURN_ERRCODE form, per-TU static __inline copy).
#pragma function(memset, memcpy)
static __inline errno_t ms2_memcpy_s_copy1(void* const d, size_t const dsz, void const* const s, size_t const ssz)
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
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnMemcpySCopy1)(void*, size_t, const void*, size_t) = &ms2_memcpy_s_copy1;

// @0x1419f70c0
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);

// ---- hooks ----
MS2_REPLACE_METHOD(0x1419F5740, UIMassiveEvent, vfunc_1, 61, 0x6859AE45);
MS2_REPLACE_METHOD(0x1419F5790, UIMassiveEvent, vfunc_2, 46, 0x1E96C254);
MS2_REPLACE_METHOD(0x1419F57D0, UIMassiveEvent, vfunc_3, 35, 0x30C8CD21);
MS2_REPLACE_METHOD(0x1419F5800, UIMassiveEvent, OnLoadComplete, 273, 0x3A530998);
MS2_REPLACE_METHOD(0x1419F5920, UIMassiveEvent, vfunc_43, 255, 0x17E9BEFD);
MS2_REPLACE_METHOD(0x1419F5A30, UIMassiveEvent, vfunc_15, 40, 0xC6DDECC3);
MS2_REPLACE_METHOD(0x1419F5A60, UIMassiveEvent, vfunc_26, 66, 0xD75ACC67);
MS2_REPLACE_METHOD(0x1419F5AB0, UIMassiveEvent, FUN_1419f5ab0, 40, 0xA8D93C19);
MS2_REPLACE_METHOD(0x1419F5AE0, UIMassiveEvent, FUN_1419f5ae0, 70, 0xB1D7DBC4);
MS2_REPLACE_METHOD(0x1419F5B30, UIMassiveEvent, FUN_1419f5b30, 325, 0x4BC9713D);
MS2_REPLACE_METHOD(0x1419F5C80, UIMassiveEvent, FUN_1419f5c80, 322, 0x543AB753);
MS2_REPLACE_METHOD(0x1419F5DD0, UIMassiveEvent, FUN_1419f5dd0, 185, 0xDCE8A878);
MS2_REPLACE_METHOD(0x1419F5E90, UIMassiveEvent, FUN_1419f5e90, 257, 0x75F5401D);
MS2_REPLACE_METHOD(0x1419F5FC0, UIMassiveEvent, FUN_1419f5fc0, 203, 0xC4AEAB65);
MS2_REPLACE_METHOD(0x1419F60A0, UIMassiveEvent, FUN_1419f60a0, 208, 0x71CBD7DA);
MS2_REPLACE_METHOD(0x1419F6180, UIMassiveEvent, FUN_1419f6180, 177, 0xC20F3482);
MS2_REPLACE_METHOD(0x1419F6240, UIMassiveEvent, FUN_1419f6240, 383, 0xDC51C886);
MS2_REPLACE_METHOD(0x1419F63D0, UIMassiveEvent, FUN_1419f63d0, 316, 0x7D568084);
MS2_REPLACE_METHOD(0x1419F6520, UIMassiveEvent, FUN_1419f6520, 177, 0x3731680A);
MS2_REPLACE_METHOD(0x1419F65E0, UIMassiveEvent, FUN_1419f65e0, 177, 0x961B55AD);
MS2_REPLACE_METHOD(0x1419F66A0, UIMassiveEvent, FUN_1419f66a0, 227, 0x272030A4);
MS2_REPLACE_METHOD(0x1419F6790, UIMassiveEvent, FUN_1419f6790, 118, 0x2C000B7D);
MS2_REPLACE_METHOD(0x1419F6810, UIMassiveEvent, FUN_1419f6810, 589, 0x04AE13FB);
MS2_REPLACE_METHOD(0x1419F6A70, UIMassiveEvent, FUN_1419f6a70, 330, 0x208418B6);
MS2_REPLACE_METHOD(0x1419F6BC0, UIMassiveEvent, FUN_1419f6bc0, 539, 0x805B3EB9);
MS2_REPLACE_METHOD(0x1419F6DF0, UIMassiveEvent, FUN_1419f6df0, 171, 0x4760258B);
MS2_REPLACE_METHOD(0x1419F6EB0, UIMassiveEvent, FUN_1419f6eb0, 89, 0x288DD250);
