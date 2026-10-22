// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The player's movement controller (PCBase +0x6d8, see
// actionkeyobject.cpp): the move-key state tracker (which arrow/dash keys are down, which buffs block them) and the
// knock-back / forced-move direction it derives. Unit and member names are invented from use.
// MS2-UNIT: unit_141682f80
// MS2-RANGE: 0x141682f80-0x1416841a0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2layout.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The exe stores the unit components as IEEE bit patterns (mov dword, 0x3f800000), so the fields are plain dwords here.
#pragma pack(push, 1)
struct Vector3 { unsigned x, y, z; };
#pragma pack(pop)
enum { UNK_ONE = 0x3f800000, UNK_MINUS_ONE = 0xbf800000 };

// The controlled actor (PCBase); only the virtuals this unit calls matter.
class Unk_PCActor
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual int GetKind();
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
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_59();
    virtual void vfunc_60();
    virtual void vfunc_61();
    virtual void vfunc_62();
    virtual int FUN_slot_1f8();
};

class Unk_PCTimer;      // the 0x38-byte key repeat timer at +8
class Unk_PCBuffTable;  // FUN_1409331e0 / FUN_1409331f0 singletons (buff block / buff lookup tables)
class Unk_PCClimb;
struct Unk_PCBuffKey { int m_nId; int m_nExtra; };
class Unk_PCServices;

// The movement controller (0x58).
class Unk_PCMove
{
public:
    bool FUN_141682f80(int nKey);
    bool FUN_141682fe0(int nKey);
    bool FUN_1416830b0(int nKey);
    bool FUN_141683100(int nKey);
    bool FUN_141683150(int nKey);
    bool FUN_141683200(int nKey);
    Vector3* FUN_141683290(Vector3* pOut);
    Vector3* FUN_1416836d0(Vector3* pOut);
    Vector3* FUN_141683900(Vector3* pOut);
    bool FUN_1416839b0();
    void FUN_141683a90();
    bool FUN_141683ef0();
    int FUN_141684060(int nKey);
    bool FUN_1416840c0(int nKey);
    bool FUN_141684170(int nKey);

    Unk_PCActor* m_pOwner;                  // +0x00
    char m_timer[0x38];                     // +0x08
    Vector3 m_dir;                  // +0x40
    int m_moving;                           // +0x4c
    int m_ready;                            // +0x50
    int m_pad54;
};
MS2_CHECK_OFFSET(Unk_PCMove, m_dir, 0x40);
MS2_CHECK_OFFSET(Unk_PCMove, m_moving, 0x4c);
MS2_CHECK_OFFSET(Unk_PCMove, m_ready, 0x50);

extern int DAT_143af7d40;                   // input enabled
extern Vector3 DAT_143b01a60;       // the zero point

// Out-of-unit callees.
Unk_PCServices* FUN_14025e7c0();
bool FUN_14116dbf0(Unk_PCServices* p, char* pOut16, char* pOut4, int* pValue, int a, int b);
bool FUN_14116d7a0(Unk_PCServices* p, int n);
Unk_PCBuffTable* FUN_1409331e0();
Unk_PCBuffTable* FUN_1409331f0();
int FUN_14138c900(Unk_PCBuffTable* p, int n);
int FUN_14138c930(Unk_PCBuffTable* p, int n);
int FUN_14142c270(Unk_PCBuffTable* p, int n);
int FUN_14142c4b0(Unk_PCBuffTable* p, int n);
int FUN_14142c540(Unk_PCBuffTable* p, int n);
int FUN_14142c940(Unk_PCBuffTable* p, int n, int m);
Unk_PCBuffKey FUN_14142d190(Unk_PCBuffTable* p, int n);
void* FUN_1403ed2d0();
void FUN_141bca010(void* p);
int FUN_141bdb5e0(void* p);
Unk_PCActor* FUN_141bd0cc0(void* p);
void* FUN_140a58540();
bool FUN_140d8ac50(void* p, int n, int m);
bool FUN_140d8ad60(void* p, int n);
bool FUN_140d8af70(void* p, int n);
bool FUN_140d8c550(void* p);
void FUN_140d8c2f0(void* p, Vector3* pOut);
void* FUN_140a58500(void* p);
int FUN_140a58520(void* p);
Unk_PCActor* FUN_141468360(Unk_PCActor* p);
Unk_PCActor* FUN_141706540(Unk_PCActor* p);
void* FUN_1416749a0(Unk_PCActor* p);
int FUN_140970a40(void* p);
Unk_PCClimb* FUN_140953f30();
int FUN_140ad21f0(Unk_PCClimb* p);
void FUN_140ad2070(Unk_PCClimb* p);
void* FUN_140ad22a0(Unk_PCClimb* p, char* pBuf32);
void FUN_140194470(Vector3* pDst, void* pSrc);
bool FUN_140552690(Vector3* a, Vector3* b);
bool FUN_140552700(Vector3* a, Vector3* b);
void FUN_140ad0c10(Vector3* p, float f);
void* FUN_140166410();
bool FUN_14036d570(void* p, int n);
void* FUN_1409a8b10();
void* FUN_140c8dac0();
bool FUN_140d07330(void* p);
void FUN_140868750(char* pTimer, int n);
int FUN_140868ba0(char* pTimer);
void FUN_1408687f0(char* pTimer);
int FUN_141671b20(Unk_PCActor* p);
int FUN_14166ce30(Unk_PCActor* p);
int FUN_1416596d0(Unk_PCActor* p);
int FUN_1409709b0(void* p);
void* FUN_1409478c0();
bool FUN_140aed3e0(void* p);

// @0x141682f80
bool Unk_PCMove::FUN_141682f80(int nKey)
{
    if (DAT_143af7d40 == 0)
        return false;
    if (!FUN_141684170(nKey))
        return false;
    return FUN_140d8ac50(FUN_140a58540(), nKey, 0);
}

// @0x141682fe0
// MS2-FUNCTIONAL: extra EH-free temporaries in the exe (stack frame differs); logic identical
bool Unk_PCMove::FUN_141682fe0(int nKey)
{
    if (DAT_143af7d40 == 0)
        return false;
    char abyPos[16];
    char abyDir[4];
    int nValue;
    if (FUN_14116dbf0(FUN_14025e7c0(), abyPos, abyDir, &nValue, 0, 0)) {
        if (nKey == 0x493e8 && 0 < nValue)
            return true;
        if (nKey == 0x493e9 && nValue < 0)
            return true;
    }
    if (!FUN_1416840c0(nKey))
        return false;
    if (FUN_14142c270(FUN_1409331f0(), nKey) == 0)
        return false;
    if (FUN_1403ed2d0() != 0)
        FUN_141bca010(FUN_1403ed2d0());
    return true;
}

// @0x1416830b0
bool Unk_PCMove::FUN_1416830b0(int nKey)
{
    if (DAT_143af7d40 == 0)
        return false;
    if (!FUN_141684170(nKey))
        return false;
    return FUN_140d8ad60(FUN_140a58540(), nKey);
}

// @0x141683100
bool Unk_PCMove::FUN_141683100(int nKey)
{
    if (!FUN_1416840c0(nKey))
        return false;
    if (FUN_14142c4b0(FUN_1409331f0(), nKey) != 0)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x141683100, Unk_PCMove, FUN_141683100, 70, 0x1110430A);

// @0x141683150
// MS2-FUNCTIONAL: exe routes the key id through a by-value 4-byte temp before FUN_14138c930; logic identical
bool Unk_PCMove::FUN_141683150(int nKey)
{
    if (DAT_143af7d40 == 0)
        return false;
    if (!FUN_141683ef0())
        return true;
    int nId = FUN_141684060(nKey);
    if (FUN_14138c930(FUN_1409331e0(), nId) != 0)
        return false;
    if (FUN_141684060(nKey) == 0x493e1) {
        if (FUN_141bdb5e0(FUN_1403ed2d0()) != 0)
            return false;
    }
    return FUN_140d8af70(FUN_140a58540(), nKey);
}

// @0x141683200
bool Unk_PCMove::FUN_141683200(int nKey)
{
    if (DAT_143af7d40 == 0)
        return false;
    if (!FUN_141683ef0())
        return true;
    if (FUN_14138c930(FUN_1409331e0(), nKey) != 0)
        return false;
    if (nKey == 0x493e1) {
        if (FUN_141bdb5e0(FUN_1403ed2d0()) != 0)
            return false;
    }
    if (FUN_14142c540(FUN_1409331f0(), nKey) != 0)
        return true;
    return false;
}

// @0x141683290
// MS2-FUNCTIONAL: exe has no /GS cookie on the 12-byte direction local and different branch layout; logic identical
Vector3* Unk_PCMove::FUN_141683290(Vector3* pOut)
{
    Vector3 kDir = DAT_143b01a60;
    if (FUN_14138c900(FUN_1409331e0(), 0x15) != 0) {
        *pOut = kDir;
        return pOut;
    }
    if (FUN_14138c900(FUN_1409331e0(), 0x14) != 0) {
        *pOut = kDir;
        return pOut;
    }
    if (FUN_141682fe0(0x30d43)) {
        kDir.x = UNK_ONE;
    } else if (FUN_141682fe0(0x30d44)) {
        kDir.x = UNK_MINUS_ONE;
    }
    if (FUN_141682fe0(0x30d41)) {
        kDir.y = UNK_ONE;
    } else if (FUN_141682fe0(0x30d42)) {
        kDir.y = UNK_MINUS_ONE;
    }
    if (FUN_141682fe0(0x30d45)) {
        kDir.x = UNK_ONE;
        kDir.y = UNK_ONE;
    } else if (FUN_141682fe0(0x30d46)) {
        kDir.x = UNK_MINUS_ONE;
        kDir.y = UNK_ONE;
    } else if (FUN_141682fe0(0x30d47)) {
        kDir.x = UNK_ONE;
        kDir.y = UNK_MINUS_ONE;
    } else if (FUN_141682fe0(0x30d48)) {
        kDir.x = UNK_MINUS_ONE;
        kDir.y = UNK_MINUS_ONE;
    }
    bool bFlipped = false;
    if (m_pOwner != 0) {
        Unk_PCActor* pActor = m_pOwner;
        Unk_PCActor* pBase = FUN_141468360(m_pOwner);
        if (pBase != 0)
            pActor = FUN_141706540(pBase);
        if (pActor != 0) {
            if (FUN_140970a40(FUN_1416749a0(pActor)) != 0)
                bFlipped = true;
        }
    }
    if (FUN_140953f30() != 0) {
        if (FUN_140ad21f0(FUN_140953f30()) == 0) {
            FUN_140ad2070(FUN_140953f30());
        } else if (FUN_140552690(&kDir, &DAT_143b01a60)) {
            char abyBuf[32];
            FUN_140194470(&kDir, FUN_140ad22a0(FUN_140953f30(), abyBuf));
        }
    }
    if (FUN_14036d570(FUN_140166410(), 0xb5)) {
        char* pFlag = static_cast<char*>(FUN_140a58500(FUN_1409a8b10()));
        if (*pFlag != 0) {
            if (!FUN_141683ef0()) {
                *pOut = DAT_143b01a60;
                return pOut;
            }
            if (!FUN_140d8c550(FUN_140a58540())) {
                *pOut = DAT_143b01a60;
                return pOut;
            }
            if (FUN_140a58520(FUN_140a58540()) == 0) {
                Vector3 kCur;
                FUN_140d8c2f0(FUN_140a58540(), &kCur);
                if (FUN_140552700(&kCur, &DAT_143b01a60))
                    FUN_140194470(&kDir, &kCur);
            } else if (FUN_1416839b0()) {
                *pOut = DAT_143b01a60;
                return pOut;
            }
        }
    }
    if (bFlipped)
        FUN_140ad0c10(&kDir, -1.0f);
    *pOut = kDir;
    return pOut;
}

// @0x1416836d0
// MS2-FUNCTIONAL: exe has no /GS cookie on the 12-byte direction local; logic identical
Vector3* Unk_PCMove::FUN_1416836d0(Vector3* pOut)
{
    Vector3 kDir = DAT_143b01a60;
    if (FUN_141683100(0x30d43)) {
        kDir.x = UNK_ONE;
    } else if (FUN_141683100(0x30d44)) {
        kDir.x = UNK_MINUS_ONE;
    }
    if (FUN_141683100(0x30d41)) {
        kDir.y = UNK_ONE;
    } else if (FUN_141683100(0x30d42)) {
        kDir.y = UNK_MINUS_ONE;
    }
    if (FUN_141683100(0x30d45)) {
        kDir.x = UNK_ONE;
        kDir.y = UNK_ONE;
    } else if (FUN_141683100(0x30d46)) {
        kDir.x = UNK_MINUS_ONE;
        kDir.y = UNK_ONE;
    } else if (FUN_141683100(0x30d47)) {
        kDir.x = UNK_ONE;
        kDir.y = UNK_MINUS_ONE;
    } else if (FUN_141683100(0x30d48)) {
        kDir.x = UNK_MINUS_ONE;
        kDir.y = UNK_MINUS_ONE;
    }
    if (m_pOwner != 0) {
        Unk_PCActor* pActor = m_pOwner;
        Unk_PCActor* pBase = FUN_141468360(m_pOwner);
        if (pBase != 0)
            pActor = FUN_141706540(pBase);
        if (pActor != 0) {
            if (FUN_140970a40(FUN_1416749a0(pActor)) != 0)
                FUN_140ad0c10(&kDir, -1.0f);
        }
    }
    *pOut = kDir;
    return pOut;
}

// @0x141683900
Vector3* Unk_PCMove::FUN_141683900(Vector3* pOut)
{
    if (!FUN_141683ef0()) {
        *pOut = DAT_143b01a60;
        return pOut;
    }
    if (!FUN_1416839b0() && (m_moving != 0 || FUN_140868ba0(m_timer) != 0)) {
        *pOut = m_dir;
        return pOut;
    } else {
        FUN_141683290(pOut);
        return pOut;
    }
}

// @0x1416839b0
bool Unk_PCMove::FUN_1416839b0()
{
    if (FUN_141682f80(FUN_14142c940(FUN_1409331f0(), 0x30d41, 2)))
        return true;
    if (FUN_141682f80(FUN_14142c940(FUN_1409331f0(), 0x30d42, 2)))
        return true;
    if (FUN_141682f80(FUN_14142c940(FUN_1409331f0(), 0x30d43, 2)))
        return true;
    if (FUN_141682f80(FUN_14142c940(FUN_1409331f0(), 0x30d44, 2)))
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1416839B0, Unk_PCMove, FUN_1416839b0, 207, 0x4ABC09D2);

// @0x141683a90
// MS2-FUNCTIONAL: exe lays the key-pair chain out with gotos and shared tails; logic identical
void Unk_PCMove::FUN_141683a90()
{
    m_moving = 0;
    if ((FUN_141683200(0x30d43) && FUN_141682fe0(0x30d41)) || (FUN_141683200(0x30d41) && FUN_141682fe0(0x30d43))) {
        m_dir.x = UNK_ONE;
        m_dir.y = UNK_ONE;
        FUN_140868750(m_timer, 0x32);
    } else if ((FUN_141683200(0x30d43) && FUN_141682fe0(0x30d42)) || (FUN_141683200(0x30d42) && FUN_141682fe0(0x30d43))) {
        m_dir.x = UNK_ONE;
        m_dir.y = UNK_MINUS_ONE;
        FUN_140868750(m_timer, 0x32);
    } else if ((FUN_141683200(0x30d44) && FUN_141682fe0(0x30d41)) || (FUN_141683200(0x30d41) && FUN_141682fe0(0x30d44))) {
        m_dir.x = UNK_MINUS_ONE;
        m_dir.y = UNK_ONE;
        FUN_140868750(m_timer, 0x32);
    } else if ((FUN_141683200(0x30d44) && FUN_141682fe0(0x30d42)) || (FUN_141683200(0x30d42) && FUN_141682fe0(0x30d44))) {
        m_dir.x = UNK_MINUS_ONE;
        m_dir.y = UNK_MINUS_ONE;
        FUN_140868750(m_timer, 0x32);
    } else {
        bool bHeld = FUN_141683200(0x30d43) || FUN_141683200(0x30d44) || FUN_141683200(0x30d41) || FUN_141683200(0x30d42);
        if (bHeld && FUN_140868ba0(m_timer) != 0) {
            FUN_1408687f0(m_timer);
            m_moving = 1;
        } else {
            bool bReset;
            if ((FUN_141683200(0x30d43) || FUN_141683200(0x30d44)) && (FUN_141683200(0x30d41) || FUN_141683200(0x30d42))) {
                bReset = true;
            } else {
                bReset = FUN_141683100(0x30d43) || FUN_141683100(0x30d44) || FUN_141683100(0x30d41) || FUN_141683100(0x30d42);
            }
            if (bReset)
                FUN_1408687f0(m_timer);
        }
    }
    if (m_pOwner != 0) {
        Unk_PCActor* pActor = m_pOwner;
        Unk_PCActor* pBase = FUN_141468360(m_pOwner);
        if (pBase != 0)
            pActor = FUN_141706540(pBase);
        if (pActor != 0) {
            if (FUN_140970a40(FUN_1416749a0(pActor)) != 0)
                FUN_140ad0c10(&m_dir, -1.0f);
        }
    }
}

// @0x141683ef0
bool Unk_PCMove::FUN_141683ef0()
{
    if (m_pOwner == 0)
        return false;
    Unk_PCActor* pSelf = FUN_141bd0cc0(FUN_1403ed2d0());
    if (m_pOwner->GetKind() != 0x6200045 && pSelf != m_pOwner && FUN_141671b20(m_pOwner) == 0
        && m_pOwner->GetKind() != 0x6200064 && m_pOwner->GetKind() != 0x6200081)
        return false;
    if (FUN_14166ce30(pSelf) != 0)
        return false;
    if (FUN_14116d7a0(FUN_14025e7c0(), 0xf))
        return false;
    if (m_pOwner->FUN_slot_1f8() == 0)
        return false;
    if (m_ready == 0) {
        if (FUN_1409709b0(FUN_1416749a0(m_pOwner)) != 0)
            return false;
    }
    if (pSelf == m_pOwner && FUN_1416596d0(pSelf) != 0)
        return false;
    if (!FUN_140aed3e0(FUN_1409478c0()))
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x141683EF0, Unk_PCMove, FUN_141683ef0, 361, 0xC6E837A1);

// @0x141684060
int Unk_PCMove::FUN_141684060(int nKey)
{
    return FUN_14142d190(FUN_1409331f0(), nKey).m_nId;
}
MS2_REPLACE_METHOD(0x141684060, Unk_PCMove, FUN_141684060, 44, 0x77C6DB8A);

// @0x1416840c0
bool Unk_PCMove::FUN_1416840c0(int nKey)
{
    if (!FUN_141683ef0() && nKey != 0x493e8 && nKey != 0x493e9)
        return false;
    if (FUN_14138c930(FUN_1409331e0(), nKey) != 0)
        return false;
    if (nKey == 0x493e8 || nKey == 0x493e9) {
        if (FUN_140d07330(FUN_140c8dac0()))
            return false;
    }
    if (nKey == 0x493e1) {
        if (FUN_141bdb5e0(FUN_1403ed2d0()) != 0)
            return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x1416840C0, Unk_PCMove, FUN_1416840c0, 161, 0x5769705B);

// @0x141684170
bool Unk_PCMove::FUN_141684170(int nKey)
{
    return FUN_1416840c0(FUN_141684060(nKey));
}
MS2_REPLACE_METHOD(0x141684170, Unk_PCMove, FUN_141684170, 44, 0x56BEA03B);

// The preceding constructors and header statics belong to this controller TU.
// MS2-RANGE: 0x141682e90-0x141682f80 .text$mn
// MS2-RANGE: 0x1400fb790-0x1400fb920 .text$di
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/unk_1402a9d70.h"

static CString s_moveSortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_moveSkill("skill");
static CString s_moveStun("stun");
static Unk_1402a9d70 s_moveCondition(17, .75f, .25f, 2.25f, 10);

// @0x141682e90
Unk_PCBaseBuffTracker::Unk_PCBaseBuffTracker()
{
    m_p00 = 0;
    m_n50 = 0;
    m_pos40 = *reinterpret_cast<const efd::Point3*>(&DAT_143b01a60);
}

// @0x141682f30
Unk_PCBaseBuffTracker::~Unk_PCBaseBuffTracker()
{
}

// @0x141682f60
void FUN_141682f60(void* tracker, PCBase* owner)
{
    static_cast<Unk_PCMove*>(tracker)->m_pOwner = reinterpret_cast<Unk_PCActor*>(owner);
}

// MS2-PIN: ??__EkENTITY_INVALID@egf@@YAXXZ 0x1400fb8b0
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb40e0-0x142cb4170 .text$yd
