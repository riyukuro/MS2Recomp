// ugcmapoptions.h - the small CPtred records of the UGC map (house) code that live in ?\ugcmapoptions.cpp: the house
// options (UGCMapOptions), a cube for sale (CubeSalable), the house entry block (UGCMapEnterBlockInfo), a blocked visitor
// (UGCMapBlock), the weapon of a cube object (ObjectWeaponInfo) and a cube's notice text (NoticeCubeInfo). The class
// names are RTTI; member names are invented from use. CubeItemInfo, UserUGCMapInfo and Cube, whose out-of-line members
// are in the same unit, keep their existing headers (placeholder/cubeiteminfo.h, userugcmapinfo.h, cube.h).
// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). NOT an original header.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <map>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/clockcriticalsection.h"

template <class T> class Unk_PayloadPtr;

// The option kind keying both option tables (as cubemapinformationservice_tail.h; enumerators unknown).
enum Unk_CMISKindB { Unk_CMISKindB_None };

// RTTI UGCMapOptions, 0x80 bytes (vftable 0x142da1bb8: the dtor slot only).
class UGCMapOptions : public CPtred
{
public:
    UGCMapOptions();                                        // 0x1408b3260
    // implicit virtual dtor (0x1408b6e70: no vfptr reset)

    CLockCriticalSection m_lock;                            // +0x18
    unsigned char m_n48;                                    // +0x48 (default 10)
    unsigned char m_n49;                                    // +0x49 (default 5)
    std::map<Unk_CMISKindB, unsigned char> m_byteOptions;   // +0x50
    std::map<Unk_CMISKindB, int> m_intOptions;              // +0x60
    int m_n70;                                              // +0x70
    int m_n74;                                              // +0x74
    int m_n78;                                              // +0x78
    float m_f7c;                                            // +0x7c (default 1)
};
MS2_CHECK_SIZE(UGCMapOptions, 0x80);
MS2_CHECK_OFFSET(UGCMapOptions, m_byteOptions, 0x50);
MS2_CHECK_OFFSET(UGCMapOptions, m_intOptions, 0x60);

// RTTI CubeSalable, 0x78 bytes (vftable 0x142da1bc8).
class CubeSalable : public CPtred
{
public:
    CubeSalable();                                          // 0x1408b3340
    // implicit virtual dtor (0x1408b6d90: no vfptr reset)

    __int64 m_n18;
    int m_n20;
    int m_n24;
    int m_n28;
    int m_n2c;
    __int64 m_n30;
    __int64 m_n38;
    CStringW m_str40;
    CStringW m_str48;
    __int64 m_n50;
    unsigned char m_n58;
    CStringW m_str60;
    __int64 m_n68;
    unsigned char m_n70;
};
MS2_CHECK_SIZE(CubeSalable, 0x78);
MS2_CHECK_OFFSET(CubeSalable, m_str60, 0x60);

// RTTI UGCMapEnterBlockInfo, 0x28 bytes (scenestategame.cpp's Unk_MyPCPortalLock).
class UGCMapEnterBlockInfo : public CPtred
{
public:
    UGCMapEnterBlockInfo();                                 // 0x1408b3e20
    // implicit virtual dtor (0x1408b6e50: no vfptr reset)

    __int64 m_n18;
    int m_n20;
};
MS2_CHECK_SIZE(UGCMapEnterBlockInfo, 0x28);

// RTTI UGCMapBlock, 0x40 bytes.
class UGCMapBlock : public CPtred
{
public:
    UGCMapBlock();                                          // 0x1408b3e70
    // implicit virtual dtor (0x1408b6e20: no vfptr reset)

    __int64 m_n18;
    int m_n20;
    int m_n24;
    int m_n28;
    int m_n2c;
    int m_n30;
    CStringA m_str38;
};
MS2_CHECK_SIZE(UGCMapBlock, 0x40);

// RTTI ObjectWeaponInfo, 0x58 bytes: the weapon a function cube hands out.
class ObjectWeaponInfo : public CPtred
{
public:
    ObjectWeaponInfo();                                     // 0x1408b45b0
    virtual ~ObjectWeaponInfo();                            // 0x1408b4660

    Unk_PayloadPtr<ObjectWeaponInfo> FUN_1408b46b0() const; // clone

    int m_n18;
    int m_n1c;
    int m_n20;
    int m_n24;                                              // (default 1)
    int m_n28;
    float m_f2c;                                            // (default 1)
    CStringA m_str30;
    ATL::CAtlArray<unsigned int> m_ids;                     // +0x38
};
MS2_CHECK_SIZE(ObjectWeaponInfo, 0x58);
MS2_CHECK_OFFSET(ObjectWeaponInfo, m_ids, 0x38);

// RTTI NoticeCubeInfo, 0x28 bytes: the notice text of a cube.
class NoticeCubeInfo : public CPtred
{
public:
    NoticeCubeInfo();                                       // 0x1408b4850
    virtual ~NoticeCubeInfo();                              // 0x1408b48a0

    NoticeCubeInfo* Clone() const;                          // 0x1408b48e0
    void Set(const CStringW& strText, int n);               // 0x1408b4970
    const CStringW& GetText() const;                        // 0x1408b49c0
    int GetN20() const;                                     // 0x1408b49e0

    CStringW m_strText;                                     // +0x18
    int m_n20;                                              // +0x20
};
MS2_CHECK_SIZE(NoticeCubeInfo, 0x28);
