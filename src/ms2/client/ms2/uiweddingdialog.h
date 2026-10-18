// uiweddingdialog.h - UIWeddingDialog (RTTI .?AVUIWeddingDialog@@, 0x1a0 bytes, UIDialog, UI id 0x4f8c, swf
// "WeddingDialog"): the couple's wedding window. A tab strip ("m_tab") over the pages (message, skill, mission) held in
// a map keyed by the page name; the couple name, anniversary, day counter, profile, divorce flag and the wedding
// exp / grade are sent to the movie with "setData". Owning unit: ?\uiweddingdialog.cpp (0x140fc6fa0-0x140fcc860, dir
// client\ms2); header name assumed from the unit path; member names are invented.
#pragma once
#include <afx.h>
#include <map>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ms2ptr_impl.h"

class UIWeddingPage;
class Unk_WdTab;
class ASObj;
class CInPacket;
class CMsgBoxData;

class UIWeddingDialog : public UIDialog
{
public:
    typedef MS2Ptr<UIWeddingPage> PagePtr;
    typedef std::map<CString, PagePtr> PageMap;

    UIWeddingDialog();                                          // 0x140fc6fa0
    virtual ~UIWeddingDialog();                                 //  0 0x140fc72a0 (??_G 0x140fcb190)
    virtual CString vfunc_1();                                  //  1 0x140fc73a0 "WeddingDialog"
    virtual void OnLoadComplete();                              // 22 0x140fc7480 setData
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                // 28 0x140fc78e0 onAddPage / onRemovePage / ...
    virtual int vfunc_48() { return 0x4f8c; }                   // 48 0x140fcb1d0
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);   // 49 0x140fc7e10 current page
    virtual int vfunc_65();                                     // 65 0x140fc73f0 only while married
    virtual void vfunc_67();                                    // 67 0x140fc7460

    void FUN_140fc7e80(const CStringW& strProfile);             // 0x140fc7e80 "setProfile" with a given image
    void FUN_140fc7f30();                                       // 0x140fc7f30 "setProfile" with the own image
    bool FUN_140fc7fd0(int nResult, const CMsgBoxData& box);    // 0x140fc7fd0 divorce confirmed
    void FUN_140fc81a0(CInPacket& packet);                      // 0x140fc81a0 packet 0x10b: back to the first tab
    void FUN_140fc8240();                                       // 0x140fc8240 onDivorce: confirm box
    void FUN_140fc83d0(PagePtr spPage);                         // 0x140fc83d0 register a page under its key
    void FUN_140fc8470();                                       // 0x140fc8470 fill the tab strip
    void FUN_140fc86c0(ASObj& data);                            // 0x140fc86c0 "exp" / "grade"
    CString FUN_140fc88d0();                                    // 0x140fc88d0 the profile image path

    MS2Ptr<Unk_WdTab> FUN_140c02870(const CString& strName);    // bind the tab strip

private:
    MS2_LAYOUT_FRIEND;
    int m_nTab;                                                 // +0x178 the selected tab
    PagePtr m_spPage;                                           // +0x180 the shown page
    PageMap m_pages;                                            // +0x190 page key -> page
};
MS2_CHECK_SIZE(UIWeddingDialog, 0x1a0);
MS2_CHECK_OFFSET(UIWeddingDialog, m_nTab, 0x178);
MS2_CHECK_OFFSET(UIWeddingDialog, m_spPage, 0x180);
MS2_CHECK_OFFSET(UIWeddingDialog, m_pages, 0x190);
