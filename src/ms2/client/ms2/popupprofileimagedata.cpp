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
Unk_PpConstants* FUN_1401d3200();
void* FUN_140a36020(Unk_PpConst* p);
unsigned int FUN_140a35ca0(void* p);
int* FUN_1402056b0(Unk_PpConst* p);
int FUN_140869420();                        // the current tick
unsigned int FUN_141697bc0(Unk_PpConst* p);  // a configured value

// The character state manager (singleton 0x1409670d0).
class Unk_PpStateMgr { public: int FUN_14162ae20(unsigned __int64 nId, void* pA, void* pB, int n); };
Unk_PpStateMgr* FUN_1409670d0();

// The popup target of a character: the entity manager finds the entity, whose slot 86 hands out a reference to the
// popup object that is hidden by its slot 3.
class Unk_PpTarget { public: virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); };
class Unk_PpHandle
{
public:
    ~Unk_PpHandle();                        // 0x141666930
    void* FUN_1416676a0();                  // the reference (null when invalid)
    Unk_PpTarget* FUN_141667730();          // the popup object
private:
    void* m_p; void* m_pad_08;
};
MS2_CHECK_SIZE(Unk_PpHandle, 0x10);
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
    virtual Unk_PpHandle vfunc_86();        // 86 0x2b0
};
class Unk_PpEntityMgr { public: Unk_PpEntity* FUN_141bd1530(unsigned __int64 nId); };
Unk_PpEntityMgr* FUN_1403ed2d0();

// @0x141697140
CPopupProfileImageData::CPopupProfileImageData()
{
}

// @0x141697180
void CPopupProfileImageData::FUN_141697180(unsigned __int64 nId)
{
    m_nId = nId;
}
MS2_REPLACE_METHOD(0x141697180, CPopupProfileImageData, FUN_141697180, 25, 0xAB8BF0FB);

// @0x1416971a0
unsigned __int64 CPopupProfileImageData::FUN_1416971a0()
{
    return m_nId;
}
MS2_REPLACE_METHOD(0x1416971A0, CPopupProfileImageData, FUN_1416971a0, 15, 0xBBB219C9);

// @0x1416971c0
void CPopupProfileImageData::FUN_1416971c0(int nTime)
{
    m_nTime = nTime;
}
MS2_REPLACE_METHOD(0x1416971C0, CPopupProfileImageData, FUN_1416971c0, 22, 0xF6E32213);

// @0x1416971e0
int CPopupProfileImageData::FUN_1416971e0()
{
    return m_nTime;
}
MS2_REPLACE_METHOD(0x1416971E0, CPopupProfileImageData, FUN_1416971e0, 14, 0xA25B27BF);

// @0x141697200
int CPopupProfileImageData::FUN_141697200(int nNow)
{
    unsigned int nElapsed = nNow - m_nTime;
    unsigned int nExpire = FUN_141697bc0(&FUN_1401d3200()->m_expire);
    if (nElapsed >= nExpire)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x141697200, CPopupProfileImageData, FUN_141697200, 80, 0x8577550E);

// @0x141697260
// MS2-FUNCTIONAL: frame-slot order of the locals/temps differs from the exe (permuter lane)
int CPopupProfileImageData::FUN_141697260(int nNow, void* pA, void* pB)
{
    int nTime = m_nTime;
    int nDelay = FUN_1409670d0()->FUN_14162ae20(m_nId, pA, pB, 0);
    if (nDelay == 1)
        nDelay = FUN_141697bc0(&FUN_1401d3200()->m_expireB);
    else
        nDelay = FUN_141697bc0(&FUN_1401d3200()->m_expireA);
    int nBase = FUN_141697bc0(&FUN_1401d3200()->m_expire);
    if ((unsigned int)(nDelay + nBase) <= (unsigned int)(nNow - nTime))
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x141697260, CPopupProfileImageData, FUN_141697260, 171, 0xF67CA85A);

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
// MS2-FUNCTIONAL: frame-slot order of the MS2Ptr/handle temps differs from the exe
void CPopupProfileImageMan::FUN_141697430()
{
    int nNow = FUN_140869420();
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
            }
            else if (spData->FUN_141697200(nNow) == 1)
            {
                Unk_PpEntity* pEntity = FUN_1403ed2d0()->FUN_141bd1530(nId);
                bool bFound = pEntity != 0 && pEntity->vfunc_86().FUN_1416676a0() != 0;
                if (bFound)
                    pEntity->vfunc_86().FUN_141667730()->vfunc_3();
                expired.AddTail(nId);
            }
        }
        POSITION posExpired = expired.GetHeadPosition();
        while (posExpired != 0)
        {
            unsigned __int64 nId = expired.GetAt(posExpired);
            m_shown.RemoveKey(nId);
            expired.GetNext(posExpired);
        }
    }
}
MS2_REPLACE_METHOD(0x141697430, CPopupProfileImageMan, FUN_141697430, 800, 0x76498148);

// @0x141697760
// MS2-FUNCTIONAL: frame-slot order of the MS2Ptr/guard temps differs from the exe
int CPopupProfileImageMan::FUN_141697760(unsigned __int64 nId)
{
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        int nNow = FUN_140869420();
        size_t nCount = m_shown.GetCount();
        if (*FUN_1402056b0(&FUN_1401d3200()->m_maxCount) <= (int)nCount)
            return 0;
        DataPtr spData(0);
        if (m_shown.Lookup(nId, spData))
        {
            spData->FUN_1416971c0(nNow);
            return 1;
        }
        int bNew = 0;
        spData = 0;
        if (m_pending.Lookup(nId, spData) == 0)
            bNew = 1;
        if (spData == 0)
            return 0;
        spData.AssignRaw(new CPopupProfileImageData);
        spData->FUN_141697180(nId);
        if (bNew != 0)
            m_pending.SetAt(nId, spData);
        spData->FUN_1416971c0(nNow);
        m_shown.SetAt(nId, spData);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x141697760, CPopupProfileImageMan, FUN_141697760, 627, 0x2C413CDA);

// @0x1416979e0
// MS2-FUNCTIONAL: frame-slot order of the MS2Ptr/handle temps differs from the exe
void CPopupProfileImageMan::FUN_1416979e0(unsigned __int64 nId)
{
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        DataPtr spData(0);
        if (m_shown.Lookup(nId, spData))
            m_shown.RemoveKey(nId);
        Unk_PpEntity* pEntity = FUN_1403ed2d0()->FUN_141bd1530(nId);
        bool bFound = pEntity != 0 && pEntity->vfunc_86().FUN_1416676a0() != 0;
        if (bFound)
            pEntity->vfunc_86().FUN_141667730()->vfunc_3();
    }
}
MS2_REPLACE_METHOD(0x1416979E0, CPopupProfileImageMan, FUN_1416979e0, 465, 0xF1C4CEB1);

// @0x141697bc0
unsigned int FUN_141697bc0(Unk_PpConst* p)
{
    return FUN_140a35ca0(FUN_140a36020(p));
}

// @0x141699890
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
