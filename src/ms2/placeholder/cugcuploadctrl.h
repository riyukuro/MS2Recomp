// cugcuploadctrl.h - PLACEHOLDER for CUgcUploadCtrl (RTTI .?AVCUgcUploadCtrl@@, 0xe8 bytes, vftable 0x142f8f020) and the
// IUgcViewer family (vftable 0x142f8eb98, 13 slots; the profile / banner / guild viewers add slot 13). NOT an original
// header. The classes are defined in ?\ugcviewerequip.cpp (0x14189eae0-); the layouts and the methods declared here
// are the ones CUgcManager (client\ms2\ugcmanager.cpp#4) uses.
//
// An upload in progress: the content kind, the owner and the upload proxies that go to the server, the viewer that
// previews the content in its dialog and the local file to send.
#pragma once

#include <afx.h>
#include <efd/SmartPointer.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/commonfiles/ugcdef.h"
#include "ms2/unnamed/unit_1401b6d10.h"

class NiTexture;

class CUploadFile;
class COutPacket;
class CItem;
class NiAVObject;
class NiTexturingProperty;
class NiSourceTexture;

// The preview of an upload kind (equip, cube, banner, profile, guild mark, ...). Slot 0 is the deleting destructor.
class IUgcViewer : public CPtred
{
public:
    IUgcViewer();                                           // 0x1418a6c20
    virtual ~IUgcViewer();                                  // 0 (0x1418a6c90, ??_G 0x1418a7060)
    virtual void vfunc_1();                                 // 1 (banner: show the banner object's decal)
    virtual int vfunc_2();                                  // 2 the viewer has content to upload (base: 0)
    virtual int vfunc_3(MS2Ptr<CUploadFile> spFile) = 0;    // 3 preview a local file
    virtual void vfunc_4() = 0;                             // 4 the upload finished
    virtual void vfunc_5();                                 // 5 refresh the preview data
    virtual void vfunc_6(COutPacket& packet);               // 6 write the preview data of an item upload
    virtual void vfunc_7();                                 // 7
    virtual int vfunc_8(MS2Ptr<IUgcProxy> spProxy, int nKind);   // 8 the uploaded content to download (0: none)
    virtual int vfunc_9();                                  // 9 the largest image size (base 0x200)
    virtual __int64 vfunc_10();                             // 10 the owner id of the content (base 0)
    virtual CString vfunc_11() = 0;                         // 11 the log text of the viewer
    virtual void vfunc_12(__int64 itemUid);                 // 12 an item to preview
};
MS2_CHECK_SIZE(IUgcViewer, 0x18);

// The item viewers (equip / cube / mount): the item proxy of the upload at +0x18 and the icon proxy at +0x68.
class CUgcViewerEquip : public IUgcViewer
{
public:
    CUgcViewerEquip();                                      // 0x14189eae0
    explicit CUgcViewerEquip(CItem* pItem);                 // 0x14189ec30
    virtual ~CUgcViewerEquip();                             // 0x14189ed40 (??_G 0x1418a6ee0)
    virtual int vfunc_2();
    virtual int vfunc_3(MS2Ptr<CUploadFile> spFile);
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(COutPacket& packet);
    virtual void vfunc_7();
    virtual int vfunc_8(MS2Ptr<IUgcProxy> spProxy, int nKind);
    virtual __int64 vfunc_10();
    virtual CString vfunc_11();
    virtual void vfunc_12(__int64 itemUid);

    int FUN_14189f730();                                    // the wearer's object id
    void FUN_14189f750(int nObjectId);
    MS2Ptr<IUgcProxy> FUN_14189f770(MS2Ptr<IUgcProxy> spOut);

    CUgcItemPC m_item;                                      // +0x18
    CUgcItemIconPC m_icon;                                  // +0x68
    CString m_strMesh;                                      // +0x100 the UGC mesh name of the item
    int m_n108;                                             // +0x108
    efd::SmartPointer<NiAVObject> m_spMesh;                 // +0x110
    efd::SmartPointer<NiTexturingProperty> m_spProperty;    // +0x118
    efd::SmartPointer<NiSourceTexture> m_spTexture;         // +0x120
};
MS2_CHECK_SIZE(CUgcViewerEquip, 0x128);
MS2_CHECK_OFFSET(CUgcViewerEquip, m_item, 0x18);
MS2_CHECK_OFFSET(CUgcViewerEquip, m_icon, 0x68);
MS2_CHECK_OFFSET(CUgcViewerEquip, m_strMesh, 0x100);
MS2_CHECK_OFFSET(CUgcViewerEquip, m_spTexture, 0x120);

class CUgcViewerCube : public IUgcViewer
{
public:
    CUgcViewerCube();                                       // 0x14189f7c0
    virtual ~CUgcViewerCube();                              // 0x14189f840 (??_G 0x1418a6ea0)
    virtual int vfunc_2();
    virtual int vfunc_3(MS2Ptr<CUploadFile> spFile);
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(COutPacket& packet);
    virtual int vfunc_8(MS2Ptr<IUgcProxy> spProxy, int nKind);
    virtual __int64 vfunc_10();
    virtual CString vfunc_11();
    virtual void vfunc_12(__int64 itemUid);

    egf::EntityID FUN_1418a0110();                          // the cube's entity id
    void FUN_1418a0150(const egf::EntityID& id);

    CUgcItemCube m_item;                                    // +0x18
    CUgcItemIconPC m_icon;                                  // +0x68
    CString m_strMesh;                                      // +0x100
};
MS2_CHECK_SIZE(CUgcViewerCube, 0x108);
MS2_CHECK_OFFSET(CUgcViewerCube, m_item, 0x18);
MS2_CHECK_OFFSET(CUgcViewerCube, m_icon, 0x68);

class CUgcViewerRidee : public IUgcViewer
{
public:
    CUgcViewerRidee();                                      // 0x1418a27d0
    virtual ~CUgcViewerRidee();                             // 0x1418a2830 (??_G 0x1418a6fe0)
    virtual int vfunc_2();
    virtual int vfunc_3(MS2Ptr<CUploadFile> spFile);
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(COutPacket& packet);
    virtual int vfunc_8(MS2Ptr<IUgcProxy> spProxy, int nKind);
    virtual __int64 vfunc_10();
    virtual CString vfunc_11();
    virtual void vfunc_12(__int64 itemUid);

    egf::EntityID FUN_1418a2fc0();                          // the mount's entity id
    void FUN_1418a3000(const egf::EntityID& id);

    CUgcItemRidee m_item;                                   // +0x18
    CUgcItemIconPC m_icon;                                  // +0x68
    char m_pad_100[8];                                      // +0x100 (never written; the sized delete frees 0x108)
};
MS2_CHECK_SIZE(CUgcViewerRidee, 0x108);
MS2_CHECK_OFFSET(CUgcViewerRidee, m_item, 0x18);
MS2_CHECK_OFFSET(CUgcViewerRidee, m_icon, 0x68);

class CUgcViewerProfile : public IUgcViewer
{
public:
    CUgcViewerProfile();                                    // 0x1418a10e0
    virtual ~CUgcViewerProfile();                           // 0x1418a1160 (??_G 0x1418a7...)
    virtual int vfunc_3(MS2Ptr<CUploadFile> spFile);
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual int vfunc_9();
    virtual __int64 vfunc_10();
    virtual CString vfunc_11();
    virtual int vfunc_13(MS2Ptr<IUgcProxy> spProxy);        // 13 the uploaded content to download
    CUgcUserProxy m_user;                                   // +0x18
    int m_bRefreshed;                                       // +0x58
    char m_pad_5c[0x60 - 0x5c];
};
MS2_CHECK_SIZE(CUgcViewerProfile, 0x60);

class CUgcViewerWeddingProfile : public IUgcViewer
{
public:
    CUgcViewerWeddingProfile();                             // 0x1418a1620
    virtual ~CUgcViewerWeddingProfile();                    // 0x1418a1670
    virtual int vfunc_3(MS2Ptr<CUploadFile> spFile);
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual int vfunc_9();
    virtual __int64 vfunc_10();
    virtual CString vfunc_11();
    virtual int vfunc_13(MS2Ptr<IUgcProxy> spProxy);
    CUgcUserProxy m_user;                                   // +0x18
    int m_bRefreshed;                                       // +0x58
    char m_pad_5c[0x60 - 0x5c];
};
MS2_CHECK_SIZE(CUgcViewerWeddingProfile, 0x60);

class CUgcViewerGuildMark : public IUgcViewer
{
public:
    CUgcViewerGuildMark();                                  // 0x1418a1b50
    virtual ~CUgcViewerGuildMark();                         // 0x1418a1bd0
    virtual int vfunc_3(MS2Ptr<CUploadFile> spFile);
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(COutPacket& packet);
    virtual int vfunc_9();
    virtual __int64 vfunc_10();
    virtual CString vfunc_11();
    virtual int vfunc_13(MS2Ptr<IUgcProxy> spProxy);
    CUgcGuildMarkProxy m_mark;                              // +0x18
    int m_bRefreshed;                                       // +0x40
    char m_pad_44[0x48 - 0x44];
};
MS2_CHECK_SIZE(CUgcViewerGuildMark, 0x48);

class CUgcViewerGuildPoster : public IUgcViewer
{
public:
    CUgcViewerGuildPoster();                                // 0x1418a2120
    virtual ~CUgcViewerGuildPoster();                       // 0x1418a21a0
    virtual int vfunc_3(MS2Ptr<CUploadFile> spFile);
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(COutPacket& packet);
    virtual int vfunc_9();
    virtual __int64 vfunc_10();
    virtual CString vfunc_11();
    virtual int vfunc_13(MS2Ptr<IUgcProxy> spProxy);
    CUgcGuildPosterProxy m_poster;                          // +0x18
    int m_bRefreshed;                                       // +0x48
    char m_pad_4c[0x50 - 0x4c];
};
MS2_CHECK_SIZE(CUgcViewerGuildPoster, 0x50);

// The banner viewer. +0x18 is a CUgcBannerPost (m_nBannerId is its id at +0x30), +0x68 the "decal loaded" state,
// +0x70 the image and +0x78 the banner table record.
class CUgcViewerBanner : public IUgcViewer
{
public:
    CUgcViewerBanner();                                     // 0x1418a0180
    virtual ~CUgcViewerBanner();                            // 0x1418a0250 (??_G 0x1418a6e20)
    virtual void vfunc_1();
    virtual int vfunc_2();
    virtual int vfunc_3(MS2Ptr<CUploadFile> spFile);
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(COutPacket& packet);
    virtual int vfunc_9();
    virtual __int64 vfunc_10();
    virtual CString vfunc_11();
    virtual int vfunc_13(MS2Ptr<IUgcProxy> spProxy);
    void FUN_1418a0f90(int nBannerId);                      // the banner to preview
    void FUN_1418a1000();                                   // show the image on the banner object

    CUgcBannerPost m_post;                                  // +0x18 the posted banner (its m_nBannerId at +0x30)
    int m_nLoaded;                                          // +0x68 the decal state
    efd::SmartPointer<NiTexture> m_spImage;                 // +0x70 the image shown on the banner
    Unk_BannerPtr m_spBanner;                               // +0x78 the banner row (TPtr<CFieldBannerData>)
};
MS2_CHECK_SIZE(CUgcViewerBanner, 0x88);
MS2_CHECK_OFFSET(CUgcViewerBanner, m_post, 0x18);
MS2_CHECK_OFFSET(CUgcViewerBanner, m_spBanner, 0x78);
static_assert(offsetof(CUgcViewerBanner, m_post) + offsetof(CUgcBannerPost, m_nBannerId) == 0x30, "banner id at +0x30");

// The blueprint image viewer: the image proxy at +0x18, the icon proxy at +0x50, the "refreshed" flag at +0xe8.

class CUgcViewerBlueprintImage : public IUgcViewer
{
public:
    CUgcViewerBlueprintImage();                             // 0x1418a3030
    virtual ~CUgcViewerBlueprintImage();                    // 0x1418a30f0 (??_G 0x1418a6e60)
    virtual int vfunc_3(MS2Ptr<CUploadFile> spFile);
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(COutPacket& packet);
    virtual int vfunc_8(MS2Ptr<IUgcProxy> spProxy, int nKind);
    virtual __int64 vfunc_10();
    virtual CString vfunc_11();

    CUgcBlueprintImageProxy m_proxy;                        // +0x18 m_n18 = CBlueprintItemData::m_n18, m_n20 = the item
                                                            //       uid, m_n28 = CItem::FUN_1405276c0
    CUgcItemIconPC m_icon;                                  // +0x50
    int m_bRefreshed;                                       // +0xe8
};
MS2_CHECK_SIZE(CUgcViewerBlueprintImage, 0xf0);
MS2_CHECK_OFFSET(CUgcViewerBlueprintImage, m_proxy, 0x18);
MS2_CHECK_OFFSET(CUgcViewerBlueprintImage, m_icon, 0x50);
MS2_CHECK_OFFSET(CUgcViewerBlueprintImage, m_bRefreshed, 0xe8);

class CUgcUploadCtrl : public CUgcUpload
{
public:
    CUgcUploadCtrl();                                       // 0x1418a3620
    virtual ~CUgcUploadCtrl();                              // 0x1418a3740 (??_G 0x1418a6de0)
    void FUN_1418a3840(int nType);                          // set the content kind
    void FUN_1418a38a0();                                   // refresh the preview of the dialog
    void FUN_1418a3ab0(int nDialog);                        // set the dialog that shows the upload
    int FUN_1418a3ad0();                                    // the dialog that shows the upload
    void FUN_1418a3af0(int nResult);
    int FUN_1418a3b80(__int64 uid);                         // prepare the upload (0 = ok)
    CStringW FUN_1418a3bd0();                               // the result text
    int FUN_1418a3c20(__int64 uid, int bFirst);
    void FUN_1418a3db0();
    MS2Ptr<CUgcUploadCtrl> FUN_1418a4100();
    void FUN_1418a4150();
    __int64 FUN_1418a41a0();
    CString FUN_1418a41e0();
    int FUN_1418a43d0();
    int FUN_1418a4470(__int64 uid);
    int FUN_1418a4690();
    int FUN_1418a4780();

    MS2Ptr<IUgcViewer> m_spViewer;                          // +0x98
    MS2Ptr<CUploadFile> m_spFile;                           // +0xa8
    __int64 m_itemUid;                                      // +0xb8
    CStringW m_strResult;                                   // +0xc0
    MS2Ptr<CUgcUploadCtrl> m_spImage;                       // +0xc8 the second upload of a blueprint (the image)
    int m_nDialog;                                          // +0xd8
    int m_unk_dc;
    __int64 m_nExtra;                                       // +0xe0
};
MS2_CHECK_SIZE(CUgcUploadCtrl, 0xe8);
MS2_CHECK_OFFSET(CUgcUploadCtrl, m_spViewer, 0x98);
MS2_CHECK_OFFSET(CUgcUploadCtrl, m_spFile, 0xa8);
MS2_CHECK_OFFSET(CUgcUploadCtrl, m_strResult, 0xc0);
MS2_CHECK_OFFSET(CUgcUploadCtrl, m_nDialog, 0xd8);
