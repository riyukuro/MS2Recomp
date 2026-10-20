// Layout proved by 1406949e0 / 140694ab0 / 140694c10; member names inferred.
#pragma once
#include <afx.h>
#include "ms2/placeholder/cptred.h"
class CInPacket;
class CMatchPartyRecruit : public CPtred {
public:
    CMatchPartyRecruit();
    virtual ~CMatchPartyRecruit();
    void FUN_140694ab0();
    void FUN_140694c10(CInPacket&);
    CMatchPartyRecruit& FUN_140694f70(const CMatchPartyRecruit&);
    __int64 recruitId;
    int fieldId, category, kind;
    CStringW title;
    int minimumLevel, maximumLevel, members;
    __int64 ownerId, created;
    CStringW ownerName;
    __int64 flags;
};
MS2_CHECK_OFFSET(CMatchPartyRecruit, recruitId, 0x18);
MS2_CHECK_OFFSET(CMatchPartyRecruit, title, 0x30);
MS2_CHECK_OFFSET(CMatchPartyRecruit, ownerName, 0x58);
MS2_CHECK_SIZE(CMatchPartyRecruit, 0x68);

// Serialization 140694280 and 1406946b0 establishes these field layouts.
struct Unk_PartyRecruitRequest {
    CStringW title;
    unsigned char kind;
    int fieldId;
};
MS2_CHECK_SIZE(Unk_PartyRecruitRequest, 0x10);
class CMatchPartyRecruitSchCond : public CPtred {
public:
    CMatchPartyRecruitSchCond();                                // 0x1406943b0 (calls Reset)
    int fieldId, category;
    unsigned char kind;
    CStringW text;
    int page, pageSize;
};
MS2_CHECK_OFFSET(CMatchPartyRecruitSchCond, page, 0x30);
MS2_CHECK_SIZE(CMatchPartyRecruitSchCond, 0x38);
