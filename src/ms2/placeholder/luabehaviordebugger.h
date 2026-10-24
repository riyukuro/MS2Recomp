// luabehaviordebugger.h - PLACEHOLDER for egf::LuaBehaviorDebugger (RTTI .?AVLuaBehaviorDebugger@egf@@): the
// interactive Lua behavior debugger singleton. NOT the SDK header: <egfLua/LuaBehaviorDebugger.h> pulls in
// SWIGluaRuntime.h, which needs lua.h (not on the engine include path). Only what the game's callers reach is
// declared: the singleton (ms_spInstance @0x143b07998) and the userdata-interpreter table at +0x18 (the exe's
// lua_ecrInitializePropertyHandlers reads its tree head there); the rest of the object is opaque.
#pragma once

#include <efd/SmartPointer.h>
#include <efd/StdContainers.h>
#include <efd/utf8string.h>

struct lua_State;

namespace egf
{
class LuaBehaviorDebugger
{
public:
    /// Formats a userdata value of one SWIG type for the debugger's watch view.
    typedef bool (UserDataInterpreter)(lua_State* L, int pos, efd::utf8string& value);

    static inline LuaBehaviorDebugger* Instance() { return ms_spInstance; }

    inline void RegisterUserDataInterpreter(const char* type, UserDataInterpreter* interpreter)
    {
        m_userDataInterpreters[type] = interpreter;
    }

private:
    char m_opaque[0x18];
    efd::map<efd::utf8string, UserDataInterpreter*> m_userDataInterpreters;   // +0x18

    static efd::SmartPointer<LuaBehaviorDebugger> ms_spInstance;
};
}
