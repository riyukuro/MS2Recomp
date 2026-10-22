// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIRealEstateSell: the sell-your-house confirmation dialog. See uirealestatesell.h.
// MS2-UNIT: ?\uirealestatesell.cpp
// MS2-RANGE: 0x141ab5d50-0x141ab6f50 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "uirealestatesell.h"
#include "uimessagebox.h"
#include "uiservice.h"
#include "uimessageboxdata.h"
#include <atlcoll.h>
#include <atltime.h>
#include <NiMesh.h>
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/mypc.h"
#include "ms2/placeholder/userugcmapinfo.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of exe types ----

CUIService* FUN_1403ed2b0();
class Unk_RsWorld { public: MyPC* FUN_141bd0cc0(); };               // the local player
Unk_RsWorld* FUN_1403ed2d0();

// The sellable-house record of a house (0xc8 bytes; ctor 0x1408ad110, dtor 0x14050de70).
struct Unk_RsSalable
{
    Unk_RsSalable();
    ~Unk_RsSalable();
    void* m_pad[25];
};
void FUN_1408ad110(Unk_RsSalable* p);
void FUN_14050de70(Unk_RsSalable* p);
Unk_RsSalable::Unk_RsSalable() { FUN_1408ad110(this); }
Unk_RsSalable::~Unk_RsSalable() { FUN_14050de70(this); }
int FUN_1408a0d30(int nGroup, Unk_RsSalable* pSalable, int nMapId);   // the house group is sellable (fills pSalable)

// The map / group record the house stands on.
class Unk_GmTarget { public: int m_pad_0[7]; int m_1c; int m_20; int m_24; };
class Unk_GmTargetRef
{
public:
    Unk_GmTargetRef(void* p);                                       // 0x14050dd40
    ~Unk_GmTargetRef();                                             // 0x14050de40
    Unk_GmTarget* FUN_14050dee0();
    void* m_0;
    void* m_8;
};

// The house service: the smart pointer to it (8 bytes; the glue COMDATs live in the unit that first used it).
class Unk_HoService;
struct Unk_EntityAppFramework;
extern Unk_EntityAppFramework DAT_143b059e8;
class Unk_HoServicePtr
{
public:
    Unk_HoServicePtr(Unk_HoService* p);                             // 0x1401cd0b0
    ~Unk_HoServicePtr();                                            // 0x1401cd150
    Unk_HoService* m_p;
};
Unk_HoService* FUN_1401cd040(Unk_EntityAppFramework* framework);

class Unk_RsGrid;                                                   // the cube map information service
Unk_RsGrid* FUN_1409670e0();
__int64 FUN_1410c3180(Unk_RsGrid* p);                               // the account id of the house owner? (compared to the own account)
extern __int64 DAT_143ab2820;                                       // my account id

class Unk_RsStrings { public: CStringW FUN_141811980(int nTable, int nIndex); };   // string table by (table, id)
Unk_RsStrings* FUN_1401a9d70();

__int64 FUN_140869440();                                            // the server time
CStringW FUN_140979570(int nMapId);                                 // the address of a map
CStringW FUN_14086d060(int nId, const __int64& n);                  // string table text with one number
CStringW FUN_14052bd00(int nId, const CStringW& arg);               // string table text with one argument
CStringW FUN_1409404f0(__int64 n);                                  // a number with thousand separators
int FUN_1408a09d0(unsigned* pnItem, __int64* pnPrice, int nMapId, int nGroup);   // the sale price (item, amount)
int FUN_1408a0b80(unsigned* pnItem, __int64* pnPrice, int nMapId, int nGroup);   // the extension price
bool FUN_14053f8c0(unsigned nItemId);
unsigned char FUN_14053f940(unsigned nItemId);

int FUN_1418fc760(const char* szEvent, void* a2, int a3, void* a4);
void FUN_140d73bc0(int nStrId, int nType, void* p, CStringW tag);
MS2Ptr<CMsgBoxData> FUN_140d73e40(int, int, void*, CStringW);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
void FUN_14151f200();
bool FUN_140164830(const CStringW& a, const CStringW& b);
int FUN_14028cb70(const CStringW& str, ATL::CAtlArray<CStringW>& out, const wchar_t* szDelim, int nMax);
void FUN_140710590(COutPacket& packet);

// @0x141ab5d50
UIRealEstateSell::UIRealEstateSell()
{
    FUN_141924170(1);
}

// @0x141ab5db0
UIRealEstateSell::~UIRealEstateSell()
{
}

// @0x141ab5df0
CString UIRealEstateSell::GetTypeName()
{
    return "RealEstateSell";
}
MS2_REPLACE_METHOD(0x141AB5DF0, UIRealEstateSell, GetTypeName, 61, 0xA6C5C1A5);

// @0x141ab5e40
int UIRealEstateSell::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    m_178 = 0;
    return 1;
}

// @0x141ab5e80
void UIRealEstateSell::vfunc_67()
{
    vfunc_47(1);
    if (m_178 != 0)
        FUN_1403ed2b0()->FUN_141adc5d0((eUIClassID)0x4e76);
    UIDialog::vfunc_67();
}

// @0x141ab5ee0
void UIRealEstateSell::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_141ab6230();
}

// MS2-FUNCTIONAL: the exe returns the IsNull result (base slot is void); extra movzx only
// @0x141ab5f10
void UIRealEstateSell::vfunc_79(void* p)
{
    UIDialog::vfunc_79(p);
    if (vfunc_55() == 0)
        m_30.IsNull();
}

// @0x141ab5f70
void UIRealEstateSell::OnLoadInit()
{
    UIObject::OnLoadInit();
    vfunc_47(0);
}

// MS2-FUNCTIONAL: small codegen diffs (temp spills / branch layout) vs exe
// @0x141ab5fb0
int UIRealEstateSell::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (FUN_1418fc760(szMethod, (void*)pArgs, nArgs, 0) != 0)
        return 1;
    if (_stricmp("OnClose", szMethod) == 0)
    {
        vfunc_67();
        return 1;
    }
    if (_stricmp("OnConfirm", szMethod) == 0)
    {
        __int64 nOwner = FUN_1410c3180(FUN_1409670e0());
        if (nOwner == 0 || nOwner != DAT_143ab2820)
        {
            MS2Ptr<CMsgBoxData> box = FUN_140d73e40(10, 0x7e4, static_cast<IMessageListener*>(this), CStringW(L"confirmName"));
            if (box.get() != 0)
            {
                box->FUN_141a01d30(2, CStringW(L""), 0x18, 0, 0);
                FUN_140d73c60(box);
            }
            return 1;
        }
        FUN_140d73bc0(0x7e6, 0, 0, CStringW(L""));
        return 1;
    }
    return 0;
}

// MS2-FUNCTIONAL: large body, temp spills / argument evaluation order differ vs exe
// @0x141ab6230
void UIRealEstateSell::FUN_141ab6230()
{
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0 || pPC->FUN_141527e00() != 0 || pPC->FUN_141523c50() == 0 || m_30.IsNull())
        return;
    ASObj obj(2);
    Unk_HoServicePtr spService(FUN_1401cd040(&DAT_143b059e8));
    Unk_GmTargetRef target(pPC->FUN_141523c50());
    Unk_RsSalable salable;
    if (FUN_1408a0d30(target.FUN_14050dee0()->m_24, &salable, target.FUN_14050dee0()->m_20) == 0)
        return;
    CStringW strName = pPC->vfunc_77();
    obj.FUN_1407cbb20("houseName", strName);
    CStringW strAddress = FUN_140979570(target.FUN_14050dee0()->m_20);
    obj.FUN_1407cbb20("address", strAddress);
    CMsTime tNow(FUN_140869440());
    CMsTime tEnd(pPC->FUN_141523c50()->m_n30);
    ATL::CTimeSpan span = tEnd - tNow;
    if (span.GetDays() >= 0)
    {
        CStringW strExpire;
        __int64 nDays = span.GetDays();
        strExpire = FUN_14086d060(0x7ce, nDays);
        obj.FUN_1407cbb20("expire", strExpire);
    }
    obj.FUN_1407cb9c0("priceType", 0);
    unsigned nItem = 0;
    __int64 nPrice = 0;
    FUN_1408a09d0(&nItem, &nPrice, target.FUN_14050dee0()->m_20, target.FUN_14050dee0()->m_24);
    unsigned nItem2 = 0;
    __int64 nPrice2 = 0;
    FUN_1408a0b80(&nItem2, &nPrice2, target.FUN_14050dee0()->m_20, target.FUN_14050dee0()->m_24);
    if (FUN_14053f8c0(nItem))
    {
        obj.FUN_1407cbb20("price", FUN_14052bd00(0x7e2, FUN_1409404f0(nPrice)));
    }
    else if (FUN_14053f940(nItem))
    {
        obj.FUN_1407cbb20("price", FUN_14052bd00(0x7e3, FUN_1409404f0(nPrice)));
    }
    else
    {
        CStringW strPrice;
        strPrice.Format(L"%s x%d", (const wchar_t*)FUN_1401a9d70()->FUN_141811980(1, nItem), nPrice);
        obj.FUN_1407cbb20("price", strPrice);
    }
    if (FUN_14053f8c0(nItem2))
    {
        obj.FUN_1407cbb20("extend", FUN_14052bd00(0x7e2, FUN_1409404f0(nPrice2)));
    }
    else if (FUN_14053f940(nItem2))
    {
        obj.FUN_1407cbb20("extend", FUN_14052bd00(0x7e3, FUN_1409404f0(nPrice2)));
    }
    else
    {
        CStringW strExtend;
        strExtend.Format(L"%s x%d", (const wchar_t*)FUN_1401a9d70()->FUN_141811980(1, nItem2), nPrice2);
        obj.FUN_1407cbb20("extend", strExtend);
    }
    m_30->Invoke("initData", obj);
}

// MS2-FUNCTIONAL: temp spills / CStringW copy placement differ vs exe
// @0x141ab6ad0
int UIRealEstateSell::SendRequestCube(CStringW strName)
{
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    if (FUN_140164830(pPC->vfunc_77(), strName))
    {
        FUN_140d73bc0(0x7e5, 0, 0, CStringW(L""));
        return 0;
    }
    if (m_30.IsNull())
        return 0;
    m_30->Invoke("onSell");
    COutPacket packet(0x37, 0);
    packet.vfunc_o10_1(6);
    FUN_140710590(packet);
    m_178 = 1;
    return 1;
}

// MS2-FUNCTIONAL: temp spills / token array element access differ vs exe
// @0x141ab6c50
int UIRealEstateSell::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) != 0)
        return 1;
    if (pMsg->FUN_1422e4520() != 0 || dynamic_cast<UIMessageBox*>(pSender) == 0)
        return 0;
    int nAnswer = pMsg->FUN_1422b8a10();
    CStringW strTag = pMsg->FUN_1422b8f40();
    if (strTag.Find(L"confirmName", 0) == 0 && nAnswer == 0)
    {
        ATL::CAtlArray<CStringW> aParts;
        if (FUN_14028cb70(strTag, aParts, L",", 2) == 0)
            return 0;
        CStringW strInput(aParts[1]);
        if (SendRequestCube(strInput) != 0)
            FUN_14151f200();
        return 1;
    }
    FUN_14151f200();
    return 1;
}

extern int DAT_143ae2b34;                                           // 1: the markers are MS2 flag bits instead of extra data (instancing)
extern NiFixedString DAT_143ae51c0;
struct Unk_RsSceneIter { void* m_p[6]; };
void FUN_14098cb80(Unk_RsSceneIter* pIter, NiAVObject* pRoot);
NiAVObject* FUN_14098e0d0(Unk_RsSceneIter* pIter, int bDescend);
void FUN_14098cf00(Unk_RsSceneIter* pIter);
void FUN_1410865e0(NiAVObject* pkObject, const NiFixedString& kKey, bool bRecursive);
void FUN_141568d80(NiAVObject* pkObject);

// MS2-FUNCTIONAL: scene walker local layout differs vs exe
// @0x141ab6e80
void FUN_141ab6e80(NiAVObject* pRoot)
{
    if (pRoot == 0)
        return;
    if (DAT_143ae2b34 == 0)
    {
        Unk_RsSceneIter it;
        FUN_14098cb80(&it, pRoot);
        NiAVObject* pObject;
        while ((pObject = FUN_14098e0d0(&it, 1)) != 0)
        {
            NiMesh* pMesh = NiDynamicCast(NiMesh, pObject);
            if (pMesh != 0 && pMesh->GetExtraData(DAT_143ae51c0) == 0)
                FUN_1410865e0(pMesh, DAT_143ae51c0, true);
        }
        FUN_14098cf00(&it);
    }
    else
    {
        FUN_141568d80(pRoot);
    }
}
