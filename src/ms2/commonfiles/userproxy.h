#pragma once
#include "ms2/placeholder/cplatformproxy.h"
#include "ms2/placeholder/cuserplayinfoproxy.h"
#include "ms2/placeholder/clubuserclub.h"
#include <set>

// This pointer specialization has a stealing move constructor and raw-pointer assignment.
// Its original template name is unknown. Layout and reference helpers match the 16-byte
// intrusive pointer used elsewhere; these additional operations are local to this unit.
template <class T> class Unk_UserProxyPtr {
public:
  Unk_UserProxyPtr() { m_p = 0; }
  Unk_UserProxyPtr(int) { m_p = 0; }
  Unk_UserProxyPtr(T *p) {
    m_p = p;
    AddRef();
  }
  Unk_UserProxyPtr(Unk_UserProxyPtr &&p) {
    m_p = p.m_p;
    p.m_p = 0;
  }
  ~Unk_UserProxyPtr() { Release(); }
  Unk_UserProxyPtr &operator=(const Unk_UserProxyPtr &p) {
    p.AddRef();
    Release();
    m_p = p.m_p;
    return *this;
  }
  Unk_UserProxyPtr &operator=(int) {
    Release();
    return *this;
  }
  Unk_UserProxyPtr &operator=(T *p) {
    Unk_UserProxyPtr tmp(p);
    T *old = m_p;
    m_p = tmp.m_p;
    tmp.m_p = old;
    return *this;
  }
  T *get() const { return m_p; }
  T *operator->() const { return m_p; }
  // @0x1417470e0 (T = CPlatformProxy; scenestategame.cpp)
  bool operator==(T *p) const { return m_p == p; }
  void AddRef() const {
    if (m_p)
      AddRefImpl(0);
  }
  static void Reference(T *p) { CPtred::AddRefPtred(p); }
  void AddRefImpl(void *) const { Reference(m_p); }
  void Release() {
    if (m_p) {
      ReleaseImpl(0);
      m_p = 0;
    }
  }
  void ReleaseImpl(void *) {
    if (CPtred::ReleasePtred(m_p) == 0) {
      Reference(m_p);
      CPtred::DeletePtred(m_p);
    }
  }

private:
  void *m_00;
  T *m_p;
};
MS2_CHECK_SIZE(Unk_UserProxyPtr<CPlatformProxy>, 0x10);
Unk_UserProxyPtr<CPlatformProxy> FUN_1408e7250();

// Distinct lock constructor overloads, verified at the annotated exe addresses.
class Unk_UserProxyWriteLock {
public:
  Unk_UserProxyWriteLock(CLockCriticalSection &, int);
  ~Unk_UserProxyWriteLock();

private:
  void *m_p;
};
class Unk_UserProxyConstLock {
public:
  Unk_UserProxyConstLock(const CLockCriticalSection &, int);
  ~Unk_UserProxyConstLock();

private:
  void *m_p;
};
MS2_CHECK_SIZE(Unk_UserProxyWriteLock, 8);
MS2_CHECK_SIZE(Unk_UserProxyConstLock, 8);
class Unk_UserProxyColor {
public:
  Unk_UserProxyColor();
  void Clear();
  void FUN_140267d00(const Unk_UserProxyColor &);
  void FUN_140267e40(COutputStream &);
  void FUN_140267e70(CInputStream &);
  Unk_UserProxyColor &operator=(const Unk_UserProxyColor &);
  int m_0, m_4, m_8;
};
MS2_CHECK_SIZE(Unk_UserProxyColor, 12);
class Unk_UserProxyBits {
public:
  Unk_UserProxyBits();
  Unk_UserProxyBits &Reset();
  bool Test(int) const;
  bool operator[](int) const;
  Unk_UserProxyBits &Set(int, bool);
  void Fill(unsigned char);
  void Trim();
  void Encode(COutputStream &);
  void Decode(CInputStream &);
  unsigned char m_bits[1]; // Genuine packed seven-bit array, not padding.
};
MS2_CHECK_SIZE(Unk_UserProxyBits, 1);
struct Unk_UserProxyLabel {
  Unk_UserProxyLabel();
  // @0x1408f2590
  ~Unk_UserProxyLabel() = default;
  Unk_UserProxyLabel &operator=(const Unk_UserProxyLabel &);
  void CopyFrom(const Unk_UserProxyLabel &);
  void Encode(COutputStream &);
  void Decode(CInputStream &);
  void Clear();
  void Expire();
  CStringW m_0;
  int m_8, m_c, m_10;
  __int64 m_18;
};
MS2_CHECK_SIZE(Unk_UserProxyLabel, 0x20);
class CItem;
class Unk_UserProxy;
struct Unk_UserProxyFlagsPacket {
  Unk_UserProxyFlagsPacket();
  void CopyFrom(Unk_UserProxy *);
  void Encode(COutputStream &);
  void Decode(CInPacket &);
  __int64 m_0;
  int m_8, m_c;
  unsigned short m_10;
};
MS2_CHECK_SIZE(Unk_UserProxyFlagsPacket, 0x18);
struct Unk_UserProxyStatsPacket {
  Unk_UserProxyStatsPacket();
  void CopyFrom(Unk_UserProxy *);
  void Encode(COutputStream &);
  void Decode(CInPacket &);
  __int64 m_0;
  int m_8, m_c, m_10;
};
MS2_CHECK_SIZE(Unk_UserProxyStatsPacket, 0x18);
struct Unk_UserProxyClubPacket {
  Unk_UserProxyClubPacket();
  // @0x1408f25b0
  ~Unk_UserProxyClubPacket() = default;
  void CopyFrom(Unk_UserProxy *);
  void Encode(COutputStream &);
  void Decode(CInPacket &);
  void GetClubs(ATL::CAtlArray<MS2Ptr<Club::NameInfo>> &);
  __int64 m_0, m_8;
  CStringW m_10;
  __int64 m_18;
  Club::UserClub m_20;
};
MS2_CHECK_SIZE(Unk_UserProxyClubPacket, 0x68);
struct Unk_UserProxySummaryPacket {
  Unk_UserProxySummaryPacket();
  // @0x1408f25f0
  ~Unk_UserProxySummaryPacket() = default;
  void CopyFrom(Unk_UserProxy *);
  void Encode(COutputStream &);
  void Decode(CInPacket *);
  void GetClubs(ATL::CAtlArray<MS2Ptr<Club::NameInfo>> &);
  __int64 m_0;
  CStringW m_8;
  unsigned char m_10;
  int m_14;
  short m_18;
  int m_1c, m_20;
  unsigned char m_24;
  __int64 m_28;
  CStringW m_30;
  CString m_38;
  Club::UserClub m_40;
  Unk_UserProxyPtr<CPlatformProxy> m_88;
  CString m_98;
  __int64 m_a0;
};
MS2_CHECK_SIZE(Unk_UserProxySummaryPacket, 0xa8);
class Unk_UserProxy {
public:
  Unk_UserProxy();
  Unk_UserProxy(const Unk_UserProxy &);
  ~Unk_UserProxy();
  // MS2-USERPROXY-METHODS
  void FUN_1408f1e60();
  void FUN_1408eeb60(CInPacket *p);
  void FUN_1408ee190(COutputStream &s);
  void FUN_1408ed170(CInPacket *p);
  void FUN_1408ec5e0(COutputStream &s);
  Unk_UserProxy &operator=(const Unk_UserProxy &p);
  void FUN_1408efa70(const Unk_UserProxy &p);
  void FUN_1408ebe30();
  void FUN_1408ec260();
  void FUN_1408ef900(CInPacket &p);
  void FUN_1408ef880(COutputStream &s);
  void FUN_1408f06e0(Unk_UserProxyClubPacket &p);
  void FUN_1408f0520(Unk_UserProxySummaryPacket &p);
  void FUN_1408f04c0(const Unk_UserProxyStatsPacket &p);
  void FUN_1408f0460(const Unk_UserProxyFlagsPacket &p);
  void FUN_1408efa00(CInPacket &s);
  void FUN_1408ef990(COutputStream &s);
  void FUN_1408ec570(CInPacket &s);
  void FUN_1408ec500(COutputStream &s);
  void FUN_1408ec4b0(CInPacket &s);
  void FUN_1408ec460(COutputStream &s);
  void FUN_1408ec410(CInPacket &s);
  void FUN_1408ec3c0(COutputStream &s);
  void FUN_1408f20e0(int bit, bool value);
  bool FUN_1408f20b0(int bit);
  int FUN_1408f2070();
  void FUN_1408f2020(unsigned char value);
  unsigned char FUN_1408f2000();
  int FUN_1408f1db0();
  __int64 FUN_1408f1d80();
  int FUN_1408f1d60();
  unsigned short FUN_1408f1d30();
  int FUN_1408f1ce0();
  void FUN_1408f1970(CInPacket &p);
  void FUN_1408f18a0();
  void FUN_1408f1900(COutputStream &p);
  void FUN_1408f1830(const ATL::CAtlArray<MS2Ptr<Club::NameInfo>> &p);
  void FUN_1408f17c0(ATL::CAtlArray<MS2Ptr<Club::NameInfo>> &p);
  void FUN_1408f1710(__int64 id, CStringW name);
  void FUN_1408f16a0(__int64 id);
  int FUN_1408f1600(MS2Ptr<Club::NameInfo> p);
  int FUN_1408f1560(__int64 id, CStringW name);
  int FUN_1408f14f0();
  size_t FUN_1408f1480();
  MS2Ptr<Club::NameInfo> FUN_1408f13f0(__int64 id);
  __int64 FUN_1408f1330();
  void FUN_1408f1270(ATL::CAtlArray<unsigned __int64> &out);
  void FUN_1408f1200();
  void FUN_1408f1190(unsigned __int64 p);
  void FUN_1408f1110(unsigned __int64 p);
  void FUN_1408f1090(CString p);
  void FUN_1408f1040(__int64 p);
  void FUN_1408f0fb0();
  void FUN_1408f0f20(CInputStream &s);
  void FUN_1408f0e90(COutputStream &s);
  void FUN_1408f0e00();
  int FUN_1408f0d30(int i);
  void FUN_1408f0ca0(int i, Unk_UserProxyLabel &p);
  void FUN_1408f0c10(int i, const Unk_UserProxyLabel &p);
  void FUN_1408f0b70(Unk_UserProxyLabel &label, int a, int b, int c, const CStringW &text, __int64 until);
  void FUN_1408f0b00(int p);
  void FUN_1408f0aa0(int p);
  void FUN_1408f07a0(const Unk_UserProxyColor &p);
  CString FUN_1408f1de0() const;
  CString FUN_1408f1c60() const;
  CStringW FUN_1408f1be0() const;
  CStringW FUN_1408f1b60();
  CStringW FUN_1408f1ae0();
  CString FUN_1408f1a60();
  CStringW FUN_1408f19e0();
  void FUN_1408f08c0(const CStringW &p);
  void FUN_1408f0a30(const CString &p);
  void FUN_1408f09c0(const CStringW &p);
  void FUN_1408f0950(const CStringW &p);
  void FUN_1408f0850(const CString &p);
  void FUN_1408f07e0(const CStringW &p);
  // @0x141748180 (scenestategame.cpp): the platform account id
  __int64 FUN_141748180() { return m_330 == 0 ? 0 : m_330->vfunc_8(); }
  // @0x1417480a0 (scenestategame.cpp): the platform account name
  CString FUN_1417480a0() { return m_330 == 0 ? "" : (const char *)m_330->vfunc_10(); }
  __int64 m_0, m_8;
  int m_10;
  unsigned char m_14;
  __int64 m_18;
  int m_20;
  unsigned char m_24;
  int m_28, m_2c, m_30;
  short m_34;
  int m_38, m_3c, m_40, m_44, m_48;
  unsigned short m_4c;
  __int64 m_50;
  int m_58[2];
  __int64 m_60, m_68, m_70;
  unsigned char m_78;
  __int64 m_80, m_88;
  int m_90;
  Unk_UserProxyBits m_94;
  int m_98, m_9c, m_a0;
  __int64 m_a8, m_b0, m_b8;
  int m_c0;
  Vector3 m_c4;
  int m_d0;
  Unk_UserProxyColor m_d4;
  Unk_UserProxyLabel m_e0[3];
  int m_140[12];
  std::set<unsigned __int64> m_170;   // unsigned: erase(key) 0x1404bfb40 / find(key) 0x1404c0270 compare with less<unsigned __int64> 0x14044a540 (jae)
  int m_180;
  bool m_184;
  __int64 m_188;
  int m_190, m_194;
  __int64 m_198;
  CString m_1a0;
  int m_1a8;
  short m_1ac;
  __int64 m_1b0;
  ATL::CAtlList<__int64> m_1b8, m_1e8;
  CString m_218;
  ATL::CAtlArray<MS2Ptr<CItem>> m_220, m_240, m_260;
  __int64 m_280, m_288;
  CLockCriticalSection m_290;
  CStringW m_2c0, m_2c8;
  CString m_2d0;
  CStringW m_2d8;
  Club::UserClub m_2e0;
  CStringW m_328;
  Unk_UserProxyPtr<CPlatformProxy> m_330;
  Unk_UserProxyPtr<CUserPlayInfoProxy> m_340;
};
MS2_CHECK_SIZE(Unk_UserProxy, 0x350);
MS2_CHECK_OFFSET(Unk_UserProxy, m_28, 0x28);
MS2_CHECK_OFFSET(Unk_UserProxy, m_94, 0x94);
MS2_CHECK_OFFSET(Unk_UserProxy, m_c4, 0xc4);
MS2_CHECK_OFFSET(Unk_UserProxy, m_d4, 0xd4);
MS2_CHECK_OFFSET(Unk_UserProxy, m_e0, 0xe0);
MS2_CHECK_OFFSET(Unk_UserProxy, m_140, 0x140);
MS2_CHECK_OFFSET(Unk_UserProxy, m_170, 0x170);
MS2_CHECK_OFFSET(Unk_UserProxy, m_180, 0x180);
MS2_CHECK_OFFSET(Unk_UserProxy, m_1b8, 0x1b8);
MS2_CHECK_OFFSET(Unk_UserProxy, m_220, 0x220);
MS2_CHECK_OFFSET(Unk_UserProxy, m_290, 0x290);
MS2_CHECK_OFFSET(Unk_UserProxy, m_2e0, 0x2e0);
MS2_CHECK_OFFSET(Unk_UserProxy, m_330, 0x330);
MS2_CHECK_OFFSET(Unk_UserProxy, m_340, 0x340);

struct Unk_UserProxyTriggerText {
  CStringW GetText();
  CStringW m_0, m_8;
  int m_10;
};
MS2_CHECK_SIZE(Unk_UserProxyTriggerText, 0x18);
MS2_CHECK_OFFSET(Unk_UserProxyTriggerText, m_8, 8);
MS2_CHECK_OFFSET(Unk_UserProxyTriggerText, m_10, 0x10);
