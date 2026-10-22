// maid.h - the maid (housekeeper NPC) record CMaid and the maid tables CMaidExpTable (Table/MaidExp.xml),
// CMaidInfoTable (Table/MaidProperty.xml), CMaidDescTable (<locale>/MaidPropertyString.xml) and
// CMaidManufactureMsgTable (<locale>/MaidManufactureMessage.xml) with their rows. Header name assumed (the unit is
// ?\maid.cpp, 0x14067c610-0x1406846a0; the exe range is two TUs: CMaid up to 0x14067e9d0, then the tables). Class
// names are RTTI names; row and member names come from the xml attributes, the rest are invented (layout hints:
// work/ext/v2525 CMaid.h / MaidInfo.h / MaidDesc.h / MaidManufactureMsg.h). The cmaid*.h placeholders forward here.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/tptrvalue.h"

class CInPacket;
template <class T> class MS2Ptr;
class COutputStream;

// The maid's 13 profile texts (CMaid +0x90; UIMaidDialog edits a copy). Its ctor/dtor/operator= are implicit
// (0x14067e520 / 0x14067e650 / 0x14067e750).
struct MaidProfile
{
    void Write(COutputStream* pStream);         // 0x14067c610
    void Read(CInPacket* pPacket);              // 0x14067c8a0
    CStringW Encode();                          // 0x14067cec0 the texts joined with ','

    CStringW title;                             // +0x00
    CStringW name;                              // +0x08 (guess)
    CStringW birthDay;                          // +0x10
    CStringW constellation;                     // +0x18
    CStringW height;                            // +0x20
    CStringW weight;                            // +0x28
    CStringW specialty;                         // +0x30 (guess)
    CStringW specialDetail;                     // +0x38
    CStringW like;                              // +0x40
    CStringW hate;                              // +0x48
    CStringW hobby;                             // +0x50
    CStringW ownerName;                         // +0x58
    CStringW belongTo;                          // +0x60
};
MS2_CHECK_SIZE(MaidProfile, 0x68);

// RTTI CMaid, 0xf8 bytes (deleting dtor 0x14067e8d0). One maid of the user / field maid managers.
class CMaid : public CPtred
{
public:
    CMaid();                                    // 0x14067d030
    CMaid(__int64 n18, unsigned __int64 nId, __int64 n28, int nItemId, __int64 nExpireTime);   // 0x14067d130
    virtual ~CMaid();                           // 0x14067d2a0
    void Update(MS2Ptr<CMaid> spMaid);          // 0x14067d300 takes the state of a newer record
    void SetProgress(int n4c, int nMood, int nLevel, __int64 t58, int nExp, __int64 nExpireTime, CStringA strList);   // 0x14067d410
    void SetTimes(__int64 t38, __int64 t40);    // 0x14067d4c0
    void SetProfile(const MaidProfile& profile);   // 0x14067d500
    void Write(COutputStream* pStream);         // 0x14067d540
    void FUN_14067d730(CInPacket* pPacket);     // 0x14067d730 Read: the maid's fields from the packet
    int GetRemainDays();                        // 0x14067daa0 days to the contract end, -1 when over
    int GetOverDays();                          // 0x14067db20 days past the contract end (>= 1), -1 when not over
    int IsExpired();                            // 0x14067dbc0
    int IsTime38Over(int nSeconds);             // 0x14067dc00
    int IsTime40Over(int nSeconds);             // 0x14067dc50
    int FUN_14067dca0();                        // 0x14067dca0 the affinity level is at its maximum
    int GetMoodGrade();                         // 0x14067dd10 0 (<= 30), 1 (<= 70), 2
    void ResetLevel();                          // 0x14067dd50
    void AddLevel(int nDelta, int bIgnoreLimit);   // 0x14067dd80
    int AddMood(int nDelta);                    // 0x14067de50 clamps to 0..100; true when changed
    void SetMode(int nMode);              // 0x14067def0 sets the maid's mode
    CStringW FUN_1409eeda0() { return m_profile.name; }   // inline COMDAT 0x1409eeda0 (astooltip.cpp): the maid's name

    MS2_LAYOUT_FRIEND;
    __int64 m_n18;                              // +0x18
    unsigned __int64 m_nId;                     // +0x20 the map key of the maid managers
    __int64 m_n28;                              // +0x28
    int m_nItemId;                              // +0x30 the maid's item
    int m_nMaidId;                              // +0x34 the row key of the maid tables (from the item data)
    __int64 m_t38;                              // +0x38
    __int64 m_t40;                              // +0x40
    int m_nMode;                                // +0x48
    int m_n4c;                                  // +0x4c (sent as a byte)
    int m_nMood;                                // +0x50
    int m_nOrder;                               // +0x54 the affinity level
    __int64 m_t58;                              // +0x58
    int m_nExp;                                 // +0x60 the affinity experience
    ATL::CAtlArray<int> m_list;                 // +0x68
    __int64 m_nExpireTime;                      // +0x88 the contract end
    MaidProfile m_profile;                      // +0x90
};
MS2_CHECK_SIZE(CMaid, 0xf8);
MS2_CHECK_OFFSET(CMaid, m_nId, 0x20);
MS2_CHECK_OFFSET(CMaid, m_nOrder, 0x54);
MS2_CHECK_OFFSET(CMaid, m_list, 0x68);
MS2_CHECK_OFFSET(CMaid, m_profile, 0x90);

// One <Property> row of MaidProperty.xml, 0x14 bytes inside a TPtredDummy box.
struct MaidInfo
{
    MaidInfo() : maidId(0), recipeGroupId(0), npcId(0), salaryType(0), salary(0) {}
    int maidId;                                 // +0x00 "MaidID"
    int recipeGroupId;                          // +0x04 "RecipeGroupID"
    unsigned npcId;                             // +0x08 "NPCID"
    int salaryType;                             // +0x0c from the item price table
    int salary;                                 // +0x10
    int FUN_1409eee80() { return salaryType == 0; }   // inline COMDAT 0x1409eee80 (astooltip.cpp): paid in meso
};
MS2_CHECK_SIZE(MaidInfo, 0x14);

// One <Desc> row of MaidPropertyString.xml, 0x80 bytes.
struct MaidDesc
{
    MaidDesc() : maidId(0) {}
    int maidId;                                 // +0x00 "MaidID"
    CStringW title;                             // +0x08 "Title"
    CStringW specialty;                         // +0x10 "Specialty"
    CStringW name;                              // +0x18 "Name"
    CStringW birthDay;                          // +0x20 "BirthDay"
    CStringW constellation;                     // +0x28 "Constellation"
    CStringW height;                            // +0x30 "Height"
    CStringW weight;                            // +0x38 "Weight"
    CStringW specialDetail;                     // +0x40 "SpecialDetail"
    CStringW like;                              // +0x48 "Like"
    CStringW hate;                              // +0x50 "Hate"
    CStringW hobby;                             // +0x58 "Hobby"
    CStringW ownerName;                         // +0x60 "OwnerName"
    CStringW belongTo;                          // +0x68 "BelongTo"
    CStringW specialTitle;                      // +0x70 "SpecialTitle"
    CStringW background;                        // +0x78 "Background"
};
MS2_CHECK_SIZE(MaidDesc, 0x80);

// One <Message> row of MaidManufactureMessage.xml, 0x40 bytes.
struct MaidManufactureMsg
{
    MaidManufactureMsg() : maidId(0) {}
    int maidId;                                 // +0x00 "MaidID"
    CStringW selectItem;                        // +0x08 "SelectItem"
    CStringW craftRequest;                      // +0x10 "CraftRequest"
    CStringW receiveItem;                       // +0x18 "RecieveItem"
    CStringW receiveJackpot;                    // +0x20 "RecieveJackpot"
    CStringW craftCancel;                       // +0x28 "CraftCancel"
    CStringW notEnoughIgd;                      // +0x30 "NotEnoughIgd"
    CStringW expired;                           // +0x38 "Expired"
};
MS2_CHECK_SIZE(MaidManufactureMsg, 0x40);

// RTTI CMaidExpTable, 0x40 bytes: affinity level -> experience.
class CMaidExpTable : public TSingleton<CMaidExpTable>, public CValidData<CMaidExpTable>
{
public:
    CMaidExpTable();                            // 0x14067e9d0
    virtual ~CMaidExpTable();                   // 0x14067ea50
    int Load();                                 // 0x14067eab0
    int GetExp(int nLevel);                     // 0x14067ed30
    int GetMaxLevel();                          // 0x14067ed80
    static void CheckInit();                    // 0x140681660
    static void SetInit(bool b);                // 0x140684100
    static bool s_bInit;                        // 0x143ab0380

    MS2_LAYOUT_FRIEND;
    ATL::CRBMap<int, int> m_exps;               // +0x10
};
MS2_CHECK_SIZE(CMaidExpTable, 0x40);
MS2_CHECK_OFFSET(CMaidExpTable, m_exps, 0x10);

// RTTI CMaidInfoTable, 0x40 bytes: maid id -> MaidInfo.
class CMaidInfoTable : public TSingleton<CMaidInfoTable>, public CValidData<CMaidInfoTable>
{
public:
    CMaidInfoTable();                           // 0x14067edb0
    virtual ~CMaidInfoTable();                  // 0x14067ee30
    int Load();                                 // 0x14067ee90
    TPtrValue<MaidInfo> Find(int nMaidId);      // 0x14067f180
    static void CheckInit();                    // 0x140681710
    static void SetInit(bool b);                // 0x140684110
    static bool s_bInit;                        // 0x143ab0390

    MS2_LAYOUT_FRIEND;
    ATL::CRBMap<int, TPtrValue<MaidInfo> > m_infos;     // +0x10
};
MS2_CHECK_SIZE(CMaidInfoTable, 0x40);

// RTTI CMaidDescTable, 0x40 bytes: maid id -> MaidDesc.
class CMaidDescTable : public TSingleton<CMaidDescTable>, public CValidData<CMaidDescTable>
{
public:
    CMaidDescTable();                           // 0x14067f240
    virtual ~CMaidDescTable();                  // 0x14067f2c0
    int Load();                                 // 0x14067f320
    TPtrValue<MaidDesc> Find(int nMaidId);      // 0x14067f780
    static void CheckInit();                    // 0x1406815b0
    static void SetInit(bool b);                // 0x1406840f0
    static bool s_bInit;                        // 0x143ab03a0

    MS2_LAYOUT_FRIEND;
    ATL::CRBMap<int, TPtrValue<MaidDesc> > m_descs;     // +0x10
};
MS2_CHECK_SIZE(CMaidDescTable, 0x40);

// RTTI CMaidManufactureMsgTable, 0x40 bytes: maid id -> MaidManufactureMsg.
class CMaidManufactureMsgTable : public TSingleton<CMaidManufactureMsgTable>,
                                 public CValidData<CMaidManufactureMsgTable>
{
public:
    CMaidManufactureMsgTable();                 // 0x14067f840
    virtual ~CMaidManufactureMsgTable();        // 0x14067f8c0
    int Load();                                 // 0x14067f920
    TPtrValue<MaidManufactureMsg> Find(int nMaidId);    // 0x14067fd60
    static void CheckInit();                    // 0x1406817c0
    static void SetInit(bool b);                // 0x140684120
    static bool s_bInit;                        // 0x143ab03b0

    MS2_LAYOUT_FRIEND;
    ATL::CRBMap<int, TPtrValue<MaidManufactureMsg> > m_msgs;    // +0x10
};
MS2_CHECK_SIZE(CMaidManufactureMsgTable, 0x40);
