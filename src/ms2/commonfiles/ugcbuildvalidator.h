// ugcbuildvalidator.h - CUGCBuildValidator (abstract) and CUGCBuildValidatorCli (RTTI names): validates one UGC cube
// placement (a point in the cube grid, the item being placed, the rotation/mode) step by step. Each virtual check
// stores an error code in *pErr and returns 0 on failure. Header name assumed; slot names are vfunc_<slot>, the
// error code each slot reports is noted next to it. The Cli class adds the client rules (cube service at +0x40).
#pragma once
#include <afx.h>
#include <efd/SmartPointer.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cube.h"
#include "ms2/placeholder/cubeiteminfo.h"
#include "ms2/commonfiles/ugcmappackageinfo.h"

class Unk_Service6100017;

// Cube grid point: Unk_Int3 whose default constructor zeroes it (0x1408850a0).
struct Unk_CubePoint : public Unk_Int3
{
    // @0x1408850a0
    Unk_CubePoint() { x = 0; y = 0; z = 0; }
};

class CUGCBuildValidator
{
public:
    CUGCBuildValidator(Unk_CubePoint point, CubeItemInfo* pItem, int nMode);   // 0x1408806b0
    virtual ~CUGCBuildValidator();                                              // 0x140880750
    virtual int vfunc_1(int nMode, unsigned* pErr);                            // sets m_nMode, checks 0x2a / 3
    virtual int vfunc_2(unsigned* pErr) = 0;
    virtual int vfunc_3(unsigned* pErr) = 0;
    virtual int vfunc_4(unsigned* pErr) = 0;
    virtual int vfunc_5(unsigned* pErr) = 0;
    virtual int vfunc_6(unsigned* pErr) = 0;
    virtual int vfunc_7(unsigned* pErr) = 0;
    virtual int vfunc_8(unsigned* pErr) = 0;
    virtual int vfunc_9(unsigned* pErr) = 0;
    virtual int vfunc_10(unsigned* pErr) = 0;
    virtual int vfunc_11(unsigned* pErr) = 0;
    virtual int vfunc_12(unsigned* pErr) = 0;
    virtual int vfunc_13(unsigned* pErr) = 0;
    virtual int vfunc_14(unsigned* pErr) = 0;
    virtual int vfunc_15(unsigned* pErr) = 0;
    virtual int vfunc_16(unsigned* pErr) = 0;
    virtual int vfunc_17(unsigned* pErr) = 0;
    virtual int vfunc_18(unsigned* pErr) = 0;
    virtual int vfunc_19(unsigned* pErr) = 0;
    virtual int vfunc_20(unsigned* pErr) = 0;
    virtual int vfunc_21(unsigned* pErr) = 0;
    virtual int vfunc_22(unsigned* pErr) = 0;
    virtual int vfunc_23(unsigned* pErr) = 0;
    virtual int vfunc_24(unsigned* pErr) = 0;
    virtual int vfunc_25(unsigned* pErr) = 0;
    virtual int vfunc_26(unsigned* pErr) = 0;
    virtual int vfunc_27(unsigned* pErr) = 0;
    virtual int vfunc_28(unsigned* pErr) = 0;
    virtual int vfunc_29(unsigned* pErr) = 0;
    virtual int vfunc_30(unsigned* pErr) = 0;
    virtual int vfunc_31(unsigned* pErr) = 0;
    virtual int vfunc_32(unsigned* pErr);                                       // 0x140880800 error 0x62
    virtual Cube* vfunc_33() = 0;                                               // the cube at the point
    virtual Cube* vfunc_34() = 0;                                               // the cube below / the neighbour
    virtual int vfunc_35() = 0;
    virtual int vfunc_36(unsigned* pErr);                                       // 0x140880a00 build (mode 1)
    virtual int vfunc_37(unsigned* pErr);                                       // 0x140880c50 mode 3
    virtual int vfunc_38(unsigned* pErr);                                       // 0x140880e30 mode 2
    virtual int vfunc_39(unsigned* pErr);                                       // 0x140881050 mode 2 (move)
    virtual int vfunc_40(unsigned* pErr);                                       // 0x140881240 mode 4
    virtual int vfunc_41(unsigned* pErr);                                       // 0x140881350 mode 5
    virtual int vfunc_42(unsigned* pErr);                                       // 0x140881440 mode 6

    int FUN_140880890();                    // the item must exist unless mode is 4 or 5
    int FUN_1408808d0();                    // loads the item data of the item; fails when it has none
    int FUN_140880990();                    // the neighbour cube exists and has a non-zero +0x68
    int GetMode();                    // m_nMode

    Unk_CubePoint m_point;                  // +0x08
    Cube* m_pCube;                          // +0x18 filled by vfunc_36 from vfunc_34
    CubeItemInfo* m_pItem;                  // +0x20 the item being placed
    MS2Ptr<CItemData> m_itemData;           // +0x28
    int m_nDirection;                       // +0x38
    int m_nMode;                            // +0x3c
};
MS2_CHECK_SIZE(CUGCBuildValidator, 0x40);
MS2_CHECK_OFFSET(CUGCBuildValidator, m_point, 0x08);
MS2_CHECK_OFFSET(CUGCBuildValidator, m_itemData, 0x28);
MS2_CHECK_OFFSET(CUGCBuildValidator, m_nMode, 0x3c);

class CUGCBuildValidatorCli : public CUGCBuildValidator
{
public:
    CUGCBuildValidatorCli(Unk_CubePoint point, CubeItemInfo* pItem);                // 0x140881540
    CUGCBuildValidatorCli(Unk_CubePoint point, CubeItemInfo* pItem, int nDirection);   // 0x1408815e0
    virtual ~CUGCBuildValidatorCli();                                               // 0x140881690

    virtual int vfunc_1(int nMode, unsigned* pErr);
    virtual int vfunc_2(unsigned* pErr);
    virtual int vfunc_3(unsigned* pErr);
    virtual int vfunc_4(unsigned* pErr);
    virtual int vfunc_5(unsigned* pErr);
    virtual int vfunc_6(unsigned* pErr);
    virtual int vfunc_7(unsigned* pErr);
    virtual int vfunc_8(unsigned* pErr);
    virtual int vfunc_9(unsigned* pErr);
    virtual int vfunc_10(unsigned* pErr);
    virtual int vfunc_11(unsigned* pErr);
    virtual int vfunc_12(unsigned* pErr);
    virtual int vfunc_13(unsigned* pErr);
    virtual int vfunc_14(unsigned* pErr);
    virtual int vfunc_15(unsigned* pErr);
    virtual int vfunc_16(unsigned* pErr);
    virtual int vfunc_17(unsigned* pErr);
    virtual int vfunc_18(unsigned* pErr);
    virtual int vfunc_19(unsigned* pErr);
    virtual int vfunc_20(unsigned* pErr);
    virtual int vfunc_21(unsigned* pErr);
    virtual int vfunc_22(unsigned* pErr);
    virtual int vfunc_23(unsigned* pErr);
    virtual int vfunc_24(unsigned* pErr);
    virtual int vfunc_25(unsigned* pErr);
    virtual int vfunc_26(unsigned* pErr);
    virtual int vfunc_27(unsigned* pErr);
    virtual int vfunc_28(unsigned* pErr);
    virtual int vfunc_29(unsigned* pErr);
    virtual int vfunc_30(unsigned* pErr);
    virtual int vfunc_31(unsigned* pErr);
    virtual Cube* vfunc_33();
    virtual Cube* vfunc_34();
    virtual int vfunc_35();

    efd::SmartPointer<Unk_Service6100017> m_pCubeService;       // +0x40 the cube service (class id 0x06100017)
};
MS2_CHECK_SIZE(CUGCBuildValidatorCli, 0x48);
MS2_CHECK_OFFSET(CUGCBuildValidatorCli, m_pCubeService, 0x40);
