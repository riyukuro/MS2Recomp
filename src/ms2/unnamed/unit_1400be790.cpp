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

// Unrecovered container/record classes: only their constructor/destructor are known (called through FUN_<va>).
#define UNK_STATIC1(Name, ctor, dtor)                                  \
    void ctor(void*);                                                  \
    void dtor(void*);                                                  \
    struct Name                                                        \
    {                                                                  \
        Name() { ctor(this); }                                         \
        ~Name() { dtor(this); }                                        \
        char m_pad[8];                                                 \
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

UNK_STATIC1(Unk_Be790B, FUN_140932870, FUN_140932b40)
UNK_STATIC1(Unk_Be790C, FUN_14063e410, FUN_14063e780)
UNK_STATIC1(Unk_Be790D, FUN_140333290, FUN_140333cb0)
UNK_STATIC1(Unk_Be790E, FUN_140de0f70, FUN_140de0ff0)
UNK_STATIC1(Unk_Be790F, FUN_140182e30, FUN_140183b40)
UNK_STATIC1(Unk_Be790G, FUN_14185b130, FUN_14185b170)
UNK_STATIC1(Unk_Be790H, FUN_140dfc480, FUN_140dfc4b0)
UNK_STATIC1(Unk_Be790J, FUN_1408fba50, FUN_1408fba80)

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

static CStringA s_str2a40;
static CStringA s_str2a28;
static Unk_Be790Map s_map30e0(17, 0.75f, 0.25f, 2.25f, 10);
static ATL::CAtlArray<Unk_PtrA*> s_arr2a58;
static ATL::CAtlArray<Unk_PtrB*> s_arr3098;
static Unk_Be790B s_obj32e8;
static Unk_Be790C s_obj32f8;
static Unk_Be790D s_obj2a30;
static CStringW s_wstr2d78(L"");
static ATL::CAtlArray<Unk_PtrC*> s_arr30b8;
static Unk_Be790E s_obj2d80;
static CStringA s_str2a48;
static Unk_Be790F s_obj3308;
static ATL::CAtlArray<Unk_PtrC*> s_arr32b8;
static ATL::CAtlArray<Unk_PtrB*> s_arr3268;
static Unk_Be790G s_obj2e80;
static Unk_Be790H s_obj2e50;
static Unk_Be790TreeA s_tree3288(10);
static ATL::CAtlArray<Unk_PtrB*> s_arr3058;
static ATL::CAtlArray<Unk_PtrB*> s_arr3078;
static Unk_Be790J s_obj2e20;
static CStringA s_sortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CStringA s_strSkill = "skill";
static CStringA s_strStun = "stun";
static Unk_1402a9d70 s_condition(17, 0.75f, 0.25f, 2.25f, 10);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9d010-0x142c9d040 .text$yd
