// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Event reward/context helpers.
// MS2-UNIT: commonfiles\usereventcontext.cpp
// MS2-RANGE: 0x1408d5470-0x1408d6b30 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\usereventcontext.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "usereventcontext.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
template<class S> void TokenizeEvent(const CStringW&, ATL::CAtlArray<S>&, const wchar_t*);
void FUN_14025a680(CStringW&, ATL::CAtlArray<CStringW>&, const wchar_t*);
int FUN_140718170(const CString&);
CMsTime FUN_140718950(const CString&);
CString FUN_140274f70(CStringW&);
// @0x1408d5470
void UserEventContext::SetData(const Unk_EventCore& other) { data = other; }
MS2_REPLACE_METHOD(0x1408D5470, UserEventContext, SetData, 37, 0x8FF6C884);
// @0x1408d54a0
bool UserEventContext::AddItem(int id, int count, unsigned char rarity, int kind, __int64 time) {
    if (items.GetCount() >= 5) { MS2_ASSERT_AT(141, FALSE); return false; }
    if (id == 0) { MS2_ASSERT_AT(147, FALSE); return false; }
    if ((rarity >= 1 && rarity <= 6) == false) { MS2_ASSERT_AT(153, FALSE); return false; }
    Unk_EventItem item;
    item.id=id; item.count=count; item.kind=kind; item.rarity=rarity; item.time=time;
    items.Add(item);
    return true;
}
MS2_REPLACE_METHOD(0x1408D54A0, UserEventContext, AddItem, 300, 0xBCB6825C);
// @0x1408d55e0
bool UserEventContext::AddExtra(Unk_EventExtra id) {
    if (extras.GetCount() >= 4) return false;
    extras.Add(id);
    return true;
}
MS2_REPLACE_METHOD(0x1408D55E0, UserEventContext, AddExtra, 70, 0x17CD39DC);
// @0x1408d5630
bool UserEventContext::ParseItem(const CStringW& text) {
    const int required = 4;
    ATL::CAtlArray<CString> fields;
    TokenizeEvent(text, fields, L",");
    int count = static_cast<int>(fields.GetCount());
    if (count < required) { MS2_ASSERT_AT(112, FALSE); return false; }
    int id = FUN_140718170(fields[0]);
    int number = FUN_140718170(fields[1]);
    int rarity = FUN_140718170(fields[2]);
    int kind = FUN_140718170(fields[3]);
    __int64 time = 0;
    if (count > 4) { CMsTime parsed = FUN_140718950(fields[4]); time = parsed.Get(); }
    return AddItem(id, number, rarity, kind, time);
}
MS2_REPLACE_METHOD(0x1408D5630, UserEventContext, ParseItem, 393, 0x3753F83F);
// @0x1408d57c0
bool UserEventContext::ParseItems(const CStringW& text) {
    ATL::CAtlArray<CStringW> entries;
    FUN_14025a680(const_cast<CStringW&>(text), entries, L"|");
    for (size_t i=0; i<entries.GetCount(); ++i) {
        const CStringW& entry = entries.GetAt(i);
        if (!ParseItem(entry)) return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x1408D57C0, UserEventContext, ParseItems, 188, 0x8B6675CE);
// @0x1408d58d0
void UserEventContext::FUN_1408d58d0(int mode) { data.FUN_1408d5390(mode); }
MS2_REPLACE_METHOD(0x1408D58D0, UserEventContext, FUN_1408d58d0, 35, 0x2F491AA7);
// @0x1408d5900
void UserEventContext::FUN_1408d5900(__int64 value) { data.a=value; }
MS2_REPLACE_METHOD(0x1408D5900, UserEventContext, FUN_1408d5900, 25, 0x6BD9AB1B);
// @0x1408d5920
void UserEventContext::FUN_1408d5920(__int64 value) { data.b=value; }
MS2_REPLACE_METHOD(0x1408D5920, UserEventContext, FUN_1408d5920, 25, 0x9BEF1163);
// @0x1408d5940
int UserEventContext::GetId() const { return data.id; }
MS2_REPLACE_METHOD(0x1408D5940, UserEventContext, GetId, 14, 0x7AB52803);
// @0x1408d5960
__int64 UserEventContext::FUN_1408d5960() const { return data.a; }
MS2_REPLACE_METHOD(0x1408D5960, UserEventContext, FUN_1408d5960, 15, 0x7BFFD3E9);
// @0x1408d5980
__int64 UserEventContext::FUN_1408d5980() const { return data.b; }
MS2_REPLACE_METHOD(0x1408D5980, UserEventContext, FUN_1408d5980, 15, 0x8B0075C1);
// @0x1408d59a0
__int64 UserEventContext::FUN_1408d59a0() const { return data.c; }
MS2_REPLACE_METHOD(0x1408D59A0, UserEventContext, FUN_1408d59a0, 15, 0x5AEB0F79);
// @0x1408d59c0
size_t UserEventContext::GetItemCount() const { return items.GetCount(); }
MS2_REPLACE_METHOD(0x1408D59C0, UserEventContext, GetItemCount, 31, 0x4BCB705C);
// @0x1408d59f0
const ATL::CAtlArray<Unk_EventItem>& UserEventContext::GetItems() const { return items; }
MS2_REPLACE_METHOD(0x1408D59F0, UserEventContext, GetItems, 15, 0x77A75649);
// @0x1408d5a10
void Unk_EventRewards::FUN_1408d5a10(const Unk_EventPtr<Unk_EventPayload>& value) { r38=value; }
MS2_REPLACE_METHOD(0x1408D5A10, Unk_EventRewards, FUN_1408d5a10, 41, 0xFFC549D7);
// @0x1408d5a40
Unk_EventPtr<Unk_EventPayload> Unk_EventRewards::FUN_1408d5a40() const { return r38; }
MS2_REPLACE_METHOD(0x1408D5A40, Unk_EventRewards, FUN_1408d5a40, 65, 0x6E529B43);
// @0x1408d5ad0
void Unk_EventCounters::SetValue(__int64 n) { value=n; }
MS2_REPLACE_METHOD(0x1408D5AD0, Unk_EventCounters, SetValue, 25, 0x8BB2CE0B);
// @0x1408d5af0
void Unk_EventRewards::FUN_1408d5af0(__int64 value) { n30=value; }
MS2_REPLACE_METHOD(0x1408D5AF0, Unk_EventRewards, FUN_1408d5af0, 25, 0x3BC76AD3);
// @0x1408d5b30
void Unk_EventRewards::FUN_1408d5b30(const Unk_EventPtr<Unk_EventPayload>& value) { r48=value; }
MS2_REPLACE_METHOD(0x1408D5B30, Unk_EventRewards, FUN_1408d5b30, 41, 0xDD1420E6);
// @0x1408d5b60
Unk_EventPtr<Unk_EventPayload> Unk_EventRewards::FUN_1408d5b60() const { return r48; }
MS2_REPLACE_METHOD(0x1408D5B60, Unk_EventRewards, FUN_1408d5b60, 65, 0x4B5A7CAE);
// @0x1408d5bb0
void Unk_EventRewards::FUN_1408d5bb0(const Unk_EventPtr<Unk_EventPayload>& value) { r20=value; }
MS2_REPLACE_METHOD(0x1408D5BB0, Unk_EventRewards, FUN_1408d5bb0, 41, 0xC4EC1EB1);
// @0x1408d5be0
Unk_EventPtr<Unk_EventPayload> Unk_EventRewards::FUN_1408d5be0() const { return r20; }
MS2_REPLACE_METHOD(0x1408D5BE0, Unk_EventRewards, FUN_1408d5be0, 65, 0xFB81EE39);
// Hook deferred: this method allocates the recovered DTReward and would install DLL-local RTTI.
// @0x1408d5c30
void Unk_EventRewardList::AddReward(const ATL::CAtlArray<unsigned int>& fields) {
    if (fields.GetCount() != 9) return;
    MS2Ptr<EventStruct::DTReward> reward(new EventStruct::DTReward);
    reward->a=fields[0]; reward->b=fields[1]; reward->c=fields[2]; reward->d=fields[3];
    reward->e=fields[4]; reward->f=fields[5]; reward->g=fields[6]; reward->h=fields[7]; reward->i=fields[8];
    rewards.Add(reward);
}
// @0x1408d5e70
void Unk_EventReward40::FUN_1408d5e70(const Unk_EventPtr<Unk_EventPayload>& value) { r40=value; }
MS2_REPLACE_METHOD(0x1408D5E70, Unk_EventReward40, FUN_1408d5e70, 41, 0x7556B933);
// @0x1408d5ea0
Unk_EventPtr<Unk_EventPayload> Unk_EventReward40::FUN_1408d5ea0() const { return r40; }
MS2_REPLACE_METHOD(0x1408D5EA0, Unk_EventReward40, FUN_1408d5ea0, 65, 0xD0EB806F);
template<class S>
void TokenizeEvent(const CStringW& text, ATL::CAtlArray<S>& output, const wchar_t* delimiter) {
    int start=0;
    CStringW token = text.Tokenize(delimiter, start);
    while (!token.IsEmpty()) {
        output.Add(FUN_140274f70(token));
        token=text.Tokenize(delimiter, start);
    }
}
MS2_EMIT_CRT_MEMMOVE_S();
