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
#pragma function(memcpy, memset)
#include "ms2/placeholder/ms2stdafx.h"
#include <errno.h>
#include <string.h>

#include "smartpushmanager.h"
#include "uismartpush.h"

#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/placeholder/cgameoption.h"

// The UCRT's `static __inline memcpy_s` of this TU (kept alive by the pointer below).
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnMemcpyS)(void*, size_t, const void*, size_t) = &memcpy_s;

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------



class ClassObject;
ClassObject*CreateClassObject(CStringW);                   // class factory: new object by registered name
unsigned long GetTickCountMs2();   // C3: was FUN_140869420

// The "do not disturb" option block (+0x14: suppress every push).
struct Unk_SpOptionData
{
    char m_pad_00[0x14];
    bool m_bSuppress;                                           // +0x14
};

// @0x140dd88c0
static UISmartPush* FindStripUI(int nUiId)
{
    if (TSingleton<CUIService>::GetInstance() != 0)
    {
        MS2Ptr<UIObject> ref = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)nUiId);
        if (ref.get() != 0)
            return dynamic_cast<UISmartPush*>(ref.operator UIObject*());
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
void CSmartPushManager::CreatePushes()
{
    ATL::CAtlArray<CSmartPushTable::DataPtr> rows;
    CSmartPushTable::GetInstance()->GetAll(rows);
    for (size_t i = 0; i < rows.GetCount(); ++i)
    {
        const CSmartPushTable::DataPtr data(static_cast<const CSmartPushTable::DataPtr&>(rows[i]));
        CStringW strClass = StringFormat(L"CSmartPush{0}", data->m_strContent);
        PushPtr push(reinterpret_cast<CSmartPush *>(CreateClassObject(strClass)));
        if (push)
        {
            push->m_nId = data->m_nId;
            push->m_data = data;
            m_pushes.SetAt(push->m_nId, push);
        }
    }
}

// @0x140dd8440
void CSmartPushManager::UpdatePushes()
{
    UISmartPush* pUi = FindStripUI(0x4ef7);
    if (pUi == 0)
        return;
    int nNow = GetTickCountMs2();
    if ((unsigned)(nNow - m_nLastTick) < 100)
        return;
    m_nLastTick = nNow;
    for (POSITION pos = m_pushes.GetStartPosition(); pos != 0; m_pushes.GetNext(pos))
    {
        const PushPtr push(static_cast<const PushPtr&>(m_pushes.GetValueAt(pos)));
        int nWanted = push->vfunc_6();
        if (reinterpret_cast<Unk_SpOptionData*>(TSingleton<CGameOption>::GetInstance()->GetStatus())->m_bSuppress)
            nWanted = 0;
        if (push->m_nState != nWanted)
        {
            if (nWanted == 0)
            {
                pUi->RemovePush(push->m_nId);
                push->m_nState = 0;
            }
            else
            {
                int nOld = push->m_nState;
                push->m_nState = nWanted;
                if (pUi->AddPush(push) == 0)
                    push->m_nState = nOld;
            }
        }
        push->vfunc_2();
    }
}

// @0x140dd8620
void CSmartPushManager::OnPushClicked(int nId)
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
void CSmartPushManager::ResetPushStates()
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
    if (reinterpret_cast<UIHeadUpDisplay*>(pUi)->FUN_141986d30() == 0)
        return;
    for (POSITION pos = m_pushes.GetStartPosition(); pos != 0; m_pushes.GetNext(pos))
    {
        const PushPtr push(static_cast<const PushPtr&>(m_pushes.GetValueAt(pos)));
        if (push->vfunc_6() != 0)
            pUi->AddPush(push);
    }
}

// The map templates are generated here and keep the exe's inline memset; only the CRT memcpy_s above calls it.
#pragma intrinsic(memset)
