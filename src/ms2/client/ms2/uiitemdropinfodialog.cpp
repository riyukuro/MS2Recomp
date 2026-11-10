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
#include "ms2/placeholder/cstringtable.h"
#include "ms2/commonfiles/itemdroptable.h"
#include "ms2/placeholder/asbutton.h"  // C3: ASButton::FUN_1422ce240
#include "ms2/placeholder/astextinput.h"   // C3: ASTextInput::FUN_1422e0b00
#include "ms2/placeholder/citem.h"   // C3: the real CItem
#include "ms2/placeholder/astextfield.h"   // C3: ASTextField::FUN_1422c4f00
#include "ms2/gfxui/asmdragtarget.h"   // C3: the item slot child

// Unit-local declarations; Unk names and member names are invented.
class CItemData;
// C3: CItem is the real class (citem.h)
#include "ms2/placeholder/astilelist.h"   // C3: the m_list child
template <class T> Unk_DropHandle<T> MakeDropChild(int id, const Scaleform::GFx::Value& v) {
    Unk_DropHandle<T> h(new T(v, id));
    return h;
}
class Unk_DropScript : public CPtred {
public:
    template <class T> Unk_DropHandle<T> GetChild(const CString& name) {
        Scaleform::GFx::Value child = reinterpret_cast<AScript*>(this)->GetMember(name);
        if (child.IsObject())
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
template <> MS2Ptr<ASTileList> UISwfEntity::GetChild<ASTileList>(const CString& strName);   // C3: was FUN_140ba4b70
class WorldService { public: static WorldService* GetInstance(); void* GetLocalPlayer(); };   // C3: member view
class ASTooltip : public AScript {
public: ASTooltip(void*, int, int); virtual ~ASTooltip(); int FUN_1409e0d40(CItem*);
private: void* m_40; void* m_48; void* m_50; void* m_58;
};
MS2_CHECK_SIZE(ASTooltip, 0x60);
void DestroyItemInfoSlot(const CString&);
void CreateItemInfoSlot(const CString&, MS2Ptr<CItem>, int, int, int);
CStringW GetItemDisplayName(unsigned);
CStringW FUN_14183e9c0(CStringW, int);
int FUN_1407181a0(const CStringW&);
class CUserCommandCli { public: static void SendCommand(CStringW); };   // C3: member view
int GetItemRank(int);
// C3: Unk_DropRef / Unk_DropEntry were the ItemDropResult view (itemdroptable.h): GetBoxItems fills a
// vector<MS2Ptr<ItemDropResult>>; vfunc_0/1 = ItemAble::vfunc_o18_0/1, m_min/m_max = m_count/m_maxCount (+0x24/+0x28).
// The MS2Ptr<ItemDropResult> Reference/ReleaseImpl/Release/~MS2Ptr COMDATs come from itemdroptable.h / itemdroptable.cpp.
template <> ItemDropResult* MS2Ptr<ItemDropResult>::get() const { return m_p; }  // COMDAT first instantiated here (0x140c3c690)
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
MS2Ptr<CItemData> FUN_14053f870(int);
typedef AScript ASObj;   // FUN_1409c5bd0 is AScript's (ascript.h)



class ASArray : public AScript {
public: int PushValue(Scaleform::GFx::Value);
};
class ASDataProvider : public ASArray {
public: ASDataProvider(int); virtual ~ASDataProvider();
};

MS2_CHECK_SIZE(ASDataProvider, 0x40);
CStringW FUN_1409eb450(int);

class Unk_CoupleInput;
// MS2Ptr<T> members whose COMDATs are first instantiated in this unit (the others are declared only).
#define MS2_DROPPTR_ASSIGN(T) \
    template <> MS2Ptr<T>& MS2Ptr<T>::AssignRaw(T* p) { \
        MS2Ptr temp(p); \
        T* old = m_p; \
        m_p = temp.m_p; \
        temp.m_p = old; \
        return *this; \
    }
MS2_DROPPTR_ASSIGN(ASButton)
MS2_DROPPTR_ASSIGN(ASTextField)
MS2_DROPPTR_ASSIGN(ASTileList)
// inline: the ms2ptr_impl.h units instantiate the same two COMDATs.
template <> inline MS2Ptr<ASTileList>::MS2Ptr() : m_p(0) {}
template <> inline MS2Ptr<ASTileList>& MS2Ptr<ASTileList>::operator=(const MS2Ptr& o) {
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
    m_list = GetChild<ASTileList>("m_list");
    if (m_list == NULL) vfunc_67();
    do {
        m_30->FUN_140bbe640("m_dropMode", m_drop);
        if (m_drop == NULL)
            throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError", MS2_THIS_FILE, MS2_LINE(44), __FUNCTION__));
    } while (0);
    do {
        m_30->FUN_140bbe640("m_testMode", m_test);
        if (m_test == NULL)
            throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError", MS2_THIS_FILE, MS2_LINE(45), __FUNCTION__));
    } while (0);
    do {
        m_30->FUN_140beaf20("m_itemName", m_name);
        if (m_name == NULL)
            throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError", MS2_THIS_FILE, MS2_LINE(46), __FUNCTION__));
    } while (0);
    do {
        m_30->FUN_140bbe940("m_dropCount", m_count);
        if (m_count == NULL)
            throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError", MS2_THIS_FILE, MS2_LINE(47), __FUNCTION__));
    } while (0);
    m_test->AddClickHandler(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIItemDropInfoDialog::OnClickDropOrTestButton), m_test.operator ASButton*());
    m_drop->AddClickHandler(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIItemDropInfoDialog::OnClickDropOrTestButton), m_drop.operator ASButton*());
    UpdateItemDisplay();
    FUN_140c3af70();
}
MS2_REPLACE_METHOD(0x140C3A140, UIItemDropInfoDialog, OnLoadComplete, 2316, 0xD90D0430);
// @0x140c3aae0
void UIItemDropInfoDialog::vfunc_26() {
    UIDialog::vfunc_26();
    DestroyItemInfoSlot(m_slot);
    m_item.AssignRaw(0);
    m_list.AssignRaw(NULL);
    m_drop.AssignRaw(NULL);
    m_test.AssignRaw(NULL);
    m_name.AssignRaw(NULL);
    reinterpret_cast<MS2Ptr<Unk_CoupleInput>&>(m_count).AssignRaw(NULL);   // the exe calls the twin at 0x140bf1810
    m_items.RemoveAll();
}
MS2_REPLACE_METHOD(0x140C3AAE0, UIItemDropInfoDialog, vfunc_26, 188, 0xAC8F9059);
// @0x140c3abb0
void UIItemDropInfoDialog::vfunc_49(Scaleform::GFx::Value* result, ASData* args) {
    UIObject::vfunc_49(result, args);
    unsigned int index = args->PopUInt();
    if (m_items.IsEmpty()) return;
    if (index >= m_items.GetCount()) return;
    MS2Ptr<CItem> item(m_items.GetAt(index));
    if (item == NULL) return;
    void* player = WorldService::GetInstance()->GetLocalPlayer();
    ASTooltip tooltip(player,0x20,2);
    if (tooltip.FUN_1409e0d40(item.get())) *result = tooltip.GetValue();
}
MS2_REPLACE_METHOD(0x140C3ABB0, UIItemDropInfoDialog, vfunc_49, 355, 0xDBDBD9E1);
// @0x140c3ad20
void UIItemDropInfoDialog::UpdateItemDisplay() {
    if (m_item == NULL) return;
    DestroyItemInfoSlot(m_slot);
    CreateItemInfoSlot(m_slot,m_item,0,0,0);
    Unk_DropHandle<ASMDragTarget> slot = GetDropChild<ASMDragTarget>("m_itemSlot");
    if (slot.get()) slot->SetBinding(m_slot);
    if (m_name.get()) {
        CStringW name = GetItemDisplayName(m_item->GetItemId());
        CStringW label = FUN_14183e9c0(name, m_item->GetRarity());
        m_name->SetTextHTMLW(label);
    }
}
MS2_REPLACE_METHOD(0x140C3AD20, UIItemDropInfoDialog, UpdateItemDisplay, 578, 0x5553B0EC);
// @0x140c3af70
void UIItemDropInfoDialog::FUN_140c3af70() {
    m_items.RemoveAll();
    if (m_list == NULL || m_item == NULL) return;
    MS2Ptr<CItemData> data((CItemData*)m_item->GetData());
    if (data == NULL) return;
    if (m_box == 0) return;
    std::vector<MS2Ptr<ItemDropResult>> entries;
    TSingleton<ItemDropTable>::GetInstance()->GetBoxItems(m_box, entries);
    ASDataProvider array(2);
    for (auto& entry : entries) {
        MS2Ptr<CItemData> info = FUN_14053f870(entry->vfunc_o18_0());
        if (info == NULL) continue;
        MS2Ptr<CItem> item(new CItem);
        if (!item->FUN_14052b130(entry->vfunc_o18_0(),entry->vfunc_o18_1(),0)) continue;
        ASObj obj(2);
        obj.FUN_1409c5bd0(entry.get());
        obj.SetIntMember(s_itemCount,0);
        {
            CStringW range;
            if (entry->m_count == entry->m_maxCount) range = StringFormat<CStringW>(L"{0}",FUN_1409eb450(entry->m_count));
            else range = StringFormat<CStringW, CStringW>(L"{0} ~ {1}",FUN_1409eb450(entry->m_count),FUN_1409eb450(entry->m_maxCount));
            obj.SetWStringMember("rangeCount",range);
        }
        array.PushValue(obj.GetValue());
        m_items.Add(item);
    }
    reinterpret_cast<Unk_DropList*>(m_list.operator->())->vfunc_25(array.GetValue());
    reinterpret_cast<Unk_DropList*>(m_list.operator->())->vfunc_24(1);
}
MS2_REPLACE_METHOD(0x140C3AF70, UIItemDropInfoDialog, FUN_140c3af70, 1646, 0x97FF2445);
// @0x140c3b5f0
CStringW UIItemDropInfoDialog::GetStringById(int id) {
    return TSingleton<CStringTable>::GetInstance()->GetRankName(id);
}
MS2_REPLACE_METHOD(0x140C3B5F0, UIItemDropInfoDialog, GetStringById, 71, 0xFC4CFB82);
// @0x140c3b640
int UIItemDropInfoDialog::GetDropCount() {
    if (m_count == NULL) return 1;
    return (std::max)(FUN_1407181a0(m_count->GetText()),1);
}
MS2_REPLACE_METHOD(0x140C3B640, UIItemDropInfoDialog, GetDropCount, 163, 0xA12099C5);
// @0x140c3b6f0
void UIItemDropInfoDialog::OnClickDropOrTestButton(const Scaleform::GFx::FunctionHandler::Params& params) {
    int count = GetDropCount();
    if (params.pUserData == m_test.operator ASButton*()) CUserCommandCli::SendCommand(StringFormat(L"DropBox {0} {1} 0 t",reinterpret_cast<const unsigned&>(m_box),count));
    else if (params.pUserData == m_drop.operator ASButton*()) CUserCommandCli::SendCommand(StringFormat(L"DropBox {0} {1}",reinterpret_cast<const unsigned&>(m_box),count));
}
MS2_REPLACE_METHOD(0x140C3B6F0, UIItemDropInfoDialog, OnClickDropOrTestButton, 217, 0x7CE52B06);
// @0x140c3b7d0
void UIItemDropInfoDialog::SetItemAndBox(int item, int box) {
    if (m_item.get() ? true : false) { if (m_item->GetItemId() == item) return; }
    m_box = box;
    m_item.AssignRaw(new CItem);
    if (!m_item->FUN_14052b130(item,GetItemRank(item),0)) vfunc_67();
    else if (FUN_141924630()) { UpdateItemDisplay(); FUN_140c3af70(); }
}
MS2_REPLACE_METHOD(0x140C3B7D0, UIItemDropInfoDialog, SetItemAndBox, 324, 0x271E3FA9);
// @0x140c3b920
int UIItemDropInfoDialog::GetItemId() {
    if (m_item == NULL) return 0;
    return m_item->GetItemId();
}
MS2_REPLACE_METHOD(0x140C3B920, UIItemDropInfoDialog, GetItemId, 73, 0xAEEFD1E3);
MS2_EMIT_CRT_MEMMOVE_S();
