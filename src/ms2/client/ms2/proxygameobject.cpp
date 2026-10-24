// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CProxyGameObject: the world's per-field-object proxy.
// MS2-UNIT: unit_1416c1cc0
// MS2-RANGE: 0x1416c1cc0-0x1416c2c00 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\proxygameobject.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/cproxygameobject.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <egf/FlatModel.h>

// ---- out-of-unit types and callees (bound to the exe by their FUN_<va> names / symbols) ----
extern __int64 DAT_143ab2828;                                       // the "self" object pointer
extern Vector3 DAT_143b01a60;                               // the zero point
extern int DAT_143b059e8;

class Unk_ProxyTarget                                               // what handle +0x18 points at
{
public:
    void* m_pad_00; void* m_pad_08; void* m_pad_10;
    void* m_key;                                                    // +0x18 (its address is passed on)
    void* m_pad_20; void* m_pad_28; void* m_pad_30; void* m_pad_38; void* m_pad_40; void* m_pad_48;
    void* m_pad_50; void* m_pad_58; void* m_pad_60; void* m_pad_68; void* m_pad_70; void* m_pad_78;
    void* m_pad_80; void* m_pad_88; void* m_pad_90; void* m_pad_98; void* m_pad_a0; void* m_pad_a8;
    void* m_pad_b0; void* m_pad_b8; void* m_pad_c0; void* m_pad_c8; void* m_pad_d0; void* m_pad_d8;
    void* m_pad_e0; void* m_pad_e8; void* m_pad_f0; void* m_pad_f8; void* m_pad_100; void* m_pad_108;
    void* m_pad_110; void* m_pad_118; void* m_pad_120; void* m_pad_128; void* m_pad_130; void* m_pad_138;
    void* m_pad_140; void* m_pad_148; void* m_pad_150; void* m_pad_158;
    int m_160;                                                      // type; 8 = special
};
MS2_CHECK_OFFSET(Unk_ProxyTarget, m_key, 0x18);
MS2_CHECK_OFFSET(Unk_ProxyTarget, m_160, 0x160);
class Unk_Entity1411cf440 { };
class Unk_Mgr1409670f0 { };
Unk_Mgr1409670f0* FUN_1409670f0();
Unk_Entity1411cf440* FUN_1411cf440(Unk_Mgr1409670f0* mgr, void** key);
egf::FlatModel* FUN_1408a9bd0(Unk_Entity1411cf440* ent);
Unk_ProxyTarget* FUN_140965960(Unk_ProxyHandle18* h);
void* FUN_140c9b7d0(Unk_ProxyHandle18* h);

class Unk_Tbl1403ed2d0 { };                                         // object table
class Unk_PosObject                                                 // MS2: slot 18 is GetPosition
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17();
    virtual Vector3 vfunc_18();
};
Unk_Tbl1403ed2d0* FUN_1403ed2d0();
Unk_PosObject* FUN_141bd1180(Unk_Tbl1403ed2d0* tbl, int id);


CStringW FUN_1401aa6a0(int id);
class Unk_Entry140965990 { };
Unk_Entry140965990* FUN_140965990(const Unk_ProxyHandle28& h);
unsigned char FUN_140a7c8d0(Unk_Entry140965990* e);

class Unk_Tbl141bd0cc0 { public: CStringW FUN_1415281c0(); };
Unk_Tbl141bd0cc0* FUN_141bd0cc0(Unk_Tbl1403ed2d0* tbl);
CStringW* FUN_141656d90(Unk_Tbl141bd0cc0* t);

class Unk_Data1401cc
{
public:
    unsigned FUN_1401cc3e0();
    CStringW FUN_1401cc350();
    int FUN_1401cc3a0();
    int FUN_1401cc3c0();
};
class Unk_Handle97a
{
public:
    ~Unk_Handle97a();                                               // 0x140979fc0
    void* FUN_14097a170();
    Unk_Data1401cc* FUN_14097a1e0();
    void* m_pad_00;
    void* m_pad_08;
};
class Unk_Svc97a780 { public: Unk_Handle97a FUN_140ae4880(void* key); };
Unk_Svc97a780* FUN_14097a780();

class Unk_Ptr1401cd040                                              // CComPtrBase<> local
{
public:
    Unk_Ptr1401cd040(void* p);
    ~Unk_Ptr1401cd040();                                            // 0x1401cd150
    void* m_p;
};
void* FUN_1401cd040(int* p);
class Unk_Local1408ad110                                            // 200-byte working struct
{
public:
    Unk_Local1408ad110();                                           // 0x1408ad110
    ~Unk_Local1408ad110();                                          // 0x14050de70
    void* m_00; void* m_08; void* m_10; void* m_18; void* m_20; void* m_28; void* m_30; void* m_38;
    void* m_40; void* m_48; void* m_50; void* m_58; void* m_60; void* m_68; void* m_70; void* m_78;
    void* m_80; void* m_88; void* m_90; void* m_98; void* m_a0; void* m_a8; void* m_b0; void* m_b8;
    void* m_c0;
};
MS2_CHECK_SIZE(Unk_Local1408ad110, 0xc8);
int FUN_1408a0d30(int a, Unk_Local1408ad110* l, unsigned b);
CStringW FUN_1409796e0(unsigned a, int b, int c, CStringW s);

class Unk_Svc6d6e90 { public: Unk_ProxyHandle28 FUN_140a7cab0(int id); };
Unk_Svc6d6e90* FUN_1406d6e90();
class Unk_Svc7476c0 { public: unsigned char FUN_14074e030(int id); };
Unk_Svc7476c0* FUN_1407476c0();
class Unk_Svc109a710 { public: int FUN_140764cd0(int id); int FUN_140764e00(int id); };
Unk_Svc109a710* FUN_14109a710();
class Unk_Svc764020 { };
Unk_Svc764020* FUN_140764020();
void FUN_1416d12d0(Unk_Svc764020* s, int id, Unk_ProxyValue88* v, int n);
class Unk_Svc6c7600 { };
Unk_Svc6c7600* FUN_1406c7600();
Unk_ProxyValueD0* FUN_140938ad0(Unk_Svc6c7600* s);

// @0x1416c1cc0
CProxyGameObject::CProxyGameObject()
{
    m_18.FUN_140964ff0(0);
    m_28.FUN_140a4fe90(0);
    m_proxyId = 0;
    m_40 = 0;
    m_48 = 0;
    kind = 0;
    m_6c = DAT_143b01a60;
    m_78 = 0;
    m_84 = 0;
    m_80 = 0;
    m_a8 = 0;
    m_dc = 0;
    m_ac = 1;
    m_b4 = 0;
    m_b8 = 0;
    m_bc = 0;
    m_c8 = 0;
    m_7c = 0;
    m_cc = 0;
    m_d0.FUN_140267bd0();
    m_a4 = 1;
    m_e0 = 0;
    m_e4 = 0;
}

// @0x1416c1f00
CProxyGameObject::~CProxyGameObject()
{
    m_18.FUN_140964ff0(0);
    m_28.FUN_140a4fe90(0);
}

// @0x1416c1ff0
int CProxyGameObject::FUN_1416c1ff0()
{
    int r;
    if (m_40 != 0 && m_40 == DAT_143ab2828) {
        r = 1;
    } else {
        r = 0;
    }
    return r;
}
MS2_REPLACE_METHOD(0x1416C1FF0, CProxyGameObject, FUN_1416c1ff0, 63, 0x2E42A744);

// @0x1416c2040
int CProxyGameObject::FUN_1416c2040()
{
    int r;
    if (m_40 != 0 && m_40 != DAT_143ab2828) {
        r = 1;
    } else {
        r = 0;
    }
    return r;
}
MS2_REPLACE_METHOD(0x1416C2040, CProxyGameObject, FUN_1416c2040, 63, 0x117FEF14);

// @0x1416c2090
int CProxyGameObject::FUN_1416c2090()
{
    int r;
    if (m_78 != 0 && m_84 == 0) {
        r = 1;
    } else {
        r = 0;
    }
    return r;
}
MS2_REPLACE_METHOD(0x1416C2090, CProxyGameObject, FUN_1416c2090, 58, 0xA0774B98);

// @0x1416c20d0
int CProxyGameObject::FUN_1416c20d0()
{
    int r;
    if (FUN_140c9b7d0(&m_18)) {
        r = 1;
    } else {
        r = 0;
    }
    return r;
}
MS2_REPLACE_METHOD(0x1416C20D0, CProxyGameObject, FUN_1416c20d0, 58, 0x7AD39F1A);

// @0x1416c2110
int CProxyGameObject::FUN_1416c2110()
{
    if (FUN_1416c20d0() == 0) {
        return 0;
    }
    Unk_Entity1411cf440* ent = FUN_1411cf440(FUN_1409670f0(), &FUN_140965960(&m_18)->m_key);
    if (ent != 0) {
        if (FUN_1408a9bd0(ent)->ContainsModel(0x7b35ceec)) {
            return 1;
        }
        if (FUN_140965960(&m_18)->m_160 == 8) {
            return 1;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1416C2110, CProxyGameObject, FUN_1416c2110, 167, 0x29EA4E0A);

// @0x1416c21c0
int CProxyGameObject::FUN_1416c21c0()
{
    int r;
    if (m_84 != 0) {
        r = 1;
    } else {
        r = 0;
    }
    return r;
}
MS2_REPLACE_METHOD(0x1416C21C0, CProxyGameObject, FUN_1416c21c0, 47, 0x5A0ED176);

// @0x1416c2200
Unk_ProxyValue88* CProxyGameObject::FUN_1416c2200()
{
    return &m_88;
}
MS2_REPLACE_METHOD(0x1416C2200, CProxyGameObject, FUN_1416c2200, 17, 0xEADCA25B);

// @0x1416c2220
Unk_ProxyHandle28 CProxyGameObject::FUN_1416c2220()
{
    return Unk_ProxyHandle28(m_28);
}
MS2_REPLACE_METHOD(0x1416C2220, CProxyGameObject, FUN_1416c2220, 65, 0xD6E756B3);

// @0x1416c2270
Vector3 CProxyGameObject::FUN_1416c2270()
{
    Unk_PosObject* obj = FUN_141bd1180(FUN_1403ed2d0(), m_proxyId);
    if (obj != 0) {
        return obj->vfunc_18();
    } else {
        return m_6c;
    }
}
MS2_REPLACE_METHOD(0x1416C2270, CProxyGameObject, FUN_1416c2270, 114, 0x6DB7BE40);

// @0x1416c22f0
void* CProxyGameObject::FUN_1416c22f0()
{
    return reinterpret_cast<void*>(m_40);
}
MS2_REPLACE_METHOD(0x1416C22F0, CProxyGameObject, FUN_1416c22f0, 15, 0x8B0075C1);

// @0x1416c2310
void* CProxyGameObject::FUN_1416c2310()
{
    return reinterpret_cast<void*>(m_48);
}
MS2_REPLACE_METHOD(0x1416C2310, CProxyGameObject, FUN_1416c2310, 15, 0x5AEB0F79);

// @0x1416c2330
unsigned short CProxyGameObject::FUN_1416c2330()
{
    return m_a8;
}
MS2_REPLACE_METHOD(0x1416C2330, CProxyGameObject, FUN_1416c2330, 18, 0xCD1B1572);

// @0x1416c2350
int CProxyGameObject::FUN_1416c2350()
{
    return m_78;
}
MS2_REPLACE_METHOD(0x1416C2350, CProxyGameObject, FUN_1416c2350, 14, 0xB1F80757);

// @0x1416c2370
int CProxyGameObject::FUN_1416c2370()
{
    return m_ac;
}
MS2_REPLACE_METHOD(0x1416C2370, CProxyGameObject, FUN_1416c2370, 17, 0x84EDFDD7);

// @0x1416c2390
int CProxyGameObject::FUN_1416c2390()
{
    return m_b0;
}
MS2_REPLACE_METHOD(0x1416C2390, CProxyGameObject, FUN_1416c2390, 17, 0x1F8D7963);

// @0x1416c23b0
CStringW CProxyGameObject::FUN_1416c23b0()
{
    if (FUN_1416c2090() != 0) {
        {
            CStringW name = FUN_1401aa6a0(m_78);
            bool found = (!name.IsEmpty() && FUN_140a7c8d0(FUN_140965990(FUN_1416c2220())) != 0);
            if (found) {
                return name;
            }
        }
    } else {
        return m_58;
    }
    return L"";
}
MS2_REPLACE_METHOD(0x1416C23B0, CProxyGameObject, FUN_1416c23b0, 352, 0xD3390841);

// @0x1416c2520
CString CProxyGameObject::FUN_1416c2520()
{
    return m_50;
}
MS2_REPLACE_METHOD(0x1416C2520, CProxyGameObject, FUN_1416c2520, 66, 0x998DDC8A);

// @0x1416c2570
CStringW CProxyGameObject::FUN_1416c2570()
{
    if (FUN_1416c1ff0() != 0) {
        return *FUN_141656d90(FUN_141bd0cc0(FUN_1403ed2d0()));
    }
    return m_60;
}
MS2_REPLACE_METHOD(0x1416C2570, CProxyGameObject, FUN_1416c2570, 133, 0x325768ED);

// @0x1416c2600
// MS2-FUNCTIONAL: byte-identical except the frame is 0x10 larger (sub rsp 0x168 vs 0x158); an unused temp slot not located
CStringW CProxyGameObject::FUN_1416c2600()
{
    if (FUN_1416c1ff0() != 0) {
        return FUN_141bd0cc0(FUN_1403ed2d0())->FUN_1415281c0();
    } else {
        {
            Unk_Handle97a h = FUN_14097a780()->FUN_140ae4880(reinterpret_cast<void*>(m_40));
            if (h.FUN_14097a170() != 0) {
                m_b4 = h.FUN_14097a1e0()->FUN_1401cc3e0();
                m_c0 = h.FUN_14097a1e0()->FUN_1401cc350();
                m_b8 = h.FUN_14097a1e0()->FUN_1401cc3a0();
                m_bc = h.FUN_14097a1e0()->FUN_1401cc3c0();
            }
        }
        if (m_b4 > 0) {
            Unk_Ptr1401cd040 ptr(FUN_1401cd040(&DAT_143b059e8));
            Unk_Local1408ad110 work;
            CStringW unused;
            if (FUN_1408a0d30(m_b8, &work, m_b4) != 0) {
                return FUN_1409796e0(m_b4, m_b8, m_bc, m_c0);
            }
        } else {
            return m_c0;
        }
    }
    return L"";
}
MS2_REPLACE_METHOD(0x1416C2600, CProxyGameObject, FUN_1416c2600, 775, 0x4AA42C46);

// @0x1416c2920
void CProxyGameObject::FUN_1416c2920()
{
    m_d0.FUN_140267c10();
}
MS2_REPLACE_METHOD(0x1416C2920, CProxyGameObject, FUN_1416c2920, 33, 0x5153CC8C);

// @0x1416c2950
Unk_ProxyValueD0* CProxyGameObject::FUN_1416c2950()
{
    if (FUN_1416c1ff0() != 0) {
        return FUN_140938ad0(FUN_1406c7600());
    }
    return &m_d0;
}
MS2_REPLACE_METHOD(0x1416C2950, CProxyGameObject, FUN_1416c2950, 54, 0x83FAF988);

// @0x1416c2990
int CProxyGameObject::FUN_1416c2990(int nTemplateId)
{
    m_78 = nTemplateId;
    m_28.FUN_140a4fe50(FUN_1406d6e90()->FUN_140a7cab0(m_78));
    m_dc = FUN_1407476c0()->FUN_14074e030(nTemplateId);
    m_e0 = FUN_14109a710()->FUN_140764cd0(nTemplateId);
    FUN_1416c2a80();
    int r;
    if (m_28.FUN_140a4ff10()) {
        r = 1;
    } else {
        r = 0;
    }
    return r;
}
MS2_REPLACE_METHOD(0x1416C2990, CProxyGameObject, FUN_1416c2990, 224, 0xA8CBDA0F);

// @0x1416c2a80
void CProxyGameObject::FUN_1416c2a80()
{
    if (FUN_1416c2090() == 0) {
        return;
    }
    if (m_dc != 0) {
        FUN_1416d12d0(FUN_140764020(), m_78, &m_88, 0);
    }
    if (m_e0 != 0) {
        m_e4 = FUN_14109a710()->FUN_140764e00(m_78);
    } else {
        m_e4 = 1;
    }
}
MS2_REPLACE_METHOD(0x1416C2A80, CProxyGameObject, FUN_1416c2a80, 157, 0x48E7C890);

// @0x1416c2b30
bool CProxyGameObject::FUN_1416c2b30()
{
    return m_e4 == 1;
}
MS2_REPLACE_METHOD(0x1416C2B30, CProxyGameObject, FUN_1416c2b30, 48, 0x552AC3F2);

// @0x1416c2b70
bool CProxyGameObject::FUN_1416c2b70()
{
    return m_e0 == 1;
}
MS2_REPLACE_METHOD(0x1416C2B70, CProxyGameObject, FUN_1416c2b70, 48, 0x4BF83D4E);

// @0x1416c2ba0
Unk_ProxyHandle18::Unk_ProxyHandle18()
{
    m_8 = 0;
}
