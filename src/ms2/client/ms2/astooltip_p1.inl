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
        {
            MS2Ptr<CMaidRecipe> spRecipe = CMaidRecipeTable::GetInstance()->Find(spManufacture->FUN_1409eedf0());
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

// The equipment sets of the item: per set the pieces (equipped ones highlighted) and the option parts by piece count.
// @0x1409c8020
// MS2-FUNCTIONAL: /Od frame is 0x10 larger (lambda/list temporaries placed differently); behaviour as the exe
void ASTooltip::FUN_1409c8020(CItem* pItem)
{
    if (pItem == 0)
        return;
    if (!SetItemTable::GetInstance()->HasSetItem(pItem->FUN_140527840()->FUN_14053c560()))
    {
        FUN_1409c8df0(pItem->FUN_1405276c0());
        return;
    }
    int nItemGender = 2;
    int nFixedGender = pItem->FUN_140525cf0();
    if (nFixedGender == 0)
    {
        MS2Ptr<CItemData> spData = FUN_14053f870(pItem->FUN_1405276c0());
        if (spData == 0)
            return;
        nItemGender = spData->limit.genderLimit;
    }
    if (nItemGender == 3)
        nItemGender = 2;
    FUN_1409e5480();
    int nActiveColor = 0xd205;
    int nInactiveColor = 0x505050;
    int nEquippedColor = 0xffffff;
    const CStringW& strRowFormat = s_wsSetNameRow;
    const CStringW& strPartFormat = s_wsSetTitle;
    const CStringW& strStatFormat = s_wsSetStatRow;
    std::vector<SetItemInfoPtr> sets;
    SetItemTable::GetInstance()->GetSetItemInfos(pItem->FUN_140527840()->FUN_14053c560(), sets);
    ASArray arr(2);
    for (unsigned i = 0; i < sets.size(); i++)
    {
        CStringW strText;
        if (sets[i]->IsDisableTooltip())
            continue;
        ATL::CAtlArray<unsigned> pieces;
        SetItemTable::GetInstance()->FUN_1407c50e0(sets[i]->FUN_1407ad550(), &pieces);
        unsigned nEquipped = 0;
        unsigned nRequired = (unsigned)sets[i]->GetItemCount();
        CStringW strPieces;
        int nPcGender = 2;
        PCBase* pPc = FUN_141bd1290(FUN_1403ed2d0_p1(), pItem->FUN_140526b10());
        if (pPc == 0 && pItem->FUN_140526b10() == 0)
            pPc = reinterpret_cast<PCBase*>(FUN_1409c6540());
        std::list<MS2Ptr<CEquipItem> > equipped;
        if (pPc != 0)
        {
            FUN_1416561a0_p1(pPc)->FUN_1411e1fc0(equipped, 2);
            nPcGender = FUN_141658e60_p1(pPc);
            if (nPcGender == 3)
                nPcGender = 2;
        }
        int nGender;
        if (nItemGender == 2)
            nGender = nPcGender;
        else
            nGender = nItemGender;
        bool bValid = true;
        for (unsigned j = 0; j < pieces.GetCount(); j++)
        {
            bool bClassBound = false;
            unsigned nPieceId = pieces.GetAt(j);
            MS2Ptr<CItemData> spData = FUN_14053f870(nPieceId);
            if (spData == 0)
                continue;
            int nClassCount = 4;
            for (int k = 0; k < nClassCount; k++)
            {
                if (spData->FUN_14053eba0()->FUN_14054b450(DAT_142dbac18[k]))
                {
                    bClassBound = true;
                    break;
                }
            }
            if (bClassBound || spData->limit.genderLimit != 2)
            {
                if (nGender != 2 && nGender != spData->limit.genderLimit)
                {
                    bValid = false;
                    break;
                }
            }
        }
        if (!bValid)
            continue;
        for (unsigned j = 0; j < pieces.GetCount(); j++)
        {
            unsigned nPieceId = pieces.GetAt(j);
            MS2Ptr<CItemData> spData = FUN_14053f870(nPieceId);
            if (spData == 0)
                continue;
            const CStringW& strName = FUN_1401a9d70_p1()->FUN_141811980(1, nPieceId);
            int nColor = nInactiveColor;
            if (!equipped.empty())
            {
                if (std::find_if(equipped.begin(), equipped.end(), [nPieceId](MS2Ptr<CEquipItem> spEquip) -> bool {
                        if (spEquip == 0 || spEquip->FUN_1411dc7a0() == 0)
                            return false;
                        if (!spEquip->FUN_1411dc7a0()->FUN_140528980())
                            return false;
                        if (spEquip->FUN_1411dc7f0()->FUN_14053c560() == nPieceId)
                            return true;
                        return false;
                    }) != equipped.end())
                {
                    nEquipped++;
                    nColor = nEquippedColor;
                }
            }
            strPieces.Append(StringFormat(strRowFormat, nColor, strName));
        }
        nEquipped = nEquipped < nRequired ? nEquipped : nRequired;
        CStringW strTitle = StringFormat(s_wsSetName, FUN_1401a9d70_p1()->FUN_1418128c0(sets[i]->FUN_1407ad550(), "name"), nEquipped, nRequired);
        strText.Append(strTitle);
        strText.Append(strPieces);
        for (unsigned n = 0; n <= sets[i]->GetItemCount(); n++)
        {
            MS2Ptr<SetItemOptionPart> spPart = sets[i]->GetOptionPart(n);
            if (spPart == 0)
                continue;
            int nColor = nInactiveColor;
            if (n <= nEquipped)
                nColor = nActiveColor;
            CStringW strPartTitle = StringFormat(strPartFormat, nColor, n);
            CStringW strOptions;
            spPart->FUN_1407bccf0([&strOptions, &strStatFormat, &nColor](const std::pair<SetItemOptionPart::StatKey, Unk_EnchantPtr<BaseOption> >& v) {
                strOptions.Append(StringFormat(strStatFormat, nColor, FUN_140631600(v.first, v.second.get())));
            });
            spPart->FUN_1407bcdb0([&strOptions, &strStatFormat, &nColor, &pItem](const std::pair<SetItemOptionPart::SpecialKey, Unk_EnchantPtr<BaseOption> >& v) {
                strOptions.Append(StringFormat(strStatFormat, nColor, FUN_140631830(v.first, v.second->FUN_140266e30(), pItem->FUN_140527840())));
            });
            const ATL::CAtlArray<int>& arrSkills = spPart->FUN_1407bc9d0();
            const ATL::CAtlArray<unsigned short>& arrLevels = spPart->FUN_1407bc9f0();
            if (!arrSkills.IsEmpty())
            {
                for (unsigned k = 0; k < arrSkills.GetCount(); k++)
                {
                    if (arrSkills[k] == 0)
                        continue;
                    CStringW strSkill = FUN_1406319f0(arrSkills[k], arrLevels[k]);
                    if (!strSkill.IsEmpty())
                        strOptions.Append(StringFormat(strStatFormat, nColor, strSkill));
                }
            }
            if (!strOptions.IsEmpty())
            {
                strText.Append(strPartTitle);
                strText.Append(strOptions);
            }
        }
        if (!strText.IsEmpty())
            arr.FUN_1422bbfe0(strText);
    }
    FUN_1409eb1d0("itemStatusSet", arr);
}
// not hooked: reads TSingleton<SetItemTable>::s_instance (a DLL-local copy)

// The UGC map (housing) set of an item: the set name and its pieces.
// @0x1409c8df0
void ASTooltip::FUN_1409c8df0(int nItemId)
{
    MS2Ptr<ItemHousing> spHousing = FUN_140281980_p1()->GetHousing(nItemId);
    if (spHousing == 0)
        return;
    if (spHousing->setItemID == 0)
        return;
    UGCMapSetItemDataPtr spSet = CUGCMapSetItemTable::GetInstance()->FUN_140b9df60(spHousing->setItemID);
    if (spSet == 0)
        return;
    FUN_1409e5480();
    int nColor = 0xffffff;
    ASArray arr(2);
    CStringW strUnused;
    CStringW strBody;
    for (std::map<unsigned int, UGCMapSetItemInfoPtr>::iterator it = spSet->m_items.begin(); it != spSet->m_items.end(); ++it)
    {
        int nPieceId = it->first;
        const CStringW& strName = FUN_1401a9d70_p1()->FUN_141811980(1, nPieceId);
        strBody.Append(StringFormat(s_wsUgcSetRow, nColor, strName));
    }
    CStringW strTitle = StringFormat(s_wsUgcSetName, FUN_1401a9d70_p1()->FUN_141812a80(spHousing->setItemID, "name"));
    arr.FUN_1422bbfe0(strTitle);
    arr.FUN_1422bbfe0(strBody);
    FUN_1409eb1d0("itemStatusSet", arr);
}
MS2_REPLACE_METHOD(0x1409C8DF0, ASTooltip, FUN_1409c8df0, 883, 0x730BDFE3);

// The option block of the item tooltip ("itemStatus"): the option rows per kind, the socket and additional-effect rows,
// the enchant and unlimited-enchant rows and the enchant / pet exp gauges. Merge items show their merge ranges instead.
// @0x1409c9170
// MS2-FUNCTIONAL: /Od frame is 0x80 larger (temporaries placed differently); same calls and control flow
void ASTooltip::FUN_1409c9170(CItem* pItem)
{
    if (pItem == 0)
        return;
    CItemData* pData = pItem->FUN_140527840();
    if (pData == 0)
        return;
    if (pItem->FUN_140527840()->FUN_14053c5e0() == 2)
    {
        FUN_1409cb7b0(pItem);
        return;
    }
    CItemStatus* pStatus = reinterpret_cast<CItemStatus*>(pItem->FUN_1405278a0());
    if (pStatus == 0)
        return;
    MS2Ptr<CItemOption> spOption(pStatus->m_spOption);
    if (spOption.IsNull())
        return;
    FUN_1409e5480();
    const CStringW& strRowFormat = s_wsText0xbf8;
    CStringW strKinds[5] = { L"" };
    CStringW strText;
    int bPet = pItem->FUN_140525640();
    MS2Ptr<CPetData> spPet(0);
    if (bPet != 0)
        spPet = FUN_14052d210()->Find(pItem->FUN_140527840()->FUN_14053dc60());
    for (unsigned __int64 i = 0; i < 5; i++)
    {
        if (i == 1)
            continue;
        CStringW& strKind = strKinds[i];
        int nKind = (int)i;
        Unk_EnchantMap& mapStats = spOption->FUN_1405cb8a0(nKind);
        Unk_SocketSpecialMap& mapSpecials = spOption->FUN_1405cb8d0(nKind);
        Unk_OptionTextMap mapTexts(10);
        if (bPet == 0 || nKind != 2)
        {
            unsigned nOrder = 0;
            for (POSITION pos = mapStats.GetStartPosition(); pos != 0; mapStats.GetNext(pos))
            {
                int nStat = mapStats.GetKeyAt(pos);
                mapTexts.SetAt(nOrder, FUN_14082efb0(nStat));
                nOrder++;
            }
            for (POSITION pos = mapSpecials.GetStartPosition(); pos != 0; mapSpecials.GetNext(pos))
            {
                Unk_SocketSpecialStat eSpecial = mapSpecials.GetKeyAt(pos);
                mapTexts.SetAt(nOrder, FUN_14081d380(eSpecial));
                nOrder++;
            }
        }
        else
        {
            spOption->FUN_1405cb900(nKind, mapTexts);
        }
        int nRow = 0;
        int nTexts = (int)mapTexts.GetCount();
        for (POSITION pos = mapTexts.GetHeadPosition(); pos != 0; mapTexts.GetNext(pos))
        {
            int nStat = FUN_14082ee80(mapTexts.GetValueAt(pos));
            if (nStat == -1)
            {
                Unk_SocketSpecialStat eSpecial = (Unk_SocketSpecialStat)FUN_14081d260(mapTexts.GetValueAt(pos));
                if (eSpecial == 0)
                    continue;
                Unk_SocketSpecialMap::CPair* pPair = mapSpecials.Lookup(eSpecial);
                if (pPair == 0)
                    continue;
                Unk_EnchantPtr<BaseOption> spBase(pPair->m_value);
                if (!spBase)
                    continue;
                CStringW strValue;
                CStringW strRow;
                if (i == 0 && bPet != 0 && spPet.get() != 0)
                {
                    CStringW strBase;
                    CStringW strMax;
                    CStringW strRate;
                    if (spBase->FUN_140266ce0())
                    {
                        int nValue = spBase->FUN_140266e30();
                        float fRate = (float)floor(FUN_1406198a0(nValue, spPet->m_fConstantOptionFactor));
                        float fBase = (float)nValue;
                        float fMax = fBase + fRate * (float)(int)(*FUN_1401d3200()->PetMaxLevel.Get() - 1);
                        nValue = (int)((float)nValue + fRate * (float)(pItem->FUN_140528c20() - 1));
                        strValue = FUN_140631830(eSpecial, nValue, pItem->FUN_140527840());
                        int nRaw = spBase->FUN_140266e30();
                        strBase = StringFormat(L"{0:0.1f}", nRaw);
                        strMax = StringFormat(L"{0:0.1f}", fMax);
                        strRate = StringFormat(L"{0:0.1f}", fRate);
                    }
                    if (FUN_1409c56f0(strRow, MS2Ptr<CItem>(pItem), eSpecial, nKind, spBase, strValue))
                    {
                        strKind.Append(strRow);
                        strKind.Append(FUN_14028dfa0(CStringW(L"s_tooltip_itemoption_stat_row_pet_constant_desc"), strBase, strMax, strRate));
                    }
                }
                else
                {
                    strValue = FUN_140631830(eSpecial, spBase->FUN_140266e30(), pItem->FUN_140527840());
                    if (FUN_1409c56f0(strRow, MS2Ptr<CItem>(pItem), eSpecial, nKind, spBase, strValue))
                        strKind.Append(strRow);
                }
                nRow++;
            }
            else
            {
                Unk_EnchantMap::CPair* pPair = mapStats.Lookup(nStat);
                if (pPair == 0)
                    continue;
                Unk_EnchantPtr<BaseOption> spBase(pPair->m_value);
                if (!spBase)
                    continue;
                if (i == 0 && pData->FUN_14053f750(nStat))
                {
                    nRow++;
                    continue;
                }
                CStringW strValue;
                CStringW strRow;
                if (i == 0 && bPet != 0 && spPet.get() != 0)
                {
                    CStringW strBase;
                    CStringW strMax;
                    CStringW strRate;
                    if (spBase->FUN_140266ce0())
                    {
                        __int64 nValue = spBase->FUN_140266e30();
                        float fRate = (float)floor((double)FUN_140632990(nValue, spPet->m_fConstantOptionFactor));
                        float fBase = (float)nValue;
                        __int64 nMax = (__int64)(fBase + fRate * (float)(int)(*FUN_1401d3200()->PetMaxLevel.Get() - 1));
                        nValue = (__int64)((float)nValue + fRate * (float)(pItem->FUN_140528c20() - 1));
                        strValue = FUN_140631720(nStat, (int)nValue, false);
                        strBase = FUN_1409e0900(spBase->FUN_140266e30());
                        strMax = FUN_1409e0900((int)nMax);
                        strRate = FUN_1409e0900((int)fRate);
                    }
                    if (FUN_1409c5210(strRow, MS2Ptr<CItem>(pItem), nStat, nKind, spBase, strValue))
                    {
                        strKind.Append(strRow);
                        strKind.Append(FUN_14028dfa0(CStringW(L"s_tooltip_itemoption_stat_row_pet_constant_desc"), strBase, strMax, strRate));
                    }
                }
                else
                {
                    strValue = FUN_140631600(nStat, spBase.get());
                    if (FUN_1409c5210(strRow, MS2Ptr<CItem>(pItem), nStat, nKind, spBase, strValue))
                        strKind.Append(strRow);
                }
                nRow++;
            }
        }
    }
    if ((m_48 & 0x10000) != 0)
    {
        CStringW& strSocket = strKinds[2];
        if (pItem->FUN_140525640())
        {
            unsigned nCount = FUN_14072fd00(pItem->FUN_140526bd0());
            strSocket.Append(StringFormat(s_wsText0xbf8, FUN_14028dfa0(CStringW(L"s_pet_item_option_count"), nCount)));
        }
    }
    if (pItem->FUN_140526390())
    {
        CStringW& strConstant = strKinds[0];
        unsigned nCount = (unsigned)pItem->FUN_140527840()->additionalEffect.ids.GetCount();
        ItemAdditionalEffect& effect = pItem->FUN_140527840()->additionalEffect;
        for (unsigned j = 0; j < nCount; j++)
        {
            MS2Ptr<AdditionalLevelData> spLevel = FUN_1401958b0()->FUN_140aafef0(effect.ids[j], effect.levels[j]);
            if (spLevel == 0)
                continue;
            if (!spLevel->IsVisibleItemOption())
                continue;
            CStringW strOption = FUN_1406319f0(effect.ids[j], effect.levels[j]);
            if (strOption.IsEmpty())
                continue;
            strConstant.Append(StringFormat(strRowFormat, strOption));
        }
    }
    CStringW strSeparator(s_wsText0xbf5);
    for (unsigned __int64 k = 0; k < 5; k++)
    {
        if (FUN_1409e5450((int)k))
            continue;
        CStringW& strKind = strKinds[k];
        if (strKind.IsEmpty())
            continue;
        if (!strSeparator.IsEmpty() && !strText.IsEmpty())
            strText.Append(strSeparator);
        strText.Append(StringFormat(FUN_1409e6010((int)k, pItem), strKind));
    }
    Unk_EnchantPtr<CItemEnchantInfo> spEnchant(pStatus->FUN_140630d60());
    if (spEnchant != 0)
    {
        if (spEnchant->FUN_14058c8a0() == 0)
        {
            Unk_EnchantMap& mapEnchant = spEnchant->FUN_14058cd40();
            if (!mapEnchant.IsEmpty())
            {
                CStringW strRows;
                for (POSITION pos = mapEnchant.GetStartPosition(); pos != 0; mapEnchant.GetNext(pos))
                {
                    int nStat = mapEnchant.GetKeyAt(pos);
                    Unk_EnchantPtr<BaseOption> spBase(mapEnchant.GetValueAt(pos));
                    if (!spBase)
                        continue;
                    strRows.Append(StringFormat(strRowFormat, FUN_140631af0(nStat, spBase, pStatus)));
                }
                if (!strRows.IsEmpty())
                {
                    if (!strText.IsEmpty())
                        strText.Append(strSeparator);
                    strText.Append(StringFormat(s_wsText0xbf6, strRows));
                }
            }
        }
        if (CItemEnchantLimitTable::GetInstance()->FUN_14058df90(pItem))
        {
            int nExp = pItem->FUN_1405270a0();
            int nPercent = nExp * 100 / 10000;
            int nNeed = 0;
            int nCur = 0;
            int nStep = pItem->FUN_140528f90(0);   // the exe passes no argument (see item.cpp)
            if (nStep > 0)
            {
                nNeed = (int)(10000.0 / (float)nStep + 0.5);
                nCur = pItem->FUN_1405270a0() / nStep;
            }
            CStringW strExp = StringFormat(L"{0} / {1}", nCur, nNeed);
            CStringW strLabel = StringFormat(s_wsEnchantExp);
            if (spEnchant->FUN_14058cd60())
                strLabel = FUN_14028b8e0(CStringW(L"s_tooltip_itemoption_enchant_exp_refund"));
            CStringW strSep(s_wsText0xbf5);
            if (!strText.IsEmpty())
                strText.Append(strSep);
            strText.Append(strLabel);
            strText.Append(L"gauge:\n\n");
            FUN_1407cbb20("itemEnchantExpString", strExp);
            FUN_1407cb9c0("itemEnchantExpPercent", nPercent);
        }
    }
    MS2Ptr<UnlimitedEnchantInfo> spUnlimited(reinterpret_cast<UnlimitedEnchantInfo*>(pStatus->FUN_140630d90()));
    if (spUnlimited != 0)
    {
        if (spUnlimited->FUN_1408bbc50() > 0)
        {
            CStringW strRows;
            UnlimitedEnchantInfo::OptionMap& mapOptions = spUnlimited->FUN_1408bc2d0();
            if (mapOptions.size() != 0)
            {
                for (UnlimitedEnchantInfo::OptionMap::const_iterator it = mapOptions.begin(); it != mapOptions.end(); ++it)
                {
                    int nKey = it->first;
                    Unk_EnchantPtr<BaseOption> spBase(it->second);
                    CStringW strRow;
                    if (nKey == 0x1c || nKey == 0x1b || nKey == 0x14)
                        strRow = FUN_140631af0(nKey, spBase, pStatus);
                    else
                        strRow = FUN_140631600(nKey, spBase.get());
                    strRows.Append(StringFormat(strRowFormat, strRow));
                }
            }
            UnlimitedEnchantInfo::SecondaryMap& mapSpecials = spUnlimited->FUN_1408bc3b0();
            if (mapSpecials.size() != 0)
            {
                for (UnlimitedEnchantInfo::SecondaryMap::const_iterator it = mapSpecials.begin(); it != mapSpecials.end(); ++it)
                {
                    int nSpecial = it->first;
                    Unk_EnchantPtr<BaseOption> spBase(it->second);
                    strRows.Append(StringFormat(strRowFormat, FUN_140631830(nSpecial, spBase->FUN_140266e30(), pItem->FUN_140527840())));
                }
            }
            if (!strRows.IsEmpty())
            {
                if (!strText.IsEmpty())
                    strText.Append(strSeparator);
                int nLevel = spUnlimited->FUN_1408bbc50();
                strText.Append(StringFormat(s_wsUnlimited, nLevel, strRows));
            }
        }
    }
    if (pItem->FUN_140525640())
    {
        MS2Ptr<CPetData> spPetData = FUN_14052d210()->Find(pItem->FUN_140527840()->FUN_14053dc60());
        if (spPetData.get() != 0 && spPetData->m_nType == 1)
        {
            __int64 nExp = pItem->FUN_140528b90();
            unsigned short nRank = pItem->FUN_1405282d0();
            int nGrade = pItem->FUN_140526bd0();
            unsigned short nLevel = pItem->FUN_140528c20();
            __int64 nNeed = FUN_1404a1bb0_p1()->GetPetExp(nLevel, nGrade, nRank);
            int nPercent = 0;
            if (nNeed > 0)
                nPercent = (int)(nExp * 100 / nNeed);
            CStringW strExp;
            strExp.Format(L"%s", (const wchar_t*)FUN_14028dfa0(CStringW(L"s_common_cur_max_ingredient"), FUN_1409404f0(nExp), FUN_1409404f0(nNeed)));
            CStringW strLabel = StringFormat(s_wsPetExp);
            CStringW strSep(s_wsText0xbf5);
            if (!strText.IsEmpty())
                strText.Append(strSep);
            strText.Append(strLabel);
            strText.Append(L"gauge:\n\n");
            unsigned nCurLevel = pItem->FUN_140528c20();
            if (nCurLevel < *FUN_1401d3200()->PetMaxLevel.Get())
            {
                FUN_1407cbb20("itemEnchantExpString", strExp);
                FUN_1407cb9c0("itemEnchantExpPercent", nPercent);
            }
            else
            {
                FUN_1407cbb20("itemEnchantExpString", FUN_14028b8e0(CStringW(L"s_mag_skillbook_max_level")));
                FUN_1407cb9c0("itemEnchantExpPercent", 100);
            }
        }
    }
    FUN_1407cbb20("itemStatus", strText);
}
// not hooked: reads TSingleton<CItemEnchantLimitTable>::s_instance (a DLL-local copy)

// The merge option ranges of the item (the first normal and the first special option of its merge slot).
// @0x1409cb7b0
void ASTooltip::FUN_1409cb7b0(CItem* pItem)
{
    if (pItem == 0 || pItem->FUN_140527840() == 0)
        return;
    Unk_ItemEnchantData* pEnchant = pItem->FUN_1405278a0();
    if (pEnchant == 0)
        return;
    FUN_1409e5480();
    CStringW strText;
    CStringW strRows;
    int nStat = -1;
    if (CItemMergeOptionTable::GetInstance()->FUN_1405c03d0(pItem->FUN_140527840()->FUN_14053de10(), &nStat))
    {
        CStringW strRange;
        // FUN_1405c0610 returns the option's whole-range variation (option + 0x20); the shared header calls it Unk_MergeRange*
        CItemMergeOptionVariation* pVariation = reinterpret_cast<CItemMergeOptionVariation*>(CItemMergeOptionTable::GetInstance()->FUN_1405c0610(pItem->FUN_140527840()->FUN_14053de10(), nStat));
        if (pVariation != 0)
        {
            if (FUN_14082f1d0(nStat))
            {
                CStringW strMin = FUN_1409e0900(pVariation->FUN_1405beac0());
                CStringW strMax = FUN_1409e0900(pVariation->FUN_1405beae0());
                strRange = FUN_14028dfa0(CStringW(L"s_tooltip_itemmerge_option_range"), FUN_14082f000(nStat), strMin, strMax);
            }
            else
            {
                CStringW strMin = FUN_1409e0a90(pVariation->FUN_1405beb00());
                CStringW strMax = FUN_1409e0a90(pVariation->FUN_1405beb20());
                strRange = FUN_14028dfa0(CStringW(L"s_tooltip_itemmerge_option_range"), FUN_14082f000(nStat), strMin, strMax);
            }
            strRows.Append(StringFormat(s_wsText0xbf8, strRange));
        }
    }
    int nSpecial = 0;
    if (CItemMergeOptionTable::GetInstance()->FUN_1405c04f0(pItem->FUN_140527840()->FUN_14053de10(), &nSpecial))
    {
        CStringW strRange;
        CItemMergeOptionVariation* pVariation = reinterpret_cast<CItemMergeOptionVariation*>(CItemMergeOptionTable::GetInstance()->FUN_1405c0740(pItem->FUN_140527840()->FUN_14053de10(), nSpecial));
        if (pVariation != 0)
        {
            if (FUN_14081dc50(nSpecial))
            {
                CStringW strMin = FUN_1409e0900(pVariation->FUN_1405beac0());
                CStringW strMax = FUN_1409e0900(pVariation->FUN_1405beae0());
                strRange = FUN_14028dfa0(CStringW(L"s_tooltip_itemmerge_option_range"), FUN_140630e10(nSpecial), strMin, strMax);
            }
            else
            {
                CStringW strMin = FUN_1409e0a90(pVariation->FUN_1405beb00());
                CStringW strMax = FUN_1409e0a90(pVariation->FUN_1405beb20());
                strRange = FUN_14028dfa0(CStringW(L"s_tooltip_itemmerge_option_range"), FUN_140630e10(nSpecial), strMin, strMax);
            }
            strRows.Append(StringFormat(s_wsText0xbf8, strRange));
        }
    }
    if (strRows.IsEmpty())
        return;
    CStringW strMerge(s_wsText0xbf5);
    if (!strMerge.IsEmpty() && !strText.IsEmpty())
        strText.Append(strMerge);
    FUN_14083d2b0(strRows);
    int nStep = 0;
    strText.Append(FUN_14028dfa0(CStringW(L"s_tooltip_itemoption_kinds_merge_step"), nStep, strRows));
    strText.TrimRight();
    FUN_1407cbb20("itemMerge", strText);
}
// not hooked: reads TSingleton<CItemMergeOptionTable>::s_instance (a DLL-local copy)

// @0x1409cc090
void ASTooltip::FUN_1409cc090(CItem* pItem)
{
    if (pItem == 0)
        return;
    CItemData* pData = pItem->FUN_140527840();
    if (pData == 0)
        return;
    Unk_ItemEnchantData* pEnchant = pItem->FUN_1405278a0();
    if (pEnchant == 0)
        return;
    MS2Ptr<CItemOption> spOption(reinterpret_cast<CItemStatus*>(pEnchant)->m_spOption);
    if (spOption.IsNull())
        return;
    {
        unsigned nTotal = 0;
        int nSocketOptions = 0;
        int nSkip = 0;
        int nOptions = 0;
        int nAdditional = 0;
        FUN_1409e5480();
        ATL::CAtlMap<int, Unk_EnchantPtr<BaseOption>, Unk_EnchantKeyTraits, ATL::CElementTraits<Unk_EnchantPtr<BaseOption> > >& mapStats = spOption->FUN_1405cb8a0(0);
        for (POSITION pos = mapStats.GetStartPosition(); pos != 0; mapStats.GetNext(pos))
        {
            int nStat = mapStats.GetKeyAt(pos);
            if (pData->FUN_14053f750(nStat))
            {
                if (nStat == 0x1b || nStat == 0x1c)
                    nSkip = 2;
                else
                    nSkip = 1;
            }
        }
        if (pItem->FUN_140526390())
        {
            unsigned nCount = (unsigned)pItem->FUN_140527840()->additionalEffect.ids.GetCount();
            ItemAdditionalEffect& effect = pItem->FUN_140527840()->additionalEffect;
            for (unsigned i = 0; i < nCount; i++)
            {
                MS2Ptr<AdditionalLevelData> spLevel = FUN_1401958b0()->FUN_140aafef0(effect.ids[i], effect.levels[i]);
                if (spLevel == 0)
                    continue;
                if (!spLevel->IsVisibleItemOption())
                    continue;
                CStringW strOption = FUN_1406319f0(effect.ids[i], effect.levels[i]);
                if (strOption.IsEmpty())
                    continue;
                nAdditional++;
            }
        }
        nOptions = spOption->FUN_1405cbbb0(0);
        nSocketOptions = pItem->FUN_14052a060();
        nTotal = nOptions - nSkip + nSocketOptions + nAdditional;
        CStringW strText;
        if (nTotal >= 1)
        {
            CStringW strCount;
            if (pItem->FUN_140525640())
                strCount = FUN_14028dfa0(CStringW(L"s_pet_item_option_count"), nTotal);
            else
                strCount = BlockFormat(0x7a8, nTotal);
            strText.Append(StringFormat(s_wsWhiteFont, strCount));
        }
        unsigned nMaxSockets = FUN_14052d200()->FUN_14062d4b0(pItem->FUN_140527840()->property.socketDataId, pItem->FUN_140526bd0(), MS2Ptr<CItemData>(pItem->FUN_140527840()));
        if (nMaxSockets > 0 && pItem->FUN_140525640() == 0)
        {
            bool bShow = (FUN_1409c6560() & 0x4000) == 0;
            if (bShow)
            {
                if (!strText.IsEmpty())
                    strText.Append(L"\n");
                strText.Append(StringFormat(s_wsWhiteFont, FUN_14028dfa0(CStringW(L"s_itemsocketsystem_socket_maxcount"), nMaxSockets)));
            }
        }
        FUN_1407cbb20("itemStatus", strText);
    }
}
MS2_REPLACE_METHOD(0x1409CC090, ASTooltip, FUN_1409cc090, 1897, 0xE19E2303);
