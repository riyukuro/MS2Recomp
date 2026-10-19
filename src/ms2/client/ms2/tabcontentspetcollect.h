// tabcontentspetcollect.h - the pet collection tab of the pet system dialog: TabContentsPetCollect (RTTI
// .?AVTabContentsPetCollect@@, 0x48 bytes, bases PetSystemTabContents and IUIAvatarEventListener at +0x18). It lists the
// pet collection groups of Table/petCollectGroup.xml with the pets the player owns (and their grades), shows the
// pet tooltip and previews one pet in an avatar view.
// Owning unit: ?\tabcontentspetcollect.cpp (0x140cac530-0x140cb1d90, .text$di 0x1400cfa40). Header name assumed from the
// unit path. The member names are invented; the FUN_ names are exe addresses.
#pragma once

#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/petsystemtabcontents.h"
#include "ms2/placeholder/tptr.h"
#include "ms2/client/ms2/uiskillpreviewdialog.h"      // IUIAvatarEventListener

class UIAvatarPet;

class TabContentsPetCollect : public PetSystemTabContents, public IUIAvatarEventListener
{
public:
    TabContentsPetCollect();                            // 0x140cac530
    virtual ~TabContentsPetCollect() = default;                   //  0 (inline, ??_G 0x140cb0000)
    virtual void vfunc_1();                             //  1 0x140cac660 drop the UI
    virtual void vfunc_3(MS2Ptr<ASUIComponent> ui);     //  3 0x140cac5c0 attach the page's UI and fill it
    virtual void vfunc_4();                             //  4 0x140cad910 leave the tab
    virtual void vfunc_5(void* pOut, void* pName, void* pData);   // 5 0x140cad9a0 the pet tooltip
    virtual int vfunc_6(const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned nArgs);   // 6 0x140cae560
    virtual void vfunc_7(void* a1, TPtr<Unk_UISwfEntity_25> a2, void* a3, void* a4);   // 7 0x140cae970
    virtual int vfunc_8();                              //  8 0x140caed20 (2)
    virtual int vfunc_o178_0(void* pAvatar);            // IUIAvatarEventListener slot 0, 0x140caec50
    virtual int vfunc_o178_1(void* pAvatar);            // IUIAvatarEventListener slot 1, 0x140caec10

    void FUN_140cac6a0();                               // the "collected / total" count
    void FUN_140cac8a0();                               // the group tabs
    void FUN_140cacc30();                               // the pets of every group
    void FUN_140cacce0();                               // the pets of the "all" group
    void FUN_140cad2b0(int nGroup);                     // the pets of one group
    void FUN_140cad8a0(int nGroup);                     // go to a group (remembered while there is no UI)
    void FUN_140caed40();                               // load the render target
    void FUN_140caeda0();                               // unload the render target

    MS2Ptr<ASUIComponent> m_ui;                         // +0x20
    MS2Ptr<UIAvatarPet> m_avatar;                       // +0x30
    int m_nGroup;                                       // +0x40
};
MS2_CHECK_SIZE(TabContentsPetCollect, 0x48);
MS2_CHECK_OFFSET(TabContentsPetCollect, m_ui, 0x20);
MS2_CHECK_OFFSET(TabContentsPetCollect, m_avatar, 0x30);
