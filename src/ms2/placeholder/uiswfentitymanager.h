// uiswfentitymanager.h - PLACEHOLDER for UISwfEntityManager (RTTI .?AVUISwfEntityManager@@, vftable 0x143112518)
// and its singleton getter. NOT an original header. Owns the loaded swf movies, keyed by (group m_28, key m_20) of
// each UISwfEntity. Only the non-virtual methods recovered code calls are declared.
#pragma once

#include <afx.h>

#include "ms2/placeholder/ascript.h"

class UISwfEntity;
class UISceneEntity;

class UISwfEntityManager
{
public:
    void FUN_1422d0cd0(MS2Ptr<UISwfEntity> p);                                                  // register (ctor)
    CString FUN_1422d1210(int nGroup, const CString& strKey, const CString& strPath, int a1, int a2);
    CString FUN_1422d1320(int nGroup, const CString& strKey, const CString& strPath, int a1, int a2, int a3,
                          UISwfEntity* pEntity);                                                // load
    CString FUN_1422d17a0(int nGroup, CString strKey, int n);                                   // unload; new key
    void FUN_1422d1b20(int nGroup, const CString& strKey, int n);
    void FUN_1422d0dc0(MS2Ptr<UISwfEntity> p);                                                  // unregister (w4s9)
    void FUN_1422d4780(UISwfEntity* p, int n);
    void FUN_1422d4840(UISwfEntity* p, int n);
    void FUN_1422d48f0(UISwfEntity* p, int nLayer);                                             // bring to the top (uimessagebox.cpp)
    void FUN_1422d4b70(bool bShow);
    void FUN_1422d0c10(MS2Ptr<UISceneEntity> p);                                               // register a scene (UISceneEntity ctor)
    UISwfEntity* FUN_1422d40b0(int nId);                                                        // the entity of an id (scene ids: gfxsceneservice.cpp)
    UISwfEntity* FUN_1422d4380(const CString& strName);                                         // a movie by name, trimmed, no case (uialignwidget.cpp)
    UISwfEntity* FUN_1422d4980(int nLayer);                                                     // the dialog on a layer (0x1422d4980)
    MS2Ptr<UISwfEntity> FUN_1422d41b0(const CString& strName);                                 // a movie by name (ugcmanager.cpp#2)                                                             // show/hide all movies (scenestategame.cpp)
    void FUN_1422d4dd0(CString strKey);                                                         // bring the movie to the top most layer (uiworldmapdialog.cpp; by value)
    int FUN_1422d4e20(CString strKey);                                                          // the movie is the top most one (uiworldmapdialog.cpp; by value)
};

UISwfEntityManager* FUN_140b632f0();    // the instance (a global pointer at 0x143abb058)
