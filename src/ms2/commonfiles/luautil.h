// luautil.h - CLua / CLua::CLuaContext / CLuaLock (RTTI names): the game's Lua host. A CLua owns one lua_State (inside a
// ref-counted CLuaContext) and wraps the calc*() formula functions of data/lua/Common/common.lua. Header name assumed;
// the formula wrapper names (FUN_<va>) are the exe VAs, the argument roles are invented from the Lua-side names.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cptred.h"

struct lua_State;
class CIngredientContainer;

// The game links its own Lua 5.1 (0x142391870..0x142394830); progress/symbols-engine.tsv only knows the Gamebryo copy
// at 0x1421e2f90.., so the entry points are the unnamed FUN_<va> of that second copy.
#define LUA_GLOBALSINDEX (-10002)
#define LUA_MULTRET (-1)
void FUN_142391870(lua_State*);                                         // lua_close
void FUN_142392210(lua_State*, int, const char*);                       // lua_getfield
int FUN_142392310(lua_State*);                                          // lua_gettop
int FUN_1423926e0(lua_State*, int, int, int);                           // lua_pcall
void FUN_142392770(lua_State*, int);                                    // lua_pushboolean
void FUN_142392790(lua_State*, int (*)(lua_State*), int);               // lua_pushcclosure
void FUN_1423928b0(lua_State*, long long);                              // lua_pushinteger
void FUN_142392980(lua_State*, double);                                 // lua_pushnumber
void FUN_1423929a0(lua_State*, const char*);                            // lua_pushstring
void FUN_142392ec0(lua_State*, int, const char*);                       // lua_setfield
void FUN_142393030(lua_State*, int);                                    // lua_settop
int FUN_142393180(lua_State*, int);                                     // lua_toboolean
long long FUN_1423931e0(lua_State*, int);                               // lua_tointeger
const char* FUN_142393210(lua_State*, int, size_t*);                    // lua_tolstring
double FUN_1423932b0(lua_State*, int);                                  // lua_tonumber
void FUN_142393470(lua_State*);                                         // luaL_openlibs
int FUN_142394530(lua_State*, const char*, size_t, const char*);        // luaL_loadbuffer
int FUN_142394560(lua_State*, const char*);                             // luaL_loadfile
lua_State* FUN_142394830();                                             // luaL_newstate
#define lua_close FUN_142391870
#define lua_getfield FUN_142392210
#define lua_gettop FUN_142392310
#define lua_pcall FUN_1423926e0
#define lua_pushboolean FUN_142392770
#define lua_pushcclosure FUN_142392790
#define lua_pushinteger FUN_1423928b0
#define lua_pushnumber FUN_142392980
#define lua_pushstring FUN_1423929a0
#define lua_setfield FUN_142392ec0
#define lua_settop FUN_142393030
#define lua_toboolean FUN_142393180
#define lua_tointeger FUN_1423931e0
#define lua_tolstring FUN_142393210
#define lua_tonumber FUN_1423932b0
#define luaL_openlibs FUN_142393470
#define luaL_loadbuffer FUN_142394530
#define luaL_loadfile FUN_142394560
#define luaL_newstate FUN_142394830

// The argument block of the OffenseScore / DefenseScore formulas (offsets from the push order; sizes unproved).
struct Unk_OffenseScore
{
    int m_00; int m_04_pad; long long m_08; long long m_10; float m_18; int m_1c_pad; long long m_20; long long m_28;
    long long m_30; long long m_38; float m_40; float m_44; float m_48; int m_4c_pad; long long m_50; long long m_58;
    long long m_60; float m_68; float m_6c; float m_70; float m_74; float m_78; float m_7c; float m_80; float m_84;
    float m_88; float m_8c; float m_90; float m_94; float m_98; int m_9c_pad; long long m_a0; int m_a8; int m_ac_pad;
    long long m_b0; float m_b8; float m_bc;

    // 0x141338cc0 (emitted by uipcinfodialog.cpp): every field but the pads is cleared
    Unk_OffenseScore()
        : m_00(0), m_08(0), m_10(0), m_18(0), m_20(0), m_28(0), m_30(0), m_38(0), m_40(0), m_44(0), m_48(0), m_50(0), m_58(0),
          m_60(0), m_68(0), m_6c(0), m_70(0), m_74(0), m_78(0), m_7c(0), m_80(0), m_84(0), m_88(0), m_8c(0), m_90(0), m_94(0),
          m_98(0), m_a0(0), m_a8(0), m_b0(0), m_b8(0), m_bc(0)
    {
    }
};
struct Unk_DefenseScore
{
    int m_00; int m_04_pad; long long m_08; long long m_10; long long m_18; long long m_20; long long m_28;
    long long m_30; float m_38; float m_3c; float m_40; float m_44; float m_48; float m_4c; float m_50; float m_54;
    float m_58; float m_5c; float m_60; float m_64; long long m_68; long long m_70;

    // 0x141338ba0 (emitted by uipcinfodialog.cpp): m_00 starts at 1, the rest is cleared (m_5c is a float field, filled by UIPCInfoDialog::FUN_141335290)
    Unk_DefenseScore()
        : m_00(1), m_08(0), m_10(0), m_18(0), m_20(0), m_28(0), m_30(0), m_38(0), m_3c(0), m_40(0), m_44(0), m_48(0), m_4c(0),
          m_50(0), m_54(0), m_58(0), m_5c(0), m_60(0), m_64(0), m_68(0), m_70(0)
    {
    }
};

class CLua
{
public:
    class CLuaContext;
    typedef MS2Ptr<CLuaContext> ContextPtr;

    CLua();                                             // 0x140672770
    virtual ~CLua();                                    // 0x1406727e0
    virtual bool vfunc_1();                             // 0x1406731f0 BindFunctions: load the scripts and validate them
    virtual bool IsClient();                            // 0x14067bc80 in CLuaClient (false)
    virtual void Validate();                            // 0x140673450 calls every formula once with zeros
    virtual ContextPtr GetContext(); // 0x140673670 creates the context on first use

    bool IsReady();                                     // 0x1406733f0
    bool SetLocale(const CString& strLocale);           // 0x140673ca0
    CString GetLocale();                                // 0x140673e10
    int Round(double dValue, int nDigits);              // 0x140673fb0
    int Round(double dValue);                           // 0x140674040
    int Truncate(double dValue, int nDigits);           // 0x140674080
    double Clamp(double dValue, double dMin, double dMax);          // 0x14067b7c0
    bool LoadScripts(lua_State* pLuaState);             // 0x1406737a0
    void Update();                                      // 0x140673330 reload when a script changed

    // the calc* formulas of common.lua
    float CalcMsiR(long long a, int unused);
    float CalcRmsiR(long long a);
    float CalcPcAsiR(long long a, float b);
    float CalcNpcAsiR(long long a, float b);
    float FUN_1406747a0(int nJob, long long a, long long b, long long c, long long d, long long e);
    float FUN_140674a70(long long a, float f, long long b);
    long long CalcMarketRegisterFee(int a, const CString& str);
    bool CalcMarketSellPriceMinMaxMusicScore(const CString& str, long long* pMin, long long* pMax);
    long long CalcBlackMarketBuyFeeCost(long long a, int b, int c, int d);
    float CalcBlackMarketCostRate(int a);
    long long CalcBlackMarketRegisterDeposit(long long a);
    float CalcBlackMarketRegisterDepositPercent();
    long long CalcBlackMarketRegisterDepositMax();
    int CalcResolvePaneltyPrice(unsigned short a, int b, int c);
    double CalcKillCountBonusExpRate(int a);
    int CalcKillCountGrade(int a);
    CString CalcKillCountMsg(int a);
    unsigned int CalcKillCount(unsigned short a, unsigned short b, unsigned int c, int d);
    long long CalcSendMailFee(long long a, long long b, long long c, long long d, long long e, long long f, long long g);
    int CalcNpcSpawnWeight(int a, int b, int c, int d);
    int CalcTaxiCharge(int a, unsigned short b);
    int CalcAirTaxiCharge(unsigned short a);
    int CalcRevivalMerat(unsigned short a, unsigned int b);
    int CalcManufactureCompleteByMerat(int a);
    int CalcGetExtendCapacity(int a);
    long long CalcGetExtendCapacityPrice(int a);
    int CalcGuildFundMax(int a);
    int CalcGuildSkillCost(int a, int b, int c);
    int CalcRevivalMeso(unsigned short a, unsigned int b, int c);
    int GetMesoRevivalDailyMaxCount();
    void CalcMeratSkinItemBreakReward(unsigned short a, int b, long long c, int d, CIngredientContainer& rRewards);
    unsigned int CalcMeratSkinItemBreakRefundPercent();
    bool CalcItemSocketMaxCount(int a, int b, unsigned short c, int d, int* pOut);
    unsigned int CalcGatheringReceipeRewardItemCount(unsigned int a, unsigned int b, unsigned int c);
    unsigned int CalcCraftReceipeRequireItemCount(unsigned int a, unsigned int b, unsigned int c);
    double CalcGatheringObjectgSuccessProp(unsigned int a, unsigned int b, unsigned int c);
    unsigned int CalcGatheringObjectgMaxCount(unsigned int a, unsigned int b);
    unsigned int CalcGatheringActionCount(float f, unsigned int a, unsigned int b, unsigned int c, unsigned int d);
    void CalcOHItemAdditionalLevel(unsigned int a, unsigned int b, unsigned int c, unsigned int d, int* pOut1, int* pOut2);
    int CalcUnlimitedEnchantItemLevel(int a, int b, int c);
    unsigned short CalcLapenshardLevel(unsigned short a, unsigned short b, unsigned short c);
    int CalcTamingPetRank(unsigned short a);
    long long CalcPetExp(long long a, unsigned short b);
    void CalcPetEnchantExp(int a, int b, unsigned short c, long long d, unsigned int e, unsigned int f, unsigned short g,
                       long long* pOut1, long long* pOut2);
    long long CalcPetEnchantBookCost(int a);
    long long CalcPetEnchantCost(int a, int b, unsigned short c, long long d);
    long long CalcPetEvolutionCost(int a);
    unsigned short CalcPetEvolutionResultLevel(int a, unsigned short b);
    long long CalcItemMergeRevertMeso(int a, int b);
    int CalcItemMergeMaterialCount(int a, unsigned int b);
    long long CalcItemMergeRequireMeso(int a, long long b);
    int CalcQuestRewardFamePoint(int a, int b, int c, int d);
    float CalcQuestRewardExpFactorRateByRank(int a, int b, int c, int d);
    int CalcFameCompletionTicketCount(int a, int b);
    bool CalcBlueprintCreateCost(int* pItem, long long* pPrice);
    int CalcRevivalPrice(unsigned short a);
    long long CalcPcDamage(long long a, long long b, long long c, float d, float e);
    int CalcAvailableSkillPoint(unsigned short a);
    unsigned int CalePcOffenseScore(const Unk_OffenseScore* pScore);
    unsigned int CalePcDefenseScore(const Unk_DefenseScore* pScore);

    bool m_bError;                                      // +0x08 a formula or script failed
    CLockCriticalSection m_lock;                        // +0x10
    ATL::CAtlArray<MS2Ptr<CCacheData> > m_scripts;      // +0x40 the loaded script files (change tracking)
    ContextPtr m_context;                               // +0x60
};
MS2_CHECK_SIZE(CLua, 0x70);

// One lua_State with its call bookkeeping (RTTI CLua::CLuaContext, 0x60 bytes).
class CLua::CLuaContext : public CPtred
{
public:
    // The lock of the state; Lock() records the stack top, Unlock() restores it.
    class CLuaLock : public CLockCriticalSection
    {
    public:
        CLuaLock();                                     // 0x14067b920
        virtual ~CLuaLock();                            // 0x140672980
        virtual void vfunc_1();                         // 0x1406729c0 Lock
        virtual void vfunc_2();                         // 0x140672a20 Unlock
        void SetParent(CLuaContext* pParent);           // 0x140672a80

        CLuaContext* m_pParent;                         // +0x30
    };

    CLuaContext();                                      // 0x140672860
    virtual ~CLuaContext();                             // 0x140672910

    void Select(const char* pszName);                   // 0x140672ad0 push the global function
    void Push(double dValue);                           // 0x140672b30
    void Push(long long nValue);                        // 0x140672b70
    void Push(const char* pszValue);                    // 0x140672bb0
    void Push(bool bValue);                             // 0x140672bf0
    bool Call();                                        // 0x140672c30
    double Number(int nIndex);                          // 0x140672c90
    long long Integer(int nIndex);                      // 0x140672d00
    const char* String(int nIndex);                     // 0x140672d70
    bool Boolean(int nIndex);                           // 0x140672df0
    void Initialize();                                  // 0x140672e80
    void Begin();                                       // 0x140672fd0
    void End();                                         // 0x140673010
    void Error();                                       // 0x140673040 reports and throws
    void SetLocale();                                   // 0x140673150

    int m_nTop;                                         // +0x18
    int m_nNumParam;                                    // +0x1c
    lua_State* m_pState;                                // +0x20
    CLuaLock m_lock;                                    // +0x28
};
MS2_CHECK_SIZE(CLua::CLuaContext, 0x60);
