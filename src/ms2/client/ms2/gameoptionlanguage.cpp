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
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
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
class Unk_LgCombo
{
public:
    void FUN_1422dfc10();                                       // clear
    void FUN_1422dfc70(ASObj& obj);                             // add an item
    void FUN_1422df5f0(unsigned int n);                         // visible rows
    void FUN_1422df690(int n);                                  // select a row
    int FUN_1422df6c0();                                        // selected row
    void FUN_1422c1fe0(unsigned int nEnabled);                  // set enabled
    RProv FUN_1422df770();                                      // the data provider
};
void* FUN_140bc04f0(RLg* p);                                    // the control (null test)
Unk_LgCombo* FUN_140bc0530(RLg* p);                             // the control
void FUN_140bbe120(RLg* pOut, int nId, const Scaleform::GFx::Value* pChild);
void FUN_140bbf570(RLg* pDst, RLg* pSrc);                       // transfer: pDst takes pSrc's handle, pSrc is nulled
void FUN_140bbf5e0(RLg* pDst, int);                             // null
template <> inline Unk_Ref<FUN_140bbfda0>::Unk_Ref(Unk_Ref& o) { FUN_140bbf570(this, &o); }
template <> inline Unk_Ref<FUN_140bbfda0>::Unk_Ref(int n) { FUN_140bbf5e0(this, n); }
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
bool FUN_140a467d0(const MS2Ptr<AScript>& kScript);             // has the AS object been released
AScript* FUN_1409ee290(MS2Ptr<AScript>* p);
Scaleform::GFx::Value FUN_140a46640(AScript* pObj, CString name, int nIndex);   // getTabChild
bool FUN_1407cce10(const Scaleform::GFx::Value* v);
int FUN_1409c1750(const Scaleform::GFx::Value& v);              // the value as an int
void FUN_1407cd930(Scaleform::GFx::Value* pObject, const char* szName, const Scaleform::GFx::Value& v);   // set a member

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
void* FUN_1412442a0(Unk_LgSettings* p);                         // the default block

// The state block's methods (0x14125f090...).
void FUN_14125f090(Unk_LgState* p);
void FUN_14125f0c0(Unk_LgState* p);
void FUN_14125f190(Unk_LgState* p, void* pDefaults);
void FUN_14125f260(Unk_LgState* pDst, const Unk_LgState* pSrc);

// the locale rows
CLocaleLanguage* FUN_1401c0da0();
unsigned __int64 FUN_1401662c0(ATL::CAtlArray<CString>&);               // GetCount
void* FUN_140164930(ATL::CAtlArray<CString>&, unsigned __int64);        // GetAt
void FUN_140165270(ATL::CAtlArray<CString>&, CString&);                 // Add
CString FUN_140652030(int nLanguage);                                   // language enum -> code
CString FUN_1406521f0(int nRegion);                                     // region enum -> code
int FUN_140651920(CString strCode);                                     // language code -> enum
int FUN_140651b00(CString strCode);                                     // region code -> enum
int FUN_1406516c0();
extern int DAT_143ab0248;                                               // the client region

CStringW FUN_1402a5170(const wchar_t* szFormat, const CString& a1);     // "{0}" formatter
CStringW FUN_14028b8e0(const CStringW& strKey);                         // string table text
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

// MS2-FUNCTIONAL: temp and EH-state layout differ
// @0x140cfb590
void CGameOptionLanguage::vfunc_6()
{
    LocaleLanguageDataPtr row = FUN_1401c0da0()->FUN_14064f070(0);
    if (FUN_140cfd210(&row) != 0)
    {
        {
            RLg list = ((Unk_LgDialog*)GetOptionDialog())->FUN_140cfcf10(CString("m_languageSelect"), -1);
            if (FUN_140bc04f0(&list) != 0)
            {
                for (unsigned __int64 i = 0; FUN_1401662c0(row->m_languages) > i; i++)
                {
                    CString strCode = FUN_140652030(m_state.m_nLanguage);
                    if (((CString*)FUN_140164930(row->m_languages, i))->CompareNoCase((const char*)strCode) == 0)
                    {
                        FUN_140bc0530(&list)->FUN_1422df690((int)i);
                        break;
                    }
                }
            }
        }
        {
            RLg list = ((Unk_LgDialog*)GetOptionDialog())->FUN_140cfcf10(CString("m_regionSelect"), -1);
            if (FUN_140bc04f0(&list) != 0)
            {
                for (unsigned __int64 i = 0; FUN_1401662c0(row->m_regions) > i; i++)
                {
                    CString strCode = FUN_1406521f0(DAT_143ab0248);
                    if (((CString*)FUN_140164930(row->m_voices, i))->CompareNoCase((const char*)strCode) == 0)
                    {
                        FUN_140bc0530(&list)->FUN_1422df690((int)i);
                        break;
                    }
                }
            }
        }
        {
            RLg list = ((Unk_LgDialog*)GetOptionDialog())->FUN_140cfcf10(CString("m_voiceSelect"), -1);
            if (FUN_140bc04f0(&list) != 0)
            {
                for (unsigned __int64 i = 0; FUN_1401662c0(row->m_voices) > i; i++)
                {
                    CString strCode = FUN_140652030(m_state.m_nVoice);
                    if (((CString*)FUN_140164930(row->m_voices, i))->CompareNoCase((const char*)strCode) == 0)
                    {
                        FUN_140bc0530(&list)->FUN_1422df690((int)i);
                        break;
                    }
                }
            }
        }
    }
}

// MS2-FUNCTIONAL: temp and EH-state layout differ
// @0x140cfb9e0
void CGameOptionLanguage::vfunc_7()
{
    {
        RLg list = ((Unk_LgDialog*)GetOptionDialog())->FUN_140cfcf10(CString("m_languageSelect"), -1);
        if (FUN_140bc04f0(&list) != 0)
        {
            int nSel = FUN_140bc0530(&list)->FUN_1422df6c0();
            ASObj item = FUN_140be3d00(FUN_140bc0530(&list)->FUN_1422df770())->FUN_1422df140(nSel);
            if (item.FUN_1422ba9a0() == 0)
                m_state.m_nLanguage = FUN_1409c1750(item.FUN_1422baa20("index"));
        }
    }
    {
        RLg list = ((Unk_LgDialog*)GetOptionDialog())->FUN_140cfcf10(CString("m_voiceSelect"), -1);
        if (FUN_140bc04f0(&list) != 0)
        {
            int nSel = FUN_140bc0530(&list)->FUN_1422df6c0();
            ASObj item = FUN_140be3d00(FUN_140bc0530(&list)->FUN_1422df770())->FUN_1422df140(nSel);
            if (item.FUN_1422ba9a0() == 0)
                m_state.m_nVoice = FUN_1409c1750(item.FUN_1422baa20("index"));
        }
    }
}

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
                FUN_140165270(files, s);
            }
            {
                CString s("./Data/Sound/MS2Sound_Emotion_Kor_def.fsb");
                FUN_140165270(files, s);
            }
            {
                CString s("./Data/Sound/MS2Sound_Voice_Kor_def.fsb");
                FUN_140165270(files, s);
            }
            {
                CString s("./Data/Sound/MS2Sound_Voice2_Kor_def.fsb");
                FUN_140165270(files, s);
            }
            {
                CString s("./Data/Sound/MS2Sound_Voice3_Kor_def.fsb");
                FUN_140165270(files, s);
            }
            {
                CString s("./Data/Sound/MS2Sound_Voice4_Kor_def.fsb");
                FUN_140165270(files, s);
            }
            {
                CString s("./Data/Sound/MS2Sound_Voice5_Kor_def.fsb");
                FUN_140165270(files, s);
            }
            {
                CString s("./Data/Sound/MS2Sound_Voice6_Kor_def.fsb");
                FUN_140165270(files, s);
            }
            for (unsigned __int64 i = 0; i < FUN_1401662c0(files); i++)
            {
                if (_access((const char*)*(CString*)FUN_140164930(files, i), 0) != 0)
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

// MS2-FUNCTIONAL: temp and EH-state layout differ
// @0x140cfbf50
void CGameOptionLanguage::FUN_140cfbf50()
{
    LocaleLanguageDataPtr row = FUN_1401c0da0()->FUN_14064f070(0);
    if (FUN_140cfd210(&row) == 0)
        return;
    {
        RLg list = ((Unk_LgDialog*)GetOptionDialog())->FUN_140cfcf10(CString("m_languageSelect"), -1);
        if (FUN_140bc04f0(&list) != 0)
        {
            FUN_140bc0530(&list)->FUN_1422dfc10();
            for (unsigned __int64 i = 0; FUN_1401662c0(row->m_languages) > i; i++)
            {
                ASObj item(2);
                CString strCode(*(CString*)FUN_140164930(row->m_languages, i));
                item.FUN_1407cbb20("label", FUN_140cfc970(CString(strCode)));
                item.FUN_140cfd0d0("index", FUN_140651920(CString(strCode)));
                FUN_140bc0530(&list)->FUN_1422dfc70(item);
            }
            if (FUN_1401662c0(row->m_languages) < 4)
                FUN_140bc0530(&list)->FUN_1422df5f0((unsigned int)FUN_1401662c0(row->m_languages));
            if (FUN_1401662c0(row->m_languages) == 1)
                FUN_140bc0530(&list)->FUN_1422c1fe0(0);
        }
    }
    {
        RLg list = ((Unk_LgDialog*)GetOptionDialog())->FUN_140cfcf10(CString("m_regionSelect"), -1);
        if (FUN_140bc04f0(&list) != 0)
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
                for (unsigned __int64 i = 0; FUN_1401662c0(row->m_regions) > i; i++)
                {
                    ASObj item(2);
                    CString strCode(*(CString*)FUN_140164930(row->m_regions, i));
                    item.FUN_1407cbb20("label", FUN_140cfca90(CString(*(CString*)FUN_140164930(row->m_regions, i))));
                    item.FUN_140cfd170("index", FUN_140651b00(CString(strCode)));
                    FUN_140bc0530(&list)->FUN_1422dfc70(item);
                }
                if (FUN_1401662c0(row->m_regions) < 4)
                    FUN_140bc0530(&list)->FUN_1422df5f0((unsigned int)FUN_1401662c0(row->m_regions));
                if (FUN_1401662c0(row->m_regions) == 1)
                    FUN_140bc0530(&list)->FUN_1422c1fe0(0);
            }
        }
    }
    {
        RLg list = ((Unk_LgDialog*)GetOptionDialog())->FUN_140cfcf10(CString("m_voiceSelect"), -1);
        if (FUN_140bc04f0(&list) != 0)
        {
            FUN_140bc0530(&list)->FUN_1422dfc10();
            for (unsigned __int64 i = 0; FUN_1401662c0(row->m_voices) > i; i++)
            {
                ASObj item(2);
                CString strCode(*(CString*)FUN_140164930(row->m_voices, i));
                item.FUN_1407cbb20("label", FUN_140cfca00(CString(strCode)));
                item.FUN_140cfd0d0("index", FUN_140651920(CString(strCode)));
                FUN_140bc0530(&list)->FUN_1422dfc70(item);
            }
            if (FUN_1401662c0(row->m_voices) < 4)
                FUN_140bc0530(&list)->FUN_1422df5f0((unsigned int)FUN_1401662c0(row->m_voices));
            if (FUN_1401662c0(row->m_voices) == 1)
                FUN_140bc0530(&list)->FUN_1422c1fe0(0);
        }
    }
}

// @0x140cfc970
CStringW CGameOptionLanguage::FUN_140cfc970(CString strCode)
{
    return FUN_14028b8e0(FUN_1402a5170(L"s_gameoption_language_{0}", strCode));
}

// @0x140cfca00
CStringW CGameOptionLanguage::FUN_140cfca00(CString strCode)
{
    return FUN_14028b8e0(FUN_1402a5170(L"s_gameoption_voice_{0}", strCode));
}

// @0x140cfca90
CStringW CGameOptionLanguage::FUN_140cfca90(CString strCode)
{
    return FUN_14028b8e0(FUN_1402a5170(L"s_gameoption_region_{0}", strCode));
}

// MS2-FUNCTIONAL: temp and EH-state layout differ
// @0x140cfcb20
void CGameOptionLanguage::vfunc_10()
{
    CBaseOption::vfunc_10();
    bool bRestart = m_state.m_nLanguage != FUN_1409a8b10()->FUN_140cfd280()->m_nLanguage;
    if (m_state.m_nVoice != FUN_1409a8b10()->FUN_140cfd280()->m_nVoice)
    {
        int nOk = FUN_140cfbcd0(m_state.m_nVoice);
        if (nOk == 0)
        {
            m_state.m_nVoice = FUN_1409a8b10()->FUN_140cfd280()->m_nVoice;
            RLg list = ((Unk_LgDialog*)GetOptionDialog())->FUN_140cfcf10(CString("m_voiceSelect"), -1);
            if (FUN_140bc04f0(&list) != 0)
                FUN_140bc0530(&list)->FUN_1422df690(m_state.m_nVoice);
        }
        if (nOk == 0)
        {
            FUN_140d73aa0(FUN_14028b8e0(CStringW(L"s_gameoption_voice_select_warning")), 0, 0, CStringW(L""));
        }
        else
        {
            if (FUN_1406516c0() != m_state.m_nVoice)
                bRestart = true;
        }
    }
    if (bRestart)
        FUN_140d73aa0(FUN_14028b8e0(CStringW(L"s_gameoption_voice_select_restart")), 0, 0, CStringW(L""));
    FUN_14125f260(FUN_1409a8b10()->FUN_140cfd280(), &m_state);
}

// @0x140cfce00
void CGameOptionLanguage::vfunc_12()
{
    CBaseOption::vfunc_12();
    FUN_14125f0c0(&m_state);
    FUN_14125f190(&m_state, FUN_1412442a0(FUN_1409a8b10()));
    vfunc_6();
}

// @0x140cfce60
CString CGameOptionLanguage::vfunc_1()
{
    return CString("GameOptionLanguage");
}

// MS2-FUNCTIONAL: result materialised with a different branch layout
// @0x140cfceb0
bool CGameOptionLanguage::vfunc_14()
{
    if (m_state.m_nLanguage == FUN_1409a8b10()->FUN_140cfd280()->m_nLanguage)
    {
        if (m_state.m_nVoice == FUN_1409a8b10()->FUN_140cfd280()->m_nVoice)
            return false;
        return true;
    }
    return true;
}

// MS2-FUNCTIONAL: temp and EH-state layout differ
// @0x140cfcf10
RLg Unk_LgDialog::FUN_140cfcf10(CString name, int nIndex)
{
    // The exe constructs straight into the return slot (0x140bbf570 / 0x140bbf5e0); a local copied out and then
    // destroyed would release the handle the caller receives.
    if (FUN_140a467d0(m_root) == 0)
    {
        Scaleform::GFx::Value child = FUN_140a46640(FUN_1409ee290(&m_root), name, nIndex);
        if (FUN_1407cce10(&child))
        {
            RLg list;
            FUN_140bbe120(&list, m_nId, &child);
            if (FUN_140bc04f0(&list) != 0)
                return RLg(list);
        }
        return RLg(0);
    }
    return RLg(0);
}

// @0x140cfd0d0
void ASObj::FUN_140cfd0d0(const char* szName, int n)
{
    ASData data;
    data.FUN_1422b7f70(n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}

// @0x140cfd170
void ASObj::FUN_140cfd170(const char* szName, int n)
{
    ASData data;
    data.FUN_1422b7f70(n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}

MS2_EMIT_CRT_MEMMOVE_S();
