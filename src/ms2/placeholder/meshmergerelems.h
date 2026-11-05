// The element types of the character mesh merger's containers (layouts proven in charactermeshmerger.cpp).
// Same definitions as unit_1410799d0 / unit_141073440; included by units that instantiate members of those
// containers (unit_141079ed0).
#pragma once
#include <NiPoint2.h>
#include <NiDataStream.h>
#include <NiFixedString.h>
#include <NiTexturingProperty.h>
#include <efd/StdContainers.h>

class NiMesh;

struct Unk_StreamElementDesc
{
    Unk_StreamElementDesc() : m_uiIndex(0), m_eFormat(NiDataStreamElement::F_UNKNOWN) {}    // explicit instantiation of the vector needs it
    Unk_StreamElementDesc(const NiFixedString& kSemantic, unsigned int uiIndex, NiDataStreamElement::Format eFormat)
        : m_kSemantic(kSemantic), m_uiIndex(uiIndex), m_eFormat(eFormat) {}

    NiFixedString m_kSemantic;
    unsigned int m_uiIndex;
    NiDataStreamElement::Format m_eFormat;
};
MS2_CHECK_SIZE(Unk_StreamElementDesc, 0x10);

struct Unk_UVRect
{
    Unk_UVRect() {}

    NiPoint2 m_kOffset;
    NiPoint2 m_kScale;
};
MS2_CHECK_SIZE(Unk_UVRect, 0x10);

struct Unk_AtlasResult
{
    Unk_AtlasResult() {}
    ~Unk_AtlasResult() {}

    efd::SmartPointer<NiTexturingProperty> m_spTexturing;
    efd::map<NiMesh*, Unk_UVRect> m_kPlacement;
};
MS2_CHECK_SIZE(Unk_AtlasResult, 0x18);
