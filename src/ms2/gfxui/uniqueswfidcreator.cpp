// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UniqueSwfIDCreator, the GFx movie id generator of the GFx UI
// library.
// MS2-UNIT: ?\uniqueswfidcreator.cpp
// MS2-RANGE: 0x1422f69e0-0x1422f7190 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). The
// class is declared in src/ms2/placeholder/uniqueswfidcreator.h. The obj's COMDAT tail: SingletonClass's ctor 0x1422f7020,
// the EE_DECLARE_CLASS inlines (GetClassDesc 0x1422f7060, SetupClassInfo 0x1422f70b0, TypeCast 0x1422f70f0 / 0x1422f7140)
// and CAtlMap<CString, unsigned>::Lookup 0x1422f7070.
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/uniqueswfidcreator.h"

#include "hook/ms2hook.h"

extern CString DAT_143b0dc28;           // "" (the id of an empty file name)
extern CString DAT_143b0dc30;           // "" (the id of an empty extension)

// ms_ClassInfo's initializer (EE_IMPLEMENT_CONCRETE_CLASS_INFO) lives in unit_14013acc0.cpp's .text$di range; this
// reference emits the SetupClassInfo inline here, where the exe has it (0x1422f70b0).
static efd::ClassInfo::CLASSINFO_FUNC s_pfnSetupClassInfo = &UniqueSwfIDCreator::SetupClassInfo;

// @0x1422f69e0
UniqueSwfIDCreator::UniqueSwfIDCreator()
    : m_list10(10)
    , m_mapCount(17, 0.75f, 0.25f, 2.25f, 10)
    , m_listIds(10)
    , m_mapExtCount(10)
    , m_mapFixed(10)
{
}

// @0x1422f6ac0
int UniqueSwfIDCreator::FUN_1422f6ac0(CString& strId, const CString& strFile, int bFixed)
{
    if (!strFile.IsEmpty()) {
        CString strName(strFile);
        strName.Replace(".swf", "");
        if (FUN_1422f6fc0(strName) || bFixed != 0) {
            strId = strName;
            if (bFixed != 0)
                m_mapFixed.SetAt(strId, 1);
        }
        else {
            ATL::CAtlMap<CString, unsigned int, ATL::CStringElementTraits<CString> >::CPair* pPair = m_mapCount.Lookup(strName);
            if (pPair != NULL) {
                pPair->m_value++;
                strId.Format("%s_%d_", (const char*)strName, pPair->m_value);
            }
            else {
                strId.Format("%s_%d_", (const char*)strName, 1);
                m_mapCount.SetAt(strName, 1);
            }
        }
        return 1;
    }
    strId = DAT_143b0dc28;
    return 0;
}
MS2_REPLACE_METHOD(0x1422F6AC0, UniqueSwfIDCreator, FUN_1422f6ac0, 448, 0xF6BCEC19);

// @0x1422f6c90
int UniqueSwfIDCreator::FUN_1422f6c90(CString strId)
{
    if (m_list10.IsEmpty())
        return 1;
    POSITION pos = m_list10.Find(strId);
    if (pos != NULL) {
        m_list10.RemoveAt(pos);
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1422F6C90, UniqueSwfIDCreator, FUN_1422f6c90, 176, 0xEE650437);

// @0x1422f6d50
int UniqueSwfIDCreator::FUN_1422f6d50(CString& strId, CString strName, const CString& strExt)
{
    if (strExt.IsEmpty()) {
        strId = DAT_143b0dc30;
        return 0;
    }
    CString strKey("");
    strKey.Format("%s.%s", (const char*)strName, (const char*)strExt);
    unsigned int n = 1;
    if (m_mapExtCount.Lookup(strKey, n))
        n++;
    strId.Format("%s_%d_", (const char*)strKey, n);
    m_listIds.AddTail(strId);
    m_mapExtCount.SetAt(strKey, n);
    return 1;
}
MS2_REPLACE_METHOD(0x1422F6D50, UniqueSwfIDCreator, FUN_1422f6d50, 356, 0xED9DF22C);

// @0x1422f6ec0
int UniqueSwfIDCreator::FUN_1422f6ec0(CString strId)
{
    for (POSITION pos = m_listIds.GetHeadPosition(); pos != NULL; m_listIds.GetNext(pos)) {
        CString str = m_listIds.GetAt(pos);
        if (str == strId) {
            m_listIds.RemoveAt(pos);
            return 1;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1422F6EC0, UniqueSwfIDCreator, FUN_1422f6ec0, 250, 0x5E402D9A);

// @0x1422f6fc0
int UniqueSwfIDCreator::FUN_1422f6fc0(CString strName)
{
    if (m_mapFixed.Lookup(strName) != NULL)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x1422F6FC0, UniqueSwfIDCreator, FUN_1422f6fc0, 96, 0xCD68A318);
