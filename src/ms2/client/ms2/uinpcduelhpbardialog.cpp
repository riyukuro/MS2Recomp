// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). NPC duel hp bar dialog. See uinpcduelhpbardialog.h.
// MS2-UNIT: client\ms2\uinpcduelhpbardialog.cpp
// MS2-RANGE: 0x140e6b7b0-0x140e6d3c0 .text$mn
// MS2-PIN: ?vfunc_48@UINpcDuelHPBarDialog@@UEAAHXZ 0x140e6d2a0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uinpcduelhpbardialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uinpcduelhpbardialog.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local declarations (names describe uses, not original class names) ----

// The effect (buff icon) container clip, created in OnLoadComplete (operator new 0x120; ctor 0x1409b5200).
class ASEffectManager : public ASDisplayObject
{
public:
    ASEffectManager(Scaleform::GFx::Value& root, int nMovieId);
    void FUN_1409b5610();                                       // per-tick refresh
    void FUN_1409b57b0(int x, int y);
    void FUN_1409b5810(int x, int y);
    void FUN_1409b5940(MS2Ptr<Unk_NdBuff> buff);                // add the buff icon
    void FUN_1409b5aa0(MS2Ptr<Unk_NdBuff> buff);                // remove the buff icon
    void FUN_1409b5b60(int nBuffId);
    void FUN_1409b5c20();                                       // clear the icons
private:
    unsigned char m_unrecovered_80[0xa0];
};
MS2_CHECK_SIZE(ASEffectManager, 0x120);

struct Unk_NdNpcRow;
// The actor (player or npc): only the virtual slots the dialog reads.
class Unk_NdActor
{
public:
    virtual ~Unk_NdActor();
        virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); 
    virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); 
    virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); 
    virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23(); virtual void vfunc_24(); 
    virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27(); virtual void vfunc_28(); virtual void vfunc_29(); virtual void vfunc_30(); 
    virtual void vfunc_31(); virtual void vfunc_32(); virtual void vfunc_33(); virtual void vfunc_34(); virtual void vfunc_35(); virtual void vfunc_36(); 
    virtual void vfunc_37(); virtual void vfunc_38(); virtual void vfunc_39(); virtual void vfunc_40(); virtual void vfunc_41(); virtual void vfunc_42(); 
    virtual void vfunc_43(); virtual void vfunc_44(); virtual void vfunc_45(); virtual void vfunc_46(); virtual void vfunc_47(); virtual void vfunc_48(); 
    virtual void vfunc_49(); virtual void vfunc_50(); virtual void vfunc_51(); virtual void vfunc_52(); virtual void vfunc_53(); virtual void vfunc_54(); 
    virtual void vfunc_55(); virtual void vfunc_56(); virtual void vfunc_57(); virtual void vfunc_58(); virtual void vfunc_59(); virtual void vfunc_60(); 
    virtual void vfunc_61(); virtual void vfunc_62(); virtual void vfunc_63(); virtual void vfunc_64(); virtual void vfunc_65(); virtual void vfunc_66(); 
    virtual void vfunc_67(); virtual void vfunc_68(); virtual void vfunc_69(); virtual void vfunc_70(); virtual void vfunc_71(); virtual void vfunc_72(); 
    virtual void vfunc_73(); virtual void vfunc_74(); virtual void vfunc_75(); virtual void vfunc_76();
    virtual CStringW vfunc_77();                                // 77 name (player)
    virtual short vfunc_78();                                   // 78 level
    __int64 FUN_141670a00(int nStat);                           // stat 4 = current hp
    __int64 FUN_141670a30(int nStat);                           // stat 4 = max hp
    CString FUN_1416612e0();                                    // profile picture path
    int FUN_141092fa0();                                        // npc id
    MS2Ptr<Unk_NdNpcRow> FUN_141093270();                               // the npc table row
};
class Unk_NdFlags { public: bool FUN_1401927c0(bool bFlag); };
struct Unk_NdBuffInfo { char m_pad[0xb8]; Unk_NdFlags m_flags; };
class Unk_NdBuff : public CPtred
{
public:
    Unk_NdActor* FUN_14096d280();                               // owner actor
    Unk_NdBuffInfo* FUN_14096d810();
    int m_18;                                                   // +0x18 buff id
};
MS2_CHECK_OFFSET(Unk_NdBuff, m_18, 0x18);
// the npc's table row (profile name at +0x90); refcounted
struct Unk_NdNpcRow : public CPtred { char m_pad[0x78]; CString m_90; };
MS2_CHECK_OFFSET(Unk_NdNpcRow, m_90, 0x90);
int FUN_1406cd310(Unk_NdNpcRow* pRow);                          // string id of the npc name
// a fixed-size list of buffs (0x30 bytes, hash map bins = 10)
struct Unk_NdBuffList { void* m_0; void* m_8; void* m_10; void* m_18; void* m_20; void* m_28; };
Unk_NdBuffList* FUN_1409750c0(Unk_NdBuffList* pList, int nBins);
void FUN_140975690(Unk_NdBuffList* pList);
POSITION FUN_140976550(Unk_NdBuffList* pList);
MS2Ptr<Unk_NdBuff>& FUN_140976370(Unk_NdBuffList* pList, POSITION pos);
void FUN_140976590(Unk_NdBuffList* pList, POSITION* pos);
struct Unk_NdBuffSource { void FUN_1409725f0(Unk_NdBuffList* pList); };
Unk_NdBuffSource* FUN_1416749a0(Unk_NdActor* pActor);

class Unk_NdWorld;
Unk_NdWorld* FUN_1403ed2d0();
Unk_NdActor* FUN_141bd0cc0(Unk_NdWorld* pWorld);                // the local player
Unk_NdActor* FUN_141bd1320(Unk_NdWorld* pWorld, int nObjectId);
unsigned int FUN_140869420();                                   // tick count (ms)
int FUN_141654730(Unk_NdActor* pPc);                            // job id
__int64 FUN_141656a80(Unk_NdActor* pPc);                        // account id
bool FUN_140930110(int nBuffId);
int FUN_14123c580(Unk_NdActor* pActor);                         // object id
class Unk_NdStrings { public: CStringW FUN_141811980(int nCategory, int nId); };
Unk_NdStrings* FUN_1401a9d70();
CStringW FUN_1401aa6a0(int nId);
CStringW FUN_1408f71a0(CStringW strKey, const CStringW& a, const CStringW& b);
CString FUN_141028be0(__int64 nAccountId, const CString& strPath, int nSize, CString strDefault);
CStringW FUN_140719dc0(const wchar_t* szFmt, const short& nValue);
void FUN_140cfee80(const Scaleform::GFx::Value& root, CString strName, CStringW strText);
void FUN_140cff1b0(const Scaleform::GFx::Value& root, CString strName, CStringW strText);
void FUN_140cff840(const Scaleform::GFx::Value& root, CString strName, int nVisible);
void FUN_140cffca0(const Scaleform::GFx::Value& root, CString strName, CString strIcon);
CStringW FUN_14062b4f0(CStringW strKey, const int* pValue);     // localized text with one {0} argument
unsigned char FUN_1409b0390(Scaleform::GFx::Value* pValue);

// the movie that creates AS objects by class name
class Unk_NdMovie { public: void FUN_14256e8e0(Scaleform::GFx::Value& out, const char* szClass, __int64 a1, int a2); };
Unk_NdMovie* FUN_1422bb8b0(int nMovieId);
MS2Ptr<ASEffectManager> FUN_140e6cd80(int nMovieId, CString strClass, __int64 a1, int a2);   // create the clip
CString FUN_140e6cf40(const char* szFmt, const int& nValue);    // format with one {0} argument

// AScript calls with a fixed argument list (the 3-argument one is this unit's own COMDAT copy)
class Unk_NdScript : public AScript
{
public:
    Scaleform::GFx::Value FUN_140cb6990(const char* szMethod, __int64 a1, __int64 a2);              // "setHpBarLeft"
    Scaleform::GFx::Value FUN_140e6cfe0(const char* szMethod, __int64 a1, __int64 a2, int a3);      // "setHpBarRight"
};
void FUN_1422bcdd0(Scaleform::GFx::Value* pValue, __int64 n);
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);

// string format helper with one {0} argument: the argument handle, the formatter table and the pack
struct Unk_FmtArg { const void* m_value; void* m_fn; };
struct Unk_FmtPack { __int64 m_n; const Unk_FmtArg* m_args; };
Unk_FmtArg* FUN_140e10ac0(Unk_FmtArg* pOut, const int& nValue);     // constructs the argument handle, returns it
__int64 FUN_140e116e0(const int& nValue);
Unk_FmtPack* FUN_140163e50(Unk_FmtPack* pOut, __int64 n, Unk_FmtArg arg);    // constructs the pack, returns it
CString FUN_1402bf9a0(const char* szFmt, const Unk_FmtPack& pack);

// ---- the dialog ----

// @0x140e6b7b0
UINpcDuelHPBarDialog::UINpcDuelHPBarDialog()
{
    FUN_141924170(1);
    FUN_141925e70(0, 1);
    m_nObjectId = 0;
    m_nBarCount = 1;
}

// @0x140e6b850
UINpcDuelHPBarDialog::~UINpcDuelHPBarDialog()
{
}

// @0x140e6b8a0
CString UINpcDuelHPBarDialog::GetTypeName()
{
    return "NpcDuelHPBarDialog";
}

// @0x140e6b8f0
void UINpcDuelHPBarDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    m_nObjectId = 0;
    m_nEndTick = 0;
    m_nBarCount = 1;
    m_effects = 0;
}

// @0x140e6b950
void UINpcDuelHPBarDialog::vfunc_72()
{
    if (m_30 == 0)
        return;
    FUN_140e6c7a0();
    FUN_140e6c900();
    FUN_140e6c9c0();
    if (m_effects.get() != 0)
        m_effects->FUN_1409b5610();
}

// @0x140e6b9e0
void UINpcDuelHPBarDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_effects = FUN_140e6cd80(2, "flash.display.MovieClip", 0, 0);
    m_effects->FUN_1409b57b0(0x2c4, 0x3c);
    m_effects->FUN_1409b5810(0x2c4, 0x69);
    m_30->Invoke("addChild", m_effects->FUN_1422bb870());
    FUN_140e6bc10();
}

// @0x140e6bb70
void UINpcDuelHPBarDialog::FUN_140e6bb70(int nObjectId, int nDurationMs, int nBarCount)
{
    m_nObjectId = nObjectId;
    m_nEndTick = FUN_140869420() + nDurationMs;
    m_nBarCount = nBarCount;
    if (m_nBarCount == 0)
        m_nBarCount = 1;
    if (m_30 == 0)
        return;
    FUN_140e6bc10();
}

// @0x140e6bc10
// MS2-FUNCTIONAL: small CString locals sit 0x10 lower than the exe's stack layout
void UINpcDuelHPBarDialog::FUN_140e6bc10()
{
    if (m_nObjectId == 0)
        return;
    Unk_NdActor* pPc = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPc != 0) {
        FUN_140cfee80(FUN_1422dbc00(), "m_leftName", pPc->vfunc_77());
        int nJob = FUN_141654730(pPc);
        CString strJobIcon = FUN_140e6cf40("_{0}", nJob);
        FUN_140cffca0(FUN_1422dbc00(), "m_leftJobIcon", strJobIcon);
        CString strProfile = FUN_141028be0(FUN_141656a80(pPc), pPc->FUN_1416612e0(), 1, "");
        ((Unk_NdScript*)m_30.operator->())->Invoke("setLeftProfile", strProfile);
        FUN_140e6c900();
    }
    Unk_NdActor* pNpc = FUN_141bd1320(FUN_1403ed2d0(), m_nObjectId);
    if (pNpc != 0) {
        CStringW strName = FUN_1408f71a0(L"s_npc_duelhpbar_dialog_right_name", FUN_1401aa6a0(pNpc->FUN_141092fa0()),
            FUN_1401a9d70()->FUN_141811980(0x11, FUN_1406cd310(pNpc->FUN_141093270().operator->())));
        FUN_140cff1b0(FUN_1422dbc00(), "m_rightName", strName);
        FUN_140cfee80(FUN_1422dbc00(), "m_rightLevel", FUN_140719dc0(L"{0}", pNpc->vfunc_78()));
        CString strProfile(pNpc->FUN_141093270()->m_90);
        m_30->Invoke("setRightProfile", strProfile);
        FUN_140e6c9c0();
        m_effects->FUN_1409b5c20();
        Unk_NdBuffList list;
        FUN_1409750c0(&list, 10);
        FUN_1416749a0(pNpc)->FUN_1409725f0(&list);
        for (POSITION pos = FUN_140976550(&list); pos != 0; FUN_140976590(&list, &pos)) {
            MS2Ptr<Unk_NdBuff> buff = FUN_140976370(&list, pos);
            if (!(buff == 0)) {
                bool bFlag = FUN_140930110(buff->m_18);
                if (buff->FUN_14096d810()->m_flags.FUN_1401927c0(bFlag))
                    FUN_140e6c440(buff);
            }
        }
        FUN_140975690(&list);
    }
}

// @0x140e6c440
void UINpcDuelHPBarDialog::FUN_140e6c440(MS2Ptr<Unk_NdBuff> buff)
{
    if (m_30 == 0)
        return;
    if (m_effects == 0)
        return;
    if (FUN_14123c580(buff->FUN_14096d280()) != m_nObjectId)
        return;
    m_effects->FUN_1409b5940(buff);
}

// @0x140e6c540
void UINpcDuelHPBarDialog::FUN_140e6c540(MS2Ptr<Unk_NdBuff> buff)
{
    if (m_30 == 0)
        return;
    if (m_effects == 0)
        return;
    if (FUN_14123c580(buff->FUN_14096d280()) != m_nObjectId)
        return;
    m_effects->FUN_1409b5aa0(buff);
}

// @0x140e6c640
void UINpcDuelHPBarDialog::FUN_140e6c640(int nBuffId)
{
    if (m_30 == 0)
        return;
    if (m_effects == 0)
        return;
    m_effects->FUN_1409b5b60(nBuffId);
}

// @0x140e6c6c0
void UINpcDuelHPBarDialog::vfunc_43()
{
    UIDialog::vfunc_43();
    MS2Ptr<ASGameEntity> pEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (pEntity.get() != 0) {
        pEntity->vfunc_2(1, 0, 0x32);
        pEntity->vfunc_3(1);
    }
}

// @0x140e6c7a0
// MS2-FUNCTIONAL: stack slot order of the minute/second locals
void UINpcDuelHPBarDialog::FUN_140e6c7a0()
{
    unsigned int nMinutes = 0;
    unsigned int nSeconds = 0;
    unsigned int nNow = FUN_140869420();
    if (nNow < m_nEndTick) {
        nSeconds = (m_nEndTick - nNow) / 1000;
        nMinutes = nSeconds / 60;
        nSeconds = nSeconds % 60;
    }
    ASDisplayObject* pRoot = dynamic_cast<ASDisplayObject*>((AScript*)m_30);
    if (pRoot != 0) {
        CString strTime;
        strTime.Format("%02d%02d", nMinutes, nSeconds);
        pRoot->Invoke("setTime", strTime);
    }
}

// @0x140e6c900
void UINpcDuelHPBarDialog::FUN_140e6c900()
{
    if (m_30 == 0)
        return;
    Unk_NdActor* pPc = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPc == 0)
        return;
    __int64 nHp = pPc->FUN_141670a00(4);
    __int64 nMaxHp = pPc->FUN_141670a30(4);
    ((Unk_NdScript*)m_30.operator->())->FUN_140cb6990("setHpBarLeft", nHp, nMaxHp);
}

// @0x140e6c9c0
void UINpcDuelHPBarDialog::FUN_140e6c9c0()
{
    if (m_30 == 0)
        return;
    if (m_nBarCount == 0)
        return;
    Unk_NdActor* pNpc = FUN_141bd1320(FUN_1403ed2d0(), m_nObjectId);
    if (pNpc == 0)
        return;
    const __int64& nHp = pNpc->FUN_141670a00(4);
    const __int64& nMaxHp = pNpc->FUN_141670a30(4);
    if (nMaxHp == 0)
        return;
    __int64 nPerBar = nMaxHp / m_nBarCount;
    if (nPerBar == 0)
        nPerBar = 1;
    int nBar = (int)(nHp / nPerBar + 1);
    if (nBar < 1)
        nBar = 1;
    if (nBar > m_nBarCount)
        nBar = m_nBarCount;
    int nShown;
    __int64 nRest = nHp - (nBar - 1) * nPerBar;
    if (nRest < 0)
        nRest = 0;
    if (nRest > nPerBar)
        nRest = nPerBar;
    ((Unk_NdScript*)m_30.operator->())->FUN_140e6cfe0("setHpBarRight", nRest, nPerBar, nBar);
    nShown = nBar;
    if (nShown <= 1) {
        FUN_140cff840(FUN_1422dbc00(), "m_rightBarCount", 0);
    } else {
        CStringW strCount = FUN_14062b4f0(L"s_npc_duelhpbar_dialog_barCount", &nShown);
        FUN_140cff840(FUN_1422dbc00(), "m_rightBarCount", 1);
        FUN_140cfee80(FUN_1422dbc00(), "m_rightBarCount", strCount);
    }
}

// @0x140e6cd80
MS2Ptr<ASEffectManager> FUN_140e6cd80(int nMovieId, CString strClass, __int64 a1, int a2)
{
    Unk_NdMovie* pMovie = FUN_1422bb8b0(nMovieId);
    if (pMovie == 0)
        return MS2Ptr<ASEffectManager>(0);
    Scaleform::GFx::Value obj;
    pMovie->FUN_14256e8e0(obj, strClass, a1, a2);
    if (FUN_1409b0390(&obj) != 0)
        return MS2Ptr<ASEffectManager>(0);
    MS2Ptr<ASEffectManager> pEffects(new ASEffectManager(obj, nMovieId));
    return pEffects;
}

// @0x140e6cf40
// MS2-FUNCTIONAL: temporaries sit 8 bytes lower than the exe's stack layout
CString FUN_140e6cf40(const char* szFmt, const int& nValue)
{
    Unk_FmtPack pack;
    Unk_FmtArg arg;
    return FUN_1402bf9a0(szFmt, *FUN_140163e50(&pack, FUN_140e116e0(nValue), *FUN_140e10ac0(&arg, nValue)));
}

// @0x140e6cfe0 (the "setHpBarRight" argument list)
Scaleform::GFx::Value Unk_NdScript::FUN_140e6cfe0(const char* szMethod, __int64 a1, __int64 a2, int a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bcdd0(args.FUN_1409b1f70(0), a1);
    FUN_1422bcdd0(args.FUN_1409b1f70(1), a2);
    FUN_1422bccb0(args.FUN_1409b1f70(2), a3);
    return FUN_1422bb8f0(szMethod, args);
}

MS2_REPLACE_METHOD(0x140E6B8A0, UINpcDuelHPBarDialog, GetTypeName, 61, 0x01524E8D);
MS2_REPLACE_METHOD(0x140E6B8F0, UINpcDuelHPBarDialog, vfunc_67, 90, 0x54B3777A);
MS2_REPLACE_METHOD(0x140E6B950, UINpcDuelHPBarDialog, vfunc_72, 123, 0x2C3B24B1);
MS2_REPLACE_METHOD(0x140E6B9E0, UINpcDuelHPBarDialog, OnLoadComplete, 387, 0x3FEED2D8);
MS2_REPLACE_METHOD(0x140E6BB70, UINpcDuelHPBarDialog, FUN_140e6bb70, 145, 0x9B9A0FFE);
MS2_REPLACE_METHOD(0x140E6C440, UINpcDuelHPBarDialog, FUN_140e6c440, 247, 0xDB003D3C);
MS2_REPLACE_METHOD(0x140E6C540, UINpcDuelHPBarDialog, FUN_140e6c540, 247, 0x169BBFC0);
MS2_REPLACE_METHOD(0x140E6C640, UINpcDuelHPBarDialog, FUN_140e6c640, 107, 0x38164386);
MS2_REPLACE_METHOD(0x140E6C6C0, UINpcDuelHPBarDialog, vfunc_43, 203, 0x0737E564);
MS2_REPLACE_METHOD(0x140E6C900, UINpcDuelHPBarDialog, FUN_140e6c900, 181, 0x15054B8C);
MS2_REPLACE_METHOD(0x140E6C9C0, UINpcDuelHPBarDialog, FUN_140e6c9c0, 951, 0xE11ED690);
MS2_REPLACE(0x140E6CD80, FUN_140e6cd80, 436, 0x15B246EF);
