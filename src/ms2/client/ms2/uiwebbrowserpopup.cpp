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

// ---- unit-local views of exe objects ----
class Unk_WpInt { public: int m_n; char m_pad_04[0x54]; };          // one value of the client constants
class Unk_WpConsts { public:
    char m_pad_0000[0x8948];
    Unk_WpInt m_8948;
    Unk_WpInt m_89a0;
    Unk_WpInt m_89f8;
    Unk_WpInt m_8a50;
};
class Unk_SingletonObj1* FUN_1401d3200();   // C3: the canonical return type (was Unk_WpConsts*)
int* FUN_1402056b0(Unk_WpInt* p);
bool FUN_140ba28d0(const MS2Ptr<AScript>* pAS, int n);                      // has the AS object been released
AScript* FUN_1409ee290(MS2Ptr<AScript>* p);
class Unk_WpScript { public: Scaleform::GFx::Value FUN_140e262c0(const char* szMethod, const char* szArg); };

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
    if (FUN_140ba28d0(&m_30, 0) != 0)
        return;
    {
        m_nMinWidth = *FUN_1402056b0(&((Unk_WpConsts*)FUN_1401d3200())->m_8948);
        m_nMinHeight = *FUN_1402056b0(&((Unk_WpConsts*)FUN_1401d3200())->m_89f8);
        m_nMaxWidth = *FUN_1402056b0(&((Unk_WpConsts*)FUN_1401d3200())->m_89a0);
        m_nMaxHeight = *FUN_1402056b0(&((Unk_WpConsts*)FUN_1401d3200())->m_8a50);
        m_nWidth = m_nMaxWidth;
        m_nHeight = m_nMaxHeight;
    }
}

// @0x140fc1fd0
void UIWebBrowserPopup::OnLoadComplete()
{
    UIWebBrowser::OnLoadComplete();
    if (m_30.get() != 0)
        reinterpret_cast<Unk_WpScript*>(FUN_1409ee290(&m_30))->FUN_140e262c0("changeTitle", "$s_webbrowserpopup_title2");
}

MS2_EMIT_CRT_MEMMOVE_S();
