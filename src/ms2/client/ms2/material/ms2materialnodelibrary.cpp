// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MS2MaterialNodeLibrary: the shader fragment library of the
// MS2 fragment materials, in the shape the Gamebryo NiMaterialNodeXMLLibraryParser tool generates (one CreateFragmentN
// per <fragment>, then the creator calling them in XML order). The fragment bodies are regenerated from the exe's data
// by work/gb14/genlib.py; the TU has no __FILE__ strings, file name guessed.
// MS2-UNIT: ?\ms2materialnodelibrary.cpp
// MS2-RANGE: 0x142756aa0-0x142767180 .text$mn
// MS2-FLAGS: gamebryo
#include "ms2/placeholder/ms2stdafx.h"

#include <NiMaterialFragmentNode.h>
#include <NiMaterialNodeLibrary.h>
#include <NiMaterialResource.h>
#include <NiCodeBlock.h>
#include "ms2/client/ms2/material/ms2materialnodelibrary.h"

//--------------------------------------------------------------------------------------------------
// @0x142756aa0
EE_NOINLINE static void CreateFragment0(NiMaterialNodeLibrary* pkLib)
{
    NiMaterialFragmentNode* pkFrag = NiNew NiMaterialFragmentNode();

    pkFrag->SetType("Vertex/Pixel");
    pkFrag->SetName("MS2Light");
    pkFrag->SetDescription("\n"
        "      This fragment is responsible for accumulating the effect of a light\n"
        "      on the current pixel.\n"
        "\n"
        "      LightType can be one of three values:\n"
        "      0 - Directional\n"
        "      1 - Point\n"
        "      2 - Spot\n"
        "\n"
        "      Note that the LightType must be a compile-time variable,\n"
        "      not a runtime constant/uniform variable on most Shader Model 2.0 cards.\n"
        "\n"
        "      The compiler will optimize out any constants that aren't used.\n"
        "\n"
        "      Attenuation is defined as (const, linear, quad, range).\n"
        "      Range is not implemented at this time.\n"
        "\n"
        "      SpotAttenuation is stored as (cos(theta/2), cos(phi/2), falloff)\n"
        "      theta is the angle of the inner cone and phi is the angle of the outer\n"
        "      cone in the traditional DX manner. Gamebryo only allows setting of\n"
        "      phi, so cos(theta/2) will typically be cos(0) or 1. To disable spot\n"
        "      effects entirely, set cos(theta/2) and cos(phi/2) to -1 or lower.\n"
        "    ");
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("Position");
        pkRes->SetLabel("World");
        pkRes->SetVariable("WorldPos");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Normal");
        pkRes->SetLabel("World");
        pkRes->SetVariable("WorldNrm");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("int");
        pkRes->SetSemantic("LightType");
        pkRes->SetVariable("LightType");
        pkRes->SetDefaultValue("(0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("bool");
        pkRes->SetSemantic("Specularity");
        pkRes->SetVariable("SpecularEnable");
        pkRes->SetDefaultValue("(false)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float");
        pkRes->SetSemantic("Shadow");
        pkRes->SetVariable("Shadow");
        pkRes->SetDefaultValue("(1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("ViewVector");
        pkRes->SetLabel("World");
        pkRes->SetVariable("WorldViewVector");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("LightPos");
        pkRes->SetLabel("World");
        pkRes->SetVariable("LightPos");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("LightAmbient");
        pkRes->SetVariable("LightAmbient");
        pkRes->SetDefaultValue("(1.0, 1.0, 1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("LightDiffuse");
        pkRes->SetVariable("LightDiffuse");
        pkRes->SetDefaultValue("(1.0, 1.0, 1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("LightSpecular");
        pkRes->SetVariable("LightSpecular");
        pkRes->SetDefaultValue("(1.0, 1.0, 1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("LightAttenuation");
        pkRes->SetVariable("LightAttenuation");
        pkRes->SetDefaultValue("(0.0, 1.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("LightSpotAttenuation");
        pkRes->SetVariable("LightSpotAttenuation");
        pkRes->SetDefaultValue("(-1.0, -1.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("LightDirection");
        pkRes->SetVariable("LightDirection");
        pkRes->SetDefaultValue("(1.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Specular");
        pkRes->SetVariable("SpecularPower");
        pkRes->SetDefaultValue("(1.0, 1.0, 1.0, 1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Ambient");
        pkRes->SetVariable("AmbientAccum");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Diffuse");
        pkRes->SetVariable("DiffuseAccum");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Specular");
        pkRes->SetVariable("SpecularAccum");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Ambient");
        pkRes->SetVariable("AmbientAccumOut");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Diffuse");
        pkRes->SetVariable("DiffuseAccumOut");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Specular");
        pkRes->SetVariable("SpecularAccumOut");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiCodeBlock* pkBlock = NiNew NiCodeBlock();

        pkBlock->SetLanguage("hlsl/Cg");
        pkBlock->SetPlatform("D3D11/D3D10/DX9/Xenon/PS3");
        pkBlock->SetTarget("vs_1_1/ps_2_0/vs_4_0/ps_4_0/vs_5_0/ps_5_0");
        pkBlock->SetText("\n"
            "      // Get the world space light vector.\n"
            "      float3 LightVector;\n"
            "      float DistanceToLight;\n"
            "      float DistanceToLightSquared;\n"
            "\n"
            "      if (LightType == 0)\n"
            "      {\n"
            "        LightVector = -LightDirection;\n"
            "      }\n"
            "      else\n"
            "      {\n"
            "        LightVector = LightPos - WorldPos;\n"
            "        DistanceToLightSquared = dot(LightVector, LightVector);\n"
            "        DistanceToLight = length(LightVector);\n"
            "        LightVector = normalize(LightVector);\n"
            "      }\n"
            "\n"
            "      // Take N dot L as intensity.\n"
            "      float LightNDotL = dot(LightVector, WorldNrm);\n"
            "      float LightIntensity = max(0, LightNDotL);\n"
            "\n"
            "      float Attenuate = Shadow;\n"
            "\n"
            "      if (LightType != 0)\n"
            "      {\n"
            "        // Attenuate Here\n"
            "        Attenuate = LightAttenuation.x +\n"
            "        LightAttenuation.y * DistanceToLight +\n"
            "        LightAttenuation.z * DistanceToLightSquared;\n"
            "        Attenuate = max(1.0, Attenuate);\n"
            "        Attenuate = 1.0 / Attenuate;\n"
            "        Attenuate *= Shadow;\n"
            "\n"
            "        if (LightType == 2)\n"
            "        {\n"
            "          // Get intensity as cosine of light vector and direction.\n"
            "          float CosAlpha = dot(-LightVector, LightDirection);\n"
            "\n"
            "          // Factor in inner and outer cone angles.\n"
            "          float AttenDiff = LightSpotAttenuation.x - LightSpotAttenuation.y;\n"
            "          CosAlpha = saturate((CosAlpha - LightSpotAttenuation.y) /\n"
            "          AttenDiff);\n"
            "\n"
            "          // Power to falloff.\n"
            "          // The pow() here can create a NaN if CosAlpha is 0 or less.\n"
            "          // On some cards (GeForce 6800), the NaN will propagate through\n"
            "          // a ternary instruction, so we need two to be safe.\n"
            "          float origCosAlpha = CosAlpha;\n"
            "          CosAlpha = origCosAlpha <= 0.0 ? 1.0 : CosAlpha;\n"
            "          CosAlpha = pow(CosAlpha, LightSpotAttenuation.z);\n"
            "          CosAlpha = origCosAlpha <= 0.0 ? 0.0 : CosAlpha;\n"
            "\n"
            "      // Multiply the spot attenuation into the overall attenuation.\n"
            "      Attenuate *= CosAlpha;\n"
            "      }\n"
            "      }\n"
            "      // Determine the interaction of diffuse color of light and material.\n"
            "      // Scale by the attenuated intensity.\n"
            "      DiffuseAccumOut = DiffuseAccum;\n"
            "\n"
            "      DiffuseAccumOut.rgb += LightDiffuse.rgb * LightIntensity * Attenuate;\n"
            "\n"
            "      // -----------------------------------------------------------------------\n"
            "      // Apply shadow color(use the ambient color of the light)\n"
            "      float ShadowIntensity = 1.f - (LightIntensity * Shadow);\n"
            "      DiffuseAccumOut.rgb += LightAmbient.rgb * ShadowIntensity;\n"
            "      // Do not apply ambient color to AmbientAccum\n"
            "      AmbientAccumOut = AmbientAccum;\n"
            "      // -----------------------------------------------------------------------\n"
            "\n"
            "      SpecularAccumOut = SpecularAccum;\n"
            "      if (SpecularEnable)\n"
            "      {\n"
            "      // Get the half vector.\n"
            "      float3 LightHalfVector = LightVector + WorldViewVector;\n"
            "      LightHalfVector = normalize(LightHalfVector);\n"
            "\n"
            "      // Determine specular intensity.\n"
            "      float LightNDotH = max(0.00001f, dot(WorldNrm, LightHalfVector));\n"
            "      float LightSpecIntensity = pow(LightNDotH, SpecularPower.x);\n"
            "\n"
            "      //if (LightNDotL < 0.0)\n"
            "        //    LightSpecIntensity = 0.0;\n"
            "        // Must use the code below rather than code above.\n"
            "        // Using previous lines will cause the compiler to generate incorrect\n"
            "        // output.\n"
            "        float SpecularMultiplier = LightNDotL > 0.0 ? 1.0 : 0.0;\n"
            "\n"
            "        // Attenuate Here\n"
            "        LightSpecIntensity = LightSpecIntensity * Attenuate *\n"
            "        SpecularMultiplier;\n"
            "\n"
            "        // Determine the interaction of specular color of light and material.\n"
            "        // Scale by the attenuated intensity.\n"
            "        SpecularAccumOut.rgb += LightSpecIntensity * LightSpecular;\n"
            "      }\n"
            "    ");

        pkFrag->AddCodeBlock(pkBlock);
    }

    pkLib->AddNode(pkFrag);
}
//--------------------------------------------------------------------------------------------------
// @0x142757e10
EE_NOINLINE static void CreateFragment10(NiMaterialNodeLibrary* pkLib)
{
    NiMaterialFragmentNode* pkFrag = NiNew NiMaterialFragmentNode();

    pkFrag->SetType("Vertex/Pixel");
    pkFrag->SetName("AlphaBlendColors");
    pkFrag->SetDescription("\n"
        "      This fragment computes the blended color SrcColor1 * ( 1 - Alpha ) + SrcColor2 * Alpha.\n"
        "    ");
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Diffuse");
        pkRes->SetVariable("SrcColor1");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Diffuse");
        pkRes->SetVariable("SrcColor2");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float");
        pkRes->SetSemantic("Alpha");
        pkRes->SetLabel("Alpha");
        pkRes->SetVariable("Alpha");
        pkRes->SetDefaultValue("(0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetVariable("ColorOut");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiCodeBlock* pkBlock = NiNew NiCodeBlock();

        pkBlock->SetLanguage("hlsl/Cg");
        pkBlock->SetPlatform("D3D11/D3D10/DX9/Xenon/PS3");
        pkBlock->SetTarget("vs_1_1/ps_2_0/vs_4_0/ps_4_0/vs_5_0/ps_5_0");
        pkBlock->SetText("\n"
            "      ColorOut = SrcColor1 * ( 1 - Alpha ) + SrcColor2 * Alpha;\n"
            "    ");

        pkFrag->AddCodeBlock(pkBlock);
    }

    pkLib->AddNode(pkFrag);
}
//--------------------------------------------------------------------------------------------------
// @0x142758380
EE_NOINLINE static void CreateFragment11(NiMaterialNodeLibrary* pkLib)
{
    NiMaterialFragmentNode* pkFrag = NiNew NiMaterialFragmentNode();

    pkFrag->SetType("Vertex/Pixel");
    pkFrag->SetName("Float4ToFloat3");
    pkFrag->SetDescription("\n"
        "      This fragment returns a float3 vector which contains float4.xyz\n"
        "    ");
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("Color");
        pkRes->SetVariable("Input");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetVariable("Output");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiCodeBlock* pkBlock = NiNew NiCodeBlock();

        pkBlock->SetLanguage("hlsl/Cg");
        pkBlock->SetPlatform("D3D11/D3D10/DX9/Xenon/PS3");
        pkBlock->SetTarget("vs_1_1/ps_2_0/vs_4_0/ps_4_0/vs_5_0/ps_5_0");
        pkBlock->SetText("\n"
            "      Output = Input.xyz;\n"
            "    ");

        pkFrag->AddCodeBlock(pkBlock);
    }

    pkLib->AddNode(pkFrag);
}
//--------------------------------------------------------------------------------------------------
// @0x1427586c0
EE_NOINLINE static void CreateFragment12(NiMaterialNodeLibrary* pkLib)
{
    NiMaterialFragmentNode* pkFrag = NiNew NiMaterialFragmentNode();

    pkFrag->SetType("Vertex/Pixel");
    pkFrag->SetName("UVColorToFloat4");
    pkFrag->SetDescription("\n"
        "      This fragment returns a float4 vector which contains uv, color in its xyz components.\n"
        "    ");
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float2");
        pkRes->SetSemantic("Color");
        pkRes->SetVariable("Input");
        pkRes->SetDefaultValue("(0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("sampler2D");
        pkRes->SetSemantic("Texture");
        pkRes->SetVariable("ControlSampler");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("Color");
        pkRes->SetVariable("Output");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiCodeBlock* pkBlock = NiNew NiCodeBlock();

        pkBlock->SetLanguage("hlsl/Cg");
        pkBlock->SetPlatform("D3D11/D3D10/DX9/Xenon/PS3");
        pkBlock->SetTarget("vs_1_1/ps_2_0/vs_4_0/ps_4_0/vs_5_0/ps_5_0");
        pkBlock->SetText("\n"
            "      float4 ControlColor = tex2D(ControlSampler, Input);\n"
            "      \n"
            "      Output = float4(Input, ControlColor.b, 0.0);\n"
            "    ");

        pkFrag->AddCodeBlock(pkBlock);
    }

    pkLib->AddNode(pkFrag);
}
//--------------------------------------------------------------------------------------------------
// @0x142758ab0
EE_NOINLINE static void CreateFragment13(NiMaterialNodeLibrary* pkLib)
{
    NiMaterialFragmentNode* pkFrag = NiNew NiMaterialFragmentNode();

    pkFrag->SetType("Vertex/Pixel");
    pkFrag->SetName("Float2ToFloat4");
    pkFrag->SetDescription("\n"
        "      This fragment returns a float4 vector which contains float2 in its xy components.\n"
        "    ");
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float2");
        pkRes->SetSemantic("Color");
        pkRes->SetVariable("Input");
        pkRes->SetDefaultValue("(0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("Color");
        pkRes->SetVariable("Output");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiCodeBlock* pkBlock = NiNew NiCodeBlock();

        pkBlock->SetLanguage("hlsl/Cg");
        pkBlock->SetPlatform("D3D11/D3D10/DX9/Xenon/PS3");
        pkBlock->SetTarget("vs_1_1/ps_2_0/vs_4_0/ps_4_0/vs_5_0/ps_5_0");
        pkBlock->SetText("\n"
            "      Output = float4(Input, 0.0, 0.0);\n"
            "    ");

        pkFrag->AddCodeBlock(pkBlock);
    }

    pkLib->AddNode(pkFrag);
}
//--------------------------------------------------------------------------------------------------
// @0x142758df0
EE_NOINLINE static void CreateFragment14(NiMaterialNodeLibrary* pkLib)
{
    NiMaterialFragmentNode* pkFrag = NiNew NiMaterialFragmentNode();

    pkFrag->SetType("Vertex/Pixel");
    pkFrag->SetName("Float3ToFloat4");
    pkFrag->SetDescription("\n"
        "      This fragment returns a float4 vector which contains float2 in its xy components.\n"
        "    ");
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetVariable("Input");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("Color");
        pkRes->SetVariable("Output");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiCodeBlock* pkBlock = NiNew NiCodeBlock();

        pkBlock->SetLanguage("hlsl/Cg");
        pkBlock->SetPlatform("D3D11/D3D10/DX9/Xenon/PS3");
        pkBlock->SetTarget("vs_1_1/ps_2_0/vs_4_0/ps_4_0/vs_5_0/ps_5_0");
        pkBlock->SetText("\n"
            "      Output = float4(Input, 0.0);\n"
            "    ");

        pkFrag->AddCodeBlock(pkBlock);
    }

    pkLib->AddNode(pkFrag);
}
//--------------------------------------------------------------------------------------------------
// @0x142759130
EE_NOINLINE static void CreateFragment15(NiMaterialNodeLibrary* pkLib)
{
    NiMaterialFragmentNode* pkFrag = NiNew NiMaterialFragmentNode();

    pkFrag->SetType("Pixel/Vertex");
    pkFrag->SetName("ExtractOutline");
    pkFrag->SetDescription("\n"
        "      This fragment is responsible for applying the view projection transform\n"
        "      to the input world position.\n"
        "    ");
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
        pkRes->SetLabel("World");
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

        pkRes->SetType("float");
        pkRes->SetSemantic("OutlineWidth");
        pkRes->SetVariable("OutlineWidth");
        pkRes->SetDefaultValue("(0.0)");

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
        pkBlock->SetTarget("vs_1_1/vs_4_0/vs_5_0");
        pkBlock->SetText("\n"
            "      ViewPos = mul(WorldPosition, ViewTransform);\n"
            "\n"
            "      float3 viewNormal = mul(WorldNormal, (float3x3)ViewTransform);\n"
            "\n"
            "      ProjPos = mul(ViewPos, ProjTransform);\n"
            "      float3 projNormal = mul(viewNormal, (float3x3)ProjTransform);\n"
            "\n"
            "      projNormal.z = 0;\n"
            "      projNormal.xy = normalize(projNormal.xy);\n"
            "\n"
            "      ProjPos.xy += OutlineWidth * projNormal.xy * 2.f;\n"
            "      //ProjPos.z += 0.001f * ProjPos.w;\n"
            "\n"
            "    ");

        pkFrag->AddCodeBlock(pkBlock);
    }

    pkLib->AddNode(pkFrag);
}
//--------------------------------------------------------------------------------------------------
// @0x142759880
EE_NOINLINE static void CreateFragment16(NiMaterialNodeLibrary* pkLib)
{
    NiMaterialFragmentNode* pkFrag = NiNew NiMaterialFragmentNode();

    pkFrag->SetType("Pixel/Vertex");
    pkFrag->SetName("MS2CompositeFinalRGBColor");
    pkFrag->SetDescription("\n"
        "      This fragment is responsible for computing the final RGB color.\n"
        "    ");
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
        pkRes->SetSemantic("Highlight");
        pkRes->SetVariable("Highlight");
        pkRes->SetDefaultValue("(0.0)");

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
            "      OutputColor.rgb = DiffuseColor.rgb + SpecularColor.rgb;\n"
            "      OutputColor.rgb += Highlight;\n"
            "    ");

        pkFrag->AddCodeBlock(pkBlock);
    }

    pkLib->AddNode(pkFrag);
}
//--------------------------------------------------------------------------------------------------
// @0x142759d70
EE_NOINLINE static void CreateFragment17(NiMaterialNodeLibrary* pkLib)
{
    NiMaterialFragmentNode* pkFrag = NiNew NiMaterialFragmentNode();

    pkFrag->SetType("Pixel/Vertex");
    pkFrag->SetName("AlphaBoost");
    pkFrag->SetDescription("\n"
        "      This fragment is responsible for computing the final RGB color.\n"
        "    ");
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetVariable("FinalColor");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float");
        pkRes->SetSemantic("Color");
        pkRes->SetVariable("FinalOpacity");
        pkRes->SetDefaultValue("(1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
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
            "      OutputColor.rgb = FinalColor.rgb;\n"
            "      if (FinalOpacity > 1)\n"
            "        OutputColor.rgb *= FinalOpacity;\n"
            "\n"
            "      OutputColor.a = FinalOpacity;\n"
            "    ");

        pkFrag->AddCodeBlock(pkBlock);
    }

    pkLib->AddNode(pkFrag);
}
//--------------------------------------------------------------------------------------------------
// @0x14275a190
EE_NOINLINE static void CreateFragment18(NiMaterialNodeLibrary* pkLib)
{
    NiMaterialFragmentNode* pkFrag = NiNew NiMaterialFragmentNode();

    pkFrag->SetType("Pixel/Vertex");
    pkFrag->SetName("ShaderInstancingTransform");
    pkFrag->SetDescription("\n"
        "      This fragment transform the WorldPos and WorldNormal with ShaderInstancing.\n"
        "    ");
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Position");
        pkRes->SetLabel("Local");
        pkRes->SetVariable("localPos");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("int2");
        pkRes->SetSemantic("BlendIndices");
        pkRes->SetVariable("BIndices");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("Position");
        pkRes->SetLabel("World");
        pkRes->SetVariable("WorldPos");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4x4");
        pkRes->SetSemantic("WorldMatrix");
        pkRes->SetVariable("WorldMatrix");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiCodeBlock* pkBlock = NiNew NiCodeBlock();

        pkBlock->SetLanguage("hlsl/Cg");
        pkBlock->SetPlatform("D3D11/D3D10/DX9/Xenon");
        pkBlock->SetTarget("vs_1_1/ps_2_0/vs_4_0/ps_4_0/vs_5_0/ps_5_0");
        pkBlock->SetText("\n"
            "          int idx =BIndices[0];\n"
            "\n"
            "          float4 translation = arrTranslations[idx];\n"
            "          if(bShaderInstancingAnimation)\n"
            "          {\n"
            "              if( localPos.z > 10 )\n"
            "              {\n"
            "                translation.w = 1.0f;\n"
            "                WorldMatrix =  float4x4(arrXAxis[idx], 0.0f,\n"
            "                arrYAxis[idx], 0.0f,\n"
            "                arrZAxis[idx], 0.0f,\n"
            "                translation);\n"
            "              }\n"
            "              else\n"
            "              {\n"
            "                float scale = translation.w;\n"
            "                translation.w = 1.0f;\n"
            "                WorldMatrix =  float4x4(scale,  0.0f,   0.0f,   0.0f,\n"
            "                0.0f,   scale,  0.0f,   0.0f,\n"
            "                0.0f,   0.0f,   scale,  0.0f,\n"
            "                translation);\n"
            "              }\n"
            "            }\n"
            "            else\n"
            "            {\n"
            "              translation.w = 1.0f;\n"
            "              WorldMatrix =  float4x4(arrXAxis[idx], 0.0f,\n"
            "              arrYAxis[idx], 0.0f,\n"
            "              arrZAxis[idx], 0.0f,\n"
            "              translation);\n"
            "            }\n"
            "\n"
            "          WorldPos = mul( float4(localPos, 1.0f), WorldMatrix );\n"
            "        ");

        pkFrag->AddCodeBlock(pkBlock);
    }

    pkLib->AddNode(pkFrag);
}
//--------------------------------------------------------------------------------------------------
// @0x14275a660
EE_NOINLINE static void CreateFragment19(NiMaterialNodeLibrary* pkLib)
{
    NiMaterialFragmentNode* pkFrag = NiNew NiMaterialFragmentNode();

    pkFrag->SetType("Vertex/Pixel");
    pkFrag->SetName("CalculateBiasedFog");
    pkFrag->SetDescription("\n"
        "      This fragment is responsible for handling fogging calculations.\n"
        "      FogType can be one of 4 values:\n"
        "\n"
        "      NONE   - 0\n"
        "      EXP    - 1\n"
        "      EXP2   - 2\n"
        "      LINEAR - 3\n"
        "    ");
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("int");
        pkRes->SetSemantic("FogType");
        pkRes->SetVariable("FogType");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float");
        pkRes->SetSemantic("FogDensity");
        pkRes->SetVariable("FogDensity");
        pkRes->SetDefaultValue("(1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("Position");
        pkRes->SetLabel("View");
        pkRes->SetVariable("ViewPosition");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("bool");
        pkRes->SetSemantic("FogRange");
        pkRes->SetVariable("FogRange");
        pkRes->SetDefaultValue("(false)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("FogStartEnd");
        pkRes->SetVariable("FogStartEnd");
        pkRes->SetDefaultValue("(0.0, 1.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float");
        pkRes->SetSemantic("FogBias");
        pkRes->SetVariable("FogBias");
        pkRes->SetDefaultValue("(0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float");
        pkRes->SetSemantic("Fog");
        pkRes->SetVariable("FogOut");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiCodeBlock* pkBlock = NiNew NiCodeBlock();

        pkBlock->SetLanguage("hlsl/Cg");
        pkBlock->SetPlatform("D3D11/D3D10/DX9/Xenon/PS3");
        pkBlock->SetTarget("vs_1_1/ps_2_0/vs_4_0/ps_4_0/vs_5_0/ps_5_0");
        pkBlock->SetText("\n"
            "      float d;\n"
            "      if (FogRange)\n"
            "      {\n"
            "      d = length(ViewPosition);\n"
            "      }\n"
            "      else\n"
            "      {\n"
            "      d = ViewPosition.z;\n"
            "      }\n"
            "\n"
            "      if (FogType == 0) // NONE\n"
            "      {\n"
            "      FogOut = 1.0;\n"
            "      }\n"
            "      else if (FogType == 1) // EXP\n"
            "      {\n"
            "      FogOut = 1.0 / exp( d * FogDensity);\n"
            "      }\n"
            "      else if (FogType == 2) // EXP2\n"
            "      {\n"
            "      FogOut = 1.0 / exp( pow( d * FogDensity, 2));\n"
            "      }\n"
            "      else if (FogType == 3) // LINEAR\n"
            "      {\n"
            "      FogOut = saturate( (FogStartEnd.y + FogBias - d) /\n"
            "      (FogStartEnd.y - FogStartEnd.x));\n"
            "      }\n"
            "    ");

        pkFrag->AddCodeBlock(pkBlock);
    }

    pkLib->AddNode(pkFrag);
}
//--------------------------------------------------------------------------------------------------
// @0x14275ade0
EE_NOINLINE static void CreateFragment1(NiMaterialNodeLibrary* pkLib)
{
    NiMaterialFragmentNode* pkFrag = NiNew NiMaterialFragmentNode();

    pkFrag->SetType("Vertex/Pixel");
    pkFrag->SetName("MS2CharacterLight");
    pkFrag->SetDescription("\n"
        "      This fragment replaces the original Light fragment in NiStandardMaterial.\n"
        "\n"
        "      Modifications from Light fragment are followings.\n"
        "      1. This fragment uses Half-Lambert equation instead of Lambert.\n"
        "      2. This fragment adds RimLight factor to diffuse.\n"
        "\n"
        "      Others are same with Light fragment.\n"
        "    ");
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("Position");
        pkRes->SetLabel("World");
        pkRes->SetVariable("WorldPos");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Normal");
        pkRes->SetLabel("World");
        pkRes->SetVariable("WorldNrm");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("int");
        pkRes->SetSemantic("LightType");
        pkRes->SetVariable("LightType");
        pkRes->SetDefaultValue("(0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("bool");
        pkRes->SetSemantic("Specularity");
        pkRes->SetVariable("SpecularEnable");
        pkRes->SetDefaultValue("(false)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float");
        pkRes->SetSemantic("Shadow");
        pkRes->SetVariable("Shadow");
        pkRes->SetDefaultValue("(1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("ViewVector");
        pkRes->SetLabel("World");
        pkRes->SetVariable("WorldViewVector");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("LightPos");
        pkRes->SetLabel("World");
        pkRes->SetVariable("LightPos");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("LightAmbient");
        pkRes->SetVariable("LightAmbient");
        pkRes->SetDefaultValue("(1.0, 1.0, 1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("LightDiffuse");
        pkRes->SetVariable("LightDiffuse");
        pkRes->SetDefaultValue("(1.0, 1.0, 1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("LightSpecular");
        pkRes->SetVariable("LightSpecular");
        pkRes->SetDefaultValue("(1.0, 1.0, 1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("LightAttenuation");
        pkRes->SetVariable("LightAttenuation");
        pkRes->SetDefaultValue("(0.0, 1.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("LightSpotAttenuation");
        pkRes->SetVariable("LightSpotAttenuation");
        pkRes->SetDefaultValue("(-1.0, -1.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("LightDirection");
        pkRes->SetVariable("LightDirection");
        pkRes->SetDefaultValue("(1.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Specular");
        pkRes->SetVariable("SpecularPower");
        pkRes->SetDefaultValue("(1.0, 1.0, 1.0, 1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Ambient");
        pkRes->SetVariable("AmbientAccum");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Diffuse");
        pkRes->SetVariable("DiffuseAccum");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Specular");
        pkRes->SetVariable("SpecularAccum");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float");
        pkRes->SetSemantic("FresnelBoost");
        pkRes->SetVariable("FresnelBoostIn");
        pkRes->SetDefaultValue("(5.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float");
        pkRes->SetSemantic("FresnelExponent");
        pkRes->SetVariable("FresnelExponentIn");
        pkRes->SetDefaultValue("(4.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("RimLightDirection");
        pkRes->SetVariable("RimLightDirIn");
        pkRes->SetDefaultValue("(0.0, 0.0, 1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Ambient");
        pkRes->SetVariable("AmbientAccumOut");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Diffuse");
        pkRes->SetVariable("DiffuseAccumOut");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Specular");
        pkRes->SetVariable("SpecularAccumOut");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiCodeBlock* pkBlock = NiNew NiCodeBlock();

        pkBlock->SetLanguage("hlsl/Cg");
        pkBlock->SetPlatform("D3D11/D3D10/DX9/Xenon/PS3");
        pkBlock->SetTarget("vs_1_1/ps_2_0/vs_4_0/ps_4_0/vs_5_0/ps_5_0");
        pkBlock->SetText("\n"
            "      // Get the world space light vector.\n"
            "      float3 LightVector;\n"
            "      float DistanceToLight;\n"
            "      float DistanceToLightSquared;\n"
            "\n"
            "      if (LightType == 0)\n"
            "      {\n"
            "      LightVector = -LightDirection;\n"
            "      }\n"
            "      else\n"
            "      {\n"
            "      LightVector = LightPos - WorldPos;\n"
            "      DistanceToLightSquared = dot(LightVector, LightVector);\n"
            "      DistanceToLight = length(LightVector);\n"
            "      LightVector = normalize(LightVector);\n"
            "      }\n"
            "\n"
            "      // -----------------------------------------------------------------------\n"
            "      // Take N dot L as intensity.\n"
            "      //float LightNDotL = dot(LightVector, WorldNrm);\n"
            "      //float LightIntensity = max(0, LightNDotL);\n"
            "\n"
            "      // Replace the lambert equation by Half-Lambert.\n"
            "      float LightNDotL = pow( 0.5 * dot( LightVector, WorldNrm ) + 0.5, 2 );\n"
            "      float LightIntensity = LightNDotL;\n"
            "      // -----------------------------------------------------------------------\n"
            "\n"
            "      // -----------------------------------------------------------------------\n"
            "      // Calculate RimLight factor\n"
            "      float Fresnel = FresnelBoostIn * pow( ( 1 - abs( dot( WorldNrm, WorldViewVector ) ) ), FresnelExponentIn );\n"
            "      // Ignore light direction\n"
            "      // float RimIntensity = max( 0, -dot( LightVector, WorldViewVector ) ) * Fresnel;\n"
            "      float RimIntensity = max( 0, -dot( RimLightDirIn, WorldNrm ) ) * Fresnel;\n"
            "      LightIntensity += RimIntensity;\n"
            "      // -----------------------------------------------------------------------\n"
            "\n"
            "      float Attenuate = Shadow;\n"
            "\n"
            "      if (LightType != 0)\n"
            "      {\n"
            "      // Attenuate Here\n"
            "      Attenuate = LightAttenuation.x +\n"
            "      LightAttenuation.y * DistanceToLight +\n"
            "      LightAttenuation.z * DistanceToLightSquared;\n"
            "      Attenuate = max(1.0, Attenuate);\n"
            "      Attenuate = 1.0 / Attenuate;\n"
            "      Attenuate *= Shadow;\n"
            "\n"
            "      if (LightType == 2)\n"
            "      {\n"
            "      // Get intensity as cosine of light vector and direction.\n"
            "      float CosAlpha = dot(-LightVector, LightDirection);\n"
            "\n"
            "      // Factor in inner and outer cone angles.\n"
            "      float AttenDiff = LightSpotAttenuation.x - LightSpotAttenuation.y;\n"
            "      CosAlpha = saturate((CosAlpha - LightSpotAttenuation.y) /\n"
            "      AttenDiff);\n"
            "\n"
            "      // Power to falloff.\n"
            "      // The pow() here can create a NaN if CosAlpha is 0 or less.\n"
            "      // On some cards (GeForce 6800), the NaN will propagate through\n"
            "      // a ternary instruction, so we need two to be safe.\n"
            "      float origCosAlpha = CosAlpha;\n"
            "      CosAlpha = origCosAlpha <= 0.0 ? 1.0 : CosAlpha;\n"
            "      CosAlpha = pow(CosAlpha, LightSpotAttenuation.z);\n"
            "      CosAlpha = origCosAlpha <= 0.0 ? 0.0 : CosAlpha;\n"
            "\n"
            "      // Multiply the spot attenuation into the overall attenuation.\n"
            "      Attenuate *= CosAlpha;\n"
            "      }\n"
            "      }\n"
            "      // Determine the interaction of diffuse color of light and material.\n"
            "      // Scale by the attenuated intensity.\n"
            "      DiffuseAccumOut = DiffuseAccum;\n"
            "      DiffuseAccumOut.rgb += LightDiffuse.rgb * LightIntensity * Attenuate;\n"
            "\n"
            "      // -----------------------------------------------------------------------\n"
            "      // Apply shadow color(use the ambient color of the light)\n"
            "      float ShadowIntensity = 1.f - (LightIntensity * Shadow);\n"
            "      DiffuseAccumOut.rgb += LightAmbient.rgb * ShadowIntensity;\n"
            "      // Do not apply ambient color to AmbientAccum\n"
            "      AmbientAccumOut = AmbientAccum;\n"
            "      // -----------------------------------------------------------------------\n"
            "\n"
            "      SpecularAccumOut = SpecularAccum;\n"
            "      if (SpecularEnable)\n"
            "      {\n"
            "      // Get the half vector.\n"
            "      float3 LightHalfVector = LightVector + WorldViewVector;\n"
            "      LightHalfVector = normalize(LightHalfVector);\n"
            "\n"
            "      // Determine specular intensity.\n"
            "      float LightNDotH = max(0.00001f, dot(WorldNrm, LightHalfVector));\n"
            "      float LightSpecIntensity = pow(LightNDotH, SpecularPower.x);\n"
            "\n"
            "      //if (LightNDotL < 0.0)\n"
            "      //    LightSpecIntensity = 0.0;\n"
            "      // Must use the code below rather than code above.\n"
            "      // Using previous lines will cause the compiler to generate incorrect\n"
            "      // output.\n"
            "      float SpecularMultiplier = LightNDotL > 0.0 ? 1.0 : 0.0;\n"
            "\n"
            "      // Attenuate Here\n"
            "      LightSpecIntensity = LightSpecIntensity * Attenuate *\n"
            "      SpecularMultiplier;\n"
            "\n"
            "      // Determine the interaction of specular color of light and material.\n"
            "      // Scale by the attenuated intensity.\n"
            "      SpecularAccumOut.rgb += LightSpecIntensity * LightSpecular;\n"
            "      }\n"
            "\n"
            "    ");

        pkFrag->AddCodeBlock(pkBlock);
    }

    pkLib->AddNode(pkFrag);
}
//--------------------------------------------------------------------------------------------------
// @0x14275c3e0
EE_NOINLINE static void CreateFragment20(NiMaterialNodeLibrary* pkLib)
{
    NiMaterialFragmentNode* pkFrag = NiNew NiMaterialFragmentNode();

    pkFrag->SetType("Pixel/Vertex");
    pkFrag->SetName("CalculateDiffuseOnlyAlpha");
    pkFrag->SetDescription("\n"
        "      This fragment computes new alpha value that doesn't reduce specular value.\n"
        "      newAlpha = ((diffuseAccum * oldAlpha) + specularAccum) / (diffuseAccum + specularAccum)\n"
        "      newAlpha * (diffuseAccum + specularAccum) = diffuseAccum * oldAplha + specularAccum\n"
        "    ");
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
        pkRes->SetSemantic("Color");
        pkRes->SetVariable("OpacityIn");
        pkRes->SetDefaultValue("(1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float");
        pkRes->SetSemantic("Color");
        pkRes->SetVariable("OpacityOut");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiCodeBlock* pkBlock = NiNew NiCodeBlock();

        pkBlock->SetLanguage("hlsl/Cg");
        pkBlock->SetPlatform("D3D11/D3D10/DX9/Xenon/PS3");
        pkBlock->SetTarget("vs_1_1/ps_2_0/vs_4_0/ps_4_0/vs_5_0/ps_5_0");
        pkBlock->SetText("\n"
            "      float diffSum = DiffuseColor.r + DiffuseColor.g + DiffuseColor.b;\n"
            "      float specSum = SpecularColor.r + SpecularColor.g + SpecularColor.b;\n"
            "      OpacityOut = saturate(OpacityIn + specSum / 3);\n"
            "\n"
            "    ");

        pkFrag->AddCodeBlock(pkBlock);
    }

    pkLib->AddNode(pkFrag);
}
//--------------------------------------------------------------------------------------------------
// @0x14275c8d0
EE_NOINLINE static void CreateFragment21(NiMaterialNodeLibrary* pkLib)
{
    NiMaterialFragmentNode* pkFrag = NiNew NiMaterialFragmentNode();

    pkFrag->SetType("Vertex/Pixel");
    pkFrag->SetName("ConstructSkinInstanceTransform");
    pkFrag->SetDescription("\n"
        "      This fragment is reponsible for creating the world-instance transform.\n"
        "      This is a 4x4 transform that is constructed from 3 float4 objects. It\n"
        "      assumes the the last column in the matrix should be (0, 0, 0, 1).\n"
        "    ");
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetVariable("Position1");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetVariable("Position2");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetVariable("Position3");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4x4");
        pkRes->SetVariable("SkinMatrix");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4x4");
        pkRes->SetSemantic("Position");
        pkRes->SetLabel("World");
        pkRes->SetVariable("InstanceWorld");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiCodeBlock* pkBlock = NiNew NiCodeBlock();

        pkBlock->SetLanguage("hlsl/Cg");
        pkBlock->SetPlatform("D3D11/D3D10/DX9/Xenon/PS3");
        pkBlock->SetTarget("vs_1_1/ps_2_0/vs_4_0/ps_4_0/vs_5_0/ps_5_0");
        pkBlock->SetText("\n"
            "\n"
            "      // Build instance world transform matrix.\n"
            "      InstanceWorld._11 = Position1.x;\n"
            "      InstanceWorld._12 = Position1.y;\n"
            "      InstanceWorld._13 = Position1.z;\n"
            "      InstanceWorld._14 = 0;\n"
            "\n"
            "      InstanceWorld._21 = Position2.x;\n"
            "      InstanceWorld._22 = Position2.y;\n"
            "      InstanceWorld._23 = Position2.z;\n"
            "      InstanceWorld._24 = 0;\n"
            "\n"
            "      InstanceWorld._31 = Position3.x;\n"
            "      InstanceWorld._32 = Position3.y;\n"
            "      InstanceWorld._33 = Position3.z;\n"
            "      InstanceWorld._34 = 0;\n"
            "\n"
            "      InstanceWorld._41 = Position1.w;\n"
            "      InstanceWorld._42 = Position2.w;\n"
            "      InstanceWorld._43 = Position3.w;\n"
            "      InstanceWorld._44 = 1;\n"
            "\n"
            "      InstanceWorld = InstanceWorld * SkinMatrix;\n"
            "    ");

        pkFrag->AddCodeBlock(pkBlock);
    }

    pkLib->AddNode(pkFrag);
}
//--------------------------------------------------------------------------------------------------
// @0x14275cd90
EE_NOINLINE static void CreateFragment22(NiMaterialNodeLibrary* pkLib)
{
    NiMaterialFragmentNode* pkFrag = NiNew NiMaterialFragmentNode();

    pkFrag->SetType("Vertex/Pixel");
    pkFrag->SetName("TransformInstanceSkinnedPosition60");
    pkFrag->SetDescription("\n"
        "      This fragment is a modified version of TransformSkinnedPosition fragment\n"
        "      in NiStandardMaterial. The count of Bones is increased to 60.\n"
        "    ");
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Position");
        pkRes->SetLabel("Local");
        pkRes->SetVariable("Position");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("int4");
        pkRes->SetSemantic("BlendIndices");
        pkRes->SetVariable("BlendIndices");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("BlendWeight");
        pkRes->SetLabel("Local");
        pkRes->SetVariable("BlendWeights");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("BONEMATRIX_TYPE");
        pkRes->SetCount(60);
        pkRes->SetSemantic("SkinBoneMatrix");
        pkRes->SetLabel("World");
        pkRes->SetVariable("Bones");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4x4");
        pkRes->SetVariable("InstanceMatrix");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("Position");
        pkRes->SetLabel("World");
        pkRes->SetVariable("WorldPos");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4x4");
        pkRes->SetSemantic("WorldMatrix");
        pkRes->SetVariable("SkinBoneTransform");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiCodeBlock* pkBlock = NiNew NiCodeBlock();

        pkBlock->SetLanguage("hlsl/Cg");
        pkBlock->SetPlatform("D3D11/D3D10/DX9/Xenon");
        pkBlock->SetTarget("vs_1_1/ps_2_0/vs_4_0/ps_4_0/vs_5_0/ps_5_0");
        pkBlock->SetText("\n"
            "      // TransformSkinnedPosition *********************************************\n"
            "      // Transform the skinned position into world space\n"
            "      // Composite the skinning transform which will take the vertex\n"
            "      // and normal to world space.\n"
            "      float fWeight3 = 1.0 - BlendWeights[0] - BlendWeights[1] - BlendWeights[2];\n"
            "      BONEMATRIX_TYPE ShortSkinBoneTransform;\n"
            "      ShortSkinBoneTransform  = Bones[BlendIndices[0]] * BlendWeights[0];\n"
            "      ShortSkinBoneTransform += Bones[BlendIndices[1]] * BlendWeights[1];\n"
            "      ShortSkinBoneTransform += Bones[BlendIndices[2]] * BlendWeights[2];\n"
            "      ShortSkinBoneTransform += Bones[BlendIndices[3]] * fWeight3;\n"
            "      SkinBoneTransform = float4x4(ShortSkinBoneTransform[0], 0.0f,\n"
            "      ShortSkinBoneTransform[1], 0.0f,\n"
            "      ShortSkinBoneTransform[2], 0.0f,\n"
            "      ShortSkinBoneTransform[3], 1.0f);\n"
            "\n"
            "      float4x4 temp0 = float4x4(SkinBoneTransform[0],\n"
            "      SkinBoneTransform[1],\n"
            "      SkinBoneTransform[2],\n"
            "      0.0f, 0.0f, 0.0f, 1.0f);\n"
            "\n"
            "      float4x4 temp1 = float4x4(InstanceMatrix[0],\n"
            "      InstanceMatrix[1],\n"
            "      InstanceMatrix[2],\n"
            "      0.0f, 0.0f, 0.0f, 1.0f);\n"
            "\n"
            "      // Transform into world space.\n"
            "      WorldPos = mul(float4(Position, 1.0), temp1 * temp0);\n"
            "      WorldPos = WorldPos + SkinBoneTransform[3] + InstanceMatrix[3];\n"
            "      WorldPos.w = 1.0f;\n"
            "\n"
            "    ");

        pkFrag->AddCodeBlock(pkBlock);
    }

    pkLib->AddNode(pkFrag);
}
//--------------------------------------------------------------------------------------------------
// @0x14275d4a0
EE_NOINLINE static void CreateFragment23(NiMaterialNodeLibrary* pkLib)
{
    NiMaterialFragmentNode* pkFrag = NiNew NiMaterialFragmentNode();

    pkFrag->SetType("Vertex/Pixel");
    pkFrag->SetName("ProjectScreenToTextureCoordinates");
    pkFrag->SetDescription("\n"
        "      This fragment is responsible for applying a projection to the input set\n"
        "      of texture coordinates.\n"
        "    ");
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("TexCoord");
        pkRes->SetVariable("TexCoordIn");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("TexCoord");
        pkRes->SetVariable("TexCoordOut");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiCodeBlock* pkBlock = NiNew NiCodeBlock();

        pkBlock->SetLanguage("hlsl/Cg");
        pkBlock->SetPlatform("D3D11/D3D10/DX9/Xenon/PS3");
        pkBlock->SetTarget("vs_1_1/ps_2_0/vs_4_0/ps_4_0/vs_5_0/ps_5_0");
        pkBlock->SetText("\n"
            "      TexCoordOut.x =  0.5 * TexCoordIn.x / TexCoordIn.w + 0.5;\n"
            "      TexCoordOut.y = -0.5 * TexCoordIn.y / TexCoordIn.w + 0.5;\n"
            "      TexCoordOut.z = 0.0;\n"
            "      TexCoordOut.w = 1.0;\n"
            "    ");

        pkFrag->AddCodeBlock(pkBlock);
    }

    pkLib->AddNode(pkFrag);
}
//--------------------------------------------------------------------------------------------------
// @0x14275d7c0
EE_NOINLINE static void CreateFragment24(NiMaterialNodeLibrary* pkLib)
{
    NiMaterialFragmentNode* pkFrag = NiNew NiMaterialFragmentNode();

    pkFrag->SetType("Vertex/Pixel");
    pkFrag->SetName("PassThruViewToTextureCoordinates");
    pkFrag->SetDescription("\n"
        "      ...\n"
        "    ");
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("Position");
        pkRes->SetLabel("Proj");
        pkRes->SetVariable("ProjPos");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("TexCoord");
        pkRes->SetVariable("TexCoordOut");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiCodeBlock* pkBlock = NiNew NiCodeBlock();

        pkBlock->SetLanguage("hlsl/Cg");
        pkBlock->SetPlatform("D3D11/D3D10/DX9/Xenon/PS3");
        pkBlock->SetTarget("vs_1_1/ps_2_0/vs_4_0/ps_4_0/vs_5_0/ps_5_0");
        pkBlock->SetText("\n"
            "      TexCoordOut = ProjPos;\n"
            "    ");

        pkFrag->AddCodeBlock(pkBlock);
    }

    pkLib->AddNode(pkFrag);
}
//--------------------------------------------------------------------------------------------------
// @0x14275db00
EE_NOINLINE static void CreateFragment25(NiMaterialNodeLibrary* pkLib)
{
    NiMaterialFragmentNode* pkFrag = NiNew NiMaterialFragmentNode();

    pkFrag->SetType("Vertex/Pixel");
    pkFrag->SetName("PositionPassThrough");
    pkFrag->SetDescription("\n"
        "      This fragment takes in a position and passes it out unmodified.\n"
        "    ");
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("Position");
        pkRes->SetVariable("Input");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("Position");
        pkRes->SetVariable("Output");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiCodeBlock* pkBlock = NiNew NiCodeBlock();

        pkBlock->SetLanguage("hlsl/Cg");
        pkBlock->SetPlatform("D3D11/D3D10/DX9/Xenon/PS3");
        pkBlock->SetTarget("vs_1_1/ps_2_0/vs_4_0/ps_4_0/vs_5_0/ps_5_0");
        pkBlock->SetText("\n"
            "      Output = Input;\n"
            "    ");

        pkFrag->AddCodeBlock(pkBlock);
    }

    pkLib->AddNode(pkFrag);
}
//--------------------------------------------------------------------------------------------------
// @0x14275de20
EE_NOINLINE static void CreateFragment26(NiMaterialNodeLibrary* pkLib)
{
    NiMaterialFragmentNode* pkFrag = NiNew NiMaterialFragmentNode();

    pkFrag->SetType("Vertex/Pixel");
    pkFrag->SetName("PositionToDepth");
    pkFrag->SetDescription("\n"
        "      This fragment takes in the view vector in world\n"
        "      space, a position, and a per-pixel normal and outputs\n"
        "      a constant unit normal (0.0, 0.0, 1.0) in xyz and the\n"
        "      z from the original position in w.\n"
        "    ");
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("Position");
        pkRes->SetVariable("Input");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float");
        pkRes->SetVariable("FinalOpacity");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("Position");
        pkRes->SetVariable("Output");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiCodeBlock* pkBlock = NiNew NiCodeBlock();

        pkBlock->SetLanguage("hlsl/Cg");
        pkBlock->SetPlatform("DX9/Xenon/PS3");
        pkBlock->SetTarget("vs_2_0/ps_2_0");
        pkBlock->SetText("\n"
            "      Output = float4(Input.z, Input.z, Input.z, saturate(FinalOpacity));\n"
            "    ");

        pkFrag->AddCodeBlock(pkBlock);
    }

    pkLib->AddNode(pkFrag);
}
//--------------------------------------------------------------------------------------------------
// @0x14275e1c0
EE_NOINLINE static void CreateFragment27(NiMaterialNodeLibrary* pkLib)
{
    NiMaterialFragmentNode* pkFrag = NiNew NiMaterialFragmentNode();

    pkFrag->SetType("Vertex/Pixel");
    pkFrag->SetName("PositionToDepthForCharacter");
    pkFrag->SetDescription("\n"
        "      This fragment outputs depth values, but if a value is less than\n"
        "      near plane depth, the value will become middle plane depth value.\n"
        "    ");
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("Position");
        pkRes->SetVariable("Input");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float");
        pkRes->SetVariable("FinalOpacity");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float");
        pkRes->SetVariable("GfNearZ");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("Position");
        pkRes->SetVariable("Output");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiCodeBlock* pkBlock = NiNew NiCodeBlock();

        pkBlock->SetLanguage("hlsl/Cg");
        pkBlock->SetPlatform("DX9/Xenon/PS3");
        pkBlock->SetTarget("vs_2_0/ps_2_0");
        pkBlock->SetText("\n"
            "      float depth = Input.z;\n"
            "      if (depth <= GfNearZ)\n"
            "        depth = 0.0f;\n"
            "      Output = float4(depth, depth, depth, saturate(FinalOpacity));\n"
            "      ");

        pkFrag->AddCodeBlock(pkBlock);
    }

    pkLib->AddNode(pkFrag);
}
//--------------------------------------------------------------------------------------------------
// @0x14275e5f0
EE_NOINLINE static void CreateFragment28(NiMaterialNodeLibrary* pkLib)
{
    NiMaterialFragmentNode* pkFrag = NiNew NiMaterialFragmentNode();

    pkFrag->SetType("Vertex/Pixel");
    pkFrag->SetName("ForcePixelOne");
    pkFrag->SetDescription("\n"
        "      Always returns 1.\n"
        "    ");
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("Color");
        pkRes->SetVariable("Output");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiCodeBlock* pkBlock = NiNew NiCodeBlock();

        pkBlock->SetLanguage("hlsl/Cg");
        pkBlock->SetPlatform("DX9/Xenon/PS3");
        pkBlock->SetTarget("vs_2_0/ps_2_0");
        pkBlock->SetText("\n"
            "      Output = float4( 1.0f / 255.0f, 0, 0, 1 );\n"
            "    ");

        pkFrag->AddCodeBlock(pkBlock);
    }

    pkLib->AddNode(pkFrag);
}
//--------------------------------------------------------------------------------------------------
// @0x14275e860
EE_NOINLINE static void CreateFragment29(NiMaterialNodeLibrary* pkLib)
{
    NiMaterialFragmentNode* pkFrag = NiNew NiMaterialFragmentNode();

    pkFrag->SetType("Pixel/Vertex");
    pkFrag->SetName("DiffuseOnly");
    pkFrag->SetDescription("\n"
        "      This fragment only outputs diffuse colors.\n"
        "    ");
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

        pkRes->SetType("float4");
        pkRes->SetSemantic("Color");
        pkRes->SetVariable("Output");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiCodeBlock* pkBlock = NiNew NiCodeBlock();

        pkBlock->SetLanguage("hlsl/Cg");
        pkBlock->SetPlatform("DX9/Xenon/PS3");
        pkBlock->SetTarget("vs_2_0/ps_2_0");
        pkBlock->SetText("\n"
            "      Output.a = 1;\n"
            "      Output.rgb = DiffuseColor;\n"
            "    ");

        pkFrag->AddCodeBlock(pkBlock);
    }

    pkLib->AddNode(pkFrag);
}
//--------------------------------------------------------------------------------------------------
// @0x14275eba0
EE_NOINLINE static void CreateFragment2(NiMaterialNodeLibrary* pkLib)
{
    NiMaterialFragmentNode* pkFrag = NiNew NiMaterialFragmentNode();

    pkFrag->SetType("Vertex/Pixel");
    pkFrag->SetName("MS2CharacterSkinLight");
    pkFrag->SetDescription("\n"
        "      This fragment adds lambSkin diffuse factor and rim light to NiStandardMaterial.\n"
        "    ");
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("Position");
        pkRes->SetLabel("World");
        pkRes->SetVariable("WorldPos");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Normal");
        pkRes->SetLabel("World");
        pkRes->SetVariable("WorldNrm");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("int");
        pkRes->SetSemantic("LightType");
        pkRes->SetVariable("LightType");
        pkRes->SetDefaultValue("(0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("bool");
        pkRes->SetSemantic("Specularity");
        pkRes->SetVariable("SpecularEnable");
        pkRes->SetDefaultValue("(false)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float");
        pkRes->SetSemantic("Shadow");
        pkRes->SetVariable("Shadow");
        pkRes->SetDefaultValue("(1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("ViewVector");
        pkRes->SetLabel("World");
        pkRes->SetVariable("WorldViewVector");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("LightPos");
        pkRes->SetLabel("World");
        pkRes->SetVariable("LightPos");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("LightAmbient");
        pkRes->SetVariable("LightAmbient");
        pkRes->SetDefaultValue("(1.0, 1.0, 1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("LightDiffuse");
        pkRes->SetVariable("LightDiffuse");
        pkRes->SetDefaultValue("(1.0, 1.0, 1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("LightSpecular");
        pkRes->SetVariable("LightSpecular");
        pkRes->SetDefaultValue("(1.0, 1.0, 1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("LightAttenuation");
        pkRes->SetVariable("LightAttenuation");
        pkRes->SetDefaultValue("(0.0, 1.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("LightSpotAttenuation");
        pkRes->SetVariable("LightSpotAttenuation");
        pkRes->SetDefaultValue("(-1.0, -1.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("LightDirection");
        pkRes->SetVariable("LightDirection");
        pkRes->SetDefaultValue("(1.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Specular");
        pkRes->SetVariable("SpecularPower");
        pkRes->SetDefaultValue("(1.0, 1.0, 1.0, 1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Ambient");
        pkRes->SetVariable("AmbientAccum");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Diffuse");
        pkRes->SetVariable("DiffuseAccum");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Specular");
        pkRes->SetVariable("SpecularAccum");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float");
        pkRes->SetSemantic("FresnelBoost");
        pkRes->SetVariable("FresnelBoostIn");
        pkRes->SetDefaultValue("(5.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float");
        pkRes->SetSemantic("FresnelExponent");
        pkRes->SetVariable("FresnelExponentIn");
        pkRes->SetDefaultValue("(4.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("RimLightDirection");
        pkRes->SetVariable("RimLightDirIn");
        pkRes->SetDefaultValue("(0.0, 0.0, 1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Ambient");
        pkRes->SetVariable("AmbientAccumOut");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Diffuse");
        pkRes->SetVariable("DiffuseAccumOut");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Specular");
        pkRes->SetVariable("SpecularAccumOut");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiCodeBlock* pkBlock = NiNew NiCodeBlock();

        pkBlock->SetLanguage("hlsl/Cg");
        pkBlock->SetPlatform("D3D11/D3D10/DX9/Xenon/PS3");
        pkBlock->SetTarget("vs_1_1/ps_2_0/vs_4_0/ps_4_0/vs_5_0/ps_5_0");
        pkBlock->SetText("\n"
            "      // Get the world space light vector.\n"
            "      float3 LightVector;\n"
            "      float DistanceToLight;\n"
            "      float DistanceToLightSquared;\n"
            "\n"
            "      if (LightType == 0)\n"
            "      {\n"
            "      LightVector = -LightDirection;\n"
            "      }\n"
            "      else\n"
            "      {\n"
            "      LightVector = LightPos - WorldPos;\n"
            "      DistanceToLightSquared = dot(LightVector, LightVector);\n"
            "      DistanceToLight = length(LightVector);\n"
            "      LightVector = normalize(LightVector);\n"
            "      }\n"
            "\n"
            "      // Take N dot L as intensity.\n"
            "      //float LightNDotL = dot(LightVector, WorldNrm);\n"
            "      //float LightIntensity = max(0, LightNDotL);\n"
            "      float LightNDotL = pow( 0.5 * dot( LightVector, WorldNrm ) + 0.5, 2 );\n"
            "      float LightIntensity = LightNDotL;\n"
            "\n"
            "      // -----------------------------------------------------------------------\n"
            "      // Calculate RimLight factor\n"
            "      float Fresnel = FresnelBoostIn * pow( ( 1 - abs( dot( WorldNrm, WorldViewVector ) ) ), FresnelExponentIn );\n"
            "      // Ignore light direction\n"
            "      //float RimIntensity = max( 0, -dot( LightVector, WorldViewVector ) ) * Fresnel;\n"
            "      float RimIntensity = max( 0, -dot( RimLightDirIn, WorldNrm ) ) * Fresnel;\n"
            "      LightIntensity += RimIntensity;\n"
            "      // -----------------------------------------------------------------------\n"
            "\n"
            "      float Attenuate = Shadow;\n"
            "\n"
            "      if (LightType != 0)\n"
            "      {\n"
            "      // Attenuate Here\n"
            "      Attenuate = LightAttenuation.x +\n"
            "      LightAttenuation.y * DistanceToLight +\n"
            "      LightAttenuation.z * DistanceToLightSquared;\n"
            "      Attenuate = max(1.0, Attenuate);\n"
            "      Attenuate = 1.0 / Attenuate;\n"
            "      Attenuate *= Shadow;\n"
            "\n"
            "      if (LightType == 2)\n"
            "      {\n"
            "      // Get intensity as cosine of light vector and direction.\n"
            "      float CosAlpha = dot(-LightVector, LightDirection);\n"
            "\n"
            "      // Factor in inner and outer cone angles.\n"
            "      float AttenDiff = LightSpotAttenuation.x - LightSpotAttenuation.y;\n"
            "      CosAlpha = saturate((CosAlpha - LightSpotAttenuation.y) /\n"
            "      AttenDiff);\n"
            "\n"
            "      // Power to falloff.\n"
            "      // The pow() here can create a NaN if CosAlpha is 0 or less.\n"
            "      // On some cards (GeForce 6800), the NaN will propagate through\n"
            "      // a ternary instruction, so we need two to be safe.\n"
            "      float origCosAlpha = CosAlpha;\n"
            "      CosAlpha = origCosAlpha <= 0.0 ? 1.0 : CosAlpha;\n"
            "      CosAlpha = pow(CosAlpha, LightSpotAttenuation.z);\n"
            "      CosAlpha = origCosAlpha <= 0.0 ? 0.0 : CosAlpha;\n"
            "\n"
            "      // Multiply the spot attenuation into the overall attenuation.\n"
            "      Attenuate *= CosAlpha;\n"
            "      }\n"
            "      }\n"
            "      // Determine the interaction of diffuse color of light and material.\n"
            "      // Scale by the attenuated intensity.\n"
            "      DiffuseAccumOut = DiffuseAccum;\n"
            "      // -----------------------------------------------------------------------\n"
            "      DiffuseAccumOut.rgb += (LightDiffuse.rgb * LightIntensity) * Attenuate;\n"
            "      // -----------------------------------------------------------------------\n"
            "\n"
            "      // -----------------------------------------------------------------------\n"
            "      // Apply shadow color(use the ambient color of the light)\n"
            "      float ShadowIntensity = 1.f - (LightIntensity * Shadow);\n"
            "      DiffuseAccumOut.rgb += LightAmbient.rgb * ShadowIntensity;\n"
            "      // Do not apply ambient color to AmbientAccum\n"
            "      AmbientAccumOut = AmbientAccum;\n"
            "      // -----------------------------------------------------------------------\n"
            "\n"
            "      SpecularAccumOut = SpecularAccum;\n"
            "      if (SpecularEnable)\n"
            "      {\n"
            "      // Get the half vector.\n"
            "      float3 LightHalfVector = LightVector + WorldViewVector;\n"
            "      LightHalfVector = normalize(LightHalfVector);\n"
            "\n"
            "      // Determine specular intensity.\n"
            "      float LightNDotH = max(0.00001f, dot(WorldNrm, LightHalfVector));\n"
            "      float LightSpecIntensity = pow(LightNDotH, SpecularPower.x);\n"
            "\n"
            "      //if (LightNDotL < 0.0)\n"
            "      //    LightSpecIntensity = 0.0;\n"
            "      // Must use the code below rather than code above.\n"
            "      // Using previous lines will cause the compiler to generate incorrect\n"
            "      // output.\n"
            "      float SpecularMultiplier = LightNDotL > 0.0 ? 1.0 : 0.0;\n"
            "\n"
            "      // Attenuate Here\n"
            "      LightSpecIntensity = LightSpecIntensity * Attenuate *\n"
            "      SpecularMultiplier;\n"
            "\n"
            "      // Determine the interaction of specular color of light and material.\n"
            "      // Scale by the attenuated intensity.\n"
            "      SpecularAccumOut.rgb += LightSpecIntensity * LightSpecular;\n"
            "      }\n"
            "\n"
            "    ");

        pkFrag->AddCodeBlock(pkBlock);
    }

    pkLib->AddNode(pkFrag);
}
//--------------------------------------------------------------------------------------------------
// @0x1427601a0
EE_NOINLINE static void CreateFragment30(NiMaterialNodeLibrary* pkLib)
{
    NiMaterialFragmentNode* pkFrag = NiNew NiMaterialFragmentNode();

    pkFrag->SetType("Pixel");
    pkFrag->SetName("CalculateHairTangentFromColor");
    pkFrag->SetDescription("\n"
        "      This fragment is responsible for sampling a hair tangent map to generate the\n"
        "      new world-space hair tangent.\n"
        "    ");
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("Color");
        pkRes->SetVariable("LocalHairTangentColor");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Normal");
        pkRes->SetLabel("World");
        pkRes->SetVariable("WorldNormalIn");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Binormal");
        pkRes->SetLabel("World");
        pkRes->SetVariable("WorldBinormalIn");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Tangent");
        pkRes->SetLabel("World");
        pkRes->SetVariable("WorldTangentIn");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetLabel("World");
        pkRes->SetVariable("WorldHairTangent");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiCodeBlock* pkBlock = NiNew NiCodeBlock();

        pkBlock->SetLanguage("hlsl/Cg");
        pkBlock->SetPlatform("D3D11/D3D10/DX9/Xenon/PS3");
        pkBlock->SetTarget("ps_2_0/ps_4_0/ps_5_0");
        pkBlock->SetText("\n"
            "      LocalHairTangentColor = LocalHairTangentColor * 2.0 - 1.0;\n"
            "      LocalHairTangentColor.z = 0;\n"
            "\n"
            "      float3x3 xForm = float3x3(WorldTangentIn, WorldBinormalIn, WorldNormalIn);\n"
            "      xForm = transpose(xForm);\n"
            "      WorldHairTangent = mul(xForm, LocalHairTangentColor.rgb);\n"
            "\n"
            "      WorldHairTangent = normalize(WorldHairTangent);\n"
            "    ");

        pkFrag->AddCodeBlock(pkBlock);
    }

    pkLib->AddNode(pkFrag);
}
//--------------------------------------------------------------------------------------------------
// @0x142760740
EE_NOINLINE static void CreateFragment31(NiMaterialNodeLibrary* pkLib)
{
    NiMaterialFragmentNode* pkFrag = NiNew NiMaterialFragmentNode();

    pkFrag->SetType("Pixel");
    pkFrag->SetName("BlendByVertexColor");
    pkFrag->SetDescription("\n"
        "      This fragment is responsible for sampling a hair tangent map to generate the\n"
        "      new world-space hair tangent.\n"
        "    ");
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetVariable("BaseColor");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetVariable("VertexColor");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float2");
        pkRes->SetSemantic("TexCoord");
        pkRes->SetVariable("UV1");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float2");
        pkRes->SetSemantic("TexCoord");
        pkRes->SetVariable("UV2");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float2");
        pkRes->SetSemantic("TexCoord");
        pkRes->SetVariable("UV3");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("sampler2D");
        pkRes->SetSemantic("Texture");
        pkRes->SetVariable("BlendMap1");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("sampler2D");
        pkRes->SetSemantic("Texture");
        pkRes->SetVariable("BlendMap2");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("sampler2D");
        pkRes->SetSemantic("Texture");
        pkRes->SetVariable("BlendMap3");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetVariable("Output");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiCodeBlock* pkBlock = NiNew NiCodeBlock();

        pkBlock->SetLanguage("hlsl/Cg");
        pkBlock->SetPlatform("D3D11/D3D10/DX9/Xenon/PS3");
        pkBlock->SetTarget("ps_2_0/ps_4_0/ps_5_0");
        pkBlock->SetText("\n"
            "      if (VertexColor.r > 0.0f)\n"
            "        Output = lerp(BaseColor, tex2D(BlendMap1, UV1).rgb, VertexColor.r);\n"
            "      else if (VertexColor.g > 0.0f)\n"
            "        Output = lerp(BaseColor, tex2D(BlendMap2, UV2).rgb, VertexColor.g);\n"
            "      else if (VertexColor.b > 0.0f)\n"
            "        Output = lerp(BaseColor, tex2D(BlendMap3, UV3).rgb, VertexColor.b);\n"
            "      else\n"
            "        Output = BaseColor;\n"
            "    ");

        pkFrag->AddCodeBlock(pkBlock);
    }

    pkLib->AddNode(pkFrag);
}
//--------------------------------------------------------------------------------------------------
// @0x142760f30
EE_NOINLINE static void CreateFragment32(NiMaterialNodeLibrary* pkLib)
{
    NiMaterialFragmentNode* pkFrag = NiNew NiMaterialFragmentNode();

    pkFrag->SetType("Pixel");
    pkFrag->SetName("CalcRimIntensity");
    pkFrag->SetDescription("\n"
        "      This fragment calculates rim light intensity.\n"
        "    ");
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Normal");
        pkRes->SetLabel("World");
        pkRes->SetVariable("WorldNrm");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("ViewVector");
        pkRes->SetLabel("World");
        pkRes->SetVariable("WorldViewVector");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float");
        pkRes->SetSemantic("FresnelBoost");
        pkRes->SetVariable("FresnelBoostIn");
        pkRes->SetDefaultValue("(5.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float");
        pkRes->SetSemantic("FresnelExponent");
        pkRes->SetVariable("FresnelExponentIn");
        pkRes->SetDefaultValue("(4.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("RimLightDirection");
        pkRes->SetVariable("RimLightDirIn");
        pkRes->SetDefaultValue("(0.0, 0.0, 1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float");
        pkRes->SetSemantic("Color");
        pkRes->SetVariable("RimIntensity");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiCodeBlock* pkBlock = NiNew NiCodeBlock();

        pkBlock->SetLanguage("hlsl/Cg");
        pkBlock->SetPlatform("D3D11/D3D10/DX9/Xenon/PS3");
        pkBlock->SetTarget("ps_2_0/ps_4_0/ps_5_0");
        pkBlock->SetText("\n"
            "      float fresnel = FresnelBoostIn * pow((1 - abs(dot(WorldNrm, WorldViewVector))), FresnelExponentIn);\n"
            "      RimIntensity = max(0, -dot(RimLightDirIn, WorldNrm)) * fresnel;\n"
            "    ");

        pkFrag->AddCodeBlock(pkBlock);
    }

    pkLib->AddNode(pkFrag);
}
//--------------------------------------------------------------------------------------------------
// @0x142761600
EE_NOINLINE static void CreateFragment33(NiMaterialNodeLibrary* pkLib)
{
    NiMaterialFragmentNode* pkFrag = NiNew NiMaterialFragmentNode();

    pkFrag->SetType("Pixel");
    pkFrag->SetName("BlendByVertexColor");
    pkFrag->SetDescription("\n"
        "      This fragment is responsible for sampling a hair tangent map to generate the\n"
        "      new world-space hair tangent.\n"
        "    ");
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetVariable("BaseColor");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetVariable("VertexColor");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float2");
        pkRes->SetSemantic("TexCoord");
        pkRes->SetVariable("UV1");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float2");
        pkRes->SetSemantic("TexCoord");
        pkRes->SetVariable("UV2");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float2");
        pkRes->SetSemantic("TexCoord");
        pkRes->SetVariable("UV3");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("sampler2D");
        pkRes->SetSemantic("Texture");
        pkRes->SetVariable("BlendMap1");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("sampler2D");
        pkRes->SetSemantic("Texture");
        pkRes->SetVariable("BlendMap2");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("sampler2D");
        pkRes->SetSemantic("Texture");
        pkRes->SetVariable("BlendMap3");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetVariable("Output");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiCodeBlock* pkBlock = NiNew NiCodeBlock();

        pkBlock->SetLanguage("hlsl/Cg");
        pkBlock->SetPlatform("D3D11/D3D10/DX9/Xenon/PS3");
        pkBlock->SetTarget("ps_2_0/ps_4_0/ps_5_0");
        pkBlock->SetText("\n"
            "      if (VertexColor.r > 0.0f)\n"
            "        Output = lerp(BaseColor, tex2D(BlendMap1, UV1).rgb, VertexColor.r);\n"
            "      else if (VertexColor.g > 0.0f)\n"
            "        Output = lerp(BaseColor, tex2D(BlendMap2, UV2).rgb, VertexColor.g);\n"
            "      else if (VertexColor.b > 0.0f)\n"
            "        Output = lerp(BaseColor, tex2D(BlendMap3, UV3).rgb, VertexColor.b);\n"
            "      else\n"
            "        Output = BaseColor;\n"
            "    ");

        pkFrag->AddCodeBlock(pkBlock);
    }

    pkLib->AddNode(pkFrag);
}
//--------------------------------------------------------------------------------------------------
// @0x142761df0
EE_NOINLINE static void CreateFragment3(NiMaterialNodeLibrary* pkLib)
{
    NiMaterialFragmentNode* pkFrag = NiNew NiMaterialFragmentNode();

    pkFrag->SetType("Vertex/Pixel");
    pkFrag->SetName("MS2CharacterHairLight");
    pkFrag->SetDescription("\n"
        "      This fragment replaces the original Light fragment in NiStandardMaterial.\n"
        "\n"
        "      Modifications from Light fragment are followings.\n"
        "      1. This fragment uses Half-Lambert equation instead of Lambert.\n"
        "      2. This fragment adds RimLight factor to diffuse.\n"
        "\n"
        "      Others are same with Light fragment.\n"
        "    ");
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("Position");
        pkRes->SetLabel("World");
        pkRes->SetVariable("WorldPos");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Normal");
        pkRes->SetLabel("World");
        pkRes->SetVariable("WorldNrm");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("int");
        pkRes->SetSemantic("LightType");
        pkRes->SetVariable("LightType");
        pkRes->SetDefaultValue("(0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("bool");
        pkRes->SetSemantic("Specularity");
        pkRes->SetVariable("SpecularEnable");
        pkRes->SetDefaultValue("(false)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float");
        pkRes->SetSemantic("Shadow");
        pkRes->SetVariable("Shadow");
        pkRes->SetDefaultValue("(1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("ViewVector");
        pkRes->SetLabel("World");
        pkRes->SetVariable("WorldViewVector");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("LightPos");
        pkRes->SetLabel("World");
        pkRes->SetVariable("LightPos");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("LightAmbient");
        pkRes->SetVariable("LightAmbient");
        pkRes->SetDefaultValue("(1.0, 1.0, 1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("LightDiffuse");
        pkRes->SetVariable("LightDiffuse");
        pkRes->SetDefaultValue("(1.0, 1.0, 1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("LightSpecular");
        pkRes->SetVariable("LightSpecular");
        pkRes->SetDefaultValue("(1.0, 1.0, 1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("LightAttenuation");
        pkRes->SetVariable("LightAttenuation");
        pkRes->SetDefaultValue("(0.0, 1.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("LightSpotAttenuation");
        pkRes->SetVariable("LightSpotAttenuation");
        pkRes->SetDefaultValue("(-1.0, -1.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("LightDirection");
        pkRes->SetVariable("LightDirection");
        pkRes->SetDefaultValue("(1.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Specular");
        pkRes->SetVariable("SpecularPower");
        pkRes->SetDefaultValue("(1.0, 1.0, 1.0, 1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Ambient");
        pkRes->SetVariable("AmbientAccum");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Diffuse");
        pkRes->SetVariable("DiffuseAccum");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Specular");
        pkRes->SetVariable("SpecularAccum");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float");
        pkRes->SetSemantic("FresnelBoost");
        pkRes->SetVariable("FresnelBoostIn");
        pkRes->SetDefaultValue("(5.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float");
        pkRes->SetSemantic("FresnelExponent");
        pkRes->SetVariable("FresnelExponentIn");
        pkRes->SetDefaultValue("(4.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("RimLightDirection");
        pkRes->SetVariable("RimLightDirIn");
        pkRes->SetDefaultValue("(0.0, 0.0, 1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetVariable("HairTangent");
        pkRes->SetDefaultValue("(0.5, 0.5, 0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Ambient");
        pkRes->SetVariable("AmbientAccumOut");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Diffuse");
        pkRes->SetVariable("DiffuseAccumOut");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Specular");
        pkRes->SetVariable("SpecularAccumOut");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiCodeBlock* pkBlock = NiNew NiCodeBlock();

        pkBlock->SetLanguage("hlsl/Cg");
        pkBlock->SetPlatform("D3D11/D3D10/DX9/Xenon/PS3");
        pkBlock->SetTarget("vs_1_1/ps_2_0/vs_4_0/ps_4_0/vs_5_0/ps_5_0");
        pkBlock->SetText("\n"
            "      // Get the world space light vector.\n"
            "      float3 LightVector;\n"
            "      float DistanceToLight;\n"
            "      float DistanceToLightSquared;\n"
            "\n"
            "      if (LightType == 0)\n"
            "      {\n"
            "      LightVector = -LightDirection;\n"
            "      }\n"
            "      else\n"
            "      {\n"
            "      LightVector = LightPos - WorldPos;\n"
            "      DistanceToLightSquared = dot(LightVector, LightVector);\n"
            "      DistanceToLight = length(LightVector);\n"
            "      LightVector = normalize(LightVector);\n"
            "      }\n"
            "\n"
            "      // -----------------------------------------------------------------------\n"
            "      // Take N dot L as intensity.\n"
            "      //float LightNDotL = dot(LightVector, WorldNrm);\n"
            "      //float LightIntensity = max(0, LightNDotL);\n"
            "\n"
            "      // Replace the lambert equation by Half-Lambert.\n"
            "      float LightNDotL = pow( 0.5 * dot( LightVector, WorldNrm ) + 0.5, 2 );\n"
            "      float LightIntensity = LightNDotL;\n"
            "      // -----------------------------------------------------------------------\n"
            "\n"
            "      // -----------------------------------------------------------------------\n"
            "      // Calculate RimLight factor\n"
            "      float Fresnel = FresnelBoostIn * pow( ( 1 - abs( dot( WorldNrm, WorldViewVector ) ) ), FresnelExponentIn );\n"
            "      // Ignore light direction\n"
            "      // float RimIntensity = max( 0, -dot( LightVector, WorldViewVector ) ) * Fresnel;\n"
            "      float RimIntensity = max( 0, -dot( RimLightDirIn, WorldNrm ) ) * Fresnel;\n"
            "      LightIntensity += RimIntensity;\n"
            "      // -----------------------------------------------------------------------\n"
            "\n"
            "      float Attenuate = Shadow;\n"
            "\n"
            "      if (LightType != 0)\n"
            "      {\n"
            "      // Attenuate Here\n"
            "      Attenuate = LightAttenuation.x +\n"
            "      LightAttenuation.y * DistanceToLight +\n"
            "      LightAttenuation.z * DistanceToLightSquared;\n"
            "      Attenuate = max(1.0, Attenuate);\n"
            "      Attenuate = 1.0 / Attenuate;\n"
            "      Attenuate *= Shadow;\n"
            "\n"
            "      if (LightType == 2)\n"
            "      {\n"
            "      // Get intensity as cosine of light vector and direction.\n"
            "      float CosAlpha = dot(-LightVector, LightDirection);\n"
            "\n"
            "      // Factor in inner and outer cone angles.\n"
            "      float AttenDiff = LightSpotAttenuation.x - LightSpotAttenuation.y;\n"
            "      CosAlpha = saturate((CosAlpha - LightSpotAttenuation.y) /\n"
            "      AttenDiff);\n"
            "\n"
            "      // Power to falloff.\n"
            "      // The pow() here can create a NaN if CosAlpha is 0 or less.\n"
            "      // On some cards (GeForce 6800), the NaN will propagate through\n"
            "      // a ternary instruction, so we need two to be safe.\n"
            "      float origCosAlpha = CosAlpha;\n"
            "      CosAlpha = origCosAlpha <= 0.0 ? 1.0 : CosAlpha;\n"
            "      CosAlpha = pow(CosAlpha, LightSpotAttenuation.z);\n"
            "      CosAlpha = origCosAlpha <= 0.0 ? 0.0 : CosAlpha;\n"
            "\n"
            "      // Multiply the spot attenuation into the overall attenuation.\n"
            "      Attenuate *= CosAlpha;\n"
            "      }\n"
            "      }\n"
            "      // Determine the interaction of diffuse color of light and material.\n"
            "      // Scale by the attenuated intensity.\n"
            "      DiffuseAccumOut = DiffuseAccum;\n"
            "      DiffuseAccumOut.rgb += LightDiffuse.rgb * LightIntensity * Attenuate;\n"
            "\n"
            "      // -----------------------------------------------------------------------\n"
            "      // Apply shadow color(use the ambient color of the light)\n"
            "      float ShadowIntensity = 1.f - (LightIntensity * Shadow);\n"
            "      DiffuseAccumOut.rgb += LightAmbient.rgb * ShadowIntensity;\n"
            "      // Do not apply ambient color to AmbientAccum\n"
            "      AmbientAccumOut = AmbientAccum;\n"
            "      // -----------------------------------------------------------------------\n"
            "\n"
            "      SpecularAccumOut = SpecularAccum;\n"
            "      if (SpecularEnable)\n"
            "      {\n"
            "      // Get the half vector.\n"
            "      float3 LightHalfVector = LightVector + WorldViewVector;\n"
            "      LightHalfVector = normalize(LightHalfVector);\n"
            "\n"
            "      // Determine specular intensity.\n"
            "      float dotTH = dot(HairTangent, LightHalfVector);\n"
            "      float LightNDotH = max(0.00001f, 1 - dotTH * dotTH);\n"
            "      float LightSpecIntensity = pow(LightNDotH, SpecularPower.x); // Anisotropic Specular\n"
            "\n"
            "      LightNDotH = max(0.00001f, dot(WorldNrm, LightHalfVector));\n"
            "      LightSpecIntensity += pow(LightNDotH, SpecularPower.x); // Normal Map Specular\n"
            "      LightSpecIntensity /= 2.0f;\n"
            "\n"
            "      //if (LightNDotL < 0.0)\n"
            "      //    LightSpecIntensity = 0.0;\n"
            "      // Must use the code below rather than code above.\n"
            "      // Using previous lines will cause the compiler to generate incorrect\n"
            "      // output.\n"
            "      float SpecularMultiplier = LightNDotL > 0.0 ? 1.0 : 0.0;\n"
            "\n"
            "      // Attenuate Here\n"
            "      LightSpecIntensity = LightSpecIntensity * Attenuate *\n"
            "      SpecularMultiplier;\n"
            "\n"
            "      // Determine the interaction of specular color of light and material.\n"
            "      // Scale by the attenuated intensity.\n"
            "      SpecularAccumOut.rgb += LightSpecIntensity * LightSpecular;\n"
            "      }\n"
            "    ");

        pkFrag->AddCodeBlock(pkBlock);
    }

    pkLib->AddNode(pkFrag);
}
//--------------------------------------------------------------------------------------------------
// @0x1427634a0
EE_NOINLINE static void CreateFragment4(NiMaterialNodeLibrary* pkLib)
{
    NiMaterialFragmentNode* pkFrag = NiNew NiMaterialFragmentNode();

    pkFrag->SetType("Vertex/Pixel");
    pkFrag->SetName("LambSkin");
    pkFrag->SetDescription("\n"
        "      This fragment adds lambSkin diffuse factor.\n"
        "    ");
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("Position");
        pkRes->SetLabel("World");
        pkRes->SetVariable("WorldPos");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Normal");
        pkRes->SetLabel("World");
        pkRes->SetVariable("WorldNrm");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("int");
        pkRes->SetSemantic("LightType");
        pkRes->SetVariable("LightType");
        pkRes->SetDefaultValue("(0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float");
        pkRes->SetSemantic("Shadow");
        pkRes->SetVariable("Shadow");
        pkRes->SetDefaultValue("(1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("LightPos");
        pkRes->SetLabel("World");
        pkRes->SetVariable("LightPos");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("LightDiffuse");
        pkRes->SetVariable("LightDiffuse");
        pkRes->SetDefaultValue("(1.0, 1.0, 1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("LightAttenuation");
        pkRes->SetVariable("LightAttenuation");
        pkRes->SetDefaultValue("(0.0, 1.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("LightSpotAttenuation");
        pkRes->SetVariable("LightSpotAttenuation");
        pkRes->SetDefaultValue("(-1.0, -1.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("LightDirection");
        pkRes->SetVariable("LightDirection");
        pkRes->SetDefaultValue("(1.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Diffuse");
        pkRes->SetVariable("DiffuseAccum");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetVariable("SSSColor");
        pkRes->SetDefaultValue("(1.0, 0.2, 0.2)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float");
        pkRes->SetVariable("SSSPower");
        pkRes->SetDefaultValue("(1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Diffuse");
        pkRes->SetVariable("DiffuseAccumOut");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiCodeBlock* pkBlock = NiNew NiCodeBlock();

        pkBlock->SetLanguage("hlsl/Cg");
        pkBlock->SetPlatform("D3D11/D3D10/DX9/Xenon/PS3");
        pkBlock->SetTarget("vs_1_1/ps_2_0/vs_4_0/ps_4_0/vs_5_0/ps_5_0");
        pkBlock->SetText("\n"
            "      // Get the world space light vector.\n"
            "      float3 LightVector;\n"
            "      float DistanceToLight;\n"
            "      float DistanceToLightSquared;\n"
            "\n"
            "      if (LightType == 0)\n"
            "      {\n"
            "      LightVector = -LightDirection;\n"
            "      }\n"
            "      else\n"
            "      {\n"
            "      LightVector = LightPos - WorldPos;\n"
            "      DistanceToLightSquared = dot(LightVector, LightVector);\n"
            "      DistanceToLight = length(LightVector);\n"
            "      LightVector = normalize(LightVector);\n"
            "      }\n"
            "\n"
            "      // Take N dot L as intensity.\n"
            "      float LightNDotL = dot(LightVector, WorldNrm);\n"
            "      float LightIntensity = max(0, LightNDotL);\n"
            "\n"
            "      // -----------------------------------------------------------------------\n"
            "      // lambSkin\n"
            "      float subLamb = smoothstep( -SSSPower, 1.0, LightNDotL ) - smoothstep( 0.0, 1.0, LightNDotL );\n"
            "      subLamb = max( 0.0, subLamb );\n"
            "      // -----------------------------------------------------------------------\n"
            "\n"
            "      float Attenuate = Shadow;\n"
            "\n"
            "      if (LightType != 0)\n"
            "      {\n"
            "      // Attenuate Here\n"
            "      Attenuate = LightAttenuation.x +\n"
            "      LightAttenuation.y * DistanceToLight +\n"
            "      LightAttenuation.z * DistanceToLightSquared;\n"
            "      Attenuate = max(1.0, Attenuate);\n"
            "      Attenuate = 1.0 / Attenuate;\n"
            "      Attenuate *= Shadow;\n"
            "\n"
            "      if (LightType == 2)\n"
            "      {\n"
            "      // Get intensity as cosine of light vector and direction.\n"
            "      float CosAlpha = dot(-LightVector, LightDirection);\n"
            "\n"
            "      // Factor in inner and outer cone angles.\n"
            "      float AttenDiff = LightSpotAttenuation.x - LightSpotAttenuation.y;\n"
            "      CosAlpha = saturate((CosAlpha - LightSpotAttenuation.y) /\n"
            "      AttenDiff);\n"
            "\n"
            "      // Power to falloff.\n"
            "      // The pow() here can create a NaN if CosAlpha is 0 or less.\n"
            "      // On some cards (GeForce 6800), the NaN will propagate through\n"
            "      // a ternary instruction, so we need two to be safe.\n"
            "      float origCosAlpha = CosAlpha;\n"
            "      CosAlpha = origCosAlpha <= 0.0 ? 1.0 : CosAlpha;\n"
            "      CosAlpha = pow(CosAlpha, LightSpotAttenuation.z);\n"
            "      CosAlpha = origCosAlpha <= 0.0 ? 0.0 : CosAlpha;\n"
            "\n"
            "      // Multiply the spot attenuation into the overall attenuation.\n"
            "      Attenuate *= CosAlpha;\n"
            "      }\n"
            "      }\n"
            "      // Determine the interaction of diffuse color of light and material.\n"
            "      // Scale by the attenuated intensity.\n"
            "      DiffuseAccumOut = DiffuseAccum;\n"
            "      // -----------------------------------------------------------------------\n"
            "      DiffuseAccumOut.rgb += LightDiffuse.rgb * SSSColor * subLamb * Attenuate;\n"
            "      // -----------------------------------------------------------------------\n"
            "    ");

        pkFrag->AddCodeBlock(pkBlock);
    }

    pkLib->AddNode(pkFrag);
}
//--------------------------------------------------------------------------------------------------
// @0x142764170
EE_NOINLINE static void CreateFragment5(NiMaterialNodeLibrary* pkLib)
{
    NiMaterialFragmentNode* pkFrag = NiNew NiMaterialFragmentNode();

    pkFrag->SetType("Vertex/Pixel");
    pkFrag->SetName("MS2CharacterMergedLight");
    pkFrag->SetDescription("\n"
        "      This fragment refers shader value from shader map and uses the values as\n"
        "      parameters of MS2CharacterLight and MS2CharacterSkinLight.\n"
        "    ");
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("Position");
        pkRes->SetLabel("World");
        pkRes->SetVariable("WorldPos");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Normal");
        pkRes->SetLabel("World");
        pkRes->SetVariable("WorldNrm");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("int");
        pkRes->SetSemantic("LightType");
        pkRes->SetVariable("LightType");
        pkRes->SetDefaultValue("(0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("bool");
        pkRes->SetSemantic("Specularity");
        pkRes->SetVariable("SpecularEnable");
        pkRes->SetDefaultValue("(false)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float");
        pkRes->SetSemantic("Shadow");
        pkRes->SetVariable("Shadow");
        pkRes->SetDefaultValue("(1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("ViewVector");
        pkRes->SetLabel("World");
        pkRes->SetVariable("WorldViewVector");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("LightPos");
        pkRes->SetLabel("World");
        pkRes->SetVariable("LightPos");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("LightAmbient");
        pkRes->SetVariable("LightAmbient");
        pkRes->SetDefaultValue("(1.0, 1.0, 1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("LightDiffuse");
        pkRes->SetVariable("LightDiffuse");
        pkRes->SetDefaultValue("(1.0, 1.0, 1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("LightSpecular");
        pkRes->SetVariable("LightSpecular");
        pkRes->SetDefaultValue("(1.0, 1.0, 1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("LightAttenuation");
        pkRes->SetVariable("LightAttenuation");
        pkRes->SetDefaultValue("(0.0, 1.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("LightSpotAttenuation");
        pkRes->SetVariable("LightSpotAttenuation");
        pkRes->SetDefaultValue("(-1.0, -1.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("LightDirection");
        pkRes->SetVariable("LightDirection");
        pkRes->SetDefaultValue("(1.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Specular");
        pkRes->SetVariable("SpecularPower");
        pkRes->SetDefaultValue("(1.0, 1.0, 1.0, 1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Ambient");
        pkRes->SetVariable("AmbientAccum");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Diffuse");
        pkRes->SetVariable("DiffuseAccum");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Specular");
        pkRes->SetVariable("SpecularAccum");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("MergedMaterialCoeff");
        pkRes->SetVariable("MergedMaterialCoeffIn");
        pkRes->SetDefaultValue("(5.0, 4.0, 0.0, 1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("RimLightDirection");
        pkRes->SetVariable("RimLightDirIn");
        pkRes->SetDefaultValue("(0.0, 0.0, 1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Ambient");
        pkRes->SetVariable("AmbientAccumOut");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Diffuse");
        pkRes->SetVariable("DiffuseAccumOut");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Specular");
        pkRes->SetVariable("SpecularAccumOut");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiCodeBlock* pkBlock = NiNew NiCodeBlock();

        pkBlock->SetLanguage("hlsl/Cg");
        pkBlock->SetPlatform("D3D11/D3D10/DX9/Xenon/PS3");
        pkBlock->SetTarget("vs_1_1/ps_2_0/vs_4_0/ps_4_0/vs_5_0/ps_5_0");
        pkBlock->SetText("\n"
            "      // Get the world space light vector.\n"
            "      float3 LightVector;\n"
            "      float DistanceToLight;\n"
            "      float DistanceToLightSquared;\n"
            "\n"
            "      float FresnelBoostIn = MergedMaterialCoeffIn.r * 10.0;\n"
            "      float FresnelExponentIn = MergedMaterialCoeffIn.g * 10.0;\n"
            "      bool bSkin = MergedMaterialCoeffIn.b > 0.0;\n"
            "\n"
            "      if (LightType == 0)\n"
            "      {\n"
            "      LightVector = -LightDirection;\n"
            "      }\n"
            "      else\n"
            "      {\n"
            "      LightVector = LightPos - WorldPos;\n"
            "      DistanceToLightSquared = dot(LightVector, LightVector);\n"
            "      DistanceToLight = length(LightVector);\n"
            "      LightVector = normalize(LightVector);\n"
            "      }\n"
            "\n"
            "      // -----------------------------------------------------------------------\n"
            "      // Replace the lambert equation by Half-Lambert.\n"
            "      float LightNDotL = pow( 0.5 * dot( LightVector, WorldNrm ) + 0.5, 2 );\n"
            "      float LightIntensity = LightNDotL;\n"
            "      float3 skinColor = float3( 1.0, 0.2, 0.2 );\n"
            "      float subLamb = 0.0;\n"
            "\n"
            "      if (bSkin)\n"
            "      {\n"
            "      // lambSkin\n"
            "      subLamb = smoothstep( -1.0, 1.0, LightNDotL ) - smoothstep( 0.0, 1.0, LightNDotL );\n"
            "      subLamb = max( 0.0, subLamb );\n"
            "      }\n"
            "      // -----------------------------------------------------------------------\n"
            "\n"
            "      // -----------------------------------------------------------------------\n"
            "      // Calculate RimLight factor\n"
            "      float Fresnel = FresnelBoostIn * pow( ( 1 - abs( dot( WorldNrm, WorldViewVector ) ) ), FresnelExponentIn );\n"
            "      // Ignore light direction\n"
            "      float RimIntensity = max( 0, -dot( RimLightDirIn, WorldNrm ) ) * Fresnel;\n"
            "      LightIntensity += RimIntensity;\n"
            "      // -----------------------------------------------------------------------\n"
            "\n"
            "      float Attenuate = Shadow;\n"
            "\n"
            "      if (LightType != 0)\n"
            "      {\n"
            "      // Attenuate Here\n"
            "      Attenuate = LightAttenuation.x +\n"
            "      LightAttenuation.y * DistanceToLight +\n"
            "      LightAttenuation.z * DistanceToLightSquared;\n"
            "      Attenuate = max(1.0, Attenuate);\n"
            "      Attenuate = 1.0 / Attenuate;\n"
            "      Attenuate *= Shadow;\n"
            "\n"
            "      if (LightType == 2)\n"
            "      {\n"
            "      // Get intensity as cosine of light vector and direction.\n"
            "      float CosAlpha = dot(-LightVector, LightDirection);\n"
            "\n"
            "      // Factor in inner and outer cone angles.\n"
            "      float AttenDiff = LightSpotAttenuation.x - LightSpotAttenuation.y;\n"
            "      CosAlpha = saturate((CosAlpha - LightSpotAttenuation.y) /\n"
            "      AttenDiff);\n"
            "\n"
            "      // Power to falloff.\n"
            "      // The pow() here can create a NaN if CosAlpha is 0 or less.\n"
            "      // On some cards (GeForce 6800), the NaN will propagate through\n"
            "      // a ternary instruction, so we need two to be safe.\n"
            "      float origCosAlpha = CosAlpha;\n"
            "      CosAlpha = origCosAlpha <= 0.0 ? 1.0 : CosAlpha;\n"
            "      CosAlpha = pow(CosAlpha, LightSpotAttenuation.z);\n"
            "      CosAlpha = origCosAlpha <= 0.0 ? 0.0 : CosAlpha;\n"
            "\n"
            "      // Multiply the spot attenuation into the overall attenuation.\n"
            "      Attenuate *= CosAlpha;\n"
            "      }\n"
            "      }\n"
            "      // Determine the interaction of diffuse color of light and material.\n"
            "      // Scale by the attenuated intensity.\n"
            "      DiffuseAccumOut = DiffuseAccum;\n"
            "      DiffuseAccumOut.rgb += LightDiffuse.rgb * ( LightIntensity + skinColor * subLamb ) * Attenuate;\n"
            "\n"
            "      // -----------------------------------------------------------------------\n"
            "      // Apply shadow color(use the ambient color of the light)\n"
            "      float ShadowIntensity = 1.f - (LightIntensity * Shadow);\n"
            "      DiffuseAccumOut.rgb += LightAmbient.rgb * ShadowIntensity;\n"
            "      // Do not apply ambient color to AmbientAccum\n"
            "      AmbientAccumOut = AmbientAccum;\n"
            "      // -----------------------------------------------------------------------\n"
            "\n"
            "      SpecularAccumOut = SpecularAccum;\n"
            "      if (SpecularEnable)\n"
            "      {\n"
            "      // Get the half vector.\n"
            "      float3 LightHalfVector = LightVector + WorldViewVector;\n"
            "      LightHalfVector = normalize(LightHalfVector);\n"
            "\n"
            "      // Determine specular intensity.\n"
            "      float LightNDotH = max(0.00001f, dot(WorldNrm, LightHalfVector));\n"
            "      float LightSpecIntensity = pow(LightNDotH, SpecularPower.x);\n"
            "\n"
            "      //if (LightNDotL < 0.0)\n"
            "      //    LightSpecIntensity = 0.0;\n"
            "      // Must use the code below rather than code above.\n"
            "      // Using previous lines will cause the compiler to generate incorrect\n"
            "      // output.\n"
            "      float SpecularMultiplier = LightNDotL > 0.0 ? 1.0 : 0.0;\n"
            "\n"
            "      // Attenuate Here\n"
            "      LightSpecIntensity = LightSpecIntensity * Attenuate *\n"
            "      SpecularMultiplier;\n"
            "\n"
            "      // Determine the interaction of specular color of light and material.\n"
            "      // Scale by the attenuated intensity.\n"
            "      SpecularAccumOut.rgb += LightSpecIntensity * LightSpecular;\n"
            "      }\n"
            "\n"
            "    ");

        pkFrag->AddCodeBlock(pkBlock);
    }

    pkLib->AddNode(pkFrag);
}
//--------------------------------------------------------------------------------------------------
// @0x142765690
EE_NOINLINE static void CreateFragment6(NiMaterialNodeLibrary* pkLib)
{
    NiMaterialFragmentNode* pkFrag = NiNew NiMaterialFragmentNode();

    pkFrag->SetType("Vertex/Pixel");
    pkFrag->SetName("TransformSkinnedPosition60");
    pkFrag->SetDescription("\n"
        "      This fragment is a modified version of TransformSkinnedPosition fragment\n"
        "      in NiStandardMaterial. The count of Bones is increased to 60.\n"
        "    ");
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Position");
        pkRes->SetLabel("Local");
        pkRes->SetVariable("Position");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("int4");
        pkRes->SetSemantic("BlendIndices");
        pkRes->SetVariable("BlendIndices");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("BlendWeight");
        pkRes->SetLabel("Local");
        pkRes->SetVariable("BlendWeights");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("BONEMATRIX_TYPE");
        pkRes->SetCount(60);
        pkRes->SetSemantic("SkinBoneMatrix");
        pkRes->SetLabel("World");
        pkRes->SetVariable("Bones");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("Position");
        pkRes->SetLabel("World");
        pkRes->SetVariable("WorldPos");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4x4");
        pkRes->SetSemantic("WorldMatrix");
        pkRes->SetVariable("SkinBoneTransform");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiCodeBlock* pkBlock = NiNew NiCodeBlock();

        pkBlock->SetLanguage("hlsl/Cg");
        pkBlock->SetPlatform("D3D11/D3D10/DX9/Xenon");
        pkBlock->SetTarget("vs_1_1/ps_2_0/vs_4_0/ps_4_0/vs_5_0/ps_5_0");
        pkBlock->SetText("\n"
            "      // TransformSkinnedPosition *********************************************\n"
            "      // Transform the skinned position into world space\n"
            "      // Composite the skinning transform which will take the vertex\n"
            "      // and normal to world space.\n"
            "      float fWeight3 = 1.0 - BlendWeights[0] - BlendWeights[1] - BlendWeights[2];\n"
            "      BONEMATRIX_TYPE ShortSkinBoneTransform;\n"
            "      ShortSkinBoneTransform  = Bones[BlendIndices[0]] * BlendWeights[0];\n"
            "      ShortSkinBoneTransform += Bones[BlendIndices[1]] * BlendWeights[1];\n"
            "      ShortSkinBoneTransform += Bones[BlendIndices[2]] * BlendWeights[2];\n"
            "      ShortSkinBoneTransform += Bones[BlendIndices[3]] * fWeight3;\n"
            "      SkinBoneTransform = float4x4(ShortSkinBoneTransform[0], 0.0f,\n"
            "      ShortSkinBoneTransform[1], 0.0f,\n"
            "      ShortSkinBoneTransform[2], 0.0f,\n"
            "      ShortSkinBoneTransform[3], 1.0f);\n"
            "\n"
            "      // Transform into world space.\n"
            "      WorldPos.xyz = mul(float4(Position, 1.0), ShortSkinBoneTransform);\n"
            "      WorldPos.w = 1.0f;\n"
            "    ");

        pkFrag->AddCodeBlock(pkBlock);
    }

    pkLib->AddNode(pkFrag);
}
//--------------------------------------------------------------------------------------------------
// @0x142765d10
EE_NOINLINE static void CreateFragment7(NiMaterialNodeLibrary* pkLib)
{
    NiMaterialFragmentNode* pkFrag = NiNew NiMaterialFragmentNode();

    pkFrag->SetType("Vertex/Pixel");
    pkFrag->SetName("ColorOverride");
    pkFrag->SetDescription("\n"
        "      This fragment overrides the base texture color with control map and colors.\n"
        "    ");
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("ColorOverrideControl");
        pkRes->SetVariable("ColorOverrideControl");
        pkRes->SetDefaultValue("(1.0, 1.0, 1.0, 1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Color0");
        pkRes->SetVariable("Color0");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0, 1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Color1");
        pkRes->SetVariable("Color1");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0, 1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Color2");
        pkRes->SetVariable("Color2");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0, 1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Diffuse");
        pkRes->SetVariable("DiffuseTexAccum");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Diffuse");
        pkRes->SetVariable("DiffuseTexAccumOut");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiCodeBlock* pkBlock = NiNew NiCodeBlock();

        pkBlock->SetLanguage("hlsl/Cg");
        pkBlock->SetPlatform("D3D11/D3D10/DX9/Xenon/PS3");
        pkBlock->SetTarget("vs_1_1/ps_2_0/vs_4_0/ps_4_0/vs_5_0/ps_5_0");
        pkBlock->SetText("\n"
            "      float3 overridedColor = Color0.rgb * ColorOverrideControl.r\n"
            "      + Color1.rgb * ColorOverrideControl.g\n"
            "      + Color2.rgb * (1.0 - ColorOverrideControl.r);\n"
            "      DiffuseTexAccumOut = lerp(DiffuseTexAccum, overridedColor, ColorOverrideControl.a);\n"
            "    ");

        pkFrag->AddCodeBlock(pkBlock);
    }

    pkLib->AddNode(pkFrag);
}
//--------------------------------------------------------------------------------------------------
// @0x1427664a0
EE_NOINLINE static void CreateFragment8(NiMaterialNodeLibrary* pkLib)
{
    NiMaterialFragmentNode* pkFrag = NiNew NiMaterialFragmentNode();

    pkFrag->SetType("Vertex/Pixel");
    pkFrag->SetName("DecalColorOverride");
    pkFrag->SetDescription("\n"
        "      This fragment overrides the base texture color with control map and colors.\n"
        "    ");
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("ColorOverrideControl");
        pkRes->SetVariable("ColorOverrideControl");
        pkRes->SetDefaultValue("(1.0, 1.0, 1.0, 1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Color0");
        pkRes->SetVariable("Color0");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0, 1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Color1");
        pkRes->SetVariable("Color1");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0, 1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Color2");
        pkRes->SetVariable("Color2");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0, 1.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Diffuse");
        pkRes->SetVariable("DiffuseTexAccum");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float3");
        pkRes->SetSemantic("Color");
        pkRes->SetLabel("Diffuse");
        pkRes->SetVariable("DiffuseTexAccumOut");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiCodeBlock* pkBlock = NiNew NiCodeBlock();

        pkBlock->SetLanguage("hlsl/Cg");
        pkBlock->SetPlatform("D3D11/D3D10/DX9/Xenon/PS3");
        pkBlock->SetTarget("vs_1_1/ps_2_0/vs_4_0/ps_4_0/vs_5_0/ps_5_0");
        pkBlock->SetText("\n"
            "      float3 overridedColor = Color0.rgb * ColorOverrideControl.r\n"
            "      + Color1.rgb * ColorOverrideControl.g\n"
            "      + Color2.rgb * (1.0 - ColorOverrideControl.r);\n"
            "      if (ColorOverrideControl.a > 0)\n"
            "        DiffuseTexAccumOut = overridedColor;\n"
            "      else\n"
            "        DiffuseTexAccumOut = DiffuseTexAccum;\n"
            "    ");

        pkFrag->AddCodeBlock(pkBlock);
    }

    pkLib->AddNode(pkFrag);
}
//--------------------------------------------------------------------------------------------------
// @0x142766c30
EE_NOINLINE static void CreateFragment9(NiMaterialNodeLibrary* pkLib)
{
    NiMaterialFragmentNode* pkFrag = NiNew NiMaterialFragmentNode();

    pkFrag->SetType("Vertex/Pixel");
    pkFrag->SetName("TexCoordTransform2D");
    pkFrag->SetDescription("\n"
        "      This fragment computes the 2D transform of a texture UV coord.\n"
        "    ");
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float2");
        pkRes->SetSemantic("TexCoord");
        pkRes->SetVariable("TexCoordIn");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float4");
        pkRes->SetSemantic("Transform2D");
        pkRes->SetVariable("Transform2D");
        pkRes->SetDefaultValue("(0.0, 0.0, 0.0, 0.1)");

        pkFrag->AddInputResource(pkRes);
    }
    {
        NiMaterialResource* pkRes = NiNew NiMaterialResource();

        pkRes->SetType("float2");
        pkRes->SetSemantic("TexCoord");
        pkRes->SetVariable("TexCoordOut");

        pkFrag->AddOutputResource(pkRes);
    }
    {
        NiCodeBlock* pkBlock = NiNew NiCodeBlock();

        pkBlock->SetLanguage("hlsl/Cg");
        pkBlock->SetPlatform("D3D11/D3D10/DX9/Xenon/PS3");
        pkBlock->SetTarget("vs_1_1/ps_2_0/vs_4_0/ps_4_0/vs_5_0/ps_5_0");
        pkBlock->SetText("\n"
            "\n"
            "      // 0.5?\?\353\271\274\352\263\240(\352\270?\?\?\?\357\277\275\353\217\231)\n"
            "      TexCoordIn -= 0.5f;\n"
            "\n"
            "      // Translation\n"
            "      TexCoordIn -= float2(Transform2D.x, Transform2D.y);\n"
            "      TexCoordIn.x *= 2.0f;\n"
            "\n"
            "      // Rotation\n"
            "      float fSin;\n"
            "      float fCos;\n"
            "      sincos(-Transform2D.z, fSin, fCos);\n"
            "      TexCoordOut.x = fCos * TexCoordIn.x - fSin * TexCoordIn.y;\n"
            "      TexCoordOut.y = fSin * TexCoordIn.x + fCos * TexCoordIn.y;\n"
            "\n"
            "      // Scaling\n"
            "      TexCoordOut *= 1.f / Transform2D.w;\n"
            "\n"
            "      // 0.5?\?\?\357\277\275\355\225\234?\?\352\270?\?\?\357\277\275\353\263\265\352\265?\n"
            "      TexCoordOut += 0.5f;\n"
            "    ");

        pkFrag->AddCodeBlock(pkBlock);
    }

    pkLib->AddNode(pkFrag);
}
//--------------------------------------------------------------------------------------------------
// @0x142767020
NiMaterialNodeLibrary* MS2MaterialNodeLibrary::CreateMaterialNodeLibrary()
{
    NiMaterialNodeLibrary* pkLib = NiNew NiMaterialNodeLibrary(1);

    CreateFragment0(pkLib);
    CreateFragment1(pkLib);
    CreateFragment2(pkLib);
    CreateFragment3(pkLib);
    CreateFragment4(pkLib);
    CreateFragment5(pkLib);
    CreateFragment6(pkLib);
    CreateFragment7(pkLib);
    CreateFragment8(pkLib);
    CreateFragment9(pkLib);
    CreateFragment10(pkLib);
    CreateFragment11(pkLib);
    CreateFragment12(pkLib);
    CreateFragment13(pkLib);
    CreateFragment14(pkLib);
    CreateFragment15(pkLib);
    CreateFragment16(pkLib);
    CreateFragment17(pkLib);
    CreateFragment18(pkLib);
    CreateFragment19(pkLib);
    CreateFragment20(pkLib);
    CreateFragment21(pkLib);
    CreateFragment22(pkLib);
    CreateFragment23(pkLib);
    CreateFragment24(pkLib);
    CreateFragment25(pkLib);
    CreateFragment26(pkLib);
    CreateFragment27(pkLib);
    CreateFragment28(pkLib);
    CreateFragment29(pkLib);
    CreateFragment30(pkLib);
    CreateFragment31(pkLib);
    CreateFragment32(pkLib);
    CreateFragment33(pkLib);

    return pkLib;
}

// MS2-PIN: ??_7?$NiTArray@V?$SmartPointer@VNiCodeBlock@@@efd@@V?$NiTNewInterface@V?$SmartPointer@VNiCodeBlock@@@efd@@@@@@6B@ 0x143026d38
// MS2-PIN: ??_7?$NiTObjectArray@V?$SmartPointer@VNiCodeBlock@@@efd@@@@6B@ 0x143026d40
// MS2-PIN: ??_7NiMaterialFragmentNode@@6B@ 0x143026d48
