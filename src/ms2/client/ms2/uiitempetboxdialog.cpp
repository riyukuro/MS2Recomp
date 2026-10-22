// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Pet box dialog (Lullu box).
// MS2-UNIT: client\ms2\uiitempetboxdialog.cpp
// MS2-RANGE: 0x140e4df70-0x140e54b60 .text$mn
// MS2-RANGE: 0x1400d8630-0x1400d8770 .text$di
// MS2-RANGE: 0x142ca6af0-0x142ca6ba6 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?8PEAVUIItemPetBoxDialog@@P80@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@YA_NAEBU?$pair@PEAVUIItemPetBoxDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@0@0@Z 0x140e52590 ; prop
// MS2-PIN: ??$?8PEAVUIItemPetBoxDialog@@P80@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA_NAEBU?$pair@PEAVUIItemPetBoxDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@0@Z 0x140e52600 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIItemPetBoxDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@QEAA@AEBV01@@Z 0x140e53b40 ; unique
// MS2-PIN: ??_GUIItemPetBoxDialog@@UEAAPEAXI@Z 0x140e540e0 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIItemPetBoxDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140e547f0 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIItemPetBoxDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140e54850 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIItemPetBoxDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x140e548e0 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVUIItemPetBoxDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x140e54910 ; unique
// MS2-PIN: ??$Call@VUIItemPetBoxDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@?$DelegateImpl@U?$pair@PEAVUIItemPetBoxDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@CAXAEAU?$pair@PEAVUIItemPetBoxDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@AEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x140e54950 ; unique
// MS2-PIN: ??$Call@VUIItemPetBoxDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVUIItemPetBoxDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVUIItemPetBoxDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x140e54990 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIItemPetBoxDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140e549d0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIItemPetBoxDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140e54a30 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@UUnk_PetBoxCard@@@std@@@std@@SA_KAEBV?$allocator@UUnk_PetBoxCard@@@2@@Z 0x140e54a90
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@UUnk_PetBoxCard@@V?$allocator@UUnk_PetBoxCard@@@std@@@std@@@std@@QEBAAEBV?$allocator@UUnk_PetBoxCard@@@2@XZ 0x140e543b0
// MS2-PIN: ?push_back@?$vector@UUnk_PetBoxCard@@V?$allocator@UUnk_PetBoxCard@@@std@@@std@@QEAAXAEBUUnk_PetBoxCard@@@Z 0x140e54af0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiitempetboxdialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uiitempetboxdialog.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "inventory.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <algorithm>
#include <errno.h>
#include <string.h>
static CString s_sndOpen = "LulluOpenBox_Open";
static CString s_sndSpecial = "LulluOpenBox_SpecialItem_Get";
static CString s_snd10 = "LulluOpenBox_10Items_Open";

// ---- local stand-ins for classes whose units are not recovered yet ----
class Unk_PetBoxText : public ASDisplayObject { public: void FUN_1422e4b80(const CStringW&); };
class Unk_PetBoxButton : public ASDisplayObject
{
public:
    void FUN_1422ce240(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>&, int);
};
class Unk_PetBoxCheck : public ASDisplayObject { public: bool FUN_1422ce0e0(); };
// ASMovieClip with the extra child lookups / setters the dialog uses
class Unk_PetBoxClip : public ASMovieClip
{
public:
    MS2Ptr<Unk_PetBoxText> FUN_140c436d0(const CString&);
    void FUN_1407cba60(const char*, CString);
};
// the AS root (m_30) with the check box lookup
class Unk_PetBoxRoot : public AScript
{
public:
    template <class T> MS2Ptr<T> FUN_140c11f50(const CString&);
};
class CMsgBoxData : public CPtred
{
public:
    void FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>);
};
// the obtained items (std::vector<ItemEntity>) and the "binding" strings (std::vector<CString>) with the exe helpers
class Unk_PetBoxItems : public Unk_ItemVec
{
public:
    ItemEntity& FUN_140be9400(size_t);
    void FUN_140c47b00(size_t);
    bool FUN_140c0e9f0();
};
class Unk_PetBoxStrVec : public Unk_StrVec
{
public:
    void FUN_140905dd0();
    void FUN_1403b0310(const CString&);
};
#define PETBOX_ITEMS static_cast<Unk_PetBoxItems&>(m_result)
#define PETBOX_ATTR(p) reinterpret_cast<Unk_PetBoxAttr*>(reinterpret_cast<char*>((p).operator->()) + 0x320)
#define PETBOX_BINDS static_cast<Unk_PetBoxStrVec&>(m_slotBinds)
// the drop list of a common box: polymorphic entries (item id, rank, count)
class Unk_PetBoxDrop
{
public:
    virtual unsigned vfunc_0();
    virtual int vfunc_1();
    virtual unsigned vfunc_2();
};
class Unk_PetBoxDropVec
{
public:
    Unk_PetBoxDropVec();                    // 0x1405a1910
    ~Unk_PetBoxDropVec();                   // 0x1405a1a40
    size_t FUN_140314170();
    Unk_PetBoxDrop* FUN_140c461b0(size_t);
    void FUN_140313cd0(Unk_PetBoxDrop*);
    void* m_begin; void* m_end; void* m_cap;
};
MS2_CHECK_SIZE(Unk_PetBoxDropVec, 24);
class Unk_PetBoxIntVec
{
public:
    Unk_PetBoxIntVec();                     // 0x140182ed0
    ~Unk_PetBoxIntVec();                    // 0x140183b90
    size_t FUN_140191110() const;
    int& FUN_140297cb0(size_t);
    void* m_begin; void* m_end; void* m_cap;
};
MS2_CHECK_SIZE(Unk_PetBoxIntVec, 24);
class Unk_PetBoxDropTable { public: void FUN_1402ea4c0(int, Unk_PetBoxDropVec&); };
Unk_PetBoxDropTable* FUN_1405a1fd0();
// the item record's attribute table (+0x320) and job table (+0x138)
class Unk_PetBoxAttr
{
public:
    CString FUN_1409e8560(const CStringW&, const CString&);
    Unk_PetBoxIntVec FUN_1409e8620(const CStringW&, const Unk_PetBoxIntVec& = Unk_PetBoxIntVec());
};
class Unk_PetBoxJobSet { public: bool FUN_140545da0(int); };
class Unk_PetBoxData : public CItemData
{
public:
    bool FUN_14053cc40();
    int FUN_14053c940(int);
};
class Unk_PetBoxSelf { public: int FUN_141654700(); int FUN_141658e60(); };
class Unk_PetBoxWorld { public: Unk_PetBoxSelf* FUN_141bd0cc0(); };
Unk_PetBoxWorld* FUN_1403ed2d0();
class Unk_PetBoxUIMgr { public: void FUN_141adc530(int); };
Unk_PetBoxUIMgr* FUN_1403ed2b0();
class Unk_PetBoxStrings { public: CStringW FUN_141811980(int, int); };
Unk_PetBoxStrings* FUN_1401a9d70();
MS2Ptr<CItemData> FUN_14053f870(int);
extern Unk_Inventory DAT_143ab2a90;
// avatar of a pet (0xc8 bytes, RTTI UIAvatarPet : UIAvatarBase), rendered into an AS clip
struct Unk_PetBoxVector
{
    Unk_PetBoxVector();
    float x, y, z;
    Unk_PetBoxVector& operator+=(const Unk_PetBoxVector&);
};
MS2_CHECK_SIZE(Unk_PetBoxVector, 12);
struct Unk_PetBoxCameraData
{
    Unk_PetBoxCameraData();
    void FUN_141b48670();
    Unk_PetBoxVector eye, target;
    float f18, f1c, f20;
    int n24, n28, n2c;
};
MS2_CHECK_SIZE(Unk_PetBoxCameraData, 0x30);
class Unk_PetBoxActor
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4();
    virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14();
    virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17();
    virtual Unk_PetBoxVector vfunc_18();
};
class Unk_PetBoxCamera
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4();
    virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12();
    virtual void vfunc_13(const Unk_PetBoxCameraData&);
};
class Unk_PetBoxCameraPtr
{
public:
    ~Unk_PetBoxCameraPtr();
    Unk_PetBoxCamera* operator->() const;
private:
    Unk_PetBoxCamera* m_p;
};
MS2_CHECK_SIZE(Unk_PetBoxCameraPtr, 8);
class Unk_PetBoxAvatar : public CPtred
{
public:
    virtual void vfunc_1(IUIAvatarEventListener*);
    virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6();
    virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16();
    virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21();
    virtual void vfunc_22(); virtual void vfunc_23();
    virtual Unk_PetBoxActor* vfunc_24();
    virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27();
    virtual void vfunc_28(void*, TPtr<Unk_UISwfEntity_25>, void*, void*);
    Unk_PetBoxCameraPtr FUN_1418b9bc0();
};
class UIAvatarPet : public Unk_PetBoxAvatar
{
public:
    UIAvatarPet(void*);
private:
    unsigned char m_18[0xb0];
};
MS2_CHECK_SIZE(UIAvatarPet, 0xc8);
void FUN_141276180(const CString&, const CString&);
void FUN_14141f970(const CString&);
void FUN_14141f770(CString&, unsigned int, const ATL::CAtlArray<MS2Ptr<CItem> >&, MS2Ptr<CItem>(*)(const ATL::CAtlArray<MS2Ptr<CItem> >&, int), int, int);
MS2Ptr<CItem> FUN_141420330(const ATL::CAtlArray<MS2Ptr<CItem> >&, int);
void FUN_141415450(const CString&, MS2Ptr<CItem>, int, int, int);
CStringW GetStringCommonByKey(const CStringW&);
MS2Ptr<CMsgBoxData> FUN_140d73f20(CStringW, int);
void FUN_140d73c60(MS2Ptr<CMsgBoxData>);
int FUN_140718170(const CString&);
int FUN_140bd09c0(void*);

// @0x140e4df70
UIItemPetBoxDialog::UIItemPetBoxDialog()
{
    m_boxItemId = 0;
    m_multi = false;
    m_sent = false;
    m_80 = 0;
}

// @0x140e4e150
UIItemPetBoxDialog::~UIItemPetBoxDialog()
{
    FUN_14141f970(m_bagId);
}

// @0x140e4e2f0
CString UIItemPetBoxDialog::GetTypeName() { return "ItemPetBoxDialog"; }

// @0x140e4e340
int UIItemPetBoxDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    return 1;
}

// @0x140e4e370
void UIItemPetBoxDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_singleOpen = 0;
    m_multiOpen = 0;
    m_itemBox = 0;
    m_resultItem = 0;
    m_skipEffect = 0;
    m_previewSingle = 0;
    m_previewMulti = 0;
    m_closeSingle = 0;
    m_closeMulti = 0;
}

// @0x140e4e450
void UIItemPetBoxDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    FUN_140e4f9a0();
    FUN_140e4f9e0();
}

// @0x140e4e490
void UIItemPetBoxDialog::OnLoadComplete()
{
    m_multi = false;
    m_sent = false;
    UIDialog::OnLoadComplete();
    FUN_141925ec0("m_closeButton");
    if (FUN_140bc6d10("m_singleOpenButton", m_singleOpen).get())
        m_singleOpen->FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIItemPetBoxDialog::FUN_140e4fa60), 0);
    if (FUN_140bc6d10("m_multiOpenButton", m_multiOpen).get())
        m_multiOpen->FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIItemPetBoxDialog::FUN_140e4fa60), 1);
    if (FUN_140c57ce0("m_petPreviewSingle", m_previewSingle).get()) {
        if (m_previewSingle->FUN_140bbe640<Unk_PetBoxButton>("m_petPreviewClose", m_closeSingle).get())
            m_closeSingle->FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIItemPetBoxDialog::FUN_140e4fb70), 0);
    }
    if (FUN_140c57ce0("m_petPreviewMulti", m_previewMulti).get()) {
        if (m_previewMulti->FUN_140bbe640<Unk_PetBoxButton>("m_petPreviewClose", m_closeMulti).get())
            m_closeMulti->FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIItemPetBoxDialog::FUN_140e4fb70), 0);
    }
    FUN_140c57ce0("m_itemBox", m_itemBox);
    FUN_140c57ce0("m_resultItem", m_resultItem);
    FUN_140e52700("m_isSkipEffect", m_skipEffect);
    FUN_140e4fd60();
}

// @0x140e4ecb0
void UIItemPetBoxDialog::vfunc_79(void* p)
{
#define PETBOX_PKT static_cast<CInPacket*>(p)
    UIDialog::vfunc_79(p);
    if (PETBOX_PKT->FUN_14070fe80() == 0xf5) {
        if (m_30 == 0)
            return;
        m_sent = false;
        unsigned reset = PETBOX_PKT->ReadUInt8();
        if (reset == 1) {
            PETBOX_ITEMS.FUN_14028a590();
            m_special2.clear();
            bool hasSpecial = false;
            int n = PETBOX_PKT->ReadInt32();
            PETBOX_ITEMS.FUN_140c47b00(n);
            for (int i = 0; i < n; ++i) {
                PETBOX_ITEMS.FUN_140be9400(i).m_itemId = PETBOX_PKT->ReadInt32();
                PETBOX_ITEMS.FUN_140be9400(i).m_count = PETBOX_PKT->ReadInt32();
                PETBOX_ITEMS.FUN_140be9400(i).SetRank(PETBOX_PKT->ReadInt32());
                bool special = PETBOX_PKT->ReadBool();
                if (special)
                    m_special2.insert(PETBOX_ITEMS.FUN_140be9400(i));
                if (FUN_140e4fc90(PETBOX_ITEMS.FUN_140be9400(i)) == true)
                    hasSpecial = true;
            }
            FUN_140e504e0();
            FUN_140e511f0();
            m_itemBox->vfunc_13("result");
            FUN_141276180(s_sndOpen, "");
            if (PETBOX_ITEMS.FUN_14028b470() > 1)
                FUN_141276180(s_snd10, "");
            MS2Ptr<ASMovieClip> fw = m_itemBox->FUN_1409b4560("m_fireworkEffect");
            if (fw.get()) {
                fw->vfunc_4(hasSpecial);
                if (hasSpecial) {
                    fw->vfunc_12(1);
                    FUN_141276180(s_sndSpecial, "");
                }
            }
        }
    }
#undef PETBOX_PKT
}

// @0x140e4f1e0
int UIItemPetBoxDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp(szMethod, "onSendOpenBox") == 0) {
        if (FUN_140e51ca0() == 0)
            FUN_140e52110();
        else {
            m_resultItem->vfunc_4(false);
            m_itemBox->vfunc_15("idle");
        }
    }
    return 0;
}

// @0x140e4f2e0
void UIItemPetBoxDialog::vfunc_25(void* a, TPtr<Unk_UISwfEntity_25> tp, void* b, void* c)
{
    if (tp.get() == 0 || b == 0)
        return;
    int idx = FUN_140718170(*static_cast<const CString*>(c));
    if (idx < 0 || idx > (int)m_cards.size())
        return;
    if (m_cards[idx].m_avatar == 0)
        return;
    Unk_PetBoxActor* actor = m_cards[idx].m_avatar->vfunc_24();
    if (!actor)
        return;
    m_cards[idx].m_avatar->vfunc_28(a, tp, b, c);
    Unk_PetBoxCameraData data;
    data.FUN_141b48670();
    data.f1c = 300.0f;
    data.target += actor->vfunc_18();
    data.eye += data.target;
    m_cards[idx].m_avatar->FUN_1418b9bc0()->vfunc_13(data);
}

// @0x140e4f5a0
void UIItemPetBoxDialog::vfunc_16()
{
    UISwfEntity::vfunc_16();
    FUN_140e4f8e0();
}

// @0x140e4f5d0
bool UIItemPetBoxDialog::vfunc_17()
{
    if (!UIDialog::vfunc_17())
        return false;
    FUN_140e4f7d0();
    return true;
}

// @0x140e4f610
int UIItemPetBoxDialog::vfunc_o178_1(void* av)
{
    if (!av)
        return 0;
    int found = 0;
    for (size_t i = 0; i < m_cards.size(); ++i) {
        if (m_cards[i].m_avatar.get() == av) {
            found = (int)i;
            break;
        }
    }
    if (found >= 0)
        FUN_140e4f6d0(found);
    return 1;
}

// @0x140e4f6d0
void UIItemPetBoxDialog::FUN_140e4f6d0(int idx)
{
    if (idx > (int)m_cards.size())
        return;
    if (m_cards[idx].m_clip.get())
        m_cards[idx].m_clip->Invoke("loadRenderTarget", StringFormat(L"{0}", idx));
}

// @0x140e4f7d0
void UIItemPetBoxDialog::FUN_140e4f7d0()
{
    for (size_t i = 0; i < m_cards.size(); ++i) {
        if (m_cards[i].m_clip.get())
            m_cards[i].m_clip->Invoke("loadRenderTarget", StringFormat(L"{0}", i));
    }
}

// @0x140e4f8e0
void UIItemPetBoxDialog::FUN_140e4f8e0()
{
    for (size_t i = 0; i < m_cards.size(); ++i) {
        if (m_cards[i].m_clip.get())
            m_cards[i].m_clip->Invoke("unloadRenderTarget");
    }
}

// @0x140e4f9a0
void UIItemPetBoxDialog::FUN_140e4f9a0()
{
    FUN_140e4f8e0();
    m_cards.clear();
}

// @0x140e4f9e0
void UIItemPetBoxDialog::FUN_140e4f9e0()
{
    for (size_t i = 0; i < PETBOX_BINDS.FUN_14028b4c0(); ++i)
        FUN_14141f970(*m_slotBinds.FUN_14027f1c0(i));
    PETBOX_BINDS.FUN_140905dd0();
}

// @0x140e4fa60
void UIItemPetBoxDialog::FUN_140e4fa60(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_30 == 0)
        return;
    if (m_previewSingle.get())
        m_previewSingle->vfunc_3(0);
    if (m_previewMulti.get())
        m_previewMulti->vfunc_3(0);
    int v = FUN_140bd09c0(params.pUserData);
    if (v != 0 && v != 1)
        return;
    if (v == 0)
        m_multi = false;
    else
        m_multi = true;
    FUN_140e51e40();
}

// @0x140e4fb70
void UIItemPetBoxDialog::FUN_140e4fb70(const Scaleform::GFx::FunctionHandler::Params&)
{
    if (m_30 == 0)
        return;
    if (m_previewSingle.get())
        m_previewSingle->vfunc_3(0);
    if (m_previewMulti.get())
        m_previewMulti->vfunc_3(0);
}

// @0x140e4fc30
void UIItemPetBoxDialog::SetBoxItemId(int id) { m_boxItemId = id; }

// @0x140e4fc50
bool UIItemPetBoxDialog::FUN_140e4fc50(int result, const CMsgBoxData&)
{
    if (result == 0)
        FUN_1403ed2b0()->FUN_141adc530(0x4ec1);
    return true;
}

// @0x140e4fc90
bool UIItemPetBoxDialog::FUN_140e4fc90(const ItemEntity& e)
{
    if (m_special1.find(e) != m_special1.end())
        return true;
    if (m_special2.find(e) != m_special2.end())
        return true;
    return false;
}

// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
// @0x140e4fd60
bool UIItemPetBoxDialog::FUN_140e4fd60()
{
    if (m_30 == 0)
        return false;
    Unk_PetBoxSelf* self = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (self == 0)
        return false;
    MS2Ptr<CItemData> data = FUN_14053f870(m_boxItemId);
    if (data == 0)
        return false;
    if (data->function.name != L"OpenPetBox")
        return false;
    Unk_PetBoxIntVec ids = PETBOX_ATTR(data)->FUN_1409e8620(L"unCommonBoxId", Unk_PetBoxIntVec());
    Unk_PetBoxDropVec drops;
    for (size_t i = 0; i < ids.FUN_140191110(); ++i)
        FUN_1405a1fd0()->FUN_1402ea4c0(ids.FUN_140297cb0(i), drops);
    Unk_PetBoxDropVec filtered;
    for (size_t i = 0; i < drops.FUN_140314170(); ++i) {
        Unk_PetBoxDrop* d = drops.FUN_140c461b0(i);
        MS2Ptr<CItemData> idata = FUN_14053f870(d->vfunc_0());
        if (idata == 0)
            continue;
        Unk_PetBoxJobSet* jobs = reinterpret_cast<Unk_PetBoxJobSet*>(reinterpret_cast<char*>(idata.operator->()) + 0x138);
        if (jobs->FUN_140545da0(self->FUN_141654700())) {
            if (static_cast<Unk_PetBoxData*>(idata.operator->())->FUN_14053c940(self->FUN_141658e60()) != 0)
                filtered.FUN_140313cd0(d);
        }
    }
    ATL::CAtlArray<MS2Ptr<CItem> > items;
    m_special1.clear();
    for (size_t i = 0; i < filtered.FUN_140314170(); ++i) {
        Unk_PetBoxDrop* d = filtered.FUN_140c461b0(i);
        MS2Ptr<CItem> item(new CItem);
        if (item->FUN_14052b130(d->vfunc_0(), d->vfunc_1(), 0) != 0) {
            item->FUN_140526c70(d->vfunc_2());
            items.Add(item);
        }
        m_special1.insert(ItemEntity(d->vfunc_0(), d->vfunc_1(), d->vfunc_2(), false, false, false, false));
    }
    FUN_14141f970(m_bagId);
    MS2Ptr<CItem> (*getter)(const ATL::CAtlArray<MS2Ptr<CItem> >&, int) = FUN_141420330;
    FUN_14141f770(m_bagId, (unsigned)items.GetCount(), items, getter, 0x415, 0x800);
    ASObj obj(2);
    obj.FUN_1407cba60("bagId", m_bagId);
    m_30->Invoke("initItemData", obj.FUN_1422bb870());
    return true;
}

// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
// @0x140e504e0
void UIItemPetBoxDialog::FUN_140e504e0()
{
    if (m_30 == 0 || PETBOX_ITEMS.FUN_140c0e9f0())
        return;
    FUN_140e4f9e0();
    if (PETBOX_ITEMS.FUN_14028b470() == 1) {
        MS2Ptr<ASMovieClip> single = m_itemBox->FUN_1409b4560("m_singleItem");
        if (single.get() == 0)
            return;
        MS2Ptr<ASMovieClip> slot = single->FUN_1409b4560("m_itemSlot");
        if (slot.get() == 0)
            return;
        MS2Ptr<Unk_PetBoxText> name = static_cast<Unk_PetBoxClip*>(single.operator->())->FUN_140c436d0("m_itemName");
        if (name.get() == 0)
            return;
        ItemEntity& e = PETBOX_ITEMS.FUN_140be9400(0);
        MS2Ptr<CItem> item(new CItem);
        if (item->FUN_14052b130(e.vfunc_o18_0(), e.vfunc_o18_1(), 0) == 0)
            return;
        MS2Ptr<ASMovieClip> unc = single->FUN_1409b4560("m_uncommonEffect");
        if (unc.get()) {
            if (FUN_140e4fc90(e) == true)
                unc->vfunc_4(true);
            else
                unc->vfunc_4(false);
        }
        item->FUN_140526c70(e.vfunc_o18_2());
        CString bagKey;
        bagKey.Format("ItemLullu_%s_%d", (const char*)GetTypeName(), 1);
        int count = item->FUN_140526c50();
        CStringW txt = StringFormat(L"{0} X {1}", item->FUN_140527b10(), count);
        FUN_141415450(bagKey, MS2Ptr<CItem>(item), 0, 0x415, 0x800);
        static_cast<Unk_PetBoxClip*>(slot.operator->())->FUN_1407cba60("binding", bagKey);
        name->FUN_1422e4b80(txt);
        PETBOX_BINDS.FUN_1403b0310(bagKey);
        m_30->Invoke("SetMultiType", false);
    } else {
        size_t n = PETBOX_ITEMS.FUN_14028b470();
        size_t cap = 10;
        size_t count = (std::min)(cap, n);
        for (size_t i = 0; i < count; ++i) {
            size_t k = i + 1;
            CString nm = StringFormat("m_multi{0}", k);
            MS2Ptr<ASMovieClip> multi = m_itemBox->FUN_1409b4560(nm);
            if (multi.get() == 0)
                continue;
            MS2Ptr<ASMovieClip> slot = multi->FUN_1409b4560("m_itemSlot");
            if (slot.get() == 0)
                continue;
            CString bagKey;
            if (i < PETBOX_ITEMS.FUN_14028b470()) {
                ItemEntity& e = PETBOX_ITEMS.FUN_140be9400(i);
                MS2Ptr<CItem> item(new CItem);
                if (item->FUN_14052b130(e.vfunc_o18_0(), e.vfunc_o18_1(), 0) == 0)
                    continue;
                item->FUN_140526c70(e.vfunc_o18_2());
                bagKey.Format("ItemLullu_%s_%d", (const char*)GetTypeName(), (int)(i + 1));
                FUN_141415450(bagKey, MS2Ptr<CItem>(item), (int)i, 0x415, 0x800);
                PETBOX_BINDS.FUN_1403b0310(bagKey);
                MS2Ptr<ASMovieClip> unc = multi->FUN_1409b4560("m_uncommonEffect");
                if (unc.get()) {
                    if (FUN_140e4fc90(e) == true) {
                        unc->vfunc_4(true);
                        unc->vfunc_12(1);
                    } else
                        unc->vfunc_4(false);
                }
                static_cast<Unk_PetBoxClip*>(slot.operator->())->FUN_1407cba60("binding", bagKey);
            }
        }
        m_30->Invoke("SetMultiType", true);
    }
}

// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
// @0x140e511f0
void UIItemPetBoxDialog::FUN_140e511f0()
{
    if (m_30 == 0)
        return;
    FUN_140e4f9a0();
    if (PETBOX_ITEMS.FUN_140c0e9f0())
        return;
    if (PETBOX_ITEMS.FUN_14028b470() == 1) {
        if (!(m_previewSingle == 0)) {
            MS2Ptr<ASMovieClip> card = m_previewSingle->FUN_1409b4560("m_petCard1");
            if (card.get() == 0)
                return;
            FUN_140e519b0(card, PETBOX_ITEMS.FUN_140be9400(0));
            MS2Ptr<CItemData> idata = FUN_14053f870(PETBOX_ITEMS.FUN_140be9400(0).m_itemId);
            if (idata.get() != 0) {
                if (static_cast<Unk_PetBoxData*>(idata.operator->())->FUN_14053cc40()) {
                    UIAvatarPet* av = new UIAvatarPet(idata.get());
                    av->vfunc_1(this);
                    Unk_PetBoxCard c;
                    c.m_avatar.AssignRaw(av);
                    c.m_clip = card;
                    c.m_clip->vfunc_3(1);
                    m_cards.push_back(c);
                }
            }
            m_previewSingle->vfunc_3(1);
            m_previewSingle->vfunc_12(1);
        }
    } else {
        if (!(m_previewMulti == 0)) {
            MS2Ptr<ASMovieClip> movie = m_previewMulti->FUN_1409b4560("m_petCardMovie");
            if (movie.get() == 0)
                return;
            size_t n = PETBOX_ITEMS.FUN_14028b470();
            size_t cap = 10;
            size_t count = (std::min)(cap, n);
            for (size_t i = 0; i < count; ++i) {
                size_t k = i + 1;
                CString nm = StringFormat("m_petCard{0}", k);
                MS2Ptr<ASMovieClip> card = movie->FUN_1409b4560(nm);
                if (card.get() == 0)
                    continue;
                FUN_140e519b0(card, PETBOX_ITEMS.FUN_140be9400(i));
                MS2Ptr<CItemData> idata = FUN_14053f870(PETBOX_ITEMS.FUN_140be9400(i).m_itemId);
                if (idata.get() != 0) {
                    if (static_cast<Unk_PetBoxData*>(idata.operator->())->FUN_14053cc40()) {
                        UIAvatarPet* av = new UIAvatarPet(idata.get());
                        av->vfunc_1(this);
                        Unk_PetBoxCard c;
                        c.m_avatar.AssignRaw(av);
                        c.m_clip = card;
                        m_cards.push_back(c);
                    }
                }
            }
            m_previewMulti->vfunc_3(1);
            m_previewMulti->vfunc_12(1);
        }
    }
}

// @0x140e519b0
void UIItemPetBoxDialog::FUN_140e519b0(MS2Ptr<ASMovieClip> clip, const ItemEntity& item)
{
    if (clip == 0)
        return;
    MS2Ptr<ASTextField> txt = clip->FUN_1409b4620("m_petNameText");
    if (txt == 0)
        return;
    CStringW name = FUN_1401a9d70()->FUN_141811980(1, item.m_itemId);
    txt->FUN_1422c4cd0(name);
    if (const_cast<ItemEntity&>(item).vfunc_o18_1() == 2)
        clip->vfunc_15("rare");
    else if (const_cast<ItemEntity&>(item).vfunc_o18_1() == 3)
        clip->vfunc_15("elite");
    else if (const_cast<ItemEntity&>(item).vfunc_o18_1() == 4)
        clip->vfunc_15("excellent");
    else
        clip->vfunc_15("normal");
}

// @0x140e51ca0
int UIItemPetBoxDialog::FUN_140e51ca0()
{
    MS2Ptr<CItemData> data = FUN_14053f870(m_boxItemId);
    if (data == 0)
        return -1;
    CString tag = PETBOX_ATTR(data)->FUN_1409e8560(L"itemTag", "");
    int tagId = (int)FUN_140557640(FUN_140281980(), &tag);
    if (tagId == 0)
        return -1;
    int have = DAT_143ab2a90.FUN_140a5f7b0(tagId, 0);
    int need = 1;
    if (m_multi)
        need = 10;
    if (have < need)
        return 1;
    return 0;
}

// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
// @0x140e51e40
void UIItemPetBoxDialog::FUN_140e51e40()
{
    if (m_30 == 0)
        return;
    int r = FUN_140e51ca0();
    if (r != -1 && r == 1) {
        MS2Ptr<CMsgBoxData> box = FUN_140d73f20(GetStringCommonByKey(L"s_lullu_key_not_enough_key"), 1);
        if (box.get()) {
            box->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIItemPetBoxDialog::FUN_140e4fc50));
            FUN_140d73c60(box);
        }
    } else if (r != -1) {
        m_30->Invoke("enableComponent", false);
        if (!m_skipEffect->FUN_1422ce0e0()) {
            m_resultItem->vfunc_4(false);
            m_itemBox->vfunc_13("open");
        } else
            FUN_140e52110();
    }
}

// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
// @0x140e52110
void UIItemPetBoxDialog::FUN_140e52110()
{
    if (m_sent == true)
        return;
    CStringW mode = L"single";
    if (m_multi)
        mode = L"multi";
    int r = FUN_140e51ca0();
    if (r != 0) {
        m_resultItem->vfunc_4(false);
        m_itemBox->vfunc_15("idle");
        return;
    }
    MS2Ptr<CItemData> data = FUN_14053f870(m_boxItemId);
    if (data == 0)
        return;
    CString tag = PETBOX_ATTR(data)->FUN_1409e8560(L"itemTag", "");
    int tagId = (int)FUN_140557640(FUN_140281980(), &tag);
    MS2Ptr<CItem> inv = DAT_143ab2a90.FUN_140a5e040(tagId);
    if (!(inv == 0)) {
        if (DAT_143ab2a90.FUN_140a63880(inv.operator->(), mode) == 0)
            vfunc_67();
        else
            m_sent = true;
    }
}

// @0x140e52670
MS2Ptr<Unk_PetBoxCheck> UIItemPetBoxDialog::FUN_140e52670(const CString& name)
{
    if (m_30 == 0)
        return MS2Ptr<Unk_PetBoxCheck>(0);
    return static_cast<Unk_PetBoxRoot*>(m_30.operator->())->FUN_140c11f50<Unk_PetBoxCheck>(name);
}

// @0x140e52700
MS2Ptr<Unk_PetBoxCheck> UIItemPetBoxDialog::FUN_140e52700(const CString& name, MS2Ptr<Unk_PetBoxCheck>& member)
{
    member = FUN_140e52670(name);
    return member;
}

// ---- hooks ----
MS2_REPLACE_METHOD(0x140E4E2F0, UIItemPetBoxDialog, GetTypeName, 61, 0xA2EBBBF1);
MS2_REPLACE_METHOD(0x140E4E340, UIItemPetBoxDialog, vfunc_65, 37, 0x4561E126);
MS2_REPLACE_METHOD(0x140E4E370, UIItemPetBoxDialog, vfunc_26, 213, 0x44B68A87);
MS2_REPLACE_METHOD(0x140E4E450, UIItemPetBoxDialog, vfunc_67, 44, 0x3C78319B);
MS2_REPLACE_METHOD(0x140E4E490, UIItemPetBoxDialog, OnLoadComplete, 2064, 0x2E8A2E45);
MS2_REPLACE_METHOD(0x140E4F1E0, UIItemPetBoxDialog, vfunc_28, 248, 0x7ABDB895);
MS2_REPLACE_METHOD(0x140E4F2E0, UIItemPetBoxDialog, vfunc_25, 683, 0x523E66EC);
MS2_REPLACE_METHOD(0x140E4F5A0, UIItemPetBoxDialog, vfunc_16, 34, 0x867535AC);
MS2_REPLACE_METHOD(0x140E4F5D0, UIItemPetBoxDialog, vfunc_17, 47, 0xA0F8AF34);
MS2_REPLACE_METHOD(0x140E4F6D0, UIItemPetBoxDialog, FUN_140e4f6d0, 244, 0x58DDE214);
MS2_REPLACE_METHOD(0x140E4F7D0, UIItemPetBoxDialog, FUN_140e4f7d0, 251, 0xFE9B33A1);
MS2_REPLACE_METHOD(0x140E4F8E0, UIItemPetBoxDialog, FUN_140e4f8e0, 176, 0x6354CE48);
MS2_REPLACE_METHOD(0x140E4F9A0, UIItemPetBoxDialog, FUN_140e4f9a0, 43, 0x34618B18);
MS2_REPLACE_METHOD(0x140E4F9E0, UIItemPetBoxDialog, FUN_140e4f9e0, 117, 0x33366119);
MS2_REPLACE_METHOD(0x140E4FA60, UIItemPetBoxDialog, FUN_140e4fa60, 259, 0x6554B4A2);
MS2_REPLACE_METHOD(0x140E4FB70, UIItemPetBoxDialog, FUN_140e4fb70, 182, 0x99CD677A);
MS2_REPLACE_METHOD(0x140E4FC30, UIItemPetBoxDialog, SetBoxItemId, 25, 0x9BF64FA6);
MS2_REPLACE_METHOD(0x140E4FC50, UIItemPetBoxDialog, FUN_140e4fc50, 50, 0x3FD9DD97);
MS2_REPLACE_METHOD(0x140E4FC90, UIItemPetBoxDialog, FUN_140e4fc90, 187, 0x768844F2);
MS2_REPLACE_METHOD(0x140E519B0, UIItemPetBoxDialog, FUN_140e519b0, 734, 0x3387E636);
MS2_REPLACE_METHOD(0x140E51CA0, UIItemPetBoxDialog, FUN_140e51ca0, 401, 0x3F87147F);
MS2_REPLACE_METHOD(0x140E52670, UIItemPetBoxDialog, FUN_140e52670, 139, 0x2C5278D7);
MS2_REPLACE_METHOD(0x140E52700, UIItemPetBoxDialog, FUN_140e52700, 138, 0x48954D03);
MS2_REPLACE_METHOD_VIA(0x140E4F610, UIItemPetBoxDialog, IUIAvatarEventListener, vfunc_o178_1, 178, 0xCEE1D1D9);
