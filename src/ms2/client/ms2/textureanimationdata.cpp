// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Texture animations: see textureanimationdata.h.
// MS2-UNIT: ?\textureanimationdata.cpp
// MS2-RANGE: 0x141847510-0x14184b540 .text$mn
// MS2-PIN: ??1CTextureAnimationData@@UEAA@XZ 0x141849da0
// MS2-PIN: ??_GCTextureAnimationData@@UEAAPEAXI@Z 0x14184a090
// MS2-PIN: ??_GCTextureAnimation@@UEAAPEAXI@Z 0x14184a050
// MS2-PIN: ??_GUITextureDensityDialog@@UEAAPEAXI@Z 0x14184aff0
// MS2-PIN: ??_GTextureLayer@@UEAAPEAXI@Z 0x14184b3c0
// MS2-PIN: ??1TextureLayer@@UEAA@XZ 0x14184b370
// MS2-PIN: ??8?$SmartPointer@VTextureLayer@@@efd@@QEBA_NPEAVTextureLayer@@@Z 0x141849f00
//
// The unit boundaries of units.tsv are guesses: the seven .text$di initialisers between 0x14010db90 and 0x14010dd90
// belong to other objs (sort-name tables, TextureOverrideEffect's RTTI), not to this one.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\textureanimationdata.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "textureanimationdata.h"

#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/filepreload_1.h"
#include "ms2/client/ms2/postprocessing/postprocessingservice.h"
#include <NiActorManager.h>
#include <efd/MemoryDefines.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// The resource manager (singleton 0x140a0afd0): texture load by path.
class Unk_TexAnimResMgr
{
public:
    Unk_PPSmartC FUN_141552f90(CString strPath, int nFlags);                // load (cached) with the given flags
    Unk_PPSmartC FUN_141553eb0(CString strPath, void* pDefault);            // look up a loaded texture
};
Unk_TexAnimResMgr* FUN_140a0afd0();

CString FUN_140540050(const char* pszFormat, const CString& strArg);        // StringFormat with one string
CString FUN_140536a50(const char* pszFormat, const CString& strArg);        // StringFormat<CString>
int FUN_140873710(Unk_140165cf0* pElem, const char* pszName, int* pnOut);   // flag attribute
Unk_140165cf0* FUN_140168650(Unk_140165cf0* pElem, const char* pszName);    // NextSiblingElement

extern NiFixedString DAT_143ae51d8;                                         // the default target node name
const char* FUN_142087e50(NiFixedString* pName);                            // NiFixedString to char*

class Unk_TexAnimSvc { public: NiActorManager* FUN_140999440(const egf::EntityID& kId); };
Unk_TexAnimSvc* FUN_141b6f910();
NiObject* FUN_14107c930(NiObject* pRoot, const CString* pName);             // child node by name
NiObject* FUN_14098d8d0(const NiRTTI* pRTTI, NiObject* pObject);
extern const NiRTTI Unk_RenderObjectRTTI;                                   // 0x143afa7d0
class MyPC;
MyPC* FUN_140a53610(GameObject* pObject);                                   // efd::DynamicCast<MyPC>

class WorldService;
WorldService* FUN_1403ed2d0();
PostProcessingService* FUN_1409a8b20();

void FUN_1422bcce0(Scaleform::GFx::Value* pValue, bool b);
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x141847510
Unk_TextureFrame::Unk_TextureFrame()
{
    m_nDelay = 0;
}

// @0x141847560
void Unk_TextureFrame::FUN_141847560(Unk_140165cf0* pNode)
{
    FUN_1408733e0(pNode, "file", m_strFile);
    FUN_1408733e0(pNode, "control", m_strControl);
    FUN_1408731e0(pNode, "delay", m_nDelay);
}
MS2_REPLACE_METHOD(0x141847560, Unk_TextureFrame, FUN_141847560, 102, 0x6C83B0D1);

// @0x1418475d0
void Unk_TextureFrame::FUN_1418475d0(const CString& strDir, int nFlags)
{
    FUN_140a0afd0()->FUN_141552f90(FUN_141847960(strDir), nFlags);
    if (!m_strControl.IsEmpty())
        FUN_140a0afd0()->FUN_141552f90(FUN_141847a60(strDir), nFlags);
}
MS2_REPLACE_METHOD(0x1418475D0, Unk_TextureFrame, FUN_1418475d0, 253, 0xED2DC14D);

// @0x1418476e0
bool Unk_TextureFrame::FUN_1418476e0(const CString& strDir)
{
    if (FUN_140a0afd0()->FUN_141553eb0(FUN_141847960(strDir), 0).Get() == 0)
        return false;
    if (!m_strControl.IsEmpty())
    {
        if (FUN_140a0afd0()->FUN_141553eb0(FUN_141847a60(strDir), 0).Get() == 0)
            return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x1418476E0, Unk_TextureFrame, FUN_1418476e0, 408, 0x4B3EAA5E);

// @0x141847880
void Unk_TextureFrame::FUN_141847880(const CString& strDir)
{
    CFilePreload::GetInstance()->FUN_141210960(FUN_141847960(strDir), 5);
    if (!m_strControl.IsEmpty())
        CFilePreload::GetInstance()->FUN_141210960(FUN_141847a60(strDir), 5);
}
MS2_REPLACE_METHOD(0x141847880, Unk_TextureFrame, FUN_141847880, 208, 0x664E1E45);

// @0x141847960
CString Unk_TextureFrame::FUN_141847960(const CString& strDir)
{
    if (m_strFile[0] == '.')
        return m_strFile;
    if (!strDir.IsEmpty())
    {
        CString strPath = FUN_140536a50(m_strFile, strDir);
        return FUN_140540050("./Data/Resource/Model/Textures/{0}", strPath);
    }
    return FUN_140540050("./Data/Resource/Model/Textures/{0}", m_strFile);
}
MS2_REPLACE_METHOD(0x141847960, Unk_TextureFrame, FUN_141847960, 248, 0x1E15214E);

// @0x141847a60
CString Unk_TextureFrame::FUN_141847a60(const CString& strDir)
{
    if (m_strControl.IsEmpty())
        return "";
    if (m_strControl[0] == '.')
        return m_strControl;
    if (!strDir.IsEmpty())
    {
        CString strPath = FUN_140536a50(m_strControl, strDir);
        return FUN_140540050("./Data/Resource/Model/Textures/{0}", strPath);
    }
    return FUN_140540050("./Data/Resource/Model/Textures/{0}", m_strControl);
}
MS2_REPLACE_METHOD(0x141847A60, Unk_TextureFrame, FUN_141847a60, 328, 0x6F047299);

// @0x141847bb0
bool Unk_TextureFrame::FUN_141847bb0()
{
    return !m_strControl.IsEmpty();
}
MS2_REPLACE_METHOD(0x141847BB0, Unk_TextureFrame, FUN_141847bb0, 62, 0x1690B4C0);

// @0x141847c00
int Unk_TextureFrame::FUN_141847c00()
{
    return m_nDelay;
}
MS2_REPLACE_METHOD(0x141847C00, Unk_TextureFrame, FUN_141847c00, 14, 0xC2D0886F);

// @0x141847c20
CTextureAnimationData::CTextureAnimationData()
    : m_nLoopFrame(-1)
{
}

// @0x141847c90
int CTextureAnimationData::FUN_141847c90(int nTime)
{
    int nCount = (int)m_arrFrames.GetCount();
    int nIndex = 0;
    int nSum = 0;
    int nLoopStart = 0;
    for (int i = 0; i < nCount; i++)
    {
        if (i == m_nLoopFrame)
            nLoopStart = nSum;
        nSum += m_arrFrames[i].FUN_141847c00();
        if (nSum < nTime)
            nIndex++;
        else
            break;
    }
    if (nIndex < nCount || m_nLoopFrame == -1)
        return nIndex;
    int nLoopLen = nSum - nLoopStart;
    if (nLoopLen == 0)
        return m_nLoopFrame;
    nTime = (nTime - nLoopStart) % nLoopLen;
    nSum = 0;
    nIndex = m_nLoopFrame;
    for (int j = m_nLoopFrame; j < nCount; j++)
    {
        nSum += m_arrFrames[j].FUN_141847c00();
        if (nSum < nTime)
            nIndex++;
        else
            break;
    }
    return nIndex;
}
MS2_REPLACE_METHOD(0x141847C90, CTextureAnimationData, FUN_141847c90, 398, 0x5BB09234);

// @0x141847e30
bool CTextureAnimationData::FUN_141847e30(Unk_140165cf0* pNode)
{
    FUN_1408733e0(pNode, "target", m_strTarget);
    if (m_strTarget.IsEmpty())
        m_strTarget = FUN_142087e50(&DAT_143ae51d8);
    for (Unk_140165cf0* pTexture = pNode->FUN_140165cf0("texture"); pTexture != 0; pTexture = FUN_140168650(pTexture, "texture"))
    {
        m_arrFrames.Add(Unk_TextureFrame());
        int nLast = (int)m_arrFrames.GetCount() - 1;
        Unk_TextureFrame* pFrame = &m_arrFrames.GetAt(nLast);
        pFrame->FUN_141847560(pTexture);
        int nLoop = 0;
        FUN_140873710(pTexture, "loop", &nLoop);
        if (nLoop != 0)
            m_nLoopFrame = nLast;
    }
    return !m_arrFrames.IsEmpty();
}
MS2_REPLACE_METHOD(0x141847E30, CTextureAnimationData, FUN_141847e30, 424, 0x3BBB44B0);

// @0x141847fe0
int CTextureAnimationData::FUN_141847fe0(const CString& strDir)
{
    if (FUN_140a0afd0() == 0)
        return 1;
    for (unsigned int i = 0; i < m_arrFrames.GetCount(); i++)
    {
        if (!m_arrFrames[i].FUN_1418476e0(strDir))
            return 0;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x141847FE0, CTextureAnimationData, FUN_141847fe0, 140, 0x530C0706);

// @0x141848080
void CTextureAnimationData::FUN_141848080(const CString& strDir, int nFlags)
{
    if (FUN_140a0afd0() == 0)
        return;
    for (unsigned int i = 0; i < m_arrFrames.GetCount(); i++)
        m_arrFrames[i].FUN_1418475d0(strDir, nFlags);
}
MS2_REPLACE_METHOD(0x141848080, CTextureAnimationData, FUN_141848080, 129, 0x0D841F1C);

// @0x141848110
Unk_PPSmartC CTextureAnimationData::FUN_141848110(unsigned int nFrame, const CString& strDir)
{
    if (nFrame >= m_arrFrames.GetCount())
        return Unk_PPSmartC(0);
    return FUN_140a0afd0()->FUN_141552f90(m_arrFrames[nFrame].FUN_141847960(strDir), 5);
}
MS2_REPLACE_METHOD(0x141848110, CTextureAnimationData, FUN_141848110, 227, 0x8EEC6057);

// @0x141848200
Unk_PPSmartC CTextureAnimationData::FUN_141848200(unsigned int nFrame, const CString& strDir)
{
    if (nFrame >= m_arrFrames.GetCount())
        return Unk_PPSmartC(0);
    return FUN_140a0afd0()->FUN_141552f90(m_arrFrames[nFrame].FUN_141847a60(strDir), 5);
}
MS2_REPLACE_METHOD(0x141848200, CTextureAnimationData, FUN_141848200, 227, 0xF1FD1EE7);

// @0x1418482f0
CTextureAnimation::CTextureAnimation(PCBase* pOwner)
    : m_pOwner(pOwner), m_nFrame(-1), m_nState(0), m_nTime(0), m_spLayer(0), m_spNode(0)
{
}

// @0x1418483e0
CTextureAnimation::~CTextureAnimation()
{
    FUN_141848650();
}

// @0x1418484a0
void CTextureAnimation::FUN_1418484a0(MS2Ptr<CTextureAnimationData> spData, const CString& strDir)
{
    m_spData = spData;
    m_strDir = strDir;
    m_vecBase.clear();
    m_vecMap.clear();
    m_spNode.FUN_141418a00(FUN_141849060(m_spData->m_strTarget));
    if (m_spNode == 0)
        return;
    int bQueue = 1;
    int nLoaded = 0;
    if (FUN_140a53610(m_pOwner) != 0)
        bQueue = 0;
    else
    {
        nLoaded = m_spData->FUN_141847fe0(m_strDir);
        bQueue = nLoaded == 0;
    }
    if (bQueue == 0)
    {
        if (nLoaded == 0)
            FUN_141849190();
        FUN_141848890(0);
        m_nState = 2;
    }
    else
    {
        FUN_141849210();
        m_nState = 1;
    }
}
MS2_REPLACE_METHOD(0x1418484A0, CTextureAnimation, FUN_1418484a0, 417, 0x34C451CC);

// @0x141848650
void CTextureAnimation::FUN_141848650()
{
    if (m_spLayer)
    {
        FUN_1403ed2d0()->FUN_141bd3650()->RemoveLayer(m_spLayer);
        m_spNode->UpdateProperties();
        m_spLayer = 0;
    }
    m_vecBase.clear();
    m_vecMap.clear();
    m_strDir.Empty();
    m_nTime = 0;
    m_nFrame = -1;
    m_nState = 0;
}
MS2_REPLACE_METHOD(0x141848650, CTextureAnimation, FUN_141848650, 221, 0x6AD946C3);

// @0x141848740
// MS2-FUNCTIONAL: the tail `return true` blocks are laid out differently
bool CTextureAnimation::FUN_141848740(int nTime)
{
    if (m_nState == 0)
        return false;
    if (m_nState == 1 && (m_nTime += nTime, m_nTime >= 1000))
    {
        m_nTime = 0;
        if (m_spData->FUN_141847fe0(m_strDir) != 0)
        {
            FUN_141848890(0);
            m_nState = 2;
        }
    }
    unsigned int nFrame = m_spData->FUN_141847c90(nTime);
    if (nFrame >= m_spData->m_arrFrames.GetCount())
    {
        FUN_141848650();
        return false;
    }
    if (!(m_spLayer == 0) && nFrame != m_nFrame)
    {
        FUN_141848890(nFrame);
        return true;
    }
    return true;
}

// @0x141848890
void CTextureAnimation::FUN_141848890(unsigned int nFrame)
{
    if (m_spNode == 0)
        return;
    if (m_spLayer == 0)
    {
        NiProperty* pTexturing = m_spNode->GetProperty(NiProperty::TEXTURING);
        if (pTexturing == 0)
            return;
        m_nFrame = nFrame;
        Unk_PPSmartC spBase = FUN_141848bb0(m_nFrame);
        Unk_PPSmartC spMap = FUN_141848dc0(m_nFrame);
        m_spLayer = new (efd::MemHint(efd::MemHint::NONE)) TextureLayer(1, pTexturing, spBase.Get(), spMap.Get());
        FUN_1403ed2d0()->FUN_141bd3650()->AddLayer(m_spLayer);
    }
    else
    {
        m_nFrame = nFrame;
        Unk_PPSmartC spBase = FUN_141848bb0(m_nFrame);
        Unk_PPSmartC spMap = FUN_141848dc0(m_nFrame);
        m_spLayer->FUN_14184b140(spBase.Get());
        m_spLayer->FUN_14184b170(spMap.Get());
        FUN_1403ed2d0()->FUN_141bd3650()->Refresh(m_spLayer);
    }
    m_spNode->UpdateProperties();
}
MS2_REPLACE_METHOD(0x141848890, CTextureAnimation, FUN_141848890, 787, 0x840C4DB0);

// @0x141848bb0
// MS2-FUNCTIONAL: the m_spData-> call loads its this pointer into rcx and the count compare is reg-reg
Unk_PPSmartC CTextureAnimation::FUN_141848bb0(unsigned int nFrame)
{
    unsigned __int64 nIndex = nFrame;
    if (!(nIndex < m_spData->m_arrFrames.GetCount()))
        return Unk_PPSmartC(0);
    if (m_vecBase.size() > 0)
    {
        if (m_vecBase[nFrame] != 0)
            return m_vecBase[nFrame];
    }
    if (m_vecBase.empty())
    {
        Unk_PPSmartC kNull(0);
        m_vecBase.resize(m_spData->m_arrFrames.GetCount(), kNull);
    }
    m_vecBase[nFrame] = m_spData->FUN_141848110(nFrame, m_strDir);
    return m_vecBase[nFrame];
}

// @0x141848dc0
// MS2-FUNCTIONAL: same as FUN_141848bb0
Unk_PPSmartC CTextureAnimation::FUN_141848dc0(unsigned int nFrame)
{
    unsigned __int64 nIndex = nFrame;
    if (!(nIndex < m_spData->m_arrFrames.GetCount()))
        return Unk_PPSmartC(0);
    unsigned __int64 nAt = nFrame;
    if (!m_spData->m_arrFrames.GetAt(nAt).FUN_141847bb0())
        return Unk_PPSmartC(0);
    if (m_vecMap.size() > 0)
    {
        if (m_vecMap[nFrame] != 0)
            return m_vecMap[nFrame];
    }
    if (m_vecMap.empty())
    {
        Unk_PPSmartC kNull(0);
        m_vecMap.resize(m_spData->m_arrFrames.GetCount(), kNull);
    }
    m_vecMap[nFrame] = m_spData->FUN_141848200(nFrame, m_strDir);
    return m_vecMap[nFrame];
}

// @0x141849060
// MS2-FUNCTIONAL: stack slot order of the entity id / result temporaries differs
NiAVObject* CTextureAnimation::FUN_141849060(const CString& strName)
{
    egf::EntityID kId;
    if (m_pOwner == 0)
        return 0;
    NiActorManager* pActorMgr = FUN_141b6f910()->FUN_140999440(m_pOwner->FUN_14123c460(kId));
    if (pActorMgr == 0)
        return 0;
    NiObject* pRoot = pActorMgr->GetNIFRoot();
    if (pRoot == 0)
        return 0;
    NiAVObject* pResult;
    if (_stricmp((const char*)strName, "Scene Root") == 0)
        pResult = (NiAVObject*)FUN_14098d8d0(&Unk_RenderObjectRTTI, pRoot);
    else
    {
        NiObject* pNode = FUN_14107c930(pRoot, &strName);
        if (pNode == 0)
            pResult = 0;
        else
            pResult = (NiAVObject*)FUN_14098d8d0(&Unk_RenderObjectRTTI, pNode);
    }
    return pResult;
}

// @0x141849150
unsigned int CTextureAnimation::FUN_141849150()
{
    return (unsigned int)m_spData->m_arrFrames.GetCount();
}
MS2_REPLACE_METHOD(0x141849150, CTextureAnimation, FUN_141849150, 43, 0xB3487E00);

// @0x141849190
void CTextureAnimation::FUN_141849190()
{
    for (unsigned int i = 0; i < FUN_141849150(); i++)
    {
        FUN_141848bb0(i);
        FUN_141848dc0(i);
    }
}
MS2_REPLACE_METHOD(0x141849190, CTextureAnimation, FUN_141849190, 112, 0xEBE04EC0);

// @0x141849210
void CTextureAnimation::FUN_141849210()
{
    for (unsigned int i = 0; i < FUN_141849150(); i++)
        m_spData->m_arrFrames.GetAt(i).FUN_141847880(m_strDir);
}
MS2_REPLACE_METHOD(0x141849210, CTextureAnimation, FUN_141849210, 128, 0xF292ED27);

// @0x141849ec0
inline bool Unk_PickMeshPtr::operator==(NiAVObject* p) const
{
    return m_p == p;
}

// @0x141849f40
bool Unk_PPSmartC::operator!=(void* p) const
{
    return m_p != p;
}

// @0x141849de0
Unk_TextureFrame::~Unk_TextureFrame()
{
}

// @0x14184ac20
UITextureDensityDialog::UITextureDensityDialog()
{
    m_bEnable = false;
    m_nMode = 0;
    m_40 = 1;
    m_7c = 1;
}

// @0x14184aca0
UITextureDensityDialog::~UITextureDensityDialog()
{
}

// @0x14184ace0
void UITextureDensityDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_30->Invoke("initData", m_bEnable, m_nMode);
}
MS2_REPLACE_METHOD(0x14184ACE0, UITextureDensityDialog, OnLoadComplete, 99, 0xFE0249C9);

// @0x14184ad50
CString UITextureDensityDialog::vfunc_1()
{
    return "TextureDensityDialog";
}
MS2_REPLACE_METHOD(0x14184AD50, UITextureDensityDialog, vfunc_1, 61, 0x08D58A85);

// @0x14184ada0
int UITextureDensityDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp("onCheckEnable", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            bool bEnable = data.FUN_1422b8a90();
            m_bEnable = bEnable;
            FUN_1409a8b20()->FUN_1416a4570(bEnable);
        }
        return 1;
    }
    else if (_stricmp("onChangeRadio", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            int nMode = data.FUN_1422b8a10();
            m_nMode = nMode;
            FUN_1409a8b20()->FUN_1416a4660(nMode);
        }
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14184ADA0, UITextureDensityDialog, vfunc_28, 390, 0x6F78477D);

// @0x14184af30
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, bool a1, int a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bcce0(args.FUN_1409b1f70(0), a1);
    FUN_1422bccb0(args.FUN_1409b1f70(1), a2);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x14184b040
TextureLayer::TextureLayer(int nKind, NiProperty* pTexturing, void* pBase, void* pMap)
    : Layer(nKind), m_spBase(0), m_spMap(0), m_spTexturing(0)
{
    m_spBase.Assign(pBase);
    m_spMap.Assign(pMap);
    m_spTexturing = (NiTexturingProperty*)pTexturing;
}

// @0x14184b110
NiAVObject* TextureLayer::vfunc_18()
{
    return reinterpret_cast<NiAVObject*>((NiTexturingProperty*)m_spTexturing);
}
MS2_REPLACE_METHOD(0x14184B110, TextureLayer, vfunc_18, 31, 0xD587040A);

// @0x14184b140
void TextureLayer::FUN_14184b140(void* pBase)
{
    m_spBase.Assign(pBase);
}
MS2_REPLACE_METHOD(0x14184B140, TextureLayer, FUN_14184b140, 41, 0x082EE532);

// @0x14184b170
void TextureLayer::FUN_14184b170(void* pMap)
{
    m_spMap.Assign(pMap);
}
MS2_REPLACE_METHOD(0x14184B170, TextureLayer, FUN_14184b170, 41, 0x7AF71C4A);

// @0x14184b1a0
void TextureLayer::vfunc_19()
{
    m_spTexturing->SetBaseTexture((NiTexture*)m_spBase.Get());
    NiTexturingProperty::Map* pMap = m_spTexturing->GetShaderMap(0);
    if (pMap != 0)
        pMap->SetTexture((NiTexture*)m_spMap.Get());
}
MS2_REPLACE_METHOD(0x14184B1A0, TextureLayer, vfunc_19, 136, 0x814EF167);

// @0x14184b230
NiPointer<Layer> TextureLayerManager::vfunc_18(NiAVObject* pObject)
{
    NiTexturingProperty* pTexturing = NiDynamicCast(NiTexturingProperty, pObject);
    if (pTexturing == 0)
        return NiPointer<Layer>((Layer*)0);
    void* pMapTexture = 0;
    NiTexturingProperty::Map* pMap = pTexturing->GetShaderMap(0);
    if (pMap != 0)
        pMapTexture = pMap->GetTexture();
    return NiPointer<Layer>(new (efd::MemHint(efd::MemHint::NONE)) TextureLayer(0, pTexturing, pTexturing->GetBaseTexture(), pMapTexture));
}
MS2_REPLACE_METHOD(0x14184B230, TextureLayerManager, vfunc_18, 318, 0x472A89EB);

// Trailing CRT memmove_s COMDAT of the ATL array growth.
// @0x14184b420
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);

// Shared header statics and class metadata of this TU (.text$di + atexit thunks; gap2 orphan di sweep).
// MS2-RANGE: 0x14010db90-0x14010dd00 .text$di
// MS2-RANGE: 0x142cbbc30-0x142cbbcc0 .text$yd
#include "ms2/placeholder/header_statics_a.h"
