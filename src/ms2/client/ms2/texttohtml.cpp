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
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/wcformat.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

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
static CStringW s_strIconMegaphone6 = L"export_common_icon_megaphone6";     // @0x14010d990
static CStringW s_strIconSystem = L"export_common_icon_system";             // @0x14010d9c0
static CStringW s_strIconWhisper = L"export_common_icon_whisper";           // @0x14010d9f0
static CString s_astrEnumName[7] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};   // @0x14010da20
static CString s_strSkill = "skill";                                        // @0x14010dae0
static CString s_strStun = "stun";                                          // @0x14010db10
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);           // @0x14010db40

// The chat colours (the chat colour table of the UI constants, 25 entries of 0x58 bytes from +0xb528; the last is set elsewhere).
static ULong s_colors[26];

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
struct Unk_ThTime { char m_pad[0x20]; };

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
    void FUN_1401b50d0();                                       // release
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
Unk_ThWorld* FUN_1403ed2d0();
bool FUN_14025cd60(const CStringW& strA, const CStringW& strB);   // equal names

class Unk_ThColorTbl { public: unsigned FUN_1405569f0(int nIdx) const; };
Unk_ThColorTbl* FUN_140281980();
class Unk_ThOptions { public: bool FUN_14036d570(int nOption) const; };
Unk_ThOptions* FUN_140166410();
struct Unk_ThFlags { char m_pad[0x30]; char m_30; };
Unk_ThFlags* FUN_1406c7610();
char* FUN_1401d3200();                                          // the UI constants
unsigned FUN_1412780f0(void* pColor);

// The wedding hall / room records.
class Unk_ThRoomRec { public: unsigned FUN_140906e40(unsigned char b) const; };
class Unk_ThRoomRef
{
public:
    void* FUN_141847320() const { return m_8; }                 // 0x141847320
    Unk_ThRoomRec* FUN_1409020e0() const;
    void FUN_140901e30();                                       // release
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
    void FUN_140901e60();                                       // release
private:
    void* m_0;
    void* m_8;
};
MS2_CHECK_SIZE(Unk_ThHallRef, 0x10);
class Unk_ThHallBook { public: Unk_ThRoomRef FUN_140907110(int nRoom) const; };
class Unk_ThHallMgr { public: Unk_ThHallRef FUN_140908b80(unsigned nHall) const; };
Unk_ThHallMgr* FUN_1409023c0();
unsigned char FUN_140900f30(unsigned __int64 nTime);
class Unk_ThStrTbl { public: CStringW FUN_141811980(int nType, unsigned nId) const; };
Unk_ThStrTbl* FUN_1401a9d70();
Unk_ThTime FUN_1406c47a0(unsigned __int64 nTime);
CStringW FUN_14083bdc0(const Unk_ThTime& t, int nFlag, CStringW strDateSep, CStringW strTimeSep);
class Unk_ThUgc { public: CStringW FUN_140b15150(unsigned __int64 nId) const; };
Unk_ThUgc* FUN_140e0d900();
void FUN_14025a680(const CStringW& strText, ATL::CAtlArray<CStringW>& arr, const wchar_t* pszSep);

// Unrecovered string formatters whose instances live in other units.
CStringW FUN_1408f71a0(CStringW strKey, const CStringW& a, const CStringW& b);
CStringW FUN_1405c2690(CStringW strKey, const CStringW& a);
CStringW FUN_1401e8510(const wchar_t* pszFormat, const CStringW& a);
CStringW FUN_140292a70(const wchar_t* pszFormat, const unsigned& a);
CStringW FUN_14052bd00(int nId, const CStringW& a);
CStringW FUN_14086d060(int nId, const unsigned __int64& a, const CStringW& b);
CStringW FUN_1409eaa20(CStringW strKey, const CStringW& a, const CStringW& b, const CStringW& c);
CStringW FUN_140cbf840(unsigned nId);                           // the dungeon name
class Unk_ThItem;
CStringW FUN_140527b10(Unk_ThItem* pItem);
unsigned FUN_140526bd0(Unk_ThItem* pItem);
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
CStringW FUN_141841b40(Unk_ThItem* pItem, int nUnused, unsigned nSize);
CStringW FUN_141841c60(unsigned nSize, CStringW strName, unsigned __int64 nIdA, unsigned __int64 nIdB, unsigned nRoomId,
                       unsigned nDungeonId, int nP8, int nP9, unsigned nSize2);
CStringW FUN_141841fd0(CStringW strName, unsigned nSize);
CStringW FUN_141842130(unsigned __int64 nId, unsigned __int64 nUnused, const CStringW& strArg);
CStringW FUN_1418421e0(unsigned __int64 nId, unsigned __int64 nUnused, const CStringW& strArg);
void FUN_141842290(CStringW& str);
CStringW FUN_141842320(const CStringW& strText);
CStringW FUN_1418423c0(unsigned nSize, CStringW& strText);
CStringW FUN_141842560(const CStringW& strText, unsigned nColor, unsigned nColorCmp);
ULong FUN_141842680(int nOwnFlag, int nIsMe, ULong nColor);
bool FUN_1418426b0(const CStringW& strName);
bool FUN_141842770(const Unk_ThMsg& msg);
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
    char* pBase = FUN_1401d3200();
    if (pBase != 0)
    {
        s_colors[0] = FUN_1412780f0(pBase + 0xb528);
        s_colors[1] = FUN_1412780f0(pBase + 0xb580);
        s_colors[2] = FUN_1412780f0(pBase + 0xb5d8);
        s_colors[3] = FUN_1412780f0(pBase + 0xb630);
        s_colors[4] = FUN_1412780f0(pBase + 0xb688);
        s_colors[5] = FUN_1412780f0(pBase + 0xb6e0);
        s_colors[6] = FUN_1412780f0(pBase + 0xb738);
        s_colors[7] = FUN_1412780f0(pBase + 0xb790);
        s_colors[8] = FUN_1412780f0(pBase + 0xb7e8);
        s_colors[9] = FUN_1412780f0(pBase + 0xb840);
        s_colors[10] = FUN_1412780f0(pBase + 0xb898);
        s_colors[11] = FUN_1412780f0(pBase + 0xb8f0);
        s_colors[12] = FUN_1412780f0(pBase + 0xb948);
        s_colors[13] = FUN_1412780f0(pBase + 0xb9a0);
        s_colors[14] = FUN_1412780f0(pBase + 0xb9f8);
        s_colors[15] = FUN_1412780f0(pBase + 0xba50);
        s_colors[16] = FUN_1412780f0(pBase + 0xbaa8);
        s_colors[17] = FUN_1412780f0(pBase + 0xbb00);
        s_colors[18] = FUN_1412780f0(pBase + 0xbb58);
        s_colors[19] = FUN_1412780f0(pBase + 0xbbb0);
        s_colors[20] = FUN_1412780f0(pBase + 0xbc08);
        s_colors[21] = FUN_1412780f0(pBase + 0xbc60);
        s_colors[22] = FUN_1412780f0(pBase + 0xbcb8);
        s_colors[23] = FUN_1412780f0(pBase + 0xbd10);
        s_colors[24] = FUN_1412780f0(pBase + 0xbd68);
    }
}

// @0x14183e930
CStringW FUN_14183e930(const CStringW& strText, unsigned nColor)
{
    CStringW str;
    str.Format(L"<FONT color='#%x'>%s</FONT>", nColor, strText.GetString());
    return str;
}

// @0x14183e9c0
CStringW FUN_14183e9c0(CStringW strText, int nIdx)
{
    return FUN_14183e930(strText, FUN_140281980()->FUN_1405569f0(nIdx));
}

// @0x14183ea40
void FUN_14183ea40(unsigned nItemId, CStringW& strIcon)
{
    strIcon = s_strIconMegaphone6;
    Unk_ThItemRef ref = FUN_14053f870(nItemId);
    if (!ref.FUN_1401b5240(0) && !ref.FUN_1401b52a0()->m_290.FUN_14034eee0(L"SuperWorldChat"))
    {
        if (ref.FUN_1401b52a0()->m_2b0.FUN_1408d2380() != 0)
        {
            CStringW strName = ref.FUN_1401b52a0()->m_2b0.FUN_1408d21c0(0, CStringW(L""));
            if (!strName.IsEmpty())
                strIcon.Format(L"export_super_icon%s", strName.GetString());
        }
    }
    ref.FUN_1401b50d0();
}

// @0x14183eba0
void FUN_14183eba0(unsigned nItemId, CStringW& strIcon, ULong& nSize, ULong& nColor1, ULong& nColor2)
{
    nSize = 1;
    strIcon = s_strIconMegaphone6;
    Unk_ThItemRef ref = FUN_14053f870(nItemId);
    if (!ref.FUN_1401b5240(0) && !ref.FUN_1401b52a0()->m_290.FUN_14034eee0(L"SuperWorldChat"))
    {
        if (ref.FUN_1401b52a0()->m_2b0.FUN_1408d2380() > 1)
        {
            CStringW strName = ref.FUN_1401b52a0()->m_2b0.FUN_1408d21c0(0, CStringW(L""));
            if (!strName.IsEmpty())
                strIcon.Format(L"export_super_icon%s", strName.GetString());
            nSize = ref.FUN_1401b52a0()->m_2b0.FUN_1408d1f60(1, 0);
        }
        if (ref.FUN_1401b52a0()->m_2b0.FUN_1408d2380() > 2)
        {
            CStringW strColor = ref.FUN_1401b52a0()->m_2b0.FUN_1408d21c0(2, CStringW(L""));
            nColor2 = (int)_wcstoi64(strColor.GetString(), NULL, 16);
            nColor1 = nColor2;
        }
    }
    ref.FUN_1401b50d0();
}

// @0x14183ee10
void FUN_14183ee10(unsigned nItemId, CStringW& strIcon, ULong& nSize, ULong& nColor1, ULong& nColor2)
{
    nSize = 1;
    strIcon = s_strIconMegaphone6;
    Unk_ThItemRef ref = FUN_14053f870(nItemId);
    if (!ref.FUN_1401b5240(0) && !ref.FUN_1401b52a0()->m_290.FUN_14034eee0(L"WeddingChat"))
    {
        if (ref.FUN_1401b52a0()->m_2b0.FUN_1408d2380() > 1)
        {
            CStringW strName = ref.FUN_1401b52a0()->m_2b0.FUN_1408d21c0(0, CStringW(L""));
            if (!strName.IsEmpty())
                strIcon.Format(L"export_super_icon%s", strName.GetString());
            nSize = ref.FUN_1401b52a0()->m_2b0.FUN_1408d1f60(1, 0);
        }
        if (ref.FUN_1401b52a0()->m_2b0.FUN_1408d2380() > 2)
        {
            CStringW strColor = ref.FUN_1401b52a0()->m_2b0.FUN_1408d21c0(2, CStringW(L""));
            nColor2 = (int)_wcstoi64(strColor.GetString(), NULL, 16);
            nColor1 = nColor2;
        }
    }
    ref.FUN_1401b50d0();
}

// @0x14183f080
CStringW FUN_14183f080(const CStringW& strText, int bSystem, unsigned nSize)
{
    return FUN_14183f1c0(strText, bSystem ? CStringW(s_strIconSystem) : CStringW(L""), s_colors[21], nSize);
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
    strUser.Format(L"'event:userSelect,%s,%I64u,%I64u'", strName.GetString(), nIdA, nIdB);
    CStringW strHome;
    strHome.Format(L"'event:moveToHome,%s,%I64u,%I64u'", strName.GetString(), nIdA, nIdB);
    int bMe = FUN_1418426b0(strName);
    CStringW strImg;
    if (FUN_141842770(msg))
        strImg = FUN_1405c2690(CStringW(L"s_html_chat_img"), s_strIconReturn);
    if (nKind == 0x10)
    {
        ULong nColorA = FUN_141842680(nOwnFlag, bMe, s_colors[6]);
        ULong nColorB = FUN_141842680(nOwnFlag, bMe, s_colors[18]);
        ULong nIconSize = 1;
        CStringW strIcon(s_strIconMegaphone6);
        FUN_14183eba0(nItemId, strIcon, nIconSize, nColorA, nColorB);
        strResult = FUN_14028dee0(0x67c, nIconSize);
        if (!FUN_140166410()->FUN_14036d570(0xde))
            strResult = FUN_14028dee0(0x66e, strResult, s_strIconMegaphone6, strIcon, strUser, nColorA, nSize, strName, nSex,
                                      strImg, strHome, s_strIconMoveToHouse, nColorB, nSize, strText2);
        else
            strResult = FUN_14028dee0(0x66e, strResult, s_strIconMegaphone6, strIcon, strUser, nColorA, nSize, strName, strImg,
                                      strHome, s_strIconMoveToHouse, nColorB, nSize, strText2);
        strResult = FUN_141842560(strResult, nColorB, 0xfffffe);
    }
    else if (nKind == 0xb)
    {
        ULong nColorA = FUN_141842680(nOwnFlag, bMe, s_colors[7]);
        ULong nColorB = FUN_141842680(nOwnFlag, bMe, s_colors[19]);
        if (!FUN_140166410()->FUN_14036d570(0xde))
            strResult = FUN_14028dee0(0x66f, s_strIconMegaphone3, strUser, nColorA, nSize, strName, nSex, strImg, strHome,
                                      s_strIconMoveToHouse, nColorB, nSize, strText2);
        else
            strResult = FUN_14028dee0(0x66f, s_strIconMegaphone3, strUser, nColorA, nSize, strName, strImg, strHome,
                                      s_strIconMoveToHouse, nColorB, nSize, strText2);
        strResult = FUN_141842560(strResult, nColorB, 0xfffffe);
    }
    else if (nKind == 0xc)
    {
        ULong nColorA = FUN_141842680(nOwnFlag, bMe, s_colors[8]);
        ULong nColorB = FUN_141842680(nOwnFlag, bMe, s_colors[20]);
        strResult = FUN_14028dee0(0x670, s_strIconMegaphone2, strUser, nColorA, nSize, strName, strImg, strHome,
                                  s_strIconMoveToHouse, nColorB, nSize, strText2);
        strResult = FUN_141842560(strResult, nColorB, 0xfffffe);
    }
    else if (nKind == 0)
    {
        ULong nColorA = FUN_141842680(nOwnFlag, bMe, s_colors[0]);
        ULong nColorB = FUN_141842680(nOwnFlag, bMe, s_colors[10]);
        strResult = FUN_14028dee0(0x671, strUser, nColorA, nSize, strName, strImg, nColorB, nSize, strText2);
        strResult = FUN_141842560(strResult, nColorB, 0xfffffe);
    }
    else if (nKind == 7)
    {
        ULong nColorA = FUN_141842680(nOwnFlag, bMe, s_colors[4]);
        ULong nColorB = FUN_141842680(nOwnFlag, bMe, s_colors[16]);
        if (!FUN_140166410()->FUN_14036d570(0xde))
            strResult = FUN_14028dee0(0x671, strUser, nColorA, nSize, strName, strImg, nColorB, nSize, strText2);
        else
            strResult = FUN_14028dee0(0x672, strUser, nColorA, nSize, strName, strImg, nColorB, nSize, strText2);
        strResult = FUN_141842560(strResult, nColorB, 0xfffffe);
    }
    else if (nKind == 0x12)
    {
        ULong nColorA = FUN_141842680(nOwnFlag, bMe, s_colors[5]);
        ULong nColorB = FUN_141842680(nOwnFlag, bMe, s_colors[17]);
        strResult = FUN_14028dee0(0x67d, s_strIconMegaphone5, strUser, nColorA, nSize, strName, strImg, nColorB, nSize,
                                  strText2);
        strResult = FUN_141842560(strResult, nColorB, 0xfffffe);
    }
    else if (nKind == 8)
    {
        ULong nColorA = FUN_141842680(nOwnFlag, bMe, s_colors[5]);
        ULong nColorB = FUN_141842680(nOwnFlag, bMe, s_colors[17]);
        if (!FUN_140166410()->FUN_14036d570(0xde))
            strResult = FUN_14028dee0(0x671, strUser, nColorA, nSize, strName, strImg, nColorB, nSize, strText2);
        else
            strResult = FUN_14028dee0(0x673, strUser, nColorA, nSize, strName, strImg, nColorB, nSize, strText2);
        strResult = FUN_141842560(strResult, nColorB, 0xfffffe);
    }
    else if (nKind == 1)
    {
        ULong nColorA = FUN_141842680(nOwnFlag, bMe, s_colors[3]);
        ULong nColorB = FUN_141842680(nOwnFlag, bMe, s_colors[12]);
        strResult = FUN_14028dee0(0x670, s_strIconMegaphone2, strUser, nColorA, nSize, strName, strImg, nColorB, nSize,
                                  strText2);
        strResult = FUN_141842560(strResult, nColorB, 0xfffffe);
    }
    else if (nKind == 2)
    {
        ULong nColorA = FUN_141842680(nOwnFlag, bMe, s_colors[3]);
        ULong nColorB = FUN_141842680(nOwnFlag, bMe, s_colors[12]);
        strResult = FUN_14028dee0(0x670, s_strIconMegaphone2, strUser, nColorA, nSize, strName, strImg, nColorB, nSize,
                                  strText2);
        strResult = FUN_141842560(strResult, nColorB, 0xfffffe);
    }
    else if (nKind == 4)
    {
        ULong nColorA = FUN_141842680(nOwnFlag, bMe, s_colors[2]);
        ULong nColorB = FUN_141842680(nOwnFlag, bMe, s_colors[13]);
        strResult = FUN_14028dee0(0x674, s_strIconWhisper, strUser, nColorA, nSize, strName, strImg, nColorB, nSize,
                                  strText2);
        strResult = FUN_141842560(strResult, nColorB, 0xfffffe);
    }
    else if (nKind == 3)
    {
        ULong nColorA = FUN_141842680(nOwnFlag, bMe, s_colors[2]);
        ULong nColorB = FUN_141842680(nOwnFlag, bMe, s_colors[15]);
        strResult = FUN_14028dee0(0x675, s_strIconWhisper, strUser, nColorA, nSize, strName, strImg, nColorB, nSize,
                                  strText2);
        strResult = FUN_141842560(strResult, nColorB, 0xfffffe);
    }
    else if (nKind == 6)
    {
        strResult = FUN_14028dee0(0x676, s_colors[14], nSize, strText2);
    }
    else if (nKind == 5)
    {
        strResult = FUN_14028dee0(0x676, s_colors[14], nSize, strText2);
    }
    else if (nKind == 9)
    {
        strResult = FUN_14028dee0(0x677, s_strIconSystem, s_colors[21], nSize, strText2);
    }
    else if (nKind == 0xf)
    {
        strResult = FUN_14028dee0(0x679, s_colors[21], nSize, strText2);
    }
    else if (nKind == 0x13)
    {
        ULong nColorA = FUN_141842680(nOwnFlag, bMe, s_colors[5]);
        ULong nColorB = FUN_141842680(nOwnFlag, bMe, s_colors[17]);
        if (!FUN_140166410()->FUN_14036d570(0xde))
            strResult = FUN_14028dee0(0x671, strUser, nColorA, nSize, strName, strImg, nColorB, nSize, strText2);
        else
            strResult = FUN_14028dee0(0x67e, strUser, nColorA, nSize, strName, strImg, nColorB, nSize, strText2);
    }
    else if (nKind == 0x14)
    {
        ULong nColorA = FUN_141842680(nOwnFlag, bMe, s_colors[9]);
        ULong nColorB = FUN_141842680(nOwnFlag, bMe, s_colors[24]);
        CStringW strUgcName = FUN_140e0d900()->FUN_140b15150(nExtra);
        strResult = FUN_14028dee0(0x67a, strUser, nColorA, nSize, strUgcName, strName, strImg, nColorB, nSize, strText2);
        strResult = FUN_141842560(strResult, nColorB, 0xfffffe);
    }
    else if (nKind == 0x16)
    {
        ATL::CAtlArray<CStringW> arrParam;
        FUN_14025a680(strText2, arrParam, L",");
        CStringW strJoin;
        strJoin.Format(L"'event:joinUGCEvent,%s,%I64u,%I64u,%s,%s,%s'", strName.GetString(), nIdA, nIdB,
                       arrParam[3].GetString(), arrParam[4].GetString(), arrParam[5].GetString());
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
    strUser.Format(L"'event:userSelect,%s,%I64u,%I64u'", strName.GetString(), nIdA, nIdB);
    CStringW strHome;
    strHome.Format(L"'event:moveToHome,%s,%I64u,%I64u'", strName.GetString(), nIdA, nIdB);
    CStringW strHall;
    strHall.Format(L"'event:moveToWeddingHall,%I64u,%d,%d,%s,%s'", wed.m_0, wed.m_8, wed.m_c, wed.m_18.GetString(),
                   wed.m_20.GetString());
    int bMe = FUN_1418426b0(strName);
    CStringW strImg;
    if (FUN_141842770(msg))
        strImg = FUN_1405c2690(CStringW(L"s_html_chat_img"), s_strIconReturn);
    ULong nColorA = FUN_141842680(nOwnFlag, bMe, s_colors[6]);
    ULong nColorB = FUN_141842680(nOwnFlag, bMe, s_colors[18]);
    ULong nIconSize = 1;
    CStringW strIcon(s_strIconMegaphone6);
    FUN_14183ee10(nItemId, strIcon, nIconSize, nColorA, nColorB);
    CStringW strBody = FUN_14028dee0(0x67c, nIconSize);
    strBody = FUN_14028dee0(0x66e, strBody, s_strIconMegaphone6, strIcon, strUser, nColorA, nSize, strName, strImg, strHome,
                            s_strIconMoveToHouse, nColorB, nSize, strText2);
    strBody = FUN_141842560(strBody, nColorB, 0xfffffe);
    CStringW strDate;
    Unk_ThHallRef hall = FUN_1409023c0()->FUN_140908b80(wed.m_8);
    if (hall.FUN_141847330() != 0)
    {
        Unk_ThRoomRef room = hall.FUN_1409020f0()->FUN_140907110(wed.m_c);
        if (room.FUN_141847320() != 0)
        {
            unsigned char b = FUN_140900f30(wed.m_10);
            unsigned nValue = room.FUN_1409020e0()->FUN_140906e40(b);
            strDate = FUN_1401a9d70()->FUN_141811980(3, nValue);
        }
        room.FUN_140901e30();
    }
    CStringW strBody2 = FUN_14028dee0(0x680, nIconSize);
    strBody2 = FUN_14028dee0(0x67f, strBody2, strIcon, strHall, nColorA, nSize, wed.m_18, wed.m_20, nColorB, nSize,
                             FUN_14083bdc0(FUN_1406c47a0(wed.m_10), 1, CStringW(L"/"), CStringW(L":")), strDate);
    strBody2 = FUN_141842560(strBody2, nColorB, 0xfffffe);
    strBody.Append(strBody2);
    CStringW strRet = FUN_1418423c0(nSize, strBody);
    hall.FUN_140901e60();
    return strRet;
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
CStringW FUN_141841b40(Unk_ThItem* pItem, int nUnused, unsigned nSize)
{
    CStringW strQuote(L"''");
    CStringW strName = FUN_14052bd00(0x626, FUN_140527b10(pItem));
    ULong nColor = FUN_141275c00(FUN_140526bd0(pItem));
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
    CStringW strDungeon = FUN_1409eaa20(CStringW(L"s_html_chat_dungeon_name"), strRoomLink, FUN_140cbf840(nDungeonId),
                                        FUN_1401a9d70()->FUN_141811980(0x14, nRoomId));
    CStringW strLine = FUN_14028dfa0(CStringW(L"s_html_chat_find_dungeon_helper"), strHelper, strDungeon, nP8, nP9, strJoin);
    return FUN_14028dfa0(CStringW(L"s_html_chat_system_notice"), s_colors[25], nSize2, strLine);
}

// @0x141841fd0
CStringW FUN_141841fd0(CStringW strName, unsigned nSize)
{
    CStringW strLink = FUN_1401e8510(L"'event:inviteParty,{0}'", strName);
    CStringW strInvite = FUN_1405c2690(CStringW(L"s_html_chat_invite_party"), strLink);
    CStringW strMessage = FUN_1408f71a0(CStringW(L"s_html_chat_invite_party_message"), strName, strInvite);
    return FUN_14028dfa0(CStringW(L"s_html_chat_system_notice"), s_colors[16], nSize, strMessage);
}

// @0x141842130
CStringW FUN_141842130(unsigned __int64 nId, unsigned __int64 nUnused, const CStringW& strArg)
{
    CStringW strBody;
    strBody = FUN_14086d060(0x625, nId, strArg);
    return FUN_14183e930(strBody, FUN_141275bd0(nId));
}

// @0x1418421e0
CStringW FUN_1418421e0(unsigned __int64 nId, unsigned __int64 nUnused, const CStringW& strArg)
{
    CStringW strBody;
    strBody = FUN_14086d060(0x624, nId, strArg);
    return FUN_14183e930(strBody, FUN_141275b40());
}

// @0x141842290
void FUN_141842290(CStringW& str)
{
    int nStart;
    int nEnd;
    while ((nStart = str.Find(L"<", 0)) != -1 && (nEnd = str.Find(L">", nStart + 1)) != -1)
        str.Delete(nStart, nEnd - nStart + 1);
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
    for (int i = 12; i < 19; ++i)
    {
        CStringW strOldSq;
        strOldSq.Format(L"size='%d'", i);
        CStringW strOldDq;
        strOldDq.Format(L"SIZE=\"%d\"", i);
        strText.Replace(strOldSq.GetString(), strSizeSq.GetString());
        strText.Replace(strOldDq.GetString(), strSizeDq.GetString());
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
    str.Replace(strOld.GetString(), strNew.GetString());
    return str;
}

// The own-colour switch of a line: the colour of the flagged own lines (the player's own name) is the "mine" colour.
// @0x141842680
ULong FUN_141842680(int nOwnFlag, int nIsMe, ULong nColor)
{
    if (nOwnFlag != 0 && nIsMe == 0)
        nColor = s_colors[23];
    return nColor;
}

// Is the sender the local player.
// @0x1418426b0
bool FUN_1418426b0(const CStringW& strName)
{
    bool bHasName = false;
    Unk_ThPc* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc != 0)
    {
        CStringW strMyName = pPc->vfunc_77();
        bHasName = true;
        if (FUN_14025cd60(strMyName, strName))
            return true;
    }
    return false;
}

// Does the line kind carry the chat image.
// @0x141842770
bool FUN_141842770(const Unk_ThMsg& msg)
{
    if (FUN_1406c7610()->m_30 == 0)
        return false;
    if (msg.m_4c != 0)
    {
        if (msg.m_20 == 0x10 || msg.m_20 == 0xb || msg.m_20 == 0xc || msg.m_20 == 0 || msg.m_20 == 0x19 || msg.m_20 == 7 ||
            msg.m_20 == 8 || msg.m_20 == 0x12 || msg.m_20 == 1 || msg.m_20 == 2 || msg.m_20 == 4 || msg.m_20 == 3 ||
            msg.m_20 == 0x13 || msg.m_20 == 0x14)
            return true;
    }
    return false;
}

// @0x141847300
TextToHtml::~TextToHtml()
{
}

// @0x1418473a0
void FUN_1418473a0(CStringW& str)
{
    FUN_1418473c0(str);
}

// Uppercases the colour attribute (the attribute names are compared case-insensitively by the HTML).
// @0x1418473c0
bool FUN_1418473c0(CStringW& str)
{
    str.MakeUpper();
    return true;
}
