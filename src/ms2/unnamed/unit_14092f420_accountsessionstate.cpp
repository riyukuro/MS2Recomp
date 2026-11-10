// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The client's account/session state zone: the global block at
// 0x143ab2820..0x143ab34c8 (session flags, wallet currencies, item sound names, slot-use requests) and the free functions
// that read and write it. Not an original file: the exe has no __FILE__ for it, names are inferred from use.
// MS2-UNIT: unit_14092f420
// MS2-RANGE: 0x1400be590-0x1400be790 .text$di
// MS2-RANGE: 0x1400bed10-0x1400befb0 .text$di
// MS2-RANGE: 0x14092f420-0x140932b20 .text$mn
// MS2-RANGE: 0x140932b40-0x140935c20 .text$mn
// MS2-RANGE: 0x142c9cc70-0x142c9cd70 .text$yd
// MS2-RANGE: 0x142c9d080-0x142c9d0a0 .text$yd
// MS2-RANGE: 0x142c9d0c0-0x142c9d1c0 .text$yd
// MS2-PIN: ??$forward@U?$pair@H_J@std@@@std@@YA$$QEAU?$pair@H_J@0@AEAU10@@Z 0x140932390 ; hand: callers expect this twin
// MS2-PIN: ??$construct@U?$pair@H_J@std@@U12@@?$_Default_allocator_traits@V?$allocator@U?$pair@H_J@std@@@std@@@std@@SAXAEAV?$allocator@U?$pair@H_J@std@@@1@QEAU?$pair@H_J@1@$$QEAU31@@Z 0x1409321e0 ; hand: callers expect this twin
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@PEAX@2@_K@Z 0x140935140 ; hand: callers expect this twin
// MS2-PIN: ?_Max@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@PEAX@2@PEAU32@@Z 0x140934ac0 ; hand: callers expect this twin
// MS2-PIN: ?_Lrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@PEAX@2@@Z 0x140934900 ; hand: callers expect this twin
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@PEAX@2@@Z 0x140934da0 ; hand: callers expect this twin
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@IVCAdventureLevelMissionData@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@3@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@PEAX@std@@@2@XZ 0x1409347f0 ; hand: callers expect this twin
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@PEAX@std@@@1@PEAU01@@Z 0x140931d80 ; hand: callers expect this twin
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@std@@@1@@Z 0x140932600 ; hand: callers expect this twin
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@PEAX@1@@Z 0x140932280 ; hand: callers expect this twin
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@PEAX@std@@@std@@YAPEAPEAU?$_Tree_node@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@PEAX@0@AEAPEAU10@@Z 0x1409320e0 ; hand: callers expect this twin
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@PEAX@1@AEAPEAU31@@Z 0x140932140 ; hand: callers expect this twin
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@std@@@2@$00@2@XZ 0x140934790 ; hand: callers expect this twin
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@std@@@2@$00@2@XZ 0x1409347a0 ; hand: callers expect this twin
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@IVCAdventureLevelMissionData@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@3@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@std@@@2@XZ 0x1409346e0 ; hand: callers expect this twin
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$_Emplace_back@U?$pair@H_J@std@@@?$_Uninitialized_backout_al@PEAU?$pair@H_J@std@@V?$allocator@U?$pair@H_J@std@@@2@@std@@QEAAX$$QEAU?$pair@H_J@1@@Z 0x140931a10 ; unique
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@std@@@0@AEAV10@@Z 0x140932120 ; unique
// MS2-PIN: ??$forward@AEB_J@std@@YAAEB_JAEB_J@Z 0x140932350 ; prop
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IVCAdventureLevelMissionData@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x140932520 ; prop
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IVCAdventureLevelMissionData@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x140932580 ; prop
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_TailSetVal@@UUnk_TailSetLess@@V?$allocator@UUnk_TailSetVal@@@std@@$0A@@std@@@std@@QEAA@AEBUUnk_TailSetLess@@@Z 0x1409325c0 ; prop
//
// MS2-PIN: ??0?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@std@@@1@@Z 0x140932680 ; unique
// MS2-PIN: ??0?$map@IVCAdventureLevelMissionData@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@3@@std@@QEAA@XZ 0x140932840 ; prop
// MS2-PIN: ??0?$set@UUnk_TailSetVal@@UUnk_TailSetLess@@V?$allocator@UUnk_TailSetVal@@@std@@@std@@QEAA@XZ 0x140932870 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tset_traits@UUnk_TailSetVal@@UUnk_TailSetLess@@V?$allocator@UUnk_TailSetVal@@@std@@$0A@@std@@@std@@QEAA@XZ 0x140932a50 ; prop
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@IVCAdventureLevelMissionData@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@3@$0A@@std@@@std@@QEAA@XZ 0x140932a80 ; prop
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_TailSetVal@@UUnk_TailSetLess@@V?$allocator@UUnk_TailSetVal@@@std@@$0A@@std@@@std@@QEAA@XZ 0x140932ab0 ; prop
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x140932c80 ; unique
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_TailSetVal@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x140932cc0 ; prop
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x140932d00 ; unique
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_TailSetVal@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x140932d40 ; prop
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x140932da0 ; unique
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_TailSetVal@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x140932e10 ; prop
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@IVCAdventureLevelMissionData@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@PEAX@2@XZ 0x1409335f0 ; prop
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_TailSetVal@@UUnk_TailSetLess@@V?$allocator@UUnk_TailSetVal@@@std@@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@UUnk_TailSetVal@@PEAX@2@XZ 0x1409336b0 ; prop
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@IVCAdventureLevelMissionData@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@3@$0A@@std@@@std@@QEAAXXZ 0x140933910 ; prop
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_TailSetVal@@UUnk_TailSetLess@@V?$allocator@UUnk_TailSetVal@@@std@@$0A@@std@@@std@@QEAAXXZ 0x140933940 ; prop
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@std@@@std@@@2@@Z 0x140933af0 ; prop
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@UUnk_TailSetVal@@@std@@@std@@QEAAPEAU?$_Tree_node@UUnk_TailSetVal@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_TailSetVal@@@std@@@std@@@2@@Z 0x1409340a0 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$pair@H_J@std@@@std@@V?$_Vector_val@U?$_Simple_types@U?$pair@H_J@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$pair@H_J@std@@@2@XZ 0x140934770 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$pair@H_J@std@@@std@@V?$_Vector_val@U?$_Simple_types@U?$pair@H_J@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$pair@H_J@std@@@2@XZ 0x140934780 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@UUnk_TailSetLess@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@UUnk_TailSetVal@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@UUnk_TailSetVal@@@std@@@2@$00@std@@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@UUnk_TailSetVal@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@UUnk_TailSetVal@@@std@@@2@$00@2@XZ 0x1409347a0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@UUnk_TailSetVal@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@UUnk_TailSetVal@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@UUnk_TailSetVal@@@std@@@2@XZ 0x1409347c0 ; unique
//
// MS2-PIN: ?_Lrotate@?$_Tree_val@U?$_Tree_simple_types@UUnk_TailSetVal@@@std@@@std@@QEAAXPEAU?$_Tree_node@UUnk_TailSetVal@@PEAX@2@@Z 0x1409349e0 ; prop
//
// MS2-PIN: ?_Max@?$_Tree_val@U?$_Tree_simple_types@UUnk_TailSetVal@@@std@@@std@@SAPEAU?$_Tree_node@UUnk_TailSetVal@@PEAX@2@PEAU32@@Z 0x140934af0 ; prop
// MS2-PIN: ?_Min@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@PEAX@2@PEAU32@@Z 0x140934b20 ; prop
// MS2-PIN: ?_Min@?$_Tree_val@U?$_Tree_simple_types@UUnk_TailSetVal@@@std@@@std@@SAPEAU?$_Tree_node@UUnk_TailSetVal@@PEAX@2@PEAU32@@Z 0x140934b50 ; prop
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@UUnk_TailSetVal@@@std@@@std@@QEAAXPEAU?$_Tree_node@UUnk_TailSetVal@@PEAX@2@@Z 0x140934e80 ; prop
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@UUnk_TailSetVal@@UUnk_TailSetLess@@V?$allocator@UUnk_TailSetVal@@@std@@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_TailSetVal@@@std@@@std@@@2@V32@@Z 0x140935980 ; la1: called from set erase(first,last) 140935890
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@UUnk_TailSetVal@@UUnk_TailSetLess@@V?$allocator@UUnk_TailSetVal@@@std@@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_TailSetVal@@@std@@@std@@@2@V32@0@Z 0x140935890 ; unique
// MS2-PIN: ??__FDAT_143ab3128@@YAXXZ 0x142c9cc90 ; unique
// MS2-PIN: ??__Fg_143ab3150@@YAXXZ 0x142c9cd10 ; unique
// MS2-PIN: ??__FDAT_143ab31a0@@YAXXZ 0x142c9cd30 ; unique
// MS2-PIN: ?Lookup@?$CAtlMap@W4Unk_FameAlliance@@HV?$CElementTraits@W4Unk_FameAlliance@@@ATL@@V?$CElementTraits@H@3@@ATL@@QEBA_NAEBW4Unk_FameAlliance@@AEAH@Z 0x1409332c0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/mypc.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/client/ms2/chatemoticoncli.h"
#include "ms2/placeholder/cmycharacter.h"
#include "ms2/client/ms2/uimainplayerinfo.h"
#include "ms2/client/ms2/uiobject.h"
#include "ms2/commonfiles/usermail.h"
#include "ms2/commonfiles/itemgift.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cguidemanager.h"
#include "ms2/commonfiles/gameeventuservalue.h"
#include "ms2/commonfiles/famegradedata.h"
#include "ms2/commonfiles/titletable.h"
#include "ms2/commonfiles/masteryinteriortable.h"

#include <map>
#include <set>
#include <vector>
#include <utility>
#include "ms2/placeholder/fittingdollpc.h"  // C3: PC::FUN_141654700 / FUN_141658e60

// ---- unit-local stand-ins ---------------------------------------------------------------------------------------------

// C3: the Unk_MailSession / Unk_ObjTable view and Unk_FieldRef are gone (no caller since f64e3e85e):
// the field getter is WorldService::GetFieldData() -> MS2Ptr<CFieldDataCli>, declared on the WorldService view below.



// The local player (MyPC); only the two slots this zone calls are declared (78: level, 141: a cap).
class Unk_MyPc : public MyPC
{
public:
    virtual void vfunc_124(); virtual void vfunc_125(); virtual void vfunc_126(); virtual void vfunc_127();
    virtual void vfunc_128(); virtual void vfunc_129(); virtual void vfunc_130(); virtual void vfunc_131();
    virtual void vfunc_132(); virtual void vfunc_133(); virtual void vfunc_134(); virtual void vfunc_135();
    virtual void vfunc_136(); virtual void vfunc_137(); virtual void vfunc_138(); virtual void vfunc_139();
    virtual void vfunc_140();
    virtual unsigned vfunc_141();
};
class CFieldDataCli;
class WorldService   // C3: member view for the former free stand-ins
{
public:
    static WorldService* GetInstance();
    void* GetLocalPlayer();
    MS2Ptr<CFieldDataCli> GetFieldData();
};

// A learned skill: its record and flags (the skill book hands out MS2Ptr<SkillLevelData>).
class SkillLevelData;
class Unk_SkillRec { public: char m_pad_00[0xa8]; int m_pad_a8; unsigned char m_pad_ac; bool m_bBlocked; };
class Unk_SkillBook
{
public:
    virtual void vfunc_0();
    virtual MS2Ptr<SkillLevelData> vfunc_1(int nSkillId);
    virtual bool vfunc_2(int nSkillId);
};

// The "slot in use" restrictions (0x143ab3330).
class Unk_Restrictions : public CGuideManager { };
// The sound/effect sink (0x143ab3328).
class Unk_SoundSink;
// Three more one-method singletons.
class Unk_Hud { public: virtual void vfunc_0(); virtual void vfunc_1(); };
Unk_Hud* GetUIServerEventDispatcher();
class Unk_BonusBar { };
class GameEventUserValueManager   // C3: member view for the former free stand-ins
{
public:
    void Dispatch(unsigned int, class GameEventVariable*);
};
class Unk_ItemSlotTable { public: int FUN_14087a930(CString strName); };
class Unk_SkillSlots { public: void FUN_14035a870(int nSlot, int nValue); };
class Unk_StatTable { public: };

class CGuideManager;
class CKeyTable { public: void FUN_14142f470(int nPage, int nSlot); };   // C3: member view (ckeytable.h)
class CMasteryInteriorTable;
class CTitleTable;
class GameEventUserValueManager;
class UIServerEventDispatcher;

// ---- data of the zone -------------------------------------------------------------------------------------------------

extern int DAT_1439f4a7c;
extern int DAT_1439f4a80;
extern __int64 DAT_143ab28f0;
extern int g_upperTargetId;
extern int DAT_143ab2878;
extern int DAT_143ab287c;
extern int DAT_143ab2884;
extern int DAT_143ab2888;
extern bool DAT_143ab2857;
extern __int64 DAT_143ab2938;
extern unsigned short DAT_143ab2940;
extern bool DAT_143ab291e;
extern __int64 DAT_143ab2948;
extern bool DAT_143ab2947;
extern bool DAT_143ab2966;
extern int DAT_143ab2914;
extern unsigned short DAT_143ab291c;
extern __int64 DAT_143ab2920;
extern __int64 DAT_143ab2928;
extern __int64 DAT_143ab2978;
extern __int64 DAT_143ab2980;
extern __int64 DAT_143ab2988;
extern unsigned short DAT_143ab2944;
extern unsigned short DAT_143ab2964;
extern unsigned DAT_143ab2970;

// ---- statics of the zone (constructed by the .text$di initializers) ----------------------------------------------------

typedef ATL::CAtlMap<Unk_FameAlliance, int> Unk_FameMap;      // alliance -> fame points (scenestategame)
typedef ATL::CAtlMap<int, int> Unk_IntMapA;
typedef ATL::CAtlMap<unsigned int, int> Unk_MasteryMap;     // mastery id -> value (scenestategame, masterymanager)
typedef ATL::CAtlArray<int> Unk_TemplateIdArray;   // templates whose first use was announced (scenestategame)
typedef std::vector<__int64> Unk_Wallet;

// The block is shared with the exe: the hook DLL binds to the exe's objects instead of constructing its own.
#ifdef MS2_HOOK_DLL
#define MS2_ZONE_GLOBAL(type, name) extern type name
#define MS2_ZONE_GLOBAL_INIT(type, name, args) extern type name
#else
#define MS2_ZONE_GLOBAL(type, name) type name
#define MS2_ZONE_GLOBAL_INIT(type, name, args) type name args
#endif

MS2_ZONE_GLOBAL(Unk_FameMap, DAT_143ab3220);                                                    // @0x1400be590
MS2_ZONE_GLOBAL(Unk_TemplateIdArray, DAT_143ab3128);                                            // @0x1400be5e0
MS2_ZONE_GLOBAL(Unk_Inventory, g_143ab2a90);                                                    // @0x1400be610
MS2_ZONE_GLOBAL(CString, g_143ab2a50);                                                          // @0x1400be640
MS2_ZONE_GLOBAL(CUserMail, g_143ab2ee0);                                                        // @0x1400be670
MS2_ZONE_GLOBAL(Unk_IntMapA, g_143ab3150);                                                      // @0x1400be6a0
MS2_ZONE_GLOBAL(Unk_MasteryMap, DAT_143ab31a0);                                                  // @0x1400be6f0
MS2_ZONE_GLOBAL_INIT(Unk_Wallet, g_143ab2a78, (4, (__int64)0));                                 // @0x1400be740

static CString s_143ab3008("button_click");                                                     // @0x1400bed10
static CString s_143ab2ed8("button_click");                                                     // @0x1400bed40
static CString s_143ab3490[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};   // @0x1400bed70
#include "ms2/placeholder/header_statics_a.h"                                                   // @0x1400bee40..0x1400bef60
#include "ms2/client/ms2/ugcmapitem.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/client/ms2/skilldatatablecli.h"
#include "ms2/commonfiles/dungeonroom.h"
#include "ms2/commonfiles/gameentitycommon.h"
#include "ms2/client/ms2/fielddatacli.h"

// return types of the getters this unit calls
class Unk_EmoNpcTable;

// ---- more unit-local stand-ins ----------------------------------------------------------------------------------------

typedef std::vector<std::pair<int, __int64> > Unk_PayList;           // (currency kind, amount) pairs

class Unk_140166410* FUN_140166410();   // C3: was FUN_140166410
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
void FUN_141275260(int nStringId, int nA, int nB);



int IsNotRecentDayChange(__int64 nTime);
bool IsEarlierDay(CMsTime tmOld, CMsTime tmNew, int nBaseHour);   // C3: was FUN_14086ab70 (commonfiles/timeutil.cpp)
__int64 GetServerTime();

class Unk_NoticeSub { public: virtual void vfunc_0(); virtual unsigned char vfunc_1(); };
class Unk_NoticeSubRef;
class Unk_Notice { public: void* m_pad_00; Unk_NoticeSub m_sub; };

#include "ms2/commonfiles/itemdatatable.h"   // Unk_TrophyKey: DAT_143ab32d8 is a std::set<Unk_TrophyKey> (userproxy.cpp)
// Same layout as the unit-local state of uiadventureleveldialog.cpp (the map global 0x143ab3318 is shared).
#include "ms2/commonfiles/adventureleveltablehelper.h"   // CAdventureLevelMissionData, the mission state of the map global 0x143ab3318
//
//
//
//
//
//

template <class T> int Unk_ArrayFind(const ATL::CAtlArray<T>& rArray, const T& rValue);   // index of the value, -1 if absent (0x140408410)
class Unk_QuickSlots { };
int FUN_14035a870(Unk_QuickSlots* pSlots, int nSlot, unsigned nValue);
Unk_EmoNpcTable* GetFameTable();
CMyCharacter* GetMyCharacter();
void FUN_140935a90(std::vector<std::pair<int, __int64> >* pVec, std::pair<int, __int64>&& value);
Unk_Restrictions* FUN_1409331e0();
Unk_SoundSink* GetKeyTable();
CMasteryInteriorTable* GetMasteryInteriorTable();
Unk_ItemSlotTable* GetTitleTable();
Unk_BonusBar* GetGameEventUserValueManager();
bool FUN_140930d70();
UIMainPlayerInfo* FindMainPlayerInfo(int nUiId);

extern GameEventUserValue DAT_143ab2fc0;
extern GameEventUserValue DAT_143ab3010;
#include "ms2/client/ms2/store.h"     // DAT_143ab2d80, the store table (CStore)
#include "ms2/client/ms2/warehouseitem.h"     // DAT_143ab2e20, the warehouse item table
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/skillsystem.h"
#include "ms2/placeholder/cskillsettable.h"   // CSkillSet
extern Unk_CubeStock DAT_143ab2e50;
template <> void std::_Tree<std::_Tset_traits<Unk_TrophyKey, std::less<Unk_TrophyKey>, std::allocator<Unk_TrophyKey>, false> >::clear() noexcept;   extern std::set<Unk_TrophyKey> DAT_143ab32d8;   // clear 0x140581e40 is another unit's
extern std::map<unsigned int, CAdventureLevelMissionData> DAT_143ab3318;   // 0x143ab3318, the mission progress (userproxy)
extern ATL::CAtlArray<unsigned int> DAT_143ab3268;
extern ATL::CAtlArray<int> DAT_143ab32b8;

class Unk_UiManager { public: };

int PlaySystemSound(const CString& strSound, const CString& strArg);

// ---- functions --------------------------------------------------------------------------------------------------------

// @0x14092f420
void FUN_14092f420()
{
    GetMyCharacter()->ClearDungeonState();
    DAT_143ab2d80.Clear();
    g_143ab2a90.Clear();
    DAT_143ab2fc0.Clear();
    DAT_143ab3010.Clear();
    DAT_143ab2e20.RemoveAll();
    DAT_143ab2e50.Clear();
    DAT_143ab2857 = 0;
    DAT_143ab2938 = 0;
    DAT_143ab32d8.clear();
    DAT_143ab2940 = 0;
    DAT_143ab291e = 0;
    DAT_143ab2948 = 0;
    DAT_143ab2947 = 0;
    DAT_143ab2966 = 0;
    DAT_143ab3318.clear();
}

// @0x14092f4e0
unsigned FUN_14092f4e0(int nSkillId)
{
    if (g_143ab2a90.FUN_140a62d30(nSkillId) != 0)
        return 1;
    Unk_MyPc* pPc = ((class Unk_MyPc*)(WorldService::GetInstance())->GetLocalPlayer());
    if (pPc != 0)
    {
        Unk_SkillBook* pBook = reinterpret_cast<Unk_SkillBook*>(reinterpret_cast<PC*>(pPc)->GetJobSystem());
        if (pBook->vfunc_2(nSkillId))
        {
            MS2Ptr<SkillLevelData> spSkill = reinterpret_cast<Unk_SkillBook*>(reinterpret_cast<PC*>(pPc)->GetJobSystem())->vfunc_1(nSkillId);
            if (spSkill.get() != 0)
            {
                if (reinterpret_cast<Unk_SkillRec*>(spSkill.operator->()->GetSkill())->m_bBlocked)
                    return 0;
                return pPc->FUN_141525480(nSkillId, spSkill.operator->()->HasSequenceName());
            }
            return pPc->FUN_141525480(nSkillId, true);   // C3: MyPC::FUN_141525480 (mypc.h)
        }
    }
    return 0;
}

// @0x14092f640
int GetCurrentChannel()
{
    if (DAT_1439f4a7c == 0)
        return DAT_1439f4a80;
    return DAT_1439f4a7c;
}

// @0x14092f660
bool FUN_14092f660()
{
    return DAT_1439f4a7c == 0;
}

// @0x14092f690
int FUN_14092f690(int nSkillId, int nItemId, __int64 nItemUid, int nSlot, int nKind)
{
    if (FUN_1409331e0()->IsRestricted(10))
    {
        FUN_141275260(0x888, 1, 1);
        return 0;
    }
    if (FUN_1409331e0()->IsRestricted(11) && nKind != 8)
    {
        FUN_141275260(0x888, 1, 1);
        return 0;
    }
    if (FUN_1409331e0()->IsRestricted(12) && nKind != 9)
    {
        FUN_141275260(0x888, 1, 1);
        return 0;
    }
    if (nSkillId != 0)
    {
        MS2Ptr<SkillData> spRow = TSingleton<SkillDataTableCli>::GetInstance()->GetSkillData(nSkillId);
        if (spRow.IsNull())
            return 0;
        if (spRow->FUN_1407e9de0())
        {
            FUN_141275260(0x9a7, 1, 1);
            return 0;
        }
        if (((class CFeatureManager*)FUN_140166410())->IsFeatureEnabled(0xd3))
        {
            Unk_Inventory::ItemPtr spItem = g_143ab2a90.FUN_140a5e2e0(nItemId);
            if (spItem.get() != 0)
            {
                if (((class CItem*)(class CItem*)(spItem))->IsLapenshard() != 0)
                    return 0;
            }
        }
    }
    else
    {
        MS2Ptr<CItemData> spData(0);
        Unk_Inventory::ItemPtr spItem = g_143ab2a90.FindItemByUid(nItemUid);
        if (spItem.get() != 0)
            spData.AssignRaw((CItemData*)spItem->GetData());
        else
            spData = FUN_14053f870(nItemId);
        if (spData == 0)
            return 0;
        if (!((class CItemData*)(class CItemData*)(spData.get()))->FUN_14053e460())
            return 0;
    }
    PlaySystemSound(s_143ab2ed8, "");
    if (!FUN_140930d70())
    {
        COutPacket packet(static_cast<int>(SendOp::KeyTable), 0);
        packet.WriteUInt8(3);
        packet.WriteInt16((short)nSlot);
        packet.WriteInt32(nSkillId);
        packet.WriteInt32(nItemId);
        packet.WriteInt64(nItemUid);
        packet.WriteInt32(nKind);
        FUN_140710590(packet);
    }
    return 1;
}

// @0x14092fac0
int FUN_14092fac0(int nSkillId, int nItemId, __int64 nItemUid, int nSlot)
{
    UIMainPlayerInfo* pInfo = FindMainPlayerInfo(0x4e5f);
    if (pInfo != 0 && pInfo->FUN_1419f29c0() != 0)
    {
        FUN_141275260(0x9a6, 1, 1);
        return 0;
    }
    if (nSkillId != 0)
    {
        MS2Ptr<SkillData> spRow = TSingleton<SkillDataTableCli>::GetInstance()->GetSkillData(nSkillId);
        if (spRow.IsNull())
            return 0;
        if (spRow->FUN_1407e9de0())
        {
            FUN_141275260(0x9a7, 1, 1);
            return 0;
        }
        if (((class CFeatureManager*)FUN_140166410())->IsFeatureEnabled(0xd3))
        {
            Unk_Inventory::ItemPtr spItem = g_143ab2a90.FUN_140a5e2e0(nItemId);
            if (spItem.get() != 0)
            {
                if (((class CItem*)(class CItem*)(spItem))->IsLapenshard() != 0)
                    return 0;
            }
        }
    }
    else
    {
        MS2Ptr<CItemData> spData(0);
        Unk_Inventory::ItemPtr spItem = g_143ab2a90.FindItemByUid(nItemUid);
        if (spItem.get() != 0)
            spData.AssignRaw((CItemData*)spItem->GetData());
        else
            spData = FUN_14053f870(nItemId);
        if (spData == 0)
            return 0;
        if (!((class CItemData*)(class CItemData*)(spData.get()))->FUN_14053e460())
            return 0;
    }
    if (FUN_1409331e0()->IsRestricted(10) != 0 || FUN_1409331e0()->IsRestricted(11) != 0 ||
        FUN_1409331e0()->IsRestricted(12) != 0)
    {
        FUN_141275260(0x888, 1, 1);
        return 0;
    }
    PlaySystemSound(s_143ab2ed8, "");
    if (!FUN_140930d70())
    {
        COutPacket packet(static_cast<int>(SendOp::KeyTable), 0);
        packet.WriteUInt8(4);
        packet.WriteInt16((short)nSlot);
        packet.WriteInt32(nSkillId);
        packet.WriteInt32(nItemId);
        packet.WriteInt64(nItemUid);
        packet.WriteInt32(-1);
        FUN_140710590(packet);
    }
    return 1;
}

// @0x14092fef0
int SendKeyTableMode5(int nSkillId, int nItemId, __int64 nItemUid, int nSlot, int nParam)
{
    if (nSkillId == 0 && nItemUid == 0 && nItemId == 0)
        return 0;
    if (FUN_1409331e0()->IsRestricted(10) != 0)
    {
        FUN_141275260(0x888, 1, 1);
        return 0;
    }
    PlaySystemSound(s_143ab3008, "");
    if (!FUN_140930d70())
    {
        COutPacket packet(static_cast<int>(SendOp::KeyTable), 0);
        packet.WriteUInt8(5);
        packet.WriteInt16((short)nSlot);
        packet.WriteInt32(nSkillId);
        packet.WriteInt64(nItemUid);
        FUN_140710590(packet);
        reinterpret_cast<CKeyTable*>(GetKeyTable())->FUN_14142f470(nSlot, nParam);
    }
    return 1;
}

// @0x140930040
int SendKeyTableMode6()
{
    COutPacket packet(static_cast<int>(SendOp::KeyTable), 0);
    packet.WriteUInt8(6);
    FUN_140710590(packet);
    return 1;
}

// @0x1409300a0
int SendKeyTableMode8(int nSlot)
{
    COutPacket packet(static_cast<int>(SendOp::KeyTable), 0);
    packet.WriteUInt8(8);
    packet.WriteInt16((short)nSlot);
    FUN_140710590(packet);
    return 1;
}

// @0x140930110
bool IsUpperTargetId(int nValue)
{
    return g_upperTargetId == nValue;
}

// @0x140930150
void FUN_140930150(int nValue)
{
    DAT_143ab2914 = nValue;
    GetUIServerEventDispatcher()->vfunc_1();
}

// @0x140930190
int FUN_140930190()
{
    if (IsNotRecentDayChange(DAT_143ab2920))
        return 0;
    return 1;
}

// @0x1409301c0
bool FUN_1409301c0()
{
    if (IsNotRecentDayChange(DAT_143ab2928))
        return false;
    return true;
}

// @0x1409301f0
unsigned FUN_1409301f0()
{
    return 1;
}

// @0x140930200
unsigned char FUN_140930200(int nKind)
{
    int bResult;
    if (nKind != 0 && nKind != 1)
        bResult = 0;
    else
        bResult = 1;
    return bResult;
}

// @0x140930240
__int64 GetMeratBalance()
{
    return DAT_143ab2978;
}

// @0x140930250
__int64 FUN_140930250()
{
    return g_143ab2a78[0] + g_143ab2a78[1];
}

// @0x1409302a0
__int64 FUN_1409302a0()
{
    return g_143ab2a78[2];
}

// @0x1409302d0
__int64 FUN_1409302d0()
{
    return g_143ab2a78[3];
}

// @0x140930300
__int64 GetOwnMerat()
{
    return g_143ab2a78[0] + g_143ab2a78[1] + g_143ab2a78[3];
}

// @0x140930370
__int64 FUN_140930370()
{
    return g_143ab2a78[0];
}

// @0x140930390
__int64 GetWalletAmountByMask(unsigned nMask)
{
    if (nMask == 0)
        return 0;
    if (nMask == 0xffffffff)
        return DAT_143ab2978;
    __int64 nSum = 0;
    if (nMask & 1)
        nSum = nSum + g_143ab2a78[0];
    if (nMask & 2)
        nSum = nSum + g_143ab2a78[1];
    if (nMask & 4)
        nSum = nSum + g_143ab2a78[2];
    if (nMask & 8)
        nSum = nSum + g_143ab2a78[3];
    return nSum;
}

// @0x140930490
__int64 GetMesoMarketTokens()
{
    return DAT_143ab28f0;
}

// @0x1409304a0
void FUN_1409304a0(__int64 nValue)
{
    g_143ab2a78[0] = nValue;
}

// @0x1409304d0
void FUN_1409304d0(__int64 n0, __int64 n1, __int64 n2, __int64 n3)
{
    g_143ab2a78[0] = n0;
    g_143ab2a78[1] = n1;
    g_143ab2a78[2] = n2;
    g_143ab2a78[3] = n3;
    DAT_143ab2978 = n0 + n1 + n2 + n3;
}

// @0x140930580
Unk_Wallet* GetWallet()
{
    return &g_143ab2a78;
}

void AddWalletAmount(Unk_Wallet* pVec, int nKind, __int64 nAmount);

// @0x140930590
bool FUN_140930590(__int64 nAmount, Unk_PayList* pOut)
{
    pOut->clear();
    __int64 nRemain = nAmount;
    if (nRemain > 0)
    {
        const Unk_Wallet* pWallet = &g_143ab2a78;
        int nLast = 3;
        for (int i = nLast; i >= 0; i = i - 1)
        {
            if (FUN_140930200(i) == true)
                continue;
            if ((*pWallet)[i] >= nRemain)
            {
                FUN_140935a90(pOut, {i, nRemain});
                nRemain = 0;
                break;
            }
            __int64 nHave = (*pWallet)[i];
            if (nHave > 0)
            {
                nRemain = nRemain - nHave;
                FUN_140935a90(pOut, {i, nHave});
            }
        }
    }
    __int64 nCash = FUN_140930250();
    if (nRemain > 0 || pOut->empty() == true)
    {
        unsigned nKind = FUN_1409301f0();
        FUN_140935a90(pOut, {nKind, nRemain});
        return nRemain > nCash;
    }
    return false;
}

bool FUN_140930910(__int64 nAmount, unsigned nMask, Unk_Wallet* pVec);

// @0x140930750
bool FUN_140930750(Unk_PayList* pIn, Unk_PayList* pOut)
{
    pOut->clear();
    if (pIn->empty())
        return false;
    Unk_Wallet vecTotals;
    for (int i = 0; i < 4; i = i + 1)
        vecTotals.push_back(-1);
    size_t nCount = pIn->size();
    for (size_t j = 0; j < nCount; j = j + 1)
    {
        std::pair<int, __int64>& rEntry = pIn->at(j);
        unsigned nMask = rEntry.first;
        FUN_140930910(rEntry.second, nMask, &vecTotals);
    }
    if (!vecTotals.empty())
    {
        for (size_t k = 0; k < vecTotals.size(); k = k + 1)
        {
            if (vecTotals[k] == -1)
                continue;
            FUN_140935a90(pOut, {k, vecTotals[k]});
        }
        return true;
    }
    return false;
}

// @0x140930910
bool FUN_140930910(__int64 nAmount, unsigned nMask, Unk_Wallet* pVec)
{
    if (pVec->size() != 4)
        return false;
    __int64 nRemain = nAmount;
    if (nRemain > 0)
    {
        const Unk_Wallet* pWallet = &g_143ab2a78;
        int nLast = 3;
        for (int i = nLast; i >= 0; i = i - 1)
        {
            if (FUN_140930200(i) == true)
                continue;
            unsigned nBits = GetColorMask(i, false);
            if ((nBits & nMask) == 0)
                continue;
            if ((*pWallet)[i] >= nRemain)
            {
                AddWalletAmount(pVec, i, nRemain);
                nRemain = 0;
                break;
            }
            __int64 nHave = (*pWallet)[i];
            if (nHave > 0)
            {
                nRemain = nRemain - nHave;
                AddWalletAmount(pVec, i, nHave);
            }
        }
    }
    if ((nMask & 1) != 0 || (nMask & 2) != 0)
    {
        __int64 nCash = FUN_140930250();
        if (nRemain > 0 || pVec->empty() == true)
        {
            unsigned nKind = FUN_1409301f0();
            AddWalletAmount(pVec, nKind, nRemain);
            return nRemain > nCash;
        }
    }
    return false;
}

// @0x140930ae0
__int64 GetRedMeratBalance()
{
    return DAT_143ab2980;
}

// @0x140930af0
void SetRedMeratBalance(__int64 nValue)
{
    DAT_143ab2980 = nValue;
}

// @0x140930b10
bool FUN_140930b10()
{
    return DAT_143ab2878 != 0;
}

// @0x140930b40
bool FUN_140930b40()
{
    if (DAT_143ab2878 == 2)
        return true;
    if (DAT_143ab287c == 8)
        return true;
    return false;
}

// @0x140930b70
bool FUN_140930b70()
{
    if (DAT_143ab2878 == 2)
        return false;
    if (DAT_143ab287c != 0)
        return false;
    return true;
}

// @0x140930ba0
void FUN_140930ba0(int nMapId)
{
    DAT_143ab2884 = nMapId;
    DAT_143ab2888 = 0;
    DungeonRoomPtr spMap = TSingleton<DungeonRoomTable>::GetInstance()->GetRoom(DAT_143ab2884);
    if (spMap.get() != 0)
        DAT_143ab2888 = spMap->m_groupType;
}

// @0x140930c20
bool FUN_140930c20()
{
    return DAT_143ab2888 == 3;
}

// @0x140930c50
unsigned char FUN_140930c50()
{
    int bResult;
    if (DAT_143ab2857 && DAT_143ab2938 != 0)
        bResult = 1;
    else
        bResult = 0;
    return bResult;
}

// @0x140930c90
unsigned char IsHousingOwner(__int64 nId)
{
    int bResult;
    if (DAT_143ab2857 && DAT_143ab2938 == nId)
        bResult = 1;
    else
        bResult = 0;
    return bResult;
}

// @0x140930ce0
unsigned char FUN_140930ce0()
{
    int bResult;
    if (DAT_143ab291e && DAT_143ab2948 != 0)
        bResult = 1;
    else
        bResult = 0;
    return bResult;
}

// @0x140930d20
unsigned char FUN_140930d20(__int64 nId)
{
    int bResult;
    if (DAT_143ab291e && DAT_143ab2948 == nId)
        bResult = 1;
    else
        bResult = 0;
    return bResult;
}

// @0x140930d70
bool FUN_140930d70()
{
    Unk_MyPc* pPc = ((class Unk_MyPc*)(WorldService::GetInstance())->GetLocalPlayer());
    if (pPc == 0)
        return false;
    bool bResult = reinterpret_cast<CSkillSystem*>(((class MyPC*)(class Unk_MyPc*)(pPc))->GetSkillSystem())->GetSkillSet().get() != 0;
    return bResult;
}

int FUN_140931890(ATL::CAtlArray<int>* pArray, unsigned short* pValue);

// @0x140930e10
int FUN_140930e10()
{
    Unk_MyPc* pPc = ((class Unk_MyPc*)(WorldService::GetInstance())->GetLocalPlayer());
    if (pPc == 0)
        return 0;
    int nCount = 0;
    for (unsigned short nLevel = 1; nLevel <= DAT_143ab291c; nLevel++)
    {
        ATL::CAtlArray<MS2Ptr<ItemEntity> > quests;
        GetMasteryInteriorTable()->GetInteriorItems(nLevel, reinterpret_cast<PC*>(pPc)->GetJobGroupId(), quests);
        if (quests.GetCount() == 0)
            continue;
        if (FUN_140931890(&DAT_143ab32b8, &nLevel) != -1)
            continue;
        nCount = nCount + 1;
    }
    return nCount;
}

// @0x140930f20
void FUN_140930f20()
{
    if (!CMsTime::IsTimeZoneSet())
        return;
    if (DAT_143ab2988 == 0)
        DAT_143ab2988 = GetServerTime();
    __int64 nNow = GetServerTime();
    if (DAT_143ab2988 == nNow)
        return;
    if (IsEarlierDay(CMsTime(DAT_143ab2988), CMsTime(nNow), 0))
        g_143ab3150.RemoveAll();
    DAT_143ab2988 = nNow;
}

// @0x140930fe0
void FUN_140930fe0(CInPacket& packet)
{
    int nKind = (&reinterpret_cast<Unk_Notice*>(&packet)->m_sub)->vfunc_1();
    switch (nKind)
    {
    case 0:
    {
        int nList = (&reinterpret_cast<Unk_Notice*>(&packet)->m_sub)->vfunc_1();
        if (nList == 0)
            DAT_143ab2fc0.Read(packet);
        else if (nList == 1)
            DAT_143ab3010.Read(packet);
        break;
    }
    case 1:
    {
        int nList = (&reinterpret_cast<Unk_Notice*>(&packet)->m_sub)->vfunc_1();
        GameEventUserValue::VariablePtr spTarget;
        if (nList == 0)
            spTarget = DAT_143ab2fc0.ReadVariable(packet);
        else if (nList == 1)
            spTarget = DAT_143ab3010.ReadVariable(packet);
        if (spTarget.get() != 0)
        {
            ((class GameEventUserValueManager*)(class Unk_BonusBar*)(GetGameEventUserValueManager()))->Dispatch(((GameEventVariable*)spTarget.operator->())->GetType(), (class GameEventVariable*)(spTarget.get()));
        }
        break;
    }
    }
}

// @0x140931210
int GetFamePoints(Unk_FameAlliance nAlliance)
{
    int nValue = 0;
    DAT_143ab3220.Lookup(nAlliance, nValue);
    return nValue;
}

// @0x140931250
int FUN_140931250(Unk_FameAlliance nAlliance)
{
    return ((CFameTable*)GetFameTable())->GetGradeByPoint(nAlliance, GetFamePoints(nAlliance));
}

// @0x140931290
int GetGeneralFameGrade()
{
    int nBest = 0;
    for (int i = 1; i < 10; i = i + 1)
    {
        int n = FUN_140931250((Unk_FameAlliance)i);
        if (nBest < n)
            nBest = n;
    }
    return nBest;
}

// @0x1409312f0
bool FUN_1409312f0()
{
    if (DAT_1439f4a7c == 0)
        return false;
    if (FUN_140930b10())
        return false;
    Unk_MyPc* pPc = ((class Unk_MyPc*)(WorldService::GetInstance())->GetLocalPlayer());
    if (pPc == 0)
        return false;
    if (((class PCBase*)(class Unk_MyPc*)(pPc))->IsDead())
        return false;
    MS2Ptr<CFieldDataCli> spField = WorldService::GetInstance()->GetFieldData();
    if (spField.IsNull())
        return false;
    return true;
}

// @0x1409313b0
unsigned FUN_1409313b0()
{
    Unk_MyPc* pPc = ((class Unk_MyPc*)(WorldService::GetInstance())->GetLocalPlayer());
    if (pPc == 0)
        return 0xffffffff;
    unsigned short nLevel = (unsigned short)pPc->vfunc_78();
    unsigned short nCap = (std::max)(DAT_143ab2944, nLevel);
    if (nCap < DAT_143ab2964)
        return 1;
    if (pPc->vfunc_141() < DAT_143ab2970)
        return 2;
    return 0;
}

// @0x140931450
unsigned HasTitle(CString strName)
{
    int nSlot = ((CTitleTable*)GetTitleTable())->FindTitleId(strName);
    if (nSlot == 0)
        return 0;
    return Unk_ArrayFind<int>(reinterpret_cast<const ATL::CAtlArray<int>&>(DAT_143ab3268), nSlot) != -1;
}

// Not in the hook DLL: the DLL's function-local static would be a second, DLL-constructed character state; DLL callers
// (FUN_14092f420 on field entry) bind the exe getter and its object 0x143ab3350 (fx6).
#ifndef MS2_HOOK_DLL
// @0x140931510
CMyCharacter* GetMyCharacter()
{
    static CMyCharacter s_character;
    return &s_character;
}
#endif

// @0x140931590
void AddWalletAmount(Unk_Wallet* pVec, int nKind, __int64 nAmount)
{
    if (nKind < 0 || (int)pVec->size() <= nKind)
        return;
    if ((*pVec)[nKind] >= 0)
    {
        __int64* pSlot = &(*pVec)[nKind];
        *pSlot = *pSlot + nAmount;
    }
    else
        (*pVec)[nKind] = nAmount;
}

// @0x140931890
int FUN_140931890(ATL::CAtlArray<int>* pArray, unsigned short* pValue)
{
    for (int i = 0; i < (int)pArray->GetCount(); i = i + 1)
    {
        if ((*pArray)[i] == *pValue)
            return i;
    }
    return -1;
}

// @0x140931900
UIMainPlayerInfo* FindMainPlayerInfo(int nUiId)
{
    if (reinterpret_cast<Unk_UiManager*>(TSingleton<CUIService>::GetInstance()) != 0)
    {
        MS2Ptr<UIObject> spUi = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)nUiId);
        if (spUi.get() != 0)
            return dynamic_cast<UIMainPlayerInfo*>((UIObject*)spUi);
    }
    return 0;
}

// Template glue of the unit's containers (the exe holds the members its callers use; the full instantiation is a superset
// that tools/tplpin.py pairs against the exe).
template class ATL::CAtlMap<Unk_FameAlliance, int>;
template class ATL::CAtlMap<int, int>;
template class ATL::CAtlArray<unsigned>;

// @0x1409331e0
Unk_Restrictions* FUN_1409331e0()
{
    return reinterpret_cast<Unk_Restrictions*>(TSingleton<CGuideManager>::s_instance);
}

// @0x1409331f0
Unk_SoundSink* GetKeyTable()
{
    return reinterpret_cast<Unk_SoundSink*>(TSingleton<CKeyTable>::s_instance);
}

// @0x140933200
CMasteryInteriorTable* GetMasteryInteriorTable()
{
    return TSingleton<CMasteryInteriorTable>::s_instance;
}

// @0x140933210
Unk_ItemSlotTable* GetTitleTable()
{
    return reinterpret_cast<Unk_ItemSlotTable*>(TSingleton<CTitleTable>::s_instance);
}

// @0x140933220
Unk_BonusBar* GetGameEventUserValueManager()
{
    return reinterpret_cast<Unk_BonusBar*>(TSingleton<GameEventUserValueManager>::s_instance);
}

// @0x140933230
Unk_Hud* GetUIServerEventDispatcher()
{
    return reinterpret_cast<Unk_Hud*>(TSingleton<UIServerEventDispatcher>::s_instance);
}

// ---- hooks (logic free functions; template glue, HasTitle and GetMyCharacter are not hooked)
MS2_REPLACE(0x14092F420, FUN_14092f420, 177, 0xF2E4E897);
MS2_REPLACE(0x14092F4E0, FUN_14092f4e0, 333, 0x577FA26D);
MS2_REPLACE(0x14092F640, GetCurrentChannel, 24, 0xBB440648);
MS2_REPLACE(0x14092F660, FUN_14092f660, 38, 0xCF7D0CEE);
MS2_REPLACE(0x14092F690, FUN_14092f690, 1064, 0xC2F7F480);
MS2_REPLACE(0x14092FAC0, FUN_14092fac0, 1051, 0xDAF9E13C);
MS2_REPLACE(0x14092FEF0, SendKeyTableMode5, 326, 0x3471EE0B);
MS2_REPLACE(0x140930040, SendKeyTableMode6, 81, 0xB09A1348);
MS2_REPLACE(0x1409300A0, SendKeyTableMode8, 103, 0x9DE9981A);
MS2_REPLACE(0x140930110, IsUpperTargetId, 45, 0x35E26EF0);
MS2_REPLACE(0x140930150, FUN_140930150, 49, 0x600B5E60);
MS2_REPLACE(0x140930190, FUN_140930190, 34, 0x990CD6A7);
MS2_REPLACE(0x1409301C0, FUN_1409301c0, 31, 0xD4DDD20D);
MS2_REPLACE(0x1409301F0, FUN_1409301f0, 6, 0xFFA3AE7F);
MS2_REPLACE(0x140930200, FUN_140930200, 47, 0xC7272AB7);
MS2_REPLACE(0x140930240, GetMeratBalance, 8, 0xA2C0D39F);
MS2_REPLACE(0x140930250, FUN_140930250, 59, 0xA9A57F01);
MS2_REPLACE(0x1409302A0, FUN_1409302a0, 29, 0xFD5CE0CE);
MS2_REPLACE(0x1409302D0, FUN_1409302d0, 29, 0xA25DF127);
MS2_REPLACE(0x140930300, GetOwnMerat, 92, 0xF2C19ABD);
MS2_REPLACE(0x140930370, FUN_140930370, 26, 0x38ECCADD);
MS2_REPLACE(0x140930390, GetWalletAmountByMask, 245, 0x5A4DAC0E);
MS2_REPLACE(0x140930490, GetMesoMarketTokens, 8, 0x0D9ADA60);
MS2_REPLACE(0x1409304A0, FUN_1409304a0, 36, 0x7B99688F);
MS2_REPLACE(0x1409304D0, FUN_1409304d0, 159, 0x2452A543);
MS2_REPLACE(0x140930580, GetWallet, 8, 0x5EEA02EA);
MS2_REPLACE(0x140930590, FUN_140930590, 433, 0x21C60B90);
MS2_REPLACE(0x140930750, FUN_140930750, 431, 0x76010D2E);
MS2_REPLACE(0x140930910, FUN_140930910, 448, 0xB742D06B);
MS2_REPLACE(0x140930AE0, GetRedMeratBalance, 8, 0x1D651B06);
MS2_REPLACE(0x140930AF0, SetRedMeratBalance, 18, 0x526F478A);
MS2_REPLACE(0x140930B10, FUN_140930b10, 38, 0xDE946B1E);
MS2_REPLACE(0x140930B40, FUN_140930b40, 29, 0x4BC52E14);
MS2_REPLACE(0x140930B70, FUN_140930b70, 29, 0x392C3F35);
MS2_REPLACE(0x140930BA0, FUN_140930ba0, 112, 0x6CE930F5);
MS2_REPLACE(0x140930C20, FUN_140930c20, 38, 0x4B6E77CD);
MS2_REPLACE(0x140930C50, FUN_140930c50, 50, 0xD820A189);
MS2_REPLACE(0x140930C90, IsHousingOwner, 59, 0x8307E93A);
MS2_REPLACE(0x140930CE0, FUN_140930ce0, 50, 0x04A46EC7);
MS2_REPLACE(0x140930D20, FUN_140930d20, 59, 0xB6070E05);
MS2_REPLACE(0x140930D70, FUN_140930d70, 143, 0x5DDD397F);
MS2_REPLACE(0x140930E10, FUN_140930e10, 262, 0xB6A2B024);
MS2_REPLACE(0x140930F20, FUN_140930f20, 181, 0xAB6D1980);
MS2_REPLACE(0x140930FE0, FUN_140930fe0, 530, 0x22983945);
MS2_REPLACE(0x140931210, GetFamePoints, 47, 0x5984E440);
MS2_REPLACE(0x140931250, FUN_140931250, 50, 0x6490BC3C);
MS2_REPLACE(0x140931290, GetGeneralFameGrade, 81, 0x20EF52D0);
MS2_REPLACE(0x1409312F0, FUN_1409312f0, 176, 0xB25D8E28);
MS2_REPLACE(0x1409313B0, FUN_1409313b0, 150, 0x698D7CE5);
MS2_REPLACE(0x140931590, AddWalletAmount, 144, 0x50E78C9C);
MS2_REPLACE(0x140931890, FUN_140931890, 98, 0x6C37EF7D);
MS2_REPLACE(0x140931900, FindMainPlayerInfo, 147, 0xE7C00ADE);
MS2_REPLACE(0x1409331E0, FUN_1409331e0, 8, 0xC54D3565);
MS2_REPLACE(0x1409331F0, GetKeyTable, 8, 0x8D62E8AD);
MS2_REPLACE(0x140933200, GetMasteryInteriorTable, 8, 0xDA9BFB2D);
MS2_REPLACE(0x140933210, GetTitleTable, 8, 0x6C3796B0);
MS2_REPLACE(0x140933220, GetGameEventUserValueManager, 8, 0xE24B178D);
MS2_REPLACE(0x140933230, GetUIServerEventDispatcher, 8, 0x9B7C0E25);

// ---- template tail the recovered source does not instantiate ----------------------------------------------------------
// The exe keeps these COMDAT members of the zone's containers (an ATL red-black map in two flavours, std::set<unsigned>, the
// ALMission tree and std::vector<pair<int,__int64>>). The recovered source cannot reproduce their instantiations, so each is
// written here as a plain unit-local function with the same behaviour, tagged with its exe VA.

extern "C" void (__cdecl* __imp_free)(void*);

struct Unk_TailAlc { };                                     // empty std::allocator stand-in
struct Unk_TailProxy { void* m_pCont; void* m_pIter; };    // _Container_proxy
struct Unk_TailZeroTag;
struct Unk_TailVecBase : Unk_TailAlc { Unk_TailProxy m_val; Unk_TailVecBase(Unk_TailZeroTag); };
// _Compressed_pair<less, _Compressed_pair<allocator, _Tree_val>>
struct Unk_TailOuterPair : std::less<unsigned> { Unk_TailVecBase m_inner; Unk_TailOuterPair(bool, const std::less<unsigned>& cmp, Unk_TailZeroTag& tag); };
struct Unk_TailIter { void* m_pNode; };                     // _Tree_const_iterator (checked iterators off the register path)
struct Unk_TailRefBox { void* m_p; };
struct Unk_TailSetVal { void* m_unk_00; Unk_TailRefBox m_ref; char m_pad_10[0x8]; };                // element of the set tree (0x18)
struct Unk_TailAlmVal { void* m_unk_00; Unk_TailRefBox m_ref; char m_pad_10[0x20]; };                // element of the mission tree (0x30)
struct Unk_TailSetNode { Unk_TailSetNode* m_pLeft; Unk_TailSetNode* m_pParent; Unk_TailSetNode* m_pRight; char m_nColor; char m_bNil; Unk_TailSetVal m_val; };
// (the mapped type of the mission tree is CAdventureLevelMissionData, 0x28)
struct Unk_TailAlmTree { char m_pad_00[0x10]; };
struct Unk_TailAlmNode { Unk_TailAlmNode* m_pLeft; Unk_TailAlmNode* m_pParent; Unk_TailAlmNode* m_pRight; char m_nColor; char m_bNil; Unk_TailAlmVal m_val; };
struct Unk_TailSetLess { bool operator()(const Unk_TailSetVal&, const Unk_TailSetVal&) const { return false; } };
typedef std::set<Unk_TailSetVal, Unk_TailSetLess> Unk_TailSet; typedef std::_Tree<std::_Tset_traits<Unk_TailSetVal, Unk_TailSetLess, std::allocator<Unk_TailSetVal>, false>> Unk_TailSTree; typedef std::_Tree_val<std::_Tree_simple_types<Unk_TailSetVal>> Unk_TailTVal; typedef std::_Tree_node<Unk_TailSetVal, void*> Unk_TailTNode; typedef std::_Tree_const_iterator<Unk_TailTVal> Unk_TailCIt; typedef std::_Tree_unchecked_const_iterator<Unk_TailTVal, std::_Iterator_base0> Unk_TailUIt;
typedef std::pair<int, __int64> Unk_TailPair;
struct Unk_TailZeroTag { };

// Red-black tree bookkeeping of the exe's map (ATL CRBTree layout), nodes of two sizes.
struct Unk_TailBoxPtr { void* m_unk_00; void* m_p; };
struct Unk_TailNodeA                                        // 0x48
{
    char m_pad_00[0x18]; Unk_TailBoxPtr m_box; char m_pad_28[0x8]; Unk_TailNodeA* m_pLeft; Unk_TailNodeA* m_pRight; char m_pad_40[0x8];
};
struct Unk_TailNodeB                                        // 0x30
{
    char m_pad_00[0x18]; Unk_TailNodeB* m_pLeft; Unk_TailNodeB* m_pRight; char m_pad_28[0x8];
};
template <class N> struct Unk_TailTree
{
    N* m_pRoot; __int64 m_nCount; N* m_pFree; void* m_pBlocks; size_t m_nBlockSize; N* m_pNil;
};
typedef Unk_TailTree<Unk_TailNodeA> Unk_TailTreeA;
typedef Unk_TailTree<Unk_TailNodeB> Unk_TailTreeB;

Unk_TailAlc* FUN_140932820(Unk_TailAlc* pAlc);
Unk_TailProxy* FUN_140932780(Unk_TailProxy* pProxy);
// (0x140162f10 is std::forward<std::_Zero_then_variadic_args_t>)
// (0x1403564a0 is std::_Vector_val<std::_Simple_types<__int64>>::_Vector_val())
Unk_TailSetNode*& FUN_140932360(Unk_TailSetNode*& pNode);
Unk_TailPair* FUN_1409323b0(Unk_TailPair* pPair);
Unk_TailAlmVal* FUN_140932fa0(Unk_TailAlmVal* pVal, unsigned nFlags);
Unk_TailSetVal* FUN_140932fe0(Unk_TailSetVal* pVal, unsigned nFlags);
void FUN_140932b80(Unk_TailSetVal* pVal);
// (0x14063e780 is the implicit std::map<int, long>::~map)
// (was FUN_140195700: now ~CAdventureLevelMissionData)
void FUN_140932b60(Unk_TailAlmVal* pVal);
// (was FUN_140932640: now the real set member)
// 0x140932a20 = std::_Tree<map<unsigned, CAdventureLevelMissionData>>::~_Tree
// (was FUN_140932a50: now the real set member)
// (was FUN_140932f10: now the real set member)
void FUN_140932ba0(Unk_TailNodeA* pNode);
void FUN_140932bc0(Unk_TailNodeB* pNode);
void FUN_140932be0(Unk_TailNodeA* pNode);
void FUN_140932c00(Unk_TailNodeB* pNode);
Unk_TailNodeA* FUN_140933020(Unk_TailNodeA* pNode, unsigned nFlags);
Unk_TailNodeB* FUN_140933060(Unk_TailNodeB* pNode, unsigned nFlags);
void FUN_140932970(Unk_TailTreeA* pTree);
void FUN_1409329b0(Unk_TailTreeB* pTree);
void FUN_1409329f0(Unk_TailBoxPtr* pBox) noexcept;
void FUN_140933320(Unk_TailTreeA* pTree);
void FUN_1409333a0(Unk_TailTreeB* pTree);
bool IsNilNode(Unk_TailTreeA* pTree, Unk_TailNodeA* pNode);
bool FUN_140933280(Unk_TailTreeB* pTree, Unk_TailNodeB* pNode);
void FUN_140933420(Unk_TailTreeA* pTree, Unk_TailNodeA* pNode);
void FUN_140933480(Unk_TailTreeB* pTree, Unk_TailNodeB* pNode);
void FUN_1409330a0(Unk_TailTreeA* pTree, Unk_TailNodeA* pNode);
void FUN_140933140(Unk_TailTreeB* pTree, Unk_TailNodeB* pNode);
void FUN_140934c70(Unk_TailBoxPtr* pBox);
void FUN_140934cd0(Unk_TailBoxPtr* pBox, void* pTag);
void FUN_1409334e0(CPtred* p);
struct Unk_TailTreeVal { void* m_pHead; size_t m_nSize; };
struct Unk_TailVecVal { Unk_TailPair* m_pFirst; Unk_TailPair* m_pLast; Unk_TailPair* m_pEnd; };
Unk_TailVecVal* FUN_1409347d0(Unk_TailVecVal* pVal);
Unk_TailTreeA* FUN_140932460(Unk_TailTreeA* pTree, size_t nBlock);
Unk_TailTreeB* FUN_1409324c0(Unk_TailTreeB* pTree, size_t nBlock);
// (was FUN_140931e10: now the real set member)
Unk_TailSetVal* FUN_140932110(Unk_TailSetVal* pVal);
void FUN_1409322c0(Unk_TailAlc* pAlc, Unk_TailSetVal* pVal);
void FUN_140933a50(Unk_TailSet* pTree, Unk_TailSetNode* pNode);
void FUN_1409339b0(Unk_TailAlmTree* pTree, Unk_TailAlmNode* pNode);
// 0x140931d80 = _Tree_node<pair<const unsigned, CAdventureLevelMissionData>>::_Freenode0
void FUN_1409322a0(Unk_TailAlc* pAlc, Unk_TailAlmVal* pVal);
Unk_TailIter* GetEnd(Unk_TailSet* pTree, Unk_TailIter* pRet) noexcept;
// (was FUN_140935280: now the real _Tree member)
// (was FUN_140935890: now the real _Tree member)
// (was FUN_140932130: now the real set member)
// (was FUN_1409340a0: now the real set member)
// (0x140934be0 is _Vector_alloc<..pair<int, __int64>..>::_Myfirst() const)
void FUN_140935120();
void* FUN_1409347e0(void* pThis);

// @0x140931620
Unk_TailVecBase::Unk_TailVecBase(Unk_TailZeroTag)
{
    FUN_140932820(this);
    FUN_140932780(&m_val);
}

// @0x140931680
Unk_TailPair* FUN_140931680(Unk_TailPair* pThis, int& nKey, __int64& nValue)
{
    pThis->first = std::forward<int&>(nKey);
    pThis->second = std::forward<__int64&>(nValue);
    return pThis;
}

// @0x140931720
Unk_TailOuterPair::Unk_TailOuterPair(bool, const std::less<unsigned>& cmp, Unk_TailZeroTag& tag)
    : std::less<unsigned>(std::forward<const std::less<unsigned>&>(cmp)), m_inner(reinterpret_cast<Unk_TailZeroTag&>(std::forward<std::_Zero_then_variadic_args_t>(reinterpret_cast<std::_Zero_then_variadic_args_t&>(tag))))
{
}

// @0x1409317c0
Unk_TailVecBase* FUN_1409317c0(Unk_TailVecBase* pThis, bool, const Unk_TailAlc& alc)
{
    std::forward<const std::allocator<__int64>&>(reinterpret_cast<const std::allocator<__int64>&>(alc));   // 0x1409323a0 (ICF)
    reinterpret_cast<std::_Vector_val<std::_Simple_types<__int64>>*>(&pThis->m_val)->std::_Vector_val<std::_Simple_types<__int64>>::_Vector_val();
    return pThis;
}

// @0x140931840
Unk_TailPair* FUN_140931840(Unk_TailPair* pThis, int& nKey, __int64& nValue)
{
    pThis->first = std::forward<int>(nKey);
    pThis->second = std::forward<__int64&>(nValue);
    return pThis;
}

// @0x1409319a0
void FUN_1409319a0(void*, void*, void*, bool)
{
}

// @0x140932100
Unk_TailAlmVal* FUN_140932100(Unk_TailAlmVal* pVal)
{
    return pVal;
}

// @0x140932110
Unk_TailSetVal* FUN_140932110(Unk_TailSetVal* pVal)
{
    return pVal;
}

// @0x140932190
void FUN_140932190(Unk_TailAlc*, Unk_TailSetNode** pDst, Unk_TailSetNode** pSrc)
{
    ::new ((void*)pDst) Unk_TailSetNode*(FUN_140932360(*pSrc));
}

// @0x140932230
void FUN_140932230(Unk_TailAlc*, Unk_TailPair* pDst, Unk_TailPair* pSrc)
{
    ::new ((void*)pDst) Unk_TailPair(*FUN_1409323b0(pSrc));
}

// @0x140932290
void FUN_140932290(void*, void*)
{
}

// @0x1409322a0
void FUN_1409322a0(Unk_TailAlc*, Unk_TailAlmVal* pVal)
{
    FUN_140932fa0(pVal, 0);
}

// @0x1409322c0
void FUN_1409322c0(Unk_TailAlc*, Unk_TailSetVal* pVal)
{
    FUN_140932fe0(pVal, 0);
}

// @0x1409323b0
Unk_TailPair* FUN_1409323b0(Unk_TailPair* pPair)
{
    return pPair;
}

// @0x140932400
Unk_TailTreeA* FUN_140932400(Unk_TailTreeA* pThis, size_t nBlock)
{
    FUN_140932460(pThis, nBlock);
    return pThis;
}

// @0x140932430
Unk_TailTreeB* FUN_140932430(Unk_TailTreeB* pThis, size_t nBlock)
{
    FUN_1409324c0(pThis, nBlock);
    return pThis;
}

// @0x140932460
Unk_TailTreeA* FUN_140932460(Unk_TailTreeA* pThis, size_t nBlock)
{
    pThis->m_pRoot = 0;
    pThis->m_nCount = 0;
    pThis->m_pFree = 0;
    pThis->m_pBlocks = 0;
    pThis->m_nBlockSize = nBlock;
    pThis->m_pNil = 0;
    return pThis;
}

// @0x1409324c0
Unk_TailTreeB* FUN_1409324c0(Unk_TailTreeB* pThis, size_t nBlock)
{
    pThis->m_pRoot = 0;
    pThis->m_nCount = 0;
    pThis->m_pFree = 0;
    pThis->m_pBlocks = 0;
    pThis->m_nBlockSize = nBlock;
    pThis->m_pNil = 0;
    return pThis;
}

// @0x1409326c0
Unk_TailIter* FUN_1409326c0(Unk_TailIter* pThis, void* pNode, const void* pCont)
{
    reinterpret_cast<Unk_TailCIt*>(pThis)->Unk_TailCIt::_Tree_const_iterator((Unk_TailTNode*)pNode, (const Unk_TailTVal*)pCont);
    return pThis;
}

// @0x140932740
Unk_TailIter* FUN_140932740(Unk_TailIter* pThis, void* pNode, void* pCont)
{
    pThis->m_pNode = pNode;
    ((std::_Iterator_base0*)(void*)(pThis))->_Adopt((void const*)(pCont));
    return pThis;
}

// @0x140932780
Unk_TailProxy* FUN_140932780(Unk_TailProxy* pThis)
{
    pThis->m_pCont = 0;
    pThis->m_pIter = 0;
    return pThis;
}

// @0x140932820
Unk_TailAlc* FUN_140932820(Unk_TailAlc* pThis)
{
    return pThis;
}

// @0x140932930
void DestroyTree(Unk_TailTreeA* pThis)
{
    FUN_140932970(pThis);
}

// @0x140932950
void FUN_140932950(Unk_TailTreeB* pThis)
{
    FUN_1409329b0(pThis);
}

// @0x140932970
void FUN_140932970(Unk_TailTreeA* pThis)
{
    FUN_140933320(pThis);
    if (pThis->m_pNil != 0)
        __imp_free(pThis->m_pNil);
}

// @0x1409329b0
void FUN_1409329b0(Unk_TailTreeB* pThis)
{
    FUN_1409333a0(pThis);
    if (pThis->m_pNil != 0)
        __imp_free(pThis->m_pNil);
}

// @0x1409329f0
void FUN_1409329f0(Unk_TailBoxPtr* pThis) noexcept
{
    FUN_140934c70(pThis);
}

// 0x140932b20 is the implicit dtor of std::map<unsigned, CAdventureLevelMissionData> (DAT_143ab3318, pinned in userproxy)
//
//
//
//

// @0x140932b40
void DestroySet(Unk_TailSet* pThis)
{
    reinterpret_cast<Unk_TailSTree*>(pThis)->Unk_TailSTree::~_Tree();
}

// @0x140932ba0
void FUN_140932ba0(Unk_TailNodeA* pThis)
{
    FUN_140932be0(pThis);
}

// @0x140932bc0
void FUN_140932bc0(Unk_TailNodeB* pThis)
{
    FUN_140932c00(pThis);
}

// @0x140932be0
void FUN_140932be0(Unk_TailNodeA* pThis)
{
    FUN_1409329f0(&pThis->m_box);
}

// @0x140932c00
void FUN_140932c00(Unk_TailNodeB*)
{
}

// @0x140932e60
Unk_TailIter* FUN_140932e60(Unk_TailIter* pThis)
{
    ++*reinterpret_cast<Unk_TailUIt*>(pThis);
    return pThis;
}

// @0x140933020
Unk_TailNodeA* FUN_140933020(Unk_TailNodeA* pThis, unsigned nFlags)
{
    FUN_140932ba0(pThis);
    if (nFlags & 1)
        ::operator delete(pThis, sizeof(Unk_TailNodeA));
    return pThis;
}

// @0x140933060
Unk_TailNodeB* FUN_140933060(Unk_TailNodeB* pThis, unsigned nFlags)
{
    FUN_140932bc0(pThis);
    if (nFlags & 1)
        ::operator delete(pThis, sizeof(Unk_TailNodeB));
    return pThis;
}

// @0x1409330a0
void FUN_1409330a0(Unk_TailTreeA* pThis, Unk_TailNodeA* pNode)
{
    ATLENSURE(pNode != NULL);
    FUN_140933020(pNode, 0);
    pNode->m_pLeft = pThis->m_pFree;
    pThis->m_pFree = pNode;
    ATLASSUME(pThis->m_nCount > 0);
    pThis->m_nCount--;
}

// @0x140933140
void FUN_140933140(Unk_TailTreeB* pThis, Unk_TailNodeB* pNode)
{
    ATLENSURE(pNode != NULL);
    FUN_140933060(pNode, 0);
    pNode->m_pLeft = pThis->m_pFree;
    pThis->m_pFree = pNode;
    ATLASSUME(pThis->m_nCount > 0);
    pThis->m_nCount--;
}

// @0x140933240
bool IsNilNode(Unk_TailTreeA* pThis, Unk_TailNodeA* pNode)
{
    return pNode == pThis->m_pNil;
}

// @0x140933280
bool FUN_140933280(Unk_TailTreeB* pThis, Unk_TailNodeB* pNode)
{
    return pNode == pThis->m_pNil;
}

// @0x140933320
void FUN_140933320(Unk_TailTreeA* pThis)
{
    if (!IsNilNode(pThis, pThis->m_pRoot))
        FUN_140933420(pThis, pThis->m_pRoot);
    pThis->m_nCount = 0;
    ((ATL::CAtlPlex*)(void*)(pThis->m_pBlocks))->FreeDataChain();
    pThis->m_pBlocks = 0;
    pThis->m_pFree = 0;
    pThis->m_pRoot = pThis->m_pNil;
}

// @0x1409333a0
void FUN_1409333a0(Unk_TailTreeB* pThis)
{
    if (!FUN_140933280(pThis, pThis->m_pRoot))
        FUN_140933480(pThis, pThis->m_pRoot);
    pThis->m_nCount = 0;
    ((ATL::CAtlPlex*)(void*)(pThis->m_pBlocks))->FreeDataChain();
    pThis->m_pBlocks = 0;
    pThis->m_pFree = 0;
    pThis->m_pRoot = pThis->m_pNil;
}

// @0x140933420
void FUN_140933420(Unk_TailTreeA* pThis, Unk_TailNodeA* pNode)
{
    if (IsNilNode(pThis, pNode))
        return;
    FUN_140933420(pThis, pNode->m_pLeft);
    FUN_140933420(pThis, pNode->m_pRight);
    FUN_1409330a0(pThis, pNode);
}

// @0x140933480
void FUN_140933480(Unk_TailTreeB* pThis, Unk_TailNodeB* pNode)
{
    if (FUN_140933280(pThis, pNode))
        return;
    FUN_140933480(pThis, pNode->m_pLeft);
    FUN_140933480(pThis, pNode->m_pRight);
    FUN_140933140(pThis, pNode);
}

// @0x1409339b0
void FUN_1409339b0(Unk_TailAlmTree* pThis, Unk_TailAlmNode* pRoot)
{
    for (Unk_TailAlmNode* pNode = pRoot; !pNode->m_bNil; pRoot = pNode)
    {
        FUN_1409339b0(pThis, pNode->m_pRight);
        pNode = pNode->m_pLeft;
        Unk_TailAlc* pAlc = ((struct Unk_TailAlc*)&((std::_Tree_comp_alloc<std::_Tmap_traits<unsigned int, CAdventureLevelMissionData, std::less<unsigned int>, std::allocator<std::pair<unsigned int const, CAdventureLevelMissionData>>, 0>>*)(struct Unk_TailAlmTree*)(pThis))->_Getal());
        FUN_1409322a0(pAlc, FUN_140932100(&pRoot->m_val));
        std::_Tree_node<std::pair<const unsigned int, CAdventureLevelMissionData>, void*>::_Freenode0(*reinterpret_cast<std::allocator<std::_Tree_node<std::pair<const unsigned int, CAdventureLevelMissionData>, void*>>*>(pAlc), reinterpret_cast<std::_Tree_node<std::pair<const unsigned int, CAdventureLevelMissionData>, void*>*>(pRoot));
    }
}

// @0x140933a50
void FUN_140933a50(Unk_TailSet* pThis, Unk_TailSetNode* pRoot)
{
    for (Unk_TailSetNode* pNode = pRoot; !pNode->m_bNil; pRoot = pNode)
    {
        FUN_140933a50(pThis, pNode->m_pRight);
        pNode = pNode->m_pLeft;
        Unk_TailAlc* pAlc = ((struct Unk_TailAlc*)&((std::_Tree_comp_alloc<std::_Tset_traits<Unk_TailSetVal, Unk_TailSetLess, std::allocator<Unk_TailSetVal>, 0>>*)(void*)(pThis))->_Getal());
        FUN_1409322c0(pAlc, FUN_140932110(&pRoot->m_val));
        Unk_TailTNode::_Freenode0(*reinterpret_cast<std::allocator<Unk_TailTNode>*>(pAlc), reinterpret_cast<Unk_TailTNode*>(pRoot));
    }
}

// @0x140934680
void FUN_140934680(Unk_TailSet* pThis, Unk_TailSetNode* pNode)
{
    Unk_TailTNode::_Freenode0(*reinterpret_cast<std::allocator<Unk_TailTNode>*>(&((std::_Tree_comp_alloc<std::_Tset_traits<Unk_TailSetVal, Unk_TailSetLess, std::allocator<Unk_TailSetVal>, 0>>*)(void*)(pThis))->_Getal()), reinterpret_cast<Unk_TailTNode*>(pNode));
}

// @0x140934730
void* FUN_140934730(std::vector<Unk_TailPair>* pThis)
{
    return FUN_1409347e0(&reinterpret_cast<Unk_TailRefBox*>(pThis)->m_p);
}

// @0x1409347e0
void* FUN_1409347e0(void* pThis)
{
    return pThis;
}

// @0x140934c70
void FUN_140934c70(Unk_TailBoxPtr* pThis)
{
    if (pThis->m_p != 0)
    {
        FUN_140934cd0(pThis, 0);
        pThis->m_p = 0;
    }
}

// @0x140934cd0
void FUN_140934cd0(Unk_TailBoxPtr* pThis, void*)
{
    if (CPtred::ReleasePtred((CPtred*)pThis->m_p) == 0)
    {
        FUN_1409334e0((CPtred*)pThis->m_p);
        CPtred::DeletePtred((CPtred*)pThis->m_p);
    }
}

// @0x140934fc0
void FUN_140934fc0(Unk_TailSet* pThis)
{
    Unk_TailIter itEnd;
    Unk_TailIter itLast = *GetEnd(pThis, &itEnd);
    Unk_TailIter itFirst = reinterpret_cast<const Unk_TailIter&>(static_cast<const Unk_TailCIt&>(reinterpret_cast<Unk_TailSTree*>(pThis)->begin()));
    reinterpret_cast<Unk_TailSTree*>(pThis)->erase(reinterpret_cast<Unk_TailCIt&>(itFirst), reinterpret_cast<Unk_TailCIt&>(itLast));   // erase(begin(), end())
}

// @0x140935120
void FUN_140935120()
{
    std::_Xout_of_range("invalid vector<T> subscript");
}

// @0x140935140
void* FUN_140935140(Unk_TailAlc*, size_t n)
{
    return std::_Allocate<16>(std::_Get_size_of_n<0x50>(n));
}

// @0x140935170
void* FUN_140935170(Unk_TailAlc*, size_t n)
{
    return std::_Allocate<16>(std::_Get_size_of_n<0x38>(n));
}

// @0x1409351d0
Unk_TailPair* FUN_1409351d0(std::vector<Unk_TailPair>* pThis, size_t n)
{
    if (!(((std::vector<std::pair<int, __int64>, std::allocator<std::pair<int, __int64>>>*)(void*)(pThis))->size() > n))
        FUN_140935120();
    return ((const std::vector<Unk_TailPair>*)pThis)->_Myfirst() + n;
}

// @0x1409354f0
void FUN_1409354f0(Unk_TailAlc*, void* p, size_t n)
{
    std::_Deallocate<16>(p, n * 0x50);
}

// @0x140935520
void FUN_140935520(Unk_TailAlc*, void* p, size_t n)
{
    std::_Deallocate<16>(p, n * 0x38);
}

// @0x140935550
void FUN_140935550(Unk_TailAlc*, void* p, size_t n)
{
    std::_Deallocate<16>(p, n * 0x50);
}

// @0x140935580
void FUN_140935580(Unk_TailAlc*, void* p, size_t n)
{
    std::_Deallocate<16>(p, n * 0x38);
}

// @0x1409355e0
bool FUN_1409355e0(std::vector<Unk_TailPair>* pThis)
{
    return static_cast<const std::vector<Unk_TailPair>*>(pThis)->_Myfirst() == static_cast<const std::vector<Unk_TailPair>*>(pThis)->_Mylast();     // 0x140934be0, 0x140934c20 (compares the pointers, not their slots)
}

// @0x140935690
Unk_TailIter* GetEnd(Unk_TailSet* pThis, Unk_TailIter* pRet) noexcept
{
    Unk_TailSetNode** pVal = (Unk_TailSetNode**)((void*)&((std::_Tree_comp_alloc<std::_Tset_traits<Unk_TailSetVal, Unk_TailSetLess, std::allocator<Unk_TailSetVal>, 0>>*)(void*)(pThis))->_Get_data());
    FUN_1409326c0(pRet, *pVal, std::addressof(*(Unk_TailTVal*)pVal));
    return pRet;
}

// @0x140935980
Unk_TailIter* Erase(Unk_TailSet* pThis, Unk_TailIter* pRet, Unk_TailIter itWhere)
{
    void* pVal = ((void*)&((std::_Tree_comp_alloc<std::_Tset_traits<Unk_TailSetVal, Unk_TailSetLess, std::allocator<Unk_TailSetVal>, 0>>*)(void*)(pThis))->_Get_data());
    Unk_TailIter itNext = itWhere;
    FUN_140932e60(&itNext);
    Unk_TailSetNode* pNode = (Unk_TailSetNode*)((Unk_TailTVal*)pVal)->_Extract(*reinterpret_cast<Unk_TailCIt*>(&itWhere));
    Unk_TailAlc* pAlc = ((struct Unk_TailAlc*)&((std::_Tree_comp_alloc<std::_Tset_traits<Unk_TailSetVal, Unk_TailSetLess, std::allocator<Unk_TailSetVal>, 0>>*)(void*)(pThis))->_Getal());
    FUN_1409322c0(pAlc, FUN_140932110(&pNode->m_val));
    Unk_TailTNode::_Freenode0(*reinterpret_cast<std::allocator<Unk_TailTNode>*>(pAlc), reinterpret_cast<Unk_TailTNode*>(pNode));
    FUN_1409326c0(pRet, itNext.m_pNode, std::addressof(*(Unk_TailTVal*)pVal));
    return pRet;
}

// @0x140935a90
// vector<pair<int, __int64>>::push_back(&&) as compiled here: the rvalue goes to emplace_back without a std::move call
// (the 0x14098a960 twin that the shared push_back row binds does call it)
void FUN_140935a90(std::vector<std::pair<int, __int64> >* pVec, std::pair<int, __int64>&& value)
{
    pVec->emplace_back(static_cast<std::pair<int, __int64>&&>(value));
}

// @0x140932c10
// MS2Ptr<CItemData>::AssignRaw (ms2ptr_impl.h body: swap through a temp)
template MS2Ptr<CItemData>& MS2Ptr<CItemData>::AssignRaw(CItemData* p);
// @0x140932360
Unk_TailSetNode*& FUN_140932360(Unk_TailSetNode*& pNode)
{
    return pNode;
}

// @0x1409327b0
Unk_TailTreeVal* FUN_1409327b0(Unk_TailTreeVal* pThis)
{
    pThis->m_pHead = 0;
    pThis->m_nSize = 0;
    return pThis;
}

// @0x140932830
Unk_TailTreeVal* FUN_140932830(Unk_TailTreeVal* pThis)
{
    return pThis;
}

// @0x1409334e0
void FUN_1409334e0(CPtred* pPtr)
{
    CPtred::AddRefPtred(pPtr);
}

// @0x140934710
Unk_TailVecVal* FUN_140934710(Unk_TailVecVal* pThis)
{
    return FUN_1409347d0(reinterpret_cast<Unk_TailVecVal*>(&pThis->m_pFirst));
}

// @0x140934760
Unk_TailVecVal* FUN_140934760(Unk_TailVecVal* pThis)
{
    return pThis;
}

// @0x1409347d0
Unk_TailVecVal* FUN_1409347d0(Unk_TailVecVal* pThis)
{
    return pThis;
}

// @0x140932b80
void FUN_140932b80(Unk_TailSetVal* pThis)
{
    reinterpret_cast<std::map<int, long>*>(&pThis->m_ref)->std::map<int, long>::~map();
}

// @0x140932b60
void FUN_140932b60(Unk_TailAlmVal* pThis)
{
    reinterpret_cast<CAdventureLevelMissionData*>(&pThis->m_ref)->CAdventureLevelMissionData::~CAdventureLevelMissionData();
}

// @0x140932fa0
Unk_TailAlmVal* FUN_140932fa0(Unk_TailAlmVal* pThis, unsigned nFlags)
{
    FUN_140932b60(pThis);
    if (nFlags & 1)
        ::operator delete(pThis, sizeof(Unk_TailAlmVal));
    return pThis;
}

// @0x140932fe0
Unk_TailSetVal* FUN_140932fe0(Unk_TailSetVal* pThis, unsigned nFlags)
{
    FUN_140932b80(pThis);
    if (nFlags & 1)
        ::operator delete(pThis, sizeof(Unk_TailSetVal));
    return pThis;
}

template class std::set<Unk_TailSetVal, Unk_TailSetLess>;
template class std::map<unsigned int, CAdventureLevelMissionData>;
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@IVCAdventureLevelMissionData@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@std@@@std@@@2@@Z 0x1409357e0 ; la1: called from map erase(first,last) 1409356f0, frees through the Alm _Freenode0 140931d80
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@IVCAdventureLevelMissionData@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@3@$0A@@std@@@std@@QEAA@XZ 0x140932a20 ; ua17: the mission tree dtor, called by the map dtor 0x140932b20
