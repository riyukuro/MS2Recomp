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
// MS2-PIN: ??0Unk_AasSourcePtr@@QEAA@PEAVUnk_AasSource@@@Z 0x140d03040 ; prop
// MS2-PIN: ??1Unk_AasImagePtr@@QEAA@XZ 0x140d030a0 ; prop
// MS2-PIN: ?AddRef@Unk_TextFieldExPtr@@AEBAXXZ 0x140d032a0 ; prop
// MS2-PIN: ?AddRefImpl@Unk_AasSourcePtr@@AEBAXPEAX@Z 0x140d033e0 ; prop
// MS2-PIN: ?Release@Unk_AasImagePtrView@@QEAAXXZ 0x140d03450 ; prop
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

// ---- unit-local views of exe objects ----

// A display object built on the stack (ctor 0x1422bf7c0, dtor 0x1422bf810).
class Unk_Disp : public ASDisplayObject
{
public:
    Unk_Disp(const Scaleform::GFx::Value& v, int nMovieId);
    ~Unk_Disp();
};

// A button (the wrapper class of 0x140acd6e0).
class Unk_140acd6e0 : public ASDisplayObject
{
public:
    void FUN_1422c1fe0(unsigned int bEnabled);          // enable / disable
    void FUN_1422cdfb0(const CStringW& strLabel);       // set the label
    void FUN_1422ce090(int n);                          // set the state
};

// A check box (the wrapper class of 0x140a58300).
class Unk_GpCheck : public ASDisplayObject
{
public:
    void FUN_1422ce090(int n);                          // set the checked state
    unsigned char FUN_1422ce0e0();                      // is checked
};

// A title text (the wrapper class of 0x140c45e20).
class Unk_WcTitle : public ASDisplayObject
{
public:
    void FUN_1422e4a50(const CStringW& strText);        // set the text
};

// The clip whose children are searched by name; the name of the clip itself.
class Unk_NamedClip : public ASMovieClip
{
public:
    CString FUN_1422ba8c0();                            // the instance name
};

// Image holder of the web page (0x90 bytes) and its source object / handle.
class Unk_AasImage : public AScript {};
class Unk_AasSource : public CPtred {};
class Unk_AasSourcePtr
{
public:
    Unk_AasSourcePtr(Unk_AasSource* p);
    ~Unk_AasSourcePtr();
    Unk_AasSource* get() const;
    Unk_AasSource* operator->() const;
    void* m_0;
    Unk_AasSource* m_p;
private:
    void AddRef() const;
    void AddRefImpl(void*) const;
    void Release();
    void ReleaseImpl(void*);
    static void Reference(Unk_AasSource* p);
};

// The TextFieldEx / InteractiveObjectEx extension holders.
class Unk_TextFieldEx : public AScript
{
public:
    Unk_TextFieldEx(const Scaleform::GFx::Value& v, int nMovieId);
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

// The child lookups every AS container wrapper has (the six deep searches are the 0x2c1-byte instances, one per child
// class). +0x18 the movie id, +0x20 the root value (AScript).
class Unk_Finder : public ASDisplayObjectContainer
{
public:
    MS2Ptr<ASMovieClip> FUN_140bc7450(const CString& strName);                      // child clip by name (another unit)
    MS2Ptr<Unk_140acd6e0> FUN_140d01c90(const CString& strName);                    // child button
    MS2Ptr<Unk_GpCheck> FUN_140d01ce0(const CString& strName);                      // child check box
    MS2Ptr<ASDisplayObject> FUN_140d01d30(const CString& strName);                  // child display object
    MS2Ptr<ASDisplayObjectContainer> FUN_140d01d80(const CString& strName);         // child container
    MS2Ptr<Unk_WcTitle> FUN_140d01dd0(const CString& strName);                      // child title
    MS2Ptr<ASTextField> FUN_140d01e20(const CString& strName);                      // child text field

    MS2Ptr<Unk_140acd6e0> FUN_140d01e70(const Scaleform::GFx::Value& root, const CString& strName);
    MS2Ptr<Unk_GpCheck> FUN_140d02140(const Scaleform::GFx::Value& root, const CString& strName);
    MS2Ptr<ASDisplayObject> FUN_140d02410(const Scaleform::GFx::Value& root, const CString& strName);
    MS2Ptr<ASDisplayObjectContainer> FUN_140d026e0(const Scaleform::GFx::Value& root, const CString& strName);
    MS2Ptr<Unk_WcTitle> FUN_140d029b0(const Scaleform::GFx::Value& root, const CString& strName);
    MS2Ptr<ASTextField> FUN_140d02c80(const Scaleform::GFx::Value& root, const CString& strName);
};

// The Value-wrapping node of a movie (0x80 bytes in the frame (the exe's 0x88 local is the node + 8 bytes of slack): ctor 0x1422c6570, dtor 0x1422c65c0).
class Unk_GemNode : public Unk_Finder
{
public:
    Unk_GemNode(const Scaleform::GFx::Value& v, int nMovieId);
    ~Unk_GemNode();
};
MS2_CHECK_SIZE(Unk_GemNode, 0x80);

class Unk_Handle1401cd100
{
public:
    Unk_Handle1401cd100(int n);
    void* m_p;
};

// ---- out-of-unit callees ----
bool FUN_1409b4d40(const Scaleform::GFx::Value& v);                         // the value is an object
bool FUN_1407cce10(const Scaleform::GFx::Value* p);                         // the value is a display object

MS2Ptr<ASDisplayObjectContainer> FUN_140bc5fc0(int nMovieId, const Scaleform::GFx::Value& v);
MS2Ptr<Unk_140acd6e0> FUN_140acc910(int nMovieId, const Scaleform::GFx::Value& v);
MS2Ptr<Unk_GpCheck> FUN_140a57df0(int nMovieId, const Scaleform::GFx::Value& v);
MS2Ptr<Unk_WcTitle> FUN_140c43580(int nMovieId, const Scaleform::GFx::Value& v);
MS2Ptr<ASTextField> FUN_1409b41a0(int nMovieId, const Scaleform::GFx::Value& v);

void FUN_1422cdfb0(Unk_140acd6e0* p, const CStringW& str);
void FUN_1422e4a50(Unk_WcTitle* p, const CStringW& str);
void FUN_1422c50e0(ASTextField* p, unsigned int n);
void FUN_1422c1fe0(ASMovieClip* p, unsigned int n);
void FUN_1422c6380(Scaleform::GFx::Value& v, int n);
void FUN_1422c63f0(Scaleform::GFx::Value& v, int n);
void FUN_1422ce090(Unk_GpCheck* p, int n);
unsigned char FUN_1422ce0e0(Unk_GpCheck* p);
void FUN_1422c0e20(ASMovieClip* p, int n);
void FUN_1422c0ec0(ASMovieClip* p, int n);
int FUN_1422c1340(ASMovieClip* p);
double FUN_1422c5970(ASTextField* p);

int FUN_1409c4510(ASSlot* p, unsigned a, unsigned b, unsigned c);
Scaleform::GFx::Value FUN_1409bb460(AScript* p, const char* szMethod, ASSlot slot);

void FUN_1422e55c0(Unk_AasImage* p, bool b);
void FUN_1422e5530(Unk_AasImage* p, const Unk_AasSourcePtr& sp);
CStringW FUN_1422e5b80(CStringW str);
void* FUN_1422e5a70(void* pMem, CStringW strUrl, int nMovieId);
void FUN_1422e5060(Unk_TextFieldEx* p, const Scaleform::GFx::Value& v, unsigned n);
void FUN_1422e5110(Unk_TextFieldEx* p, const Scaleform::GFx::Value& v, const CString& strMode);
Unk_TextFieldEx* FUN_1422e4fd0(void* pMem, const Scaleform::GFx::Value& v, int nMovieId);

class Unk_UiMgr
{
public:
    float FUN_1422afec0(int nUiId);                         // the ui scale of a movie
    GFxMovie* FUN_1422b01a0(int nUiId);                     // the movie of a ui id
};
Unk_UiMgr* FUN_14025e7a0();
class Unk_GfxMovie
{
public:
    Scaleform::GFx::Value FUN_1422bd120(const CString& strClass);   // the AS class object of a name
};
class Unk_AsEx : public AScript
{
public:
    Scaleform::GFx::Value FUN_140ba9570(const char* szMethod, Scaleform::GFx::Value a1, bool a2);
};
UIWebBrowser* FUN_140c43790(int nUiId);

// ---- .text$mn: the movie-child setters ----

// @0x140cff310
void FUN_140cff310(const Scaleform::GFx::Value& root, CString strClip, CString strName, CStringW strText)
{
    if (!FUN_1409b4d40(root))
        return;
    Unk_GemNode node(root, 2);
    MS2Ptr<ASDisplayObjectContainer> spClip = node.FUN_140d01d80(strClip);
    if (spClip == 0)
        return;
    MS2Ptr<ASDisplayObject> spText = ((Unk_Finder*)spClip.operator->())->FUN_140d01d30(strName);
    if (spText.get() != 0)
        static_cast<ASObj*>(static_cast<AScript*>(spText.operator->()))->FUN_1407cbb20("htmlText", strText);
}

// @0x140cff4e0
void FUN_140cff4e0(const Scaleform::GFx::Value& root, CString strName, CStringW strText)
{
    if (!FUN_1409b4d40(root))
        return;
    Unk_GemNode node(root, 2);
    MS2Ptr<Unk_140acd6e0> spChild = node.FUN_140d01c90(strName);
    if (spChild == 0)
        return;
    FUN_1422cdfb0(spChild.operator->(), strText);
}

// @0x140cff610
void FUN_140cff610(const Scaleform::GFx::Value& root, CString strName, CStringW strText)
{
    if (!FUN_1409b4d40(root))
        return;
    Unk_GemNode node(root, 2);
    MS2Ptr<Unk_WcTitle> spChild = node.FUN_140d01dd0(strName);
    if (spChild == 0)
        return;
    FUN_1422e4a50(spChild.operator->(), strText);
}

// @0x140cff740
void FUN_140cff740(const Scaleform::GFx::Value& root, CString strName, unsigned int n)
{
    if (!FUN_1409b4d40(root))
        return;
    Unk_GemNode node(root, 2);
    MS2Ptr<ASTextField> spChild = node.FUN_140d01e20(strName);
    if (spChild == 0)
        return;
    FUN_1422c50e0(spChild.operator->(), n);
}

// @0x140cff840
void FUN_140cff840(const Scaleform::GFx::Value& root, CString strName, int nVisible)
{
    if (!FUN_1409b4d40(root))
        return;
    Unk_GemNode node(root, 2);
    MS2Ptr<ASMovieClip> spClip = node.FUN_140bc7450(strName);
    if (spClip == 0)
        return;
    spClip.operator->()->vfunc_3(nVisible);
}

// @0x140cff950
void FUN_140cff950(const Scaleform::GFx::Value& root, CString strName, unsigned int n)
{
    if (!FUN_1409b4d40(root))
        return;
    Unk_GemNode node(root, 2);
    MS2Ptr<ASMovieClip> spClip = node.FUN_140bc7450(strName);
    if (spClip == 0)
        return;
    FUN_1422c1fe0(spClip.operator->(), n);
}

// @0x140cffa50
void FUN_140cffa50(const Scaleform::GFx::Value& root, CString strName, CString strLabel)
{
    if (!FUN_1409b4d40(root))
        return;
    Unk_GemNode node(root, 2);
    MS2Ptr<ASMovieClip> spClip = node.FUN_140bc7450(strName);
    if (spClip == 0)
        return;
    spClip.operator->()->vfunc_13(strLabel);
}

// @0x140cffb90
void FUN_140cffb90(const Scaleform::GFx::Value& root, CString strName, int nFrame)
{
    if (!FUN_1409b4d40(root))
        return;
    Unk_GemNode node(root, 2);
    MS2Ptr<ASMovieClip> spClip = node.FUN_140bc7450(strName);
    if (spClip == 0)
        return;
    spClip.operator->()->vfunc_12(nFrame);
}

// @0x140cffca0
void FUN_140cffca0(const Scaleform::GFx::Value& root, CString strName, CString strLabel)
{
    if (!FUN_1409b4d40(root))
        return;
    Unk_GemNode node(root, 2);
    MS2Ptr<ASMovieClip> spClip = node.FUN_140bc7450(strName);
    if (spClip == 0)
        return;
    spClip.operator->()->vfunc_15(strLabel);
}

// @0x140cffde0
void FUN_140cffde0(const Scaleform::GFx::Value& root, CString strName, int nFrame)
{
    if (!FUN_1409b4d40(root))
        return;
    Unk_GemNode node(root, 2);
    MS2Ptr<ASMovieClip> spClip = node.FUN_140bc7450(strName);
    if (spClip == 0)
        return;
    spClip.operator->()->vfunc_14(nFrame);
}

void FUN_140d00050(const Scaleform::GFx::Value* pRoot, CString strLabel);

// @0x140cffef0
void FUN_140cffef0(const Scaleform::GFx::Value& root, CString strName, CString strLabel)
{
    if (!FUN_1409b4d40(root))
        return;
    Unk_GemNode node(root, 2);
    MS2Ptr<ASMovieClip> spClip = node.FUN_140bc7450(strName);
    if (spClip == 0)
        return;
    FUN_140d00050(&(*spClip).FUN_1422bb890(), CString(strLabel));
}

// @0x140d00050
// MS2-FUNCTIONAL: written against the exe callees
void FUN_140d00050(const Scaleform::GFx::Value* pRoot, CString strLabel)
{
    if (!FUN_1407cce10(pRoot))
        return;
    Scaleform::GFx::Value copy(*pRoot);
    ASMovieClip clip(copy, 2);
    if (static_cast<Unk_NamedClip&>(clip).FUN_1422ba8c0().IsEmpty())
        return;
    clip.vfunc_13(strLabel);
    if (clip.FUN_1422ba9f0("numChildren") && clip.FUN_1422ba9f0("getChildAt"))
    {
        int nCount = clip.FUN_1422c6670();
        for (int i = 0; i < nCount; i++)
        {
            Scaleform::GFx::Value child = clip.FUN_1422c6aa0(i);
            if (FUN_1407cce10(&child))
                FUN_140d00050(&child, CString(strLabel));
        }
    }
}

void FUN_140d00360(const Scaleform::GFx::Value& root, CString strName, unsigned a, unsigned b, unsigned c);

// @0x140d00270
void FUN_140d00270(const Scaleform::GFx::Value& root, CString strName, Unk_SlotSource* pSource)
{
    unsigned c = pSource->vfunc_2();
    unsigned b = pSource->vfunc_1();
    unsigned a = pSource->vfunc_0();
    FUN_140d00360(root, CString(strName), a, b, c);
}

// @0x140d00360
// MS2-FUNCTIONAL: written against the exe callees
void FUN_140d00360(const Scaleform::GFx::Value& root, CString strName, unsigned a, unsigned b, unsigned c)
{
    if (!FUN_1409b4d40(root))
        return;
    Unk_GemNode node(root, 2);
    MS2Ptr<ASMovieClip> spClip = node.FUN_140bc7450(strName);
    if (spClip == 0)
        return;
    ASSlot slot(2);
    if (FUN_1409c4510(&slot, a, b, c) != 0)
        FUN_1409bb460(spClip.operator->(), "setSlotData", ASSlot(slot));
}

// @0x140d004f0
// MS2-FUNCTIONAL: written against the exe callees
void FUN_140d004f0(const Scaleform::GFx::Value& root, CString strName, ASSlot* pSlot)
{
    if (!FUN_1409b4d40(root))
        return;
    Unk_GemNode node(root, 2);
    MS2Ptr<ASMovieClip> spClip = node.FUN_140bc7450(strName);
    if (spClip == 0)
        return;
    FUN_1409bb460(spClip.operator->(), "setSlotData", ASSlot(*pSlot));
}

// @0x140d00640
void FUN_140d00640(const Scaleform::GFx::Value& root, CString strName, int nId)
{
    if (!FUN_1409b4d40(root))
        return;
    Unk_GemNode node(root, nId);
    MS2Ptr<ASDisplayObject> spChild = node.FUN_140d01d30(strName);
    if (spChild == 0)
        return;
    FUN_1422c6380(spChild.operator->()->FUN_1422bb890(), nId);
}

// @0x140d00750
void FUN_140d00750(const Scaleform::GFx::Value& root, CString strName, int nId)
{
    if (!FUN_1409b4d40(root))
        return;
    Unk_GemNode node(root, nId);
    MS2Ptr<ASDisplayObject> spChild = node.FUN_140d01d30(strName);
    if (spChild == 0)
        return;
    FUN_1422c63f0(spChild.operator->()->FUN_1422bb890(), nId);
}

// @0x140d00860
void FUN_140d00860(const Scaleform::GFx::Value& root, CString strName, int n)
{
    if (!FUN_1409b4d40(root))
        return;
    Unk_GemNode node(root, 2);
    MS2Ptr<Unk_GpCheck> spChild = node.FUN_140d01ce0(strName);
    if (spChild == 0)
        return;
    FUN_1422ce090(spChild.operator->(), n);
}

// @0x140d00960
void FUN_140d00960(const Scaleform::GFx::Value& root, CString strName, unsigned int* pOut)
{
    if (!FUN_1409b4d40(root))
        return;
    Unk_GemNode node(root, 2);
    MS2Ptr<Unk_GpCheck> spChild = node.FUN_140d01ce0(strName);
    if (spChild == 0)
        return;
    *pOut = FUN_1422ce0e0(spChild.operator->());
}

// @0x140d00a70
void FUN_140d00a70(const Scaleform::GFx::Value& target, const Scaleform::GFx::Value& anchor, int nGap)
{
    if (!FUN_1409b4d40(target) || !FUN_1409b4d40(anchor))
        return;
    Unk_Disp a(target, 2);
    Unk_Disp b(anchor, 2);
    float fLeft = b.FUN_1422c10a0();
    float fX = fLeft + (float)b.FUN_1422c1340() + (float)nGap;
    float fY = b.FUN_1422c1110();
    a.FUN_1422c00f0(fX, fY);
}

// @0x140d00b80
void FUN_140d00b80(const Scaleform::GFx::Value& root, CString strName, int n)
{
    if (!FUN_1409b4d40(root))
        return;
    Unk_GemNode node(root, 2);
    MS2Ptr<ASMovieClip> spClip = node.FUN_140bc7450(strName);
    if (spClip == 0)
        return;
    FUN_1422c0e20(spClip.operator->(), n);
}

// @0x140d00c80
void FUN_140d00c80(const Scaleform::GFx::Value& root, CString strName, int n)
{
    if (!FUN_1409b4d40(root))
        return;
    Unk_GemNode node(root, 2);
    MS2Ptr<ASMovieClip> spClip = node.FUN_140bc7450(strName);
    if (spClip == 0)
        return;
    FUN_1422c0ec0(spClip.operator->(), n);
}

// @0x140d00d80
int FUN_140d00d80(const Scaleform::GFx::Value& root, CString strName)
{
    if (!FUN_1409b4d40(root))
        return 0;
    Unk_GemNode node(root, 2);
    MS2Ptr<ASMovieClip> spClip = node.FUN_140bc7450(strName);
    if (spClip == 0)
        return 0;
    return FUN_1422c1340(spClip.operator->());
}

// @0x140d00e90
int FUN_140d00e90(const Scaleform::GFx::Value& root, CString strName)
{
    if (!FUN_1409b4d40(root))
        return 0;
    Unk_GemNode node(root, 2);
    MS2Ptr<ASTextField> spChild = node.FUN_140d01e20(strName);
    if (spChild == 0)
        return 0;
    return (unsigned int)(__int64)FUN_1422c5970(spChild.operator->());
}

// @0x140d00fb0
void FUN_140d00fb0(const efd::Point3& kWorld, efd::Point2* pScreen)
{
    NiPoint3 kPos;
    if (CameraMgr::GetInstance()->FUN_140af0700(kWorld, kPos))
    {
        kPos *= FUN_14025e7a0()->FUN_1422afec0(2);
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
static Unk_Handle1401cd100 s_hGfx(0);

// @0x140d01040
int FUN_140d01040(CString& strAlign)
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
// MS2-FUNCTIONAL: written against the exe callees
void FUN_140d011c0(Unk_AasImagePtr spImage, CStringW strUrl, bool bFlag)
{
    if (spImage.get() == 0)
        return;
    FUN_1422e55c0(spImage.operator->(), bFlag);
    void* pMem = operator new(0x40);
    Unk_AasSource* pSource = pMem ? (Unk_AasSource*)FUN_1422e5a70(pMem, FUN_1422e5b80(CStringW(strUrl)), 2) : 0;
    Unk_AasSourcePtr sp(pSource);
    FUN_1422e5530(spImage.operator->(), sp);
}

extern CString DAT_143b0d350;                                   // "shrink"

Unk_TextFieldExPtr FUN_140d01530(int nMovieId);

// @0x140d01340
// MS2-FUNCTIONAL: written against the exe callees
void FUN_140d01340(const Scaleform::GFx::Value& target, unsigned nParam, int nMovieId)
{
    Unk_TextFieldExPtr sp = FUN_140d01530(nMovieId);
    if (sp.get() != 0)
        FUN_1422e5060(sp.operator->(), target, nParam);
}

// @0x140d013b0
// MS2-FUNCTIONAL: written against the exe callees
void FUN_140d013b0(const Scaleform::GFx::Value& target, int nMovieId)
{
    Unk_TextFieldExPtr sp = FUN_140d01530(nMovieId);
    if (sp.get() != 0)
        FUN_1422e5110(sp.operator->(), target, DAT_143b0d350);
}

// @0x140d01420
void FUN_140d01420(const Scaleform::GFx::Value& root, CString strName, int nMovieId)
{
    if (!FUN_1409b4d40(root))
        return;
    Unk_GemNode node(root, 2);
    MS2Ptr<ASMovieClip> spClip = node.FUN_140bc7450(strName);
    if (spClip == 0)
        return;
    FUN_140d013b0((*spClip).FUN_1422bb890(), nMovieId);
}

// @0x140d01530
// MS2-FUNCTIONAL: written against the exe callees
Unk_TextFieldExPtr FUN_140d01530(int nMovieId)
{
    unsigned nDummy = 0;
    GFxMovie* pMovie = FUN_14025e7a0()->FUN_1422b01a0(nMovieId);
    if (pMovie == 0)
        return Unk_TextFieldExPtr(0);
    void* pMem = operator new(0x40);
    Unk_TextFieldEx* p = 0;
    if (pMem)
        p = FUN_1422e4fd0(pMem, ((Unk_GfxMovie*)pMovie)->FUN_1422bd120(CString("scaleform.gfx.TextFieldEx")), nMovieId);
    return Unk_TextFieldExPtr(p);
}

void FUN_140d01780(const Scaleform::GFx::Value& target, bool bDisable);

// @0x140d01670
void FUN_140d01670(const Scaleform::GFx::Value& root, CString strName, bool bDisable)
{
    if (!FUN_1409b4d40(root))
        return;
    Unk_GemNode node(root, 2);
    MS2Ptr<ASMovieClip> spClip = node.FUN_140bc7450(strName);
    if (spClip == 0)
        return;
    FUN_140d01780((*spClip).FUN_1422bb890(), bDisable);
}

// @0x140d01780
// MS2-FUNCTIONAL: written against the exe callees
void FUN_140d01780(const Scaleform::GFx::Value& target, bool bDisable)
{
    GFxMovie* pMovie = FUN_14025e7a0()->FUN_1422b01a0(2);
    if (pMovie == 0)
        return;
    void* pMem = operator new(0x40);
    AScript* p = 0;
    if (pMem)
        p = new (pMem) AScript(((Unk_GfxMovie*)pMovie)->FUN_1422bd120(CString("scaleform.gfx.InteractiveObjectEx")), 2);
    MS2Ptr<AScript> sp(p);
    if (!sp->FUN_1422ba9a0())
        ((Unk_AsEx*)sp.operator->())->FUN_140ba9570("setHitTestDisable", Scaleform::GFx::Value(target), bDisable);
}

// @0x140d01960
void FUN_140d01960(CString strKey)
{
    UIWebBrowser* pBrowser = FUN_140c43790(0x4e6a);
    if (pBrowser != 0)
        pBrowser->FUN_141b50490(strKey);
}

// @0x140d019b0
// MS2-FUNCTIONAL: written against the exe callees
MS2Ptr<AScript> FUN_140d019b0(MS2Ptr<AScript> spObj, const CString& strName)
{
    if (spObj == 0)
        return MS2Ptr<AScript>(0);
    if (strName.IsEmpty())
        return MS2Ptr<AScript>(0);
    void* pMem = operator new(0x40);
    AScript* p = 0;
    if (pMem)
        p = new (pMem) AScript(spObj.operator->()->FUN_1422baa20(strName), 2);
    MS2Ptr<AScript> sp(p);
    if (sp == 0)
        return MS2Ptr<AScript>(0);
    if (!sp->FUN_1422ba9a0())
        return sp;
    return MS2Ptr<AScript>(0);
}

// @0x140d01be0
MS2Ptr<ASDisplayObject> FUN_140d01be0(int nMovieId, const Scaleform::GFx::Value& v)
{
    MS2Ptr<ASDisplayObject> sp(new Unk_Disp(v, nMovieId));
    return sp;
}

// @0x140d01c90
MS2Ptr<Unk_140acd6e0> Unk_Finder::FUN_140d01c90(const CString& strName)
{
    return FUN_140d01e70(m_value, strName);
}

// @0x140d01ce0
MS2Ptr<Unk_GpCheck> Unk_Finder::FUN_140d01ce0(const CString& strName)
{
    return FUN_140d02140(m_value, strName);
}

// @0x140d01d30
MS2Ptr<ASDisplayObject> Unk_Finder::FUN_140d01d30(const CString& strName)
{
    return FUN_140d02410(m_value, strName);
}

// @0x140d01d80
MS2Ptr<ASDisplayObjectContainer> Unk_Finder::FUN_140d01d80(const CString& strName)
{
    return FUN_140d026e0(m_value, strName);
}

// @0x140d01dd0
MS2Ptr<Unk_WcTitle> Unk_Finder::FUN_140d01dd0(const CString& strName)
{
    return FUN_140d029b0(m_value, strName);
}

// @0x140d01e20
MS2Ptr<ASTextField> Unk_Finder::FUN_140d01e20(const CString& strName)
{
    return FUN_140d02c80(m_value, strName);
}

// The six deep searches: getChildByName on the root, else the same search in each child.
#define MS2_FINDER_DEEP(VA, NAME, T, CREATE)                                                                       \
    /* @0x ## VA */                                                                                              \
    MS2Ptr<T> Unk_Finder::NAME(const Scaleform::GFx::Value& root, const CString& strName)                           \
    {                                                                                                              \
        MS2Ptr<ASDisplayObjectContainer> spCont = FUN_140bc5fc0(m_nMovieId, root);                                 \
        if (!spCont->FUN_1422ba9f0("getChildByName"))                                                              \
            return MS2Ptr<T>(0);                                                                                   \
        Scaleform::GFx::Value child = spCont->FUN_1422c6b00(strName);                                              \
        if (FUN_1409b4d40(child))                                                                                  \
            return CREATE(m_nMovieId, child);                                                                      \
        if (!spCont->FUN_1422ba9f0("numChildren"))                                                                 \
            return MS2Ptr<T>(0);                                                                                   \
        int nCount = spCont->FUN_1422c6670();                                                                      \
        for (int i = 0; i < nCount; i++)                                                                           \
        {                                                                                                          \
            Scaleform::GFx::Value sub = spCont->FUN_1422c6aa0(i);                                                  \
            if (!FUN_1409b4d40(sub))                                                                               \
                continue;                                                                                          \
            MS2Ptr<T> sp = NAME(sub, strName);                                                                     \
            if (sp.get() != 0)                                                                                     \
                return sp;                                                                                         \
        }                                                                                                          \
        return MS2Ptr<T>(0);                                                                                       \
    }

// @0x140d01e70
MS2_FINDER_DEEP(140d01e70, FUN_140d01e70, Unk_140acd6e0, FUN_140acc910)
// @0x140d02140
MS2_FINDER_DEEP(140d02140, FUN_140d02140, Unk_GpCheck, FUN_140a57df0)
// @0x140d02410
MS2_FINDER_DEEP(140d02410, FUN_140d02410, ASDisplayObject, FUN_140d01be0)
// @0x140d026e0
MS2_FINDER_DEEP(140d026e0, FUN_140d026e0, ASDisplayObjectContainer, FUN_140bc5fc0)
// @0x140d029b0
MS2_FINDER_DEEP(140d029b0, FUN_140d029b0, Unk_WcTitle, FUN_140c43580)
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
MS2_UNK_PTR_IMPL(Unk_AasSourcePtr, Unk_AasSource)

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca4800-0x142ca4940 .text$yd
