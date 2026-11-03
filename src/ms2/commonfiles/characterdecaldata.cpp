// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CharacterDecalData, the <decal> block of an item model
// slot (see placeholder/characterdecaldata.h), plus the template glue of its std::vector<MS2Ptr<ItemCustom>>.
// MS2-UNIT: ?\characterdecaldata.cpp
// MS2-RANGE: 0x1401e4000-0x1401e5760 .text$mn
// MS2-PIN: ??1CharacterDecalData@@UEAA@XZ 0x1401e4e40
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\characterdecaldata.cpp"
#include <afx.h>
#include <afxwin.h>
#include <vector>
#include "ms2/placeholder/characterdecaldata.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
class Unk_XmlNode   // C3: member view for the former Unk_140165cf0 stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};

// @0x1401e4000
CharacterDecalData::CharacterDecalData()
    : unknown20(0.0f), unknown24(0.0f), unknown28(0.0f), unknown2c(1.0f)
{
}

// @0x1401e4090
void CharacterDecalData::FUN_1401e4090(Unk_140165cf0* pElem)
{
    Unk_140165cf0* pDecal = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("decal"));
    if (pDecal != 0)
    {
        XmlGetAttr((class TiXmlElement*)(pDecal), "texture", unknown18);
        for (Unk_140165cf0* pCustom = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pDecal))->FirstChild("custom")); pCustom != 0;
             pCustom = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pCustom))->NextSibling("custom")))
        {
            MS2Ptr<ItemCustom> spCustom(new ItemCustom);
            spCustom->FUN_140266aa0(pCustom);
            customs.push_back(spCustom);
        }
    }
}

// @0x1401e41c0
std::vector<MS2Ptr<ItemCustom> >* CharacterDecalData::FUN_1401e41c0()
{
    return &customs;
}
