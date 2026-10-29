// Nexon Messenger download-guild-mark request serialization.
// MS2-UNIT: unit_141592580
// MS2-RANGE: 0x141592580-0x1415929a0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"
extern void FUN_14156bcb0(void*,void*,void*); extern void FUN_14156bd50(void*); extern void FUN_14156be10(void*,void*,void*); extern void FUN_14156bf10(void*);
extern void FUN_14156ac20(void*,unsigned int); extern void FUN_14156acb0(void*,unsigned __int64); extern void FUN_14156ae30(void*,const void*); extern void FUN_1415fbe70(void*,unsigned int,const void*); extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*); extern int FUN_1415fb750(void*); extern int FUN_1415fb6d0(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
// MS2-FUNCTIONAL 0x141592580: initializes an empty guild-mark download request.
CNMDownloadGuildMarkFileFunc::CNMDownloadGuildMarkFileFunc():CNMFunc(0x801d,1,0,0),m_nGameCode(0),m_n34(0),m_nGuildKey(0),m_szPath{}{}
// MS2-FUNCTIONAL 0x141592600: stores game, guild, and bounded path values.
CNMDownloadGuildMarkFileFunc::CNMDownloadGuildMarkFileFunc(int game,unsigned __int64 guild,const char*path):CNMFunc(0x801d,1,0,0),m_nGameCode(game),m_n34(0),m_nGuildKey(guild),m_szPath{}{if(path)FUN_1415fbe70(m_szPath,0x100,path);}
// MS2-FUNCTIONAL 0x1415926b0: frames the guild-mark request.
unsigned int CNMDownloadGuildMarkFileFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMDownloadGuildMarkFileFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}
// MS2-FUNCTIONAL 0x141592710: dispatches encoding by message format.
unsigned int CNMDownloadGuildMarkFileFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMDownloadGuildMarkFileFunc::Encode(pEncoder, pStream);
    return CNMDownloadGuildMarkFileFunc::EncodeFramed(pStream);
}
// MS2-FUNCTIONAL 0x141592770: encodes game, guild, and path values.
unsigned int CNMDownloadGuildMarkFileFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(FUN_1415fb700(this)){FUN_14156ac20(e,static_cast<unsigned int>(m_nGameCode));FUN_14156acb0(e,m_nGuildKey);FUN_14156ae30(e,m_szPath);}FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x141592800: decodes a framed guild-mark response.
unsigned int CNMDownloadGuildMarkFileFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMDownloadGuildMarkFileFunc::Decode(&decoder, pStream);
}
// MS2-FUNCTIONAL 0x141592890: dispatches decoding by response format.
unsigned int CNMDownloadGuildMarkFileFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMDownloadGuildMarkFileFunc::DecodeFramed(pStream);
    return CNMDownloadGuildMarkFileFunc::Decode(pDecoder, pStream);
}
// MS2-FUNCTIONAL 0x1415928f0: restores game, guild, and path values from the reply.
unsigned int CNMDownloadGuildMarkFileFunc::Decode(CNMSerializableDecoder*d,CNMStream*s){CNMFunc::DecodeDispatch(d,s);if(FUN_1415fb700(this)){void**v=*reinterpret_cast<void***>(d);using U=unsigned(__fastcall*)(void*);using U64=unsigned __int64(__fastcall*)(void*);using B=void(__fastcall*)(void*,void*,unsigned);m_nGameCode=static_cast<int>(reinterpret_cast<U>(v[3])(d));m_nGuildKey=reinterpret_cast<U64>(v[4])(d);reinterpret_cast<B>(v[9])(d,m_szPath,0x100);}return static_cast<unsigned>(FUN_1415fb750(d));}
// MS2-PIN: ??0CNMDownloadGuildMarkFileFunc@@QEAA@XZ 0x141592580
// MS2-PIN: ??0CNMDownloadGuildMarkFileFunc@@QEAA@H_KPEBD@Z 0x141592600
// MS2-PIN: ?EncodeFramed@CNMDownloadGuildMarkFileFunc@@UEAAIPEAVCNMStream@@@Z 0x1415926b0
// MS2-PIN: ?EncodeDispatch@CNMDownloadGuildMarkFileFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x141592710
// MS2-PIN: ?Encode@CNMDownloadGuildMarkFileFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x141592770
// MS2-PIN: ?DecodeFramed@CNMDownloadGuildMarkFileFunc@@UEAAIPEAVCNMStream@@@Z 0x141592800
// MS2-PIN: ?DecodeDispatch@CNMDownloadGuildMarkFileFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x141592890
// MS2-PIN: ?Decode@CNMDownloadGuildMarkFileFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x1415928f0
