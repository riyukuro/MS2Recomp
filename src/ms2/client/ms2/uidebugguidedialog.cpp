// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIDebugGuideDialog: the GM command helper (command groups and
// commands read from XmlDebug/DebugCommand*.xml).
// MS2-UNIT: client\ms2\uidebugguidedialog.cpp
// MS2-RANGE: 0x1400ec6a0-0x1400ec950 .text$di
// MS2-RANGE: 0x141286410-0x14128e7f0 .text$mn
// MS2-PIN: ??__Fs_unk1402a9d70@@YAXXZ 0x142caed40 ; hand: atexit of header-statics map
// MS2-PIN: ??$Unk_SocketFormat@$$BY0BN@DV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@@YA?AV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEBDAEAY0BN@$$CBDAEBV01@@Z 0x141289220
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_unk1402a9d70@@YAXXZ 0x1400ec900 ; unique
// MS2-PIN: ??$?8PEAVUIDebugGuideDialog@@P80@EAAXAEAVCInPacket@@@Z@std@@YA_NAEBU?$pair@PEAVUIDebugGuideDialog@@P81@EAAXAEAVCInPacket@@@Z@0@0@Z 0x141289140 ; prop
// MS2-PIN: ??$?8PEAVUIDebugGuideDialog@@P80@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@YA_NAEBU?$pair@PEAVUIDebugGuideDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@0@0@Z 0x1412891b0 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIDebugGuideDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@QEAA@AEBV01@@Z 0x14128bc70 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIDebugGuideDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@QEAA@AEBV01@@Z 0x14128bd10 ; prop
// MS2-PIN: ??_GUIDebugGuideDialog@@UEAAPEAXI@Z 0x14128c9b0 ; unique
// MS2-PIN: ?vfunc_48@UIDebugGuideDialog@@UEAAHXZ 0x14128c9f0 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIDebugGuideDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x14128e180 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIDebugGuideDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x14128e1e0 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIDebugGuideDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEAAXAEAVCInPacket@@@Z 0x14128e370 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIDebugGuideDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x14128e3a0 ; unique
// MS2-PIN: ??$Call@VUIDebugGuideDialog@@P81@EAAXAEAVCInPacket@@@Z@?$DelegateImpl@U?$pair@PEAVUIDebugGuideDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@CAXAEAU?$pair@PEAVUIDebugGuideDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@AEAVCInPacket@@@Z 0x14128e3d0 ; prop
// MS2-PIN: ??$Call@VUIDebugGuideDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@?$DelegateImpl@U?$pair@PEAVUIDebugGuideDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@CAXAEAU?$pair@PEAVUIDebugGuideDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@AEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x14128e410 ; prop
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIDebugGuideDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x14128e450 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIDebugGuideDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x14128e4b0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uidebugguidedialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "uidebugguidedialog.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/gfxexception.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/commonfiles/filesystem.h"
#include "hook/ms2hook.h"

// ---- header statics (the exe runs them in this order: two copies of the shared header's names, the handle, the condition) ----

class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };
static CString s_strSortNamesA[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkillA = "skill";
static CString s_strStunA = "stun";
static CString s_strSortNamesB[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkillB = "skill";
static CString s_strStunB = "stun";
static Unk_1401cd100 s_pointerB(NULL);
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);

// ---- unit-local views of exe types ----

class Unk_140165cf0                                             // game TinyXML element
{
public:
    Unk_140165cf0* FUN_140165cf0(const char* pszName);          // FirstChildElement
    Unk_140165cf0* FUN_140168650(const char* pszName);          // NextSiblingElement
};
int FUN_140873420(Unk_140165cf0* pElem, const char* pszName, CStringW& rValue);
void FUN_1408730a0(Unk_140165cf0* pElem, const char* pszName, bool& rValue);

// The AS controls of the movie (AScript subclasses; slot 24 is the visibility the dialog calls).
class Unk_DebugGuideCtl : public AScript
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5();
    virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10();
    virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20();
    virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bShow);
};
class Unk_DebugGuideList : public Unk_DebugGuideCtl
{
public:
    void FUN_1422dd1d0();                                       // clear
    void FUN_1422dd310(const CStringW& strLabel);               // add a row
    void FUN_1422dcca0(int nIndex);                             // select
    int FUN_1422dccd0();                                        // the selected index
    void FUN_1422e1890(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& callback);   // selection callback
};
class Unk_DebugGuideButton : public Unk_DebugGuideCtl
{
public:
    void FUN_1422ce240(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& callback, int nFlags);   // click
};
class Unk_DebugGuideInput : public Unk_DebugGuideCtl { public: CStringW FUN_1422e0b00(); };    // the text
class Unk_DebugGuideMovie
{
public:
    void FUN_1422c3600(const CString& strEvent, const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& callback,
                       int a3, int a4, int a5, void* a6);
};
MS2Ptr<ASMovieClip> FUN_1409b40c0(int nMovieId, const Scaleform::GFx::Value& rValue);
class Unk_DebugGuideKeys { public: bool FUN_14116d9c0(int nKey, bool b, int n); };
Unk_DebugGuideKeys* FUN_14025e7c0();
class Unk_DebugGuideDTPackets
{
public:
    void FUN_140da5180(int nOpcode, Delegate<void(CInPacket&)> handler);
    void FUN_140da51e0(int nOpcode, Delegate<void(CInPacket&)> handler);
};
Unk_DebugGuideDTPackets* FUN_140bccd50();
void* FUN_140166440();
void FUN_14015eb90(void* pLog, int a, int b, const wchar_t* pszFormat, const CString& strArg);
CString FUN_140651350();
CString FUN_1411c0aa0(const char* pszPath);
class Unk_DebugGuideWorld { public: CStringW FUN_141bd0d30(); };
Unk_DebugGuideWorld* FUN_1403ed2d0();
bool FUN_140164830(const CStringW& a, const CStringW& b);
void* FUN_140a3ab70(int nUiType);
void FUN_141a25770(void* pChat, CStringW strText, int n);
void FUN_1412751b0(const CStringW& str, int n);
void FUN_140710590(COutPacket* p);
CStringW FUN_1406564a0(const wchar_t* pszFormat, const CStringW& a, const CStringW& b, const CStringW& c);
CStringW FUN_140656190(const wchar_t* pszFormat, const CStringW& a, const CStringW& b);
CStringW FUN_140292a70(const wchar_t* pszFormat, const int& n);
void FUN_140cfee80(const Scaleform::GFx::Value& root, CString strName, CStringW strText);

// ---- the XML records ----

// @0x141286410
Unk_DebugGuideArg::Unk_DebugGuideArg(Unk_140165cf0* pElem)
{
    Read(pElem);
}

// @0x141286460
Unk_DebugGuideArg::Unk_DebugGuideArg(CStringW strCmd, bool bUseArg)
    : m_strCmd(strCmd), m_bUseArg(bUseArg)
{
}

// @0x1412864c0
void Unk_DebugGuideArg::Read(Unk_140165cf0* pElem)
{
    m_bUseArg = false;
    FUN_140873420(pElem, "cmd", m_strCmd);
    FUN_1408730a0(pElem, "useArg", m_bUseArg);
}

// @0x14128c740
Unk_DebugGuideArg::~Unk_DebugGuideArg()
{
}

// @0x14128c480
Unk_DebugGuideCommand::Unk_DebugGuideCommand()
{
}

// @0x14128c760
Unk_DebugGuideCommand::~Unk_DebugGuideCommand()
{
}

// @0x141286520
void Unk_DebugGuideCommand::Read(Unk_140165cf0* pElem)
{
    FUN_140873420(pElem, "name", m_strName);
    FUN_140873420(pElem, "desc", m_strDesc);
    CStringW strCmd;
    bool bUseArg = false;
    FUN_140873420(pElem, "cmd", strCmd);
    FUN_1408730a0(pElem, "useArg", bUseArg);
    if (!strCmd.IsEmpty())
        m_args.push_back(Unk_DebugGuideArg(strCmd, bUseArg));
    for (Unk_140165cf0* pChild = pElem->FUN_140165cf0("v"); pChild != 0; pChild = pChild->FUN_140168650("v"))
        m_args.push_back(Unk_DebugGuideArg(pChild));
}

// @0x1412866e0
void Unk_DebugGuideCommand::AddArg(const Unk_DebugGuideArg& rArg)
{
    m_args.push_back(rArg);
}

// @0x141286710
Unk_DebugGuideGroup::Unk_DebugGuideGroup(Unk_140165cf0* pElem)
{
    Read(pElem);
}

// @0x14128c7a0
Unk_DebugGuideGroup::~Unk_DebugGuideGroup()
{
}

// @0x141286780
void Unk_DebugGuideGroup::Read(Unk_140165cf0* pElem)
{
    FUN_140873420(pElem, "name", m_strName);
    FUN_140873420(pElem, "charOnlyName", m_strCharOnly);
    for (Unk_140165cf0* pChild = pElem->FUN_140165cf0("CommandSet"); pChild != 0; pChild = pChild->FUN_140168650("CommandSet"))
    {
        Unk_DebugGuideCommand cmd;
        cmd.Read(pChild);
        m_commands.push_back(cmd);
    }
}

// ---- the dialog ----

// @0x141286850
UIDebugGuideDialog::UIDebugGuideDialog()
{
    m_40 = 1;
    FUN_1422dc3b0(1);
    FUN_140bccd50()->FUN_140da5180(0x87, Delegate<void(CInPacket&)>(this, &UIDebugGuideDialog::OnPacket));
}

// @0x141286a10
UIDebugGuideDialog::~UIDebugGuideDialog()
{
    FUN_140bccd50()->FUN_140da51e0(0x87, Delegate<void(CInPacket&)>(this, &UIDebugGuideDialog::OnPacket));
}

// @0x141286ba0
CString UIDebugGuideDialog::vfunc_1()
{
    return "DebugGuideDialog";
}

// @0x141286bf0
void UIDebugGuideDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    m_groups.clear();
    LoadXml("./Data/XmlDebug/DebugCommandCustom.xml");
    CString strPath = Unk_SocketFormat("{0}_{1}.xml", "./Data/XmlDebug/DebugCommand", FUN_140651350());
    if (GetFileSystem()->FUN_1403987d0(std::string(strPath)) == 0)
        strPath = FUN_1411c0aa0("./Data/XmlDebug/DebugCommand.xml");
    LoadXml(strPath);
    m_movie = FUN_1409b40c0(m_28, (*m_30).FUN_1422bb890());
    do {
        m_30->FUN_140bc7340("m_leftList", m_leftList);
        if (m_leftList == NULL)
            throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError",
                                                      MS2_THIS_FILE, MS2_LINE(107), __FUNCTION__));
    } while (0);
    do {
        m_30->FUN_140bc7340("m_rightList", m_rightList);
        if (m_rightList == NULL)
            throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError",
                                                      MS2_THIS_FILE, MS2_LINE(108), __FUNCTION__));
    } while (0);
    do {
        m_30->FUN_140bbe640("m_executeButton", m_executeButton);
        if (m_executeButton == NULL)
            throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError",
                                                      MS2_THIS_FILE, MS2_LINE(109), __FUNCTION__));
    } while (0);
    do {
        m_30->FUN_140bbe640("m_multiExecuteButton", m_multiExecuteButton);
        if (m_multiExecuteButton == NULL)
            throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError",
                                                      MS2_THIS_FILE, MS2_LINE(110), __FUNCTION__));
    } while (0);
    do {
        m_30->FUN_140bbe940("m_input", m_input);
        if (m_input == NULL)
            throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError",
                                                      MS2_THIS_FILE, MS2_LINE(111), __FUNCTION__));
    } while (0);
    FUN_141925fa0("m_dragBar");
    FUN_141925ec0("m_closeButton");
    m_leftList->FUN_1422e1890(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIDebugGuideDialog::OnSelectGroup));
    m_rightList->FUN_1422e1890(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIDebugGuideDialog::OnSelectCommand));
    m_executeButton->FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIDebugGuideDialog::OnExecute), 0);
    m_multiExecuteButton->FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIDebugGuideDialog::OnMultiExecute), 0);
    reinterpret_cast<Unk_DebugGuideMovie*>(m_movie.operator->())->FUN_1422c3600("doubleClick", Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIDebugGuideDialog::OnDoubleClick), 0, 0, 0, 0);
    FillGroups();
}

// @0x141287b50
void UIDebugGuideDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_leftList = 0;
    m_rightList = 0;
    m_executeButton = 0;
    m_multiExecuteButton = 0;
    m_input = 0;
    m_movie = 0;
}

// @0x141287bf0
// MS2-FUNCTIONAL: control flow follows the exe; the key is read through an extra register copy.
int UIDebugGuideDialog::vfunc_13()
{
    if (UIDialog::vfunc_13())
        return 1;
    for (int i = 0; i < 10; i++)
    {
        if (FUN_14025e7c0()->FUN_14116d9c0(i + 0x3b, true, 0) && PrintCommand(i))
            return 1;
    }
    return 0;
}

// @0x141287c80
// MS2-FUNCTIONAL: control flow follows the exe; the two loop-read string locals sit in swapped stack slots.
void UIDebugGuideDialog::OnPacket(CInPacket& iPacket)
{
    int nType = iPacket.vfunc_o8_1();
    if (nType == 7)
    {
        CStringW strHeader = iPacket.vfunc_o8_8();
        int nCount = iPacket.vfunc_o8_3();
        for (int i = 0; i < nCount; i++)
        {
            CStringW strDesc = iPacket.vfunc_o8_8();
            CStringW strName = iPacket.vfunc_o8_8();
            PrintLine(CStringW(strName), CStringW(strDesc));
            FUN_1412751b0(FUN_1406564a0(L"{0}님이 {1} {2} 커맨드 실행", strHeader, strDesc, strName), 20);
        }
    }
}

// @0x141287ed0
void UIDebugGuideDialog::OnSelectGroup(const Scaleform::GFx::FunctionHandler::Params& rParams)
{
    FillCommands();
    ShowExplain();
}

// @0x141287f00
void UIDebugGuideDialog::OnSelectCommand(const Scaleform::GFx::FunctionHandler::Params& rParams)
{
    ShowExplain();
}

// @0x141287f30
void UIDebugGuideDialog::OnExecute(const Scaleform::GFx::FunctionHandler::Params& rParams)
{
    PrintCommand(-1);
}

// @0x141287f60
void UIDebugGuideDialog::OnMultiExecute(const Scaleform::GFx::FunctionHandler::Params& rParams)
{
    SendCommand(-1);
}

// @0x141287f90
void UIDebugGuideDialog::OnDoubleClick(const Scaleform::GFx::FunctionHandler::Params& rParams)
{
    PrintCommand(-1);
}

// @0x141287fc0
// MS2-FUNCTIONAL: control flow follows the exe; the exe keeps the load result in an int local and destroys the group temporaries in a different order.
void UIDebugGuideDialog::LoadXml(CString strPath)
{
    bool bTemp = false;
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 1, true, false) != 0)
    {
        Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
        if (pRoot == 0)
        {
            FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        }
        else
        {
            for (Unk_140165cf0* pElem = pRoot->FUN_140165cf0("Group"); pElem != 0; pElem = pElem->FUN_140168650("Group"))
            {
                Unk_DebugGuideGroup group(pElem);
                bool bSkip;
                if (group.m_strCharOnly.IsEmpty())
                {
                    bSkip = false;
                }
                else
                {
                    bTemp = true;
                    bSkip = !FUN_140164830(FUN_1403ed2d0()->FUN_141bd0d30(), group.m_strCharOnly);
                }
                if (bTemp)
                    bTemp = false;
                if (!bSkip)
                    m_groups.push_back(group);
            }
        }
    }
}

// @0x141288200
void UIDebugGuideDialog::FillGroups()
{
    m_leftList->FUN_1422dd1d0();
    for (unsigned int i = 0; i < m_groups.size(); i++)
        m_leftList->FUN_1422dd310(m_groups[i].m_strName);
    if (!m_groups.empty())
        m_leftList->FUN_1422dcca0(0);
    m_leftList->vfunc_24(true);
    FillCommands();
}

// @0x141288320
// MS2-FUNCTIONAL: control flow follows the exe; temporaries differ.
void UIDebugGuideDialog::FillCommands()
{
    if (!m_groups.empty())
    {
        int nGroup = m_leftList->FUN_1422dccd0();
        if (nGroup < (int)m_groups.size())
        {
            m_rightList->FUN_1422dd1d0();
            Unk_DebugGuideGroup& rGroup = m_groups[nGroup];
            for (unsigned int i = 0; i < rGroup.m_commands.size(); i++)
            {
                CStringW strPrefix;
                if (i < 10)
                {
                    int nKey = i + 1;
                    strPrefix = FUN_140292a70(L"F{0}] ", nKey);
                }
                m_rightList->FUN_1422dd310(FUN_140656190(L"{0}{1}", strPrefix, rGroup.m_commands[i].m_strName));
            }
            if (!rGroup.m_commands.empty())
                m_rightList->FUN_1422dcca0(0);
            m_rightList->vfunc_24(true);
        }
    }
}

// @0x141288570
// MS2-FUNCTIONAL: control flow follows the exe; temporaries differ.
void UIDebugGuideDialog::ShowExplain()
{
    int nGroup = m_leftList->FUN_1422dccd0();
    if (nGroup < (int)m_groups.size())
    {
        int nCommand = m_rightList->FUN_1422dccd0();
        if (nCommand < (int)m_groups[nGroup].m_commands.size())
        {
            CStringW strText = m_groups[nGroup].m_commands[nCommand].m_strDesc;
            strText.Replace(L"\\n", L"\n");
            FUN_140cfee80(FUN_1422dbc00(), "explainText", strText);
        }
    }
}

// @0x141288770
// MS2-FUNCTIONAL: control flow follows the exe; temporaries differ.
bool UIDebugGuideDialog::PrintCommand(int nIndex)
{
    int nGroup = m_leftList->FUN_1422dccd0();
    if (nGroup < (int)m_groups.size())
    {
        int nCommand = nIndex;
        if (nCommand < 0)
            nCommand = m_rightList->FUN_1422dccd0();
        if (nCommand < (int)m_groups[nGroup].m_commands.size())
        {
            Unk_DebugGuideCommand& rCommand = m_groups[nGroup].m_commands[nCommand];
            if (FUN_140a3ab70(0x4e61) != 0)
            {
                for (int i = 0; i < (int)rCommand.m_args.size(); i++)
                {
                    Unk_DebugGuideArg& rArg = rCommand.m_args[i];
                    if (!rArg.m_bUseArg)
                        PrintLine(rArg.m_strCmd, L"");
                    else
                        PrintLine(rArg.m_strCmd, m_input->FUN_1422e0b00().Trim());
                }
            }
            return true;
        }
    }
    return false;
}

// @0x141288a70
// MS2-FUNCTIONAL: control flow follows the exe; temporaries differ.
bool UIDebugGuideDialog::SendCommand(int nIndex)
{
    int nGroup = m_leftList->FUN_1422dccd0();
    if (nGroup < (int)m_groups.size())
    {
        int nCommand = nIndex;
        if (nCommand < 0)
            nCommand = m_rightList->FUN_1422dccd0();
        if (nCommand < (int)m_groups[nGroup].m_commands.size())
        {
            Unk_DebugGuideCommand& rCommand = m_groups[nGroup].m_commands[nCommand];
            unsigned __int64 nCount = rCommand.m_args.size();
            COutPacket pkt(0x50, 0);
            pkt.vfunc_o10_1(7);
            pkt.vfunc_o10_3((int)nCount);
            for (unsigned __int64 i = 0; i < nCount; i++)
            {
                Unk_DebugGuideArg& rArg = rCommand.m_args[i];
                pkt.vfunc_o10_8(rArg.m_strCmd);
                if (!rArg.m_bUseArg)
                    pkt.vfunc_o10_8(CStringW(L""));
                else
                    pkt.vfunc_o10_8(m_input->FUN_1422e0b00().Trim());
            }
            FUN_140710590(&pkt);
            return true;
        }
    }
    return false;
}

// @0x141288d00
void UIDebugGuideDialog::PrintLine(CStringW strName, CStringW strArg)
{
    void* pChat = FUN_140a3ab70(0x4e61);
    if (pChat != 0)
    {
        if (strArg.IsEmpty())
            FUN_141a25770(pChat, CStringW(strName), 0);
        else
            FUN_141a25770(pChat, FUN_140656190(L"{0} {1}", strName, strArg), 0);
    }
}

MS2_REPLACE_METHOD(0x1412864C0, Unk_DebugGuideArg, Read, 82, 0x3EB8FB22);
MS2_REPLACE_METHOD(0x141286520, Unk_DebugGuideCommand, Read, 430, 0xBCACC3BB);
MS2_REPLACE_METHOD(0x1412866E0, Unk_DebugGuideCommand, AddArg, 41, 0xF69EC827);
MS2_REPLACE_METHOD(0x141286780, Unk_DebugGuideGroup, Read, 197, 0x7154E43F);
MS2_REPLACE_METHOD(0x141286BA0, UIDebugGuideDialog, vfunc_1, 61, 0x68749244);
MS2_REPLACE_METHOD(0x141287B50, UIDebugGuideDialog, vfunc_26, 150, 0x5640E0C4);
MS2_REPLACE_METHOD(0x141287BF0, UIDebugGuideDialog, vfunc_13, 135, 0xBA54EFC5);
MS2_REPLACE_METHOD(0x141287C80, UIDebugGuideDialog, OnPacket, 579, 0x32B73FF0);
MS2_REPLACE_METHOD(0x141287ED0, UIDebugGuideDialog, OnSelectGroup, 39, 0x4515AE00);
MS2_REPLACE_METHOD(0x141287F00, UIDebugGuideDialog, OnSelectCommand, 29, 0xCAE34F3D);
MS2_REPLACE_METHOD(0x141287F30, UIDebugGuideDialog, OnExecute, 34, 0x7A657B6C);
MS2_REPLACE_METHOD(0x141287F60, UIDebugGuideDialog, OnMultiExecute, 34, 0xA31DBF6A);
MS2_REPLACE_METHOD(0x141287F90, UIDebugGuideDialog, OnDoubleClick, 34, 0xBAE75FCF);
MS2_REPLACE_METHOD(0x141287FC0, UIDebugGuideDialog, LoadXml, 568, 0xBF5E6968);
MS2_REPLACE_METHOD(0x141288200, UIDebugGuideDialog, FillGroups, 270, 0x779F4A50);
MS2_REPLACE_METHOD(0x141288320, UIDebugGuideDialog, FillCommands, 575, 0x1B679EEF);
MS2_REPLACE_METHOD(0x141288570, UIDebugGuideDialog, ShowExplain, 500, 0x08318E2B);
MS2_REPLACE_METHOD(0x141288770, UIDebugGuideDialog, PrintCommand, 755, 0x894A9C52);
MS2_REPLACE_METHOD(0x141288A70, UIDebugGuideDialog, SendCommand, 641, 0xADFD931B);
MS2_REPLACE_METHOD(0x141288D00, UIDebugGuideDialog, PrintLine, 222, 0x9B4D9414);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142caec60-0x142caed60 .text$yd
