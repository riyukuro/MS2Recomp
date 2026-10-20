// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIItemCreateDialog (UI type 0x4e25): the GM "create item"
// window, and the item option simulator (ItemOptionDebug). See uiitemcreatedialog.h.
// MS2-UNIT: ?\uiitemcreatedialog.cpp
// MS2-RANGE: 0x140115380-0x140115690 .text$di
// MS2-RANGE: 0x1419b3c50-0x1419bc730 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?CompareElementsOrdered@?$CDefaultCompareTraits@M@ATL@@SAHAEBM0@Z 0x1419ba3e0 ; unique
// MS2-PIN: ?vfunc_48@UIItemCreateDialog@@UEAAHXZ 0x1419baa80 ; unique
// MS2-PIN: ?Lookup@?$CRBMap@_JHV?$CElementTraits@_J@ATL@@V?$CElementTraits@H@2@@ATL@@QEBA_N_JAEAH@Z 0x1419bb090 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??1?$CRBMap@MHV?$CElementTraits@M@ATL@@V?$CElementTraits@H@2@@ATL@@QEAA@XZ 0x1419b9f60 ; the counts of FUN_1419b7b10 / 80e0 / 83d0
// MS2-PIN: ??1?$CRBTree@MHV?$CElementTraits@M@ATL@@V?$CElementTraits@H@2@@ATL@@QEAA@XZ 0x1419b9f80 ; called by 0x1419b9f60
// MS2-PIN: ?IsEmpty@?$CRBTree@MHV?$CElementTraits@M@ATL@@V?$CElementTraits@H@2@@ATL@@QEBA_NXZ 0x1419bad80 ; called by FUN_1419b7b10
// MS2-PIN: ?IsEmpty@?$CRBTree@_JHV?$CElementTraits@_J@ATL@@V?$CElementTraits@H@2@@ATL@@QEBA_NXZ 0x1419badb0 ; called by FUN_1419b7e00
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiitemcreatedialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uiitemcreatedialog.h"

#include <direct.h>
#include <utility>
#include <vector>

#include <efd/File.h>

#include "ms2/ms2format.h"
#include "ms2/client/ms2/uiitemdropinfodialog.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/commonfiles/itemdata.h"
#include "ms2/commonfiles/itemdatatable.h"
#include "ms2/commonfiles/itemoption.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/guess/usercommandcli.h"
#include "ms2/placeholder/asbutton.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/cccreateitempacket.h"
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/commonresource.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/ms2ptr_impl.h"

// ---- the statics of the shared header, the key input controller, then a second copy of the shared statics ----
#include "ms2/placeholder/header_statics_a.h"                                          // @0x140115380..0x1401154a0
#ifndef MS2_HOOK_DLL
static UICommon::CMyPCKeyInputController s_keyInputController;                          // @0x1401154f0
#endif
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};  // @0x140115520
static CString s_strSkill2 = "skill";                                                   // @0x1401155e0
static CString s_strStun2 = "stun";                                                     // @0x140115610
static Unk_1402a9d70 s_unk1402a9d70b(17, 0.75f, 0.25f, 2.25f, 10);                      // @0x140115640

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of exe objects ----

// The movie root of the dialog (UIDialog::m_90); slot 24 shows / hides it.
class ASDialog : public ASMovieClip
{
public:
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bShow);
};

// The AS controls of the movie: the list controls ("m_items", "m_contextMenu", "m_function"), the rank combo
// ("m_itemGrade"), the period input, the job / gender check boxes and the "m_clearInven" button.
class Unk_IcControl : public ASUIComponent
{
public:
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);                   // refresh the control
};
class Unk_IcList : public Unk_IcControl
{
public:
    void FUN_1422dd1d0();                                   // remove all rows
    void FUN_1422dcca0(int nSelected);                      // select a row
    void FUN_1422dd230(const ASObj& row);                   // append a row
    void FUN_1422dd310(const CStringW& strLabel);           // append a text row
    int FUN_1422dd150();                                    // row count
    CStringW FUN_1422dd520();                               // label of the selected row
    void FUN_1422de0e0(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& callback, int n);   // change handler
};
class Unk_IcDataProvider : public ASArray
{
public:
    ASObj FUN_1422df140(int nIndex);                        // the row at the index
    void FUN_1419b9900(int nIndex, const CString& strName, int& nOut);
};
class Unk_IcCombo : public Unk_IcControl
{
public:
    int FUN_1422df6c0();                                    // the selected row
    MS2Ptr<Unk_IcDataProvider> FUN_1422df770();             // the data provider
    void FUN_1419b9990(const CString& strName, int& nOut);  // a member of the selected row
};
class Unk_IcInput : public Unk_IcControl
{
public:
    void FUN_1422e0ab0(const CStringW& strText);            // set the text
    void FUN_1422c1fe0(unsigned int bEnabled);              // enable / disable
};
class Unk_IcCheck : public ASCheckBox
{
};
class Unk_IcButton : public ASButton
{
};

// The click event of a list row (ctor 0x1422e2740).
class ASListEvent
{
public:
    ASListEvent(const Scaleform::GFx::FunctionHandler::Params& params);
    ~ASListEvent();
    Scaleform::GFx::Value FUN_1422e2780();                  // the row object
    char m_pad[0x40];
};

// The game TinyXML element (ctor 0x14086f2f0, 0x90 bytes; the document owns and deletes it).
class TiXmlElement
{
public:
    TiXmlElement(const char* szName);
private:
    char m_pad[0x90];
};
void* FUN_14081b310(TiXmlDocument* pDoc);                   // the root element
void FUN_14086ddc0(TiXmlDocument* pDoc);                    // load the document
void* FUN_14086e090(void* pParent, TiXmlElement* pChild);   // link a child
bool FUN_1408710c0(TiXmlDocument* pDoc, const char* szPath);   // save
void FUN_140873ce0(void* pElement, const char* szName, int n);           // set an int attribute
void FUN_140873e30(void* pElement, const char* szName, float f);         // set a float attribute
void FUN_140874050(void* pElement, const char* szName, const CString& str);   // set a string attribute

MS2Ptr<CItemData> FUN_14053f870(unsigned nItemId);          // the item row (NULL: no such item)
int FUN_14053feb0(int nItemId);                             // the default rank of an item
bool FUN_14053ff30(int nItemId, int nRank);                 // the item has the rank
int FUN_1405451c0(const CString& strGroup);                 // the item group index of a group name
unsigned short FUN_140718200(const CStringW& strText);      // text to number
CStringW FUN_1407196b0(int n);                              // number to text
CStringW FUN_14083f330(CStringW strText, wchar_t chBegin, wchar_t chEnd);  // the text between two characters
void FUN_140841420(CStringW& str);                          // lower case
void FUN_14025a680(const CStringW& strText, ATL::CAtlArray<CStringW>& tokens, const wchar_t* szSeparator);   // split
void FUN_14083d890(CStringW strText);                       // copy to the clipboard
void FUN_1412751b0(const CStringW& strText, int nType);     // system notice
CStringW FUN_14082f000(int nStat);                          // text of a stat
CStringW FUN_140630e10(int nSpecial);                       // text of a special ability
CString FUN_14016a600(const wchar_t* sz, int nCodePage);    // narrow a string
CString FUN_14016a5c0(const char* sz, int nCodePage);       // copy a string
CString FUN_140cc2a00(CString strDir, const CString& strFile);   // the path of a file in a directory
void FUN_140710590(COutPacket& packet);                     // send
void FUN_1418fc840(MS2Ptr<Unk_IcCombo> spCombo, int nItemId, int nRank);   // fill the rank combo of an item
CFileSystem* FUN_140166420();

template <class T> static T* Unk_IcGetDialog(int nId)
{
    if (CUIService::GetInstance()) {
        MS2Ptr<UIObject> p = CUIService::GetInstance()->FUN_141adcea0((eUIClassID)nId);
        if (p.get())
            return dynamic_cast<T*>((UIObject*)p);
    }
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x1419b3c50
UIItemCreateDialog::UIItemCreateDialog()
{
    m_40 = 1;
    FUN_1422dc3b0(1);
}

// @0x1419b3d10
CString UIItemCreateDialog::vfunc_1()
{
    return "ItemCreateDialog";
}
MS2_REPLACE_METHOD(0x1419b3d10, UIItemCreateDialog, vfunc_1, 61, 0xB554FE81);

// MS2-FUNCTIONAL: child binding / delegate temporaries ordered differently
// @0x1419b3d60
void UIItemCreateDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_90->vfunc_24(false);
    FUN_1419b4c70();
    m_spClearInven = FUN_140bb4b10("m_clearInven");
    if ((Unk_IcButton*)m_spClearInven) {
        m_spClearInven->FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIItemCreateDialog::FUN_1419b4dd0), 0);
    }
    FUN_1419b6350();
    FUN_1419b6790();
}
MS2_REPLACE_METHOD(0x1419b3d60, UIItemCreateDialog, OnLoadComplete, 416, 0xA5A1CFB7);

// @0x1419b3f10
void UIItemCreateDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_spClearInven = 0;
    m_spContextMenu = 0;
}
MS2_REPLACE_METHOD(0x1419b3f10, UIItemCreateDialog, vfunc_26, 66, 0xDE173C0D);

// MS2-FUNCTIONAL: key handler branch layout differs
// @0x1419b3f60
int UIItemCreateDialog::vfunc_13()
{
    if (UIDialog::vfunc_13() == 0) {
        if (CInputKeyHandler::GetInstance()->FUN_14116d9c0(0x1c, 0, 0) == 0) {
            if (CInputKeyHandler::GetInstance()->FUN_14116d9c0(0xf, 0, 0) == 0) {
                if (CInputKeyHandler::GetInstance()->FUN_14116d950(0x1d, 0, 0) && CInputKeyHandler::GetInstance()->FUN_14116d9c0(0x2e, 0, 0)) {
                    FUN_14083d890(CStringW(FUN_1407196b0(FUN_1419b5080())));
                    return 1;
                }
                return 0;
            }
            if (m_30.get() != 0)
                m_30->Invoke("onTabKey");
            return 1;
        }
        if (m_30.get() != 0)
            m_30->Invoke("onEnterKey");
        return 1;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1419b3f60, UIItemCreateDialog, vfunc_13, 444, 0x223A8463);

// @0x1419b4130
int UIItemCreateDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    UIDialog::vfunc_28(szMethod, pArgs, nArgs);
    ASData data;
    if (_stricmp("OnItemChange", szMethod) == 0) {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0) {
            int nItemId = data.FUN_1422b8b10();
            int nRank = data.FUN_1422b8b10();
            FUN_1419b5560(nItemId, nRank);
        }
        return 1;
    } else if (_stricmp("OnGroupChange", szMethod) == 0) {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0) {
            FUN_1419b5730(data.FUN_1422b8d30(), L"");
        }
        return 1;
    } else if (_stricmp("OnFunctionChange", szMethod) == 0) {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0) {
            FUN_1419b5730("", data.FUN_1422b8f40());
        }
        return 1;
    } else if (_stricmp("OnCreateItem", szMethod) == 0) {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0) {
            int nItemId = data.FUN_1422b8b10();
            int nCount = data.FUN_1422b8b10();
            int nRank = data.FUN_1422b8b10();
            int nLevel = data.FUN_1422b8b10();
            int nEnchant = FUN_1419b5280(nItemId, nLevel);
            int nPeriod = data.FUN_1422b8b10();
            int g = data.FUN_1422b8a10();
            int h = data.FUN_1422b8a10();
            int i = data.FUN_1422b8a10();
            int j = data.FUN_1422b8a10();
            CCCreateItemPacket packet;
            packet.a = nItemId;
            packet.b = nCount;
            packet.c = nRank;
            packet.e = nLevel;
            packet.f = nEnchant;
            packet.d = nPeriod;
            packet.g = g;
            packet.h = h;
            packet.i = i;
            packet.j = j;
            FUN_1419b5370(packet);
        }
        return 1;
    } else if (_stricmp("OnCompareItem", szMethod) == 0) {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0) {
            int nItemId = data.FUN_1422b8b10();
            int nCount = data.FUN_1422b8b10();
            int nRank = data.FUN_1422b8b10();
            int nLevel = data.FUN_1422b8b10();
            int nEnchant = FUN_1419b5280(nItemId, nLevel);
            int nPeriod = data.FUN_1422b8b10();
            int g = data.FUN_1422b8a10();
            int h = data.FUN_1422b8a10();
            int i = data.FUN_1422b8a10();
            CCCompareItemPacket packet;
            packet.a = nItemId;
            packet.b = nCount;
            packet.c = nRank;
            packet.e = nLevel;
            packet.f = nEnchant;
            packet.d = nPeriod;
            packet.g = g;
            packet.h = h;
            packet.i = i;
            FUN_1419b53d0(packet);
        }
    } else if (_stricmp("OnRepeatItem", szMethod) == 0) {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0) {
            int nItemId = data.FUN_1422b8b10();
            int nCount = data.FUN_1422b8b10();
            int nRank = data.FUN_1422b8b10();
            int nLevel = data.FUN_1422b8b10();
            int nEnchant = FUN_1419b5280(nItemId, nLevel);
            int nPeriod = data.FUN_1422b8b10();
            int g = data.FUN_1422b8a10();
            int h = data.FUN_1422b8a10();
            int i = data.FUN_1422b8a10();
            int nRepeat = data.FUN_1422b8b10();
            CCCompareItemPacket packet;
            packet.a = nItemId;
            packet.b = nCount;
            packet.c = nRank;
            packet.e = nLevel;
            packet.f = nEnchant;
            packet.d = nPeriod;
            packet.g = g;
            packet.h = h;
            packet.i = i;
            packet.compareValue = nRepeat;
            FUN_1419b54a0(packet);
        }
    } else if (_stricmp("OnSearchItem", szMethod) == 0) {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0) {
            FUN_1419b5730("", data.FUN_1422b8f40());
        }
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1419b4130, UIItemCreateDialog, vfunc_28, 2224, 0x6825D924);

// The item tooltip of a list row.
// @0x1419b4a00
void UIItemCreateDialog::vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
    UIObject::vfunc_49(pRetVal, pArgs);
    if (pArgs->FUN_1422b9360() != 2)
        return;
    int nItemId = pArgs->FUN_1422b8b10();
    if (nItemId == 0 || FUN_14053f870(nItemId) == 0)
        return;
    int nRank = pArgs->FUN_1422b8b10();
    if (!FUN_14053ff30(nItemId, nRank))
        nRank = FUN_14053feb0(nItemId);
    MS2Ptr<CItem> item(new CItem);
    if (item == 0)
        return;
    if (item->FUN_14052b130(nItemId, nRank, 0) == 0)
        return;
    item->FUN_14052b420(0);
    ASTooltip tooltip(WorldService::GetInstance()->FUN_141bd0cc0(), 0x20, 2);
    if (tooltip.FUN_1409e0d40(item))
        *pRetVal = tooltip.FUN_1422bb870();
}
MS2_REPLACE_METHOD(0x1419b4a00, UIItemCreateDialog, vfunc_49, 603, 0xA49C1F61);

// Collect the items of the item table (once) and their function names.
// MS2-FUNCTIONAL: item table walk: temporaries and loop shape differ
// @0x1419b4c70
void UIItemCreateDialog::FUN_1419b4c70()
{
    if (m_items.IsEmpty()) {
        m_items.RemoveAll();
        std::vector<unsigned> ids;
        CItemDataTable::GetInstance()->LoadItemNameIds(ids);
        for (size_t i = 0; i < ids.size(); ++i) {
            MS2Ptr<CItemData> item = FUN_14053f870(ids[i]);
            if (item == 0)
                continue;
            m_items.Add(item);
            if (item->function.name.GetLength() > 0)
                m_functions.insert(item->function.name);
        }
    }
}
MS2_REPLACE_METHOD(0x1419b4c70, UIItemCreateDialog, FUN_1419b4c70, 336, 0x9B91A89C);

// "m_clearInven": empty the inventory (the "ClearInven" GM command).
// @0x1419b4dd0
void UIItemCreateDialog::FUN_1419b4dd0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_30 == 0)
        return;
    CUserCommandCli::SendCommand(CStringW(L"ClearInven"));
}
MS2_REPLACE_METHOD(0x1419b4dd0, UIItemCreateDialog, FUN_1419b4dd0, 90, 0x17D725EF);

// The context menu click: "openDropInfo" opens the drop info of the selected box item.
// MS2-FUNCTIONAL: context menu arguments: temporary order differs
// @0x1419b4e30
void UIItemCreateDialog::FUN_1419b4e30(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_30 == 0 || m_spContextMenu == 0)
        return;
    ASListEvent evt(params);
    Scaleform::GFx::Value target = evt.FUN_1422e2780();
    ASObj row(target, 2);
    if (row.FUN_1422ba9a0())
        return;
    CStringW strFunc = row.FUN_1422bb2b0("func");
    if (strFunc.IsEmpty())
        return;
    int nItemId = FUN_1419b5080();
    if (nItemId == 0)
        return;
    if (strFunc.CompareNoCase(L"openDropInfo") == 0) {
        MS2Ptr<CItemData> item = FUN_14053f870(nItemId);
        if ((CItemData*)item) {
            int nBox = item->function.FUN_14054a460();
            if (nBox) {
                UIItemDropInfoDialog* pDialog = Unk_IcGetDialog<UIItemDropInfoDialog>(0x4f74);
                if (pDialog) {
                    pDialog->FUN_140c3b7d0(nItemId, nBox);
                    CUIService::GetInstance()->FUN_141adc530((eUIClassID)0x4f74);
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1419b4e30, UIItemCreateDialog, FUN_1419b4e30, 584, 0x6CAD080F);

// The item id of the selected row: the label starts with "[<id>]".
// MS2-FUNCTIONAL: list selection temporaries differ
// @0x1419b5080
int UIItemCreateDialog::FUN_1419b5080()
{
    MS2Ptr<Unk_IcList> list = FUN_140c02900("m_items");
    if (list == 0)
        return 0;
    CStringW strLabel = list->FUN_1422dd520();
    if (strLabel.IsEmpty())
        return 0;
    return FUN_140718200(FUN_14083f330(strLabel, L'[', L']'));
}
MS2_REPLACE_METHOD(0x1419b5080, UIItemCreateDialog, FUN_1419b5080, 274, 0xAE5E507B);

// @0x1419b51a0
int UIItemCreateDialog::FUN_1419b51a0()
{
    MS2Ptr<Unk_IcCombo> combo = FUN_140c28560("m_itemGrade");
    if (combo == 0)
        return 1;
    int nRank = 1;
    combo->FUN_1419b9990("itemRank", nRank);
    return nRank;
}
MS2_REPLACE_METHOD(0x1419b51a0, UIItemCreateDialog, FUN_1419b51a0, 206, 0xF74AB5D1);

// The enchant level of a created item: the level above 15, capped by the item's limit.
// MS2-FUNCTIONAL: enchant clamp branch layout differs
// @0x1419b5280
unsigned UIItemCreateDialog::FUN_1419b5280(int nItemId, unsigned nLevel)
{
    if (nLevel < 0x10)
        return 0;
    MS2Ptr<CItemData> item = FUN_14053f870(nItemId);
    if (item == 0)
        return 0;
    unsigned nMax = item->FUN_14053e9e0();
    if (nMax == 0)
        return 0;
    if (nLevel - 0xf < nMax)
        nMax = nLevel - 0xf;
    return nMax;
}
MS2_REPLACE_METHOD(0x1419b5280, UIItemCreateDialog, FUN_1419b5280, 226, 0x663C0A39);

// @0x1419b5370
void UIItemCreateDialog::FUN_1419b5370(CCCreateItemPacket& packet)
{
    COutPacket out(0x15, 0);
    packet.vfunc_0(out);
    FUN_140710590(out);
}
MS2_REPLACE_METHOD(0x1419b5370, UIItemCreateDialog, FUN_1419b5370, 88, 0xE0A3735C);

// MS2-FUNCTIONAL: packet field reads ordered differently
// @0x1419b53d0
void UIItemCreateDialog::FUN_1419b53d0(CCCompareItemPacket& packet)
{
    if ((CItemData*)FUN_14053f870(packet.a)) {
        packet.b = 1;
        COutPacket out(0x8f, 0);
        packet.vfunc_0(out);
        FUN_140710590(out);
    }
}
MS2_REPLACE_METHOD(0x1419b53d0, UIItemCreateDialog, FUN_1419b53d0, 194, 0xA5E307F0);

// MS2-FUNCTIONAL: packet field reads ordered differently
// @0x1419b54a0
void UIItemCreateDialog::FUN_1419b54a0(CCCompareItemPacket& packet)
{
    if ((CItemData*)FUN_14053f870(packet.a)) {
        packet.b = 1;
        COutPacket out(0x9a, 0);
        packet.vfunc_0(out);
        FUN_140710590(out);
    }
}
MS2_REPLACE_METHOD(0x1419b54a0, UIItemCreateDialog, FUN_1419b54a0, 186, 0x285F60FD);

// The picked item changed: fill the rank combo and reset the period.
// MS2-FUNCTIONAL: temporaries ordered differently
// @0x1419b5560
void UIItemCreateDialog::FUN_1419b5560(int nItemId, int nRank)
{
    MS2Ptr<Unk_IcCombo> combo = FUN_140c28560("m_itemGrade");
    if ((Unk_IcCombo*)combo)
        FUN_1418fc840(combo, nItemId, nRank);
    MS2Ptr<CItemData> item = FUN_14053f870(nItemId);
    if ((CItemData*)item) {
        MS2Ptr<Unk_IcInput> input = FUN_140e35bd0("m_periodInput");
        if ((Unk_IcInput*)input) {
            input->FUN_1422e0ab0(L"0");
            input->FUN_1422c1fe0(1);
        }
    }
}
MS2_REPLACE_METHOD(0x1419b5560, UIItemCreateDialog, FUN_1419b5560, 447, 0x9D254153);

// Fill the item list: the items of a group (no search text) or the items matching the search text (words joined by
// '&' must all match, words joined by '|' any of them; the label, the id and the function name are searched).
// MS2-FUNCTIONAL: big filter loop: register allocation / temporaries differ
// @0x1419b5730
void UIItemCreateDialog::FUN_1419b5730(const CString& strGroup, const CStringW& strSearch)
{
    PC* pPC = (PC*)WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPC == 0)
        return;
    MS2Ptr<Unk_IcList> list = FUN_140c02900("m_items");
    if (list == 0)
        return;
    MS2Ptr<Unk_IcCheck> checkJob = FUN_140e52670("m_checkJob");
    if (checkJob == 0)
        return;
    MS2Ptr<Unk_IcCheck> checkGender = FUN_140e52670("m_checkGender");
    if (checkGender == 0)
        return;
    bool bJob = checkJob->FUN_1422ce0e0();
    bool bGender = checkGender->FUN_1422ce0e0();
    list->FUN_1422dd1d0();
    list->FUN_1422dcca0(-1);
    CStringW strFind(strSearch);
    for (size_t i = 0; i < m_items.GetCount(); ++i) {
        MS2Ptr<CItemData> item = m_items[i];
        if (item == 0)
            continue;
        if (bJob && !item->limit.FUN_140545da0(pPC->FUN_141654700()))
            continue;
        if (bGender && !item->FUN_14053c940(pPC->FUN_141658e60()))
            continue;
        int nId = item->FUN_14053c510();
        CStringW strId = FUN_1407196b0(nId);
        int nLevel = item->limit.levelLimit;
        CStringW strType;
        if (item->FUN_14053ce80())
            strType = L"BEAUTY";
        else if (item->FUN_14053d880())
            strType = L"COIN";
        else if (item->FUN_14053e130())
            strType = L"CASH";
        else if (item->FUN_14053cf90())
            strType = L"SKIN";
        else if (item->FUN_14053cbc0())
            strType = L"EQUIP";
        else
            strType = L"GAME";
        CStringW strLabel = StringFormat(L"[{0:08d}] [{1}] [Lv.{2}] {3}", (unsigned)nId, strType, (unsigned)nLevel,
                                         CStringTable::GetInstance()->FUN_141811980(1, nId));
        ASObj row(2);
        row.FUN_1407cbb20("label", strLabel);
        row.FUN_1409c0d20("itemId", nId);
        FUN_140841420(strLabel);
        FUN_140841420(strFind);
        strLabel.Remove(L' ');
        strFind.Remove(L' ');
        if (strFind.IsEmpty()) {
            if (strGroup == "RHLH") {
                if (item->FUN_14053d460())
                    list->FUN_1422dd230(row);
            } else if (strGroup == "CLPA") {
                if (item->FUN_14053d2b0())
                    list->FUN_1422dd230(row);
            } else if (strGroup == "CONSUME") {
                if (item->FUN_14053c5c0() == 2 || item->FUN_14053c5c0() == 0x18)
                    list->FUN_1422dd230(row);
            } else if (strGroup == "ETC") {
                if (item->FUN_14053c5c0() == 4)
                    list->FUN_1422dd230(row);
            } else if (strGroup == "MISSION") {
                if (item->FUN_14053c5c0() == 3)
                    list->FUN_1422dd230(row);
            } else if (strGroup == "SKILL") {
                if (item->FUN_14053cb40())
                    list->FUN_1422dd230(row);
            } else if (strGroup == "INSTALL") {
                if (item->FUN_14053cb80())
                    list->FUN_1422dd230(row);
            } else {
                if (item->FUN_14053eba0()->FUN_14054b3d0() < 2) {
                    int nGroup = FUN_1405451c0(strGroup);
                    if (item->FUN_14053eba0()->FUN_14054b450(nGroup))
                        list->FUN_1422dd230(row);
                }
            }
        } else {
            CStringW strFunc = item->function.name;
            if (!strFunc.IsEmpty())
                FUN_140841420(strFunc);
            ATL::CAtlArray<CStringW> tokens;
            FUN_14025a680(strFind, tokens, L"&");
            bool bAnd = tokens.GetCount() >= 2;
            if (!bAnd)
                FUN_14025a680(strFind, tokens, L"|");
            bool bMatch = bAnd;
            for (size_t t = 0; t < tokens.GetCount(); ++t) {
                if (tokens[t].IsEmpty())
                    continue;
                bool bFound = strLabel.Find(tokens[t]) != -1 || strId.Find(tokens[t]) != -1 || strFunc.Find(tokens[t]) != -1;
                if (!bFound && bAnd)
                    bMatch = false;
                if (bFound && !bAnd)
                    bMatch = true;
            }
            if (bMatch)
                list->FUN_1422dd230(row);
        }
    }
    list->FUN_1422dcca0(0);
    list->vfunc_24(true);
}
MS2_REPLACE_METHOD(0x1419b5730, UIItemCreateDialog, FUN_1419b5730, 3090, 0xA1CFB757);

// The context menu of the item list (only without the packed file system: "openDropInfo").
// MS2-FUNCTIONAL: menu building temporaries differ
// @0x1419b6350
void UIItemCreateDialog::FUN_1419b6350()
{
    m_spContextMenu = FUN_140c02900("m_contextMenu");
    if (!(Unk_IcList*)m_spContextMenu)
        return;
    bool bPacked = FUN_140166420()->FUN_140398190();
    m_spContextMenu->vfunc_3(!bPacked);
    if (!bPacked) {
        ATL::CAtlArray<std::pair<CStringW, CStringW> > menu;
        menu.Add(std::pair<CStringW, CStringW>(L"openDropInfo", L"openDropInfo"));
        for (size_t i = 0; i < menu.GetCount(); ++i) {
            if (menu[i].first.IsEmpty())
                continue;
            ASObj row(2);
            row.FUN_1407cbb20("label", menu[i].first);
            row.FUN_1407cbb20("func", menu[i].second);
            m_spContextMenu->FUN_1422dd230(row);
        }
        int nRows = m_spContextMenu->FUN_1422dd150();
        m_spContextMenu->FUN_1422c79e0(0x78, nRows * 0x1a);
        m_spContextMenu->vfunc_24(true);
        m_spContextMenu->FUN_1422de0e0(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIItemCreateDialog::FUN_1419b4e30), 0);
    } else {
        m_spContextMenu = 0;
    }
}
MS2_REPLACE_METHOD(0x1419b6350, UIItemCreateDialog, FUN_1419b6350, 1078, 0x57B2A9BC);

// Fill the function list with the item function names.
// MS2-FUNCTIONAL: set iteration shape differs
// @0x1419b6790
void UIItemCreateDialog::FUN_1419b6790()
{
    MS2Ptr<Unk_IcList> list = FUN_140c02900("m_function");
    if ((Unk_IcList*)list) {
        list->FUN_1422dd1d0();
        for (std::set<CStringW>::iterator it = m_functions.begin(); it != m_functions.end(); ++it)
            list->FUN_1422dd310(*it);
        list->vfunc_24(true);
    }
}
MS2_REPLACE_METHOD(0x1419b6790, UIItemCreateDialog, FUN_1419b6790, 320, 0x45D2CE89);

// ---- ItemOptionDebug ----

// @0x1419b68e0
ItemOptionDebug::ItemOptionDebug()
    : m_nItemId(0), m_nRank(0), m_options(10)
{
}

// @0x1419b6940
float ItemOptionDebug::FUN_1419b6940(int nGroup, int nStat)
{
    float fMin = 0;
    POSITION pos = m_options.GetHeadPosition();
    while (pos) {
        MS2Ptr<CItemOption> option = m_options.GetNext(pos);
        if (option == 0)
            continue;
        Unk_EnchantPtr<BaseOption> value = option->FUN_1405cb760(nGroup, nStat);
        if (value == 0)
            continue;
        float f = value->FUN_140266e10();
        if (fMin > f || fMin == 0)
            fMin = f;
    }
    return fMin;
}
MS2_REPLACE_METHOD(0x1419b6940, ItemOptionDebug, FUN_1419b6940, 320, 0x14B1D644);

// @0x1419b6a90
float ItemOptionDebug::FUN_1419b6a90(int nGroup, int nStat)
{
    float fMax = 0;
    POSITION pos = m_options.GetHeadPosition();
    while (pos) {
        MS2Ptr<CItemOption> option = m_options.GetNext(pos);
        if (option == 0)
            continue;
        Unk_EnchantPtr<BaseOption> value = option->FUN_1405cb760(nGroup, nStat);
        if (value == 0)
            continue;
        float f = value->FUN_140266e10();
        if (fMax < f || fMax == 0)
            fMax = f;
    }
    return fMax;
}
MS2_REPLACE_METHOD(0x1419b6a90, ItemOptionDebug, FUN_1419b6a90, 320, 0x3CE6722C);

// @0x1419b6be0
void ItemOptionDebug::FUN_1419b6be0(int nGroup, int nStat, Unk_IcRateCounts& counts)
{
    POSITION pos = m_options.GetHeadPosition();
    while (pos) {
        MS2Ptr<CItemOption> option = m_options.GetNext(pos);
        if (option == 0)
            continue;
        Unk_EnchantPtr<BaseOption> value = option->FUN_1405cb760(nGroup, nStat);
        if (value == 0)
            continue;
        float fKey = value->FUN_140266e10();
        int n = 0;
        counts.Lookup(fKey, n);
        n++;
        counts.SetAt(fKey, n);
    }
}
MS2_REPLACE_METHOD(0x1419b6be0, ItemOptionDebug, FUN_1419b6be0, 337, 0x67CFDA31);

// @0x1419b6d40
__int64 ItemOptionDebug::FUN_1419b6d40(int nGroup, int nStat)
{
    __int64 nMin = 0;
    POSITION pos = m_options.GetHeadPosition();
    while (pos) {
        MS2Ptr<CItemOption> option = m_options.GetNext(pos);
        if (option == 0)
            continue;
        Unk_EnchantPtr<BaseOption> value = option->FUN_1405cb760(nGroup, nStat);
        if (value == 0)
            continue;
        __int64 n = value->FUN_140266e30();
        if (nMin > n || nMin == 0)
            nMin = n;
    }
    return nMin;
}
MS2_REPLACE_METHOD(0x1419b6d40, ItemOptionDebug, FUN_1419b6d40, 310, 0x7D620EF9);

// @0x1419b6e80
__int64 ItemOptionDebug::FUN_1419b6e80(int nGroup, int nStat)
{
    __int64 nMax = 0;
    POSITION pos = m_options.GetHeadPosition();
    while (pos) {
        MS2Ptr<CItemOption> option = m_options.GetNext(pos);
        if (option == 0)
            continue;
        Unk_EnchantPtr<BaseOption> value = option->FUN_1405cb760(nGroup, nStat);
        if (value == 0)
            continue;
        __int64 n = value->FUN_140266e30();
        if (nMax < n || nMax == 0)
            nMax = n;
    }
    return nMax;
}
MS2_REPLACE_METHOD(0x1419b6e80, ItemOptionDebug, FUN_1419b6e80, 310, 0x35E99D93);

// @0x1419b6fc0
void ItemOptionDebug::FUN_1419b6fc0(int nGroup, int nStat, Unk_IcValueCounts& counts)
{
    POSITION pos = m_options.GetHeadPosition();
    while (pos) {
        MS2Ptr<CItemOption> option = m_options.GetNext(pos);
        if (option == 0)
            continue;
        Unk_EnchantPtr<BaseOption> value = option->FUN_1405cb760(nGroup, nStat);
        if (value == 0)
            continue;
        __int64 nKey = value->FUN_140266e30();
        int n = 0;
        counts.Lookup(nKey, n);
        n++;
        counts.SetAt(nKey, n);
    }
}
MS2_REPLACE_METHOD(0x1419b6fc0, ItemOptionDebug, FUN_1419b6fc0, 336, 0x41AA412B);

// @0x1419b7120
float ItemOptionDebug::FUN_1419b7120(int nGroup, unsigned nSpecial)
{
    float fMin = 0;
    POSITION pos = m_options.GetHeadPosition();
    while (pos) {
        MS2Ptr<CItemOption> option = m_options.GetNext(pos);
        if (option == 0)
            continue;
        Unk_EnchantPtr<BaseOption> value = option->FUN_1405cb800(nGroup, nSpecial);
        if (value == 0)
            continue;
        float f = value->FUN_140266e10();
        if (fMin > f || fMin == 0)
            fMin = f;
    }
    return fMin;
}
MS2_REPLACE_METHOD(0x1419b7120, ItemOptionDebug, FUN_1419b7120, 320, 0x391A1A06);

// @0x1419b7270
float ItemOptionDebug::FUN_1419b7270(int nGroup, unsigned nSpecial)
{
    float fMax = 0;
    POSITION pos = m_options.GetHeadPosition();
    while (pos) {
        MS2Ptr<CItemOption> option = m_options.GetNext(pos);
        if (option == 0)
            continue;
        Unk_EnchantPtr<BaseOption> value = option->FUN_1405cb800(nGroup, nSpecial);
        if (value == 0)
            continue;
        float f = value->FUN_140266e10();
        if (fMax < f || fMax == 0)
            fMax = f;
    }
    return fMax;
}
MS2_REPLACE_METHOD(0x1419b7270, ItemOptionDebug, FUN_1419b7270, 320, 0xB0BFC139);

// @0x1419b73c0
void ItemOptionDebug::FUN_1419b73c0(int nGroup, unsigned nSpecial, Unk_IcRateCounts& counts)
{
    POSITION pos = m_options.GetHeadPosition();
    while (pos) {
        MS2Ptr<CItemOption> option = m_options.GetNext(pos);
        if (option == 0)
            continue;
        Unk_EnchantPtr<BaseOption> value = option->FUN_1405cb800(nGroup, nSpecial);
        if (value == 0)
            continue;
        float fKey = value->FUN_140266e10();
        int n = 0;
        counts.Lookup(fKey, n);
        n++;
        counts.SetAt(fKey, n);
    }
}
MS2_REPLACE_METHOD(0x1419b73c0, ItemOptionDebug, FUN_1419b73c0, 337, 0xCFCBE6A2);

// @0x1419b7520
float ItemOptionDebug::FUN_1419b7520(int nGroup, unsigned nSpecial)
{
    float fMin = 0;
    POSITION pos = m_options.GetHeadPosition();
    while (pos) {
        MS2Ptr<CItemOption> option = m_options.GetNext(pos);
        if (option == 0)
            continue;
        Unk_EnchantPtr<BaseOption> value = option->FUN_1405cb800(nGroup, nSpecial);
        if (value == 0)
            continue;
        float f = (float)value->FUN_140266e30();
        if (fMin > f || fMin == 0)
            fMin = f;
    }
    return fMin;
}
MS2_REPLACE_METHOD(0x1419b7520, ItemOptionDebug, FUN_1419b7520, 324, 0x1F550F66);

// @0x1419b7670
float ItemOptionDebug::FUN_1419b7670(int nGroup, unsigned nSpecial)
{
    float fMax = 0;
    POSITION pos = m_options.GetHeadPosition();
    while (pos) {
        MS2Ptr<CItemOption> option = m_options.GetNext(pos);
        if (option == 0)
            continue;
        Unk_EnchantPtr<BaseOption> value = option->FUN_1405cb800(nGroup, nSpecial);
        if (value == 0)
            continue;
        float f = (float)value->FUN_140266e30();
        if (fMax < f || fMax == 0)
            fMax = f;
    }
    return fMax;
}
MS2_REPLACE_METHOD(0x1419b7670, ItemOptionDebug, FUN_1419b7670, 324, 0x8CB4B52A);

// @0x1419b77c0
void ItemOptionDebug::FUN_1419b77c0(int nGroup, unsigned nSpecial, Unk_IcRateCounts& counts)
{
    POSITION pos = m_options.GetHeadPosition();
    while (pos) {
        MS2Ptr<CItemOption> option = m_options.GetNext(pos);
        if (option == 0)
            continue;
        Unk_EnchantPtr<BaseOption> value = option->FUN_1405cb800(nGroup, nSpecial);
        if (value == 0)
            continue;
        float fKey = (float)value->FUN_140266e30();
        int n = 0;
        counts.Lookup(fKey, n);
        n++;
        counts.SetAt(fKey, n);
    }
}
MS2_REPLACE_METHOD(0x1419b77c0, ItemOptionDebug, FUN_1419b77c0, 341, 0xF5086F46);

// @0x1419b7920
int ItemOptionDebug::FUN_1419b7920(int nGroup, int nStat)
{
    float fMin = FUN_1419b6940(nGroup, nStat);
    float fMax = FUN_1419b6a90(nGroup, nStat);
    if (fMin > 0)
        return 1;
    if (fMax > 0)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x1419b7920, ItemOptionDebug, FUN_1419b7920, 119, 0x9C50E6E4);

// @0x1419b79a0
int ItemOptionDebug::FUN_1419b79a0(int nGroup, int nStat)
{
    __int64 nMin = FUN_1419b6d40(nGroup, nStat);
    __int64 nMax = FUN_1419b6e80(nGroup, nStat);
    if (nMin > 0)
        return 1;
    if (nMax > 0)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x1419b79a0, ItemOptionDebug, FUN_1419b79a0, 103, 0x97CF2668);

// @0x1419b7a10
int ItemOptionDebug::FUN_1419b7a10(int nGroup, unsigned nSpecial)
{
    float fMin = FUN_1419b7120(nGroup, nSpecial);
    float fMax = FUN_1419b7270(nGroup, nSpecial);
    if (fMin > 0)
        return 1;
    if (fMax > 0)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x1419b7a10, ItemOptionDebug, FUN_1419b7a10, 119, 0xAD3F06E7);

// @0x1419b7a90
int ItemOptionDebug::FUN_1419b7a90(int nGroup, unsigned nSpecial)
{
    __int64 nMin = (__int64)FUN_1419b7520(nGroup, nSpecial);
    __int64 nMax = (__int64)FUN_1419b7670(nGroup, nSpecial);
    if (nMin > 0)
        return 1;
    if (nMax > 0)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x1419b7a90, ItemOptionDebug, FUN_1419b7a90, 113, 0xAA8D7CF5);

// <rate name="<stat>" minimum maximum><output option count/>..</rate>
// @0x1419b7b10
TiXmlElement* ItemOptionDebug::FUN_1419b7b10(int nGroup, int nStat)
{
    float fMinimum = FUN_1419b6940(nGroup, nStat);
    float fMaximum = FUN_1419b6a90(nGroup, nStat);
    TiXmlElement* pRate = new TiXmlElement("rate");
    FUN_140874050(pRate, "name", FUN_14016a600(FUN_14082f000(nStat), 0));
    FUN_140873e30(pRate, "minimum", fMinimum);
    FUN_140873e30(pRate, "maximum", fMaximum);
    Unk_IcRateCounts counts(10);
    FUN_1419b6be0(nGroup, nStat, counts);
    if (!counts.IsEmpty()) {
        for (POSITION pos = counts.GetHeadPosition(); pos; counts.GetNext(pos)) {
            float fKey = counts.GetKeyAt(pos);
            int nCount = counts.GetValueAt(pos);
            TiXmlElement* pOutput = new TiXmlElement("output");
            FUN_140873e30(pOutput, "option", fKey);
            FUN_140873ce0(pOutput, "count", nCount);
            FUN_14086e090(pRate, pOutput);
        }
    }
    return pRate;
}
MS2_REPLACE_METHOD(0x1419b7b10, ItemOptionDebug, FUN_1419b7b10, 737, 0x51695B5A);

// <value name="<stat>" minimum maximum><output option count/>..</value>
// MS2-FUNCTIONAL: XML builder: local layout differs
// @0x1419b7e00
TiXmlElement* ItemOptionDebug::FUN_1419b7e00(int nGroup, int nStat)
{
    int nMinimum = (int)FUN_1419b6d40(nGroup, nStat);
    int nMaximum = (int)FUN_1419b6e80(nGroup, nStat);
    TiXmlElement* pValue = new TiXmlElement("value");
    FUN_140874050(pValue, "name", FUN_14016a600(FUN_14082f000(nStat), 0));
    FUN_140873ce0(pValue, "minimum", nMinimum);
    FUN_140873ce0(pValue, "maximum", nMaximum);
    Unk_IcValueCounts counts(10);
    FUN_1419b6fc0(nGroup, nStat, counts);
    if (!counts.IsEmpty()) {
        for (POSITION pos = counts.GetHeadPosition(); pos; counts.GetNext(pos)) {
            __int64 nKey = counts.GetKeyAt(pos);
            int nCount = counts.GetValueAt(pos);
            TiXmlElement* pOutput = new TiXmlElement("output");
            FUN_140873ce0(pOutput, "option", (int)nKey);
            FUN_140873ce0(pOutput, "count", nCount);
            FUN_14086e090(pValue, pOutput);
        }
    }
    return pValue;
}
MS2_REPLACE_METHOD(0x1419b7e00, ItemOptionDebug, FUN_1419b7e00, 726, 0x1DBE3E74);

// @0x1419b80e0
TiXmlElement* ItemOptionDebug::FUN_1419b80e0(int nGroup, unsigned nSpecial)
{
    float fMinimum = FUN_1419b7120(nGroup, nSpecial);
    float fMaximum = FUN_1419b7270(nGroup, nSpecial);
    TiXmlElement* pRate = new TiXmlElement("rate");
    FUN_140874050(pRate, "name", FUN_14016a600(FUN_140630e10(nSpecial), 0));
    FUN_140873e30(pRate, "minimum", fMinimum);
    FUN_140873e30(pRate, "maximum", fMaximum);
    Unk_IcRateCounts counts(10);
    FUN_1419b73c0(nGroup, nSpecial, counts);
    if (!counts.IsEmpty()) {
        for (POSITION pos = counts.GetHeadPosition(); pos; counts.GetNext(pos)) {
            float fKey = counts.GetKeyAt(pos);
            int nCount = counts.GetValueAt(pos);
            TiXmlElement* pOutput = new TiXmlElement("output");
            FUN_140873e30(pOutput, "option", fKey);
            FUN_140873ce0(pOutput, "count", nCount);
            FUN_14086e090(pRate, pOutput);
        }
    }
    return pRate;
}
MS2_REPLACE_METHOD(0x1419b80e0, ItemOptionDebug, FUN_1419b80e0, 737, 0x232FA530);

// MS2-FUNCTIONAL: XML builder: local layout differs
// @0x1419b83d0
TiXmlElement* ItemOptionDebug::FUN_1419b83d0(int nGroup, unsigned nSpecial)
{
    int nMinimum = (int)FUN_1419b7520(nGroup, nSpecial);
    int nMaximum = (int)FUN_1419b7670(nGroup, nSpecial);
    TiXmlElement* pValue = new TiXmlElement("value");
    FUN_140874050(pValue, "name", FUN_14016a600(FUN_140630e10(nSpecial), 0));
    FUN_140873ce0(pValue, "minimum", nMinimum);
    FUN_140873ce0(pValue, "maximum", nMaximum);
    Unk_IcRateCounts counts(10);
    FUN_1419b77c0(nGroup, nSpecial, counts);
    if (!counts.IsEmpty()) {
        for (POSITION pos = counts.GetHeadPosition(); pos; counts.GetNext(pos)) {
            float fKey = counts.GetKeyAt(pos);
            int nCount = counts.GetValueAt(pos);
            TiXmlElement* pOutput = new TiXmlElement("output");
            FUN_140873e30(pOutput, "option", fKey);
            FUN_140873ce0(pOutput, "count", nCount);
            FUN_14086e090(pValue, pOutput);
        }
    }
    return pValue;
}
MS2_REPLACE_METHOD(0x1419b83d0, ItemOptionDebug, FUN_1419b83d0, 741, 0x8572E694);

// ---- Unk_ItemOptionSimulator ----

// @0x1419b86c0
Unk_ItemOptionSimulator::Unk_ItemOptionSimulator()
    : m_mapItems(10)
{
    m_strFile = "itemOptionRepeat.xml";
}

// MS2-FUNCTIONAL: document setup temporaries differ
// @0x1419b8730
void Unk_ItemOptionSimulator::FUN_1419b8730()
{
    FUN_1412751b0(L"Item Simulate Start", 0x14);
    FUN_14086ddc0(&m_doc);
    if (FUN_14081b310(&m_doc) == 0)
        FUN_14086e090(&m_doc, new TiXmlElement("ms2"));
    void* pRoot = FUN_14081b310(&m_doc);
}
MS2_REPLACE_METHOD(0x1419b8730, Unk_ItemOptionSimulator, FUN_1419b8730, 218, 0x43485A38);

// Write the collected rolls: <ms2><item id name rank><constant|static|random><stat>..</stat><special>..</special>..
// MS2-FUNCTIONAL: big XML dump: local layout differs
// @0x1419b8810
void Unk_ItemOptionSimulator::FUN_1419b8810()
{
    FUN_1412751b0(L"Item Simulate End", 0x14);
    void* pRoot = FUN_14081b310(&m_doc);
    if (pRoot == 0)
        return;
    CString strGroups[4] = {"constant", "static", "random", "title"};
    POSITION pos = m_mapItems.GetHeadPosition();
    while (pos) {
        MS2Ptr<ItemOptionDebug> debug = m_mapItems.GetValueAt(pos);
        m_mapItems.GetNext(pos);
        if (debug == 0)
            continue;
        TiXmlElement* pItem = new TiXmlElement("item");
        FUN_140873ce0(pItem, "id", debug->m_nItemId);
        FUN_140874050(pItem, "name", FUN_14016a600(CStringTable::GetInstance()->FUN_141811980(1, debug->m_nItemId), 0));
        FUN_140874050(pItem, "rank", FUN_14016a600(CStringTable::GetInstance()->FUN_141813150(debug->m_nRank), 0));
        for (int nGroup = 0; nGroup < 3; ++nGroup) {
            TiXmlElement* pGroup = new TiXmlElement(strGroups[nGroup]);
            TiXmlElement* pStat = new TiXmlElement("stat");
            TiXmlElement* pSpecial = new TiXmlElement("special");
            for (int nStat = 0; nStat < 0x23; ++nStat) {
                if (debug->FUN_1419b7920(nGroup, nStat))
                    FUN_14086e090(pStat, debug->FUN_1419b7b10(nGroup, nStat));
                if (debug->FUN_1419b79a0(nGroup, nStat))
                    FUN_14086e090(pStat, debug->FUN_1419b7e00(nGroup, nStat));
            }
            for (unsigned nSpecial = 1; nSpecial < 0xcf; ++nSpecial) {
                if (debug->FUN_1419b7a10(nGroup, nSpecial))
                    FUN_14086e090(pSpecial, debug->FUN_1419b80e0(nGroup, nSpecial));
                if (debug->FUN_1419b7a90(nGroup, nSpecial))
                    FUN_14086e090(pSpecial, debug->FUN_1419b83d0(nGroup, nSpecial));
            }
            FUN_14086e090(pGroup, pStat);
            FUN_14086e090(pGroup, pSpecial);
            FUN_14086e090(pItem, pGroup);
        }
        FUN_14086e090(pRoot, pItem);
    }
    CString strDir;
    strDir.Format("%s%s", (const char*)FUN_14016a5c0(CommonResource::GetInstance()->m_strResourcePath, 0), "../Debug/");
    if (!efd::File::DirectoryExists(strDir))
        _mkdir(strDir);
    FUN_1408710c0(&m_doc, FUN_140cc2a00(CString("../Debug/"), m_strFile));
}
MS2_REPLACE_METHOD(0x1419b8810, Unk_ItemOptionSimulator, FUN_1419b8810, 2061, 0x9B8A55DF);

// @0x1419b9030
void Unk_ItemOptionSimulator::FUN_1419b9030(int nItemId, int nRank, MS2Ptr<CItemOption> spOption)
{
    FUN_1412751b0(StringFormat(L"Item Simulate ItemName[{0}]", CStringTable::GetInstance()->FUN_141811980(1, nItemId)), 0x14);
    MS2Ptr<ItemOptionDebug> debug = FUN_1419b91f0(nItemId, nRank);
    if (debug == 0) {
        debug.AssignRaw(new ItemOptionDebug);
        debug->m_nItemId = nItemId;
        debug->m_nRank = nRank;
        m_mapItems.Insert(nItemId, debug);
    }
    if (debug.get())
        debug->m_options.AddTail(spOption);
}
MS2_REPLACE_METHOD(0x1419b9030, Unk_ItemOptionSimulator, FUN_1419b9030, 440, 0x5EA07D29);

// MS2-FUNCTIONAL: MS2Ptr copy / dtor sequence in the multimap walk differs
// @0x1419b91f0
MS2Ptr<ItemOptionDebug> Unk_ItemOptionSimulator::FUN_1419b91f0(int nItemId, int nRank)
{
    POSITION pos = m_mapItems.FindFirstWithKey(nItemId);
    while (pos) {
        MS2Ptr<ItemOptionDebug> debug = m_mapItems.GetNextValueWithKey(pos, nItemId);
        if (!debug)
            continue;
        if (debug->m_nRank == nRank)
            return debug;
    }
    return MS2Ptr<ItemOptionDebug>(0);
}
MS2_REPLACE_METHOD(0x1419b91f0, Unk_ItemOptionSimulator, FUN_1419b91f0, 258, 0x4430BD33);

// ---- inline COMDATs ----

// MS2-FUNCTIONAL: branch order of the AS value read differs
// @0x1419b9900
void Unk_IcDataProvider::FUN_1419b9900(int nIndex, const CString& strName, int& nOut)
{
    ASObj row = FUN_1422df140(nIndex);
    if (!row.FUN_1422ba9a0())
        row.FUN_1422bae10(strName, nOut);
}

// MS2-FUNCTIONAL: branch order of the AS value read differs
// @0x1419b9990
void Unk_IcCombo::FUN_1419b9990(const CString& strName, int& nOut)
{
    int nSelected = FUN_1422df6c0();
    if (nSelected < 0)
        return;
    MS2Ptr<Unk_IcDataProvider> provider = FUN_1422df770();
    if (provider == 0)
        return;
    if ((unsigned)nSelected < provider->FUN_1422bc5d0())
        provider->FUN_1419b9900(nSelected, strName, nOut);
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cbed80-0x142cbeec0 .text$yd
