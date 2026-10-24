// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). std::_Tree const-iterator increment glue: the postfix
// ++ of the three iterator types the event-context range erases walk (std::map<int,int>, std::set<pair<unsigned,int>>,
// std::set<Unk_UGCUploadType>), the matching prefix ++ / _Inc instances, and std::map<unsigned long,int>::iterator's
// prefix ++ (which forwards to the const-iterator one).
// MS2-UNIT: unit_1403e8e60
// MS2-RANGE: 0x1403e8e60-0x1403e9180 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x1403e8e60 ; prop
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1403e8eb0 ; prop
// MS2-PIN: ??E?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKH@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1403e8fb0 ; prop
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include <map>
#include <set>

enum Unk_UGCUploadType {};

typedef std::map<int, int> IntIntMap;
typedef std::set<std::pair<unsigned, int> > PairSet;
typedef std::set<Unk_UGCUploadType> UploadTypeSet;
typedef std::map<unsigned long, int> ULongIntMap;

template IntIntMap::const_iterator IntIntMap::const_iterator::operator++(int);   // 0x1403e8e60
template IntIntMap::const_iterator& IntIntMap::const_iterator::operator++();   // 0x1403e8eb0
template PairSet::const_iterator PairSet::const_iterator::operator++(int);   // 0x1403e8ed0
template PairSet::const_iterator& PairSet::const_iterator::operator++();   // 0x1403e8f20
template UploadTypeSet::const_iterator UploadTypeSet::const_iterator::operator++(int);   // 0x1403e8f40
template UploadTypeSet::const_iterator& UploadTypeSet::const_iterator::operator++();   // 0x1403e8f90
template ULongIntMap::iterator& ULongIntMap::iterator::operator++();   // 0x1403e8fb0
