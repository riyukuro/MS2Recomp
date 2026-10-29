// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). NM map lookup and string delimiter searches.
// MS2-UNIT: unit_14160a570
// MS2-RANGE: 0x14160a570-0x14160a7f0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include <functional>
#include <string>

struct NmByteTreeIter
{
    void* node;

    bool FUN_1415f2a60(const NmByteTreeIter& right) const;     // operator==
};

// The byte-keyed std::map the iterators walk; the helpers are its members (this = the map, the iterator comes back
// through the hidden return slot).
struct NmByteTree
{
    NmByteTreeIter FUN_1416099b0();                             // end()
    NmByteTreeIter FUN_14160a570(const unsigned char& key);     // find()
};

extern void* FUN_1415dbdb0(void* tree, const unsigned char& key);
extern void* FUN_14160a790(void* tree, void* result, const unsigned char* key);
extern const unsigned char& FUN_141602800(void* tree, void* node);
extern const std::less<unsigned char>& FUN_141602090(void* tree);
extern void** FUN_141600e10(void* tree);
extern const void* FUN_1415e1750(void* data);
extern void FUN_1415e5cf0(void* iterator, void* node, const void* data);

// @0x14160a570
NmByteTreeIter NmByteTree::FUN_14160a570(const unsigned char& key)
{
    NmByteTreeIter lowerBound;
    FUN_14160a790(this, &lowerBound, &key);
    return (lowerBound.FUN_1415f2a60(FUN_1416099b0()) || FUN_141602090(this)(key, FUN_141602800(this, lowerBound.node)))
        ? FUN_1416099b0() : lowerBound;
}

// MS2-FUNCTIONAL: uses the recovered std::string operation; template helper code generation differs from the executable.
// @0x14160a650
size_t FUN_14160a650(const std::string* text, const std::string* chars, size_t start)
{
    return text->find_first_not_of(*chars, start);
}

// MS2-FUNCTIONAL: uses the recovered std::string operation; template helper code generation differs from the executable.
// @0x14160a6f0
size_t FUN_14160a6f0(const std::string* text, const std::string* chars, size_t start)
{
    return text->find_first_of(*chars, start);
}

// @0x14160a790
void* FUN_14160a790(void* tree, void* result, const unsigned char* key)
{
    FUN_1415e5cf0(result, FUN_1415dbdb0(tree, *key), FUN_1415e1750(FUN_141600e10(tree)));
    return result;
}
