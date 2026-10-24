// schedulerlua.h - PLACEHOLDER for egf::SchedulerLua (RTTI .?AVSchedulerLua@egf@@, 0x78 bytes): the Lua scripting
// runtime of the egf::Scheduler. NOT the SDK header: <egfLua/SchedulerLua.h> pulls in SWIGluaRuntime.h, which needs
// lua.h (not on the engine include path). The declarations below follow the SDK header (same virtual order); the data
// members are opaque.
#pragma once

#include <egf/ISchedulerScripting.h>
#include <egf/egfClassIDs.h>

#include "ms2/ms2layout.h"

struct lua_State;

namespace egf
{
class ILuaPropertyHandler;

class SchedulerLua : public egf::ISchedulerScripting
{
    EE_DECLARE_CLASS1(SchedulerLua, efd::kCLASSID_SchedulerLua, egf::ISchedulerScripting);
protected:
    virtual ~SchedulerLua();
public:
    SchedulerLua();
    typedef int (*LuaScriptInitFunction)(lua_State*);
    static bool AddStaticBuiltinInitFunction(LuaScriptInitFunction i_pfn);
    bool RegisterPropertyHandler(efd::ClassID propDataType, ILuaPropertyHandler* pHandler);
    static SchedulerLua* GetSchedulerLua(lua_State* L);
    virtual lua_State* GetLuaState() const;
    virtual efd::Category GetAssetLoadCategory() const;
protected:
    virtual bool InitForScripting(Scheduler* pScheduler);
    virtual void PreloadModule(const char* moduleName, efd::Category callback = efd::kCAT_INVALID);
    virtual bool ReloadModule(const char* moduleName);
    virtual bool DoScriptBehavior(egf::PendingBehavior* pPendBehavior);
    virtual void Shutdown();
private:
    MS2_LAYOUT_FRIEND;
    char m_opaque[0x78 - sizeof(egf::ISchedulerScripting)];
};
}
MS2_CHECK_SIZE(egf::SchedulerLua, 0x78);
