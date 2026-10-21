// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Column height index object.
// MS2-FUNCTIONAL: seven engine-map helpers have conflicting global STL bindings;
// their emitted bodies and signed 32-bit keys were reviewed against the executable.
// MS2-UNIT: client\ms2\cubemapinformationservice.cpp#1
// MS2-RANGE: 0x1410b2510-0x1410b4e80 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$_Insert_hint@AEAU?$pair@$$CBHH@std@@PEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHH@std@@@efd@@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@1@AEAU?$pair@$$CBHH@1@PEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@1@@Z 0x1410b2e00 ; unique
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBHH@std@@PEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHH@std@@@efd@@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBHH@1@PEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@1@@Z 0x1410b3a40 ; prop
// MS2-PIN: ??$_Try_emplace@AEBH$$V@?$map@HHU?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHH@std@@@efd@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x1410b3f00 ; unique
// MS2-PIN: ??A?$map@HHU?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHH@std@@@efd@@@std@@QEAAAEAHAEBH@Z 0x1410b42c0 ; unique
// MS2-PIN: ?get@?$MS2Ptr@VUnk_WsB_Vibrator@@@@QEBAPEAVUnk_WsB_Vibrator@@XZ 0x1410b4300 ; unique
// MS2-PIN: ??C?$MS2Ptr@VUnk_WsB_Vibrator@@@@QEBAPEAVUnk_WsB_Vibrator@@XZ 0x1410b4310 ; unique
// MS2-PIN: ?Reference@?$MS2Ptr@VUnk_WsB_Vibrator@@@@CAXPEAVUnk_WsB_Vibrator@@@Z 0x1410b4340 ; prop
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHH@std@@@efd@@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x1410b4440 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@$00@2@$00@std@@QEAAAEAU?$less@H@2@XZ 0x1410b4600 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@$00@2@$00@std@@QEBAAEBU?$less@H@2@XZ 0x1410b4610 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHH@std@@@efd@@$0A@@std@@@std@@QEAAAEAU?$less@H@2@XZ 0x1410b46e0 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHH@std@@@efd@@$0A@@std@@@std@@QEBAAEBU?$less@H@2@XZ 0x1410b4700 ; prop
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VUnk_WsB_Vibrator@@@@AEAAXPEAX@Z 0x1410b47d0 ; unique
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHH@std@@@efd@@$0A@@std@@@std@@QEBA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@2@AEBH@Z 0x1410b4ac0 ; prop
// MS2-PIN: ?find@?$map@HHU?$less@H@std@@@efd@@QEBA_NAEBHAEAH@Z 0x1410b4ba0 ; unique
// MS2-PINS-END tplpin

#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\cubemapinformationservice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "cubemapinformationservice_1.h"
#include "ms2/placeholder/cube.h"
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wregister" // Scaleform 4.x headers use the C++14 keyword.
#endif
#include "worldservice.h"
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

class CubeMapInformationService;
const void* FUN_1413f9850();
CubeMapInformationService* FUN_1401cd070(const void*);
Cube* FUN_1410b8a60(CubeMapInformationService*,Unk_Int3);
void* FUN_1403ed280();
void FUN_1411a7db0(void*);
WorldService* FUN_1403ed2d0();
int FUN_1411cd550(Unk_WsB_Vibrator*);
Unk_Int3* FUN_1408a85a0(Unk_Int3*,int,int,int);

// The shared WorldService declaration uses this handle spelling. Its per-type
// ownership helpers are instantiated first in this object.
template<> void MS2Ptr<Unk_WsB_Vibrator>::Release();
template<> void MS2Ptr<Unk_WsB_Vibrator>::ReleaseImpl(void*);
template<> void MS2Ptr<Unk_WsB_Vibrator>::Reference(Unk_WsB_Vibrator*);
template<> inline MS2Ptr<Unk_WsB_Vibrator>::~MS2Ptr() { Release(); }
template<> inline Unk_WsB_Vibrator* MS2Ptr<Unk_WsB_Vibrator>::get()const { return m_p; }
template<> inline Unk_WsB_Vibrator* MS2Ptr<Unk_WsB_Vibrator>::operator->()const { return m_p; }
template<> inline void MS2Ptr<Unk_WsB_Vibrator>::Reference(Unk_WsB_Vibrator* p) {
    reinterpret_cast<Unk_PayloadRef*>(p)->FUN_14015b020();
}
template<> inline void MS2Ptr<Unk_WsB_Vibrator>::Release() {
    if(m_p) { ReleaseImpl(0); m_p=0; }
}
template<> inline void MS2Ptr<Unk_WsB_Vibrator>::ReleaseImpl(void*) {
    if(reinterpret_cast<Unk_PayloadRef*>(m_p)->FUN_140159bc0()==0) {
        Reference(m_p);
        reinterpret_cast<Unk_PayloadRef*>(m_p)->FUN_140159ba0();
    }
}
// @0x1410b27c0
inline CubeMapInformationService* GetCubeMapService() { return FUN_1401cd070(FUN_1413f9850()); }

// @0x1410b2510
void Unk_CubeHeightIndex::FUN_1410b2510(int x,int y,int z) {
    int key=Key(x,y);
    int oldHeight=INT_MIN;
    m_heights.find(key,oldHeight);
    if(oldHeight<z) m_heights[key]=z;
    FUN_1411a7db0(FUN_1403ed280());
}
MS2_REPLACE_METHOD(0x1410b2510, Unk_CubeHeightIndex, FUN_1410b2510, 123, 0xd1ba07bc);
// MS2-FUNCTIONAL: ID argument register transfer differs; calls and control flow verified.
// @0x1410b25a0
void Unk_CubeHeightIndex::FUN_1410b25a0(int x,int y,int z) {
    int key=Key(x,y);
    int oldHeight=INT_MIN;
    m_heights.find(key,oldHeight);
    if(oldHeight>z) return;
    CubeMapInformationService* service=GetCubeMapService();
    int height=z;
    while(--height>0) {
        Unk_Int3 position; FUN_1408a85a0(&position,x,y,height);
        Cube* cube=FUN_1410b8a60(service,position);
        if(cube!=0) {
            if((egf::Entity*)cube->entity!=0) {
                unsigned __int64 id=cube->entity->GetEntityIDValue();
                MS2Ptr<Unk_WsB_Vibrator> vibrator=FUN_1403ed2d0()->FUN_141bc8f60_value(id);
                if(vibrator.get()!=0) {
                    if(FUN_1411cd550(vibrator.operator->())!=0) continue;
                }
            }
            break;
        }
    }
    m_heights[key]=height;
    FUN_1411a7db0(FUN_1403ed280());
}
MS2_REPLACE_METHOD(0x1410b25a0, Unk_CubeHeightIndex, FUN_1410b25a0, 440, 0xff7f5236);
// @0x1410b2760
void Unk_CubeHeightIndex::Clear() { m_heights.clear(); }
MS2_REPLACE_METHOD(0x1410b2760, Unk_CubeHeightIndex, Clear, 27, 0xfadc04ac);
MS2_EMIT_CRT_MEMMOVE_S();

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE(0x1410b27c0, GetCubeMapService, 22, 0xB397CB61);

