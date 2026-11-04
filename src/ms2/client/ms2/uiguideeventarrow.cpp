// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: client\ms2\uiguideeventarrow.cpp
// MS2-RANGE: 0x141959330-0x141960ce0 .text$mn
// MS2-RANGE: 0x140113ff0-0x1401141b0 .text$di
// MS2-RANGE: 0x142cbe500-0x142cbe5b0 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PIN: ??1?$MS2Ptr@VUnk_GuideMarker@@@@QEAA@XZ 0x141960970 ; hand: MS2Ptr dtors of identical shape are ambiguous; the minimap marker pointer is the one this unit owns
// MS2-PIN: ??C?$MS2Ptr@VUnk_GuideMarker@@@@QEBAPEAVUnk_GuideMarker@@XZ 0x141960a80 ; hand: get
// MS2-PIN: ?IsNull@?$MS2Ptr@VUnk_GuideMarker@@@@QEBA_NXZ 0x141960a10 ; hand: IsNull
// MS2-PIN: ?Reference@?$MS2Ptr@VUnk_GuideMarker@@@@CAXPEAVUnk_GuideMarker@@@Z 0x141960b10 ; hand: AddRef
// MS2-PIN: ?Release@?$MS2Ptr@VUnk_GuideMarker@@@@AEAAXXZ 0x141960b30 ; hand: Release
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VUnk_GuideMarker@@@@AEAAXPEAX@Z 0x141960b70 ; hand: ReleaseImpl
// MS2-PIN: ??__Es_guideSound@@YAXXZ 0x140113ff0 ; initpin: a header's look-alike initializer must not make these ambiguous
// MS2-PIN: ??__Es_sortNames@@YAXXZ 0x140114020
// MS2-PIN: ??__Es_skill@@YAXXZ 0x1401140e0
// MS2-PIN: ??__Es_stun@@YAXXZ 0x140114110
// MS2-PIN: ??__Es_pointer@@YAXXZ 0x140114140
// MS2-PIN: ??__Es_conditions@@YAXXZ 0x140114160
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiguideeventarrow.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uiguideeventarrow.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asbuttonbar.h"
#include "ms2/placeholder/asbutton.h"
#include "ms2/placeholder/effectquery.h"
#include "ms2/client/ms2/uimessagebox.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/creservedwordtable.h"
#include "ms2/placeholder/cgameoption.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/citem.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/client/ms2/camera.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "ms2/commonfiles/usermail.h"  // C3: CUserMail::FUN_1408e57f0 (the scene-service global)
#include "ms2/placeholder/ichromamanager.h"  // C3: ChromaSDK::GetChromaManager
#include "ms2/placeholder/intervaltimer.h"  // C3: Unk_IntervalTimer::Init, Check
#include "ms2/client/ms2/uiinventorydialog.h"  // C3: UIInventoryDialog (cast at the call)
#include "ms2/placeholder/ckeytable.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/client/ms2/uihousemark.h"
#include "ms2/client/ms2/uimessenger.h"
#include "ms2/client/ms2/uiugccubepalettedialog.h"
#include "ms2/client/ms2/uipartydialog.h"
#include "ms2/client/ms2/uiminimapentity.h"
#include "ms2/placeholder/cgamemenutable.h"  // C3: CGameMenuTable (cast at the call)
static CString s_guideSound("system_guide_tooltip");
static CString s_sortNames[] = {"None","Buy","Like","PriceLow","PriceHigh","Create","EnumEnd"};
static CString s_skill("skill");
static CString s_stun("stun");
class Unk_BuddyHandle { public: Unk_BuddyHandle(void*); private: void* m_p; };
static Unk_BuddyHandle s_pointer(NULL);
static ATL::CAtlMap<unsigned int,CString> s_conditions(17,.75f,.25f,2.25f,10);
class Unk_1403ed280 { public: void FUN_1411a6060(int); int FUN_1411a49c0(NoticeMessage*); void FUN_1411a4f40(CString,const Vector3&); };
int FUN_1412755a0();
int FUN_141276180(const CString&,const CString&);
unsigned long GetTickCountMs2();   // C3: was FUN_140869420
class Unk_1422baa20 { public: Scaleform::GFx::Value FUN_1422baa20(const char*); Scaleform::GFx::Value FUN_140acd130(const char*,CStringW); Scaleform::GFx::Value FUN_140ba26d0(const char*,unsigned int);
    Scaleform::GFx::Value FUN_140cbe3a0(const char*,const wchar_t*); Scaleform::GFx::Value FUN_1422bb3c0(); };
// @0x141959330
UIGuideEvent::UIGuideEvent() : m_sound(0),m_guide(0),m_tip(0),m_lastTip(0),m_tips(10),
    m_strings(17,.75f,.25f,2.25f,10),m_voices(17,.75f,.25f,2.25f,10),m_expiry(0),m_arrows(17,.75f,.25f,2.25f,10) { FUN_14195b970(); }
// @0x1419594f0
CString UIGuideEvent::GetTypeName() { return "GuideEvent"; }
// @0x141959540
void UIGuideEvent::OnLoadComplete() {
    UIObject::OnLoadComplete();
    FUN_14195c230("guideTutorial",m_tutorial);
    FUN_14195c230("guideSummary",m_summary);
    m_hasArrow.AssignRaw(new AScript(const_cast<Scaleform::GFx::Value&>(static_cast<const Scaleform::GFx::Value&>(((AScript*)m_30.operator->())->GetMember("hasGuideArrow"))),2));   // the Value& ctor (0x1422ba7f0)
}
// @0x1419596e0
void UIGuideEvent::vfunc_26() { UIObject::vfunc_26(); m_summary=NULL; m_tutorial=NULL; m_hasArrow=NULL; m_timer.Init(); }
// @0x141959750
void UIGuideEvent::vfunc_43() { if(m_30.get()) m_30->Invoke("alignment"); }
// @0x1419597b0
void UIGuideEvent::vfunc_15() {
    if(m_30==NULL) return;
    for(POSITION p=m_arrows.GetStartPosition(); p; m_arrows.GetNext(p)) {
        MS2Ptr<UIGuideEventArrow> arrow=m_arrows.GetValueAt(p); arrow->vfunc_1(m_30);
    }
    FUN_14195be30(); CheckSummaryExpiry();
}
// @0x1419598e0
int UIGuideEvent::vfunc_28(const char* method,const Scaleform::GFx::Value* args,unsigned int n) {
    if(UISwfEntity::vfunc_28(method,args,n)) return 1;
    if(_stricmp("onTextTipClose",method)==0) { AdvanceTextTip(0); return 1; }
    return 0;
}
// @0x141959960
void UIGuideEvent::vfunc_2() { if(FUN_1412755a0()) return; FUN_1422dbf00(0x23,0,0); }
// @0x1419599a0
void UIGuideEvent::vfunc_3() {
    if(FUN_1412755a0()) return; {
        FUN_1422dc080(); m_tip=0; m_tips.RemoveAll();
        if(m_sound) { TSingleton<CEffectService>::GetInstance()->FUN_1411a6060(m_sound); m_sound=0; }
    }
}
// @0x141959a20
int UIGuideEvent::SkipTextTip() { if(IsTextTipShowing()) { AdvanceTextTip(0); return 1; } return 0; }
// @0x14195a0c0
void UIGuideEvent::ReleaseArrow(unsigned int id) {
    MS2Ptr<UIGuideEventArrow> arrow;
    if(!m_arrows.Lookup(id,arrow)) return;
    arrow->FUN_14195dfc0();
    if(arrow->GetUseCount()==0) {
        if(m_30.get()) ((AScript*)m_30.operator->())->Invoke("removeArrow",(unsigned int)(id));
        m_arrows.RemoveKey(id);
    }
    ChromaSDK::GetChromaManager()->ResetKeys(1);
}
// @0x14195a1d0
void UIGuideEvent::FUN_14195a1d0(CStringW& input,CStringW& out,int& special) {
    CStringW start(L"[["),end(L"]]");
    int minimum=5;
    special=0;
    if(input.GetLength()<5) { out=input;input=L"";return; }
    int i=input.Find(start,0);
    if(i<0) { out=input;input=L"";return; }
    else if(i>0) { out=input.Mid(0,i);input=input.Mid(i);return; }
    i=input.Find(end,0);
    if(i<0) { out=input;input=L"";return; }
    out=input.Mid(2,i-2); input=input.Mid(i+2);special=1;
}
// @0x14195b330
void UIGuideEvent::QueueOrShowTextTip(unsigned int id,unsigned int stringid) {
    if(m_30==NULL) return;
    if(IsTextTipShowing()) {
        std::pair<unsigned int,unsigned int> tip(std::make_pair((int&)id,stringid));
        m_tips.AddTail(tip);
    } else {
        ((AScript*)m_30.operator->())->Invoke("showTextTip",GetGuideText(stringid));
        m_tip=id; FUN_141276180(s_guideSound,"");
    }
}
// @0x14195b490
void UIGuideEvent::HideTutorial(int id) {
    if(m_30==NULL) return;
    if(id && m_guide!=id) return;
    m_30->Invoke("hideTutorial");m_guide=0;ChromaSDK::GetChromaManager()->ResetKeys(1);
}
// @0x14195b540
void UIGuideEvent::HideSummary(int id) {
    if(m_30==NULL) return;
    if(id && m_guide!=id) return;
    m_30->Invoke("hideSummary");ChromaSDK::GetChromaManager()->ResetKeys(1);m_guide=0;m_expiry=0;
}
// @0x14195b600
void UIGuideEvent::AdvanceTextTip(int id) {
    if(id && m_tip!=id) return; {
        if(m_tips.GetCount()!=0) { std::pair<unsigned int,unsigned int> v=m_tips.RemoveHead(); if(m_30.get()) m_30->Invoke("removeTextTip"); QueueOrShowTextTip(v.first,v.second); }
        else { if(m_30.get()) m_30->Invoke("hideTextTip");m_tip=0; }
        ChromaSDK::GetChromaManager()->ResetKeys(1);m_lastTip=m_tip;
    }
}
// @0x14195b760
int UIGuideEvent::IsTutorialShowing() { if(m_tutorial==NULL) return false; return ((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(m_tutorial->Invoke("isShowing")))->GetBool()!=0; }
// @0x14195b810
int UIGuideEvent::IsSummaryShowing() { if(m_summary==NULL) return false; return ((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(m_summary->Invoke("isShowing")))->GetBool()!=0; }
// @0x14195b8c0
int UIGuideEvent::IsTextTipShowing() { if(m_30==NULL) return 0; return ((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(m_30->Invoke("isShowTextTip")))->GetBool(); }
// @0x14195b950
int UIGuideEvent::GetLastTip() { return m_lastTip; }
// @0x14195bfc0
void UIGuideEvent::CheckSummaryExpiry() { if(!m_expiry) return; if(GetTickCountMs2()>=m_expiry) HideSummary(m_guide); }


// ---- out-of-unit callees of the recovered (functional) part ----
typedef Scaleform::GFx::Value GfxValue;
int FUN_141274f80();
float FUN_1412762d0(const NiPoint3&);
int FUN_141389500(const CStringW&,int);                             // wide string to int
bool FUN_1401c0090(const CString&,const CString&);
void FUN_14025a680(CStringW&,ATL::CAtlArray<CStringW>&,const wchar_t*);
CString FUN_14016a600(const wchar_t*,int);
CString FUN_14071ae20(const CString&);
class Unk_XmlNode   // C3: member view for the former free stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};
bool FUN_14028f710(struct Unk_XmlElement*);   // C3: was FUN_14028f710
int XmlGetAttr(class TiXmlElement*, char const*, unsigned int&);   // C3: was FUN_140873220
int XmlGetAttr(class TiXmlElement*, char const*, CStringW&);   // C3: was FUN_140873420
int XmlGetAttr(class TiXmlElement*, char const*, CString&);   // C3: was FUN_1408733e0
class CFileSystem* GetFileSystem();   // C3: was FUN_140166420
class CLogString;
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);   // C3: was V::FUN_14015eb90
struct Unk_GuideLog { };
class CLogString* GetLogString();   // C3: was FUN_140166440
struct Unk_GpState* FUN_140a58500(class Unk_GpSettings*);   // C3: was FUN_140a58500
class Unk_SingletonObj* FUN_1401d31f0();   // C3: was FUN_1401d31f0
class GFxSceneService   // C3: member view for the former free stand-ins
{
public:
    int FUN_1422b9ea0();
    int GetSubSceneId();
};
UIMessageBox* FUN_14151f890();

// A display object seen through its accessors (the exe's inline/COMDAT members, bound by their FUN_ names).
class Unk_GuideDO : public AScript {
public:
    float FUN_1422c10a0(); float FUN_1422c1110(); float FUN_1422c1180();   // x, y, z
    MS2Ptr<ASDisplayObject> FUN_1422e32b0(int);                               // child by index
};
static Unk_1422baa20* GuideAS(const MS2Ptr<AScript>& p) { return reinterpret_cast<Unk_1422baa20*>(p.operator->()); }

// UIs of the dialogs the arrows point at.
class Unk_GuideInventory : public UISwfEntity {
public:
    int FUN_141999de0(); int FUN_141999f10();
    MS2Ptr<ASButtonBar> FUN_14199aad0();                             // tab strip
    int FUN_14199ab20(CString);                               // tab index by name
};
class Unk_GuideItem : public CItem { public: bool FUN_140525f10(); bool FUN_140525f60();};
extern Unk_Inventory g_143ab2a90;
class UIInventoryDialog;
template<class T> T* Unk_BreakDialog(int);   // C3: was Unk_GuideInventory* FUN_1405344f0 (calls cast back)
class Unk_GuideMarker : public CPtred { public: MS2Ptr<ASMovieClip> m_18; };
class Unk_GuideMinimap : public UISwfEntity { public: MS2Ptr<Unk_GuideMarker> FUN_141a3b510(MS2Ptr<CPtred>); };
class UIMinimapDialog* FUN_140c9b540(int);   // C3: was FUN_140c9b540
class Unk_GuideWorld : public WorldService { public: MS2Ptr<CPtred> FUN_141bc9be0(unsigned);};
class Unk_GuidePortal : public CPtred { public: char m_pad_18[0x134]; unsigned m_14c; };
class Unk_GuidePortalMgr { public: MS2Ptr<Unk_GuidePortal> FUN_141bc2800(int); };
class GameObject   // C3: member view for the former free stand-ins
{
public:
    int FUN_14123c580();
};
class Unk_CMISHouseMark* FUN_1410dc020();   // C3: was FUN_1410dc020
void* FUN_1413b1c60(const CString&);
class UIMessengerBrowser* FUN_140a3ab70(int);   // C3: was FUN_140a3ab70
class UIUGCCubePaletteDialog* FUN_140ef4a50(int);   // C3: was FUN_140ef4a50
class Unk_GuideSceneMgr { public: virtual void vfunc_0(); virtual CString vfunc_1(); };
class UIGameMenuDialog : public UIObject {};

// @0x14195bd90
void UIGuideEvent::PlayVoice(unsigned int stringId)
{
    CString voice = GetGuideVoice(stringId);
    if (voice.GetLength() != 0)
        TSingleton<CEffectService>::GetInstance()->FUN_1411a4f40(CString(voice), (const NiPoint3&)DAT_143b01a60);
}

// @0x14195c010
CStringW UIGuideEvent::GetGuideText(unsigned int id)
{
    CStringW text;
    if (!m_strings.Lookup(id, text))
        return CStringW(L"");
    TSingleton<CReservedWordTable>::GetInstance()->ReplaceValueWords(text);
    return text;
}

// @0x14195c0e0
CString UIGuideEvent::GetGuideVoice(unsigned int id)
{
    CString voice;
    if (!m_voices.Lookup(id, voice))
        return CString("");
    return voice;
}

// @0x14195c1a0
MS2Ptr<AScript> UIGuideEvent::FindChildScript(const CString& name)
{
    if (m_30 == NULL)
        return MS2Ptr<AScript>(0);
    return ((AScript*)GuideAS(m_30))->FUN_141311f50<AScript>(name);
}

// @0x14195c230
MS2Ptr<AScript> UIGuideEvent::FUN_14195c230(const CString& name, MS2Ptr<AScript>& out)
{
    out = FindChildScript(name);
    return out;
}

// @0x14195bc50  "name:value" of a [[...]] tag
void UIGuideEvent::ParseTagNameValue(CStringW tag, CStringW& name, CStringW& value)
{
    ATL::CAtlArray<CStringW> parts;
    FUN_14025a680(tag, parts, L":");
    if (parts.GetCount() == 2) {
        name = (const char*)FUN_14016a600(parts[0], 0);
        value = (const char*)FUN_14016a600(parts[1], 0);
    }
}

// @0x14195b970  stringGuide.xml: <ms2><key id name voiceID/>...</ms2>
void UIGuideEvent::FUN_14195b970()
{
    m_strings.RemoveAll();
    m_voices.RemoveAll();
    CString path = FUN_14071ae20("stringGuide.xml");
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, path, 0, true, false) == 0)
        return;
    void* root = ((void*)((class Unk_XmlNode*)(void*)(&doc))->FirstChild("ms2"));
    if (root == 0) {
        Unk_AchieveLog<CString>((class CLogString*)GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", path);
        return;
    }
    for (void* node = ((void*)((class Unk_XmlNode*)(void*)(root))->FirstChild("key")); node != 0; node = ((void*)((class Unk_XmlNode*)(void*)(node))->NextSibling("key"))) {
        int id = 0;
        CStringW name;
        CString voice;
        if (!FUN_14028f710((struct Unk_XmlElement*)(node)))
            continue;
        XmlGetAttr((class TiXmlElement*)(node), "id", *(unsigned int*)&static_cast<int&>(id));
        XmlGetAttr((class TiXmlElement*)(node), "name", name);
        XmlGetAttr((class TiXmlElement*)(node), "voiceID", voice);
        if (!name.IsEmpty()) {
            name.Replace(L"\\n", L"\n");
            TSingleton<CReservedWordTable>::GetInstance()->ReplaceObjectWords(name);
            m_strings.SetAt(id, name);
        }
        if (!voice.IsEmpty())
            m_voices.SetAt(id, voice);
    }
}

// @0x14195be30  the voice/sound loop is on while the arrow flag is
void UIGuideEvent::FUN_14195be30()
{
    if (m_30 == NULL)
        return;
    if (m_timer.Check(300) == 0)
        return;
    bool bPlaying = m_sound != 0;
    bool bWanted = false;
    if (((class GFxSceneService*)(void*)(((void*)CUserMail::FUN_1408e57f0())))->FUN_1422b9ea0() == 0)
        bWanted = ((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(((AScript*)m_hasArrow.operator->())->InvokeSelf()))->GetBool();
    if (bPlaying == bWanted)
        return;
    if (bPlaying) {
        TSingleton<CEffectService>::GetInstance()->FUN_1411a6060(m_sound);
        m_sound = 0;
    } else {
        NoticeMessage request;
        request.m_strName = *reinterpret_cast<CString*>((char*)((void*)FUN_1401d31f0()) + 0x2f8);
        request.m_nObject = 0;
        m_sound = TSingleton<CEffectService>::GetInstance()->FUN_1411a49c0(*(Unk_EffectTarget*)&request);
    }
}

// @0x141959a60  AddArrow: shared by id, a second add only bumps the use count
void UIGuideEvent::FUN_141959a60(MS2Ptr<UIGuideEventArrow> arrow)
{
    MS2Ptr<UIGuideEventArrow> existing;
    if (m_arrows.Lookup(arrow->m_id, existing)) {
        existing->FUN_14195dfa0();
        return;
    }
    existing = arrow;
    m_arrows.SetAt(arrow->m_id, existing);
    Vector3 pos = reinterpret_cast<const Vector3&>(DAT_143b01a60);
    int hide = 0;
    if (arrow->vfunc_2(&pos) == 0)
        hide = 1;
    ASObj info(2);
    info.FUN_1409c0d20("id", arrow->m_id);
    info.FUN_1409c0d20("align", arrow->m_align);
    info.FUN_1409c0d20("direction", arrow->m_direction);
    info.FUN_1409c4a30("x", pos.x);
    info.FUN_1409c4a30("y", pos.y);
    info.FUN_1407cb9c0("hide", hide);
    {
        CStringW text = GetGuideText(arrow->m_textId);
        int special = 0;
        CStringW part;
        FUN_14195a1d0(text, part, special);
        if (special != 0) {
            CStringW name, value;
            ParseTagNameValue(part, name, value);
            if (name == L"keyText") {
                info.FUN_1407cbb20("key", value);
                ChromaSDK::GetChromaManager()->OnKeyName(value);
            } else if (name == L"keyAction") {
                int action = FUN_141389500(value, 0);
                CStringW key = FUN_1409331f0()->GetActionKeyName(action, 0);
                info.FUN_1407cbb20("key", key);
                ChromaSDK::GetChromaManager()->OnKeySkill(action, 1);
            } else if (name == L"keyActionSub") {
                int action = FUN_141389500(value, 0);
                CStringW key = FUN_1409331f0()->GetActionKeyName(action, 1);
                info.FUN_1407cbb20("key", key);
                ChromaSDK::GetChromaManager()->OnKeySkill(action, 1);
            }
        } else {
            info.FUN_1407cbb20("text", part);
        }
    }
    if (m_30.get()) {
        if ((unsigned int)arrow->m_textId > 0) {
            PlayVoice(arrow->m_textId);
            m_30->Invoke("addTextArrow", info);
        } else {
            m_30->Invoke("addArrow", info);
        }
    }
    FUN_14195be30();
}

// Adds the [[keyText/keyAction/keyActionSub/...]] tagged parts of a guide text to the text box `box`.
// @0x14195a520
void UIGuideEvent::FUN_14195a520(unsigned int guideId, unsigned int stringId, int mode)
{
    if (m_30 == NULL)
        return;
    if (m_tutorial == NULL)
        return;
    m_tutorial->Invoke("clearContents");
    CStringW text = GetGuideText(stringId);
    while (text.GetLength() != 0) {
        int special = 0;
        CStringW part;
        FUN_14195a1d0(text, part, special);
        if (special != 0) {
            CStringW name, value;
            ParseTagNameValue(part, name, value);
            if (name == L"keyText") {
                ((AScript*)GuideAS(m_tutorial))->Invoke("addKeyButton", value);
                ChromaSDK::GetChromaManager()->OnKeyName(value);
            } else if (name == L"keyDirection") {
                m_tutorial->Invoke("addDirectionKey");
            } else if (name == L"keyAction") {
                int action = FUN_141389500(value, 0);
                CStringW key = FUN_1409331f0()->GetActionKeyName(action, 0);
                ((AScript*)GuideAS(m_tutorial))->Invoke("addKeyButton", key);
                ChromaSDK::GetChromaManager()->OnKeySkill(action, 1);
            } else if (name == L"keyActionSub") {
                int action = FUN_141389500(value, 0);
                CStringW key = FUN_1409331f0()->GetActionKeyName(action, 1);
                ((AScript*)GuideAS(m_tutorial))->Invoke("addKeyButton", key);
                ChromaSDK::GetChromaManager()->OnKeySkill(action, 1);
            }
        } else {
            ((AScript*)GuideAS(m_tutorial))->Invoke("addText", part);
        }
    }
    PlayVoice(stringId);
    if (mode != 0) {
        m_30->Invoke("showTutorial");
    } else {
        m_tutorial->Invoke("alignment");
        GuideAS(m_tutorial)->FUN_140cbe3a0("gotoAndPlayText", L"show");
    }
    m_guide = guideId;
}

// @0x14195ab40  summary window: keyAction tags become plain text for gamepad users
void UIGuideEvent::FUN_14195ab40(unsigned int guideId, unsigned int stringId, int durationMs)
{
    if (m_30 == NULL || m_summary == NULL)
        return;
    m_summary->Invoke("clearContents");
    ChromaSDK::GetChromaManager()->ResetKeys(1);
    CStringW text = GetGuideText(stringId);
    while (text.GetLength() != 0) {
        int special = 0;
        CStringW part;
        FUN_14195a1d0(text, part, special);
        if (special != 0) {
            CStringW name, value;
            ParseTagNameValue(part, name, value);
            if (name == L"keyText") {
                ((AScript*)GuideAS(m_summary))->Invoke("addKeyButton", value);
                ChromaSDK::GetChromaManager()->OnKeyName(value);
            } else if (name == L"icon") {
                ((AScript*)GuideAS(m_summary))->Invoke("addIcon", value);
            } else if (name == L"keyAction") {
                if (*((unsigned char*)FUN_140a58500((class Unk_GpSettings*)(TSingleton<CGameOption>::GetInstance()))) != 0) {
                    int action = FUN_141389500(value, 0);
                    CStringW key = FUN_1409331f0()->GetActionKeyName(action, 2);
                    ((AScript*)GuideAS(m_summary))->Invoke("addText", key);
                } else {
                    int action = FUN_141389500(value, 0);
                    CStringW key = FUN_1409331f0()->GetActionKeyName(action, 0);
                    ((AScript*)GuideAS(m_summary))->Invoke("addKeyButton", key);
                    ChromaSDK::GetChromaManager()->OnKeySkill(action, 1);
                }
            } else if (name == L"keyActionSub") {
                if (*((unsigned char*)FUN_140a58500((class Unk_GpSettings*)(TSingleton<CGameOption>::GetInstance()))) != 0) {
                    int action = FUN_141389500(value, 0);
                    CStringW key = FUN_1409331f0()->GetActionKeyName(action, 2);
                    ((AScript*)GuideAS(m_summary))->Invoke("addText", key);
                } else {
                    int action = FUN_141389500(value, 0);
                    CStringW key = FUN_1409331f0()->GetActionKeyName(action, 1);
                    ((AScript*)GuideAS(m_summary))->Invoke("addKeyButton", key);
                    ChromaSDK::GetChromaManager()->OnKeySkill(action, 1);
                }
            }
        } else {
            ((AScript*)GuideAS(m_summary))->Invoke("addText", part);
        }
    }
    m_30->Invoke("showSummary");
    PlayVoice(stringId);
    m_guide = guideId;
    m_expiry = 0;
    if ((unsigned int)durationMs > 0)
        m_expiry = GetTickCountMs2() + durationMs;
}

// ---- UIGuideEventArrow ----
// @0x14195dd10
UIGuideEventArrow::UIGuideEventArrow() : m_pos(), m_direction(0), m_align(0), m_textId(0), m_useCount(1) {}
// @0x14195dd90
void UIGuideEventArrow::vfunc_1(MS2Ptr<AScript> movie)
{
    Vector3 pos;
    if (vfunc_2(&pos) == 0) {
        ((AScript*)GuideAS(movie))->Invoke("hideArrow", (unsigned int)(m_id));
        return;
    }
    ASObj info(2);
    info.FUN_1409c0d20("id", m_id);
    info.FUN_1409c4a30("x", pos.x);
    info.FUN_1409c4a30("y", pos.y);
    movie->Invoke("updateArrow", info);
}
// @0x14195dee0
int UIGuideEventArrow::vfunc_2(void* out)
{
    if (FUN_141274f80() != 0)
        return 0;
    *(Vector3*)out = reinterpret_cast<const Vector3&>(DAT_143b01a60);
    if (TSingleton<CameraMgr>::GetInstance()->FUN_140af0700(reinterpret_cast<const efd::Point3&>(m_pos), *(NiPoint3*)out))
    {
        *reinterpret_cast<efd::Point3*>(out) *= TSingleton<CUIService>::GetInstance()->FUN_141adbe70();
        ((Vector3*)out)->y += FUN_1412762d0(reinterpret_cast<const NiPoint3&>(m_pos));
        return 1;
    }
    return 0;
}
// @0x14195dfa0
void UIGuideEventArrow::FUN_14195dfa0() { m_useCount++; }
// @0x14195dfc0
void UIGuideEventArrow::FUN_14195dfc0()
{
    if (m_useCount == 0) {
        MS2_ASSERT_AT(0x27, 0);
        return;
    }
    m_useCount--;
}
// @0x14195e020
int UIGuideEventArrow::GetUseCount() { return m_useCount; }

// ---- UIGuideEventArrowDialog ----
// @0x14195e040
UIGuideEventArrowDialog::UIGuideEventArrowDialog() : m_38(0), m_48(-1), m_kind(0), m_param(0) {}

// @0x14195e0e0
int UIGuideEventArrowDialog::vfunc_2(void* out)
{
    if (((class GFxSceneService*)(void*)(((void*)CUserMail::FUN_1408e57f0())))->GetSubSceneId() == 0x6200041)
        return 0;
    UIMessageBox* box = FUN_14151f890();
    if (box != 0 && box->FUN_1419f8270() == 0)
        return 0;
    if (FUN_141960510() == 0)
        return 0;
    switch (m_kind) {
    case 0:  if (GetTargetPosition(out) == 0) return 0; break;
    case 1:  if (FUN_14195e3f0(out) == 0) return 0; break;
    case 2: case 3: case 4: case 5:
             if (FUN_14195e6e0(out) == 0) return 0; break;
    case 6:  if (FUN_14195ead0(out) == 0) return 0; break;
    case 7: case 8:
             if (FUN_14195eee0(out) == 0) return 0; break;
    case 9:  if (GetHouseMarkPosition(out) == 0) return 0; break;
    case 10: if (GetPartyDialogPosition(out) == 0) return 0; break;
    case 11: if (GetMessengerTargetPosition(out) == 0) return 0; break;
    case 12: if (GetCubeTypePosition(out) == 0) return 0; break;
    }
    ((Vector3*)out)->FUN_140a4e560(m_pos);
    return 1;
}

// @0x14195e2d0
static int GuideKindOf(const CString& name);
void UIGuideEventArrowDialog::SetKindFromName(CString name) { m_kind = GuideKindOf(name); }

// @0x141960620  the kind of a <ms2> arrow from its classifier name
static int GuideKindOf(const CString& name)
{
    if ((name == "myInfoSkillID"))
        return 1;
    else if ((name == "inventoryDesignItem"))
        return 2;
    else if ((name == "inventoryItemType"))
        return 3;
    else if ((name == "inventoryIconType"))
        return 4;
    else if ((name == "inventoryItemID"))
        return 5;
    else if ((name == "inventoryTab"))
        return 6;
    else if ((name == "minimapMyPc"))
        return 7;
    else if ((name == "minimapPortalID"))
        return 8;
    else if ((name == "houseMark"))
        return 9;
    else if ((name == "partyCamera"))
        return 10;
    else if ((name == "messenger"))
        return 11;
    else if ((name == "cubeType"))
        return 12;
    else
        return 0;
}

// @0x1419607f0  UI by type id
static UIObject* GuideUIById(int id)
{
    if (((void*)TSingleton<CUIService>::GetInstance()) != 0) {
        MS2Ptr<UIObject> ref = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)id);
        if (ref.get() != 0)
            return ref.operator->();
    }
    return 0;
}
// @0x141960870  UI by name
static UIObject* GuideUIByName(const CString& name)
{
    if (((void*)TSingleton<CUIService>::GetInstance()) != 0) {
        MS2Ptr<UIObject> ref = TSingleton<CUIService>::GetInstance()->FindObjectByName(name);
        if (ref.get() != 0)
            return ref.operator->();
    }
    return 0;
}

// @0x1419608f0  (a second copy of the by-name lookup)
static UIObject* GuideUIByName2(const CString& name)
{
    if (((void*)TSingleton<CUIService>::GetInstance()) != 0) {
        MS2Ptr<UIObject> ref = TSingleton<CUIService>::GetInstance()->FindObjectByName(name);
        if (ref.get() != 0)
            return ref.operator->();
    }
    return 0;
}

// @0x14195e320
int UIGuideEventArrowDialog::GetTargetPosition(void* out)
{
    *(Vector3*)out = reinterpret_cast<const Vector3&>(DAT_143b01a60);
    UIObject* ui = 0;
    if (m_38 != 0)
        ui = GuideUIById(m_38);
    if (ui == 0)
        ui = GuideUIByName(m_name);
    if (ui == 0)
        return 0;
    if (dynamic_cast<UIGameMenuDialog*>(ui) != 0)
        return FUN_14195fc40(ui, out);
    return FUN_14195f870(ui, out);
}

// @0x14195e3f0  skill slot of MainPlayerInfo
int UIGuideEventArrowDialog::FUN_14195e3f0(void* out)
{
    UISwfEntity* ui = GuideUIByName2("MainPlayerInfo");
    if (ui == 0)
        return 0;
    MS2Ptr<ASDisplayObject> root(dynamic_cast<ASDisplayObject*>((AScript*)ui->FUN_1422dba00()));
    if (root == 0)
        return 0;
    *(Vector3*)out = Vector3(root.operator->()->FUN_1422c10a0(),
        root.operator->()->FUN_1422c1110(), root.operator->()->GetZ());
    int slot = FUN_1409331f0()->FindQuickSlotBySkillAndItemUid(m_param, 0);
    if (slot == -1)
        return 0;
    float baseX = 0.0f;
    float baseY = 0.0f;
    if (slot >= 0 && slot <= 3) { baseX = -88.0f; baseY = -68.0f; }
    else if (slot > 3 && slot <= 7) { baseX = -68.0f; baseY = 0.0f; }
    else if (slot > 7 && slot <= 11) { baseX = 380.0f; baseY = -68.0f; }
    else { baseX = 400.0f; baseY = 0.0f; }
    slot %= 4;
    baseX += (float)(slot * 0x44 + 0x20);
    ((Vector3*)out)->FUN_140a4e560(Vector3(baseX + 57.0f, baseY + 103.0f, 0.0f));
    return 1;
}

// @0x14195f600  does the inventory item match the arrow's kind / parameter
int UIGuideEventArrowDialog::FUN_14195f600(MS2Ptr<CItem> item, int kind)
{
    if (kind == 2)
        return item->HasCubeTextureMesh() != 0 && item->FUN_140525f60() == 0;
    else if (kind == 3)
        return reinterpret_cast<CItemData*>(reinterpret_cast<Unk_GuideItem*>(item.operator->())->FUN_140527840())->GetType() == m_param;
    else if (kind == 4)
        return reinterpret_cast<CItemData*>(reinterpret_cast<Unk_GuideItem*>(item.operator->())->FUN_140527840())->GetIconCode() == m_param;
    else if (kind == 5)
        return item->FUN_1405276c0() == m_param;
    return 0;
}

// @0x14195e6e0  inventory item
int UIGuideEventArrowDialog::FUN_14195e6e0(void* out)
{
    Unk_GuideInventory* inv = reinterpret_cast<Unk_GuideInventory*>(Unk_BreakDialog<UIInventoryDialog>(0x4e2d));
    if (inv == 0)
        return 0;
    MS2Ptr<ASDisplayObject> root(dynamic_cast<ASDisplayObject*>((AScript*)inv->FUN_1422dba00()));
    if (root == 0)
        return 0;
    const int nCols = 6;
    const int nRows = 6;
    *(Vector3*)out = Vector3(root.operator->()->FUN_1422c10a0(),
        root.operator->()->FUN_1422c1110(), root.operator->()->GetZ());
    ATL::CAtlArray<MS2Ptr<CItem> > items;
    g_143ab2a90.FUN_140a60880(((UIInventoryDialog*)inv)->FUN_141999de0(), items);
    for (size_t i = 0; i < items.GetCount(); i++) {
        if (!reinterpret_cast<Unk_GuideItem*>(items[i].operator->())->FUN_140528980())
            continue;
        if (FUN_14195f600(MS2Ptr<CItem>(items[i]), m_kind) == 0)
            continue;
        int slot = items[i]->FUN_140526b50();
        int page = ((UIInventoryDialog*)inv)->GetScrollPosition();
        int start = page * nCols;
        int end = (page + nRows) * nCols;
        if (start <= slot && slot < end) {
            int col = (slot - start) % nCols + 1;
            int row = (slot - start) / nCols;
            float fx = (float)(col * 0x3f);
            float fy = (float)(row * 0x3e);
            ((Vector3*)out)->FUN_140a4e560(Vector3(fx + 17.0f, fy + 99.0f, 0.0f));
            return 1;
        } else {
            return 0;
        }
    }
    return 0;
}

// @0x14195ead0  inventory tab
int UIGuideEventArrowDialog::FUN_14195ead0(void* out)
{
    Unk_GuideInventory* inv = reinterpret_cast<Unk_GuideInventory*>(Unk_BreakDialog<UIInventoryDialog>(0x4e2d));
    if (inv == 0)
        return 0;
    MS2Ptr<ASButtonBar> tabs = ((UIInventoryDialog*)inv)->GetTabBar();
    if (tabs == 0)
        return 0;
    MS2Ptr<ASDisplayObject> root(dynamic_cast<ASDisplayObject*>((AScript*)inv->FUN_1422dba00()));
    if (root == 0)
        return 0;
    if (m_path.IsEmpty())
        return 0;
    int index = ((UIInventoryDialog*)inv)->FindTabIndexByName(m_path[0]);
    if (index == -1)
        return 0;
    *(Vector3*)out = Vector3(root->FUN_1422c10a0(), root->FUN_1422c1110(), root->GetZ());
    ((Vector3*)out)->FUN_140a4e560(Vector3(tabs->FUN_1422c10a0(), tabs->FUN_1422c1110(), tabs->GetZ()));
    MS2Ptr<ASButton> tab = tabs->GetButtonAt(index);
    if (tab == 0)
        return 0;
    ((Vector3*)out)->FUN_140a4e560(Vector3(tab->FUN_1422c10a0(), tab->FUN_1422c1110(), tab->GetZ()));
    return 1;
}

// @0x14195f7b0
unsigned UIGuideEventArrowDialog::FUN_14195f7b0(int kind)
{
    if (kind == 7) {
        void* actor = reinterpret_cast<Unk_GuideWorld*>(((void*)WorldService::GetInstance()))->FUN_141bd0cc0();
        if (actor != 0)
            return ((class GameObject*)(void*)(actor))->FUN_14123c580();
    } else if (kind == 8) {
        MS2Ptr<Unk_GuidePortal> portal = reinterpret_cast<Unk_GuidePortalMgr*>(((void*)WorldService::GetInstance()))->FUN_141bc2800(m_param);
        if (portal.get() != 0)
            return portal->m_14c;
    }
    return 0;
}

// @0x14195eee0  minimap marker
int UIGuideEventArrowDialog::FUN_14195eee0(void* out)
{
    Unk_GuideMinimap* minimap = ((class Unk_GuideMinimap*)FUN_140c9b540(0x4e29));
    if (minimap == 0)
        return 0;
    int objectId = FUN_14195f7b0(m_kind);
    if (objectId == 0)
        return 0;
    MS2Ptr<CPtred> object = reinterpret_cast<Unk_GuideWorld*>(((void*)WorldService::GetInstance()))->FUN_141bc9be0(objectId);
    if (object.IsNull())
        return 0;
    MS2Ptr<Unk_GuideMarker> marker = minimap->FUN_141a3b510(MS2Ptr<CPtred>(object));
    if (marker.IsNull())
        return 0;
    ((Vector3*)out)->x = (float)minimap->FUN_1422dba00()->Invoke("getGlobalX", marker->m_18->FUN_1422bb870()).GetNumber();
    ((Vector3*)out)->y = (float)minimap->FUN_1422dba00()->Invoke("getGlobalY", marker->m_18->FUN_1422bb870()).GetNumber();
    ((Vector3*)out)->z = 0.0f;
    if (((Vector3*)out)->x == 0.0f || ((Vector3*)out)->y == 0.0f)
        return 0;
    return 1;
}

// @0x14195f270  house mark
int UIGuideEventArrowDialog::GetHouseMarkPosition(void* out)
{
    if (FUN_141274f80() != 0)
        return 0;
    UIHouseMark* house = ((class UIHouseMark*)FUN_1410dc020());
    if (house == 0)
        return 0;
    MS2Ptr<UIHouseMarkEntity> mark = house->FUN_14198ce50(m_param);
    if (mark == 0)
        return 0;
    Vector3 tmp;
    if (!TSingleton<CameraMgr>::GetInstance()->FUN_140af0700(reinterpret_cast<const efd::Point3&>(mark->FUN_14198b2b0()), *(NiPoint3*)out))
        return 0;
    *reinterpret_cast<efd::Point3*>(out) *= TSingleton<CUIService>::GetInstance()->FUN_141adbe70();
    return 1;
}

// @0x14195f3a0  party camera button
int UIGuideEventArrowDialog::GetPartyDialogPosition(void* out)
{
    UIPartyDialog* party = (UIPartyDialog*)FUN_1413b1c60("PartyDialog");
    if (party == 0)
        return 0;
    MS2Ptr<ASDisplayObject> root(dynamic_cast<ASDisplayObject*>((AScript*)party->FUN_1422dba00()));
    if (root == 0)
        return 0;
    *(Vector3*)out = Vector3(root.operator->()->FUN_1422c10a0(),
        root.operator->()->FUN_1422c1110(), root.operator->()->GetZ());
    return party->FUN_141a75680((float*)out);
}

// @0x14195f530  messenger
int UIGuideEventArrowDialog::GetMessengerTargetPosition(void* out)
{
    UIMessengerBrowser* messenger = FUN_140a3ab70(0x4e61);
    if (messenger == 0)
        return 0;
    UISwfEntity* sub = reinterpret_cast<UISwfEntity*>(messenger->FUN_141a25970());
    if (sub == 0)
        return 0;
    return FUN_14195f870(sub, out);
}

// @0x14195f5a0  cube palette
int UIGuideEventArrowDialog::GetCubeTypePosition(void* out)
{
    UIUGCCubePaletteDialog* cube = FUN_140ef4a50(0x4f16);
    if (cube == 0)
        return 0;
    if (m_48 == -1)
        return 0;
    return cube->FUN_140eec4d0(m_48, (Vector3*)out);
}

// @0x14195f870  position of the element reached through the child path m_path
int UIGuideEventArrowDialog::FUN_14195f870(UISwfEntity* ui, void* out)
{
    MS2Ptr<ASDisplayObject> root(dynamic_cast<ASDisplayObject*>((AScript*)ui->FUN_1422dba00()));
    if (root == 0)
        return 0;
    *(Vector3*)out = Vector3(root->FUN_1422c10a0(), root->FUN_1422c1110(), root->GetZ());
    MS2Ptr<ASDisplayObject> last(0);
    if (m_path.GetCount() != 0) {
        MS2Ptr<ASDisplayObject> cur = ui->FUN_1422dba50();
        for (size_t i = 0; i < m_path.GetCount(); i++) {
            cur = cur->FUN_140e159f0<ASDisplayObject>(m_path[i]);
            if (cur == 0)
                return 0;
            if (!cur->GetVisible())
                return 0;
            ((Vector3*)out)->FUN_140a4e560(Vector3(cur->FUN_1422c10a0(), cur->FUN_1422c1110(), cur->GetZ()));
            last = cur;
        }
    }
    if (last.get() != 0)
        ((Vector3*)out)->x += (float)(last->FUN_1422c1340() / 2);
    return 1;
}

// Game menu dialog: path elements the menu table remaps are resolved by getChildObjectPos instead of child lookup.
class Unk_GpDb* FUN_140c1d2f0();   // C3: was FUN_140c1d2f0
int FUN_14193a010();
// @0x14195fc40
int UIGuideEventArrowDialog::FUN_14195fc40(UISwfEntity* ui, void* out)
{
    MS2Ptr<ASDisplayObject> root(dynamic_cast<ASDisplayObject*>((AScript*)ui->FUN_1422dba00()));
    if (root == 0)
        return 0;
    *(Vector3*)out = Vector3(root->FUN_1422c10a0(), root->FUN_1422c1110(), root->GetZ());
    MS2Ptr<ASDisplayObject> last(0);
    if (m_path.GetCount() != 0) {
        MS2Ptr<ASDisplayObject> cur = ui->FUN_1422dba50();
        for (size_t i = 0; i < m_path.GetCount(); i++) {
            MS2Ptr<CGameMenuDef> entry = ((CGameMenuTable*)FUN_140c1d2f0())->FindByName(CString(m_path[i]));
            if ((entry.get() ? true : false) && ((CGameMenuTable*)FUN_140c1d2f0())->IsChild(entry->m_nId, (EGameMenuSet)FUN_14193a010()) != 0) {
                CString shown = m_path[i];
                int target = ((CGameMenuTable*)FUN_140c1d2f0())->FindTopId(entry->m_nId, (EGameMenuSet)FUN_14193a010());
                MS2Ptr<CGameMenuDef> moved = ((CGameMenuTable*)FUN_140c1d2f0())->Find(target);
                if (moved.get() != 0)
                    shown = moved->m_strName;
                GfxValue v = reinterpret_cast<Unk_GuideDO*>(cur.operator->())->FUN_1413127f0("getChildObjectPos", CString(shown), CString(m_path[i]));
                if (!v.IsObject())
                    return 0;
                GfxValue vx, vy, vw;
                v.GetMember("x", &vx);
                v.GetMember("y", &vy);
                v.GetMember("width", &vw);
                ((Vector3*)out)->x += vx.GetNumber();
                ((Vector3*)out)->y += vy.GetNumber();
                ((Vector3*)out)->x += vw.GetNumber() / 2.0;
                break;
            } else {
                cur = cur->FUN_140e159f0<ASDisplayObject>(m_path[i]);
                if (cur == 0)
                    return 0;
                if (!cur->GetVisible())
                    return 0;
                ((Vector3*)out)->FUN_140a4e560(Vector3(cur->FUN_1422c10a0(), cur->FUN_1422c1110(), cur->GetZ()));
                last = cur;
            }
        }
    }
    if (last.get() != 0)
        ((Vector3*)out)->x += (float)(last->FUN_1422c1340() / 2);
    return 1;
}

// @0x141960510
int UIGuideEventArrowDialog::FUN_141960510()
{
    if (m_scenes.IsEmpty())
        return 1;
    Unk_GuideSceneMgr* scene = reinterpret_cast<Unk_GuideSceneMgr*>(FUN_140b632f0()->GetTopEntity(4));
    if (scene == 0)
        return 0;
    for (unsigned i = 0; i < m_scenes.GetCount(); i++) {
        if (scene->vfunc_1() == m_scenes[i])
            return 1;
    }
    return 0;
}

MS2_EMIT_CRT_MEMMOVE_S();

// Guarded replacements for the byte-matched ordinary methods.
MS2_REPLACE_METHOD(0x1419594F0, UIGuideEvent, GetTypeName, 61, 0x83DCB50B);
MS2_REPLACE_METHOD(0x141959540, UIGuideEvent, OnLoadComplete, 408, 0xAD280B30);
MS2_REPLACE_METHOD(0x1419596E0, UIGuideEvent, vfunc_26, 106, 0xC1AA5402);
MS2_REPLACE_METHOD(0x141959750, UIGuideEvent, vfunc_43, 83, 0xBD27DA7E);
MS2_REPLACE_METHOD(0x1419597B0, UIGuideEvent, vfunc_15, 284, 0x94941D74);
MS2_REPLACE_METHOD(0x1419598E0, UIGuideEvent, vfunc_28, 107, 0x13A6DC37);
MS2_REPLACE_METHOD(0x141959960, UIGuideEvent, vfunc_2, 46, 0x5650486B);
MS2_REPLACE_METHOD(0x1419599A0, UIGuideEvent, vfunc_3, 108, 0x93DA484D);
MS2_REPLACE_METHOD(0x141959A20, UIGuideEvent, SkipTextTip, 49, 0xE566080A);
MS2_REPLACE_METHOD(0x14195A0C0, UIGuideEvent, ReleaseArrow, 264, 0x35F07F85);
MS2_REPLACE_METHOD(0x14195A1D0, UIGuideEvent, FUN_14195a1d0, 826, 0xE8B5605C);
MS2_REPLACE_METHOD(0x14195B490, UIGuideEvent, HideTutorial, 156, 0xFFB94B4F);
MS2_REPLACE_METHOD(0x14195B540, UIGuideEvent, HideSummary, 171, 0x84A11ADD);
MS2_REPLACE_METHOD(0x14195B600, UIGuideEvent, AdvanceTextTip, 342, 0x9E9CF949);
MS2_REPLACE_METHOD(0x14195B760, UIGuideEvent, IsTutorialShowing, 166, 0xB3BB373C);
MS2_REPLACE_METHOD(0x14195B810, UIGuideEvent, IsSummaryShowing, 166, 0xC1178F37);
MS2_REPLACE_METHOD(0x14195B8C0, UIGuideEvent, IsTextTipShowing, 136, 0x51C8B7CD);
MS2_REPLACE_METHOD(0x14195B950, UIGuideEvent, GetLastTip, 14, 0x99EEE733);
MS2_REPLACE_METHOD(0x14195BFC0, UIGuideEvent, CheckSummaryExpiry, 66, 0x7CE6065D);
