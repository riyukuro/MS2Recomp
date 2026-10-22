// CProxyGameObject (RTTI .?AVCProxyGameObject@@, 0xe8 bytes, CPtred), the per-field-object proxy the world keeps.
// ctor 0x1416c1cc0, dtor 0x1416c1f00, vftable 0x142f54b78 (dtor only). Recovered in src/ms2/unnamed/unit_1416c1cc0.cpp;
// the member sub-objects are opaque handle/value types (Unk_Proxy*) whose ctors/dtors live elsewhere in the exe.
#pragma once
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/nipoint3.h"

class CInputStream;

// +0x18: 16-byte handle (second word is the object pointer). Ctor is the inline 0x1416c2ba0.
class Unk_ProxyHandle18
{
public:
    Unk_ProxyHandle18();                // 0x1416c2ba0 (m_8 = 0)
    ~Unk_ProxyHandle18();               // 0x140964a70
    void FUN_140964ff0(int n);          // reset / assign
    void* m_pad_00;
    void* m_8;
};
MS2_CHECK_SIZE(Unk_ProxyHandle18, 0x10);

// +0x28: 16-byte handle.
class Unk_ProxyHandle28
{
public:
    Unk_ProxyHandle28();                // 0x140a7fba0
    Unk_ProxyHandle28(const Unk_ProxyHandle28& o);   // 0x140a4fc70 (copy)
    ~Unk_ProxyHandle28();               // 0x1406d5390
    void FUN_140a4fe90(int n);          // reset
    void FUN_140a4fe50(const Unk_ProxyHandle28& h); // assign
    void* FUN_140a4ff10();              // get the object pointer (null when empty)
    void* m_pad_00;
    void* m_pad_08;
};
MS2_CHECK_SIZE(Unk_ProxyHandle28, 0x10);

// +0x88: 0x1c-byte value (ctor 0x140964630, dtor 0x140964e40).
class Unk_ProxyValue88
{
public:
    Unk_ProxyValue88();
    ~Unk_ProxyValue88();
    int m_pad_00; int m_pad_04; int m_pad_08; int m_pad_0c;
    int m_pad_10; int m_pad_14; int m_pad_18;
};
MS2_CHECK_SIZE(Unk_ProxyValue88, 0x1c);

// +0xd0: 0xc-byte value (ctor 0x140267ba0, cleared by 0x140267c10).
class Unk_ProxyValueD0
{
public:
    Unk_ProxyValueD0();
    void FUN_140267c10();
    void FUN_140267bd0();               // clear to zero (_FillZeroMan)
    void FUN_140267e70(CInputStream& s);   // decode (the Unk_UserProxyColor body; scenestategame 0x7e)
    int m_pad_00;
    int m_pad_04;
    int m_pad_08;
};
MS2_CHECK_SIZE(Unk_ProxyValueD0, 0xc);

class CProxyGameObject : public CPtred {
public:
    CProxyGameObject();                                 // 0x1416c1cc0
    virtual ~CProxyGameObject();                        // slot 0, 0x1416c1f00 (??_G 0x1416c2bc0)

    int FUN_1416c1ff0();                                // m_40 is the self object
    int FUN_1416c2040();                                // m_40 is another object
    int FUN_1416c2090();                                // has a template id and no pending flag
    int FUN_1416c20d0();                               // handle +0x18 has an object
    int FUN_1416c2110();
    int FUN_1416c21c0();
    Unk_ProxyValue88* FUN_1416c2200();
    Unk_ProxyHandle28 FUN_1416c2220();
    Vector3 FUN_1416c2270();
    void* FUN_1416c22f0();
    void* FUN_1416c2310();
    unsigned short FUN_1416c2330();
    int FUN_1416c2350();
    int FUN_1416c2370();
    int FUN_1416c2390();
    CStringW FUN_1416c23b0();
    CString FUN_1416c2520();
    CStringW FUN_1416c2570();
    CStringW FUN_1416c2600();
    void FUN_1416c2920();
    Unk_ProxyValueD0* FUN_1416c2950();
    int FUN_1416c2990(int nTemplateId);
    void FUN_1416c2a80();
    bool FUN_1416c2b30();
    bool FUN_1416c2b70();

    Unk_ProxyHandle18 m_18;
    Unk_ProxyHandle28 m_28;
    int m_proxyId;                                      // +0x38 (object id)
    int m_pad_3c;
    __int64 m_40;                                       // owner character id (scenestategame 0x7e)
    __int64 m_48;
    CString m_50;
    CStringW m_58;
    CStringW m_60;
    int kind; // initialized to zero at +68; party member count tests it
    Vector3 m_6c;
    int m_78;                                           // template id
    int m_7c;
    int m_80;
    int m_84;
    Unk_ProxyValue88 m_88;
    int m_a4;
    unsigned short m_a8;
    int m_ac;
    int m_b0;
    unsigned m_b4;
    int m_b8;
    int m_bc;
    CStringW m_c0;
    int m_c8;
    int m_cc;
    Unk_ProxyValueD0 m_d0;
    unsigned char m_dc;
    int m_e0;
    int m_e4;
};
MS2_CHECK_OFFSET(CProxyGameObject, kind, 0x68);
MS2_CHECK_OFFSET(CProxyGameObject, m_28, 0x28);
MS2_CHECK_OFFSET(CProxyGameObject, m_6c, 0x6c);
MS2_CHECK_OFFSET(CProxyGameObject, m_88, 0x88);
MS2_CHECK_OFFSET(CProxyGameObject, m_a4, 0xa4);
MS2_CHECK_OFFSET(CProxyGameObject, m_c0, 0xc0);
MS2_CHECK_OFFSET(CProxyGameObject, m_d0, 0xd0);
MS2_CHECK_OFFSET(CProxyGameObject, m_dc, 0xdc);
MS2_CHECK_SIZE(CProxyGameObject, 0xe8);
