// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). client\ms2\string\stringidinterface.cpp: the client side of
// StringIdInterface (a string id + arguments sent by the server, formatted through the string tables), the
// StringXmlProc<PVPStringId> table loader, and the UGC download-cache host/folder settings.
// MS2-UNIT: client\ms2\string\stringidinterface.cpp
// MS2-RANGE: 0x141024dc0-0x141026ab0 .text$mn
// MS2-RANGE: 0x1400e4300-0x1400e4330 .text$di
// MS2-PIN: ?CompareElementsOrdered@?$CDefaultCompareTraits@W4PVPStringId@@@ATL@@SAHAEBW4PVPStringId@@0@Z 0x1410255b0
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\string\\stringidinterface.cpp"
#ifndef _HAS_AUTO_PTR_ETC
#define _HAS_AUTO_PTR_ETC 1
#endif
#include "ms2/placeholder/ms2stdafx.h"
extern "C" _ACRTIMP void __cdecl _wassert(wchar_t const* _Message, wchar_t const* _File, unsigned _Line);

#include <atlcoll.h>
#include <memory>

#include "ms2/placeholder/stringidinterface.h"
#include "ms2/placeholder/stringmanager.h"
#include "ms2/placeholder/stringxmlproc.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unrecovered helpers -----------------------------------------------------------------------------------------

// Packet reader of StringIdInterfaceBase (kind/id/arguments or the plain text).
void FUN_14084f390(StringIdInterfaceBase* pThis, CInPacket& packet);
CStringW FUN_14028b8e0(const CStringW& strKey);                         // string table text of a key
size_t FUN_14015a000(ATL::CAtlArray<CStringW>& arr);                    // GetCount
CStringW& FUN_14025e580(ATL::CAtlArray<CStringW>& arr, size_t i);       // operator[]

// Builds the text of a "{0} {1}" format with arguments.
class Unk_StringArgFormatter
{
public:
    // @0x1410254e0
    Unk_StringArgFormatter(const CStringW& strFormat) : m_strFormat(strFormat), m_nCount(0), m_nPad(0) {}
    // @0x141025530
    ~Unk_StringArgFormatter() {}
    void FUN_140840530(CStringW strArg);                                // appends one argument
    CStringW FUN_1408405d0();                                           // the formatted text
private:
    CStringW m_strFormat;                                               // +0x00
    int m_nCount;                                                       // +0x08
    int m_nPad;                                                         // +0x0c
};
MS2_CHECK_SIZE(Unk_StringArgFormatter, 0x10);

class Unk_ChatTextFilter
{
public:
    void FUN_1416fb300(CStringW& str);
};
Unk_ChatTextFilter* FUN_1403b4750();

CLogString* FUN_140166440();
void FUN_14015eb90(CLogString* log, int level, int category, const wchar_t* format, const CString& arg);
class Unk_XmlFiles { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_XmlFiles* FUN_140166420();
CString FUN_14071ae20(const CString& strFile);                          // path below the Table folder
CStringW FUN_14016a730(const char* psz, int nCodePage);                 // widens a narrow string
bool FUN_140184310(const CString& str, const char* psz);                // string == literal
CStringW FUN_1401bf530(Unk_140165cf0* pElem, const char* pszAttr, CStringW strDefault);   // wide attribute
extern StringManager* DAT_143ab1c98;                                    // the manager singleton

// The download cache root (set by FUN_1410268a0) and the "use the simple cache layout" switch.
extern CString DAT_143accfc0;
extern int DAT_1439f6efc;

// ---- StringIdInterface -----------------------------------------------------------------------------------------

// @0x141024dc0
StringIdInterface::StringIdInterface(const StringIdInterfaceBase& base) : StringIdInterfaceBase(base)
{
}

// @0x141025b70
StringManager* FUN_141025b70()
{
    return DAT_143ab1c98;
}

// @0x141025220
void FUN_141025220(CInPacket& packet, StringIdInterface* pThis)
{
    FUN_14084f390(pThis, packet);
}

// @0x141024e00
StringIdInterface::StringIdInterface(CInPacket& packet)
{
    FUN_141025220(packet, this);
}

// @0x141024e60
// MS2-FUNCTIONAL: exe frame is 0x10 larger (an unused 8-byte slot below the format string), no source form found
CStringW StringIdInterface::FUN_141024e60()
{
    if (formatted)
    {
        CStringW strFormat;
        switch (kind)
        {
        case 1:
            strFormat = FUN_141025b70()->FUN_14084f9c0(StringXmlCategory(1), id);
            break;
        case 2:
            return CStringW(L"");
        case 3:
            strFormat = FUN_141025b70()->GetText(StringXmlCategory(3), PVPStringId(id));
            break;
        default:
            MS2_ASSERT_AT(0x25, 0);
        }
        Unk_StringArgFormatter formatter(strFormat);
        for (size_t i = 0; i < FUN_14015a000(arguments); i++)
            formatter.FUN_140840530(FUN_14025e580(arguments, i));
        CStringW strBuilt = formatter.FUN_1408405d0();
        CStringW strResult = strBuilt;
        FUN_1403b4750()->FUN_1416fb300(strResult);
        return strResult;
    }
    if (kind == 0)
        return CStringW(text);
    else if (kind == 5)
        return FUN_14028b8e0(text);
    else
        return CStringW(L"");
}

// @0x141025250
template <class T> CStringW StringManager::GetText(StringXmlCategory category, T id)
{
    ATL::CRBMap<StringXmlCategory, MS2Ptr<StringXmlProcBase> >::CPair* pPair = m_tables.Lookup(category);
    if (pPair == 0)
        return CStringW(L"");
    StringXmlProc<T>* pProc = dynamic_cast<StringXmlProc<T>*>(pPair->m_value.get());
    if (pProc == 0)
        return CStringW(L"");
    return pProc->GetText(id);
}

// @0x141025350
// @0x1410255f0
template <class T> typename StringXmlProc<T>::ValueMap* StringXmlProc<T>::LoadData()
{
    Unk_140165cf0* pRoot = 0;
    ValueMap* pMap;
    TiXmlDocument doc;
    do
    {
        if (m_path18.IsEmpty())
            break;
        CString strPath = FUN_14071ae20(m_path18);
        if (strPath.IsEmpty())
            break;
        if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
            break;
        pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    } while (0);
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", m_path18);
        return 0;
    }
    pMap = new ValueMap(10);
    std::auto_ptr<KeyMap> names = m_factory30();
    for (Unk_140165cf0* pElem = pRoot->FUN_140165cf0("key"); pElem != 0; pElem = pElem->FUN_140168650("key"))
    {
        CStringW strName = FUN_1401bf530(pElem, m_keyAttribute20, CStringW(L""));
        CStringW strText = FUN_1401bf530(pElem, m_valueAttribute28, CStringW(L""));
        typename KeyMap::CPair* pPair = names->Lookup(strName);
        if (pPair == 0)
        {
            FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", m_path18);
            delete pMap;
            pMap = 0;
            return 0;
        }
        pMap->SetAt(pPair->m_value, strText);
    }
    return pMap;
}

// @0x141025b80
template <class T> CStringW StringXmlProc<T>::GetText(T id)
{
    ValueMap* pMap = GetData();
    if (pMap == 0)
        return CStringW(L"");
    typename ValueMap::CPair* pPair = pMap->Lookup(id);
    if (pPair == 0)
        return CStringW(L"");
    return CStringW(pPair->m_value);
}

// @0x141025c50
template <class T> typename StringXmlProc<T>::ValueMap* StringXmlProc<T>::GetData()
{
    if (m_cached38 == 0)
        m_cached38 = LoadData();
    return m_cached38;
}

template CStringW StringManager::GetText<PVPStringId>(StringXmlCategory, PVPStringId);
template CStringW StringXmlProc<PVPStringId>::GetText(PVPStringId);
template StringXmlProc<PVPStringId>::ValueMap* StringXmlProc<PVPStringId>::GetData();
template StringXmlProc<PVPStringId>::ValueMap* StringXmlProc<PVPStringId>::LoadData();

// ---- the UGC cache settings -----------------------------------------------------------------------------------

// @0x141026740
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);

// @0x141026860
CString FUN_141026860()
{
    return DAT_143accfc0;
}

// @0x1410268a0
void FUN_1410268a0(CString strHost, CString strRegion)
{
    DAT_143accfc0 = strHost;
    strRegion.MakeLower();
    if (FUN_140184310(strRegion, "cn"))
        DAT_1439f6efc = 0;
}

// @0x141026920
CStringW FUN_141026920(int nKind)
{
    CString strDir;
    switch (nKind)
    {
    case 1:
        strDir = ".\\Custom\\Equip";
        break;
    case 3:
        strDir = ".\\Custom\\Image";
        break;
    case 2:
        strDir = ".\\Custom\\Cube";
        break;
    case 5:
        strDir = ".\\Custom\\Image";
        break;
    case 6:
        strDir = ".\\Custom\\Guild";
        break;
    case 8:
        strDir = ".\\Custom\\Guild\\Poster";
        break;
    case 7:
        strDir = ".\\Custom\\Ridee";
        break;
    case 9:
        strDir = ".\\Custom\\Image";
        break;
    case 10:
        strDir = ".\\Custom\\WeddingProfile";
        break;
    }
    return FUN_14016a730(strDir, 0);
}

// ---- statics (.text$di) -----------------------------------------------------------------------------------------

CString DAT_143accfc0("ua-maplestory2.nexon.com");
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cab540-0x142cab560 .text$yd
