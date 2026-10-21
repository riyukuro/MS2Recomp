// uiugcitemeditdialog.h - UIUGCItemEditDialog (RTTI .?AVUIUGCItemEditDialog@@, 0x260 bytes, UI id 0x4e69, swf
// "UGCItemEditDialog"): the UGC item designer. The player picks a UGC design (an outfit, cube or mount template of
// Table/UGCDesign.xml), previews it on an avatar in the render view, picks a texture image from the upload folder and
// "makes" the item (pays the design price, the merat way or the meso way, then uploads the texture). The dialog can
// also re-edit an existing UGC item (m_spEditItem).
// Bases: UIDialog, UIStatusEventListener (+0x178), IUIAvatarEventListener (+0x180), UIUGCEventListener (+0x188) and
// IAvatarObjectEventListener (+0x190). ctor 0x141b3b830 (operator new 0x260 in CUIService::RegisterDialogs).
// Also declares the ItemPreviewCommon helpers that the exe links right after the dialog (a second TU in the same range:
// 0x141b48430-0x141b4a150, the .text$di copy of the header statics at 0x14011eeb0).
// Owning unit: ?\uiugcitemeditdialog.cpp. File name assumed (class name); member names are invented from use.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <NiRect.h>
#include <efd/SmartPointer.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/client/ms2/uiavatarbase.h"
#include "ms2/client/ms2/uiskillpreviewdialog.h"       // IUIAvatarEventListener
#include "ms2/client/ms2/shoptabinfo.h"                // Unk_ShopTabArray
#include "ms2/placeholder/uistatuseventlistener.h"
#include "ms2/placeholder/uiugceventlistener.h"

class ASObj;
class ASData;
class CItem;
class CItemData;
class CUGCDesignData;
class CMsgBoxData;
class NotifyObject;
class UIRenderView;
class CUgcItemProxy;
class CItemUgc;
class UGCItemSlot;

class UIUGCItemEditDialog : public UIDialog,
                            public UIStatusEventListener,
                            public IUIAvatarEventListener,
                            public UIUGCEventListener,
                            public IAvatarObjectEventListener
{
public:
    UIUGCItemEditDialog();                                      // 0x141b3b830
    virtual ~UIUGCItemEditDialog();                             //  0 0x141b3bad0 (??_G 0x141b473c0)
    virtual CString vfunc_1();                                  //  1 0x141b3bc50 "UGCItemEditDialog"
    virtual void vfunc_16();                                    // 16 0x141b3cca0 unload the render target
    virtual bool vfunc_17();                                    // 17 0x141b3ccd0 load the render target
    virtual void OnLoadComplete();                              // 22 0x141b3bd60
    virtual void vfunc_25(void* p1, TPtr<Unk_UISwfEntity_25> p2, void* p3, void* p4);   // 25 0x141b3cac0 mouse on the render view
    virtual void vfunc_26();                                    // 26 0x141b3d180
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141b3c3d0
    virtual int vfunc_48() { return 0x4e69; }                   // 48 0x141b47860
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);   // 49 0x141b3d370 the tooltips
    virtual int vfunc_65();                                     // 65 0x141b3ce00 Open
    virtual void vfunc_67();                                    // 67 0x141b3cea0 Close
    virtual void vfunc_72();                                    // 72 0x141b3d1b0 per frame
    virtual int vfunc_73();                                     // 73 0x141b3bca0 may open (an upload is running)
    // IUIAvatarEventListener (+0x180)
    virtual int vfunc_o178_0(void* pAvatar);                    // 0x141b3d7e0 the avatar's model was created
    virtual int vfunc_o178_1(void* pAvatar);                    // 0x141b3d890 the avatar's model finished loading
    // UIUGCEventListener (+0x188)
    virtual void vfunc_ugc_4(int nDialog);                      // 4 0x141b3d770 the upload moved to this dialog

    void FUN_141b3cd10();                                       // "loadRenderTarget"
    void FUN_141b3cd70();                                       // "unloadRenderTarget"
    void FUN_141b3da90(int nModel);                             // create the avatar of a model radio index
    void FUN_141b3e370();                                       // drop every avatar and the render view
    void FUN_141b3e410(MS2Ptr<UIAvatarBase> spAvatar, bool bChanged);   // show an avatar in the render view
    void FUN_141b3e640(MS2Ptr<UIAvatarBase> spAvatar, bool bUseItem, bool bResetCamera);   // reset the avatar's pose
    void FUN_141b3e780(MS2Ptr<UIAvatarBase> spAvatar, bool bUseItem);   // the avatar's facing angle
    void FUN_141b3e990();                                       // "setCameraPosition"
    bool FUN_141b3ea70(int* pnY, int* pnZoom);                  // the camera frame of the design's slot
    void FUN_141b3f180(MS2Ptr<UIAvatarBase> spAvatar);          // reset the render view's camera
    bool FUN_141b3f3a0(ASObj& obj, MS2Ptr<CUGCDesignData> spDesign);   // fill one design entry
    bool FUN_141b3f690(ASObj& obj, MS2Ptr<CItem> spItem);       // fill the entry of the item being re-edited
    void FUN_141b3f960(ASObj& obj, MS2Ptr<CUGCDesignData> spDesign);   // the price members of a design entry
    void FUN_141b3fb60(MS2Ptr<CItem> spItem, bool* pbModelChanged);    // set the design item
    void FUN_141b401b0(MS2Ptr<CItem> spItem);                   // set the design item (ignores the model change)
    void FUN_141b40220();                                       // drop the design and the image
    void FUN_141b40270();                                       // "restart"
    bool FUN_141b40300(__int64 nPrice, int nMeret);             // send the make request
    void FUN_141b40880(ASObj& obj);                             // the model radio buttons
    void FUN_141b40ab0(int nKind, int nImage);                  // switch the content kind and reload the images
    void FUN_141b40b00(int nPage);                              // "buildImageFiles"
    void FUN_141b40c30();                                       // "buildDesignItems"
    void FUN_141b41090(ASObj& obj);                             // the category and gender drop downs
    void FUN_141b41700(int nIndex);                             // "selectImage"
    bool FUN_141b417e0();                                       // refresh the preview of the upload
    void FUN_141b419c0();                                       // "updateSelectedImage"
    void FUN_141b41a20();                                       // "requestCapture"
    bool FUN_141b41a80(const NiRect<unsigned int>& kRect);      // save the capture, "savedCapture"
    void FUN_141b41cd0();                                       // the capture state machine (per frame)
    void FUN_141b41e80(int nModel);                             // "changeModel"
    void FUN_141b41ef0(MS2Ptr<CItemData> spData);               // the content kind of the design
    void FUN_141b41f90(MS2Ptr<CItemData> spData);               // "m_showRadioSelect"
    void FUN_141b420f0(int nKind, MS2Ptr<UIAvatarBase> spAvatar, MS2Ptr<CItem> spItem);   // attach the viewer
    void FUN_141b42800();                                       // refresh the viewer of the upload
    void FUN_141b428d0(int nKind);                              // save a screenshot of the render view
    int FUN_141b42a50(MS2Ptr<UIAvatarPC> spAvatar, int nGender);
    int FUN_141b42b20(MS2Ptr<CItemData> spData, MS2Ptr<UIAvatarBase> spAvatar);   // the model index for a design
    int FUN_141b430b0();                                        // "getMakeCount"
    CStringW FUN_141b43140();                                   // the item name input (trimmed)
    __int64 FUN_141b43240(MS2Ptr<CUGCDesignData> spDesign, int nCount);   // the price of nCount items
    int FUN_141b432f0(MS2Ptr<CItemData> spData);                // the UGC content kind of an item
    MS2Ptr<UIAvatarBase> FUN_141b433f0(int nModel);             // the avatar of a model index
    UIAvatarBase* FUN_141b43490();                              // the shown avatar
    void FUN_141b434c0(ASData& args);                           // onChangeModel
    int FUN_141b43660(int nImage);                              // select an image of the folder
    bool FUN_141b437c0(ASData& args);                           // onChangeIndexDesign
    bool FUN_141b43be0(int nImage);                              // onDoubleClickImage
    bool FUN_141b43c60(int nImage);                             // onClickMake
    void FUN_141b44910();                                       // onClickAddImage
    void FUN_141b44990();                                       // onClickInitialize
    void FUN_141b44a20();                                       // onClickNewDraw
    void FUN_141b44a60(ASData& args);                           // onStartCapture
    void FUN_141b44b30(int nPosition);                          // onImageScrollPosition
    void FUN_141b44b90(ASData& args);                           // onChangeIndexDropDownCategory
    void FUN_141b44d10(ASData& args);                           // onChangeIndexDropDownGender
    void FUN_141b44d50(NotifyObject* pNotify);                  // "NotifyGameEventChanged"
    void FUN_141b44e80(const Scaleform::GFx::FunctionHandler::Params& params);   // "setDesignDataImpl"
    void FUN_141b45020();                                       // clear the item name input
    void FUN_141b450d0(int nResult);                            // the server answered the make request
    void FUN_141b45180(MS2Ptr<CItem> spItem);                   // the made item: rename box
    void FUN_141b45770(const CUgcItemProxy* pProxy, CItemUgc* pUgc);   // the made item of a proxy (uncalled)
    bool FUN_141b45980(int nResult, const CMsgBoxData& box);
    bool FUN_141b459d0(int nResult, const CMsgBoxData& box);    // the meso price box
    bool FUN_141b45cc0(int nResult, const CMsgBoxData& box);    // the merat price box
    bool FUN_141b46070(int nResult, const CMsgBoxData& box);    // the rename box
    bool FUN_141b461b0(int nResult, const CMsgBoxData& box);    // the screenshot box (meso)
    bool FUN_141b462a0(int nResult, const CMsgBoxData& box);    // the screenshot box (merat)
    void FUN_141b463b0(MS2Ptr<CItem> spItem);                   // re-edit an item

private:
    MS2_LAYOUT_FRIEND;
    int m_nKind;                                                // +0x198 the UGC content kind (1 equip, 2 cube, 7 ridee)
    int m_nRadioMode;                                           // +0x19c 0 my model, 1 radio select, 2 none
    CString m_strSlotBindId;                                    // +0x1a0 "<name>.0", the bind id of the design slot
    MS2Ptr<CItem> m_spItem;                                     // +0x1a8 the design item
    MS2Ptr<CItem> m_spMadeItem;                                 // +0x1b8 the item the server made
    int m_nCapture;                                             // +0x1c8 0 none, 1 requested, 2 next frame
    NiRect<unsigned int> m_kCapture;                            // +0x1cc the capture rectangle
    int m_nImage;                                               // +0x1dc the selected image (-1 none)
    int m_nModel;                                               // +0x1e0 the model radio index (-1 none)
    int m_nDirty;                                               // +0x1e4 1 avatar, 2 design data, 4 equip
    bool m_bEventSale;                                          // +0x1e8
    MS2Ptr<UIAvatarBase> m_spAvatar;                            // +0x1f0 the shown avatar
    efd::SmartPointer<UIRenderView> m_spView;                   // +0x200
    ATL::CAtlArray<MS2Ptr<UIAvatarBase> > m_avatars;            // +0x208 per model index
    Unk_ShopTabArray m_tabs;                                    // +0x228 the design categories
    int m_nImagesPerPage;                                       // +0x248 "imageListCountPerPage"
    MS2Ptr<CItem> m_spEditItem;                                 // +0x250 the item being re-edited
};
MS2_CHECK_SIZE(UIUGCItemEditDialog, 0x260);
MS2_CHECK_OFFSET(UIUGCItemEditDialog, m_nKind, 0x198);
MS2_CHECK_OFFSET(UIUGCItemEditDialog, m_strSlotBindId, 0x1a0);
MS2_CHECK_OFFSET(UIUGCItemEditDialog, m_nCapture, 0x1c8);
MS2_CHECK_OFFSET(UIUGCItemEditDialog, m_kCapture, 0x1cc);
MS2_CHECK_OFFSET(UIUGCItemEditDialog, m_bEventSale, 0x1e8);
MS2_CHECK_OFFSET(UIUGCItemEditDialog, m_spAvatar, 0x1f0);
MS2_CHECK_OFFSET(UIUGCItemEditDialog, m_avatars, 0x208);
MS2_CHECK_OFFSET(UIUGCItemEditDialog, m_tabs, 0x228);
MS2_CHECK_OFFSET(UIUGCItemEditDialog, m_spEditItem, 0x250);

// ItemPreviewCommon (the second TU of the range): the avatar framing constants of the item preview dialogs and the
// item filters they share.
int FUN_141b48430(int nAvatarKind);                             // avatar kind -> preview kind (1 PC, 6, 9, 11)
float FUN_141b48480(int nPreviewKind, int nSlot);               // the facing angle of a preview kind / equip slot
float FUN_141b48500(int nPreviewKind);                          // the frame width of a preview kind
