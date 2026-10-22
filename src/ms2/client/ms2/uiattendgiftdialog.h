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
class Unk_140ce3510;
class Unk_140bfc2e0;
class Unk_140acd6e0;

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
template<> Unk_14102fe10<Unk_140bfc2e0>& Unk_14102fe10<Unk_140bfc2e0>::operator=(int);

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
    bool FUN_14102c7a0(int);
    void FUN_14102c8e0(Unk_14102fe10<Unk_140ce3510>);
    void FUN_14102c9e0(Unk_14102fe10<Unk_140ce3510>);
    bool FUN_14102cb60();
    Unk_14102fe10<Unk_140ce3510> FUN_14102cbb0(int);
    int FUN_14102ccd0();
    void FUN_14102cdc0(const Scaleform::GFx::FunctionHandler::Params&);
    void FUN_14102cea0(const Scaleform::GFx::FunctionHandler::Params&);
    void FUN_14102cf30(const Scaleform::GFx::FunctionHandler::Params&);
    void FUN_14102d4b0(const Scaleform::GFx::FunctionHandler::Params&);
    bool FUN_14102d4e0(int,const CMsgBoxData&);
    void FUN_14102d5c0(int);
    void FUN_14102d610(GameEventVariable*);
    void FUN_14102d650(GameEventVariable*);
    void FUN_14102d690();
    void FUN_14102d6e0();
    void FUN_14102da40();
    void FUN_14102e490();
    void FUN_14102e6a0();
    void FUN_14102e940();
    void FUN_14102ea30();
    void FUN_14102ebb0(CInPacket&);
    void FUN_14102ec60(CInPacket&);
    void FUN_14102ec90(CInPacket&);
    void FUN_14102ecc0(CInPacket&);
    void FUN_14102ed90(CInPacket&);
    void FUN_14102f080();
    void FUN_14102f0e0();
    void FUN_14102f180(ASData&);
    template<class T> Unk_14102fe10<T> FUN_14102f870(const CString&,Unk_14102fe10<T>&);
    template<class T> Unk_14102fe10<T> FUN_140bfa760(const CString&,Unk_14102fe10<T>&,int);
    MS2Ptr<Unk_140acd6e0> FUN_140bc6d10(const CString&,MS2Ptr<Unk_140acd6e0>&);
private:
    MS2_LAYOUT_FRIEND;
    Unk_14102fe10<Unk_140bfc2e0> m_giftList;
    MS2Ptr<Unk_140acd6e0> m_detail;
    MS2Ptr<Unk_140acd6e0> m_pay;
    MS2Ptr<Unk_140acd6e0> m_usePoint;
    std::map<unsigned long,Unk_14102fe10<Unk_140ce3510>> m_events;
    ATL::CAtlArray<Unk_14102fe10<Unk_140ce3510>> m_activeEvents;
    ATL::CAtlArray<MS2Ptr<Unk_140acd6e0>> m_buttons;
    Unk_14102fe10<Unk_140ce3510> m_selected;
    Unk_14102fe10<Unk_140ce3510> m_requested;
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
