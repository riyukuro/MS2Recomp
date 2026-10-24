// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The Lua property handler for ecr::AttachNifData that MS2
// injected into the ecr SWIG wrapper: egf::SwigPropHandler<ecr::AttachNifData, swig_type_info>, plus the
// ParameterList/Entity template instances it pulls in and the wrapper's static _SWIG_Lua_AddMetatable. The engine-stage
// ecr wrapper (gb:ecr/AttachedNifAsset_LuaWrap_Release) has no AttachNifData handler, so these exe copies have no
// engine-stage pair.
// MS2-UNIT: lib_ecrlua_tail
// MS2-RANGE: 0x1420532b0-0x142053bd9 .text$mn
// MS2-RANGE: 0x1420544e0-0x142054884 .text$mn
// MS2-RANGE: 0x142054c40-0x142054e68 .text$mn
// MS2-RANGE: 0x142054fe0-0x1420550d9 .text$mn
// MS2-FLAGS: gamebryo
// MS2-PIN: ??$AddParameter@VAttachNifData@ecr@@@ParameterList@efd@@QEAAHAEBVAttachNifData@ecr@@@Z 0x1420532b0
// MS2-PIN: ??$AddParameter@VAttachNifData@ecr@@@ParameterList@efd@@QEAAHAEBVutf8string@1@AEBVAttachNifData@ecr@@@Z 0x142053340
// MS2-PIN: ??$CachePropertyValue@VAttachNifData@ecr@@@Entity@egf@@IEAAXIAEBVAttachNifData@ecr@@@Z 0x142053420
// MS2-PIN: ??$CachePropertyValue@VAttachNifData@ecr@@@Entity@egf@@IEAAXIAEBVutf8string@efd@@AEBVAttachNifData@ecr@@@Z 0x1420535c0
// MS2-PIN: ??$GetDefaultPropertyValue@VAttachNifData@ecr@@@Entity@egf@@QEBA?AW4PropertyResult@1@IAEBVutf8string@efd@@AEAVAttachNifData@ecr@@@Z 0x142053860
// MS2-PIN: ??$GetParameter@VAttachNifData@ecr@@@ParameterList@efd@@QEBA?AW4ParameterResult@1@IAEAVAttachNifData@ecr@@@Z 0x142053880
// MS2-PIN: ??$SetParameterData@VAttachNifData@ecr@@@ParameterList@efd@@IEAAXAEBVAttachNifData@ecr@@AEAVArchive@1@@Z 0x1420539e0
// MS2-PIN: ??$SetPropertyValue@VAttachNifData@ecr@@@Entity@egf@@QEAA?AW4PropertyResult@1@IAEBVAttachNifData@ecr@@@Z 0x142053a30
// MS2-PIN: ?GetDefaultProperty@?$SwigPropHandler@VAttachNifData@ecr@@Uswig_type_info@@@egf@@UEAA?AW4PropertyResult@2@PEAVEntity@2@IAEBVutf8string@efd@@PEAUlua_State@@AEAH@Z 0x1420544e0
// MS2-PIN: ?GetParameter@?$SwigPropHandler@VAttachNifData@ecr@@Uswig_type_info@@@egf@@UEAAHPEAVParameterList@efd@@IPEAUlua_State@@@Z 0x142054600
// MS2-PIN: ?GetProperty@?$SwigPropHandler@VAttachNifData@ecr@@Uswig_type_info@@@egf@@UEAA?AW4PropertyResult@2@PEAVEntity@2@IAEBVutf8string@efd@@PEAUlua_State@@AEAH@Z 0x142054770
// MS2-PIN: ?SetParameter@?$SwigPropHandler@VAttachNifData@ecr@@Uswig_type_info@@@egf@@UEAA_NPEAVParameterList@efd@@AEBVutf8string@4@PEAUlua_State@@H@Z 0x142054c40
// MS2-PIN: ?SetProperty@?$SwigPropHandler@VAttachNifData@ecr@@Uswig_type_info@@@egf@@UEAA?AW4PropertyResult@2@PEAVEntity@2@IAEBVutf8string@efd@@PEAUlua_State@@H@Z 0x142054db0
// MS2-PIN: ??_7AttachNifData@ecr@@6B@ 0x1430b44b0
// MS2-PIN: ?_SWIG_Lua_AddMetatable@@YAXPEAUlua_State@@PEAUswig_type_info@@@Z 0x142054fe0
#define MS2_THIS_FILE ""
#define MS2_ENTITY_PROPERTY_CACHE
#include "ms2/placeholder/ms2stdafx.h"
#include <efd/ParameterList.h>
#include <egf/Entity.h>
#include <ecr/AttachNifData.h>
#include <egfLua/ILuaPropertyHandler.h>

// The Lua 5.1 API the handler uses (lua.h is not on the engine include path; the exe's Lua is built as C++).
typedef int (*lua_CFunction)(lua_State* L);
void lua_pushnil(lua_State* L);
void lua_pushstring(lua_State* L, const char* s);
void lua_rawget(lua_State* L, int idx);
void lua_rawset(lua_State* L, int idx);
void lua_remove(lua_State* L, int idx);
void lua_settop(lua_State* L, int idx);
void lua_createtable(lua_State* L, int narr, int nrec);
int lua_type(lua_State* L, int idx);
int lua_setmetatable(lua_State* L, int objindex);
void* lua_newuserdata(lua_State* L, size_t sz);
int lua_error(lua_State* L);

#define LUA_REGISTRYINDEX (-10000)
#define LUA_TTABLE 5

// The SWIG 1.3 Lua runtime types the wrapper defines locally.
struct swig_cast_info;
typedef struct swig_type_info* (*swig_dycast_func)(void**);
struct swig_type_info
{
    const char* name;
    const char* str;
    swig_dycast_func dcast;
    swig_cast_info* cast;
    void* clientdata;   // swig_lua_class*
    int owndata;
};

struct swig_lua_class
{
    const char* name;
    // type, constructor, destructor, methods, attributes, bases, base_names follow
};

struct swig_lua_userdata
{
    swig_type_info* type;
    int own;
    void* ptr;
};

#define SWIG_IsOK(r) (r >= 0)

// SWIG_Lua_ConvertPtr: the identical-code-folded copy the exe calls from every wrapper.
int FUN_142054a70(lua_State* L, int index, void** ptr, swig_type_info* type, int flags);
#define SWIG_ConvertPtr(L, idx, ptr, type, flags) FUN_142054a70(L, idx, ptr, type, flags)

// SWIG_Lua_get_class_registry: pushes the "SWIG" registry table, creating it on first use.
static __forceinline void SWIG_Lua_get_class_registry(lua_State* L)
{
    lua_pushstring(L, "SWIG");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_type(L, -1) != LUA_TTABLE)
    {
        lua_settop(L, -2);
        lua_pushstring(L, "SWIG");
        lua_createtable(L, 0, 0);
        lua_rawset(L, LUA_REGISTRYINDEX);
        lua_pushstring(L, "SWIG");
        lua_rawget(L, LUA_REGISTRYINDEX);
    }
}

// SWIG_Lua_get_class_metatable: pushes the metatable registered for class cname.
static __forceinline void SWIG_Lua_get_class_metatable(lua_State* L, const char* cname)
{
    SWIG_Lua_get_class_registry(L);
    lua_pushstring(L, cname);
    lua_rawget(L, -2);
    lua_remove(L, -2);
}

// _SWIG_Lua_AddMetatable: gives a new userdata its class metatable, if the class has one.
// @0x142054fe0
static void _SWIG_Lua_AddMetatable(lua_State* L, swig_type_info* type)
{
    if (type->clientdata)
    {
        SWIG_Lua_get_class_metatable(L, ((swig_lua_class*)type->clientdata)->name);
        if (lua_type(L, -1) == LUA_TTABLE)
            lua_setmetatable(L, -2);
        else
            lua_settop(L, -2);
    }
}

static __forceinline void SWIG_Lua_NewPointerObj(lua_State* L, void* ptr, swig_type_info* type, int own)
{
    if (!ptr)
    {
        lua_pushnil(L);
        return;
    }
    swig_lua_userdata* usr = (swig_lua_userdata*)lua_newuserdata(L, sizeof(swig_lua_userdata));
    usr->ptr = ptr;
    usr->type = type;
    usr->own = own;
    _SWIG_Lua_AddMetatable(L, type);
}
#define SWIG_NewPointerObj(L, ptr, type, owner) SWIG_Lua_NewPointerObj(L, (void*)ptr, type, owner)

// MS2's SDK let `new T()` of a MemObject reach MemObject::operator new(size_t, MemHint) with the hint defaulted
// (the exe passes MemHint 0); this engine tree has no default, so the handler's external news are spelled EE_NEW here.
#undef EE_EXTERNAL_NEW
#define EE_EXTERNAL_NEW EE_NEW
#include <egfLua/SwigPropHandler.h>
#undef EE_EXTERNAL_NEW
#define EE_EXTERNAL_NEW new

// The handler and, through it, the out-of-line instances at 0x1420532b0-0x142053bd9.
// MS2-FUNCTIONAL: GetProperty/GetDefaultProperty differ only in frame layout (the exe gives the MemHint temporary's
// address and the new'd pointer two locals, MSVC 14.16 puts one in a home slot); SetParameter differs because the exe
// inlines both AddParameter calls; SetProperty because the exe tail-calls SetPropertyValue/SetPropertyValueUnsafe.
// Only the members are instantiated: the handler's ctor and vftable live with its registration in the wrapper.
typedef egf::SwigPropHandler<ecr::AttachNifData, swig_type_info> AttachNifDataSwigPropHandler;
template egf::PropertyResult AttachNifDataSwigPropHandler::GetDefaultProperty(
    egf::Entity*, egf::PropertyID, const efd::utf8string&, lua_State*, int&);   // 0x1420544e0
template int AttachNifDataSwigPropHandler::GetParameter(efd::ParameterList*, efd::UInt32, lua_State*);   // 0x142054600
template egf::PropertyResult AttachNifDataSwigPropHandler::GetProperty(
    egf::Entity*, egf::PropertyID, const efd::utf8string&, lua_State*, int&);   // 0x142054770
template bool AttachNifDataSwigPropHandler::SetParameter(
    efd::ParameterList*, const efd::utf8string&, lua_State*, int);   // 0x142054c40
template egf::PropertyResult AttachNifDataSwigPropHandler::SetProperty(
    egf::Entity*, egf::PropertyID, const efd::utf8string&, lua_State*, int);   // 0x142054db0
