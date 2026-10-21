// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Nexon Messenger (NM) client library, destructor zone: the
// CNMStr<N> destructors, the codec map's and the list vectors' destructors (with the copy-backout guards of
// unit_1415e5c20's vector copies), and the destructors of the library's records, events and requests
// (nmfunc.h, nmchatroomfunc.h, nmobjects.h), A..U (CNMV*/CNMW* are in unit_1415eef30). All but
// CNMSerializable's are implicit (no vptr store) and COMDATs in the exe; the anchors below only instantiate them.
// MS2-UNIT: unit_1415eb6c0
// MS2-RANGE: 0x1415eb6c0-0x1415eef30 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <map>
#include <memory>
#include <vector>
#include "ms2/placeholder/nmobjects.h"
#include "ms2/ms2recover.h"

// @0x1415eec70
CNMSerializable::~CNMSerializable()
{
}

// ---- anchors -------------------------------------------------------------------------------------------------------

template <class T>
void Unk_NMDestroy(T* p)
{
    p->T::~T();
}

class CNMCodec;

template void Unk_NMDestroy(CNMStr<0x20>*);
template void Unk_NMDestroy(CNMStr<0x40>*);
template void Unk_NMDestroy(CNMStr<0x15e>*);
template void Unk_NMDestroy(CNMStr<0x400>*);
template void Unk_NMDestroy(CNMStr<0x800>*);
template void Unk_NMDestroy(CNMStr<0x1000>*);
template void Unk_NMDestroy(std::map<unsigned char, CNMCodec*>*);
template void Unk_NMDestroy(std::_Uninitialized_backout_al<CNMCateFriendInfo*, std::allocator<CNMCateFriendInfo>>*);
template void Unk_NMDestroy(std::_Uninitialized_backout_al<CNMChannelMemberInfo*, std::allocator<CNMChannelMemberInfo>>*);
template void Unk_NMDestroy(std::_Uninitialized_backout_al<CNMCharacter*, std::allocator<CNMCharacter>>*);
template void Unk_NMDestroy(std::_Uninitialized_backout_al<CNMChatRoomMemberInfo*, std::allocator<CNMChatRoomMemberInfo>>*);
template void Unk_NMDestroy(std::_Uninitialized_backout_al<CNMFileEvent*, std::allocator<CNMFileEvent>>*);
template void Unk_NMDestroy(std::_Uninitialized_backout_al<CNMFilePath*, std::allocator<CNMFilePath>>*);
template void Unk_NMDestroy(std::_Uninitialized_backout_al<CNMFindUserInfo*, std::allocator<CNMFindUserInfo>>*);
template void Unk_NMDestroy(std::_Uninitialized_backout_al<CNMFriendInfo*, std::allocator<CNMFriendInfo>>*);
template void Unk_NMDestroy(std::_Uninitialized_backout_al<CNMGameCode*, std::allocator<CNMGameCode>>*);
template void Unk_NMDestroy(std::_Uninitialized_backout_al<CNMGameInfo*, std::allocator<CNMGameInfo>>*);
template void Unk_NMDestroy(std::_Uninitialized_backout_al<CNMGameServerCode*, std::allocator<CNMGameServerCode>>*);
template void Unk_NMDestroy(std::_Uninitialized_backout_al<CNMGuildInfoEx*, std::allocator<CNMGuildInfoEx>>*);
template void Unk_NMDestroy(std::_Uninitialized_backout_al<CNMGuildMemberInfo*, std::allocator<CNMGuildMemberInfo>>*);
template void Unk_NMDestroy(std::_Uninitialized_backout_al<CNMGuildMemberLevelInfo*, std::allocator<CNMGuildMemberLevelInfo>>*);
template void Unk_NMDestroy(std::_Uninitialized_backout_al<CNMGuildOnlineInfoEx*, std::allocator<CNMGuildOnlineInfoEx>>*);
template void Unk_NMDestroy(std::_Uninitialized_backout_al<CNMNoteInfo2*, std::allocator<CNMNoteInfo2>>*);
template void Unk_NMDestroy(std::_Uninitialized_backout_al<CNMNoteInfo*, std::allocator<CNMNoteInfo>>*);
template void Unk_NMDestroy(std::_Uninitialized_backout_al<CNMRejectedUser*, std::allocator<CNMRejectedUser>>*);
template void Unk_NMDestroy(std::_Uninitialized_backout_al<CNMSessionMemberInfo*, std::allocator<CNMSessionMemberInfo>>*);
template void Unk_NMDestroy(std::_Uninitialized_backout_al<CNMVirtualUserInfo*, std::allocator<CNMVirtualUserInfo>>*);
template void Unk_NMDestroy(std::_Uninitialized_backout_al<CNMSetServerInfoFunc::RequestInfo*, std::allocator<CNMSetServerInfoFunc::RequestInfo>>*);
template void Unk_NMDestroy(std::vector<NMChatSessionTarget>*);
template void Unk_NMDestroy(std::vector<NMFriendKey>*);
template void Unk_NMDestroy(std::vector<CNMCateFriendInfo>*);
template void Unk_NMDestroy(std::vector<CNMChannelMemberInfo>*);
template void Unk_NMDestroy(std::vector<CNMCharacter>*);
template void Unk_NMDestroy(std::vector<CNMChatRoomMemberInfo>*);
template void Unk_NMDestroy(std::vector<CNMFileEvent>*);
template void Unk_NMDestroy(std::vector<CNMFilePath>*);
template void Unk_NMDestroy(std::vector<CNMFindUserInfo>*);
template void Unk_NMDestroy(std::vector<CNMFriendInfo>*);
template void Unk_NMDestroy(std::vector<CNMGameCode>*);
template void Unk_NMDestroy(std::vector<CNMGameInfo>*);
template void Unk_NMDestroy(std::vector<CNMGameServerCode>*);
template void Unk_NMDestroy(std::vector<CNMGuildInfoEx>*);
template void Unk_NMDestroy(std::vector<CNMGuildMemberInfo>*);
template void Unk_NMDestroy(std::vector<CNMGuildMemberLevelInfo>*);
template void Unk_NMDestroy(std::vector<CNMGuildOnlineInfoEx>*);
template void Unk_NMDestroy(std::vector<CNMNoteInfo2>*);
template void Unk_NMDestroy(std::vector<CNMNoteInfo>*);
template void Unk_NMDestroy(std::vector<CNMRejectedUser>*);
template void Unk_NMDestroy(std::vector<CNMSessionMemberInfo>*);
template void Unk_NMDestroy(std::vector<CNMVirtualUserInfo>*);
template void Unk_NMDestroy(std::vector<CNMSetServerInfoFunc::RequestInfo>*);
template void Unk_NMDestroy(CNMCSLock*);
template void Unk_NMDestroy(CNMAddCategoryFunc*);
template void Unk_NMDestroy(CNMAddFriendToCategoryFunc*);
template void Unk_NMDestroy(CNMAppendRejectedUserFunc*);
template void Unk_NMDestroy(CNMAttachToNMCOServerFunc*);
template void Unk_NMDestroy(CNMAttendanceEventEvent*);
template void Unk_NMDestroy(CNMAuthConnectionClosedEvent*);
template void Unk_NMDestroy(CNMAuthSecondaryConnectionClosedEvent*);
template void Unk_NMDestroy(CNMAvatarFullInfo*);
template void Unk_NMDestroy(CNMAvatarItemInfo*);
template void Unk_NMDestroy(CNMBlockFriendFunc*);
template void Unk_NMDestroy(CNMBringForwardStandAloneMsgFunc*);
template void Unk_NMDestroy(CNMCHBanUserFunc*);
template void Unk_NMDestroy(CNMCHChangeChannelInfoFunc*);
template void Unk_NMDestroy(CNMCHChangeMyInfoFunc*);
template void Unk_NMDestroy(CNMCHCloseFunc*);
template void Unk_NMDestroy(CNMCHGetChannelInfoFunc*);
template void Unk_NMDestroy(CNMCHGetMemberInfoListFunc*);
template void Unk_NMDestroy(CNMCHInviteUserFunc*);
template void Unk_NMDestroy(CNMCHSendChannelMessageFunc*);
template void Unk_NMDestroy(CNMCRBanUserFunc*);
template void Unk_NMDestroy(CNMCRChangeMyInfoFunc*);
template void Unk_NMDestroy(CNMCRChangeRoomInfoFunc*);
template void Unk_NMDestroy(CNMCRChatRoomCreatedEvent*);
template void Unk_NMDestroy(CNMCRChatRoomCreatedExEvent*);
template void Unk_NMDestroy(CNMCRChatRoomErrorEvent*);
template void Unk_NMDestroy(CNMCRChatRoomEstablishedEvent*);
template void Unk_NMDestroy(CNMCRChatRoomEstablishedExEvent*);
template void Unk_NMDestroy(CNMCRChatRoomInfoEvent*);
template void Unk_NMDestroy(CNMCRChatRoomInfoExEvent*);
template void Unk_NMDestroy(CNMCRChatRoomMemberEvent*);
template void Unk_NMDestroy(CNMCRChatRoomMessageReceivedEvent*);
template void Unk_NMDestroy(CNMCRCloseFunc*);
template void Unk_NMDestroy(CNMCRGetMemberInfoFunc*);
template void Unk_NMDestroy(CNMCRGetMemberListFunc*);
template void Unk_NMDestroy(CNMCRGetRoomInfoExFunc*);
template void Unk_NMDestroy(CNMCRGetRoomInfoFunc*);
template void Unk_NMDestroy(CNMCRInviteUserFunc*);
template void Unk_NMDestroy(CNMCRRegisterCallbackFunc*);
template void Unk_NMDestroy(CNMCRSendChatMessageFunc*);
template void Unk_NMDestroy(CNMCSChatMessageReceivedEvent*);
template void Unk_NMDestroy(CNMCSMultiChatCreatedEvent*);
template void Unk_NMDestroy(CNMCSSendChatMessageFunc*);
template void Unk_NMDestroy(CNMCateFriendInfo*);
template void Unk_NMDestroy(CNMCategoryInfo*);
template void Unk_NMDestroy(CNMChangeCategoryAllowTypeFunc*);
template void Unk_NMDestroy(CNMChangeCategoryNameFunc*);
template void Unk_NMDestroy(CNMChangeCategoryPropertyFunc*);
template void Unk_NMDestroy(CNMChangeConfigFunc*);
template void Unk_NMDestroy(CNMChangeFriendMemoExFunc*);
template void Unk_NMDestroy(CNMChangeFriendMemoFunc*);
template void Unk_NMDestroy(CNMChangeLocalConfigFunc*);
template void Unk_NMDestroy(CNMChangeMetaDataFunc*);
template void Unk_NMDestroy(CNMChangeMyInfoFunc*);
template void Unk_NMDestroy(CNMChangeMyLevelFunc*);
template void Unk_NMDestroy(CNMChangeMyPositionFunc*);
template void Unk_NMDestroy(CNMChangeNicknameFunc*);
template void Unk_NMDestroy(CNMChannelCreatedEvent*);
template void Unk_NMDestroy(CNMChannelErrorEvent*);
template void Unk_NMDestroy(CNMChannelEstablishedEvent*);
template void Unk_NMDestroy(CNMChannelInfo*);
template void Unk_NMDestroy(CNMChannelInfoEvent*);
template void Unk_NMDestroy(CNMChannelMemberInfo*);
template void Unk_NMDestroy(CNMChannelMemberInfoEvent*);
template void Unk_NMDestroy(CNMChannelMemberInfoList*);
template void Unk_NMDestroy(CNMChannelMemberInfoListEvent*);
template void Unk_NMDestroy(CNMChannelMessage*);
template void Unk_NMDestroy(CNMChannelMessageEvent*);
template void Unk_NMDestroy(CNMCharacter*);
template void Unk_NMDestroy(CNMCharacterChangeName64Func*);
template void Unk_NMDestroy(CNMCharacterChangeNameFunc*);
template void Unk_NMDestroy(CNMCharacterLogin64Func*);
template void Unk_NMDestroy(CNMCharacterLoginFunc*);
template void Unk_NMDestroy(CNMCharacterLogout64Func*);
template void Unk_NMDestroy(CNMCharacterLogoutFunc*);
template void Unk_NMDestroy(CNMCharacterRemove64Func*);
template void Unk_NMDestroy(CNMCharacterRemoveFunc*);
template void Unk_NMDestroy(CNMCharacterSync64Func*);
template void Unk_NMDestroy(CNMCharacterSyncFunc*);
template void Unk_NMDestroy(CNMChatMessage*);
template void Unk_NMDestroy(CNMChatRoomInfo*);
template void Unk_NMDestroy(CNMChatRoomInfoEx*);
template void Unk_NMDestroy(CNMChatRoomMemberInfo*);
template void Unk_NMDestroy(CNMChatRoomMemberList*);
template void Unk_NMDestroy(CNMCheckNewsFunc*);
template void Unk_NMDestroy(CNMClientChannelInfo*);
template void Unk_NMDestroy(CNMConfirmNewFriendFunc*);
template void Unk_NMDestroy(CNMConnConfig*);
template void Unk_NMDestroy(CNMCreateChannelFunc*);
template void Unk_NMDestroy(CNMCreateChatRoomExFunc*);
template void Unk_NMDestroy(CNMCreateChatRoomFunc*);
template void Unk_NMDestroy(CNMCustomMessageEvent*);
template void Unk_NMDestroy(CNMCustomNotifyData*);
template void Unk_NMDestroy(CNMCustomNotifyEvent*);
template void Unk_NMDestroy(CNMCustomNotifyFunc*);
template void Unk_NMDestroy(CNMDefaultUserInfo*);
template void Unk_NMDestroy(CNMDeleteCategoryFunc*);
template void Unk_NMDestroy(CNMDeleteFriendFromCategoryFunc*);
template void Unk_NMDestroy(CNMDetachFromNMCOServerFunc*);
template void Unk_NMDestroy(CNMDownloadFileFunc*);
template void Unk_NMDestroy(CNMDownloadGuildMarkFileFunc*);
template void Unk_NMDestroy(CNMEvent*);
template void Unk_NMDestroy(CNMExecuteCommonFunc*);
template void Unk_NMDestroy(CNMExecuteLauncherFunc*);
template void Unk_NMDestroy(CNMExecuteNGMInstallerFunc*);
template void Unk_NMDestroy(CNMExecuteNGMLauncherFunc*);
template void Unk_NMDestroy(CNMExecuteNGMPatcher2Func*);
template void Unk_NMDestroy(CNMExecuteNGMPatcherFunc*);
template void Unk_NMDestroy(CNMExecutePatcherFunc*);
template void Unk_NMDestroy(CNMFDSControlFunc*);
template void Unk_NMDestroy(CNMFDSFileDownloadEventReceivedEvent*);
template void Unk_NMDestroy(CNMFDSGetDownloadDirFunc*);
template void Unk_NMDestroy(CNMFDSSetDownloadDirFunc*);
template void Unk_NMDestroy(CNMFUDSGetFileEventFunc*);
template void Unk_NMDestroy(CNMFUSControlFunc*);
template void Unk_NMDestroy(CNMFUSFileUploadEventReceivedEvent*);
template void Unk_NMDestroy(CNMFUSSendFileFunc*);
template void Unk_NMDestroy(CNMFileEvent*);
template void Unk_NMDestroy(CNMFilePath*);
template void Unk_NMDestroy(CNMFinalizeFunc*);
template void Unk_NMDestroy(CNMFindUserFunc*);
template void Unk_NMDestroy(CNMFindUserInfo*);
template void Unk_NMDestroy(CNMFindUserReplyEvent*);
template void Unk_NMDestroy(CNMFindUserRequestInfo*);
template void Unk_NMDestroy(CNMFriendInfo*);
template void Unk_NMDestroy(CNMFriendInfoChangedEvent*);
template void Unk_NMDestroy(CNMFriendList*);
template void Unk_NMDestroy(CNMFunc*);
template void Unk_NMDestroy(CNMGSGetInviteCandidateListFunc*);
template void Unk_NMDestroy(CNMGSGetMemberListFunc*);
template void Unk_NMDestroy(CNMGSGetSessionInfoFunc*);
template void Unk_NMDestroy(CNMGSInviteRejectedEvent*);
template void Unk_NMDestroy(CNMGSInviteUserExFunc*);
template void Unk_NMDestroy(CNMGSInviteUserFunc*);
template void Unk_NMDestroy(CNMGSMemberInfoChangedEvent*);
template void Unk_NMDestroy(CNMGSMemberLeavedEvent*);
template void Unk_NMDestroy(CNMGSNewMemberJoinedEvent*);
template void Unk_NMDestroy(CNMGSRegisterCallbackFunc*);
template void Unk_NMDestroy(CNMGSSessionClosedEvent*);
template void Unk_NMDestroy(CNMGSSessionCreatedEvent*);
template void Unk_NMDestroy(CNMGSSessionEstablishedEvent*);
template void Unk_NMDestroy(CNMGSSessionFailedEvent*);
template void Unk_NMDestroy(CNMGSSessionInfoChangedEvent*);
template void Unk_NMDestroy(CNMGSSessionInfoEvent*);
template void Unk_NMDestroy(CNMGSSetServingProcessIDFunc*);
template void Unk_NMDestroy(CNMGSWantCloseFunc*);
template void Unk_NMDestroy(CNMGameCode*);
template void Unk_NMDestroy(CNMGameInfo*);
template void Unk_NMDestroy(CNMGameListData*);
template void Unk_NMDestroy(CNMGameLogFinalizeFunc*);
template void Unk_NMDestroy(CNMGameLogGetSessionIDFunc*);
template void Unk_NMDestroy(CNMGameLogInitializeFunc*);
template void Unk_NMDestroy(CNMGameLogWriteErrorLogFunc*);
template void Unk_NMDestroy(CNMGameLogWriteStageLogFunc*);
template void Unk_NMDestroy(CNMGameServerCode*);
template void Unk_NMDestroy(CNMGetConfigFunc*);
template void Unk_NMDestroy(CNMGetConnConfigFunc*);
template void Unk_NMDestroy(CNMGetCountFunc*);
template void Unk_NMDestroy(CNMGetDomainFunc*);
template void Unk_NMDestroy(CNMGetFindUserResultFunc*);
template void Unk_NMDestroy(CNMGetFriendInfoFunc*);
template void Unk_NMDestroy(CNMGetFriendListFunc*);
template void Unk_NMDestroy(CNMGetGameFriendTitleFunc*);
template void Unk_NMDestroy(CNMGetGameFullNameFunc*);
template void Unk_NMDestroy(CNMGetGameListFunc*);
template void Unk_NMDestroy(CNMGetGameServerListFunc*);
template void Unk_NMDestroy(CNMGetGameServerNameFunc*);
template void Unk_NMDestroy(CNMGetGameShortNameFunc*);
template void Unk_NMDestroy(CNMGetGameTokenFunc*);
template void Unk_NMDestroy(CNMGetLocalConfigFunc*);
template void Unk_NMDestroy(CNMGetMyGuildListExFunc*);
template void Unk_NMDestroy(CNMGetMyInfoFunc*);
template void Unk_NMDestroy(CNMGetMyVirtualUserListFunc*);
template void Unk_NMDestroy(CNMGetNexonPassportFunc*);
template void Unk_NMDestroy(CNMGetNoteBox2Func*);
template void Unk_NMDestroy(CNMGetNoteBoxFunc*);
template void Unk_NMDestroy(CNMGetNxHWIDFunc*);
template void Unk_NMDestroy(CNMGetPathFunc*);
template void Unk_NMDestroy(CNMGetRejectedUserListFunc*);
template void Unk_NMDestroy(CNMGetSecurityCodeCNFunc*);
template void Unk_NMDestroy(CNMGetSecurityQuestionFunc*);
template void Unk_NMDestroy(CNMGetServerInfoFunc*);
template void Unk_NMDestroy(CNMGetSessionValueFunc*);
template void Unk_NMDestroy(CNMGetSupportGameListFunc*);
template void Unk_NMDestroy(CNMGetUrlExFunc*);
template void Unk_NMDestroy(CNMGetUrlFunc*);
template void Unk_NMDestroy(CNMGetUserDataListFunc*);
template void Unk_NMDestroy(CNMGetUserInfoFunc*);
template void Unk_NMDestroy(CNMGuildChatMessageEvent*);
template void Unk_NMDestroy(CNMGuildInfoEx*);
template void Unk_NMDestroy(CNMGuildListExInfo*);
template void Unk_NMDestroy(CNMGuildMemberInfo*);
template void Unk_NMDestroy(CNMGuildMemberLevelInfo*);
template void Unk_NMDestroy(CNMGuildOnlineInfo*);
template void Unk_NMDestroy(CNMGuildOnlineInfoEvent*);
template void Unk_NMDestroy(CNMGuildOnlineInfoEx*);
template void Unk_NMDestroy(CNMGuildOnlineInfoExEvent*);
template void Unk_NMDestroy(CNMInitializeFunc*);
template void Unk_NMDestroy(CNMInviteVirtualUserEvent*);
template void Unk_NMDestroy(CNMIsNGMInstalledFunc*);
template void Unk_NMDestroy(CNMJoinChannelFunc*);
template void Unk_NMDestroy(CNMJoinToChatRoomExFunc*);
template void Unk_NMDestroy(CNMJoinToChatRoomFunc*);
template void Unk_NMDestroy(CNMLogReportSyncEvent*);
template void Unk_NMDestroy(CNMLogReportSyncFunc*);
template void Unk_NMDestroy(CNMLoginAuthFunc*);
template void Unk_NMDestroy(CNMLoginAuthSecurityCNFunc*);
template void Unk_NMDestroy(CNMLoginMessengerFunc*);
template void Unk_NMDestroy(CNMLoginNexonPassportFunc*);
template void Unk_NMDestroy(CNMLoginPassportFunc*);
template void Unk_NMDestroy(CNMLoginVirtualFunc*);
template void Unk_NMDestroy(CNMLogoutAuthFunc*);
template void Unk_NMDestroy(CNMLogoutMessengerFunc*);
template void Unk_NMDestroy(CNMLogoutVirtualFunc*);
template void Unk_NMDestroy(CNMMessageData*);
template void Unk_NMDestroy(CNMMessengerReplyEvent*);
template void Unk_NMDestroy(CNMMinimizeAllFunc*);
template void Unk_NMDestroy(CNMMonitorGuildOnlineInfoExFunc*);
template void Unk_NMDestroy(CNMMonitorGuildOnlineInfoFunc*);
template void Unk_NMDestroy(CNMMoveFriendCategoryFunc*);
template void Unk_NMDestroy(CNMMsgConnectionClosedEvent*);
template void Unk_NMDestroy(CNMMyGameInfo*);
template void Unk_NMDestroy(CNMNoteInfo2*);
template void Unk_NMDestroy(CNMNoteInfo*);
template void Unk_NMDestroy(CNMNoteInfoEvent*);
template void Unk_NMDestroy(CNMNoteInfoEx*);
template void Unk_NMDestroy(CNMNoteInstantMsgEvent*);
template void Unk_NMDestroy(CNMNotifyEvent*);
template void Unk_NMDestroy(CNMOpenGameSummaryFunc*);
template void Unk_NMDestroy(CNMPCBangLoginFunc*);
template void Unk_NMDestroy(CNMProcessNoteFunc*);
template void Unk_NMDestroy(CNMRealFriendInfo*);
template void Unk_NMDestroy(CNMRealFriendInfoChangedEvent*);
template void Unk_NMDestroy(CNMRealUserInfo*);
template void Unk_NMDestroy(CNMRefreshEvent*);
template void Unk_NMDestroy(CNMRefreshMessageEvent*);
template void Unk_NMDestroy(CNMRegisterCallbackFunc*);
template void Unk_NMDestroy(CNMRejectedUser*);
template void Unk_NMDestroy(CNMRejectedUserListChangedEvent*);
template void Unk_NMDestroy(CNMRemoveMyVirtualUserFunc*);
template void Unk_NMDestroy(CNMRemoveRejectedUserFunc*);
template void Unk_NMDestroy(CNMReplySessionRequestFunc*);
template void Unk_NMDestroy(CNMReportInfo*);
template void Unk_NMDestroy(CNMRequestChatSessionExFunc*);
template void Unk_NMDestroy(CNMRequestChatSessionFunc*);
template void Unk_NMDestroy(CNMRequestFileUploadSessionExFunc*);
template void Unk_NMDestroy(CNMRequestFileUploadSessionFunc*);
template void Unk_NMDestroy(CNMRequestMultiChatSessionExFunc*);
template void Unk_NMDestroy(CNMRequestMultiChatSessionFunc*);
template void Unk_NMDestroy(CNMRequestNewFriendData*);
template void Unk_NMDestroy(CNMRequestNewFriendEvent*);
template void Unk_NMDestroy(CNMRequestNewFriendFunc*);
template void Unk_NMDestroy(CNMRequestNewsFunc*);
template void Unk_NMDestroy(CNMRequestSessionData*);
template void Unk_NMDestroy(CNMRequestSessionToOtherFunc*);
template void Unk_NMDestroy(CNMRequestWBSessionExFunc*);
template void Unk_NMDestroy(CNMRequestWBSessionFunc*);
template void Unk_NMDestroy(CNMResetCallbackFunc*);
template void Unk_NMDestroy(CNMRestrictedWordsFunc*);
template void Unk_NMDestroy(CNMSelfUserInfo*);
template void Unk_NMDestroy(CNMSendAccuseNoteMsgFunc*);
template void Unk_NMDestroy(CNMSendNoteExMsgFunc*);
template void Unk_NMDestroy(CNMSendNoteInfoFunc*);
template void Unk_NMDestroy(CNMSendNoteMsgFunc*);
template void Unk_NMDestroy(CNMSendRefreshMessageFunc*);
template void Unk_NMDestroy(CNMServerMessageEvent*);
template void Unk_NMDestroy(CNMSessionInfo*);
template void Unk_NMDestroy(CNMSessionMemberInfo*);
template void Unk_NMDestroy(CNMSessionMemberList*);
template void Unk_NMDestroy(CNMSetAuthClosedCallbackFunc*);
template void Unk_NMDestroy(CNMSetCodePageFunc*);
template void Unk_NMDestroy(CNMSetConnConfigFunc*);
template void Unk_NMDestroy(CNMSetCountFunc*);
template void Unk_NMDestroy(CNMSetLocaleFunc*);
template void Unk_NMDestroy(CNMSetServerInfoFunc*);
template void Unk_NMDestroy(CNMSetSessionValueFunc*);
template void Unk_NMDestroy(CNMSetStatInfoFunc*);
template void Unk_NMDestroy(CNMSpecialEvent*);
template void Unk_NMDestroy(CNMStartStandAloneMsgFunc*);
template void Unk_NMDestroy(CNMTPATokenLoginFunc*);
template void Unk_NMDestroy(CNMUploadFileFunc*);
template void Unk_NMDestroy(CNMUserInfoEvent*);

// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAVCNMCateFriendInfo@@V?$allocator@VCNMCateFriendInfo@@@std@@@std@@QEAA@XZ 0x1415eb840 ; order
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAVCNMChannelMemberInfo@@V?$allocator@VCNMChannelMemberInfo@@@std@@@std@@QEAA@XZ 0x1415eb880 ; order
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAVCNMCharacter@@V?$allocator@VCNMCharacter@@@std@@@std@@QEAA@XZ 0x1415eb8c0 ; order
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAVCNMChatRoomMemberInfo@@V?$allocator@VCNMChatRoomMemberInfo@@@std@@@std@@QEAA@XZ 0x1415eb900 ; order
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAVCNMFileEvent@@V?$allocator@VCNMFileEvent@@@std@@@std@@QEAA@XZ 0x1415eb940 ; order
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAVCNMFilePath@@V?$allocator@VCNMFilePath@@@std@@@std@@QEAA@XZ 0x1415eb980 ; order
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAVCNMFindUserInfo@@V?$allocator@VCNMFindUserInfo@@@std@@@std@@QEAA@XZ 0x1415eb9c0 ; order
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAVCNMFriendInfo@@V?$allocator@VCNMFriendInfo@@@std@@@std@@QEAA@XZ 0x1415eba00 ; order
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAVCNMGameCode@@V?$allocator@VCNMGameCode@@@std@@@std@@QEAA@XZ 0x1415eba40 ; order
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAVCNMGameInfo@@V?$allocator@VCNMGameInfo@@@std@@@std@@QEAA@XZ 0x1415eba80 ; order
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAVCNMGameServerCode@@V?$allocator@VCNMGameServerCode@@@std@@@std@@QEAA@XZ 0x1415ebac0 ; order
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAVCNMGuildInfoEx@@V?$allocator@VCNMGuildInfoEx@@@std@@@std@@QEAA@XZ 0x1415ebb00 ; order
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAVCNMGuildMemberInfo@@V?$allocator@VCNMGuildMemberInfo@@@std@@@std@@QEAA@XZ 0x1415ebb40 ; order
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAVCNMGuildMemberLevelInfo@@V?$allocator@VCNMGuildMemberLevelInfo@@@std@@@std@@QEAA@XZ 0x1415ebb80 ; order
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAVCNMGuildOnlineInfoEx@@V?$allocator@VCNMGuildOnlineInfoEx@@@std@@@std@@QEAA@XZ 0x1415ebbc0 ; order
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAVCNMNoteInfo2@@V?$allocator@VCNMNoteInfo2@@@std@@@std@@QEAA@XZ 0x1415ebc00 ; order
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAVCNMNoteInfo@@V?$allocator@VCNMNoteInfo@@@std@@@std@@QEAA@XZ 0x1415ebc40 ; order
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAVCNMRejectedUser@@V?$allocator@VCNMRejectedUser@@@std@@@std@@QEAA@XZ 0x1415ebc80 ; order
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAVCNMSessionMemberInfo@@V?$allocator@VCNMSessionMemberInfo@@@std@@@std@@QEAA@XZ 0x1415ebcc0 ; order
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAVCNMVirtualUserInfo@@V?$allocator@VCNMVirtualUserInfo@@@std@@@std@@QEAA@XZ 0x1415ebd00 ; order
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAVRequestInfo@CNMSetServerInfoFunc@@V?$allocator@VRequestInfo@CNMSetServerInfoFunc@@@std@@@std@@QEAA@XZ 0x1415ebd40 ; order
// MS2-PIN: ??1?$vector@UNMChatSessionTarget@@V?$allocator@UNMChatSessionTarget@@@std@@@std@@QEAA@XZ 0x1415ebda0 ; order
// MS2-PIN: ??1?$vector@UNMFriendKey@@V?$allocator@UNMFriendKey@@@std@@@std@@QEAA@XZ 0x1415ebdd0 ; order
// MS2-PIN: ??1?$vector@VCNMGuildOnlineInfoEx@@V?$allocator@VCNMGuildOnlineInfoEx@@@std@@@std@@QEAA@XZ 0x1415ec0a0 ; order
// MS2-PIN: ??1?$vector@VCNMNoteInfo@@V?$allocator@VCNMNoteInfo@@@std@@@std@@QEAA@XZ 0x1415ec100 ; order
// MS2-PIN: ??1?$vector@VCNMRejectedUser@@V?$allocator@VCNMRejectedUser@@@std@@@std@@QEAA@XZ 0x1415ec130 ; prop
// MS2-PIN: ??1?$vector@VCNMVirtualUserInfo@@V?$allocator@VCNMVirtualUserInfo@@@std@@@std@@QEAA@XZ 0x1415ec190 ; order
// MS2-PIN: ??1?$vector@VRequestInfo@CNMSetServerInfoFunc@@V?$allocator@VRequestInfo@CNMSetServerInfoFunc@@@std@@@std@@QEAA@XZ 0x1415ec1c0 ; prop
// MS2-PIN: ??1CNMAttendanceEventEvent@@UEAA@XZ 0x1415ec280 ; RTTI
// MS2-PIN: ??1CNMAuthConnectionClosedEvent@@UEAA@XZ 0x1415ec2a0 ; RTTI
// MS2-PIN: ??1CNMAuthSecondaryConnectionClosedEvent@@UEAA@XZ 0x1415ec2c0 ; RTTI
// MS2-PIN: ??1CNMBlockFriendFunc@@UEAA@XZ 0x1415ec320 ; order
// MS2-PIN: ??1CNMBringForwardStandAloneMsgFunc@@UEAA@XZ 0x1415ec340 ; prop
// MS2-PIN: ??1CNMCHBanUserFunc@@UEAA@XZ 0x1415ec360 ; order
// MS2-PIN: ??1CNMCRChatRoomEstablishedEvent@@UEAA@XZ 0x1415ec5e0 ; order
// MS2-PIN: ??1CNMCRChatRoomEstablishedExEvent@@UEAA@XZ 0x1415ec620 ; order
// MS2-PIN: ??1CNMCRChatRoomInfoEvent@@UEAA@XZ 0x1415ec660 ; order
// MS2-PIN: ??1CNMCRChatRoomInfoExEvent@@UEAA@XZ 0x1415ec6a0 ; order
// MS2-PIN: ??1CNMChangeCategoryAllowTypeFunc@@UEAA@XZ 0x1415ec9a0 ; order
// MS2-PIN: ??1CNMChangeCategoryNameFunc@@UEAA@XZ 0x1415ec9c0 ; order
// MS2-PIN: ??1CNMChangeCategoryPropertyFunc@@UEAA@XZ 0x1415ec9e0 ; order
// MS2-PIN: ??1CNMChangeFriendMemoExFunc@@UEAA@XZ 0x1415eca30 ; order
// MS2-PIN: ??1CNMChangeFriendMemoFunc@@UEAA@XZ 0x1415eca50 ; order
// MS2-PIN: ??1CNMChangeLocalConfigFunc@@UEAA@XZ 0x1415eca70 ; order
// MS2-PIN: ??1CNMChangeMetaDataFunc@@UEAA@XZ 0x1415eca90 ; order
// MS2-PIN: ??1CNMChangeMyInfoFunc@@UEAA@XZ 0x1415ecab0 ; order
// MS2-PIN: ??1CNMChangeMyLevelFunc@@UEAA@XZ 0x1415ecad0 ; order
// MS2-PIN: ??1CNMChangeMyPositionFunc@@UEAA@XZ 0x1415ecaf0 ; order
// MS2-PIN: ??1CNMChangeNicknameFunc@@UEAA@XZ 0x1415ecb10 ; order
// MS2-PIN: ??1CNMCharacterChangeName64Func@@UEAA@XZ 0x1415ecdd0 ; order
// MS2-PIN: ??1CNMCharacterChangeNameFunc@@UEAA@XZ 0x1415ecdf0 ; order
// MS2-PIN: ??1CNMCharacterLogin64Func@@UEAA@XZ 0x1415ece10 ; order
// MS2-PIN: ??1CNMCharacterLoginFunc@@UEAA@XZ 0x1415ece30 ; order
// MS2-PIN: ??1CNMCharacterLogout64Func@@UEAA@XZ 0x1415ece50 ; order
// MS2-PIN: ??1CNMCharacterLogoutFunc@@UEAA@XZ 0x1415ece70 ; order
// MS2-PIN: ??1CNMCharacterRemove64Func@@UEAA@XZ 0x1415ece90 ; order
// MS2-PIN: ??1CNMCharacterRemoveFunc@@UEAA@XZ 0x1415eceb0 ; order
// MS2-PIN: ??1CNMCharacterSync64Func@@UEAA@XZ 0x1415eced0 ; order
// MS2-PIN: ??1CNMCharacterSyncFunc@@UEAA@XZ 0x1415ecef0 ; order
// MS2-PIN: ??1CNMDeleteCategoryFunc@@UEAA@XZ 0x1415ed1e0 ; order
// MS2-PIN: ??1CNMDeleteFriendFromCategoryFunc@@UEAA@XZ 0x1415ed200 ; order
// MS2-PIN: ??1CNMDetachFromNMCOServerFunc@@UEAA@XZ 0x1415ed220 ; order
// MS2-PIN: ??1CNMDownloadFileFunc@@UEAA@XZ 0x1415ed240 ; prop
// MS2-PIN: ??1CNMDownloadGuildMarkFileFunc@@UEAA@XZ 0x1415ed260 ; prop
// MS2-PIN: ??1CNMExecuteCommonFunc@@UEAA@XZ 0x1415ed2a0 ; order
// MS2-PIN: ??1CNMExecuteLauncherFunc@@UEAA@XZ 0x1415ed2c0 ; prop
// MS2-PIN: ??1CNMExecuteNGMInstallerFunc@@UEAA@XZ 0x1415ed2e0 ; prop
// MS2-PIN: ??1CNMExecuteNGMLauncherFunc@@UEAA@XZ 0x1415ed300 ; prop
// MS2-PIN: ??1CNMExecuteNGMPatcher2Func@@UEAA@XZ 0x1415ed320 ; prop
// MS2-PIN: ??1CNMExecuteNGMPatcherFunc@@UEAA@XZ 0x1415ed340 ; prop
// MS2-PIN: ??1CNMExecutePatcherFunc@@UEAA@XZ 0x1415ed360 ; prop
// MS2-PIN: ??1CNMFDSControlFunc@@UEAA@XZ 0x1415ed380 ; order
// MS2-PIN: ??1CNMFDSGetDownloadDirFunc@@UEAA@XZ 0x1415ed3d0 ; order
// MS2-PIN: ??1CNMFDSSetDownloadDirFunc@@UEAA@XZ 0x1415ed3f0 ; order
// MS2-PIN: ??1CNMGSInviteUserExFunc@@UEAA@XZ 0x1415ed730 ; order
// MS2-PIN: ??1CNMGSInviteUserFunc@@UEAA@XZ 0x1415ed750 ; order
// MS2-PIN: ??1CNMGSMemberLeavedEvent@@UEAA@XZ 0x1415ed7b0 ; order
// MS2-PIN: ??1CNMGSNewMemberJoinedEvent@@UEAA@XZ 0x1415ed7e0 ; order
// MS2-PIN: ??1CNMGSRegisterCallbackFunc@@UEAA@XZ 0x1415ed810 ; order
// MS2-PIN: ??1CNMGSSessionClosedEvent@@UEAA@XZ 0x1415ed830 ; order
// MS2-PIN: ??1CNMGSSessionCreatedEvent@@UEAA@XZ 0x1415ed860 ; order
// MS2-PIN: ??1CNMGSSessionEstablishedEvent@@UEAA@XZ 0x1415ed8a0 ; order
// MS2-PIN: ??1CNMGSSessionFailedEvent@@UEAA@XZ 0x1415ed8e0 ; order
// MS2-PIN: ??1CNMGSSessionInfoChangedEvent@@UEAA@XZ 0x1415ed910 ; order
// MS2-PIN: ??1CNMGSSessionInfoEvent@@UEAA@XZ 0x1415ed940 ; order
// MS2-PIN: ??1CNMGSSetServingProcessIDFunc@@UEAA@XZ 0x1415ed980 ; order
// MS2-PIN: ??1CNMGSWantCloseFunc@@UEAA@XZ 0x1415ed9a0 ; order
// MS2-PIN: ??1CNMGameLogFinalizeFunc@@UEAA@XZ 0x1415eda30 ; order
// MS2-PIN: ??1CNMGameLogGetSessionIDFunc@@UEAA@XZ 0x1415eda50 ; order
// MS2-PIN: ??1CNMGameLogInitializeFunc@@UEAA@XZ 0x1415eda70 ; order
// MS2-PIN: ??1CNMGameLogWriteErrorLogFunc@@UEAA@XZ 0x1415eda90 ; order
// MS2-PIN: ??1CNMGameLogWriteStageLogFunc@@UEAA@XZ 0x1415edab0 ; order
// MS2-PIN: ??1CNMGetCountFunc@@UEAA@XZ 0x1415edb50 ; order
// MS2-PIN: ??1CNMGetDomainFunc@@UEAA@XZ 0x1415edb70 ; order
// MS2-PIN: ??1CNMGetGameFriendTitleFunc@@UEAA@XZ 0x1415edc30 ; prop
// MS2-PIN: ??1CNMGetGameFullNameFunc@@UEAA@XZ 0x1415edc50 ; prop
// MS2-PIN: ??1CNMGetGameListFunc@@UEAA@XZ 0x1415edc70 ; prop
// MS2-PIN: ??1CNMGetGameServerListFunc@@UEAA@XZ 0x1415edca0 ; prop
// MS2-PIN: ??1CNMGetGameServerNameFunc@@UEAA@XZ 0x1415edcd0 ; prop
// MS2-PIN: ??1CNMGetGameShortNameFunc@@UEAA@XZ 0x1415edcf0 ; prop
// MS2-PIN: ??1CNMGetGameTokenFunc@@UEAA@XZ 0x1415edd10 ; prop
// MS2-PIN: ??1CNMGetLocalConfigFunc@@UEAA@XZ 0x1415edd40 ; order
// MS2-PIN: ??1CNMGetMyGuildListExFunc@@UEAA@XZ 0x1415edd60 ; prop
// MS2-PIN: ??1CNMGetMyInfoFunc@@UEAA@XZ 0x1415edd90 ; prop
// MS2-PIN: ??1CNMGetMyVirtualUserListFunc@@UEAA@XZ 0x1415eddc0 ; order
// MS2-PIN: ??1CNMGetNexonPassportFunc@@UEAA@XZ 0x1415eddf0 ; order
// MS2-PIN: ??1CNMGetNoteBox2Func@@UEAA@XZ 0x1415ede10 ; order
// MS2-PIN: ??1CNMGetNoteBoxFunc@@UEAA@XZ 0x1415ede40 ; order
// MS2-PIN: ??1CNMGetNxHWIDFunc@@UEAA@XZ 0x1415ede70 ; prop
// MS2-PIN: ??1CNMGetPathFunc@@UEAA@XZ 0x1415edea0 ; order
// MS2-PIN: ??1CNMGetRejectedUserListFunc@@UEAA@XZ 0x1415edec0 ; prop
// MS2-PIN: ??1CNMGetSecurityCodeCNFunc@@UEAA@XZ 0x1415edef0 ; order
// MS2-PIN: ??1CNMGetSecurityQuestionFunc@@UEAA@XZ 0x1415edf10 ; prop
// MS2-PIN: ??1CNMGetServerInfoFunc@@UEAA@XZ 0x1415edf40 ; prop
// MS2-PIN: ??1CNMGetSessionValueFunc@@UEAA@XZ 0x1415edf70 ; prop
// MS2-PIN: ??1CNMGetSupportGameListFunc@@UEAA@XZ 0x1415edf90 ; prop
// MS2-PIN: ??1CNMGetUrlExFunc@@UEAA@XZ 0x1415edfc0 ; prop
// MS2-PIN: ??1CNMGetUrlFunc@@UEAA@XZ 0x1415edfe0 ; order
// MS2-PIN: ??1CNMGetUserDataListFunc@@UEAA@XZ 0x1415ee000 ; order
// MS2-PIN: ??1CNMGetUserInfoFunc@@UEAA@XZ 0x1415ee020 ; order
// MS2-PIN: ??1CNMLogReportSyncFunc@@UEAA@XZ 0x1415ee330 ; order
// MS2-PIN: ??1CNMLoginAuthFunc@@UEAA@XZ 0x1415ee350 ; order
// MS2-PIN: ??1CNMLoginMessengerFunc@@UEAA@XZ 0x1415ee3b0 ; order
// MS2-PIN: ??1CNMLoginNexonPassportFunc@@UEAA@XZ 0x1415ee3d0 ; order
// MS2-PIN: ??1CNMLoginPassportFunc@@UEAA@XZ 0x1415ee3f0 ; order
// MS2-PIN: ??1CNMLoginVirtualFunc@@UEAA@XZ 0x1415ee410 ; order
// MS2-PIN: ??1CNMLogoutAuthFunc@@UEAA@XZ 0x1415ee430 ; order
// MS2-PIN: ??1CNMLogoutMessengerFunc@@UEAA@XZ 0x1415ee450 ; order
// MS2-PIN: ??1CNMLogoutVirtualFunc@@UEAA@XZ 0x1415ee470 ; order
// MS2-PIN: ??1CNMMessengerReplyEvent@@UEAA@XZ 0x1415ee4b0 ; order
// MS2-PIN: ??1CNMMinimizeAllFunc@@UEAA@XZ 0x1415ee4d0 ; order
// MS2-PIN: ??1CNMMonitorGuildOnlineInfoExFunc@@UEAA@XZ 0x1415ee4f0 ; order
// MS2-PIN: ??1CNMMonitorGuildOnlineInfoFunc@@UEAA@XZ 0x1415ee510 ; order
// MS2-PIN: ??1CNMMoveFriendCategoryFunc@@UEAA@XZ 0x1415ee530 ; order
// MS2-PIN: ??1CNMMsgConnectionClosedEvent@@UEAA@XZ 0x1415ee550 ; order
// MS2-PIN: ??1CNMRefreshEvent@@UEAA@XZ 0x1415ee7b0 ; order
// MS2-PIN: ??1CNMRefreshMessageEvent@@UEAA@XZ 0x1415ee7d0 ; order
// MS2-PIN: ??1CNMRequestChatSessionExFunc@@UEAA@XZ 0x1415ee8f0 ; order
// MS2-PIN: ??1CNMRequestChatSessionFunc@@UEAA@XZ 0x1415ee910 ; order
// MS2-PIN: ??1CNMRequestMultiChatSessionExFunc@@UEAA@XZ 0x1415ee990 ; order
// MS2-PIN: ??1CNMRequestMultiChatSessionFunc@@UEAA@XZ 0x1415ee9c0 ; order
// MS2-PIN: ??1CNMRequestWBSessionExFunc@@UEAA@XZ 0x1415eeae0 ; order
// MS2-PIN: ??1CNMRequestWBSessionFunc@@UEAA@XZ 0x1415eeb00 ; order
// MS2-PIN: ??1CNMResetCallbackFunc@@UEAA@XZ 0x1415eeb20 ; order
// MS2-PIN: ??1CNMSetAuthClosedCallbackFunc@@UEAA@XZ 0x1415eed40 ; order
// MS2-PIN: ??1CNMSetCodePageFunc@@UEAA@XZ 0x1415eed60 ; order
// MS2-PIN: ??1CNMSetConnConfigFunc@@UEAA@XZ 0x1415eed80 ; prop
// MS2-PIN: ??1CNMSetCountFunc@@UEAA@XZ 0x1415eedb0 ; order
// MS2-PIN: ??1CNMSetLocaleFunc@@UEAA@XZ 0x1415eedd0 ; order
// MS2-PIN: ??1CNMSetServerInfoFunc@@UEAA@XZ 0x1415eedf0 ; prop
// MS2-PIN: ??1CNMSetSessionValueFunc@@UEAA@XZ 0x1415eee20 ; prop
// MS2-PINS-END tplpin
