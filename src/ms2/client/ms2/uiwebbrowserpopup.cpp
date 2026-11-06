// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIWebBrowserPopup: see uiwebbrowserpopup.h.
// MS2-UNIT: ?\uiwebbrowserpopup.cpp
// MS2-RANGE: 0x140fc1e20-0x140fc2090 .text$mn
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiwebbrowserpopup.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uiwebbrowserpopup.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/clientconstants.h"  // C3: Common::Constants::Value<int>::Get

// ---- unit-local views of exe objects ----
class Unk_WpInt { public: int m_n; char m_pad_04[0x54]; };          // one value of the client constants
class Unk_WpConsts { public:
    char m_pad_0000[0x8948];
    Unk_WpInt m_8948;
    Unk_WpInt m_89a0;
    Unk_WpInt m_89f8;
    Unk_WpInt m_8a50;
};
// C3: was FUN_1401d3200 (= TSingleton<Client::Constants>::GetInstance, GetClientConstants()); C3: the canonical return type (was Unk_WpConsts*)

// @0x140fc1e20
UIWebBrowserPopup::UIWebBrowserPopup()
{
    m_nBrowserId = 5;
}

// @0x140fc1e90
UIWebBrowserPopup::~UIWebBrowserPopup()
{
}

// @0x140fc1ee0
void UIWebBrowserPopup::OnLoadInit()
{
    UIWebBrowser::OnLoadInit();
    if ((m_30 == 0) != 0)
        return;
    {
        m_nMinWidth = *reinterpret_cast<Common::Constants::Value<int>*>(&((Unk_WpConsts*)GetClientConstants())->m_8948)->Get();
        m_nMinHeight = *reinterpret_cast<Common::Constants::Value<int>*>(&((Unk_WpConsts*)GetClientConstants())->m_89f8)->Get();
        m_nMaxWidth = *reinterpret_cast<Common::Constants::Value<int>*>(&((Unk_WpConsts*)GetClientConstants())->m_89a0)->Get();
        m_nMaxHeight = *reinterpret_cast<Common::Constants::Value<int>*>(&((Unk_WpConsts*)GetClientConstants())->m_8a50)->Get();
        m_nWidth = m_nMaxWidth;
        m_nHeight = m_nMaxHeight;
    }
}

// @0x140fc1fd0
void UIWebBrowserPopup::OnLoadComplete()
{
    UIWebBrowser::OnLoadComplete();
    if (m_30.get() != 0)
        reinterpret_cast<AScript*>(m_30.operator->())->FUN_140e262c0("changeTitle", "$s_webbrowserpopup_title2");
}

MS2_EMIT_CRT_MEMMOVE_S();
