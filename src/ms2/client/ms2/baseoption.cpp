// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The client's baseoption.cpp: base of the game-option rows.
// MS2-UNIT: ?\baseoption.cpp
// MS2-RANGE: 0x140a02ac0-0x140a03090 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\baseoption.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "baseoption.h"
#include "ms2/placeholder/uiobject.h"
#include "ms2/client/ms2/uigameoptiondialog.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local placeholders ----
void FUN_141943820(UIGameOptionDialog* pDialog, int n);

// The UI manager's reference to a dialog (16 bytes, object at +8; dtor 0x1403e5630).
class Unk_BoUIRef
{
public:
    ~Unk_BoUIRef();
    UIObject* FUN_1403e8a70() const;                                // the object, or 0
    UIObject* FUN_1403ed9e0();
private:
    void* unknown;
    UIObject* object;
};
MS2_CHECK_SIZE(Unk_BoUIRef, 0x10);
// The UI manager singleton (0x1403ed2b0).
class Unk_BoUIService
{
public:
    Unk_BoUIRef FUN_141adcea0(int nId);
};
Unk_BoUIService* FUN_1403ed2b0();

// @0x140a02ac0
CBaseOption::CBaseOption(int nId, int nType)
{
    m_nId = nId;
    m_nType = nType;
    m_nActive = 0;
    m_nPending = 0;
    m_bEnabled = true;
}

// @0x140a02b40
CBaseOption::~CBaseOption()
{
}

// @0x140a02b70
CString CBaseOption::vfunc_1()
{
    return CString("");
}

// @0x140a02bc0
void CBaseOption::vfunc_2()
{
    m_nActive = 1;
    if (m_nPending != 0)
    {
        vfunc_6();
        m_nPending = 0;
    }
}

// @0x140a02c10
void CBaseOption::vfunc_3(int n)
{
    if (m_nActive != 0)
        vfunc_6();
    else
        m_nPending = 1;
}

// @0x140a02c60
void CBaseOption::vfunc_4(int n)
{
    if (n == 0)
        m_nActive = 0;
    else
        vfunc_7();
}

// @0x140a02ca0
int CBaseOption::vfunc_5(const char* pszName, void* pArg, int nArg)
{
    return 0;
}

// @0x140a02cc0
void CBaseOption::vfunc_6()
{
}

// @0x140a02cd0
void CBaseOption::vfunc_7()
{
}

// @0x140a02ce0
int CBaseOption::vfunc_8()
{
    return 0;
}

// @0x140a02cf0
void CBaseOption::vfunc_9()
{
}

// @0x140a02d00
void CBaseOption::vfunc_10()
{
    if (m_nActive != 0)
        vfunc_7();
}

// @0x140a02d30
void CBaseOption::vfunc_11()
{
}

// @0x140a02d40
void CBaseOption::vfunc_12()
{
}

// @0x140a02d50
void CBaseOption::vfunc_13()
{
}

// @0x140a02d60
int CBaseOption::vfunc_14()
{
    return 0;
}

// @0x140a02d70
UIGameOptionDialog* CBaseOption::GetOptionDialog()
{
    return FUN_140a02e60(0x4ef3);
}

// @0x140a02d90
void CBaseOption::FUN_140a02d90(int n)
{
    UIGameOptionDialog* pDialog = GetOptionDialog();
    if (pDialog != 0)
        FUN_141943820(pDialog, n);
}

// @0x140a02dd0
bool CBaseOption::IsEnabled() const
{
    return m_bEnabled;
}

// @0x140a02df0
void CBaseOption::SetEnabled(bool b)
{
    m_bEnabled = b;
}

// @0x140a02e10
int CBaseOption::GetType() const
{
    return m_nType;
}

// @0x140a02e30
int CBaseOption::GetActive() const
{
    return m_nActive;
}

// @0x140a02e50
int CBaseOption::FUN_140a02e50() const
{
    return m_nId;
}

// @0x140a02e60
UIGameOptionDialog* FUN_140a02e60(int nDialogId)
{
    if (FUN_1403ed2b0())
    {
        Unk_BoUIRef ref = FUN_1403ed2b0()->FUN_141adcea0(nDialogId);
        if (ref.FUN_1403e8a70())
            return dynamic_cast<UIGameOptionDialog*>(ref.FUN_1403ed9e0());
    }
    return 0;
}

// The UCRT's header-inline memcpy_s of this TU (0x140a02f40), kept alive through the pointer below.
// @0x140a02f40
#pragma function(memset, memcpy)
static __inline errno_t ms2_bo_memcpy_s(void* const d, size_t const dsz, void const* const s, size_t const ssz)
{
    if (ssz == 0) { return 0; }
    { int e = !!(d != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    if (s == NULL || dsz < ssz)
    {
        memset(d, 0, dsz);
        { int e = !!(s != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
        { int e = !!(dsz >= ssz); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
        return EINVAL;
    }
    memcpy(d, s, ssz);
    return 0;
}
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnBoMemcpyS)(void*, size_t, const void*, size_t) = &ms2_bo_memcpy_s;
