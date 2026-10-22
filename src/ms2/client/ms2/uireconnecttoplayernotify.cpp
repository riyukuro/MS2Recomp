// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See uireconnecttoplayernotify.h.
// MS2-UNIT: ?\uireconnecttoplayernotify.cpp
// MS2-RANGE: 0x140e7fd50-0x140e80220 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uireconnecttoplayernotify.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uireconnecttoplayernotify.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/client/ms2/reconnectionmanagercli.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The reconnection manager singleton (the global is typed Unk_SingletonObj* in the symbol table).
class Unk_SingletonObj;
extern Unk_SingletonObj* DAT_143ab8aa0;
CReconnectionManagerCli* FUN_140e800e0();

// @0x140e7fd50
UIReconnectTopLayerNotify::UIReconnectTopLayerNotify()
{
    m_2c = 0x1a;
    m_70 = 1;
    m_74 = 5;
}

// @0x140e7fdc0
UIReconnectTopLayerNotify::~UIReconnectTopLayerNotify()
{
}

// @0x140e7fe00
CString UIReconnectTopLayerNotify::GetTypeName() { return "ReconnectTopLayerNotify"; }

// @0x140e7fe50
void UIReconnectTopLayerNotify::vfunc_2() { UIHeadUpDisplay::vfunc_2(); }

// @0x140e7fe70
void UIReconnectTopLayerNotify::vfunc_3() { UIHeadUpDisplay::vfunc_3(); }

// @0x140e7fe90
void UIReconnectTopLayerNotify::OnLoadComplete()
{
    UIObject::OnLoadComplete();
    FUN_140e80030();
}

// @0x140e7fec0
void UIReconnectTopLayerNotify::vfunc_43()
{
    MS2Ptr<ASGameEntity> pEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (pEntity.get())
        pEntity->vfunc_2(0, 0, -25);
}

// @0x140e7ff60
void UIReconnectTopLayerNotify::vfunc_52(int nRetry, int nMax)
{
    m_70 = nRetry;
    m_74 = nMax;
    FUN_140e80030();
}

// @0x140e7ffa0
int UIReconnectTopLayerNotify::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISwfEntity::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp("onCancel", szMethod) == 0)
    {
        vfunc_3();
        if (FUN_140e800e0() != 0)
            FUN_140e800e0()->FUN_140aad8f0();
        return 1;
    }
    return 0;
}

// @0x140e80030
void UIReconnectTopLayerNotify::FUN_140e80030()
{
    if (m_30.get() != 0)
        m_30->FUN_1409ba0d0("setRetryCount", m_70, m_74);
}

// @0x140e800e0
CReconnectionManagerCli* FUN_140e800e0()
{
    return (CReconnectionManagerCli*)DAT_143ab8aa0;
}

// The CRT's memmove_s (static inline in corecrt_memcpy_s.h) sits in this unit's range; referencing it instantiates it.
void Unk_ReconnectNotifyMoveAnchor(void* pDst, size_t nDst, void* pSrc, size_t nSrc)
{
    memmove_s(pDst, nDst, pSrc, nSrc);
}
