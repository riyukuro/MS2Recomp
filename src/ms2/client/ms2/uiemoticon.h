// uiemoticon.h - UIEmoticon (RTTI .?AVUIEmoticon@@, 0xf0 bytes like UIHudEntity: no fields of its own, the swf "Emoticon"
// ui id 0x4e2f, cache clip "emoticon_entity_body") and UIEmoticon::Entity (0xc8 bytes: TimerEntity + the status/quest
// listener subobjects + the emoticon state). Owning unit: ?\uiemoticon.cpp (0x14192e8f0-0x141930710). Header name assumed
// from the unit path (w20).
#pragma once
#include "ms2/client/ms2/uihudentity.h"
#include "ms2/client/ms2/uigalleryeventdialog.h"        // UIQuestEventListener (13 slots)
#include "ms2/placeholder/uistatuseventlistener.h"      // UIStatusEventListener (32 slots)

class Unk_EmoPlayer;

class UIEmoticon : public UIHudEntity
{
public:
    // The emoticon of an actor (a chat bubble over its head): m_b0 is the kind shown.
    //   0 npc movie (npc id from the player's quest object), 1 quest movie, 2 skill/stun status text, 3 above, 4 none
    class Entity : public UIHudEntity::TimerEntity, public UIStatusEventListener, public UIQuestEventListener
    {
    public:
        Entity(int nLayer, const Scaleform::GFx::Value& clip, int nActorId);   // 0x14192ef40
        virtual ~Entity();                                  //  0 0x14192f0f0 (??_G 0x141930530)
        virtual void vfunc_2();                             //  2 0x14192f200 TimerEntity::vfunc_2()
        virtual void vfunc_3();                             //  3 0x14192f220 TimerEntity::vfunc_3(); vfunc_7()
        virtual void vfunc_4();                             //  4 0x14192f250 reset: m_b0 = 4, m_b8 = ""
        virtual void vfunc_5();                             //  5 0x14192f2a0 "open"(movie name)
        virtual void vfunc_6(NiPoint3* pPos);               //  6 0x14192f3a0 place the clip
        virtual void vfunc_7();                             //  7 0x14192f540 hide the clip
        virtual int vfunc_8(int n);                         //  8 0x14192f5a0
        // UIStatusEventListener (+0xa0) overrides: 7 and 9
        virtual void vfunc_oa0_7(int a1, CStringW s);     //  oa0 7 0x14192f770
        virtual void vfunc_oa0_9(unsigned short a1);                      //  oa0 9 0x14192f740
        // UIQuestEventListener (+0xa8) overrides: 1, 3, 2, 7, 5 (definition order)
        virtual void vfunc_o178_1(void*);                   //  oa8 1 0x14192f7c0
        virtual void vfunc_o178_3(void*);                   //  oa8 3 0x14192f7f0
        virtual void vfunc_o178_2(void*);                   //  oa8 2 0x14192f820
        virtual void vfunc_o178_7(int, int);                //  oa8 7 0x14192f850
        virtual void vfunc_o178_5(void*);                   //  oa8 5 0x14192f880

        void FUN_14192f8b0(int nState);                     // m_b0 = n
        void FUN_14192f8d0(const CString& str);             // m_b8 = str
        void FUN_14192f910();                               // refresh the shown kind from the player's state
        void FUN_14192f9f0(int n);                          // leave kind 2 when n != 1
        CString FUN_14192fa50();                            // name of the movie to open
        void FUN_14192fbd0();                               // player->FUN_141093e90() (quest/status changed)
        int FUN_1419305c0();                                // m_b0 == 1

        int m_b0;                                           // +0xb0 kind (see above), initial 4
        CStringA m_b8;                                      // +0xb8 text of kind 2
        float m_c0;                                         // +0xc0 (config value, default 400.0f)
    };

    UIEmoticon();                                           // 0x14192fc10
    virtual ~UIEmoticon();                                  //  0 0x14192fc80 (??_G 0x141930570)
    virtual CString GetTypeName();                              //  1 0x14192fcc0 "Emoticon"
    virtual void OnLoadComplete();                          // 22 0x14192fd10 UIObject::OnLoadComplete(); FUN_14192fe20(m_68)
    virtual int vfunc_48() { return 0x4e2f; }               // 48 0x1419305b0

    void FUN_14192fe20(unsigned int nCount);                // create the entity cache
    Entity* FUN_141930000(int nActorId);                    // the entity of the actor (created or recycled)
};
MS2_CHECK_SIZE(UIEmoticon::Entity, 0xc8);
MS2_CHECK_OFFSET(UIEmoticon::Entity, m_b0, 0xb0);
MS2_CHECK_OFFSET(UIEmoticon::Entity, m_b8, 0xb8);
MS2_CHECK_OFFSET(UIEmoticon::Entity, m_c0, 0xc0);
MS2_CHECK_SIZE(UIEmoticon, 0xf0);
