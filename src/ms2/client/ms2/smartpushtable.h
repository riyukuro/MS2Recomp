// smartpushtable.h - CSmartPushData / CAutoActionPricePackage / CSmartPushTable (RTTI names): the smart-push (shop
// suggestion) table read from Table/smartPush.xml and the auto-action price packages from
// Table/AutoActionPricePackage.xml. Header name assumed; member and helper names are invented from the xml attributes.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/ms2svrptr.h"
#include "ms2/placeholder/tptrvalue.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/commonstruct_wa.h"

// One <push> row of smartPush.xml. RTTI CSmartPushData, 0x68 bytes, base CPtred.
class CSmartPushData : public CPtred
{
public:
    CSmartPushData();                   // 0x140812180
    virtual ~CSmartPushData();          // 0x140812480

    int m_nId;                          // +0x18 "id"
    CStringW m_strContent;              // +0x20 "content"
    int m_nActionType;                  // +0x28 "actionType"
    unsigned m_nActionValue;            // +0x2c "actionValue"
    __int64 m_nRequireMerat;            // +0x30 "requireMerat"
    CIngredientInfo m_requireItem;      // +0x38 "requireItem" (id:tag,count)
    CStringW m_strImgPath;              // +0x60 "imgPath"
};
MS2_CHECK_SIZE(CSmartPushData, 0x68);
MS2_CHECK_OFFSET(CSmartPushData, m_requireItem, 0x38);
MS2_CHECK_OFFSET(CSmartPushData, m_strImgPath, 0x60);

// One <package> row of AutoActionPricePackage.xml. RTTI CAutoActionPricePackage, 0x38 bytes, base CPtred.
class CAutoActionPricePackage : public CPtred
{
public:
    CAutoActionPricePackage();          // 0x140812000
    virtual ~CAutoActionPricePackage(); // 0x1408123c0

    CStringW m_strContent;              // +0x18 "content"
    unsigned m_nId;                     // +0x20 "id"
    unsigned m_nDuration;               // +0x24 "duration" (minutes)
    __int64 m_nMerat;                   // +0x28 "merat"
    __int64 m_nMeso;                    // +0x30 "meso"
};
MS2_CHECK_SIZE(CAutoActionPricePackage, 0x38);

class CSmartPushTable : public TSingleton<CSmartPushTable>, public CValidData<CSmartPushTable>
{
public:
    typedef MS2SvrPtr<CSmartPushData> DataPtr;
    typedef MS2SvrPtr<CAutoActionPricePackage> PackagePtr;
    typedef ATL::CAtlArray<PackagePtr> PackageArray;
    typedef TPtrValue<PackageArray> PackageArrayPtr;
    typedef ATL::CAtlMap<int, DataPtr> DataMap;
    typedef ATL::CAtlMap<CStringW, PackageArrayPtr, ATL::CStringElementTraits<CStringW> > PackageMap;

    CSmartPushTable();                  // 0x1408105e0
    virtual ~CSmartPushTable();         // 0x1408106c0

    void Load();                                                // 0x140810730
    void LoadPackages();                                        // 0x140810d30
    void GetAll(ATL::CAtlArray<DataPtr>& rOut);                 // 0x140810c20 (name invented)
    DataPtr GetData(int nId);                                   // 0x140810ca0 (name invented)
    PackagePtr GetPackage(const CStringW& strName, unsigned n); // 0x140811110
    __int64 GetPackageMerat(const CStringW& strName, unsigned n);   // 0x140811240
    int GetPackageDuration(const CStringW& strName, unsigned n);    // 0x1408112d0 milliseconds
    CStringW GetPackageDurationText(const CStringW& strName, unsigned n);   // 0x140811370
    unsigned GetPackageCount(const CStringW& strName);          // 0x1408115a0

    static void CheckInit();            // 0x140812a90
    static void SetInit(bool b);        // 0x140815130

    static bool s_bInit;                // 0x143ab1a30

private:
    MS2_LAYOUT_FRIEND;
    DataMap m_data;                     // +0x10 id -> row
    PackageMap m_packages;              // +0x58 package name -> packages
};
MS2_CHECK_SIZE(CSmartPushTable, 0xa0);
MS2_CHECK_OFFSET(CSmartPushTable, m_data, 0x10);
MS2_CHECK_OFFSET(CSmartPushTable, m_packages, 0x58);
