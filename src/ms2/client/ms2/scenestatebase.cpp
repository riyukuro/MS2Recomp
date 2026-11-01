// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: client\ms2\scenestatebase.cpp
// MS2-RANGE: 0x14170b850-0x14170bd90 .text$mn
// MS2-RANGE: 0x1400ff840-0x1400ff860 .text$di
// This obj sits inside the units.tsv range of client\ms2\scenestategame.cpp (0x141703a70-0x14174bd70 holds six objs:
// ridee 0x141703a70, uirimlightdialog 0x141709320, rpgcameramode 0x141709970, scalemodifier 0x14170b530, this one,
// scenestategame 0x14170bda0); the CU name is assumed.
// MS2-PIN: ?SetupClassInfo@CSceneStateBase@@SAXPEAVClassInfo@efd@@_K@Z 0x14170ba30
// MS2-PIN: memcpy_s 0x14170bb30
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\scenestatebase.cpp"
// The exe's memcpy_s copy calls memset/memcpy (no /Oi expansion): the pragma must precede its inline definition.
#include <vcruntime_string.h>
#pragma function(memcpy, memset)
#include "ms2/placeholder/ms2stdafx.h"
#include "scenestatebase.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <efd/Win32/Win32PlatformService.h>  // C3: efd::Win32PlatformService::GetWindowRef

unsigned long GetTickCountMs2();   // C3: was FUN_140869420
void* FUN_140aadf80();                      // the application object
extern int g_143af7d58;                     // nonzero: keep the window hidden

EE_IMPLEMENT_CONCRETE_CLASS_INFO(CSceneStateBase);

// @0x14170b850
CSceneStateBase::CSceneStateBase()
{
    m_nEnterTime = 0;
}

// @0x14170b8b0
CSceneStateBase::~CSceneStateBase()
{
}

// @0x14170b8e0
void CSceneStateBase::OnEnter(int nPrevState)
{
    m_nEnterTime = GetTickCountMs2();
    FUN_140aadf80();
    if (!g_143af7d58)
        ShowWindow(((efd::Win32PlatformService*)FUN_140aadf80())->GetWindowRef(), SW_SHOWNORMAL);
}
MS2_REPLACE_METHOD(0x14170b8e0, CSceneStateBase, OnEnter, 72, 0x60A9E002);

// @0x14170b930
void CSceneStateBase::OnLeave(int nNextState)
{
}

// @0x14170b940
void CSceneStateBase::OnUpdate(double fTime)
{
}

// @0x14170b960
void CSceneStateBase::OnPacket(CInPacket& packet)
{
}

// @0x14170b980
void CSceneStateBase::OnWndMessage(unsigned int nMsg, int wParam, int lParam)
{
}

// @0x14170b9a0
int CSceneStateBase::vfunc_14()
{
    return 0;
}

// @0x14170b9b0
int CSceneStateBase::vfunc_15()
{
    return 1;
}

// memcpy_s 0x14170bb30 and memmove_s 0x14170bc80 close the obj's COMDAT tail.
__declspec(selectany) extern errno_t(__cdecl* const ms2_sceneStateBaseMemcpyS)(void*, size_t, const void*, size_t) = &memcpy_s;
MS2_EMIT_CRT_MEMMOVE_S();
