// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dynamic banned-word filters.
// MS2-UNIT: commonfiles\dynamicbanwordmanager.cpp
// MS2-RANGE: 0x140348ce0-0x14034d030 .text$mn
// MS2-PIN: ??0Unk_BanChange@@QEAA@AEBVBannedWordData@@H@Z 0x14034a910
// MS2-PIN: ??0Unk_BanChange@@QEAA@XZ 0x14034a950
// MS2-PIN: ??1Unk_BanChange@@QEAA@XZ 0x14034abb0
// MS2-PIN: ??8BannedWordData@@QEBA_NAEBV0@@Z 0x14034ad60
// MS2-PIN: ??_G?$TSingleton@VCDynamicBanWordManager@@@@UEAAPEAXI@Z 0x14034aef0
// MS2-PIN: ??_GBannedWordData@@UEAAPEAXI@Z 0x14034af30
// MS2-PIN: ?Find@?$CRBTree@JV?$Unk_BanPtr@VBannedWordData@@@@V?$CElementTraits@J@ATL@@V?$CElementTraits@V?$Unk_BanPtr@VBannedWordData@@@@@3@@ATL@@IEBAPEAVCNode@12@J@Z 0x14034b290
// MS2-PIN: ??1CBannedWordFilter@@UEAA@XZ 0x14034abd0
// MS2-PIN: ??1CDynamicBanWordManager@@UEAA@XZ 0x14034ac10
// MS2-PIN: ??_GCBannedWordFilter@@UEAAPEAXI@Z 0x14034afb0
// MS2-PIN: ??_GCDynamicBanWordManager@@UEAAPEAXI@Z 0x14034aff0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\dynamicbanwordmanager.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "dynamicbanwordmanager.h"
#include "ms2/ms2format.h"
#include "logstring.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
class Unk_BanLogger {
public:
    template<class T> void Write(void* a,void* b,int flags,const wchar_t* format,const T& value) {
        fmt::internal::Value values[]={fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(value)};
        reinterpret_cast<CLogString*>(this)->FUN_1406535b0((unsigned __int64)a,(unsigned __int64)b,flags,format,fmt::ArgList(fmt::internal::make_type(value),values));
    }
};
class CLogString* GetLogString();
// @0x140348ce0
BannedWordData::BannedWordData() : id(0),type(0),word(L""),replacement(L"") {}
// @0x140348d70
BannedWordData::BannedWordData(int i,int t,const CStringW& w,const CStringW& r) : id(i),type(t),word(w),replacement(r) {}
// @0x140348e10
BannedWordData::BannedWordData(Unk_BanReader& input) { Read(input); }
// @0x140348e90
void BannedWordData::Write(Unk_BanWriter& out) const { out.vfunc_3(id); out.vfunc_3(type); out.vfunc_8(word); out.vfunc_8(replacement); }
MS2_REPLACE_METHOD(0x140348E90, BannedWordData, Write, 143, 0x484A94C4);
// @0x140348f30
void BannedWordData::Read(Unk_BanReader& input) { id=input.vfunc_3(); type=input.vfunc_3(); word=input.vfunc_8(); replacement=input.vfunc_8(); }
MS2_REPLACE_METHOD(0x140348F30, BannedWordData, Read, 218, 0xD37F3E9D);
// @0x140349010
bool BannedWordData::FUN_140349010(const BannedWordData& o) const { return *this==o; }
MS2_REPLACE_METHOD(0x140349010, BannedWordData, FUN_140349010, 34, 0x44F50C22);
// @0x140349040
void Unk_BanChange::Write(Unk_BanWriter& out) const { data.Write(out); out.vfunc_2(static_cast<unsigned short>(mode)); }
MS2_REPLACE_METHOD(0x140349040, Unk_BanChange, Write, 62, 0xF5571011);
// @0x140349090
void Unk_BanChange::Read(Unk_BanReader& input) { data.Read(input); mode=input.vfunc_2(); }
MS2_REPLACE_METHOD(0x140349090, Unk_BanChange, Read, 64, 0xBF02A1AE);
// @0x1403490e0
CBannedWordFilter::CBannedWordFilter(__int64 v,const Words& input) : version(v) { FUN_140349d00(input); }
// @0x140349170
CBannedWordFilter::CBannedWordFilter(__int64 v,Unk_BanReader& input) : version(v) { Read(input); }
// @0x140349200
void CBannedWordFilter::Write(Unk_BanWriter& out) const { FUN_140349b10(out); }
MS2_REPLACE_METHOD(0x140349200, CBannedWordFilter, Write, 34, 0x6DE6000F);
// @0x140349230
int CBannedWordFilter::FilterText(const CStringW& input,CStringW& result) {
    int start=0,offset=0,length=0; CStringW text(input); CStringW replacement; bool changed=false;
    while(filter.Find(text,start,true,&offset,&length,&replacement)) {
        if(replacement.IsEmpty()) return 2;
        text.Delete(offset,length); text.Insert(offset,replacement); start=offset+replacement.GetLength(); changed=true;
    }
    if(changed) { result=text; return 1; } return 0;
}
MS2_REPLACE_METHOD(0x140349230, CBannedWordFilter, FilterText, 414, 0x86E27D89);
// @0x1403493e0
const CBannedWordFilter::Map& CBannedWordFilter::GetWords() const { return words; }
MS2_REPLACE_METHOD(0x1403493E0, CBannedWordFilter, GetWords, 15, 0x5731F599);
// @0x140349400
__int64 CBannedWordFilter::GetVersion() const { return version; }
MS2_REPLACE_METHOD(0x140349400, CBannedWordFilter, GetVersion, 15, 0xBBB219C9);
// @0x140349420
void CBannedWordFilter::DiffFilter(const Unk_BanPtr<CBannedWordFilter>& previous,const Unk_BanPtr<CBannedWordFilter>& next,Changes& output) {
    if(next==0) { reinterpret_cast<Unk_BanLogger*>(GetLogString())->Write(0,0,0x84,L"{0} failed. pNextFilter is null",L"CBannedWordFilter::DiffFilter"); MS2_ASSERT_AT(142,FALSE); return; }
    if(previous==0) {
        const Map& map=next->GetWords();
        for(POSITION pos=map.GetHeadPosition();pos;map.GetNext(pos)) { const WordPtr& word=map.GetValueAt(pos); output.Add(Unk_BanChange(*word,1)); }
    } else {
        const Map& oldMap=previous->GetWords(); const Map& newMap=next->GetWords();
        for(POSITION pos=oldMap.GetHeadPosition();pos;oldMap.GetNext(pos)) { const WordPtr& word=oldMap.GetValueAt(pos); const Map::CPair* found=newMap.Lookup(word->id);
            if(!found) { output.Add(Unk_BanChange(*word,2)); continue; } if(!word->FUN_140349010(*found->m_value)) { output.Add(Unk_BanChange(*word,1)); continue; }
        }
        for(POSITION pos=newMap.GetHeadPosition();pos;newMap.GetNext(pos)) { const WordPtr& word=newMap.GetValueAt(pos); const Map::CPair* found=oldMap.Lookup(word->id); if(!found) { output.Add(Unk_BanChange(*word,1)); continue; } }
    }
}
// Hook deferred: constructs persistent objects with DLL-local vftables/RTTI.
// @0x140349800
Unk_BanPtr<CBannedWordFilter> CBannedWordFilter::ApplyChanges(__int64 version,const Unk_BanPtr<CBannedWordFilter>& old,const Changes& changes) {
    Map map;
    if(old.get()) { const Map& source=old->GetWords(); for(POSITION pos=source.GetHeadPosition();pos;source.GetNext(pos)) { const WordPtr& word=source.GetValueAt(pos); map.SetAt(word->id,word); } }
    for(unsigned i=0;i<changes.GetCount();++i) { const Unk_BanChange& change=changes[i]; if(change.mode==2) map.RemoveKey(change.data.id); else if(change.mode==1) { WordPtr word(new BannedWordData(change.data),1); map.SetAt(change.data.id,word); } }
    Words values; for(POSITION pos=map.GetHeadPosition();pos;map.GetNext(pos)) { const WordPtr& value=map.GetValueAt(pos); values.Add(value); }
    Unk_BanPtr<CBannedWordFilter> result(new CBannedWordFilter(version,values)); return result;
}
// Hook deferred: constructs persistent objects with DLL-local vftables/RTTI.
// @0x140349b10
void CBannedWordFilter::FUN_140349b10(Unk_BanWriter& out) const { out.vfunc_2(static_cast<unsigned short>(words.GetCount())); for(POSITION pos=words.GetHeadPosition();pos;words.GetNext(pos)) { const WordPtr& word=words.GetValueAt(pos); word->Write(out); } }
MS2_REPLACE_METHOD(0x140349B10, CBannedWordFilter, FUN_140349b10, 171, 0x4FB31C3D);
// @0x140349bd0
void CBannedWordFilter::Read(Unk_BanReader& input) { Words values; unsigned short count=input.vfunc_2(); for(int i=0;i<count;++i) { BannedWordData word; word.Read(input); WordPtr value(new BannedWordData(word),1); values.Add(value); } FUN_140349d00(values); }
// Hook deferred: constructs persistent objects with DLL-local vftables/RTTI.
// @0x140349d00
void CBannedWordFilter::FUN_140349d00(const Words& input) {
    for(unsigned i=0;i<input.GetCount();++i) { const WordPtr& word=input[i]; words.SetAt(word->id,word); }
    filter.Clear();
    for(unsigned i=0;i<input.GetCount();++i) { const WordPtr& word=input[i]; CStringW text(word->word); CStringW replacement;
        if(word->type==1) { replacement=word->replacement; if(replacement.IsEmpty()) replacement=CStringW(L'*',word->word.GetLength()); }
        text.MakeLower(); filter.Insert(text,0,replacement);
    }
}
MS2_REPLACE_METHOD(0x140349D00, CBannedWordFilter, FUN_140349d00, 548, 0x609142CF);
// @0x140349f30
CDynamicBanWordManager::CDynamicBanWordManager() : current(0),next(0) {}
// @0x140349fb0
void CDynamicBanWordManager::SetCurrent(const Ptr& value) { if(Unk_LockGuard guard=lock) {} else { current=value; } }
MS2_REPLACE_METHOD(0x140349FB0, CDynamicBanWordManager, SetCurrent, 100, 0xF3B3E865);
// @0x14034a020
CDynamicBanWordManager::Ptr CDynamicBanWordManager::GetCurrent() { if(Unk_LockGuard guard=lock) { __assume(0); } else { return current; } }
MS2_REPLACE_METHOD(0x14034a020, CDynamicBanWordManager, GetCurrent, 136, 0xDD3192F5);
// @0x14034a0b0
void CDynamicBanWordManager::SetNext(const Ptr& value) { if(Unk_LockGuard guard=lock) {} else { next=value; } }
MS2_REPLACE_METHOD(0x14034A0B0, CDynamicBanWordManager, SetNext, 100, 0x9E82B8B1);
// @0x14034a120
CDynamicBanWordManager::Ptr CDynamicBanWordManager::GetNext() { if(Unk_LockGuard guard=lock) { __assume(0); } else { return next; } }
MS2_REPLACE_METHOD(0x14034a120, CDynamicBanWordManager, GetNext, 136, 0x81959B88);
// @0x14034a1b0
__int64 CDynamicBanWordManager::GetCurrentVersion() { Ptr value=GetCurrent(); if(value==0) return 0; return value->GetVersion(); }
MS2_REPLACE_METHOD(0x14034A1B0, CDynamicBanWordManager, GetCurrentVersion, 122, 0xE65F8EE1);
// @0x14034a230
int CDynamicBanWordManager::FilterText(const CStringW& text,CStringW& result) { Ptr value=GetCurrent(); if(value==0) return 0; return value->FilterText(text,result); }
MS2_REPLACE_METHOD(0x14034A230, CDynamicBanWordManager, FilterText, 138, 0xEA94D0C4);
// @0x14034a2c0
void CDynamicBanWordManager::Read(Unk_BanReader& input) {
    int mode=input.vfunc_1(); __int64 version=input.vfunc_4();
    switch(mode) {
    case 0: { Ptr value(0); SetCurrent(value); } break;
    case 1: { Ptr value(new CBannedWordFilter(version,input)); SetCurrent(value); } break;
    case 2: { CBannedWordFilter::Changes changes; int count=input.vfunc_2(); for(int i=0;i<count;++i) { Unk_BanChange change; change.Read(input); changes.Add(change); } Ptr old=GetCurrent(); Ptr value=CBannedWordFilter::ApplyChanges(version,old,changes); SetCurrent(value); } break;
    }
}
// Hook deferred: constructs persistent objects with DLL-local vftables/RTTI.

MS2_EMIT_CRT_MEMMOVE_S();
