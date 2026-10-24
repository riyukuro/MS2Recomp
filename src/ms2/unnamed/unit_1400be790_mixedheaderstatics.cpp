// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dynamic initializers of the header statics of a run of
// neighbouring TUs: CStringA/CStringW labels, ATL pointer arrays, hash-map style tables and the sort-name tables.
// MS2-UNIT: unit_1400be790
// MS2-RANGE: 0x1400be790-0x1400bed10 .text$di
// MS2-RANGE: 0x142c9cd70-0x142c9d010 .text$yd
// MS2-RANGE: 0x142c9d040-0x142c9d080 .text$yd
// MS2-RANGE: 0x142c9d0a0-0x142c9d0c0 .text$yd
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include "ms2/ms2recover.h"
#include "ms2/placeholder/unk_1402a9d70.h"

// Unrecovered container/record classes: only their constructor/destructor are known (called through FUN_<va>). `size`
// is the object's extent in the exe (the gap to the next static): the ctors write that far, so a smaller m_pad lets a
// full-exe ctor overwrite the neighbouring statics.
#define UNK_STATIC1(Name, ctor, dtor, size)                            \
    void ctor(void*);                                                  \
    void dtor(void*);                                                  \
    struct Name                                                        \
    {                                                                  \
        Name() { ctor(this); }                                         \
        ~Name() { dtor(this); }                                        \
        char m_pad[size];                                              \
    };

struct Unk_Be790Map
{
    Unk_Be790Map(int n1, float f1, float f2, float f3, int n2);
    ~Unk_Be790Map();
    char m_pad[0x48];
};
void FUN_14027c6b0(void*, int, float, float, float, int);
void FUN_14027deb0(void*);
Unk_Be790Map::Unk_Be790Map(int n1, float f1, float f2, float f3, int n2) { FUN_14027c6b0(this, n1, f1, f2, f3, n2); }
Unk_Be790Map::~Unk_Be790Map() { FUN_14027deb0(this); }

UNK_STATIC1(Unk_Be790B, FUN_140932870, FUN_140932b40, 0x10)
UNK_STATIC1(Unk_Be790C, FUN_14063e410, FUN_14063e780, 0x10)
UNK_STATIC1(Unk_Be790D, FUN_140333290, FUN_140333cb0, 0x10)
UNK_STATIC1(Unk_Be790E, FUN_140de0f70, FUN_140de0ff0, 0xa0)
UNK_STATIC1(Unk_Be790F, FUN_140182e30, FUN_140183b40, 0x10)
UNK_STATIC1(Unk_Be790H, FUN_140dfc480, FUN_140dfc4b0, 0x30)
UNK_STATIC1(Unk_Be790J, FUN_1408fba50, FUN_1408fba80, 0x30)

// 0x14185b130 / 0x14185b170 are this class's own ctor/dtor (symbols.tsv binds ??0/??1Unk_Be790G there; tpscameramode
// pins the same folded code as ATL's _ATL_WIN_MODULE70), so the bodies are written out here: forwarding to FUN_14185b130
// would make the full-exe ctor call itself. A block-size-10 container at +8 (FUN_140a698a0) and a CAtlArray<void*> at
// +0x38, the same pair as unit_140de0f70's object.
void FUN_140a698a0(void*, int, void*, void*, unsigned __int64);
void FUN_140a69d20(void*);
struct Unk_Be790G
{
    Unk_Be790G()
    {
        FUN_140a698a0(m_storage, 10, nullptr, nullptr, 0);
        new (&m_items) ATL::CAtlArray<void*>;
    }
    ~Unk_Be790G()
    {
        m_items.~CAtlArray<void*>();
        FUN_140a69d20(m_storage);
    }
    char m_head[8];
    char m_storage[0x30];
    union { ATL::CAtlArray<void*> m_items; };
    char m_tail[0x60 - 0x38 - sizeof(ATL::CAtlArray<void*>)];
};

struct Unk_Be790TreeA
{
    Unk_Be790TreeA(int nBlock);
    ~Unk_Be790TreeA();
    char m_pad[8];
};
void FUN_140932400(void*, int);
void FUN_140932930(void*);
Unk_Be790TreeA::Unk_Be790TreeA(int nBlock) { FUN_140932400(this, nBlock); }
Unk_Be790TreeA::~Unk_Be790TreeA() { FUN_140932930(this); }

struct Unk_PtrA;
struct Unk_PtrB;
struct Unk_PtrC;

#ifndef MS2_HOOK_DLL   // s_str2a40: the exe's object at 0x143ab2a40, which other units reach as DAT_143ab2a40 (the hook DLL binds it)
CStringA DAT_143ab2a40;
#else
extern CStringA DAT_143ab2a40;
#endif
#ifndef MS2_HOOK_DLL   // s_str2a28: the exe's object at 0x143ab2a28, which other units reach as DAT_143ab2a28 (the hook DLL binds it)
CStringA DAT_143ab2a28;
#else
extern CStringA DAT_143ab2a28;
#endif
#ifndef MS2_HOOK_DLL   // s_map30e0: the exe's object at 0x143ab30e0, which other units reach as DAT_143ab30e0 (the hook DLL binds it)
Unk_Be790Map DAT_143ab30e0(17, 0.75f, 0.25f, 2.25f, 10);
#else
extern Unk_Be790Map DAT_143ab30e0;
#endif
#ifndef MS2_HOOK_DLL   // s_arr2a58: the exe's object at 0x143ab2a58, which other units reach as DAT_143ab2a58 (the hook DLL binds it)
ATL::CAtlArray<Unk_PtrA*> DAT_143ab2a58;
#else
extern ATL::CAtlArray<Unk_PtrA*> DAT_143ab2a58;
#endif
#ifndef MS2_HOOK_DLL   // s_arr3098: the exe's object at 0x143ab3098, which other units reach as DAT_143ab3098 (the hook DLL binds it)
ATL::CAtlArray<Unk_PtrB*> DAT_143ab3098;
#else
extern ATL::CAtlArray<Unk_PtrB*> DAT_143ab3098;
#endif
#ifndef MS2_HOOK_DLL   // s_obj32e8: the exe's object at 0x143ab32e8, which other units reach as DAT_143ab32e8 (the hook DLL binds it)
Unk_Be790B DAT_143ab32e8;
#else
extern Unk_Be790B DAT_143ab32e8;
#endif
#ifndef MS2_HOOK_DLL   // s_obj32f8: the exe's object at 0x143ab32f8, which other units reach as DAT_143ab32f8 (the hook DLL binds it)
Unk_Be790C DAT_143ab32f8;
#else
extern Unk_Be790C DAT_143ab32f8;
#endif
#ifndef MS2_HOOK_DLL   // s_obj2a30: the exe's object at 0x143ab2a30, which other units reach as DAT_143ab2a30 (the hook DLL binds it)
Unk_Be790D DAT_143ab2a30;
#else
extern Unk_Be790D DAT_143ab2a30;
#endif
#ifndef MS2_HOOK_DLL   // s_wstr2d78: the exe's object at 0x143ab2d78, which other units reach as DAT_143ab2d78 (the hook DLL binds it)
CStringW DAT_143ab2d78(L"");
#else
extern CStringW DAT_143ab2d78;
#endif
#ifndef MS2_HOOK_DLL   // s_arr30b8: the exe's object at 0x143ab30b8, which other units reach as DAT_143ab30b8 (the hook DLL binds it)
ATL::CAtlArray<Unk_PtrC*> DAT_143ab30b8;
#else
extern ATL::CAtlArray<Unk_PtrC*> DAT_143ab30b8;
#endif
#ifndef MS2_HOOK_DLL   // s_obj2d80: the exe's object at 0x143ab2d80, which other units reach as DAT_143ab2d80 (the hook DLL binds it)
Unk_Be790E DAT_143ab2d80;
#else
extern Unk_Be790E DAT_143ab2d80;
#endif
#ifndef MS2_HOOK_DLL   // s_str2a48: the exe's object at 0x143ab2a48, which other units reach as DAT_143ab2a48 (the hook DLL binds it)
CStringA DAT_143ab2a48;
#else
extern CStringA DAT_143ab2a48;
#endif
#ifndef MS2_HOOK_DLL   // s_obj3308: the exe's object at 0x143ab3308, which other units reach as DAT_143ab3308 (the hook DLL binds it)
Unk_Be790F DAT_143ab3308;
#else
extern Unk_Be790F DAT_143ab3308;
#endif
#ifndef MS2_HOOK_DLL   // s_arr32b8: the exe's object at 0x143ab32b8, which other units reach as DAT_143ab32b8 (the hook DLL binds it)
ATL::CAtlArray<Unk_PtrC*> DAT_143ab32b8;
#else
extern ATL::CAtlArray<Unk_PtrC*> DAT_143ab32b8;
#endif
#ifndef MS2_HOOK_DLL   // s_arr3268: the exe's object at 0x143ab3268, which other units reach as DAT_143ab3268 (the hook DLL binds it)
ATL::CAtlArray<Unk_PtrB*> DAT_143ab3268;
#else
extern ATL::CAtlArray<Unk_PtrB*> DAT_143ab3268;
#endif
#ifndef MS2_HOOK_DLL   // s_obj2e80: the exe's object at 0x143ab2e80, which other units reach as DAT_143ab2e80 (the hook DLL binds it)
Unk_Be790G DAT_143ab2e80;
#else
extern Unk_Be790G DAT_143ab2e80;
#endif
static Unk_Be790H s_obj2e50;
#ifndef MS2_HOOK_DLL   // s_tree3288: the exe's object at 0x143ab3288, which other units reach as DAT_143ab3288 (the hook DLL binds it)
Unk_Be790TreeA DAT_143ab3288(10);
#else
extern Unk_Be790TreeA DAT_143ab3288;
#endif
#ifndef MS2_HOOK_DLL   // s_arr3058: the exe's object at 0x143ab3058, which other units reach as DAT_143ab3058 (the hook DLL binds it)
ATL::CAtlArray<Unk_PtrB*> DAT_143ab3058;
#else
extern ATL::CAtlArray<Unk_PtrB*> DAT_143ab3058;
#endif
#ifndef MS2_HOOK_DLL   // s_arr3078: the exe's object at 0x143ab3078, which other units reach as DAT_143ab3078 (the hook DLL binds it)
ATL::CAtlArray<Unk_PtrB*> DAT_143ab3078;
#else
extern ATL::CAtlArray<Unk_PtrB*> DAT_143ab3078;
#endif
#ifndef MS2_HOOK_DLL   // s_obj2e20: the exe's object at 0x143ab2e20, which other units reach as DAT_143ab2e20 (the hook DLL binds it)
Unk_Be790J DAT_143ab2e20;
#else
extern Unk_Be790J DAT_143ab2e20;
#endif
static CStringA s_sortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CStringA s_strSkill = "skill";
static CStringA s_strStun = "stun";
static Unk_1402a9d70 s_condition(17, 0.75f, 0.25f, 2.25f, 10);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9d010-0x142c9d040 .text$yd
// The exe-addressed statics (DAT_<va>, other units reach them) pinned: their look-alike ??__E/??__F bodies
// MS2-PIN: ??__EDAT_143ab2a28@@YAXXZ 0x1400be7c0
// MS2-PIN: ??__FDAT_143ab2a28@@YAXXZ 0x142c9cd90
// MS2-PIN: ??__EDAT_143ab2a30@@YAXXZ 0x1400be900
// MS2-PIN: ??__FDAT_143ab2a30@@YAXXZ 0x142c9ce50
// MS2-PIN: ??__EDAT_143ab2a40@@YAXXZ 0x1400be790
// MS2-PIN: ??__FDAT_143ab2a40@@YAXXZ 0x142c9cd70
// MS2-PIN: ??__EDAT_143ab2a48@@YAXXZ 0x1400be9c0
// MS2-PIN: ??__FDAT_143ab2a48@@YAXXZ 0x142c9ced0
// MS2-PIN: ??__EDAT_143ab2a58@@YAXXZ 0x1400be840
// MS2-PIN: ??__FDAT_143ab2a58@@YAXXZ 0x142c9cdd0
// MS2-PIN: ??__EDAT_143ab2d80@@YAXXZ 0x1400be990
// MS2-PIN: ??__FDAT_143ab2d80@@YAXXZ 0x142c9ceb0
// MS2-PIN: ??__EDAT_143ab2e20@@YAXXZ 0x1400beb70
// MS2-PIN: ??__FDAT_143ab2e20@@YAXXZ 0x142c9cff0
// MS2-PIN: ??__EDAT_143ab2e80@@YAXXZ 0x1400bea80
// MS2-PIN: ??__FDAT_143ab2e80@@YAXXZ 0x142c9cf50
// MS2-PIN: ??__EDAT_143ab3058@@YAXXZ 0x1400beb10
// MS2-PIN: ??__FDAT_143ab3058@@YAXXZ 0x142c9cfb0
// MS2-PIN: ??__EDAT_143ab3078@@YAXXZ 0x1400beb40
// MS2-PIN: ??__FDAT_143ab3078@@YAXXZ 0x142c9cfd0
// MS2-PIN: ??__EDAT_143ab3098@@YAXXZ 0x1400be870
// MS2-PIN: ??__FDAT_143ab3098@@YAXXZ 0x142c9cdf0
// MS2-PIN: ??__EDAT_143ab2d78@@YAXXZ 0x1400be930
// MS2-PIN: ??__FDAT_143ab2d78@@YAXXZ 0x142c9ce70
// MS2-PIN: ??__EDAT_143ab30b8@@YAXXZ 0x1400be960
// MS2-PIN: ??__FDAT_143ab30b8@@YAXXZ 0x142c9ce90
// MS2-PIN: ??__EDAT_143ab30e0@@YAXXZ 0x1400be7f0
// MS2-PIN: ??__FDAT_143ab30e0@@YAXXZ 0x142c9cdb0
// MS2-PIN: ??__EDAT_143ab3268@@YAXXZ 0x1400bea50
// MS2-PIN: ??__FDAT_143ab3268@@YAXXZ 0x142c9cf30
// MS2-PIN: ??__EDAT_143ab3288@@YAXXZ 0x1400beae0
// MS2-PIN: ??__FDAT_143ab3288@@YAXXZ 0x142c9cf90
// MS2-PIN: ??__EDAT_143ab32b8@@YAXXZ 0x1400bea20
// MS2-PIN: ??__FDAT_143ab32b8@@YAXXZ 0x142c9cf10
// MS2-PIN: ??__EDAT_143ab32e8@@YAXXZ 0x1400be8a0
// MS2-PIN: ??__FDAT_143ab32e8@@YAXXZ 0x142c9ce10
// MS2-PIN: ??__EDAT_143ab32f8@@YAXXZ 0x1400be8d0
// MS2-PIN: ??__FDAT_143ab32f8@@YAXXZ 0x142c9ce30
// MS2-PIN: ??__EDAT_143ab3308@@YAXXZ 0x1400be9f0
// MS2-PIN: ??__FDAT_143ab3308@@YAXXZ 0x142c9cef0
