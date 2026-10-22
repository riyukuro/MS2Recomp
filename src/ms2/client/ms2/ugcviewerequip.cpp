// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The UGC viewers: the previews that CUgcManager attaches to a
// CUgcUploadCtrl (equip, cube, mount, banner, profile, wedding profile, guild mark, guild poster, blueprint image), the
// base IUgcViewer, and CUgcUploadCtrl itself (the upload in progress: content kind, the viewer, the local file and the
// result text). Class names are the RTTI names; the unit name is a guess (queue row ?\ugcviewerequip.cpp).
// MS2-UNIT: ?\ugcviewerequip.cpp
// MS2-GUESS-LOOKALIKES
// MS2-RANGE: 0x14189eae0-0x1418a7310 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define NOMINMAX
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\ugcviewerequip.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include <io.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <egf/Entity.h>
#include <egf/EntityID.h>
#include <efd/SmartPointer.h>
#include <NiTexture.h>
#include <NiSourceTexture.h>
#include <efd/utf8string.h>
#include <NiTexturingProperty.h>

#include "ms2/placeholder/cugcuploadctrl.h"
#include "ms2/placeholder/cugcmanager.h"
#include "ms2/placeholder/cequipitem.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/postprocesseffect.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/client/ms2/itemugcmesh.h"
#include "ms2/client/ms2/clonecube.h"
#include "ms2/client/ms2/avatarcube.h"
#include "ms2/client/ms2/avatarpc.h"
#include "ms2/client/ms2/ugcmanager.h"
#include "ms2/unnamed/unit_1401b6d10.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/client/ms2/interactobject.h"
#include "ms2/client/ms2/uiitemblueprintcreatedialog.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit types and callees (bound to the exe by their FUN_<va> names) ----

class Unk_VwWearer;

// The world service: the player and the object / entity lookups.
class Unk_ItemEquipData : public CItemData { };             // CItem::FUN_140527840's record (item.cpp)
class Unk_SgNifLoader { public: NiTexturePtr FUN_141553eb0(CString strPath, NiTexture* pkSelf); };
Unk_SgNifLoader* FUN_140a0afd0();
CString FUN_1410280d0(int nKind, CString strName);          // the local file of a ugc content kind
NiAVObject* FUN_141b6efc0(void* pEntity);                   // the scene root of an entity
void FUN_141890b60(egf::Entity* pEntity, const efd::utf8string& strProp, efd::utf8string& strOut);
class Unk_VwWorld
{
public:
    GameObject* FUN_141bd0cc0();                            // the local player
    GameObject* FUN_141bd1290(int nObjectId);               // a player by object id
    egf::Entity* FUN_141bd04d0(int nObjectId);              // an entity by object id
    GameObject* FUN_141bd0fa0(egf::EntityID id);            // the game object of an entity
    MS2Ptr<CInteractObject> FUN_141bc66b0(const CString& strName);   // an interact object by name
};
Unk_VwWorld* FUN_1403ed2d0();
Unk_VwWearer* FUN_140b120b0(GameObject* pPlayer);           // the player as a wearer of items

class Unk_VwWearer
{
public:
    MS2Ptr<CEquipItem> FUN_141655c30(__int64 itemUid);      // a worn item by uid
};

extern Vector3 DAT_143b01a60;                       // the zero point
void FUN_1409618c0(egf::Entity* pEntity, unsigned nProperty, Vector3* pOut);   // reads a point property
float FUN_140966f00(NiPoint3 kA, Vector3 kB);           // the distance
float FUN_140966ea0(NiPoint3 kA, Vector3 kB);           // the planar distance
struct Unk_VwConfig { char m_pad[0xd8]; CStringA m_strUploadDir; };   // the client config
void* FUN_140166410();                                      // the game settings
bool FUN_14036e510(void* pSettings);                        // a content switch
void* FUN_1403ed290();                                      // the guild manager (+8: the own guild)
__int64 FUN_1404ccbd0(void* pGuild);                        // the guild id
struct Unk_VwUIService; Unk_VwUIService* FUN_1403ed2b0();  // the UI service
void* FUN_1409eed90();                                      // the singleton of the own character
struct Unk_VwSummary { char m_pad[0x20]; int m_nState; };   // the own character's summary (+0x20: 2 = wedding done)
Unk_VwSummary* FUN_140d295d0(void* pSingleton);


// The upload manager; the CUgcManager singleton.
CUgcManager* FUN_14052d220();

// UI dialogs by id.
void* FUN_140938c30(int nId);                               // 0x2711 the profile dialog
void* FUN_1418764c0(int nId);                               // 0x4f8c the wedding profile dialog
void* FUN_14136f480(int nId);                               // 0x4e4f the guild mark dialog
void FUN_14132faf0(void* pDialog, const CStringW& strFile);        // show the uploaded image (profile)
void FUN_14132fa90(void* pDialog);
void FUN_140fc7e80(void* pDialog, const CStringW& strFile);        // (wedding profile)
void FUN_140fc7f30(void* pDialog);
void FUN_141976980(void* pDialog, const CStringW& strFile);        // (guild mark)
void FUN_1419769d0(void* pDialog);
void FUN_141403180(CInteractGuildPosterObject* pPoster, CStringW strFile);   // load the poster file into the entity
void FUN_141402eb0(CInteractGuildPosterObject* pPoster, unsigned char bShow);

// Textures of the preview files and the format helper strings.
int FUN_14186ced0(NiTexture* pTexture, int nItemId, int nKind, CStringW& strOut);   // the texture fits the item mesh (0 = yes)
int FUN_14186d050(NiTexture* pTexture, int nBannerId, CStringW& strOut);
CString FUN_1411c0aa0(const char* szText);                  // a text without arguments
NiTexturePtr FUN_14186bd30(const CStringW& strPath, int nSize, bool bFlag);   // the texture of an image file (null on error)

// The exe formats ids as unsigned values (the unsigned ArgType constructors).
#define VW_U(x) reinterpret_cast<const unsigned&>(x)
#define VW_U64(x) reinterpret_cast<const unsigned __int64&>(x)
enum class Unk_VwDialogId : int { None = 0 };               // a dialog id (formatted as a custom argument)
// A dialog of the UI service by id; slot 55 is its "is hidden" state.
class Unk_VwDialogUi
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual int vfunc_55();
};
Unk_VwDialogUi* FUN_140c300a0(int nId);
// The upload event hub (slot 4 shows the finished upload of a dialog).
class Unk_VwEvents
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4(int nDialog);
};
Unk_VwEvents* FUN_140bc09f0();
class Unk_CommandUIRef {
public:
    ~Unk_CommandUIRef();
    UIObject* FUN_1403e8a70() const;
private: void* unknown; UIObject* object;
};
MS2_CHECK_SIZE(Unk_CommandUIRef,0x10);
struct Unk_VwUIService { Unk_CommandUIRef FUN_141adcea0(int nId); };  // the UI lookup by class id
UIObject* FUN_1403ed9e0(Unk_CommandUIRef&);
bool FUN_140534e80(Unk_CommandUIRef&);
void FUN_140c381b0(UIItemBlueprintCreateDialog* pDialog, MS2Ptr<CUploadFile> spFile);   // show the uploaded image
void FUN_140c38240(UIItemBlueprintCreateDialog* pDialog);
CStringW FUN_14016a730(const char* psz, int n);             // narrow -> wide
extern __int64 DAT_143ab2820;                               // my account id
extern __int64 DAT_143ab2828;                               // my character id
CString FUN_14016a600(const wchar_t* psz, int n);          // wide -> narrow
extern unsigned DAT_143ab2830;                              // my character's type

// MS2-PIN: ??$format_arg@DW4Unk_VwDialogId@@@fmt@@YAXAEAV?$BasicFormatter@D@0@AEAPEBDAEBW4Unk_VwDialogId@@@Z 0x1418a69d0

// ---- CUgcViewerEquip ----------------------------------------------------------------------------------------------

// @0x14189eae0
CUgcViewerEquip::CUgcViewerEquip()
{
    m_item.Clear();
    m_icon.Clear();
    m_n108 = 0;
    m_spMesh = 0;
    m_spProperty = 0;
    m_spTexture = 0;
}

// @0x14189ec30
CUgcViewerEquip::CUgcViewerEquip(CItem* pItem)
    : m_item(pItem, pItem == 0 ? 0 : pItem->FUN_140526b10())
    , m_icon(pItem, pItem == 0 ? 0 : pItem->FUN_140526b10())
{
}

// @0x14189ed40
CUgcViewerEquip::~CUgcViewerEquip()
{
    m_spMesh = 0;
    m_spProperty = 0;
    m_spTexture = 0;
}

// @0x14189ee30
int CUgcViewerEquip::vfunc_2()
{
    Unk_VwWearer* pWearer = FUN_140b120b0(FUN_1403ed2d0()->FUN_141bd1290(FUN_14189f730()));
    if (pWearer == 0)
        return 0;
    MS2Ptr<CEquipItem> spEquip = pWearer->FUN_141655c30(m_item.m_itemUid);
    if (spEquip == 0)
        return 0;
    MS2Ptr<CItemUgcMeshContainer> spMeshes = spEquip->GetUgcMeshes();
    if (spMeshes == 0)
        return 0;
    NiTexturePtr spTexture = spMeshes->FUN_141426e30();
    if (spTexture == 0)
        return 0;
    CStringW strError;
    int nResult = FUN_14186ced0(spTexture, m_item.m_nItemId, 1, strError);
    if (nResult != 0)
        return 0;
    return 1;
}

// @0x14189f040
int CUgcViewerEquip::vfunc_3(MS2Ptr<CUploadFile> spFile)
{
    if (spFile == 0)
        return 0;
    MS2Ptr<CUgcUploadCtrl> spCtrl = FUN_14052d220()->FUN_141882610();
    if (spCtrl == 0)
        return 0;
    CStringW strPath = spFile->GetPath();
    NiTexturePtr spTexture = FUN_14186bd30(strPath, vfunc_9(), true);
    if (spTexture == 0)
        return 0;
    if (FUN_14052d220()->FUN_141886a90(&m_item, spTexture) == 0)
        return 0;
    spCtrl->m_spFile = spFile;
    return 1;
}

// @0x14189f260
void CUgcViewerEquip::vfunc_4()
{
    Unk_VwWearer* pWearer = FUN_140b120b0(FUN_1403ed2d0()->FUN_141bd1290(FUN_14189f730()));
    if (pWearer == 0)
        return;
    MS2Ptr<CEquipItem> spEquip = pWearer->FUN_141655c30(m_item.m_itemUid);
    if (spEquip == 0)
        return;
    MS2Ptr<CItemUgcMeshContainer> spMeshes = spEquip->GetUgcMeshes();
    if (spMeshes == 0)
        return;
    spMeshes->FUN_141426980();
}

// @0x14189f360
void CUgcViewerEquip::vfunc_5()
{
    Unk_VwWearer* pWearer = FUN_140b120b0(FUN_1403ed2d0()->FUN_141bd1290(FUN_14189f730()));
    if (pWearer == 0)
        return;
    MS2Ptr<CEquipItem> spEquip = pWearer->FUN_141655c30(m_item.m_itemUid);
    if (spEquip == 0)
        return;
    MS2Ptr<CItem> spItem = spEquip->GetItem();
    if (spItem == 0 || spItem->FUN_140527840() == 0)
        return;
    m_strMesh = spItem->FUN_140527840()->cubeTextureName.mesh;
}

// @0x14189f490
CString CUgcViewerEquip::vfunc_11()
{
    CString str;
    str = Unk_SocketFormat("[viewer={0}] [strUgcMesh={1}] [dropOid={2}] [pcOid={3}]", "UgcViewerEquip", m_strMesh, VW_U(m_item.m_nSlot), VW_U(m_item.m_nObjectId));
    return str;
}

// @0x14189f560
void CUgcViewerEquip::vfunc_6(COutPacket& packet)
{
    m_item.Write(packet);
}

// @0x14189f5a0
void CUgcViewerEquip::vfunc_7(void* p)
{
}

// @0x14189f5c0
int CUgcViewerEquip::vfunc_8(MS2Ptr<IUgcProxy> spProxy, int nKind)
{
    if (spProxy == 0)
        return 0;
    if (nKind == 1)
    {
        IUgcProxy* pProxy = spProxy.get();
        if (pProxy == 0)
            return 0;
        pProxy->CopyFrom(&m_item);
    }
    else if (nKind == 0xc9)
    {
        CUgcItemIconPC* pProxy = static_cast<CUgcItemIconPC*>(spProxy.get());
        if (pProxy == 0)
            return 0;
        pProxy->CopyFrom(&m_icon);
        pProxy->m_nKind = 2;
    }
    return 1;
}

// @0x14189f700
void CUgcViewerEquip::vfunc_12(__int64 itemUid)
{
    m_item.m_itemUid = itemUid;
    m_icon.m_itemUid = itemUid;
}

// @0x14189f730
int CUgcViewerEquip::FUN_14189f730()
{
    return m_item.m_nObjectId;
}

// @0x14189f750
void CUgcViewerEquip::FUN_14189f750(int nObjectId)
{
    m_item.m_nObjectId = nObjectId;
}

// @0x14189f770
MS2Ptr<IUgcProxy> CUgcViewerEquip::FUN_14189f770(MS2Ptr<IUgcProxy> spOut)
{
    return spOut;
}

// ---- CUgcViewerCube -----------------------------------------------------------------------------------------------

// @0x14189f7c0
CUgcViewerCube::CUgcViewerCube()
{
}

// @0x14189f840
CUgcViewerCube::~CUgcViewerCube()
{
}

// @0x14189f8b0
int CUgcViewerCube::vfunc_2()
{
    efd::SmartPointer<AvatarCube> spCube = efd::DynamicCast<AvatarCube>(FUN_1403ed2d0()->FUN_141bd0fa0(FUN_1418a0110()));
    if (spCube == 0)
        return 0;
    MS2Ptr<CItemUgcMeshContainer> spMeshes = spCube->GetUgcMesh();
    if (spMeshes == 0)
        return 0;
    NiTexturePtr spTexture = spMeshes->FUN_141426e30();
    if (spTexture == 0)
        return 0;
    CStringW strError;
    int nResult = FUN_14186ced0(spTexture, m_item.m_nItemId, 2, strError);
    if (nResult != 0)
        return 0;
    return 1;
}

// @0x14189fab0
int CUgcViewerCube::vfunc_3(MS2Ptr<CUploadFile> spFile)
{
    if (spFile == 0)
        return 0;
    MS2Ptr<CUgcUploadCtrl> spCtrl = FUN_14052d220()->FUN_141882610();
    if (spCtrl == 0)
        return 0;
    CStringW strPath = spFile->GetPath();
    NiTexturePtr spTexture = FUN_14186bd30(strPath, vfunc_9(), true);
    if (spTexture == 0)
        return 0;
    if (FUN_14052d220()->FUN_141886de0(&m_item, spTexture) == 0)
        return 0;
    spCtrl->m_spFile = spFile;
    return 1;
}

// @0x14189fcd0
void CUgcViewerCube::vfunc_4()
{
    efd::SmartPointer<AvatarCube> spCube = efd::DynamicCast<AvatarCube>(FUN_1403ed2d0()->FUN_141bd0fa0(FUN_1418a0110()));
    if (spCube == 0)
        return;
    spCube->FUN_141085250();
}

// @0x14189fd80
void CUgcViewerCube::vfunc_5()
{
    efd::SmartPointer<AvatarCube> spCube = efd::DynamicCast<AvatarCube>(FUN_1403ed2d0()->FUN_141bd0fa0(FUN_1418a0110()));
    if (spCube == 0)
        return;
    CItemData* pData = spCube->GetItemData().get();
    if (pData == 0)
        return;
    m_strMesh = pData->cubeTextureName.mesh;
}

// @0x14189fe90
CString CUgcViewerCube::vfunc_11()
{
    CString str;
    str = Unk_SocketFormat("[viewer={0}] [strUgcMesh={1}] [itemSN={2}]", "UgcViewerCube", m_strMesh, VW_U64(m_item.m_itemUid));
    return str;
}

// @0x14189ff60
void CUgcViewerCube::vfunc_6(COutPacket& packet)
{
    m_item.Write(packet);
}

// @0x14189ffa0
int CUgcViewerCube::vfunc_8(MS2Ptr<IUgcProxy> spProxy, int nKind)
{
    if (spProxy == 0)
        return 0;
    if (nKind == 2)
    {
        IUgcProxy* pProxy = spProxy.get();
        if (pProxy == 0)
            return 0;
        pProxy->CopyFrom(&m_item);
    }
    else if (nKind == 0xc9)
    {
        CUgcItemIconPC* pProxy = static_cast<CUgcItemIconPC*>(spProxy.get());
        if (pProxy == 0)
            return 0;
        pProxy->CopyFrom(&m_icon);
        pProxy->m_nKind = 2;
    }
    return 1;
}

// @0x1418a00e0
void CUgcViewerCube::vfunc_12(__int64 itemUid)
{
    m_item.m_itemUid = itemUid;
    m_icon.m_itemUid = itemUid;
}

// @0x1418a0110
egf::EntityID CUgcViewerCube::FUN_1418a0110()
{
    return m_item.m_entityId;
}

// @0x1418a0150
void CUgcViewerCube::FUN_1418a0150(const egf::EntityID& id)
{
    m_item.m_entityId = id;
}

// ---- CUgcViewerBanner (the post at +0x18, the decal state at +0x68, the image at +0x70, the banner record at +0x78) ----

// (the members are declared in cugcuploadctrl.h)
















// @0x1418a0180
CUgcViewerBanner::CUgcViewerBanner()
    : m_spImage(0)
{


    m_post.Clear();
    m_nLoaded = 0;
    m_spImage = 0;
    m_spBanner = 0;
}

// @0x1418a0250
CUgcViewerBanner::~CUgcViewerBanner()
{
    m_spImage = 0;
    m_spBanner = 0;



}

// @0x1418a02f0
void CUgcViewerBanner::vfunc_1()
{
    efd::SmartPointer<egf::Entity> spEntity = FUN_1403ed2d0()->FUN_141bd04d0(m_post.m_nBannerId);
    if (spEntity == 0)
        return;
    GameObject* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    NiPoint3 kPlayer = pPlayer->vfunc_18();
    Vector3 kBanner = DAT_143b01a60;
    FUN_1409618c0(spEntity, 0xfd95ca52, &kBanner);
    int bPlanar = 0;
    float fDistance = bPlanar ? FUN_140966ea0(kPlayer, kBanner) : FUN_140966f00(kPlayer, kBanner);
    float fLimit = FUN_1401d3200()->RegistUgcDistanceClose.Read();
    if (fDistance > fLimit)
        FUN_14052d220()->FUN_14187f1f0();
}

// @0x1418a04d0
int CUgcViewerBanner::vfunc_2()
{
    if (m_spImage == 0)
        return 0;
    CStringW strError;
    int nResult = FUN_14186d050(m_spImage, m_post.m_nBannerId, strError);
    if (nResult != 0)
        return 0;
    return 1;
}

// @0x1418a0580
int CUgcViewerBanner::vfunc_3(MS2Ptr<CUploadFile> spFile)
{
    if (spFile == 0)
        return 0;
    MS2Ptr<CUgcUploadCtrl> spCtrl = FUN_14052d220()->FUN_141882610();
    if (spCtrl == 0)
        return 0;
    efd::SmartPointer<egf::Entity> spEntity = FUN_1403ed2d0()->FUN_141bd04d0(m_post.m_nBannerId);
    if (spEntity == 0)
        return 0;
    CStringW strPath = spFile->GetPath();
    NiTexturePtr spTexture = FUN_14186bd30(strPath, vfunc_9(), true);
    if (spTexture == 0)
        return 0;
    if (FUN_14052d220()->FUN_141888770(spEntity, spTexture) == 1)
        spCtrl->m_spFile = spFile;
    return 1;
}

// @0x1418a0800
void CUgcViewerBanner::vfunc_4()
{
    int nBannerId = m_post.m_nBannerId;
    NiTexturePtr spTexture;
    efd::SmartPointer<egf::Entity> spEntity = FUN_1403ed2d0()->FUN_141bd04d0(m_post.m_nBannerId);
    if (spEntity == 0)
        return;
    MS2Ptr<CUgcRegistBanner> spRegist = FUN_14052d220()->FUN_141887ce0(nBannerId);
    if (spRegist == 0)
        spTexture = m_spImage;
    else
    {
        CString strFile = FUN_1410280d0(3, spRegist->m_strUrl);
        if (_access(strFile, 0) == 0)
        {
            spTexture = FUN_140a0afd0()->FUN_141553eb0(strFile, 0);
            if (spTexture == 0)
            {
                FUN_14052d220()->FUN_141884af0(spRegist);
                return;
            }
        }
        else
            spTexture = m_spImage;
    }
    FUN_14052d220()->FUN_141888770(spEntity, spTexture);
}

// @0x1418a0b10
void CUgcViewerBanner::vfunc_5()
{
    if (m_nLoaded == 1)
        return;
    efd::SmartPointer<egf::Entity> spEntity = FUN_1403ed2d0()->FUN_141bd04d0(m_post.m_nBannerId);
    if (spEntity == 0)
        return;
    NiAVObject* pRoot = FUN_141b6efc0(spEntity.data());
    if (pRoot != 0)
    {
        efd::utf8string strMesh;
        FUN_141890b60(spEntity, "Index00MeshName", strMesh);
        efd::utf8string strTexture;
        FUN_141890b60(spEntity, "Index00TexturePath", strTexture);
        if (!strMesh.empty())
        {
            if (NiAVObject* pMesh = pRoot->GetObjectByName(strMesh.c_str()))
            {
                NiTexturingProperty* pProperty = NiDynamicCast(NiTexturingProperty, pMesh->GetProperty(NiProperty::TEXTURING));
                if (pProperty != 0)
                {
                    NiTexturingProperty::Map* pMap = pProperty->GetDecalMap(0);
                    m_spImage = pMap->GetTexture();
                    m_nLoaded = 1;
                }
            }
        }
    }
}

// @0x1418a0d70
CString CUgcViewerBanner::vfunc_11()
{
    CString str;
    str = Unk_SocketFormat("[viewer={0}] [bannerSN={1}]", "UgcViewerBanner", VW_U(m_post.m_nBannerId));
    return str;
}

// @0x1418a0e20
void CUgcViewerBanner::vfunc_6(COutPacket& packet)
{
    m_post.Write(packet);
}

// @0x1418a0e60
int CUgcViewerBanner::vfunc_13(MS2Ptr<IUgcProxy> spProxy)
{
    if (spProxy == 0)
        return 0;
    IUgcProxy* pProxy = spProxy.get();
    if (pProxy == 0)
        return 0;
    pProxy->CopyFrom(&m_post);
    return 1;
}

// @0x1418a0f20
int CUgcViewerBanner::vfunc_9()
{
    CFieldBannerData* pBanner = CFieldBannerData::GetBanner(m_post.m_nBannerId).get();
    if (pBanner == 0)
        return 0;
    return pBanner->m_nSize;
}

// @0x1418a0f90
void CUgcViewerBanner::FUN_1418a0f90(int nBannerId)
{
    m_post.m_nBannerId = nBannerId;
    m_spBanner = CFieldBannerData::GetBanner(nBannerId);
}

// @0x1418a1000
void CUgcViewerBanner::FUN_1418a1000()
{
    efd::SmartPointer<egf::Entity> spEntity = FUN_1403ed2d0()->FUN_141bd04d0(m_post.m_nBannerId);
    if (spEntity == 0)
        return;
    NiTexturePtr spTexture = m_spImage;
    FUN_14052d220()->FUN_141888770(spEntity, spTexture);
}

// ---- CUgcViewerProfile --------------------------------------------------------------------------------------------

// @0x1418a10e0
CUgcViewerProfile::CUgcViewerProfile()
{
    m_bRefreshed = 0;
    m_user.Clear();
}

// @0x1418a1160
CUgcViewerProfile::~CUgcViewerProfile()
{
}

// @0x1418a11a0
int CUgcViewerProfile::vfunc_3(MS2Ptr<CUploadFile> spFile)
{
    if (spFile == 0)
        return 0;
    MS2Ptr<CUgcUploadCtrl> spCtrl = FUN_14052d220()->FUN_141882610();
    if (spCtrl == 0)
        return 0;
    GameObject* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    CStringW strPath = spFile->GetPath();
    if (_waccess(strPath, 0) != 0)
        return 0;
    CStringW strThumb = spFile->GetThumbnailPath();
    if (strThumb.GetLength() == 0)
        return 0;
    spCtrl->m_spFile = spFile;
    void* pDialog = FUN_140938c30(0x2711);
    if (pDialog == 0)
        return 0;
    FUN_14132faf0(pDialog, strThumb);
    return 1;
}

// @0x1418a1430
void CUgcViewerProfile::vfunc_4()
{
    void* pDialog = FUN_140938c30(0x2711);
    if (pDialog == 0)
        return;
    FUN_14132fa90(pDialog);
}

// @0x1418a1470
void CUgcViewerProfile::vfunc_5()
{
    m_bRefreshed = 1;
}

// @0x1418a1490
CString CUgcViewerProfile::vfunc_11()
{
    CString str;
    str = Unk_SocketFormat("[viewer={0}] [objectId={1}]", "UgcViewerProfile", m_user.m_strObjectName);
    return str;
}

// @0x1418a1540
int CUgcViewerProfile::vfunc_13(MS2Ptr<IUgcProxy> spProxy)
{
    if (spProxy == 0)
        return 0;
    IUgcProxy* pProxy = spProxy.get();
    if (pProxy == 0)
        return 0;
    pProxy->CopyFrom(&m_user);
    return 1;
}

// @0x1418a1600
int CUgcViewerProfile::vfunc_9()
{
    return 0x6b;
}

// ---- CUgcViewerWeddingProfile -------------------------------------------------------------------------------------

// @0x1418a1620
CUgcViewerWeddingProfile::CUgcViewerWeddingProfile()
{
    m_bRefreshed = 0;
    m_user.Clear();
}

// @0x1418a1670
CUgcViewerWeddingProfile::~CUgcViewerWeddingProfile()
{
}

// @0x1418a16b0
int CUgcViewerWeddingProfile::vfunc_3(MS2Ptr<CUploadFile> spFile)
{
    if (spFile == 0)
        return 0;
    MS2Ptr<CUgcUploadCtrl> spCtrl = FUN_14052d220()->FUN_141882610();
    if (spCtrl == 0)
        return 0;
    GameObject* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (FUN_140d295d0(FUN_1409eed90())->m_nState != 2)
        return 0;
    CStringW strPath = spFile->GetPath();
    if (_waccess(strPath, 0) != 0)
        return 0;
    CStringW strThumb = spFile->GetThumbnailPath();
    if (strThumb.GetLength() == 0)
        return 0;
    spCtrl->m_spFile = spFile;
    void* pDialog = FUN_1418764c0(0x4f8c);
    if (pDialog == 0)
        return 0;
    FUN_140fc7e80(pDialog, strThumb);
    return 1;
}

// @0x1418a1970
void CUgcViewerWeddingProfile::vfunc_4()
{
    void* pDialog = FUN_1418764c0(0x4f8c);
    if (pDialog == 0)
        return;
    FUN_140fc7f30(pDialog);
}

// @0x1418a19b0
void CUgcViewerWeddingProfile::vfunc_5()
{
    m_bRefreshed = 1;
}

// @0x1418a19d0
CString CUgcViewerWeddingProfile::vfunc_11()
{
    CString str;
    str = FUN_1411c0aa0("[viewer=UgcViewerWeddingProfile]");
    return str;
}

// @0x1418a1a70
int CUgcViewerWeddingProfile::vfunc_13(MS2Ptr<IUgcProxy> spProxy)
{
    if (spProxy == 0)
        return 0;
    IUgcProxy* pProxy = spProxy.get();
    if (pProxy == 0)
        return 0;
    pProxy->CopyFrom(&m_user);
    return 1;
}

// @0x1418a1b30
int CUgcViewerWeddingProfile::vfunc_9()
{
    return 0xaa;
}

// ---- CUgcViewerGuildMark ------------------------------------------------------------------------------------------

// @0x1418a1b50
CUgcViewerGuildMark::CUgcViewerGuildMark()
{
    m_bRefreshed = 0;
    m_mark.Clear();
}

// @0x1418a1bd0
CUgcViewerGuildMark::~CUgcViewerGuildMark()
{
}

// @0x1418a1c10
int CUgcViewerGuildMark::vfunc_3(MS2Ptr<CUploadFile> spFile)
{
    if (spFile == 0)
        return 0;
    MS2Ptr<CUgcUploadCtrl> spCtrl = FUN_14052d220()->FUN_141882610();
    if (spCtrl == 0)
        return 0;
    GameObject* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (FUN_1404ccbd0((char*)FUN_1403ed290() + 8) == 0)
        return 0;
    CStringW strPath = spFile->GetPath();
    if (_waccess(strPath, 0) != 0)
        return 0;
    CStringW strThumb = spFile->GetThumbnailPath();
    if (strThumb.GetLength() == 0)
        return 0;
    spCtrl->m_spFile = spFile;
    void* pDialog = FUN_14136f480(0x4e4f);
    if (pDialog == 0)
        return 0;
    FUN_141976980(pDialog, strThumb);
    return 1;
}

// @0x1418a1ee0
void CUgcViewerGuildMark::vfunc_4()
{
    void* pDialog = FUN_14136f480(0x4e4f);
    if (pDialog == 0)
        return;
    FUN_1419769d0(pDialog);
}

// @0x1418a1f20
void CUgcViewerGuildMark::vfunc_5()
{
    m_bRefreshed = 1;
}

// @0x1418a1f40
CString CUgcViewerGuildMark::vfunc_11()
{
    CString str;
    str = Unk_SocketFormat("[viewer={0}] [guild={1}] [objectId={2}]", "UgcViewerGuildMark", VW_U64(m_mark.m_nGuildId), m_mark.m_strName);
    return str;
}

// @0x1418a2000
void CUgcViewerGuildMark::vfunc_6(COutPacket& packet)
{
    m_mark.Write(packet);
}

// @0x1418a2040
int CUgcViewerGuildMark::vfunc_13(MS2Ptr<IUgcProxy> spProxy)
{
    if (spProxy == 0)
        return 0;
    IUgcProxy* pProxy = spProxy.get();
    if (pProxy == 0)
        return 0;
    pProxy->CopyFrom(&m_mark);
    return 1;
}

// @0x1418a2100
int CUgcViewerGuildMark::vfunc_9()
{
    return 0x6b;
}

// ---- CUgcViewerGuildPoster ----------------------------------------------------------------------------------------

// @0x1418a2120
CUgcViewerGuildPoster::CUgcViewerGuildPoster()
{
    m_bRefreshed = 0;
    m_poster.Clear();
}

// @0x1418a21a0
CUgcViewerGuildPoster::~CUgcViewerGuildPoster()
{
}

// @0x1418a21e0
int CUgcViewerGuildPoster::vfunc_3(MS2Ptr<CUploadFile> spFile)
{
    if (spFile == 0)
        return 0;
    MS2Ptr<CUgcUploadCtrl> spCtrl = FUN_14052d220()->FUN_141882610();
    if (spCtrl == 0)
        return 0;
    GameObject* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (FUN_1404ccbd0((char*)FUN_1403ed290() + 8) == 0)
        return 0;
    CStringW strPath = spFile->GetPath();
    if (_waccess(strPath, 0) != 0)
        return 0;
    CStringW strThumb = spFile->GetThumbnailPath();
    if (strThumb.GetLength() == 0)
        return 0;
    spCtrl->m_spFile = spFile;
    MS2Ptr<CInteractObject> spObject = FUN_1403ed2d0()->FUN_141bc66b0(m_poster.m_strName);
    CInteractGuildPosterObject* pPoster = dynamic_cast<CInteractGuildPosterObject*>(spObject.get());
    if (pPoster != 0)
        FUN_141403180(pPoster, strThumb);
    return 1;
}

// @0x1418a2520
void CUgcViewerGuildPoster::vfunc_4()
{
    MS2Ptr<CInteractObject> spObject = FUN_1403ed2d0()->FUN_141bc66b0(m_poster.m_strName);
    CInteractGuildPosterObject* pPoster = dynamic_cast<CInteractGuildPosterObject*>(spObject.get());
    if (pPoster != 0)
        FUN_141402eb0(pPoster, 1);
}

// @0x1418a25d0
void CUgcViewerGuildPoster::vfunc_5()
{
    m_bRefreshed = 1;
}

// @0x1418a25f0
CString CUgcViewerGuildPoster::vfunc_11()
{
    CString str;
    str = Unk_SocketFormat("[viewer={0}] [guild={1}] [objectId={2}]", "CUgcViewerGuildPoster", VW_U64(m_poster.m_nGuildId), m_poster.m_strName);
    return str;
}

// @0x1418a26b0
void CUgcViewerGuildPoster::vfunc_6(COutPacket& packet)
{
    m_poster.Write(packet);
}

// @0x1418a26f0
int CUgcViewerGuildPoster::vfunc_13(MS2Ptr<IUgcProxy> spProxy)
{
    if (spProxy == 0)
        return 0;
    IUgcProxy* pProxy = spProxy.get();
    if (pProxy == 0)
        return 0;
    pProxy->CopyFrom(&m_poster);
    return 1;
}

// @0x1418a27b0
int CUgcViewerGuildPoster::vfunc_9()
{
    return 0x6b;
}

// ---- CUgcViewerRidee ----------------------------------------------------------------------------------------------

// @0x1418a27d0
CUgcViewerRidee::CUgcViewerRidee()
{
}

// @0x1418a2830
CUgcViewerRidee::~CUgcViewerRidee()
{
}

// @0x1418a2880
int CUgcViewerRidee::vfunc_2()
{
    efd::SmartPointer<AvatarRidee> spRidee = efd::DynamicCast<AvatarRidee>(FUN_1403ed2d0()->FUN_141bd0fa0(FUN_1418a2fc0()));
    if (spRidee == 0)
        return 0;
    MS2Ptr<CItemUgcMeshContainer> spMeshes = spRidee->GetUgcMesh();
    if (spMeshes == 0)
        return 0;
    NiTexturePtr spTexture = spMeshes->FUN_141426e30();
    if (spTexture == 0)
        return 0;
    CStringW strError;
    int nResult = FUN_14186ced0(spTexture, m_item.m_nItemId, 7, strError);
    if (nResult != 0)
        return 0;
    return 1;
}

// @0x1418a2a80
int CUgcViewerRidee::vfunc_3(MS2Ptr<CUploadFile> spFile)
{
    if (spFile == 0)
        return 0;
    MS2Ptr<CUgcUploadCtrl> spCtrl = FUN_14052d220()->FUN_141882610();
    if (spCtrl == 0)
        return 0;
    CStringW strPath = spFile->GetPath();
    NiTexturePtr spTexture = FUN_14186bd30(strPath, vfunc_9(), true);
    if (spTexture == 0)
        return 0;
    if (FUN_14052d220()->FUN_141887160(&m_item, spTexture) == 0)
        return 0;
    spCtrl->m_spFile = spFile;
    return 1;
}

// @0x1418a2ca0
void CUgcViewerRidee::vfunc_4()
{
    efd::SmartPointer<AvatarRidee> spRidee = efd::DynamicCast<AvatarRidee>(FUN_1403ed2d0()->FUN_141bd0fa0(FUN_1418a2fc0()));
    if (spRidee == 0)
        return;
    spRidee->FUN_141085250();
}

// @0x1418a2d50
void CUgcViewerRidee::vfunc_5()
{
}

// @0x1418a2d60
CString CUgcViewerRidee::vfunc_11()
{
    CString str;
    str = Unk_SocketFormat("[viewer={0}] [itemSN={1}]", "UgcViewerRidee", VW_U64(m_item.m_itemUid));
    return str;
}

// @0x1418a2e10
void CUgcViewerRidee::vfunc_6(COutPacket& packet)
{
    m_item.Write(packet);
}

// @0x1418a2e50
int CUgcViewerRidee::vfunc_8(MS2Ptr<IUgcProxy> spProxy, int nKind)
{
    if (spProxy == 0)
        return 0;
    if (nKind == 7)
    {
        IUgcProxy* pProxy = spProxy.get();
        if (pProxy == 0)
            return 0;
        pProxy->CopyFrom(&m_item);
    }
    else if (nKind == 0xc9)
    {
        CUgcItemIconPC* pProxy = static_cast<CUgcItemIconPC*>(spProxy.get());
        if (pProxy == 0)
            return 0;
        pProxy->CopyFrom(&m_icon);
        pProxy->m_nKind = 2;
    }
    return 1;
}

// @0x1418a2f90
void CUgcViewerRidee::vfunc_12(__int64 itemUid)
{
    m_item.m_itemUid = itemUid;
    m_icon.m_itemUid = itemUid;
}

// @0x1418a2fc0
egf::EntityID CUgcViewerRidee::FUN_1418a2fc0()
{
    return m_item.m_entityId;
}

// @0x1418a3000
void CUgcViewerRidee::FUN_1418a3000(const egf::EntityID& id)
{
    m_item.m_entityId = id;
}

// ---- CUgcViewerBlueprintImage (the image proxy at +0x18, the icon proxy at +0x50, the refreshed flag at +0xe8) ----

// (the members are declared in cugcuploadctrl.h)












// The create dialog of a blueprint item (0x4f7b), if it is open.
UIItemBlueprintCreateDialog* FUN_1418a6920();
int FUN_1418a7190();

// @0x1418a3030
CUgcViewerBlueprintImage::CUgcViewerBlueprintImage()
{


    m_bRefreshed = 0;
    m_proxy.Clear();
    m_icon.Clear();
}

// @0x1418a30f0
CUgcViewerBlueprintImage::~CUgcViewerBlueprintImage()
{


}

// @0x1418a3140
int CUgcViewerBlueprintImage::vfunc_3(MS2Ptr<CUploadFile> spFile)
{
    if (spFile == 0)
        return 0;
    MS2Ptr<CUgcUploadCtrl> spCtrl = FUN_14052d220()->FUN_141882610();
    if (spCtrl == 0)
        return 0;
    CStringW strPath = spFile->GetPath();
    if (_waccess(strPath, 0) != 0)
        return 0;
    CStringW strThumb = spFile->GetThumbnailPath();
    if (strThumb.GetLength() == 0)
        return 0;
    spCtrl->m_spFile = spFile;
    UIItemBlueprintCreateDialog* pDialog = FUN_1418a6920();
    if (pDialog == 0)
        return 0;
    FUN_140c381b0(pDialog, spFile);
    return 1;
}

// @0x1418a33a0
void CUgcViewerBlueprintImage::vfunc_4()
{
    UIItemBlueprintCreateDialog* pDialog = FUN_1418a6920();
    if (pDialog != 0)
        FUN_140c38240(pDialog);
}

// @0x1418a33d0
void CUgcViewerBlueprintImage::vfunc_5()
{
    m_bRefreshed = 1;
}

// @0x1418a33f0
CString CUgcViewerBlueprintImage::vfunc_11()
{
    CString str;
    str = Unk_SocketFormat("[viewer={0}] [blueprint_item_sn={1}]", "UgcViewerBlueprintImage", VW_U64(m_proxy.m_n18));
    return str;
}

// @0x1418a34a0
void CUgcViewerBlueprintImage::vfunc_6(COutPacket& packet)
{
    m_proxy.Write(packet);
}

// @0x1418a34e0
int CUgcViewerBlueprintImage::vfunc_8(MS2Ptr<IUgcProxy> spProxy, int nKind)
{
    if (spProxy == 0)
        return 0;
    if (nKind == 9)
    {
        IUgcProxy* pProxy = spProxy.get();
        if (pProxy == 0)
            return 0;
        pProxy->CopyFrom(&m_proxy);
    }
    else if (nKind == 0xd1)
    {
        CUgcItemIconPC* pProxy = static_cast<CUgcItemIconPC*>(spProxy.get());
        if (pProxy == 0)
            return 0;
        pProxy->CopyFrom(&m_icon);
        pProxy->m_nKind = 4;
    }
    return 1;
}

// @0x1418a6920
UIItemBlueprintCreateDialog* FUN_1418a6920()
{
    Unk_VwUIService* pService = FUN_1403ed2b0();
    if (pService == 0)
        return 0;
    Unk_CommandUIRef ref = pService->FUN_141adcea0(FUN_1418a7190());
    if (FUN_140534e80(ref))
        return 0;
    return dynamic_cast<UIItemBlueprintCreateDialog*>(FUN_1403ed9e0(ref));
}

// ---- viewer vfunc_10 getters, base stubs --------------------------------------------------------------------------

// @0x1418a70e0
__int64 CUgcViewerBanner::vfunc_10()
{
    return (unsigned)m_post.m_nBannerId;
}

// @0x1418a70f0
__int64 CUgcViewerBlueprintImage::vfunc_10()
{
    return m_proxy.m_n18;
}

// @0x1418a7100
__int64 CUgcViewerCube::vfunc_10()
{
    return (unsigned)m_item.m_nItemId;
}

// @0x1418a7110
__int64 CUgcViewerEquip::vfunc_10()
{
    return (unsigned)m_item.m_nItemId;
}

// @0x1418a7120
__int64 CUgcViewerGuildMark::vfunc_10()
{
    return m_mark.m_nGuildId;
}

// @0x1418a7130
__int64 CUgcViewerGuildPoster::vfunc_10()
{
    return m_poster.m_nGuildId;
}

// @0x1418a7140
__int64 CUgcViewerProfile::vfunc_10()
{
    return m_user.m_characterId;
}

// @0x1418a7150
__int64 CUgcViewerRidee::vfunc_10()
{
    return (unsigned)m_item.m_nItemId;
}

// @0x1418a7160
__int64 CUgcViewerWeddingProfile::vfunc_10()
{
    return m_user.m_characterId;
}

// @0x1418a6c20
IUgcViewer::IUgcViewer()
{
}

// @0x1418a6c90
IUgcViewer::~IUgcViewer()
{
}

// @0x1418a70a0
int IUgcViewer::vfunc_2()
{
    return 0;
}

// @0x1418a70b0
int IUgcViewer::vfunc_8(MS2Ptr<IUgcProxy> spProxy, int nKind)
{
    return 0;
}

// @0x1418a7170
__int64 IUgcViewer::vfunc_10()
{
    return 0;
}

// @0x1418a7180
int IUgcViewer::vfunc_9()
{
    return 0x200;
}

// @0x1418a7190
int FUN_1418a7190()
{
    return 0x4f7b;
}

// @0x1418a71a0
void IUgcViewer::vfunc_6(COutPacket& packet)
{
}

// @0x1418a71b0
void IUgcViewer::vfunc_7(void* p)
{
}

// @0x1418a71c0
void IUgcViewer::vfunc_12(__int64 itemUid)
{
}

// @0x1418a71d0
void IUgcViewer::vfunc_5()
{
}

// @0x1418a71e0
void IUgcViewer::vfunc_1()
{
}

// ---- CUgcUploadCtrl -----------------------------------------------------------------------------------------------

// @0x1418a3620
CUgcUploadCtrl::CUgcUploadCtrl()
{
    Clear();
    m_spViewer = 0;
    m_spFile = 0;
    m_itemUid = 0;
    m_spImage = 0;
    m_nExtra = 0;
    m_strResult = "";
}

// @0x1418a3740
CUgcUploadCtrl::~CUgcUploadCtrl()
{
    Clear();
    m_spViewer = 0;
    m_spFile = 0;
    m_itemUid = 0;
    m_spImage = 0;
    m_nDialog = 0;
}

// @0x1418a3840
void CUgcUploadCtrl::FUN_1418a3840(int nType)
{
    Clear();
    m_nKind = nType;
    m_user.m_nType = DAT_143ab2830;
    m_user.m_accountId = DAT_143ab2820;
    m_user.m_characterId = DAT_143ab2828;
}

// @0x1418a38a0
void CUgcUploadCtrl::FUN_1418a38a0()
{
    Unk_VwDialogUi* pDialog = FUN_140c300a0(m_nDialog);
    if (pDialog != 0 && pDialog->vfunc_55() != 1 && m_spViewer.get() != 0)
    {
        m_spViewer->vfunc_5();
        m_spViewer->vfunc_1();
        if (m_spFile.get() != 0)
        {
            if (m_spFile->Refresh() != 0)
            {
                ConvertIconFile(m_spFile->GetPath());
                m_spViewer->vfunc_3(m_spFile);
                FUN_140bc09f0()->vfunc_4(m_nDialog);
            }
        }
    }
}

// @0x1418a3ab0
void CUgcUploadCtrl::SetDialog(int nDialog)
{
    m_nDialog = nDialog;
}

// @0x1418a3ad0
int CUgcUploadCtrl::GetDialog()
{
    return m_nDialog;
}

// @0x1418a3af0
void CUgcUploadCtrl::FUN_1418a3af0(int nResult)
{
    if (m_nDialog != nResult)
        return;
    if (m_spViewer == 0)
        return;
    if (m_upload.m_nType == 3)
        return;
    m_spViewer->vfunc_4();
}

// @0x1418a3b80
int CUgcUploadCtrl::FUN_1418a3b80(__int64 uid)
{
    int nResult = 1;
    nResult = FUN_1418a3c20(uid);
    if (nResult != 0)
        return nResult;
    FUN_1418a3db0();
    return 0;
}

// @0x1418a3bd0
CStringW CUgcUploadCtrl::GetResult()
{
    return m_strResult;
}

// @0x1418a3c20
int CUgcUploadCtrl::FUN_1418a3c20(__int64 uid)
{
    int nResult = 1;
    switch (m_nKind)
    {
    case 1:
    case 2:
    case 3:
    case 7:
        nResult = FUN_1418a4470(uid);
        break;
    case 0xc9:
    case 0xd1:
        nResult = FUN_1418a4690();
        break;
    case 5:
    case 6:
    case 8:
    case 10:
        nResult = FUN_1418a43d0();
        break;
    case 9:
        nResult = FUN_1418a4780();
    }
    return nResult;
}

// @0x1418a3db0
// MS2-FUNCTIONAL: second upload (the preview image) of an item/cube/mount/blueprint upload
void CUgcUploadCtrl::FUN_1418a3db0()
{
    if (m_nKind == 1 || m_nKind == 2 || m_nKind == 7 || m_nKind == 9)
    {
        CStringW strDir = FUN_14016a730(static_cast<Unk_VwConfig*>(FUN_1401d31f0())->m_strUploadDir, 0);
        if (_waccess(strDir, 0) == 0)
        {
            MS2Ptr<CUploadFile> spFile(new CUploadFile());
            CStringW strName = FUN_14016a730("upload_i.png", 0);
            spFile->Set(strDir, strName, 0, 0, 0);
            m_spImage.AssignRaw(new CUgcUploadCtrl());
            m_spImage->m_nKind = m_nKind == 9 ? 0xd1 : 0xc9;
            m_spImage->m_user.CopyFrom(&m_user);
            m_spImage->m_upload.CopyFrom(&m_upload);
            m_spImage->m_spFile = spFile;
            m_spImage->m_spViewer = m_spViewer;
            m_spImage->FUN_1418a3c20(0);
        }
    }
}

// @0x1418a4100
MS2Ptr<CUgcUploadCtrl> CUgcUploadCtrl::GetImage()
{
    return m_spImage;
}

// @0x1418a4150
void CUgcUploadCtrl::FUN_1418a4150()
{
    m_nExtra = m_spViewer->vfunc_10();
}

// @0x1418a41a0
__int64 CUgcUploadCtrl::FUN_1418a41a0()
{
    if (m_nExtra == 0)
        FUN_1418a4150();
    return m_nExtra;
}

// @0x1418a41e0
CString CUgcUploadCtrl::FUN_1418a41e0()
{
    CString str;
    CString strViewer;
    if (m_spViewer.get() != 0)
        strViewer = m_spViewer->vfunc_11();
    str = Unk_SocketFormat("[accSN={0}] [charSN={1}] [dialog={2}] [extraParam={3}] [uploadPath={4}] {5}", VW_U64(DAT_143ab2820), VW_U64(DAT_143ab2828), reinterpret_cast<Unk_VwDialogId&>(m_nDialog), VW_U64(m_nExtra), FUN_14016a600(m_strResult, 0), strViewer);
    return str;
}

// @0x1418a43d0
int CUgcUploadCtrl::FUN_1418a43d0()
{
    if (m_spFile == 0)
        return 0xb;
    m_strResult = m_spFile->GetThumbnailDir();
    return 0;
}

// @0x1418a4470
int CUgcUploadCtrl::FUN_1418a4470(__int64 uid)
{
    if (m_spFile == 0)
        return 0xb;
    int nSize = m_spViewer->vfunc_9();
    Unk_UgcFileResult result = ChangeFormat(m_nKind, m_spFile, nSize, FUN_14036e510(FUN_140166410()));
    int nResult = result.m_nResult;
    if (nResult == 0)
    {
        CUgcCompress compress;
        nResult = compress.Compress(result.m_strPath, (void*)uid);
        if (nResult == 0)
        {
            m_strResult = compress.GetZipFile();
            if (result.m_bTemporary == 1)
                DeleteFileW(result.m_strPath);
            nResult = 0;
        }
    }
    return nResult;
}

// @0x1418a4690
int CUgcUploadCtrl::FUN_1418a4690()
{
    if (m_spFile == 0)
        return 0xb;
    Unk_UgcFileResult result = ChangeFormat(m_nKind, m_spFile, 0x30, 0);
    int nResult = result.m_nResult;
    if (nResult == 0)
    {
        m_strResult = result.m_strPath;
        nResult = 0;
    }
    return nResult;
}

// @0x1418a4780
int CUgcUploadCtrl::FUN_1418a4780()
{
    if (m_spFile == 0)
        return 0xb;
    int nSize = m_spViewer->vfunc_9();
    Unk_UgcFileResult result = ChangeFormat(m_nKind, m_spFile, nSize, 0);
    int nResult = result.m_nResult;
    if (nResult == 0)
    {
        m_strResult = result.m_strPath;
        nResult = 0;
    }
    return nResult;
}

// @0x1418a71f0
// MS2-FUNCTIONAL: CRT memcpy_s copy (library lane); same checks and errno values as the CRT
unsigned __int64 FUN_1418a71f0(void* pDst, unsigned __int64 nDstSize, const void* pSrc, unsigned __int64 nCount)
{
    if (nCount == 0)
        return 0;
    if (pDst == 0 || pSrc == 0 || nDstSize < nCount)
    {
        int nErr = (pDst == 0 || pSrc == 0) ? 22 : 34;
        *_errno() = nErr;
        _invalid_parameter_noinfo();
        return nErr;
    }
    memmove(pDst, pSrc, nCount);
    return 0;
}
