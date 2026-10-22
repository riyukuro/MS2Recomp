// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIPortalEmoticon: see uiportalemoticon.h.
// MS2-UNIT: unit_140f9b9c0
// MS2-RANGE: 0x140f9b9c0-0x140f9c1e0 .text$mn
// MS2-PIN: ??_GUIPortalEmoticon@@UEAAPEAXI@Z 0x140f9c130
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiportalemoticon.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "uiportalemoticon.h"

#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local placeholders (unrecovered helpers; promote to src/ms2/placeholder/ when shared) ----

// This assignment COMDAT belongs to the earlier unit at 0x140ba7780.
template <> template <>
MS2Ptr<AScript>& MS2Ptr<AScript>::operator=<ASGameEntity>(const MS2Ptr<ASGameEntity>&);

MS2Ptr<ASGameEntity> FUN_140ba77e0(int n, const Scaleform::GFx::Value& v);    // new ASGameEntity(v, n)
char FUN_140a467d0(const MS2Ptr<AScript>* p);                        // has the AS object been released

// The camera (FUN_1409478c0): projects a world point to the screen.
class Unk_PeCamera { public: bool FUN_140af0700(const Unk_StreamPoint* pWorld, Unk_StreamPoint* pScreen); };
Unk_PeCamera* FUN_1409478c0();

// The ui scale service: scale of a layer.
class Unk_PeScale;
Unk_PeScale* FUN_14025e7a0();
float FUN_1422afec0(Unk_PeScale* pScale, int nLayer);

// ASGameEntity's slots beyond ASDisplayObject's 0-5 (only slot 24, +0xc0, is used here).
class Unk_PeEntity : public ASGameEntity
{
public:
    virtual void Unk_Slot6(); virtual void Unk_Slot7(); virtual void Unk_Slot8(); virtual void Unk_Slot9();
    virtual void Unk_Slot10(); virtual void Unk_Slot11(); virtual void Unk_Slot12(); virtual void Unk_Slot13();
    virtual void Unk_Slot14(); virtual void Unk_Slot15(); virtual void Unk_Slot16(); virtual void Unk_Slot17();
    virtual void Unk_Slot18(); virtual void Unk_Slot19(); virtual void Unk_Slot20(); virtual void Unk_Slot21();
    virtual void Unk_Slot22(); virtual void Unk_Slot23();
    virtual void vfunc_24(bool b);
};

extern const Unk_StreamPoint DAT_143b01a60;                          // the zero point

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x140f9b9c0
UIPortalEmoticon::UIPortalEmoticon()
    : m_ptWorld(DAT_143b01a60), m_bShown(0), m_bPending(0)
{
    m_28 = 0;
    m_2c = 4;
    m_58 = 0;
    FUN_1422dbf00(m_2c, m_44, 0);
}

// @0x140f9baa0
UIPortalEmoticon::~UIPortalEmoticon()
{
}

// @0x140f9bb00
CString UIPortalEmoticon::GetTypeName()
{
    return "PortalEmoticon";
}

// @0x140f9bb50
int UIPortalEmoticon::IsShown()
{
    return m_bShown;
}

// @0x140f9bb70
void UIPortalEmoticon::FUN_140f9bb70()
{
    m_bPending = 1;
    m_bShown = 1;
}

// @0x140f9bba0
void UIPortalEmoticon::FUN_140f9bba0()
{
    m_bPending = 0;
    m_bShown = 0;
}

// @0x140f9bbd0
void UIPortalEmoticon::FUN_140f9bbd0()
{
    FUN_140b632f0()->FUN_1422d0dc0(MS2Ptr<UISwfEntity>(this));
    m_bPending = 0;
    m_bShown = 0;
}

// @0x140f9bc40
void UIPortalEmoticon::FUN_140f9bc40(Unk_StreamPoint ptWorld)
{
    m_ptWorld = ptWorld;
    m_ptWorld.FUN_140a4e560(Unk_StreamPoint(0.0f, 0.0f, 150.0f));
}

// @0x140f9bca0
void UIPortalEmoticon::SetName(const CStringW& strName)
{
    m_strName = strName;
}

// @0x140f9bce0
void UIPortalEmoticon::vfunc_2()
{
    UIObject::vfunc_2();
    FUN_1422dbf00(m_2c, m_44, 0);
    FUN_140f9bb70();
}

// @0x140f9bd30
void UIPortalEmoticon::vfunc_3()
{
    UIObject::vfunc_3();
    FUN_1422dc080();
    FUN_140f9bba0();
}

// MS2-FUNCTIONAL: EH state / temporaries differ
// @0x140f9bd70
void UIPortalEmoticon::vfunc_52()
{
    if (FUN_140a467d0(&m_30) == 0)
    {
        MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
        if (spEntity.get() != 0)
        {
            spEntity->Invoke("open", m_strName);
            spEntity->vfunc_3(1);
            spEntity->FUN_1422bfe00(50.0f);
            vfunc_8(1);
            m_bPending = 0;
        }
    }
}

// MS2-FUNCTIONAL: branch layout and EH state differ
// @0x140f9bee0
void UIPortalEmoticon::vfunc_15()
{
    UIObject::vfunc_15();
    if (FUN_140a467d0(&m_30) == 0)
    {
        if (m_bPending != 0)
            vfunc_52();
        if (IsShown() == 0)
            vfunc_8(0);
        else
            FUN_140f9bf70();
    }
}

// MS2-FUNCTIONAL: EH state / float temporaries differ
// @0x140f9bf70
void UIPortalEmoticon::FUN_140f9bf70()
{
    Unk_StreamPoint ptScreen;
    if (!FUN_1409478c0()->FUN_140af0700(&m_ptWorld, &ptScreen))
        vfunc_8(0);
    else
    {
        MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
        if (spEntity.get() != 0)
        {
            ptScreen.FUN_140ad0c10(FUN_1422afec0(FUN_14025e7a0(), m_28));
            spEntity->FUN_1422c00f0(ptScreen.x, ptScreen.y);
        }
        vfunc_8(1);
    }
}

// @0x140f9c090
void UIPortalEmoticon::vfunc_41(const Scaleform::GFx::Value& root)
{
    m_30 = FUN_140ba77e0(m_28, root);
}

MS2_EMIT_CRT_MEMMOVE_S();
