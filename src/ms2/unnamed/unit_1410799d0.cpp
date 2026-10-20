// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Second template tail of the character mesh merger: the members of the efd::vector /
// set / map instantiations that sort after unit_141073440's range (_Tree erase .. lower_bound, max_size ..). Same instantiation list and element
// types as unit_141073440 / client/ms2/charactermeshmerger.cpp.
// MS2-UNIT: unit_1410799d0
// MS2-RANGE: 0x1410799d0-0x141079ed0 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@std@@@std@@@2@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z 0x1410799d0
// MS2-PIN: ?find@?$_Tree@V?$_Tset_traits@PEAVNiAVObject@@U?$less@PEAVNiAVObject@@@std@@V?$CustomAllocator@PEAVNiAVObject@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@PEAVNiAVObject@@@std@@@std@@@2@AEBQEAVNiAVObject@@@Z 0x141079ab0
// MS2-PIN: ?key_comp@?$_Tree@V?$_Tmap_traits@EEU?$less@E@std@@V?$CustomAllocator@U?$pair@$$CBEE@std@@@efd@@$0A@@std@@@std@@QEBA?AU?$less@E@2@XZ 0x141079b90 ; prop
// MS2-PIN: ?key_comp@?$_Tree@V?$_Tset_traits@EU?$less@E@std@@V?$CustomAllocator@E@efd@@$0A@@std@@@std@@QEBA?AU?$less@E@2@XZ 0x141079bf0 ; prop
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAVTexNode@CCharacterMeshMerger@@@std@@@std@@@std@@@2@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z 0x141079d10
// MS2-PIN: ?max_size@?$CustomAllocator@PEAVNiMesh@@@efd@@QEBA_KXZ 0x141079df0 ; fx19 chain
// MS2-PIN: ?max_size@?$CustomAllocator@UUnk_AtlasResult@@@efd@@QEBA_KXZ 0x141079ec0 ; fx19 chain
// MS2-PIN: ?max_size@?$CustomAllocator@V?$vector@E@efd@@@efd@@QEBA_KXZ 0x141079ea0 ; fx19 chain
// MS2-PIN: ?max_size@?$CustomAllocator@V?$vector@PEAVNiMesh@@@efd@@@efd@@QEBA_KXZ 0x141079eb0 ; fx19 chain
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/charactermeshmerger.h"
#include <NiMesh.h>
#include <NiNode.h>
#include <NiTexturingProperty.h>
#include <NiPoint2.h>
#include <NiTransform.h>
#include <NiDataStream.h>

// Element types of the mesh merger's containers (layouts proven in charactermeshmerger.cpp).
struct Unk_StreamElementDesc
{
    Unk_StreamElementDesc() : m_uiIndex(0), m_eFormat(NiDataStreamElement::F_UNKNOWN) {}    // explicit instantiation of the vector needs it
    Unk_StreamElementDesc(const NiFixedString& kSemantic, unsigned int uiIndex, NiDataStreamElement::Format eFormat)
        : m_kSemantic(kSemantic), m_uiIndex(uiIndex), m_eFormat(eFormat) {}

    NiFixedString m_kSemantic;
    unsigned int m_uiIndex;
    NiDataStreamElement::Format m_eFormat;
};
MS2_CHECK_SIZE(Unk_StreamElementDesc, 0x10);

struct Unk_UVRect
{
    Unk_UVRect() {}

    NiPoint2 m_kOffset;
    NiPoint2 m_kScale;
};
MS2_CHECK_SIZE(Unk_UVRect, 0x10);

struct Unk_AtlasResult
{
    Unk_AtlasResult() {}
    ~Unk_AtlasResult() {}

    efd::SmartPointer<NiTexturingProperty> m_spTexturing;
    efd::map<NiMesh*, Unk_UVRect> m_kPlacement;
};
MS2_CHECK_SIZE(Unk_AtlasResult, 0x18);

struct Unk_TransformLess
{
    bool operator()(const NiTransform& kA, const NiTransform& kB) const;
};

template class std::vector<unsigned char, efd::CustomAllocator<unsigned char> >;
template class std::vector<efd::vector<unsigned char>, efd::CustomAllocator<efd::vector<unsigned char> > >;
template class std::vector<efd::set<unsigned char>, efd::CustomAllocator<efd::set<unsigned char> > >;
template class std::vector<efd::set<NiAVObject*>, efd::CustomAllocator<efd::set<NiAVObject*> > >;
template class std::vector<efd::map<unsigned char, unsigned char>, efd::CustomAllocator<efd::map<unsigned char, unsigned char> > >;
template class std::vector<NiAVObject*, efd::CustomAllocator<NiAVObject*> >;
template class std::vector<NiDataStreamRef*, efd::CustomAllocator<NiDataStreamRef*> >;
template class std::vector<Unk_AtlasResult, efd::CustomAllocator<Unk_AtlasResult> >;
template class std::set<unsigned char, std::less<unsigned char>, efd::CustomAllocator<unsigned char> >;
template class std::set<NiAVObject*, std::less<NiAVObject*>, efd::CustomAllocator<NiAVObject*> >;
template class std::map<unsigned char, unsigned char, std::less<unsigned char>, efd::CustomAllocator<std::pair<const unsigned char, unsigned char> > >;
template class std::map<NiMesh*, efd::map<unsigned char, unsigned char>, std::less<NiMesh*>, efd::CustomAllocator<std::pair<NiMesh* const, efd::map<unsigned char, unsigned char> > > >;
template class std::map<NiMesh*, Unk_UVRect, std::less<NiMesh*>, efd::CustomAllocator<std::pair<NiMesh* const, Unk_UVRect> > >;
template class std::map<CString, CCharacterMeshMerger::TexNode*, std::less<CString>, efd::CustomAllocator<std::pair<const CString, CCharacterMeshMerger::TexNode*> > >;
template class std::map<NiTransform, MeshList, Unk_TransformLess, efd::CustomAllocator<std::pair<const NiTransform, MeshList> > >;
template class std::vector<NiMesh*, efd::CustomAllocator<NiMesh*> >;
template class std::vector<MeshList, efd::CustomAllocator<MeshList> >;
template class std::vector<Unk_StreamElementDesc, std::allocator<Unk_StreamElementDesc> >;
template void std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned char> > >::_Seek_to(const unsigned char*);
template std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tree_simple_types<unsigned char> > >
    std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<unsigned char> > >::_Unwrapped() const;

// find is not part of the explicit set/map instantiations above (it lives in the _Tree base), so the two the exe keeps are named here: the
// TexNode map's (0x1410799d0 -> lower_bound 0x141079d10 -> less<CString>) and set<NiAVObject*>'s (0x141079ab0 -> 0x141079d70 -> the set's less 0x14106a330).
typedef std::map<CString, CCharacterMeshMerger::TexNode*, std::less<CString>, efd::CustomAllocator<std::pair<const CString, CCharacterMeshMerger::TexNode*> > > Unk_TexNodeMap;
typedef std::set<NiAVObject*, std::less<NiAVObject*>, efd::CustomAllocator<NiAVObject*> > Unk_AVObjectSet;
template Unk_TexNodeMap::iterator Unk_TexNodeMap::_Mybase::find(const CString&);
template Unk_AVObjectSet::iterator Unk_AVObjectSet::_Mybase::find(NiAVObject* const&);
// fx17: the finds and lower_bounds by call graph (find -> lower_bound -> _Lbound -> comparator), so the look-alike pairing cannot rotate them between gates
