// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIItemMultiOpenBoxDialog: see uiitemmultiopenboxdialog.h.
// MS2-UNIT: ?\uiitemmultiopenboxdialog.cpp
// MS2-RANGE: 0x140c3f350-0x140c3ff80 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiitemmultiopenboxdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uiitemmultiopenboxdialog.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit callees (names describe uses) ----
class Unk_McAttendTable                                          // the player inventory (global 0x143ab2a90)
{
public:
    MS2Ptr<CItem> FUN_140a5e2e0(unsigned nItemId);
};
extern Unk_McAttendTable g_attendItems;
void FUN_141415600(const CString& strName);                      // drop the item shown under a dialog name
void FUN_141415450(const CString& strName, MS2Ptr<CItem> item, int a, int b, int c);   // show an item under a dialog name
unsigned FUN_140869420();                                        // the client millisecond clock
void FUN_140710590(COutPacket& packet);
CStringW GetStringCommonByKey(const CStringW& strKey);                  // string table text
void FUN_140d73aa0(CStringW text, int nType, void* p, CStringW tag);   // message box
CStringW FUN_1409e8970(CStringW strKey, const int& a, const int& b);  // formatted string-table text
const int* FUN_1402fbd20(const int* a, const int* b);            // std::min<int>
struct Unk_McConstVal;
const int* FUN_1402056b0(Unk_McConstVal* slot);                  // constant value
struct Unk_McConstVal { void* m_0; void* m_8; };
struct Unk_McConfig
{
    char m_pad_00[0xa2e8];
    Unk_McConstVal m_multiOpenMax;                               // +0xa2e8
};
Unk_McConfig* FUN_1401d3200();

// The inventory dialog (ui id 0x4e2d): only the flag word this dialog sets on it.
class Unk_McInventoryDialog : public UIDialog
{
public:
    void FUN_140c3fe30(unsigned nFlags);                         // m_19c |= nFlags
private:
    char m_pad_178[0x19c - 0x178];
    unsigned m_19c;
};
Unk_McInventoryDialog* FUN_1405344f0(int nId);

// @0x140c3f350
UIItemMultiOpenBoxDialog::UIItemMultiOpenBoxDialog() : m_180(0), m_184(0), m_190(0), m_194(0), m_198(0)
{
    FUN_141924170(1);
}

// @0x140c3f410
UIItemMultiOpenBoxDialog::~UIItemMultiOpenBoxDialog()
{
}

// @0x140c3f470
CString UIItemMultiOpenBoxDialog::GetTypeName()
{
    return "ItemMultiOpenBoxDialog";
}
MS2_REPLACE_METHOD(0x140C3F470, UIItemMultiOpenBoxDialog, GetTypeName, 61, 0x54C11ABA);

// @0x140c3f4c0
void UIItemMultiOpenBoxDialog::vfunc_67()
{
    UIModalDialog::vfunc_67();
    FUN_141415600(GetTypeName());
    Unk_McInventoryDialog* pInventory = FUN_1405344f0(0x4e2d);
    if (pInventory != 0)
        pInventory->FUN_140c3fe30(2);
    m_180 = 0;
    m_184 = 0;
    m_190 = 0;
    m_194 = 0;
    m_198 = 0;
    m_188.Empty();
}
MS2_REPLACE_METHOD(0x140C3F4C0, UIItemMultiOpenBoxDialog, vfunc_67, 224, 0x199BF750);

// @0x140c3f5b0
int UIItemMultiOpenBoxDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140C3F5B0, UIItemMultiOpenBoxDialog, vfunc_65, 37, 0xA5103A1F);

// @0x140c3f5e0
void UIItemMultiOpenBoxDialog::vfunc_26()
{
    UIDialog::vfunc_26();
}
MS2_REPLACE_METHOD(0x140C3F5E0, UIItemMultiOpenBoxDialog, vfunc_26, 24, 0xF4021161);

// @0x140c3f600
void UIItemMultiOpenBoxDialog::OnLoadComplete()
{
    UIModalDialog::OnLoadComplete();
    FUN_140c3fca0();
    MS2Ptr<CItem> item = g_attendItems.FUN_140a5e2e0(m_180);
    if (item.get() != 0)
    {
        FUN_141415600(GetTypeName());
        FUN_141415450(GetTypeName(), item, 0, 1, 0);
        if (m_30.get() != 0)
            m_30->Invoke("setItem", GetTypeName());
        m_198 = FUN_140869420() + 500;
    }
}
MS2_REPLACE_METHOD(0x140C3F600, UIItemMultiOpenBoxDialog, OnLoadComplete, 507, 0x1D0B5491);

// @0x140c3f810
int UIItemMultiOpenBoxDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("OnCancel", szMethod) == 0)
    {
        m_198 = 0;
        vfunc_67();
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140C3F810, UIItemMultiOpenBoxDialog, vfunc_28, 129, 0x87EE845D);

// @0x140c3f8a0
void UIItemMultiOpenBoxDialog::vfunc_15()
{
    UISwfEntity::vfunc_15();
    unsigned nNow = FUN_140869420();
    if (m_198 != 0 && nNow > (unsigned)m_198)
    {
        m_198 = 0;
        int nCount = *FUN_1402fbd20(&m_194, FUN_1402056b0(&FUN_1401d3200()->m_multiOpenMax));
        COutPacket packet(0x1a, 0);
        packet.vfunc_o10_3(m_180);
        packet.vfunc_o10_2(m_184);
        packet.vfunc_o10_3(nCount);
        packet.vfunc_o10_8(m_188);
        FUN_140710590(packet);
    }
}
MS2_REPLACE_METHOD(0x140C3F8A0, UIItemMultiOpenBoxDialog, vfunc_15, 286, 0xD93FFCC0);

// @0x140c3f9d0
void UIItemMultiOpenBoxDialog::FUN_140c3f9d0(int nBoxId, int nSlot, CStringW strKey, int nCount)
{
    m_180 = nBoxId;
    m_184 = nSlot;
    m_190 = nCount;
    m_188 = strKey;
    m_194 = nCount;
    m_198 = 0;
    FUN_141924680();
}

// @0x140c3fa80
// MS2-FUNCTIONAL: the exe stores the two message-box temporaries' addresses before it builds the string-table key (no source form found)
void UIItemMultiOpenBoxDialog::FUN_140c3fa80(int nOpened, int nResult)
{
    if (vfunc_55() != 0)
        return;
    m_194 = m_194 - nOpened;
    if (nResult == 2)
    {
        FUN_140c3fca0();
        if (m_194 > 0)
            m_198 = FUN_140869420() + 100;
        else
            vfunc_67();
    }
    else
    {
        switch (nResult)
        {
        case 3:
        {
            CStringW strKey(L"s_err_cannot_open_multi_itembox_inventory_fail");
            FUN_140d73aa0(GetStringCommonByKey(strKey), 0, 0, CStringW(L""));
            break;
        }
        case 4:
        {
            CStringW strKey(L"s_err_cannot_open_multi_itembox_inventory");
            FUN_140d73aa0(GetStringCommonByKey(strKey), 0, 0, CStringW(L""));
            break;
        }
        }
        vfunc_67();
    }
}
MS2_REPLACE_METHOD(0x140C3FA80, UIItemMultiOpenBoxDialog, FUN_140c3fa80, 536, 0x96E33585);

// @0x140c3fca0
// MS2-FUNCTIONAL: the exe copies the returned text-field handle through one more pointer temp than the source form gives
void UIItemMultiOpenBoxDialog::FUN_140c3fca0()
{
    MS2Ptr<ASTextField> spCount = FUN_140bb4cf0(CString("m_count"));
    if (spCount.get() != 0)
    {
        int nUsed = m_190 - m_194;
        spCount.operator->()->FUN_1422c4cd0(FUN_1409e8970(CStringW(L"s_item_multi_open_box_count"), nUsed, m_190));
    }
}
MS2_REPLACE_METHOD(0x140C3FCA0, UIItemMultiOpenBoxDialog, FUN_140c3fca0, 310, 0xAF05CB1C);

// @0x140c3fe30
void Unk_McInventoryDialog::FUN_140c3fe30(unsigned nFlags)
{
    m_19c |= nFlags;
}

MS2_EMIT_CRT_MEMMOVE_S();
