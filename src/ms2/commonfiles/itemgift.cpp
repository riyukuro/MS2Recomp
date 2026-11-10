// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Item gift validation and serialization.
// MS2-UNIT: commonfiles\itemgift.cpp
// MS2-PIN: ??_GItemGift@@UEAAPEAXI@Z 0x1405b3ea0
// MS2-RANGE: 0x1405b38e0-0x1405b4080 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\itemgift.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "itemgift.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"   // C3: MS2Ptr<CItemData>::operator->
class CItemData;   // C3: MS2Ptr<CItemData>::operator->
struct Unk_GiftItem : public CItemData { };
MS2Ptr<CItemData> FUN_14053f870(int);
#include "ms2/ms2format.h"
#include "ms2/commonfiles/os.h"
class COutputStream;
COutputStream& FUN_14070f9a0(COutputStream& out, unsigned int value);  // C3: the definition's signature
int FUN_14053feb0(int);  // C3: the definition's signature
enum { ItemRank_Unknown=0 };
int XmlGetAttr(class TiXmlElement*, char const*, unsigned int&);   // C3: was FUN_140873220
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
// @0x1405b38e0
ItemGift::ItemGift() {}
// @0x1405b3930
int ItemGift::ValidateItem(CString& error) {
    MS2Ptr<CItemData> item=FUN_14053f870(m_itemId);
    if(item.IsNull()) { error=(const wchar_t*)StringFormat<unsigned int>(L"ItemGift::ValidateItem no item:{0}",m_itemId);return 0; }
    if(m_count>1) {
        if(!reinterpret_cast<Unk_GiftItem*>(item.operator->())->IsStackable()) { error=(const wchar_t*)StringFormat<unsigned int>(L"ItemGift::ValidateItem no foldable item:{0}",m_itemId);return 0; }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1405B3930, ItemGift, ValidateItem, 363, 0x5ABDEF96);
// @0x1405b3ab0
int ItemGift::vfunc_o18_1() {
    int itemRank=FUN_14053feb0(vfunc_o18_0());
    MS2_ASSERT_AT(32,itemRank != ItemRank_Unknown);
    return itemRank;
}
MS2_REPLACE_METHOD_VIA(0x1405B3AB0, ItemGift, ItemAble, vfunc_o18_1, 92, 0x589C0B82);
// @0x1405b3b20
ItemGiftPcBang::ItemGiftPcBang() : m_giftId(0) {}
// @0x1405b3b70
void ItemGiftPcBang::vfunc_4(void* xml) { ItemEntity::vfunc_2(xml);XmlGetAttr((class TiXmlElement*)(xml), "giftID", m_giftId); }
MS2_REPLACE_METHOD(0x1405B3B70, ItemGiftPcBang, vfunc_4, 63, 0x2610ADE3);
// @0x1405b3bc0
void ItemGiftPcBang::vfunc_5(Unk_GiftOutput& out) { Write(out);FUN_14070f9a0(reinterpret_cast<COutputStream&>(out), m_giftId); }
MS2_REPLACE_METHOD(0x1405B3BC0, ItemGiftPcBang, vfunc_5, 52, 0x19D5B21B);
// @0x1405b3c00
void ItemGiftPcBang::vfunc_6(Unk_GiftInput& in) { Read(in);reinterpret_cast<Unk_OSInput&>(in).Read6(m_giftId); }
MS2_REPLACE_METHOD(0x1405B3C00, ItemGiftPcBang, vfunc_6, 56, 0x5310BBA1);
// @0x1405b3c40
PlayBonusItemGift::PlayBonusItemGift() : m_systemMailId(0) {}
// @0x1405b3c90
void PlayBonusItemGift::vfunc_4(void* xml) {
    ItemGiftPcBang::vfunc_4(xml);
    int minutes=0;
    XmlGetAttr((class TiXmlElement*)(xml), "requireMins", minutes);
    XmlGetAttr((class TiXmlElement*)(xml), "systemMailID", m_systemMailId);
    m_requiredTime=minutes*60*1000;
}
MS2_REPLACE_METHOD(0x1405B3C90, PlayBonusItemGift, vfunc_4, 112, 0x45D5D2E0);
// @0x1405b3d10
void PlayBonusItemGift::vfunc_5(Unk_GiftOutput& out) { ItemGiftPcBang::vfunc_5(out);out.vfunc_3(m_requiredTime);out.vfunc_3(m_3c); }
MS2_REPLACE_METHOD(0x1405B3D10, PlayBonusItemGift, vfunc_5, 82, 0x0E6B1B17);
// @0x1405b3d70
void PlayBonusItemGift::vfunc_6(Unk_GiftInput& in) { ItemGiftPcBang::vfunc_6(in);m_requiredTime=in.vfunc_3();m_3c=in.vfunc_3(); }
MS2_REPLACE_METHOD(0x1405B3D70, PlayBonusItemGift, vfunc_6, 82, 0x1EFACAA7);
// @0x1405b3dd0
unsigned int PlayBonusItemGift::GetHours() { return GetMinutes()/60; }
MS2_REPLACE_METHOD(0x1405B3DD0, PlayBonusItemGift, GetHours, 33, 0xB81DB5E9);
// @0x1405b3e00
unsigned int PlayBonusItemGift::GetMinutes() { return m_requiredTime/1000/60; }
MS2_REPLACE_METHOD(0x1405B3E00, PlayBonusItemGift, GetMinutes, 32, 0xD8CE197E);
MS2_EMIT_CRT_MEMMOVE_S();
