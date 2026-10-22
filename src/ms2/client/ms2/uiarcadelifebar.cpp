// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIArcadeLifeBar (class name "ArcadeLifeBar", UI type
// 0x4efc, 0x190 bytes) is the arcade minigame's life counter. The game pushes the init / life / max-life values
// (packet modes 5 and 6, or directly through FUN_140ef5320 / FUN_140ef5370) and the dialog forwards them to the swf
// ("init" once the movie has loaded, "setlife" while it is open).
// MS2-UNIT: ?\uiarcadelifebar.cpp
// MS2-RANGE: 0x140ef4f10-0x140ef5640 .text$mn
// MS2-PIN: ??_GUIArcadeLifeBar@@UEAAPEAXI@Z 0x140ef54d0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiarcadelifebar.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uiarcadelifebar.h"

#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// @0x140ef4f10
UIArcadeLifeBar::UIArcadeLifeBar() : m_nInit(0), m_nLife(0), m_nMaxLife(0)
{
    m_pos.x = 0;
    m_pos.y = 0;
    FUN_141924170(1);
    FUN_141925e70(1, 1);
}

// @0x140ef4ff0
UIArcadeLifeBar::~UIArcadeLifeBar()
{
}

// @0x140ef5030
CString UIArcadeLifeBar::GetTypeName()
{
    return "ArcadeLifeBar";
}
MS2_REPLACE_METHOD(0x140EF5030, UIArcadeLifeBar, GetTypeName, 61, 0xDCF7423F);

// @0x140ef5080
void UIArcadeLifeBar::vfunc_43()
{
    UIDialog::vfunc_43();
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (spEntity.get() != 0)
        spEntity->vfunc_2(2, (int)m_pos.x, (int)(m_pos.y - 120.0f));
}

// @0x140ef5160
void UIArcadeLifeBar::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (m_nInit > 0)
    {
        m_30.operator->()->Invoke("init", m_nInit);
        m_nInit = 0;
    }
    FUN_140ef5430();
}
MS2_REPLACE_METHOD(0x140EF5160, UIArcadeLifeBar, OnLoadComplete, 122, 0x803E7BC9);

// @0x140ef51e0
void UIArcadeLifeBar::FUN_140ef51e0(int nMode, CInPacket& packet)
{
    if (nMode == 5)
    {
        m_nInit = packet.vfunc_o8_3();
        m_nLife = packet.vfunc_o8_3();
        m_nMaxLife = packet.vfunc_o8_3();
        if (FUN_141924630() == 0)
            FUN_141924680();
        else
            FUN_140ef5430();
    }
    else if (nMode == 6)
    {
        m_nLife = packet.vfunc_o8_3();
        m_nMaxLife = packet.vfunc_o8_3();
        FUN_140ef5430();
    }
}
MS2_REPLACE_METHOD(0x140EF51E0, UIArcadeLifeBar, FUN_140ef51e0, 314, 0x2F30AEE1);

// @0x140ef5320
void UIArcadeLifeBar::FUN_140ef5320(int nLife, int nMaxLife)
{
    m_nLife = nLife;
    m_nMaxLife = nMaxLife;
    FUN_140ef5430();
}
MS2_REPLACE_METHOD(0x140EF5320, UIArcadeLifeBar, FUN_140ef5320, 63, 0x72ACF90C);

// @0x140ef5370
void UIArcadeLifeBar::FUN_140ef5370(int nInit, int nLife, int nMaxLife)
{
    m_nInit = nInit;
    m_nLife = nLife;
    m_nMaxLife = nMaxLife;
    if (FUN_141924630() == 0)
        FUN_141924680();
    else
        FUN_140ef5430();
}
MS2_REPLACE_METHOD(0x140EF5370, UIArcadeLifeBar, FUN_140ef5370, 109, 0xC40BB8C8);

// @0x140ef53f0
void UIArcadeLifeBar::FUN_140ef53f0(int nX, int nY)
{
    m_pos.x = (float)nX;
    m_pos.y = (float)nY;
}
MS2_REPLACE_METHOD(0x140EF53F0, UIArcadeLifeBar, FUN_140ef53f0, 53, 0x22091A77);

// Send the life values to the swf once it is up, then refresh the movie root (vfunc_43).
// @0x140ef5430
void UIArcadeLifeBar::FUN_140ef5430()
{
    if (m_30 == 0)
        return;
    if (m_nMaxLife == 0)
        return;
    m_30.operator->()->FUN_1409ba0d0("setlife", m_nLife, m_nMaxLife);
    vfunc_43();
}
MS2_REPLACE_METHOD(0x140EF5430, UIArcadeLifeBar, FUN_140ef5430, 151, 0xECD683BC);

// @0x140ef5510
int UIArcadeLifeBar::vfunc_48()
{
    return 0x4efc;
}

// @0x140ef5520
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
