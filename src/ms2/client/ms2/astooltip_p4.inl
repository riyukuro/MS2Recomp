// astooltip.cpp part 4: functions 0x1409d9f30-0x1409e0450 (exe order). Included by astooltip.cpp; merged into it when the unit is done.
// The hook registrations are named by __LINE__: each one sits in namespace p4hook so that it cannot collide with a
// registration on the same line of astooltip.cpp or of another part (same translation unit).

// The play count text of a music score item.
// @0x1409d9f30
CStringW ASTooltip::FUN_1409d9f30(MS2Ptr<CItemData> spData)
{
    CStringW str;
    if (!spData)
        return str;
    if (!spData->FUN_14053cd10())
        return str;
    MS2Ptr<ItemMusicScore> spScore = CItemDataTable::GetInstance()->GetMusicScore(spData->FUN_14053c510());
    if (spScore == 0)
        return str;
    int nCount = spScore->FUN_14054ad00();
    if (spScore->FUN_14054aca0())
        str = BlockFormat(0x9bd, nCount);
    else
        str = BlockFormat(0x9bb, nCount);
    return str;
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409D9F30, ASTooltip, FUN_1409d9f30, 641, 0x5D355221); }

// The period text of a music score item.
// @0x1409da1c0
CStringW ASTooltip::FUN_1409da1c0(CItem* pItem)
{
    CStringW str;
    if (pItem == 0)
        return str;
    if (pItem->FUN_140525730())
        str = FUN_1409da3d0(MS2Ptr<CItemData>(pItem->FUN_140527840()));
    if (str.IsEmpty())
    {
        unsigned nSeconds = MsToSeconds(pItem->FUN_1405299a0());
        CStringW strPeriod = FUN_141b708a0(nSeconds, true);
        str = BlockFormat(0x9c1, pItem->FUN_140529aa0(), strPeriod);
    }
    return str;
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DA1C0, ASTooltip, FUN_1409da1c0, 513, 0x386E96EF); }

// @0x1409da3d0
CStringW ASTooltip::FUN_1409da3d0(MS2Ptr<CItemData> spData)
{
    CStringW str;
    if (!spData)
        return str;
    MS2Ptr<ItemMusicScore> spScore = CItemDataTable::GetInstance()->GetMusicScore(spData->FUN_14053c510());
    if (spScore == 0)
        return str;
    if (spScore->FUN_14054aca0())
    {
        int nLength = spScore->FUN_14054acc0();
        str = BlockFormat(0x9c0, nLength);
    }
    else
    {
        unsigned nSeconds = MsToSeconds(spScore->FUN_14054ace0());
        CStringW strPeriod = FUN_141b708a0(nSeconds, true);
        str = BlockFormat(0x9c1, spScore->FUN_14054ad20(), strPeriod);
    }
    return str;
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DA3D0, ASTooltip, FUN_1409da3d0, 689, 0x1A4506A2); }

// The mastery recipes that use the item as an ingredient (with the owned / needed count).
// @0x1409da690
CStringW ASTooltip::FUN_1409da690(CItem* pItem)
{
    CMasteryTable::IngredientListPtr spList = CMasteryTable::GetInstance()->IngredientReceipes(pItem->FUN_1405276c0());
    if (spList.get() != 0)
    {
        CStringW str;
        for (size_t i = 0; i < spList->GetCount(); i++)
        {
            std::pair<int, int>* pEntry = &(*spList.operator->())[i];
            CMasteryTable::ReceipePtr spReceipe = CMasteryTable::GetInstance()->Find(pEntry->first);
            if (!spReceipe)
                continue;
            int nHave = DAT_143ab2a90.FUN_140a5f180(pItem->FUN_1405276c0(), 0);
            int nNeed = pEntry->second;
            CStringW strKey(L"s_msg_tooltip_mastery_recipe_count");
            if (nHave < nNeed)
                strKey += L"_lack";
            CStringW strType = CMasteryTable::GetInstance()->TypeName(spReceipe->m_nType);
            CStringW strName = CStringTable::GetInstance()->FUN_141811980(0x2f, spReceipe->m_nId);
            CStringW strCount = FUN_14028dfa0(strKey, nHave, nNeed);
            if (str.GetLength() != 0)
                str += L"\n";
            str += FUN_14028dfa0(CStringW(L"s_msg_tooltip_mastery_recipe_info"), strType, strName, strCount);
        }
        return str;
    }
    return L"";
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DA690, ASTooltip, FUN_1409da690, 922, 0x597922AA); }

// @0x1409daa30
CStringW ASTooltip::FUN_1409daa30(MS2Ptr<CItemData> spData)
{
    if (!spData)
        return L"";
    if (!spData->FUN_14053dfd0(L"ChatEmoticonAdd"))
        return L"";
    CXmlData& xml = spData->function.xml;
    std::vector<unsigned> ids;
    {
        CStringW strIds = xml.FUN_14042cad0(L"id", L"");
        FUN_1402929a0(strIds, ids, L",");
    }
    std::list<MS2Ptr<ChatEmoticonData> > emoticons;
    std::vector<unsigned>& rIds = ids;
    std::vector<unsigned>::const_iterator itIdEnd = rIds.end();
    for (std::vector<unsigned>::const_iterator itId = rIds.begin(); itId != itIdEnd; ++itId)
    {
        unsigned nGroupId = *itId;
        std::list<MS2Ptr<ChatEmoticonData> > group;
        CChatEmoticonTable::GetInstance()->FUN_1401e73c0(nGroupId, &group);
        emoticons.insert(emoticons.end(), group.begin(), group.end());
    }
    const int nPerRow = 4;
    CStringW strGap = FUN_14028b8e0(L"s_tooltip_chat_emoticon_extra_comment_image_gap");
    int nCount = 0;
    CStringW str;
    std::list<MS2Ptr<ChatEmoticonData> >& rEmoticons = emoticons;
    std::list<MS2Ptr<ChatEmoticonData> >::const_iterator itEnd = rEmoticons.end();
    for (std::list<MS2Ptr<ChatEmoticonData> >::const_iterator it = rEmoticons.begin(); it != itEnd; ++it)
    {
        MS2Ptr<ChatEmoticonData> spEmoticon = *it;
        if (!spEmoticon)
            continue;
        CStringW strIcon = StringFormat(L"img://icon:{0}", spEmoticon->m_strImagePath);
        str += FUN_14028dfa0(CStringW(L"s_tooltip_chat_emoticon_extra_comment_image_tag"), strIcon);
        nCount++;
        if (nCount % nPerRow != 0)
            str += strGap;
        else
            str += L"\n";
    }
    FUN_1409c0dc0("extraCommentAlign", "center");
    return str;
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DAA30, ASTooltip, FUN_1409daa30, 1466, 0xEE156D83); }

// @0x1409daff0
CStringW ASTooltip::FUN_1409daff0(MS2Ptr<CItemData> spData)
{
    if (!spData)
        return L"";
    CXmlData& xml = spData->function.xml;
    int nCount = 0;
    std::vector<int> ids = xml.FUN_1409e8620(L"id", std::vector<int>());
    for each (int nGroupId in ids)
    {
        std::list<MS2Ptr<ChatEmoticonData> > group;
        CChatEmoticonTable::GetInstance()->FUN_1401e73c0(nGroupId, &group);
        nCount += static_cast<int>(group.size());
    }
    CStringW str = FUN_14028dfa0(CStringW(L"s_tooltip_chat_emoticon_description"), nCount) + L"\n";
    if (xml.FUN_14092c5f0(L"endDate"))
    {
        CString strEndDate = xml.FUN_1409e8560(L"endDate", "");
        CMsTime time;
        CString strFormat("%04d-%02d-%02d-%02d-%02d-%02d");
        if (FUN_14028e280(time, strFormat, strEndDate) == 0)
            return L"";
        str += FUN_14028dfa0(CStringW(L"s_tooltip_chat_emoticon_description_enddate"), time.GetYear(), time.GetMonth(),
            time.GetDay(), time.GetHour(), time.GetMinute());
    }
    else if (xml.FUN_14092c5f0(L"durationSec"))
    {
        __int64 nSeconds = xml.FUN_1409e86e0(L"durationSec", 0);
        CTimeSpan span(nSeconds);
        CStringW strDuration = FormatTimeSpan(span, true, true, true, true);
        str += FUN_14028dfa0(CStringW(L"s_tooltip_chat_emoticon_description_duration"), strDuration);
    }
    return str;
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DAFF0, ASTooltip, FUN_1409daff0, 1710, 0x5BC1D730); }

// @0x1409db6b0
MS2Ptr<AScript> ASTooltip::FUN_1409db6b0()
{
    Scaleform::GFx::Value v = FUN_1422baa20("rhsTooltip");
    return FUN_1409e7dc0(m_nMovieId, v);
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DB6B0, ASTooltip, FUN_1409db6b0, 108, 0xEB7EE570); }

// @0x1409db730
MS2Ptr<AScript> ASTooltip::FUN_1409db730()
{
    Scaleform::GFx::Value v = FUN_1422baa20("lhsTooltip");
    return FUN_1409e7dc0(m_nMovieId, v);
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DB730, ASTooltip, FUN_1409db730, 108, 0x9E63F646); }

// @0x1409db7b0
void ASTooltip::FUN_1409db7b0(MS2Ptr<CItem> spItem)
{
    if (!FUN_141b48950(spItem))
        return;
    CStringW str = FUN_1409e7880();
    FUN_1407cbb20("enablePreview", str);
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DB7B0, ASTooltip, FUN_1409db7b0, 186, 0x7FFD03BD); }

// @0x1409db870
void ASTooltip::FUN_1409db870(MS2Ptr<CItemData> spData)
{
    if (!FUN_141b488c0(spData))
        return;
    CStringW str = FUN_1409e7880();
    FUN_1407cbb20("enablePreview", str);
}
// not hooked: overloaded with the stale Unk_GalleryPtr declaration (uigalleryeventdialog.cpp)

// The item tooltip with an optional comparison item: each one goes to its side tooltip when the movie has one.
// @0x1409db930
// MS2-FUNCTIONAL: the exe keeps the null test of the side tooltip in a bool temp (no source form found)
void ASTooltip::FUN_1409db930(MS2Ptr<CItem> spCompare, MS2Ptr<CItem> spItem)
{
    if (spCompare.get() != 0)
    {
        MS2Ptr<AScript> spLhs = FUN_1409db730();
        if (spLhs.get() != 0 && !spLhs->FUN_1422ba9a0())
        {
            ASTooltip tip(spLhs->FUN_1422bb870(), 2);
            tip.FUN_1409db7b0(spCompare);
        }
        else
            FUN_1409db7b0(spCompare);
    }
    if (spItem.get() == 0)
        return;
    MS2Ptr<AScript> spRhs = FUN_1409db6b0();
    if (spRhs.get() != 0 && !spRhs->FUN_1422ba9a0())
    {
        ASTooltip tip(spRhs->FUN_1422bb870(), 2);
        tip.FUN_1409db7b0(spItem);
    }
    else
        FUN_1409db7b0(spItem);
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DB930, ASTooltip, FUN_1409db930, 640, 0x795DD30D); }

// @0x1409dbbc0
void ASTooltip::FUN_1409dbbc0(CStringW str)
{
    FUN_1407cbb20(s_strItemName, str);
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DBBC0, ASTooltip, FUN_1409dbbc0, 102, 0x4BAE7722); }

// @0x1409dbc60
void ASTooltip::FUN_1409dbc60(int nSkillId, const CStringW& strSuffix)
{
    CStringW str = CStringTable::GetInstance()->FUN_141811980(4, nSkillId) + strSuffix;
    FUN_1407cbb20(s_strSkillName, str);
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DBC60, ASTooltip, FUN_1409dbc60, 185, 0xA2BE6DF6); }

// @0x1409dbd30
void ASTooltip::FUN_1409dbd30(int nSkillId)
{
    MS2Ptr<SkillData> spSkill = SkillDataTableCli::GetInstance()->GetSkillData(nSkillId);
    if (!spSkill)
        return;
    unsigned nElement = spSkill->GetElement();
    int ids[8] = {0, 0x5c4, 0x5c5, 0x5c6, 0x5c7, 0x5c8, 0x5c9, 0};
    if ((int)nElement >= 8)
        return;
    ASObj obj(2);
    obj.FUN_1409c0d20("type", nElement);
    obj.FUN_1407cbb20("text", FUN_14028de60(ids[nElement]));
    FUN_1409adbe0("skillElement", obj.FUN_1422bb870());
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DBD30, ASTooltip, FUN_1409dbd30, 442, 0x5850A4D6); }

// @0x1409dbef0
void ASTooltip::FUN_1409dbef0(int nSkillId)
{
    MS2Ptr<SkillData> spSkill = SkillDataTableCli::GetInstance()->GetSkillData(nSkillId);
    if (!spSkill)
        return;
    FUN_1407cba60(s_strIconPath, spSkill->m_strIcon);
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DBEF0, ASTooltip, FUN_1409dbef0, 165, 0x9B19764E); }

// The quick slot hint of an active skill the player has learnt.
// @0x1409dbfa0
void ASTooltip::FUN_1409dbfa0(int nSkillId)
{
    if (FUN_1409c6540() == 0)
        return;
    MS2Ptr<SkillData> spSkill = SkillDataTableCli::GetInstance()->GetSkillData(nSkillId);
    if (!spSkill)
        return;
    if (spSkill->FUN_1407e9de0())
        return;
    Unk_TooltipJobSystem* pJob = FUN_1416546d0(reinterpret_cast<MyPC*>(FUN_1409c6540()));
    if (pJob->vfunc_2(nSkillId))
    {
        int nSlot = CKeyTable::GetInstance()->FUN_14142e090(nSkillId, 0);
        if (nSlot != -1)
            FUN_1407cbb20(s_strItemEquip, FUN_14028de60(0x58a));
        else
            FUN_1409c69b0(FUN_14028de60(0x75a));
    }
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DBFA0, ASTooltip, FUN_1409dbfa0, 386, 0xE6EADCDD); }

// @0x1409dc130
void ASTooltip::FUN_1409dc130(int nSkillId, unsigned short nLevel)
{
    FUN_1407cbb20("skillDescription", CStringTable::GetInstance()->FUN_141811e50(nSkillId, nLevel, "name"));
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DC130, ASTooltip, FUN_1409dc130, 178, 0x7C4A5F42); }

// @0x1409dc1f0
void ASTooltip::FUN_1409dc1f0(int nSkillId, unsigned short nLevel)
{
    MS2Ptr<SkillData> spSkill = SkillDataTableCli::GetInstance()->GetSkillData(nSkillId);
    if (spSkill == 0)
        return;
    MS2Ptr<SkillLevelData> spLevel = spSkill->FUN_1407e90a0(nLevel);
    if (spLevel == 0)
        return;
    CStringW strLevel;
    strLevel = BlockFormat(0x57e, nLevel);
    if (spSkill->FUN_1407e9ac0() == nLevel)
        strLevel += FUN_14028de60(0x79b);
    CStringW strSp;
    if (spLevel->m_nSp > 0)
        strSp.Format(L"%s %d", (const wchar_t*)FUN_14028de60(0x490), spLevel->m_nSp);
    CStringW strEp;
    if (spLevel->m_nEp > 0)
        strEp.Format(L"%s %d", (const wchar_t*)FUN_14028de60(0x491), spLevel->m_nEp);
    CStringW strCooltime;
    int nCooltime = (int)spLevel->FUN_140804660();
    if (nCooltime > 0)
        strCooltime = BlockFormat(0x583, nCooltime);
    ASObj obj(2);
    obj.FUN_1407cb9c0("type", 1);
    obj.FUN_1407cbb20("level", strLevel);
    obj.FUN_1407cbb20("statSP", strSp);
    obj.FUN_1407cbb20("statEP", strEp);
    obj.FUN_1407cbb20("cooltime", strCooltime);
    FUN_1409adbe0("statDescription", obj.FUN_1422bb870());
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DC1F0, ASTooltip, FUN_1409dc1f0, 1288, 0x964B9442); }

// The cast hint, the target / attack kind and the required weapons of a skill level.
// @0x1409dc700
void ASTooltip::FUN_1409dc700(int nSkillId, unsigned short nLevel)
{
    MS2Ptr<SkillData> spSkill = SkillDataTableCli::GetInstance()->GetSkillData(nSkillId);
    if (!spSkill)
        return;
    MS2Ptr<SkillLevelData> spLevel = spSkill->FUN_1407e90a0(nLevel);
    if (!spLevel)
        return;
    ASArray rows(2);
    {
        CStringW str;
        if (!spSkill->FUN_1407e9de0())
            str = FUN_14028de60(0x5c1);
        else
            str = FUN_14028de60(0x5c2);
        if (!str.IsEmpty())
        {
            ASObj row(2);
            row.FUN_1407cbb20("text", str);
            row.FUN_1409c0dc0("color", "aaaaaa");
            rows.FUN_1422bc050(row.FUN_1422bb870());
        }
    }
    unsigned nRange = spSkill->GetRangeType();
    unsigned nAttack = spSkill->m_eAttackType;
    int rangeIds[3] = {0, 0x597, 0x598};
    int attackIds[3] = {0, 0x5c3, 0x596};
    {
        CStringW str;
        if (rangeIds[nRange] != 0)
            str.AppendFormat(L"%s", (const wchar_t*)FUN_14028de60(rangeIds[nRange]));
        if (attackIds[nAttack] != 0)
        {
            if (str.IsEmpty())
                str.AppendFormat(L"%s", (const wchar_t*)FUN_14028de60(attackIds[nAttack]));
            else
                str.AppendFormat(L" / %s", (const wchar_t*)FUN_14028de60(attackIds[nAttack]));
        }
        if (!str.IsEmpty())
        {
            ASObj row(2);
            row.FUN_1407cbb20("text", str);
            row.FUN_1409c0dc0("color", "aaaaaa");
            rows.FUN_1422bc050(row.FUN_1422bb870());
        }
    }
    int nRight = 0;
    int nLeft = 0;
    {
        MS2Ptr<CEquipItem> spEquip = reinterpret_cast<Unk_TooltipOwnerPC*>(FUN_1409c6540())->FUN_141655c90(5);
        if (spEquip.get() != 0)
            nRight = spEquip->FUN_1411dc7f0()->FUN_14053c620();
    }
    {
        MS2Ptr<CEquipItem> spEquip = reinterpret_cast<Unk_TooltipOwnerPC*>(FUN_1409c6540())->FUN_141655c90(4);
        if (spEquip.get() != 0)
            nLeft = spEquip->FUN_1411dc7f0()->FUN_14053c620();
    }
    {
        int nAllowed = 0;
        CStringW str(L"");
        FUN_1409e6d00(nRight, nLeft, spSkill->m_condition.m_arrWeapon, nAllowed, str);
        if (!str.IsEmpty())
        {
            ASObj row(2);
            row.FUN_1407cbb20("text", str);
            row.FUN_1409c0dc0("color", nAllowed != 0 ? "aaaaaa" : "ff4040");
            rows.FUN_1422bc050(row.FUN_1422bb870());
        }
    }
    FUN_1409adbe0("extraDescription", rows.FUN_1422bb870());
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DC700, ASTooltip, FUN_1409dc700, 2045, 0x705AB547); }

// @0x1409dcf10
void ASTooltip::FUN_1409dcf10(int nSkillId, unsigned short nLevel, int bFromDialog)
{
    MS2Ptr<SkillData> spSkill = SkillDataTableCli::GetInstance()->GetSkillData(nSkillId);
    if (!spSkill)
        return;
    MS2Ptr<JobData> spJob = FUN_1416546d0(reinterpret_cast<MyPC*>(FUN_1409c6540()))->FUN_140639bb0();
    if (spJob == 0)
        return;
    MS2Ptr<JobSkillData> spRequire = spJob->FindSkill(nSkillId);
    if (spRequire == 0)
    {
        spRequire = spJob->FindSkill(spSkill->GetOriginId());
        if (spRequire == 0)
            return;
    }
    if (!spRequire->HasRequirement())
        return;
    ASArray rows(2);
    {
        ASObj row(2);
        row.FUN_1407cbb20("text", FUN_14028b8e0(L"s_word_learn_require_condition"));
        row.FUN_1409c0dc0("color", "aaaaaa");
        rows.FUN_1422bc050(row.FUN_1422bb870());
    }
    unsigned short nRequireLevel = spRequire->GetRequireLevel(nLevel);
    if (nRequireLevel > 0)
    {
        // vfunc_78 is the level (an unsigned short in the exe's view of this slot)
        int nAllowed = static_cast<unsigned short>(reinterpret_cast<PCBase*>(FUN_1409c6540())->vfunc_78()) >= nRequireLevel;
        ASObj row(2);
        row.FUN_1407cbb20("text", FUN_14028dfa0(CStringW(L"s_word_require_player_level"), nRequireLevel));
        row.FUN_1409c0dc0("color", nAllowed != 0 ? "ffd400" : "ff4040");
        rows.FUN_1422bc050(row.FUN_1422bb870());
    }
    {
        MS2Ptr<Unk_TooltipSkillSim> spSim(0);
        if (bFromDialog != 0)
        {
            Unk_TooltipSkillTreeDialog* pDialog = reinterpret_cast<Unk_TooltipSkillTreeDialog*>(FUN_1409eb120(0x4f2d));
            if (pDialog != 0)
                spSim = pDialog->FUN_140ec8ad0();
        }
        ATL::CAtlArray<unsigned>& ids = spRequire->m_requireSkillIDs;
        ATL::CAtlArray<unsigned short>& levels = spRequire->m_requireSkillLevels;
        for (unsigned i = 0; i < ids.GetCount(); i++)
        {
            MS2Ptr<Unk_TooltipJobSkillP4> spJobSkill(0);
            if (spSim.get() != 0)
                spJobSkill = spSim->FUN_140abc980(ids[i]);
            else
                spJobSkill = FUN_1416546d0(reinterpret_cast<MyPC*>(FUN_1409c6540()))->FUN_1406394d0(ids[i]);
            if (spJobSkill == 0)
                continue;
            int nAllowed = 1;
            if (!spJobSkill->m_bLearnt || spJobSkill->m_nLevel < levels[i])
                nAllowed = 0;
            CStringW str = FUN_14028dfa0(CStringW(L"s_word_require_skill_level"),
                CStringTable::GetInstance()->FUN_141811980(4, spJobSkill->FUN_140637cc0()), levels[i]);
            if (nAllowed == 0
                && reinterpret_cast<PC*>(FUN_1409c6540())->FUN_1409eee00()->FUN_14080baf0(spJobSkill->FUN_140637cc0()) > 0)
                str = FUN_14028dfa0(CStringW(L"s_word_require_skill_level_without_leveloption"), str);
            ASObj row(2);
            row.FUN_1407cbb20("text", str);
            row.FUN_1409c0dc0("color", nAllowed != 0 ? "ffd400" : "ff4040");
            rows.FUN_1422bc050(row.FUN_1422bb870());
        }
    }
    Unk_TooltipQuestOwner* pPC = FUN_141bd0cc0_p4(FUN_1403ed2d0_p4());
    if (pPC != 0 && spRequire->m_requireQuestID != 0)
    {
        CStringW str = FUN_14028dfa0(CStringW(L"s_word_require_quest_completed"), FUN_1416e4df0(spRequire->m_requireQuestID));
        int bCompleted = pPC->FUN_141523ba0()->m_quests.FUN_140745590(spRequire->m_requireQuestID);
        ASObj row(2);
        row.FUN_1407cbb20("text", str);
        row.FUN_1409c0dc0("color", bCompleted != 0 ? "ffd400" : "ff4040");
        rows.FUN_1422bc050(row.FUN_1422bb870());
    }
    FUN_1409adbe0("requireDescription", rows.FUN_1422bb870());
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DCF10, ASTooltip, FUN_1409dcf10, 3355, 0x74CB32AB); }
// The market description of an UGC market product (seller, sale count / date / price).
// @0x1409ddc40
void ASTooltip::FUN_1409ddc40(CMeratMarketProduct* pProduct)
{
    if (pProduct == 0)
        return;
    CMsTime endDate(pProduct->m_ugc.m_n68);
    CStringW strDate;
    CMsTime zero(0);
    if (endDate == zero)
        strDate = L"-";
    else
    {
        int nSecond = endDate.GetSecond();
        int nMinute = endDate.GetMinute();
        int nHour = endDate.GetHour();
        int nDay = endDate.GetDay();
        int nMonth = endDate.GetMonth();
        int nYear = endDate.GetYear();
        strDate = BlockFormat(0x9dd, nYear, nMonth, nDay, nHour, nMinute, nSecond);
    }
    ASObj obj(2);
    obj.FUN_1407cbb20("seller", pProduct->m_ugc.m_user.m_strName);
    obj.FUN_1407cbb20("desc", pProduct->m_ugc.GetStr208());
    obj.FUN_1407cbb20("tag", pProduct->m_ugc.GetStr200Head());
    obj.FUN_1407cbb20("sellcount", BlockFormat(0x9dc, pProduct->m_ugc.m_n44));
    obj.FUN_1407cbb20("selldate", strDate);
    obj.FUN_1407cbb20("sellprice", StringFormat(L"{0}<img src = 'export_common_icon_merat' vspace = '-4'>< / img>", FUN_1409404f0(pProduct->m_ugc.m_n50)));
    FUN_1409eb270("marketDesc", obj);
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DDC40, ASTooltip, FUN_1409ddc40, 976, 0xF641BD2B); }

// @0x1409de020
void ASTooltip::FUN_1409de020(CMeratMarketPremiumProduct* pProduct)
{
    FUN_1409de070(pProduct->m_nBuyLimit, pProduct->m_n90, pProduct->m_nBuyLimitMax);
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DE020, ASTooltip, FUN_1409de020, 64, 0x3806FEEC); }

// @0x1409de070
// MS2-FUNCTIONAL: the exe frame keeps fewer string temporaries (no source form found)
void ASTooltip::FUN_1409de070(int nScope, int nReset, int nCount)
{
    CStringW strKey = FUN_1409e3050(CStringW(L"s_tooltip_buylimit"), nScope, nReset);
    FUN_1409c6ef0(FUN_14028dfa0(strKey, nCount));
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DE070, ASTooltip, FUN_1409de070, 190, 0xC37C1BCE); }

// The name row of an item, with its icon code and the cash prefix.
// @0x1409de140
void ASTooltip::FUN_1409de140(ASArray* pRows, int nItemId, int nRank)
{
    if (FUN_1409c6540() == 0)
        return;
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (!spData)
        return;
    CStringW strCode(nRank == 0 ? L"" : (const wchar_t*)CStringTable::GetInstance()->FUN_141813150(nRank));
    CStringW strName = FUN_141277910(spData);
    CStringW strBody;
    if (strCode.IsEmpty())
        strBody = strName;
    else
    {
        CStringW strSuffix = FUN_1409df920(spData);
        if (strSuffix.IsEmpty())
            strBody = FUN_14028dfa0(CStringW(L"s_item_tooltip_icon_code_param2"), strCode, strName);
        else
            strBody = FUN_14028dfa0(CStringW(L"s_item_tooltip_icon_code_param3"), strCode, strSuffix, strName);
    }
    CStringW strText;
    if (spData->FUN_14053e130())
        strText = StringFormat(L"{0} {1}", FUN_14028de60(0x593), strBody);
    else
        strText = strBody;
    ASObj row(2);
    row.FUN_1407cbb20("text", strText);
    row.FUN_1409c0dc0("color", "aaaaaa");
    pRows->FUN_1422bc050(row.FUN_1422bb870());
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DE140, ASTooltip, FUN_1409de140, 1245, 0xB8C7CCAF); }

// The trade rows of an item (install space bits 1, 2, 4).
// @0x1409de630
void ASTooltip::FUN_1409de630(ASArray* pRows, int nItemId)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (!spData)
        return;
    if ((spData->install.space & 1) != 0)
    {
        if ((spData->install.space & 2) != 0)
        {
            ASObj row(2);
            row.FUN_1407cbb20("text", FUN_14028de60(0x590));
            row.FUN_1409c0dc0("color", "aaaaaa");
            pRows->FUN_1422bc050(row.FUN_1422bb870());
        }
        else if ((spData->install.space & 4) != 0)
        {
            ASObj row(2);
            row.FUN_1407cbb20("text", FUN_14028de60(0x590));
            row.FUN_1409c0dc0("color", "aaaaaa");
            pRows->FUN_1422bc050(row.FUN_1422bb870());
        }
        else
        {
            ASObj row(2);
            row.FUN_1407cbb20("text", FUN_14028de60(0x58f));
            row.FUN_1409c0dc0("color", "aaaaaa");
            pRows->FUN_1422bc050(row.FUN_1422bb870());
        }
    }
    else
    {
        ASObj row(2);
        row.FUN_1407cbb20("text", FUN_14028de60(0x58e));
        row.FUN_1409c0dc0("color", "aaaaaa");
        pRows->FUN_1422bc050(row.FUN_1422bb870());
    }
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DE630, ASTooltip, FUN_1409de630, 955, 0x29905478); }

// @0x1409dea00
void ASTooltip::FUN_1409dea00(ASArray* pRows, int nItemId)
{
    MS2Ptr<ItemHousing> spHousing = CItemDataTable::GetInstance()->GetHousing(nItemId);
    if (spHousing == 0)
        return;
    ASObj row(2);
    row.FUN_1407cbb20("text", FUN_14052bd00(0x6f8, CStringTable::GetInstance()->FUN_141811980(0x32, spHousing->categoryIndex)));
    row.FUN_1409c0dc0("color", "aaaaaa");
    pRows->FUN_1422bc050(row.FUN_1422bb870());
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DEA00, ASTooltip, FUN_1409dea00, 368, 0x47F7EBFE); }

// @0x1409deb80
// MS2-FUNCTIONAL: argument evaluation order of the job limit call differs
void ASTooltip::FUN_1409deb80(ASArray* pRows, int nItemId)
{
    if (FUN_1409c6540() == 0)
        return;
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (!spData)
        return;
    {
        int nAllowed = 0;
        CStringW str(L"");
        ATL::CAtlArray<unsigned>& jobs = spData->limit.jobLimit;
        FUN_1409e68a0(FUN_141654700(reinterpret_cast<PCBase*>(FUN_1409c6540())), jobs, nAllowed, str);
        if (!str.IsEmpty())
        {
            ASObj row(2);
            row.FUN_1407cbb20("text", str);
            row.FUN_1409c0dc0("color", nAllowed == 0 ? "ff4040" : "aaaaaa");
            pRows->FUN_1422bc050(row.FUN_1422bb870());
        }
    }
    {
        CStringW str(L"");
        ATL::CAtlArray<unsigned>& jobs = spData->limit.disableJobLimit;
        FUN_1409e6aa0(FUN_141654700(reinterpret_cast<PCBase*>(FUN_1409c6540())), jobs, str);
        if (!str.IsEmpty())
        {
            ASObj row(2);
            row.FUN_1407cbb20("text", str);
            row.FUN_1409c0dc0("color", "ff4040");
            pRows->FUN_1422bc050(row.FUN_1422bb870());
        }
    }
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DEB80, ASTooltip, FUN_1409deb80, 786, 0x867CF598); }

// The level row of an item (with the additional level).
// @0x1409deea0
void ASTooltip::FUN_1409deea0(ASArray* pRows, int nItemId, int nRarity, int nLevel, int nAdditional)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (!spData)
        return;
    if (!spData->FUN_14053cbc0())
        return;
    if (spData->FUN_14053cf90())
        return;
    int nBase = nLevel - nAdditional;
    int nAdd = nAdditional;
    if (nLevel <= 0)
    {
        nBase = spData->FUN_14053f0d0(nRarity);
        nAdd = 0;
    }
    CStringW str;
    if (nAdd > 0)
        str = FUN_14028dfa0(CStringW(L"s_common_item_level_with_value_additional"), nBase, nAdd);
    else
        str = FUN_14028dfa0(CStringW(L"s_common_item_level_with_value"), nBase);
    ASObj row(2);
    row.FUN_1407cbb20("text", str);
    row.FUN_1409c0dc0("color", "aaaaaa");
    pRows->FUN_1422bc050(row.FUN_1422bb870());
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DEEA0, ASTooltip, FUN_1409deea0, 721, 0xF72AA294); }

// The level limit row of an item (red when the owner is below it).
// @0x1409df180
// MS2-FUNCTIONAL: the level getter result is kept in a word temp (no source form found)
void ASTooltip::FUN_1409df180(ASArray* pRows, int nItemId)
{
    if (FUN_1409c6540() == 0)
        return;
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (!spData)
        return;
    if (!spData->FUN_14053c8b0())
        return;
    if (spData->limit.levelLimit == 1)
        return;
    PCBase* pOwner = reinterpret_cast<PCBase*>(FUN_1409c6540());
    bool bAllowed = spData->FUN_14053c9a0((unsigned short)pOwner->vfunc_78());
    CStringW str;
    str.Format(L"%s %d", (const wchar_t*)FUN_14028de60(0x589), spData->limit.levelLimit);
    ASObj row(2);
    row.FUN_1407cbb20("text", str);
    row.FUN_1409c0dc0("color", bAllowed == 0 ? "ff4040" : "aaaaaa");
    pRows->FUN_1422bc050(row.FUN_1422bb870());
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DF180, ASTooltip, FUN_1409df180, 624, 0x3E3F3BC9); }

// @0x1409df400
// MS2-FUNCTIONAL: the exe frame is 0x10 smaller (no source form found)
void ASTooltip::FUN_1409df400(ASArray* pRows, int nItemId)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (!spData)
        return;
    if (!spData->limit.flag6a)
        return;
    CStringW str;
    ASObj row(2);
    row.FUN_1407cbb20("text", FUN_14028b8e0(CStringW(L"s_word_item_limit_vip")));
    row.FUN_1409c0dc0("color", FUN_141662de0(reinterpret_cast<PCBase*>(FUN_1409c6540())) == 0 ? "ff4040" : "aaaaaa");
    pRows->FUN_1422bc050(row.FUN_1422bb870());
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DF400, ASTooltip, FUN_1409df400, 417, 0x7C8CC9F0); }

// @0x1409df5b0
// MS2-FUNCTIONAL: the exe frame is 0x10 smaller (no source form found)
void ASTooltip::FUN_1409df5b0(ASArray* pRows, int nItemId)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (!spData)
        return;
    if (!spData->limit.wedding)
        return;
    CStringW str;
    ASObj row(2);
    row.FUN_1407cbb20("text", FUN_14028b8e0(CStringW(L"s_word_item_limit_wedding")));
    row.FUN_1409c0dc0("color", WeddingManager::GetInstance()->IsInProgress() == 0 ? "ff4040" : "aaaaaa");
    pRows->FUN_1422bc050(row.FUN_1422bb870());
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DF5B0, ASTooltip, FUN_1409df5b0, 412, 0xF4AAE57C); }

// The upgrade row of a gemstone item.
// @0x1409df760
// MS2-FUNCTIONAL: the null test of the data pointer jumps differently (no source form found)
void ASTooltip::FUN_1409df760(ASArray* pRows, MS2Ptr<CItemData> spData)
{
    if (!(spData == 0) && spData->FUN_14053d840())
    {
        CItemGemStoneUpgradeTable::DataPtr spGem = CItemGemStoneUpgradeTable::GetInstance()->FUN_1405b1a60(spData->FUN_14053c510());
        if (spGem == 0)
            return;
        CStringW str = FUN_1406285d0(spGem->m_nMask);
        ASObj row(2);
        row.FUN_1407cbb20("text", str);
        row.FUN_1409c0dc0("color", "aaaaaa");
        pRows->FUN_1422bc050(row.FUN_1422bb870());
    }
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DF760, ASTooltip, FUN_1409df760, 438, 0xECB12C0F); }

// @0x1409df920
CStringW ASTooltip::FUN_1409df920(MS2Ptr<CItemData> spData)
{
    if (!spData)
        return L"";
    if (spData->cubeTextureName.mesh.GetLength() != 0)
        return FUN_14028de60(0x58c);
    if (spData->FUN_14053cf90())
        return FUN_14028de60(0x594);
    return L"";
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DF920, ASTooltip, FUN_1409df920, 291, 0xDEC1F450); }

// @0x1409dfa50
void ASTooltip::FUN_1409dfa50(CItem* pItem, int& nTransferable, int& nReady, CStringW& strName)
{
    Unk_ItemOwnerRef* pTransfer = pItem->FUN_140527930();
    if (pTransfer != 0)
    {
        if (pTransfer->FUN_140635100() != 0)
        {
            nTransferable = 1;
            if (pTransfer->FUN_140635120() != 0)
            {
                nReady = 1;
                pTransfer->FUN_140635350(reinterpret_cast<PCBase*>(FUN_1409c6540()), &strName);
            }
        }
    }
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DFA50, ASTooltip, FUN_1409dfa50, 130, 0x14099EEF); }

// @0x1409dfae0
int ASTooltip::FUN_1409dfae0(CItem* pItem)
{
    if (pItem == 0)
        return 0;
    Unk_ItemOwnerRef* pTransfer = pItem->FUN_140527930();
    if (pTransfer == 0)
        return 0;
    if (!pItem->FUN_140528e20())
        return 0;
    if (pItem->FUN_1405279c0() != 0 && pItem->FUN_1405279c0()->FUN_140622790() == 0)
        return 0;
    if ((pItem->FUN_140525640() != 0 || pItem->FUN_140526bd0() >= 4) && pTransfer->FUN_140634fa0() > 0)
        return 1;
    return 0;
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DFAE0, ASTooltip, FUN_1409dfae0, 175, 0xE08D17A2); }

// @0x1409dfba0
// MS2-FUNCTIONAL: CItemData::FUN_14053d660 is declared bool but the exe tests its eax without movzx (as part 1)
void ASTooltip::FUN_1409dfba0(MS2Ptr<CItemData> spData, ATL::CAtlList<CStringW>& list, int* pExpiring, unsigned nMax,
    __int64 nExpiry)
{
    if (!spData->function.FUN_14054a3d0())
        return;
    ItemDropContext ctx;
    PCBase* pOwner = reinterpret_cast<PCBase*>(FUN_1409c6540());
    if (pOwner != 0)
    {
        ctx.m_gender = FUN_141658e60_p4(pOwner);
        ctx.m_job = FUN_141654700(pOwner);
    }
    std::vector<ItemDropResult> drops;
    unsigned nBoxId = spData->function.FUN_14054a460();
    if (nBoxId > 0)
        FUN_1405a1fd0_p4()->GetBoxItems(nBoxId, ctx, drops, true);
    if (drops.empty())
        return;
    bool bFollowEndDate = false;
    if (spData->function.FUN_14054a410())
    {
        bool bDefault = false;
        bFollowEndDate = spData->function.xml.FUN_1409e8780(L"isFollowEndDate", bDefault);
    }
    std::vector<ItemDropResult> picked;
    {
        ATL::CAtlList<CStringW> names(10);
        std::sort(drops.begin(), drops.end(), FUN_1409e7a40);
        for (std::vector<ItemDropResult>::iterator it = drops.begin(); it != drops.end(); ++it)
        {
            ItemDropResult drop = *it;
            MS2Ptr<CItemData> spItem = FUN_14053f870(drop.m_itemId);
            if (spItem == 0)
                continue;
            CStringW strName = CStringTable::GetInstance()->FUN_141811980(1, drop.m_itemId);
            const CStringW& rName = strName;
            if (names.Find(rName) != 0)
                continue;
            if (*pExpiring == 0)
            {
                if (drop.HasItemLife() || spData->FUN_14053d660())
                    *pExpiring = 1;
                int nLifeType = 0;
                if (drop.m_itemLife)
                    nLifeType = drop.m_itemLife->m_type;
                if (*pExpiring == 0)
                {
                    if (FUN_14052a3f0(bFollowEndDate, nExpiry, spData->period.expirationType, nLifeType,
                            spItem->period.expirationType))
                        *pExpiring = 1;
                }
            }
            if (drop.m_tooltip != 1)
            {
                if (picked.size() >= nMax)
                    continue;
            }
            names.AddTail(rName);
            picked.push_back(drop);
        }
    }
    std::sort(picked.begin(), picked.end(), FUN_1409e7930);
    for (std::vector<ItemDropResult>::iterator it = picked.begin(); it != picked.end(); ++it)
    {
        ItemDropResult drop = *it;
        MS2Ptr<CItemData> spItem = FUN_14053f870(drop.m_itemId);
        if (spItem == 0)
            continue;
        CStringW strName = CStringTable::GetInstance()->FUN_141811980(1, drop.m_itemId);
        const CStringW& rName = strName;
        CStringW str;
        bool bExpiring = false;
        if (drop.HasItemLife() || spData->FUN_14053d660())
            bExpiring = true;
        int nLifeType = 0;
        if (drop.m_itemLife)
            nLifeType = drop.m_itemLife->m_type;
        if (!bExpiring)
        {
            if (FUN_14052a3f0(bFollowEndDate, nExpiry, spData->period.expirationType, nLifeType,
                    spItem->period.expirationType))
                bExpiring = true;
        }
        if (bExpiring)
            str.Format(L"- %s\n",
                (const wchar_t*)FUN_14028dfa0(CStringW(L"s_item_end_time_tooltip_expiration_prefix"), rName));
        else
            str.Format(L"- %s\n", (const wchar_t*)rName);
        list.AddTail(FUN_14183e9c0(str, drop.vfunc_o18_1()));
    }
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DFBA0, ASTooltip, FUN_1409dfba0, 2207, 0xAB580EF8); }
