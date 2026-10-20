// astooltip.cpp part 5: functions 0x1409e0450-0x1409e7dc0 (exe order). Included by astooltip.cpp; merged into it when the unit is done.

// True when an individual drop box item (type 0x19) contains a drop that expires (item life or follows the end date).
// @0x1409e0450
// MS2-FUNCTIONAL: CItemData::FUN_14053d660 is declared bool but the exe tests its eax without movzx (as part 1); CXmlData::GetInt is an inline COMDAT here
int ASTooltip::FUN_1409e0450(int nItemId, __int64 nExpiry)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData == 0)
        return 0;
    if (spData->FUN_14053c5c0() != 0x19)
        return 0;
    bool bFollowEndDate = false;
    int nBoxId = 0;
    unsigned nArgs = spData->function.parameter.FUN_1408d2380();
    if (nArgs > 0)
    {
        int nIndex = nArgs - 1;
        nBoxId = spData->function.parameter.FUN_1408d1fd0(nIndex, 0);
    }
    else
    {
        int nDefault = 0;
        nBoxId = spData->function.xml.GetInt(CStringW(L"individualDropBoxId"), nDefault);
        bool bDefault = false;
        bFollowEndDate = spData->function.xml.FUN_1409e8780(CStringW(L"isFollowEndDate"), bDefault);
    }
    if (nBoxId == 0)
        return 0;
    PCBase* pPc = FUN_141bd0cc0_p5(FUN_1403ed2d0_p5());
    if (pPc == 0)
        return 0;
    std::vector<ItemDropResult> drops;
    ItemDropContext ctx;
    ctx.m_job = FUN_141654700(pPc);
    ctx.m_gender = FUN_141658e60_p5(pPc);
    if (!FUN_1405a1fd0_p5()->GetBoxItems(nBoxId, ctx, drops, true))
        return 0;
    for (std::vector<ItemDropResult>::iterator it = drops.begin(); it != drops.end(); ++it)
    {
        ItemDropResult* pDrop = &*it;
        MS2Ptr<CItemData> spItem = FUN_14053f870(pDrop->m_itemId);
        if (spItem == 0)
            continue;
        if (pDrop->HasItemLife() || spItem->FUN_14053d660())
            return 1;
        int nLifeType = 0;
        if (pDrop->m_itemLife)
            nLifeType = pDrop->m_itemLife->m_type;
        CItemData* pItem = spItem.operator->();
        bool bExpiring = FUN_14052a3f0(bFollowEndDate, nExpiry, spData->period.expirationType, nLifeType, pItem->period.expirationType);
        if (bExpiring)
            return 1;
    }
    return 0;
}
namespace p5hook { MS2_REPLACE_METHOD(0x1409E0450, ASTooltip, FUN_1409e0450, 1192, 0x235C66A5); }


// @0x1409e0900
CStringW FUN_1409e0900(int n)
{
    CStringW str = StringFormat(L"{0}", n);
    return str;
}
namespace p5hook { MS2_REPLACE(0x1409E0900, FUN_1409e0900, 101, 0xC860B13F); }

// @0x1409e0970
CStringW FUN_1409e0970(int nStat, int n)
{
    CStringW str = StringFormat((const wchar_t*)GetStatValueText(nStat), n);
    return str;
}
namespace p5hook { MS2_REPLACE(0x1409E0970, FUN_1409e0970, 153, 0x301A029D); }

// @0x1409e0a10
CStringW FUN_1409e0a10(const CStringW& strFormat, int n)
{
    CStringW str = StringFormat((const wchar_t*)strFormat, n);
    return str;
}
namespace p5hook { MS2_REPLACE(0x1409E0A10, FUN_1409e0a10, 114, 0x05CCA779); }

// @0x1409e0a90
CStringW FUN_1409e0a90(float fRate)
{
    CStringW str = FUN_14052bd00(0x98e, StringFormat(L"{0:0.1f}", fRate * 100.0f));
    return str;
}
namespace p5hook { MS2_REPLACE(0x1409E0A90, FUN_1409e0a90, 169, 0x6FF830AD); }

// @0x1409e0b40
CStringW FUN_1409e0b40(int nTenths)
{
    CStringW str = FUN_14052bd00(0x98e, StringFormat(L"{0:0.1f}", (float)nTenths / 10.0f));
    return str;
}
namespace p5hook { MS2_REPLACE(0x1409E0B40, FUN_1409e0b40, 167, 0x15562167); }

// @0x1409e0bf0
CStringW FUN_1409e0bf0(int nStat, int nTenths)
{
    CStringW str = StringFormat((const wchar_t*)GetStatValueText(nStat), (float)nTenths / 10.0f);
    return str;
}
namespace p5hook { MS2_REPLACE(0x1409E0BF0, FUN_1409e0bf0, 173, 0x06299A49); }

// @0x1409e0cb0
CStringW FUN_1409e0cb0(const CStringW& strFormat, float fRate)
{
    CStringW str = StringFormat((const wchar_t*)strFormat, fRate * 100.0f);
    return str;
}
namespace p5hook { MS2_REPLACE(0x1409E0CB0, FUN_1409e0cb0, 135, 0x798D1A23); }

// Fills the whole item tooltip of an item; 0 when the item has no data.
// @0x1409e0d40
// MS2-FUNCTIONAL: /Od frame is 0x10 larger (locals placed differently); same calls and control flow
int ASTooltip::FUN_1409e0d40(CItem* pItem)
{
    if (pItem == 0)
        return 0;
    MS2Ptr<CItemData> spData(pItem->FUN_140527840());
    if (!spData)
        return 0;
    {
        CString strKind("export_common_tooltip_kindsItem");
        FUN_1409c6d70(strKind);
    }
    if (FUN_140166410_p5()->FUN_14036d570(0x8c))
        FUN_1409d43e0(pItem);
    else
        FUN_1409d5160(pItem->FUN_1405276c0());
    int nItemId = pItem->FUN_1405276c0();
    FUN_1409d5200(pItem->FUN_1405276c0());
    FUN_1409d52a0(pItem->FUN_1405276c0());
    FUN_1409d5340(pItem->FUN_1405276c0());
    FUN_1409d53f0(pItem->FUN_1405276c0());
    FUN_1409d5490(pItem->FUN_1405276c0());
    FUN_1409c7c10(pItem);
    FUN_1409c7c70(pItem);
    FUN_1409d5610(pItem->FUN_1405276c0());
    FUN_1409c7cc0(pItem);
    FUN_1409c7f70(pItem);
    FUN_1409c7fc0(pItem);
    FUN_1409c8020(pItem);
    FUN_1409cc800(pItem);
    FUN_1409cd5b0(pItem);
    FUN_1409cd6b0(pItem);
    FUN_1409cd9c0(pItem);
    FUN_1409ce5f0(pItem);
    FUN_1409ce950(pItem);
    FUN_1409d5920(pItem->FUN_1405276c0());
    FUN_1409d7900(nItemId);
    FUN_1409cfbf0(pItem);
    FUN_1409d0710(pItem);
    FUN_1409d0a80(pItem);
    FUN_1409d1d30(pItem);
    FUN_1409d64a0(pItem->FUN_1405276c0(), pItem->FUN_140526bd0(), pItem->FUN_140529070(), pItem->FUN_140529090());
    FUN_1409c7b10(pItem);
    FUN_1409c72c0(pItem);
    FUN_1409d88e0(MS2Ptr<CItem>(pItem));
    FUN_1409d3470(pItem);
    FUN_1409d3f10(pItem);
    FUN_1409d4350(pItem->FUN_140527840());
    FUN_1409d43b0(pItem);
    FUN_1409d4460(pItem);
    FUN_1409d8570(pItem);
    FUN_1409d4490(pItem);
    FUN_1409d46a0(pItem);
    FUN_1409d46e0(pItem);
    bool bSkill = spData->FUN_14053e900() == 0xb;
    FUN_1409d8d50(bSkill);
    unsigned nFlags = FUN_1409c6560();
    if ((nFlags & 0x80) != 0 || (nFlags & 4) != 0)
        FUN_1409cd750(pItem);
    if (((nFlags & 0x80) != 0 || (nFlags & 4) != 0 || (nFlags & 0x200) != 0 || (nFlags & 0x20) != 0 ||
            (nFlags & 0x400) != 0 || (nFlags & 0x1000) != 0 || (nFlags & 0x100) != 0 || (nFlags & 2) != 0) &&
        FUN_1409d2cb0(pItem))
        FUN_1409d3010(pItem);
    if ((nFlags & 0x80) != 0 || (nFlags & 0x400) != 0 || (nFlags & 0x1000) != 0)
        FUN_1409d3a40(pItem);
    if ((nFlags & 0x40) == 0 && (nFlags & 2) == 0)
        FUN_1409c6dc0(5);
    else
        FUN_1409c6dc0(9);
    return 1;
}
namespace p5hook { MS2_REPLACE_METHOD(0x1409E0D40, ASTooltip, FUN_1409e0d40, 1621, 0x0A9BE151); }

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
namespace p5hook { MS2_REPLACE_METHOD(0x1409E15A0, ASTooltip, FUN_1409e15a0, 447, 0x2508DDC9); }

// Fills the whole item tooltip of an item id (no item instance) at a rank; 0 when the item has no data.
// @0x1409e1770
// MS2-FUNCTIONAL: ASTooltip::FUN_1409d55a0 is declared (CItem*, int) but the exe passes the item id (unused by the callee)
int ASTooltip::FUN_1409e1770(int nItemId, int nRank)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (!spData)
        return 0;
    {
        CString strKind("export_common_tooltip_kindsItem");
        FUN_1409c6d70(strKind);
    }
    if (FUN_140166410_p5()->FUN_14036d570(0x8c))
        FUN_1409d7560(nItemId, nRank);
    else
        FUN_1409d5160(nItemId);
    FUN_1409d5200(nItemId);
    FUN_1409d52a0(nItemId);
    FUN_1409d5340(nItemId);
    FUN_1409d53f0(nItemId);
    FUN_1409d5490(nItemId);
    FUN_1409d5530(nItemId);
    FUN_1409d55a0(0, nRank);
    FUN_1409d5610(nItemId);
    FUN_1409d56b0(nItemId);
    FUN_1409c8df0(nItemId);
    FUN_1409d5770(nItemId);
    FUN_1409d5850(nItemId);
    FUN_1409d5860(nItemId, nRank);
    FUN_1409d5920(nItemId);
    FUN_1409d7900(nItemId);
    FUN_1409d5aa0(nItemId);
    FUN_1409d5b70(nItemId);
    FUN_1409d6120(nItemId);
    FUN_1409d64a0(nItemId, nRank, 0, 0);
    FUN_1409d6730(nItemId);
    FUN_1409d4350(spData);
    FUN_1409d6a40(nItemId, 0);
    FUN_1409d8800(spData);
    FUN_1409d74a0(nItemId);
    FUN_1409d8300(nItemId);
    FUN_1409d8650(nItemId, nRank, 0);
    FUN_1409d7630(nItemId);
    FUN_1409d77b0(nItemId);
    bool bSkill = spData->FUN_14053e900() == 0xb;
    FUN_1409d8d50(bSkill);
    unsigned nFlags = FUN_1409c6560();
    if ((nFlags & 0x40) == 0 && (nFlags & 2) == 0)
        FUN_1409c6dc0(5);
    else
        FUN_1409c6dc0(7);
    return 1;
}
namespace p5hook { MS2_REPLACE_METHOD(0x1409E1770, ASTooltip, FUN_1409e1770, 1028, 0xB3EFB093); }

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
namespace p5hook { MS2_REPLACE(0x1409E1B80, FUN_1409e1b80, 202, 0x98C7C3C0); }

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
namespace p5hook { MS2_REPLACE_METHOD(0x1409E1C50, ASTooltip, FUN_1409e1c50, 916, 0x9544E995); }

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
namespace p5hook { MS2_REPLACE_METHOD(0x1409E21A0, ASTooltip, FUN_1409e21a0, 1076, 0x920515FB); }

// @0x1409e2630
int ASTooltip::FUN_1409e2630(int nId)
{
    if (nId == 0)
        return 0;
    return FUN_1409e26b0(FUN_1401a9d70()->FUN_141811980(9, nId));
}
namespace p5hook { MS2_REPLACE_METHOD(0x1409E2630, ASTooltip, FUN_1409e2630, 116, 0xE5467A3C); }

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
namespace p5hook { MS2_REPLACE_METHOD(0x1409E2750, ASTooltip, FUN_1409e2750, 1517, 0x92AA5002); }

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
namespace p5hook { MS2_REPLACE_METHOD(0x1409E2D50, ASTooltip, FUN_1409e2d50, 378, 0x856F2937); }

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
namespace p5hook { MS2_REPLACE(0x1409E3050, FUN_1409e3050, 314, 0x28431E15); }

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
namespace p5hook { MS2_REPLACE_METHOD(0x1409E3190, ASTooltip, FUN_1409e3190, 833, 0x2635AC39); }

// The option text of an item: the rows of every shown option kind (the pet constant options with their growth), each
// kind under its title (pet info tab).
// @0x1409e34e0
// MS2-FUNCTIONAL: written after part 1's FUN_1409c9170 loop; /Od temporaries differ
CStringW FUN_1409e34e0(MS2Ptr<CItem> spItem)
{
    if (!spItem)
        return CStringW(L"");
    if (spItem->FUN_140527840() == 0)
        return CStringW(L"");
    CItemStatus* pStatus = reinterpret_cast<CItemStatus*>(spItem->FUN_1405278a0());
    if (pStatus == 0)
        return CStringW(L"");
    MS2Ptr<CItemOption> spOption(pStatus->m_spOption);
    if (spOption.IsNull())
        return CStringW(L"");
    FUN_1409e5480();
    CStringW strKinds[5] = { L"" };
    CStringW strText;
    int bPet = spItem->FUN_140525640();
    MS2Ptr<CPetData> spPet(0);
    if (bPet != 0)
        spPet = FUN_14052d210()->Find(spItem->FUN_140527840()->FUN_14053dc60());
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
        size_t nTexts = mapTexts.GetCount();
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
                        nValue = (int)((float)nValue + fRate * (float)(spItem->FUN_140528c20() - 1));
                        strValue = FUN_140631830(eSpecial, nValue, spItem->FUN_140527840());
                        int nRaw = spBase->FUN_140266e30();
                        strBase = StringFormat(L"{0:0.1f}", nRaw);
                        strMax = StringFormat(L"{0:0.1f}", fMax);
                        strRate = StringFormat(L"{0:0.1f}", fRate);
                    }
                    if (FUN_1409c56f0(strRow, spItem, eSpecial, nKind, spBase, strValue))
                    {
                        strKind.Append(strRow);
                        strKind.Append(FUN_14028dfa0(CStringW(L"s_tooltip_itemoption_stat_row_pet_constant_desc"), strBase, strMax, strRate));
                    }
                }
                else
                {
                    strValue = FUN_140631830(eSpecial, spBase->FUN_140266e30(), spItem->FUN_140527840());
                    if (FUN_1409c56f0(strRow, spItem, eSpecial, nKind, spBase, strValue))
                        strKind.Append(strRow);
                }
            }
            else
            {
                Unk_EnchantMap::CPair* pPair = mapStats.Lookup(nStat);
                if (pPair == 0)
                    continue;
                Unk_EnchantPtr<BaseOption> spBase(pPair->m_value);
                if (!spBase)
                    continue;
                if (i == 0 && spItem->FUN_140527840()->FUN_14053f750(nStat))
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
                        __int64 nValue = spBase->FUN_140266e30();
                        float fRate = (float)floor((double)FUN_140632990(nValue, spPet->m_fConstantOptionFactor));
                        float fBase = (float)nValue;
                        __int64 nMax = (__int64)(fBase + fRate * (float)(int)(*FUN_1401d3200()->PetMaxLevel.Get() - 1));
                        nValue = (__int64)((float)nValue + fRate * (float)(spItem->FUN_140528c20() - 1));
                        strValue = FUN_140631720(nStat, (int)nValue, false);
                        strBase = FUN_1409e0900(spBase->FUN_140266e30());
                        strMax = FUN_1409e0900((int)nMax);
                        strRate = FUN_1409e0900((int)fRate);
                    }
                    if (FUN_1409c5210(strRow, spItem, nStat, nKind, spBase, strValue))
                    {
                        strKind.Append(strRow);
                        strKind.Append(FUN_14028dfa0(CStringW(L"s_tooltip_itemoption_stat_row_pet_constant_desc"), strBase, strMax, strRate));
                    }
                }
                else
                {
                    strValue = FUN_140631600(nStat, spBase.get());
                    if (FUN_1409c5210(strRow, spItem, nStat, nKind, spBase, strValue))
                        strKind.Append(strRow);
                }
            }
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
        strText.Append(StringFormat(FUN_1409e6010((int)k, spItem.get()), strKind));
    }
    return strText;
}
namespace p5hook { MS2_REPLACE(0x1409E34E0, FUN_1409e34e0, 5142, 0x1005618E); }

// The random option rows of an item (option kind 2) in the compact layout; *pBest when any row has the best roll.
// @0x1409e4950
// MS2-FUNCTIONAL: /Od frame is 0x10 larger and the temporaries are placed differently; same calls and control flow
void FUN_1409e4950(MS2Ptr<CItem> spItem, CStringW& strOut, bool* pBest)
{
    *pBest = false;
    if (!spItem)
        return;
    MS2Ptr<CItemData> spData(spItem->FUN_140527840());
    if (!spData)
        return;
    CItemStatus* pStatus = reinterpret_cast<CItemStatus*>(spItem->FUN_1405278a0());
    if (pStatus == 0)
        return;
    MS2Ptr<CItemOption> spOption(pStatus->m_spOption);
    if (spOption.IsNull())
        return;
    FUN_1409e5480();
    CStringW strText;
    int bPet = spItem->FUN_140525640();
    Unk_EnchantMap& mapStats = spOption->FUN_1405cb8a0(2);
    Unk_SocketSpecialMap& mapSpecials = spOption->FUN_1405cb8d0(2);
    {
        Unk_OptionTextMap mapTexts(10);
        if (bPet == 0)
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
            spOption->FUN_1405cb900(2, mapTexts);
        }
        int nRow = 0;
        size_t nTexts = mapTexts.GetCount();
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
                if (FUN_140166430()->FUN_1405f6a90(spItem, pPair->m_key, 2, spBase->FUN_140266e30()) == true)
                    *pBest = true;
                CStringW strValue = FUN_140631830(eSpecial, spBase->FUN_140266e30(), spItem->FUN_140527840());
                CStringW strRow;
                if (FUN_1409c56f0(strRow, spItem, eSpecial, 2, spBase, strValue))
                    strText.Append(strRow);
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
                if (FUN_140166430()->FUN_1405f67e0(spItem, nStat, 2, spBase->FUN_140266e30()) == true)
                    *pBest = true;
                CStringW strValue = FUN_140631600(nStat, spBase.get());
                CStringW strRow;
                if (FUN_1409c5210(strRow, spItem, nStat, 2, spBase, strValue))
                    strText.Append(strRow);
                nRow++;
            }
        }
    }
    CStringW strSeparator(s_wsText0xbf5);
    if (!FUN_1409e5450(2) && !strText.IsEmpty())
    {
        CStringW strKey(L"s_tooltip_itemoption_kinds_random_nohead");
        strOut = StringFormat((const wchar_t*)FUN_14028b8e0(strKey), strText);
    }
}
namespace p5hook { MS2_REPLACE(0x1409E4950, FUN_1409e4950, 2417, 0xFE9700B0); }

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
namespace p5hook { MS2_REPLACE(0x1409E5320, FUN_1409e5320, 284, 0xCE0B0243); }

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

// The trade / bind / move limit lines of an item, joined with strSeparator.
// @0x1409e6120
// MS2-FUNCTIONAL: the bind-type switch block layout (key temporaries / case order) differs; same calls and results
CStringW FUN_1409e6120(CItem* pItem, int nTradeable, int nPersonal, int nBindable, int nBindOnGet, const CStringW& strSeparator, int nCount, CStringW strBindName, int nRemainOnly)
{
    CStringW strText;
    if (nRemainOnly != 0)
        strText = FUN_1408116a0(0x525, nCount);
    else if (nTradeable == 1 && nCount > 0)
    {
        if (nPersonal != 0)
            strText = FUN_1408116a0(0x523, nCount);
        else
            strText = FUN_1408116a0(0x524, nCount);
    }
    else if (nPersonal == 0 && nTradeable == 0)
        strText = FUN_14028de60(0x520);
    else if (nPersonal == 0)
        strText = FUN_14028de60(0x51e);
    else if (nTradeable == 0)
        strText = FUN_14028de60(0x51f);
    if (nBindable == 1)
    {
        if (nBindOnGet == 1)
        {
            if (!strText.IsEmpty())
                strText += strSeparator;
            strText += FUN_14052bd00(0x527, strBindName);
        }
        else
        {
            CStringW strBind = BlockFormat(0x526);
            switch (pItem->FUN_140527840()->limit.transferType)
            {
            case 2:
            {
                CStringW strKey(L"s_word_item_limit_bind_get");
                strBind = FUN_14028b8e0(strKey);
                break;
            }
            case 3:
            case 4:
                if (pItem->FUN_140527840()->FUN_14053cc40())
                {
                    CStringW strKey(L"s_word_item_limit_bind_pet");
                    strBind = FUN_14028b8e0(strKey);
                }
                else if (pItem->FUN_140527840()->FUN_14053cbc0())
                {
                    CStringW strKey(L"s_word_item_limit_bind_equip");
                    strBind = FUN_14028b8e0(strKey);
                }
                else
                {
                    CStringW strKey(L"s_word_item_limit_bind_use");
                    strBind = FUN_14028b8e0(strKey);
                }
                break;
            }
            if (!strText.IsEmpty())
                strText += strSeparator;
            strText += strBind;
        }
    }
    if (FUN_140166410_p5()->FUN_14036d570(0xcf))
    {
        if (pItem->FUN_140527840()->FUN_14053e8e0())
        {
            if (!strText.IsEmpty())
                strText += strSeparator;
            if (pItem->FUN_14052a480() != 0)
                strText += FUN_14028dfa0(CStringW(L"s_word_item_limit_moveDisable_store_in"), pItem->FUN_14052a4f0());
            else
            {
                CStringW strKey(L"s_word_item_limit_moveDisable");
                strText += FUN_14028b8e0(strKey);
            }
        }
    }
    return strText;
}
namespace p5hook { MS2_REPLACE(0x1409E6120, FUN_1409e6120, 1901, 0x31228E7E); }

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
        if (!FUN_1402226b0(nJobId))
            continue;
        if (nJobId == 1)
            nAllowed = 1;
        if (nJobId == nJob)
            nAllowed = 1;
        CStringW strName = FUN_1401a9d70_p5()->FUN_141811980(0x4d, nJobId);
        if (!strList.IsEmpty())
            strList.Append(StringFormat(L", {0}", strName));
        else
            strList.Append(strName);
    }
    if (strList.GetLength() > 0)
        strOut = FUN_14028dfa0(CStringW(L"s_word_enable_jobs"), strList);
}
namespace p5hook { MS2_REPLACE(0x1409E68A0, FUN_1409e68a0, 503, 0xAA7F5742); }

// The "disabled jobs" line (tests the output string's length, not the list's, as the exe does).
// @0x1409e6aa0
void FUN_1409e6aa0(int nJob, ATL::CAtlArray<unsigned>& jobs, CStringW& strOut)
{
    CStringW strList;
    for (unsigned i = 0; i < jobs.GetCount(); i++)
    {
        int nJobId = jobs[i];
        if (!FUN_1402226b0(nJobId))
            continue;
        CStringW strName = FUN_1401a9d70_p5()->FUN_141811980(0x4d, FUN_1401d7a50_p5()->GetSubJob1(nJobId));
        if (!strList.IsEmpty())
            strList.Append(StringFormat(L", {0}", strName));
        else
            strList.Append(strName);
    }
    if (strOut.GetLength() > 0)
        strOut = FUN_14028dfa0(CStringW(L"s_word_disable_jobs"), strList);
}
namespace p5hook { MS2_REPLACE(0x1409E6AA0, FUN_1409e6aa0, 461, 0xD970B87F); }

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
namespace p5hook { MS2_REPLACE(0x1409E6C80, FUN_1409e6c80, 112, 0xBBCD868C); }

// The required weapons line; nAllowed is set when the equipped right or left hand weapon kind is listed.
// @0x1409e6d00
void FUN_1409e6d00(int nRight, int nLeft, ATL::CAtlArray<Unk_SkillWeapon>& weapons, int& nAllowed, CStringW& strOut)
{
    CStringW strSep(L"");
    for (unsigned i = 0; i < weapons.GetCount(); i++)
    {
        Unk_SkillWeapon& weapon = weapons[i];
        if (weapon.m_nRightHand == nRight || weapon.m_nLeftHand == nLeft)
            nAllowed = 1;
        if (weapon.m_nRightHand != 0)
        {
            strOut += strSep + FUN_1401a9d70_p5()->FUN_141811980(8, weapon.m_nRightHand);
            strSep = L", ";
        }
        if (weapon.m_nLeftHand != 0)
        {
            strOut += strSep + FUN_1401a9d70_p5()->FUN_141811980(8, weapon.m_nLeftHand);
            strSep = L", ";
        }
    }
    if (strOut.GetLength() > 0)
    {
        CStringW strText = StringFormat((const wchar_t*)FUN_14028de60(0x584), strOut);
        strOut = strText;
    }
}
namespace p5hook { MS2_REPLACE(0x1409E6D00, FUN_1409e6d00, 695, 0xCA3426ED); }

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
namespace p5hook { MS2_REPLACE(0x1409E6FC0, FUN_1409e6fc0, 118, 0xD6007B33); }

// Appends the trophy requirements (id + grade) the player has not reached; true when any.
// @0x1409e7080
bool FUN_1409e7080(const ATL::CAtlArray<unsigned long>& ids, const ATL::CAtlArray<int>& grades, CStringW& strOut)
{
    for (unsigned i = 0; i < ids.GetCount(); i++)
    {
        int nId = ids[i];
        MS2Ptr<CAchieveData> spData = GetAchieveData(nId);
        if (!spData)
            continue;
        int nGrade = FUN_1409e8500(grades, i, spData->m_nMaxGrade);
        MS2Ptr<CAchieveGradeData> spGrade = spData->GetGrade(nGrade);
        if (!spGrade)
            continue;
        if (FUN_140936640(FUN_1406c7600(), nId, nGrade) != 0)
            continue;
        if (!strOut.IsEmpty())
            strOut.Append(L"\n");
        CStringW strLine = FUN_14093bd40(nId, nGrade, CStringW(L""));
        strOut += strLine;
    }
    return !strOut.IsEmpty();
}
namespace p5hook { MS2_REPLACE(0x1409E7080, FUN_1409e7080, 530, 0xA5E61942); }

// Fills the itemPackageList rows (one row per drop result).
// @0x1409e72a0
void ASTooltip::FUN_1409e72a0(const std::vector<ItemDropResult>* pResults)
{
    if (pResults->empty())
        return;
    ASArray rows(2);
    for (std::vector<ItemDropResult>::const_iterator it = pResults->begin(); it != pResults->end(); ++it)
    {
        ItemDropResult* pDrop = const_cast<ItemDropResult*>(&*it);
        ASObj row(2);
        if (!row.FUN_1409c5bd0(pDrop))
            continue;
        rows.FUN_1422bc050(row.FUN_1422bb870());
    }
    FUN_1409adbe0(s_strItemPackageList, rows.FUN_1422bb870());
    CString strKind("export_common_tooltip_kindsItemPackage");
    FUN_1409c6d70(strKind);
}
namespace p5hook { MS2_REPLACE_METHOD(0x1409E72A0, ASTooltip, FUN_1409e72a0, 431, 0x99FCA1A4); }

// Fills the itemBreakIngredientList rows (the ingredients with a count that are not plain materials).
// @0x1409e7460
// MS2-FUNCTIONAL: the exe iterates the ingredients as std::vector<MS2Ptr<CIngredientInfo>> const_iterators (Unk_IngVec has no typed iterator) and passes a temporary ItemDropResult
void ASTooltip::FUN_1409e7460(Unk_IngVec* pIngredients)
{
    if (!pIngredients->FUN_14028a8c0())
    {
        ASArray rows(2);
        for (size_t i = 0; i < pIngredients->FUN_14028b500(); i++)
        {
            Unk_IngRef spIng(*pIngredients->FUN_14027f1f0(i));
            if (spIng == 0)
                continue;
            if (spIng->m_c == 0)
                continue;
            MS2Ptr<CItemData> spData = FUN_14053f870(spIng->m_a);
            if (spData == 0)
                continue;
            if (!spData->FUN_14053d990() && !spData->FUN_14053d880() && spData->FUN_14053c5c0() != 0xf)
                continue;
            ASObj row(2);
            int nRank = FUN_14053feb0(spIng->m_a);
            bool bFilled;
            {
                ItemDropResult drop(spIng->m_a, spIng->m_c, nRank, 0, 0, 0, 0, false, false, 0, false, false, false, false);
                bFilled = row.FUN_1409c5bd0(&drop);
            }
            if (!bFilled)
                continue;
            rows.FUN_1422bc050(row.FUN_1422bb870());
        }
        FUN_1409adbe0(s_strItemBreakIngredientList, rows.FUN_1422bb870());
    }
}
namespace p5hook { MS2_REPLACE_METHOD(0x1409E7460, ASTooltip, FUN_1409e7460, 1043, 0xA27F316C); }

// The enablePreview hint ("preview" key binding text).
// @0x1409e7880
CStringW FUN_1409e7880()
{
    CStringW strKey = FUN_1409331f0()->FUN_14142d760(0x49406, 0);
    CStringW str = FUN_14028dfa0(CStringW(L"s_msg_tooltip_enable_preview"), strKey);
    return str;
}
namespace p5hook { MS2_REPLACE(0x1409E7880, FUN_1409e7880, 168, 0x057BF814); }

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
namespace p5hook { MS2_REPLACE(0x1409E7930, FUN_1409e7930, 259, 0x1A341905); }

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
namespace p5hook { MS2_REPLACE(0x1409E7A40, FUN_1409e7a40, 215, 0x3F3CBC7A); }
