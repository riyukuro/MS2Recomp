// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MS2UIMaterialNodeLibrary: the small fragment library of
// MS2UIMaterial, in the generated NiMaterialNodeXMLLibraryParser shape (see ms2materialnodelibrary.cpp). Bodies
// regenerated from the exe's data by work/gb14/genlib.py; the TU has no __FILE__ strings, file name guessed.
// MS2-UNIT: ?\ms2uimaterialnodelibrary.cpp
// MS2-RANGE: 0x142777210-0x1427784c0 .text$mn
// MS2-FLAGS: gamebryo
#include "ms2/placeholder/ms2stdafx.h"

#include <NiMaterialFragmentNode.h>
#include <NiMaterialNodeLibrary.h>
#include <NiMaterialResource.h>
#include <NiCodeBlock.h>
#include "ms2/client/ms2/material/ms2materialnodelibrary.h"

//--------------------------------------------------------------------------------------------------
// @0x142777210
EE_NOINLINE static void CreateFragment0(NiMaterialNodeLibrary* pkLib)
{
    NiMaterialFragmentNode* pkFrag = NiNew NiMaterialFragmentNode();

    pkFrag->SetType("Pixel/Vertex");
    pkFrag->SetName("MonochromeCompositeFinalRGBColor");
    pkFrag->SetDescription("\n"
        "    This fragment is responsible for computing the final RGB color.\n"
        "  ");
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetVariable("DiffuseColor");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetVariable("SpecularColor");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float");
        pkRes->SetVariable("MonochromeLevel");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetVariable("OutputColor");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiCodeBlock* pkBlock = NiNew NiCodeBlock();

        pkBlock->SetLanguage("hlsl/Cg");
        pkBlock->SetPlatform("D3D11/D3D10/DX9/Xenon/PS3");
        pkBlock->SetTarget("vs_1_1/ps_2_0/vs_4_0/ps_4_0/vs_5_0/ps_5_0");
        pkBlock->SetText("\n"
            "    OutputColor.rgb = DiffuseColor.rgb + SpecularColor.rgb;\n"
            "    OutputColor.rgb = OutputColor.rgb * MonochromeLevel + (OutputColor.r + OutputColor.g + OutputColor.b) / 3.0f * (1 - MonochromeLevel);\n"
            "  ");

        pkFrag->AddCodeBlock(pkBlock);
    }

    pkLib->AddNode(pkFrag);
}
//--------------------------------------------------------------------------------------------------
// @0x1427776b0
EE_NOINLINE static void CreateFragment1(NiMaterialNodeLibrary* pkLib)
{
    NiMaterialFragmentNode* pkFrag = NiNew NiMaterialFragmentNode();

    pkFrag->SetType("Pixel/Vertex");
    pkFrag->SetName("PositionToVelocity");
    pkFrag->SetDescription("  \n"
        "    This fragment is responsible for computing Vertex's velocity.\n"
        "  ");
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("POSITION");
        pkRes->SetVariable("vWorldPos");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4x4");
        pkRes->SetVariable("mViewProjection");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4x4");
        pkRes->SetVariable("mViewProjectionLast");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float2");
        pkRes->SetVariable("velocity");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiCodeBlock* pkBlock = NiNew NiCodeBlock();

        pkBlock->SetLanguage("hlsl/Cg");
        pkBlock->SetPlatform("D3D11/D3D10/DX9/Xenon/PS3");
        pkBlock->SetTarget("vs_1_1/ps_2_0/vs_4_0/ps_4_0/vs_5_0/ps_5_0");
        pkBlock->SetText("\n"
            "\n"
            "    // Transform from object space to homogeneous projection space\n"
            "\n"
            "\n"
            "    float4 vPosProjSpaceCurrent =  mul(vWorldPos, mViewProjection);\n"
            "    float4 vPosProjSpaceLast = mul(vWorldPos, mViewProjectionLast);\n"
            "\n"
            "    // Convert to non-homogeneous points [-1,1] by dividing by w\n"
            "    vPosProjSpaceCurrent /= vPosProjSpaceCurrent.w;\n"
            "    vPosProjSpaceLast /= vPosProjSpaceLast.w;\n"
            "\n"
            "    // Vertex's velocity (in non-homogeneous projection space) is the position this frame minus\n"
            "    // its position last frame.  This information is stored in a texture coord.  The pixel shader\n"
            "    // will read the texture coordinate with a sampler and use it to output each pixel's velocity.\n"
            "    velocity = vPosProjSpaceCurrent - vPosProjSpaceLast;\n"
            "\n"
            "    // The velocity is now between (-2,2) so divide by 2 to get it to (-1,1)\n"
            "    velocity /= 2.0f;\n"
            "    \n"
            "  ");

        pkFrag->AddCodeBlock(pkBlock);
    }

    pkLib->AddNode(pkFrag);
}
//--------------------------------------------------------------------------------------------------
// @0x142777ae0
EE_NOINLINE static void CreateFragment2(NiMaterialNodeLibrary* pkLib)
{
    NiMaterialFragmentNode* pkFrag = NiNew NiMaterialFragmentNode();

    pkFrag->SetType("Pixel/Vertex");
    pkFrag->SetName("Float2ToFloat4");
    pkFrag->SetDescription("\n"
        "    haha\n"
        "  ");
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float2");
        pkRes->SetSemantic("TEXCOORD1 ");
        pkRes->SetVariable("Input");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("COLOR0");
        pkRes->SetVariable("Output");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiCodeBlock* pkBlock = NiNew NiCodeBlock();

        pkBlock->SetLanguage("hlsl/Cg");
        pkBlock->SetPlatform("D3D11/D3D10/DX9/Xenon/PS3");
        pkBlock->SetTarget("vs_1_1/ps_2_0/vs_4_0/ps_4_0/vs_5_0/ps_5_0");
        pkBlock->SetText("\n"
            "\n"
            "    // Velocity of this pixel simply equals the linear interpolation of the\n"
            "    // velocity of this triangle's vertices.  The interpolation is done\n"
            "    // automatically since the velocity is stored in a texture coord.\n"
            "    // We're storing the velocity in .R  .G channels and the app creates\n"
            "    // a D3DFMT_G16R16F texture to store this info in high precison.\n"
            "    Output = float4( Input, 1.0f, 1.0f );\n"
            "  ");

        pkFrag->AddCodeBlock(pkBlock);
    }

    pkLib->AddNode(pkFrag);
}
//--------------------------------------------------------------------------------------------------
// @0x142777e00
EE_NOINLINE static void CreateFragment3(NiMaterialNodeLibrary* pkLib)
{
    NiMaterialFragmentNode* pkFrag = NiNew NiMaterialFragmentNode();

    pkFrag->SetType("Vertex/Pixel");
    pkFrag->SetName("ProjectPositionWorldToViewToProj_Outer");
    pkFrag->SetDescription("\n"
        "    This fragment is responsible for applying the view projection transform\n"
        "    to the input world position.\n"
        "  ");
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("Position");
        pkRes->SetLabel("World");
        pkRes->SetVariable("WorldPosition");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Normal");
        pkRes->SetVariable("WorldNormal");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4x4");
        pkRes->SetSemantic("ViewMatrix");
        pkRes->SetVariable("ViewTransform");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4x4");
        pkRes->SetSemantic("ProjMatrix");
        pkRes->SetVariable("ProjTransform");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("Position");
        pkRes->SetLabel("View");
        pkRes->SetVariable("ViewPos");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("Position");
        pkRes->SetLabel("Proj");
        pkRes->SetVariable("ProjPos");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiCodeBlock* pkBlock = NiNew NiCodeBlock();

        pkBlock->SetLanguage("hlsl/Cg");
        pkBlock->SetPlatform("D3D11/D3D10/DX9/Xenon/PS3");
        pkBlock->SetTarget("vs_1_1/ps_2_0/vs_4_0/ps_4_0/vs_5_0/ps_5_0");
        pkBlock->SetText("\n"
            "    ViewPos = mul(WorldPosition, ViewTransform);\n"
            "\n"
            "\n"
            "    float3 ViewNormal =  mul(WorldNormal, (float3x3)ViewTransform);\n"
            "\n"
            "    if (ViewNormal.z >= -0.1f || ViewNormal.z <= 0.1f)\n"
            "      ViewPos.xyz += ViewNormal * 3.0f;\n"
            "\n"
            "    ProjPos = mul(ViewPos, ProjTransform);\n"
            "  ");

        pkFrag->AddCodeBlock(pkBlock);
    }

    pkLib->AddNode(pkFrag);
}
//--------------------------------------------------------------------------------------------------
// @0x142778450
NiMaterialNodeLibrary* MS2UIMaterialNodeLibrary::CreateMaterialNodeLibrary()
{
    NiMaterialNodeLibrary* pkLib = NiNew NiMaterialNodeLibrary(1);

    CreateFragment0(pkLib);
    CreateFragment1(pkLib);
    CreateFragment2(pkLib);
    CreateFragment3(pkLib);

    return pkLib;
}

// MS2-PIN: ??_7?$NiTArray@V?$SmartPointer@VNiCodeBlock@@@efd@@V?$NiTNewInterface@V?$SmartPointer@VNiCodeBlock@@@efd@@@@@@6B@ 0x143026d38
// MS2-PIN: ??_7?$NiTObjectArray@V?$SmartPointer@VNiCodeBlock@@@efd@@@@6B@ 0x143026d40
// MS2-PIN: ??_7NiMaterialFragmentNode@@6B@ 0x143026d48
