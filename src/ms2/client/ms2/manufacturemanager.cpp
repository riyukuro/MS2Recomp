// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CManufactureManager: the maid manufacture (crafting) records of
// the user, the manufacture requests (packet 0x68) with their client-side checks, and the maid speech text. The head of the
// unit is the header statics (maid sound names, market sort names); the tail is the CRBMap<id, MS2Ptr<CManufacture>> glue.
// MS2-UNIT: ?\manufacturemanager.cpp
// MS2-RANGE: 0x1400d3280-0x1400d3440 .text$di
// MS2-RANGE: 0x140d50010-0x140d53490 .text$mn
// MS2-RANGE: 0x142ca5180-0x142ca5240 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?IsNull@?$Unk_MfValuePtr@UUnk_MfIngredient@@@@QEBA_NXZ 0x140d51d00 ; unique
// MS2-PIN: ?IsNull@?$Unk_MfValuePtr@UUnk_MfMaidMsg@@@@QEBA_NXZ 0x140d51d30 ; prop
// MS2-PIN: ?IsNull@?$MS2Ptr@VUnk_MfMaid@@@@QEBA_NXZ 0x140d51d60 ; unique
// MS2-PIN: ?FUN_140d52020@CManufacture@@QEAA_JXZ 0x140d52020 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\manufacturemanager.cpp"
#define NOMINMAX
#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include <vector>
#include <afxdialogex.h>
#include "ms2/placeholder/cmaidmanufacturemsgtable.h"
#include <efd/ISystemService.h>
#include <efd/ServiceManager.h>
#include "ms2/placeholder/cmanufacturemanager.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cmaid.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/socketptr.h"
#include "ms2/placeholder/uiobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/gamerule.h"
#include "ms2/placeholder/creservedwordtable.h"
#include "ms2/commonfiles/maidgradejockpottable.h"
#include "ms2/client/ms2/uiservice.h"  // C3: CUIService::FUN_141adc890
#include "ms2/placeholder/fittingdollpc.h"  // C3: PC::FUN_1416561a0
#include "ms2/ms2format.h"   // C3: fmt for BlockFormat<int>
#include "ms2/client/ms2/cubemapinformationservice_3.h"

// ---- statics of the unit's header (init order: maid sound names, then the market sort names) ----------------------------
static CString s_strMaidCancel = "maid_Cancel";
static CString s_strMaidFirework = "maid_Firework";
static CString s_strMaidReceive = "maid_Receive";
static CString s_strMaidReceiveJackpot = "maid_Receive_Jackpot";
static CString s_strMaidRequest = "maid_Request";
static CString s_strSortTypeNames[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};

// ---- unit-local views of exe types (names invented) ------------------------------------------------------------------------

// Payload types boxed in a TPtredDummy (the smart pointer points at the value, 0x18 behind the CPtred base).
struct Unk_MfIngredient                                         // one recipe ingredient
{
    int m_nCount;                                               // +0x00
    int m_nRarity;                                              // +0x04
    unsigned m_nItemId;                                         // +0x08
    int m_nGroup;                                               // +0x0c
};
struct Unk_MfMaidMsg                                            // MaidManufactureMsg payload (strings from +0x08)
{
    int m_nMaidId;                                              // +0x00
    int m_pad_04;
    CStringW m_strSelectItem;                                   // +0x08
    CStringW m_strCraftRequest;                                 // +0x10
    CStringW m_strReceiveItem;                                  // +0x18
    CStringW m_strReceiveJackpot;                               // +0x20
    CStringW m_strCraftCancel;                                  // +0x28
    CStringW m_strNotEnoughIgd;                                 // +0x30
    CStringW m_strExpired;                                      // +0x38
};
MS2_CHECK_SIZE(Unk_MfMaidMsg, 0x40);

template <class T> class Unk_MfValuePtr                         // the exe's 16-byte smart pointer to a boxed payload
{
public:
    Unk_MfValuePtr() : m_pad(0), m_p(0) {}
    Unk_MfValuePtr(const Unk_MfValuePtr& o) : m_pad(0), m_p(o.m_p) { AddRef(); }
    ~Unk_MfValuePtr() { Release(); }
    Unk_MfValuePtr& operator=(const Unk_MfValuePtr& o) { o.AddRef(); Release(); m_p = o.m_p; return *this; }
    T* get() const { return m_p; }
    T* operator->() const { return m_p; }
    bool IsNull() const { return m_p == 0; }
private:
    static CPtred* Base(T* p) { return reinterpret_cast<CPtred*>(reinterpret_cast<char*>(p) - sizeof(CPtred)); }
    void AddRef() const { if (m_p) CPtred::AddRefPtred(Base(m_p)); }
    void Release()
    {
        if (m_p)
        {
            if (CPtred::ReleasePtred(Base(m_p)) == 0)
            {
                CPtred::AddRefPtred(Base(m_p));
                CPtred::DeletePtred(Base(m_p));
            }
            m_p = 0;
        }
    }
    void* m_pad;
    T* m_p;
};
MS2_CHECK_SIZE(Unk_MfValuePtr<Unk_MfIngredient>, 0x10);

struct Unk_MfRecipe                                             // maid recipe (the table at DAT_143ab03c8 maps id -> recipe)
{
    int m_pad_00[7];
    int m_nMeso;                                                // +0x1c
    char m_pad_20[0x38 - 0x20];
    std::vector<Unk_MfValuePtr<Unk_MfIngredient> > m_aIngredients;  // +0x38
};
MS2_CHECK_OFFSET(Unk_MfRecipe, m_aIngredients, 0x38);

class Unk_MfMaid : public CPtred                                // the maid object of an npc (only the message id is used)
{
public:
    char m_pad_18[0x34 - 0x18];
    int m_nMsgId;                                               // +0x34
};
MS2_CHECK_OFFSET(Unk_MfMaid, m_nMsgId, 0x34);

class Unk_MfNpc { public: MS2Ptr<Unk_MfMaid> FUN_141093800(); };    // npc: its maid (empty when it has none)

class Unk_MfRecipeTable { public: Unk_MfValuePtr<Unk_MfRecipe> FUN_1406855c0(int nRecipeId); };
class Unk_MfMsgTable { public: Unk_MfValuePtr<Unk_MfMaidMsg> FUN_14067fd60(int nMaidId); };
class Unk_MfInventory
{
public:
    unsigned FUN_140a5f780(int nGroup, int nRarity);            // owned count of the group
};
enum SAType;   // C3: the special ability type (commonfiles/additionalactionadditional.h)
class CEquipment { public: float GetAbilityRate(SAType eType); };   // C3: the real member (0x1411e1110, a special ability rate)
class Unk_MfPC { public: };
class Unk_MfCubeService : public efd::ISystemService { public: int FUN_1410d2fb0(__int64 nAccountId, int nMeso, int* pnCode); };
class Unk_MfWordTable : public CReservedWordTable { public: void FUN_1416fb400(CStringW& str, Unk_MfNpc* pNpc);};
struct Unk_EntityAppFramework { efd::ServiceManagerPtr manager; };

namespace egf { class ScriptContext; extern ScriptContext g_bapiContext; }
#define DAT_143b059e8 (*(Unk_EntityAppFramework*)&egf::g_bapiContext)          // C3: was extern Unk_EntityAppFramework DAT_143b059e8
class Unk_Inventory { public: int FUN_140a5f180(int itemId, int rarity); };   // C3: unit-local view (def in inventory); owned count of the item
extern Unk_Inventory g_143ab2a90;   // C3: the real global (0x143ab2a90); read through Unk_MfInventory // the player's inventory
extern __int64 DAT_143ab2820;                                   // own account id

// ---- out-of-unit callees ----
class WorldService   // C3: member view for the former free stand-ins
{
public:
    void* FUN_141bd0cc0();
    static class WorldService* GetInstance();
};
void*FUN_1401c0d90();
class Unk_Service6100017* FUN_1401cd040(struct Unk_EntityAppFramework*);   // C3: was FUN_1401cd040
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
int FUN_14053feb0(int nItemId);                                 // default rarity of an item
__int64 GetServerTime();                                        // server time
void FUN_140710590(COutPacket& packet);                         // send
int FUN_141276180(const CString& strName, const CString& strArg);  // play a system sound
CStringW GetStringCommon(int nStringId);
#include "ms2/placeholder/blockformat.h"
void FUN_140694050(class CManufacture&, class CByteBuffer&);   // C3: was FUN_140694050
void FUN_1412dc3c0(UIManufactureStatus* pDlg);

class UIManufactureDialog : public UIObject {public:
    void FUN_1412e6110(int);   // C3: was free FUN_1412e6110
public:
    void FUN_1412e6850(int);   // C3: was free FUN_1412e6850
public:
    void FUN_1412e6af0(int);   // C3: was free FUN_1412e6af0
public:
    void FUN_1412e6c30(int, int, int, int, int, int, int);   // C3: was free FUN_1412e6c30
};
class UIManufactureStatus : public UIObject {};

// @0x140d50010
CManufactureManager::CManufactureManager()
    : m_mapManufacture(10)
{
}

// @0x140d50060
CManufactureManager::~CManufactureManager()
{
    m_mapManufacture.RemoveAll();
}

// @0x140d500b0
void CManufactureManager::OnPacket(CInPacket* pPacket)
{
    int cMode = pPacket->ReadUInt8();
    if (cMode == 0)
    {
        m_mapManufacture.RemoveAll();
        unsigned __int64 nCount = (unsigned)pPacket->ReadInt32();
        for (unsigned __int64 i = 0; i < nCount; i++)
        {
            MS2Ptr<CManufacture> spItem(new CManufacture);
            FUN_140694050(*spItem.get(), *(class CByteBuffer*)&(*pPacket));
            m_mapManufacture.SetAt(spItem->FUN_140d52020(), spItem);
        }
    }
    else if (cMode == 1)
    {
        MS2Ptr<CManufacture> spItem(new CManufacture);
        FUN_140694050(*spItem.get(), *(class CByteBuffer*)&(*pPacket));
        m_mapManufacture.SetAt(spItem->FUN_140d52020(), spItem);
    }
    else if (cMode == 2)
    {
        MS2Ptr<CManufacture> spItem(new CManufacture);
        FUN_140694050(*spItem.get(), *(class CByteBuffer*)&(*pPacket));
        m_mapManufacture.SetAt(spItem->FUN_140d52020(), spItem);
    }
    else if (cMode == 3)
    {
        unsigned __int64 nId = pPacket->ReadInt64();
        m_mapManufacture.RemoveKey(nId);
    }
    else if (cMode == 4)
    {
        int nValue = pPacket->ReadInt32();
        if ((((CUIService*)(TSingleton<CUIService>::GetInstance()))->FUN_141adc890((eUIClassID)(0x4ec0))) != 0)
        {
            UIManufactureDialog* pDlg = GetManufactureDialog(0x4ec0);
            if (pDlg != 0)
                ((class UIManufactureDialog*)(class UIManufactureDialog*)(pDlg))->FUN_1412e6110(nValue);
        }
    }
    else if (cMode == 6)
    {
        int nValue = pPacket->ReadInt32();
        if ((((CUIService*)(TSingleton<CUIService>::GetInstance()))->FUN_141adc890((eUIClassID)(0x4ec0))) != 0)
        {
            UIManufactureDialog* pDlg = GetManufactureDialog(0x4ec0);
            if (pDlg != 0)
                ((class UIManufactureDialog*)(class UIManufactureDialog*)(pDlg))->FUN_1412e6850(nValue);
        }
    }
    else if (cMode == 7)
    {
        int nValue = pPacket->ReadInt32();
        if ((((CUIService*)(TSingleton<CUIService>::GetInstance()))->FUN_141adc890((eUIClassID)(0x4ec0))) != 0)
        {
            UIManufactureDialog* pDlg = GetManufactureDialog(0x4ec0);
            if (pDlg != 0)
                ((class UIManufactureDialog*)(class UIManufactureDialog*)(pDlg))->FUN_1412e6850(nValue);
        }
    }
    else if (cMode == 8)
    {
        int nValue = pPacket->ReadInt32();
        if ((((CUIService*)(TSingleton<CUIService>::GetInstance()))->FUN_141adc890((eUIClassID)(0x4ec0))) != 0)
        {
            UIManufactureDialog* pDlg = GetManufactureDialog(0x4ec0);
            if (pDlg != 0)
                ((class UIManufactureDialog*)(class UIManufactureDialog*)(pDlg))->FUN_1412e6850(nValue);
        }
    }
    else if (cMode == 9)
    {
        int nValue = pPacket->ReadInt32();
        if ((((CUIService*)(TSingleton<CUIService>::GetInstance()))->FUN_141adc890((eUIClassID)(0x4ec0))) != 0)
        {
            UIManufactureDialog* pDlg = GetManufactureDialog(0x4ec0);
            if (pDlg != 0)
                ((class UIManufactureDialog*)(class UIManufactureDialog*)(pDlg))->FUN_1412e6850(nValue);
        }
    }
    else if (cMode == 10)
    {
        int nValue = pPacket->ReadInt32();
        if ((((CUIService*)(TSingleton<CUIService>::GetInstance()))->FUN_141adc890((eUIClassID)(0x4ec0))) != 0)
        {
            UIManufactureDialog* pDlg = GetManufactureDialog(0x4ec0);
            if (pDlg != 0)
                ((class UIManufactureDialog*)(class UIManufactureDialog*)(pDlg))->FUN_1412e6af0(nValue);
        }
    }
    else if (cMode == 11)
    {
        int nA = pPacket->ReadInt32();
        int nB = pPacket->ReadInt32();
        int cC = pPacket->ReadUInt8();
        int nD = pPacket->ReadInt32();
        int nE = pPacket->ReadInt32();
        int cF = pPacket->ReadUInt8();
        int cG = pPacket->ReadUInt8();
        if ((((CUIService*)(TSingleton<CUIService>::GetInstance()))->FUN_141adc890((eUIClassID)(0x4ec0))) != 0)
        {
            UIManufactureDialog* pDlg = GetManufactureDialog(0x4ec0);
            if (pDlg != 0)
                ((class UIManufactureDialog*)(class UIManufactureDialog*)(pDlg))->FUN_1412e6c30(nA, cC, nB, nD, nE, cF, cG);
        }
    }
    if (cMode == 1 || cMode == 2 || cMode == 3)
    {
        if ((((CUIService*)(TSingleton<CUIService>::GetInstance()))->FUN_141adc890((eUIClassID)(0x4ec9))) != 0)
        {
            UIManufactureStatus* pDlg = GetManufactureStatus(0x4ec9);
            if (pDlg != 0)
                FUN_1412dc3c0(pDlg);
        }
    }
}

// @0x140d509b0
int CManufactureManager::SendRequest4(unsigned __int64 nId, int nRecipeId, int* pnResult)
{
    Unk_MfPC* pPC = ((class Unk_MfPC*)((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0());
    if (pPC == 0)
        return 0;
    {
        Unk_MfValuePtr<Unk_MfRecipe> spRecipe = reinterpret_cast<Unk_MfRecipeTable*>(TSingleton<CMaidRecipeTable>::GetInstance())->FUN_1406855c0(nRecipeId);
        if (spRecipe.get() != 0)
        {
            for (unsigned __int64 i = 0; i < spRecipe->m_aIngredients.size(); i++)
            {
                Unk_MfValuePtr<Unk_MfIngredient> spIng = spRecipe->m_aIngredients[i];
                if (spIng.IsNull())
                    continue;
                unsigned nItemId = reinterpret_cast<MaidIngredient*>(spIng.operator->())->GetItemId();
                MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
                if (spItem == 0)
                    continue;
                int nRarity = spItem->FUN_14053cbc0() ? spIng->m_nRarity : FUN_14053feb0(nItemId);
                unsigned nOwned = 0;
                if (reinterpret_cast<MaidIngredient*>(spIng.operator->())->GetItemStringId() == 0)
                    nOwned = g_143ab2a90.FUN_140a5f180(nItemId, nRarity);
                else
                    nOwned = reinterpret_cast<Unk_MfInventory&>(g_143ab2a90).FUN_140a5f780(reinterpret_cast<MaidIngredient*>(spIng.operator->())->GetItemStringId(), nRarity);
                unsigned nNeed = reinterpret_cast<CGameRule *>(FUN_1401c0d90())->FUN_14047b860(reinterpret_cast<CEquipment*>(reinterpret_cast<PC*>(pPC)->FUN_1416561a0())->GetAbilityRate((SAType)0x3f), spIng->m_nCount);
                if (nNeed > nOwned)
                {
                    *pnResult = 8;
                    return 0;
                }
            }
            if (0 < spRecipe->m_nMeso)
            {
                int nCode = 0;
                efd::SmartPointer<Unk_MfCubeService> spService(((class Unk_MfCubeService*)FUN_1401cd040(&DAT_143b059e8)));
                int nOk = reinterpret_cast<CubeMapInformationService*>(spService.operator->())->FUN_1410d2fb0(DAT_143ab2820, spRecipe->m_nMeso, &nCode);
                if (nOk == 0)
                {
                    *pnResult = 8;
                    return 0;
                }
            }
        }
    }
    COutPacket packet(static_cast<int>(SendOp::MaidCraftItem), 0);
    packet.WriteUInt8(4);
    packet.WriteInt32(nRecipeId);
    packet.WriteInt64(nId);
    FUN_140710590(packet);
    *pnResult = 1;
    return 1;
}

// @0x140d50dd0
int CManufactureManager::SendRequest5(unsigned __int64 nId, int nRecipeId, int* pnResult)
{
    COutPacket packet(static_cast<int>(SendOp::MaidCraftItem), 0);
    packet.WriteUInt8(5);
    packet.WriteInt32(nRecipeId);
    packet.WriteInt64(nId);
    FUN_140710590(packet);
    *pnResult = 1;
    return 1;
}

// @0x140d50e70
int CManufactureManager::SendRequest6(unsigned __int64 nId, int* pnResult)
{
    MS2Ptr<CManufacture> spItem(0);
    if (Lookup(nId, spItem) == 0)
    {
        *pnResult = 7;
        return 0;
    }
    if (spItem->FUN_140694170() > GetServerTime())
    {
        *pnResult = 0xd;
        return 0;
    }
    COutPacket packet(static_cast<int>(SendOp::MaidCraftItem), 0);
    packet.WriteUInt8(6);
    packet.WriteInt64(nId);
    FUN_140710590(packet);
    *pnResult = 2;
    return 1;
}

// @0x140d50fb0
int CManufactureManager::SendRequest7(unsigned __int64 nId, int* pnResult)
{
    MS2Ptr<CManufacture> spItem(0);
    if (Lookup(nId, spItem) == 0)
    {
        *pnResult = 7;
        return 0;
    }
    COutPacket packet(static_cast<int>(SendOp::MaidCraftItem), 0);
    packet.WriteUInt8(7);
    packet.WriteInt64(nId);
    FUN_140710590(packet);
    *pnResult = 2;
    return 1;
}

// @0x140d510a0
int CManufactureManager::SendRequest8(unsigned __int64 nId, int* pnResult)
{
    MS2Ptr<CManufacture> spItem(0);
    if (Lookup(nId, spItem) == 0)
    {
        *pnResult = 7;
        return 0;
    }
    COutPacket packet(static_cast<int>(SendOp::MaidCraftItem), 0);
    packet.WriteUInt8(8);
    packet.WriteInt64(nId);
    FUN_140710590(packet);
    *pnResult = 2;
    return 1;
}

// @0x140d51190
int CManufactureManager::SendRequest9(unsigned __int64 nId, int* pnResult)
{
    MS2Ptr<CManufacture> spItem(0);
    if (Lookup(nId, spItem) == 0)
    {
        *pnResult = 7;
        return 0;
    }
    COutPacket packet(static_cast<int>(SendOp::MaidCraftItem), 0);
    packet.WriteUInt8(9);
    packet.WriteInt64(nId);
    FUN_140710590(packet);
    *pnResult = 3;
    return 1;
}

// @0x140d51280
int CManufactureManager::SendRequest10(unsigned __int64 nId, int* pnResult)
{
    MS2Ptr<CManufacture> spItem(0);
    if (Lookup(nId, spItem) == 0)
    {
        *pnResult = 7;
        return 0;
    }
    COutPacket packet(static_cast<int>(SendOp::MaidCraftItem), 0);
    packet.WriteUInt8(10);
    packet.WriteInt64(nId);
    FUN_140710590(packet);
    *pnResult = 4;
    return 1;
}

// @0x140d51370
int CManufactureManager::Lookup(unsigned __int64 nId, MS2Ptr<CManufacture>& spOut)
{
    if (m_mapManufacture.Lookup(nId, spOut))
        return 1;
    return 0;
}

// @0x140d513c0
int CManufactureManager::HasManufacture()
{
    return m_mapManufacture.GetCount() != 0 ? 1 : 0;
}

// @0x140d51400
CStringW CManufactureManager::GetMaidText(int nType, Unk_MfNpc* pNpc)
{
    CStringW strText(L"");
    if (pNpc == 0)
        return strText;
    MS2Ptr<Unk_MfMaid> spMaid = pNpc->FUN_141093800();
    if (spMaid.IsNull())
        return strText;
    Unk_MfValuePtr<Unk_MfMaidMsg> spMsg = reinterpret_cast<Unk_MfMsgTable*>(CMaidManufactureMsgTable::GetInstance())->FUN_14067fd60(spMaid.get()->m_nMsgId);
    if (spMsg.IsNull())
        return strText;
    switch (nType)
    {
    case 0:
        strText = spMsg.get()->m_strSelectItem;
        break;
    case 1:
        FUN_141276180(s_strMaidRequest, "");
        strText = spMsg.get()->m_strCraftRequest;
        break;
    case 2:
        FUN_141276180(s_strMaidReceive, "");
        strText = spMsg.get()->m_strReceiveItem;
        break;
    case 3:
        FUN_141276180(s_strMaidReceiveJackpot, "");
        FUN_141276180(s_strMaidFirework, "");
        strText = spMsg.get()->m_strReceiveJackpot;
        break;
    case 4:
        FUN_141276180(s_strMaidCancel, "");
        strText = spMsg.get()->m_strCraftCancel;
        break;
    case 8:
        strText = spMsg.get()->m_strNotEnoughIgd;
        break;
    case 0x12:
        strText = spMsg.get()->m_strExpired;
        break;
    case 5:
    case 6:
    case 7:
    case 9:
    case 10:
    case 0xb:
    case 0xc:
    case 0xd:
    case 0xe:
    case 0xf:
    case 0x10:
    case 0x11:
    case 0x13:
    case 0x14:
    {
        int nArg = nType;
        strText = BlockFormat<int>(0x7c6, nArg);
        break;
    }
    case 0x15:
        strText = GetStringCommon(0xc07);
        break;
    }
    TSingleton<CReservedWordTable>::GetInstance()->FUN_1416fb400(strText, pNpc);
    reinterpret_cast<Unk_MfWordTable*>(TSingleton<CReservedWordTable>::GetInstance())->FUN_1416fb340(strText);
    return strText;
}

// @0x140d51900
UIManufactureDialog* CManufactureManager::GetManufactureDialog(int nUiId)
{
    if (TSingleton<CUIService>::GetInstance() != 0)
    {
        MS2Ptr<UIObject> spUI = ((CUIService*)TSingleton<CUIService>::GetInstance())->FindObject((eUIClassID)nUiId);
        if (spUI.get() != 0)
            return dynamic_cast<UIManufactureDialog*>((UIObject*)spUI);
    }
    return 0;
}

// @0x140d519a0
UIManufactureStatus* CManufactureManager::GetManufactureStatus(int nUiId)
{
    if (TSingleton<CUIService>::GetInstance() != 0)
    {
        MS2Ptr<UIObject> spUI = ((CUIService*)TSingleton<CUIService>::GetInstance())->FindObject((eUIClassID)nUiId);
        if (spUI.get() != 0)
            return dynamic_cast<UIManufactureStatus*>((UIObject*)spUI);
    }
    return 0;
}

// @0x140d53460
CRuntimeClass* FUN_140d53460()
{
    return CDialogEx::GetThisClass();
}
