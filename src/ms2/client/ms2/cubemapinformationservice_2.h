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
    void SelectByItemId(int);
    void SelectByInstanceId(__int64);
    void SelectByIndex(int);
    MS2Ptr<CubeItemInfo> FUN_1410b55b0();
    MS2Ptr<CubeItemInfo> GetInfoByIndex(int);
    MS2Ptr<CubeItemInfo> GetInfoByInstanceId(__int64);
    CubePtr GetSelected();
    CubePtr FindByIndex(int);
    CubePtr FindByItemId(int);
    CubePtr FindByInstanceId(__int64);
    int GetSelectedItemId();
    int GetItemIdByIndex(int);
    unsigned GetSelectedPage();
    int GetSelectedIndex();
    MS2Ptr<CItem> FindItemByInstanceId(__int64);
    int FUN_1410b5e70();
    int FUN_1410b5eb0();
    int IsItemAllowedInCurrentSpace(int itemId);
    int FUN_1410b6060(unsigned index);
    void GoToPrevPage();
    void GoToNextPage();
    void SelectNext();
    void SelectPaletteRow(int);
    MS2Ptr<UGCCubePalette> palette;
    CubePtr selected;
    CubeArray cubes;
};
MS2_CHECK_SIZE(CubeHolderManager,0x48);
MS2_CHECK_OFFSET(CubeHolderManager,palette,8);
MS2_CHECK_OFFSET(CubeHolderManager,selected,0x18);
MS2_CHECK_OFFSET(CubeHolderManager,cubes,0x28);
