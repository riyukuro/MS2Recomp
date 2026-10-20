// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Nexon Messenger (NM) client library, template zone: the
// std::vector<T> constructors (and their _Vector_alloc/_Vector_val/_Compressed_pair/allocator/iterator pieces) of the
// library's list types, the codec map's constructor pieces, and the implicit copy/move constructors of the
// serializable records (nmfunc.h). Everything here is a COMDAT in the exe; the anchors below only instantiate the
// templates (their users, the list requests/events and the records' serializers, live in the neighbouring units).
// MS2-UNIT: unit_1415e5c20
// MS2-RANGE: 0x1415e5c20-0x1415eaeb0 .text$mn
// MS2-PIN: ??0CNMGameCode@@QEAA@$$QEAV0@@Z 0x1415e98c0
// MS2-PIN: ??0CNMGameServerCode@@QEAA@$$QEAV0@@Z 0x1415e9c80
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <new>
#include <map>
#include <utility>
#include <vector>
#include "ms2/placeholder/nmfunc.h"
#include "ms2/ms2recover.h"

// ---- records: implicit copy/move constructors ---------------------------------------------------------------------

CNMAvatarItemInfo::CNMAvatarItemInfo(const CNMAvatarItemInfo& r) noexcept = default;
CNMAvatarItemInfo::CNMAvatarItemInfo(CNMAvatarItemInfo&& r) noexcept = default;
CNMAvatarFullInfo::CNMAvatarFullInfo(const CNMAvatarFullInfo& r) noexcept = default;
CNMAvatarFullInfo::CNMAvatarFullInfo(CNMAvatarFullInfo&& r) noexcept = default;
CNMCharacter::CNMCharacter(const CNMCharacter& r) noexcept = default;
CNMCharacter::CNMCharacter(CNMCharacter&& r) noexcept = default;
CNMDefaultUserInfo::CNMDefaultUserInfo(const CNMDefaultUserInfo& r) noexcept = default;
CNMDefaultUserInfo::CNMDefaultUserInfo(CNMDefaultUserInfo&& r) noexcept = default;
CNMRealUserInfo::CNMRealUserInfo(const CNMRealUserInfo& r) noexcept = default;
CNMRealUserInfo::CNMRealUserInfo(CNMRealUserInfo&& r) noexcept = default;
CNMRealFriendInfo::CNMRealFriendInfo(const CNMRealFriendInfo& r) noexcept = default;
CNMRealFriendInfo::CNMRealFriendInfo(CNMRealFriendInfo&& r) noexcept = default;
CNMFriendInfo::CNMFriendInfo(const CNMFriendInfo& r) noexcept = default;
CNMFriendInfo::CNMFriendInfo(CNMFriendInfo&& r) noexcept = default;
CNMCategoryInfo::CNMCategoryInfo(const CNMCategoryInfo& r) noexcept = default;
CNMCategoryInfo::CNMCategoryInfo(CNMCategoryInfo&& r) noexcept = default;
CNMCateFriendInfo::CNMCateFriendInfo(const CNMCateFriendInfo& r) = default;
CNMCateFriendInfo::CNMCateFriendInfo(CNMCateFriendInfo&& r) noexcept = default;
CNMChatRoomMemberInfo::CNMChatRoomMemberInfo(const CNMChatRoomMemberInfo& r) noexcept = default;
CNMChatRoomMemberInfo::CNMChatRoomMemberInfo(CNMChatRoomMemberInfo&& r) noexcept = default;
CNMGuildMemberLevelInfo::CNMGuildMemberLevelInfo(const CNMGuildMemberLevelInfo& r) noexcept = default;
CNMGuildMemberLevelInfo::CNMGuildMemberLevelInfo(CNMGuildMemberLevelInfo&& r) noexcept = default;
CNMChatRoomInfoEx::CNMChatRoomInfoEx(CNMChatRoomInfoEx&& r) noexcept = default;
CNMFileEvent::CNMFileEvent(const CNMFileEvent& r) noexcept = default;
CNMFileEvent::CNMFileEvent(CNMFileEvent&& r) noexcept = default;
CNMFilePath::CNMFilePath(const CNMFilePath& r) noexcept = default;
CNMFilePath::CNMFilePath(CNMFilePath&& r) noexcept = default;
CNMFindUserInfo::CNMFindUserInfo(const CNMFindUserInfo& r) noexcept = default;
CNMFindUserInfo::CNMFindUserInfo(CNMFindUserInfo&& r) noexcept = default;
CNMGameCode::CNMGameCode(const CNMGameCode& r) noexcept = default;
CNMGameCode::CNMGameCode(CNMGameCode&& r) noexcept = default;
CNMGameInfo::CNMGameInfo(const CNMGameInfo& r) noexcept = default;
CNMGameInfo::CNMGameInfo(CNMGameInfo&& r) noexcept = default;
CNMGameServerCode::CNMGameServerCode(const CNMGameServerCode& r) noexcept = default;
CNMGameServerCode::CNMGameServerCode(CNMGameServerCode&& r) noexcept = default;
CNMGuildInfoEx::CNMGuildInfoEx(const CNMGuildInfoEx& r) noexcept = default;
CNMGuildInfoEx::CNMGuildInfoEx(CNMGuildInfoEx&& r) noexcept = default;
CNMGuildListExInfo::CNMGuildListExInfo(const CNMGuildListExInfo& r) = default;
CNMGuildMemberInfo::CNMGuildMemberInfo(const CNMGuildMemberInfo& r) noexcept = default;
CNMGuildMemberInfo::CNMGuildMemberInfo(CNMGuildMemberInfo&& r) noexcept = default;
CNMGuildOnlineInfoEx::CNMGuildOnlineInfoEx(const CNMGuildOnlineInfoEx& r) = default;
CNMGuildOnlineInfoEx::CNMGuildOnlineInfoEx(CNMGuildOnlineInfoEx&& r) noexcept = default;
CNMNoteInfo::CNMNoteInfo(const CNMNoteInfo& r) noexcept = default;
CNMNoteInfo::CNMNoteInfo(CNMNoteInfo&& r) noexcept = default;
CNMNoteInfo2::CNMNoteInfo2(const CNMNoteInfo2& r) = default;
CNMNoteInfo2::CNMNoteInfo2(CNMNoteInfo2&& r) noexcept = default;

CNMCSLock::CNMCSLock(CRITICAL_SECTION* pcs)
    : m_pcs(pcs)
{
    EnterCriticalSection(m_pcs);
}

// ---- list constructors ----------------------------------------------------------------------------------------------

template <class T>
void Unk_NMListConstruct(std::vector<T>* pList)
{
    new (pList) std::vector<T>();
}

template <class T>
void Unk_NMListCopy(std::vector<T>* pList, const std::vector<T>& src)
{
    new (pList) std::vector<T>(src);
}

template <class T>
void Unk_NMListMove(std::vector<T>* pList, std::vector<T>& src)
{
    new (pList) std::vector<T>(std::move(src));
}

// begin() on a mutable and on a const list: the iterator (pointer, container) constructors.
template <class T>
void Unk_NMListIterate(std::vector<T>& list, const std::vector<T>& clist)
{
    list.begin();
    clist.begin();
}

template <class T>
void Unk_NMListIterator()
{
    typename std::vector<T>::iterator it;
    typename std::vector<T>::const_iterator cit;
}

template void Unk_NMListConstruct(std::vector<NMChatSessionTarget>*);
template void Unk_NMListIterate(std::vector<NMChatSessionTarget>&, const std::vector<NMChatSessionTarget>&);
template void Unk_NMListConstruct(std::vector<NMFriendKey>*);
template void Unk_NMListIterate(std::vector<NMFriendKey>&, const std::vector<NMFriendKey>&);
template void Unk_NMListConstruct(std::vector<CNMCateFriendInfo>*);
template void Unk_NMListMove(std::vector<CNMCateFriendInfo>*, std::vector<CNMCateFriendInfo>&);
template void Unk_NMListIterate(std::vector<CNMCateFriendInfo>&, const std::vector<CNMCateFriendInfo>&);
template void Unk_NMListConstruct(std::vector<CNMChannelMemberInfo>*);
template void Unk_NMListCopy(std::vector<CNMChannelMemberInfo>*, const std::vector<CNMChannelMemberInfo>&);
template void Unk_NMListIterate(std::vector<CNMChannelMemberInfo>&, const std::vector<CNMChannelMemberInfo>&);
template void Unk_NMListConstruct(std::vector<CNMCharacter>*);
template void Unk_NMListCopy(std::vector<CNMCharacter>*, const std::vector<CNMCharacter>&);
template void Unk_NMListMove(std::vector<CNMCharacter>*, std::vector<CNMCharacter>&);
template void Unk_NMListIterate(std::vector<CNMCharacter>&, const std::vector<CNMCharacter>&);
template void Unk_NMListConstruct(std::vector<CNMChatRoomMemberInfo>*);
template void Unk_NMListIterate(std::vector<CNMChatRoomMemberInfo>&, const std::vector<CNMChatRoomMemberInfo>&);
template void Unk_NMListConstruct(std::vector<CNMFileEvent>*);
template void Unk_NMListIterate(std::vector<CNMFileEvent>&, const std::vector<CNMFileEvent>&);
template void Unk_NMListConstruct(std::vector<CNMFilePath>*);
template void Unk_NMListCopy(std::vector<CNMFilePath>*, const std::vector<CNMFilePath>&);
template void Unk_NMListIterate(std::vector<CNMFilePath>&, const std::vector<CNMFilePath>&);
template void Unk_NMListConstruct(std::vector<CNMFindUserInfo>*);
template void Unk_NMListIterate(std::vector<CNMFindUserInfo>&, const std::vector<CNMFindUserInfo>&);
template void Unk_NMListConstruct(std::vector<CNMFriendInfo>*);
template void Unk_NMListCopy(std::vector<CNMFriendInfo>*, const std::vector<CNMFriendInfo>&);
template void Unk_NMListMove(std::vector<CNMFriendInfo>*, std::vector<CNMFriendInfo>&);
template void Unk_NMListIterate(std::vector<CNMFriendInfo>&, const std::vector<CNMFriendInfo>&);
template void Unk_NMListConstruct(std::vector<CNMGameCode>*);
template void Unk_NMListIterate(std::vector<CNMGameCode>&, const std::vector<CNMGameCode>&);
template void Unk_NMListConstruct(std::vector<CNMGameInfo>*);
template void Unk_NMListIterate(std::vector<CNMGameInfo>&, const std::vector<CNMGameInfo>&);
template void Unk_NMListConstruct(std::vector<CNMGameServerCode>*);
template void Unk_NMListIterate(std::vector<CNMGameServerCode>&, const std::vector<CNMGameServerCode>&);
template void Unk_NMListConstruct(std::vector<CNMGuildInfoEx>*);
template void Unk_NMListCopy(std::vector<CNMGuildInfoEx>*, const std::vector<CNMGuildInfoEx>&);
template void Unk_NMListIterate(std::vector<CNMGuildInfoEx>&, const std::vector<CNMGuildInfoEx>&);
template void Unk_NMListConstruct(std::vector<CNMGuildMemberInfo>*);
template void Unk_NMListCopy(std::vector<CNMGuildMemberInfo>*, const std::vector<CNMGuildMemberInfo>&);
template void Unk_NMListMove(std::vector<CNMGuildMemberInfo>*, std::vector<CNMGuildMemberInfo>&);
template void Unk_NMListIterate(std::vector<CNMGuildMemberInfo>&, const std::vector<CNMGuildMemberInfo>&);
template void Unk_NMListIterator<CNMGuildMemberInfo>();
template void Unk_NMListConstruct(std::vector<CNMGuildMemberLevelInfo>*);
template void Unk_NMListMove(std::vector<CNMGuildMemberLevelInfo>*, std::vector<CNMGuildMemberLevelInfo>&);
template void Unk_NMListIterate(std::vector<CNMGuildMemberLevelInfo>&, const std::vector<CNMGuildMemberLevelInfo>&);
template void Unk_NMListConstruct(std::vector<CNMGuildOnlineInfoEx>*);
template void Unk_NMListIterate(std::vector<CNMGuildOnlineInfoEx>&, const std::vector<CNMGuildOnlineInfoEx>&);
template void Unk_NMListIterator<CNMGuildOnlineInfoEx>();
template void Unk_NMListConstruct(std::vector<CNMNoteInfo2>*);
template void Unk_NMListIterate(std::vector<CNMNoteInfo2>&, const std::vector<CNMNoteInfo2>&);
template void Unk_NMListConstruct(std::vector<CNMNoteInfo>*);
template void Unk_NMListCopy(std::vector<CNMNoteInfo>*, const std::vector<CNMNoteInfo>&);
template void Unk_NMListIterate(std::vector<CNMNoteInfo>&, const std::vector<CNMNoteInfo>&);
template void Unk_NMListConstruct(std::vector<CNMRejectedUser>*);
template void Unk_NMListIterate(std::vector<CNMRejectedUser>&, const std::vector<CNMRejectedUser>&);
template void Unk_NMListConstruct(std::vector<CNMSessionMemberInfo>*);
template void Unk_NMListIterate(std::vector<CNMSessionMemberInfo>&, const std::vector<CNMSessionMemberInfo>&);
template void Unk_NMListConstruct(std::vector<CNMVirtualUserInfo>*);
template void Unk_NMListIterate(std::vector<CNMVirtualUserInfo>&, const std::vector<CNMVirtualUserInfo>&);
template void Unk_NMListConstruct(std::vector<CNMSetServerInfoFunc::RequestInfo>*);
template void Unk_NMListCopy(std::vector<CNMSetServerInfoFunc::RequestInfo>*, const std::vector<CNMSetServerInfoFunc::RequestInfo>&);
template void Unk_NMListIterate(std::vector<CNMSetServerInfoFunc::RequestInfo>&, const std::vector<CNMSetServerInfoFunc::RequestInfo>&);

// Element copies (_Uninitialized_copy -> _Uninitialized_backout_al) of the lists copied elsewhere in the library, and
// the category list's iterators.
template void Unk_NMListCopy(std::vector<CNMCateFriendInfo>*, const std::vector<CNMCateFriendInfo>&);
template void Unk_NMListCopy(std::vector<CNMChatRoomMemberInfo>*, const std::vector<CNMChatRoomMemberInfo>&);
template void Unk_NMListCopy(std::vector<CNMFileEvent>*, const std::vector<CNMFileEvent>&);
template void Unk_NMListCopy(std::vector<CNMFindUserInfo>*, const std::vector<CNMFindUserInfo>&);
template void Unk_NMListCopy(std::vector<CNMGameCode>*, const std::vector<CNMGameCode>&);
template void Unk_NMListCopy(std::vector<CNMGameInfo>*, const std::vector<CNMGameInfo>&);
template void Unk_NMListCopy(std::vector<CNMGameServerCode>*, const std::vector<CNMGameServerCode>&);
template void Unk_NMListCopy(std::vector<CNMGuildMemberLevelInfo>*, const std::vector<CNMGuildMemberLevelInfo>&);
template void Unk_NMListCopy(std::vector<CNMGuildOnlineInfoEx>*, const std::vector<CNMGuildOnlineInfoEx>&);
template void Unk_NMListCopy(std::vector<CNMNoteInfo2>*, const std::vector<CNMNoteInfo2>&);
template void Unk_NMListCopy(std::vector<CNMRejectedUser>*, const std::vector<CNMRejectedUser>&);
template void Unk_NMListCopy(std::vector<CNMSessionMemberInfo>*, const std::vector<CNMSessionMemberInfo>&);
template void Unk_NMListCopy(std::vector<CNMVirtualUserInfo>*, const std::vector<CNMVirtualUserInfo>&);
template void Unk_NMListIterate(std::vector<CNMCategoryInfo>&, const std::vector<CNMCategoryInfo>&);

// ---- CNMCodecManager's codec map ------------------------------------------------------------------------------------

class CNMCodec;

void Unk_NMCodecMapConstruct(std::map<unsigned char, CNMCodec*>* pCodecs)
{
    new (pCodecs) std::map<unsigned char, CNMCodec*>();
}

void Unk_NMCodecMapIterate(std::map<unsigned char, CNMCodec*>& codecs, const std::map<unsigned char, CNMCodec*>& ccodecs)
{
    std::map<unsigned char, CNMCodec*>::iterator it;
    std::map<unsigned char, CNMCodec*>::const_iterator cit;
    it = codecs.begin();
    cit = ccodecs.begin();
}
