// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uihomeresizedialog.h (name assumed: the
// .cpp's __FILE__ string is in the exe, the header's is not).
//
// UIHomeResizeDialog (UI type 0x4f7e, "HomeResizeDialog", 0x178 bytes = a plain UIDialog): the home size window. Its four
// movie buttons shrink / extend the area or the height of the player's home by one step. Each asks for the next or the
// previous step of the CMasteryInteriorTable (the ugc housing tables), shows a confirmation box with the price and, on
// "yes", sends packet 0x37 with the sub-op 0x25 (extend area) / 0x26 (shrink area) / 0x2c (extend height) / 0x2d (shrink
// height). The movie is refreshed through "buildInteriorExtension". UIUGCHousingPointDialog derives from this class.
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"

class CMsgBoxData;

class UIHomeResizeDialog : public UIDialog
{
public:
    UIHomeResizeDialog();                                       // 0x140c2bc50
    virtual ~UIHomeResizeDialog();                              //  0 0x140c2bce0 (??_G 0x140c2dbf0)
    virtual CString vfunc_1();                                  //  1 0x140c2bd20
    virtual void OnLoadComplete();                              // 22 0x140c2bd70
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140c2be50
    virtual void vfunc_43();                                    // 43 0x140c2bdb0 center the movie
    virtual int vfunc_48() { return 0x4f7e; }                   // 48 0x140c2dc30
    virtual void vfunc_84();                                    // 84 0x140c2cf50 "buildInteriorExtension"

    void FUN_140c2bf40();                                       // 0x140c2bf40 refresh the movie
    void FUN_140c2bf70();                                       // 0x140c2bf70 same body
    void FUN_140c2bfa0();                                       // 0x140c2bfa0 "OnShrinkArea"
    void FUN_140c2c2f0();                                       // 0x140c2c2f0 "OnShrinkHeight"
    void FUN_140c2c640();                                       // 0x140c2c640 "OnExtensionArea"
    void FUN_140c2cac0();                                       // 0x140c2cac0 "OnExtensionHeight"
    bool SendRequestCubeMode38(int nResult, const CMsgBoxData& data);   // 0x140c2cd90 shrink area box result
    bool SendRequestCubeMode45(int nResult, const CMsgBoxData& data);   // 0x140c2ce00 shrink height box result
    bool SendRequestCubeMode37(int nResult, const CMsgBoxData& data);   // 0x140c2ce70 extend area box result
    bool SendRequestCubeMode44(int nResult, const CMsgBoxData& data);   // 0x140c2cee0 extend height box result
};
MS2_CHECK_SIZE(UIHomeResizeDialog, 0x178);
