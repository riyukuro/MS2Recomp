// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UISwfEntityManager, the registry of the UI entities and
// their swf movies. See src/ms2/placeholder/uiswfentitymanager.h.
// MS2-UNIT: ?\uiswfentitymanager.cpp
// MS2-RANGE: 0x1422d0960-0x1422d8dc0 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). The
// COMDAT tail is the SingletonClass / MS2Ptr<UISwfEntity> / MS2Ptr<UISceneEntity> members and the ATL containers of
// the members (CAtlMap<CString, POSITION>, CRBMap<MS2Ptr<UISwfEntity>, POSITION>, CAtlList<MS2Ptr<...> >).
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/uiswfentitymanager.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/asmoviecliploader.h"
#include "ms2/placeholder/gfxexception.h"
#include "ms2/placeholder/gfxmanager.h"
#include "ms2/placeholder/uniqueswfidcreator.h"
#include "ms2/gfxui/uialignwidget.h"
#include "ms2/gfxui/uisceneentity.h"
#include "ms2/gfxui/uiswfentity.h"

#include "hook/ms2hook.h"

void* FUN_140166440();                                                      // the log
void FUN_14015eb90(void*, int, int, const wchar_t*, const CString&);        // log line ("{0}" = the argument)

static CString s_strNoSwfKey = "";      // 0x143b0d2d0 the key of a failed load / an unloaded movie

// @0x1422d0960
UISwfEntityManager::UISwfEntityManager()
    : m_09(false), m_0a(false), m_pfnInputTaken(0)
{
}

// @0x1422d0af0
UISwfEntityManager::~UISwfEntityManager()
{
    FUN_1422d0fb0();
}

// @0x1422d0bf0
void UISwfEntityManager::FUN_1422d0bf0(bool b)
{
    m_09 = b;
}
MS2_REPLACE_METHOD(0x1422D0BF0, UISwfEntityManager, FUN_1422d0bf0, 23, 0xF9F55C0C);

// @0x1422d0c10
int UISwfEntityManager::FUN_1422d0c10(MS2Ptr<UISceneEntity> p)
{
    if (p)
    {
        MS2Ptr<UISceneEntity> sp(p);
        POSITION pos = m_listScenes.Find(p);
        if (!pos)
            m_listScenes.AddTail(p);
    }
    return (int)m_listScenes.GetCount();
}
MS2_REPLACE_METHOD(0x1422D0C10, UISwfEntityManager, FUN_1422d0c10, 171, 0x9409DC64);

// @0x1422d0cd0
int UISwfEntityManager::FUN_1422d0cd0(MS2Ptr<UISwfEntity> p)
{
    if (p)
    {
        MS2Ptr<UISwfEntity> sp(p);
        if (sp)
        {
            POSITION pos = 0;
            if (!m_mapEntities.Lookup(sp, pos))
            {
                pos = m_listEntities.AddTail(sp);
                m_mapEntities.SetAt(sp, pos);
            }
        }
    }
    return (int)m_listEntities.GetCount();
}
MS2_REPLACE_METHOD(0x1422D0CD0, UISwfEntityManager, FUN_1422d0cd0, 225, 0xD881BC53);

// @0x1422d0dc0
int UISwfEntityManager::FUN_1422d0dc0(MS2Ptr<UISwfEntity> p)
{
    if (p)
    {
        POSITION pos = 0;
        MS2Ptr<UISwfEntity> sp(p);
        if (m_mapEntities.Lookup(sp, pos))
        {
            MS2Ptr<UISwfEntity> spEntity(m_listEntities.GetAt(pos));
            if (spEntity)
            {
                spEntity->FUN_1422dc080();
                {
                    MS2Ptr<UISceneEntity> spScene(dynamic_cast<UISceneEntity*>(p.get()));
                    if (spScene)
                    {
                        POSITION posScene = m_listScenes.Find(spScene);
                        if (posScene)
                            m_listScenes.RemoveAt(posScene);
                    }
                }
                m_listEntities.RemoveAt(pos);
                m_mapEntities.RemoveKey(spEntity);
            }
        }
    }
    return (int)m_listEntities.GetCount();
}
MS2_REPLACE_METHOD(0x1422D0DC0, UISwfEntityManager, FUN_1422d0dc0, 475, 0xB37F0CAC);

// @0x1422d0fb0
void UISwfEntityManager::FUN_1422d0fb0()
{
    m_mapLoaded.RemoveAll();
    m_mapEntities.RemoveAll();
    m_listScenes.RemoveAll();
    while (m_listEntities.GetCount() > 0)
    {
        MS2Ptr<UISwfEntity> sp = m_listEntities.RemoveHead();
        if (sp)
            FUN_1422d17a0(sp->FUN_1422db730(), sp->FUN_1422db6e0(), sp->FUN_1422db750());
    }
    m_listEntities.RemoveAll();
    for (int i = 0; i < 5; i++)
        m_listLayers[i].RemoveAll();
    m_listLoaded.RemoveAll();
    m_mapUnloading.RemoveAll();
}
MS2_REPLACE_METHOD(0x1422D0FB0, UISwfEntityManager, FUN_1422d0fb0, 447, 0x29D8755F);

// @0x1422d1180
void UISwfEntityManager::FUN_1422d1180()
{
    POSITION pos = m_listEntities.GetHeadPosition();
    while (pos)
    {
        POSITION posCur = pos;
        m_listEntities.GetNext(pos);
        UISwfEntity* p = m_listEntities.GetAt(posCur);
        if (p)
            p->FUN_1422dc1e0();
    }
}
MS2_REPLACE_METHOD(0x1422D1180, UISwfEntityManager, FUN_1422d1180, 137, 0x76CDEFD4);

// @0x1422d1210
CString UISwfEntityManager::FUN_1422d1210(int nGroup, CString& strKey, const CString& strPath, int a1, int a2)
{
    if (SingletonClass<UniqueSwfIDCreator>::GetInstance()->FUN_1422f6ac0(strKey, strPath, a2 == 0))
    {
        MS2Ptr<ASMovieClipLoader> spLoader = FUN_14025e7a0()->FUN_1422b03f0(nGroup);
        if (spLoader.get())
            spLoader->FUN_1422d0370(strPath, strKey, a1);
        return strKey;
    }
    return s_strNoSwfKey;
}
MS2_REPLACE_METHOD(0x1422D1210, UISwfEntityManager, FUN_1422d1210, 256, 0x9D665494);

// @0x1422d1320
CString UISwfEntityManager::FUN_1422d1320(int nGroup, CString& strKey, const CString& strPath, int a1, int a2,
                                          int a3, UISwfEntity* pEntity)
{
    if (m_09)
        return s_strNoSwfKey;
    if (SingletonClass<UniqueSwfIDCreator>::GetInstance()->FUN_1422f6ac0(strKey, strPath, 0))
    {
        MS2Ptr<ASMovieClipLoader> spLoader = FUN_14025e7a0()->FUN_1422b03f0(nGroup);
        if (spLoader.get())
        {
            if (SingletonClass<UniqueSwfIDCreator>::GetInstance()->FUN_1422f6fc0(strKey))
            {
                spLoader->FUN_1422d0440(strPath, strKey, a1);
            }
            else
            {
                spLoader->FUN_1422d0070(strPath, strKey, a1, a2);
                if (pEntity)
                {
                    MS2Ptr<UISwfEntity> sp(pEntity);
                    POSITION pos = m_listLoaded.AddTail(sp);
                    m_mapLoaded.SetAt(strKey, pos);
                }
            }
            if (nGroup == 0)
                FUN_14015eb90(FUN_140166440(), 0xc, 0x13, L"LoadSwf[GFX_HUD][{0}]", strPath);
            else if (nGroup == 2)
                FUN_14015eb90(FUN_140166440(), 0xc, 0x13, L"LoadSwf[GFX_Main][{0}]", strPath);
            else if (nGroup == 3)
                FUN_14015eb90(FUN_140166440(), 0xc, 0x13, L"LoadSwf[GFX_PostDisplay][{0}]", strPath);
            else if (nGroup == 4)
                FUN_14015eb90(FUN_140166440(), 0xc, 0x13, L"LoadSwf[GFX_Background][{0}]", strPath);
            else if (nGroup == 5)
                FUN_14015eb90(FUN_140166440(), 0xc, 0x13, L"LoadSwf[GFX_Tooltip][{0}]", strPath);
            else if (nGroup == 6)
                FUN_14015eb90(FUN_140166440(), 0xc, 0x13, L"LoadSwf[GFX_MouseCursor][{0}]", strPath);
        }
        return strKey;
    }
    return s_strNoSwfKey;
}
MS2_REPLACE_METHOD(0x1422D1320, UISwfEntityManager, FUN_1422d1320, 917, 0x207A485C);

// @0x1422d16c0
CString UISwfEntityManager::FUN_1422d16c0(int nGroup, CString& strKey, const CString& strPath, int a1)
{
    FUN_1422d1210(nGroup, strKey, strPath, a1, 0);
    return FUN_1422d1320(nGroup, strKey, strPath, a1, 0, 0, 0);
}
MS2_REPLACE_METHOD(0x1422D16C0, UISwfEntityManager, FUN_1422d16c0, 207, 0x424D9D96);

// @0x1422d17a0
CString UISwfEntityManager::FUN_1422d17a0(int nGroup, CString strKey, int n)
{
    int bFixed = SingletonClass<UniqueSwfIDCreator>::GetInstance()->FUN_1422f6fc0(strKey);
    if (bFixed)
    {
        MS2Ptr<ASMovieClipLoader> spLoader = FUN_14025e7a0()->FUN_1422b03f0(nGroup);
        if (spLoader.get())
            spLoader->FUN_1422d0510(strKey, n);
    }
    else if (SingletonClass<UniqueSwfIDCreator>::GetInstance()->FUN_1422f6c90(strKey))
    {
        MS2Ptr<ASMovieClipLoader> spLoader = FUN_14025e7a0()->FUN_1422b03f0(nGroup);
        if (spLoader.get())
        {
            spLoader->FUN_1422d01b0(strKey, n);
            POSITION pos = 0;
            if (m_mapLoaded.Lookup(strKey, pos))
                m_mapUnloading.SetAt(strKey, pos);
        }
    }
    return s_strNoSwfKey;
}
MS2_REPLACE_METHOD(0x1422D17A0, UISwfEntityManager, FUN_1422d17a0, 540, 0x7FF69715);

// @0x1422d19d0
void UISwfEntityManager::FUN_1422d19d0(const CString& strClass)
{
    POSITION pos = m_listEntities.GetHeadPosition();
    int bFound = 0;
    while (pos)
    {
        bFound = 0;
        UISwfEntity* p = m_listEntities.GetAt(pos);
        if (p)
        {
            if (p->vfunc_1() == strClass)
                bFound = 1;
            if (bFound)
            {
                p->FUN_1422dc080();
                POSITION posCur = pos;
                m_listEntities.GetNext(pos);
                m_listEntities.RemoveAt(posCur);
            }
            else
            {
                m_listEntities.GetNext(pos);
            }
        }
        else
        {
            m_listEntities.GetNext(pos);
        }
    }
}
MS2_REPLACE_METHOD(0x1422D19D0, UISwfEntityManager, FUN_1422d19d0, 325, 0x651775BB);

// @0x1422d1b20
void UISwfEntityManager::FUN_1422d1b20(int nGroup, const CString& strKey, int n)
{
    MS2Ptr<ASMovieClipLoader> spLoader = FUN_14025e7a0()->FUN_1422b03f0(nGroup);
    if (spLoader.get())
        spLoader->FUN_1422d0270(strKey, n);
}
MS2_REPLACE_METHOD(0x1422D1B20, UISwfEntityManager, FUN_1422d1b20, 115, 0x242A8A6B);

// @0x1422d1ba0
void UISwfEntityManager::FUN_1422d1ba0()
{
    POSITION pos = m_listEntities.GetHeadPosition();
    while (pos)
    {
        UISwfEntity* p = m_listEntities.GetNext(pos);
        if (p)
            p->vfunc_10();
    }
    FUN_1422d0fb0();
}
MS2_REPLACE_METHOD(0x1422D1BA0, UISwfEntityManager, FUN_1422d1ba0, 119, 0xBD80DBF9);

// @0x1422d1c20
int UISwfEntityManager::FUN_1422d1c20()
{
    if (m_pfnInputTaken && m_pfnInputTaken())
        return 1;
    int bTextInput = FUN_14025e7a0()->FUN_1422af2d0(2);
    int bInput = FUN_14025e7a0()->FUN_1422af7a0(2);
    for (int i = 0; i < 5; i++)
    {
        POSITION pos = m_listLayers[i].GetTailPosition();
        while (pos)
        {
            POSITION posCur = pos;
            m_listLayers[i].GetPrev(pos);
            MS2Ptr<UISwfEntity> sp(m_listLayers[i].GetAt(posCur));
            if (sp)
            {
                MS2Ptr<UISceneEntity> spScene(dynamic_cast<UISceneEntity*>(sp.get()));
                if (spScene)
                    continue;
                if (bTextInput && !sp->FUN_1422dc3d0())
                    continue;
                if (bInput)
                    continue;
                if (sp->vfunc_9())
                {
                    if (sp->vfunc_13())
                        return 1;
                }
                else
                {
                    if (sp->vfunc_14())
                        return 1;
                }
            }
        }
    }
    POSITION pos = m_listScenes.GetHeadPosition();
    while (pos)
    {
        POSITION posCur = pos;
        m_listScenes.GetNext(pos);
        UISceneEntity* p = m_listScenes.GetAt(posCur);
        if (p)
        {
            if (!p->FUN_1422e7970())
                continue;
            if (bTextInput && !p->FUN_1422dc3d0())
                continue;
            if (p->vfunc_9())
            {
                if (p->vfunc_13())
                    return 1;
            }
            else
            {
                if (p->vfunc_14())
                    return 1;
            }
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1422D1C20, UISwfEntityManager, FUN_1422d1c20, 1009, 0xD9E90AAA);

// @0x1422d2020
void UISwfEntityManager::FUN_1422d2020()
{
    FUN_1422d2250();
    POSITION pos = m_listLoaded.GetHeadPosition();
    while (pos)
    {
        POSITION posCur = pos;
        m_listLoaded.GetNext(pos);
        MS2Ptr<UISwfEntity> sp(FUN_1422d4af0(posCur));
        if (sp)
        {
            MS2Ptr<UISceneEntity> spScene(dynamic_cast<UISceneEntity*>(sp.get()));
            if ((bool)spScene && !spScene->FUN_1422e7970())
                continue;
            sp->vfunc_15();
        }
    }
    if (SingletonClass<UIAlignWidgetManager>::GetInstance())
        SingletonClass<UIAlignWidgetManager>::GetInstance()->FUN_1422e6d30();
}
MS2_REPLACE_METHOD(0x1422D2020, UISwfEntityManager, FUN_1422d2020, 390, 0xB27796F8);

// @0x1422d21b0
void UISwfEntityManager::FUN_1422d21b0()
{
    POSITION pos = m_listEntities.GetHeadPosition();
    while (pos)
    {
        POSITION posCur = pos;
        m_listEntities.GetNext(pos);
        UISwfEntity* p = m_listEntities.GetAt(posCur);
        if (p)
            p->vfunc_19();
    }
}
MS2_REPLACE_METHOD(0x1422D21B0, UISwfEntityManager, FUN_1422d21b0, 146, 0xA6AFA4D9);

// @0x1422d2250
void UISwfEntityManager::FUN_1422d2250()
{
    if (m_mapUnloading.IsEmpty())
        return;
    for (POSITION pos = m_mapUnloading.GetStartPosition(); pos; m_mapUnloading.GetNext(pos))
    {
        m_listLoaded.RemoveAt(m_mapUnloading.GetValueAt(pos));
        m_mapLoaded.RemoveKey(m_mapUnloading.GetKeyAt(pos));
    }
    m_mapUnloading.RemoveAll();
}
MS2_REPLACE_METHOD(0x1422D2250, UISwfEntityManager, FUN_1422d2250, 218, 0x800210E7);

// @0x1422d2330
void UISwfEntityManager::vfunc_1()
{
    POSITION pos = m_listLoaded.GetHeadPosition();
    while (pos)
    {
        POSITION posCur = pos;
        m_listLoaded.GetNext(pos);
        UISwfEntity* p = FUN_1422d4af0(posCur);
        if (p)
            p->FUN_1422dc450();
    }
}
MS2_REPLACE_METHOD(0x1422D2330, UISwfEntityManager, vfunc_1, 120, 0x480BC708);

// @0x1422d23b0
void UISwfEntityManager::vfunc_2()
{
    POSITION pos = m_listLoaded.GetHeadPosition();
    while (pos)
    {
        POSITION posCur = pos;
        m_listLoaded.GetNext(pos);
        MS2Ptr<UISwfEntity> sp(FUN_1422d4af0(posCur));
        if (sp)
        {
            MS2Ptr<UISceneEntity> spScene(dynamic_cast<UISceneEntity*>(sp.get()));
            if ((bool)spScene && !spScene->FUN_1422e7970())
                continue;
            sp->vfunc_11();
        }
    }
}
MS2_REPLACE_METHOD(0x1422D23B0, UISwfEntityManager, vfunc_2, 354, 0xD666BB04);

// @0x1422d2520
void UISwfEntityManager::vfunc_3()
{
    POSITION pos = m_listLoaded.GetHeadPosition();
    while (pos)
    {
        POSITION posCur = pos;
        m_listLoaded.GetNext(pos);
        MS2Ptr<UISwfEntity> sp(FUN_1422d4af0(posCur));
        if (sp)
        {
            MS2Ptr<UISceneEntity> spScene(dynamic_cast<UISceneEntity*>(sp.get()));
            if ((bool)spScene && !spScene->FUN_1422e7970())
                continue;
            sp->vfunc_12();
        }
    }
}
MS2_REPLACE_METHOD(0x1422D2520, UISwfEntityManager, vfunc_3, 354, 0x8D3A967F);

// @0x1422d2690
void UISwfEntityManager::vfunc_4()
{
    POSITION pos = m_listLoaded.GetHeadPosition();
    while (pos)
    {
        POSITION posCur = pos;
        m_listLoaded.GetNext(pos);
        UISwfEntity* p = FUN_1422d4af0(posCur);
        if (p)
            p->vfunc_16();
    }
}
MS2_REPLACE_METHOD(0x1422D2690, UISwfEntityManager, vfunc_4, 129, 0x06580766);

// @0x1422d2720
bool UISwfEntityManager::vfunc_5()
{
    POSITION pos = m_listLoaded.GetHeadPosition();
    while (pos)
    {
        POSITION posCur = pos;
        m_listLoaded.GetNext(pos);
        UISwfEntity* p = FUN_1422d4af0(posCur);
        if (p && !p->vfunc_17())
            return false;
    }
    vfunc_1();
    return true;
}
MS2_REPLACE_METHOD(0x1422D2720, UISwfEntityManager, vfunc_5, 158, 0xE9799BD9);

// @0x1422d27d0
void UISwfEntityManager::vfunc_6()
{
    POSITION pos = m_listEntities.GetHeadPosition();
    while (pos)
    {
        POSITION posCur = pos;
        m_listEntities.GetNext(pos);
        UISwfEntity* p = m_listEntities.GetAt(posCur);
        if (p)
            p->vfunc_18();
    }
}
MS2_REPLACE_METHOD(0x1422D27D0, UISwfEntityManager, vfunc_6, 146, 0xFAFF5059);

// @0x1422d2870
void UISwfEntityManager::vfunc_7(CString strKey, Scaleform::GFx::Value vRoot)
{
    MS2Ptr<UISwfEntity> sp = FUN_1422d41b0(strKey);
    if (sp)
    {
        sp->vfunc_41(vRoot);
        if (sp->FUN_1422dba00().get())
        {
            sp->FUN_1422dc2b0(1);
            sp->OnLoadInit();
        }
    }
}
MS2_REPLACE_METHOD(0x1422D2870, UISwfEntityManager, vfunc_7, 289, 0xED1031FA);

// @0x1422d29a0
void UISwfEntityManager::vfunc_8(CString strKey, Scaleform::GFx::Value vRoot)
{
    MS2Ptr<UISwfEntity> sp = FUN_1422d41b0(strKey);
    if (sp)
        sp->vfunc_21();
}
MS2_REPLACE_METHOD(0x1422D29A0, UISwfEntityManager, vfunc_8, 137, 0x67E86BE0);

// @0x1422d2a30
void UISwfEntityManager::vfunc_9(CString strKey, Scaleform::GFx::Value vRoot, float fTime)
{
    MS2Ptr<UISwfEntity> sp = FUN_1422d41b0(strKey);
    if (sp)
    {
        if (sp->FUN_1422dc410())
        {
            FUN_1422d17a0(sp->FUN_1422db730(), strKey, sp->FUN_1422db750());
            FUN_140b632f0()->FUN_1422d0dc0(sp);
        }
        else
        {
            sp->FUN_1422dc370(1);
            try
            {
                sp->OnLoadComplete();
            }
            catch (GfxExceptionSwfLoad* e)
            {
                sp->vfunc_42(e);
            }
            sp->vfunc_46();
        }
    }
}
MS2_REPLACE_METHOD(0x1422D2A30, UISwfEntityManager, vfunc_9, 486, 0xC7F642AC);

// @0x1422d2c20
void UISwfEntityManager::vfunc_10(CString strKey, Scaleform::GFx::Value vRoot, void* p)
{
    MS2Ptr<UISwfEntity> sp = FUN_1422d41b0(strKey);
    if (sp)
        sp->vfunc_23(p);
}
MS2_REPLACE_METHOD(0x1422D2C20, UISwfEntityManager, vfunc_10, 147, 0xCB883843);

// @0x1422d2cc0
void UISwfEntityManager::vfunc_11(CString strKey, Scaleform::GFx::Value vRoot, float x, float y)
{
    MS2Ptr<UISwfEntity> sp = FUN_1422d41b0(strKey);
    if (sp)
        sp->vfunc_24(x, y);
}
MS2_REPLACE_METHOD(0x1422D2CC0, UISwfEntityManager, vfunc_11, 155, 0x3E487F78);

// @0x1422d2d70
void UISwfEntityManager::vfunc_12(const CString& a1, const CString& a2, const CString& a3)
{
    POSITION pos = m_listLoaded.GetHeadPosition();
    while (pos)
    {
        POSITION posCur = pos;
        m_listLoaded.GetNext(pos);
        MS2Ptr<UISwfEntity> sp(FUN_1422d4af0(posCur));
        if (sp && sp->FUN_1422dc390())
        {
            MS2Ptr<UISceneEntity> spScene(dynamic_cast<UISceneEntity*>(sp.get()));
            if ((bool)spScene && !spScene->FUN_1422e7970())
                continue;
            sp->vfunc_30(a1, a2, a3);
        }
    }
}
MS2_REPLACE_METHOD(0x1422D2D70, UISwfEntityManager, vfunc_12, 443, 0x2FF86674);

// @0x1422d2f40
void UISwfEntityManager::vfunc_13(const CString& a1, float a2, const void* a3)
{
    POSITION pos = m_listLoaded.GetHeadPosition();
    while (pos)
    {
        POSITION posCur = pos;
        m_listLoaded.GetNext(pos);
        MS2Ptr<UISwfEntity> sp(FUN_1422d4af0(posCur));
        if (sp && sp->FUN_1422dc390())
        {
            MS2Ptr<UISceneEntity> spScene(dynamic_cast<UISceneEntity*>(sp.get()));
            if ((bool)spScene && !spScene->FUN_1422e7970())
                continue;
            sp->vfunc_31(a1, a2, a3);
        }
    }
}
MS2_REPLACE_METHOD(0x1422D2F40, UISwfEntityManager, vfunc_13, 445, 0x599770F7);

// The mouse events go to the visible loaded movies; a scene only while it is shown.
#define MS2_UISWFENTITYMANAGER_MOUSE(name, slot, params, args)                                  \
    void UISwfEntityManager::name params                                                        \
    {                                                                                           \
        POSITION pos = m_listLoaded.GetHeadPosition();                                          \
        while (pos)                                                                             \
        {                                                                                       \
            POSITION posCur = pos;                                                              \
            m_listLoaded.GetNext(pos);                                                          \
            MS2Ptr<UISwfEntity> sp(FUN_1422d4af0(posCur));                                      \
            if (sp && sp->vfunc_9())                                                            \
            {                                                                                   \
                MS2Ptr<UISceneEntity> spScene(dynamic_cast<UISceneEntity*>(sp.get()));         \
                if (spScene)                                                                    \
                {                                                                               \
                    if (spScene->FUN_1422e7970())                                               \
                        spScene->slot args;                                                     \
                }                                                                               \
                else                                                                            \
                {                                                                               \
                    sp->slot args;                                                              \
                }                                                                               \
            }                                                                                   \
        }                                                                                       \
    }

// @0x1422d3110
MS2_UISWFENTITYMANAGER_MOUSE(vfunc_14, vfunc_32, (void* p, float x, float y), (p, x, y))
MS2_REPLACE_METHOD(0x1422D3110, UISwfEntityManager, vfunc_14, 478, 0x8A30D9EF);
// @0x1422d3300
MS2_UISWFENTITYMANAGER_MOUSE(vfunc_15, vfunc_33, (void* p, float x, float y), (p, x, y))
MS2_REPLACE_METHOD(0x1422D3300, UISwfEntityManager, vfunc_15, 478, 0xB78D2178);
// @0x1422d34f0
MS2_UISWFENTITYMANAGER_MOUSE(vfunc_16, vfunc_34, (void* p, float x, float y), (p, x, y))
MS2_REPLACE_METHOD(0x1422D34F0, UISwfEntityManager, vfunc_16, 478, 0xCAF89A40);
// @0x1422d36e0
MS2_UISWFENTITYMANAGER_MOUSE(vfunc_17, vfunc_35, (void* p, float x, float y), (p, x, y))
MS2_REPLACE_METHOD(0x1422D36E0, UISwfEntityManager, vfunc_17, 478, 0x91480478);
// @0x1422d38d0
MS2_UISWFENTITYMANAGER_MOUSE(vfunc_18, vfunc_36, (void* p, float x, float y), (p, x, y))
MS2_REPLACE_METHOD(0x1422D38D0, UISwfEntityManager, vfunc_18, 478, 0xD37FEF42);
// @0x1422d3ac0
MS2_UISWFENTITYMANAGER_MOUSE(vfunc_19, vfunc_37, (void* p, float x, float y), (p, x, y))
MS2_REPLACE_METHOD(0x1422D3AC0, UISwfEntityManager, vfunc_19, 478, 0xA573ABB8);
// @0x1422d3cb0
MS2_UISWFENTITYMANAGER_MOUSE(vfunc_20, vfunc_38, (void* p, float x, float y), (p, x, y))
MS2_REPLACE_METHOD(0x1422D3CB0, UISwfEntityManager, vfunc_20, 478, 0xF9170D08);
// @0x1422d3ea0
MS2_UISWFENTITYMANAGER_MOUSE(vfunc_21, vfunc_39, (void* p, float x, float y, float f), (p, x, y, f))
MS2_REPLACE_METHOD(0x1422D3EA0, UISwfEntityManager, vfunc_21, 508, 0x6351E8D7);

// @0x1422d40b0
UISwfEntity* UISwfEntityManager::FUN_1422d40b0(int nId)
{
    POSITION pos = m_listScenes.GetHeadPosition();
    while (pos)
    {
        POSITION posCur = pos;
        m_listScenes.GetNext(pos);
        MS2Ptr<UISceneEntity> sp(m_listScenes.GetAt(posCur));
        if (sp && sp->FUN_1422e7950() == nId)
            return sp;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1422D40B0, UISwfEntityManager, FUN_1422d40b0, 244, 0xEE65AF86);

// @0x1422d41b0
MS2Ptr<UISwfEntity> UISwfEntityManager::FUN_1422d41b0(const CString& strName)
{
    if (strName.GetLength() < 1)
        return MS2Ptr<UISwfEntity>(0);
    MS2Ptr<UISwfEntity> sp;
    POSITION pos = 0;
    if (m_mapLoaded.Lookup(strName, pos))
        return MS2Ptr<UISwfEntity>(FUN_1422d4af0(pos));
    sp = FUN_1422d4580(strName);
    if (!sp)
    {
        FUN_14015eb90(FUN_140166440(), 2, 0x1a, L"UISwfEntityManager::GetUISwfEntity Warning invalid swfID:{0}",
                      strName);
        sp.AssignRaw(FUN_1422d4380(strName));
    }
    return sp;
}
MS2_REPLACE_METHOD(0x1422D41B0, UISwfEntityManager, FUN_1422d41b0, 448, 0xF66E4EDE);

// @0x1422d4380
UISwfEntity* UISwfEntityManager::FUN_1422d4380(const CString& strName)
{
    CString strTrim(strName);
    strTrim.Trim();
    POSITION pos = m_listEntities.GetHeadPosition();
    while (pos)
    {
        POSITION posCur = pos;
        m_listEntities.GetNext(pos);
        MS2Ptr<UISwfEntity> sp(m_listEntities.GetAt(posCur));
        if (sp && sp->vfunc_1().CompareNoCase(strTrim) == 0)
            return sp;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1422D4380, UISwfEntityManager, FUN_1422d4380, 506, 0x332B55D5);

// @0x1422d4580
MS2Ptr<UISwfEntity> UISwfEntityManager::FUN_1422d4580(const CString& strName)
{
    CString strTrim(strName);
    strTrim.Trim();
    POSITION pos = m_listEntities.GetHeadPosition();
    while (pos)
    {
        POSITION posCur = pos;
        m_listEntities.GetNext(pos);
        MS2Ptr<UISwfEntity> sp(m_listEntities.GetAt(posCur));
        if (sp && sp->FUN_1422db6e0().CompareNoCase(strTrim) == 0)
            return sp;
    }
    return MS2Ptr<UISwfEntity>(0);
}
MS2_REPLACE_METHOD(0x1422D4580, UISwfEntityManager, FUN_1422d4580, 503, 0xC86B119A);

// @0x1422d4780
void UISwfEntityManager::FUN_1422d4780(UISwfEntity* p, int nLayer)
{
    POSITION pos = m_listLayers[nLayer].Find(p);
    if (!pos)
        m_listLayers[nLayer].AddTail(p);
}
MS2_REPLACE_METHOD(0x1422D4780, UISwfEntityManager, FUN_1422d4780, 171, 0xEAAF0D08);

// @0x1422d4840
void UISwfEntityManager::FUN_1422d4840(UISwfEntity* p, int nLayer)
{
    POSITION pos = m_listLayers[nLayer].Find(p);
    if (pos)
        m_listLayers[nLayer].RemoveAt(pos);
    if (nLayer != 1)
        FUN_1422d4840(p, 1);
}
MS2_REPLACE_METHOD(0x1422D4840, UISwfEntityManager, FUN_1422d4840, 163, 0x5D4CCB87);

// @0x1422d48f0
void UISwfEntityManager::FUN_1422d48f0(UISwfEntity* p, int nLayer)
{
    POSITION pos = m_listLayers[nLayer].Find(p);
    if (pos)
        m_listLayers[nLayer].MoveToTail(pos);
}
MS2_REPLACE_METHOD(0x1422D48F0, UISwfEntityManager, FUN_1422d48f0, 135, 0x87E6EA4C);

// @0x1422d4980
UISwfEntity* UISwfEntityManager::FUN_1422d4980(int nLayer)
{
    if (m_listLayers[nLayer].IsEmpty())
        return 0;
    return m_listLayers[nLayer].GetTail();
}
MS2_REPLACE_METHOD(0x1422D4980, UISwfEntityManager, FUN_1422d4980, 97, 0xFA6B2D4F);

// @0x1422d49f0
void UISwfEntityManager::FUN_1422d49f0()
{
    FUN_1422d4a30(!m_0a);
}
MS2_REPLACE_METHOD(0x1422D49F0, UISwfEntityManager, FUN_1422d49f0, 54, 0x6E91C6F8);

// @0x1422d4a30
void UISwfEntityManager::FUN_1422d4a30(bool b)
{
    m_0a = b;
    FUN_14025e7a0()->FUN_1422aed30(m_0a);
}
MS2_REPLACE_METHOD(0x1422D4A30, UISwfEntityManager, FUN_1422d4a30, 53, 0x12F58206);

// @0x1422d4a70
int UISwfEntityManager::FUN_1422d4a70(POSITION pos)
{
    for (POSITION posMap = m_mapUnloading.GetStartPosition(); posMap; m_mapUnloading.GetNext(posMap))
    {
        if (m_mapUnloading.GetValueAt(posMap) == pos)
            return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1422D4A70, UISwfEntityManager, FUN_1422d4a70, 122, 0xF48CD337);

// @0x1422d4af0
UISwfEntity* UISwfEntityManager::FUN_1422d4af0(POSITION pos)
{
    if (FUN_1422d4a70(pos))
        return 0;
    return m_listLoaded.GetAt(pos);
}
MS2_REPLACE_METHOD(0x1422D4AF0, UISwfEntityManager, FUN_1422d4af0, 74, 0x8F2E1412);

// @0x1422d4b40
void UISwfEntityManager::FUN_1422d4b40(int (*pfn)())
{
    m_pfnInputTaken = pfn;
}
MS2_REPLACE_METHOD(0x1422D4B40, UISwfEntityManager, FUN_1422d4b40, 28, 0x441A3819);

// @0x1422d4b70
void UISwfEntityManager::FUN_1422d4b70(bool bShow)
{
    FUN_1422d0bf0(bShow);
    if (bShow)
        FUN_1422d4bb0();
}
MS2_REPLACE_METHOD(0x1422D4B70, UISwfEntityManager, FUN_1422d4b70, 52, 0x49080477);

// @0x1422d4bb0
void UISwfEntityManager::FUN_1422d4bb0()
{
    POSITION pos = m_listEntities.GetHeadPosition();
    while (pos)
    {
        POSITION posCur = pos;
        m_listEntities.GetNext(pos);
        MS2Ptr<UISwfEntity> sp(m_listEntities.GetAt(posCur));
        if (sp)
        {
            MS2Ptr<UISceneEntity> spScene(dynamic_cast<UISceneEntity*>(sp.get()));
            if (!spScene)
                sp->FUN_1422dc080();
        }
    }
    for (int i = 0; i < 5; i++)
        m_listLayers[i].RemoveAll();
}
MS2_REPLACE_METHOD(0x1422D4BB0, UISwfEntityManager, FUN_1422d4bb0, 335, 0x32CB8DBD);

// @0x1422d4d10
void UISwfEntityManager::FUN_1422d4d10()
{
    POSITION pos = m_listScenes.GetHeadPosition();
    while (pos)
    {
        POSITION posCur = pos;
        m_listScenes.GetNext(pos);
        MS2Ptr<UISceneEntity> sp(m_listScenes.GetAt(posCur));
        if (sp)
            sp->FUN_1422dc080();
    }
}
MS2_REPLACE_METHOD(0x1422D4D10, UISwfEntityManager, FUN_1422d4d10, 173, 0xD4889579);

// @0x1422d4dd0
void UISwfEntityManager::FUN_1422d4dd0(CString strKey)
{
    m_258 = strKey;
}
MS2_REPLACE_METHOD(0x1422D4DD0, UISwfEntityManager, FUN_1422d4dd0, 65, 0x04DCD397);

// @0x1422d4e20
int UISwfEntityManager::FUN_1422d4e20(CString strKey)
{
    if (m_258.Compare(strKey) == 0)
        return 1;
    else
        return 0;
}
MS2_REPLACE_METHOD(0x1422D4E20, UISwfEntityManager, FUN_1422d4e20, 114, 0x910BDE0F);


// The exe calls memset in CAtlMap::Rehash / CRBTree::NewNode (no /Oi expansion): templates are instantiated at the
// end of the TU.
#pragma function(memset)
// Pins: ATL members that have look-alike copies in other units.
// MS2-PIN: ??_GUISwfEntityManager@@UEAAPEAXI@Z 0x1422d57c0
// MS2-PIN: ?GetTail@?$CAtlList@V?$MS2Ptr@VUISwfEntity@@@@V?$CElementTraits@V?$MS2Ptr@VUISwfEntity@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@VUISwfEntity@@@@XZ 0x1422d6600
// MS2-PIN: ?MoveToTail@?$CAtlList@V?$MS2Ptr@VUISwfEntity@@@@V?$CElementTraits@V?$MS2Ptr@VUISwfEntity@@@@@ATL@@@ATL@@QEAAXPEAU__POSITION@@@Z 0x1422d6ca0
// MS2-PIN: ?NewNode@?$CRBTree@V?$MS2Ptr@VUISwfEntity@@@@PEAU__POSITION@@V?$CElementTraits@V?$MS2Ptr@VUISwfEntity@@@@@ATL@@V?$CElementTraits@PEAU__POSITION@@@4@@ATL@@AEAAPEAVCNode@12@AEBV?$MS2Ptr@VUISwfEntity@@@@AEBQEAU__POSITION@@@Z 0x1422d70b0
