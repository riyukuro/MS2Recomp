// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CGameEventValueManager: the TSingleton holding every game
// event value (commonfiles/gameeventvalue.h) and the shut down event sets (placeholder/cshutdownevent.h). The TU has
// the ctor / dtor and one accessor; the rest is the COMDAT tail its members' implicit dtors instantiate (std::map /
// set / vector and ATL::CAtlMap / CRBMap glue).
// MS2-UNIT: ?\gameeventvaluemanager.cpp
// MS2-RANGE: 0x14046c710-0x1404746a0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??1?$CRBTree@IIV?$CElementTraits@I@ATL@@V12@@ATL@@QEAA@XZ 0x14046dad0 ; unique
// MS2-PIN: ?RemoveAll@?$CRBTree@IIV?$CElementTraits@I@ATL@@V12@@ATL@@QEAAXXZ 0x1404702d0 ; unique
// MS2-PIN: ?RemovePostOrder@?$CRBTree@IIV?$CElementTraits@I@ATL@@V12@@ATL@@AEAAXPEAVCNode@12@@Z 0x1404703d0 ; unique
// MS2-PINS-END tplpin
// The exe keeps a second copy of the EventShopNpc map's _Freeheadnode (0x140462b50 in gameevent.cpp's range, same callees);
// this unit's ~_Tree_comp_alloc (0x14046dd00, called by the paired ~_Tree 0x14046dc10) calls the copy at 0x140472590.
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@KV?$list@V?$MS2Ptr@VEventShopNpcContext@@@@V?$allocator@V?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@U?$less@K@2@V?$allocator@U?$pair@$$CBKV?$list@V?$MS2Ptr@VEventShopNpcContext@@@@V?$allocator@V?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAA@XZ 0x14046dd00
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@KV?$list@V?$MS2Ptr@VEventShopNpcContext@@@@V?$allocator@V?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@U?$less@K@2@V?$allocator@U?$pair@$$CBKV?$list@V?$MS2Ptr@VEventShopNpcContext@@@@V?$allocator@V?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBKV?$list@V?$MS2Ptr@VEventShopNpcContext@@@@V?$allocator@V?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@std@@PEAX@2@@Z 0x140472590
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\gameeventvaluemanager.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <afx.h>
#include <atlcoll.h>
#include "ms2/placeholder/ms2ptr_impl.h"
#define MS2_GAMEEVENTVALUE_TYPES
#include "ms2/placeholder/cgameeventvaluemanager.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// @0x14046c710
CGameEventValueManager::CGameEventValueManager()
{
}

// @0x14046cc20
CGameEventValueManager::~CGameEventValueManager()
{
}

// @0x14046d0d0
CShutdownEventValue* CGameEventValueManager::GetShutdownValue(int nKind)
{
    return m_shutdownGroup.GetValue(nKind);
}
