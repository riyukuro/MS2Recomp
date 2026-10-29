// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): the out-of-line ATL module destructors that the
// lib_di_atl selectany initializers hand over as their exit routines. Three linked objects each carry the
// _AtlComModule / _AtlWinModule pair, so each destructor appears three times (the atexit thunks are lib_yd_atl).
// MS2-UNIT: lib_atl_moduleterm
// MS2-RANGE: 0x142cc4300-0x142cc4470 .text$mn
// MS2-RANGE: 0x142cc4590-0x142cc4700 .text$mn
// MS2-RANGE: 0x142cc5d00-0x142cc5e70 .text$mn
// MS2-FLAGS: gamebryo
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"

// ~CAtlComModule: Term() releases the cached class factories (DecodePointer'd), deletes the object-map lock and
// clears cbSize. Written out because the exe inlines the noexcept destructor and 14.16 ATL here keeps it out of line.
static __forceinline void AtlComModuleTerm() noexcept
{
    ATL::CAtlComModule& m = ATL::_AtlComModule;
    if (m.cbSize == 0)
        return;
    for (ATL::_ATL_OBJMAP_ENTRY_EX** ppEntry = m.m_ppAutoObjMapFirst; ppEntry < m.m_ppAutoObjMapLast; ppEntry++) {
        if (*ppEntry != NULL) {
            ATL::_ATL_OBJMAP_CACHE* pCache = (**ppEntry).pCache;
            if (pCache->pCF != NULL) {
                IUnknown* pFactory = static_cast<IUnknown*>(DecodePointer(pCache->pCF));
                pFactory->Release();
                pCache->pCF = NULL;
            }
        }
    }
    m.m_csObjMap.Term();
    m.cbSize = 0;
}

// @0x142cc4300
void FUN_142cc4300()
{
    AtlComModuleTerm();
}

// ~CAtlWinModule: AtlWinModuleTerm with the base module's instance (unregisters the window classes), then the
// atom array's destructor, written out for the same reason (the exe build is MBCS: UnregisterClassA).
static __forceinline void AtlWinModuleDtor() noexcept
{
    ATL::CAtlWinModule& m = ATL::_AtlWinModule;
    HINSTANCE hInst = ATL::_AtlBaseModule.GetModuleInstance();
    if (m.cbSize == sizeof(ATL::_ATL_WIN_MODULE)) {
        for (int i = 0; i < m.m_rgWindowClassAtoms.GetSize(); i++)
            UnregisterClassA((LPCSTR)m.m_rgWindowClassAtoms[i], hInst);
        m.m_rgWindowClassAtoms.RemoveAll();
        m.m_csWindowCreate.Term();
        m.cbSize = 0;
    }
    m.m_rgWindowClassAtoms.RemoveAll();
}

// @0x142cc4390
void FUN_142cc4390()
{
    AtlWinModuleDtor();
}

// The second object's copies.
// @0x142cc4590
void FUN_142cc4590()
{
    AtlComModuleTerm();
}

// @0x142cc4620
void FUN_142cc4620()
{
    AtlWinModuleDtor();
}

// The third object's copies.
// @0x142cc5d00
void FUN_142cc5d00()
{
    AtlComModuleTerm();
}

// @0x142cc5d90
void FUN_142cc5d90()
{
    AtlWinModuleDtor();
}
