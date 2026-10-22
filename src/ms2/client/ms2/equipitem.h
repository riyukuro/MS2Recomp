// equipitem.h - CEquipItem (RTTI .?AVCEquipItem@@, CPtred-derived, 0xb0 bytes, vftable 0x142ebe698 with the dtor only,
// ??_G 0x1411de450): one worn item of a PC's Equipment (PC+0xde0) and the models (CEquipModel: CNifModel / CKfmModel)
// that render it. Owning unit ?\equipitem.cpp (0x1411dbc70-0x1411df580). Header name assumed; the member names are
// invented (FUN_<va> where no evidence names them, v2525 snapshot names in the comments).
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"   // MS2Ptr<T>
#include "ms2/placeholder/cptred.h"

class PC;
class CItem;
class CEquipModel;
class CKfmModel;
class CNifModel;
class CItemUgcMeshContainer;
struct Unk_EquipItemData;   // the item's CItemData (each user defines it as `struct Unk_EquipItemData : CItemData {}`)
namespace efd { class utf8string; template <class T> class SmartPointer; }
class NiNode;
class NiTexture;

class CEquipItem : public CPtred
{
public:
    CEquipItem();                                                   // 0x1411dbc70
    CEquipItem(PC* pPC, CItem* pItem);                              // 0x1411dbd50 (operator new(0xb0) at 0x14141a128)
    virtual ~CEquipItem();                                          // 0x1411dbe30

    void FUN_1411dbf60();                                           // 0x1411dbf60 OnEquipped: refresh the PC's effect source
    void FUN_1411dbf80(int bKeepModels);                            // 0x1411dbf80 Detach (Equipment 0x1411e3bd0)
    void FUN_1411dbfd0();                                           // 0x1411dbfd0 unequip the items worn along with this one
    void FUN_1411dc040();                                           // 0x1411dc040 Unequip: unload and drop every model
    int FUN_1411dc0d0();                                            // 0x1411dc0d0 IsLoaded: every model reports a state
    int FUN_1411dc190(void* p);                                     // 0x1411dc190 (load callback: rebuild when p is set)
    int FUN_1411dc1d0(void* p);                                     // 0x1411dc1d0 (same, second callback)
    void FUN_1411dc210();                                           // 0x1411dc210 the models finished loading: apply them to the PC
    int FUN_1411dc500(void* p);                                     // 0x1411dc500
    void FUN_1411dc530(void* p);                                    // 0x1411dc530
    int FUN_1411dc560();                                            // 0x1411dc560 drop the models (unload slot 7) and re-apply the look
    int FUN_1411dc670();                                            // 0x1411dc670 CanEquip: a model is ready (slot 20)
    int FUN_1411dc710();                                            // 0x1411dc710 a model's part folds the ears
    MS2Ptr<CItem> GetItem();                                  // 0x1411dc7a0 the item the slot shows
    struct Unk_EquipItemData* FUN_1411dc7f0();                      // 0x1411dc7f0 the item's table data (mypc)
    int FUN_1411dc820();                                            // 0x1411dc820 the item id (mypc)
    __int64 FUN_1411dc870();                                        // 0x1411dc870 the item uid
    PC* FUN_1411dc8c0();                                            // 0x1411dc8c0 the wearer
    void FUN_1411dc8e0(PC* pPC);                                    // 0x1411dc8e0
    void FUN_1411dc900(int bPending);                               // 0x1411dc900 a UGC item waits for its download
    MS2Ptr<CEquipModel> FUN_1411dc950(const CString& strName);      // 0x1411dc950 the model whose part has this name
    void FUN_1411dca30(int nKind, ATL::CAtlArray<CString>& aOut);   // 0x1411dca30 the part names of a model kind
    void FUN_1411dcae0(ATL::CAtlArray<MS2Ptr<CNifModel> >* pOut);  // 0x1411dcae0 the NIF models
    void FUN_1411dcbb0(ATL::CAtlArray<MS2Ptr<CKfmModel> >* pOut);  // 0x1411dcbb0 the KFM models
    void FUN_1411dcc80(ATL::CAtlArray<MS2Ptr<CEquipModel> >& aOut); // 0x1411dcc80 all models
    void FUN_1411dcd00();                                           // 0x1411dcd00 (slot 11 of every model)
    int FUN_1411dcda0();                                            // 0x1411dcda0 a model reports slot 15
    int FUN_1411dce60(const CString& strTag);                       // 0x1411dce60 add a tag ("Customize", "Undo"; customize.cpp)
    int FUN_1411dcf10(const CString& strTag);                       // 0x1411dcf10 remove a tag (customize.cpp)
    int FUN_1411dcfc0(const CString& strTag);                       // 0x1411dcfc0 the first model has the tag
    void FUN_1411dd090();                                           // 0x1411dd090 hair / face items refresh the PC's look (Equipment 0x1411e5c10)
    void FUN_1411dd0f0();                                           // 0x1411dd0f0 the same, Equipment 0x1411e6ab0
    void FUN_1411dd150();                                           // 0x1411dd150 effect items reload the PC's effects
    void FUN_1411dd1c0();                                           // 0x1411dd1c0 (scenestategame, w86)
    void FUN_1411dd280();                                           // 0x1411dd280 apply the tags (customize.cpp)
    void FUN_1411dd3b0();                                           // 0x1411dd3b0 kind 0x12 items
    void FUN_1411dd400(double fTime);                               // 0x1411dd400 Update
    void FUN_1411dd4a0(int n);                                      // 0x1411dd4a0 (slot 32 of every model)
    void FUN_1411dd520(const CString& strA, const CString& strB, const efd::utf8string& kDefault, float fBlend,
        bool b);                                                    // 0x1411dd520 play an animation on the KFM models
    void FUN_1411dd5e0(const CString& strName);                           // 0x1411dd5e0
    void FUN_1411dd650();                                           // 0x1411dd650 drop effect slot 2 of every model
    void FUN_1411dd6d0(CItem* pItem);                               // 0x1411dd6d0
    efd::SmartPointer<NiNode> FUN_1411dd700();                      // 0x1411dd700 the first model's "Point01"
    efd::SmartPointer<NiTexture> FUN_1411dd820();                   // 0x1411dd820 the UGC texture
    MS2Ptr<CItemUgcMeshContainer> GetUgcMeshes();                  // 0x1411dd950 the UGC meshes of the item (ugcmanager.cpp#4)
    void FUN_1411dd9a0();                                           // 0x1411dd9a0 request the UGC download
    void FUN_1411ddae0();                                           // 0x1411ddae0 the UGC download finished
    int FUN_1411ddcb0();                                            // 0x1411ddcb0 the UGC file is here (1)
    CString FUN_1411ddd50();                                        // 0x1411ddd50 the UGC file name
    void FUN_1411dde50(CEquipModel* pModel);                        // 0x1411dde50 add a model
    void FUN_1411ddf10(CEquipModel* pModel);                        // 0x1411ddf10 RemoveModel
    void FUN_1411ddfb0(double fTime);                               // 0x1411ddfb0 update the models (slot 19)
    void FUN_1411de030();                                           // 0x1411de030 create the UGC mesh container

public:
    MS2_LAYOUT_FRIEND;
    PC* m_pPC;                                          // +0x18
    MS2Ptr<CItem> m_spItem;                             // +0x20
    ATL::CAtlList<MS2Ptr<CEquipModel> > m_models;       // +0x30 (ctor 0x1411de210)
    ATL::CAtlList<MS2Ptr<CEquipItem> > m_linkedItems;   // +0x60 worn along with this one (ctor 0x140884ed0)
    int m_bUgcPending;                                  // +0x90
    int m_bTagsDirty;                                   // +0x94
    CString m_strUgcFile;                               // +0x98
    MS2Ptr<CItemUgcMeshContainer> m_spUgcMeshes;        // +0xa0
};
MS2_CHECK_SIZE(CEquipItem, 0xb0);
MS2_CHECK_OFFSET(CEquipItem, m_spItem, 0x20);
MS2_CHECK_OFFSET(CEquipItem, m_models, 0x30);
MS2_CHECK_OFFSET(CEquipItem, m_linkedItems, 0x60);
MS2_CHECK_OFFSET(CEquipItem, m_bUgcPending, 0x90);
MS2_CHECK_OFFSET(CEquipItem, m_strUgcFile, 0x98);
MS2_CHECK_OFFSET(CEquipItem, m_spUgcMeshes, 0xa0);
