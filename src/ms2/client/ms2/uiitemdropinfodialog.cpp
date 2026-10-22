// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Item drop preview dialog.
// MS2-UNIT: client\ms2\uiitemdropinfodialog.cpp
// MS2-RANGE: 0x140c39fd0-0x140c3cc10 .text$mn
// MS2-RANGE: 0x1400ccf60-0x1400cd100 .text$di
// MS2-RANGE: 0x142ca2ae0-0x142ca2b90 .text$yd
// MS2-PIN: ??_GUIItemDropInfoDialog@@UEAAPEAXI@Z 0x140c3c6e0
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUIItemDropInfoDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAPEAXI@Z 0x140c3c6a0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiitemdropinfodialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uiitemdropinfodialog.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/gfxexception.h"
#include "ms2/ms2format.h"
#include <vector>
#include <algorithm>
static CString s_itemCount("itemCount");
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Unit-local declarations; Unk names and member names are invented.
class ASData : public CPtred { public: int FUN_1422b8b10(); };
class Unk_ItemData;
class Unk_ItemPtrSetter { public: void FUN_1401bffe0(CItem*); };
class CItem {
public:
    CItem();
    int FUN_1405276c0();
    int FUN_140526bd0();
    Unk_ItemData* FUN_140527840();
    int FUN_14052b130(int id, int rarity, int flag);
private:
    void* m_0; void* m_8; void* m_10; void* m_18; void* m_20; void* m_28; void* m_30; void* m_38;
    void* m_40; void* m_48; void* m_50; void* m_58; void* m_60; void* m_68; void* m_70; void* m_78;
    void* m_80; void* m_88; void* m_90; void* m_98; void* m_a0; void* m_a8; void* m_b0; void* m_b8;
    void* m_c0; void* m_c8; void* m_d0; void* m_d8; void* m_e0; void* m_e8; void* m_f0; void* m_f8;
    void* m_100; void* m_108; void* m_110; void* m_118; void* m_120; void* m_128; void* m_130; void* m_138;
    void* m_140; void* m_148; void* m_150; void* m_158; void* m_160; void* m_168; void* m_170; void* m_178;
    void* m_180; void* m_188; void* m_190; void* m_198;
};
MS2_CHECK_SIZE(CItem, 0x1a0);
class Unk_DropText : public ASDisplayObject { public: void FUN_1422c4f00(const CStringW&); };
class Unk_DropInput : public ASDisplayObject { public: CStringW FUN_1422e0b00(); };
class Unk_DropButton : public ASDisplayObject { public: void FUN_1422ce240(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>&, void*); };
class Unk_DropSlot : public ASDisplayObject {
public:
    Unk_DropSlot(const Scaleform::GFx::Value&, int);
    void FUN_1422e4840(CString);
    void FUN_14015b020(); int FUN_140159bc0(); void FUN_140159ba0();
private:
    MS2_LAYOUT_FRIEND;
    void* m_pad_80;
};
MS2_CHECK_SIZE(Unk_DropSlot, 0x88);
class Unk_DropValue { public: bool FUN_1409b4d40() const; };
template <class T> Unk_DropHandle<T> MakeDropChild(int id, const Scaleform::GFx::Value& v) {
    Unk_DropHandle<T> h(new T(v, id));
    return h;
}
class Unk_DropScript : public CPtred {
public:
    Scaleform::GFx::Value FUN_1422baa20(const char*);
    template <class T> Unk_DropHandle<T> GetChild(const CString& name) {
        Scaleform::GFx::Value child = FUN_1422baa20(name);
        if (reinterpret_cast<const Unk_DropValue*>(&child)->FUN_1409b4d40())
            return MakeDropChild<T>(m_id, child);
        return Unk_DropHandle<T>(0);
    }
private:
    int m_id;
};
template <class T> Unk_DropHandle<T> UIItemDropInfoDialog::GetDropChild(const CString& name) {
    if (m_30 == NULL)
        return Unk_DropHandle<T>(0);
    return reinterpret_cast<Unk_DropScript*>(m_30.operator->())->GetChild<T>(name);
}
class Unk_DropList {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24(bool);
    virtual void vfunc_25(const Scaleform::GFx::Value&);
};
class Unk_ASBinding {
public:
    Unk_DropPtr<Unk_DropButton> FUN_140bbe640(const CString&, Unk_DropPtr<Unk_DropButton>&);
    Unk_DropPtr<Unk_DropText> FUN_140beaf20(const CString&, Unk_DropPtr<Unk_DropText>&);
    Unk_DropPtr<Unk_DropInput> FUN_140bbe940(const CString&, Unk_DropPtr<Unk_DropInput>&);
};
class Unk_1403ed2d0 { public: void* FUN_141bd0cc0(); };
Unk_1403ed2d0* FUN_1403ed2d0();
class ASTooltip : public AScript {
public: ASTooltip(void*, int, int); virtual ~ASTooltip(); int FUN_1409e0d40(CItem*);
private: void* m_40; void* m_48; void* m_50; void* m_58;
};
MS2_CHECK_SIZE(ASTooltip, 0x60);
void FUN_141415600(const CString&);
void FUN_141415450(const CString&, MS2Ptr<CItem>, int, int, int);
CStringW FUN_141425950(int);
CStringW FUN_14183e9c0(CStringW, int);
int FUN_1407181a0(const CStringW&);
CStringW FUN_140323ab0(const wchar_t*, const int&, const int&);
void FUN_141361e60(CStringW);
int FUN_14053feb0(int);
class Unk_1401a9d70 { public: CStringW FUN_141813150(int); };
Unk_1401a9d70* FUN_1401a9d70();
class Unk_DropRef { public: void* m_08; };
int FUN_140159bc0(Unk_DropRef*);
void FUN_140159ba0(Unk_DropRef*);
void FUN_14015b020(Unk_DropRef*);
class Unk_DropEntry : public Unk_DropRef {
public:
    virtual int vfunc_0();
    virtual int vfunc_1();
    void* m_10; void* m_18;
    int m_20; int m_min; int m_max;
};
MS2_CHECK_OFFSET(Unk_DropEntry, m_min, 0x24);
MS2_CHECK_OFFSET(Unk_DropEntry, m_max, 0x28);
template <> Unk_DropEntry* MS2Ptr<Unk_DropEntry>::get() const { return m_p; }  // COMDAT first instantiated here
// The rest of the MS2Ptr<Unk_DropEntry> COMDAT chain (shared with a sibling unit; defined here so the DLL links).
// @0x1403038d0
template <> void MS2Ptr<Unk_DropEntry>::Reference(Unk_DropEntry* p) { FUN_14015b020(p); }
// @0x14030d460
template <> void MS2Ptr<Unk_DropEntry>::ReleaseImpl(void*) {
    if (FUN_140159bc0(m_p) == 0) {
        Reference(m_p);
        FUN_140159ba0(m_p);
    }
}
// @0x14030d010
template <> void MS2Ptr<Unk_DropEntry>::Release() { if (m_p) { ReleaseImpl((Unk_DropRef*)(Unk_DropEntry*)0); m_p = 0; } }
// @0x1402fee10
template <> MS2Ptr<Unk_DropEntry>::~MS2Ptr() { Release(); }
class Unk_1405a1fd0 { public: void FUN_1402eab20(int, std::vector<MS2Ptr<Unk_DropEntry>>&); };
Unk_1405a1fd0* FUN_1405a1fd0();
MS2Ptr<Unk_ItemData> FUN_14053f870(int);
class ASObj : public AScript {
public: ASObj(int); virtual ~ASObj();
    void FUN_1409c5bd0(Unk_DropEntry*);
    void FUN_1407cb9c0(const char*, int);
    void FUN_1407cbb20(const char*, CStringW);
};
class Unk_DropArray : public AScript {
public: Unk_DropArray(int); virtual ~Unk_DropArray(); bool FUN_1422bc050(Scaleform::GFx::Value);
};
MS2_CHECK_SIZE(ASObj, 0x40);
MS2_CHECK_SIZE(Unk_DropArray, 0x40);
CStringW FUN_1409eb450(int);
CStringW FUN_1401e8510(const wchar_t*, const CStringW&);
CStringW FUN_140656190(const wchar_t*, const CStringW&, const CStringW&);

// Unk_DropPtr<T> members whose COMDATs are first instantiated in this unit (the others are declared only).
#define MS2_DROPPTR_ASSIGN(T) \
    template <> Unk_DropPtr<T>& Unk_DropPtr<T>::operator=(T* p) { \
        Unk_DropPtr temp(p); \
        T* old = m_p; \
        m_p = temp.m_p; \
        temp.m_p = old; \
        return *this; \
    }
MS2_DROPPTR_ASSIGN(Unk_DropButton)
MS2_DROPPTR_ASSIGN(Unk_DropText)
MS2_DROPPTR_ASSIGN(Unk_DropList)
template <> Unk_DropPtr<Unk_DropList>::Unk_DropPtr() : m_p(0) {}
template <> Unk_DropPtr<Unk_DropList>& Unk_DropPtr<Unk_DropList>::operator=(const Unk_DropPtr& o) {
    o.AddRef();
    Release();
    m_p = o.m_p;
    return *this;
}
// @0x140c39fd0
UIItemDropInfoDialog::UIItemDropInfoDialog() {
    m_40 = 1;
    m_slot = "UIItemDropInfoDialog_slot";
}
// @0x140c3a0f0
CString UIItemDropInfoDialog::GetTypeName() { return "ItemDropInfoDialog"; }
MS2_REPLACE_METHOD(0x140C3A0F0, UIItemDropInfoDialog, GetTypeName, 61, 0x3F9626B1);
// @0x140c3a140
void UIItemDropInfoDialog::OnLoadComplete() {
    UIDialog::OnLoadComplete();
    m_list = FUN_140ba4b70("m_list");
    if (m_list == NULL) vfunc_67();
    do {
        reinterpret_cast<Unk_ASBinding*>(m_30.operator->())->FUN_140bbe640("m_dropMode", m_drop);
        if (m_drop == NULL)
            throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError", MS2_THIS_FILE, MS2_LINE(44), __FUNCTION__));
    } while (0);
    do {
        reinterpret_cast<Unk_ASBinding*>(m_30.operator->())->FUN_140bbe640("m_testMode", m_test);
        if (m_test == NULL)
            throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError", MS2_THIS_FILE, MS2_LINE(45), __FUNCTION__));
    } while (0);
    do {
        reinterpret_cast<Unk_ASBinding*>(m_30.operator->())->FUN_140beaf20("m_itemName", m_name);
        if (m_name == NULL)
            throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError", MS2_THIS_FILE, MS2_LINE(46), __FUNCTION__));
    } while (0);
    do {
        reinterpret_cast<Unk_ASBinding*>(m_30.operator->())->FUN_140bbe940("m_dropCount", m_count);
        if (m_count == NULL)
            throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError", MS2_THIS_FILE, MS2_LINE(47), __FUNCTION__));
    } while (0);
    m_test->FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIItemDropInfoDialog::FUN_140c3b6f0), m_test.get());
    m_drop->FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIItemDropInfoDialog::FUN_140c3b6f0), m_drop.get());
    FUN_140c3ad20();
    FUN_140c3af70();
}
MS2_REPLACE_METHOD(0x140C3A140, UIItemDropInfoDialog, OnLoadComplete, 2316, 0xD90D0430);
// @0x140c3aae0
void UIItemDropInfoDialog::vfunc_26() {
    UIDialog::vfunc_26();
    FUN_141415600(m_slot);
    m_item.AssignRaw(0);
    m_list = NULL;
    m_drop = NULL;
    m_test = NULL;
    m_name = NULL;
    m_count = NULL;
    m_items.RemoveAll();
}
MS2_REPLACE_METHOD(0x140C3AAE0, UIItemDropInfoDialog, vfunc_26, 188, 0xAC8F9059);
// @0x140c3abb0
void UIItemDropInfoDialog::vfunc_49(Scaleform::GFx::Value* result, ASData* args) {
    UIObject::vfunc_49(result, args);
    unsigned int index = args->FUN_1422b8b10();
    if (m_items.IsEmpty()) return;
    if (index >= m_items.GetCount()) return;
    MS2Ptr<CItem> item(m_items.GetAt(index));
    if (item == NULL) return;
    void* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    ASTooltip tooltip(player,0x20,2);
    if (tooltip.FUN_1409e0d40(item.get())) *result = tooltip.FUN_1422bb870();
}
MS2_REPLACE_METHOD(0x140C3ABB0, UIItemDropInfoDialog, vfunc_49, 355, 0xDBDBD9E1);
// @0x140c3ad20
void UIItemDropInfoDialog::FUN_140c3ad20() {
    if (m_item == NULL) return;
    FUN_141415600(m_slot);
    FUN_141415450(m_slot,m_item,0,0,0);
    Unk_DropHandle<Unk_DropSlot> slot = GetDropChild<Unk_DropSlot>("m_itemSlot");
    if (slot.get()) slot->FUN_1422e4840(m_slot);
    if (m_name.get()) {
        CStringW name = FUN_141425950(m_item->FUN_1405276c0());
        CStringW label = FUN_14183e9c0(name, m_item->FUN_140526bd0());
        m_name->FUN_1422c4f00(label);
    }
}
MS2_REPLACE_METHOD(0x140C3AD20, UIItemDropInfoDialog, FUN_140c3ad20, 578, 0x5553B0EC);
// @0x140c3af70
void UIItemDropInfoDialog::FUN_140c3af70() {
    m_items.RemoveAll();
    if (m_list == NULL || m_item == NULL) return;
    MS2Ptr<Unk_ItemData> data(m_item->FUN_140527840());
    if (data == NULL) return;
    if (m_box == 0) return;
    std::vector<MS2Ptr<Unk_DropEntry>> entries;
    FUN_1405a1fd0()->FUN_1402eab20(m_box, entries);
    Unk_DropArray array(2);
    for (auto& entry : entries) {
        MS2Ptr<Unk_ItemData> info = FUN_14053f870(entry->vfunc_0());
        if (info == NULL) continue;
        MS2Ptr<CItem> item(new CItem);
        if (!item->FUN_14052b130(entry->vfunc_0(),entry->vfunc_1(),0)) continue;
        ASObj obj(2);
        obj.FUN_1409c5bd0(entry.get());
        obj.FUN_1407cb9c0(s_itemCount,0);
        {
            CStringW range;
            if (entry->m_min == entry->m_max) range = FUN_1401e8510(L"{0}",FUN_1409eb450(entry->m_min));
            else range = FUN_140656190(L"{0} ~ {1}",FUN_1409eb450(entry->m_min),FUN_1409eb450(entry->m_max));
            obj.FUN_1407cbb20("rangeCount",range);
        }
        array.FUN_1422bc050(obj.FUN_1422bb870());
        m_items.Add(item);
    }
    m_list->vfunc_25(array.FUN_1422bb870());
    m_list->vfunc_24(1);
}
MS2_REPLACE_METHOD(0x140C3AF70, UIItemDropInfoDialog, FUN_140c3af70, 1646, 0x97FF2445);
// @0x140c3b5f0
CStringW UIItemDropInfoDialog::FUN_140c3b5f0(int id) {
    return FUN_1401a9d70()->FUN_141813150(id);
}
MS2_REPLACE_METHOD(0x140C3B5F0, UIItemDropInfoDialog, FUN_140c3b5f0, 71, 0xFC4CFB82);
// @0x140c3b640
int UIItemDropInfoDialog::FUN_140c3b640() {
    if (m_count == NULL) return 1;
    return (std::max)(FUN_1407181a0(m_count->FUN_1422e0b00()),1);
}
MS2_REPLACE_METHOD(0x140C3B640, UIItemDropInfoDialog, FUN_140c3b640, 163, 0xA12099C5);
// @0x140c3b6f0
void UIItemDropInfoDialog::FUN_140c3b6f0(const Scaleform::GFx::FunctionHandler::Params& params) {
    int count = FUN_140c3b640();
    if (params.pUserData == m_test.get()) FUN_141361e60(FUN_140323ab0(L"DropBox {0} {1} 0 t",m_box,count));
    else if (params.pUserData == m_drop.get()) FUN_141361e60(FUN_140323ab0(L"DropBox {0} {1}",m_box,count));
}
MS2_REPLACE_METHOD(0x140C3B6F0, UIItemDropInfoDialog, FUN_140c3b6f0, 217, 0x7CE52B06);
// @0x140c3b7d0
void UIItemDropInfoDialog::FUN_140c3b7d0(int item, int box) {
    if (m_item.get() ? true : false) { if (m_item->FUN_1405276c0() == item) return; }
    m_box = box;
    reinterpret_cast<Unk_ItemPtrSetter*>(&m_item)->FUN_1401bffe0(new CItem);
    if (!m_item->FUN_14052b130(item,FUN_14053feb0(item),0)) vfunc_67();
    else if (FUN_141924630()) { FUN_140c3ad20(); FUN_140c3af70(); }
}
MS2_REPLACE_METHOD(0x140C3B7D0, UIItemDropInfoDialog, FUN_140c3b7d0, 324, 0x271E3FA9);
// @0x140c3b920
int UIItemDropInfoDialog::FUN_140c3b920() {
    if (m_item == NULL) return 0;
    return m_item->FUN_1405276c0();
}
MS2_REPLACE_METHOD(0x140C3B920, UIItemDropInfoDialog, FUN_140c3b920, 73, 0xAEEFD1E3);
MS2_EMIT_CRT_MEMMOVE_S();
