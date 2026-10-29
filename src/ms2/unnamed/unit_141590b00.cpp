// Nexon Messenger server-info request serialization.
// MS2-UNIT: unit_141590b00
// MS2-RANGE: 0x141590b00-0x141591200 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"
extern void FUN_14156bcb0(void*,void*,void*); extern void FUN_14156bd50(void*); extern void FUN_14156be10(void*,void*,void*); extern void FUN_14156bf10(void*);
extern void FUN_14156ac20(void*,unsigned int); extern void FUN_14156ab90(void*,unsigned short); extern void FUN_14156ae30(void*,const void*); extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*); extern int FUN_1415fb750(void*); extern int FUN_1415fb6d0(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern void FUN_1415e8880(void*); extern void FUN_1415e87b0(void*,const void*); extern void* FUN_1415f39c0(void*); extern void* FUN_1415f39f0(void*);
extern void* FUN_1415f9fa0(void*); extern unsigned int FUN_1415fa060(void*); extern void* FUN_1415fa000(void*); extern unsigned int FUN_1415fa090(void*);
extern void* FUN_1415f9ed0(void*,void*); extern void FUN_1415eb720(void*); extern void FUN_1415ef0e0(void*); extern void FUN_1415eb7b0(void*);
extern void FUN_1415eb5c0(void*); extern void FUN_1415e5a20(void*); extern void FUN_1415e5c00(void*); extern void FUN_1415fb800(void*,unsigned int); extern void FUN_1415fba10(void*,unsigned int); extern void FUN_1415fb850(void*,void*); extern void FUN_1415fb8a0(void*,unsigned short); extern void FUN_1415fba30(void*,void*); extern void FUN_14160b570(void*,void*);
// MS2-FUNCTIONAL 0x141590b00: initializes an empty server-info vector.
CNMSetServerInfoFunc::CNMSetServerInfoFunc():CNMFunc(0x801c,1,0,0),m_requests(){FUN_1415e8880(&m_requests);}
// MS2-FUNCTIONAL 0x141590b60: copies the supplied server-info vector.
CNMSetServerInfoFunc::CNMSetServerInfoFunc(const std::vector<RequestInfo>&requests):CNMFunc(0x801c,1,0,0),m_requests(){FUN_1415e87b0(&m_requests,&requests);}
// MS2-FUNCTIONAL 0x141590bd0: frames the server-info request.
unsigned int CNMSetServerInfoFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMSetServerInfoFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}
// MS2-FUNCTIONAL 0x141590c30: dispatches encoding by message format.
unsigned int CNMSetServerInfoFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMSetServerInfoFunc::Encode(pEncoder, pStream);
    return CNMSetServerInfoFunc::EncodeFramed(pStream);
}
// MS2-FUNCTIONAL 0x141590c90: writes every server-info record and its nested strings.
unsigned int CNMSetServerInfoFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(FUN_1415fb700(this)){FUN_14156ac20(e,static_cast<unsigned int>(m_requests.size()));for(const auto&r:m_requests){FUN_14156ac20(e,r.m_kind);FUN_14156ac20(e,r.m_flags);FUN_14156ae30(e,FUN_1415f39c0(const_cast<CNMStr<0x20>*>(&r.m_address.m_host)));FUN_14156ab90(e,r.m_address.m_port);FUN_14156ae30(e,FUN_1415f39f0(const_cast<CNMStr<0x800>*>(&r.m_info)));}}FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x141590ee0: decodes a framed server-info response.
unsigned int CNMSetServerInfoFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMSetServerInfoFunc::Decode(&decoder, pStream);
}
// MS2-FUNCTIONAL 0x141590f70: dispatches decoding by response format.
unsigned int CNMSetServerInfoFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMSetServerInfoFunc::DecodeFramed(pStream);
    return CNMSetServerInfoFunc::Decode(pDecoder, pStream);
}
// MS2-FUNCTIONAL 0x141590fd0: rebuilds each server-info record from the response stream.
unsigned int CNMSetServerInfoFunc::Decode(CNMSerializableDecoder*d,CNMStream*s){CNMFunc::DecodeDispatch(d,s);if(FUN_1415fb700(this)){void**v=*reinterpret_cast<void***>(d);using U=unsigned(__fastcall*)(void*);using U16=unsigned short(__fastcall*)(void*);using B=void(__fastcall*)(void*,void*,unsigned);unsigned count=reinterpret_cast<U>(v[3])(d);for(unsigned i=0;i<count;++i){RequestInfo item;item.m_kind=reinterpret_cast<U>(v[3])(d);item.m_flags=reinterpret_cast<U>(v[3])(d);reinterpret_cast<B>(v[9])(d,FUN_1415f9fa0(&item.m_address.m_host),FUN_1415fa060(&item.m_address.m_host));item.m_address.m_port=reinterpret_cast<U16>(v[2])(d);reinterpret_cast<B>(v[9])(d,FUN_1415fa000(&item.m_info),FUN_1415fa090(&item.m_info));m_requests.push_back(item);}}return static_cast<unsigned>(FUN_1415fb750(d));}
// MS2-PIN: ??0CNMSetServerInfoFunc@@QEAA@XZ 0x141590b00
// MS2-PIN: ??0CNMSetServerInfoFunc@@QEAA@AEBV?$vector@VRequestInfo@CNMSetServerInfoFunc@@V?$allocator@VRequestInfo@CNMSetServerInfoFunc@@@std@@@std@@@Z 0x141590b60
// MS2-PIN: ?EncodeFramed@CNMSetServerInfoFunc@@UEAAIPEAVCNMStream@@@Z 0x141590bd0
// MS2-PIN: ?EncodeDispatch@CNMSetServerInfoFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x141590c30
// MS2-PIN: ?Encode@CNMSetServerInfoFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x141590c90
// MS2-PIN: ?DecodeFramed@CNMSetServerInfoFunc@@UEAAIPEAVCNMStream@@@Z 0x141590ee0
// MS2-PIN: ?DecodeDispatch@CNMSetServerInfoFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x141590f70
// MS2-PIN: ?Decode@CNMSetServerInfoFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x141590fd0
