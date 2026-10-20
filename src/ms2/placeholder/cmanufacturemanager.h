// cmanufacturemanager.h - PLACEHOLDER for CManufactureManager (RTTI .?AVCManufactureManager@@, 0x38 bytes). NOT an original header.
// Bases: TSingleton<CManufactureManager> at +0x0.
// Keeps the maid manufacture (crafting) records of the user keyed by their id (CManufacture +0x20), sends the
// manufacture requests (opcode 0x68) and picks the maid's speech text. CGameApp::InitInstance (?\ms2.cpp) creates it.
// Implemented in ?\manufacturemanager.cpp (0x140d50010). Method names are invented.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/commonfiles/manufacture.h"

class CInPacket;
class UIManufactureDialog;
class Unk_MfNpc;

class CManufactureManager : public TSingleton<CManufactureManager>
{
public:
    typedef ATL::CRBMap<unsigned __int64, MS2Ptr<CManufacture> > ManufactureMap;

    CManufactureManager();                                  // 0x140d50010
    virtual ~CManufactureManager();
    void OnPacket(CInPacket* pPacket);                      // 0x140d500b0: modes 0..2 add records, 3 remove, 4..0xb dialog updates
    int SendRequest4(unsigned __int64 nId, int nRecipeId, int* pnResult);   // 0x140d509b0: checks the recipe, sends mode 4
    int SendRequest5(unsigned __int64 nId, int nRecipeId, int* pnResult);   // 0x140d50dd0
    int SendRequest6(unsigned __int64 nId, int* pnResult);  // 0x140d50e70: also checks the meso cost
    int SendRequest7(unsigned __int64 nId, int* pnResult); // 0x140d50fb0
    int SendRequest8(unsigned __int64 nId, int* pnResult); // 0x140d510a0
    int SendRequest9(unsigned __int64 nId, int* pnResult); // 0x140d51190
    int SendRequest10(unsigned __int64 nId, int* pnResult);    // 0x140d51280
    int Lookup(unsigned __int64 nId, MS2Ptr<CManufacture>& spOut);     // 0x140d51370
    bool HasManufacture();                                  // 0x140d513c0
    CStringW GetMaidText(int nType, Unk_MfNpc* pNpc);       // 0x140d51400: speech text of the maid npc (plays its sound)
    static UIManufactureDialog* GetManufactureDialog(int nUiId);    // 0x140d51900
    static class UIManufactureStatus* GetManufactureStatus(int nUiId);  // 0x140d519a0
private:
    MS2_LAYOUT_FRIEND;
    ManufactureMap m_mapManufacture;                        // +0x8 (CRBMap with block size 10)
};
MS2_CHECK_SIZE(CManufactureManager, 0x38);
MS2_CHECK_OFFSET(CManufactureManager, m_mapManufacture, 8);
