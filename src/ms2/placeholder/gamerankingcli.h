// gamerankingcli.h - PLACEHOLDER for the client side of the game ranking service (CGameRankingCli, CGameRankingParam,
// CGameRankingData, the rank key and the result handles). NOT an original header; names of the classes come from RTTI
// (CGameRankingParam) or are inferred from use by UIGameRankingDialog. Their unit (gamerankingcli.cpp,
// 0x140b2.... - 0x140b4....) is not recovered yet: units must include this header instead of redefining the types.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/commonfiles/os.h"

// The 12-byte key of a ranking board: (type, sub category, tab / season, ...).
struct Unk_RankKey
{
    Unk_RankKey();                                          // 0x140b356e0
    ~Unk_RankKey();                                         // 0x140b35780
    Unk_RankKey& FUN_140b35820(const Unk_RankKey& o);       // copy
    int FUN_140b357e0() const;                              // the ranking type of the key
    int m_0;
    int m_4;
    int m_8;
};
MS2_CHECK_SIZE(Unk_RankKey, 0xc);

// One ranking row (the JSON "rank" object of the web service; strings are UTF-16). Only the fields the dialog reads
// are named; the rest is padding. The party members (10 x 0x40 bytes from +0xa8) are filled by the party boards.
struct Unk_RankMember
{
    CStringW m_name;                                        // +0x00
    void* m_pad_08;
    int m_nJob;                                             // +0x10
    int m_nLevel;                                           // +0x14
    char m_pad_18[0x28];
};
MS2_CHECK_SIZE(Unk_RankMember, 0x40);

struct Unk_RankData
{
    int m_nRank;                                            // +0x00
    int m_nRankType;                                        // +0x04
    __int64 m_nPoint;                                       // +0x08
    int m_nRankPoint;                                       // +0x10
    int m_nPvpGrade;                                        // +0x14
    char m_pad_18[8];
    __int64 m_nMarkId;                                      // +0x20 (0 = the mark is a file of the web service)
    __int64 m_nAccountSN;                                   // +0x28
    __int64 m_nCharSN;                                      // +0x30
    CStringW m_cname;                                       // +0x38
    CStringW m_pbname;                                      // +0x40
    CStringW m_gname;                                       // +0x48
    CStringW m_gbname;                                      // +0x50
    CStringW m_registerationDate;                           // +0x58
    char m_pad_60[8];
    CStringW m_attackTime;                                  // +0x68
    CStringW m_pvpGradeName;                                // +0x70
    CStringW m_markFile;                                    // +0x78
    CStringW m_homename;                                    // +0x80
    char m_pad_88[0x20];
    Unk_RankMember m_party[10];                             // +0xa8
    void FUN_140b287b0(int nType, struct Unk_RankJson json);    // fill the row from the answer
};
MS2_CHECK_OFFSET(Unk_RankData, m_cname, 0x38);
MS2_CHECK_OFFSET(Unk_RankData, m_homename, 0x80);
MS2_CHECK_OFFSET(Unk_RankData, m_party, 0xa8);

// A request of the ranking service (vftable 0x142ddf4b8, 0x50 bytes).
class CGameRankingParam : public CPtred
{
public:
    CGameRankingParam();                                    // 0x140b3dd70
    virtual ~CGameRankingParam();                           //  0 0x140b436f0

    Unk_RankKey m_key;                                      // +0x18
    int m_24;                                               // +0x24 (DAT_143ab2830)
    __int64 m_28;                                           // +0x28 (DAT_143ab2820)
    __int64 m_30;                                           // +0x30 (DAT_143ab2828)
    void* m_38;                                             // +0x38 the board's cached answer
    CStringW m_search;                                      // +0x40 search text
    void* m_48;
};
MS2_CHECK_SIZE(CGameRankingParam, 0x50);

// The tag that selects the "make a fresh object" constructor of the service's handles (0x1401b7b90, no code).
struct Unk_RankNewTag
{
    explicit Unk_RankNewTag(int);
};

// The answer of a request: slot 2 = percent rank flag, slot 3 = my rank (both through the pointee's vftable).
struct Unk_RankListHandle;
class Unk_RankReply
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual int vfunc_2();                                  // 0x10 percent rank flag
    virtual int vfunc_3();                                  // 0x18 my rank
    int FUN_140b2e9c0();                                    // number of pages
    int GetRankType();                                    // the ranking type of the answer (inline, rankdialog)
    Unk_RankListHandle FUN_140b3dcc0();                     // the row list of the answer
    char m_pad_08[0x10];
    int m_nRankType;                                        // +0x18
};

// The row list of an answer (field 1 the list; dtor 0x140b2dad0).
struct Unk_RankListHandle
{
    ~Unk_RankListHandle();                                  // 0x140b2dad0
    void* FUN_140b2e170();                                  // the list (NULL test)
    void* m_00;
    void* m_p;
};

// The parsed JSON of a row list (copy of the handle; consumed by Unk_RankData::FUN_140b287b0).
struct Unk_RankJson
{
    Unk_RankJson(const Unk_RankListHandle& h);              // 0x140b2d460
    ~Unk_RankJson();
    void* m_00;
    void* m_p;
};

// Four 16-byte smart pointers of the service (field 0 unused, field 1 the pointee), each a distinct instance of the
// service's handle template; the members are out-of-line in the exe.
struct Unk_RankInfoPtr                                      // my-rank answer (Cli::FUN_140b2ac30)
{
    ~Unk_RankInfoPtr();                                     // 0x140b2db00
    bool FUN_140b2e080(int);                                // == NULL
    void* FUN_140b2e180();                                  // the handle itself (NULL test)
    Unk_RankReply* FUN_140b2e210();                         // the answer
    void* m_00;
    void* m_p;
};

struct Unk_RankPageReq                                      // page request (Cli::FUN_140b2add0 / FUN_140b2af90)
{
    ~Unk_RankPageReq();                                     // 0x140b2db30
    bool FUN_140b2e0c0(int);                                // == NULL
    void* FUN_140b2e190();                                  // the handle itself (NULL test)
    Unk_RankReply* FUN_140b2e220();                         // the answer
    void* m_00;
    void* m_p;
};

struct Unk_RankDataPtr                                      // boxed Unk_RankData
{
    Unk_RankDataPtr() : m_00(0), m_p(0) {}                  // 0x140e362f0 (folded with the other m_p = 0 ctors)
    Unk_RankDataPtr(const Unk_RankNewTag&);                 // 0x140b2d310
    Unk_RankDataPtr(const Unk_RankDataPtr& o) : m_00(o.m_00), m_p(o.m_p) { if (m_p) CPtred::AddRefPtred(reinterpret_cast<CPtred*>(m_p)); }   // copy: adds a reference to the box
    ~Unk_RankDataPtr();                                     // 0x140b2da40
    Unk_RankData* FUN_140b2e1e0() const;                    // the row
    void* m_00;
    Unk_RankData* m_p;
};

// RTTI: TSingleton<CGameRankingCli> is the only base; 0x100 bytes (the operator new size in CGameApp::InitInstance).
class CGameRankingCli : public TSingleton<CGameRankingCli>
{
public:
    CGameRankingCli();                                      // 0x140b2a790
    virtual ~CGameRankingCli();
    static CGameRankingCli* FUN_140b2e980();                // the singleton
    int FUN_140b2b440(const Unk_RankKey& key, int nPage, ATL::CAtlArray<Unk_RankDataPtr>& rows, CStringW strSearch, int bForce);
    void FUN_140b2bf30(CGameRankingParam* pParam);          // send the request
    Unk_RankInfoPtr FUN_140b2ac30(const Unk_RankKey& key, int bFlag);
    Unk_RankPageReq FUN_140b2add0(const Unk_RankKey& key, int a1, int a2);
    Unk_RankPageReq FUN_140b2af90(const Unk_RankKey& key, CStringW strSearch, int a1);
    void FUN_140b2b870(Unk_RankKey* pKey, int nType, int nSub, int nTab, int nSeason);
    void FUN_140b2bbf0(Unk_RankKey* pKey, int nType, int nSub, int nTab, int nSeason);
    void* FUN_140b2c6f0(int nType);
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x100 - 0x8];
};
MS2_CHECK_SIZE(CGameRankingCli, 0x100);
