// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Guild/item assignment and smart-pointer null-test COMDATs
// (CPtred/Unk_GuildStrEntry/ItemEntity copy-assign, Unk_PayloadPtr<T>/MS2Ptr<T> operator==(T*)).
// MS2-UNIT: unit_1404efd80
// MS2-RANGE: 0x1404efd80-0x1404f01e0 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-FUNCTIONAL: operator== for the pointer wrappers whose element type is unnamed in symbols (guessed; bodies are byte-identical copies)
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\unknown_1404efd80.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <afx.h>
#include "ms2/commonfiles/guilddef_1.h"
#include "ms2/commonfiles/guilddef_2.h"
#include "ms2/commonfiles/guilddef_4.h"
#include "ms2/commonfiles/itemgift.h"
#include "ms2/placeholder/cguildxmldata.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// {2 qwords, CStringW}: copy-assign at 0x1404efd90
struct Unk_QQStr {
    __int64 a;
    __int64 b;
    CStringW s;
};
MS2_CHECK_SIZE(Unk_QQStr, 0x18);

// Anchor: odr-uses the implicitly defined copy-assignments so their COMDATs are emitted.
void Unk_Anchor_1404efd80(CPtred& a, const CPtred& b, Unk_GuildStrEntry& c, const Unk_GuildStrEntry& d,
                          ItemEntity& e, const ItemEntity& f, Unk_QQStr& g, const Unk_QQStr& h)
{
    a = b;
    c = d;
    e = f;
    g = h;
}

template bool Unk_PayloadPtr<CGuildXmlData::GuildHouse>::operator==(CGuildXmlData::GuildHouse*) const;      // at 0x1404eff20
template bool Unk_PayloadPtr<CGuildXmlData::GuildProperty>::operator==(CGuildXmlData::GuildProperty*) const;  // at 0x1404eff60
template bool Unk_PayloadPtr<CGuildXmlData::GuildSkill>::operator==(CGuildXmlData::GuildSkill*) const;       // at 0x1404effa0
template bool MS2Ptr<CGuildGrade>::operator==(CGuildGrade*) const;                                        // at 0x1404effe0
template bool MS2Ptr<CGuildMember>::operator==(CGuildMember*) const;                                      // at 0x1404f0020
template bool MS2Ptr<CGuildNpc>::operator==(CGuildNpc*) const;                                            // at 0x1404f0060
template bool Unk_PayloadPtr<CGuildNpcShop>::operator==(CGuildNpcShop*) const;                            // at 0x1404f00a0
template bool MS2Ptr<CGuildCustomEvent>::operator==(CGuildCustomEvent*) const;                            // at 0x1404f00e0
template bool MS2Ptr<CGuildSkill>::operator==(CGuildSkill*) const;                                        // at 0x1404f0120
template bool Unk_PayloadPtr<CGuildXmlData::GuildNpc>::operator==(CGuildXmlData::GuildNpc*) const;           // at 0x1404f0160
template bool Unk_PayloadPtr<CGuildXmlData::GuildEvent>::operator==(CGuildXmlData::GuildEvent*) const;       // at 0x1404f01a0
