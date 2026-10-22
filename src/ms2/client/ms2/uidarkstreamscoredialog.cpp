// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIDarkStreamScoreDialog and its base UIScoreDialog: see
// uidarkstreamscoredialog.h.
// MS2-UNIT: ?\uidarkstreamscoredialog.cpp
// MS2-RANGE: 0x140f35340-0x140f359b0 .text$mn
// MS2-PIN: ??_GUIDarkStreamScoreDialog@@UEAAPEAXI@Z 0x140f35800
// MS2-PIN: ??_GUIScoreDialog@@UEAAPEAXI@Z 0x140f35840
// MS2-PIN: ??1UIScoreDialog@@UEAA@XZ 0x140f357e0
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uidarkstreamscoredialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uidarkstreamscoredialog.h"

#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

class ASGameEntity : public ASDisplayObject { public: virtual void vfunc_2(int, int, int); };

bool FUN_140a467d0(const MS2Ptr<AScript>*);                     // has the AS object been released
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
void FUN_1422bcce0(Scaleform::GFx::Value* pValue, bool b);

// @0x140f35340
UIDarkStreamScoreDialog::UIDarkStreamScoreDialog()
{
    m_nScore = 0;
    m_nOffsetY = 0;
    m_nAlign = 1;
    m_80 = 0;
    FUN_141924170(1);
    FUN_141925e70(1, 1);
}

// @0x140f353f0
UIDarkStreamScoreDialog::~UIDarkStreamScoreDialog()
{
}

// @0x140f35430
CString UIDarkStreamScoreDialog::GetTypeName()
{
    return "DarkStreamScoreDialog";
}
MS2_REPLACE_METHOD(0x140F35430, UIDarkStreamScoreDialog, GetTypeName, 61, 0x8F0A72B3);

// @0x140f35480
void UIDarkStreamScoreDialog::vfunc_43()
{
    UIDialog::vfunc_43();
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (spEntity.get() != 0)
        spEntity->vfunc_2(m_nAlign, 0, m_nOffsetY + 0x82);
}
MS2_REPLACE_METHOD(0x140F35480, UIDarkStreamScoreDialog, vfunc_43, 196, 0xB71DF70F);

// @0x140f35550
void UIDarkStreamScoreDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    vfunc_84(m_nScore);
}
MS2_REPLACE_METHOD(0x140F35550, UIDarkStreamScoreDialog, OnLoadComplete, 54, 0x69063E2E);

// @0x140f35590
void UIDarkStreamScoreDialog::vfunc_84(int nScore)
{
    m_nScore = nScore;
    vfunc_85();
}
MS2_REPLACE_METHOD(0x140F35590, UIDarkStreamScoreDialog, vfunc_84, 52, 0x314E7360);

// @0x140f355d0
void UIDarkStreamScoreDialog::vfunc_85()
{
    if (FUN_140a467d0(&m_30))
        return;
    m_30.operator->()->Invoke("setScore", m_nScore, m_nScore < 0);
}
MS2_REPLACE_METHOD(0x140F355D0, UIDarkStreamScoreDialog, vfunc_85, 134, 0xA0CA5A42);

// @0x140f35660
void UIDarkStreamScoreDialog::FUN_140f35660(int nOffsetY)
{
    m_nOffsetY = nOffsetY;
    vfunc_43();
}
MS2_REPLACE_METHOD(0x140F35660, UIDarkStreamScoreDialog, FUN_140f35660, 52, 0x38C50FB3);

// @0x140f356a0
void UIDarkStreamScoreDialog::FUN_140f356a0(int nAlign)
{
    m_nAlign = nAlign;
    vfunc_43();
}
MS2_REPLACE_METHOD(0x140F356A0, UIDarkStreamScoreDialog, FUN_140f356a0, 52, 0xAD6E7DF7);

// @0x140f356e0 Invoke(name, int, bool)
Scaleform::GFx::Value AScript::Invoke(const char* szMethod, int a1, bool a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bccb0(args.FUN_1409b1f70(0), a1);
    FUN_1422bcce0(args.FUN_1409b1f70(1), a2);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140f357a0
UIScoreDialog::UIScoreDialog()
{
}

// @0x140f35880
int UIDarkStreamScoreDialog::vfunc_48()
{
    return 0x4ee4;
}
MS2_REPLACE_METHOD(0x140F35880, UIDarkStreamScoreDialog, vfunc_48, 11, 0x891EE895);

// @0x140f35890
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
