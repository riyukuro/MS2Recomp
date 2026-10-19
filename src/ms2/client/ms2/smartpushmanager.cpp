// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CSmartPushManager: see smartpushmanager.h.
// MS2-UNIT: ?\smartpushmanager.cpp
// MS2-RANGE: 0x140dd81d0-0x140dda280 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PIN: memcpy_s 0x140dda130
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\smartpushmanager.cpp"    // assumed

// The exe's memcpy_s is a plain call (no /Oi expansion); the pragma must precede the inline copy.
#include <vcruntime_string.h>
#pragma function(memcpy)
#include "ms2/placeholder/ms2stdafx.h"
#include <errno.h>
#include <string.h>

#include "smartpushmanager.h"
#include "uismartpush.h"

#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The UCRT's `static __inline memcpy_s` of this TU (kept alive by the pointer below).
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnMemcpyS)(void*, size_t, const void*, size_t) = &memcpy_s;

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// A counted handle on a UI object (the UI manager hands it out by id); the object is at +8.
class Unk_SpUIRef
{
public:
    ~Unk_SpUIRef();                                             // 0x1403e5630
    UIObject* FUN_1403e8a70() const;                            // the object (null if the UI is not open)
private:
    void* unknown;
    UIObject* object;
};
MS2_CHECK_SIZE(Unk_SpUIRef, 0x10);

class Unk_SpUIMgr
{
public:
    Unk_SpUIRef FUN_141adcea0(int nUiId);                       // find a UI by type id
};
Unk_SpUIMgr* FUN_1403ed2b0();
UIObject* FUN_1403ed9e0(Unk_SpUIRef& rRef);

CSmartPush* FUN_1401f7f50(CStringW strClass);                   // class factory: new object by registered name
unsigned FUN_140869420();                                       // client millisecond clock
int FUN_141986d30(UISmartPush* pUi);                            // the strip's movie is ready

// The "do not disturb" option block (+0x14: suppress every push).
struct Unk_SpOptionData
{
    char m_pad_00[0x14];
    bool m_bSuppress;                                           // +0x14
};
class Unk_SpOptions { public: Unk_SpOptionData* FUN_140b123b0(); };
Unk_SpOptions* FUN_1409a8b10();

// @0x140dd88c0
static UISmartPush* FindStripUI(int nUiId)
{
    if (FUN_1403ed2b0() != 0)
    {
        Unk_SpUIRef ref = FUN_1403ed2b0()->FUN_141adcea0(nUiId);
        if (ref.FUN_1403e8a70() != 0)
            return dynamic_cast<UISmartPush*>(FUN_1403ed9e0(ref));
    }
    return 0;
}

// @0x140dd81d0
CSmartPushManager::CSmartPushManager()
    : m_pushes(0x11, 0.75f, 0.25f, 2.25f, 10)
{
    m_nLastTick = 0;
}

// @0x140dd8250
CSmartPushManager::~CSmartPushManager()
{
    m_pushes.RemoveAll();
}

// @0x140dd82b0
void CSmartPushManager::FUN_140dd82b0()
{
    ATL::CAtlArray<CSmartPushTable::DataPtr> rows;
    CSmartPushTable::GetInstance()->GetAll(rows);
    for (size_t i = 0; i < rows.GetCount(); ++i)
    {
        const CSmartPushTable::DataPtr data(static_cast<const CSmartPushTable::DataPtr&>(rows[i]));
        CStringW strClass = StringFormat(L"CSmartPush{0}", data->m_strContent);
        PushPtr push(FUN_1401f7f50(strClass));
        if (push)
        {
            push->m_nId = data->m_nId;
            push->m_data = data;
            m_pushes.SetAt(push->m_nId, push);
        }
    }
}

// @0x140dd8440
void CSmartPushManager::FUN_140dd8440()
{
    UISmartPush* pUi = FindStripUI(0x4ef7);
    if (pUi == 0)
        return;
    int nNow = FUN_140869420();
    if ((unsigned)(nNow - m_nLastTick) < 100)
        return;
    m_nLastTick = nNow;
    for (POSITION pos = m_pushes.GetStartPosition(); pos != 0; m_pushes.GetNext(pos))
    {
        const PushPtr push(static_cast<const PushPtr&>(m_pushes.GetValueAt(pos)));
        int nWanted = push->vfunc_6();
        if (FUN_1409a8b10()->FUN_140b123b0()->m_bSuppress)
            nWanted = 0;
        if (push->m_nState != nWanted)
        {
            if (nWanted == 0)
            {
                pUi->FUN_140fa40c0(push->m_nId);
                push->m_nState = 0;
            }
            else
            {
                int nOld = push->m_nState;
                push->m_nState = nWanted;
                if (pUi->FUN_140fa3e20(push) == 0)
                    push->m_nState = nOld;
            }
        }
        push->vfunc_2();
    }
}

// @0x140dd8620
void CSmartPushManager::FUN_140dd8620(int nId)
{
    PushPtr push(0);
    if (m_pushes.Lookup(nId, push))
        push->vfunc_3();
}

// @0x140dd86a0
void CSmartPushManager::FUN_140dd86a0(int nId, int nValue)
{
    PushPtr push(0);
    if (m_pushes.Lookup(nId, push))
        push->vfunc_4(nValue);
}

// @0x140dd8730
void CSmartPushManager::FUN_140dd8730()
{
    for (POSITION pos = m_pushes.GetStartPosition(); pos != 0; m_pushes.GetNext(pos))
    {
        const PushPtr push(static_cast<const PushPtr&>(m_pushes.GetValueAt(pos)));
        push->m_nState = 0;
    }
}

// @0x140dd87d0
void CSmartPushManager::FUN_140dd87d0()
{
    UISmartPush* pUi = FindStripUI(0x4ef7);
    if (pUi == 0)
        return;
    if (FUN_141986d30(pUi) == 0)
        return;
    for (POSITION pos = m_pushes.GetStartPosition(); pos != 0; m_pushes.GetNext(pos))
    {
        const PushPtr push(static_cast<const PushPtr&>(m_pushes.GetValueAt(pos)));
        if (push->vfunc_6() != 0)
            pUi->FUN_140fa3e20(push);
    }
}
