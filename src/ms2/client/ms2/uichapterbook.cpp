// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIChapterBook: see uichapterbook.h.
// MS2-UNIT: ?\uichapterbook.cpp
// MS2-RANGE: 0x140e09a90-0x140e0aa10 .text$mn
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uichapterbook.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"
#include "uichapterbook.h"
#include "uirewardnotify.h"
#include "ms2/commonfiles/chapterbooktable.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of exe objects ----

class Unk_CbTextFilter { public: void FUN_1416fb340(CStringW& str); };
Unk_CbTextFilter* FUN_1403b4750();

// The client constants (singleton): the reward icons.
class Unk_CbIcons
{
public:
    CString FUN_140cca050(int nKind);                           // skill point icon
    char m_pad_000[0x1d0];
    CString m_strStatIcon;                                      // +0x1d0
};
Unk_CbIcons* FUN_1401d31f0();

CStringTable* FUN_1401a9d70();
CStringW FUN_14062b4f0(CStringW strKey, const int* pn);         // localized text with one number (pointer form)
CString FUN_1401d9af0(const char* szFormat, unsigned __int64* pArg);   // StringFormat "reward{0}"
void FUN_1412751b0(const CStringW& strMsg, int nType);
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);
void FUN_141901470(int n, int nType);                           // UIObject::vfunc_47's helper
UIRewardNotify* FUN_140938cd0(int uiType);                      // GetDialog<UIRewardNotify>

// The "setPrologue" call: the page text and the display time.
class Unk_CbScript : public AScript
{
public:
    Scaleform::GFx::Value FUN_140e0a8c0(const char* szMethod, CStringW strText, int nTime);
};

// @0x140e0a8c0
inline Scaleform::GFx::Value Unk_CbScript::FUN_140e0a8c0(const char* szMethod, CStringW strText, int nTime)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bcea0(args.FUN_1409b1f70(0), strText.GetString());
    FUN_1422bccb0(args.FUN_1409b1f70(1), nTime);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140e09a90
UIChapterBook::UIChapterBook()
{
    m_2c = 0x23;
    m_nPrologue = 0;
    m_nEpilogue = 0;
}

// @0x140e09b00
UIChapterBook::~UIChapterBook()
{
}

// @0x140e09b40
CString UIChapterBook::GetTypeName()
{
    return "ChapterBook";
}

// @0x140e09b90
void UIChapterBook::OnLoadComplete()
{
    UIHeadUpDisplay::OnLoadComplete();
    if (m_nPrologue == 0)
    {
        if (m_nEpilogue != 0)
        {
            CChapterBookTable::DataPtr spBook = CChapterBookTable::GetInstance()->Get(m_nEpilogue);
            if (spBook.get() != 0)
            {
                CStringW strEpilogue = FUN_1401a9d70()->FUN_141811980(0x3a, m_nEpilogue);
                FUN_1403b4750()->FUN_1416fb340(strEpilogue);
                ASObj obj(2);
                obj.FUN_1407cb9c0("id", spBook->m_nId);
                obj.FUN_1407cbb20("chapter", FUN_1401a9d70()->FUN_141811980(0x39, m_nEpilogue));
                obj.FUN_1407cbb20("epilogue", CStringW(strEpilogue));
                for (unsigned __int64 i = 0; i < spBook->m_rewards.GetCount(); i++)
                {
                    Unk_ChapterReward& reward = spBook->m_rewards[i];
                    if (reward.m_nType == 1)
                    {
                        MS2Ptr<CItemData> spItem = FUN_14053f870(reward.m_item.m_itemId);
                        if (!spItem.IsNull())
                        {
                            ASObj objReward(2);
                            objReward.FUN_1407cba60("icon", spItem->FUN_14053fdd0());
                            objReward.FUN_1407cbb20("name", FUN_1401a9d70()->FUN_141811980(1, reward.m_item.m_itemId));
                            objReward.FUN_1409c0d20("count", reward.m_item.m_count);
                            obj.FUN_1409eb270(FUN_1401d9af0("reward{0}", &i), objReward);
                        }
                    }
                    else if (reward.m_nType == 3)
                    {
                        ASObj objReward(2);
                        objReward.FUN_1407cba60("icon", FUN_1401d31f0()->FUN_140cca050(reward.m_nKind));
                        CStringW strKey(L"s_chapterbook_skill_point");
                        if (reward.m_nKind == 2)
                            strKey = L"s_achieve_reward_skill_point_sub_1";
                        objReward.FUN_1407cbb20("name", FUN_14062b4f0(strKey, &reward.m_nValue));
                        obj.FUN_1409eb270(FUN_1401d9af0("reward{0}", &i), objReward);
                    }
                    else if (reward.m_nType == 2)
                    {
                        ASObj objReward(2);
                        objReward.FUN_1407cba60("icon", FUN_1401d31f0()->m_strStatIcon);
                        objReward.FUN_1407cbb20("name", FUN_14062b4f0(CStringW(L"s_chapterbook_stat_point"), &reward.m_nValue));
                        obj.FUN_1409eb270(FUN_1401d9af0("reward{0}", &i), objReward);
                    }
                }
                m_30->Invoke("setEpilogue", obj);
            }
        }
    }
    else
    {
        CChapterBookTable::DataPtr spBook = CChapterBookTable::GetInstance()->Get(m_nPrologue);
        if (spBook.get() != 0)
        {
            static_cast<Unk_CbScript*>(m_30.operator->())->FUN_140e0a8c0("setPrologue",
                FUN_1401a9d70()->FUN_141811980(0x39, m_nPrologue), 5000);
        }
    }
}

// @0x140e0a3b0
void UIChapterBook::vfunc_26()
{
    UIObject::vfunc_26();
}

// @0x140e0a3d0
int UIChapterBook::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIHeadUpDisplay::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp(szMethod, "onHide") == 0)
    {
        CChapterBookTable::DataPtr spBook = CChapterBookTable::GetInstance()->Get(m_nEpilogue);
        UIRewardNotify* pNotify;
        if (spBook.get() != 0 && (pNotify = FUN_140938cd0(0x4e5d)) != 0)
        {
            for (unsigned __int64 i = 0; i < spBook->m_rewards.GetCount(); i++)
            {
                Unk_ChapterReward& reward = spBook->m_rewards[i];
                int nType = reward.m_nType;
                if (nType == 1)
                {
                    ItemEntity* pItem = &reward.m_item;
                    pNotify->FUN_141abf6e0(reward.m_item.m_itemId, pItem->vfunc_o18_1());
                }
                else if (nType == 2)
                {
                    pNotify->FUN_141ac1b50(reward.m_nValue);
                    FUN_1412751b0(FUN_14062b4f0(CStringW(L"s_reward_notify_stat_point"), &reward.m_nValue), 0x14);
                }
                else if (nType == 3)
                {
                    pNotify->FUN_141ac1950(reward.m_nValue, reward.m_nKind);
                    CStringW strKey(L"s_reward_notify_skill_point");
                    if (reward.m_nKind == 2)
                        strKey = L"s_reward_notify_skill_point_sub_1";
                    FUN_1412751b0(FUN_14062b4f0(strKey, &reward.m_nValue), 0x14);
                }
            }
        }
        m_nPrologue = 0;
        m_nEpilogue = 0;
        vfunc_3();
        UIRewardNotify* pNotify2 = FUN_140938cd0(0x4e5d);
        if (pNotify2 != 0)
            pNotify2->FUN_141abf210();
        return 1;
    }
    return 0;
}

// @0x140e0a770
void UIChapterBook::vfunc_43()
{
    if (m_30.get() != 0)
        m_30->Invoke("alignment");
}

// @0x140e0a7d0
void UIChapterBook::vfunc_2()
{
    UIHeadUpDisplay::vfunc_2();
    FUN_141901470(0, 0x4f37);
}

// @0x140e0a800
void UIChapterBook::vfunc_3()
{
    UIHeadUpDisplay::vfunc_3();
    m_nPrologue = 0;
    m_nEpilogue = 0;
    FUN_141901470(1, 0x4f37);
}

// @0x140e0a850
void UIChapterBook::FUN_140e0a850(int nPrologue)
{
    m_nPrologue = nPrologue;
    vfunc_2();
}

// @0x140e0a890
void UIChapterBook::FUN_140e0a890(int nEpilogue)
{
    m_nEpilogue = nEpilogue;
    vfunc_2();
}
