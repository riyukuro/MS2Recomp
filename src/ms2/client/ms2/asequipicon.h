// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\asequipicon.h (name assumed: the
// .cpp's __FILE__ string is in the exe, the header's is not).
//
// ASEquipIcon (RTTI .?AVASEquipIcon@@, 0x80 bytes, vftable 0x142db7898) is the C++ side of the equipment icon movie
// that the inventory / market UIs create; ASMeratMarketEquipData (0x58 bytes, vftable 0x142db78a8) carries a market
// equipment entry. Both derive directly from AScript and add smart pointers / data only. Member names are invented
// (the exe has none); FUN_<va> otherwise.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/delegate.h"

// The market basket entry held by ASMeratMarketEquipData (a CPtred-derived game object; the real type is not recovered).
class Unk_MeratEquipEntry;
class CMeratMarketProduct;

class ASEquipIcon : public AScript
{
public:
    ASEquipIcon(int nMovieId);                                              // 0x1409b8e30
    ASEquipIcon(const Scaleform::GFx::Value& v, int nMovieId);              // 0x1409b8ec0
    ASEquipIcon(Scaleform::GFx::Value& v, int nMovieId);                    // 0x1409b8f60
    virtual ~ASEquipIcon();                                                 //  0 0x1409b9000 (??_G 0x1409b9c40)

    void FUN_1409b90d0(const Scaleform::GFx::Value& v);                     // m_70 = new AScript(v, 2)
    void FUN_1409b9150(MS2Ptr<AScript> p);                                  // m_70 = p
    void FUN_1409b91a0(MS2Ptr<ASUIComponent> p);                            // m_50 = p
    void FUN_1409b91f0(MS2Ptr<CItem> p);                                    // m_40 = p
    void FUN_1409b9240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> cb, long long n);   // m_50->FUN_1422c7a90(cb, n)
    MS2Ptr<ASUIComponent> FUN_1409b92e0();                                  // m_50
    MS2Ptr<AScript> FUN_1409b9330();                                        // m_70
    MS2Ptr<ASMovieClip> FUN_1409b9380();                                    // binds the "m_slot" child of m_50 into m_60
    MS2Ptr<CItem> FUN_1409b9550();                                          // m_40
    int FUN_1409b95a0();                                                    // m_40's FUN_1405276c0, or 0

private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<CItem> m_40;                                                     // +0x40 the item shown
    MS2Ptr<ASUIComponent> m_50;                                             // +0x50 the icon component
    MS2Ptr<ASMovieClip> m_60;                                               // +0x60 its slot clip
    MS2Ptr<AScript> m_70;                                                   // +0x70
};
MS2_CHECK_SIZE(ASEquipIcon, 0x80);
MS2_CHECK_OFFSET(ASEquipIcon, m_40, 0x40);
MS2_CHECK_OFFSET(ASEquipIcon, m_50, 0x50);
MS2_CHECK_OFFSET(ASEquipIcon, m_60, 0x60);
MS2_CHECK_OFFSET(ASEquipIcon, m_70, 0x70);

class ASMeratMarketEquipData : public AScript
{
public:
    ASMeratMarketEquipData(int nMovieId);                                   // 0x1409b9600
    ASMeratMarketEquipData(const Scaleform::GFx::Value& v, int nMovieId);   // 0x1409b9670
    ASMeratMarketEquipData(Scaleform::GFx::Value& v, int nMovieId);         // 0x1409b96e0
    virtual ~ASMeratMarketEquipData();                                      //  0 0x1409b9750 (??_G 0x1409b9c80)

    void FUN_1409b97c0(MS2Ptr<Unk_MeratEquipEntry> p);                      // m_40 = p
    void FUN_1409b9810(void* p);                                            // m_50 = p
    MS2Ptr<CMeratMarketProduct> FUN_1409b9830();                            // m_40
    void* FUN_1409b9880();                                                  // m_50

private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<Unk_MeratEquipEntry> m_40;                                       // +0x40
    void* m_50;                                                             // +0x50
};
MS2_CHECK_SIZE(ASMeratMarketEquipData, 0x58);
MS2_CHECK_OFFSET(ASMeratMarketEquipData, m_40, 0x40);
MS2_CHECK_OFFSET(ASMeratMarketEquipData, m_50, 0x50);
