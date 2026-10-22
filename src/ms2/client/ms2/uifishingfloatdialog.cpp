// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIFishingFloatDialog: see uifishingfloatdialog.h.
// MS2-UNIT: ?\uifishingfloatdialog.cpp
// MS2-RANGE: 0x1400df560-0x1400df5c0 .text$di
// MS2-RANGE: 0x140f43df0-0x140f447d0 .text$mn
// MS2-PIN: ??1UIFishingFloatDialog@@UEAA@XZ 0x140f44760
// MS2-PIN: ??_GUIFishingFloatDialog@@UEAAPEAXI@Z 0x140f44780
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uifishingfloatdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uifishingfloatdialog.h"

#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/gameoptiongamepad.h"
#include "ms2/client/ms2/ms2inputservice.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// The name tables the sounds and system sounds are taken from.
static CString s_143aca738("System_Fishing_ActionFail");
static CString s_143aca6e8("System_Fishing_ActionPopup");

// The AS movie of the float: three more Invoke instances (an int argument each) the exe has per translation unit.
class ASArgList;
class Unk_FishAS
{
public:
    Scaleform::GFx::Value FUN_140f446c0(const char* szMethod, int a1);      // 0x140f446c0 Invoke(name, int)
    Scaleform::GFx::Value FUN_140caf230(const char* szMethod, int a1);      // 0x140caf230 Invoke(name, int)
    Scaleform::GFx::Value FUN_1422bb330(const char* szMethod);              // Invoke(name)
};
bool FUN_1409c1720(const Scaleform::GFx::Value& v);
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
bool FUN_140a467d0(const MS2Ptr<AScript>*);                     // has the AS object been released

class Unk_StringTable { public: CStringW FUN_14142d760(int nId, int n); };
Unk_StringTable* FUN_1409331f0();
struct Unk_GpSettings;
Unk_GpSettings* FUN_1409a8b10();
Unk_GpState* FUN_140a58500(Unk_GpSettings* p);
class CFeatureManager { public: bool FUN_14036d570(int n); };
CFeatureManager* FUN_140166410();
CInputKeyHandler* FUN_14025e7c0();

// The sound-state objects behind the three loops.
class Unk_SoundParam
{
public:
    Unk_SoundParam();                                               // 0x140a52ef0
    ~Unk_SoundParam();                                              // 0x1405a89e0
    void FUN_140a53190(int n);
    CString m_name;
    int m_08;
    int m_0c;
    __int64 m_10, m_18, m_20, m_28, m_30, m_38, m_40, m_48, m_50, m_58, m_60, m_68;
};
class Unk_SoundOwner;
class Unk_SoundMgr
{
public:
    int FUN_1411a49c0(Unk_SoundParam& p);                           // 0x1411a49c0 play
    void FUN_1411a6060(int nHandle);                                // 0x1411a6060 stop
};
void FUN_141276180(const CString&, const CString&);
MS2InputService* FUN_140a58540();
Unk_SoundMgr* FUN_1403ed280();
Unk_SoundOwner* FUN_1403ed2d0();
Unk_SoundMgr* FUN_141bd0cc0(Unk_SoundOwner*);
int FUN_14123c580(Unk_SoundMgr*);

// The "fish info" message the size / rank are taken from, and the fish table it is resolved against.
class Unk_FishPacket : public CPtred
{
public:
    int m_18;
    int m_1c;                           // +0x1c the fish id
    int m_20;                           // +0x20 rank key
    int m_24;
    int m_28;                           // +0x28 fish size
};
class Unk_FishRankTable { public: int FUN_1403b1520(int nKey); };
class Unk_FishRef
{
public:
    ~Unk_FishRef();                                                 // 0x1403b3920
    void* m_00; void* m_08; void* m_10;
    void* FUN_140cdf9b0();                                          // 0x140cdf9b0 the entry, null if the id is unknown
    Unk_FishRankTable* FUN_1403b3c80();                             // 0x1403b3c80 its rank table
};
class Unk_FishTable { public: Unk_FishRef FUN_1403b2d30(int nId); };
Unk_FishTable* FUN_1403b4740();
class Unk_Misc { public: void FUN_140cdaaa0(); };
Unk_Misc* FUN_140953f20();

// @0x1400df560, @0x1400df590 (the two static CStrings above)

// @0x140f43df0
UIFishingFloatDialog::UIFishingFloatDialog()
{
    m_2c = 0x1a;
    m_80 = 0;
    FUN_141924170(1);
    FUN_141925e70(1, 1);
    memset(m_180, 0, sizeof(m_180));
}

// @0x140f43ea0
CString UIFishingFloatDialog::GetTypeName()
{
    return "FishingFloatDialog";
}
MS2_REPLACE_METHOD(0x140F43EA0, UIFishingFloatDialog, GetTypeName, 61, 0xDDB30DA7);

// @0x140f43ef0
void UIFishingFloatDialog::vfunc_15()
{
}

// @0x140f43f00
void UIFishingFloatDialog::vfunc_43()
{
    UIDialog::vfunc_43();
}

// @0x140f43f20
void UIFishingFloatDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (m_30.get())
    {
        int nKeyType = FUN_140a58500(FUN_1409a8b10())->m_bUse ? 2 : 0;
        m_30.operator->()->Invoke("setKeyText", FUN_1409331f0()->FUN_14142d760(0x493e2, nKeyType));
        reinterpret_cast<Unk_FishAS*>(m_30.operator->())->FUN_140f446c0("setFishSize", m_178);
        reinterpret_cast<Unk_FishAS*>(m_30.operator->())->FUN_140caf230("setFishRank", m_17c);
    }
    FUN_140f44520(0);
    FUN_141276180(s_143aca6e8, "");
    if (FUN_140166410()->FUN_14036d570(0xc3))
    {
        if (FUN_140a58500(FUN_1409a8b10())->m_bVibration)
            FUN_140a58540()->FUN_140d8b3e0(1.7976931348623157e+308);
    }
}

// @0x140f44120
void UIFishingFloatDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    FUN_140f44650(0);
    FUN_140f44650(1);
    FUN_140f44650(2);
    FUN_140a58540()->FUN_140d8b560(false);
}

// @0x140f44180
int UIFishingFloatDialog::vfunc_13()
{
    if (UIDialog::vfunc_13())
        return 1;
    if (FUN_140a467d0(&m_30))
        return 0;
    if (FUN_14025e7c0()->FUN_14116dd30(0x493e2, 0, 0))
    {
        reinterpret_cast<Unk_FishAS*>(m_30.operator->())->FUN_1422bb330("onFishUp");
        return 1;
    }
    else if (FUN_14025e7c0()->FUN_14116ddb0(0x493e2, 0, 0))
    {
        reinterpret_cast<Unk_FishAS*>(m_30.operator->())->FUN_1422bb330("onFishUpRelease");
        return 1;
    }
    return 0;
}

// @0x140f44280
int UIFishingFloatDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp(szMethod, "onFloatTouchDown") == 0)
    {
        FUN_140953f20()->FUN_140cdaaa0();
        vfunc_67();
        FUN_141276180(s_143aca738, "");
        return 1;
    }
    else if (_stricmp(szMethod, "onFloatOut") == 0)
    {
        if (m_68 == 0)
        {
            FUN_140f44650(2);
            FUN_140f44520(1);
        }
    }
    else if (_stricmp(szMethod, "onFloatIn") == 0)
    {
        if (m_68 == 0)
        {
            FUN_140f44650(1);
            FUN_140f44520(2);
        }
    }
    return 0;
}

// @0x140f443d0
void UIFishingFloatDialog::FUN_140f443d0(MS2Ptr<Unk_FishPacket> spInfo)
{
    Unk_FishPacket* pInfo = spInfo.operator->();
    Unk_FishRef ref = FUN_1403b4740()->FUN_1403b2d30(pInfo->m_1c);
    if (ref.FUN_140cdf9b0())
    {
        m_17c = spInfo.operator->()->m_28;
        Unk_FishPacket* pInfo2 = spInfo.operator->();
        m_178 = ref.FUN_1403b3c80()->FUN_1403b1520(pInfo2->m_20);
    }
}

// @0x140f44490
int UIFishingFloatDialog::FUN_140f44490()
{
    if (FUN_140a467d0(&m_30))
        return 0;
    return FUN_1409c1720(reinterpret_cast<Unk_FishAS*>(m_30.operator->())->FUN_1422bb330("getResult"));
}

// @0x140f44520
void UIFishingFloatDialog::FUN_140f44520(int nSound)
{
    if (m_180[nSound])
        FUN_140f44650(nSound);
    Unk_SoundMgr* pOwner = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pOwner == 0)
        return;
    Unk_SoundParam param;
    if (nSound == 0)
        param.m_name = "ETC/Fishing/Sound_Fish_Action.xml";
    else if (nSound == 1)
        param.m_name = "ETC/Fishing/Sound_Fish_Action_Red.xml";
    else if (nSound == 2)
        param.m_name = "ETC/Fishing/Sound_Fish_Action_Blue.xml";
    param.m_08 = 1;
    param.FUN_140a53190(FUN_14123c580(pOwner));
    m_180[nSound] = FUN_1403ed280()->FUN_1411a49c0(param);
}

// @0x140f44650
void UIFishingFloatDialog::FUN_140f44650(int nSound)
{
    if (m_180[nSound])
    {
        FUN_1403ed280()->FUN_1411a6060(m_180[nSound]);
        m_180[nSound] = 0;
    }
}

// @0x140f446c0
Scaleform::GFx::Value Unk_FishAS::FUN_140f446c0(const char* szMethod, int a1)
{
    ASArgList args;
    args.FUN_1409b2800(1);
    FUN_1422bccb0(args.FUN_1409b1f70(0), a1);
    return reinterpret_cast<AScript*>(this)->FUN_1422bb8f0(szMethod, args);
}

// @0x140f447c0
int UIFishingFloatDialog::vfunc_48()
{
    return 0x4ee7;
}
MS2_REPLACE_METHOD(0x140F447C0, UIFishingFloatDialog, vfunc_48, 11, 0xA233B848);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca96a0-0x142ca96e0 .text$yd
