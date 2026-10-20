// astooltip.cpp part 1: functions 0x1409c5210-0x1409cc800 (exe order). Included by astooltip.cpp; merged into it when the unit is done.


// Formats one stat option value row; kind 2 (random options) marks the top of the roll range as "best".
// @0x1409c5210
bool FUN_1409c5210(CStringW& strOut, MS2Ptr<CItem> spItem, int nIndex, int nKind, Unk_EnchantPtr<BaseOption> spOption, const CStringW& strValue)
{
    if (spItem == 0 || spOption == 0)
        return false;
    if (nKind != 2)
    {
        if (FUN_1409e5450(nKind))
        {
            strOut = StringFormat(FUN_1409e6010(nKind, spItem.get()), strValue);
            strOut = StringFormat(s_wsText0xbf8, strOut);
        }
        else
        {
            strOut = StringFormat(s_wsText0xbf8, strValue);
        }
        return true;
    }
    std::pair<int, int> range = FUN_140166430()->FUN_1405f64e0(spItem->FUN_1405276c0(), spItem->FUN_140526bd0(), nIndex);
    bool bBest = range.second == spOption->FUN_140266e30();
    if (bBest)
    {
        CStringW strBest = StringFormat(s_wsText0x48d, strValue);
        strOut = StringFormat(s_wsStatRowBest, strBest);
    }
    else if (FUN_140166430()->FUN_1405f67e0(spItem, nIndex, nKind, spOption->FUN_140266e30()) == true)
    {
        strOut = StringFormat(s_wsStatRowBest, strValue);
    }
    else
    {
        strOut = StringFormat(s_wsText0xbf8, strValue);
    }
    return true;
}
// not hooked: reads the unit statics s_ws* without loading them (FUN_1409e5480)

// The special option twin of FUN_1409c5210.
// @0x1409c56f0
bool FUN_1409c56f0(CStringW& strOut, MS2Ptr<CItem> spItem, int nIndex, int nKind, Unk_EnchantPtr<BaseOption> spOption, const CStringW& strValue)
{
    if (spItem == 0 || spOption == 0)
        return false;
    if (nKind != 2)
    {
        if (FUN_1409e5450(nKind))
        {
            strOut = StringFormat(FUN_1409e6010(nKind, spItem.get()), strValue);
            strOut = StringFormat(s_wsText0xbf8, strOut);
        }
        else
        {
            strOut = StringFormat(s_wsText0xbf8, strValue);
        }
        return true;
    }
    std::pair<int, int> range = FUN_140166430()->FUN_1405f6650(spItem->FUN_1405276c0(), spItem->FUN_140526bd0(), nIndex);
    bool bBest = range.second == spOption->FUN_140266e30();
    if (bBest)
    {
        CStringW strBest = StringFormat(s_wsText0x48d, strValue);
        strOut = StringFormat(s_wsStatRowBest, strBest);
    }
    else if (FUN_140166430()->FUN_1405f6a90(spItem, nIndex, nKind, spOption->FUN_140266e30()) == true)
    {
        strOut = StringFormat(s_wsStatRowBest, strValue);
    }
    else
    {
        strOut = StringFormat(s_wsText0xbf8, strValue);
    }
    return true;
}
// not hooked: reads the unit statics s_ws* without loading them (FUN_1409e5480)

// Fills an item drop/reward row object (count, pet rank, icon, name, grade, gemstone level or season).
// @0x1409c5bd0
// MS2-FUNCTIONAL: CItemData::FUN_14053d660 is declared bool (itemdata.cpp) but this caller tests eax without movzx
bool ASObj::FUN_1409c5bd0(ItemDropResult* pDrop)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(pDrop->m_itemId);
    if (spData == 0)
        return false;
    bool bMoney = FUN_1403ba4c0(reinterpret_cast<const int&>(pDrop->m_itemId));
    if (bMoney)
        FUN_1407cb9c0(s_strItemCount, 0);
    else
        FUN_1409c0d20(s_strItemCount, pDrop->vfunc_o18_2());
    if (FUN_140166410()->FUN_14036d570(0x8c))
    {
        if (spData->FUN_14053cc40())
        {
            FUN_1409adc90(s_strItemPetRank, pDrop->vfunc_o18_1());
            FUN_1407cb9c0(s_strDropShadowDisable, 1);
        }
    }
    else
        FUN_1407cbbe0(s_strItemPet, spData->FUN_14053cc40());
    FUN_1407cbbe0(s_strItemCash, spData->FUN_14053e130());
    FUN_1407cbb20(s_strIconPath, FUN_14016a730(spData->FUN_14053fdd0(), 0));
    FUN_1407cbbe0(s_strItemSkin, spData->FUN_14053cf90());
    if (bMoney)
    {
        CStringW strName = FUN_14028dfa0(CStringW(L"s_tooltip_fmt_in_package_money"), FUN_141425950(spData->FUN_14053c510()), FUN_1409eb450(pDrop->vfunc_o18_2()));
        FUN_1407cbb20(s_strItemName, strName);
    }
    else
    {
        CStringW strName = FUN_141425950(spData->FUN_14053c510());
        const CStringW& strNameRef = strName;
        if (spData->FUN_14053d660())
            FUN_1407cbb20(s_strItemName, FUN_14028dfa0(CStringW(L"s_item_end_time_tooltip_expiration_prefix"), strNameRef));
        else
            FUN_1407cbb20(s_strItemName, FUN_141425950(spData->FUN_14053c510()));
    }
    FUN_1409adc90(s_strItemGrade, pDrop->vfunc_o18_1());
    if (spData->FUN_14053d840())
    {
        short nLevel = FUN_140626f20(spData->FUN_14053c510());
        if (nLevel != 0)
            FUN_1409c48f0("gemstoneLevel", nLevel);
    }
    else if (pDrop->m_enchant > 0)
        FUN_1407cb9c0("gemstoneLevel", pDrop->m_enchant);
    else if (spData->FUN_14053dec0() != 0)
    {
        int nSeason = spData->FUN_14053dec0();
        CStringW strSeason = FUN_1409e5320(nSeason);
        FUN_1407cbb20("itemSeason", strSeason);
    }
    FUN_1407cbbe0(s_strItemPiece, spData->FUN_14053d990());
    return true;
}
MS2_REPLACE_METHOD(0x1409C5BD0, ASObj, FUN_1409c5bd0, 1799, 0xE8C98E14);

// The maid contract item: the maid description row, the maid's name and the running manufacture.
// @0x1409c72c0
// MS2-FUNCTIONAL: the recipe id is passed through ecx (mov ecx,[x]; mov r8d,ecx) in the exe; no source form found
void ASTooltip::FUN_1409c72c0(CItem* pItem)
{
    MS2Ptr<CItemData> spData(pItem->FUN_140527840());
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
    FUN_1409adbe0("statDescription", Scaleform::GFx::Value(row.FUN_1422bb870()));
    MS2Ptr<CMaid> spMaid = CUserMaidManager::GetInstance()->GetMaid(pItem->FUN_140526a50());
    if (spMaid.get() != 0)
    {
    CStringW strName = spMaid->FUN_1409eeda0().IsEmpty() ? FUN_1401a9d70()->FUN_141811980(1, pItem->FUN_1405276c0()) : spMaid->FUN_1409eeda0();
    FUN_1409dbbc0(strName);
    MS2Ptr<CManufacture> spManufacture(0);
    if (CManufactureManager::GetInstance()->Lookup(pItem->FUN_140526a50(), spManufacture) != 0)
    {
        BOOL bWorking = spMaid->m_n4c == 1;
        int nStringId = bWorking ? 0x7a4 : 0x7a3;
        CTimeSpan span(spManufacture->FUN_140694200());
        CStringW strProduct(L"");
        unsigned nRecipeId = spManufacture->FUN_1409eedf0();
        {
            MS2Ptr<CMaidRecipe> spRecipe = CMaidRecipeTable::GetInstance()->Find(nRecipeId);
            if (spRecipe.get() != 0)
                strProduct = FUN_1401a9d70()->FUN_141811980(1, spRecipe->productItemId);
        }
        CStringW strRemain(L"");
        if (span.GetTotalSeconds() > 0)
            strRemain = FUN_1412e1e50(span, 1, 1);
        else
            strRemain = FUN_14028de60(0x7b8);
        FUN_1407cbb20("itemManufacture", FUN_140632a60(nStringId, strProduct, strRemain));
    }
    }
}
// not hooked: reads the TSingleton<CMaid*Table/CUserMaidManager/CManufactureManager>::s_instance (DLL-local copies)

// The item movie: the UGC look's resource for UGC items (kind 0x16), else the item data's movie.
// @0x1409c7cc0
void ASTooltip::FUN_1409c7cc0(CItem* pItem)
{
    if ((m_48 & 0x40) != 0)
        return;
    {
        MS2Ptr<CItemData> spData(pItem->FUN_140527840());
        if (spData == 0)
            return;
        if (spData->FUN_14053c5c0() == 0x16)
        {
            if (pItem->FUN_1405278d0() != 0 && pItem->FUN_140525f60() != 0)
            {
                CString strMovie;
                // CItem::FUN_1405278d0 returns the placeholder name of the item's CItemUgc
                if (FUN_14052d220()->FUN_1418859f0(&reinterpret_cast<CItemUgc*>(pItem->FUN_1405278d0())->m_look,
                        &reinterpret_cast<CItemUgc*>(pItem->FUN_1405278d0())->m_blueprint, MS2Ptr<CItem>(pItem)))
                    strMovie = FUN_1401d31f0()->m_strUgcMovie;
                else
                    strMovie = FUN_1410280d0(9, pItem->FUN_1405278d0()->m_strName);
                FUN_1407cba60(s_strItemMovie, strMovie);
            }
        }
        else
            FUN_1407cba60(s_strItemMovie, spData->property.movie);
    }
}
MS2_REPLACE_METHOD(0x1409C7CC0, ASTooltip, FUN_1409c7cc0, 681, 0xD953CC81);
