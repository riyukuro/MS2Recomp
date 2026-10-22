// uidamagetext.h - UIDamageText (RTTI .?AVUIDamageText@@, 0x2c8 bytes): the floating damage / heal / exp / meso / item
// numbers HUD ("DamageText" swf), and its nested UIDamageText::DamageInfo / CounterInfo / DamageQueueParam (RTTI).
// NOT an original header; recovered from ?\uidamagetext.cpp (0x141910bf0-0x14191a7e0): the ctor 0x141911060 / dtor
// 0x141911370, operator new(0x78 / 0x20 / 0x28) of the nested types and their ctors 0x141910bf0 / 0x1419181f0 /
// 0x141918240. The names m_counter / m_ownerFollowerCounter / m_ownerFollowers / m_normals are the exe's own (debug text of
// 0x1419136c0); the other member names are invented. Base UIHeadUpDisplay (placeholder/uiheadupdisplay.h). Created by
// UIService (0x141911060 call in uiservice.cpp).
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uiheadupdisplay.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include <NiPoint3.h>

class ASMovieClip;
class ASGameEntity;
class GameObject;
class PCBase;
struct Unk_BattleState;     // client/ms2/gameoptionbattle.h (the battle tab state of CGameOption)
struct Unk_InterfaceState;  // client/ms2/gameoptioninterface.h (the interface tab state of CGameOption)

class UIDamageText : public UIHeadUpDisplay
{
public:
    // One shown number: the clip under the "damageText" container, its "m_ani" child and the follow / timing state.
    class DamageInfo : public CPtred
    {
    public:
        DamageInfo(int nType, unsigned __int64 nOwnerId, const NiPoint3& kPos, int nIndex,
                   MS2Ptr<ASMovieClip> spClip, int nGrade);                 // 0x141910bf0 (spClip by value)
        virtual ~DamageInfo();                                              // 0x141910d10 stop + "RemoveAni" unless clearing
        void FUN_141910e60(const unsigned int& nNow);                       // update m_nElapsed
        void FUN_141910ee0(const unsigned int& nNow);                       // start the clock once
        bool FUN_141910f10(const unsigned int& nNow);                       // expired (> 1000 ms)
        bool FUN_141910f60(const unsigned int& nNow);                       // idle and > 100 ms: may jump
        bool FUN_141910fc0(const unsigned int& nNow);                       // idle and > 200 ms
        static void FUN_141911020(const int& nMovieId);                     // s_nMovieId = nMovieId
        static void FUN_141911040(bool bClearing);                          // s_bClearing = bClearing

        int m_nType;                        // +0x18 0 damage (follows the target), 1 exp / meso / item
        unsigned __int64 m_nOwnerId;        // +0x20 entity id of the target
        NiPoint3 m_kPos;                    // +0x28 world position
        int m_nIndex;                       // +0x34 counter index when it was added
        MS2Ptr<ASMovieClip> m_spClip;       // +0x38
        MS2Ptr<ASMovieClip> m_spAni;        // +0x48 the clip's "m_ani"
        int m_nGrade;                       // +0x58 the damage grade (0 normal, 1 critical, 2 miss, 3 block, 5-7 recover)
        float m_fScale;                     // +0x5c 1.0, then the clip's y scale
        bool m_bMyDamage;                   // +0x60
        bool m_bCanJump;                    // +0x61 1
        unsigned int m_nStart;              // +0x64 start time (ms)
        int m_nState;                       // +0x68 0 shown, 1 jumped, 3 removed
        unsigned int m_nElapsed;            // +0x6c
        bool m_bDecreased;                  // +0x70 "decreaseCounter" already applied (not set by the ctor)

        static int s_nMovieId;              // 0x1439f8fb4 (= 1)
        static bool s_bClearing;            // 0x143af1f50
    };
    // Per-target counter of the numbers in flight.
    class CounterInfo : public CPtred
    {
    public:
        CounterInfo(int nCount, int nIndex) : m_nCount(nCount), m_nIndex(nIndex) {}   // 0x1419181f0
        int m_nCount;                       // +0x18
        int m_nIndex;                       // +0x1c next index (wraps at m_nMaxIndex)
    };
    // A queued exp / meso number (shown one per 200 ms).
    class DamageQueueParam : public CPtred
    {
    public:
        DamageQueueParam(int nActorId, int nValue, int nType) : m_nActorId(nActorId), m_nValue(nValue), m_nType(nType) {}   // 0x141918240
        int m_nActorId;                     // +0x18
        int m_nValue;                       // +0x1c
        int m_nType;                        // +0x20 0 exp, 1 meso
    };
    typedef ATL::CAtlMap<unsigned __int64, MS2Ptr<CounterInfo> > CounterMap;
    typedef ATL::CAtlList<MS2Ptr<DamageInfo> > DamageList;

    UIDamageText();                                                         // 0x141911060
    virtual ~UIDamageText();                                                //  0 0x141911370 (??_G 0x141918760)
    virtual CString GetTypeName();                                              //  1 0x1419114d0 "DamageText"
    virtual void vfunc_3();                                                 //  3 0x141911520 clear, hide
    virtual void vfunc_15();                                                // 15 0x141911a70 update
    virtual void vfunc_16();                                                // 16 0x141917a90 clear
    virtual void OnLoadComplete();                                          // 22 0x141911550
    virtual void vfunc_26();                                                // 26 0x141911d10 unload
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141911c20
    virtual void vfunc_41(const Scaleform::GFx::Value& root);               // 41 0x141917a20
    virtual void vfunc_43();                                                // 43 0x141911c70
    virtual int vfunc_48() { return 0x4e32; }                               // 48 0x141919060 (inline: emitted after ??_G)

    void FUN_141911e90(PCBase* pTarget, __int64 nValue, int nGrade, int nCasterId, const efd::Point3& kHitPos);  // add a damage number
    void FUN_1419129d0(GameObject* pTarget, int nValue, int nType);                     // queue an exp / meso number
    void FUN_141912a80(GameObject* pTarget, int nValue, int nType);                     // show an exp / meso number now
    void FUN_141912b20(GameObject* pTarget, int nValue, int nType, const NiPoint3& kPos);
    void FUN_141913060(GameObject* pTarget, int nCount, const CString& strIcon);        // item icon number
    void FUN_1419134a0(const CString& strFont);                                         // AS loadFont
    void FUN_141913530(const CString& strFont);                                         // AS unloadFont
    void FUN_1419135c0();                                                               // clear everything
    bool FUN_1419136c0(CStringW& strOut);                                               // debug text of the containers
    void FUN_141913990(bool bClearing);
    void SetObserver(bool b);                                                         // m_bObserver
    void SetObservedId(__int64 n);                                                      // m_nObservedId
    void FUN_141913a20();                                                               // read the layout constants
    float FUN_141913af0(GameObject* pTarget);                                           // height offset of a target
    float FUN_141913b80(const NiPoint3& kPos);
    int FUN_141913bd0(GameObject* pTarget, int nGrade, int nCasterId);                  // the number is shown (battle options)
    int FUN_141914020(GameObject* pTarget, NiPoint3& kPos, const CString& strNode);    // anchor position of a target
    int FUN_1419140f0(GameObject* pTarget, int& nIndex, CounterMap& map);
    int FUN_1419141a0(GameObject* pTarget);                                            // within the show distance
    int FUN_1419142a0(GameObject* pTarget);                                             // 0 npc-like, 1 player
    CString FUN_1419143c0(int nTargetKind, bool bUser);                                 // "Monster" / "User"
    int FUN_141914490(GameObject* pTarget);                                             // pc bang bonus (0)
    int FUN_1419144b0(int nGrade);                                                      // recover grade
    bool FUN_1419144f0(int nGrade);                                                     // damage grade
    int FUN_141914530(int nGrade);                                                      // recover grade
    CString FUN_141914570(int nGrade);                                                  // "Normal" / "Critical" / "Recover"
    CString FUN_141914660(__int64 nValue, int nGrade);                                  // the value text
    CString FUN_1419147e0();                                                            // the option flags as text
    int FUN_141914850(int nType);
    CString FUN_141914890(int nValue, int nType);                                       // the exp / meso / item value text
    CString FUN_1419149d0(int nType);                                                   // "Exp" / "Meso" / "Item"
    float FUN_141914a90(const NiPoint3& kPos);                                          // distance scale
    float FUN_141914c40(GameObject* pTarget);
    int FUN_141914d40(GameObject* pTarget);                                             // 1: do not show
    void FUN_141914da0(int bAppend, POSITION* pLast, DamageList& list, CounterMap& map,
                       MS2Ptr<DamageInfo> spInfo, int nMax);                            // insert into a list
    void FUN_141915090(POSITION pos);                                                   // remove from m_ownerFollowers
    void FUN_1419150f0(POSITION pos);                                                   // remove from m_normals
    void FUN_141915150(const unsigned __int64& nOwnerId, int nCount, CounterMap& map);  // decrement a counter
    MS2Ptr<CounterInfo> FUN_141915240(unsigned __int64 nOwnerId, CounterMap& map, int nGrade);   // get or create a counter
    void FUN_1419153d0();                                                               // update m_ownerFollowers
    void FUN_141915990();                                                               // update m_normals
    void FUN_141916340();                                                               // pop the queue
    void FUN_141916430(MS2Ptr<ASGameEntity> spRoot);                                    // update m_ownerFollowers (clearing)
    void FUN_141916ac0(MS2Ptr<ASGameEntity> spRoot);                                    // update m_normals (clearing)
    int FUN_1419175c0(MS2Ptr<DamageInfo> spInfo, NiPoint3 kPos, GameObject* pTarget,
                      const Scaleform::GFx::Value& clip, const efd::Point3& kScreen, int bAppend);   // bind the clip and insert it

    MS2_LAYOUT_FRIEND;
    CString m_strDamageNode;                // +0x70 "Eff_Damage"
    CString m_strBodyNode;                  // +0x78 "Eff_Body"
    CounterMap m_counter;                   // +0x80
    CounterMap m_ownerFollowerCounter;      // +0xc8
    DamageList m_ownerFollowers;            // +0x110 the recover numbers
    DamageList m_normals;                   // +0x140
    POSITION m_posOwnerFollowers;           // +0x170 last inserted
    POSITION m_posNormals;                  // +0x178
    Scaleform::GFx::Value m_onNextAni;      // +0x180
    Scaleform::GFx::Value m_onJumpAni;      // +0x1a0
    Scaleform::GFx::Value m_onForceRemove;  // +0x1c0
    MS2Ptr<AScript> m_spDamageEnable;       // +0x1e0
    MS2Ptr<AScript> m_spDamageGarbage;      // +0x1f0
    Scaleform::GFx::Value m_loadFont;       // +0x200
    Scaleform::GFx::Value m_unloadFont;     // +0x220
    MS2Ptr<AScript> m_spDamageText;         // +0x240
    int m_nLineHeight;                      // +0x250
    int m_nJumpCount;                       // +0x254
    int m_nMaxShown;                        // +0x258
    int m_nMaxList;                         // +0x25c m_nMaxShown + 10
    int m_nMaxIndex;                        // +0x260 1000
    Unk_BattleState* m_pBattleOption;       // +0x268
    Unk_InterfaceState* m_pInterfaceOption; // +0x270
    unsigned int m_nLastQueueTime;          // +0x278
    ATL::CAtlList<MS2Ptr<DamageQueueParam> > m_queue;   // +0x280
    bool m_bObserver;                       // +0x2b0
    __int64 m_nObservedId;                  // +0x2b8
    bool m_bClearing;                       // +0x2c0
    int m_nRepeat;                          // +0x2c4 1
};
MS2_CHECK_SIZE(UIDamageText::DamageInfo, 0x78);
MS2_CHECK_OFFSET(UIDamageText::DamageInfo, m_spAni, 0x48);
MS2_CHECK_OFFSET(UIDamageText::DamageInfo, m_bDecreased, 0x70);
MS2_CHECK_SIZE(UIDamageText::CounterInfo, 0x20);
MS2_CHECK_SIZE(UIDamageText::DamageQueueParam, 0x28);
MS2_CHECK_SIZE(UIDamageText, 0x2c8);
MS2_CHECK_OFFSET(UIDamageText, m_counter, 0x80);
MS2_CHECK_OFFSET(UIDamageText, m_ownerFollowers, 0x110);
MS2_CHECK_OFFSET(UIDamageText, m_onNextAni, 0x180);
MS2_CHECK_OFFSET(UIDamageText, m_spDamageText, 0x240);
MS2_CHECK_OFFSET(UIDamageText, m_pBattleOption, 0x268);
MS2_CHECK_OFFSET(UIDamageText, m_queue, 0x280);
MS2_CHECK_OFFSET(UIDamageText, m_nRepeat, 0x2c4);
