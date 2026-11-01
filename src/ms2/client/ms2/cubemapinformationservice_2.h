#pragma once
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ugccubepalette.h"
#include "ms2/placeholder/citem.h"
class CubeHolderManager : public TSingleton<CubeHolderManager> {
public:
    typedef UGCCubePalette::CubePtr CubePtr;
    typedef UGCCubePalette::CubeArray CubeArray;
    CubeHolderManager();
    virtual ~CubeHolderManager();
    void LoadCubes(const Unk_CubePaletteFilter&);
    int GetCubes(CubeArray&);
    int FUN_1410b50d0(MS2Ptr<CubeItemInfo>&);
    void FUN_1410b5280(MS2Ptr<CubeItemInfo>);
    void FUN_1410b5460(int);
    void FUN_1410b54d0(__int64);
    void FUN_1410b5540(int);
    MS2Ptr<CubeItemInfo> FUN_1410b55b0();
    MS2Ptr<CubeItemInfo> GetInfoByIndex(int);
    MS2Ptr<CubeItemInfo> GetInfoByInstanceId(__int64);
    CubePtr GetSelected();
    CubePtr FUN_1410b57f0(int);
    CubePtr FUN_1410b5930(int);
    CubePtr FUN_1410b5a70(__int64);
    int GetSelectedItemId();
    int FUN_1410b5c50(int);
    unsigned GetSelectedPage();
    int FUN_1410b5d70();
    MS2Ptr<CItem> FindItemByInstanceId(__int64);
    int FUN_1410b5e70();
    int FUN_1410b5eb0();
    int FUN_1410b5f10(int itemId);
    int FUN_1410b6060(unsigned index);
    void FUN_1410b6210();
    void FUN_1410b6260();
    void FUN_1410b62d0();
    void FUN_1410b6340(int);
    MS2Ptr<UGCCubePalette> palette;
    CubePtr selected;
    CubeArray cubes;
};
MS2_CHECK_SIZE(CubeHolderManager,0x48);
MS2_CHECK_OFFSET(CubeHolderManager,palette,8);
MS2_CHECK_OFFSET(CubeHolderManager,selected,0x18);
MS2_CHECK_OFFSET(CubeHolderManager,cubes,0x28);
