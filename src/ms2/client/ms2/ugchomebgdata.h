// ugchomebgdata.h - the ugc home environment tables: UgcHomeBgData (background), UgcHomeLightData (ambient light),
// UgcHomeCameraData (camera pose) and UgcHomeOptionData, the TSingleton that loads Table/ugcBackground.xml,
// ugcHousingLight.xml and ugcHousingCamera.xml and applies one selected row of each to the home map. Recovered from
// MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is ?\ugchomebgdata.cpp (0x140b67d70-0x140b6c7a0). Header and
// member names are invented from use. UgcHomeOptionData (0x98) replaces the placeholder of the same size in
// placeholder/ugchomeoptiondata.h (only the ctor was known).
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <atlstr.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"   // MS2Ptr<T>
#include "ms2/placeholder/nipoint3.h"
#include "ms2/commonfiles/os.h"        // TSingleton<T>

class CInPacket;

// efd::Point3 with the default constructor 0x1405522f0 and the plain assignment 0x14097fad0.
struct Unk_UhPoint3
{
    Unk_UhPoint3();                                         // 0x1405522f0
    Unk_UhPoint3(const Vector3& pt);                // 0x14027dcf0 (NiPoint3(const efd::Point3&))
    Unk_UhPoint3& operator=(const Unk_UhPoint3& pt);        // 0x14097fad0
    Unk_UhPoint3& FUN_140ae9270(float f);                   // efd::Point3::operator/=(float)
    float x, y, z;
};
MS2_CHECK_SIZE(Unk_UhPoint3, 12);

// RTTI UgcHomeBgData, 0x28 bytes: one background row (the string-table name and the map path).
class UgcHomeBgData : public CPtred
{
public:
    UgcHomeBgData(CStringW strName, CString strPath);       // 0x140b67d70
    virtual ~UgcHomeBgData();                               // 0x140b69780

    CStringW m_strName;                                     // +0x18 display name (string table 0x33)
    CString m_strPath;                                      // +0x20 "path"
};
MS2_CHECK_SIZE(UgcHomeBgData, 0x28);

// RTTI UgcHomeLightData, 0x30 bytes: one ambient light row.
class UgcHomeLightData : public CPtred
{
public:
    UgcHomeLightData(CStringW strName, Unk_UhPoint3 color);   // 0x140b67e00
    virtual ~UgcHomeLightData();                            // 0x140b697f0

    CStringW m_strName;                                     // +0x18
    Unk_UhPoint3 m_color;                                   // +0x20 "ambientcolor" / 255
};
MS2_CHECK_SIZE(UgcHomeLightData, 0x30);

// RTTI UgcHomeCameraData, 0x38 bytes: one camera row.
class UgcHomeCameraData : public CPtred
{
public:
    UgcHomeCameraData(CStringW strName);                    // 0x140b67e90
    virtual ~UgcHomeCameraData();                           // 0x140b697c0

    CStringW m_strName;                                     // +0x18
    Unk_UhPoint3 m_offset;                                  // +0x20 "offset"
    Unk_UhPoint3 m_upAxis;                                  // +0x2c "upAxis"
};
MS2_CHECK_SIZE(UgcHomeCameraData, 0x38);

// The selected row of each table, 3 bytes: {background, light, camera}.
struct Unk_UhSetting
{
    Unk_UhSetting();                                        // 0x140b68e60
    void Reset();                                           // 0x140b68e90
    void Read(CInPacket& packet);                           // 0x140b68ec0
    void Apply();                                           // 0x140b68f60 apply all three to the home map

    unsigned char m_nBg;
    unsigned char m_nLight;
    unsigned char m_nCamera;
};
MS2_CHECK_SIZE(Unk_UhSetting, 3);

class UgcHomeOptionData : public TSingleton<UgcHomeOptionData>
{
public:
    UgcHomeOptionData();                                    // 0x140b67f20
    virtual ~UgcHomeOptionData();                           // 0x140b69820 (??_G 0x140b69b20)

    void Load();                                            // 0x140b67fa0 the three tables
    CString GetBgPath(unsigned char nType);                 // 0x140b67fe0 "" when missing
    Unk_UhPoint3 GetLightColor(unsigned char nType);     // 0x140b680b0
    Unk_UhPoint3 GetCameraOffset(unsigned char nType);   // 0x140b68160
    Unk_UhPoint3 GetCameraUp(unsigned char nType);       // 0x140b68210
    void ApplyBg(unsigned char nType);                      // 0x140b682c0
    void ApplyLight(unsigned char nType);                   // 0x140b682f0
    void ApplyCamera(unsigned char nType);                  // 0x140b683f0
    void LoadBg();                                          // 0x140b684a0 ugcBackground.xml
    void LoadLight();                                       // 0x140b68810 ugcHousingLight.xml
    void LoadCamera();                                      // 0x140b68b20 ugcHousingCamera.xml

    ATL::CRBMap<unsigned, MS2Ptr<UgcHomeBgData> > m_mapBg;       // +0x08
    ATL::CRBMap<unsigned, MS2Ptr<UgcHomeLightData> > m_mapLight; // +0x38
    ATL::CRBMap<unsigned, MS2Ptr<UgcHomeCameraData> > m_mapCamera;   // +0x68
};
MS2_CHECK_SIZE(UgcHomeOptionData, 0x98);
