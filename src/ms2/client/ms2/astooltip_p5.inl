// astooltip.cpp part 5: functions 0x1409e0450-0x1409e7dc0 (exe order). Included by astooltip.cpp; merged into it when the unit is done.


// @0x1409e0900
CStringW FUN_1409e0900(int n)
{
    CStringW str = StringFormat(L"{0}", n);
    return str;
}
MS2_REPLACE(0x1409E0900, FUN_1409e0900, 101, 0xC860B13F);

// @0x1409e0970
CStringW FUN_1409e0970(int nStat, int n)
{
    CStringW str = StringFormat((const wchar_t*)GetStatValueText(nStat), n);
    return str;
}
MS2_REPLACE(0x1409E0970, FUN_1409e0970, 153, 0x301A029D);

// @0x1409e0a10
CStringW FUN_1409e0a10(const CStringW& strFormat, int n)
{
    CStringW str = StringFormat((const wchar_t*)strFormat, n);
    return str;
}
MS2_REPLACE(0x1409E0A10, FUN_1409e0a10, 114, 0x05CCA779);

// @0x1409e0a90
CStringW FUN_1409e0a90(float fRate)
{
    CStringW str = FUN_14052bd00(0x98e, StringFormat(L"{0:0.1f}", fRate * 100.0f));
    return str;
}
MS2_REPLACE(0x1409E0A90, FUN_1409e0a90, 169, 0x6FF830AD);

// @0x1409e0b40
CStringW FUN_1409e0b40(int nTenths)
{
    CStringW str = FUN_14052bd00(0x98e, StringFormat(L"{0:0.1f}", (float)nTenths / 10.0f));
    return str;
}
MS2_REPLACE(0x1409E0B40, FUN_1409e0b40, 167, 0x15562167);

// @0x1409e0bf0
CStringW FUN_1409e0bf0(int nStat, int nTenths)
{
    CStringW str = StringFormat((const wchar_t*)GetStatValueText(nStat), (float)nTenths / 10.0f);
    return str;
}
MS2_REPLACE(0x1409E0BF0, FUN_1409e0bf0, 173, 0x06299A49);

// @0x1409e0cb0
CStringW FUN_1409e0cb0(const CStringW& strFormat, float fRate)
{
    CStringW str = StringFormat((const wchar_t*)strFormat, fRate * 100.0f);
    return str;
}
MS2_REPLACE(0x1409E0CB0, FUN_1409e0cb0, 135, 0x798D1A23);

// @0x1409e13f0
int ASTooltip::FUN_1409e13f0(CItem* pCompare, CItem* pItem, int a1, int a2)
{
    if (pItem == 0 && pCompare == 0)
        return 0;
    if (pCompare != 0 && pItem != 0)
    {
        FUN_1409c6d70("export_common_tooltip_tooltipCompare");
        ASTooltip lhs((void*)FUN_1409c6540(), a1, 2);
        ASTooltip rhs((void*)FUN_1409c6540(), a2, 2);
        FUN_1409e15a0(pCompare, pItem, &lhs, &rhs);
    }
    else
    {
        if (pCompare != 0)
        {
            FUN_1409c6580(a1);
            FUN_1409e0d40(pCompare);
        }
        if (pItem != 0)
        {
            FUN_1409c6580(a2);
            FUN_1409e0d40(pItem);
        }
    }
    return 1;
}
// not hooked: constructs local ASTooltip objects with the DLL-compiled ctor (functional, own vftable reference)

// @0x1409e15a0
int ASTooltip::FUN_1409e15a0(CItem* pEquipped, CItem* pItem, ASTooltip* pLhs, ASTooltip* pRhs)
{
    if (pItem == 0 && pEquipped == 0)
        return 0;
    if (pEquipped != 0 && pItem != 0)
    {
        FUN_1409c6d70("export_common_tooltip_tooltipCompare");
        if (pLhs->FUN_1409e0d40(pEquipped) != 0)
            FUN_1409adbe0("lhsTooltip", pLhs->FUN_1422bb870());
        if (pRhs->FUN_1409e0d40(pItem) != 0)
            FUN_1409adbe0("rhsTooltip", pRhs->FUN_1422bb870());
    }
    else
    {
        if (pEquipped != 0)
        {
            *this = *pLhs;
            pLhs->FUN_1409e0d40(pEquipped);
        }
        if (pItem != 0)
        {
            *this = *pRhs;
            pRhs->FUN_1409e0d40(pItem);
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1409E15A0, ASTooltip, FUN_1409e15a0, 447, 0x2508DDC9);

// The skill tooltip at the level the player learnt (level 1 when not learnt).
// @0x1409e1b80
int FUN_1409e1b80(ASTooltip* pTooltip, int nSkillId, int bFromDialog)
{
    MyPC* pPC = (MyPC*)pTooltip->FUN_1409c6540();
    if (pPC == 0)
        return 0;
    MS2Ptr<Unk_TooltipJobSkill> spSkill = FUN_1416546d0_p5(pPC)->FUN_1406394d0(nSkillId);
    if (spSkill.get() != 0)
        return pTooltip->FUN_1409e1c50(nSkillId, spSkill->m_nLevel, bFromDialog);
    return pTooltip->FUN_1409e1c50(nSkillId, 1, bFromDialog);
}
MS2_REPLACE(0x1409E1B80, FUN_1409e1b80, 202, 0x98C7C3C0);

// @0x1409e1c50
int ASTooltip::FUN_1409e1c50(unsigned nSkillId, unsigned short nLevel, int n)
{
    MS2Ptr<SkillData> spSkill = FUN_1401958b0_p5()->GetSkillData(nSkillId);
    if (!spSkill)
        return 0;
    unsigned nOrigId = nSkillId;
    CStringW strSuffix(L"");
    do
    {
        unsigned nTooltipId = spSkill->m_nTooltip;
        if (nTooltipId == 0)
            break;
        unsigned short nTooltipLevel = nLevel;
        MS2Ptr<SkillLevelData> spLevel = FUN_1401958b0_p5()->GetSkillLevelData(nTooltipId, nTooltipLevel);
        if (!spLevel)
        {
            spLevel = FUN_1401958b0_p5()->GetSkillLevelData(nTooltipId, 1);
            nTooltipLevel = 1;
        }
        if (!spLevel)
            break;
        if (g_nDebugUI != 0)
            strSuffix.Format(L"&lt;-[%d]", nSkillId);
        nSkillId = nTooltipId;
        nLevel = nTooltipLevel;
    } while (0);
    MS2Ptr<SkillLevelData> spLevelData = spSkill->FUN_1407e90a0(nLevel);
    if (!spLevelData)
        return 0;
    FUN_1409c6d70("export_common_tooltip_kindsSkill");
    FUN_1409dbef0(nOrigId);
    FUN_1409dbc60(nSkillId, strSuffix);
    FUN_1409dbd30(nSkillId);
    FUN_1409dbfa0(nOrigId);
    FUN_1409dc130(nSkillId, nLevel);
    FUN_1409dc1f0(nSkillId, nLevel);
    FUN_1409dcf10(nSkillId, nLevel, n);
    FUN_1409dc700(nSkillId, nLevel);
    unsigned nFlags = FUN_1409c6560();
    if ((nFlags & 0x40) != 0 || (nFlags & 2) != 0)
        FUN_1409c6dc0(7);
    else
        FUN_1409c6dc0(5);
    return 1;
}
MS2_REPLACE_METHOD(0x1409E1C50, ASTooltip, FUN_1409e1c50, 916, 0x9544E995);

// @0x1409e1ff0
int ASTooltip::FUN_1409e1ff0(CItem* pItem, int nSkillId)
{
    FUN_1409c6d70("export_common_tooltip_tooltipCompareSkill");
    ASTooltip lhs((void*)FUN_1409c6540(), FUN_1409c6560(), 2);
    if (lhs.FUN_1409e0d40(pItem) != 0)
        FUN_1409adbe0("lhsTooltip", lhs.FUN_1422bb870());
    ASTooltip rhs((void*)FUN_1409c6540(), FUN_1409c6560(), 2);
    if (FUN_1409e1b80(&rhs, nSkillId, 0) != 0)
        FUN_1409adbe0("rhsTooltip", rhs.FUN_1422bb870());
    return 1;
}
// not hooked: constructs local ASTooltip objects with the DLL-compiled ctor (functional, own vftable reference)

// @0x1409e21a0
int ASTooltip::FUN_1409e21a0(unsigned nId, unsigned nGrade)
{
    MS2Ptr<CAchieveData> spData = GetAchieveData(nId);
    if (!spData)
        return 0;
    FUN_1409c6d70("export_common_tooltip_kindsAchieve");
    FUN_1409c6dc0(7);
    FUN_1407cb9c0("grade", nGrade);
    FUN_1407cbb20("title", FUN_14093b970(nId));
    FUN_1407cbb20("desc", FUN_14093c8d0(nId, nGrade, 0));
    FUN_1407cbb20("reward", FUN_14093ce70(nId, nGrade));
    FUN_1407cba60("imgPath", FUN_140159490(spData));
    {
        MS2Ptr<CAchieve> spAchieve = FUN_1406c7600()->Find(nId);
        if (spAchieve.get() != 0)
        {
            int nValue = (int)spAchieve->GetValue(nGrade);
            CStringW strState = nValue != 0 ? FUN_14028de60(0x780) : FUN_14028de60(0x77f);
            if (nValue != 0)
            {
                CStringW strDate = FUN_14093e330(spAchieve.get(), nGrade);
                strState = StringFormat(L"{0} ({1})", strState, strDate);
            }
            FUN_1407cbb20("state", strState);
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1409E21A0, ASTooltip, FUN_1409e21a0, 1076, 0x920515FB);

// @0x1409e2630
int ASTooltip::FUN_1409e2630(int nId)
{
    if (nId == 0)
        return 0;
    return FUN_1409e26b0(FUN_1401a9d70()->FUN_141811980(9, nId));
}
MS2_REPLACE_METHOD(0x1409E2630, ASTooltip, FUN_1409e2630, 116, 0xE5467A3C);

// The buff (additional effect) tooltip; pSkillAttr is an AdditionalLevelData.
// @0x1409e2750
int ASTooltip::FUN_1409e2750(void* pSkillAttr, int a1, unsigned a2)
{
    if (pSkillAttr == 0)
        return 0;
    int nMaxWidth = 0x198;
    CStringW strText;
    if (((AdditionalLevelData*)pSkillAttr)->IsBuff())
        strText = StringFormat(L"<FONT color='#00AEFF'>{0}</FONT>\n", FUN_1401a9d70_p5()->FUN_141812290(((AdditionalLevelData*)pSkillAttr)->GetID(), ((AdditionalLevelData*)pSkillAttr)->GetLevel(), "name"));
    else
        strText = StringFormat(L"<FONT color='#FF4040'>{0}</FONT>\n", FUN_1401a9d70_p5()->FUN_141812290(((AdditionalLevelData*)pSkillAttr)->GetID(), ((AdditionalLevelData*)pSkillAttr)->GetLevel(), "name"));
    CStringW strDesc = FUN_1401a9d70_p5()->FUN_141812290(((AdditionalLevelData*)pSkillAttr)->GetID(), ((AdditionalLevelData*)pSkillAttr)->GetLevel(), "tooltipDescription");
    if (a2 > 0 && ((AdditionalLevelData*)pSkillAttr)->m_nDurationTick > 0)
    {
        if (!((AdditionalLevelData*)pSkillAttr)->IsHideBuffIcon())
        {
            CTimeSpan span((__int64)FUN_14028d280(a2));
            CStringW strTime = FormatTimeSpan(span, true, true, true, true);
            if (strTime.IsEmpty() && a2 > 0 && a2 < 1000)
            {
                float fSec = (float)a2 / 1000.0f;
                strTime = FUN_14028dfa0(CStringW(L"s_common_millisec"), fSec);
            }
            CStringW strRemain = StringFormat((const wchar_t*)FUN_14028de60(0x5cf), strTime);
            strDesc.Append(StringFormat(L"\n\n{0}", strRemain));
        }
    }
    strText.Append(strDesc);
    FUN_1409c6d70("export_common_tooltip_tooltipText");
    FUN_1409c6cb0(strText);
    FUN_1409c6e00(0);
    FUN_1409c6e30(0);
    FUN_1409c6dc0(a1);
    FUN_1409c6ec0(0x198);
    return 1;
}
MS2_REPLACE_METHOD(0x1409E2750, ASTooltip, FUN_1409e2750, 1517, 0x92AA5002);

// @0x1409e2d50
void ASTooltip::FUN_1409e2d50(int nCount)
{
    CStringW strText;
    CStringW strCount;
    if (nCount < 0)
        strCount = FUN_14028de60(0x51b);
    else if (nCount == 0)
        strCount = FUN_14028de60(0x51d);
    else
        strCount.Format(L"%d", nCount);
    strText = FUN_14052bd00(0x588, strCount);
    FUN_1407cbb20("text", strText);
}
MS2_REPLACE_METHOD(0x1409E2D50, ASTooltip, FUN_1409e2d50, 378, 0x856F2937);

// Builds the item tooltip of an item-able entry (a reward / drop row) into pOut.
// @0x1409e2ed0
void FUN_1409e2ed0(Scaleform::GFx::Value* pOut, ItemAble& item)
{
    MS2Ptr<CItem> spItem(new CItem());
    if (spItem->FUN_14052b130(item.vfunc_o18_0(), item.vfunc_o18_1(), 0) != 0)
    {
        spItem->FUN_140526c70(item.vfunc_o18_2());
        ASTooltip tip((void*)FUN_141bd0cc0_p5(FUN_1403ed2d0_p5()), 0x20, 2);
        if (tip.FUN_1409e0d40(spItem.get()) != 0)
            *pOut = tip.FUN_1422bb870();
    }
}
// not hooked: constructs local ASTooltip objects with the DLL-compiled ctor (functional, own vftable reference)

// The buy-limit key "<prefix>_<reset>_<scope>".
// @0x1409e3050
CStringW FUN_1409e3050(const CStringW& strPrefix, int nScope, int nReset)
{
    CStringW strScope;
    if (nScope == 1)
        strScope = L"account";
    else if (nScope == 2)
        strScope = L"character";
    CStringW strReset;
    switch (nReset)
    {
    case 0:
        strReset = L"noreset";
        break;
    case 1:
        strReset = L"day";
        break;
    case 2:
        strReset = L"week";
        break;
    case 3:
        strReset = L"month";
        break;
    }
    return StringFormat(L"{0}_{1}_{2}", strPrefix, strReset, strScope);
}
MS2_REPLACE(0x1409E3050, FUN_1409e3050, 314, 0x28431E15);

// The package tooltip of a limited (type 3) merat market product: its items as drop rows.
// @0x1409e3190
bool ASTooltip::FUN_1409e3190(CMeratMarketPremiumProduct* pProduct, bool bWithName)
{
    if (pProduct->m_nType != 3)
        return false;
    CRBMap<int, MS2Ptr<CDBPremiumProduct> >& mapLimit = pProduct->m_mapLimit;
    if (mapLimit.IsEmpty())
        return false;
    std::vector<ItemDropResult> results;
    for (POSITION pos = mapLimit.GetHeadPosition(); pos != 0; mapLimit.GetNext(pos))
    {
        MS2Ptr<CDBPremiumProduct> spSub = mapLimit.GetValueAt(pos);
        if (spSub == 0)
            continue;
        int nRank = spSub->m_nGrade;
        results.push_back(ItemDropResult(spSub->m_nItemId, spSub->m_nb0, nRank, 0, 0, 0, 0, false, false, 0, false, false, false, false));
    }
    if (results.empty())
        return false;
    FUN_1409e72a0(&results);
    CString strKind(bWithName == true ? "export_common_tooltip_item_package_and_name" : "export_common_tooltip_item_package");
    FUN_1409c6d70(strKind);
    FUN_1409dbbc0(pProduct->GetName());
    FUN_1409d55a0(0, pProduct->GetGrade());
    FUN_1409c6dc0(5);
    return true;
}
MS2_REPLACE_METHOD(0x1409E3190, ASTooltip, FUN_1409e3190, 833, 0x2635AC39);

// @0x1409e5320
CStringW FUN_1409e5320(const int& nSeason)
{
    GachaBoxDataPtr spBox = FUN_14052d230_p5()->FUN_14059e340(nSeason);
    if (spBox == 0)
        return L"";
    if ((unsigned)spBox->GetSeason() <= 0)
        return L"";
    CStringW str = FUN_1407196b0(spBox->GetSeason());
    return str;
}
MS2_REPLACE(0x1409E5320, FUN_1409e5320, 284, 0xCE0B0243);

// @0x1409e6010
CStringW FUN_1409e6010(int nKind, CItem* pItem)
{
    if (nKind == 0 && pItem->FUN_140525640() != 0)
    {
        CStringW strKey(L"s_tooltip_itemoption_kinds_constant_pet");
        return FUN_14028b8e0(strKey);
    }
    if (nKind == 2 && pItem->FUN_140525640() != 0)
    {
        CStringW strKey(L"s_tooltip_itemoption_kinds_random_pet");
        return FUN_14028b8e0(strKey);
    }
    return s_wsKindLabel[nKind];
}
// not hooked: reads s_wsKindLabel (filled by FUN_1409e5480 in the exe; the DLL copy stays empty)

// The "enabled jobs" line; nAllowed is set when the player's job (or the beginner job 1) is in the list.
// @0x1409e68a0
void FUN_1409e68a0(int nJob, ATL::CAtlArray<unsigned>& jobs, int& nAllowed, CStringW& strOut)
{
    if (nJob == 1)
        nJob = 10;
    CStringW strList;
    for (unsigned i = 0; i < jobs.GetCount(); i++)
    {
        int nJobId = jobs[i];
        if (FUN_1402226b0(nJobId))
        {
            if (nJobId == 1)
                nAllowed = 1;
            if (nJobId == nJob)
                nAllowed = 1;
            CStringW strName = FUN_1401a9d70_p5()->FUN_141811980(0x4d, nJobId);
            if (strList.IsEmpty())
                strList.Append(strName);
            else
                strList.Append(StringFormat(L", {0}", strName));
        }
    }
    if (strList.GetLength() > 0)
        strOut = FUN_14028dfa0(CStringW(L"s_word_enable_jobs"), strList);
}

// The "disabled jobs" line (tests the output string's length, not the list's, as the exe does).
// @0x1409e6aa0
void FUN_1409e6aa0(int nJob, ATL::CAtlArray<unsigned>& jobs, CStringW& strOut)
{
    CStringW strList;
    for (unsigned i = 0; i < jobs.GetCount(); i++)
    {
        int nJobId = jobs[i];
        if (FUN_1402226b0(nJobId))
        {
            CStringW strName = FUN_1401a9d70_p5()->FUN_141811980(0x4d, FUN_1401d7a50_p5()->GetSubJob1(nJobId));
            if (strList.IsEmpty())
                strList.Append(strName);
            else
                strList.Append(StringFormat(L", {0}", strName));
        }
    }
    if (strOut.GetLength() > 0)
        strOut = FUN_14028dfa0(CStringW(L"s_word_disable_jobs"), strList);
}

// @0x1409e6c80
int FUN_1409e6c80(CItem* pItem)
{
    if (pItem == 0)
        return 0;
    if (!pItem->FUN_140527840()->FUN_14053cbc0())
        return 0;
    if (FUN_1403ed2b0()->FUN_141adc940((eUIClassID)0x4e8d) == 0)
        return 0;
    if (FUN_1403ed2b0()->FUN_141adc940((eUIClassID)0x4e8e) == 0)
        return 0;
    return 1;
}
MS2_REPLACE(0x1409E6C80, FUN_1409e6c80, 112, 0xBBCD868C);

// @0x1409e6fc0
int FUN_1409e6fc0(int nKind)
{
    switch (nKind)
    {
    case 0x28:
    case 0x29:
        return 0x19;
    case 0x2b:
        return 9;
    case 0x2c:
        return 0xe;
    case 0x2d:
        return 0x26;
    case 0x2e:
    case 0x2f:
        return 0x22;
    case 0x30:
    case 0x31:
        return 0xc;
    case 0x32:
        return 0x32;
    case 0x35:
        return 0x17;
    }
    return nKind;
}
MS2_REPLACE(0x1409E6FC0, FUN_1409e6fc0, 118, 0xD6007B33);

// The enablePreview hint ("preview" key binding text).
// @0x1409e7880
CStringW FUN_1409e7880()
{
    CStringW strKey = FUN_1409331f0()->FUN_14142d760(0x49406, 0);
    CStringW str = FUN_14028dfa0(CStringW(L"s_msg_tooltip_enable_preview"), strKey);
    return str;
}
MS2_REPLACE(0x1409E7880, FUN_1409e7880, 168, 0x057BF814);

// Drop list order: higher rank first, then the tooltip-flagged entries.
// @0x1409e7930
bool FUN_1409e7930(ItemDropResult& lhs, ItemDropResult& rhs)
{
    if (lhs.vfunc_o18_1() != rhs.vfunc_o18_1())
        return lhs.vfunc_o18_1() > rhs.vfunc_o18_1();
    int bLhs = lhs.m_tooltip == 1;
    int bRhs = rhs.m_tooltip == 1;
    return bLhs > bRhs;
}
MS2_REPLACE(0x1409E7930, FUN_1409e7930, 259, 0x1A341905);

// Drop list order: the tooltip-flagged entries first, then lower rank first.
// @0x1409e7a40
bool FUN_1409e7a40(ItemDropResult& lhs, ItemDropResult& rhs)
{
    int bLhs = lhs.m_tooltip == 1;
    int bRhs = rhs.m_tooltip == 1;
    if (bLhs != bRhs)
        return bLhs > bRhs;
    return lhs.vfunc_o18_1() < rhs.vfunc_o18_1();
}
MS2_REPLACE(0x1409E7A40, FUN_1409e7a40, 215, 0x3F3CBC7A);
