// Attendance gift and banner dialogs. Supporting field/type names are inferred.
#pragma once
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/delegate.h"
#include <atlcoll.h>
#include <map>
class CInPacket;
class ASData;
class CMsgBoxData;
class GameEventVariable;
class GameEventAttendGiftCli;   // C3: was Unk_140ce3510
class ASTileCacheList;
class ASButton;

// Intrusive owner; only COMDATs present in this unit are defined here.
template<class T> class Unk_14102fe10 {
public:
    Unk_14102fe10() : m_p(0) {}
    Unk_14102fe10(int);
    Unk_14102fe10(T* p);                        // 0x140ce8d10 (gameeventcli.cpp)
    Unk_14102fe10(const Unk_14102fe10&);
    Unk_14102fe10(Unk_14102fe10&&);
    ~Unk_14102fe10();
    Unk_14102fe10& operator=(int) { Release(); return *this; }
    Unk_14102fe10& operator=(const Unk_14102fe10& o) { o.AddRef(); Release(); m_p=o.m_p; return *this; }
    T* get() const;
    T* operator->() const;
    bool operator==(T*) const;
private:
    void AddRef() const;
    void Release();
    void* m_00;
    T* m_p;
};
// The list reset COMDAT belongs to an earlier unit.
// (the gift list is MS2Ptr<ASTileCacheList>; its reset COMDAT belongs to an earlier unit)

class UIAttendGiftDialog : public UIDialog {
public:
    UIAttendGiftDialog();
    virtual ~UIAttendGiftDialog();
    virtual CString GetTypeName();
    virtual void OnLoadComplete();
    virtual void vfunc_26();
    virtual int vfunc_28(const char*,const Scaleform::GFx::Value*,unsigned int);
    // @0x141030400
    virtual int vfunc_48() { return 0x4eb8; }
    bool SelectRequestedEvent(int);
    void AddEvent(MS2Ptr<GameEventAttendGiftCli>);
    void RemoveEvent(MS2Ptr<GameEventAttendGiftCli>);
    bool HasActiveEvents();
    MS2Ptr<GameEventAttendGiftCli> FindEventByKind(int);
    int GetTotalUsablePoints();
    void SelectEventByIndex(const Scaleform::GFx::FunctionHandler::Params&);
    void FUN_14102cea0(const Scaleform::GFx::FunctionHandler::Params&);
    void FUN_14102cf30(const Scaleform::GFx::FunctionHandler::Params&);
    void FUN_14102d4b0(const Scaleform::GFx::FunctionHandler::Params&);
    bool OnAttendanceMsgBox(int,const CMsgBoxData&);
    void SetEventId(int);
    void FUN_14102d610(GameEventVariable*);
    void FUN_14102d650(GameEventVariable*);
    void RefreshAll();
    void UpdateEventButtons();
    void UpdateGiftList();
    void UpdatePayButton();
    void UpdateUsePointButton();
    void RebuildActiveEvents();
    void UpdateSelectedEvent();
    void OnAttendancePacket(CInPacket&);
    void FUN_14102ec60(CInPacket&);
    void FUN_14102ec90(CInPacket&);
    void FUN_14102ecc0(CInPacket&);
    void FUN_14102ed90(CInPacket&);
    void FUN_14102f080();
    void SendSelectedEventRequest();
    void FUN_14102f180(ASData&);
    template<class T> MS2Ptr<T> FUN_14102f870(const CString&,MS2Ptr<T>&);
    // C3: the list child lookup 0x140bfa760 is UIAllianceQuestDialog::FUN_140bfa760 (uiattendgiftdialog.cpp view)
private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<ASTileCacheList> m_giftList;
    MS2Ptr<ASButton> m_detail;
    MS2Ptr<ASButton> m_pay;
    MS2Ptr<ASButton> m_usePoint;
    std::map<unsigned long,MS2Ptr<GameEventAttendGiftCli>> m_events;
    ATL::CAtlArray<MS2Ptr<GameEventAttendGiftCli>> m_activeEvents;
    ATL::CAtlArray<MS2Ptr<ASButton>> m_buttons;
    MS2Ptr<GameEventAttendGiftCli> m_selected;
    MS2Ptr<GameEventAttendGiftCli> m_requested;
    int m_eventId;
};
MS2_CHECK_SIZE(UIAttendGiftDialog,0x230);
MS2_CHECK_OFFSET(UIAttendGiftDialog,m_events,0x1b8);
MS2_CHECK_OFFSET(UIAttendGiftDialog,m_activeEvents,0x1c8);
MS2_CHECK_OFFSET(UIAttendGiftDialog,m_selected,0x208);
MS2_CHECK_OFFSET(UIAttendGiftDialog,m_eventId,0x228);
class UIBannerAdvertisingDialog : public UIDialog {
public:
    UIBannerAdvertisingDialog();
    virtual ~UIBannerAdvertisingDialog();
    virtual CString GetTypeName();
    virtual void vfunc_67();
    virtual void vfunc_43();
    virtual void OnLoadInit();
    virtual void OnLoadComplete();
    virtual int vfunc_28(const char*,const Scaleform::GFx::Value*,unsigned int);
    // @0x141031420
    virtual int vfunc_48() { return 0x4eca; }
    void FUN_141031260();
    void FUN_1410312d0();
    void FUN_141031320(const CStringW&,const CStringW&);
    // @0x14187c6a0 (inlined into client\ms2\ugcmanager.cpp#2: the downloaded banner image)
    void SetImage(CString strPath) { m_image = strPath; }
private:
    MS2_LAYOUT_FRIEND;
    int m_refs;
    CString m_name;
    CString m_link;
    CString m_image;
};
MS2_CHECK_SIZE(UIBannerAdvertisingDialog,0x198);
MS2_CHECK_OFFSET(UIBannerAdvertisingDialog,m_refs,0x178);
MS2_CHECK_OFFSET(UIBannerAdvertisingDialog,m_link,0x188);
