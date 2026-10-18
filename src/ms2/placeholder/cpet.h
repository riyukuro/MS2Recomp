// cpet.h - shared declaration of CPet (efd RTTI "CPet", class id 0x06200074; derives CNpc; 0x10b0 bytes): the summoned /
// tamed pet actor. NOT an original header. Constructor 0x140b0f4c0, destructor 0x140b0f840, deleting dtor 0x140b12310
// (passes 0x10b0). Defined in unit_140b0f4c0 (src/ms2/unnamed/unit_140b0f4c0.cpp). vftables 0x142dd98e0 (IBase) and
// 0x142dd9cf8 (NiActorManager::CallbackObject).
#pragma once

#include "ms2/placeholder/cnpc.h"
#include "ms2/placeholder/ccpetinfopacket.h"
#include "ms2/placeholder/mctimer.h"
#include "ms2/client/ms2/uitamingbar.h"

// A row of the pet table (FUN_14052d210()->FUN_1407290f0(nPetId)); only the proven field is named.
class Unk_PetRow : public CPtred
{
public:
    int m_nF18;                                             // +0x18 (1: the pet takes part in the summon button state; petmanager.cpp)
    char m_pad_1c[0x9c - 0x1c];
    float m_fScaleBonus;                                    // +0x9c added to the pet's body height (vfunc_89)
    int m_nSlots;                                           // +0xa0 the pet inventory's slot count (petmanager.cpp)
};

class CPet : public CNpc
{
    EE_DECLARE_CLASS1(CPet, 0x06200074, CNpc);

public:
    CPet();                                                 // 0x140b0f4c0
    virtual ~CPet();                                        // 0x140b0f840

    virtual void vfunc_16() override;                       // 0x140b0fdf0 hide the taming bar, drop its entity
    virtual void vfunc_52(double fTime) override;           // 0x140b0ff40
    virtual void vfunc_53(float f) override;                // 0x140b0fb90
    virtual int vfunc_58() override;                        // 0x140b100f0
    virtual float vfunc_89() override;                      // 0x140b0fca0
    virtual float vfunc_97() override;                      // 0x140b0f9d0
    virtual int vfunc_116() override;                       // 0x140b0f9b0
    virtual int vfunc_124(int nNpcId) override;             // 0x140b0f930
    virtual void vfunc_125(int n) override;                 // 0x140b0fe30
    virtual void vfunc_126(int a, int b) override;          // 0x140b0f970
    virtual int vfunc_127() override;                       // 0x140b11460
    virtual bool vfunc_128() override;                      // 0x140b10140
    virtual MS2Ptr<UITamingBar::Entity> vfunc_129();        // 0x140b11050 the taming bar entity (created on demand)

    int FUN_140b10150();                                    // the pet is unusable by its owner (hidden / forbidden)
    void FUN_140b10210(int nPetId);                         // m_nPetId + its table row
    int FUN_140b10290();                                    // m_nPetId
    MS2Ptr<Unk_PetRow> FUN_140b102b0();                     // copy of the row
    int FUN_140b10300();                                    // m_nF44
    PCBase* FUN_140b10320();                                // the owner as a PC (null when it is not one)
    PCBase* FUN_140b10360();                                // the owner (class 0x6200003 cast helper 0x1409613d0)
    CCPetInfoPacket::Info* FUN_140b103a0();                 // &m_info
    void FUN_140b103c0(void* p);                            // m_info.FUN_1401ffd00(p)
    void FUN_140b10400();                                   // refresh the field object's drop / light state
    void FUN_140b10510();                                   // keep the two aura effects of the taming state alive
    void FUN_140b107f0(int nId);                            // m_nTargetId; arm the taming bar when it is the local player's pet
    int FUN_140b109f0();                                    // m_nKind
    void FUN_140b10a10(unsigned __int64 nPoint);            // taming point changed
    unsigned __int64 FUN_140b10c00();                       // m_nTamingPoint
    bool FUN_140b10c20();                                   // m_nTamingPoint == TamingPetMaxPoint
    void FUN_140b10c80(CStringW str);                       // set the pet's display name
    void FUN_140b10f90(unsigned short n);                   // m_nGrade + its sound/effect id
    unsigned short FUN_140b10fe0();                         // m_nGrade
    int FUN_140b11000();                                    // m_nGradeFx
    void FUN_140b11020();                                   // FUN_140291d10(m_nGradeFx)
    int FUN_140b11180();                                    // use a pet skill (returns 1: used)
    void FUN_140b11320(float fTime);                        // accumulate the idle time, finish the owner's emote
    void FUN_140b114e0(int nAnimId);                        // play a pet animation
    void FUN_140b11760(CString strEffect);                  // spawn an effect on the pet
    int FUN_140b11810(int nSkillType, unsigned nSkillId, unsigned short nLevel);   // skill may be used

    int m_nPetId;                                           // +0xf40
    int m_nF44;                                             // +0xf44 = 1
    MS2Ptr<Unk_PetRow> m_spRow;                             // +0xf48
    CCPetInfoPacket::Info m_info;                           // +0xf58
    Timer m_timer1030;                                      // +0x1030 (armed 1000 ms)
    Unk_McTimer m_tm1068;                                   // +0x1068
    int m_nKind;                                            // +0x1070
    unsigned __int64 m_nTamingPoint;                        // +0x1078
    unsigned short m_nGrade;                                // +0x1080
    int m_nGradeFx;                                         // +0x1084 = 1
    int m_nFxOther;                                         // +0x1088 effect handle (other user's trap area / grade)
    int m_nFxMax;                                           // +0x108c effect handle (max point)
    MS2Ptr<UITamingBar::Entity> m_spBar;                    // +0x1090
    int m_nTargetId;                                        // +0x10a0
    int m_nIdleMs;                                          // +0x10a4
    Unk_McTimer m_tm10a8;                                   // +0x10a8
};
MS2_CHECK_SIZE(CPet, 0x10b0);
MS2_CHECK_OFFSET(CPet, m_spRow, 0xf48);
MS2_CHECK_OFFSET(CPet, m_info, 0xf58);
MS2_CHECK_OFFSET(CPet, m_timer1030, 0x1030);
MS2_CHECK_OFFSET(CPet, m_tm1068, 0x1068);
MS2_CHECK_OFFSET(CPet, m_nKind, 0x1070);
MS2_CHECK_OFFSET(CPet, m_nTamingPoint, 0x1078);
MS2_CHECK_OFFSET(CPet, m_nFxOther, 0x1088);
MS2_CHECK_OFFSET(CPet, m_spBar, 0x1090);
MS2_CHECK_OFFSET(CPet, m_nTargetId, 0x10a0);
MS2_CHECK_OFFSET(CPet, m_tm10a8, 0x10a8);
