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
#include "ms2/placeholder/wcformat.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/creservedwordtable.h"

// ---- unit-local views of exe objects ----

class CReservedWordTable;

// The client constants (singleton): the reward icons.
class CommonResource { public: class ATL::CStringT<char, class StrTraitMFC_DLL<char, class ATL::ChTraitsCRT<char>>> GetPath(int); }; class Unk_CbIcons : public CommonResource {
public:

    char m_pad_000[0x1d0];
    CString m_strStatIcon;                                      // +0x1d0
};
class Unk_SingletonObj* FUN_1401d31f0();   // C3: was FUN_1401d31f0

CStringTable* GetStringTable();
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
    FUN_1422bcea0(args.FUN_1409b1f70(0), (const wchar_t*)strText);
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
    if (m_nPrologue != 0)
    {
        CChapterBookTable::DataPtr spBook = CChapterBookTable::GetInstance()->Get(m_nPrologue);
        if (spBook.get() != 0)
        {
            static_cast<Unk_CbScript*>(m_30.operator->())->FUN_140e0a8c0("setPrologue",
                GetStringTable()->FUN_141811980(0x39, m_nPrologue), 5000);
        }
    }
    else if (m_nEpilogue != 0)
    {
        CChapterBookTable::DataPtr spBook = CChapterBookTable::GetInstance()->Get(m_nEpilogue);
        if (spBook.get() != 0)
        {
            CStringW strEpilogue = GetStringTable()->FUN_141811980(0x3a, m_nEpilogue);
            TSingleton<CReservedWordTable>::GetInstance()->ReplaceValueWords(strEpilogue);
            ASObj obj(2);
            ((class AScript&)(obj)).FUN_1407cb9c0("id", spBook->m_nId);
            ((class AScript&)(obj)).FUN_1407cbb20("chapter", GetStringTable()->FUN_141811980(0x39, m_nEpilogue));
            ((class AScript&)(obj)).FUN_1407cbb20("epilogue", CStringW(strEpilogue));
            for (unsigned __int64 i = 0; i < spBook->m_rewards.GetCount(); i++)
            {
                Unk_ChapterReward& reward = spBook->m_rewards[i];
                if (reward.m_nType == 1)
                {
                    MS2Ptr<CItemData> spItem = FUN_14053f870(reward.m_item.m_itemId);
                    if (spItem.IsNull())
                        continue;
                    ASObj objReward(2);
                    objReward.FUN_1407cba60("icon", spItem->GetIconPath());
                    ((class AScript&)(objReward)).FUN_1407cbb20("name", GetStringTable()->FUN_141811980(1, reward.m_item.m_itemId));
                    objReward.FUN_1409c0d20("count", reward.m_item.m_count);
                    obj.FUN_1409eb270(StringFormat<unsigned __int64>("reward{0}", i), objReward);
                }
                else if (reward.m_nType == 3)
                {
                    ASObj objReward(2);
                    objReward.FUN_1407cba60("icon", ((class Unk_CbIcons*)FUN_1401d31f0())->GetPath(reward.m_nKind));
                    CStringW strKey(L"s_chapterbook_skill_point");
                    if (reward.m_nKind == 2)
                        strKey = L"s_achieve_reward_skill_point_sub_1";
                    ((class AScript&)(objReward)).FUN_1407cbb20("name", FUN_14028dfa0<int>(strKey, reinterpret_cast<const int&>(reward.m_nValue)));
                    obj.FUN_1409eb270(StringFormat<unsigned __int64>("reward{0}", i), objReward);
                }
                else if (reward.m_nType == 2)
                {
                    ASObj objReward(2);
                    objReward.FUN_1407cba60("icon", ((class Unk_CbIcons*)FUN_1401d31f0())->m_strStatIcon);
                    ((class AScript&)(objReward)).FUN_1407cbb20("name", FUN_14028dfa0<int>(CStringW(L"s_chapterbook_stat_point"), reinterpret_cast<const int&>(reward.m_nValue)));
                    obj.FUN_1409eb270(StringFormat<unsigned __int64>("reward{0}", i), objReward);
                }
            }
            m_30->Invoke("setEpilogue", obj);
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
                switch (reward.m_nType)
                {
                case 3:
                {
                    pNotify->FUN_141ac1950(reward.m_nValue, reward.m_nKind);
                    CStringW strKey(L"s_reward_notify_skill_point");
                    if (reward.m_nKind == 2)
                        strKey = L"s_reward_notify_skill_point_sub_1";
                    FUN_1412751b0(FUN_14028dfa0<int>(strKey, reinterpret_cast<const int&>(reward.m_nValue)), 0x14);
                }
                break;
                case 2:
                    pNotify->FUN_141ac1b50(reward.m_nValue);
                    FUN_1412751b0(FUN_14028dfa0<int>(CStringW(L"s_reward_notify_stat_point"), reinterpret_cast<const int&>(reward.m_nValue)), 0x14);
                    break;
                case 1:
                    pNotify->FUN_141abf6e0(reward.m_item.m_itemId, reward.m_item.vfunc_o18_1());
                    break;
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
