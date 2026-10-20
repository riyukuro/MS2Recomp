// uiequipiconcontainer.h - UIEquipIconContainer (RTTI .?AVUIEquipIconContainer@@, 0x78 bytes, CPtred + one virtual: the
// destructor): the equipment icons of a character preview, keyed by equip slot. It drives the "equipItem" /
// "changeEquipItem" / "unequipItem" calls of its movie clip. Owning unit: client\ms2\uiequipiconcontainer.cpp
// (0x140e29f60-0x140e2cc90). Header name assumed from the unit path (w48); member names are invented.
#pragma once
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/asequipicon.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/cptred.h"

class Unk_EquipOutfit;      // the outfit the icons were built from (a CPtred; lists its items)
class Unk_EquipItemPtr;     // an item handle (callee-destroyed when passed by value)

class UIEquipIconContainer : public CPtred
{
public:
    UIEquipIconContainer();                                             // 0x140e29f60
    virtual ~UIEquipIconContainer();                                    //  0 0x140e2a000 (??_G 0x140e2b9d0)

    MS2Ptr<ASEquipIcon> FUN_140e2a090(int nSlot, MS2Ptr<CItem> pItem, MS2Ptr<AScript> pSrc, MS2Ptr<Unk_EquipOutfit> pOutfit);   // equip an item in a slot (creating or changing its icon)
    void FUN_140e2a640(int nSlot);                                      // remove the slot's icon
    void FUN_140e2a670();                                               // remove every icon
    void FUN_140e2a6e0(int nVisible);                                   // show / hide the clip
    MS2Ptr<ASEquipIcon> FUN_140e2a740(int nSlot);                       // the slot's icon (0: none)
    int FUN_140e2a7e0(Unk_EquipItemPtr pItem);                          // the hand slot (4 / 5) a weapon goes to
    int FUN_140e2a7e0(MS2Ptr<CItemData> spData);                        // 0x140e2a7e0 the same, the item handle spelled as it is (uimeratmarketdialog.cpp)
    ATL::CAtlMap<int, MS2Ptr<ASEquipIcon> >* GetIconMap() { return &m_28; }   // 0x1413157e0 (inline; uimeratmarketdialog.cpp)
    MS2Ptr<ASEquipIcon> FUN_140e2a990(int nSlot, MS2Ptr<CItem> pItem, MS2Ptr<AScript> pSrc);                         // create the slot's icon
    MS2Ptr<ASEquipIcon> FUN_140e2ad70(MS2Ptr<ASEquipIcon> pIcon, int nSlot, MS2Ptr<CItem> pItem, MS2Ptr<AScript> pSrc);   // change the slot's icon
    void FUN_1412d6ca0(MS2Ptr<ASMovieClip> pClip);                      // 0x1412d6ca0 inline: m_18 = pClip (defined in uiitempreviewdialog.cpp)
    void FUN_140e2b140(int nSlot);                                      // remove the slot's icon (unEquipItem)

private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<ASMovieClip> m_18;                                           // +0x18 the equip icon clip
    ATL::CAtlMap<int, MS2Ptr<ASEquipIcon> > m_28;                       // +0x28 slot -> icon
    int m_70;                                                           // +0x70 the last hand slot used
};
MS2_CHECK_SIZE(UIEquipIconContainer, 0x78);
MS2_CHECK_OFFSET(UIEquipIconContainer, m_18, 0x18);
MS2_CHECK_OFFSET(UIEquipIconContainer, m_28, 0x28);
MS2_CHECK_OFFSET(UIEquipIconContainer, m_70, 0x70);
