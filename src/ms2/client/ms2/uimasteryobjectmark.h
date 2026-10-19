// uimasteryobjectmark.h - UIMasteryObjectMark (RTTI .?AVUIMasteryObjectMark@@, 0xf8 bytes, UIObject, ui id 0x4f3a) and
// its nested EntityContext. Owning unit: ?\uimasteryobjectmark.cpp (0x140e59a00-0x140e5db70; header name assumed from
// the unit path).
//
// The HUD layer that floats a "mastery mark" (tooltip with the gather success chance, the mastery kind and whether
// the player may gather it) over every gathering node (CInteractGatheringObject) and every homemade cube
// (CHomemadeCubeObject: breeding / farming) near the player. Each mark is an ASGameEntity clip created by the swf's
// "create"; the two name -> context maps keep the clip and the last texts sent to it. Per frame the marks are
// repositioned and their tooltip refreshed; a mark whose object left the field is removed.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <atlstr.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/client/ms2/uiobject.h"

class CInteractObject;
class CInteractGatheringObject;
class CFunctionCubeObject;
class CHomemadeCubeObject;
class ASObj;

class UIMasteryObjectMark : public UIObject
{
public:
    // One mark: the clip (+0x40) and what was last sent to it. RTTI .?AVEntityContext@UIMasteryObjectMark@@, 0x50 bytes.
    class EntityContext : public CPtred
    {
    public:
        EntityContext();                                            // 0x140e5c360
        virtual ~EntityContext() = default;                         //  0 0x140e5c4c0 (??_G 0x140e5c6c0)

        int m_nShown;                                               // +0x18 the tooltip is shown
        int m_nEnabled;                                             // +0x1c the object can be gathered
        CStringW m_strProp;                                         // +0x20 "prop" (success chance text)
        CStringW m_strObjName;                                      // +0x28 "objName"
        CStringW m_strType;                                         // +0x30 "type" (mastery kind: mining, farming ...)
        CStringW m_strStatus;                                       // +0x38 "status" (disable / impossible / ...)
        MS2Ptr<ASGameEntity> m_spEntity;                            // +0x40 the mark clip
    };

    typedef ATL::CAtlMap<CStringA, MS2Ptr<EntityContext>, ATL::CStringElementTraits<CStringA> > MarkMap;

    UIMasteryObjectMark();                                          // 0x140e59a00
    virtual ~UIMasteryObjectMark();                                 //  0 0x140e59af0 (??_G 0x140e5c700)
    virtual CString vfunc_1();                                      //  1 0x140e59b60 "MasteryObjectMark"
    virtual void vfunc_2();                                         //  2 0x140e5a190 load the swf
    virtual void vfunc_3();                                         //  3 0x140e5a1c0 clear the marks, unload
    virtual void vfunc_15();                                        // 15 0x140e5a560 per-frame update
    virtual void OnLoadComplete();                                  // 22 0x140e5a210 create the clips of the queued objects
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140e5a5b0
    // @0x140e5cca0
    virtual int vfunc_48() { return 0x4f3a; }                       // 48

    void FUN_140e59bb0(CInteractObject* pObject);                   // add the mark of a gathering node
    void FUN_140e59ea0(CFunctionCubeObject* pCube);                 // add the mark of a homemade cube
    void FUN_140e5a600();                                           // refresh the gathering node marks
    void FUN_140e5ac30();                                           // refresh the cube marks
    void FUN_140e5b450(const CStringA& strKey);                     // remove a gathering node mark (swf "remove")
    int FUN_140e5b520(CInteractObject* pObject, EntityContext* pContext);   // update the texts of a node mark: changed
    int FUN_140e5b620(CFunctionCubeObject* pCube, EntityContext* pContext); // same for a cube mark
    unsigned FUN_140e5b720(int nReceipeId, EntityContext* pContext);        // fill the mastery texts of a recipe: changed
    void FUN_140e5bd80(EntityContext* pContext);                    // send the texts to the clip ("setData")

private:
    MS2_LAYOUT_FRIEND;
    MarkMap m_nodes;                                                // +0x68 gathering node name -> mark
    MarkMap m_cubes;                                                // +0xb0 cube id -> mark
};
MS2_CHECK_SIZE(UIMasteryObjectMark, 0xf8);
MS2_CHECK_SIZE(UIMasteryObjectMark::EntityContext, 0x50);
MS2_CHECK_OFFSET(UIMasteryObjectMark, m_nodes, 0x68);
MS2_CHECK_OFFSET(UIMasteryObjectMark, m_cubes, 0xb0);
