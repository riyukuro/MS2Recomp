// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CNametagSymbolTable: the name tag symbol table
// (Table/nametagSymbol.xml) held in an ATL::CRBMap<unsigned short, MS2Ptr<CNametagSymbolData>>, and the rules that pick
// the symbol icon of a player.
// MS2-UNIT: ?\nametagsymboltable.cpp
// MS2-RANGE: 0x1400bb6a0-0x1400bb810 .text$di
// MS2-RANGE: 0x1406c53d0-0x1406c8680 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x1400bb760 ; probe
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x1400bb790 ; probe
// MS2-PIN: ?get@?$MS2Ptr@VCNametagSymbolData@@@@QEBAPEAVCNametagSymbolData@@XZ 0x1406c71a0 ; unique
// MS2-PIN: ??C?$MS2Ptr@VCNametagSymbolData@@@@QEBAPEAVCNametagSymbolData@@XZ 0x1406c71c0 ; unique
// MS2-PIN: ?get@?$MS2Ptr@VUnk_NametagChar@@@@QEBAPEAVUnk_NametagChar@@XZ 0x1406c71d0 ; order
// MS2-PIN: ?CompareElementsOrdered@?$CDefaultCompareTraits@G@ATL@@SAHAEBG0@Z 0x1406c73e0 ; unique
// MS2-PIN: ?SetAt@?$CRBMap@GV?$MS2Ptr@VCNametagSymbolData@@@@V?$CElementTraits@G@ATL@@V?$CElementTraits@V?$MS2Ptr@VCNametagSymbolData@@@@@3@@ATL@@QEAAPEAU__POSITION@@GAEBV?$MS2Ptr@VCNametagSymbolData@@@@@Z 0x1406c81e0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_7CNametagSymbolTable@@6B?$TSingleton@VCNametagSymbolTable@@@@@ 0x142d79fe0
// MS2-PIN: ??_7CNametagSymbolTable@@6B?$CValidData@VCNametagSymbolTable@@@@@ 0x142d79ff0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\nametagsymboltable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "nametagsymboltable.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include <vector>
#include "hook/ms2hook.h"

// The statics of the common header (the sort names, "skill", "stun" and the condition map).
#include "ms2/placeholder/header_statics_a.h"

// ---- unrecovered helpers (the tinyxml wrappers and the singletons the other table units share) ----

class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* pDoc, const char* pszPath, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
class Unk_CommonLog { public: void FUN_14015eb90(int level, int flags, const wchar_t* format, const CString& arg); };
Unk_CommonLog* FUN_140166440();
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);        // Table/<file>
CString FUN_14016a5c0(const char* pszName, int nFlags);     // undecorated class name
void FUN_14028faa0(Unk_140165cf0* pParent, const char* pszName, const char* pszAttr, std::vector<Unk_140165cf0*>* pOut);
void* FUN_1403ed2d0();                                      // the own player
Unk_NametagActor* FUN_141bd0cc0(void* pPlayer);             // its actor
int FUN_14123c580(Unk_NametagActor* pActor);                // the actor's character id

class Unk_NametagTitles { public: int FUN_140408410(const unsigned int* pCode); };   // the owned titles
extern Unk_NametagTitles DAT_143ab3268;
class Unk_NametagScore { public: int FUN_140267c10(); };    // the trophy points
class Unk_NametagTrophy { public: Unk_NametagScore* FUN_140938ad0(); };
extern Unk_NametagTrophy* DAT_143ab0668;
struct Unk_NametagFlags { char m_pad[0x30]; char m_bEnabled; };
extern Unk_NametagFlags* DAT_143ab0468;

// The character record of a character id (the trophy points sit at +0xd0).
class Unk_NametagChar : public CPtred
{
public:
    char m_pad[0xd0 - 0x18];
    Unk_NametagScore m_score;
};
struct Unk_NtPlayer { MS2Ptr<Unk_NametagChar> FUN_141bc9be0(int nCharId); };

// The unit's init flag and singleton are exe globals (symbols-manual.tsv); the hook DLL binds the exe's.
#ifndef MS2_HOOK_DLL
CNametagSymbolTable* TSingleton<CNametagSymbolTable>::s_instance;
bool CNametagSymbolTable::s_bInit;
#endif

static NametagConditionType FUN_1406c67a0(const CStringA& str);
static CStringW FUN_1406c6990(const CStringW& strIcon, unsigned short nValue);
static CStringW FUN_1406c6ab0(const CStringW& strIcon, unsigned short nValue);

// ---- CNametagSymbolTable ----

// @0x1406c53d0
CNametagSymbolTable::CNametagSymbolTable()
    : m_map(10)
{
}

// @0x1406c5460
CNametagSymbolTable::~CNametagSymbolTable()
{
}

// @0x1406c54d0
int CNametagSymbolTable::Load()
{
    CString strPath = FUN_14071a5b0(CString("Table"), CString("nametagSymbol.xml"));
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_140166440()->FUN_14015eb90(1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 0;
    }
    std::vector<Unk_140165cf0*> nodes;
    FUN_14028faa0(pRoot, "symbol", "id", &nodes);
    for (size_t i = 0; i < nodes.size(); ++i)
    {
        Unk_140165cf0* pNode = nodes[i];
        if (pNode != 0)
        {
            CNametagSymbolDataPtr spData(new CNametagSymbolData);
            FUN_1408731a0(pNode, "id", spData->m_nId);
            FUN_140873420(pNode, "icon", spData->m_strIcon);
            XmlEnumName<NametagConditionType, FUN_1406c67a0>(pNode, "conditionType", spData->m_eCondition);
            FUN_140873220(pNode, "code", spData->m_nCode);
            FUN_1408731e0(pNode, "hideSymbol", spData->m_nHideSymbol);
            FUN_140873220(pNode, "buffID", spData->m_nBuffId);
            FUN_1408731a0(pNode, "buffLv", spData->m_nBuffLv);
            FUN_1408731e0(pNode, "pushSymbol", spData->m_nPushSymbol);
            m_map.SetAt(spData->m_nId, spData);
            m_arrIds.Add(spData->m_nId);
        }
    }
    SetInit(true);
    return 1;
}

// @0x1406c58c0
CNametagSymbolDataPtr CNametagSymbolTable::GetData(unsigned short nId)
{
    CheckInit();
    CNametagSymbolDataPtr spData(0);
    m_map.Lookup(nId, spData);
    return spData;
}

// @0x1406c5950
CNametagSymbolDataPtr CNametagSymbolTable::FindByTitle(int nTitleId)
{
    CheckInit();
    POSITION pos = m_map.GetHeadPosition();
    while (pos != 0)
    {
        CNametagSymbolDataPtr spData = m_map.GetValueAt(pos);
        if (spData->m_eCondition == NAMETAG_CONDITION_TITLE)
        {
            if ((int)spData->m_nCode == nTitleId)
                return spData;
        }
        m_map.GetNext(pos);
    }
    return CNametagSymbolDataPtr(0);
}

// @0x1406c5a70
bool CNametagSymbolTable::Exists(unsigned short nId)
{
    CheckInit();
    CNametagSymbolDataPtr spData(0);
    m_map.Lookup(nId, spData);
    return spData.get() != 0;
}

// @0x1406c5b00
bool CNametagSymbolTable::IsType(unsigned short nId, int nType)
{
    CheckInit();
    CNametagSymbolDataPtr spData(0);
    if (!m_map.Lookup(nId, spData))
        return false;
    return spData->m_eCondition == nType;
}

// @0x1406c5bb0
unsigned short CNametagSymbolTable::FindIdByType(int nType)
{
    CheckInit();
    POSITION pos = m_map.GetHeadPosition();
    while (pos != 0)
    {
        CNametagSymbolDataPtr spData = m_map.GetValueAt(pos);
        if (spData->m_eCondition == nType)
            return spData->m_nId;
        m_map.GetNext(pos);
    }
    return 0;
}

// @0x1406c5c80
bool CNametagSymbolTable::IsShown(unsigned short nId)
{
    CheckInit();
    CNametagSymbolDataPtr spData(0);
    if (!m_map.Lookup(nId, spData))
        return false;
    if (spData->m_nHideSymbol == 0)
        return false;
    return CheckCondition(nId) == 0;
}

// @0x1406c5d60
unsigned int CNametagSymbolTable::CheckCondition(unsigned short nId)
{
    CheckInit();
    Unk_NametagActor* pActor = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pActor == 0)
        return 0;
    CNametagSymbolDataPtr spData(0);
    if (!m_map.Lookup(nId, spData))
        return 0;
    unsigned int nResult;
    switch (spData->m_eCondition)
    {
    case NAMETAG_CONDITION_LEVEL:
        nResult = pActor->vfunc_78() > 0x31;
        break;
    case NAMETAG_CONDITION_ENCHANT:
    {
        char a[8];
        char b[4];
        nResult = pActor->FUN_141661e40(a, b);
        break;
    }
    case NAMETAG_CONDITION_TITLE:
        nResult = DAT_143ab3268.FUN_140408410(&spData->m_nCode) != -1;
        break;
    case NAMETAG_CONDITION_TROPHY_POINT:
        nResult = DAT_143ab0668->FUN_140938ad0()->FUN_140267c10() > 999;
        break;
    case NAMETAG_CONDITION_VIP:
        nResult = pActor->FUN_141662de0();
        break;
    case NAMETAG_CONDITION_TENCENTVIP:
        nResult = pActor->FUN_141663080() != 0;
        break;
    case NAMETAG_CONDITION_TGP:
        nResult = pActor->FUN_1416630c0();
        break;
    case NAMETAG_CONDITION_GM:
        nResult = pActor->GetGmGrade() > 0x31;
        break;
    case NAMETAG_CONDITION_RETURN_USER:
        if (!DAT_143ab0468->m_bEnabled)
            nResult = 0;
        else
            nResult = pActor->FUN_14165ffe0() == 2;
        break;
    case NAMETAG_CONDITION_BIRTHDAY:
        nResult = pActor->FUN_141660030();
        break;
    case NAMETAG_CONDITION_ADVENTURE_LEVEL:
        nResult = pActor->vfunc_141() > 99;
        break;
    case NAMETAG_CONDITION_BURNING:
        nResult = pActor->FUN_1415275b0(nId);
        break;
    case NAMETAG_CONDITION_SURVIVAL_LEVEL:
        nResult = pActor->FUN_141663b50() > 4;
        break;
    default:
        nResult = 0;
        break;
    }
    return nResult;
}

// @0x1406c61a0
CStringW CNametagSymbolTable::GetIconRanked(unsigned short nId, Unk_NametagActor* pActor)
{
    CheckInit();
    CNametagSymbolDataPtr spData(0);
    if (!m_map.Lookup(nId, spData))
        return CStringW(L"");
    CStringW strIcon(spData->m_strIcon);
    if (spData->m_eCondition == NAMETAG_CONDITION_ADVENTURE_LEVEL)
        return FUN_1406c6990(strIcon, (unsigned short)pActor->vfunc_141());
    if (spData->m_eCondition == NAMETAG_CONDITION_SURVIVAL_LEVEL)
        return FUN_1406c6ab0(strIcon, pActor->FUN_141663b50());
    return strIcon;
}

// @0x1406c6360
CStringW CNametagSymbolTable::GetIcon(unsigned short nId, Unk_NametagActor* pActor)
{
    CheckInit();
    CNametagSymbolDataPtr spData(0);
    if (!m_map.Lookup(nId, spData))
        return CStringW(L"");
    int nType = spData->m_eCondition;
    if (nType == NAMETAG_CONDITION_LEVEL)
    {
        unsigned short nLevel = pActor->vfunc_78();
        for (unsigned __int64 nBase = 0x32; nBase < 0x5b; nBase += 10)
        {
            if (nBase <= nLevel && (unsigned __int64)nLevel < nBase + 10)
                return StringFormat(L"level{0}", nBase);
        }
        return CStringW(L"");
    }
    if (nType == NAMETAG_CONDITION_TROPHY_POINT)
    {
        CStringW strIcon(spData->m_strIcon);
        int nCharId = FUN_14123c580(pActor);
        MS2Ptr<Unk_NametagChar> spChar = reinterpret_cast<Unk_NtPlayer*>(FUN_1403ed2d0())->FUN_141bc9be0(nCharId);
        if (spChar.get() != 0)
        {
            if (spChar->m_score.FUN_140267c10() < 2000)
                strIcon += L"1000";
            else if (spChar->m_score.FUN_140267c10() < 3000)
                strIcon += L"2000";
            else
                strIcon += L"3000";
        }
        return strIcon;
    }
    if (nType == NAMETAG_CONDITION_TENCENTVIP)
    {
        int nGrade = pActor->FUN_141663080();
        return StringFormat(L"{0}{1}", spData->m_strIcon, nGrade);
    }
    return GetIconRanked(nId, pActor);
}

// @0x1406c66d0
CStringW CNametagSymbolTable::GetIcon(unsigned short nId)
{
    CheckInit();
    CNametagSymbolDataPtr spData(0);
    if (!m_map.Lookup(nId, spData))
        return CStringW(L"");
    return CStringW(spData->m_strIcon);
}

// @0x1406c67a0
static NametagConditionType FUN_1406c67a0(const CStringA& str)
{
    if (str.IsEmpty())
        return NAMETAG_CONDITION_NONE;
    if (str.CompareNoCase("level") == 0)
        return NAMETAG_CONDITION_LEVEL;
    if (str.CompareNoCase("enchant") == 0)
        return NAMETAG_CONDITION_ENCHANT;
    if (str.CompareNoCase("title") == 0)
        return NAMETAG_CONDITION_TITLE;
    if (str.CompareNoCase("trophy_point") == 0)
        return NAMETAG_CONDITION_TROPHY_POINT;
    if (str.CompareNoCase("vip") == 0)
        return NAMETAG_CONDITION_VIP;
    if (str.CompareNoCase("tencentvip") == 0)
        return NAMETAG_CONDITION_TENCENTVIP;
    if (str.CompareNoCase("tgp") == 0)
        return NAMETAG_CONDITION_TGP;
    if (str.CompareNoCase("gm") == 0)
        return NAMETAG_CONDITION_GM;
    if (str.CompareNoCase("return_user") == 0)
        return NAMETAG_CONDITION_RETURN_USER;
    if (str.CompareNoCase("birthday") == 0)
        return NAMETAG_CONDITION_BIRTHDAY;
    if (str.CompareNoCase("adventure_level") == 0)
        return NAMETAG_CONDITION_ADVENTURE_LEVEL;
    if (str.CompareNoCase("burning") == 0)
        return NAMETAG_CONDITION_BURNING;
    if (str.CompareNoCase("survivallevel") == 0)
        return NAMETAG_CONDITION_SURVIVAL_LEVEL;
    return NAMETAG_CONDITION_NONE;
}

// The adventure level icon: the icon name plus the highest level step reached.
// @0x1406c6990
static CStringW FUN_1406c6990(const CStringW& strIcon, unsigned short nValue)
{
    int nUnused = 0;
    unsigned short arrStep[5] = { 1000, 700, 500, 300, 100 };
    unsigned int i = 0;
    for (;;)
    {
        if (i > 4)
        {
            int nLast = 100;
            return StringFormat(L"{0}_{1}", strIcon, nLast);
        }
        if (arrStep[(int)i] <= nValue)
            break;
        ++i;
    }
    return StringFormat(L"{0}_{1}", strIcon, arrStep[(int)i]);
}

// The survival level icon.
// @0x1406c6ab0
static CStringW FUN_1406c6ab0(const CStringW& strIcon, unsigned short nValue)
{
    int nUnused = 0;
    unsigned short arrStep[7] = { 0x3c, 0x37, 0x2d, 0x23, 0x19, 0xf, 5 };
    unsigned int i = 0;
    for (;;)
    {
        if (i > 6)
        {
            int nLast = 5;
            return StringFormat(L"{0}_{1}", strIcon, nLast);
        }
        if (arrStep[(int)i] <= nValue)
            break;
        ++i;
    }
    return StringFormat(L"{0}_{1}", strIcon, arrStep[(int)i]);
}

// @0x1406c6ed0
CNametagSymbolData::CNametagSymbolData()
    : m_nId(0), m_eCondition(NAMETAG_CONDITION_NONE), m_nCode(0), m_nHideSymbol(0), m_nBuffId(0), m_nBuffLv(0), m_nPushSymbol(0)
{
}

// @0x1406c70f0
CNametagSymbolData::~CNametagSymbolData()
{
}

// @0x1406c7330
void CNametagSymbolTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CNametagSymbolTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x1406c75c0
int Unk_NametagActor::GetGmGrade()
{
    return m_nGmGrade;
}

// @0x1406c7600
Unk_NametagTrophy* FUN_1406c7600()
{
    return DAT_143ab0668;
}

// @0x1406c7610
Unk_NametagFlags* FUN_1406c7610()
{
    return DAT_143ab0468;
}

// @0x1406c82c0
void CNametagSymbolTable::SetInit(bool b)
{
    s_bInit = b;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9b750-0x142c9b7e0 .text$yd
