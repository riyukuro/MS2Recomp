// effectquery.h - PLACEHOLDER for NoticeMessage (name from the v2525 reference decomp, unconfirmed by RTTI): the
// 0x70-byte effect request handed to the client effect manager (CEffectService FUN_1411a49c0 spawn / FUN_1411a4a00 play
// once): an effect file name, the owner's object id, the node to attach to and the owner actor. Ctor 0x140a52ef0 and the
// methods 0x140a53010..0x140a53580 are unit_140a52ef0; the implicit dtor 0x1405a89e0 is a COMDAT first emitted by
// ?\itemgem.cpp. Field names other than m_strName / m_nObject / m_nActor are invented.
// First used by ?\stateeffectmgr.cpp and ?\groundeffectdata.cpp (as Unk_EffectQuery, kept as an alias).
#pragma once
#include <afx.h>
#include <efd/SmartPointer.h>
#include <NiAVObject.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/delegate.h"

class GameObject;
class NiNode;

// The callback owned by NoticeMessage +0x40 is Delegate<void(unsigned, CString, bool)> (delegate.h): CEquipment passes
// a bound-member Delegate of that signature to SetCallback (DelegateImpl<pair<CEquipment*, ...>> ctor 0x1411f0240), and
// CEffectService::FUN_1411a4a00 calls GetCallback() as that Delegate (IsNull 0x1411b80a0, operator() 0x1411b0e30).
// Its ctor 0x140a53660 and operator= 0x140a53680 are COMDATs of unit_140a52ef0, the dtor 0x1405a8560 one of
// ?\itemgem.cpp. delegate.h declares ~Delegate / operator= only, so this signature's bodies are specialized here.
typedef Delegate<void(unsigned, CString, bool)> Unk_NoticeCallbackPtr;
template <>
inline Delegate<void(unsigned, CString, bool)>::~Delegate()
{
    if (m_pImpl)
        delete m_pImpl;
}
template <>
inline Delegate<void(unsigned, CString, bool)>& Delegate<void(unsigned, CString, bool)>::operator=(const Delegate& other)
{
    if (this == &other)
        return *this;
    if (m_pImpl)
        delete m_pImpl;
    if (other.m_pImpl == 0)
        m_pImpl = 0;
    else
        m_pImpl = other.m_pImpl->vfunc_1();
    return *this;
}

class NoticeMessage
{
public:
    NoticeMessage();                                        // 0x140a52ef0

    int FUN_140a53010();                                    // the owner PC's FUN_141658e60, else 2
    int FUN_140a53050();                                    // the owner PC's job (FUN_141654700), else 2
    int GetObjectCode();                                    // 0x140a53090 the owner's FUN_140976780, else m_nObjectCode
    bool IsMyPC();                                          // 0x140a530d0 the owner is the local player
    bool CanShow();                                         // 0x140a53110
    void SetObjectCode(int nCode);                          // 0x140a53170
    void SetActor(int nActor);                              // 0x140a53190
    void SetLookupId(int nId);                              // 0x140a531b0
    void SetValue38(unsigned __int64 nValue);               // 0x140a531d0
    void SetCallback(Unk_NoticeCallbackPtr callback);       // 0x140a531f0 (by value, callee destroys)
    void SetMode48(int nMode);                              // 0x140a53240
    void CopyFrom(const NoticeMessage& other);              // 0x140a53260 selected fields
    int GetActor();                                         // 0x140a53390
    GameObject* GetOwner();                                 // 0x140a533b0
    NiNode* GetRoot();                                      // 0x140a533d0 the avatar's UI effect root, else the effect root
    double GetTimestamp();                                  // 0x140a53420
    unsigned __int64 GetValue38();                          // 0x140a53440
    Unk_NoticeCallbackPtr& GetCallback();                   // 0x140a53460
    int GetMode48();                                        // 0x140a53480
    void Bind();                                            // 0x140a534a0 resolves m_pOwner and m_spNode
    void Stamp();                                           // 0x140a53550 m_dTimestamp = now
    GameObject* ResolveOwner();                             // 0x140a53580

    CString m_strName;                                      // +0x00 effect file name
    int m_nObject;                                          // +0x08 owner object (player manager lookup); ctor 9
    efd::SmartPointer<NiAVObject> m_spNode;                 // +0x10
    void* m_p18;                                            // +0x18 (magicdata: the transform to play at)
    void* m_p20;                                            // +0x20
    void* m_p28;                                            // +0x28 (magicdata: where the spawned ids are collected)
    bool m_bFlag30;                                         // +0x30
    bool m_bFlag31;                                         // +0x31 hidden (CanShow)
    bool m_bFlag32;                                         // +0x32
    bool m_bFlag33;                                         // +0x33
    bool m_bFlag34;                                         // +0x34 ctor true
    unsigned __int64 m_n38;                                 // +0x38
    Unk_NoticeCallbackPtr m_callback;                       // +0x40
    int m_nMode48;                                          // +0x48 ctor 6
    int m_n4c;                                              // +0x4c
    int m_nObjectCode;                                      // +0x50
    int m_nActor;                                           // +0x54 the owner actor id (WorldService FUN_141bd1180)
    GameObject* m_pOwner;                                   // +0x58
    int m_nLookupId;                                        // +0x60 (WorldService FUN_141bd1180)
    double m_dTimestamp;                                    // +0x68
};
MS2_CHECK_OFFSET(NoticeMessage, m_spNode, 0x10);
MS2_CHECK_OFFSET(NoticeMessage, m_n38, 0x38);
MS2_CHECK_OFFSET(NoticeMessage, m_callback, 0x40);
MS2_CHECK_OFFSET(NoticeMessage, m_pOwner, 0x58);
MS2_CHECK_OFFSET(NoticeMessage, m_dTimestamp, 0x68);
MS2_CHECK_SIZE(NoticeMessage, 0x70);

typedef NoticeMessage Unk_EffectQuery;
