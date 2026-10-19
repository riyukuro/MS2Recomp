// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIItemOptionCreateDialog (UI type 0x4ecd): the item option
// "create item" window. See uiitemoptioncreatedialog.h.
// MS2-UNIT: ?\uiitemoptioncreatedialog.cpp
// MS2-RANGE: 0x1400edd90-0x1400ede80 .text$di
// MS2-RANGE: 0x1412d2660-0x1412d5890 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0AEBV<lambda_7186e7be7a3596860ecf3da510e6b81d>@@X@?$_Func_impl_no_alloc@V<lambda_7186e7be7a3596860ecf3da510e6b81d>@@XPEAVItemOptionValueRandom@@@std@@QEAA@AEBV<lambda_7186e7be7a3596860ecf3da510e6b81d>@@@Z 0x1412d4550 ; prop
// MS2-PIN: ??$?0AEBV<lambda_a792bcd89ec462b6e9fc17d6447f68d5>@@X@?$_Func_impl_no_alloc@V<lambda_a792bcd89ec462b6e9fc17d6447f68d5>@@XPEAVItemOptionValue@@@std@@QEAA@AEBV<lambda_a792bcd89ec462b6e9fc17d6447f68d5>@@@Z 0x1412d45b0 ; prop
// MS2-PIN: ??$?0V<lambda_7186e7be7a3596860ecf3da510e6b81d>@@X@?$_Func_impl_no_alloc@V<lambda_7186e7be7a3596860ecf3da510e6b81d>@@XPEAVItemOptionValueRandom@@@std@@QEAA@$$QEAV<lambda_7186e7be7a3596860ecf3da510e6b81d>@@@Z 0x1412d4610 ; unique
// MS2-PIN: ??$?0V<lambda_7186e7be7a3596860ecf3da510e6b81d>@@X@?$function@$$A6AXPEAVItemOptionValueRandom@@@Z@std@@QEAA@V<lambda_7186e7be7a3596860ecf3da510e6b81d>@@@Z 0x1412d4670 ; prop
// MS2-PIN: ??$?0V<lambda_a792bcd89ec462b6e9fc17d6447f68d5>@@X@?$_Func_impl_no_alloc@V<lambda_a792bcd89ec462b6e9fc17d6447f68d5>@@XPEAVItemOptionValue@@@std@@QEAA@$$QEAV<lambda_a792bcd89ec462b6e9fc17d6447f68d5>@@@Z 0x1412d46c0 ; unique
// MS2-PIN: ??$?0V<lambda_a792bcd89ec462b6e9fc17d6447f68d5>@@X@?$function@$$A6AXPEAVItemOptionValue@@@Z@std@@QEAA@V<lambda_a792bcd89ec462b6e9fc17d6447f68d5>@@@Z 0x1412d4720 ; prop
// MS2-PIN: ??0<lambda_7186e7be7a3596860ecf3da510e6b81d>@@QEAA@QEAVUIItemOptionCreateDialog@@AEAV?$MS2Ptr@VASUIComponent@@@@@Z 0x1412d4e20 ; order
// MS2-PIN: ??0<lambda_a792bcd89ec462b6e9fc17d6447f68d5>@@QEAA@QEAVUIItemOptionCreateDialog@@AEAV?$MS2Ptr@VASUIComponent@@@@@Z 0x1412d4e50 ; order
// MS2-PIN: ??0CCCreateItemPacket@@QEAA@XZ 0x1412d4ee0 ; unique
// MS2-PIN: ??1CCCreateItemPacket@@QEAA@XZ 0x1412d4ff0 ; unique
// MS2-PIN: ??_GUIItemOptionCreateDialog@@UEAAPEAXI@Z 0x1412d5510 ; unique
// MS2-PIN: ?_Clone@?$_Func_impl_no_alloc@V<lambda_7186e7be7a3596860ecf3da510e6b81d>@@XPEAVItemOptionValueRandom@@@std@@AEBAPEAV?$_Func_base@XPEAVItemOptionValueRandom@@@2@PEAXU?$integral_constant@_N$0A@@2@@Z 0x1412d5590 ; prop
// MS2-PIN: ?_Clone@?$_Func_impl_no_alloc@V<lambda_a792bcd89ec462b6e9fc17d6447f68d5>@@XPEAVItemOptionValue@@@std@@AEBAPEAV?$_Func_base@XPEAVItemOptionValue@@@2@PEAXU?$integral_constant@_N$0A@@2@@Z 0x1412d55e0 ; prop
// MS2-PIN: ?_Copy@?$_Func_impl_no_alloc@V<lambda_7186e7be7a3596860ecf3da510e6b81d>@@XPEAVItemOptionValueRandom@@@std@@EEBAPEAV?$_Func_base@XPEAVItemOptionValueRandom@@@2@PEAX@Z 0x1412d5630 ; prop
// MS2-PIN: ?_Copy@?$_Func_impl_no_alloc@V<lambda_a792bcd89ec462b6e9fc17d6447f68d5>@@XPEAVItemOptionValue@@@std@@EEBAPEAV?$_Func_base@XPEAVItemOptionValue@@@2@PEAX@Z 0x1412d5660 ; prop
// MS2-PIN: ?_Delete_this@?$_Func_impl_no_alloc@V<lambda_7186e7be7a3596860ecf3da510e6b81d>@@XPEAVItemOptionValueRandom@@@std@@EEAAX_N@Z 0x1412d5690 ; order
// MS2-PIN: ?_Delete_this@?$_Func_impl_no_alloc@V<lambda_a792bcd89ec462b6e9fc17d6447f68d5>@@XPEAVItemOptionValue@@@std@@EEAAX_N@Z 0x1412d56d0 ; order
// MS2-PIN: ?_Get@?$_Func_impl_no_alloc@V<lambda_a792bcd89ec462b6e9fc17d6447f68d5>@@XPEAVItemOptionValue@@@std@@EEBAPEBXXZ 0x1412d5790 ; prop
// MS2-PIN: ?_Move@?$_Func_impl_no_alloc@V<lambda_7186e7be7a3596860ecf3da510e6b81d>@@XPEAVItemOptionValueRandom@@@std@@EEAAPEAV?$_Func_base@XPEAVItemOptionValueRandom@@@2@PEAX@Z 0x1412d57d0 ; prop
// MS2-PIN: ?_Move@?$_Func_impl_no_alloc@V<lambda_a792bcd89ec462b6e9fc17d6447f68d5>@@XPEAVItemOptionValue@@@std@@EEAAPEAV?$_Func_base@XPEAVItemOptionValue@@@2@PEAX@Z 0x1412d5820 ; prop
// MS2-PIN: ?_Target_type@?$_Func_impl_no_alloc@V<lambda_7186e7be7a3596860ecf3da510e6b81d>@@XPEAVItemOptionValueRandom@@@std@@EEBAAEBVtype_info@@XZ 0x1412d5870 ; order
// MS2-PIN: ?_Target_type@?$_Func_impl_no_alloc@V<lambda_a792bcd89ec462b6e9fc17d6447f68d5>@@XPEAVItemOptionValue@@@std@@EEBAAEBVtype_info@@XZ 0x1412d5880 ; order
// MS2-PINS-END tplpin
// MS2-PIN: ??1UIItemOptionCreateDialog@@UEAA@XZ 0x1412d5060 ; the exe dtor has no vptr store (implicit)
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiitemoptioncreatedialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uiitemoptioncreatedialog.h"

#include <functional>
#include <utility>
#include <vector>

#include "ms2/commonfiles/citemoptiontable.h"
#include "ms2/commonfiles/itemdata.h"
#include "ms2/commonfiles/itemoptiondata.h"
#include "ms2/gfxui/uiswfentity.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/cccreateitempacket.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/ms2ptr_impl.h"

// The seven sort names of the shared header (this unit has no skill / stun statics), then the key input controller.
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};   // @0x1400edd90
#ifndef MS2_HOOK_DLL
static UICommon::CMyPCKeyInputController s_keyInputController;                          // @0x1400ede50
#endif

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of exe objects ----

// The item table the list is filled from.
class Unk_OcItemTable
{
public:
    void FUN_1405594b0(std::vector<unsigned>& vIds);        // every item id of the table
};
Unk_OcItemTable* FUN_140281980();

// The input state (key presses of the frame).
class Unk_OcInputState
{
public:
    bool FUN_14116d9c0(int nKey, int a, int b);             // the key was pressed
};
Unk_OcInputState* FUN_14025e7c0();

// The AS list controls of the movie ("m_itemGrade" combo, "m_items" list) and the search input.
class Unk_PsCombo : public AScript
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);
    void FUN_1422dfc10();                                   // remove all rows
    int FUN_1422dfb90();                                    // row count
    void FUN_1422dfc70(const ASObj& row);                   // append a row
    void FUN_1422df5f0(unsigned nRows);                     // visible rows
    void FUN_1422df690(int nRow);                           // select a row
};
class Unk_AcList : public AScript
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);
    void FUN_1422dd1d0();                                   // clear
    void FUN_1422dcca0(int nSelected);                      // select a row
    void FUN_1422dd230(const ASObj& row);                   // append a row
};
class Unk_CoupleInput : public AScript
{
public:
    CStringW FUN_1422e0b00();                               // the text
};

// The string table (item rank names, item names).
class Unk_OcStringTable
{
public:
    CStringW FUN_141813150(int nId);                        // text of a rank
    CStringW FUN_141811980(int nTable, unsigned nId);       // text of an item
};
Unk_OcStringTable* FUN_1401a9d70();

MS2Ptr<CItemData> FUN_14053f870(unsigned nItemId);          // the item row (NULL: no such item)
CItemOptionTable* FUN_140166430();
int FUN_1405451c0(const CString& strGroup);                 // the item group index of a group name
const CString& FUN_14082efb0(int nStat);                    // text of a stat
CStringW FUN_14082f000(int nStat);                          // text of a stat (wide)
CStringW FUN_140630e10(int nSpecial);                       // text of a special ability
int FUN_1409c17e0(const Scaleform::GFx::Value& v);          // value as an integer
int FUN_1409c1750(const Scaleform::GFx::Value& v);          // value as an integer
const char* FUN_140b63540(const Scaleform::GFx::Value& v);  // value as a string
bool FUN_140ebaf70(const Scaleform::GFx::Value* pArray, unsigned nIndex, Scaleform::GFx::Value* pOut);   // array element
unsigned FUN_1412d5550(const Scaleform::GFx::Value& v);     // array size (inline COMDAT)
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
void FUN_1422bcd10(Scaleform::GFx::Value* pValue, int n);
void FUN_1422bce70(Scaleform::GFx::Value* pValue, const char* sz);
void FUN_1407cd930(Scaleform::GFx::Value* pObject, const char* szName, const Scaleform::GFx::Value& v);   // set a member
void FUN_140710590(COutPacket& packet);                     // send

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x1412d2660
UIItemOptionCreateDialog::UIItemOptionCreateDialog()
    : m_nItemId(0), m_nRank(0)
{
    m_40 = 1;
    FUN_1422dc3b0(1);
}

// @0x1412d2700
CString UIItemOptionCreateDialog::vfunc_1()
{
    return "ItemOptionCreateDialog";
}

// @0x1412d2750
void UIItemOptionCreateDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    if (m_ids.empty()) {
        FUN_140281980()->FUN_1405594b0(m_ids);
        m_nItemId = 0;
        m_nRank = 1;
    }
}

// @0x1412d27d0
int UIItemOptionCreateDialog::vfunc_13()
{
    if (UIDialog::vfunc_13() == 0) {
        if (FUN_14025e7c0()->FUN_14116d9c0(0x1c, 0, 0) == 0) {
            if (FUN_14025e7c0()->FUN_14116d9c0(0xf, 0, 0) == 0)
                return 0;
            if (m_30.get() != 0)
                m_30->Invoke("onTabKey");
            return 1;
        }
        MS2Ptr<Unk_CoupleInput> input = FUN_140e35bd0("m_searchInput");
        if (input) {
            FUN_1412d3c10("", input->FUN_1422e0b00());
        }
        return 1;
    }
    return 1;
}

// @0x1412d2980
int UIItemOptionCreateDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    UIDialog::vfunc_28(szMethod, pArgs, nArgs);
    ASData data;
    if (_stricmp("OnItemChange", szMethod) == 0) {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0) {
            m_nItemId = data.FUN_1422b8b10();
            m_nRank = data.FUN_1422b8b10();
            FUN_1412d33b0();
            FUN_1412d3740();
            FUN_1412d3a60();
        }
        return 1;
    } else if (_stricmp("OnItemRank", szMethod) == 0) {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0) {
            data.FUN_1422b8b10();
            m_nRank = data.FUN_1422b8b10();
            FUN_1412d3740();
            FUN_1412d3a60();
        }
        return 1;
    } else if (_stricmp("OnGroupChange", szMethod) == 0) {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0) {
            FUN_1412d3c10(data.FUN_1422b8d30(), L"");
        }
        return 1;
    } else if (_stricmp("OnCreateItem", szMethod) == 0) {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0) {
            int a = data.FUN_1422b8b10();
            int b = data.FUN_1422b8b10();
            int c = data.FUN_1422b8b10();
            int d = data.FUN_1422b8b10();
            FUN_1412d2e50(a, b, c, d, data.FUN_1422b9260());
        }
        return 1;
    } else if (_stricmp("OnSearchItem", szMethod) == 0) {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0) {
            FUN_1412d3c10("", data.FUN_1422b8f40());
        }
        return 1;
    } else if (_stricmp("OnOptionInit", szMethod) == 0) {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0) {
            m_nItemId = data.FUN_1422b8b10();
            m_nRank = data.FUN_1422b8b10();
            FUN_1412d3a60();
        }
        return 1;
    }
    return 0;
}

// "OnCreateItem": the packet carries the item, the count and the stat / special ability rows the user typed in.
// @0x1412d2e50
void UIItemOptionCreateDialog::FUN_1412d2e50(unsigned nItemId, unsigned nCount, int nParam, int nParam2, const Scaleform::GFx::Value& options)
{
    MS2Ptr<CItemData> item = FUN_14053f870(nItemId);
    if (!item)
        return;
    unsigned nWanted = nCount;
    if (item->FUN_14053cbc0())
        nWanted = 1;
    CCCreateItemPacket packet;
    packet.a = nItemId;
    packet.b = nWanted < 2 ? 1 : nWanted;
    packet.c = nParam;
    packet.d = 0;
    packet.e = nParam2;
    for (unsigned i = 0; i < FUN_1412d5550(options); ++i) {
        Scaleform::GFx::Value elem;
        if (FUN_140ebaf70(&options, i, &elem) == 0)
            continue;
        ASObj row(elem, 2);
        Scaleform::GFx::Value vKinds = row.FUN_1422baa20("kinds");
        Scaleform::GFx::Value vType = row.FUN_1422baa20("type");
        Scaleform::GFx::Value vIndex = row.FUN_1422baa20("index");
        Scaleform::GFx::Value vValue = row.FUN_1422baa20("value");
        int nKind = FUN_1409c17e0(vKinds);
        if (nKind < 0)
            continue;
        if (nKind < 5) {
            if (_stricmp("stat", FUN_140b63540(vType)) == 0) {
                Unk_PacketOptionA key = (Unk_PacketOptionA)FUN_1409c17e0(vIndex);
                Unk_PayloadPtr<BaseOption> option = new BaseOption;
                int nValue = FUN_1409c1750(vValue);
                option->FUN_140266e90(nValue);
                packet.optionsA[nKind].SetAt(key, option);
            } else if (_stricmp("specialAbility", FUN_140b63540(vType)) == 0) {
                Unk_PacketOptionB key = (Unk_PacketOptionB)FUN_1409c17e0(vIndex);
                Unk_PayloadPtr<BaseOption> option = new BaseOption;
                int nValue = FUN_1409c1750(vValue);
                option->FUN_140266e90(nValue);
                packet.optionsB[nKind].SetAt(key, option);
            }
        }
    }
    COutPacket out(0x15, 0);
    packet.vfunc_0(out);
    FUN_140710590(out);
}

// Fill the rank combo with the ranks of the picked item.
// @0x1412d33b0
void UIItemOptionCreateDialog::FUN_1412d33b0()
{
    MS2Ptr<Unk_PsCombo> combo = FUN_140c28560("m_itemGrade");
    if (combo.get() == 0)
        return;
    combo->FUN_1422dfc10();
    MS2Ptr<CItemData> item = FUN_14053f870(m_nItemId);
    if (item == 0)
        return;
    int nSelected = 0;
    if (item->FUN_14053c5a0() == 0) {
        for (int nRank = 1; nRank < 7; ++nRank) {
            ASObj row(2);
            row.FUN_1407cbb20("label", FUN_1401a9d70()->FUN_141813150(nRank));
            row.FUN_1407cb9c0("itemRank", nRank);
            if (nRank == m_nRank)
                nSelected = combo->FUN_1422dfb90();
            combo->FUN_1422dfc70(row);
        }
    } else {
        ASObj row(2);
        row.FUN_1407cbb20("label", FUN_1401a9d70()->FUN_141813150(item->FUN_14053c5a0()));
        row.FUN_1409adc90("itemRank", item->FUN_14053c5a0());
        combo->FUN_1422dfc70(row);
        nSelected = 0;
        m_nRank = item->FUN_14053c5a0();
    }
    unsigned nRows = combo->FUN_1422dfb90();
    if (nRows < 2)
        nRows = 1;
    combo->FUN_1422df5f0(nRows);
    combo->FUN_1422df690(nSelected);
    combo->vfunc_24(true);
}

// The unit's two row builders and the AS member setters used by the callbacks below.
// @0x1412d4400
static void FUN_1412d4400(ASObj& obj, int nStat)
{
    if (nStat == 0x1b || nStat == 0x1c) {
        obj.FUN_1407cba60("label", FUN_14082efb0(nStat));
    } else {
        obj.FUN_1407cbb20("label", FUN_14082f000(nStat));
    }
    obj.FUN_1409c0dc0("type", "stat");
    obj.FUN_1412d49a0("index", nStat);
}

// @0x1412d44d0
static void FUN_1412d44d0(ASObj& obj, int nSpecial)
{
    obj.FUN_1407cbb20("label", FUN_140630e10(nSpecial));
    obj.FUN_1409c0dc0("type", "specialAbility");
    obj.FUN_1412d4900("index", nSpecial);
}

// Fill the random option table of the picked item / rank.
// @0x1412d3740
void UIItemOptionCreateDialog::FUN_1412d3740()
{
    MS2Ptr<CItemData> item = FUN_14053f870(m_nItemId);
    if (item == 0)
        return;
    MS2Ptr<ASUIComponent> sheet = FUN_140c02990("m_optionSheet");
    if (sheet == 0)
        return;
    sheet->Invoke("resetTable");
    MS2Ptr<ASUIComponent> table = sheet->FUN_140accfb0<ASUIComponent>("m_tableRandom");
    if (table == 0)
        return;
    MS2Ptr<ItemOptionRandom> random = FUN_140166430()->FUN_1405f6010(item->FUN_14053eff0(m_nRank));
    if (random == 0)
        return;
    int nRows = random->FUN_1405d5fe0(m_nRank);
    table->Invoke("initTable", nRows, nRows, "Random", 2);
    if (nRows != 0) {
        std::function<void(ItemOptionValueRandom*)> fn = [this, &table](ItemOptionValueRandom* pValue) {
            ASObj column(2);
            ASObj label(2);
            if (pValue->FUN_1405d2790() == 0) {
                FUN_1412d4400(label, pValue->FUN_1405d2750());
                std::pair<int, int> range = FUN_140166430()->FUN_1405f64e0(m_nItemId, m_nRank, pValue->FUN_1405d2750());
                column.FUN_1407cb9c0("minV", range.first);
                column.FUN_1407cb9c0("maxV", range.second);
                column.FUN_1407cb9c0("value", range.second);
            } else if (pValue->FUN_1405d2790() == 1) {
                FUN_1412d44d0(label, pValue->FUN_1405d2770());
                std::pair<int, int> range = FUN_140166430()->FUN_1405f6650(m_nItemId, m_nRank, pValue->FUN_1405d2770());
                column.FUN_1407cb9c0("minV", range.first);
                column.FUN_1407cb9c0("maxV", range.second);
                column.FUN_1407cb9c0("value", range.second);
            }
            column.FUN_1409adbe0("optionName", label.FUN_1422bb870());
            table->Invoke("createOptionColumn", column.FUN_1422bb870());
        };
        random->FUN_1405d75d0(fn);
    }
}

// Fill the constant option result of the picked item / rank.
// @0x1412d3a60
void UIItemOptionCreateDialog::FUN_1412d3a60()
{
    MS2Ptr<CItemData> item = FUN_14053f870(m_nItemId);
    if (item == 0)
        return;
    MS2Ptr<ASUIComponent> result = FUN_140c02990("m_optionResult");
    if (result == 0)
        return;
    MS2Ptr<ItemOptionConstant> constant = FUN_140166430()->FUN_1405f5ee0(item->FUN_14053efd0(), m_nRank);
    if (constant.get() != 0) {
        std::function<void(ItemOptionValue*)> fn = [this, &result](ItemOptionValue* pValue) {
            ASObj row(2);
            row.FUN_1412d4860("kinds", 0);
            if (pValue->FUN_1405ce470() == 0) {
                FUN_1412d4400(row, pValue->FUN_1405ce370());
            } else if (pValue->FUN_1405ce470() == 1) {
                FUN_1412d44d0(row, pValue->FUN_1405ce390());
            }
            int nValue = pValue->vfunc_1(m_nItemId, m_nRank);
            if (nValue != 0) {
                row.FUN_1407cb9c0("value", nValue);
                result->Invoke("appendOption", row.FUN_1422bb870());
            }
        };
        constant->FUN_1405d33e0(fn);
    }
}

// Fill the item list with the items of the group / search text.
// @0x1412d3c10
void UIItemOptionCreateDialog::FUN_1412d3c10(const CString& strGroup, const CStringW& strSearch)
{
    MS2Ptr<Unk_AcList> list = FUN_140c02900("m_items");
    if (!list)
        return;
    list->FUN_1422dd1d0();
    list->FUN_1422dcca0(-1);
    list->vfunc_24(true);
    for (size_t i = 0; i < m_ids.size(); ++i) {
        unsigned nId = m_ids[i];
        MS2Ptr<CItemData> item = FUN_14053f870(nId);
        if (!item) {
            continue;
        }
        CStringW strLabel;
        int nLevel = item->limit.levelLimit;
        CStringW strFormat(L"[%ld] [%s] [Lv.%d] %s");
        if (item->FUN_14053e130() == 0) {
            if (item->FUN_14053cf90() == 0) {
                strLabel.Format(strFormat, (unsigned __int64)nId, L"GAME", nLevel, (LPCWSTR)FUN_1401a9d70()->FUN_141811980(1, nId));
            } else {
                strLabel.Format(strFormat, (unsigned __int64)nId, L"SKIN", nLevel, (LPCWSTR)FUN_1401a9d70()->FUN_141811980(1, nId));
            }
        } else {
            strLabel.Format(strFormat, (unsigned __int64)nId, L"CASH", nLevel, (LPCWSTR)FUN_1401a9d70()->FUN_141811980(1, nId));
        }
        ASObj row(2);
        row.FUN_1407cbb20("label", strLabel);
        row.FUN_1409c0d20("itemId", nId);
        if (strSearch.IsEmpty()) {
            if (strGroup == "RHLH") {
                if (item->FUN_14053d460())
                    list->FUN_1422dd230(row);
            } else if (strGroup == "CLPA") {
                if (item->FUN_14053d2b0())
                    list->FUN_1422dd230(row);
            } else if (strGroup == "CONSUME") {
                if (item->FUN_14053c5c0() == 2 || item->FUN_14053c5c0() == 0x18)
                    list->FUN_1422dd230(row);
            } else if (strGroup == "ETC") {
                if (item->FUN_14053c5c0() == 4)
                    list->FUN_1422dd230(row);
            } else if (strGroup == "MISSION") {
                if (item->FUN_14053c5c0() == 3)
                    list->FUN_1422dd230(row);
            } else if (strGroup == "SKILL") {
                if (item->FUN_14053cb40())
                    list->FUN_1422dd230(row);
            } else if (strGroup == "INSTALL") {
                if (item->FUN_14053cb80())
                    list->FUN_1422dd230(row);
            } else {
                if (item->FUN_14053eba0()->FUN_14054b3d0() < 2) {
                    int nGroup = FUN_1405451c0(strGroup);
                    if (item->FUN_14053eba0()->FUN_14054b450(nGroup))
                        list->FUN_1422dd230(row);
                }
            }
        } else {
            if (strLabel.Find(strSearch, 0) == -1)
                continue;
            list->FUN_1422dd230(row);
        }
    }
    list->FUN_1422dcca0(0);
    list->vfunc_24(true);
}


// ---- inline COMDATs ----

// @0x1412d4770
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, int a1, int a2, const char* a3, int a4)
{
    ASArgList args;
    args.FUN_1409b2800(4);
    FUN_1422bcd10(args.FUN_1409b1f70(0), a1);
    FUN_1422bcd10(args.FUN_1409b1f70(1), a2);
    FUN_1422bce70(args.FUN_1409b1f70(2), a3);
    FUN_1422bccb0(args.FUN_1409b1f70(3), a4);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x1412d4860
inline void ASObj::FUN_1412d4860(const char* szName, int n)
{
    ASData data;
    data.FUN_1422b7f70(n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}

// @0x1412d4900
inline void ASObj::FUN_1412d4900(const char* szName, int n)
{
    ASData data;
    data.FUN_1422b7f70(n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}

// @0x1412d49a0
inline void ASObj::FUN_1412d49a0(const char* szName, int n)
{
    ASData data;
    data.FUN_1422b7f70(n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}
