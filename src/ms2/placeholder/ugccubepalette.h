// Heap-only palette records, from 140df19b0/140def070 and their deleting destructors.
#pragma once
#include <atlcoll.h>
#include "ms2/placeholder/cubeiteminfo.h"
#include "ms2/placeholder/citemdata.h"


struct Unk_CubePaletteFilter {
    Unk_CubePaletteFilter(); // 140df0030
    ~Unk_CubePaletteFilter(); // 140ef04a0
    bool FUN_140df00b0();                                                         // 0x140df00b0 (ugccubepalette.cpp)
    bool FUN_140df00d0();                                                         // 0x140df00d0 (uiugccubepalettedialog.cpp)
    bool FUN_140df00f0();                                                         // 0x140df00f0
    int FUN_140df0110();                                                          // 0x140df0110
    int FUN_140df0160();                                                          // 0x140df0160
    int FUN_140df01a0();                                                          // 0x140df01a0
    void FUN_140df0140(int);                                                      // 0x140df0140
    void FUN_140df0180(int);                                                      // 0x140df0180
    bool includeOwned,flag1,flag2;
    int category;
    CStringW text;
    int field10,field14,field18;
};
MS2_CHECK_SIZE(Unk_CubePaletteFilter,0x20);
MS2_CHECK_OFFSET(Unk_CubePaletteFilter,text,8);

class UGCCubePalette : public CPtred {
public:
    class UGCCube : public CPtred {
    public:
        UGCCube(int itemId);                                                      // 0x140def070
        UGCCube(int itemId, __int64 uid, __int64 count, CUgcItemLook* pLook);     // 0x140def210
        MS2Ptr<CubeItemInfo> FUN_140def3d0();
        int FUN_140def5a0();
        __int64 FUN_140def5f0();
        int FUN_140defff0();
        // uiugccubepalettedialog.cpp
        __int64 FUN_140defba0();
        bool FUN_140def420();
        __int64 FUN_140def620();
        __int64 FUN_140def6c0();
        CStringW FUN_140def710();
        CStringW FUN_140def880();
        CStringW FUN_140defd20();
        int FUN_140defcd0();
        unsigned FUN_140defe70();
        unsigned FUN_140defed0();
        bool FUN_140def4f0();
        // ugccubepalette.cpp
        int FUN_140defc30();
        int FUN_140defc80();
        bool FUN_140defdd0(int nId);
        bool FUN_140deff30();
        void FUN_140df0010(int nIndex);
        int index;
        MS2Ptr<CItemData> itemData;
        MS2Ptr<ItemHousing> ingredient;
        MS2Ptr<CubeItemInfo> info;
    };
    typedef MS2Ptr<UGCCube> CubePtr;
    typedef ATL::CAtlArray<CubePtr> CubeArray;
    UGCCubePalette();
    unsigned FUN_140df1a40(CubeArray& out,Unk_CubePaletteFilter& filter);
    // uiugccubepalettedialog.cpp
    CubePtr FUN_1410b57f0(int);
    CubePtr FUN_1410b57a0();
    CubePtr FUN_1410b5930(int);
    CubePtr FUN_1410b5a70(unsigned __int64);
    MS2Ptr<CubeItemInfo> FUN_1410b55b0();
    void FUN_1410b54d0(unsigned __int64);
    void FUN_1410b5030(CubeArray&);
    void FUN_1410b4f60(Unk_CubePaletteFilter*);
    int FUN_1410b5460(int);
    int FUN_1410b5d70();
    int FUN_1410b6060(int);
    int FUN_1410b5bc0();
    void FUN_1410b6210();
    void FUN_1410b6260();
    void FUN_1410b62d0();
private:
    void FUN_140df2250();
    void FUN_140df23f0(CubeArray& out, Unk_CubePaletteFilter* pFilter);
    void FUN_140df2bc0(CubeArray& out, Unk_CubePaletteFilter* pFilter);
    bool FUN_140df3100(const MS2Ptr<class CFieldDataCli>& spField, const MS2Ptr<CItemData>& spData, Unk_CubePaletteFilter* pFilter);
    typedef ATL::CAtlMap<int, MS2Ptr<CItemData> > ItemMap;
    ItemMap mapItems;                   // +0x18 the cube items of the item table that are not stocked or owned
};
MS2_CHECK_SIZE(UGCCubePalette,0x60);
MS2_CHECK_SIZE(UGCCubePalette::UGCCube,0x50);
MS2_CHECK_OFFSET(UGCCubePalette::UGCCube,itemData,0x20);
MS2_CHECK_OFFSET(UGCCubePalette::UGCCube,info,0x40);
