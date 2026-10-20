// astooltip.cpp part 2: functions 0x1409cc800-0x1409d3010 (exe order). Included by astooltip.cpp; merged into it when the unit is done.

// The socket rows of an item (itemSocket): one row per open socket (gemstone options, bind/trade limits), the locked
// sockets, or the empty rows of the compact layout.
// @0x1409cc800
// MS2-FUNCTIONAL: frame/temporary layout differs from the exe
void ASTooltip::FUN_1409cc800(CItem* pItem)
{
    if (!FUN_140166410()->FUN_14036d570(0x2e) || pItem == 0 || pItem->FUN_140527840() == 0 || pItem->FUN_1405279c0() == 0)
        return;
    if (pItem->FUN_1405258b0() != 0 && !FUN_140166410()->FUN_14036d570(0x5e))
        return;
    CItemSocket* pSocket = pItem->FUN_1405279c0();
    unsigned nFlags = FUN_1409c6560();
    if ((nFlags & 0x800) == 0)
    {
        if (pSocket->FUN_140620a50() == 0)
            return;
        FUN_1409e5480();
        const CStringW& strRowEmpty = s_wsSocketRowEmpty;
        const CStringW& strRowStat = s_wsSocketRowStat;
        const CStringW& strRowStatByPet = s_wsSocketRowStatByPet;
        const CStringW& strTransfer = s_wsSocketTransfer;
        CStringW strSeparator(L", ");
        CStringW strRows;
        unsigned nOpen = pSocket->FUN_140620a20();
        for (unsigned i = 0; i < nOpen; i++)
        {
            MS2Ptr<TSocketGemStoneInfo> spGem = pSocket->FUN_140620b70(i);
            if (spGem == 0 || spGem->m_nGemId == 0)
            {
                if (pItem->FUN_140525640() == 0)
                    strRows.Append(strRowEmpty);
                continue;
            }
            int nGemId = spGem->m_nGemId;
            MS2Ptr<CItemData> spData = FUN_14053f870(nGemId);
            if (spData == 0)
            {
                if (pItem->FUN_140525640() == 0)
                    strRows.Append(strRowEmpty);
                continue;
            }
            CStringW strOption = FUN_14062ae60(nGemId);
            if (spData->FUN_14053e670())
            {
                size_t nCount = spData->additionalEffect.ids.GetCount();
                const ItemAdditionalEffect& effect = spData->additionalEffect;
                for (unsigned j = 0; j < nCount; j++)
                {
                    MS2Ptr<AdditionalLevelData> spLevel = FUN_1401958b0()->FUN_140aafef0(effect.ids[j], effect.levels[j]);
                    if (spLevel == 0)
                        continue;
                    if (!spLevel->IsVisibleItemOption())
                        continue;
                    CStringW strEffect = FUN_1406319f0(effect.ids[j], effect.levels[j]);
                    if (strEffect.IsEmpty())
                        continue;
                    if (strOption.IsEmpty())
                        strOption.Append(strEffect);
                    else
                    {
                        strOption.AppendChar(L'\n');
                        strOption.Append(FUN_14028dfa0(CStringW(L"s_tooltip_itemoption_socket_additional"), strEffect));
                    }
                }
            }
            int nPersonal = CItemSocket::FUN_140622440(pSocket, spData, spGem);
            int nTradeable = CItemSocket::FUN_1406221c0(pSocket, spData, spGem);
            CStringW strName = spGem->FUN_1406201d0();
            int nBindable = spData->FUN_14053d7c0();
            int nBound = !strName.IsEmpty();
            CStringW strText = FUN_1409e6120(pItem, nTradeable, nPersonal, nBindable, nBound, strSeparator, 0, strName, 0);
            if (!strText.IsEmpty())
                strText = StringFormat(strTransfer, strText);
            if (pItem->FUN_140525640() == 0)
                strRows.Append(StringFormat(strRowStat, FUN_140627390(nGemId), strOption, strText, FUN_14062b310(spGem)));
            else
                strRows.Append(StringFormat(strRowStatByPet, strOption, strText));
        }
        if (pItem->FUN_140525640() == 0)
        {
            int nLocked = pSocket->FUN_140620a70();
            if (nLocked != 0)
            {
                const CStringW& strRowLock = s_wsSocketRowLock;
                for (int i = 0; i < nLocked; i++)
                    strRows.Append(strRowLock);
            }
            FUN_1407cbb20("itemSocket", StringFormat(s_wsSocket, strRows));
        }
        else if (!strRows.IsEmpty())
            FUN_1407cbb20("itemSocket", StringFormat(s_wsSocketByPet, strRows));
    }
    else
    {
        int bShow = (nFlags & 0x4000) == 0;
        if (!bShow && pItem->FUN_140525640() == 0)
        {
            const CStringW& strRowEmpty = s_wsSocketRowEmpty;
            CStringW strRows;
            if (pSocket->FUN_140620a50() == 0)
            {
                unsigned nMax = FUN_14052d200()->FUN_14062d4b0(pItem->FUN_140527840()->property.socketDataId, pItem->FUN_140526bd0(),
                                                              MS2Ptr<CItemData>(pItem->FUN_140527840()));
                for (unsigned i = 0; i < nMax; i++)
                    strRows.Append(strRowEmpty);
            }
            else
            {
                unsigned nOpen = pSocket->FUN_140620a20();
                for (unsigned i = 0; i < nOpen; i++)
                    strRows.Append(strRowEmpty);
                int nLocked = pSocket->FUN_140620a70();
                if (nLocked != 0)
                {
                    const CStringW& strRowLock = s_wsSocketRowLock;
                    for (int i = 0; i < nLocked; i++)
                        strRows.Append(strRowLock);
                }
            }
            FUN_1407cbb20("itemSocket", StringFormat(s_wsSocket, strRows));
        }
    }
}
// not hooked: the compact-layout branch reads the unit statics s_ws* without calling FUN_1409e5480() first

// itemMerge: the merge option description.
// @0x1409cd5b0
void ASTooltip::FUN_1409cd5b0(CItem* pItem)
{
    FUN_1409e5480();
    CStringW strMerge = TSingleton<CItemMergeOptionTable>::GetInstance()->FUN_1405c1090(MS2Ptr<CItem>(pItem), 1);
    if (strMerge.GetLength() != 0)
    {
        CStringW strText = StringFormat(L"{0}{1}", s_wsMerge, strMerge);
        FUN_1407cbb20("itemMerge", strText);
    }
}
// not hooked: TSingleton<CItemMergeOptionTable>::GetInstance reads the DLL-local s_instance

// @0x1409cd6b0
void ASTooltip::FUN_1409cd6b0(CItem* pItem)
{
    FUN_1407cbb20(s_strIconPath, FUN_14016a730(pItem->FUN_140528590(), 0));
}
MS2_REPLACE_METHOD(0x1409CD6B0, ASTooltip, FUN_1409cd6b0, 143, 0x5DBF3A1B);

// The double-click / equip hints of an item that the player does not wear.
// @0x1409cd750
// MS2-FUNCTIONAL: unwind state order / frame size differ from the exe
void ASTooltip::FUN_1409cd750(CItem* pItem)
{
    if (FUN_1409c6540() == 0)
        return;
    MS2Ptr<CEquipItem> spEquip = ((MyPC*)FUN_1409c6540())->FUN_141655c30(pItem->FUN_140526a50());
    if (spEquip.get() == 0)
    {
        if ((m_48 & 0x80) != 0)
        {
            if (FUN_1409e6c80(pItem) != 0)
            {
                FUN_1409c6880();
                if (pItem->FUN_140527840()->FUN_14053d510())
                    FUN_1409c68e0();
            }
            if (pItem->FUN_140525a80() != 0)
            {
                if (pItem->FUN_140525c00() == 0)
                {
                    if (!pItem->FUN_140527840()->FUN_14053cd10())
                    {
                        if (pItem->FUN_140527840()->FUN_14053ddb0() == 0)
                            FUN_1409c65a0();
                        else
                            FUN_1409c65f0(FUN_14028b8e0(CStringW(L"s_msg_dclick_open_shop")));
                    }
                    else if (pItem->FUN_140525730())
                        FUN_1409c65a0();
                }
                else
                    FUN_1409c65f0(FUN_14028de60(0x763));
            }
        }
    }
    else
        FUN_1407cbb20(s_strItemEquip, FUN_14028de60(0x58a));
}
MS2_REPLACE_METHOD(0x1409CD750, ASTooltip, FUN_1409cd750, 606, 0xD4640D82);

// itemSellPrice and the trade limits (notExchange).
// @0x1409cd9c0
// MS2-FUNCTIONAL: temporary/frame layout differs from the exe
void ASTooltip::FUN_1409cd9c0(CItem* pItem)
{
    if (pItem == 0)
        return;
    MS2Ptr<CItemData> spData = FUN_14053f870(pItem->FUN_1405276c0());
    if (spData == 0)
        return;
    MS2Ptr<CItemTransfer> spTransfer(pItem->FUN_140527930());
    if (spTransfer == 0)
        return;
    if (spData->FUN_14053cb80())
    {
        int nHousingId = spData->FUN_14053c510();
        MS2Ptr<ItemHousing> spHousing = FUN_140281980_p2()->GetHousing(nHousingId);
        if (spHousing == 0)
            return;
        if (spTransfer->FUN_1406354d0() == 0)
        {
            if (spHousing->FUN_140549470(pItem->FUN_1405276c0(), pItem->FUN_140526a50(), pItem->FUN_1405283d0()) != 0)
            {
                __int64 nPrice = FUN_1401c0d90()->FUN_14047bc50((Unk_SaleHousingKey)spHousing->filter, spHousing->priceCount, spHousing->price);
                CStringW strText;
                strText.Format(L"%s : %s", (const wchar_t*)FUN_14028de60(0x6f9), (const wchar_t*)FUN_1418fec00(spHousing->priceCount, nPrice, true));
                FUN_1407cbb20("itemSellPrice", strText);
            }
        }
        else
        {
            CStringW strText;
            strText.Format(L"%s : %s", (const wchar_t*)FUN_14028de60(0x587),
                           (const wchar_t*)FUN_1418fec00(spHousing->priceCount, pItem->FUN_140527670(), true));
            FUN_1407cbb20("itemSellPrice", strText);
        }
    }
    else if (spTransfer->FUN_1406354d0() != 0)
    {
        CStringW strText;
        strText.Format(L"%s : %s", (const wchar_t*)FUN_14028de60(0x587), (const wchar_t*)FUN_1418fec00(1, pItem->FUN_140527670(), true));
        FUN_1407cbb20("itemSellPrice", strText);
    }
    CStringW strText;
    if ((m_48 & 0x2000) == 0)
    {
        int nTradeable = FUN_140633a20(MS2Ptr<CItem>(pItem));
        int nPersonal = spTransfer->FUN_1406354d0();
        CStringW strBindName;
        int nBindable = 0;
        int nBindOnGet = 0;
        FUN_1409dfa50(pItem, nBindable, nBindOnGet, strBindName);
        int nCount = spTransfer->FUN_140635630() != 0 ? spTransfer->FUN_140634fa0() : 0;
        strText = FUN_1409e6120(pItem, nTradeable, nPersonal, nBindable, nBindOnGet, L"\n", nCount, strBindName, FUN_1409dfae0(pItem));
        FUN_1409d98a0(pItem, strText);
        if (FUN_140166410()->FUN_14036d570(0xa7) && spData->FUN_14053cf90() && spTransfer->FUN_140635900() == 0)
        {
            strText.Append(L"\n");
            strText.Append(FUN_14028b8e0(CStringW(L"s_word_item_limit_socket_transfer")));
        }
    }
    if (FUN_140166410()->FUN_14036d570(0x8d) && pItem->FUN_140525640() != 0)
    {
        int nPetId = pItem->FUN_140527840()->FUN_14053dc60();
        MS2Ptr<CPetData> spPet = FUN_14052d210()->Find(nPetId);
        if (spPet.get() != 0 && spPet->m_nType == 0)
        {
            if (!strText.IsEmpty())
                strText.Append(L"\n");
            strText.Append(FUN_14028b8e0(CStringW(L"s_word_limit_petcompose")));
        }
    }
    CStringW strCouple = pItem->FUN_140529410();
    if (!strCouple.IsEmpty())
    {
        if (!strText.IsEmpty())
            strText.Append(L"\n");
        strText.Append(FUN_14028dfa0(CStringW(L"s_couple_effect_partner"), strCouple));
    }
    FUN_1407cbb20("notExchange", strText);
}
MS2_REPLACE_METHOD(0x1409CD9C0, ASTooltip, FUN_1409cd9c0, 3106, 0x09CDE211);

// itemCreateTime: the creation time of a crafted item, or the UGC design time and the original item name.
// @0x1409ce5f0
void ASTooltip::FUN_1409ce5f0(CItem* pItem)
{
    if (pItem == 0)
        return;
    if (pItem->FUN_140525f10() != 0 || pItem->FUN_140526010() != 0)
    {
        CUgcItemLook* pLook = pItem->FUN_140528380();
        if (pLook == 0)
            return;
        __int64 nUid = pLook->m_n18;
        if (nUid == 0)
        {
            CStringW strText = FUN_14028de60(0x46a);
            FUN_1407cbb20("itemCreateTime", strText);
        }
        else
        {
            CMsTime time(pLook->m_n50);
            int nYear = time.GetYear();
            int nMonth = time.GetMonth();
            int nDay = time.GetDay();
            int nHour = time.GetHour();
            int nMinute = time.GetMinute();
            int nSecond = time.GetSecond();
            CStringW strText = BlockFormat(0xb7, pLook->m_str48, nYear, nMonth, nDay, nHour, nMinute, nSecond);
            FUN_1407cbb20("itemCreateTime", strText);
            CStringW strName = FUN_1401a9d70_p3()->FUN_141811980(1, pItem->FUN_1405276c0());
            FUN_1407cbb20("designOrgItemName", strName);
        }
    }
    else if (pItem->FUN_140525680())
    {
        CStringW strTime = pItem->FUN_140529890();
        if (!strTime.IsEmpty())
            FUN_1407cbb20("itemCreateTime", FUN_14052bd00(0x9c2, strTime));
    }
}
MS2_REPLACE_METHOD(0x1409CE5F0, ASTooltip, FUN_1409ce5f0, 852, 0xD65B232C);

// itemUsePeriod: the expiry time of an item (or its shop life / item data period).
// @0x1409ce950
// MS2-FUNCTIONAL: temporary/frame layout differs from the exe
void ASTooltip::FUN_1409ce950(CItem* pItem)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(pItem->FUN_1405276c0());
    if (spData == 0)
        return;
    Unk_ItemSlot188 spLife = pItem->FUN_14052b8c0();
    if (pItem->FUN_140528910() < 1)
    {
        if ((CPtred*)spLife != 0 && static_cast<NpcShopItemLife*>(spLife.get())->FUN_14026f0f0())
        {
            // the slot holds the item's NpcShopItemLife reference (same 16-byte handle as Unk_ShopLifeRef)
            FUN_1409cf4d0(reinterpret_cast<Unk_ShopLifeRef&>(spLife));
            return;
        }
        if (spData->FUN_14053d660() || spData->FUN_14053ce20())
            FUN_1409d6a40(pItem->FUN_1405276c0(), 0);
        return;
    }
    if (pItem->FUN_140525640() != 0)
        return;
    CMsTime time(pItem->FUN_140528910());
    int nYear = time.GetYear();
    int nMonth = time.GetMonth();
    int nDay = time.GetDay();
    int nHour = time.GetHour();
    int nMinute = time.GetMinute();
    CStringW strText(L"");
    if (pItem->FUN_140527840() != 0 && pItem->FUN_140527840()->FUN_14053cde0())
    {
        bool bExpired = pItem->FUN_140528930();
        strText = bExpired ? BlockFormat(0xbb, nYear, nMonth, nDay, nHour, nMinute) : BlockFormat(0xba, nYear, nMonth, nDay, nHour, nMinute);
    }
    else if (pItem->FUN_140527840() != 0 && pItem->FUN_140527840()->FUN_14053ce20())
    {
        bool bExpired = pItem->FUN_140528930();
        strText = bExpired ? BlockFormat(0xbd, nYear, nMonth, nDay, nHour, nMinute) : BlockFormat(0xbc, nYear, nMonth, nDay, nHour, nMinute);
    }
    else
    {
        bool bExpired = pItem->FUN_140528930();
        strText = bExpired ? BlockFormat(0xb9, nYear, nMonth, nDay, nHour, nMinute) : BlockFormat(0xb8, nYear, nMonth, nDay, nHour, nMinute);
    }
    FUN_1407cbb20("itemUsePeriod", strText);
}
MS2_REPLACE_METHOD(0x1409CE950, ASTooltip, FUN_1409ce950, 1710, 0x68CBE9AD);

// itemUsePeriod: the use period in minutes as "{days}{ hours}{ minutes}".
// @0x1409cf010
// MS2-FUNCTIONAL: frame 8 bytes smaller than the exe (an extra temporary there)
void ASTooltip::FUN_1409cf010(CItem* pItem, unsigned n)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(pItem->FUN_1405276c0());
    if (spData == 0)
        return;
    if (n > 0)
    {
        CStringW strText(L"");
        CStringW strDays(L"");
        CStringW strHours(L"");
        CStringW strMinutes(L"");
        ATL::CTimeSpan span(n * 60);
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
        strText = StringFormat(L"{0}{1}{2}", strDays, strHours, strMinutes);
        if (spData->FUN_14053ce20())
            FUN_1407cbb20("itemUsePeriod", FUN_14052bd00(0xc3, strText));
        else if (spData->FUN_14053cde0())
            FUN_1407cbb20("itemUsePeriod", FUN_14052bd00(0xc4, strText));
        else
            FUN_1407cbb20("itemUsePeriod", FUN_14052bd00(0xc2, strText));
    }
}
// (hook registration line kept off line numbers used by astooltip.cpp: the thunk names use __LINE__)
MS2_REPLACE_METHOD(0x1409CF010, ASTooltip, FUN_1409cf010, 1208, 0x498EDCFE);

// itemUsePeriod of a shop item life: a duration (1), an end date (2), weekly (3) or monthly (4) expiry.
// @0x1409cf4d0
// MS2-FUNCTIONAL: frame/temporary layout differs from the exe
void ASTooltip::FUN_1409cf4d0(Unk_ShopLifeRef spLife)
{
    if (spLife == 0)
        return;
    switch (spLife->m_type)
    {
    case 1:
    {
        CStringW strText(L"");
        CStringW strDays(L"");
        CStringW strHours(L"");
        CStringW strMinutes(L"");
        ATL::CTimeSpan span((unsigned)(spLife->m_value * 60));
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
        strText = StringFormat(L"{0}{1}{2}", strDays, strHours, strMinutes);
        FUN_1407cbb20("itemUsePeriod", FUN_14052bd00(0xbe, strText));
        break;
    }
    case 2:
    {
        int nYear = spLife->m_time.GetYear();
        int nMonth = spLife->m_time.GetMonth();
        int nDay = spLife->m_time.GetDay();
        int nHour = spLife->m_time.GetHour();
        int nMinute = spLife->m_time.GetMinute();
        FUN_1407cbb20("itemUsePeriod", FUN_14052bd00(0xbf, BlockFormat(0xb8, nYear, nMonth, nDay, nHour, nMinute)));
        break;
    }
    case 3:
    {
        unsigned nWeeks = spLife->m_value;
        if (nWeeks == 0)
            nWeeks = 1;
        FUN_1407cbb20("itemUsePeriod", FUN_14028dfa0(CStringW(L"s_item_end_time_tooltip_expirationtype_weekly"), nWeeks));
        break;
    }
    case 4:
    {
        unsigned nMonths = spLife->m_value;
        if (nMonths == 0)
            nMonths = 1;
        FUN_1407cbb20("itemUsePeriod", FUN_14028dfa0(CStringW(L"s_item_end_time_tooltip_expirationtype_monthly"), nMonths));
        break;
    }
    }
}
// not hooked: by-value Unk_ShopLifeRef parameter (the callee destroys it)

// itemCompare: the stat change of equipping the item (stats, special stats, the item level score).
// @0x1409cfbf0
// MS2-FUNCTIONAL: frame/temporary layout differs from the exe
void ASTooltip::FUN_1409cfbf0(CItem* pItem)
{
    MyPC* pPC = FUN_1409613d0((PCBase*)m_40);
    if (pPC == 0 || (m_48 & 0x800) != 0)
        return;
    if (pItem->FUN_140527840()->FUN_14053c5c0() != 1)
        return;
    static ATL::CAtlArray<int> s_aStatOrder;
    if (s_aStatOrder.IsEmpty())
    {
        s_aStatOrder.Add(0x1c);
        s_aStatOrder.Add(0x1d);
        s_aStatOrder.Add(0x1e);
        s_aStatOrder.Add(0x14);
        s_aStatOrder.Add(4);
        s_aStatOrder.Add(7);
        s_aStatOrder.Add(10);
        s_aStatOrder.Add(0xe);
        s_aStatOrder.Add(0x20);
        s_aStatOrder.Add(0);
        s_aStatOrder.Add(1);
        s_aStatOrder.Add(2);
        s_aStatOrder.Add(3);
        s_aStatOrder.Add(0x17);
        s_aStatOrder.Add(0x18);
        s_aStatOrder.Add(0xd);
        s_aStatOrder.Add(0xf);
        s_aStatOrder.Add(0x11);
        s_aStatOrder.Add(0x19);
        s_aStatOrder.Add(0x1a);
        s_aStatOrder.Add(0x12);
        s_aStatOrder.Add(0x10);
        s_aStatOrder.Add(0x13);
        s_aStatOrder.Add(0x15);
        s_aStatOrder.Add(0x16);
        s_aStatOrder.Add(0x1f);
        s_aStatOrder.Add(5);
        s_aStatOrder.Add(6);
        s_aStatOrder.Add(8);
        s_aStatOrder.Add(9);
        s_aStatOrder.Add(0xb);
        s_aStatOrder.Add(0xc);
    }
    int aStat[35] = {0};
    int aSpecial[207] = {0};
    int nScore = 0;
    pPC->FUN_141523e60(pItem, aStat, aSpecial, &nScore);
    ASArray arr(2);
    for (unsigned i = 0; i < s_aStatOrder.GetCount(); i++)
    {
        int nStat = s_aStatOrder[i];
        if (aStat[nStat] != 0)
        {
            ASObj obj(2);
            obj.FUN_1407cbb20("statName", FUN_14082f000(nStat));
            if (!FUN_14082f250(nStat))
                obj.FUN_1407cbb20("statValue", FUN_1409e0900(abs(aStat[nStat])));
            else
                obj.FUN_1407cbb20("statRate", FUN_1409e0b40(abs(aStat[nStat])));
            bool bUp = aStat[nStat] > 0;
            obj.FUN_1407cbbe0("up", bUp);
            arr.FUN_1422bc050(obj.FUN_1422bb870());
        }
    }
    for (int i = 0; i < 0xcf; i++)
    {
        int nSpecial = i;
        CStringW strName = FUN_140630e10(i);
        if (strName.IsEmpty())
            continue;
        if (aSpecial[nSpecial] != 0)
        {
            ASObj obj(2);
            obj.FUN_1407cbb20("statName", strName);
            if (!FUN_14081dcd0(nSpecial))
                obj.FUN_1407cbb20("statValue", FUN_1409e0900(abs(aSpecial[nSpecial])));
            else
                obj.FUN_1407cbb20("statRate", FUN_1409e0b40(abs(aSpecial[nSpecial])));
            bool bUp = aSpecial[nSpecial] > 0;
            obj.FUN_1407cbbe0("up", bUp);
            arr.FUN_1422bc050(obj.FUN_1422bb870());
        }
    }
    if (nScore != 0)
    {
        ASObj obj(2);
        obj.FUN_1407cbb20("statName", FUN_14028b8e0(CStringW(L"s_common_item_level")));
        obj.FUN_1407cbb20("statRate", FUN_1409e0900(abs(nScore)));
        bool bUp = nScore > 0;
        obj.FUN_1407cbbe0("up", bUp);
        arr.FUN_1422bc050(obj.FUN_1422bb870());
    }
    FUN_1409adbe0("itemCompare", arr.FUN_1422bb870());
}
MS2_REPLACE_METHOD(0x1409CFBF0, ASTooltip, FUN_1409cfbf0, 2840, 0xE852E99E);

// itemDescription: the music score / UGC text, else the string table's tooltipDescription.
// @0x1409d0710
// MS2-FUNCTIONAL: frame 8 bytes smaller than the exe (an extra temporary there)
void ASTooltip::FUN_1409d0710(CItem* pItem)
{
    if (pItem == 0)
        return;
    int bCustom = 0;
    CStringW strDesc;
    if (pItem->FUN_140525f10() == 0 && pItem->FUN_140526010() == 0)
    {
        if (pItem->FUN_140525790())
        {
            int nId = pItem->FUN_140527840()->FUN_14053c510();
            MS2Ptr<ItemMusicScore> spScore = FUN_140281980_p2()->GetMusicScore(nId);
            bCustom = (ItemMusicScore*)spScore != 0;
            if (bCustom)
            {
                int nMax = spScore->FUN_14054ade0();
                strDesc = FUN_1408116a0(0x9be, nMax);
            }
        }
    }
    else
    {
        Unk_ItemUgcInfo* pUgc = pItem->FUN_1405278d0();
        if (pUgc != 0)
        {
            if (pUgc->FUN_1406321a0() == 0)
            {
                int nLength = pItem->FUN_1405278d0()->FUN_140632100().GetLength();
                if (nLength > 0)
                {
                    bCustom = 1;
                    strDesc.Empty();
                }
            }
            else
            {
                bCustom = 1;
                strDesc = FUN_14028de60(0xf3);
            }
        }
    }
    if (bCustom != 0)
        FUN_1407cbb20("itemDescription", strDesc);
    else
    {
        CStringW strText = FUN_1401a9d70_p3()->FUN_141811c90(pItem->FUN_1405276c0(), "tooltipDescription");
        FUN_1403b4750()->FUN_1416fb340(strText);
        FUN_1407cbb20("itemDescription", strText);
    }
}
MS2_REPLACE_METHOD(0x1409D0710, ASTooltip, FUN_1409d0710, 873, 0xFBAEFA73);

// itemGuideDescription: the guide text of an item (box contents, billboard limits, object rights, housing limits and
// the trophy requirement), followed by m_50.
// @0x1409d0a80
// MS2-FUNCTIONAL: temporary/frame layout differs from the exe
void ASTooltip::FUN_1409d0a80(CItem* pItem)
{
    MS2Ptr<CItemData> spData(pItem->FUN_140527840());
    if (spData == 0)
        return;
    int bCustom = 0;
    CStringW strDesc;
    if (pItem->FUN_140525f10() == 0 && pItem->FUN_140526010() == 0)
    {
        if (!pItem->FUN_140525790())
        {
            if (pItem->FUN_140527840()->FUN_14053ccc0() && FUN_140166410()->FUN_14036d570(0xad))
            {
                bCustom = 1;
                strDesc = FUN_1401a9d70_p3()->FUN_141811c90(pItem->FUN_1405276c0(), "guideDescription");
                strDesc += FUN_14028b8e0(CStringW(L"s_multi_riding_item_desc"));
            }
        }
        else
        {
            bCustom = 1;
            strDesc = FUN_14028de60(0x9bf);
        }
    }
    else
    {
        Unk_ItemUgcInfo* pUgc = pItem->FUN_1405278d0();
        if (pUgc != 0 && (pUgc->FUN_1406321a0() != 0 || pUgc->FUN_140632100().GetLength() > 0))
        {
            bCustom = 1;
            strDesc.Empty();
        }
    }
    CStringW strResult;
    if (bCustom != 0)
    {
        PCBase* pPC = FUN_141bd0cc0_p2(FUN_1403ed2d0_p2());
        if (pPC != 0)
        {
            int nA = FUN_141901d20(pItem->FUN_1405276c0(), pItem->FUN_140526a50(), pItem->FUN_1405283d0());
            int nB = FUN_141901f70(pItem->FUN_1405276c0(), pItem->FUN_140526a50(), pItem->FUN_1405283d0());
            if (nA != 0 || nB != 0)
            {
                if (!strDesc.IsEmpty())
                    strDesc.Append(L"\n");
                strDesc.Append(BlockFormat(0x6fd, nB, nA));
            }
        }
        strResult = strDesc;
    }
    else
    {
        CStringW strGuide = FUN_1401a9d70_p3()->FUN_141811c90(pItem->FUN_1405276c0(), "guideDescription");
        if (spData->FUN_14053c5c0() == 0x1a)
        {
            int bExpiring = 0;
            ATL::CAtlList<CStringW> list;
            FUN_1409dfba0(spData, list, &bExpiring, 15, pItem->FUN_140528910());
            if (!list.IsEmpty())
            {
                CStringW strItems;
                POSITION pos = list.GetHeadPosition();
                while (pos != 0)
                {
                    strItems.Append(list.GetAt(pos));
                    list.GetNext(pos);
                }
                strGuide.Append(L"\n\n");
                strGuide.Append(FUN_14028b8e0(CStringW(L"s_gachaitem_acquire")));
                strGuide.Append(L"\n");
                strGuide.Append(strItems);
                strGuide.Append(L"\n");
                strGuide.Append(FUN_14028b8e0(CStringW(L"s_gachaitem_open_desc")));
                if (bExpiring != 0)
                {
                    strGuide.Append(L"\n");
                    strGuide.Append(FUN_14028b8e0(CStringW(L"s_item_end_time_tooltip_expiration_notice")));
                }
            }
        }
        else if (spData->FUN_14053cd90() == true && spData->function.name == L"InstallBillBoard")
        {
            if (DAT_143ab2964 != 0)
                strGuide.Append(FUN_14028dfa0(CStringW(L"s_special_item_billboard_tooltip_limit_defence_spamer_level"), DAT_143ab2964));
            if (DAT_143ab2970 != 0)
                strGuide.Append(FUN_14028dfa0(CStringW(L"s_special_item_billboard_tooltip_limit_defence_spamer_adventure_level"), DAT_143ab2970));
        }
        else
        {
            int nObjCode = pItem->FUN_140527840()->install.objCode;
            if (nObjCode != 0)
            {
                if (FUN_1407077c0(nObjCode) != 0)
                    strGuide = FUN_14052bd00(0xafa, strGuide);
                if (FUN_140707710(nObjCode) != 0)
                    strGuide = FUN_14052bd00(0xaf9, strGuide);
            }
            if (!spData->FUN_14053cb80())
            {
                if (spData->FUN_14053c5c0() == 0x19 && FUN_1409e0450(pItem->FUN_1405276c0(), pItem->FUN_140528910()) != 0)
                {
                    strGuide.Append(L"\n");
                    strGuide.Append(FUN_14028b8e0(CStringW(L"s_item_end_time_tooltip_expiration_notice")));
                }
            }
            else
            {
                int nHousingId = spData->FUN_14053c510();
                MS2Ptr<ItemHousing> spHousing = FUN_140281980_p2()->GetHousing(nHousingId);
                if (spHousing == 0)
                    return;
                unsigned short nLevel = spHousing->interiorLevel;
                unsigned nTrophyId = spHousing->trophyID;
                unsigned nTrophyLevel = spHousing->trophyLevel;
                int nPriceCount = spHousing->priceCount;
                bool bLocal = !FUN_140930c50();
                if (FUN_140166410()->FUN_14036d570(0xdb) && nLevel != 0 && nPriceCount == 1)
                {
                    UGCCubeCategoryTable::InteriorPtr spInterior = TSingleton<UGCCubeCategoryTable>::GetInstance()->GetInterior(spHousing->categoryIndex);
                    if (spInterior.get() != 0)
                    {
                        int nCurrent = nLevel;
                        nLevel = spInterior->m_nRequireLevel < nCurrent ? nLevel : spInterior->m_nRequireLevel;
                    }
                    bool bShow = false;
                    if (bLocal)
                    {
                        if (DAT_143ab291c < nLevel)
                            bShow = true;
                    }
                    else
                        bShow = DAT_143ab2940 < nLevel;
                    if (bShow)
                    {
                        if (!strGuide.IsEmpty())
                            strGuide.Append(L"\n");
                        strGuide.Append(BlockFormat(0x6fa, nLevel));
                    }
                }
                bool bTrophy = false;
                if (bLocal)
                {
                    if (FUN_140936640(FUN_1406c7600(), nTrophyId, nTrophyLevel) == 0)
                        bTrophy = true;
                }
                else
                {
                    Unk_SSGHouseKey key;
                    key.m_nA = nTrophyId;
                    key.m_nB = nTrophyLevel;
                    bTrophy = DAT_143ab32d8.find(key) != DAT_143ab32d8.end();
                }
                if (bTrophy)
                {
                    CStringW strTrophy = FUN_14093bd40(nTrophyId, nTrophyLevel, CStringW(L""));
                    if (!strTrophy.IsEmpty())
                    {
                        if (!strGuide.IsEmpty())
                            strGuide.Append(L"\n");
                        strGuide.Append(FUN_14028dfa0(CStringW(L"s_construct_require_trophy"), strTrophy));
                    }
                }
                PCBase* pPC = FUN_141bd0cc0_p2(FUN_1403ed2d0_p2());
                if (bLocal && pPC != 0)
                {
                    int nA = FUN_141901d20(pItem->FUN_1405276c0(), pItem->FUN_140526a50(), pItem->FUN_1405283d0());
                    int nB = FUN_141901f70(pItem->FUN_1405276c0(), pItem->FUN_140526a50(), pItem->FUN_1405283d0());
                    if (nA != 0 || nB != 0)
                    {
                        if (!strGuide.IsEmpty())
                            strGuide.Append(L"\n");
                        strGuide.Append(BlockFormat(0x6fd, nB, nA));
                    }
                }
            }
        }
        strResult = strGuide;
    }
    if (!m_50.IsEmpty())
    {
        if (!strResult.IsEmpty())
            strResult.Append(L"\n");
        strResult.Append(m_50);
    }
    FUN_1407cbb20("itemGuideDescription", strResult);
}
// not hooked: TSingleton<UGCCubeCategoryTable>::GetInstance reads the DLL-local s_instance

// The main description in the full (0x800 clear) or the compact layout.
// @0x1409d1d30
void ASTooltip::FUN_1409d1d30(CItem* pItem)
{
    if ((m_48 & 0x800) != 0)
        FUN_1409d26d0(pItem);
    else
        FUN_1409d1d80(pItem);
}
MS2_REPLACE_METHOD(0x1409D1D30, ASTooltip, FUN_1409d1d30, 68, 0x120E11D7);

// statDescription (full layout): the main description, the pet size-up level, the chat emoticon, the book, a special
// description or the music score text.
// @0x1409d1d80
// MS2-FUNCTIONAL: temporary/frame layout differs from the exe
void ASTooltip::FUN_1409d1d80(CItem* pItem)
{
    if (pItem == 0)
        return;
    Unk_EnchantPtr<CItemEnchantInfo> spEnchant(FUN_140630d60_p2(pItem->FUN_1405278a0()));
    if (!spEnchant)
        return;
    MS2Ptr<CItemData> spData(pItem->FUN_140527840());
    if (spData.IsNull())
        return;
    CStringW strMain = FUN_1401a9d70_p3()->FUN_141811c90(pItem->FUN_1405276c0(), "mainDescription");
    if (strMain.GetLength() > 0)
    {
        ASObj row(2);
        row.FUN_1407cb9c0("type", 0);
        row.FUN_1407cbb20("text", strMain);
        FUN_1409adbe0("statDescription", row.FUN_1422bb870());
        return;
    }
    if (pItem->FUN_140525640() != 0)
    {
        int nPetId = pItem->FUN_140527840()->FUN_14053dc60();
        MS2Ptr<CPetData> spPet = FUN_14052d210()->Find(nPetId);
        if (spPet.get() != 0 && spPet->m_nType == 1)
        {
            CStringW strText;
            unsigned short nLevel = pItem->FUN_140528c20();
            strText.Format(L"%s", (const wchar_t*)FUN_14028dfa0(CStringW(L"s_word_petlevel_sizeup"), nLevel));
            ASObj row(2);
            row.FUN_1407cb9c0("type", 0);
            row.FUN_1407cbb20("text", strText);
            FUN_1409adbe0("statDescription", row.FUN_1422bb870());
        }
        return;
    }
    if (spData->FUN_14053dfd0(CStringW(L"ChatEmoticonAdd")))
    {
        CStringW strText = FUN_1409daff0(spData);
        ASObj row(2);
        row.FUN_1407cb9c0("type", 0);
        row.FUN_1407cbb20("text", strText);
        FUN_1409adbe0("statDescription", row.FUN_1422bb870());
        return;
    }
    if (pItem->FUN_1405262c0() != 0)
    {
        int nBookId = pItem->FUN_140527840()->FUN_14053df80();
        CStringW strText = FUN_1416e4df0(nBookId);
        ASObj row(2);
        row.FUN_1407cb9c0("type", 0);
        row.FUN_1407cbb20("text", strText);
        FUN_1409adbe0("statDescription", row.FUN_1422bb870());
        return;
    }
    if (FUN_1409d4760(pItem))
        return;
    if (!pItem->FUN_140527840()->FUN_14053cd10())
        return;
    CStringW strText = FUN_1409da1c0(pItem);
    if (strText.IsEmpty())
        return;
    ASObj row(2);
    row.FUN_1407cb9c0("type", 0);
    row.FUN_1407cbb20("text", strText);
    FUN_1409adbe0("statDescription", row.FUN_1422bb870());
}
MS2_REPLACE_METHOD(0x1409D1D80, ASTooltip, FUN_1409d1d80, 2376, 0x9D5E3B93);

// statDescription (compact layout).
// @0x1409d26d0
// MS2-FUNCTIONAL: temporary/frame layout differs from the exe
void ASTooltip::FUN_1409d26d0(CItem* pItem)
{
    if (pItem == 0)
        return;
    Unk_EnchantPtr<CItemEnchantInfo> spEnchant(FUN_140630d60_p2(pItem->FUN_1405278a0()));
    if (!spEnchant)
        return;
    CStringW strMain = FUN_1401a9d70_p3()->FUN_141811c90(pItem->FUN_1405276c0(), "mainDescription");
    if (strMain.GetLength() > 0)
    {
        ASObj row(2);
        row.FUN_1407cb9c0("type", 0);
        row.FUN_1407cbb20("text", strMain);
        FUN_1409adbe0("statDescription", row.FUN_1422bb870());
        return;
    }
    if (pItem->FUN_140525640() != 0)
    {
        int nPetId = pItem->FUN_140527840()->FUN_14053dc60();
        MS2Ptr<CPetData> spPet = FUN_14052d210()->Find(nPetId);
        if (spPet.get() != 0 && spPet->m_nType == 1)
        {
            CStringW strText;
            unsigned short nLevel = pItem->FUN_140528c20();
            strText.Format(L"%s", (const wchar_t*)FUN_14028dfa0(CStringW(L"s_word_petlevel_sizeup"), nLevel));
            ASObj row(2);
            row.FUN_1407cb9c0("type", 0);
            row.FUN_1407cbb20("text", strText);
            FUN_1409adbe0("statDescription", row.FUN_1422bb870());
            return;
        }
    }
    if (FUN_1409d4760(pItem))
        return;
    if (!pItem->FUN_140527840()->FUN_14053cd10())
        return;
    CStringW strText = FUN_1409da1c0(pItem);
    if (strText.IsEmpty())
        return;
    ASObj row(2);
    row.FUN_1407cb9c0("type", 0);
    row.FUN_1407cbb20("text", strText);
    FUN_1409adbe0("statDescription", row.FUN_1422bb870());
}
MS2_REPLACE_METHOD(0x1409D26D0, ASTooltip, FUN_1409d26d0, 1490, 0xE8CE7567);

// customizeColor: the dye hint of a customizable item.
// @0x1409d2cb0
// MS2-FUNCTIONAL: temporary/frame layout differs from the exe
bool ASTooltip::FUN_1409d2cb0(CItem* pItem)
{
    MyPC* pPC = (MyPC*)FUN_1409c6540();
    if (pPC == 0)
        return false;
    MS2Ptr<CItemData> spData(pItem->FUN_140527840());
    if (spData == 0)
        return false;
    bool bCustomizable = spData->FUN_14053e170();
    if (!bCustomizable)
        return false;
    CStringW strText;
    unsigned nFlags = m_48;
    int nColor = spData->FUN_14053e2b0(0);
    if ((nFlags & 4) == 0 || nColor >= 0)
        strText = FUN_14028de60(0x9b7);
    else
    {
        MS2Ptr<CEquipItem> spEquip = pPC->FUN_141655c30(pItem->FUN_140526a50());
        if (spEquip == 0)
        {
            CStringW strLines;
            strLines.Format(L"%s\n%s", (const wchar_t*)FUN_14028de60(0x9b8), (const wchar_t*)FUN_14028de60(0x9b7));
            strText = strLines;
        }
        else
            strText = FUN_14028de60(0x9b7);
    }
    FUN_1407cbb20("customizeColor", strText);
    return true;
}
MS2_REPLACE_METHOD(0x1409D2CB0, ASTooltip, FUN_1409d2cb0, 857, 0x9F20292B);
