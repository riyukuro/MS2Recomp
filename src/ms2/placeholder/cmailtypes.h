// cmailtypes.h - PLACEHOLDER for the mail object classes defined in ?\mailattachitem.cpp (0x14068f630-0x140693e60):
// CMailAttachItem, CMailAdItem, CMailSendKeep and CMailInfo (RTTI names), all CPtred-derived. Member names are
// FUN_<va> where the purpose is not certain. NOT original headers.
//   CMailAttachItem 0x40: +0x18 int64 receive time, +0x20 int, +0x28 int64, +0x30 MS2Ptr<CItem> (ctor 0x14068f630)
//   CMailAdItem     0x40: +0x18..+0x24 four ints, +0x28/+0x30/+0x38 int64 (sums of +0x30/+0x38 over the ads)
//   CMailSendKeep   0x40: +0x18 int kind, +0x20 attach pointer, +0x30 MS2Ptr<CItem>  (ctors 0x14068fce0 / 0x14068fc30)
//   CMailInfo      0x138: see the class; strings, five attachment slots, five ads, three time ranges, benefit list
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"

class CItem;
class CMailAttachItem;
class CMailAdItem;
class CInPacket;
class CInputStream;
class Unk_CommonPriceRecord;

// Attachment-list pointer (member +0x20 of CMailSendKeep, element of CMailInfo's attachment array). The same
// 16-byte intrusive pointer as MS2Ptr<T>; every member is out of line in mailattachitem.cpp except operator=(T*),
// whose COMDAT (0x1408e4f40) is in usermail.cpp.
class Unk_MailAttachPtr {
public:
    Unk_MailAttachPtr();                                      // 0x1406929e0
    Unk_MailAttachPtr(int);                                   // 0x140692990
    Unk_MailAttachPtr(CMailAttachItem*);                      // 0x1406929b0
    Unk_MailAttachPtr(const Unk_MailAttachPtr&);              // 0x140692950
    Unk_MailAttachPtr(Unk_MailAttachPtr&&);                   // 0x140692920
    ~Unk_MailAttachPtr();                                     // 0x140692bc0
    Unk_MailAttachPtr& operator=(const Unk_MailAttachPtr&);   // 0x140692d40
    Unk_MailAttachPtr& operator=(int);                        // 0x140692d80
    Unk_MailAttachPtr& operator=(CMailAttachItem* value) {
        Unk_MailAttachPtr temp(value);
        CMailAttachItem* old = p;
        p = temp.p;
        temp.p = old;
        return *this;
    }
    bool operator==(CMailAttachItem* value) const;            // 0x140692e30
    CMailAttachItem* get() const;                             // 0x140692f70
    CMailAttachItem* operator->() const;                      // 0x140692fa0
private:
    void AddRef() const;                                      // 0x140693b60
    void AddRefImpl(void*) const;                             // 0x140693c50
    static void Reference(CMailAttachItem*);                  // 0x140693be0
    void Release();                                           // 0x140693cf0
    void ReleaseImpl(void*);                                  // 0x140693dc0
    void* m_unk_00; CMailAttachItem* p;
};
MS2_CHECK_SIZE(Unk_MailAttachPtr, 0x10);

class CMailAttachItem : public CPtred {
public:
    CMailAttachItem(int index, MS2Ptr<CItem> item);           // 0x14068f630
    CMailAttachItem(CInPacket& packet);                       // 0x14068f740
    virtual ~CMailAttachItem();
    void FUN_14068fac0();                                     // reset (drops the item, zeroes the fields)
    int FUN_14068fb10();                                      // item id, -1 without an item
    MS2_LAYOUT_FRIEND;
    __int64 m_nTime; int m_n20; int m_pad_24; __int64 m_n28;   // +0x18
    MS2Ptr<CItem> m_item;                                      // +0x30
};
MS2_CHECK_SIZE(CMailAttachItem, 0x40);
MS2_CHECK_OFFSET(CMailAttachItem, m_item, 0x30);

class CMailAdItem : public CPtred {
public:
    CMailAdItem();                                            // 0x140692a20
    virtual ~CMailAdItem();                                   // 0x140692c20
    void FUN_14068fb60(CInputStream* stream);                 // read from the packet stream
    MS2_LAYOUT_FRIEND;
    int m_n18; int m_n1c; int m_n20; int m_n24;                // +0x18
    __int64 m_n28; __int64 m_n30; __int64 m_n38;               // +0x28
};
MS2_CHECK_SIZE(CMailAdItem, 0x40);

// Mail template record looked up by id (0x140851e50); the three strings seed an empty mail.
class Unk_MailTpl : public CPtred {
public:
    MS2_LAYOUT_FRIEND;
    char m_pad_18[0x20];
    CStringW m_str38; CStringW m_str40; CStringW m_str48;
    char m_pad_50[0x28];
};
MS2_CHECK_OFFSET(Unk_MailTpl, m_str48, 0x48);

class CMailSendKeep : public CPtred {
public:
    CMailSendKeep(MS2Ptr<CItem> item);                         // 0x14068fc30 (kind 1)
    CMailSendKeep(Unk_MailAttachPtr attach);                   // 0x14068fce0 (kind 0)
    virtual ~CMailSendKeep();
    __int64 FUN_14068fe20(int slot);
    MS2_LAYOUT_FRIEND;
    int m_kind; int m_pad_1c;                                  // +0x18
    Unk_MailAttachPtr m_attach;                                // +0x20
    MS2Ptr<CItem> m_item;                                      // +0x30
};
MS2_CHECK_SIZE(CMailSendKeep, 0x40);
MS2_CHECK_OFFSET(CMailSendKeep, m_kind, 0x18);
MS2_CHECK_OFFSET(CMailSendKeep, m_attach, 0x20);
MS2_CHECK_OFFSET(CMailSendKeep, m_item, 0x30);

// Two int64 values (0x10 bytes): a start time and a claim time.
struct Unk_MailTimeRange {
    __int64 m_nBegin; __int64 m_nClaim;
    Unk_MailTimeRange();                                       // 0x140692840
    bool FUN_1406936a0() const;                                // begin set, not claimed
    bool FUN_1406936e0() const;
    bool FUN_140693b00(__int64 claim);                         // claims once
    void FUN_140693300(CInputStream* stream);                  // read both values
};
MS2_CHECK_SIZE(Unk_MailTimeRange, 0x10);

// One reward entry of the mail benefit list (0x18 bytes); the member functions live in another unit. It is the price
// record of commonfiles/commonpricerecord.h (Unk_CommonPriceRecord: ctor 0x14027d8d0, GetAvailableAmount 0x14026a1f0) and
// the list is Unk_CommonPriceRecordList (GetCount 0x14026a4b0, Read 0x14026a3d0); the names here are kept for mailattachitem.cpp.
struct Unk_MailBenefit {
    int m_nType; int m_nSub; char m_pad_08[0x10];
    bool FUN_14026a170() const;
    bool FUN_14026a220() const;
    __int64 FUN_14026a1f0();                                   // the amount while unused (Unk_CommonPriceRecord::GetAvailableAmount)
};
MS2_CHECK_SIZE(Unk_MailBenefit, 0x18);

class Unk_MailBenefitList {
public:
    Unk_MailBenefitList();                                     // 0x140692ab0
    ~Unk_MailBenefitList();                                    // 0x140692c40
    int FUN_14026a4b0() const;                                 // count
    bool FUN_14026a510() const;
    void FUN_14026a3d0(CInputStream* stream);                  // read from the packet stream
    mutable ATL::CAtlArray<Unk_MailBenefit> m_array;           // 0x20
};
MS2_CHECK_SIZE(Unk_MailBenefitList, 0x20);

class CMailInfo : public CPtred {
public:
    CMailInfo(int kind);                                       // 0x14068ff50
    virtual ~CMailInfo();
    void FUN_140690330(__int64 id);
    __int64 FUN_140690350();
    int FUN_140690370();
    void FUN_140690390(__int64 value, CStringW text);
    __int64 FUN_1406903f0();
    CStringW FUN_140690410() const;
    void FUN_140690460(__int64 value);
    __int64 FUN_140690480();
    void FUN_1406904a0(CStringW text);
    CStringW FUN_1406904f0() const;
    void FUN_140690540(CStringW a, CStringW b);
    CStringW FUN_1406905b0() const;
    CStringW FUN_140690600() const;
    void FUN_140690650(int slot, Unk_MailAttachPtr attach);
    void FUN_1406906c0(int slot, __int64 time);               // per-attachment receive time
    Unk_MailAttachPtr FUN_140690790(int slot) const;
    int FUN_140690840() const;                                 // attachments already received
    __int64 FUN_140690920(int slot) const;
    int FUN_1406909b0() const;
    int FUN_140690b80() const;
    void FUN_140690d20(__int64 a, __int64 b);
    void FUN_140690d60(__int64 time);
    __int64 FUN_140690db0() const;
    __int64 FUN_140690dd0() const;
    void FUN_140690df0(__int64 time);
    __int64 FUN_140690e40() const;
    __int64 FUN_140690e60() const;
    void FUN_140690e80(__int64 time);
    __int64 FUN_140690ed0() const;
    __int64 FUN_140690ef0() const;
    void FUN_140690f10(__int64 time);
    bool FUN_140690fa0(int type, int sub, Unk_MailBenefit* out) const;
    void FUN_140691090();
    void FUN_1406910e0(__int64 value);
    __int64 FUN_140691110() const;
    int FUN_140691130();
    __int64 FUN_140691160() const;
    int FUN_140691180() const;
    __int64 FUN_1406911c0() const;
    void FUN_1406911e0(int state);
    int FUN_140691200() const;
    int FUN_140691220();
    void FUN_1406913e0(CInPacket& packet);                    // read the mail body
    CStringW FUN_1406922d0() const;                            // formatted date
    void FUN_1406923a0(int slot, MS2Ptr<CMailAdItem> ad);
    void FUN_140692420(__int64 time);
    MS2Ptr<CMailAdItem> FUN_140692480(int slot) const;
    __int64 FUN_140692510() const;                             // sum of the ads' +0x30
    __int64 FUN_1406925a0() const;                             // sum of the ads' +0x38
    int FUN_140692630() const;
    bool FUN_140692690(int kind) const;
    bool FUN_1406926e0(int kind) const;
    bool FUN_140692720(int kind) const;
    __int64 FUN_140692760() const;
    bool FUN_140690fa0(int type, int sub, Unk_CommonPriceRecord* out) const;   // 0x140690fa0 (the benefit as a price record)
    // @0x1419ea9a0
    Unk_MailBenefitList& FUN_1419ea9a0() { return m_benefits; }   // inline COMDAT (uimaillistdialog.cpp)
    // @0x1419eab80
    CStringW FUN_1419eab80() const { return m_str120; }            // inline COMDAT (uimaillistdialog.cpp): the ad product name
    MS2_LAYOUT_FRIEND;
    __int64 m_nId; int m_nKind; int m_n24; __int64 m_n28;      // +0x18
    CStringW m_str30; __int64 m_n38;                           // +0x30
    CStringW m_str40; CStringW m_str48; CStringW m_str50;
    CStringW m_str58; CStringW m_str60; CStringW m_str68;
    ATL::CAtlArray<Unk_MailAttachPtr> m_attach;                // +0x70 (five slots)
    ATL::CAtlArray<MS2Ptr<CMailAdItem> > m_ads;                // +0x90 (five slots)
    Unk_MailTimeRange m_rangeB0; Unk_MailTimeRange m_rangeC0; Unk_MailTimeRange m_rangeD0;
    Unk_MailBenefitList m_benefits;                            // +0xe0
    __int64 m_n100; __int64 m_n108; __int64 m_n110; __int64 m_n118;
    CStringW m_str120; __int64 m_n128; int m_n130; int m_nState; // +0x120
};
MS2_CHECK_SIZE(CMailInfo, 0x138);
MS2_CHECK_OFFSET(CMailInfo, m_attach, 0x70);
MS2_CHECK_OFFSET(CMailInfo, m_ads, 0x90);
MS2_CHECK_OFFSET(CMailInfo, m_rangeB0, 0xb0);
MS2_CHECK_OFFSET(CMailInfo, m_benefits, 0xe0);
MS2_CHECK_OFFSET(CMailInfo, m_str120, 0x120);
MS2_CHECK_OFFSET(CMailInfo, m_nState, 0x134);
