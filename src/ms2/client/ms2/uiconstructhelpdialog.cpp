// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIConstructHelpDialog: see uiconstructhelpdialog.h.
// MS2-UNIT: ?\uiconstructhelpdialog.cpp
// MS2-RANGE: 0x141905eb0-0x141906490 .text$mn
// MS2-PIN: ??_GUIConstructHelpDialog@@UEAAPEAXI@Z 0x141906440
// MS2-PIN: ??0Unk_ChTree@@QEAA@XZ 0x140333290
// MS2-PIN: ??1Unk_ChTree@@QEAA@XZ 0x140333cb0
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

// ---- unit-local views of exe types ----------------------------------------------------------------------------------

struct Unk_EntityAppFramework { efd::ServiceManagerPtr manager; };
extern Unk_EntityAppFramework DAT_143b059e8;

// The tree the home map information service collects the visitors into (24 bytes).
struct Unk_ChTree
{
    Unk_ChTree();                                               // 0x140333290
    ~Unk_ChTree();                                              // 0x140333cb0
    bool FUN_1404bd700();                                       // is empty
    void* m_pad_00[3];
};

// The home (cube map information) service.
class Unk_HoService : public efd::ISystemService {
public:
    static const efd::ClassID CLASS_ID = 0x06100017;
    bool FUN_1410c35c0();                                       // construct mode
    void FUN_1410d5930(Unk_ChTree* pOut);                       // collect the visitors
};
Unk_HoService* FUN_1401cd040(Unk_EntityAppFramework* framework);

// The smart pointer to the service (8 bytes; its glue COMDATs live in the unit that first used it).
class Unk_HoServicePtr
{
public:
    Unk_HoServicePtr(Unk_HoService* p);                         // 0x1401cd0b0
    ~Unk_HoServicePtr();                                        // 0x1401cd150
    Unk_HoService* FUN_1401cd1a0() const;                       // operator->
private:
    Unk_HoService* m_p;
};
unsigned char FUN_140ef4cb0(Unk_HoServicePtr* pService, int n);

WorldService* FUN_1403ed2d0();

bool FUN_140a467d0(const MS2Ptr<AScript>*);                     // has the AS object been released
int FUN_1418fc760(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs, void* pUnused);
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
    Unk_HoServicePtr spService(FUN_1401cd040(&DAT_143b059e8));
    if (FUN_140ef4cb0(&spService, 0))
        return;
    if (m_30.get() != 0)
        m_30->Invoke("setMode", !spService.FUN_1401cd1a0()->FUN_1410c35c0());
}

// @0x1419060e0
void UIConstructHelpDialog::vfunc_79(void* p)
{
    UIDialog::vfunc_79(p);
    vfunc_55() || FUN_140a467d0(&m_30);
}

// @0x141906140
int UIConstructHelpDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (FUN_1418fc760(szMethod, pArgs, nArgs, 0) != 0)
    {
        return 1;
    }
    return 0;
}

// @0x1419061b0
void UIConstructHelpDialog::vfunc_43()
{
    UIDialog::vfunc_43();
    Unk_HoServicePtr spService(FUN_1401cd040(&DAT_143b059e8));
    if (FUN_140ef4cb0(&spService, 0))
        return;
    MS2Ptr<ASGameEntity> pEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (pEntity.get())
    {
        if (FUN_1403ed2d0()->FUN_141bcb1a0() && FUN_1418fd280() != 0)
        {
            Unk_ChTree kVisitors;
            spService.FUN_1401cd1a0()->FUN_1410d5930(&kVisitors);
            if (kVisitors.FUN_1404bd700() != 0)
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
        int nIndex = pMsg->FUN_1422b8a10();
        CStringW strTag = pMsg->FUN_1422b8f40();
        FUN_14151f200();
        return 1;
    }
    return 0;
}
