// MS2-UNIT: commonfiles\item.cpp
// MS2-RANGE: 0x140523790-0x140530640 .text$mn
// MS2-RANGE: 0x1400b9290-0x1400b9410 .text$di
// MS2-RANGE: 0x142c9ab10-0x142c9ab70 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??1?$MS2Ptr@VUnk_IngItem@@@@QEAA@XZ 0x14052c480 ; unique
// MS2-PIN: ?get@?$MS2Ptr@VUnk_PetRow@@@@QEBAPEAVUnk_PetRow@@XZ 0x14052cde0 ; unique
// MS2-PIN: ??B?$MS2Ptr@VUnk_IngItem@@@@QEBAPEAVUnk_IngItem@@XZ 0x14052cdf0 ; unique
// MS2-PIN: ??C?$MS2Ptr@VUnk_IngItem@@@@QEBAPEAVUnk_IngItem@@XZ 0x14052ced0 ; unique
// MS2-PIN: ?Reference@?$MS2Ptr@VCItemData@@@@CAXPEAVCItemData@@@Z 0x14052d520 ; prop
// MS2-PIN: ??$StringFormat@I@@YA?AV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEBDAEBI@Z 0x14052ea30 ; unique
// MS2-PIN: ??8?$MS2SvrPtr@VCIngredientContainer@@@@QEBA_NPEAVCIngredientContainer@@@Z 0x14052f040 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$MS2SvrPtr@VCIngredientContainer@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2SvrPtr@VCIngredientContainer@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x14052f400 ; unique
// MS2-PIN: ??1?$MS2Ptr@VUnk_PetRow@@@@QEAA@XZ 0x14052c420 ; prop: symbols.tsv (hand)
// MS2-PIN: ?Release@?$MS2Ptr@VUnk_PetRow@@@@AEAAXXZ 0x14052d920 ; prop (hand)
// MS2-PINS-END tplpin
// hand pins (w108)
// MS2-PIN: ??8?$MS2Ptr@VUnk_IngItem@@@@QEBA_NPEAVUnk_IngItem@@@Z 0x14052ccc0
// MS2-PIN: ?Release@?$MS2Ptr@VUnk_IngItem@@@@AEAAXXZ 0x14052d9a0
// MS2-PIN: ?get@?$MS2SvrPtr@VCIngredientContainer@@@@QEBAPEAVCIngredientContainer@@XZ 0x14052f0b0
// MS2-PIN: ??B?$MS2SvrPtr@VCIngredientContainer@@@@QEBAPEAVCIngredientContainer@@XZ 0x14052f0d0
// MS2-PIN: ??4?$MS2Ptr@VCItemData@@@@QEAAAEAV0@AEBV0@@Z 0x14052c6f0
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VCItemData@@@@AEAAXPEAX@Z 0x14052dd90
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\item.cpp"
// item.cpp - CItem (commonfiles\item.cpp; the wassert path is e:\build\kr\22_04\ms2code\commonfiles\item.cpp).
// Partial: the plain scalar field accessors. The constructor, serializer and smart-pointer slot helpers are not
// recovered yet (their pointee types and the COMDAT glue are still open).
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/commonfiles/item.h"
#include "ms2/placeholder/cubeiteminfo.h"
#include "ms2/commonfiles/itemdata.h"
#include "ms2/commonfiles/itemenchantinfo.h"
#include "ms2/commonfiles/itemgachaboxtable.h"
#include "ms2/ms2recover.h"
#include "ms2/fmt/format.h"
#include "ms2/commonfiles/stream.h"
// commonstruct_wa.h gives NpcShopItemLife the real handle type; this unit only sees the 16-byte m_slot188, so keep its local stand-in.
#define NpcShopItemLife Unk_WaNpcShopItemLife
#define Unk_ShopLifeRef Unk_WaShopLifeRef
#include "ms2/commonfiles/commonstruct_wa.h"
#undef NpcShopItemLife
#undef Unk_ShopLifeRef
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/ms2format.h"
#include <vector>
#include "hook/ms2hook.h"

class Unk_ItemEquipData : public CItemData
{
public:
    int FUN_14053c620();
    int FUN_14053f0d0(int);
    int FUN_14053f390(int, int);
    int FUN_14053e9e0();
};
class Unk_ItemPriceSvc { public: int FUN_140678760(int, int, int); };
extern Unk_ItemPriceSvc* FUN_1401c0db0();
class Unk_ItemEnchantData : public CItemStatus { public: int FUN_14062ffb0(unsigned, int, int); int FUN_140630290(unsigned, int, int); unsigned short FUN_140630d00(); };
class Unk_ItemOwnerRef : public CItemTransfer {};
extern __int64 FUN_140869440();
extern unsigned FUN_14054b400(ItemModelData*);

// w101 additions: unit-local record types for the table lookups CItem makes (names are descriptive, not original).
class Unk_IngItem : public CPtred { public: bool FUN_14054aca0(); int FUN_14054ace0(); CStringW FUN_14054ad20(); int FUN_14054ad00(); };
class Unk_IngTable { public: MS2Ptr<Unk_IngItem> FUN_1405565f0(int); CString FUN_140557270(int, int, int, unsigned); };
extern Unk_IngTable* FUN_140281980();
extern bool FUN_1403b3c40(const CStringW&, const wchar_t*);
CStringW FUN_1401d0080(const CStringW& strA, const CStringW& strB); // strA + strB
extern void* FUN_140166410();
extern unsigned short FUN_14036dc40(void*);
extern MS2Ptr<CItemData> FUN_14053f870(int);
// @0x14052d230 TSingleton<ItemGachaBoxTable>::GetInstance (s_instance is the exe's DAT_143aaf1d0)
ItemGachaBoxTable* FUN_14052d230();
class NpcShopItemLife : public CPtred { public: Unk_ItemSlot188 FUN_14026eab0(); };   // commonstruct_wa.h has the full class
class Unk_SingletonObj {};
// The UGC model download manager behind DAT_143aaf1d8 (avatarpc.cpp declares the same class).
struct Unk_UgcNullKey { Unk_UgcNullKey(int n); void* m_pad; };   // ctor 0x1401cd100
class Unk_UgcRideeMgr : public Unk_SingletonObj
{
public:
    void FUN_141883df0(MS2Ptr<CItem> spItem, const Unk_UgcNullKey& kKey);
    void FUN_141885880(MS2Ptr<CItem> spItem);
};
class Unk_MusicBookInfo : public CPtred { public: char m_pad18[0x10]; CString m_str28; CStringW FUN_14072c480(); };
class Unk_MusicBookTable { public: MS2Ptr<Unk_MusicBookInfo> FUN_14072cc10(unsigned); };
extern Unk_MusicBookTable* DAT_143aaf1a8;
class Unk_EnchantRates { public: int FUN_140594720(int); int FUN_140594750(int); int FUN_1405947c0(int); };
extern Unk_EnchantRates* DAT_143aaf1b0;
// The pet row table behind DAT_143aaf1c8 (tabcontentspetevolution.cpp declares the same lookup).
class Unk_PetRow : public CPtred { public: int m_n18; };
class Unk_PetRowTable : public Unk_SingletonObj { public: MS2Ptr<Unk_PetRow> FUN_1407290f0(int); };
CStringW FUN_141277a90(CUgcItemLook* pLook, const CStringW& strFallback);
class Unk_ItemSetTable { public: int FUN_140597430(int); };   // behind DAT_143aaf1b8 (FUN_14052d1f0 returns it as void*)
extern void* DAT_143aaf1b8;
void* FUN_140166440();
void FUN_140177a80(void* logger, int level, int category, const wchar_t* fmt, const int& arg);
extern void* DAT_143aaf1c0;
extern Unk_SingletonObj* DAT_143aaf1c8;
extern Unk_SingletonObj* DAT_143aaf1d8;
#define MS2_ASSERT_MSG_AT(line, msg, cond) (void)((!!(cond)) || (_wassert(msg, _CRT_WIDE(MS2_THIS_FILE), (unsigned)(line)), 0))

// @0x14052a020
int CItem::FUN_14052a020()
{
    return m_20;
}
MS2_REPLACE_METHOD(0x14052A020, CItem, FUN_14052a020, 14, 0xA25B27BF);

// @0x14052a040
void CItem::FUN_14052a040(int v)
{
    m_20 = v;
}
MS2_REPLACE_METHOD(0x14052A040, CItem, FUN_14052a040, 22, 0xF6E32213);

// @0x14052a150
int CItem::FUN_14052a150()
{
    return m_24;
}
MS2_REPLACE_METHOD(0x14052A150, CItem, FUN_14052a150, 14, 0xBA6447E3);

// @0x14052a130
void CItem::FUN_14052a130(int v)
{
    m_24 = v;
}
MS2_REPLACE_METHOD(0x14052A130, CItem, FUN_14052a130, 22, 0x5ED7A56F);

// @0x1405268f0
int CItem::FUN_1405268f0()
{
    return m_2c;
}
MS2_REPLACE_METHOD(0x1405268F0, CItem, FUN_1405268f0, 14, 0x6A78E4AB);

// @0x1405268d0
void CItem::FUN_1405268d0(int v)
{
    m_2c = v;
}
MS2_REPLACE_METHOD(0x1405268D0, CItem, FUN_1405268d0, 22, 0x0EEC4237);

// @0x140526930
unsigned char CItem::FUN_140526930()
{
    return m_30;
}
MS2_REPLACE_METHOD(0x140526930, CItem, FUN_140526930, 15, 0x228C1F9D);

// @0x140526910
void CItem::FUN_140526910(unsigned char v)
{
    m_30 = v;
}
MS2_REPLACE_METHOD(0x140526910, CItem, FUN_140526910, 23, 0x09675A9D);

// @0x140526a10
int CItem::FUN_140526a10()
{
    return m_34;
}
MS2_REPLACE_METHOD(0x140526A10, CItem, FUN_140526a10, 14, 0x9A8B24F3);

// @0x140526a30
void CItem::FUN_140526a30(int v)
{
    m_34 = v;
}
MS2_REPLACE_METHOD(0x140526A30, CItem, FUN_140526a30, 22, 0xFEAFFEDF);

// @0x140526970
int CItem::FUN_140526970()
{
    return m_38;
}
MS2_REPLACE_METHOD(0x140526970, CItem, FUN_140526970, 14, 0xB2976B17);

// @0x1405269b0
int CItem::FUN_1405269b0()
{
    return m_3c;
}
MS2_REPLACE_METHOD(0x1405269B0, CItem, FUN_1405269b0, 14, 0xCAA08B3B);

// @0x140526990
void CItem::FUN_140526990(int v)
{
    m_3c = v;
}
MS2_REPLACE_METHOD(0x140526990, CItem, FUN_140526990, 22, 0x2EC56527);

// @0x140526a50
__int64 CItem::FUN_140526a50()
{
    return m_40;
}
MS2_REPLACE_METHOD(0x140526A50, CItem, FUN_140526a50, 15, 0x8B0075C1);

// @0x140526a70
void CItem::FUN_140526a70(__int64 v)
{
    m_40 = v;
}
MS2_REPLACE_METHOD(0x140526A70, CItem, FUN_140526a70, 25, 0x9BEF1163);

// @0x140526a90
__int64 CItem::FUN_140526a90()
{
    return m_48;
}
MS2_REPLACE_METHOD(0x140526A90, CItem, FUN_140526a90, 15, 0x5AEB0F79);

// @0x140526ab0
void CItem::FUN_140526ab0(__int64 v)
{
    m_48 = v;
}
MS2_REPLACE_METHOD(0x140526AB0, CItem, FUN_140526ab0, 25, 0x4C00882B);

// @0x140526ad0
__int64 CItem::FUN_140526ad0()
{
    return m_50;
}
MS2_REPLACE_METHOD(0x140526AD0, CItem, FUN_140526ad0, 15, 0x6B2752D1);

// @0x140526af0
void CItem::FUN_140526af0(__int64 v)
{
    m_50 = v;
}
MS2_REPLACE_METHOD(0x140526AF0, CItem, FUN_140526af0, 25, 0x7C15EE73);

// @0x140526b10
int CItem::FUN_140526b10()
{
    return m_58;
}
MS2_REPLACE_METHOD(0x140526B10, CItem, FUN_140526b10, 14, 0x7245C177);

// @0x140526b30
void CItem::FUN_140526b30(int v)
{
    m_58 = v;
}
MS2_REPLACE_METHOD(0x140526B30, CItem, FUN_140526b30, 22, 0x05E09DEB);

// @0x140526b50
int CItem::FUN_140526b50()
{
    return m_5c;
}
MS2_REPLACE_METHOD(0x140526B50, CItem, FUN_140526b50, 14, 0x8A52079B);

// @0x140526b70
void CItem::FUN_140526b70(int v)
{
    m_5c = v;
}
MS2_REPLACE_METHOD(0x140526B70, CItem, FUN_140526b70, 22, 0x6DD84747);

// @0x140526b90
int CItem::FUN_140526b90()
{
    return m_60;
}
MS2_REPLACE_METHOD(0x140526B90, CItem, FUN_140526b90, 14, 0xA1BBC3FF);

// @0x140526bd0
int CItem::FUN_140526bd0()
{
    return m_64;
}
MS2_REPLACE_METHOD(0x140526BD0, CItem, FUN_140526bd0, 14, 0xB9C4E423);

// @0x140526bf0
void CItem::FUN_140526bf0(int v)
{
    m_64 = v;
}
MS2_REPLACE_METHOD(0x140526BF0, CItem, FUN_140526bf0, 22, 0x5E3B67AF);

// @0x140526c30
int CItem::FUN_140526c30()
{
    return m_68;
}
MS2_REPLACE_METHOD(0x140526C30, CItem, FUN_140526c30, 14, 0xD1D12A47);

// @0x140526c10
void CItem::FUN_140526c10(int v)
{
    m_68 = v;
}
MS2_REPLACE_METHOD(0x140526C10, CItem, FUN_140526c10, 22, 0x2659249B);

// @0x140526c50
int CItem::FUN_140526c50()
{
    return m_6c;
}
MS2_REPLACE_METHOD(0x140526C50, CItem, FUN_140526c50, 14, 0x69D980EB);

// @0x140526e40
int CItem::FUN_140526e40()
{
    return m_70;
}
MS2_REPLACE_METHOD(0x140526E40, CItem, FUN_140526e40, 14, 0x81E2A10F);

// @0x140528910
__int64 CItem::FUN_140528910()
{
    return m_80;
}
MS2_REPLACE_METHOD(0x140528910, CItem, FUN_140528910, 18, 0x841B6891);

// @0x1405288e0
void CItem::FUN_1405288e0(__int64 v)
{
    m_80 = v;
}
MS2_REPLACE_METHOD(0x1405288E0, CItem, FUN_1405288e0, 28, 0xF376627F);

// @0x140528a90
__int64 CItem::FUN_140528a90()
{
    return m_88;
}
MS2_REPLACE_METHOD(0x140528A90, CItem, FUN_140528a90, 18, 0x4EDF9779);

// @0x140528a60
void CItem::FUN_140528a60(__int64 v)
{
    m_88 = v;
}
MS2_REPLACE_METHOD(0x140528A60, CItem, FUN_140528a60, 28, 0x28AF0D97);

// @0x140528ae0
__int64 CItem::FUN_140528ae0()
{
    return m_90;
}
MS2_REPLACE_METHOD(0x140528AE0, CItem, FUN_140528ae0, 18, 0xEE8FE4C1);

// @0x140528ab0
void CItem::FUN_140528ab0(__int64 v)
{
    m_90 = v;
}
MS2_REPLACE_METHOD(0x140528AB0, CItem, FUN_140528ab0, 28, 0x5DEADEAF);

// @0x140529260
int CItem::FUN_140529260()
{
    return m_98;
}
MS2_REPLACE_METHOD(0x140529260, CItem, FUN_140529260, 17, 0xA9AE535B);

// @0x140527300
int CItem::FUN_140527300()
{
    return m_9c;
}
MS2_REPLACE_METHOD(0x140527300, CItem, FUN_140527300, 17, 0x444DCEE7);

// @0x1405272e0
void CItem::FUN_1405272e0(int v)
{
    m_9c = v;
}
MS2_REPLACE_METHOD(0x1405272E0, CItem, FUN_1405272e0, 25, 0x79F379CB);

// @0x140527340
int CItem::FUN_140527340()
{
    return m_a0;
}
MS2_REPLACE_METHOD(0x140527340, CItem, FUN_140527340, 17, 0xB518FD33);

// @0x140527320
void CItem::FUN_140527320(int v)
{
    m_a0 = v;
}
MS2_REPLACE_METHOD(0x140527320, CItem, FUN_140527320, 25, 0x9EB3CF4F);

// @0x140528ca0
int CItem::FUN_140528ca0()
{
    return m_a4;
}
MS2_REPLACE_METHOD(0x140528CA0, CItem, FUN_140528ca0, 17, 0x4FB552BF);

// @0x140528c80
void CItem::FUN_140528c80(int v)
{
    m_a4 = v;
}
MS2_REPLACE_METHOD(0x140528C80, CItem, FUN_140528c80, 25, 0x041453C3);

// @0x140528e00
__int64 CItem::FUN_140528e00()
{
    return m_a8;
}
MS2_REPLACE_METHOD(0x140528E00, CItem, FUN_140528e00, 18, 0x23C88FD9);

// @0x140528dd0
void CItem::FUN_140528dd0(__int64 v)
{
    m_a8 = v;
}
MS2_REPLACE_METHOD(0x140528DD0, CItem, FUN_140528dd0, 28, 0x7D973C77);

// @0x140529070
int CItem::FUN_140529070()
{
    return m_b0;
}
MS2_REPLACE_METHOD(0x140529070, CItem, FUN_140529070, 17, 0x1F8D7963);

// @0x140529090
int CItem::FUN_140529090()
{
    return m_b4;
}
MS2_REPLACE_METHOD(0x140529090, CItem, FUN_140529090, 17, 0xBA29CEEF);

// @0x140528b90
__int64 CItem::FUN_140528b90()
{
    return m_c0;
}
MS2_REPLACE_METHOD(0x140528B90, CItem, FUN_140528b90, 18, 0xADEC8FD1);

// @0x140528b60
void CItem::FUN_140528b60(__int64 v)
{
    m_c0 = v;
}
MS2_REPLACE_METHOD(0x140528B60, CItem, FUN_140528b60, 28, 0xC9A2153F);

// @0x140528bd0
int CItem::FUN_140528bd0()
{
    return m_c8;
}
MS2_REPLACE_METHOD(0x140528BD0, CItem, FUN_140528bd0, 17, 0x690E246B);

// @0x140528bb0
void CItem::FUN_140528bb0(int v)
{
    m_c8 = v;
}
MS2_REPLACE_METHOD(0x140528BB0, CItem, FUN_140528bb0, 25, 0xA8D572C7);

// @0x140528c20
unsigned short CItem::FUN_140528c20()
{
    return m_cc;
}
MS2_REPLACE_METHOD(0x140528C20, CItem, FUN_140528c20, 18, 0xB3C569C6);

// @0x140528bf0
void CItem::FUN_140528bf0(unsigned short v)
{
    m_cc = v;
}
MS2_REPLACE_METHOD(0x140528BF0, CItem, FUN_140528bf0, 28, 0xF1E0B56E);

// @0x140528c60
int CItem::FUN_140528c60()
{
    return m_d0;
}
MS2_REPLACE_METHOD(0x140528C60, CItem, FUN_140528c60, 17, 0x9E46CF83);

// @0x140528c40
void CItem::FUN_140528c40(int v)
{
    m_d0 = v;
}
MS2_REPLACE_METHOD(0x140528C40, CItem, FUN_140528c40, 25, 0x09284B7F);

// @0x140529620
unsigned char CItem::FUN_140529620()
{
    return m_d4;
}
MS2_REPLACE_METHOD(0x140529620, CItem, FUN_140529620, 18, 0x9D8408D9);

// @0x1405292a0
int CItem::FUN_1405292a0()
{
    return m_d8;
}
MS2_REPLACE_METHOD(0x1405292A0, CItem, FUN_1405292a0, 17, 0xD382A09B);

// @0x140529280
void CItem::FUN_140529280(int v)
{
    m_d8 = v;
}
MS2_REPLACE_METHOD(0x140529280, CItem, FUN_140529280, 25, 0x3E60F697);

// @0x140529640
int CItem::FUN_140529640()
{
    return m_dc;
}
MS2_REPLACE_METHOD(0x140529640, CItem, FUN_140529640, 17, 0x6E1EF627);

// @0x140529660
void CItem::FUN_140529660(int v)
{
    m_dc = v;
}
MS2_REPLACE_METHOD(0x140529660, CItem, FUN_140529660, 25, 0xA3C4A10B);

// @0x1405269f0
unsigned char CItem::FUN_1405269f0()
{
    return m_198;
}
MS2_REPLACE_METHOD(0x1405269F0, CItem, FUN_1405269f0, 18, 0x6158C2DC);

// @0x1405269d0
void CItem::FUN_1405269d0(unsigned char v)
{
    m_198 = v;
}
MS2_REPLACE_METHOD(0x1405269D0, CItem, FUN_1405269d0, 26, 0x4FD40BDC);

// @0x1405291f0
int CItem::FUN_1405291f0()
{
    return m_19c;
}
MS2_REPLACE_METHOD(0x1405291F0, CItem, FUN_1405291f0, 17, 0x1679479E);

// @0x140525640
int CItem::FUN_140525640()
{
    return m_spData->FUN_14053cc40();
}
MS2_REPLACE_METHOD(0x140525640, CItem, FUN_140525640, 44, 0x892B8595);

// @0x140525870
int CItem::FUN_140525870()
{
    return m_spData->FUN_14053d150();
}
MS2_REPLACE_METHOD(0x140525870, CItem, FUN_140525870, 44, 0x1B3AC98C);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x140525ca0
int CItem::FUN_140525ca0()
{
    if (m_spData.IsNull())
        return 0;
    return m_spData->FUN_14053ce20();
}
MS2_REPLACE_METHOD(0x140525CA0, CItem, FUN_140525ca0, 74, 0x4FAA5D2F);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x140525db0
int CItem::FUN_140525db0()
{
    if (m_spData.IsNull())
        return 0;
    return m_spData->FUN_14053d1f0();
}
MS2_REPLACE_METHOD(0x140525DB0, CItem, FUN_140525db0, 74, 0x1FA82CFB);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x140525e00
int CItem::FUN_140525e00()
{
    if (m_spData.IsNull())
        return 0;
    return m_spData->FUN_14053d210();
}
MS2_REPLACE_METHOD(0x140525E00, CItem, FUN_140525e00, 74, 0xAE2063CB);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x140525e50
int CItem::FUN_140525e50(int nGender, int nCategory)
{
    if (!m_spData->FUN_14053cae0(nGender, nCategory))
        return 0;
    return FUN_140525eb0(nGender, nCategory);
}
MS2_REPLACE_METHOD(0x140525E50, CItem, FUN_140525e50, 86, 0xCD65FAD7);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x140525eb0
int CItem::FUN_140525eb0(int nGender, int nB)
{
    if (m_spData.get() == 0)
        return 0;
    return m_spData->FUN_14053c9e0(nGender, nB);
}
MS2_REPLACE_METHOD(0x140525EB0, CItem, FUN_140525eb0, 87, 0x3CF14EF1);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x140526010
int CItem::FUN_140526010()
{
    if (m_spData.get() == 0)
        return 0;
    return m_spData->FUN_14053d900();
}
MS2_REPLACE_METHOD(0x140526010, CItem, FUN_140526010, 72, 0x6813C8A0);

// @0x140526100
int CItem::FUN_140526100()
{
    if (m_spData == 0)
        return 0;
    return m_spData->FUN_14053d8c0();
}
MS2_REPLACE_METHOD(0x140526100, CItem, FUN_140526100, 76, 0x532D60CC);

// @0x1405262c0
int CItem::FUN_1405262c0()
{
    if (m_spData == 0)
        return 0;
    return m_spData->FUN_14053dad0();
}
MS2_REPLACE_METHOD(0x1405262C0, CItem, FUN_1405262c0, 76, 0x8CD26A7C);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x140526320
bool CItem::FUN_140526320()
{
    if (m_spData == 0)
        return false;
    return m_spData->FUN_14053c6f0() == 0x60;
}
MS2_REPLACE_METHOD(0x140526320, CItem, FUN_140526320, 100, 0x95712DC4);

// @0x140526790
int CItem::FUN_140526790(int nJob)
{
    return m_spData->FUN_14053c8e0(nJob);
}
MS2_REPLACE_METHOD(0x140526790, CItem, FUN_140526790, 49, 0xCA42CD40);

// @0x1405267d0
int CItem::FUN_1405267d0(int nGender)
{
    return m_spData->FUN_14053c940(nGender);
}
MS2_REPLACE_METHOD(0x1405267D0, CItem, FUN_1405267d0, 49, 0xC0D977A0);

// @0x140526810
int CItem::FUN_140526810(unsigned short nLevel)
{
    return m_spData->FUN_14053c9a0(nLevel);
}
MS2_REPLACE_METHOD(0x140526810, CItem, FUN_140526810, 51, 0xAFB2B386);

// MS2-PIN: ?IsNull@?$MS2Ptr@VCItemData@@@@QEBA_NXZ 0x1402ffd90

// @0x14052c230
Unk_MusicNoteBlock::Unk_MusicNoteBlock()
{
    FUN_14052d040();
}

// @0x14052d040
void Unk_MusicNoteBlock::FUN_14052d040()
{
    m_n00 = 0;
    m_n08 = 0;
    m_n10 = 0;
    m_str18.Empty();
}
MS2_REPLACE_METHOD(0x14052D040, Unk_MusicNoteBlock, FUN_14052d040, 69, 0x99410530);

// @0x14052c0f0
CItemTransfer::CItemBinding::CItemBinding() : m_n18(0)
{
}

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x14052c4e0
CItemTransfer::CItemBinding::~CItemBinding()
{
}

// @0x14052c140
CItemCoupleInfo::CItemCoupleInfo()
{
    FUN_14052d000();
}

// @0x14052d000
void CItemCoupleInfo::FUN_14052d000()
{
    m_n18 = 0;
    m_str20 = L"";
    m_b28 = 0;
}
MS2_REPLACE_METHOD(0x14052D000, CItemCoupleInfo, FUN_14052d000, 61, 0xDD3E3735);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x14052c510
CItemCoupleInfo::~CItemCoupleInfo()
{
}

// @0x14052c1a0
CItemCustomMusicScore::CItemCustomMusicScore()
{
    FUN_1406328c0();
}

// @0x140523790
CItem::CItem()
    : m_strName("")
    , m_20(0)
    , m_24(-1)
    , m_28(0)
    , m_2c(0)
    , m_30(0)
    , m_34(0)
    , m_38(0)
    , m_3c(0)
    , m_40(0)
    , m_48(0)
    , m_50(0)
    , m_58(0)
    , m_5c(-1)
    , m_60(-1)
    , m_64(0)
    , m_68(0)
    , m_6c(1)
    , m_70(0)
    , m_80(0)
    , m_88(0)
    , m_90(0)
    , m_98(0)
    , m_9c(0)
    , m_a0(0)
    , m_a4(0)
    , m_a8(0)
    , m_b0(0)
    , m_b4(0)
    , m_strB8("")
    , m_c0(0)
    , m_c8(0)
    , m_cc(1)
    , m_d0(0)
    , m_d4(0)
    , m_d8(0)
    , m_dc(0)
    , m_spData(0)
    , m_spStatus(0)
    , m_spProxy(0)
    , m_spUgc(0)
    , m_spGem(0)
    , m_spTransfer(0)
    , m_spMusic(0)
    , m_spCouple(0)
    , m_spBinding(0)
    , m_198(0)
    , m_19c(0)
{
}

// @0x140523b00
CItem::~CItem()
{
}

unsigned char FUN_14053f8c0(unsigned);
unsigned char FUN_14053f940(unsigned);
int FUN_14053f990(unsigned);

// @0x140524240
void CItem::vfunc_1()
{
}
MS2_REPLACE_METHOD(0x140524240, CItem, vfunc_1, 6, 0xA9AF6E37);

// @0x1405268c0
void CItem::vfunc_2()
{
}
MS2_REPLACE_METHOD(0x1405268C0, CItem, vfunc_2, 6, 0xA9AF6E37);

// @0x140526d80
void CItem::vfunc_3(int)
{
    MS2_ASSERT_AT(0x43d, 0);
}
MS2_REPLACE_METHOD(0x140526D80, CItem, vfunc_3, 52, 0x532D3E75);

// @0x140526dc0
int CItem::vfunc_4()
{
    unsigned nCount = FUN_140526c50();
    if (m_198 != 0)
        return nCount > 0 ? nCount - 1 : 0;
    return nCount;
}
MS2_REPLACE_METHOD(0x140526DC0, CItem, vfunc_4, 81, 0x28A974E4);

// @0x140525590
void CItem::FUN_140525590(__int64 n)
{
    m_spProxy->vfunc_5(n);
}
MS2_REPLACE_METHOD(0x140525590, CItem, FUN_140525590, 64, 0xECB9E513);

// @0x1405255e0
void CItem::FUN_1405255e0(CInPacket& pkt)
{
    m_spProxy->vfunc_6(reinterpret_cast<CInputStream*>(reinterpret_cast<char*>(&pkt) + 8));
}
MS2_REPLACE_METHOD(0x1405255E0, CItem, FUN_1405255e0, 81, 0x6811AC4A);

// @0x140525730
bool CItem::FUN_140525730()
{
    if (!FUN_140525680())
        return false;
    CItemCustomMusicScore* pScore = FUN_140527960();
    if (pScore != 0 && pScore->FUN_140632780())
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x140525730, CItem, FUN_140525730, 81, 0x2CA15262);

// @0x140525790
bool CItem::FUN_140525790()
{
    if (!FUN_140525680())
        return false;
    CItemCustomMusicScore* pScore = FUN_140527960();
    if (pScore != 0 && !pScore->FUN_140632780())
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x140525790, CItem, FUN_140525790, 81, 0x1FD1AC30);

// @0x1405257f0
int CItem::FUN_1405257f0()
{
    if (FUN_140527a20() != 0)
        return 0;
    if (FUN_140525c60() != 0 && m_spData->period.usePeriod > 0)
        return 0;
    if (m_spData->property.slotMax > 1)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x1405257F0, CItem, FUN_1405257f0, 115, 0xC01347F9);

// @0x1405258b0
int CItem::FUN_1405258b0()
{
    return m_spData->FUN_14053cf90();
}
MS2_REPLACE_METHOD(0x1405258B0, CItem, FUN_1405258b0, 44, 0x1E0F1D2F);

// @0x1405258f0
int CItem::FUN_1405258f0()
{
    return FUN_14053f8c0(FUN_1405276c0());
}
MS2_REPLACE_METHOD(0x1405258F0, CItem, FUN_1405258f0, 34, 0xB579842C);

// @0x140525920
int CItem::FUN_140525920()
{
    return FUN_14053f940(FUN_1405276c0());
}
MS2_REPLACE_METHOD(0x140525920, CItem, FUN_140525920, 34, 0xA303E991);

// @0x140525950
int CItem::FUN_140525950()
{
    return FUN_14053f990(FUN_1405276c0());
}
MS2_REPLACE_METHOD(0x140525950, CItem, FUN_140525950, 31, 0x537B6C6C);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x1405259e0
int CItem::FUN_1405259e0()
{
    if (m_spData.IsNull())
        return 0;
    return m_spData->FUN_14053ce80();
}
MS2_REPLACE_METHOD(0x1405259E0, CItem, FUN_1405259e0, 74, 0xC931371A);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x140525a30
int CItem::FUN_140525a30()
{
    if (m_spData.IsNull())
        return 0;
    return m_spData->FUN_14053cc00();
}
MS2_REPLACE_METHOD(0x140525A30, CItem, FUN_140525a30, 74, 0xA87C95CD);

// @0x140529210
void CItem::FUN_140529210(unsigned nId, __int64 nCount)
{
    if (nId > 0)
    {
        FUN_1405288e0(nCount);
        m_98 = nId;
    }
}
MS2_REPLACE_METHOD(0x140529210, CItem, FUN_140529210, 60, 0xC03BAF7D);

// @0x1405292c0
void CItem::FUN_1405292c0(const CItemCoupleInfo& src)
{
    MS2_ASSERT_MSG_AT(0xb40, L"m_pCoupleInfo != NULL", m_spCouple.get() != 0);
    *m_spCouple = src;
}
MS2_REPLACE_METHOD(0x1405292C0, CItem, FUN_1405292c0, 103, 0x10173ED6);

// @0x140529330
void CItem::FUN_140529330(const CStringW& str)
{
    MS2_ASSERT_MSG_AT(0xb46, L"m_pCoupleInfo != NULL", m_spCouple.get() != 0);
    m_spCouple->m_str20 = str;
}
MS2_REPLACE_METHOD(0x140529330, CItem, FUN_140529330, 108, 0x6C0038BA);

// @0x1405293b0
__int64 CItem::FUN_1405293b0()
{
    MS2_ASSERT_MSG_AT(0xb34, L"m_pCoupleInfo != NULL", m_spCouple.get() != 0);
    return m_spCouple->m_n18;
}
MS2_REPLACE_METHOD(0x1405293B0, CItem, FUN_1405293b0, 89, 0x8AEEB83D);

// @0x1405294a0
unsigned char CItem::FUN_1405294a0()
{
    MS2_ASSERT_MSG_AT(0xb4c, L"m_pCoupleInfo != NULL", m_spCouple.get() != 0);
    return m_spCouple->m_b28;
}
MS2_REPLACE_METHOD(0x1405294A0, CItem, FUN_1405294a0, 89, 0xB5B90365);

// @0x140529500
void CItem::FUN_140529500(const CStringW& str)
{
    m_strE0 = str;
}
MS2_REPLACE_METHOD(0x140529500, CItem, FUN_140529500, 44, 0x44BD2447);

// @0x140529540
CStringW* CItem::FUN_140529540()
{
    return &m_strE0;
}
MS2_REPLACE_METHOD(0x140529540, CItem, FUN_140529540, 17, 0x8A8CEFA3);

// @0x140529600
void CItem::FUN_140529600()
{
    m_d4 = 1;
}
MS2_REPLACE_METHOD(0x140529600, CItem, FUN_140529600, 18, 0xAAF63E0F);

// @0x140529680
bool CItem::FUN_140529680(int n)
{
    return m_dc == n;
}
MS2_REPLACE_METHOD(0x140529680, CItem, FUN_140529680, 55, 0xA5806025);

// @0x140529fd0
void CItem::FUN_140529fd0(CString str)
{
    m_strName = str;
}
MS2_REPLACE_METHOD(0x140529FD0, CItem, FUN_140529fd0, 63, 0xD01079EB);

// @0x14052a210
void CItem::FUN_14052a210(unsigned n)
{
    m_28 = n;
}
MS2_REPLACE_METHOD(0x14052A210, CItem, FUN_14052a210, 22, 0x26F5625B);

// @0x14052a230
void CItem::FUN_14052a230(unsigned n)
{
    m_28 = m_28 | n;
}
MS2_REPLACE_METHOD(0x14052A230, CItem, FUN_14052a230, 32, 0x19425900);

// @0x14052a260
void CItem::FUN_14052a260(unsigned n)
{
    m_28 = m_28 & ~n;
}
MS2_REPLACE_METHOD(0x14052A260, CItem, FUN_14052a260, 36, 0x2B91A089);

// @0x14052a290
bool CItem::FUN_14052a290(unsigned n)
{
    return (m_28 & n) > 0;
}
MS2_REPLACE_METHOD(0x14052A290, CItem, FUN_14052a290, 56, 0x7063F737);

// @0x14052a2d0
bool CItem::FUN_14052a2d0()
{
    if (FUN_14052a290(1))
        return false;
    return FUN_140525ca0() == 1;
}
MS2_REPLACE_METHOD(0x14052A2D0, CItem, FUN_14052a2d0, 78, 0xF3A5AB3E);

// @0x14052a330
bool CItem::FUN_14052a330()
{
    if (FUN_14052a290(1))
        return false;
    return FUN_140525db0() == 1;
}
MS2_REPLACE_METHOD(0x14052A330, CItem, FUN_14052a330, 78, 0x28AA9D71);

// @0x14052a390
bool CItem::FUN_14052a390()
{
    if (FUN_14052a290(1))
        return false;
    return FUN_140525e00() == 1;
}
MS2_REPLACE_METHOD(0x14052A390, CItem, FUN_14052a390, 78, 0xE7EBFA56);

// @0x14052a480
__int64 CItem::FUN_14052a480()
{
    MS2_ASSERT_MSG_AT(0xc28, L"m_pMoveStoreChar != NULL", m_spBinding.get() != 0);
    return m_spBinding->FUN_14052d1c0();
}
MS2_REPLACE_METHOD(0x14052A480, CItem, FUN_14052a480, 93, 0xC2E28FA1);

// @0x14052b340
int CItem::FUN_14052b340(unsigned n)
{
    m_6c = n;
    return 1;
}
MS2_REPLACE_METHOD(0x14052B340, CItem, FUN_14052b340, 27, 0xE2CA3F90);

// @0x14052b710
bool CItem::FUN_14052b710(unsigned* pA, __int64* pB)
{
    FUN_140528c80(*pA);
    FUN_140528dd0(*pB);
    return true;
}
MS2_REPLACE_METHOD(0x14052B710, CItem, FUN_14052b710, 61, 0x8AB3CC15);

// @0x14052b630
unsigned char CItem::FUN_14052b630()
{
    if (FUN_140527930() == 0)
        return 1;
    return reinterpret_cast<CItemTransfer*>(FUN_140527930())->FUN_1406352b0();
}
MS2_REPLACE_METHOD(0x14052B630, CItem, FUN_14052b630, 51, 0xDD6A277F);

// @0x14052cae0
CItemCoupleInfo& CItemCoupleInfo::operator=(const CItemCoupleInfo& o)
{
    CPtred::operator=(o);
    m_n18 = o.m_n18;
    m_str20 = o.m_str20;
    m_b28 = o.m_b28;
    return *this;
}

// @0x14052d1c0
__int64 CItemTransfer::CItemBinding::FUN_14052d1c0()
{
    return m_n18;
}
MS2_REPLACE_METHOD(0x14052D1C0, CItemTransfer::CItemBinding, FUN_14052d1c0, 15, 0xBBB219C9);

// @0x140527840
Unk_ItemEquipData* CItem::FUN_140527840()
{
    return static_cast<Unk_ItemEquipData*>(m_spData.get());
}
MS2_REPLACE_METHOD(0x140527840, CItem, FUN_140527840, 33, 0xFF365AEE);

// @0x1405277b0
Unk_ItemEquipData* CItem::FUN_1405277b0()
{
    return static_cast<Unk_ItemEquipData*>(m_spData.get());
}
MS2_REPLACE_METHOD(0x1405277B0, CItem, FUN_1405277b0, 33, 0x7099585E);

// @0x140527870
Unk_UserProxyItemData* CItem::FUN_140527870()
{
    return m_spProxy.get();
}
MS2_REPLACE_METHOD(0x140527870, CItem, FUN_140527870, 33, 0x82E03B80);

// @0x1405278a0
Unk_ItemEnchantData* CItem::FUN_1405278a0()
{
    return static_cast<Unk_ItemEnchantData*>(m_spStatus.get());
}
MS2_REPLACE_METHOD(0x1405278A0, CItem, FUN_1405278a0, 33, 0x1C66B116);

// @0x1405278d0
Unk_ItemUgcInfo* CItem::FUN_1405278d0()
{
    return reinterpret_cast<Unk_ItemUgcInfo*>(m_spUgc.get());
}
MS2_REPLACE_METHOD(0x1405278D0, CItem, FUN_1405278d0, 33, 0xF5A6EEE7);

// @0x140527900
CItemGem* CItem::FUN_140527900()
{
    return m_spGem.get();
}
MS2_REPLACE_METHOD(0x140527900, CItem, FUN_140527900, 33, 0xF400AA87);

// @0x140527930
Unk_ItemOwnerRef* CItem::FUN_140527930()
{
    return static_cast<Unk_ItemOwnerRef*>(m_spTransfer.get());
}
MS2_REPLACE_METHOD(0x140527930, CItem, FUN_140527930, 33, 0x70254757);

// @0x140527960
CItemCustomMusicScore* CItem::FUN_140527960()
{
    return m_spMusic.get();
}
MS2_REPLACE_METHOD(0x140527960, CItem, FUN_140527960, 33, 0xD0F5E797);

// @0x140527990
CItemCustomMusicScore* CItem::FUN_140527990()
{
    return m_spMusic.get();
}
MS2_REPLACE_METHOD(0x140527990, CItem, FUN_140527990, 33, 0xC78B125C);

// @0x1405279c0
CItemSocket* CItem::FUN_1405279c0()
{
    return m_spSocket.get();
}
MS2_REPLACE_METHOD(0x1405279C0, CItem, FUN_1405279c0, 33, 0x830CFC5C);

// @0x1405279f0
int CItem::FUN_1405279f0()
{
    if (FUN_140525680())
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1405279F0, CItem, FUN_1405279f0, 40, 0x27EECBC7);

// @0x140526160
int CItem::FUN_140526160()
{
    if ((unsigned)m_dc > 0)
        return 1;
    else
        return 0;
}
MS2_REPLACE_METHOD(0x140526160, CItem, FUN_140526160, 29, 0x4E475867);

// @0x140526c70
void CItem::FUN_140526c70(int nCount)
{
    m_6c = (unsigned)nCount < FUN_1405281e0() ? nCount : FUN_1405281e0();
}
MS2_REPLACE_METHOD(0x140526C70, CItem, FUN_140526c70, 70, 0x1DBDC687);

// @0x140526cc0
unsigned CItem::FUN_140526cc0(int nAdd)
{
    m_6c = m_6c + nAdd;
    FUN_140526c70((unsigned)m_6c < 0 ? 0 : m_6c);
    return m_6c;
}
MS2_REPLACE_METHOD(0x140526CC0, CItem, FUN_140526cc0, 93, 0x92394BB5);

// @0x140526d30
int CItem::FUN_140526d30()
{
    if (FUN_1405277b0()->FUN_14053cd10())
        return 0x17;
    if (FUN_140525640() != 0)
        return 0x18;
    return 0;
}
MS2_REPLACE_METHOD(0x140526D30, CItem, FUN_140526d30, 69, 0x30D36CF3);

// @0x1405274e0
unsigned CItem::FUN_1405274e0()
{
    if (m_spData == NULL)
        return 0;
    return m_spData->property.rePackingLimitCount;
}
MS2_REPLACE_METHOD(0x1405274E0, CItem, FUN_1405274e0, 71, 0x3C7D6924);

// @0x140527530
unsigned CItem::FUN_140527530()
{
    if (m_spData == NULL)
        return 0;
    return m_spData->property.rePackingItemConsumeCount;
}
MS2_REPLACE_METHOD(0x140527530, CItem, FUN_140527530, 71, 0xB0CECF7D);

// @0x140527580
int CItem::FUN_140527580()
{
    unsigned n;
    if ((int)(FUN_1405274e0() - FUN_140527440()) < 0)
        n = 0;
    else
        n = FUN_1405274e0() - FUN_140527440();
    return n;
}
MS2_REPLACE_METHOD(0x140527580, CItem, FUN_140527580, 100, 0xDED28C8F);

// @0x140527640
__int64 CItem::FUN_140527640()
{
    return FUN_140527670() * (unsigned)m_6c;
}
MS2_REPLACE_METHOD(0x140527640, CItem, FUN_140527640, 36, 0x1268982F);

// @0x140527670
__int64 CItem::FUN_140527670()
{
    return m_spData->FUN_14053ea00(FUN_140526bd0());
}
MS2_REPLACE_METHOD(0x140527670, CItem, FUN_140527670, 59, 0xD7F60E55);

// @0x1405276c0
int CItem::FUN_1405276c0()
{
    if (m_spData != NULL)
        return m_spData->FUN_14053c510();
    return 0;
}
MS2_REPLACE_METHOD(0x1405276C0, CItem, FUN_1405276c0, 69, 0x027BAB5E);

// @0x140527710
unsigned CItem::FUN_140527710()
{
    if (m_spData.get() != 0)
        return m_spData->limit.levelLimit;
    return 0;
}
MS2_REPLACE_METHOD(0x140527710, CItem, FUN_140527710, 67, 0x198C6BCE);

// @0x140527760
int CItem::FUN_140527760()
{
    if (m_spData.get() != 0)
        return m_spData->FUN_14053c600();
    return 0;
}
MS2_REPLACE_METHOD(0x140527760, CItem, FUN_140527760, 69, 0xAC97522B);

// @0x1405277e0
bool CItem::FUN_1405277e0(int n)
{
    if (m_spData.get() != 0)
        return m_spData->FUN_14053c6b0(n);
    return false;
}
MS2_REPLACE_METHOD(0x1405277E0, CItem, FUN_1405277e0, 77, 0x4F881743);

// @0x140527a20
unsigned CItem::FUN_140527a20()
{
    if (m_68 != 0 && m_spData->FUN_14053d510())
        return m_68;
    return FUN_14054b400(m_spData->FUN_14053eba0());
}
MS2_REPLACE_METHOD(0x140527A20, CItem, FUN_140527a20, 104, 0x946235F9);

// @0x1405281e0
unsigned CItem::FUN_1405281e0()
{
    if (m_spData == NULL)
        return 0;
    return m_spData->property.slotMax;
}
MS2_REPLACE_METHOD(0x1405281E0, CItem, FUN_1405281e0, 71, 0xD8B41AF4);

// @0x1405282d0
unsigned short CItem::FUN_1405282d0()
{
    return m_spData->limit.levelLimit;
}
MS2_REPLACE_METHOD(0x1405282D0, CItem, FUN_1405282d0, 40, 0x5F468EB9);

// @0x140528930
bool CItem::FUN_140528930()
{
    __int64 nNow = FUN_140869440();
    if (m_80 > 0 && m_80 <= nNow)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x140528930, CItem, FUN_140528930, 64, 0x2211389E);

// @0x140528b00
void CItem::FUN_140528b00(const CStringW& str)
{
    m_strB8 = str;
}
MS2_REPLACE_METHOD(0x140528B00, CItem, FUN_140528b00, 44, 0x874D4D35);

// @0x140528b40
CStringW* CItem::FUN_140528b40()
{
    return &m_strB8;
}
MS2_REPLACE_METHOD(0x140528B40, CItem, FUN_140528b40, 17, 0x2B7FF74B);

// @0x140528da0
bool CItem::FUN_140528da0()
{
    if (FUN_140528ca0() == 1)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x140528DA0, CItem, FUN_140528da0, 35, 0x83E8C624);

// @0x140528e20
bool CItem::FUN_140528e20()
{
    if (FUN_140528ca0() == 1)
        return true;
    if (FUN_140528ca0() == 0)
    {
        if (FUN_140869440() < FUN_140528e00())
            return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x140528E20, CItem, FUN_140528e20, 83, 0x1359AAF1);

// @0x140525f60
int CItem::FUN_140525f60()
{
    if (m_spUgc == NULL)
        return 0;
    if (m_spUgc.get()->FUN_140632030() > 0)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x140525F60, CItem, FUN_140525f60, 87, 0x14B28FAE);

// ---- w98 batch 1: table-row / UGC delegations
extern bool FUN_1403b3c40(const CStringW&, const wchar_t*);
extern bool FUN_14026d4d0(void*, int, __int64);
extern int g_ItemFunctionFlags[4];   // 0x142d568c0

// @0x140525c00
int CItem::FUN_140525c00()
{
    if (m_spData.IsNull())
        return 0;
    return FUN_1403b3c40(m_spData->function.name, L"StoryBook");
}
MS2_REPLACE_METHOD(0x140525C00, CItem, FUN_140525c00, 87, 0xBF027633);

// @0x140525cf0
int CItem::FUN_140525cf0()
{
    if (m_spData.IsNull())
        return 0;
    int nCount = 4;
    for (int i = 0; i < nCount; i++)
    {
        if (m_spData->FUN_14053eba0()->FUN_14054b450(g_ItemFunctionFlags[i]))
            return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140525CF0, CItem, FUN_140525cf0, 171, 0xC6A23014);

// @0x140525f10
int CItem::FUN_140525f10()
{
    if (m_spData.get() != 0)
        return m_spData->FUN_14053d6f0();
    return 0;
}
MS2_REPLACE_METHOD(0x140525F10, CItem, FUN_140525f10, 72, 0x5D744C7D);

// @0x140525fc0
int CItem::FUN_140525fc0()
{
    if (m_spUgc == NULL)
        return 0;
    return m_spUgc.get()->FUN_1406321d0();
}
MS2_REPLACE_METHOD(0x140525FC0, CItem, FUN_140525fc0, 73, 0xDD20CE3F);

// @0x140526060
int CItem::FUN_140526060(void* pArg)
{
    if (!FUN_140525f10() || !FUN_140525f60())
        return 0;
    CUgcItemLook* pItemLook = FUN_140528380();
    MS2_ASSERT_MSG_AT(0x296, L"pItemLook != NULL", pItemLook != NULL);
    if (FUN_14026d4d0(pArg, pItemLook->m_n34, pItemLook->m_n38))
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x140526060, CItem, FUN_140526060, 145, 0x57D9062C);

// @0x140526850
bool CItem::FUN_140526850()
{
    if (!(!FUN_140527840()->FUN_14053cbc0() && FUN_140526c50() != 1 && FUN_1405257f0() != 0 && !FUN_140528e20()))
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x140526850, CItem, FUN_140526850, 91, 0xCCCB08AA);

// ---- w98 batch 2: status (enchant) / transfer delegations
class Unk_ItemPlusInfo { public: int FUN_1408bbc50(); void FUN_1408bbcb0(int, bool); };

// @0x140526fc0
int CItem::FUN_140526fc0()
{
    if (m_spStatus == NULL)
        return 0;
    CItemEnchantInfo* pInfo = m_spStatus->FUN_140630d60();
    if (pInfo == 0)
        return 0;
    return pInfo->FUN_14058c5f0();
}
MS2_REPLACE_METHOD(0x140526FC0, CItem, FUN_140526fc0, 100, 0xC4F66D3A);

// @0x140527030
int CItem::FUN_140527030()
{
    if (m_spStatus == NULL)
        return 0;
    CItemEnchantInfo* pInfo = m_spStatus->FUN_140630d60();
    if (pInfo == 0)
        return 0;
    return pInfo->FUN_14058c8a0();
}
MS2_REPLACE_METHOD(0x140527030, CItem, FUN_140527030, 100, 0xBD08A65D);

// @0x1405270a0
int CItem::FUN_1405270a0()
{
    if (m_spStatus == NULL)
        return 0;
    CItemEnchantInfo* pInfo = m_spStatus->FUN_140630d60();
    if (pInfo == 0)
        return 0;
    return pInfo->FUN_14058c730();
}
MS2_REPLACE_METHOD(0x1405270A0, CItem, FUN_1405270a0, 100, 0xCC383426);

// @0x140527110
void CItem::FUN_140527110(int nExp)
{
    if (m_spStatus == NULL)
        return;
    CItemEnchantInfo* pInfo = m_spStatus->FUN_140630d60();
    if (pInfo == 0)
        return;
    pInfo->FUN_14058c7c0(nExp);
}
MS2_REPLACE_METHOD(0x140527110, CItem, FUN_140527110, 104, 0x12B5FEE3);

// @0x140527270
int CItem::FUN_140527270()
{
    if (m_spStatus == NULL)
        return 0;
    Unk_ItemPlusInfo* pInfo = m_spStatus->FUN_140630d90();
    if (pInfo == 0)
        return 0;
    return pInfo->FUN_1408bbc50();
}
MS2_REPLACE_METHOD(0x140527270, CItem, FUN_140527270, 100, 0x46C766FE);

// @0x140527360
bool CItem::FUN_140527360()
{
    if (m_a0 > 0)
    {
        m_a0 = m_a0 - 1;
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x140527360, CItem, FUN_140527360, 50, 0x6B1F3D35);

// @0x1405273a0
int CItem::FUN_1405273a0()
{
    if (m_spTransfer.get() != 0)
        return m_spTransfer->FUN_140634fa0();
    return 0;
}
MS2_REPLACE_METHOD(0x1405273A0, CItem, FUN_1405273a0, 69, 0xCE7A4785);

// @0x1405273f0
void CItem::FUN_1405273f0(unsigned n)
{
    if (m_spTransfer.get() != 0)
        m_spTransfer->FUN_140634fc0(n);
}
MS2_REPLACE_METHOD(0x1405273F0, CItem, FUN_1405273f0, 73, 0x5F564C20);

// @0x140527440
int CItem::FUN_140527440()
{
    if (m_spTransfer.get() != 0)
        return m_spTransfer->FUN_140634fe0();
    return 0;
}
MS2_REPLACE_METHOD(0x140527440, CItem, FUN_140527440, 69, 0xFB6124AE);

// @0x140527490
void CItem::FUN_140527490(unsigned n)
{
    if (m_spTransfer.get() != 0)
        m_spTransfer->FUN_140635000(n);
}
MS2_REPLACE_METHOD(0x140527490, CItem, FUN_140527490, 73, 0xB4A0DF13);

// @0x1405275f0
void CItem::FUN_1405275f0()
{
    if (m_spTransfer.get() != 0)
        m_spTransfer->FUN_140635300();
}
MS2_REPLACE_METHOD(0x1405275F0, CItem, FUN_1405275f0, 65, 0x42D1E6C9);

// @0x1405290b0
void CItem::FUN_1405290b0()
{
    if (!FUN_140527840()->FUN_14053cbc0())
    {
        m_b4 = 0;
        m_b0 = 0;
        return;
    }
    int nA = FUN_140526bd0();
    int nB = FUN_140527840()->FUN_14053c620();
    int nLevel = FUN_140526fc0();
    int nBase = FUN_140527840()->FUN_14053f0d0(nA);
    m_b4 = FUN_140527840()->FUN_14053f390(nBase, nLevel);
    int nPlus = FUN_140527270();
    if (0 < nPlus)
    {
        int nExtra = FUN_140527840()->FUN_14053e9e0();
        int nBonus = FUN_1401c0db0()->FUN_140678760(nPlus, nExtra, nB);
        m_b4 = m_b4 + nBonus;
    }
    m_b0 = m_b4 + nBase;
}
MS2_REPLACE_METHOD(0x1405290B0, CItem, FUN_1405290b0, 314, 0x1A68A1AB);

// @0x140526e60
bool CItem::FUN_140526e60(int nLevel, bool bFlag)
{
    if (m_spStatus == NULL)
    {
        MS2_ASSERT_MSG_AT(0xca8, L"FALSE", false);
        return false;
    }
    CItemEnchantInfo* pInfo = m_spStatus->FUN_140630d60();
    if (pInfo == 0)
    {
        MS2_ASSERT_MSG_AT(0xcaf, L"FALSE", false);
        return false;
    }
    pInfo->FUN_14058c6b0(nLevel, bFlag);
    if (bFlag)
    {
        FUN_1405290b0();
        vfunc_5(true);
    }
    return true;
}
MS2_REPLACE_METHOD(0x140526E60, CItem, FUN_140526e60, 229, 0x7BD37AA2);

// @0x140527180
bool CItem::FUN_140527180(int nLevel, bool bFlag)
{
    if (m_spStatus == NULL)
    {
        MS2_ASSERT_MSG_AT(0xcf6, L"FALSE", false);
        return false;
    }
    Unk_ItemPlusInfo* pInfo = m_spStatus->FUN_140630d90();
    if (pInfo == 0)
    {
        MS2_ASSERT_MSG_AT(0xcfd, L"FALSE", false);
        return false;
    }
    pInfo->FUN_1408bbcb0(nLevel, bFlag);
    if (bFlag)
    {
        FUN_1405290b0();
        vfunc_5(true);
    }
    return true;
}
MS2_REPLACE_METHOD(0x140527180, CItem, FUN_140527180, 229, 0x6E805001);

// @0x140526f50
void CItem::FUN_140526f50(unsigned nLevel, bool bFlag)
{
    if (!FUN_140526e60(nLevel, bFlag))
        return;
    CItemEnchantInfo* pInfo = FUN_1405278a0()->FUN_140630d60();
    if (pInfo != 0)
        pInfo->FUN_14058c830();
}
MS2_REPLACE_METHOD(0x140526F50, CItem, FUN_140526f50, 93, 0x5DBC915F);

// @0x14052a170
int CItem::FUN_14052a170()
{
    if (m_24 != -1)
        return m_24;
    int nKind = 0;
    if (FUN_140527840()->FUN_14053cf90())
        nKind = 1;
    else if (FUN_140527840()->FUN_14053e130())
        nKind = 0;
    else if (FUN_140527840()->property.flag08 != 0)
        nKind = 3;
    return nKind;
}
MS2_REPLACE_METHOD(0x14052A170, CItem, FUN_14052a170, 143, 0xF8F11542);

// @0x14052a3f0
bool FUN_14052a3f0(int nA, __int64 nB, int nC, int nD, int nE)
{
    bool bResult = false;
    if (nA != 0 && nB > 0)
        bResult = true;
    else if (nD != 0)
    {
        if (nD == 3 && nC == 1)
            bResult = true;
        else if (nD == 4 && nC == 2)
            bResult = true;
    }
    else
    {
        if (nE != 0 && nC != 0 && nE == nC)
            bResult = true;
    }
    return bResult;
}

// @0x14052a4f0
CStringW CItem::FUN_14052a4f0()
{
    MS2_ASSERT_MSG_AT(0xc2e, L"m_pMoveStoreChar != NULL", m_spBinding.get() != 0);
    return m_spBinding->FUN_14052d1b0();
}
MS2_REPLACE_METHOD(0x14052A4F0, CItem, FUN_14052a4f0, 136, 0x2B76F1F7);

// @0x14052a580
int CItem::FUN_14052a580(void* pArg)
{
    MS2_ASSERT_MSG_AT(0xc34, L"m_pMoveStoreChar != NULL", m_spBinding.get() != 0);
    if (m_spBinding->FUN_14052d1c0() == 0)
        return 1;
    return m_spBinding->FUN_140634790(pArg);
}
MS2_REPLACE_METHOD(0x14052A580, CItem, FUN_14052a580, 145, 0x2731BEF2);

// @0x14052d1b0
const CStringW& CItemTransfer::CItemBinding::FUN_14052d1b0()
{
    return m_str20;
}

// @0x140528cc0
bool CItem::FUN_140528cc0()
{
    if (FUN_140528ca0() == 1)
        return false;
    if (FUN_140525ca0() == 1)
        return false;
    if (FUN_140525db0() == 1)
        return false;
    if (FUN_140525e00() == 1)
        return false;
    int nType = FUN_140527840()->FUN_14053c5c0();
    switch (nType)
    {
    case 1:
    case 5:
    case 9:
    case 11:
    case 12:
    case 13:
    case 21:
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x140528CC0, CItem, FUN_140528cc0, 178, 0xE2BEDD66);

// @0x140528980
bool CItem::FUN_140528980()
{
    if (FUN_140528930() && FUN_140525640() == 0)
    {
        if (!FUN_140527840()->FUN_14053cde0())
            return false;
    }
    if (FUN_140527840()->FUN_14053cd10())
    {
        if (!FUN_140525730() && FUN_140527340() < 1)
            return false;
        if (FUN_140525680())
        {
            CItemCustomMusicScore* pScore = FUN_140527990();
            if (pScore == 0)
                return false;
            if (pScore->m_n38 != 0 && pScore->m_n38 != 1)
                return false;
        }
    }
    return true;
}
MS2_REPLACE_METHOD(0x140528980, CItem, FUN_140528980, 210, 0xC3F33C70);

// @0x140525680
bool CItem::FUN_140525680()
{
    if (!FUN_1405277b0()->FUN_14053cd10())
        return false;
    MS2Ptr<Unk_IngItem> spIng = FUN_140281980()->FUN_1405565f0(FUN_1405276c0());
    if (spIng == 0)
        return false;
    return spIng->FUN_14054aca0();
}
MS2_REPLACE_METHOD(0x140525680, CItem, FUN_140525680, 170, 0x68FB8AA6);

// @0x140525980
int CItem::FUN_140525980()
{
    return FUN_1405258f0() || FUN_140525920() || FUN_140525950();
}
MS2_REPLACE_METHOD(0x140525980, CItem, FUN_140525980, 78, 0xEC17A787);

// @0x140525a80
int CItem::FUN_140525a80()
{
    if (m_spData.IsNull())
        return 0;
    switch (m_spData->FUN_14053c5c0())
    {
    case 1:
        if (FUN_140525f10() != 0 && FUN_140525f60() == 0)
            return 1;
        break;
    case 2:
    case 5:
    case 9:
    case 0xb:
    case 0xc:
    case 0x18:
        return 1;
    }
    if (m_spData->FUN_14053cd90())
    {
        CStringW* pName = &m_spData->function.name;
        if (FUN_1403b3c40(*pName, L"RecallParty") || FUN_1403b3c40(*pName, L"TreasureMap"))
            return 0;
        return 1;
    }
    if ((unsigned)m_spData->FUN_14053ddb0() > 0)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x140525A80, CItem, FUN_140525a80, 340, 0x9FD5B6B6);

// @0x140526190
int CItem::FUN_140526190()
{
    if (FUN_140526160() == 1)
    {
        GachaBoxDataPtr spBox = FUN_14052d230()->FUN_14059e340(FUN_140529640());
        if (spBox == 0)
            return 0;
        MS2Ptr<CItemData> spCoin = FUN_14053f870(spBox->m_nCoinItemID);
        if (spCoin == 0)
            return 0;
        if (spBox->m_nCoinItemAmount == 0)
            return 0;
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140526190, CItem, FUN_140526190, 294, 0x9B68AECD);

// @0x140526390
int CItem::FUN_140526390()
{
    if (m_spData == 0)
        return 0;
    if (m_spData->FUN_14053e670())
        return 1;
    CItemSocket* pSocket = FUN_1405279c0();
    if (pSocket != 0 && pSocket->FUN_140620de0())
        return 1;
    if (m_spStatus.get() != 0)
    {
        if (m_spStatus->m_spOption->FUN_1405cbc90() != 0)
            return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140526390, CItem, FUN_140526390, 213, 0xDBB250D2);

// @0x140526470
void CItem::FUN_140526470(unsigned nSlot)
{
    unsigned nResult;
    if (FUN_140525640())
        FUN_140526670(nSlot, &nResult);
    else
        FUN_1405264c0(nSlot, &nResult);
}
MS2_REPLACE_METHOD(0x140526470, CItem, FUN_140526470, 72, 0x8C36A151);

// @0x1405264c0
int CItem::FUN_1405264c0(int nSlot, unsigned* pResult)
{
    if (m_spData.IsNull())
    {
        *pResult = 1;
        return false;
    }
    if (FUN_140526bd0() < 4)
    {
        *pResult = 7;
        return false;
    }
    if (!m_spData->FUN_14053d600() && !m_spData->FUN_14053d5c0())
    {
        *pResult = 8;
        return false;
    }
    if (m_spData->limit.levelLimit < FUN_14036dc40(FUN_140166410()))
    {
        *pResult = 4;
        return false;
    }
    if (m_spData->property.remakeDisable == 1)
    {
        *pResult = 2;
        return false;
    }
    if (m_spStatus->m_spOption->FUN_1405cbbb0(nSlot) == 0)
    {
        *pResult = 6;
        return false;
    }
    *pResult = 0;
    return true;
}
MS2_REPLACE_METHOD(0x1405264C0, CItem, FUN_1405264c0, 378, 0x2F4CADF4);

// @0x140526640
void CItem::FUN_140526640(unsigned nSlot)
{
    unsigned nResult;
    FUN_140526670(nSlot, &nResult);
}
MS2_REPLACE_METHOD(0x140526640, CItem, FUN_140526640, 37, 0x01B62087);

// @0x140526670
int CItem::FUN_140526670(int nSlot, unsigned* pResult)
{
    if (m_spData.IsNull())
    {
        *pResult = 1;
        return false;
    }
    if (FUN_140526bd0() < 3)
    {
        *pResult = 7;
        return false;
    }
    if (!m_spData->FUN_14053cc40())
    {
        *pResult = 8;
        return false;
    }
    if (m_spData->property.remakeDisable == 1)
    {
        *pResult = 2;
        return false;
    }
    if (m_spStatus->m_spOption->FUN_1405cbbb0(nSlot) == 0)
    {
        *pResult = 6;
        return false;
    }
    *pResult = 0;
    return true;
}
MS2_REPLACE_METHOD(0x140526670, CItem, FUN_140526670, 273, 0x5F65DE16);

// The TSingleton<T>::GetInstance bodies this unit instantiates (the s_instance statics are the exe's own data).
// @0x14052d1d0
Unk_MusicBookTable* FUN_14052d1d0()
{
    return DAT_143aaf1a8;
}

// @0x14052d1e0
Unk_EnchantRates* FUN_14052d1e0()
{
    return DAT_143aaf1b0;
}

// @0x14052d1f0
void* FUN_14052d1f0()
{
    return DAT_143aaf1b8;
}

// @0x14052d200
void* FUN_14052d200()
{
    return DAT_143aaf1c0;
}

// @0x14052d210
Unk_PetRowTable* FUN_14052d210()
{
    return static_cast<Unk_PetRowTable*>(DAT_143aaf1c8);
}

// @0x14052d220
Unk_UgcRideeMgr* FUN_14052d220()
{
    return static_cast<Unk_UgcRideeMgr*>(DAT_143aaf1d8);
}

// @0x14052d230
ItemGachaBoxTable* FUN_14052d230()
{
    return TSingleton<ItemGachaBoxTable>::s_instance;
}

// ---- w101 batch 3: UGC look accessors, name/category helpers

// @0x140525c60
int CItem::FUN_140525c60()
{
    return 0 < FUN_140528910();
}
MS2_REPLACE_METHOD(0x140525C60, CItem, FUN_140525c60, 51, 0x6105C5B1);

// @0x140527a90
unsigned CItem::FUN_140527a90(size_t nIndex)
{
    if (m_68 != 0 && m_spData->FUN_14053d510())
        return m_68;
    return m_spData->FUN_14053eba0()->FUN_14054b2f0(nIndex)->FUN_1405451a0();
}
MS2_REPLACE_METHOD(0x140527A90, CItem, FUN_140527a90, 122, 0x4D291B02);

// @0x140528230
CString CItem::FUN_140528230()
{
    if (m_spData == NULL)
        return CString("");
    return m_spData->property.category;
}
MS2_REPLACE_METHOD(0x140528230, CItem, FUN_140528230, 146, 0xD05BE2EF);

// @0x140528300
void CItem::FUN_140528300(CUgcItemLook* pLook)
{
    if (pLook == 0)
        return;
    if (FUN_140525f10() == 0 && FUN_140526010() == 0)
        return;
    if (static_cast<CItemUgc*>(m_spUgc) != 0)
        m_spUgc.get()->FUN_140631ff0(pLook);
}
MS2_REPLACE_METHOD(0x140528300, CItem, FUN_140528300, 115, 0x85D67BAB);

// @0x140528380
CUgcItemLook* CItem::FUN_140528380()
{
    if (m_spUgc == NULL)
        return 0;
    return &m_spUgc->m_look;
}
MS2_REPLACE_METHOD(0x140528380, CItem, FUN_140528380, 69, 0x9943DD56);

// @0x1405283d0
unsigned __int64 CItem::FUN_1405283d0()
{
    if (m_spUgc == NULL)
        return 0;
    return m_spUgc.get()->FUN_140632030();
}
MS2_REPLACE_METHOD(0x1405283D0, CItem, FUN_1405283d0, 73, 0x2AB13BCA);

// @0x140528420
int CItem::FUN_140528420()
{
    if (m_spUgc == NULL)
        return 0;
    return m_spUgc.get()->FUN_140632050();
}
MS2_REPLACE_METHOD(0x140528420, CItem, FUN_140528420, 73, 0x96D2DFC9);

// @0x140528470
void CItem::FUN_140528470(CBlueprintItemData* pLook)
{
    if (pLook == 0)
        return;
    if (FUN_140526010() == 0)
        return;
    if (FUN_1405276c0() != 35200000)
        return;
    if (static_cast<CItemUgc*>(m_spUgc) != 0)
        m_spUgc.get()->FUN_140632070(pLook);
}
MS2_REPLACE_METHOD(0x140528470, CItem, FUN_140528470, 120, 0xEA20A929);

// @0x1405284f0
CBlueprintItemData* CItem::FUN_1405284f0()
{
    if (m_spUgc == NULL)
        return 0;
    return &m_spUgc->m_blueprint;
}
MS2_REPLACE_METHOD(0x1405284F0, CItem, FUN_1405284f0, 71, 0x33B685AE);

// @0x140528540
__int64 CItem::FUN_140528540()
{
    if (m_spUgc == NULL)
        return 0;
    return m_spUgc.get()->FUN_1406320c0();
}
MS2_REPLACE_METHOD(0x140528540, CItem, FUN_140528540, 73, 0x78F83810);

// ---- w101 batch 4: couple/gem/effect-name helpers
class Unk_OptionData : public CPtred { public: int FUN_1405d5fe0(int); };
class Unk_OptionMgr { public: MS2Ptr<Unk_OptionData> FUN_1405f6010(int); };
extern Unk_OptionMgr* FUN_140166430();
extern bool FUN_14036d570(void*, int);
extern int FUN_14088de00(MS2Ptr<CItemData>);
extern int FUN_14062d6f0(void*, int, int, MS2Ptr<CItemData>);
extern unsigned FUN_14062d4b0(void*, int, int, MS2Ptr<CItemData>);

// @0x140528840
int CItem::FUN_140528840()
{
    if (static_cast<CItemUgc*>(m_spUgc) != 0 ? true : false)
    {
        if (m_spUgc.get()->FUN_1406320e0() != 0)
            return FUN_14088de00(m_spData);
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140528840, CItem, FUN_140528840, 143, 0x5DF16F86);

// @0x140529410
CStringW CItem::FUN_140529410()
{
    MS2_ASSERT_MSG_AT(0xb3a, L"m_pCoupleInfo != NULL", m_spCouple != NULL);
    return m_spCouple->m_str20;
}
MS2_REPLACE_METHOD(0x140529410, CItem, FUN_140529410, 132, 0x5F30A84A);

// @0x140529560
int CItem::FUN_140529560()
{
    if (!FUN_14036d570(FUN_140166410(), 0x2e))
        return 0;
    if (FUN_140527840() == 0)
        return 0;
    if (!FUN_140527840()->FUN_14053e940())
        return 0;
    if (FUN_140525c60() != 0 && FUN_140527840()->property.socketDataId == 0)
        return 0;
    if ((unsigned)FUN_140529260() > 0)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140529560, CItem, FUN_140529560, 151, 0x8A8E3DC7);

// @0x140529de0
CStringW CItem::FUN_140529de0()
{
    if (FUN_140525a30() == 0)
        return CStringW(L"");
    if (!m_spGem)
        return CStringW(L"");
    return m_spGem->FUN_1405a7d60();
}
MS2_REPLACE_METHOD(0x140529DE0, CItem, FUN_140529de0, 187, 0x2B386C86);

// @0x140529eb0
CString CItem::FUN_140529eb0()
{
    return FUN_140529f60(m_spData->FUN_14053c620(), FUN_140526fc0(), FUN_140527270(), m_spData->effect.enchantShape);
}
MS2_REPLACE_METHOD(0x140529EB0, CItem, FUN_140529eb0, 168, 0xB191BA0F);

// @0x140529f60
CString CItem::FUN_140529f60(int nA, int nB, int nC, unsigned nD)
{
    return FUN_140281980()->FUN_140557270(nA, nB, nC, nD);
}
MS2_REPLACE_METHOD(0x140529F60, CItem, FUN_140529f60, 97, 0xF4F758D0);

// @0x14052a060
int CItem::FUN_14052a060()
{
    MS2Ptr<Unk_OptionData> spOption = FUN_140166430()->FUN_1405f6010(m_spData->FUN_14053eff0(FUN_140526bd0()));
    if (spOption == NULL)
        return 0;
    return spOption->FUN_1405d5fe0(FUN_140526bd0());
}
MS2_REPLACE_METHOD(0x14052A060, CItem, FUN_14052a060, 197, 0x509A0B26);

// @0x14052b370
void CItem::FUN_14052b370()
{
    int nMax = FUN_14062d6f0(FUN_14052d200(), m_spData->property.socketDataId, FUN_140526bd0(),
        MS2Ptr<CItemData>(FUN_140527840()));
    FUN_14052b420(nMax);
}
MS2_REPLACE_METHOD(0x14052B370, CItem, FUN_14052b370, 162, 0x8FD3EAB9);

// @0x14052b420
int CItem::FUN_14052b420(unsigned nMax)
{
    if (!FUN_14036d570(FUN_140166410(), 0x2e))
        return 1;
    if (!FUN_140527840()->FUN_14053cbc0())
        return 1;
    if (FUN_140527840() == 0)
        return 1;
    if (FUN_140525c60() != 0)
        return 1;
    unsigned nCur = FUN_14062d4b0(FUN_14052d200(), m_spData->property.socketDataId, FUN_140526bd0(),
        MS2Ptr<CItemData>(FUN_140527840()));
    unsigned nUse = nCur < nMax ? nCur : nMax;
    MS2Ptr<CItemSocket> spSocket = m_spSocket;
    if (static_cast<CItemSocket*>(spSocket) != 0)
        spSocket->FUN_140620840(nCur, nUse);
    return 1;
}
MS2_REPLACE_METHOD(0x14052B420, CItem, FUN_14052b420, 429, 0x3FB6220B);

// ---- w101 batch 5: binding/slot helpers, string table formatter
CStringW FormatStringId(int nId, const fmt::ArgList& args);   // 0x14028dee0
FMT_VARIADIC_W(CStringW, FormatStringId, int)
template CStringW FormatStringId<CStringW>(int, const CStringW&);   // 0x14052bd00

// The key based back end FUN_14028dfa0 with this unit's own (ushort, CStringW) instance.
CStringW FUN_14028dfa0(const CStringW&, const fmt::ArgList&);
namespace fmt { namespace internal {
struct Unk_WcFormatter { typedef wchar_t Char; };
template <typename T> inline ULongLong wc_make_type(const T& arg) { return MakeValue<Unk_WcFormatter>::type(arg); }
struct Unk_WcArgType {
    ULongLong type;
    Unk_WcArgType() : type(0) {}
    template <typename T> Unk_WcArgType(const T& arg) : type(wc_make_type(arg)) {}
};
inline ULongLong wc_make_type(Unk_WcArgType t0 = Unk_WcArgType(), Unk_WcArgType t1 = Unk_WcArgType(), Unk_WcArgType t2 = Unk_WcArgType(),
                              Unk_WcArgType t3 = Unk_WcArgType(), Unk_WcArgType t4 = Unk_WcArgType(), Unk_WcArgType t5 = Unk_WcArgType(),
                              Unk_WcArgType t6 = Unk_WcArgType(), Unk_WcArgType t7 = Unk_WcArgType(), Unk_WcArgType t8 = Unk_WcArgType(),
                              Unk_WcArgType t9 = Unk_WcArgType(), Unk_WcArgType t10 = Unk_WcArgType(), Unk_WcArgType t11 = Unk_WcArgType(),
                              Unk_WcArgType t12 = Unk_WcArgType(), Unk_WcArgType t13 = Unk_WcArgType(), Unk_WcArgType t14 = Unk_WcArgType()) {
    return t0.type | (t1.type << 4) | (t2.type << 8) | (t3.type << 12) | (t4.type << 16) | (t5.type << 20) |
           (t6.type << 24) | (t7.type << 28) | (t8.type << 32) | (t9.type << 36) | (t10.type << 40) |
           (t11.type << 44) | (t12.type << 48) | (t13.type << 52) | (t14.type << 56);
}
} }
#define WC_REF(n) fmt::internal::MakeValue<fmt::internal::Unk_WcFormatter>(v##n)
#define WC_WRAP(n) \
    template <FMT_GEN(n, FMT_MAKE_TEMPLATE_ARG)> \
    inline CStringW FUN_14028dfa0(CStringW arg1, FMT_GEN(n, FMT_MAKE_ARG)) { \
        const fmt::internal::ArgArray<n>::Type array = {FMT_GEN(n, WC_REF)}; \
        return FUN_14028dfa0(arg1, fmt::ArgList(fmt::internal::wc_make_type(FMT_GEN(n, FMT_MAKE_REF2)), array)); \
    }
WC_WRAP(1)
WC_WRAP(2)
template CStringW FUN_14028dfa0<unsigned short, CStringW>(CStringW, const unsigned short&, const CStringW&);   // 0x14052b9d0

extern int FUN_14052a7e0(MS2Ptr<CItem>, MS2Ptr<CItem>);

// @0x14052b5e0
unsigned char CItem::FUN_14052b5e0(void* pA, void* pB)
{
    if (FUN_140527930() == 0)
        return 0;
    return FUN_140527930()->FUN_1406351f0(pA, pB);
}
MS2_REPLACE_METHOD(0x14052B5E0, CItem, FUN_14052b5e0, 71, 0x6D360F0B);

// @0x14052b670
bool CItem::FUN_14052b670(MS2Ptr<CItem> spItem)
{
    if (spItem == NULL)
        return false;
    __int64 n64 = spItem->FUN_140528e00();
    unsigned n32 = spItem->FUN_140528ca0();
    FUN_14052b710(&n32, &n64);
    return true;
}
MS2_REPLACE_METHOD(0x14052B670, CItem, FUN_14052b670, 154, 0xE6542247);

// @0x14052b870
// MS2-FUNCTIONAL: the by-value parameter's destructor is the folded exe copy 0x14027e150 (outside the unit); the body is identical
void CItem::FUN_14052b870(Unk_ItemSlot188 slot)
{
    m_slot188 = slot;
}

// @0x14052b8c0
Unk_ItemSlot188 CItem::FUN_14052b8c0()
{
    return m_slot188;
}
MS2_REPLACE_METHOD(0x14052B8C0, CItem, FUN_14052b8c0, 67, 0xBDDFB3B2);

// @0x14052b910
int FUN_14052b910(const MS2Ptr<CItem>& rFirst, const MS2Ptr<CItem>& rSecond)
{
    MS2Ptr<CItem> spFirst = rFirst;
    MS2Ptr<CItem> spSecond = rSecond;
    return FUN_14052a7e0(spFirst, spSecond);
}

// ---- w101 batch 6: UGC / gem display names
class Unk_StringTbl { public: CStringW FUN_141811980(int nTable, int nIndex); };
extern Unk_StringTbl* FUN_1401a9d70();
extern CString FUN_14016a5c0(const char* psz, int n);
extern CStringW FUN_14183e9c0(CStringW strName, int nRank);

// @0x140528010
CStringW CItem::FUN_140528010()
{
    CStringW strName = FUN_1401a9d70()->FUN_141811980(1, FUN_1405276c0());
    if (static_cast<CItemUgc*>(m_spUgc) != 0)
    {
        bool bNamed = m_spUgc->m_look.GetLocalPath().GetLength() > 0;
        if (bNamed)
            return m_spUgc->m_look.m_str28;
    }
    return strName;
}
MS2_REPLACE_METHOD(0x140528010, CItem, FUN_140528010, 322, 0x89EAC3CB);

// @0x140527b10
// MS2-FUNCTIONAL: branch layout / pet-name tail ordering differs from the exe
CStringW CItem::FUN_140527b10()
{
    CStringW strName = FUN_1401a9d70()->FUN_141811980(1, FUN_1405276c0());
    if (static_cast<CItemUgc*>(m_spUgc) != 0)
    {
        return FUN_141277a90(&m_spUgc->m_look, strName);
    }
    else if (FUN_140527840()->FUN_14053cd10())
    {
        return FUN_1405296c0();
    }
    else if (FUN_140525640() != 0)
    {
        if (m_strB8.GetLength() > 0)
            strName = m_strB8;
        MS2Ptr<Unk_PetRow> spRow = FUN_14052d210()->FUN_1407290f0(FUN_140527840()->FUN_14053dc60());
        if (spRow.get() == 0)
            return strName;
        if (spRow->m_n18 == 1)
            return FormatStringId(0xcd6, strName);
        return FormatStringId(0xcd5, strName);
    }
    else
    {
        if (m_spData->FUN_14053da20() || m_spData->FUN_14053d9d0())
            return strName;
        if (FUN_140525a30() != 0)
        {
            CStringW strGem = FUN_140529de0();
            if (!strGem.IsEmpty())
                return FUN_1401d0080(strName, strGem); // strName + strGem (exe operator+; clang would import MFC CopyChars)
        }
        unsigned short nUnlimited = FUN_1405278a0()->FUN_140630d90()->FUN_1408bbc50();
        if (nUnlimited != 0)
            return FUN_14028dfa0(CStringW(L"s_word_item_unlimited_enchant"), nUnlimited, strName);
        unsigned short nEnchant = FUN_1405278a0()->FUN_140630d00();
        if (nEnchant != 0)
        {
            CStringW strFormatted;
            strFormatted.Format(L"+%d %s", nEnchant, (LPCWSTR)strName);
            return strFormatted;
        }
        return strName;
    }
}

// @0x140528160
CStringW CItem::FUN_140528160()
{
    return FUN_14183e9c0(FUN_140527b10(), FUN_140526bd0());
}

// @0x140528590
CString CItem::FUN_140528590()
{
    if (m_strName.GetLength() > 0)
        return m_strName;
    if ((static_cast<CItemUgc*>(m_spUgc) != 0 ? true : false) && m_spUgc.get()->FUN_1406320e0() != 0)
    {
        if (m_spUgc->FUN_1406321a0() == 1)
            return m_spData->FUN_14053fdd0();
        return FUN_14016a5c0(m_spUgc->FUN_140632100(), 0);
    }
    if (FUN_140527840()->FUN_14053cd10())
        return FUN_140529cb0();
    if ((static_cast<CItemGem*>(m_spGem) != 0 ? true : false) && m_spGem->FUN_1405a7c60() != 0)
        return FUN_14016a5c0(m_spGem->FUN_1405a7cc0(), 0);
    return m_spData->FUN_14053fdd0();
}
MS2_REPLACE_METHOD(0x140528590, CItem, FUN_140528590, 669, 0x0B183905);

// ---- w101 batch 7: enchant success rate, music/couple names, bind check
// @0x140528e80
bool CItem::FUN_140528e80(int nType, __int64 nTime)
{
    if (FUN_140528ca0() != nType)
        return false;
    if (nType == 1)
    {
        if (FUN_140528e00() == nTime)
            return true;
    }
    else if (nType == 0)
    {
        __int64 nNow = FUN_140869440();
        bool bMine = FUN_140528e00() == 0 || nNow >= FUN_140528e00();
        bool bOther = nTime == 0 || nNow >= nTime;
        if (bMine && bOther)
            return true;
        if (FUN_140528e00() == nTime)
            return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x140528E80, CItem, FUN_140528e80, 254, 0x4CEA5801);

// @0x140528f90
// MS2-FUNCTIONAL: the exe takes no parameter (no home-slot spill of edx) although uiitemenchantdialog passes one; kept for the shared prototype
int CItem::FUN_140528f90(int)
{
    Unk_ItemEnchantData* pEnchant = FUN_1405278a0();
    if (pEnchant == 0)
        return 0;
    CItemEnchantInfo* pInfo = pEnchant->FUN_140630d60();
    if (pInfo == 0)
        return 0;
    int nRate = 0;
    int nLevel = pInfo->FUN_14058c5f0() + 1;
    if (pInfo->FUN_14058c730() != 0)
    {
        switch (pInfo->FUN_14058cdc0())
        {
        case 0:
            nRate = FUN_14052d1e0()->FUN_140594750(nLevel);
            break;
        case 1:
            nRate = FUN_14052d1e0()->FUN_1405947c0(nLevel);
            break;
        }
    }
    else
    {
        nRate = FUN_14052d1e0()->FUN_140594720(nLevel);
    }
    return nRate;
}

// @0x1405296c0
CStringW CItem::FUN_1405296c0()
{
    CStringW strName = FUN_1401a9d70()->FUN_141811980(1, FUN_1405276c0());
    if (!FUN_140527840()->FUN_14053cd10())
        return strName;
    if (FUN_140525680() && (static_cast<CItemCustomMusicScore*>(m_spMusic) != 0 ? true : false))
    {
        if (!m_spMusic->FUN_140632780())
            return m_spMusic->m_str28;
        if (!m_strE0.IsEmpty())
            return m_strE0;
    }
    return strName;
}
MS2_REPLACE_METHOD(0x1405296C0, CItem, FUN_1405296c0, 449, 0xB6D03849);

// ---- w101 batch 8: music book names
// @0x140529890
CStringW CItem::FUN_140529890()
{
    if (!FUN_140527840()->FUN_14053cd10())
        return CStringW(L"");
    if (FUN_140525680())
    {
        if (m_spMusic == NULL)
            return CStringW(L"");
        return m_spMusic->m_str20;
    }
    return CStringW(L"");
}
MS2_REPLACE_METHOD(0x140529890, CItem, FUN_140529890, 261, 0x7DA563E5);

// @0x1405299a0
int CItem::FUN_1405299a0()
{
    if (!FUN_140527840()->FUN_14053cd10())
        return 0;
    if (FUN_140525680())
    {
        if (m_spMusic == NULL)
            return 0;
        return m_spMusic->m_n18;
    }
    MS2Ptr<Unk_IngItem> spIng = FUN_140281980()->FUN_1405565f0(FUN_1405276c0());
    if (spIng == NULL)
        return 0;
    return spIng->FUN_14054ace0();
}
MS2_REPLACE_METHOD(0x1405299A0, CItem, FUN_1405299a0, 250, 0xCFD163E1);

// @0x140529cb0
CString CItem::FUN_140529cb0()
{
    CItemCustomMusicScore* pScore;
    if (FUN_140525680() && (pScore = FUN_140527990()) != 0 && !pScore->FUN_140632780())
    {
        unsigned nBook = m_spMusic->m_n1c;
        MS2Ptr<Unk_MusicBookInfo> spInfo = FUN_14052d1d0()->FUN_14072cc10(nBook);
        if (static_cast<Unk_MusicBookInfo*>(spInfo) != 0)
            return spInfo->m_str28;
    }
    return m_spData->FUN_14053fdd0();
}
MS2_REPLACE_METHOD(0x140529CB0, CItem, FUN_140529cb0, 284, 0x5CFDCA28);

// ---- w101 batch 9: enchant comparison
// @0x14052a620
int FUN_14052a620(MS2Ptr<CItem> spFirst, MS2Ptr<CItem> spSecond)
{
    for (unsigned i = 0; i < 0x23; ++i)
    {
        unsigned nKey = i;
        int nA = spFirst->FUN_1405278a0()->FUN_14062ffb0(nKey, 0, 5);
        int nB = spSecond->FUN_1405278a0()->FUN_14062ffb0(nKey, 0, 5);
        if (nA - nB)
            return 0;
    }
    for (unsigned j = 1; j < 0xcf; ++j)
    {
        unsigned nKey = j;
        int nA = spFirst->FUN_1405278a0()->FUN_140630290(nKey, 0, 5);
        int nB = spSecond->FUN_1405278a0()->FUN_140630290(nKey, 0, 5);
        if (nA - nB)
            return 0;
    }
    return 1;
}

// @0x14052a7e0
// MS2-FUNCTIONAL: behaviour-equivalent; exe keeps the two equip-data pointers in different frame slots (0xa8/0x50 vs 0x50/0x30), frame 0xd8 vs 0xc8
// item ordering (inventory sort comparator): empty first, then category, equip level, enchant level, id, count
int FUN_14052a7e0(MS2Ptr<CItem> spFirst, MS2Ptr<CItem> spSecond)
{
    if (spFirst == 0)
    {
        if (spSecond == 0)
            return 0;
        else
            return 1;
    }
    else if (spSecond == 0)
        return -1;
    Unk_ItemEquipData* pFirst = spFirst->FUN_140527840();
    Unk_ItemEquipData* pSecond = spSecond->FUN_140527840();
    if (pFirst == 0)
    {
        if (pSecond == 0)
            return 0;
        else
            return 1;
    }
    else if (pSecond == 0)
        return -1;
    unsigned nKind[2];
    nKind[0] = spFirst->FUN_14052afe0();
    nKind[1] = spSecond->FUN_14052afe0();
    if (nKind[0] < nKind[1])
        return -1;
    else if (nKind[1] < nKind[0])
        return 1;
    int nLevel[2];
    nLevel[0] = pFirst->FUN_14053c620();
    nLevel[1] = pSecond->FUN_14053c620();
    if (nLevel[0] < nLevel[1])
        return -1;
    else if (nLevel[1] < nLevel[0])
        return 1;
    if (nKind[0] == 2)
    {
        if ((int)pFirst->limit.levelLimit < (int)pSecond->limit.levelLimit)
            return -1;
        if ((int)pSecond->limit.levelLimit < (int)pFirst->limit.levelLimit)
            return 1;
        int nRarity[2];
        nRarity[0] = spFirst->FUN_140526bd0();
        nRarity[1] = spSecond->FUN_140526bd0();
        if (nRarity[0] < nRarity[1])
            return -1;
        if (nRarity[1] < nRarity[0])
            return 1;
    }
    unsigned nId[2];
    nId[0] = spFirst->FUN_1405276c0();
    nId[1] = spSecond->FUN_1405276c0();
    if (nId[0] < nId[1])
        return -1;
    else if (nId[1] < nId[0])
        return 1;
    if (nKind[0] != 1)
    {
        int nCount[2];
        nCount[0] = spFirst->FUN_140526c50();
        nCount[1] = spSecond->FUN_140526c50();
        if (nCount[1] < nCount[0])
            return -1;
        if (nCount[0] < nCount[1])
            return 1;
    }
    unsigned nIdTie[2];
    nIdTie[0] = spFirst->FUN_1405276c0();
    nIdTie[1] = spSecond->FUN_1405276c0();
    if (nIdTie[0] < nIdTie[1])
        return -1;
    else
        return 1;
}

// @0x140529aa0
CStringW CItem::FUN_140529aa0()
{
    if (!FUN_140527840()->FUN_14053cd10())
        return CStringW(L"");
    if (FUN_140525680())
    {
        if (m_spMusic == NULL)
            return CStringW(L"");
        MS2Ptr<Unk_MusicBookInfo> spInfo = FUN_14052d1d0()->FUN_14072cc10(m_spMusic->m_n1c);
        if (spInfo == NULL)
            return CStringW(L"");
        return spInfo->FUN_14072c480();
    }
    MS2Ptr<Unk_IngItem> spIng = FUN_140281980()->FUN_1405565f0(FUN_1405276c0());
    if (spIng == NULL)
        return CStringW(L"");
    return spIng->FUN_14054ad20();
}
MS2_REPLACE_METHOD(0x140529AA0, CItem, FUN_140529aa0, 516, 0x85FDBEFF);

// ---- w101 batch 10: item kind, create, bind
// @0x14052afe0
int CItem::FUN_14052afe0()
{
    int nKind = 0;
    if (m_spData->FUN_14053ce20())
        nKind = 6;
    else if (m_spData->FUN_14053d1f0())
        nKind = 5;
    else if (m_spData->FUN_14053e130())
        nKind = 0;
    else if (m_spData->FUN_14053cf90())
        nKind = 1;
    else if (m_spData->FUN_14053c5c0() == 2)
        nKind = 2;
    else if (m_spData->FUN_14053c5c0() == 4)
        nKind = 4;
    else
        nKind = 3;
    return nKind;
}
MS2_REPLACE_METHOD(0x14052AFE0, CItem, FUN_14052afe0, 303, 0xB587E3F4);

// @0x14052b130
int CItem::FUN_14052b130(int nItemId, int nRarity, int nAmount)
{
    if (!FUN_140523c40(nItemId, nRarity, nAmount))
        return 0;
    m_19c = 1;
    m_spStatus->FUN_1406306f0(nItemId, FUN_140526bd0(), nAmount);
    if (FUN_140527840()->FUN_14053cd10())
    {
        MS2Ptr<Unk_IngItem> spIng = FUN_140281980()->FUN_1405565f0(nItemId);
        if (static_cast<Unk_IngItem*>(spIng) != 0)
            FUN_140527320(spIng->FUN_14054ad00());
    }
    if (FUN_140525a30() != 0 && (static_cast<CItemGem*>(m_spGem) != 0 ? true : false))
        m_spGem->FUN_1405a7020(m_spData->FUN_14053e900(), m_spData->FUN_14053c650());
    return 1;
}
MS2_REPLACE_METHOD(0x14052B130, CItem, FUN_14052b130, 416, 0xB502F344);

// @0x14052b760
bool CItem::FUN_14052b760(MS2Ptr<CItem> spItem)
{
    if (spItem == NULL || spItem->FUN_140527930() == 0)
        return false;
    m_spTransfer = spItem->FUN_140527930()->FUN_140634b30();
    if (static_cast<CItemTransfer*>(m_spTransfer) != 0)
        m_spTransfer->FUN_140634970(this);
    return true;
}
MS2_REPLACE_METHOD(0x14052B760, CItem, FUN_14052b760, 252, 0x53E6689C);

// @0x14052b120
void CItem::vfunc_5(bool)
{
}
MS2_REPLACE_METHOD(0x14052B120, CItem, vfunc_5, 10, 0x208A1D67);

// @0x14052b2e0
int CItem::FUN_14052b2e0(int nItemId, int nRarity, int nAmount, int n6c)
{
    if (!FUN_14052b130(nItemId, nRarity, nAmount))
        return 0;
    m_6c = n6c;
    return 1;
}
MS2_REPLACE_METHOD(0x14052B2E0, CItem, FUN_14052b2e0, 77, 0x982D1C2E);

// @0x140524eb0
// MS2-FUNCTIONAL: the UGC manager call's temporaries (null key, MS2Ptr<CItem>) are laid out differently (the exe hoists both temp addresses and uses an 8-byte-larger frame); behaviour identical
void CItem::FUN_140524eb0(CInputStream& in)
{
    m_6c = in.vfunc_o8_3();
    m_60 = in.vfunc_o8_3();
    m_90 = in.vfunc_o8_4();
    m_80 = in.vfunc_o8_4();
    m_88 = in.vfunc_o8_4();
    m_9c = in.vfunc_o8_3();
    m_a0 = in.vfunc_o8_3();
    m_a4 = in.vfunc_o8_1();
    m_a8 = in.vfunc_o8_4();
    m_d8 = (unsigned short)in.vfunc_o8_2();
    m_d4 = in.vfunc_o8_0();
    m_dc = in.vfunc_o8_3();
    m_spProxy->vfunc_6(&in);
    m_spStatus->FUN_14062fe20(in);
    if ((FUN_140525f10() != 0 || FUN_140526010() != 0) && static_cast<CItemUgc*>(m_spUgc) != 0)
    {
        m_spUgc->FUN_140631fa0(in);
        if (FUN_140525f10() != 0)
        {
            if (m_spUgc->FUN_140632100().GetLength() > 0)
            {
                FUN_14052d220()->FUN_141883df0(MS2Ptr<CItem>(this), Unk_UgcNullKey(0));
            }
        }
        if (FUN_140526010() != 0)
        {
            if (m_spUgc->FUN_140632100().GetLength() > 0)
                FUN_14052d220()->FUN_141885880(MS2Ptr<CItem>(this));
        }
    }
    if (FUN_140525a30() != 0 && static_cast<CItemGem*>(m_spGem) != 0)
        m_spGem->vfunc_4(in);
    if (FUN_140525680() && static_cast<CItemCustomMusicScore*>(m_spMusic) != 0)
        m_spMusic->FUN_140632620(in);
    if (FUN_140525640() != 0)
    {
        m_strB8 = in.vfunc_o8_8();
        m_c0 = in.vfunc_o8_4();
        FUN_140528bb0(in.vfunc_o8_3());
        FUN_140528bf0(in.vfunc_o8_3());
        m_d0 = in.vfunc_o8_1();
    }
    m_spTransfer->vfunc_2(in);
    m_spSocket->FUN_140620700(in);
    m_spCouple->FUN_14052d090(in);
    m_spBinding->FUN_140634700(in);
    FUN_1405290b0();
}

// ---- w101 batch 11: item copy
// @0x140524250
// MS2-FUNCTIONAL: the shop-life ref's operator-> (0x14027f340) and dtor (0x14027e150) are the exe's copies outside the unit; the bytes are identical otherwise
MS2Ptr<CItem> CItem::FUN_140524250()
{
    MS2Ptr<CItem> spNew(new CItem);
    if (!spNew->FUN_140523c40(FUN_1405276c0(), FUN_140526bd0(), 0))
        return MS2Ptr<CItem>(0);
    spNew->m_48 = m_48;
    spNew->m_50 = m_50;
    spNew->m_40 = m_40;
    spNew->m_58 = m_58;
    spNew->m_6c = m_6c;
    spNew->m_5c = m_5c;
    spNew->m_60 = m_60;
    spNew->m_9c = m_9c;
    spNew->m_a0 = m_a0;
    spNew->m_a4 = m_a4;
    spNew->m_a8 = m_a8;
    spNew->m_d8 = m_d8;
    spNew->m_d4 = m_d4;
    spNew->m_dc = m_dc;
    spNew->FUN_1405288e0(FUN_140528910());
    spNew->FUN_140526c10(m_68);
    if (static_cast<CItemStatus*>(m_spStatus) != 0)
        spNew->m_spStatus = m_spStatus->FUN_14062fbc0();
    if (m_spProxy.get() != 0)
        spNew->m_spProxy->vfunc_3(m_spProxy.get());
    if (static_cast<CItemUgc*>(m_spUgc) != 0)
        spNew->m_spUgc = m_spUgc->FUN_140631e80();
    if (static_cast<CItemGem*>(m_spGem) != 0)
        spNew->m_spGem = m_spGem->vfunc_2();
    if (static_cast<CItemTransfer*>(m_spTransfer) != 0)
    {
        spNew->m_spTransfer = m_spTransfer->FUN_140634b30();
        spNew->m_spTransfer->FUN_140634970(spNew.get());
    }
    if (static_cast<CItemCustomMusicScore*>(m_spMusic) != 0)
        spNew->m_spMusic = m_spMusic->FUN_1406322c0();
    if (static_cast<CItemSocket*>(m_spSocket) != 0)
        spNew->m_spSocket = m_spSocket->FUN_140620490();
    if (static_cast<CItemTransfer::CItemBinding*>(m_spBinding) != 0)
    {
        spNew->m_spBinding.AssignRaw(new CItemTransfer::CItemBinding);
        spNew->m_spBinding->FUN_1406347d0(m_spBinding->FUN_14052d1c0(), m_spBinding->FUN_14052d1b0());
    }
    if (static_cast<CPtred*>(m_slot188) != 0)
        spNew->m_slot188 = static_cast<NpcShopItemLife*>(m_slot188.get())->FUN_14026eab0();
    spNew->FUN_1405290b0();
    return spNew;
}

// ---- w101 batch 11: item create
// @0x140523c40
bool CItem::FUN_140523c40(int nItemId, int nRarity, int nStatusArg)
{
    m_spData = FUN_14053f870(nItemId);
    if (m_spData.IsNull())
    {
        FUN_140177a80(FUN_140166440(), 1, 0x13, L"Item 정보를 읽을 수 없습니다.itemID {0}", nItemId);
        return false;
    }
    if (m_spData->FUN_14053c5a0() == 0)
        FUN_140526bf0(nRarity);
    else
        FUN_140526bf0(m_spData->FUN_14053c5a0());
    reinterpret_cast<Unk_PayloadPtr<CItemExtraData>&>(m_spProxy) = m_spData->FUN_14053e6c0();
    m_spStatus.AssignRaw(new CItemStatus(nItemId, FUN_140526bd0(), nStatusArg));
    if (FUN_140525f10() != 0 || FUN_140526010() != 0)
        m_spUgc.AssignRaw(new CItemUgc);
    if (FUN_140525a30() != 0)
        m_spGem.AssignRaw(new CItemGem);
    if (FUN_140525680())
        m_spMusic.AssignRaw(new CItemCustomMusicScore);
    m_spTransfer.AssignRaw(new CItemTransfer);
    m_spTransfer->FUN_140634990(this);
    if (m_spData->FUN_14053d510())
        FUN_140526c10(5);
    else
        FUN_140526c10(FUN_140527a20());
    vfunc_1();
    m_spSocket.AssignRaw(new CItemSocket);
    m_spCouple.AssignRaw(new CItemCoupleInfo);
    FUN_1405290b0();
    m_d8 = static_cast<Unk_ItemSetTable*>(FUN_14052d1f0())->FUN_140597430(nItemId);
    m_spBinding.AssignRaw(new CItemTransfer::CItemBinding);
    vfunc_2();
    return true;
}
MS2_REPLACE_METHOD(0x140523C40, CItem, FUN_140523c40, 1529, 0x46F3A047);

// ---- w101 batch 11: item write
// @0x140524ad0
void CItem::FUN_140524ad0(COutputStream& out)
{
    out.vfunc_o10_3(m_6c);
    out.vfunc_o10_3(m_60);
    out.vfunc_o10_4(m_90);
    out.vfunc_o10_4(m_80);
    out.vfunc_o10_4(m_88);
    out.vfunc_o10_3(m_9c);
    out.vfunc_o10_3(m_a0);
    out.vfunc_o10_1((unsigned char)m_a4);
    out.vfunc_o10_4(m_a8);
    out.vfunc_o10_2((short)m_d8);
    out.vfunc_o10_0(m_d4);
    out.vfunc_o10_3(m_dc);
    m_spProxy->vfunc_5(reinterpret_cast<__int64>(&out));
    m_spStatus->FUN_14062fda0(out);
    if (FUN_140525f10() != 0 || FUN_140526010() != 0)
    {
        if (static_cast<CItemUgc*>(m_spUgc) != 0)
            m_spUgc->FUN_140631f50(out);
    }
    if (FUN_140525a30() != 0)
    {
        if (static_cast<CItemGem*>(m_spGem) != 0)
            m_spGem->vfunc_3(out);
    }
    if (FUN_140525680())
    {
        if (static_cast<CItemCustomMusicScore*>(m_spMusic) != 0)
            m_spMusic->FUN_140632500(out);
    }
    if (FUN_140525640() != 0)
    {
        out.vfunc_o10_8(m_strB8);
        out.vfunc_o10_4(m_c0);
        out.vfunc_o10_3(m_c8);
        out.vfunc_o10_3(m_cc);
        out.vfunc_o10_1((unsigned char)m_d0);
    }
    m_spTransfer->vfunc_1(out);
    m_spSocket->FUN_1406205e0(out);
    m_spCouple->FUN_14052d130(out);
    m_spBinding->FUN_1406346a0(out);
}
MS2_REPLACE_METHOD(0x140524AD0, CItem, FUN_140524ad0, 982, 0x8BA0884C);

// ---- w101 batch 11: couple info streams
// @0x14052d090
void CItemCoupleInfo::FUN_14052d090(CInputStream& in)
{
    m_n18 = in.vfunc_o8_4();
    if (m_n18 != 0)
    {
        m_str20 = in.vfunc_o8_8();
        m_b28 = in.vfunc_o8_0();
    }
}
MS2_REPLACE_METHOD(0x14052D090, CItemCoupleInfo, FUN_14052d090, 159, 0x772E2F30);

// @0x14052d130
void CItemCoupleInfo::FUN_14052d130(COutputStream& out)
{
    out.vfunc_o10_4(m_n18);
    if (m_n18 != 0)
    {
        out.vfunc_o10_8(m_str20);
        out.vfunc_o10_0(m_b28);
    }
}
MS2_REPLACE_METHOD(0x14052D130, CItemCoupleInfo, FUN_14052d130, 118, 0xAC4AF148);

// Two copies of the market sort-key names (the exe emits both arrays in this unit's initializers; names are invented).
static const CString s_sortNames[] = { "None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd" };
static const CString s_sortNamesCopy[] = { "None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd" };

// ---- w106: CItemBreakIngredientTable (itemBreakIngredient.xml and the gacha box coin costs)
// Unrecovered helpers (the same xml loader helpers the other table units use).
class Unk_140165cf0 { public: Unk_140165cf0* FUN_140165cf0(const char*); Unk_140165cf0* FUN_140168650(const char*); };
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
void FUN_14015eb90(void*, int, int, const wchar_t*, const CString&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax
void FUN_140873220(Unk_140165cf0*, const char*, int&);
bool FUN_14028f710(Unk_140165cf0*);                                       // the element is usable
void FUN_14059ec70(ItemGachaBoxTable*, std::vector<GachaBoxDataPtr>&);   // every box of the table
void FUN_140530c90(MS2Ptr<CItemData> spItem, int nGrade, int nEnchant, CIngredientContainer& output);
// Scoped lock helper shared with banktable / logstring: locks on construction when asked, unlocks on exit.
class Unk_1401b4ec0
{
public:
    Unk_1401b4ec0(CLockCriticalSection& lock, int bLock);   // 0x1401b4ec0
    ~Unk_1401b4ec0();                                       // 0x1401b5120
private:
    void* m_p;
};
MS2_CHECK_SIZE(Unk_1401b4ec0, 8);

// @0x14052de30
CItemBreakIngredientTable::CItemBreakIngredientTable()
{
    Reload();
}

// @0x14052df20
CItemBreakIngredientTable::~CItemBreakIngredientTable()
{
}

// @0x14052dfa0
int CItemBreakIngredientTable::Reload()
{
    Unk_1401b4ec0 guard(m_lock, 1);
    LoadBreakItems();
    LoadGachaBoxes();
    return 1;
}

// @0x14052e010
// MS2-FUNCTIONAL: EH-state/temp-CString layout of the XML loader differs from the exe (precedent itemdata.cpp); behaviour matches the decompile
int CItemBreakIngredientTable::LoadBreakItems()
{
    m_mapBreak.RemoveAll();
    CString strPath = FUN_14071a5b0(CString("Table"), CString("itemBreakIngredient.xml"));
    m_spCache = new CCacheData;
    m_spCache->FUN_1401d1160(CString(strPath));
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return 0;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("item"); pNode != 0; pNode = pNode->FUN_140168650("item"))
    {
        if (!FUN_14028f710(pNode))
            continue;
        int nItemId = 0;
        FUN_140873220(pNode, "ItemID", nItemId);
        if (nItemId == 0)
            continue;
        IngredientPtr spIngredients(new CIngredientContainer);
        unsigned n = 1;
        while (true)
        {
            int nIngredientId = 0;
            int nCount = 0;
            CString strId = StringFormat("IngredientItemID{0}", n);
            CString strCount = StringFormat("IngredientCount{0}", n);
            FUN_140873220(pNode, strId, nIngredientId);
            FUN_140873220(pNode, strCount, nCount);
            if (nIngredientId == 0 || nCount == 0)
                break;
            spIngredients->FUN_14026bbf0(nIngredientId, nCount);
            n++;
        }
        m_mapBreak.SetAt(nItemId, spIngredients);
    }
    return 1;
}

// @0x14052e490
int CItemBreakIngredientTable::LoadGachaBoxes()
{
    if (FUN_14052d230() == 0)
        return 0;
    m_mapGacha.RemoveAll();
    std::vector<GachaBoxDataPtr> boxes;
    FUN_14059ec70(FUN_14052d230(), boxes);
    for (size_t i = 0; i < boxes.size(); i++)
    {
        if (boxes[i] == 0)
            continue;
        IngredientPtr spIngredients(new CIngredientContainer);
        spIngredients->FUN_14026bbf0(boxes[i]->m_nCoinItemID, boxes[i]->m_nCoinItemAmount);
        m_mapGacha.SetAt(boxes[i]->m_nRandomBoxID, spIngredients);
    }
    return 1;
}

// @0x14052e650
CItemBreakIngredientTable::IngredientPtr CItemBreakIngredientTable::GetBreakItem(int nItemId)
{
    Unk_1401b4ec0 guard(m_lock, 1);
    if (FUN_1401d1320(m_spCache.get()) != 0)
        LoadBreakItems();
    IngredientPtr spResult(0);
    m_mapBreak.Lookup(nItemId, spResult);
    return spResult;
}
MS2_REPLACE_METHOD(0x14052E650, CItemBreakIngredientTable, GetBreakItem, 203, 0xF14D16F6);

// @0x14052e730
CItemBreakIngredientTable::IngredientPtr CItemBreakIngredientTable::GetGachaBox(int nBoxId)
{
    Unk_1401b4ec0 guard(m_lock, 1);
    if (FUN_1401d1320(m_spCache.get()) != 0)
        LoadGachaBoxes();
    IngredientPtr spResult(0);
    m_mapGacha.Lookup(nBoxId, spResult);
    return spResult;
}

// @0x14052e810
CItemBreakIngredientTable::IngredientPtr CItemBreakIngredientTable::GetIngredients(int nItemId, int nGrade, int nEnchant)
{
    IngredientPtr spResult = GetBreakItem(nItemId);
    if (spResult == 0)
    {
        MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
        if (spItem.get() != 0)
        {
            int nEnableBreak = spItem->limit.enableBreak;
            if (nEnableBreak == 0 || nEnableBreak == 2)
                return spResult;
            if (spItem->FUN_14053cf90())
            {
                spResult = new CIngredientContainer;
                if (spResult.get() != 0)
                    FUN_140530c90(spItem, nGrade, nEnchant, *spResult);
            }
        }
    }
    return spResult;
}
MS2_REPLACE_METHOD(0x14052E810, CItemBreakIngredientTable, GetIngredients, 493, 0x57327929);

// ---- w101 batch 11: MS2Ptr glue instances
template class MS2Ptr<CItemCoupleInfo>;
template class MS2Ptr<CItemTransfer::CItemBinding>;
template class MS2Ptr<CItemCustomMusicScore>;
template class MS2Ptr<CItemSocket>;
template class MS2Ptr<CItemGem>;
template class MS2Ptr<CItemTransfer>;
template class MS2Ptr<CItemUgc>;
template class MS2Ptr<CItemStatus>;
template class MS2Ptr<Unk_IngItem>;
template class MS2Ptr<Unk_MusicBookInfo>;
template class MS2Ptr<CItemOption>;
template class MS2Ptr<CItem>;
template class MS2Ptr<CItemData>;

// UCRT memmove_s (static inline copy pulled in by the container glue above)
// @0x140530520
static __inline errno_t ms2_item_memmove_s(void* const d, size_t const dsz, void const* const s, size_t const ssz)
{
    if (ssz == 0)
        return 0;
    { int e = !!(d != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    { int e = !!(s != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    { int e = !!(dsz >= ssz); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
    memmove(d, s, ssz);
    return 0;
}
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnItemMemmoveS)(void*, size_t, const void*, size_t) = &ms2_item_memmove_s;
