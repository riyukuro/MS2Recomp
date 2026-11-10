// Stand-in map value type of unit_140447ef0 (eventvaluemapglue.cpp), shared so that the two COMDAT-tail units whose
// ranges hold its pointer_traits / addressof copies (unit_14045b740, commonfiles/gameeventvalue.cpp) name the same
// instantiations as the exe chain: _Tree_const_iterator<V8<10>>::operator-> 0x140448270 calls
// pointer_traits<const pair*>::pointer_to 0x14046c3b0, which calls addressof<const pair> 0x14043fd70.
#pragma once

template <int N> struct Unk_Gev447V8 { void* raw; };        // value type of alignment 8
