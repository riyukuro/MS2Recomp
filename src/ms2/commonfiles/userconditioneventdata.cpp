// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CUserConditionEventData: the user condition event table
// (userConditionEvent.xml) and the id -> event map (ATL::CRBMap<int, MS2Ptr<CUserConditionEventData>>).
// MS2-UNIT: ?\userconditioneventdata.cpp
// MS2-RANGE: 0x1408d24c0-0x1408d4f60 .text$mn
// MS2-RANGE: 0x1400be110-0x1400be260 .text$di
// MS2-PIN: ??_7CUserConditionEventData@@6B?$CValidData@VCUserConditionEventData@@@@@ 0x142da3488
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\userconditioneventdata.cpp"    // assumed
#define MS2_UCE_XML_ERR L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]"

#include "ms2/placeholder/ms2stdafx.h"
#include "userconditioneventdata.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/placeholder/cconditioncommon.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"

typedef ATL::CRBMap<int, CUserConditionEventData::Ptr> Unk_UceMap;

// ---- unrecovered helpers ----

class Unk_UceLoader { public: int FUN_1403974b0(TiXmlDocument* pDoc, const char* pszPath, int a, bool b, bool c); };
Unk_UceLoader* FUN_140166420();
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);       // Table/<file>
CString FUN_14016a5c0(const char* pszName, int nFlags);         // undecorated class name
class Unk_UceChecker { public: int FUN_1405f5e90(int nCode, int nRank, CString strTag, CString strInfo); };   // the item exists
Unk_UceChecker* FUN_140166430();
int FUN_14029ea20(CConditionCommonData* pData, Unk_140165cf0* pNode, CStringW strTag, unsigned nId);   // reads a <condition>
extern CLockCriticalSection g_cacheLock;                        // 0x143aac550
extern int DAT_1439ed00c;
unsigned char FUN_1401d1320(CCacheData* p);                     // file changed since load
int FUN_14015f500(Unk_140165cf0*, const char*, int*);           // itemRank

#ifndef MS2_HOOK_DLL
bool CUserConditionEventData::s_bInit;
#endif

// The id -> event map. The exe constructs it in a dynamic initializer (.text$di), then the shared name tables.
static Unk_UceMap s_events(10);
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";

// The log call with one string argument (FMT_VARIADIC wrapper over CLogString::FUN_1406530d0).
// @0x1408d3210
template <class T> inline void Unk_UceLog(CLogString* log, int level, int category, const wchar_t* format, const T& first)
{
    const fmt::internal::ArgArray<1>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(first)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(first), args));
}

// @0x1408d3470
Unk_UceAttachment::Unk_UceAttachment()
    : m_nJob(0), m_nItemId(0), m_nItemRank(1), m_nItemCount(0), m_pad_10(0)
{
}

// @0x1408d3550
Unk_UceMail::Unk_UceMail()
    : m_nUseMail(0), m_nContext(0), m_nMeso(0), m_nMerat(0)
{
}

// @0x1408d35b0
Unk_UceNotify::Unk_UceNotify()
    : m_nUseNotify(0), m_nPreview(0)
{
}

// @0x1408d24c0
CUserConditionEventData::CUserConditionEventData()
    : m_spCondition(new CConditionCommonData)
{
    m_nId = 0;
    m_nGameEventId = 0;
}

// @0x1408d25b0
CUserConditionEventData::~CUserConditionEventData()
{
}

// Reads the table; every <event> becomes a row of the map.
#ifndef MS2_HOOK_DLL
// @0x1408d2640
// MS2-FUNCTIONAL: written from the decompile; temporaries / frame slots not tuned
bool CUserConditionEventData::Load()
{
    TiXmlDocument doc;
    CString strPath = FUN_14071a5b0(CString("Table"), CString("userConditionEvent.xml"));
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        Unk_UceLog(CLogString::GetInstance(), 1, 0x13, MS2_UCE_XML_ERR, "userConditionEvent.xml");
        return false;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("event"); pNode != 0; pNode = pNode->FUN_140168650("event"))
    {
        Ptr spData(new CUserConditionEventData);
        spData->FUN_1401d1160(CString(strPath));
        FUN_1408731e0(pNode, "id", spData->m_nId);
        FUN_1408731e0(pNode, "gameEventID", spData->m_nGameEventId);
        CString strInfo;
        strInfo.Format("eventID=%u gameEventID=%u", (unsigned)spData->m_nId, (unsigned)spData->m_nGameEventId);
        Unk_140165cf0* pCondition = pNode->FUN_140165cf0("condition");
        if (pCondition != 0)
        {
            if (FUN_14029ea20(spData->m_spCondition.get(), pCondition, CStringW(L"UserConditionEvent"), spData->m_nId) == 0)
                continue;
        }
        Unk_140165cf0* pNotify = pNode->FUN_140165cf0("notify");
        if (pNotify != 0)
        {
            FUN_1408731e0(pNotify, "preview", spData->m_notify.m_nPreview);
            FUN_1408731e0(pNotify, "useNotify", spData->m_notify.m_nUseNotify);
            spData->m_notify.m_strDescKey = FUN_14015f710(pNotify, "descKey", CString(""));
            spData->m_notify.m_strDescArg = FUN_14015f710(pNotify, "descArg", CString(""));
            for (Unk_140165cf0* pAttach = pNotify->FUN_140165cf0("attachment"); pAttach != 0; pAttach = pAttach->FUN_140168650("attachment"))
            {
                Unk_UceAttachment attach;
                FUN_1408731e0(pAttach, "job", attach.m_nJob);
                FUN_140873220(pAttach, "itemID", attach.m_nItemId);
                FUN_14015f500(pAttach, "itemRank", &attach.m_nItemRank);
                FUN_140873220(pAttach, "itemCount", attach.m_nItemCount);
                if (FUN_140166430()->FUN_1405f5e90(attach.m_nItemId, attach.m_nItemRank, CString("systemMail.xml"), CString(strInfo)) != 0)
                    spData->m_notify.m_attachments.Add(attach);
            }
        }
        Unk_140165cf0* pMail = pNode->FUN_140165cf0("mail");
        if (pMail != 0)
        {
            FUN_1408731e0(pMail, "context", spData->m_mail.m_nContext);
            FUN_1408731e0(pMail, "useMail", spData->m_mail.m_nUseMail);
            FUN_1408732e0(pMail, "meso", spData->m_mail.m_nMeso);
            FUN_1408732e0(pMail, "merat", spData->m_mail.m_nMerat);
            for (Unk_140165cf0* pAttach = pMail->FUN_140165cf0("attachment"); pAttach != 0; pAttach = pAttach->FUN_140168650("attachment"))
            {
                Unk_UceAttachment attach;
                FUN_1408731e0(pAttach, "job", attach.m_nJob);
                FUN_140873220(pAttach, "itemID", attach.m_nItemId);
                FUN_14015f500(pAttach, "itemRank", &attach.m_nItemRank);
                FUN_140873220(pAttach, "itemCount", attach.m_nItemCount);
                if (FUN_140166430()->FUN_1405f5e90(attach.m_nItemId, attach.m_nItemRank, CString("systemMail.xml"), CString(strInfo)) != 0)
                    spData->m_mail.m_attachments.Add(attach);
            }
        }
        if (Unk_LockGuard guard = g_cacheLock)
        {
        }
        else
        {
            s_events.SetAt(spData->m_nId, spData);
        }
    }
    SetInit(true);
    return true;
}
#endif

// @0x1408d2fc0
void CUserConditionEventData::GetAllEvents(ATL::CAtlArray<Ptr>& out)
{
    CheckInit();
    if (Unk_LockGuard guard = g_cacheLock)
    {
    }
    else
    {
        POSITION pos = s_events.GetHeadPosition();
        while (pos != 0)
        {
            Ptr spData = GetEvent(s_events.GetKeyAt(pos));
            out.Add(spData);
            s_events.GetNext(pos);
        }
    }
}

#ifndef MS2_HOOK_DLL
// @0x1408d3090
// MS2-FUNCTIONAL: the exe returns the local smart pointer by a steal (no AddRef/Release pair); MS2Ptr has no move ctor
CUserConditionEventData::Ptr CUserConditionEventData::GetEvent(int nId)
{
    CheckInit();
    if (nId == 0)
        return Ptr(0);
    Ptr spData(0);
    if (Unk_LockGuard guard = g_cacheLock)
    {
    }
    else
    {
        if (DAT_1439ed00c != 0 && s_events.Lookup(nId, spData) && !FUN_1401d1320(spData.get()))
            return spData;
        s_events.RemoveAll();
        Load();
        if (Unk_LockGuard guard2 = g_cacheLock)
        {
        }
        else
        {
            s_events.Lookup(nId, spData);
        }
    }
    return spData;
}
#endif

// @0x1408d3a70
void CUserConditionEventData::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CUserConditionEventData).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x1408d4d30
void CUserConditionEventData::SetInit(bool b)
{
    s_bInit = b;
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9ca40-0x142c9cad0 .text$yd
