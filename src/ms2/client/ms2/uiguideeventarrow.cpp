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
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiguideeventarrow.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uiguideeventarrow.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/client/ms2/uimessagebox.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
static CString s_guideSound("system_guide_tooltip");
static CString s_sortNames[] = {"None","Buy","Like","PriceLow","PriceHigh","Create","EnumEnd"};
static CString s_skill("skill");
static CString s_stun("stun");
class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };
static Unk_1401cd100 s_pointer(NULL);
static ATL::CAtlMap<unsigned int,CString> s_conditions(17,.75f,.25f,2.25f,10);
struct Unk_GuideCeRequest { CString m_strName; int m_nOwnerId; int m_pad_0c; char m_pad_10[0x68]; };
void FUN_140a52ef0(Unk_GuideCeRequest*);
void FUN_1405a89e0(Unk_GuideCeRequest*);
class Unk_1403ed280 { public: void FUN_1411a6060(int); int FUN_1411a49c0(Unk_GuideCeRequest*); void FUN_1411a4f40(CString,const Unk_StreamPoint&); };
Unk_1403ed280* FUN_1403ed280();
int FUN_1412755a0();
void FUN_141276180(const CString&,const CString&);
unsigned int FUN_140869420();
bool FUN_1409c1720(const Scaleform::GFx::Value&);
class Unk_1422baa20 { public: Scaleform::GFx::Value FUN_1422baa20(const char*); Scaleform::GFx::Value FUN_140acd130(const char*,CStringW); Scaleform::GFx::Value FUN_140ba26d0(const char*,unsigned int);
    Scaleform::GFx::Value FUN_140cbe3a0(const char*,const wchar_t*); Scaleform::GFx::Value FUN_1422bb3c0(); MS2Ptr<AScript> FUN_141311f50(const CString&); };
class Unk_1422ba7f0 : public AScript { public: Unk_1422ba7f0(const Scaleform::GFx::Value&,int); };
class Unk_1409b9b40 { public: void FUN_1409b9b40(AScript*); };
class Unk_140a94350 { public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(CStringW&); virtual void vfunc_7(int,int);
    virtual void vfunc_8(bool);
};
Unk_140a94350* FUN_140a94350();

// @0x141959330
UIGuideEvent::UIGuideEvent() : m_sound(0),m_guide(0),m_tip(0),m_lastTip(0),m_tips(10),
    m_strings(17,.75f,.25f,2.25f,10),m_voices(17,.75f,.25f,2.25f,10),m_expiry(0),m_arrows(17,.75f,.25f,2.25f,10) { FUN_14195b970(); }
// @0x1419594f0
CString UIGuideEvent::vfunc_1() { return "GuideEvent"; }
// @0x141959540
void UIGuideEvent::OnLoadComplete() {
    UIObject::OnLoadComplete();
    FUN_14195c230("guideTutorial",m_tutorial);
    FUN_14195c230("guideSummary",m_summary);
    reinterpret_cast<Unk_1409b9b40*>(&m_hasArrow)->FUN_1409b9b40(new Unk_1422ba7f0(reinterpret_cast<Unk_1422baa20*>(m_30.operator->())->FUN_1422baa20("hasGuideArrow"),2));
}
// @0x1419596e0
void UIGuideEvent::vfunc_26() { UIObject::vfunc_26(); m_summary=NULL; m_tutorial=NULL; m_hasArrow=NULL; m_timer.FUN_140268840(); }
// @0x141959750
void UIGuideEvent::vfunc_43() { if(m_30.get()) m_30->Invoke("alignment"); }
// @0x1419597b0
void UIGuideEvent::vfunc_15() {
    if(m_30==NULL) return;
    for(POSITION p=m_arrows.GetStartPosition(); p; m_arrows.GetNext(p)) {
        MS2Ptr<UIGuideEventArrow> arrow=m_arrows.GetValueAt(p); arrow->vfunc_1(m_30);
    }
    FUN_14195be30(); FUN_14195bfc0();
}
// @0x1419598e0
int UIGuideEvent::vfunc_28(const char* method,const Scaleform::GFx::Value* args,unsigned int n) {
    if(UISwfEntity::vfunc_28(method,args,n)) return 1;
    if(_stricmp("onTextTipClose",method)==0) { FUN_14195b600(0); return 1; }
    return 0;
}
// @0x141959960
void UIGuideEvent::vfunc_2() { if(FUN_1412755a0()) return; FUN_1422dbf00(0x23,0,0); }
// @0x1419599a0
void UIGuideEvent::vfunc_3() {
    if(FUN_1412755a0()) return; {
        FUN_1422dc080(); m_tip=0; m_tips.RemoveAll();
        if(m_sound) { FUN_1403ed280()->FUN_1411a6060(m_sound); m_sound=0; }
    }
}
// @0x141959a20
int UIGuideEvent::FUN_141959a20() { if(FUN_14195b8c0()) { FUN_14195b600(0); return 1; } return 0; }
// @0x14195a0c0
void UIGuideEvent::FUN_14195a0c0(unsigned int id) {
    MS2Ptr<UIGuideEventArrow> arrow;
    if(!m_arrows.Lookup(id,arrow)) return;
    arrow->FUN_14195dfc0();
    if(arrow->FUN_14195e020()==0) {
        if(m_30.get()) reinterpret_cast<Unk_1422baa20*>(m_30.operator->())->FUN_140ba26d0("removeArrow",id);
        m_arrows.RemoveKey(id);
    }
    FUN_140a94350()->vfunc_8(1);
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
// MS2-FUNCTIONAL: temp/frame layout and callee typing differ (opaque exe helpers)
void UIGuideEvent::FUN_14195b330(unsigned int id,unsigned int stringid) {
    if(m_30==NULL) return;
    if(FUN_14195b8c0()) {
        m_tips.AddTail(std::pair<unsigned int,unsigned int>(std::make_pair(id,stringid)));
    } else {
        reinterpret_cast<Unk_1422baa20*>(m_30.operator->())->FUN_140acd130("showTextTip",FUN_14195c010(stringid));
        m_tip=id; FUN_141276180(s_guideSound,"");
    }
}
// @0x14195b490
void UIGuideEvent::FUN_14195b490(int id) {
    if(m_30==NULL) return;
    if(id && m_guide!=id) return;
    m_30->Invoke("hideTutorial");m_guide=0;FUN_140a94350()->vfunc_8(1);
}
// @0x14195b540
void UIGuideEvent::FUN_14195b540(int id) {
    if(m_30==NULL) return;
    if(id && m_guide!=id) return;
    m_30->Invoke("hideSummary");FUN_140a94350()->vfunc_8(1);m_guide=0;m_expiry=0;
}
// @0x14195b600
void UIGuideEvent::FUN_14195b600(int id) {
    if(id && m_tip!=id) return; {
        if(m_tips.GetCount()!=0) { std::pair<unsigned int,unsigned int> v=m_tips.RemoveHead(); if(m_30.get()) m_30->Invoke("removeTextTip"); FUN_14195b330(v.first,v.second); }
        else { if(m_30.get()) m_30->Invoke("hideTextTip");m_tip=0; }
        FUN_140a94350()->vfunc_8(1);m_lastTip=m_tip;
    }
}
// @0x14195b760
int UIGuideEvent::FUN_14195b760() { if(m_tutorial==NULL) return false; return FUN_1409c1720(m_tutorial->Invoke("isShowing"))!=0; }
// @0x14195b810
int UIGuideEvent::FUN_14195b810() { if(m_summary==NULL) return false; return FUN_1409c1720(m_summary->Invoke("isShowing"))!=0; }
// @0x14195b8c0
int UIGuideEvent::FUN_14195b8c0() { if(m_30==NULL) return 0; return FUN_1409c1720(m_30->Invoke("isShowTextTip")); }
// @0x14195b950
int UIGuideEvent::FUN_14195b950() { return m_lastTip; }
// @0x14195bfc0
void UIGuideEvent::FUN_14195bfc0() { if(!m_expiry) return; if(FUN_140869420()>=m_expiry) FUN_14195b540(m_guide); }


// ---- out-of-unit callees of the recovered (functional) part ----
extern Unk_StreamPoint DAT_143b01a60;                               // the zero point
typedef Scaleform::GFx::Value GfxValue;
void* FUN_1403ed2b0();                                              // UI manager
void* FUN_1403ed2d0();                                              // world service
struct Unk_GeaUiMgrView                                             // UI manager members (this=rcx, hidden return=rdx)
{
    MS2Ptr<UIObject> FUN_141adcea0(int nId);                        // UI by type id
    MS2Ptr<UIObject> FUN_141adcf50(const CString& strName);         // UI by name
};
int FUN_141274f80();
float FUN_141adbe70(void*);                                         // UI scale
Unk_StreamPoint* FUN_140ad0c10(Unk_StreamPoint*,float);             // efd::Point3::operator*=
float FUN_1412762d0(const Unk_StreamPoint&);
bool FUN_1403b3c40(const CStringW&,const wchar_t*);                 // equals
int FUN_141389500(const CStringW&,int);                             // wide string to int
bool FUN_140184310(const CString&,const char*);
bool FUN_1401c0090(const CString&,const CString&);
double FUN_140f17ed0(const GfxValue*);                              // Value::GetNumber
void FUN_14025a680(const CStringW&,ATL::CAtlArray<CStringW>&,const wchar_t*);
CString FUN_14016a600(const wchar_t*,int);
CString FUN_14071ae20(const CString&);
void* FUN_140165cf0(void*,const char*);
void* FUN_140168650(void*,const char*);
bool FUN_14028f710(void*);
int FUN_140873220(void*,const char*,int&);
int FUN_140873420(void*,const char*,CStringW&);
int FUN_1408733e0(void*,const char*,CString&);
struct Unk_GuideFiles { int FUN_1403974b0(TiXmlDocument&,const char*,int,bool,bool); };
Unk_GuideFiles* FUN_140166420();
struct Unk_GuideLog { void FUN_14015eb90(int,int,const wchar_t*,const CString&); };
Unk_GuideLog* FUN_140166440();
class Unk_GuideText { public: void FUN_1416fb340(CStringW&); void FUN_1416fb380(CStringW&); };
Unk_GuideText* FUN_1403b4750();
class Unk_GuideTable { public: CStringW FUN_14142d760(int,int); int FUN_14142e090(int,int); };
Unk_GuideTable* FUN_1409331f0();
void* FUN_1409a8b10();
char* FUN_140a58500(void*);
void* FUN_1401d31f0();
void* FUN_1408e57f0();
int FUN_1422b9e00(void*);
int FUN_1422b9ea0(void*);
UIMessageBox* FUN_14151f890();
class Unk_GuideCamera { public: bool FUN_140af0700(const Unk_StreamPoint&,Unk_StreamPoint&); };
Unk_GuideCamera* FUN_1409478c0();

// A display object seen through its accessors (the exe's inline/COMDAT members, bound by their FUN_ names).
class Unk_GuideDO {
public:
    float FUN_1422c10a0(); float FUN_1422c1110(); float FUN_1422c1180();   // x, y, z
    MS2Ptr<ASDisplayObject> FUN_1413b19d0(const CString&);                    // child by name
    MS2Ptr<ASDisplayObject> FUN_1422e32b0(int);                               // child by index
    GfxValue FUN_1413127f0(const char*,CString,CString);
};
class Unk_GuideValue { public: bool FUN_1409b4d40() const; void FUN_1409c1770(const char*,GfxValue*) const; };
static Unk_GuideDO* GuideDO(ASDisplayObject* p) { return reinterpret_cast<Unk_GuideDO*>(p); }
static Unk_StreamPoint GuideDOPoint(ASDisplayObject* o)
{
    Unk_GuideDO* d = GuideDO(o);
    float z = d->FUN_1422c1180(); float y = d->FUN_1422c1110(); float x = d->FUN_1422c10a0();
    return Unk_StreamPoint(x, y, z);
}
static MS2Ptr<ASDisplayObject> GuideRoot(UISwfEntity* ui)
{
    MS2Ptr<AScript> as = ui->FUN_1422dba00();
    return MS2Ptr<ASDisplayObject>(dynamic_cast<ASDisplayObject*>((AScript*)as));
}
static Unk_1422baa20* GuideAS(const MS2Ptr<AScript>& p) { return reinterpret_cast<Unk_1422baa20*>(p.operator->()); }

// UIs of the dialogs the arrows point at.
class Unk_GuideInventory : public UISwfEntity {
public:
    int FUN_141999de0(); int FUN_141999f10();
    MS2Ptr<ASDisplayObject> FUN_14199aad0();                         // tab strip
    int FUN_14199ab20(CString);                               // tab index by name
};
class Unk_GuideItem { public: bool FUN_140525f10(); bool FUN_140525f60(); void* FUN_140527840(); bool FUN_140528980(); };
class Unk_GuideItemInfo { public: int FUN_14053c5c0(); int FUN_14053c600(); };
class Unk_GuideInvMgr { public: void FUN_140a60880(int,ATL::CAtlArray<MS2Ptr<CItem> >&); };
extern Unk_GuideInvMgr DAT_143ab2a90;
Unk_GuideInventory* FUN_1405344f0(int);
class Unk_GuideMarker : public CPtred { public: MS2Ptr<AScript> m_18; };
class Unk_GuideMinimap : public UISwfEntity { public: MS2Ptr<Unk_GuideMarker> FUN_141a3b510(MS2Ptr<CPtred>); };
Unk_GuideMinimap* FUN_140c9b540(int);
class Unk_GuideWorld { public: MS2Ptr<CPtred> FUN_141bc9be0(unsigned); void* FUN_141bd0cc0(); };
class Unk_GuidePortal : public CPtred { public: char m_pad_18[0x134]; unsigned m_14c; };
class Unk_GuidePortalMgr { public: MS2Ptr<Unk_GuidePortal> FUN_141bc2800(int); };
int FUN_14123c580(void*);
class Unk_GuideHouseMark : public CPtred {};
class Unk_GuideHouse { public: MS2Ptr<Unk_GuideHouseMark> FUN_14198ce50(int*); };
Unk_GuideHouse* FUN_1410dc020();
const Unk_StreamPoint& FUN_14198b2b0(Unk_GuideHouseMark*);
class Unk_GuideParty : public UISwfEntity { public: int FUN_141a75680(void*); };
Unk_GuideParty* FUN_1413b1c60(const CString&);
class Unk_GuideMessenger : public UISwfEntity { public: UISwfEntity* FUN_141a25970(); };
Unk_GuideMessenger* FUN_140a3ab70(int);
class Unk_GuideCube { public: int FUN_140eec4d0(int,void*); };
Unk_GuideCube* FUN_140ef4a50(int);
class Unk_GuideSceneMgr { public: virtual void vfunc_0(); virtual CString vfunc_1(); };
class Unk_GuideScenes { public: Unk_GuideSceneMgr* FUN_1422d4980(int); };
Unk_GuideScenes* FUN_140b632f0();
class UIGameMenuDialog : public UIObject {};

// @0x14195bd90
void UIGuideEvent::FUN_14195bd90(unsigned int stringId)
{
    CString voice = FUN_14195c0e0(stringId);
    if (voice.GetLength() != 0)
        FUN_1403ed280()->FUN_1411a4f40(CString(voice), DAT_143b01a60);
}

// @0x14195c010
CStringW UIGuideEvent::FUN_14195c010(unsigned int id)
{
    CStringW text;
    if (!m_strings.Lookup(id, text))
        return CStringW(L"");
    FUN_1403b4750()->FUN_1416fb340(text);
    return text;
}

// @0x14195c0e0
CString UIGuideEvent::FUN_14195c0e0(unsigned int id)
{
    CString voice;
    if (!m_voices.Lookup(id, voice))
        return CString("");
    return voice;
}

// @0x14195c1a0
MS2Ptr<AScript> UIGuideEvent::FUN_14195c1a0(const CString& name)
{
    if (m_30 == NULL)
        return MS2Ptr<AScript>(0);
    return GuideAS(m_30)->FUN_141311f50(name);
}

// @0x14195c230
MS2Ptr<AScript> UIGuideEvent::FUN_14195c230(const CString& name, MS2Ptr<AScript>& out)
{
    out = FUN_14195c1a0(name);
    return out;
}

// @0x14195bc50  "name:value" of a [[...]] tag
void UIGuideEvent::FUN_14195bc50(CStringW tag, CStringW& name, CStringW& value)
{
    ATL::CAtlArray<CStringW> parts;
    FUN_14025a680(tag, parts, L":");
    if (parts.GetCount() == 2) {
        name = (const char*)FUN_14016a600(parts[0], 0);
        value = (const char*)FUN_14016a600(parts[1], 0);
    }
}

// @0x14195b970  stringGuide.xml: <ms2><key id name voiceID/>...</ms2>
// MS2-FUNCTIONAL: temp/frame layout and callee typing differ (opaque exe helpers)
void UIGuideEvent::FUN_14195b970()
{
    m_strings.RemoveAll();
    m_voices.RemoveAll();
    CString path = FUN_14071ae20(CString("stringGuide.xml"));
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(doc, path, 0, true, false) == 0)
        return;
    void* root = FUN_140165cf0(&doc, "ms2");
    if (root == 0) {
        FUN_140166440()->FUN_14015eb90(1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", path);
        return;
    }
    for (void* node = FUN_140165cf0(root, "key"); node != 0; node = FUN_140168650(node, "key")) {
        int id = 0;
        CStringW name;
        CString voice;
        if (!FUN_14028f710(node))
            continue;
        FUN_140873220(node, "id", id);
        FUN_140873420(node, "name", name);
        FUN_1408733e0(node, "voiceID", voice);
        if (!name.IsEmpty()) {
            name.Replace(L"\\n", L"\n");
            FUN_1403b4750()->FUN_1416fb380(name);
            m_strings.SetAt(id, name);
        }
        if (!voice.IsEmpty())
            m_voices.SetAt(id, voice);
    }
}

// @0x14195be30  the voice/sound loop is on while the arrow flag is
// MS2-FUNCTIONAL: temp/frame layout and callee typing differ (opaque exe helpers)
void UIGuideEvent::FUN_14195be30()
{
    if (m_30 == NULL || m_timer.FUN_140268870(300) == 0)
        return;
    bool bPlaying = m_sound != 0;
    char bWanted = 0;
    if (FUN_1422b9ea0(FUN_1408e57f0()) == 0) {
        GfxValue v = GuideAS(m_hasArrow)->FUN_1422bb3c0();
        bWanted = FUN_1409c1720(v);
    }
    if (bPlaying != (bWanted != 0)) {
        if (bPlaying) {
            FUN_1403ed280()->FUN_1411a6060(m_sound);
            m_sound = 0;
        } else {
            Unk_GuideCeRequest request;
            FUN_140a52ef0(&request);
            request.m_strName = *reinterpret_cast<CString*>((char*)FUN_1401d31f0() + 0x2f8);
            request.m_nOwnerId = 0;
            m_sound = FUN_1403ed280()->FUN_1411a49c0(&request);
            FUN_1405a89e0(&request);
        }
    }
}

// @0x141959a60  AddArrow: shared by id, a second add only bumps the use count
// MS2-FUNCTIONAL: temp/frame layout and callee typing differ (opaque exe helpers)
void UIGuideEvent::FUN_141959a60(MS2Ptr<UIGuideEventArrow> arrow)
{
    MS2Ptr<UIGuideEventArrow> existing;
    if (m_arrows.Lookup(arrow->m_id, existing)) {
        existing->FUN_14195dfa0();
        return;
    }
    existing = arrow;
    m_arrows.SetAt(arrow->m_id, existing);
    Unk_StreamPoint pos = DAT_143b01a60;
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
    CStringW text = FUN_14195c010(arrow->m_textId);
    int special = 0;
    CStringW part;
    FUN_14195a1d0(text, part, special);
    if (special == 0) {
        info.FUN_1407cbb20("text", part);
    } else {
        CStringW name, value;
        FUN_14195bc50(part, name, value);
        if (FUN_1403b3c40(name, L"keyText")) {
            info.FUN_1407cbb20("key", value);
            FUN_140a94350()->vfunc_6(value);
        } else if (FUN_1403b3c40(name, L"keyAction")) {
            int action = FUN_141389500(value, 0);
            CStringW key = FUN_1409331f0()->FUN_14142d760(action, 0);
            info.FUN_1407cbb20("key", key);
            FUN_140a94350()->vfunc_7(action, 1);
        } else if (FUN_1403b3c40(name, L"keyActionSub")) {
            int action = FUN_141389500(value, 0);
            CStringW key = FUN_1409331f0()->FUN_14142d760(action, 1);
            info.FUN_1407cbb20("key", key);
            FUN_140a94350()->vfunc_7(action, 1);
        }
    }
    if (m_30.get()) {
        if (arrow->m_textId == 0) {
            m_30->Invoke("addArrow", info);
        } else {
            FUN_14195bd90(arrow->m_textId);
            m_30->Invoke("addTextArrow", info);
        }
    }
    FUN_14195be30();
}

// Adds the [[keyText/keyAction/keyActionSub/...]] tagged parts of a guide text to the text box `box`.
// @0x14195a520
// MS2-FUNCTIONAL: temp/frame layout and callee typing differ (opaque exe helpers)
void UIGuideEvent::FUN_14195a520(unsigned int guideId, unsigned int stringId, int mode)
{
    if (m_30 == NULL || m_tutorial == NULL)
        return;
    m_tutorial->Invoke("clearContents");
    CStringW text = FUN_14195c010(stringId);
    while (text.GetLength() != 0) {
        int special = 0;
        CStringW part;
        FUN_14195a1d0(text, part, special);
        if (special == 0) {
            GuideAS(m_tutorial)->FUN_140acd130("addText", part);
            continue;
        }
        CStringW name, value;
        FUN_14195bc50(part, name, value);
        if (FUN_1403b3c40(name, L"keyText")) {
            GuideAS(m_tutorial)->FUN_140acd130("addKeyButton", value);
            FUN_140a94350()->vfunc_6(value);
        } else if (FUN_1403b3c40(name, L"keyDirection")) {
            m_tutorial->Invoke("addDirectionKey");
        } else if (FUN_1403b3c40(name, L"keyAction")) {
            int action = FUN_141389500(value, 0);
            GuideAS(m_tutorial)->FUN_140acd130("addKeyButton", FUN_1409331f0()->FUN_14142d760(action, 0));
            FUN_140a94350()->vfunc_7(action, 1);
        } else if (FUN_1403b3c40(name, L"keyActionSub")) {
            int action = FUN_141389500(value, 0);
            GuideAS(m_tutorial)->FUN_140acd130("addKeyButton", FUN_1409331f0()->FUN_14142d760(action, 1));
            FUN_140a94350()->vfunc_7(action, 1);
        }
    }
    FUN_14195bd90(stringId);
    if (mode == 0) {
        m_tutorial->Invoke("alignment");
        GuideAS(m_tutorial)->FUN_140cbe3a0("gotoAndPlayText", L"show");
    } else {
        m_30->Invoke("showTutorial");
    }
    m_guide = guideId;
}

// @0x14195ab40  summary window: keyAction tags become plain text for gamepad users
// MS2-FUNCTIONAL: temp/frame layout and callee typing differ (opaque exe helpers)
void UIGuideEvent::FUN_14195ab40(unsigned int guideId, unsigned int stringId, int durationMs)
{
    if (m_30 == NULL || m_summary == NULL)
        return;
    m_summary->Invoke("clearContents");
    FUN_140a94350()->vfunc_8(1);
    CStringW text = FUN_14195c010(stringId);
    while (text.GetLength() != 0) {
        int special = 0;
        CStringW part;
        FUN_14195a1d0(text, part, special);
        if (special == 0) {
            GuideAS(m_summary)->FUN_140acd130("addText", part);
        } else {
            CStringW name, value;
            FUN_14195bc50(part, name, value);
            if (FUN_1403b3c40(name, L"keyText")) {
                GuideAS(m_summary)->FUN_140acd130("addKeyButton", value);
                FUN_140a94350()->vfunc_6(value);
            } else if (FUN_1403b3c40(name, L"icon")) {
                GuideAS(m_summary)->FUN_140acd130("addIcon", value);
            } else if (FUN_1403b3c40(name, L"keyAction")) {
                if (*FUN_140a58500(FUN_1409a8b10()) == 0) {
                    int action = FUN_141389500(value, 0);
                    CStringW key = FUN_1409331f0()->FUN_14142d760(action, 0);
                    GuideAS(m_summary)->FUN_140acd130("addKeyButton", key);
                    FUN_140a94350()->vfunc_7(action, 1);
                } else {
                    int action = FUN_141389500(value, 0);
                    CStringW key = FUN_1409331f0()->FUN_14142d760(action, 2);
                    GuideAS(m_summary)->FUN_140acd130("addText", key);
                }
            } else if (FUN_1403b3c40(name, L"keyActionSub")) {
                if (*FUN_140a58500(FUN_1409a8b10()) == 0) {
                    int action = FUN_141389500(value, 0);
                    CStringW key = FUN_1409331f0()->FUN_14142d760(action, 1);
                    GuideAS(m_summary)->FUN_140acd130("addKeyButton", key);
                    FUN_140a94350()->vfunc_7(action, 1);
                } else {
                    int action = FUN_141389500(value, 0);
                    CStringW key = FUN_1409331f0()->FUN_14142d760(action, 2);
                    GuideAS(m_summary)->FUN_140acd130("addText", key);
                }
            }
        }
    }
    m_30->Invoke("showSummary");
    FUN_14195bd90(stringId);
    m_guide = guideId;
    m_expiry = 0;
    if (durationMs != 0)
        m_expiry = FUN_140869420() + durationMs;
}

// ---- UIGuideEventArrow ----
// @0x14195dd10
UIGuideEventArrow::UIGuideEventArrow() : m_pos(), m_direction(0), m_align(0), m_textId(0), m_useCount(1) {}
// @0x1419609a0
// MS2-FUNCTIONAL: temp/frame layout and callee typing differ (opaque exe helpers)
UIGuideEventArrow::~UIGuideEventArrow() {}
// @0x14195dd90
// MS2-FUNCTIONAL: temp/frame layout and callee typing differ (opaque exe helpers)
void UIGuideEventArrow::vfunc_1(MS2Ptr<AScript> movie)
{
    Unk_StreamPoint pos;
    if (vfunc_2(&pos) == 0) {
        GuideAS(movie)->FUN_140ba26d0("hideArrow", m_id);
    } else {
        ASObj info(2);
        info.FUN_1409c0d20("id", m_id);
        info.FUN_1409c4a30("x", pos.x);
        info.FUN_1409c4a30("y", pos.y);
        movie->Invoke("updateArrow", info);
    }
}
// @0x14195dee0
// MS2-FUNCTIONAL: temp/frame layout and callee typing differ (opaque exe helpers)
int UIGuideEventArrow::vfunc_2(void* out)
{
    Unk_StreamPoint* pos = (Unk_StreamPoint*)out;
    if (FUN_141274f80() != 0)
        return 0;
    *pos = DAT_143b01a60;
    if (!FUN_1409478c0()->FUN_140af0700(m_pos, *pos))
        return 0;
    FUN_140ad0c10(pos, FUN_141adbe70(FUN_1403ed2b0()));
    pos->y += FUN_1412762d0(m_pos);
    return 1;
}
// @0x14195dfa0
void UIGuideEventArrow::FUN_14195dfa0() { m_useCount++; }
// @0x14195dfc0
// MS2-FUNCTIONAL: temp/frame layout and callee typing differ (opaque exe helpers)
int UIGuideEventArrow::FUN_14195dfc0()
{
    if (m_useCount == 0) {
        MS2_ASSERT_AT(0x27, 0);
        return 0;
    }
    return --m_useCount;
}
// @0x14195e020
int UIGuideEventArrow::FUN_14195e020() { return m_useCount; }

// ---- UIGuideEventArrowDialog ----
// @0x14195e040
UIGuideEventArrowDialog::UIGuideEventArrowDialog() : m_38(0), m_48(-1), m_kind(0), m_param(0) {}
// @0x1419609c0
// MS2-FUNCTIONAL: temp/frame layout and callee typing differ (opaque exe helpers)
UIGuideEventArrowDialog::~UIGuideEventArrowDialog() {}

// @0x14195e0e0
int UIGuideEventArrowDialog::vfunc_2(void* out)
{
    if (FUN_1422b9e00(FUN_1408e57f0()) == 0x6200041)
        return 0;
    UIMessageBox* box = FUN_14151f890();
    if (box != 0 && box->FUN_1419f8270() == 0)
        return 0;
    if (FUN_141960510() == 0)
        return 0;
    switch (m_kind) {
    case 0:  if (FUN_14195e320(out) == 0) return 0; break;
    case 1:  if (FUN_14195e3f0(out) == 0) return 0; break;
    case 2: case 3: case 4: case 5:
             if (FUN_14195e6e0(out) == 0) return 0; break;
    case 6:  if (FUN_14195ead0(out) == 0) return 0; break;
    case 7: case 8:
             if (FUN_14195eee0(out) == 0) return 0; break;
    case 9:  if (FUN_14195f270(out) == 0) return 0; break;
    case 10: if (FUN_14195f3a0(out) == 0) return 0; break;
    case 11: if (FUN_14195f530(out) == 0) return 0; break;
    case 12: if (FUN_14195f5a0(out) == 0) return 0; break;
    }
    ((Unk_StreamPoint*)out)->FUN_140a4e560(m_pos);
    return 1;
}

// @0x14195e2d0
static int GuideKindOf(const CString& name);
void UIGuideEventArrowDialog::FUN_14195e2d0(CString name) { m_kind = GuideKindOf(name); }

// @0x141960620  the kind of a <ms2> arrow from its classifier name
// MS2-FUNCTIONAL: temp/frame layout and callee typing differ (opaque exe helpers)
static int GuideKindOf(const CString& name)
{
    if (FUN_140184310(name, "myInfoSkillID")) return 1;
    if (FUN_140184310(name, "inventoryDesignItem")) return 2;
    if (FUN_140184310(name, "inventoryItemType")) return 3;
    if (FUN_140184310(name, "inventoryIconType")) return 4;
    if (FUN_140184310(name, "inventoryItemID")) return 5;
    if (FUN_140184310(name, "inventoryTab")) return 6;
    if (FUN_140184310(name, "minimapMyPc")) return 7;
    if (FUN_140184310(name, "minimapPortalID")) return 8;
    if (FUN_140184310(name, "houseMark")) return 9;
    if (FUN_140184310(name, "partyCamera")) return 10;
    if (FUN_140184310(name, "messenger")) return 11;
    if (FUN_140184310(name, "cubeType")) return 12;
    return 0;
}

// @0x1419607f0  UI by type id
// MS2-FUNCTIONAL: temp/frame layout and callee typing differ (opaque exe helpers)
static UIObject* GuideUIById(int id)
{
    if (FUN_1403ed2b0() != 0) {
        MS2Ptr<UIObject> ref = static_cast<Unk_GeaUiMgrView*>(FUN_1403ed2b0())->FUN_141adcea0(id);
        if (ref.get() != 0)
            return ref.operator->();
    }
    return 0;
}
// @0x141960870  UI by name
// MS2-FUNCTIONAL: temp/frame layout and callee typing differ (opaque exe helpers)
static UIObject* GuideUIByName(const CString& name)
{
    if (FUN_1403ed2b0() != 0) {
        MS2Ptr<UIObject> ref = static_cast<Unk_GeaUiMgrView*>(FUN_1403ed2b0())->FUN_141adcf50(name);
        if (ref.get() != 0)
            return ref.operator->();
    }
    return 0;
}

// @0x1419608f0  (a second copy of the by-name lookup)
// MS2-FUNCTIONAL: temp/frame layout and callee typing differ (opaque exe helpers)
static UIObject* GuideUIByName2(const CString& name)
{
    if (FUN_1403ed2b0() != 0) {
        MS2Ptr<UIObject> ref = static_cast<Unk_GeaUiMgrView*>(FUN_1403ed2b0())->FUN_141adcf50(name);
        if (ref.get() != 0)
            return ref.operator->();
    }
    return 0;
}

// @0x14195e320
// MS2-FUNCTIONAL: temp/frame layout and callee typing differ (opaque exe helpers)
int UIGuideEventArrowDialog::FUN_14195e320(void* out)
{
    Unk_StreamPoint* pos = (Unk_StreamPoint*)out;
    *pos = DAT_143b01a60;
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
// MS2-FUNCTIONAL: temp/frame layout and callee typing differ (opaque exe helpers)
int UIGuideEventArrowDialog::FUN_14195e3f0(void* out)
{
    Unk_StreamPoint* pos = (Unk_StreamPoint*)out;
    UISwfEntity* ui = GuideUIByName2(CString("MainPlayerInfo"));
    if (ui == 0)
        return 0;
    MS2Ptr<ASDisplayObject> root = GuideRoot(ui);
    if (root.IsNull())
        return 0;
    *pos = GuideDOPoint(root.operator->());
    int slot = FUN_1409331f0()->FUN_14142e090(m_param, 0);
    if (slot == -1)
        return 0;
    float baseX, baseY;
    if (slot >= 0 && slot <= 3) { baseX = -88.0f; baseY = -68.0f; }
    else if (slot >= 4 && slot <= 7) { baseX = -68.0f; baseY = 0.0f; }
    else if (slot >= 8 && slot <= 11) { baseX = 380.0f; baseY = -68.0f; }
    else { baseX = 400.0f; baseY = 0.0f; }
    pos->FUN_140a4e560(Unk_StreamPoint(baseX + (float)((slot % 4) * 0x44 + 0x20) + 57.0f, baseY + 103.0f, 0.0f));
    return 1;
}

// @0x14195f600  does the inventory item match the arrow's kind / parameter
// MS2-FUNCTIONAL: temp/frame layout and callee typing differ (opaque exe helpers)
int UIGuideEventArrowDialog::FUN_14195f600(MS2Ptr<CItem> item, int kind)
{
    if (kind == 2) {
        Unk_GuideItem* it = reinterpret_cast<Unk_GuideItem*>(item.operator->());
        return it->FUN_140525f10() != 0 && it->FUN_140525f60() == 0;
    }
    if (kind == 3)
        return reinterpret_cast<Unk_GuideItemInfo*>(reinterpret_cast<Unk_GuideItem*>(item.operator->())->FUN_140527840())->FUN_14053c5c0() == m_param;
    if (kind == 4)
        return reinterpret_cast<Unk_GuideItemInfo*>(reinterpret_cast<Unk_GuideItem*>(item.operator->())->FUN_140527840())->FUN_14053c600() == m_param;
    if (kind == 5)
        return item->FUN_1405276c0() == m_param;
    return 0;
}

// @0x14195e6e0  inventory item
// MS2-FUNCTIONAL: temp/frame layout and callee typing differ (opaque exe helpers)
int UIGuideEventArrowDialog::FUN_14195e6e0(void* out)
{
    Unk_StreamPoint* pos = (Unk_StreamPoint*)out;
    Unk_GuideInventory* inv = FUN_1405344f0(0x4e2d);
    if (inv == 0)
        return 0;
    MS2Ptr<ASDisplayObject> root = GuideRoot(inv);
    if (root.IsNull())
        return 0;
    *pos = GuideDOPoint(root.operator->());
    ATL::CAtlArray<MS2Ptr<CItem> > items;
    DAT_143ab2a90.FUN_140a60880(inv->FUN_141999de0(), items);
    for (size_t i = 0; i < items.GetCount(); i++) {
        if (!reinterpret_cast<Unk_GuideItem*>(items[i].operator->())->FUN_140528980())
            continue;
        if (FUN_14195f600(MS2Ptr<CItem>(items[i]), m_kind) == 0)
            continue;
        int slot = items[i]->FUN_140526b50();
        int page = inv->FUN_141999f10();
        if (page * 6 <= slot && slot < (page + 6) * 6) {
            int rel = slot - page * 6;
            int col = rel % 6 + 1;
            int row = rel / 6;
            pos->FUN_140a4e560(Unk_StreamPoint((float)(col * 0x3f) + 17.0f, (float)(row * 0x3e) + 99.0f, 0.0f));
            return 1;
        }
        return 0;
    }
    return 0;
}

// @0x14195ead0  inventory tab
// MS2-FUNCTIONAL: temp/frame layout and callee typing differ (opaque exe helpers)
int UIGuideEventArrowDialog::FUN_14195ead0(void* out)
{
    Unk_StreamPoint* pos = (Unk_StreamPoint*)out;
    Unk_GuideInventory* inv = FUN_1405344f0(0x4e2d);
    if (inv == 0)
        return 0;
    MS2Ptr<ASDisplayObject> tabs = inv->FUN_14199aad0();
    if (tabs.IsNull())
        return 0;
    MS2Ptr<ASDisplayObject> root = GuideRoot(inv);
    if (root.IsNull())
        return 0;
    if (m_path.IsEmpty())
        return 0;
    int index = inv->FUN_14199ab20(CString(m_path[0]));
    if (index == -1)
        return 0;
    *pos = GuideDOPoint(root.operator->());
    pos->FUN_140a4e560(GuideDOPoint(tabs.operator->()));
    MS2Ptr<ASDisplayObject> tab = GuideDO(tabs.operator->())->FUN_1422e32b0(index);
    if (tab.IsNull())
        return 0;
    pos->FUN_140a4e560(GuideDOPoint(tab.operator->()));
    return 1;
}

// @0x14195f7b0
unsigned UIGuideEventArrowDialog::FUN_14195f7b0(int kind)
{
    if (kind == 7) {
        void* actor = reinterpret_cast<Unk_GuideWorld*>(FUN_1403ed2d0())->FUN_141bd0cc0();
        if (actor != 0)
            return FUN_14123c580(actor);
    } else if (kind == 8) {
        MS2Ptr<Unk_GuidePortal> portal = reinterpret_cast<Unk_GuidePortalMgr*>(FUN_1403ed2d0())->FUN_141bc2800(m_param);
        if (portal.get() != 0)
            return portal->m_14c;
    }
    return 0;
}

// @0x14195eee0  minimap marker
// MS2-FUNCTIONAL: temp/frame layout and callee typing differ (opaque exe helpers)
int UIGuideEventArrowDialog::FUN_14195eee0(void* out)
{
    Unk_StreamPoint* pos = (Unk_StreamPoint*)out;
    Unk_GuideMinimap* minimap = FUN_140c9b540(0x4e29);
    if (minimap == 0)
        return 0;
    int objectId = FUN_14195f7b0(m_kind);
    if (objectId == 0)
        return 0;
    MS2Ptr<CPtred> object = reinterpret_cast<Unk_GuideWorld*>(FUN_1403ed2d0())->FUN_141bc9be0(objectId);
    if (object.IsNull())
        return 0;
    MS2Ptr<Unk_GuideMarker> marker = minimap->FUN_141a3b510(MS2Ptr<CPtred>(object));
    if (marker.IsNull())
        return 0;
    GfxValue gx = marker->m_18->FUN_1422bb870();
    GfxValue rx = minimap->FUN_1422dba00()->Invoke("getGlobalX", gx);
    pos->x = (float)FUN_140f17ed0(&rx);
    GfxValue gy = marker->m_18->FUN_1422bb870();
    GfxValue ry = minimap->FUN_1422dba00()->Invoke("getGlobalY", gy);
    pos->y = (float)FUN_140f17ed0(&ry);
    pos->z = 0.0f;
    return !(pos->x == 0.0f || pos->y == 0.0f);
}

// @0x14195f270  house mark
int UIGuideEventArrowDialog::FUN_14195f270(void* out)
{
    if (FUN_141274f80() != 0)
        return 0;
    Unk_GuideHouse* house = FUN_1410dc020();
    if (house == 0)
        return 0;
    MS2Ptr<Unk_GuideHouseMark> mark = house->FUN_14198ce50(&m_param);
    if (mark == 0)
        return 0;
    Unk_StreamPoint tmp;
    if (!FUN_1409478c0()->FUN_140af0700(FUN_14198b2b0(mark.operator->()), *(Unk_StreamPoint*)out))
        return 0;
    FUN_140ad0c10((Unk_StreamPoint*)out, FUN_141adbe70(FUN_1403ed2b0()));
    return 1;
}

// @0x14195f3a0  party camera button
// MS2-FUNCTIONAL: temp/frame layout and callee typing differ (opaque exe helpers)
int UIGuideEventArrowDialog::FUN_14195f3a0(void* out)
{
    Unk_GuideParty* party = FUN_1413b1c60(CString("PartyDialog"));
    if (party == 0)
        return 0;
    MS2Ptr<ASDisplayObject> root = GuideRoot(party);
    if (root.IsNull())
        return 0;
    *(Unk_StreamPoint*)out = GuideDOPoint(root.operator->());
    return party->FUN_141a75680(out);
}

// @0x14195f530  messenger
int UIGuideEventArrowDialog::FUN_14195f530(void* out)
{
    Unk_GuideMessenger* messenger = FUN_140a3ab70(0x4e61);
    if (messenger == 0)
        return 0;
    UISwfEntity* sub = messenger->FUN_141a25970();
    if (sub == 0)
        return 0;
    return FUN_14195f870(sub, out);
}

// @0x14195f5a0  cube palette
int UIGuideEventArrowDialog::FUN_14195f5a0(void* out)
{
    Unk_GuideCube* cube = FUN_140ef4a50(0x4f16);
    if (cube == 0)
        return 0;
    if (m_48 == -1)
        return 0;
    return cube->FUN_140eec4d0(m_48, out);
}

// @0x14195f870  position of the element reached through the child path m_path
// MS2-FUNCTIONAL: temp/frame layout and callee typing differ (opaque exe helpers)
int UIGuideEventArrowDialog::FUN_14195f870(UISwfEntity* ui, void* out)
{
    Unk_StreamPoint* pos = (Unk_StreamPoint*)out;
    MS2Ptr<ASDisplayObject> root = GuideRoot(ui);
    if (root.IsNull())
        return 0;
    *pos = GuideDOPoint(root.operator->());
    MS2Ptr<ASDisplayObject> last(0);
    if (m_path.GetCount() != 0) {
        MS2Ptr<ASDisplayObject> cur = ui->FUN_1422dba50();
        for (size_t i = 0; i < m_path.GetCount(); i++) {
            cur = GuideDO(cur.operator->())->FUN_1413b19d0(m_path[i]);
            if (cur.IsNull())
                return 0;
            if (!cur->FUN_1422bfca0())
                return 0;
            pos->FUN_140a4e560(GuideDOPoint(cur.operator->()));
            last = cur;
        }
    }
    if (last.get() != 0)
        pos->x += (float)(last->FUN_1422c1340() / 2);
    return 1;
}

// Game menu dialog: path elements the menu table remaps are resolved by getChildObjectPos instead of child lookup.
struct Unk_GuideMenuEntry { char m_pad_00[0x18]; int m_18; int m_pad_1c; CString m_name; };   // +0x00 CPtred header, +0x20 name (0x14195fc40)
class Unk_GuideMenuRef { public: ~Unk_GuideMenuRef(); bool FUN_140c1cd90() const; Unk_GuideMenuEntry* FUN_140c1cda0() const; private: char m_pad[0x20]; };
class Unk_GuideMenuTable { public: Unk_GuideMenuRef FUN_140cf7470(CString); int FUN_140cf71f0(int,int); int FUN_140cf72f0(int,int); Unk_GuideMenuRef FUN_140cf7690(int); };
Unk_GuideMenuTable* FUN_140c1d2f0();
int FUN_14193a010();
// @0x14195fc40
// MS2-FUNCTIONAL: temp/frame layout and callee typing differ (opaque exe helpers)
int UIGuideEventArrowDialog::FUN_14195fc40(UISwfEntity* ui, void* out)
{
    Unk_StreamPoint* pos = (Unk_StreamPoint*)out;
    MS2Ptr<ASDisplayObject> root = GuideRoot(ui);
    if (root.IsNull())
        return 0;
    *pos = GuideDOPoint(root.operator->());
    MS2Ptr<ASDisplayObject> last(0);
    if (m_path.GetCount() != 0) {
        MS2Ptr<ASDisplayObject> cur = ui->FUN_1422dba50();
        for (size_t i = 0; i < m_path.GetCount(); i++) {
            Unk_GuideMenuRef entry = FUN_140c1d2f0()->FUN_140cf7470(CString(m_path[i]));
            if (entry.FUN_140c1cd90() != 0) {
                int lang = FUN_14193a010();
                if (FUN_140c1d2f0()->FUN_140cf71f0(entry.FUN_140c1cda0()->m_18, lang) != 0) {
                    CString shown = m_path[i];
                    int lang2 = FUN_14193a010();
                    int target = FUN_140c1d2f0()->FUN_140cf72f0(entry.FUN_140c1cda0()->m_18, lang2);
                    Unk_GuideMenuRef moved = FUN_140c1d2f0()->FUN_140cf7690(target);
                    if (moved.FUN_140c1cd90() != 0)
                        shown = moved.FUN_140c1cda0()->m_name;
                    GfxValue v = GuideDO(cur.operator->())->FUN_1413127f0("getChildObjectPos", CString(m_path[i]), CString(shown));
                    const Unk_GuideValue* vv = reinterpret_cast<const Unk_GuideValue*>(&v);
                    if (!vv->FUN_1409b4d40())
                        return 0;
                    GfxValue vx, vy, vw;
                    vv->FUN_1409c1770("x", &vx);
                    vv->FUN_1409c1770("y", &vy);
                    vv->FUN_1409c1770("width", &vw);
                    pos->x = (float)((double)pos->x + FUN_140f17ed0(&vx));
                    pos->y = (float)((double)pos->y + FUN_140f17ed0(&vy));
                    pos->x = (float)((double)pos->x + FUN_140f17ed0(&vw) / 2.0);
                    break;
                }
            }
            cur = GuideDO(cur.operator->())->FUN_1413b19d0(m_path[i]);
            if (cur.IsNull())
                return 0;
            if (!cur->FUN_1422bfca0())
                return 0;
            pos->FUN_140a4e560(GuideDOPoint(cur.operator->()));
            last = cur;
        }
    }
    if (last.get() != 0)
        pos->x += (float)(last->FUN_1422c1340() / 2);
    return 1;
}

// @0x141960510
// MS2-FUNCTIONAL: temp/frame layout and callee typing differ (opaque exe helpers)
int UIGuideEventArrowDialog::FUN_141960510()
{
    if (m_scenes.IsEmpty())
        return 1;
    Unk_GuideSceneMgr* scene = FUN_140b632f0()->FUN_1422d4980(4);
    if (scene == 0)
        return 0;
    for (unsigned i = 0; i < m_scenes.GetCount(); i++) {
        CString current = scene->vfunc_1();
        if (FUN_1401c0090(current, m_scenes[i]))
            return 1;
    }
    return 0;
}

MS2_EMIT_CRT_MEMMOVE_S();

// Guarded replacements for the byte-matched ordinary methods.
MS2_REPLACE_METHOD(0x1419594F0, UIGuideEvent, vfunc_1, 61, 0x83DCB50B);
MS2_REPLACE_METHOD(0x141959540, UIGuideEvent, OnLoadComplete, 408, 0xAD280B30);
MS2_REPLACE_METHOD(0x1419596E0, UIGuideEvent, vfunc_26, 106, 0xC1AA5402);
MS2_REPLACE_METHOD(0x141959750, UIGuideEvent, vfunc_43, 83, 0xBD27DA7E);
MS2_REPLACE_METHOD(0x1419597B0, UIGuideEvent, vfunc_15, 284, 0x94941D74);
MS2_REPLACE_METHOD(0x1419598E0, UIGuideEvent, vfunc_28, 107, 0x13A6DC37);
MS2_REPLACE_METHOD(0x141959960, UIGuideEvent, vfunc_2, 46, 0x5650486B);
MS2_REPLACE_METHOD(0x1419599A0, UIGuideEvent, vfunc_3, 108, 0x93DA484D);
MS2_REPLACE_METHOD(0x141959A20, UIGuideEvent, FUN_141959a20, 49, 0xE566080A);
MS2_REPLACE_METHOD(0x14195A0C0, UIGuideEvent, FUN_14195a0c0, 264, 0x35F07F85);
MS2_REPLACE_METHOD(0x14195A1D0, UIGuideEvent, FUN_14195a1d0, 826, 0xE8B5605C);
MS2_REPLACE_METHOD(0x14195B490, UIGuideEvent, FUN_14195b490, 156, 0xFFB94B4F);
MS2_REPLACE_METHOD(0x14195B540, UIGuideEvent, FUN_14195b540, 171, 0x84A11ADD);
MS2_REPLACE_METHOD(0x14195B600, UIGuideEvent, FUN_14195b600, 342, 0x9E9CF949);
MS2_REPLACE_METHOD(0x14195B760, UIGuideEvent, FUN_14195b760, 166, 0xB3BB373C);
MS2_REPLACE_METHOD(0x14195B810, UIGuideEvent, FUN_14195b810, 166, 0xC1178F37);
MS2_REPLACE_METHOD(0x14195B8C0, UIGuideEvent, FUN_14195b8c0, 136, 0x51C8B7CD);
MS2_REPLACE_METHOD(0x14195B950, UIGuideEvent, FUN_14195b950, 14, 0x99EEE733);
MS2_REPLACE_METHOD(0x14195BFC0, UIGuideEvent, FUN_14195bfc0, 66, 0x7CE6065D);
