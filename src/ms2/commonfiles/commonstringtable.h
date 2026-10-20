// commonstringtable.h - CBanTextChecker (the chat / name text filter: banned, reserved and prefix word tries loaded from
// Table/banWord.xml & co, length / charset rules, error string ids) and its helpers. Header name and member names are
// assumed; types are the RTTI names. Recovered from the KMS2_DEV x64 exe (0x140223c60-0x140266860 .text$mn).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/tptreddummy.h"
#include "ms2/placeholder/socketptr.h"
#include <map>
#include <set>

// One node of a character trie (0x78 bytes): the children by lower-cased character, the character itself, the depth
// (number of characters from the root) and, when a word ends here, its replacement text.
class TextFilterUnit : public CPtred
{
public:
    TextFilterUnit();                                       // 0x140223c60
    TextFilterUnit(wchar_t ch, int nDepth);                 // 0x140223d10
    // virtual ~TextFilterUnit() is implicit (0x14025caa0)

    wchar_t GetChar() const;                                // 0x140223dc0
    void Insert(const CStringW& str, int nIndex, CStringW replacement);                         // 0x140223de0
    bool Find(const CStringW& str, int nStart, bool bSkipTags, int* pnPos, int* pnLen, CStringW* pReplacement);   // 0x140223fe0
    void Clear();                                           // 0x140224170
    int GetChildCount() const;                              // 0x1402241a0
    bool Match(const CStringW& str, int nIndex, int* pnLen, CStringW* pReplacement);            // 0x1402241d0
    bool IsTagStart(wchar_t ch);                     // 0x140224340
    void SkipTag(const CStringW& str, int* pnIndex); // 0x140224380

    ATL::CAtlMap<wchar_t, MS2Ptr<TextFilterUnit> > m_children;      // +0x18 keyed by the lower-cased character
    wchar_t m_ch;                                           // +0x60
    int m_nDepth;                                           // +0x64
    int m_bWordEnd;                                         // +0x68
    CStringW m_replacement;                                 // +0x70
};
MS2_CHECK_SIZE(TextFilterUnit, 0x78);
MS2_CHECK_OFFSET(TextFilterUnit, m_children, 0x18);
MS2_CHECK_OFFSET(TextFilterUnit, m_replacement, 0x70);

// The word list of one key: the box the ban word map's pointer owns (a CPtred base, the array at +0x18).
typedef ATL::CAtlArray<CStringW> Unk_BanWordList;
template<> struct Unk_SocketRef<Unk_BanWordList> {
    static CPtred* Base(Unk_BanWordList* p) {
        CPtred* result;
        if (p == NULL) result = NULL;
        else result = CONTAINING_RECORD(p, TPtredDummy<Unk_BanWordList>, value);
        return result;
    }
    static TPtredDummy<Unk_BanWordList>* New(void*) { return new TPtredDummy<Unk_BanWordList>(); }
    static Unk_BanWordList* Value(CPtred* p) {
        Unk_BanWordList* result;
        if (p == NULL) result = NULL;
        else result = &static_cast<TPtredDummy<Unk_BanWordList>*>(p)->value;
        return result;
    }
    static Unk_BanWordList* Create(void*) { return Value(FUN_1401ba820(New(NULL))); }
};
MS2_SOCKETPTR_BOXED(Unk_BanWordList)
MS2_CHECK_SIZE(TPtredDummy<Unk_BanWordList>, 0x38);
typedef Unk_SocketPtr<Unk_BanWordList> Unk_BanWordPtr;

enum EBanErrKind { };       // error kind (1..8); an enum so that the ATL map takes it by reference
enum EBanStringId { };      // string table id

class Unk_ConstVal;         // one 0x58-byte slot of the game constants table (FUN_1401d3200()), read by FUN_1402056b0

// The text filter: banned / reserved / prefix word tries loaded from Table/*.xml, length and charset rules and the error
// string ids (0x3e8 bytes; vftable 0x142... with the deleting dtor, secondary CValidData<CBanTextChecker> at +0x18).
class CBanTextChecker : public CPtred, public CValidData<CBanTextChecker>
{
public:
    // The error string ids a check can answer with, by error kind (0x60 bytes).
    class CheckerErrStringPackage : public CPtred
    {
    public:
        CheckerErrStringPackage();                          // 0x140224430
        virtual ~CheckerErrStringPackage();                 // 0x1402244a0

        bool IsEmpty() const;                               // 0x140224500
        void Add(EBanErrKind nKind, EBanStringId nStringId);    // 0x140224530
        CStringW GetErrString(EBanErrKind nKind);           // 0x140224570

        ATL::CAtlMap<EBanErrKind, EBanStringId> m_ids;      // +0x18 error kind -> string id
    };

    // Which word lists a check consults (bit 1: reserved names, 2: ban words, 4: ban words (all), 8: ..., see
    // FUN_140227930) and the error strings it answers with (0x18 bytes).
    struct CheckerOption
    {
        CheckerOption(unsigned nTypes, bool bFlag);                                             // 0x14025c350
        CheckerOption(MS2Ptr<CheckerErrStringPackage> errs, unsigned nTypes, bool bFlag);        // 0x14025c2e0
        ~CheckerOption();                                                                       // 0x14025c9d0

        bool m_bFlag;                                       // +0x00
        unsigned m_nTypes;                                  // +0x04
        MS2Ptr<CheckerErrStringPackage> m_errs;             // +0x08
    };

    // Length and charset limits of a name (0x20 bytes).
    struct CheckerLimit
    {
        CheckerLimit(int nMin, int nMax, bool bAllowSpace, bool bSkipTrimCheck, bool bNoCharCheck, bool bWideCountsTwice, bool bAllowPunct);   // 0x14025c3a0
        ~CheckerLimit();                                                                        // 0x14025ca10

        int m_nMin;                                         // +0x00 (values below 2 are treated as 1)
        int m_nMax;                                         // +0x04
        bool m_bAllowSpace;                                 // +0x08
        bool m_bSkipTrimCheck;                              // +0x09
        bool m_bNoCharCheck;                                // +0x0a
        bool m_bWideCountsTwice;                            // +0x0b
        bool m_bAllowPunct;                                 // +0x0c
        MS2Ptr<CheckerErrStringPackage> m_errs;             // +0x10
    };

    CBanTextChecker();                                      // 0x140224890
    virtual ~CBanTextChecker();                             // 0x1402249e0

    static CStringW GetErrString(EBanErrKind nKind, MS2Ptr<CheckerErrStringPackage> pkg);       // 0x1402247f0
    static CStringW GetDefaultErrString(EBanErrKind nKind);                                    // 0x140224760
    static CStringW GetLimitErrString(CheckerLimit& limit, unsigned nKind);                    // 0x140259fe0
    static CStringW GetOptionErrString(CheckerOption& opt, EBanErrKind nKind, const CStringW& strMatched, unsigned char bFlag);   // 0x14025a290

    int LoadTables();                                       // 0x140224b20
    int HasStartWithWords(unsigned nTypes);                // 0x140224f80
    bool IsAlnumName(const CStringW& str, void*);                  // 0x140224fe0 (1..32 characters of [0-9A-Za-z])

    int FUN_140225120(const CStringW& str, CStringW& message);
    int FUN_140225210(const CStringW& str, CStringW& message, int bShort);
    int FUN_1402252f0(const CStringW& str, CStringW& message);
    int FUN_1402253b0(const CStringW& str, CStringW& message);
    int FUN_140225470(const CStringW& str, CStringW& message);
    int FUN_140225550(const CStringW& str, CStringW& message);
    int FUN_140225630(const CStringW& str, CStringW& message);
    int FUN_140225720(const CStringW& str, CStringW& message);
    int FUN_140225810(const CStringW& str, CStringW& message);
    int FUN_1402258f0(const CStringW& str, CStringW& message);
    int FUN_1402259b0(const CStringW& str, CStringW& message);
    int FUN_140225a70(const CStringW& str, CStringW& message);
    int FUN_140225c90(const CStringW& str, CStringW& message);
    int FUN_140225de0(const CStringW& str, CStringW& message);
    int FUN_140225f30(const CStringW& str, CStringW& message);
    int FUN_140225f70(const CStringW& str, CStringW& message);
    int FUN_1402260c0(const CStringW& str, CStringW& message);
    int FUN_140226100(const CStringW& str, CStringW& message);
    int FUN_140226160(const CStringW& str, CStringW& message);
    int FUN_1402261e0(const CStringW& str, CStringW& message);
    int FUN_140226220(const CStringW& str, CStringW& message);
    int FUN_140226260(const CStringW& str, CStringW& message);
    int FUN_1402262a0(const CStringW& str, CStringW& message);
    int FUN_1402262e0(const CStringW& str, CStringW& message);
    int FUN_140226320(const CStringW& str, CStringW& message);
    int FUN_140226400(const CStringW& str, CStringW& message);
    int FUN_140226440(const CStringW& str, CStringW& message);
    int FUN_140226590(const CStringW& str, CStringW& message);
    int FUN_1402266e0(const CStringW& str, CStringW& message);
    int FUN_140226830(const CStringW& str, CStringW& message);

    int CheckTextWithLimit(const CStringW& str, CheckerOption& opt, CheckerLimit& limit, CStringW& message);   // 0x140227fb0
    int CheckTextOption(const CStringW& str, CheckerOption& opt, CStringW& message);      // 0x140227930
    int CheckTypes(const CStringW& str, unsigned nTypes, bool bFlag, CStringW& message);  // 0x140228080
    unsigned ScanLimit(const CStringW& str, CheckerLimit& limit);                         // 0x140228110

    bool FindReserveIdAll(const CStringW& str, CStringW& matched);     // 0x140228a60
    bool FindReserveIdAny(const CStringW& str, CStringW& matched);     // 0x140228b40
    bool FindBanWord(const CStringW& str, CStringW& matched);          // 0x140228c50
    bool FindUgcBanWord(const CStringW& str, CStringW& matched);       // 0x140228d60
    bool FindReserveWord(const CStringW& str, CStringW& matched);      // 0x140228e70
    bool FindStartWithWord(const CStringW& str, CStringW& matched);    // 0x140228f80
    bool FindBanWordAll(const CStringW& str, CStringW& matched);       // 0x1402290b0

    void MaskBannedWords(CStringW& str);                    // 0x140226980
    void FilterReservedWords(CStringW& str);                // 0x140226b10
    void FilterBanWords(CStringW& str);                     // 0x140226cd0
    void SetBanWords(unsigned nKey, Unk_BanWordList& words);   // 0x1402271a0
    void RemoveBanWords(unsigned nKey);                     // 0x140227280
    static void CheckInit();                                // 0x14025d6f0 message box when not initialized
    static void SetInit(bool bInit);                        // 0x140263710
    void ClearTries();                                      // 0x140227890
    void FUN_140229220();                                   // empty
    int LoadWords(CString strPath, TextFilterUnit* pTrie);  // 0x1402272c0 Table xml of <key name="word[,replacement]"/>
    int LoadIdSet(CString strPath, std::set<CStringW>* pSet);   // 0x140227670
    void BuildUrlHashes();                                  // 0x140228740
    bool ReplaceUrlsWithHashes(CStringW& str);              // 0x140228880
    bool ReplaceHashesWithUrls(CStringW& str);              // 0x140228970

    TextFilterUnit m_trieBanUrl;                            // +0x020 Table/banUrl.xml
    TextFilterUnit m_trieBanWord;                           // +0x098 Table/banWord.xml
    TextFilterUnit m_trieBanWordAll;                        // +0x110 Table/banWordAll.xml
    TextFilterUnit m_trieReserveWord;                       // +0x188 Table/reserveWord.xml
    TextFilterUnit m_trieReserveIdAny;                      // +0x200 Table/reserveIDAny.xml
    TextFilterUnit m_trieUgcBanWord;                        // +0x278 Table/ugcBanWord.xml
    TextFilterUnit m_trieStartWith;                         // +0x2f0 Table/startWithWord.xml
    std::set<CStringW> m_setReserveIdAll;                   // +0x368 Table/reserveIDAll.xml (lower-cased)
    ATL::CRBMap<CStringW, CStringW> m_mapUrlHash;           // +0x378 url prefix -> its hash as text
    ATL::CRBMap<unsigned, Unk_BanWordPtr> m_mapBanWords;      // +0x3a8
    std::map<unsigned, int> m_mapCharClass;                 // +0x3d8
    static bool s_bInit;                                    // DAT_143aacc48
};
MS2_CHECK_SIZE(CBanTextChecker::CheckerErrStringPackage, 0x60);
MS2_CHECK_SIZE(CBanTextChecker::CheckerOption, 0x18);
MS2_CHECK_SIZE(CBanTextChecker::CheckerLimit, 0x20);
MS2_CHECK_SIZE(CBanTextChecker, 0x3e8);
MS2_CHECK_OFFSET(CBanTextChecker, m_trieBanUrl, 0x20);
MS2_CHECK_OFFSET(CBanTextChecker, m_trieStartWith, 0x2f0);
MS2_CHECK_OFFSET(CBanTextChecker, m_setReserveIdAll, 0x368);
MS2_CHECK_OFFSET(CBanTextChecker, m_mapUrlHash, 0x378);
MS2_CHECK_OFFSET(CBanTextChecker, m_mapBanWords, 0x3a8);
MS2_CHECK_OFFSET(CBanTextChecker, m_mapCharClass, 0x3d8);

class CommonString;
class Unk_140165cf0;

// This instantiation stores the complete object pointer; DAT_143aacce8 (getter FUN_14025e7d0).
template <> class TSingleton<CommonString>
{
public:
    TSingleton();                           // 0x14025bc10
    virtual ~TSingleton() { s_instance = 0; }   // 0x14025c730
    static CommonString* s_instance;
    static CommonString* GetInstance();                 // 0x14025e7d0
};

// The localized string table (RTTI CommonString, 0xf8 bytes, one global instance): string id -> text from
// Table/stringCommon.xml (and ../XmlDebug/stringDebug.xml), the id names compiled into the exe (FUN_140229ad0 fills
// m_strings), and the shared text filter. CCacheData +0 (vftable 0x...), TSingleton +0x28, CValidData +0x30.
class CommonString : public CCacheData, public TSingleton<CommonString>, public CValidData<CommonString>
{
public:
    typedef ATL::CRBMap<CStringW, CStringW, ATL::CStringElementTraitsI<CStringW> > TextMap;   // case-insensitive (Find/InsertImpl call the _wcsicmp traits 0x1401f8280/0x140212e70)

    CommonString();                                     // 0x140229230
    virtual ~CommonString();                            // 0x1402293a0

    static void CheckInit();                            // 0x14025d7a0 message box when not initialized
    static void SetInit(bool bInit);                    // 0x140263720
    CStringW MapText(int nMap, const CStringW& strKey);         // 0x1402294e0 text of a key in map 0 (strings) or 1
    CString GetNarrowDefault(int nId);                          // 0x1402295b0
    CString GetNarrow(int nId);                                 // 0x140229600 narrow text of a string id
    CString GetNarrowByKey(const CString& strKey);              // 0x140229690
    CStringW GetWide(int nId);                                  // 0x140229760 wide text of a string id
    CStringW GetWideByKey(const CStringW& strKey);              // 0x140229820
    CStringW FUN_140229940(const CString& strKey);              // 0x140229940 wide text of a "$..." key
    CStringW GetWideRaw(int nId);                               // 0x140229990 id text without key mapping
    MS2Ptr<CBanTextChecker> GetChecker();                       // 0x140229a50
    void RegisterIds();                                         // 0x140229ad0 fills m_strings with the id names
    int LoadCommon();                                           // 0x140259340 Table/stringCommon.xml
    int FUN_140259910();                                        // 0x140259910 always 1
    bool LoadDebug();                                           // 0x140259640 ../XmlDebug/stringDebug.xml
    void Reload();                                              // 0x140259930
    void LoadStrings(Unk_140165cf0* pRoot);                     // 0x140259e60
    bool FUN_1402599e0();                                       // 0x1402599e0 self test of the ban word checker (this unused)

    TextMap m_maps[2];                                  // +0x38
    ATL::CAtlMap<int, CStringW, ATL::CDefaultElementTraits<int> > m_strings;              // +0x98
    MS2Ptr<CBanTextChecker> m_spChecker;                // +0xe0
    unsigned char m_bRaw;                               // +0xf0
    static bool s_bInit;                                // DAT_143aaccf0
};
MS2_CHECK_SIZE(CommonString, 0xf8);
MS2_CHECK_OFFSET(CommonString, m_maps, 0x38);
MS2_CHECK_OFFSET(CommonString, m_strings, 0x98);
MS2_CHECK_OFFSET(CommonString, m_spChecker, 0xe0);
MS2_CHECK_OFFSET(CommonString, m_bRaw, 0xf0);
