// unk_nodeptr.h - NiNodePtr (efd::SmartPointer<NiNode>), the game's 8-byte smart pointer to a scene-graph node. NOT an
// original header. Its operators are out of line in the exe: ctor 0x1409f7170, copy 0x1409f7130, dtor 0x1409f74b0,
// operator NiNode* 0x1409475d0, operator-> 0x1409475f0, operator== 0x1409f77a0 (operator= 0x140aac240 and
// operator!= 0x140aac3e0 are randomtargeteffect's COMDATs). Reset(p) is the SDK operator=(NiNode*) (0x1409f76f0).
#pragma once

#include <NiNode.h>

void FUN_1405a93d0(void* p);            // NiRefObject::DecRefCount
void FUN_140980460(void* p);            // NiRefObject::IncRefCount
