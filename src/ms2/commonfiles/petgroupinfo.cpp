// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). PetGroupInfo / CPetCollectTable: Table/petCollectGroup.xml
// and the pet -> collection group indexes.
// MS2-UNIT: ?\petgroupinfo.cpp
// MS2-RANGE: 0x140721000-0x140728140 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\petgroupinfo.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "petgroupinfo.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unrecovered helpers (the tinyxml wrappers the other table units share) ----

class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* pDoc, const char* pszPath, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
void* FUN_140166440();
void FUN_14015eb90(void*, int, int, const wchar_t*, const CString&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);        // Table/<file>
bool FUN_14028f710(Unk_140165cf0* pElem);                   // the node is a usable element

// @0x140721000
PetGroupInfo::PetGroupInfo()
{
    m_nGroupId = 0;
}

// @0x140721040
PetGroupInfo::~PetGroupInfo()
{
}

// @0x140721070
bool PetGroupInfo::Load(Unk_140165cf0* pNode)
{
    if (!FUN_14028f710(pNode))
        return false;
    FUN_1408731e0(pNode, "groupId", m_nGroupId);
    return true;
}

// @0x1407210c0
CPetCollectTable::CPetCollectTable()
{
}

// @0x140721130
CPetCollectTable::~CPetCollectTable()
{
}

// @0x140721190
bool CPetCollectTable::Load()
{
    CString strPath = FUN_14071a5b0("Table", "petCollectGroup.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml \uD615\uC2DD\uC774 \uC798\uBABB \uB418\uC5C8\uC2B5\uB2C8\uB2E4[<ms2> {0}]", strPath);
        return false;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("groupInfo"); pNode != 0; pNode = pNode->FUN_140168650("groupInfo"))
    {
        PetGroupInfoPtr spGroup(new PetGroupInfo());
        if (!spGroup->Load(pNode))
            continue;
        m_groups[spGroup->m_nGroupId] = spGroup;
    }
    return true;
}

// @0x140721410
void CPetCollectTable::Add(unsigned nPetId, int nGroupId)
{
    if (nGroupId == 0)
        return;
    m_petGroups[nPetId] = nGroupId;
    m_groupPets[nGroupId].push_back(nPetId);
}

// @0x140721480
std::map<unsigned, unsigned>& CPetCollectTable::PetGroups()
{
    return m_petGroups;
}

// @0x1407214a0
std::map<int, std::vector<unsigned> >& CPetCollectTable::GroupPets()
{
    return m_groupPets;
}

// @0x1407214c0
PetGroupInfoPtr CPetCollectTable::Find(int nGroupId)
{
    if (m_groups.find(nGroupId) == m_groups.end())
        return PetGroupInfoPtr(0);
    return m_groups[nGroupId];
}

// @0x140728020
MS2_EMIT_CRT_MEMMOVE_S();
