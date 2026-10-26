// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CInputKeyHandler (the debug-mode / key-binding gate in front of the
// input service) with its NotifyDebugMode notice and the TSingleton<CInputKeyHandler> glue. See ms2/placeholder/cinputkeyhandler.h.
// MS2-UNIT: unit_14116d540
// MS2-RANGE: 0x14116d540-0x14116e3f0 .text$mn
// MS2-PIN: ??1NotifyDebugMode@@UEAA@XZ 0x14116df30
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"

#include <new>

#include <NiAVObject.h>
#include <NiTexture.h>
#include <NiSourceTexture.h>
#include <NiTexturingProperty.h>
#include <NiStringExtraData.h>
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/ms2inputservice.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The notice posted when the debug mode toggles (the name virtual GetTypeName lives in another unit).
class NotifyDebugMode : public NotifyObject
{
public:
    NotifyDebugMode(bool bOn);                              // 0x14116ded0
    virtual ~NotifyDebugMode() = default;                   // 0x14116df30
    virtual CStringW GetTypeName();                             // 0x140db4c70
    bool m_bOn;                                             // +0x18
};
MS2_CHECK_SIZE(NotifyDebugMode, 0x20);

// ---- unit-local views of the exe objects and unrecovered callees --------------------------------------------------------

class Unk_KhUI { public: int FUN_141adbb00(); int FUN_141adbd10(); };   // CUIService
Unk_KhUI* FUN_1403ed2b0();
class Unk_KhCamera { public: bool FUN_140d07330(); };
Unk_KhCamera* FUN_140c8dac0();
class Unk_KhKeyBinds
{
public:
    int FUN_14142c270(int nSetting);
    int FUN_14142c4b0(int nSetting);
    int FUN_14142c540(int nSetting);
};
Unk_KhKeyBinds* FUN_1409331f0();
class Unk_KhGame { public: bool FUN_14036d570(int nId); };
Unk_KhGame* FUN_140166410();
class Unk_KhState { public: unsigned char* FUN_140a58500(); };
Unk_KhState* FUN_1409a8b10();
class Unk_KhNotices { public: void FUN_140da4fe0(MS2Ptr<NotifyObject> spNotify); };
Unk_KhNotices* FUN_140939a10();
MS2InputService* FUN_140a58540();                           // TSingleton<MS2InputService>::GetInstance
void FUN_1412751b0(const CStringW& text, int nType);        // chat/system line

class Unk_KhTextures { public: NiTexturePtr FUN_141552f90(CString strPath, char nFlags); };   // loads (and caches) a texture file
Unk_KhTextures* FUN_140a0afd0();
class Unk_KhSkinView { public: void FUN_141047900(); };
Unk_KhSkinView* FUN_140d89420(NiAVObject* pObject);

extern int DAT_143ab2914;                                   // the GM level
extern int DAT_143af7d40;                                   // input enabled

int FUN_14116e010(int nLevel);                               // 1 when 1 <= nLevel <= 100

// ---- CInputKeyHandler -----------------------------------------------------------------------------------------------------

// @0x14116d540
CInputKeyHandler::CInputKeyHandler()
{
    m_bDebugMode = false;
    m_bModifier1 = false;
    m_bModifier2 = false;
    m_b0b = false;
    m_b0c = false;
}

// @0x14116d5a0
CInputKeyHandler::~CInputKeyHandler()
{
}

// @0x14116d5d0
void CInputKeyHandler::SetDebugMode(bool bOn)
{
    if (bOn == true && DAT_143ab2914 < 50)
        return;
    {
        m_bDebugMode = bOn;
        CStringW strMsg;
        const wchar_t* pszState;
        if (IsDebugMode())
            pszState = L"On !! (command '/?' - help)";
        else
            pszState = L"Off";
        strMsg.Format(L"Debug Mode: %s", pszState);
        FUN_1412751b0(strMsg, 20);
        FUN_140939a10()->FUN_140da4fe0(MS2Ptr<NotifyObject>(new NotifyDebugMode(m_bDebugMode)));
    }
}
MS2_REPLACE_METHOD(0x14116D5D0, CInputKeyHandler, SetDebugMode, 317, 0x97A7D3E9);

// @0x14116d720
bool CInputKeyHandler::IsDebugMode()
{
    if (FUN_14116e010(DAT_143ab2914) != 0 && DAT_143ab2914 < 50)
        return false;
    return m_bDebugMode;
}
MS2_REPLACE_METHOD(0x14116D720, CInputKeyHandler, IsDebugMode, 51, 0xE6F88370);

// @0x14116d760
void CInputKeyHandler::SetModifier1(bool b)
{
    m_bModifier1 = b;
}
MS2_REPLACE_METHOD(0x14116D760, CInputKeyHandler, SetModifier1, 23, 0xF9F55C0C);

// @0x14116d780
void CInputKeyHandler::SetModifier2(bool b)
{
    m_bModifier2 = b;
}
MS2_REPLACE_METHOD(0x14116D780, CInputKeyHandler, SetModifier2, 23, 0x21F96C9B);

// @0x14116d7a0
bool CInputKeyHandler::FUN_14116d7a0(unsigned nMask)
{
    if (FUN_1403ed2b0()->FUN_141adbb00() != 0 && (nMask & 2) != 0)
        return true;
    if (FUN_140c8dac0()->FUN_140d07330() != 0 && (nMask & 4) != 0)
        return true;
    if (m_bModifier1 != false && (nMask & 1) != 0)
        return true;
    if (m_bModifier2 != false && (nMask & 8) != 0)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x14116D7A0, CInputKeyHandler, FUN_14116d7a0, 143, 0x00EC7853);

// @0x14116d840
bool CInputKeyHandler::FUN_14116d840()
{
    if (FUN_140a58540()->FUN_140d8ad60(1))
        return true;
    if (FUN_1409331f0()->FUN_14142c4b0(0x49409) != 0)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x14116D840, CInputKeyHandler, FUN_14116d840, 71, 0x5C1438AB);

// @0x14116d890
bool CInputKeyHandler::FUN_14116d890(bool bAlt)
{
    if (FUN_140a58540()->FUN_140d8ad60(0x1c))
        return true;
    if (FUN_1409331f0()->FUN_14142c4b0(0x49408) != 0)
        return true;
    if (FUN_140166410()->FUN_14036d570(0xb5) == true)
    {
        if (*FUN_1409a8b10()->FUN_140a58500() != 0)
        {
            if (FUN_1403ed2b0()->FUN_141adbb00() != 0)
                return false;
        }
    }
    if (bAlt != false)
    {
        if (FUN_1409331f0()->FUN_14142c4b0(0x493e2) != 0)
            return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x14116D890, CInputKeyHandler, FUN_14116d890, 180, 0x2308ADB8);

// @0x14116d950
bool CInputKeyHandler::FUN_14116d950(int nKey, bool bDebugOnly, int nLevel)
{
    if (bDebugOnly != false && IsDebugMode() == false)
        return false;
    if (DAT_143ab2914 < nLevel)
        return false;
    return FUN_140a58540()->FUN_140d8ac50(nKey, 0);
}
MS2_REPLACE_METHOD(0x14116D950, CInputKeyHandler, FUN_14116d950, 94, 0x1516CB0C);

// @0x14116d9c0
bool CInputKeyHandler::FUN_14116d9c0(int nKey, bool bDebugOnly, int nLevel)
{
    if (bDebugOnly != false && IsDebugMode() == false)
        return false;
    if (DAT_143ab2914 < nLevel)
        return false;
    return FUN_140a58540()->FUN_140d8ad60(nKey);
}
MS2_REPLACE_METHOD(0x14116D9C0, CInputKeyHandler, FUN_14116d9c0, 91, 0xDA608B14);

// @0x14116da30
bool CInputKeyHandler::FUN_14116da30(int nKey, bool bDebugOnly, int nLevel)
{
    if (bDebugOnly != false && IsDebugMode() == false)
        return false;
    if (DAT_143ab2914 < nLevel)
        return false;
    return FUN_140a58540()->FUN_140d8af70(nKey);
}
MS2_REPLACE_METHOD(0x14116DA30, CInputKeyHandler, FUN_14116da30, 91, 0x411CF2AC);

// @0x14116daa0
bool CInputKeyHandler::FUN_14116daa0(int nKey, bool bDebugOnly, int nLevel)
{
    if (bDebugOnly != false && IsDebugMode() == false)
        return false;
    if (DAT_143ab2914 < nLevel)
        return false;
    return FUN_140a58540()->FUN_140d8b010(nKey);
}
MS2_REPLACE_METHOD(0x14116DAA0, CInputKeyHandler, FUN_14116daa0, 91, 0x73C0F6D9);

// @0x14116db10
bool CInputKeyHandler::FUN_14116db10(int nKey, bool bDebugOnly, int nLevel)
{
    if (bDebugOnly != false && IsDebugMode() == false)
        return false;
    if (DAT_143ab2914 < nLevel)
        return false;
    return FUN_140a58540()->FUN_140d8b070(nKey);
}
MS2_REPLACE_METHOD(0x14116DB10, CInputKeyHandler, FUN_14116db10, 91, 0x03E62CD8);

// @0x14116db80
bool CInputKeyHandler::FUN_14116db80(int nKey, bool bDebugOnly, int nLevel)
{
    if (bDebugOnly != false && IsDebugMode() == false)
        return false;
    if (DAT_143ab2914 < nLevel)
        return false;
    return FUN_140a58540()->FUN_140d8b0d0(nKey);
}
MS2_REPLACE_METHOD(0x14116DB80, CInputKeyHandler, FUN_14116db80, 91, 0x69171645);

// @0x14116dbf0
bool CInputKeyHandler::FUN_14116dbf0(int* pnX, int* pnY, int* pnZ, bool bDebugOnly, int nLevel)
{
    if (bDebugOnly != false && IsDebugMode() == false)
        return false;
    if (DAT_143ab2914 < nLevel)
        return false;
    if (DAT_143af7d40 == 0)
        return false;
    if (FUN_1403ed2b0()->FUN_141adbd10() != 0)
    {
        FUN_140a58540()->FUN_140d8b130(pnX, pnY, pnZ);
        *pnZ = 0;
        return false;
    }
    return FUN_140a58540()->FUN_140d8b130(pnX, pnY, pnZ);
}
MS2_REPLACE_METHOD(0x14116DBF0, CInputKeyHandler, FUN_14116dbf0, 176, 0x7EBD267F);

// @0x14116dcb0
bool CInputKeyHandler::FUN_14116dcb0(int nSetting, bool bDebugOnly, int nLevel)
{
    if (bDebugOnly != false && IsDebugMode() == false)
        return false;
    if (DAT_143ab2914 < nLevel)
        return false;
    if (DAT_143af7d40 == 0)
        return false;
    if (FUN_1409331f0()->FUN_14142c270(nSetting) != 0)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x14116DCB0, CInputKeyHandler, FUN_14116dcb0, 114, 0x384BBBA6);

// @0x14116dd30
bool CInputKeyHandler::FUN_14116dd30(int nSetting, bool bDebugOnly, int nLevel)
{
    if (bDebugOnly != false && IsDebugMode() == false)
        return false;
    if (DAT_143ab2914 < nLevel)
        return false;
    if (DAT_143af7d40 == 0)
        return false;
    if (FUN_1409331f0()->FUN_14142c4b0(nSetting) != 0)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x14116DD30, CInputKeyHandler, FUN_14116dd30, 114, 0x662885F5);

// @0x14116ddb0
bool CInputKeyHandler::FUN_14116ddb0(int nSetting, bool bDebugOnly, int nLevel)
{
    if (bDebugOnly != false && IsDebugMode() == false)
        return false;
    if (DAT_143ab2914 < nLevel)
        return false;
    if (DAT_143af7d40 == 0)
        return false;
    if (FUN_1409331f0()->FUN_14142c540(nSetting) != 0)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x14116DDB0, CInputKeyHandler, FUN_14116ddb0, 114, 0xFBF30D0E);

// @0x14116de30
bool CInputKeyHandler::FUN_14116de30(int nKey)
{
    if (DAT_143af7d40 == 0)
        return false;
    FUN_140a58540()->FUN_140d8b200(nKey);
    return true;
}
MS2_REPLACE_METHOD(0x14116DE30, CInputKeyHandler, FUN_14116de30, 50, 0xF94EB644);

// @0x14116de70
bool CInputKeyHandler::FUN_14116de70(int nKey)
{
    FUN_140a58540()->FUN_140d8b250(nKey);
    return true;
}
MS2_REPLACE_METHOD(0x14116DE70, CInputKeyHandler, FUN_14116de70, 37, 0x37431F25);

// ---- NotifyDebugMode ----------------------------------------------------------------------------------------------------

// @0x14116ded0
NotifyDebugMode::NotifyDebugMode(bool bOn)
{
    m_bOn = bOn;
}

// ---- helpers ----------------------------------------------------------------------------------------------------------------

// @0x14116e010
int FUN_14116e010(int nLevel)
{
    if (nLevel >= 1 && nLevel <= 100)
        return 1;
    return 0;
}

// @0x14116e030
CStringA FUN_14116e030(void* pUnused)
{
    return "FA_Skin";
}

// @0x14116e080
// MS2-FUNCTIONAL: the exe calls NiFixedString ctor/dtor, GetExtraData, DynamicCast out of line and keeps its own temporaries; ours inlines them
// Reloads the original base / control textures that the skin replacement stored as string extra data on the object
// (extra data "OriginalBaseTexturePath" / "OriginalControlTexturePath"), puts them back into the texturing property
// and drops the extra data.
bool FUN_14116e080(NiAVObject* pObject)
{
    NiTexturingProperty* pTexturing = NiDynamicCast(NiTexturingProperty, pObject->GetProperty(NiProperty::TEXTURING));
    if (pTexturing == 0)
        return false;
    NiStringExtraData* pBase = NiDynamicCast(NiStringExtraData, pObject->GetExtraData(NiFixedString("OriginalBaseTexturePath")));
    if (pBase != 0)
    {
        NiTexturePtr spBase = FUN_140a0afd0()->FUN_141552f90(CString((const char*)pBase->GetValue()), 5);
        pTexturing->SetBaseTexture(spBase);
        pObject->RemoveExtraData(NiFixedString("OriginalBaseTexturePath"));
    }
    NiStringExtraData* pControl = NiDynamicCast(NiStringExtraData, pObject->GetExtraData(NiFixedString("OriginalControlTexturePath")));
    if (pControl != 0)
    {
        NiTexturePtr spControl = FUN_140a0afd0()->FUN_141552f90(CString((const char*)pControl->GetValue()), 5);
        NiTexturingProperty::ShaderMap* pMap = new (efd::MemHint(efd::MemHint::NONE))
            NiTexturingProperty::ShaderMap(spControl, 0, (NiTexturingProperty::ClampMode)3, (NiTexturingProperty::FilterMode)2, 0);
        pTexturing->SetShaderMap(0, pMap);
        pObject->RemoveExtraData(NiFixedString("OriginalControlTexturePath"));
    }
    pTexturing->SetShaderMap(1, 0);
    pTexturing->SetShaderMap(2, 0);
    pObject->UpdateProperties();
    FUN_140d89420(pObject)->FUN_141047900();
    return true;
}
