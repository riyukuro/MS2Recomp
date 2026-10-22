// uiweddingguestdialog.h - UIWeddingGuestDialog (RTTI .?AVUIWeddingGuestDialog@@, 0x1a8 bytes, UIDialog, UI id 0x4f94, swf
// "WeddingGuestDialog") and its pages UIWeddingGuestPage{Friend,Guild,Stranger} (the tabs "PageFriend", "PageGuild",
// "PageStranger"). The dialog picks the guests of the own wedding from the friend list, the guild or a searched stranger;
// "onAdd" hands the picked guests to the invitation dialog (0x4f8e). Owning unit: ?\uiweddingguestdialog.cpp. Header name
// assumed from the unit path; member names are invented from use, vfunc_N are vftable slots.
#pragma once
#include <afx.h>
#include <map>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/weddingguest.h"
#include "uidialog.h"

class UIWeddingGuestDialog;
class UIWeddingInvitationDialog;
class ASTextField;
class Unk_GsTab;
class Unk_GsList;
class Unk_GsPageScript;
struct Unk_GsFound;
class CBuddy;
class CGuildMember;
template <class T> class Unk_BuddyPtr;

// A page of the dialog: owns the AS object of its page movie clip and points back at the dialog.
class UIWeddingGuestPage : public CPtred
{
public:
    UIWeddingGuestPage(UIWeddingGuestDialog* pDialog);                      // 0x140fd6bc0
    virtual ~UIWeddingGuestPage();                                          //  0 0x140fd6c30 (??_G 0x140fd8c80)

    virtual bool vfunc_1();                                                 //  1 0x140fd6c70 binds the page movie clip ("m_currentPage")
    virtual void vfunc_2();                                                 //  2 0x140fd6dd0 drops the page AS object
    virtual void vfunc_3();                                                 //  3 0x140fd6e00
    virtual bool vfunc_4(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                            //  4 0x140fd6e10 false
    virtual void vfunc_5();                                                 //  5 0x140fd6e30
    virtual CString vfunc_6() = 0;                                          //  6 the page key
    virtual CStringW vfunc_7() = 0;                                         //  7 the tab label

    MS2Ptr<AScript> GetScript();                                        // 0x140fd6e40 the page AS object
    UIWeddingGuestDialog* GetDialog();                                  // 0x140fd6e90 the dialog

    MS2Ptr<AScript> m_pScript;                                              // +0x18
    UIWeddingGuestDialog* m_pDialog;                                        // +0x28
};
MS2_CHECK_SIZE(UIWeddingGuestPage, 0x30);

class UIWeddingGuestPageFriend : public UIWeddingGuestPage
{
public:
    UIWeddingGuestPageFriend(UIWeddingGuestDialog* pDialog);                // 0x140fd6eb0
    virtual ~UIWeddingGuestPageFriend();                                    //  0 0x140fd8b90 (??_G 0x140fd8cc0)
    virtual bool vfunc_1();                                                 //  1 0x140fd6ef0 fills "m_list" from the friend list
    virtual bool vfunc_4(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                            //  4 0x140fd7570 onSelectCheckbox
    virtual CString vfunc_6();                                              //  6 0x140fd74b0 "PageFriend"
    virtual CStringW vfunc_7();                                             //  7 0x140fd7500
};
MS2_CHECK_SIZE(UIWeddingGuestPageFriend, 0x30);

class UIWeddingGuestPageGuild : public UIWeddingGuestPage
{
public:
    UIWeddingGuestPageGuild(UIWeddingGuestDialog* pDialog);                 // 0x140fd77c0
    virtual ~UIWeddingGuestPageGuild();                                     //  0 0x140fd8bb0 (??_G 0x140fd8d00)
    virtual bool vfunc_1();                                                 //  1 0x140fd7800 fills "m_list" from the guild members
    virtual bool vfunc_4(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                            //  4 0x140fd7e90 onSelectCheckbox
    virtual CString vfunc_6();                                              //  6 0x140fd7dd0 "PageGuild"
    virtual CStringW vfunc_7();                                             //  7 0x140fd7e20

    MS2Ptr<CGuildMember> FUN_140fd80e0(const CStringW& strName);            // 0x140fd80e0 find a guild member by name
};
MS2_CHECK_SIZE(UIWeddingGuestPageGuild, 0x30);

class UIWeddingGuestPageStranger : public UIWeddingGuestPage
{
public:
    typedef MS2Ptr<WeddingGuest> GuestPtr;

    UIWeddingGuestPageStranger(UIWeddingGuestDialog* pDialog);              // 0x140fd8230
    virtual ~UIWeddingGuestPageStranger();                                  //  0 0x140fd8bd0 (??_G 0x140fd8d40)
    virtual bool vfunc_1();                                                 //  1 0x140fd8290 lists the found strangers
    virtual void vfunc_3();                                                 //  3 0x140fd8640 forget the strangers
    virtual bool vfunc_4(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                            //  4 0x140fd8670 onFind / onSelectCheckbox
    virtual CString vfunc_6();                                              //  6 0x140fd8580 "PageStranger"
    virtual CStringW vfunc_7();                                             //  7 0x140fd85d0

    void FUN_140fd88e0(GuestPtr spGuest);                                   // 0x140fd88e0 add a found stranger

    std::map<CStringW, GuestPtr> m_strangers;                               // +0x30
};
MS2_CHECK_SIZE(UIWeddingGuestPageStranger, 0x40);

class UIWeddingGuestDialog : public UIDialog
{
public:
    typedef MS2Ptr<WeddingGuest> GuestPtr;
    typedef MS2Ptr<UIWeddingGuestPage> PagePtr;

    UIWeddingGuestDialog();                                                 // 0x140fcc860
    virtual ~UIWeddingGuestDialog();                                        //  0 0x140fccab0 (??_G 0x140fd3a30)
    virtual CString vfunc_1();                                              //  1 0x140fccb30 "WeddingGuestDialog"
    virtual void OnLoadComplete();                                          // 22 0x140fccc00 tabs and the counter
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                            // 28 0x140fcce80 onAddPage / onRemovePage / onAdd / CanAdd
    virtual void vfunc_43();                                                // 43 0x140fccd50 dock beside the character window
    virtual int vfunc_48() { return 0x4f94; }                               // 48 0x140fd3a80 UI type id
    virtual int vfunc_65();                                                 // 65 0x140fccb80
    virtual void vfunc_67();                                                // 67 0x140fccbe0

    void FUN_140fcd5b0(Unk_GsFound* pFound);                                 // 0x140fcd5b0 a stranger was found
    void FUN_140fcd850(GuestPtr spGuest);                                   // 0x140fcd850 pick a guest
    void FUN_140fcd9d0(const CStringW& strName);                            // 0x140fcd9d0 unpick a guest
    bool FUN_140fcdb30(const CStringW& strName);                            // 0x140fcdb30 is the name picked
    void FUN_140fcdba0();                                                   // 0x140fcdba0 forget the picked guests
    void FUN_140fcdc50(PagePtr spPage);                                     // 0x140fcdc50 register a page by its key
    void FUN_140fcdcf0();                                                   // 0x140fcdcf0 fill the "m_tab" strip
    bool FUN_140fcdf30(const CStringW& strName);                            // 0x140fcdf30 may that name be added
    int FUN_140fce0a0();                                                    // 0x140fce0a0 invitations still allowed

    MS2Ptr<ASTextField> FUN_140bb4cf0(const CString& strName);              // 0x140bb4cf0 text field child lookup
    MS2Ptr<Unk_GsTab> FUN_140c02870(const CString& strName);                // 0x140c02870 tab strip child lookup

    MS2_LAYOUT_FRIEND;
    PagePtr m_spPage;                                                       // +0x178 the shown page
    std::map<CString, PagePtr> m_pages;                                     // +0x188 by key
    std::map<CStringW, GuestPtr> m_guests;                                  // +0x198 the picked guests by name
};
MS2_CHECK_SIZE(UIWeddingGuestDialog, 0x1a8);
MS2_CHECK_OFFSET(UIWeddingGuestDialog, m_spPage, 0x178);
MS2_CHECK_OFFSET(UIWeddingGuestDialog, m_pages, 0x188);
MS2_CHECK_OFFSET(UIWeddingGuestDialog, m_guests, 0x198);

UIWeddingInvitationDialog* FUN_140fce870(int nId);                          // 0x140fce870 the invitation dialog, if open
