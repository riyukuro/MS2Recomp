// CInPacket: wire input buffer (RTTI .?AVCInPacket@@, CIOBuffer at +0, CInputStream at +8); layout from
// commonfiles\packet.cpp (which owns this header) and gamesocket's inline constructor. Field names inferred except
// m_nState / RS_* (assert text). One receive buffer is filled by FUN_14070ff00 in two phases (header, data).
#pragma once
#include <afx.h>
#include "ms2/commonfiles/stream.h"
#include "ms2/placeholder/socketptr.h"
class CPacketBuffer;
class CInPacket : public CIOBuffer, public CInputStream {
public:
    enum { RS_HEADER = 0, RS_DATA = 1, RS_COMPLETED = 2 };
    inline explicit CInPacket(int flags=0);
    CInPacket(CInPacket& iPacket);                                 // 0x14070fd00: takes over a completed packet
    inline ~CInPacket();
    unsigned vfunc_0() override;
    short vfunc_1() override;

    bool vfunc_o8_0() override;
    unsigned char vfunc_o8_1() override;
    short vfunc_o8_2() override;
    int vfunc_o8_3() override;
    __int64 vfunc_o8_4() override;
    float vfunc_o8_5() override;
    CString vfunc_o8_6() override;
    CString vfunc_o8_7() override;
    CStringW vfunc_o8_8() override;
    void vfunc_o8_9(void* data,int count) override;
    Unk_StreamPoint vfunc_o8_10() override;
    Unk_StreamPoint vfunc_o8_11() override;
    float vfunc_o8_12() override;
    float vfunc_o8_13() override;
    float vfunc_o8_14(int scale) override;
    float vfunc_o8_15() override;
    float vfunc_o8_16(int scale) override;

    // Feeds the packet from `buffer` (header first, then payload); returns the new m_nState. If bytes are left over
    // `buffer` is replaced by a slice of them (or cleared). `stateBefore` receives the state on entry.
    int FUN_14070ff00(Unk_SocketPtr<CPacketBuffer>* buffer,int* stateBefore,int hasSequence);
    void FUN_140710280(int connectionState,unsigned* key);       // decrypts the payload in place
    int FUN_14070fe80();                                           // opcode: seeks to 6 and reads a short
    void FUN_140713940();                                          // reset (state 0, length 0, offset 0)
    void FUN_140715120(const char* data,unsigned count);           // appends bytes to the payload
    void FUN_140715280(unsigned offset);                           // SetOffset (throws past the end)
    CString FUN_140710300() const;                                 // hex dump "%02x " of the buffer, @0x140710300
    short FUN_1407140a0();                                         // Decode2 through the secondary vtable
    Unk_StreamPoint FUN_1407140d0();                               // three int reads -> point
    unsigned FUN_141269940(unsigned key) { return m_opcode ^ (unsigned short)((key >> 16) & 0xffff); }
    void FUN_14126c7b0(int n) { m_sequence=n; }
    int m_flags,m_nState;
    ATL::CAtlArray<unsigned char> m_data;
    unsigned m_length; unsigned short m_opcode;
    int m_40,m_packetLength; unsigned m_offset; int m_sequence;
};
MS2_CHECK_SIZE(CInPacket,0x50);
MS2_CHECK_OFFSET(CInPacket,m_data,0x18);
MS2_CHECK_OFFSET(CInPacket,m_opcode,0x3c);
// Definitions of Unk_SocketRef<CInPacket> (declared in socketptr.h, needs the complete CInPacket).
inline CPtred* Unk_SocketRef<CInPacket>::Base(CInPacket* p) { CPtred* result; if(p==NULL) result=NULL; else result=reinterpret_cast<TPtredDummy<CInPacket>*>(reinterpret_cast<char*>(p)-0x18); return result; }
inline TPtredDummy<CInPacket>* Unk_SocketRef<CInPacket>::New(void*) { return new TPtredDummy<CInPacket>(); }
inline CInPacket* Unk_SocketRef<CInPacket>::Value(TPtredDummy<CInPacket>* p) { CInPacket* result; if(p==NULL) result=NULL; else result=&p->value; return result; }
inline CInPacket* Unk_SocketRef<CInPacket>::Create(void*) { return Value(static_cast<TPtredDummy<CInPacket>*>(FUN_1401ba820(New(NULL)))); }
