// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The Razer Chroma keyboard/mouse lighting of
// client\ms2\razerchroma (the ChromaSDK effect classes, ChromaLinkEffect, ChromaManagerImpl and ChromaManagerDummy) and
// their std::vector / std::map / std::set template glue. The exe range holds several original objs in a row (one per
// effect class, the manager, the dummy); this file keeps them in exe order. Class names from RTTI, the rest invented
// (see unit_140a93d00.h). Bodies cross-checked with the third-party v2525 snapshot and the Razer ChromaSDKPlugin code.
// MS2-UNIT: unit_140a93d00
// MS2-RANGE: 0x1400c4e10-0x1400c5120 .text$di
// MS2-RANGE: 0x140a93d00-0x140aaadb0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <process.h>
#include <math.h>
#include <algorithm>
#include <cguid.h>

#include "unit_140a93d00.h"
#include "ms2/placeholder/uistatuseventdispatcher.h"
#include "ms2/placeholder/ckeytable.h"
#include "ms2/placeholder/cgameoption.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/client/ms2/uiservice.h"
#include <egf/Entity.h>
#include "ms2/client/ms2/statemanager.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Header-defined statics of the first obj (the ChromaEffectBase one also defines the dummy service instance).
#include "ms2/placeholder/header_statics_a.h"

unsigned FUN_140869420();                                   // the raw timer tick (ms)
int FUN_14028d260(float fSecond);                           // seconds -> ticks

#define GetCurrentTick() FUN_140869420()

// assert() of the inline Cooldown members in chromaeffectplaying.h
#define CHROMA_ASSERT_H(line, expression)                                                                         \
    (void)((!!(expression)) ||                                                                                  \
           (_wassert(_CRT_WIDE(#expression),                                                                    \
                     L"e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\razerchroma\\chromaeffectplaying.h",            \
                     (unsigned)(line)), 0))

namespace ChromaSDK {

ChromaManagerDummy g_chromaManagerDummy;                    // 0x143ab89f8

// static_cast helper of the effects (instances IChromaManager -> ChromaManagerImpl, ChromaEffectBase -> Character)
template <class T, class U> T* chroma_cast(U* p)
{
    return static_cast<T*>(p);
}

// ================================================================================================================
// ChromaEffectBase

// @0x140a93d00
ChromaEffectBase::ChromaEffectBase()
{
    m_dwNextTick = 0;
}

// @0x140a93d50
ChromaEffectBase::~ChromaEffectBase()
{
    Clear();
}

// @0x140a93da0
void ChromaEffectBase::Update()
{
    DWORD dwNow = GetCurrentTick();
    if (m_dwNextTick <= dwNow)
    {
        Play();
        m_dwNextTick = dwNow + GetInterval();
    }
}

// @0x140a93e00
void ChromaEffectBase::OnEnter(int nPrevState)
{
    m_dwNextTick = 0;
}

// @0x140a93e20
void ChromaEffectBase::Clear()
{
    for (std::vector<RZEFFECTID>::iterator it = m_effects.begin(); it != m_effects.end(); ++it)
        GetChromaManager()->DeleteEffect(*it);
    m_effects.clear();
}

// @0x140a93ee0
void ChromaEffectBase::Play()
{
    if (m_effects.empty())
        Create();
    if (m_effects.empty())
        return;
    if (m_effects.size() <= m_nFrame)
        m_nFrame = 0;
    GetChromaManager()->SetEffect(m_effects[m_nFrame++]);
}

// @0x140a94360
DWORD ChromaEffectBase::GetInterval()
{
    return 100;
}

// ================================================================================================================
// ChromaEffectCharacter

// @0x140a94850
ChromaEffectCharacter::ChromaEffectCharacter()
{
    m_nFrame = 0;
    m_color = 0;
}

// @0x140a948a0
ChromaEffectCharacter::~ChromaEffectCharacter()
{
}

// @0x140a948d0
void ChromaEffectCharacter::Create()
{
    ChromaManagerImpl* pImpl = chroma_cast<ChromaManagerImpl>(GetChromaManager());
    Clear();
    Keyboard::STATIC_EFFECT_TYPE keyboard = {};
    m_color = pImpl->GetColor(1);
    keyboard.Color = m_color;
    RZEFFECTID effectId;
    if (pImpl->CreateKeyboardEffect(Keyboard::CHROMA_STATIC, &keyboard, &effectId) == 0)
        m_effects.push_back(effectId);
    Mouse::STATIC_EFFECT_TYPE mouse = {};
    mouse.Color = m_color;
    mouse.LEDId = Mouse::RZLED_ALL;
    if (pImpl->CreateMouseEffect(Mouse::CHROMA_STATIC, &mouse, &effectId) == 0)
        m_effects.push_back(effectId);
    Headset::STATIC_EFFECT_TYPE headset = {};
    headset.Color = m_color;
    if (pImpl->CreateHeadsetEffect(Headset::CHROMA_STATIC, &headset, &effectId) == 0)
        m_effects.push_back(effectId);
    Mousepad::STATIC_EFFECT_TYPE mousepad = {};
    mousepad.Color = m_color;
    if (pImpl->CreateMousepadEffect(Mousepad::CHROMA_STATIC, &mousepad, &effectId) == 0)
        m_effects.push_back(effectId);
}

// @0x140a94b30
void ChromaEffectCharacter::Play()
{
    if (m_color != GetChromaManager()->GetColor(1) || m_effects.empty())
        Create();
    if (m_effects.empty())
        return;
    GetChromaManager()->SetEffect(m_effects[0]);
}

// @0x140a94c00
void ChromaEffectCharacter::UpdateMouse()
{
    if (!m_effects.empty())
    {
        for (std::vector<RZEFFECTID>::iterator it = m_effects.begin() + 1; it != m_effects.end(); ++it)
            GetChromaManager()->SetEffect(*it);
    }
}

// @0x140a95420
DWORD ChromaEffectCharacter::GetInterval()
{
    return 200;
}

// ================================================================================================================
// ChromaEffectCinematic

// @0x140a95830
ChromaEffectCinematic::ChromaEffectCinematic()
{
    m_nFrame = 0;
}

// @0x140a95870
ChromaEffectCinematic::~ChromaEffectCinematic()
{
}

// @0x140a958a0
void ChromaEffectCinematic::Create()
{
    ChromaManagerImpl* pImpl = chroma_cast<ChromaManagerImpl>(GetChromaManager());
    Clear();
    Keyboard::CUSTOM_KEY_EFFECT_TYPE effect = {};
    int nKey = pImpl->GetKeyboardKey(1);
    if (nKey != -1)
    {
        effect.Key[HIBYTE(nKey)][LOBYTE(nKey)] = pImpl->GetColor(1) | 0x01000000;
        RZEFFECTID effectId;
        if (pImpl->CreateKeyboardEffect(Keyboard::CHROMA_CUSTOM_KEY, &effect, &effectId) == 0)
            m_effects.push_back(effectId);
    }
}

// @0x140a95a40
DWORD ChromaEffectCinematic::GetInterval()
{
    return 200;
}

// ================================================================================================================
// ChromaEffectDClear

// @0x140a95a50
ChromaEffectDClear::ChromaEffectDClear()
{
    m_nFrame = 0;
    m_nRepeat = 0;
    m_nCenter = 10;
}

// @0x140a95ab0
ChromaEffectDClear::~ChromaEffectDClear()
{
}

// @0x140a95ae0
void ChromaEffectDClear::OnEnter(int nPrevState)
{
    ChromaEffectBase::OnEnter(nPrevState);
    m_nFrame = 0;
    m_nRepeat = 5;
}

// @0x140a95b20
void ChromaEffectDClear::Create()
{
    Clear();
    IChromaManager* pManager = GetChromaManager();
    Keyboard::CUSTOM_EFFECT_TYPE effect = {};
    int nRadius = m_nFrame - 2;
    int nCount = 0;
    for (int row = 0; row < Keyboard::MAX_ROW; row++)
    {
        for (int col = 0; col < Keyboard::MAX_COLUMN; col++)
        {
            int nDistance = (int)sqrt(pow((float)row - (float)HIBYTE(m_nCenter), 2) + pow((float)col - (float)LOBYTE(m_nCenter), 2));
            if (nRadius <= nDistance)
            {
                effect.Color[row][col] = pManager->GetColor(12);
                nCount++;
            }
            else
            {
                effect.Color[row][col] = pManager->GetColor(13);
            }
        }
    }
    RZEFFECTID effectId;
    if (pManager->CreateKeyboardEffect(Keyboard::CHROMA_CUSTOM, &effect, &effectId) == 0)
    {
        m_effects.push_back(effectId);
        m_nFrame++;
    }
    if (nCount == 0)
    {
        if (--m_nRepeat <= 0)
            pManager->SetState(STATE_PLAYING);
        m_nFrame = 0;
    }
}

// @0x140a95da0
void ChromaEffectDClear::Play()
{
    Create();
    if (m_effects.empty())
        return;
    GetChromaManager()->SetEffect(m_effects[0]);
}

// ================================================================================================================
// ChromaEffectDeath

// @0x140a95e70
ChromaEffectDeath::ChromaEffectDeath()
{
    m_nFrame = 0;
    m_n34 = -1;
    m_n38 = 0;
}

// @0x140a95ed0
ChromaEffectDeath::~ChromaEffectDeath()
{
}

// @0x140a95f00
void ChromaEffectDeath::OnEnter(int nPrevState)
{
    ChromaEffectBase::OnEnter(nPrevState);
    m_nFrame = 0;
}

// @0x140a95f40
void ChromaEffectDeath::Create()
{
    Clear();
    IChromaManager* pManager = GetChromaManager();
    COLORREF inner = pManager->GetColor(8);
    COLORREF outer = pManager->GetColor(0);
    Keyboard::CUSTOM_EFFECT_TYPE effect = {};
    int nRadius = 0;
    m_nCenter = 0x409;
    int nLeft = LOBYTE(m_nCenter);
    int nRight = Keyboard::MAX_COLUMN - LOBYTE(m_nCenter) - 1;
    nRadius = (std::max)(nRight, nLeft) - m_nFrame;
    RZEFFECTID effectId;
    if (nRadius <= 0)
    {
        if (pManager->CreateKeyboardEffect(Keyboard::CHROMA_NONE, NULL, &effectId) == 0)
        {
            m_effects.push_back(effectId);
            m_nFrame = 0xffffffff;
        }
    }
    else
    {
        for (int row = 0; row < Keyboard::MAX_ROW; row++)
        {
            for (int col = 0; col < Keyboard::MAX_COLUMN; col++)
            {
                if (nRadius <= (int)sqrt(pow((float)row - (float)HIBYTE(m_nCenter), 2) + pow((float)col - (float)LOBYTE(m_nCenter), 2)))
                    effect.Color[row][col] = outer;
                else
                    effect.Color[row][col] = inner;
            }
        }
        if (pManager->CreateKeyboardEffect(Keyboard::CHROMA_CUSTOM, &effect, &effectId) == 0)
        {
            m_effects.push_back(effectId);
            m_nFrame++;
        }
    }
}

// @0x140a96210
void ChromaEffectDeath::Play()
{
    if (m_nFrame != 0xffffffff)
        Create();
    if (m_effects.empty())
        return;
    GetChromaManager()->SetEffect(m_effects[0]);
}

// ================================================================================================================
// ChromaEffectLoading

// @0x140a962f0
ChromaEffectLoading::ChromaEffectLoading()
{
    m_nFrame = 0;
}

// @0x140a96330
ChromaEffectLoading::~ChromaEffectLoading()
{
}

// @0x140a96360
void ChromaEffectLoading::Create()
{
    ChromaManagerImpl* pImpl = chroma_cast<ChromaManagerImpl>(GetChromaManager());
    Clear();
    Keyboard::CUSTOM_EFFECT_TYPE effect = {};
    if (m_nFrame > 0xfffffff)
        m_nFrame = 0;
    m_nPattern = 0;
    switch (pImpl->GetColorMode())
    {
    case 30:
    case 40:
        m_nPattern = 1;
        break;
    case 50:
        m_nPattern = 2;
        break;
    case 60:
        m_nPattern = 3;
        break;
    case 70:
    case 80:
        m_nPattern = 6;
        break;
    case 90:
        m_nPattern = 4;
        break;
    case 100:
    case 110:
        m_nPattern = 5;
        break;
    default:
        m_nPattern = 0;
        break;
    }
    for (int col = 0; col < Keyboard::MAX_COLUMN; col++)
    {
        for (int row = 0; row < Keyboard::MAX_ROW; row++)
            effect.Color[row][col] = GetPatternColor(col, row, pImpl->GetColor(1), pImpl->GetColor(2));
    }
    RZEFFECTID effectId;
    if (pImpl->CreateKeyboardEffect(Keyboard::CHROMA_CUSTOM, &effect, &effectId) == 0)
    {
        m_effects.push_back(effectId);
        m_nFrame++;
    }
}

// @0x140a96680
void ChromaEffectLoading::Play()
{
    Create();
    if (m_effects.empty())
        return;
    GetChromaManager()->SetEffect(m_effects[0]);
}

// @0x140a96710
DWORD ChromaEffectLoading::GetInterval()
{
    if (m_nPattern == 5 || m_nPattern == 1)
        return 200;
    return 50;
}

// @0x140a96740
COLORREF ChromaEffectLoading::GetPatternColor(int x, int y, COLORREF back, COLORREF fore)
{
    int nCol = m_nFrame % Keyboard::MAX_COLUMN;
    int nRow = m_nFrame % Keyboard::MAX_ROW;
    if (m_nPattern == 0)
    {
        if (nCol == x || nCol == x + 1 || nCol == x - 1)
            return fore;
    }
    else if (m_nPattern == 1)
    {
        if (nRow == y)
            return fore;
    }
    else if (m_nPattern == 4)
    {
        nCol = Keyboard::MAX_COLUMN - nCol - 1;
        if (nCol == x || nCol == x + 1 || nCol == x - 1)
            return fore;
    }
    else if (m_nPattern == 5)
    {
        if (Keyboard::MAX_ROW - nRow - 1 == y)
            return fore;
    }
    else if (m_nPattern == 6)
    {
        nCol = nCol % (Keyboard::MAX_COLUMN / 2);
        if (nCol + Keyboard::MAX_COLUMN / 2 == x || Keyboard::MAX_COLUMN / 2 - nCol - 1 == x)
            return fore;
    }
    else if (m_nPattern == 2)
    {
        nCol = m_nFrame % (Keyboard::MAX_COLUMN + Keyboard::MAX_ROW);
        if (x + y == nCol || x + y + 1 == nCol || x + y - 1 == nCol)
            return fore;
    }
    else if (m_nPattern == 3)
    {
        nCol = Keyboard::MAX_COLUMN - m_nFrame % (Keyboard::MAX_COLUMN + Keyboard::MAX_ROW) - 1;
        if (x - y == nCol || x - y - 1 == nCol || x - y + 1 == nCol)
            return fore;
    }
    return back;
}

// ================================================================================================================
// ChromaEffectLogo

// @0x140a969e0
ChromaEffectLogo::ChromaEffectLogo()
{
    m_nFrame = 0;
}

// @0x140a96a20
ChromaEffectLogo::~ChromaEffectLogo()
{
}

// @0x140a96a50
void ChromaEffectLogo::Create()
{
    Clear();
    Keyboard::CUSTOM_EFFECT_TYPE effect = {};
    IChromaManager* pManager = GetChromaManager();
    RZEFFECTID effectId;
    pManager->CreateKeyboardEffect(Keyboard::CHROMA_NONE, NULL, &effectId);
    m_effects.push_back(effectId);
    for (int row = 0; row < Keyboard::MAX_ROW; row++)
    {
        for (int col = 0; col < Keyboard::MAX_COLUMN; col++)
        {
            if (row == 0)
            {
                effect.Color[row][col] = RGB(255, 0, 0);
            }
            else if (col < 18)
            {
                effect.Color[row][col] = RGB(200, 200, 200);
            }
            else if (col >= 18 && col < 21)
            {
                if (row == 1 || row == 3 || row == 5 || (row == 2 && col == 20) || (row == 4 && col == 18))
                    effect.Color[row][col] = RGB(255, 100, 0);
            }
        }
        if (pManager->CreateKeyboardEffect(Keyboard::CHROMA_CUSTOM, &effect, &effectId) == 0)
            m_effects.push_back(effectId);
    }
}

// @0x140a96c30
void ChromaEffectLogo::Play()
{
    if (GetChromaManager()->GetState() != STATE_LOGIN)
        m_nFrame = m_effects.size() - 1;
    ChromaEffectBase::Play();
}

// @0x140a96cd0
DWORD ChromaEffectLogo::GetInterval()
{
    return 200;
}

// ================================================================================================================
// ChromaEffectPlaying

// @0x140a96ce0
ChromaEffectPlaying::ChromaEffectPlaying()
{
    memset(m_bPressed, 0, sizeof(m_bPressed));
    m_nMaxHp = 0;
    m_nHp = 0;
    m_nMaxSp = 0;
    m_nSp = 0;
    m_bFlash = false;
    m_effectId = GUID_NULL;
}

// @0x140a96de0
ChromaEffectPlaying::~ChromaEffectPlaying()
{
    if (m_effectId != GUID_NULL)
        GetChromaManager()->DeleteEffect(m_effectId);
}

// @0x140a96eb0
void ChromaEffectPlaying::SetHp(unsigned nHp, unsigned nMaxHp)
{
    if (m_nHp != 0 && m_nMaxHp != 0 && nMaxHp != 0 && nHp < m_nHp)
    {
        m_bFlash = true;
        ChromaManagerImpl* pImpl = dynamic_cast<ChromaManagerImpl*>(GetChromaManager());
        if (pImpl)
            pImpl->AddLinkFlag(ChromaLinkEffect::FLAG_HIT);
    }
    m_nMaxHp = nMaxHp;
    m_nHp = nHp;
}

// @0x140a96f60
void ChromaEffectPlaying::SetSp(unsigned nSp, unsigned nMaxSp)
{
    m_nMaxSp = nMaxSp;
    m_nSp = nSp;
}

// @0x140a96f90
void ChromaEffectPlaying::StartCooldown(int nSlot, int a2, __int64 a3, float fTime)
{
    if (nSlot < 0 || nSlot >= COOLDOWN_COUNT)
        return;
    if (fTime > 0.0f)
        m_cooldowns[nSlot].Start(fTime);
}

// @0x140a97000
void ChromaEffectPlaying::ResetCooldown(int nSlot)
{
    if (nSlot < 0 || nSlot >= COOLDOWN_COUNT)
        return;
    m_cooldowns[nSlot].Reset();
}

// @0x140a97050
void ChromaEffectPlaying::PressSkill(int nSkill)
{
    ChromaManagerImpl* pImpl = chroma_cast<ChromaManagerImpl>(GetChromaManager());
    if (pImpl)
    {
        for (int nKey = 1; nKey < KEY_COUNT; nKey++)
        {
            if (nSkill == pImpl->GetKeySkill(nKey))
                m_bPressed[nKey] = true;
        }
    }
}

// @0x140a970d0
void ChromaEffectPlaying::PressKey(const CStringW& strName)
{
    ChromaManagerImpl* pImpl = chroma_cast<ChromaManagerImpl>(GetChromaManager());
    if (pImpl)
    {
        if (strName.CompareNoCase(L"esc") == 0)
            m_bPressed[1] = true;              // DIK_ESCAPE
        else if (strName.CompareNoCase(L"enter") == 0)
            m_bPressed[0x1c] = true;           // DIK_RETURN
    }
}

// @0x140a97160
void ChromaEffectPlaying::ResetKeys()
{
    memset(m_bPressed, 0, sizeof(m_bPressed));
}

// @0x140a97190
COLORREF ChromaEffectPlaying::GetSkillColor(int nSkill)
{
    if (nSkill >= 500001 && nSkill <= 500025)
    {
        nSkill -= 500001;
        if (m_cooldowns[nSkill].IsActive())
        {
            if (m_cooldowns[nSkill].IsExpired())
                return RGB(255, 255, 255);
            float fProgress = m_cooldowns[nSkill].GetProgress();
            return RGB(fProgress * 200.0f, fProgress * 200.0f, fProgress * 200.0f);
        }
        return m_keyColor;
    }
    else if (nSkill >= 200001 && nSkill <= 200004)
    {
        return m_keyColor;
    }
    return m_backColor;
}

// @0x140a97300
void ChromaEffectPlaying::Create()
{
    m_nFrame = (m_nFrame == 0);
    ChromaManagerImpl* pImpl = dynamic_cast<ChromaManagerImpl*>(GetChromaManager());
    if (pImpl)
    {
        m_keyColor = pImpl->GetColor(1);
        m_blinkColor = pImpl->GetColor(2);
        m_backColor = pImpl->GetColor(0);
        Keyboard::CUSTOM_KEY_EFFECT_TYPE effect = {};
        for (int nKey = 1; nKey < KEY_COUNT; nKey++)
        {
            if (m_bPressed[nKey])
            {
                int nRzKey = pImpl->GetKeyboardKey(nKey);
                if (nRzKey != -1)
                {
                    if (m_nFrame % 2 == 0)
                        effect.Key[HIBYTE(nRzKey)][LOBYTE(nRzKey)] = m_keyColor | 0x01000000;
                    else
                        effect.Key[HIBYTE(nRzKey)][LOBYTE(nRzKey)] = m_blinkColor | 0x01000000;
                }
            }
            else
            {
                int nSkill = pImpl->GetKeySkill(nKey);
                if (nSkill > 0)
                {
                    int nRzKey = pImpl->GetKeyboardKey(nKey);
                    COLORREF color;
                    if (nRzKey != -1 && m_backColor != (color = GetSkillColor(nSkill)))
                        effect.Key[HIBYTE(nRzKey)][LOBYTE(nRzKey)] = color | 0x01000000;
                }
            }
        }
        if (m_nMaxHp != 0)
        {
            unsigned nCount = (m_nHp << 3) / m_nMaxHp;
            for (int i = 0; i < 8; i++)
            {
                if (i < (int)nCount)
                    effect.Key[0][LOBYTE(i + 3)] = pImpl->GetColor(3) | 0x01000000;
                else
                    effect.Key[0][LOBYTE(i + 3)] = m_backColor | 0x01000000;
            }
        }
        if (m_nMaxSp != 0)
        {
            unsigned nCount = (m_nSp * 7) / m_nMaxSp;
            for (int i = 0; i < 7; i++)
            {
                if (i < (int)nCount)
                    effect.Key[0][LOBYTE(i + 11)] = pImpl->GetColor(4) | 0x01000000;
                else
                    effect.Key[0][LOBYTE(i + 11)] = m_backColor | 0x01000000;
            }
        }
        bool bLowHp = false;
        if (m_nFrame % 2 == 1 && m_nMaxHp != 0 && m_nHp != 0)
        {
            pImpl->RemoveLinkFlag(ChromaLinkEffect::FLAG_LOW_HP);
            if ((float)m_nHp / (float)m_nMaxHp < 0.3f)
            {
                bLowHp = true;
                pImpl->AddLinkFlag(ChromaLinkEffect::FLAG_LOW_HP);
            }
        }
        if (bLowHp || m_bFlash)
        {
            for (unsigned row = 0; row < Keyboard::MAX_ROW; row++)
            {
                for (unsigned col = 0; col < Keyboard::MAX_COLUMN; col++)
                    effect.Color[(int)row][(int)col] = RGB(255, 0, 0);
            }
            m_bFlash = false;
        }
        IChromaManager* pManager = GetChromaManager();
        if (m_effectId != GUID_NULL)
            pManager->ReserveDeleteEffect(m_effectId);
        if (pManager->CreateKeyboardEffect(Keyboard::CHROMA_CUSTOM_KEY, &effect, &m_effectId) != 0)
            m_effectId = GUID_NULL;
    }
}

// @0x140a979f0
void ChromaEffectPlaying::Play()
{
    Create();
    if (m_effectId != GUID_NULL)
        GetChromaManager()->SetEffect(m_effectId);
}

// @0x140a985e0
DWORD ChromaEffectPlaying::GetInterval()
{
    return 200;
}

// @0x140a98650
bool ChromaEffectPlaying::Cooldown::IsExpired()
{
    CHROMA_ASSERT_H(35, m_fStartTime <= GetCurrentTick());
    if (m_dwDuration == 0)
        return true;
    if (m_fStartTime + m_dwDuration > GetCurrentTick())
        return false;
    Reset();
    return true;
}

// @0x140a986d0
float ChromaEffectPlaying::Cooldown::GetProgress()
{
    CHROMA_ASSERT_H(46, m_fStartTime <= GetCurrentTick());
    if (m_dwDuration == 0)
        return 1.0f;
    return (float)(GetCurrentTick() - m_fStartTime) / (float)m_dwDuration;
}

// @0x140a98750
void ChromaEffectPlaying::Cooldown::Start(float fSecond)
{
    m_fStartTime = GetCurrentTick();
    m_dwDuration = FUN_14028d260(fSecond);
}

// ================================================================================================================
// ChromaEffectResurrection

// @0x140a9a4b0
ChromaEffectResurrection::ChromaEffectResurrection()
{
    m_nFrame = 0;
    m_n34 = 0;
    m_nCenter = 0x409;
}

// @0x140a9a510
ChromaEffectResurrection::~ChromaEffectResurrection()
{
}

// @0x140a9a540
void ChromaEffectResurrection::OnEnter(int nPrevState)
{
    ChromaEffectBase::OnEnter(nPrevState);
    m_nFrame = 0;
}

// @0x140a9a580
void ChromaEffectResurrection::Create()
{
    Clear();
    IChromaManager* pManager = GetChromaManager();
    Keyboard::CUSTOM_EFFECT_TYPE effect = {};
    int nRadius = m_nFrame - 2;
    int nCount = 0;
    for (int row = 0; row < Keyboard::MAX_ROW; row++)
    {
        for (int col = 0; col < Keyboard::MAX_COLUMN; col++)
        {
            int nDistance = (int)sqrt(pow((float)row - (float)HIBYTE(m_nCenter), 2) + pow((float)col - (float)LOBYTE(m_nCenter), 2));
            if (nRadius < nDistance)
            {
                effect.Color[row][col] = pManager->GetColor(5);
                nCount++;
            }
            else if (nRadius == nDistance)
            {
                effect.Color[row][col] = pManager->GetColor(6);
                nCount++;
            }
            else
            {
                effect.Color[row][col] = pManager->GetColor(7);
            }
        }
    }
    RZEFFECTID effectId;
    if (pManager->CreateKeyboardEffect(Keyboard::CHROMA_CUSTOM, &effect, &effectId) == 0)
    {
        m_effects.push_back(effectId);
        m_nFrame++;
    }
    if (nCount == 0)
        pManager->SetState(STATE_PLAYING);
}

// @0x140a9a800
void ChromaEffectResurrection::Play()
{
    Create();
    if (m_effects.empty())
        return;
    GetChromaManager()->SetEffect(m_effects[0]);
}

// ================================================================================================================
// ChromaEffectRipple

// @0x140a9a8d0
ChromaEffectRipple::ChromaEffectRipple()
{
    m_nFrame = 0;
    m_nReturnState = -1;
    m_nFieldType = 0;
    m_nRepeat = 0;
}

// @0x140a9a940
ChromaEffectRipple::~ChromaEffectRipple()
{
}

// @0x140a9a970
void ChromaEffectRipple::OnEnter(int nPrevState)
{
    ChromaEffectBase::OnEnter(nPrevState);
    m_nFrame = 0;
    m_nRepeat = 3;
    m_nReturnState = nPrevState;
}

// @0x140a9a9c0
void ChromaEffectRipple::Create()
{
    Clear();
    Keyboard::CUSTOM_EFFECT_TYPE effect = {};
    ChromaManagerImpl* pImpl = chroma_cast<ChromaManagerImpl>(GetChromaManager());
    for (int row = 0; row < Keyboard::MAX_ROW; row++)
    {
        COLORREF color = pImpl->GetColor(9);
        if (row == (int)(Keyboard::MAX_ROW - m_nFrame))
            color = pImpl->GetColor(10);
        else if (row > (int)(Keyboard::MAX_ROW - m_nFrame))
            color = pImpl->GetColor(11);
        for (int col = 0; col < Keyboard::MAX_COLUMN; col++)
            effect.Color[row][col] = color;
    }
    RZEFFECTID effectId;
    if (pImpl->CreateKeyboardEffect(Keyboard::CHROMA_CUSTOM, &effect, &effectId) == 0)
        m_effects.push_back(effectId);
    if (m_nFrame++ >= 7)
    {
        m_nFrame = 0;
        if (--m_nRepeat <= 0)
            pImpl->SetStateDirect(m_nReturnState);
    }
}

// @0x140a9ac20
void ChromaEffectRipple::OnFieldChanged(unsigned short nFieldType)
{
    ChromaManagerImpl* pImpl = chroma_cast<ChromaManagerImpl>(GetChromaManager());
    int nState = pImpl->GetState();
    if (nFieldType != 0 && m_nFieldType != 0 && m_nFieldType != nFieldType && (nState == STATE_PLAYING || nState == STATE_TALKING))
    {
        pImpl->SetState(STATE_RIPPLE);
        pImpl->AddLinkFlag(ChromaLinkEffect::FLAG_RAINBOW);
    }
    m_nFieldType = nFieldType;
}

// @0x140a9ad10
void ChromaEffectRipple::Play()
{
    Create();
    if (m_effects.empty())
        return;
    GetChromaManager()->SetEffect(m_effects[0]);
}

// ================================================================================================================
// ChromaEffectSurviveWinner

// @0x140a9ade0
ChromaEffectSurviveWinner::ChromaEffectSurviveWinner()
{
    m_nFrame = 0;
}

// @0x140a9ae20
ChromaEffectSurviveWinner::~ChromaEffectSurviveWinner()
{
}

// @0x140a9ae50
void ChromaEffectSurviveWinner::OnEnter(int nPrevState)
{
    ChromaEffectBase::OnEnter(nPrevState);
    m_nFrame = 0;
}

// @0x140a9ae90
void ChromaEffectSurviveWinner::Create()
{
    Clear();
    IChromaManager* pManager = GetChromaManager();
    Keyboard::WAVE_EFFECT_TYPE effect = {};
    effect.Direction = Keyboard::WAVE_EFFECT_TYPE::DIRECTION_LEFT_TO_RIGHT;
    RZEFFECTID effectId;
    if (pManager->CreateKeyboardEffect(Keyboard::CHROMA_WAVE, &effect, &effectId) == 0)
        m_effects.push_back(effectId);
}

// @0x140a9af40
void ChromaEffectSurviveWinner::Play()
{
    if (m_effects.empty())
        Create();
    if (m_effects.empty())
        return;
    if (m_nFrame == 0)
        GetChromaManager()->SetEffect(m_effects[0]);
    if (m_nFrame++ >= 50)
        GetChromaManager()->SetState(STATE_PLAYING);
}

// @0x140a9b080
DWORD ChromaEffectSurviveWinner::GetInterval()
{
    return 100;
}

// ================================================================================================================
// ChromaEffectTalking

// @0x140a9b090
ChromaEffectTalking::ChromaEffectTalking()
{
    m_nFrame = 0;
}

// @0x140a9b0d0
ChromaEffectTalking::~ChromaEffectTalking()
{
}

// @0x140a9b100
void ChromaEffectTalking::Create()
{
    ChromaManagerImpl* pImpl = chroma_cast<ChromaManagerImpl>(GetChromaManager());
    if (!pImpl)
        return;
    Clear();
    Keyboard::CUSTOM_KEY_EFFECT_TYPE effect = {};
    int nRzKey = pImpl->GetKeyboardKey(1);
    if (nRzKey != -1)
        effect.Key[HIBYTE(nRzKey)][LOBYTE(nRzKey)] = pImpl->GetColor(1) | 0x01000000;
    for (int nFrame = 0; nFrame < 2; nFrame++)
    {
        for (int nKey = 1; nKey < ChromaManagerImpl::KEY_SKILL_COUNT; nKey++)
        {
            int nSkill = pImpl->GetKeySkill(nKey);
            if (nSkill == 300002)
            {
                nRzKey = pImpl->GetKeyboardKey(nKey);
                if (nRzKey != -1)
                {
                    if (nFrame == 0)
                        effect.Key[HIBYTE(nRzKey)][LOBYTE(nRzKey)] = pImpl->GetColor(1) | 0x01000000;
                    else
                        effect.Key[HIBYTE(nRzKey)][LOBYTE(nRzKey)] = pImpl->GetColor(2) | 0x01000000;
                }
            }
        }
        RZEFFECTID effectId;
        if (pImpl->CreateKeyboardEffect(Keyboard::CHROMA_CUSTOM_KEY, &effect, &effectId) == 0)
            m_effects.push_back(effectId);
    }
}

// @0x140a9b410
DWORD ChromaEffectTalking::GetInterval()
{
    return 200;
}

// ================================================================================================================
// ChromaLinkEffect

// @0x140a9b420
ChromaLinkEffect::ChromaLinkEffect()
{
    m_effectId = GUID_NULL;
    m_nFlags = 0;
    m_dwNextTick = 0;
    m_nFrame = 0;
}

// @0x140a9b470
ChromaLinkEffect::~ChromaLinkEffect()
{
    Delete();
}

// @0x140a9b4a0
void ChromaLinkEffect::Update()
{
    DWORD dwNow = GetCurrentTick();
    if (dwNow >= m_dwNextTick)
    {
        Create();
        if (m_effectId != GUID_NULL)
            GetChromaManager()->SetEffect(m_effectId);
        m_dwNextTick = dwNow + GetInterval();
    }
}

// @0x140a9b550
void ChromaLinkEffect::Delete()
{
    if (m_effectId != GUID_NULL)
    {
        GetChromaManager()->DeleteEffect(m_effectId);
        m_effectId = GUID_NULL;
    }
}

// @0x140a9b5d0
void ChromaLinkEffect::AddFlag(unsigned nFlag)
{
    if (nFlag == 0)
    {
        m_nFlags = 0;
        return;
    }
    if (nFlag == FLAG_RAINBOW)
        m_nFrame = 0;
    else if (nFlag == FLAG_HIT && (m_nFlags & FLAG_HIT) == 0 && m_nFrame % 2 != 0)
        m_nFrame++;
    m_nFlags |= nFlag;
}

// @0x140a9b660
void ChromaLinkEffect::RemoveFlag(unsigned nFlag)
{
    m_nFlags &= ~nFlag;
}

// @0x140a9b690
void ChromaLinkEffect::Create()
{
    ChromaManagerImpl* pImpl = chroma_cast<ChromaManagerImpl>(GetChromaManager());
    Delete();
    ChromaLink::STATIC_EFFECT_TYPE effect = {};
    if (m_nFlags & FLAG_HIT)
    {
        if (m_nFrame % 2 == 0)
        {
            effect.Color = pImpl->GetColor(14);
        }
        else
        {
            effect.Color = pImpl->GetColor(0);
            RemoveFlag(FLAG_HIT);
        }
    }
    else if (m_nFlags & FLAG_RAINBOW)
    {
        CreateRainbow();
        return;
    }
    else if (m_nFlags & FLAG_LOW_HP)
    {
        int nLevel = abs((int)m_nFrame % 20 - 10);
        effect.Color = RGB(nLevel * 255 / 10, 0, 0);
    }
    else
    {
        effect.Color = pImpl->GetColor(1);
    }
    if (pImpl->CreateChromaLinkEffect(ChromaLink::CHROMA_STATIC, &effect, &m_effectId) != 0)
        m_effectId = GUID_NULL;
    m_nFrame++;
}

// @0x140a9b860
void ChromaLinkEffect::CreateRainbow()
{
    ChromaLink::CUSTOM_EFFECT_TYPE effect = {};
    switch ((m_nFrame / 2) % ChromaLink::MAX_LEDS + 1)
    {
    case 5:
        effect.Color[4] = RGB(0, 0, 200);
    case 4:
        effect.Color[3] = RGB(0, 180, 180);
    case 3:
        effect.Color[2] = RGB(0, 200, 0);
    case 2:
        effect.Color[1] = RGB(180, 180, 0);
    case 1:
        effect.Color[0] = RGB(200, 0, 0);
    }
    IChromaManager* pManager = GetChromaManager();
    if (pManager->CreateChromaLinkEffect(ChromaLink::CHROMA_CUSTOM, &effect, &m_effectId) != 0)
        m_effectId = GUID_NULL;
    m_nFrame++;
    if (m_nFrame >= ChromaLink::MAX_LEDS * 6 + 6)
        RemoveFlag(FLAG_RAINBOW);
}

// @0x140a9b9e0
DWORD ChromaLinkEffect::GetInterval()
{
    return 100;
}

// ================================================================================================================
// ChromaManagerImpl

// @0x140a9b9f0
ChromaManagerImpl::~ChromaManagerImpl()
{
}

// @0x140a9ba90
void ChromaManagerImpl::SetState(int nState)
{
    if (nState == m_nState)
        return;
    if (m_nState == STATE_RIPPLE && nState != STATE_RIPPLE && m_effects[STATE_RIPPLE] != NULL)
    {
        static_cast<ChromaEffectRipple*>(m_effects[STATE_RIPPLE])->SetReturnState(nState);
        return;
    }
    if (nState < STATE_COUNT && nState > -1 && m_effects[nState] != NULL)
        m_effects[nState]->OnEnter(m_nState);
    if (nState == -1)
    {
        if (m_nPrevState != -1)
            m_nState = m_nPrevState;
    }
    else
    {
        if (nState == STATE_PLAYING)
        {
            if (CStateService::GetInstance()->FUN_1417e2610() != 0x620000c)
                nState = STATE_CHARACTER;
        }
        m_nPrevState = m_nState;
        m_nState = nState;
    }
    ResetKeys(true);
}

// @0x140a9bbe0
void ChromaManagerImpl::SetStateDirect(int nState)
{
    m_nPrevState = -1;
    m_nState = nState;
}

// @0x140a9bc10
void ChromaManagerImpl::vfunc_oa0_3(int nHp, int nMaxHp)
{
    if (m_effects[STATE_PLAYING] != NULL)
        static_cast<ChromaEffectPlaying*>(m_effects[STATE_PLAYING])->SetHp(nHp, nMaxHp);
}

// @0x140a9bc70
void ChromaManagerImpl::vfunc_oa0_4(int nSp, int nMaxSp)
{
    if (m_effects[STATE_PLAYING] != NULL)
        static_cast<ChromaEffectPlaying*>(m_effects[STATE_PLAYING])->SetSp(nSp, nMaxSp);
}

// @0x140a9bcd0
void ChromaManagerImpl::vfunc_oa0_9(unsigned short nFieldType)
{
    if (m_effects[STATE_RIPPLE] != NULL)
        static_cast<ChromaEffectRipple*>(m_effects[STATE_RIPPLE])->OnFieldChanged(nFieldType);
}

// @0x140a9bd20
void ChromaManagerImpl::SetCooldown(int nSlot, int a2, __int64 a3, float fTime)
{
    if (m_effects[STATE_PLAYING] != NULL)
        static_cast<ChromaEffectPlaying*>(m_effects[STATE_PLAYING])->StartCooldown(nSlot, a2, a3, fTime);
}

// @0x140a9bd90
void ChromaManagerImpl::ResetCooldown(int nSlot)
{
    if (m_effects[STATE_PLAYING] != NULL)
        static_cast<ChromaEffectPlaying*>(m_effects[STATE_PLAYING])->ResetCooldown(nSlot);
}

// @0x140a9bde0
void ChromaManagerImpl::Pause()
{
    m_bPaused = true;
}

// @0x140a9be00
void ChromaManagerImpl::Resume()
{
    m_bPaused = false;
    RefreshKeys();
}

// @0x140a9be40
int ChromaManagerImpl::GetKeySkill(int nKey)
{
    if (nKey <= 0 || nKey >= KEY_SKILL_COUNT)
        return 0;
    return m_keySkills[nKey];
}

// @0x140a9be80
void ChromaManagerImpl::RefreshKeySkills()
{
    if (m_bPaused)
        return;
    memset(m_keySkills, 0, sizeof(m_keySkills));
    CKeyTable* pKeyTable = CKeyTable::GetInstance();
    for (int nKey = 1; nKey < KEY_SKILL_COUNT; nKey++)
    {
        unsigned __int64 nSkill = pKeyTable->FUN_14142d190(nKey);
        if (nSkill != 0 && nSkill <= 500025)
        {
            int nId = (int)nSkill;
            m_keySkills[nKey] = nId;
        }
    }
}

// @0x140a9bf30
int ChromaManagerImpl::GetKeyboardKey(int nKey)
{
    std::map<int, Keyboard::RZKEY>::iterator it = m_keyboardKeys.find(nKey);
    if (it != m_keyboardKeys.end())
        return (*it).second;
    return -1;
}

// @0x140a9bfb0
void ChromaManagerImpl::DeleteReservedEffects()
{
    for (std::vector<RZEFFECTID>::iterator it = m_reservedDeletes.begin(); it != m_reservedDeletes.end(); ++it)
        DeleteEffect(*it);
    m_reservedDeletes.clear();
}

// @0x140a9c070
void ChromaManagerImpl::ReserveDeleteEffect(RZEFFECTID effectId)
{
    m_reservedDeletes.push_back(effectId);
}

// @0x140a9c0b0
void ChromaManagerImpl::OnKeySkill(int nSkill, bool bKeep)
{
    if (m_effects[STATE_PLAYING] != NULL)
    {
        static_cast<ChromaEffectPlaying*>(m_effects[STATE_PLAYING])->PressSkill(nSkill);
        m_bKeyLock = bKeep || m_bKeyLock;
    }
}

// @0x140a9c140
void ChromaManagerImpl::OnKeyName(const CStringW& strName)
{
    if (m_effects[STATE_PLAYING] != NULL)
    {
        static_cast<ChromaEffectPlaying*>(m_effects[STATE_PLAYING])->PressKey(strName);
        m_bKeyLock = true;
    }
}

// @0x140a9c1a0
void ChromaManagerImpl::ResetKeys(bool bForce)
{
    if (!m_bKeyLock || bForce)
    {
        m_bKeyLock = false;
        if (m_effects[STATE_PLAYING] != NULL)
            static_cast<ChromaEffectPlaying*>(m_effects[STATE_PLAYING])->ResetKeys();
    }
}

// @0x140a9c210
void ChromaManagerImpl::RefreshKeys()
{
    ResetKeys(true);
    RefreshKeySkills();
}

// @0x140a9c260
void ChromaManagerImpl::SetColorMode(int nMode)
{
    m_nColorMode = nMode;
    m_pColorTable->SetLevel(nMode);
    if (nMode == 0)
    {
        SetState(STATE_LOGO);
    }
    else
    {
        if (CUIService::GetInstance()->FUN_141adc890((eUIClassID)0x4eea) || CUIService::GetInstance()->FUN_141adc890((eUIClassID)0x4ef1))
            SetState(STATE_CHARACTER);
    }
}

// @0x140a9c320
void ChromaManagerImpl::AddLinkFlag(unsigned nFlag)
{
    m_linkEffect.AddFlag(nFlag);
}

// @0x140a9c350
void ChromaManagerImpl::RemoveLinkFlag(unsigned nFlag)
{
    m_linkEffect.RemoveFlag(nFlag);
}

// @0x140a9c380
COLORREF ChromaManagerImpl::GetColor(int nIndex)
{
    return m_pColorTable->GetColor(nIndex);
}

// @0x140a9c3b0
RZRESULT ChromaManagerImpl::Init()
{
    if (m_Init == NULL)
        return RZRESULT_INVALID;
    RZRESULT result = m_Init();
    m_bInitialized = true;
    return result;
}

// @0x140a9c3f0
RZRESULT ChromaManagerImpl::UnInit()
{
    if (m_UnInit == NULL)
        return RZRESULT_INVALID;
    RZRESULT result = m_UnInit();
    m_bInitialized = false;
    return result;
}

// @0x140a9c430
RZRESULT ChromaManagerImpl::CreateEffect(RZDEVICEID DeviceId, ChromaSDK::EFFECT_TYPE Effect, PRZPARAM pParam, RZEFFECTID* pEffectId)
{
    if (m_CreateEffect == NULL)
        return RZRESULT_INVALID;
    return m_CreateEffect(DeviceId, Effect, pParam, pEffectId);
}

// @0x140a9c4a0
RZRESULT ChromaManagerImpl::CreateChromaLinkEffect(int Effect, PRZPARAM pParam, RZEFFECTID* pEffectId)
{
    if (m_CreateChromaLinkEffect == NULL)
        return RZRESULT_INVALID;
    return m_CreateChromaLinkEffect(Effect, pParam, pEffectId);
}

// @0x140a9c4f0
RZRESULT ChromaManagerImpl::CreateHeadsetEffect(int Effect, PRZPARAM pParam, RZEFFECTID* pEffectId)
{
    if (m_CreateHeadsetEffect == NULL)
        return RZRESULT_INVALID;
    return m_CreateHeadsetEffect(Effect, pParam, pEffectId);
}

// @0x140a9c540
RZRESULT ChromaManagerImpl::CreateKeyboardEffect(int Effect, PRZPARAM pParam, RZEFFECTID* pEffectId)
{
    if (m_CreateKeyboardEffect == NULL)
        return RZRESULT_INVALID;
    return m_CreateKeyboardEffect(Effect, pParam, pEffectId);
}

// @0x140a9c590
RZRESULT ChromaManagerImpl::CreateKeypadEffect(int Effect, PRZPARAM pParam, RZEFFECTID* pEffectId)
{
    if (m_CreateKeypadEffect == NULL)
        return RZRESULT_INVALID;
    return m_CreateKeypadEffect(Effect, pParam, pEffectId);
}

// @0x140a9c5e0
RZRESULT ChromaManagerImpl::CreateMouseEffect(int Effect, PRZPARAM pParam, RZEFFECTID* pEffectId)
{
    if (m_CreateMouseEffect == NULL)
        return RZRESULT_INVALID;
    return m_CreateMouseEffect(Effect, pParam, pEffectId);
}

// @0x140a9c630
RZRESULT ChromaManagerImpl::CreateMousepadEffect(int Effect, PRZPARAM pParam, RZEFFECTID* pEffectId)
{
    if (m_CreateMousepadEffect == NULL)
        return RZRESULT_INVALID;
    return m_CreateMousepadEffect(Effect, pParam, pEffectId);
}

// @0x140a9c680
RZRESULT ChromaManagerImpl::SetEffect(RZEFFECTID EffectId)
{
    if (m_SetEffect == NULL)
        return RZRESULT_INVALID;
    return m_SetEffect(EffectId);
}

// @0x140a9c6e0
RZRESULT ChromaManagerImpl::DeleteEffect(RZEFFECTID EffectId)
{
    if (m_DeleteEffect == NULL)
        return RZRESULT_INVALID;
    return m_DeleteEffect(EffectId);
}

// @0x140a9c740
ChromaManagerImpl::ChromaManagerImpl()
{
    m_bKeyLock = false;
    m_hModule = NULL;
    m_pColorTable = NULL;
    m_bPaused = false;
    m_nColorMode = 0;
    UnloadSDK();
    m_nState = STATE_LOGIN;
    m_hThread = 0;
    memset(m_effects, 0, sizeof(m_effects));
    memset(m_keySkills, 0, sizeof(m_keySkills));
}

// @0x140a9c890
void ChromaManagerImpl::SetModule(HMODULE hModule)
{
    m_hModule = hModule;
}

// @0x140a9c8b0
bool ChromaManagerImpl::IsInitialized()
{
    return m_bInitialized;
}

// @0x140a9c8d0
bool ChromaManagerImpl::Initialize()
{
    if (!LoadSDK())
        return false;
    if (Init() != RZRESULT_SUCCESS)
        return false;
    m_pColorTable = new ChromaColorTable();
    InitKeyMap();
    m_effects[STATE_PLAYING] = new ChromaEffectPlaying();
    m_effects[STATE_LOADING] = new ChromaEffectLoading();
    m_effects[STATE_LOGO] = new ChromaEffectLogo();
    m_effects[STATE_LOGIN] = m_effects[STATE_LOGO];
    m_effects[STATE_TALKING] = new ChromaEffectTalking();
    m_effects[STATE_RIPPLE] = new ChromaEffectRipple();
    m_effects[STATE_CHARACTER] = new ChromaEffectCharacter();
    m_effects[STATE_DEATH] = new ChromaEffectDeath();
    m_effects[STATE_RESURRECTION] = new ChromaEffectResurrection();
    m_effects[STATE_DCLEAR] = new ChromaEffectDClear();
    m_effects[STATE_SURVIVE_WINNER] = new ChromaEffectSurviveWinner();
    m_effects[STATE_CINEMATIC] = new ChromaEffectCinematic();
    UIStatusEventDispatcher::GetInstance()->FUN_141b0cd00(this);
    m_hThread = _beginthreadex(NULL, 0, ThreadProc, this, 0, NULL);
    return true;
}

// @0x140a9cee0
void ChromaManagerImpl::Finalize()
{
    UIStatusEventDispatcher::GetInstance()->FUN_141b0cd90(this);
    if (m_bInitialized)
    {
        m_bInitialized = false;
        if (m_hThread != 0 && WaitForSingleObject((HANDLE)m_hThread, 1000) != WAIT_OBJECT_0)
            TerminateThread((HANDLE)m_hThread, 0);
        for (int i = 0; i < STATE_COUNT; i++)
        {
            if (m_effects[i] != NULL && i != STATE_LOGIN && i != STATE_CHARACTER)
                delete m_effects[i];
            m_effects[i] = NULL;
        }
        SetChromaManager(NULL);
        UnInit();
    }
    UnloadSDK();
    delete this;
}

// @0x140a9d090
int ChromaManagerImpl::GetMaxLeds(const EChromaSDKDevice1DEnum& device)
{
    switch (device)
    {
    case EChromaSDKDevice1DEnum::DE_ChromaLink:
        return ChromaLink::MAX_LEDS;
    case EChromaSDKDevice1DEnum::DE_Headset:
        return Headset::MAX_LEDS;
    case EChromaSDKDevice1DEnum::DE_Mousepad:
        return Mousepad::MAX_LEDS;
    }
    return 0;
}

// @0x140a9d0e0
int ChromaManagerImpl::GetMaxRow(const EChromaSDKDevice2DEnum& device)
{
    switch (device)
    {
    case EChromaSDKDevice2DEnum::DE_Keyboard:
        return Keyboard::MAX_ROW;
    case EChromaSDKDevice2DEnum::DE_Keypad:
        return Keypad::MAX_ROW;
    case EChromaSDKDevice2DEnum::DE_Mouse:
        return Mouse::MAX_ROW;
    }
    return 0;
}

// @0x140a9d130
int ChromaManagerImpl::GetMaxColumn(const EChromaSDKDevice2DEnum& device)
{
    switch (device)
    {
    case EChromaSDKDevice2DEnum::DE_Keyboard:
        return Keyboard::MAX_COLUMN;
    case EChromaSDKDevice2DEnum::DE_Keypad:
        return Keypad::MAX_COLUMN;
    case EChromaSDKDevice2DEnum::DE_Mouse:
        return Mouse::MAX_COLUMN;
    }
    return 0;
}

// @0x140a9d180
std::vector<COLORREF> ChromaManagerImpl::CreateColors1D(const EChromaSDKDevice1DEnum& device)
{
    std::vector<COLORREF> colors = std::vector<COLORREF>();
    int elements = GetMaxLeds(device);
    COLORREF black = RGB(0, 0, 0);
    for (int i = 0; i < elements; ++i)
        colors.push_back(black);
    return colors;
}

// @0x140a9d230
std::vector<FChromaSDKColors> ChromaManagerImpl::CreateColors2D(const EChromaSDKDevice2DEnum& device)
{
    std::vector<FChromaSDKColors> result = std::vector<FChromaSDKColors>();
    int maxRow = GetMaxRow(device);
    int maxColumn = GetMaxColumn(device);
    COLORREF black = RGB(0, 0, 0);
    for (int i = 0; i < maxRow; ++i)
    {
        FChromaSDKColors row = FChromaSDKColors();
        for (int j = 0; j < maxColumn; ++j)
            row.Colors.push_back(black);
        result.push_back(row);
    }
    return result;
}

// @0x140a9d360
std::vector<COLORREF> ChromaManagerImpl::CreateRandomColors1D(const EChromaSDKDevice1DEnum& device)
{
    std::vector<COLORREF> colors = std::vector<COLORREF>();
    int elements = GetMaxLeds(device);
    for (int i = 0; i < elements; ++i)
    {
        int red = rand() % 256;
        int green = rand() % 256;
        int blue = rand() % 256;
        COLORREF color = RGB(red, green, blue);
        colors.push_back(color);
    }
    return colors;
}

// @0x140a9d480
std::vector<FChromaSDKColors> ChromaManagerImpl::CreateRandomColors2D(const EChromaSDKDevice2DEnum& device)
{
    std::vector<FChromaSDKColors> result = std::vector<FChromaSDKColors>();
    int maxRows = GetMaxRow(device);
    int maxColumns = GetMaxColumn(device);
    for (int i = 0; i < maxRows; ++i)
    {
        FChromaSDKColors row = FChromaSDKColors();
        for (int j = 0; j < maxColumns; ++j)
        {
            int red = rand() % 256;
            int green = rand() % 256;
            int blue = rand() % 256;
            COLORREF color = RGB(red, green, blue);
            row.Colors.push_back(color);
        }
        result.push_back(row);
    }
    return result;
}

// @0x140a9d640
const std::vector<FChromaSDKColors>& ChromaManagerImpl::SetMouseLEDColor(const EChromaSDKMouseLED& led, COLORREF color, std::vector<FChromaSDKColors>& colors)
{
    int maxRow = Mouse::MAX_ROW;
    int maxColumn = Mouse::MAX_COLUMN;
    if (maxRow != colors.size() || colors.size() == 0 || maxColumn != colors[0].Colors.size())
        return colors;
    Mouse::RZLED2 rzled = m_mouseLeds[led];
    colors[HIBYTE(rzled)].Colors[LOBYTE(rzled)] = color;
    return colors;
}

// @0x140a9d730
FChromaSDKEffectResult ChromaManagerImpl::CreateEffect(RZDEVICEID deviceId, ChromaSDK::EFFECT_TYPE effect, const std::vector<FChromaSDKColors>& colors)
{
    FChromaSDKEffectResult data = FChromaSDKEffectResult();

    CUSTOM_EFFECT_TYPE pParam = {};
    for (int i = 0; i < MAX_ROW; i++)
    {
        const FChromaSDKColors& row = colors[i];
        for (int j = 0; j < MAX_COLUMN; ++j)
            pParam.Color[i][j] = row.Colors[j];
    }

    RZRESULT result = 0;
    RZEFFECTID effectId = RZEFFECTID();
    result = CreateEffect(deviceId, ChromaSDK::CHROMA_CUSTOM, &pParam, &effectId);
    data.EffectId.Data = effectId;
    data.Result = result;
    return data;
}

// @0x140a9d8e0
FChromaSDKEffectResult ChromaManagerImpl::CreateEffectNone1D(const EChromaSDKDevice1DEnum& device)
{
    FChromaSDKEffectResult data = FChromaSDKEffectResult();

    RZRESULT result = 0;
    RZEFFECTID effectId = RZEFFECTID();
    switch (device)
    {
    case EChromaSDKDevice1DEnum::DE_ChromaLink:
        result = CreateChromaLinkEffect(ChromaLink::CHROMA_NONE, NULL, &effectId);
        break;
    case EChromaSDKDevice1DEnum::DE_Headset:
        result = CreateHeadsetEffect(Headset::CHROMA_NONE, NULL, &effectId);
        break;
    case EChromaSDKDevice1DEnum::DE_Mousepad:
        result = CreateMousepadEffect(Mousepad::CHROMA_NONE, NULL, &effectId);
        break;
    }
    data.EffectId.Data = effectId;
    data.Result = result;
    return data;
}

// @0x140a9da60
FChromaSDKEffectResult ChromaManagerImpl::CreateEffectNone2D(const EChromaSDKDevice2DEnum& device)
{
    FChromaSDKEffectResult data = FChromaSDKEffectResult();

    int result = 0;
    RZEFFECTID effectId = RZEFFECTID();
    switch (device)
    {
    case EChromaSDKDevice2DEnum::DE_Keyboard:
        result = CreateKeyboardEffect(Keyboard::CHROMA_NONE, NULL, &effectId);
        break;
    case EChromaSDKDevice2DEnum::DE_Keypad:
        result = CreateKeypadEffect(Keypad::CHROMA_NONE, NULL, &effectId);
        break;
    case EChromaSDKDevice2DEnum::DE_Mouse:
        result = CreateMouseEffect(Mouse::CHROMA_NONE, NULL, &effectId);
        break;
    }
    data.EffectId.Data = effectId;
    data.Result = result;
    return data;
}

// @0x140a9dbe0
FChromaSDKEffectResult ChromaManagerImpl::CreateEffectStatic1D(const EChromaSDKDevice1DEnum& device, COLORREF color)
{
    FChromaSDKEffectResult data = FChromaSDKEffectResult();

    RZRESULT result = 0;
    RZEFFECTID effectId = RZEFFECTID();
    switch (device)
    {
    case EChromaSDKDevice1DEnum::DE_ChromaLink:
    {
        ChromaLink::STATIC_EFFECT_TYPE pParam = {};
        pParam.Color = color;
        result = CreateChromaLinkEffect(ChromaLink::CHROMA_STATIC, &pParam, &effectId);
    }
    break;
    case EChromaSDKDevice1DEnum::DE_Headset:
    {
        Headset::STATIC_EFFECT_TYPE pParam = {};
        pParam.Color = color;
        result = CreateHeadsetEffect(Headset::CHROMA_STATIC, &pParam, &effectId);
    }
    break;
    case EChromaSDKDevice1DEnum::DE_Mousepad:
    {
        Mousepad::STATIC_EFFECT_TYPE pParam = {};
        pParam.Color = color;
        result = CreateMousepadEffect(Mousepad::CHROMA_STATIC, &pParam, &effectId);
    }
    break;
    }
    data.EffectId.Data = effectId;
    data.Result = result;
    return data;
}

// @0x140a9ddd0
FChromaSDKEffectResult ChromaManagerImpl::CreateEffectStatic2D(const EChromaSDKDevice2DEnum& device, COLORREF color)
{
    FChromaSDKEffectResult data = FChromaSDKEffectResult();

    RZRESULT result = 0;
    RZEFFECTID effectId = RZEFFECTID();
    switch (device)
    {
    case EChromaSDKDevice2DEnum::DE_Keyboard:
    {
        Keyboard::STATIC_EFFECT_TYPE pParam = {};
        pParam.Color = color;
        result = CreateKeyboardEffect(Keyboard::CHROMA_STATIC, &pParam, &effectId);
    }
    break;
    case EChromaSDKDevice2DEnum::DE_Keypad:
    {
        Keypad::STATIC_EFFECT_TYPE pParam = {};
        pParam.Color = color;
        result = CreateKeypadEffect(Keypad::CHROMA_STATIC, &pParam, &effectId);
    }
    break;
    case EChromaSDKDevice2DEnum::DE_Mouse:
    {
        Mouse::STATIC_EFFECT_TYPE pParam = {};
        pParam.Color = color;
        pParam.LEDId = Mouse::RZLED_ALL;
        result = CreateMouseEffect(Mouse::CHROMA_STATIC, &pParam, &effectId);
    }
    break;
    }
    data.EffectId.Data = effectId;
    data.Result = result;
    return data;
}

// @0x140a9dfd0
FChromaSDKEffectResult ChromaManagerImpl::CreateEffectCustom1D(const EChromaSDKDevice1DEnum& device, const std::vector<COLORREF>& colors)
{
    FChromaSDKEffectResult data = FChromaSDKEffectResult();

    RZRESULT result = 0;
    RZEFFECTID effectId = RZEFFECTID();
    int maxLeds = 0;
    switch (device)
    {
    case EChromaSDKDevice1DEnum::DE_ChromaLink:
    {
        maxLeds = ChromaLink::MAX_LEDS;
        if (maxLeds != colors.size())
            break;
        ChromaLink::CUSTOM_EFFECT_TYPE pParam = {};
        for (int i = 0; i < maxLeds; i++)
            pParam.Color[i] = colors[i];
        result = CreateChromaLinkEffect(ChromaLink::CHROMA_CUSTOM, &pParam, &effectId);
    }
    break;
    case EChromaSDKDevice1DEnum::DE_Headset:
    {
        maxLeds = Headset::MAX_LEDS;
        if (maxLeds != colors.size())
            break;
        Headset::CUSTOM_EFFECT_TYPE pParam = {};
        for (int i = 0; i < maxLeds; i++)
            pParam.Color[i] = colors[i];
        result = CreateHeadsetEffect(Headset::CHROMA_CUSTOM, &pParam, &effectId);
    }
    break;
    case EChromaSDKDevice1DEnum::DE_Mousepad:
    {
        maxLeds = Mousepad::MAX_LEDS;
        if (maxLeds != colors.size())
            break;
        Mousepad::CUSTOM_EFFECT_TYPE pParam = {};
        for (int i = 0; i < maxLeds; i++)
            pParam.Color[i] = colors[i];
        result = CreateMousepadEffect(Mousepad::CHROMA_CUSTOM, &pParam, &effectId);
    }
    break;
    }
    data.EffectId.Data = effectId;
    data.Result = result;
    return data;
}

// @0x140a9e300
FChromaSDKEffectResult ChromaManagerImpl::CreateEffectCustom2D(const EChromaSDKDevice2DEnum& device, const std::vector<FChromaSDKColors>& colors)
{
    FChromaSDKEffectResult data = FChromaSDKEffectResult();

    RZRESULT result = 0;
    RZEFFECTID effectId = RZEFFECTID();
    int maxRow = 0;
    int maxColumn = 0;
    switch (device)
    {
    case EChromaSDKDevice2DEnum::DE_Keyboard:
    {
        maxRow = Keyboard::MAX_ROW;
        maxColumn = Keyboard::MAX_COLUMN;
        if (maxRow != colors.size() || colors.size() == 0 || maxColumn != colors[0].Colors.size())
            break;
        Keyboard::CUSTOM_EFFECT_TYPE pParam = {};
        for (int i = 0; i < maxRow; i++)
        {
            const FChromaSDKColors& row = colors[i];
            for (int j = 0; j < maxColumn; j++)
                pParam.Color[i][j] = row.Colors[j];
        }
        result = CreateKeyboardEffect(Keyboard::CHROMA_CUSTOM, &pParam, &effectId);
    }
    break;
    case EChromaSDKDevice2DEnum::DE_Keypad:
    {
        maxRow = Keypad::MAX_ROW;
        maxColumn = Keypad::MAX_COLUMN;
        if (maxRow != colors.size() || colors.size() == 0 || maxColumn != colors[0].Colors.size())
            break;
        Keypad::CUSTOM_EFFECT_TYPE pParam = {};
        for (int i = 0; i < maxRow; i++)
        {
            const FChromaSDKColors& row = colors[i];
            for (int j = 0; j < maxColumn; j++)
                pParam.Color[i][j] = row.Colors[j];
        }
        result = CreateKeypadEffect(Keypad::CHROMA_CUSTOM, &pParam, &effectId);
    }
    break;
    case EChromaSDKDevice2DEnum::DE_Mouse:
    {
        maxRow = Mouse::MAX_ROW;
        maxColumn = Mouse::MAX_COLUMN;
        if (maxRow != colors.size() || colors.size() == 0 || maxColumn != colors[0].Colors.size())
            break;
        Mouse::CUSTOM_EFFECT_TYPE2 pParam = {};
        for (int i = 0; i < maxRow; i++)
        {
            const FChromaSDKColors& row = colors[i];
            for (int j = 0; j < maxColumn; j++)
                pParam.Color[i][j] = row.Colors[j];
        }
        result = CreateMouseEffect(Mouse::CHROMA_CUSTOM2, &pParam, &effectId);
    }
    break;
    }
    data.EffectId.Data = effectId;
    data.Result = result;
    return data;
}

// @0x140a9e7f0
FChromaSDKEffectResult ChromaManagerImpl::CreateEffectKeyboardCustom2D(const std::vector<FChromaSDKColors>& colors)
{
    FChromaSDKEffectResult data = FChromaSDKEffectResult();

    RZRESULT result = 0;
    RZEFFECTID effectId = RZEFFECTID();
    int maxRow = Keyboard::MAX_ROW;
    int maxColumn = Keyboard::MAX_COLUMN;
    if (maxRow != colors.size() || colors.size() == 0 || maxColumn != colors[0].Colors.size())
    {
    }
    else
    {
        Keyboard::CUSTOM_KEY_EFFECT_TYPE pParam = {};
        for (int i = 0; i < maxRow; i++)
        {
            const FChromaSDKColors& row = colors[i];
            for (int j = 0; j < maxColumn; j++)
                pParam.Key[i][j] = row.Colors[j];
        }
        result = CreateKeyboardEffect(Keyboard::CHROMA_CUSTOM_KEY, &pParam, &effectId);
    }
    data.EffectId.Data = effectId;
    data.Result = result;
    return data;
}

// @0x140a9e9e0
RZRESULT ChromaManagerImpl::PlayEffect(RZEFFECTID EffectId)
{
    RZRESULT result = SetEffect(EffectId);
    return result;
}

// @0x140a9ea40
RZRESULT ChromaManagerImpl::RemoveEffect(RZEFFECTID EffectId)
{
    RZRESULT result = DeleteEffect(EffectId);
    return result;
}

// @0x140a9eaa0
unsigned __stdcall ChromaManagerImpl::ThreadProc(void* pParam)
{
    ChromaManagerImpl* pManager = (ChromaManagerImpl*)pParam;
    ChromaEffectCharacter* pCharacter = chroma_cast<ChromaEffectCharacter>(pManager->m_effects[STATE_CHARACTER]);
    while (pManager->IsInitialized())
    {
        pManager->Tick();
        pCharacter->UpdateMouse();
        pManager->DeleteReservedEffects();
        Sleep(20);
    }
    _endthreadex(0);
    return 0;
}

// @0x140a9eb40
void ChromaManagerImpl::Tick()
{
    if (m_nState >= STATE_COUNT || m_nState <= -1)
        return;
    ChromaEffectBase* pEffect = m_effects[m_nState];
    if (pEffect)
        pEffect->Update();
    m_linkEffect.Update();
}

// @0x140a9ebb0
bool ChromaManagerImpl::LoadSDK()
{
    try
    {
        m_bInitialized = false;
        if (m_hModule == NULL)
        {
            m_hModule = LoadLibraryA("RzChromaSDK64.dll");
            if (m_hModule == NULL)
                throw "RzChromaSDK64.dll";
        }
        m_Init = (INIT)GetProcAddress(m_hModule, "Init");
        if (m_Init == NULL)
            throw "Init";
        m_UnInit = (UNINIT)GetProcAddress(m_hModule, "UnInit");
        if (m_Init == NULL)
            throw "UnInit";
        m_QueryDevice = (QUERYDEVICE)GetProcAddress(m_hModule, "QueryDevice");
        if (m_Init == NULL)
            throw "UnInit";
        m_UnInit = (UNINIT)GetProcAddress(m_hModule, "UnInit");
        if (m_Init == NULL)
            throw "UnInit";
        m_CreateChromaLinkEffect = (CREATEDEVICEEFFECT)GetProcAddress(m_hModule, "CreateChromaLinkEffect");
        if (m_Init == NULL)
            throw "UnInit";
        m_CreateHeadsetEffect = (CREATEDEVICEEFFECT)GetProcAddress(m_hModule, "CreateHeadsetEffect");
        if (m_Init == NULL)
            throw "UnInit";
        m_CreateKeyboardEffect = (CREATEDEVICEEFFECT)GetProcAddress(m_hModule, "CreateKeyboardEffect");
        if (m_Init == NULL)
            throw "UnInit";
        m_CreateMouseEffect = (CREATEDEVICEEFFECT)GetProcAddress(m_hModule, "CreateMouseEffect");
        if (m_Init == NULL)
            throw "UnInit";
        m_CreateMousepadEffect = (CREATEDEVICEEFFECT)GetProcAddress(m_hModule, "CreateMousepadEffect");
        if (m_Init == NULL)
            throw "UnInit";
        m_CreateKeypadEffect = (CREATEDEVICEEFFECT)GetProcAddress(m_hModule, "CreateKeypadEffect");
        if (m_Init == NULL)
            throw "UnInit";
        m_CreateEffect = (CREATEEFFECT)GetProcAddress(m_hModule, "CreateEffect");
        if (m_Init == NULL)
            throw "UnInit";
        m_SetEffect = (SETEFFECT)GetProcAddress(m_hModule, "SetEffect");
        if (m_Init == NULL)
            throw "UnInit";
        m_DeleteEffect = (DELETEEFFECT)GetProcAddress(m_hModule, "DeleteEffect");
        if (m_Init == NULL)
            throw "UnInit";
    }
    catch (...)
    {
        return false;
    }
    return true;
}

// @0x140a9f080
void ChromaManagerImpl::InitKeyMap()
{
    m_keyboardKeys[0x01] = Keyboard::RZKEY_ESC;
    m_keyboardKeys[0x3B] = Keyboard::RZKEY_F1;
    m_keyboardKeys[0x3C] = Keyboard::RZKEY_F2;
    m_keyboardKeys[0x3D] = Keyboard::RZKEY_F3;
    m_keyboardKeys[0x3E] = Keyboard::RZKEY_F4;
    m_keyboardKeys[0x3F] = Keyboard::RZKEY_F5;
    m_keyboardKeys[0x40] = Keyboard::RZKEY_F6;
    m_keyboardKeys[0x41] = Keyboard::RZKEY_F7;
    m_keyboardKeys[0x42] = Keyboard::RZKEY_F8;
    m_keyboardKeys[0x43] = Keyboard::RZKEY_F9;
    m_keyboardKeys[0x44] = Keyboard::RZKEY_F10;
    m_keyboardKeys[0x55] = Keyboard::RZKEY_F11;
    m_keyboardKeys[0x56] = Keyboard::RZKEY_F12;
    m_keyboardKeys[0x29] = Keyboard::RZKEY_OEM_1;
    m_keyboardKeys[0x02] = Keyboard::RZKEY_1;
    m_keyboardKeys[0x03] = Keyboard::RZKEY_2;
    m_keyboardKeys[0x04] = Keyboard::RZKEY_3;
    m_keyboardKeys[0x05] = Keyboard::RZKEY_4;
    m_keyboardKeys[0x06] = Keyboard::RZKEY_5;
    m_keyboardKeys[0x07] = Keyboard::RZKEY_6;
    m_keyboardKeys[0x08] = Keyboard::RZKEY_7;
    m_keyboardKeys[0x09] = Keyboard::RZKEY_8;
    m_keyboardKeys[0x0A] = Keyboard::RZKEY_9;
    m_keyboardKeys[0x0B] = Keyboard::RZKEY_0;
    m_keyboardKeys[0x1E] = Keyboard::RZKEY_A;
    m_keyboardKeys[0x30] = Keyboard::RZKEY_B;
    m_keyboardKeys[0x2E] = Keyboard::RZKEY_C;
    m_keyboardKeys[0x20] = Keyboard::RZKEY_D;
    m_keyboardKeys[0x12] = Keyboard::RZKEY_E;
    m_keyboardKeys[0x21] = Keyboard::RZKEY_F;
    m_keyboardKeys[0x22] = Keyboard::RZKEY_G;
    m_keyboardKeys[0x23] = Keyboard::RZKEY_H;
    m_keyboardKeys[0x17] = Keyboard::RZKEY_I;
    m_keyboardKeys[0x24] = Keyboard::RZKEY_J;
    m_keyboardKeys[0x25] = Keyboard::RZKEY_K;
    m_keyboardKeys[0x26] = Keyboard::RZKEY_L;
    m_keyboardKeys[0x32] = Keyboard::RZKEY_M;
    m_keyboardKeys[0x31] = Keyboard::RZKEY_N;
    m_keyboardKeys[0x18] = Keyboard::RZKEY_O;
    m_keyboardKeys[0x19] = Keyboard::RZKEY_P;
    m_keyboardKeys[0x10] = Keyboard::RZKEY_Q;
    m_keyboardKeys[0x13] = Keyboard::RZKEY_R;
    m_keyboardKeys[0x1F] = Keyboard::RZKEY_S;
    m_keyboardKeys[0x14] = Keyboard::RZKEY_T;
    m_keyboardKeys[0x16] = Keyboard::RZKEY_U;
    m_keyboardKeys[0x2F] = Keyboard::RZKEY_V;
    m_keyboardKeys[0x11] = Keyboard::RZKEY_W;
    m_keyboardKeys[0x2D] = Keyboard::RZKEY_X;
    m_keyboardKeys[0x15] = Keyboard::RZKEY_Y;
    m_keyboardKeys[0x2C] = Keyboard::RZKEY_Z;
    m_keyboardKeys[0x52] = Keyboard::RZKEY_NUMPAD0;
    m_keyboardKeys[0x4F] = Keyboard::RZKEY_NUMPAD1;
    m_keyboardKeys[0x50] = Keyboard::RZKEY_NUMPAD2;
    m_keyboardKeys[0x51] = Keyboard::RZKEY_NUMPAD3;
    m_keyboardKeys[0x4B] = Keyboard::RZKEY_NUMPAD4;
    m_keyboardKeys[0x4C] = Keyboard::RZKEY_NUMPAD5;
    m_keyboardKeys[0x4D] = Keyboard::RZKEY_NUMPAD6;
    m_keyboardKeys[0x47] = Keyboard::RZKEY_NUMPAD7;
    m_keyboardKeys[0x48] = Keyboard::RZKEY_NUMPAD8;
    m_keyboardKeys[0x49] = Keyboard::RZKEY_NUMPAD9;
    m_keyboardKeys[0x74] = Keyboard::RZKEY_NUMPAD_DIVIDE;
    m_keyboardKeys[0x37] = Keyboard::RZKEY_NUMPAD_MULTIPLY;
    m_keyboardKeys[0x4A] = Keyboard::RZKEY_NUMPAD_SUBTRACT;
    m_keyboardKeys[0x4E] = Keyboard::RZKEY_NUMPAD_ADD;
    m_keyboardKeys[0x6A] = Keyboard::RZKEY_NUMPAD_ENTER;
    m_keyboardKeys[0x53] = Keyboard::RZKEY_NUMPAD_DECIMAL;
    m_keyboardKeys[0x46] = Keyboard::RZKEY_SCROLL;
    m_keyboardKeys[0x77] = Keyboard::RZKEY_PAUSE;
    m_keyboardKeys[0x80] = Keyboard::RZKEY_INSERT;
    m_keyboardKeys[0x78] = Keyboard::RZKEY_HOME;
    m_keyboardKeys[0x7A] = Keyboard::RZKEY_PAGEUP;
    m_keyboardKeys[0x81] = Keyboard::RZKEY_DELETE;
    m_keyboardKeys[0x7D] = Keyboard::RZKEY_END;
    m_keyboardKeys[0x7F] = Keyboard::RZKEY_PAGEDOWN;
    m_keyboardKeys[0x79] = Keyboard::RZKEY_UP;
    m_keyboardKeys[0x7B] = Keyboard::RZKEY_LEFT;
    m_keyboardKeys[0x7E] = Keyboard::RZKEY_DOWN;
    m_keyboardKeys[0x7C] = Keyboard::RZKEY_RIGHT;
    m_keyboardKeys[0x0F] = Keyboard::RZKEY_TAB;
    m_keyboardKeys[0x3A] = Keyboard::RZKEY_CAPSLOCK;
    m_keyboardKeys[0x0E] = Keyboard::RZKEY_BACKSPACE;
    m_keyboardKeys[0x1C] = Keyboard::RZKEY_ENTER;
    m_keyboardKeys[0x1D] = Keyboard::RZKEY_LCTRL;
    m_keyboardKeys[0x82] = Keyboard::RZKEY_LWIN;
    m_keyboardKeys[0x38] = Keyboard::RZKEY_LALT;
    m_keyboardKeys[0x39] = Keyboard::RZKEY_SPACE;
    m_keyboardKeys[0x76] = Keyboard::RZKEY_RALT;
    m_keyboardKeys[0x6B] = Keyboard::RZKEY_RCTRL;
    m_keyboardKeys[0x2A] = Keyboard::RZKEY_LSHIFT;
    m_keyboardKeys[0x36] = Keyboard::RZKEY_RSHIFT;
    m_keyboardKeys[0x0C] = Keyboard::RZKEY_OEM_2;
    m_keyboardKeys[0x0D] = Keyboard::RZKEY_OEM_3;
    m_keyboardKeys[0x1A] = Keyboard::RZKEY_OEM_4;
    m_keyboardKeys[0x1B] = Keyboard::RZKEY_OEM_5;
    m_keyboardKeys[0x2B] = Keyboard::RZKEY_OEM_6;
    m_keyboardKeys[0x27] = Keyboard::RZKEY_OEM_7;
    m_keyboardKeys[0x28] = Keyboard::RZKEY_OEM_8;
    m_keyboardKeys[0x33] = Keyboard::RZKEY_OEM_9;
    m_keyboardKeys[0x34] = Keyboard::RZKEY_OEM_10;
    m_keyboardKeys[0x35] = Keyboard::RZKEY_OEM_11;
    m_mouseLeds[EChromaSDKMouseLED::ML_SCROLLWHEEL] = Mouse::RZLED2_SCROLLWHEEL;
    m_mouseLeds[EChromaSDKMouseLED::ML_LOGO] = Mouse::RZLED2_LOGO;
    m_mouseLeds[EChromaSDKMouseLED::ML_BACKLIGHT] = Mouse::RZLED2_BACKLIGHT;
    m_mouseLeds[EChromaSDKMouseLED::ML_LEFT_SIDE1] = Mouse::RZLED2_LEFT_SIDE1;
    m_mouseLeds[EChromaSDKMouseLED::ML_LEFT_SIDE2] = Mouse::RZLED2_LEFT_SIDE2;
    m_mouseLeds[EChromaSDKMouseLED::ML_LEFT_SIDE3] = Mouse::RZLED2_LEFT_SIDE3;
    m_mouseLeds[EChromaSDKMouseLED::ML_LEFT_SIDE4] = Mouse::RZLED2_LEFT_SIDE4;
    m_mouseLeds[EChromaSDKMouseLED::ML_LEFT_SIDE5] = Mouse::RZLED2_LEFT_SIDE5;
    m_mouseLeds[EChromaSDKMouseLED::ML_LEFT_SIDE6] = Mouse::RZLED2_LEFT_SIDE6;
    m_mouseLeds[EChromaSDKMouseLED::ML_LEFT_SIDE7] = Mouse::RZLED2_LEFT_SIDE7;
    m_mouseLeds[EChromaSDKMouseLED::ML_BOTTOM1] = Mouse::RZLED2_BOTTOM1;
    m_mouseLeds[EChromaSDKMouseLED::ML_BOTTOM2] = Mouse::RZLED2_BOTTOM2;
    m_mouseLeds[EChromaSDKMouseLED::ML_BOTTOM3] = Mouse::RZLED2_BOTTOM3;
    m_mouseLeds[EChromaSDKMouseLED::ML_BOTTOM4] = Mouse::RZLED2_BOTTOM4;
    m_mouseLeds[EChromaSDKMouseLED::ML_BOTTOM5] = Mouse::RZLED2_BOTTOM5;
    m_mouseLeds[EChromaSDKMouseLED::ML_RIGHT_SIDE1] = Mouse::RZLED2_RIGHT_SIDE1;
    m_mouseLeds[EChromaSDKMouseLED::ML_RIGHT_SIDE2] = Mouse::RZLED2_RIGHT_SIDE2;
    m_mouseLeds[EChromaSDKMouseLED::ML_RIGHT_SIDE3] = Mouse::RZLED2_RIGHT_SIDE3;
    m_mouseLeds[EChromaSDKMouseLED::ML_RIGHT_SIDE4] = Mouse::RZLED2_RIGHT_SIDE4;
    m_mouseLeds[EChromaSDKMouseLED::ML_RIGHT_SIDE5] = Mouse::RZLED2_RIGHT_SIDE5;
    m_mouseLeds[EChromaSDKMouseLED::ML_RIGHT_SIDE6] = Mouse::RZLED2_RIGHT_SIDE6;
    m_mouseLeds[EChromaSDKMouseLED::ML_RIGHT_SIDE7] = Mouse::RZLED2_RIGHT_SIDE7;
}

// @0x140aa0670
void ChromaManagerImpl::UnloadSDK()
{
    m_Init = NULL;
    m_UnInit = NULL;
    m_CreateEffect = NULL;
    m_CreateChromaLinkEffect = NULL;
    m_CreateHeadsetEffect = NULL;
    m_CreateKeyboardEffect = NULL;
    m_CreateKeypadEffect = NULL;
    m_CreateMouseEffect = NULL;
    m_CreateMousepadEffect = NULL;
    m_SetEffect = NULL;
    m_DeleteEffect = NULL;
    m_QueryDevice = NULL;
    if (m_hModule != NULL)
        FreeLibrary(m_hModule);
    if (m_pColorTable != NULL)
    {
        delete m_pColorTable;
        m_pColorTable = NULL;
    }
}

} // namespace ChromaSDK

// the plugin's out-of-line ChromaSDKPluginTypes.cpp members

// @0x140aaa620
ChromaSDK::FChromaSDKColorFrame1D::FChromaSDKColorFrame1D()
{
    Duration = 1.0f;
}

// @0x140aaa660
ChromaSDK::FChromaSDKColorFrame2D::FChromaSDKColorFrame2D()
{
    Duration = 1.0f;
}

namespace ChromaSDK {

// @0x140aaa6a0
void SetChromaManager(IChromaManager* pManager)
{
    g_pChromaManager = pManager;
    if (pManager == NULL)
        g_pChromaManager = &g_chromaManagerDummy;
}

// ================================================================================================================
// ChromaManagerDummy

// @0x140aaa6d0
ChromaManagerDummy::ChromaManagerDummy()
{
}

// @0x140aaa710
ChromaManagerDummy::~ChromaManagerDummy()
{
}

// @0x140aaa740
bool ChromaManagerDummy::Initialize()
{
    if (CFeatureManager::GetInstance()->FUN_14036d570(0xd5))
    {
        if (CGameOption::GetInstance()->FUN_140aaaa90()->m_bDisable)
            return false;
        HMODULE hModule = LoadLibraryA("RzChromaSDK64.dll");
        if (hModule != NULL)
        {
            ChromaManagerImpl* pImpl = new ChromaManagerImpl();
            pImpl->SetModule(hModule);
            if (pImpl->Initialize())
            {
                SetChromaManager(pImpl);
                return true;
            }
            delete pImpl;
            return false;
        }
    }
    return false;
}

} // namespace ChromaSDK

// @0x140aaaa90
Unk_GoChroma* CGameOption::FUN_140aaaa90()
{
    return &m_chroma;
}

// The second obj's copy of the header statics.
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_unk1402a9d70_2(17, 0.75f, 0.25f, 2.25f, 10);
