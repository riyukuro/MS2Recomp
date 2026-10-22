// nametagsymboltable.h - CNametagSymbolData / CNametagSymbolTable (RTTI names): the name tag symbol table read from
// Table/nametagSymbol.xml (<symbol id icon conditionType code hideSymbol buffID buffLv pushSymbol/>) and the rules that
// decide which symbol a player shows. Header name assumed. Member names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"

// The xml "conditionType" attribute (a name, FUN_1406c67a0 is its converter).
enum NametagConditionType
{
    NAMETAG_CONDITION_NONE = 0,
    NAMETAG_CONDITION_LEVEL = 1,
    NAMETAG_CONDITION_ENCHANT = 2,
    NAMETAG_CONDITION_TITLE = 3,
    NAMETAG_CONDITION_TROPHY_POINT = 4,
    NAMETAG_CONDITION_VIP = 5,
    NAMETAG_CONDITION_TENCENTVIP = 6,
    NAMETAG_CONDITION_TGP = 7,
    NAMETAG_CONDITION_GM = 8,
    NAMETAG_CONDITION_RETURN_USER = 9,
    NAMETAG_CONDITION_BIRTHDAY = 10,
    NAMETAG_CONDITION_ADVENTURE_LEVEL = 11,
    NAMETAG_CONDITION_BURNING = 12,
    NAMETAG_CONDITION_SURVIVAL_LEVEL = 13,
};

// The own player as the nametag rules query it (an unrecovered class; only the slots and the member used here).
class Unk_NametagActor
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_59();
    virtual void vfunc_60();
    virtual void vfunc_61();
    virtual void vfunc_62();
    virtual void vfunc_63();
    virtual void vfunc_64();
    virtual void vfunc_65();
    virtual void vfunc_66();
    virtual void vfunc_67();
    virtual void vfunc_68();
    virtual void vfunc_69();
    virtual void vfunc_70();
    virtual void vfunc_71();
    virtual void vfunc_72();
    virtual void vfunc_73();
    virtual void vfunc_74();
    virtual void vfunc_75();
    virtual void vfunc_76();
    virtual void vfunc_77();
    virtual unsigned short vfunc_78();                  // 0x270 the level
    virtual void vfunc_79();
    virtual void vfunc_80();
    virtual void vfunc_81();
    virtual void vfunc_82();
    virtual void vfunc_83();
    virtual void vfunc_84();
    virtual void vfunc_85();
    virtual void vfunc_86();
    virtual void vfunc_87();
    virtual void vfunc_88();
    virtual void vfunc_89();
    virtual void vfunc_90();
    virtual void vfunc_91();
    virtual void vfunc_92();
    virtual void vfunc_93();
    virtual void vfunc_94();
    virtual void vfunc_95();
    virtual void vfunc_96();
    virtual void vfunc_97();
    virtual void vfunc_98();
    virtual void vfunc_99();
    virtual void vfunc_100();
    virtual void vfunc_101();
    virtual void vfunc_102();
    virtual void vfunc_103();
    virtual void vfunc_104();
    virtual void vfunc_105();
    virtual void vfunc_106();
    virtual void vfunc_107();
    virtual void vfunc_108();
    virtual void vfunc_109();
    virtual void vfunc_110();
    virtual void vfunc_111();
    virtual void vfunc_112();
    virtual void vfunc_113();
    virtual void vfunc_114();
    virtual void vfunc_115();
    virtual void vfunc_116();
    virtual void vfunc_117();
    virtual void vfunc_118();
    virtual void vfunc_119();
    virtual void vfunc_120();
    virtual void vfunc_121();
    virtual void vfunc_122();
    virtual void vfunc_123();
    virtual void vfunc_124();
    virtual void vfunc_125();
    virtual void vfunc_126();
    virtual void vfunc_127();
    virtual void vfunc_128();
    virtual void vfunc_129();
    virtual void vfunc_130();
    virtual void vfunc_131();
    virtual void vfunc_132();
    virtual void vfunc_133();
    virtual void vfunc_134();
    virtual void vfunc_135();
    virtual void vfunc_136();
    virtual void vfunc_137();
    virtual void vfunc_138();
    virtual void vfunc_139();
    virtual void vfunc_140();
    virtual unsigned int vfunc_141();                   // 0x468 the adventure level
    unsigned int FUN_141661e40(void* pA, void* pB);     // enchant condition (two out values)
    unsigned int FUN_141662de0();                       // vip
    int FUN_141663080();                                // tencent vip
    unsigned int FUN_1416630c0();                       // tgp
    unsigned int FUN_14165ffe0();                       // return user state
    unsigned int FUN_141660030();                       // birthday
    unsigned char FUN_1415275b0(unsigned short nId);    // burning
    unsigned short FUN_141663b50();                     // survival level
    int GetGmGrade();                                // the gm grade (member +0x11c8)
private:
    char m_pad[0x11c8 - 8];
    int m_nGmGrade;
};

// One <symbol> row. RTTI CNametagSymbolData, 0x40 bytes, base CPtred; vftable slot 0 the deleting destructor.
class CNametagSymbolData : public CPtred
{
public:
    CNametagSymbolData();                   // 0x1406c6ed0
    virtual ~CNametagSymbolData();          // 0x1406c70f0

    unsigned short m_nId;                   // +0x18 "id"
    NametagConditionType m_eCondition;      // +0x1c "conditionType"
    unsigned int m_nCode;                   // +0x20 "code" (the condition value)
    CStringW m_strIcon;                     // +0x28 "icon"
    int m_nHideSymbol;                      // +0x30 "hideSymbol"
    unsigned int m_nBuffId;                 // +0x34 "buffID"
    unsigned short m_nBuffLv;               // +0x38 "buffLv"
    int m_nPushSymbol;                      // +0x3c "pushSymbol"
};
MS2_CHECK_SIZE(CNametagSymbolData, 0x40);
MS2_CHECK_OFFSET(CNametagSymbolData, m_strIcon, 0x28);
MS2_CHECK_OFFSET(CNametagSymbolData, m_nPushSymbol, 0x3c);

typedef MS2Ptr<CNametagSymbolData> CNametagSymbolDataPtr;

// The table. RTTI CNametagSymbolTable, 0x60 bytes: TSingleton +0, CValidData +8, the id -> row map +0x10 and the ids in
// file order +0x40. Created by CGameApp::InitInstance (?\ms2.cpp).
class CNametagSymbolTable : public TSingleton<CNametagSymbolTable>,
                            public CValidData<CNametagSymbolTable>
{
public:
    CNametagSymbolTable();                  // 0x1406c53d0
    virtual ~CNametagSymbolTable();         // 0x1406c5460

    int Load();                             // 0x1406c54d0 parses the xml (0 when the file is missing)
    CNametagSymbolDataPtr GetData(unsigned short nId);                  // 0x1406c58c0
    CNametagSymbolDataPtr FindByTitle(int nTitleId);                    // 0x1406c5950 the title symbol of a title id
    bool Exists(unsigned short nId);                                    // 0x1406c5a70
    bool IsType(unsigned short nId, int nType);                         // 0x1406c5b00
    unsigned short FindIdByType(int nType);                             // 0x1406c5bb0 the first symbol of a condition type
    bool IsShown(unsigned short nId);                                   // 0x1406c5c80 hideSymbol set and the condition holds not
    unsigned int CheckCondition(unsigned short nId);                    // 0x1406c5d60 the own player fulfils the condition
    CStringW GetIconRanked(unsigned short nId, Unk_NametagActor* pActor);   // 0x1406c61a0
    CStringW GetIcon(unsigned short nId, Unk_NametagActor* pActor);     // 0x1406c6360
    CStringW GetIcon(unsigned short nId);                               // 0x1406c66d0 the plain icon name

    static void CheckInit();                // 0x1406c7330
    static void SetInit(bool b);            // 0x1406c82c0

    static bool s_bInit;                    // DAT_143ab05c0

private:
    MS2_LAYOUT_FRIEND;
    ATL::CRBMap<unsigned short, CNametagSymbolDataPtr> m_map;   // +0x10 id -> row
    ATL::CAtlArray<unsigned short> m_arrIds;                    // +0x40
};
MS2_CHECK_SIZE(CNametagSymbolTable, 0x60);
MS2_CHECK_OFFSET(CNametagSymbolTable, m_map, 0x10);
MS2_CHECK_OFFSET(CNametagSymbolTable, m_arrIds, 0x40);
