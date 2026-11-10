// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The gfxutil.h helpers that set one property of a named child of a
// movie (text, label, frame, visibility, ...), a per-wrapper-class child search (the six 0x2c1-byte instances), and the
// inline MS2Ptr-shaped handles of those wrapper classes. Continues ?\gemstoneslot.cpp (the first three helpers of the
// header are there). Member and local names are invented from the use. w441.
// MS2-UNIT: unit_140cff310
// MS2-RANGE: 0x1400d1bd0-0x1400d1dd0 .text$di
// MS2-RANGE: 0x140cff310-0x140d03650 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$MS2Ptr@VASDisplayObject@@@@QEAA@H@Z 0x140d02f80 ; unique
// MS2-PIN: ??0?$MS2Ptr@VASDisplayObjectContainer@@@@QEAA@H@Z 0x140d02fd0 ; unique
// MS2-PIN: ??0?$MS2Ptr@VASURLRequest@@@@QEAA@PEAVASURLRequest@@@Z 0x140d03040 ; prop
// MS2-PIN: ??1Unk_AasImagePtr@@QEAA@XZ 0x140d030a0 ; prop
// MS2-PIN: ??C?$MS2Ptr@VASURLRequest@@@@QEBAPEAVASURLRequest@@XZ 0x140d03260
// MS2-PIN: ?AddRef@Unk_TextFieldExPtr@@AEBAXXZ 0x140d032a0 ; prop
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VASURLRequest@@@@AEBAXPEAX@Z 0x140d033e0 ; prop
// MS2-PIN: ?Release@Unk_AasImagePtrView@@QEAAXXZ 0x140d03450 ; prop
// MS2-PIN: ?get@?$MS2Ptr@VASURLRequest@@@@QEBAPEAVASURLRequest@@XZ 0x140d03240
// MS2-PINS-END tplpin
#define MS2_ASSLOT_COPY_EXTERN
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\gfxlib\\gfxutil.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/uitencentaas2dialog.h"
#include "ms2/client/ms2/uiwebbrowser.h"
#include "ms2/client/ms2/camera.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asslot.h"
#include "ms2/placeholder/gfxmovie.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/gfxmanager.h"
#include "ms2/placeholder/asbutton.h"  // C3: ASButton::FUN_1422ce090
#include "ms2/placeholder/aslabel.h"   // C3: ASLabel::FUN_1422e4a50
#include "ms2/gfxui/astextfieldex.h"   // C3: ASTextFieldEx
#include "ms2/gfxui/asurlrequest.h"   // C3: ASURLRequest

// ---- unit-local views of exe objects ----

// The clip whose children are searched by name; the name of the clip itself.
class Unk_NamedClip : public ASMovieClip
{
};

// Image holder of the web page (0x90 bytes). Its source handle is MS2Ptr<ASURLRequest> (instantiated below).
class Unk_AasImage : public AScript {};

// The TextFieldEx / InteractiveObjectEx extension holders.
class Unk_TextFieldEx : public AScript
{
public:
};
class Unk_TextFieldExPtr
{
public:
    Unk_TextFieldExPtr(int);
    Unk_TextFieldExPtr(Unk_TextFieldEx* p);
    ~Unk_TextFieldExPtr();
    Unk_TextFieldEx* get() const;
    Unk_TextFieldEx* operator->() const;
private:
    void AddRef() const;
    void AddRefImpl(void*) const;
    void Release();
    void ReleaseImpl(void*);
    static void Reference(Unk_TextFieldEx* p);
    void* m_0;
    Unk_TextFieldEx* m_p;
};


// Slot data source of the setSlotData helper: three virtual accessors.
class Unk_SlotSource
{
public:
    virtual int vfunc_0();
    virtual int vfunc_1();
    virtual int vfunc_2();
};

// The child clip lookup is uicashattenddialog's Unk_CadNode::FUN_140bc7400<Unk_CadCheck> (0x140bc7450): the exe folds the
// movie clip instantiations into that one body. Its result is MS2Ptr<Unk_CadCheck>; this view of it is MS2Ptr<ASMovieClip>
// for every member, and its dtor is the same body (0x1409b4a90, folded with MS2Ptr<ASMovieClip>'s).
class Unk_CadCheck;
template<> class MS2Ptr<Unk_CadCheck> : public MS2Ptr<ASMovieClip> { public: ~MS2Ptr(); };
class Unk_CadNode : public ASDisplayObjectContainer { public:
    template<class T> MS2Ptr<T> FUN_140bc7400(const CString& strName);
};

// The child lookups every AS container wrapper has (the six deep searches are the 0x2c1-byte instances, one per child
// class). +0x18 the movie id, +0x20 the root value (AScript).
class Unk_Finder : public ASDisplayObjectContainer
{
public:
    MS2Ptr<ASButton> FindButton(const CString& strName);                    // child button
    MS2Ptr<ASCheckBox> FindCheckBox(const CString& strName);                      // child check box
    MS2Ptr<ASDisplayObject> FindDisplayObject(const CString& strName);                  // child display object
    MS2Ptr<ASDisplayObjectContainer> FindDisplayObjectContainer(const CString& strName);         // child container
    MS2Ptr<ASLabel> FindLabel(const CString& strName);                      // child title
    MS2Ptr<ASTextField> FindTextField(const CString& strName);                      // child text field

    MS2Ptr<ASButton> FUN_140d01e70(const Scaleform::GFx::Value& root, const CString& strName);
    MS2Ptr<ASCheckBox> FUN_140d02140(const Scaleform::GFx::Value& root, const CString& strName);
    MS2Ptr<ASDisplayObject> FUN_140d02410(const Scaleform::GFx::Value& root, const CString& strName);
    MS2Ptr<ASDisplayObjectContainer> FUN_140d026e0(const Scaleform::GFx::Value& root, const CString& strName);
    MS2Ptr<ASLabel> FUN_140d029b0(const Scaleform::GFx::Value& root, const CString& strName);
    MS2Ptr<ASTextField> FUN_140d02c80(const Scaleform::GFx::Value& root, const CString& strName);
};

// The Value-wrapping node of a movie is a local ASDisplayObjectContainer (0x80 bytes in the frame (the exe's 0x88 local is the
// node + 8 bytes of slack): ctor 0x1422c6570, dtor 0x1422c65c0); its child lookups go through the Unk_Finder view.
MS2_CHECK_SIZE(ASDisplayObjectContainer, 0x80);

#include <egf/EntityID.h>   // B22: was class Unk_BuddyHandle (ctor 0x1401cd100 = egf::EntityID(efd::UInt64))
// {
// public:
//     Unk_BuddyHandle(void*);
// private:
//     void* m_p;
// };

// ---- out-of-unit callees ----

MS2Ptr<ASDisplayObjectContainer> CreateDisplayObjectContainer(int nMovieId, const Scaleform::GFx::Value& v);
template <class T> MS2Ptr<T> Unk_ASCreate(int nMovieId, const Scaleform::GFx::Value& v);   // C3: was FUN_140acc910 (T = ASButton)
MS2Ptr<ASCheckBox> CreateCheckBox(int nMovieId, const Scaleform::GFx::Value& v);
MS2Ptr<ASLabel> CreateASLabel(int nMovieId, const Scaleform::GFx::Value& v);
MS2Ptr<ASTextField> FUN_1409b41a0(int nMovieId, const Scaleform::GFx::Value& v);

void FUN_1422c6380(Scaleform::GFx::Value& v, int n);
void FUN_1422c63f0(Scaleform::GFx::Value& v, int n);


CStringW GetIconUrl(CStringW str);

// FUN_14025e7a0 (the GFxManager singleton, 0x14025e7a0) is declared in gfxmanager.h
class Unk_AsEx : public AScript
{
public:
};
class Unk_BannerClip   // C3: unit-local view (defs in uibanner); the entity clip's create / update calls
{
public:
    Scaleform::GFx::Value UpdateEntity(const char* szMethod, Scaleform::GFx::Value a1, bool a2); // "updateEntity"
};
UIWebBrowser* FindWebBrowser(int nUiId);

// ---- .text$mn: the movie-child setters ----

// @0x140cff310
void FUN_140cff310(const Scaleform::GFx::Value& root, CString strClip, CString strName, CStringW strText)
{
    if (!((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(root))->IsObject())
        return;
    ASDisplayObjectContainer node(root, 2);
    MS2Ptr<ASDisplayObjectContainer> spClip = static_cast<Unk_Finder&>(node).FindDisplayObjectContainer(strClip);
    if (spClip == 0)
        return;
    MS2Ptr<ASDisplayObject> spText = ((Unk_Finder*)spClip.operator->())->FindDisplayObject(strName);
    if (spText.get() != 0)
        static_cast<ASObj*>(static_cast<AScript*>(spText.operator->()))->SetWStringMember("htmlText", strText);
}

// @0x140cff4e0
void SetButtonText(const Scaleform::GFx::Value& root, CString strName, CStringW strText)
{
    if (!((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(root))->IsObject())
        return;
    ASDisplayObjectContainer node(root, 2);
    MS2Ptr<ASButton> spChild = static_cast<Unk_Finder&>(node).FindButton(strName);
    if (spChild == 0)
        return;
    static_cast<ASButton*>(spChild.operator->())->FUN_1422cdfb0(strText);
}

// @0x140cff610
void SetLabelText(const Scaleform::GFx::Value& root, CString strName, CStringW strText)
{
    if (!((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(root))->IsObject())
        return;
    ASDisplayObjectContainer node(root, 2);
    MS2Ptr<ASLabel> spChild = static_cast<Unk_Finder&>(node).FindLabel(strName);
    if (spChild == 0)
        return;
    reinterpret_cast<ASLabel*>(spChild.operator->())->FUN_1422e4a50(strText);
}

// @0x140cff740
void FUN_140cff740(const Scaleform::GFx::Value& root, CString strName, unsigned int n)
{
    if (!((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(root))->IsObject())
        return;
    ASDisplayObjectContainer node(root, 2);
    MS2Ptr<ASTextField> spChild = static_cast<Unk_Finder&>(node).FindTextField(strName);
    if (spChild == 0)
        return;
    ((class ASTextField*)(class ASTextField*)(spChild.operator->()))->SetTextColor(n);
}

// @0x140cff840
void SetChildVisible(const Scaleform::GFx::Value& root, CString strName, int nVisible)
{
    if (!((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(root))->IsObject())
        return;
    ASDisplayObjectContainer node(root, 2);
    MS2Ptr<Unk_CadCheck> spClip = static_cast<Unk_CadNode&>(node).FUN_140bc7400<Unk_CadCheck>(strName);
    if (spClip == 0)
        return;
    spClip.operator->()->vfunc_3(nVisible);
}

// @0x140cff950
void SetChildEnabled(const Scaleform::GFx::Value& root, CString strName, unsigned int n)
{
    if (!((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(root))->IsObject())
        return;
    ASDisplayObjectContainer node(root, 2);
    MS2Ptr<Unk_CadCheck> spClip = static_cast<Unk_CadNode&>(node).FUN_140bc7400<Unk_CadCheck>(strName);
    if (spClip == 0)
        return;
    spClip.operator->()->SetEnabled(n);
}

// @0x140cffa50
void FUN_140cffa50(const Scaleform::GFx::Value& root, CString strName, CString strLabel)
{
    if (!((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(root))->IsObject())
        return;
    ASDisplayObjectContainer node(root, 2);
    MS2Ptr<Unk_CadCheck> spClip = static_cast<Unk_CadNode&>(node).FUN_140bc7400<Unk_CadCheck>(strName);
    if (spClip == 0)
        return;
    spClip.operator->()->vfunc_13(strLabel);
}

// @0x140cffb90
void FUN_140cffb90(const Scaleform::GFx::Value& root, CString strName, int nFrame)
{
    if (!((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(root))->IsObject())
        return;
    ASDisplayObjectContainer node(root, 2);
    MS2Ptr<Unk_CadCheck> spClip = static_cast<Unk_CadNode&>(node).FUN_140bc7400<Unk_CadCheck>(strName);
    if (spClip == 0)
        return;
    spClip.operator->()->vfunc_12(nFrame);
}

// @0x140cffca0
void FUN_140cffca0(const Scaleform::GFx::Value& root, CString strName, CString strLabel)
{
    if (!((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(root))->IsObject())
        return;
    ASDisplayObjectContainer node(root, 2);
    MS2Ptr<Unk_CadCheck> spClip = static_cast<Unk_CadNode&>(node).FUN_140bc7400<Unk_CadCheck>(strName);
    if (spClip == 0)
        return;
    spClip.operator->()->vfunc_15(strLabel);
}

// @0x140cffde0
void FUN_140cffde0(const Scaleform::GFx::Value& root, CString strName, int nFrame)
{
    if (!((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(root))->IsObject())
        return;
    ASDisplayObjectContainer node(root, 2);
    MS2Ptr<Unk_CadCheck> spClip = static_cast<Unk_CadNode&>(node).FUN_140bc7400<Unk_CadCheck>(strName);
    if (spClip == 0)
        return;
    spClip.operator->()->vfunc_14(nFrame);
}

void FUN_140d00050(const Scaleform::GFx::Value* pRoot, CString strLabel);

// @0x140cffef0
void FUN_140cffef0(const Scaleform::GFx::Value& root, CString strName, CString strLabel)
{
    if (!((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(root))->IsObject())
        return;
    ASDisplayObjectContainer node(root, 2);
    MS2Ptr<Unk_CadCheck> spClip = static_cast<Unk_CadNode&>(node).FUN_140bc7400<Unk_CadCheck>(strName);
    if (spClip == 0)
        return;
    FUN_140d00050(&(*spClip).FUN_1422bb890(), CString(strLabel));
}

// @0x140d00050
void FUN_140d00050(const Scaleform::GFx::Value* pRoot, CString strLabel)
{
    if (!((Scaleform::GFx::Value*)(void*)(pRoot))->IsDisplayObject())
        return;
    ASMovieClip clip(*pRoot, 2);
    if (static_cast<Unk_NamedClip&>(clip).GetName().IsEmpty())
        return;
    clip.vfunc_13(strLabel);
    if (!clip.HasMember("numChildren") || !clip.HasMember("getChildAt"))
        return;
    int nCount = clip.GetNumChildren();
    for (int i = 0; i < nCount; i++)
    {
        Scaleform::GFx::Value child = clip.GetChildAt(i);
        if (!((Scaleform::GFx::Value*)(void*)(&child))->IsDisplayObject())
            continue;
        FUN_140d00050(&child, CString(strLabel));
    }
}

void FUN_140d00360(const Scaleform::GFx::Value& root, CString strName, unsigned a, unsigned b, unsigned c);

// @0x140d00270
void FUN_140d00270(const Scaleform::GFx::Value& root, CString strName, Unk_SlotSource* pSource)
{
    FUN_140d00360(root, CString(strName), pSource->vfunc_0(), pSource->vfunc_1(), pSource->vfunc_2());
}

// @0x140d00360
void FUN_140d00360(const Scaleform::GFx::Value& root, CString strName, unsigned a, unsigned b, unsigned c)
{
    if (!((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(root))->IsObject())
        return;
    ASDisplayObjectContainer node(root, 2);
    MS2Ptr<Unk_CadCheck> spClip = static_cast<Unk_CadNode&>(node).FUN_140bc7400<Unk_CadCheck>(strName);
    if (spClip == 0)
        return;
    ASSlot slot(2);
    if (slot.SetItemById(a, b, c) != 0)
        spClip->Invoke("setSlotData", ASSlot(slot));
}

// @0x140d004f0
void FUN_140d004f0(const Scaleform::GFx::Value& root, CString strName, ASSlot* pSlot)
{
    if (!((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(root))->IsObject())
        return;
    ASDisplayObjectContainer node(root, 2);
    MS2Ptr<Unk_CadCheck> spClip = static_cast<Unk_CadNode&>(node).FUN_140bc7400<Unk_CadCheck>(strName);
    if (spClip == 0)
        return;
    spClip->Invoke("setSlotData", ASSlot(*pSlot));
}

// @0x140d00640
void FUN_140d00640(const Scaleform::GFx::Value& root, CString strName, int nId)
{
    if (!((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(root))->IsObject())
        return;
    ASDisplayObjectContainer node(root, nId);
    MS2Ptr<ASDisplayObject> spChild = static_cast<Unk_Finder&>(node).FindDisplayObject(strName);
    if (spChild == 0)
        return;
    FUN_1422c6380(spChild.operator->()->FUN_1422bb890(), nId);
}

// @0x140d00750
void FUN_140d00750(const Scaleform::GFx::Value& root, CString strName, int nId)
{
    if (!((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(root))->IsObject())
        return;
    ASDisplayObjectContainer node(root, nId);
    MS2Ptr<ASDisplayObject> spChild = static_cast<Unk_Finder&>(node).FindDisplayObject(strName);
    if (spChild == 0)
        return;
    FUN_1422c63f0(spChild.operator->()->FUN_1422bb890(), nId);
}

// @0x140d00860
void FUN_140d00860(const Scaleform::GFx::Value& root, CString strName, int n)
{
    if (!((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(root))->IsObject())
        return;
    ASDisplayObjectContainer node(root, 2);
    MS2Ptr<ASCheckBox> spChild = static_cast<Unk_Finder&>(node).FindCheckBox(strName);
    if (spChild == 0)
        return;
    spChild->SetSelected(n);
}

// @0x140d00960
void FUN_140d00960(const Scaleform::GFx::Value& root, CString strName, unsigned int* pOut)
{
    if (!((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(root))->IsObject())
        return;
    ASDisplayObjectContainer node(root, 2);
    MS2Ptr<ASCheckBox> spChild = static_cast<Unk_Finder&>(node).FindCheckBox(strName);
    if (spChild == 0)
        return;
    *pOut = spChild->IsSelected();
}

// @0x140d00a70
void FUN_140d00a70(const Scaleform::GFx::Value& target, const Scaleform::GFx::Value& anchor, int nGap)
{
    if (!((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(target))->IsObject() || !((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(anchor))->IsObject())
        return;
    ASDisplayObject a(target, 2);
    ASDisplayObject b(anchor, 2);
    float fLeft = b.GetX();
    float fX = fLeft + (float)b.GetWidthCeil() + (float)nGap;
    float fY = b.GetY();
    a.SetPositionFloat(fX, fY);
}

// @0x140d00b80
void SetChildWidth(const Scaleform::GFx::Value& root, CString strName, int n)
{
    if (!((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(root))->IsObject())
        return;
    ASDisplayObjectContainer node(root, 2);
    MS2Ptr<Unk_CadCheck> spClip = static_cast<Unk_CadNode&>(node).FUN_140bc7400<Unk_CadCheck>(strName);
    if (spClip == 0)
        return;
    ((class ASDisplayObject*)(class ASMovieClip*)(spClip.operator->()))->SetWidthInt(n);
}

// @0x140d00c80
void SetChildHeight(const Scaleform::GFx::Value& root, CString strName, int n)
{
    if (!((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(root))->IsObject())
        return;
    ASDisplayObjectContainer node(root, 2);
    MS2Ptr<Unk_CadCheck> spClip = static_cast<Unk_CadNode&>(node).FUN_140bc7400<Unk_CadCheck>(strName);
    if (spClip == 0)
        return;
    ((class ASDisplayObject*)(class ASMovieClip*)(spClip.operator->()))->SetHeightInt(n);
}

// @0x140d00d80
int GetChildWidth(const Scaleform::GFx::Value& root, CString strName)
{
    if (!((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(root))->IsObject())
        return 0;
    ASDisplayObjectContainer node(root, 2);
    MS2Ptr<Unk_CadCheck> spClip = static_cast<Unk_CadNode&>(node).FUN_140bc7400<Unk_CadCheck>(strName);
    if (spClip == 0)
        return 0;
    return spClip.operator->()->GetWidthCeil();
}

// @0x140d00e90
int GetChildTextWidth(const Scaleform::GFx::Value& root, CString strName)
{
    if (!((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(root))->IsObject())
        return 0;
    ASDisplayObjectContainer node(root, 2);
    MS2Ptr<ASTextField> spChild = static_cast<Unk_Finder&>(node).FindTextField(strName);
    if (spChild == 0)
        return 0;
    return (unsigned int)(__int64)((class ASTextField*)(class ASTextField*)(spChild.operator->()))->GetTextWidth();
}

// @0x140d00fb0
void WorldToScreen(Vector3 kWorld, efd::Point2* pScreen)
{
    NiPoint3 kPos;
    if (CameraMgr::GetInstance()->FUN_140af0700(reinterpret_cast<const efd::Point3&>(kWorld), kPos))
    {
        kPos *= GetGFxManager()->GetMovieScale(2);
        *pScreen = efd::Point2(kPos.x, kPos.y);
    }
}

// ---- the alignment names ----

// @0x1400d1bd0
static CString s_strStun2("stun");
// @0x1400d1c00
static CString s_strBottomCenter("bottomCenter");
// @0x1400d1c30
static CString s_strBottomLeft("bottomLeft");
// @0x1400d1c60
static CString s_strBottomRight("bottomRight");
// @0x1400d1c90
static CString s_strCenter("center");
// @0x1400d1cc0
static CString s_strCenterLeft("centerLeft");
// @0x1400d1cf0
static CString s_strCenterRight("centerRight");
// @0x1400d1d20
static CString s_strTopCenter("topCenter");
// @0x1400d1d50
static CString s_strTopLeft("topLeft");
// @0x1400d1d80
static CString s_strTopRight("topRight");
// @0x1400d1db0
static egf::EntityID s_hGfx(0);

// @0x140d01040
int GetAlignFromName(CString& strAlign)
{
    if (strAlign.CompareNoCase(s_strTopLeft) == 0)
        return 5;
    if (strAlign.CompareNoCase(s_strTopCenter) == 0)
        return 1;
    if (strAlign.CompareNoCase(s_strTopRight) == 0)
        return 6;
    if (strAlign.CompareNoCase(s_strCenterLeft) == 0)
        return 3;
    if (strAlign.CompareNoCase(s_strCenter) == 0)
        return 0;
    if (strAlign.CompareNoCase(s_strCenterRight) == 0)
        return 4;
    if (strAlign.CompareNoCase(s_strBottomLeft) == 0)
        return 7;
    if (strAlign.CompareNoCase(s_strBottomCenter) == 0)
        return 2;
    if (strAlign.CompareNoCase(s_strBottomRight) == 0)
        return 8;
    return 0;
}

// ---- the web image holder ----

// @0x140d011c0
void FUN_140d011c0(MS2Ptr<ASLoader> spImage, CStringW strUrl, bool bFlag)
{
    if (spImage == 0)
        return;
    spImage.operator->()->UnloadAndStop(bFlag);
    spImage.operator->()->Load(MS2Ptr<ASURLRequest>(new ASURLRequest(GetIconUrl(CStringW(strUrl)), 2)));
}

extern CString DAT_143b0d350;                                   // "shrink"

Unk_TextFieldExPtr GetTextFieldEx(int nMovieId);

// @0x140d01340
void FUN_140d01340(const Scaleform::GFx::Value& target, unsigned nParam, int nMovieId)
{
    Unk_TextFieldExPtr sp = GetTextFieldEx(nMovieId);
    if (sp.get() != 0)
        reinterpret_cast<ASTextFieldEx*>(sp.operator->())->SetVerticalAlign(target, nParam);
}

// @0x140d013b0
void SetTextAutoSize(const Scaleform::GFx::Value& target, int nMovieId)
{
    Unk_TextFieldExPtr sp = GetTextFieldEx(nMovieId);
    if (sp.get() != 0)
        reinterpret_cast<ASTextFieldEx*>(sp.operator->())->SetTextAutoSize(target, DAT_143b0d350);
}

// @0x140d01420
void SetChildTextAutoSize(const Scaleform::GFx::Value& root, CString strName, int nMovieId)
{
    if (!((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(root))->IsObject())
        return;
    ASDisplayObjectContainer node(root, 2);
    MS2Ptr<Unk_CadCheck> spClip = static_cast<Unk_CadNode&>(node).FUN_140bc7400<Unk_CadCheck>(strName);
    if (spClip == 0)
        return;
    SetTextAutoSize((*spClip).FUN_1422bb890(), nMovieId);
}

// @0x140d01530
Unk_TextFieldExPtr GetTextFieldEx(int nMovieId)
{
    GFxMovie* pMovie = GetGFxManager()->FindMovie(nMovieId);
    if (pMovie != 0)
        return Unk_TextFieldExPtr(reinterpret_cast<Unk_TextFieldEx*>(new ASTextFieldEx(((GFxMovie*)pMovie)->GetDefinitionByName(CString("scaleform.gfx.TextFieldEx")), nMovieId)));
    return Unk_TextFieldExPtr(0);
}

void SetHitTestDisable(const Scaleform::GFx::Value& target, bool bDisable);

// @0x140d01670
void SetChildHitTestDisable(const Scaleform::GFx::Value& root, CString strName, bool bDisable)
{
    if (!((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(root))->IsObject())
        return;
    ASDisplayObjectContainer node(root, 2);
    MS2Ptr<Unk_CadCheck> spClip = static_cast<Unk_CadNode&>(node).FUN_140bc7400<Unk_CadCheck>(strName);
    if (spClip == 0)
        return;
    SetHitTestDisable((*spClip).FUN_1422bb890(), bDisable);
}

// @0x140d01780
void SetHitTestDisable(const Scaleform::GFx::Value& target, bool bDisable)
{
    GFxMovie* pMovie = GetGFxManager()->FindMovie(2);
    if (pMovie != 0)
    {
        MS2Ptr<AScript> sp(new AScript(((GFxMovie*)pMovie)->GetDefinitionByName(CString("scaleform.gfx.InteractiveObjectEx")), 2));
        if (sp->IsUndefinedOrNull())
            return;
        ((Unk_BannerClip*)sp.operator->())->UpdateEntity("setHitTestDisable", Scaleform::GFx::Value(target), bDisable);
    }
}

// @0x140d01960
void FUN_140d01960(CString strKey)
{
    UIWebBrowser* pBrowser = FindWebBrowser(0x4e6a);
    if (pBrowser != 0)
        pBrowser->NavigateToGuide(strKey);
}

// @0x140d019b0
MS2Ptr<AScript> FUN_140d019b0(MS2Ptr<AScript> spObj, const CString& strName)
{
    if (spObj == 0)
        return MS2Ptr<AScript>(0);
    if (strName.IsEmpty() == true)
        return MS2Ptr<AScript>(0);
    MS2Ptr<AScript> sp(new AScript(spObj.operator->()->GetMember(strName), 2));
    if (sp == 0 || sp->IsUndefinedOrNull() == true)
        return MS2Ptr<AScript>(0);
    return sp;
}

// @0x140d01be0
MS2Ptr<ASDisplayObject> CreateDisplayObject(int nMovieId, const Scaleform::GFx::Value& v)
{
    MS2Ptr<ASDisplayObject> sp(new ASDisplayObject(v, nMovieId));
    return sp;
}

// @0x140d01c90
MS2Ptr<ASButton> Unk_Finder::FindButton(const CString& strName)
{
    return FUN_140d01e70(m_value, strName);
}

// @0x140d01ce0
MS2Ptr<ASCheckBox> Unk_Finder::FindCheckBox(const CString& strName)
{
    return FUN_140d02140(m_value, strName);
}

// @0x140d01d30
MS2Ptr<ASDisplayObject> Unk_Finder::FindDisplayObject(const CString& strName)
{
    return FUN_140d02410(m_value, strName);
}

// @0x140d01d80
MS2Ptr<ASDisplayObjectContainer> Unk_Finder::FindDisplayObjectContainer(const CString& strName)
{
    return FUN_140d026e0(m_value, strName);
}

// @0x140d01dd0
MS2Ptr<ASLabel> Unk_Finder::FindLabel(const CString& strName)
{
    return FUN_140d029b0(m_value, strName);
}

// @0x140d01e20
MS2Ptr<ASTextField> Unk_Finder::FindTextField(const CString& strName)
{
    return FUN_140d02c80(m_value, strName);
}
// uicashshopdialog's Unk_CashChildFinder::FindTextField<ASUIComponent> (call at 0x14103a812) is this same body: the exe
// folds the getChildByName<T> instantiations into one copy, so its declared name is bound here.
#ifndef MS2_HOOK_DLL
#pragma comment(linker, "/alternatename:??$FindTextField@VASUIComponent@@@Unk_CashChildFinder@@QEAA?AV?$MS2Ptr@VASUIComponent@@@@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z=?FindTextField@Unk_Finder@@QEAA?AV?$MS2Ptr@VASTextField@@@@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z")
#endif

// The six deep searches: getChildByName on the root, else the same search in each child.
#define MS2_FINDER_DEEP(VA, NAME, T, CREATE)                                                                       \
    /* @0x ## VA */                                                                                              \
    MS2Ptr<T> Unk_Finder::NAME(const Scaleform::GFx::Value& root, const CString& strName)                           \
    {                                                                                                              \
        MS2Ptr<ASDisplayObjectContainer> spCont = CreateDisplayObjectContainer(m_nMovieId, root);                                 \
        if (!spCont->HasMember("getChildByName"))                                                              \
            return MS2Ptr<T>(0);                                                                                   \
        Scaleform::GFx::Value child = spCont->GetChildByName(strName);                                              \
        if (((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(child))->IsObject())                                                                                  \
            return CREATE(m_nMovieId, child);                                                                      \
        if (!spCont->HasMember("numChildren"))                                                                 \
            return MS2Ptr<T>(0);                                                                                   \
        int nCount = spCont->GetNumChildren();                                                                      \
        for (int i = 0; i < nCount; i++)                                                                           \
        {                                                                                                          \
            Scaleform::GFx::Value sub = spCont->GetChildAt(i);                                                  \
            if (!((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(sub))->IsObject())                                                                               \
                continue;                                                                                          \
            MS2Ptr<T> sp = NAME(sub, strName);                                                                     \
            if (sp.get() != 0)                                                                                     \
                return sp;                                                                                         \
        }                                                                                                          \
        return MS2Ptr<T>(0);                                                                                       \
    }

// @0x140d01e70
MS2_FINDER_DEEP(140d01e70, FUN_140d01e70, ASButton, Unk_ASCreate<ASButton>)
// @0x140d02140
MS2_FINDER_DEEP(140d02140, FUN_140d02140, ASCheckBox, CreateCheckBox)
// @0x140d02410
MS2_FINDER_DEEP(140d02410, FUN_140d02410, ASDisplayObject, CreateDisplayObject)
// @0x140d026e0
MS2_FINDER_DEEP(140d026e0, FUN_140d026e0, ASDisplayObjectContainer, CreateDisplayObjectContainer)
// @0x140d029b0
MS2_FINDER_DEEP(140d029b0, FUN_140d029b0, ASLabel, CreateASLabel)
// @0x140d02c80
MS2_FINDER_DEEP(140d02c80, FUN_140d02c80, ASTextField, FUN_1409b41a0)

// ---- the inline handles of this unit ----

// The MS2Ptr-shaped handle of the page image (the same shapes as MS2Ptr<T>; ~Unk_AasImagePtr is the exe's 0x140d030a0).
struct Unk_AasImagePtrView
{
    void* m_0;
    Unk_AasImage* m_p;
    bool operator==(Unk_AasImage* p) const { return m_p == p; }
    Unk_AasImage* get() const { return m_p; }
    void Release();
    void ReleaseImpl(void*);
    static void Reference(Unk_AasImage* p);
};
void Unk_AasImagePtrView::Reference(Unk_AasImage* p) { CPtred::AddRefPtred(p); }
void Unk_AasImagePtrView::ReleaseImpl(void*)
{
    if (CPtred::ReleasePtred(m_p) == 0)
    {
        Reference(m_p);
        CPtred::DeletePtred(m_p);
    }
}
void Unk_AasImagePtrView::Release()
{
    if (m_p)
    {
        ReleaseImpl(0);
        m_p = 0;
    }
}
Unk_AasImagePtr::~Unk_AasImagePtr() { ((Unk_AasImagePtrView*)this)->Release(); }
bool Unk_AasImagePtr::operator==(Unk_AasImage* p) const { return m_p == p; }
void FUN_140d03450(Unk_AasImagePtr* p) { ((Unk_AasImagePtrView*)p)->Release(); }
void FUN_140d03320(Unk_AasImage* p) { Unk_AasImagePtrView::Reference(p); }

// The text-field-extension handle and the image source handle (the same shapes as MS2Ptr<T>).
#define MS2_UNK_PTR_IMPL(P, T)                                                  \
    P::P(T* p) { m_p = p; AddRef(); }                                           \
    P::~P() { Release(); }                                                      \
    T* P::get() const { return m_p; }                                           \
    T* P::operator->() const { return m_p; }                                    \
    void P::AddRef() const { if (m_p) AddRefImpl(0); }                          \
    void P::AddRefImpl(void*) const { Reference(m_p); }                         \
    void P::Reference(T* p) { CPtred::AddRefPtred(p); }                         \
    void P::Release()                                                           \
    {                                                                           \
        if (m_p)                                                                \
        {                                                                       \
            ReleaseImpl(0);                                                     \
            m_p = 0;                                                            \
        }                                                                       \
    }                                                                           \
    void P::ReleaseImpl(void*)                                                  \
    {                                                                           \
        if (CPtred::ReleasePtred(m_p) == 0)                                     \
        {                                                                       \
            Reference(m_p);                                                     \
            CPtred::DeletePtred(m_p);                                           \
        }                                                                       \
    }

Unk_TextFieldExPtr::Unk_TextFieldExPtr(int) { m_p = 0; }
MS2_UNK_PTR_IMPL(Unk_TextFieldExPtr, Unk_TextFieldEx)
// The image source handle: MS2Ptr<ASURLRequest> (the ASLoader::Load argument, 0x1422e5530 destroys it with 0x140d03100).
template MS2Ptr<ASURLRequest>::MS2Ptr(ASURLRequest*);
template MS2Ptr<ASURLRequest>::~MS2Ptr();
template ASURLRequest* MS2Ptr<ASURLRequest>::get() const;
template ASURLRequest* MS2Ptr<ASURLRequest>::operator->() const;
template void MS2Ptr<ASURLRequest>::AddRef() const;
template void MS2Ptr<ASURLRequest>::Reference(ASURLRequest*);
template void MS2Ptr<ASURLRequest>::AddRefImpl(void*) const;
template void MS2Ptr<ASURLRequest>::Release();
template void MS2Ptr<ASURLRequest>::ReleaseImpl(void*);

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca4800-0x142ca4940 .text$yd
