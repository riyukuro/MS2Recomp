// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See ascommondepth.h.
// MS2-UNIT: ?\ascommondepth.cpp
// MS2-RANGE: 0x1409b0fd0-0x1409b2880 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@VValue@GFx@Scaleform@@V?$allocator@VValue@GFx@Scaleform@@@std@@@std@@@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@VValue@GFx@Scaleform@@@std@@@2@XZ 0x1409b22d0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@VValue@GFx@Scaleform@@@std@@V?$_Vector_val@U?$_Simple_types@VValue@GFx@Scaleform@@@std@@@2@$00@std@@QEAAAEAV?$allocator@VValue@GFx@Scaleform@@@2@XZ 0x1409b2310 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@VValue@GFx@Scaleform@@@std@@V?$_Vector_val@U?$_Simple_types@VValue@GFx@Scaleform@@@std@@@2@$00@std@@QEBAAEBV?$allocator@VValue@GFx@Scaleform@@@2@XZ 0x1409b2320 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@VValue@GFx@Scaleform@@@std@@V?$_Vector_val@U?$_Simple_types@VValue@GFx@Scaleform@@@std@@@2@$00@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@VValue@GFx@Scaleform@@@std@@@2@XZ 0x1409b2330 ; prop
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@VValue@GFx@Scaleform@@V?$allocator@VValue@GFx@Scaleform@@@std@@@std@@@std@@QEBAAEBQEAVValue@GFx@Scaleform@@XZ 0x1409b23b0 ; unique
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@VValue@GFx@Scaleform@@V?$allocator@VValue@GFx@Scaleform@@@std@@@std@@@std@@QEBAAEBQEAVValue@GFx@Scaleform@@XZ 0x1409b2430 ; unique
// MS2-PIN: ??0?$vector@VValue@GFx@Scaleform@@V?$allocator@VValue@GFx@Scaleform@@@std@@@std@@QEAA@XZ 0x1409b1e80 ; sfk: ASArgList is this vector
// MS2-PIN: ?resize@?$vector@VValue@GFx@Scaleform@@V?$allocator@VValue@GFx@Scaleform@@@std@@@std@@QEAAX_K@Z 0x1409b2800 ; sfk: ASArgList is this vector
// MS2-PIN: ??A?$vector@VValue@GFx@Scaleform@@V?$allocator@VValue@GFx@Scaleform@@@std@@@std@@QEAAAEAVValue@GFx@Scaleform@@_K@Z 0x1409b1f70 ; sfk: ASArgList is this vector
// MS2-PINS-END tplpin
// MS2-FUNCTIONAL: ASArgList is a std::vector<Value> (with the container proxy) whose instantiation helpers are pinned by hand.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\ascommondepth.cpp"
#include <vcruntime_string.h>
#pragma function(memcpy, memset)
#include "ms2/placeholder/ms2stdafx.h"

#include <vector>

#include "ascommondepth.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/gfxmovie.h"

// ---- unit-local placeholders ----

// The Scaleform movie of a UI movie id (GFx movie view wrapper).
class GFxManager
{
public:
    GFxMovie* FindMovie(int nMovieId);
};
class Unk_AltStringMgr* FUN_14025e7a0();   // C3: was FUN_14025e7a0
void* FUN_1422bb8b0(int nMovieId);
void FUN_14256e8e0(void* pMovie, Scaleform::GFx::Value* pValue, const char* szClass, int a, int b);
void FUN_1422bcc70(Scaleform::GFx::Value* pValue, Scaleform::GFx::Value v);   // set Value from Value (callee destroys)
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);

// ---- ASCommonDepth ----

// @0x1409b0fd0
ASCommonDepth::ASCommonDepth(Scaleform::GFx::Value v, int nMovieId)
    : AScript(v, nMovieId)
{
    void* pMovie = FUN_1422bb8b0(m_nMovieId);
    if (pMovie == 0)
        return;
    FUN_14256e8e0(pMovie, &m_value, "scaleform.ms2.common.CommonDepth", 0, 0);
    if (((Scaleform::GFx::Value*)(void*)(&m_value))->IsUndefined()) {}
}

// @0x1409b1090
MS2Ptr<ASCommonDepth> ASCommonDepth::Create(int nMovieId)
{
    GFxMovie* pMovie = ((class GFxManager*)FUN_14025e7a0())->FindMovie(nMovieId);
    if (pMovie != 0)
        return MS2Ptr<ASCommonDepth>(new ASCommonDepth(pMovie->FUN_1422bd120(CString("scaleform.ms2.common.CommonDepth")), nMovieId));
    return MS2Ptr<ASCommonDepth>(0);
}

// @0x1409b11d0
void ASCommonDepth::AddLayer(const Scaleform::GFx::Value& layer, int nDepth, int nMovieId)
{
    MS2Ptr<ASCommonDepth> p = Create(nMovieId);
    if (p.get())
        p->Invoke("addLayer", layer, nDepth);
}

// @0x1409b1290
Scaleform::GFx::Value ASCommonDepth::GetLayer(const Scaleform::GFx::Value& layer, int nMovieId)
{
    {
        MS2Ptr<ASCommonDepth> p = Create(nMovieId);
        if (p.get())
            return p->Invoke("getLayer", layer);
    }
    return Scaleform::GFx::Value();
}

// ---- ASArgList: std::vector<Value> ----

struct Unk_ArgVec
{
    std::vector<Scaleform::GFx::Value> v;
};

// ASArgList is really std::vector<GFx::Value>: the exe rows 0x1409b1e80 (vector()), 0x1409b2800 (resize(size_t))
// and 0x1409b1f70 (operator[](size_t)) are the vector instantiations these wrappers call, pinned above.
// The wrappers stay for the ~750 call sites in 119 units that use ASArgList.
ASArgList::ASArgList()
{
    new (this) Unk_ArgVec();
}

// ASArgList is really std::vector<GFx::Value>: the exe dtor is ~vector(), _Tidy 0x1409b2530 under the noexcept frame.
void FUN_1409b2530(void* pVec);     // vector<Value>::_Tidy, private
template std::vector<Scaleform::GFx::Value>::~vector();     // emits _Tidy; not a row of its own
// @0x1409b1f20
ASArgList::~ASArgList()
{
    FUN_1409b2530(this);
}

void ASArgList::FUN_1409b2800(int nCount)
{
    ((Unk_ArgVec*)this)->v.resize(nCount);
}

Scaleform::GFx::Value* ASArgList::FUN_1409b1f70(int nIndex)
{
    return &((Unk_ArgVec*)this)->v[nIndex];
}

// ---- AScript::Invoke back ends ----

// @0x1409b13b0
Scaleform::GFx::Value AScript::Invoke(const char* szMethod, Scaleform::GFx::Value a1)
{
    ASArgList args;
    args.FUN_1409b2800(1);
    FUN_1422bcc70(args.FUN_1409b1f70(0), a1);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x1409b1490
Scaleform::GFx::Value AScript::Invoke(const char* szMethod, Scaleform::GFx::Value a1, int a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bcc70(args.FUN_1409b1f70(0), a1);
    FUN_1422bccb0(args.FUN_1409b1f70(1), a2);
    return FUN_1422bb8f0(szMethod, args);
}

MS2_EMIT_CRT_MEMMOVE_S();
