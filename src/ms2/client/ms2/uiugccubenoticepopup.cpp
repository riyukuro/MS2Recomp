// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIUGCCubeNoticePopup: see uiugccubenoticepopup.h.
// MS2-UNIT: unit_140fb49b0
// MS2-RANGE: 0x140fb49b0-0x140fb53d0 .text$mn
// MS2-RANGE: 0x1400e21b0-0x1400e2230 .text$di
// MS2-PIN: ??_GUIUGCCubeNoticePopup@@UEAAPEAXI@Z 0x140fb5260
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiugccubenoticepopup.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "uiugccubenoticepopup.h"

#include "worldservice.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- header statics (.text$di): a shared header's condition keys and a null pointer holder ----
// @0x1400e21b0
static CString s_skill("skill");
// @0x1400e21e0
static CString s_stun("stun");
class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };
// @0x1400e2210
static Unk_1401cd100 s_pointer(NULL);

// ---- unit-local placeholders (unrecovered helpers; promote to src/ms2/placeholder/ when shared) ----

// This assignment COMDAT belongs to the earlier unit at 0x140ba7780.
template <> template <>
MS2Ptr<AScript>& MS2Ptr<AScript>::operator=<ASGameEntity>(const MS2Ptr<ASGameEntity>&);

MS2Ptr<ASGameEntity> FUN_140ba77e0(int n, const Scaleform::GFx::Value& v);    // new ASGameEntity(v, n)
bool FUN_140a467d0(const MS2Ptr<AScript>* p);                        // has the AS object been released
WorldService* FUN_1403ed2d0();

extern const Vector3 DAT_143b01a60;                          // the zero point

// The camera (FUN_1409478c0): projects a world point to the screen.
class Unk_UnpCamera { public: bool FUN_140af0700(const Vector3* pWorld, Vector3* pScreen); };
Unk_UnpCamera* FUN_1409478c0();

// The ui scale service: scale of a layer.
class Unk_UnpScale;
Unk_UnpScale* FUN_14025e7a0();
float FUN_1422afec0(Unk_UnpScale* pScale, int nLayer);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x140fb49b0
UIUGCCubeNoticePopup::UIUGCCubeNoticePopup()
    : m_ptWorld(DAT_143b01a60), m_bShown(0), m_bPending(0), m_bVisible(0)
{
    m_58 = 0;
    FUN_1422dbf00(7, 0, 0);
}

// @0x140fb4aa0
UIUGCCubeNoticePopup::~UIUGCCubeNoticePopup()
{
}

// @0x140fb4b10
CString UIUGCCubeNoticePopup::GetTypeName()
{
    return "UGCCubeNoticePopup";
}

// @0x140fb4b60
void UIUGCCubeNoticePopup::OnLoadComplete()
{
    UIObject::OnLoadComplete();
    FUN_140fb5080(1);
}

// @0x140fb4b90
int UIUGCCubeNoticePopup::IsShown()
{
    return m_bShown;
}

// @0x140fb4bb0
void UIUGCCubeNoticePopup::FUN_140fb4bb0()
{
    m_bPending = 1;
    m_bShown = 1;
}

// @0x140fb4be0
void UIUGCCubeNoticePopup::FUN_140fb4be0()
{
    FUN_140b632f0()->FUN_1422d0dc0(MS2Ptr<UISwfEntity>(this));
    m_bPending = 0;
    m_bShown = 0;
}

// @0x140fb4c50
void UIUGCCubeNoticePopup::SetPtWorld(Vector3 ptWorld)
{
    m_ptWorld = ptWorld;
}

// @0x140fb4c80
void UIUGCCubeNoticePopup::SetIdEntity(const egf::EntityID& id)
{
    m_idEntity = id;
}

// @0x140fb4cc0
void UIUGCCubeNoticePopup::FUN_140fb4cc0(const CStringW& strTitle, const CStringW& strText)
{
    m_strTitle = strTitle;
    m_strText = strText;
}

// MS2-FUNCTIONAL: EH state / temporary layout differs
// @0x140fb4d10
void UIUGCCubeNoticePopup::vfunc_52()
{
    if (!FUN_140a467d0(&m_30))
    {
        MS2Ptr<ASMovieClip> spClip(dynamic_cast<ASMovieClip*>((AScript*)m_30));
        if (spClip.get() != 0)
        {
            vfunc_8(0);
            m_bPending = 0;
        }
    }
}

// MS2-FUNCTIONAL: branch layout and EH state differ
// @0x140fb4dc0
void UIUGCCubeNoticePopup::vfunc_15()
{
    UIObject::vfunc_15();
    if (!FUN_140a467d0(&m_30))
    {
        if (FUN_1403ed2d0()->FUN_141bd0cc0() != 0)
        {
            if (m_bPending != 0)
                vfunc_52();
            if (IsShown() == 0)
                vfunc_8(0);
            else
                FUN_140fb4eb0();
        }
    }
}

// MS2-FUNCTIONAL: the exe returns bool from the int slot (source spelling unknown)
// @0x140fb4e60
int UIUGCCubeNoticePopup::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    return UIObject::vfunc_28(szMethod, pArgs, nArgs) != 0;
}

// MS2-FUNCTIONAL: EH state / float temporaries differ
// @0x140fb4eb0
void UIUGCCubeNoticePopup::FUN_140fb4eb0()
{
    if (FUN_1403ed2d0()->FUN_141bd0cc0() != 0 && m_bVisible != 0)
    {
        Vector3 ptScreen;
        if (!FUN_1409478c0()->FUN_140af0700(&m_ptWorld, &ptScreen))
            vfunc_8(0);
        else
        {
            MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
            if (spEntity.get() != 0)
            {
                vfunc_8(1);
                ptScreen.FUN_140ad0c10(FUN_1422afec0(FUN_14025e7a0(), m_28));
                int nHeight = spEntity->FUN_1422c13b0();
                int nWidth = spEntity->FUN_1422c1340();
                spEntity->FUN_1422c00f0(ptScreen.x - (float)(nWidth / 2), (ptScreen.y - (float)nHeight) - 15.0f);
            }
        }
    }
}

// MS2-FUNCTIONAL: EH state / string temporaries differ
// @0x140fb5080
void UIUGCCubeNoticePopup::FUN_140fb5080(int bShow)
{
    if (!FUN_140a467d0(&m_30) && m_bVisible != bShow)
    {
        m_bVisible = bShow;
        if (bShow != 0)
            m_30->Invoke("setText", m_strTitle, m_strText);
        m_30->Invoke("setShow", bShow);
    }
}

// @0x140fb51f0
void UIUGCCubeNoticePopup::vfunc_41(const Scaleform::GFx::Value& root)
{
    m_30 = FUN_140ba77e0(m_28, root);
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142caa860-0x142caa8a0 .text$yd
