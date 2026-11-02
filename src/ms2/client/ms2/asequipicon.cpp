// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See asequipicon.h.
// MS2-UNIT: ?\asequipicon.cpp
// MS2-RANGE: 0x1409b8e30-0x1409b9ee0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\asequipicon.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/commonfiles/meratmarketbasketinfo.h"
#include "asequipicon.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// @0x1409b9890 (Delegate copy: clone the impl through its vfunc_1)
template<> inline Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>::Delegate(const Delegate& o) {
    if(o.m_pImpl==0) m_pImpl=0;
    else m_pImpl=o.m_pImpl->vfunc_1();
}

class Unk_MeratEquipEntry : public CPtred
{
};

// @0x1409b8e30
ASEquipIcon::ASEquipIcon(int nMovieId)
    : AScript(nMovieId)
{
}

// @0x1409b8ec0
ASEquipIcon::ASEquipIcon(const Scaleform::GFx::Value& v, int nMovieId)
    : AScript(v, nMovieId)
{
}

// @0x1409b8f60
ASEquipIcon::ASEquipIcon(Scaleform::GFx::Value& v, int nMovieId)
    : AScript(v, nMovieId)
{
}

// @0x1409b9000
// MS2-FUNCTIONAL: bytes identical; only symbols.tsv has MS2Ptr<CItem>::operator=(int) at 0x1401bffe0 (stale harvest), exe calls 0x1401bffb0
ASEquipIcon::~ASEquipIcon()
{
    m_40 = 0;
    m_70 = 0;
    m_60 = 0;
    m_50 = 0;
}

// @0x1409b90d0
void ASEquipIcon::FUN_1409b90d0(const Scaleform::GFx::Value& v)
{
    m_70.AssignRaw(new AScript(v, 2));
}
MS2_REPLACE_METHOD(0x1409B90D0, ASEquipIcon, FUN_1409b90d0, 120, 0x0BAD6E15);

// @0x1409b9150
void ASEquipIcon::FUN_1409b9150(MS2Ptr<AScript> p)
{
    m_70 = p;
}

// @0x1409b91a0
void ASEquipIcon::FUN_1409b91a0(MS2Ptr<ASUIComponent> p)
{
    m_50 = p;
}

// @0x1409b91f0
void ASEquipIcon::FUN_1409b91f0(MS2Ptr<CItem> p)
{
    m_40 = p;
}

// @0x1409b9240
void ASEquipIcon::FUN_1409b9240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> cb, long long n)
{
    if (m_50.get())
        m_50->SetGetTooltipFunction(cb, n);
}

// @0x1409b92e0
MS2Ptr<ASUIComponent> ASEquipIcon::FUN_1409b92e0()
{
    return m_50;
}

// @0x1409b9330
MS2Ptr<AScript> ASEquipIcon::FUN_1409b9330()
{
    return m_70;
}

// @0x1409b9380
MS2Ptr<ASMovieClip> ASEquipIcon::FUN_1409b9380()
{
    if (m_50.get() != 0)
    {
        Scaleform::GFx::Value slot = m_50->GetMember("m_slot");
        MS2Ptr<ASMovieClip> clip(new ASMovieClip(slot, 2));
        m_60 = clip;
        if (clip == (ASMovieClip*)0 || clip->IsUndefinedOrNull())
            return MS2Ptr<ASMovieClip>(0);
        return clip;
    }
    return MS2Ptr<ASMovieClip>(0);
}

// @0x1409b9550
MS2Ptr<CItem> ASEquipIcon::FUN_1409b9550()
{
    return m_40;
}

// @0x1409b95a0
int ASEquipIcon::FUN_1409b95a0()
{
    int n;
    if (m_40.get() != 0)
        n = ((CItem*)m_40)->FUN_1405276c0();
    else
        n = 0;
    return n;
}

// @0x1409b9600
ASMeratMarketEquipData::ASMeratMarketEquipData(int nMovieId)
    : AScript(nMovieId)
{
    m_50 = 0;
}

// @0x1409b9670
ASMeratMarketEquipData::ASMeratMarketEquipData(const Scaleform::GFx::Value& v, int nMovieId)
    : AScript(v, nMovieId)
{
    m_50 = 0;
}

// @0x1409b96e0
ASMeratMarketEquipData::ASMeratMarketEquipData(Scaleform::GFx::Value& v, int nMovieId)
    : AScript(v, nMovieId)
{
    m_50 = 0;
}

// @0x1409b9750
ASMeratMarketEquipData::~ASMeratMarketEquipData()
{
    m_40 = 0;
    m_50 = 0;
}

// @0x1409b97c0
void ASMeratMarketEquipData::FUN_1409b97c0(MS2Ptr<Unk_MeratEquipEntry> p)
{
    m_40 = p;
}

// @0x1409b9810
void ASMeratMarketEquipData::FUN_1409b9810(void* p)
{
    m_50 = p;
}

// @0x1409b9830
MS2Ptr<CMeratMarketProduct> ASMeratMarketEquipData::FUN_1409b9830()
{
    return reinterpret_cast<MS2Ptr<CMeratMarketProduct>&>(m_40);
}

// @0x1409b9880
void* ASMeratMarketEquipData::FUN_1409b9880()
{
    return m_50;
}
