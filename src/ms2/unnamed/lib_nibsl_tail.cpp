// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). NiBinaryShaderLib (NiBinaryShaderLibrary_DX9.cpp) functions
// the engine stage leaves unpaired: the out-of-line NiBinaryShaderLibrary::ConvertNSBRenderStateValue and
// GetD3DRenderStateType with every GetD3D* value helper inlined into them, plus the std::map<unsigned int, unsigned int>
// tree head-node allocation and subtree erase the library carries its own copies of. Free functions under the exe's own
// FUN_<va> names, so they cannot collide with the engine-stage NiBinaryShaderLibrary or the game's std::map copies.
// MS2-UNIT: lib_nibsl_tail
// MS2-RANGE: 0x141cac4b0-0x141cac4e7 .text$mn
// MS2-RANGE: 0x141cac530-0x141cac585 .text$mn
// MS2-RANGE: 0x141cae4f0-0x141cae6ec .text$mn
// MS2-RANGE: 0x141caeee0-0x141caf2a2 .text$mn
// MS2-FLAGS: gamebryo
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <d3d9.h>
#include <NSBRenderStates.h>
#include <map>

// std::map<unsigned int, unsigned int>'s tree node (MSVC layout: links, colour, nil flag, then the value).
struct UIntUIntTreeNode
{
    UIntUIntTreeNode* _Left;
    UIntUIntTreeNode* _Parent;
    UIntUIntTreeNode* _Right;
    char _Color;
    char _Isnil;
    std::pair<const unsigned int, unsigned int> _Myval;
};

// std::_Tree_comp_alloc<map<unsigned int, unsigned int> traits>::_Buyheadnode: this library's own copy (the game's is
// 0x140a422c0): a black nil head node linked to itself.
// MS2-FUNCTIONAL: the exe's copy has the library's EH frame (the empty try/catch of the std source) and homes `this`.
// @0x141cac4b0
UIntUIntTreeNode* FUN_141cac4b0(void* self)
{
    UIntUIntTreeNode* pnode = (UIntUIntTreeNode*)::operator new(sizeof(UIntUIntTreeNode));
    pnode->_Left = pnode;
    pnode->_Parent = pnode;
    pnode->_Right = pnode;
    pnode->_Color = 1;   // _Black
    pnode->_Isnil = 1;
    return pnode;
}

// std::_Tree<map<unsigned int, unsigned int> traits>::_Erase: this library's own copy (the game's is 0x140a42520):
// frees a subtree without rebalancing.
// @0x141cac530
void FUN_141cac530(void* self, UIntUIntTreeNode* rootnode)
{
    for (UIntUIntTreeNode* pnode = rootnode; !pnode->_Isnil; rootnode = pnode)
    {
        FUN_141cac530(self, pnode->_Right);
        pnode = pnode->_Left;
        ::operator delete(rootnode, sizeof(UIntUIntTreeNode));
    }
}

namespace lib_nibsl_tail {

// The NiBinaryShaderLibrary::GetD3D* value converters (protected statics the exe only has inlined).
__forceinline bool GetD3DZBufferType(
    NSBRenderStates::NSBZBufferType eZBufferType,
    unsigned int& uiD3DValue)
{
    switch (eZBufferType)
    {
    case NSBRenderStates::NSB_ZB_FALSE:
        uiD3DValue = (unsigned int)D3DZB_FALSE;
        return true;
    case NSBRenderStates::NSB_ZB_TRUE:
        uiD3DValue = (unsigned int)D3DZB_TRUE;
        return true;
    case NSBRenderStates::NSB_ZB_USEW:
        uiD3DValue = (unsigned int)D3DZB_USEW;
        return true;
    default:
        return false;
    }
}

//--------------------------------------------------------------------------------------------------
__forceinline bool GetD3DFillMode(
    NSBRenderStates::NSBFillMode eFillMode,
    unsigned int& uiD3DValue)
{
    switch (eFillMode)
    {
    case NSBRenderStates::NSB_FILL_POINT:
        uiD3DValue = (unsigned int)D3DFILL_POINT;
        return true;
    case NSBRenderStates::NSB_FILL_WIREFRAME:
        uiD3DValue = (unsigned int)D3DFILL_WIREFRAME;
        return true;
    case NSBRenderStates::NSB_FILL_SOLID:
        uiD3DValue = (unsigned int)D3DFILL_SOLID;
        return true;
    default:
        return false;
    }
}

//--------------------------------------------------------------------------------------------------
__forceinline bool GetD3DShadeMode(
    NSBRenderStates::NSBShadeMode eShadeMode,
    unsigned int& uiD3DValue)
{
    switch (eShadeMode)
    {
    case NSBRenderStates::NSB_SHADE_FLAT:
        uiD3DValue = (unsigned int)D3DSHADE_FLAT;
        return true;
    case NSBRenderStates::NSB_SHADE_GOURAUD:
        uiD3DValue = (unsigned int)D3DSHADE_GOURAUD;
        return true;
    case NSBRenderStates::NSB_SHADE_PHONG:
        uiD3DValue = (unsigned int)D3DSHADE_PHONG;
        return true;
    default:
        return false;
    }
}

//--------------------------------------------------------------------------------------------------
__forceinline bool GetD3DBlend(
    NSBRenderStates::NSBBlend eBlend,
    unsigned int& uiD3DValue)
{
    switch (eBlend)
    {
    case NSBRenderStates::NSB_BLEND_ZERO:
        uiD3DValue = (unsigned int)D3DBLEND_ZERO;
        return true;
    case NSBRenderStates::NSB_BLEND_ONE:
        uiD3DValue = (unsigned int)D3DBLEND_ONE;
        return true;
    case NSBRenderStates::NSB_BLEND_SRCCOLOR:
        uiD3DValue = (unsigned int)D3DBLEND_SRCCOLOR;
        return true;
    case NSBRenderStates::NSB_BLEND_INVSRCCOLOR:
        uiD3DValue = (unsigned int)D3DBLEND_INVSRCCOLOR;
        return true;
    case NSBRenderStates::NSB_BLEND_SRCALPHA:
        uiD3DValue = (unsigned int)D3DBLEND_SRCALPHA;
        return true;
    case NSBRenderStates::NSB_BLEND_INVSRCALPHA:
        uiD3DValue = (unsigned int)D3DBLEND_INVSRCALPHA;
        return true;
    case NSBRenderStates::NSB_BLEND_DESTALPHA:
        uiD3DValue = (unsigned int)D3DBLEND_DESTALPHA;
        return true;
    case NSBRenderStates::NSB_BLEND_INVDESTALPHA:
        uiD3DValue = (unsigned int)D3DBLEND_INVDESTALPHA;
        return true;
    case NSBRenderStates::NSB_BLEND_DESTCOLOR:
        uiD3DValue = (unsigned int)D3DBLEND_DESTCOLOR;
        return true;
    case NSBRenderStates::NSB_BLEND_INVDESTCOLOR:
        uiD3DValue = (unsigned int)D3DBLEND_INVDESTCOLOR;
        return true;
    case NSBRenderStates::NSB_BLEND_SRCALPHASAT:
        uiD3DValue = (unsigned int)D3DBLEND_SRCALPHASAT;
        return true;
    case NSBRenderStates::NSB_BLEND_BOTHSRCALPHA:
        uiD3DValue = (unsigned int)D3DBLEND_BOTHSRCALPHA;
        return true;
    case NSBRenderStates::NSB_BLEND_BOTHINVSRCALPHA:
        uiD3DValue = (unsigned int)D3DBLEND_BOTHINVSRCALPHA;
        return true;
    case NSBRenderStates::NSB_BLEND_BLENDFACTOR:
        uiD3DValue = (unsigned int)D3DBLEND_BLENDFACTOR;
        return true;
    case NSBRenderStates::NSB_BLEND_INVBLENDFACTOR:
        uiD3DValue = (unsigned int)D3DBLEND_INVBLENDFACTOR;
        return true;
    default:
        return false;
    }
}

//--------------------------------------------------------------------------------------------------
__forceinline bool GetD3DCull(
    NSBRenderStates::NSBCull eCull, 
    unsigned int& uiD3DValue)
{
    switch (eCull)
    {
    case NSBRenderStates::NSB_CULL_NONE:
        uiD3DValue = (unsigned int)D3DCULL_NONE;
        return true;
    case NSBRenderStates::NSB_CULL_CW:
        uiD3DValue = (unsigned int)D3DCULL_CW;
        return true;
    case NSBRenderStates::NSB_CULL_CCW:
        uiD3DValue = (unsigned int)D3DCULL_CCW;
        return true;
    default:
        return false;
    }
}

//--------------------------------------------------------------------------------------------------
__forceinline bool GetD3DCmpFunc(
    NSBRenderStates::NSBCmpFunc eCmpFunc,
    unsigned int& uiD3DValue)
{
    switch (eCmpFunc)
    {
    case NSBRenderStates::NSB_CMP_NEVER:
        uiD3DValue = (unsigned int)D3DCMP_NEVER;
        return true;
    case NSBRenderStates::NSB_CMP_LESS:
        uiD3DValue = (unsigned int)D3DCMP_LESS;
        return true;
    case NSBRenderStates::NSB_CMP_EQUAL:
        uiD3DValue = (unsigned int)D3DCMP_EQUAL;
        return true;
    case NSBRenderStates::NSB_CMP_LESSEQUAL:
        uiD3DValue = (unsigned int)D3DCMP_LESSEQUAL;
        return true;
    case NSBRenderStates::NSB_CMP_GREATER:
        uiD3DValue = (unsigned int)D3DCMP_GREATER;
        return true;
    case NSBRenderStates::NSB_CMP_NOTEQUAL:
        uiD3DValue = (unsigned int)D3DCMP_NOTEQUAL;
        return true;
    case NSBRenderStates::NSB_CMP_GREATEREQUAL:
        uiD3DValue = (unsigned int)D3DCMP_GREATEREQUAL;
        return true;
    case NSBRenderStates::NSB_CMP_ALWAYS:
        uiD3DValue = (unsigned int)D3DCMP_ALWAYS;
        return true;
    default:
        return false;
    }
}

//--------------------------------------------------------------------------------------------------
__forceinline bool GetD3DFogMode(
    NSBRenderStates::NSBFogMode eFogMode,
    unsigned int& uiD3DValue)
{
    switch (eFogMode)
    {
    case NSBRenderStates::NSB_FOG_NONE:
        uiD3DValue = (unsigned int)D3DFOG_NONE;
        return true;
    case NSBRenderStates::NSB_FOG_EXP:
        uiD3DValue = (unsigned int)D3DFOG_EXP;
        return true;
    case NSBRenderStates::NSB_FOG_EXP2:
        uiD3DValue = (unsigned int)D3DFOG_EXP2;
        return true;
    case NSBRenderStates::NSB_FOG_LINEAR:
        uiD3DValue = (unsigned int)D3DFOG_LINEAR;
        return true;
    default:
        return false;
    }
}

//--------------------------------------------------------------------------------------------------
__forceinline bool GetD3DStencilOp(
    NSBRenderStates::NSBStencilOp eStencilOp,
    unsigned int& uiD3DValue)
{
    switch (eStencilOp)
    {
    case NSBRenderStates::NSB_STENCTIL_OP_KEEP:
        uiD3DValue = (unsigned int)D3DSTENCILOP_KEEP;
        return true;
    case NSBRenderStates::NSB_STENCTIL_OP_ZERO:
        uiD3DValue = (unsigned int)D3DSTENCILOP_ZERO;
        return true;
    case NSBRenderStates::NSB_STENCTIL_OP_REPLACE:
        uiD3DValue = (unsigned int)D3DSTENCILOP_REPLACE;
        return true;
    case NSBRenderStates::NSB_STENCTIL_OP_INCRSAT:
        uiD3DValue = (unsigned int)D3DSTENCILOP_INCRSAT;
        return true;
    case NSBRenderStates::NSB_STENCTIL_OP_DECRSAT:
        uiD3DValue = (unsigned int)D3DSTENCILOP_DECRSAT;
        return true;
    case NSBRenderStates::NSB_STENCTIL_OP_INVERT:
        uiD3DValue = (unsigned int)D3DSTENCILOP_INVERT;
        return true;
    case NSBRenderStates::NSB_STENCTIL_OP_INCR:
        uiD3DValue = (unsigned int)D3DSTENCILOP_INCR;
        return true;
    case NSBRenderStates::NSB_STENCTIL_OP_DECR:
        uiD3DValue = (unsigned int)D3DSTENCILOP_DECR;
        return true;
    default:
        return false;
    }
}

//--------------------------------------------------------------------------------------------------
__forceinline bool GetD3DWrap(
    NSBRenderStates::NSBWrap eWrap, 
    unsigned int& uiD3DValue)
{
    switch (eWrap)
    {
    case NSBRenderStates::NSB_WRAP_DISABLED:
        uiD3DValue = 0;
        return true;
    case NSBRenderStates::NSB_WRAP_U:
        uiD3DValue = (unsigned int)D3DWRAP_U;
        return true;
    case NSBRenderStates::NSB_WRAP_V:
        uiD3DValue = (unsigned int)D3DWRAP_V;
        return true;
    case NSBRenderStates::NSB_WRAP_W:
        uiD3DValue = (unsigned int)D3DWRAP_W;
        return true;
    case NSBRenderStates::NSB_WRAP_UV:
        uiD3DValue = (unsigned int)(D3DWRAP_U | D3DWRAP_V);
        return true;
    case NSBRenderStates::NSB_WRAP_UW:
        uiD3DValue = (unsigned int)(D3DWRAP_U | D3DWRAP_W);
        return true;
    case NSBRenderStates::NSB_WRAP_VW:
        uiD3DValue = (unsigned int)(D3DWRAP_V | D3DWRAP_W);
        return true;
    case NSBRenderStates::NSB_WRAP_UVW:
        uiD3DValue = (unsigned int)(D3DWRAP_U | D3DWRAP_V | D3DWRAP_W);
        return true;
    default:
        return false;
    }
}

//--------------------------------------------------------------------------------------------------
__forceinline bool GetD3DMaterialColorSource(
    NSBRenderStates::NSBMaterialColorSource eMaterialColorSource, 
    unsigned int& uiD3DValue)
{
    switch (eMaterialColorSource)
    {
    case NSBRenderStates::NSB_MCS_MATERIAL:
        uiD3DValue = (unsigned int)D3DMCS_MATERIAL;
        return true;
    case NSBRenderStates::NSB_MCS_COLOR1:
        uiD3DValue = (unsigned int)D3DMCS_COLOR1;
        return true;
    case NSBRenderStates::NSB_MCS_COLOR2:
        uiD3DValue = (unsigned int)D3DMCS_COLOR2;
        return true;
    default:
        return false;
    }
}

//--------------------------------------------------------------------------------------------------
__forceinline bool GetD3DVertexBlendFlags(
    NSBRenderStates::NSBVertexBlendFlags eVertexBlendFlags, 
    unsigned int& uiD3DValue)
{
    switch (eVertexBlendFlags)
    {
    case NSBRenderStates::NSB_VBF_DISABLE:
        uiD3DValue = (unsigned int)D3DVBF_DISABLE;
        return true;
    case NSBRenderStates::NSB_VBF_1WEIGHTS:
        uiD3DValue = (unsigned int)D3DVBF_1WEIGHTS;
        return true;
    case NSBRenderStates::NSB_VBF_2WEIGHTS:
        uiD3DValue = (unsigned int)D3DVBF_2WEIGHTS;
        return true;
    case NSBRenderStates::NSB_VBF_3WEIGHTS:
        uiD3DValue = (unsigned int)D3DVBF_3WEIGHTS;
        return true;
    case NSBRenderStates::NSB_VBF_TWEENING:
        uiD3DValue = (unsigned int)D3DVBF_TWEENING;
        return true;
    case NSBRenderStates::NSB_VBF_0WEIGHTS:
        uiD3DValue = (unsigned int)D3DVBF_0WEIGHTS;
        return true;
    default:
        return false;
    }
}

//--------------------------------------------------------------------------------------------------
__forceinline bool GetD3DPatchEdgeStyle(
    NSBRenderStates::NSBPatchEdgeStyle ePatchEdgeStyle, 
    unsigned int& uiD3DValue)
{
    switch (ePatchEdgeStyle)
    {
    case NSBRenderStates::NSB_PATCH_EDGE_DISCRETE:
        uiD3DValue = (unsigned int)D3DPATCHEDGE_DISCRETE;
        return true;
    case NSBRenderStates::NSB_PATCH_EDGE_CONTINUOUS:
        uiD3DValue = (unsigned int)D3DPATCHEDGE_CONTINUOUS;
        return true;
    default:
        return false;
    }
}

//--------------------------------------------------------------------------------------------------
__forceinline bool GetD3DDebugMonitorTokens(
    NSBRenderStates::NSBDebugMonitorTokens eDebugMonitorTokens, 
    unsigned int& uiD3DValue)
{
    switch (eDebugMonitorTokens)
    {
    case NSBRenderStates::NSB_DMT_ENABLE:
        uiD3DValue = (unsigned int)D3DDMT_ENABLE;
        return true;
    case NSBRenderStates::NSB_DMT_DISABLE:
        uiD3DValue = (unsigned int)D3DDMT_DISABLE;
        return true;
    default:
        return false;
    }
}

//--------------------------------------------------------------------------------------------------
__forceinline bool GetD3DBlendOp(
    NSBRenderStates::NSBBlendOp eBlendOp,
    unsigned int& uiD3DValue)
{
    switch (eBlendOp)
    {
    case NSBRenderStates::NSB_BLENDOP_ADD:
        uiD3DValue = (unsigned int)D3DBLENDOP_ADD;
        return true;
    case NSBRenderStates::NSB_BLENDOP_SUBTRACT:
        uiD3DValue = (unsigned int)D3DBLENDOP_SUBTRACT;
        return true;
    case NSBRenderStates::NSB_BLENDOP_REVSUBTRACT:
        uiD3DValue = (unsigned int)D3DBLENDOP_REVSUBTRACT;
        return true;
    case NSBRenderStates::NSB_BLENDOP_MIN:
        uiD3DValue = (unsigned int)D3DBLENDOP_MIN;
        return true;
    case NSBRenderStates::NSB_BLENDOP_MAX:
        uiD3DValue = (unsigned int)D3DBLENDOP_MAX;
        return true;
    default:
        return false;
    }
}

//--------------------------------------------------------------------------------------------------
__forceinline bool GetD3DDegreeType(
    NSBRenderStates::NSBDegreeType eDegreeType,
    unsigned int& uiD3DValue)
{
    switch (eDegreeType)
    {
    case NSBRenderStates::NSB_DEGREE_LINEAR:
        uiD3DValue = (unsigned int)D3DDEGREE_LINEAR;
        return true;
    case NSBRenderStates::NSB_DEGREE_QUADRATIC:
        uiD3DValue = (unsigned int)D3DDEGREE_QUADRATIC;
        return true;
    case NSBRenderStates::NSB_DEGREE_CUBIC:
        uiD3DValue = (unsigned int)D3DDEGREE_CUBIC;
        return true;
    case NSBRenderStates::NSB_DEGREE_QUINTIC:
        uiD3DValue = (unsigned int)D3DDEGREE_QUINTIC;
        return true;
    default:
        return false;
    };
}

//--------------------------------------------------------------------------------------------------
__forceinline bool GetD3DTessellationMode(
    NSBRenderStates::NSBTessellationMode eTessMode,
    unsigned int& uiD3DValue)
{
    EE_UNUSED_ARG(eTessMode);
    EE_UNUSED_ARG(uiD3DValue); 
    return false;
}
} // namespace lib_nibsl_tail

using namespace lib_nibsl_tail;

//--------------------------------------------------------------------------------------------------
// NiBinaryShaderLibrary::ConvertNSBRenderStateValue: an NSB render-state value to its D3D value.
// @0x141cae4f0
bool FUN_141cae4f0(
    NSBRenderStates::NSBRenderStateEnum eNSBState, unsigned int uiNSBValue,
    unsigned int& uiD3DValue)
{
    bool bResult = true;

    switch (eNSBState)
    {
        // Simple states
    case NSBRenderStates::NSB_RS_ZFUNC:
    case NSBRenderStates::NSB_RS_ALPHAFUNC:
    case NSBRenderStates::NSB_RS_STENCILFUNC:
    case NSBRenderStates::NSB_RS_CCW_STENCILFUNC:
        bResult = GetD3DCmpFunc((NSBRenderStates::NSBCmpFunc)uiNSBValue, uiD3DValue);
        break;
    case NSBRenderStates::NSB_RS_SRCBLEND:
    case NSBRenderStates::NSB_RS_DESTBLEND:
        bResult = GetD3DBlend((NSBRenderStates::NSBBlend)uiNSBValue, uiD3DValue);
        break;
    case NSBRenderStates::NSB_RS_SHADEMODE:
        bResult = GetD3DShadeMode((NSBRenderStates::NSBShadeMode)uiNSBValue, uiD3DValue);
        break;
    case NSBRenderStates::NSB_RS_STENCILZFAIL:
    case NSBRenderStates::NSB_RS_STENCILPASS:
    case NSBRenderStates::NSB_RS_STENCILFAIL:
    case NSBRenderStates::NSB_RS_CCW_STENCILFAIL:
    case NSBRenderStates::NSB_RS_CCW_STENCILZFAIL:
    case NSBRenderStates::NSB_RS_CCW_STENCILPASS:
        bResult = GetD3DStencilOp((NSBRenderStates::NSBStencilOp)uiNSBValue, uiD3DValue);
        break;
    case NSBRenderStates::NSB_RS_BLENDOP:
        bResult = GetD3DBlendOp((NSBRenderStates::NSBBlendOp)uiNSBValue, uiD3DValue);
        break;
    case NSBRenderStates::NSB_RS_FOGTABLEMODE:
    case NSBRenderStates::NSB_RS_FOGVERTEXMODE:
        bResult = GetD3DFogMode((NSBRenderStates::NSBFogMode)uiNSBValue, uiD3DValue);
        break;
    case NSBRenderStates::NSB_RS_WRAP0:
    case NSBRenderStates::NSB_RS_WRAP1:
    case NSBRenderStates::NSB_RS_WRAP2:
    case NSBRenderStates::NSB_RS_WRAP3:
    case NSBRenderStates::NSB_RS_WRAP4:
    case NSBRenderStates::NSB_RS_WRAP5:
    case NSBRenderStates::NSB_RS_WRAP6:
    case NSBRenderStates::NSB_RS_WRAP7:
    case NSBRenderStates::NSB_RS_WRAP8:
    case NSBRenderStates::NSB_RS_WRAP9:
    case NSBRenderStates::NSB_RS_WRAP10:
    case NSBRenderStates::NSB_RS_WRAP11:
    case NSBRenderStates::NSB_RS_WRAP12:
    case NSBRenderStates::NSB_RS_WRAP13:
    case NSBRenderStates::NSB_RS_WRAP14:
    case NSBRenderStates::NSB_RS_WRAP15:
        bResult = GetD3DWrap((NSBRenderStates::NSBWrap)uiNSBValue, uiD3DValue);
        break;
    case NSBRenderStates::NSB_RS_SPECULARMATERIALSOURCE:
    case NSBRenderStates::NSB_RS_DIFFUSEMATERIALSOURCE:
    case NSBRenderStates::NSB_RS_AMBIENTMATERIALSOURCE:
    case NSBRenderStates::NSB_RS_EMISSIVEMATERIALSOURCE:
        bResult = GetD3DMaterialColorSource(
            (NSBRenderStates::NSBMaterialColorSource)uiNSBValue, uiD3DValue);
        break;
    case NSBRenderStates::NSB_RS_PATCHEDGESTYLE:
        bResult = GetD3DPatchEdgeStyle((NSBRenderStates::NSBPatchEdgeStyle)uiNSBValue,
            uiD3DValue);
        break;
    case NSBRenderStates::NSB_RS_VERTEXBLEND:
        bResult = GetD3DVertexBlendFlags((NSBRenderStates::NSBVertexBlendFlags)uiNSBValue,
            uiD3DValue);
        break;
    case NSBRenderStates::NSB_RS_FILLMODE:
        bResult = GetD3DFillMode((NSBRenderStates::NSBFillMode)uiNSBValue, uiD3DValue);
        break;
    case NSBRenderStates::NSB_RS_ZENABLE:
        bResult = GetD3DZBufferType((NSBRenderStates::NSBZBufferType)uiNSBValue,
            uiD3DValue);
        break;
    case NSBRenderStates::NSB_RS_CULLMODE:
        bResult = GetD3DCull((NSBRenderStates::NSBCull)uiNSBValue, uiD3DValue);
        break;
    case NSBRenderStates::NSB_RS_DEBUGMONITORTOKEN:
        bResult = GetD3DDebugMonitorTokens(
            (NSBRenderStates::NSBDebugMonitorTokens)uiNSBValue, uiD3DValue);
        break;
    case NSBRenderStates::NSB_RS_POSITIONDEGREE:
    case NSBRenderStates::NSB_RS_NORMALDEGREE:
        bResult = GetD3DDegreeType((NSBRenderStates::NSBDegreeType)uiNSBValue, uiD3DValue);
        break;
    case NSBRenderStates::NSB_RS_TESSELLATIONMODE:
        bResult = GetD3DTessellationMode((NSBRenderStates::NSBTessellationMode)uiNSBValue,
            uiD3DValue);
        break;
    default:
        // Assume we are passing the value straight through!
        uiD3DValue = uiNSBValue;
        bResult = true;
        break;
    }

    return bResult;
}
//--------------------------------------------------------------------------------------------------
// NiBinaryShaderLibrary::GetD3DRenderStateType: an NSB render state to its D3DRENDERSTATETYPE.
// @0x141caeee0
bool FUN_141caeee0(
    NSBRenderStates::NSBRenderStateEnum eRenderState,
    D3DRENDERSTATETYPE& eD3DRS)
{
    switch (eRenderState)
    {
    case NSBRenderStates::NSB_RS_ZENABLE:
        eD3DRS = D3DRS_ZENABLE;
        return true;
    case NSBRenderStates::NSB_RS_FILLMODE:
        eD3DRS = D3DRS_FILLMODE;
        return true;
    case NSBRenderStates::NSB_RS_ZWRITEENABLE:
        eD3DRS = D3DRS_ZWRITEENABLE;
        return true;
    case NSBRenderStates::NSB_RS_ALPHATESTENABLE:
        eD3DRS = D3DRS_ALPHATESTENABLE;
        return true;
    case NSBRenderStates::NSB_RS_SRCBLEND:
        eD3DRS = D3DRS_SRCBLEND;
        return true;
    case NSBRenderStates::NSB_RS_DESTBLEND:
        eD3DRS = D3DRS_DESTBLEND;
        return true;
    case NSBRenderStates::NSB_RS_CULLMODE:
        eD3DRS = D3DRS_CULLMODE;
        return true;
    case NSBRenderStates::NSB_RS_ZFUNC:
        eD3DRS = D3DRS_ZFUNC;
        return true;
    case NSBRenderStates::NSB_RS_ALPHAREF:
        eD3DRS = D3DRS_ALPHAREF;
        return true;
    case NSBRenderStates::NSB_RS_ALPHAFUNC:
        eD3DRS = D3DRS_ALPHAFUNC;
        return true;
    case NSBRenderStates::NSB_RS_ALPHABLENDENABLE:
        eD3DRS = D3DRS_ALPHABLENDENABLE;
        return true;
    case NSBRenderStates::NSB_RS_STENCILENABLE:
        eD3DRS = D3DRS_STENCILENABLE;
        return true;
    case NSBRenderStates::NSB_RS_STENCILFAIL:
        eD3DRS = D3DRS_STENCILFAIL;
        return true;
    case NSBRenderStates::NSB_RS_STENCILZFAIL:
        eD3DRS = D3DRS_STENCILZFAIL;
        return true;
    case NSBRenderStates::NSB_RS_STENCILPASS:
        eD3DRS = D3DRS_STENCILPASS;
        return true;
    case NSBRenderStates::NSB_RS_STENCILFUNC:
        eD3DRS = D3DRS_STENCILFUNC;
        return true;
    case NSBRenderStates::NSB_RS_STENCILREF:
        eD3DRS = D3DRS_STENCILREF;
        return true;
    case NSBRenderStates::NSB_RS_STENCILMASK:
        eD3DRS = D3DRS_STENCILMASK;
        return true;
    case NSBRenderStates::NSB_RS_STENCILWRITEMASK:
        eD3DRS = D3DRS_STENCILWRITEMASK;
        return true;
    case NSBRenderStates::NSB_RS_WRAP0:
        eD3DRS = D3DRS_WRAP0;
        return true;
    case NSBRenderStates::NSB_RS_WRAP1:
        eD3DRS = D3DRS_WRAP1;
        return true;
    case NSBRenderStates::NSB_RS_WRAP2:
        eD3DRS = D3DRS_WRAP2;
        return true;
    case NSBRenderStates::NSB_RS_WRAP3:
        eD3DRS = D3DRS_WRAP3;
        return true;
    case NSBRenderStates::NSB_RS_WRAP4:
        eD3DRS = D3DRS_WRAP4;
        return true;
    case NSBRenderStates::NSB_RS_WRAP5:
        eD3DRS = D3DRS_WRAP5;
        return true;
    case NSBRenderStates::NSB_RS_WRAP6:
        eD3DRS = D3DRS_WRAP6;
        return true;
    case NSBRenderStates::NSB_RS_WRAP7:
        eD3DRS = D3DRS_WRAP7;
        return true;
    case NSBRenderStates::NSB_RS_CLIPPLANEENABLE:
        eD3DRS = D3DRS_CLIPPLANEENABLE;
        return true;
    case NSBRenderStates::NSB_RS_POINTSIZE:
        eD3DRS = D3DRS_POINTSIZE;
        return true;
    case NSBRenderStates::NSB_RS_POINTSIZE_MIN:
        eD3DRS = D3DRS_POINTSIZE_MIN;
        return true;
    case NSBRenderStates::NSB_RS_POINTSPRITEENABLE:
        eD3DRS = D3DRS_POINTSPRITEENABLE;
        return true;
    case NSBRenderStates::NSB_RS_MULTISAMPLEANTIALIAS:
        eD3DRS = D3DRS_MULTISAMPLEANTIALIAS;
        return true;
    case NSBRenderStates::NSB_RS_MULTISAMPLEMASK:
        eD3DRS = D3DRS_MULTISAMPLEMASK;
        return true;
    case NSBRenderStates::NSB_RS_POINTSIZE_MAX:
        eD3DRS = D3DRS_POINTSIZE_MAX;
        return true;
    case NSBRenderStates::NSB_RS_COLORWRITEENABLE:
        eD3DRS = D3DRS_COLORWRITEENABLE;
        return true;
    case NSBRenderStates::NSB_RS_BLENDOP:
        eD3DRS = D3DRS_BLENDOP;
        return true;
    case NSBRenderStates::NSB_RS_SCISSORTESTENABLE:
        eD3DRS = D3DRS_SCISSORTESTENABLE;
        return true;
    case NSBRenderStates::NSB_RS_SLOPESCALEDEPTHBIAS:
        eD3DRS = D3DRS_SLOPESCALEDEPTHBIAS;
        return true;
    case NSBRenderStates::NSB_RS_MINTESSELLATIONLEVEL:
        eD3DRS = D3DRS_MINTESSELLATIONLEVEL;
        return true;
    case NSBRenderStates::NSB_RS_MAXTESSELLATIONLEVEL:
        eD3DRS = D3DRS_MAXTESSELLATIONLEVEL;
        return true;
    case NSBRenderStates::NSB_RS_TWOSIDEDSTENCILMODE:
        eD3DRS = D3DRS_TWOSIDEDSTENCILMODE;
        return true;
    case NSBRenderStates::NSB_RS_CCW_STENCILFAIL:
        eD3DRS = D3DRS_CCW_STENCILFAIL;
        return true;
    case NSBRenderStates::NSB_RS_CCW_STENCILZFAIL:
        eD3DRS = D3DRS_CCW_STENCILZFAIL;
        return true;
    case NSBRenderStates::NSB_RS_CCW_STENCILPASS:
        eD3DRS = D3DRS_CCW_STENCILPASS;
        return true;
    case NSBRenderStates::NSB_RS_CCW_STENCILFUNC:
        eD3DRS = D3DRS_CCW_STENCILFUNC;
        return true;
    case NSBRenderStates::NSB_RS_COLORWRITEENABLE1:
        eD3DRS = D3DRS_COLORWRITEENABLE1;
        return true;
    case NSBRenderStates::NSB_RS_COLORWRITEENABLE2:
        eD3DRS = D3DRS_COLORWRITEENABLE2;
        return true;
    case NSBRenderStates::NSB_RS_COLORWRITEENABLE3:
        eD3DRS = D3DRS_COLORWRITEENABLE3;
        return true;
    case NSBRenderStates::NSB_RS_BLENDFACTOR:
        eD3DRS = D3DRS_BLENDFACTOR;
        return true;
    case NSBRenderStates::NSB_RS_DEPTHBIAS:
        eD3DRS = D3DRS_DEPTHBIAS;
        return true;
    case NSBRenderStates::NSB_RS_WRAP8:
        eD3DRS = D3DRS_WRAP8;
        return true;
    case NSBRenderStates::NSB_RS_WRAP9:
        eD3DRS = D3DRS_WRAP9;
        return true;
    case NSBRenderStates::NSB_RS_WRAP10:
        eD3DRS = D3DRS_WRAP10;
        return true;
    case NSBRenderStates::NSB_RS_WRAP11:
        eD3DRS = D3DRS_WRAP11;
        return true;
    case NSBRenderStates::NSB_RS_WRAP12:
        eD3DRS = D3DRS_WRAP12;
        return true;
    case NSBRenderStates::NSB_RS_WRAP13:
        eD3DRS = D3DRS_WRAP13;
        return true;
    case NSBRenderStates::NSB_RS_WRAP14:
        eD3DRS = D3DRS_WRAP14;
        return true;
    case NSBRenderStates::NSB_RS_WRAP15:
        eD3DRS = D3DRS_WRAP15;
        return true;
    case NSBRenderStates::NSB_RS_SEPARATEALPHABLENDENABLE:
        eD3DRS = D3DRS_SEPARATEALPHABLENDENABLE;
        return true;
    case NSBRenderStates::NSB_RS_SRCBLENDALPHA:
        eD3DRS = D3DRS_SRCBLENDALPHA;
        return true;
    case NSBRenderStates::NSB_RS_DESTBLENDALPHA:
        eD3DRS = D3DRS_DESTBLENDALPHA;
        return true;
    case NSBRenderStates::NSB_RS_BLENDOPALPHA:
        eD3DRS = D3DRS_BLENDOPALPHA;
        return true;

    case NSBRenderStates::NSB_RS_SHADEMODE:
        eD3DRS = D3DRS_SHADEMODE;
        return true;
    case NSBRenderStates::NSB_RS_LASTPIXEL:
        eD3DRS = D3DRS_LASTPIXEL;
        return true;
    case NSBRenderStates::NSB_RS_DITHERENABLE:
        eD3DRS = D3DRS_DITHERENABLE;
        return true;
    case NSBRenderStates::NSB_RS_FOGENABLE:
        eD3DRS = D3DRS_FOGENABLE;
        return true;
    case NSBRenderStates::NSB_RS_SPECULARENABLE:
        eD3DRS = D3DRS_SPECULARENABLE;
        return true;
    case NSBRenderStates::NSB_RS_FOGCOLOR:
        eD3DRS = D3DRS_FOGCOLOR;
        return true;
    case NSBRenderStates::NSB_RS_FOGTABLEMODE:
        eD3DRS = D3DRS_FOGTABLEMODE;
        return true;
    case NSBRenderStates::NSB_RS_FOGSTART:
        eD3DRS = D3DRS_FOGSTART;
        return true;
    case NSBRenderStates::NSB_RS_FOGEND:
        eD3DRS = D3DRS_FOGEND;
        return true;
    case NSBRenderStates::NSB_RS_FOGDENSITY:
        eD3DRS = D3DRS_FOGDENSITY;
        return true;
    case NSBRenderStates::NSB_RS_RANGEFOGENABLE:
        eD3DRS = D3DRS_RANGEFOGENABLE;
        return true;
    case NSBRenderStates::NSB_RS_TEXTUREFACTOR:
        eD3DRS = D3DRS_TEXTUREFACTOR;
        return true;
    case NSBRenderStates::NSB_RS_CLIPPING:
        eD3DRS = D3DRS_CLIPPING;
        return true;
    case NSBRenderStates::NSB_RS_LIGHTING:
        eD3DRS = D3DRS_LIGHTING;
        return true;
    case NSBRenderStates::NSB_RS_AMBIENT:
        eD3DRS = D3DRS_AMBIENT;
        return true;
    case NSBRenderStates::NSB_RS_FOGVERTEXMODE:
        eD3DRS = D3DRS_FOGVERTEXMODE;
        return true;
    case NSBRenderStates::NSB_RS_COLORVERTEX:
        eD3DRS = D3DRS_COLORVERTEX;
        return true;
    case NSBRenderStates::NSB_RS_LOCALVIEWER:
        eD3DRS = D3DRS_LOCALVIEWER;
        return true;
    case NSBRenderStates::NSB_RS_NORMALIZENORMALS:
        eD3DRS = D3DRS_NORMALIZENORMALS;
        return true;
    case NSBRenderStates::NSB_RS_DIFFUSEMATERIALSOURCE :
        eD3DRS = D3DRS_DIFFUSEMATERIALSOURCE ;
        return true;
    case NSBRenderStates::NSB_RS_SPECULARMATERIALSOURCE:
        eD3DRS = D3DRS_SPECULARMATERIALSOURCE;
        return true;
    case NSBRenderStates::NSB_RS_AMBIENTMATERIALSOURCE:
        eD3DRS = D3DRS_AMBIENTMATERIALSOURCE;
        return true;
    case NSBRenderStates::NSB_RS_EMISSIVEMATERIALSOURCE:
        eD3DRS = D3DRS_EMISSIVEMATERIALSOURCE;
        return true;
    case NSBRenderStates::NSB_RS_VERTEXBLEND:
        eD3DRS = D3DRS_VERTEXBLEND;
        return true;
    case NSBRenderStates::NSB_RS_POINTSCALEENABLE:
        eD3DRS = D3DRS_POINTSCALEENABLE;
        return true;
    case NSBRenderStates::NSB_RS_POINTSCALE_A:
        eD3DRS = D3DRS_POINTSCALE_A;
        return true;
    case NSBRenderStates::NSB_RS_POINTSCALE_B:
        eD3DRS = D3DRS_POINTSCALE_B;
        return true;
    case NSBRenderStates::NSB_RS_POINTSCALE_C:
        eD3DRS = D3DRS_POINTSCALE_C;
        return true;
    case NSBRenderStates::NSB_RS_PATCHEDGESTYLE:
        eD3DRS = D3DRS_PATCHEDGESTYLE;
        return true;
    case NSBRenderStates::NSB_RS_DEBUGMONITORTOKEN:
        eD3DRS = D3DRS_DEBUGMONITORTOKEN;
        return true;
    case NSBRenderStates::NSB_RS_INDEXEDVERTEXBLENDENABLE:
        eD3DRS = D3DRS_INDEXEDVERTEXBLENDENABLE;
        return true;
    case NSBRenderStates::NSB_RS_TWEENFACTOR:
        eD3DRS = D3DRS_TWEENFACTOR;
        return true;
    case NSBRenderStates::NSB_RS_POSITIONDEGREE:
        eD3DRS = D3DRS_POSITIONDEGREE;
        return true;
    case NSBRenderStates::NSB_RS_NORMALDEGREE:
        eD3DRS = D3DRS_NORMALDEGREE;
        return true;
    case NSBRenderStates::NSB_RS_ANTIALIASEDLINEENABLE:
        eD3DRS = D3DRS_ANTIALIASEDLINEENABLE;
        return true;
    case NSBRenderStates::NSB_RS_ADAPTIVETESS_X:
        eD3DRS = D3DRS_ADAPTIVETESS_X;
        return true;
    case NSBRenderStates::NSB_RS_ADAPTIVETESS_Y:
        eD3DRS = D3DRS_ADAPTIVETESS_Y;
        return true;
    case NSBRenderStates::NSB_RS_ADAPTIVETESS_Z:
        eD3DRS = D3DRS_ADAPTIVETESS_Z;
        return true;
    case NSBRenderStates::NSB_RS_ADAPTIVETESS_W:
        eD3DRS = D3DRS_ADAPTIVETESS_W;
        return true;
    case NSBRenderStates::NSB_RS_ENABLEADAPTIVETESSELLATION:
        eD3DRS = D3DRS_ENABLEADAPTIVETESSELLATION;
        return true;
    case NSBRenderStates::NSB_RS_SRGBWRITEENABLE:
        eD3DRS = D3DRS_SRGBWRITEENABLE;
        return true;


    default:
        return false;
    }
}