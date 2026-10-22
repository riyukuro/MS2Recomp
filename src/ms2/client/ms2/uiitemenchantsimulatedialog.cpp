// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIItemEnchantSimulateDialog: see uiitemenchantsimulatedialog.h.
// MS2-UNIT: ?\uiitemenchantsimulatedialog.cpp
// MS2-RANGE: 0x1412d1400-0x1412d2660 .text$mn
// MS2-RANGE: 0x1400edcd0-0x1400edd90 .text$di
// MS2-RANGE: 0x142caf550-0x142caf580 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PIN: ??1UIItemEnchantSimulateDialog@@UEAA@XZ 0x1412d24d0
// MS2-PIN: ??_GUIItemEnchantSimulateDialog@@UEAAPEAXI@Z 0x1412d24f0
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiitemenchantsimulatedialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uiitemenchantsimulatedialog.h"

#include "ms2/ms2format.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The sort type names (the dynamic initializer at 0x1400edcd0 builds them; header statics shared with other units).
static CString s_sortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

void FUN_140710590(COutPacket& packet);                         // 0x140710590 send the packet
CStringW FUN_1406329c0(const wchar_t* pszFormat, float* pfArg); // "{0}" substitution of a float
CStringW FUN_1401e8510(const wchar_t* pszFormat, const CStringW& strArg);   // StringFormat with one text argument

// @0x1412d1400
UIItemEnchantSimulateDialog::UIItemEnchantSimulateDialog()
{
    m_40 = 1;
}

// @0x1412d1450
CString UIItemEnchantSimulateDialog::GetTypeName()
{
    return "ItemEnchantSimulateDialog";
}
MS2_REPLACE_METHOD(0x1412D1450, UIItemEnchantSimulateDialog, GetTypeName, 61, 0x33EFD67E);

// @0x1412d14a0
// MS2-FUNCTIONAL: behaviour-equivalent; the exe keeps each ASData string / packet read in its own temp slot, branch layout and EH unwind map differ
int UIItemEnchantSimulateDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("OnSelect", szMethod) == 0) {
        ASData args;
        if (args.FUN_1422b9620(pArgs, nArgs) != 0) {
            int n1 = atoi(args.FUN_1422b8d30());
            int n2 = atoi(args.FUN_1422b8d30());
            int n3 = atoi(args.FUN_1422b8d30());
            if (n1 != 0 && n2 != 0 && n3 != 0) {
                COutPacket packet(static_cast<int>(SendOp::RequestItemEnchant), 0);
                packet.vfunc_o10_1(0xd);
                packet.vfunc_o10_3(n1);
                packet.vfunc_o10_3(n2);
                short s3 = (short)n3;
                packet.vfunc_o10_2(s3);
                FUN_140710590(packet);
            }
        }
        return 1;
    }
    if (_stricmp("OnEnchant", szMethod) == 0) {
        ASData args;
        if (args.FUN_1422b9620(pArgs, nArgs) != 0) {
            int n1 = atoi(args.FUN_1422b8d30());
            int n2 = atoi(args.FUN_1422b8d30());
            int n3 = atoi(args.FUN_1422b8d30());
            atoi(args.FUN_1422b8d30());
            atoi(args.FUN_1422b8d30());
            int n6 = atoi(args.FUN_1422b8d30());
            if (n1 != 0 && n2 != 0 && n3 != 0) {
                {
                    COutPacket packet(static_cast<int>(SendOp::RequestItemEnchant), 0);
                    packet.vfunc_o10_1(0);
                    FUN_140710590(packet);
                }
                COutPacket packet(static_cast<int>(SendOp::RequestItemEnchant), 0);
                packet.vfunc_o10_1(0xe);
                packet.vfunc_o10_3(n1);
                packet.vfunc_o10_3(n2);
                short s3 = (short)n3;
                packet.vfunc_o10_2(s3);
                packet.vfunc_o10_3(n6);
                FUN_140710590(packet);
            }
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1412D14A0, UIItemEnchantSimulateDialog, vfunc_28, 1261, 0x323FC846);

// @0x1412d19a0
// MS2-FUNCTIONAL: behaviour-equivalent; the exe keeps temps for the if-with-declaration handles and string temporaries; frame layout and EH unwind map differ
void UIItemEnchantSimulateDialog::vfunc_79(void* p)
{
    CInPacket* pPacket = static_cast<CInPacket*>(p);
    UIDialog::vfunc_79(p);
    if (pPacket->FUN_14070fe80() != 0x97)
        return;
    unsigned char nKind = pPacket->vfunc_o8_1();
    if (nKind == 0xd) {
        float fSuccess = pPacket->vfunc_o8_5();
        float fSkipped = pPacket->vfunc_o8_5();
        float fReset = pPacket->vfunc_o8_5();
        CStringW strIngredient = pPacket->vfunc_o8_8();
        CStringW strReturn = pPacket->vfunc_o8_8();
        if (MS2Ptr<ASTextField> spText = FUN_140bb4cf0("m_tfSuccess"))
            spText->FUN_1422c4cd0(FUN_1406329c0(L"{0}", &fSuccess));
        if (MS2Ptr<ASTextField> spText = FUN_140bb4cf0("m_tfReset"))
            spText->FUN_1422c4cd0(FUN_1406329c0(L"{0}", &fReset));
        if (MS2Ptr<ASTextField> spText = FUN_140bb4cf0("m_tfReturn"))
            spText->FUN_1422c4cd0(strReturn);
        if (MS2Ptr<ASTextField> spText = FUN_140bb4cf0("m_tfIngredient"))
            spText->FUN_1422c4cd0(strIngredient);
    } else if (nKind == 0xe) {
        unsigned int nSuccess = pPacket->vfunc_o8_3();
        unsigned int nBroken = pPacket->vfunc_o8_3();
        unsigned int nDown = pPacket->vfunc_o8_3();
        CStringW strIngredient = pPacket->vfunc_o8_8();
        CStringW strReturn = pPacket->vfunc_o8_8();
        CStringW strResult = StringFormat(L"{0}번 성공\n{1}번 손상\n{2}번 하락\n", nSuccess, nBroken, nDown);
        strResult += FUN_1401e8510(L"총 재료 갯수 : {0}\n", strIngredient);
        strResult += FUN_1401e8510(L"총 위로금 갯수 : {0}\n", strReturn);
        if (MS2Ptr<ASTextField> spText = FUN_140bb4cf0("m_result"))
            spText->FUN_1422c4cd0(strResult);
    }
}
MS2_REPLACE_METHOD(0x1412D19A0, UIItemEnchantSimulateDialog, vfunc_79, 1886, 0xC0212CE7);

// @0x1412d2110
CStringW FUN_1412d2110(void* pUnused)
{
    return L"";
}

// @0x1412d2530
int UIItemEnchantSimulateDialog::vfunc_48()
{
    return 0x4e9c;
}

MS2_EMIT_CRT_MEMMOVE_S();
