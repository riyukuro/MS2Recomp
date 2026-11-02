// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIScreenMask: see uiscreenmask.h.
// MS2-UNIT: ?\uiscreenmask.cpp
// MS2-RANGE: 0x141ad0650-0x141ad0c80 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiscreenmask.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "uiscreenmask.h"

#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asuicomponent.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
class CFieldDataCli;   // C3: the real class (fielddatacli.h), MS2Ptr<CFieldDataCli>::get

// ---- unit-local placeholders (unrecovered helpers; promote to src/ms2/placeholder/ when shared) ----

template <class T> MS2Ptr<T> Unk_ASCreate(int nMovieId, const Scaleform::GFx::Value& v);   // new T(v, nMovieId)
template <> MS2Ptr<ASUIComponent> Unk_ASCreate<ASUIComponent>(int nMovieId, const Scaleform::GFx::Value& v); // 0x140acca70

// This assignment COMDAT belongs to the earlier unit at 0x140c74dd0.
template <> template <>
MS2Ptr<AScript>& MS2Ptr<AScript>::operator=<ASUIComponent>(const MS2Ptr<ASUIComponent>&);

// The client's world/context table (FUN_1403ed2d0) and the current field's data behind a counted pointer.
class Unk_1403ed2d0;
class Unk_FieldData
{
public:
    char m_pad_0[0x1a8];
    CString m_strName;                                  // +0x1a8 the field's screen mask effect name
};
class Unk_FieldDataPtr
{
public:
    ~Unk_FieldDataPtr();                                // 0x1408850f0
    Unk_FieldData* FUN_140885340() const;               // operator->
private:
    void* m_pad_00;
    Unk_FieldData* m_p;
};
class Unk_1403ed2d0 { public: Unk_FieldDataPtr FUN_141bd30a0(); };   // current field's data
class WorldService   // C3: member view for the former free stand-ins
{
public:
    static class WorldService* GetInstance();
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x141ad0650
UIScreenMask::UIScreenMask()
{
    m_58 = 0;
    m_2c = 10;
}

// @0x141ad06b0
UIScreenMask::~UIScreenMask()
{
}

// @0x141ad06f0
CString UIScreenMask::GetTypeName()
{
    return "ScreenMask";
}

// @0x141ad0740
void UIScreenMask::vfunc_2()
{
    FUN_1422dbf00(10, 0, 0);
}

// @0x141ad0770
void UIScreenMask::vfunc_3()
{
    FUN_1422dc080();
}

// @0x141ad0790
void UIScreenMask::OnLoadInit()
{
    UIObject::OnLoadInit();
    MS2Ptr<ASUIComponent> spComponent = dynamic_cast<ASUIComponent*>((AScript*)m_30);
    if (spComponent.get()) {
        const CString& strName = FUN_141ad09e0();
        if (!strName.IsEmpty())
            spComponent->Invoke("load", strName);
    }
}

// @0x141ad08c0
void UIScreenMask::vfunc_43()
{
    MS2Ptr<ASUIComponent> spComponent = dynamic_cast<ASUIComponent*>((AScript*)m_30);
    if (spComponent.get()) {
        spComponent->SetSizeInt(((class ASDisplayObject*)spComponent.operator->())->FUN_1422c1500(), ((class ASDisplayObject*)spComponent.operator->())->FUN_1422c1530());
        spComponent->vfunc_2(5, 0, 0);
        spComponent->vfunc_3(1);
    }
}

// @0x141ad09e0
CString UIScreenMask::FUN_141ad09e0()
{
    Unk_FieldDataPtr spField = ((class Unk_1403ed2d0*)WorldService::GetInstance())->FUN_141bd30a0();
    if (reinterpret_cast<Unk_FieldData*>(reinterpret_cast<const MS2Ptr<CFieldDataCli>&>(spField).get()) != 0)
        return spField.FUN_140885340()->m_strName;
    return "";
}

// @0x141ad0aa0
void UIScreenMask::vfunc_41(const Scaleform::GFx::Value& root)
{
    m_30 = Unk_ASCreate<ASUIComponent>(m_28, root);
}

// @0x141ad0b60
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
