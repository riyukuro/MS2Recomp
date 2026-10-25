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
Unk_WdUgcPaths* FUN_1401d31f0();

PC* FUN_141bd1530(WorldService* pWorld, __int64 nCharacterId);              // the field player of a character id
CString FUN_141028be0(__int64 nCharacterId, const CString& strKey, int nKind, CString strExt);   // a UGC profile path
CStringTable* GetStringTable();                                              // the string table singleton
bool FUN_140900f30(__int64 nTime);                                          // the time is at night (before 6 / after 17)
CStringW FUN_140b8e850(const CMsTime& kTime);                               // the date text
CStringW FUN_1409404f0(__int64 nMerat);                                     // the price text

CStringW FormatStringId(int nId, const fmt::ArgList& args);                 // 0x14052bd00 (CStringW)
FMT_VARIADIC_W(CStringW, FormatStringId, int)

// @0x140fdab30
// The portrait icon of a partner: its UGC profile image when it is in the field, else the default portrait.
CString FUN_140fdab30(const Unk_WeddingPartner* pPartner)
{
    PC* pPC = FUN_141bd1530(WorldService::GetInstance(), pPartner->m_nCharacterId);
    if (pPC == 0)
        return FUN_1401d31f0()->m_strDefaultProfile;
    return FUN_141028be0(pPartner->m_nCharacterId, pPC->FUN_1416612e0(), 1, CString(""));
}
MS2_REPLACE(0x140FDAB30, FUN_140fdab30, 281, 0xC1D9E733);

// @0x140fdac50
// MS2-FUNCTIONAL: the exe's public flag is a bool parameter passed on without a conversion; the reservation pages
// (uiweddinghallreservationpage*.cpp) declare it unsigned char, so here it is converted for ASObj's bool setter.
void FUN_140fdac50(int nPackageId, int nHallId, __int64 nTime, unsigned char bPublic, ASObj* pData)
{
    WeddingProxy* pProxy = WeddingManager::GetInstance()->FUN_140d295d0();
    MS2Ptr<WeddingPackage> spPackage = WeddingTable::GetInstance()->FUN_140908b80(nPackageId);
    if (spPackage == 0)
        return;
    MS2Ptr<WeddingHallData> spHall = spPackage->FUN_140907110(nHallId);
    if (spHall == 0)
        return;
    ASObj kGroom(2);
    kGroom.FUN_1407cbb20("name", pProxy->m_groom.m_strName);
    kGroom.FUN_1407cba60("iconPath", FUN_140fdab30(&pProxy->m_groom));
    pData->FUN_1409eb270("groom", kGroom);
    ASObj kBride(2);
    kBride.FUN_1407cbb20("name", pProxy->m_bride.m_strName);
    kBride.FUN_1407cba60("iconPath", FUN_140fdab30(&pProxy->m_bride));
    pData->FUN_1409eb270("bride", kBride);
    pData->FUN_1407cbb20("hall", GetStringTable()->FUN_141811980(3,
        WeddingTable::GetInstance()->FUN_140908d50(spPackage->m_nId, spHall->m_nId, FUN_140900f30(nTime))));
    pData->FUN_1407cbb20("date", FUN_140b8e850(CMsTime(nTime)));
    pData->FUN_1407cbbe0("isPublic", bPublic);
    pData->FUN_1407cbb20("price", FormatStringId(0x987, FUN_1409404f0(spHall->m_nMerat)));
}
MS2_REPLACE(0x140FDAC50, FUN_140fdac50, 1079, 0xF9348D26);
