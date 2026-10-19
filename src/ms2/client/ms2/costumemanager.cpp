// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CostumeManager: see costumemanager.h.
// MS2-UNIT: ?\costumemanager.cpp
// MS2-RANGE: 0x140b1d2b0-0x140b1dcf0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?FindNextNode@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEBAPEAVCNode@12@PEAV312@@Z 0x140b1da30 ; unique
// MS2-PIN: ?GetNext@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x140b1db90 ; unique
// MS2-PIN: ?GetStartPosition@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEBAPEAU__POSITION@@XZ 0x140b1dbe0 ; unique
// MS2-PIN: ?GetValueAt@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAAAEAHPEAU__POSITION@@@Z 0x140b1dc50 ; unique
// MS2-PIN: ?IsEmpty@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEBA_NXZ 0x140b1dcc0 ; unique
// MS2-PINS-END tplpin
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\costumemanager.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "costumemanager.h"

#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/avatarpc.h"

__int64 FUN_14028d0e0();                                    // the current server time
int FUN_141658e60(PC* pPC);                                 // 0x141658e60 the partner gem id of an actor
int FUN_141420f90(CItem* pItem, AvatarPC* pAvatar);         // 0x141420f90 the customize id of an item
CItem* FUN_14052cd70(MS2Ptr<CItem>* pItem);                 // 0x14052cd70 the item of a handle

extern Unk_CostumeTable* DAT_143aaf318;

// @0x140b1db00
Unk_CostumeTable* FUN_140b1db00()
{
    return DAT_143aaf318;
}

// @0x140b1d2b0
CostumeManager::CostumeManager(AvatarPC* pOwner) : m_pOwner(pOwner), m_nCostumeId(0), m_items(10)
{
}

// @0x140b1d320
CostumeManager::~CostumeManager()
{
}

// @0x140b1d360
// MS2-FUNCTIONAL: the exe passes the kind / owner id / time locals through an extra register hop (mov ecx,[x]; mov edx,ecx);
// source shape not found, flow and calls match.
void CostumeManager::FUN_140b1d360(int nCostumeId)
{
    unsigned int nKind = FUN_141658e60(m_pOwner);
    MS2Ptr<Unk_CostumeRow> spRow = FUN_140b1db00()->FUN_1405360b0(nCostumeId, nKind);
    if (spRow == 0)
        return;
    if (m_nCostumeId != 0)
        FUN_140b1d890(m_nCostumeId);
    for (POSITION pos = spRow->m_mapPart2.GetStartPosition(); pos != 0; spRow->m_mapPart2.GetNext(pos))
    {
        int nItemId = spRow->m_mapPart2.GetValueAt(pos);
        if (nItemId == 0)
            continue;
        MS2Ptr<CItem> spItem(new CItem);
        if (!spItem->FUN_140523c40(nItemId, 1, 0))
            continue;
        int nCustomize = FUN_141420f90(FUN_14052cd70(&spItem), m_pOwner);
        spItem->FUN_140526c10(nCustomize);
        __int64 nTime = FUN_14028d0e0();
        spItem->FUN_140526a70(nTime);
        int nOwnerId = m_pOwner->FUN_14123c580();
        spItem->FUN_140526b30(nOwnerId);
        spItem->FUN_14052a130(4);
        m_pOwner->vfunc_127(FUN_14052cd70(&spItem), 0);
        m_items.AddTail(spItem);
    }
    for (POSITION pos = spRow->m_mapPart1.GetStartPosition(); pos != 0; spRow->m_mapPart1.GetNext(pos))
    {
        int nItemId = spRow->m_mapPart1.GetValueAt(pos);
        if (nItemId == 0)
            continue;
        MS2Ptr<CItem> spItem(new CItem);
        if (!spItem->FUN_140523c40(nItemId, 1, 0))
            return;
        int nCustomize = FUN_141420f90(FUN_14052cd70(&spItem), m_pOwner);
        spItem->FUN_140526c10(nCustomize);
        int nOwnerId = m_pOwner->FUN_14123c580();
        spItem->FUN_140526b30(nOwnerId);
        __int64 nTime = FUN_14028d0e0();
        spItem->FUN_140526a70(nTime);
        spItem->FUN_14052a130(4);
        m_pOwner->vfunc_127(FUN_14052cd70(&spItem), 0);
        m_items.AddTail(spItem);
    }
    m_nCostumeId = nCostumeId;
}

// @0x140b1d890
void CostumeManager::FUN_140b1d890(int nCostumeId)
{
    if (m_nCostumeId != nCostumeId)
        return;
    for (POSITION pos = m_items.GetHeadPosition(); pos != 0; m_items.GetNext(pos))
    {
        MS2Ptr<CItem> spItem = m_items.GetAt(pos);
        if (spItem == 0)
            continue;
        m_pOwner->vfunc_128(FUN_14052cd70(&spItem), 0);
    }
    m_items.RemoveAll();
    m_nCostumeId = 0;
}
