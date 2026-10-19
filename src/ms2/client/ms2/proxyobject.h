// proxyobject.h - CProxyObject (efd RTTI "CProxyObject", class id 0x0620004b): a GameObject that stands for a map entity in the
// map editor's proxy view: it shows the entity's model (the "DropItemNIF" placeholder named by the entity's asset id) and, for
// a radius, a CTwoCircleCollision shape that follows it. The proxies are kept by the proxy manager (CProxyObjectMgr below,
// unrecovered real name) in a map entity id -> proxy. Header and file name assumed from the RTTI name; unit unit_1416c2c00
// (0x1416c2c00-0x1416c4de0 .text$mn, 0x1400fe440-0x1400fe730 .text$di). Size 0x148 (??_G 0x1416c3ce0 frees 0x148). w422.
#pragma once
#include <atlcoll.h>
#include <efd/AssetID.h>
#include "ms2/client/ms2/gameobject.h"
#include "ms2/placeholder/ctwocirclecollision.h"
#include "ms2/placeholder/nipoint3.h"

class Unk_GoAttachment;

class CProxyObject : public GameObject
{
    EE_DECLARE_CLASS1(CProxyObject, 0x0620004b, GameObject);

public:
    CProxyObject();                                                 // 0x1416c2c00
    virtual ~CProxyObject();                                        // 0x1416c2c60 (??_G 0x1416c3ce0)

    virtual int vfunc_11();                                         // 11 0x1416c2d10 hide the model's shadow flags, clear the visible property
    virtual void vfunc_19(efd::Point3 kPos);                        // 19 0x1416c2d80 move the object and its collision shape
    virtual Unk_GoAttachment* vfunc_26();                           // 26 0x1416c3ee0 the collision shape

    int FUN_1416c2e70(efd::AssetID asset, efd::Point3 kPos, efd::Point3 kRot, float fRadius);   // 0x1416c2e70 place the proxy

private:
    MS2_LAYOUT_FRIEND;
    CTwoCircleCollision* m_pCollision;                              // +0x140 owned
};
MS2_CHECK_SIZE(CProxyObject, 0x148);
MS2_CHECK_OFFSET(CProxyObject, m_pCollision, 0x140);
