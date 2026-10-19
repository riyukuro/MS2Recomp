// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CU name unknown: std::vector<T> COMDAT tail (size, max_size,
// capacity, push_back, allocator::max_size and the small forwarding helpers) over 24 element types the exe does not name (stand-ins of the exact
// element size; the tag number is the one the 21 _Buy instances of unit_1415fbae0 use), followed by a small
// npc marker struct and the CRT's non-const memchr / vsnprintf wrappers.
// MS2-GUESS-LOOKALIKES
// MS2-UNIT: unit_14160a7f0
// MS2-RANGE: 0x14160a7f0-0x14160bf90 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?max_size@?$vector@U?$Unk_VecElem@$0A@$0BA@@@V?$allocator@U?$Unk_VecElem@$0A@$0BA@@@@std@@@std@@QEBA_KXZ 0x14160a990 ; prop
// MS2-PIN: ?max_size@?$vector@U?$Unk_VecElem@$00$0BI@@@V?$allocator@U?$Unk_VecElem@$00$0BI@@@@std@@@std@@QEBA_KXZ 0x14160a9e0 ; prop
// MS2-PIN: ?max_size@?$vector@U?$Unk_VecElem@$02$0DA@@@V?$allocator@U?$Unk_VecElem@$02$0DA@@@@std@@@std@@QEBA_KXZ 0x14160aa80 ; prop
// MS2-PIN: ?max_size@?$vector@U?$Unk_VecElem@$03$0JI@@@V?$allocator@U?$Unk_VecElem@$03$0JI@@@@std@@@std@@QEBA_KXZ 0x14160aad0 ; prop
// MS2-PIN: ?max_size@?$vector@U?$Unk_VecElem@$04$0CCA@@@V?$allocator@U?$Unk_VecElem@$04$0CCA@@@@std@@@std@@QEBA_KXZ 0x14160ab20 ; prop
// MS2-PIN: ?max_size@?$vector@U?$Unk_VecElem@$05$0BCI@@@V?$allocator@U?$Unk_VecElem@$05$0BCI@@@@std@@@std@@QEBA_KXZ 0x14160ab70 ; prop
// MS2-PIN: ?max_size@?$vector@U?$Unk_VecElem@$06$0BBI@@@V?$allocator@U?$Unk_VecElem@$06$0BBI@@@@std@@@std@@QEBA_KXZ 0x14160abc0 ; prop
// MS2-PIN: ?max_size@?$vector@U?$Unk_VecElem@$0BG@$0OA@@@V?$allocator@U?$Unk_VecElem@$0BG@$0OA@@@@std@@@std@@QEBA_KXZ 0x14160ac10 ; prop
// MS2-PIN: ?max_size@?$vector@U?$Unk_VecElem@$07$0FIA@@@V?$allocator@U?$Unk_VecElem@$07$0FIA@@@@std@@@std@@QEBA_KXZ 0x14160ac60 ; prop
// MS2-PIN: ?max_size@?$vector@U?$Unk_VecElem@$08$0BI@@@V?$allocator@U?$Unk_VecElem@$08$0BI@@@@std@@@std@@QEBA_KXZ 0x14160acb0 ; prop
// MS2-PIN: ?max_size@?$vector@U?$Unk_VecElem@$09$0BEKI@@@V?$allocator@U?$Unk_VecElem@$09$0BEKI@@@@std@@@std@@QEBA_KXZ 0x14160ad00 ; prop
// MS2-PIN: ?max_size@?$vector@U?$Unk_VecElem@$0L@$0BI@@@V?$allocator@U?$Unk_VecElem@$0L@$0BI@@@@std@@@std@@QEBA_KXZ 0x14160ad50 ; prop
// MS2-PIN: ?max_size@?$vector@U?$Unk_VecElem@$0M@$0BJA@@@V?$allocator@U?$Unk_VecElem@$0M@$0BJA@@@@std@@@std@@QEBA_KXZ 0x14160ada0 ; prop
// MS2-PIN: ?max_size@?$vector@U?$Unk_VecElem@$0N@$0LI@@@V?$allocator@U?$Unk_VecElem@$0N@$0LI@@@@std@@@std@@QEBA_KXZ 0x14160adf0 ; prop
// MS2-PIN: ?max_size@?$vector@U?$Unk_VecElem@$0O@$0FI@@@V?$allocator@U?$Unk_VecElem@$0O@$0FI@@@@std@@@std@@QEBA_KXZ 0x14160ae40 ; prop
// MS2-PIN: ?max_size@?$vector@U?$Unk_VecElem@$0BH@$0GI@@@V?$allocator@U?$Unk_VecElem@$0BH@$0GI@@@@std@@@std@@QEBA_KXZ 0x14160ae90 ; prop
// MS2-PIN: ?max_size@?$vector@U?$Unk_VecElem@$0P@$0KOI@@@V?$allocator@U?$Unk_VecElem@$0P@$0KOI@@@@std@@@std@@QEBA_KXZ 0x14160aee0 ; prop
// MS2-PIN: ?max_size@?$vector@U?$Unk_VecElem@$0BA@$0OMI@@@V?$allocator@U?$Unk_VecElem@$0BA@$0OMI@@@@std@@@std@@QEBA_KXZ 0x14160af30 ; prop
// MS2-PIN: ?max_size@?$vector@U?$Unk_VecElem@$0BB@$0MI@@@V?$allocator@U?$Unk_VecElem@$0BB@$0MI@@@@std@@@std@@QEBA_KXZ 0x14160af80 ; prop
// MS2-PIN: ?max_size@?$vector@U?$Unk_VecElem@$0BC@$0PI@@@V?$allocator@U?$Unk_VecElem@$0BC@$0PI@@@@std@@@std@@QEBA_KXZ 0x14160afd0 ; prop
// MS2-PIN: ?max_size@?$vector@U?$Unk_VecElem@$0BD@$0EJA@@@V?$allocator@U?$Unk_VecElem@$0BD@$0EJA@@@@std@@@std@@QEBA_KXZ 0x14160b020 ; prop
// MS2-PIN: ?max_size@?$vector@U?$Unk_VecElem@$0BE@$0CA@@@V?$allocator@U?$Unk_VecElem@$0BE@$0CA@@@@std@@@std@@QEBA_KXZ 0x14160b070 ; prop
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#define _ALLOW_KEYWORD_MACROS 1
#define private public
#include <vector>
#include <list>
#undef private
#include "ms2/placeholder/ms2stdafx.h"
#include <string.h>
#include <stdio.h>
#include <efd/Point3.h>
#include "ms2/ms2recover.h"

template <int Tag, int N> struct Unk_VecElem { unsigned __int64 q[N / 8]; };

size_t Unk_Anchor_0(std::vector<Unk_VecElem<0, 16> >& v, const Unk_VecElem<0, 16>& e)
{
    v.push_back(e);
    return v.size() + v.max_size() + v.capacity();
}
size_t Unk_Anchor_1(std::vector<Unk_VecElem<1, 24> >& v, const Unk_VecElem<1, 24>& e)
{
    v.push_back(e);
    return v.size() + v.max_size() + v.capacity();
}
size_t Unk_Anchor_2(std::vector<Unk_VecElem<2, 88> >& v, const Unk_VecElem<2, 88>& e)
{
    v.push_back(e);
    return v.size() + v.max_size() + v.capacity();
}
size_t Unk_Anchor_3(std::vector<Unk_VecElem<3, 48> >& v, const Unk_VecElem<3, 48>& e)
{
    v.push_back(e);
    return v.size() + v.max_size() + v.capacity();
}
size_t Unk_Anchor_4(std::vector<Unk_VecElem<4, 152> >& v, const Unk_VecElem<4, 152>& e)
{
    v.push_back(e);
    return v.size() + v.max_size() + v.capacity();
}
size_t Unk_Anchor_5(std::vector<Unk_VecElem<5, 544> >& v, const Unk_VecElem<5, 544>& e)
{
    v.push_back(e);
    return v.size() + v.max_size() + v.capacity();
}
size_t Unk_Anchor_6(std::vector<Unk_VecElem<6, 296> >& v, const Unk_VecElem<6, 296>& e)
{
    v.push_back(e);
    return v.size() + v.max_size() + v.capacity();
}
size_t Unk_Anchor_7(std::vector<Unk_VecElem<7, 280> >& v, const Unk_VecElem<7, 280>& e)
{
    v.push_back(e);
    return v.size() + v.max_size() + v.capacity();
}
size_t Unk_Anchor_21(std::vector<Unk_VecElem<21, 48> >& v, const Unk_VecElem<21, 48>& e)
{
    v.push_back(e);
    return v.size() + v.max_size() + v.capacity();
}
size_t Unk_Anchor_22(std::vector<Unk_VecElem<22, 224> >& v, const Unk_VecElem<22, 224>& e)
{
    v.push_back(e);
    return v.size() + v.max_size() + v.capacity();
}
size_t Unk_Anchor_8(std::vector<Unk_VecElem<8, 1408> >& v, const Unk_VecElem<8, 1408>& e)
{
    v.push_back(e);
    return v.size() + v.max_size() + v.capacity();
}
size_t Unk_Anchor_9(std::vector<Unk_VecElem<9, 24> >& v, const Unk_VecElem<9, 24>& e)
{
    v.push_back(e);
    return v.size() + v.max_size() + v.capacity();
}
size_t Unk_Anchor_10(std::vector<Unk_VecElem<10, 5288> >& v, const Unk_VecElem<10, 5288>& e)
{
    v.push_back(e);
    return v.size() + v.max_size() + v.capacity();
}
size_t Unk_Anchor_11(std::vector<Unk_VecElem<11, 24> >& v, const Unk_VecElem<11, 24>& e)
{
    v.push_back(e);
    return v.size() + v.max_size() + v.capacity();
}
size_t Unk_Anchor_12(std::vector<Unk_VecElem<12, 400> >& v, const Unk_VecElem<12, 400>& e)
{
    v.push_back(e);
    return v.size() + v.max_size() + v.capacity();
}
size_t Unk_Anchor_13(std::vector<Unk_VecElem<13, 184> >& v, const Unk_VecElem<13, 184>& e)
{
    v.push_back(e);
    return v.size() + v.max_size() + v.capacity();
}
size_t Unk_Anchor_14(std::vector<Unk_VecElem<14, 88> >& v, const Unk_VecElem<14, 88>& e)
{
    v.push_back(e);
    return v.size() + v.max_size() + v.capacity();
}
size_t Unk_Anchor_23(std::vector<Unk_VecElem<23, 104> >& v, const Unk_VecElem<23, 104>& e)
{
    v.push_back(e);
    return v.size() + v.max_size() + v.capacity();
}
size_t Unk_Anchor_15(std::vector<Unk_VecElem<15, 2792> >& v, const Unk_VecElem<15, 2792>& e)
{
    v.push_back(e);
    return v.size() + v.max_size() + v.capacity();
}
size_t Unk_Anchor_16(std::vector<Unk_VecElem<16, 3784> >& v, const Unk_VecElem<16, 3784>& e)
{
    v.push_back(e);
    return v.size() + v.max_size() + v.capacity();
}
size_t Unk_Anchor_17(std::vector<Unk_VecElem<17, 200> >& v, const Unk_VecElem<17, 200>& e)
{
    v.push_back(e);
    return v.size() + v.max_size() + v.capacity();
}
size_t Unk_Anchor_18(std::vector<Unk_VecElem<18, 248> >& v, const Unk_VecElem<18, 248>& e)
{
    v.push_back(e);
    return v.size() + v.max_size() + v.capacity();
}
size_t Unk_Anchor_19(std::vector<Unk_VecElem<19, 1168> >& v, const Unk_VecElem<19, 1168>& e)
{
    v.push_back(e);
    return v.size() + v.max_size() + v.capacity();
}
size_t Unk_Anchor_20(std::vector<Unk_VecElem<20, 32> >& v, const Unk_VecElem<20, 32>& e)
{
    v.push_back(e);
    return v.size() + v.max_size() + v.capacity();
}

// The npc's 0x30-byte marker (CNpc +0xdb0, Unk_CNpcDB0 in cnpc.h): two end points, a width/height pair derived from their
// distance and a label. Descriptive names are provisional.
struct Unk_NpcBeam
{
    Unk_NpcBeam();                                                                  // 0x14160bd70
    void Set(const efd::Point3& a, const efd::Point3& b, const char* pszLabel);     // 0x14160bde0
    void Set(const efd::Point3& a, const efd::Point3& b, float fWidth, float fScale, const char* pszLabel);     // 0x14160beb0

    bool m_bActive;             // +0x00
    efd::Point3 m_a;            // +0x04
    efd::Point3 m_b;            // +0x10
    float m_f1c;                // +0x1c
    float m_fWidth;             // +0x20
    float m_fLength;            // +0x24
    CStringA m_strLabel;        // +0x28
};
MS2_CHECK_OFFSET(Unk_NpcBeam, m_strLabel, 0x28);
MS2_CHECK_SIZE(Unk_NpcBeam, 0x30);

// @0x14160bd70
Unk_NpcBeam::Unk_NpcBeam()
{
    m_f1c = 0.0f;
    m_bActive = false;
}

// @0x14160bde0
// MS2-FUNCTIONAL: behaviour-equivalent (temp slots differ)
void Unk_NpcBeam::Set(const efd::Point3& a, const efd::Point3& b, const char* pszLabel)
{
    m_f1c = 0.0f;
    m_bActive = true;
    m_a = a;
    m_b = b;
    float fUnused = 212.132f;
    m_fLength = 0.7071f * (a - b).Length();
    m_fWidth = 0.45f;
    m_strLabel = pszLabel;
}

// @0x14160beb0
// MS2-FUNCTIONAL: behaviour-equivalent (temp slots differ)
void Unk_NpcBeam::Set(const efd::Point3& a, const efd::Point3& b, float fWidth, float fScale, const char* pszLabel)
{
    m_f1c = 0.0f;
    m_bActive = true;
    m_a = a;
    m_b = b;
    float fUnused = 212.132f;
    m_fLength = 0.7071f * (a - b).Length() * fScale;
    m_fWidth = fWidth;
    m_strLabel = pszLabel;
}

// The 32-byte forwarder at 0x14160a970 is the max_size of a container whose allocator element is 48 bytes (a list node).
size_t Unk_ListMax(std::list<Unk_VecElem<24, 32> >& l)
{
    return l.max_size();
}

// The non-const memchr overload and the CRT's static-inline _vsnprintf_l-forwarding wrapper (this unit's copy is
// FUN_14160bd30, which unit_1415fbae0 calls); a selectany table keeps the copies emitted.
void* Unk_FindByte(void* p, int c, size_t n)
{
    return memchr(p, c, n);
}

int __cdecl FUN_14160bd30(char* pDest, size_t nBufferCount, const char* pszFormat, va_list args)
{
    return _vsnprintf_l(pDest, nBufferCount, pszFormat, NULL, args);
}
