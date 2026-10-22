// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIMoveFieldDialog: see uimovefielddialog.h.
// MS2-UNIT: ?\uimovefielddialog.cpp
// MS2-RANGE: 0x141a55740-0x141a57b00 .text$mn
// MS2-RANGE: 0x140118e40-0x140118fe0 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?vfunc_48@UIMoveFieldDialog@@UEAAHXZ 0x141a57a20 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??1UIMoveFieldDialog@@UEAA@XZ 0x141a57940
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uimovefielddialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "uimovefielddialog.h"

#include <algorithm>
#include <vector>

#include "ms2/client/ms2/mypc.h"
#include "ms2/commonfiles/fielddata.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/header_statics_a.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/commandchat.h"

static UICommon::CMyPCKeyInputController s_keyInput;

// ---- unit-local placeholders (unrecovered helpers) ----

// The list control of the movie (the AS list with clear / append).
class Unk_MoveFieldList : public AScript
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);
    void FUN_1422dd230(const ASObj& row);               // append a row
};

// The key input state (singleton).
class Unk_14025e7c0 { public: bool FUN_14116d9c0(int nKey, int a, int b); bool FUN_14116d840(); };
Unk_14025e7c0* FUN_14025e7c0();

// The player manager (singleton): the local player.
class Unk_MoveFieldPlayers { public: MyPC* FUN_141bd0cc0(); };
Unk_MoveFieldPlayers* FUN_1403ed2d0();

// Unk_CommandChat: placeholder/commandchat.h (the chat command record).
void FUN_141276f80(const Unk_CommandChat&);

void FUN_140d73bc0(int nTable, int nId, void* pListener, CStringW strExtra);    // pop the system message nTable
void FUN_140841420(CStringW& str);                                              // trim
CStringTable* FUN_1401a9d70();
extern int DAT_143ab2914;                                                       // the character level

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x141a55740
UIMoveFieldDialog::UIMoveFieldDialog()
{
    m_40 = 1;
    FUN_1422dc3b0(1);
}

// @0x141a557b0
CString UIMoveFieldDialog::vfunc_1()
{
    return "MoveFieldDialog";
}

// @0x141a55800
void UIMoveFieldDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    FUN_141a55de0();
}

// @0x141a55830
int UIMoveFieldDialog::vfunc_13()
{
    if (UIDialog::vfunc_13())
        return 1;
    if (FUN_14025e7c0()->FUN_14116d9c0(0x1c, 0, 0)) {
        if (m_30.get())
            m_30->Invoke("onEnterKey");
        return 1;
    } else if (FUN_14025e7c0()->FUN_14116d840()) {
        vfunc_67();
        return 1;
    }
    return 0;
}

// @0x141a55900
int UIMoveFieldDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (DAT_143ab2914 < 50)
        return 0;
    ASData data;
    if (_stricmp("OnMoveField", szMethod) == 0) {
        MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPlayer == 0 || pPlayer->FUN_14166ce30() != 0) {
            FUN_140d73bc0(0x42, 0, 0, CStringW(L""));
            return 1;
        }
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            CStringW strField = data.FUN_1422b8f40();
            int nField = _wtoi(strField);
            if (CFieldData::FUN_140374410(nField) == true) {
                FUN_140d73bc0(0x51, 0, 0, CStringW(L""));
            } else {
                pPlayer->SendFunctionCube();
                Unk_CommandChat chat;
                chat.kind = 0;
                chat.message = StringFormat(L"/MoveField {0}", strField);
                FUN_141276f80(chat);
            }
        }
        return 1;
    } else if (_stricmp("OnAddField", szMethod) == 0) {
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            CStringW strField = data.FUN_1422b8f40();
            int nField = _wtoi(strField);
            if (CFieldData::FUN_140374410(nField)) {
                FUN_140d73bc0(0x14, 0, 0, CStringW(L""));
                return 1;
            }
            Unk_CommandChat chat;
            chat.kind = 0;
            chat.message = StringFormat(L"/AddField {0}", strField);
            FUN_141276f80(chat);
        }
        return 1;
    } else if (_stricmp("OnSearchField", szMethod) == 0) {
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            CStringW strFilter = data.FUN_1422b8f40();
            FUN_140841420(strFilter);
            strFilter.Remove(L' ');
            FUN_141a55e30(strFilter);
        }
        return 1;
    }
    return 0;
}

// @0x141a55de0
void UIMoveFieldDialog::FUN_141a55de0()
{
    CStringW strFilter(L"");
    FUN_141a55e30(strFilter);
}

// @0x141a55e30
void UIMoveFieldDialog::FUN_141a55e30(const CStringW& strFilter)
{
    MS2Ptr<Unk_MoveFieldList> list = FUN_140c02900("m_fieldList");
    if (list == 0)
        return;
    std::vector<MS2Ptr<CFieldData> > fields;
    CFieldData::FUN_140374090(fields);
    // The comparator (operator() @0x141a57960): by field id.
    std::sort(fields.begin(), fields.end(), [](MS2Ptr<CFieldData> a, MS2Ptr<CFieldData> b) { return (unsigned)a->m_nFieldID < (unsigned)b->m_nFieldID; });
    unsigned bFilter = !strFilter.IsEmpty();
    for (MS2Ptr<CFieldData>& field : fields) {
        CStringW strId = StringFormat(L"{0}", reinterpret_cast<const unsigned&>(field->m_nFieldID));
        int nFieldId = field->m_nFieldID;
        CStringW strSpaced = FUN_1401a9d70()->FUN_141811980(3, nFieldId);
        FUN_140841420(strSpaced);
        CStringW strName(strSpaced);
        strSpaced.Remove(L' ');
        unsigned bMatch = !bFilter;
        if (bFilter) {
            if (strId.Find(strFilter, 0) != -1) {
                bMatch = 1;
            } else {
                if (strSpaced.Find(strFilter, 0) != -1)
                    bMatch = 1;
            }
        }
        if (bMatch && strId.Find(L"_deco", 0) == -1 && strName.GetLength() != 0) {
            ASObj row(2);
            row.FUN_1407cbb20("code", strId);
            row.FUN_1407cbb20("field", strName);
            ((Unk_MoveFieldList*)list)->FUN_1422dd230(row);
        }
    }
    ((Unk_MoveFieldList*)list)->vfunc_24(true);
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cc0d10-0x142cc0dc0 .text$yd
