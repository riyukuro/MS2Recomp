// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: unit_14164dfd0
// MS2-RANGE: 0x14164dfd0-0x14166a650 .text$mn
// MS2-RANGE: 0x1400fb010-0x1400fb4d0 .text$di
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/state.h"
#include "hook/ms2hook.h"

extern void FUN_1411e0810(Unk_PCEquipSet* equipment);
extern void FUN_141b6f220(NiAVObject* root, int kind, const Unk_CharEquip* equipment);
extern int FUN_140869420();

// @0x141651d00
void PC::vfunc_15()
{
    PCBase::vfunc_15();
    FUN_1411e0810(&m_kEquipDE0);
}
MS2_REPLACE_METHOD(0x141651D00, PC, vfunc_15, 43, 0x5A36F6F9);

// @0x141652030
void PC::vfunc_31(bool enabled)
{
    switch (FUN_14166c930())
    {
    case 0x3f:
        enabled = false;
        break;
    }
    GameObject::vfunc_31(enabled);
}
MS2_REPLACE_METHOD(0x141652030, PC, vfunc_31, 61, 0x5A226AF8);

// @0x1416537d0
void PC::vfunc_59(int state, StateData* data, int substate, int force)
{
    if (!vfunc_124(state, substate))
        return;
    PCBase::vfunc_59(state, data, substate, force);
}
MS2_REPLACE_METHOD(0x1416537D0, PC, vfunc_59, 94, 0x9CB1080D);

// @0x141654840
int PC::vfunc_64() { return 0; }
MS2_REPLACE_METHOD(0x141654840, PC, vfunc_64, 8, 0x7F371472);

// @0x1416561a0
Unk_PCEquipSet* PC::FUN_1416561a0() { return &m_kEquipDE0; }
MS2_REPLACE_METHOD(0x1416561A0, PC, FUN_1416561a0, 17, 0x1D689B1E);

// @0x141658cd0
CStringW PC::vfunc_134() { return CStringW(L""); }
MS2_REPLACE_METHOD(0x141658CD0, PC, vfunc_134, 61, 0xE16DABBF);

// @0x141658f70
void PC::FUN_141658f70(unsigned char flags) { m_nFF9 |= flags; }
MS2_REPLACE_METHOD(0x141658F70, PC, FUN_141658f70, 42, 0xE44E913E);

// @0x141659700
Unk_PCCubeCraft* PC::FUN_141659700() { return m_pCubeCraft; }
MS2_REPLACE_METHOD(0x141659700, PC, FUN_141659700, 18, 0x829A31E1);

// @0x14165f050
void PC::vfunc_138(NiAVObject* root, int kind, const Unk_CharEquip* equipment)
{
    FUN_141b6f220(root, kind, equipment);
}
MS2_REPLACE_METHOD(0x14165F050, PC, vfunc_138, 48, 0xB5D4861C);

// @0x14165fec0
void PC::vfunc_113(void* data)
{
    PCBase::vfunc_113(data);
    m_n1200 = FUN_140869420();
}
MS2_REPLACE_METHOD(0x14165FEC0, PC, vfunc_113, 50, 0x3953A97A);

// @0x141660f80
void PC::vfunc_144()
{
    FUN_14166ccb0()->vfunc_23();
}
MS2_REPLACE_METHOD(0x141660F80, PC, vfunc_144, 48, 0x840E7B21);

// @0x141661be0
int PC::vfunc_145() { return 1; }
MS2_REPLACE_METHOD(0x141661BE0, PC, vfunc_145, 11, 0x30025ED0);

// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__FstrMgr@?1??GetInstance@CAtlStringMgr@ATL@@SAPEAUIAtlStringMgr@2@XZ@YAXXZ 0x14166a060 ; prop
// MS2-PINS-END tplpin
