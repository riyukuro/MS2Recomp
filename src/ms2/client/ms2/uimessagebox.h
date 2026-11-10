// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uimessagebox.h (name assumed).
//
// UIMessageBox (RTTI .?AVUIMessageBox@@, 0x90 bytes, vftables 0x142fc27b0 / 0x142fc2958, ctor 0x1419f71e0, dtor
// 0x1419f72a0): the HUD layer that shows the CMsgBoxData queue (uimessageboxdata.h) one box at a time and dispatches
// the button results by the box tag. CMsgBoxData is only forward declared here: some users define their own view of it.
#pragma once

#include "ms2/placeholder/uiheadupdisplay.h"

class CItem;
class CMsgBoxData;

// The message box record handle (the exe's MS2Ptr<CMsgBoxData> helpers: copy 0x140534b80, dtor 0x140534d60, get
// 0x140534fc0, -> 0x140534fe0). The old name is kept for the units that spelled it before the type was recovered.
typedef MS2Ptr<CMsgBoxData> Unk_MessageBoxPtr;

class UIMessageBox : public UIHeadUpDisplay
{
public:
    UIMessageBox();                                                 // 0x1419f71e0
    virtual ~UIMessageBox();                                        // 0x1419f72a0 (??_G 0x141a008e0)
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual CString GetTypeName();
    virtual void vfunc_8(int bVisible);
    virtual void vfunc_43();
    virtual void OnLoadComplete();
    virtual int vfunc_13();                                         // keyboard
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
    virtual void vfunc_47(int bBlock);
    // @0x141a00920
    virtual int vfunc_48() { return 20040; }                        // the UI id (0x4e48)

    int ShowMessage(MS2Ptr<CMsgBoxData> spData);                  // show now (replacing the current box)
    void FUN_1419f8120();                                           // close the current box
    void CloseAll(int nResult);                                // close all
    void ShowIfIdle(MS2Ptr<CMsgBoxData> spData);                 // show when idle
    int FUN_1419f8270();                                            // no box shown
    void UpdateErrorMessage(const CStringW& strText);                    // error text
    void UpdateMessage(const CStringW& strText);                    // message text
    MS2Ptr<CMsgBoxData> GetCurrentBox();                            // the current box
    int IsSameBox(MS2Ptr<CMsgBoxData> spData);                  // same box (tag or callback) as the current one
    void FUN_1419f88e0(int bBlock);
    void AttachToLayer();                                           // bring the layer to the top
    void PlayMessageSound(MS2Ptr<CMsgBoxData> spData);                 // play the open sound
    void FUN_1419f8ec0(MS2Ptr<CMsgBoxData> spData);                 // open
    void ResetAfterClose();                                           // reset after closing
    void FUN_1419f9250(int nResult);                                // close the current box with a result
    void FUN_1419f9410(int nButton, int nBoxId, CStringW strTag, Scaleform::GFx::Value& extra);   // OnClick
    int FUN_1419f97a0(int nButton, int nBoxId, CStringW strTag, Scaleform::GFx::Value& extra);
    int HandlePlainTag(int nButton, int nBoxId, CStringW strTag, Scaleform::GFx::Value& extra);   // plain tags
    int FUN_1419fa910(int nButton, int nBoxId, CStringW strTag, Scaleform::GFx::Value& extra);   // "tag,arg" tags

    // Tag handlers (nButton 0 = OK / yes). Non-zero: the result was consumed.
    int HandleForceloginButton();                                            // forcelogin
    int HandleGameexitButton(int nButton);                                 // gameexit
    int HandleStartbypassButton(int nButton);                                 // startbypass
    int FUN_1419fb630(int nButton);
    int HandleLearnSkillButton(int nButton);                                 // learn_skill
    int HandleUnlockcashButton(int nButton);                                 // unlockcash
    int HandlePartyinviteButton(int nButton);                                 // partyinvite
    int HandleGuildinviteButton(int nButton);                                 // guildinvite
    int HandleDestroyItemButton(int nButton);                                 // destroy_item
    int HandleDestroyStoreItemButton(int nButton, CStringW strTag);                // destroy_store_item
    int HandleDestroyDollItemButton(int nButton, CStringW strTag);                // destroy_doll_item
    int HandleLearnEmotionButton(int nButton);                                 // learn_emotion
    int HandleRecallconfirmButton(int nButton);                                 // recallconfirm
    int SendRequestCube(int nButton);                                 // confirmCommend
    int HandleGuildArenaJoinButton(int nButton);                                 // guildArenaJoin
    int HandleRequestTradeExButton(int nButton);                                 // requestTradeEx
    int HandleMaintenanceExitButton(int nButton);                                 // maintenanceExit
    int FUN_1419fc810(int nButton);                                 // use_function_item
    int HandleAlreadyReconnectButton(int nButton);                                 // alreadyReconnect
    int HandleExternalBlockButton(int nButton);                                 // externalBlock
    int OnConfirmCancelPvpRequest(int nButton);                                 // individualArenaJoin
    int HandleConfirmChangeCharNameButton(int nButton);                                 // confirmChangeCharName
    int HandleRecallscrollconfirmButton(int nButton);                                 // recallscrollconfirm
    int HandleItemlockConfirmButton(int nButton);                                 // itemlock_confirm
    int HandleSummonBindPetButton(int nButton);                                 // summonBindPet
    int HandleComposeBindPetButton(int nButton);                                 // composeBindPet
    int HandleEvolutionBindPetButton(int nButton);                                 // evolutionBindPet
    int HandleTrainingBindPetButton(int nButton);                                 // trainingBindPet
    int HandleStudyBindPetButton(int nButton);                                 // studyBindPet / remakeOptionBindPet
    int HandleRemakeOptionScrollBindPetButton(int nButton);                                 // remakeOptionScrollBindPet
    int HandleUseBindItemSkillButton(int nButton);                                 // useBindItemSkill
    int HandleUseBindFuncItemButton(int nButton);                                 // useBindFuncItem
    int HandleUseBindEquipItemButton(int nButton);                                 // useBindEquipItem
    int HandleUseBindGemEquipItemButton(int nButton);                                 // useBindGemEquipItem
    int HandleUseStoreInButton(int nButton, int nCount);                     // usestorein
    int HandleUseStoreOutButton(int nButton, int nCount);                     // usestoreout
    int HandleSwapStoreInButton(int nButton, int nCount);                     // swapstorein-
    int HandleSwapStoreOutButton(int nButton, int nCount);                     // swapstoreout-
    int HandleDropButton(int nButton, int nCount);                     // drop
    int HandleSellButton(int nButton, int nCount);                     // sell
    int HandleTradeInButton(int nButton, int nCount);                     // tradein
    int HandleSellConfirmButton(int nButton, int nCount);                     // sellconfirm
    int HandleChangeCharNameButton(int nButton, const CStringW& strName);        // changeCharName
    int HandleChangeInvalidCharNameButton(int nButton, const CStringW& strName);        // changeInvalidCharName
    int HandleChangeGuildNameButton(int nButton, const CStringW& strName);        // changeGuildName
    int HandleOpenMassiveButton(int nButton, const CStringW& strName);        // openMassive
    int HandleBannerCloseButton(int nButton);                                 // bannerClose
    int HandleCoupleEmotionButton(int nButton);                                 // coupleEmotion
    int HandleRpsGameRequestButton(int nButton);                                 // rpsGameRequest
    int HandleCurrencyOverflowAskButton(int nButton);                                 // currency_overflow_ask
    int HandleCoupleDanceRequestButton(int nButton);                                 // coupleDanceRequest

private:
    MS2_LAYOUT_FRIEND;
    int m_count;                                                    // +0x70 a box is shown
    int m_layer;                                                    // +0x74
    int m_closing;                                                  // +0x78
    MS2Ptr<CMsgBoxData> m_data;                                     // +0x80 the current box
};
MS2_CHECK_SIZE(UIMessageBox, 0x90);
MS2_CHECK_OFFSET(UIMessageBox, m_data, 0x80);
