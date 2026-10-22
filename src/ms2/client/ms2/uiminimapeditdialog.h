// uiminimapeditdialog.h - UIMinimapEditDialog (RTTI .?AVUIMinimapEditDialog@@ 0x143a9b630, 0x1f8 bytes, UI type 0x4e2b, swf
// "MinimapEditDialog", vftable 0x142fcb510): the map editor's minimap tool. It edits the CMinimap record of the current map
// (the <minimap> node of ./data/xml/MapXblock/<xblock>.xml): the minimap camera (fov, distance, vertical angle, rotation), the
// image rectangle (m_rectarea) and the image name/icon, saves the record back to the xml and takes the minimap screenshot.
// Header name assumed from the unit (unit_141a51ec0 = ?\uiminimapeditdialog.cpp, 0x141a51ec0-0x141a55270). Names invented from
// the callers: FUN_<va> are non-virtual members. w422.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/client/ms2/fielddatacli.h"
#include <egf/EntityID.h>
#include <NiRect.h>

class ASMovieClip;
class ASUIComponent;
class Unk_MeSlider;
class Unk_MeLabel;
class Unk_MeInput;
namespace egf { class Entity; }

class UIMinimapEditDialog : public UIDialog
{
public:
    UIMinimapEditDialog();                                          // 0x141a51f00
    virtual ~UIMinimapEditDialog();                                 //  0 0x141a54c20 (??_G 0x141a54ce0)

    virtual CString vfunc_1();                                      //  1 0x141a52020 "MinimapEditDialog"
    virtual void OnLoadComplete();                                  // 22 0x141a522a0 bind the sliders, labels and the image area
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141a52d60 swf callbacks
    virtual int vfunc_48() { return 0x4e2b; }                       // 48 0x141a54ff0 UI type
    virtual int vfunc_65();                                         // 65 0x141a52070 open: switch to the editor camera
    virtual void vfunc_67();                                        // 67 0x141a52190 close: restore the camera and the hidden entities

    MS2Ptr<Unk_MeSlider> FUN_140faff90(const CString& strName);     // 0x140faff90 slider child lookup (a UIDialog member)
    MS2Ptr<Unk_MeLabel> FUN_140e6d820(const CString& strName);      // 0x140e6d820 label child lookup
    MS2Ptr<Unk_MeInput> FUN_140e35bd0(const CString& strName);      // 0x140e35bd0 text input child lookup
    MS2Ptr<ASMovieClip> FUN_140ba7930(const CString& strName);      // 0x140ba7930 movie clip child lookup

    void FUN_141a53100();                                           // 0x141a53100 load the <minimap> node of the map xml into m_spMinimap and the camera
    void FUN_141a53750();                                           // 0x141a53750 store the camera/image area into m_spMinimap and save the xml
    void FUN_141a540f0(int bShow);                                  // 0x141a540f0 hide (1) / restore (0) the world objects for the capture
    void OnScreenShot();                                           // 0x141a545a0 save the minimap area as a png screenshot
    CString FUN_141a54940(CString strXBlock);                       // 0x141a54940 "./data/xml/MapXblock/{0}.xml"
    CString FUN_141a549c0();                                        // 0x141a549c0 "./Data/Resource/Image/Map/Minimap/%08d.dds" of the current map
    NiRect<unsigned int> FUN_141a54a50();                                           // 0x141a54a50 the rounded screen rectangle of the record

private:
    MS2_LAYOUT_FRIEND;
    CString m_strImageIcon;                                         // +0x178 <image icon>
    CString m_strImageName;                                         // +0x180 <image name>
    MS2Ptr<CMinimap> m_spMinimap;                                   // +0x188 the edited record
    ATL::CAtlList<egf::EntityID> m_hidden;                          // +0x198 entities of the objects hidden by FUN_141a540f0
    ATL::CAtlList<egf::Entity*> m_instanced;                        // +0x1c8 hardware-instanced entities hidden from the instancing service
};
MS2_CHECK_SIZE(UIMinimapEditDialog, 0x1f8);
MS2_CHECK_OFFSET(UIMinimapEditDialog, m_strImageIcon, 0x178);
MS2_CHECK_OFFSET(UIMinimapEditDialog, m_spMinimap, 0x188);
MS2_CHECK_OFFSET(UIMinimapEditDialog, m_hidden, 0x198);
MS2_CHECK_OFFSET(UIMinimapEditDialog, m_instanced, 0x1c8);
