// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CPopupProfileImageMan / CPopupProfileImageData: see
// ms2/placeholder/cpopupprofileimageman.h.
// MS2-UNIT: ?\popupprofileimagedata.cpp
// MS2-RANGE: 0x141697140-0x1416999b0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VCPopupProfileImageData@@@@QEAAAEAV1@PEAVCPopupProfileImageData@@@Z 0x141697f40 ; unique
// MS2-PIN: ?SetAt@?$CRBMap@_KV?$MS2Ptr@VCPopupProfileImageData@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$MS2Ptr@VCPopupProfileImageData@@@@@3@@ATL@@QEAAPEAU__POSITION@@_KAEBV?$MS2Ptr@VCPopupProfileImageData@@@@@Z 0x141699470 ; unique
// MS2-PINS-END tplpin
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\popupprofileimagedata.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/cpopupprofileimageman.h"

#include <atlcoll.h>
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/partymanager.h"
#include "ms2/placeholder/clientconstants.h"  // C3: Common::Constants::Value<int>::Get

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// A configured value of the constants singleton (0x58 bytes each, read through 0x140a36020 / 0x140a35ca0).
struct Unk_PpConst { void* m_p[11]; };
MS2_CHECK_SIZE(Unk_PpConst, 0x58);
class Unk_PpConstants
{
public:
    char m_pad_00[0xb60];
    Unk_PpConst m_expire;                   // +0xb60 ticks a popup stays
    Unk_PpConst m_maxCount;                 // +0xbb8 how many characters are kept
    Unk_PpConst m_expireA;                  // +0xc10 extra delay
    Unk_PpConst m_expireB;                  // +0xc68 extra delay (state 1)
};
// C3: was FUN_1401d3200 (= TSingleton<Client::Constants>::GetInstance, GetClientConstants())
unsigned int FUN_140a35ca0(struct MS2Tick*);   // C3: was FUN_140a35ca0
unsigned long GetTickCountMs2();   // C3: was FUN_140869420
unsigned int FUN_141697bc0(Unk_PpConst* p);  // a configured value

// The character state manager (singleton 0x1409670d0).

// The popup target of a character: the entity manager finds the entity, whose slot 86 hands out a reference to the
// popup object that is hidden by its slot 3.
// slot 86 is PCBase::vfunc_86, MS2Ptr<Unk_PCBaseComp_ab8> (pcbase.h; the UIPopupProfileImage::Entity of the actor).
// Its slot 3 hides the popup. Its ~MS2Ptr / operator T* / operator-> are 0x141666930 / 0x1416676a0 / 0x141667730.
class Unk_PCBaseComp_ab8 : public CPtred
{
public:
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();                 // close the popup
};
//
//
class Unk_PpEntity
{
public:
    virtual ~Unk_PpEntity();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_59();
    virtual void vfunc_60();
    virtual void vfunc_61();
    virtual void vfunc_62();
    virtual void vfunc_63();
    virtual void vfunc_64();
    virtual void vfunc_65();
    virtual void vfunc_66();
    virtual void vfunc_67();
    virtual void vfunc_68();
    virtual void vfunc_69();
    virtual void vfunc_70();
    virtual void vfunc_71();
    virtual void vfunc_72();
    virtual void vfunc_73();
    virtual void vfunc_74();
    virtual void vfunc_75();
    virtual void vfunc_76();
    virtual void vfunc_77();
    virtual void vfunc_78();
    virtual void vfunc_79();
    virtual void vfunc_80();
    virtual void vfunc_81();
    virtual void vfunc_82();
    virtual void vfunc_83();
    virtual void vfunc_84();
    virtual void vfunc_85();
    virtual MS2Ptr<Unk_PCBaseComp_ab8> vfunc_86();   // 86 0x2b0
};
class Unk_PpEntityMgr { public: };

// @0x141697140
CPopupProfileImageData::CPopupProfileImageData()
{
}

// @0x141697180
void CPopupProfileImageData::SetId(unsigned __int64 nId)
{
    m_nId = nId;
}
MS2_REPLACE_METHOD(0x141697180, CPopupProfileImageData, SetId, 25, 0xAB8BF0FB);

// @0x1416971a0
unsigned __int64 CPopupProfileImageData::GetId()
{
    return m_nId;
}
MS2_REPLACE_METHOD(0x1416971A0, CPopupProfileImageData, GetId, 15, 0xBBB219C9);

// @0x1416971c0
void CPopupProfileImageData::SetTime(int nTime)
{
    m_nTime = nTime;
}
MS2_REPLACE_METHOD(0x1416971C0, CPopupProfileImageData, SetTime, 22, 0xF6E32213);

// @0x1416971e0
int CPopupProfileImageData::GetTime()
{
    return m_nTime;
}
MS2_REPLACE_METHOD(0x1416971E0, CPopupProfileImageData, GetTime, 14, 0xA25B27BF);

// @0x141697200
int CPopupProfileImageData::IsExpired(int nNow)
{
    unsigned int nElapsed = nNow - m_nTime;
    unsigned int nExpire = FUN_141697bc0(&((class Unk_PpConstants*)GetClientConstants())->m_expire);
    if (nElapsed >= nExpire)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x141697200, CPopupProfileImageData, IsExpired, 80, 0x8577550E);

// @0x141697260
int CPopupProfileImageData::IsExpiredWithDelay(int nNow)
{
    unsigned int nElapsed = nNow - m_nTime;
    unsigned int nDelay = 0;
    if (TSingleton<CPartyManager>::GetInstance()->IsMemberByCharId(m_nId) == 1)
        nDelay = FUN_141697bc0(&((class Unk_PpConstants*)GetClientConstants())->m_expireB);
    else
        nDelay = FUN_141697bc0(&((class Unk_PpConstants*)GetClientConstants())->m_expireA);
    nDelay += FUN_141697bc0(&((class Unk_PpConstants*)GetClientConstants())->m_expire);
    if (nElapsed >= nDelay)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x141697260, CPopupProfileImageData, IsExpiredWithDelay, 171, 0xF67CA85A);

// @0x141697320
CPopupProfileImageMan::CPopupProfileImageMan()
    : m_pending(10), m_shown(10)
{
}

// @0x1416973a0
CPopupProfileImageMan::~CPopupProfileImageMan()
{
    m_pending.RemoveAll();
    m_shown.RemoveAll();
}

// @0x141697430
void CPopupProfileImageMan::RemoveExpired()
{
    int nNow = GetTickCountMs2();
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        ATL::CAtlList<unsigned __int64> expired(10);
        for (POSITION pos = m_shown.GetHeadPosition(); pos != 0; m_shown.GetNext(pos))
        {
            unsigned __int64 nId = m_shown.GetKeyAt(pos);
            DataPtr spData = m_shown.GetValueAt(pos);
            if (spData == 0)
            {
                expired.AddTail(nId);
                continue;
            }
            if (spData->IsExpired(nNow) == 1)
            {
                Unk_PpEntity* pEntity = reinterpret_cast<Unk_PpEntity*>(WorldService::GetInstance()->FUN_141bd1530(nId));
                bool bFound = pEntity != 0 && (pEntity->vfunc_86().operator Unk_PCBaseComp_ab8*() ? true : false);
                if (bFound)
                    pEntity->vfunc_86()->vfunc_3();
                expired.AddTail(nId);
            }
        }
        for (POSITION posExpired = expired.GetHeadPosition(); posExpired != 0; expired.GetNext(posExpired))
        {
            unsigned __int64 nId = expired.GetAt(posExpired);
            m_shown.RemoveKey(nId);
        }
        expired.RemoveAll();
    }
}
MS2_REPLACE_METHOD(0x141697430, CPopupProfileImageMan, RemoveExpired, 800, 0x76498148);

// @0x141697760
int CPopupProfileImageMan::AddShown(unsigned __int64 nId)
{
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        int nNow = GetTickCountMs2();
        if ((int)m_shown.GetCount() >= *reinterpret_cast<Common::Constants::Value<int>*>(&((class Unk_PpConstants*)GetClientConstants())->m_maxCount)->Get())
            return 0;
        DataPtr spData(0);
        if (m_shown.Lookup(nId, spData))
        {
            spData->SetTime(nNow);
            return 1;
        }
        int bNew = 0;
        spData = 0;
        if (m_pending.Lookup(nId, spData) == 0)
            bNew = 1;
        if (spData == 0)
        {
            spData.AssignRaw(new CPopupProfileImageData);
            spData->SetId(nId);
        }
        else
        {
            return 0;
        }
        if (bNew != 0)
            m_pending.SetAt(nId, spData);
        spData->SetTime(nNow);
        m_shown.SetAt(nId, spData);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x141697760, CPopupProfileImageMan, AddShown, 627, 0x2C413CDA);

// @0x1416979e0
void CPopupProfileImageMan::RemoveShown(unsigned __int64 nId)
{
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        DataPtr spData(0);
        if (m_shown.Lookup(nId, spData))
            m_shown.RemoveKey(nId);
        Unk_PpEntity* pEntity = reinterpret_cast<Unk_PpEntity*>(WorldService::GetInstance()->FUN_141bd1530(nId));
        bool bFound = pEntity != 0 && (pEntity->vfunc_86().operator Unk_PCBaseComp_ab8*() ? true : false);
        if (bFound)
            pEntity->vfunc_86()->vfunc_3();
    }
}
MS2_REPLACE_METHOD(0x1416979E0, CPopupProfileImageMan, RemoveShown, 465, 0xF1C4CEB1);

// @0x141697bc0
unsigned int FUN_141697bc0(Unk_PpConst* p)
{
    return FUN_140a35ca0(reinterpret_cast<Common::Constants::Value<MS2Tick>*>(p)->Get());
}

// @0x141699890
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
