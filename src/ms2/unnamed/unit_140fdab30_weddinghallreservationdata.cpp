// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The couple data of the wedding hall reservation pages
// (UIWeddingHallReservationPage / PageChange): the groom / bride rows (name, portrait icon), the hall name, the date,
// the public flag and the price of a package's hall. Shapes follow the v2525 reference decomp (tu/140fdab30.cpp).
// MS2-UNIT: unit_140fdab30
// MS2-RANGE: 0x140fdab30-0x140fdb090 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/weddingmanager.h"
#include "ms2/placeholder/weddingproxy.h"
#include "ms2/placeholder/weddingtable.h"
#include "ms2/placeholder/weddingpackage.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/fmt/format.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The UGC image paths (the portrait shown for a character that is not in the field at +0x90).
struct Unk_WdUgcPaths
{
    unsigned char m_pad_00[0x90];
    CString m_strDefaultProfile;                            // +0x90
};
class Unk_SingletonObj* GetCommonResource();   // C3: was GetCommonResource

CString FUN_141028be0(__int64 nCharacterId, const CString& strKey, int nKind, CString strExt);   // a UGC profile path
bool IsNightTime(__int64 nTime);                                          // the time is at night (before 6 / after 17)
CStringW FormatYearMonthDayHour(const CMsTime& kTime);                               // the date text
CStringW FUN_1409404f0(__int64 nMerat);                                     // the price text

#include "ms2/placeholder/formatstringid.h"   // C3: FormatStringId<...> over FUN_14028dee0 by its real name (was FormatStringId(int, const ArgList&))

// @0x140fdab30
// The portrait icon of a partner: its UGC profile image when it is in the field, else the default portrait.
CString GetPartnerProfileIconPath(const Unk_WeddingPartner* pPartner)
{
    PC* pPC = ((class PC*)((class WorldService*)(class WorldService*)(WorldService::GetInstance()))->FUN_141bd1530(pPartner->m_nCharacterId));
    if (pPC == 0)
        return ((struct Unk_WdUgcPaths*)GetCommonResource())->m_strDefaultProfile;
    return FUN_141028be0(pPartner->m_nCharacterId, pPC->FUN_1416612e0(), 1, CString(""));
}
MS2_REPLACE(0x140FDAB30, GetPartnerProfileIconPath, 281, 0xC1D9E733);

// @0x140fdac50
// Fills the page data object from the package, hall, time and public flag.
//
void FUN_140fdac50(int nPackageId, int nHallId, __int64 nTime, bool bPublic, ASObj* pData)
{
    WeddingProxy* pProxy = WeddingManager::GetInstance()->GetWeddingProxy();
    MS2Ptr<WeddingPackage> spPackage = WeddingTable::GetInstance()->FindPackage(nPackageId);
    if (spPackage == 0)
        return;
    MS2Ptr<WeddingHallData> spHall = spPackage->FindHall(nHallId);
    if (spHall == 0)
        return;
    ASObj kGroom(2);
    kGroom.SetWStringMember("name", pProxy->m_groom.m_strName);
    kGroom.SetStringMember("iconPath", GetPartnerProfileIconPath(&pProxy->m_groom));
    pData->FUN_1409eb270("groom", kGroom);
    ASObj kBride(2);
    kBride.SetWStringMember("name", pProxy->m_bride.m_strName);
    kBride.SetStringMember("iconPath", GetPartnerProfileIconPath(&pProxy->m_bride));
    pData->FUN_1409eb270("bride", kBride);
    pData->SetWStringMember("hall", TSingleton<CStringTable>::GetInstance()->FUN_141811980(3,
        WeddingTable::GetInstance()->GetHallFieldId(spPackage->m_nId, spHall->m_nId, IsNightTime(nTime))));
    pData->SetWStringMember("date", FormatYearMonthDayHour(CMsTime(nTime)));
    pData->SetBoolMember("isPublic", bPublic);
    pData->SetWStringMember("price", FormatStringId(0x987, FUN_1409404f0(spHall->m_nMerat)));
}
MS2_REPLACE(0x140FDAC50, FUN_140fdac50, 1079, 0xF9348D26);
