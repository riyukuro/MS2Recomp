// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). COMDAT tail of the ranking item / answer obj of
// ?\gamerankingcli.cpp (that unit ends at 0x140b498e0; its obj's selectany COMDATs continue here): the ATL CRBMap /
// CRBTree members of the rank -> row and name -> row maps of the GameRanking answers (InsertImpl, IsNil, LeftRotate,
// Lookup, Maximum, Minimum, NewNode, Predecessor, RBInsert, RemoveAll, RemovePostOrder, RightRotate, SetAt, SetNil,
// Successor) and three inline members of gamerankingcli.h (IResponse::IsPercent, MyRankPercent::IsPercent,
// Page::SetTotal).
//
// In the original these were instantiated by the answer code in gamerankingcli.cpp (Read -> SetAt, Search ->
// Lookup, Page/answer dtors -> RemoveAll, CRBTree::Find -> Predecessor, GetHeadPosition -> Minimum, GetNext ->
// Successor). This file stands in for that tail on its own: explicit instantiations of exactly the members the exe
// has (their callees come along implicitly), over the map types of gamerankingcli.h, plus one anchor for the inline
// members. A probe compiling gamerankingcli.cpp under this range pairs the same 417 functions.
// MS2-UNIT: unit_140b498e0
// MS2-RANGE: 0x140b498e0-0x140b5faf0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\gamerankingcli.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/gamerankingcli.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"

// The CRBTree base of a CRBMap (the protected tree members are instantiated on it).
template <class M> struct Unk_GrTreeOf;
template <class K, class V, class KTraits, class VTraits>
struct Unk_GrTreeOf<ATL::CRBMap<K, V, KTraits, VTraits> >
{
    typedef ATL::CRBTree<K, V, KTraits, VTraits> Type;
};

// The members every map of the answers uses: SetAt (Read), RemoveAll (dtors), Predecessor (CRBTree::Find).
#define MS2_GR_MAP_COMMON(Map, Tree)                                                                            \
    template POSITION Map::SetAt(Map::KINARGTYPE, Map::VINARGTYPE);                                             \
    template void Tree::RemoveAll() throw();                                                                    \
    template Tree::CNode* Tree::Predecessor(Tree::CNode*) const throw()

// rank -> row map of a board: Lookup by rank (GetPage); the searchable boards also walk it (GetHeadPosition ->
// Minimum, GetNext -> Successor).
#define MS2_GR_RANKS(Name)                                                                                      \
    typedef decltype(GameRanking::Name::m_ranks) Unk_GrRanks_##Name;                                            \
    typedef Unk_GrTreeOf<Unk_GrRanks_##Name>::Type Unk_GrRanksTree_##Name;                                      \
    MS2_GR_MAP_COMMON(Unk_GrRanks_##Name, Unk_GrRanksTree_##Name);                                              \
    template bool Unk_GrRanks_##Name::Lookup(Unk_GrRanks_##Name::KINARGTYPE, Unk_GrRanks_##Name::VOUTARGTYPE) const

#define MS2_GR_RANKS_WALK(Name)                                                                                 \
    MS2_GR_RANKS(Name);                                                                                         \
    template Unk_GrRanksTree_##Name::CNode* Unk_GrRanksTree_##Name::Minimum(Unk_GrRanksTree_##Name::CNode*) const throw(); \
    template Unk_GrRanksTree_##Name::CNode* Unk_GrRanksTree_##Name::Successor(Unk_GrRanksTree_##Name::CNode*) const throw()

// name -> row map of a searchable board: both Lookups (Search, Merge).
#define MS2_GR_NAMES(Name)                                                                                      \
    typedef decltype(GameRanking::Name::m_names) Unk_GrNames_##Name;                                            \
    typedef Unk_GrTreeOf<Unk_GrNames_##Name>::Type Unk_GrNamesTree_##Name;                                      \
    MS2_GR_MAP_COMMON(Unk_GrNames_##Name, Unk_GrNamesTree_##Name);                                              \
    template Unk_GrNames_##Name::CPair* Unk_GrNames_##Name::Lookup(Unk_GrNames_##Name::KINARGTYPE) throw();     \
    template bool Unk_GrNames_##Name::Lookup(Unk_GrNames_##Name::KINARGTYPE, Unk_GrNames_##Name::VOUTARGTYPE) const

#define MS2_GR_LIST(Name)                                                                                       \
    MS2_GR_RANKS_WALK(Name);                                                                                    \
    MS2_GR_NAMES(Name)

MS2_GR_LIST(GuildTrophy);
MS2_GR_LIST(UserTrophy);
MS2_GR_LIST(DarkStream);
MS2_GR_LIST(UserPvp);
MS2_GR_LIST(GuildPvp);
MS2_GR_LIST(UgcMapCommendation);
MS2_GR_LIST(BossKillCount);
MS2_GR_RANKS(BossKillRecord);
MS2_GR_LIST(Arcade);
MS2_GR_LIST(BossDamageCount);
MS2_GR_RANKS(BossDamageDate);
MS2_GR_RANKS(BossDamageAmount);
MS2_GR_LIST(BossRumbleCount);
MS2_GR_RANKS(BossRumbleRecord);
MS2_GR_LIST(WorldChampion);
MS2_GR_LIST(BossColosseum);

// The rows of a page (Page::Add -> SetAt, GetItem -> Lookup, GetFirstItem -> GetHeadPosition, ~Page -> RemoveAll).
typedef decltype(GameRanking::Page::m_items) Unk_GrPageItems;
typedef Unk_GrTreeOf<Unk_GrPageItems>::Type Unk_GrPageItemsTree;
MS2_GR_MAP_COMMON(Unk_GrPageItems, Unk_GrPageItemsTree);
template bool Unk_GrPageItems::Lookup(Unk_GrPageItems::KINARGTYPE, Unk_GrPageItems::VOUTARGTYPE) const;
template Unk_GrPageItemsTree::CNode* Unk_GrPageItemsTree::Minimum(Unk_GrPageItemsTree::CNode*) const throw();

#undef MS2_GR_LIST
#undef MS2_GR_NAMES
#undef MS2_GR_RANKS_WALK
#undef MS2_GR_RANKS
#undef MS2_GR_MAP_COMMON

// Anchor for the three inline header members of the tail (the answers' vftables and Read code emit them in the
// original obj). Not an exe function; invented name.
void Unk_GrTailInlines(GameRanking::IResponse* pResponse, GameRanking::MyRankPercent* pPercent,
                       GameRanking::Page* pPage)
{
    pResponse->GameRanking::IResponse::IsPercent();
    pPercent->GameRanking::MyRankPercent::IsPercent();
    pPage->SetTotal(0);
}
