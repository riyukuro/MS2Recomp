// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The "reconnecting" HUD notice (retry counter + cancel).
#pragma once
#include "ms2/placeholder/uiheadupdisplay.h"

class UIReconnectTopLayerNotify : public UIHeadUpDisplay {
public:
    UIReconnectTopLayerNotify();                                                        // 0x140e7fd50
    virtual ~UIReconnectTopLayerNotify();                                               // 0 0x140e7fdc0 (??_G 0x140e800a0)
    virtual CString GetTypeName();                                                          // 1 0x140e7fe00 "ReconnectTopLayerNotify"
    virtual void vfunc_2();                                                             // 2 0x140e7fe50
    virtual void vfunc_3();                                                             // 3 0x140e7fe70
    virtual void OnLoadComplete();                                                      // 22 0x140e7fe90
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140e7ffa0
    virtual void vfunc_43();                                                            // 43 0x140e7fec0
    virtual int vfunc_48() { return 0x4f78; }                                           // 48 0x140e800f0
    virtual void vfunc_52(int nRetry, int nMax);                                        // 52 0x140e7ff60 sets the retry counter

    void FUN_140e80030();                                                               // pushes "setRetryCount" to the movie

private:
    MS2_LAYOUT_FRIEND;
    int m_70;                                                                           // +0x70 retry counter (1)
    int m_74;                                                                           // +0x74 retry limit (5)
};
MS2_CHECK_SIZE(UIReconnectTopLayerNotify, 0x78);
MS2_CHECK_OFFSET(UIReconnectTopLayerNotify, m_70, 0x70);
MS2_CHECK_OFFSET(UIReconnectTopLayerNotify, m_74, 0x74);
