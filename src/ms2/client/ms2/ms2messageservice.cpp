// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The game's subclass of efd::MessageService. The range is almost all
// template COMDATs instantiated by the vftable (efd::MessageFactory = GenericFactory<SmartPointer<IMessage>>, efd::list<MessageWithCategory>).
// MS2-UNIT: ?\ms2messageservice.cpp
// MS2-RANGE: 0x140d966b0-0x140d9aba0 .text$mn
// MS2-PIN: ??_7MS2MessageService@@6BISystemService@efd@@@ 0x142e33748
// MS2-PIN: ??_7MS2MessageService@@6BINetCallback@efd@@@ 0x142e33878
// MS2-PIN: ??_7MS2MessageService@@6B?$GenericFactory@V?$SmartPointer@VIMessage@efd@@@efd@@I@efd@@@ 0x142e33890
// MS2-PIN: ??$?0V?$tuple@AEBI@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBIP6A?AV?$SmartPointer@VIMessage@efd@@@efd@@XZ@std@@QEAA@AEAV?$tuple@AEBI@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x140d969e0
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2messageservice.h"
#include "hook/ms2hook.h"

// ---- out-of-unit callees ----
void* FUN_140166440();                                                  // the game logger
void FUN_1401859c0(void* pLog, int nCategory, int nLevel, const wchar_t* pszMessage);

// Not in the hook DLL: MS2::RegisterServices (hooked) must build the exe object (exe vtable; unhooked virtuals stay exe).
#ifndef MS2_HOOK_DLL
// @0x140d966b0
MS2MessageService::MS2MessageService()
{
}
#endif

// @0x140d96710
MS2MessageService::~MS2MessageService()
{
    FUN_1401859c0(FUN_140166440(), 0xc, 0x13, L"~MS2MessageService()\n");
    if (m_pMessageList != NULL)
    {
        EE_DELETE m_pMessageList;
        m_pMessageList = NULL;
    }
    if (m_pMessageListInternal != NULL)
    {
        EE_DELETE m_pMessageListInternal;
        m_pMessageListInternal = NULL;
    }
}
