// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Active block restrictions.
// MS2-UNIT: commonfiles\blockchecker.cpp
// MS2-RANGE: 0x1401c9a00-0x1401cbd50 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\blockchecker.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "blockchecker.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
__int64 FUN_140869440();
CStringW GetStringCommon(int);
#include "ms2/ms2format.h"
CStringW BlockFormat(int,const fmt::ArgList&);
FMT_VARIADIC_W(CStringW,BlockFormat,int)
// Custom game time has the CTime value at offset zero and a flag at offset eight.
#include "ms2/placeholder/mstime.h"
#define BLOCK_BIT_ASSERT(line,expr) (void)((!!(expr)) || (_wassert(_CRT_WIDE(#expr),L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\bitset.inl",line),0))
template<int T> class Unk_BlockBits {
public:
    class Reference {
    public:
        Reference(Unk_BlockBits* p,int pos) : owner(p),position(pos) {}
        operator bool() const { return owner->Test(position); }
    private: Unk_BlockBits* owner; int position;
    };
    Unk_BlockBits() { Fill(0); }
    Reference operator[](int pos) { BLOCK_BIT_ASSERT(152,UINT(pos) < UINT(T));return Reference(this,pos); }
    Unk_BlockBits& Set(int pos,bool value=true) {
        if(UINT(pos)>=UINT(T)) { BLOCK_BIT_ASSERT(243,0); }
        if(value) m_bits[pos/8] |= 1 << (pos%8);
        else m_bits[pos/8] &= ~(1 << (pos%8));
        return *this;
    }
    bool Test(int pos) const {
        if(UINT(pos)>=UINT(T)) { BLOCK_BIT_ASSERT(404,0);return false; }
        return (m_bits[pos/8] & (1 << (pos%8)))!=0;
    }
    void Fill(unsigned char value) { for(int i=(T+7)/8-1;i>=0;--i) m_bits[i]=value; if(value) Trim(); }
    void Trim() { if(T%8) return; m_bits[(T+7)/8-1] &= (1<<(T%8))-1; }
private: unsigned char m_bits[(T+7)/8]; // Actual packed bits; causes the original /GS cookie.
};
// @0x1401c9a00
CBlockChecker::CBlockChecker() { m_records.SetCount(11); }
// @0x1401c9a70
CBlockChecker::~CBlockChecker() {}
// @0x1401c9ab0
BlockPtr CBlockChecker::FindId(__int64 id) {
    for(int i=1;i<11;++i) {
        BlockPtr record=m_records[i];
        if(!IsExpired(record) && record->id==id) return record;
    }
    return BlockPtr(0);
}
MS2_REPLACE_METHOD(0x1401C9AB0, CBlockChecker, FindId, 270, 0x48531D67);
// @0x1401c9bd0
BlockPtr CBlockChecker::FindType(int type) {
    BlockPtr record=m_records[type];
    if(!IsExpired(record)) return record;
    return BlockPtr(0);
}
MS2_REPLACE_METHOD(0x1401C9BD0, CBlockChecker, FindType, 213, 0x7FF27F8E);
// @0x1401c9cb0
BlockPtr CBlockChecker::FindAction(int action) {
    for(int i=1;i<11;++i) { if(IsExpired(m_records[i])) continue; if(IsBlockedAction(i,action)) return m_records[i]; }
    return BlockPtr(0);
}
MS2_REPLACE_METHOD(0x1401C9CB0, CBlockChecker, FindAction, 249, 0xE3C274F0);
// @0x1401c9db0
bool CBlockChecker::GetAll(ATL::CAtlArray<BlockPtr>& out) {
    for(int i=1;i<11;++i) { BlockPtr record=m_records[i]; if(IsExpired(record)) continue; out.Add(record); }
    return !out.IsEmpty();
}
MS2_REPLACE_METHOD(0x1401C9DB0, CBlockChecker, GetAll, 230, 0x4252A0AE);
// @0x1401c9ea0
void CBlockChecker::Set(const BlockPtr& record) {
    int type=record->kind;
    if(!(type>=1 && type<=10 ? TRUE : FALSE)) { MS2_ASSERT_AT(80,FALSE);return; }
    m_records[type]=record;
}
MS2_REPLACE_METHOD(0x1401C9EA0, CBlockChecker, Set, 146, 0x7F454761);
// @0x1401c9f40
BlockPtr CBlockChecker::Remove(__int64 id) {
    for(int i=1;i<11;++i) {
        BlockPtr record=m_records[i];
        if(record.get() && record->id==id) {
            BlockPtr removed=m_records[i]; m_records[i]=0; return removed;
        }
    }
    return BlockPtr(0);
}
MS2_REPLACE_METHOD(0x1401C9F40, CBlockChecker, Remove, 313, 0x2A4BCBA8);
// @0x1401ca080
BlockPtr CBlockChecker::ExtendType(int type,int seconds) {
    BlockPtr record=FindType(type);
    if(IsExpired(record)==true) return BlockPtr(0);
    record->expiry+=seconds;return record;
}
MS2_REPLACE_METHOD(0x1401CA080, CBlockChecker, ExtendType, 265, 0x7E18DBC3);
// @0x1401ca190
BlockPtr CBlockChecker::ExtendId(__int64 id,int seconds) {
    BlockPtr record=FindId(id);
    if(IsExpired(record)==true) return BlockPtr(0);
    record->expiry+=seconds;return record;
}
MS2_REPLACE_METHOD(0x1401CA190, CBlockChecker, ExtendId, 265, 0xA36D122F);
// @0x1401ca2a0
BlockPtr CBlockChecker::SetExpiry(__int64 id,__int64 expiry) {
    BlockPtr record=FindId(id);
    if(IsExpired(record)==true) return BlockPtr(0);
    record->expiry=expiry;return record;
}
MS2_REPLACE_METHOD(0x1401CA2A0, CBlockChecker, SetExpiry, 226, 0xB71F3C1D);
// @0x1401ca390
void CBlockChecker::Clear() { for(size_t i=0;i<m_records.GetCount();++i) m_records[i]=0; }
MS2_REPLACE_METHOD(0x1401CA390, CBlockChecker, Clear, 96, 0xEBE98BC1);
// @0x1401ca400
CStringW FUN_1401ca400(const BlockPtr& record,int action) {
    int message=FUN_1401ca560(record->kind,action);
    switch(message) { case 0x432: case 0x438: {
        CMsTime time(record->expiry);
        return BlockFormat(message,time.GetYear(),time.GetMonth(),time.GetDay(),time.GetHour(),time.GetMinute(),time.GetSecond());
    }
    default: return GetStringCommon(message);
    }
}
MS2_REPLACE(0x1401CA400, FUN_1401ca400, 338, 0x2B651537);
// @0x1401ca560
int FUN_1401ca560(int type,int action) {
    switch(type) {
    case 2: return action==2 ? 0x433 : 0x432;
    case 4: return 0x432;
    case 8: return 0x452;
    }
    int message;
    switch(action) {
    case 1: message=1089;break;
    case 2: message=1090;break;
    case 3: message=1094;break;
    case 4: message=1093;break;
    case 5: message=1091;break;
    case 33: message=1092;break;
    case 7: message=1095;break;
    case 8: message=1096;break;
    case 9: message=1097;break;
    case 10: message=1098;break;
    case 11: message=1099;break;
    case 13: message=1100;break;
    case 14: message=1101;break;
    case 15: message=1102;break;
    case 16: message=1103;break;
    case 20:
    case 32:
    case 34:
    case 35:
    case 37:
    case 38:
    case 39:
    case 40:
    message=0x451;break;
    default:message=0x453;break;
    }
    return message;
}
MS2_REPLACE(0x1401CA560, FUN_1401ca560, 323, 0x2E15B3FC);
// @0x1401ca720
bool CBlockChecker::IsExpired(BlockPtr record) { return record==NULL || record->expiry<FUN_140869440(); }
MS2_REPLACE_METHOD(0x1401CA720, CBlockChecker, IsExpired, 120, 0x15368163);
// @0x1401ca7a0
bool CBlockChecker::IsBlockedAction(int type,int action) {
    Unk_BlockBits<43> bits;
    switch(type) {
    case 1:
    case 9:
        bits.Set(1);
        break;
    case 2:
        bits.Set(2);
        bits.Set(3);
        bits.Set(13);
        bits.Set(14);
        bits.Set(4);
        bits.Set(5);
        bits.Set(33);
        bits.Set(8);
        bits.Set(9);
        bits.Set(10);
        bits.Set(11);
        bits.Set(15);
        bits.Set(16);
        break;
    case 3:
        bits.Set(7);
        bits.Set(8);
        break;
    case 4:
        bits.Set(3);
        bits.Set(13);
        bits.Set(4);
        bits.Set(5);
        bits.Set(33);
        bits.Set(8);
        bits.Set(9);
        bits.Set(10);
        bits.Set(11);
        bits.Set(15);
        bits.Set(14);
        bits.Set(16);
        break;
    case 5:
        bits.Set(33);
        bits.Set(34);
        bits.Set(35);
        bits.Set(37);
        bits.Set(38);
        bits.Set(39);
        bits.Set(40);
        bits.Set(20);
        bits.Set(32);
        break;
    case 6:
        bits.Set(2);
        break;
    case 7:
        bits.Set(11);
        break;
    case 8:
        bits.Set(17);
        bits.Set(18);
        bits.Set(19);
        bits.Set(30);
        bits.Set(31);
        bits.Set(32);
        bits.Set(20);
        bits.Set(37);
        bits.Set(38);
        bits.Set(33);
        bits.Set(34);
        bits.Set(35);
        break;
    case 10:
        bits.Set(36);
        bits.Set(34);
        bits.Set(6);
        bits.Set(32);
        bits.Set(37);
        bits.Set(39);
        bits.Set(20);
        break;
    }
    return bits[action];
}
MS2_REPLACE_METHOD(0x1401CA7A0, CBlockChecker, IsBlockedAction, 1223, 0xCD503B85);
