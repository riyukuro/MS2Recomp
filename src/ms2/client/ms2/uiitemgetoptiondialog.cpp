// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIItemGetOptionDialog: the auto-loot options window.
// MS2-UNIT: unit_1419d95c0
// MS2-RANGE: 0x1419d95c0-0x1419db000 .text$mn
// MS2-PIN: ??0Unk_GoPacket@@QEAA@XZ 0x1401ff780
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiitemgetoptiondialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uiitemgetoptiondialog.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdropdownmenu.h"   // C3: ASDropdownMenu::SetSelectedIndex
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/commonfiles/packet.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/asbutton.h"  // C3: ASButton::FUN_1422ce090
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cpetmanager.h"   // C3: CPetManager::GetInfo (was FUN_140c8b450)

// ---- unit-local views of exe types ----

// The check box child.
class UIItemPetBoxDialog : public UIDialog   // C3: was Unk_GoEntity
{
public:
    MS2Ptr<ASCheckBox> FindCheckBox(const CString& strName);   // 0x140e52670
};

// The auto-loot options as the server gets them: one dword per group and the grade.
struct Unk_GoPacket
{
    Unk_GoPacket();                                             // 0x1401ff780 defaults
    unsigned int m_nMeso;
    unsigned int m_nMerat;
    unsigned int m_nEtc;
    unsigned int m_nToken;
    unsigned int m_nEquip;
    unsigned int m_nConsume;
    unsigned int m_nGemstone;
    unsigned int m_nPet;
    unsigned int m_nOther;
    int m_nGrade;
};
void FUN_1401ff810(unsigned char*, class COutputStream&);   // C3: was FUN_1401ff810

// The account settings (+0xb0.. the auto-loot flags the server sent).
struct Unk_GoAutoCfg
{
    char m_pad_0[0xb0];
    int m_nMeso;                                                // +0xb0
    int m_nMerat;                                               // +0xb4
    int m_nEtc;                                                 // +0xb8
    int m_nToken;                                               // +0xbc
    int m_nEquip;                                               // +0xc0
    int m_nConsume;                                             // +0xc4
    int m_nGemstone;                                            // +0xc8
    int m_nPet;                                                 // +0xcc
    int m_nOther;                                               // +0xd0
    int m_nGrade;                                               // +0xd4
};
struct Unk_GoAutoLoot;   // the auto-loot block of the game options (cgameoption.h)
struct Unk_GsAutoLoot;   // C3: the auto-loot options as gameoptionstruct.cpp declares them
void FUN_141261310(Unk_GsAutoLoot* pDst, const Unk_GsAutoLoot* pSrc);   // copy the auto-loot options (gameoptionstruct.cpp)
Unk_GsAutoLoot* FUN_141260ea0(Unk_GsAutoLoot* p);                       // reset, returns p
void FUN_141260ed0(Unk_GsAutoLoot* p);                                  // reset to the defaults
int LoadGameOptionAutoLooting(Unk_GsAutoLoot* p, class TiXmlDocument* pDoc);   // C3: was FUN_141260f40
void FUN_141261530(Unk_GsAutoLoot* p, bool b);                          // set equip
void FUN_141261550(Unk_GsAutoLoot* p, int n);                           // set the grade
void FUN_141261570(Unk_GsAutoLoot* p, bool b);                          // set consume
void FUN_141261590(Unk_GsAutoLoot* p, bool b);                          // set etc
void FUN_1412615b0(Unk_GsAutoLoot* p, bool b);                          // set meso
void FUN_1412615d0(Unk_GsAutoLoot* p, bool b);                          // set merat
void FUN_1412615f0(Unk_GsAutoLoot* p, bool b);                          // set token
void FUN_141261610(Unk_GsAutoLoot* p, bool b);                          // set other
void FUN_141261630(Unk_GsAutoLoot* p, bool b);                          // set gemstone
void FUN_141261650(Unk_GsAutoLoot* p, bool b);                          // set pet

// ---- out-of-unit callees ----
class Unk_140166410* FUN_140166410();   // C3: was FUN_140166410
class CFeatureManager   // C3: member view for the former free stand-ins
{
public:
    bool FUN_14036d570(int);
    bool IsRegionCN();
};
class Unk_BreakSelected* FUN_140535320();   // C3: was FUN_140535320
#define FUN_140c8b450(p) ((Unk_GoAutoCfg*)reinterpret_cast<CPetManager*>(p)->GetInfo())   // C3: CPetManager::GetInfo (cpetmanager.h)
class CGameOption { public: void SaveCharacterSettings(); class TiXmlDocument* FUN_141244300(); Unk_GoAutoLoot* FUN_141533e20(); };   // C3: member view (gameoption.cpp)
void FUN_140710590(COutPacket& packet);                         // send

// @0x1419d95c0
UIItemGetOptionDialog::UIItemGetOptionDialog()
{
    m_nMode = 1;
    FUN_141260ea0((Unk_GsAutoLoot*)&m_opt);
    FUN_141924170(1);
}

// @0x1419d9640
UIItemGetOptionDialog::~UIItemGetOptionDialog()
{
}

// @0x1419d9680
CString UIItemGetOptionDialog::GetTypeName()
{
    return CString("ItemGetOptionDialog");
}

// @0x1419d96d0
void UIItemGetOptionDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    FUN_1419da8f0();
}

// @0x1419d9700
void UIItemGetOptionDialog::vfunc_67()
{
    UIModalDialog::vfunc_67();
}

// @0x1419d9720
void UIItemGetOptionDialog::OnLoadComplete()
{
    UIModalDialog::OnLoadComplete();
    if (MS2Ptr<ASCheckBox> hEquip = GetChild<ASCheckBox>("m_equip"))
        hEquip.get()->FUN_1422ce090(m_opt.FUN_1419dae70());
    if (MS2Ptr<ASCheckBox> hConsume = GetChild<ASCheckBox>("m_consume"))
        hConsume.get()->FUN_1422ce090(m_opt.FUN_1419dae50());
    if (MS2Ptr<ASCheckBox> hEtc = GetChild<ASCheckBox>("m_etc"))
        hEtc.get()->FUN_1422ce090(m_opt.FUN_1419dae60());
    if (MS2Ptr<ASCheckBox> hMeso = GetChild<ASCheckBox>("m_meso"))
        hMeso.get()->FUN_1422ce090(m_opt.FUN_1419daea0());
    if (MS2Ptr<ASCheckBox> hMerat = GetChild<ASCheckBox>("m_merat"))
        hMerat.get()->FUN_1422ce090(m_opt.FUN_1419dae90());
    if (MS2Ptr<ASCheckBox> hToken = GetChild<ASCheckBox>("m_token"))
        hToken.get()->FUN_1422ce090(m_opt.FUN_1419daed0());
    if (MS2Ptr<ASCheckBox> hOther = GetChild<ASCheckBox>("m_other"))
        hOther.get()->FUN_1422ce090(m_opt.FUN_1419daeb0());
    if (MS2Ptr<ASCheckBox> hGem = GetChild<ASCheckBox>("m_gemstone"))
        hGem.get()->FUN_1422ce090(m_opt.FUN_1419dae80());
    if (MS2Ptr<ASCheckBox> hPet = GetChild<ASCheckBox>("m_pet"))
        hPet.get()->FUN_1422ce090(m_opt.FUN_1419daec0());
    if (MS2Ptr<ASDropdownMenu> hRank = ((UISwfEntity*)this)->GetChild<ASDropdownMenu>("m_equipRank"))
    {
        int nSel = 0;
        int nGrade = m_opt.FUN_1419dae30();
        if (nGrade == 1)
            nSel = 0;
        else if (nGrade == 2)
            nSel = 1;
        else if (nGrade == 3)
            nSel = 2;
        else if (nGrade == 4)
            nSel = 3;
        else if (nGrade == 5)
            nSel = 4;
        else if (nGrade == 6)
            nSel = 5;
        if (hRank.get()->GetSelectedIndex() != nSel)
            hRank.get()->SetSelectedIndex(nSel);
    }
}

// @0x1419d9f30
int UIItemGetOptionDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("OnCheckEquip", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            bool bValue = data.PopBool();
            FUN_141261530((Unk_GsAutoLoot*)&m_opt, bValue);
        }
        return 1;
    }
    else if (_stricmp("OnCheckConsume", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            bool bValue = data.PopBool();
            FUN_141261570((Unk_GsAutoLoot*)&m_opt, bValue);
        }
        return 1;
    }
    else if (_stricmp("OnCheckEtc", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            bool bValue = data.PopBool();
            FUN_141261590((Unk_GsAutoLoot*)&m_opt, bValue);
        }
        return 1;
    }
    else if (_stricmp("onCheckGemStone", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            bool bValue = data.PopBool();
            FUN_141261630((Unk_GsAutoLoot*)&m_opt, bValue);
        }
        return 1;
    }
    else if (_stricmp("OnCheckMeso", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            bool bValue = data.PopBool();
            FUN_1412615b0((Unk_GsAutoLoot*)&m_opt, bValue);
        }
        return 1;
    }
    else if (_stricmp("OnCheckMerat", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            bool bValue = data.PopBool();
            FUN_1412615d0((Unk_GsAutoLoot*)&m_opt, bValue);
        }
        return 1;
    }
    else if (_stricmp("OnCheckToken", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            bool bValue = data.PopBool();
            FUN_1412615f0((Unk_GsAutoLoot*)&m_opt, bValue);
        }
        return 1;
    }
    else if (_stricmp("OnCheckOther", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            bool bValue = data.PopBool();
            FUN_141261610((Unk_GsAutoLoot*)&m_opt, bValue);
        }
        return 1;
    }
    else if (_stricmp("onCheckPet", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            bool bValue = data.PopBool();
            FUN_141261650((Unk_GsAutoLoot*)&m_opt, bValue);
        }
        return 1;
    }
    else if (_stricmp("onChangeEquipRank", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            int nIndex = data.PopInt();
            int nGrade = 1;
            if (nIndex == 0)
                nGrade = 1;
            else if (nIndex == 1)
                nGrade = 2;
            else if (nIndex == 2)
                nGrade = 3;
            else if (nIndex == 3)
                nGrade = 4;
            else if (nIndex == 4)
                nGrade = 5;
            else if (nIndex == 5)
                nGrade = 6;
            FUN_141261550((Unk_GsAutoLoot*)&m_opt, nGrade);
        }
        return 1;
    }
    else if (_stricmp("OnClickOk", szMethod) == 0)
    {
        FUN_1419dabc0();
        vfunc_67();
        return 1;
    }
    return 0;
}

// @0x1419da620
void UIItemGetOptionDialog::SetMode(int nMode)
{
    m_nMode = nMode;
}

// @0x1419da640
int UIItemGetOptionDialog::vfunc_46()
{
    if (!((class CFeatureManager*)(void*)(((void*)FUN_140166410())))->FUN_14036d570(0x8d))
    {
        if (MS2Ptr<ASCheckBox> hPet = GetChild<ASCheckBox>("m_pet"))
        {
            ASCheckBox* pCheck = hPet.get();
            pCheck->vfunc_4(false);
            hPet.get()->FUN_1422c1fe0(0);
        }
    }
    if (!((class CFeatureManager*)(void*)(((void*)FUN_140166410())))->FUN_14036d570(0x2e))
    {
        if (MS2Ptr<ASCheckBox> hGem = GetChild<ASCheckBox>("m_gemstone"))
        {
            ASCheckBox* pCheck = hGem.get();
            pCheck->vfunc_3(0);
        }
    }
    if (((class CFeatureManager*)(void*)(((void*)FUN_140166410())))->IsRegionCN() == true)
    {
        if (MS2Ptr<ASCheckBox> hMerat = GetChild<ASCheckBox>("m_merat"))
        {
            ASCheckBox* pCheck = hMerat.get();
            pCheck->vfunc_3(0);
        }
    }
    if (m_30.get())
        m_30->Invoke("updateAlign");
    return 1;
}

// @0x1419da8f0
void UIItemGetOptionDialog::FUN_1419da8f0()
{
    if (m_nMode != 0)
    {
        FUN_141260ed0((Unk_GsAutoLoot*)&m_opt);
        LoadGameOptionAutoLooting((Unk_GsAutoLoot*)&m_opt, TSingleton<CGameOption>::GetInstance()->FUN_141244300());
    }
    else
    {
        FUN_1412615b0((Unk_GsAutoLoot*)&m_opt, FUN_140c8b450(((void*)FUN_140535320()))->m_nMeso != 0);
        if (!((class CFeatureManager*)(void*)(((void*)FUN_140166410())))->IsRegionCN())
            FUN_1412615d0((Unk_GsAutoLoot*)&m_opt, FUN_140c8b450(((void*)FUN_140535320()))->m_nMerat != 0);
        FUN_141261590((Unk_GsAutoLoot*)&m_opt, FUN_140c8b450(((void*)FUN_140535320()))->m_nEtc != 0);
        FUN_1412615f0((Unk_GsAutoLoot*)&m_opt, FUN_140c8b450(((void*)FUN_140535320()))->m_nToken != 0);
        FUN_141261530((Unk_GsAutoLoot*)&m_opt, FUN_140c8b450(((void*)FUN_140535320()))->m_nEquip != 0);
        FUN_141261570((Unk_GsAutoLoot*)&m_opt, FUN_140c8b450(((void*)FUN_140535320()))->m_nConsume != 0);
        FUN_141261610((Unk_GsAutoLoot*)&m_opt, FUN_140c8b450(((void*)FUN_140535320()))->m_nOther != 0);
        FUN_141261550((Unk_GsAutoLoot*)&m_opt, FUN_140c8b450(((void*)FUN_140535320()))->m_nGrade);
        if (((class CFeatureManager*)(void*)(((void*)FUN_140166410())))->FUN_14036d570(0x2e) == true)
            FUN_141261630((Unk_GsAutoLoot*)&m_opt, FUN_140c8b450(((void*)FUN_140535320()))->m_nGemstone != 0);
        if (((class CFeatureManager*)(void*)(((void*)FUN_140166410())))->FUN_14036d570(0x8c))
            FUN_141261650((Unk_GsAutoLoot*)&m_opt, FUN_140c8b450(((void*)FUN_140535320()))->m_nPet != 0);
    }
}

// @0x1419dabc0
void UIItemGetOptionDialog::FUN_1419dabc0()
{
    if (m_nMode != 0)
    {
        FUN_141261310((Unk_GsAutoLoot*)TSingleton<CGameOption>::GetInstance()->FUN_141533e20(), (const Unk_GsAutoLoot*)&m_opt);
        TSingleton<CGameOption>::GetInstance()->SaveCharacterSettings();
    }
    else
    {
        Unk_PetFlags data;   // ccpetinfopacket.h's (ctor 0x1401ff780), the Unk_GoPacket layout: a..j = meso, merat, etc, token, equip, consume, gemstone, pet, other, grade
        data.a = m_opt.FUN_1419daea0();
        if (!((class CFeatureManager*)(void*)(((void*)FUN_140166410())))->IsRegionCN())
            data.b = m_opt.FUN_1419dae90();
        data.c = m_opt.FUN_1419dae60();
        data.d = m_opt.FUN_1419daed0();
        data.e = m_opt.FUN_1419dae70();
        data.f = m_opt.FUN_1419dae50();
        data.i = m_opt.FUN_1419daeb0();
        data.j = m_opt.FUN_1419dae30();
        if (((class CFeatureManager*)(void*)(((void*)FUN_140166410())))->FUN_14036d570(0x2e) == true)
            data.g = m_opt.FUN_1419dae80();
        if (((class CFeatureManager*)(void*)(((void*)FUN_140166410())))->FUN_14036d570(0x8c))
            data.h = m_opt.FUN_1419daec0();
        COutPacket packet(static_cast<int>(SendOp::RequestPet), 0);
        packet.WriteUInt8(6);
        FUN_1401ff810((unsigned char*)(&data), *(class COutputStream*)(&packet));
        FUN_140710590(packet);
    }
}

// @0x1419daee0
// The CRT inline memmove_s, emitted here as a COMDAT copy that nothing in this unit calls (_VALIDATE_RETURN_ERRCODE).
unsigned long long FUN_1419daee0(void* pDst, unsigned long long nDstSize, void* pSrc, unsigned long long nCount)
{
    if (nCount == 0)
        return 0;
    {
        int nExpr = !!(pDst != 0);
        if (!nExpr)
        {
            *_errno() = 0x16;
            _invalid_parameter_noinfo();
            return 0x16;
        }
    }
    {
        int nExpr = !!(pSrc != 0);
        if (!nExpr)
        {
            *_errno() = 0x16;
            _invalid_parameter_noinfo();
            return 0x16;
        }
    }
    {
        int nExpr = !!(nDstSize >= nCount);
        if (!nExpr)
        {
            *_errno() = 0x22;
            _invalid_parameter_noinfo();
            return 0x22;
        }
    }
    memmove(pDst, pSrc, nCount);
    return 0;
}

// ---- hooks ----
