// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Mentor packet serialization.
// MS2-UNIT: commonfiles\mentor.cpp
// MS2-RANGE: 0x14069a0b0-0x14069bcb0 .text$mn
// MS2-PIN: ??_G?$Unk_MentorPtr@VCMentor@@@@QEAAPEAXI@Z 0x14069b360
// MS2-PIN: ?CallConstructors@?$CAtlArray@V?$Unk_MentorPtr@VCMentor@@@@V?$CElementTraits@V?$Unk_MentorPtr@VCMentor@@@@@ATL@@@ATL@@CAXPEAV?$Unk_MentorPtr@VCMentor@@@@_K@Z 0x14069b490
// MS2-PIN: ?CallDestructors@?$CAtlArray@V?$Unk_MentorPtr@VCMentor@@@@V?$CElementTraits@V?$Unk_MentorPtr@VCMentor@@@@@ATL@@@ATL@@CAXPEAV?$Unk_MentorPtr@VCMentor@@@@_K@Z 0x14069b510
// MS2-PIN: ?vfunc_1@CMentor@@UEAAXAEAVUnk_MentorReader@@@Z 0x14069b570
// MS2-PIN: ?vfunc_1@CPairMode@CMentorPairModePacket@@UEAAXAEAVUnk_MentorReader@@@Z 0x14069b5a0
// MS2-PIN: ?vfunc_0@CMentor@@UEAAXAEAVUnk_MentorWriter@@@Z 0x14069b5d0
// MS2-PIN: ?vfunc_0@CPairMode@CMentorPairModePacket@@UEAAXAEAVUnk_MentorWriter@@@Z 0x14069b600
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\mentor.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "mentor.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
// Exception RTTI name comes from the executable's throw metadata.
class Exception { public: Exception(int); private: int code; CString message; };
MS2_CHECK_SIZE(Exception,0x10);

// @0x14069a0b0
void Unk_MentorListPacket::FUN_14069a0b0(Unk_MentorReader& stream) {
    stream.FUN_14070f340(nProtocol);
    MS2_ASSERT_AT(35,nProtocol == PROTOCOL_MENTORING::MENTOR_LIST);
    unsigned int count=0; stream.FUN_14070f480(count);
    entries.SetCount(count);
    for(unsigned int i=0;i<count;++i) { entries[i]=new CMentor; stream.FUN_14070f770(*entries[i].operator->()); }
}
// Hook deferred: constructs persistent objects with DLL-local vftables/RTTI.

// @0x14069a1f0
void Unk_MentorListPacket::FUN_14069a1f0(Unk_MentorWriter& stream) {
    stream.FUN_14070f860(nProtocol);
    unsigned int count=static_cast<unsigned int>(entries.GetCount()); stream.FUN_14070f9a0(count);
    for(unsigned int i=0;i<count;++i) stream.FUN_14070fc40(*entries[i].operator->());
}
MS2_REPLACE_METHOD(0x14069A1F0, Unk_MentorListPacket, FUN_14069a1f0, 149, 0x6BD3A5D2);

// @0x14069a290
void Unk_MentorListPacket::FUN_14069a290(Unk_MentorReader& stream) {
    stream.FUN_14070f340(nProtocol);
    MS2_ASSERT_AT(64,nProtocol == PROTOCOL_MENTORING::MENTEE_LIST);
    unsigned int count=0; stream.FUN_14070f480(count);
    entries.SetCount(count);
    for(unsigned int i=0;i<count;++i) { entries[i]=new CMentor; stream.FUN_14070f770(*entries[i].operator->()); }
}
// Hook deferred: constructs persistent objects with DLL-local vftables/RTTI.

// @0x14069a3d0
void Unk_MentorResultPacket::FUN_14069a3d0(Unk_MentorWriter& stream) {
    stream.FUN_14070f860(protocol); stream.FUN_14070f860(result); stream.FUN_14070f9a0(value);
}
MS2_REPLACE_METHOD(0x14069A3D0, Unk_MentorResultPacket, FUN_14069a3d0, 74, 0x3B50DE28);

// @0x14069a420
void Unk_MentorResultPacket::FUN_14069a420(Unk_MentorReader& stream) {
    stream.FUN_14070f340(protocol); stream.FUN_14070f340(result); stream.FUN_14070f480(value);
}
MS2_REPLACE_METHOD(0x14069A420, Unk_MentorResultPacket, FUN_14069a420, 80, 0x49F91B21);

// @0x14069a480
void Unk_MentorEmptyPacket::FUN_14069a480(Unk_MentorWriter& stream) {
    stream.FUN_14070f860(protocol);
}
MS2_REPLACE_METHOD(0x14069A480, Unk_MentorEmptyPacket, FUN_14069a480, 37, 0x3774822F);

// @0x14069a4b0
void Unk_MentorEmptyPacket::FUN_14069a4b0(Unk_MentorReader& stream) {
    stream.FUN_14070f340(protocol);
}
MS2_REPLACE_METHOD(0x14069A4B0, Unk_MentorEmptyPacket, FUN_14069a4b0, 37, 0xFCD81D2E);

// @0x14069a4e0
void Unk_MentorEmptyPacket::FUN_14069a4e0(Unk_MentorWriter& stream) {
    stream.FUN_14070f860(protocol);
}
MS2_REPLACE_METHOD(0x14069A4E0, Unk_MentorEmptyPacket, FUN_14069a4e0, 37, 0xF7A9B84F);

// @0x14069a510
void Unk_MentorEmptyPacket::FUN_14069a510(Unk_MentorReader& stream) {
    stream.FUN_14070f340(protocol);
}
MS2_REPLACE_METHOD(0x14069A510, Unk_MentorEmptyPacket, FUN_14069a510, 37, 0xF615B58E);

// @0x14069a540
void Unk_MentorNamePacket::FUN_14069a540(Unk_MentorWriter& stream) {
    stream.FUN_14070f860(protocol); stream.FUN_14070f9e0(id); stream.FUN_14070fae0(name);
}
MS2_REPLACE_METHOD(0x14069A540, Unk_MentorNamePacket, FUN_14069a540, 78, 0xBE5919BF);

// @0x14069a5a0
void Unk_MentorNamePacket::FUN_14069a5a0(Unk_MentorReader& stream) {
    stream.FUN_14070f340(protocol); stream.FUN_14070f4c0(id); stream.FUN_14070f5f0(name);
    if(name.GetLength()>24) throw Exception(13);
}
MS2_REPLACE_METHOD(0x14069A5A0, Unk_MentorNamePacket, FUN_14069a5a0, 136, 0x5FC23AD5);

// @0x14069a630
void Unk_MentorIdPacket::FUN_14069a630(Unk_MentorWriter& stream) {
    stream.FUN_14070f860(protocol); stream.FUN_14070f9e0(id);
}
MS2_REPLACE_METHOD(0x14069A630, Unk_MentorIdPacket, FUN_14069a630, 56, 0xCEBC7EBA);

// @0x14069a670
void Unk_MentorIdPacket::FUN_14069a670(Unk_MentorReader& stream) {
    stream.FUN_14070f340(protocol); stream.FUN_14070f4c0(id);
}
MS2_REPLACE_METHOD(0x14069A670, Unk_MentorIdPacket, FUN_14069a670, 59, 0x7ACE07F5);

// @0x14069a6c0
void Unk_MentorIdPacket::FUN_14069a6c0(Unk_MentorWriter& stream) {
    stream.FUN_14070f860(protocol); stream.FUN_14070f9e0(id);
}
MS2_REPLACE_METHOD(0x14069A6C0, Unk_MentorIdPacket, FUN_14069a6c0, 56, 0x3B18C0CA);

// @0x14069a700
void Unk_MentorIdPacket::FUN_14069a700(Unk_MentorReader& stream) {
    stream.FUN_14070f340(protocol); stream.FUN_14070f4c0(id);
}
MS2_REPLACE_METHOD(0x14069A700, Unk_MentorIdPacket, FUN_14069a700, 59, 0x449BFB1E);

// @0x14069a750
Unk_MentorDetailPacket::Unk_MentorDetailPacket() : protocol(14), mentor(new CMentor) {}

// @0x14069a7e0
void Unk_MentorDetailPacket::FUN_14069a7e0(Unk_MentorWriter& stream) {
    stream.FUN_14070f860(protocol); stream.FUN_14070fae0(name); stream.FUN_14070fc40(*mentor.operator->());
}
MS2_REPLACE_METHOD(0x14069A7E0, Unk_MentorDetailPacket, FUN_14069a7e0, 93, 0xD146895C);

// @0x14069a850
void Unk_MentorDetailPacket::FUN_14069a850(Unk_MentorReader& stream) {
    stream.FUN_14070f340(protocol); stream.FUN_14070f5f0(name); stream.FUN_14070f770(*mentor.operator->());
}
MS2_REPLACE_METHOD(0x14069A850, Unk_MentorDetailPacket, FUN_14069a850, 93, 0x19B07424);

// @0x14069a8c0
void Unk_MentorResultPacket::FUN_14069a8c0(Unk_MentorWriter& stream) {
    stream.FUN_14070f860(protocol); stream.FUN_14070f860(result); stream.FUN_14070f9a0(value);
}
MS2_REPLACE_METHOD(0x14069A8C0, Unk_MentorResultPacket, FUN_14069a8c0, 74, 0xEA91F01B);

// @0x14069a910
void Unk_MentorResultPacket::FUN_14069a910(Unk_MentorReader& stream) {
    stream.FUN_14070f340(protocol); stream.FUN_14070f340(result); stream.FUN_14070f480(value);
}
MS2_REPLACE_METHOD(0x14069A910, Unk_MentorResultPacket, FUN_14069a910, 80, 0x7CD7389E);

// @0x14069a970
void Unk_MentorValuePacket::FUN_14069a970(Unk_MentorWriter& stream) {
    stream.FUN_14070f860(protocol); stream.FUN_14070f9a0(value); stream.FUN_14070f9e0(id);
}
MS2_REPLACE_METHOD(0x14069A970, Unk_MentorValuePacket, FUN_14069a970, 74, 0x79AB6852);

// @0x14069a9c0
void Unk_MentorValuePacket::FUN_14069a9c0(Unk_MentorReader& stream) {
    stream.FUN_14070f340(protocol); stream.FUN_14070f480(value); stream.FUN_14070f4c0(id);
}
MS2_REPLACE_METHOD(0x14069A9C0, Unk_MentorValuePacket, FUN_14069a9c0, 81, 0xEB1D80DB);

// @0x14069aa20
void Unk_MentorTwoValuePacket::FUN_14069aa20(Unk_MentorWriter& stream) {
    stream.FUN_14070f860(protocol); stream.FUN_14070f9a0(a); stream.FUN_14070f9a0(b); stream.FUN_14070f9e0(id);
}
MS2_REPLACE_METHOD(0x14069AA20, Unk_MentorTwoValuePacket, FUN_14069aa20, 92, 0x22F457F4);

// @0x14069aa90
void Unk_MentorTwoValuePacket::FUN_14069aa90(Unk_MentorReader& stream) {
    stream.FUN_14070f340(protocol); stream.FUN_14070f480(a); stream.FUN_14070f480(b); stream.FUN_14070f4c0(id);
}
MS2_REPLACE_METHOD(0x14069AA90, Unk_MentorTwoValuePacket, FUN_14069aa90, 103, 0x17914AA4);

// @0x14069ab00
void CMentorPairModePacket::FUN_14069ab00(Unk_MentorWriter& stream) {
    stream.FUN_14070f860(protocol); stream.WriteItems(entries);
}
MS2_REPLACE_METHOD(0x14069AB00, CMentorPairModePacket, FUN_14069ab00, 59, 0xDF4EADC2);

// @0x14069ab50
void CMentorPairModePacket::FUN_14069ab50(Unk_MentorReader& stream) {
    stream.FUN_14070f340(protocol); stream.ReadItems(entries);
}
// Hook deferred: constructs persistent objects with DLL-local vftables/RTTI.

// @0x14069aba0
void CMentorPairModePacket::CPairMode::FUN_14069aba0(Unk_MentorWriter& stream) {
    stream.FUN_14070f9e0(id); stream.FUN_14070f820(enabled);
}
MS2_REPLACE_METHOD(0x14069ABA0, CMentorPairModePacket::CPairMode, FUN_14069aba0, 57, 0x2F2F8D01);

// @0x14069abe0
void CMentorPairModePacket::CPairMode::FUN_14069abe0(Unk_MentorReader& stream) {
    stream.FUN_14070f4c0(id); stream.FUN_14070f300(enabled);
}
MS2_REPLACE_METHOD(0x14069ABE0, CMentorPairModePacket::CPairMode, FUN_14069abe0, 63, 0x91ADF6CC);

// @0x14069ac30
void Unk_MentorTwoIdPacket::FUN_14069ac30(Unk_MentorWriter& stream) {
    stream.FUN_14070f860(protocol); stream.FUN_14070f9e0(a); stream.FUN_14070f9e0(b);
}
MS2_REPLACE_METHOD(0x14069AC30, Unk_MentorTwoIdPacket, FUN_14069ac30, 75, 0xEFF39371);

// @0x14069ac90
void Unk_MentorTwoIdPacket::FUN_14069ac90(Unk_MentorReader& stream) {
    stream.FUN_14070f340(protocol); stream.FUN_14070f4c0(a); stream.FUN_14070f4c0(b);
}
MS2_REPLACE_METHOD(0x14069AC90, Unk_MentorTwoIdPacket, FUN_14069ac90, 81, 0xD117B05C);

// @0x14069acf0
CMentor::CMentor() : a(0),b(0),c(0),level(0),x(0),y(0),online(false) {}
// @0x14069adc0
CMentor::~CMentor() {}

// @0x14069ae30
void CMentor::FUN_14069ae30(Unk_MentorWriter& stream) {
    stream.FUN_14070f9e0(a); stream.FUN_14070f9e0(b); stream.FUN_14070f9e0(c);
    stream.FUN_14070fae0(name); stream.FUN_14070f8a0(level); stream.FUN_14070fae0(guild);
    stream.FUN_14070f9a0(x); stream.FUN_14070f820(online); stream.FUN_14070f9a0(y);
}
MS2_REPLACE_METHOD(0x14069AE30, CMentor, FUN_14069ae30, 194, 0xCE861498);

// @0x14069af00
void CMentor::FUN_14069af00(Unk_MentorReader& stream) {
    stream.FUN_14070f4c0(a); stream.FUN_14070f4c0(b); stream.FUN_14070f4c0(c);
    stream.FUN_14070f5f0(name); stream.FUN_14070f380(level); stream.FUN_14070f5f0(guild);
    stream.FUN_14070f480(x); stream.FUN_14070f300(online); stream.FUN_14070f480(y);
}
MS2_REPLACE_METHOD(0x14069AF00, CMentor, FUN_14069af00, 217, 0x42428FFF);

// The MENTOR_LIST writer, the twin of FUN_14069a1f0 (sits just before this TU's range start in the exe).
// MS2-RANGE: 0x14069a010-0x14069a0b0 .text$mn
// @0x14069a010
void Unk_MentorListPacket::FUN_14069a010(Unk_MentorWriter& stream) {
    stream.FUN_14070f860(nProtocol);
    unsigned int count=static_cast<unsigned int>(entries.GetCount()); stream.FUN_14070f9a0(count);
    for(unsigned int i=0;i<count;++i) stream.FUN_14070fc40(*entries[i].operator->());
}
MS2_REPLACE_METHOD(0x14069A010, Unk_MentorListPacket, FUN_14069a010, 149, 0xBE8887DB);
