// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIArcadeTextEffectDialog (class name
// "ArcadeTextEffectDialog", UI type 0x4f82, 0x180 bytes) is the arcade minigame's centre text. A game packet
// (mode 8) carries a flag and a combo count; the dialog stores the localised "s_arcade_text_effect_consecutive"
// text of that count in m_strText and asks the swf to show it ("showText"), or clears it. Its movie root is
// centred on the screen (half of its width, 210 down).
// MS2-UNIT: ?\uiarcadetexteffectdialog.cpp
// MS2-RANGE: 0x140ba7d90-0x140ba8280 .text$mn
// MS2-PIN: ??_GUIArcadeTextEffectDialog@@UEAAPEAXI@Z 0x140ba8230
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiarcadetexteffectdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uiarcadetexteffectdialog.h"

#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The localisation helper of commonfiles (a string key plus one int argument): looks the key up and formats it.
CStringW FUN_14062b4f0(CStringW strKey, const int* pnArg);

// @0x140ba7d90
UIArcadeTextEffectDialog::UIArcadeTextEffectDialog()
{
    FUN_141924170(0);
    FUN_141925e70(1, 1);
}

// @0x140ba7e20
UIArcadeTextEffectDialog::~UIArcadeTextEffectDialog()
{
}

// @0x140ba7e80
CString UIArcadeTextEffectDialog::GetTypeName()
{
    return "ArcadeTextEffectDialog";
}

// The movie root is centred horizontally and sits 210 below the middle.
// @0x140ba7ed0
void UIArcadeTextEffectDialog::vfunc_43()
{
    UIDialog::vfunc_43();
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (spEntity.get() != 0)
    {
        int nY = 0xd2;
        spEntity->FUN_1422bffe0((int)(spEntity->FUN_1422c1500() * 0.5f), nY);
    }
}

// Mode 8: the combo. With the flag clear the text is the localised combo count (a count of 0 clears it) - the swf
// only shows the text while the dialog is still open, otherwise the close animation is played.
// @0x140ba7fe0
void UIArcadeTextEffectDialog::FUN_140ba7fe0(int nMode, CInPacket& packet)
{
    if (nMode == 8)
    {
        m_strText = L"";
        int nFlag = packet.vfunc_o8_1();
        if (nFlag == 0)
        {
            int nCount = packet.vfunc_o8_3();
            if (nCount <= 0)
                m_strText = L"";
            else
                m_strText = FUN_14062b4f0(CStringW(L"s_arcade_text_effect_consecutive"), &nCount);
        }
        if (UIDialog::FUN_141924630())
            FUN_140ba8160();
        else
            UIDialog::FUN_141924680();
    }
}

// An OnLoadComplete or a packet left a text behind: hand it to the swf and clear it.
// @0x140ba8160
void UIArcadeTextEffectDialog::FUN_140ba8160()
{
    if (m_30 == 0)
        return;
    m_30.operator->()->Invoke("showText", m_strText);
    m_strText = L"";
}

// @0x140ba7fa0
void UIArcadeTextEffectDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (m_strText.GetLength() > 0)
        FUN_140ba8160();
}

// @0x140ba8270
int UIArcadeTextEffectDialog::vfunc_48()
{
    return 0x4f82;
}
