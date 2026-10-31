// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\gameobjecteffectnifctx.cpp
// MS2-RANGE: 0x1404746a0-0x140474af0 .text$mn
// MS2-PIN: ??1GameObjectEffectNifCtx@@UEAA@XZ 0x140474960
// MS2-PIN: ??_GGameObjectEffectNifCtx@@UEAAPEAXI@Z 0x140474990
// MS2-PIN: memmove_s 0x1404749d0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\gameobjecteffectnifctx.cpp"
#include <vcruntime_string.h>
#pragma function(memcpy, memset)
#include "ms2/placeholder/ms2stdafx.h"
#include "gameobjecteffectnifctx.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit callees (bound to the exe by name) ----
// TinyXML attribute helpers (commonfiles\tinyxmlhelper.cpp).
int XmlGetAttr(class TiXmlElement*, char const*, unsigned int&);   // C3: was FUN_140873220
int FUN_1408733e0(Unk_140165cf0* pNode, const char* pszName, CString& strOut);
int XmlGetAttr(class TiXmlElement*, char const*, bool&);   // C3: was FUN_1408730a0
int XmlGetAttr(class TiXmlElement*, char const*, float&);   // C3: was FUN_140873360
// Stream primitives (packet.cpp).
CInputStream& FUN_14070f480(CInputStream& in, unsigned& n);
CInputStream& FUN_14070f580(CInputStream& in, CString& str);
CInputStream& FUN_14070f300(CInputStream& in, bool& b);
CInputStream& FUN_14070f540(CInputStream& in, float& f);
COutputStream& FUN_14070f9a0(COutputStream& out, unsigned n);
COutputStream& FUN_14070faa0(COutputStream& out, const CString& str);
COutputStream& FUN_14070f820(COutputStream& out, bool b);
COutputStream& FUN_14070fa60(COutputStream& out, float f);

MS2_EMIT_CRT_MEMMOVE_S_COPY(1);

// @0x1404746a0
GameObjectEffectNifCtx::GameObjectEffectNifCtx()
    : m_nGameOID(0), m_bOutline(true), m_fScale(1.0f), m_fRotateZ(0.0f)
{
}

// @0x140474720
unsigned GameObjectEffectNifCtx::GetGameOID() const
{
    return m_nGameOID;
}

// @0x140474740
void GameObjectEffectNifCtx::LoadXml(Unk_140165cf0* pNode)
{
    XmlGetAttr((class TiXmlElement*)(pNode), "gameOID", m_nGameOID);
    FUN_1408733e0(pNode, "nifPath", m_strNifPath);
    XmlGetAttr((class TiXmlElement*)(pNode), "isOutline", m_bOutline);
    XmlGetAttr((class TiXmlElement*)(pNode), "scale", m_fScale);
    XmlGetAttr((class TiXmlElement*)(pNode), "rotateZ", m_fRotateZ);
}
MS2_REPLACE_METHOD(0x140474740, GameObjectEffectNifCtx, LoadXml, 164, 0x6F31E288);

// @0x1404747f0
void GameObjectEffectNifCtx::Write(COutputStream& out) const
{
    FUN_14070f9a0(out, m_nGameOID);
    FUN_14070faa0(out, m_strNifPath);
    FUN_14070f820(out, m_bOutline);
    FUN_14070fa60(out, m_fScale);
    FUN_14070fa60(out, m_fRotateZ);
}
MS2_REPLACE_METHOD(0x1404747f0, GameObjectEffectNifCtx, Write, 118, 0x43FEDBFD);

// @0x140474870
void GameObjectEffectNifCtx::Read(CInputStream& in)
{
    FUN_14070f480(in, m_nGameOID);
    FUN_14070f580(in, m_strNifPath);
    FUN_14070f300(in, m_bOutline);
    FUN_14070f540(in, m_fScale);
    FUN_14070f540(in, m_fRotateZ);
}
MS2_REPLACE_METHOD(0x140474870, GameObjectEffectNifCtx, Read, 129, 0x2AF331AA);

// @0x140474900
CInputStream& FUN_140474900(CInputStream& in, GameObjectEffectNifCtx& ctx)
{
    ctx.Read(in);
    return in;
}

// @0x140474930
COutputStream& FUN_140474930(COutputStream& out, const GameObjectEffectNifCtx& ctx)
{
    ctx.Write(out);
    return out;
}

