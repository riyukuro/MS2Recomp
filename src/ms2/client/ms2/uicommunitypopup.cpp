// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Community text ticker.
// Recovery incomplete after the first pass: OnLoadComplete and template COMDATs remain.
// MS2-UNIT: client\ms2\uicommunitypopup.cpp
// MS2-RANGE: 0x140be99c0-0x140bebfb0 .text$mn
// MS2-RANGE: 0x1400cb070-0x1400cb1e0 .text$di
// MS2-RANGE: 0x142ca1e40-0x142ca1ed0 .text$yd
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uicommunitypopup.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uicommunitypopup.h"
#include "ms2/placeholder/gfxexception.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cmainsystem.h"
#include "ms2/client/ms2/uiupperhuddialog.h"
#include "ms2/client/ms2/uiservice.h"
// This unit includes the shared header statics in a different order.
#include "ms2/placeholder/unk_1402a9d70.h"
static CString s_skill("skill");
static CString s_stun("stun");
static Unk_1402a9d70 s_condition(17,0.75f,0.25f,2.25f,10);
static CString s_sortNames[] = {"None","Buy","Like","PriceLow","PriceHigh","Create","EnumEnd"};

class ASGameEntity : public ASDisplayObject {
public: virtual void vfunc_2(int,int,int);
};
class CMainSystem;
__int64 GetServerTime();
class UIWebBrowserPopup : public UIWebBrowserBase { };
class Unk_PopupUIManager { public: };
// @0x140beafe0
UIWebBrowserPopup* GetWebBrowserPopup(int id) {
    if (reinterpret_cast<Unk_PopupUIManager*>(TSingleton<CUIService>::GetInstance())) {
        MS2Ptr<UIObject> obj = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)id);
        if (obj.get())
            return dynamic_cast<UIWebBrowserPopup*>((UIObject*)obj);
    }
    return NULL;
}
#define MS2_ASCRIPT_INL_ASSERT(line, expression) \
    (void)((!!(expression)) || (_wassert(_CRT_WIDE(#expression), L"e:\\build\\kr\\22_04\\ms2code\\client\\gfxlib\\ascript.inl", (unsigned)(line)), 0))
// @0x140beaf20
template <> MS2Ptr<ASTextField> AScript::FUN_140beaf20<ASTextField>(const CString& name, MS2Ptr<ASTextField>& outChild) {
    MS2_ASCRIPT_INL_ASSERT(0xd5, outChild == NULL);
    outChild = FUN_1409b4620(name);
    return outChild;
}

// @0x140be99c0
UICommunityPopup::UICommunityPopup() : m_pending(false),m_speed(50.0f),m_x(0.0f),m_y(0),m_width(0),m_queue(10) {
    m_time = GetServerTime();
    FUN_1422dc3b0(1);
}
// @0x140be9af0
UICommunityPopup::~UICommunityPopup() {}
// @0x140be9b90
CString UICommunityPopup::GetTypeName() { return "CommunityPopup"; }
MS2_REPLACE_METHOD(0x140BE9B90, UICommunityPopup, GetTypeName, 61, 0x2E1C0B56);
// @0x140be9be0
void UICommunityPopup::OnLoadComplete() {
    UIObject::OnLoadComplete();
    do {
        m_30->FUN_140bc71c0<ASMovieClip>("m_popupText",m_movie);
        if (m_movie == NULL)
            throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}","SwfLoadError",MS2_THIS_FILE,MS2_LINE(43),__FUNCTION__));
    } while(0);
    if (m_movie->FUN_140beaf20<ASTextField>("textField",m_field) == NULL)
        throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}","SwfLoadError",MS2_THIS_FILE,MS2_LINE(46),__FUNCTION__));
    m_y = (int)m_field->GetY();
    m_movie->FUN_1422c2a70(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this,&UICommunityPopup::FUN_140bea960),(void*)0);
    FUN_140bea730();
    if (m_text.IsEmpty()) vfunc_3();
}
MS2_REPLACE_METHOD(0x140BE9BE0, UICommunityPopup, OnLoadComplete, 1124, 0xEAE20402);
// @0x140bea090
void UICommunityPopup::vfunc_26() {
    UIObject::vfunc_26();
    m_field = NULL;
    m_movie = NULL;
}
MS2_REPLACE_METHOD(0x140BEA090, UICommunityPopup, vfunc_26, 64, 0x5AA2226E);
// @0x140bea0e0
void UICommunityPopup::vfunc_15() {
    if (GetServerTime() - m_time > 120) {
        FUN_140bea6b0();
        m_time = GetServerTime();
        if (m_queue.GetCount() == 0) vfunc_3();
        else {
            Unk_PopupPtr<PopupText> text(m_queue.GetHead());
            if (text.get()) {
                CStringW message(text->text);
                CString url(text->url);
                m_queue.RemoveHead();
                FUN_140bea390(message,url);
            }
        }
    } else FUN_140bea540();
}
MS2_REPLACE_METHOD(0x140BEA0E0, UICommunityPopup, vfunc_15, 443, 0x6DDBFB80);
// @0x140bea2b0
void UICommunityPopup::vfunc_43() {
    MS2Ptr<ASGameEntity> entity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (entity.get()) entity->vfunc_2(3,0,-200);
}
MS2_REPLACE_METHOD(0x140BEA2B0, UICommunityPopup, vfunc_43, 157, 0x264968BA);
// @0x140bea390
void UICommunityPopup::FUN_140bea390(CStringW text, CString url) {
    if (!FUN_141986d30()) vfunc_2();
    if (m_text.IsEmpty()) {
        CStringW padding(L"       ");
#if defined(__clang__)
        // clang-cl inlines the dllimport Concatenate and needs CSimpleStringT::CopyChars, which no mfc140 import provides.
        m_text = text;
        m_text += padding;
#else
        m_text = text + padding;
#endif
        m_url = url;
        m_pending = true;
        m_time = GetServerTime();
        if (m_width == 0) FUN_140bea730();
    } else {
        Unk_PopupPtr<PopupText> pending(Unk_SocketNew(0));
        pending->text = text;
        pending->url = url;
        m_queue.AddTail(pending);
    }
}
MS2_REPLACE_METHOD(0x140BEA390, UICommunityPopup, FUN_140bea390, 423, 0xD6A3F5FA);
// @0x140bea540
void UICommunityPopup::FUN_140bea540() {
    if (m_field == NULL) return;
    if (m_width == 0) return;
    float delta = TSingleton<CMainSystem>::GetInstance()->GetLastGameTimeDelta();
    m_x -= m_speed * delta;
    int x = (int)m_x;
    if (!m_pending) {
        if (x < -m_width) { m_x = 0; x = 0; }
        m_field->SetPositionInt(x,m_y);
    } else {
        if (x > -m_field->GetWidthCeil()) m_field->SetPositionInt(x,m_y);
        else FUN_140bea730();
    }
}
MS2_REPLACE_METHOD(0x140BEA540, UICommunityPopup, FUN_140bea540, 348, 0xF50D1509);
// @0x140bea6b0
void UICommunityPopup::FUN_140bea6b0() {
    m_text = L"";
    m_url = L"";
    m_x = 0;
    m_width = 0;
    m_pending = false;
}
MS2_REPLACE_METHOD(0x140BEA6B0, UICommunityPopup, FUN_140bea6b0, 111, 0x4B92458B);
// @0x140bea730
void UICommunityPopup::FUN_140bea730() {
    if (m_field == NULL) return;
    if (m_text.IsEmpty()) {
        m_width = 0;
        m_movie->vfunc_3(0);
    } else {
        m_movie->vfunc_3(1);
        m_field->SetTextHTMLW(m_text);
        m_width = (int)m_field->GetTextWidth();
        int totalWidth = m_width + 275;
        int repeat = totalWidth / m_width + 1;
        CStringW text;
        for (int i=0; i<repeat; ++i) text += m_text;
        m_field->SetTextHTMLW(text);
        m_field->SetWidthInt((int)(m_field->GetTextWidth() + 20.0));
        m_x = 275.0f;
        m_pending = false;
        FUN_140bea540();
    }
}
MS2_REPLACE_METHOD(0x140BEA730, UICommunityPopup, FUN_140bea730, 549, 0xBC351929);
// @0x140bea960
void UICommunityPopup::FUN_140bea960(const Scaleform::GFx::FunctionHandler::Params&) {
    UIWebBrowserPopup* browser = GetWebBrowserPopup(0x4f40);
    if (browser) { browser->Navigate(m_url,1); m_time = 0; }
}
MS2_REPLACE_METHOD(0x140BEA960, UICommunityPopup, FUN_140bea960, 85, 0x10AE4226);
MS2_EMIT_CRT_MEMMOVE_S();
