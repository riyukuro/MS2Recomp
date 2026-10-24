// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The Lua property handler for ecr::AttachNifData that MS2
// injected into the ecr SWIG wrapper: egf::SwigPropHandler<ecr::AttachNifData, swig_type_info>, plus the
// ParameterList/Entity template instances it pulls in, the wrapper's static _SWIG_Lua_AddMetatable, the SWIG runtime
// helpers its registration uses (ConvertPtr, GetModule, TypeQueryModule, typename) and the registration itself,
// ecr::lua_ecrInitializePropertyHandlers with its debugger userdata interpreter. The engine-stage ecr wrapper
// (gb:ecr/AttachedNifAsset_LuaWrap_Release) has no AttachNifData handler, so these exe copies have no engine-stage pair.
// MS2-UNIT: lib_ecrlua_tail
// MS2-RANGE: 0x1420532b0-0x142053bd9 .text$mn
// MS2-RANGE: 0x1420544e0-0x142054884 .text$mn
// MS2-RANGE: 0x142054890-0x142054c34 .text$mn
// MS2-RANGE: 0x142054c40-0x142054e68 .text$mn
// MS2-RANGE: 0x142054fe0-0x1420550d9 .text$mn
// MS2-RANGE: 0x142055130-0x1420554ea .text$mn
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
// MS2-PIN: ?IntepretAttachNifUserData@@YA_NPEAUlua_State@@HAEAVutf8string@efd@@@Z 0x142054890
// MS2-PIN: ?SWIG_Lua_GetModule@@YAPEAUswig_module_info@@PEAUlua_State@@@Z 0x142054b60
// MS2-PIN: ?SWIG_Lua_typename@@YAPEBDPEAUlua_State@@H@Z 0x142054bd0
// MS2-PIN: ?SWIG_TypeQueryModule@@YAPEAUswig_type_info@@PEAUswig_module_info@@0PEBD@Z 0x142055320
// MS2-PIN: ?lua_ecrInitializePropertyHandlers@ecr@@YAXPEAUlua_State@@@Z 0x142055130
// MS2-PIN: ??_7?$SwigPropHandler@VAttachNifData@ecr@@Uswig_type_info@@@egf@@6B@ 0x1430bae58
#define MS2_THIS_FILE ""
#define MS2_ENTITY_PROPERTY_CACHE
#include "ms2/placeholder/ms2stdafx.h"
#include <efd/ParameterList.h>
#include <egf/Entity.h>
#include <ecr/AttachNifData.h>
#include <egfLua/ILuaPropertyHandler.h>
#include "ms2/placeholder/schedulerlua.h"
#include "ms2/placeholder/luabehaviordebugger.h"

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
int lua_isuserdata(lua_State* L, int idx);
void* lua_touserdata(lua_State* L, int idx);
const char* lua_tolstring(lua_State* L, int idx, size_t* len);
const char* lua_typename(lua_State* L, int tp);
int luaL_callmeta(lua_State* L, int obj, const char* e);
extern "C" int luaopen_AttachedNifAsset(lua_State* L);
namespace ecr { void lua_ecrInitializePropertyHandlers(lua_State* L); }

#define LUA_REGISTRYINDEX (-10000)
#define LUA_TNIL 0
#define LUA_TLIGHTUSERDATA 2
#define LUA_TTABLE 5

// The SWIG 1.3 Lua runtime types the wrapper defines locally.
struct swig_cast_info;
typedef void* (*swig_converter_func)(void*, int*);
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

struct swig_cast_info
{
    swig_type_info* type;
    swig_converter_func converter;
    swig_cast_info* next;
    swig_cast_info* prev;
};

struct swig_module_info
{
    swig_type_info** types;
    size_t size;
    swig_module_info* next;
    swig_type_info** type_initial;
    swig_cast_info** cast_initial;
    void* clientdata;
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

// SWIG_TypeCheckStruct: the cast entry of `type` that converts from `from`, moved to the head of the list so the
// next lookup of the same pair is the first probe.
static __forceinline swig_cast_info* SWIG_TypeCheckStruct(swig_type_info* from, swig_type_info* type)
{
    swig_cast_info* head = type->cast;
    for (swig_cast_info* c = head; c; c = c->next)
    {
        if (c->type != from)
            continue;
        if (c != head)
        {
            c->prev->next = c->next;
            if (c->next)
                c->next->prev = c->prev;
            c->next = type->cast;
            c->prev = 0;
            if (type->cast)
                type->cast->prev = c;
            type->cast = c;
        }
        return c;
    }
    return 0;
}

// SWIG_Lua_ConvertPtr: the userdata at `index` as a `type` pointer (nil gives a null pointer). This TU's copy is the
// identical-code-folded one the exe calls from every wrapper (flags unused: the runtime has no disown here).
// @0x142054a70
int FUN_142054a70(lua_State* L, int index, void** ptr, swig_type_info* type, int flags)
{
    if (lua_type(L, index) == LUA_TNIL)
    {
        *ptr = 0;
        return 0;
    }
    swig_lua_userdata* usr = (swig_lua_userdata*)lua_touserdata(L, index);
    if (!usr)
        return -1;
    if (!type)
    {
        *ptr = usr->ptr;
        return 0;
    }
    swig_cast_info* cast = SWIG_TypeCheckStruct(usr->type, type);
    if (!cast)
        return -1;
    int newmem = 0;
    *ptr = cast->converter ? cast->converter(usr->ptr, &newmem) : usr->ptr;
    return 0;
}
#define SWIG_ConvertPtr(L, idx, ptr, type, flags) FUN_142054a70(L, idx, ptr, type, flags)

// SWIG_Lua_GetModule: the module list the first loaded wrapper stored in the registry, or null.
// @0x142054b60
static swig_module_info* SWIG_Lua_GetModule(lua_State* L)
{
    swig_module_info* module = 0;
    lua_pushstring(L, "swig_runtime_data_type_pointer4");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_type(L, -1) == LUA_TLIGHTUSERDATA)
        module = (swig_module_info*)lua_touserdata(L, -1);
    lua_settop(L, -2);
    return module;
}

// SWIG_Lua_typename: a SWIG userdata's C type string, else Lua's name for the value's type.
// @0x142054bd0
static const char* SWIG_Lua_typename(lua_State* L, int tp)
{
    if (lua_isuserdata(L, tp))
    {
        swig_lua_userdata* usr = (swig_lua_userdata*)lua_touserdata(L, tp);
        if (usr && usr->type && usr->type->str)
            return usr->type->str;
        return "userdata (unknown type)";
    }
    return lua_typename(L, lua_type(L, tp));
}

// SWIG_TypeNameComp: compares [f1, l1) with [f2, l2), skipping blanks on both sides.
static __forceinline int SWIG_TypeNameComp(const char* f1, const char* l1, const char* f2, const char* l2)
{
    for (; f1 != l1 && f2 != l2; ++f1, ++f2)
    {
        while (*f1 == ' ' && f1 != l1)
            ++f1;
        while (*f2 == ' ' && f2 != l2)
            ++f2;
        if (*f1 != *f2)
            return *f1 > *f2 ? 1 : -1;
    }
    return (int)((l1 - f1) - (l2 - f2));
}

// SWIG_TypeEquiv: whether `name` equals one of the '|'-separated alternatives in `str`.
static __forceinline int SWIG_TypeEquiv(const char* str, const char* name)
{
    const char* nameEnd = name + strlen(name);
    const char* cur = str;
    int equiv = 0;
    while (!equiv && *cur)
    {
        const char* first = cur;
        while (*cur && *cur != '|')
            ++cur;
        equiv = SWIG_TypeNameComp(first, cur, name, nameEnd) == 0;
        if (*cur)
            ++cur;
    }
    return equiv;
}

// SWIG_TypeQueryModule: the type named `name` in the module ring [start, end): a binary search of each module's
// mangled-name-sorted table first, then a scan of the human-readable type strings.
// @0x142055320
static swig_type_info* SWIG_TypeQueryModule(swig_module_info* start, swig_module_info* end, const char* name)
{
    swig_module_info* iter = start;
    do
    {
        if (iter->size)
        {
            size_t lo = 0, hi = iter->size - 1;
            do
            {
                size_t mid = (lo + hi) >> 1;
                const char* iname = iter->types[mid]->name;
                if (!iname)
                    break;
                int cmp = strcmp(name, iname);
                if (cmp == 0)
                    return iter->types[mid];
                if (cmp < 0)
                {
                    if (!mid)
                        break;
                    hi = mid - 1;
                }
                else
                {
                    lo = mid + 1;
                }
            } while (lo <= hi);
        }
        iter = iter->next;
    } while (iter != end);

    iter = start;
    do
    {
        for (size_t i = 0; i < iter->size; ++i)
        {
            if (iter->types[i]->str && SWIG_TypeEquiv(iter->types[i]->str, name))
                return iter->types[i];
        }
        iter = iter->next;
    } while (iter != end);
    return 0;
}

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
// The ctor and vftable come with the `new` in lua_ecrInitializePropertyHandlers below.
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

// IntepretAttachNifUserData: the Lua debugger's view of an AttachNifData userdata: its __tostring text. The exe
// compares against "ecr::AttachedNifData *", which no SWIG type string is (the type is "ecr::AttachNifData *"), so in
// practice it always declines.
// @0x142054890
static bool IntepretAttachNifUserData(lua_State* L, int pos, efd::utf8string& value)
{
    if (!lua_isuserdata(L, pos))
        return false;
    if (strcmp(SWIG_Lua_typename(L, pos), "ecr::AttachedNifData *"))
        return false;
    if (!luaL_callmeta(L, -1, "__tostring"))
    {
        lua_settop(L, 0);
        return false;
    }
    const char* text = lua_tolstring(L, -1, 0);
    value = text ? efd::utf8string(text) : efd::utf8string::NullString();
    lua_settop(L, -3);
    return true;
}

// lua_ecrInitializePropertyHandlers: once per process, loads the AttachedNifAsset wrapper into L and registers the
// AttachNifData property handler with L's scheduler and the interpreter with the Lua debugger.
// @0x142055130
void ecr::lua_ecrInitializePropertyHandlers(lua_State* L)
{
    static bool s_initialized = false;
    if (s_initialized || !L)
        return;
    egf::SchedulerLua* pScheduler = egf::SchedulerLua::GetSchedulerLua(L);
    if (!pScheduler)
        return;

    luaopen_AttachedNifAsset(L);
    swig_module_info* module = SWIG_Lua_GetModule(L);
    swig_type_info* typeInfo = SWIG_TypeQueryModule(module, module, "ecr::AttachNifData *");
    pScheduler->RegisterPropertyHandler(ecr::AttachNifData::CLASS_ID, EE_NEW AttachNifDataSwigPropHandler(typeInfo));

    egf::LuaBehaviorDebugger* pDebugger = egf::LuaBehaviorDebugger::Instance();
    if (pDebugger)
        pDebugger->RegisterUserDataInterpreter("AttachedNifAsset", &IntepretAttachNifUserData);
    s_initialized = true;
}
