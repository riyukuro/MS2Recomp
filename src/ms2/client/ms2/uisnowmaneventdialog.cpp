// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Snowman event dialog.
// MS2-UNIT: client\ms2\uisnowmaneventdialog.cpp
// MS2-RANGE: 0x140e943b0-0x140e97670 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uisnowmaneventdialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uisnowmaneventdialog.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/aswindow.h"   // C3: ASDialog (an ASWindow: FUN_1422e6270/FUN_1422e6310)
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/commonfiles/itemgift.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/uirewardnotify.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/intervaltimer.h"  // C3: Unk_IntervalTimer::Check (0x140268870)
#include "ms2/placeholder/gameeventuservaluemanager.h"
#include "ms2/commonfiles/gameevent.h"
#include "ms2/commonfiles/gamerule.h"
#include "ms2/commonfiles/gameeventuservalue.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/placeholder/mstime.h"

namespace UICommon {
class CAlignmentInfo : public CPtred {
public:
    CAlignmentInfo(int alignment, float x, float y);
    void FUN_14015b020();
    int FUN_140159bc0();
    void FUN_140159ba0();
    void FUN_141901b20(int alignment, float x, float y);
    void FUN_141901880(MS2Ptr<AScript>, float, float, float, float);
    void FUN_1419015e0(class TiXmlElement* pNode);   // C3: uicommon.h's signatures
    bool FUN_141901660(class TiXmlElement* pNode);
    void FUN_141901c10(MS2Ptr<AScript>, int, int);
private:
    float m_x; float m_y; int m_align; float m_defaultX; float m_defaultY; int m_defaultAlign;
};
MS2_CHECK_SIZE(CAlignmentInfo, 0x30);
}
class Unk_BonusBar* GetGameEventUserValueManager();   // C3: was GetGameEventUserValueManager
void* GetGameRule();   // C3: was GetGameRule


__int64 GetServerTime();


class Unk_LtaTable {   // C3: gameeventcli.cpp's view of the user value table
public:
    CStringW GetStringValue(int, int, const CStringW&);
};
extern GameEventUserValue DAT_143ab2fc0;
void ParseIntArray(CStringW&, ATL::CAtlArray<int>&, const wchar_t*);
template<class T> bool Contains(T& values, int n) {
    if (values.GetCount() == 0) return false;
    {
        for (unsigned int i = 0; i < values.GetCount(); ++i) {
            if (values[i] == n) return true;
        }
    }
    return false;
}
class CItemData : public CPtred { public: CString GetIconPath(); };   // C3: member view (itemdata.cpp)
MS2Ptr<CItemData> FUN_14053f870(int);
void FUN_140710590(COutPacket&);

UIRewardNotify* FindRewardNotify(int);

// ASObj members used here only (the shared header lacks them).
class Unk_SnowmanDisplay { public: virtual void vfunc_0(); virtual void vfunc_1(int, int, int, int, int); };

int FUN_140d01040(CString&);
int XmlGetAttr(class TiXmlElement*, char const*, CStringA&);   // C3: was FUN_1408733e0
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
class CFileSystem* GetFileSystem();   // C3: was FUN_140166420
class TiXmlElement* FUN_140345b40(class TiXmlDocument*);   // C3: was FUN_140345b40

// @0x140e943b0
UISnowmanEventDialog::UISnowmanEventDialog()
{
    m_80 = 1;
    m_2c = 13;
    SetFlag(0, 1);
    m_alignment = 6;
    m_offsetX = 0;
    m_offsetY = 0;
    m_alignInfo = new UICommon::CAlignmentInfo(m_alignment, (float)m_offsetX, (float)m_offsetY);
    m_lastUpdate = 0;
}

// @0x140e94510
UISnowmanEventDialog::~UISnowmanEventDialog()
{
}

// @0x140e94560
CString UISnowmanEventDialog::GetTypeName()
{
    return "SnowmanEventDialog";
}
MS2_REPLACE_METHOD(0x140E94560, UISnowmanEventDialog, GetTypeName, 61, 0x753AD780);

// @0x140e945b0
int UISnowmanEventDialog::vfunc_65()
{
    if (!UIDialog::vfunc_65())
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140E945B0, UISnowmanEventDialog, vfunc_65, 37, 0xACC9F404);

// @0x140e945e0
void UISnowmanEventDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    reinterpret_cast<GameEventUserValueManager*>(GetGameEventUserValueManager())->UnregisterListener(0x6a4, Delegate<void(GameEventVariable*)>(this, &UISnowmanEventDialog::OnSnowflakeCountChanged));
    reinterpret_cast<GameEventUserValueManager*>(GetGameEventUserValueManager())->UnregisterListener(0x6a5, Delegate<void(GameEventVariable*)>(this, &UISnowmanEventDialog::OnDailyCompleteCountChanged));
    reinterpret_cast<GameEventUserValueManager*>(GetGameEventUserValueManager())->UnregisterListener(0x6a6, Delegate<void(GameEventVariable*)>(this, &UISnowmanEventDialog::OnAccumCompleteCountChanged));
    reinterpret_cast<GameEventUserValueManager*>(GetGameEventUserValueManager())->UnregisterListener(0x6a7, Delegate<void(GameEventVariable*)>(this, &UISnowmanEventDialog::FUN_140e96f60));
}
MS2_REPLACE_METHOD(0x140E945E0, UISnowmanEventDialog, vfunc_67, 645, 0x4676E7F6);

// @0x140e94870
void UISnowmanEventDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    reinterpret_cast<GameEventUserValueManager*>(GetGameEventUserValueManager())->RegisterListener(0x6a4, Delegate<void(GameEventVariable*)>(this, &UISnowmanEventDialog::OnSnowflakeCountChanged));
    reinterpret_cast<GameEventUserValueManager*>(GetGameEventUserValueManager())->RegisterListener(0x6a5, Delegate<void(GameEventVariable*)>(this, &UISnowmanEventDialog::OnDailyCompleteCountChanged));
    reinterpret_cast<GameEventUserValueManager*>(GetGameEventUserValueManager())->RegisterListener(0x6a6, Delegate<void(GameEventVariable*)>(this, &UISnowmanEventDialog::OnAccumCompleteCountChanged));
    reinterpret_cast<GameEventUserValueManager*>(GetGameEventUserValueManager())->RegisterListener(0x6a7, Delegate<void(GameEventVariable*)>(this, &UISnowmanEventDialog::FUN_140e96f60));
    MS2Ptr<SnowmanContext> context = ((CGameRule*)GetGameRule())->GetSnowman();
    if (context == NULL)
        return;
    m_timer.Init();
    FUN_140e954b0(context);
}
MS2_REPLACE_METHOD(0x140E94870, UISnowmanEventDialog, OnLoadComplete, 803, 0xED9A998C);

// @0x140e94ba0
void UISnowmanEventDialog::vfunc_45(Scaleform::GFx::Value* result, const CString& method, ASData* args)
{
    UIObject::vfunc_45(result, method, args);
    if ((method == "getTooltipItem")) {
        int id = args->PopUInt();
        int rank = args->PopUInt();
        void* owner = WorldService::GetInstance()->FUN_141bd0cc0();
        if (owner) {
            ASTooltip tooltip(owner, 0x20, 2);
            if (tooltip.FUN_1409e1770(id, rank))
                *result = tooltip.GetValue();
        }
    }
}
MS2_REPLACE_METHOD(0x140E94BA0, UISnowmanEventDialog, vfunc_45, 260, 0x71A5F12B);

// @0x140e94cb0
int UISnowmanEventDialog::vfunc_28(const char* method, const Scaleform::GFx::Value* args, unsigned int count)
{
    if (UIDialog::vfunc_28(method, args, count))
        return 1;
    MS2Ptr<SnowmanContext> context = ((CGameRule*)GetGameRule())->GetSnowman();
    if (context == NULL)
        return 0;
    if (!_stricmp("OnDailyCompleteReward", method)) {
        ASData data;
        if (!data.SetArgsIfAny(args, count)) {
            MS2_ASSERT_AT(134, "data.Parsing(args, argCount)" && 0);
            return 0;
        }
        int n = data.PopUInt();
        SendEventRewardMode12(n);
        return 1;
    } else if (!_stricmp("OnAccumCompleteReward", method)) {
        ASData data;
        if (!data.SetArgsIfAny(args, count)) {
            MS2_ASSERT_AT(144, "data.Parsing(args, argCount)" && 0);
            return 0;
        }
        int n = data.PopUInt();
        SendEventRewardMode13(n);
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140E94CB0, UISnowmanEventDialog, vfunc_28, 635, 0x35685B82);

// @0x140e94f40
void UISnowmanEventDialog::vfunc_72()
{
    UIDialog::vfunc_72();
    if (m_30.IsNull())
        return;
    if (m_timer.Check(1000) == 0)
        return;
    __int64 now = GetServerTime();
    if (IsEarlierDay(CMsTime(m_lastUpdate), CMsTime(now), 0))
        UpdateInfo();
}
MS2_REPLACE_METHOD(0x140E94F40, UISnowmanEventDialog, vfunc_72, 191, 0x3C07D89C);

// @0x140e95010
void UISnowmanEventDialog::vfunc_43()
{
    UIDialog::vfunc_43();
    if (m_60 && !m_78)
        m_alignInfo->FUN_141901b20(m_alignment, (float)m_offsetX, (float)m_offsetY);
    ApplyAlign();
}
MS2_REPLACE_METHOD(0x140E95010, UISnowmanEventDialog, vfunc_43, 150, 0xCED83769);

// @0x140e950b0
void UISnowmanEventDialog::vfunc_44(int a1, int a2, int a3, int* pWidth, int* pHeight)
{
    if (FUN_1422dc430() == 0)
        return;
    MS2Ptr<ASDisplayObject> pRoot = FUN_1422dba50();
    if (pRoot.get()) {
        GetDialogSize(pWidth, pHeight);
        reinterpret_cast<Unk_SnowmanDisplay*>(pRoot.operator->())->vfunc_1(a1, a2, a3, *pWidth, *pHeight);
    }
}
MS2_REPLACE_METHOD(0x140E950B0, UISnowmanEventDialog, vfunc_44, 197, 0x2D63DD42);

// @0x140e95180
int UISnowmanEventDialog::vfunc_53(void* cfg)
{
    if (UIDialog::vfunc_53(cfg)) {
        ASDialog* dialog = dynamic_cast<ASDialog*>((AScript*)m_30);
        if ((m_alignInfo.get() ? true : false) && dialog) {
            float x = (float)reinterpret_cast<ASDisplayObject*>(dialog)->FUN_1422c1500();
            float y = (float)reinterpret_cast<ASDisplayObject*>(dialog)->FUN_1422c1530();
            m_alignInfo->FUN_141901880(m_30, (float)dialog->GetWindowWidth(), (float)dialog->GetWindowHeight(), x, y);
            m_alignInfo->FUN_1419015e0((class TiXmlElement*)cfg);
        }
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140E95180, UISnowmanEventDialog, vfunc_53, 439, 0x6623F540);

// @0x140e95340
int UISnowmanEventDialog::vfunc_54(void* cfg)
{
    if (UIDialog::vfunc_54(cfg)) {
        ASDialog* dialog = dynamic_cast<ASDialog*>((AScript*)m_30);
        if ((m_alignInfo.get() ? true : false) && dialog) {
            if (!m_alignInfo->FUN_141901660((class TiXmlElement*)cfg))
                m_alignInfo->FUN_141901b20(m_alignment, (float)m_offsetX, (float)m_offsetY);
        }
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140E95340, UISnowmanEventDialog, vfunc_54, 299, 0xDA323820);

// @0x140e95480
void UISnowmanEventDialog::vfunc_19()
{
    m_78 = 0;
    UISwfEntity::vfunc_19();
}
MS2_REPLACE_METHOD(0x140E95480, UISnowmanEventDialog, vfunc_19, 36, 0x61A75A82);

// @0x140e954b0
void UISnowmanEventDialog::FUN_140e954b0(MS2Ptr<SnowmanContext> context)
{
    if (context.IsNull()) {
        MS2_ASSERT_AT(380, "context" && 0);
        return;
    }
    if (m_30.IsNull()) {
        MS2_ASSERT_AT(381, "m_ascript" && 0);
        return;
    }
    ASObj info(2);
    ASArray snowmans(2);
    for (size_t i = 0; i < context->m_snowmen.GetCount(); ++i) {
        MS2Ptr<SnowmanContext::Snowman> snowman = context->m_snowmen[i];
        if (snowman.IsNull()) {
            MS2_ASSERT_AT(389, "snowman" && 0);
            continue;
        }
        ASObj row(2);
        row.FUN_140e846b0("index", i);
        row.SetIntMember("curSnowflakeCount", GetCurSnowflakeCount((int)i));
        row.SetIntMember("maxSnowflakeCount", snowman->m_18);
        row.SetIntMember("curDailyCompleteCount", GetCurDailyCompleteCount((int)i));
        row.SetIntMember("maxDailyCompleteCount", snowman->m_1c);
        row.SetIntMember("curAccumCompleteCount", GetCurAccumCompleteCount((int)i));
        row.SetIntMember("maxAccumCompleteCount", snowman->m_20);
        row.SetBoolMember("accumCompleteRewardReceived", IsAccumRewardReceived((int)i));
        {
            ItemEntity item;
            if (!snowman->m_items.IsEmpty())
                item = snowman->m_items[0];
            ASObj reward(2);
            reward.SetMemberUInt("itemID", item.m_itemId);
            reward.FUN_1409adc90("itemRank", item.vfunc_o18_1());
            reward.SetMemberUInt("itemCount", item.m_count);
            reward.SetStringMember("iconPath", GetItemIconPath(item.m_itemId));
            row.FUN_1409eb270("dailyCompleteReward", reward);
        }
        {
            ItemEntity item;
            if (!snowman->m_bonusItems.IsEmpty())
                item = snowman->m_bonusItems[0];
            ASObj reward(2);
            reward.SetMemberUInt("itemID", item.m_itemId);
            reward.FUN_1409adc90("itemRank", item.vfunc_o18_1());
            reward.SetMemberUInt("itemCount", item.m_count);
            reward.SetStringMember("iconPath", GetItemIconPath(item.m_itemId));
            row.FUN_1409eb270("accumCompleteReward", reward);
        }
        snowmans.PushValue(row.GetValue());
    }
    info.FUN_1409adbe0("snowmans", snowmans.GetValue());
    info.SetWStringMember("thema", context->m_strTitle);
    m_30->Invoke("init", info.GetValue());
    m_lastUpdate = GetServerTime();
}
MS2_REPLACE_METHOD(0x140E954B0, UISnowmanEventDialog, FUN_140e954b0, 1819, 0x9131C474);

// @0x140e95be0
void UISnowmanEventDialog::SendEventRewardMode12(int index)
{
    MS2Ptr<SnowmanContext> context = ((CGameRule*)GetGameRule())->GetSnowman();
    if (context == NULL)
        return;
    if (index < 0 || index > (int)context->m_snowmen.GetCount() - 1) {
        MS2_ASSERT_AT(350, "CHECK_RANGE(index, 0, (int)context->m_snowmans.GetCount() - 1)" && 0);
        return;
    }
    MS2Ptr<SnowmanContext::Snowman> snowman = context->m_snowmen[index];
    if (snowman.IsNull()) {
        MS2_ASSERT_AT(353, "snowman" && 0);
        return;
    }
    COutPacket packet(static_cast<int>(SendOp::EventReward), 0);
    packet.Encode1(0xc);
    packet.Encode1((unsigned char)index);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x140E95BE0, UISnowmanEventDialog, SendEventRewardMode12, 425, 0xF738D945);

// @0x140e95d90
void UISnowmanEventDialog::SendEventRewardMode13(int index)
{
    MS2Ptr<SnowmanContext> context = ((CGameRule*)GetGameRule())->GetSnowman();
    if (context == NULL)
        return;
    if (index < 0 || index > (int)context->m_snowmen.GetCount() - 1) {
        MS2_ASSERT_AT(367, "CHECK_RANGE(index, 0, (int)context->m_snowmans.GetCount() - 1)" && 0);
        return;
    }
    MS2Ptr<SnowmanContext::Snowman> snowman = context->m_snowmen[index];
    if (snowman.IsNull()) {
        MS2_ASSERT_AT(370, "snowman" && 0);
        return;
    }
    COutPacket packet(static_cast<int>(SendOp::EventReward), 0);
    packet.Encode1(0xd);
    packet.Encode1((unsigned char)index);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x140E95D90, UISnowmanEventDialog, SendEventRewardMode13, 425, 0xFB46BF75);

// @0x140e95f40
int UISnowmanEventDialog::GetCurSnowflakeCount(int index)
{
    MS2Ptr<SnowmanContext> context = ((CGameRule*)GetGameRule())->GetSnowman();
    if (context == NULL)
        return 0;
    CStringW values = reinterpret_cast<Unk_LtaTable&>(DAT_143ab2fc0).GetStringValue(0x6a4, context->m_eventId, L"");
    ATL::CAtlArray<int> ints;
    ParseIntArray(values, ints, L",");
    BOOL valid;
    if (index >= 0 && index <= (int)ints.GetCount() - 1)
        valid = TRUE;
    else
        valid = FALSE;
    if (!valid)
        return 0;
    return ints[index];
}
MS2_REPLACE_METHOD(0x140E95F40, UISnowmanEventDialog, GetCurSnowflakeCount, 379, 0x8CE80314);

// @0x140e960d0
int UISnowmanEventDialog::GetCurDailyCompleteCount(int index)
{
    MS2Ptr<SnowmanContext> context = ((CGameRule*)GetGameRule())->GetSnowman();
    if (context == NULL)
        return 0;
    CStringW values = reinterpret_cast<Unk_LtaTable&>(DAT_143ab2fc0).GetStringValue(0x6a5, context->m_eventId, L"");
    ATL::CAtlArray<int> ints;
    ParseIntArray(values, ints, L",");
    BOOL valid;
    if (index >= 0 && index <= (int)ints.GetCount() - 1)
        valid = TRUE;
    else
        valid = FALSE;
    if (!valid)
        return 0;
    return ints[index];
}
MS2_REPLACE_METHOD(0x140E960D0, UISnowmanEventDialog, GetCurDailyCompleteCount, 379, 0x012AD364);

// @0x140e96260
int UISnowmanEventDialog::GetCurAccumCompleteCount(int index)
{
    MS2Ptr<SnowmanContext> context = ((CGameRule*)GetGameRule())->GetSnowman();
    if (context == NULL)
        return 0;
    CStringW values = reinterpret_cast<Unk_LtaTable&>(DAT_143ab2fc0).GetStringValue(0x6a6, context->m_eventId, L"");
    ATL::CAtlArray<int> ints;
    ParseIntArray(values, ints, L",");
    BOOL valid;
    if (index >= 0 && index <= (int)ints.GetCount() - 1)
        valid = TRUE;
    else
        valid = FALSE;
    if (!valid)
        return 0;
    return ints[index];
}
MS2_REPLACE_METHOD(0x140E96260, UISnowmanEventDialog, GetCurAccumCompleteCount, 379, 0xA99A1D27);

// @0x140e963f0
bool UISnowmanEventDialog::IsAccumRewardReceived(int index)
{
    MS2Ptr<SnowmanContext> context = ((CGameRule*)GetGameRule())->GetSnowman();
    if (context == NULL)
        return false;
    ATL::CAtlArray<int> ints;
    CStringW values = reinterpret_cast<Unk_LtaTable&>(DAT_143ab2fc0).GetStringValue(0x6a7, context->m_eventId, L"");
    ParseIntArray(values, ints, L",");
    return Contains(ints, index);
}
MS2_REPLACE_METHOD(0x140E963F0, UISnowmanEventDialog, IsAccumRewardReceived, 266, 0x0AF304C2);

// @0x140e96500
CString UISnowmanEventDialog::GetItemIconPath(int itemId)
{
    if (!itemId)
        return "";
    MS2Ptr<CItemData> item = FUN_14053f870(itemId);
    if (item.IsNull())
        return "";
    return item->GetIconPath();
}
MS2_REPLACE_METHOD(0x140E96500, UISnowmanEventDialog, GetItemIconPath, 211, 0x675DA32B);

// @0x140e965e0
void UISnowmanEventDialog::UpdateInfo()
{
    if (m_30.IsNull()) {
        MS2_ASSERT_AT(234, "m_ascript" && 0);
        return;
    }
    MS2Ptr<SnowmanContext> context = ((CGameRule*)GetGameRule())->GetSnowman();
    if (context == NULL)
        return;
    ASObj info(2);
    ASArray snowmans(2);
    for (size_t i = 0; i < context->m_snowmen.GetCount(); ++i) {
        ASObj row(2);
        row.FUN_140e846b0("index", i);
        row.SetIntMember("curSnowflakeCount", GetCurSnowflakeCount((int)i));
        row.SetIntMember("curDailyCompleteCount", GetCurDailyCompleteCount((int)i));
        row.SetIntMember("curAccumCompleteCount", GetCurAccumCompleteCount((int)i));
        row.SetBoolMember("accumCompleteRewardReceived", IsAccumRewardReceived((int)i));
        snowmans.PushValue(row.GetValue());
    }
    info.FUN_1409adbe0("snowmans", snowmans.GetValue());
    m_30->Invoke("updateInfo", info.GetValue());
    m_lastUpdate = GetServerTime();
}
MS2_REPLACE_METHOD(0x140E965E0, UISnowmanEventDialog, UpdateInfo, 784, 0xAF323AEA);

// @0x140e96900
void UISnowmanEventDialog::GetDialogSize(int* width, int* height)
{
    if (m_30 == NULL)
        return;
    ASDialog* dialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (dialog) {
        *width = dialog->GetWindowWidth();
        *height = dialog->GetWindowHeight();
    }
}
MS2_REPLACE_METHOD(0x140E96900, UISnowmanEventDialog, GetDialogSize, 148, 0x464891AD);

// @0x140e969a0
void UISnowmanEventDialog::ApplyAlign()
{
    if (m_alignInfo.IsNull()) {
        MS2_ASSERT_AT(502, "m_pAlignInfo" && 0);
        return;
    }
    int width = 0;
    int height = 0;
    GetDialogSize(&width, &height);
    m_alignInfo->FUN_141901c10(m_30, width, height);
}
MS2_REPLACE_METHOD(0x140E969A0, UISnowmanEventDialog, ApplyAlign, 223, 0x48771CFC);

// @0x140e96a90
void UISnowmanEventDialog::FUN_140e96a90(const CStringW& path)
{
    TiXmlDocument doc;
    if (!GetFileSystem()->LoadXmlFromString(&doc, path)) {
        MS2_ASSERT_AT(160, FALSE);
        return;
    }
    void* root = ((void*)FUN_140345b40((class TiXmlDocument*)(&doc)));
    if (!root) {
        MS2_ASSERT_AT(167, FALSE);
        return;
    }
    void* node = ((void*)FUN_140345b40((class TiXmlDocument*)(root)));
    if (!node) {
        MS2_ASSERT_AT(174, FALSE);
        return;
    }
    CString align;
    XmlGetAttr((class TiXmlElement*)(node), "align", *(&align));
    m_alignment = FUN_140d01040(align);
    XmlGetAttr((class TiXmlElement*)(node), "offsetX", *(int*)(&m_offsetX));
    XmlGetAttr((class TiXmlElement*)(node), "offsetY", *(int*)(&m_offsetY));
    m_60 = 1;
}
MS2_REPLACE_METHOD(0x140E96A90, UISnowmanEventDialog, FUN_140e96a90, 431, 0x570BF6B3);

// @0x140e96c50
// The exe returns no value on any path (eax holds whatever was last loaded); the only caller ignores it.
#pragma warning(push)
#pragma warning(disable : 4716)
int UISnowmanEventDialog::FUN_140e96c50(int type, CInPacket& packet)
{
    if (m_30.IsNull()) {
        MS2_ASSERT_AT(190, "m_ascript" && 0);
    } else {
        switch (type) {
        case 0xc: {
            UIRewardNotify* popup = FindRewardNotify(20061);
            if (popup == 0)
                break;
            int count = packet.ReadInt32();
            for (int i = 0; i < count; ++i) {
                int id = packet.ReadInt32();
                int num = (unsigned short)packet.ReadInt16();
                popup->FUN_141abf6e0(id, num);
            }
            break;
        }
        case 0xd: {
            UIRewardNotify* popup = FindRewardNotify(20061);
            if (popup == 0)
                break;
            int count = packet.ReadInt32();
            for (int i = 0; i < count; ++i) {
                int id = packet.ReadInt32();
                int num = (unsigned short)packet.ReadInt16();
                popup->FUN_141abf6e0(id, num);
            }
            break;
        }
        default:
            MS2_ASSERT_AT(227, 0);
        }
    }
#ifdef __clang__
    return 0;   // clang would treat the fall-off as unreachable
#endif
}
#pragma warning(pop)
MS2_REPLACE_METHOD(0x140E96C50, UISnowmanEventDialog, FUN_140e96c50, 622, 0x872ADDA2);

// @0x140e96ed0
void UISnowmanEventDialog::OnSnowflakeCountChanged(GameEventVariable*) { UpdateInfo(); }
MS2_REPLACE_METHOD(0x140E96ED0, UISnowmanEventDialog, OnSnowflakeCountChanged, 29, 0x5E788497);
// @0x140e96f00
void UISnowmanEventDialog::OnDailyCompleteCountChanged(GameEventVariable*) { UpdateInfo(); }
MS2_REPLACE_METHOD(0x140E96F00, UISnowmanEventDialog, OnDailyCompleteCountChanged, 29, 0xB2FF4CA7);
// @0x140e96f30
void UISnowmanEventDialog::OnAccumCompleteCountChanged(GameEventVariable*) { UpdateInfo(); }
MS2_REPLACE_METHOD(0x140E96F30, UISnowmanEventDialog, OnAccumCompleteCountChanged, 29, 0x13444DB7);
// @0x140e96f60
void UISnowmanEventDialog::FUN_140e96f60(GameEventVariable*) { UpdateInfo(); }
MS2_REPLACE_METHOD(0x140E96F60, UISnowmanEventDialog, FUN_140e96f60, 29, 0x69C2AD47);

// @0x140e973f0
int UISnowmanEventDialog::vfunc_48()
{
    return 20317;
}
MS2_REPLACE_METHOD(0x140E973F0, UISnowmanEventDialog, vfunc_48, 11, 0xAF46DE0F);
