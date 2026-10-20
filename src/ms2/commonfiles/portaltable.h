// portaltable.h - CPortalTable / PortalRandomTargetData (RTTI names): the field portal tables read from
// Table/stringPortal.xml (display name per fieldID+portalID) and Table/portalRandomTarget.xml (weighted random
// destination per portal). Header name assumed; member and helper names are invented from use.
#pragma once
#include <afx.h>
#include <map>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ms2svrptr.h"
#include "ms2/commonfiles/os.h"

// One weighted destination of a random-target portal (<portalRandomTarget targetFieldID targetPortalID weight>).
// 12 bytes; the exe's vector<> of these has no name.
struct PortalRandomTarget
{
    int nTargetFieldId;                 // +0 "targetFieldID"
    int nTargetPortalId;                // +4 "targetPortalID"
    int nWeight;                        // +8 "weight"
    PortalRandomTarget() : nTargetFieldId(0), nTargetPortalId(0), nWeight(0) {}
};
MS2_CHECK_SIZE(PortalRandomTarget, 0xc);

// RTTI PortalRandomTargetData, 0x40 bytes; vftable 0x142d83cd0 (deleting dtor only).
class PortalRandomTargetData : public CPtred
{
public:
    PortalRandomTargetData();           // 0x140735030
    virtual ~PortalRandomTargetData();  // 0x1407352d0

    int m_nFieldId;                     // +0x18 "fieldID"
    int m_nPortalId;                    // +0x1c "portalID"
    int m_nTotalWeight;                 // +0x20 sum of the targets' weights
    std::vector<PortalRandomTarget> m_targets;   // +0x28
};
MS2_CHECK_SIZE(PortalRandomTargetData, 0x40);
MS2_CHECK_OFFSET(PortalRandomTargetData, m_targets, 0x28);

typedef MS2SvrPtr<PortalRandomTargetData> PortalRandomTargetPtr;

// RTTI CPortalTable, 0x28 bytes; vftable 0x142d83cf0 (+ TSingleton at 0x142d83ce0). Keys are
// (fieldID << 32) | portalID.
class CPortalTable : public TSingleton<CPortalTable>
{
public:
    typedef std::map<unsigned __int64, CStringW> NameMap;
    typedef std::map<unsigned __int64, PortalRandomTargetPtr> TargetMap;

    CPortalTable();                     // 0x140730120
    virtual ~CPortalTable();            // 0x140730180

    bool LoadNames();                   // 0x1407301d0 stringPortal.xml
    bool LoadRandomTargets();           // 0x140730500 portalRandomTarget.xml
    bool Load();                        // 0x140730920 both, stops at the first failure
    bool GetRandomTarget(int nFieldId, int nPortalId, int* pnTargetField, int* pnTargetPortal);   // 0x140730960
    CStringW GetName(int nFieldId, int nPortalId);                                                // 0x140730b80

private:
    MS2_LAYOUT_FRIEND;
    NameMap m_names;                    // +0x08
    TargetMap m_targets;                // +0x18
};
MS2_CHECK_SIZE(CPortalTable, 0x28);
MS2_CHECK_OFFSET(CPortalTable, m_names, 0x08);
MS2_CHECK_OFFSET(CPortalTable, m_targets, 0x18);
