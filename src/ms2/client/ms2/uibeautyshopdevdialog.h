// uibeautyshopdevdialog.h - the beauty shop developer page (RTTI UIBeautyShopDevDialog, UI id 0x4e79, 0x2c8 bytes): a
// debug twin of the beauty shop (UIBeautyShopDialog) that lists every hair / face / makeup / skin / emotion / cap item the
// player's gender can wear, previews it on the character through a Customize controller and saves or resets the
// change. NOT an original header (the unit was ?\uibeautyshopdevdialog.cpp, now queue unit_14191c7d0). Member and
// helper names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <vector>
#include "ms2/placeholder/asobj.h"
#include "ms2/client/ms2/uibeautyshopstyledialog.h"     // IItemCustomizeEventListener, Customize, Unk_BSCamera

class CItemData;
class CEquipItem;
class CMsgBoxData;
class NotifyObject;
class ASDropdownMenu;
struct Unk_EquipItemData;

class UIBeautyShopDevDialog : public UIDialog, public UIItemEventListener, public IItemCustomizeEventListener
{
public:
    UIBeautyShopDevDialog();                            // 0x14191c7d0
    virtual ~UIBeautyShopDevDialog();                   // 0x14191c980
    virtual CString GetTypeName();
    virtual int vfunc_13();
    virtual void vfunc_15();
    virtual void OnLoadComplete();
    virtual void vfunc_26();
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
    virtual void vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs);
    // @0x141922e30
    virtual int vfunc_48() { return 0x4e79; }
    virtual int vfunc_65();
    virtual void vfunc_67();
    virtual int vfunc_74(int a1, void* p2, void* p3);
    virtual void vfunc_79(void* pPacket);
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);
    virtual void vfunc_84(int nTab, int bKeepList, const CStringW& strSearch);  // 84 (new) build the item list of a tab
    virtual void vfunc_85(int nPalette, int nType);     // 85 (new) apply a detail colour
    virtual void vfunc_86(int nPalette, int nColor);    // 86 (new) apply a palette colour

    // UIItemEventListener overrides
    virtual void vfunc_21(void* p);
    virtual void vfunc_24(void* p);
    virtual void vfunc_25(void* p);
    // IItemCustomizeEventListener overrides
    virtual int vfunc_1(void* p);
    virtual int vfunc_2(void* p, float fValue, int nIndex);
    virtual int vfunc_3(void* p, float fValue);
    virtual int vfunc_4(void* p, void* q);
    virtual int vfunc_5(void* p, void* q);

    bool FUN_14191e9e0(int nResult, const CMsgBoxData& data);   // the close confirmation
    void FUN_14191f620(int nItemId);                    // preview an item ("buildCurrentItem")
    void FUN_14191f8e0(unsigned nIndex);                // play the nIndex-th listed emotion
    void FUN_14191f970();                               // hide the cap
    void FUN_14191f9d0();                               // show the cap
    int FUN_14191fa30();                                // restore and leave
    void FUN_14191fae0();                               // close (asks when there are unsaved changes)
    void FUN_14191fc40(int bChanged);                   // enable "m_save" / "m_reset"
    void FUN_14191fe00();                               // play the apply effect
    void FUN_14191ff70();                               // refresh the worn list and the selection
    void FUN_14191ffb0();
    int FUN_14191fff0();                                // "m_save" is enabled
    void FUN_1419200c0(int bForce);                     // "buildEquipItems"
    void FUN_1419206a0(int* pnTab, MS2Ptr<CItemData> spData);   // the tab an item belongs to (-1: none)
    void FUN_141920770();                               // clear the item lists
    void FUN_1419207c0(int nTab);                       // select the worn item of the tab
    void FUN_141920aa0(int nItemId);                    // preview an item id
    void OnClickNew();                               // "OnClickNew"
    void OnClickAdd();                               // "OnClickAdd": store the cap transform of the hat
    void OnClickDelete();                               // "OnClickDelete"
    void FUN_141921190(int nItemId);                    // enable "m_new" / "m_add" / "m_delete"
    void FUN_1419213f0(NotifyObject* pNotify);          // NotifyChangeActiveMyCodiTab
    bool FUN_141921460();                               // the previewed item has colours
    int FUN_141921500();                                // the selected colour index

private:
    MS2_LAYOUT_FRIEND;
    int m_198;                                          // +0x198 an item was changed
    int m_19c;                                          // +0x19c the page takes input (1)
    int m_1a0;                                          // +0x1a0 the current tab (-1: none; 0..6)
    int m_1a4;                                          // +0x1a4 the item id whose debug text is pending
    ATL::CAtlArray<unsigned> m_1a8[7];                  // +0x1a8 the item ids of each tab
    MS2Ptr<Customize> m_288;                            // +0x288 the customize controller
    Unk_BSCamera* m_298;                                // +0x298 the camera
    std::vector<CString> m_2a0;                         // +0x2a0 the listed emotions
    MS2Ptr<ASDropdownMenu> m_2b8;                       // +0x2b8 "m_colorIndexMenu"
};
MS2_CHECK_SIZE(UIBeautyShopDevDialog, 0x2c8);
MS2_CHECK_OFFSET(UIBeautyShopDevDialog, m_198, 0x198);
MS2_CHECK_OFFSET(UIBeautyShopDevDialog, m_1a8, 0x1a8);
MS2_CHECK_OFFSET(UIBeautyShopDevDialog, m_288, 0x288);
MS2_CHECK_OFFSET(UIBeautyShopDevDialog, m_2a0, 0x2a0);
MS2_CHECK_OFFSET(UIBeautyShopDevDialog, m_2b8, 0x2b8);
