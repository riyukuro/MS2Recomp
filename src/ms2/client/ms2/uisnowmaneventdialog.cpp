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
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/commonfiles/itemgift.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

namespace UICommon {
class CAlignmentInfo : public CPtred {
public:
    CAlignmentInfo(int alignment, float x, float y);
    void FUN_14015b020();
    int FUN_140159bc0();
    void FUN_140159ba0();
    void FUN_141901b20(int alignment, float x, float y);
    void FUN_141901880(MS2Ptr<AScript>, float, float, float, float);
    void FUN_1419015e0(void*);
    bool FUN_141901660(void*);
    void FUN_141901c10(MS2Ptr<AScript>, int, int);
private:
    float m_x; float m_y; int m_align; float m_defaultX; float m_defaultY; int m_defaultAlign;
};
MS2_CHECK_SIZE(CAlignmentInfo, 0x30);
}
class Unk_SnowmanEventManager {
public:
    void FUN_140da5430(int id, Delegate<void(GameEventVariable*)> handler);
    void FUN_140da5490(int id, Delegate<void(GameEventVariable*)> handler);
};
Unk_SnowmanEventManager* FUN_140933220();
class Unk_SnowmanContextManager {
public:
    MS2Ptr<Unk_SnowmanContext> FUN_14047d050();
};
Unk_SnowmanContextManager* FUN_1401c0d90();

class ASDialog : public AScript {
public:
    int FUN_1422c1500();
    int FUN_1422c1530();
    int FUN_1422e6270();
    int FUN_1422e6310();
};

class Unk_SnowmanUIManager { public: void* FUN_141bd0cc0(); };
Unk_SnowmanUIManager* FUN_1403ed2d0();
bool FUN_140184310(const CString&, const char*);

// Time value (ctor 0x1406c47a0); the declared copy ctor forces by-pointer passing.
class Unk_Time
{
public:
    Unk_Time(__int64 n);
    Unk_Time(const Unk_Time& o);
private:
    __int64 m_0; __int64 m_8;
};
bool FUN_14086ab70(Unk_Time a, Unk_Time b, int nBaseHour);
__int64 FUN_140869440();

// The item lists inside a snowman record: +8 is the first element.
class Unk_SnowmanItems {
public:
    bool IsEmpty() const { return m_first == 0; }
    ItemEntity& FUN_140410df0(size_t index);
private:
    void* m_0; ItemEntity* m_first; void* m_10; void* m_18;
};
MS2_CHECK_SIZE(Unk_SnowmanItems, 0x20);
void* FUN_1404efe60(ItemEntity* dest, const ItemEntity* source);

class Unk_Snowman : public CPtred {
public:
    int m_maxSnowflakeCount;
    int m_maxDailyCompleteCount;
    int m_maxAccumCompleteCount;
    int m_pad_24;
    Unk_SnowmanItems m_dailyRewards;
    Unk_SnowmanItems m_accumRewards;
};
MS2_CHECK_OFFSET(Unk_Snowman, m_maxSnowflakeCount, 0x18);
MS2_CHECK_OFFSET(Unk_Snowman, m_dailyRewards, 0x28);
MS2_CHECK_OFFSET(Unk_Snowman, m_accumRewards, 0x48);

class Unk_SnowmanArray {
public:
    size_t FUN_140412ea0() const;
    MS2Ptr<Unk_Snowman>& FUN_140410f70(size_t index);
private:
    void* m_0; void* m_8; void* m_10; void* m_18;
};
MS2_CHECK_SIZE(Unk_SnowmanArray, 0x20);

class Unk_SnowmanContext : public CPtred {
public:
    int m_id;
    int m_pad_1c;
    Unk_SnowmanArray m_snowmans;
    CStringW m_thema;
};
MS2_CHECK_OFFSET(Unk_SnowmanContext, m_id, 0x18);
MS2_CHECK_OFFSET(Unk_SnowmanContext, m_snowmans, 0x20);
MS2_CHECK_OFFSET(Unk_SnowmanContext, m_thema, 0x40);

class Unk_SnowmanStrings {
public:
    CStringW FUN_140c6d980(int, int, const CStringW&);
};
extern Unk_SnowmanStrings g_snowmanStrings;
void FUN_1401d9a30(const CStringW&, ATL::CAtlArray<int>&, const wchar_t*);
template<class T> bool Contains(T& values, int n) {
    if (values.GetCount() == 0) return false;
    {
        for (unsigned int i = 0; i < values.GetCount(); ++i) {
            if (values[i] == n) return true;
        }
    }
    return false;
}
class Unk_SnowmanItem : public CPtred { public: CString FUN_14053fdd0(); };
MS2Ptr<Unk_SnowmanItem> FUN_14053f870(int);
void FUN_140710590(COutPacket&);

class Unk_SnowmanPopup { public: void FUN_141abf6e0(int, unsigned short); };
Unk_SnowmanPopup* FUN_140938cd0(int);

// ASObj members used here only (the shared header lacks them).
class Unk_SnowmanDisplay { public: virtual void vfunc_0(); virtual void vfunc_1(int, int, int, int, int); };

int FUN_140d01040(CString&);
int FUN_1408733e0(void*, const char*, CString*);
int FUN_1408731e0(void*, const char*, int*);
void* FUN_140166420();
int FUN_140397ab0(void*, TiXmlDocument*, const CStringW&);
void* FUN_140345b40(const void*);

// @0x140e943b0
UISnowmanEventDialog::UISnowmanEventDialog()
{
    m_80 = 1;
    m_2c = 13;
    FUN_141925e70(0, 1);
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
    FUN_140933220()->FUN_140da5490(0x6a4, Delegate<void(GameEventVariable*)>(this, &UISnowmanEventDialog::FUN_140e96ed0));
    FUN_140933220()->FUN_140da5490(0x6a5, Delegate<void(GameEventVariable*)>(this, &UISnowmanEventDialog::FUN_140e96f00));
    FUN_140933220()->FUN_140da5490(0x6a6, Delegate<void(GameEventVariable*)>(this, &UISnowmanEventDialog::FUN_140e96f30));
    FUN_140933220()->FUN_140da5490(0x6a7, Delegate<void(GameEventVariable*)>(this, &UISnowmanEventDialog::FUN_140e96f60));
}
MS2_REPLACE_METHOD(0x140E945E0, UISnowmanEventDialog, vfunc_67, 645, 0x4676E7F6);

// @0x140e94870
void UISnowmanEventDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_140933220()->FUN_140da5430(0x6a4, Delegate<void(GameEventVariable*)>(this, &UISnowmanEventDialog::FUN_140e96ed0));
    FUN_140933220()->FUN_140da5430(0x6a5, Delegate<void(GameEventVariable*)>(this, &UISnowmanEventDialog::FUN_140e96f00));
    FUN_140933220()->FUN_140da5430(0x6a6, Delegate<void(GameEventVariable*)>(this, &UISnowmanEventDialog::FUN_140e96f30));
    FUN_140933220()->FUN_140da5430(0x6a7, Delegate<void(GameEventVariable*)>(this, &UISnowmanEventDialog::FUN_140e96f60));
    MS2Ptr<Unk_SnowmanContext> context = FUN_1401c0d90()->FUN_14047d050();
    if (context == NULL)
        return;
    m_timer.FUN_140268840();
    FUN_140e954b0(context);
}
MS2_REPLACE_METHOD(0x140E94870, UISnowmanEventDialog, OnLoadComplete, 803, 0xED9A998C);

// @0x140e94ba0
void UISnowmanEventDialog::vfunc_45(Scaleform::GFx::Value* result, const CString& method, ASData* args)
{
    UIObject::vfunc_45(result, method, args);
    if (FUN_140184310(method, "getTooltipItem")) {
        int id = args->FUN_1422b8b10();
        int rank = args->FUN_1422b8b10();
        void* owner = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (owner) {
            ASTooltip tooltip(owner, 0x20, 2);
            if (tooltip.FUN_1409e1770(id, rank))
                *result = tooltip.FUN_1422bb870();
        }
    }
}
MS2_REPLACE_METHOD(0x140E94BA0, UISnowmanEventDialog, vfunc_45, 260, 0x71A5F12B);

// @0x140e94cb0
int UISnowmanEventDialog::vfunc_28(const char* method, const Scaleform::GFx::Value* args, unsigned int count)
{
    if (UIDialog::vfunc_28(method, args, count))
        return 1;
    MS2Ptr<Unk_SnowmanContext> context = FUN_1401c0d90()->FUN_14047d050();
    if (context == NULL)
        return 0;
    if (!_stricmp("OnDailyCompleteReward", method)) {
        ASData data;
        if (!data.FUN_1422b9620(args, count)) {
            MS2_ASSERT_AT(134, "data.Parsing(args, argCount)" && 0);
            return 0;
        }
        int n = data.FUN_1422b8b10();
        SendEventRewardMode12(n);
        return 1;
    } else if (!_stricmp("OnAccumCompleteReward", method)) {
        ASData data;
        if (!data.FUN_1422b9620(args, count)) {
            MS2_ASSERT_AT(144, "data.Parsing(args, argCount)" && 0);
            return 0;
        }
        int n = data.FUN_1422b8b10();
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
    if (m_timer.FUN_140268870(1000) == 0)
        return;
    __int64 now = FUN_140869440();
    if (FUN_14086ab70(Unk_Time(m_lastUpdate), Unk_Time(now), 0))
        FUN_140e965e0();
}
MS2_REPLACE_METHOD(0x140E94F40, UISnowmanEventDialog, vfunc_72, 191, 0x3C07D89C);

// @0x140e95010
void UISnowmanEventDialog::vfunc_43()
{
    UIDialog::vfunc_43();
    if (m_60 && !m_78)
        m_alignInfo->FUN_141901b20(m_alignment, (float)m_offsetX, (float)m_offsetY);
    FUN_140e969a0();
}
MS2_REPLACE_METHOD(0x140E95010, UISnowmanEventDialog, vfunc_43, 150, 0xCED83769);

// @0x140e950b0
void UISnowmanEventDialog::vfunc_44(int a1, int a2, int a3, int* pWidth, int* pHeight)
{
    if (FUN_1422dc430() == 0)
        return;
    MS2Ptr<ASDisplayObject> pRoot = FUN_1422dba50();
    if (pRoot.get()) {
        FUN_140e96900(pWidth, pHeight);
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
            float x = (float)dialog->FUN_1422c1500();
            float y = (float)dialog->FUN_1422c1530();
            m_alignInfo->FUN_141901880(m_30, (float)dialog->FUN_1422e6310(), (float)dialog->FUN_1422e6270(), x, y);
            m_alignInfo->FUN_1419015e0(cfg);
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
            if (!m_alignInfo->FUN_141901660(cfg))
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
void UISnowmanEventDialog::FUN_140e954b0(MS2Ptr<Unk_SnowmanContext> context)
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
    for (size_t i = 0; i < context->m_snowmans.FUN_140412ea0(); ++i) {
        MS2Ptr<Unk_Snowman> snowman = context->m_snowmans.FUN_140410f70(i);
        if (snowman.IsNull()) {
            MS2_ASSERT_AT(389, "snowman" && 0);
            continue;
        }
        ASObj row(2);
        row.FUN_140e846b0("index", i);
        row.FUN_1407cb9c0("curSnowflakeCount", FUN_140e95f40((int)i));
        row.FUN_1407cb9c0("maxSnowflakeCount", snowman->m_maxSnowflakeCount);
        row.FUN_1407cb9c0("curDailyCompleteCount", FUN_140e960d0((int)i));
        row.FUN_1407cb9c0("maxDailyCompleteCount", snowman->m_maxDailyCompleteCount);
        row.FUN_1407cb9c0("curAccumCompleteCount", FUN_140e96260((int)i));
        row.FUN_1407cb9c0("maxAccumCompleteCount", snowman->m_maxAccumCompleteCount);
        row.FUN_1407cbbe0("accumCompleteRewardReceived", FUN_140e963f0((int)i));
        {
            ItemEntity item;
            if (!snowman->m_dailyRewards.IsEmpty())
                FUN_1404efe60(&item, &snowman->m_dailyRewards.FUN_140410df0(0));
            ASObj reward(2);
            reward.FUN_1409c0d20("itemID", item.m_itemId);
            reward.FUN_1409adc90("itemRank", item.vfunc_o18_1());
            reward.FUN_1409c0d20("itemCount", item.m_count);
            reward.FUN_1407cba60("iconPath", FUN_140e96500(item.m_itemId));
            row.FUN_1409eb270("dailyCompleteReward", reward);
        }
        {
            ItemEntity item;
            if (!snowman->m_accumRewards.IsEmpty())
                FUN_1404efe60(&item, &snowman->m_accumRewards.FUN_140410df0(0));
            ASObj reward(2);
            reward.FUN_1409c0d20("itemID", item.m_itemId);
            reward.FUN_1409adc90("itemRank", item.vfunc_o18_1());
            reward.FUN_1409c0d20("itemCount", item.m_count);
            reward.FUN_1407cba60("iconPath", FUN_140e96500(item.m_itemId));
            row.FUN_1409eb270("accumCompleteReward", reward);
        }
        snowmans.FUN_1422bc050(row.FUN_1422bb870());
    }
    info.FUN_1409adbe0("snowmans", snowmans.FUN_1422bb870());
    info.FUN_1407cbb20("thema", context->m_thema);
    m_30->Invoke("init", info.FUN_1422bb870());
    m_lastUpdate = FUN_140869440();
}
MS2_REPLACE_METHOD(0x140E954B0, UISnowmanEventDialog, FUN_140e954b0, 1819, 0x9131C474);

// @0x140e95be0
void UISnowmanEventDialog::SendEventRewardMode12(int index)
{
    MS2Ptr<Unk_SnowmanContext> context = FUN_1401c0d90()->FUN_14047d050();
    if (context == NULL)
        return;
    if (index < 0 || index > (int)context->m_snowmans.FUN_140412ea0() - 1) {
        MS2_ASSERT_AT(350, "CHECK_RANGE(index, 0, (int)context->m_snowmans.GetCount() - 1)" && 0);
        return;
    }
    MS2Ptr<Unk_Snowman> snowman = context->m_snowmans.FUN_140410f70(index);
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
    MS2Ptr<Unk_SnowmanContext> context = FUN_1401c0d90()->FUN_14047d050();
    if (context == NULL)
        return;
    if (index < 0 || index > (int)context->m_snowmans.FUN_140412ea0() - 1) {
        MS2_ASSERT_AT(367, "CHECK_RANGE(index, 0, (int)context->m_snowmans.GetCount() - 1)" && 0);
        return;
    }
    MS2Ptr<Unk_Snowman> snowman = context->m_snowmans.FUN_140410f70(index);
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
int UISnowmanEventDialog::FUN_140e95f40(int index)
{
    MS2Ptr<Unk_SnowmanContext> context = FUN_1401c0d90()->FUN_14047d050();
    if (context == NULL)
        return 0;
    CStringW values = g_snowmanStrings.FUN_140c6d980(0x6a4, context->m_id, L"");
    ATL::CAtlArray<int> ints;
    FUN_1401d9a30(values, ints, L",");
    BOOL valid;
    if (index >= 0 && index <= (int)ints.GetCount() - 1)
        valid = TRUE;
    else
        valid = FALSE;
    if (!valid)
        return 0;
    return ints[index];
}
MS2_REPLACE_METHOD(0x140E95F40, UISnowmanEventDialog, FUN_140e95f40, 379, 0x8CE80314);

// @0x140e960d0
int UISnowmanEventDialog::FUN_140e960d0(int index)
{
    MS2Ptr<Unk_SnowmanContext> context = FUN_1401c0d90()->FUN_14047d050();
    if (context == NULL)
        return 0;
    CStringW values = g_snowmanStrings.FUN_140c6d980(0x6a5, context->m_id, L"");
    ATL::CAtlArray<int> ints;
    FUN_1401d9a30(values, ints, L",");
    BOOL valid;
    if (index >= 0 && index <= (int)ints.GetCount() - 1)
        valid = TRUE;
    else
        valid = FALSE;
    if (!valid)
        return 0;
    return ints[index];
}
MS2_REPLACE_METHOD(0x140E960D0, UISnowmanEventDialog, FUN_140e960d0, 379, 0x012AD364);

// @0x140e96260
int UISnowmanEventDialog::FUN_140e96260(int index)
{
    MS2Ptr<Unk_SnowmanContext> context = FUN_1401c0d90()->FUN_14047d050();
    if (context == NULL)
        return 0;
    CStringW values = g_snowmanStrings.FUN_140c6d980(0x6a6, context->m_id, L"");
    ATL::CAtlArray<int> ints;
    FUN_1401d9a30(values, ints, L",");
    BOOL valid;
    if (index >= 0 && index <= (int)ints.GetCount() - 1)
        valid = TRUE;
    else
        valid = FALSE;
    if (!valid)
        return 0;
    return ints[index];
}
MS2_REPLACE_METHOD(0x140E96260, UISnowmanEventDialog, FUN_140e96260, 379, 0xA99A1D27);

// @0x140e963f0
bool UISnowmanEventDialog::FUN_140e963f0(int index)
{
    MS2Ptr<Unk_SnowmanContext> context = FUN_1401c0d90()->FUN_14047d050();
    if (context == NULL)
        return false;
    ATL::CAtlArray<int> ints;
    CStringW values = g_snowmanStrings.FUN_140c6d980(0x6a7, context->m_id, L"");
    FUN_1401d9a30(values, ints, L",");
    return Contains(ints, index);
}
MS2_REPLACE_METHOD(0x140E963F0, UISnowmanEventDialog, FUN_140e963f0, 266, 0x0AF304C2);

// @0x140e96500
CString UISnowmanEventDialog::FUN_140e96500(int itemId)
{
    if (!itemId)
        return "";
    MS2Ptr<Unk_SnowmanItem> item = FUN_14053f870(itemId);
    if (item.IsNull())
        return "";
    return item->FUN_14053fdd0();
}
MS2_REPLACE_METHOD(0x140E96500, UISnowmanEventDialog, FUN_140e96500, 211, 0x675DA32B);

// @0x140e965e0
void UISnowmanEventDialog::FUN_140e965e0()
{
    if (m_30.IsNull()) {
        MS2_ASSERT_AT(234, "m_ascript" && 0);
        return;
    }
    MS2Ptr<Unk_SnowmanContext> context = FUN_1401c0d90()->FUN_14047d050();
    if (context == NULL)
        return;
    ASObj info(2);
    ASArray snowmans(2);
    for (size_t i = 0; i < context->m_snowmans.FUN_140412ea0(); ++i) {
        ASObj row(2);
        row.FUN_140e846b0("index", i);
        row.FUN_1407cb9c0("curSnowflakeCount", FUN_140e95f40((int)i));
        row.FUN_1407cb9c0("curDailyCompleteCount", FUN_140e960d0((int)i));
        row.FUN_1407cb9c0("curAccumCompleteCount", FUN_140e96260((int)i));
        row.FUN_1407cbbe0("accumCompleteRewardReceived", FUN_140e963f0((int)i));
        snowmans.FUN_1422bc050(row.FUN_1422bb870());
    }
    info.FUN_1409adbe0("snowmans", snowmans.FUN_1422bb870());
    m_30->Invoke("updateInfo", info.FUN_1422bb870());
    m_lastUpdate = FUN_140869440();
}
MS2_REPLACE_METHOD(0x140E965E0, UISnowmanEventDialog, FUN_140e965e0, 784, 0xAF323AEA);

// @0x140e96900
void UISnowmanEventDialog::FUN_140e96900(int* width, int* height)
{
    if (m_30 == NULL)
        return;
    ASDialog* dialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (dialog) {
        *width = dialog->FUN_1422e6310();
        *height = dialog->FUN_1422e6270();
    }
}
MS2_REPLACE_METHOD(0x140E96900, UISnowmanEventDialog, FUN_140e96900, 148, 0x464891AD);

// @0x140e969a0
void UISnowmanEventDialog::FUN_140e969a0()
{
    if (m_alignInfo.IsNull()) {
        MS2_ASSERT_AT(502, "m_pAlignInfo" && 0);
        return;
    }
    int width = 0;
    int height = 0;
    FUN_140e96900(&width, &height);
    m_alignInfo->FUN_141901c10(m_30, width, height);
}
MS2_REPLACE_METHOD(0x140E969A0, UISnowmanEventDialog, FUN_140e969a0, 223, 0x48771CFC);

// @0x140e96a90
void UISnowmanEventDialog::FUN_140e96a90(const CStringW& path)
{
    TiXmlDocument doc;
    if (!FUN_140397ab0(FUN_140166420(), &doc, path)) {
        MS2_ASSERT_AT(160, FALSE);
        return;
    }
    void* root = FUN_140345b40(&doc);
    if (!root) {
        MS2_ASSERT_AT(167, FALSE);
        return;
    }
    void* node = FUN_140345b40(root);
    if (!node) {
        MS2_ASSERT_AT(174, FALSE);
        return;
    }
    CString align;
    FUN_1408733e0(node, "align", &align);
    m_alignment = FUN_140d01040(align);
    FUN_1408731e0(node, "offsetX", &m_offsetX);
    FUN_1408731e0(node, "offsetY", &m_offsetY);
    m_60 = 1;
}
MS2_REPLACE_METHOD(0x140E96A90, UISnowmanEventDialog, FUN_140e96a90, 431, 0x570BF6B3);

// @0x140e96c50
// MS2-FUNCTIONAL: the exe falls off the end after the loop (returns the last-loaded loop bound in eax) and keeps a switch temp; we return the count explicitly.
int UISnowmanEventDialog::FUN_140e96c50(int type, CInPacket& packet)
{
    if (m_30.IsNull()) {
        MS2_ASSERT_AT(190, "m_ascript" && 0);
        return 0;
    }
    switch (type) {
    case 0xc: {
        Unk_SnowmanPopup* popup = FUN_140938cd0(20061);
        if (popup == 0)
            return 0;
        int count = packet.ReadInt32();
        for (int i = 0; i < count; ++i)
            popup->FUN_141abf6e0(packet.ReadInt32(), packet.ReadInt16());
        return count;
    }
    case 0xd: {
        Unk_SnowmanPopup* popup = FUN_140938cd0(20061);
        if (popup == 0)
            return 0;
        int count = packet.ReadInt32();
        for (int i = 0; i < count; ++i)
            popup->FUN_141abf6e0(packet.ReadInt32(), packet.ReadInt16());
        return count;
    }
    default:
        MS2_ASSERT_AT(227, 0);
        return 0;
    }
}
MS2_REPLACE_METHOD(0x140E96C50, UISnowmanEventDialog, FUN_140e96c50, 622, 0x872ADDA2);

// @0x140e96ed0
void UISnowmanEventDialog::FUN_140e96ed0(GameEventVariable*) { FUN_140e965e0(); }
MS2_REPLACE_METHOD(0x140E96ED0, UISnowmanEventDialog, FUN_140e96ed0, 29, 0x5E788497);
// @0x140e96f00
void UISnowmanEventDialog::FUN_140e96f00(GameEventVariable*) { FUN_140e965e0(); }
MS2_REPLACE_METHOD(0x140E96F00, UISnowmanEventDialog, FUN_140e96f00, 29, 0xB2FF4CA7);
// @0x140e96f30
void UISnowmanEventDialog::FUN_140e96f30(GameEventVariable*) { FUN_140e965e0(); }
MS2_REPLACE_METHOD(0x140E96F30, UISnowmanEventDialog, FUN_140e96f30, 29, 0x13444DB7);
// @0x140e96f60
void UISnowmanEventDialog::FUN_140e96f60(GameEventVariable*) { FUN_140e965e0(); }
MS2_REPLACE_METHOD(0x140E96F60, UISnowmanEventDialog, FUN_140e96f60, 29, 0x69C2AD47);

// @0x140e973f0
int UISnowmanEventDialog::vfunc_48()
{
    return 20317;
}
MS2_REPLACE_METHOD(0x140E973F0, UISnowmanEventDialog, vfunc_48, 11, 0xAF46DE0F);
