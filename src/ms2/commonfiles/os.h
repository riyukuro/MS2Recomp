// COSInfo from RTTI; field and query names inferred from behavior.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
template<class T> class TSingleton {
public:
    // The exe stores the complete object: for a T whose TSingleton is a secondary base the ctor adjusts back to T and
    // GetInstance returns s_instance unadjusted.
    TSingleton() { s_instance=static_cast<T*>(this); }
    virtual ~TSingleton() { s_instance=0; }
    static T* s_instance;
    static T* GetInstance() { return s_instance; }   // w3o1: 0x14015a050 for T = GameEventManagerCli
    // w261: created on demand / destroyed by CMainSystem::OnInit / OnShutdown (0x141475730.., 0x141475b50..).
    static T* CreateInstance() { return s_instance != 0 ? GetInstance() : new T; }
    static void DestroyInstance() { if (s_instance != 0) { delete GetInstance(); s_instance = 0; } }
};
template<class T> T* TSingleton<T>::s_instance=0;
struct Unk_OSData {
    Unk_OSData() : isNT(false),is64(false) {}
    OSVERSIONINFOEXA version;
    SYSTEM_INFO system;
    int kind;
    int family;
    bool isNT;
    bool is64;
};
class COSInfo : public TSingleton<COSInfo> {
public:
    void StartUp();
    void ShutDown();
    CString GetName();
    COSInfo();
    virtual ~COSInfo();
    bool IsNT();
    bool Is64Bit();
    CString GetFullName();
    CString GetServicePack();
    int GetKind();
    int GetFamily();
    unsigned long GetMajor();
    unsigned long GetMinor();
    unsigned long GetProcessorCount();
private:
    MS2_LAYOUT_FRIEND;
    Unk_OSData* m_data;
    int m_country;
};
MS2_CHECK_SIZE(Unk_OSData,0xe0);
MS2_CHECK_OFFSET(Unk_OSData,system,0xa0);
MS2_CHECK_OFFSET(Unk_OSData,kind,0xd0);
MS2_CHECK_OFFSET(Unk_OSData,isNT,0xd8);
MS2_CHECK_SIZE(COSInfo,0x18);
MS2_CHECK_OFFSET(COSInfo,m_data,8);
struct Unk_OSNumber { explicit Unk_OSNumber(unsigned __int64); Unk_OSNumber& operator=(const Unk_OSNumber&); unsigned __int64 value; bool flag; };
class Unk_OSInput {
public:
    virtual bool vfunc_0();
    virtual unsigned char vfunc_1();
    virtual unsigned short vfunc_2();
    virtual unsigned int vfunc_3();
    virtual unsigned __int64 vfunc_4();
    virtual float vfunc_5();
    virtual double vfunc_6();
    virtual CString vfunc_7();
    virtual CStringW vfunc_8();
    Unk_OSInput& Read0(bool&);
    Unk_OSInput& Read1(unsigned char&);
    Unk_OSInput& Read2(short&);
    Unk_OSInput& Read3(unsigned short&);
    Unk_OSInput& Read4(int&);
    Unk_OSInput& Read5(long&);
    Unk_OSInput& Read6(unsigned int&);
    Unk_OSInput& Read7(__int64&);
    Unk_OSInput& Read8(unsigned __int64&);
    Unk_OSInput& Read9(float&);
    Unk_OSInput& Read10(CString&);
    Unk_OSInput& Read11(CStringW&);
    Unk_OSInput& Read12(ATL::CTime&);
    Unk_OSInput& Read13(Unk_OSNumber&);
};
