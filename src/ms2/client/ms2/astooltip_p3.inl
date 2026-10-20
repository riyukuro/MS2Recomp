// astooltip.cpp part 3: functions 0x1409d3010-0x1409d9f30 (exe order). Included by astooltip.cpp; merged into it when the unit is done.

// @0x1409d3010
void ASTooltip::FUN_1409d3010(CItem* pItem)
{
    if (!FUN_140166410_p3()->FUN_14036d570(0xb7))
        return;
    __int64 nOwner = FUN_1409c6540();
    if (nOwner == 0)
        return;
    MS2Ptr<CItemData> spData(pItem->FUN_140527840());
    if (spData == 0)
        return;
    if (spData->FUN_14053e260() == 0)
        return;
    bool bFixed = (m_48 & 4) > 0 || (m_48 & 0x8000) > 0;
    bool bHasDefault = spData->FUN_14053e2b0(0) >= 0;
    if (bFixed && !bHasDefault)
        return;
    // the proxy data of an item is its CItemExtraData (CItem::FUN_140527870 returns the proxy base)
    Unk_PayloadPtr<CItemExtraData> spExtra(reinterpret_cast<CItemExtraData*>(pItem->FUN_140527870()));
    if (spExtra == 0)
        return;
    int nPalette = spExtra->FUN_14059a0b0(0);
    int nColorSN = spExtra->FUN_14059a040(0);
    if (nPalette == 0 || nColorSN < 0)
        return;
    MS2Ptr<ItemColorEx> spColor = FUN_140281980_p3()->GetPaletteColorBySN(nPalette, nColorSN);
    if (spColor == 0 || spColor->m_n2c == 0)
        return;
    ASObj obj(2);
    {
        ASObj color(2);
        bool bAlt = false;
        FUN_140f33250(color, spColor, spData, bAlt);
        obj.FUN_1409adbe0("color", color.FUN_1422bb870());
        obj.FUN_1407cbb20("desc", FUN_1401a9d70_p3()->FUN_141811980(0x48, spColor->m_n2c));
    }
    FUN_1409adbe0("customizeColorData", obj.FUN_1422bb870());
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D3010, ASTooltip, FUN_1409d3010, 1104, 0x85F94BBB); }

// @0x1409d3470
// MS2-FUNCTIONAL: the exe converts the gem id through ecx (a long-typed parameter) and keeps a bool temporary for the row test
void ASTooltip::FUN_1409d3470(CItem* pItem)
{
    MS2Ptr<CItemData> spData(pItem->FUN_140527840());
    if (spData == 0)
        return;
    CStringW str;
    if (spData->FUN_14053cd10())
        str = FUN_1409d9c50(pItem);
    else if (spData->FUN_14053d840())
    {
        if (!FUN_140166410_p3()->FUN_14036d570(0x2e))
            return;
        int nGemId = spData->FUN_14053c510();
        MS2Ptr<CItemGemStoneData> spRow = FUN_14062c280_p3()->FUN_1405b1a60(nGemId);
        if (spRow)
        {
            if (!FUN_140627020(spRow))
            {
                str = FUN_14028de60(0x9c3);
                CIngredientContainer* pIngredients = &spRow->m_ingredients;
                if (!pIngredients->FUN_14026bf70())
                {
                    str.Append(L"\n");
                    CStringW strList;
                    size_t nCount = pIngredients->FUN_14026bf10();
                    for (size_t i = 0; i < nCount; i++)
                    {
                        Unk_IngRef ref = pIngredients->FUN_14026be50(i);
                        if (ref == 0)
                            continue;
                        if (!strList.IsEmpty())
                            strList.Append(L", ");
                        CIngredientInfo* pInfo = ref.operator->();
                        strList.Append(FUN_1401a9d70_p3()->FUN_141811980(1, pInfo->m_a));
                    }
                    str.Append(FUN_14028dfa0(L"s_msg_tooltip_gemstone_enable_upgrade_ingredients", strList));
                }
            }
        }
    }
    else if (spData->FUN_14053c5c0() == 0x10)
        str = FUN_1409da690(pItem);
    else if (spData->FUN_14053dfd0(L"ChatEmoticonAdd"))
        str = FUN_1409daa30(spData);
    if (!str.IsEmpty())
        FUN_1407cbb20("extraComment", str);
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D3470, ASTooltip, FUN_1409d3470, 1471, 0xBE16A635); }

// @0x1409d3a40
void ASTooltip::FUN_1409d3a40(CItem* pItem)
{
    PCBase* pPc = FUN_141bd0cc0_p3(FUN_1403ed2d0_p3());
    if (pPc == 0)
        return;
    ATL::CAtlArray<Unk_QuestItemLink> arrLinks;
    FUN_140764020_p3()->FUN_1416ce860(MS2Ptr<CItem>(pItem), arrLinks);
    if (arrLinks.GetCount() != 0)
    {
        int bEquipQuest = 0;
        CStringW strQuests;
        for (size_t i = 0; i < arrLinks.GetCount(); i++)
        {
            if (arrLinks[i].m_kind == 0)
            {
                CStringW strKey;
                switch (arrLinks[i].m_state)
                {
                case 1:
                    strKey = L"s_msg_tooltip_quest_name_progress";
                    break;
                case 0:
                    strKey = L"s_msg_tooltip_quest_name";
                    break;
                case 2:
                    strKey = L"s_msg_tooltip_quest_name_complete";
                    break;
                }
                if (strQuests.GetLength() != 0)
                    strQuests += L", ";
                strQuests += FUN_1416e5210(arrLinks[i].m_questId, strKey);
            }
            else if (arrLinks[i].m_kind == 1)
                bEquipQuest = 1;
        }
        CStringW strInfo;
        if (strQuests.GetLength() != 0)
            strInfo = FUN_14028dfa0(L"s_msg_tooltip_quest_info", strQuests);
        if (bEquipQuest != 0)
        {
            if (strInfo.GetLength() != 0)
                strInfo += "\n";
            strInfo += FUN_14028b8e0(L"s_msg_tooltip_equip_quest_info");
        }
        if (strInfo.GetLength() != 0)
        {
            FUN_1407cbb20("itemQuestInfo", strInfo);
            int nState = FUN_140764020_p3()->FUN_1416ce6a0(MS2Ptr<CItem>(pItem));
            if (nState == 0)
                FUN_1407cb9c0("questBeginAble", 1);
            else if (nState == 1)
                FUN_1407cb9c0("questProgress", 1);
        }
    }
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D3A40, ASTooltip, FUN_1409d3a40, 1219, 0x3120A701); }

// @0x1409d3f10
void ASTooltip::FUN_1409d3f10(CItem* pItem)
{
    int nState = pItem->FUN_140528ca0();
    __int64 nUnlockTime = pItem->FUN_140528e00();
    if (nState == 0 && nUnlockTime > FUN_140869440())
    {
        FUN_1407cbbe0(s_strItemIconLock, false);
        FUN_1407cbbe0(s_strItemIconUnLock, true);
        CStringW strText;
        CMsTime remain(pItem->FUN_140528e00() - FUN_140869440());
        int nHours = (int)(remain.Get() / 3600);
        int nMinutes = (std::max)((int)(remain.Get() % 3600 / 60), 1);
        if (nHours > 0)
        {
            strText = FUN_14025e7a0_p3()->FUN_1422b0570("$s_itemlock_tooltip_msg_unlock");
            strText = StringFormat(strText, nHours, nMinutes);
        }
        else
        {
            strText = FUN_14025e7a0_p3()->FUN_1422b0570("$s_itemlock_tooltip_msg_unlock2");
            strText = StringFormat(strText, nMinutes);
        }
        FUN_1407cbb20("itemLockInfo", strText);
        return;
    }
    if (nState == 1)
    {
        FUN_1407cbbe0(s_strItemIconLock, true);
        FUN_1407cbbe0(s_strItemIconUnLock, false);
        FUN_1407cbb20("itemLockInfo", FUN_14025e7a0_p3()->FUN_1422b0570("$s_itemlock_tooltip_msg_lock"));
    }
    else
    {
        FUN_1407cbbe0(s_strItemIconLock, false);
        FUN_1407cbbe0(s_strItemIconUnLock, false);
    }
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D3F10, ASTooltip, FUN_1409d3f10, 1072, 0x005C7805); }

// @0x1409d4490
// MS2-FUNCTIONAL: the exe loads nRank through ecx and compares the max level with the operands swapped (source form not found)
void ASTooltip::FUN_1409d4490(CItem* pItem)
{
    if (!FUN_140166410_p3()->FUN_14036d570(0xeb))
        return;
    if (pItem == 0)
        return;
    if (pItem->FUN_140525640() == 0)
        return;
    int nRank = pItem->FUN_140526bd0();
    unsigned nNeed = FUN_1404a1bb0_p3()->GetPetEvolution(pItem->FUN_1405282d0(), nRank);
    if (nNeed == 0)
        return;
    unsigned nLevel = pItem->FUN_140528c20();
    if (nLevel >= *FUN_1401d3200()->PetMaxLevel.Get())
    {
        CStringW strText = StringFormat(s_wsPetEvolutionPoint);
        unsigned nPoint = pItem->FUN_140528bd0();
        CStringW strGauge = StringFormat(L"{0} / {1}", nPoint, nNeed);
        unsigned nPercent = (unsigned)(pItem->FUN_140528bd0() * 100) / nNeed;
        strText.Append(L"gauge:\n\n");
        FUN_1407cbb20("petEvolution", strText);
        FUN_1407cbb20("petEvolutionGauge", strGauge);
        FUN_1409c0d20("petEvolutionPercent", nPercent);
    }
}
// not hooked: reads s_wsPetEvolutionPoint (a DLL-local copy, filled by FUN_1409e5480)

// @0x1409d46e0
void ASTooltip::FUN_1409d46e0(CItem* pItem)
{
    if (pItem == 0)
        return;
    if (pItem->FUN_1405278a0() == 0)
        return;
    Unk_ItemPlusInfo* pInfo = pItem->FUN_1405278a0()->FUN_140630d90();
    if (pInfo != 0 && pInfo->FUN_1408bbc50() > 0)
        FUN_1407cb9c0("unlimited", pInfo->FUN_1408bbc50());
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D46E0, ASTooltip, FUN_1409d46e0, 121, 0x0809F9B2); }

// @0x1409d4760
bool ASTooltip::FUN_1409d4760(CItem* pItem)
{
    if (pItem->FUN_140527840()->FUN_14053d760())
    {
        if (pItem->FUN_140527840()->FUN_14053efd0() == 0)
            return true;
        __int64 nMin = pItem->FUN_1405278a0()->FUN_14062ffb0(0x1b, 3, 0);
        __int64 nMax = pItem->FUN_1405278a0()->FUN_14062ffb0(0x1c, 3, 0);
        ASObj obj(2);
        obj.FUN_1407cb9c0("type", 2);
        obj.FUN_1407cbb20("title", FUN_14082f000(0x1b));
        obj.FUN_1407cb9c0("extraup", 0);
        obj.FUN_1407cbb20("min", FUN_1409e0900((int)nMin));
        obj.FUN_1407cbb20("max", FUN_1409e0900((int)nMax));
        FUN_1409adbe0("statDescription", obj.FUN_1422bb870());
        return true;
    }
    if (pItem->FUN_140527840()->FUN_14053c5c0() == 0xd)
    {
        if (pItem->FUN_140527840()->FUN_14053efd0() == 0)
            return true;
        std::pair<Unk_SocketSpecialStat, int> special = pItem->FUN_1405278a0()->FUN_140630d30()->FUN_1405cb620(0);
        if (special.first != 0)
        {
            ASObj obj(2);
            obj.FUN_1407cb9c0("type", 2);
            obj.FUN_1407cbb20("title", FUN_140630e10(special.first));
            obj.FUN_1407cb9c0("extraup", 0);
            CStringW strValue;
            if (FUN_14081dcd0(special.first))
                strValue = FUN_1409e0a90((float)special.second / 1000.0f);
            else
                strValue = FUN_1409e0900(special.second);
            obj.FUN_1407cbb20("min", strValue);
            obj.FUN_1407cbb20("max", strValue);
            FUN_1409adbe0("statDescription", obj.FUN_1422bb870());
        }
        std::pair<Unk_StatType, int> stat = pItem->FUN_1405278a0()->FUN_140630d30()->FUN_1405cb4e0(0);
        if (stat.first != -1)
        {
            ASObj obj(2);
            obj.FUN_1407cb9c0("type", 2);
            obj.FUN_1407cbb20("title", FUN_14082f000(stat.first));
            obj.FUN_1407cb9c0("extraup", 0);
            CStringW strValue;
            if (FUN_14082f250(stat.first))
                strValue = FUN_1409e0a90((float)stat.second / 1000.0f);
            else
                strValue = FUN_1409e0900(stat.second);
            obj.FUN_1407cbb20("min", strValue);
            obj.FUN_1407cbb20("max", strValue);
            FUN_1409adbe0("statDescription", obj.FUN_1422bb870());
        }
    }
    int nStat = pItem->FUN_140527840()->FUN_14053f7c0();
    if (nStat != -1)
    {
        if (pItem->FUN_140527840()->FUN_14053efd0() == 0)
            return true;
        __int64 nValue = pItem->FUN_1405278a0()->FUN_14062ffb0(nStat, 3, 0);
        if (nValue != 0)
        {
            ASObj obj(2);
            obj.FUN_1407cb9c0("type", 2);
            obj.FUN_1407cbb20("title", FUN_14082f000(nStat));
            obj.FUN_1407cb9c0("extraup", 0);
            if (FUN_14082f250(nStat))
            {
                obj.FUN_1407cbb20("min", FUN_1409e0a90((float)nValue / 1000.0f));
                obj.FUN_1407cbb20("max", FUN_1409e0a90((float)nValue / 1000.0f));
            }
            else
            {
                obj.FUN_1407cbb20("min", FUN_1409e0900((int)nValue));
                obj.FUN_1407cbb20("max", FUN_1409e0900((int)nValue));
            }
            FUN_1409adbe0("statDescription", obj.FUN_1422bb870());
        }
        return true;
    }
    return false;
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D4760, ASTooltip, FUN_1409d4760, 2550, 0x405341EB); }

// @0x1409d5610
void ASTooltip::FUN_1409d5610(int nItemId)
{
    MS2Ptr<CItemData> sp = FUN_14053f870(nItemId);
    if (sp.IsNull())
        return;
    long nKinds = FUN_1409e6fc0(sp->FUN_14053c600());
    FUN_1409eb3b0(s_strItemKinds, nKinds);
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D5610, ASTooltip, FUN_1409d5610, 142, 0x346866BF); }

// @0x1409d56b0
void ASTooltip::FUN_1409d56b0(int nItemId)
{
    if (m_48 & 0x40)
        return;
    MS2Ptr<CItemData> sp = FUN_14053f870(nItemId);
    if (sp.IsNull())
        return;
    FUN_1407cba60(s_strItemMovie, sp->property.movie);
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D56B0, ASTooltip, FUN_1409d56b0, 178, 0x8173E7A7); }

// @0x1409d5770
void ASTooltip::FUN_1409d5770(int nItemId)
{
    MS2Ptr<CItemData> sp = FUN_14053f870(nItemId);
    if (sp.IsNull())
        return;
    FUN_1407cbb20(s_strIconPath, FUN_14016a730(sp->FUN_14053fdd0(), 0));
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D5770, ASTooltip, FUN_1409d5770, 214, 0x8CD290D2); }

// @0x1409d5850
void ASTooltip::FUN_1409d5850(int nItemId)
{
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D5850, ASTooltip, FUN_1409d5850, 10, 0x96F6F902); }

// @0x1409d5860
void ASTooltip::FUN_1409d5860(int nItemId, int nRarity)
{
    MS2Ptr<CItem> sp(new CItem);
    if (sp->FUN_140523c40(nItemId, nRarity, 0))
        FUN_1409cd9c0(sp.get());
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D5860, ASTooltip, FUN_1409d5860, 178, 0x98E59B9F); }

// @0x1409d5920
void ASTooltip::FUN_1409d5920(int nItemId)
{
    MS2Ptr<CItemData> sp = FUN_14053f870(nItemId);
    if (sp.IsNull())
        return;
    if (sp->FUN_14053c5c0() != 0x19)
        return;
    int nBoxId = sp->function.FUN_14054a460();
    if (nBoxId == 0)
        return;
    PCBase* pPc = FUN_141bd0cc0_p3(FUN_1403ed2d0_p3());
    if (pPc == 0)
        return;
    std::vector<ItemDropResult> results;
    ItemDropContext ctx;
    ctx.m_job = FUN_141654700_p3(pPc);
    ctx.m_gender = FUN_141658e60_p3(pPc);
    if (!FUN_1405a1fd0_p3()->GetBoxItems(nBoxId, ctx, results, true))
        return;
    FUN_1409e72a0(&results);
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D5920, ASTooltip, FUN_1409d5920, 363, 0x5540657B); }

// @0x1409d5aa0
void ASTooltip::FUN_1409d5aa0(int nItemId)
{
    CStringW str = FUN_1401a9d70_p3()->FUN_141811c90(nItemId, "tooltipDescription");
    FUN_1403b4750()->FUN_1416fb340(str);
    FUN_1407cbb20("itemDescription", str);
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D5AA0, ASTooltip, FUN_1409d5aa0, 189, 0xA32EDB32); }

// @0x1409d5b70
// MS2-FUNCTIONAL: the housing id argument is staged through ecx in the exe (unsolved /Od idiom)
void ASTooltip::FUN_1409d5b70(int nItemId)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData == 0)
        return;
    CStringW strGuide = FUN_1401a9d70_p3()->FUN_141811c90(nItemId, "guideDescription");
    int nObjCode = spData->install.objCode;
    if (nObjCode != 0)
    {
        if (FUN_1407077c0(nObjCode) != 0)
            strGuide = FUN_14052bd00(0xafa, strGuide);
        if (FUN_140707710(nObjCode) != 0)
            strGuide = FUN_14052bd00(0xaf9, strGuide);
    }
    if (spData->FUN_14053cb80())
    {
        int nHousingId = spData->FUN_14053c510();
        MS2Ptr<ItemHousing> spHousing = FUN_140281980_p3()->GetHousing(nHousingId);
        if (spHousing == 0)
            return;
        unsigned short nLevel = spHousing->interiorLevel;
        unsigned nTrophyId = spHousing->trophyID;
        unsigned nTrophyLevel = spHousing->trophyLevel;
        int nPriceCount = spHousing->priceCount;
        if (FUN_140166410_p3()->FUN_14036d570(0xdb) && nLevel > 0 && nPriceCount == 1)
        {
            UGCCubeCategoryTable::InteriorPtr spInterior = TSingleton<UGCCubeCategoryTable>::GetInstance()->GetInterior(spHousing->categoryIndex);
            if (spInterior.get() != 0)
            {
                int nCurrent = nLevel;
                nLevel = nCurrent > spInterior->m_nRequireLevel ? nLevel : spInterior->m_nRequireLevel;
            }
            if (nLevel > DAT_143ab291c)
            {
                if (!strGuide.IsEmpty())
                    strGuide.Append(L"\n");
                strGuide.Append(BlockFormat(0x6fa, nLevel));
            }
        }
        if (FUN_140936640(FUN_1406c7600(), nTrophyId, nTrophyLevel) == 0)
        {
            CStringW strTrophy = FUN_14093bd40(nTrophyId, nTrophyLevel, CStringW(L""));
            if (!strTrophy.IsEmpty())
            {
                if (!strGuide.IsEmpty())
                    strGuide.Append(L"\n");
                strGuide.Append(FUN_14028dfa0(CStringW(L"s_construct_require_trophy"), strTrophy));
            }
        }
    }
    if (!m_50.IsEmpty())
    {
        if (!strGuide.IsEmpty())
            strGuide.Append(L"\n");
        strGuide.Append(m_50);
    }
    FUN_1407cbb20("itemGuideDescription", strGuide);
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D5B70, ASTooltip, FUN_1409d5b70, 1438, 0x2F4EEABA); }

// @0x1409d6120
// MS2-FUNCTIONAL: the exe destroys the main description before the emoticon branch inside one if/else (frame layout differs)
void ASTooltip::FUN_1409d6120(int nItemId)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData == 0)
        return;
    {
        CStringW strMain = FUN_1401a9d70_p3()->FUN_141811c90(nItemId, "mainDescription");
        if (strMain.GetLength() != 0)
        {
            ASObj obj(2);
            obj.FUN_1407cb9c0("type", 0);
            obj.FUN_1407cbb20("text", strMain);
            FUN_1409adbe0("statDescription", obj.FUN_1422bb870());
            return;
        }
    }
    CStringW strText;
    if (spData->FUN_14053dfd0(CStringW(L"ChatEmoticonAdd")))
        strText = FUN_1409daff0(spData);
    if (strText.GetLength() != 0)
    {
        ASObj obj(2);
        obj.FUN_1407cb9c0("type", 0);
        obj.FUN_1407cbb20("text", strText);
        FUN_1409adbe0("statDescription", obj.FUN_1422bb870());
    }
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D6120, ASTooltip, FUN_1409d6120, 876, 0x748328C9); }

// @0x1409d64a0
void ASTooltip::FUN_1409d64a0(int nItemId, int nRank, int nLevel, int nAdditional)
{
    if (FUN_1409c6540() == 0)
        return;
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (!spData)
        return;
    ASArray arr(2);
    FUN_1409deea0(&arr, nItemId, nRank, nLevel, nAdditional);
    FUN_1409df180(&arr, nItemId);
    if (spData->FUN_14053cb80())
    {
        FUN_1409de140(&arr, nItemId, nRank);
        FUN_1409de630(&arr, nItemId);
        FUN_1409dea00(&arr, nItemId);
    }
    else if (spData->FUN_14053d840())
    {
        FUN_1409de140(&arr, nItemId, nRank);
        FUN_1409df760(&arr, spData);
    }
    else
    {
        FUN_1409de140(&arr, nItemId, nRank);
    }
    FUN_1409deb80(&arr, nItemId);
    FUN_1409df400(&arr, nItemId);
    FUN_1409df5b0(&arr, nItemId);
    FUN_1409adbe0("extraDescription", arr.FUN_1422bb870());
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D64A0, ASTooltip, FUN_1409d64a0, 650, 0x9A297696); }

// @0x1409d6730
void ASTooltip::FUN_1409d6730(int nItemId)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData == 0)
        return;
    if (spData->FUN_14053dd30() <= 0)
        return;
    TPtrValue<MaidDesc> spDesc = CMaidDescTable::GetInstance()->Find(spData->FUN_14053dd30());
    if (!spDesc)
        return;
    TPtrValue<MaidInfo> spInfo = CMaidInfoTable::GetInstance()->Find(spData->FUN_14053dd30());
    if (!spInfo)
        return;
    CStringW strIcon(spInfo->FUN_1409eee80() != 0 ? L"export_common_icon_meso" : L"export_common_icon_merat");
    CStringW strText = BlockFormat(0x7a2, spDesc->specialty, FUN_140763e10(spInfo->salary), strIcon);
    ASObj row(2);
    row.FUN_1407cb9c0("type", 0);
    row.FUN_1407cbb20("text", strText);
    FUN_1409adbe0("statDescription", row.FUN_1422bb870());
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D6730, ASTooltip, FUN_1409d6730, 763, 0x6733EB1B); }

// @0x1409d6a40
void ASTooltip::FUN_1409d6a40(int nItemId, __int64 nMinutes)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData == 0)
        return;
    if (spData->period.usePeriod > 0 || spData->FUN_14053ce20() || nMinutes > 0)
    {
        CStringW strPeriod(L"");
        CStringW strDays(L"");
        CStringW strHours(L"");
        CStringW strMinutes(L"");
        __int64 nSeconds = 0;
        if (spData->period.usePeriod > 0)
            nSeconds = spData->period.usePeriod * 60;
        else if (spData->FUN_14053ce20())
            nSeconds = *FUN_1401d3200()->PCBangItemDefaultPeriod.Get() * 60;
        if (nMinutes > 0)
            nSeconds = nMinutes * 60;
        ATL::CTimeSpan span(nSeconds);
        if (span.GetDays() > 0)
            strDays = FUN_14086d060(0xc5, span.GetDays());
        if (span.GetHours() > 0)
        {
            strHours = FUN_14086cfc0(0xc6, span.GetHours());
            if (span.GetDays() > 0)
                strHours = StringFormat(L" {0}", strHours);
        }
        if (span.GetMinutes() > 0)
        {
            strMinutes = FUN_14086cfc0(199, span.GetMinutes());
            if (span.GetDays() > 0 || span.GetHours() > 0)
                strMinutes = StringFormat(L" {0}", strMinutes);
        }
        strPeriod = StringFormat(L"{0}{1}{2}", strDays, strHours, strMinutes);
        if (spData->FUN_14053ce20())
            FUN_1407cbb20("itemUsePeriod", FUN_14052bd00(0xc0, strPeriod));
        else if (spData->FUN_14053cde0())
            FUN_1407cbb20("itemUsePeriod", FUN_14052bd00(0xc1, strPeriod));
        else
            FUN_1407cbb20("itemUsePeriod", FUN_14052bd00(0xbe, strPeriod));
    }
    else
    {
        CMsTime tNull(0);
        if (spData->period.expiration > tNull)
        {
            int nYear = spData->period.expiration.GetYear();
            int nMonth = spData->period.expiration.GetMonth();
            int nDay = spData->period.expiration.GetDay();
            int nHour = spData->period.expiration.GetHour();
            int nMinute = spData->period.expiration.GetMinute();
            FUN_1407cbb20("itemUsePeriod", FUN_14052bd00(0xbf, BlockFormat(0xb8, nYear, nMonth, nDay, nHour, nMinute)));
        }
        else if (spData->period.expirationType == 1)
        {
            unsigned nCount = spData->period.numberOfWeeksMonths;
            if (nCount == 0)
                nCount = 1;
            FUN_1407cbb20("itemUsePeriod", FUN_14028dfa0(CStringW(L"s_item_end_time_tooltip_expirationtype_weekly"), nCount));
        }
        else if (spData->period.expirationType == 2)
        {
            unsigned nCount = spData->period.numberOfWeeksMonths;
            if (nCount == 0)
                nCount = 1;
            FUN_1407cbb20("itemUsePeriod", FUN_14028dfa0(CStringW(L"s_item_end_time_tooltip_expirationtype_monthly"), nCount));
        }
        else if (!spData->period.termTag.IsEmpty())
        {
            CMsTime end = TermTagManagerCli::GetInstance()->GetEndTime(spData->period.termTag);
            int nYear = end.GetYear();
            int nMonth = end.GetMonth();
            int nDay = end.GetDay();
            int nHour = end.GetHour();
            int nMinute = end.GetMinute();
            FUN_1407cbb20("itemUsePeriod", FUN_14052bd00(0xbf, BlockFormat(0xb8, nYear, nMonth, nDay, nHour, nMinute)));
        }
    }
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D6A40, ASTooltip, FUN_1409d6a40, 2638, 0xD20CA894); }

// @0x1409d7560
void ASTooltip::FUN_1409d7560(int nItemId, int nRank)
{
    MS2Ptr<CItemData> sp = FUN_14053f870(nItemId);
    if (sp.IsNull())
        return;
    if (!sp->FUN_14053cc40())
        return;
    FUN_1409adc90(s_strItemPetRank, nRank);
    FUN_1407cb9c0(s_strDropShadowDisable, 1);
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D7560, ASTooltip, FUN_1409d7560, 187, 0xFBC6422C); }

// @0x1409d7630
void ASTooltip::FUN_1409d7630(int nItemId)
{
    MS2Ptr<CItemData> sp = FUN_14053f870(nItemId);
    if (sp == 0)
        return;
    CStringW str;
    if (sp->FUN_14053dfd0(L"ChatEmoticonAdd"))
        str = FUN_1409daa30(sp);
    if (!str.IsEmpty())
        FUN_1407cbb20("extraComment", str);
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D7630, ASTooltip, FUN_1409d7630, 365, 0xCCE37309); }

// @0x1409d77b0
void ASTooltip::FUN_1409d77b0(int nItemId)
{
    MS2Ptr<CItemData> sp = FUN_14053f870(nItemId);
    if (sp == 0)
        return;
    int nSeason = sp->FUN_14053dec0();
    ItemGachaBoxTable* pTable = FUN_14052d230();
    if (pTable == 0)
        return;
    if (pTable->FUN_14059eec0(nItemId) == true)
        nSeason = pTable->FUN_14059ebb0(nItemId);
    if (nSeason == 0)
        return;
    if (!pTable->FUN_14059ef70(nSeason))
        return;
    CStringW str = FUN_1409e5320(nSeason);
    FUN_1407cbb20("itemSeason", str);
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D77B0, ASTooltip, FUN_1409d77b0, 330, 0xAD681CF7); }

// @0x1409d7900
void ASTooltip::FUN_1409d7900(int nItemId)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (!spData)
        return;
    PCBase* pPc = FUN_141bd0cc0_p3(FUN_1403ed2d0_p3());
    if (pPc == 0)
        return;
    ItemFunction& func = spData->function;
    if (func.name == L"ItemChangeBeauty")
    {
        unsigned nCount = func.parameter.FUN_1408d2380();
        if (nCount == 0)
            return;
        if (nCount > 0)
        {
            int nShopId = func.parameter.FUN_1408d1fd0(0, 0);
            if (nShopId == 0)
                return;
            Unk_SocketPtr<Unk_TooltipBeautyItems> spItems = FUN_1406e5af0(nShopId);
            if (spItems == 0 || FUN_1405729c0(spItems.operator->()) == true)
                return;
            std::vector<ItemDropResult> drops;
            size_t nItems = spItems->GetCount();
            drops.reserve(nItems);
            int nGender = FUN_141658e60_p3(pPc);
            bool bGenderOnly = static_cast<Unk_ItemDataIntView*>(spData.operator->())->FUN_14053c940(nGender) == 1;
            for (size_t i = 0; i < nItems; i++)
            {
                MS2Ptr<CItemData> spItem(spItems->operator[](i));
                if (spItem == 0)
                    continue;
                if (bGenderOnly && static_cast<Unk_ItemDataIntView*>(spItem.operator->())->FUN_14053c940(nGender) == 0)
                    continue;
                int nId = spItem->FUN_14053c510();
                int nRank = FUN_14053feb0(nId);
                ItemDropResult drop(nId, 0, nRank, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
                drops.push_back(drop);
            }
            if (drops.empty() == true)
                return;
            FUN_1409e72a0(&drops);
        }
    }
    else if (func.name == L"OpenCoupleEffectBox")
    {
        unsigned nCount = func.parameter.FUN_1408d2380();
        if (nCount < 2)
            return;
        int nId = func.parameter.FUN_1408d1fd0(0, 0);
        if (nId == 0)
            return;
        MS2Ptr<CItemData> spItem = FUN_14053f870(nId);
        if (spItem == 0)
            return;
        int nRank = func.parameter.FUN_1408d1fd0(1, 0);
        if (nRank == 0)
            return;
        std::vector<ItemDropResult> drops;
        drops.push_back(ItemDropResult(nId, 0, nRank, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
        FUN_1409e72a0(&drops);
    }
    else if (func.name == L"ItemRemakeScroll")
    {
        unsigned nCount = func.parameter.FUN_1408d2380();
        if (nCount == 0)
            return;
        unsigned nScrollId = func.parameter.FUN_1408d1f60(0, 0);
        CItemRemakeScrollDataPtr spInfo = CItemRemakeScrollTable::GetInstance()->GetData(nScrollId);
        if (spInfo == 0 || spInfo->m_arrItemTypes.IsEmpty() == true)
            return;
        std::vector<ItemDropResult> drops;
        const ATL::CAtlArray<unsigned>& ids = spInfo->m_arrItemTypes;
        const ATL::CAtlArray<unsigned>& ranks = spInfo->m_arrRanks;
        int nRank = ranks.IsEmpty() ? 1 : ranks[0];
        int nJob = FUN_141654700_p3(pPc);
        for (size_t i = 0; i < ids.GetCount(); i++)
        {
            unsigned nId = ids[i];
            MS2Ptr<CItemData> spItem = FUN_14053f870(nId);
            if (spItem == 0)
                continue;
            if (!spItem->limit.FUN_140545c80(nJob))
                continue;
            if (!spItem->limit.FUN_140545da0(nJob))
                continue;
            drops.push_back(ItemDropResult(nId, 0, nRank, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
        }
        FUN_1409e72a0(&drops);
    }
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D7900, ASTooltip, FUN_1409d7900, 2552, 0x6AF15DEB); }

// @0x1409d8300
void ASTooltip::FUN_1409d8300(int nItemId)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData == 0)
        return;
    if (spData->function.name != L"SuperWorldChat")
        return;
    unsigned long nColor1 = DAT_1439f87c0;
    unsigned long nColor2 = DAT_1439f87f0;
    unsigned long nSize = 1;
    CStringW strIcon(DAT_143aef3b8);
    FUN_14183eba0(nItemId, strIcon, nSize, nColor1, nColor2);
    CStringW strPreview = FUN_14028dfa0(CStringW(L"s_html_chat_super_preview"), strIcon, nColor1, FUN_1401a9d70_p3()->FUN_141811980(1, nItemId));
    ASObj obj(2);
    obj.FUN_1407cbb20("text", strPreview);
    obj.FUN_1409c4990("colorIdx", nSize);
    FUN_1409adbe0("previewSuperWorldChat", obj.FUN_1422bb870());
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D8300, ASTooltip, FUN_1409d8300, 606, 0xC0DF2680); }

// @0x1409d8570
void ASTooltip::FUN_1409d8570(CItem* pItem)
{
    if (FUN_1409c4b20_p3()->FUN_140531270(MS2Ptr<CItem>(pItem)) == 0)
        return;
    int nItemId = pItem->FUN_1405276c0();
    if (pItem->FUN_140529640() != 0)
        nItemId = pItem->FUN_140529640();
    int nSockets = 0;
    if (pItem->FUN_1405279c0() != 0)
        nSockets = pItem->FUN_1405279c0()->FUN_140620a20();
    FUN_1409d8650(nItemId, pItem->FUN_140526bd0(), nSockets);
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D8570, ASTooltip, FUN_1409d8570, 212, 0xF9182D6C); }

// @0x1409d8650
void ASTooltip::FUN_1409d8650(int nItemId, int nGrade, int nSockets)
{
    bool bGacha = false;
    if (FUN_14052d230() != 0)
        bGacha = FUN_14052d230()->FUN_14059e340(nItemId) == 0 ? false : true;
    MS2SvrPtr<CIngredientContainer> spIngredients(0);
    if (bGacha)
        spIngredients = FUN_140535300_p3()->FUN_14052e730(nItemId);
    else
        spIngredients = FUN_140535300_p3()->FUN_14052e810(nItemId, nGrade, nSockets);
    if (spIngredients == 0)
        return;
    FUN_1409e7460(spIngredients->FUN_14026c230());
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D8650, ASTooltip, FUN_1409d8650, 420, 0x50CA6567); }

// @0x1409d8800
void ASTooltip::FUN_1409d8800(MS2Ptr<CItemData> spData)
{
    if (spData == 0)
        return;
    if (!FUN_1406a6030(spData))
        return;
    if (static_cast<Unk_ItemDataMeratView*>(spData.operator->())->FUN_14053d740() == 0)
        FUN_1407cbb20("ugcItemLimitRegister", FUN_14028de60(0x9b9));
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D8800, ASTooltip, FUN_1409d8800, 206, 0xE07649E6); }

// @0x1409d88e0
void ASTooltip::FUN_1409d88e0(MS2Ptr<CItem> spItem)
{
    if (spItem == 0 || spItem->FUN_140527840() == 0 || FUN_1409c6540() == 0)
        return;
    if (!FUN_1406a6030(MS2Ptr<CItemData>(spItem->FUN_140527840())))
        return;
    Unk_TooltipItemOwner owner;
    owner.FUN_1409aff60();
    owner.m_nAccount = DAT_143ab2820;
    owner.m_nType = DAT_143ab2830;
    owner.m_pCharacter = (void*)DAT_143ab2838;
    owner.m_n18 = DAT_143ab2834;
    MS2Ptr<CItemData> spData(spItem->FUN_140527840());
    bool bRegistrable = false;
    if (spItem->FUN_140525f10() != 0 || spItem->FUN_140526010() != 0)
    {
        if (spItem->FUN_140525f60())
            bRegistrable = FUN_1406a5a50(spItem, &owner);
        else
            bRegistrable = static_cast<Unk_ItemDataMeratView*>(spData.operator->())->FUN_14053d740() == 1;
    }
    else if (spItem->FUN_140525680())
    {
        if (spItem->FUN_140525790())
            bRegistrable = FUN_1406a5a50(spItem, &owner);
        else
            bRegistrable = static_cast<Unk_ItemDataMeratView*>(spData.operator->())->FUN_14053d740() == 1;
    }
    if (!bRegistrable)
        FUN_1407cbb20("ugcItemLimitRegister", FUN_14028de60(0x9b9));
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D88E0, ASTooltip, FUN_1409d88e0, 775, 0xA2C0CBD9); }

// @0x1409d8bf0
void ASTooltip::FUN_1409d8bf0(bool bEnable)
{
    if (bEnable)
        FUN_1407cbb20(s_strItemEquip, FUN_14028de60(0x58a));
    else
        FUN_1409c0e60(s_strItemEquip, L"");
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D8BF0, ASTooltip, FUN_1409d8bf0, 123, 0xFF195793); }

// @0x1409d8d90
void ASTooltip::FUN_1409d8d90(CItem* pItem, CStringW& strOut)
{
    if (pItem == 0)
        return;
    Unk_EnchantPtr<CItemEnchantInfo> spEnchant(pItem->FUN_1405278a0()->FUN_140630d60());
    if (!spEnchant)
        return;
    if (!pItem->FUN_140527840()->FUN_14053cbc0())
        return;
    if (pItem->FUN_1405258b0() != 0)
        return;
    int bNoEnchant = pItem->FUN_140525c60() != 0 || static_cast<Unk_ItemDataIntView*>(static_cast<CItemData*>(pItem->FUN_140527840()))->FUN_14053d660() != 0 || pItem->FUN_140525ca0() != 0;
    if (pItem->FUN_140527840()->limit.exceptEnchant || bNoEnchant != 0)
    {
        if (!strOut.IsEmpty())
            strOut.Append(L"\n");
        strOut.Append(FUN_14028de60(0x94e));
        return;
    }
    bool bEnchantable = true;
    if (CItemEnchantLimitTable::GetInstance()->FUN_14058df90(pItem) == 0)
        bEnchantable = false;
    if (bEnchantable)
    {
        if (!strOut.IsEmpty())
            strOut.Append(L"\n");
        if (spEnchant->FUN_14058c8a0() == 0)
        {
            strOut.Append(FUN_14028de60(0x959));
            if (FUN_140166410_p3()->FUN_14036d570(0xa6))
            {
                unsigned nLevel = CItemEnchantTransformTable::GetInstance()->FUN_140592620(pItem->FUN_1405276c0());
                if (nLevel != 0)
                {
                    strOut.Append(L"\n");
                    strOut.Append(FUN_14028dfa0(CStringW(L"s_itemenchant_transform_valid_item"), nLevel));
                }
            }
        }
        else
        {
            strOut.Append(FUN_14028de60(0x95a));
        }
        if (spEnchant->FUN_14058ccf0() > 0)
        {
            if (!strOut.IsEmpty())
                strOut.Append(L"\n");
            strOut.Append(FUN_14028dfa0(CStringW(L"s_itemenchant_fail_stack_count"), spEnchant->FUN_14058ccf0()));
        }
    }
    else
    {
        if (spEnchant->FUN_14058c8a0() == 0)
        {
            if (FUN_140166410_p3()->FUN_14036d570(0xa6))
            {
                unsigned nLevel = CItemEnchantTransformTable::GetInstance()->FUN_140592620(pItem->FUN_1405276c0());
                if (nLevel != 0)
                {
                    strOut.Append(L"\n");
                    strOut.Append(FUN_14028dfa0(CStringW(L"s_itemenchant_transform_valid_item"), nLevel));
                }
            }
        }
    }
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D8D90, ASTooltip, FUN_1409d8d90, 1423, 0x01772AAA); }

// @0x1409d9330
void ASTooltip::FUN_1409d9330(CItem* pItem, CStringW& strOut)
{
    if (pItem == 0)
        return;
    if (static_cast<Unk_TooltipItemView*>(pItem)->FUN_140526470(2) == 1)
    {
        if (!strOut.IsEmpty())
            strOut.Append(L"\n");
        if ((m_48 & 0x400) != 0 || (m_48 & 0x1000) != 0)
        {
            CStringW str;
            if (pItem->FUN_140525640() != 0)
                str = FUN_14028b8e0(L"s_tooltip_petremake_enable");
            else
                str = FUN_14028de60(0xbfa);
            strOut.Append(str);
        }
        else
        {
            CStringW str;
            if (pItem->FUN_140525640() != 0)
            {
                int nCount = pItem->FUN_140527300();
                str = FUN_14028dfa0(L"s_tooltip_petremake_count", nCount);
            }
            else
            {
                int nCount = pItem->FUN_140527300();
                str = FUN_1408116a0(0xbf9, nCount);
            }
            strOut.Append(str);
        }
    }
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D9330, ASTooltip, FUN_1409d9330, 683, 0x416C252A); }

// @0x1409d95f0
void ASTooltip::FUN_1409d95f0(CItem* pItem, CStringW& strOut)
{
    if (!FUN_140166410_p3()->FUN_14036d570(0x38))
        return;
    if (pItem == 0)
        return;
    if (pItem->FUN_140527840() == 0)
        return;
    if (!pItem->FUN_140527840()->FUN_14053d800())
        return;
    if (pItem->FUN_140527030() != 0)
        return;
    if (FUN_140634230(MS2Ptr<CItem>(pItem)))
        return;
    CItemEnchantInfo* pEnchant = pItem->FUN_1405278a0()->FUN_140630d60();
    if (pEnchant != 0 && !pEnchant->FUN_14058c9a0())
        return;
    int nRemain = pItem->FUN_1405274e0();
    if (nRemain <= 0)
        return;
    if (!strOut.IsEmpty())
        strOut.Append(L"\n");
    if (pItem->FUN_140527580() == 0)
    {
        CStringW str = FUN_14028b8e0(L"s_item_repacking_disable");
        strOut.Append(str);
    }
    else
    {
        CStringW strKey(L"s_item_repacking_limit_count");
        if (pItem->FUN_140525640() != 0)
        {
            if (!FUN_140166410_p3()->FUN_14036d570(0x101))
                return;
            strKey = L"s_item_repacking_pet_limit_count";
        }
        int nUsed = pItem->FUN_140527530();
        int nMax = pItem->FUN_140527580();
        CStringW str = FUN_14028dfa0(strKey, nMax, nUsed);
        strOut.Append(str);
    }
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D95F0, ASTooltip, FUN_1409d95f0, 679, 0x1836DFFB); }

// @0x1409d98a0
void ASTooltip::FUN_1409d98a0(CItem* pItem, CStringW& strText)
{
    if (pItem == 0)
        return;
    if (!FUN_140166410_p3()->FUN_14036d570(0x3a))
        return;
    if (pItem->FUN_1405258b0() == 0)
        return;
    if (FUN_1409c4b20_p3()->FUN_140531270(MS2Ptr<CItem>(pItem)) == 0)
    {
        if (!strText.IsEmpty())
            strText.Append(L"\n");
        CStringW str = FUN_14028de60(0xc44);
        strText.Append(str);
    }
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D98A0, ASTooltip, FUN_1409d98a0, 247, 0x20F31EEC); }

// @0x1409d99a0
void ASTooltip::FUN_1409d99a0(CItem* pItem, CStringW& strText)
{
    if (pItem == 0)
        return;
    if (!FUN_140166410_p3()->FUN_14036d570(0x6f))
        return;
    if (pItem->FUN_140527840() == 0)
        return;
    if (pItem->FUN_140527840()->fusion.fusionable == 0)
        return;
    if (!strText.IsEmpty())
        strText.Append(L"\n");
    strText.Append(FUN_14028b8e0(L"s_item_merge_valid_item"));
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D99A0, ASTooltip, FUN_1409d99a0, 242, 0xE8D921E7); }

// @0x1409d9aa0
// MS2-FUNCTIONAL: the exe passes the item id to GetData through ecx (an argument conversion; source form not found)
void ASTooltip::FUN_1409d9aa0(CItem* pItem, CStringW& strText)
{
    if (pItem == 0)
        return;
    int nItemId = pItem->FUN_1405276c0();
    CExtractionItemInfoPtr spRow = FUN_14052d1f0_p3()->GetData(nItemId);
    if (spRow.get() != 0)
    {
        unsigned nTry = pItem->FUN_1405292a0();
        if (!strText.IsEmpty())
            strText.Append(L"\n");
        if (nTry > 0)
            strText.Append(FUN_14028dfa0(L"s_itemextraction_trycount", nTry, spRow->m_nScrollCount));
        else
            strText.Append(FUN_14028b8e0(L"s_itemextraction_invalid"));
    }
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D9AA0, ASTooltip, FUN_1409d9aa0, 424, 0x4D23CBFE); }

// @0x1409d9c50
CStringW ASTooltip::FUN_1409d9c50(CItem* pItem)
{
    CStringW str;
    if (pItem == 0)
        return str;
    MS2Ptr<CItemData> spData(pItem->FUN_140527840());
    if (spData.IsNull())
        return str;
    if (!spData->FUN_14053cd10())
        return str;
    if (pItem->FUN_140525680() && pItem->FUN_140527990() != 0 && FUN_140632780_p3(pItem->FUN_140527990()))
        return FUN_1409d9f30(spData);
    int nCount = pItem->FUN_140527340();
    if (nCount > 0)
        str = FUN_1408116a0(0x9bb, nCount);
    else
        str = FUN_1408116a0(0x9bc, nCount);
    return str;
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D9C50, ASTooltip, FUN_1409d9c50, 723, 0x63A8522D); }
