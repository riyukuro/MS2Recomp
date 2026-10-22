// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). User platform proxies.
// MS2-UNIT: commonfiles\userproxy.cpp
// MS2-RANGE: 0x1400be2c0-0x1400be590 .text$di
// MS2-RANGE: 0x1408e70b0-0x1408f4e20 .text$mn
// MS2-RANGE: 0x142c9cb10-0x142c9cb90 .text$yd
// MS2-RANGE: 0x142c9cbb0-0x142c9cc70 .text$yd
// The intervening 0x142c9cb90 thunk belongs to nxa::DefaultMemoryAllocator (unit_14092cb30).
// MS2-PIN: ?begin@?$_Tree@V?$_Tset_traits@_KU?$less@_K@std@@V?$allocator@_K@2@$0A@@std@@@std@@QEBA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@_K@std@@@std@@@2@XZ 0x1408f48f0 ; cf3: const overload (m_170 read through a const ref); byte-identical to the non-const one, end() 0x140341f40 is the one find() calls
// MS2-PIN: ?end@?$_Tree@V?$_Tset_traits@_KU?$less@_K@std@@V?$allocator@_K@2@$0A@@std@@@std@@QEBA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@_K@std@@@std@@@2@XZ 0x1408f4960 ; cf3: const overload (m_170 read through a const ref); byte-identical to the non-const one, end() 0x140341f40 is the one find() calls
// MS2-PIN: ??1CCNPlatformProxy@@UEAA@XZ 0x1408f2420
// MS2-PIN: ??__Es_proxySortA@@YAXXZ 0x1400be2c0
// MS2-PIN: ??__Es_proxyKeys@@YAXXZ 0x1400be380
// MS2-PIN: ??__Es_proxySortB@@YAXXZ 0x1400be3b0
// MS2-PIN: ??__Es_proxyEmpty@@YAXXZ 0x1400be470
// MS2-PIN: ??__Es_proxyEventA@@YAXXZ 0x1400be4a0
// MS2-PIN: ??__Es_proxyTreeA@@YAXXZ 0x1400be4d0
// MS2-PIN: ??__Es_proxyEventB@@YAXXZ 0x1400be500
// MS2-PIN: ??__Es_proxyTreeB@@YAXXZ 0x1400be530
// MS2-PIN: ??__Es_proxyMap@@YAXXZ 0x1400be560
// MS2-PIN: ??_GCJPPlatformProxy@@UEAAPEAXI@Z 0x1408f29f0
// MS2-PIN: ??_GCKRPlatformProxy@@UEAAPEAXI@Z 0x1408f2a30
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\userproxy.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <algorithm>
#include "userproxy.h"
#include "ms2/placeholder/cuserplayinfoproxy.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
class Unk_ProxyInput {
public:
  virtual bool vfunc_0();
  virtual unsigned char vfunc_1();
  virtual short vfunc_2();
  virtual int vfunc_3();
  virtual __int64 vfunc_4();
  virtual float vfunc_5();
  virtual CString vfunc_6();
};
struct Unk_ProxyPacketPrefix {
  void *p0;
  Unk_ProxyInput input;
};
#define PROXY_INPUT(p) (&reinterpret_cast<Unk_ProxyPacketPrefix *>(&(p))->input)
template <class T> T ClampProxyValue(const T &x, T lo, T hi) {
  if (x < lo)
    return lo;
  if (hi < x)
    return hi;
  return x;
}
extern int DAT_143ab0248; // platform setting owned by the configuration unit

void FUN_14083d2b0(CStringW &);
__int64 FUN_140869440();
unsigned char FUN_14028da10();
CStringW FUN_1405c2690(CStringW, const CStringW &);
#define PROXY_STREAM(p) (reinterpret_cast<CInputStream *>(reinterpret_cast<char *>(p) + 8))
#define PROXY_BITS_ASSERT(line)                                                                              \
  (void)((!!(0)) || (_wassert(L"0", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\bitset.inl", line), 0))
#include "ms2/placeholder/citem.h"
class Unk_UserProxyItemData {
public:
  int FUN_140599fd0(int);
};
unsigned FUN_140869420();

#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/gameeventuservalue.h"
class Unk_ProxyStaticTreeA {
public:
  Unk_ProxyStaticTreeA();
  ~Unk_ProxyStaticTreeA();

private:
  void *m_0;
  size_t m_8;
};
class Unk_ProxyStaticTreeB {
public:
  Unk_ProxyStaticTreeB();
  ~Unk_ProxyStaticTreeB();

private:
  void *m_0;
  size_t m_8;
};
class Unk_ProxyStaticMap {
public:
  Unk_ProxyStaticMap(int);
  ~Unk_ProxyStaticMap();

private:
  void *m_0;
  void *m_8;
  void *m_10;
  void *m_18;
  size_t m_20;
  void *m_28;
};
MS2_CHECK_SIZE(Unk_ProxyStaticTreeA, 0x10);
MS2_CHECK_SIZE(Unk_ProxyStaticTreeB, 0x10);
MS2_CHECK_SIZE(Unk_ProxyStaticMap, 0x30);
static CString s_proxySortA[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static UICommon::CMyPCKeyInputController s_proxyKeys;
static CString s_proxySortB[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_proxyEmpty;
static GameEventUserValue s_proxyEventA;
static Unk_ProxyStaticTreeA s_proxyTreeA;
static GameEventUserValue s_proxyEventB;
static Unk_ProxyStaticTreeB s_proxyTreeB;
static Unk_ProxyStaticMap s_proxyMap(10);
// @0x1408e70b0
CPlatformProxy::CPlatformProxy() { vfunc_1(); }

// @0x1408e7100
void CPlatformProxy::vfunc_1() {
  m_20 = 0;
  m_24 = 0;
  m_18 = 0;
}
MS2_REPLACE_METHOD(0x1408E7100, CPlatformProxy, vfunc_1, 43, 0xAC8795C9);

// @0x1408e7140
void CPlatformProxy::vfunc_2(CPlatformProxy *p) {
  if (!p)
    return;
  m_20 = p->m_20;
  m_24 = p->m_24;
}
MS2_REPLACE_METHOD(0x1408E7140, CPlatformProxy, vfunc_2, 53, 0x464E85E3);

// @0x1408e7180
void CPlatformProxy::vfunc_3(COutputStream &s) {
  s.WriteInt32(m_20);
  s.WriteInt32(m_24);
}
MS2_REPLACE_METHOD(0x1408E7180, CPlatformProxy, vfunc_3, 67, 0x25E24290);

// @0x1408e71d0
void CPlatformProxy::vfunc_4(CInputStream &s) {
  m_20 = s.ReadInt32();
  m_24 = s.ReadInt32();
}
MS2_REPLACE_METHOD(0x1408E71D0, CPlatformProxy, vfunc_4, 67, 0xA01F94A0);

// @0x1408e7220
void CPlatformProxy::FUN_1408e7220(CString) {}
MS2_REPLACE_METHOD(0x1408E7220, CPlatformProxy, FUN_1408e7220, 30, 0x63D39D29);

// @0x1408e7250
Unk_UserProxyPtr<CPlatformProxy> FUN_1408e7250() {
  Unk_UserProxyPtr<CPlatformProxy> p(0);
  switch (DAT_143ab0248) {
  case 0:
    p = new CKRPlatformProxy;
    break;
  case 1:
    p = new CJPPlatformProxy;
    break;
  case 2:
    p = new CNAPlatformProxy;
    break;
  case 3:
    p = new CCNPlatformProxy;
    break;
  default:
    MS2_ASSERT_AT(100, FALSE);
    break;
  }
  return p;
}

// @0x1408e7460
CKRPlatformProxy::CKRPlatformProxy() { vfunc_1(); }

// @0x1408e74d0
void CKRPlatformProxy::vfunc_1() {
  CPlatformProxy::vfunc_1();
  m_28 = 0;
  vfunc_11("");
  m_30 = 0;
  m_34 = 0;
  m_38 = 0;
  m_40 = 0;
}
MS2_REPLACE_METHOD(0x1408E74D0, CKRPlatformProxy, vfunc_1, 140, 0xDE440B37);

// @0x1408e7570
void CKRPlatformProxy::vfunc_2(CPlatformProxy *p) {
  if (!p)
    return;
  CPlatformProxy::vfunc_2(p);
  CKRPlatformProxy *q = static_cast<CKRPlatformProxy *>(p);
  if (!q)
    return;
  m_28 = q->m_28;
  vfunc_11(q->vfunc_10());
  m_30 = q->m_30;
  m_34 = q->m_34;
  m_38 = q->m_38;
  m_40 = q->m_40;
}
MS2_REPLACE_METHOD(0x1408E7570, CKRPlatformProxy, vfunc_2, 211, 0x02E2A179);

// @0x1408e7650
void CKRPlatformProxy::vfunc_3(COutputStream &s) {
  CPlatformProxy::vfunc_3(s);
  s.WriteInt64(m_28);
  s.WriteUnicodeStringA(vfunc_10());
  s.WriteInt32(m_30);
  s.WriteInt32(m_34);
  s.WriteInt32(m_38);
  s.WriteInt64(m_40);
}
MS2_REPLACE_METHOD(0x1408E7650, CKRPlatformProxy, vfunc_3, 234, 0x80EF786A);

// @0x1408e7740
void CKRPlatformProxy::vfunc_4(CInputStream &s) {
  CPlatformProxy::vfunc_4(s);
  m_28 = s.ReadInt64();
  vfunc_11(s.ReadUnicodeStringA());
  m_30 = s.ReadInt32();
  m_34 = s.ReadInt32();
  m_38 = s.ReadInt32();
  m_40 = s.ReadInt64();
}
MS2_REPLACE_METHOD(0x1408E7740, CKRPlatformProxy, vfunc_4, 213, 0xAD92B6B5);

// @0x1408e7820
void CKRPlatformProxy::vfunc_5(COutputStream &s) {
  s.WriteUnicodeStringA(vfunc_10());
  s.WriteInt64(m_28);
}
MS2_REPLACE_METHOD(0x1408E7820, CKRPlatformProxy, vfunc_5, 122, 0x6F516B6C);

// @0x1408e78a0
void CKRPlatformProxy::vfunc_6(CInPacket &p) {
  vfunc_11(PROXY_INPUT(p)->vfunc_6());
  m_28 = PROXY_INPUT(p)->vfunc_4();
}
MS2_REPLACE_METHOD(0x1408E78A0, CKRPlatformProxy, vfunc_6, 137, 0x6C0521C6);

// @0x1408e7930
__int64 CKRPlatformProxy::vfunc_28() {
  MS2_ASSERT_AT(196, 0);
  return 0;
}
MS2_REPLACE_METHOD(0x1408E7930, CKRPlatformProxy, vfunc_28, 50, 0x175620FD);

// @0x1408e7970
__int64 CKRPlatformProxy::vfunc_33() {
  MS2_ASSERT_AT(216, 0);
  return 0;
}
MS2_REPLACE_METHOD(0x1408E7970, CKRPlatformProxy, vfunc_33, 50, 0xEBE21645);

// @0x1408e79b0
CJPPlatformProxy::CJPPlatformProxy() { vfunc_1(); }

// @0x1408e7a20
void CJPPlatformProxy::vfunc_1() {
  CPlatformProxy::vfunc_1();
  m_28 = 0;
  vfunc_11("");
  m_30 = 0;
  m_34 = 0;
  m_38 = 0;
  m_40 = 0;
}
MS2_REPLACE_METHOD(0x1408E7A20, CJPPlatformProxy, vfunc_1, 140, 0x35AF83B0);

// @0x1408e7ac0
void CJPPlatformProxy::vfunc_2(CPlatformProxy *p) {
  if (!p)
    return;
  CPlatformProxy::vfunc_2(p);
  CJPPlatformProxy *q = static_cast<CJPPlatformProxy *>(p);
  if (!q)
    return;
  m_28 = q->m_28;
  vfunc_11(q->vfunc_10());
  m_30 = q->m_30;
  m_34 = q->m_34;
  m_38 = q->m_38;
  m_40 = q->m_40;
}
MS2_REPLACE_METHOD(0x1408E7AC0, CJPPlatformProxy, vfunc_2, 211, 0xF3B5A00C);

// @0x1408e7ba0
void CJPPlatformProxy::vfunc_3(COutputStream &s) {
  CPlatformProxy::vfunc_3(s);
  s.WriteInt64(m_28);
  s.WriteUnicodeStringA(vfunc_10());
  s.WriteInt32(m_30);
  s.WriteInt32(m_34);
  s.WriteInt32(m_38);
  s.WriteInt64(m_40);
}
MS2_REPLACE_METHOD(0x1408E7BA0, CJPPlatformProxy, vfunc_3, 234, 0x8AD5D2B1);

// @0x1408e7c90
void CJPPlatformProxy::vfunc_4(CInputStream &s) {
  CPlatformProxy::vfunc_4(s);
  m_28 = s.ReadInt64();
  vfunc_11(s.ReadUnicodeStringA());
  m_30 = s.ReadInt32();
  m_34 = s.ReadInt32();
  m_38 = s.ReadInt32();
  m_40 = s.ReadInt64();
}
MS2_REPLACE_METHOD(0x1408E7C90, CJPPlatformProxy, vfunc_4, 213, 0x00F30584);

// @0x1408e7d70
void CJPPlatformProxy::vfunc_5(COutputStream &s) {
  s.WriteUnicodeStringA(vfunc_10());
  s.WriteInt64(m_28);
}
MS2_REPLACE_METHOD(0x1408E7D70, CJPPlatformProxy, vfunc_5, 122, 0x5D5AF482);

// @0x1408e7df0
void CJPPlatformProxy::vfunc_6(CInPacket &p) {
  vfunc_11(PROXY_INPUT(p)->vfunc_6());
  m_28 = PROXY_INPUT(p)->vfunc_4();
}
MS2_REPLACE_METHOD(0x1408E7DF0, CJPPlatformProxy, vfunc_6, 137, 0x6C0521C6);

// @0x1408e7e80
__int64 CJPPlatformProxy::vfunc_28() {
  MS2_ASSERT_AT(309, 0);
  return 0;
}
MS2_REPLACE_METHOD(0x1408E7E80, CJPPlatformProxy, vfunc_28, 50, 0x99EBBAA1);

// @0x1408e7ec0
__int64 CJPPlatformProxy::vfunc_33() {
  MS2_ASSERT_AT(329, 0);
  return 0;
}
MS2_REPLACE_METHOD(0x1408E7EC0, CJPPlatformProxy, vfunc_33, 50, 0xF09CCB10);

// @0x1408e7f00
CCNPlatformProxy::CCNPlatformProxy() { vfunc_1(); }

// @0x1408e7f50
void CCNPlatformProxy::vfunc_1() {
  CPlatformProxy::vfunc_1();
  m_28 = 0;
  m_30 = 0;
  m_40 = 0;
  m_38 = 0;
  m_44 = 0;
  m_48 = 0;
  m_4c = 1.0f;
  m_50 = 0;
  m_58 = 0;
  m_60 = 0;
  m_68 = 0;
  m_70 = 0;
  m_74 = 0;
  m_78 = 0;
}
MS2_REPLACE_METHOD(0x1408E7F50, CCNPlatformProxy, vfunc_1, 203, 0xAF96764B);

// @0x1408e8030
void CCNPlatformProxy::vfunc_2(CPlatformProxy *p) {
  if (!p)
    return;
  CPlatformProxy::vfunc_2(p);
  CCNPlatformProxy *q = static_cast<CCNPlatformProxy *>(p);
  if (!q)
    return;
  m_28 = q->m_28;
  m_38 = q->m_38;
  m_44 = q->m_44;
  m_48 = q->m_48;
  m_4c = q->m_4c;
  m_50 = q->m_50;
  m_58 = q->m_58;
  m_60 = q->m_60;
  m_68 = q->m_68;
  m_70 = q->m_70;
  m_74 = q->m_74;
  m_78 = q->m_78;
}
MS2_REPLACE_METHOD(0x1408E8030, CCNPlatformProxy, vfunc_2, 274, 0x754E57DD);

// @0x1408e8150
void CCNPlatformProxy::vfunc_3(COutputStream &s) {
  CPlatformProxy::vfunc_3(s);
  s.WriteInt64(m_28);
  s.WriteInt64(m_38);
  s.WriteUInt8(m_44);
  s.WriteUInt8(m_48);
  s.WriteFloat(m_4c);
  s.WriteUInt8(m_50);
  s.WriteInt64(m_58);
  s.WriteUInt8(m_60);
  s.WriteInt64(m_68);
  s.WriteInt32(m_70);
  s.WriteUInt8(m_74);
  s.WriteInt32(m_78);
}
MS2_REPLACE_METHOD(0x1408E8150, CCNPlatformProxy, vfunc_3, 333, 0x6E9A8C02);

// @0x1408e82b0
void CCNPlatformProxy::vfunc_4(CInputStream &s) {
  CPlatformProxy::vfunc_4(s);
  m_28 = s.ReadInt64();
  m_38 = s.ReadInt64();
  m_44 = s.ReadUInt8();
  m_48 = s.ReadUInt8();
  m_4c = s.ReadFloat();
  m_50 = s.ReadUInt8();
  m_58 = s.ReadInt64();
  m_60 = s.ReadUInt8();
  m_68 = s.ReadInt64();
  m_70 = s.ReadInt32();
  m_74 = s.ReadUInt8();
  m_78 = s.ReadInt32();
}
MS2_REPLACE_METHOD(0x1408E82B0, CCNPlatformProxy, vfunc_4, 343, 0xC11FE026);

// @0x1408e8410
void CCNPlatformProxy::vfunc_5(COutputStream &s) {
  s.WriteInt32(m_70);
  s.WriteInt64(m_28);
  s.WriteUInt8(m_74);
  s.WriteInt32(m_78);
}
MS2_REPLACE_METHOD(0x1408E8410, CCNPlatformProxy, vfunc_5, 117, 0xEA4DFB02);

// @0x1408e8490
void CCNPlatformProxy::vfunc_6(CInPacket &p) {
  m_70 = PROXY_INPUT(p)->vfunc_3();
  m_28 = PROXY_INPUT(p)->vfunc_4();
  m_74 = PROXY_INPUT(p)->vfunc_1();
  m_78 = PROXY_INPUT(p)->vfunc_3();
}
MS2_REPLACE_METHOD(0x1408E8490, CCNPlatformProxy, vfunc_6, 191, 0x55A39773);

// @0x1408e8560
void CCNPlatformProxy::vfunc_29(__int64 p) {
  if (p < 0)
    return;
  m_58 = p;
}
MS2_REPLACE_METHOD(0x1408E8560, CCNPlatformProxy, vfunc_29, 35, 0xCC88322A);

// @0x1408e8590
void CCNPlatformProxy::vfunc_30() {
  vfunc_27(0);
  vfunc_29(0);
}
MS2_REPLACE_METHOD(0x1408E8590, CCNPlatformProxy, vfunc_30, 56, 0x734EA921);

// @0x1408e85d0
void CCNPlatformProxy::vfunc_34(__int64 p) {
  if (p < 0)
    return;
  m_68 = p;
}
MS2_REPLACE_METHOD(0x1408E85D0, CCNPlatformProxy, vfunc_34, 35, 0xAC12D17A);

// @0x1408e8600
void CCNPlatformProxy::vfunc_35() {
  vfunc_32(0);
  vfunc_34(0);
}
MS2_REPLACE_METHOD(0x1408E8600, CCNPlatformProxy, vfunc_35, 56, 0x9A175C9F);

// @0x1408e8640
void CCNPlatformProxy::vfunc_36(int p) { m_70 = p; }
MS2_REPLACE_METHOD(0x1408E8640, CCNPlatformProxy, vfunc_36, 22, 0x161CE143);

// @0x1408e8660
int CCNPlatformProxy::vfunc_37() { return m_70; }
MS2_REPLACE_METHOD(0x1408E8660, CCNPlatformProxy, vfunc_37, 14, 0x81E2A10F);

// @0x1408e8680
int CCNPlatformProxy::vfunc_38() { return m_74; }
MS2_REPLACE_METHOD(0x1408E8680, CCNPlatformProxy, vfunc_38, 14, 0x99EEE733);

// @0x1408e86a0
void CCNPlatformProxy::vfunc_39(int p) { m_74 = p; }
MS2_REPLACE_METHOD(0x1408E86A0, CCNPlatformProxy, vfunc_39, 22, 0xFE13C11F);

// @0x1408e86c0
CNAPlatformProxy::CNAPlatformProxy() { vfunc_1(); }

// @0x1408e87b0
void CNAPlatformProxy::vfunc_1() {
  CPlatformProxy::vfunc_1();
  m_28 = 0;
  vfunc_11("");
  vfunc_41("");
  vfunc_43(0);
  vfunc_45(0);
  vfunc_47(0);
  vfunc_49("");
  vfunc_63("");
  vfunc_65("");
  vfunc_67("");
  vfunc_59("");
  m_78 = 0;
  m_80 = 0;
  m_88 = 0;
  m_90 = 0;
  m_98 = 0;
}
MS2_REPLACE_METHOD(0x1408E87B0, CNAPlatformProxy, vfunc_1, 675, 0x6CBB8D5B);

// @0x1408e8a60
void CNAPlatformProxy::vfunc_2(CPlatformProxy *p) {
  if (!p)
    return;
  CPlatformProxy::vfunc_2(p);
  CNAPlatformProxy *q = static_cast<CNAPlatformProxy *>(p);
  if (!q)
    return;
  m_28 = q->m_28;
  vfunc_11(q->vfunc_10());
  vfunc_41(q->vfunc_40());
  vfunc_43(q->m_40);
  vfunc_45(q->m_48);
  vfunc_47(q->m_50);
  vfunc_49(q->vfunc_48());
  vfunc_63(q->m_60);
  vfunc_65(q->m_68);
  vfunc_67(q->m_70);
  vfunc_59(q->vfunc_58());
  m_78 = q->m_78;
  m_80 = q->m_80;
  m_88 = q->m_88;
  m_90 = q->m_90;
  m_98 = q->m_98;
}
MS2_REPLACE_METHOD(0x1408E8A60, CNAPlatformProxy, vfunc_2, 761, 0x59591B6D);

// @0x1408e8d60
void CNAPlatformProxy::vfunc_3(COutputStream &s) {
  CPlatformProxy::vfunc_3(s);
  s.WriteInt64(m_28);
  s.WriteUnicodeStringA(vfunc_10());
  s.WriteString(vfunc_40());
  s.WriteInt32(static_cast<unsigned>(vfunc_42()));
  s.WriteInt64(vfunc_44());
  s.WriteUInt8(vfunc_46());
  s.WriteString(vfunc_48());
  s.WriteString(vfunc_58());
  s.WriteInt64(m_78);
  s.WriteInt64(m_80);
  s.WriteInt64(m_88);
  s.WriteInt32(m_90);
  s.WriteInt64(m_98);
}
MS2_REPLACE_METHOD(0x1408E8D60, CNAPlatformProxy, vfunc_3, 808, 0x02A975D6);

// @0x1408e9090
void CNAPlatformProxy::vfunc_4(CInputStream &s) {
  CPlatformProxy::vfunc_4(s);
  m_28 = s.ReadInt64();
  vfunc_11(s.ReadUnicodeStringA());
  vfunc_41(s.ReadString());
  vfunc_43(static_cast<float>(static_cast<unsigned>(s.ReadInt32())));
  vfunc_45(s.ReadInt64());
  vfunc_47(s.ReadUInt8());
  vfunc_49(s.ReadString());
  vfunc_59(s.ReadString());
  m_78 = s.ReadInt64();
  m_80 = s.ReadInt64();
  m_88 = s.ReadInt64();
  m_90 = s.ReadInt32();
  m_98 = s.ReadInt64();
}
MS2_REPLACE_METHOD(0x1408E9090, CNAPlatformProxy, vfunc_4, 731, 0xCFCEEF50);

// @0x1408e9380
void CNAPlatformProxy::vfunc_5(COutputStream &s) {
  s.WriteUnicodeStringA(vfunc_10());
  s.WriteInt64(m_28);
  s.WriteInt64(m_80);
  s.WriteInt64(m_88);
}
MS2_REPLACE_METHOD(0x1408E9380, CNAPlatformProxy, vfunc_5, 178, 0x9DCFA658);

// @0x1408e9440
void CNAPlatformProxy::vfunc_6(CInPacket &p) {
  vfunc_11(PROXY_INPUT(p)->vfunc_6());
  m_28 = PROXY_INPUT(p)->vfunc_4();
  m_80 = PROXY_INPUT(p)->vfunc_4();
  m_88 = PROXY_INPUT(p)->vfunc_4();
}
MS2_REPLACE_METHOD(0x1408E9440, CNAPlatformProxy, vfunc_6, 229, 0xAEC91AE2);

// @0x1408e9530
CString CNAPlatformProxy::vfunc_58() {
  if (m_a0.IsEmpty())
    return "US";
  return m_a0;
}
MS2_REPLACE_METHOD(0x1408E9530, CNAPlatformProxy, vfunc_58, 131, 0x9B23867D);

// @0x1408e95c0
UserPlayCommonInfoData::UserPlayCommonInfoData() { FUN_1408e9610(); }

// @0x1408e9610
void UserPlayCommonInfoData::FUN_1408e9610() {
  m_18 = 0;
  m_1c = 0;
  m_20 = 0;
  m_24 = 0;
  m_28 = 0;
  m_30 = 0;
  m_38 = 0;
  m_40 = 0;
  m_48 = 0;
  m_50 = 0;
  m_60 = 0;
  m_58 = 0;
  m_68 = 0;
  m_6c = 0;
  m_70 = 0;
  m_74 = 0;
  m_78 = 0;
  m_80 = 0;
  m_84 = 0;
  m_88 = 0;
  m_8c = 0;
  m_90 = 0;
  m_94 = 0;
  m_98 = 0;
  m_9c = 0;
  m_a0 = 0;
  m_a4 = 0;
  m_a8 = 0;
  m_ac = 0;
  m_b0 = 0;
  m_b4 = 0;
  m_b8 = 0;
  m_bc = 0;
}
MS2_REPLACE_METHOD(0x1408E9610, UserPlayCommonInfoData, FUN_1408e9610, 458, 0xACFCB653);

// @0x1408e97e0
void UserPlayCommonInfoData::FUN_1408e97e0(COutputStream &s) {
  s.WriteInt32(m_18);
  s.WriteInt16(m_1c);
  s.WriteInt32(m_20);
  s.WriteInt32(m_24);
  s.WriteInt64(m_28);
  s.WriteInt64(m_30);
  s.WriteInt64(m_38);
  s.WriteInt64(m_40);
  s.WriteInt64(m_48);
  s.WriteInt64(m_50);
  s.WriteInt64(m_60);
  s.WriteInt32(m_68);
  s.WriteInt32(m_6c);
  s.WriteInt32(m_70);
  s.WriteInt32(m_74);
  s.WriteInt64(m_78);
  s.WriteInt32(m_80);
  s.WriteInt32(m_84);
  s.WriteInt32(m_88);
  s.WriteInt32(m_8c);
  s.WriteInt32(m_90);
  s.WriteInt32(m_94);
  s.WriteInt32(m_98);
  s.WriteInt32(m_9c);
  s.WriteInt32(m_a0);
  s.WriteInt32(m_a4);
  s.WriteInt32(m_a8);
  s.WriteInt32(m_ac);
  s.WriteInt32(m_b0);
  s.WriteInt32(m_b4);
  s.WriteInt32(m_b8);
  s.WriteInt32(m_bc);
}
MS2_REPLACE_METHOD(0x1408E97E0, UserPlayCommonInfoData, FUN_1408e97e0, 844, 0xF60073B5);

// @0x1408e9b40
void UserPlayCommonInfoData::FUN_1408e9b40(CInputStream &s) {
  m_18 = s.ReadInt32();
  m_1c = s.ReadInt16();
  m_20 = s.ReadInt32();
  m_24 = s.ReadInt32();
  m_28 = s.ReadInt64();
  m_30 = s.ReadInt64();
  m_38 = s.ReadInt64();
  m_40 = s.ReadInt64();
  m_48 = s.ReadInt64();
  m_50 = s.ReadInt64();
  m_60 = s.ReadInt64();
  m_68 = s.ReadInt32();
  m_6c = s.ReadInt32();
  m_70 = s.ReadInt32();
  m_74 = s.ReadInt32();
  m_78 = s.ReadInt64();
  m_80 = s.ReadInt32();
  m_84 = s.ReadInt32();
  m_88 = s.ReadInt32();
  m_8c = s.ReadInt32();
  m_90 = s.ReadInt32();
  m_94 = s.ReadInt32();
  m_98 = s.ReadInt32();
  m_9c = s.ReadInt32();
  m_a0 = s.ReadInt32();
  m_a4 = s.ReadInt32();
  m_a8 = s.ReadInt32();
  m_ac = s.ReadInt32();
  m_b0 = s.ReadInt32();
  m_b4 = s.ReadInt32();
  m_b8 = s.ReadInt32();
  m_bc = s.ReadInt32();
}
MS2_REPLACE_METHOD(0x1408E9B40, UserPlayCommonInfoData, FUN_1408e9b40, 844, 0x315EC51A);

// @0x1408e9ea0
CUserPlayInfoProxy::CUserPlayInfoProxy() { m_198 = 0; }

// @0x1408e9f20
void CUserPlayInfoProxy::FUN_1408e9f20() {
  m_18.FUN_1408e9610();
  m_d8.FUN_1408e9610();
}
MS2_REPLACE_METHOD(0x1408E9F20, CUserPlayInfoProxy, FUN_1408e9f20, 50, 0xCF67A5F8);

// @0x1408e9f60
void CUserPlayInfoProxy::FUN_1408e9f60() {
  m_18.m_18 += m_d8.m_18;
  m_18.m_1c += m_d8.m_1c;
  m_18.m_20 += m_d8.m_20;
  m_18.m_24 += m_d8.m_24;
  m_18.m_28 += m_d8.m_28;
  m_18.m_30 += m_d8.m_30;
  m_18.m_38 += m_d8.m_38;
  m_18.m_40 += m_d8.m_40;
  m_18.m_48 += m_d8.m_48;
  m_18.m_50 += m_d8.m_50;
  m_18.m_60 += m_d8.m_60;
  m_18.m_68 += m_d8.m_68;
  m_18.m_6c += m_d8.m_6c;
  m_18.m_70 += m_d8.m_70;
  m_18.m_74 += m_d8.m_74;
  m_18.m_78 = m_d8.m_78;
  m_18.m_80 += m_d8.m_80;
  m_18.m_84 += m_d8.m_84;
  m_18.m_88 += m_d8.m_88;
  m_18.m_8c += m_d8.m_8c;
  m_18.m_90 += m_d8.m_90;
  m_18.m_94 += m_d8.m_94;
  m_18.m_98 += m_d8.m_98;
  m_18.m_9c += m_d8.m_9c;
  m_18.m_a0 = m_d8.m_a0;
  m_18.m_a4 = m_d8.m_a4;
  m_18.m_a8 = m_d8.m_a8;
  m_18.m_ac += m_d8.m_ac;
  m_18.m_b0 += m_d8.m_b0;
  m_18.m_b4 += m_d8.m_b4;
  m_18.m_b8 += m_d8.m_b8;
  m_18.m_bc += m_d8.m_bc;
}
MS2_REPLACE_METHOD(0x1408E9F60, CUserPlayInfoProxy, FUN_1408e9f60, 982, 0x361C54E2);

// @0x1408ea340
void CUserPlayInfoProxy::FUN_1408ea340() { m_d8.FUN_1408e9610(); }
MS2_REPLACE_METHOD(0x1408EA340, CUserPlayInfoProxy, FUN_1408ea340, 33, 0x8B703A56);

// @0x1408ea370
Unk_UserProxyFlagsPacket::Unk_UserProxyFlagsPacket() {
  m_0 = 0;
  m_8 = 0;
  m_c = 0;
  m_10 = 0;
}

// @0x1408ea3b0
void Unk_UserProxyFlagsPacket::CopyFrom(Unk_UserProxy *p) {
  m_0 = p->m_0;
  m_8 = p->m_44;
  m_c = p->m_48;
  m_10 = p->m_4c;
}
MS2_REPLACE_METHOD(0x1408EA3B0, Unk_UserProxyFlagsPacket, CopyFrom, 77, 0x84FB5DC5);

// @0x1408ea410
void Unk_UserProxyFlagsPacket::Encode(COutputStream &s) {
  s.WriteInt64(m_0);
  s.WriteInt32(m_8);
  s.WriteInt32(m_c);
  s.WriteInt16(m_10);
}
MS2_REPLACE_METHOD(0x1408EA410, Unk_UserProxyFlagsPacket, Encode, 116, 0x421C9A5D);

// @0x1408ea490
void Unk_UserProxyFlagsPacket::Decode(CInPacket &p) {
  m_0 = PROXY_STREAM(&p)->ReadInt64();
  m_8 = PROXY_STREAM(&p)->ReadInt32();
  m_c = PROXY_STREAM(&p)->ReadInt32();
  m_10 = PROXY_STREAM(&p)->ReadInt16();
}
MS2_REPLACE_METHOD(0x1408EA490, Unk_UserProxyFlagsPacket, Decode, 188, 0x3F191422);

// @0x1408ea560
Unk_UserProxyClubPacket::Unk_UserProxyClubPacket() {
  m_0 = 0;
  m_8 = 0;
  m_10.Empty();
  m_18 = 0;
  m_20.FUN_14020c9e0();
}

// @0x1408ea600
void Unk_UserProxyClubPacket::CopyFrom(Unk_UserProxy *p) {
  m_0 = p->m_0;
  m_8 = p->m_8;
  m_10 = p->FUN_1408f19e0();
  m_18 = p->m_80;
  ATL::CAtlArray<MS2Ptr<Club::NameInfo>> clubs;
  p->FUN_1408f17c0(clubs);
  for (size_t i = 0; i < clubs.GetCount(); ++i)
    m_20.FUN_14020cc00(clubs[i]);
}
MS2_REPLACE_METHOD(0x1408EA600, Unk_UserProxyClubPacket, CopyFrom, 328, 0x4B1F5988);

// @0x1408ea750
void Unk_UserProxyClubPacket::Encode(COutputStream &s) {
  s.WriteInt64(m_0);
  s.WriteInt64(m_8);
  s.WriteUnicodeString(m_10);
  s.WriteInt64(m_18);
  m_20.FUN_14020ce50(s);
}
MS2_REPLACE_METHOD(0x1408EA750, Unk_UserProxyClubPacket, Encode, 153, 0xC49C542A);

// @0x1408ea7f0
void Unk_UserProxyClubPacket::Decode(CInPacket &p) {
  m_0 = PROXY_STREAM(&p)->ReadInt64();
  m_8 = PROXY_STREAM(&p)->ReadInt64();
  m_10 = PROXY_STREAM(&p)->ReadUnicodeString();
  m_18 = PROXY_STREAM(&p)->ReadInt64();
  m_20.FUN_14020cfc0(*PROXY_STREAM(&p));
}
MS2_REPLACE_METHOD(0x1408EA7F0, Unk_UserProxyClubPacket, Decode, 271, 0x90EB5F0A);

// @0x1408ea910
void Unk_UserProxyClubPacket::GetClubs(ATL::CAtlArray<MS2Ptr<Club::NameInfo>> &out) {
  m_20.FUN_14020cce0(out);
}
MS2_REPLACE_METHOD(0x1408EA910, Unk_UserProxyClubPacket, GetClubs, 41, 0xB79CA5D6);

// @0x1408ea940
Unk_UserProxyStatsPacket::Unk_UserProxyStatsPacket() {
  m_0 = 0;
  m_8 = 0;
  m_c = 0;
  m_10 = 0;
}

// @0x1408ea990
void Unk_UserProxyStatsPacket::CopyFrom(Unk_UserProxy *p) {
  m_0 = p->m_0;
  m_8 = p->m_28;
  m_c = p->m_2c;
  m_10 = p->m_30;
}
MS2_REPLACE_METHOD(0x1408EA990, Unk_UserProxyStatsPacket, CopyFrom, 75, 0x36C08A5A);

// @0x1408ea9f0
void Unk_UserProxyStatsPacket::Encode(COutputStream &s) {
  s.WriteInt64(m_0);
  s.WriteInt32(m_8);
  s.WriteInt32(m_c);
  s.WriteInt32(m_10);
}
MS2_REPLACE_METHOD(0x1408EA9F0, Unk_UserProxyStatsPacket, Encode, 115, 0x690D8CE0);

// @0x1408eaa70
void Unk_UserProxyStatsPacket::Decode(CInPacket &p) {
  m_0 = PROXY_STREAM(&p)->ReadInt64();
  m_8 = PROXY_STREAM(&p)->ReadInt32();
  m_c = PROXY_STREAM(&p)->ReadInt32();
  m_10 = PROXY_STREAM(&p)->ReadInt32();
}
MS2_REPLACE_METHOD(0x1408EAA70, Unk_UserProxyStatsPacket, Decode, 187, 0x42E6C1A0);

// @0x1408eab40
Unk_UserProxySummaryPacket::Unk_UserProxySummaryPacket() {
  m_8.Empty();
  m_0 = 0;
  m_10 = 0;
  m_14 = 0;
  m_18 = 1;
  m_1c = 0;
  m_20 = 0;
  m_24 = 0;
  m_40.FUN_14020c9e0();
  m_88 = FUN_1408e7250();
  m_98.Empty();
  m_a0 = 0;
}

// @0x1408eacb0
void Unk_UserProxySummaryPacket::CopyFrom(Unk_UserProxy *p) {
  m_0 = p->m_8;
  m_8 = p->FUN_1408f19e0();
  m_10 = p->m_14;
  m_14 = p->m_28;
  m_18 = p->m_34;
  m_24 = p->m_78;
  m_28 = p->m_80;
  m_30 = p->FUN_1408f1b60();
  m_38 = p->FUN_1408f1a60();
  ATL::CAtlArray<MS2Ptr<Club::NameInfo>> clubs;
  p->FUN_1408f17c0(clubs);
  for (size_t i = 0; i < clubs.GetCount(); ++i)
    m_40.FUN_14020cc00(clubs[i]);
  if (m_88.get())
    m_88->vfunc_2(p->m_330.get());
  m_98 = p->FUN_1408f1c60();
  m_a0 = p->m_88;
}
MS2_REPLACE_METHOD(0x1408EACB0, Unk_UserProxySummaryPacket, CopyFrom, 798, 0xA735BE14);

// @0x1408eafe0
void Unk_UserProxySummaryPacket::Encode(COutputStream &s) {
  s.WriteInt64(m_0);
  s.WriteUnicodeString(m_8);
  s.WriteUInt8(m_10);
  s.WriteInt32(m_14);
  s.WriteInt16(m_18);
  s.WriteInt32(m_1c);
  s.WriteInt32(m_20);
  s.WriteUInt8(m_24);
  s.WriteInt64(m_28);
  s.WriteUnicodeString(m_30);
  s.WriteUnicodeStringA(m_38);
  m_40.FUN_14020ce50(s);
  if (m_88.get())
    m_88->vfunc_3(s);
  s.WriteString(m_98);
  s.WriteInt64(m_a0);
}
MS2_REPLACE_METHOD(0x1408EAFE0, Unk_UserProxySummaryPacket, Encode, 488, 0x5B3A756C);

// @0x1408eb1d0
void Unk_UserProxySummaryPacket::Decode(CInPacket *p) {
  m_0 = PROXY_STREAM(p)->ReadInt64();
  m_8 = PROXY_STREAM(p)->ReadUnicodeString();
  m_10 = PROXY_STREAM(p)->ReadUInt8();
  m_14 = PROXY_STREAM(p)->ReadInt32();
  m_18 = PROXY_STREAM(p)->ReadInt16();
  m_1c = PROXY_STREAM(p)->ReadInt32();
  m_20 = PROXY_STREAM(p)->ReadInt32();
  m_24 = PROXY_STREAM(p)->ReadUInt8();
  m_28 = PROXY_STREAM(p)->ReadInt64();
  m_30 = PROXY_STREAM(p)->ReadUnicodeString();
  m_38 = PROXY_STREAM(p)->ReadUnicodeStringA();
  m_40.FUN_14020cfc0(*PROXY_STREAM(p));
  if (m_88.get())
    m_88->vfunc_4(*(p ? PROXY_STREAM(p) : nullptr));
  m_98 = PROXY_STREAM(p)->ReadString();
  m_a0 = PROXY_STREAM(p)->ReadInt64();
}
MS2_REPLACE_METHOD(0x1408EB1D0, Unk_UserProxySummaryPacket, Decode, 1132, 0x1B2A32D9);

// @0x1408eb650
void Unk_UserProxySummaryPacket::GetClubs(ATL::CAtlArray<MS2Ptr<Club::NameInfo>> &out) {
  m_40.FUN_14020cce0(out);
}
MS2_REPLACE_METHOD(0x1408EB650, Unk_UserProxySummaryPacket, GetClubs, 41, 0x5BDFB077);

// @0x1408eb680
Unk_UserProxy::Unk_UserProxy() {
  m_0 = 0;
  m_330 = FUN_1408e7250();
  m_340 = new CUserPlayInfoProxy();
  FUN_1408ebe30();
}

// @0x1408eb970
Unk_UserProxy::Unk_UserProxy(const Unk_UserProxy &p) {
  m_330 = FUN_1408e7250();
  m_340 = new CUserPlayInfoProxy();
  FUN_1408efa70(p);
}

// @0x1408ebc60
Unk_UserProxy::~Unk_UserProxy() {
  m_330 = 0;
  m_340 = 0;
}

// @0x1408ebe30
void Unk_UserProxy::FUN_1408ebe30() {
  m_8 = 0;
  FUN_1408f07e0(L"");
  m_10 = 0;
  m_14 = 0;
  m_24 = 0;
  m_18 = 0;
  m_20 = 0;
  FUN_1408ec260();
  FUN_1408f18a0();
  m_90 = 0;
  m_94.Reset();
  m_98 = 0;
  m_9c = 0;
  m_a0 = 0;
  m_a8 = 0;
  m_b0 = 0;
  m_b8 = 0;
  m_c0 = 0;
  m_c4 = Vector3(0, 0, 0);
  m_d0 = 0;
  m_d4.Clear();
  FUN_1408f0850("");
  FUN_1408f08c0(L"");
  FUN_1408f09c0(L"");
  m_220.RemoveAll();
  m_240.RemoveAll();
  m_260.RemoveAll();
  m_280 = 0;
  m_288 = 0;
  FUN_1408f0e00();
  if (m_330.get())
    m_330->vfunc_1();
  memset(m_140, 0, sizeof(m_140));
  FUN_1408f1200();
  m_180 = 0;
  m_184 = false;
  m_188 = 0;
  m_190 = 0;
  m_194 = 0;
  m_198 = 0;
  m_1b0 = 0;
  FUN_1408f0a30("");
  m_1b8.RemoveAll();
  m_1e8.RemoveAll();
  m_218 = "";
}
MS2_REPLACE_METHOD(0x1408EBE30, Unk_UserProxy, FUN_1408ebe30, 1059, 0xE44D8782);

// @0x1408ec260
void Unk_UserProxy::FUN_1408ec260() {
  m_28 = 0;
  m_2c = 0;
  m_30 = 0;
  m_34 = 1;
  m_38 = 0;
  m_3c = 0;
  m_40 = 0;
  m_44 = 0;
  m_48 = 0;
  m_4c = 0;
  m_50 = 0;
  for (int i = 0; i < 2; ++i)
    m_58[i] = 0;
  m_60 = 0;
  m_70 = 0;
  m_78 = 0;
  m_80 = 0;
  m_88 = 0;
  FUN_1408f0950(L"");
  m_1a8 = 0;
  m_1ac = 0;
}
MS2_REPLACE_METHOD(0x1408EC260, Unk_UserProxy, FUN_1408ec260, 346, 0x6DD26C75);

// @0x1408ec3c0
void Unk_UserProxy::FUN_1408ec3c0(COutputStream &s) {
  Unk_UserProxyFlagsPacket p;
  p.CopyFrom(this);
  p.Encode(s);
}
MS2_REPLACE_METHOD(0x1408EC3C0, Unk_UserProxy, FUN_1408ec3c0, 59, 0x6881C03A);

// @0x1408ec410
void Unk_UserProxy::FUN_1408ec410(CInPacket &s) {
  Unk_UserProxyFlagsPacket p;
  p.Decode(s);
  FUN_1408f0460(p);
}
MS2_REPLACE_METHOD(0x1408EC410, Unk_UserProxy, FUN_1408ec410, 59, 0xF8231901);

// @0x1408ec460
void Unk_UserProxy::FUN_1408ec460(COutputStream &s) {
  Unk_UserProxyStatsPacket p;
  p.CopyFrom(this);
  p.Encode(s);
}
MS2_REPLACE_METHOD(0x1408EC460, Unk_UserProxy, FUN_1408ec460, 59, 0x0EDFA3EA);

// @0x1408ec4b0
void Unk_UserProxy::FUN_1408ec4b0(CInPacket &s) {
  Unk_UserProxyStatsPacket p;
  p.Decode(s);
  FUN_1408f04c0(p);
}
MS2_REPLACE_METHOD(0x1408EC4B0, Unk_UserProxy, FUN_1408ec4b0, 59, 0xF01F526A);

// @0x1408ec500
void Unk_UserProxy::FUN_1408ec500(COutputStream &s) {
  Unk_UserProxySummaryPacket p;
  p.CopyFrom(this);
  p.Encode(s);
}

// @0x1408ec570
void Unk_UserProxy::FUN_1408ec570(CInPacket &s) {
  Unk_UserProxySummaryPacket p;
  p.Decode(&s);
  FUN_1408f0520(p);
}

// @0x1408ec5e0
void Unk_UserProxy::FUN_1408ec5e0(COutputStream &s) {
  s.WriteInt64(m_0);
  s.WriteInt64(m_8);
  s.WriteUnicodeString(FUN_1408f19e0());
  s.WriteInt32(m_10);
  s.WriteUInt8(m_14);
  s.WriteUInt8(m_24);
  s.WriteInt64(m_18);
  s.WriteInt32(m_20);
  s.WriteUnicodeStringA(m_218);
  s.WriteInt32(m_28);
  s.WriteInt32(m_2c);
  s.WriteInt32(m_30);
  s.WriteInt16(m_34);
  s.WriteInt16(m_38);
  s.WriteInt32(m_3c);
  s.WriteInt32(m_40);
  s.WriteInt32(m_44);
  s.WriteInt32(m_48);
  s.WriteInt16(m_4c);
  s.WriteInt64(m_50);
  for (int i = 0; i < 2; ++i)
    s.WriteInt32(m_58[i]);
  s.WriteInt64(m_60);
  s.WriteInt64(m_70);
  s.WriteUInt8(m_78);
  s.WriteInt64(m_80);
  s.WriteUnicodeString(FUN_1408f1b60());
  FUN_1408f1900(s);
  s.WriteUInt8(m_90);
  m_94.Encode(s);
  s.WriteInt32(m_98);
  s.WriteInt32(m_9c);
  s.WriteInt32(m_a0);
  s.WriteInt64(m_a8);
  s.WriteInt64(m_b0);
  s.WriteInt64(m_b8);
  s.WriteInt32(m_c0);
  s.WriteVector3(m_c4);
  s.WriteInt32(m_d0);
  m_d4.FUN_140267e40(s);
  s.WriteUnicodeStringA(FUN_1408f1a60());
  s.WriteUnicodeString(FUN_1408f1ae0());
  s.WriteUnicodeString(FUN_1408f1be0());
  FUN_1408f0e90(s);
  if (m_330.get())
    m_330->vfunc_3(s);
  ATL::CAtlArray<unsigned __int64> values;
  FUN_1408f1270(values);
  s.WriteInt32(static_cast<int>(values.GetCount()));
  for (unsigned i = 0; i < values.GetCount(); ++i)
    s.WriteInt64(values[i]);
  s.WriteUInt8(m_180);
  s.WriteBool(m_184);
  s.WriteInt64(m_188);
  s.WriteInt32(m_190);
  s.WriteInt32(m_194);
  s.WriteInt64(m_198);
  s.WriteString(FUN_1408f1c60());
  s.WriteInt32(m_1a8);
  s.WriteInt64(m_1b0);
  s.WriteInt32(static_cast<int>(m_1b8.GetCount()));
  for (POSITION pos = m_1b8.GetHeadPosition(); pos != 0; m_1b8.GetNext(pos))
    s.WriteInt64(m_1b8.GetAt(pos));
  s.WriteInt32(static_cast<int>(m_1e8.GetCount()));
  for (POSITION pos = m_1e8.GetHeadPosition(); pos != 0; m_1e8.GetNext(pos))
    s.WriteInt64(m_1e8.GetAt(pos));
  s.WriteInt16(m_1ac);
  s.WriteInt64(m_88);
}
MS2_REPLACE_METHOD(0x1408EC5E0, Unk_UserProxy, FUN_1408ec5e0, 2952, 0x9BCC4DC2);

// @0x1408ed170
void Unk_UserProxy::FUN_1408ed170(CInPacket *p) {
  m_0 = PROXY_STREAM(p)->ReadInt64();
  m_8 = PROXY_STREAM(p)->ReadInt64();
  FUN_1408f07e0(PROXY_STREAM(p)->ReadUnicodeString());
  m_10 = PROXY_STREAM(p)->ReadInt32();
  m_14 = PROXY_STREAM(p)->ReadUInt8();
  m_24 = PROXY_STREAM(p)->ReadUInt8();
  m_18 = PROXY_STREAM(p)->ReadInt64();
  m_20 = PROXY_STREAM(p)->ReadInt32();
  m_218 = PROXY_STREAM(p)->ReadUnicodeStringA();
  m_28 = PROXY_STREAM(p)->ReadInt32();
  m_2c = PROXY_STREAM(p)->ReadInt32();
  m_30 = PROXY_STREAM(p)->ReadInt32();
  m_34 = PROXY_STREAM(p)->ReadInt16();
  m_38 = static_cast<unsigned short>(PROXY_STREAM(p)->ReadInt16());
  m_3c = PROXY_STREAM(p)->ReadInt32();
  m_40 = PROXY_STREAM(p)->ReadInt32();
  m_44 = PROXY_STREAM(p)->ReadInt32();
  m_48 = PROXY_STREAM(p)->ReadInt32();
  m_4c = PROXY_STREAM(p)->ReadInt16();
  m_50 = PROXY_STREAM(p)->ReadInt64();
  for (int i = 0; i < 2; ++i)
    m_58[i] = PROXY_STREAM(p)->ReadInt32();
  m_60 = PROXY_STREAM(p)->ReadInt64();
  m_70 = PROXY_STREAM(p)->ReadInt64();
  m_78 = PROXY_STREAM(p)->ReadUInt8();
  m_80 = PROXY_STREAM(p)->ReadInt64();
  FUN_1408f0950(PROXY_STREAM(p)->ReadUnicodeString());
  FUN_1408f1970(*p);
  m_90 = PROXY_STREAM(p)->ReadUInt8();
  m_94.Decode(*PROXY_STREAM(p));
  m_98 = PROXY_STREAM(p)->ReadInt32();
  m_9c = PROXY_STREAM(p)->ReadInt32();
  m_a0 = PROXY_STREAM(p)->ReadInt32();
  m_a8 = PROXY_STREAM(p)->ReadInt64();
  m_b0 = PROXY_STREAM(p)->ReadInt64();
  m_b8 = PROXY_STREAM(p)->ReadInt64();
  m_c0 = PROXY_STREAM(p)->ReadInt32();
  m_c4 = PROXY_STREAM(p)->ReadVector3();
  m_d0 = PROXY_STREAM(p)->ReadInt32();
  m_d4.FUN_140267e70(*PROXY_STREAM(p));
  FUN_1408f0850(PROXY_STREAM(p)->ReadUnicodeStringA());
  FUN_1408f08c0(PROXY_STREAM(p)->ReadUnicodeString());
  FUN_1408f09c0(PROXY_STREAM(p)->ReadUnicodeString());
  FUN_1408f0f20(*PROXY_STREAM(p));
  if (m_330.get())
    m_330->vfunc_4(*(p ? PROXY_STREAM(p) : nullptr));
  unsigned setCount = PROXY_STREAM(p)->ReadInt32();
  for (unsigned i = 0; i < setCount; ++i)
    FUN_1408f1110(PROXY_STREAM(p)->ReadInt64());
  m_180 = PROXY_STREAM(p)->ReadUInt8();
  m_184 = PROXY_STREAM(p)->ReadBool();
  m_188 = PROXY_STREAM(p)->ReadInt64();
  m_190 = PROXY_STREAM(p)->ReadInt32();
  m_194 = PROXY_STREAM(p)->ReadInt32();
  m_198 = PROXY_STREAM(p)->ReadInt64();
  FUN_1408f0a30(PROXY_STREAM(p)->ReadString());
  m_1a8 = PROXY_STREAM(p)->ReadInt32();
  m_1b0 = PROXY_STREAM(p)->ReadInt64();
  m_1b8.RemoveAll();
  unsigned count_1b8 = PROXY_STREAM(p)->ReadInt32();
  for (unsigned i = 0; i < count_1b8; ++i)
    m_1b8.AddTail(PROXY_STREAM(p)->ReadInt64());
  m_1e8.RemoveAll();
  unsigned count_1e8 = PROXY_STREAM(p)->ReadInt32();
  for (unsigned i = 0; i < count_1e8; ++i)
    m_1e8.AddTail(PROXY_STREAM(p)->ReadInt64());
  m_1ac = PROXY_STREAM(p)->ReadInt16();
  m_88 = PROXY_STREAM(p)->ReadInt64();
}
MS2_REPLACE_METHOD(0x1408ED170, Unk_UserProxy, FUN_1408ed170, 4122, 0x30A08577);

// @0x1408ee190
void Unk_UserProxy::FUN_1408ee190(COutputStream &s) {
  s.WriteInt64(m_0);
  s.WriteInt64(m_8);
  s.WriteUnicodeString(FUN_1408f19e0());
  s.WriteUInt8(m_14);
  s.WriteUInt8(m_78);
  s.WriteInt64(m_18);
  s.WriteInt32(m_20);
  s.WriteInt32(m_28);
  s.WriteInt32(m_2c);
  s.WriteInt32(m_30);
  s.WriteInt16(m_34);
  s.WriteInt16(m_38);
  s.WriteInt32(m_3c);
  s.WriteInt32(m_40);
  s.WriteInt32(m_44);
  s.WriteInt32(m_48);
  s.WriteInt16(m_4c);
  s.WriteInt64(m_50);
  s.WriteInt64(m_b0);
  s.WriteInt64(m_b8);
  s.WriteInt32(m_c0);
  s.WriteVector3(m_c4);
  s.WriteInt32(m_d0);
  for (int i = 0; i < 2; ++i)
    s.WriteInt32(m_58[i]);
  s.WriteInt64(m_70);
  m_d4.FUN_140267e40(s);
  s.WriteInt64(m_80);
  s.WriteUnicodeString(FUN_1408f1b60());
  s.WriteUnicodeString(FUN_1408f1ae0());
  s.WriteUnicodeStringA(FUN_1408f1a60());
  FUN_1408f1900(s);
  s.WriteUInt8(m_24);
  for (size_t i = 0; i < 12; ++i)
    s.WriteInt32(m_140[i]);
  if (m_330.get())
    m_330->vfunc_5(s);
  ATL::CAtlArray<unsigned __int64> values;
  FUN_1408f1270(values);
  s.WriteInt32(static_cast<int>(values.GetCount()));
  for (unsigned i = 0; i < values.GetCount(); ++i)
    s.WriteInt64(values[i]);
  s.WriteUInt8(m_180);
  s.WriteBool(m_184);
  s.WriteInt64(m_188);
  s.WriteInt32(m_190);
  s.WriteInt32(m_194);
  s.WriteInt64(m_198);
  s.WriteInt32(m_1a8);
  s.WriteInt64(m_1b0);
  s.WriteInt32(static_cast<int>(m_1b8.GetCount()));
  for (POSITION pos = m_1b8.GetHeadPosition(); pos != 0; m_1b8.GetNext(pos))
    s.WriteInt64(m_1b8.GetAt(pos));
  s.WriteInt32(static_cast<int>(m_1e8.GetCount()));
  for (POSITION pos = m_1e8.GetHeadPosition(); pos != 0; m_1e8.GetNext(pos))
    s.WriteInt64(m_1e8.GetAt(pos));
  s.WriteInt16(m_1ac);
  s.WriteInt64(m_88);
}
MS2_REPLACE_METHOD(0x1408EE190, Unk_UserProxy, FUN_1408ee190, 2499, 0x0995AAE0);

// @0x1408eeb60
void Unk_UserProxy::FUN_1408eeb60(CInPacket *p) {
  m_0 = PROXY_STREAM(p)->ReadInt64();
  m_8 = PROXY_STREAM(p)->ReadInt64();
  FUN_1408f07e0(PROXY_STREAM(p)->ReadUnicodeString());
  m_14 = PROXY_STREAM(p)->ReadUInt8();
  m_78 = PROXY_STREAM(p)->ReadUInt8();
  m_18 = PROXY_STREAM(p)->ReadInt64();
  m_20 = PROXY_STREAM(p)->ReadInt32();
  m_28 = PROXY_STREAM(p)->ReadInt32();
  m_2c = PROXY_STREAM(p)->ReadInt32();
  m_30 = PROXY_STREAM(p)->ReadInt32();
  m_34 = PROXY_STREAM(p)->ReadInt16();
  m_38 = static_cast<unsigned short>(PROXY_STREAM(p)->ReadInt16());
  m_3c = PROXY_STREAM(p)->ReadInt32();
  m_40 = PROXY_STREAM(p)->ReadInt32();
  m_44 = PROXY_STREAM(p)->ReadInt32();
  m_48 = PROXY_STREAM(p)->ReadInt32();
  m_4c = PROXY_STREAM(p)->ReadInt16();
  m_50 = PROXY_STREAM(p)->ReadInt64();
  m_b0 = PROXY_STREAM(p)->ReadInt64();
  m_b8 = PROXY_STREAM(p)->ReadInt64();
  m_c0 = PROXY_STREAM(p)->ReadInt32();
  m_c4 = PROXY_STREAM(p)->ReadVector3();
  m_d0 = PROXY_STREAM(p)->ReadInt32();
  for (int i = 0; i < 2; ++i)
    m_58[i] = PROXY_STREAM(p)->ReadInt32();
  m_70 = PROXY_STREAM(p)->ReadInt64();
  m_d4.FUN_140267e70(*PROXY_STREAM(p));
  m_80 = PROXY_STREAM(p)->ReadInt64();
  FUN_1408f0950(PROXY_STREAM(p)->ReadUnicodeString());
  FUN_1408f08c0(PROXY_STREAM(p)->ReadUnicodeString());
  FUN_1408f0850(PROXY_STREAM(p)->ReadUnicodeStringA());
  FUN_1408f1970(*p);
  m_24 = PROXY_STREAM(p)->ReadUInt8();
  for (size_t i = 0; i < 12; ++i)
    m_140[i] = PROXY_STREAM(p)->ReadInt32();
  if (m_330.get())
    m_330->vfunc_6(*p);
  unsigned setCount = PROXY_STREAM(p)->ReadInt32();
  for (unsigned i = 0; i < setCount; ++i)
    FUN_1408f1110(PROXY_STREAM(p)->ReadInt64());
  m_180 = PROXY_STREAM(p)->ReadUInt8();
  m_184 = PROXY_STREAM(p)->ReadBool();
  m_188 = PROXY_STREAM(p)->ReadInt64();
  m_190 = PROXY_STREAM(p)->ReadInt32();
  m_194 = PROXY_STREAM(p)->ReadInt32();
  m_198 = PROXY_STREAM(p)->ReadInt64();
  m_1a8 = PROXY_STREAM(p)->ReadInt32();
  m_1b0 = PROXY_STREAM(p)->ReadInt64();
  m_1b8.RemoveAll();
  unsigned count_1b8 = PROXY_STREAM(p)->ReadInt32();
  for (unsigned i = 0; i < count_1b8; ++i)
    m_1b8.AddTail(PROXY_STREAM(p)->ReadInt64());
  m_1e8.RemoveAll();
  unsigned count_1e8 = PROXY_STREAM(p)->ReadInt32();
  for (unsigned i = 0; i < count_1e8; ++i)
    m_1e8.AddTail(PROXY_STREAM(p)->ReadInt64());
  m_1ac = PROXY_STREAM(p)->ReadInt16();
  m_88 = PROXY_STREAM(p)->ReadInt64();
}
MS2_REPLACE_METHOD(0x1408EEB60, Unk_UserProxy, FUN_1408eeb60, 3352, 0x1D7DF205);

// @0x1408ef880
void Unk_UserProxy::FUN_1408ef880(COutputStream &s) {
  m_340->m_18.FUN_1408e97e0(s);
  s.WriteInt64(m_340->m_198);
}
MS2_REPLACE_METHOD(0x1408EF880, Unk_UserProxy, FUN_1408ef880, 107, 0x7288E7FB);

// @0x1408ef900
void Unk_UserProxy::FUN_1408ef900(CInPacket &p) {
  m_340->m_18.FUN_1408e9b40(*PROXY_STREAM(&p));
  m_340->m_198 = PROXY_STREAM(&p)->ReadInt64();
}
MS2_REPLACE_METHOD(0x1408EF900, Unk_UserProxy, FUN_1408ef900, 138, 0x6A87F2EE);

// @0x1408ef990
void Unk_UserProxy::FUN_1408ef990(COutputStream &s) {
  Unk_UserProxyClubPacket p;
  p.CopyFrom(this);
  p.Encode(s);
}

// @0x1408efa00
void Unk_UserProxy::FUN_1408efa00(CInPacket &s) {
  Unk_UserProxyClubPacket p;
  p.Decode(s);
  FUN_1408f06e0(p);
}

// @0x1408efa70
void Unk_UserProxy::FUN_1408efa70(const Unk_UserProxy &p) {
  m_0 = p.m_0;
  m_8 = p.m_8;
  m_10 = p.m_10;
  m_14 = p.m_14;
  m_24 = p.m_24;
  m_18 = p.m_18;
  m_20 = p.m_20;
  m_218 = p.m_218;
  m_28 = p.m_28;
  m_2c = p.m_2c;
  m_30 = p.m_30;
  m_34 = p.m_34;
  m_38 = p.m_38;
  m_3c = p.m_3c;
  m_40 = p.m_40;
  m_44 = p.m_44;
  m_48 = p.m_48;
  m_4c = p.m_4c;
  m_50 = p.m_50;
  for (int i = 0; i < 2; ++i)
    m_58[i] = p.m_58[i];
  m_60 = p.m_60;
  m_70 = p.m_70;
  m_78 = p.m_78;
  m_80 = p.m_80;
  ATL::CAtlArray<MS2Ptr<Club::NameInfo>> clubs;
  const_cast<Unk_UserProxy &>(p).FUN_1408f17c0(clubs);
  FUN_1408f1830(clubs);
  FUN_1408f07e0(const_cast<Unk_UserProxy &>(p).FUN_1408f19e0());
  FUN_1408f0950(const_cast<Unk_UserProxy &>(p).FUN_1408f1b60());
  m_90 = p.m_90;
  m_94 = p.m_94;
  m_98 = p.m_98;
  m_9c = p.m_9c;
  m_a0 = p.m_a0;
  m_a8 = p.m_a8;
  m_b0 = p.m_b0;
  m_b8 = p.m_b8;
  m_c0 = p.m_c0;
  m_c4 = p.m_c4;
  m_d0 = p.m_d0;
  for (size_t i = 0; i < 12; ++i)
    m_140[i] = p.m_140[i];
  m_d4 = p.m_d4;
  FUN_1408f0850(const_cast<Unk_UserProxy &>(p).FUN_1408f1a60());
  FUN_1408f08c0(const_cast<Unk_UserProxy &>(p).FUN_1408f1ae0());
  FUN_1408f09c0(p.FUN_1408f1be0());
  for (int i = 0; i < 3; ++i) {
    Unk_UserProxyLabel label;
    const_cast<Unk_UserProxy &>(p).FUN_1408f0ca0(i, label);
    FUN_1408f0c10(i, label);
  }
  if (m_330.get())
    m_330->vfunc_2(p.m_330.get());
  ATL::CAtlArray<unsigned __int64> values;
  const_cast<Unk_UserProxy &>(p).FUN_1408f1270(values);
  for (unsigned i = 0; i < values.GetCount(); ++i)
    FUN_1408f1110(values[i]);
  m_180 = p.m_180;
  m_184 = p.m_184;
  m_188 = p.m_188;
  m_190 = p.m_190;
  m_194 = p.m_194;
  m_198 = p.m_198;
  m_1a8 = p.m_1a8;
  m_1b0 = p.m_1b0;
  m_1b8.RemoveAll();
  for (POSITION pos = p.m_1b8.GetHeadPosition(); pos != 0; p.m_1b8.GetNext(pos))
    m_1b8.AddTail(p.m_1b8.GetAt(pos));
  m_1e8.RemoveAll();
  for (POSITION pos = p.m_1e8.GetHeadPosition(); pos != 0; p.m_1e8.GetNext(pos))
    m_1e8.AddTail(p.m_1e8.GetAt(pos));
  m_1ac = p.m_1ac;
  FUN_1408f0a30(p.FUN_1408f1c60());
  m_88 = p.m_88;
}
MS2_REPLACE_METHOD(0x1408EFA70, Unk_UserProxy, FUN_1408efa70, 2532, 0xDB69999B);

// @0x1408f0460
void Unk_UserProxy::FUN_1408f0460(const Unk_UserProxyFlagsPacket &p) {
  m_0 = p.m_0;
  m_44 = p.m_8;
  m_48 = p.m_c;
  m_4c = p.m_10;
}
MS2_REPLACE_METHOD(0x1408F0460, Unk_UserProxy, FUN_1408f0460, 77, 0xACD2362D);

// @0x1408f04c0
void Unk_UserProxy::FUN_1408f04c0(const Unk_UserProxyStatsPacket &p) {
  m_0 = p.m_0;
  m_28 = p.m_8;
  m_2c = p.m_c;
  m_30 = p.m_10;
}
MS2_REPLACE_METHOD(0x1408F04C0, Unk_UserProxy, FUN_1408f04c0, 75, 0x7F03D85A);

// @0x1408f0520
void Unk_UserProxy::FUN_1408f0520(Unk_UserProxySummaryPacket &p) {
  m_8 = p.m_0;
  m_14 = p.m_10;
  m_28 = p.m_14;
  m_34 = p.m_18;
  m_78 = p.m_24;
  m_80 = p.m_28;
  m_88 = p.m_a0;
  ATL::CAtlArray<MS2Ptr<Club::NameInfo>> clubs;
  p.GetClubs(clubs);
  FUN_1408f1830(clubs);
  FUN_1408f07e0(p.m_8);
  FUN_1408f0950(p.m_30);
  FUN_1408f0850(p.m_38);
  m_3c = p.m_1c;
  m_40 = p.m_20;
  if (m_330.get())
    m_330->vfunc_2(p.m_88.get());
  FUN_1408f0a30(p.m_98);
}
MS2_REPLACE_METHOD(0x1408F0520, Unk_UserProxy, FUN_1408f0520, 428, 0x77AC4D8E);

// @0x1408f06e0
void Unk_UserProxy::FUN_1408f06e0(Unk_UserProxyClubPacket &p) {
  m_0 = p.m_0;
  m_8 = p.m_8;
  CStringW name(p.m_10);
  FUN_1408f07e0(name);
  m_80 = p.m_18;
  ATL::CAtlArray<MS2Ptr<Club::NameInfo>> clubs;
  p.GetClubs(clubs);
  FUN_1408f1830(clubs);
}
MS2_REPLACE_METHOD(0x1408F06E0, Unk_UserProxy, FUN_1408f06e0, 186, 0x549831D0);

// @0x1408f07a0
void Unk_UserProxy::FUN_1408f07a0(const Unk_UserProxyColor &p) { m_d4.FUN_140267d00(p); }
MS2_REPLACE_METHOD(0x1408F07A0, Unk_UserProxy, FUN_1408f07a0, 43, 0xE310C0A3);

// @0x1408f07e0
void Unk_UserProxy::FUN_1408f07e0(const CStringW &p) {
  Unk_UserProxyWriteLock lock(m_290, 1);
  m_2c0 = p;
}

// @0x1408f0850
void Unk_UserProxy::FUN_1408f0850(const CString &p) {
  Unk_UserProxyWriteLock lock(m_290, 1);
  m_2d0 = p;
}

// @0x1408f08c0
void Unk_UserProxy::FUN_1408f08c0(const CStringW &p) {
  Unk_UserProxyWriteLock lock(m_290, 1);
  CStringW tmp(p);
  FUN_14083d2b0(tmp);
  m_2d8 = tmp;
}

// @0x1408f0950
void Unk_UserProxy::FUN_1408f0950(const CStringW &p) {
  Unk_UserProxyWriteLock lock(m_290, 1);
  m_2c8 = p;
}

// @0x1408f09c0
void Unk_UserProxy::FUN_1408f09c0(const CStringW &p) {
  Unk_UserProxyWriteLock lock(m_290, 1);
  m_328 = p;
}

// @0x1408f0a30
void Unk_UserProxy::FUN_1408f0a30(const CString &p) {
  Unk_UserProxyWriteLock lock(m_290, 1);
  m_1a0 = p;
}

// @0x1408f0aa0
void Unk_UserProxy::FUN_1408f0aa0(int p) {
  unsigned short value = (std::min)(p, 200);
  m_4c = (m_4c & 0xff) | (value << 8);
}

// @0x1408f0b00
void Unk_UserProxy::FUN_1408f0b00(int p) {
  unsigned short value = 0;
  if (p == 1)
    value |= 1;
  else if (p == 2)
    value |= 2;
  m_4c = (m_4c & 0xff00) | value;
}

// @0x1408f0b70
void Unk_UserProxy::FUN_1408f0b70(Unk_UserProxyLabel &label, int a, int b, int c, const CStringW &text,
                                  __int64 until) {
  Unk_UserProxyWriteLock lock(m_290, 1);
  label.m_0 = text;
  label.m_8 = a;
  label.m_c = b;
  label.m_10 = c;
  label.m_18 = until;
}

// @0x1408f0c10
void Unk_UserProxy::FUN_1408f0c10(int i, const Unk_UserProxyLabel &p) {
  if (i < 0 || i >= 3)
    return;
  {
    Unk_UserProxyWriteLock lock(m_290, 1);
    m_e0[i].CopyFrom(p);
  }
}

// @0x1408f0ca0
void Unk_UserProxy::FUN_1408f0ca0(int i, Unk_UserProxyLabel &p) {
  if (i < 0 || i >= 3)
    return;
  {
    Unk_UserProxyWriteLock lock(m_290, 1);
    p = m_e0[i];
  }
}

// @0x1408f0d30
int Unk_UserProxy::FUN_1408f0d30(int i) {
  if (i < 0 || i >= 3)
    return 0;
  Unk_UserProxyWriteLock lock(m_290, 1);
  if (m_e0[i].m_18) {
    m_e0[i].Clear();
    return 1;
  } else {
    return 0;
  }
}

// @0x1408f0e00
void Unk_UserProxy::FUN_1408f0e00() {
  Unk_UserProxyWriteLock lock(m_290, 1);
  for (int i = 0; i < 3; ++i)
    m_e0[i].Clear();
}

// @0x1408f0e90
void Unk_UserProxy::FUN_1408f0e90(COutputStream &s) {
  Unk_UserProxyWriteLock lock(m_290, 1);
  for (int i = 0; i < 3; ++i)
    m_e0[i].Encode(s);
}

// @0x1408f0f20
void Unk_UserProxy::FUN_1408f0f20(CInputStream &s) {
  Unk_UserProxyWriteLock lock(m_290, 1);
  for (int i = 0; i < 3; ++i)
    m_e0[i].Decode(s);
}

// @0x1408f0fb0
void Unk_UserProxy::FUN_1408f0fb0() {
  Unk_UserProxyWriteLock lock(m_290, 1);
  for (int i = 0; i < 3; ++i)
    m_e0[i].Expire();
}

// @0x1408f1040
void Unk_UserProxy::FUN_1408f1040(__int64 p) {
  Unk_UserProxyWriteLock lock(m_290, 1);
  m_50 = p;
}

// @0x1408f1090
void Unk_UserProxy::FUN_1408f1090(CString p) {
  Unk_UserProxyWriteLock lock(m_290, 1);
  m_218 = p;
}

// @0x1408f1110
void Unk_UserProxy::FUN_1408f1110(unsigned __int64 p) {
  if (Unk_LockGuard lock = m_290) {
      __assume(0);
  } else {
    m_170.insert(p);
  }
}

// @0x1408f1190
void Unk_UserProxy::FUN_1408f1190(unsigned __int64 p) {
  if (Unk_LockGuard lock = m_290) {
      __assume(0);
  } else {
    m_170.erase(p);
  }
}

// @0x1408f1200
void Unk_UserProxy::FUN_1408f1200() {
  if (Unk_LockGuard lock = m_290) {
      __assume(0);
  } else {
    m_170.clear();
  }
}

// @0x1408f1270
void Unk_UserProxy::FUN_1408f1270(ATL::CAtlArray<unsigned __int64> &out) {
  if (Unk_LockGuard lock = m_290) {
      __assume(0);
  } else {
    // const begin/end 0x1408f48f0 / 0x1408f4960 (the non-const end is 0x140341f40, used by find).
    for (auto it = static_cast<const std::set<unsigned __int64> &>(m_170).begin();
         it != static_cast<const std::set<unsigned __int64> &>(m_170).end(); ++it)
      out.Add(*it);
  }
}

// @0x1408f1330
__int64 Unk_UserProxy::FUN_1408f1330() {
  if (Unk_LockGuard lock = m_290) {
      __assume(0);
  } else {
    if (m_170.empty())
      return 0;
    return *static_cast<const std::set<unsigned __int64> &>(m_170).begin();
  }
}

// @0x1408f13f0
MS2Ptr<Club::NameInfo> Unk_UserProxy::FUN_1408f13f0(__int64 id) {
  Unk_UserProxyWriteLock lock(m_290, 1);
  return m_2e0.FUN_14020ca10(id);
}

// @0x1408f1480
size_t Unk_UserProxy::FUN_1408f1480() {
  Unk_UserProxyWriteLock lock(m_290, 1);
  return m_2e0.FUN_14020ca90();
}

// @0x1408f14f0
int Unk_UserProxy::FUN_1408f14f0() {
  Unk_UserProxyWriteLock lock(m_290, 1);
  return m_2e0.FUN_14020cac0();
}

// @0x1408f1560
int Unk_UserProxy::FUN_1408f1560(__int64 id, CStringW name) {
  Unk_UserProxyWriteLock lock(m_290, 1);
  return m_2e0.FUN_14020cb00(id, name);
}

// @0x1408f1600
int Unk_UserProxy::FUN_1408f1600(MS2Ptr<Club::NameInfo> p) {
  Unk_UserProxyWriteLock lock(m_290, 1);
  return m_2e0.FUN_14020cc00(p);
}

// @0x1408f16a0
void Unk_UserProxy::FUN_1408f16a0(__int64 id) {
  Unk_UserProxyWriteLock lock(m_290, 1);
  m_2e0.FUN_14020ccb0(id);
}

// @0x1408f1710
void Unk_UserProxy::FUN_1408f1710(__int64 id, CStringW name) {
  Unk_UserProxyWriteLock lock(m_290, 1);
  MS2Ptr<Club::NameInfo> p = FUN_1408f13f0(id);
  if (p.get())
    p->m_20 = name;
}

// @0x1408f17c0
void Unk_UserProxy::FUN_1408f17c0(ATL::CAtlArray<MS2Ptr<Club::NameInfo>> &p) {
  Unk_UserProxyWriteLock lock(m_290, 1);
  m_2e0.FUN_14020cce0(p);
}

// @0x1408f1830
void Unk_UserProxy::FUN_1408f1830(const ATL::CAtlArray<MS2Ptr<Club::NameInfo>> &p) {
  Unk_UserProxyWriteLock lock(m_290, 1);
  m_2e0.FUN_14020cda0(p);
}

// @0x1408f18a0
void Unk_UserProxy::FUN_1408f18a0() {
  Unk_UserProxyWriteLock lock(m_290, 1);
  m_2e0.FUN_14020c9e0();
}

// @0x1408f1900
void Unk_UserProxy::FUN_1408f1900(COutputStream &p) {
  Unk_UserProxyWriteLock lock(m_290, 1);
  m_2e0.FUN_14020ce50(p);
}

// @0x1408f1970
void Unk_UserProxy::FUN_1408f1970(CInPacket &p) {
  Unk_UserProxyWriteLock lock(m_290, 1);
  m_2e0.FUN_14020cfc0(*PROXY_STREAM(&p));
}

// @0x1408f19e0
CStringW Unk_UserProxy::FUN_1408f19e0() {
  Unk_UserProxyWriteLock lock(m_290, 1);
  return m_2c0;
}

// @0x1408f1a60
CString Unk_UserProxy::FUN_1408f1a60() {
  Unk_UserProxyWriteLock lock(m_290, 1);
  return m_2d0;
}

// @0x1408f1ae0
CStringW Unk_UserProxy::FUN_1408f1ae0() {
  Unk_UserProxyWriteLock lock(m_290, 1);
  return m_2d8;
}

// @0x1408f1b60
CStringW Unk_UserProxy::FUN_1408f1b60() {
  Unk_UserProxyWriteLock lock(m_290, 1);
  return m_2c8;
}

// @0x1408f1be0
CStringW Unk_UserProxy::FUN_1408f1be0() const {
  Unk_UserProxyConstLock lock(m_290, 1);
  return m_328;
}

// @0x1408f1c60
CString Unk_UserProxy::FUN_1408f1c60() const {
  Unk_UserProxyConstLock lock(m_290, 1);
  return m_1a0;
}

// @0x1408f1ce0
int Unk_UserProxy::FUN_1408f1ce0() {
  unsigned short value = m_4c & 3;
  if (value == 1)
    return 1;
  else if (value == 2)
    return 2;
  return 0;
}

// @0x1408f1d30
unsigned short Unk_UserProxy::FUN_1408f1d30() {
  unsigned short value = (m_4c & 0xff00) >> 8;
  return value;
}

// @0x1408f1d60
int Unk_UserProxy::FUN_1408f1d60() { return m_10; }

// @0x1408f1d80
__int64 Unk_UserProxy::FUN_1408f1d80() {
  if (m_18 == 0)
    return m_0;
  return m_18;
}

// @0x1408f1db0
int Unk_UserProxy::FUN_1408f1db0() {
  if (m_20 == 0)
    return m_10;
  return m_20;
}

// @0x1408f1de0
CString Unk_UserProxy::FUN_1408f1de0() const {
  Unk_UserProxyConstLock lock(m_290, 1);
  return m_218;
}

// @0x1408f1e60
void Unk_UserProxy::FUN_1408f1e60() {
  m_8 = FUN_140869420();
  m_34 = 1;
  m_14 = rand() % 2 ? 1 : 0;
  MS2Ptr<CItem> item(new CItem());
  if (item->FUN_140523c40(0x9a1d21, 1, 0)) {
    Unk_UserProxyItemData *data = item->FUN_140527870();
    if (data) {
      for (int i = 0; i < 2; ++i)
        m_58[i] = data->FUN_140599fd0(i);
    }
  }
  m_220.RemoveAll();
  m_260.RemoveAll();
}

// @0x1408f1fd0
Unk_UserProxy &Unk_UserProxy::operator=(const Unk_UserProxy &p) {
  FUN_1408efa70(p);
  return *this;
}

// @0x1408f2000
unsigned char Unk_UserProxy::FUN_1408f2000() { return m_24; }

// @0x1408f2020
void Unk_UserProxy::FUN_1408f2020(unsigned char value) {
  unsigned char limit = FUN_14028da10();
  m_24 = value < limit ? value : limit;
}

// @0x1408f2070
int Unk_UserProxy::FUN_1408f2070() { return m_24 > 0; }

// @0x1408f20b0
bool Unk_UserProxy::FUN_1408f20b0(int bit) { return m_94[bit]; }

// @0x1408f20e0
void Unk_UserProxy::FUN_1408f20e0(int bit, bool value) { m_94.Set(bit, value); }

// @0x1408f2170
Unk_UserProxyBits::Unk_UserProxyBits() { Fill(0); }

// @0x1408f2300
Unk_UserProxyLabel::Unk_UserProxyLabel() { Clear(); }

// @0x1408f2850
Unk_UserProxyLabel &Unk_UserProxyLabel::operator=(const Unk_UserProxyLabel &p) {
  m_0 = p.m_0;
  m_8 = p.m_8;
  m_c = p.m_c;
  m_10 = p.m_10;
  m_18 = p.m_18;
  return *this;
}

// @0x1408f28c0
bool Unk_UserProxyBits::operator[](int p) const { return Test(p); }

// @0x1408f2c50
void CNAPlatformProxy::vfunc_68() {
  m_70 = L"";
  m_60 = L"";
  m_68 = L"";
}

// @0x1408f2cb0
void Unk_UserProxyLabel::CopyFrom(const Unk_UserProxyLabel &p) {
  m_0 = p.m_0;
  m_8 = p.m_8;
  m_c = p.m_c;
  m_10 = p.m_10;
  m_18 = p.m_18;
}

// @0x1408f2d20
void Unk_UserProxyBits::Decode(CInputStream &s) {
  for (int i = 0; i < 1; ++i)
    m_bits[i] = s.ReadUInt8();
}

// @0x1408f2d70
void Unk_UserProxyLabel::Decode(CInputStream &s) {
  m_0 = s.ReadUnicodeString();
  m_8 = s.ReadInt32();
  m_c = s.ReadInt32();
  m_10 = s.ReadInt32();
  m_18 = s.ReadInt64();
}

// @0x1408f2e30
void CPlatformProxy::vfunc_6(CInPacket &p) {}

// @0x1408f2e40
void Unk_UserProxyBits::Encode(COutputStream &s) {
  for (int i = 0; i < 1; ++i)
    s.WriteUInt8(m_bits[i]);
}

// @0x1408f2ea0
void Unk_UserProxyLabel::Encode(COutputStream &s) {
  s.WriteUnicodeString(m_0);
  s.WriteInt32(m_8);
  s.WriteInt32(m_c);
  s.WriteInt32(m_10);
  s.WriteInt64(m_18);
}

// @0x1408f2f40
void CPlatformProxy::vfunc_5(COutputStream &s) {}

// @0x1408f2f50
CString CNAPlatformProxy::vfunc_40() {
  {
    if (Unk_LockGuard lock = m_lock) {
        __assume(0);
    } else {
      return m_38;
    }
  }
}

// @0x1408f2fe0
CString CPlatformProxy::vfunc_40() { return ""; }

// @0x1408f3020
float CNAPlatformProxy::vfunc_42() {
  {
    if (Unk_LockGuard lock = m_lock) {
        __assume(0);
    } else {
      return m_40;
    }
  }
}

// @0x1408f3090
float CPlatformProxy::vfunc_42() { return 0; }

// @0x1408f30a0
__int64 CNAPlatformProxy::vfunc_44() {
  {
    if (Unk_LockGuard lock = m_lock) {
        __assume(0);
    } else {
      return m_48;
    }
  }
}

// @0x1408f3110
__int64 CPlatformProxy::vfunc_44() { return 0; }

// @0x1408f3120
int CNAPlatformProxy::vfunc_46() { return m_50; }

// @0x1408f3130
int CPlatformProxy::vfunc_46() { return 0; }

// @0x1408f3140
int CNAPlatformProxy::vfunc_54() { return m_90; }

// @0x1408f3160
int CPlatformProxy::vfunc_54() { return 0; }

// @0x1408f3170
__int64 CNAPlatformProxy::vfunc_56() { return m_98; }

// @0x1408f3190
__int64 CPlatformProxy::vfunc_56() { return 0; }

// @0x1408f31a0
int CCNPlatformProxy::vfunc_22() { return m_48; }

// @0x1408f31b0
int CPlatformProxy::vfunc_22() { return 0; }

// @0x1408f32b0
__int64 CNAPlatformProxy::vfunc_50() { return m_80; }

// @0x1408f32d0
__int64 CPlatformProxy::vfunc_50() { return 0; }

// @0x1408f32e0
int CPlatformProxy::vfunc_38() { return 0; }

// @0x1408f32f0
float CCNPlatformProxy::vfunc_24() { return m_4c; }

// @0x1408f3300
float CPlatformProxy::vfunc_24() { return 1.0f; }

// @0x1408f3310
CString CCNPlatformProxy::vfunc_58() { return "CN"; }

// @0x1408f3350
CString CJPPlatformProxy::vfunc_58() { return "JP"; }

// @0x1408f3390
CString CKRPlatformProxy::vfunc_58() { return "KR"; }

// @0x1408f33d0
int CCNPlatformProxy::vfunc_20() { return m_44; }

// @0x1408f33e0
int CPlatformProxy::vfunc_20() { return 0; }

// @0x1408f33f0
__int64 CCNPlatformProxy::vfunc_28() { return m_58; }

// @0x1408f3400
__int64 CPlatformProxy::vfunc_28() { return 0; }

// @0x1408f3410
__int64 CCNPlatformProxy::vfunc_33() { return m_68; }

// @0x1408f3420
__int64 CPlatformProxy::vfunc_33() { return 0; }

// @0x1408f34b0
int CCNPlatformProxy::vfunc_60() { return m_78; }

// @0x1408f34c0
int CJPPlatformProxy::vfunc_60() { return 0; }

// @0x1408f34d0
int CKRPlatformProxy::vfunc_60() { return 0; }

// @0x1408f34e0
int CNAPlatformProxy::vfunc_60() { return 0; }

// @0x1408f34f0
__int64 CCNPlatformProxy::vfunc_18() { return m_38; }

// @0x1408f3500
__int64 CJPPlatformProxy::vfunc_18() { return m_40; }

// @0x1408f3510
__int64 CKRPlatformProxy::vfunc_18() { return m_40; }

// @0x1408f3520
__int64 CNAPlatformProxy::vfunc_18() { return m_78; }

// @0x1408f3530
__int64 CPlatformProxy::vfunc_18() { return 0; }

// @0x1408f3540
int CJPPlatformProxy::vfunc_14() { return m_34; }

// @0x1408f3550
int CKRPlatformProxy::vfunc_14() { return m_34; }

// @0x1408f3560
int CPlatformProxy::vfunc_14() { return 0; }

// @0x1408f3570
int CJPPlatformProxy::vfunc_12() { return m_30 == 2 ? 1 : 0; }

// @0x1408f35a0
int CKRPlatformProxy::vfunc_12() { return m_30 == 2 ? 1 : 0; }

// @0x1408f35d0
int CPlatformProxy::vfunc_12() { return 3; }

// @0x1408f35e0
CString CJPPlatformProxy::vfunc_10() {
  {
    if (Unk_LockGuard lock = m_lock) {
        __assume(0);
    } else {
      return m_78;
    }
  }
}

// @0x1408f3670
CString CKRPlatformProxy::vfunc_10() {
  {
    if (Unk_LockGuard lock = m_lock) {
        __assume(0);
    } else {
      return m_78;
    }
  }
}

// @0x1408f3700
CString CNAPlatformProxy::vfunc_10() {
  {
    if (Unk_LockGuard lock = m_lock) {
        __assume(0);
    } else {
      return m_30;
    }
  }
}

// @0x1408f3790
CString CPlatformProxy::vfunc_10() { return ""; }

// @0x1408f37d0
__int64 CCNPlatformProxy::vfunc_8() { return m_28; }

// @0x1408f37e0
__int64 CJPPlatformProxy::vfunc_8() { return m_28; }

// @0x1408f37f0
__int64 CKRPlatformProxy::vfunc_8() { return m_28; }

// @0x1408f3800
__int64 CNAPlatformProxy::vfunc_8() { return m_28; }

// @0x1408f3810
int CJPPlatformProxy::vfunc_16() { return m_38; }

// @0x1408f3820
int CKRPlatformProxy::vfunc_16() { return m_38; }

// @0x1408f3830
int CPlatformProxy::vfunc_16() { return 0; }

// @0x1408f3840
__int64 CNAPlatformProxy::vfunc_52() { return m_88; }

// @0x1408f3860
__int64 CPlatformProxy::vfunc_52() { return 0; }

// @0x1408f3870
CString CNAPlatformProxy::vfunc_48() {
  {
    if (Unk_LockGuard lock = m_lock) {
        __assume(0);
    } else {
      return m_58;
    }
  }
}

// @0x1408f3900
CString CPlatformProxy::vfunc_48() { return ""; }

// @0x1408f3940
CString CNAPlatformProxy::vfunc_62() { return m_60; }

// @0x1408f3990
CString CNAPlatformProxy::vfunc_64() { return m_68; }

// @0x1408f39e0
CString CNAPlatformProxy::vfunc_66() { return m_70; }

// @0x1408f3a30
int CPlatformProxy::vfunc_37() { return 0; }

// @0x1408f3a40
int CCNPlatformProxy::vfunc_26() { return m_50; }

// @0x1408f3a50
int CPlatformProxy::vfunc_26() { return 1; }

// @0x1408f3a60
int CCNPlatformProxy::vfunc_31() { return m_60; }

// @0x1408f3a70
int CPlatformProxy::vfunc_31() { return 1; }

// @0x1408f3aa0
void Unk_UserProxyLabel::Clear() {
  m_0.Empty();
  m_8 = 0;
  m_c = 0;
  m_10 = 0;
  m_18 = 0;
}

// @0x1408f3af0
void CPlatformProxy::vfunc_30() {}

// @0x1408f3b00
void CPlatformProxy::vfunc_35() {}

// @0x1408f3b10
void CNAPlatformProxy::vfunc_41(CString p) {
  if (Unk_LockGuard lock = m_lock) {
      __assume(0);
  } else {
    m_38 = p;
  }
}

// @0x1408f3b90
void CPlatformProxy::vfunc_41(CString p) {}

// @0x1408f3bb0
void CNAPlatformProxy::vfunc_43(float p) {
  if (Unk_LockGuard lock = m_lock) {
      __assume(0);
  } else {
    m_40 = p;
  }
}

// @0x1408f3c10
void CPlatformProxy::vfunc_43(float p) {}

// @0x1408f3c20
void CNAPlatformProxy::vfunc_45(__int64 p) {
  if (Unk_LockGuard lock = m_lock) {
      __assume(0);
  } else {
    m_48 = p;
  }
}

// @0x1408f3c80
void CPlatformProxy::vfunc_45(__int64 p) {}

// @0x1408f3c90
void CNAPlatformProxy::vfunc_47(int p) {
  if (Unk_LockGuard lock = m_lock) {
      __assume(0);
  } else {
    m_50 = p;
  }
}

// @0x1408f3cf0
void CPlatformProxy::vfunc_47(int p) {}

// @0x1408f3d00
void CNAPlatformProxy::vfunc_55(int p) { m_90 = p; }

// @0x1408f3d20
void CPlatformProxy::vfunc_55(int p) {}

// @0x1408f3d30
void CNAPlatformProxy::vfunc_57(__int64 p) { m_98 = p; }

// @0x1408f3d50
void CPlatformProxy::vfunc_57(__int64 p) {}

// @0x1408f3d60
void CCNPlatformProxy::vfunc_23(int p) { m_48 = p; }

// @0x1408f3d80
void CPlatformProxy::vfunc_23(int p) {}

// @0x1408f3f20
void CNAPlatformProxy::vfunc_51(__int64 p) { m_80 = p; }

// @0x1408f3f40
void CPlatformProxy::vfunc_51(__int64 p) {}

// @0x1408f3f50
void CPlatformProxy::vfunc_39(int p) {}

// @0x1408f3f60
void CCNPlatformProxy::vfunc_25(float p) { m_4c = ClampProxyValue(p, 0.0f, 1.0f); }

// @0x1408f3fa0
void CPlatformProxy::vfunc_25(float p) {}

// @0x1408f3fb0
void CCNPlatformProxy::vfunc_59(CString p) {}

// @0x1408f3fd0
void CJPPlatformProxy::vfunc_59(CString p) {}

// @0x1408f3ff0
void CKRPlatformProxy::vfunc_59(CString p) {}

// @0x1408f4010
void CNAPlatformProxy::vfunc_59(CString p) { m_a0 = p; }

// @0x1408f4060
void CCNPlatformProxy::vfunc_21(int p) { m_44 = p; }

// @0x1408f4080
void CPlatformProxy::vfunc_21(int p) {}

// @0x1408f4090
void CPlatformProxy::vfunc_29(__int64 p) {}

// @0x1408f40a0
void CCNPlatformProxy::vfunc_27(int p) { m_50 = p; }

// @0x1408f40c0
void CPlatformProxy::vfunc_27(int p) {}

// @0x1408f40d0
void CPlatformProxy::vfunc_34(__int64 p) {}

// @0x1408f40e0
void CCNPlatformProxy::vfunc_32(int p) { m_60 = p; }

// @0x1408f4100
void CPlatformProxy::vfunc_32(int p) {}

// @0x1408f4110
void CCNPlatformProxy::vfunc_61(int p) { m_78 = p; }

// @0x1408f4130
void CJPPlatformProxy::vfunc_61(int p) {}

// @0x1408f4140
void CKRPlatformProxy::vfunc_61(int p) {}

// @0x1408f4150
void CNAPlatformProxy::vfunc_61(int p) {}

// @0x1408f4160
void CCNPlatformProxy::vfunc_19(__int64 p) { m_38 = p; }

// @0x1408f4180
void CJPPlatformProxy::vfunc_19(__int64 p) { m_40 = p; }

// @0x1408f41a0
void CKRPlatformProxy::vfunc_19(__int64 p) { m_40 = p; }

// @0x1408f41c0
void CNAPlatformProxy::vfunc_19(__int64 p) { m_78 = p; }

// @0x1408f41e0
void CPlatformProxy::vfunc_19(__int64 p) {}

// @0x1408f41f0
void CJPPlatformProxy::vfunc_15(int p) { m_34 = p; }

// @0x1408f4210
void CKRPlatformProxy::vfunc_15(int p) { m_34 = p; }

// @0x1408f4230
void CPlatformProxy::vfunc_15(int p) {}

// @0x1408f4240
void CJPPlatformProxy::vfunc_13(int p) { m_30 = p; }

// @0x1408f4260
void CKRPlatformProxy::vfunc_13(int p) { m_30 = p; }

// @0x1408f4280
void CPlatformProxy::vfunc_13(int p) {}

// @0x1408f4290
void CJPPlatformProxy::vfunc_11(CString p) {
  if (Unk_LockGuard lock = m_lock) {
      __assume(0);
  } else {
    m_78 = p;
  }
}

// @0x1408f4310
void CKRPlatformProxy::vfunc_11(CString p) {
  if (Unk_LockGuard lock = m_lock) {
      __assume(0);
  } else {
    m_78 = p;
  }
}

// @0x1408f4390
void CNAPlatformProxy::vfunc_11(CString p) {
  if (Unk_LockGuard lock = m_lock) {
      __assume(0);
  } else {
    m_30 = p;
  }
}

// @0x1408f4410
void CPlatformProxy::vfunc_11(CString p) {}

// @0x1408f4430
void CCNPlatformProxy::vfunc_9(__int64 p) { m_28 = p; }

// @0x1408f4450
void CJPPlatformProxy::vfunc_9(__int64 p) { m_28 = p; }

// @0x1408f4470
void CKRPlatformProxy::vfunc_9(__int64 p) { m_28 = p; }

// @0x1408f4490
void CNAPlatformProxy::vfunc_9(__int64 p) { m_28 = p; }

// @0x1408f44b0
void CJPPlatformProxy::vfunc_17(int p) { m_38 = p; }

// @0x1408f44d0
void CKRPlatformProxy::vfunc_17(int p) { m_38 = p; }

// @0x1408f44f0
void CPlatformProxy::vfunc_17(int p) {}

// @0x1408f4500
void CNAPlatformProxy::vfunc_53(__int64 p) { m_88 = p; }

// @0x1408f4520
void CPlatformProxy::vfunc_53(__int64 p) {}

// @0x1408f4530
void CNAPlatformProxy::vfunc_49(CString p) {
  if (Unk_LockGuard lock = m_lock) {
      __assume(0);
  } else {
    m_58 = p;
  }
}

// @0x1408f45b0
void CPlatformProxy::vfunc_49(CString p) {}

// @0x1408f45d0
void CNAPlatformProxy::vfunc_63(const CString &p) { m_60 = p; }

// @0x1408f4600
void CNAPlatformProxy::vfunc_65(const CString &p) { m_68 = p; }

// @0x1408f4630
void CNAPlatformProxy::vfunc_67(const CString &p) { m_70 = p; }

// @0x1408f4660
void CPlatformProxy::vfunc_7(void *p) { m_18 = p; }

// @0x1408f4680
void CPlatformProxy::vfunc_36(int p) {}
// @0x1408f4690
void Unk_UserProxyLabel::Expire() {
  if (m_18 != 0) {
    __int64 now = FUN_140869440();
    if (now > m_18)
      Clear();
  }
}

// @0x1408f49c0
Unk_UserProxyBits &Unk_UserProxyBits::Reset() {
  Fill(0);
  return *this;
}

// @0x1408f49e0
Unk_UserProxyBits &Unk_UserProxyBits::Set(int pos, bool value) {
  if ((unsigned)pos >= 7u) {
    PROXY_BITS_ASSERT(243);
  }
  if (value)
    m_bits[pos / 8] |= 1 << (pos % 8);
  else
    m_bits[pos / 8] &= ~(1 << (pos % 8));
  return *this;
}

// @0x1408f4b00
bool Unk_UserProxyBits::Test(int pos) const {
  if ((unsigned)pos >= 7u) {
    PROXY_BITS_ASSERT(404);
    return false;
  }
  return (m_bits[pos / 8] & (1 << (pos % 8))) != 0;
}

// @0x1408f4ba0
void Unk_UserProxyBits::Fill(unsigned char value) {
  for (int i = 0; i >= 0; --i)
    m_bits[i] = value;
  if (value)
    Trim();
}

// @0x1408f4c00
void Unk_UserProxyBits::Trim() {
  if (7 % 8)
    return;
  m_bits[0] &= (1 << (7 % 8)) - 1;
}

// @0x1408f4c40
CStringW Unk_UserProxyTriggerText::GetText() {
  if (m_10 == 0)
    return L"\0";
  switch (m_10) {
  case 1:
    return L"";
  case 2:
    return FUN_1405c2690(L"s_user_trigger_label_action", m_0);
  case 3:
    return FUN_1405c2690(L"s_user_trigger_label_condition", m_0);
  case 4:
    return m_8;
  default:
    return L"";
  }
}

// No hooks for constructors/destructors, the platform factory, or the COMDAT tail.
// Packet wrapper methods constructing RTTI-bearing embedded club/platform objects are also left unhooked.
