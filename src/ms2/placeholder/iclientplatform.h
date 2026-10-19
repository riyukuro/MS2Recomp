// iclientplatform.h - PLACEHOLDER for IClientPlatform (RTTI .?AVIClientPlatform@@, vftable 0x142e10008, 78 slots).
// NOT an original header. The publisher platform interface (base impl CClientPlatformBase 0x142e10280, the Nexon impl
// 0x142e10aa0) that client\ms2\ms2clientplatform.cpp hands out. Only the slot types CGameApp::InitInstance (?\ms2.cpp)
// proves are typed; the rest are `void()` stand-ins. Other units use their own views (networkservice.h
// Unk_NetworkCallbacks, gamesocket.cpp Unk_140d86260).
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/ascript.h"

class CUserReportData;

class IClientPlatform
{
public:
    IClientPlatform();                          // 0x140c77100
    virtual int vfunc_0();
    virtual int vfunc_1();
    virtual int vfunc_2();
    virtual const char* vfunc_3();
    virtual int vfunc_4();                                  // 0x20: the authentication result (1 ok, 3 cancelled)
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual int vfunc_12();
    virtual CStringA vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual int vfunc_17();                                 // 0x88: the platform is ready (ms2clientplatform.cpp)
    virtual void vfunc_18(void* a1);
    virtual void vfunc_19(int a1, void* a2, void* a3);
    virtual void vfunc_20(int a1, int a2);                  // 0xa0: (code, 1) (uilogindialog.cpp)
    virtual void vfunc_21(void* a1);
    virtual void vfunc_22(int nCode, const char* pszFormat, ...);   // 0xb0: a startup step report ("GameInit", ...)
    virtual void vfunc_23(int nCode, const char* pszFormat, ...);   // 0xb8
    virtual void vfunc_24();
    virtual void vfunc_25(void* a1);
    virtual void vfunc_26(void* a1);
    virtual int vfunc_27();
    virtual void* vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31(CStringA a1, int a2, int a3);
    virtual void vfunc_32(void* a1);
    virtual void vfunc_33(__int64 a1);                      // 0x108: the account id (uilogindialog.cpp)
    virtual int vfunc_34(void* a1);
    virtual int vfunc_35(void* a1);
    virtual int vfunc_36();
    virtual int vfunc_37(void* a1);
    virtual void vfunc_38(void* a1);
    virtual bool vfunc_39(__int64 a1, int a2);
    virtual bool vfunc_40(__int64 a1);
    virtual bool vfunc_41(__int64 a1);
    virtual void vfunc_42(void* a1);
    virtual bool vfunc_43(int a1, bool a2, int a3);
    virtual const CStringA& vfunc_44();
    virtual const CStringA& vfunc_45();
    virtual int vfunc_46();
    virtual void vfunc_47(CStringA a1, CStringA a2);
    virtual void vfunc_48(MS2Ptr<CUserReportData> spReport);
    virtual int vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual int vfunc_52(void* a1, int a2);
    virtual int vfunc_53(void* a1, int a2);
    virtual int vfunc_54(CStringW a1, CStringW a2, int a3, CStringW a4);
    virtual void vfunc_55(float a1);
    virtual void vfunc_56(int a1);
    virtual void vfunc_57(void* a1);
    virtual void vfunc_58(int a1, int a2);
    virtual void vfunc_59(int a1);
    virtual void vfunc_60(int a1);
    virtual void vfunc_61();
    virtual void vfunc_62();
    virtual void vfunc_63(bool a1, int a2, int a3);
    virtual void vfunc_64(int a1);
    virtual void vfunc_65(int a1);
    virtual void vfunc_66();
    virtual void vfunc_67();
    virtual void vfunc_68();
    virtual void vfunc_69();
    virtual void vfunc_70();
    virtual void vfunc_71(void* a1);
    virtual void vfunc_72();
    virtual void vfunc_73(int a1);
    virtual int vfunc_74();
    virtual CStringA vfunc_75();
    virtual CStringA vfunc_76();
    virtual CStringA vfunc_77();
};
MS2_CHECK_SIZE(IClientPlatform, 8);

// The live platform (0x140d86260; other units declare it under its FUN_ name with their own view type).
IClientPlatform* GetClientPlatform();
