// CItem: external constructor 0x140523790, allocation size 0x1a0.
#pragma once
#include "ms2/placeholder/ascript.h"   // MS2Ptr<T>
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ms2svrptr.h"
class CItemData;
class CItemStatus;
class CItemUgc;
class CItemGem;
class CItemCustomMusicScore;
class CItemSocket;
class CItemCoupleInfo;
template <class T> class MS2Ptr;
class CItem;
class COutputStream;
class CInputStream;
// The transfer (trade / bind) state of an item, 0x58 bytes (ctor 0x140634820). Member names are invented from use.
class CItemTransfer : public CPtred
{
public:
    class CItemBinding;
    CItemTransfer();                                    // 0x140634820
    virtual ~CItemTransfer();                           // 0x140634930 (scalar deleting 0x140635e80)
    virtual void vfunc_1(COutputStream&);               // 0x140634d00 write
    virtual void vfunc_2(CInputStream&);                // 0x140634e30 read
    unsigned char FUN_1406352b0();
    unsigned char FUN_1406351f0(void*, void*);
    int FUN_140634fa0();
    void FUN_140634fc0(unsigned);
    int FUN_140634fe0();
    void FUN_140635000(unsigned);
    void FUN_140635300();
    MS2Ptr<CItemTransfer> FUN_140634b30();
    void FUN_140634970(CItem*);
    void FUN_140634990(CItem*);
    CItemTransfer& operator=(const CItemTransfer&);     // 0x140635cf0
    int FUN_140634cc0();
    int FUN_140635020();
    int FUN_140635070();
    unsigned FUN_140635100();                           // m_nRule & 8
    int FUN_140635120();                               // has a binding
    CItemBinding* FUN_140635160();                      // the binding
    int FUN_140635190();
    bool FUN_1406351b0();
    void FUN_140635320(bool);
    void FUN_140635350(class PCBase* pPc, CStringW* pName);   // the binding owner name
    int FUN_1406354d0();
    unsigned FUN_140635520();
    int FUN_140635580();
    unsigned FUN_140635590();
    int FUN_140635630();
    unsigned FUN_140635690();
    int FUN_140635770();
    int FUN_140635870();
    int FUN_1406358c0();
    int FUN_140635900();
    bool FUN_140635940();
    bool FUN_140635980(const __int64*);
    bool FUN_140635470(const __int64*);
    void FUN_1406359c0(__int64*, CStringW*);
    void FUN_140635a60();
    static unsigned FUN_140635ae0(int, CItemData*, int);

    CItem* m_pItem;                                     // +0x18 the owner item (not owned)
    unsigned m_nRule;                                   // +0x20 transfer rule mask (0x4, 0x8, 0x10 tested)
    int m_n24;                                          // +0x24
    int m_nType;                                        // +0x28 the data record's transfer type
    unsigned char m_b2C;                                         // +0x2c
    int m_nCount;                                       // +0x30 remaining transfers
    int m_nMax;                                         // +0x34 transfers used
    bool m_b38;                                         // +0x38
    unsigned char m_b39;                                         // +0x39
    unsigned char m_b3A;                                         // +0x3a
    unsigned char m_b3B;                                         // +0x3b
    unsigned char m_b3C;                                         // +0x3c
    unsigned char m_b3D;                                         // +0x3d
    unsigned char m_b3E;                                         // +0x3e
    unsigned char m_b3F;                                         // +0x3f
    unsigned char m_b40;                                         // +0x40
    unsigned char m_b41;                                         // +0x41
    unsigned char m_b42;                                         // +0x42
    MS2Ptr<CItemBinding> m_spBinding;                   // +0x48
};
MS2_CHECK_SIZE(CItemTransfer, 0x58);
typedef MS2SvrPtr<CPtred> Unk_ItemSlot188;   // 16-byte handle (ctor 0x14052c0d0, dtor 0x14027e150)
class Unk_UserProxyItemData;
class COutputStream;
class CInputStream;
class COutputStream;
class Unk_ItemUgcInfo;
class Unk_ItemEquipData;
class Unk_ItemEnchantData;
class Unk_ItemOwnerRef;
class CInPacket;
template <class T> class MS2Ptr;
class CItem : public CPtred {
public:
  CItem();
  virtual ~CItem();
  bool FUN_140523c40(int, int, int);
  Unk_UserProxyItemData *FUN_140527870();

  // Packet serialization declarations appended by a4 (unit_1401f9eb0).
  void FUN_140524ad0(COutputStream&);
  void FUN_140524eb0(CInputStream&);
  __int64 FUN_140526a50();
  void FUN_140526a70(__int64);
  void FUN_140526c10(int);
  int FUN_140526b50();
  void FUN_140526b70(int);
  void FUN_140526c70(int);
  int FUN_140526bd0();
  int FUN_140528840();                    // 0x140528840 (astooltip.cpp)
  int FUN_1405276c0();
  Unk_ItemEquipData* FUN_1405277b0();   // 0x1405277b0
  int FUN_140527760();                  // 0x140527760
  Unk_ItemEquipData* FUN_140527840();   // 0x140527840 the item's data record (equip flags; uiequipiconcontainer.cpp)
  // Inventory ordering accessors, a1 (inventory.cpp).
  int FUN_140525c60();
  __int64 FUN_140528910();
  // Remaining primary slots verified from CItem's exe vftable by a1.
  virtual void vfunc_1();
  virtual void vfunc_2();
  virtual void vfunc_3(int);
  virtual int vfunc_4();
  virtual void vfunc_5(bool);
  int FUN_1405268f0();
  CString FUN_140528590();                // 0x140528590 the item's name (uirewardnotify.cpp)
  int FUN_14052b130(int, int, int);   // can the item be combined with this one (ItemInfoSlot exchange scroll)
  // sb4 (clonecube.cpp): UGC look of the item. The callee returns a byte; callers test eax (declared int there).
  int FUN_140525f10();                   // 0x140525f10 item data at +0xe8 is a UGC item
  Unk_ItemUgcInfo* FUN_1405278d0();       // 0x1405278d0 operator-> of the MS2Ptr at +0x118 (UGC info)
  unsigned __int64 FUN_1405283d0();       // 0x1405283d0 UGC uid of that info (0 when null; avatarcube.cpp)
  CStringW FUN_140527b10();               // 0x140527b10 (uiugccubepalettedialog.cpp)
  void FUN_1405288e0(__int64);            // 0x1405288e0 set the count (uiugccubepalettedialog.cpp)
  class CUgcItemLook* FUN_140528380();    // 0x140528380 the UGC look of the item (ugccubepalette.cpp)
  void FUN_140528300(class CUgcItemLook*);   // 0x140528300 set the UGC look (uiugccubepalettedialog.cpp)
  bool FUN_140528cc0();                   // 0x140528cc0 can be item-locked (unit_1406125d0)
  bool FUN_140528da0();                   // 0x140528da0 can be item-unlocked (unit_1406125d0)
  // uiitemenchantdialog.cpp: enchant-related accessors.
  int FUN_140526fc0();                    // 0x140526fc0 enchant level
  int FUN_1405270a0();                    // 0x1405270a0 enchant exp
  void FUN_140527110(int);                // 0x140527110 set enchant exp
  int FUN_140527270();
  int FUN_140527030();
  Unk_ItemEnchantData* FUN_1405278a0();   // 0x1405278a0 the enchant data object (null when absent)
  Unk_ItemOwnerRef* FUN_140527930();      // 0x140527930 binding owner holder
  unsigned FUN_140527710();               // 0x140527710 item level
  int FUN_14052b2e0(int, int, int, int);  // set up from id, rank, 0, count
  MS2Ptr<CItem> FUN_140524250();          // 0x140524250 copy
  bool FUN_1405277e0(int);
  bool FUN_140528e20();
  int FUN_140528f90(int);
  CStringW FUN_140528160();               // 0x140528160 item name
  int FUN_140526c50();                    // 0x140526c50 count
  int FUN_1405258b0();                    // 0x1405258b0 nonzero: no sell confirm by price (uimessagebox.cpp)
  __int64 FUN_140527670();                // 0x140527670 unit sell price (uimessagebox.cpp)
  void FUN_140526b30(int);                // 0x140526b30 set the owner object id (uibeautyshopstyledialog.cpp)
  void FUN_140528ab0(__int64);            // 0x140528ab0 set the creation time (saved beauty styles)
  __int64 FUN_140528ae0();                // 0x140528ae0 the creation time
  void FUN_1405255e0(CInPacket&);         // 0x1405255e0 read the item body (saved beauty styles)
  // Delegations to the item table row (item.cpp, w74); names are by address.
  int FUN_140525640();
  int FUN_140525870();
  int FUN_140525ca0();
  int FUN_140525db0();
  int FUN_140525e00();
  int FUN_140525e50(int, int);
  int FUN_140525eb0(int, int);
  int FUN_140526010();
  int FUN_140526100();
  int FUN_1405262c0();
  bool FUN_140526320();
  int FUN_140526790(int);
  int FUN_1405267d0(int);
  int FUN_140526810(unsigned short);
  // Scalar accessors (item.cpp, w87): plain field getters/setters; names are by offset.
  int FUN_14052a020();
  void FUN_14052a040(int);
  int FUN_14052a150();
  void FUN_14052a130(int);
  void FUN_1405268d0(int);
  unsigned char FUN_140526930();
  void FUN_140526910(unsigned char);
  int FUN_140526a10();
  void FUN_140526a30(int);
  int FUN_140526970();
  int FUN_1405269b0();
  void FUN_140526990(int);
  __int64 FUN_140526a90();
  void FUN_140526ab0(__int64);
  __int64 FUN_140526ad0();
  void FUN_140526af0(__int64);
  int FUN_140526b10();
  int FUN_140526b90();
  void FUN_140526bf0(int);
  int FUN_140526c30();
  int FUN_140526e40();
  __int64 FUN_140528a90();
  void FUN_140528a60(__int64);
  int FUN_140529260();
  int FUN_140527300();
  void FUN_1405272e0(int);
  int FUN_140527340();
  void FUN_140527320(int);
  int FUN_140528ca0();
  void FUN_140528c80(int);
  __int64 FUN_140528e00();
  void FUN_140528dd0(__int64);
  int FUN_140529070();
  int FUN_140529090();
  __int64 FUN_140528b90();
  void FUN_140528b60(__int64);
  int FUN_140528bd0();
  void FUN_140528bb0(int);
  unsigned short FUN_140528c20();
  void FUN_140528bf0(unsigned short);
  int FUN_140528c60();
  void FUN_140528c40(int);
  unsigned char FUN_140529620();
  int FUN_1405292a0();
  void FUN_140529280(int);
  int FUN_140529640();
  void FUN_140529660(int);
  unsigned char FUN_1405269f0();
  void FUN_1405269d0(unsigned char);
  int FUN_1405291f0();
  // item.cpp (w101): name is the address; return types read from the callers' disassembly.
  int FUN_140525980();
  int FUN_140525a80();
  int FUN_140526190();
  int FUN_140526390();
  int FUN_1405264c0(int, unsigned*);
  int FUN_140526670(int, unsigned*);
  unsigned FUN_140527a90(size_t);
  CString FUN_140528230();
  CStringW FUN_140529410();
  int FUN_140529560();
  CStringW FUN_140529de0();
  CString FUN_140529eb0();
  CString FUN_140529f60(int, int, int, unsigned);
  int FUN_14052a060();
  void FUN_14052b370();
  int FUN_14052b420(unsigned);
  unsigned char FUN_14052b5e0(void*, void*);
  CStringW FUN_140528010();
  bool FUN_140528e80(int, __int64);
  CStringW FUN_1405296c0();
  CStringW FUN_140529890();
  CStringW FUN_140529aa0();
  int FUN_14052afe0();
  bool FUN_14052b760(MS2Ptr<CItem>);
  int FUN_1405299a0();
  CString FUN_140529cb0();
  bool FUN_14052b670(MS2Ptr<CItem>);
  void FUN_14052b870(Unk_ItemSlot188);
  Unk_ItemSlot188 FUN_14052b8c0();
  // item.cpp (w88): name is the address.
  bool FUN_140525680();
  bool FUN_140525730();
  bool FUN_140525790();
  int FUN_1405257f0();
  int FUN_1405258f0();
  int FUN_140525920();
  int FUN_140525950();
  int FUN_1405259e0();
  int FUN_140525a30();
  int FUN_140525c00();
  bool FUN_140527360();                  // w98
  int FUN_1405273a0();               // w98
  void FUN_1405290b0();                  // w98
  bool FUN_140526e60(int, bool);
  bool FUN_140527180(int, bool);
  int FUN_14052a170();                   // w98
  CStringW FUN_14052a4f0();
  int FUN_14052a580(void*);
  bool FUN_140528980();                   // w98
  int FUN_140525cf0();                   // w98
  int FUN_140526060(void*);              // w98
  int FUN_140525f60();
  int FUN_140525fc0();
  int FUN_140526160();
  void FUN_140526470(unsigned);
  void FUN_140526640(unsigned);
  bool FUN_140526850();
  unsigned FUN_140526cc0(int);
  int FUN_140526d30();
  void FUN_140526f50(unsigned, bool);
  int FUN_140527440();
  void FUN_1405273f0(unsigned);
  void FUN_140527490(unsigned);
  unsigned FUN_1405274e0();
  unsigned FUN_140527530();
  int FUN_140527580();
  void FUN_1405275f0();
  __int64 FUN_140527640();
  int FUN_1405279f0();
  unsigned FUN_140527a20();
  unsigned FUN_1405281e0();
  unsigned short FUN_1405282d0();
  int FUN_140528420();
  void FUN_140528470(class CBlueprintItemData*);
  class CBlueprintItemData* FUN_1405284f0();
  __int64 FUN_140528540();
  bool FUN_140528930();
  void FUN_140528b00(const CStringW&);
  CStringW* FUN_140528b40();
  void FUN_140525590(__int64);
  CItemCustomMusicScore* FUN_140527960();
  CItemCustomMusicScore* FUN_140527990();
  CItemSocket* FUN_1405279c0();
  CItemGem* FUN_140527900();
  void FUN_140529210(unsigned, __int64);
  void FUN_1405292c0(const CItemCoupleInfo&);
  void FUN_140529330(const CStringW&);
  __int64 FUN_1405293b0();
  unsigned char FUN_1405294a0();
  void FUN_140529500(const CStringW&);
  CStringW* FUN_140529540();
  void FUN_140529600();
  bool FUN_140529680(int);
  void FUN_140529fd0(CString);
  void FUN_14052a210(unsigned);
  void FUN_14052a230(unsigned);
  void FUN_14052a260(unsigned);
  bool FUN_14052a290(unsigned);
  bool FUN_14052a2d0();
  bool FUN_14052a330();
  bool FUN_14052a390();
  __int64 FUN_14052a480();
  int FUN_14052b340(unsigned);
  bool FUN_14052b710(unsigned*, __int64*);
  unsigned char FUN_14052b630();
private:
  CString m_strName;                    // +0x18
  int m_20;
  int m_24;
  unsigned m_28;
  int m_2c;
  unsigned char m_30;
  char m_pad_31[3];
  int m_34;
  int m_38;
  int m_3c;
  __int64 m_40;
  __int64 m_48;
  __int64 m_50;
  int m_58;
  int m_5c;
  int m_60;
  int m_64;
  int m_68;
  int m_6c;
  int m_70;
  char m_pad_74[12];
  __int64 m_80;
  __int64 m_88;
  __int64 m_90;
  int m_98;
  int m_9c;
  int m_a0;
  int m_a4;
  __int64 m_a8;
  int m_b0;
  int m_b4;
  CStringW m_strB8;                     // +0xb8
  __int64 m_c0;
  int m_c8;
  unsigned short m_cc;
  char m_pad_ce[2];
  int m_d0;
  bool m_d4;
  char m_pad_d5[3];
  int m_d8;
  int m_dc;
  CStringW m_strE0;                     // +0xe0
  MS2Ptr<CItemData> m_spData;           // +0xe8 (the pointer is at +0xf0): the item's table row
  MS2Ptr<CItemStatus> m_spStatus;       // +0xf8 enchant/status block (CItemStatus, 0x48)
  MS2Ptr<Unk_UserProxyItemData> m_spProxy;   // +0x108
  MS2Ptr<CItemUgc> m_spUgc;             // +0x118 (CItemUgc, 0xd8)
  MS2Ptr<CItemGem> m_spGem;             // +0x128 (CItemGem, 0x28)
  MS2Ptr<CItemTransfer> m_spTransfer;   // +0x138 (CItemTransfer, 0x58)
  MS2Ptr<CItemCustomMusicScore> m_spMusic;   // +0x148 (0x78)
  MS2Ptr<CItemSocket> m_spSocket;       // +0x158 (CItemSocket, 0xf0)
  MS2Ptr<CItemCoupleInfo> m_spCouple;   // +0x168 (CItemCoupleInfo, 0x30)
  MS2Ptr<CItemTransfer::CItemBinding> m_spBinding;   // +0x178 (CItemTransfer::CItemBinding, 0x28)
  Unk_ItemSlot188 m_slot188;            // +0x188 (ctor 0x14052c0d0 zeroes +8; dtor 0x14027e150)
  unsigned char m_198;
  char m_pad_199[3];
  int m_19c;
};
MS2_CHECK_SIZE(CItem, 0x1a0);
// Prefix view of the UGC info behind CItem::FUN_1405278d0 (type name unknown; inventory.cpp views the same +0x30
// field as Unk_InventoryStackIdentity::owner).
class Unk_ItemUgcInfo {
public:
  void *m_pad_00[6];
  __int64 m_nUgcUid;                     // +0x30 compared by CloneCube::vfunc_61
  char m_pad_38[0x38];
  CString m_strName;                     // +0x70 cached UGC file name (avatarcube.cpp)
  void FUN_140632200(CItemUgc* pSource); // copy the UGC info of a proxy (uiugcitemeditdialog.cpp)
  int FUN_1406321a0();                   // 0x1406321a0 CItemUgc::FUN_1406321a0 (astooltip.cpp: nonzero = a UGC text exists)
  CString FUN_140632100();               // 0x140632100 CItemUgc::FUN_140632100 (astooltip.cpp: the UGC text)
};
