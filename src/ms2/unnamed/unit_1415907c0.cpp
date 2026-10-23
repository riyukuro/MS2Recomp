// Nexon Messenger log-report synchronization request.
// MS2-UNIT: unit_1415907c0
// MS2-RANGE: 0x1415907c0-0x141590b00 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/ms2recover.h"
extern void FUN_14156bcb0(void*,void*,void*); extern void FUN_14156bd50(void*); extern void FUN_14156be10(void*,void*,void*); extern void FUN_14156bf10(void*);
extern void FUN_14156ab90(void*,unsigned short); extern void FUN_1415f9990(void*); extern int FUN_1415fb700(void*); extern int FUN_1415fb750(void*); extern int FUN_1415fb6d0(void*);
// MS2-FUNCTIONAL 0x1415907c0: initializes the sync code to zero.
CNMLogReportSyncFunc::CNMLogReportSyncFunc():CNMFunc(0x801a,1,0,0),m_30(0),m_32{}{}
// MS2-FUNCTIONAL 0x141590810: stores the supplied sync code.
CNMLogReportSyncFunc::CNMLogReportSyncFunc(short code):CNMFunc(0x801a,1,0,0),m_30(code),m_32{}{}
// MS2-FUNCTIONAL 0x141590870: frames the log-sync request.
unsigned int CNMLogReportSyncFunc::EncodeFramed(CNMStream*s){unsigned char b[0x18];FUN_14156bcb0(b,s,this);void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMLogReportSyncFunc*,CNMEncoder*,CNMStream*);auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s);FUN_14156bd50(b);return r;}
// MS2-FUNCTIONAL 0x1415908d0: dispatches encoding by message format.
unsigned int CNMLogReportSyncFunc::EncodeDispatch(CNMEncoder*e,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(m_bFormat==1){using F=unsigned int(__fastcall*)(CNMLogReportSyncFunc*,CNMEncoder*,CNMStream*);return reinterpret_cast<F>(v[2])(this,e,s);}using F=unsigned int(__fastcall*)(CNMLogReportSyncFunc*,CNMStream*);return reinterpret_cast<F>(v[3])(this,s);}
// MS2-FUNCTIONAL 0x141590930: serializes the synchronization code.
unsigned int CNMLogReportSyncFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(FUN_1415fb700(this))FUN_14156ab90(e,static_cast<unsigned short>(m_30));FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x1415909a0: decodes a framed sync response.
unsigned int CNMLogReportSyncFunc::DecodeFramed(CNMStream*s){unsigned char b[0x38];FUN_14156be10(b,s,this);unsigned r=0;if(FUN_1415fb750(b)){void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMLogReportSyncFunc*,CNMSerializableDecoder*,CNMStream*);r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s);}FUN_14156bf10(b);return r;}
// MS2-FUNCTIONAL 0x141590a30: dispatches decoding by response format.
unsigned int CNMLogReportSyncFunc::DecodeDispatch(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(FUN_1415fb6d0(d)==2){using F=unsigned int(__fastcall*)(CNMLogReportSyncFunc*,CNMStream*);return reinterpret_cast<F>(v[6])(this,s);}using F=unsigned int(__fastcall*)(CNMLogReportSyncFunc*,CNMSerializableDecoder*,CNMStream*);return reinterpret_cast<F>(v[5])(this,d,s);}
// MS2-FUNCTIONAL 0x141590a90: restores the response synchronization code.
unsigned int CNMLogReportSyncFunc::Decode(CNMSerializableDecoder*d,CNMStream*s){CNMFunc::DecodeDispatch(d,s);if(FUN_1415fb700(this)){void**v=*reinterpret_cast<void***>(d);using U16=unsigned short(__fastcall*)(void*);m_30=static_cast<short>(reinterpret_cast<U16>(v[2])(d));}return static_cast<unsigned>(FUN_1415fb750(d));}
// MS2-PIN: ??0CNMLogReportSyncFunc@@QEAA@XZ 0x1415907c0
// MS2-PIN: ??0CNMLogReportSyncFunc@@QEAA@F@Z 0x141590810
// MS2-PIN: ?EncodeFramed@CNMLogReportSyncFunc@@UEAAIPEAVCNMStream@@@Z 0x141590870
// MS2-PIN: ?EncodeDispatch@CNMLogReportSyncFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x1415908d0
// MS2-PIN: ?Encode@CNMLogReportSyncFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x141590930
// MS2-PIN: ?DecodeFramed@CNMLogReportSyncFunc@@UEAAIPEAVCNMStream@@@Z 0x1415909a0
// MS2-PIN: ?DecodeDispatch@CNMLogReportSyncFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x141590a30
// MS2-PIN: ?Decode@CNMLogReportSyncFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x141590a90
