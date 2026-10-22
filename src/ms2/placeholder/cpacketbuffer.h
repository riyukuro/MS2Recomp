// CPacketBuffer: RTTI and commonfiles\packet.cpp layout; names inferred. A reference counted view of received or
// outgoing wire bytes: the owner (m_parent == 0) frees the block with delete[]; a slice holds its parent alive.
// The constructor, destructor and the small accessors are header-inline in the exe; they are emitted by packet.cpp.
#pragma once
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/socketptr.h"
class CPacketBuffer : public CPtred {
public:
    CPacketBuffer(int size, char* data, CPacketBuffer* parent);   // @0x1407130d0
    virtual ~CPacketBuffer();                                       // @0x1407132c0
    int GetSize() const;                                      // size, @0x140714fa0
    char* FUN_140713530();                                          // data, @0x140713530
    CPacketBuffer* FUN_140715390(unsigned offset,int size,const Unk_SocketNew&);         // slice [offset, offset+size), @0x140715390
    CPacketBuffer* FUN_140715000(int size,char* data,CPacketBuffer* parent);  // @0x140715000
    void FUN_140715360(void* value);                                // @0x140715360 (stores into the field at +0x10)
    void** FUN_140715db0();                                         // @0x140715db0 (address of the field at +0x10)
private:
    MS2_LAYOUT_FRIEND;
    int m_size;                                                     // +0x18
    char* m_data;                                                   // +0x20
    Unk_SocketPtr<CPacketBuffer> m_parent;                          // +0x28 (pad, pointer)
};
MS2_CHECK_SIZE(CPacketBuffer,0x38);
MS2_CHECK_OFFSET(CPacketBuffer,m_size,0x18);
MS2_CHECK_OFFSET(CPacketBuffer,m_data,0x20);
// The exe's AddRef/Release chain for CPacketBuffer reads the pointer field straight into the CPtred calls (the
// generic Base() helper is a real call here at /Ob0), so spell these two out.
template<> inline void Unk_SocketPtr<CPacketBuffer>::AddRefImpl(void*) const { Reference(p); }
template<> inline void Unk_SocketPtr<CPacketBuffer>::ReleaseImpl(void*)
{
    if (FUN_140159bc0(p) == 0) { Reference(p); FUN_140159ba0(p); }
}
