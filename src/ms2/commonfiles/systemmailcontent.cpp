// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CSystemMailContent: the system mail text table
// (systemMailContent.xml) and the id -> mail map (ATL::CAtlMap<unsigned, MS2Ptr<CSystemMailContent>>).
// MS2-UNIT: ?\systemmailcontent.cpp
// MS2-RANGE: 0x140851620-0x1408533a0 .text$mn
// MS2-RANGE: 0x1400bd250-0x1400bd2a0 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?GetNode@?$CAtlMap@IV?$MS2Ptr@VCSystemMailContent@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCSystemMailContent@@@@@3@@ATL@@AEBAPEAVCNode@12@IAEAI0AEAPEAV312@@Z 0x1408526b0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_7CSystemMailContent@@6B?$CValidData@VCSystemMailContent@@@@@ 0x142d99f38
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\systemmailcontent.cpp"    // assumed
#define MS2_SM_XML_ERR L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]"

#include "ms2/placeholder/ms2stdafx.h"
#include "systemmailcontent.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"

typedef ATL::CAtlMap<unsigned int, CSystemMailContent::Ptr> Unk_SystemMailMap;

// ---- unrecovered helpers ----

class Unk_SmLoader { public: int FUN_1403974b0(TiXmlDocument* pDoc, const char* pszPath, int a, bool b, bool c); };
Unk_SmLoader* FUN_140166420();
CString FUN_140651390();                                        // the language directory
CString FUN_140298360(const char* pszName, const CString& strDir);   // locale file name
CString FUN_14038f6d0(const CString& strA, const char* pszB);   // string concatenation
CString FUN_14071ae20(const CString& strFile);                  // Table/<file>
CString FUN_14016a5c0(const char* pszName, int nFlags);         // undecorated class name
class Unk_SmTextMgr;
Unk_SmTextMgr* FUN_1403b4750();
void FUN_1416fb380(Unk_SmTextMgr* pMgr, CStringW* pStr);        // post-process a loaded text
extern CLockCriticalSection g_cacheLock;                        // 0x143aac550
extern int DAT_1439ed00c;
unsigned char FUN_1401d1320(CCacheData* p);                     // file changed since load

#ifndef MS2_HOOK_DLL
bool CSystemMailContent::s_bInit;
#endif

// The id -> mail map. The exe constructs it in a dynamic initializer (.text$di).
static Unk_SystemMailMap s_mails(17, 0.75f, 0.25f, 2.25f, 10);

// @0x140851620
CSystemMailContent::CSystemMailContent()
{
    m_nId = 0;
}

// @0x1408516c0
CSystemMailContent::~CSystemMailContent()
{
}

// The log call with one string argument (FMT_VARIADIC wrapper over CLogString::FUN_1406530d0).
// @0x140851fc0
template <class T> inline void Unk_SmLog(CLogString* log, int level, int category, const wchar_t* format, const T& first)
{
    const fmt::internal::ArgArray<1>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(first)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(first), args));
}

// Reads the table: language file first, then the plain file; every <mail> becomes a row of the map.
void FUN_140851750();
#ifndef MS2_HOOK_DLL
// @0x140851750
// MS2-FUNCTIONAL: temp slots of the nested path-building calls sit in a different order than the exe (frame 0x10 larger).
void FUN_140851750()
{
    TiXmlDocument doc;
    CString strPath = FUN_14071ae20(FUN_14038f6d0(FUN_140298360("systemMailContent", FUN_140651390()), ".xml"));
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
    {
        strPath = FUN_14071ae20(CString("systemMailContent.xml"));
        if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
            return;
    }
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        Unk_SmLog(CLogString::GetInstance(), 1, 0x13, MS2_SM_XML_ERR, "systemMailContent.xml");
        return;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("mail"); pNode != 0; pNode = pNode->FUN_140168650("mail"))
    {
        CSystemMailContent::Ptr spMail(new CSystemMailContent);
        spMail->FUN_1401d1160(strPath);
        FUN_1408731e0(pNode, "id", spMail->m_nId);
        FUN_140873420(pNode, "sender", spMail->m_strSender);
        FUN_140873420(pNode, "subject", spMail->m_strSubject);
        FUN_140873420(pNode, "content", spMail->m_strContent);
        FUN_1416fb380(FUN_1403b4750(), &spMail->m_strSender);
        FUN_1416fb380(FUN_1403b4750(), &spMail->m_strSubject);
        FUN_1416fb380(FUN_1403b4750(), &spMail->m_strContent);
        if (Unk_LockGuard guard = g_cacheLock)
        {
        }
        else
        {
            s_mails.SetAt(spMail->m_nId, spMail);
        }
    }
    CSystemMailContent::SetInit(true);
}
#endif

// The same rows read from an element of another document.
// @0x140851c40
void FUN_140851c40(Unk_140165cf0* pRoot)
{
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("mail"); pNode != 0; pNode = pNode->FUN_140168650("mail"))
    {
        CSystemMailContent::Ptr spMail(new CSystemMailContent);
        FUN_1408731e0(pNode, "id", spMail->m_nId);
        FUN_140873420(pNode, "sender", spMail->m_strSender);
        FUN_140873420(pNode, "subject", spMail->m_strSubject);
        FUN_140873420(pNode, "content", spMail->m_strContent);
        FUN_1416fb380(FUN_1403b4750(), &spMail->m_strSender);
        FUN_1416fb380(FUN_1403b4750(), &spMail->m_strSubject);
        FUN_1416fb380(FUN_1403b4750(), &spMail->m_strContent);
        if (Unk_LockGuard guard = g_cacheLock)
        {
        }
        else
        {
            s_mails.SetAt(spMail->m_nId, spMail);
        }
    }
}

// @0x140851e50
CSystemMailContent::Ptr CSystemMailContent::GetMail(int nId)
{
    CheckInit();
    if (nId == 0)
        return CSystemMailContent::Ptr(0);
    CSystemMailContent::Ptr spMail(0);
    if (Unk_LockGuard guard = g_cacheLock)
    {
    }
    else
    {
        if (DAT_1439ed00c != 0 && s_mails.Lookup(nId, spMail) && !FUN_1401d1320(spMail.get()))
            return spMail;
    }
    FUN_140851750();
    if (Unk_LockGuard guard2 = g_cacheLock)
    {
    }
    else
    {
        s_mails.Lookup(nId, spMail);
    }
    return spMail;
}

// @0x1408523e0
void CSystemMailContent::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CSystemMailContent).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x1408532b0
void CSystemMailContent::SetInit(bool b)
{
    s_bInit = b;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9c4b0-0x142c9c4d0 .text$yd
