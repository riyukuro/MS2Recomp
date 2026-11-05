// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIConstructHelpDialog: see uiconstructhelpdialog.h.
// MS2-UNIT: ?\uiconstructhelpdialog.cpp
// MS2-RANGE: 0x141905eb0-0x141906490 .text$mn
// MS2-PIN: ??_GUIConstructHelpDialog@@UEAAPEAXI@Z 0x141906440
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiconstructhelpdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uiconstructhelpdialog.h"
#include "uimessagebox.h"

#include <efd/ISystemService.h>
#include <efd/ServiceManager.h>

#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/worldservice.h"
#include <efd/SmartPointer.h>   // C3: efd::SmartPointer<CubeMapInformationService>::operator->
class CubeMapInformationService;   // C3: efd::SmartPointer<CubeMapInformationService>::operator->

// ---- unit-local views of exe types ----------------------------------------------------------------------------------

#include "ms2/placeholder/scriptcontext.h"   // egf::ScriptContext g_bapiContext (was a local framework view)
namespace egf { class ScriptContext; extern ScriptContext g_bapiContext; }
#define DAT_143b059e8 egf::g_bapiContext

// The home (cube map information) service.
template <int N> struct Unk_CMISTree;   // the visitor id tree (a std::set<unsigned __int64>, cubemapinformationservice_3.h)
class CubeMapInformationService { public: bool FUN_1410c35c0(); void FUN_1410d5930(Unk_CMISTree<0x11e>* pOut); };   // FUN_1410d5930: collect the visitors
class Unk_HoService : public efd::ISystemService {
public:
    static const efd::ClassID CLASS_ID = 0x06100017;
};
//

// The smart pointer to the service (C3: efd::SmartPointer<CubeMapInformationService>).
template <> efd::SmartPointer<CubeMapInformationService>::SmartPointer(CubeMapInformationService* pObject);   // 0x1401cd0b0
template <> efd::SmartPointer<CubeMapInformationService>::~SmartPointer();                             // 0x1401cd150
template <> bool efd::SmartPointer<CubeMapInformationService>::operator==(CubeMapInformationService* pObject) const;   // 0x140ef4cb0 (C3: was the Unk_HoServicePtr view)
//


int FUN_1418fc760(char const*, void*, int, void*);   // C3: was FUN_1418fc760
int FUN_1418fd280();
void FUN_14151f200();

// @0x141905eb0
UIConstructHelpDialog::UIConstructHelpDialog()
{
    FUN_141924170(1);
    FUN_141925e70(0, 1);
}

// @0x141905f20
UIConstructHelpDialog::~UIConstructHelpDialog()
{
}

// @0x141905f60
CString UIConstructHelpDialog::GetTypeName()
{
    return "ConstructHelpDialog";
}

// @0x141905fb0
int UIConstructHelpDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    return 1;
}

// @0x141905fe0
void UIConstructHelpDialog::vfunc_67()
{
    UIDialog::vfunc_67();
}

// @0x141906000
void UIConstructHelpDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    efd::SmartPointer<CubeMapInformationService> spService(egf::g_bapiContext.GetSystemServiceAs<CubeMapInformationService>());
    if (spService == (CubeMapInformationService*)0)
        return;
    if (m_30.get() != 0)
        m_30->Invoke("setMode", !reinterpret_cast<CubeMapInformationService*>(spService.operator->())->FUN_1410c35c0());
}

// @0x1419060e0
void UIConstructHelpDialog::vfunc_79(void* p)
{
    UIDialog::vfunc_79(p);
    vfunc_55() || ((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull();
}

// @0x141906140
int UIConstructHelpDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (FUN_1418fc760(szMethod, (void*)(pArgs), nArgs, 0) != 0)
    {
        return 1;
    }
    return 0;
}

// @0x1419061b0
void UIConstructHelpDialog::vfunc_43()
{
    UIDialog::vfunc_43();
    efd::SmartPointer<CubeMapInformationService> spService(egf::g_bapiContext.GetSystemServiceAs<CubeMapInformationService>());
    if (spService == (CubeMapInformationService*)0)
        return;
    MS2Ptr<ASGameEntity> pEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (pEntity.get())
    {
        if (WorldService::GetInstance()->FUN_141bcb1a0() && FUN_1418fd280() != 0)
        {
            std::set<unsigned __int64> kVisitors;
            reinterpret_cast<CubeMapInformationService*>(spService.operator->())->FUN_1410d5930((Unk_CMISTree<0x11e>*)&kVisitors);
            if (kVisitors.empty() != 0)
                pEntity->vfunc_2(6, 0, 0x21);
            else
                pEntity->vfunc_2(6, -300, 0);
        }
        else
        {
            pEntity->vfunc_2(6, -300, 0);
        }
    }
}

// @0x141906380
int UIConstructHelpDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) != 0)
        return 1;
    if (pMsg->FUN_1422e4520() == 0 && dynamic_cast<UIMessageBox*>(pSender))
    {
        int nIndex = pMsg->PopInt();
        CStringW strTag = pMsg->FUN_1422b8f40();
        FUN_14151f200();
        return 1;
    }
    return 0;
}
