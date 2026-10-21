// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CLua: the game's Lua host (data/lua/*.lua) and the calc*()
// formula wrappers that the item, market, pet, quest and combat code call.
// MS2-UNIT: commonfiles\luautil.cpp
// MS2-RANGE: 0x1400bb180-0x1400bb240 .text$di
// MS2-RANGE: 0x140672770-0x14067c020 .text$mn
// MS2-RANGE: 0x142c9b580-0x142c9b5b0 .text$yd
// MS2-PIN: ??_7CLuaClient@@6B?$TSingleton@VCLuaClient@@@@@ 0x142d74858
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VCLuaContext@CLua@@@@QEAAAEAV1@PEAVCLuaContext@CLua@@@Z 0x14067ba20 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\luautil.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "luautil.h"
#include "ms2/placeholder/cluaclient.h"
#include "ms2/placeholder/exception.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/commonfiles/commonstruct_wa.h"
#include "ms2/ms2recover.h"
#include <math.h>
#include <algorithm>
#include <efd/MemoryDefines.h>
#include "hook/ms2hook.h"

// Unrecovered helpers.
class Unk_LuaFileSystem { public: char FUN_140398190(); int FUN_1403972f0(const char* pszPath, void** ppBuffer, int* pnSize, int nFlags); };
Unk_LuaFileSystem* FUN_140166420();
void* FUN_140166440();                                                  // the log
void FUN_1401859c0(void* pLog, int nLevel, int nCategory, const wchar_t* pszText);
void FUN_14015eb90(void*, int, int, const wchar_t*, const CString&);   // log with a path argument
CString FUN_14016a5c0(const char* psz, int n);
CString FUN_140188f50(const char* psz, int n);
void FUN_1412751b0(const CStringW&, int);                               // chat/system message
CLua* FUN_1401c0db0();                                                  // the CLuaClient singleton
class Unk_LuaSettings { public: CString FUN_14036d8e0(); };
Unk_LuaSettings* FUN_140166410();
double FUN_1405e6d60(int nBase, int nExp);
int FUN_14088da20(int nPriceType);                                      // the blueprint cost type -> the runtime enum

// The ingredient's tag setter (an inline member of CIngredientInfo in the exe, first instantiated by itemgemstonedata.cpp).
inline void Unk_GemIngredientTag(CIngredientInfo* pInfo, int nTag)
{
    pInfo->m_b = nTag;
}
int FUN_1423933c0(lua_State*, int);                                     // lua_type
#define lua_type FUN_1423933c0

// the sort name table of the market search (one copy per including unit)
static CString s_strSortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

int LuaPrintInfo(lua_State*);
int LuaPrintError(lua_State*);
int LuaPrintWarn(lua_State*);
void LuaPrint(lua_State*, int);
extern "C" double (__cdecl* __imp_floor)(double);          // the exe imports floor from the UCRT

// @0x140672770
CLua::CLua() : m_bError(false) {}

// @0x1406727e0
CLua::~CLua() { m_context = 0; }

// @0x140672860
CLua::CLuaContext::CLuaContext() : m_nTop(0), m_nNumParam(0), m_pState(0), m_lock()
{
    m_lock.SetParent(this);
}

// @0x140672910
CLua::CLuaContext::~CLuaContext()
{
    if (m_pState)
    {
        lua_close(m_pState);
        m_pState = 0;
    }
}

// @0x14067b920
CLua::CLuaContext::CLuaLock::CLuaLock() {}

// @0x140672980
CLua::CLuaContext::CLuaLock::~CLuaLock() { m_pParent = 0; }

// @0x1406729c0
void CLua::CLuaContext::CLuaLock::vfunc_1()
{
    CLockCriticalSection::vfunc_1();
    MS2_ASSERT_AT(0x89, m_pParent);
    m_pParent->Begin();
}

// @0x140672a20
void CLua::CLuaContext::CLuaLock::vfunc_2()
{
    MS2_ASSERT_AT(0x90, m_pParent);
    m_pParent->End();
    CLockCriticalSection::vfunc_2();
}

// @0x140672a80
void CLua::CLuaContext::CLuaLock::SetParent(CLuaContext* pParent)
{
    m_pParent = pParent;
    MS2_ASSERT_AT(0x76, m_pParent);
}

// @0x140672ad0
void CLua::CLuaContext::Select(const char* pszName)
{
    MS2_ASSERT_AT(0xdf, m_nNumParam == 0);
    lua_getfield(m_pState, LUA_GLOBALSINDEX, pszName);
}

// @0x140672b30
void CLua::CLuaContext::Push(double dValue)
{
    lua_pushnumber(m_pState, dValue);
    ++m_nNumParam;
}

// @0x140672b70
void CLua::CLuaContext::Push(long long nValue)
{
    lua_pushinteger(m_pState, nValue);
    ++m_nNumParam;
}

// @0x140672bb0
void CLua::CLuaContext::Push(const char* pszValue)
{
    lua_pushstring(m_pState, pszValue);
    ++m_nNumParam;
}

// @0x140672bf0
void CLua::CLuaContext::Push(bool bValue)
{
    lua_pushboolean(m_pState, bValue);
    ++m_nNumParam;
}

// @0x140672c30
bool CLua::CLuaContext::Call()
{
    try
    {
        if (lua_pcall(m_pState, m_nNumParam, LUA_MULTRET, 0))
            Error();
    }
    catch (...)
    {
        return false;
    }
    return true;
}

// @0x140672c90
double CLua::CLuaContext::Number(int nIndex)
{
    int nTop = lua_gettop(m_pState);
    if (nIndex > nTop)
    {
        MS2_ASSERT_AT(0x11f, 0);
        return 0;
    }
    return lua_tonumber(m_pState, nIndex);
}

// @0x140672d00
long long CLua::CLuaContext::Integer(int nIndex)
{
    int nTop = lua_gettop(m_pState);
    if (nIndex > nTop)
    {
        MS2_ASSERT_AT(299, 0);
        return 0;
    }
    return lua_tointeger(m_pState, nIndex);
}

// @0x140672d70
const char* CLua::CLuaContext::String(int nIndex)
{
    int nTop = lua_gettop(m_pState);
    if (nIndex > nTop)
    {
        MS2_ASSERT_AT(0x137, 0);
        return "";
    }
    return lua_tolstring(m_pState, nIndex, 0);
}

// @0x140672df0
bool CLua::CLuaContext::Boolean(int nIndex)
{
    int nTop = lua_gettop(m_pState);
    if (nIndex > nTop)
    {
        MS2_ASSERT_AT(0x143, 0);
        return false;
    }
    return lua_toboolean(m_pState, nIndex) > 0;
}

// @0x140672e80
void CLua::CLuaContext::Initialize()
{
    m_pState = luaL_newstate();
    if (m_pState != 0)
    {
        luaL_openlibs(m_pState);
        lua_pushcclosure(m_pState, LuaPrintInfo, 0);
        lua_setfield(m_pState, LUA_GLOBALSINDEX, "print");
        lua_pushcclosure(m_pState, LuaPrintError, 0);
        lua_setfield(m_pState, LUA_GLOBALSINDEX, "printErr");
        lua_pushcclosure(m_pState, LuaPrintWarn, 0);
        lua_setfield(m_pState, LUA_GLOBALSINDEX, "printWarn");
        lua_pushcclosure(m_pState, LuaPrintError, 0);
        lua_setfield(m_pState, LUA_GLOBALSINDEX, "printError");
        FUN_1401c0db0()->LoadScripts(m_pState);
        SetLocale();
    }
    else
    {
        MS2_ASSERT_AT(0xad, 0);
    }
}

// @0x140672fd0
void CLua::CLuaContext::Begin()
{
    m_nTop = lua_gettop(m_pState);
    m_nNumParam = 0;
}

// @0x140673010
void CLua::CLuaContext::End() { lua_settop(m_pState, m_nTop); }

// @0x140673040
void CLua::CLuaContext::Error()
{
    FUN_1401c0db0()->m_bError = true;
    CString strMessage;
    strMessage.Format("[Lua_Err] %s", (const char*)FUN_140188f50(lua_tolstring(m_pState, -1, 0), 0));
    MessageBoxA(0, strMessage, "Lua Error", 0);
    throw Exception(strMessage);
}

// @0x140673150
void CLua::CLuaContext::SetLocale()
{
    CString strLocale = FUN_140166410()->FUN_14036d8e0();
    Select("set_locale");
    Push((const char*)strLocale);
    bool bOk = Call();
    if (!bOk)
    MS2_ASSERT_AT(0xd9, 0);
}

// @0x1406731f0
bool CLua::vfunc_1()
{
    CLuaContext* pContext = GetContext().get();
    if (pContext == 0)
    return false;
    if (Unk_LockGuard guard = m_lock) { __assume(0); }
    else
    {
        if (Unk_LockGuard contextGuard = pContext->m_lock) {}
        else
        {
            if (!LoadScripts(pContext->m_pState))
            return false;
            pContext->SetLocale();
        }
    }
    if (!IsReady())
    return false;
    return true;
}

// @0x140673330
void CLua::Update()
{
    for (unsigned int i = 0; i < m_scripts.GetCount(); ++i)
    {
        if (FUN_1401d1320(m_scripts[i].operator->()))
        {
            if (!vfunc_1())
            FUN_1401859c0(FUN_140166440(), 1, 0xd, L"BindFunctions() failed at Lua::Update");
            return;
        }
    }
}

// @0x1406733f0
bool CLua::IsReady()
{
    m_bError = false;
    Validate();
    return !m_bError;
}

// @0x140673450
void CLua::Validate()
{
    CString strLocale = FUN_140166410()->FUN_14036d8e0();
    CString strCurrent = GetLocale();
    if (strLocale.Compare(strCurrent) != 0)
    {
        MS2_ASSERT_AT(0x207, 0);
        m_bError = true;
        return;
    }
    FUN_140674100(0, 0);
    FUN_140674290(0);
    FUN_140674420(0, 0);
    FUN_1406745e0(0, 0);
    FUN_140674bb0(0, "");
    FUN_140675730(0, 0, 0);
    FUN_140675920(0);
    FUN_140675ab0(0);
    FUN_140675c30(0);
    FUN_140675e00(0, 0, 0, 0);
    FUN_140676020(0, 0, 0, 0, 0, 0, 0);
    FUN_1406762d0(0, 0, 0, 0);
    FUN_1406764e0(0, 0);
}

// @0x140673670
CLua::ContextPtr CLua::GetContext()
{
    if (Unk_LockGuard guard = m_lock) { __assume(0); }
    else
    {
        if (m_context.IsNull())
        {
            m_context.AssignRaw(new CLuaContext);
            if (m_context.get() != 0)
            m_context->Initialize();
        }
        return m_context;
    }
}

// @0x1406737a0
bool CLua::LoadScripts(lua_State* pLuaState)
{
    MS2_ASSERT_AT(0x16b, pLuaState);
    if (!FUN_140166420()->FUN_140398190())
    {
        ATL::CAtlArray<CString> arrPaths;
        arrPaths.Add(CString("./data/lua/Common/common.lua"));
        arrPaths.Add(CString("./data/lua/Client/client.lua"));
        arrPaths.Add(CString("./data/lua/Common/itemOption.lua"));
        m_scripts.RemoveAll();
        for (unsigned int i = 0; i < arrPaths.GetCount(); ++i)
        {
            CString strPath = arrPaths[i];
            CString strFile = FUN_14016a5c0(strPath, 0);
            MS2Ptr<CCacheData> spCache(new CCacheData);
            if (spCache.get() != 0)
            {
                spCache.operator->()->FUN_1401d1160(strPath);
                m_scripts.Add(spCache);
            }
            int nError = luaL_loadfile(pLuaState, strFile) == 0 && lua_pcall(pLuaState, 0, LUA_MULTRET, 0) == 0 ? 0 : 1;
            if (nError != 0)
            {
                FUN_14015eb90(FUN_140166440(), 1, 0x12d, L"Lua script failed", strPath);
                return false;
            }
        }
    }
    else
    {
        CString strPath("./data/lua/Precompiled/luapack64.o");
        CString strName = FUN_14016a5c0(strPath, 0);
        void* pBuffer;
        int nSize[2];
        if (FUN_140166420()->FUN_1403972f0(strPath, &pBuffer, nSize, 0) == 0)
        {
            FUN_14015eb90(FUN_140166440(), 1, 0x12d, L"Lua load failed", strPath);
            return false;
        }
        int nError = luaL_loadbuffer(pLuaState, (const char*)pBuffer, nSize[0], strName) == 0 && lua_pcall(pLuaState, 0, LUA_MULTRET, 0) == 0 ? 0 : 1;
        if (nError != 0)
        {
            efd::_Free(pBuffer, (size_t)-1);
            return false;
        }
        efd::_Free(pBuffer, (size_t)-1);
    }
    return true;
}

// @0x140673ca0
bool CLua::SetLocale(const CString& strLocale)
{
    ContextPtr spContext = GetContext();
    if (spContext.IsNull())
    {
        MS2_ASSERT_AT(0x225, 0);
        return false;
    }
    if (Unk_LockGuard guard = spContext->m_lock) { __assume(0); }
    else
    {
        spContext->Select("set_locale");
        spContext->Push((const char*)strLocale);
        if (!spContext->Call())
        return false;
        return true;
    }
}

// @0x140673e10
CString CLua::GetLocale()
{
    ContextPtr spContext = GetContext();
    if (spContext.IsNull())
    {
        MS2_ASSERT_AT(0x23b, 0);
        return "";
    }
    if (Unk_LockGuard guard = spContext->m_lock) { __assume(0); }
    else
    {
        spContext->Select("get_locale");
        if (!spContext->Call())
        return "";
        return spContext->String(1);
    }
}

// @0x140673fb0
int CLua::Round(double dValue, int nDigits)
{
    double dEps = 1e-06;
    double dScaled = __imp_floor(dValue * FUN_1405e6d60(10, nDigits) + 0.5 + dEps);
    return (int)(dScaled / FUN_1405e6d60(10, nDigits));
}

// @0x140674040
int CLua::Round(double dValue) { return (int)__imp_floor(dValue + 0.9); }

// @0x140674080
int CLua::Truncate(double dValue, int nDigits)
{
    double dEps = 1e-06;
    double dScaled = __imp_floor(dValue * FUN_1405e6d60(10, nDigits) + dEps);
    return (int)(dScaled / FUN_1405e6d60(10, nDigits));
}

// @0x140674100
float CLua::FUN_140674100(long long p2, int unused) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x261, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calc_msiR");
        context->Push((double)p2);
        if (!context->Call()) { return 0; }
        return (float)context->Number(1);
    }
}

// @0x140674290
float CLua::FUN_140674290(long long p2) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x277, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calc_rmsiR");
        context->Push((double)p2);
        if (!context->Call()) { return 0; }
        return (float)context->Number(1);
    }
}

// @0x140674420
float CLua::FUN_140674420(long long p2, float p3) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x28d, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calc_pc_asiR");
        context->Push((double)p2);
        context->Push((double)p3);
        if (!context->Call()) { return 0; }
        return (float)context->Number(1);
    }
}

// @0x1406745e0
float CLua::FUN_1406745e0(long long p2, float p3) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x2a4, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calc_npc_asiR");
        context->Push((double)p2);
        context->Push((double)p3);
        if (!context->Call()) { return 0; }
        return (float)context->Number(1);
    }
}

// @0x1406747a0
float CLua::FUN_1406747a0(int job,long long attack,long long defense,long long level,long long bonus,long long rate) {
    double factor=0.0;
    switch(job) {
        case 1:factor=1.63625;break; case 10:factor=3.78;break; case 20:factor=4.305;break;
        case 30:factor=3.40375;break; case 40:factor=7.34125;break; case 50:factor=6.4575;break;
        case 60:factor=2.03875;break; case 70:factor=0.60375;break; case 80:factor=0.55125;break;
        case 90:factor=3.78;break; case 100:factor=2.03875;break; case 110:factor=3.40375;break;
    }
    if(level<=0) level=1;
    const double maximum=0.4;
    double result=((double)attack*factor+(double)defense*5.3)*0.015/(double)(level<<1);
    result=Clamp(result,0,maximum);
    if(bonus!=0) result+=((double)bonus*5.3*0.015)/(double)(level<<1);
    if(rate!=0) result+=(double)((float)rate/1000.0f);
    return (float)result;
}

// @0x140674a70
float CLua::FUN_140674a70(long long value,float rate,long long bonus) {
    double result=1.0;
    double zero=0;
    double remainder=1.0-(double)rate;
    double scale=(double)value/1000.0;
    result=scale*std::max<double>(remainder,zero);
    result=Clamp(1.0+result,1.0,2.5);
    if(bonus!=0) {
        double zero2=0;
        double remainder2=1.0-(double)rate;
        double scale2=(double)bonus/1000.0;
        result+=scale2*std::max<double>(remainder2,zero2);
    }
    return (float)result;
}

// @0x140674bb0
long long CLua::FUN_140674bb0(int p2, const CString& p3) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x304, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calcMarketRegisterFee");
        context->Push((long long)p2);
        context->Push((const char*)p3);
        if (!context->Call()) { return 0; }
        return (long long)context->Number(1);
    }
}

// @0x140674d70
bool CLua::FUN_140674d70(const CString& p2, long long* p3, long long* p4) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x31c, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calcMarketSellPriceMinMaxMusicScore");
        context->Push((const char*)p2);
        if (!context->Call()) { return 0; }
        *p3 = context->Number(1);
        *p4 = context->Number(2);
        return true;
    }
}

// @0x140674f30
long long CLua::FUN_140674f30(long long p2, int p3, int p4, int p5) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x2eb, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calc_blackMarketBuyFeeCost");
        context->Push((double)p2);
        context->Push((long long)p3);
        context->Push((long long)p4);
        context->Push((long long)p5);
        if (!context->Call()) { return 0; }
        return (long long)context->Number(1);
    }
}

// @0x140675150
float CLua::FUN_140675150(int p2) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x334, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calc_blackMarketCostRate");
        context->Push((long long)p2);
        if (!context->Call()) { return 0; }
        return (float)context->Number(1);
    }
}

// @0x1406752e0
long long CLua::FUN_1406752e0(long long p2) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x34a, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calc_blackMarketRegisterDeposit");
        context->Push((double)p2);
        if (!context->Call()) { return 0; }
        return (long long)context->Number(1);
    }
}

// @0x140675470
float CLua::FUN_140675470() {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x360, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calc_blackMarketRegisterDepositPercent");
        if (!context->Call()) { return 0; }
        return (float)context->Integer(1);
    }
}

// @0x1406755d0
long long CLua::FUN_1406755d0() {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x374, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calc_blackMarketRegisterDepositMax");
        if (!context->Call()) { return 0; }
        return (long long)context->Number(1);
    }
}

// @0x140675730
int CLua::FUN_140675730(unsigned short p2, int p3, int p4) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x388, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calcResolvePaneltyPrice");
        context->Push((double)p2);
        context->Push((double)p3);
        context->Push((double)p4);
        if (!context->Call()) { return 0; }
        return (int)context->Number(1);
    }
}

// @0x140675920
double CLua::FUN_140675920(int p2) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x3a0, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calcKillCountBonusExpRate");
        context->Push((double)p2);
        if (!context->Call()) { return 0; }
        return (double)context->Number(1);
    }
}

// @0x140675ab0
int CLua::FUN_140675ab0(int p2) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x3b6, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calcKillCountGrade");
        context->Push((double)p2);
        if (!context->Call()) { return 0; }
        return (int)context->Number(1);
    }
}

// @0x140675c30
CString CLua::FUN_140675c30(int p3) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x3cc, 0);
        return "";
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calcKillCountMsg");
        context->Push((double)(int)p3);
        if (!context->Call()) { return ""; }
        return context->String(1);
    }
}

// @0x140675e00
unsigned int CLua::FUN_140675e00(unsigned short p2, unsigned short p3, unsigned int p4, int p5) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x3e2, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calcKillCount");
        context->Push((double)p2);
        context->Push((double)p3);
        context->Push((double)p4);
        context->Push((double)p5);
        if (!context->Call()) { return 0; }
        return (unsigned int)context->Number(1);
    }
}

// @0x140676020
long long CLua::FUN_140676020(long long p2, long long p3, long long p4, long long p5, long long p6, long long p7, long long p8) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x3fb, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calcSendMailFee");
        context->Push((double)p2);
        context->Push((double)p3);
        context->Push((double)p4);
        context->Push((double)p5);
        context->Push((double)p6);
        context->Push((double)p7);
        context->Push((double)p8);
        if (!context->Call()) { return 0; }
        return (long long)context->Number(1);
    }
}

// @0x1406762d0
int CLua::FUN_1406762d0(int p2, int p3, int p4, int p5) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x417, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calcNpcSpawnWeight");
        context->Push((double)p2);
        context->Push((double)p3);
        context->Push((double)p4);
        context->Push((double)p5);
        if (!context->Call()) { return 0; }
        return (int)context->Number(1);
    }
}

// @0x1406764e0
int CLua::FUN_1406764e0(int p2, unsigned short p3) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x430, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calcTaxiCharge");
        context->Push((double)p2);
        context->Push((double)p3);
        if (!context->Call()) { return 0; }
        return (int)context->Number(1);
    }
}

// @0x1406766a0
int CLua::FUN_1406766a0(unsigned short p2) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x447, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calcAirTaxiCharge");
        context->Push((double)p2);
        if (!context->Call()) { return 0; }
        return (int)context->Number(1);
    }
}

// @0x140676830
int CLua::FUN_140676830(unsigned short p2, unsigned int p3) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x45d, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calcRevivalMerat");
        context->Push((double)p2);
        context->Push((double)p3);
        if (!context->Call()) { return 0; }
        return (int)context->Number(1);
    }
}

// @0x1406769f0
int CLua::FUN_1406769f0(int p2) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x4a2, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calcManufactureCompleteByMerat");
        context->Push((double)p2);
        if (!context->Call()) { return 0; }
        return (int)context->Number(1);
    }
}

// @0x140676b70
int CLua::FUN_140676b70(int p2) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x4b9, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calcGetExtendCapacity");
        context->Push((double)p2);
        if (!context->Call()) { return 0; }
        return (int)context->Number(1);
    }
}

// @0x140676cf0
long long CLua::FUN_140676cf0(int p2) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x4d0, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calcGetExtendCapacityPrice");
        context->Push((double)p2);
        if (!context->Call()) { return 0; }
        return (long long)context->Number(1);
    }
}

// @0x140676e80
int CLua::FUN_140676e80(int p2) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x4e7, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calcGuildFundMax");
        context->Push((double)p2);
        if (!context->Call()) { return 0; }
        return (int)context->Number(1);
    }
}

// @0x140677000
int CLua::FUN_140677000(int p2, int p3, int p4) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x4fe, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calcGuildSkillCost");
        context->Push((long long)p2);
        context->Push((long long)p3);
        context->Push((long long)p4);
        if (!context->Call()) { return 0x7fffffff; }
        return (int)context->Number(1);
    }
}

// @0x1406771e0
int CLua::FUN_1406771e0(unsigned short p2, unsigned int p3, int p4) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x474, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calcRevivalMeso");
        context->Push((double)p2);
        context->Push((double)p3);
        context->Push((double)p4);
        if (!context->Call()) { return 0; }
        return (int)context->Number(1);
    }
}

// @0x1406773d0
int CLua::FUN_1406773d0() {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x48c, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("getMesoRevivalDailyMaxCount");
        if (!context->Call()) { return 0; }
        return (int)context->Number(1);
    }
}

// @0x140677530
void CLua::FUN_140677530(unsigned short a, int b, long long c, int d, CIngredientContainer& rRewards)
{
    ContextPtr context = GetContext();
    if (!context)
    {
        MS2_ASSERT_AT(0x517, 0);
        return;
    }
    if (Unk_LockGuard guard = context->m_lock) { __assume(0); }
    else
    {
        context->Select("calcMeratSkinItemBreakReward");
        context->Push((long long)a);
        context->Push((long long)b);
        context->Push(c);
        context->Push((long long)d);
        if (!context->Call())
            return;
        CStringW strMessage(context->String(1));
        int nCount = (int)context->Integer(2);
        if (nCount > 0)
        {
            int nEnd = nCount * 3 + 3;
            for (int i = 3; i < nEnd; i += 3)
            {
                int nItem = (int)context->Integer(i);
                int nAmount = (int)context->Integer(i + 1);
                CString strTag(context->String(i + 2));
                int nTag = FUN_140557640(FUN_140281980(), &strTag);
                Unk_IngRef info(new CIngredientInfo(nItem, nAmount, 0));
                Unk_GemIngredientTag(info.operator->(), nTag);
                rRewards.FUN_14026bca0(info);
            }
        }
    }
}

// @0x140677910
unsigned int CLua::FUN_140677910() {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x543, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calcMeratSkinItemBreakRefundPercent");
        if (!context->Call()) { return 0; }
        return (unsigned int)context->Number(0);
    }
}

// @0x140677a70
bool CLua::FUN_140677a70(int p2, int p3, unsigned short p4, int p5, int *p6) {
    ContextPtr context=GetContext();
    if (!context) {
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calcItemSocketMaxCount");
        context->Push((long long)p2);
        context->Push((long long)p3);
        context->Push((long long)p4);
        context->Push((long long)p5);
        if (!context->Call()) { return 0; }
        *p6 = context->Integer(1);
        return true;
    }
}

// @0x140677c60
unsigned int CLua::FUN_140677c60(unsigned int p2, unsigned int p3, unsigned int p4) {
    ContextPtr context=GetContext();
    if (!context) {
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calcGatheringReceipeRewardItemCount");
        context->Push((long long)p2);
        context->Push((long long)p3);
        context->Push((long long)p4);
        if (!context->Call()) { return 0; }
        return (unsigned int)context->Number(1);
    }
}

// @0x140677e20
unsigned int CLua::FUN_140677e20(unsigned int p2, unsigned int p3, unsigned int p4) {
    ContextPtr context=GetContext();
    if (!context) {
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calcCraftReceipeRequireItemCount");
        context->Push((long long)p2);
        context->Push((long long)p3);
        context->Push((long long)p4);
        if (!context->Call()) { return 0; }
        return (unsigned int)context->Number(1);
    }
}

// @0x140677fe0
double CLua::FUN_140677fe0(unsigned int p2, unsigned int p3, unsigned int p4) {
    ContextPtr context=GetContext();
    if (!context) {
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calcGatheringObjectgSuccessProp");
        context->Push((long long)p2);
        context->Push((long long)p3);
        context->Push((long long)p4);
        context->Push((long long)1);
        if (!context->Call()) { return 0; }
        return (double)context->Number(1);
    }
}

// @0x1406781c0
unsigned int CLua::FUN_1406781c0(unsigned int p2, unsigned int p3) {
    ContextPtr context=GetContext();
    if (!context) {
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calcGatheringObjectgMaxCount");
        context->Push((long long)p2);
        context->Push((long long)p3);
        if (!context->Call()) { return 0; }
        return (unsigned int)context->Number(1);
    }
}

// @0x140678350
unsigned int CLua::FUN_140678350(float p2, unsigned int p3, unsigned int p4, unsigned int p5, unsigned int p6) {
    ContextPtr context=GetContext();
    if (!context) {
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calcGatheringActionCount");
        context->Push((double)p2);
        context->Push((long long)p3);
        context->Push((long long)p4);
        context->Push((long long)p5);
        context->Push((long long)p6);
        if (!context->Call()) { return 0; }
        return (unsigned int)context->Number(1);
    }
}

// @0x140678570
void CLua::FUN_140678570(unsigned int p2, unsigned int p3, unsigned int p4, unsigned int p5, int *p6, int *p7) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x5ec, 0);
        return;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calcOHItemAdditionalLevel");
        context->Push((long long)p2);
        context->Push((long long)p3);
        context->Push((long long)p4);
        context->Push((long long)p5);
        if (!context->Call()) { return; }
        *p6 = context->Integer(1);
        *p7 = context->Integer(2);
    }
}

// @0x140678760
int CLua::FUN_140678760(int p2, int p3, int p4) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x606, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calcUnlimitedEnchantItemLevel");
        context->Push((long long)p2);
        context->Push((long long)p3);
        context->Push((long long)p4);
        if (!context->Call()) { return 0; }
        return (int)context->Integer(1);
    }
}

// @0x140678940
unsigned short CLua::FUN_140678940(unsigned short a,unsigned short b,unsigned short c) {
    ContextPtr context=GetContext(); if(!context) { MS2_ASSERT_AT(0x61e, 0); return 0; }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calcLapenshardLevel"); context->Push((long long)a); context->Push((long long)b); context->Push((long long)c);
        if(!context->Call()) return 0;
        return context->Integer(1)>1 ? context->Integer(1) : 1;
    }
}

// @0x140678b50
int CLua::FUN_140678b50(unsigned short p2) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x636, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calc_TamingPetRank");
        context->Push((long long)p2);
        if (!context->Call()) { return 0; }
        return (int)context->Integer(1);
    }
}

// @0x140678cd0
long long CLua::FUN_140678cd0(long long p2, unsigned short p3) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x6f0, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calc_petExp");
        context->Push((long long)p2);
        context->Push((long long)p3);
        if (!context->Call()) { return 0; }
        return (long long)context->Number(1);
    }
}

// @0x140678e80
void CLua::FUN_140678e80(int p2, int p3, unsigned short p4, long long p5, unsigned int p6, unsigned int p7, unsigned short p8, long long *p9, long long *p10) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x707, 0);
        return;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calc_petEnchantExp");
        context->Push((long long)p2);
        context->Push((long long)p3);
        context->Push((long long)p4);
        context->Push((long long)p5);
        context->Push((long long)p6);
        context->Push((long long)p7);
        context->Push((long long)p8);
        if (!context->Call()) { return; }
        *p9 = context->Integer(1);
        *p10 = context->Integer(2);
    }
}

// @0x1406790e0
long long CLua::FUN_1406790e0(int p2) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x724, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calc_petEnchantBookCost");
        context->Push((long long)p2);
        if (!context->Call()) { return 0; }
        return (long long)(int)context->Integer(1);
    }
}

// @0x140679260
long long CLua::FUN_140679260(int p2, int p3, unsigned short p4, long long p5) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x73a, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calc_petEnchantCost");
        context->Push((long long)p2);
        context->Push((long long)p3);
        context->Push((long long)p4);
        context->Push((long long)p5);
        if (!context->Call()) { return 0; }
        return (long long)(int)context->Integer(1);
    }
}

// @0x140679460
long long CLua::FUN_140679460(int p2) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x752, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calc_petEvolutionCost");
        context->Push((long long)p2);
        if (!context->Call()) { return 0; }
        return (long long)context->Integer(1);
    }
}

// @0x1406795e0
unsigned short CLua::FUN_1406795e0(int p2, unsigned short p3) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x767, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calc_petEvolutionResultLevel");
        context->Push((long long)p2);
        context->Push((long long)p3);
        if (!context->Call()) { return 0; }
        return (unsigned short)context->Integer(1);
    }
}

// @0x140679790
long long CLua::FUN_140679790(int p2, int p3) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x64c, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calcItemMergeRevertMeso");
        context->Push((long long)p2);
        context->Push((long long)p3);
        if (!context->Call()) { return 0; }
        return (long long)context->Integer(1);
    }
}

// @0x140679950
int CLua::FUN_140679950(int p2, unsigned int p3) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x663, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calcItemMergeMaterialCount");
        context->Push((long long)p2);
        context->Push((long long)p3);
        if (!context->Call()) { return 0; }
        return (int)context->Integer(1);
    }
}

// @0x140679b00
long long CLua::FUN_140679b00(int p2, long long p3) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x67a, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calcItemMergeRequireMeso");
        context->Push((long long)p2);
        context->Push((long long)p3);
        if (!context->Call()) { return 0; }
        return (long long)context->Integer(1);
    }
}

// @0x140679ca0
int CLua::FUN_140679ca0(int p2, int p3, int p4, int p5) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x691, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calcQuestRewardFamePoint");
        context->Push((long long)p2);
        context->Push((long long)p3);
        context->Push((long long)p4);
        context->Push((long long)p5);
        if (!context->Call()) { return 0; }
        return (int)context->Integer(1);
    }
}

// @0x140679ea0
float CLua::FUN_140679ea0(int p2, int p3, int p4, int p5) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x6aa, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calcQuestRewardExpFactorRateByRank");
        context->Push((long long)p2);
        context->Push((long long)p3);
        context->Push((long long)p4);
        context->Push((long long)p5);
        if (!context->Call()) { return 0; }
        return (float)context->Number(1);
    }
}

// @0x14067a0b0
int CLua::FUN_14067a0b0(int p2, int p3) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x6c3, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calcFameCompletionTicketCount");
        context->Push((long long)p2);
        context->Push((long long)p3);
        if (!context->Call()) { return 0; }
        return (int)context->Number(1);
    }
}

// @0x14067a260
bool CLua::FUN_14067a260(int* item,long long* price) {
    ContextPtr context=GetContext(); if(!context) { MS2_ASSERT_AT(0x6d9, 0); return false; }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calc_blueprintCreateCost"); if(!context->Call()) return false;
        int nItem = (int)context->Integer(1);
        *item = FUN_14088da20(nItem);
        *price = context->Integer(2);
        return true;
    }
}

// @0x14067a3f0
void CLuaClient::Validate()
{
    CLua::Validate();
    FUN_14067a4f0(0);
    FUN_14067a680(0, 0, 0, 0, 0);
}

// @0x14067a440
CLuaClient::CLuaClient() {}

// @0x14067a4a0
CLuaClient::~CLuaClient() {}

// @0x14067bc30
CString Exception::GetText() { return m_message; }

// @0x14067bc80
bool CLuaClient::IsClient() { return false; }

// @0x14067a4f0
int CLua::FUN_14067a4f0(unsigned short p2) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x793, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calcRevivalPrice");
        context->Push((double)p2);
        if (!context->Call()) { return 0; }
        return (int)context->Number(1);
    }
}

// @0x14067a680
long long CLua::FUN_14067a680(long long p2, long long p3, long long p4, float p5, float p6) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x7a9, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calc_pc_damage");
        context->Push((double)p2);
        context->Push((double)p3);
        context->Push((double)p4);
        context->Push((double)p5);
        context->Push((double)p6);
        if (!context->Call()) { return 0; }
        return (long long)context->Number(1);
    }
}

// @0x14067a8d0
int CLua::FUN_14067a8d0(unsigned short p2) {
    ContextPtr context=GetContext();
    if (!context) {
        MS2_ASSERT_AT(0x7c3, 0);
        return 0;
    }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("calcAvailableSkillPoint");
        context->Push((double)p2);
        if (!context->Call()) { return 0; }
        return (int)context->Number(1);
    }
}

// @0x14067aa60
unsigned int CLua::FUN_14067aa60(const Unk_OffenseScore* score) {
    ContextPtr context=GetContext(); if(!context) { MS2_ASSERT_AT(0x7d9, 0); return 0; }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("cale_pc_OffenseScore");
        context->Push((long long)score->m_00);
        context->Push((long long)score->m_08);
        context->Push((long long)score->m_10);
        context->Push((double)score->m_18);
        context->Push((long long)score->m_20);
        context->Push((long long)score->m_28);
        context->Push((long long)score->m_30);
        context->Push((long long)score->m_38);
        context->Push(score->m_40 * 0.01);
        context->Push(score->m_44 * 0.01);
        context->Push(score->m_48 * 0.01);
        context->Push((long long)score->m_50);
        context->Push((long long)score->m_58);
        context->Push((double)score->m_60);
        context->Push(score->m_68 * 0.01);
        context->Push(score->m_6c * 0.01);
        context->Push(score->m_70 * 0.01);
        context->Push(score->m_74 * 0.01);
        context->Push(score->m_78 * 0.01);
        context->Push(score->m_7c * 0.01);
        context->Push(score->m_80 * 0.01);
        context->Push(score->m_84 * 0.01);
        context->Push(score->m_88 * 0.01);
        context->Push(score->m_8c * 0.01);
        context->Push(score->m_90 * 0.01);
        context->Push((double)score->m_94);
        context->Push(score->m_98 * 0.01);
        context->Push((long long)score->m_a0);
        context->Push((long long)score->m_a8);
        context->Push((long long)score->m_b0);
        context->Push(score->m_b8 * 0.01);
        context->Push(score->m_bc * 0.01);
        if(!context->Call()) return 0;
        return (int)context->Number(1);
    }
}

// @0x14067b230
unsigned int CLua::FUN_14067b230(const Unk_DefenseScore* score) {
    ContextPtr context=GetContext(); if(!context) { MS2_ASSERT_AT(0x80f, 0); return 0; }
    if (Unk_LockGuard guard = context->m_lock) {
        __assume(0);
    } else {
        context->Select("cale_pc_DefenseScore");
        context->Push((long long)score->m_00);
        context->Push((long long)score->m_08);
        context->Push((long long)score->m_10);
        context->Push((long long)score->m_18);
        context->Push((long long)score->m_20);
        context->Push((long long)score->m_28);
        context->Push((long long)score->m_30);
        context->Push(score->m_38 * 0.01);
        context->Push(score->m_3c * 0.01);
        context->Push(score->m_40 * 0.01);
        context->Push(score->m_44 * 0.01);
        context->Push(score->m_48 * 0.01);
        context->Push(score->m_4c * 0.01);
        context->Push(score->m_50 * 0.01);
        context->Push(score->m_54 * 0.01);
        context->Push(score->m_58 * 0.01);
        context->Push((double)score->m_60);
        context->Push((double)score->m_64);
        context->Push((long long)score->m_68);
        context->Push((long long)score->m_70);
        if(!context->Call()) return 0;
        return (int)context->Number(1);
    }
}

// @0x14067b740
int LuaPrintInfo(lua_State* pState)
{
    LuaPrint(pState, 0xb);
    return 0;
}

// @0x14067b770
int LuaPrintError(lua_State* pState)
{
    LuaPrint(pState, 1);
    return 0;
}

// @0x14067b7a0
int LuaPrintWarn(lua_State* pState)
{
    LuaPrint(pState, 2);
    return 0;
}

// @0x14067b7c0
double CLua::Clamp(double dValue, double dMin, double dMax)
{
    if (dValue < dMin)
        return dMin;
    if (dValue > dMax)
        return dMax;
    return dValue;
}

// @0x14067bda0
void LuaPrint(lua_State* pState, int nLevel)
{
    CString strMessage;
    if (lua_type(pState, 1) == -1)
    strMessage += "none";
    int nCount = lua_gettop(pState);
    for (int i = 1; i <= nCount; i++)
    {
        if (lua_type(pState, i) == 0)
        strMessage += "nil";
        else if (lua_type(pState, i) == 1)
        strMessage += lua_toboolean(pState, i) ? "true" : "false";
        else if (lua_type(pState, i) == 6)
        strMessage += "function";
        else if (lua_type(pState, i) == 5)
        strMessage += "table";
        else if (lua_type(pState, i) == 2)
        strMessage += "userdata";
        else if (lua_type(pState, i) == 8)
        strMessage += "thread";
        else
        strMessage += lua_tolstring(pState, i, 0);
        if (i != nCount)
        strMessage += " ";
    }
    CStringW strText(L"Lua:");
    strText += strMessage;
    FUN_1401859c0(FUN_140166440(), nLevel, 0xd, strText);
    if (!FUN_1401c0db0()->IsClient())
    FUN_1412751b0(strText, 0x14);
}
