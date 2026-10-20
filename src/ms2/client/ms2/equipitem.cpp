// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CEquipItem: one worn item of a PC and its models.
// MS2-UNIT: ?\equipitem.cpp
// MS2-RANGE: 0x1411dbc70-0x1411df580 .text$mn
// MS2-RANGE: 0x1400e8040-0x1400e81b0 .text$di
// MS2-RANGE: 0x142cacfa0-0x142cad030 .text$yd
// The queue row's ranges also cover the next TU (0x1411df590-0x1411ff4c0, .text$di 0x1400e81b0-0x1400e8680; the
// Equipment container, CEquipmentSlot, Equipment::SetEffectInfo): memcpy_s 0x1411df320 + memmove_s 0x1411df470 end
// this obj. That TU is ?\equipment.cpp (src/ms2/client/ms2/equipment.cpp).
// MS2-PIN: memcpy_s 0x1411df320
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\equipitem.cpp"
#include <vcruntime_string.h>
#pragma function(memcpy, memset)   // the TU-local memcpy_s calls memcpy/memset out of line
#include "ms2/placeholder/ms2stdafx.h"
#pragma intrinsic(memset, memcpy)
#include "equipitem.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/equipmodel.h"
#include "ms2/client/ms2/nifmodel.h"
#include "ms2/client/ms2/kfmmodel.h"
#include "ms2/client/ms2/itemugcmesh.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cugcmanager.h"
#include "ms2/placeholder/cgameoption.h"
#include "ms2/client/ms2/gameoptiongraphicdefault.h"
#include "ms2/commonfiles/ugcdef.h"
#include "ms2/commonfiles/itemdata.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Header statics every client obj of this group carries (see uiguideeventarrow.cpp).
static CString s_sortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_skill("skill");
static CString s_stun("stun");
static ATL::CAtlMap<unsigned int, CString> s_conditions(17, .75f, .25f, 2.25f, 10);

// CItem::FUN_140527840 returns the item's CItemData.
class Unk_ItemEquipData : public CItemData {};
struct Unk_EquipItemData : public Unk_ItemEquipData {};

// The non-virtual CEquipModel members this unit calls (defined in ?\equipmodel.cpp; equipmodel.h does not declare
// them). ModelPart is the model's <asset> record (CEquipModel::m_unk_20).
class Unk_EquipModelCalls : public CEquipModel
{
public:
    ModelPart* FUN_141200ab0();                                     // the <asset> record
    int FUN_141200bb0(const CString& strTag);                       // AddTag (1: changed)
    int FUN_141200c10(const CString& strTag);                       // RemoveTag (1: changed)
    int FUN_141200c50(const CString& strTag);                       // HasTag
    void FUN_141200230();                                           // ApplyPointEffect
    void FUN_141201180(const CString& strName);
    NiNodePtr FUN_141201bd0(const CString& strName);                // the node of that name
    int FUN_141202940();                                            // the model kind
    void FUN_141202dc0(int nSlot);                                  // RemoveEffect
};
#define MODEL(sp) static_cast<Unk_EquipModelCalls*>((sp).operator->())

CString FUN_1410280d0(int nKind, CString strName);                  // the local file of a ugc content kind

// @0x1411dbc70
CEquipItem::CEquipItem()
    : m_pPC(0), m_spItem(0), m_models(10), m_linkedItems(10), m_bUgcPending(0), m_bTagsDirty(0)
{
}

// @0x1411dbd50
CEquipItem::CEquipItem(PC* pPC, CItem* pItem)
    : m_pPC(pPC), m_spItem(pItem), m_models(10), m_linkedItems(10), m_bUgcPending(0), m_bTagsDirty(0)
{
}

// @0x1411dbe30
CEquipItem::~CEquipItem()
{
    FUN_1411dbfd0();
    if (!m_models.IsEmpty())
        FUN_1411dbf80(0);
    m_pPC = 0;
    m_spItem = 0;
    m_models.RemoveAll();
    m_linkedItems.RemoveAll();
    m_spUgcMeshes = 0;
}

// @0x1411dbf60
void CEquipItem::FUN_1411dbf60()
{
    FUN_1411dd150();
}
MS2_REPLACE_METHOD(0x1411DBF60, CEquipItem, FUN_1411dbf60, 24, 0x35F8000E);

// @0x1411dbf80
void CEquipItem::FUN_1411dbf80(int bKeepModels)
{
    if (bKeepModels != 0)
    {
        FUN_1411dbfd0();
    }
    else
    {
        FUN_1411dc560();
        m_pPC->FUN_1416561a0()->FUN_1411e0ba0();
    }
}
MS2_REPLACE_METHOD(0x1411DBF80, CEquipItem, FUN_1411dbf80, 69, 0x7DB620F3);

// @0x1411dbfd0
void CEquipItem::FUN_1411dbfd0()
{
    PC* pPC = FUN_1411dc8c0();
    if (pPC != 0)
    {
        pPC->FUN_1416561a0()->FUN_1411e3d20(m_linkedItems, 0);
        m_linkedItems.RemoveAll();
    }
}
MS2_REPLACE_METHOD(0x1411DBFD0, CEquipItem, FUN_1411dbfd0, 97, 0x58A50CD3);

// @0x1411dc040
void CEquipItem::FUN_1411dc040()
{
    POSITION pos = m_models.GetHeadPosition();
    while (pos != NULL)
    {
        MS2Ptr<CEquipModel>& spModel = m_models.GetNext(pos);
        if (spModel.get() != 0)
            spModel->vfunc_5();
    }
    m_models.RemoveAll();
}
MS2_REPLACE_METHOD(0x1411DC040, CEquipItem, FUN_1411dc040, 136, 0x9602397C);

// @0x1411dc0d0
int CEquipItem::FUN_1411dc0d0()
{
    for (POSITION pos = m_models.GetHeadPosition(); pos != NULL; m_models.GetNext(pos))
    {
        MS2Ptr<CEquipModel>& spModel = m_models.GetAt(pos);
        if (spModel.get() ? true : false)
        {
            if (spModel->vfunc_9() == 0)
                return 0;
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1411DC0D0, CEquipItem, FUN_1411dc0d0, 180, 0x9F56C642);

// @0x1411dc190
int CEquipItem::FUN_1411dc190(void* p)
{
    if (p)
    {
        FUN_1411dc210();
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1411DC190, CEquipItem, FUN_1411dc190, 46, 0xE7D895C2);

// @0x1411dc1d0
int CEquipItem::FUN_1411dc1d0(void* p)
{
    if (p)
    {
        FUN_1411dc210();
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1411DC1D0, CEquipItem, FUN_1411dc1d0, 46, 0x9F62F582);

// @0x1411dc210
void CEquipItem::FUN_1411dc210()
{
    if (FUN_1411dc0d0())
    {
        FUN_1411dd090();
        FUN_1411dd0f0();
        FUN_1411dd150();
        FUN_1411dd3b0();
        m_pPC->FUN_1416561a0()->FUN_1411e46b0(MS2Ptr<CEquipItem>(this));
        FUN_1411dd4a0(m_pPC->vfunc_65());
        if (FUN_1411dc7f0()->FUN_14053d2f0())
            m_pPC->FUN_141659000(1);
        FUN_1411dd9a0();
        float fBlend = 1.0f;
        if (m_pPC->FUN_14166c930() == 0x2f)
            fBlend = m_pPC->FUN_14165eb80();
        FUN_1411dd520(m_pPC->FUN_141658d20(), m_pPC->vfunc_60(), m_pPC->FUN_14166e0d0(), fBlend, false);
    }
    else
    {
        if ((m_spItem.get() ? true : false) && m_spItem->FUN_140525f10() && m_spItem->FUN_140525f60() && FUN_1411ddcb0() == 1)
            m_bUgcPending = 1;
    }
    FUN_1411de030();
}
MS2_REPLACE_METHOD(0x1411DC210, CEquipItem, FUN_1411dc210, 742, 0x8BA7AED8);

// @0x1411dc500
int CEquipItem::FUN_1411dc500(void* p)
{
    if (p)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x1411DC500, CEquipItem, FUN_1411dc500, 28, 0xF02671A3);

// @0x1411dc530
void CEquipItem::FUN_1411dc530(void* p)
{
    FUN_1411dc1d0(p);
}
MS2_REPLACE_METHOD(0x1411DC530, CEquipItem, FUN_1411dc530, 34, 0x2E3016A5);

// @0x1411dc560
int CEquipItem::FUN_1411dc560()
{
    POSITION pos = m_models.GetHeadPosition();
    while (pos != NULL)
    {
        MS2Ptr<CEquipModel>& spModel = m_models.GetNext(pos);
        if (spModel.get() != 0)
            spModel->vfunc_7();
    }
    m_models.RemoveAll();
    FUN_1411dd0f0();
    FUN_1411dd150();
    m_pPC->FUN_1416561a0()->FUN_1411e4b30(MS2Ptr<CEquipItem>(this));
    return 1;
}
MS2_REPLACE_METHOD(0x1411DC560, CEquipItem, FUN_1411dc560, 259, 0xED376193);

// @0x1411dc670
int CEquipItem::FUN_1411dc670()
{
    for (POSITION pos = m_models.GetHeadPosition(); pos != NULL; m_models.GetNext(pos))
    {
        MS2Ptr<CEquipModel>& spModel = m_models.GetAt(pos);
        if (spModel->vfunc_20())
            return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1411DC670, CEquipItem, FUN_1411dc670, 144, 0x8C4F8E43);

// @0x1411dc710
int CEquipItem::FUN_1411dc710()
{
    for (POSITION pos = m_models.GetHeadPosition(); pos != NULL; m_models.GetNext(pos))
    {
        if (MODEL(m_models.GetAt(pos))->FUN_141200ab0()->earfold == 1)
            return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1411DC710, CEquipItem, FUN_1411dc710, 123, 0xED7EE5A7);

// @0x1411dc7a0
MS2Ptr<CItem> CEquipItem::FUN_1411dc7a0()
{
    return m_spItem;
}
MS2_REPLACE_METHOD(0x1411DC7A0, CEquipItem, FUN_1411dc7a0, 65, 0xE76D92EE);

// @0x1411dc7f0
Unk_EquipItemData* CEquipItem::FUN_1411dc7f0()
{
    return static_cast<Unk_EquipItemData*>(m_spItem->FUN_140527840());
}
MS2_REPLACE_METHOD(0x1411DC7F0, CEquipItem, FUN_1411dc7f0, 39, 0x136456ED);

// @0x1411dc820
int CEquipItem::FUN_1411dc820()
{
    if (m_spItem.get() != 0)
        return m_spItem->FUN_1405276c0();
    return 0;
}
MS2_REPLACE_METHOD(0x1411DC820, CEquipItem, FUN_1411dc820, 65, 0xC3F937C3);

// @0x1411dc870
__int64 CEquipItem::FUN_1411dc870()
{
    if (m_spItem.get() != 0)
        return m_spItem->FUN_140526a50();
    return 0;
}
MS2_REPLACE_METHOD(0x1411DC870, CEquipItem, FUN_1411dc870, 65, 0xC9EF30FC);

// @0x1411dc8c0
PC* CEquipItem::FUN_1411dc8c0()
{
    return m_pPC;
}
MS2_REPLACE_METHOD(0x1411DC8C0, CEquipItem, FUN_1411dc8c0, 15, 0xBBB219C9);

// @0x1411dc8e0
void CEquipItem::FUN_1411dc8e0(PC* pPC)
{
    m_pPC = pPC;
}
MS2_REPLACE_METHOD(0x1411DC8E0, CEquipItem, FUN_1411dc8e0, 25, 0xAB8BF0FB);

// @0x1411dc900
void CEquipItem::FUN_1411dc900(int bPending)
{
    if (!m_spItem->FUN_140525f10())
        return;
    m_bUgcPending = bPending;
}
MS2_REPLACE_METHOD(0x1411DC900, CEquipItem, FUN_1411dc900, 64, 0xFECDAB85);

// @0x1411dc950
MS2Ptr<CEquipModel> CEquipItem::FUN_1411dc950(const CString& strName)
{
    for (POSITION pos = m_models.GetHeadPosition(); pos != NULL; m_models.GetNext(pos))
    {
        MS2Ptr<CEquipModel>& spModel = m_models.GetAt(pos);
        if (MODEL(spModel)->FUN_141200ab0()->name0 == strName)
            return spModel;
    }
    return MS2Ptr<CEquipModel>(0);
}
MS2_REPLACE_METHOD(0x1411DC950, CEquipItem, FUN_1411dc950, 217, 0x8D8D2155);

// @0x1411dca30
void CEquipItem::FUN_1411dca30(int nKind, ATL::CAtlArray<CString>& aOut)
{
    for (POSITION pos = m_models.GetHeadPosition(); pos != NULL; m_models.GetNext(pos))
    {
        MS2Ptr<CEquipModel>& spModel = m_models.GetAt(pos);
        if (MODEL(spModel)->FUN_141202940() == nKind)
            aOut.Add(MODEL(spModel)->FUN_141200ab0()->name0);
    }
}
MS2_REPLACE_METHOD(0x1411DCA30, CEquipItem, FUN_1411dca30, 161, 0x0761C1C2);

// @0x1411dcae0
void CEquipItem::FUN_1411dcae0(ATL::CAtlArray<MS2Ptr<CNifModel> >* pOut)
{
    for (POSITION pos = m_models.GetHeadPosition(); pos != NULL; m_models.GetNext(pos))
    {
        MS2Ptr<CEquipModel>& spModel = m_models.GetAt(pos);
        CNifModel* pNif = efd::DynamicCast<CNifModel>((CEquipModel*)spModel);
        if (pNif != 0)
        {
            MS2Ptr<CNifModel> spNif(pNif);
            pOut->Add(spNif);
        }
    }
}
MS2_REPLACE_METHOD(0x1411DCAE0, CEquipItem, FUN_1411dcae0, 187, 0xBE672FA9);

// @0x1411dcbb0
void CEquipItem::FUN_1411dcbb0(ATL::CAtlArray<MS2Ptr<CKfmModel> >* pOut)
{
    for (POSITION pos = m_models.GetHeadPosition(); pos != NULL; m_models.GetNext(pos))
    {
        MS2Ptr<CEquipModel>& spModel = m_models.GetAt(pos);
        CKfmModel* pKfm = efd::DynamicCast<CKfmModel>((CEquipModel*)spModel);
        if (pKfm != 0)
        {
            MS2Ptr<CKfmModel> spKfm(pKfm);
            pOut->Add(spKfm);
        }
    }
}
MS2_REPLACE_METHOD(0x1411DCBB0, CEquipItem, FUN_1411dcbb0, 187, 0x9BFF8DF1);

// @0x1411dcc80
void CEquipItem::FUN_1411dcc80(ATL::CAtlArray<MS2Ptr<CEquipModel> >& aOut)
{
    for (POSITION pos = m_models.GetHeadPosition(); pos != NULL; m_models.GetNext(pos))
    {
        MS2Ptr<CEquipModel>& spModel = m_models.GetAt(pos);
        aOut.Add(spModel);
    }
}
MS2_REPLACE_METHOD(0x1411DCC80, CEquipItem, FUN_1411dcc80, 117, 0xBD220E42);

// @0x1411dcd00
void CEquipItem::FUN_1411dcd00()
{
    for (POSITION pos = m_models.GetHeadPosition(); pos != NULL; m_models.GetNext(pos))
    {
        MS2Ptr<CEquipModel>& spModel = m_models.GetAt(pos);
        if (spModel.get() != 0)
            spModel->vfunc_11();
    }
}
MS2_REPLACE_METHOD(0x1411DCD00, CEquipItem, FUN_1411dcd00, 143, 0x157D1688);

// @0x1411dcda0
int CEquipItem::FUN_1411dcda0()
{
    for (POSITION pos = m_models.GetHeadPosition(); pos != NULL; m_models.GetNext(pos))
    {
        MS2Ptr<CEquipModel>& spModel = m_models.GetAt(pos);
        if (spModel.get() ? true : false)
        {
            if (spModel->vfunc_15() != 0)
                return 1;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1411DCDA0, CEquipItem, FUN_1411dcda0, 180, 0x6477AD8D);

// @0x1411dce60
int CEquipItem::FUN_1411dce60(const CString& strTag)
{
    int bChanged = 0;
    for (POSITION pos = m_models.GetHeadPosition(); pos != NULL; m_models.GetNext(pos))
    {
        MS2Ptr<CEquipModel>& spModel = m_models.GetAt(pos);
        if (MODEL(spModel)->FUN_141200bb0(strTag))
        {
            m_bTagsDirty = 1;
            bChanged = 1;
        }
    }
    return bChanged;
}
MS2_REPLACE_METHOD(0x1411DCE60, CEquipItem, FUN_1411dce60, 164, 0x5DAB8B19);

// @0x1411dcf10
int CEquipItem::FUN_1411dcf10(const CString& strTag)
{
    int bChanged = 0;
    for (POSITION pos = m_models.GetHeadPosition(); pos != NULL; m_models.GetNext(pos))
    {
        MS2Ptr<CEquipModel>& spModel = m_models.GetAt(pos);
        if (MODEL(spModel)->FUN_141200c10(strTag))
        {
            m_bTagsDirty = 1;
            bChanged = 1;
        }
    }
    return bChanged;
}
MS2_REPLACE_METHOD(0x1411DCF10, CEquipItem, FUN_1411dcf10, 164, 0x3E1490C9);

// @0x1411dcfc0
int CEquipItem::FUN_1411dcfc0(const CString& strTag)
{
    if (m_models.IsEmpty())
        return 0;
    MS2Ptr<CEquipModel> spModel = m_models.GetAt(m_models.GetHeadPosition());
    if (spModel == 0)
        return 0;
    return MODEL(spModel)->FUN_141200c50(strTag);
}
MS2_REPLACE_METHOD(0x1411DCFC0, CEquipItem, FUN_1411dcfc0, 191, 0xC7A3714C);

// @0x1411dd090
void CEquipItem::FUN_1411dd090()
{
    if (FUN_1411dc7f0()->FUN_14053c620() == 0xd || FUN_1411dc7f0()->FUN_14053cfd0())
        m_pPC->FUN_1416561a0()->FUN_1411e5c10();
}
MS2_REPLACE_METHOD(0x1411DD090, CEquipItem, FUN_1411dd090, 84, 0x5F4E7D1F);

// @0x1411dd0f0
void CEquipItem::FUN_1411dd0f0()
{
    if (FUN_1411dc7f0()->FUN_14053c620() == 0xd || FUN_1411dc7f0()->FUN_14053cfd0())
        m_pPC->FUN_1416561a0()->FUN_1411e6ab0();
}
MS2_REPLACE_METHOD(0x1411DD0F0, CEquipItem, FUN_1411dd0f0, 84, 0xD926319C);

// @0x1411dd150
void CEquipItem::FUN_1411dd150()
{
    if (FUN_1411dc7f0()->FUN_14053d070() || FUN_1411dc7f0()->FUN_14053d020())
    {
        m_pPC->FUN_141656780();
        m_pPC->FUN_14166f380();
    }
}
MS2_REPLACE_METHOD(0x1411DD150, CEquipItem, FUN_1411dd150, 92, 0x83A3F36C);

// @0x1411dd1c0
void CEquipItem::FUN_1411dd1c0()
{
    for (POSITION pos = m_models.GetHeadPosition(); pos != NULL; m_models.GetNext(pos))
    {
        MS2Ptr<CEquipModel>& spModel = m_models.GetAt(pos);
        if (spModel.get() != 0)
            spModel->vfunc_16();
    }
    FUN_1411dd090();
    FUN_1411dd0f0();
    FUN_1411dd150();
    FUN_1411dcd00();
}
MS2_REPLACE_METHOD(0x1411DD1C0, CEquipItem, FUN_1411dd1c0, 186, 0x48591C55);

// @0x1411dd280
void CEquipItem::FUN_1411dd280()
{
    for (POSITION pos = m_models.GetHeadPosition(); pos != NULL; m_models.GetNext(pos))
    {
        MS2Ptr<CEquipModel>& spModel = m_models.GetAt(pos);
        spModel->vfunc_17();
    }
    if (static_cast<CItemData*>(m_spItem->FUN_140527840())->FUN_14053d2f0())
    {
        if (TSingleton<CGameOption>::GetInstance()->FUN_1409a8ac0()->m_bEnchantEffect)
        {
            for (POSITION posEffect = m_models.GetHeadPosition(); posEffect != NULL; m_models.GetNext(posEffect))
            {
                MS2Ptr<CEquipModel>& spEffect = m_models.GetAt(posEffect);
                MODEL(spEffect)->FUN_141200230();
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1411DD280, CEquipItem, FUN_1411dd280, 293, 0x8597AC58);

// @0x1411dd3b0
void CEquipItem::FUN_1411dd3b0()
{
    if (FUN_1411dc7f0()->FUN_14053c620() == 0x12)
        m_pPC->FUN_1416561a0()->FUN_1411e7380();
}
MS2_REPLACE_METHOD(0x1411DD3B0, CEquipItem, FUN_1411dd3b0, 59, 0xFC5D8593);

// @0x1411dd400
void CEquipItem::FUN_1411dd400(double fTime)
{
    if (m_bUgcPending != 0)
    {
        if (FUN_1411dc0d0() && FUN_1411ddcb0() == 1)
        {
            FUN_1411ddae0();
            m_bUgcPending = 0;
        }
    }
    if (m_bTagsDirty != 0)
    {
        FUN_1411dd0f0();
        m_bTagsDirty = 0;
    }
    FUN_1411ddfb0(fTime);
}
MS2_REPLACE_METHOD(0x1411DD400, CEquipItem, FUN_1411dd400, 143, 0x0FFE1A27);

// @0x1411dd4a0
void CEquipItem::FUN_1411dd4a0(int n)
{
    POSITION pos = m_models.GetHeadPosition();
    while (pos != NULL)
    {
        MS2Ptr<CEquipModel>& spModel = m_models.GetNext(pos);
        spModel->vfunc_32(n);
    }
}
MS2_REPLACE_METHOD(0x1411DD4A0, CEquipItem, FUN_1411dd4a0, 115, 0x34A15B68);

// @0x1411dd520
void CEquipItem::FUN_1411dd520(const CString& strA, const CString& strB, const efd::utf8string& kDefault, float fBlend,
    bool b)
{
    for (POSITION pos = m_models.GetHeadPosition(); pos != NULL; m_models.GetNext(pos))
    {
        CKfmModel* pKfm = efd::DynamicCast<CKfmModel>(m_models.GetAt(pos).get());
        if (pKfm != 0)
            pKfm->FUN_141440380(strA, strB, kDefault, fBlend, b);
    }
}
MS2_REPLACE_METHOD(0x1411DD520, CEquipItem, FUN_1411dd520, 185, 0xE9AD54D5);

// @0x1411dd5e0
void CEquipItem::FUN_1411dd5e0(const CString& strName)
{
    POSITION pos = m_models.GetHeadPosition();
    while (pos != NULL)
    {
        MS2Ptr<CEquipModel>& spModel = m_models.GetNext(pos);
        MODEL(spModel)->FUN_141201180(strName);
    }
}
MS2_REPLACE_METHOD(0x1411DD5E0, CEquipItem, FUN_1411dd5e0, 101, 0x7B61FF3C);

// @0x1411dd650
void CEquipItem::FUN_1411dd650()
{
    for (POSITION pos = m_models.GetHeadPosition(); pos != NULL; m_models.GetNext(pos))
    {
        MS2Ptr<CEquipModel>& spModel = m_models.GetAt(pos);
        MODEL(spModel)->FUN_141202dc0(2);
    }
}
MS2_REPLACE_METHOD(0x1411DD650, CEquipItem, FUN_1411dd650, 120, 0xAA779C63);

// @0x1411dd6d0
void CEquipItem::FUN_1411dd6d0(CItem* pItem)
{
    m_spItem.AssignRaw(pItem);
}
MS2_REPLACE_METHOD(0x1411DD6D0, CEquipItem, FUN_1411dd6d0, 41, 0xE71DC818);

// @0x1411dd700
NiNodePtr CEquipItem::FUN_1411dd700()
{
    for (POSITION pos = m_models.GetHeadPosition(); pos != NULL; m_models.GetNext(pos))
    {
        MS2Ptr<CEquipModel>& spModel = m_models.GetAt(pos);
        NiNodePtr spNode = MODEL(spModel)->FUN_141201bd0("Point01");
        if (spNode)
            return spNode;
    }
    return NiNodePtr(0);
}
MS2_REPLACE_METHOD(0x1411DD700, CEquipItem, FUN_1411dd700, 281, 0x1E098B50);

// @0x1411dd820
NiTexturePtr CEquipItem::FUN_1411dd820()
{
    return m_spUgcMeshes.get() ? m_spUgcMeshes->FUN_141426d40() : NiTexturePtr(0);
}
MS2_REPLACE_METHOD(0x1411DD820, CEquipItem, FUN_1411dd820, 284, 0xE0250037);

// @0x1411dd950
MS2Ptr<CItemUgcMeshContainer> CEquipItem::FUN_1411dd950()
{
    return m_spUgcMeshes;
}
MS2_REPLACE_METHOD(0x1411DD950, CEquipItem, FUN_1411dd950, 67, 0x8A622E97);

// @0x1411dd9a0
void CEquipItem::FUN_1411dd9a0()
{
    if (m_bUgcPending != 0)
        return;
    if (m_spItem == 0)
        return;
    if (m_spItem->FUN_140525f10() && m_spItem->FUN_140525f60())
    {
        if (TSingleton<CUgcManager>::GetInstance()->FUN_14188aa20(m_spItem->FUN_1405278d0()->m_strName) == 0)
            TSingleton<CUgcManager>::GetInstance()->FUN_141884300(m_spItem, m_pPC->FUN_14123c580());
        FUN_1411dc900(1);
    }
}
MS2_REPLACE_METHOD(0x1411DD9A0, CEquipItem, FUN_1411dd9a0, 304, 0x466982C4);

// @0x1411ddae0
void CEquipItem::FUN_1411ddae0()
{
    if (!m_spItem->FUN_140525f10())
        return;
    if (!m_spItem->FUN_140525f60())
        return;
    CString strFile = FUN_1411ddd50();
    if (TSingleton<CUgcManager>::GetInstance()->FUN_14188aa20(m_spItem->FUN_1405278d0()->m_strName) == 0)
        return;
    CUgcItemPC kItem(m_spItem.get(), m_pPC->FUN_14123c580());
    if (TSingleton<CUgcManager>::GetInstance()->FUN_141886980(&kItem, strFile) == 0)
        TSingleton<CUgcManager>::GetInstance()->FUN_141884300(m_spItem, m_pPC->FUN_14123c580());
}
MS2_REPLACE_METHOD(0x1411DDAE0, CEquipItem, FUN_1411ddae0, 457, 0xDC1D7EF2);

// @0x1411ddcb0
int CEquipItem::FUN_1411ddcb0()
{
    if (!m_spItem->FUN_140525f10())
        return 1;
    if (!m_spItem->FUN_140525f60())
        return 1;
    return TSingleton<CUgcManager>::GetInstance()->FUN_14188aa20(m_spItem->FUN_1405278d0()->m_strName);
}
MS2_REPLACE_METHOD(0x1411DDCB0, CEquipItem, FUN_1411ddcb0, 141, 0x1EE2CF38);

// @0x1411ddd50
CString CEquipItem::FUN_1411ddd50()
{
    if (m_strUgcFile.IsEmpty())
        m_strUgcFile = FUN_1410280d0(1, m_spItem->FUN_1405278d0()->m_strName);
    return m_strUgcFile;
}
MS2_REPLACE_METHOD(0x1411DDD50, CEquipItem, FUN_1411ddd50, 238, 0xBAD18CBE);

// @0x1411dde50
void CEquipItem::FUN_1411dde50(CEquipModel* pModel)
{
    for (POSITION pos = m_models.GetHeadPosition(); pos != NULL; m_models.GetNext(pos))
    {
        MS2Ptr<CEquipModel>& spModel = m_models.GetAt(pos);
        if (spModel == pModel)
            return;
    }
    MS2Ptr<CEquipModel> spNew(pModel);
    m_models.AddTail(spNew);
}
MS2_REPLACE_METHOD(0x1411DDE50, CEquipItem, FUN_1411dde50, 184, 0x073EED80);

// @0x1411ddf10
void CEquipItem::FUN_1411ddf10(CEquipModel* pModel)
{
    for (POSITION pos = m_models.GetHeadPosition(); pos != NULL; m_models.GetNext(pos))
    {
        MS2Ptr<CEquipModel>& spModel = m_models.GetAt(pos);
        if (spModel == pModel)
        {
            m_models.RemoveAt(pos);
            return;
        }
    }
}
MS2_REPLACE_METHOD(0x1411DDF10, CEquipItem, FUN_1411ddf10, 148, 0x00BF91C6);

// @0x1411ddfb0
void CEquipItem::FUN_1411ddfb0(double fTime)
{
    POSITION pos = m_models.GetHeadPosition();
    while (pos != NULL)
    {
        MS2Ptr<CEquipModel>& spModel = m_models.GetNext(pos);
        spModel->vfunc_19(fTime);
    }
}
MS2_REPLACE_METHOD(0x1411DDFB0, CEquipItem, FUN_1411ddfb0, 119, 0x2B011AFF);

// @0x1411de030
void CEquipItem::FUN_1411de030()
{
    if (m_spUgcMeshes.get() != 0)
        return;
    if ((m_spItem.get() ? true : false) && m_spItem->FUN_140525f10())
    {
        m_spUgcMeshes.AssignRaw(new CItemUgcMeshContainer());
        m_spUgcMeshes->FUN_141426170(MS2Ptr<CEquipItem>(this));
    }
}
MS2_REPLACE_METHOD(0x1411DE030, CEquipItem, FUN_1411de030, 306, 0xA17A0E80);

// The UCRT's `static __inline memcpy_s` of this TU (kept alive by the pointer below), then its memmove_s.
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnMemcpyS)(void*, size_t, const void*, size_t) = &memcpy_s;
MS2_EMIT_CRT_MEMMOVE_S();
