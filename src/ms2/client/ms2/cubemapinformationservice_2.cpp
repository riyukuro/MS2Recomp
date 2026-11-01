// Cube palette selection and paging. Recovered from KMS2_DEV x64, 2022-04-13.
// MS2-UNIT: client\ms2\cubemapinformationservice.cpp#2
// MS2-RANGE: 0x1410b4e80-0x1410b68a0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??4?$MS2Ptr@VCubeItemInfo@@@@QEAAAEAV0@AEBV0@@Z 0x1410b6490 ; unique
// MS2-PIN: ?IsEmpty@?$CAtlArray@V?$MS2Ptr@VUGCCube@UGCCubePalette@@@@V?$CElementTraits@V?$MS2Ptr@VUGCCube@UGCCubePalette@@@@@ATL@@@ATL@@QEBA_NXZ 0x1410b6640 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\cubemapinformationservice.cpp"
#if defined(__clang__)
// The original SDK uses the pre-C++17 register keyword.
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wregister"
#endif
#include "ms2/placeholder/ms2stdafx.h"
#include "cubemapinformationservice_2.h"
#include "inventory.h"
#include "fielddatacli.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#if defined(__clang__)
#pragma clang diagnostic pop
#endif

extern Unk_Inventory g_143ab2a90;
#include "ms2/client/ms2/warehouseitem.h"     // DAT_143ab2e20, the warehouse item table
class PCBase;
class Unk_CubeCraftCore;
class WorldService   // C3: member view for the former free stand-ins
{
public:
    void* FUN_141bd0cc0();
    static class WorldService* GetInstance();
    MS2Ptr<CFieldDataCli> FUN_141bd30a0();   // C3: the real member (0x141bd30a0, copy of m_298)
};
class PC { public: int FUN_1416595d0(); };   // C3: unit-local view
class MyPC   // C3: member view for the former free stand-ins
{
public:
    class Unk_PCCubeCraft* GetActiveCubeCraft();
};
int FUN_1410a8a90(Unk_CubeCraftCore*);
// WorldService singleton viewed through its +0x298 current-field handle getter (0x141bd30a0).
MS2Ptr<CItemData> FUN_14053f870(int);
class UIUGCCubePaletteDialog;
UIUGCCubePaletteDialog* FUN_140ef4a50(int);
class UIUGCCubePaletteDialog   // C3: member view for the former free stand-ins
{
public:
    void FUN_140eef560(int);
};

// @0x1410b4e80
CubeHolderManager::CubeHolderManager() : palette(0),selected(0) {}
// @0x1410b4f00
CubeHolderManager::~CubeHolderManager() {}

// Constructs a local RTTI object; not hooked.
// @0x1410b4f60
void CubeHolderManager::LoadCubes(const Unk_CubePaletteFilter& filter) {
    if(palette==0) palette.AssignRaw(new UGCCubePalette);
    cubes.RemoveAll();
    palette->FUN_140df1a40(cubes,const_cast<Unk_CubePaletteFilter&>(filter));
}
// @0x1410b5030
int CubeHolderManager::GetCubes(CubeArray& out) {
    for(unsigned i=0;i<cubes.GetCount();++i) out.Add(cubes[i]);
    return cubes.IsEmpty() ? 0 : 1;
}
MS2_REPLACE_METHOD(0x1410B5030, CubeHolderManager, GetCubes, 153, 0xA3D8AD39);
// Constructs a local RTTI object (filter); not hooked.
// @0x1410b50d0
int CubeHolderManager::FUN_1410b50d0(MS2Ptr<CubeItemInfo>& out) {
    selected=0;
    if(cubes.IsEmpty()) { Unk_CubePaletteFilter filter;LoadCubes(filter); }
    for(unsigned i=0;i<cubes.GetCount();++i) {
        CubePtr cube=cubes[i];
        if(cube==0) continue;
        if(IsItemAllowedInCurrentSpace(cube->FUN_140def5a0())) {
            out=cube->FUN_140def3d0();
            selected=cube;
            return 1;
        }
    }
    return 0;
}
// MS2-FUNCTIONAL: same calls and branches; /Od temp slots differ (exe frame 0x88 keeps the id-compare int temp above the cube handle).
// @0x1410b5280
void CubeHolderManager::FUN_1410b5280(MS2Ptr<CubeItemInfo> info) {
    selected=FindByInstanceId(info->instanceId);
    if(selected==0) {
        for(unsigned i=0;i<cubes.GetCount();++i) {
            CubePtr cube=cubes[i];
            if(cube==0) continue;
            if(cube->FUN_140def5a0()!=info->itemId) continue;
            if(cube->FUN_140def5f0()!=info->instanceId) continue;
            selected=cube;
            break;
        }
    }
}
MS2_REPLACE_METHOD(0x1410B5280, CubeHolderManager, FUN_1410b5280, 453, 0xEBE0474B);
// @0x1410b5460
void CubeHolderManager::SelectByItemId(int itemId) { selected=FindByItemId(itemId); }
// @0x1410b54d0
void CubeHolderManager::SelectByInstanceId(__int64 instanceId) { selected=FindByInstanceId(instanceId); }
MS2_REPLACE_METHOD(0x1410B5460, CubeHolderManager, SelectByItemId, 95, 0x0111D5C6);
// @0x1410b5540
void CubeHolderManager::SelectByIndex(int index) { selected=FindByIndex(index); }
MS2_REPLACE_METHOD(0x1410B54D0, CubeHolderManager, SelectByInstanceId, 96, 0x00C47404);
// @0x1410b55b0
MS2Ptr<CubeItemInfo> CubeHolderManager::FUN_1410b55b0() {
    if(selected.get()) return selected->FUN_140def3d0();
    return MS2Ptr<CubeItemInfo>(0);
}
MS2_REPLACE_METHOD(0x1410B5540, CubeHolderManager, SelectByIndex, 95, 0x3B066F7B);
MS2_REPLACE_METHOD(0x1410B55B0, CubeHolderManager, FUN_1410b55b0, 125, 0xB63FE91C);
// @0x1410b5640
MS2Ptr<CubeItemInfo> CubeHolderManager::GetInfoByIndex(int index) {
    CubePtr cube=FindByIndex(index);
    if(cube.get()) return cube->FUN_140def3d0();
    return MS2Ptr<CubeItemInfo>(0);
}
MS2_REPLACE_METHOD(0x1410B5640, CubeHolderManager, GetInfoByIndex, 166, 0xB1C66128);
// @0x1410b56f0
MS2Ptr<CubeItemInfo> CubeHolderManager::GetInfoByInstanceId(__int64 instanceId) {
    CubePtr cube=FindByInstanceId(instanceId);
    if(cube.get()) return cube->FUN_140def3d0();
    return MS2Ptr<CubeItemInfo>(0);
}
MS2_REPLACE_METHOD(0x1410B56F0, CubeHolderManager, GetInfoByInstanceId, 166, 0xCC45B9C2);
// @0x1410b57a0
CubeHolderManager::CubePtr CubeHolderManager::GetSelected() { return selected; }
// @0x1410b57f0
CubeHolderManager::CubePtr CubeHolderManager::FindByIndex(int index) {
    if(index==0) return CubePtr(0);
    for(unsigned i=0;i<cubes.GetCount();++i) {
        CubePtr cube=cubes[i];
        if(cube==0) continue;
        if(cube->FUN_140defff0()==index) return cube;
    }
    return CubePtr(0);
}
MS2_REPLACE_METHOD(0x1410B57A0, CubeHolderManager, GetSelected, 65, 0xEB612B86);
MS2_REPLACE_METHOD(0x1410B57F0, CubeHolderManager, FindByIndex, 313, 0xD8172207);
// @0x1410b5930
CubeHolderManager::CubePtr CubeHolderManager::FindByItemId(int itemId) {
    if(itemId==0) return CubePtr(0);
    for(unsigned i=0;i<cubes.GetCount();++i) {
        CubePtr cube=cubes[i];
        if(cube==0) continue;
        if(cube->FUN_140def5a0()==itemId) return cube;
    }
    return CubePtr(0);
}
MS2_REPLACE_METHOD(0x1410B5930, CubeHolderManager, FindByItemId, 313, 0x7616A57C);
// @0x1410b5a70
CubeHolderManager::CubePtr CubeHolderManager::FindByInstanceId(__int64 instanceId) {
    if(instanceId==0) return CubePtr(0);
    for(unsigned i=0;i<cubes.GetCount();++i) {
        CubePtr cube=cubes[i];
        if(cube==0) continue;
        if(cube->FUN_140def5f0()==instanceId) return cube;
    }
    return CubePtr(0);
}
MS2_REPLACE_METHOD(0x1410B5A70, CubeHolderManager, FindByInstanceId, 315, 0xDAAB77E4);
// @0x1410b5bc0
int CubeHolderManager::GetSelectedItemId() {
    if(selected==0) return 0;
    return selected->FUN_140def3d0()->itemId;
}
MS2_REPLACE_METHOD(0x1410B5BC0, CubeHolderManager, GetSelectedItemId, 129, 0x271D420E);
// @0x1410b5c50
int CubeHolderManager::GetItemIdByIndex(int index) {
    CubePtr cube=FindByIndex(index);
    if(cube==0) return 0;
    return cube->FUN_140def5a0();
}
MS2_REPLACE_METHOD(0x1410B5C50, CubeHolderManager, GetItemIdByIndex, 127, 0x04DC8125);
// @0x1410b5ce0
unsigned CubeHolderManager::GetSelectedPage() {
    unsigned index=GetSelectedIndex();
    if(index>0) {
        unsigned page=(index-1)/10;
        unsigned last=(unsigned)((cubes.GetCount()-1)/10);
        return last<page ? last : page;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1410B5CE0, CubeHolderManager, GetSelectedPage, 124, 0x63B03BF7);
// @0x1410b5d70
int CubeHolderManager::GetSelectedIndex() {
    if(selected==0) return 0;
    return selected->FUN_140defff0();
}
MS2_REPLACE_METHOD(0x1410B5D70, CubeHolderManager, GetSelectedIndex, 69, 0xA29D55F1);
// @0x1410b5dc0
MS2Ptr<CItem> CubeHolderManager::FindItemByInstanceId(__int64 instanceId) {
    MS2Ptr<CItem> item=g_143ab2a90.FUN_140a5d680(instanceId);
    if(item.get()) return item;
    return DAT_143ab2e20.FUN_1408fbf90(instanceId);
}
MS2_REPLACE_METHOD(0x1410B5DC0, CubeHolderManager, FindItemByInstanceId, 170, 0xC00EE4A8);
// @0x1410b5e70
int CubeHolderManager::FUN_1410b5e70() {
    PCBase* pc=((class PCBase*)((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0());
    if(pc==0) return 0;
    return ((PC*)pc)->FUN_1416595d0();
}
MS2_REPLACE_METHOD(0x1410B5E70, CubeHolderManager, FUN_1410b5e70, 54, 0x2F3817D5);
// @0x1410b5eb0
int CubeHolderManager::FUN_1410b5eb0() {
    PCBase* pc=((class PCBase*)((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0());
    if(pc==0) return 0;
    Unk_CubeCraftCore* craft=((class Unk_CubeCraftCore*)((class MyPC*)(class PCBase*)(pc))->GetActiveCubeCraft());
    if(craft==0) return 0;
    return FUN_1410a8a90(craft);
}
MS2_REPLACE_METHOD(0x1410B5EB0, CubeHolderManager, FUN_1410b5eb0, 81, 0x1BD6028B);
// @0x1410b5f10
int CubeHolderManager::IsItemAllowedInCurrentSpace(int itemId) {
    if(FUN_1410b5eb0()==2) return 0;
    MS2Ptr<CFieldDataCli> field=WorldService::GetInstance()->FUN_141bd30a0();
    if(field==0) return 0;
    MS2Ptr<CItemData> item=FUN_14053f870(itemId);
    if(item==0) return 0;
    if((item->install.space&field->m_nIndoorMask)==field->m_nIndoorMask) return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x1410B5F10, CubeHolderManager, IsItemAllowedInCurrentSpace, 326, 0x90A46527);
// @0x1410b6060
int CubeHolderManager::FUN_1410b6060(unsigned index) {
    if(index==0) {
        return 1;
    } else {
        if(cubes.GetCount()<=index) return 1;
        MS2Ptr<CubeItemInfo> info=GetInfoByIndex(index);
        if(info==0) return 2;
        MS2Ptr<CItemData> item=FUN_14053f870(info->itemId);
        if(item==0) return 2;
        MS2Ptr<CFieldDataCli> field=WorldService::GetInstance()->FUN_141bd30a0();
        if((item->install.space&field->m_nIndoorMask)!=field->m_nIndoorMask) return 3;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1410B6060, CubeHolderManager, FUN_1410b6060, 408, 0xFA708C3B);
// @0x1410b6210
void CubeHolderManager::GoToPrevPage() {
    unsigned page=GetSelectedPage();
    unsigned index=(page-1)*10+1;
    if(page>0) SelectPaletteRow(index);
}
MS2_REPLACE_METHOD(0x1410B6210, CubeHolderManager, GoToPrevPage, 64, 0x5214C64F);
// @0x1410b6260
void CubeHolderManager::GoToNextPage() {
    unsigned page=GetSelectedPage();
    unsigned last=(unsigned)((cubes.GetCount()-1)/10);
    unsigned next=(page+1)*10+1;
    if(page<last) SelectPaletteRow(next);
}
MS2_REPLACE_METHOD(0x1410B6260, CubeHolderManager, GoToNextPage, 101, 0xEA5CE1E2);
// @0x1410b62d0
void CubeHolderManager::SelectNext() {
    unsigned next=static_cast<unsigned>(GetSelectedIndex())+1;
    if(next>cubes.GetCount()) SelectPaletteRow(1);
    else SelectPaletteRow(next);
}
MS2_REPLACE_METHOD(0x1410B62D0, CubeHolderManager, SelectNext, 94, 0xEFE7B3D8);
// @0x1410b6340
void CubeHolderManager::SelectPaletteRow(int index) {
    UIUGCCubePaletteDialog* dialog=FUN_140ef4a50(0x4f16);
    if(dialog!=0) ((class UIUGCCubePaletteDialog*)(dialog))->FUN_140eef560(index);
}
MS2_REPLACE_METHOD(0x1410B6340, CubeHolderManager, SelectPaletteRow, 55, 0x4EA4BF9E);
MS2_EMIT_CRT_MEMMOVE_S();
