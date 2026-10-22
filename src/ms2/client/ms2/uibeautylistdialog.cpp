// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIBeautyListDialog: see uibeautylistdialog.h.
// MS2-UNIT: ?\uibeautylistdialog.cpp
// MS2-RANGE: 0x140f004b0-0x140f01070 .text$mn
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uibeautylistdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uibeautylistdialog.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

MS2_EMIT_CRT_MEMMOVE_S();

// ---- unit-local views of exe objects ----

class Unk_BlConstInt { public: int* FUN_1401d7c10(); };
class Unk_BlGlobals
{
public:
    char m_pad_0000[0x61f8];
    Unk_BlConstInt m_61f8;
    char m_pad_61f9[0x62a8 - 0x61f9];
    Unk_BlConstInt m_62a8;
    char m_pad_62a9[0x6358 - 0x62a9];
    Unk_BlConstInt m_6358;
};
Unk_BlGlobals* FUN_1401d3200();

class Unk_BlWorld { };
Unk_BlWorld* FUN_1403ed2d0();
void* FUN_141bd0cc0(Unk_BlWorld* pWorld);                       // the local player
int FUN_141bd3060(Unk_BlWorld* pWorld);                         // the current map id
bool FUN_1418fe060();
void FUN_140710590(COutPacket& packet);
CStringW FUN_14028b8e0(const CStringW& str);
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW text, int nUnk, CStringW tag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);

// @0x140f004b0
UIBeautyListDialog::UIBeautyListDialog()
{
    FUN_141924170(1);
}

// @0x140f00510
UIBeautyListDialog::~UIBeautyListDialog()
{
}

// @0x140f00550
CString UIBeautyListDialog::vfunc_1()
{
    return "BeautyListDialog";
}

// @0x140f005a0
int UIBeautyListDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    return 1;
}

// @0x140f005d0
void UIBeautyListDialog::vfunc_67()
{
    UIDialog::vfunc_67();
}

// @0x140f005f0
void UIBeautyListDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
}

// @0x140f00610
bool UIBeautyListDialog::SendBeautyMode10(int nResult, const CMsgBoxData& box)
{
    if (nResult != 0)
        return true;
    int nType = box.FUN_141a02e50(0, 0);
    COutPacket packet(0x23, 0);
    packet.vfunc_o10_1(10);
    packet.vfunc_o10_2(nType);
    FUN_140710590(packet);
    return true;
}

// @0x140f006b0
int UIBeautyListDialog::FUN_140f006b0(int nMapId)
{
    if (nMapId == *FUN_1401d3200()->m_61f8.FUN_1401d7c10())
        return 1;
    if (nMapId == *FUN_1401d3200()->m_62a8.FUN_1401d7c10())
        return 1;
    if (nMapId == *FUN_1401d3200()->m_6358.FUN_1401d7c10())
        return 1;
    return 0;
}

// MS2-FUNCTIONAL: the exe shares one return temp / has a larger frame (EH state count 7 vs 8); same calls and branches
// @0x140f00730
int UIBeautyListDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    int nType = 0;
    ASData data;
    if (_stricmp("onClickHair", szMethod) == 0)
        nType = 1;
    else if (_stricmp("onClickColoring", szMethod) == 0)
        nType = 5;
    else if (_stricmp("onClickFace", szMethod) == 0)
        nType = 3;
    int nRet;
    if (nType == 0)
    {
        nRet = 0;
    }
    else
    {
        void* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
        if (pPlayer == 0)
        {
            nRet = 0;
        }
        else
        {
            int bSalon = FUN_140f006b0(FUN_141bd3060(FUN_1403ed2d0()));
            int bFlag = FUN_1418fe060();
            if (bFlag == 0 && bSalon == 0)
            {
                MS2Ptr<CMsgBoxData> box = FUN_140d73d20(1, FUN_14028b8e0(CStringW(L"s_beauty_goto_map_return_warn")), 0, CStringW(L""));
                if (box.get() != 0)
                {
                    box->FUN_140533ff0(nType);
                    box->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIBeautyListDialog::SendBeautyMode10));
                    FUN_140d73c60(box);
                }
            }
            else
            {
                COutPacket packet(0x23, 0);
                packet.vfunc_o10_1(10);
                packet.vfunc_o10_2(nType);
                FUN_140710590(packet);
            }
            vfunc_67();
            nRet = 1;
        }
    }
    return nRet;
}

// ---- hooks ----
MS2_REPLACE_METHOD(0x140F00550, UIBeautyListDialog, vfunc_1, 61, 0x39CDE7B6);
MS2_REPLACE_METHOD(0x140F005A0, UIBeautyListDialog, vfunc_65, 37, 0x08DECE9B);
MS2_REPLACE_METHOD(0x140F005D0, UIBeautyListDialog, vfunc_67, 24, 0xCDB64A16);
MS2_REPLACE_METHOD(0x140F005F0, UIBeautyListDialog, OnLoadComplete, 24, 0xF14792AA);
MS2_REPLACE_METHOD(0x140F00610, UIBeautyListDialog, SendBeautyMode10, 144, 0x8984A75E);
MS2_REPLACE_METHOD(0x140F006B0, UIBeautyListDialog, FUN_140f006b0, 122, 0x2A121F15);
MS2_REPLACE_METHOD(0x140F00730, UIBeautyListDialog, vfunc_28, 986, 0xE0F5361C);

// Shared header statics and class metadata of this TU (.text$di + atexit thunks; gap2 orphan di sweep).
// MS2-RANGE: 0x1400ddba0-0x1400ddde0 .text$di
// MS2-RANGE: 0x142ca8d00-0x142ca8dc0 .text$yd
static CString s_strPremiumSortNames[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
#include "ms2/placeholder/header_statics_a.h"
