// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\triggerservice.cpp
// MS2-RANGE: 0x14010e910-0x14010eca0 .text$di
// MS2-RANGE: 0x141860e60-0x141868af0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$CRBMap@HUUnk_TrigHandle@@V?$CElementTraits@H@ATL@@V?$CElementTraits@UUnk_TrigHandle@@@3@@ATL@@QEAA@_K@Z 0x1418645d0 ; unique
// MS2-PIN: ??0?$CRBTree@HUUnk_TrigHandle@@V?$CElementTraits@H@ATL@@V?$CElementTraits@UUnk_TrigHandle@@@3@@ATL@@IEAA@_K@Z 0x141864630 ; prop
// MS2-PIN: ??0?$CRBTree@HV?$MS2Ptr@VTriggerObject@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VTriggerObject@@@@@3@@ATL@@IEAA@_K@Z 0x141864690 ; prop
// MS2-PIN: ??0?$MS2Ptr@VTriggerObject@@@@QEAA@XZ 0x1418648d0 ; unique
// MS2-PIN: ??1?$MessageHandlerImpl@VCTriggerService@@VEntityChangeMessage@egf@@@efd@@UEAA@XZ 0x141864ca0 ; prop
// MS2-PIN: ??1?$MessageWrapperSubclassHandler@VCTriggerService@@VEntityChangeMessage@egf@@V23@$0CADO@@efd@@UEAA@XZ 0x141864d00 ; order
// MS2-PIN: ?get@?$MS2Ptr@VTriggerObjectMesh@@@@QEBAPEAVTriggerObjectMesh@@XZ 0x141864f00 ; order
// MS2-PIN: ??_G?$MessageHandlerImpl@VCTriggerService@@VEntityChangeMessage@egf@@@efd@@UEAAPEAXI@Z 0x141864f20 ; prop
// MS2-PIN: ??_G?$MessageSubclassHandler@VCTriggerService@@VEntityChangeMessage@egf@@V23@@efd@@UEAAPEAXI@Z 0x141864f60 ; prop
// MS2-PIN: ??_G?$MessageWrapperSubclassHandler@VCTriggerService@@VEntityChangeMessage@egf@@V23@$0CADN@@efd@@UEAAPEAXI@Z 0x141864fa0 ; order
// MS2-PIN: ??_G?$MessageWrapperSubclassHandler@VCTriggerService@@VEntityChangeMessage@egf@@V23@$0CADO@@efd@@UEAAPEAXI@Z 0x141864fe0 ; order
// MS2-PIN: ?RegisterMessageFactory@?$MessageHandlerImpl@VCTriggerService@@VEntityChangeMessage@egf@@@efd@@UEAAXPEAV?$GenericFactory@V?$SmartPointer@VIMessage@efd@@@efd@@I@2@@Z 0x141867af0 ; unique
// MS2-PIN: ?RegisterMessageFactory@?$MessageSubclassHandler@VCTriggerService@@VEntityChangeMessage@egf@@V23@@efd@@UEAAXPEAV?$GenericFactory@V?$SmartPointer@VIMessage@efd@@@efd@@I@2@@Z 0x141867b30 ; unique
// MS2-PIN: ?RegisterMessageFactory@?$MessageWrapperSubclassHandler@VCTriggerService@@VEntityChangeMessage@egf@@V23@$0CADO@@efd@@UEAAXPEAV?$GenericFactory@V?$SmartPointer@VIMessage@efd@@@efd@@I@2@@Z 0x141867b90 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??0CPair@?$CRBTree@HUUnk_TrigHandle@@V?$CElementTraits@H@ATL@@V?$CElementTraits@UUnk_TrigHandle@@@3@@ATL@@IEAA@HUUnk_TrigHandle@@@Z 0x141864a40
// MS2-PIN: ??0CNode@?$CRBTree@HUUnk_TrigHandle@@V?$CElementTraits@H@ATL@@V?$CElementTraits@UUnk_TrigHandle@@@3@@ATL@@QEAA@HUUnk_TrigHandle@@@Z 0x1418649a0
// MS2-PIN: ?NewNode@?$CRBTree@HUUnk_TrigHandle@@V?$CElementTraits@H@ATL@@V?$CElementTraits@UUnk_TrigHandle@@@3@@ATL@@AEAAPEAVCNode@12@HUUnk_TrigHandle@@@Z 0x1418665d0
// MS2-PIN: ?InsertImpl@?$CRBTree@HUUnk_TrigHandle@@V?$CElementTraits@H@ATL@@V?$CElementTraits@UUnk_TrigHandle@@@3@@ATL@@AEAAPEAVCNode@12@HUUnk_TrigHandle@@@Z 0x141865d70
// MS2-PIN: ?RBInsert@?$CRBTree@HUUnk_TrigHandle@@V?$CElementTraits@H@ATL@@V?$CElementTraits@UUnk_TrigHandle@@@3@@ATL@@IEAAPEAVCNode@12@HUUnk_TrigHandle@@@Z 0x1418675f0
// MS2-PIN: ?SetAt@?$CRBMap@HUUnk_TrigHandle@@V?$CElementTraits@H@ATL@@V?$CElementTraits@UUnk_TrigHandle@@@3@@ATL@@QEAAPEAU__POSITION@@HUUnk_TrigHandle@@@Z 0x141868240
// MS2-PIN: ?Lookup@?$CRBMap@HUUnk_TrigHandle@@V?$CElementTraits@H@ATL@@V?$CElementTraits@UUnk_TrigHandle@@@3@@ATL@@QEBA_NHAEAUUnk_TrigHandle@@@Z 0x141866290
// MS2-PIN: ??C?$MS2Ptr@VSidePopupTalkParam@@@@QEBAPEAVSidePopupTalkParam@@XZ 0x141864ef0
// MS2-PIN: ??_7CTriggerService@@6BISystemService@efd@@@ 0x142f88808
// MS2-PIN: ??_ECTriggerService@@WCA@EAAPEAXI@Z 0x141864f10
// MS2-PIN: ??_7CTriggerService@@6B?$TSingleton@VCTriggerService@@@@@ 0x142f888d8
// MS2-PIN: ?TypeCast@CTriggerService@@UEBA_NIPEAPEAX@Z 0x1418688b0
// MS2-PIN: ?TypeCast@CTriggerService@@UEBA_NIPEAPEBX@Z 0x141868900
// MS2-PIN: ??8?$MS2Ptr@VTriggerObject@@@@QEBA_NPEAVTriggerObject@@@Z 0x141864e60
// MS2-PIN: ??8?$MS2Ptr@VTriggerObjectMesh@@@@QEBA_NPEAVTriggerObjectMesh@@@Z 0x141864ea0
// MS2-PIN: ??B?$MS2Ptr@VTriggerObject@@@@QEBAPEAVTriggerObject@@XZ 0x141864ee0
// MS2-PIN: ?IsEmpty@?$CAtlList@UUnk_TrigCamStep@@V?$CElementTraits@UUnk_TrigCamStep@@@ATL@@@ATL@@QEBA_NXZ 0x141865f70
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VTriggerObjectMesh@@@@AEBAXPEAX@Z 0x1418689a0
// CTriggerService: the client side of the cube-trigger system (see triggerservice.h). The container glue of the
// exe (CRBMap / CAtlList / MS2Ptr instances and the message handler templates) comes from the real templates here.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\triggerservice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include <efd/MessageService.h>
#include <efd/ServiceManager.h>
#include <egf/Entity.h>
#include <egf/EntityChangeMessage.h>
#include <egf/FlatModel.h>
#include "triggerservice.h"
#include "cameramode.h"
#include "targetlookcentercameramode.h"
#include "uicutscenemovie.h"
#include "uiguideeventarrow.h"
#include "uinpcduelhpbardialog.h"
#include "worldservice.h"
#include "pcbase.h"
#include "ms2/commonfiles/filebuffer_1.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/sidepopuptalkparam.h"
#include "ms2/placeholder/statetriggeremotiondata.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- services reached through globals ----
void* FUN_140166440();                                              // the log
void FUN_140353fc0(void* pLog, int nLevel, int nCategory, const wchar_t* szFormat, const int& rArg);
WorldService* FUN_1403ed2d0();
void* FUN_1403ed2b0();                                              // the UI manager
void FUN_141adc530(void* pUi, int nId);                             // show
void FUN_141adc5d0(void* pUi, int nId);                             // hide
void FUN_141add040(void* pUi, int nId);
void FUN_141add0b0(void* pUi, int nId);
class Unk_TrigCmdMgr { public: void FUN_14138bf00(int nKind, int nId, int nArg); };
Unk_TrigCmdMgr* FUN_1409331e0();

// The effect manager (effect handles) and its request block.
struct Unk_TrigFxXform;
struct Unk_TrigSvcFxReq
{
    CStringA m_strName;                                             // +0
    int m_nOwnerId;                                                 // +8
    int m_pad_0c;
    void* m_pSlot10;                                                // +0x10
    Unk_TrigFxXform* m_pXform;                                      // +0x18
    char m_pad_20[0x58];
};
MS2_CHECK_SIZE(Unk_TrigSvcFxReq, 0x78);
class Unk_TrigSvcFxMgr
{
public:
    int FUN_1411a49c0(Unk_TrigSvcFxReq* pRequest);                  // spawn, returns the handle
    void FUN_1411a6060(int nHandle);                                // release
};
Unk_TrigSvcFxMgr* FUN_1403ed280();
void FUN_140a52ef0(Unk_TrigSvcFxReq* p);
void FUN_1405a89e0(Unk_TrigSvcFxReq* p);

// ---- entities ----
egf::FlatModel* FUN_1408a9bd0(egf::Entity* pEntity);
void FUN_1408a2020(egf::Entity* pEntity, unsigned uPropId, int* pOut);
const void* FUN_1408b76f0(const void* pEntity);                     // &entity id
void* FUN_1408b6b20(void* pDst, const void* pSrc);                  // copy an entity id
bool FUN_140de6d70(TriggerObject* pObject, void* pEntityId);
bool FUN_140de6db0(TriggerObject* pObject);

// ---- camera ----
class Unk_Entity;
int FUN_140af7e30(Unk_CameraManager* p);                            // id of the current camera mode
CCameraMode* FUN_140af2520(Unk_CameraManager* p);
Unk_CameraSetting* FUN_140947880(CCameraMode* p);
void FUN_140aed720(Unk_CameraManager* p, Unk_CameraSetting* pSetting);
void FUN_140aed750(Unk_CameraManager* p, int nMode, bool bFlag);
void FUN_140aed580(Unk_CameraManager* p, Unk_FlyByCameraData* pData, int n, float f);
void FUN_140aed1c0(Unk_CameraManager* p);
float FUN_140ad4b30(CCameraMode* p);
float FUN_140af7ef0(CCameraMode* p);
float FUN_140af7e90(CCameraMode* p);

// ---- world service objects ----
class Unk_TrigNpc;
void FUN_14166f8f0(Unk_TrigNpc* p, int n, int b);
void FUN_14166ed50(Unk_TrigNpc* p, int n);
void FUN_14166ef10(Unk_TrigNpc* p, const CString& str, bool b, int n1, int n2);
void FUN_14166d8b0(PCBase* p, float fYaw);
void FUN_14166d2d0(PCBase* p, efd::Point3 pt, bool b);

// ---- UI ----
class Unk_CommandUIRef {
public:
    ~Unk_CommandUIRef();                                            // 0x1403e5630
    UIObject* FUN_1403e8a70() const;
    UIObject* FUN_141371280();
private: void* unknown; UIObject* object;
};
MS2_CHECK_SIZE(Unk_CommandUIRef, 0x10);
struct Unk_TsUiMgrView                                              // UI manager members (this=rcx, hidden return=rdx)
{
    Unk_CommandUIRef FUN_141adcea0(int nId);
    Unk_CommandUIRef FUN_141adcf50(const CString& strName);
};
UIObject* FUN_1403ed9e0(Unk_CommandUIRef& rRef);
bool FUN_140534e80(Unk_CommandUIRef& rRef);                         // is the reference empty

class UITypingGameDialog : public UIDialog
{
public:
    virtual void vfunc_84();
    void FUN_140ee57b0(int nA, int nB);
};
class Unk_TrigTextUI { public: void FUN_141b2b7e0(MS2Ptr<CFileBuffer> spText); };
Unk_TrigTextUI* FUN_14122d570(int nId);
class Unk_TrigHintUI { public: void FUN_141b334d0(int n); void FUN_141b33510(int n); };
Unk_TrigHintUI* FUN_140ee6300(int nId);
class Unk_TrigTalkUI { public: void FUN_140e879a0(MS2Ptr<SidePopupTalkParam> spParam); };
Unk_TrigTalkUI* FUN_1413868b0(int nId);
UINpcDuelHPBarDialog* FUN_14096e200(int nId);
UICutSceneMovie* FUN_14138fd50(int nId);
UIGuideEvent* FUN_14136f3e0(int nId);

// The pvp observer popup (id 0x4e96) takes one of two record blocks read from the packet.
struct Unk_TrigPvpA
{
    Unk_TrigPvpA() : m_0(0), m_8(0), m_10(0), m_18(0), m_20(0), m_28(0), m_30(0), m_38(0) {}     // 0x141864ab0
    __int64 m_0, m_8, m_10;
    int m_18, m_1c;
    __int64 m_20, m_28, m_30;
    int m_38, m_3c;
};
MS2_CHECK_SIZE(Unk_TrigPvpA, 0x40);
struct Unk_TrigPvpB
{
    Unk_TrigPvpB() : m_0(0), m_8(0), m_10(0), m_18(0), m_1c(0), m_20(0), m_28(0), m_30(0), m_38(0), m_3c(0), m_40(0) {}   // 0x141864b20
    __int64 m_0, m_8, m_10;
    int m_18, m_1c;
    __int64 m_20, m_28, m_30;
    int m_38, m_3c, m_40, m_44;
};
MS2_CHECK_SIZE(Unk_TrigPvpB, 0x48);
class Unk_TrigPvpDlg
{
public:
    void FUN_141a92c80();
    void FUN_141a91940(const Unk_TrigPvpA& rBlock);
    void FUN_141a91a30(const Unk_TrigPvpB& rBlock);
};
Unk_TrigPvpDlg* FUN_141531c80(int nId);
void FUN_140743ca0(Unk_TrigPvpA* pOut, CInPacket* pPacket);
void FUN_140743f50(Unk_TrigPvpB* pOut, CInPacket* pPacket);

class Unk_TextFilter { public: CStringW FUN_14087ede0(const CStringW& rText); };
Unk_TextFilter* FUN_140a87680();
Unk_TextFilter* FUN_140a87690(Unk_TextFilter* p);
bool FUN_140841300(const CStringW& rText, const char* szCompare);
CStringW FUN_1408767c0(const char* pszUtf8);                        // utf8 -> wide
void FUN_14015f050(CString& rText, ATL::CAtlArray<CString>& rOut, const char* szDelimiter);
void FUN_140d73bc0(int nId, int n, IMessageListener* pListener, CStringW str);

// ---- service plumbing ----
efd::MessageService* FUN_1411d1530(efd::ServiceManager* pManager);
class Unk_TrigNetSvc { public: efd::Category FUN_142156c20(); };
Unk_TrigNetSvc* FUN_140ae1200(efd::ServiceManager* pManager);
class Unk_TrigAnimSvc { public: efd::Category FUN_141235eb0(); };
Unk_TrigAnimSvc* FUN_141b6f910();
void FUN_1410db4c0(efd::IDependencyRegistrar* pRegistrar, unsigned n);
void FUN_1411ab6e0(efd::IDependencyRegistrar* pRegistrar, unsigned n);

// ---- static initializers (.text$di, in this order) ----
// @0x14010e910
EE_IMPLEMENT_CONCRETE_CLASS_INFO(CTriggerService);
#ifndef MS2_HOOK_DLL
// @0x14010e930
EE_HANDLER_WRAP(CTriggerService, FUN_141861620, egf::EntityChangeMessage, 8253);
// @0x14010e990
EE_HANDLER_WRAP(CTriggerService, FUN_141861760, egf::EntityChangeMessage, 8254);
#endif
// @0x14010e9f0
static CString s_aSortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
// @0x14010eab0
static CString s_strSkill = "skill";
// @0x14010eae0
static CString s_strStun = "stun";
// @0x14010eb10
static const efd::Category s_catEntityChannel(efd::UniversalID::ECU_Any, 0xfff, 0x07f00004);
// @0x14010eb40
static const efd::Category s_catAnimationChannel(efd::UniversalID::ECU_Any, 0xfff, 0x07001008);
// @0x14010eb70
class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };
static Unk_1401cd100 s_pointer(NULL);
// @0x14010eb90
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);
// @0x14010ebe0
static CString s_aSortNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// @0x141864920
inline TSingleton<CTriggerService>::TSingleton() { s_instance = static_cast<CTriggerService*>(this); }

// The packet is a CIOBuffer at +0 and the CInputStream at +8; the trigger objects take it as their event.
#define TrigEvent(p) reinterpret_cast<Unk_TriggerEvent*>(p)

// Not in the hook DLL: MS2::RegisterServices (hooked) must build the exe object (exe vtable; unhooked virtuals stay exe).
#ifndef MS2_HOOK_DLL
// @0x141860e60
CTriggerService::CTriggerService() : m_mapObjects(10), m_mapHandles(10), m_listCamera(10)
{
}
#endif

// @0x141860f50
CTriggerService::~CTriggerService()
{
}

// @0x141861000
const char* CTriggerService::GetDisplayName() const
{
    return "TriggerService";
}

// IWorldServiceCallback slot 3 (the exe's body works on the adjusted this): drop the objects and the effects.
// @0x141861020
void CTriggerService::vfunc_3(int nMap)
{
    m_mapObjects.RemoveAll();
    POSITION pos = m_mapHandles.GetHeadPosition();
    while (pos)
    {
        int nHandle = m_mapHandles.GetValueAt(pos);
        if (nHandle != 0)
            FUN_1403ed280()->FUN_1411a6060(nHandle);
        m_mapHandles.GetNext(pos);
    }
    m_mapHandles.RemoveAll();
}

// @0x1418610d0
efd::SyncResult CTriggerService::OnPreInit(efd::IDependencyRegistrar* pRegistrar)
{
    FUN_1410db4c0(pRegistrar, 1);
    FUN_1411ab6e0(pRegistrar, 3);
    return efd::SyncResult_Success;
}

// MS2-FUNCTIONAL: the exe holds the services in CComPtr wrappers; raw pointers are used here
// @0x141861110
efd::AsyncResult CTriggerService::OnInit()
{
    efd::MessageService* pMessages = FUN_1411d1530(m_pServiceManager);
    Unk_TrigNetSvc* pNet = FUN_140ae1200(m_pServiceManager);
    m_catGlobal = pMessages->GetGloballyUniqueCategory();
    pMessages->Subscribe(this, s_catEntityChannel, 0, false);
    pMessages->Subscribe(this, m_catGlobal, 0, false);
    efd::Category catNet = pNet->FUN_142156c20();
    pMessages->Subscribe(this, catNet, 0, false);
    pMessages->Subscribe(this, s_catAnimationChannel, 0, false);
    efd::Category catAnim = FUN_141b6f910()->FUN_141235eb0();
    pMessages->Subscribe(this, catAnim, 0, false);
    FUN_1403ed2d0()->FUN_141bbae40(this ? static_cast<IWorldServiceCallback*>(this) : 0);
    return efd::AsyncResult_Complete;
}

// @0x1418613f0
efd::AsyncResult CTriggerService::OnTick()
{
    return efd::AsyncResult_Pending;
}

// MS2-FUNCTIONAL: the exe holds the services in CComPtr wrappers; raw pointers are used here
// @0x141861410
efd::AsyncResult CTriggerService::OnShutdown()
{
    efd::MessageService* pMessages = FUN_1411d1530(m_pServiceManager);
    Unk_TrigNetSvc* pNet = FUN_140ae1200(m_pServiceManager);
    pMessages->Unsubscribe(this, s_catEntityChannel, 0);
    pMessages->Unsubscribe(this, m_catGlobal, 0);
    efd::Category catNet = pNet->FUN_142156c20();
    pMessages->Unsubscribe(this, catNet, 0);
    pMessages->Unsubscribe(this, s_catAnimationChannel, 0);
    efd::Category catAnim = FUN_141b6f910()->FUN_141235eb0();
    pMessages->Unsubscribe(this, catAnim, 0);
    return efd::AsyncResult_Complete;
}

// A trigger entity appeared: create its world object.
// @0x141861620
void CTriggerService::FUN_141861620(const egf::EntityChangeMessage* pMsg, efd::Category)
{
    egf::Entity* pEntity = pMsg->GetEntity();
    if (pEntity == 0)
        return;
    egf::FlatModel* pModel = FUN_1408a9bd0(pEntity);
    if (pModel->ContainsModel(0xe8dd99d))
    {
        int nId = 0;
        FUN_1408a2020(pEntity, 0x6c37a861, &nId);
        MS2Ptr<TriggerObject> spObject = TriggerObject::Create(pEntity);
        if (spObject == 0)
            return;
        Unk_EntRef kRef(0);
        kRef.FUN_1408b6ec0(reinterpret_cast<Unk_Entity*>(pEntity));
        spObject->Init(nId, kRef);
        m_mapObjects.SetAt(nId, spObject);
    }
}

// @0x141861760
void CTriggerService::FUN_141861760(const egf::EntityChangeMessage* pMsg, efd::Category)
{
    if (!m_mapObjects.IsEmpty())
    {
        egf::Entity* pEntity = pMsg->GetEntity();
        if (pEntity != 0)
        {
            egf::FlatModel* pModel = FUN_1408a9bd0(pEntity);
            if (pModel->ContainsModel(0xe8dd99d))
            {
                int nId = 0;
                FUN_1408a2020(pEntity, 0x6c37a861, &nId);
                m_mapObjects.RemoveKey(nId);
            }
        }
    }
}

// @0x141861810
void CTriggerService::FUN_141861810(const efd::IMessage*, efd::Category)
{
}

// @0x141861840
void CTriggerService::FUN_141861840(CInPacket* pEvent)
{
    unsigned char nType = pEvent->vfunc_o8_1();
    switch (nType)
    {
    case 2:
        FUN_141861a50(pEvent);
        break;
    case 3:
        FUN_141861ad0(pEvent);
        break;
    case 5:
        FUN_141861b00(pEvent);
        break;
    case 6:
        FUN_141861c20(pEvent);
        break;
    case 7:
        FUN_141861f30(pEvent);
        break;
    case 9:
        FUN_1418627c0(pEvent);
        break;
    case 0xc:
        FUN_141861fc0(pEvent);
        break;
    case 0xf:
        FUN_141862110(pEvent);
        break;
    case 0x10:
        FUN_1403ed2d0()->FUN_141bd42f0(pEvent);
        break;
    case 0x11:
        FUN_1403ed2d0()->FUN_141bd4490(pEvent);
        break;
    case 0x12:
        FUN_1403ed2d0()->FUN_141bd4670(pEvent);
        break;
    case 0x13:
        FUN_1418629b0(pEvent);
        break;
    case 0x14:
        FUN_141862d30(pEvent);
        break;
    case 0x15:
        FUN_141862ec0(pEvent);
        break;
    case 0x16:
        FUN_141862930(pEvent);
        break;
    case 0x17:
    case 0x18:
    case 0x19:
        FUN_141862ff0(nType, pEvent);
        break;
    }
}

// @0x141861a50
void CTriggerService::FUN_141861a50(CInPacket* pEvent)
{
    int nCount = pEvent->vfunc_o8_3();
    for (int i = 0; i < nCount; i++)
        FUN_141863a90(pEvent, true);
}

// @0x141861ad0
void CTriggerService::FUN_141861ad0(CInPacket* pEvent)
{
    FUN_141863a90(pEvent, false);
}

// @0x141861b00
void CTriggerService::FUN_141861b00(CInPacket* pEvent)
{
    m_listCamera.RemoveAll();
    unsigned char nCount = pEvent->vfunc_o8_1();
    ATL::CAtlArray<int> aObjects;
    for (int i = 0; i < nCount; i++)
        aObjects.Add(pEvent->vfunc_o8_3());
    unsigned char bEnd = pEvent->vfunc_o8_1();
    FUN_141863340(aObjects, bEnd);
}

// @0x141861c20
void CTriggerService::FUN_141861c20(CInPacket* pEvent)
{
    char nSub = pEvent->vfunc_o8_1();
    if (nSub == 0)
    {
        Unk_StreamPoint ptCenter = pEvent->FUN_1407140d0();
        unsigned uOuter = pEvent->vfunc_o8_3();
        unsigned uInner = pEvent->vfunc_o8_3();
        Unk_CameraManager* pCamera = Unk_CameraManager::FUN_1409478c0();
        if (FUN_140af7e30(pCamera) != 0x13)
        {
            Unk_CameraSetting* pSetting = FUN_140947880(FUN_140af2520(Unk_CameraManager::FUN_1409478c0()));
            FUN_140aed720(Unk_CameraManager::FUN_1409478c0(), pSetting);
            FUN_140aed750(Unk_CameraManager::FUN_1409478c0(), 0x13, true);
        }
        CTargetLookCenterCameraMode* pMode =
            dynamic_cast<CTargetLookCenterCameraMode*>(FUN_140af2520(Unk_CameraManager::FUN_1409478c0()));
        if (pMode != 0)
        {
            pMode->FUN_140a4e0d0(ptCenter);
            pMode->FUN_140a4e150((float)uOuter);
            pMode->FUN_140a4e1d0((float)uInner);
        }
    }
    else if (nSub == 1)
    {
        bool bCheck = pEvent->vfunc_o8_0();
        CTargetLookCenterCameraMode* pMode =
            dynamic_cast<CTargetLookCenterCameraMode*>(FUN_140af2520(Unk_CameraManager::FUN_1409478c0()));
        if (pMode != 0)
            pMode->FUN_140a4e180(bCheck);
    }
    else if (nSub == 2)
    {
        bool bFixed = pEvent->vfunc_o8_0();
        float fAngle = pEvent->vfunc_o8_5();
        CTargetLookCenterCameraMode* pMode =
            dynamic_cast<CTargetLookCenterCameraMode*>(FUN_140af2520(Unk_CameraManager::FUN_1409478c0()));
        if (pMode != 0)
        {
            pMode->FUN_140a4e110(fAngle);
            pMode->FUN_140a4e200(bFixed);
        }
    }
}

// @0x141861f30
void CTriggerService::FUN_141861f30(CInPacket*)
{
    FUN_141863460(0.0f);
}

// @0x141861f60
void CTriggerService::FUN_141861f60(CInPacket* pEvent)
{
    FUN_141863460(pEvent->vfunc_o8_5());
}

// Show a text popup (UI 0x4e6b) with a text file buffer.
// @0x141861fc0
void CTriggerService::FUN_141861fc0(CInPacket* pEvent)
{
    CStringA strText = pEvent->vfunc_o8_7();
    CStringW strWide = FUN_1408767c0(strText);
    MS2Ptr<CFileBuffer> spBuffer(new CFileBuffer);
    spBuffer->SetText(strWide);
    Unk_TrigTextUI* pUi = FUN_14122d570(0x4e6b);
    if (pUi != 0)
        pUi->FUN_141b2b7e0(spBuffer);
}

// @0x141862110
void CTriggerService::FUN_141862110(CInPacket* pEvent)
{
    char nKind = pEvent->vfunc_o8_1();
    if (nKind == 1)
    {
        int nA = pEvent->vfunc_o8_3();
        int nB = pEvent->vfunc_o8_3();
        unsigned char nC = pEvent->vfunc_o8_1();
        int nD = pEvent->vfunc_o8_3();
        CStringW strCompare = pEvent->vfunc_o8_8();
        FUN_1403ed2d0()->FUN_141bc6f60(nA, nB, nC);
        if (nB == 0)
        {
            FUN_141adc5d0(FUN_1403ed2b0(), 0x4e95);
        }
        else
        {
            FUN_141adc530(FUN_1403ed2b0(), 0x4e95);
            Unk_TrigHintUI* pUi = FUN_140ee6300(0x4e95);
            if (pUi != 0)
            {
                pUi->FUN_141b334d0(nD);
                if (!FUN_140841300(strCompare, "TR"))
                    pUi->FUN_141b33510(1);
                else
                    pUi->FUN_141b33510(6);
            }
        }
    }
    else if (nKind == 2)
    {
        int nA = pEvent->vfunc_o8_3();
        int nB = pEvent->vfunc_o8_3();
        unsigned char nC = pEvent->vfunc_o8_1();
        FUN_1403ed2d0()->FUN_141bc6f60(nA, nB, nC);
        Unk_TrigPvpA kBlock;
        FUN_140743ca0(&kBlock, pEvent);
        Unk_TrigPvpDlg* pUi = FUN_141531c80(0x4e96);
        if (pUi != 0)
        {
            if (kBlock.m_0 == 0 || kBlock.m_20 == 0)
            {
                pUi->FUN_141a92c80();
            }
            else
            {
                pUi->FUN_141a91940(kBlock);
                FUN_141adc530(FUN_1403ed2b0(), 0x4e96);
            }
        }
    }
    else if (nKind == 5)
    {
        int nA = pEvent->vfunc_o8_3();
        int nB = pEvent->vfunc_o8_3();
        unsigned char nC = pEvent->vfunc_o8_1();
        FUN_1403ed2d0()->FUN_141bc6f60(nA, nB, nC);
        Unk_TrigPvpB kBlock;
        FUN_140743f50(&kBlock, pEvent);
        Unk_TrigPvpDlg* pUi = FUN_141531c80(0x4e96);
        if (pUi != 0)
        {
            if (kBlock.m_0 == 0 || kBlock.m_20 == 0)
            {
                pUi->FUN_141a92c80();
            }
            else
            {
                pUi->FUN_141a91a30(kBlock);
                FUN_141adc530(FUN_1403ed2b0(), 0x4e96);
            }
        }
    }
    else if (nKind == 3)
    {
        int nA = pEvent->vfunc_o8_3();
        int nB = pEvent->vfunc_o8_3();
        unsigned char nC = pEvent->vfunc_o8_1();
        FUN_1403ed2d0()->FUN_141bc6f60(nA, nB, nC);
        if (nB == 0)
        {
            FUN_141adc5d0(FUN_1403ed2b0(), 0x4e99);
            FUN_141adc5d0(FUN_1403ed2b0(), 0x4e9a);
        }
        else
        {
            FUN_141adc530(FUN_1403ed2b0(), 0x4e99);
            FUN_141adc530(FUN_1403ed2b0(), 0x4e9a);
        }
    }
    else if (nKind == 4)
    {
        int nA = pEvent->vfunc_o8_3();
        int nB = pEvent->vfunc_o8_3();
        unsigned char nC = pEvent->vfunc_o8_1();
        FUN_1403ed2d0()->FUN_141bc6f60(nA, nB, nC);
        if (nB != 0)
        {
            FUN_141adc530(FUN_1403ed2b0(), 0x4e95);
            FUN_141adc530(FUN_1403ed2b0(), 0x4ed3);
        }
    }
}

// @0x1418627c0
void CTriggerService::FUN_1418627c0(CInPacket* pEvent)
{
    unsigned char nSub = pEvent->vfunc_o8_1();
    switch (nSub)
    {
    case 1:
        FUN_141863df0(pEvent);
        break;
    case 2:
        FUN_141863cc0(pEvent);
        break;
    case 3:
        FUN_141863d80(pEvent);
        break;
    case 4:
        FUN_141863b70(pEvent);
        break;
    case 5:
        FUN_141863c50(pEvent);
        break;
    case 7:
        FUN_141863e50(pEvent);
        break;
    case 8:
        FUN_141864010(pEvent);
        break;
    case 9:
        FUN_1418641e0(pEvent);
        break;
    case 10:
        FUN_1418642e0(pEvent);
        break;
    case 0xb:
        FUN_1418643c0(pEvent);
        break;
    case 0xc:
        FUN_141863030(pEvent);
        break;
    }
}

// @0x141862930
void CTriggerService::FUN_141862930(CInPacket* pEvent)
{
    if (pEvent->vfunc_o8_3() == 0)
        FUN_140d73bc0(0xb03, 0, 0, CStringW(L""));
}

// Side popup talk (UI 0x4f57).
// @0x1418629b0
void CTriggerService::FUN_1418629b0(CInPacket* pEvent)
{
    unsigned nKind = pEvent->vfunc_o8_1();
    int nNpc = pEvent->vfunc_o8_3();
    CStringA strName = pEvent->vfunc_o8_7();
    CStringA strIcon = pEvent->vfunc_o8_7();
    CStringA strSound = pEvent->vfunc_o8_7();
    CStringA strScript = pEvent->vfunc_o8_7();
    CStringW strText = pEvent->vfunc_o8_8();
    Unk_TrigTalkUI* pUi = FUN_1413868b0(0x4f57);
    if (pUi != 0)
    {
        MS2Ptr<SidePopupTalkParam> spParam(new SidePopupTalkParam);
        spParam->m_nKind = nKind;
        spParam->m_strName = strName;
        spParam->m_strIcon = strIcon;
        spParam->m_nNpcId = nNpc;
        spParam->m_strText = FUN_140a87690(FUN_140a87680())->FUN_14087ede0(strText);
        spParam->m_strSound = strSound;
        spParam->m_strScript = strScript;
        pUi->FUN_140e879a0(spParam);
    }
}

// Set the state of the named UI objects.
// @0x141862d30
void CTriggerService::FUN_141862d30(CInPacket* pEvent)
{
    unsigned char nState = pEvent->vfunc_o8_1();
    CStringA strNames = pEvent->vfunc_o8_7();
    ATL::CAtlArray<CString> aNames;
    FUN_14015f050(strNames, aNames, ",");
    for (size_t i = 0; i < aNames.GetCount(); i++)
    {
        Unk_CommandUIRef kRef = static_cast<Unk_TsUiMgrView*>(FUN_1403ed2b0())->FUN_141adcf50(aNames[i]);
        if (!FUN_140534e80(kRef))
        {
            if (kRef.FUN_141371280()->vfunc_9() != nState)
                kRef.FUN_141371280()->vfunc_8(nState);
        }
    }
}

// @0x141862ec0
void CTriggerService::FUN_141862ec0(CInPacket* pEvent)
{
    if (pEvent->vfunc_o8_0() == 0)
    {
        FUN_141adc5d0(FUN_1403ed2b0(), 0x4f62);
        FUN_141add040(FUN_1403ed2b0(), 0x4e3d);
    }
    else
    {
        int nA = pEvent->vfunc_o8_3();
        int nB = pEvent->vfunc_o8_3();
        int nC = pEvent->vfunc_o8_3();
        UINpcDuelHPBarDialog* pUi = FUN_14096e200(0x4f62);
        if (pUi != 0)
        {
            pUi->FUN_140e6bb70(nA, nB, nC);
            pUi->FUN_141924680();
        }
        FUN_141add0b0(FUN_1403ed2b0(), 0x4e3d);
    }
}

// @0x141862ff0
void CTriggerService::FUN_141862ff0(int nType, CInPacket* pEvent)
{
    FUN_1403ed2d0()->FUN_141bdad00(nType, reinterpret_cast<Unk_WsD_Msg*>(pEvent));
}

// The typing game dialog (UI 0x4f89); the exe's cast helper is FUN_1418644d0.
// @0x1418644d0
static UITypingGameDialog* FUN_1418644d0(int nId)
{
    if (FUN_1403ed2b0() != 0)
    {
        Unk_CommandUIRef kRef = static_cast<Unk_TsUiMgrView*>(FUN_1403ed2b0())->FUN_141adcea0(nId);
        if (kRef.FUN_1403e8a70() != 0)
            return dynamic_cast<UITypingGameDialog*>(FUN_1403ed9e0(kRef));
    }
    return 0;
}

// @0x141863030
void CTriggerService::FUN_141863030(CInPacket* pEvent)
{
    int nA = pEvent->vfunc_o8_3();
    int nB = pEvent->vfunc_o8_3();
    UITypingGameDialog* pDialog = FUN_1418644d0(0x4f89);
    if (pDialog != 0)
    {
        if (pDialog->FUN_141924630() != 0)
            pDialog->vfunc_67();
        pDialog->FUN_140ee57b0(nA, nB);
        pDialog->vfunc_84();
    }
}

// @0x141863100
bool CTriggerService::FUN_141863100(int nObject, Unk_StreamPoint pt)
{
    MS2Ptr<TriggerObject> spObject;
    m_mapObjects.Lookup(nObject, spObject);
    if (spObject == 0)
        return false;
    return spObject->Contains(pt);
}

// @0x1418631a0
void CTriggerService::FUN_1418631a0()
{
    FUN_141863260();
}

// @0x1418631c0
void CTriggerService::FUN_1418631c0()
{
    m_listCamera.RemoveAll();
}

// @0x1418631f0
void CTriggerService::FUN_1418631f0(int nObject, int bStart)
{
    Unk_TrigCamStep kStep;
    kStep.m_nObject = nObject;
    kStep.m_bStart = bStart;
    m_listCamera.AddTail(kStep);
    if (FUN_140af7e30(Unk_CameraManager::FUN_1409478c0()) != 3)
        FUN_141863260();
}

// Run the next queued camera step.
// @0x141863260
void CTriggerService::FUN_141863260()
{
    if (!m_listCamera.IsEmpty())
    {
        Unk_TrigCamStep kStep = m_listCamera.RemoveHead();
        MS2Ptr<TriggerObject> spObject;
        if (m_mapObjects.Lookup(kStep.m_nObject, spObject))
        {
            if (kStep.m_bStart == 0)
                spObject->vfunc_4();
            else
                spObject->vfunc_3();
        }
    }
}

// @0x141863340
void CTriggerService::FUN_141863340(const ATL::CAtlArray<int>& aObjects, int bEnd)
{
    m_listCamera.RemoveAll();
    if (!aObjects.IsEmpty())
    {
        if (aObjects.GetCount() == 1 && aObjects[0] == 0)
        {
            FUN_140aed750(Unk_CameraManager::FUN_1409478c0(), 2, false);
        }
        else
        {
            for (size_t i = 0; i < aObjects.GetCount(); i++)
                FUN_1418631f0(aObjects[i], 1);
            if (!aObjects.IsEmpty() && bEnd != 0)
                FUN_1418631f0(aObjects[aObjects.GetCount() - 1], 0);
        }
    }
}

// Fade the camera (fade 0 = back to the normal mode).
// MS2-FUNCTIONAL: locals/temporaries of the fly-by block are laid out by the compiler
// @0x141863460
void CTriggerService::FUN_141863460(float fFade)
{
    m_listCamera.RemoveAll();
    if (fFade != 0.0f)
    {
        Unk_FlyByCameraData kData;
        kData.m_nKind = 1;
        kData.m_fDuration = fFade;
        kData.m_from.m_0 = Unk_CameraManager::FUN_1409478c0()->FUN_140ad4b40();
        kData.m_from.m_4 = Unk_CameraManager::FUN_1409478c0()->FUN_140af7f00();
        kData.m_from.m_8 = Unk_CameraManager::FUN_1409478c0()->FUN_140af7ea0();
        kData.m_from.m_c = Unk_CameraManager::FUN_1409478c0()->FUN_140a17e10();
        kData.m_from.m_18 = Unk_CameraManager::FUN_1409478c0()->FUN_140af8290();
        kData.m_to = kData.m_from;
        kData.m_to.m_0 = FUN_140ad4b30(Unk_CameraManager::FUN_1409478c0()->FUN_140af24f0());
        kData.m_to.m_4 = FUN_140af7ef0(Unk_CameraManager::FUN_1409478c0()->FUN_140af24f0());
        kData.m_to.m_8 = FUN_140af7e90(Unk_CameraManager::FUN_1409478c0()->FUN_140af24f0());
        kData.m_to.m_18 = Unk_CameraManager::FUN_1409478c0()->FUN_140af24f0()->FUN_140af8260();
        FUN_140aed580(Unk_CameraManager::FUN_1409478c0(), &kData, 1, 1.0f);
    }
    FUN_140aed1c0(Unk_CameraManager::FUN_1409478c0());
    FUN_140aed750(Unk_CameraManager::FUN_1409478c0(), 2, fFade != 0.0f);
}

// Create or release the effect shown for a trigger object.
// @0x141863630
void CTriggerService::FUN_141863630(int nId, char bAdd, CStringA strName)
{
    if (bAdd == 0)
    {
        Unk_TrigHandle nHandle;
        if (m_mapHandles.Lookup(nId, nHandle))
        {
            if (nHandle != 0)
                FUN_1403ed280()->FUN_1411a6060(nHandle);
            m_mapHandles.RemoveKey(nId);
        }
    }
    else
    {
        Unk_TrigHandle nExisting;
        if (m_mapHandles.Lookup(nId, nExisting))
            return;
        Unk_TrigSvcFxReq kRequest;
        FUN_140a52ef0(&kRequest);
        kRequest.m_strName = strName;
        kRequest.m_nOwnerId = 0;
        int nHandle = FUN_1403ed280()->FUN_1411a49c0(&kRequest);
        if (nHandle != 0)
            m_mapHandles.SetAt(nId, nHandle);
        FUN_1405a89e0(&kRequest);
    }
}

// Collect the ids of the objects whose FlatModel contains the model.
// @0x1418637a0
bool CTriggerService::FUN_1418637a0(const unsigned& rModel, ATL::CAtlList<int>& rIds)
{
    rIds.RemoveAll();
    POSITION pos = m_mapObjects.GetHeadPosition();
    while (pos)
    {
        int nKey = m_mapObjects.GetKeyAt(pos);
        MS2Ptr<TriggerObject> spObject = m_mapObjects.GetValueAt(pos);
        if (spObject)
        {
            if (spObject->HasModel(rModel))
                rIds.AddTail(nKey);
        }
        m_mapObjects.GetNext(pos);
    }
    return !rIds.IsEmpty();
}

// @0x1418638d0
bool CTriggerService::FUN_1418638d0(egf::Entity* pEntity)
{
    POSITION pos = m_mapObjects.GetHeadPosition();
    while (pos)
    {
        MS2Ptr<TriggerObject> spObject = m_mapObjects.GetValueAt(pos);
        unsigned uMesh = 0x74b363a7;
        if (spObject->HasModel(uMesh))
        {
            MS2Ptr<TriggerObjectMesh> spMesh(dynamic_cast<TriggerObjectMesh*>((TriggerObject*)spObject));
            if (!(spMesh == 0))
            {
                char aId[8];
                FUN_1408b6b20(aId, FUN_1408b76f0(pEntity));
                if (FUN_140de6d70(spMesh.get(), aId) && FUN_140de6db0(spMesh.get()))
                    return true;
            }
        }
        m_mapObjects.GetNext(pos);
    }
    return false;
}

// Forward an object event to the object with the id read from the packet.
// @0x141863a90
void CTriggerService::FUN_141863a90(CInPacket* pEvent, bool bSkipFx)
{
    int nId = pEvent->vfunc_o8_3();
    MS2Ptr<TriggerObject> spObject;
    if (!m_mapObjects.Lookup(nId, spObject))
        FUN_140353fc0(FUN_140166440(), 0xc, 0x13, L"Trigger Object Sync Error. ObjectID:{0}", nId);
    else
        spObject->vfunc_2(TrigEvent(pEvent), bSkipFx);
}

// Play a cut scene movie (UI 0x4e7e).
// @0x141863b70
void CTriggerService::FUN_141863b70(CInPacket* pEvent)
{
    CStringA strPath = pEvent->vfunc_o8_7();
    int nCutScene = pEvent->vfunc_o8_3();
    UICutSceneMovie* pMovie = FUN_14138fd50(0x4e7e);
    if (pMovie != 0)
    {
        if (pMovie->FUN_1419102c0() != 0)
            pMovie->vfunc_53();
        pMovie->SetCutSceneId(nCutScene);
        pMovie->vfunc_52(strPath, 0.0f);
    }
}

// @0x141863c50
void CTriggerService::FUN_141863c50(CInPacket* pEvent)
{
    int nCutScene = pEvent->vfunc_o8_3();
    UICutSceneMovie* pMovie = FUN_14138fd50(0x4e7e);
    if (pMovie != 0)
        pMovie->StopIfCutScene(nCutScene);
}

// @0x141863cc0
void CTriggerService::FUN_141863cc0(CInPacket* pEvent)
{
    unsigned nA = pEvent->vfunc_o8_3();
    unsigned nB = pEvent->vfunc_o8_3();
    int nC = pEvent->vfunc_o8_3();
    UIGuideEvent* pGuide = FUN_14136f3e0(0x4e53);
    if (pGuide != 0)
        pGuide->FUN_14195ab40(nA, nB, nC);
}

// @0x141863d80
void CTriggerService::FUN_141863d80(CInPacket* pEvent)
{
    int nA = pEvent->vfunc_o8_3();
    UIGuideEvent* pGuide = FUN_14136f3e0(0x4e53);
    if (pGuide != 0)
        pGuide->FUN_14195b540(nA);
}

// @0x141863df0
void CTriggerService::FUN_141863df0(CInPacket* pEvent)
{
    int nId = pEvent->vfunc_o8_3();
    FUN_1409331e0()->FUN_14138bf00(0x15, nId, 0);
}

// Play an emotion list on the local player.
// @0x141863e50
void CTriggerService::FUN_141863e50(CInPacket* pEvent)
{
    PCBase* pPlayer = static_cast<PCBase*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPlayer != 0)
    {
        int nCount = pEvent->vfunc_o8_3();
        MS2Ptr<StateTriggerEmotionData> spData(new StateTriggerEmotionData);
        spData->m_nFlag = 0;
        spData->m_nMode = 0;
        spData->m_nValue = 0;
        for (int i = 0; i < nCount; i++)
        {
            CStringA strEmotion = pEvent->vfunc_o8_6();
            spData->m_aEmotions.Add(strEmotion);
        }
        pPlayer->vfunc_59(0x35, spData.get(), 0, 0);
    }
}

// Play one emotion on the local player.
// @0x141864010
void CTriggerService::FUN_141864010(CInPacket* pEvent)
{
    PCBase* pPlayer = static_cast<PCBase*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPlayer != 0)
    {
        unsigned char nFlag = pEvent->vfunc_o8_1();
        int nValue = pEvent->vfunc_o8_3();
        CStringA strEmotion = pEvent->vfunc_o8_6();
        MS2Ptr<StateTriggerEmotionData> spData(new StateTriggerEmotionData);
        spData->m_nFlag = nFlag;
        spData->m_nMode = 1;
        spData->m_nValue = nValue;
        spData->m_aEmotions.Add(strEmotion);
        pPlayer->vfunc_59(0x35, spData.get(), 0, 1);
    }
}

// An NPC says a line (or stops talking when the text is empty).
// @0x1418641e0
void CTriggerService::FUN_1418641e0(CInPacket* pEvent)
{
    int nNpc = pEvent->vfunc_o8_3();
    CStringA strText = pEvent->vfunc_o8_7();
    Unk_TrigNpc* pNpc = reinterpret_cast<Unk_TrigNpc*>(FUN_1403ed2d0()->FUN_141bd1200(nNpc));
    if (pNpc != 0)
    {
        if (strText.IsEmpty())
        {
            FUN_14166f8f0(pNpc, 0, 1);
        }
        else
        {
            FUN_14166ed50(pNpc, 0);
            FUN_14166ef10(pNpc, strText, true, 0, 1);
        }
    }
}

// Turn the local player towards / to a point.
// @0x1418642e0
void CTriggerService::FUN_1418642e0(CInPacket* pEvent)
{
    PCBase* pPlayer = static_cast<PCBase*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPlayer != 0)
    {
        Unk_StreamPoint pt = pEvent->vfunc_o8_11();
        bool bMove = pEvent->vfunc_o8_0();
        FUN_14166d8b0(pPlayer, pt.z);
        if (bMove)
            pPlayer->vfunc_21(efd::Point3(pt.x, pt.y, pt.z));
    }
}

// @0x1418643c0
void CTriggerService::FUN_1418643c0(CInPacket* pEvent)
{
    PCBase* pPlayer = static_cast<PCBase*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPlayer != 0)
    {
        Unk_StreamPoint pt = pEvent->vfunc_o8_11();
        bool bFlag = pEvent->vfunc_o8_0();
        FUN_14166d2d0(pPlayer, efd::Point3(pt.x, pt.y, pt.z), bFlag);
    }
}
