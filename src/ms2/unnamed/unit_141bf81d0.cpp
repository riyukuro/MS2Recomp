// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). A small intrusive-list helper pair: the link pointer is the
// node's own first member, so advancing is "replace the node pointer by its tail" and the other overload hands out the
// old node before advancing.
// MS2-UNIT: unit_141bf81d0
// MS2-RANGE: 0x141bf81d0-0x141bf8240 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

// Unrecovered node: only its first member (the link) is touched here.
struct Unk_LinkNode
{
    Unk_LinkNode* m_pNext;              // +0x00
};

// @0x141bf8220
Unk_LinkNode** FUN_141bf8220(Unk_LinkNode** ppNode)
{
    *ppNode = (*ppNode)->m_pNext;
    return ppNode;
}

// @0x141bf81d0
Unk_LinkNode** PostIncrement(Unk_LinkNode** ppNode, Unk_LinkNode** ppNodeOld, int nUnknown)
{
    Unk_LinkNode* pNode = *ppNode;
    FUN_141bf8220(ppNode);
    *ppNodeOld = pNode;
    return ppNodeOld;
}
