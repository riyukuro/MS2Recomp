// gameobjecteffectnifctx.h - GameObjectEffectNifCtx (RTTI .?AVGameObjectEffectNifCtx@@, 0x38 bytes, CPtred): the description of
// one nif effect attached to a game object (fields from the XML node and the packet stream). Owning unit:
// ?\gameobjecteffectnifctx.cpp (0x1404746a0-0x140474af0). Header name assumed from the unit path. vftable: dtor only.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/commonfiles/stream.h"

class TiXmlElement;     // game TinyXML element

class GameObjectEffectNifCtx : public CPtred
{
public:
    GameObjectEffectNifCtx();                                   // 0x1404746a0
    virtual ~GameObjectEffectNifCtx() = default;                     // 0x140474960 (scalar deleting 0x140474990)

    unsigned GetGameOID() const;                                // 0x140474720
    void LoadXml(TiXmlElement* pNode);                         // 0x140474740
    void Write(COutputStream& out) const;                       // 0x1404747f0
    void Read(CInputStream& in);                                // 0x140474870

    unsigned m_nGameOID;            // +0x18 xml "gameOID"
    CString m_strNifPath;           // +0x20 "nifPath"
    bool m_bOutline;                // +0x28 "isOutline" (true)
    float m_fScale;                 // +0x2c "scale" (1.0)
    float m_fRotateZ;               // +0x30 "rotateZ" (0.0)
};
MS2_CHECK_SIZE(GameObjectEffectNifCtx, 0x38);
MS2_CHECK_OFFSET(GameObjectEffectNifCtx, m_nGameOID, 0x18);
MS2_CHECK_OFFSET(GameObjectEffectNifCtx, m_strNifPath, 0x20);
MS2_CHECK_OFFSET(GameObjectEffectNifCtx, m_bOutline, 0x28);
MS2_CHECK_OFFSET(GameObjectEffectNifCtx, m_fScale, 0x2c);
MS2_CHECK_OFFSET(GameObjectEffectNifCtx, m_fRotateZ, 0x30);

// Stream operators (inline-style wrappers emitted in this unit).
CInputStream& FUN_140474900(CInputStream& in, GameObjectEffectNifCtx& ctx);     // in >> ctx
COutputStream& FUN_140474930(COutputStream& out, const GameObjectEffectNifCtx& ctx);   // out << ctx
