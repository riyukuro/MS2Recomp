// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). DungeonRewardCoupon: the extra reward ticket definition of a
// dungeon room (Table/DungeonRewardCoupon.xml, loaded by DungeonRoomTable).
// MS2-UNIT: commonfiles\dungeonrewardcoupon.cpp
// MS2-RANGE: 0x14031c510-0x14031c970 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??1DungeonRewardCoupon@@UEAA@XZ 0x14031c7e0 ; unique
// MS2-PIN: ??_GDungeonRewardCoupon@@UEAAPEAXI@Z 0x14031c810 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\dungeonrewardcoupon.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "dungeonrewardcoupon.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Unrecovered helpers (the xml loader helpers the other table units use).
class Unk_140165cf0
{
public:
    Unk_140165cf0* FUN_14086e8d0(const char* pszName);     // first child element
    Unk_140165cf0* FUN_14086e7e0(const char* pszName);     // next sibling element
};
int XmlGetAttr(class TiXmlElement*, char const*, bool&);   // C3: was FUN_1408730a0
int FUN_140873220(Unk_140165cf0* pElem, const char* pszName, int& rOut);
int FUN_140873220(Unk_140165cf0* pElem, const char* pszName, unsigned& rOut);
int FUN_1408733e0(Unk_140165cf0* pElem, const char* pszName, CString& rOut);
unsigned FUN_140540000(const CString& strTag);              // ticket tag name -> value

// tinyxmlhelper.h: an attribute converted from its string form.
// @0x14031c680
#undef MS2_THIS_FILE
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinyxmlhelper.h"
inline int ReadTicketTagAttr(Unk_140165cf0* pElem, const char* pszName, unsigned* pnOut)
{
    if (FALSE)
    {
        MS2_ASSERT_AT(0xfa, FALSE);
        return 2;
    }
    CString str;
    int nRead = FUN_1408733e0(pElem, pszName, str);
    if (nRead != 0)
        return nRead;
    *pnOut = FUN_140540000(str);
    return nRead;
}
#undef MS2_THIS_FILE
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\dungeonrewardcoupon.cpp"

// tinyxmlhelper.h: the "v" attributes of the child elements `pszName` (1 when there is none).
// @0x14031c740
inline int ReadValueList(Unk_140165cf0* pElem, const char* pszName, ATL::CAtlArray<unsigned>& rOut)
{
    int nCount = 0;
    for (Unk_140165cf0* pChild = pElem->FUN_14086e8d0(pszName); pChild; pChild = pChild->FUN_14086e7e0(pszName))
    {
        unsigned nValue;
        FUN_140873220(pChild, "v", nValue);
        rOut.Add(nValue);
        nCount++;
    }
    return nCount > 0 ? 0 : 1;
}

// @0x14031c510
DungeonRewardCoupon::DungeonRewardCoupon()
    : m_id(0), m_ticketTag(0), m_baseItemID(0), m_maxExtraCount(0), m_canBuyInMeratMarket(true)
{
}

// @0x14031c590
int DungeonRewardCoupon::GetId()
{
    return m_id;
}
MS2_REPLACE_METHOD(0x14031C590, DungeonRewardCoupon, GetId, 14, 0x72E52537);

// @0x14031c5b0
void DungeonRewardCoupon::Load(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "id", m_id);
    ReadTicketTagAttr(pElem, "ticketTag", &m_ticketTag);
    FUN_140873220(pElem, "baseItemID", m_baseItemID);
    FUN_140873220(pElem, "maxExtraCount", m_maxExtraCount);
    ReadValueList(pElem, "baseRate", m_baseRate);
    XmlGetAttr((class TiXmlElement*)(pElem), "canBuyInMeratMarket", m_canBuyInMeratMarket);
}
MS2_REPLACE_METHOD(0x14031C5B0, DungeonRewardCoupon, Load, 193, 0x0D5BDF8D);

MS2_EMIT_CRT_MEMMOVE_S();
