// Nexon Messenger execute-NGM-installer request serialization.
// MS2-UNIT: unit_14158f620
// MS2-RANGE: 0x14158f620-0x14158fca0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"
extern void FUN_14156bcb0(void*,void*,void*); extern void FUN_14156bd50(void*); extern void FUN_14156be10(void*,void*,void*); extern void FUN_14156bf10(void*);
extern void FUN_14156ae30(void*,const void*); extern void FUN_14156ac20(void*,unsigned int); extern void FUN_1415fbe70(void*,unsigned int,const void*); extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*); extern int FUN_1415fb750(void*); extern int FUN_1415fb6d0(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
// MS2-FUNCTIONAL 0x14158f620: initializes the installer request and its default enable flag.
CNMExecuteNGMInstallerFunc::CNMExecuteNGMInstallerFunc()
 : CNMFunc(0x8020,1,0,0)
{
    m_nGameCode = 0;
    m_n34 = 1;
    m_n38 = 0;
    m_sz3c[0] = 0;
    m_sz43c[0] = 0;
    m_sz83c[0] = 0;
    m_sz85c[0] = 0;
    m_n8dc = 0;
}
// MS2-FUNCTIONAL 0x14158f6f0: copies installer paths and stores request settings.
CNMExecuteNGMInstallerFunc::CNMExecuteNGMInstallerFunc(int gameCode,int n2,int n3,const char* sz4,const char* sz5,const char* sz6,const char* sz7,int n8)
 : CNMFunc(0x8020,1,0,0)
{
    m_nGameCode = gameCode;
    m_n34 = n2;
    m_n38 = n3;
    if (sz4) FUN_1415fbe70(m_sz3c, 0x400, sz4); else m_sz3c[0] = 0;
    if (sz5) FUN_1415fbe70(m_sz43c, 0x400, sz5); else m_sz43c[0] = 0;
    if (sz6) FUN_1415fbe70(m_sz83c, 0x20, sz6); else m_sz83c[0] = 0;
    if (sz7) FUN_1415fbe70(m_sz85c, 0x80, sz7); else m_sz85c[0] = 0;
    m_n8dc = n8;
}
// MS2-FUNCTIONAL 0x14158f880: frames the installer request.
unsigned int CNMExecuteNGMInstallerFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMExecuteNGMInstallerFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}
// MS2-FUNCTIONAL 0x14158f8e0: dispatches encoding by message format.
unsigned int CNMExecuteNGMInstallerFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMExecuteNGMInstallerFunc::Encode(pEncoder, pStream);
    return CNMExecuteNGMInstallerFunc::EncodeFramed(pStream);
}
// MS2-FUNCTIONAL 0x14158f940: encodes installer identifiers, paths, and options.
unsigned int CNMExecuteNGMInstallerFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(FUN_1415fb700(this)){FUN_14156ac20(e,m_nGameCode);FUN_14156ac20(e,m_n34);FUN_14156ac20(e,m_n38);FUN_14156ae30(e,m_sz3c);FUN_14156ae30(e,m_sz43c);FUN_14156ae30(e,m_sz83c);FUN_14156ae30(e,m_sz85c);FUN_14156ac20(e,m_n8dc);}FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x14158fa40: decodes a framed installer response.
unsigned int CNMExecuteNGMInstallerFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMExecuteNGMInstallerFunc::Decode(&decoder, pStream);
}
// MS2-FUNCTIONAL 0x14158fad0: dispatches decoding by response format.
unsigned int CNMExecuteNGMInstallerFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMExecuteNGMInstallerFunc::DecodeFramed(pStream);
    return CNMExecuteNGMInstallerFunc::Decode(pDecoder, pStream);
}
// MS2-FUNCTIONAL 0x14158fb30: restores installer identifiers, paths, and settings.
unsigned int CNMExecuteNGMInstallerFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this)) {
        m_nGameCode = pDecoder->ReadU32();
        m_n34 = pDecoder->ReadU32();
        m_n38 = pDecoder->ReadU32();
        pDecoder->ReadStringBufAlias(m_sz3c, 0x400);
        pDecoder->ReadStringBufAlias(m_sz43c, 0x400);
        pDecoder->ReadStringBufAlias(m_sz83c, 0x20);
        pDecoder->ReadStringBufAlias(m_sz85c, 0x80);
        m_n8dc = pDecoder->ReadU32();
    }
    return static_cast<unsigned>(FUN_1415fb750(pDecoder));
}
// MS2-PIN: ??0CNMExecuteNGMInstallerFunc@@QEAA@XZ 0x14158f620
// MS2-PIN: ??0CNMExecuteNGMInstallerFunc@@QEAA@HHHPEBD000H@Z 0x14158f6f0
// MS2-PIN: ?EncodeFramed@CNMExecuteNGMInstallerFunc@@UEAAIPEAVCNMStream@@@Z 0x14158f880
// MS2-PIN: ?EncodeDispatch@CNMExecuteNGMInstallerFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x14158f8e0
// MS2-PIN: ?Encode@CNMExecuteNGMInstallerFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x14158f940
// MS2-PIN: ?DecodeFramed@CNMExecuteNGMInstallerFunc@@UEAAIPEAVCNMStream@@@Z 0x14158fa40
// MS2-PIN: ?DecodeDispatch@CNMExecuteNGMInstallerFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x14158fad0
// MS2-PIN: ?Decode@CNMExecuteNGMInstallerFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x14158fb30
