// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIUGCCubeBillDialog: the bill of an UGC cube / blueprint
// purchase. See uiugccubebilldialog.h.
// MS2-UNIT: ?\uiugccubebilldialog.cpp
// MS2-RANGE: 0x1400dd010-0x1400dd160 .text$di
// MS2-RANGE: 0x140ee7610-0x140ee9c90 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?CompareElementsOrdered@?$CDefaultCompareTraits@W4ePayType@@@ATL@@SAHAEBW4ePayType@@0@Z 0x140ee8b60 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiugccubebilldialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uiugccubebilldialog.h"
#include "uiservice.h"
#include "uimessageboxdata.h"
#include "inventory.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <vector>

// ---- unit-local views of unrecovered callees -----------------------------------------------------------------------

// The confirm button of the bill ("m_buy").
class Unk_UcbButton : public ASDisplayObject
{
public:
    void FUN_1422cdfb0(const CStringW& strLabel);       // set the label
};

CUIService* FUN_1403ed2b0();
CFeatureManager* FUN_140166410();
extern Unk_Inventory DAT_143ab2a90;
void FUN_140710590(COutPacket& packet);                 // send
CStringW FUN_140938ae0(CStringW strFormat, const int& nArg);    // string table text with one argument
CStringW FUN_1418fe5d0(int nPayType);                   // pay type name
CStringW FUN_1418fec00(int nType, __int64 nValue, int);     // money text by pay type
void FUN_140930590(__int64 nId, std::vector<std::pair<int, __int64> >& vecOut);     // the pay type rows of a pool
unsigned char FUN_140930200(int nKind);

// ---- statics (init order: the cost, the pending cost, the sort type names of the shared header, the key controller) ----

UIUGCCubeBillDialog::Cost UIUGCCubeBillDialog::s_cost;
UIUGCCubeBillDialog::PendingCost UIUGCCubeBillDialog::s_pending;
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static UICommon::CMyPCKeyInputController s_keyInput;

// ---- UIUGCCubeBillDialog ----

// @0x140ee7610
UIUGCCubeBillDialog::UIUGCCubeBillDialog()
{
    m_80 = 0;
    m_88 = 1;
    m_58 = 1;
    FUN_141924170(1);
}

// @0x140ee76a0
UIUGCCubeBillDialog::~UIUGCCubeBillDialog()
{
}

// @0x140ee76e0
CString UIUGCCubeBillDialog::vfunc_1()
{
    return "UGCCubeBillDialog";
}

// @0x140ee7730
void UIUGCCubeBillDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    s_cost.Cost::Reset();
}

// MS2-FUNCTIONAL: written from the decompile; the child-name CString temporaries are bound through extra pointer slots (frame 0x388 against 0x378)
// @0x140ee7760
void UIUGCCubeBillDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    s_pending.PendingCost::Reset();
    CStringW strDesc;
    if (s_cost.m_bPreview != 0)
    {
        MS2Ptr<Unk_UcbButton> spBuy = FUN_140bb4b10("m_buy");
        if (spBuy.get() != 0)
            spBuy->FUN_1422cdfb0(CStringW(L"$s_common_confirm"));
        MS2Ptr<ASTextField> spTitle = FUN_140bb4cf0("m_title");
        if (spTitle.get() != 0)
            spTitle->FUN_1422c4cd0(CStringW(L"$s_ugc_cube_bill_title_calculate"));
        if (s_cost.m_nKind == 3)
            strDesc = FUN_140938ae0(CStringW(L"s_home_bill_description_blueprint_preview"), s_cost.m_nArg);
    }
    if (strDesc.IsEmpty())
        strDesc = FUN_140938ae0(CStringW(L"s_home_bill_description"), s_cost.m_nArg);
    MS2Ptr<ASTextField> spDesc = FUN_140bb4cf0("m_billDescription");
    if (spDesc.get() != 0)
        spDesc->FUN_1422c4f00(strDesc);
    ASObj obj(2);
    POSITION pos = s_cost.m_map.GetHeadPosition();
    while (pos != 0)
    {
        int nPayType = s_cost.m_map.GetKeyAt(pos);
        __int64 nAmount = s_cost.m_map.GetValueAt(pos);
        CStringW strAmount = FUN_1418fec00(nPayType, nAmount, 1);
        if (nPayType == 1)
        {
            obj.FUN_1407cbb20("meso", CStringW(strAmount));
        }
        else if (nPayType == 3)
        {
            obj.FUN_1407cbb20("bluemerat", CStringW(strAmount));
            bool bList = false;
            if (!FUN_140166410()->FUN_14036d710(0x61))
            {
                std::vector<std::pair<int, __int64> > vecRows;
                FUN_140930590(nAmount, vecRows);
                if (!vecRows.empty())
                {
                    if (vecRows.size() < 2)
                    {
                        if (!FUN_140930200(vecRows[0].first))
                            bList = true;
                    }
                    else
                        bList = true;
                }
                if (bList)
                {
                    ASArray arrMerats(2);
                    for (size_t i = 0; i < vecRows.size(); ++i)
                    {
                        ASObj objRow(2);
                        objRow.FUN_1407cbb20("name", FUN_1418fe5d0(vecRows[i].first));
                        objRow.FUN_1407cbb20("money", FUN_1418fec00(3, vecRows[i].second, 1));
                        arrMerats.FUN_1422bc050(objRow.FUN_1422bb870());
                    }
                    obj.FUN_140c16160("merats", ASArray(arrMerats));
                }
            }
        }
        else if (nPayType == 9)
        {
            obj.FUN_1407cbb20("redmerat", CStringW(strAmount));
        }
        s_cost.m_map.GetNext(pos);
    }
    m_30->FUN_140acd1f0("setData", AScript(obj));
}

// @0x140ee7f40
int UIUGCCubeBillDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    ASData data;
    if (_stricmp("OnBuy", szMethod) == 0)
    {
        FUN_140ee80a0();
        return 1;
    }
    return 0;
}

// @0x140ee8e20
int UIUGCCubeBillDialog::vfunc_48()
{
    return 0x4f29;
}

// ---- the message box answer, the packets and the purchase requests ----

// The pending item the bill is for (the answer of a message box).
// MS2-FUNCTIONAL: the empty-name temporary is bound through an extra pointer slot (frame 0x58 against 0x48)
// @0x140ee8610
void FUN_140ee8610(MS2Ptr<CItem> spItem)
{
    if (spItem == 0)
        return;
    int nResult = DAT_143ab2a90.FUN_140a63880(spItem.get(), CStringW(L""));
    if (nResult != 0)
    {
        FUN_1403ed2b0()->FUN_141adc690((eUIClassID)0x4f29);
        UIUGCCubeBillDialog::s_pending.PendingCost::Reset();
        UIUGCCubeBillDialog::s_pending.m_nBlueprintUid = spItem->FUN_140526a50();
        UIUGCCubeBillDialog::s_pending.m_nKind = 3;
    }
}

// @0x140ee8000
bool FUN_140ee8000(void* pUnused, int nAnswer, const CMsgBoxData& data)
{
    if (nAnswer == 0)
    {
        __int64 nItemUid = data.FUN_141a02c20();
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nItemUid);
        if (spItem.get() != 0)
            FUN_140ee8610(spItem);
    }
    return 1;
}

// @0x140ee80a0
void UIUGCCubeBillDialog::FUN_140ee80a0()
{
    if (s_cost.m_bPreview == 0)
    {
        if (s_cost.m_nKind == 1)
        {
            COutPacket packet(0x37, 0);
            packet.vfunc_o10_1(0x30);
            packet.vfunc_o10_3(s_cost.m_nCubeId);
            FUN_140710590(packet);
        }
        else if (s_cost.m_nKind == 3)
        {
            COutPacket packet(0x37, 0);
            packet.vfunc_o10_1(0x46);
            packet.vfunc_o10_4(s_cost.m_nBlueprintUid);
            FUN_140710590(packet);
        }
    }
    FUN_1403ed2b0()->FUN_141adc5d0((eUIClassID)0x4f29);
}

// The server's bill for a cube.
// @0x140ee8190
void FUN_140ee8190(CInPacket& packet)
{
    FUN_1403ed2b0()->FUN_141adc690((eUIClassID)0x4f29);
    UIUGCCubeBillDialog::s_cost.Cost::Reset();
    UIUGCCubeBillDialog::s_cost.PendingCost::Assign(UIUGCCubeBillDialog::s_pending);
    UIUGCCubeBillDialog::s_cost.m_nKind = 1;
    UIUGCCubeBillDialog::s_cost.m_map.RemoveAll();
    unsigned char nCount = packet.vfunc_o8_1();
    UIUGCCubeBillDialog::s_cost.m_nArg = packet.vfunc_o8_3();
    for (int i = 0; i < (int)nCount; ++i)
    {
        ePayType eType = (ePayType)packet.vfunc_o8_1();
        __int64 nAmount = packet.vfunc_o8_4();
        UIUGCCubeBillDialog::s_cost.m_map.SetAt(eType, nAmount);
    }
    FUN_1403ed2b0()->FUN_141adc5d0((eUIClassID)0x4f27);
    if (nCount > 0)
    {
        FUN_1403ed2b0()->OpenDialog((eUIClassID)0x4f29);
    }
    else
    {
        COutPacket out(0x37, 0);
        out.vfunc_o10_1(0x30);
        out.vfunc_o10_3(UIUGCCubeBillDialog::s_cost.m_nCubeId);
        FUN_140710590(out);
    }
}

// Ask the server for the bill of a cube.
// @0x140ee8360
void FUN_140ee8360(int nCubeId)
{
    FUN_1403ed2b0()->FUN_141adc690((eUIClassID)0x4f29);
    UIUGCCubeBillDialog::s_pending.PendingCost::Reset();
    UIUGCCubeBillDialog::s_pending.m_nKind = 1;
    UIUGCCubeBillDialog::s_pending.m_nCubeId = nCubeId;
    COutPacket packet(0x37, 0);
    packet.vfunc_o10_1(0x23);
    packet.vfunc_o10_3(nCubeId);
    FUN_140710590(packet);
}

// The server's bill for a blueprint.
// @0x140ee83f0
void FUN_140ee83f0(CInPacket& packet)
{
    FUN_1403ed2b0()->FUN_141adc690((eUIClassID)0x4f29);
    UIUGCCubeBillDialog::s_cost.Cost::Reset();
    UIUGCCubeBillDialog::s_cost.PendingCost::Assign(UIUGCCubeBillDialog::s_pending);
    UIUGCCubeBillDialog::s_cost.m_nKind = 3;
    UIUGCCubeBillDialog::s_cost.m_map.RemoveAll();
    unsigned char nCount = packet.vfunc_o8_1();
    UIUGCCubeBillDialog::s_cost.m_nArg = packet.vfunc_o8_3();
    for (int i = 0; i < (int)nCount; ++i)
    {
        ePayType eType = (ePayType)packet.vfunc_o8_1();
        __int64 nAmount = packet.vfunc_o8_4();
        UIUGCCubeBillDialog::s_cost.m_map.SetAt(eType, nAmount);
    }
    bool bPreview = packet.vfunc_o8_0();
    UIUGCCubeBillDialog::s_cost.m_bPreview = bPreview;
    FUN_1403ed2b0()->FUN_141adc5d0((eUIClassID)0x4f27);
    if (nCount > 0 || bPreview == 1)
    {
        FUN_1403ed2b0()->OpenDialog((eUIClassID)0x4f29);
    }
    else if (bPreview == 0)
    {
        COutPacket out(0x37, 0);
        out.vfunc_o10_1(0x46);
        out.vfunc_o10_4(UIUGCCubeBillDialog::s_cost.m_nBlueprintUid);
        FUN_140710590(out);
    }
}

// Ask the server for the bill of a blueprint.
// @0x140ee86f0
void FUN_140ee86f0(void* pBlueprintUid)
{
    FUN_1403ed2b0()->FUN_141adc690((eUIClassID)0x4f29);
    UIUGCCubeBillDialog::s_pending.PendingCost::Reset();
    COutPacket packet(0x37, 0);
    packet.vfunc_o10_1(0x42);
    packet.vfunc_o10_4(*(__int64*)pBlueprintUid);
    packet.vfunc_o10_0(true);
    FUN_140710590(packet);
}

// ---- PendingCost / Cost ----

// @0x140ee8900
UIUGCCubeBillDialog::PendingCost::PendingCost()
{
    PendingCost::Reset();
}

// @0x140ee89f0
UIUGCCubeBillDialog::PendingCost::~PendingCost()
{
}

// @0x140ee9890
void UIUGCCubeBillDialog::PendingCost::Reset()
{
    m_nKind = 0;
    m_nBlueprintUid = 0;
    m_nCubeId = 0;
}

// @0x140ee8ba0
void UIUGCCubeBillDialog::PendingCost::Assign(const PendingCost& o)
{
    *this = o;
}

// @0x140ee88a0
UIUGCCubeBillDialog::Cost::Cost()
    : m_map(10)
{
    Cost::Reset();
}

// @0x140ee9850
void UIUGCCubeBillDialog::Cost::Reset()
{
    PendingCost::Reset();
    m_bPreview = 0;
    m_nArg = 0;
    m_map.RemoveAll();
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca8810-0x142ca88a0 .text$yd
