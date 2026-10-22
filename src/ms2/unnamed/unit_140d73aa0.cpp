// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Message-box factory helpers: each builds a CMsgBoxData,
// fills it in and returns it as an MS2Ptr (or shows it).
// MS2-UNIT: unit_140d73aa0
// MS2-RANGE: 0x1400d39c0-0x1400d39e0 .text$di
// MS2-RANGE: 0x140d73aa0-0x140d74b20 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ascript.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local placeholders ----

class CMsgBoxData;
typedef Delegate<bool(int, const CMsgBoxData&)> Unk_MsgBoxCallback;

// The message box data (0x2a0 bytes).
class CMsgBoxData
{
public:
    CMsgBoxData(int nType);
    void FUN_141a02860(void* p);
    void SetExtra(const CStringW& str);
    void SetMsg(const CStringW& str);
    void FUN_141a027c0(Unk_MsgBoxCallback cb);
    void FUN_141a01800(int n);
    void SetTitle(const CStringW& str);
    void FUN_141a024e0(CStringW str, bool b);
    void SetAgreement(bool b);

    char m_pad[0x2a0];
};
MS2_CHECK_SIZE(CMsgBoxData, 0x2a0);

typedef MS2Ptr<CMsgBoxData> Unk_MsgBoxPtr;

// One bit of an 11-bit set (std::bitset<11>-like) and its reference proxy.
struct Unk_BitRef
{
    bool FUN_140d750f0() const;
    void* m_pSet;
    unsigned m_nPos;
};
class Unk_BitSet11
{
public:
    Unk_BitSet11();
    Unk_BitRef FUN_140d75090(unsigned nPos);
    char m_bits[2];
};

Unk_MsgBoxCallback FUN_140b240b0();
void FUN_14151f150(Unk_MsgBoxPtr box);
CStringW GetStringCommon(int nId);
CStringW GetStringCommonByKey(const CStringW& str);

// Global of this unit (constructed by the .text$di initializer) and the "terms" flag word.
#ifdef MS2_HOOK_DLL
extern Unk_BitSet11 g_143ac2fb8;
#else
Unk_BitSet11 g_143ac2fb8;
#endif
extern int g_1439f5a0c;

void FUN_140d73c60(Unk_MsgBoxPtr box);
Unk_MsgBoxPtr FUN_140d73d20(int nType, CStringW text, void* p, CStringW tag);
Unk_MsgBoxPtr FUN_140d74390(CStringW text, int nType, Unk_MsgBoxCallback cb);
void FUN_140d73aa0(CStringW text, int nType, void* p, CStringW tag);
void FUN_140d73bc0(int nStrId, int nType, void* p, CStringW tag);

// @0x140d73aa0
void FUN_140d73aa0(CStringW text, int nType, void* p, CStringW tag)
{
    Unk_MsgBoxPtr box(new CMsgBoxData(nType));
    box->FUN_141a02860(p);
    box->SetExtra(tag);
    box->SetMsg(text);
    FUN_14151f150(box);
}

// @0x140d73bc0
void FUN_140d73bc0(int nStrId, int nType, void* p, CStringW tag)
{
    FUN_140d73aa0(GetStringCommon(nStrId), nType, p, tag);
}

// @0x140d73c60
void FUN_140d73c60(Unk_MsgBoxPtr box)
{
    if (box == 0)
        return;
    FUN_14151f150(box);
}

// @0x140d73cd0
void FUN_140d73cd0()
{
    FUN_140d73bc0(0x302, 0, 0, CStringW(L""));
}

// @0x140d73d20
Unk_MsgBoxPtr FUN_140d73d20(int nType, CStringW text, void* p, CStringW tag)
{
    Unk_MsgBoxPtr box(new CMsgBoxData(nType));
    box->FUN_141a02860(p);
    box->SetExtra(tag);
    box->SetMsg(text);
    return box;
}

// @0x140d73e40
Unk_MsgBoxPtr FUN_140d73e40(int nType, int nStrId, void* p, CStringW tag)
{
    return FUN_140d73d20(nType, GetStringCommon(nStrId), p, tag);
}

// @0x140d73f20
Unk_MsgBoxPtr FUN_140d73f20(CStringW text, int nType)
{
    Unk_MsgBoxPtr box(new CMsgBoxData(nType));
    box->SetMsg(text);
    return box;
}

// @0x140d73ff0
void FUN_140d73ff0(CStringW text)
{
    Unk_MsgBoxPtr box = FUN_140d74390(GetStringCommonByKey(text), 0, FUN_140b240b0());
}

// @0x140d74090
Unk_MsgBoxPtr FUN_140d74090(Unk_MsgBoxCallback cb, CStringW text)
{
    Unk_MsgBoxPtr box(new CMsgBoxData(1));
    box->SetMsg(GetStringCommonByKey(text));
    box->FUN_141a027c0(cb);
    FUN_14151f150(box);
    return box;
}

// @0x140d74230
Unk_MsgBoxPtr FUN_140d74230(Unk_MsgBoxCallback cb, CStringW text)
{
    Unk_MsgBoxPtr box(new CMsgBoxData(1));
    box->SetMsg(text);
    box->FUN_141a027c0(cb);
    FUN_14151f150(box);
    return box;
}

// @0x140d74390
Unk_MsgBoxPtr FUN_140d74390(CStringW text, int nType, Unk_MsgBoxCallback cb)
{
    Unk_MsgBoxPtr box(new CMsgBoxData(nType));
    box->SetMsg(text);
    box->FUN_141a027c0(cb);
    FUN_14151f150(box);
    return box;
}

// @0x140d74500
Unk_MsgBoxPtr FUN_140d74500(CStringW text, int nType, Unk_MsgBoxCallback cb)
{
    Unk_MsgBoxPtr box(new CMsgBoxData(nType));
    box->SetMsg(text);
    box->FUN_141a027c0(cb);
    return box;
}

void FUN_140d746e0(void* p, int nBit, const CStringW& strA, const CStringW& strB);

// @0x140d74640
void FUN_140d74640(void* p, int nBit, int nIdA, int nIdB)
{
    FUN_140d746e0(p, nBit, GetStringCommon(nIdA), GetStringCommon(nIdB));
}

// @0x140d746e0
void FUN_140d746e0(void* p, int nBit, const CStringW& strA, const CStringW& strB)
{
    Unk_MsgBoxPtr box = FUN_140d73d20(0x1b, CStringW(strB), p, CStringW(L"terms"));
    if (box.get() != 0)
    {
        box->FUN_141a01800(1);
        box->SetTitle(strA);
        box->FUN_141a024e0(GetStringCommon(0x9d0), 1);
        g_1439f5a0c = nBit;
        box->SetAgreement(g_143ac2fb8.FUN_140d75090(nBit).FUN_140d750f0());
        FUN_140d73c60(box);
    }
}

// @0x140d748b0
Unk_MsgBoxPtr FUN_140d748b0(int nBit, const CStringW& strA, const CStringW& strB, Unk_MsgBoxCallback cb)
{
    g_1439f5a0c = nBit;
    Unk_MsgBoxPtr box(new CMsgBoxData(0x1b));
    box->SetMsg(strB);
    {
        CStringW tag(L"terms");
        box->SetExtra(tag);
    }
    box->FUN_141a01800(1);
    box->SetTitle(strA);
    box->FUN_141a024e0(GetStringCommon(0x9d0), 1);
    box->SetAgreement(g_143ac2fb8.FUN_140d75090(nBit).FUN_140d750f0());
    box->FUN_141a027c0(cb);
    FUN_140d73c60(box);
    return box;
}
