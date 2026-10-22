// item.h - the small CPtred-derived parts of an item (commonfiles\item.cpp): CItemTransfer::CItemBinding,
// CItemCoupleInfo and CItemCustomMusicScore. Header name assumed from the unit path; the CItem slots that hold them
// are declared in ms2/placeholder/citem.h. Member names are by offset.
#pragma once

#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/citem.h"
#include "ms2/commonfiles/itemgem.h"
#include "ms2/placeholder/cubeiteminfo.h"
#include "ms2/placeholder/blueprintitemdata.h"
#include "ms2/commonfiles/itemenchantinfo.h"
#include "ms2/commonfiles/itemoption.h"
#include "ms2/commonfiles/itemsocket.h"
#include "ms2/placeholder/unlimitedenchantinfo.h"
#include <atlcoll.h>
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/ms2svrptr.h"

class Unk_ItemPlusInfo;

// Opaque parts defined in their own units; only the allocation sizes and constructors are known here.
// The status block of an item (CItem +0xf8): the option record, the enchant record and the unlimited-enchant record.
class CItemStatus : public CPtred
{
public:
    CItemStatus(unsigned, unsigned, unsigned);   // 0x14062fa00
    CItemStatus(CItemOption* pOption, CItemEnchantInfo* pEnchant, UnlimitedEnchantInfo* pUnlimited);   // 0x140631ce0
    virtual ~CItemStatus();                      // 0x140633280 (??_G 0x140633450)
    CItemEnchantInfo* FUN_140630d60();           // the enchant record (null when absent)
    Unk_ItemPlusInfo* FUN_140630d90();           // the unlimited-enchant record
    CItemOption* FUN_140630d30();                // the option record
    void FUN_1406306f0(int, int, int);
    void FUN_14062fda0(COutputStream&);
    MS2Ptr<CItemStatus> FUN_14062fbc0();
    void FUN_14062fe20(CInputStream&);
    int FUN_14062fea0(unsigned nType);
    int FUN_14062ff70(unsigned nType);
    int FUN_14062ffb0(unsigned nType, int nWhich, int nSub);
    int FUN_140630290(unsigned nType, int nWhich, int nSub);
    unsigned short FUN_140630d00();
    float FUN_1406303e0(unsigned nType);
    int FUN_1406304b0(int nSub, int nWhich, unsigned nType);
    CStringW FUN_1406305e0(int nSub, unsigned nType, void* pArg);
    bool FUN_140630dc0(int nType);
    bool FUN_140630810();
    void FUN_140630840();
    bool FUN_1406308a0(MS2Ptr<CItemStatus> spOther);   // 0x1406308a0 take over the options of another status

    MS2Ptr<CItemOption> m_spOption;             // +0x18
    Unk_EnchantPtr<CItemEnchantInfo> m_spEnchant;   // +0x28
    MS2Ptr<UnlimitedEnchantInfo> m_spUnlimited;     // +0x38
};
MS2_CHECK_SIZE(CItemStatus, 0x48);
class CItemUgc : public CPtred
{
public:
    CItemUgc();                             // 0x140631d70
    virtual ~CItemUgc();                    // 0x140631de0 (??_G 0x140633490)
    void FUN_140631e50();                   // resets the look
    int FUN_1406321a0();
    int FUN_1406321d0();
    void FUN_140631f50(COutputStream&);
    MS2Ptr<CItemUgc> FUN_140631e80();
    void FUN_140631fa0(CInputStream&);
    void FUN_140631ff0(CUgcItemLook* pLook);
    unsigned __int64 FUN_140632030();                // the ugc id of the look
    int FUN_140632050();
    void FUN_140632070(CBlueprintItemData* pBlueprint);
    __int64 FUN_1406320c0();
    int FUN_1406320e0();
    CString FUN_140632100();
    CStringW FUN_140632150();
    void FUN_140632200(CItemUgc* pSource);
    CUgcItemLook m_look;                    // +0x18
    CBlueprintItemData m_blueprint;         // +0x80
};
MS2_CHECK_SIZE(CItemUgc, 0xd8);
class Unk_UserProxyItemData : public CPtred
{
public:
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3(Unk_UserProxyItemData* pSrc);
    virtual void vfunc_4();
    virtual void vfunc_5(__int64);
    virtual void vfunc_6(CInputStream*);
};

// The music score's note block at +0x50 of CItemCustomMusicScore (ctor 0x14052c230, reset 0x14052d040).
struct Unk_MusicNoteBlock
{
    Unk_MusicNoteBlock();                   // 0x14052c230
    void FUN_14052d040();                   // reset all fields
    int m_n00;
    int m_pad04;
    __int64 m_n08;
    __int64 m_n10;
    CStringW m_str18;
};
MS2_CHECK_OFFSET(Unk_MusicNoteBlock, m_str18, 0x18);

// CItemTransfer::CItemBinding, 0x28 bytes (RTTI CItemTransfer::CItemBinding).
class CItemTransfer::CItemBinding : public CPtred
{
public:
    CItemBinding();                         // 0x14052c0f0
    virtual ~CItemBinding();                // 0x14052c4e0 (??_G 0x14052cf40)

    __int64 m_n18;                          // +0x18
    CStringW m_str20;                       // +0x20
    __int64 FUN_14052d1c0();                // m_n18
    const CStringW& FUN_14052d1b0();        // m_str20
    void FUN_1406346a0(COutputStream&);
    bool FUN_1406347d0(const __int64& nId, const CStringW& strName);
    CItemBinding& operator=(const CItemBinding&);   // 0x140635c90
    void FUN_140634700(CInputStream&);
    bool FUN_140634790(void*);              // elsewhere (itemtransfer)
};
MS2_CHECK_SIZE(CItemTransfer::CItemBinding, 0x28);

// CItemCoupleInfo, 0x30 bytes.
class CItemCoupleInfo : public CPtred
{
public:
    CItemCoupleInfo();                      // 0x14052c140
    virtual ~CItemCoupleInfo();             // 0x14052c510 (??_G 0x14052cf80)
    void FUN_14052d000();                   // reset
    void FUN_14052d090(CInputStream&);      // read from a stream
    void FUN_14052d130(COutputStream&);     // write to a stream
    CItemCoupleInfo& operator=(const CItemCoupleInfo&);   // 0x14052cae0

    __int64 m_n18;                          // +0x18
    CStringW m_str20;                       // +0x20
    bool m_b28;                    // +0x28
};
MS2_CHECK_SIZE(CItemCoupleInfo, 0x30);

// CItemCustomMusicScore, 0x78 bytes. Its destructor is not in item.cpp.
class CItemCustomMusicScore : public CPtred
{
public:
    CItemCustomMusicScore();                // 0x14052c1a0
    bool FUN_140632780();
    void FUN_140632500(COutputStream&);
    MS2Ptr<CItemCustomMusicScore> FUN_1406322c0();
    void FUN_140632620(CInputStream&);
    virtual ~CItemCustomMusicScore();       // (??_G 0x14052cfc0)
    void FUN_1406328c0();                   // reset the score (elsewhere)

    int m_n18;                              // +0x18
    int m_n1c;                              // +0x1c a music book id
    CStringW m_str20;                       // +0x20
    CStringW m_str28;                       // +0x28
    CString m_str30;                        // +0x30
    int m_n38;                              // +0x38 (streamed as a byte)
    int m_pad3c;
    __int64 m_n40;                          // +0x40
    __int64 m_n48;                          // +0x48
    Unk_MusicNoteBlock m_note;              // +0x50
    unsigned m_b70 : 1;                     // +0x70 (cleared by FUN_1406328c0)
    unsigned m_b70b : 1;
    unsigned m_n70c : 30;
    int m_pad74;
    void FUN_1406327c0(const struct Unk_MusicScoreInfo& info);   // copy from a market listing's score (itemsocketsystemutil.cpp)
};
MS2_CHECK_SIZE(CItemCustomMusicScore, 0x78);
MS2_CHECK_OFFSET(CItemCustomMusicScore, m_n48, 0x48);

// CItemBreakIngredientTable (RTTI name), 0xd8 bytes: what breaking an item (itemBreakIngredient.xml) or a gacha box
// yields. Member and method names are invented. TSingleton at +0 (DAT_143aaf1e0); vftable holds the deleting
// destructor only. Both maps are CAtlMap<int, MS2SvrPtr<CIngredientContainer>> with ATL's default sizing.
class CIngredientContainer;
class CItemBreakIngredientTable : public TSingleton<CItemBreakIngredientTable>
{
public:
    typedef MS2SvrPtr<CIngredientContainer> IngredientPtr;
    typedef ATL::CAtlMap<int, IngredientPtr> IngredientMap;

    CItemBreakIngredientTable();            // 0x14052de30
    virtual ~CItemBreakIngredientTable();   // 0x14052df20 (??_G 0x14052f160)

    int Reload();                           // 0x14052dfa0: locked reload of both maps
    int LoadBreakItems();                   // 0x14052e010 itemBreakIngredient.xml
    int LoadGachaBoxes();                   // 0x14052e490 coin cost of every gacha box
    IngredientPtr GetBreakItem(int nItemId);    // 0x14052e650
    IngredientPtr GetGachaBox(int nBoxId);      // 0x14052e730
    IngredientPtr GetIngredients(int nItemId, int nGrade, int nEnchant);    // 0x14052e810

private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;            // +0x08
    MS2Ptr<CCacheData> m_spCache;           // +0x38
    IngredientMap m_mapBreak;               // +0x48 itemID -> ingredients
    IngredientMap m_mapGacha;               // +0x90 gacha box id -> coin cost
};
MS2_CHECK_SIZE(CItemBreakIngredientTable, 0xd8);
MS2_CHECK_OFFSET(CItemBreakIngredientTable, m_lock, 0x08);
MS2_CHECK_OFFSET(CItemBreakIngredientTable, m_spCache, 0x38);
MS2_CHECK_OFFSET(CItemBreakIngredientTable, m_mapBreak, 0x48);
MS2_CHECK_OFFSET(CItemBreakIngredientTable, m_mapGacha, 0x90);
