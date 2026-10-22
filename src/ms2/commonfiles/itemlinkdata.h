// itemlinkdata.h - the hyperlink data of chat/mail text: CHyperLinkData (RTTI .?AVCHyperLinkData@@, 0x20 bytes: CPtred +
// the link type at +0x18) and its subclasses, one per link type (RTTI names): CItemLinkData (+0x20 the owner id),
// CLinkSerialID (1), CLinkItemID (2), CLinkItemGUID (3), CLinkAchieveID (4), CLinkCashSaleProduct (5),
// CLinkBlackMarketSN (6) and CLinkMeratMarketProduct (7). Parsed from "<...>" tags by FUN_1405bd720. Recovered from
// MapleStory2.exe KMS2_DEV x64 (2022-04-13); unit ?\itemlinkdata.cpp (0x1405bd5b0-0x1405bea40, was ?\hyperlinkdata.cpp). The
// header name is assumed; member names are invented from use.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"

class CHyperLinkData : public CPtred
{
public:
    CHyperLinkData(long nType);                                 // 0x1405bd5b0
    virtual ~CHyperLinkData() = default;                                  // 0x1405be190 (??_G 0x1405be340)
    long GetType() const;                                 // the link type
protected:
    MS2_LAYOUT_FRIEND;
    long m_nType;                                               // +0x18
    int m_pad_1c;
};
MS2_CHECK_SIZE(CHyperLinkData, 0x20);

class CItemLinkData : public CHyperLinkData
{
public:
    CItemLinkData(long nType, __int64 nOwnerId);                // 0x1405bd6d0
    virtual ~CItemLinkData() = default;                                   // 0x1405be1b0 (??_G 0x1405be380)
    __int64 GetOwnerId() const;                              // the owner id
protected:
    __int64 m_nOwnerId;                                         // +0x20
};
MS2_CHECK_SIZE(CItemLinkData, 0x28);

class CLinkAchieveID : public CHyperLinkData
{
public:
    CLinkAchieveID();                                           // 0x1405bd650
    virtual ~CLinkAchieveID() = default;                                  // 0x1405be1d0 (??_G 0x1405be3c0)
};
MS2_CHECK_SIZE(CLinkAchieveID, 0x20);

class CLinkCashSaleProduct : public CHyperLinkData
{
public:
    CLinkCashSaleProduct();                                     // 0x1405bd690
    virtual ~CLinkCashSaleProduct() = default;                            // 0x1405be210 (??_G 0x1405be440)
};
MS2_CHECK_SIZE(CLinkCashSaleProduct, 0x20);

class CLinkItemID : public CItemLinkData
{
public:
    CLinkItemID(__int64 nOwnerId, int nItemId, int nRarity);    // 0x1405bd9c0
    virtual ~CLinkItemID() = default;                                     // 0x1405be250 (??_G 0x1405be4c0)
    int GetItemId() const;                                  // the item id
    unsigned short FUN_1405bdb20() const;                       // the rarity
protected:
    int m_nItemId;                                              // +0x28
    int m_nRarity;                                              // +0x2c
};
MS2_CHECK_SIZE(CLinkItemID, 0x30);

class CLinkItemGUID : public CItemLinkData
{
public:
    CLinkItemGUID(__int64 nOwnerId, __int64 nGuid);             // 0x1405bdb40
    virtual ~CLinkItemGUID() = default;                                   // 0x1405be230 (??_G 0x1405be480)
    __int64 GetGuid() const;                              // the item guid
protected:
    __int64 m_nGuid;                                            // +0x28
};
MS2_CHECK_SIZE(CLinkItemGUID, 0x30);

class CLinkSerialID : public CItemLinkData
{
public:
    CLinkSerialID(__int64 nOwnerId, int nSerialLow, int nSerialHigh);   // 0x1405bdc70
    virtual ~CLinkSerialID() = default;                                   // 0x1405be2a0 (??_G 0x1405be540)
    int GetLow() const;
    int GetHigh() const;
protected:
    int m_nLow;                                                 // +0x28
    int m_nHigh;                                                // +0x2c
};
MS2_CHECK_SIZE(CLinkSerialID, 0x30);

class CLinkBlackMarketSN : public CItemLinkData
{
public:
    CLinkBlackMarketSN(__int64 nOwnerId, __int64 nSerial);      // 0x1405bddf0
    virtual ~CLinkBlackMarketSN() = default;                              // 0x1405be1f0 (??_G 0x1405be400)
    __int64 GetSerial() const;                              // the serial number
protected:
    __int64 m_nSerial;                                          // +0x28
};
MS2_CHECK_SIZE(CLinkBlackMarketSN, 0x30);

class CLinkMeratMarketProduct : public CItemLinkData
{
public:
    CLinkMeratMarketProduct(__int64 nOwnerId, const CString& strName, bool bFlag, int nCount);   // 0x1405bdf20
    virtual ~CLinkMeratMarketProduct() = default;                         // 0x1405be270 (??_G 0x1405be500)
protected:
    CString m_strName;                                          // +0x28
    bool m_bFlag;                                               // +0x30
    int m_nCount;                                               // +0x34
};
MS2_CHECK_SIZE(CLinkMeratMarketProduct, 0x38);

// Parses the "<...>" tags of a text into link objects (0x1405bd720).
void FUN_1405bd720(const CStringW& strText, ATL::CAtlArray<MS2Ptr<CHyperLinkData> >& arrOut);
