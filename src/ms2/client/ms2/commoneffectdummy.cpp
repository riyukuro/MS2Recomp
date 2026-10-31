// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CommonEffectDummy: Table/defaultEffectDummy.xml.
// MS2-UNIT: ?\commoneffectdummy.cpp
// MS2-RANGE: 0x140a40060-0x140a40940 .text$mn
// MS2-PIN: ??_7CommonEffectDummy@@6B?$TSingleton@VCommonEffectDummy@@@@@ 0x142dc66e0
// MS2-PIN: ??_7CommonEffectDummy@@6B?$CValidData@VCommonEffectDummy@@@@@ 0x142dc66f0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\commoneffectdummy.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "commoneffectdummy.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/ms2recover.h"
#include "ms2/commonfiles/filesystem.h"

// Unrecovered helpers (same ones continentregiontable.cpp uses).
class Unk_140165cf0 { public: Unk_140165cf0* FUN_140165cf0(const char*); };
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax
class Unk_140166420 : public CFileSystem { };
Unk_140166420* FUN_140166420();
CString FUN_14016a5c0(const char* psz, int n);
void* FUN_140166440();
void FUN_1403a1280(void*, int, int, const wchar_t*, const char**);

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's flag (symbols.tsv); a local copy stays false -> "is not initialized" box
bool CommonEffectDummy::s_bInit;
#endif

// @0x140a40060
CommonEffectDummy::CommonEffectDummy()
{
}

// @0x140a400d0
bool CommonEffectDummy::Load()
{
    CString strPath = FUN_14071a5b0("Table", "defaultEffectDummy.xml");
    bool ok = LoadFile(strPath);
    SetInit(true);
    return ok;
}

// @0x140a40180
CEffectDummy* CommonEffectDummy::Find(const CString& name)
{
    CheckInit();
    return m_pGroup->FUN_140a515f0(name);
}

// @0x140a40200
void CommonEffectDummy::Clear()
{
    m_pGroup->FUN_140a515c0();
}

// @0x140a40230
bool CommonEffectDummy::Get(unsigned int idx, void* pOut)
{
    CheckInit();
    return m_pGroup->FUN_140a516e0(idx, pOut);
}

// @0x140a40280
bool CommonEffectDummy::LoadFile(const char* path)
{
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, path, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_1403a1280(FUN_140166440(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", &path);
        return false;
    }
    m_pGroup = new EffectDummyGroup;
    m_pGroup->FUN_140a514e0(reinterpret_cast<TiXmlNode*>(pRoot));
    return true;
}

// @0x140a406c0
void CommonEffectDummy::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CommonEffectDummy).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x140a40770
void CommonEffectDummy::SetInit(bool b)
{
    s_bInit = b;
}
