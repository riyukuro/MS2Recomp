// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UISidePopupTalk, the NPC speech balloons in the screen
// corner: see uisidepopuptalk.h. First of the three TUs of ?\uisidepopuptalk.cpp.
// MS2-UNIT: ?\uisidepopuptalk.cpp#1
// MS2-RANGE: 0x1400dacd0-0x1400dae40 .text$di
// MS2-RANGE: 0x140e86d80-0x140e8bcb0 .text$mn
// MS2-RANGE: 0x142ca7a80-0x142ca7b10 .text$yd
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uisidepopuptalk.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "uisidepopuptalk.h"

#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/placeholder/cgameoption.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/creservedwordtable.h"
#include "ms2/placeholder/weddingmanager.h"
#include "ms2/commonfiles/timeutil.h"
#include "ms2/client/ms2/questmanager_1.h"
#include "ms2/client/ms2/uiquesteventlistener.h"
#include "ms2/client/ms2/uiwhispernotifydialog.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// The notice UIWorldShareInfoEventDispatcher hands to its listeners (the whisper dialog reads it as a system whisper).
struct Unk_SptNpcNotice
{
    unsigned m_nNpcId;                                      // +0x00
};

int FUN_140768010(int nMax, int nMin);                      // a random number in [nMin, nMax)
UISwfEntity* FUN_140c9b540(int nId);                        // the minimap dialog (ui class 0x4e29)
bool FUN_140184310(const CString& str, const char* sz);     // CString == const char*
void FUN_141276180(const CString& strName, const CString& strGroup);   // play a system sound
__int64 FUN_140718320(const CStringW& str);                 // parse a number text
unsigned __int64 FUN_140718370(const CStringW& str);        // parse an unsigned 64-bit number text
void FUN_1407cd930(Scaleform::GFx::Value* pObject, const char* szName, const Scaleform::GFx::Value& v);   // set a member of an AS object

// The dialog of a ui class id (or 0).
template <class T> T* Unk_SptGetUI(int nId)
{
    if (TSingleton<CUIService>::GetInstance())
    {
        MS2Ptr<UIObject> spObj = TSingleton<CUIService>::GetInstance()->FUN_141adcea0((eUIClassID)nId);
        if (spObj.get())
            return dynamic_cast<T*>((UIObject*)spObj);
    }
    return 0;
}

// @0x140e86d80
UISidePopupTalk::UISidePopupTalk()
{
    m_2c = 0x1a;
    m_table.Init();
    TSingleton<UIQuestEventDispatcher>::GetInstance()->FUN_141aa87c0(this);
    TSingleton<UIWorldShareInfoEventDispatcher>::GetInstance()->FUN_14135fd20(this);
    TSingleton<NotifySystem>::GetInstance()->RegisterNotify(L"NotifyFadeInComplete", Delegate<void(NotifyObject*)>(this, &UISidePopupTalk::FUN_140e87ec0));
}

// @0x140e87040
UISidePopupTalk::~UISidePopupTalk()
{
    TSingleton<UIQuestEventDispatcher>::GetInstance()->FUN_141aa8850(this);
    TSingleton<UIWorldShareInfoEventDispatcher>::GetInstance()->FUN_14135fdb0(this);
    TSingleton<NotifySystem>::GetInstance()->UnregisterNotify(L"NotifyFadeInComplete", Delegate<void(NotifyObject*)>(this, &UISidePopupTalk::FUN_140e87ec0));
}

// @0x140e87260
CString UISidePopupTalk::vfunc_1()
{
    return "SidePopupTalk";
}


// @0x140e872b0
void UISidePopupTalk::OnLoadComplete()
{
    UIHeadUpDisplay::OnLoadComplete();
    m_voices.RemoveAll();
    for (size_t i = 0; i < m_pending.GetCount(); i++)
        FUN_140e88010(m_pending[i]);
    m_pending.RemoveAll();
}
MS2_REPLACE_METHOD(0x140E872B0, UISidePopupTalk, OnLoadComplete, 181, 0x318E81AB);

// @0x140e87370
void UISidePopupTalk::vfunc_43()
{
    UIHeadUpDisplay::vfunc_43();
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (spEntity.get())
        spEntity->vfunc_2(5, 0, 0);
}
MS2_REPLACE_METHOD(0x140E87370, UISidePopupTalk, vfunc_43, 164, 0xA237E465);

// @0x140e87420
int UISidePopupTalk::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIHeadUpDisplay::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp(szMethod, "onHideComplete") == 0)
    {
        ASData args;
        if (args.FUN_1422b9620(pArgs, nArgs))
        {
            int nKind = args.FUN_1422b8a10();
            if (nKind == 1)
                FUN_140e886f0(1);
        }
        return 1;
    }
    else if (_stricmp(szMethod, "onPlayVoice") == 0)
    {
        ASData args;
        if (args.FUN_1422b9620(pArgs, nArgs))
        {
            eSidePopupVoice eKey = (eSidePopupVoice)args.FUN_1422b8a10();
            unsigned nEffect = 0;
            if (m_voices.Lookup(eKey, nEffect))
            {
                TSingleton<CEffectService>::GetInstance()->FUN_1411a6060(nEffect);
                m_voices.SetAt(eKey, 0);
            }
            CString strVoice = args.FUN_1422b8d30();
            if (strVoice.GetLength() != 0)
            {
                PCBase* pPlayer = static_cast<PCBase*>(TSingleton<WorldService>::GetInstance()->FUN_141bd0cc0());
                if (pPlayer != 0)
                {
                    unsigned nId = TSingleton<CEffectService>::GetInstance()->FUN_1411a4f40(strVoice, pPlayer->vfunc_18());
                    m_voices.SetAt(eKey, nId);
                }
            }
        }
        return 1;
    }
    else if (_stricmp(szMethod, "onPlaySound") == 0)
    {
        ASData args;
        if (args.FUN_1422b9620(pArgs, nArgs))
        {
            int nKind = args.FUN_1422b8a10();
            CString strSound = args.FUN_1422b8d30();
            FUN_141276180(strSound, "");
        }
    }
    else if (_stricmp(szMethod, "onEnterFieldWar") == 0)
    {
        COutPacket packet(0xb6);
        packet.Encode1(1);
        FUN_140710590(packet);
    }
    else if (_stricmp(szMethod, "onEnterWeddingHall") == 0)
    {
        ASData args;
        if (args.FUN_1422b9620(pArgs, nArgs))
        {
            unsigned __int64 nId = FUN_140718370(args.FUN_1422b8f40());
            if (nId == 0)
                TSingleton<CUIService>::GetInstance()->ToggleDialog((eUIClassID)0x4f96);
            else
                TSingleton<WeddingManager>::GetInstance()->SendInvitation(nId);
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140E87420, UISidePopupTalk, vfunc_28, 1181, 0x8026C307);


// @0x140e878d0
void UISidePopupTalk::vfunc_2()
{
    UIHeadUpDisplay::vfunc_2();
}
MS2_REPLACE_METHOD(0x140E878D0, UISidePopupTalk, vfunc_2, 24, 0xCA049B49);


// @0x140e878f0
void UISidePopupTalk::vfunc_3()
{
    UIHeadUpDisplay::vfunc_3();
    FUN_140e886f0(1);
    for (POSITION pos = m_voices.GetStartPosition(); pos != NULL; m_voices.GetNext(pos))
    {
        unsigned& nEffect = m_voices.GetValueAt(pos);
        TSingleton<CEffectService>::GetInstance()->FUN_1411a6060(nEffect);
    }
    m_voices.RemoveAll();
}
MS2_REPLACE_METHOD(0x140E878F0, UISidePopupTalk, vfunc_3, 167, 0xC9B74047);


// @0x140e879a0
void UISidePopupTalk::FUN_140e879a0(MS2Ptr<SidePopupTalkParam> spParam)
{
    if (m_30.IsNull())
    {
        m_pending.Add(spParam);
        vfunc_2();
    }
    else
    {
        FUN_140e88010(spParam);
    }
}

// @0x140e87a40
void UISidePopupTalk::vfunc_o178_1(void* p)
{
    {
        MS2Ptr<SidePopupTalkParam> spParam = m_table.Find(SIDEPOPUP_EVENT_QUEST_ACCEPT, static_cast<CQuest*>(p)->FUN_140bfc580());
        if (spParam.get())
            FUN_140e879a0(spParam);
    }
    if (static_cast<CQuest*>(p)->IsComplete())
    {
        MS2Ptr<SidePopupTalkParam> spParam = m_table.Find(SIDEPOPUP_EVENT_QUEST_SATISFIED, static_cast<CQuest*>(p)->FUN_140bfc580());
        if (spParam.get())
            FUN_140e879a0(spParam);
    }
}
MS2_REPLACE_METHOD_VIA(0x140E87A40, UISidePopupTalk, UIQuestEventListener, vfunc_o178_1, 337, 0x5F70B326);

// @0x140e87ba0
void UISidePopupTalk::vfunc_o178_3(void* p)
{
    {
        MS2Ptr<SidePopupTalkParam> spParam = m_table.Find(SIDEPOPUP_EVENT_QUEST_PROGRESS, static_cast<CQuest*>(p)->FUN_140bfc580());
        if (spParam.get())
            FUN_140e879a0(spParam);
    }
    if (static_cast<CQuest*>(p)->IsComplete())
    {
        MS2Ptr<SidePopupTalkParam> spParam = m_table.Find(SIDEPOPUP_EVENT_QUEST_SATISFIED, static_cast<CQuest*>(p)->FUN_140bfc580());
        if (spParam.get())
            FUN_140e879a0(spParam);
    }
}
MS2_REPLACE_METHOD_VIA(0x140E87BA0, UISidePopupTalk, UIQuestEventListener, vfunc_o178_3, 337, 0x4B164C3C);

// @0x140e87d00
void UISidePopupTalk::vfunc_o178_2(void* p)
{
    MS2Ptr<SidePopupTalkParam> spParam = m_table.Find(SIDEPOPUP_EVENT_QUEST_COMPLETE, static_cast<CQuest*>(p)->FUN_140bfc580());
    if (spParam.get())
        FUN_140e879a0(spParam);
}
MS2_REPLACE_METHOD_VIA(0x140E87D00, UISidePopupTalk, UIQuestEventListener, vfunc_o178_2, 145, 0xE893A71B);

// @0x140e87da0
void UISidePopupTalk::vfunc_1(__int64 n, int a, int b)
{
    if (FUN_140e88690(reinterpret_cast<const Unk_SptNpcNotice*>(n)->m_nNpcId))
        return;
    m_lastTick.SetAt(reinterpret_cast<const Unk_SptNpcNotice*>(n)->m_nNpcId, GetTickCountMs2());
    MS2Ptr<SidePopupTalkParam> spParam = m_table.Find(SIDEPOPUP_EVENT_BOSS_REGEN, reinterpret_cast<const Unk_SptNpcNotice*>(n)->m_nNpcId);
    if (spParam.get())
    {
        FUN_140e879a0(spParam);
    }
    else
    {
        UIWhisperNotifyDialog* pDialog = Unk_SptGetUI<UIWhisperNotifyDialog>(0x4e5e);
        if (pDialog != 0)
            pDialog->FUN_141b52570(reinterpret_cast<const Unk_WhisperInfo*>(n), a, b);
    }
}

// @0x140e87ec0
void UISidePopupTalk::FUN_140e87ec0(NotifyObject* pNotify)
{
    MS2Ptr<SidePopupTalkParam> spParam = m_table.FindByMap(TSingleton<WorldService>::GetInstance()->FUN_141bd3060());
    if (spParam.get())
        FUN_140e879a0(spParam);
}
MS2_REPLACE_METHOD(0x140E87EC0, UISidePopupTalk, FUN_140e87ec0, 138, 0x3BC35300);

// @0x140e87f50
void UISidePopupTalk::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
    UIHeadUpDisplay::vfunc_45(pRetVal, strMethod, pArgs);
    if (FUN_140184310(strMethod, "getExpireDuration"))
    {
        __int64 nExpire = FUN_140718320(pArgs->FUN_1422b8f40());
        __int64 nNow = GetServerTime();
        pRetVal->SetInt((int)(nExpire - nNow));
    }
}
MS2_REPLACE_METHOD(0x140E87F50, UISidePopupTalk, vfunc_45, 181, 0xC6A4F5C2);


// @0x140e88010
void UISidePopupTalk::FUN_140e88010(MS2Ptr<SidePopupTalkParam> spParam)
{
    CStringW strMsg;
    if (spParam->m_script.size() > 0)
    {
        int nIndex = FUN_140768010(spParam->m_script.size(), 0);
        strMsg = TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x44, spParam->m_script[nIndex]);
    }
    else
    {
        strMsg = spParam->m_strText;
    }
    TSingleton<CReservedWordTable>::GetInstance()->FUN_1416fb300(strMsg);

    ASObj obj(2);
    obj.FUN_140e88a10("type", spParam->m_nKind);
    obj.FUN_1407cba60("movie", spParam->m_strName);
    obj.FUN_1407cbb20("msg", strMsg);
    obj.FUN_1407cba60("illust", spParam->m_strIcon);
    obj.FUN_1409c4990("duration", spParam->m_nNpcId);
    obj.FUN_1407cba60("voice", spParam->m_strSound);
    obj.FUN_1407cba60("sound", spParam->m_strScript);
    obj.FUN_1407cba60("mapTile", spParam->m_str68);
    obj.FUN_1407cbb20("mapName", spParam->m_str70);
    obj.FUN_1407cba60("expire", spParam->m_str78);
    obj.FUN_1407cbb20("userValue", spParam->m_strUserValue);
    for (POSITION pos = spParam->m_extra.GetStartPosition(); pos != NULL; spParam->m_extra.GetNext(pos))
    {
        CStringA strName = spParam->m_extra.GetKeyAt(pos);
        CStringW strValue = spParam->m_extra.GetValueAt(pos);
        obj.FUN_1407cbb20(strName, strValue);
    }
    Unk_SoundState* pSound = TSingleton<CGameOption>::GetInstance()->FUN_140d13c70();
    if (pSound != 0)
        obj.FUN_1409c4a30("volume", pSound->m_b00 ? 0.0f : pSound->FUN_1412602e0());
    m_30->Invoke("addPopup", obj);
    if (spParam->m_nKind == 1)
        FUN_140e886f0(0);
}

// @0x140e88690
int UISidePopupTalk::FUN_140e88690(unsigned nId)
{
    DWORD nTick = 0;
    if (!m_lastTick.Lookup(nId, nTick))
        return 0;
    if ((unsigned)(GetTickCountMs2() - nTick) > 60000)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140E88690, UISidePopupTalk, FUN_140e88690, 90, 0x43DD4ACF);

// @0x140e886f0
void UISidePopupTalk::FUN_140e886f0(int bVisible)
{
    UISwfEntity* pMinimap = FUN_140c9b540(0x4e29);
    if (pMinimap != 0)
    {
        if (pMinimap->vfunc_9() != bVisible)
            pMinimap->vfunc_8(bVisible);
    }
    UIQuestGuideDialog* pGuide = Unk_SptGetUI<UIQuestGuideDialog>(0x4e43);
    if (pGuide != 0)
    {
        if (pGuide->vfunc_9() != bVisible)
            pGuide->vfunc_8(bVisible);
    }
}
MS2_REPLACE_METHOD(0x140E886F0, UISidePopupTalk, FUN_140e886f0, 148, 0x698C3076);

// The "type" member of a popup (an int through ASData; the COMDAT is this unit's).
// @0x140e88a10
void ASObj::FUN_140e88a10(const char* szName, int n)
{
    ASData data;
    data.FUN_1422b7f70(n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}
