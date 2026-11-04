// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIHouseDemolishDialog: see unit_14134fc90.h. w276.
// MS2-UNIT: unit_14134fc90
// MS2-RANGE: 0x14134fc90-0x141350cf0 .text$mn
// MS2-PIN: ??_GUIHouseDemolishDialog@@UEAAPEAXI@Z 0x141350b70
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "unit_14134fc90.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/commonfiles/fielddata.h"
#include "ms2/client/ms2/fielddatacli.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/client/ms2/cubemapinformationservice_3.h"
#include "ms2/placeholder/fittingdollpc.h"
class MyPC { public: class Unk_PCCubeCraft * GetActiveCubeCraft(void); };
// return types of the getters this unit calls
class Unk_SoundSink;

// ---- unit-local views of exe types ----

// The ASGameEntity of the movie (the exe's dynamic_cast target; slot 2 positions it).
class ASGameEntity : public ASDisplayObject
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(int nAlign, int nX, int nY);
};

class Unk_DemolishCube;
// The local player (a MyPC).
class Unk_DemolishPC : public PC
{
public:
    Unk_DemolishCube* FUN_141530290();                          // the cube craft controller
};

// WorldService singleton (FUN_1403ed2d0).
class Unk_DemolishWorld
{
public:
    Unk_DemolishPC* FUN_141bd0cc0();                            // the local player
};
class WorldService   // C3: member view for the former free stand-ins
{
public:
    void* FUN_141bd0cc0();   // C3: the real member (0x141bd0cc0, the local player)
    static class WorldService* GetInstance();
    MS2Ptr<CFieldDataCli> FUN_141bd30a0();   // C3: the real member (0x141bd30a0, copy of m_298)
};

// The housing manager (FUN_1409670e0).
class Unk_DemolishHousing : public CubeMapInformationService
{
public:
    bool FUN_1410d27c0(__int64 nOwner, int nMode, int* pCount, int* pLimit);   // building count and limit
};
class Unk_AkoHouseSvc   // C3: member view for the former free stand-ins
{
public:
    static class Unk_AkoHouseSvc* GetInstance();
};

// The notice dispatcher (FUN_140939a10).
NotifySystem* FUN_140939a10();

// The string table (FUN_1409331f0).
class CKeyTable { public: class ATL::CStringT<wchar_t, class StrTraitMFC_DLL<wchar_t, class ATL::ChTraitsCRT<wchar_t>>> GetActionKeyName(int, int); }; class Unk_DemolishTable : public CKeyTable {
public:

};
Unk_SoundSink* FUN_1409331f0();

template <class A, class B> CStringW FormatStringId(int nId, const A& a, const B& b);
int FUN_14053f9c0(int nItemId);

// The notices of this dialog (RTTI names from the exe's dynamic_casts; payload int at +0x18).
class NotifyChangeGameOptionInput : public NotifyObject
{
public:
    int m_nOption;
};
class NotifyChangeUIBuildingCount : public NotifyObject
{
public:
    int m_nCount;
};

// @0x14134fc90
UIHouseDemolishDialog::UIHouseDemolishDialog()
    : m_bShown(false), m_bRefreshed(false), m_nDirty(0)
{
    m_58 = 0;
    FUN_141925e70(0, 1);
}

// @0x14134fd40
UIHouseDemolishDialog::~UIHouseDemolishDialog()
{
}

// @0x14134fd80
CString UIHouseDemolishDialog::GetTypeName()
{
    return "HouseDemolishDialog";
}
MS2_REPLACE_METHOD(0x14134FD80, UIHouseDemolishDialog, GetTypeName, 61, 0xA24B2187);

// @0x14134fdd0
int UIHouseDemolishDialog::vfunc_84()
{
    if (vfunc_55() != 0)
        return 0;
    Unk_DemolishPC* pPC = ((Unk_DemolishPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPC == 0)
        return 0;
    if (pPC->FUN_141659690() != 0)
        return 0;
    Unk_DemolishCube* pCube = ((class Unk_DemolishCube *)((class MyPC*)(pPC))->GetActiveCubeCraft());
    if (pCube == 0)
        return 0;
    if (((class Unk_DemolishHousing*)Unk_AkoHouseSvc::GetInstance())->FUN_1410c3180() != 0)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x14134FDD0, UIHouseDemolishDialog, vfunc_84, 143, 0x0B9FC753);

// @0x14134fe70
void UIHouseDemolishDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_bShown = false;
    m_bRefreshed = false;
    m_nDirty = 0;
    m_tick.Init();
    FUN_140939a10()->UnregisterNotify(L"NotifyChangeGameOptionInput", Delegate<void(NotifyObject*)>(this, &UIHouseDemolishDialog::OnNotifyChangeGameOptionInput));
    FUN_140939a10()->UnregisterNotify(L"NotifyChangeUIBuildingCount", Delegate<void(NotifyObject*)>(this, &UIHouseDemolishDialog::OnNotifyChangeUIBuildingCount));
}
MS2_REPLACE_METHOD(0x14134FE70, UIHouseDemolishDialog, vfunc_26, 509, 0xF36A0F20);

// @0x141350080
void UIHouseDemolishDialog::vfunc_67()
{
    UIDialog::vfunc_67();
}
MS2_REPLACE_METHOD(0x141350080, UIHouseDemolishDialog, vfunc_67, 24, 0x526E4F64);

// @0x1413500a0
void UIHouseDemolishDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_140939a10()->RegisterNotify(L"NotifyChangeGameOptionInput", Delegate<void(NotifyObject*)>(this, &UIHouseDemolishDialog::OnNotifyChangeGameOptionInput));
    FUN_140939a10()->RegisterNotify(L"NotifyChangeUIBuildingCount", Delegate<void(NotifyObject*)>(this, &UIHouseDemolishDialog::OnNotifyChangeUIBuildingCount));
}
MS2_REPLACE_METHOD(0x1413500A0, UIHouseDemolishDialog, OnLoadComplete, 439, 0xA6D31912);

// @0x141350260
void UIHouseDemolishDialog::vfunc_43()
{
    if (m_60 == 0 && m_78 != 0)
        return;
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (spEntity.get() != 0)
        spEntity->vfunc_2(1, 0, 0);
}
MS2_REPLACE_METHOD(0x141350260, UIHouseDemolishDialog, vfunc_43, 181, 0xE519B375);

// @0x141350320
void UIHouseDemolishDialog::vfunc_15()
{
    if (FUN_1422dc430() == 0)
        return;
    if (m_bShown == 0)
        return;
    if (m_nDirty == 0)
        return;
    if (m_tick.Check(300) != 0)
    {
        Refresh(&m_nDirty);
        m_nDirty = 0;
    }
}
MS2_REPLACE_METHOD(0x141350320, UIHouseDemolishDialog, vfunc_15, 131, 0xB17841E5);

// @0x1413503b0
void UIHouseDemolishDialog::Show()
{
    if (m_bShown == 1)
        return;
    vfunc_8(1);
    m_bShown = true;
    if (m_bRefreshed == 0)
    {
        unsigned nFlags = 3;
        Refresh(&nFlags);
    }
    else
    {
        unsigned nFlags = 3;
        AddDirty(&nFlags);
    }
}
MS2_REPLACE_METHOD(0x1413503B0, UIHouseDemolishDialog, Show, 130, 0x4C1CB1A0);

// @0x141350440
void UIHouseDemolishDialog::Hide()
{
    if (m_bShown == 0)
        return;
    vfunc_8(0);
    m_bShown = false;
}
MS2_REPLACE_METHOD(0x141350440, UIHouseDemolishDialog, Hide, 62, 0xE025C16A);

// @0x141350490
void UIHouseDemolishDialog::Refresh(const unsigned* pnFlags)
{
    if ((*(const MS2Ptr<AScript>*)(&m_30) == 0) != 0 || m_bShown == 0)
        return;
    if (*pnFlags == 0)
        return;
    if ((*pnFlags & 1) != 0)
    {
        Unk_DemolishPC* pPC = ((Unk_DemolishPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
        if (pPC != 0)
        {
            MS2Ptr<CFieldDataCli> spField = WorldService::GetInstance()->FUN_141bd30a0();
            if (spField ? true : false)
            {
                if (spField->FUN_140375130() == 0)
                {
                    int nCount = 0;
                    int nLimit = 0;
                    ((class CubeMapInformationService*)(((class Unk_DemolishHousing*)Unk_AkoHouseSvc::GetInstance())))->FUN_1410d27c0(((class PC*)(class Unk_DemolishPC*)(pPC))->FUN_141656ad0(), 0, &nCount, &nLimit);
                    MS2Ptr<ASTextField> spText = GetChild<ASTextField>("m_textField");
                    if (spText.get() != 0)
                    {
                        CStringW strText = FormatStringId<int, int>(0x700, nCount, nLimit);
                        spText->SetTextHTMLW(strText);
                    }
                }
            }
        }
    }
    if ((*pnFlags & 2) != 0)
    {
        MS2Ptr<ASTextField> spText = GetChild<ASTextField>("m_textKey");
        if (spText.get() != 0)
        {
            CStringW strText = reinterpret_cast<Unk_DemolishTable*>(FUN_1409331f0())->GetActionKeyName(0x493ed, 0);
            spText->SetTextHTMLW(strText);
        }
    }
    m_bRefreshed = true;
}
MS2_REPLACE_METHOD(0x141350490, UIHouseDemolishDialog, Refresh, 672, 0x61028F6C);

// @0x141350740
void UIHouseDemolishDialog::AddDirty(const unsigned* pnFlags)
{
    m_nDirty |= *pnFlags;
}
MS2_REPLACE_METHOD(0x141350740, UIHouseDemolishDialog, AddDirty, 42, 0xDB6FDCAE);

// @0x141350770
void UIHouseDemolishDialog::OnNotifyChangeGameOptionInput(NotifyObject* pNotify)
{
    if ((*(const MS2Ptr<AScript>*)(&m_30) == 0))
        return;
    if (!m_bShown)
        return;
    NotifyChangeGameOptionInput* pOption = dynamic_cast<NotifyChangeGameOptionInput*>(pNotify);
    if (!pOption)
        return;
    if (pOption->m_nOption != 9)
        return;
    unsigned nFlags = 2;
    AddDirty(&nFlags);
}

// @0x141350810
void UIHouseDemolishDialog::OnNotifyChangeUIBuildingCount(NotifyObject* pNotify)
{
    if ((*(const MS2Ptr<AScript>*)(&m_30) == 0))
        return;
    if (!m_bShown)
        return;
    NotifyChangeUIBuildingCount* pCount = dynamic_cast<NotifyChangeUIBuildingCount*>(pNotify);
    if (!pCount)
        return;
    if (pCount->m_nCount == 0 || FUN_14053f9c0(pCount->m_nCount) != 0)
    {
        unsigned nFlags = 1;
        AddDirty(&nFlags);
    }
}
