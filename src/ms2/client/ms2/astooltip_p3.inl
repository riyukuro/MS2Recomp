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
