// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIRangePreviewDialog: see uirangepreviewdialog.h.
// MS2-UNIT: ?\uirangepreviewdialog.cpp
// MS2-RANGE: 0x141346a40-0x141347260 .text$mn
// MS2-PIN: ??1UIRangePreviewDialog@@UEAA@XZ 0x141346a90
// MS2-PIN: ??_GUIRangePreviewDialog@@UEAAPEAXI@Z 0x141347050
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uirangepreviewdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uirangepreviewdialog.h"

#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

void* FUN_141347090(void* pMap, void** pPos);
void* FUN_1413470e0(void* pMap, void* pos);

// Debug flags (the check boxes' state).
extern char DAT_143ae95e0;              // skill range, pc
extern char DAT_143ae95e1;              // skill range, npc
extern char DAT_143ae95e2;              // collision, pc
extern char DAT_143ae95e3;              // collision, npc

// An npc's data record handle (2 pointers); record fields at +0x2d8 / +0x2dc. The npc hands out a Tmp that is copied into
// the Data handle.
struct Unk_RpDataTmp
{
    ~Unk_RpDataTmp();                                   // 0x1406d5390
    void* m_a;
    void* m_b;
};
struct Unk_RpData
{
    Unk_RpData(const Unk_RpDataTmp& o);                 // 0x1406cf850
    ~Unk_RpData();                                      // 0x14035e5b0
    bool FUN_1406a9050(int n);
    char* FUN_14035eb90();                              // the record
    void* m_a;
    void* m_b;
};
class Unk_RpNpc : public PCBase
{
public:
    Unk_RpDataTmp FUN_141093270();                      // the npc's data record handle
};

// The npc map iterator and the npc size setters.
struct Unk_RpExtent { float cx, cy; };
class Unk_RpWorld
{
public:
    void* FUN_141bd36d0();                              // npc tree
};
Unk_RpWorld* FUN_1403ed2d0();
void* FUN_1406d6e90();
void FUN_140a7cbe0(void* p);
void* FUN_140a7b840(void* pMap);
void* FUN_140a7b9f0(void* pMap, void* pos);
PCBase* FUN_140a7b650(void* pEntry);
Unk_RpExtent* FUN_140a0a600(Unk_RpExtent* pOut, float cx, float cy);
class Unk_RpBody;
void FUN_141670d50(PCBase* pNpc, Unk_RpExtent kExtent);
Unk_RpBody* FUN_14166d220(PCBase* pNpc);
void FUN_141240520(Unk_RpBody* pBody, float cx, float cy);
void FUN_140159b70(long hr);                            // AtlThrow

// @0x141346a40
UIRangePreviewDialog::UIRangePreviewDialog()
{
    m_40 = 1;
}

// @0x141346ad0
CString UIRangePreviewDialog::GetTypeName()
{
    return "RangePreviewDialog";
}
MS2_REPLACE_METHOD(0x141346AD0, UIRangePreviewDialog, GetTypeName, 61, 0xE3FB3AF4);

// @0x141346b20
void UIRangePreviewDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    ASObj obj(2);
    obj.FUN_1407cbbe0("collisionPC", DAT_143ae95e2);
    obj.FUN_1407cbbe0("collisionNPC", DAT_143ae95e3);
    obj.FUN_1407cbbe0("skillPC", DAT_143ae95e0);
    obj.FUN_1407cbbe0("skillNPC", DAT_143ae95e1);
    m_30->Invoke("initData", obj.FUN_1422bb870());
}
MS2_REPLACE_METHOD(0x141346B20, UIRangePreviewDialog, OnLoadComplete, 282, 0x7D8BCB79);

// @0x141346c40
int UIRangePreviewDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("onCheckCollision", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_141346dc0(this, &data);
        return 1;
    }
    if (_stricmp("onCheckSkillRange", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_141346e00(this, &data);
        return 1;
    }
    if (_stricmp("onClickNpcExtentReload", szMethod) == 0) {
        OnClickNpcExtentReload();
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141346C40, UIRangePreviewDialog, vfunc_28, 370, 0x2E61E272);

// @0x141346dc0
void FUN_141346dc0(UIRangePreviewDialog* pDialog, ASData* pArgs)
{
    DAT_143ae95e2 = pArgs->FUN_1422b8a90();
    DAT_143ae95e3 = pArgs->FUN_1422b8a90();
}

// @0x141346e00
void FUN_141346e00(UIRangePreviewDialog* pDialog, ASData* pArgs)
{
    DAT_143ae95e0 = pArgs->FUN_1422b8a90();
    DAT_143ae95e1 = pArgs->FUN_1422b8a90();
}

// @0x141346e40
void UIRangePreviewDialog::OnClickNpcExtentReload()
{
    FUN_140a7cbe0(FUN_1406d6e90());
    void* pMap = FUN_1403ed2d0()->FUN_141bd36d0();
    for (void* pos = FUN_140a7b840(pMap); pos != 0; FUN_141347090(pMap, &pos))
    {
        PCBase* pNpc = FUN_140a7b650(FUN_1413470e0(pMap, pos));
        if (pNpc != 0)
        {
            Unk_RpData kData(static_cast<Unk_RpNpc*>(pNpc)->FUN_141093270());
            if (kData.FUN_1406a9050(0) != 0)
                continue;
            Unk_RpExtent kSize;
            FUN_141670d50(pNpc, *FUN_140a0a600(&kSize, *(float*)(kData.FUN_14035eb90() + 0x2d8),
                                               *(float*)(kData.FUN_14035eb90() + 0x2dc)));
            FUN_141240520(FUN_14166d220(pNpc), *(float*)(kData.FUN_14035eb90() + 0x2d8),
                          *(float*)(kData.FUN_14035eb90() + 0x2dc));
            NiPoint3 kPos = pNpc->vfunc_18();
            kPos.z += *(float*)(kData.FUN_14035eb90() + 0x2dc);
            pNpc->vfunc_19(*reinterpret_cast<efd::Point3*>(&kPos));
        }
    }
}

// @0x141347090
void* FUN_141347090(void* pMap, void** pPos)
{
    void* pOld = *pPos;
    *pPos = FUN_140a7b9f0(pMap, pOld);
    return pOld;
}

// @0x1413470d0
int UIRangePreviewDialog::vfunc_48()
{
    return 0x4eb5;
}

// @0x1413470e0
void* FUN_1413470e0(void* pMap, void* pos)
{
    if (pos != 0)
        return (char*)pos + 8;
    FUN_140159b70(0x80004005);
    return 0;
}

MS2_EMIT_CRT_MEMMOVE_S();
