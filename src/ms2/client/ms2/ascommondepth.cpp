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
// MS2-PIN: ??1?$vector@VValue@GFx@Scaleform@@V?$allocator@VValue@GFx@Scaleform@@@std@@@std@@QEAA@XZ 0x1409b1f20 ; sfk: ASArgList is this vector
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
class Unk_AltStringMgr* GetGFxManager();   // C3: was GetGFxManager
Scaleform::GFx::Movie* GetMovie(int nMovieId);
void SetValue(Scaleform::GFx::Value* pValue, Scaleform::GFx::Value v);   // set Value from Value (callee destroys)
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);

// ---- ASCommonDepth ----

// @0x1409b0fd0
ASCommonDepth::ASCommonDepth(Scaleform::GFx::Value v, int nMovieId)
    : AScript(v, nMovieId)
{
    Scaleform::GFx::Movie* pMovie = GetMovie(m_nMovieId);
    if (pMovie == 0)
        return;
    pMovie->CreateObject(&m_value, "scaleform.ms2.common.CommonDepth", 0, 0);
    if (((Scaleform::GFx::Value*)(void*)(&m_value))->IsUndefined()) {}
}

// @0x1409b1090
MS2Ptr<ASCommonDepth> ASCommonDepth::Create(int nMovieId)
{
    GFxMovie* pMovie = ((class GFxManager*)GetGFxManager())->FindMovie(nMovieId);
    if (pMovie != 0)
        return MS2Ptr<ASCommonDepth>(new ASCommonDepth(pMovie->GetDefinitionByName(CString("scaleform.ms2.common.CommonDepth")), nMovieId));
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

// ASArgList is the exe's std::vector<GFx::Value> itself (typedef in asdata.h/ascript.h): the call sites name
// vector() 0x1409b1e80, ~vector() 0x1409b1f20, resize(size_t) 0x1409b2800 and operator[](size_t) 0x1409b1f70
// directly. This unit instantiates the four, pinned above.
template std::vector<Scaleform::GFx::Value>::vector() noexcept;




// ~vector() 0x1409b1f20 calls _Tidy 0x1409b2530 under the noexcept frame.


template std::vector<Scaleform::GFx::Value>::~vector();

template void std::vector<Scaleform::GFx::Value>::resize(size_t);

template Scaleform::GFx::Value& std::vector<Scaleform::GFx::Value>::operator[](size_t);







// ---- AScript::Invoke back ends ----

// @0x1409b13b0
Scaleform::GFx::Value AScript::Invoke(const char* szMethod, Scaleform::GFx::Value a1)
{
    ASArgList args;
    args.resize(1);
    SetValue(&args[0], a1);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x1409b1490
Scaleform::GFx::Value AScript::Invoke(const char* szMethod, Scaleform::GFx::Value a1, int a2)
{
    ASArgList args;
    args.resize(2);
    SetValue(&args[0], a1);
    FUN_1422bccb0(&args[1], a2);
    return FUN_1422bb8f0(szMethod, args);
}

MS2_EMIT_CRT_MEMMOVE_S();
