// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The small CPtred records of the UGC map (house) code:
// UGCMapOptions (two option tables keyed by Unk_CMISKindB), CubeSalable, CubeItemInfo (item id / uid / count + an
// optional uploaded look, with packet read/write and comparison), UGCMapEnterBlockInfo, UGCMapBlock, UserUGCMapInfo
// (the local player's house; set / copy / packet read/write), ObjectWeaponInfo, NoticeCubeInfo and Cube (ctor/dtor,
// item accessors, the look download / image check), plus per-item-id predicates over the item, housing, price and bank
// tables. Follows ugcmapdata.cpp in the exe ("dir commonfiles"); the file name is the unit's guess.
// MS2-UNIT: ?\ugcmapoptions.cpp
// MS2-RANGE: 0x1408b3260-0x1408b9860 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <io.h>
#include <egf/Entity.h>
#include "ugcmapoptions.h"
#include "stream.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/cugcitemlook.h"
#include "ms2/placeholder/cubeiteminfo.h"
#include "ms2/placeholder/userugcmapinfo.h"
#include "ms2/placeholder/cube.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cugcmanager.h"
#include "ms2/commonfiles/itemdatatable.h"
#include "ms2/commonfiles/pricetable.h"
#include "ms2/commonfiles/banktable.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/commonfiles/objectdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "hook/ms2hook.h"

CFeatureManager* FUN_140166410();                           // TSingleton<CFeatureManager>::GetInstance
CItemDataTable* FUN_140281980();                            // TSingleton<CItemDataTable>::GetInstance
CPriceTable* FUN_140552df0();                               // TSingleton<CPriceTable>::GetInstance
CBankTable* FUN_1401b59c0();                                // TSingleton<CBankTable>::GetInstance
CUgcManager* FUN_14052d220();                               // TSingleton<CUgcManager>::GetInstance
MS2Ptr<CItemData> FUN_14053f870(int nItemId);               // the item table record
CStringA FUN_1410280d0(int nPathType, CStringA strName);    // a local resource path
Vector3 FUN_1408a15b0(Unk_Int3 kCell, Vector3& kOffset);   // the world position of a cube cell

// ---- UGCMapOptions -------------------------------------------------------------------------------------------------

// @0x1408b3260
UGCMapOptions::UGCMapOptions()
{
    m_n48 = 10;
    m_n49 = 5;
    m_byteOptions.clear();
    m_intOptions.clear();
    m_n70 = 0;
    m_n74 = 0;
    m_n78 = 0;
    m_f7c = 1.0f;
}

// ---- CubeSalable ---------------------------------------------------------------------------------------------------

// @0x1408b3340
CubeSalable::CubeSalable()
    : m_n18(0), m_n20(0), m_n24(0), m_n28(0), m_n2c(0), m_n30(0), m_n38(0), m_str40(""), m_str48(""), m_n50(0), m_n58(0),
      m_str60(""), m_n68(0), m_n70(0)
{
}

// ---- CubeItemInfo --------------------------------------------------------------------------------------------------

// @0x1408b3450
CubeItemInfo::CubeItemInfo()
{
    FUN_1408b3810();
}

// @0x1408b34b0
CubeItemInfo::CubeItemInfo(const CubeItemInfo& src)
{
    FUN_1408b3810();
    FUN_1408b3700(&src);
}

// @0x1408b3520
CubeItemInfo::CubeItemInfo(int nItemId, __int64 nInstanceId, __int64 nCount, CUgcItemLook* pLook)
{
    FUN_1408b3810();
    itemId = nItemId;
    instanceId = nInstanceId;
    count = nCount;
    if (pLook != 0)
    {
        look.AssignRaw(new CUgcItemLook);
        look->CopyFrom(pLook);
    }
}

// @0x1408b3630
CubeItemInfo::CubeItemInfo(CInPacket& packet)
{
    FUN_1408b3aa0(packet);
}

// @0x1408b36a0
CubeItemInfo::~CubeItemInfo()
{
    FUN_1408b3810();
}

// @0x1408b3700
void CubeItemInfo::FUN_1408b3700(const CubeItemInfo* pSrc)
{
    FUN_1408b3810();
    if (pSrc == 0)
        return;
    itemId = pSrc->itemId;
    instanceId = pSrc->instanceId;
    count = pSrc->count;
    if (pSrc->look.get() != 0)
    {
        look.AssignRaw(new CUgcItemLook);
        look->CopyFrom(pSrc->look.get());
    }
}
MS2_REPLACE_METHOD(0x1408B3700, CubeItemInfo, FUN_1408b3700, 262, 0xD0A2557A);

// Clear.
// @0x1408b3810
void CubeItemInfo::FUN_1408b3810()
{
    itemId = 0;
    instanceId = 0;
    count = 0;
    look = 0;
}
MS2_REPLACE_METHOD(0x1408B3810, CubeItemInfo, FUN_1408b3810, 71, 0x7398FE4F);

// Valid: an item with a downloaded look.
// @0x1408b3860
int CubeItemInfo::FUN_1408b3860() const
{
    if (itemId != 0 && look.get() != 0 && look->m_n18 != 0)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x1408B3860, CubeItemInfo, FUN_1408b3860, 80, 0x061950D6);

// Same cube item: both invalid with the same item id, or both valid with the same item id and look id.
// @0x1408b38c0
int CubeItemInfo::FUN_1408b38c0(const CubeItemInfo* pOther) const
{
    if (pOther == 0)
        return 0;
    if (FUN_1408b3860() == 0)
    {
        if (pOther->FUN_1408b3860() == 1)
            return 0;
        if (pOther->itemId == itemId)
            return 1;
        return 0;
    }
    else
    {
        if (pOther->FUN_1408b3860() == 0)
            return 0;
        if (itemId != pOther->itemId)
            return 0;
        if (look == 0)
            return 0;
        if (look->m_n18 != pOther->look->m_n18)
            return 0;
        return 1;
    }
}
MS2_REPLACE_METHOD(0x1408B38C0, CubeItemInfo, FUN_1408b38c0, 235, 0xC8C20775);

// @0x1408b39c0
void CubeItemInfo::FUN_1408b39c0(COutPacket& packet) const
{
    packet.WriteInt32(itemId);
    packet.WriteInt64(instanceId);
    packet.WriteInt64(count);
    packet.WriteUInt8(look.get() ? 1 : 0);
    if (look.get() != 0)
        look->Write(packet);
}
MS2_REPLACE_METHOD(0x1408B39C0, CubeItemInfo, FUN_1408b39c0, 206, 0x22D53FE2);

// @0x1408b3aa0
void CubeItemInfo::FUN_1408b3aa0(CInPacket& packet)
{
    FUN_1408b3810();
    itemId = packet.ReadInt32();
    instanceId = packet.ReadInt64();
    count = packet.ReadInt64();
    unsigned char bHasLook = packet.ReadUInt8();
    if (bHasLook)
    {
        look.AssignRaw(new CUgcItemLook);
        look->Read(packet);
    }
}
MS2_REPLACE_METHOD(0x1408B3AA0, CubeItemInfo, FUN_1408b3aa0, 387, 0x52A16DB4);

// @0x1408b3c30
void CubeItemInfo::FUN_1408b3c30(COutputStream& stream) const
{
    stream.WriteInt32(itemId);
    stream.WriteInt64(instanceId);
    stream.WriteInt64(count);
    stream.WriteUInt8(look.get() ? 1 : 0);
    if (look.get() != 0)
        look->Write(stream);
}
MS2_REPLACE_METHOD(0x1408B3C30, CubeItemInfo, FUN_1408b3c30, 206, 0x262C9B57);

// @0x1408b3d10
void CubeItemInfo::FUN_1408b3d10(CInputStream& stream)
{
    FUN_1408b3810();
    itemId = stream.ReadInt32();
    instanceId = stream.ReadInt64();
    count = stream.ReadInt64();
    unsigned char bHasLook = stream.ReadUInt8();
    if (bHasLook)
    {
        look.AssignRaw(new CUgcItemLook);
        look->Read(stream);
    }
}
MS2_REPLACE_METHOD(0x1408B3D10, CubeItemInfo, FUN_1408b3d10, 252, 0xE76E41F1);

// ---- UGCMapEnterBlockInfo / UGCMapBlock ----------------------------------------------------------------------------

// @0x1408b3e20
UGCMapEnterBlockInfo::UGCMapEnterBlockInfo() : m_n18(0), m_n20(0)
{
}

// @0x1408b3e70
UGCMapBlock::UGCMapBlock() : m_n18(0), m_n20(0), m_n24(0), m_n28(0), m_n2c(0), m_n30(0), m_str38(L"")
{
}

// ---- UserUGCMapInfo ------------------------------------------------------------------------------------------------

// @0x1408b3f10
UserUGCMapInfo::UserUGCMapInfo() : m_n18(0), m_n1c(0), m_n20(0), m_n24(0), m_str28(""), m_n30(0), m_n38(0), m_n40(0)
{
    if (FUN_140166410()->FUN_14036e510())
        m_n40 = 2;
}

// @0x1408b3fe0
UserUGCMapInfo::~UserUGCMapInfo()
{
}

// @0x1408b4020
void UserUGCMapInfo::FUN_1408b4020(int n18, int n1c, int n20, int n24, CStringW str28, __int64 n30, __int64 n38,
                                   unsigned char n40)
{
    m_n18 = n18;
    m_n1c = n1c;
    m_n20 = n20;
    m_n24 = n24;
    m_str28 = str28;
    m_n30 = n30;
    m_n38 = n38;
    m_n40 = n40;
}
MS2_REPLACE_METHOD(0x1408B4020, UserUGCMapInfo, FUN_1408b4020, 163, 0xE18692C1);

// @0x1408b40d0
void UserUGCMapInfo::FUN_1408b40d0(Unk_BmPtr<UserUGCMapInfo> spOther)
{
    m_n18 = spOther->m_n18;
    m_n1c = spOther->m_n1c;
    m_n20 = spOther->m_n20;
    m_n24 = spOther->m_n24;
    m_str28 = spOther->m_str28;
    m_n30 = spOther->m_n30;
    m_n38 = spOther->m_n38;
    m_n40 = spOther->m_n40;
}
MS2_REPLACE_METHOD(0x1408B40D0, UserUGCMapInfo, FUN_1408b40d0, 222, 0x94FC9250);

// Encodes the house info packet (0x69, sub 0x14).
// @0x1408b41c0
void UserUGCMapInfo::FUN_1408b41c0(COutPacket& packet, int nFlag) const
{
    packet.FUN_140710740(0x69, 0, 1);
    packet.WriteUInt8(0x14);
    FUN_1408b4450(packet, nFlag);
}
MS2_REPLACE_METHOD(0x1408B41C0, UserUGCMapInfo, FUN_1408b41c0, 86, 0x3B8F3AB2);

// @0x1408b4220
void UserUGCMapInfo::FUN_1408b4220(CInPacket& packet, int* pResult)
{
    m_n18 = packet.ReadInt32();
    m_n1c = packet.ReadInt32();
    m_n20 = packet.ReadInt32();
    m_n24 = packet.ReadInt32();
    m_str28 = packet.ReadUnicodeString();
    m_n30 = packet.ReadInt64();
    m_n38 = packet.ReadInt64();
    *pResult = packet.ReadUInt8();
    m_n40 = packet.ReadUInt8();
}
MS2_REPLACE_METHOD(0x1408B4220, UserUGCMapInfo, FUN_1408b4220, 552, 0x37BCDCDE);

// @0x1408b4450
void UserUGCMapInfo::FUN_1408b4450(COutputStream& stream, int nFlag) const
{
    stream.WriteInt32(m_n18);
    stream.WriteInt32(m_n1c);
    stream.WriteInt32(m_n20);
    stream.WriteInt32(m_n24);
    stream.WriteUnicodeString(m_str28);
    stream.WriteInt64(m_n30);
    stream.WriteInt64(m_n38);
    stream.WriteUInt8(nFlag);
    stream.WriteUInt8(m_n40);
}
MS2_REPLACE_METHOD(0x1408B4450, UserUGCMapInfo, FUN_1408b4450, 254, 0x4785F72F);

// @0x1408b4560
void UserUGCMapInfo::FUN_1408b4560(CStringW str)
{
    m_str28 = str;
}
MS2_REPLACE_METHOD(0x1408B4560, UserUGCMapInfo, FUN_1408b4560, 63, 0x95118258);

// ---- ObjectWeaponInfo ----------------------------------------------------------------------------------------------

// @0x1408b45b0
ObjectWeaponInfo::ObjectWeaponInfo() : m_n18(0), m_n1c(0), m_n20(0), m_n24(1), m_n28(0), m_f2c(1.0f)
{
}

// @0x1408b4660
ObjectWeaponInfo::~ObjectWeaponInfo()
{
}

// @0x1408b46b0
Unk_PayloadPtr<ObjectWeaponInfo> ObjectWeaponInfo::FUN_1408b46b0() const
{
    Unk_PayloadPtr<ObjectWeaponInfo> spCopy(new ObjectWeaponInfo);
    spCopy->m_n18 = m_n18;
    spCopy->m_n1c = m_n1c;
    spCopy->m_n20 = m_n20;
    spCopy->m_n24 = m_n24;
    spCopy->m_n28 = m_n28;
    spCopy->m_f2c = m_f2c;
    spCopy->m_str30 = m_str30;
    spCopy->m_ids.Copy(m_ids);
    return spCopy;
}
MS2_REPLACE_METHOD(0x1408B46B0, ObjectWeaponInfo, FUN_1408b46b0, 401, 0x359BDB97);

// ---- NoticeCubeInfo ------------------------------------------------------------------------------------------------

// @0x1408b4850
NoticeCubeInfo::NoticeCubeInfo()
{
}

// @0x1408b48a0
NoticeCubeInfo::~NoticeCubeInfo()
{
}

// @0x1408b48e0
NoticeCubeInfo* NoticeCubeInfo::Clone() const
{
    NoticeCubeInfo* pCopy = new NoticeCubeInfo;
    pCopy->Set(m_strText, m_n20);
    return pCopy;
}
MS2_REPLACE_METHOD(0x1408B48E0, NoticeCubeInfo, Clone, 128, 0x8C9161A9);

// @0x1408b4970
void NoticeCubeInfo::Set(const CStringW& strText, int n)
{
    m_strText = strText;
    m_n20 = n;
}
MS2_REPLACE_METHOD(0x1408B4970, NoticeCubeInfo, Set, 59, 0xD539A294);

// @0x1408b49c0
const CStringW& NoticeCubeInfo::GetText() const
{
    return m_strText;
}

// @0x1408b49e0
int NoticeCubeInfo::GetN20() const
{
    return m_n20;
}

// ---- Cube ----------------------------------------------------------------------------------------------------------

// MS2-FUNCTIONAL: cube.h types position as a trivial Unk_Int3 and offset/pointBc as NiPoint3 (the exe calls an Unk_Int3 default ctor
// 0x1408850a0 and the out-of-line point ctor 0x1402bd040); same stores in the same order.
// @0x1408b4a00
Cube::Cube() : entity(0)
{
    entity = 0;
    item = new CubeItemInfo;
    position = Unk_Int3(0, 0, -1);
    field44 = 0;
    field48 = 0;
    field50 = 0;
    field54 = 0;
    field4c = 0;
    field58 = 0;
    field5c = 0;
    field60 = 0;
    field64 = 0;
    field68 = 0;
    field6c = 0;
    field70 = 0;
    field74 = 0;
    field78 = 0;
    field7c = 0;
    weapon = 0;
    fieldAc = 0;
    fieldB0 = 0;
    fieldB4 = 0;
    fieldB8 = 0.0f;
    pointBc = NiPoint3(0.0f, 0.0f, 0.0f);
    fieldC8 = 0;
    fieldCc = 0;
    fieldD0 = true;
    reinterpret_cast<float&>(fieldD4) = 0.0f;
    fieldD8 = 0;
    fieldA8 = 0;
    record.field0 = 0;
    CPtred::InterlockedInc(&ms_nCount);
}

// @0x1408b4da0
Cube::~Cube()
{
    item = 0;
    weapon = 0;
    CPtred::InterlockedDec(&ms_nCount);
}

// @0x1408b4e90
unsigned Cube::FUN_1408b4e90() const
{
    return field5c;
}

// Holds this item (pInfo 0: holds no valid item).
// @0x1408b4eb0
bool Cube::FUN_1408b4eb0(const CubeItemInfo* pInfo) const
{
    if (pInfo == 0)
    {
        if (item->FUN_1408b3860() == 0)
            return true;
        return false;
    }
    else
    {
        if (item->FUN_1408b38c0(pInfo) != 0)
            return true;
        return false;
    }
}
MS2_REPLACE_METHOD(0x1408B4EB0, Cube, FUN_1408b4eb0, 104, 0x6EE89605);

// @0x1408b4f20
int Cube::FUN_1408b4f20()
{
    return item->itemId;
}
MS2_REPLACE_METHOD(0x1408B4F20, Cube, FUN_1408b4f20, 34, 0x2A0E4B7C);

// @0x1408b4f50
__int64 Cube::FUN_1408b4f50() const
{
    return item->instanceId;
}
MS2_REPLACE_METHOD(0x1408B4F50, Cube, FUN_1408b4f50, 35, 0xD747657A);

// @0x1408b4f80
CUgcItemLook* Cube::FUN_1408b4f80()
{
    return item->look.get();
}
MS2_REPLACE_METHOD(0x1408B4F80, Cube, FUN_1408b4f80, 43, 0xA69DCEC9);

// The cube's entity was created: show the downloaded look image, or queue its download.
// @0x1408b4fd0
void Cube::FUN_1408b4fd0(egf::Entity* pEntity)
{
    if (pEntity != entity)
        return;
    if (entity == 0)
        return;
    if (item->FUN_1408b3860() == 0)
        return;
    CStringA strPath;
    if (item->look == 0)
        return;
    strPath = FUN_1410280d0(2, CStringA(item->look->m_strUrl));
    if (_access(strPath, 4) == 0)
        FUN_1408b51d0();
    else
        FUN_14052d220()->FUN_1418845a0(item.get(), entity->GetEntityID());
}
MS2_REPLACE_METHOD(0x1408B4FD0, Cube, FUN_1408b4fd0, 500, 0xE53038B6);

// Applies the downloaded look image (0: not downloaded yet).
// @0x1408b51d0
int Cube::FUN_1408b51d0()
{
    if (entity == 0)
        return 0;
    if (item->FUN_1408b3860() == 0)
        return 0;
    CStringA strPath;
    if (item->look == 0)
        return 0;
    strPath = FUN_1410280d0(2, CStringA(item->look->m_strUrl));
    if (_access(strPath, 4) != 0)
        return 0;
    FUN_14052d220()->FUN_1418873c0(this);
    return 1;
}
MS2_REPLACE_METHOD(0x1408B51D0, Cube, FUN_1408b51d0, 405, 0x984A0955);

// @0x1408b5370
Vector3 Cube::FUN_1408b5370()
{
    Vector3 kOffset;
    return FUN_1408a15b0(position, kOffset);
}
MS2_REPLACE_METHOD(0x1408B5370, Cube, FUN_1408b5370, 82, 0xC52D8A9F);

// ---- item id predicates --------------------------------------------------------------------------------------------

// The housing item does not install as a blueprint.
// @0x1408b53d0
int FUN_1408b53d0(int nItemId)
{
    if (nItemId == 0)
        return 0;
    MS2Ptr<ItemHousing> spHousing = FUN_140281980()->GetHousing(nItemId);
    if (spHousing == 0)
        return 0;
    if (spHousing->doNotInstallBlueprint)
        return 1;
    return 0;
}
MS2_REPLACE(0x1408B53D0, FUN_1408b53d0, 167, 0x267F2C3D);

// @0x1408b5480
int FUN_1408b5480(unsigned nItemId)
{
    if (FUN_140552df0() == 0)
        return 0;
    return FUN_140552df0()->IsHousingBuyable(nItemId);
}
MS2_REPLACE(0x1408B5480, FUN_1408b5480, 44, 0x938A7F09);

// The item's install object switches with the fitting doll ui.
// @0x1408b54c0
int FUN_1408b54c0(int nItemId)
{
    if (nItemId == 0)
        return 0;
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (!spItem)
        return 0;
    if (FUN_1407072e0(spItem->install.objCode))
        return 1;
    return 0;
}
MS2_REPLACE(0x1408B54C0, FUN_1408b54c0, 160, 0x289323F0);

// Bank ui.
// @0x1408b5570
int FUN_1408b5570(int nItemId)
{
    if (nItemId == 0)
        return 0;
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (!spItem)
        return 0;
    if (FUN_1407074f0(spItem->install.objCode))
        return 1;
    return 0;
}
MS2_REPLACE(0x1408B5570, FUN_1408b5570, 160, 0xFD49CD99);

int FUN_1408b56c0(MS2Ptr<CItemData> spItem);

// @0x1408b5620
int FUN_1408b5620(int nItemId)
{
    if (nItemId == 0)
        return 0;
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (!spItem)
        return 0;
    return FUN_1408b56c0(spItem);
}
MS2_REPLACE(0x1408B5620, FUN_1408b5620, 147, 0x0B03CCEE);

// Summons an npc (and spawns or installs it).
// @0x1408b56c0
int FUN_1408b56c0(MS2Ptr<CItemData> spItem)
{
    if (!spItem)
        return 0;
    if (spItem->FUN_14053dd30() > 0 && FUN_1407075a0(spItem->install.objCode))
        return 1;
    return 0;
}
MS2_REPLACE(0x1408B56C0, FUN_1408b56c0, 157, 0x1E611F48);

// Nurturing control type.
// @0x1408b5770
int FUN_1408b5770(int nItemId)
{
    if (nItemId == 0)
        return 0;
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (!spItem)
        return 0;
    if (FUN_140707dc0(spItem->install.objCode))
        return 1;
    return 0;
}
MS2_REPLACE(0x1408B5770, FUN_1408b5770, 160, 0x8F729D27);

int FUN_1408b58c0(MS2Ptr<CItemData> spItem);

// @0x1408b5820
int FUN_1408b5820(int nItemId)
{
    if (nItemId == 0)
        return 0;
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (!spItem)
        return 0;
    return FUN_1408b58c0(spItem);
}
MS2_REPLACE(0x1408B5820, FUN_1408b5820, 147, 0x99721A18);

// Trigger tool ui.
// @0x1408b58c0
int FUN_1408b58c0(MS2Ptr<CItemData> spItem)
{
    if (spItem == 0)
        return 0;
    if (FUN_140707660(spItem->install.objCode))
        return 1;
    return 0;
}
MS2_REPLACE(0x1408B58C0, FUN_1408b58c0, 137, 0x784DB58C);

// Trigger control enabled.
// @0x1408b5950
int FUN_1408b5950(int nItemId)
{
    if (nItemId == 0)
        return 0;
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (!spItem)
        return 0;
    if (FUN_140707710(spItem->install.objCode))
        return 1;
    return 0;
}
MS2_REPLACE(0x1408B5950, FUN_1408b5950, 160, 0x3DB99285);

// @0x1408b5a00
int FUN_1408b5a00(int nItemId)
{
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (spItem == 0)
        return 0;
    if (spItem->FUN_14053c600() == 0x31)
        return 1;
    return 0;
}
MS2_REPLACE(0x1408B5A00, FUN_1408b5a00, 149, 0x130521A6);

// Password ui.
// @0x1408b5aa0
int FUN_1408b5aa0(int nItemId)
{
    if (nItemId == 0)
        return 0;
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (!spItem)
        return 0;
    if (FUN_140707870(spItem->install.objCode))
        return 1;
    return 0;
}
MS2_REPLACE(0x1408B5AA0, FUN_1408b5aa0, 160, 0x4C7701E0);

// Forbids jump, climb, skill or instrument.
// @0x1408b5b50
int FUN_1408b5b50(int nItemId)
{
    if (nItemId == 0)
        return 0;
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (!spItem)
        return 0;
    if (FUN_140707920(spItem->install.objCode))
        return 1;
    return 0;
}
MS2_REPLACE(0x1408B5B50, FUN_1408b5b50, 160, 0xB07A5059);

// Forbidden for non owners.
// @0x1408b5c00
int FUN_1408b5c00(int nItemId)
{
    if (nItemId == 0)
        return 0;
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (!spItem)
        return 0;
    if (FUN_140707a00(spItem->install.objCode))
        return 1;
    return 0;
}
MS2_REPLACE(0x1408B5C00, FUN_1408b5c00, 160, 0xC4622598);

// Portal control type.
// @0x1408b5cb0
int FUN_1408b5cb0(int nItemId)
{
    if (nItemId == 0)
        return 0;
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (!spItem)
        return 0;
    if (FUN_140707ac0(spItem->install.objCode))
        return 1;
    return 0;
}
MS2_REPLACE(0x1408B5CB0, FUN_1408b5cb0, 160, 0x034D9EC0);

// Notice control type.
// @0x1408b5d60
int FUN_1408b5d60(int nItemId)
{
    if (nItemId == 0)
        return 0;
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (!spItem)
        return 0;
    if (FUN_140707b40(spItem->install.objCode))
        return 1;
    return 0;
}
MS2_REPLACE(0x1408B5D60, FUN_1408b5d60, 160, 0x1700F77F);

// Breeding control type.
// @0x1408b5e10
int FUN_1408b5e10(int nItemId)
{
    if (nItemId == 0)
        return 0;
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (!spItem)
        return 0;
    if (FUN_140707c60(spItem->install.objCode))
        return 1;
    return 0;
}
MS2_REPLACE(0x1408B5E10, FUN_1408b5e10, 160, 0x5F7719C0);

// Farming control type.
// @0x1408b5ec0
int FUN_1408b5ec0(int nItemId)
{
    if (nItemId == 0)
        return 0;
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (spItem == 0)
        return 0;
    if (FUN_140707d10(spItem->install.objCode))
        return 1;
    return 0;
}
MS2_REPLACE(0x1408B5EC0, FUN_1408b5ec0, 165, 0x0E1C426D);

// Install npc control type.
// @0x1408b5f70
int FUN_1408b5f70(int nItemId)
{
    if (nItemId == 0)
        return 0;
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (spItem == 0)
        return 0;
    if (FUN_140707e70(spItem->install.objCode))
        return 1;
    return 0;
}
MS2_REPLACE(0x1408B5F70, FUN_1408b5f70, 165, 0xDF1B756B);

// @0x1408b6020
int FUN_1408b6020(int nItemId)
{
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (spItem == 0)
        return 0;
    if (spItem->FUN_14053c600() == 0x1c)
        return 1;
    if (spItem->FUN_14053c600() == 0x1d)
        return 1;
    if (spItem->FUN_14053c600() == 0x1e)
        return 1;
    return 0;
}
MS2_REPLACE(0x1408B6020, FUN_1408b6020, 246, 0xDB54E2DE);

// The housing item has a trophy.
// @0x1408b6120
int FUN_1408b6120(unsigned nItemId)
{
    MS2Ptr<ItemHousing> spHousing = FUN_140281980()->GetHousing(nItemId);
    if (spHousing == 0)
        return 0;
    if (spHousing->trophyID > 0)
        return 1;
    return 0;
}
MS2_REPLACE(0x1408B6120, FUN_1408b6120, 151, 0xD177F686);

// The price table has no housing row for the item.
// @0x1408b61c0
int FUN_1408b61c0(unsigned nItemId)
{
    if (FUN_140552df0() == 0)
        return 0;
    if (FUN_140552df0()->HasHousing(nItemId) != 0)
        return 0;
    return 1;
}
MS2_REPLACE(0x1408B61C0, FUN_1408b61c0, 57, 0xE59C84D7);

// The bank slot count of the item's bank.
// MS2-FUNCTIONAL: CItemData::FUN_14053dce0 returns int and GetBankData takes unsigned here (the exe passes the id without the
// int->unsigned register copy); same calls.
// @0x1408b6200
int FUN_1408b6200(int nItemId)
{
    if (nItemId == 0)
        return 0;
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (!spItem)
        return 0;
    MS2Ptr<CBankData> spBank = FUN_1401b59c0()->GetBankData(spItem->FUN_14053dce0());
    if (spBank == 0)
        return 0;
    return spBank->m_nSlotCount;
}
MS2_REPLACE(0x1408B6200, FUN_1408b6200, 237, 0x7FEBF024);
