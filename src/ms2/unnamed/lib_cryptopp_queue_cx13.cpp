// Executable-derived copy constructor for Crypto++'s queue storage object.
// MS2-UNIT: lib_cryptopp_queue_cx13
// MS2-RANGE: 0x142351e00-0x142351e6e .text$mn
// MS2-FLAGS: gamebryo
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

#include <cstddef>
#include <cstdint>
#include <cstring>

#include "cryptopp562/secblock.h"

// queue.cpp's ByteQueueNode (defined in the .cpp, not a header): the members as the real class has them
struct CppByteQueueNode
{
    CppByteQueueNode* next;
    CryptoPP::SecByteBlock buf;
    std::size_t m_head, m_tail;
};

// ByteQueueNode's implicit copy constructor (ByteQueue::CopyFrom's `new ByteQueueNode(*current)`), out of line in the
// exe; the SecBlock copy ctor (allocate + memcpy_s) is inlined into it
// @0x142351e00
CppByteQueueNode* FUN_142351e00(CppByteQueueNode* destination, const CppByteQueueNode* source)
{
    destination->CppByteQueueNode::CppByteQueueNode(*source);
    return destination;
}
