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

// ---- unit-local views of exe types ----

// The ASGameEntity of the movie (the exe's dynamic_cast target; slot 2 positions it).
class ASGameEntity : public ASDisplayObject
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(int nAlign, int nX, int nY);
};

class Unk_DemolishCube;
// The local player (a MyPC).
class Unk_DemolishPC
{
public:
    int FUN_141659690();                                        // state flag (nonzero: not buildable)
    Unk_DemolishCube* FUN_141530290();                          // the cube craft controller
};
__int64 FUN_141656ad0(Unk_DemolishPC* pPC);                     // the owner id of the player's plot

// WorldService singleton (FUN_1403ed2d0).
class Unk_DemolishWorld
{
public:
    Unk_DemolishPC* FUN_141bd0cc0();                            // the local player
    MS2Ptr<CFieldDataCli> FUN_141bd30a0();                      // the current field data
};
Unk_DemolishWorld* FUN_1403ed2d0();

// The housing manager (FUN_1409670e0).
class Unk_DemolishHousing
{
public:
    bool FUN_1410d27c0(__int64 nOwner, int nMode, int* pCount, int* pLimit);   // building count and limit
    __int64 FUN_1410c3180();                                    // the owner id of the visited house
};
Unk_DemolishHousing* FUN_1409670e0();

// The notice dispatcher (FUN_140939a10).
class Unk_DemolishNotices
{
public:
    void FUN_140da4e40(CStringW strName, Delegate<void(NotifyObject*)> cb);    // subscribe
    void FUN_140da4eb0(CStringW strName, Delegate<void(NotifyObject*)> cb);    // unsubscribe
};
Unk_DemolishNotices* FUN_140939a10();

// The string table (FUN_1409331f0).
class Unk_DemolishTable
{
public:
    CStringW FUN_14142d760(int nId, int n);
};
Unk_DemolishTable* FUN_1409331f0();

CStringW FUN_140811740(int nId, const int& nArg1, const int& nArg2);   // formatted system text
bool FUN_140ba28d0(const MS2Ptr<AScript>* pAS, int n);          // has the AS object been released
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
CString UIHouseDemolishDialog::vfunc_1()
{
    return "HouseDemolishDialog";
}
MS2_REPLACE_METHOD(0x14134FD80, UIHouseDemolishDialog, vfunc_1, 61, 0xA24B2187);

// @0x14134fdd0
int UIHouseDemolishDialog::vfunc_84()
{
    if (vfunc_55() != 0)
        return 0;
    Unk_DemolishPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    if (pPC->FUN_141659690() != 0)
        return 0;
    Unk_DemolishCube* pCube = pPC->FUN_141530290();
    if (pCube == 0)
        return 0;
    if (FUN_1409670e0()->FUN_1410c3180() != 0)
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
    m_tick.FUN_140268840();
    FUN_140939a10()->FUN_140da4eb0(L"NotifyChangeGameOptionInput", Delegate<void(NotifyObject*)>(this, &UIHouseDemolishDialog::OnNotifyChangeGameOptionInput));
    FUN_140939a10()->FUN_140da4eb0(L"NotifyChangeUIBuildingCount", Delegate<void(NotifyObject*)>(this, &UIHouseDemolishDialog::OnNotifyChangeUIBuildingCount));
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
    FUN_140939a10()->FUN_140da4e40(L"NotifyChangeGameOptionInput", Delegate<void(NotifyObject*)>(this, &UIHouseDemolishDialog::OnNotifyChangeGameOptionInput));
    FUN_140939a10()->FUN_140da4e40(L"NotifyChangeUIBuildingCount", Delegate<void(NotifyObject*)>(this, &UIHouseDemolishDialog::OnNotifyChangeUIBuildingCount));
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
    if (m_tick.FUN_140268870(300) != 0)
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
// MS2-FUNCTIONAL: the owner id reaches the housing call through an extra rcx->rdx copy in the exe (3 bytes)
void UIHouseDemolishDialog::Refresh(const unsigned* pnFlags)
{
    if (FUN_140ba28d0(&m_30, 0) != 0 || m_bShown == 0)
        return;
    if (*pnFlags == 0)
        return;
    if ((*pnFlags & 1) != 0)
    {
        Unk_DemolishPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPC != 0)
        {
            MS2Ptr<CFieldDataCli> spField = FUN_1403ed2d0()->FUN_141bd30a0();
            if (spField ? true : false)
            {
                if (spField->FUN_140375130() == 0)
                {
                    int nCount = 0;
                    int nLimit = 0;
                    __int64 nOwner = FUN_141656ad0(pPC);
                    FUN_1409670e0()->FUN_1410d27c0(nOwner, 0, &nCount, &nLimit);
                    MS2Ptr<ASTextField> spText = FUN_140bb4cf0("m_textField");
                    if (spText.get() != 0)
                    {
                        CStringW strText = FUN_140811740(0x700, nCount, nLimit);
                        spText->FUN_1422c4f00(strText);
                    }
                }
            }
        }
    }
    if ((*pnFlags & 2) != 0)
    {
        MS2Ptr<ASTextField> spText = FUN_140bb4cf0("m_textKey");
        if (spText.get() != 0)
        {
            CStringW strText = FUN_1409331f0()->FUN_14142d760(0x493ed, 0);
            spText->FUN_1422c4f00(strText);
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
    if (FUN_140ba28d0(&m_30, 0))
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
    if (FUN_140ba28d0(&m_30, 0))
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
