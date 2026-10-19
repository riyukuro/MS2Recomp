// Market payload RTTI classes; field offsets are observed in 0x1401fe3d0-0x1401fe730.
#pragma once
#include "ms2/placeholder/cptred.h"
#include "ms2/commonfiles/stream.h"
class CMeratMarketPacket {
public:
    struct BuyPacket;       // meratmarketbasketinfo.h
    struct ErrorPacket;     // meratmarketbasketinfo.h
    class UgcAddProductBase:public CPtred {
    public:
        UgcAddProductBase();                // 0x14131cff0 (uimeratmarketregisterdialog.cpp)
        virtual ~UgcAddProductBase();
        virtual void vfunc_1(COutputStream&);
        virtual void vfunc_2(void*);
        __int64 id;
        bool enabled;
        CStringW name,description;
        __int64 price;
    };
    class UgcAddProduct:public UgcAddProductBase {
    public:
        UgcAddProduct();                    // 0x14131cfb0
        virtual ~UgcAddProduct();
        void vfunc_1(COutputStream&)override;
        void vfunc_2(void*)override;
        __int64 product;
    };
    class UgcResaleProduct:public UgcAddProductBase {
    public:
        UgcResaleProduct();                 // 0x14131d070
        virtual ~UgcResaleProduct();
        void vfunc_1(COutputStream&)override;
        void vfunc_2(void*)override;
        __int64 product;
    };
};
MS2_CHECK_SIZE(CMeratMarketPacket::UgcAddProductBase,0x40);
MS2_CHECK_OFFSET(CMeratMarketPacket::UgcAddProductBase,name,0x28);
MS2_CHECK_SIZE(CMeratMarketPacket::UgcAddProduct,0x48);
MS2_CHECK_SIZE(CMeratMarketPacket::UgcResaleProduct,0x48);
