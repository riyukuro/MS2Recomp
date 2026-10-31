// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The chat text to HTML converter (TextToHtml): colours the chat
// lines by their kind (normal, whisper, party, guild, megaphone, system notice, wedding hall, UGC event, dungeon helper, ...),
// builds the "event:" link texts of the Scaleform text field and the string-table formatted line bodies. See texttohtml.h.
// MS2-UNIT: ?\texttohtml.cpp
// MS2-RANGE: 0x14010d840-0x14010db90 .text$di
// MS2-RANGE: 0x14183e640-0x141847510 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\texttohtml.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "texttohtml.h"

#include <atlcoll.h>

#include "ms2/ms2format.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/wcformat.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/commonfiles/itemdatatable.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/weddingtable.h"

MS2_EMIT_CRT_MEMMOVE_S();

typedef unsigned long ULong;                                    // the colour (a 32 bit unsigned: DWORD)

// ---- statics (dynamic initializers 0x14010d840..0x14010db40) ----

static CStringW s_strIconMegaphone1 = L"export_common_icon_megaphone1";     // @0x14010d840
static CStringW s_strIconMegaphone2 = L"export_common_icon_megaphone2";     // @0x14010d870
static CStringW s_strIconMegaphone3 = L"export_common_icon_megaphone3";     // @0x14010d8a0
static CStringW s_strIconMegaphone5 = L"export_common_icon_megaphone5";     // @0x14010d8d0
static CStringW s_strIconMoveToHouse = L"export_common_icon_movetohouse";   // @0x14010d900
static CStringW s_strIconOxQuiz = L"export_common_icon_ox_quiz";            // @0x14010d930
static CStringW s_strIconReturn = L"export_common_icon_return";             // @0x14010d960
#ifndef MS2_HOOK_DLL   // s_strIconMegaphone6: the exe's object at 0x143aef3b8, which other units reach as DAT_143aef3b8 (the hook DLL binds it)
CStringW DAT_143aef3b8 = L"export_common_icon_megaphone6";     // @0x14010d990
#else
extern CStringW DAT_143aef3b8;
#endif
static CStringW s_strIconSystem = L"export_common_icon_system";             // @0x14010d9c0
static CStringW s_strIconWhisper = L"export_common_icon_whisper";           // @0x14010d9f0
static CString s_astrEnumName[7] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};   // @0x14010da20
static CString s_strSkill = "skill";                                        // @0x14010dae0
static CString s_strStun = "stun";                                          // @0x14010db10
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);           // @0x14010db40

// The chat colours (the chat colour table of the UI constants, 25 entries of 0x58 bytes from +0xb528; the last is set elsewhere).
// External, with the exe's initial values (white; 25 = the system notice colour): astooltip and uimessenger read them as
// DAT_1439f87a8 + 4n (tools/fullexe/alias-manual.tsv).
ULong s_color0 = 0xffffff, s_color1 = 0xffffff, s_color2 = 0xffffff, s_color3 = 0xffffff, s_color4 = 0xffffff, s_color5 = 0xffffff, s_color6 = 0xffffff, s_color7 = 0xffffff, s_color8 = 0xffffff, s_color9 = 0xffffff, s_color10 = 0xffffff, s_color11 = 0xffffff, s_color12 = 0xffffff, s_color13 = 0xffffff, s_color14 = 0xffffff, s_color15 = 0xffffff, s_color16 = 0xffffff, s_color17 = 0xffffff, s_color18 = 0xffffff, s_color19 = 0xffffff, s_color20 = 0xffffff, s_color21 = 0xffffff, s_color22 = 0xffffff, s_color23 = 0xffffff, s_color24 = 0xffffff, s_color25 = 0xa493fe;

// ---- unit-local views of exe objects and unrecovered callees ----

// The chat message record handed to the converter.
struct Unk_ThMsg
{
    unsigned __int64 m_0;                                       // the sender account id
    unsigned __int64 m_8;                                       // the sender character id
    CStringW m_10;                                              // the sender name
    unsigned __int64 m_18;
    int m_20;                                                   // the chat kind
    int m_24;
    unsigned __int64 m_28;
    int m_30;
    int m_34;                                                   // the flag that switches to the own colour
    unsigned __int64 m_38;
    unsigned __int64 m_40;
    int m_48;
    int m_4c;                                                   // tested by FUN_141842770
    int m_50;                                                   // the item id of a megaphone
    int m_54;
};
MS2_CHECK_SIZE(Unk_ThMsg, 0x58);

// The wedding hall record of a wedding hall invitation line.
struct Unk_ThWedding
{
    unsigned __int64 m_0;
    unsigned m_8;                                               // hall id
    int m_c;                                                    // room id
    unsigned __int64 m_10;                                      // the time
    CStringW m_18;
    CStringW m_20;
};
MS2_CHECK_SIZE(Unk_ThWedding, 0x28);

// A time value (the date text helper).

// The item record handle (the item of a megaphone): the function name at +0x290 and its parameter list at +0x2b0.
class Unk_ThName { public: bool FUN_14034eee0(const wchar_t* psz) const; private: char m_pad[0x20]; };
MS2_CHECK_SIZE(Unk_ThName, 0x20);
class Unk_ThParams
{
public:
    unsigned FUN_1408d2380() const;                             // the count
    CStringW FUN_1408d21c0(int nIdx, CStringW strDefault) const;    // a string parameter
    unsigned FUN_1408d1f60(int nIdx, int nDefault) const;       // an integer parameter
private:
    char m_pad[0x28];
};
struct Unk_ThItemRec
{
    char m_pad[0x290];
    Unk_ThName m_290;
    Unk_ThParams m_2b0;
};
class Unk_ThItemRef
{
public:
    bool FUN_1401b5240(int n) const;
    Unk_ThItemRec* FUN_1401b52a0() const;
    ~Unk_ThItemRef();                                           // 0x1401b50d0 (release)
private:
    void* m_0;
    void* m_8;
};
MS2_CHECK_SIZE(Unk_ThItemRef, 0x10);
Unk_ThItemRef FUN_14053f870(unsigned nItemId);

// The local player (only the name getter, slot 77).
class Unk_ThPc
{
public:
    virtual void Unk_Slot0();
    virtual void Unk_Slot1();
    virtual void Unk_Slot2();
    virtual void Unk_Slot3();
    virtual void Unk_Slot4();
    virtual void Unk_Slot5();
    virtual void Unk_Slot6();
    virtual void Unk_Slot7();
    virtual void Unk_Slot8();
    virtual void Unk_Slot9();
    virtual void Unk_Slot10();
    virtual void Unk_Slot11();
    virtual void Unk_Slot12();
    virtual void Unk_Slot13();
    virtual void Unk_Slot14();
    virtual void Unk_Slot15();
    virtual void Unk_Slot16();
    virtual void Unk_Slot17();
    virtual void Unk_Slot18();
    virtual void Unk_Slot19();
    virtual void Unk_Slot20();
    virtual void Unk_Slot21();
    virtual void Unk_Slot22();
    virtual void Unk_Slot23();
    virtual void Unk_Slot24();
    virtual void Unk_Slot25();
    virtual void Unk_Slot26();
    virtual void Unk_Slot27();
    virtual void Unk_Slot28();
    virtual void Unk_Slot29();
    virtual void Unk_Slot30();
    virtual void Unk_Slot31();
    virtual void Unk_Slot32();
    virtual void Unk_Slot33();
    virtual void Unk_Slot34();
    virtual void Unk_Slot35();
    virtual void Unk_Slot36();
    virtual void Unk_Slot37();
    virtual void Unk_Slot38();
    virtual void Unk_Slot39();
    virtual void Unk_Slot40();
    virtual void Unk_Slot41();
    virtual void Unk_Slot42();
    virtual void Unk_Slot43();
    virtual void Unk_Slot44();
    virtual void Unk_Slot45();
    virtual void Unk_Slot46();
    virtual void Unk_Slot47();
    virtual void Unk_Slot48();
    virtual void Unk_Slot49();
    virtual void Unk_Slot50();
    virtual void Unk_Slot51();
    virtual void Unk_Slot52();
    virtual void Unk_Slot53();
    virtual void Unk_Slot54();
    virtual void Unk_Slot55();
    virtual void Unk_Slot56();
    virtual void Unk_Slot57();
    virtual void Unk_Slot58();
    virtual void Unk_Slot59();
    virtual void Unk_Slot60();
    virtual void Unk_Slot61();
    virtual void Unk_Slot62();
    virtual void Unk_Slot63();
    virtual void Unk_Slot64();
    virtual void Unk_Slot65();
    virtual void Unk_Slot66();
    virtual void Unk_Slot67();
    virtual void Unk_Slot68();
    virtual void Unk_Slot69();
    virtual void Unk_Slot70();
    virtual void Unk_Slot71();
    virtual void Unk_Slot72();
    virtual void Unk_Slot73();
    virtual void Unk_Slot74();
    virtual void Unk_Slot75();
    virtual void Unk_Slot76();
    virtual CStringW vfunc_77();
};
class Unk_ThWorld { public: Unk_ThPc* FUN_141bd0cc0(); };
bool FUN_14025cd60(const CStringW& strA, const CStringW& strB) noexcept;   // equal names (no EH state in the exe callers)

class Unk_ThColorTbl { public: unsigned FUN_1405569f0(int nIdx) const; };
class Unk_ThOptions { public: bool FUN_14036d570(int nOption) const; };
class Unk_140166410* FUN_140166410();   // C3: was FUN_140166410
struct Unk_ThFlags { char m_pad[0x30]; bool m_30; };
struct Unk_NametagFlags* FUN_1406c7610();   // C3: was FUN_1406c7610
class Unk_SingletonObj1* FUN_1401d3200();   // C3: was FUN_1401d3200
unsigned FUN_1412780f0(void* pColor);

// The wedding hall / room records.
class Unk_ThRoomRec { public: unsigned FUN_140906e40(unsigned char b) const; };
class Unk_ThRoomRef
{
public:
    void* FUN_141847320() const { return m_8; }                 // 0x141847320
    Unk_ThRoomRec* FUN_1409020e0() const;
    ~Unk_ThRoomRef();                                           // 0x140901e30 (release)
private:
    void* m_0;
    void* m_8;
};
MS2_CHECK_SIZE(Unk_ThRoomRef, 0x10);
class Unk_ThHallRef
{
public:
    void* FUN_141847330() const { return m_8; }                 // 0x141847330
    class Unk_ThHallBook* FUN_1409020f0() const;
    ~Unk_ThHallRef();                                           // 0x140901e60 (release)
private:
    void* m_0;
    void* m_8;
};
MS2_CHECK_SIZE(Unk_ThHallRef, 0x10);
class Unk_ThHallBook { public: Unk_ThRoomRef FUN_140907110(int nRoom) const; };
class Unk_ThHallMgr { public: Unk_ThHallRef FUN_140908b80(unsigned nHall) const; };
unsigned char FUN_140900f30(unsigned __int64 nTime);
class Unk_ThStrTbl { public: CStringW FUN_141811980(int nType, unsigned nId) const; };
// 0x1406c47a0 is CMsTime(__time64_t) (ms2/placeholder/mstime.h)
CStringW FUN_14083bdc0(const CMsTime& t, bool bSeconds, CStringW strDateSep, CStringW strTimeSep);   // date and time text
class Unk_ThUgc { public: CStringW FUN_140b15150(unsigned __int64 nId) const; };
class Unk_ClubManager* FUN_140e0d900();   // C3: was FUN_140e0d900
void FUN_14025a680(const CStringW& strText, ATL::CAtlArray<CStringW>& arr, const wchar_t* pszSep);

// Unrecovered string formatters whose instances live in other units.
CStringW FUN_1408f71a0(CStringW strKey, const CStringW& a, const CStringW& b);
CStringW FUN_1405c2690(CStringW strKey, const CStringW& a);
CStringW FUN_1401e8510(const wchar_t* pszFormat, const CStringW& a);
CStringW FUN_140292a70(const wchar_t* pszFormat, const unsigned& a);
CStringW FUN_14052bd00(int nId, const CStringW& a);
CStringW FUN_14086d060(int nId, const __int64& n);              // FormatStringId<__int64>
CStringW FUN_1409eaa20(CStringW strKey, const CStringW& a, const CStringW& b, const CStringW& c);
CStringW TranslateEnumDungeonGroup(unsigned nId);               // the dungeon name
unsigned FUN_141275c00(unsigned nRank);
unsigned FUN_141275bd0(unsigned __int64 nId);
unsigned FUN_141275b40();

// The string-table block formatter ("{0}..." of a string id) and its variadic wrappers.
CStringW FUN_14028dee0(int nId, const fmt::ArgList& args);
FMT_VARIADIC_W(CStringW, FUN_14028dee0, int)

// ---- unit functions (forward declarations, definitions in address order) ----
void FUN_14183e690();
CStringW FUN_14183e930(const CStringW& strText, unsigned nColor);
CStringW FUN_14183e9c0(CStringW strText, int nIdx);
void FUN_14183ea40(unsigned nItemId, CStringW& strIcon);
void FUN_14183eba0(unsigned nItemId, CStringW& strIcon, ULong& nSize, ULong& nColor1, ULong& nColor2);
void FUN_14183ee10(unsigned nItemId, CStringW& strIcon, ULong& nSize, ULong& nColor1, ULong& nColor2);
CStringW FUN_14183f080(const CStringW& strText, int bSystem, unsigned nSize);
CStringW FUN_14183f1c0(const CStringW& strText, const CStringW& strIcon, ULong nColor, unsigned nSize);
CStringW FUN_14183f310(const Unk_ThMsg& msg, const CStringW& strText, unsigned nSize);
CStringW FUN_141841180(const Unk_ThMsg& msg, const Unk_ThWedding& wed, const CStringW& strText, unsigned nSize);
CStringW FUN_141841a80(const CStringW& strText, int nSize);
CStringW FUN_141841b40(CItem* pItem, const CStringW& strKind, int nSize);   // strKind unused (uimessenger passes L"inven")
CStringW FUN_141841c60(unsigned nSize, CStringW strName, unsigned __int64 nIdA, unsigned __int64 nIdB, unsigned nRoomId,
                       unsigned nDungeonId, int nP8, int nP9, unsigned nSize2);
CStringW FUN_141841fd0(CStringW strName, unsigned nSize);
CStringW FUN_141842130(__int64 nId);
CStringW FUN_1418421e0(__int64 nId);
void FUN_141842290(CStringW& str);
CStringW FUN_141842320(const CStringW& strText);
CStringW FUN_1418423c0(unsigned nSize, CStringW& strText);
CStringW FUN_141842560(const CStringW& strText, unsigned nColor, unsigned nColorCmp);
ULong FUN_141842680(int nOwnFlag, int nIsMe, ULong nColor);
int FUN_1418426b0(const CStringW& strName);
int FUN_141842770(const Unk_ThMsg& msg);
void FUN_1418473a0(CStringW& str);
bool FUN_1418473c0(CStringW& str);

// @0x14183e640
TextToHtml::TextToHtml()
{
    FUN_14183e690();
}

// @0x14183e690
void FUN_14183e690()
{
    char* pBase = ((char*)FUN_1401d3200());
    if (pBase != 0)
    {
        s_color0 = FUN_1412780f0(pBase + 0xb528);
        s_color1 = FUN_1412780f0(pBase + 0xb580);
        s_color2 = FUN_1412780f0(pBase + 0xb5d8);
        s_color3 = FUN_1412780f0(pBase + 0xb630);
        s_color4 = FUN_1412780f0(pBase + 0xb688);
        s_color5 = FUN_1412780f0(pBase + 0xb6e0);
        s_color6 = FUN_1412780f0(pBase + 0xb738);
        s_color7 = FUN_1412780f0(pBase + 0xb790);
        s_color8 = FUN_1412780f0(pBase + 0xb7e8);
        s_color9 = FUN_1412780f0(pBase + 0xb840);
        s_color10 = FUN_1412780f0(pBase + 0xb898);
        s_color11 = FUN_1412780f0(pBase + 0xb8f0);
        s_color12 = FUN_1412780f0(pBase + 0xb948);
        s_color13 = FUN_1412780f0(pBase + 0xb9a0);
        s_color14 = FUN_1412780f0(pBase + 0xb9f8);
        s_color15 = FUN_1412780f0(pBase + 0xba50);
        s_color16 = FUN_1412780f0(pBase + 0xbaa8);
        s_color17 = FUN_1412780f0(pBase + 0xbb00);
        s_color18 = FUN_1412780f0(pBase + 0xbb58);
        s_color19 = FUN_1412780f0(pBase + 0xbbb0);
        s_color20 = FUN_1412780f0(pBase + 0xbc08);
        s_color21 = FUN_1412780f0(pBase + 0xbc60);
        s_color22 = FUN_1412780f0(pBase + 0xbcb8);
        s_color23 = FUN_1412780f0(pBase + 0xbd10);
        s_color24 = FUN_1412780f0(pBase + 0xbd68);
    }
}

// @0x14183e930
CStringW FUN_14183e930(const CStringW& strText, unsigned nColor)
{
    CStringW str;
    str.Format(L"<FONT color='#%x'>%s</FONT>", nColor, (LPCWSTR)strText);
    return str;
}

// @0x14183e9c0
CStringW FUN_14183e9c0(CStringW strText, int nIdx)
{
    unsigned nColor = reinterpret_cast<Unk_ThColorTbl*>(TSingleton<CItemDataTable>::GetInstance())->FUN_1405569f0(nIdx);
    return FUN_14183e930(strText, nColor);
}

// @0x14183ea40
void FUN_14183ea40(unsigned nItemId, CStringW& strIcon)
{
    strIcon = DAT_143aef3b8;
    Unk_ThItemRef ref = FUN_14053f870(nItemId);
    if (ref.FUN_1401b5240(0))
        return;
    if (ref.FUN_1401b52a0()->m_290.FUN_14034eee0(L"SuperWorldChat"))
        return;
    if (ref.FUN_1401b52a0()->m_2b0.FUN_1408d2380() > 0)
    {
        CStringW strName = ref.FUN_1401b52a0()->m_2b0.FUN_1408d21c0(0, CStringW(L""));
        if (!strName.IsEmpty())
            strIcon.Format(L"export_super_icon%s", (LPCWSTR)strName);
    }
}

// @0x14183eba0
void FUN_14183eba0(unsigned nItemId, CStringW& strIcon, ULong& nSize, ULong& nColor1, ULong& nColor2)
{
    nSize = 1;
    strIcon = DAT_143aef3b8;
    Unk_ThItemRef ref = FUN_14053f870(nItemId);
    if (ref.FUN_1401b5240(0))
        return;
    if (ref.FUN_1401b52a0()->m_290.FUN_14034eee0(L"SuperWorldChat"))
        return;
    if (ref.FUN_1401b52a0()->m_2b0.FUN_1408d2380() > 1)
    {
        CStringW strName = ref.FUN_1401b52a0()->m_2b0.FUN_1408d21c0(0, L"");
        if (!strName.IsEmpty())
            strIcon.Format(L"export_super_icon%s", (LPCWSTR)strName);
        nSize = ref.FUN_1401b52a0()->m_2b0.FUN_1408d1f60(1, 0);
    }
    if (ref.FUN_1401b52a0()->m_2b0.FUN_1408d2380() > 2)
    {
        const CStringW& strColor = ref.FUN_1401b52a0()->m_2b0.FUN_1408d21c0(2, L"");
        nColor2 = (int)_wcstoi64((LPCWSTR)strColor, NULL, 16);
        nColor1 = nColor2;
    }
}

// @0x14183ee10
void FUN_14183ee10(unsigned nItemId, CStringW& strIcon, ULong& nSize, ULong& nColor1, ULong& nColor2)
{
    nSize = 1;
    strIcon = DAT_143aef3b8;
    Unk_ThItemRef ref = FUN_14053f870(nItemId);
    if (ref.FUN_1401b5240(0))
        return;
    if (ref.FUN_1401b52a0()->m_290.FUN_14034eee0(L"WeddingChat"))
        return;
    if (ref.FUN_1401b52a0()->m_2b0.FUN_1408d2380() > 1)
    {
        CStringW strName = ref.FUN_1401b52a0()->m_2b0.FUN_1408d21c0(0, L"");
        if (!strName.IsEmpty())
            strIcon.Format(L"export_super_icon%s", (LPCWSTR)strName);
        nSize = ref.FUN_1401b52a0()->m_2b0.FUN_1408d1f60(1, 0);
    }
    if (ref.FUN_1401b52a0()->m_2b0.FUN_1408d2380() > 2)
    {
        const CStringW& strColor = ref.FUN_1401b52a0()->m_2b0.FUN_1408d21c0(2, L"");
        nColor2 = (int)_wcstoi64((LPCWSTR)strColor, NULL, 16);
        nColor1 = nColor2;
    }
}

// @0x14183f080
CStringW FUN_14183f080(const CStringW& strText, int bSystem, unsigned nSize)
{
    return FUN_14183f1c0(strText, bSystem ? CStringW(s_strIconSystem) : CStringW(L""), s_color21, nSize);
}

// @0x14183f1c0
CStringW FUN_14183f1c0(const CStringW& strText, const CStringW& strIcon, ULong nColor, unsigned nSize)
{
    CStringW strResult;
    if (strIcon.IsEmpty())
        strResult = FUN_14028dee0(0x676, nColor, nSize, strText);
    else
        strResult = FUN_14028dee0(0x677, strIcon, nColor, nSize, strText);
    return strResult;
}

// The body of a chat line by kind.
// @0x14183f310
CStringW FUN_14183f310(const Unk_ThMsg& msg, const CStringW& strText, unsigned nSize)
{
    CStringW strResult;
    CStringW strName(msg.m_10);
    CStringW strText2(strText);
    int nKind = msg.m_20;
    int nOwnFlag = msg.m_34;
    int nSex = msg.m_30;
    unsigned __int64 nIdA = msg.m_0;
    unsigned __int64 nIdB = msg.m_8;
    unsigned __int64 nExtra = msg.m_40;
    unsigned nItemId = msg.m_50;
    CStringW strUser;
    strUser.Format(L"'event:userSelect,%s,%I64u,%I64u'", (LPCWSTR)strName, nIdA, nIdB);
    CStringW strHome;
    strHome.Format(L"'event:moveToHome,%s,%I64u,%I64u'", (LPCWSTR)strName, nIdA, nIdB);
    int bMe = FUN_1418426b0(strName);
    CStringW strImg;
    if (FUN_141842770(msg))
        strImg = FUN_1405c2690(CStringW(L"s_html_chat_img"), s_strIconReturn);
    if (nKind == 0x10)
    {
        ULong nColorA = FUN_141842680(nOwnFlag, bMe, s_color6);
        ULong nColorB = FUN_141842680(nOwnFlag, bMe, s_color18);
        ULong nIconSize = 1;
        CStringW strIcon(DAT_143aef3b8);
        FUN_14183eba0(nItemId, strIcon, nIconSize, nColorA, nColorB);
        strResult = FUN_14028dee0(0x67c, nIconSize);
        if (((class Unk_ThOptions*)FUN_140166410())->FUN_14036d570(0xde))
            strResult = FUN_14028dee0(0x66e, strResult, DAT_143aef3b8, strIcon, strUser, nColorA, nSize, strName, strImg,
                                      strHome, s_strIconMoveToHouse, nColorB, nSize, strText2);
        else
            strResult = FUN_14028dee0(0x66e, strResult, DAT_143aef3b8, strIcon, strUser, nColorA, nSize, strName, nSex,
                                      strImg, strHome, s_strIconMoveToHouse, nColorB, nSize, strText2);
        strResult = FUN_141842560(strResult, nColorB, 0xfffffe);
    }
    else if (nKind == 0xb)
    {
        ULong nColorA = FUN_141842680(nOwnFlag, bMe, s_color7);
        ULong nColorB = FUN_141842680(nOwnFlag, bMe, s_color19);
        if (((class Unk_ThOptions*)FUN_140166410())->FUN_14036d570(0xde))
            strResult = FUN_14028dee0(0x66f, s_strIconMegaphone3, strUser, nColorA, nSize, strName, strImg, strHome,
                                      s_strIconMoveToHouse, nColorB, nSize, strText2);
        else
            strResult = FUN_14028dee0(0x66f, s_strIconMegaphone3, strUser, nColorA, nSize, strName, nSex, strImg, strHome,
                                      s_strIconMoveToHouse, nColorB, nSize, strText2);
        strResult = FUN_141842560(strResult, nColorB, 0xfffffe);
    }
    else if (nKind == 0xc)
    {
        ULong nColorA = FUN_141842680(nOwnFlag, bMe, s_color8);
        ULong nColorB = FUN_141842680(nOwnFlag, bMe, s_color20);
        strResult = FUN_14028dee0(0x670, s_strIconMegaphone2, strUser, nColorA, nSize, strName, strImg, strHome,
                                  s_strIconMoveToHouse, nColorB, nSize, strText2);
        strResult = FUN_141842560(strResult, nColorB, 0xfffffe);
    }
    else if (nKind == 0)
    {
        ULong nColorA = FUN_141842680(nOwnFlag, bMe, s_color0);
        ULong nColorB = FUN_141842680(nOwnFlag, bMe, s_color10);
        strResult = FUN_14028dee0(0x671, strUser, nColorA, nSize, strName, strImg, nColorB, nSize, strText2);
        strResult = FUN_141842560(strResult, nColorB, 0xfffffe);
    }
    else if (nKind == 7)
    {
        ULong nColorA = FUN_141842680(nOwnFlag, bMe, s_color4);
        ULong nColorB = FUN_141842680(nOwnFlag, bMe, s_color16);
        if (((class Unk_ThOptions*)FUN_140166410())->FUN_14036d570(0xde))
            strResult = FUN_14028dee0(0x672, strUser, nColorA, nSize, strName, strImg, nColorB, nSize, strText2);
        else
            strResult = FUN_14028dee0(0x671, strUser, nColorA, nSize, strName, strImg, nColorB, nSize, strText2);
        strResult = FUN_141842560(strResult, nColorB, 0xfffffe);
    }
    else if (nKind == 0x12)
    {
        ULong nColorA = FUN_141842680(nOwnFlag, bMe, s_color5);
        ULong nColorB = FUN_141842680(nOwnFlag, bMe, s_color17);
        strResult = FUN_14028dee0(0x67d, s_strIconMegaphone5, strUser, nColorA, nSize, strName, strImg, nColorB, nSize,
                                  strText2);
        strResult = FUN_141842560(strResult, nColorB, 0xfffffe);
    }
    else if (nKind == 8)
    {
        ULong nColorA = FUN_141842680(nOwnFlag, bMe, s_color5);
        ULong nColorB = FUN_141842680(nOwnFlag, bMe, s_color17);
        if (((class Unk_ThOptions*)FUN_140166410())->FUN_14036d570(0xde))
            strResult = FUN_14028dee0(0x673, strUser, nColorA, nSize, strName, strImg, nColorB, nSize, strText2);
        else
            strResult = FUN_14028dee0(0x671, strUser, nColorA, nSize, strName, strImg, nColorB, nSize, strText2);
        strResult = FUN_141842560(strResult, nColorB, 0xfffffe);
    }
    else if (nKind == 1)
    {
        ULong nColorA = FUN_141842680(nOwnFlag, bMe, s_color3);
        ULong nColorB = FUN_141842680(nOwnFlag, bMe, s_color12);
        strResult = FUN_14028dee0(0x670, s_strIconMegaphone2, strUser, nColorA, nSize, strName, strImg, nColorB, nSize,
                                  strText2);
        strResult = FUN_141842560(strResult, nColorB, 0xfffffe);
    }
    else if (nKind == 2)
    {
        ULong nColorA = FUN_141842680(nOwnFlag, bMe, s_color3);
        ULong nColorB = FUN_141842680(nOwnFlag, bMe, s_color12);
        strResult = FUN_14028dee0(0x670, s_strIconMegaphone2, strUser, nColorA, nSize, strName, strImg, nColorB, nSize,
                                  strText2);
        strResult = FUN_141842560(strResult, nColorB, 0xfffffe);
    }
    else if (nKind == 4)
    {
        ULong nColorA = FUN_141842680(nOwnFlag, bMe, s_color2);
        ULong nColorB = FUN_141842680(nOwnFlag, bMe, s_color13);
        strResult = FUN_14028dee0(0x674, s_strIconWhisper, strUser, nColorA, nSize, strName, strImg, nColorB, nSize,
                                  strText2);
        strResult = FUN_141842560(strResult, nColorB, 0xfffffe);
    }
    else if (nKind == 3)
    {
        ULong nColorA = FUN_141842680(nOwnFlag, bMe, s_color2);
        ULong nColorB = FUN_141842680(nOwnFlag, bMe, s_color15);
        strResult = FUN_14028dee0(0x675, s_strIconWhisper, strUser, nColorA, nSize, strName, strImg, nColorB, nSize,
                                  strText2);
        strResult = FUN_141842560(strResult, nColorB, 0xfffffe);
    }
    else if (nKind == 6)
    {
        strResult = FUN_14028dee0(0x676, s_color14, nSize, strText2);
    }
    else if (nKind == 5)
    {
        strResult = FUN_14028dee0(0x676, s_color14, nSize, strText2);
    }
    else if (nKind == 9)
    {
        strResult = FUN_14028dee0(0x677, s_strIconSystem, s_color21, nSize, strText2);
    }
    else if (nKind == 0xf)
    {
        strResult = FUN_14028dee0(0x679, s_color21, nSize, strText2);
    }
    else if (nKind == 0x13)
    {
        ULong nColorA = FUN_141842680(nOwnFlag, bMe, s_color5);
        ULong nColorB = FUN_141842680(nOwnFlag, bMe, s_color17);
        if (((class Unk_ThOptions*)FUN_140166410())->FUN_14036d570(0xde))
            strResult = FUN_14028dee0(0x67e, strUser, nColorA, nSize, strName, strImg, nColorB, nSize, strText2);
        else
            strResult = FUN_14028dee0(0x671, strUser, nColorA, nSize, strName, strImg, nColorB, nSize, strText2);
    }
    else if (nKind == 0x14)
    {
        ULong nColorA = FUN_141842680(nOwnFlag, bMe, s_color9);
        ULong nColorB = FUN_141842680(nOwnFlag, bMe, s_color24);
        CStringW strUgcName = ((class Unk_ThUgc*)FUN_140e0d900())->FUN_140b15150(nExtra);
        strResult = FUN_14028dee0(0x67a, strUser, nColorA, nSize, strUgcName, strName, strImg, nColorB, nSize, strText2);
        strResult = FUN_141842560(strResult, nColorB, 0xfffffe);
    }
    else if (nKind == 0x16)
    {
        ATL::CAtlArray<CStringW> arrParam;
        FUN_14025a680(strText2, arrParam, L",");
        CStringW strJoin;
        strJoin.Format(L"'event:joinUGCEvent,%s,%I64u,%I64u,%s,%s,%s'", (LPCWSTR)strName, nIdA, nIdB,
                       (LPCWSTR)arrParam[3], (LPCWSTR)arrParam[4], (LPCWSTR)arrParam[5]);
        strResult = FUN_14028dee0(0x67b, strUser, strName, strJoin, s_strIconOxQuiz, arrParam[0]);
    }
    return FUN_1418423c0(nSize, strResult);
}

// The wedding hall invitation line.
// @0x141841180
CStringW FUN_141841180(const Unk_ThMsg& msg, const Unk_ThWedding& wed, const CStringW& strText, unsigned nSize)
{
    CStringW strName(msg.m_10);
    CStringW strText2(strText);
    int nOwnFlag = msg.m_34;
    unsigned __int64 nIdA = msg.m_0;
    unsigned __int64 nIdB = msg.m_8;
    unsigned nItemId = msg.m_50;
    CStringW strUser;
    strUser.Format(L"'event:userSelect,%s,%I64u,%I64u'", (LPCWSTR)strName, nIdA, nIdB);
    CStringW strHome;
    strHome.Format(L"'event:moveToHome,%s,%I64u,%I64u'", (LPCWSTR)strName, nIdA, nIdB);
    CStringW strHall;
    strHall.Format(L"'event:moveToWeddingHall,%I64u,%d,%d,%s,%s'", wed.m_0, wed.m_8, wed.m_c, (LPCWSTR)wed.m_18,
                   (LPCWSTR)wed.m_20);
    int bMe = FUN_1418426b0(strName);
    CStringW strImg;
    if (FUN_141842770(msg))
        strImg = FUN_1405c2690(CStringW(L"s_html_chat_img"), s_strIconReturn);
    ULong nColorA = FUN_141842680(nOwnFlag, bMe, s_color6);
    ULong nColorB = FUN_141842680(nOwnFlag, bMe, s_color18);
    ULong nIconSize = 1;
    CStringW strIcon(DAT_143aef3b8);
    FUN_14183ee10(nItemId, strIcon, nIconSize, nColorA, nColorB);
    CStringW strBody = FUN_14028dee0(0x67c, nIconSize);
    strBody = FUN_14028dee0(0x66e, strBody, DAT_143aef3b8, strIcon, strUser, nColorA, nSize, strName, strImg, strHome,
                            s_strIconMoveToHouse, nColorB, nSize, strText2);
    strBody = FUN_141842560(strBody, nColorB, 0xfffffe);
    CStringW strDate;
    Unk_ThHallRef hall = reinterpret_cast<Unk_ThHallMgr*>(TSingleton<WeddingTable>::GetInstance())->FUN_140908b80(wed.m_8);
    if (hall.FUN_141847330() != 0)
    {
        Unk_ThRoomRef room = hall.FUN_1409020f0()->FUN_140907110(wed.m_c);
        if (room.FUN_141847320() != 0)
        {
            strDate = reinterpret_cast<Unk_ThStrTbl*>(TSingleton<CStringTable>::GetInstance())->FUN_141811980(3, room.FUN_1409020e0()->FUN_140906e40(FUN_140900f30(wed.m_10)));
        }
    }
    CStringW strBody2 = FUN_14028dee0(0x680, nIconSize);
    strBody2 = FUN_14028dee0(0x67f, strBody2, strIcon, strHall, nColorA, nSize, wed.m_18, wed.m_20, nColorB, nSize,
                             FUN_14083bdc0(CMsTime(wed.m_10), true, CStringW(L"/"), CStringW(L":")), strDate);
    strBody2 = FUN_141842560(strBody2, nColorB, 0xfffffe);
    strBody.Append(strBody2);
    return FUN_1418423c0(nSize, strBody);
}

// @0x141841a80
CStringW FUN_141841a80(const CStringW& strText, int nSize)
{
    CStringW strResult;
    int nColor = 0xffbfff;
    strResult = FUN_14028dee0(0x690, strText, nColor, nSize);
    return strResult;
}

// @0x141841b40
CStringW FUN_141841b40(CItem* pItem, const CStringW& strKind, int nSize)
{
    CStringW strQuote(L"''");
    CStringW strName = FUN_14052bd00(0x626, pItem->FUN_140527b10());
    ULong nColor = FUN_141275c00(pItem->FUN_140526bd0());
    CStringW strResult = FUN_14028dee0(0x678, strQuote, nColor, nSize, strName);
    return strResult;
}

// @0x141841c60
CStringW FUN_141841c60(unsigned nSize, CStringW strName, unsigned __int64 nIdA, unsigned __int64 nIdB, unsigned nRoomId,
                       unsigned nDungeonId, int nP8, int nP9, unsigned nSize2)
{
    CStringW strUser = StringFormat(L"'event:userSelect,{0},{1},{2}'", strName, nIdA, nIdB);
    CStringW strHelper = FUN_1408f71a0(CStringW(L"s_html_chat_user_dungeon_helper"), strUser, strName);
    CStringW strJoinLink = StringFormat(L"'event:joinPartyDungeonHelper,{0},{1},{2}'", nSize, strName, nRoomId);
    CStringW strJoin = FUN_1405c2690(CStringW(L"s_html_chat_join_party"), strJoinLink);
    CStringW strRoomLink = FUN_140292a70(L"'event:dungeonRoom,{0}'", nRoomId);
    CStringW strDungeon = FUN_1409eaa20(CStringW(L"s_html_chat_dungeon_name"), strRoomLink, TranslateEnumDungeonGroup(nDungeonId),
                                        reinterpret_cast<Unk_ThStrTbl*>(TSingleton<CStringTable>::GetInstance())->FUN_141811980(0x14, nRoomId));
    CStringW strLine = FUN_14028dfa0(CStringW(L"s_html_chat_find_dungeon_helper"), strHelper, strDungeon, nP8, nP9, strJoin);
    return FUN_14028dfa0(CStringW(L"s_html_chat_system_notice"), s_color25, nSize2, strLine);
}

// @0x141841fd0
CStringW FUN_141841fd0(CStringW strName, unsigned nSize)
{
    CStringW strLink = FUN_1401e8510(L"'event:inviteParty,{0}'", strName);
    CStringW strInvite = FUN_1405c2690(CStringW(L"s_html_chat_invite_party"), strLink);
    CStringW strMessage = FUN_1408f71a0(CStringW(L"s_html_chat_invite_party_message"), strName, strInvite);
    return FUN_14028dfa0(CStringW(L"s_html_chat_system_notice"), s_color16, nSize, strMessage);
}

// @0x141842130
CStringW FUN_141842130(__int64 nId)
{
    CStringW strBody;
    strBody = FUN_14086d060(0x625, nId);
    return FUN_14183e930(strBody, FUN_141275bd0(nId));
}

// @0x1418421e0
CStringW FUN_1418421e0(__int64 nId)
{
    CStringW strBody;
    strBody = FUN_14086d060(0x624, nId);
    return FUN_14183e930(strBody, FUN_141275b40());
}

// @0x141842290
void FUN_141842290(CStringW& str)
{
    int nStart = 0;
    while ((nStart = str.Find(L"<", 0)) != -1)
    {
        int nEnd = str.Find(L">", nStart + 1);
        if (nEnd == -1)
            break;
        str.Delete(nStart, nEnd - nStart + 1);
    }
}

// @0x141842320
CStringW FUN_141842320(const CStringW& strText)
{
    CStringW str(strText);
    str.Replace(L"<", L"&lt;");
    str.Replace(L">", L"&gt;");
    return str;
}

// @0x1418423c0
CStringW FUN_1418423c0(unsigned nSize, CStringW& strText)
{
    CStringW strSizeSq;
    strSizeSq.Format(L"size='%d'", nSize);
    CStringW strSizeDq;
    strSizeDq.Format(L"SIZE=\"%d\"", nSize);
    for (int i = 12; i <= 18; ++i)
    {
        CStringW strOldSq;
        strOldSq.Format(L"size='%d'", i);
        CStringW strOldDq;
        strOldDq.Format(L"SIZE=\"%d\"", i);
        strText.Replace((LPCWSTR)strOldSq, (LPCWSTR)strSizeSq);
        strText.Replace((LPCWSTR)strOldDq, (LPCWSTR)strSizeDq);
    }
    return strText;
}

// @0x141842560
CStringW FUN_141842560(const CStringW& strText, unsigned nColor, unsigned nColorCmp)
{
    CStringW strNew;
    strNew.Format(L"color='#%x'", nColor);
    FUN_1418473a0(strNew);
    CStringW strOld;
    strOld.Format(L"color=\"#%x\"", nColorCmp);
    FUN_1418473a0(strOld);
    CStringW str(strText);
    str.Replace((LPCWSTR)strOld, (LPCWSTR)strNew);
    return str;
}

// The own-colour switch of a line: the colour of the flagged own lines (the player's own name) is the "mine" colour.
// @0x141842680
ULong FUN_141842680(int nOwnFlag, int nIsMe, ULong nColor)
{
    if (nOwnFlag != 0 && nIsMe == 0)
        return s_color23;
    return nColor;
}

// Is the sender the local player.
// @0x1418426b0
int FUN_1418426b0(const CStringW& strName)
{
    Unk_ThPc* pPc = reinterpret_cast<Unk_ThWorld*>(WorldService::GetInstance())->FUN_141bd0cc0();
    bool bMe = pPc != 0 && FUN_14025cd60(pPc->vfunc_77(), strName);
    if (bMe)
        return 1;
    return 0;
}

// Does the line kind carry the chat image.
// @0x141842770
int FUN_141842770(const Unk_ThMsg& msg)
{
    if (!((struct Unk_ThFlags*)FUN_1406c7610())->m_30)
        return 0;
    if (msg.m_4c != 0)
    {
        if (msg.m_20 == 0x10)
            return 1;
        if (msg.m_20 == 0xb)
            return 1;
        if (msg.m_20 == 0xc)
            return 1;
        if (msg.m_20 == 0)
            return 1;
        if (msg.m_20 == 0x19)
            return 1;
        if (msg.m_20 == 7)
            return 1;
        if (msg.m_20 == 8)
            return 1;
        if (msg.m_20 == 0x12)
            return 1;
        if (msg.m_20 == 1)
            return 1;
        if (msg.m_20 == 2)
            return 1;
        if (msg.m_20 == 4)
            return 1;
        if (msg.m_20 == 3)
            return 1;
        if (msg.m_20 == 0x13)
            return 1;
        if (msg.m_20 == 0x14)
            return 1;
    }
    return 0;
}

// 0x141847300 ~TextToHtml is implicit (the exe's dtor has no vptr store).

// @0x1418473a0
void FUN_1418473a0(CStringW& str)
{
    FUN_1418473c0(str);
}

// Uppercases the colour attribute (the attribute names are compared case-insensitively by the HTML).
// @0x1418473c0
bool FUN_1418473c0(CStringW& str)
{
    try
    {
        str.MakeUpper();
    }
    catch (CException* e)
    {
        // ASSERT(FALSE) of commonfiles\stringutil.h (the function body lives in that header)
        (void)((!!(FALSE)) || (_wassert(L"FALSE", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\stringutil.h", 461), 0));
        return false;
    }
    return true;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cbba60-0x142cbbc30 .text$yd
