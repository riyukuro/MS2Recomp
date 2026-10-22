// Recovered pet box dialog (the Lullu box: opens one or ten pet boxes with a key, shows the obtained pets as rendered
// avatar cards). Unk_ names are local reconstruction names.
#pragma once
#include <set>
#include <vector>
#include "uiskillpreviewdialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/commonfiles/itemgift.h"
#include "ms2/commonfiles/commonstruct_wa.h"
class CMsgBoxData;
class UIAvatarPet;
class ASMovieClip;
class Unk_PetBoxButton;
class Unk_PetBoxCheck;
// Orders the set of dropped pets (the comparator is the ItemEntity ordering of commonfiles\commonstruct).
struct Unk_PetBoxLess
{
    bool operator()(const ItemEntity& a, const ItemEntity& b) const { return FUN_14026aeb0(a, b); }
};
// One obtained pet: the rendered avatar and the AS clip (m_petCard) it is shown in. The user-declared ctor and dtor
// make the vector's element destroy go through the scalar deleting dtor (0x140e540a0).
struct Unk_PetBoxCard
{
    // @0x140e53ea0
    Unk_PetBoxCard() {}
    // @0x140e53f90
    ~Unk_PetBoxCard() {}
    Unk_PetBoxCard(const Unk_PetBoxCard&) = default;
    Unk_PetBoxCard(Unk_PetBoxCard&&) = default;
    MS2Ptr<UIAvatarPet> m_avatar;       // +0x00
    MS2Ptr<ASMovieClip> m_clip;         // +0x10
};
MS2_CHECK_SIZE(Unk_PetBoxCard, 0x20);
class UIItemPetBoxDialog : public UIDialog, public IUIAvatarEventListener
{
public:
    UIItemPetBoxDialog();
    virtual ~UIItemPetBoxDialog();
    virtual CString GetTypeName();
    virtual int vfunc_65();
    virtual void vfunc_26();
    virtual void vfunc_67();
    virtual void OnLoadComplete();
    virtual void vfunc_79(void*);
    virtual int vfunc_28(const char*, const Scaleform::GFx::Value*, unsigned int);
    virtual void vfunc_25(void*, TPtr<Unk_UISwfEntity_25>, void*, void*);
    virtual void vfunc_16();
    virtual bool vfunc_17();
    virtual int vfunc_o178_1(void*);
    // @0x140e54120
    virtual int vfunc_48() { return 20268; }
    void FUN_140e4f6d0(int);
    void FUN_140e4f7d0();
    void FUN_140e4f8e0();
    void FUN_140e4f9a0();
    void FUN_140e4f9e0();
    void FUN_140e4fa60(const Scaleform::GFx::FunctionHandler::Params&);
    void FUN_140e4fb70(const Scaleform::GFx::FunctionHandler::Params&);
    void SetBoxItemId(int);
    bool FUN_140e4fc50(int, const CMsgBoxData&);
    bool FUN_140e4fc90(const ItemEntity&);
    bool FUN_140e4fd60();
    void FUN_140e504e0();
    void FUN_140e511f0();
    void FUN_140e519b0(MS2Ptr<ASMovieClip>, const ItemEntity&);
    int FUN_140e51ca0();
    void FUN_140e51e40();
    void FUN_140e52110();
    MS2Ptr<Unk_PetBoxCheck> FUN_140e52670(const CString&);
    MS2Ptr<Unk_PetBoxCheck> FUN_140e52700(const CString&, MS2Ptr<Unk_PetBoxCheck>&);
    MS2Ptr<Unk_PetBoxButton> FUN_140bc6d10(const CString&, MS2Ptr<Unk_PetBoxButton>&);
    MS2Ptr<ASMovieClip> FUN_140c57ce0(const CString&, MS2Ptr<ASMovieClip>&);
private:
    MS2_LAYOUT_FRIEND;
    int m_boxItemId;                            // +0x180 item id of the box that is being opened
    CString m_bagId;                            // +0x188 "bagId" of the key items (ItemLullu_...)
    Unk_ItemVec m_result;                       // +0x190 the obtained items (std::vector<ItemEntity>)
    Unk_StrVec m_slotBinds;                     // +0x1a8 the "binding" strings handed to the AS slots
    std::set<ItemEntity, Unk_PetBoxLess> m_special1;    // +0x1c0
    std::set<ItemEntity, Unk_PetBoxLess> m_special2;    // +0x1d0 items of the second set (flag read from the packet)
    bool m_multi;                               // +0x1e0 ten at a time
    bool m_sent;                                // +0x1e1 the open request was sent
    MS2Ptr<Unk_PetBoxButton> m_singleOpen;      // +0x1e8
    MS2Ptr<Unk_PetBoxButton> m_multiOpen;       // +0x1f8
    MS2Ptr<Unk_PetBoxCheck> m_skipEffect;       // +0x208
    MS2Ptr<ASMovieClip> m_itemBox;              // +0x218
    MS2Ptr<ASMovieClip> m_resultItem;           // +0x228
    MS2Ptr<ASMovieClip> m_previewSingle;        // +0x238
    MS2Ptr<ASMovieClip> m_previewMulti;         // +0x248
    MS2Ptr<Unk_PetBoxButton> m_closeSingle;     // +0x258
    MS2Ptr<Unk_PetBoxButton> m_closeMulti;      // +0x268
    std::vector<Unk_PetBoxCard> m_cards;        // +0x278
};
MS2_CHECK_SIZE(UIItemPetBoxDialog, 0x290);
MS2_CHECK_OFFSET(UIItemPetBoxDialog, m_boxItemId, 0x180);
MS2_CHECK_OFFSET(UIItemPetBoxDialog, m_bagId, 0x188);
MS2_CHECK_OFFSET(UIItemPetBoxDialog, m_result, 0x190);
MS2_CHECK_OFFSET(UIItemPetBoxDialog, m_slotBinds, 0x1a8);
MS2_CHECK_OFFSET(UIItemPetBoxDialog, m_special1, 0x1c0);
MS2_CHECK_OFFSET(UIItemPetBoxDialog, m_special2, 0x1d0);
MS2_CHECK_OFFSET(UIItemPetBoxDialog, m_multi, 0x1e0);
MS2_CHECK_OFFSET(UIItemPetBoxDialog, m_singleOpen, 0x1e8);
MS2_CHECK_OFFSET(UIItemPetBoxDialog, m_skipEffect, 0x208);
MS2_CHECK_OFFSET(UIItemPetBoxDialog, m_itemBox, 0x218);
MS2_CHECK_OFFSET(UIItemPetBoxDialog, m_closeMulti, 0x268);
MS2_CHECK_OFFSET(UIItemPetBoxDialog, m_cards, 0x278);
