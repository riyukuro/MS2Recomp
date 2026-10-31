// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). GFxMovieHeadUpDisplay, the head-up display movie of the GFx
// UI library. See gfxmovieheadupdisplay.h.
// MS2-UNIT: ?\gfxmovieheadupdisplay.cpp
// MS2-RANGE: 0x1422f30b0-0x1422f3990 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings).
#include "ms2/placeholder/ms2stdafx.h"
#include <windowsx.h>

#include "gfxmovieheadupdisplay.h"
#include "uiswfentity.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/gfxmanager.h"

// The UISwfEntityManager slots the movies call (vftable 0x143112518; the shared placeholder declares no virtuals). Both
// take the swf key and the AS root object by value (the callee destroys them).
class Unk_SwfEntityManagerSlots
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7(CString strKey, Scaleform::GFx::Value vRoot);              // 0x1422d2870 swf "loadInit"
    virtual void vfunc_8(CString strKey, Scaleform::GFx::Value vRoot);              // 0x1422d29a0
    virtual void vfunc_9(CString strKey, Scaleform::GFx::Value vRoot, float fTime); // 0x1422d2a30 swf "loadComplete"
};

GFxManager* FUN_14025e7a0();

class CLogString* GetLogString();
template<class T, class U> void Unk_FileLog(CLogString* log, int level, int category, const wchar_t* format,
                                            const T& a0, const U& a1);   // filesystem.cpp


// @0x1422f30b0
GFxMovieHeadUpDisplay::GFxMovieHeadUpDisplay()
{
    m_18 = 0;
}

// @0x1422f30f0
GFxMovieHeadUpDisplay::~GFxMovieHeadUpDisplay()
{
}

// @0x1422f3120
void GFxMovieHeadUpDisplay::vfunc_4(void* pMovie, const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned nArgs)
{
    if (nArgs < 1)
        return;
    GFxMovie::vfunc_4(pMovie, szEvent, pArgs, nArgs);
    if (_stricmp("initializeClass", szEvent) == 0)
    {
        if (nArgs > 1)
        {
            Scaleform::GFx::Value vStage(pArgs[0]);
            Scaleform::GFx::Value vLoader(pArgs[1]);
            FUN_1422be510(FUN_140b62400(m_18, vStage));
            FUN_1422be5b0(FUN_140b62350(m_18, vLoader));
            FUN_14025e7a0()->FUN_1422b0790(m_18);
            FUN_1422be140();
            FUN_1422be2a0();
        }
    }
    else
    {
        const char* szName = pArgs[0].GetString();
        if (_stricmp("loadInit", szName) == 0)
        {
            Scaleform::GFx::Value vRoot(pArgs[1]);
            if (vRoot.IsObject())
                ((Unk_SwfEntityManagerSlots*)FUN_140b632f0())->vfunc_7(szEvent, vRoot);
        }
        else if (_stricmp("loadComplete", szName) == 0)
        {
            Scaleform::GFx::Value vRoot(pArgs[1]);
            if (vRoot.IsObject())
                ((Unk_SwfEntityManagerSlots*)FUN_140b632f0())->vfunc_9(szEvent, vRoot, 0.0f);
        }
        else if (_stricmp("playSound", szName) == 0)
        {
            MS2Ptr<UISwfEntity> spEntity = FUN_140b632f0()->GetUISwfEntity(szEvent);
            if ((spEntity.get() ? true : false) && spEntity->FUN_1422dc390() != 0)
            {
                CString strSound(pArgs[1].GetString());
                spEntity->vfunc_29(&strSound);      // slot 29 takes the sound name (const CString&)
            }
        }
        else
        {
            MS2Ptr<UISwfEntity> spEntity = FUN_140b632f0()->GetUISwfEntity(szEvent);
            if (spEntity.get())
            {
                if (_stricmp("OnTopMostLayer", szName) == 0)
                    FUN_140b632f0()->FUN_1422d4dd0(szEvent);
                if (spEntity->FUN_1422dc390() != 0)
                    spEntity->vfunc_28(szName, &pArgs[1], nArgs - 1);
                else
                    Unk_FileLog(GetLogString(), 2, 0x1a, L"DispatchEvent Warning[{0}][{1}]", szEvent, szName);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1422F3120, GFxMovieHeadUpDisplay, vfunc_4, 1649, 0x3487307D);

// @0x1422f37a0
int GFxMovieHeadUpDisplay::vfunc_14(void* hwnd, unsigned msg, unsigned __int64 wParam, __int64 lParam)
{
    switch (msg)
    {
    case WM_MOUSEMOVE:
        {
            float x = (float)GET_X_LPARAM(lParam);
            float y = (float)GET_Y_LPARAM(lParam);
            vfunc_26(hwnd, x, y);
            return 1;
        }
        break;
    case WM_LBUTTONUP:
        {
            float x = (float)GET_X_LPARAM(lParam);
            float y = (float)GET_Y_LPARAM(lParam);
            ReleaseCapture();
            vfunc_31(hwnd, x, y);
            return 1;
        }
        break;
    case WM_LBUTTONDOWN:
        {
            float x = (float)GET_X_LPARAM(lParam);
            float y = (float)GET_Y_LPARAM(lParam);
            SetCapture((HWND)hwnd);
            vfunc_32(hwnd, x, y);
            return 1;
        }
        break;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1422F37A0, GFxMovieHeadUpDisplay, vfunc_14, 371, 0xC4B53142);

// MS2-PIN: ??_GGFxMovieHeadUpDisplay@@UEAAPEAXI@Z 0x1422f3920
