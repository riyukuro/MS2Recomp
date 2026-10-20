// unk_optionnamelist.h - Unk_OptionNameList (commonfiles\itemoptiondata.cpp#3). NOT an original header.
#pragma once

#include <atlcoll.h>
#include "ms2/placeholder/socketptr.h"

// The stat names of one exclusive option group (the box the table's name map points at; a CPtred base, the list at
// +0x18). Owned through Unk_OptionNameListPtr (get 0x1405e9a40, operator-> 0x1405e9a70, dtor 0x1405e89b0).
typedef ATL::CAtlList<CString> Unk_OptionNameList;
template<> struct Unk_SocketRef<Unk_OptionNameList> {
    static CPtred* Base(Unk_OptionNameList* p) {
        CPtred* result;
        if (p == NULL) result = NULL;
        else result = CONTAINING_RECORD(p, TPtredDummy<Unk_OptionNameList>, value);
        return result;
    }
    static TPtredDummy<Unk_OptionNameList>* New(void*) { return new TPtredDummy<Unk_OptionNameList>(); }
    static Unk_OptionNameList* Value(CPtred* p) {
        Unk_OptionNameList* result;
        if (p == NULL) result = NULL;
        else result = &static_cast<TPtredDummy<Unk_OptionNameList>*>(p)->value;
        return result;
    }
    static Unk_OptionNameList* Create(void*) { return Value(FUN_1401ba820(New(NULL))); }
};
MS2_SOCKETPTR_BOXED(Unk_OptionNameList)
typedef Unk_SocketPtr<Unk_OptionNameList> Unk_OptionNameListPtr;
