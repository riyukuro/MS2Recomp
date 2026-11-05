// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Header name assumed.
#pragma once
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"   // MS2Ptr
#include <utility>
class ASButton;
class ASTextInput;
class CUgcUploadCtrl;
class CUgcViewerBlueprintImage;
class CUploadFile;
class Unk_BpItem;
class CItem;
class CMsgBoxData;
enum Unk_BpCurrency { Unk_BpCurrency_Default = 1 };
class UIItemBlueprintCreateDialog : public UIDialog {
public:
    UIItemBlueprintCreateDialog();
    virtual ~UIItemBlueprintCreateDialog();
    virtual CString GetTypeName();
    virtual void OnLoadComplete();
    virtual void vfunc_26();
    virtual void vfunc_72();
    virtual int vfunc_48() { return 0x4f7b; }
    void FUN_140c36b40(Unk_BpItem*);
    void OpenForItem(__int64);
    void FUN_140c370a0(const int&, MS2Ptr<CUploadFile>);
    void FUN_140c37360(MS2Ptr<CUploadFile>, const int&);
    void UpdateCreateButtonEnabled();
    void OnAddIconClick(const Scaleform::GFx::FunctionHandler::Params&);
    void OnAddImageClick(const Scaleform::GFx::FunctionHandler::Params&);
    void FUN_140c37700(const Scaleform::GFx::FunctionHandler::Params&);
    void OnNameInputChanged(const Scaleform::GFx::FunctionHandler::Params&);
    bool FUN_140c37d50(int, const CMsgBoxData&);
    bool FUN_140c37f90(int, const CMsgBoxData&);
    CStringW GetTrimmedName();
    void FUN_140c38150();
    void FUN_140c381b0(MS2Ptr<CUploadFile>);
    void FUN_140c38240();
    void FUN_140c38400();
private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<ASButton> m_addIcon, m_addImage, m_create;
    MS2Ptr<ASTextInput> m_input;
    int m_type;
    MS2Ptr<CUgcUploadCtrl> m_upload;
    MS2Ptr<CItem> m_item;
    MS2Ptr<CUploadFile> m_icon, m_image;
    std::pair<Unk_BpCurrency, __int64> m_fee;
    __int64 m_itemId;
    int m_ready, m_dirty;
};
MS2_CHECK_SIZE(UIItemBlueprintCreateDialog, 0x220);
MS2_CHECK_OFFSET(UIItemBlueprintCreateDialog, m_addIcon, 0x178);
MS2_CHECK_OFFSET(UIItemBlueprintCreateDialog, m_type, 0x1b8);
MS2_CHECK_OFFSET(UIItemBlueprintCreateDialog, m_upload, 0x1c0);
MS2_CHECK_OFFSET(UIItemBlueprintCreateDialog, m_item, 0x1d0);
MS2_CHECK_OFFSET(UIItemBlueprintCreateDialog, m_fee, 0x200);
MS2_CHECK_OFFSET(UIItemBlueprintCreateDialog, m_itemId, 0x210);
