// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). std iterator comparison glue near 0x1403e8650: the _Tree
// const-iterator ==/!= instances (std::map<int,int> plus three more whose element types are not recoverable per copy),
// the vector const-iterator ==/!= pair that goes through the empty _Compat check, and the two CAtlArray<4-byte>::GetAt
// copies (bounds check, then `m_pData + n * 4`). Unit-local stand-ins as in unit_1403e8960.
// MS2-UNIT: unit_1403e8650
// MS2-RANGE: 0x1403e8650-0x1403e8960 .text$mn
// MS2-PIN: ??8?$Unk_TreeIter@$0A@@@QEBA_NAEBV0@@Z 0x1403e8690
// MS2-PIN: ??9?$Unk_TreeIter@$0A@@@QEBA_NAEBV0@@Z 0x1403e87e0
// MS2-PIN: ??8?$Unk_TreeIter@$00@@QEBA_NAEBV0@@Z 0x1403e86d0
// MS2-PIN: ??9?$Unk_TreeIter@$00@@QEBA_NAEBV0@@Z 0x1403e8820
// MS2-PIN: ??8?$Unk_TreeIter@$01@@QEBA_NAEBV0@@Z 0x1403e8710
// MS2-PIN: ??9?$Unk_TreeIter@$01@@QEBA_NAEBV0@@Z 0x1403e8860
// MS2-PIN: ??8?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@H@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x1403e8750
// MS2-PIN: ??9?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@H@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x1403e88a0
// MS2-PIN: ??A?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@QEAAAEAH_K@Z 0x1403e88e0
// MS2-PIN: ??A?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@QEAAAEAI_K@Z 0x1403e8920
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include <map>
#include <vector>
#include <atlcoll.h>

// Tree-node iterator: the node pointer only.
template <int N>
class Unk_TreeIter
{
public:
    bool operator==(const Unk_TreeIter& right) const { return m_pNode == right.m_pNode; }
    bool operator!=(const Unk_TreeIter& right) const { return !(*this == right); }
    char* m_pNode;
};

typedef std::map<int, int> IntIntMap;

template bool IntIntMap::const_iterator::operator==(const IntIntMap::const_iterator&) const;   // 0x1403e8650
template bool Unk_TreeIter<0>::operator==(const Unk_TreeIter<0>&) const;   // 0x1403e8690
template bool Unk_TreeIter<1>::operator==(const Unk_TreeIter<1>&) const;   // 0x1403e86d0
template bool Unk_TreeIter<2>::operator==(const Unk_TreeIter<2>&) const;   // 0x1403e8710
template bool std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<int> > >::operator==(const std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<int> > >&) const;   // 0x1403e8750
template bool IntIntMap::const_iterator::operator!=(const IntIntMap::const_iterator&) const;   // 0x1403e87a0
template bool Unk_TreeIter<0>::operator!=(const Unk_TreeIter<0>&) const;   // 0x1403e87e0
template bool Unk_TreeIter<1>::operator!=(const Unk_TreeIter<1>&) const;   // 0x1403e8820
template bool Unk_TreeIter<2>::operator!=(const Unk_TreeIter<2>&) const;   // 0x1403e8860
template bool std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<int> > >::operator!=(const std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<int> > >&) const;   // 0x1403e88a0
template int& ATL::CAtlArray<int, ATL::CElementTraits<int> >::operator[](size_t) throw();   // 0x1403e88e0
template unsigned& ATL::CAtlArray<unsigned, ATL::CElementTraits<unsigned> >::operator[](size_t) throw();   // 0x1403e8920
