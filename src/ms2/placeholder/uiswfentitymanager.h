// uiswfentitymanager.h - PLACEHOLDER for UISwfEntityManager (RTTI .?AVUISwfEntityManager@@, vftable 0x143112518)
// and its singleton getter. NOT an original header. Owns the UI entities (UISwfEntity / UISceneEntity) and the swf
// movies they load, keyed by the unique swf id (UniqueSwfIDCreator) each entity keeps in m_20. RTTI: efd::MemObject @8
// and SingletonClass<UISwfEntityManager> @9, 22 vftable slots (0 ??_G 0x1422d57c0); 0x260 bytes (GFxService's EE_NEW).
// Code in ?\uiswfentitymanager.cpp (src/ms2/gfxui/uiswfentitymanager.cpp); layout from its ctor 0x1422d0960 / dtor
// 0x1422d0af0. The virtual slots are the GFx movies' callbacks (gfxmoviemain.cpp & co. still call them through
// unit-local views): each forwards to the entities' UISwfEntity slot noted on it.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <efd/MemObject.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/singletonclass.h"

#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/gfxvalue.h"

class UISwfEntity;
class UISceneEntity;

class UISwfEntityManager : public efd::MemObject, public SingletonClass<UISwfEntityManager>
{
public:
    UISwfEntityManager();                                                                       // 0x1422d0960
    virtual ~UISwfEntityManager();                                                              // 0 0x1422d0af0 (??_G 0x1422d57c0)
    virtual void vfunc_1();                                                                     // 1 loaded movies: FUN_1422dc450
    virtual void vfunc_2();                                                                     // 2 loaded movies: slot 11 (scenes: shown only)
    virtual void vfunc_3();                                                                     // 3 loaded movies: slot 12 (scenes: shown only)
    virtual void vfunc_4();                                                                     // 4 render device lost (slot 16)
    virtual bool vfunc_5();                                                                     // 5 render device restored (slot 17)
    virtual void vfunc_6();                                                                     // 6 all entities: slot 18
    virtual void vfunc_7(CString strKey, Scaleform::GFx::Value vRoot);                          // 7 swf "loadInit": slot 41, slot 20
    virtual void vfunc_8(CString strKey, Scaleform::GFx::Value vRoot);                          // 8 slot 21
    virtual void vfunc_9(CString strKey, Scaleform::GFx::Value vRoot, float fTime);             // 9 swf "loadComplete": slot 22, 46
    virtual void vfunc_10(CString strKey, Scaleform::GFx::Value vRoot, void* p);                // 10 slot 23
    virtual void vfunc_11(CString strKey, Scaleform::GFx::Value vRoot, float x, float y);       // 11 slot 24
    virtual void vfunc_12(const CString& a1, const CString& a2, const CString& a3);             // 12 slot 30 (video status)
    virtual void vfunc_13(const CString& a1, float a2, const void* a3);                         // 13 slot 31 (video cue point)
    virtual void vfunc_14(void* p, float x, float y);                                           // 14..20 mouse: slots 32..38
    virtual void vfunc_15(void* p, float x, float y);
    virtual void vfunc_16(void* p, float x, float y);
    virtual void vfunc_17(void* p, float x, float y);
    virtual void vfunc_18(void* p, float x, float y);
    virtual void vfunc_19(void* p, float x, float y);
    virtual void vfunc_20(void* p, float x, float y);                                           // mouse move
    virtual void vfunc_21(void* p, float x, float y, float f);                                  // 21 mouse wheel: slot 39

    void FUN_1422d0bf0(bool b);                                                                 // m_09 (no loads while set)
    int FUN_1422d0c10(MS2Ptr<UISceneEntity> p);                                                 // register a scene (UISceneEntity ctor)
    int FUN_1422d0cd0(MS2Ptr<UISwfEntity> p);                                                   // register (UISwfEntity ctor)
    int FUN_1422d0dc0(MS2Ptr<UISwfEntity> p);                                                   // unregister (unloads it)
    void FUN_1422d0fb0();                                                                       // unload and drop everything
    void FUN_1422d1180();                                                                       // reload every entity (FUN_1422dc1e0)
    CString FUN_1422d1210(int nGroup, CString& strKey, const CString& strPath, int a1, int a2); // preload; the new key
    CString FUN_1422d1320(int nGroup, CString& strKey, const CString& strPath, int a1, int a2, int a3,
                          UISwfEntity* pEntity);                                                // load; the new key
    CString FUN_1422d16c0(int nGroup, CString& strKey, const CString& strPath, int a1);         // preload + load
    CString FUN_1422d17a0(int nGroup, CString strKey, int n);                                   // unload; the new key ("")
    void FUN_1422d19d0(const CString& strClass);                                                // unload the entities of a class name
    void FUN_1422d1b20(int nGroup, const CString& strKey, int n);                               // swap the depth layer
    void FUN_1422d1ba0();                                                                       // shutdown (GFxService::OnShutdown)
    int FUN_1422d1c20();                                                                        // per tick (GFxService::OnTick): input taken
    void FUN_1422d2020();                                                                       //   then this
    void FUN_1422d21b0();                                                                       // all entities: slot 19
    void FUN_1422d2250();                                                                       // drop the pending unloads
    UISwfEntity* FUN_1422d40b0(int nId);                                                        // the scene of a scene id
    MS2Ptr<UISwfEntity> GetUISwfEntity(const CString& strName);                                 // a movie by key (else by class name)
    UISwfEntity* FUN_1422d4380(const CString& strName);                                         // an entity by class name (trimmed, no case)
    MS2Ptr<UISwfEntity> FUN_1422d4580(const CString& strName);                                 // an entity by key (trimmed, no case)
    void FUN_1422d4780(UISwfEntity* p, int nLayer);                                             // add to a layer
    void FUN_1422d4840(UISwfEntity* p, int nLayer);                                             // remove from a layer (and layer 1)
    void FUN_1422d48f0(UISwfEntity* p, int nLayer);                                             // bring to the top (uimessagebox.cpp)
    UISwfEntity* FUN_1422d4980(int nLayer);                                                     // the dialog on top of a layer
    void FUN_1422d49f0();                                                                       // toggle m_0a
    void FUN_1422d4a30(bool b);                                                                 // m_0a, forwarded to GFxManager
    int FUN_1422d4a70(POSITION pos);                                                            // the movie is pending unload
    UISwfEntity* FUN_1422d4af0(POSITION pos);                                                   // a loaded movie (not pending unload)
    void FUN_1422d4b40(int (*pfn)());                                                           // the input-taken override of FUN_1422d1c20
    void FUN_1422d4b70(bool bShow);                                                             // m_09; set: FUN_1422d4bb0
    void FUN_1422d4bb0();                                                                       // unload every non-scene entity
    void FUN_1422d4d10();                                                                       // unload every scene
    void FUN_1422d4dd0(CString strKey);                                                         // m_258 (by value)
    int FUN_1422d4e20(CString strKey);                                                          // strKey == m_258 (by value)

private:
    MS2_LAYOUT_FRIEND;
    bool m_09;                                                          // +0x09 (shares the empty SingletonClass base's byte)
    bool m_0a;                                                          // +0x0a
    CAtlMap<CString, POSITION, CStringElementTraitsI<CString> > m_mapLoaded;   // +0x10 key (no case) -> m_listLoaded position
    CRBMap<MS2Ptr<UISwfEntity>, POSITION> m_mapEntities;                // +0x58 entity -> m_listEntities position
    CAtlList<MS2Ptr<UISceneEntity> > m_listScenes;                      // +0x88
    CAtlList<MS2Ptr<UISwfEntity> > m_listEntities;                      // +0xb8 every registered entity
    CAtlList<MS2Ptr<UISwfEntity> > m_listLoaded;                        // +0xe8 entities with a loaded movie
    CAtlList<MS2Ptr<UISwfEntity> > m_listLayers[5];                     // +0x118 the dialogs of each layer (top first)
    CAtlMap<CString, POSITION, CStringElementTraitsI<CString> > m_mapUnloading; // +0x208 key -> m_listLoaded position, dropped next tick
    int (*m_pfnInputTaken)();                                           // +0x250
    CString m_258;                                                      // +0x258
};
MS2_CHECK_OFFSET(UISwfEntityManager, m_09, 0x09);
MS2_CHECK_OFFSET(UISwfEntityManager, m_mapLoaded, 0x10);
MS2_CHECK_OFFSET(UISwfEntityManager, m_mapEntities, 0x58);
MS2_CHECK_OFFSET(UISwfEntityManager, m_listScenes, 0x88);
MS2_CHECK_OFFSET(UISwfEntityManager, m_listLayers, 0x118);
MS2_CHECK_OFFSET(UISwfEntityManager, m_mapUnloading, 0x208);
MS2_CHECK_OFFSET(UISwfEntityManager, m_258, 0x258);
MS2_CHECK_SIZE(UISwfEntityManager, 0x260);

UISwfEntityManager* FUN_140b632f0();    // the instance (a global pointer at 0x143abb058)
