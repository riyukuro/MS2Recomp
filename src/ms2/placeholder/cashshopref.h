// cashshopref.h - PLACEHOLDER for the handle the cash-shop web dialogs take of the UICashShopDialog while they close
// (0x10 bytes, the intrusively counted pointee at +8). Defined in cashchargedialog.cpp (0x140b05020-0x140b05570). NOT an original header.
#pragma once

#include "ms2/ms2layout.h"

class UICashShopDialog;

class Unk_CashShopRef
{
public:
    Unk_CashShopRef(UICashShopDialog* pDialog);                     // 0x140b05020
    ~Unk_CashShopRef();                                             // 0x140b05080
    UICashShopDialog* FUN_140b051c0() const;                        // the pointee (null test)
    UICashShopDialog* FUN_140b051d0() const;                        // the pointee
private:
    void FUN_140b054b0();                                           // takes the reference
    void FUN_140b05500(void*);
    void FUN_140b05530();                                           // drops the reference
    void FUN_140b05570(void*);
    static void FUN_140b054e0(UICashShopDialog* pDialog);
    void* m_unk0;
    UICashShopDialog* m_pDialog;
};
MS2_CHECK_SIZE(Unk_CashShopRef, 0x10);

UICashShopDialog* FUN_140b04f80(int nId);                           // the open UICashShopDialog with the UI id
