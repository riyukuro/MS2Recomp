// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Nexon Messenger (NM) client library, template zone: the
// std::vector<T>::assign tails (_Assign_range, _Copy_unchecked, _Copy_unchecked1, _Copy_memmove) of the library's
// list types, the CNMGuildMemberInfo list built from a CNMChannelMemberInfo list, and a few tree/iterator helpers.
// Everything here is a COMDAT; the anchors below only instantiate them (their callers, the lists' operator= and the
// request/event classes, live in the neighbouring units).
// MS2-UNIT: unit_1415cf3e0
// MS2-RANGE: 0x1415cf3e0-0x1415d3570 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <vector>
#include <map>
#include <utility>
#include "ms2/placeholder/nmfunc.h"
#include "ms2/ms2recover.h"

// vector<T>::operator= -> assign(first, last) -> _Assign_range<T*> and its copy helpers.
template <class T>
void Unk_NMAssignList(std::vector<T>& dst, const std::vector<T>& src)
{
    dst = src;
}

template void Unk_NMAssignList(std::vector<NMChatSessionTarget>&, const std::vector<NMChatSessionTarget>&);
template void Unk_NMAssignList(std::vector<NMFriendKey>&, const std::vector<NMFriendKey>&);
template void Unk_NMAssignList(std::vector<CNMCateFriendInfo>&, const std::vector<CNMCateFriendInfo>&);
template void Unk_NMAssignList(std::vector<CNMChannelMemberInfo>&, const std::vector<CNMChannelMemberInfo>&);
template void Unk_NMAssignList(std::vector<CNMCharacter>&, const std::vector<CNMCharacter>&);
template void Unk_NMAssignList(std::vector<CNMChatRoomMemberInfo>&, const std::vector<CNMChatRoomMemberInfo>&);
template void Unk_NMAssignList(std::vector<CNMFileEvent>&, const std::vector<CNMFileEvent>&);
template void Unk_NMAssignList(std::vector<CNMFilePath>&, const std::vector<CNMFilePath>&);
template void Unk_NMAssignList(std::vector<CNMFriendInfo>&, const std::vector<CNMFriendInfo>&);
template void Unk_NMAssignList(std::vector<CNMGameCode>&, const std::vector<CNMGameCode>&);
template void Unk_NMAssignList(std::vector<CNMGameInfo>&, const std::vector<CNMGameInfo>&);
template void Unk_NMAssignList(std::vector<CNMGameServerCode>&, const std::vector<CNMGameServerCode>&);
template void Unk_NMAssignList(std::vector<CNMGuildMemberInfo>&, const std::vector<CNMGuildMemberInfo>&);
template void Unk_NMAssignList(std::vector<CNMGuildMemberLevelInfo>&, const std::vector<CNMGuildMemberLevelInfo>&);
template void Unk_NMAssignList(std::vector<CNMNoteInfo2>&, const std::vector<CNMNoteInfo2>&);
template void Unk_NMAssignList(std::vector<CNMRejectedUser>&, const std::vector<CNMRejectedUser>&);
template void Unk_NMAssignList(std::vector<CNMSessionMemberInfo>&, const std::vector<CNMSessionMemberInfo>&);
template void Unk_NMAssignList(std::vector<CNMVirtualUserInfo>&, const std::vector<CNMVirtualUserInfo>&);

// CNMGuildOnlineInfoEx(..., const std::vector<CNMChannelMemberInfo>&) (0x141575020): the member list is assigned from
// the channel member list, converting each element (_Assign_range<const CNMChannelMemberInfo*>).
void Unk_NMAssignGuildMembers(std::vector<CNMGuildMemberInfo>& dst, const std::vector<CNMChannelMemberInfo>& src)
{
    dst.assign(src.begin(), src.end());
}

// CNMCodecManager keeps its codecs in a std::map<unsigned char, CNMCodec*> keyed by the codec flag; AddCodec inserts
// make_pair(codec->GetCodecFlag(), codec) (emplace -> _Buynode, _Insert_nohint -> _Insert_at -> _Buy_if_not_node).
class CNMCodec;

void Unk_NMCodecMapInsert(std::map<unsigned char, CNMCodec*>& codecs, unsigned char cFlag, CNMCodec* pCodec)
{
    codecs.insert(std::make_pair(cFlag, pCodec));
}
