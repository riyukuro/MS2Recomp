// RTTI-named item-colouring payload, layout from 0x140200000 and new(0x48).
#pragma once
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/citemextradata.h"
#include "ms2/unnamed/payloadptr_1401f9eb0.h"
#include <atlcoll.h>
class CCItemColoringPacket {
public:
    class ChangeColorItem:public CPtred {
    public:
        ChangeColorItem();
        ~ChangeColorItem();
        void FUN_1402000a0(COutputStream&);
        void FUN_1402001b0(void*);
        void FUN_140200480(COutputStream&);
        void FUN_140200590(CInputStream&);
        void FUN_1402007b0(const ChangeColorItem&);
        bool flag18,flag19,flag1a;
        int value1c;
        __int64 value20,value28;
        int type;
        Unk_PayloadPtr<CItemExtraData> extra;
    };
    // The dye request (0x23/0x16; CPtred + the items; ctor 0x1419b31c0, dtor 0x1419b32c0, inline in uiitemcoloringdialog.cpp).
    // unit_1401f9eb0.cpp views the same object as Unk_ColorItems.
    class ChangeColors:public CPtred {
    public:
        ChangeColors() {}
        virtual ~ChangeColors() {}
        void FUN_140200950(COutputStream& stream);                          // encode
        void FUN_140200bc0(Unk_PayloadPtr<ChangeColorItem> spItem);         // add
        ATL::CAtlArray<Unk_PayloadPtr<ChangeColorItem> > items;
    };
};
MS2_CHECK_SIZE(CCItemColoringPacket::ChangeColorItem,0x48);
MS2_CHECK_OFFSET(CCItemColoringPacket::ChangeColorItem,extra,0x38);
