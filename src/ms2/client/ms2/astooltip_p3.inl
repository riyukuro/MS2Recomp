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
MS2_REPLACE_METHOD(0x1409D3010, ASTooltip, FUN_1409d3010, 1104, 0x85F94BBB);

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
MS2_REPLACE_METHOD(0x1409D46E0, ASTooltip, FUN_1409d46e0, 121, 0x0809F9B2);

// @0x1409d5610
void ASTooltip::FUN_1409d5610(int nItemId)
{
    MS2Ptr<CItemData> sp = FUN_14053f870(nItemId);
    if (sp.IsNull())
        return;
    long nKinds = FUN_1409e6fc0(sp->FUN_14053c600());
    FUN_1409eb3b0(s_strItemKinds, nKinds);
}
MS2_REPLACE_METHOD(0x1409D5610, ASTooltip, FUN_1409d5610, 142, 0x346866BF);

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
MS2_REPLACE_METHOD(0x1409D56B0, ASTooltip, FUN_1409d56b0, 178, 0x8173E7A7);

// @0x1409d5770
void ASTooltip::FUN_1409d5770(int nItemId)
{
    MS2Ptr<CItemData> sp = FUN_14053f870(nItemId);
    if (sp.IsNull())
        return;
    FUN_1407cbb20(s_strIconPath, FUN_14016a730(sp->FUN_14053fdd0(), 0));
}
MS2_REPLACE_METHOD(0x1409D5770, ASTooltip, FUN_1409d5770, 214, 0x8CD290D2);

// @0x1409d5850
void ASTooltip::FUN_1409d5850(int nItemId)
{
}
MS2_REPLACE_METHOD(0x1409D5850, ASTooltip, FUN_1409d5850, 10, 0x96F6F902);

// @0x1409d5860
void ASTooltip::FUN_1409d5860(int nItemId, int nRarity)
{
    MS2Ptr<CItem> sp(new CItem);
    if (sp->FUN_140523c40(nItemId, nRarity, 0))
        FUN_1409cd9c0(sp.get());
}
MS2_REPLACE_METHOD(0x1409D5860, ASTooltip, FUN_1409d5860, 178, 0x98E59B9F);

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
MS2_REPLACE_METHOD(0x1409D5920, ASTooltip, FUN_1409d5920, 363, 0x5540657B);

// @0x1409d5aa0
void ASTooltip::FUN_1409d5aa0(int nItemId)
{
    CStringW str = FUN_1401a9d70_p3()->FUN_141811c90(nItemId, "tooltipDescription");
    FUN_1403b4750()->FUN_1416fb340(str);
    FUN_1407cbb20("itemDescription", str);
}
MS2_REPLACE_METHOD(0x1409D5AA0, ASTooltip, FUN_1409d5aa0, 189, 0xA32EDB32);

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
MS2_REPLACE_METHOD(0x1409D7560, ASTooltip, FUN_1409d7560, 187, 0xFBC6422C);

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
MS2_REPLACE_METHOD(0x1409D7630, ASTooltip, FUN_1409d7630, 365, 0xCCE37309);

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
MS2_REPLACE_METHOD(0x1409D77B0, ASTooltip, FUN_1409d77b0, 330, 0xAD681CF7);

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
MS2_REPLACE_METHOD(0x1409D8570, ASTooltip, FUN_1409d8570, 212, 0xF9182D6C);

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
MS2_REPLACE_METHOD(0x1409D8650, ASTooltip, FUN_1409d8650, 420, 0x50CA6567);

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
MS2_REPLACE_METHOD(0x1409D8800, ASTooltip, FUN_1409d8800, 206, 0xE07649E6);

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
MS2_REPLACE_METHOD(0x1409D88E0, ASTooltip, FUN_1409d88e0, 775, 0xA2C0CBD9);

// @0x1409d8bf0
void ASTooltip::FUN_1409d8bf0(bool bEnable)
{
    if (bEnable)
        FUN_1407cbb20(s_strItemEquip, FUN_14028de60(0x58a));
    else
        FUN_1409c0e60(s_strItemEquip, L"");
}
MS2_REPLACE_METHOD(0x1409D8BF0, ASTooltip, FUN_1409d8bf0, 123, 0xFF195793);
