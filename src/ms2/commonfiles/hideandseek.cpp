// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). HideAndSeek::Info / ObjectData and the riding object table:
// see hideandseek.h. Also holds the template glue of std::map<int, std::vector<int>> (the table).
// MS2-UNIT: ?\hideandseek.cpp
// MS2-RANGE: 0x1400b8ec0-0x1400b9090 .text$di
// MS2-RANGE: 0x14050a120-0x14050d4c0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0AEAIAEAV?$vector@HV?$allocator@H@std@@@std@@$0A@@?$pair@IV?$vector@HV?$allocator@H@std@@@std@@@std@@QEAA@AEAIAEAV?$vector@HV?$allocator@H@std@@@1@@Z 0x14050ab30 ; unique
// MS2-PIN: ??$?0V?$allocator@H@std@@$$V@?$_Compressed_pair@V?$allocator@H@std@@V?$_Vector_val@U?$_Simple_types@H@std@@@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@$$QEAV?$allocator@H@1@@Z 0x14050acc0 ; unique
// MS2-PIN: ??$?0V?$allocator@H@std@@X@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEAA@$$QEAV?$allocator@H@1@@Z 0x14050ad00 ; unique
// MS2-PIN: ??$forward@V?$allocator@H@std@@@std@@YA$$QEAV?$allocator@H@0@AEAV10@@Z 0x14050b870 ; prop
// MS2-PIN: ??0?$vector@HV?$allocator@H@std@@@std@@QEAA@$$QEAV01@@Z 0x14050ba90 ; unique
// MS2-PIN: ??0?$vector@HV?$allocator@H@std@@@std@@QEAA@AEBV01@@Z 0x14050bb10 ; unique
// MS2-PIN: ??1?$pair@$$CBIV?$vector@HV?$allocator@H@std@@@std@@@std@@QEAA@XZ 0x14050bc60 ; unique
// MS2-PIN: ??1?$pair@IV?$vector@HV?$allocator@H@std@@@std@@@std@@QEAA@XZ 0x14050bc80 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$vector@HV?$allocator@H@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$vector@HV?$allocator@H@std@@@std@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@I@2@XZ 0x14050c9c0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$vector@HV?$allocator@H@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$vector@HV?$allocator@H@std@@@std@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@I@2@XZ 0x14050c9d0 ; unique
// MS2-PIN: ?_Move_from@?$vector@HV?$allocator@H@std@@@std@@AEAAX$$QEAV12@U?$integral_constant@_N$00@2@@Z 0x14050cc80 ; unique
// MS2-PIN: ?_Swap_all@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEAAXAEAV12@@Z 0x14050ce80 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "hideandseek.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/ms2recover.h"
#include <map>
#include "hook/ms2hook.h"

// ---- unit-local views of exe objects ----

class Unk_HsFileSystem { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_HsFileSystem* FUN_140166420();
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // Table/<file>
bool FUN_14028f710(Unk_140165cf0* pElem);                              // element is enabled
int FUN_140873220(Unk_140165cf0* pElem, const char* pszName, unsigned& rOut);
const char* FUN_14086f4b0(Unk_140165cf0* pElem, const char* pszName);   // attribute text (null = absent)
void FUN_1401783d0(const CString* pText, std::vector<int>* pOut, const char* pszSep);   // split into ints
__int64 FUN_140475ff0(unsigned short nRule);                            // the rule's limit
void FUN_1402a9d70(void*, int, float, float, float, int);
void FUN_142c9aa30();                                                   // the exe's atexit destructor of the marker
struct Unk_RegMarker {};

// ---- dynamic initializers (.text$di) ----

// @0x1400b8ec0
static std::map<unsigned, std::vector<int> > s_ridingTable;

// @0x1400b8ef0
static CLockCriticalSection s_lock;

// @0x1400b8f20
static CString s_shopSort[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// @0x1400b8fe0
static CString s_skill("skill");

// @0x1400b9010
static CString s_stun("stun");

#ifndef MS2_HOOK_DLL
// @0x1400b9040
static char s_marker[0x48];
static Unk_RegMarker s_initMarker = (FUN_1402a9d70(&s_marker, 0x11, 0.75f, 0.25f, 2.25f, 10), atexit(FUN_142c9aa30), Unk_RegMarker());
#endif

// @0x14050a120
HideAndSeek::Info::Info()
{
    m_18 = false;
    m_19 = false;
    m_1a = false;
    m_20 = 0;
    m_28 = 0;
    m_2c = 0;
    m_30 = 0;
}

// @0x14050a1a0
HideAndSeek::Info::~Info()
{
    FUN_14050a1f0();
}

// @0x14050a1f0
void HideAndSeek::Info::FUN_14050a1f0()
{
    m_18 = false;
    m_19 = false;
    m_1a = false;
    m_20 = 0;
    m_28 = 0;
    m_2c = 0;
    m_30 = 0;
}

// @0x14050a250
void HideAndSeek::Info::FUN_14050a250(COutputStream& out)
{
    out.vfunc_o10_0(m_18);
    out.vfunc_o10_0(m_19);
    out.vfunc_o10_0(m_1a);
    out.vfunc_o10_4(m_20);
    out.vfunc_o10_3(m_28);
    out.vfunc_o10_1((unsigned char)m_2c);
    if (m_2c == 1)
        out.vfunc_o10_3(m_30);
}

// @0x14050a320
void HideAndSeek::Info::FUN_14050a320(CInPacket& in)
{
    m_18 = in.vfunc_o8_0();
    m_19 = in.vfunc_o8_0();
    m_1a = in.vfunc_o8_0();
    m_20 = in.vfunc_o8_4();
    m_28 = in.vfunc_o8_3();
    m_2c = in.vfunc_o8_1();
    if (m_2c == 1)
        m_30 = in.vfunc_o8_3();
}

// @0x14050a490
bool HideAndSeek::Info::FUN_14050a490() { return m_18; }

// @0x14050a4d0
bool HideAndSeek::Info::FUN_14050a4d0() { return m_19; }

// @0x14050a510
bool HideAndSeek::Info::FUN_14050a510() { return m_1a; }

// MS2-FUNCTIONAL: clamp codegen differs
// @0x14050a530
void HideAndSeek::Info::FUN_14050a530(__int64 nAdd, unsigned short nRule)
{
    __int64 nLimit = FUN_140475ff0(nRule);
    __int64 n = nAdd;
    if (nLimit < nAdd)
        n = nLimit;
    m_20 += n;
}

// MS2-FUNCTIONAL: clamp codegen differs
// @0x14050a5a0
void HideAndSeek::Info::FUN_14050a5a0(__int64 nValue, unsigned short nRule)
{
    __int64 nLimit = FUN_140475ff0(nRule);
    __int64 n = nValue;
    if (nLimit < nValue)
        n = nLimit;
    m_20 = n;
}

// @0x14050a600
__int64 HideAndSeek::Info::FUN_14050a600() { return m_20; }

// @0x14050a620
void HideAndSeek::Info::FUN_14050a620() { m_28 = m_28 + 1; }

// @0x14050a660
int HideAndSeek::Info::FUN_14050a660() { return m_28; }

// @0x14050a6a0
int HideAndSeek::Info::FUN_14050a6a0() { return m_2c; }

// @0x14050a6e0
int HideAndSeek::Info::FUN_14050a6e0() { return m_30; }

// @0x14050a700
HideAndSeek::ObjectData::ObjectData()
{
}

// @0x14050a740
HideAndSeek::ObjectData::~ObjectData()
{
}

// MS2-FUNCTIONAL: lock-guard/find sequence schedules registers differently
// @0x14050a770
void HideAndSeek::FUN_14050a770(unsigned nMapCode, std::vector<int>& out)
{
    Unk_LockGuard guard(s_lock);
    if (guard == 0)
    {
        if (s_ridingTable.empty())
            FUN_14050a830();
        std::map<unsigned, std::vector<int> >::iterator it = s_ridingTable.find(nMapCode);
        if (it != s_ridingTable.end())
            out = it->second;
    }
}

// MS2-FUNCTIONAL: XML loader; register/call-order differences in the tokenise/emplace sequence
// @0x14050a830
void HideAndSeek::FUN_14050a830()
{
    CString strPath = FUN_14071a5b0("Table/Server", "hideAndSeek.xml");
    {
        Unk_LockGuard guard(s_lock);
        if (guard == 0)
            s_ridingTable.clear();
    }
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
        return;
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("field"); pNode != 0; pNode = pNode->FUN_140168650("field"))
    {
        if (FUN_14028f710(pNode))
        {
            unsigned nMapCode = 0;
            FUN_140873220(pNode, "mapCode", nMapCode);
            std::vector<int> objects;
            CString strObjects(FUN_14086f4b0(pNode, "ridingObject"));
            FUN_1401783d0(&strObjects, &objects, ",");
            Unk_LockGuard guard(s_lock);
            if (guard == 0 && nMapCode != 0)
            {
                s_ridingTable.insert(std::pair<unsigned, std::vector<int> >(nMapCode, objects));
            }
        }
    }
}

MS2_EMIT_CRT_MEMMOVE_S();
