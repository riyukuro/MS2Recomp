// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UINameTagSymbolSettingDialog: see
// uinametagsymbolsettingdialog.h.
// MS2-UNIT: ?\uinametagsymbolsettingdialog.cpp
// MS2-RANGE: 0x1400ef050-0x1400ef1c0 .text$di
// MS2-RANGE: 0x14131d910-0x14131e150 .text$mn
// MS2-PIN: ??_GUINameTagSymbolSettingDialog@@UEAAPEAXI@Z 0x14131e0e0
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uinametagsymbolsettingdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uinametagsymbolsettingdialog.h"

#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

#include "ms2/placeholder/unk_1402a9d70.h"

static CString s_sortNames[] = { "None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd" };
static CString s_skill("skill");
static CString s_stun("stun");
static Unk_1402a9d70 s_conditionTable(17, 0.75f, 0.25f, 2.25f, 10);

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// The "m_list" control of the movie (the AS list with clear / append / select).
class Unk_NtList : public AScript
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);
    void FUN_1422dcca0(int n);                                      // select a row
    void FUN_1422dd230(const ASObj& row);                           // append a row
};

// The record of one symbol (the tooltip fields).
class Unk_NtInfo
{
public:
    char m_pad_00[0x34];
    int m_34;                                                       // +0x34 tooltip string id (0 = none)
    short m_38;                                                     // +0x38 tooltip argument
};

// The handle of a symbol record: the layout of an MS2Ptr (null test is the second word).
struct Unk_NtInfoRef
{
    ~Unk_NtInfoRef() { FUN_1406c7070(); }
    Unk_NtInfo* operator->() { return FUN_1406c71c0(); }
    void FUN_1406c7070();                                           // release
    Unk_NtInfo* FUN_1406c71c0();                                    // the record
    void* m_0;
    void* m_8;
};

struct Unk_NtPlayer;
short FUN_141661e00(Unk_NtPlayer* pPlayer);                         // the symbol the player wears

// The name tag symbol manager (global at 0x143ab05b8): its list of symbol ids is at +0x40.
class Unk_NtMgr
{
public:
    Unk_NtInfoRef FUN_1406c58c0(short nId);                         // the record of a symbol
    int FUN_1406c5a70(short nId);                                   // can this symbol be picked
    int FUN_1406c5c80(short nId);                                   // hidden
    int FUN_1406c5d60(short nId);                                   // owned
    CStringW FUN_1406c61a0(short nId, Unk_NtPlayer* pPlayer);       // icon path
    char m_pad_00[0x40];
    char m_ids[1];                                                  // +0x40 the id list
};
class Unk_SingletonObj { public: virtual ~Unk_SingletonObj(); };    // the type the global is mapped with
extern Unk_SingletonObj* DAT_143ab05b8;                             // the manager
Unk_NtMgr* FUN_14131e120();                                         // 0x14131e120 the manager
char* FUN_14131e130(Unk_NtMgr* p);                                  // 0x14131e130 &m_ids
size_t FUN_140186250(char* pIds);                                   // count
short* FUN_140184490(char* pIds, size_t nIndex);                    // element

void* FUN_1403ed2d0();
Unk_NtPlayer* FUN_141bd0cc0(void* p);                               // the local player
void FUN_1422ba6e0();

class Unk_NtStrings
{
public:
    CStringW FUN_141811980(int nId, short nArg);                    // string of (id, symbol)
    CStringW FUN_141812290(int nId, short nArg, CString strKey);    // tooltip string
};
Unk_NtStrings* FUN_1401a9d70();
void FUN_140710590(COutPacket& packet);

// @0x14131e0b0
inline bool FUN_14131e0b0(Unk_NtInfoRef* p)
{
    return p->m_8 == 0;
}

// @0x14131d910
UINameTagSymbolSettingDialog::UINameTagSymbolSettingDialog()
{
    FUN_141924170(0);
    m_88 = 1;
}

// @0x14131d980
UINameTagSymbolSettingDialog::~UINameTagSymbolSettingDialog()
{
}

// @0x14131d9c0
CString UINameTagSymbolSettingDialog::GetTypeName()
{
    return "NameTagSymbolSettingDialog";
}
MS2_REPLACE_METHOD(0x14131D9C0, UINameTagSymbolSettingDialog, GetTypeName, 61, 0xCDA77D77);

// @0x14131da10
void UINameTagSymbolSettingDialog::vfunc_67()
{
    UIDialog::vfunc_67();
}
MS2_REPLACE_METHOD(0x14131DA10, UINameTagSymbolSettingDialog, vfunc_67, 24, 0x6C682280);

// MS2-FUNCTIONAL: OnLoadComplete: the exe keeps extra pointer temps around the list and string helper results (stack frame)
// @0x14131da30
void UINameTagSymbolSettingDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    Unk_NtPlayer* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    unsigned int nSelected = 0;
    MS2Ptr<Unk_NtList> spList = FUN_140c02900(CString("m_list"));
    if (spList.get() != 0)
    {
        char* pIds = FUN_14131e130(FUN_14131e120());
        int nRow = 0;
        for (size_t i = 0; i < FUN_140186250(pIds); ++i)
        {
            short nId = *FUN_140184490(pIds, i);
            Unk_NtInfoRef info = FUN_14131e120()->FUN_1406c58c0(nId);
            if (!FUN_14131e0b0(&info))
            {
                if (FUN_14131e120()->FUN_1406c5c80(nId) == 0)
                {
                    ASObj row(2);
                    row.FUN_1409c48f0("id", nId);
                    row.FUN_1407cbb20("icon", FUN_14131e120()->FUN_1406c61a0(nId, pPlayer));
                    row.FUN_1407cbbe0("disabled", FUN_14131e120()->FUN_1406c5d60(nId) == 0);
                    row.FUN_1407cbb20("title", FUN_1401a9d70()->FUN_141811980(0x27, nId));
                    row.FUN_1407cbb20("desc", FUN_1401a9d70()->FUN_141811980(0x28, nId));
                    if (info.operator->()->m_34 != 0)
                    {
                        row.FUN_1407cbb20("info", FUN_1401a9d70()->FUN_141812290(info.operator->()->m_34,
                                                                               info.operator->()->m_38,
                                                                               CString("tooltipDescription")));
                    }
                    spList.operator->()->FUN_1422dd230(row);
                    if (nId == FUN_141661e00(pPlayer))
                        nSelected = nRow;
                    ++nRow;
                }
            }
        }
        spList.operator->()->vfunc_24(true);
        spList.operator->()->FUN_1422dcca0(nSelected);
    }
}
MS2_REPLACE_METHOD(0x14131DA30, UINameTagSymbolSettingDialog, OnLoadComplete, 1203, 0x2FB46A41);

// @0x14131def0
int UINameTagSymbolSettingDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) != 0)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x14131DEF0, UINameTagSymbolSettingDialog, OnMessage, 60, 0x37A60664);

// @0x14131df40
int UINameTagSymbolSettingDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("onOk", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            short nId = data.FUN_1422b8a10();
            if (FUN_14131e120()->FUN_1406c5a70(nId) != 0)
            {
                COutPacket packet(static_cast<int>(SendOp::Insignia), 0);
                packet.WriteInt16(nId);
                FUN_140710590(packet);
            }
        }
        vfunc_67();
        return 1;
    }
    else
    {
        if (_stricmp("onCancel", szMethod) == 0)
        {
            vfunc_67();
            return 1;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14131DF40, UINameTagSymbolSettingDialog, vfunc_28, 363, 0x33CFAF3D);

// @0x14131e120
Unk_NtMgr* FUN_14131e120()
{
    return (Unk_NtMgr*)DAT_143ab05b8;
}

// @0x14131e130
char* FUN_14131e130(Unk_NtMgr* p)
{
    return p->m_ids;
}

// @0x14131e140
int UINameTagSymbolSettingDialog::vfunc_48()
{
    return 0x4ed5;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cafd30-0x142cafdc0 .text$yd
