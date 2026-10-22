// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See uihideandseekresultdialog.h.
// MS2-UNIT: ?\uihideandseekresultdialog.cpp
// MS2-RANGE: 0x140c1e730-0x140c220d0 .text$mn
// MS2-RANGE: 0x1400cc560-0x1400cc590 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?vfunc_48@UIHideAndSeekResultDialog@@UEAAHXZ 0x140c20a70 ; unique
// MS2-PIN: ?FUN_140c21fb0@@YAHQEAX_KQEBX1@Z 0x140c21fb0
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "uihideandseekresultdialog.h"
#include <atlcoll.h>
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/tptr.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <string.h>

static CString s_strResultSound = "System_HideNSeek_Result_01";

// ---- unit-local views of exe objects ----

// The hide and seek record of a player (the object FUN_141664200 hands back).
class Unk_HsInfo : public CPtred
{
public:
    int FUN_14050a6a0();                                    // +0x2c team
    unsigned int FUN_14050a660();                           // +0x28 kills
    bool FUN_14050a4d0();                                   // +0x19 dead
    __int64 FUN_14050a600();                                // +0x20 exp
};
class Unk_HsPC : public PC
{
public:
    MS2Ptr<Unk_HsInfo> FUN_141664200();                     // the player's record
};


class Unk_HsItemNames { public: CStringW FUN_141811980(int nTable, int nItemId); };
Unk_HsItemNames* FUN_1401a9d70();
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
CStringW FUN_140b99450(CStringW strFormat, const CStringW& strArg, const int& nCount);
WorldService* FUN_1403ed2d0();
int FUN_141654730(PCBase* pPC);                             // job
void FUN_140bd0d90(ASObj* pObj, const char* szName, int n);
void FUN_141276180(const CString& strSound, const CString& strArg);
void FUN_141415450(const CString& strName, MS2Ptr<CItem> spItem, int nIndex, int nIconType, int nFlags);
void FUN_141415600(const CString& strName);
int FUN_1418fc760(const char* szEvent, void* a2, int a3, void* a4);
void FUN_1407cd930(Scaleform::GFx::Value* pObject, const char* szName, const Scaleform::GFx::Value& v);
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
void FUN_1422bcc70(Scaleform::GFx::Value* pValue, Scaleform::GFx::Value v);

// @0x140c20410 TPtr<PCBase> copy: AddRef through the pointee's slot 1
// @0x140c206b0
template <> inline bool TPtr<PCBase>::operator==(PCBase* p) const
{
    return m_p == p;
}

template <> inline TPtr<PCBase>::TPtr(const TPtr& o)
{
    m_p = o.m_p;
    if (m_p)
        m_p->IncRefCount();
}

// @0x140c1f8b0
void ASObj::FUN_140c1f8b0(const char* szName, int n)
{
    ASData data;
    data.FUN_1422b7f70(n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}

// @0x140c1f740 Invoke(name, int, AS object, AS array): both by-value arguments are destroyed by the callee
Scaleform::GFx::Value AScript::Invoke(const char* szMethod, int a1, AScript a2, ASArray a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bccb0(args.FUN_1409b1f70(0), a1);
    FUN_1422bcc70(args.FUN_1409b1f70(1), Scaleform::GFx::Value(a2.FUN_1422bb890()));
    FUN_1422bcc70(args.FUN_1409b1f70(2), Scaleform::GFx::Value(a3.FUN_1422bb890()));
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140c1e730
UIHideAndSeekResultDialog::UIHideAndSeekResultDialog()
{
    m_nRound = 0;
    m_nItemId = 0;
    m_nUnused = 0;
    m_nCount = 0;
    m_80 = 0;
    FUN_141924170(1);
}

// @0x140c1e7f0
UIHideAndSeekResultDialog::~UIHideAndSeekResultDialog()
{
}

// @0x140c1e840
CString UIHideAndSeekResultDialog::GetTypeName()
{
    return CString("HideAndSeekResultDialog");
}
MS2_REPLACE_METHOD(0x140C1E840, UIHideAndSeekResultDialog, GetTypeName, 61, 0xF8DFF252);

// @0x140c1e890
void UIHideAndSeekResultDialog::vfunc_67()
{
    m_nRound = 0;
    m_nItemId = 0;
    m_nUnused = 0;
    m_nCount = 0;
    FUN_140c1f590();
    UIDialog::vfunc_67();
}
MS2_REPLACE_METHOD(0x140C1E890, UIHideAndSeekResultDialog, vfunc_67, 94, 0xCE0B0531);

// @0x140c1e900
void UIHideAndSeekResultDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_140c1eb20();
    CString strArg("");
    FUN_141276180(s_strResultSound, strArg);
}
MS2_REPLACE_METHOD(0x140C1E900, UIHideAndSeekResultDialog, OnLoadComplete, 91, 0xEA20896F);

// @0x140c1e970
int UIHideAndSeekResultDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (FUN_1418fc760(szMethod, (void*)pArgs, nArgs, 0))
        return 1;
    if (_stricmp("OnClose", szMethod) == 0)
    {
        vfunc_67();
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140C1E970, UIHideAndSeekResultDialog, vfunc_28, 148, 0xCE28F034);

// @0x140c1ea10
void UIHideAndSeekResultDialog::vfunc_43()
{
    UIDialog::vfunc_43();
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (spEntity.get())
        spEntity->vfunc_2(1, 0, 0x96);
}
MS2_REPLACE_METHOD(0x140C1EA10, UIHideAndSeekResultDialog, vfunc_43, 167, 0x42FBD539);

// @0x140c1eac0
void UIHideAndSeekResultDialog::FUN_140c1eac0(int nRound, int nItemId, int nUnused, int nCount)
{
    m_nRound = nRound;
    m_nItemId = nItemId;
    m_nUnused = nUnused;
    m_nCount = nCount;
}
MS2_REPLACE_METHOD(0x140C1EAC0, UIHideAndSeekResultDialog, FUN_140c1eac0, 80, 0x0B85E4B4);

// @0x140c1eb20
void UIHideAndSeekResultDialog::FUN_140c1eb20()
{
    if (m_30 == 0)
        return;
    ASObj objMine(2);
    ASArray rows(2);
    ATL::CRBMap<unsigned, Unk_WsV118>* pMap = FUN_1403ed2d0()->FUN_141bd36b0();
    for (POSITION pos = pMap->GetHeadPosition(); pos != 0; pMap->GetNext(pos))
    {
        // the map element (Unk_WsV118, one pointer) is read as the TPtr<PCBase> it holds
        TPtr<PCBase> spActor = *reinterpret_cast<TPtr<PCBase>*>(&pMap->GetValueAt(pos));
        if (spActor == 0)
            continue;
        MS2Ptr<Unk_HsInfo> spInfo = static_cast<Unk_HsPC*>(static_cast<PC*>(spActor.operator->()))->FUN_141664200();
        if (spInfo == 0)
            continue;
        if (spInfo->FUN_14050a6a0() == 0)
            continue;
        bool bMine = (static_cast<PC*>(FUN_1403ed2d0()->FUN_141bd0cc0()) == spActor.get());
        if (bMine)
            FUN_140c1eec0(objMine, spInfo);
        FUN_140c1f120(rows, spInfo, static_cast<PC*>(spActor.get()), bMine);
    }
    m_30->Invoke("setData", m_nRound, objMine, rows);
}
MS2_REPLACE_METHOD(0x140C1EB20, UIHideAndSeekResultDialog, FUN_140c1eb20, 921, 0x1DB5C4C3);

// @0x140c1eec0
void UIHideAndSeekResultDialog::FUN_140c1eec0(AScript objMine, MS2Ptr<Unk_HsInfo> spInfo)
{
    MS2Ptr<CItemData> spItem = FUN_14053f870(m_nItemId);
    if (spItem == 0)
        return;
    if ((unsigned int)m_nCount < 1u)
        return;
    int nItemId = m_nItemId;
    int nCount = m_nCount;
    CString strIcon = FUN_140c1f300(nItemId, nCount);
    const CString& rIcon = strIcon;
    CStringW strName = FUN_1401a9d70()->FUN_141811980(1, nItemId);
    const CStringW& rName = strName;
    CStringW strText = FUN_140b99450(CStringW(L"s_hideandseek_winner_reward"), rName, nCount);
    const CStringW& rText = strText;
    static_cast<ASObj&>(objMine).FUN_1407cba60("binding", rIcon);
    static_cast<ASObj&>(objMine).FUN_1407cbb20("text", rText);
}

// @0x140c1f120
void UIHideAndSeekResultDialog::FUN_140c1f120(ASArray& rows, MS2Ptr<Unk_HsInfo> spInfo, PC* pPC, bool bMine)
{
    ASObj row(2);
    row.FUN_140c1f8b0("team", spInfo->FUN_14050a6a0());
    FUN_140bd0d90(&row, "job", FUN_141654730(pPC));
    row.FUN_1407cbb20("charName", pPC->vfunc_77());
    row.FUN_1409c0d20("kill", spInfo->FUN_14050a660());
    row.FUN_1407cb9c0("death", spInfo->FUN_14050a4d0() != 0);
    row.FUN_1409c1180("exp", spInfo->FUN_14050a600());
    row.FUN_1407cbbe0("isMe", bMine);
    rows.FUN_1422bc050(Scaleform::GFx::Value(row.FUN_1422bb870()));
}

// @0x140c1f300
CString UIHideAndSeekResultDialog::FUN_140c1f300(unsigned int nItemId, int nCount)
{
    CString strKey;
    strKey.Format("%s_%d", (const char*)GetTypeName(), nItemId);
    if (m_boundIcons.find(strKey) == m_boundIcons.end())
    {
        MS2Ptr<CItem> spItem(new CItem);
        if (!spItem->FUN_140523c40(nItemId, 1, 0))
            return CString("");
        spItem->FUN_140526c70(nCount);
        FUN_141415450(strKey, spItem, 0, 0x411, 0);
        m_boundIcons.insert(strKey);
    }
    return strKey;
}
MS2_REPLACE_METHOD(0x140C1F300, UIHideAndSeekResultDialog, FUN_140c1f300, 642, 0x90239FD2);

// @0x140c1f590
void UIHideAndSeekResultDialog::FUN_140c1f590()
{
    std::set<CString>::iterator it = m_boundIcons.begin();
    std::set<CString>::iterator itEnd = m_boundIcons.end();
    for (; it != itEnd; ++it)
        FUN_141415600(*it);
    m_boundIcons.clear();
}
MS2_REPLACE_METHOD(0x140C1F590, UIHideAndSeekResultDialog, FUN_140c1f590, 135, 0x47207A4E);

// @0x140c21fb0 (the UCRT header-inline memcpy_s without the memset of the newer headers, emitted here as an ordinary function)
#define MS2_VALIDATE_RETURN_ERRCODE(expr, errorcode)                                                           \
    {                                                                                                          \
        int _Expr_val = !!(expr);                                                                              \
        if (!(_Expr_val)) {                                                                                    \
            errno = errorcode;                                                                                 \
            _invalid_parameter_noinfo();                                                                       \
            return errorcode;                                                                                  \
        }                                                                                                      \
    }
#pragma function(memcpy)
errno_t FUN_140c21fb0(void* const dst, rsize_t const dstSize, void const* const src, rsize_t const srcSize)
{
    if (srcSize == 0)
        return 0;
    MS2_VALIDATE_RETURN_ERRCODE(dst != NULL, EINVAL);
    MS2_VALIDATE_RETURN_ERRCODE(src != NULL, EINVAL);
    MS2_VALIDATE_RETURN_ERRCODE(dstSize >= srcSize, ERANGE);
    memcpy(dst, src, srcSize);
    return 0;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca26e0-0x142ca2700 .text$yd
