// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CU name unknown: the std::_Tree iterator decrement COMDATs (const/plain/unchecked
// operator--) of the event tables used by commonfiles\gameevent.cpp (map<int,int>, map<unsigned,int>, set<pair<unsigned,int>>,
// set<UGC upload kind>) plus less<UGC upload kind>. Pure template glue: the original TU construct that instantiated them first is
// unknown, so a never-called driver instantiates the same members and tplpin pairs them.
// MS2-UNIT: unit_1403e9210
// MS2-RANGE: 0x1403e9210-0x1403e9650 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1403e9210 ; prop
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1403e9230 ; prop
// MS2-PIN: ??F?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1403e9290 ; prop
// MS2-PIN: ??F?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1403e92b0 ; prop
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x1403e93a0 ; prop
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\unknown_1403e9210.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <map>
#include <set>
#include <utility>

enum Unk_UGCUploadType
{
};

template <class C> static void Unk_DecrementAll(C& c)
{
    typename C::const_iterator ci = c.end();
    --ci;
    typename C::iterator it = c.end();
    --it;
    typename C::_Unchecked_const_iterator ui = c._Unchecked_end();
    --ui;
}

void Unk_E9210Drive(std::map<int, int>& m, std::map<unsigned, int>& mk, std::set<std::pair<unsigned, int> >& sp,
                    std::set<Unk_UGCUploadType>& su)
{
    Unk_DecrementAll(m);
    Unk_DecrementAll(mk);
    Unk_DecrementAll(sp);
    Unk_DecrementAll(su);
    std::less<Unk_UGCUploadType>()(Unk_UGCUploadType(), Unk_UGCUploadType());
}
