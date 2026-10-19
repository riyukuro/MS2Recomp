// questmasktable.h - CQuestMaskTable (commonfiles\questmasktable.cpp, RTTI .?AVCQuestMaskTable@@, 0x98 bytes).
// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The member names are invented where the exe has none.
//
// CQuestMaskTable is a TSingleton created by CGameApp::InitInstance. It reads QuestMaskPortal.xml and QuestMaskNpc.xml
// (field id -> object key -> the quest mask that has to be satisfied to use the portal / talk to the npc) and answers
// whether the local player passes a mask.
#pragma once

#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/blackmarketitemoption.h"
#include "ms2/placeholder/tptr.h"

// One quest range: the start quest / state and the end quest / state (16 bytes).
struct Unk_Z16i { int a, b, c, d; };

// RTTI QuestMask (a struct: .?AUQuestMask@@), 0x40 bytes: whether the mask is enabled (1 by default) and the quest
// ranges that make it up.
struct QuestMask : public CPtred
{
public:
    QuestMask();                                        // 0x140266860
    bool FUN_140266970() const;                         // every range is satisfied (and there is one)

    int m_nEnable;                                      // +0x18 the "enableInMask" flag
    int m_pad_1c;
    ATL::CAtlArray<Unk_Z16i> m_aRanges;                 // +0x20
};
MS2_CHECK_SIZE(QuestMask, 0x40);

// The exe's RTTI names the inner map TPtredDummy<CAtlMap<unsigned, TPtr<struct QuestMask>>>: the 16-byte CPtred
// pointer (Unk_BmPtr's code) under its real template name.
template <> class TPtr<QuestMask>
{
public:
    TPtr() { m_p = 0; }
    TPtr(int) { m_p = 0; }
    TPtr(QuestMask* p) { m_p = p; AddRef(); }
    TPtr(const Unk_BmNewTag&) { m_p = 0; Make(); }
    TPtr(const TPtr& o) { m_p = o.m_p; AddRef(); }
    TPtr(TPtr&& o) { m_p = o.m_p; o.m_p = 0; }
    ~TPtr() { Release(); }
    TPtr& operator=(const TPtr& o) { o.AddRef(); Release(); m_p = o.m_p; return *this; }
    TPtr& operator=(const Unk_BmNewTag&) { Make(); return *this; }
    QuestMask* get() const { return m_p; }
    QuestMask* operator->() const { return m_p; }
    QuestMask& operator*() const { return *m_p; }
    bool operator==(QuestMask* p) const { return m_p == p; }

private:
    void AddRef() const { if (m_p) AddRefImpl(0); }
    void Make() { Release(); m_p = Create(0); }
    void Release() { if (m_p) { ReleaseImpl(0); m_p = 0; } }
    static QuestMask* Allocate(void*) { return new QuestMask(); }
    static QuestMask* Create(void*) { return static_cast<QuestMask*>(FUN_1401ba820(Allocate(0))); }
    static void Ref(CPtred* p) { CPtred::AddRefPtred(p); }
    void AddRefImpl(void*) const { Ref(m_p); }
    void ReleaseImpl(void*) { if (CPtred::ReleasePtred(m_p) == 0) { Ref(m_p); CPtred::DeletePtred(m_p); } }
    void* m_00;
    QuestMask* m_p;
};
MS2_CHECK_SIZE(TPtr<QuestMask>, 0x10);
typedef TPtr<QuestMask> Unk_QmMaskPtr;
typedef ATL::CAtlMap<unsigned, Unk_QmMaskPtr> Unk_QmMaskMap;                      // object key -> mask
typedef Unk_BmBoxPtr<Unk_QmMaskMap> Unk_QmFieldPtr;
typedef ATL::CAtlMap<unsigned, Unk_QmFieldPtr> Unk_QmFieldMap;                    // field id -> its masks

// The portal object the table is asked about: its key at +0x20 and its own mask at +0x108.
struct Unk_QmPortal
{
    char m_pad_00[0x20];
    int m_nKey;                                         // +0x20
    char m_pad_24[0x108 - 0x24];
    QuestMask m_mask;                                   // +0x108
};
MS2_CHECK_SIZE(Unk_QmPortal, 0x148);

class CQuestMaskTable : public TSingleton<CQuestMaskTable>
{
public:
    CQuestMaskTable();                                  // 0x1407648d0
    virtual ~CQuestMaskTable();                         // 0x140764980

    bool Load();                                        // 0x1407649d0
    bool LoadFile(const CStringA& strFile, Unk_QmFieldMap& rMap);           // 0x140765080
    Unk_QmMaskPtr GetPortalMask(unsigned nField, int nKey);                 // 0x140764a90
    Unk_QmMaskPtr GetNpcMask(unsigned nField, int nKey);                    // 0x140764b90
    bool HasNpcMask(void* pNpc);                        // 0x140764c90
    bool HasNpcMaskHere(int nKey);                      // 0x140764cd0 in the current field
    bool HasPortalMask(Unk_QmPortal* pPortal);          // 0x140764d50
    void CheckNpcHere(int nKey);                        // 0x140764e00
    int CheckNpc(unsigned nField, int nKey);            // 0x140764e40
    int CheckNpcObject(void* pNpc);                     // 0x140764ef0
    int CheckPortal(Unk_QmPortal* pPortal);             // 0x140764f30

    Unk_QmFieldMap m_npcMasks;                          // +0x08
    Unk_QmFieldMap m_portalMasks;                       // +0x50
};
MS2_CHECK_SIZE(CQuestMaskTable, 0x98);
MS2_CHECK_OFFSET(CQuestMaskTable, m_npcMasks, 0x08);
MS2_CHECK_OFFSET(CQuestMaskTable, m_portalMasks, 0x50);
