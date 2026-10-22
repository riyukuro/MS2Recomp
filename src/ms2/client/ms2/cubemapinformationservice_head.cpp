// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Head of the CubeMapInformationService COMDAT tail
// (queue unit_1410d5bc0): the nine house-notice CString statics, the notice-message helpers of the cube service
// (message id -> sound/notice key, message id -> string-table id, show the notice) and the rvalue-key
// pair<const K, V> piecewise constructors the node builders of cubemapinformationservice_tail11.cpp call. Names of the
// helper classes are invented. Not an original file; part of client\ms2\cubemapinformationservice.cpp.
// MS2-UNIT: unit_1410d5bc0
// MS2-RANGE: 0x1410d5bc0-0x1410d6a30 .text$mn
// MS2-RANGE: 0x1400e6420-0x1400e65d0 .text$di
// MS2-PIN: ??$?0$$QEAH$$Z$$V@?$pair@$$CBHW4Unk_CMISByteKind@@@std@@QEAA@Upiecewise_construct_t@1@V?$tuple@$$QEAH@1@V?$tuple@$$V@1@@Z 0x1410d67c0 ; manual: inner 0x1410da9e0 stores a byte; sorts between EntityID and KindA
// MS2-PIN: ??$?0$$QEAH$$Z$$V@?$pair@$$CBHW4Unk_CMISKindA@@@std@@QEAA@Upiecewise_construct_t@1@V?$tuple@$$QEAH@1@V?$tuple@$$V@1@@Z 0x1410d6810 ; manual: inner 0x1410daa30 = pair<int,KindA>
// MS2-PIN: ??$?0$$QEAI$$Z$$V@?$pair@$$CBIH@std@@QEAA@Upiecewise_construct_t@1@V?$tuple@$$QEAI@1@V?$tuple@$$V@1@@Z 0x1410d6860 ; manual: inner 0x1410daa80 = pair<uint,int>
// MS2-PIN: ??$?0$$QEAW4Unk_CMISKindB@@$$Z$$V@?$pair@$$CBW4Unk_CMISKindB@@H@std@@QEAA@Upiecewise_construct_t@1@V?$tuple@$$QEAW4Unk_CMISKindB@@@1@V?$tuple@$$V@1@@Z 0x1410d6950 ; manual: inner 0x1410dab70 stores a dword
// MS2-PIN: ??$?0$$QEAW4Unk_CMISKindB@@$$Z$$V@?$pair@$$CBW4Unk_CMISKindB@@E@std@@QEAA@Upiecewise_construct_t@1@V?$tuple@$$QEAW4Unk_CMISKindB@@@1@V?$tuple@$$V@1@@Z 0x1410d69a0 ; manual: inner 0x1410dabc0 = pair<KindB,uchar>
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\cubemapinformationservice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/cubemapinformationservice_tail.h"
#include "ms2/commonfiles/ugcmapsetiteminfo.h"
#include "ms2/ms2recover.h"

CStringW GetStringCommonByKey(const CStringW& strKey);                // string table text by key
CStringW GetStringCommon(int nStringId);                         // string table text by id
void FUN_141276180(const CString&, const CString&);
void FUN_1412751f0(const CStringW&, int, int);                 // show a notice
class Unk_LockUIManager;
Unk_LockUIManager* FUN_1403ed2b0();
void FUN_141add1f0(Unk_LockUIManager*);

// @0x1400e6420
static CString s_strBuildingCount("system_notice_error_warningBuildingCount");
static CString s_strDefaultLand("system_notice_error_warningDefaultLand");
static CString s_strDefaultLandRotation("system_notice_error_warningDefaultLandRotation");
static CString s_strNoBuild("system_notice_error_warningNoBuild");
static CString s_strNoChangeCube("system_notice_error_warningNoChangeCube");
static CString s_strNoTearDown("system_notice_error_warningNoTearDown");
static CString s_strNoWall("system_notice_error_warningNoWall");
static CString s_strNotThisPlace("system_notice_error_warningNotThisPlace");
static CString s_strOnlyWall("system_notice_error_warningOnlyWall");

class Unk_Service6100017
{
public:
    CStringW FUN_1410d5d80(int nMessage);                      // the message's string-table text
};

class Unk_MyPCHousingSvc
{
public:
    int FUN_1410d5bc0(int nMessage, CString& strOut);          // the message's sound key (0 = none)
    void FUN_1410d6590(int nMessage);                          // show the build notice
};

// @0x1410d5bc0
int Unk_MyPCHousingSvc::FUN_1410d5bc0(int nMessage, CString& strOut)
{
    switch (nMessage) {
    case 0:
    case 0xd:
    case 0xe:
    case 0x21:
    case 0x23:
    case 0x24:
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x2a:
    case 0x2e:
    case 0x2f:
    case 0x30:
    case 0x31:
    case 0x32:
    case 0x33:
    case 0x34:
    case 0x36:
    case 0x37:
    case 0x38:
    case 0x42:
    case 0x47:
    case 0x53:
    case 0x57:
    case 0x5e:
    case 0x5f:
    case 0x60:
    case 0x61:
    case 0x66:
    case 0x70:
        return 0;
        break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 0xa:
    case 0xb:
    case 0xc:
    case 0x10:
    case 0x13:
    case 0x1e:
    case 0x2b:
    case 0x2c:
    case 0x39:
    case 0x3d:
    case 0x3e:
    case 0x40:
    case 0x41:
    case 0x49:
    case 0x4b:
    case 0x52:
    case 0x5b:
    case 0x5c:
    case 0x5d:
    case 0x63:
    case 0x65:
    case 0x67:
    case 0x68:
    case 0x69:
    case 0x6a:
    case 0x6b:
    case 0x6c:
    case 0x6d:
    case 0x6e:
    case 0x6f:
        strOut = s_strNoBuild;
        break;
    case 0xf:
    case 0x11:
        strOut = s_strOnlyWall;
        break;
    case 0x12:
        strOut = s_strNoWall;
        break;
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x18:
    case 0x19:
    case 0x29:
    case 0x4a:
        strOut = s_strNoTearDown;
        break;
    case 0x1a:
    case 0x20:
    case 0x3b:
    case 0x3c:
    case 0x58:
    case 0x5a:
        strOut = s_strNotThisPlace;
        break;
    case 0x28:
        strOut = s_strDefaultLand;
        break;
    case 0x1b:
        strOut = s_strDefaultLandRotation;
        break;
    case 0x1c:
    case 0x1d:
    case 0x1f:
    case 0x35:
    case 0x3a:
    case 0x3f:
    case 0x48:
        strOut = s_strNoChangeCube;
        break;
    case 0x2d:
        strOut = s_strBuildingCount;
        break;
    default:
        return 0;
    }
    return 1;
}

// @0x1410d5d80
CStringW Unk_Service6100017::FUN_1410d5d80(int nMessage)
{
    int nId = 0x691;
    switch (nMessage) {
    case 0: nId = 0x691; break;
    case 1: nId = 0; break;
    case 2: nId = 0x692; break;
    case 3: nId = 0x693; break;
    case 4: nId = 0x694; break;
    case 5: nId = 0x695; break;
    case 6: nId = 0x696; break;
    case 7: nId = 0x697; break;
    case 8: nId = 0x698; break;
    case 9: nId = 0x699; break;
    case 10: nId = 0x69a; break;
    case 11: nId = 0x69b; break;
    case 12: nId = 0x69c; break;
    case 13: nId = 0x69d; break;
    case 14: nId = 0x69e; break;
    case 15: nId = 0x69f; break;
    case 16: nId = 0x6a0; break;
    case 17: nId = 0x6a1; break;
    case 18: nId = 0x6a2; break;
    case 19: nId = 0x6a3; break;
    case 20: nId = 0x6a4; break;
    case 21: nId = 0x6a5; break;
    case 22: nId = 0x6a6; break;
    case 23: nId = 0x6a7; break;
    case 24: nId = 0x6a8; break;
    case 25: nId = 0x6a9; break;
    case 26: nId = 0x6aa; break;
    case 27: nId = 0x6ab; break;
    case 28: nId = 0x6ac; break;
    case 29: nId = 0x6ad; break;
    case 30: nId = 0x6ae; break;
    case 31: nId = 0x6af; break;
    case 32: nId = 0x6b0; break;
    case 33: nId = 0x6b1; break;
    case 35: nId = 0x6b2; break;
    case 36: nId = 0x6b3; break;
    case 37: nId = 0x6b4; break;
    case 38: nId = 0x6b5; break;
    case 39: nId = 0x6b6; break;
    case 40: nId = 0x6b7; break;
    case 41: nId = 0x6b8; break;
    case 42: nId = 0x6b9; break;
    case 43: nId = 0x6ba; break;
    case 44: nId = 0x6bb; break;
    case 45: nId = 0x6bc; break;
    case 46: nId = 0x6bd; break;
    case 47: nId = 0x6be; break;
    case 48: nId = 0x6bf; break;
    case 49: nId = 0x6c0; break;
    case 50: nId = 0x6c1; break;
    case 51: nId = 0x6c2; break;
    case 52: nId = 0x6c3; break;
    case 53: nId = 0x6c4; break;
    case 54: nId = 0x6c5; break;
    case 55: nId = 0x6c6; break;
    case 56: nId = 0x6c2; break;
    case 57: nId = 0x6ca; break;
    case 58: nId = 0x6cb; break;
    case 59: nId = 0x6cc; break;
    case 60: nId = 0x6c7; break;
    case 61: nId = 0x6cd; break;
    case 62: nId = 0x6ce; break;
    case 63: nId = 0x6cf; break;
    case 64: nId = 0x6d0; break;
    case 65: nId = 0x6d1; break;
    case 66: nId = 0x6d2; break;
    case 67: nId = 0x6d3; break;
    case 68: nId = 0x6d4; break;
    case 69: nId = 0x6d5; break;
    case 70: nId = 0x6d6; break;
    case 71: nId = 0x6d7; break;
    case 73: nId = 0x6d8; break;
    case 72: nId = 0x6d9; break;
    case 74: nId = 0x6da; break;
    case 75: nId = 0x6db; break;
    case 99:
    {
        CStringW strKey(L"s_ugcmap_installnpc_count");
        return GetStringCommonByKey(strKey);
    }
    case 76: nId = 0x6dc; break;
    case 77: nId = 0x6dd; break;
    case 78: nId = 0x6de; break;
    case 79: nId = 0x6e0; break;
    case 80: nId = 0x6e1; break;
    case 81: nId = 0x6df; break;
    case 83: nId = 0xcaa; break;
    case 84: nId = 0x6e3; break;
    case 85: nId = 0x6e4; break;
    case 86: nId = 0x6e5; break;
    case 87: nId = 0xcab; break;
    case 88: nId = 0xcac; break;
    case 89: nId = 0xcad; break;
    case 90: nId = 99; break;
    case 91: nId = 100; break;
    case 92: nId = 0x65; break;
    case 93: nId = 0x66; break;
    case 101: nId = 0x67; break;
    case 103: nId = 0x68; break;
    case 104: nId = 0x69; break;
    case 105: nId = 0x6a; break;
    case 106: nId = 0x6b; break;
    case 107: nId = 0x6c; break;
    case 108: nId = 0x6d; break;
    case 109: nId = 0x6e; break;
    case 110: nId = 0x6f; break;
    case 111: nId = 0x70; break;
    case 94: nId = 0xcae; break;
    case 95: nId = 0xcaf; break;
    case 96: nId = 0xcb0; break;
    case 97: nId = 0xcb1; break;
    case 98: nId = 0xcb5; break;
    case 100: nId = 0xcb7; break;
    case 102: nId = 0x6ea; break;
    case 112:
        nId = 0x6c2;
        break;
    default:
        nId = 0x6c2;
        break;
    }
    return GetStringCommon(nId);
}

// @0x1410d6590
void Unk_MyPCHousingSvc::FUN_1410d6590(int nMessage)
{
    if (nMessage == 0x22) {
        FUN_141add1f0(FUN_1403ed2b0());
    }
    else {
        if (nMessage == 1)
            return;
        CString strKey;
        if (FUN_1410d5bc0(nMessage, strKey) == 1) {
            CString strNone("");
            FUN_141276180(strKey, strNone);
        }
        CStringW strText = reinterpret_cast<Unk_Service6100017*>(this)->FUN_1410d5d80(nMessage);
        if (!strText.IsEmpty()) {
            FUN_1412751f0(strText, 1, 1);
        }
    }
}

// a byte-sized enum (value of an int-keyed map; the name only fixes the COMDAT sort position, before Unk_CMISKindA)
enum Unk_CMISByteKind : unsigned char { Unk_CMISByteKind_None };

// rvalue-key pair<const K, V> built piecewise (the outer constructors the allocator's construct calls)
template <class K, class V> void Unk_CMISPiecewiseRv()
{
    K k = K();
    std::pair<const K, V> pr(std::piecewise_construct, std::tuple<K&&>(std::move(k)), std::tuple<>());
    (void)pr;
}

void Unk_CMISDriveHead()
{
    Unk_CMISPiecewiseRv<int, Unk_CMISCell>();
    Unk_CMISPiecewiseRv<int, MS2Ptr<FittingDollData> >();
    Unk_CMISPiecewiseRv<int, Unk_CMISStdMapCube>();
    Unk_CMISPiecewiseRv<int, egf::EntityID>();
    Unk_CMISPiecewiseRv<int, Unk_CMISByteKind>();
    Unk_CMISPiecewiseRv<int, Unk_CMISKindA>();
    Unk_CMISPiecewiseRv<unsigned int, int>();
    Unk_CMISPiecewiseRv<unsigned int, MS2SvrPtr<CUGCMapSetItemInfo> >();
    Unk_CMISPiecewiseRv<std::pair<int, int>, MS2Ptr<SaleStateData> >();
    Unk_CMISPiecewiseRv<Unk_CMISKindB, int>();
    Unk_CMISPiecewiseRv<Unk_CMISKindB, unsigned char>();
    efd::vector<int> v;
    (void)v;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cac290-0x142cac3b0 .text$yd
