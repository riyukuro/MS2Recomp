// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Field-move error message builder (localized-string
// switch with one formatted default case), the fmt MakeValue<int> lambda closure used by that default case, and
// four "%s%s/..." path builders over the global config object's base directories.
// MS2-UNIT: unit_140cc20a0
// MS2-RANGE: 0x140cc20a0-0x140cc2c70 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

#include <sstream>
#include <string>

typedef __int64 i64;
typedef unsigned __int64 u64;

// ---- shared string-table lookups (defined in the stringtable unit) ----
CStringW GetStringCommonByKey(const CStringW& strKey);   // text by key
CStringW GetStringCommon(int nStringId);            // text by numeric id
CString FUN_140651350();                           // localized base path

// ---- fmt argument pack (same layout as the other recovered fmt call sites) ----
struct Unk_FmtArg { const void* m_value; void* m_fn; };
struct Unk_FmtPack { i64 m_n; const Unk_FmtArg* m_args; };
CStringW FUN_14028dfa0(const CStringW& strKey, const Unk_FmtPack& args);   // StringFormat over the string table
Unk_FmtPack* FUN_140163e50(Unk_FmtPack* pOut, i64 nTypes, Unk_FmtArg arg); // fmt::internal::make_args

// fmt::internal::MakeValue's boxed-argument record: 16 payload bytes + a type tag (1 = int, 0xa = ostream text).
struct Unk_FmtVal { i64 m_w0, m_w1; int m_type; };
struct Unk_Str16 { i64 m_w0, m_w1; };
Unk_Str16* FUN_140182090(Unk_Str16*, const std::wstring&);
i64 FUN_1402da110(i64 ctx, i64* pOut, Unk_FmtVal* pVal);

// The global application/config singleton whose +0x60/+0x68/+0x70 are the base directory strings.
struct Unk_MoveErrConfig {
    char m_pad_00[0x60];
    CString m_strDir60;
    CString m_strDir68;
    CString m_strDir70;
};
MS2_CHECK_OFFSET(Unk_MoveErrConfig, m_strDir60, 0x60);
MS2_CHECK_OFFSET(Unk_MoveErrConfig, m_strDir68, 0x68);
MS2_CHECK_OFFSET(Unk_MoveErrConfig, m_strDir70, 0x70);
Unk_MoveErrConfig* FUN_1401d31f0();

// ---- the int-argument formatter lambda and its closure ----

void FUN_140cc2650(i64 ctx, i64* pOut, int* pValue);
void FUN_140cc2770(i64 ctx, i64 value, i64* pOut);
i64 FUN_140cc27a0(int* pValue);
i64 FUN_140cc27c0();

// fmt::internal::MakeValue<int>: box the int (tag 1) and hand it to the formatter.
// @0x140cc2650
void FUN_140cc2650(i64 ctx, i64* pOut, int* pValue)
{
    Unk_FmtVal val;
    Unk_FmtVal* pv = &val;
    *(int*)pv = *pValue;   // the exe's generic ostream branch (tag 0xa) is unreachable for int
    val.m_type = 1;
    *pOut = FUN_1402da110(ctx, pOut, &val);
}

// The lambda thunk: vfunc(value, out) forwarding to MakeValue<int>.
// @0x140cc2770
void FUN_140cc2770(i64 ctx, i64 value, i64* pOut)
{
    FUN_140cc2650(ctx, pOut, (int*)value);
}

// Closure construction for the one-argument lambda: { captured int*, thunk }.
// @0x140cc2570
Unk_FmtArg* FUN_140cc2570(Unk_FmtArg* pOut, int* pValue)
{
    pOut->m_value = pValue;
    pOut->m_fn = (void*)&FUN_140cc2770;
    return pOut;
}

// The argument-type id handed to make_args for this lambda.
// @0x140cc27a0
i64 FUN_140cc27a0(int*)
{
    return FUN_140cc27c0();
}

// @0x140cc27c0
i64 FUN_140cc27c0()
{
    return 0xd;
}

// Format the default move-error message with the error code as {0}.
// @0x140cc25a0
CStringW FUN_140cc25a0(CStringW strKey, int* pValue)
{
    Unk_FmtArg arg;
    FUN_140cc2570(&arg, pValue);
    Unk_FmtPack pack;
    FUN_140163e50(&pack, FUN_140cc27a0(pValue), arg);
    return FUN_14028dfa0(strKey, pack);
}

// @0x140cc27d0 - the CRT's bounds-checked memmove_s (UCRT static-inline copy, unreferenced in this TU).
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);

// ---- path builders over the config's base directories ----

// @0x140cc28f0
CString FUN_140cc28f0(const CString& strA, const CString& strB)
{
    CString str;
    str.Format("%s%s/%s/%s", (LPCSTR)FUN_1401d31f0()->m_strDir68, (LPCSTR)FUN_140651350(),
               (LPCSTR)strA, (LPCSTR)strB);
    return str;
}

// @0x140cc2a00
CString FUN_140cc2a00(const CString& strA, const CString& strB)
{
    CString str;
    str.Format("%s%s/%s", (LPCSTR)FUN_1401d31f0()->m_strDir60, (LPCSTR)strA, (LPCSTR)strB);
    return str;
}

// @0x140cc2ad0
CString FUN_140cc2ad0(const CString& strA, const CString& strB)
{
    CString str;
    str.Format("%s%s/%s", (LPCSTR)FUN_1401d31f0()->m_strDir68, (LPCSTR)strA, (LPCSTR)strB);
    return str;
}

// @0x140cc2ba0
CString FUN_140cc2ba0(const CString& strA, const CString& strB)
{
    CString str;
    str.Format("%s%s/%s", (LPCSTR)FUN_1401d31f0()->m_strDir70, (LPCSTR)strA, (LPCSTR)strB);
    return str;
}

// ---- the move-error switch ----

// @0x140cc20a0
CStringW FUN_140cc20a0(int nErr)
{
    switch (nErr) {
    case 8:  return GetStringCommon(0x268);
    case 9:
    case 0x15: return GetStringCommon(0x269);
    case 0x11: return GetStringCommon(0x26a);
    case 10:
    case 0x16: return GetStringCommon(0x26c);
    case 0xc:  return GetStringCommon(0x26d);
    case 0x1b: { CStringW str(L"s_party_err_not_chief"); return GetStringCommonByKey(str); }
    case 0x1d: { CStringW str(L"s_move_err_dungeon_not_exist"); return GetStringCommonByKey(str); }
    case 0x1e: { CStringW str(L"s_move_err_FailCreateDungeon"); return GetStringCommonByKey(str); }
    case 0x1f: { CStringW str(L"s_move_err_DungeonMatch"); return GetStringCommonByKey(str); }
    case 0x1c: { CStringW str(L"s_move_err_NotFoundParty"); return GetStringCommonByKey(str); }
    case 0x20: { CStringW str(L"s_move_err_InsideDungeonUser"); return GetStringCommonByKey(str); }
    case 0x22: { CStringW str(L"s_move_err_InsideSurvivalSquad"); return GetStringCommonByKey(str); }
    case 0x21: { CStringW str(L"s_move_err_ExpireEnterTime"); return GetStringCommonByKey(str); }
    case 7: { CStringW str(L"s_move_err_field_limit"); return GetStringCommonByKey(str); }
    case 0x23: { CStringW str(L"s_move_err_wedding_complete"); return GetStringCommonByKey(str); }
    default:
        return FUN_140cc25a0(CStringW(L"s_move_err_default"), &nErr);
    }
}
