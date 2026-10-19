// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Container COMDAT tail: std::map<__int64, CStringA> tree code
// (insert, rotations, erase, clear), std::vector<SceneGraphCacheDataPtr, efd::CustomAllocator> and the std::unordered_map
// <unsigned int, int> helpers. The owning TU is not identified, so the instantiations are driven from unit-local anchors.
// MS2-UNIT: unit_1414a6be0
// MS2-RANGE: 0x1414a6be0-0x1414a8240 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@_JV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@_J@std@@V?$allocator@U?$pair@$$CB_JV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@4@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CB_JV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@2@@Z 0x1414a74c0 ; prop
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@V?$SmartPointer@VSceneGraphCacheData@SceneGraphCache@ecr@@@efd@@V?$CustomAllocator@V?$SmartPointer@VSceneGraphCacheData@SceneGraphCache@ecr@@@efd@@@2@@std@@@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@V?$SmartPointer@VSceneGraphCacheData@SceneGraphCache@ecr@@@efd@@@std@@@2@XZ 0x1414a75a0 ; unique
// MS2-PIN: ??Yutf8string@efd@@QEAAAEAV01@PEBD@Z 0x1414a7d40 ; unique
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CB_JV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CB_JV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CB_JV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@2@_K@Z 0x1414a7f10 ; prop
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@$$CB_JV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@$$CB_JV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@2@_K@Z 0x1414a7f40 ; prop
// MS2-PINS-END tplpin
// MS2-PIN: ?Unk_1414a7d40@@YAAEAVutf8string@efd@@PEAV12@PEBD@Z 0x1414a7d40
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <map>
#include <vector>
#include <unordered_map>
#include <string>
#include <efd/utf8string.h>
#include <ecr/SceneGraphCache.h>
#include "ms2/ms2recover.h"

struct Unk_CacheAccess : public ecr::SceneGraphCache
{
    typedef SceneGraphCacheDataPtr Ptr;
};
typedef Unk_CacheAccess::Ptr Unk_CachePtr;
typedef std::map<__int64, CStringA> Unk_Int64StrMap;
typedef std::vector<Unk_CachePtr, efd::CustomAllocator<Unk_CachePtr> > Unk_CacheDataVec;

// Composite key of the unordered_map; its hasher (FUN_140ad7090, shared with the owner of this container) hashes the
// members at +0 and +8 and is not a std::hash specialization the exe instantiates here.
struct Unk_HashKey
{
    unsigned __int64 m_a;
    unsigned __int64 m_b;
    bool operator==(const Unk_HashKey& o) const { return m_a == o.m_a && m_b == o.m_b; }
};
struct Unk_HashKeyHash
{
    size_t operator()(const Unk_HashKey& k) const;
};
typedef std::unordered_map<Unk_HashKey, int, Unk_HashKeyHash> Unk_KeyIntMap;

void Unk_1414a6be0_MapAnchor(Unk_Int64StrMap& m, __int64 k, const CStringA& s)
{
    m.insert(Unk_Int64StrMap::value_type(k, s));
    m[k] = s;
    m.erase(m.begin());
    if (m.empty())
        m[0] = s;
    m.clear();
    Unk_Int64StrMap c(m);
}

void Unk_1414a6be0_VecAnchor(Unk_CacheDataVec& v, const Unk_CachePtr& p)
{
    v.push_back(p);
    v.reserve(16);
    v.resize(4);
    v.erase(v.begin());
    v.clear();
    Unk_CacheDataVec c(v);
}

int Unk_1414a6be0_HashAnchor(Unk_KeyIntMap& m, const Unk_HashKey& k)
{
    m.insert(Unk_KeyIntMap::value_type(k, 1));
    m[k] = 2;
    m.erase(k);
    m.rehash(8);
    return m.find(k) != m.end();
}

int Unk_1414a6be0_WStrMapAnchor(std::unordered_map<std::wstring, int>& m)
{
    std::unordered_map<std::wstring, int> c(m);
    m.clear();
    return (int)c.size();
}

// utf8string::operator+=(const char*) as compiled in another TU: a forwarder to that TU's string append (FUN_14112cd60).
void FUN_14112cd60(efd::utf8string* s, const char* p);

// @0x1414a7d40
efd::utf8string& Unk_1414a7d40(efd::utf8string* s, const char* p)
{
    FUN_14112cd60(s, p);
    return *s;
}
