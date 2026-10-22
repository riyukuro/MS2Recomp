// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIEventIntroduce: see uieventintroduce.h.
// MS2-UNIT: ?\uieventintroduce.cpp
// MS2-RANGE: 0x140f40ce0-0x140f41250 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uieventintroduce.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "uieventintroduce.h"

#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/ascript.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local placeholders (unrecovered helpers; promote to src/ms2/placeholder/ when shared) ----

int FUN_1412755a0();                    // the micro-game driver's mode query (0 = the intro is on screen)

// The movie's root entity: slot 25 is the entity's "validate now" (ASGameEntity declares only slots 0..5).
class Unk_EiEntity : public ASGameEntity
{
public:
    virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17();
    virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24();
    virtual void vfunc_25();
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x140f40ce0
UIEventIntroduce::UIEventIntroduce()
{
    m_2c = 0x1e;
}

// @0x140f40d30
UIEventIntroduce::~UIEventIntroduce()
{
}

// @0x140f40d70
CString UIEventIntroduce::GetTypeName()
{
    return "EventIntroduce";
}

// @0x140f40dc0
void UIEventIntroduce::vfunc_2()
{
    if (FUN_1412755a0() != 0)
    {
    }
    else
    {
        FUN_1422dbf00(0x1e, 0, 0);
    }
}

// @0x140f40e00
void UIEventIntroduce::vfunc_3()
{
    if (FUN_1412755a0() != 0)
    {
    }
    else
    {
        FUN_1422dc080();
    }
}

// @0x140f40e30
void UIEventIntroduce::OnLoadInit()
{
    UIObject::OnLoadInit();
}

// @0x140f40e50
void UIEventIntroduce::vfunc_43()
{
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (spEntity.get())
        static_cast<Unk_EiEntity*>(spEntity.operator->())->vfunc_25();
}

// @0x140f40ef0
void UIEventIntroduce::FUN_140f40ef0(int n)
{
    if (m_30.get())
        m_30.operator->()->Invoke("onWin", n);
}

// @0x140f40f60
void UIEventIntroduce::FUN_140f40f60(int n)
{
    if (m_30.get())
        m_30.operator->()->Invoke("onLose", n);
}

// @0x140f40fd0
void UIEventIntroduce::FUN_140f40fd0(int n)
{
    if (m_30.get())
        m_30.operator->()->Invoke("onDraw", n);
}

// @0x140f41040
void UIEventIntroduce::FUN_140f41040(int n)
{
    if (m_30.get())
        m_30.operator->()->Invoke("onPerfect", n);
}

// @0x140f410b0
void UIEventIntroduce::FUN_140f410b0(int n)
{
    if (m_30.get())
        m_30.operator->()->Invoke("onFight", n);
}

// @0x140f41120
void UIEventIntroduce::FUN_140f41120(int n)
{
    if (m_30.get())
        m_30.operator->()->Invoke("onFinalRound", n);
}

// @0x140f41190
void UIEventIntroduce::FUN_140f41190(int a1, int a2)
{
    if (m_30.get())
        m_30.operator->()->FUN_1409ba0d0("onRound", a1, a2);
}
