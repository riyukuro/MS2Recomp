// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). GFxMovieTooltip, the GFx movie of the tooltip layer, and the
// two Scaleform value visitors that deep-copy the tooltip data into it.
// MS2-UNIT: ?\gfxmovietooltip.cpp
// MS2-RANGE: 0x1422f0900-0x1422f2600 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). The
// classes are declared in gfxmovietooltip.h. The obj's COMDAT tail holds the inline adapter ctors/dtors, the SDK's
// Value::operator== / VisitMembers / VisitElements, the CAtlList<Value>::Find/RemoveAt instances, the Ptr<Movie> copy and
// the three-value AScript::Invoke.
#include "ms2/placeholder/ms2stdafx.h"
#include <windowsx.h>
#include <shlwapi.h>

#include "gfxmovietooltip.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/ms2ptr_impl.h"

#include "hook/ms2hook.h"

#pragma comment(lib, "shlwapi.lib")

MS2Ptr<ASUIComponent> FUN_140acca70(int nMovieId, const Scaleform::GFx::Value& v);   // wrap an AS object in an ASUIComponent
void FUN_1422bcc70(Scaleform::GFx::Value* pValue, Scaleform::GFx::Value v);           // *pValue = v (v by value)

// @0x1422f0900
GFxMovieTooltip::GFxMovieTooltip()
    : m_90(0)
{
    m_18 = 5;
}

// @0x1422f0980
GFxMovieTooltip::~GFxMovieTooltip()
{
    if (m_90.get())
        m_90 = 0;
    m_a0.RemoveAll();
}

// @0x1422f0a30
void GFxMovieTooltip::vfunc_11()
{
    if (m_90.get())
        m_90 = 0;
    m_a0.RemoveAll();
    GFxMovieEventHandler::vfunc_11();
}
MS2_REPLACE_METHOD(0x1422F0A30, GFxMovieTooltip, vfunc_11, 88, 0x6BA8227F);

// @0x1422f0a90
void GFxMovieTooltip::vfunc_3(const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned nArgs)
{
    if (m_90 == 0)
        return;
    if (_stricmp("createTooltip", szEvent) == 0)
    {
        if (nArgs < 3)
            return;
        Scaleform::GFx::Value vId(pArgs[0]);
        Scaleform::GFx::Value vA(pArgs[1]);
        Scaleform::GFx::Value vB(pArgs[2]);
        GFxObjectAdapter adapterA(m_60);
        vA.VisitMembers(&adapterA);
        GFxObjectAdapter adapterB(m_60);
        vB.VisitMembers(&adapterB);
        CreateTooltip(vId, adapterA.m_value, adapterB.m_value);
    }
    else if (_stricmp("destroyTooltip", szEvent) == 0)
    {
        if (nArgs < 1)
            return;
        Scaleform::GFx::Value vId(pArgs[0]);
        DestroyTooltip(vId);
    }
}
MS2_REPLACE_METHOD(0x1422F0A90, GFxMovieTooltip, vfunc_3, 605, 0x3CF05D7D);

// @0x1422f0d00
void GFxMovieTooltip::vfunc_4(void* pMovie, const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned nArgs)
{
    if (_stricmp("initializeClass", szEvent) == 0)
    {
        if (nArgs > 0)
        {
            Scaleform::GFx::Value vRoot(pArgs[0]);
            FUN_1422be140();
            FUN_1422be2a0();
            m_90 = FUN_140acca70(m_18, vRoot);
        }
    }
    else if (_stricmp("Tooltip", szEvent) == 0 && nArgs > 1)
    {
        const char* szName = pArgs[0].GetString();
        if (_stricmp("destroyTooltip", szName) == 0)
        {
            Scaleform::GFx::Value vId(pArgs[1]);
            DestroyTooltip(vId);
        }
    }
}
MS2_REPLACE_METHOD(0x1422F0D00, GFxMovieTooltip, vfunc_4, 405, 0x39A02B38);

// @0x1422f0ea0
int GFxMovieTooltip::vfunc_14(void* hwnd, unsigned msg, unsigned __int64 wParam, __int64 lParam)
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
MS2_REPLACE_METHOD(0x1422F0EA0, GFxMovieTooltip, vfunc_14, 371, 0x9DB9DEC6);

// @0x1422f1020
int GFxMovieTooltip::FUN_1422f1020()
{
    if (m_a0.IsEmpty())
        return 0;
    POSITION pos = m_a0.GetHeadPosition();
    while (pos != NULL)
    {
        const Scaleform::GFx::Value& vId = m_a0.GetNext(pos);
        if (m_90.get())
            m_90->Invoke("destroyTooltip", vId);
    }
    m_a0.RemoveAll();
    return 1;
}
MS2_REPLACE_METHOD(0x1422F1020, GFxMovieTooltip, FUN_1422f1020, 293, 0x6731A213);

// @0x1422f1150
void GFxMovieTooltip::CreateTooltip(const Scaleform::GFx::Value& vId, const Scaleform::GFx::Value& vA, const Scaleform::GFx::Value& vB)
{
    POSITION pos = m_a0.Find(vId);
    if (pos == NULL)
        m_a0.AddTail(vId);
    m_90->Invoke("createTooltip", vId, vA, vB);
}
MS2_REPLACE_METHOD(0x1422F1150, GFxMovieTooltip, CreateTooltip, 345, 0x341697FE);

// @0x1422f12b0
void GFxMovieTooltip::DestroyTooltip(const Scaleform::GFx::Value& vId)
{
    POSITION pos = m_a0.Find(vId);
    if (pos != NULL)
        m_a0.RemoveAt(pos);
    if (m_90.get())
        m_90->Invoke("destroyTooltip", vId);
}
MS2_REPLACE_METHOD(0x1422F12B0, GFxMovieTooltip, DestroyTooltip, 235, 0x33C6F17D);

// @0x1422f13b0
void GFxObjectAdapter::Visit(const char* name, const Scaleform::GFx::Value& val)
{
    if (val.IsObject())
    {
        if (val.IsArray())
        {
            GFxArrayAdapter adapter(m_pMovie);
            val.VisitElements(&adapter);
            m_value.SetMember(name, adapter.m_value);
        }
        else
        {
            GFxObjectAdapter adapter(m_pMovie);
            val.VisitMembers(&adapter);
            m_value.SetMember(name, adapter.m_value);
        }
        return;
    }
    if (val.IsString() && StrCmpCA(val.GetString(), "") == 0)
    {
        Scaleform::GFx::Value vEmpty("");
        m_value.SetMember(name, vEmpty);
        return;
    }
    if (val.IsStringW() && StrCmpCW(val.GetStringW(), L"") == 0)
    {
        Scaleform::GFx::Value vEmpty(L"");
        m_value.SetMember(name, vEmpty);
        return;
    }
    if (val.IsString())
    {
        Scaleform::GFx::Value v;
        m_pMovie->CreateString(&v, val.GetString());
        m_value.SetMember(name, v);
    }
    else if (val.IsStringW())
    {
        Scaleform::GFx::Value v;
        m_pMovie->CreateStringW(&v, val.GetStringW());
        m_value.SetMember(name, v);
    }
    else
    {
        m_value.SetMember(name, val);
    }
}
MS2_REPLACE_METHOD(0x1422F13B0, GFxObjectAdapter, Visit, 932, 0xAAF6122C);

// @0x1422f1760
void GFxArrayAdapter::Visit(unsigned idx, const Scaleform::GFx::Value& val)
{
    if (val.IsObject())
    {
        if (val.IsArray())
        {
            GFxArrayAdapter adapter(m_pMovie);
            val.VisitElements(&adapter);
            m_value.SetElement(idx, adapter.m_value);
        }
        else
        {
            GFxObjectAdapter adapter(m_pMovie);
            val.VisitMembers(&adapter);
            m_value.SetElement(idx, adapter.m_value);
        }
        return;
    }
    if (val.IsString() && StrCmpCA(val.GetString(), "") == 0)
    {
        Scaleform::GFx::Value vEmpty("");
        m_value.SetElement(idx, vEmpty);
        return;
    }
    if (val.IsStringW() && StrCmpCW(val.GetStringW(), L"") == 0)
    {
        Scaleform::GFx::Value vEmpty(L"");
        m_value.SetElement(idx, vEmpty);
        return;
    }
    if (val.IsString())
    {
        Scaleform::GFx::Value v;
        m_pMovie->CreateString(&v, val.GetString());
        m_value.SetElement(idx, v);
    }
    else if (val.IsStringW())
    {
        Scaleform::GFx::Value v;
        m_pMovie->CreateStringW(&v, val.GetStringW());
        m_value.SetElement(idx, v);
    }
    else
    {
        m_value.SetElement(idx, val);
    }
}
MS2_REPLACE_METHOD(0x1422F1760, GFxArrayAdapter, Visit, 924, 0x4FD751F1);

// The "createTooltip" call (id and the two copied objects).
// @0x1422f1b50
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, Scaleform::GFx::Value a1, Scaleform::GFx::Value a2, Scaleform::GFx::Value a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bcc70(args.FUN_1409b1f70(0), a1);
    FUN_1422bcc70(args.FUN_1409b1f70(1), a2);
    FUN_1422bcc70(args.FUN_1409b1f70(2), a3);
    return FUN_1422bb8f0(szMethod, args);
}

// MS2-PIN: ??_GGFxMovieTooltip@@UEAAPEAXI@Z 0x1422f2260
// MS2-PIN: ??_GGFxArrayAdapter@@UEAAPEAXI@Z 0x1422f2220
// MS2-FUNCTIONAL: SDK Value::operator== (inline): the GFx UI library was built with /fp:precise (ucomisd + jp on the
// VT_Number case), the per-unit build uses the game's /fp:fast; otherwise identical.
// MS2-PIN: ??8Value@GFx@Scaleform@@QEBA_NAEBV012@@Z 0x1422f1f80
