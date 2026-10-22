// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIHomeResizeDialog: shrink / extend the area and height of the
// player's home.
// MS2-UNIT: ?\uihomeresizedialog.cpp
// MS2-RANGE: 0x140c2bc50-0x140c2dea0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uihomeresizedialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "uihomeresizedialog.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "ms2/commonfiles/masteryinteriortable.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/wcformat.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "hook/ms2hook.h"

MS2_EMIT_CRT_MEMMOVE_S();

// ---- unit-local views of exe types ----

class ASDialog : public ASDisplayObject {};

// The ugc home state of the player (the cube service): the current area and height step.
class Unk_HrHomeSvc
{
public:
    int FUN_1410c3470();                              // the area step
    int FUN_1410c34b0();                              // the height step
};
Unk_HrHomeSvc* FUN_1409670e0();

class Unk_HrOptions { public: bool FUN_14036d570(int nFeature); };      // the content switches
Unk_HrOptions* FUN_140166410();
class Unk_HrBlockFlags { public: int FUN_1402c4c90(int nFlag); };       // blocked-action flag set
struct Unk_HrConfig { char m_pad[8]; Unk_HrBlockFlags m_flags; };
Unk_HrConfig* FUN_14025e7b0();                                  // global client config

class Unk_HrTrophy { public: int FUN_140936640(int nWidth, int nLength); };     // trophy requirement check
Unk_HrTrophy* FUN_1406c7600();
CMasteryInteriorTable* FUN_140933200();

class Unk_HrWorld;
class Unk_HrPc;
Unk_HrWorld* FUN_1403ed2d0();
Unk_HrPc* FUN_141bd0cc0(Unk_HrWorld*);

int FUN_1418dd100();
CStringW FUN_1418fec00(int nType, __int64 nValue, int);         // money text by pay type
CStringW FUN_14093bad0(int nWidth, int nLength, CStringW strDefault);   // the trophy requirement text (empty: none)
CStringW FUN_1409e8970(CStringW strKey, const int& nA, const int& nB);
CStringW FUN_14062b4f0(CStringW strKey, const int* pnValue);   // string table text with one number
void FUN_141275260(int nStringId, int nA, int nB);
void FUN_1412751f0(const CStringW& strText, int nA, int nB);
CStringW FUN_14028b8e0(const CStringW& strKey);                 // string table text
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW strText, int nUnk, CStringW strTag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> spBox);
void FUN_140710590(COutPacket& pkt);

// The key-formatted texts with an int pair plus the price (and the trophy text): one COMDAT per argument-type list.
template CStringW FUN_14028dfa0<int, int, CStringW>(CStringW, const int&, const int&, const CStringW&);
template CStringW FUN_14028dfa0<int, int, CStringW, CStringW>(CStringW, const int&, const int&, const CStringW&, const CStringW&);

// @0x140c2bc50
UIHomeResizeDialog::UIHomeResizeDialog()
{
    m_80 = 1;
    m_88 = 1;
    m_58 = 1;
    FUN_141925e70(0, 1);
}

// @0x140c2bce0
UIHomeResizeDialog::~UIHomeResizeDialog() {}

// @0x140c2bd20
CString UIHomeResizeDialog::GetTypeName() { return "HomeResizeDialog"; }

// @0x140c2bd70
void UIHomeResizeDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    vfunc_84();
}

// @0x140c2bdb0
void UIHomeResizeDialog::vfunc_43()
{
    if (m_60 == 0 && m_78 != 0)
        return;
    {
        ASDialog* dialog = dynamic_cast<ASDialog*>((AScript*)m_30);
        if (dialog != 0)
            dialog->vfunc_2(5, 0, FUN_1418dd100());
    }
}

// @0x140c2be50
int UIHomeResizeDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("OnShrinkArea", szMethod) == 0) {
        OnShrinkArea();
        return 1;
    } else if (_stricmp("OnShrinkHeight", szMethod) == 0) {
        OnShrinkHeight();
        return 1;
    } else if (_stricmp("OnExtensionArea", szMethod) == 0) {
        OnExtensionArea();
        return 1;
    } else if (_stricmp("OnExtensionHeight", szMethod) == 0) {
        OnExtensionHeight();
        return 1;
    }
    return 0;
}

// @0x140c2bf40
void UIHomeResizeDialog::FUN_140c2bf40() { vfunc_84(); }

// @0x140c2bf70
void UIHomeResizeDialog::FUN_140c2bf70() { vfunc_84(); }

// @0x140c2bfa0
// MS2-FUNCTIONAL: frame slot order of the MS2Ptr/CStringW temporaries differs from the exe
void UIHomeResizeDialog::OnShrinkArea()
{
    if (FUN_14025e7b0()->m_flags.FUN_1402c4c90(99) != 0) {
        FUN_141275260(0x2f7, 1, 1);
    } else {
        if (FUN_140166410()->FUN_14036d570(0xe4)) {
            int nArea = FUN_1409670e0()->FUN_1410c3470();
            MS2Ptr<ExtendAreaInfo> spPrev = FUN_140933200()->GetPreviousArea(nArea);
            if (spPrev == 0) {
                CStringW strKey(L"s_ugcmap_cant_shrink_area_level_anymore");
                FUN_1412751f0(FUN_14028b8e0(strKey), 1, 1);
            } else {
                CStringW strMsg = FUN_1409e8970(CStringW(L"s_home_shrink_area_messagebox"), nArea, spPrev->m_nArea);
                MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, CStringW(strMsg), 0, CStringW(L""));
                if (spBox.get() != 0) {
                    spBox->FUN_141a01800(1);
                    spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIHomeResizeDialog::SendRequestCubeMode38));
                    FUN_140d73c60(spBox);
                }
            }
        }
    }
}

// @0x140c2c2f0
// MS2-FUNCTIONAL: frame slot order of the MS2Ptr/CStringW temporaries differs from the exe
void UIHomeResizeDialog::OnShrinkHeight()
{
    if (FUN_14025e7b0()->m_flags.FUN_1402c4c90(99) != 0) {
        FUN_141275260(0x2f7, 1, 1);
    } else {
        if (FUN_140166410()->FUN_14036d570(0xe4)) {
            int nHeight = FUN_1409670e0()->FUN_1410c34b0();
            MS2Ptr<ExtendHeightInfo> spPrev = FUN_140933200()->GetPreviousHeight(nHeight);
            if (spPrev == 0) {
                CStringW strKey(L"s_ugcmap_cant_shrink_height_level_anymore");
                FUN_1412751f0(FUN_14028b8e0(strKey), 1, 1);
            } else {
                CStringW strMsg = FUN_1409e8970(CStringW(L"s_home_shrink_height_messagebox"), nHeight, spPrev->m_nHeight);
                MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, CStringW(strMsg), 0, CStringW(L""));
                if (spBox.get() != 0) {
                    spBox->FUN_141a01800(1);
                    spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIHomeResizeDialog::SendRequestCubeMode45));
                    FUN_140d73c60(spBox);
                }
            }
        }
    }
}

// @0x140c2c640
void UIHomeResizeDialog::OnExtensionArea()
{
    int nArea = FUN_1409670e0()->FUN_1410c3470();
    MS2Ptr<ExtendAreaInfo> spNext = FUN_140933200()->GetNextArea(nArea);
    if (spNext == 0) {
        FUN_141275260(0xcaa, 1, 1);
        return;
    }
    CStringW strPrice = FUN_1418fec00(1, spNext->m_nPrice, 0);
    CStringW strTrophy = FUN_14093bad0(spNext->m_nWidth, spNext->m_nLength, CStringW(L""));
    CStringW strMsg = FUN_14028dfa0(CStringW(L"s_home_extension_area_trophy_messagebox"), nArea, spNext->m_nArea, strTrophy, strPrice);
    if (strTrophy.IsEmpty() || FUN_1406c7600()->FUN_140936640(spNext->m_nWidth, spNext->m_nLength) != 0)
        strMsg = FUN_14028dfa0(CStringW(L"s_home_extension_area_messagebox"), nArea, spNext->m_nArea, strPrice);
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, CStringW(strMsg), 0, CStringW(L""));
    if (spBox.get() != 0) {
        spBox->FUN_141a01800(1);
        spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIHomeResizeDialog::SendRequestCubeMode37));
        FUN_140d73c60(spBox);
    }
}

// @0x140c2cac0
void UIHomeResizeDialog::OnExtensionHeight()
{
    int nHeight = FUN_1409670e0()->FUN_1410c34b0();
    MS2Ptr<ExtendHeightInfo> spNext = FUN_140933200()->GetNextHeight(nHeight);
    if (spNext == 0) {
        FUN_141275260(0xcab, 1, 1);
        return;
    }
    CStringW strPrice = FUN_1418fec00(1, spNext->m_nPrice, 0);
    CStringW strMsg = FUN_14028dfa0(CStringW(L"s_home_extension_height_messagebox"), nHeight, spNext->m_nHeight, strPrice);
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, CStringW(strMsg), 0, CStringW(L""));
    if (spBox.get() != 0) {
        spBox->FUN_141a01800(1);
        spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIHomeResizeDialog::SendRequestCubeMode44));
        FUN_140d73c60(spBox);
    }
}

// @0x140c2cd90
bool UIHomeResizeDialog::SendRequestCubeMode38(int nResult, const CMsgBoxData& data)
{
    if (nResult == 0) {
        COutPacket pkt(0x37, 0);
        pkt.Encode1(0x26);
        FUN_140710590(pkt);
    }
    return true;
}

// @0x140c2ce00
bool UIHomeResizeDialog::SendRequestCubeMode45(int nResult, const CMsgBoxData& data)
{
    if (nResult == 0) {
        COutPacket pkt(0x37, 0);
        pkt.Encode1(0x2d);
        FUN_140710590(pkt);
    }
    return true;
}

// @0x140c2ce70
bool UIHomeResizeDialog::SendRequestCubeMode37(int nResult, const CMsgBoxData& data)
{
    if (nResult == 0) {
        COutPacket pkt(0x37, 0);
        pkt.Encode1(0x25);
        FUN_140710590(pkt);
    }
    return true;
}

// @0x140c2cee0
bool UIHomeResizeDialog::SendRequestCubeMode44(int nResult, const CMsgBoxData& data)
{
    if (nResult == 0) {
        COutPacket pkt(0x37, 0);
        pkt.Encode1(0x2c);
        FUN_140710590(pkt);
    }
    return true;
}

// @0x140c2cf50
void UIHomeResizeDialog::vfunc_84()
{
    Unk_HrPc* pPc = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPc == 0)
        return;
    ASDialog* dialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (dialog == 0)
        return;
    bool bShrink = true;
    bool bExtend = true;
    if (!FUN_140166410()->FUN_14036d570(0xe4))
        bShrink = false;
    if (FUN_14025e7b0()->m_flags.FUN_1402c4c90(99) != 0)
        bShrink = false;
    ASObj obj(2);
    int nArea;
    obj.FUN_1407cbb20("extensionArea", FUN_14062b4f0(CStringW(L"s_home_info_area"), &(nArea = FUN_1409670e0()->FUN_1410c3470())));
    int nHeight;
    obj.FUN_1407cbb20("extensionHeight", FUN_14062b4f0(CStringW(L"s_home_info_height"), &(nHeight = FUN_1409670e0()->FUN_1410c34b0())));
    obj.FUN_1407cbbe0("shrinkEnable", bShrink);
    obj.FUN_1407cbbe0("extensionEnable", bExtend);
    dialog->FUN_140acd1f0("buildInteriorExtension", obj);
}
