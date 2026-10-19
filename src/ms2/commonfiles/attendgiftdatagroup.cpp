// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). AttendGiftDataGroup / AttendGiftData / AttendGiftDataTable:
// the attendance gift table (Table/AttendGiftData.xml).
// MS2-UNIT: ?\attendgiftdatagroup.cpp
// MS2-RANGE: 0x1401adea0-0x1401b3c70 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0AEAIAEAV?$Unk_AttendPtr@VAttendGiftData@@@@$0A@@?$pair@IV?$Unk_AttendPtr@VAttendGiftData@@@@@std@@QEAA@AEAIAEAV?$Unk_AttendPtr@VAttendGiftData@@@@@Z 0x1401ae810 ; unique
// MS2-PIN: ??$?0IV?$Unk_AttendPtr@VAttendGiftData@@@@$0A@@?$pair@$$CBIV?$Unk_AttendPtr@VAttendGiftData@@@@@std@@QEAA@$$QEAU?$pair@IV?$Unk_AttendPtr@VAttendGiftData@@@@@1@@Z 0x1401ae860 ; unique
// MS2-PIN: ??$construct@V?$Unk_AttendPtr@UItemGift@@@@V1@@?$_Default_allocator_traits@V?$allocator@V?$Unk_AttendPtr@UItemGift@@@@@std@@@std@@SAXAEAV?$allocator@V?$Unk_AttendPtr@UItemGift@@@@@1@QEAV?$Unk_AttendPtr@UItemGift@@@@$$QEAV3@@Z 0x1401b0470 ; unique
// MS2-PIN: ??$construct@V?$Unk_AttendPtr@VAttendGiftDataGroup@@@@V1@@?$_Default_allocator_traits@V?$allocator@V?$Unk_AttendPtr@VAttendGiftDataGroup@@@@@std@@@std@@SAXAEAV?$allocator@V?$Unk_AttendPtr@VAttendGiftDataGroup@@@@@1@QEAV?$Unk_AttendPtr@VAttendGiftDataGroup@@@@$$QEAV3@@Z 0x1401b0560 ; unique
// MS2-PIN: ??$make_pair@AEAIAEAV?$Unk_AttendPtr@VAttendGiftData@@@@@std@@YA?AU?$pair@IV?$Unk_AttendPtr@VAttendGiftData@@@@@0@AEAIAEAV?$Unk_AttendPtr@VAttendGiftData@@@@@Z 0x1401b0880 ; unique
// MS2-PIN: ??1?$pair@$$CBIV?$Unk_AttendPtr@VAttendGiftData@@@@@std@@QEAA@XZ 0x1401b1080 ; unique
// MS2-PIN: ??1?$pair@IV?$Unk_AttendPtr@VAttendGiftData@@@@@std@@QEAA@XZ 0x1401b10a0 ; prop
// MS2-PIN: ??_G?$TSingleton@VAttendGiftDataTable@@@@UEAAPEAXI@Z 0x1401b1580 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\attendgiftdatagroup.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <utility>
#include "attendgiftdatagroup.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unrecovered helpers (the tinyxml wrappers the other table units share) ----

class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* pDoc, const char* pszPath, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
void* FUN_140166440();
void FUN_140177a80(void* log, int level, int category, const wchar_t* format, const unsigned int& arg);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);        // Table/<file>
void FUN_14028faa0(Unk_140165cf0* pParent, const char* pszName, const char* pszAttr, std::vector<Unk_140165cf0*>& out);

// @0x1401adea0
AttendGiftDataGroup::AttendGiftDataGroup()
{
}

// @0x1401adef0
bool AttendGiftDataGroup::Load(Unk_140165cf0* pNode, const CString& strContext)
{
    for (Unk_140165cf0* pElem = pNode->FUN_140165cf0("v"); pElem != 0; pElem = pElem->FUN_140168650("v"))
    {
        Unk_AttendPtr<ItemGift> spGift(new ItemGift());
        spGift->vfunc_2(pElem);
        m_gifts.push_back(spGift);
    }
    return true;
}

// @0x1401adff0
AttendGiftData::AttendGiftData()
    : m_nGiftId(0)
{
}

// @0x1401ae040
bool AttendGiftData::Load(Unk_140165cf0* pNode)
{
    FUN_140873220(pNode, "giftID", m_nGiftId);
    CString strContext;
    strContext.Format("giftID=%u", m_nGiftId);
    for (Unk_140165cf0* pElem = pNode->FUN_140165cf0("group"); pElem != 0; pElem = pElem->FUN_140168650("group"))
    {
        AttendGiftDataGroupPtr spGroup(new AttendGiftDataGroup());
        if (!spGroup->Load(pElem, strContext))
            return false;
        m_groups.push_back(spGroup);
    }
    return true;
}

// @0x1401ae1c0
unsigned AttendGiftData::GetId()
{
    return m_nGiftId;
}

// @0x1401ae1e0
unsigned AttendGiftData::GetGroupCount()
{
    return (unsigned)m_groups.size();
}

// @0x1401ae210
AttendGiftDataGroupPtr AttendGiftData::GetGroup(unsigned nIndex) const
{
    if (nIndex >= (unsigned)m_groups.size())
        return AttendGiftDataGroupPtr(0);
    return m_groups[nIndex];
}

// @0x1401ae2a0
AttendGiftDataTable::AttendGiftDataTable()
{
}

// @0x1401ae2f0
// MS2-FUNCTIONAL: frame has two more pointer temporaries around the make_pair/insert call than the compiled source
bool AttendGiftDataTable::Load()
{
    CString strPath = FUN_14071a5b0("Table", "AttendGiftData.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
        return false;
    std::vector<Unk_140165cf0*> nodes;
    FUN_14028faa0(pRoot, "AttendGiftData", "giftID", nodes);
    for (size_t i = 0; i < nodes.size(); i++)
    {
        AttendGiftDataPtr spData(new AttendGiftData());
        if (!spData->Load(nodes[i]))
        {
            unsigned nId = spData->GetId();
            FUN_140177a80(FUN_140166440(), 1, 0x13, L"AttendGiftDataTable::ReadData FromXel SeasonID={0}", nId);
        }
        else
        {
            unsigned nKey = spData->GetId();
            m_data.insert(std::make_pair(nKey, spData));
        }
    }
    return true;
}

// @0x1401ae630
AttendGiftDataPtr AttendGiftDataTable::Find(unsigned nGiftId)
{
    std::map<unsigned, AttendGiftDataPtr>::iterator it = m_data.find(nGiftId);
    if (it != m_data.end())
        return it->second;
    return AttendGiftDataPtr(0);
}

MS2_EMIT_CRT_MEMMOVE_S();
