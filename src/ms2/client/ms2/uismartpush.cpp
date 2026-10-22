// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UISmartPush: see uismartpush.h.
// MS2-UNIT: ?\uismartpush.cpp
// MS2-RANGE: 0x140fa3b10-0x140fa4180 .text$mn
// MS2-PIN: ??_GUISmartPush@@UEAAPEAXI@Z 0x140fa4130
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uismartpush.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uismartpush.h"

#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// The pushed record (CSmartPush, RTTI; 0x38 bytes): the slots the HUD asks.
class CSmartPush
{
public:
    virtual ~CSmartPush();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual CStringW vfunc_7();                                 // name
    virtual CStringW vfunc_8();                                 // active movie
    virtual void s9();
    virtual CStringW vfunc_10();                                // event popup
    virtual bool vfunc_11();                                    // is a toggle
    virtual bool vfunc_12();                                    // uses the small active icon

    char m_pad_08[0x10];
    int m_nId;                                                  // +0x18
    int m_n1c;
    int m_nState;                                               // +0x20 2 = active
    int m_pad_24;
    void* m_pData;                                              // +0x28 handle of the data
};

class Unk_SpNet
{
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5();
    virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17();
    virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29();
    virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35();
    virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39(); virtual void s40(); virtual void s41();
    virtual void s42();
    virtual void vfunc_43(int nEvent, int a2, int nDelay);
};
class Unk_SpMgr
{
public:
    void FUN_140dd8620(int nId);                                // a smart push was clicked
    void FUN_140dd8730();                                       // the strip was hidden
};

Unk_SpNet* FUN_140d86260();

bool FUN_140a467d0(const MS2Ptr<AScript>*);                     // has the AS object been released
int FUN_1418dd0d0();
Unk_SpMgr* FUN_140cea070();
void* FUN_140812670(void* pHandle);

// @0x140fa3b10
UISmartPush::UISmartPush()
{
    m_2c = 0xd;
}

// @0x140fa3b60
UISmartPush::~UISmartPush()
{
}

// @0x140fa3ba0
CString UISmartPush::GetTypeName()
{
    return "SmartPush";
}
MS2_REPLACE_METHOD(0x140FA3BA0, UISmartPush, GetTypeName, 61, 0x3DDD7BA2);

// @0x140fa3bf0
void UISmartPush::OnLoadComplete()
{
    UIObject::OnLoadComplete();
    FUN_140d86260()->vfunc_43(0xe, 0, 1000);
}
MS2_REPLACE_METHOD(0x140FA3BF0, UISmartPush, OnLoadComplete, 67, 0x97CD5915);

// @0x140fa3c40
void UISmartPush::vfunc_43()
{
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (spEntity.get() != 0)
        spEntity->vfunc_2(7, 0x1b4, (FUN_1418dd0d0() + 0x5a) * -1);
}

// @0x140fa3d00
int UISmartPush::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISwfEntity::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("onSmartPush", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            int nId = data.FUN_1422b8a10();
            FUN_140cea070()->FUN_140dd8620(nId);
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140FA3D00, UISmartPush, vfunc_28, 201, 0xFD7815C0);

// @0x140fa3dd0
void UISmartPush::vfunc_2()
{
    UIHeadUpDisplay::vfunc_2();
}

// @0x140fa3df0
void UISmartPush::vfunc_3()
{
    UIHeadUpDisplay::vfunc_3();
    FUN_140cea070()->FUN_140dd8730();
}
MS2_REPLACE_METHOD(0x140FA3DF0, UISmartPush, vfunc_3, 37, 0xAEF58F5C);

// @0x140fa3e20
int UISmartPush::FUN_140fa3e20(CSmartPush* pPush)
{
    if (FUN_140a467d0(&m_30) != 0)
    {
        if (FUN_141986d30() == 0)
            vfunc_2();
        return 0;
    }
    ASObj obj(2);
    obj.FUN_1407cb9c0("id", pPush->m_nId);
    obj.FUN_1407cbb20("text", pPush->vfunc_7());
    obj.FUN_1407cbb20("icon", *(CStringW*)((char*)FUN_140812670(&pPush->m_pData) + 0x60));
    obj.FUN_1407cbbe0("isToggle", pPush->vfunc_11());
    obj.FUN_1407cbbe0("active", pPush->m_nState == 2);
    obj.FUN_1407cbbe0("isSmallActiveIcon", pPush->vfunc_12());
    obj.FUN_1407cbb20("activeMovie", pPush->vfunc_8());
    obj.FUN_1407cbb20("eventPopup", pPush->vfunc_10());
    m_30->Invoke("addPush", obj);
    return 1;
}
MS2_REPLACE_METHOD(0x140FA3E20, UISmartPush, FUN_140fa3e20, 652, 0x58779CBF);

// @0x140fa40c0
int UISmartPush::FUN_140fa40c0(int nId)
{
    if (FUN_140a467d0(&m_30))
        return 0;
    m_30->Invoke("removePush", nId);
    return 1;
}
MS2_REPLACE_METHOD(0x140FA40C0, UISmartPush, FUN_140fa40c0, 103, 0x5D5C0778);

// @0x140fa4170
int UISmartPush::vfunc_48()
{
    return 0x4ef7;
}
