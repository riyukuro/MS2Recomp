// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Terms-agreement message box ("terms" tag, 11-bit "already
// agreed" bit set), its two "terms:<flag>:<flag>" tag parsers, the bitset<11> helpers and the CExplorer1 DYNCREATE glue.
// Names are invented from use.
// MS2-UNIT: unit_140d74b20
// MS2-RANGE: 0x140d74b20-0x140d75430 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\bitset.inl"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cexplorer1.h"
#include <atlcoll.h>

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local placeholders (the same views as in unit_140d73aa0) ----

class CMsgBoxData;
typedef Delegate<bool(int, const CMsgBoxData&)> Unk_MsgBoxCallback;

class CMsgBoxData                                               // 0x2a0 bytes
{
public:
    CMsgBoxData(int nType);
    void FUN_141a01660(const CStringW& str);
    void FUN_141a01570(const CStringW& str);
    void FUN_141a027c0(Unk_MsgBoxCallback cb);
    void FUN_141a01800(int n);
    void FUN_141a015d0(const CStringW& str);
    void FUN_141a024e0(CStringW str, bool b);
    void FUN_141a02560(CStringW str, bool b);
    void FUN_141a02730(bool b);

    char m_pad[0x2a0];
};
MS2_CHECK_SIZE(CMsgBoxData, 0x2a0);

typedef MS2Ptr<CMsgBoxData> Unk_MsgBoxPtr;

// std::bitset<11>-like set (2 bytes). The member names follow the symbols the other units already use.
class Unk_PCBaseFlags
{
public:
    Unk_PCBaseFlags& FUN_140d75120(unsigned nPos, bool bValue);   // set / clear one bit
    bool FUN_140d75240(unsigned nPos) const;                // test one bit
    void FUN_140d752e0(unsigned char c);                             // fill both bytes
    void FUN_140d75340();                                   // trim the unused top bits

    unsigned char m_bits[2];
};

struct Unk_BitRef                                           // reference proxy for one bit
{
    Unk_BitRef(Unk_PCBaseFlags* pSet, unsigned nPos);       // 0x140d75060
    bool FUN_140d750f0() const;
    Unk_PCBaseFlags* m_pSet;
    unsigned m_nPos;
};

class Unk_BitSet11 : public Unk_PCBaseFlags
{
public:
    Unk_BitSet11();
    Unk_BitRef FUN_140d75090(unsigned nPos);
};

class Unk_UgcTextFilter { public: void FUN_1416fb300(CStringW& str); };
Unk_UgcTextFilter* FUN_1403b4750();
CStringW FUN_14028de60(int nId);
CStringW FUN_1405c2690(CStringW key, const CStringW& arg);
void FUN_14025a680(const CStringW& str, ATL::CAtlArray<CStringW>& out, const wchar_t* sep);
size_t FUN_14015a000(ATL::CAtlArray<CStringW>& arr);
CStringW& FUN_140159a00(ATL::CAtlArray<CStringW>& arr, size_t i);
void FUN_140d73c60(Unk_MsgBoxPtr box);

extern Unk_BitSet11 g_143ac2fb8;
extern int g_1439f5a0c;

// @0x140d74b20
Unk_MsgBoxPtr FUN_140d74b20(int nBit, const CStringW& strA, const CStringW& strB, const CStringW& strText, Unk_MsgBoxCallback cb)
{
    g_1439f5a0c = nBit;
    Unk_MsgBoxPtr box(new CMsgBoxData(0x1c));
    box->FUN_141a01570(strText);
    {
        CStringW tag(L"terms");
        box->FUN_141a01660(tag);
    }
    box->FUN_141a01800(1);
    box->FUN_141a015d0(strA);
    box->FUN_141a024e0(FUN_14028de60(0x9d0), 1);
    CStringW coupon = FUN_1405c2690(CStringW(L"s_ugc_edit_terms_coupon_agree"), strB);
    FUN_1403b4750()->FUN_1416fb300(coupon);
    box->FUN_141a02560(CStringW(coupon), 1);
    box->FUN_141a02730(g_143ac2fb8.FUN_140d75090(nBit).FUN_140d750f0());
    box->FUN_141a027c0(cb);
    FUN_140d73c60(box);
    return box;
}

// @0x140d74e50
void FUN_140d74e50(int nBit)
{
    g_143ac2fb8.FUN_140d75120(nBit, 1);
}

// @0x140d74e80
int FUN_140d74e80(CStringW& tag)
{
    if (tag.Find(L"terms", 0) != 0)
        return 0;
    ATL::CAtlArray<CStringW> parts;
    FUN_14025a680(tag, parts, L",");
    if (FUN_14015a000(parts) < 2)
        return 0;
    if (g_1439f5a0c != 8)
        FUN_140d74e50(g_1439f5a0c);
    return FUN_140159a00(parts, 1).Find(L"true", 0) != -1;
}

// @0x140d74f70
int FUN_140d74f70(CStringW& tag)
{
    if (tag.Find(L"terms", 0) != 0)
        return 0;
    ATL::CAtlArray<CStringW> parts;
    FUN_14025a680(tag, parts, L",");
    if (FUN_14015a000(parts) < 3)
        return 0;
    return FUN_140159a00(parts, 2).Find(L"true", 0) != -1;
}

// @0x140d75040
Unk_BitSet11::Unk_BitSet11()
{
    FUN_140d752e0(0);
}

// @0x140d75060
Unk_BitRef::Unk_BitRef(Unk_PCBaseFlags* pSet, unsigned nPos)
{
    m_pSet = pSet;
    m_nPos = nPos;
}

// @0x140d75090
Unk_BitRef Unk_BitSet11::FUN_140d75090(unsigned nPos)
{
    (void)((!!(nPos < 11)) || (_wassert(L"UINT(pos) < UINT(T)", _CRT_WIDE(MS2_THIS_FILE), 0x98), 0));
    return Unk_BitRef(this, nPos);
}

// @0x140d750f0
bool Unk_BitRef::FUN_140d750f0() const
{
    return m_pSet->FUN_140d75240(m_nPos);
}

// @0x140d75120
Unk_PCBaseFlags& Unk_PCBaseFlags::FUN_140d75120(unsigned nPos, bool bValue)
{
    if (nPos >= 11)
        MS2_ASSERT_AT(0xf3, 0);
    if (bValue)
        m_bits[(int)nPos / 8] |= 1 << ((int)nPos % 8);
    else
        m_bits[(int)nPos / 8] &= ~(1 << ((int)nPos % 8));
    return *this;
}

// @0x140d75240
bool Unk_PCBaseFlags::FUN_140d75240(unsigned nPos) const
{
    if (nPos >= 11)
    {
        MS2_ASSERT_AT(0x194, 0);
        return false;
    }
    return (m_bits[(int)nPos / 8] & (1 << ((int)nPos % 8))) != 0;
}

// @0x140d752e0
void Unk_PCBaseFlags::FUN_140d752e0(unsigned char c)
{
    for (int i = 1; i >= 0; i--)
        m_bits[i] = c;
    if (c != 0)
        FUN_140d75340();
}

// @0x140d75340
// The exe's constant test runs the trim only when 11 % 8 == 0, i.e. never.
void Unk_PCBaseFlags::FUN_140d75340()
{
    if (11 % 8) {
    } else {
        m_bits[1] &= 7;
    }
}

// CExplorer1 IMPLEMENT_DYNCREATE, spelled out in the exe's function order
// @0x140d75380
CRuntimeClass* PASCAL CExplorer1::_GetBaseClass()
{
    return RUNTIME_CLASS(CWnd);
}

AFX_COMDAT const CRuntimeClass CExplorer1::classCExplorer1 = {
    "CExplorer1", sizeof(class CExplorer1), 0xFFFF, CExplorer1::CreateObject, &CExplorer1::_GetBaseClass, NULL, NULL };

CRuntimeClass* PASCAL CExplorer1::GetThisClass()
{
    return _RUNTIME_CLASS(CExplorer1);
}

// @0x140d753b0
CRuntimeClass* CExplorer1::GetRuntimeClass() const
{
    return _RUNTIME_CLASS(CExplorer1);
}

// @0x140d753d0
CObject* PASCAL CExplorer1::CreateObject()
{
    return new CExplorer1;
}
