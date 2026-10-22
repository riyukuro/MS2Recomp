// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UITopLayerNotify: see uitoplayernotify.h.
// MS2-UNIT: ?\uitoplayernotify.cpp
// MS2-RANGE: 0x140fa8640-0x140fa8cc0 .text$mn
// MS2-PIN: ??_GUITopLayerNotify@@UEAAPEAXI@Z 0x140fa8b50
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uitoplayernotify.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uitoplayernotify.h"

#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);     // Value = string
void FUN_1422bcd40(Scaleform::GFx::Value* pValue, unsigned long n);        // Value = n (UInt)

// The exe has a byte-identical private copy of AScript::Invoke(const char*, CStringW, int) (0x140e0a8c0) for this unit.
class Unk_TnScript : public AScript
{
public:
    Scaleform::GFx::Value FUN_140fa8a70(const char* szMethod, CStringW a1, int a2);
};

extern unsigned DAT_143af62d8;                                  // client area height

// @0x140fa8640
UITopLayerNotify::UITopLayerNotify()
{
    m_70.Empty();
    m_78 = 0;
    m_2c = 0x26;
}

// @0x140fa86c0
UITopLayerNotify::~UITopLayerNotify()
{
}

// @0x140fa8710
CString UITopLayerNotify::GetTypeName()
{
    return "TopLayerNotify";
}
MS2_REPLACE_METHOD(0x140FA8710, UITopLayerNotify, GetTypeName, 61, 0x634A659E);

// @0x140fa8760
void UITopLayerNotify::vfunc_2()
{
    UIHeadUpDisplay::vfunc_2();
}

// @0x140fa8780
void UITopLayerNotify::vfunc_3()
{
    UIHeadUpDisplay::vfunc_3();
    m_70.Empty();
    m_78 = 0;
}

// @0x140fa87c0
void UITopLayerNotify::OnLoadComplete()
{
    UIObject::OnLoadComplete();
    if (m_70.GetLength() != 0)
        FUN_140fa8970(m_70, m_78);
}

// @0x140fa8820
void UITopLayerNotify::vfunc_43()
{
    MS2Ptr<ASGameEntity> pEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (pEntity.get())
        pEntity->vfunc_2(1, 0, (int)((double)DAT_143af62d8 * 0.1));
}

// @0x140fa88f0
int UITopLayerNotify::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISwfEntity::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp(szMethod, "onHideMessage") == 0) {
        vfunc_3();
        return 1;
    }
    return 0;
}

// @0x140fa8970
void UITopLayerNotify::FUN_140fa8970(const CStringW& strText, int nType)
{
    if (m_30.get() == 0) {
        m_70 = strText;
        m_78 = nType;
        vfunc_2();
    } else {
        static_cast<Unk_TnScript*>(m_30.operator->())->FUN_140fa8a70("showMessage", CStringW(strText), nType);
    }
}

// @0x140fa8a70
Scaleform::GFx::Value Unk_TnScript::FUN_140fa8a70(const char* szMethod, CStringW a1, int a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bcea0(args.FUN_1409b1f70(0), (const wchar_t*)a1);
    FUN_1422bcd40(args.FUN_1409b1f70(1), a2);
    return FUN_1422bb8f0(szMethod, args);
}

MS2_EMIT_CRT_MEMMOVE_S();
