// clonepc.h - ClonePC (RTTI "ClonePC"): a PC that mirrors another PC's look for a UI model view (the "Mannequin").
// Base of AvatarPC (?\avatarpc.cpp) and PortraitPC (?\portraitpc.cpp), which put their listener base
// (IAvatarObjectEventListener / UIItemEventListener) at +0x1340. Owning unit: ?\clonepc.cpp (0x141086ae0-0x14108e1e0,
// not recovered). Header name assumed. Heap-only.
//
// Size 0x1340 (??_G 0x14108bbf0 frees 0x1340). vftable 0x142ea7b80 (153 slots: PC's 147 + 147..152), CallbackObject
// vftable 0x142ea8050 (dtor thunk 0x14108bb58). efd: TypeCast 0x14108c2b0 / 0x14108c260, GetClassDesc 0x14108be60.
// Ctor 0x141087420 (homes rcx/rdx only; calls PC::PC(this) 0x14164dfd0), dtor 0x141086ae0.
// Overrides (out of line in clonepc.cpp): 9 0x141086b70, 12 0x1410875f0, 14 0x1410876b0, 26 0x141086e60 (return 0),
// 49 0x141086cb0 (empty), 55 0x141087cd0 / 56 0x141087c90 (gated on m_b12fa), 68 0x141086ea0 (return false),
// 80/82/83/85/86/87 0x141086ce0/d20/d60/da0/de0/e20 (null MS2Ptr), 88 0x141086e70 (0), 93 0x141087290 (empty),
// 133 0x141086e80 (0), 139 0x141086c30, 143 0x141086cc0 (PC::vfunc_143), 145 0x1410872a0 (0).
// Only the overrides a derived unit needs are declared below; vfunc_24's COMDAT (0x1409f7f40) is in avatarpc.
#pragma once
#include <efd/StdContainers.h>
#include <atlcoll.h>
#include <efd/SmartPointer.h>
#include <vector>
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/fittingdollpc.h"

class UIModelView;   // NiRefObject-derived (UIRenderView); smart pointer COMDATs: ctor 0x14108aea0, dtor 0x140cb1460
class NiAVObject;
class CEquipItem;       // RTTI CPtred-derived, ?\equipitem.cpp
class AdditionalCli;    // RTTI CPtred-derived buff record (0x78), ?\additionalcli.cpp
class NiActorManager;   // the equip model records are NiActorManagers (GetNIFRoot() = COMDAT 0x1409f7cb0)

// The 8-byte poll timer of the preview refresh (FUN_140268870: true once nMs have passed since the last true).
struct Unk_CloneTimer
{
    // @0x140517b00 (COMDAT in client\ms2\clonepc.cpp)
    Unk_CloneTimer() { m_nA = 0; m_nB = 0; }
    int FUN_140268870(unsigned int nMs);                    // 0x140268870
    int m_nA;
    int m_nB;
};

class ClonePC : public PC
{
    EE_DECLARE_CLASS1(ClonePC, 0x0620004f, PC);   // ClassInfo 0x143acdbc0 (setup COMDAT 0x1409f7fc0 in avatarpc)

public:
    ClonePC(PC* pSource);                                   // 0x141087420 m_pSourcePC = pSource; copies its id
    virtual ~ClonePC();                                     // 0x141086ae0

    // @0x1409f7f40
    virtual void vfunc_24(int) { m_unk_40 = 0; }            // 24 (inline; COMDAT in avatarpc)
    virtual void vfunc_12();                                // 12 0x1410875f0
    virtual void vfunc_14();                                // 14 0x1410876b0
    // slots AvatarPC inherits from here (declared so the vftable resolves to the exe slots)
    virtual Unk_GoAttachment* vfunc_26();                   // 26 0x141086e60
    virtual void vfunc_49();                                // 49 0x141086cb0
    virtual bool vfunc_55(float a, float b);                // 55 0x141087cd0
    virtual bool vfunc_56(float f);                         // 56 0x141087c90
    virtual bool vfunc_68(void* a, double t, int b, unsigned c, int d);// 68 0x141086ea0
    virtual MS2Ptr<Unk_PCBaseComp_a58> vfunc_80();          // 80 0x141086ce0
    virtual MS2Ptr<Unk_PCBaseComp_a78> vfunc_82();          // 82 0x141086d20
    virtual MS2Ptr<Unk_PCBaseComp_a88> vfunc_83();          // 83 0x141086d60
    virtual MS2Ptr<Unk_PCBaseComp_aa8> vfunc_85();          // 85 0x141086da0
    virtual MS2Ptr<Unk_PCBaseComp_ab8> vfunc_86();          // 86 0x141086de0
    virtual MS2Ptr<Unk_PCBaseComp_ac8> vfunc_87();          // 87 0x141086e20
    virtual UISwfEntity* vfunc_88();                        // 88 0x141086e70
    virtual void vfunc_93(bool b);                          // 93 0x141087290
    virtual void vfunc_9(void* p);                          // 9 0x141086b70
    virtual int vfunc_133(CItem* pItem, bool b);            // 133 0x141086e80
    virtual void vfunc_139();                               // 139 0x141086c30
    virtual void vfunc_143();                               // 143 0x141086cc0
    virtual int vfunc_145();                                // 145 0x1410872a0
    // new virtuals
    virtual void vfunc_147(UIModelView* pView);             // 147 0x141086bc0 m_spModelView = pView
    virtual UIModelView* vfunc_148();                       // 148 0x141086c00
    virtual void vfunc_149();                               // 149 0x141086ec0 (PortraitPC 0x141699d60)
    virtual int vfunc_150();                                // 150 0x141087280 return 0
    virtual void vfunc_151();                               // 151 0x141087d20
    // pList receives the equip records of pEquip (the source PC's holder or this clone's own, +0xde0)
    virtual void vfunc_152(ATL::CAtlList<MS2Ptr<CEquipItem> >* pList, Unk_PCEquipSet* pEquip);   // 152 0x1410884f0

    // non-virtual (out of line in the unrecovered clonepc unit; called by AvatarPC)
    void FUN_141087220(bool b);                             // 0x141087220 m_b12fa = b, then vfunc_47(b)
    bool FUN_141087260();                                   // 0x141087260 m_b12fa
    bool FUN_1410872b0(MS2Ptr<AdditionalCli> spCli);        // 0x1410872b0 adds a buff record to the PC's list and m_kClis
    void FUN_141087390();                                   // 0x141087390 marks the model view dirty (m_b12f9 = 1)
    void FUN_1410873b0();                                   // 0x1410873b0 m_b12f8 = 1
    void FUN_1410873d0();                                   // 0x1410873d0 forgets the source PC
    static void FUN_141087400(bool b);                      // 0x141087400 DAT_143acdb20 = b
    void FUN_141087770();                                   // 0x141087770 pre-update hook of the view refresh
    void FUN_141087790();                                   // 0x141087790 post-update hook of the view refresh
    void FUN_141087850();                                   // 0x141087850 syncs the name/job from the source PC (by m_unk_12fc)
    bool FUN_141088620();                                   // 0x141088620 m_b12fb
    void FUN_141088640(bool b);                             // 0x141088640 m_b12fb = b
    bool FUN_141088590();                                   // 0x141088590 m_b1338
    void FUN_1410885b0(bool b);                             // 0x1410885b0 m_b1338 = b
    void FUN_1410885d0(Delegate<void(ATL::CAtlList<MS2Ptr<CEquipItem> >*, Unk_PCEquipSet*)> kFilter);   // 0x1410885d0 m_kEquipFilter = kFilter (callee-destroyed)
    void FUN_1410879c0(ATL::CAtlArray<efd::SmartPointer<NiActorManager>>& kOut);   // 0x1410879c0 collects the equip records

public:
    MS2_LAYOUT_FRIEND;
    PC* m_pSourcePC;                                        // +0x12e0 ctor argument
    int m_nSourceId;                                        // +0x12e8 m_pSourcePC->FUN_14123c580()
    efd::SmartPointer<UIModelView> m_spModelView;           // +0x12f0
    bool m_b12f8;                                           // +0x12f8 = 0
    bool m_b12f9;                                           // +0x12f9 = 0
    bool m_b12fa;                                           // +0x12fa = 0 (gates vfunc_55/56)
    bool m_b12fb;                                           // +0x12fb = 1
    int m_unk_12fc;                                         // +0x12fc = 1
    std::list<NiAVObject*> m_kList1300;                     // +0x1300 (ctor 0x141043710, dtor 0x141043950)
    Delegate<void(ATL::CAtlList<MS2Ptr<CEquipItem> >*, Unk_PCEquipSet*)> m_kEquipFilter;   // +0x1310 (ctor 0x14108ae80, dtor 0x14108b370)
    Unk_CloneTimer m_unk_1318;                              // +0x1318 8-byte timer value (ctor 0x140517b00 zeroes it)
    std::vector<MS2Ptr<AdditionalCli> > m_kClis;            // +0x1320 (ctor 0x14108b300, dtor 0x14108b4c0)
    bool m_b1338;                                           // +0x1338 = 0
};
MS2_CHECK_SIZE(ClonePC, 0x1340);
MS2_CHECK_OFFSET(ClonePC, m_pSourcePC, 0x12e0);
MS2_CHECK_OFFSET(ClonePC, m_spModelView, 0x12f0);
MS2_CHECK_OFFSET(ClonePC, m_b12fa, 0x12fa);
MS2_CHECK_OFFSET(ClonePC, m_unk_12fc, 0x12fc);
MS2_CHECK_OFFSET(ClonePC, m_kList1300, 0x1300);
MS2_CHECK_OFFSET(ClonePC, m_kEquipFilter, 0x1310);
MS2_CHECK_OFFSET(ClonePC, m_kClis, 0x1320);
MS2_CHECK_OFFSET(ClonePC, m_b1338, 0x1338);
