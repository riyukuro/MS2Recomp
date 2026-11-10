// Layouts recovered from userproxy.cpp constructors, serializers and RTTI.
#pragma once
#include "ms2/placeholder/cptred.h"
#include "ms2/commonfiles/stream.h"
class UserPlayCommonInfoData : public CPtred {
public:
  UserPlayCommonInfoData();
  // @0x1408f26b0
  virtual ~UserPlayCommonInfoData() = default;
  void Reset();
  void FUN_1408e97e0(COutputStream &);
  void FUN_1408e9b40(CInputStream &);
  int m_18;
  unsigned short m_1c;
  int m_20;
  int m_24;
  __int64 m_28;
  __int64 m_30;
  __int64 m_38;
  __int64 m_40;
  __int64 m_48;
  __int64 m_50;
  __int64 m_58;
  __int64 m_60;
  int m_68;
  int m_6c;
  int m_70;
  int m_74;
  __int64 m_78;
  int m_80;
  int m_84;
  int m_88;
  int m_8c;
  int m_90;
  int m_94;
  int m_98;
  int m_9c;
  int m_a0;
  int m_a4;
  int m_a8;
  int m_ac;
  int m_b0;
  int m_b4;
  int m_b8;
  int m_bc;
};
MS2_CHECK_SIZE(UserPlayCommonInfoData, 0xc0);
MS2_CHECK_OFFSET(UserPlayCommonInfoData, m_18, 0x18);
MS2_CHECK_OFFSET(UserPlayCommonInfoData, m_bc, 0xbc);
class CUserPlayInfoProxy : public CPtred {
public:
  CUserPlayInfoProxy();
  // @0x1408f2670
  virtual ~CUserPlayInfoProxy() = default;
  void Reset();
  void FUN_1408e9f60();
  void FUN_1408ea340();
  UserPlayCommonInfoData m_18, m_d8;
  __int64 m_198;
};
MS2_CHECK_SIZE(CUserPlayInfoProxy, 0x1a0);
MS2_CHECK_OFFSET(CUserPlayInfoProxy, m_18, 0x18);
MS2_CHECK_OFFSET(CUserPlayInfoProxy, m_d8, 0xd8);
MS2_CHECK_OFFSET(CUserPlayInfoProxy, m_198, 0x198);
