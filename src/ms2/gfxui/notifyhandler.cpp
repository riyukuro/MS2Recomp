// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). NotifyHandler, the GFx function handler base of the GFx UI
// library's notify handlers. See notifyhandler.h.
// MS2-UNIT: ?\notifyhandler.cpp
// MS2-RANGE: 0x142300880-0x142301060 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). The
// tail is the CRBMap<CString, NotifyHandler::Callback> instantiation and the implicit dtor.
#include "ms2/placeholder/ms2stdafx.h"

#include "notifyhandler.h"
#include "hook/ms2hook.h"

Scaleform::GFx::Movie* FUN_1422bb8b0(int nMovieId);            // the GFx movie of a movie id (null if not loaded)

// @0x142300880
NotifyHandler::NotifyHandler(Unk_NotifyContext* pContext)
    : m_spContext(pContext)
{
}

// @0x1423008f0
void NotifyHandler::FUN_1423008f0(int nMovieId, Scaleform::GFx::Value& obj)
{
    if (obj.IsObject())
    {
        for (POSITION pos = m_callbacks.GetHeadPosition(); pos != NULL; m_callbacks.GetNext(pos))
        {
            Scaleform::GFx::Movie* pMovie = FUN_1422bb8b0(nMovieId);
            if (pMovie != NULL)
            {
                Scaleform::GFx::Value vFunc;
                pMovie->CreateFunction(&vFunc, this, m_callbacks.GetValueAt(pos));
                obj.SetMember(m_callbacks.GetKeyAt(pos), vFunc);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1423008F0, NotifyHandler, FUN_1423008f0, 260, 0x1E16D067);

// @0x142300a00
void NotifyHandler::Call(const Params& params)
{
    ((Callback)params.pUserData)(this, params);
}
MS2_REPLACE_METHOD(0x142300A00, NotifyHandler, Call, 37, 0x4C79639A);

// MS2-PIN: ??_GNotifyHandler@@UEAAPEAXI@Z 0x142300be0
