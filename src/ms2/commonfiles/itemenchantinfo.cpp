// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Item enchantment state and serialization.
// MS2-UNIT: commonfiles\itemenchantinfo.cpp
// MS2-RANGE: 0x14058c160-0x14058d5c0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\itemenchantinfo.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "itemenchantinfo.h"
#include "ms2/placeholder/ms2ptr_impl.h"   // MS2Ptr<CItemEnchantInfo> bodies (0x14058d040..0x14058d570): the first obj that uses them
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
template<class Map> void CopyEnchantMap(Map& to,const Map& from) {
    for (POSITION pos=from.GetStartPosition();pos;from.GetNext(pos)) {
        to.SetAt(from.GetKeyAt(pos),from.GetValueAt(pos));
    }
}

// @0x14058c160
void Unk_EnchantHistory::FUN_14058c160() {
    itemId=0; attempts=0; failures=0; failed=false; enabled=true; extra=0;
}
MS2_REPLACE_METHOD(0x14058C160, Unk_EnchantHistory, FUN_14058c160, 72, 0x6F00E9E1);

// @0x14058c1b0
void Unk_EnchantHistory::Write(Unk_EnchantWrite& stream) const {
    stream.vfunc_4(itemId); stream.vfunc_3(attempts); stream.vfunc_3(failures); stream.vfunc_0(enabled); stream.vfunc_3(extra);
}
MS2_REPLACE_METHOD(0x14058C1B0, Unk_EnchantHistory, Write, 139, 0xAC366D52);
// @0x14058c250
void Unk_EnchantHistory::Read(Unk_EnchantRead& stream) {
    itemId=stream.vfunc_4(); attempts=stream.vfunc_3(); failures=stream.vfunc_3(); enabled=stream.vfunc_0(); extra=stream.vfunc_3();
}
MS2_REPLACE_METHOD(0x14058C250, Unk_EnchantHistory, Read, 138, 0xE36FD4B5);
// @0x14058c2e0
CItemEnchantInfo::CItemEnchantInfo(int id, int rarity) : m_id(id), m_rarity(rarity), m_version(0) { Reset(); }

// Hook deferred: cloning would construct CItemEnchantInfo with DLL-local RTTI.
// @0x14058c3b0
MS2Ptr<CItemEnchantInfo> CItemEnchantInfo::Clone() {
    MS2Ptr<CItemEnchantInfo> result(new CItemEnchantInfo(m_id,m_rarity));
    result->m_level=m_level; result->m_charge=m_charge; result->m_version=m_version;
    result->m_history=m_history;
    CopyEnchantMap(result->m_options,m_options);
    return result;
}

// @0x14058c510
void CItemEnchantInfo::Reset() {
    m_level=0; m_charge=0; m_version=0; m_history.FUN_14058c160(); m_options.RemoveAll(); m_dirty=false;
}
MS2_REPLACE_METHOD(0x14058C510, CItemEnchantInfo, Reset, 96, 0x8247595A);

// @0x14058c5a0
int CItemEnchantInfo::GetAttemptCount() {
    return m_history.attempts;
}
MS2_REPLACE_METHOD(0x14058C5A0, CItemEnchantInfo, GetAttemptCount, 14, 0xB2976B17);

// @0x14058c5c0
int CItemEnchantInfo::IncrementAttemptCount() {
    return ++m_history.attempts;
}
MS2_REPLACE_METHOD(0x14058C5C0, CItemEnchantInfo, IncrementAttemptCount, 41, 0xADE1B9D7);

// @0x14058c5f0
int CItemEnchantInfo::GetLevel() {
    return m_level;
}
MS2_REPLACE_METHOD(0x14058C5F0, CItemEnchantInfo, GetLevel, 14, 0xA25B27BF);

// @0x14058c610
int CItemEnchantInfo::IncreaseLevel() {
    SetLevel(m_level+1,true); ClearCharge(); return GetLevel();
}
MS2_REPLACE_METHOD(0x14058C610, CItemEnchantInfo, IncreaseLevel, 59, 0xBD673904);

// @0x14058c660
int CItemEnchantInfo::DecreaseLevel() {
    SetLevel(m_level-1,true); ClearCharge(); return GetLevel();
}
MS2_REPLACE_METHOD(0x14058C660, CItemEnchantInfo, DecreaseLevel, 59, 0xF291359C);

// @0x14058c6b0
void CItemEnchantInfo::SetLevel(int level, bool dirty) {
    if (level < 0) { MS2_ASSERT_AT(156,FALSE); level=0; }
    m_level=level; FUN_14058ce60(); SetDirty(dirty);
}
MS2_REPLACE_METHOD(0x14058C6B0, CItemEnchantInfo, SetLevel, 109, 0x16E22D3E);

// @0x14058c730
int CItemEnchantInfo::GetCharge() {
    return m_charge;
}
MS2_REPLACE_METHOD(0x14058C730, CItemEnchantInfo, GetCharge, 14, 0xBA6447E3);

// @0x14058c750
void CItemEnchantInfo::AddCharge(int charge) {
    m_charge+=charge;
    if (m_charge<0) m_charge=0;
    if (m_charge>10000) m_charge=10000;
    SetVersion(Version());
}
MS2_REPLACE_METHOD(0x14058C750, CItemEnchantInfo, AddCharge, 104, 0x27481316);

// @0x14058c7c0
void CItemEnchantInfo::SetCharge(int charge) {
    m_charge=charge;
    if (m_charge<0) m_charge=0;
    if (m_charge>10000) m_charge=10000;
    SetVersion(Version());
}
MS2_REPLACE_METHOD(0x14058C7C0, CItemEnchantInfo, SetCharge, 96, 0x74E7F2E4);

// @0x14058c830
void CItemEnchantInfo::ClearCharge() {
    m_charge=0;
}
MS2_REPLACE_METHOD(0x14058C830, CItemEnchantInfo, ClearCharge, 18, 0xC3DE2A87);

// @0x14058c850
bool CItemEnchantInfo::IsChargeFull() {
    if (m_charge >= 10000) return true;
    return false;
}
MS2_REPLACE_METHOD(0x14058C850, CItemEnchantInfo, IsChargeFull, 26, 0xEF19BACA);

// @0x14058c870
void CItemEnchantInfo::FUN_14058c870() {
    
}
MS2_REPLACE_METHOD(0x14058C870, CItemEnchantInfo, FUN_14058c870, 6, 0xA9AF6E37);

// @0x14058c880
void CItemEnchantInfo::ClearHistoryItemId() {
    m_history.itemId=0;
}
MS2_REPLACE_METHOD(0x14058C880, CItemEnchantInfo, ClearHistoryItemId, 19, 0xD9044AAD);

// @0x14058c8a0
int CItemEnchantInfo::FUN_14058c8a0() {
    return false;
}
MS2_REPLACE_METHOD(0x14058C8A0, CItemEnchantInfo, FUN_14058c8a0, 8, 0x7F371472);

// @0x14058c8b0
__int64 CItemEnchantInfo::GetHistoryItemId() {
    return m_history.itemId;
}
MS2_REPLACE_METHOD(0x14058C8B0, CItemEnchantInfo, GetHistoryItemId, 15, 0xAC153A31);

// @0x14058c8f0
int CItemEnchantInfo::GetFailureCount() {
    return m_history.failures;
}
MS2_REPLACE_METHOD(0x14058C8F0, CItemEnchantInfo, GetFailureCount, 14, 0xCAA08B3B);

// @0x14058c910
int CItemEnchantInfo::IncrementFailureCount() {
    return ++m_history.failures;
}
MS2_REPLACE_METHOD(0x14058C910, CItemEnchantInfo, IncrementFailureCount, 41, 0xBE639D07);

// @0x14058c940
void CItemEnchantInfo::MarkFailed() {
    m_history.failed=true;
}
MS2_REPLACE_METHOD(0x14058C940, CItemEnchantInfo, MarkFailed, 15, 0x1096902D);

// @0x14058c960
bool CItemEnchantInfo::HasFailed() {
    return m_history.failed;
}
MS2_REPLACE_METHOD(0x14058C960, CItemEnchantInfo, HasFailed, 15, 0x43A40A0D);

// @0x14058c9a0
bool CItemEnchantInfo::IsEnabled() {
    return m_history.enabled;
}
MS2_REPLACE_METHOD(0x14058C9A0, CItemEnchantInfo, IsEnabled, 15, 0x63A4E804);

// @0x14058c9c0
void CItemEnchantInfo::Write(Unk_EnchantWrite& stream) const {
    stream.vfunc_3(m_level); stream.vfunc_3(m_charge); stream.vfunc_1(static_cast<unsigned char>(m_version));
    m_history.Write(stream);
    int count=static_cast<int>(m_options.GetCount());
    stream.vfunc_1(static_cast<unsigned char>(count));
    for (POSITION pos=m_options.GetStartPosition();pos;m_options.GetNext(pos)) {
        int key=m_options.GetKeyAt(pos);
        MS2Ptr<BaseOption> option=m_options.GetValueAt(pos);
        stream.vfunc_3(key); option->Write(stream);
    }
}
MS2_REPLACE_METHOD(0x14058C9C0, CItemEnchantInfo, Write, 342, 0xFD1FCBD1);

// @0x14058cb20
void CItemEnchantInfo::Read(Unk_EnchantRead& stream) {
    Reset();
    m_level=stream.vfunc_3(); m_charge=stream.vfunc_3(); m_version=stream.vfunc_1();
    m_history.Read(stream);
    int count=stream.vfunc_1();
    for(int i=0;i<count;++i) {
        int key=stream.vfunc_3();
        MS2Ptr<BaseOption> option(new BaseOption);
        option->Read(stream);
        m_options.SetAt(key,option);
    }
}
MS2_REPLACE_METHOD(0x14058CB20, CItemEnchantInfo, Read, 353, 0x7502ED0B);

// @0x14058cc90
void CItemEnchantInfo::SetDirty(bool dirty) {
    m_dirty=dirty;
}
MS2_REPLACE_METHOD(0x14058CC90, CItemEnchantInfo, SetDirty, 26, 0x506FF4A5);

// @0x14058ccb0
bool CItemEnchantInfo::GetDirty() {
    return m_dirty;
}
MS2_REPLACE_METHOD(0x14058CCB0, CItemEnchantInfo, GetDirty, 18, 0x61F4ABA5);

// @0x14058ccf0
int CItemEnchantInfo::FUN_14058ccf0() {
    return m_history.extra;
}
MS2_REPLACE_METHOD(0x14058CCF0, CItemEnchantInfo, FUN_14058ccf0, 14, 0x7A15C443);

// @0x14058cd40
Unk_EnchantMap& CItemEnchantInfo::GetOptions() {
    return m_options;
}
MS2_REPLACE_METHOD(0x14058CD40, CItemEnchantInfo, GetOptions, 15, 0x47951601);

// @0x14058cd60
int CItemEnchantInfo::NeedsChargeVersionUpdate() {
    if (m_version == Version()) return false;
    if (m_charge == 0) return false;
    return true;
}
MS2_REPLACE_METHOD(0x14058CD60, CItemEnchantInfo, NeedsChargeVersionUpdate, 53, 0x84C048D0);

// @0x14058cda0
void CItemEnchantInfo::SetVersion(int version) {
    m_version=version;
}
MS2_REPLACE_METHOD(0x14058CDA0, CItemEnchantInfo, SetVersion, 22, 0x26F5625B);

// @0x14058cdc0
int CItemEnchantInfo::GetVersion() {
    return m_version;
}
MS2_REPLACE_METHOD(0x14058CDC0, CItemEnchantInfo, GetVersion, 14, 0xD26D6807);

// @0x14058cde0
MS2Ptr<BaseOption> CItemEnchantInfo::GetOption(int key) {
    MS2Ptr<BaseOption> result;
    m_options.Lookup(key,result);
    return result;
}
MS2_REPLACE_METHOD(0x14058CDE0, CItemEnchantInfo, GetOption, 120, 0xDA1105F7);

// @0x14058ce60
void CItemEnchantInfo::FUN_14058ce60() {
    
}
MS2_REPLACE_METHOD(0x14058CE60, CItemEnchantInfo, FUN_14058ce60, 6, 0xA9AF6E37);
