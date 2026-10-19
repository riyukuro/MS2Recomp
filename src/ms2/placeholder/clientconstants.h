// clientconstants.h - Common::Constants / Client::Constants (exe vftables 0x142d1ec00 / 0x142d1eca0, sizes 0xae68 / 0xea98)
// and their Object / Value<T> / Values<T> members. RTTI names: Common::Constants::Value<MS2Tick|MS2Color|...>.
// Every member is a self-registering Object (ctor 0x1402b72d0 + Register 0x1402b7590) named by its constants.xml key.
// MS2Color here is Unk_ConstColor (a packed 4-byte value; ms2color.h's float MS2Color is a different class).
#pragma once
#include <string>
#include <vector>
#include <afx.h>
#include <atlcoll.h>
#include <NiPoint3.h>
#include "ms2/commonfiles/os.h"
#include "ms2/ms2layout.h"
#include "ms2/placeholder/tptr.h"
#include "ms2/placeholder/ccachedata.h"

namespace Client { class Constants; }
struct MS2Tick { unsigned value; MS2Tick(); MS2Tick(unsigned v); };
struct Unk_ConstColor { unsigned argb; Unk_ConstColor(); Unk_ConstColor(unsigned v); };
struct MS2Colors : ATL::CAtlArray<unsigned long> { MS2Colors(); ~MS2Colors(); MS2Colors& operator=(const MS2Colors& o); };
// 16-byte intrusive reference to a CCacheData (base at +0 unrecovered; pointee at +8). The element type of Constants::cacheRefs.
struct Unk_ConstCacheRef {
    void* m_base;                                   // +0
    CCacheData* m_p;                                // +8
    Unk_ConstCacheRef() : m_base(0), m_p(0) {}
    Unk_ConstCacheRef(CCacheData* p);               // 0x1401e0d50
    Unk_ConstCacheRef(const Unk_ConstCacheRef& o);  // 0x1401ef790
    ~Unk_ConstCacheRef();                           // 0x1401e1170
    CCacheData* get() const { return m_p; }         // 0x1402be5b0
    CCacheData* operator->() const { return m_p; }  // 0x1401e1390
};

template<> class TSingleton<Client::Constants> {
public:
    TSingleton();
    virtual ~TSingleton();
    static Client::Constants* s_instance;
    static Client::Constants* GetInstance();        // 0x1401d3200 (FUN_1401d3200 below)
};

// @0x1401d3200 TSingleton<Client::Constants>::GetInstance as seen from Common::Constants code.
namespace Common { class Constants; }
Common::Constants* FUN_1401d3200();
// CString -> value parsers (other units).
unsigned short FUN_140718110(const CString& s);
unsigned int FUN_1407181d0(const CString& s);
unsigned long FUN_140718290(const CString& s);
__int64 FUN_1407182f0(const CString& s);
bool FUN_140718390(const CString& s);
efd::Point3* FUN_140db9570(efd::Point3* out, const CString& s);
int FUN_140718170(const CString& s);
float FUN_140718450(const CString& s);
unsigned* FUN_140718770(unsigned* out, const CString& s);
unsigned* FUN_140718830(unsigned* out, const CString& s);
CString* FUN_1407185b0(CString* out, const CString& s);
CStringW* FUN_140718650(CStringW* out, const CString& s);
MS2Colors* FUN_1407186f0(MS2Colors* out, const CString& s);
void FUN_140178270(const CString& s, std::vector<int>* out, const char* sep);
void FUN_1401782a0(const CString& s, std::vector<unsigned>* out, const char* sep);

namespace Common {
class Constants {
public:
    class Object {
    public:
        Object(const char* typeName);
        virtual ~Object();
        virtual void vfunc_1();             // Reset: forget the loaded value
        bool IsValid() const;
        const char* GetTypeName() const;
        const char* GetKey() const;
        void SetKey(const char* key);
        void Error(const char* msg);
        void MarkLoaded();
        void MarkForced();
        bool IsDefined() const;
        bool HasKey() const;
        bool IsLoaded() const;
        bool m_defined, m_hasKey, m_loaded, m_forced;       // +8..+0xb
        std::string m_typeName;                             // +0x10
        std::string m_key;                                  // +0x30
    };

    template<class T> static const char* TypeName();

    template<class T> class Value : public Object {
    public:
        Value() : Object(TypeName<T>()) { FUN_1401d3200()->Register(this); }
        T* Define(const char* key, const T& def);
        T* Get();
        const T& Get(const T& kDefault);                    // 0x140967520 (float): the value once loaded, else kDefault
        T Read() { return *Get(); }   // 0x1402bac50 (uint) / bac70 (float) / bac90 (__int64)
        T* Set(const T& v);
        T m_value;                                          // +0x50
        T m_default;
    };

    template<class T> class Values : public Object {
    public:
        Values() : Object(TypeName<T>()) { FUN_1401d3200()->Register(this); }
        virtual void vfunc_1();
        bool Define(const char* key);
        bool Define(const char* key, ATL::CAtlArray<T>* out);
        bool Contains(T v);
        bool Get(ATL::CAtlArray<T>& out);                   // 0x140ce06c0 (CString): copy the loaded values
        ATL::CAtlArray<T> m_values;                         // +0x50
    };

    Constants();
    virtual void vfunc_0();                                 // load constants.xml values (defaults + overrides)
    virtual ~Constants();

    static void Register(Object* obj);
    static bool Test();
    static void ResetAll();
    bool LoadFiles();                                       // read constants.xml / colorConstants.xml / testConstants.xml into `values`
    bool Load();
    void Reload();
    bool AreSameGroup(int a, int b);

    bool Lookup(const CString& key, unsigned short* out);
    bool Lookup(const CString& key, int* out);
    bool Lookup(const CString& key, unsigned long* out);
    bool Lookup(const CString& key, std::vector<int>* out);
    bool Lookup(const CString& key, unsigned int* out);
    bool Lookup(const CString& key, std::vector<unsigned>* out);
    bool Lookup(const CString& key, float* out);
    bool Lookup(const CString& key, Unk_ConstColor* out);
    bool Lookup(const CString& key, MS2Colors* out);
    bool Lookup(const CString& key, MS2Tick* out);
    bool Lookup(const CString& key, CString* out);
    bool Lookup(const CString& key, CStringW* out);
    bool Lookup(const CString& key, efd::Point3* out);
    bool Lookup(const CString& key, __int64* out);
    bool Lookup(const CString& key, bool* out);
    bool GetOr(const CString& key, unsigned short* out, const unsigned short& def);
    bool GetOr(const CString& key, int* out, const int& def);
    bool GetOr(const CString& key, float* out, const float& def);
    bool GetOr(const CString& key, bool* out, const bool& def);
    bool GetOr(const CString& key, CStringW* out, const CStringW& def);

    __int64 m_unk8;
    CAtlArray<Unk_ConstCacheRef> cacheRefs;               // +0x10
    ATL::CRBMap<CString, CString> values;            // +0x30
    Value<MS2Tick> LookAtInterval;                   // +0x60
    Value<float> LookAtDistanceNPC;                  // +0xb8
    Value<float> LookAtDistanceCry;                  // +0x110
    Value<float> DamageDistance;                     // +0x168
    Value<float> DropIconDistance;                   // +0x1c0
    Value<float> TalkableDistance;                   // +0x218
    Value<float> ChatBalloonDistance;                // +0x270
    Value<float> HpBarDistance;                      // +0x2c8
    Value<float> HpBarDistance2;                     // +0x320
    Value<float> BuffBallonDistance;                 // +0x378
    Value<float> DropIconHeadOffset;                 // +0x3d0
    Value<float> OffsetPcHpbar;                      // +0x428
    Value<float> OffsetPcNametag;                    // +0x480
    Value<float> OffsetPcChatballoon;                // +0x4d8
    Value<float> OffsetPcDamagenumber;               // +0x530
    Value<float> OffsetNpcHpbar;                     // +0x588
    Value<float> OffsetNpcNametag;                   // +0x5e0
    Value<float> OffsetNpcEmoticon;                  // +0x638
    Value<float> OffsetNpcChatballoon;               // +0x690
    Value<float> OffsetNpcDamagenumber;              // +0x6e8
    Value<float> OffsetNpcMonologue;                 // +0x740
    Value<float> OffsetPcPopupMenu;                  // +0x798
    Value<float> OffsetPcProfileTag;                 // +0x7f0
    Value<float> fOffsetOnTombstoneNameTag;          // +0x848
    Value<int> ChatBalloonDuration;                  // +0x8a0
    Value<MS2Tick> MonologueInterval;                // +0x8f8
    Value<MS2Tick> MonologueRandom;                  // +0x950
    Value<MS2Tick> MonologueShowTime;                // +0x9a8
    Value<int> BoreWaitingTick;                      // +0xa00
    Value<float> SkipFrameGameObject;                // +0xa58
    Value<float> SkipFrameDistanceGameObject;        // +0xab0
    Value<int> PassengerProfileImageSize;            // +0xb08
    Value<MS2Tick> PassengerProfileImageLifeTime;    // +0xb60
    Value<int> PassengerProfileImageShowNumber;      // +0xbb8
    Value<MS2Tick> PassengerProfileImageShowCooldown; // +0xc10
    Value<MS2Tick> PassengerProfileImageShowCooldownParty; // +0xc68
    Value<int> PassengerProfileImageShowRange;       // +0xcc0
    Value<int> UGCCameraDefaultSize;                 // +0xd18
    Value<int> UGCCameraMinSize;                     // +0xd70
    Value<int> UGCCameraMaxSize;                     // +0xdc8
    Value<int> UGCCameraSnapshotPreviewTime;         // +0xe20
    Value<int> UGCImgUploadSizeLimit;                // +0xe78
    Value<unsigned int> UGCImgFileCountCheck;        // +0xed0
    Value<float> InteractionDistance;                // +0xf28
    Value<float> FunctionCubeDistance;               // +0xf80
    Value<float> FunctionCubeDistance2;              // +0xfd8
    Value<float> ConstructUgcDistance;               // +0x1030
    Value<float> RegistUgcDistance;                  // +0x1088
    Value<float> RegistUgcDistanceClose;             // +0x10e0
    Value<int> UgcBoundaryStartDistance;             // +0x1138
    Value<int> UgcBoundaryEndDistance;               // +0x1190
    Value<int> DurationForBoundaryDisplay;           // +0x11e8
    Value<int> HouseMarkShowDistance;                // +0x1240
    Value<float> HouseMarkShowClippingUp;            // +0x1298
    Value<float> HouseMarkShowClippingDown;          // +0x12f0
    Value<int> HouseMarkPopupDistance;               // +0x1348
    Value<float> VolumeMyPcToNpc;                    // +0x13a0
    Value<float> VolumeMyPcToObject;                 // +0x13f8
    Value<float> VolumeMyPcToBreakableObject;        // +0x1450
    Value<float> VolumePcToNpc;                      // +0x14a8
    Value<float> VolumePcToBreakableObject;          // +0x1500
    Value<float> VolumeNpcToMyPc;                    // +0x1558
    Value<float> VolumeNpcToPc;                      // +0x15b0
    Value<float> VolumeOtherPc;                      // +0x1608
    Value<float> FieldCachingTime;                   // +0x1660
    Value<int> FieldCachingCount;                    // +0x16b8
    Value<int> FieldCachingMaxCount;                 // +0x1710
    Value<int> FieldUnloadThreshold;                 // +0x1768
    Value<float> EffectLODOneStepDistance;           // +0x17c0
    Value<float> EffectLODTwoStepDistance;           // +0x1818
    Value<float> EffectLODThreeStepDistance;         // +0x1870
    Value<float> CameraInterpolationTime;            // +0x18c8
    Value<int> EscapeHitMethodSkill;                 // +0x1920
    Value<int> EscapeHitMethodJump;                  // +0x1978
    Value<int> EscapeHitMethodMove;                  // +0x19d0
    Value<int> EscapeHitMoveKeyIsDown;               // +0x1a28
    Value<float> CameraFinalLoose;                   // +0x1a80
    Value<float> CameraCurrentLoose;                 // +0x1ad8
    Value<float> CameraUpdateLoose;                  // +0x1b30
    Value<float> CameraExtraDistance;                // +0x1b88
    Value<float> CameraExtraMoveScaleByMonster;      // +0x1be0
    Value<float> CameraExtraMoveScaleByMap;          // +0x1c38
    Value<int> UserRevivalPaneltyPercent;            // +0x1c90
    Value<float> RegionSkillFadeOutDuration;         // +0x1ce8
    Value<float> DropItemTargetZPos;                 // +0x1d40
    Value<float> DropItemMaxLength;                  // +0x1d98
    Value<float> DropMoneyMaxLength;                 // +0x1df0
    Value<float> DropItemPickUpVel;                  // +0x1e48
    Value<float> DropItemPickUpGravity;              // +0x1ea0
    Value<float> DropItemPickUpCompleteRotateTime;   // +0x1ef8
    Value<float> DropItemPickUpCompleteRotateVel;    // +0x1f50
    Value<float> moneyTreeDropHeight;                // +0x1fa8
    Value<float> moneyTreeDropBase;                  // +0x2000
    Value<int> moneyTreeDropRandom;                  // +0x2058
    Value<float> DefaultDropItemAlpha;               // +0x20b0
    Value<float> DropItemPickFailTime;               // +0x2108
    Value<float> DropItemPickFailHeight;             // +0x2160
    Value<float> GetExpMinVelocity;                  // +0x21b8
    Value<float> GetExpVelocityPer1Length;           // +0x2210
    Value<float> GetExpTimeAcceleration;             // +0x2268
    Value<float> GetExpCollisionRadius;              // +0x22c0
    Value<efd::Point3> GetExpControlValue0;          // +0x2318
    Value<efd::Point3> GetExpControlValue1;          // +0x2380
    Value<CString> GetExpTargetPCDummyName;          // +0x23e8
    Value<float> NPCRandomDeadPushRate;              // +0x2448
    Value<float> unusedFloat24a0;                    // +0x24a0
    Value<float> unusedFloat24f8;                    // +0x24f8
    Value<float> unusedFloat2550;                    // +0x2550
    Value<float> CameraVelocityInPortalMove;         // +0x25a8
    Value<float> EmoticonVisibleDistance;            // +0x2600
    Value<int> TalkableFrontOnly;                    // +0x2658
    Value<float> TelescopeFindDistance;              // +0x26b0
    Value<float> ConstructionGuideCamZoomVelocity;   // +0x2708
    Value<float> ConstructionGuideCamDistance;       // +0x2760
    Value<float> ConstructionGuideCamVelocity;       // +0x27b8
    Value<float> FindHoldTargetRange;                // +0x2810
    Value<float> FindGrabNodeRange;                  // +0x2868
    Value<float> ClimbVelocityV;                     // +0x28c0
    Value<float> ClimbVelocityH;                     // +0x2918
    Value<int> UserRevivalInvincibleTick;            // +0x2970
    Value<int> EmotionBoreAnimProbability;           // +0x29c8
    Value<int> ItemTransferBlackMarketGrade;         // +0x2a20
    Value<int> TaxiCallDuration;                     // +0x2a78
    Value<int> TaxiCallBestDriverDuration;           // +0x2ad0
    Value<int> TaxiCallBestDriverLevel;              // +0x2b28
    Value<int> AirTaxiCashCallDuration;              // +0x2b80
    Value<int> AirTaxiMesoCallDuration;              // +0x2bd8
    Value<float> TaxiStationFindDistance;            // +0x2c30
    Value<int> CancelSwing_KeyIsDown;                // +0x2c88
    Value<float> CustomizingHairSecondPartHighlight; // +0x2ce0
    Value<float> CustomizingHairFirstPartHighlight;  // +0x2d38
    Value<float> CustomizingWheelSpeed_Morph;        // +0x2d90
    Value<float> CustomizingWheelSpeed_Makeup;       // +0x2de8
    Value<float> CustomizingRotationSpeed_Makeup;    // +0x2e40
    Value<float> CustomizingWheelSpeed_Item;         // +0x2e98
    Value<int> ItemDropLevelMaxBoundry;              // +0x2ef0
    Value<float> WindPeriodVar2Cloak;                // +0x2f48
    Value<float> WindPeriod2Cloak;                   // +0x2fa0
    Value<float> WindAmp2Cloak;                      // +0x2ff8
    Value<int> TransparencyCP;                       // +0x3050
    Value<int> TransparencyEY;                       // +0x30a8
    Value<int> TransparencyCL;                       // +0x3100
    Value<int> TransparencyPA;                       // +0x3158
    Value<int> TransparencyMT;                       // +0x31b0
    Value<int> TransparencyEA;                       // +0x3208
    Value<int> TransparencyFH;                       // +0x3260
    Value<int> TransparencyGL;                       // +0x32b8
    Value<int> TransparencyRI;                       // +0x3310
    Value<int> TransparencySH;                       // +0x3368
    Value<int> SummonRideeDuration;                  // +0x33c0
    Value<int> WorldMapAdjustTileX;                  // +0x3418
    Value<int> WorldMapAdjustTileY;                  // +0x3470
    Value<float> TimeScalePCScale;                   // +0x34c8
    Value<float> TimeScalePCDuration;                // +0x3520
    Value<int> returnHomeSkillMerat;                 // +0x3578
    Value<int> GoToHomeCastingTime;                  // +0x35d0
    Value<int> RecallCastingTime;                    // +0x3628
    Value<int> UserPortalInvincibleTick;             // +0x3680
    Value<int> MaxFPS;                               // +0x36d8
    Value<int> TalkCooldown;                         // +0x3730
    Value<int> TradeRequestDuration;                 // +0x3788
    Value<int> CoupleEmotionMaxDistance;             // +0x37e0
    Value<int> CoupleEmotionRequestDuration;         // +0x3838
    Value<int> MicroGameRequestDuration;             // +0x3890
    Value<int> MicroGameMaxDistance;                 // +0x38e8
    Value<int> TailEffectDefaultID;                  // +0x3940
    Value<int> UgcBannerCheckTime;                   // +0x3998
    Value<int> CubeCraftSafetyCapID;                 // +0x39f0
    Value<unsigned int> CubeCraftLightStickLeftID;   // +0x3a48
    Value<unsigned int> CubeCraftLightStickRightID;  // +0x3aa0
    Value<int> CubeLiftHeightLimitUp;                // +0x3af8
    Value<int> CubeLiftHeightLimitDown;              // +0x3b50
    Value<int> BoatPrice;                            // +0x3ba8
    Value<float> TutorialIntroSkipTime;              // +0x3c00
    Value<int> FastChat_CheckTime;                   // +0x3c58
    Value<int> SameChat_CheckTime;                   // +0x3cb0
    Value<int> FastChat_CheckCount;                  // +0x3d08
    Value<int> SameChat_CheckCount;                  // +0x3d60
    Value<int> SameChat_RestrictTime;                // +0x3db8
    Value<int> FastChat_RestrictTime;                // +0x3e10
    Value<int> RestrictChat_AddRestrictTime;         // +0x3e68
    Value<int> AccumWarning_AddRestrictTime;         // +0x3ec0
    Value<int> RestrictWarning_ReleaseTime;          // +0x3f18
    Value<int> WisperIgnoreTime;                     // +0x3f70
    Value<int> WisperDurationTime;                   // +0x3fc8
    Value<int> WisperMaxCount;                       // +0x4020
    Value<int> QuestGuidePageCount;                  // +0x4078
    Value<int> QuestGuideMaxCount;                   // +0x40d0
    Value<int> ShopSeedResetTime;                    // +0x4128
    Value<int> UgcHomeSaleWaitingTime;               // +0x4180
    Value<int> UgcContainerExpireDurationNormal;     // +0x41d8
    Value<int> UgcContainerExpireDurationCash;       // +0x4230
    Value<int> UgcContainerExpireDurationMerat;      // +0x4288
    Value<int> UgcHomeExtensionNoticeDate;           // +0x42e0
    Value<int> UgcHomePasswordExpireDuration;        // +0x4338
    Value<int> AddressPopupDuration;                 // +0x4390
    Value<CString> AvatarDefaultItemMale;            // +0x43e8
    Value<CString> AvatarDefaultItemFemale;          // +0x4448
    Value<int> StoreExpandMaxSlotCount;              // +0x44a8
    Value<int> StoreExpandPrice1Row;                 // +0x4500
    Value<int> StoreDepositMax;                      // +0x4558
    Value<int> StoreWithdrawMax;                     // +0x45b0
    Value<int> UGCShopSellMinPrice;                  // +0x4608
    Value<int> UGCShopSellMaxPrice;                  // +0x4660
    Value<int> UGCShopAdHour;                        // +0x46b8
    Value<__int64> UGCShopAdFeeMerat;                // +0x4710
    Value<int> UGCShopSaleDay;                       // +0x4770
    Value<__int64> UGCShopSellingRestrictAmount;     // +0x47c8
    Value<__int64> BlackMarketSellMinPrice;          // +0x4828
    Value<__int64> BlackMarketSellMaxPrice;          // +0x4888
    Value<float> FallMoveSpeed;                      // +0x48e8
    Value<int> GuildCreatePrice;                     // +0x4940
    Value<int> GuildCreateMinLevel;                  // +0x4998
    Value<float> guildFundRate;                      // +0x49f0
    Value<int> guildExpMaxCountForPlayTime;          // +0x4a48
    Value<int> guildDonateMeso;                      // +0x4aa0
    Value<int> guildStorageGiftNeedPeriod;           // +0x4af8
    Value<int> PvpFFARewardItem;                     // +0x4b50
    Value<int> PvpFFARewardCount[10];                // +0x4ba8
    Value<int> PvpFFAAdditionRewardRate;             // +0x4f18
    Value<int> pvpBtiRewardItem;                     // +0x4f70
    Value<int> pvpBtiRewardWinnerCount;              // +0x4fc8
    Value<int> pvpBtiRewardLoserCount;               // +0x5020
    Value<int> BootyPopupDuration;                   // +0x5078
    Value<int> PeriodOfMaidEmployment;               // +0x50d0
    Value<int> MaidReadyToPay;                       // +0x5128
    Value<int> MaidAffinityMax;                      // +0x5180
    Value<unsigned int> MeratRevivalDebuffCode;      // +0x51d8
    Value<unsigned int> MeratConsumeSuperChat;       // +0x5230
    Value<unsigned int> MeratConsumeWorldChat;       // +0x5288
    Value<unsigned int> MeratConsumeChannelChat;     // +0x52e0
    Value<int> HonorTokenMax;                        // +0x5338
    Value<int> KarmaTokenMax;                        // +0x5390
    Value<int> LuTokenMax;                           // +0x53e8
    Value<int> HabiTokenMax;                         // +0x5440
    Value<int> ReverseCoinMax;                       // +0x5498
    Value<int> MentorTokenMax;                       // +0x54f0
    Value<int> MenteeTokenMax;                       // +0x5548
    Value<int> CharacterDestroyDivisionLevel;        // +0x55a0
    Value<int> CharacterDestroyWaitSecond;           // +0x55f8
    Value<unsigned int> PCBangItemDefaultPeriod;     // +0x5650
    Value<float> SwimDashSpeed;                      // +0x56a8
    Value<unsigned int> UserTriggerStateMax;         // +0x5700
    Value<unsigned int> UserTriggerEnterActionMax;   // +0x5758
    Value<unsigned int> UserTriggerConditionMax;     // +0x57b0
    Value<unsigned int> UserTriggerConditionActionMax; // +0x5808
    Value<unsigned int> HomePasswordUsersKickDelay;  // +0x5860
    Value<unsigned int> PCBangAdditionalEffectID;    // +0x58b8
    Value<unsigned int> PCBangAdditionalEffectExp;   // +0x5910
    Value<unsigned int> PCBangAdditionalEffectMeso;  // +0x5968
    Value<int> QuestRewardSAIgnoreLevel;             // +0x59c0
    Value<float> DropSPEPBallTargetZPos;             // +0x5a18
    Value<float> DropSPEPBallMaxLength;              // +0x5a70
    Value<float> DropSPEPBallPickUpVel;              // +0x5ac8
    Value<float> DropSPEPBallPickUpGravity;          // +0x5b20
    Value<float> DropSPEPBallPickUpCompleteRotateTime; // +0x5b78
    Value<float> DropSPEPBallPickUpCompleteRotateVel; // +0x5bd0
    Value<int> BankCallDuration;                     // +0x5c28
    Value<int> RemakeOptionMaxCount;                 // +0x5c80
    Values<int> WarpOpenContinent;                   // +0x5cd8
    Value<int> BlackMarketSellEndDay;                // +0x5d48
    Value<int> MailExpiryDays;                       // +0x5da0
    Value<int> MailExpiryDaysPremium;                // +0x5df8
    Value<int> MailExpiryDaysBlackMarket;            // +0x5e50
    Value<int> MailExpiryDaysFittingDoll;            // +0x5ea8
    Value<__int64> TradeMinMeso;                     // +0x5f00
    Value<__int64> TradeMaxMeso;                     // +0x5f60
    Value<int> TradeFeePercent;                      // +0x5fc0
    Value<__int64> MesoMarketBasePrice;              // +0x6018
    Values<__int64> MesoMarketProductUnit;           // +0x6078
    Value<int> MesoMarketIconType;                   // +0x60e8
    Value<int> MesoMarketBuyPayType;                 // +0x6140
    Value<CString> MesoMarketTokenDetailUrl;         // +0x6198
    Value<unsigned int> BeautyHairShopGotoFieldID;   // +0x61f8
    Value<unsigned int> BeautyHairShopGotoPortalID;  // +0x6250
    Value<unsigned int> BeautyColorShopGotoFieldID;  // +0x62a8
    Value<unsigned int> BeautyColorShopGotoPortalID; // +0x6300
    Value<unsigned int> BeautyFaceShopGotoFieldID;   // +0x6358
    Value<unsigned int> BeautyFaceShopGotoPortalID;  // +0x63b0
    Value<unsigned int> shadowWorldBuffHpUp;         // +0x6408
    Value<unsigned int> shadowWorldBuffMoveProtect;  // +0x6460
    Value<__int64> BeautyStyleExpandSlotPrice;       // +0x64b8
    Value<unsigned int> BeautyStyleExpandSlotCount1time; // +0x6518
    Value<unsigned int> BeautyStyleDefaultSlotCount; // +0x6570
    Value<unsigned int> BeautyStyleMaxSlotCount;     // +0x65c8
    Value<unsigned int> ItemUnLockTime;              // +0x6620
    Value<unsigned int> HomeBankCallDuration;        // +0x6678
    Value<unsigned int> HomeBankCallCooltime;        // +0x66d0
    Value<CString> HomeBankCallSequence;             // +0x6728
    Value<unsigned int> HomeDoctorCallDuration;      // +0x6788
    Value<unsigned int> HomeDoctorCallCooltime;      // +0x67e0
    Value<CString> HomeDoctorCallSequence;           // +0x6838
    Value<unsigned int> HomeDoctorNpcID;             // +0x6898
    Value<int> HomeDoctorScriptID0;                  // +0x68f0
    Value<int> HomeDoctorScriptID1;                  // +0x6948
    Value<int> EnchantMasterScriptID;                // +0x69a0
    Value<int> MergeSmithScriptID;                   // +0x69f8
    Value<int> EnchantTransformScriptID;             // +0x6a50
    Value<int> PropertyProtectionTime;               // +0x6aa8
    Value<unsigned int> RestExpAcquireRate;          // +0x6b00
    Value<unsigned int> RestExpMaxAcquireRate;       // +0x6b58
    Value<unsigned int> ApartmentPreviewRequireLevel; // +0x6bb0
    Value<unsigned int> ApartmentPreviewRequireQuestID; // +0x6c08
    Value<unsigned int> CharacterAbilityDefaultPoint; // +0x6c60
    Value<unsigned int> CharacterAbilityResetCoolTimeMinute; // +0x6cb8
    Value<__int64> CharacterAbilityResetMeso;        // +0x6d10
    Value<__int64> CharacterAbilityResetMerat;       // +0x6d70
    Value<unsigned int> CharacterAbilityOpenQuestID; // +0x6dd0
    Value<unsigned int> KeyboardGuideShowLevel;      // +0x6e28
    int DungeonRoomMaxRewardCount;                   // +0x6e80
    int DungeonMatchRecommendPickCount;              // +0x6e84
    int DungeonSeasonRankMinLevel;                   // +0x6e88
    unsigned char m_pad_6e8c[0x4];
    Value<unsigned int> ResetShadowBuffMerat;        // +0x6e90
    Value<unsigned int> InventoryExpandPrice1Row;    // +0x6ee8
    Value<unsigned int> VIPServicePeriodLimitDay;    // +0x6f40
    Value<unsigned int> BreedDuration;               // +0x6f98
    Value<unsigned int> HarvestDuration;             // +0x6ff0
    Value<unsigned int> RestartQuestStartField;      // +0x7048
    Value<unsigned int> RestartQuestStartFieldRuneBlader; // +0x70a0
    Value<unsigned int> RestartQuestStartFieldStriker; // +0x70f8
    Value<unsigned int> RestartQuestStartFieldSoulBinder; // +0x7150
    Value<float> QuestPortalKeepTime;                // +0x71a8
    Value<CString> QuestPortalKeepNif;               // +0x7200
    Value<float> QuestPortalDimensionY;              // +0x7260
    Value<float> QuestPortalDimensionZ;              // +0x72b8
    Value<unsigned int> QuestPortalSummonTime;       // +0x7310
    Value<unsigned int> QuestPortalDistanceFromNpc;  // +0x7368
    Value<unsigned int> PartyRecallMerat;            // +0x73c0
    Value<__int64> PetChangeNameMerat;               // +0x7418
    Value<CString> VisitorBookURL;                   // +0x7478
    Value<std::vector<unsigned int>> bagSlotTabGameCount; // +0x74d8
    Value<std::vector<unsigned int>> bagSlotTabSkinCount; // +0x7558
    Value<std::vector<unsigned int>> bagSlotTabSummonCount; // +0x75d8
    Value<std::vector<unsigned int>> bagSlotTabMaterialCount; // +0x7658
    Value<std::vector<unsigned int>> bagSlotTabMasteryCount; // +0x76d8
    Value<std::vector<unsigned int>> bagSlotTabLifeCount; // +0x7758
    Value<std::vector<unsigned int>> bagSlotTabQuestCount; // +0x77d8
    Value<std::vector<unsigned int>> bagSlotTabGemCount; // +0x7858
    Value<std::vector<unsigned int>> bagSlotTabPetCount; // +0x78d8
    Value<std::vector<unsigned int>> bagSlotTabPetEquipCount; // +0x7958
    Value<std::vector<unsigned int>> bagSlotTabActiveSkillCount; // +0x79d8
    Value<std::vector<unsigned int>> bagSlotTabMiscCount; // +0x7a58
    Value<std::vector<unsigned int>> bagSlotTabCoinCount; // +0x7ad8
    Value<std::vector<unsigned int>> bagSlotTabBadgeCount; // +0x7b58
    Value<std::vector<unsigned int>> bagSlotTabLapenShardCount; // +0x7bd8
    Value<std::vector<unsigned int>> bagSlotTabPieceCount; // +0x7c58
    Value<float> PetPickDistance;                    // +0x7cd8
    Value<unsigned int> PetSummonCastTime;           // +0x7d30
    Value<unsigned int> PetBoreTime;                 // +0x7d88
    Value<unsigned int> PetIdleTime;                 // +0x7de0
    Value<unsigned int> PetTiredTime;                // +0x7e38
    Value<unsigned int> PetSkillTime;                // +0x7e90
    Value<CString> PetEffectUse;                     // +0x7ee8
    Value<CString> PetEffectSkill;                   // +0x7f48
    Value<CString> PetEffectHappy;                   // +0x7fa8
    Value<CString> PetGemChatBalloon;                // +0x8008
    Value<float> PetTrapAreaDistanceEasy;            // +0x8068
    Value<float> PetTrapAreaDistanceNormal;          // +0x80c0
    Value<float> PetTrapAreaDistanceHard;            // +0x8118
    Value<CString> PetTrapAreaEffectEasy;            // +0x8170
    Value<CString> PetTrapAreaEffectNormal;          // +0x81d0
    Value<CString> PetTrapAreaEffectHard;            // +0x8230
    Value<CString> PetTrapAreaEffectOtherUser;       // +0x8290
    Value<CString> PetTamingMaxPointEffect;          // +0x82f0
    Value<CString> PetTamingAttackMissEffect;        // +0x8350
    Value<CString> PetTrapDropItemEffect;            // +0x83b0
    Value<unsigned int> TamingPetEscapeTime;         // +0x8410
    Value<unsigned int> TamingPetMaxPoint;           // +0x8468
    Value<unsigned int> PetMaxLevel;                 // +0x84c0
    Value<float> PetRunSpeed;                        // +0x8518
    Value<unsigned int> PetTrapDropVisibleDelay;     // +0x8570
    Value<bool> DisableSoloPlayHighLevelDungeon;     // +0x85c8
    Value<int> WebBrowserSizeWidthMin;               // +0x8620
    Value<int> WebBrowserSizeWidthMax;               // +0x8678
    Value<int> WebBrowserSizeHeightMin;              // +0x86d0
    Value<int> WebBrowserSizeHeightMax;              // +0x8728
    Value<bool> WebBrowserEnableSizingButton;        // +0x8780
    Value<CString> LiveBroadcastURL;                 // +0x87d8
    Value<CString> TencentWebURL;                    // +0x8838
    Value<int> MaxChatLength;                        // +0x8898
    Value<unsigned int> CodiTabMaxDay;               // +0x88f0
    Value<int> WebBrowserPopupSizeWidthMin;          // +0x8948
    Value<int> WebBrowserPopupSizeWidthMax;          // +0x89a0
    Value<int> WebBrowserPopupSizeHeightMin;         // +0x89f8
    Value<int> WebBrowserPopupSizeHeightMax;         // +0x8a50
    Value<__int64> MeratAirTaxiPrice;                // +0x8aa8
    Value<int> MentorMaxWaitingCount;                // +0x8b08
    Value<int> MenteeMaxReceivedCount;               // +0x8b60
    Value<unsigned int> SkillBookTreeAddTabFeeMerat; // +0x8bb8
    Value<unsigned int> MentorRequireLevel;          // +0x8c10
    Value<unsigned int> MenteeRequireLevel;          // +0x8c68
    Value<float> MeratRevivalFeeReduceLimit;         // +0x8cc0
    Value<unsigned int> DailyPetEnchantMaxCount;     // +0x8d18
    Values<unsigned int> FameContentsSkyFortressMapID; // +0x8d70
    Value<unsigned int> FameContentsSkyFortressGotoMapID; // +0x8de0
    Value<unsigned int> FameContentsSkyFortressGotoPortalID; // +0x8e38
    Value<unsigned int> FameContentsSkyFortressBridgeID; // +0x8e90
    Value<int> FameContentsMissionAttackCount;       // +0x8ee8
    Value<unsigned int> FameContentsFieldQuestPickAccept; // +0x8f40
    Value<unsigned int> FameContentsFieldQuestPickComplete; // +0x8f98
    Value<unsigned int> UgcMarketNewMusicScoreItemID; // +0x8ff0
    Value<unsigned int> TreewateringEmotion;         // +0x9048
    Value<float> GamePadRumbleMultiple;              // +0x90a0
    float MesoRevivalFeeReduceLimit;                 // +0x90f8
    float IngredientFeeReduceLimit;                  // +0x90fc
    int StatPointLimit_str;                          // +0x9100
    int StatPointLimit_dex;                          // +0x9104
    int StatPointLimit_int;                          // +0x9108
    int StatPointLimit_luk;                          // +0x910c
    int StatPointLimit_hp;                           // +0x9110
    unsigned char m_pad_9114[0x30];
    int StatPointLimit_cap;                          // +0x9144
    unsigned char m_pad_9148[0x48];
    Value<unsigned int> AdventureLevelLvUpRewardItem; // +0x9190
    Value<unsigned int> AdventureLevelLvUpExp;       // +0x91e8
    Value<unsigned int> AdventureLevelMaxExp;        // +0x9240
    Value<unsigned int> AdventureLevelStartLevel;    // +0x9298
    Value<unsigned int> AdventureLevelLimit;         // +0x92f0
    Value<unsigned int> unusedUInt9348;              // +0x9348
    Value<unsigned int> ConstructExpMaxCount;        // +0x93a0
    Value<unsigned int> NurturingEatMaxCount;        // +0x93f8
    Value<unsigned int> NurturingPlayMaxCount;       // +0x9450
    Value<CStringW> NurturingQuestTag;               // +0x94a8
    Value<unsigned int> NurturingDuration;           // +0x9508
    Value<unsigned int> NurturingInteractionDistance; // +0x9560
    Value<unsigned int> NurturingEatGrowth;          // +0x95b8
    Value<unsigned int> NurturingPlayGrowth;         // +0x9610
    Value<unsigned int> NurturingPlayMaxGrowth;      // +0x9668
    Value<unsigned int> NurturingHungryTime;         // +0x96c0
    unsigned short SkillPointLimitLevel1;            // +0x9718
    unsigned short SkillPointLimitLevel2;            // +0x971a
    unsigned char m_pad_971c[0x4];
    Value<unsigned int> EnchantEquipIngredientMaxCount; // +0x9720
    Value<int> EnchantEquipIngredientOpenRank;       // +0x9778
    Value<int> EnchantEquipIngredientOpenLevel;      // +0x97d0
    Value<unsigned int> EnchantFailStackUsingMaxCount; // +0x9828
    Value<unsigned int> EnchantFailStackTakeMaxCount; // +0x9880
    Value<int> EnchantFailStackOpenLevel;            // +0x98d8
    Value<unsigned int> EnchantFailStackTakeMaxSuccessProb; // +0x9930
    Value<unsigned int> EnchantEquipIngredientMaxSuccessProb; // +0x9988
    Value<unsigned int> EnchantItemBindingRequireLevel; // +0x99e0
    Value<unsigned int> HomePVPRevivalItemId;        // +0x9a38
    int SummonRideSkillID;                           // +0x9a90
    int HoldAttackSkillID;                           // +0x9a94
    int GlideItemSkillID;                            // +0x9a98
    int GmGlideSkillID;                              // +0x9a9c
    Value<unsigned int> SellPriceNormalMax;          // +0x9aa0
    Value<unsigned int> SellPriceRareMax;            // +0x9af8
    Value<unsigned int> SellPriceEliteMax;           // +0x9b50
    Value<unsigned int> SellPriceExcellentMax;       // +0x9ba8
    Value<unsigned int> SellPriceLegendaryMax;       // +0x9c00
    Value<unsigned int> SellPriceArtifactMax;        // +0x9c58
    Value<int> PetNameLengthMin;                     // +0x9cb0
    Value<int> PetNameLengthMax;                     // +0x9d08
    Value<int> GuildNameLengthMin;                   // +0x9d60
    Value<int> GuildNameLengthMax;                   // +0x9db8
    Value<int> ClubNameLengthMin;                    // +0x9e10
    Value<int> ClubNameLengthMax;                    // +0x9e68
    Value<int> UgcNameLengthMin;                     // +0x9ec0
    Value<int> UgcNameLengthMax;                     // +0x9f18
    Value<int> UgcTagLengthMax;                      // +0x9f70
    Value<unsigned int> ChangeJobLevel;              // +0x9fc8
    CAtlArray<Value<unsigned int>*> tierItems;       // +0xa020
    Value<std::vector<unsigned int>> LapenShardOpenQuestID; // +0xa040
    Value<int> MaidNameLengthMin;                    // +0xa0c0
    Value<int> MaidNameLengthMax;                    // +0xa118
    Value<int> MaidDescLengthMin;                    // +0xa170
    Value<int> MaidDescLengthMax;                    // +0xa1c8
    Value<unsigned int> gemPetSkinBaseItemID;        // +0xa220
    bool LimitMeratRevival;                          // +0xa278
    unsigned char m_pad_a279[0x3];
    int MaxClosetMaxCount;                           // +0xa27c
    int MaxClosetTabNameLength;                      // +0xa280
    int SummonPetSkillID;                            // +0xa284
    Value<int> UGCMapSetItemEffectCountLimit;        // +0xa288
    int StatScaleMarkingAdditionalEffect;            // +0xa2e0
    unsigned char m_pad_a2e4[0x4];
    Value<int> ItemBoxMultiOpenMaxCount;             // +0xa2e8
    Value<int> ItemBoxMultiOpenLimitCount;           // +0xa340
    Value<unsigned int> WeddingProposeItemID;        // +0xa398
    Value<unsigned int> WeddingInvitationMaxCount;   // +0xa3f0
    Value<unsigned int> WeddingProposeCooltime;      // +0xa448
    Value<unsigned int> WeddingDivorceFieldID;       // +0xa4a0
    Value<unsigned int> WeddingInvitationMeso;       // +0xa4f8
    Value<unsigned int> WeddingDivorceMeso;          // +0xa550
    Value<unsigned int> WeddingCoolingOffDay;        // +0xa5a8
    Value<unsigned int> WeddingPromiseLimitDay;      // +0xa600
    Value<unsigned int> WeddingHallModifyLimitHour;  // +0xa658
    Value<unsigned int> WeddingDivorceRequireMarriageDay; // +0xa6b0
    Value<int> PaybackStartDate;                     // +0xa708
    Value<int> PaybackEndDate;                       // +0xa760
    Value<std::vector<int>> unusedIntList;           // +0xa7b8
    Value<int> PaybackRewardMinutes;                 // +0xa838
    Value<unsigned int> DeleteAccountPendingDay;     // +0xa890
    Value<unsigned short> AdventureProtectedRequireLevel; // +0xa8e8
    Value<unsigned int> AdventureProtectedRequireQuest; // +0xa940
    Value<int> AdventureProtectedCharCreateTime;     // +0xa998
    Value<int> PvpOnePunchRewardItem;                // +0xa9f0
    Value<int> PvpOnePunchRewardCount[10];           // +0xaa48
    Value<int> PvpOnePunchScoreNpcKill;              // +0xadb8
    Value<float> BothHandGearScorePenaltyDiv;        // +0xae10
};
}
MS2_CHECK_SIZE(Common::Constants::Object,0x50);
MS2_CHECK_SIZE(Common::Constants::Value<int>,0x58);
MS2_CHECK_SIZE(Common::Constants::Value<__int64>,0x60);
MS2_CHECK_SIZE(Common::Constants::Value<CString>,0x60);
MS2_CHECK_SIZE(Common::Constants::Value<efd::Point3>,0x68);
MS2_CHECK_SIZE(Common::Constants::Value<std::vector<int> >,0x80);
MS2_CHECK_SIZE(Common::Constants::Value<MS2Colors>,0x90);
MS2_CHECK_SIZE(Common::Constants::Values<int>,0x70);
MS2_CHECK_SIZE(Common::Constants,0xae68);
MS2_CHECK_OFFSET(Common::Constants,ConstructUgcDistance,0x1030);

namespace Client {
class Constants : public Common::Constants, public TSingleton<Constants> {
public:
    Constants();
    virtual void vfunc_0();
    virtual ~Constants();
    static Client::Constants* GetInstance() { return s_instance; }

    Value<Unk_ConstColor> NameTagColorFriendly;            // +0xae70
    Value<Unk_ConstColor> NameTagColorMob;                 // +0xaec8
    Value<Unk_ConstColor> NameTagColorLeader;              // +0xaf20
    Value<Unk_ConstColor> NameTagColorNamed;               // +0xaf78
    Value<Unk_ConstColor> NameTagColorBoss;                // +0xafd0
    Value<Unk_ConstColor> NameTagColorMyPC;                // +0xb028
    Value<Unk_ConstColor> NameTagColorPC;                  // +0xb080
    Value<Unk_ConstColor> NameTagColorPCHostile;           // +0xb0d8
    Value<Unk_ConstColor> NameTagColorParty;               // +0xb130
    Value<Unk_ConstColor> NameTagColorDead;                // +0xb188
    Value<MS2Colors> job;                            // +0xb1e0
    Value<Unk_ConstColor> meso;                            // +0xb270
    Value<Unk_ConstColor> merat;                           // +0xb2c8
    Value<Unk_ConstColor> meratCancel;                     // +0xb320
    Value<MS2Colors> categoryColor;                  // +0xb378
    Value<Unk_ConstColor> exp;                             // +0xb408
    Values<Unk_ConstColor> outlineColor;                   // +0xb460
    Value<float> outlineBoost;                       // +0xb4d0
    Value<Unk_ConstColor> chatUserNormal;                  // +0xb528
    Value<Unk_ConstColor> chatUserNotice;                  // +0xb580
    Value<Unk_ConstColor> chatUserWhisper;                 // +0xb5d8
    Value<Unk_ConstColor> chatUserMapNotice;               // +0xb630
    Value<Unk_ConstColor> chatUserParty;                   // +0xb688
    Value<Unk_ConstColor> chatUserGuild;                   // +0xb6e0
    Value<Unk_ConstColor> chatUserSuper;                   // +0xb738
    Value<Unk_ConstColor> chatUserWorld;                   // +0xb790
    Value<Unk_ConstColor> chatUserChannel;                 // +0xb7e8
    Value<Unk_ConstColor> chatUserClub;                    // +0xb840
    Value<Unk_ConstColor> chatTextNormal;                  // +0xb898
    Value<Unk_ConstColor> chatTextNotice;                  // +0xb8f0
    Value<Unk_ConstColor> chatTextMapNotice;               // +0xb948
    Value<Unk_ConstColor> chatTextWhisperTo;               // +0xb9a0
    Value<Unk_ConstColor> chatTextWhisperFail;             // +0xb9f8
    Value<Unk_ConstColor> chatTextWhisperFrom;             // +0xba50
    Value<Unk_ConstColor> chatTextParty;                   // +0xbaa8
    Value<Unk_ConstColor> chatTextGuild;                   // +0xbb00
    Value<Unk_ConstColor> chatTextSuper;                   // +0xbb58
    Value<Unk_ConstColor> chatTextWorld;                   // +0xbbb0
    Value<Unk_ConstColor> chatTextChannel;                 // +0xbc08
    Value<Unk_ConstColor> chatTextSystemMessage;           // +0xbc60
    Value<Unk_ConstColor> chatTextMinorSystemMessage;      // +0xbcb8
    Value<Unk_ConstColor> chatTextGMColor;                 // +0xbd10
    Value<Unk_ConstColor> chatTextClub;                    // +0xbd68
    Value<int> EnableSkillJumpDown;                  // +0xbdc0
    Value<float> SkillGlobalCooldown;                // +0xbe18
    Value<int> SkillGlobalCooldown_CheckSameSkill;   // +0xbe70
    Value<float> NPCColorScale;                      // +0xbec8
    Value<float> NPCDuration;                        // +0xbf20
    Value<float> PCColorScale;                       // +0xbf78
    Value<float> PCDuration;                         // +0xbfd0
    Value<float> GetEXPColorScale;                   // +0xc028
    Value<float> GetEXPDuration;                     // +0xc080
    Value<float> AccumulationRatio;                  // +0xc0d8
    Value<unsigned int> ShopSellConfirmPrice;        // +0xc130
    Value<unsigned int> ShopBuyConfirmPrice;         // +0xc188
    Value<int> ShowKillCountMin;                     // +0xc1e0
    Value<efd::Point3> UgcshopCharCameraLookat;      // +0xc238
    Value<efd::Point3> UgcshopCharCameraPos;         // +0xc2a0
    Value<float> UgcshopCharCameraMinDistance;       // +0xc308
    Value<float> UgcshopCharCameraZoomVelocity;      // +0xc360
    Value<efd::Point3> UgcshopCubeCameraLookat;      // +0xc3b8
    Value<efd::Point3> UgcshopCubeCameraPos;         // +0xc420
    Value<float> UgcshopCubeCameraMinDistance;       // +0xc488
    Value<float> UgcshopCubeCameraZoomVelocity;      // +0xc4e0
    Value<efd::Point3> UgcshopRideeCameraLookat;     // +0xc538
    Value<efd::Point3> UgcshopRideeCameraPos;        // +0xc5a0
    Value<float> UgcshopRideeCameraMinDistance;      // +0xc608
    Value<float> UgcshopRideeCameraZoomVelocity;     // +0xc660
    Value<float> UgcshopCharRotateStartDegreeY;      // +0xc6b8
    Value<int> UgcshopCharRotateEndDegreeY;          // +0xc710
    Value<int> OffsetActionTooltipX;                 // +0xc768
    Value<int> OffsetActionTooltipY;                 // +0xc7c0
    Value<float> DamageEffectMinHPPercent;           // +0xc818
    Value<float> DamageEffectCriticalPercent;        // +0xc870
    Value<int> DamageGap;                            // +0xc8c8
    Value<int> DamageRenderCount;                    // +0xc920
    Value<int> DamageRenderTotalCount;               // +0xc978
    Value<float> DamageOtherScale;                   // +0xc9d0
    Value<float> DamageOtherAlpha;                   // +0xca28
    Value<CString> UserRevivalIconPath;              // +0xca80
    Value<CString> UserRevivalInvincibleIconPath;    // +0xcae0
    Value<CString> UserPortalInvincibleIconPath;     // +0xcb40
    Value<float> BossHpBarAutoDetectRange;           // +0xcba0
    Value<float> BossHpBarDuration;                  // +0xcbf8
    Value<CString> mirrorGuideMoviePath;             // +0xcc50
    Value<CString> hairGuideMoviePath;               // +0xccb0
    Value<CString> makeUpGuideMoviePath;             // +0xcd10
    Value<CString> charCreateGuideMoviePath;         // +0xcd70
    Value<float> FastShimmerRadius;                  // +0xcdd0
    Value<float> FastShimmerHeight;                  // +0xce28
    Value<unsigned int> SmartRecommendNotify_DurationTick; // +0xce80
    Value<unsigned int> KeyIsDownSkill_MaxDurationTick; // +0xced8
    Value<int> WorldmapBossTooltipCount;             // +0xcf30
    Value<int> BossNotifyAbsLevel;                   // +0xcf88
    Value<int> RoomExitWaitSecond;                   // +0xcfe0
    Value<float> BossShimmerScaleUpActiveDistance;   // +0xd038
    Value<float> BossShimmerScaleUpSize;             // +0xd090
    Value<float> BossKillSoundRange;                 // +0xd0e8
    Value<int> ShowNameTagEnchantItemGrade;          // +0xd140
    Value<int> ShowNameTagEnchantLevel;              // +0xd198
    Value<int> MeratMarketHomeBannerShowTick;        // +0xd1f0
    Value<int> ShadowWorldAutoReviveDeadAction;      // +0xd248
    Value<int> GoodIteriorRecommendUICloseTime;      // +0xd2a0
    Value<CString> UGCInfoDetailViewPage;            // +0xd2f8
    Value<int> UGCInfoStoryBookID;                   // +0xd358
    Value<CString> WriteMusicDetailWebPage;          // +0xd3b0
    Value<int> WriteMusicStoryBookID;                // +0xd410
    Value<float> MusicListenInRadius;                // +0xd468
    Value<float> MusicListenOutRadius;               // +0xd4c0
    Value<CString> TriggerEditorHelpURL;             // +0xd518
    Value<float> CashCallMedicLeaveDelay;            // +0xd578
    Value<CString> NoticeDialogUrl;                  // +0xd5d0
    Value<unsigned int> NoticeDialogOpenSeconds;     // +0xd630
    Values<unsigned int> WorldmapSpecialFunctionNpcID; // +0xd688
    Values<CString> WorldmapSpecialFunctionNpcFrame; // +0xd6f8
    Values<CString> WorldmapSpecialFunctionNpcTooltip; // +0xd768
    Value<unsigned int> fisherBoreDuration;          // +0xd7d8
    Values<CString> fishingStartCastingBarText;      // +0xd830
    Values<CString> fishingStartBalloonText;         // +0xd8a0
    Values<CString> fishFightingCastingBarText;      // +0xd910
    Values<CString> fishFightingBalloonText;         // +0xd980
    Value<unsigned int> MinimapScaleSkipDuration;    // +0xd9f0
    Value<unsigned int> MinimapScaleSkipSplitPixel;  // +0xda48
    Value<CString> CashshopFigureAddressPage;        // +0xdaa0
    Value<CString> TencentSecurityWebPage;           // +0xdb00
    Value<CString> TencentCashChargeWebPage;         // +0xdb60
    Value<int> TencentCashChargeWebPageWidth;        // +0xdbc0
    Value<int> TencentCashChargeWebPageHight;        // +0xdc18
    Value<int> NxaCashChargeWebPageWidth;            // +0xdc70
    Value<int> NxaCashChargeWebPageHight;            // +0xdcc8
    Value<unsigned int> extendAutoFishMaxCount;      // +0xdd20
    Value<unsigned int> extendAutoPlayInstrumentMaxCount; // +0xdd78
    Value<float> GatheringObjectMarkOffsetX;         // +0xddd0
    Value<float> GatheringObjectMarkOffsetY;         // +0xde28
    Value<float> BreedingObjectMarkOffsetX;          // +0xde80
    Value<float> BreedingObjectMarkOffsetY;          // +0xded8
    Value<int> UGCAttention;                         // +0xdf30
    Value<int> UGCInfringementCenter;                // +0xdf88
    Value<float> MasteryObjectInteractionDistance;   // +0xdfe0
    Value<CString> CharacterSelectBoreIdleEffect_Ranger; // +0xe038
    Value<CString> CharacterSelectBoreIdleEffect_SoulBinder; // +0xe098
    Value<unsigned int> AutoPressActionKeyDuration;  // +0xe0f8
    Value<unsigned int> GlobalPortalMinLevel;        // +0xe150
    Value<unsigned long> CoupleEffectCheckTick;      // +0xe1a8
    Value<float> CoupleEffectCheckRadius;            // +0xe200
    int BirthdayFieldID;                             // +0xe258
    unsigned char m_pad_e25c[0x4];
    Value<unsigned int> MouseCursorHideTime;         // +0xe260
    Value<float> AutoHideGroupAlpha;                 // +0xe2b8
    Value<unsigned long> AutoHideGroupHitVisibleTick; // +0xe310
    Value<unsigned int> NameColorDeadDuration;       // +0xe368
    Value<CString> ShopProbInfoUrl;                  // +0xe3c0
    Value<CString> RegionServerUrl_de;               // +0xe420
    Value<CString> RegionServerUrl_en;               // +0xe480
    Value<CString> RegionServerUrl_bpo;              // +0xe4e0
    int TooltipLabelMaxWidth;                        // +0xe540
    unsigned char m_pad_e544[0x4];
    CStringW RpgModeMoviePath;                       // +0xe548
    CStringW RoyaleModeMoviePath;                    // +0xe550
    Value<unsigned int> HighlightMenuUsingLevel;     // +0xe558
    Value<int> GamePadStickMoveValue;                // +0xe5b0
    int PartyVoteReadyTagExpireSeconds;              // +0xe608
    unsigned char m_pad_e60c[0x4];
    Value<int> ShieldBarOffsetY;                     // +0xe610
    Value<unsigned int> MouseInteractLimitDistance;  // +0xe668
    Value<unsigned int> AutoInstallEquipmentMinLevel; // +0xe6c0
    Value<unsigned int> AutoInstallEquipmentMaxLevel; // +0xe718
    std::vector<int> PartySearchRegisterComboValues; // +0xe770
    Value<int> WorldMapShadowUsingContinent;         // +0xe788
    std::vector<unsigned int> DungeonRewardFailEmotions; // +0xe7e0
    Value<CString> DiscordAppID;                     // +0xe7f8
    Value<CString> ItemGachaBoxProbabilityUrl;       // +0xe858
    Value<CString> DeleteAccountTermsUrl;            // +0xe8b8
    Value<CString> PersonalInfoAgreementURL;         // +0xe918
    Value<CString> TencentUserConsultationWebPage;   // +0xe978
    Value<CString> TencentPricavyGuideWebPage;       // +0xe9d8
    Value<CString> TencentThirdPartyInformationSharingListWebPage; // +0xea38
};
}
MS2_CHECK_SIZE(Client::Constants,0xea98);
