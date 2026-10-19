// itempreview.h - ItemPreview / ItemPreviewMgr (RTTI .?AVItemPreview@@ 0xb8, .?AVItemPreviewMgr@@ 0x28): the item preview of
// UIItemPreviewDialog (UI type 0x4ec2). ItemPreview keeps the previewed items and the avatar (UIAvatarPC / Cube / Ridee /
// Pet) they are put on; ItemPreviewMgr is the singleton that owns the current preview.
// Unit `?\itempreview.cpp` (.text$mn 0x140d3b9f0-0x140d418e0, vftables 0x142e2b1f8 / 0x142e2b218). Header name assumed;
// every name except the RTTI class names is invented from use.
#pragma once

#include <vector>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"

class PC;
class CItem;
class CItemData;
class UIAvatarBase;
class IUIAvatarEventListener;
class Unk_UISwfEntity_25;
template <class T> class TPtr;
namespace Scaleform { namespace GFx { class Value; } }

class ItemPreview : public CPtred
{
public:
    ItemPreview(PC* pPC, IUIAvatarEventListener* pListener, int nMode);    // 0x140d3b9f0
    virtual ~ItemPreview();                                 // 0x140d3baf0 (scalar deleting 0x140d41380)

    int FUN_140d3bc30();                                    // 0x140d3bc30 the avatar's object id
    int FUN_140d3bc90(MS2Ptr<CItem> spItem);                // 0x140d3bc90 preview one item
    int FUN_140d3c3c0(std::vector<MS2Ptr<CItem> > items);   // 0x140d3c3c0 preview the items on the player's avatar
    MS2Ptr<CItem> FUN_140d3c640();                          // 0x140d3c640 the shown item
    void FUN_140d3c690(std::vector<MS2Ptr<CItem> >& items); // 0x140d3c690 copy of the shown items
    MS2Ptr<CItem> FUN_140d3c710();                          // 0x140d3c710 the requested item
    MS2Ptr<CItem> FUN_140d3c760(MS2Ptr<CItem> spItem);      // 0x140d3c760 the item to show for an item
    MS2Ptr<CItemData> FUN_140d3ce10();                      // 0x140d3ce10 the item data shown
    MS2Ptr<UIAvatarBase> FUN_140d3cf00();                   // 0x140d3cf00 the avatar
    void FUN_140d3cf50();                                   // 0x140d3cf50 put the shown item on the cube avatar
    void FUN_140d3d010();                                   // 0x140d3d010 zoom in
    void FUN_140d3d070();                                   // 0x140d3d070 zoom out
    void FUN_140d3d0d0(void* p1, TPtr<Unk_UISwfEntity_25> spTarget, void* pArg, void* pUnused);   // 0x140d3d0d0 view attached
    int FUN_140d3d580(const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);  // 0x140d3d580
    void FUN_140d3d600(MS2Ptr<CItem> spItem);               // 0x140d3d600 set the camera for an item
    bool FUN_140d3de80(MS2Ptr<CItemData> spData);           // 0x140d3de80 shown on a character avatar
    void FUN_140d3e130();                                   // 0x140d3e130 reset the camera
    MS2Ptr<UIAvatarBase> FUN_140d3e2f0();                   // 0x140d3e2f0 avatar of the player
    MS2Ptr<UIAvatarBase> FUN_140d3e450(MS2Ptr<CItemData> spData, int nUnused, bool bDefault);    // 0x140d3e450 character avatar for an item
    MS2Ptr<UIAvatarBase> FUN_140d3e7d0(MS2Ptr<CItemData> spData, int nUnused);   // 0x140d3e7d0 cube avatar
    MS2Ptr<UIAvatarBase> FUN_140d3e8e0(MS2Ptr<CItemData> spData, int nUnused);   // 0x140d3e8e0 ridee avatar
    MS2Ptr<UIAvatarBase> FUN_140d3ea20(MS2Ptr<CItemData> spData, int nUnused);   // 0x140d3ea20 pet avatar
    void FUN_140d3eb30(MS2Ptr<CItem> spItem);               // 0x140d3eb30 put an item on the avatar
    void FUN_140d3f160(MS2Ptr<CItemData> spData, MS2Ptr<CItem> spItem);   // 0x140d3f160 put a package item on the avatar
    void FUN_140d3f3b0();                                   // 0x140d3f3b0 forget the package
    bool FUN_140d3f400(MS2Ptr<CItem> spItem);               // 0x140d3f400 add an item to the preview
    void FUN_140d3f9a0();                                   // 0x140d3f9a0 take everything off
    void FUN_140d3fa30();                                   // 0x140d3fa30 show the player's own equipment
    void FUN_140d3fac0(__int64 nItemUid);                   // 0x140d3fac0 take one item off
    bool FUN_140d3fda0(MS2Ptr<CItem> spItem);               // 0x140d3fda0 an item of the same id is shown
    void FUN_140d3fea0(MS2Ptr<CItem> spItem);               // 0x140d3fea0 replace the item of the same slot

private:
    MS2_LAYOUT_FRIEND;
    PC* m_pPC;                                              // +0x18
    MS2Ptr<CItem> m_spItem;                                 // +0x20 the requested item
    MS2Ptr<CItem> m_spPreview;                              // +0x30 the item shown
    std::vector<MS2Ptr<CItem> > m_items;                    // +0x40 the items shown
    MS2Ptr<UIAvatarBase> m_spAvatar;                        // +0x58
    IUIAvatarEventListener* m_pListener;                    // +0x68
    int m_nMode;                                            // +0x70 0 one item, 1 a set of items
    MS2Ptr<CItemData> m_spData;                             // +0x78 the item data shown
    MS2Ptr<CItemData> m_spPackageData;                      // +0x88 the package's own item
    ATL::CAtlArray<MS2Ptr<CItemData> > m_packageItems;      // +0x98 the package's items
};
MS2_CHECK_SIZE(ItemPreview, 0xb8);
MS2_CHECK_OFFSET(ItemPreview, m_pPC, 0x18);
MS2_CHECK_OFFSET(ItemPreview, m_items, 0x40);
MS2_CHECK_OFFSET(ItemPreview, m_spAvatar, 0x58);
MS2_CHECK_OFFSET(ItemPreview, m_nMode, 0x70);
MS2_CHECK_OFFSET(ItemPreview, m_packageItems, 0x98);

class UIItemPreviewDialog;

class ItemPreviewMgr : public TSingleton<ItemPreviewMgr>
{
public:
    ItemPreviewMgr();                                       // 0x140d3fff0
    virtual ~ItemPreviewMgr();                              // 0x140d40070 (scalar deleting 0x140d413c0)

    int FUN_140d400d0();                                    // 0x140d400d0 the avatar's object id
    int FUN_140d40120(MS2Ptr<CItem> spItem, int nArg);      // 0x140d40120 open the preview of an item
    MS2Ptr<CItem> FUN_140d40470();                          // 0x140d40470 the shown item
    MS2Ptr<CItem> FUN_140d40500();                          // 0x140d40500 the requested item
    MS2Ptr<CItemData> FUN_140d40590();                      // 0x140d40590 the item data shown
    MS2Ptr<ItemPreview> FUN_140d40620();                    // 0x140d40620 the preview
    int FUN_140d40670();                                    // 0x140d40670 the HUD is shown
    void FUN_140d40690();                                   // 0x140d40690 toggle the HUD
    void FUN_140d406d0(int bOn);                            // 0x140d406d0 show / hide the gamepad HUD
    void FUN_140d407d0();                                   // 0x140d407d0 drop the preview
    void FUN_140d40800();                                   // 0x140d40800 put the shown item on the cube avatar
    int FUN_140d40850();                                    // 0x140d40850 the argument of the open call
    void FUN_140d40870();                                   // 0x140d40870 zoom in
    void FUN_140d408c0();                                   // 0x140d408c0 zoom out
    void FUN_140d40910(void* p1, TPtr<Unk_UISwfEntity_25> spTarget, void* pArg, void* pUnused);  // 0x140d40910
    int FUN_140d409e0(const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);    // 0x140d409e0
    static UIItemPreviewDialog* FUN_140d40ab0(int nClass);  // 0x140d40ab0 the open preview dialog

private:
    MS2_LAYOUT_FRIEND;
    int m_nArg;                                             // +0x08
    int m_nUnk0c;                                           // +0x0c
    int m_bHudOn;                                           // +0x10
    MS2Ptr<ItemPreview> m_spPreview;                        // +0x18
};
MS2_CHECK_SIZE(ItemPreviewMgr, 0x28);
MS2_CHECK_OFFSET(ItemPreviewMgr, m_bHudOn, 0x10);
MS2_CHECK_OFFSET(ItemPreviewMgr, m_spPreview, 0x18);
