// guideentity.h - the guide entity (one step of a guide quest): the condition lists that start, advance, close and cancel it
// and the actions it runs. Layout proven from ctor 0x1413a2a50, dtor 0x1413a2b40 and the accessors in
// client\ms2\guideentity.cpp (0x1413a2c00..). The base is a CPtred. NOT an original header (member names invented).
#pragma once

#include <map>

#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cguidecondition.h"
#include "ms2/placeholder/cguideaction.h"

class Unk_140165cf0;

// 0xd8.
class CGuideEntity : public CPtred
{
public:
    CGuideEntity();                                         // 0x1413a2a50
    virtual ~CGuideEntity();                                // 0 0x1413a2b40

    unsigned GetSaveId() const;                             // 0x1413a2c00
    unsigned GetSaveStep() const;                           // 0x1413a2c20
    int GetForce() const;                                   // 0x1413a2c40
    int IsSaveSkipped() const;                              // 0x1413a2c60: no save id, or saving disabled
    int CheckStart(bool* pbOpen, unsigned* pnFailed);      // 0x1413a2ca0: the trigger conditions, then the open conditions
    int CheckClose(unsigned* pnFailed);                    // 0x1413a2dd0
    int CheckCancel(unsigned* pnFailed);                   // 0x1413a2e70
    void GetFailedText(CStringW& strOut, bool bTrigger, unsigned nIdx);   // 0x1413a2f30
    void GetCloseText(CStringW& strOut, unsigned nIdx);     // 0x1413a30a0
    void GetCancelText(CStringW& strOut, unsigned nIdx);    // 0x1413a3150
    void StartActions();                                    // 0x1413a3210
    void StopActions();                                     // 0x1413a32a0
    int AreActionsDone();                                  // 0x1413a3330
    bool Load(Unk_140165cf0* pElem);                        // 0x1413a33c0
    void Clear(bool bNotify);                               // 0x1413a35d0
    void SetState(int nState);                              // 0x1413a3670
    void UpdateConditions();                                // 0x1413a36b0
    void MoveStartedConditions();                           // 0x1413a3720
    void CollectTriggerValues(std::map<int, int>& mapValues);   // 0x1413a3820
    void LoadConditions(Unk_140165cf0* pElem, Unk_GcCondList& list);   // 0x1413a3960
    void LoadActions(Unk_140165cf0* pElem, CAtlArray<MS2Ptr<CGuideAction> >& list);   // 0x1413a3a30
    void PruneConditions(Unk_GcCondList& list);             // 0x1413a3b00
    void ResetConditions(Unk_GcCondList& list);             // 0x1413a3be0

    unsigned m_nId;                                         // +0x18
    int m_nState;                                           // +0x1c: 0 idle, 1 / 2 running
    CStringW m_strDesc;                                     // +0x20
    int m_nForce;                                           // +0x28
    unsigned m_nSaveId;                                     // +0x2c
    unsigned m_nSaveStep;                                   // +0x30
    int m_nNoSave;                                          // +0x34
    Unk_GcCondList m_condTrigger;                           // +0x38
    Unk_GcCondList m_condOpen;                              // +0x58
    Unk_GcCondList m_condClose;                             // +0x78
    Unk_GcCondList m_condCancel;                            // +0x98
    CAtlArray<MS2Ptr<CGuideAction> > m_actions;             // +0xb8
};
MS2_CHECK_SIZE(CGuideEntity, 0xd8);
