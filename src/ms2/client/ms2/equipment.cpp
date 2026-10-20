// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CEquipment: the slots a PC wears its items in.
// MS2-UNIT: ?\equipment.cpp
// MS2-RANGE: 0x1411df590-0x1411ff420 .text$mn
// MS2-RANGE: 0x1400e81b0-0x1400e8680 .text$di
// MS2-RANGE: 0x142cad030-0x142cad300 .text$yd
// The queue row ?\equipitem.cpp also covers this TU (equipitem.cpp holds 0x1411dbc70-0x1411df580).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\equipment.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "equipment.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/equipitem.h"
#include "ms2/client/ms2/itemloadinfo.h"
#include "ms2/placeholder/notifychangeactivemycoditab.h"
#include "ms2/placeholder/cequipmentslotlayerinfo.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/citemservice.h"
#include "ms2/placeholder/csetitemmanager.h"
#include "ms2/placeholder/coptimizer.h"
#include "ms2/placeholder/bitset.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/effectquery.h"
#include "ms2/placeholder/setitemtable.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/invokeeffectoption.h"
#include "ms2/placeholder/notifychange.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/commonfiles/gamerule.h"
#include "ms2/commonfiles/timeutil.h"
#include "ms2/client/ms2/equipmodel.h"
#include "ms2/commonfiles/itemdata.h"
#include "ms2/commonfiles/item.h"
#include "ms2/placeholder/tcreatecharinfo.h"
#include "ms2/client/ms2/gameobject.h"
#include "ms2/client/ms2/effectservice.h"
#include <NiNode.h>
#include <NiMesh.h>
#include <set>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The mesh name suffixes the ctor fills once.
static ATL::CAtlList<CString> s_meshSuffixes(10);

// Equip item tags.
static CString s_tagCap("Cap");
static CString s_tagCustomize("Customize");
static CString s_tagDefault("Default");
static CString s_tagEmotion("Emotion");
static CString s_tagExceptRender("ExceptRender");
static CString s_tagExpired("Expired");
static CString s_tagHair("Hair");
static CString s_tagInvalide("Invalide");
static CString s_tagLayerExpired("layerExpired");
static CString s_tagLower("Lower");
static CString s_tagMissMatch("MissMatch");
static CString s_tagOptimizer("Optimizer");
static CString s_tagPCBang("PCBang");
static CString s_tagSlot("Slot");
static CString s_tagUndo("Undo");
static CString s_tagVIP("VIP");
static CString s_tagWillUpdatePos("WillUpdatePos");

// Header statics every client obj of this group carries (see uiguideeventarrow.cpp).
static CString s_sortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_skill("skill");
static CString s_stun("stun");
static ATL::CAtlMap<unsigned int, CString> s_conditions(17, .75f, .25f, 2.25f, 10);

// PCBase::FUN_1416749a0 returns the actor's AdditionalCliList (pcbase.h's opaque view).
class Unk_PCBaseBuffs : public AdditionalCliList {};
// CItem::FUN_140527840 / CEquipItem::FUN_1411dc7f0 return the item's CItemData.
class Unk_ItemEquipData : public CItemData
{
public:
    ItemModelHead* FUN_14053ec70();                 // the model head record
};
struct Unk_EquipItemData : public Unk_ItemEquipData {};

CFeatureManager* FUN_140166410();
COptimizer* FUN_1409f7c90();
CGameRule* FUN_1401c0d90();
int FUN_14081d8a0(int nType);                       // a skill stat option type
int FUN_14081d8e0(int nType);                       // an effect stat option type
float FUN_14028d3a0(float f);                       // f / 100
int FUN_14028d260(float fSeconds);                  // seconds -> ms
int FUN_141421690(CItem* pItem);                    // the item kind
bool FUN_14087ddc0(const efd::ClassInfo* pInfo, unsigned int nId);   // is of the class id
bool FUN_14028d470(float a, float b);               // a == b (epsilon)
CString FUN_14021c050(int nSlot);                   // the slot name
void FUN_141653f00(PC* pPC);                        // refresh the PC's look
void FUN_1411a6060(CEffectService* pService, unsigned nEffect);   // remove an effect
std::set<NiAVObjectPtr>* FUN_141201c90(CEquipModel* pModel);      // the model's root nodes
NiNode* FUN_140a0b000(NiAVObject* pObj);            // the parent node
void FUN_140a0b300(NiAVObject* pObj, bool bCulled); // app culled
egf::Entity* FUN_14123c410(GameObject* pObject);    // the object's entity
NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);    // the entity's scene graph
NiAVObject* FUN_141b6ef70(egf::EntityID id);        // the scene node of an entity
bool FUN_14116e080(NiAVObject* pObject);            // the skin decal is set up
void FUN_14116e3f0(NiMesh* pMesh, float fA, float fB, float fC, float fD, bool bFlag, const CString& strTexture,
    const Unk_CharEquip& kColor0, const Unk_CharEquip& kColor1, const Unk_CharEquip& kColor2);   // apply the skin decal
Unk_CharEquip FUN_141b6dea0(unsigned nColor);       // a colour value
int FUN_140ddcc90(COptimizer* pOptimizer);          // mesh merging is on
// The world service (WorldService) as the equipment uses it.
struct Unk_EqWorld
{
    PCBase* FUN_141bd3620();                        // the local player
    int FUN_141bd1a10(GameObject* pObject);         // the object's actor id
};
Unk_EqWorld* FUN_1403ed2d0();
PCBase* FUN_141bd0cc0(Unk_EqWorld* pWorld);         // the local player
CString FUN_1414253b0(const CString& str, int n);
// NoticeMessage::SetCallback with the callback typed as the 3-argument delegate it is.
class Unk_EqNotice : public NoticeMessage
{
public:
    void FUN_140a531f0(Delegate<void(unsigned, CString, bool)> callback);
};
unsigned FUN_1411a49c0(CEffectService* pService, NoticeMessage& msg);   // spawn the effect
int FUN_141420a30(int nType, CItem* pItem, PC* pPC);    // the slot a model group of the item takes off
int FUN_141420990(int nType, CItem* pItem, PC* pPC);    // the slot a model group of the item goes on
void FUN_140a0b2a0(NiAVObject* pObj);                   // detach from the parent
void FUN_1412751b0(const CStringW& strMessage, int nColor);   // the debug chat line
extern int DAT_143ae2b58;                               // the optimizer debug level

// @0x1411f0ad0 (the unit's three-argument log call: an FMT_VARIADIC wrapper over CLogString::FUN_1406530d0).
template <class A, class B, class C>
inline void Unk_EquipLog(CLogString* log, int level, int category, const wchar_t* format, const A& a, const B& b,
    const C& c)
{
    const fmt::internal::ArgArray<3>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(a),
        fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(b), fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(c)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(a, b, c), args));
}
// CItem::FUN_140527870's record as the skin decal reads it (the decal values at +0x58..+0x67).
class Unk_EquipSkinRecord : public Unk_UserProxyItemData
{
public:
    int FUN_140599fd0(int nIndex);                  // a decal colour
    char m_pad_18[0x40];
    float m_f58;                                    // +0x58
    float m_f5c;                                    // +0x5c
    float m_f60;                                    // +0x60
    float m_f64;                                    // +0x64
};

class Unk_EquipModelCalls : public CEquipModel
{
public:
    ModelPart* FUN_141200ab0();                                     // the <asset> record
};
#define MODEL(sp) static_cast<Unk_EquipModelCalls*>((sp).operator->())

void FUN_1411ff420(unsigned char* pBits, unsigned char nValue);    // fill (unit_1411ff420)

// The 6-layer bit set of 0x1411e3000 (commonfiles\bitset.inl, T = 6; bitset.h's Unk_Bitset has no ctor / reference).
class Unk_LayerBits
{
public:
    class reference
    {
    public:
        reference(Unk_LayerBits& bits, int pos) : m_pBits(&bits), m_nPos(pos) {}
        operator bool() const { return m_pBits->Test(m_nPos); }
        Unk_LayerBits* m_pBits;
        int m_nPos;
    };
    Unk_LayerBits() { FUN_1411ff420(m_bits, 0); }
    Unk_LayerBits& Set(int pos, bool value)
    {
        if (UINT(pos) >= UINT(6)) { MS2_BITSET_ASSERT(243, 0); }
        if (value) m_bits[pos / 8] |= 1 << (pos % 8);
        else m_bits[pos / 8] &= ~(1 << (pos % 8));
        return *this;
    }
    reference operator[](int pos) { return reference(*this, pos); }
    bool Test(int pos) const
    {
        if (UINT(pos) >= UINT(6)) { MS2_BITSET_ASSERT(404, 0); return false; }
        return (m_bits[pos / 8] & (1 << (pos % 8))) != 0;
    }
    unsigned char m_bits[1];
};

// @0x1411df590
CEquipmentSlot::CEquipmentSlot()
{
    m_nIndex = 0;
    m_items.resize(6, MS2Ptr<CEquipItem>(0));
    m_bShown.resize(6, 0);
}

// @0x1411df670
CEquipmentSlot::~CEquipmentSlot()
{
    m_replaced.RemoveAll();
    m_items.clear();
}

// @0x1411df700
bool CEquipmentSlotLayerInfo::FUN_1411df700()
{
    if (FUN_1411df7d0() == true) {
        if (m_start == CMsTime(0))
            return true;
        if (m_end > CMsTime(0))
            return GetServerTime() >= m_end.Get();
        return false;
    }
    return false;
}

// @0x1411df7d0
bool CEquipmentSlotLayerInfo::FUN_1411df7d0()
{
    if (m_nKind == 2 && FUN_140166410()->FUN_14036d570(0x8e) == true)
        return true;
    return false;
}

// @0x1411df810
bool CEquipmentSlotLayerInfo::FUN_1411df810()
{
    return m_bActive;
}

// @0x1411df830
int CEquipmentSlotLayerInfo::FUN_1411df830()
{
    if (!FUN_1411df7d0())
        return 0;
    if (m_start == CMsTime(0))
        return 4;
    if (m_end == CMsTime(0))
        return 2;
    if (FUN_1411df700() == true)
        return 3;
    return 1;
}

// @0x1411df910
unsigned char CEquipmentSlotLayerInfo::FUN_1411df910()
{
    if (!m_bBusy && (m_48 == 0 || m_timer.Check(m_48) == 0)) {
        unsigned last = m_timer.GetLast();
        unsigned now = GetTickCountMs2();
        if (now <= last || now - last <= 60000)
            return false;
        m_bBusy = true;
        m_timer.Check(0);
    }
    bool bActive = !FUN_1411df700();
    unsigned char bChanged = bActive != m_bActive;
    m_bActive = bActive;
    m_3c = FUN_1411df830();
    int nInterval;
    if (m_3c == 1) {
        CMsTime now(GetServerTime());
        if (now < m_end) {
            ATL::CTimeSpan left = m_end - now;
            int nDays = (int)left.GetDays();
            LONG nHours = left.GetHours();
            LONG nMinutes = left.GetMinutes();
            LONG nSeconds = left.GetSeconds();
            if (nDays > 0) {
                if (nHours == 0 && nMinutes == 0)
                    nInterval = FUN_14028d260((float)nSeconds);
                else
                    nInterval = nHours > 0 ? FUN_14028d260((float)HoursToSeconds(nHours))
                                           : FUN_14028d260((float)MinutesToSeconds(nMinutes));
            } else if (nHours > 0) {
                nInterval = nMinutes > 0 ? FUN_14028d260((float)MinutesToSeconds(nMinutes))
                                         : FUN_14028d260((float)nSeconds);
            } else {
                nInterval = FUN_14028d260((float)nSeconds);
            }
            if (nInterval == 0)
                nInterval = 1000;
        }
    }
    m_48 = nInterval;
    m_bBusy = false;
    return bChanged;
}

// @0x1411dfbf0
void CEquipmentSlotLayerInfo::FUN_1411dfbf0(bool bDirty)
{
    m_bBusy = true;
}

// @0x1411dfc10
bool CEquipmentSlotLayerInfo::FUN_1411dfc10(const CMsTime& kStart, const CMsTime& kEnd)
{
    m_start = kStart;
    m_end = kEnd;
    FUN_1411dfbf0(true);
    FUN_1411df910();
    return true;
}

// @0x1411dfc80
Equipment::SetEffectInfo::SetEffectInfo()
{
    m_nEffect = 0;
    m_nGroup = 0;
}

// @0x1411dfcf0
bool Equipment::SetEffectInfo::FUN_1411dfcf0(MS2Ptr<SetEffectInfo> spOther)
{
    if (spOther == 0)
        return false;
    if (m_nGroup != spOther->m_nGroup)
        return false;
    if (m_strName != spOther->m_strName)
        return false;
    if (m_uids != spOther->m_uids)
        return false;
    return true;
}

// @0x1411dfe00
CEquipment::CEquipment(PC* pPC)
    : m_00(0), m_04(0), m_pPC(pPC), m_slots(10), m_spCutting(0), m_48(0), m_4c(0), m_50(0), m_54(0), m_58(0),
      m_5c(false), m_bOptimize(false), m_5e(false), m_5f(false), m_64(0),
      m_skillStats(17, .75f, .25f, 2.25f, 10), m_effectStats(17, .75f, .25f, 2.25f, 10), m_bHasSetName(false)
{
    for (int i = 0; i < 20; i++) {
        MS2Ptr<CEquipmentSlot> spSlot(new CEquipmentSlot);
        spSlot->m_nIndex = i;
        m_slots.SetAt(spSlot->m_nIndex, spSlot);
    }
    m_spCutting = EE_NEW CPriortyCutting(this);
    if (s_meshSuffixes.IsEmpty()) {
        s_meshSuffixes.AddTail("");
        s_meshSuffixes.AddTail(":0");
        s_meshSuffixes.AddTail(":1");
        s_meshSuffixes.AddTail(":2");
        s_meshSuffixes.AddTail(":3");
        s_meshSuffixes.AddTail(":4");
        s_meshSuffixes.AddTail(":5");
        s_meshSuffixes.AddTail(":6");
        s_meshSuffixes.AddTail(":7");
        s_meshSuffixes.AddTail(":8");
        s_meshSuffixes.AddTail(":9");
        s_meshSuffixes.AddTail("_Belt");
        s_meshSuffixes.AddTail("_Wrist");
        s_meshSuffixes.AddTail("_Knee");
        s_meshSuffixes.AddTail("_Ankle");
        s_meshSuffixes.AddTail("_Stocking");
        s_meshSuffixes.AddTail("_Armor");
        s_meshSuffixes.AddTail("_Skin");
        s_meshSuffixes.AddTail("_Bra");
        s_meshSuffixes.AddTail("_Panty");
    }
    m_spLayerInfo = new CEquipmentSlotLayerInfo(2);
    FUN_1411ef740();
    m_setEffects.resize(3, MS2Ptr<Equipment::SetEffectInfo>(0));
}

// @0x1411e06e0
CEquipment::~CEquipment()
{
    m_pPC = 0;
    m_spCutting = 0;
    m_slots.RemoveAll();
}

// @0x1411e0810
void CEquipment::FUN_1411e0810()
{
    for (POSITION pos = m_slots.GetHeadPosition(); pos != NULL; m_slots.GetNext(pos)) {
        MS2Ptr<CEquipmentSlot> spSlot = m_slots.GetValueAt(pos);
        for (int i = 0; i < 6; i++) {
            MS2Ptr<CEquipItem> spItem = spSlot->m_items[i];
            if (spItem.get() != NULL && spSlot->m_bShown[i] != 0)
                spItem->FUN_1411dc040();
            spSlot->m_items[i] = 0;
        }
    }
    FUN_1411ef970();
}

// @0x1411e09a0
int CEquipment::FUN_1411e09a0()
{
    for (POSITION pos = m_slots.GetHeadPosition(); pos != NULL; m_slots.GetNext(pos)) {
        MS2Ptr<CEquipmentSlot> spSlot = m_slots.GetValueAt(pos);
        for (int i = 0; i < 6; i++) {
            MS2Ptr<CEquipItem> spItem = spSlot->m_items[i];
            if (spItem == 0)
                continue;
            if (spSlot->m_bShown[i] == 0)
                continue;
            if (spItem->FUN_1411dc0d0() == 0)
                return 0;
        }
    }
    return 1;
}

// @0x1411e0b30
int CEquipment::FUN_1411e0b30()
{
    if (FUN_1411e09a0() != 0) {
        m_pPC->vfunc_32(true);
        m_pPC->FUN_1416749a0()->FUN_140971150();
    }
    FUN_1411e6e70();
    return 1;
}

// @0x1411e0ba0
int CEquipment::FUN_1411e0ba0()
{
    m_pPC->vfunc_32(true);
    m_pPC->FUN_1416749a0()->FUN_140971150();
    FUN_1411e6e70();
    return 1;
}

// @0x1411e0c00
int CEquipment::FUN_1411e0c00()
{
    return 0;
}

// @0x1411e0c10
void CEquipment::FUN_1411e0c10()
{
    FUN_1411e0b30();
}

// @0x1411e0c30
int CEquipment::FUN_1411e0c30(int nItemId)
{
    ATL::CAtlList<MS2Ptr<CEquipItem> > items(10);
    FUN_1411e1b80(items);
    POSITION pos = items.GetHeadPosition();
    while (pos != NULL) {
        MS2Ptr<CEquipItem> spItem = items.GetNext(pos);
        if (spItem.get() != NULL && spItem->FUN_1411dc820() == nItemId)
            return 1;
    }
    return 0;
}

// @0x1411e0d40
int CEquipment::FUN_1411e0d40(int nItemId)
{
    ATL::CAtlList<MS2Ptr<CEquipItem> > items(10);
    FUN_1411e1b80(items);
    POSITION pos = items.GetHeadPosition();
    while (pos != NULL) {
        MS2Ptr<CEquipItem> spItem = items.GetNext(pos);
        if (spItem.get() != NULL && spItem->FUN_1411dc7a0()->FUN_140528980() && spItem->FUN_1411dc820() == nItemId)
            return 1;
    }
    return 0;
}

// @0x1411e0ee0
PC* CEquipment::FUN_1411e0ee0()
{
    return m_pPC;
}

// MS2-FUNCTIONAL: the (double)a * b + 1e-6 helper 0x1411f0e30 is a header inline; written out here.
// @0x1411e0f00
float CEquipment::FUN_1411e0f00(float f)
{
    return (float)((double)f * (double)(FUN_1411e1110((SAType)3) + 1.0f) + 0.000001);
}

// @0x1411e0f50
float CEquipment::FUN_1411e0f50(float f)
{
    return f + (float)FUN_1411e1160((SAType)4);
}

// @0x1411e0f90
float CEquipment::FUN_1411e0f90(float f)
{
    float fLevel = (float)FUN_1411e1160((SAType)0x27);
    float fReduce = 0.0f;
    if (fLevel == 1.0f)
        fReduce = FUN_14028d3a0(50.0f);
    else if (fLevel == 2.0f)
        fReduce = FUN_14028d3a0(100.0f);
    else if (fLevel == 3.0f)
        fReduce = FUN_14028d3a0(150.0f);
    else if (fLevel > 4.0f)
        fReduce = FUN_14028d3a0(200.0f);
    return efd::Max(0.0f, f - fReduce);
}

// @0x1411e1080
unsigned CEquipment::FUN_1411e1080(unsigned n)
{
    n = (unsigned)((float)n - (float)n * FUN_1411e1110((SAType)0x22));
    return n < 0 ? 0 : n;
}

// @0x1411e1110
float CEquipment::FUN_1411e1110(SAType eType)
{
    int nValue = FUN_1411e1160(eType);
    return nValue / 1000.0f;
}

// @0x1411e1160
int CEquipment::FUN_1411e1160(SAType eType)
{
    int nValue = m_abilities[eType];
    nValue += m_pPC->FUN_1416749a0()->FUN_1409716f0(eType);
    nValue += FUN_1401c0d90()->FUN_1404774a0(eType, m_pPC->FUN_141658f30());
    nValue += m_pPC->FUN_1411f9310()->GetSpecialAbility(eType);
    return nValue;
}

// @0x1411e1250
float CEquipment::FUN_1411e1250(int nOption, unsigned nKey)
{
    MS2Ptr<SAInvokeEffectStat> spStat;
    if (FUN_14081d8a0(nOption) != 0) {
        if (!m_skillStats.Lookup(nKey, spStat))
            return 0;
    } else if (FUN_14081d8e0(nOption) != 0 && !m_effectStats.Lookup(nKey, spStat)) {
        return 0;
    }
    if (!spStat)
        return 0;
    MS2Ptr<InvokeEffectOption> spOption;
    if (!spStat->m_18.Lookup((Unk_InvokeOptionType)nOption, spOption))
        return 0;
    return spOption->FUN_140267350();
}

// @0x1411e13e0
float CEquipment::FUN_1411e13e0(int nOption, unsigned nKey)
{
    MS2Ptr<SAInvokeEffectStat> spStat;
    if (FUN_14081d8a0(nOption) != 0) {
        if (!m_skillStats.Lookup(nKey, spStat))
            return 0.0f;
    } else if (FUN_14081d8e0(nOption) != 0 && !m_effectStats.Lookup(nKey, spStat)) {
        return 0.0f;
    }
    if (!spStat)
        return 0.0f;
    MS2Ptr<InvokeEffectOption> spOption;
    if (!spStat->m_18.Lookup((Unk_InvokeOptionType)nOption, spOption))
        return 0.0f;
    return (float)spOption->FUN_140267370();
}

// @0x1411e1580
MS2Ptr<CEquipItem> CEquipment::FUN_1411e1580(__int64 nUid)
{
    for (POSITION pos = m_slots.GetHeadPosition(); pos != NULL; m_slots.GetNext(pos)) {
        MS2Ptr<CEquipmentSlot> spSlot = m_slots.GetValueAt(pos);
        for (int i = 0; i < 6; i++) {
            MS2Ptr<CEquipItem> spItem = spSlot->m_items[i];
            if (spItem == 0)
                continue;
            if (spItem->FUN_1411dc7a0()->FUN_140526a50() == nUid)
                return spItem;
        }
    }
    return 0;
}

// @0x1411e1780
MS2Ptr<CEquipItem> CEquipment::FUN_1411e1780(int nSlot, int nLayer)
{
    MS2Ptr<CEquipmentSlot> spSlot(0);
    if (!m_slots.Lookup(nSlot, spSlot))
        return 0;
    return spSlot->m_items[nLayer];
}

// @0x1411e1860
MS2Ptr<CEquipItem> CEquipment::FUN_1411e1860(int nSlot, int nSkip, int bCheck)
{
    for (int i = 5; i >= 0; i--) {
        if (i == nSkip)
            continue;
        MS2Ptr<CEquipItem> spItem = FUN_1411e1780(nSlot, i);
        if (!spItem)
            continue;
        if (FUN_1411e0ee0()->FUN_141662eb0(spItem->FUN_1411dc7a0().get()) == 0)
            continue;
        if (bCheck != 0 && FUN_1411ef780(spItem, i) == 0)
            continue;
        return spItem;
    }
    return 0;
}

// @0x1411e1a50
MS2Ptr<CEquipItem> CEquipment::FUN_1411e1a50(int nSlot, int bCheck)
{
    for (int i = 2; i >= 0; i--) {
        MS2Ptr<CEquipItem> spItem = FUN_1411e1780(nSlot, i);
        if (!spItem)
            continue;
        if (bCheck != 0 && FUN_1411ef780(spItem, i) == 0)
            continue;
        return spItem;
    }
    return 0;
}

// @0x1411e1b80
void CEquipment::FUN_1411e1b80(ATL::CAtlList<MS2Ptr<CEquipItem> >& items) const
{
    for (POSITION pos = m_slots.GetHeadPosition(); pos != NULL; m_slots.GetNext(pos)) {
        MS2Ptr<CEquipmentSlot> spSlot = m_slots.GetValueAt(pos);
        for (int i = 0; i < 6; i++) {
            MS2Ptr<CEquipItem> spItem = spSlot->m_items[i];
            if (spItem == 0)
                continue;
            if (spSlot->m_bShown[i] != 0)
                items.AddTail(spItem);
        }
    }
}

// @0x1411e1ce0
void CEquipment::FUN_1411e1ce0(ATL::CAtlList<MS2Ptr<CEquipItem> >& items, int nLayer)
{
    for (POSITION pos = m_slots.GetHeadPosition(); pos != NULL; m_slots.GetNext(pos)) {
        MS2Ptr<CEquipmentSlot> spSlot = m_slots.GetValueAt(pos);
        MS2Ptr<CEquipItem> spItem = spSlot->m_items[nLayer];
        if (spItem == 0)
            continue;
        if (spSlot->m_bShown[nLayer] != 0)
            items.AddTail(spItem);
    }
}

// @0x1411e1e30
void CEquipment::FUN_1411e1e30(ATL::CAtlList<MS2Ptr<CEquipItem> >& items, int nSkip)
{
    for (POSITION pos = m_slots.GetHeadPosition(); pos != NULL; m_slots.GetNext(pos)) {
        MS2Ptr<CEquipmentSlot> spSlot = m_slots.GetValueAt(pos);
        if (spSlot == 0)
            continue;
        for (int i = 0; i < 6; i++) {
            if (i == nSkip)
                continue;
            MS2Ptr<CEquipItem> spItem = spSlot->m_items[i];
            if (spItem == 0)
                continue;
            if (spSlot->m_bShown[i] != 0)
                items.AddTail(spItem);
        }
    }
}

// @0x1411e1fc0
void CEquipment::FUN_1411e1fc0(std::vector<MS2Ptr<CEquipItem> >& items, int nSkip)
{
    for (POSITION pos = m_slots.GetHeadPosition(); pos != NULL; m_slots.GetNext(pos)) {
        MS2Ptr<CEquipmentSlot> spSlot = m_slots.GetValueAt(pos);
        if (spSlot == 0)
            continue;
        for (int i = 0; i < 6; i++) {
            if (i == nSkip)
                continue;
            MS2Ptr<CEquipItem> spItem = spSlot->m_items[i];
            if (spItem == 0)
                continue;
            if (spSlot->m_bShown[i] != 0)
                items.push_back(spItem);
        }
    }
}

// @0x1411e2150
void CEquipment::FUN_1411e2150(std::vector<MS2Ptr<CEquipItem> >& items, int nLayer)
{
    for (POSITION pos = m_slots.GetHeadPosition(); pos != NULL; m_slots.GetNext(pos)) {
        MS2Ptr<CEquipmentSlot> spSlot = m_slots.GetValueAt(pos);
        if (spSlot == 0)
            continue;
        MS2Ptr<CEquipItem> spItem = spSlot->m_items[nLayer];
        if (spItem == 0)
            continue;
        if (spSlot->m_bShown[nLayer] != 0)
            items.push_back(spItem);
    }
}

// @0x1411e22c0
void CEquipment::FUN_1411e22c0(ATL::CAtlList<MS2Ptr<CEquipItem> >& items, int nLayer)
{
    for (POSITION pos = m_slots.GetHeadPosition(); pos != NULL; m_slots.GetNext(pos)) {
        MS2Ptr<CEquipmentSlot> spSlot = m_slots.GetValueAt(pos);
        for (int i = nLayer; i >= 0; i--) {
            MS2Ptr<CEquipItem> spItem = spSlot->m_items[i];
            if (spItem == 0)
                continue;
            if (FUN_1411ef870(spSlot, i) != 0)
                items.AddTail(spItem);
        }
    }
}

// @0x1411e2440
int CEquipment::FUN_1411e2440(int nLayer)
{
    int nCount = 0;
    for (POSITION pos = m_slots.GetHeadPosition(); pos != NULL; m_slots.GetNext(pos)) {
        MS2Ptr<CEquipmentSlot> spSlot = m_slots.GetValueAt(pos);
        if (spSlot == 0)
            continue;
        MS2Ptr<CEquipItem> spItem = spSlot->m_items[nLayer];
        if (spItem == 0)
            continue;
        if (FUN_141421690(spItem->FUN_1411dc7a0().get()) == 1)
            continue;
        nCount++;
    }
    return nCount;
}

// @0x1411e2e40
void CEquipment::FUN_1411e2e40(ATL::CAtlList<MS2Ptr<CEquipItem> >& items)
{
    for (POSITION pos = m_slots.GetHeadPosition(); pos != NULL; m_slots.GetNext(pos)) {
        MS2Ptr<CEquipmentSlot> spSlot = m_slots.GetValueAt(pos);
        for (int i = 5; i >= 0; i--) {
            MS2Ptr<CEquipItem> spItem = spSlot->m_items[i];
            if (spItem == 0)
                continue;
            if (FUN_1411ef870(spSlot, i) != 0 && FUN_1411ef780(spItem, i) != 0) {
                items.AddTail(spItem);
                break;
            }
        }
    }
}

// @0x1411e3600
void CEquipment::FUN_1411e3600(MS2Ptr<CItem> spItem)
{
    MS2Ptr<CEquipItem> spEquip = CItemService::GetInstance()->FUN_14141a060(spItem.get(), m_pPC, 0);
    if (!spEquip)
        return;
    FUN_1411e36e0(spEquip);
}

// @0x1411e36e0
void CEquipment::FUN_1411e36e0(MS2Ptr<CEquipItem> spItem)
{
    FUN_1411eeda0();
    FUN_1411ec190(spItem, 0);
    spItem->FUN_1411dbf60();
    NotifySystem::GetInstance()->Post(MS2Ptr<NotifyObject>(new NotifyChangeEquipment(m_pPC)));
}

// @0x1411e37f0
void CEquipment::FUN_1411e37f0(MS2Ptr<CItem> spItem, __int64 nValue)
{
    MS2Ptr<CEquipItem> spEquip = CItemService::GetInstance()->FUN_14141a060(spItem.get(), m_pPC, nValue);
    if (!spEquip)
        return;
    FUN_1411e36e0(spEquip);
}

// @0x1411e38e0
void CEquipment::FUN_1411e38e0(MS2Ptr<CItem> spItem)
{
    CItemLoader::GetInstance()->Request(m_pPC->FUN_14123c580(), spItem);
}

// @0x1411e3960
void CEquipment::FUN_1411e3960(MS2Ptr<CItem> spItem, int nFlag)
{
    if (spItem->FUN_140527840()->FUN_14053ec50() == 0)
        return;
    FUN_1411eeda0();
    MS2Ptr<CEquipItem> spEquip(0);
    if (spItem->FUN_14052a170() == 3)
        spEquip = FUN_1411e1780(spItem->FUN_140527a20(), 3);
    else
        spEquip = FUN_1411e1580(spItem->FUN_140526a50());
    if (spEquip.get() != NULL)
        FUN_1411e3bd0(spEquip, nFlag);
}

// @0x1411e3b10
void CEquipment::FUN_1411e3b10(MS2Ptr<CItem> spItem, int nFlag)
{
    if (spItem->FUN_140527840()->FUN_14053ec50() == 0)
        return;
    CItemLoader::GetInstance()->Request(m_pPC->FUN_14123c580(), spItem, nFlag);
}

// @0x1411e3bd0
void CEquipment::FUN_1411e3bd0(MS2Ptr<CEquipItem> spItem, int nFlag)
{
    if (!spItem)
        return;
    FUN_1411ebec0(spItem, 0);
    spItem->FUN_1411dbf80(nFlag);
}

// @0x1411e3c70
void CEquipment::FUN_1411e3c70(MS2Ptr<CEquipItem> spItem, int nFlag)
{
    if (!spItem)
        return;
    CItemLoader::GetInstance()->Request(m_pPC->FUN_14123c580(), MS2Ptr<CPtred>(spItem), nFlag);
}

// @0x1411e3d20
void CEquipment::FUN_1411e3d20(ATL::CAtlList<MS2Ptr<CEquipItem> >& items, int nFlag)
{
    for (POSITION pos = items.GetHeadPosition(); pos != NULL; items.GetNext(pos)) {
        MS2Ptr<CEquipItem> spItem = items.GetAt(pos);
        if (spItem.get() != NULL)
            FUN_1411e3bd0(spItem, nFlag);
    }
}

// @0x1411e3de0
void CEquipment::FUN_1411e3de0(int bKeepLoaded)
{
    for (POSITION pos = m_slots.GetHeadPosition(); pos != NULL; m_slots.GetNext(pos)) {
        MS2Ptr<CEquipmentSlot> spSlot = m_slots.GetValueAt(pos);
        for (int i = 0; i < 6; i++) {
            MS2Ptr<CEquipItem> spItem = spSlot->m_items[i];
            if (spItem.get() != NULL) {
                if (bKeepLoaded == 0 && FUN_1409f7c90()->FUN_1409f7ea0() != 0)
                    FUN_1411e3c70(spItem, 0);
                else
                    FUN_1411e3bd0(spItem, 0);
            }
        }
    }
}

// @0x1411e3f80
void CEquipment::FUN_1411e3f80(const ATL::CRBMap<int, int>& keep, int bKeepLoaded)
{
    for (POSITION pos = m_slots.GetHeadPosition(); pos != NULL; m_slots.GetNext(pos)) {
        MS2Ptr<CEquipmentSlot> spSlot = m_slots.GetValueAt(pos);
        for (int i = 0; i < 6; i++) {
            if (keep.Lookup(spSlot->m_nIndex) != NULL)
                continue;
            MS2Ptr<CEquipItem> spItem = spSlot->m_items[i];
            if (spItem.get() != NULL) {
                if (bKeepLoaded == 0 && FUN_1409f7c90()->FUN_1409f7ea0() != 0)
                    FUN_1411e3c70(spItem, 0);
                else
                    FUN_1411e3bd0(spItem, 0);
            }
        }
    }
}

// @0x1411e2610
MS2Ptr<CEquipItem> CEquipment::FUN_1411e2610(NiAVObject* pObj, bool bActive, int nLayer, bool bDeep)
{
    ATL::CAtlList<MS2Ptr<CEquipItem> > items(10);
    if (nLayer == 6) {
        if (!bActive)
            FUN_1411e1b80(items);
        else
            FUN_1411e2e40(items);
    } else {
        FUN_1411e1ce0(items, nLayer);
    }
    for (POSITION pos = items.GetHeadPosition(); pos != NULL; items.GetNext(pos)) {
        MS2Ptr<CEquipItem> spItem = items.GetAt(pos);
        if (spItem == 0)
            continue;
        if (bActive && spItem->FUN_1411dc670() == 0)
            continue;
        ATL::CAtlArray<MS2Ptr<CEquipModel> > models;
        spItem->FUN_1411dcc80(models);
        for (unsigned i = 0; i < models.GetCount(); i++) {
            MS2Ptr<CEquipModel> spModel = models[i];
            if (spModel == 0)
                continue;
            for (NiAVObjectPtr spNode : *FUN_141201c90(spModel.operator->())) {
                if (spNode == pObj)
                    return spItem;
                if (bDeep) {
                    NiAVObjectPtr spFound = spNode->GetObjectByName(pObj->GetName());
                    if (spFound == pObj)
                        return spItem;
                }
            }
        }
    }
    return 0;
}

// @0x1411e2a60
NiAVObjectPtr CEquipment::FUN_1411e2a60(__int64 nUid, const CString& strName, bool bDeep)
{
    MS2Ptr<CEquipItem> spItem = FUN_1411e1580(nUid);
    if (spItem == 0)
        return 0;
    ATL::CAtlArray<MS2Ptr<CEquipModel> > models;
    spItem->FUN_1411dcc80(models);
    if (models.IsEmpty())
        return 0;
    for (unsigned i = 0; i < models.GetCount(); i++) {
        MS2Ptr<CEquipModel> spModel = models[i];
        if (spModel == 0)
            continue;
        std::set<NiAVObjectPtr>* pNodes = FUN_141201c90(spModel.operator->());
        const char* pszName = strName;
        for (NiAVObjectPtr spNode : *pNodes) {
            if (spNode->GetName() == pszName)
                return spNode;
            if (bDeep) {
                NiAVObjectPtr spFound = spNode->GetObjectByName(NiFixedString(pszName));
                if (spFound)
                    return spFound;
            }
        }
    }
    return 0;
}

// @0x1411e3000
void CEquipment::FUN_1411e3000(ATL::CAtlList<MS2Ptr<CEquipItem> >& items, int nMaxLayer, int bCheck, bool bForce)
{
    bool bNotFitting = !FUN_14087ddc0(m_pPC != 0 ? m_pPC->GetClassDesc() : 0, 0x6200044);
    Unk_LayerBits shown;
    for (POSITION pos = m_slots.GetHeadPosition(); pos != NULL; m_slots.GetNext(pos)) {
        MS2Ptr<CEquipmentSlot> spSlot = m_slots.GetValueAt(pos);
        if (spSlot == 0)
            continue;
        bool bDone = false;
        for (int i = 5; i >= 0; i--) {
            if (i >= nMaxLayer || (i == 2 && !FUN_1411ea770()))
                continue;
            MS2Ptr<CEquipItem> spItem = spSlot->m_items[i];
            if (spItem == 0 || spItem->FUN_1411dc7a0() == 0)
                continue;
            if (FUN_1411ef870(spSlot, i) == 0)
                continue;
            if (m_pPC->FUN_141662eb0(spItem->FUN_1411dc7a0().get()) == 0)
                continue;
            if (bCheck != 0 && FUN_1411ef780(spItem, i) == 0 && FUN_141421690(spItem->FUN_1411dc7a0().get()) == 0)
                continue;
            Unk_EquipItemData* pData = spItem->FUN_1411dc7f0();
            if (pData == NULL)
                continue;
            if (!pData->property.flag08) {
                if (bNotFitting && spItem->FUN_1411dcfc0(s_tagMissMatch) != 0)
                    continue;
                if (pData->FUN_14053d2b0()) {
                    if (spSlot->m_nIndex == 9)
                        break;
                    shown.Set(i, true);
                }
                if (shown[i] == true && spSlot->m_nIndex == 9)
                    break;
                if (pData->FUN_14053d460() && spSlot->m_nIndex == 4)
                    break;
                if (bForce == true || !pData->FUN_14053d2f0())
                    bDone = true;
                items.AddTail(spItem);
            } else {
                bDone = true;
            }
            if (bDone)
                break;
        }
    }
}

// @0x1411e4150
void CEquipment::FUN_1411e4150(__int64 nItemUid, int nSlot, int nLayer)
{
    MS2Ptr<CEquipItem> spItem = FUN_1411e1580(nItemUid);
    if (!spItem)
        return;
    int nOldSlot = spItem->FUN_1411dc7a0()->FUN_140526c30();
    int nNewSlot = nSlot;
    MS2Ptr<CEquipmentSlot> spSlot(0);
    if (m_slots.Lookup(nSlot, spSlot)) {
        MS2Ptr<CEquipItem> spOther = spSlot->m_items[nLayer != 0 ? nLayer : spItem->FUN_1411dc7a0()->FUN_14052a170()];
        if (spOther.get() == NULL) {
            FUN_1411ebec0(spItem, 1);
            spItem->FUN_1411dc7a0()->FUN_140526c10(nNewSlot);
            spItem->FUN_1411dcf10(s_tagLower);
            spItem->FUN_1411dd280();
            FUN_1411ec190(spItem, 1);
        } else {
            FUN_1411ebec0(spItem, 1);
            FUN_1411ebec0(spOther, 1);
            spItem->FUN_1411dc7a0()->FUN_140526c10(nNewSlot);
            spItem->FUN_1411dcf10(s_tagLower);
            spItem->FUN_1411dd280();
            spOther->FUN_1411dc7a0()->FUN_140526c10(nOldSlot);
            spOther->FUN_1411dcf10(s_tagLower);
            spOther->FUN_1411dd280();
            FUN_1411ec190(spItem, 1);
            FUN_1411ec190(spOther, 1);
        }
        m_pPC->FUN_141659000(1);
        FUN_141653f00(m_pPC);
    }
}

// @0x1411e46b0
void CEquipment::FUN_1411e46b0(MS2Ptr<CEquipItem> spItem)
{
    if (spItem == 0)
        return;
    MS2Ptr<CItem> spData = spItem->FUN_1411dc7a0();
    if (spData == 0)
        return;
    if (!spData->FUN_140528980()) {
        if (spData->FUN_140528930())
            FUN_1411e5450(spItem);
        else
            FUN_1411e5500(spItem);
    }
    FUN_1411e5100(spItem);
    if (spData->FUN_14052a2d0()) {
        if (m_pPC->FUN_141658f30() == 0)
            FUN_1411e55b0(spItem);
        else
            FUN_1411e5660(spItem);
    }
    if (spData->FUN_14052a330()) {
        if (m_pPC->FUN_141662de0() == 0)
            FUN_1411e56e0(spItem);
        else
            FUN_1411e5790(spItem);
    }
    for (unsigned i = 0; i < spData->FUN_140527840()->FUN_14053eba0()->FUN_14054b3d0(); i++) {
        unsigned nSlot = spData->FUN_140527a90(i);
        bool bCovered = false;
        for (int j = 5; j >= 0; j--) {
            MS2Ptr<CEquipItem> spWorn = FUN_1411e1780(nSlot, j);
            if (spWorn.get() != NULL) {
                if (bCovered) {
                    spWorn->FUN_1411dce60(s_tagLower);
                    spWorn->FUN_1411dd280();
                } else if (m_pPC->FUN_141662eb0(spWorn->FUN_1411dc7a0().get()) != 0) {
                    bCovered = true;
                }
            }
        }
    }
}

// @0x1411e4b30
void CEquipment::FUN_1411e4b30(MS2Ptr<CEquipItem> spItem)
{
    if (spItem == 0)
        return;
    MS2Ptr<CItem> spData = spItem->FUN_1411dc7a0();
    if (spData == 0)
        return;
    Unk_ItemEquipData* pData = spData->FUN_140527840();
    if (pData == NULL)
        return;
    if (!spData->FUN_140528980()) {
        if (spData->FUN_140528930())
            FUN_1411e5450(spItem);
        else
            FUN_1411e5500(spItem);
    }
    FUN_1411e5100(spItem);
    if (spData->FUN_14052a2d0()) {
        if (m_pPC->FUN_141658f30() == 0)
            FUN_1411e55b0(spItem);
        else
            FUN_1411e5660(spItem);
    }
    if (spData->FUN_14052a330()) {
        if (m_pPC->FUN_141662de0() == 0)
            FUN_1411e56e0(spItem);
        else
            FUN_1411e5790(spItem);
    }
    int nLayer = spData->FUN_14052a170();
    for (unsigned i = 0; i < pData->FUN_14053eba0()->FUN_14054b3d0(); i++) {
        unsigned nSlot = spData->FUN_140527a90(i);
        for (int j = 5; j >= 0; j--) {
            MS2Ptr<CEquipItem> spWorn = FUN_1411e1780(nSlot, j);
            if (!spWorn)
                continue;
            if (m_pPC->FUN_141662eb0(spWorn->FUN_1411dc7a0().get()) != 0) {
                if (j < nLayer) {
                    if (!spWorn->FUN_1411dc7a0()->FUN_140527840()->FUN_14053d2b0()) {
                        spWorn->FUN_1411dcf10(s_tagLower);
                        spWorn->FUN_1411dd280();
                    } else if (FUN_1411e5280(j) != 0) {
                        spWorn->FUN_1411dcf10(s_tagLower);
                        spWorn->FUN_1411dd280();
                    }
                }
                break;
            }
        }
    }
    if (m_pPC != 0 && pData->FUN_14053d2f0())
        m_pPC->FUN_141659000(1);
}

// @0x1411e5100
void CEquipment::FUN_1411e5100(MS2Ptr<CEquipItem> spItem)
{
    if (m_pPC == 0 || spItem == 0)
        return;
    MS2Ptr<CItem> spData = spItem->FUN_1411dc7a0();
    if (spData == 0)
        return;
    if (spData->FUN_140527840() == NULL)
        return;
    if (spData->FUN_14052a150() == 2) {
        if (!FUN_1411ea770())
            FUN_1411e5810(spItem, s_tagLayerExpired);
        else
            FUN_1411e58c0(spItem, s_tagLayerExpired);
    }
}

// @0x1411e5280
int CEquipment::FUN_1411e5280(int nLayer)
{
    for (int i = nLayer + 1; i <= 5; i++) {
        MS2Ptr<CEquipItem> spUpper = FUN_1411e1780(9, i);
        if (spUpper.get() != NULL && m_pPC->FUN_141662eb0(spUpper->FUN_1411dc7a0().get()) != 0)
            return 0;
        MS2Ptr<CEquipItem> spLower = FUN_1411e1780(8, i);
        if (spLower.get() != NULL && m_pPC->FUN_141662eb0(spLower->FUN_1411dc7a0().get()) != 0)
            return 0;
    }
    return 1;
}

// @0x1411e5450
void CEquipment::FUN_1411e5450(MS2Ptr<CEquipItem> spItem)
{
    if (!spItem)
        return;
    spItem->FUN_1411dce60(s_tagExpired);
    spItem->FUN_1411dd280();
    FUN_1411e5940(spItem);
}

// @0x1411e5500
void CEquipment::FUN_1411e5500(MS2Ptr<CEquipItem> spItem)
{
    if (!spItem)
        return;
    spItem->FUN_1411dce60(s_tagInvalide);
    spItem->FUN_1411dd280();
    FUN_1411e5940(spItem);
}

// @0x1411e55b0
void CEquipment::FUN_1411e55b0(MS2Ptr<CEquipItem> spItem)
{
    if (!spItem)
        return;
    spItem->FUN_1411dce60(s_tagPCBang);
    spItem->FUN_1411dd280();
    FUN_1411e5940(spItem);
}

// @0x1411e5660
void CEquipment::FUN_1411e5660(MS2Ptr<CEquipItem> spItem)
{
    if (!spItem)
        return;
    spItem->FUN_1411dcf10(s_tagPCBang);
    spItem->FUN_1411dd280();
}

// @0x1411e56e0
void CEquipment::FUN_1411e56e0(MS2Ptr<CEquipItem> spItem)
{
    if (!spItem)
        return;
    spItem->FUN_1411dce60(s_tagVIP);
    spItem->FUN_1411dd280();
    FUN_1411e5940(spItem);
}

// @0x1411e5790
void CEquipment::FUN_1411e5790(MS2Ptr<CEquipItem> spItem)
{
    if (!spItem)
        return;
    spItem->FUN_1411dcf10(s_tagVIP);
    spItem->FUN_1411dd280();
}

// @0x1411e5810
void CEquipment::FUN_1411e5810(MS2Ptr<CEquipItem> spItem, const CString& strTag)
{
    if (!spItem)
        return;
    spItem->FUN_1411dce60(strTag);
    spItem->FUN_1411dd280();
    FUN_1411e5940(spItem);
}

// @0x1411e58c0
void CEquipment::FUN_1411e58c0(MS2Ptr<CEquipItem> spItem, const CString& strTag)
{
    if (!spItem)
        return;
    spItem->FUN_1411dcf10(strTag);
    spItem->FUN_1411dd280();
}

// @0x1411e5940
void CEquipment::FUN_1411e5940(MS2Ptr<CEquipItem> spItem)
{
    if (!spItem)
        return;
    MS2Ptr<CItem> spData = spItem->FUN_1411dc7a0();
    if (!spData) {
        Unk_ItemEquipData* pData = spData->FUN_140527840();
        if (pData == NULL)
            return;
        if (pData->FUN_14053c620() == 0xe || pData->FUN_14053c620() == 0xf || pData->FUN_14053c620() == 0x16 ||
            pData->FUN_14053c620() == 0x10 || pData->FUN_14053c620() == 0x11) {
            int nSlot = spData->FUN_140527a20();
            MS2Ptr<CEquipmentSlot> spSlot(0);
            if (m_slots.Lookup(nSlot, spSlot)) {
                bool bShown = false;
                for (int i = 0; i < 6; i++) {
                    MS2Ptr<CEquipItem> spWorn = spSlot->m_items[i];
                    if (spWorn == 0)
                        continue;
                    if (FUN_1411ef780(spWorn, i) != 0)
                        bShown = true;
                }
                if (!bShown)
                    FUN_1411e9530(nSlot, FUN_14021c050(spData->FUN_140527a20()));
            }
        }
    }
}

// @0x1411e7320
void CEquipment::FUN_1411e7320()
{
    m_pPC->FUN_1416749a0()->FUN_140971720(m_skillStats, m_effectStats);
}

// @0x1411e7380
void CEquipment::FUN_1411e7380()
{
    MS2Ptr<CEquipItem> spItem = m_pPC->FUN_141655e10(7);
    if (!spItem)
        return;
    if (spItem->FUN_1411dc0d0() == 0)
        return;
    ATL::CAtlArray<MS2Ptr<CEquipModel> > models;
    spItem->FUN_1411dcc80(models);
    if (models.IsEmpty())
        return;
    float fScale = MODEL(models[0])->FUN_141200ab0()->mantlescale;
    if (FUN_14028d470(fScale, 1.0f))
        return;
    for (unsigned i = 0; i < models.GetCount(); i++) {
        models[i]->vfunc_22(fScale);
        std::set<NiAVObjectPtr>* pNodes = FUN_141201c90(models[i].operator->());
        for (std::set<NiAVObjectPtr>::iterator it = pNodes->begin(); it != pNodes->end(); ++it) {
            NiAVObjectPtr spNode = *it;
            spNode->SetScale(fScale);
        }
    }
}

// @0x1411e75f0
void CEquipment::FUN_1411e75f0()
{
    m_48 = 1;
}

// @0x1411e7610
void CEquipment::FUN_1411e7610()
{
    m_4c = 1;
    FUN_1411e7660();
}

// @0x1411e7640
void CEquipment::FUN_1411e7640()
{
    m_50 = 1;
}

// @0x1411e7660
void CEquipment::FUN_1411e7660()
{
    m_54 = 1;
}

// @0x1411e7680
void CEquipment::FUN_1411e7680()
{
    m_58 = 1;
}

// @0x1411e76a0
void CEquipment::FUN_1411e76a0()
{
    m_5f = true;
}

// @0x1411ea2e0
void CEquipment::FUN_1411ea2e0(bool bEnable)
{
    m_bOptimize = bEnable;
    if (!m_bOptimize)
        FUN_1411eeda0();
}

// @0x1411ea770
bool CEquipment::FUN_1411ea770()
{
    if (m_spLayerInfo.get() != NULL)
        return m_spLayerInfo->FUN_1411df810();
    return false;
}

// @0x1411eac20
bool CEquipment::FUN_1411eac20()
{
    return m_bHasSetName;
}

// @0x1411ef740
void CEquipment::FUN_1411ef740()
{
    m_attrs.clear();
    m_abilities.clear();
}

// @0x1411ef780
int CEquipment::FUN_1411ef780(MS2Ptr<CEquipItem> spItem, int nLayer)
{
    if (spItem == 0)
        return 0;
    if (nLayer == 2 && m_spLayerInfo.get() != NULL && !m_spLayerInfo->FUN_1411df810())
        return 0;
    return spItem->FUN_1411dc670();
}

// @0x1411ef870
int CEquipment::FUN_1411ef870(MS2Ptr<CEquipmentSlot> spSlot, int nLayer)
{
    if (spSlot == 0)
        return 0;
    if (nLayer == 2 && m_spLayerInfo.get() != NULL && !m_spLayerInfo->FUN_1411df810())
        return 0;
    return spSlot->m_bShown[nLayer];
}

// @0x1411ef970
void CEquipment::FUN_1411ef970()
{
    size_t nCount = m_setEffects.size();
    for (size_t i = 0; i < nCount; i++)
        FUN_1411efa00((int)i);
    m_pPC->FUN_141670ea0();
    m_bHasSetName = false;
    m_strSetName.Empty();
}

// @0x1411efa00
void CEquipment::FUN_1411efa00(int nIndex)
{
    if (nIndex < 0 || nIndex >= (int)m_setEffects.size())
        return;
    MS2Ptr<Equipment::SetEffectInfo> spInfo = m_setEffects[nIndex];
    if (spInfo == 0)
        return;
    if (spInfo->m_nEffect != 0)
        FUN_1411a6060(CEffectService::GetInstance(), spInfo->m_nEffect);
    m_setEffects[nIndex] = 0;
}

// @0x1411efb90
int CEquipment::FUN_1411efb90(const CString& strName, const std::vector<MS2Ptr<Equipment::SetEffectInfo> >& effects)
{
    if (m_setEffects.empty())
        return -1;
    size_t nCount = effects.size();
    for (size_t i = 0; i < nCount; i++) {
        MS2Ptr<Equipment::SetEffectInfo> spInfo = effects[i];
        if (spInfo == 0)
            continue;
        if (spInfo->m_strName != strName)
            continue;
        return (int)i;
    }
    return -1;
}

// @0x1411e6ab0
void CEquipment::FUN_1411e6ab0()
{
    m_04 = FUN_1411eacf0() == 0;
    if (m_04 == 0) {
        m_04 = FUN_1411eb3c0() == 0;
        if (m_04 == 0) {
            FUN_1411e5c10();
            FUN_1411ed270();
        }
    }
}

// @0x1411e6b50
void CEquipment::FUN_1411e6b50()
{
    NiAVObject* pRoot = FUN_141b6efc0(FUN_14123c410(m_pPC));
    if (pRoot == NULL)
        return;
    NiMesh* pMesh = NiDynamicCast(NiMesh, pRoot->GetObjectByName(NiFixedString("FA_Skin")));
    if (m_meshes68.GetCount() != 0)
        pMesh = m_meshes68[0];
    if (pMesh == NULL)
        return;
    FUN_14116e080(pMesh);
    MS2Ptr<CEquipItem> spItem = FUN_1411e1860(3, 6, 0);
    if (!spItem)
        return;
    if (!spItem->FUN_1411dc7f0()->FUN_14053d070())
        return;
    Unk_EquipSkinRecord* pRecord = static_cast<Unk_EquipSkinRecord*>(spItem->FUN_1411dc7a0()->FUN_140527870());
    CharacterDecalData* pDecal = spItem->FUN_1411dc7f0()->FUN_14053eba0()->FUN_14054b6b0();
    if (pRecord->m_f60 != 0.0f) {
        const Unk_CharEquip& kColor2 = FUN_141b6dea0(pRecord->FUN_140599fd0(2));
        const Unk_CharEquip& kColor1 = FUN_141b6dea0(pRecord->FUN_140599fd0(1));
        const Unk_CharEquip& kColor0 = FUN_141b6dea0(pRecord->FUN_140599fd0(0));
        const CString& strTexture = pDecal->GetTexture();
        FUN_14116e3f0(pMesh, pRecord->m_f58, pRecord->m_f5c, pRecord->m_f64, pRecord->m_f60,
            spItem->FUN_1411dc7f0()->FUN_14053ec70()->FUN_140547190(), strTexture, kColor0, kColor1, kColor2);
    }
}

// @0x1411e6e70
void CEquipment::FUN_1411e6e70()
{
    for (POSITION pos = m_slots.GetHeadPosition(); pos != NULL; m_slots.GetNext(pos)) {
        MS2Ptr<CEquipmentSlot> spSlot = m_slots.GetValueAt(pos);
        for (int i = 0; i < 6; i++) {
            MS2Ptr<CEquipItem> spItem = spSlot->m_items[i];
            if (spItem == 0)
                continue;
            if (FUN_1411ef870(spSlot, i) == 0)
                continue;
            if (m_pPC->FUN_14123c660() != 0)
                spItem->FUN_1411dce60(s_tagDefault);
            if (m_pPC->vfunc_25() != 0 && FUN_140ddcc90(FUN_1409f7c90()) == 0)
                spItem->FUN_1411dce60(s_tagOptimizer);
            spItem->FUN_1411dd280();
        }
    }
    CString strCL("CL");
    CString strPA("PA");
    FUN_1411ed270();
    FUN_1411edbb0();
    m_spCutting->vfunc_2();
    if (FUN_1411e1860(8, 6, 1).get() != NULL)
        FUN_1411e9760(8, strCL);
    if (FUN_1411e1860(9, 6, 1).get() != NULL) {
        FUN_1411e9760(8, strPA);
        FUN_1411e9760(9, strPA);
    }
    if (FUN_1411e1860(8, 6, 1) == 0)
        FUN_1411e9530(8, strCL);
    if (FUN_1411e1860(9, 6, 1) == 0) {
        FUN_1411e9530(8, strPA);
        FUN_1411e9530(9, strPA);
    }
    NiAVObject* pRoot = FUN_141b6ef70(m_pPC->FUN_14123c460());
    if (pRoot != NULL) {
        pRoot->UpdateProperties();
        pRoot->UpdateEffects();
    }
    m_5f = false;
}

// @0x1411e89d0
void CEquipment::FUN_1411e89d0(int n)
{
    for (POSITION pos = m_slots.GetHeadPosition(); pos != NULL; m_slots.GetNext(pos)) {
        MS2Ptr<CEquipmentSlot> spSlot = m_slots.GetValueAt(pos);
        for (int i = 0; i < 6; i++) {
            MS2Ptr<CEquipItem> spItem = spSlot->m_items[i];
            if (spItem == 0)
                continue;
            if (FUN_1411ef870(spSlot, i) == 0)
                continue;
            spItem->FUN_1411dd4a0(n);
        }
    }
}

// @0x1411e8b60
void CEquipment::FUN_1411e8b60(const CString& strA, const CString& strB, const efd::utf8string& kDefault, float fBlend)
{
    for (POSITION pos = m_slots.GetHeadPosition(); pos != NULL; m_slots.GetNext(pos)) {
        MS2Ptr<CEquipmentSlot> spSlot = m_slots.GetValueAt(pos);
        for (int i = 0; i < 6; i++) {
            MS2Ptr<CEquipItem> spItem = spSlot->m_items[i];
            if (spItem == 0)
                continue;
            if (FUN_1411ef870(spSlot, i) == 0)
                continue;
            spItem->FUN_1411dd520(strA, strB, kDefault, fBlend, false);
        }
    }
}

// @0x1411e8d20
void CEquipment::FUN_1411e8d20(const CString& strName)
{
    for (POSITION pos = m_slots.GetHeadPosition(); pos != NULL; m_slots.GetNext(pos)) {
        MS2Ptr<CEquipmentSlot> spSlot = m_slots.GetValueAt(pos);
        for (int i = 0; i < 6; i++) {
            MS2Ptr<CEquipItem> spItem = spSlot->m_items[i];
            if (spItem == 0)
                continue;
            if (FUN_1411ef870(spSlot, i) == 0)
                continue;
            spItem->FUN_1411dd5e0(strName);
        }
    }
}

// @0x1411e8eb0
void CEquipment::FUN_1411e8eb0(const CString& strTag)
{
    for (POSITION pos = m_slots.GetHeadPosition(); pos != NULL; m_slots.GetNext(pos)) {
        MS2Ptr<CEquipmentSlot> spSlot = m_slots.GetValueAt(pos);
        for (int i = 5; i >= 0; i--) {
            MS2Ptr<CEquipItem> spItem = spSlot->m_items[i];
            if (spItem == 0)
                continue;
            if (spSlot->m_bShown[i] != 0)
                spItem->FUN_1411dce60(strTag);
        }
    }
    FUN_1411e6e70();
}

// @0x1411e9020
void CEquipment::FUN_1411e9020(const CString& strTag)
{
    for (POSITION pos = m_slots.GetHeadPosition(); pos != NULL; m_slots.GetNext(pos)) {
        MS2Ptr<CEquipmentSlot> spSlot = m_slots.GetValueAt(pos);
        for (int i = 5; i >= 0; i--) {
            MS2Ptr<CEquipItem> spItem = spSlot->m_items[i];
            if (spItem == 0)
                continue;
            if (spSlot->m_bShown[i] != 0)
                spItem->FUN_1411dcf10(strTag);
        }
    }
    FUN_1411e6e70();
}

// @0x1411e9190
void CEquipment::FUN_1411e9190(int bShow)
{
    for (POSITION pos = m_slots.GetHeadPosition(); pos != NULL; m_slots.GetNext(pos)) {
        MS2Ptr<CEquipmentSlot> spSlot = m_slots.GetValueAt(pos);
        if (spSlot == 0)
            continue;
        for (POSITION pos2 = spSlot->m_replaced.GetHeadPosition(); pos2 != NULL; spSlot->m_replaced.GetNext(pos2)) {
            MS2Ptr<ReplaceObject> spReplace = spSlot->m_replaced.GetValueAt(pos2);
            if (spReplace == 0)
                continue;
            if (spReplace->m_spMesh != NULL)
                FUN_140a0b300(spReplace->m_spMesh, bShow != 0);
            if (spReplace->m_spNode != NULL)
                FUN_140a0b300(spReplace->m_spNode, bShow != 0);
        }
    }
    for (POSITION pos = m_slots.GetHeadPosition(); pos != NULL; m_slots.GetNext(pos)) {
        MS2Ptr<CEquipmentSlot> spSlot = m_slots.GetValueAt(pos);
        for (int i = 5; i >= 0; i--) {
            MS2Ptr<CEquipItem> spItem = spSlot->m_items[i];
            if (spItem == 0)
                continue;
            if (spSlot->m_nIndex == 1)
                continue;
            if (spSlot->m_bShown[i] != 0) {
                if (bShow == 0)
                    spItem->FUN_1411dcf10(s_tagCustomize);
                else
                    spItem->FUN_1411dce60(s_tagCustomize);
            }
        }
    }
    FUN_1411e6e70();
}

// @0x1411e9530
int CEquipment::FUN_1411e9530(int nSlot, const CString& strName)
{
    MS2Ptr<CEquipmentSlot> spSlot(0);
    if (!m_slots.Lookup(nSlot, spSlot))
        return 0;
    CString strMesh;
    POSITION pos = s_meshSuffixes.GetHeadPosition();
    while (pos != NULL) {
        strMesh = strName + s_meshSuffixes.GetNext(pos);
        MS2Ptr<ReplaceObject> spReplace(0);
        if (spSlot->m_replaced.Lookup(strMesh, spReplace) && spReplace->m_spNode != NULL && spReplace->m_spMesh != NULL &&
            FUN_140a0b000(spReplace->m_spMesh) == NULL)
            spReplace->m_spNode->AttachChild(spReplace->m_spMesh, true);
    }
    return 1;
}

// @0x1411e9760
int CEquipment::FUN_1411e9760(int nSlot, const CString& strName)
{
    MS2Ptr<CEquipmentSlot> spSlot(0);
    if (!m_slots.Lookup(nSlot, spSlot))
        return 0;
    CString strMesh;
    POSITION pos = s_meshSuffixes.GetHeadPosition();
    while (pos != NULL) {
        strMesh = strName + s_meshSuffixes.GetNext(pos);
        MS2Ptr<ReplaceObject> spReplace(0);
        if (spSlot->m_replaced.Lookup(strMesh, spReplace) && spReplace->m_spNode != NULL && spReplace->m_spMesh != NULL &&
            FUN_140a0b000(spReplace->m_spMesh) != NULL)
            spReplace->m_spNode->DetachChild(spReplace->m_spMesh);
    }
    return 1;
}

// @0x1411ea320
void CEquipment::FUN_1411ea320()
{
    for (POSITION pos = m_slots.GetHeadPosition(); pos != NULL; m_slots.GetNext(pos)) {
        MS2Ptr<CEquipmentSlot> spSlot = m_slots.GetValueAt(pos);
        for (int i = 0; i < 6; i++) {
            MS2Ptr<CEquipItem> spItem = spSlot->m_items[i];
            if (spItem.get() != NULL)
                spItem->FUN_1411dd650();
        }
    }
}

// @0x1411ea430
void CEquipment::FUN_1411ea430(MS2Ptr<CEquipItem> spItem)
{
    if (SetItemTable::GetInstance()->FUN_1407c51f0(spItem->FUN_1411dc7f0()->FUN_14053c560()))
        m_bSetDirty = true;
    else if (spItem->FUN_1411dc7a0()->FUN_14052a170() == 3)
        m_bSetDirty = true;
}

// @0x1411ea500
void CEquipment::FUN_1411ea500(MS2Ptr<CEquipItem> spItem)
{
    if (SetItemTable::GetInstance()->FUN_1407c51f0(spItem->FUN_1411dc7f0()->FUN_14053c560()))
        m_bSetDirty = true;
    else if (spItem->FUN_1411dc7a0()->FUN_14052a170() == 3)
        m_bSetDirty = true;
}

// @0x1411ea5d0
CString CEquipment::FUN_1411ea5d0(const CString& str)
{
    return FUN_1414253b0(str, m_00);
}

// @0x1411ea620
void CEquipment::FUN_1411ea620(const CMsTime& kStart, const CMsTime& kEnd)
{
    if (m_spLayerInfo == 0)
        m_spLayerInfo = new CEquipmentSlotLayerInfo(2);
    if (m_spLayerInfo.get() != NULL) {
        bool bWasActive = m_spLayerInfo->FUN_1411df810();
        if (m_spLayerInfo->FUN_1411dfc10(kStart, kEnd) == true && bWasActive != m_spLayerInfo->FUN_1411df810())
            m_5c = true;
        FUN_1411ea7c0();
    }
}

// @0x1411ea7c0
void CEquipment::FUN_1411ea7c0()
{
    if (m_spLayerInfo == 0)
        return;
    if (FUN_14087ddc0(m_pPC != 0 ? m_pPC->GetClassDesc() : 0, 0x6200004)) {
        PCBase* pMyPC = FUN_1403ed2d0()->FUN_141bd3620();
        if (pMyPC != NULL)
            static_cast<PC*>(pMyPC)->FUN_1416561a0()->FUN_1411ea620(m_spLayerInfo->m_start, m_spLayerInfo->m_end);
    }
}

// @0x1411ea8c0
void CEquipment::FUN_1411ea8c0()
{
    if (m_spLayerInfo == 0)
        return;
    PCBase* pMyPC = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pMyPC != NULL && m_pPC != 0 && m_pPC->FUN_14123c580() == pMyPC->FUN_14123c580())
        NotifySystem::GetInstance()->Post(MS2Ptr<NotifyObject>(new NotifyChangeActiveMyCodiTab(m_spLayerInfo->FUN_1411df810())));
}

// @0x1411eaa00
void CEquipment::FUN_1411eaa00(MS2Ptr<Equipment::SetEffectInfo> spInfo)
{
    if (spInfo == 0)
        return;
    NoticeMessage msg;
    msg.m_strName = spInfo->m_strName;
    msg.m_nObject = FUN_1403ed2d0()->FUN_141bd1a10(m_pPC);
    msg.SetActor(m_pPC->FUN_14123c580());
    static_cast<Unk_EqNotice&>(msg).FUN_140a531f0(Delegate<void(unsigned, CString, bool)>(this, &CEquipment::FUN_1411efcb0));
    msg.SetMode48(spInfo->m_nGroup);
    spInfo->m_nEffect = FUN_1411a49c0(CEffectService::GetInstance(), msg);
    if ((size_t)spInfo->m_nGroup < m_setEffects.size())
        m_setEffects[spInfo->m_nGroup] = spInfo;
}

// @0x1411eabd0
CString CEquipment::FUN_1411eabd0()
{
    return m_strSetName;
}

// @0x1411ebde0
void CEquipment::FUN_1411ebde0()
{
    if (m_updateTimer.Check(500) == 0)
        return;
    if (m_bSetDirty && FUN_1411e09a0() != 0)
        FUN_1411ee930();
    if (m_5c || (m_spLayerInfo.get() != NULL && m_spLayerInfo->FUN_1411df910() == 1)) {
        m_5c = true;
        FUN_1411ea8c0();
    }
    if (m_04 != 0)
        FUN_1411e6ab0();
}

// @0x1411ee930
void CEquipment::FUN_1411ee930()
{
    m_bSetDirty = false;
    if (m_pPC->GetClassID() != 0x6200016)
        FUN_1411ec480(false);
}

// @0x1411efaf0
MS2Ptr<Equipment::SetEffectInfo> CEquipment::FUN_1411efaf0(const CString& strName,
    const std::vector<MS2Ptr<Equipment::SetEffectInfo> >& effects)
{
    int nIndex = FUN_1411efb90(strName, effects);
    if (nIndex < 0)
        return 0;
    return effects[nIndex];
}

// @0x1411efcb0
void CEquipment::FUN_1411efcb0(unsigned nId, CString strName, bool bInserted)
{
    if (!bInserted) {
        MS2Ptr<Equipment::SetEffectInfo> spInfo = FUN_1411efaf0(strName, m_setEffects);
        if (spInfo.get() != NULL)
            spInfo->m_nEffect = 0;
    } else {
        FUN_1411e76a0();
    }
}

// @0x1411efd50
int FUN_1411efd50(MS2Ptr<CEquipItem> spItem)
{
    if (spItem == 0)
        return 0;
    Unk_EquipItemData* pData = spItem->FUN_1411dc7f0();
    if (pData == NULL)
        return 0;
    for (unsigned i = 0; i < pData->FUN_14053eba0()->FUN_14054b3d0(); i++) {
        const ModelGroup* pGroup = pData->FUN_14053eba0()->FUN_14054b2f0(i);
        for (int j = 0; j < (int)pGroup->FUN_1405450c0(); j++) {
            if (pGroup->FUN_140544fe0(j)->name0.Find("_D.nif", 0) != -1)
                return 1;
        }
    }
    return spItem->FUN_1411dc710();
}

// @0x1411ebec0
void CEquipment::FUN_1411ebec0(MS2Ptr<CEquipItem> spItem, int nFlag)
{
    MS2Ptr<CItem> spData = spItem->FUN_1411dc7a0();
    if (spData == 0)
        return;
    Unk_ItemEquipData* pData = spData->FUN_140527840();
    if (pData == NULL)
        return;
    int nLayer = spData->FUN_14052a170();
    for (unsigned i = 0; i < pData->FUN_14053eba0()->FUN_14054b3d0(); i++) {
        MS2Ptr<CEquipmentSlot> spSlot(0);
        int nSlot = FUN_141420a30(spData->FUN_140527840()->FUN_14053eba0()->FUN_14054b2f0(i)->FUN_1405451a0(),
            spData.get(), m_pPC);
        if (m_slots.Lookup(nSlot, spSlot) && spSlot->m_items[nLayer] == spItem.get()) {
            spSlot->m_items[nLayer] = 0;
            spSlot->m_bShown[nLayer] = 0;
        }
    }
    if (nFlag != 0)
        FUN_1411e4b30(spItem);
    FUN_1411e7660();
}

// @0x1411ec190
void CEquipment::FUN_1411ec190(MS2Ptr<CEquipItem> spItem, int nFlag)
{
    MS2Ptr<CItem> spData = spItem->FUN_1411dc7a0();
    if (spData == 0)
        return;
    MS2Ptr<CItemData> spItemData(spData->FUN_140527840());
    if (spItemData == 0)
        return;
    int nLayer = spData->FUN_14052a170();
    size_t nCount = spItemData->FUN_14053eba0()->FUN_14054b3d0();
    for (unsigned i = 0; i < nCount; i++) {
        MS2Ptr<CEquipmentSlot> spSlot(0);
        int nSlot = FUN_141420990(spItemData->FUN_14053eba0()->FUN_14054b2f0(i)->FUN_1405451a0(), spData.get(), m_pPC);
        if (nSlot == 0)
            continue;
        if (m_slots.Lookup(nSlot, spSlot)) {
            spSlot->m_items[nLayer] = spItem;
            spSlot->m_bShown[nLayer] = i == 0;
        }
    }
    if (nFlag != 0)
        FUN_1411e46b0(spItem);
    FUN_1411e7660();
}

// @0x1411ee980
void CEquipment::FUN_1411ee980(int bMissMatch, MS2Ptr<CEquipItem> spA, MS2Ptr<CEquipItem> spB)
{
    if (bMissMatch == 0) {
        if (spA.get() != NULL) {
            spA->FUN_1411dcf10(s_tagMissMatch);
            spA->FUN_1411dd280();
            FUN_1411e46b0(spA);
        }
        if (spB.get() != NULL) {
            spB->FUN_1411dcf10(s_tagMissMatch);
            spB->FUN_1411dd280();
            FUN_1411e46b0(spB);
        }
    } else {
        if (spA.get() != NULL) {
            spA->FUN_1411dce60(s_tagMissMatch);
            spA->FUN_1411dd280();
            FUN_1411e4b30(spA);
        }
        if (spB.get() != NULL) {
            spB->FUN_1411dce60(s_tagMissMatch);
            spB->FUN_1411dd280();
            FUN_1411e4b30(spB);
        }
    }
}

// @0x1411eebc0
void CEquipment::FUN_1411eebc0()
{
    for (POSITION pos = m_slots.GetHeadPosition(); pos != NULL; m_slots.GetNext(pos)) {
        int nSlot = m_slots.GetKeyAt(pos);
        MS2Ptr<CEquipmentSlot> spSlot = m_slots.GetValueAt(pos);
        if (spSlot.get() == NULL)
            continue;
        for (int i = 0; i < 6; i++) {
            MS2Ptr<CEquipItem> spItem = spSlot->m_items[i];
            if (spItem.get() != NULL) {
                int nItemId = spItem->FUN_1411dc820();
                Unk_EquipLog(CLogString::GetInstance(), 0xc, 0x13, L"[Slot {0}][Layer {1}][Item {2}]", nSlot, i,
                    CStringTable::GetInstance()->FUN_141811980(1, nItemId));
            }
        }
    }
}

// @0x1411eeda0
void CEquipment::FUN_1411eeda0()
{
    if (m_5e == true)
        return;
    if (DAT_143ae2b58 > 1)
        FUN_1412751b0(StringFormat(L"[MeshOptimizer] Reset merge mesh: {0}", m_pPC->vfunc_77()), 0x14);
    m_5e = true;
    m_64 = GetTickCountMs2();
    for (size_t i = 0; i < m_meshes68.GetCount(); i++)
        FUN_140a0b2a0(m_meshes68[i]);
    m_meshes68.RemoveAll();
    for (size_t i = 0; i < m_meshes88.GetCount(); i++)
        FUN_140a0b300(m_meshes88[i].operator->(), false);
}
