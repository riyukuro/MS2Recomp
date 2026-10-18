// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uicharacterabilitydialog.h (name assumed:
// the exe has no __FILE__ string for this unit).
//
// UICharacterAbilityDialog ("CharacterAbilityDialog", UI type 0x4f0c, RTTI .?AVUICharacterAbilityDialog@@, 0x188 bytes): the
// character ability window. The ability table (categories with their abilities, each with a required level) is sent to
// the movie ("buildCategory" / "buildAbility"); the manager (CCharacterAbilityManager) holds the learned ids. The movie
// calls back "onAddButton" (learn, packet 0x89 mode 2) and "onResetButton" (a meso message box; "OnMesoReset" answers with
// packet 0x89 mode 1). A 1 s timer refreshes the reset cooldown button. Names: virtuals are Ghidra's vfunc_<slot>;
// FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/abilitytable.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/mctimer.h"

class NotifyObject;
class UIMsg;
class UISwfEntity;
class ASData;

class UICharacterAbilityDialog : public UIDialog
{
public:
    UICharacterAbilityDialog();                         // 0x140f2a260
    virtual ~UICharacterAbilityDialog();                //  0 0x140f2a2f0 (??_G 0x140f2ce70)
    virtual CString vfunc_1();                          //  1 0x140f2a330 "CharacterAbilityDialog"
    virtual void OnLoadComplete();                      // 22 0x140f2a510
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                        // 28 0x140f2a620 onAddButton / onResetButton
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);   // 49 0x140f2abc0 "getTooltip" of an ability / category icon
    virtual int vfunc_65();                             // 65 0x140f2a380 Open: listen to the level notification
    virtual void vfunc_67();                            // 67 0x140f2a480
    virtual void vfunc_72();                            // 72 0x140f2a4a0 1 s tick: the reset cooldown button
    virtual int vfunc_48() { return 0x4f0c; }           // 48 0x140f2d3a0 UI type id
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   // IMessageListener 0 0x140f2ae70 "OnMesoReset"
    virtual void vfunc_15();                            // 15 0x140f2abb0 empty

    void FUN_140f2b000(NotifyObject* pNotify);          // the level changed
    void FUN_140f2b0f0();                               // all abilities arrived
    void FUN_140f2b110(MS2Ptr<Unk_CaAbilityRow> ref);   // one ability learned (by value: callee destroys)
    void FUN_140f2b1e0();                               // send the whole table
    void FUN_140f2b760();                               // send the points text
    void FUN_140f2b850();                               // send the reset cooldown button
    void FUN_140f2ba20();                               // send the "disabled" text (quest not done)
    void FUN_140f2bee0(unsigned short nLevel);          // flag the menu button when an ability is new at this level

private:
    MS2_LAYOUT_FRIEND;
    Unk_McTimer m_timer;                                // +0x178 1 s tick
    int m_bBuilt;                                       // +0x180 the table was sent
    int m_pad_184;
};
MS2_CHECK_SIZE(UICharacterAbilityDialog, 0x188);

UICharacterAbilityDialog* FUN_140f2c530(int nId);       // GetDialog<UICharacterAbilityDialog>
