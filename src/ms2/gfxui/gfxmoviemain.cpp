// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). GFxMovieMain, the main movie of the GFx UI library. See
// gfxmoviemain.h.
// MS2-UNIT: ?\gfxmoviemain.cpp
// MS2-RANGE: 0x1422ef250-0x1422f0900 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings).
#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>

#include "gfxmoviemain.h"
#include "notifybinding.h"
#include "notifydragslot.h"
#include "notifyswfentity.h"
#include "uiswfentity.h"
#include "ms2/placeholder/asmoviecliploader.h"
#include "ms2/placeholder/gfxmanager.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "hook/ms2hook.h"

// The UISwfEntityManager slots the main movie calls (vftable 0x143112518; the shared placeholder declares no
// virtuals). The by-value arguments are destroyed by the callee.
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
    virtual void vfunc_10();
    virtual void vfunc_11();
    // VideoPlayer "OnMovieStatus" (three strings) / "onMovieCuePoint" (name, time, parameters).
    virtual void vfunc_12(const CString& a, const CString& b, const CString& c);
    virtual void vfunc_13(const CString& strName, float fTime, CAtlList<CString>& params);
    virtual void vfunc_14(void* hwnd, float x, float y);
    virtual void vfunc_15(void* hwnd, float x, float y);
    virtual void vfunc_16(void* hwnd, float x, float y);
    virtual void vfunc_17(void* hwnd, float x, float y);
    virtual void vfunc_18(void* hwnd, float x, float y);
    virtual void vfunc_19(void* hwnd, float x, float y);
    virtual void vfunc_20(void* hwnd, float x, float y);                            // mouse move
    virtual void vfunc_21(void* hwnd, float x, float y, float fDelta);                     // mouse wheel
};

class Unk_GfxLog
{
public:
    void FUN_1403a1310(int nLevel, int nCategory, const wchar_t* szFormat, const char* const& a0, const char* const& a1);
};
Unk_GfxLog* FUN_140166440();

const char* FUN_140b63540(const Scaleform::GFx::Value& v);     // Value::GetString
bool FUN_1409b4d40(const Scaleform::GFx::Value& v);            // the value is set

// Defines the callbacks of a new notify handler T (NotifyBinding/NotifyDragSlot/NotifySwfEntity) on the AS object obj
// of movie nMovieId. Instantiated at 0x1422f0470/0x1422f0560/0x1422f0650 (pinned at the end of the file).
template <class T>
void BindNotifyHandler(int nMovieId, Scaleform::GFx::Value& obj)
{
    efd::SmartPointer<Unk_NotifyContext> spContext = FUN_14025e7a0()->FUN_1422b0260();
    if (spContext)
    {
        Scaleform::Ptr<T> spHandler = *new T(spContext);
        if (spHandler)
            spHandler->FUN_1423008f0(nMovieId, obj);
    }
}

// @0x1422ef250
GFxMovieMain::GFxMovieMain()
{
    m_90 = false;
    m_18 = 2;
}

// @0x1422ef2a0
GFxMovieMain::~GFxMovieMain()
{
}

// @0x1422ef2d0
int GFxMovieMain::vfunc_6(MS2_GFX_LOADER* pLoader, CString strPath, int nLoadFlags)
{
    m_90 = false;
    if (GFxMovie::vfunc_6(pLoader, strPath, nLoadFlags) != 0)
    {
        Scaleform::GFx::Event kEvent(Scaleform::GFx::Event::SetFocus);
        m_60->HandleEvent(kEvent);
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1422EF2D0, GFxMovieMain, vfunc_6, 231, 0x4BC7D34C);

// @0x1422ef3c0
void GFxMovieMain::vfunc_4(void* pMovie, const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned nArgs)
{
    if (nArgs < 1)
        return;
    if (!pArgs[0].IsString())
        return;
    GFxMovie::vfunc_4(pMovie, szEvent, pArgs, nArgs);
    if (_stricmp("Main", szEvent) == 0)
    {
        const char* szName = FUN_140b63540(pArgs[0]);
        if (_stricmp("classMemberSendToClient", szName) == 0)
        {
            Scaleform::GFx::Value vStage(pArgs[1]);
            Scaleform::GFx::Value vLoader(pArgs[3]);
            FUN_1422be510(FUN_140b62400(m_18, vStage));
            FUN_1422be5b0(FUN_140b62350(m_18, vLoader));
            FUN_14025e7a0()->FUN_1422b0790(m_18);
            FUN_1422be140();
            FUN_1422be2a0();
            m_90 = true;
        }
        else if (_stricmp("sharedDataInit", szName) == 0)
        {
            Scaleform::GFx::Value vObj(pArgs[1]);
            BindNotifyHandler<NotifyBinding>(m_18, vObj);
        }
        else if (_stricmp("sharedFunctionInit", szName) == 0)
        {
            Scaleform::GFx::Value vDragSlot(pArgs[1]);
            Scaleform::GFx::Value vSwfEntity(pArgs[2]);
            BindNotifyHandler<NotifyDragSlot>(m_18, vDragSlot);
            BindNotifyHandler<NotifySwfEntity>(m_18, vSwfEntity);
        }
    }
    else if (_stricmp("Tooltip", szEvent) == 0)
    {
        GFxMovie* pTooltip = FUN_14025e7a0()->FUN_1422b01a0(5);
        if (pTooltip != 0)
        {
            const char* szMethod = FUN_140b63540(pArgs[0]);
            pTooltip->vfunc_3(szMethod, &pArgs[1], nArgs - 1);
        }
    }
    else if (_stricmp("MouseCursor", szEvent) == 0)
    {
        GFxMovie* pCursor = FUN_14025e7a0()->FUN_1422b01a0(6);
        if (pCursor != 0)
        {
            const char* szMethod = FUN_140b63540(pArgs[0]);
            pCursor->vfunc_3(szMethod, &pArgs[1], nArgs - 1);
        }
    }
    else if (_stricmp("VideoPlayer", szEvent) == 0)
    {
        const char* szName = FUN_140b63540(pArgs[0]);
        if (_stricmp("OnMovieStatus", szName) == 0)
        {
            CString strC(FUN_140b63540(pArgs[3]));
            CString strB(FUN_140b63540(pArgs[2]));
            CString strA(FUN_140b63540(pArgs[1]));
            ((Unk_SwfEntityManagerSlots*)FUN_140b632f0())->vfunc_12(strA, strB, strC);
        }
        else if (_stricmp("onMovieCuePoint", szName) == 0)
        {
            CString strName(FUN_140b63540(pArgs[1]));
            float fTime = (float)pArgs[2].GetNumber();
            CAtlList<CString> params;
            ((Unk_SwfEntityManagerSlots*)FUN_140b632f0())->vfunc_13(strName, fTime, params);
        }
    }
    else
    {
        const char* szName = FUN_140b63540(pArgs[0]);
        if (_stricmp("loadInit", szName) == 0)
        {
            Scaleform::GFx::Value vRoot(pArgs[1]);
            if (FUN_1409b4d40(vRoot))
                ((Unk_SwfEntityManagerSlots*)FUN_140b632f0())->vfunc_7(szEvent, vRoot);
        }
        else if (_stricmp("loadComplete", szName) == 0)
        {
            Scaleform::GFx::Value vRoot(pArgs[1]);
            if (FUN_1409b4d40(vRoot))
                ((Unk_SwfEntityManagerSlots*)FUN_140b632f0())->vfunc_9(szEvent, vRoot, 0.0f);
        }
        else if (_stricmp("playSound", szName) == 0)
        {
            MS2Ptr<UISwfEntity> spEntity = FUN_140b632f0()->FUN_1422d41b0(szEvent);
            if ((spEntity.get() ? true : false) && spEntity->FUN_1422dc390() != 0)
            {
                CString strSound(FUN_140b63540(pArgs[1]));
                spEntity->vfunc_29(&strSound);      // slot 29 takes the sound name (const CString&)
            }
        }
        else
        {
            MS2Ptr<UISwfEntity> spEntity = FUN_140b632f0()->FUN_1422d41b0(szEvent);
            if (spEntity.get())
            {
                if (_stricmp("OnTopMostLayer", szName) == 0)
                    FUN_140b632f0()->FUN_1422d4dd0(szEvent);
                if (spEntity->FUN_1422dc390() != 0)
                    spEntity->vfunc_28(szName, &pArgs[1], nArgs - 1);
                else
                    FUN_140166440()->FUN_1403a1310(2, 0x1a, L"DispatchEvent Warning[{0}][{1}]", szEvent, szName);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1422EF3C0, GFxMovieMain, vfunc_4, 3030, 0xAAB4E01C);

// @0x1422effa0
void GFxMovieMain::vfunc_5(bool bShow)
{
    MS2Ptr<ASMovieClipLoader> spLoader = FUN_1422be4c0();
    if (spLoader.get())
        spLoader->FUN_1409ba030("setVisibleStep", bShow ? 3 : 0);
}
MS2_REPLACE_METHOD(0x1422EFFA0, GFxMovieMain, vfunc_5, 141, 0x82538CCC);

// @0x1422f0040
void GFxMovieMain::vfunc_8(float fTime)
{
    GFxMovieEventHandler::vfunc_8(fTime);
}
MS2_REPLACE_METHOD(0x1422F0040, GFxMovieMain, vfunc_8, 36, 0xD6D44938);

// @0x1422f0070
void GFxMovieMain::vfunc_17(void* hwnd)
{
    GFxMovieEventHandler::vfunc_17(hwnd);
    FUN_1422d8e80(hwnd);
}
MS2_REPLACE_METHOD(0x1422F0070, GFxMovieMain, vfunc_17, 49, 0x216A8A57);

// @0x1422f00b0
void GFxMovieMain::vfunc_26(void* hwnd, float x, float y)
{
    GFxMovieEventHandler::vfunc_26(hwnd, x, y);
    ((Unk_SwfEntityManagerSlots*)FUN_140b632f0())->vfunc_20(hwnd, x, y);
}
MS2_REPLACE_METHOD(0x1422F00B0, GFxMovieMain, vfunc_26, 104, 0x76C80C75);

// @0x1422f0120
void GFxMovieMain::vfunc_30(void* hwnd, float x, float y, float fDelta)
{
    GFxMovieEventHandler::vfunc_30(hwnd, x, y, fDelta);
    ((Unk_SwfEntityManagerSlots*)FUN_140b632f0())->vfunc_21(hwnd, x, y, fDelta);
}
MS2_REPLACE_METHOD(0x1422F0120, GFxMovieMain, vfunc_30, 128, 0x607092EF);

// @0x1422f01b0
void GFxMovieMain::vfunc_31(void* hwnd, float x, float y)
{
    GFxMovieEventHandler::vfunc_31(hwnd, x, y);
    ((Unk_SwfEntityManagerSlots*)FUN_140b632f0())->vfunc_14(hwnd, x, y);
}
MS2_REPLACE_METHOD(0x1422F01B0, GFxMovieMain, vfunc_31, 101, 0xD5F75476);

// @0x1422f0220
void GFxMovieMain::vfunc_32(void* hwnd, float x, float y)
{
    GFxMovieEventHandler::vfunc_32(hwnd, x, y);
    ((Unk_SwfEntityManagerSlots*)FUN_140b632f0())->vfunc_15(hwnd, x, y);
}
MS2_REPLACE_METHOD(0x1422F0220, GFxMovieMain, vfunc_32, 101, 0x17D5C04F);

// @0x1422f0290
void GFxMovieMain::vfunc_33(void* hwnd, float x, float y)
{
    GFxMovieEventHandler::vfunc_33(hwnd, x, y);
    ((Unk_SwfEntityManagerSlots*)FUN_140b632f0())->vfunc_16(hwnd, x, y);
}
MS2_REPLACE_METHOD(0x1422F0290, GFxMovieMain, vfunc_33, 104, 0x196A7CC9);

// @0x1422f0300
void GFxMovieMain::vfunc_34(void* hwnd, float x, float y)
{
    GFxMovieEventHandler::vfunc_34(hwnd, x, y);
    ((Unk_SwfEntityManagerSlots*)FUN_140b632f0())->vfunc_17(hwnd, x, y);
}
MS2_REPLACE_METHOD(0x1422F0300, GFxMovieMain, vfunc_34, 104, 0xFEE35719);

// @0x1422f0370
void GFxMovieMain::vfunc_35(void* hwnd, float x, float y)
{
    GFxMovieEventHandler::vfunc_35(hwnd, x, y);
    ((Unk_SwfEntityManagerSlots*)FUN_140b632f0())->vfunc_18(hwnd, x, y);
}
MS2_REPLACE_METHOD(0x1422F0370, GFxMovieMain, vfunc_35, 104, 0x7E004A01);

// @0x1422f03e0
void GFxMovieMain::vfunc_36(void* hwnd, float x, float y)
{
    GFxMovieEventHandler::vfunc_36(hwnd, x, y);
    ((Unk_SwfEntityManagerSlots*)FUN_140b632f0())->vfunc_19(hwnd, x, y);
}
MS2_REPLACE_METHOD(0x1422F03E0, GFxMovieMain, vfunc_36, 104, 0xBCD85BCE);

// @0x1422f0450
bool GFxMovieMain::FUN_1422f0450()
{
    return m_90;
}
MS2_REPLACE_METHOD(0x1422F0450, GFxMovieMain, FUN_1422f0450, 18, 0x61F4ABA5);

// MS2-PIN: ??_GGFxMovieMain@@UEAAPEAXI@Z 0x1422f0890
