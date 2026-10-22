// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIGameMakerMainDialog (UI type 0x4f6f, "GameMakerMainDialog"): the
// game maker's Lua script panel (pick a .lua file, send it or a console line to the server). Class declared in this file
// (no known header); the tail of the unit is the std::vector<char> resize glue of "OnPlay".
// MS2-UNIT: ?\uigamemakermaindialog.cpp
// MS2-RANGE: 0x140c193f0-0x140c19f20 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uigamemakermaindialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <afxdlgs.h>
#include <vector>
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

class ASDialog : public ASDisplayObject {};

// UIGameMakerMainDialog: RTTI .?AVUIGameMakerMainDialog@@, vftables (primary) and +0x18 (IMessageListener).
class UIGameMakerMainDialog : public UIDialog
{
public:
    UIGameMakerMainDialog();                                                // 0x140c193f0
    virtual ~UIGameMakerMainDialog();                                       //  0 0x140c19450
    virtual CString GetTypeName();                                              //  1 0x140c194b0
    virtual void OnLoadComplete();                                          // 22 0x140c19500
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                            // 28 0x140c19520
    virtual void vfunc_43();                                                // 43 0x140c19a30
    virtual int vfunc_48() { return 0x4f6f; }                               // 48 (COMDAT 0x140c19e90)

    CString m_strPath;                                                      // +0x178 the chosen script file
};
MS2_CHECK_SIZE(UIGameMakerMainDialog, 0x180);

// @0x140c193f0
UIGameMakerMainDialog::UIGameMakerMainDialog()
{
}

// @0x140c19450
UIGameMakerMainDialog::~UIGameMakerMainDialog()
{
}

// @0x140c194b0
CString UIGameMakerMainDialog::GetTypeName()
{
    return "GameMakerMainDialog";
}
MS2_REPLACE_METHOD(0x140C194B0, UIGameMakerMainDialog, GetTypeName, 61, 0xAABBDD2A);

// @0x140c19500
void UIGameMakerMainDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
}
MS2_REPLACE_METHOD(0x140C19500, UIGameMakerMainDialog, OnLoadComplete, 24, 0xEDBAA11B);

// @0x140c19520
// MS2-FUNCTIONAL: behaviour-equivalent; the CFileDialog temporaries (GetPathName / GetFileName) get extra copies in our cl
int UIGameMakerMainDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp("OnOpen", szMethod) == 0) {
        CString strFilter("Lua Script (*.lua)|*.lua|");
        CFileDialog dlg(0, ".lua", 0, 0, strFilter, 0, 0, 1);
        if (dlg.DoModal() == 1) {
            m_strPath = dlg.GetPathName();
            m_30->Invoke("setLabel", dlg.GetFileName());
            return 1;
        }
        return 1;
    }
    else if (_stricmp("OnPlay", szMethod) == 0) {
        CFile file;
        file.Open(m_strPath, 0x4000, 0);
        ULONGLONG nLength = file.GetLength();
        std::vector<char> buffer;
        buffer.resize(nLength + 1);
        file.Read(&buffer[0], (UINT)nLength);
        buffer[nLength] = 0;
        COutPacket packet(0xae, 0);
        packet.vfunc_o10_2(0x1e);
        packet.vfunc_o10_7(CString(&buffer[0]));
        FUN_140710590(packet);
        return 1;
    }
    else if (_stricmp("OnConsole", szMethod) == 0) {
        return 1;
    }
    else if (_stricmp("OnExecute", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            CString strCommand = data.FUN_1422b8d30();
            if (strCommand.GetLength() == 0)
                return 1;
            COutPacket packet(0xae, 0);
            packet.vfunc_o10_2(0x1e);
            packet.vfunc_o10_7(strCommand);
            FUN_140710590(packet);
        }
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140C19520, UIGameMakerMainDialog, vfunc_28, 1267, 0x7827B062);

// @0x140c19a30
void UIGameMakerMainDialog::vfunc_43()
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
        pDialog->vfunc_2(8, -5, -5);
}
MS2_REPLACE_METHOD(0x140C19A30, UIGameMakerMainDialog, vfunc_43, 109, 0x2637275E);
