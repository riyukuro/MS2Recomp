// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). NotifyBinding, the "createBindingImpl" /
// "deleteBindingImpl" notify handler of the GFx UI library. See notifybinding.h.
// MS2-UNIT: ?\notifybinding.cpp
// MS2-RANGE: 0x142301060-0x142301ff0 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). The
// tail is the implicit dtor and the CRBMap<CString, NotifyHandler::Callback> members the ctor's SetAt instantiates.
// MS2-PIN: ??_GNotifyBinding@@UEAAPEAXI@Z 0x142301470
#include "ms2/placeholder/ms2stdafx.h"

#include "notifybinding.h"
#include "dragslot.h"
#include "hook/ms2hook.h"

NotifyContext::BindData* FUN_1422c8e90(const CString& strName);                                  // the bind data of a name (null if none)
bool FUN_1422f1f80(const Scaleform::GFx::Value& a, const Scaleform::GFx::Value& b);              // the two AS values are equal

// @0x142301060
NotifyBinding::NotifyBinding(Unk_NotifyContext* pContext)
    : NotifyHandler(pContext)
{
    m_callbacks.SetAt("createBindingImpl", &NotifyBinding::OnCreateBindingImpl);
    m_callbacks.SetAt("deleteBindingImpl", &NotifyBinding::OnDeleteBindingImpl);
}

// @0x142301140
void NotifyBinding::CreateBindingImpl(const Params& params)
{
    const char* szName = params.pArgs[0].GetString();
    const Scaleform::GFx::Value& vTarget = params.pArgs[1];
    const Scaleform::GFx::Value& vData = params.pArgs[2];
    NotifyContext::BindData* pData = FUN_1422c8e90(szName);
    if (pData != NULL)
    {
        pData->FUN_1422c8cb0(vData);
        pData->FUN_1422c8d10(vTarget);
        pData->FUN_1422c8be0();
    }
}
MS2_REPLACE_METHOD(0x142301140, NotifyBinding, CreateBindingImpl, 196, 0xDF1D4B7F);

// @0x142301210
void NotifyBinding::DeleteBindingImpl(const Params& params)
{
    const char* szName = params.pArgs[0].GetString();
    const Scaleform::GFx::Value& vData = params.pArgs[2];
    NotifyContext::BindData* pData = FUN_1422c8e90(szName);
    if (pData != NULL)
    {
        if (params.pArgs[2].IsNull() || FUN_1422f1f80(vData, pData->FUN_1422c8d40()))
        {
            Scaleform::GFx::Value vNull;
            vNull.SetNull();
            pData->FUN_1422c8b50();
            pData->FUN_1422c8cb0(vNull);
            pData->FUN_1422c8d10(vNull);
        }
    }
}
MS2_REPLACE_METHOD(0x142301210, NotifyBinding, DeleteBindingImpl, 281, 0x2FEE6B15);

// @0x142301330
void NotifyBinding::OnCreateBindingImpl(NotifyHandler* pHandler, const Params& params)
{
    NotifyBinding* pThis = static_cast<NotifyBinding*>(pHandler);
    if (pThis != NULL)
        pThis->CreateBindingImpl(params);
}
MS2_REPLACE(0x142301330, NotifyBinding::OnCreateBindingImpl, 52, 0x736E23EA);

// @0x142301370
void NotifyBinding::OnDeleteBindingImpl(NotifyHandler* pHandler, const Params& params)
{
    NotifyBinding* pThis = static_cast<NotifyBinding*>(pHandler);
    if (pThis != NULL)
        pThis->DeleteBindingImpl(params);
}
MS2_REPLACE(0x142301370, NotifyBinding::OnDeleteBindingImpl, 52, 0xC7057EE1);

// The exe calls memset in CRBTree::NewNode (no /Oi expansion): templates are instantiated at the end of the TU.
#pragma function(memset)
