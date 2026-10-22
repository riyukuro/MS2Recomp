// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See uibuildbtnguide.h.
// MS2-UNIT: ?\uibuildbtnguide.cpp
// MS2-RANGE: 0x1418dcba0-0x1418dcf70 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uibuildbtnguide.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uibuildbtnguide.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit callees ----
class Unk_BuildKeyTable { public: CStringW FUN_14142d760(int nId, int n); };
Unk_BuildKeyTable* FUN_1409331f0();                                     // the key table
bool FUN_140a467d0(const MS2Ptr<AScript>& kScript);                     // has the AS object been released

// the slot list of ASGameEntity is not recovered: only slot 25 is called here
class Unk_BuildBtnEntity : public ASGameEntity
{
public:
    virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23(); virtual void vfunc_24();
    virtual void vfunc_25();
};

// @0x1418dcba0
UIBuildBtnGuide::UIBuildBtnGuide()
{
    m_70 = 0;
    m_58 = 0;
}

// @0x1418dcc00
UIBuildBtnGuide::~UIBuildBtnGuide()
{
}

// @0x1418dcc40
CString UIBuildBtnGuide::GetTypeName()
{
    return "BuildBtnGuideAni";
}

// @0x1418dcc90
void UIBuildBtnGuide::OnLoadComplete()
{
    m_70 = 0;
    UIObject::OnLoadComplete();
}

// @0x1418dccc0
void UIBuildBtnGuide::vfunc_43()
{
    MS2Ptr<ASGameEntity> pEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (pEntity != 0)
        static_cast<Unk_BuildBtnEntity*>(pEntity.operator->())->vfunc_25();
}

// MS2-FUNCTIONAL: the exe returns a bool from this slot (setne only); the int slot signature adds a movzx
// @0x1418dcd60
int UIBuildBtnGuide::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    return UISwfEntity::vfunc_28(szMethod, pArgs, nArgs) != 0;
}

// @0x1418dcdb0
void UIBuildBtnGuide::vfunc_8(int nVisible)
{
    UISwfEntity::vfunc_8(nVisible);
}

// MS2-FUNCTIONAL: temporaries of the two Invoke calls are laid out 4 bytes differently
// @0x1418dcde0
void UIBuildBtnGuide::FUN_1418dcde0(int nGuide)
{
    int nKey;
    if (FUN_141986d30() != 0 && !FUN_140a467d0(m_30) && (nKey = vfunc_9(), m_70 != nGuide))
    {
        m_30->Invoke("setKey", FUN_1409331f0()->FUN_14142d760(0x493ed, nKey));
        m_30->Invoke("showGuide", nGuide);
        m_70 = nGuide;
    }
}
