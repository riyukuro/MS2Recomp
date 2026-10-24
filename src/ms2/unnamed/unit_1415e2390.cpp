// Nexon Messenger STL construction glue recovered from the decompilation.
// MS2-UNIT: unit_1415e2390
// MS2-RANGE: 0x1415e2390-0x1415e5c20 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/unnamed/unk_stlglue.h"
#include <cstring>
#include <new>
#include <string>

extern void* FUN_140159860(unsigned __int64 n, void* p);
extern void FUN_1415f9a90(void* p, const char* value);
extern void FUN_1415f9b80(void* p, const char* value);
extern void FUN_1415f93d0(void* p, unsigned int flags);

// MS2-FUNCTIONAL: reproduces the allocator-traits construction operation recovered at 0x1415e2430.
// @0x1415e2430
void FUN_1415e2430(void*, Unk_StlElem<0x10>* p, Unk_StlElem<0x10>* pVal)
{
    std::memcpy(p, pVal, 0x10);
}
// MS2-PIN: ?FUN_1415e2430@@YAXPEAXPEAU?$Unk_StlElem@$0BA@@@1@Z 0x1415e2430

// MS2-FUNCTIONAL: reproduces the allocator-traits construction operation recovered at 0x1415e2480.
// @0x1415e2480
void FUN_1415e2480(void*, Unk_StlElem<0x18>* p, Unk_StlElem<0x18>* pVal)
{
    std::memcpy(p, pVal, 0x18);
}
// MS2-PIN: ?FUN_1415e2480@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@1@Z 0x1415e2480

// MS2-FUNCTIONAL: reproduces the allocator-traits construction operation recovered at 0x1415e24d0.
// @0x1415e24d0
void FUN_1415e24d0(void*, Unk_StlElem<0x20>* p, Unk_StlElem<0x20>* pVal)
{
    ::new (p) std::string(*reinterpret_cast<const std::string*>(pVal));
}
// MS2-PIN: ?FUN_1415e24d0@@YAXPEAXPEAU?$Unk_StlElem@$0CA@@@1@Z 0x1415e24d0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMCateFriendInfo's copy constructor.
// @0x1415e2520
void FUN_1415e2520(void*, Unk_StlElem<0x58>* p, Unk_StlElem<0x58>* pVal)
{
    auto* pObject = static_cast<CNMCateFriendInfo*>(FUN_140159860(0x58, p));
    ::new (pObject) CNMCateFriendInfo(*reinterpret_cast<const CNMCateFriendInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e2520@@YAXPEAXPEAU?$Unk_StlElem@$0FI@@@1@Z 0x1415e2520

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMCateFriendInfo's copy constructor.
// @0x1415e2570
void FUN_1415e2570(void*, Unk_StlElem<0x58>* p, Unk_StlElem<0x58>* pVal)
{
    auto* pObject = static_cast<CNMCateFriendInfo*>(FUN_140159860(0x58, p));
    ::new (pObject) CNMCateFriendInfo(*reinterpret_cast<const CNMCateFriendInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e2570@@YAXPEAXPEAU?$Unk_StlElem@$0FI@@@1@Z 0x1415e2570

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMCateFriendInfo's copy constructor.
// @0x1415e25c0
void FUN_1415e25c0(void*, Unk_StlElem<0x58>* p, Unk_StlElem<0x58>* pVal)
{
    auto* pObject = static_cast<CNMCateFriendInfo*>(FUN_140159860(0x58, p));
    ::new (pObject) CNMCateFriendInfo(*reinterpret_cast<const CNMCateFriendInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e25c0@@YAXPEAXPEAU?$Unk_StlElem@$0FI@@@1@Z 0x1415e25c0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMChannelMemberInfo's copy constructor.
// @0x1415e2610
void FUN_1415e2610(void*, Unk_StlElem<0x30>* p, Unk_StlElem<0x30>* pVal)
{
    auto* pObject = static_cast<CNMChannelMemberInfo*>(FUN_140159860(0x30, p));
    ::new (pObject) CNMChannelMemberInfo(*reinterpret_cast<const CNMChannelMemberInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e2610@@YAXPEAXPEAU?$Unk_StlElem@$0DA@@@1@Z 0x1415e2610

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMChannelMemberInfo's copy constructor.
// @0x1415e2660
void FUN_1415e2660(void*, Unk_StlElem<0x30>* p, Unk_StlElem<0x30>* pVal)
{
    auto* pObject = static_cast<CNMChannelMemberInfo*>(FUN_140159860(0x30, p));
    ::new (pObject) CNMChannelMemberInfo(*reinterpret_cast<const CNMChannelMemberInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e2660@@YAXPEAXPEAU?$Unk_StlElem@$0DA@@@1@Z 0x1415e2660

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMChannelMemberInfo's copy constructor.
// @0x1415e26b0
void FUN_1415e26b0(void*, Unk_StlElem<0x30>* p, Unk_StlElem<0x30>* pVal)
{
    auto* pObject = static_cast<CNMChannelMemberInfo*>(FUN_140159860(0x30, p));
    ::new (pObject) CNMChannelMemberInfo(*reinterpret_cast<const CNMChannelMemberInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e26b0@@YAXPEAXPEAU?$Unk_StlElem@$0DA@@@1@Z 0x1415e26b0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMCharacter's copy constructor.
// @0x1415e2700
void FUN_1415e2700(void*, Unk_StlElem<0x98>* p, Unk_StlElem<0x98>* pVal)
{
    auto* pObject = static_cast<CNMCharacter*>(FUN_140159860(0x98, p));
    ::new (pObject) CNMCharacter(*reinterpret_cast<const CNMCharacter*>(pVal));
}
// MS2-PIN: ?FUN_1415e2700@@YAXPEAXPEAU?$Unk_StlElem@$0JI@@@1@Z 0x1415e2700

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMCharacter's copy constructor.
// @0x1415e2750
void FUN_1415e2750(void*, Unk_StlElem<0x98>* p, Unk_StlElem<0x98>* pVal)
{
    auto* pObject = static_cast<CNMCharacter*>(FUN_140159860(0x98, p));
    ::new (pObject) CNMCharacter(*reinterpret_cast<const CNMCharacter*>(pVal));
}
// MS2-PIN: ?FUN_1415e2750@@YAXPEAXPEAU?$Unk_StlElem@$0JI@@@1@Z 0x1415e2750

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMCharacter's copy constructor.
// @0x1415e27a0
void FUN_1415e27a0(void*, Unk_StlElem<0x98>* p, Unk_StlElem<0x98>* pVal)
{
    auto* pObject = static_cast<CNMCharacter*>(FUN_140159860(0x98, p));
    ::new (pObject) CNMCharacter(*reinterpret_cast<const CNMCharacter*>(pVal));
}
// MS2-PIN: ?FUN_1415e27a0@@YAXPEAXPEAU?$Unk_StlElem@$0JI@@@1@Z 0x1415e27a0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMChatRoomMemberInfo's copy constructor.
// @0x1415e27f0
void FUN_1415e27f0(void*, Unk_StlElem<0x220>* p, Unk_StlElem<0x220>* pVal)
{
    auto* pObject = static_cast<CNMChatRoomMemberInfo*>(FUN_140159860(0x220, p));
    ::new (pObject) CNMChatRoomMemberInfo(*reinterpret_cast<const CNMChatRoomMemberInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e27f0@@YAXPEAXPEAU?$Unk_StlElem@$0CCA@@@1@Z 0x1415e27f0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMChatRoomMemberInfo's copy constructor.
// @0x1415e2840
void FUN_1415e2840(void*, Unk_StlElem<0x220>* p, Unk_StlElem<0x220>* pVal)
{
    auto* pObject = static_cast<CNMChatRoomMemberInfo*>(FUN_140159860(0x220, p));
    ::new (pObject) CNMChatRoomMemberInfo(*reinterpret_cast<const CNMChatRoomMemberInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e2840@@YAXPEAXPEAU?$Unk_StlElem@$0CCA@@@1@Z 0x1415e2840

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMChatRoomMemberInfo's copy constructor.
// @0x1415e2890
void FUN_1415e2890(void*, Unk_StlElem<0x220>* p, Unk_StlElem<0x220>* pVal)
{
    auto* pObject = static_cast<CNMChatRoomMemberInfo*>(FUN_140159860(0x220, p));
    ::new (pObject) CNMChatRoomMemberInfo(*reinterpret_cast<const CNMChatRoomMemberInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e2890@@YAXPEAXPEAU?$Unk_StlElem@$0CCA@@@1@Z 0x1415e2890

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMFileEvent's copy constructor.
// @0x1415e28e0
void FUN_1415e28e0(void*, Unk_StlElem<0x128>* p, Unk_StlElem<0x128>* pVal)
{
    auto* pObject = static_cast<CNMFileEvent*>(FUN_140159860(0x128, p));
    ::new (pObject) CNMFileEvent(*reinterpret_cast<const CNMFileEvent*>(pVal));
}
// MS2-PIN: ?FUN_1415e28e0@@YAXPEAXPEAU?$Unk_StlElem@$0BCI@@@1@Z 0x1415e28e0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMFileEvent's copy constructor.
// @0x1415e2930
void FUN_1415e2930(void*, Unk_StlElem<0x128>* p, Unk_StlElem<0x128>* pVal)
{
    auto* pObject = static_cast<CNMFileEvent*>(FUN_140159860(0x128, p));
    ::new (pObject) CNMFileEvent(*reinterpret_cast<const CNMFileEvent*>(pVal));
}
// MS2-PIN: ?FUN_1415e2930@@YAXPEAXPEAU?$Unk_StlElem@$0BCI@@@1@Z 0x1415e2930

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMFileEvent's copy constructor.
// @0x1415e2980
void FUN_1415e2980(void*, Unk_StlElem<0x128>* p, Unk_StlElem<0x128>* pVal)
{
    auto* pObject = static_cast<CNMFileEvent*>(FUN_140159860(0x128, p));
    ::new (pObject) CNMFileEvent(*reinterpret_cast<const CNMFileEvent*>(pVal));
}
// MS2-PIN: ?FUN_1415e2980@@YAXPEAXPEAU?$Unk_StlElem@$0BCI@@@1@Z 0x1415e2980

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMFilePath's copy constructor.
// @0x1415e29d0
void FUN_1415e29d0(void*, Unk_StlElem<0x118>* p, Unk_StlElem<0x118>* pVal)
{
    auto* pObject = static_cast<CNMFilePath*>(FUN_140159860(0x118, p));
    ::new (pObject) CNMFilePath(*reinterpret_cast<const CNMFilePath*>(pVal));
}
// MS2-PIN: ?FUN_1415e29d0@@YAXPEAXPEAU?$Unk_StlElem@$0BBI@@@1@Z 0x1415e29d0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMFilePath's copy constructor.
// @0x1415e2a20
void FUN_1415e2a20(void*, Unk_StlElem<0x118>* p, Unk_StlElem<0x118>* pVal)
{
    auto* pObject = static_cast<CNMFilePath*>(FUN_140159860(0x118, p));
    ::new (pObject) CNMFilePath(*reinterpret_cast<const CNMFilePath*>(pVal));
}
// MS2-PIN: ?FUN_1415e2a20@@YAXPEAXPEAU?$Unk_StlElem@$0BBI@@@1@Z 0x1415e2a20

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMFilePath's copy constructor.
// @0x1415e2a70
void FUN_1415e2a70(void*, Unk_StlElem<0x118>* p, Unk_StlElem<0x118>* pVal)
{
    auto* pObject = static_cast<CNMFilePath*>(FUN_140159860(0x118, p));
    ::new (pObject) CNMFilePath(*reinterpret_cast<const CNMFilePath*>(pVal));
}
// MS2-PIN: ?FUN_1415e2a70@@YAXPEAXPEAU?$Unk_StlElem@$0BBI@@@1@Z 0x1415e2a70

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMFindUserInfo's copy constructor.
// @0x1415e2ac0
void FUN_1415e2ac0(void*, Unk_StlElem<0xe0>* p, Unk_StlElem<0xe0>* pVal)
{
    auto* pObject = static_cast<CNMFindUserInfo*>(FUN_140159860(0xe0, p));
    ::new (pObject) CNMFindUserInfo(*reinterpret_cast<const CNMFindUserInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e2ac0@@YAXPEAXPEAU?$Unk_StlElem@$0OA@@@1@Z 0x1415e2ac0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMFindUserInfo's copy constructor.
// @0x1415e2b10
void FUN_1415e2b10(void*, Unk_StlElem<0xe0>* p, Unk_StlElem<0xe0>* pVal)
{
    auto* pObject = static_cast<CNMFindUserInfo*>(FUN_140159860(0xe0, p));
    ::new (pObject) CNMFindUserInfo(*reinterpret_cast<const CNMFindUserInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e2b10@@YAXPEAXPEAU?$Unk_StlElem@$0OA@@@1@Z 0x1415e2b10

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMFriendInfo's copy constructor.
// @0x1415e2b60
void FUN_1415e2b60(void*, Unk_StlElem<0x580>* p, Unk_StlElem<0x580>* pVal)
{
    auto* pObject = static_cast<CNMFriendInfo*>(FUN_140159860(0x580, p));
    ::new (pObject) CNMFriendInfo(*reinterpret_cast<const CNMFriendInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e2b60@@YAXPEAXPEAU?$Unk_StlElem@$0FIA@@@1@Z 0x1415e2b60

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMFriendInfo's copy constructor.
// @0x1415e2bb0
void FUN_1415e2bb0(void*, Unk_StlElem<0x580>* p, Unk_StlElem<0x580>* pVal)
{
    auto* pObject = static_cast<CNMFriendInfo*>(FUN_140159860(0x580, p));
    ::new (pObject) CNMFriendInfo(*reinterpret_cast<const CNMFriendInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e2bb0@@YAXPEAXPEAU?$Unk_StlElem@$0FIA@@@1@Z 0x1415e2bb0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMFriendInfo's copy constructor.
// @0x1415e2c00
void FUN_1415e2c00(void*, Unk_StlElem<0x580>* p, Unk_StlElem<0x580>* pVal)
{
    auto* pObject = static_cast<CNMFriendInfo*>(FUN_140159860(0x580, p));
    ::new (pObject) CNMFriendInfo(*reinterpret_cast<const CNMFriendInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e2c00@@YAXPEAXPEAU?$Unk_StlElem@$0FIA@@@1@Z 0x1415e2c00

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMGameCode's copy constructor.
// @0x1415e2c50
void FUN_1415e2c50(void*, Unk_StlElem<0x18>* p, Unk_StlElem<0x18>* pVal)
{
    auto* pObject = static_cast<CNMGameCode*>(FUN_140159860(0x18, p));
    ::new (pObject) CNMGameCode(*reinterpret_cast<const CNMGameCode*>(pVal));
}
// MS2-PIN: ?FUN_1415e2c50@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@1@Z 0x1415e2c50

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMGameCode's copy constructor.
// @0x1415e2ca0
void FUN_1415e2ca0(void*, Unk_StlElem<0x18>* p, Unk_StlElem<0x18>* pVal)
{
    auto* pObject = static_cast<CNMGameCode*>(FUN_140159860(0x18, p));
    ::new (pObject) CNMGameCode(*reinterpret_cast<const CNMGameCode*>(pVal));
}
// MS2-PIN: ?FUN_1415e2ca0@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@1@Z 0x1415e2ca0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMGameCode's copy constructor.
// @0x1415e2cf0
void FUN_1415e2cf0(void*, Unk_StlElem<0x18>* p, Unk_StlElem<0x18>* pVal)
{
    auto* pObject = static_cast<CNMGameCode*>(FUN_140159860(0x18, p));
    ::new (pObject) CNMGameCode(*reinterpret_cast<const CNMGameCode*>(pVal));
}
// MS2-PIN: ?FUN_1415e2cf0@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@1@Z 0x1415e2cf0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMGameInfo's copy constructor.
// @0x1415e2d40
void FUN_1415e2d40(void*, Unk_StlElem<0x14a8>* p, Unk_StlElem<0x14a8>* pVal)
{
    auto* pObject = static_cast<CNMGameInfo*>(FUN_140159860(0x14a8, p));
    ::new (pObject) CNMGameInfo(*reinterpret_cast<const CNMGameInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e2d40@@YAXPEAXPEAU?$Unk_StlElem@$0BEKI@@@1@Z 0x1415e2d40

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMGameInfo's copy constructor.
// @0x1415e2d90
void FUN_1415e2d90(void*, Unk_StlElem<0x14a8>* p, Unk_StlElem<0x14a8>* pVal)
{
    auto* pObject = static_cast<CNMGameInfo*>(FUN_140159860(0x14a8, p));
    ::new (pObject) CNMGameInfo(*reinterpret_cast<const CNMGameInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e2d90@@YAXPEAXPEAU?$Unk_StlElem@$0BEKI@@@1@Z 0x1415e2d90

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMGameInfo's copy constructor.
// @0x1415e2de0
void FUN_1415e2de0(void*, Unk_StlElem<0x14a8>* p, Unk_StlElem<0x14a8>* pVal)
{
    auto* pObject = static_cast<CNMGameInfo*>(FUN_140159860(0x14a8, p));
    ::new (pObject) CNMGameInfo(*reinterpret_cast<const CNMGameInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e2de0@@YAXPEAXPEAU?$Unk_StlElem@$0BEKI@@@1@Z 0x1415e2de0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMGameServerCode's copy constructor.
// @0x1415e2e30
void FUN_1415e2e30(void*, Unk_StlElem<0x18>* p, Unk_StlElem<0x18>* pVal)
{
    auto* pObject = static_cast<CNMGameServerCode*>(FUN_140159860(0x18, p));
    ::new (pObject) CNMGameServerCode(*reinterpret_cast<const CNMGameServerCode*>(pVal));
}
// MS2-PIN: ?FUN_1415e2e30@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@1@Z 0x1415e2e30

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMGameServerCode's copy constructor.
// @0x1415e2e80
void FUN_1415e2e80(void*, Unk_StlElem<0x18>* p, Unk_StlElem<0x18>* pVal)
{
    auto* pObject = static_cast<CNMGameServerCode*>(FUN_140159860(0x18, p));
    ::new (pObject) CNMGameServerCode(*reinterpret_cast<const CNMGameServerCode*>(pVal));
}
// MS2-PIN: ?FUN_1415e2e80@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@1@Z 0x1415e2e80

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMGameServerCode's copy constructor.
// @0x1415e2ed0
void FUN_1415e2ed0(void*, Unk_StlElem<0x18>* p, Unk_StlElem<0x18>* pVal)
{
    auto* pObject = static_cast<CNMGameServerCode*>(FUN_140159860(0x18, p));
    ::new (pObject) CNMGameServerCode(*reinterpret_cast<const CNMGameServerCode*>(pVal));
}
// MS2-PIN: ?FUN_1415e2ed0@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@1@Z 0x1415e2ed0

// MS2-FUNCTIONAL: reconstructs the recovered request-info allocator copy constructor.
// @0x1415e2f20
void FUN_1415e2f20(void*, Unk_StlElem<0x20>* p, Unk_StlElem<0x20>* pVal)
{
    auto* pObject = static_cast<CNMSetServerInfoFunc::RequestInfo*>(FUN_140159860(0x20, p));
    ::new (pObject) CNMSetServerInfoFunc::RequestInfo(*reinterpret_cast<const CNMSetServerInfoFunc::RequestInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e2f20@@YAXPEAXPEAU?$Unk_StlElem@$0BJA@@@1@Z 0x1415e2f20

// MS2-FUNCTIONAL: reconstructs the recovered request-info allocator copy constructor.
// @0x1415e2f70
void FUN_1415e2f70(void*, Unk_StlElem<0x20>* p, Unk_StlElem<0x20>* pVal)
{
    auto* pObject = static_cast<CNMSetServerInfoFunc::RequestInfo*>(FUN_140159860(0x20, p));
    ::new (pObject) CNMSetServerInfoFunc::RequestInfo(*reinterpret_cast<const CNMSetServerInfoFunc::RequestInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e2f70@@YAXPEAXPEAU?$Unk_StlElem@$0BJA@@@1@Z 0x1415e2f70

// MS2-FUNCTIONAL: reconstructs the recovered request-info allocator copy constructor.
// @0x1415e2fc0
void FUN_1415e2fc0(void*, Unk_StlElem<0x20>* p, Unk_StlElem<0x20>* pVal)
{
    auto* pObject = static_cast<CNMSetServerInfoFunc::RequestInfo*>(FUN_140159860(0x20, p));
    ::new (pObject) CNMSetServerInfoFunc::RequestInfo(*reinterpret_cast<const CNMSetServerInfoFunc::RequestInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e2fc0@@YAXPEAXPEAU?$Unk_StlElem@$0BJA@@@1@Z 0x1415e2fc0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMGuildMemberInfo's copy constructor.
// @0x1415e3010
void FUN_1415e3010(void*, Unk_StlElem<0xb8>* p, Unk_StlElem<0xb8>* pVal)
{
    auto* pObject = static_cast<CNMGuildMemberInfo*>(FUN_140159860(0xb8, p));
    ::new (pObject) CNMGuildMemberInfo(*reinterpret_cast<const CNMGuildMemberInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e3010@@YAXPEAXPEAU?$Unk_StlElem@$0LI@@@1@Z 0x1415e3010

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMGuildMemberInfo's copy constructor.
// @0x1415e3060
void FUN_1415e3060(void*, Unk_StlElem<0xb8>* p, Unk_StlElem<0xb8>* pVal)
{
    auto* pObject = static_cast<CNMGuildMemberInfo*>(FUN_140159860(0xb8, p));
    ::new (pObject) CNMGuildMemberInfo(*reinterpret_cast<const CNMGuildMemberInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e3060@@YAXPEAXPEAU?$Unk_StlElem@$0LI@@@1@Z 0x1415e3060

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMGuildMemberInfo's copy constructor.
// @0x1415e30b0
void FUN_1415e30b0(void*, Unk_StlElem<0xb8>* p, Unk_StlElem<0xb8>* pVal)
{
    auto* pObject = static_cast<CNMGuildMemberInfo*>(FUN_140159860(0xb8, p));
    ::new (pObject) CNMGuildMemberInfo(*reinterpret_cast<const CNMGuildMemberInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e30b0@@YAXPEAXPEAU?$Unk_StlElem@$0LI@@@1@Z 0x1415e30b0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMGuildMemberInfo's copy constructor.
// @0x1415e3100
void FUN_1415e3100(void*, Unk_StlElem<0xb8>* p, Unk_StlElem<0xb8>* pVal)
{
    auto* pObject = static_cast<CNMGuildMemberInfo*>(FUN_140159860(0xb8, p));
    ::new (pObject) CNMGuildMemberInfo(*reinterpret_cast<const CNMGuildMemberInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e3100@@YAXPEAXPEAU?$Unk_StlElem@$0LI@@@1@Z 0x1415e3100

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMGuildMemberLevelInfo's copy constructor.
// @0x1415e3150
void FUN_1415e3150(void*, Unk_StlElem<0x58>* p, Unk_StlElem<0x58>* pVal)
{
    auto* pObject = static_cast<CNMGuildMemberLevelInfo*>(FUN_140159860(0x58, p));
    ::new (pObject) CNMGuildMemberLevelInfo(*reinterpret_cast<const CNMGuildMemberLevelInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e3150@@YAXPEAXPEAU?$Unk_StlElem@$0FI@@@1@Z 0x1415e3150

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMGuildMemberLevelInfo's copy constructor.
// @0x1415e31a0
void FUN_1415e31a0(void*, Unk_StlElem<0x58>* p, Unk_StlElem<0x58>* pVal)
{
    auto* pObject = static_cast<CNMGuildMemberLevelInfo*>(FUN_140159860(0x58, p));
    ::new (pObject) CNMGuildMemberLevelInfo(*reinterpret_cast<const CNMGuildMemberLevelInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e31a0@@YAXPEAXPEAU?$Unk_StlElem@$0FI@@@1@Z 0x1415e31a0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMGuildMemberLevelInfo's copy constructor.
// @0x1415e31f0
void FUN_1415e31f0(void*, Unk_StlElem<0x58>* p, Unk_StlElem<0x58>* pVal)
{
    auto* pObject = static_cast<CNMGuildMemberLevelInfo*>(FUN_140159860(0x58, p));
    ::new (pObject) CNMGuildMemberLevelInfo(*reinterpret_cast<const CNMGuildMemberLevelInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e31f0@@YAXPEAXPEAU?$Unk_StlElem@$0FI@@@1@Z 0x1415e31f0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMGuildOnlineInfoEx's copy constructor.
// @0x1415e3240
void FUN_1415e3240(void*, Unk_StlElem<0x68>* p, Unk_StlElem<0x68>* pVal)
{
    auto* pObject = static_cast<CNMGuildOnlineInfoEx*>(FUN_140159860(0x68, p));
    ::new (pObject) CNMGuildOnlineInfoEx(*reinterpret_cast<const CNMGuildOnlineInfoEx*>(pVal));
}
// MS2-PIN: ?FUN_1415e3240@@YAXPEAXPEAU?$Unk_StlElem@$0GI@@@1@Z 0x1415e3240

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMGuildOnlineInfoEx's copy constructor.
// @0x1415e3290
void FUN_1415e3290(void*, Unk_StlElem<0x68>* p, Unk_StlElem<0x68>* pVal)
{
    auto* pObject = static_cast<CNMGuildOnlineInfoEx*>(FUN_140159860(0x68, p));
    ::new (pObject) CNMGuildOnlineInfoEx(*reinterpret_cast<const CNMGuildOnlineInfoEx*>(pVal));
}
// MS2-PIN: ?FUN_1415e3290@@YAXPEAXPEAU?$Unk_StlElem@$0GI@@@1@Z 0x1415e3290

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMNoteInfo2's copy constructor.
// @0x1415e32e0
void FUN_1415e32e0(void*, Unk_StlElem<0xae8>* p, Unk_StlElem<0xae8>* pVal)
{
    auto* pObject = static_cast<CNMNoteInfo2*>(FUN_140159860(0xae8, p));
    ::new (pObject) CNMNoteInfo2(*reinterpret_cast<const CNMNoteInfo2*>(pVal));
}
// MS2-PIN: ?FUN_1415e32e0@@YAXPEAXPEAU?$Unk_StlElem@$0KOI@@@1@Z 0x1415e32e0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMNoteInfo2's copy constructor.
// @0x1415e3330
void FUN_1415e3330(void*, Unk_StlElem<0xae8>* p, Unk_StlElem<0xae8>* pVal)
{
    auto* pObject = static_cast<CNMNoteInfo2*>(FUN_140159860(0xae8, p));
    ::new (pObject) CNMNoteInfo2(*reinterpret_cast<const CNMNoteInfo2*>(pVal));
}
// MS2-PIN: ?FUN_1415e3330@@YAXPEAXPEAU?$Unk_StlElem@$0KOI@@@1@Z 0x1415e3330

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMNoteInfo2's copy constructor.
// @0x1415e3380
void FUN_1415e3380(void*, Unk_StlElem<0xae8>* p, Unk_StlElem<0xae8>* pVal)
{
    auto* pObject = static_cast<CNMNoteInfo2*>(FUN_140159860(0xae8, p));
    ::new (pObject) CNMNoteInfo2(*reinterpret_cast<const CNMNoteInfo2*>(pVal));
}
// MS2-PIN: ?FUN_1415e3380@@YAXPEAXPEAU?$Unk_StlElem@$0KOI@@@1@Z 0x1415e3380

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMNoteInfo's copy constructor.
// @0x1415e33d0
void FUN_1415e33d0(void*, Unk_StlElem<0xec8>* p, Unk_StlElem<0xec8>* pVal)
{
    auto* pObject = static_cast<CNMNoteInfo*>(FUN_140159860(0xec8, p));
    ::new (pObject) CNMNoteInfo(*reinterpret_cast<const CNMNoteInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e33d0@@YAXPEAXPEAU?$Unk_StlElem@$0OMI@@@1@Z 0x1415e33d0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMNoteInfo's copy constructor.
// @0x1415e3420
void FUN_1415e3420(void*, Unk_StlElem<0xec8>* p, Unk_StlElem<0xec8>* pVal)
{
    auto* pObject = static_cast<CNMNoteInfo*>(FUN_140159860(0xec8, p));
    ::new (pObject) CNMNoteInfo(*reinterpret_cast<const CNMNoteInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e3420@@YAXPEAXPEAU?$Unk_StlElem@$0OMI@@@1@Z 0x1415e3420

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMNoteInfo's copy constructor.
// @0x1415e3470
void FUN_1415e3470(void*, Unk_StlElem<0xec8>* p, Unk_StlElem<0xec8>* pVal)
{
    auto* pObject = static_cast<CNMNoteInfo*>(FUN_140159860(0xec8, p));
    ::new (pObject) CNMNoteInfo(*reinterpret_cast<const CNMNoteInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e3470@@YAXPEAXPEAU?$Unk_StlElem@$0OMI@@@1@Z 0x1415e3470

// MS2-FUNCTIONAL: reconstructs the recovered request-info allocator copy constructor.
// @0x1415e34c0
void FUN_1415e34c0(void*, Unk_StlElem<0x20>* p, Unk_StlElem<0x20>* pVal)
{
    auto* pObject = static_cast<CNMSetServerInfoFunc::RequestInfo*>(FUN_140159860(0x20, p));
    ::new (pObject) CNMSetServerInfoFunc::RequestInfo(*reinterpret_cast<const CNMSetServerInfoFunc::RequestInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e34c0@@YAXPEAXPEAU?$Unk_StlElem@$0MI@@@1@Z 0x1415e34c0

// MS2-FUNCTIONAL: reconstructs the recovered request-info allocator copy constructor.
// @0x1415e3510
void FUN_1415e3510(void*, Unk_StlElem<0x20>* p, Unk_StlElem<0x20>* pVal)
{
    auto* pObject = static_cast<CNMSetServerInfoFunc::RequestInfo*>(FUN_140159860(0x20, p));
    ::new (pObject) CNMSetServerInfoFunc::RequestInfo(*reinterpret_cast<const CNMSetServerInfoFunc::RequestInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e3510@@YAXPEAXPEAU?$Unk_StlElem@$0MI@@@1@Z 0x1415e3510

// MS2-FUNCTIONAL: reconstructs the recovered request-info allocator copy constructor.
// @0x1415e3560
void FUN_1415e3560(void*, Unk_StlElem<0x20>* p, Unk_StlElem<0x20>* pVal)
{
    auto* pObject = static_cast<CNMSetServerInfoFunc::RequestInfo*>(FUN_140159860(0x20, p));
    ::new (pObject) CNMSetServerInfoFunc::RequestInfo(*reinterpret_cast<const CNMSetServerInfoFunc::RequestInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e3560@@YAXPEAXPEAU?$Unk_StlElem@$0MI@@@1@Z 0x1415e3560

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMSessionMemberInfo's copy constructor.
// @0x1415e35b0
void FUN_1415e35b0(void*, Unk_StlElem<0xf8>* p, Unk_StlElem<0xf8>* pVal)
{
    auto* pObject = static_cast<CNMSessionMemberInfo*>(FUN_140159860(0xf8, p));
    ::new (pObject) CNMSessionMemberInfo(*reinterpret_cast<const CNMSessionMemberInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e35b0@@YAXPEAXPEAU?$Unk_StlElem@$0PI@@@1@Z 0x1415e35b0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMSessionMemberInfo's copy constructor.
// @0x1415e3600
void FUN_1415e3600(void*, Unk_StlElem<0xf8>* p, Unk_StlElem<0xf8>* pVal)
{
    auto* pObject = static_cast<CNMSessionMemberInfo*>(FUN_140159860(0xf8, p));
    ::new (pObject) CNMSessionMemberInfo(*reinterpret_cast<const CNMSessionMemberInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e3600@@YAXPEAXPEAU?$Unk_StlElem@$0PI@@@1@Z 0x1415e3600

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMSessionMemberInfo's copy constructor.
// @0x1415e3650
void FUN_1415e3650(void*, Unk_StlElem<0xf8>* p, Unk_StlElem<0xf8>* pVal)
{
    auto* pObject = static_cast<CNMSessionMemberInfo*>(FUN_140159860(0xf8, p));
    ::new (pObject) CNMSessionMemberInfo(*reinterpret_cast<const CNMSessionMemberInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e3650@@YAXPEAXPEAU?$Unk_StlElem@$0PI@@@1@Z 0x1415e3650

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMVirtualUserInfo's copy constructor.
// @0x1415e36a0
void FUN_1415e36a0(void*, Unk_StlElem<0x490>* p, Unk_StlElem<0x490>* pVal)
{
    auto* pObject = static_cast<CNMVirtualUserInfo*>(FUN_140159860(0x490, p));
    ::new (pObject) CNMVirtualUserInfo(*reinterpret_cast<const CNMVirtualUserInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e36a0@@YAXPEAXPEAU?$Unk_StlElem@$0EJA@@@1@Z 0x1415e36a0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMVirtualUserInfo's copy constructor.
// @0x1415e36f0
void FUN_1415e36f0(void*, Unk_StlElem<0x490>* p, Unk_StlElem<0x490>* pVal)
{
    auto* pObject = static_cast<CNMVirtualUserInfo*>(FUN_140159860(0x490, p));
    ::new (pObject) CNMVirtualUserInfo(*reinterpret_cast<const CNMVirtualUserInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e36f0@@YAXPEAXPEAU?$Unk_StlElem@$0EJA@@@1@Z 0x1415e36f0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMVirtualUserInfo's copy constructor.
// @0x1415e3740
void FUN_1415e3740(void*, Unk_StlElem<0x490>* p, Unk_StlElem<0x490>* pVal)
{
    auto* pObject = static_cast<CNMVirtualUserInfo*>(FUN_140159860(0x490, p));
    ::new (pObject) CNMVirtualUserInfo(*reinterpret_cast<const CNMVirtualUserInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e3740@@YAXPEAXPEAU?$Unk_StlElem@$0EJA@@@1@Z 0x1415e3740

// MS2-FUNCTIONAL: reconstructs the recovered request-info allocator copy constructor.
// @0x1415e3790
void FUN_1415e3790(void*, Unk_StlElem<0x20>* p, Unk_StlElem<0x20>* pVal)
{
    auto* pObject = static_cast<CNMSetServerInfoFunc::RequestInfo*>(FUN_140159860(0x20, p));
    ::new (pObject) CNMSetServerInfoFunc::RequestInfo(*reinterpret_cast<const CNMSetServerInfoFunc::RequestInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e3790@@YAXPEAXPEAU?$Unk_StlElem@$0CA@@@1@Z 0x1415e3790

// MS2-FUNCTIONAL: reconstructs the recovered request-info allocator copy constructor.
// @0x1415e37e0
void FUN_1415e37e0(void*, Unk_StlElem<0x20>* p, Unk_StlElem<0x20>* pVal)
{
    auto* pObject = static_cast<CNMSetServerInfoFunc::RequestInfo*>(FUN_140159860(0x20, p));
    ::new (pObject) CNMSetServerInfoFunc::RequestInfo(*reinterpret_cast<const CNMSetServerInfoFunc::RequestInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e37e0@@YAXPEAXPEAU?$Unk_StlElem@$0CA@@@1@Z 0x1415e37e0

// MS2-FUNCTIONAL: reconstructs the recovered request-info allocator copy constructor.
// @0x1415e3830
void FUN_1415e3830(void*, Unk_StlElem<0x20>* p, Unk_StlElem<0x20>* pVal)
{
    auto* pObject = static_cast<CNMSetServerInfoFunc::RequestInfo*>(FUN_140159860(0x20, p));
    ::new (pObject) CNMSetServerInfoFunc::RequestInfo(*reinterpret_cast<const CNMSetServerInfoFunc::RequestInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e3830@@YAXPEAXPEAU?$Unk_StlElem@$0CA@@@1@Z 0x1415e3830

// MS2-FUNCTIONAL: dispatches the recovered scalar-deleting destructor through the element vtable.
// @0x1415e38a0
void FUN_1415e38a0(void*, Unk_StlElem<0x58>* p)
{
    auto** vftable = *reinterpret_cast<void***>(p);
    using Destroy = void(__fastcall*)(void*, unsigned int);
    reinterpret_cast<Destroy>(vftable[0])(p, 0);
}
// MS2-PIN: ?FUN_1415e38a0@@YAXPEAXPEAU?$Unk_StlElem@$0FI@@@@Z 0x1415e38a0

// MS2-FUNCTIONAL: dispatches the recovered scalar-deleting destructor through the element vtable.
// @0x1415e38d0
void FUN_1415e38d0(void*, Unk_StlElem<0x30>* p)
{
    auto** vftable = *reinterpret_cast<void***>(p);
    using Destroy = void(__fastcall*)(void*, unsigned int);
    reinterpret_cast<Destroy>(vftable[0])(p, 0);
}
// MS2-PIN: ?FUN_1415e38d0@@YAXPEAXPEAU?$Unk_StlElem@$0DA@@@@Z 0x1415e38d0

// MS2-FUNCTIONAL: dispatches the recovered scalar-deleting destructor through the element vtable.
// @0x1415e3900
void FUN_1415e3900(void*, Unk_StlElem<0x98>* p)
{
    auto** vftable = *reinterpret_cast<void***>(p);
    using Destroy = void(__fastcall*)(void*, unsigned int);
    reinterpret_cast<Destroy>(vftable[0])(p, 0);
}
// MS2-PIN: ?FUN_1415e3900@@YAXPEAXPEAU?$Unk_StlElem@$0JI@@@@Z 0x1415e3900

// MS2-FUNCTIONAL: dispatches the recovered scalar-deleting destructor through the element vtable.
// @0x1415e3930
void FUN_1415e3930(void*, Unk_StlElem<0x220>* p)
{
    auto** vftable = *reinterpret_cast<void***>(p);
    using Destroy = void(__fastcall*)(void*, unsigned int);
    reinterpret_cast<Destroy>(vftable[0])(p, 0);
}
// MS2-PIN: ?FUN_1415e3930@@YAXPEAXPEAU?$Unk_StlElem@$0CCA@@@@Z 0x1415e3930

// MS2-FUNCTIONAL: dispatches the recovered scalar-deleting destructor through the element vtable.
// @0x1415e3960
void FUN_1415e3960(void*, Unk_StlElem<0x128>* p)
{
    auto** vftable = *reinterpret_cast<void***>(p);
    using Destroy = void(__fastcall*)(void*, unsigned int);
    reinterpret_cast<Destroy>(vftable[0])(p, 0);
}
// MS2-PIN: ?FUN_1415e3960@@YAXPEAXPEAU?$Unk_StlElem@$0BCI@@@@Z 0x1415e3960

// MS2-FUNCTIONAL: dispatches the recovered scalar-deleting destructor through the element vtable.
// @0x1415e3990
void FUN_1415e3990(void*, Unk_StlElem<0x118>* p)
{
    auto** vftable = *reinterpret_cast<void***>(p);
    using Destroy = void(__fastcall*)(void*, unsigned int);
    reinterpret_cast<Destroy>(vftable[0])(p, 0);
}
// MS2-PIN: ?FUN_1415e3990@@YAXPEAXPEAU?$Unk_StlElem@$0BBI@@@@Z 0x1415e3990

// MS2-FUNCTIONAL: dispatches the recovered scalar-deleting destructor through the element vtable.
// @0x1415e39c0
void FUN_1415e39c0(void*, Unk_StlElem<0xe0>* p)
{
    auto** vftable = *reinterpret_cast<void***>(p);
    using Destroy = void(__fastcall*)(void*, unsigned int);
    reinterpret_cast<Destroy>(vftable[0])(p, 0);
}
// MS2-PIN: ?FUN_1415e39c0@@YAXPEAXPEAU?$Unk_StlElem@$0OA@@@@Z 0x1415e39c0

// MS2-FUNCTIONAL: dispatches the recovered scalar-deleting destructor through the element vtable.
// @0x1415e39f0
void FUN_1415e39f0(void*, Unk_StlElem<0x580>* p)
{
    auto** vftable = *reinterpret_cast<void***>(p);
    using Destroy = void(__fastcall*)(void*, unsigned int);
    reinterpret_cast<Destroy>(vftable[0])(p, 0);
}
// MS2-PIN: ?FUN_1415e39f0@@YAXPEAXPEAU?$Unk_StlElem@$0FIA@@@@Z 0x1415e39f0

// MS2-FUNCTIONAL: dispatches the recovered scalar-deleting destructor through the element vtable.
// @0x1415e3a20
void FUN_1415e3a20(void*, Unk_StlElem<0x18>* p)
{
    auto** vftable = *reinterpret_cast<void***>(p);
    using Destroy = void(__fastcall*)(void*, unsigned int);
    reinterpret_cast<Destroy>(vftable[0])(p, 0);
}
// MS2-PIN: ?FUN_1415e3a20@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@@Z 0x1415e3a20

// MS2-FUNCTIONAL: dispatches the recovered scalar-deleting destructor through the element vtable.
// @0x1415e3a50
void FUN_1415e3a50(void*, Unk_StlElem<0x14a8>* p)
{
    auto** vftable = *reinterpret_cast<void***>(p);
    using Destroy = void(__fastcall*)(void*, unsigned int);
    reinterpret_cast<Destroy>(vftable[0])(p, 0);
}
// MS2-PIN: ?FUN_1415e3a50@@YAXPEAXPEAU?$Unk_StlElem@$0BEKI@@@@Z 0x1415e3a50

// MS2-FUNCTIONAL: dispatches the recovered scalar-deleting destructor through the element vtable.
// @0x1415e3a80
void FUN_1415e3a80(void*, Unk_StlElem<0x18>* p)
{
    auto** vftable = *reinterpret_cast<void***>(p);
    using Destroy = void(__fastcall*)(void*, unsigned int);
    reinterpret_cast<Destroy>(vftable[0])(p, 0);
}
// MS2-PIN: ?FUN_1415e3a80@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@@Z 0x1415e3a80

// MS2-FUNCTIONAL: dispatches the recovered scalar-deleting destructor through the element vtable.
// @0x1415e3ab0
void FUN_1415e3ab0(void*, Unk_StlElem<0x190>* p)
{
    auto** vftable = *reinterpret_cast<void***>(p);
    using Destroy = void(__fastcall*)(void*, unsigned int);
    reinterpret_cast<Destroy>(vftable[0])(p, 0);
}
// MS2-PIN: ?FUN_1415e3ab0@@YAXPEAXPEAU?$Unk_StlElem@$0BJA@@@@Z 0x1415e3ab0

// MS2-FUNCTIONAL: dispatches the recovered scalar-deleting destructor through the element vtable.
// @0x1415e3ae0
void FUN_1415e3ae0(void*, Unk_StlElem<0xb8>* p)
{
    auto** vftable = *reinterpret_cast<void***>(p);
    using Destroy = void(__fastcall*)(void*, unsigned int);
    reinterpret_cast<Destroy>(vftable[0])(p, 0);
}
// MS2-PIN: ?FUN_1415e3ae0@@YAXPEAXPEAU?$Unk_StlElem@$0LI@@@@Z 0x1415e3ae0

// MS2-FUNCTIONAL: dispatches the recovered scalar-deleting destructor through the element vtable.
// @0x1415e3b10
void FUN_1415e3b10(void*, Unk_StlElem<0x58>* p)
{
    auto** vftable = *reinterpret_cast<void***>(p);
    using Destroy = void(__fastcall*)(void*, unsigned int);
    reinterpret_cast<Destroy>(vftable[0])(p, 0);
}
// MS2-PIN: ?FUN_1415e3b10@@YAXPEAXPEAU?$Unk_StlElem@$0FI@@@@Z 0x1415e3b10

// MS2-FUNCTIONAL: dispatches the recovered scalar-deleting destructor through the element vtable.
// @0x1415e3b40
void FUN_1415e3b40(void*, Unk_StlElem<0x68>* p)
{
    auto** vftable = *reinterpret_cast<void***>(p);
    using Destroy = void(__fastcall*)(void*, unsigned int);
    reinterpret_cast<Destroy>(vftable[0])(p, 0);
}
// MS2-PIN: ?FUN_1415e3b40@@YAXPEAXPEAU?$Unk_StlElem@$0GI@@@@Z 0x1415e3b40

// MS2-FUNCTIONAL: dispatches the recovered scalar-deleting destructor through the element vtable.
// @0x1415e3b70
void FUN_1415e3b70(void*, Unk_StlElem<0xae8>* p)
{
    auto** vftable = *reinterpret_cast<void***>(p);
    using Destroy = void(__fastcall*)(void*, unsigned int);
    reinterpret_cast<Destroy>(vftable[0])(p, 0);
}
// MS2-PIN: ?FUN_1415e3b70@@YAXPEAXPEAU?$Unk_StlElem@$0KOI@@@@Z 0x1415e3b70

// MS2-FUNCTIONAL: dispatches the recovered scalar-deleting destructor through the element vtable.
// @0x1415e3ba0
void FUN_1415e3ba0(void*, Unk_StlElem<0xec8>* p)
{
    auto** vftable = *reinterpret_cast<void***>(p);
    using Destroy = void(__fastcall*)(void*, unsigned int);
    reinterpret_cast<Destroy>(vftable[0])(p, 0);
}
// MS2-PIN: ?FUN_1415e3ba0@@YAXPEAXPEAU?$Unk_StlElem@$0OMI@@@@Z 0x1415e3ba0

// MS2-FUNCTIONAL: dispatches the recovered scalar-deleting destructor through the element vtable.
// @0x1415e3bd0
void FUN_1415e3bd0(void*, Unk_StlElem<0xc8>* p)
{
    auto** vftable = *reinterpret_cast<void***>(p);
    using Destroy = void(__fastcall*)(void*, unsigned int);
    reinterpret_cast<Destroy>(vftable[0])(p, 0);
}
// MS2-PIN: ?FUN_1415e3bd0@@YAXPEAXPEAU?$Unk_StlElem@$0MI@@@@Z 0x1415e3bd0

// MS2-FUNCTIONAL: dispatches the recovered scalar-deleting destructor through the element vtable.
// @0x1415e3c00
void FUN_1415e3c00(void*, Unk_StlElem<0xf8>* p)
{
    auto** vftable = *reinterpret_cast<void***>(p);
    using Destroy = void(__fastcall*)(void*, unsigned int);
    reinterpret_cast<Destroy>(vftable[0])(p, 0);
}
// MS2-PIN: ?FUN_1415e3c00@@YAXPEAXPEAU?$Unk_StlElem@$0PI@@@@Z 0x1415e3c00

// MS2-FUNCTIONAL: dispatches the recovered scalar-deleting destructor through the element vtable.
// @0x1415e3c30
void FUN_1415e3c30(void*, Unk_StlElem<0x490>* p)
{
    auto** vftable = *reinterpret_cast<void***>(p);
    using Destroy = void(__fastcall*)(void*, unsigned int);
    reinterpret_cast<Destroy>(vftable[0])(p, 0);
}
// MS2-PIN: ?FUN_1415e3c30@@YAXPEAXPEAU?$Unk_StlElem@$0EJA@@@@Z 0x1415e3c30

// MS2-FUNCTIONAL: forwards the recovered allocator destroy operation to the function-object destructor.
// @0x1415e3c60
void FUN_1415e3c60(void*, Unk_StlElem<0x20>* p)
{
    FUN_1415f93d0(p, 0);
}
// MS2-PIN: ?FUN_1415e3c60@@YAXPEAXPEAU?$Unk_StlElem@$0CA@@@@Z 0x1415e3c60

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4bf0
Unk_StlElem<0x58>* FUN_1415e4bf0(Unk_StlElem<0x58>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4bf0@@YAPEAU?$Unk_StlElem@$0FI@@@PEAU1@@Z 0x1415e4bf0

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4c00
Unk_StlElem<0x30>* FUN_1415e4c00(Unk_StlElem<0x30>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4c00@@YAPEAU?$Unk_StlElem@$0DA@@@PEAU1@@Z 0x1415e4c00

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4c10
Unk_StlElem<0x98>* FUN_1415e4c10(Unk_StlElem<0x98>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4c10@@YAPEAU?$Unk_StlElem@$0JI@@@PEAU1@@Z 0x1415e4c10

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4c20
Unk_StlElem<0x220>* FUN_1415e4c20(Unk_StlElem<0x220>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4c20@@YAPEAU?$Unk_StlElem@$0CCA@@@PEAU1@@Z 0x1415e4c20

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4c30
Unk_StlElem<0x128>* FUN_1415e4c30(Unk_StlElem<0x128>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4c30@@YAPEAU?$Unk_StlElem@$0BCI@@@PEAU1@@Z 0x1415e4c30

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4c40
Unk_StlElem<0x118>* FUN_1415e4c40(Unk_StlElem<0x118>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4c40@@YAPEAU?$Unk_StlElem@$0BBI@@@PEAU1@@Z 0x1415e4c40

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4c50
Unk_StlElem<0x580>* FUN_1415e4c50(Unk_StlElem<0x580>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4c50@@YAPEAU?$Unk_StlElem@$0FIA@@@PEAU1@@Z 0x1415e4c50

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4c60
Unk_StlElem<0x18>* FUN_1415e4c60(Unk_StlElem<0x18>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4c60@@YAPEAU?$Unk_StlElem@$0BI@@@PEAU1@@Z 0x1415e4c60

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4c70
Unk_StlElem<0x14a8>* FUN_1415e4c70(Unk_StlElem<0x14a8>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4c70@@YAPEAU?$Unk_StlElem@$0BEKI@@@PEAU1@@Z 0x1415e4c70

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4c80
Unk_StlElem<0x18>* FUN_1415e4c80(Unk_StlElem<0x18>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4c80@@YAPEAU?$Unk_StlElem@$0BI@@@PEAU1@@Z 0x1415e4c80

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4c90
Unk_StlElem<0x190>* FUN_1415e4c90(Unk_StlElem<0x190>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4c90@@YAPEAU?$Unk_StlElem@$0BJA@@@PEAU1@@Z 0x1415e4c90

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4ca0
Unk_StlElem<0xb8>* FUN_1415e4ca0(Unk_StlElem<0xb8>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4ca0@@YAPEAU?$Unk_StlElem@$0LI@@@PEAU1@@Z 0x1415e4ca0

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4cb0
Unk_StlElem<0x58>* FUN_1415e4cb0(Unk_StlElem<0x58>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4cb0@@YAPEAU?$Unk_StlElem@$0FI@@@PEAU1@@Z 0x1415e4cb0

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4cc0
Unk_StlElem<0xae8>* FUN_1415e4cc0(Unk_StlElem<0xae8>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4cc0@@YAPEAU?$Unk_StlElem@$0KOI@@@PEAU1@@Z 0x1415e4cc0

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4cd0
Unk_StlElem<0xec8>* FUN_1415e4cd0(Unk_StlElem<0xec8>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4cd0@@YAPEAU?$Unk_StlElem@$0OMI@@@PEAU1@@Z 0x1415e4cd0

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4ce0
Unk_StlElem<0xc8>* FUN_1415e4ce0(Unk_StlElem<0xc8>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4ce0@@YAPEAU?$Unk_StlElem@$0MI@@@PEAU1@@Z 0x1415e4ce0

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4cf0
Unk_StlElem<0xf8>* FUN_1415e4cf0(Unk_StlElem<0xf8>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4cf0@@YAPEAU?$Unk_StlElem@$0PI@@@PEAU1@@Z 0x1415e4cf0

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4d00
Unk_StlElem<0x490>* FUN_1415e4d00(Unk_StlElem<0x490>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4d00@@YAPEAU?$Unk_StlElem@$0EJA@@@PEAU1@@Z 0x1415e4d00

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4d10
Unk_StlElem<0x20>* FUN_1415e4d10(Unk_StlElem<0x20>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4d10@@YAPEAU?$Unk_StlElem@$0CA@@@PEAU1@@Z 0x1415e4d10

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4d20
Unk_StlElem<0x10>* FUN_1415e4d20(Unk_StlElem<0x10>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4d20@@YAPEAU?$Unk_StlElem@$0BA@@@PEAU1@@Z 0x1415e4d20

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4d30
Unk_StlElem<0x18>* FUN_1415e4d30(Unk_StlElem<0x18>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4d30@@YAPEAU?$Unk_StlElem@$0BI@@@PEAU1@@Z 0x1415e4d30

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4d40
Unk_StlElem<0x58>* FUN_1415e4d40(Unk_StlElem<0x58>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4d40@@YAPEAU?$Unk_StlElem@$0FI@@@PEAU1@@Z 0x1415e4d40

// MS2-FUNCTIONAL: returns the input pointer as recovered.
// @0x1415e4d50
void* FUN_1415e4d50(void* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4d50@@YAPEAXPEAX@Z 0x1415e4d50

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4d60
Unk_StlElem<0x98>* FUN_1415e4d60(Unk_StlElem<0x98>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4d60@@YAPEAU?$Unk_StlElem@$0JI@@@PEAU1@@Z 0x1415e4d60

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4d70
Unk_StlElem<0x220>* FUN_1415e4d70(Unk_StlElem<0x220>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4d70@@YAPEAU?$Unk_StlElem@$0CCA@@@PEAU1@@Z 0x1415e4d70

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4d80
Unk_StlElem<0x128>* FUN_1415e4d80(Unk_StlElem<0x128>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4d80@@YAPEAU?$Unk_StlElem@$0BCI@@@PEAU1@@Z 0x1415e4d80

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4d90
Unk_StlElem<0x118>* FUN_1415e4d90(Unk_StlElem<0x118>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4d90@@YAPEAU?$Unk_StlElem@$0BBI@@@PEAU1@@Z 0x1415e4d90

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4da0
Unk_StlElem<0xe0>* FUN_1415e4da0(Unk_StlElem<0xe0>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4da0@@YAPEAU?$Unk_StlElem@$0OA@@@PEAU1@@Z 0x1415e4da0

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4db0
Unk_StlElem<0x580>* FUN_1415e4db0(Unk_StlElem<0x580>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4db0@@YAPEAU?$Unk_StlElem@$0FIA@@@PEAU1@@Z 0x1415e4db0

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4dc0
Unk_StlElem<0x18>* FUN_1415e4dc0(Unk_StlElem<0x18>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4dc0@@YAPEAU?$Unk_StlElem@$0BI@@@PEAU1@@Z 0x1415e4dc0

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4dd0
Unk_StlElem<0x14a8>* FUN_1415e4dd0(Unk_StlElem<0x14a8>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4dd0@@YAPEAU?$Unk_StlElem@$0BEKI@@@PEAU1@@Z 0x1415e4dd0

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4de0
Unk_StlElem<0x18>* FUN_1415e4de0(Unk_StlElem<0x18>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4de0@@YAPEAU?$Unk_StlElem@$0BI@@@PEAU1@@Z 0x1415e4de0

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4df0
Unk_StlElem<0x190>* FUN_1415e4df0(Unk_StlElem<0x190>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4df0@@YAPEAU?$Unk_StlElem@$0BJA@@@PEAU1@@Z 0x1415e4df0

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4e00
Unk_StlElem<0xb8>* FUN_1415e4e00(Unk_StlElem<0xb8>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4e00@@YAPEAU?$Unk_StlElem@$0LI@@@PEAU1@@Z 0x1415e4e00

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4e10
Unk_StlElem<0x58>* FUN_1415e4e10(Unk_StlElem<0x58>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4e10@@YAPEAU?$Unk_StlElem@$0FI@@@PEAU1@@Z 0x1415e4e10

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4e20
Unk_StlElem<0x68>* FUN_1415e4e20(Unk_StlElem<0x68>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4e20@@YAPEAU?$Unk_StlElem@$0GI@@@PEAU1@@Z 0x1415e4e20

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4e30
Unk_StlElem<0xae8>* FUN_1415e4e30(Unk_StlElem<0xae8>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4e30@@YAPEAU?$Unk_StlElem@$0KOI@@@PEAU1@@Z 0x1415e4e30

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4e40
Unk_StlElem<0xec8>* FUN_1415e4e40(Unk_StlElem<0xec8>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4e40@@YAPEAU?$Unk_StlElem@$0OMI@@@PEAU1@@Z 0x1415e4e40

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4e50
Unk_StlElem<0xc8>* FUN_1415e4e50(Unk_StlElem<0xc8>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4e50@@YAPEAU?$Unk_StlElem@$0MI@@@PEAU1@@Z 0x1415e4e50

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4e60
Unk_StlElem<0xf8>* FUN_1415e4e60(Unk_StlElem<0xf8>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4e60@@YAPEAU?$Unk_StlElem@$0PI@@@PEAU1@@Z 0x1415e4e60

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4e70
Unk_StlElem<0x490>* FUN_1415e4e70(Unk_StlElem<0x490>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4e70@@YAPEAU?$Unk_StlElem@$0EJA@@@PEAU1@@Z 0x1415e4e70

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4e80
Unk_StlElem<0x20>* FUN_1415e4e80(Unk_StlElem<0x20>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4e80@@YAPEAU?$Unk_StlElem@$0CA@@@PEAU1@@Z 0x1415e4e80

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4f60
Unk_StlElem<0x58>* FUN_1415e4f60(Unk_StlElem<0x58>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4f60@@YAPEAU?$Unk_StlElem@$0FI@@@PEAU1@@Z 0x1415e4f60

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4f70
Unk_StlElem<0x30>* FUN_1415e4f70(Unk_StlElem<0x30>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4f70@@YAPEAU?$Unk_StlElem@$0DA@@@PEAU1@@Z 0x1415e4f70

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4f80
Unk_StlElem<0x98>* FUN_1415e4f80(Unk_StlElem<0x98>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4f80@@YAPEAU?$Unk_StlElem@$0JI@@@PEAU1@@Z 0x1415e4f80

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4f90
Unk_StlElem<0x220>* FUN_1415e4f90(Unk_StlElem<0x220>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4f90@@YAPEAU?$Unk_StlElem@$0CCA@@@PEAU1@@Z 0x1415e4f90

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4fa0
Unk_StlElem<0x128>* FUN_1415e4fa0(Unk_StlElem<0x128>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4fa0@@YAPEAU?$Unk_StlElem@$0BCI@@@PEAU1@@Z 0x1415e4fa0

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4fb0
Unk_StlElem<0x118>* FUN_1415e4fb0(Unk_StlElem<0x118>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4fb0@@YAPEAU?$Unk_StlElem@$0BBI@@@PEAU1@@Z 0x1415e4fb0

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4fc0
Unk_StlElem<0xe0>* FUN_1415e4fc0(Unk_StlElem<0xe0>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4fc0@@YAPEAU?$Unk_StlElem@$0OA@@@PEAU1@@Z 0x1415e4fc0

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4fd0
Unk_StlElem<0x580>* FUN_1415e4fd0(Unk_StlElem<0x580>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4fd0@@YAPEAU?$Unk_StlElem@$0FIA@@@PEAU1@@Z 0x1415e4fd0

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4fe0
Unk_StlElem<0x18>* FUN_1415e4fe0(Unk_StlElem<0x18>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4fe0@@YAPEAU?$Unk_StlElem@$0BI@@@PEAU1@@Z 0x1415e4fe0

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4ff0
Unk_StlElem<0x14a8>* FUN_1415e4ff0(Unk_StlElem<0x14a8>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4ff0@@YAPEAU?$Unk_StlElem@$0BEKI@@@PEAU1@@Z 0x1415e4ff0

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e5000
Unk_StlElem<0x18>* FUN_1415e5000(Unk_StlElem<0x18>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e5000@@YAPEAU?$Unk_StlElem@$0BI@@@PEAU1@@Z 0x1415e5000

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e5010
Unk_StlElem<0x190>* FUN_1415e5010(Unk_StlElem<0x190>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e5010@@YAPEAU?$Unk_StlElem@$0BJA@@@PEAU1@@Z 0x1415e5010

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e5020
Unk_StlElem<0xb8>* FUN_1415e5020(Unk_StlElem<0xb8>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e5020@@YAPEAU?$Unk_StlElem@$0LI@@@PEAU1@@Z 0x1415e5020

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e5030
Unk_StlElem<0x58>* FUN_1415e5030(Unk_StlElem<0x58>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e5030@@YAPEAU?$Unk_StlElem@$0FI@@@PEAU1@@Z 0x1415e5030

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e5040
Unk_StlElem<0x68>* FUN_1415e5040(Unk_StlElem<0x68>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e5040@@YAPEAU?$Unk_StlElem@$0GI@@@PEAU1@@Z 0x1415e5040

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e5050
Unk_StlElem<0xae8>* FUN_1415e5050(Unk_StlElem<0xae8>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e5050@@YAPEAU?$Unk_StlElem@$0KOI@@@PEAU1@@Z 0x1415e5050

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e5060
Unk_StlElem<0xec8>* FUN_1415e5060(Unk_StlElem<0xec8>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e5060@@YAPEAU?$Unk_StlElem@$0OMI@@@PEAU1@@Z 0x1415e5060

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e5070
Unk_StlElem<0xc8>* FUN_1415e5070(Unk_StlElem<0xc8>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e5070@@YAPEAU?$Unk_StlElem@$0MI@@@PEAU1@@Z 0x1415e5070

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e5080
Unk_StlElem<0xf8>* FUN_1415e5080(Unk_StlElem<0xf8>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e5080@@YAPEAU?$Unk_StlElem@$0PI@@@PEAU1@@Z 0x1415e5080

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e5090
Unk_StlElem<0x490>* FUN_1415e5090(Unk_StlElem<0x490>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e5090@@YAPEAU?$Unk_StlElem@$0EJA@@@PEAU1@@Z 0x1415e5090

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e50a0
Unk_StlElem<0x20>* FUN_1415e50a0(Unk_StlElem<0x20>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e50a0@@YAPEAU?$Unk_StlElem@$0CA@@@PEAU1@@Z 0x1415e50a0

// MS2-FUNCTIONAL: initializes the recovered fixed-capacity string copy and delegates content ownership.
// @0x1415e59a0
template<> CNMStr<0x20>::CNMStr(const CNMStr<0x20>& r)
    : m_p(nullptr)
{
    FUN_1415f9a90(this, r.m_p);
}
// MS2-PIN: ??0?$CNMStr@$0CA@@@QEAA@AEBV0@@Z 0x1415e59a0

// MS2-FUNCTIONAL: initializes the recovered fixed-capacity string to its shared empty value.
// @0x1415e5a20
template<> CNMStr<0x20>::CNMStr()
    : m_p(nullptr)
{
}
// MS2-PIN: ??0?$CNMStr@$0CA@@@QEAA@XZ 0x1415e5a20

// MS2-FUNCTIONAL: initializes the recovered fixed-capacity string copy and delegates content ownership.
// @0x1415e5b80
template<> CNMStr<0x800>::CNMStr(const CNMStr<0x800>& r)
    : m_p(nullptr)
{
    FUN_1415f9b80(this, r.m_p);
}
// MS2-PIN: ??0?$CNMStr@$0IAA@@@QEAA@AEBV0@@Z 0x1415e5b80

// MS2-FUNCTIONAL: initializes the recovered fixed-capacity string to its shared empty value.
// @0x1415e5c00
template<> CNMStr<0x800>::CNMStr()
    : m_p(nullptr)
{
}
// MS2-PIN: ??0?$CNMStr@$0IAA@@@QEAA@XZ 0x1415e5c00

// MS2-PIN: ??$construct@PEADAEBQEAD@?$_Default_allocator_traits@V?$allocator@D@std@@@std@@SAXAEAV?$allocator@D@1@QEAPEADAEBQEAD@Z 0x1415e2390
// MS2-PIN: ??$forward@AEBQEAD@std@@YAAEBQEADAEBQEAD@Z 0x1415e4bb0
