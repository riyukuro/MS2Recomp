// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CPriceTable: Table/shop_Maid.xml, shop_UGCAll.xml, MaidSalary.xml.
// MS2-UNIT: ?\pricetable.cpp
// MS2-RANGE: 0x140738a30-0x14073b630 .text$mn
// MS2-PIN: ??1CPriceTable@@UEAA@XZ 0x1407396f0
// MS2-PIN: ??_GCPriceTable@@UEAAPEAXI@Z 0x1407397f0
// MS2-PIN: ??_7CPriceTable@@6B?$TSingleton@VCPriceTable@@@@@ 0x142d83ff0
// MS2-PIN: ??_7CPriceTable@@6B?$CValidData@VCPriceTable@@@@@ 0x142d84000
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\pricetable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "pricetable.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/filesystem.h"

// Unrecovered helpers (the same xml loader helpers the other table units use).
class Unk_140165cf0 { public: Unk_140165cf0* FUN_140165cf0(const char*); Unk_140165cf0* FUN_140168650(const char*); };
class CLogString* GetLogString();
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax
void FUN_1408731e0(Unk_140165cf0*, const char*, int&);
void FUN_140873220(Unk_140165cf0*, const char*, unsigned&);
int FUN_1408730a0(Unk_140165cf0*, const char*, bool&);
void FUN_1408732e0(Unk_140165cf0*, const char*, __int64&);

// @0x140738a30
Unk_PriceHousing::Unk_PriceHousing()
{
    m_bBuy = true;
    m_nDefaultPrice = 0;
    m_nMoneyType = 1;
}

// @0x140738a70
Unk_PriceSalary::Unk_PriceSalary()
{
    m_nType = 0;
    m_nAmount = 0;
}

// @0x140738aa0
CPriceTable::CPriceTable() : m_salaries(17, 0.75f, 0.25f, 2.25f, 10), m_housing(17, 0.75f, 0.25f, 2.25f, 10)
{
}

// @0x140738ba0
int CPriceTable::Load()
{
    if (!LoadHousing("shop_Maid.xml"))
        return 0;
    if (!LoadHousing("shop_UGCAll.xml"))
        return 0;
    if (!LoadSalary("MaidSalary.xml"))
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140738BA0, CPriceTable, Load, 298, 0x5CC452C5);

// @0x140738cd0
void CPriceTable::GetSalary(int nId, int* pnType, int* pnAmount)
{
    Unk_PriceSalary salary;
    if (m_salaries.Lookup(nId, salary))
    {
        *pnType = salary.m_nType;
        *pnAmount = salary.m_nAmount;
    }
}
MS2_REPLACE_METHOD(0x140738CD0, CPriceTable, GetSalary, 93, 0xB963986E);

// @0x140738d40
void CPriceTable::GetHousing(unsigned nId, bool* pbBuy, __int64* pnPrice, int* pnMoneyType)
{
    Unk_PriceHousing housing;
    if (m_housing.Lookup(nId, housing))
    {
        *pbBuy = housing.m_bBuy;
        *pnPrice = housing.m_nDefaultPrice;
        *pnMoneyType = housing.m_nMoneyType;
    }
}
MS2_REPLACE_METHOD(0x140738D40, CPriceTable, GetHousing, 109, 0xEF0BCF87);

// @0x140738dc0
int CPriceTable::HasHousing(unsigned nId)
{
    if (m_housing.Lookup(nId))
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x140738DC0, CPriceTable, HasHousing, 55, 0x82EE30EE);

// @0x140738e00
int CPriceTable::IsHousingBuyable(unsigned nId)
{
    Unk_PriceHousing housing;
    if (m_housing.Lookup(nId, housing) && housing.m_bBuy)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x140738E00, CPriceTable, IsHousingBuyable, 81, 0x4EF58335);

// @0x140738e60
int CPriceTable::LoadHousing(const CString& strFile)
{
    CString strPath = FUN_14071a5b0("Table", strFile);
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, (const char*)strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 0;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("key"); pNode != 0; pNode = pNode->FUN_140168650("key"))
    {
        unsigned nId = 0;
        FUN_140873220(pNode, "id", nId);
        bool bBuy = false;
        FUN_1408730a0(pNode, "ugcHousingBuy", bBuy);
        __int64 nPrice = 0;
        FUN_1408732e0(pNode, "ugcHousingDefaultPrice", nPrice);
        int nMoneyType = 1;
        FUN_140873220(pNode, "ugcHousingMoneyType", reinterpret_cast<unsigned&>(nMoneyType));
        Unk_PriceHousing housing;
        housing.m_bBuy = bBuy;
        housing.m_nDefaultPrice = nPrice;
        housing.m_nMoneyType = nMoneyType;
        m_housing.SetAt(nId, housing);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x140738E60, CPriceTable, LoadHousing, 626, 0x6696CFE3);

// @0x1407390e0
int CPriceTable::LoadSalary(const CString& strFile)
{
    CString strPath = FUN_14071a5b0("Table", strFile);
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, (const char*)strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 0;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("key"); pNode != 0; pNode = pNode->FUN_140168650("key"))
    {
        int nId = 0;
        FUN_1408731e0(pNode, "id", nId);
        Unk_PriceSalary salary;
        FUN_1408731e0(pNode, "SalaryType", salary.m_nType);
        FUN_1408731e0(pNode, "SalaryAmount", salary.m_nAmount);
        m_salaries.SetAt(nId, salary);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1407390E0, CPriceTable, LoadSalary, 531, 0x2F2D2DD6);
