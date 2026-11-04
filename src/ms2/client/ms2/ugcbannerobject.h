// ugcbannerobject.h - UgcBannerObject (RTTI .?AVUgcBannerObject@@, 0x28 bytes, base CPtred, vftable 0x142dea500 with
// the scalar deleting dtor only): the client-side wrapper of a UGC banner entity (id and visibility are read from
// the entity). Owning unit: ?\ugcbannerobject.cpp (0x140b9c680-0x140b9c920). Header name assumed; member and
// method names invented.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/client/ms2/cubespawnobject.h"     // egf::EntityPtr

class UgcBannerObject : public CPtred
{
public:
    UgcBannerObject(egf::EntityPtr ent);                // 0x140b9c680 (ent by value: the callee destroys it)
    virtual ~UgcBannerObject();                     // 0x140b9c710

    unsigned int GetBannerId() const;               // 0x140b9c750
    void SetVisible(unsigned char bVisible);                 // 0x140b9c770 pushes the flag to the entity
    unsigned char GetVisible() const;                        // 0x140b9c7f0
    Unk_Entity* GetEntity() const;                  // 0x140b9c810
    void Init();                                    // 0x140b9c840 reads id / visibility from the entity

private:
    MS2_LAYOUT_FRIEND;
    egf::EntityPtr m_ent;                               // +0x18
    unsigned int m_nBannerId;                       // +0x20
    unsigned char m_bVisible;                                // +0x24
};
MS2_CHECK_SIZE(UgcBannerObject, 0x28);
MS2_CHECK_OFFSET(UgcBannerObject, m_ent, 0x18);
MS2_CHECK_OFFSET(UgcBannerObject, m_nBannerId, 0x20);
