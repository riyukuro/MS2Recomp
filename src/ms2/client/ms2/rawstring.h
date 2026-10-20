// rawstring.h - RawString: the hard-coded launcher/platform error texts (per service region), usable before the string
// tables load. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the header name comes from the assert path
// e:\build\kr\22_04\ms2code\client\ms2\rawstring.h (ASSERT(FALSE), line 184, MakeList 0x140c7a750). The class name
// is the file name; the enumerator names are invented from the texts. Inline header class: its COMDATs (and the
// CAtlMap<ERawString, CStringW> / CAtlArray<RawString::Entry> instances) sit in unit_140c77ab0, the first user in link
// order (CClientPlatformNexonKorea); CGameApp::InitInstance, CNXMan and CNetworkService call the same copies.
// Strings cross-checked with the third-party v2525 snapshot (work/ext/v2525, same VAs).
#pragma once

#include <afxstr.h>
#include <atlcoll.h>
#include "ms2/ms2format.h"
#include "ms2/ms2layout.h"

extern "C" _ACRTIMP void __cdecl _wassert(wchar_t const* _Message, wchar_t const* _File, unsigned _Line);
#define MS2_RAWSTRING_ASSERT(line, expression)                                                                     \
    (void)((!!(expression)) ||                                                                                     \
           (_wassert(_CRT_WIDE(#expression), L"e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\rawstring.h", line), 0))

extern int DAT_143ab0248;                       // the service region (0 Korea, 1 Japan, 2 global, 3 China)

// The text id; an enum (not int): the fallback "{0}" argument goes through fmt's custom-argument path (0x140c794b0).
enum ERawString
{
    RAWSTRING_INIT_ERROR = 0,
    RAWSTRING_INVALID_LAUNCH = 1,
    RAWSTRING_AUTH_INIT_FAILED = 2,
    RAWSTRING_VERSION_CHECK_FAILED = 3,
    RAWSTRING_VERSION_CHECK_FAILED2 = 4,
    RAWSTRING_AUTH_SUSPENDED = 5,
    RAWSTRING_REGION_MISMATCH = 6,
    RAWSTRING_IP_RESTRICTED = 7,
    RAWSTRING_LOGIN_LOCKED = 8,
    RAWSTRING_ACCOUNT_SUSPENDED = 9,
    RAWSTRING_WRONG_PASSWORD = 10,
    RAWSTRING_WRONG_PASSWORD2 = 11,
    RAWSTRING_NOT_OWNER = 12,
    RAWSTRING_TEMPORARY_MEMBER = 13,
    RAWSTRING_INACTIVE_MEMBER = 14,
    RAWSTRING_PASSWORD_CAMPAIGN = 15,
    RAWSTRING_OVERSEAS_BLOCKED = 16,
    RAWSTRING_ACCOUNT_RESTRICTED = 17,
    RAWSTRING_EMAIL_ID = 18,
    RAWSTRING_TRIAL_ID_EXPIRED = 19,
    RAWSTRING_PCROOM_NUMBER = 20,
    RAWSTRING_PCROOM_LOCKED = 21,
    RAWSTRING_OTHER_IP_LOGIN = 22,
    RAWSTRING_IP_CHANGED = 23,
    RAWSTRING_LOGIN_FAILED = 24,
    RAWSTRING_LAUNCH_ERROR = 25,
    RAWSTRING_NGS_ERROR = 26,
    RAWSTRING_NGS_VERIFY_ERROR = 27,
    RAWSTRING_END = 28
};

class RawString
{
public:
    // 0x10 bytes: code +0, text +8.
    struct Entry
    {
        Entry(ERawString code, CStringW text) { m_code = code; m_text = text; }     // @0x140c79820 (text by value)
        ERawString GetCode() { return m_code; }                                     // @0x140c7a470
        CStringW GetText() { return m_text; }                                       // @0x140c7a420
        ERawString m_code;
        CStringW m_text;
    };

    // @0x140c79890
    RawString()
    {
        ATL::CAtlArray<Entry> list;
        MakeList(list);
        int i = 0;
        Entry entry = list[i];
        while (entry.GetCode() != RAWSTRING_END) {
            m_map.SetAt(entry.GetCode(), entry.GetText());
            ++i;
            entry = list[i];
        }
    }

    // @0x140c79b50
    ~RawString() {}

    // @0x140c7a360
    CStringW Get(const ERawString& code)
    {
        CStringW text;
        if (m_map.Lookup(code, text))
            return text;
        return StringFormat(L"An error occurred. ( code : {0} )", code);
    }

    // @0x140c7a750: one list per service region, each ending with RAWSTRING_END.
    void MakeList(ATL::CAtlArray<Entry>& list)
    {
        switch (DAT_143ab0248) {
        case 0:
            list.Add(Entry(RAWSTRING_INIT_ERROR, L"\uAC8C\uC784 \uCD08\uAE30\uD654 \uC5D0\uB7EC\uC785\uB2C8\uB2E4.\nCode ({0})"));
            list.Add(Entry(RAWSTRING_INVALID_LAUNCH, L"\uC798\uBABB\uB41C \uC2E4\uD589\uC785\uB2C8\uB2E4\n\uC6F9 \uD398\uC774\uC9C0\uB97C \uD1B5\uD574\uC11C \uC2E4\uD589\uD574 \uC8FC\uC138\uC694.(21)"));
            list.Add(Entry(RAWSTRING_AUTH_INIT_FAILED, L"\uC778\uC99D \uBAA8\uB4C8 \uCD08\uAE30\uD654\uC5D0 \uC2E4\uD328\uD588\uC2B5\uB2C8\uB2E4.(31)"));
            list.Add(Entry(RAWSTRING_VERSION_CHECK_FAILED, L"\uD074\uB77C\uC774\uC5B8\uD2B8 \uBC84\uC804 \uCCB4\uD06C\uC5D0 \uC2E4\uD328\uD588\uC2B5\uB2C8\uB2E4.(37)"));
            list.Add(Entry(RAWSTRING_VERSION_CHECK_FAILED2, L"\uD074\uB77C\uC774\uC5B8\uD2B8 \uBC84\uC804 \uCCB4\uD06C\uC5D0 \uC2E4\uD328\uD588\uC2B5\uB2C8\uB2E4.(38)"));
            list.Add(Entry(RAWSTRING_AUTH_SUSPENDED, L"\uC778\uC99D \uC11C\uBE44\uC2A4\uAC00 \uC77C\uC2DC\uC801\uC73C\uB85C \uC911\uB2E8\uB418\uC5C8\uC2B5\uB2C8\uB2E4. \uD648\uD398\uC774\uC9C0 \uACF5\uC9C0\uC0AC\uD56D\uC744 \uD655\uC778\uD574\uC8FC\uC138\uC694."));
            list.Add(Entry(RAWSTRING_REGION_MISMATCH, L"\uC9C0\uC5ED \uC815\uBCF4\uAC00 \uB9DE\uC9C0 \uC54A\uC2B5\uB2C8\uB2E4."));
            list.Add(Entry(RAWSTRING_IP_RESTRICTED, L"\uC81C\uD55C\uB41C IP \uC8FC\uC18C\uB85C \uB85C\uADF8\uC778\uC774 \uBD88\uAC00\uB2A5\uD569\uB2C8\uB2E4."));
            list.Add(Entry(RAWSTRING_LOGIN_LOCKED, L"\uB85C\uADF8\uC778\uC744 10\uD68C \uC774\uC0C1 \uC2E4\uD328\uD588\uC2B5\uB2C8\uB2E4. \uACC4\uC815\uBCF4\uD638\uB97C \uC704\uD574\uC11C 10\uBD84\uAC04 \uB85C\uADF8\uC778\uC744 \uC911\uC9C0\uD569\uB2C8\uB2E4."));
            list.Add(Entry(RAWSTRING_ACCOUNT_SUSPENDED, L"\uAD00\uB9AC\uC790\uC5D0 \uC758\uD574 \uC0AC\uC6A9\uC774 \uC911\uC9C0\uB41C \uC544\uC774\uB514\uC785\uB2C8\uB2E4. \uB85C\uADF8\uC778\uC774 \uBD88\uAC00\uB2A5\uD569\uB2C8\uB2E4."));
            list.Add(Entry(RAWSTRING_WRONG_PASSWORD, L"\uC785\uB825\uD558\uC2E0 \uC544\uC774\uB514 \uB610\uB294 \uBE44\uBC00\uBC88\uD638\uAC00 \uC815\uD655\uD558\uC9C0 \uC54A\uC2B5\uB2C8\uB2E4. \uD655\uC778 \uD6C4 \uB2E4\uC2DC \uC2DC\uB3C4\uD574\uC8FC\uC138\uC694."));
            list.Add(Entry(RAWSTRING_WRONG_PASSWORD2, L"\uC785\uB825\uD558\uC2E0 \uC544\uC774\uB514 \uB610\uB294 \uBE44\uBC00\uBC88\uD638\uAC00 \uC815\uD655\uD558\uC9C0 \uC54A\uC2B5\uB2C8\uB2E4. \uD655\uC778 \uD6C4 \uB2E4\uC2DC \uC2DC\uB3C4\uD574\uC8FC\uC138\uC694."));
            list.Add(Entry(RAWSTRING_NOT_OWNER, L"\uD604\uC7AC \uC544\uC774\uB514\uB294 \uBCF8\uC778 \uC544\uB2D8\uC774 \uD655\uC778\uB418\uC5B4 \uC0AC\uC6A9\uD558\uC2E4 \uC218 \uC5C6\uC2B5\uB2C8\uB2E4."));
            list.Add(Entry(RAWSTRING_TEMPORARY_MEMBER, L"\uD68C\uC6D0\uB2D8\uC740 \uC784\uC2DC\uAC00\uC785 \uC0C1\uD0DC\uC785\uB2C8\uB2E4. \uB125\uC2A8 \uD648\uD398\uC774\uC9C0\uC5D0\uC11C \uBCF8\uC778\uC778\uC99D \uC644\uB8CC \uD6C4 \uB85C\uADF8\uC778\uD574\uC8FC\uC138\uC694."));
            list.Add(Entry(RAWSTRING_INACTIVE_MEMBER, L"\uACE0\uAC1D\uB2D8\uC740 \uC7A5\uAE30\uBBF8\uC811\uC18D \uD68C\uC6D0\uC73C\uB85C \uBCF8\uC778\uD655\uC778 \uD6C4 \uB85C\uADF8\uC778\uD558\uC2E4 \uC218 \uC788\uC2B5\uB2C8\uB2E4."));
            list.Add(Entry(RAWSTRING_PASSWORD_CAMPAIGN, L"\uBE44\uBC00\uBC88\uD638 \uBCC0\uACBD \uCEA0\uD398\uC778 \uC9C4\uD589 \uC911 \uC785\uB2C8\uB2E4. \uBE44\uBC00\uBC88\uD638 \uBCC0\uACBD \uD6C4 \uB2E4\uC2DC \uB85C\uADF8\uC778\uD574\uC8FC\uC138\uC694."));
            list.Add(Entry(RAWSTRING_OVERSEAS_BLOCKED, L"\uD574\uC678 \uB85C\uADF8\uC778 \uCC28\uB2E8 \uAE30\uB2A5\uC774 \uC2E4\uD589\uB418\uC5C8\uC2B5\uB2C8\uB2E4. \uB125\uC2A8\uB2F7\uCEF4\uC5D0\uC11C \uB85C\uADF8\uC778\uD558\uC2DC\uBA74 \uBCF8\uC778\uD655\uC778\uC744 \uD1B5\uD574 \uC548\uC804\uD558\uAC8C \uB85C\uADF8\uC778 \uD560 \uC218 \uC788\uC2B5\uB2C8\uB2E4."));
            list.Add(Entry(RAWSTRING_ACCOUNT_RESTRICTED, L"\uC0AC\uC6A9\uC774 \uC81C\uD55C\uB41C \uC544\uC774\uB514\uC785\uB2C8\uB2E4."));
            list.Add(Entry(RAWSTRING_EMAIL_ID, L"\uC774\uBA54\uC77C \uC544\uC774\uB514\uB85C \uC804\uD658\uB418\uC5B4 \uC788\uC5B4 \uC774\uBA54\uC77C \uC544\uC774\uB514\uB85C \uB85C\uADF8\uC778 \uD558\uC154\uC57C \uD569\uB2C8\uB2E4."));
            list.Add(Entry(RAWSTRING_TRIAL_ID_EXPIRED, L"\uACE0\uAC1D\uB2D8\uAED8\uC11C \uC774\uC6A9\uD558\uC2DC\uB294 \uD3F0\uBC88\uD638\uCCB4\uD5D8ID\uB294 \uC0AC\uC6A9\uAE30\uAC04\uC774 \uB9CC\uB8CC\uB418\uC5C8\uC2B5\uB2C8\uB2E4. \uC815\uADDC \uC774\uBA54\uC77CID\uB85C \uC804\uD658 \uD6C4 \uB125\uC2A8 \uC11C\uBE44\uC2A4\uB97C \uC774\uC6A9\uD574\uC8FC\uC2DC\uAE30 \uBC14\uB78D\uB2C8\uB2E4."));
            list.Add(Entry(RAWSTRING_PCROOM_NUMBER, L"PC\uBC29 \uB85C\uADF8\uC778 \uBC88\uD638\uAC00 \uC798\uBABB\uB418\uC5C8\uC2B5\uB2C8\uB2E4. \uBC88\uD638\uB97C \uD655\uC778\uD55C \uD6C4 8\uC790\uB9AC \uC22B\uC790\uB97C \uC785\uB825\uD574\uC8FC\uC2DC\uAE30 \uBC14\uB78D\uB2C8\uB2E4."));
            list.Add(Entry(RAWSTRING_PCROOM_LOCKED, L"PC\uBC29 \uB85C\uADF8\uC778 \uBC88\uD638\uB97C 10\uD68C \uC774\uC0C1 \uC798\uBABB \uC785\uB825\uD558\uC168\uC2B5\uB2C8\uB2E4. \uC7A0\uC2DC \uD6C4 \uB2E4\uC2DC \uC774\uC6A9\uD574\uC8FC\uC2DC\uAE30 \uBC14\uB78D\uB2C8\uB2E4."));
            list.Add(Entry(RAWSTRING_OTHER_IP_LOGIN, L"\uB2E4\uB978 IP\uC5D0\uC11C \uB85C\uADF8\uC778 \uD588\uC2B5\uB2C8\uB2E4. \uAC8C\uC784\uC744 \uC885\uB8CC\uD569\uB2C8\uB2E4."));
            list.Add(Entry(RAWSTRING_LOGIN_FAILED, L"\uB85C\uADF8\uC778\uC5D0 \uC2E4\uD328\uD588\uC2B5\uB2C8\uB2E4. \uC7A0\uC2DC \uD6C4\uC5D0 \uB2E4\uC2DC \uC2DC\uB3C4\uD574\uC8FC\uC138\uC694. [{0}]"));
            list.Add(Entry(RAWSTRING_NGS_ERROR, L"NGS \uC5D0\uB7EC\uC785\uB2C8\uB2E4. ({0:08X})"));
            list.Add(Entry(RAWSTRING_NGS_VERIFY_ERROR, L"NGS \uAC80\uC99D\uC5D0\uB7EC\uC785\uB2C8\uB2E4. ({0:08X})"));
            list.Add(Entry(RAWSTRING_IP_CHANGED, L"IP\uAC00 \uBCC0\uACBD\uB418\uC5B4 \uB85C\uADF8\uC778\uC774 \uD574\uC81C\uB418\uC5C8\uC2B5\uB2C8\uB2E4. \uB2E4\uC2DC \uB85C\uADF8\uC778\uD574\uC8FC\uC138\uC694.\n* \uB124\uD2B8\uC6CC\uD06C\uAC00 \uBD88\uC548\uC815\uD55C \uD658\uACBD\uC5D0\uC11C\uB294 \uC811\uC18D\uC5D0 \uBB38\uC81C\uAC00 \uBC1C\uC0DD\uD560 \uC218 \uC788\uC2B5\uB2C8\uB2E4. \n\uACC4\uC18D\uC801\uC73C\uB85C \uBB38\uC81C\uAC00 \uBC1C\uC0DD\uD558\uB294 \uACBD\uC6B0 \uC720\uC120 \uB124\uD2B8\uC6CC\uD06C \uD639\uC740 WI-FI \uB97C \uD1B5\uD574 \uAC8C\uC784\uC5D0 \uC811\uC18D\uD574\uC8FC\uC2DC\uAE30 \uBC14\uB78D\uB2C8\uB2E4."));
            list.Add(Entry(RAWSTRING_END, L""));
            break;
        case 1:
            list.Add(Entry(RAWSTRING_INIT_ERROR, L"\u30B2\u30FC\u30E0\u521D\u671F\u5316\u30A8\u30E9\u30FC\u3067\u3059\u3002\nCode ({0})"));
            list.Add(Entry(RAWSTRING_INVALID_LAUNCH, L"\u5B9F\u884C\u30A8\u30E9\u30FC\u304C\u767A\u751F\u3057\u307E\u3057\u305F\u3002\n\u516C\u5F0F\u30B5\u30A4\u30C8\u304B\u3089\u5B9F\u884C\u3057\u3066\u304F\u3060\u3055\u3044\u3002(21)"));
            list.Add(Entry(RAWSTRING_AUTH_INIT_FAILED, L"\u8A8D\u8A3C\u30E2\u30B8\u30E5\u30FC\u30EB\u306E\u521D\u671F\u5316\u306B\u5931\u6557\u3057\u307E\u3057\u305F\u3002(31)"));
            list.Add(Entry(RAWSTRING_VERSION_CHECK_FAILED, L"\u30AF\u30E9\u30A4\u30A2\u30F3\u30C8\u306E\u30D0\u30FC\u30B8\u30E7\u30F3\u30C1\u30A7\u30C3\u30AF\u306B\u5931\u6557\u3057\u307E\u3057\u305F\u3002(37)"));
            list.Add(Entry(RAWSTRING_VERSION_CHECK_FAILED2, L"\u30AF\u30E9\u30A4\u30A2\u30F3\u30C8\u306E\u30D0\u30FC\u30B8\u30E7\u30F3\u30C1\u30A7\u30C3\u30AF\u306B\u5931\u6557\u3057\u307E\u3057\u305F\u3002(38)"));
            list.Add(Entry(RAWSTRING_IP_CHANGED, L"\u30ED\u30B0\u30A4\u30F3\u6642\u3068\u7570\u306A\u308B\u30B0\u30ED\u30FC\u30D0\u30EBIP\u3067\u63A5\u7D9A\u3055\u308C\u307E\u3057\u305F\u3002\n\u30B0\u30ED\u30FC\u30D0\u30EBIP\u304C\u5360\u6709\u3055\u308C\u306A\u3044\u7B49\u306E\u4E00\u90E8\u5229\u7528\u74B0\u5883\u3067\u306F\u63A5\u7D9A\u306B\u554F\u984C\u304C\u767A\u751F\u3059\u308B\u5834\u5408\u304C\u3054\u3056\u3044\u307E\u3059\u3002\n\u3054\u5229\u7528\u306E\u74B0\u5883\u306E\u30CD\u30C3\u30C8\u30EF\u30FC\u30AF\u7BA1\u7406\u8005\u307E\u305F\u306F\u30D7\u30ED\u30D0\u30A4\u30C0\u3078\u304A\u554F\u3044\u5408\u308F\u305B\u304F\u3060\u3055\u3044\u3002"));
            list.Add(Entry(RAWSTRING_LOGIN_FAILED, L"\u518D\u5EA6\u3001\u30ED\u30B0\u30A4\u30F3\u3057\u3066\u304F\u3060\u3055\u3044\u3002[{0}]"));
            list.Add(Entry(RAWSTRING_NGS_ERROR, L"NGS\u30A8\u30E9\u30FC\u3067\u3059\u3002({0:08X})"));
            list.Add(Entry(RAWSTRING_END, L""));
            break;
        case 2:
            list.Add(Entry(RAWSTRING_INVALID_LAUNCH, L"Game execution failure\nPlease restart the game from launcher.(21)"));
            list.Add(Entry(RAWSTRING_NGS_ERROR, L"An error occurred while executing NGS. ({0:08X})"));
            list.Add(Entry(RAWSTRING_END, L""));
            break;
        case 3:
            list.Add(Entry(RAWSTRING_INIT_ERROR, L"\u6E38\u620F\u521D\u59CB\u5316\u9519\u8BEF.\nCode({0})"));
            list.Add(Entry(RAWSTRING_INVALID_LAUNCH, L"\u8FD0\u884C\u5F02\u5E38\n\u8BF7\u901A\u8FC7\u7F51\u9875\u8FD0\u884C.(21)"));
            list.Add(Entry(RAWSTRING_AUTH_INIT_FAILED, L"\u8BA4\u8BC1\u6A21\u5757\u521D\u59CB\u5316\u5931\u8D25.(31)"));
            list.Add(Entry(RAWSTRING_VERSION_CHECK_FAILED, L"\u6E38\u620F\u7248\u672C\u68C0\u6D4B\u5931\u8D25.(37)"));
            list.Add(Entry(RAWSTRING_VERSION_CHECK_FAILED2, L"\u6E38\u620F\u7248\u672C\u68C0\u6D4B\u5931\u8D25.(38)"));
            list.Add(Entry(RAWSTRING_LAUNCH_ERROR, L"\u8FD0\u884C\u5F02\u5E38(21) - {0}"));
            list.Add(Entry(RAWSTRING_END, L""));
            break;
        default:
            MS2_RAWSTRING_ASSERT(184, FALSE);
            list.Add(Entry(RAWSTRING_END, L""));
            break;
        }
    }

    ATL::CAtlMap<ERawString, CStringW> m_map;
};
MS2_CHECK_SIZE(RawString, 0x48);
