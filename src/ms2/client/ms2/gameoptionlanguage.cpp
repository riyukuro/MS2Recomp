// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The client's gameoptionlanguage.cpp: the language / region
// / voice row of the game options.
// MS2-UNIT: ?\gameoptionlanguage.cpp
// MS2-RANGE: 0x140cfb450-0x140cfd2a0 .text$mn
// MS2-PIN: ??_GCGameOptionLanguage@@UEAAPEAXI@Z 0x140cfd220
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\gameoptionlanguage.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "gameoptionlanguage.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/commonfiles/localepath.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ascorelist.h"
#include <io.h>

// ---- handles: a smart reference whose destructor is the exe function REL ----
template <void (*REL)(void*)>
struct Unk_Ref
{
    void* m_0;
    void* m_p;
    Unk_Ref() : m_0(0), m_p(0) {}
    Unk_Ref(Unk_Ref& o);                        // takes o's handle (auto_ptr style), per handle type below
    explicit Unk_Ref(int n);                    // the null handle, per handle type below
    Unk_Ref(int nId, const Scaleform::GFx::Value* pChild);   // a child control, per handle type below
    ~Unk_Ref() { REL(this); }
};

void FUN_140bbfda0(void*);
void FUN_140be3520(void*);
typedef Unk_Ref<FUN_140bbfda0> RLg;             // a drop down of the option dialog
typedef Unk_Ref<FUN_140be3520> RProv;           // its data provider

// ---- unit-local placeholders ----

// The drop down control (a list component of the option swf).
class Unk_LgProv
{
public:
    ASObj FUN_1422df140(int nIndex);                            // the row at the index
};
class Unk_LgCombo : public ASDropdownMenu
{
public:
    void FUN_1422dfc70(ASObj& obj);                             // add an item
    void FUN_1422c1fe0(unsigned int nEnabled);                  // set enabled
    RProv FUN_1422df770();                                      // the data provider
};
Unk_LgCombo* FUN_140bc0530(RLg* p);                             // the control
void FUN_140bbe120(RLg* pOut, int nId, const Scaleform::GFx::Value* pChild);
void FUN_140bbf570(RLg* pDst, RLg* pSrc);                       // transfer: pDst takes pSrc's handle, pSrc is nulled
void FUN_140bbf5e0(RLg* pDst, int);                             // null
template <> inline Unk_Ref<FUN_140bbfda0>::Unk_Ref(Unk_Ref& o) { FUN_140bbf570(this, &o); }
template <> inline Unk_Ref<FUN_140bbfda0>::Unk_Ref(int n) { FUN_140bbf5e0(this, n); }
template <> inline Unk_Ref<FUN_140bbfda0>::Unk_Ref(int nId, const Scaleform::GFx::Value* pChild) { FUN_140bbe120(this, nId, pChild); }
Unk_LgProv* FUN_140be3d00(const RProv& r);

// View of the option dialog: the option id at +0x28 and the AS root at +0x30.
struct Unk_LgDialog
{
    char m_pad[0x28];
    int m_nId;
    int m_pad2;
    MS2Ptr<AScript> m_root;
    RLg FUN_140cfcf10(CString name, int nIndex);                // a child drop down by name
};

// The game-option settings object returned by FUN_1409a8b10.
class Unk_LgSettings
{
public:
    Unk_LgState* FUN_140cfd280();                               // +0x198 the saved language / voice
    CStringW* FUN_140cfd260();                                  // +0xe8 the region name
    char m_pad[0xe8];
    CStringW m_strRegion;                                       // +0xe8
    char m_pad2[0x198 - 0xf0];
    Unk_LgState m_state;                                        // +0x198
};
Unk_LgSettings* FUN_1409a8b10();
class CGameOption   // C3: member view for the former free stand-ins
{
public:
    class TiXmlDocument* FUN_1412442a0();
};

// The state block's methods (0x14125f090...).
struct Unk_LgState* FUN_14125f090(struct Unk_LgState*);   // C3: was FUN_14125f090
void FUN_14125f0c0(Unk_LgState* p);
int LoadGameOptionLanguage(struct Unk_LgState*, class TiXmlDocument*);   // C3: was FUN_14125f190
void FUN_14125f260(Unk_LgState* pDst, const Unk_LgState* pSrc);

// the locale rows
CLocaleLanguage* FUN_1401c0da0();
CString FUN_140652030(int nLanguage);                                   // language enum -> code
CString FUN_1406521f0(int nRegion);                                     // region enum -> code
int FUN_140651920(CString strCode);                                     // language code -> enum
int FUN_140651b00(CString strCode);                                     // region code -> enum
int FUN_1406516c0();
extern int DAT_143ab0248;                                               // the client region

CStringW GetStringCommonByKey(const CStringW& strKey);                         // string table text
void FUN_140d73aa0(CStringW strText, int, void*, CStringW strTitle);   // message box

struct Unk_LgPtrView { void* m_0; CLocaleLanguageData* m_p; };

// @0x140cfd210
CLocaleLanguageData* FUN_140cfd210(LocaleLanguageDataPtr* p)
{
    return ((Unk_LgPtrView*)p)->m_p;
}

// @0x140cfd260
CStringW* Unk_LgSettings::FUN_140cfd260()
{
    return &m_strRegion;
}

// @0x140cfd280
Unk_LgState* Unk_LgSettings::FUN_140cfd280()
{
    return &m_state;
}

// @0x140cfb450
CGameOptionLanguage::CGameOptionLanguage(int nId, int nType)
    : CBaseOption(nId, nType)
{
    FUN_14125f090(&m_state);
}

// @0x140cfb4b0
CGameOptionLanguage::~CGameOptionLanguage()
{
}

// @0x140cfb4e0
void CGameOptionLanguage::vfunc_3(int n)
{
    if (n == 0)
        FUN_14125f260(&m_state, FUN_1409a8b10()->FUN_140cfd280());
    else
        FUN_140cfbf50();
    CBaseOption::vfunc_3(n);
}

// @0x140cfb540
void CGameOptionLanguage::vfunc_4(int n)
{
    CBaseOption::vfunc_4(n);
}

// @0x140cfb570
int CGameOptionLanguage::vfunc_5(const char* pszName, void* pArg, int nArg)
{
    return 0;
}

// @0x140cfb590
void CGameOptionLanguage::vfunc_6()
{
    LocaleLanguageDataPtr row = FUN_1401c0da0()->FUN_14064f070(0);
    if (FUN_140cfd210(&row) != 0)
    {
        {
            RLg list = ((Unk_LgDialog*)GetOptionDialog())->FUN_140cfcf10("m_languageSelect", -1);
            if (((void*)((MS2Ptr<ASDropdownMenu>*)(void*)(&list))->get()) != 0)
            {
                for (unsigned __int64 i = 0; i < row->m_languages.GetCount(); i++)
                {
                    CString strCode = FUN_140652030(m_state.m_nLanguage);
                    if (row->m_languages.GetAt(i).CompareNoCase((const char*)strCode) == 0)
                    {
                        FUN_140bc0530(&list)->FUN_1422df690((int)i);
                        break;
                    }
                }
            }
        }
        {
            RLg list = ((Unk_LgDialog*)GetOptionDialog())->FUN_140cfcf10("m_regionSelect", -1);
            if (((void*)((MS2Ptr<ASDropdownMenu>*)(void*)(&list))->get()) != 0)
            {
                for (unsigned __int64 i = 0; i < row->m_regions.GetCount(); i++)
                {
                    CString strCode = FUN_1406521f0(DAT_143ab0248);
                    if (row->m_voices.GetAt(i).CompareNoCase((const char*)strCode) == 0)
                    {
                        FUN_140bc0530(&list)->FUN_1422df690((int)i);
                        break;
                    }
                }
            }
        }
        {
            RLg list = ((Unk_LgDialog*)GetOptionDialog())->FUN_140cfcf10("m_voiceSelect", -1);
            if (((void*)((MS2Ptr<ASDropdownMenu>*)(void*)(&list))->get()) != 0)
            {
                for (unsigned __int64 i = 0; i < row->m_voices.GetCount(); i++)
                {
                    CString strCode = FUN_140652030(m_state.m_nVoice);
                    if (row->m_voices.GetAt(i).CompareNoCase((const char*)strCode) == 0)
                    {
                        FUN_140bc0530(&list)->FUN_1422df690((int)i);
                        break;
                    }
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x140cfb590, CGameOptionLanguage, vfunc_6, 1090, 0x0F1D4889);

// @0x140cfb9e0
void CGameOptionLanguage::vfunc_7()
{
    {
        RLg list = ((Unk_LgDialog*)GetOptionDialog())->FUN_140cfcf10("m_languageSelect", -1);
        if (((void*)((MS2Ptr<ASDropdownMenu>*)(void*)(&list))->get()) != 0)
        {
            ASObj item = FUN_140be3d00(FUN_140bc0530(&list)->FUN_1422df770())->FUN_1422df140(FUN_140bc0530(&list)->FUN_1422df6c0());
            if (item.FUN_1422ba9a0() == 0)
                m_state.m_nLanguage = item.FUN_1422baa20("index").GetInt();
        }
    }
    {
        RLg list = ((Unk_LgDialog*)GetOptionDialog())->FUN_140cfcf10("m_voiceSelect", -1);
        if (((void*)((MS2Ptr<ASDropdownMenu>*)(void*)(&list))->get()) != 0)
        {
            ASObj item = FUN_140be3d00(FUN_140bc0530(&list)->FUN_1422df770())->FUN_1422df140(FUN_140bc0530(&list)->FUN_1422df6c0());
            if (item.FUN_1422ba9a0() == 0)
                m_state.m_nVoice = item.FUN_1422baa20("index").GetInt();
        }
    }
}
MS2_REPLACE_METHOD(0x140cfb9e0, CGameOptionLanguage, vfunc_7, 746, 0x850CE415);

// @0x140cfbcd0
int CGameOptionLanguage::FUN_140cfbcd0(int nVoice)
{
    if (DAT_143ab0248 == 3)
    {
        if (nVoice == 3)
            return 1;
        if (nVoice == 0)
        {
            ATL::CAtlArray<CString> files;
            {
                CString s("./Data/Sound/MS2Sound_AttackVoice_Kor_def.fsb");
                files.Add(s);
            }
            {
                CString s("./Data/Sound/MS2Sound_Emotion_Kor_def.fsb");
                files.Add(s);
            }
            {
                CString s("./Data/Sound/MS2Sound_Voice_Kor_def.fsb");
                files.Add(s);
            }
            {
                CString s("./Data/Sound/MS2Sound_Voice2_Kor_def.fsb");
                files.Add(s);
            }
            {
                CString s("./Data/Sound/MS2Sound_Voice3_Kor_def.fsb");
                files.Add(s);
            }
            {
                CString s("./Data/Sound/MS2Sound_Voice4_Kor_def.fsb");
                files.Add(s);
            }
            {
                CString s("./Data/Sound/MS2Sound_Voice5_Kor_def.fsb");
                files.Add(s);
            }
            {
                CString s("./Data/Sound/MS2Sound_Voice6_Kor_def.fsb");
                files.Add(s);
            }
            for (unsigned __int64 i = 0; i < files.GetCount(); i++)
            {
                if (_access((const char*)files.GetAt(i), 0) != 0)
                    return 0;
            }
            return 1;
        }
        return 0;
    }
    else
    {
        return 1;
    }
}

// @0x140cfbf50
void CGameOptionLanguage::FUN_140cfbf50()
{
    int nIndex = 0;
    LocaleLanguageDataPtr row = FUN_1401c0da0()->FUN_14064f070(nIndex);
    if (FUN_140cfd210(&row) != 0)
    {
        {
            RLg list = ((Unk_LgDialog*)GetOptionDialog())->FUN_140cfcf10("m_languageSelect", -1);
            if (((void*)((MS2Ptr<ASDropdownMenu>*)(void*)(&list))->get()) != 0)
            {
                FUN_140bc0530(&list)->FUN_1422dfc10();
                for (unsigned __int64 i = 0; i < row->m_languages.GetCount(); i++)
                {
                    ASObj item(2);
                    CString strCode(row->m_languages.GetAt(i));
                    item.FUN_1407cbb20("label", FUN_140cfc970(CString(strCode)));
                    item.FUN_140cfd0d0("index", FUN_140651920(CString(strCode)));
                    FUN_140bc0530(&list)->FUN_1422dfc70(item);
                }
                if (row->m_languages.GetCount() <= 3)
                    FUN_140bc0530(&list)->FUN_1422df5f0((unsigned int)row->m_languages.GetCount());
                if (row->m_languages.GetCount() == 1)
                    FUN_140bc0530(&list)->FUN_1422c1fe0(0);
            }
        }
        {
            RLg list = ((Unk_LgDialog*)GetOptionDialog())->FUN_140cfcf10("m_regionSelect", -1);
            if (((void*)((MS2Ptr<ASDropdownMenu>*)(void*)(&list))->get()) != 0)
            {
                FUN_140bc0530(&list)->FUN_1422dfc10();
                if (DAT_143ab0248 == 2)
                {
                    CString strRegion;
                    strRegion = (const wchar_t*)*FUN_1409a8b10()->FUN_140cfd260();
                    if (strRegion.IsEmpty())
                        strRegion = "stage";
                    ASObj item(2);
                    item.FUN_1407cbb20("label", FUN_140cfca90(CString(strRegion)));
                    item.FUN_1407cb9c0("index", 0);
                    FUN_140bc0530(&list)->FUN_1422dfc70(item);
                    FUN_140bc0530(&list)->FUN_1422df5f0(1);
                    FUN_140bc0530(&list)->FUN_1422df690(0);
                    FUN_140bc0530(&list)->FUN_1422c1fe0(0);
                }
                else
                {
                    for (unsigned __int64 i = 0; i < row->m_regions.GetCount(); i++)
                    {
                        ASObj item(2);
                        CString strCode(row->m_regions.GetAt(i));
                        item.FUN_1407cbb20("label", FUN_140cfca90(CString(row->m_regions.GetAt(i))));
                        item.FUN_140cfd170("index", FUN_140651b00(CString(strCode)));
                        FUN_140bc0530(&list)->FUN_1422dfc70(item);
                    }
                    if (row->m_regions.GetCount() <= 3)
                        FUN_140bc0530(&list)->FUN_1422df5f0((unsigned int)row->m_regions.GetCount());
                    if (row->m_regions.GetCount() == 1)
                        FUN_140bc0530(&list)->FUN_1422c1fe0(0);
                }
            }
        }
        {
            RLg list = ((Unk_LgDialog*)GetOptionDialog())->FUN_140cfcf10("m_voiceSelect", -1);
            if (((void*)((MS2Ptr<ASDropdownMenu>*)(void*)(&list))->get()) != 0)
            {
                FUN_140bc0530(&list)->FUN_1422dfc10();
                for (unsigned __int64 i = 0; i < row->m_voices.GetCount(); i++)
                {
                    ASObj item(2);
                    CString strCode(row->m_voices.GetAt(i));
                    item.FUN_1407cbb20("label", FUN_140cfca00(CString(strCode)));
                    item.FUN_140cfd0d0("index", FUN_140651920(CString(strCode)));
                    FUN_140bc0530(&list)->FUN_1422dfc70(item);
                }
                if (row->m_voices.GetCount() <= 3)
                    FUN_140bc0530(&list)->FUN_1422df5f0((unsigned int)row->m_voices.GetCount());
                if (row->m_voices.GetCount() == 1)
                    FUN_140bc0530(&list)->FUN_1422c1fe0(0);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x140cfbf50, CGameOptionLanguage, FUN_140cfbf50, 2585, 0x4044FF97);

// @0x140cfc970
CStringW CGameOptionLanguage::FUN_140cfc970(CString strCode)
{
    return GetStringCommonByKey(StringFormat<CString>(L"s_gameoption_language_{0}", strCode));
}

// @0x140cfca00
CStringW CGameOptionLanguage::FUN_140cfca00(CString strCode)
{
    return GetStringCommonByKey(StringFormat<CString>(L"s_gameoption_voice_{0}", strCode));
}

// @0x140cfca90
CStringW CGameOptionLanguage::FUN_140cfca90(CString strCode)
{
    return GetStringCommonByKey(StringFormat<CString>(L"s_gameoption_region_{0}", strCode));
}

// @0x140cfcb20
void CGameOptionLanguage::vfunc_10()
{
    CBaseOption::vfunc_10();
    int bRestart = 0;
    if (m_state.m_nLanguage != FUN_1409a8b10()->FUN_140cfd280()->m_nLanguage)
        bRestart = 1;
    if (m_state.m_nVoice != FUN_1409a8b10()->FUN_140cfd280()->m_nVoice)
    {
        int nOk = FUN_140cfbcd0(m_state.m_nVoice);
        if (nOk == 0)
        {
            m_state.m_nVoice = FUN_1409a8b10()->FUN_140cfd280()->m_nVoice;
            RLg list = ((Unk_LgDialog*)GetOptionDialog())->FUN_140cfcf10("m_voiceSelect", -1);
            if (((void*)((MS2Ptr<ASDropdownMenu>*)(void*)(&list))->get()) != 0)
                FUN_140bc0530(&list)->FUN_1422df690(m_state.m_nVoice);
        }
        if (nOk == 0)
        {
            FUN_140d73aa0(GetStringCommonByKey(L"s_gameoption_voice_select_warning"), 0, 0, CStringW(L""));
        }
        else
        {
            if (FUN_1406516c0() != m_state.m_nVoice)
                bRestart = 1;
        }
    }
    if (bRestart)
        FUN_140d73aa0(GetStringCommonByKey(L"s_gameoption_voice_select_restart"), 0, 0, CStringW(L""));
    FUN_14125f260(FUN_1409a8b10()->FUN_140cfd280(), &m_state);
}
MS2_REPLACE_METHOD(0x140cfcb20, CGameOptionLanguage, vfunc_10, 726, 0xD92A6CE6);

// @0x140cfce00
void CGameOptionLanguage::vfunc_12()
{
    CBaseOption::vfunc_12();
    FUN_14125f0c0(&m_state);
    LoadGameOptionLanguage(&m_state, (class TiXmlDocument*)(((void*)((class CGameOption*)(class Unk_LgSettings*)(FUN_1409a8b10()))->FUN_1412442a0())));
    vfunc_6();
}

// @0x140cfce60
CString CGameOptionLanguage::GetTypeName()
{
    return CString("GameOptionLanguage");
}

// @0x140cfceb0
int CGameOptionLanguage::vfunc_14()
{
    if (m_state.m_nLanguage != FUN_1409a8b10()->FUN_140cfd280()->m_nLanguage)
        return true;
    if (m_state.m_nVoice != FUN_1409a8b10()->FUN_140cfd280()->m_nVoice)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x140cfceb0, CGameOptionLanguage, vfunc_14, 81, 0x137F3485);

// @0x140cfcf10
RLg Unk_LgDialog::FUN_140cfcf10(CString name, int nIndex)
{
    // The exe constructs straight into the return slot (0x140bbf570 / 0x140bbf5e0); a local copied out and then
    // destroyed would release the handle the caller receives.
    if (m_root.IsNull() != 0)
        return RLg(0);
    Scaleform::GFx::Value child = m_root->Invoke("getTabChild", name, nIndex);
    if (child.IsDisplayObject())
    {
        RLg list(m_nId, &child);
        if (((void*)((MS2Ptr<ASDropdownMenu>*)(void*)(&list))->get()) != 0)
            return RLg(list);
    }
    return RLg(0);
}
MS2_REPLACE_METHOD(0x140cfcf10, Unk_LgDialog, FUN_140cfcf10, 443, 0x487EB451);

// @0x140cfd0d0
void ASObj::FUN_140cfd0d0(const char* szName, int n)
{
    ASData data;
    data.FUN_1422b7f70(n);
    m_value.SetMember(szName, data.FUN_1422b9260());
}

// @0x140cfd170
void ASObj::FUN_140cfd170(const char* szName, int n)
{
    ASData data;
    data.FUN_1422b7f70(n);
    m_value.SetMember(szName, data.FUN_1422b9260());
}

MS2_EMIT_CRT_MEMMOVE_S();
