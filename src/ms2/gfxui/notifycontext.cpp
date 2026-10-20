// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). NotifyContext::BindData, a named AS data binding of the GFx
// UI library, and the NotifyContext registry of bindings.
// MS2-UNIT: ?\notifycontext.cpp
// MS2-RANGE: 0x1422c88e0-0x1422cc350 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings).
// BindData is declared in src/ms2/gfxui/dragslot.h, the registry on Unk_NotifyContext (src/ms2/gfxui/notifyhandler.h:
// the name NotifyContext is the namespace around BindData there). A binding pushes its data (vfunc_8) to an AS
// callback (m_value38); the names in m_arr58 are the bindings that depend on it, and FUN_1422c90d0 later tells each
// registered binding whose m_arr58 holds a changed name (vfunc_7). The tail is the CRBMap / std::set template code of
// the registry.
// MS2_THIS_FILE is only needed by ms2recover.h (MS2_FOR_EACH) and never emitted.
#define MS2_THIS_FILE "notifycontext.cpp"

#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/gfxui/dragslot.h"
#include "ms2/gfxui/notifyhandler.h"
#include "ms2/commonfiles/crashmanager.h"
#include "ms2/ms2recover.h"

#include "hook/ms2hook.h"

// CRBTree::NewNode (0x1422ca8a0 / 0x1422cab10) zeroes its nil node with a CRT memset call, not the intrinsic.
#pragma function(memset)

using NotifyContext::BindData;
using Scaleform::GFx::Value;

CCrashManager* FUN_140a44830();         // the crash manager singleton (its log)

// The exe objects; unit_140135ac0.cpp holds their dynamic initializers (as file statics there). The hook DLL binds
// the exe's objects (symbols-manual rows).
#ifndef MS2_HOOK_DLL
std::set<CString> Unk_NotifyContext::ms_setChanged;
std::set<CString> Unk_NotifyContext::ms_setPushed;
CRBMap<CString, efd::SmartPointer<BindData> > Unk_NotifyContext::ms_mapBindings;
#endif

// ---- NotifyContext::BindData --------------------------------------------------------------------------------------------

// @0x1422c88e0
BindData::BindData(const CString& strName)
    : m_strName(strName)
{
}

// @0x1422c8970
BindData::~BindData()
{
}

// @0x1422c89f0
CString BindData::FUN_1422c89f0()
{
    return m_strName;
}
MS2_REPLACE_METHOD(0x1422C89F0, BindData, FUN_1422c89f0, 66, 0xECF52CD8);

// @0x1422c8a40
void BindData::FUN_1422c8a40()
{
    for (unsigned int i = 0; i < m_arr58.GetCount(); ++i)
        Unk_NotifyContext::FUN_1422c9380(m_arr58[i]);
    Unk_NotifyContext::FUN_1422c93e0(m_strName);
}
MS2_REPLACE_METHOD(0x1422C8A40, BindData, FUN_1422c8a40, 114, 0x0B236149);

// @0x1422c8ac0
int BindData::FUN_1422c8ac0(const CString& strName)
{
    for (unsigned int i = 0; i < m_arr58.GetCount(); ++i)
    {
        if (m_arr58[i] == strName)
            return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1422C8AC0, BindData, FUN_1422c8ac0, 123, 0x9906C579);

// @0x1422c8b50
void BindData::FUN_1422c8b50()
{
    if (m_value38.IsClosure())
    {
        Value v;
        v.SetNull();
        m_value38.InvokeSelf(NULL, &v, 1);
        FUN_1422c8a40();
        m_arr58.RemoveAll();
    }
}
MS2_REPLACE_METHOD(0x1422C8B50, BindData, FUN_1422c8b50, 136, 0xB0A6362F);

// @0x1422c8be0
void BindData::FUN_1422c8be0()
{
    if (m_value38.IsClosure())
    {
        Value v;
        v.SetNull();
        vfunc_8(&v);
        m_value38.InvokeSelf(NULL, &v, 1);
        m_arr58.RemoveAll();
        vfunc_6(&m_arr58);
        FUN_1422c8a40();
    }
}
MS2_REPLACE_METHOD(0x1422C8BE0, BindData, FUN_1422c8be0, 199, 0x29681822);

// @0x1422c8cb0
void BindData::FUN_1422c8cb0(const Value& v)
{
    m_value18 = v;
    if (!m_value18.IsNull())
        vfunc_9();
}
MS2_REPLACE_METHOD(0x1422C8CB0, BindData, FUN_1422c8cb0, 81, 0x3A980BB3);

// @0x1422c8d10
void BindData::FUN_1422c8d10(const Value& v)
{
    m_value38 = v;
}
MS2_REPLACE_METHOD(0x1422C8D10, BindData, FUN_1422c8d10, 41, 0xBCD8186A);

// @0x1422c8d40
Value& BindData::FUN_1422c8d40()
{
    return m_value18;
}
MS2_REPLACE_METHOD(0x1422C8D40, BindData, FUN_1422c8d40, 15, 0x271C8F51);

// @0x1422c8d60
void BindData::vfunc_5()
{
}

// @0x1422c8d70
void BindData::vfunc_6(void* p)
{
}

// @0x1422c8d90
int BindData::vfunc_7(void* p)
{
    return 1;
}

// @0x1422c8db0
int BindData::vfunc_8(void* p)
{
    return 0;
}

// @0x1422c8dd0
void BindData::vfunc_9()
{
}

// ---- the registry -------------------------------------------------------------------------------------------------------

// @0x1422c8de0
void Unk_NotifyContext::FUN_1422c8de0()
{
    if (ms_mapBindings.GetCount() != 0)
    {
        FUN_140a44830()->FUN_1401ce2b0("\n--- NotifyContext Log ---");
        for (POSITION pos = ms_mapBindings.GetHeadPosition(); pos != NULL; ms_mapBindings.GetNext(pos))
            FUN_140a44830()->FUN_1401ce2f0("Unremoved binding slot : %s", (const char*)ms_mapBindings.GetKeyAt(pos));
    }
    FUN_1422c9010();
}

// @0x1422c8e90
BindData* Unk_NotifyContext::FUN_1422c8e90(const CString& strName)
{
    efd::SmartPointer<BindData> spData = NULL;
    if (ms_mapBindings.Lookup(strName, spData))
        return spData;
    return NULL;
}

// @0x1422c8f10
void Unk_NotifyContext::FUN_1422c8f10(const CString& strName, BindData* pData)
{
    ms_mapBindings.SetAt(strName, pData);
}

// @0x1422c8f70
void Unk_NotifyContext::FUN_1422c8f70(const CString& strName)
{
    efd::SmartPointer<BindData> spData = NULL;
    if (ms_mapBindings.Lookup(strName, spData))
    {
        spData->FUN_1422c8b50();
        spData->vfunc_5();
        ms_mapBindings.RemoveKey(strName);
    }
}

// @0x1422c9010
void Unk_NotifyContext::FUN_1422c9010()
{
    for (POSITION pos = ms_mapBindings.GetHeadPosition(); pos != NULL; ms_mapBindings.GetNext(pos))
    {
        efd::SmartPointer<BindData> spData = ms_mapBindings.GetValueAt(pos);
        if (spData)
        {
            spData->FUN_1422c8b50();
            spData->vfunc_5();
        }
    }
    ms_mapBindings.RemoveAll();
}

// @0x1422c90d0
void Unk_NotifyContext::FUN_1422c90d0()
{
    CRBMap<efd::SmartPointer<BindData>, CString> mapNotify;
    // a range-for over the set as const: the exe calls the const begin()/end() COMDATs 0x1422cc2c0/0x1422cc310
    for (const CString& strChanged : static_cast<const std::set<CString>&>(ms_setChanged))
    {
        for (POSITION pos = ms_mapBindings.GetHeadPosition(); pos != NULL; ms_mapBindings.GetNext(pos))
        {
            efd::SmartPointer<BindData> spData = ms_mapBindings.GetValueAt(pos);
            if (!spData)
                continue;
            CString strName = spData->FUN_1422c89f0();
            if (ms_setPushed.find(strName) != ms_setPushed.end())
                continue;
            if (spData->FUN_1422c8ac0(strChanged))
                mapNotify.SetAt(spData, strChanged);
        }
    }
    for (POSITION pos = mapNotify.GetHeadPosition(); pos != NULL; mapNotify.GetNext(pos))
    {
        efd::SmartPointer<BindData> spData = mapNotify.GetKeyAt(pos);
        CString strName = mapNotify.GetValueAt(pos);
        spData->vfunc_7(&strName);
    }
    ms_setChanged.clear();
    ms_setPushed.clear();
}

// @0x1422c9380
void Unk_NotifyContext::FUN_1422c9380(const CString& strName)
{
    if (strName.IsEmpty())
        return;
    if (strName == "0")
        return;
    ms_setChanged.insert(strName);
}

// @0x1422c93e0
void Unk_NotifyContext::FUN_1422c93e0(const CString& strName)
{
    if (strName.IsEmpty())
        return;
    if (strName == "0")
        return;
    ms_setPushed.insert(strName);
}

// MS2-PIN: ??_GBindData@NotifyContext@@UEAAPEAXI@Z 0x1422c9a80
