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
    virtual CString vfunc_1();
    virtual void vfunc_8(int bVisible);
    virtual void vfunc_43();
    virtual void OnLoadComplete();
    virtual int vfunc_13();                                         // keyboard
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
    virtual void vfunc_47(int bBlock);
    // @0x141a00920
    virtual int vfunc_48() { return 20040; }                        // the UI id (0x4e48)

    int FUN_1419f7ff0(MS2Ptr<CMsgBoxData> spData);                  // show now (replacing the current box)
    void FUN_1419f8120();                                           // close the current box
    void FUN_1419f8170(int nResult);                                // close all
    void FUN_1419f81f0(MS2Ptr<CMsgBoxData> spData);                 // show when idle
    int FUN_1419f8270();                                            // no box shown
    void FUN_1419f82b0(const CStringW& strText);                    // error text
    void FUN_1419f8370(const CStringW& strText);                    // message text
    MS2Ptr<CMsgBoxData> FUN_1419f8470();                            // the current box
    int FUN_1419f84c0(MS2Ptr<CMsgBoxData> spData);                  // same box (tag or callback) as the current one
    void FUN_1419f88e0(int bBlock);
    void FUN_1419f8de0();                                           // bring the layer to the top
    void FUN_1419f8e10(MS2Ptr<CMsgBoxData> spData);                 // play the open sound
    void FUN_1419f8ec0(MS2Ptr<CMsgBoxData> spData);                 // open
    void FUN_1419f9110();                                           // reset after closing
    void FUN_1419f9250(int nResult);                                // close the current box with a result
    void FUN_1419f9410(int nButton, int nBoxId, CStringW strTag, Scaleform::GFx::Value& extra);   // OnClick
    int FUN_1419f97a0(int nButton, int nBoxId, CStringW strTag, Scaleform::GFx::Value& extra);
    int FUN_1419f9ba0(int nButton, int nBoxId, CStringW strTag, Scaleform::GFx::Value& extra);   // plain tags
    int FUN_1419fa910(int nButton, int nBoxId, CStringW strTag, Scaleform::GFx::Value& extra);   // "tag,arg" tags

    // Tag handlers (nButton 0 = OK / yes). Non-zero: the result was consumed.
    int FUN_1419fb3c0();                                            // forcelogin
    int FUN_1419fb480(int nButton);                                 // gameexit
    int FUN_1419fb500(int nButton);                                 // startbypass
    int FUN_1419fb630(int nButton);
    int FUN_1419fb7b0(int nButton);                                 // learn_skill
    int FUN_1419fb8e0(int nButton);                                 // unlockcash
    int FUN_1419fb930(int nButton);                                 // partyinvite
    int FUN_1419fba00(int nButton);                                 // guildinvite
    int FUN_1419fba50(int nButton);                                 // destroy_item
    int FUN_1419fbd40(int nButton, CStringW strTag);                // destroy_store_item
    int FUN_1419fc140(int nButton, CStringW strTag);                // destroy_doll_item
    int FUN_1419fc550(int nButton);                                 // learn_emotion
    int FUN_1419fc640(int nButton);                                 // recallconfirm
    int SendRequestCube(int nButton);                                 // confirmCommend
    int FUN_1419fc710(int nButton);                                 // guildArenaJoin
    int FUN_1419fc750(int nButton);                                 // requestTradeEx
    int FUN_1419fc7d0(int nButton);                                 // maintenanceExit
    int FUN_1419fc810(int nButton);                                 // use_function_item
    int FUN_1419fcc70(int nButton);                                 // alreadyReconnect
    int FUN_1419fccb0(int nButton);                                 // externalBlock
    int FUN_1419fcde0(int nButton);                                 // individualArenaJoin
    int FUN_1419fce20(int nButton);                                 // confirmChangeCharName
    int FUN_1419fcf60(int nButton);                                 // recallscrollconfirm
    int FUN_1419fd0d0(int nButton);                                 // itemlock_confirm
    int FUN_1419fd130(int nButton);                                 // summonBindPet
    int FUN_1419fd260(int nButton);                                 // composeBindPet
    int FUN_1419fd4a0(int nButton);                                 // evolutionBindPet
    int FUN_1419fd6e0(int nButton);                                 // trainingBindPet
    int FUN_1419fd830(int nButton);                                 // studyBindPet / remakeOptionBindPet
    int FUN_1419fda70(int nButton);                                 // remakeOptionScrollBindPet
    int FUN_1419fdbe0(int nButton);                                 // useBindItemSkill
    int FUN_1419fde80(int nButton);                                 // useBindFuncItem
    int FUN_1419fdf80(int nButton);                                 // useBindEquipItem
    int FUN_1419fe110(int nButton);                                 // useBindGemEquipItem
    int FUN_1419fe240(int nButton, int nCount);                     // usestorein
    int FUN_1419fe310(int nButton, int nCount);                     // usestoreout
    int FUN_1419fe590(int nButton, int nCount);                     // swapstorein-
    int FUN_1419fe690(int nButton, int nCount);                     // swapstoreout-
    int FUN_1419fe790(int nButton, int nCount);                     // drop
    int FUN_1419fe830(int nButton, int nCount);                     // sell
    int FUN_1419fe900(int nButton, int nCount);                     // tradein
    int FUN_1419fea00(int nButton, int nCount);                     // sellconfirm
    int FUN_1419feae0(int nButton, const CStringW& strName);        // changeCharName
    int FUN_1419fecc0(int nButton, const CStringW& strName);        // changeInvalidCharName
    int FUN_1419feeb0(int nButton, const CStringW& strName);        // changeGuildName
    int FUN_1419ff130(int nButton, const CStringW& strName);        // openMassive
    int FUN_1419ff7d0(int nButton);                                 // bannerClose
    int FUN_1419ff870(int nButton);                                 // coupleEmotion
    int FUN_1419ffb20(int nButton);                                 // rpsGameRequest
    int FUN_1419ffe20(int nButton);                                 // currency_overflow_ask
    int FUN_1419fff10(int nButton);                                 // coupleDanceRequest

private:
    MS2_LAYOUT_FRIEND;
    int m_count;                                                    // +0x70 a box is shown
    int m_layer;                                                    // +0x74
    int m_closing;                                                  // +0x78
    MS2Ptr<CMsgBoxData> m_data;                                     // +0x80 the current box
};
MS2_CHECK_SIZE(UIMessageBox, 0x90);
MS2_CHECK_OFFSET(UIMessageBox, m_data, 0x80);
