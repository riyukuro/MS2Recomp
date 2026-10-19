// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The "Swoosh" effect: param + runtime effect (a ribbon that
// trails two nodes of the target). See swoosheffectparam.h.
// MS2-UNIT: ?\swoosheffectparam.cpp
// MS2-RANGE: 0x14010d290-0x14010d320 .text$di
// MS2-RANGE: 0x14181cf50-0x141821bf0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@V?$_Vector_val@U?$_Simple_types@UUnk_StreamPoint@@@std@@@std@@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x14181fd20 ; unique
// MS2-PIN: ??$_Construct1@UUnk_StreamPoint@@AEBU1@@?$_Normal_allocator_traits@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@SAXU?$integral_constant@_N$0A@@1@AEAV?$CustomAllocator@UUnk_StreamPoint@@@efd@@PEAUUnk_StreamPoint@@AEBU5@@Z 0x14181fd90 ; prop
// MS2-PIN: ??$_Construct1@UUnk_StreamPoint@@U1@@?$_Normal_allocator_traits@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@SAXU?$integral_constant@_N$0A@@1@AEAV?$CustomAllocator@UUnk_StreamPoint@@@efd@@PEAUUnk_StreamPoint@@$$QEAU5@@Z 0x14181fdd0 ; prop
// MS2-PIN: ??$_Destroy1@UUnk_StreamPoint@@@?$_Normal_allocator_traits@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@SAXAEAV?$CustomAllocator@UUnk_StreamPoint@@@efd@@PEAUUnk_StreamPoint@@U?$integral_constant@_N$0A@@1@@Z 0x14181fe10 ; unique
// MS2-PIN: ??$_Destroy_range1@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@YAXPEAUUnk_StreamPoint@@0AEAV?$CustomAllocator@UUnk_StreamPoint@@@efd@@U?$integral_constant@_N$0A@@0@@Z 0x14181fe40 ; unique
// MS2-PIN: ??$_Destroy_range@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@YAXPEAUUnk_StreamPoint@@0AEAV?$CustomAllocator@UUnk_StreamPoint@@@efd@@@Z 0x14181fea0 ; unique
// MS2-PIN: ??$_Emplace_back@UUnk_StreamPoint@@@?$_Uninitialized_backout_al@PEAUUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@QEAAX$$QEAUUnk_StreamPoint@@@Z 0x14181fef0 ; unique
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@AEBUUnk_StreamPoint@@@?$vector@UUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@AEAAXAEBUUnk_StreamPoint@@@Z 0x14181ff50 ; prop
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@UUnk_StreamPoint@@@?$vector@UUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@AEAAX$$QEAUUnk_StreamPoint@@@Z 0x141820010 ; prop
// MS2-PIN: ??$_Emplace_reallocate@AEBUUnk_StreamPoint@@@?$vector@UUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@QEAAPEAUUnk_StreamPoint@@QEAU2@AEBU2@@Z 0x1418200d0 ; prop
// MS2-PIN: ??$_Emplace_reallocate@UUnk_StreamPoint@@@?$vector@UUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@QEAAPEAUUnk_StreamPoint@@QEAU2@$$QEAU2@@Z 0x141820330 ; prop
// MS2-PIN: ??$_Get_unwrapped@UUnk_StreamPoint@@@std@@YAPEAUUnk_StreamPoint@@QEAU1@@Z 0x141820590 ; prop
// MS2-PIN: ??$_Idl_distance@PEAUUnk_StreamPoint@@PEAU1@@std@@YA_JAEBQEAUUnk_StreamPoint@@0@Z 0x1418205e0 ; prop
// MS2-PIN: ??$_Move_unchecked1@PEAUUnk_StreamPoint@@PEAU1@@std@@YAPEAUUnk_StreamPoint@@PEAU1@00U_General_ptr_iterator_tag@0@@Z 0x141820610 ; unique
// MS2-PIN: ??$_Move_unchecked@PEAUUnk_StreamPoint@@PEAU1@@std@@YAPEAUUnk_StreamPoint@@PEAU1@00@Z 0x141820680 ; unique
// MS2-PIN: ??$_Ptr_move_cat@UUnk_StreamPoint@@U1@@std@@YA?AU_General_ptr_iterator_tag@0@AEBQEAUUnk_StreamPoint@@0@Z 0x1418206d0 ; unique
// MS2-PIN: ??$_Unfancy@UUnk_StreamPoint@@@std@@YAPEAUUnk_StreamPoint@@PEAU1@@Z 0x141820720 ; prop
// MS2-PIN: ??$_Uninitialized_move@PEAUUnk_StreamPoint@@PEAU1@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@YAPEAUUnk_StreamPoint@@QEAU1@0PEAU1@AEAV?$CustomAllocator@UUnk_StreamPoint@@@efd@@@Z 0x141820730 ; unique
// MS2-PIN: ??$_Uninitialized_move_al_unchecked@PEAUUnk_StreamPoint@@PEAU1@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@YAPEAUUnk_StreamPoint@@PEAU1@QEAU1@1AEAV?$CustomAllocator@UUnk_StreamPoint@@@efd@@U_General_ptr_iterator_tag@0@U_Unused_parameter@0@@Z 0x141820800 ; unique
// MS2-PIN: ??$addressof@V?$_Vector_val@U?$_Simple_types@UUnk_StreamPoint@@@std@@@std@@@std@@YAPEAV?$_Vector_val@U?$_Simple_types@UUnk_StreamPoint@@@std@@@0@AEAV10@@Z 0x141820890 ; prop
// MS2-PIN: ??$construct@UUnk_StreamPoint@@AEBU1@@?$_Normal_allocator_traits@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@SAXAEAV?$CustomAllocator@UUnk_StreamPoint@@@efd@@PEAUUnk_StreamPoint@@AEBU4@@Z 0x1418208a0 ; prop
// MS2-PIN: ??$construct@UUnk_StreamPoint@@U1@@?$_Normal_allocator_traits@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@SAXAEAV?$CustomAllocator@UUnk_StreamPoint@@@efd@@PEAUUnk_StreamPoint@@$$QEAU4@@Z 0x1418208e0 ; prop
// MS2-PIN: ??$destroy@UUnk_StreamPoint@@@?$_Normal_allocator_traits@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@SAXAEAV?$CustomAllocator@UUnk_StreamPoint@@@efd@@PEAUUnk_StreamPoint@@@Z 0x141820920 ; prop
// MS2-PIN: ??$emplace_back@AEBUUnk_StreamPoint@@@?$vector@UUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@QEAAXAEBUUnk_StreamPoint@@@Z 0x141820950 ; prop
// MS2-PIN: ??$emplace_back@UUnk_StreamPoint@@@?$vector@UUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@QEAAX$$QEAUUnk_StreamPoint@@@Z 0x1418209c0 ; prop
// MS2-PIN: ??$forward@AEBUUnk_StreamPoint@@@std@@YAAEBUUnk_StreamPoint@@AEBU1@@Z 0x141820a30 ; prop
// MS2-PIN: ??$forward@UUnk_StreamPoint@@@std@@YA$$QEAUUnk_StreamPoint@@AEAU1@@Z 0x141820a40 ; prop
// MS2-PIN: ??$move@AEAUUnk_StreamPoint@@@std@@YA$$QEAUUnk_StreamPoint@@AEAU1@@Z 0x141820a50 ; prop
// MS2-PIN: ??0?$CustomAllocator@UUnk_StreamPoint@@@efd@@QEAA@XZ 0x141820a60 ; prop
// MS2-PIN: ??0?$_Uninitialized_backout_al@PEAUUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@QEAA@PEAUUnk_StreamPoint@@AEAV?$CustomAllocator@UUnk_StreamPoint@@@efd@@@Z 0x141820a70 ; unique
// MS2-PIN: ??0?$_Vector_alloc@U?$_Vec_base_types@UUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@@std@@QEAA@XZ 0x141820ab0 ; unique
// MS2-PIN: ??0?$_Vector_val@U?$_Simple_types@UUnk_StreamPoint@@@std@@@std@@QEAA@XZ 0x141820b60 ; unique
// MS2-PIN: ??0?$vector@UUnk_StreamPoint@@@efd@@QEAA@XZ 0x141820ba0 ; unique
// MS2-PIN: ??0?$vector@UUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@QEAA@XZ 0x141820bc0 ; unique
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAUUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@QEAA@XZ 0x141820c20 ; unique
// MS2-PIN: ??1?$_Vector_alloc@U?$_Vec_base_types@UUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@@std@@QEAA@XZ 0x141820c60 ; prop
// MS2-PIN: ??1?$vector@UUnk_StreamPoint@@@efd@@QEAA@XZ 0x141820c80 ; unique
// MS2-PIN: ??A?$vector@UUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@QEAAAEAUUnk_StreamPoint@@_K@Z 0x141820d30 ; unique
// MS2-PIN: ?_Calculate_growth@?$vector@UUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@AEBA_K_K@Z 0x141820fc0 ; unique
// MS2-PIN: ?_Change_array@?$vector@UUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@AEAAXQEAUUnk_StreamPoint@@_K1@Z 0x141821050 ; unique
// MS2-PIN: ?_Destroy@?$vector@UUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@AEAAXPEAUUnk_StreamPoint@@0@Z 0x141821160 ; unique
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@UUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@UUnk_StreamPoint@@@std@@@2@XZ 0x1418211a0 ; prop
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@UUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@UUnk_StreamPoint@@@std@@@2@XZ 0x1418211c0 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@V?$_Vector_val@U?$_Simple_types@UUnk_StreamPoint@@@std@@@std@@$00@std@@QEAAAEAV?$CustomAllocator@UUnk_StreamPoint@@@efd@@XZ 0x1418211e0 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@V?$_Vector_val@U?$_Simple_types@UUnk_StreamPoint@@@std@@@std@@$00@std@@QEBAAEBV?$CustomAllocator@UUnk_StreamPoint@@@efd@@XZ 0x1418211f0 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@V?$_Vector_val@U?$_Simple_types@UUnk_StreamPoint@@@std@@@std@@$00@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@UUnk_StreamPoint@@@std@@@2@XZ 0x141821200 ; prop
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@UUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@@std@@QEAAAEAV?$CustomAllocator@UUnk_StreamPoint@@@efd@@XZ 0x141821220 ; prop
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@UUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@@std@@QEBAAEBV?$CustomAllocator@UUnk_StreamPoint@@@efd@@XZ 0x141821240 ; prop
// MS2-PIN: ?_Has_unused_capacity@?$vector@UUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@AEBA_NXZ 0x141821260 ; unique
// MS2-PIN: ?_Max_size1@?$_Normal_allocator_traits@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@SA_KAEBV?$CustomAllocator@UUnk_StreamPoint@@@efd@@U?$integral_constant@_N$00@2@@Z 0x1418212b0 ; unique
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@UUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@@std@@QEAAAEAPEAUUnk_StreamPoint@@XZ 0x1418212d0 ; prop
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@UUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@@std@@QEBAAEBQEAUUnk_StreamPoint@@XZ 0x1418212f0 ; prop
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@UUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@@std@@QEAAAEAPEAUUnk_StreamPoint@@XZ 0x141821310 ; prop
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@UUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@@std@@QEBAAEBQEAUUnk_StreamPoint@@XZ 0x141821330 ; prop
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@UUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@@std@@QEAAAEAPEAUUnk_StreamPoint@@XZ 0x141821350 ; prop
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@UUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@@std@@QEBAAEBQEAUUnk_StreamPoint@@XZ 0x141821370 ; prop
// MS2-PIN: ?_Orphan_all@?$_Vector_alloc@U?$_Vec_base_types@UUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@@std@@QEAAXXZ 0x141821390 ; unique
// MS2-PIN: ?_Orphan_range@?$vector@UUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@AEBAXPEAUUnk_StreamPoint@@0@Z 0x1418213b0 ; unique
// MS2-PIN: ?_Reallocate_exactly@?$vector@UUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@AEAAX_K@Z 0x1418213c0 ; unique
// MS2-PIN: ?_Release@?$_Uninitialized_backout_al@PEAUUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@QEAAPEAUUnk_StreamPoint@@XZ 0x141821460 ; unique
// MS2-PIN: ?_Tidy@?$vector@UUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@AEAAXXZ 0x141821480 ; unique
// MS2-PIN: ?_Umove@?$vector@UUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@AEAAPEAUUnk_StreamPoint@@PEAU3@00@Z 0x141821550 ; prop
// MS2-PIN: ?_Umove_if_noexcept1@?$vector@UUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@AEAAXPEAUUnk_StreamPoint@@00U?$integral_constant@_N$00@2@@Z 0x141821590 ; prop
// MS2-PIN: ?_Umove_if_noexcept@?$vector@UUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@AEAAXPEAUUnk_StreamPoint@@00@Z 0x1418215d0 ; unique
// MS2-PIN: ?allocate@?$CustomAllocator@UUnk_StreamPoint@@@efd@@QEAAPEAUUnk_StreamPoint@@_KPEBX@Z 0x141821650 ; unique
// MS2-PIN: ?begin@?$vector@UUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@UUnk_StreamPoint@@@std@@@std@@@2@XZ 0x1418216a0 ; unique
// MS2-PIN: ?capacity@?$vector@UUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@QEBA_KXZ 0x141821700 ; prop
// MS2-PIN: ?clear@?$vector@UUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@QEAAXXZ 0x141821750 ; unique
// MS2-PIN: ?deallocate@?$CustomAllocator@UUnk_StreamPoint@@@efd@@QEAAXPEAUUnk_StreamPoint@@_K@Z 0x141821830 ; unique
// MS2-PIN: ?erase@?$vector@UUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@UUnk_StreamPoint@@@std@@@std@@@2@V?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@UUnk_StreamPoint@@@std@@@std@@@2@@Z 0x141821890 ; unique
// MS2-PIN: ?max_size@?$CustomAllocator@UUnk_StreamPoint@@@efd@@QEBA_KXZ 0x141821950 ; unique
// MS2-PIN: ?max_size@?$_Normal_allocator_traits@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@SA_KAEBV?$CustomAllocator@UUnk_StreamPoint@@@efd@@@Z 0x141821960 ; unique
// MS2-PIN: ?max_size@?$vector@UUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@QEBA_KXZ 0x141821980 ; unique
// MS2-PIN: ?push_back@?$vector@UUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@QEAAX$$QEAUUnk_StreamPoint@@@Z 0x1418219d0 ; unique
// MS2-PIN: ?push_back@?$vector@UUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@QEAAXAEBUUnk_StreamPoint@@@Z 0x141821a00 ; unique
// MS2-PIN: ?reserve@?$vector@UUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@QEAAX_K@Z 0x141821a30 ; unique
// MS2-PIN: ?size@?$vector@UUnk_StreamPoint@@V?$CustomAllocator@UUnk_StreamPoint@@@efd@@@std@@QEBA_KXZ 0x141821a80 ; prop
// MS2-PINS-END tplpin
#ifndef NOMINMAX
#define NOMINMAX
#endif
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\swoosheffectparam.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "swoosheffectparam.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/postprocesseffect.h"      // Unk_PPSmartC
#include <algorithm>
#include <new>
#include <vector>
#include <efd/MemoryDefines.h>
#include <NiNode.h>
#include <NiMesh.h>
#include <NiFixedString.h>
#include <NiCommonSemantics.h>
#include <NiColor.h>
#include <NiPoint2.h>
#include <NiPoint3.h>
#include <NiTimeController.h>
#include <NiAlphaProperty.h>
#include <NiVertexColorProperty.h>
#include <NiFogProperty.h>
#include <NiWireframeProperty.h>
#include <NiStencilProperty.h>
#include <NiZBufferProperty.h>
#include <NiTexturingProperty.h>
#include <NiMaterialProperty.h>
#include <d3dx9math.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit types and callees (bound to the exe by their FUN_<va> names / symbols) ----
int FUN_1408733e0(Unk_140165cf0* pNode, const char* pszName, CString& strOut);
int FUN_140873360(Unk_140165cf0* pNode, const char* pszName, float& fOut);
int FUN_1408731e0(Unk_140165cf0* pNode, const char* pszName, int& nOut);
const char* FUN_14086f4b0(Unk_140165cf0* pNode, const char* pszName);
int FUN_140ad02f0(int nValue, int nLimit);                          // upper clamp
bool FUN_14028d470(float a, float b);                               // nearly equal
const int& FUN_1404eb7e0(const int& a, const int& b);               // max
class Unk_GameClock { public: double FUN_141473280(); float FUN_141473210(); };
Unk_GameClock* FUN_14086d260();
void* FUN_1409849b0(void* pHandle);                                 // handle -> node pointer
void* FUN_14098d8d0(const void* pRtti, void* pObj);                 // dynamic cast through an NiRTTI
void* FUN_14098d0f0(void* pHandle);                                 // handle -> object
const Unk_StreamPoint& FUN_140947900(void* pNode);                  // world translate
bool FUN_14098dad0(void* pNode);                                    // node is app-culled
void FUN_141d16040(void* pNode, float fTime, bool bUpdateControllers);    // NiAVObject::Update
void FUN_14097fad0(NiPoint3* pDst, const Unk_StreamPoint* pSrc);    // NiPoint3 assignment
bool FUN_1409a7f70(NiAVObjectPtr* pPtr, int nNull);                 // pointer == NULL?
void FUN_140a0b2a0(NiAVObject* pObj);                               // detach from the parent
void FUN_140a0b300(NiAVObject* pObj, bool bCulled);                 // SetAppCulled
bool FUN_14109a9a0(const NiRTTI* pRtti, void* pObj);                // object is of the type
void FUN_140980200(NiAVObject* pObj, NiProperty* pProp);            // NiAVObject::AttachProperty
void FUN_140980880(NiTexturingProperty* pProp, void* pTexture);     // SetBaseTexture
void FUN_1409807b0(NiTexturingProperty* pProp, int n);
void FUN_1409805c0(NiTexturingProperty* pProp, int n);
void FUN_1409806e0(NiTexturingProperty* pProp, int n);
void FUN_140980560(NiAlphaProperty* pProp, bool b);                 // SetAlphaBlending
void FUN_140980f60(NiAlphaProperty* pProp, int nMode);              // source blend mode
void FUN_140980af0(NiAlphaProperty* pProp, int nMode);              // destination blend mode
void FUN_140980f20(NiVertexColorProperty* pProp, int n);
void FUN_140980e60(NiVertexColorProperty* pProp, int n);
void FUN_1409a9b90(NiFogProperty* pProp, int n);
void FUN_140981100(NiZBufferProperty* pProp, int n);
void FUN_140a0b6c0(NiWireframeProperty* pProp, bool b);             // SetWireframe
void FUN_1415672e0(NiAVObject* pObj, int n);
// Time controller helpers.
NiTimeController* FUN_14098dc80(NiObjectNET* pObj);                 // first controller
NiTimeController* FUN_14098de40(NiTimeController* pCtrl);           // next controller
void FUN_1416f18b0(NiTimeController* pCtrl, int n);
float FUN_1415467d0(NiTimeController* pCtrl);                       // start time
void FUN_141d18aa0(NiObjectNET* pObj, NiTimeController* pCtrl);     // NiObjectNET::SetControllers
unsigned short FUN_14106bc50(NiObjectNET* pObj);                    // extra data count
NiExtraData* FUN_14106bc30(NiObjectNET* pObj, unsigned short i);    // extra data by index
// Property list of an NiMesh (hash/list walk with a position cursor).
class Unk_PropList;
Unk_PropList* FUN_14127cc40(NiMesh* pMesh);
void* FUN_14098ddb0(Unk_PropList* pList);                           // head position
void* FUN_14098de00(Unk_PropList* pList, void** ppPos);             // slot at the position, advances it
NiProperty* FUN_140993f00(void* pSlot);                             // slot -> property
void* FUN_140166440();                                              // logger singleton
void FUN_140b850d0(void* pLog, int nA, int nB, const wchar_t* pszFormat, const char*& pszArg, CString* pstrArg);
CString FUN_140cc2ba0(const CString& strDir, const CString& strName);

// Depth-first walker over a scene graph (0x38 bytes; unrecovered class).
class Unk_SceneWalker
{
public:
    Unk_SceneWalker(NiObject* pkRoot);              // 0x14098cb80
    ~Unk_SceneWalker();                             // 0x14098cf00
    NiAVObject* Next(bool bDescend);                // 0x14098e0d0
private:
    void* m_pad_00; void* m_pad_08; void* m_pad_10; void* m_pad_18; void* m_pad_20; void* m_pad_28; void* m_pad_30;
};
MS2_CHECK_SIZE(Unk_SceneWalker, 0x38);

// The resource manager (singleton, instance pointer at 0x143ab5bc8): model / texture cache by path.
class Unk_ResourceMgr
{
public:
    Unk_PPSmartC FUN_141552f90(CString strPath, int nFlags);                    // texture load
    NiAVObjectPtr FUN_141551ea0(CString strPath, bool bA, int nB, int nC, int nD);   // model load
    bool FUN_141551db0(CString strPath);                                        // model is available
    void FUN_1415525d0(CString strPath, int nA, int nB);                        // preload
};
extern Unk_ResourceMgr* DAT_143ab5bc8;
Unk_ResourceMgr* FUN_140a0afd0();
class Unk_ModelCache { public: void FUN_141210ac0(CString strPath); };           // release by path
Unk_ModelCache* FUN_140ab7a10();

// The effect manager (singleton 0x1403ed280): scene root, quality level.
class Unk_EffectMgr
{
public:
    void* FUN_1411a6b10();                          // scene root
    unsigned FUN_1411a88c0();                       // quality level (1..3)
    char m_pad_08[0x128];
    int m_nTrailMode;                               // +0x128
};
Unk_EffectMgr* FUN_1403ed280();

// Scene nodes of the effect system. EffectNode (400 bytes) carries the effect-space point; SeparateNode (0x138) follows
// only the selected parts of its parent's transform.
class Unk_EffectNode : public NiNode
{
public:
    Unk_EffectNode(int nA, int nB);                                 // 0x1411a34b0
    char m_pad_node[400 - sizeof(NiNode)];
};
MS2_CHECK_SIZE(Unk_EffectNode, 400);
class Unk_SeparateNode : public NiNode
{
public:
    Unk_SeparateNode(unsigned char nX, unsigned char nY, unsigned char nZ);   // 0x141751380
    char m_pad_node[0x138 - sizeof(NiNode)];
};
MS2_CHECK_SIZE(Unk_SeparateNode, 0x138);

struct Unk_SwooshTarget { char m_pad_00[0x10]; void* m_hNode; };            // +0x10 handle of the owner's scene node
MS2_CHECK_OFFSET(Unk_SwooshTarget, m_hNode, 0x10);
NiPoint3 FUN_141820e00(const Unk_StreamPoint& p0, const Unk_StreamPoint& p1, const Unk_StreamPoint& p2, const Unk_StreamPoint& p3, float fT);
int FUN_141820fa0(const Unk_EffectMgr* pMgr);

#ifndef MS2_HOOK_DLL
// File statics of this TU (initialised by the .text$di entries).
const NiRTTI CSwooshEffect::ms_RTTI("CSwooshEffect", &CEffect::ms_RTTI);        // @0x14010d290
static CString s_str143aef0b0("skill");                                          // @0x14010d2c0
static CString s_str143aef0a8("stun");                                           // @0x14010d2f0
#else
const NiRTTI CSwooshEffect::ms_RTTI("CSwooshEffect", &CEffect::ms_RTTI);
#endif

// @0x14181cf50
CSwooshEffectParam::CSwooshEffectParam()
    : CEffectParam(7)
{
    m_fLength = 0.1f;
    m_nQuality = 4;
    m_nAlphaMode = 0;
    m_nSampling = 15;
}

// @0x14181d010
void CSwooshEffectParam::vfunc_1(Unk_140165cf0* pNode)
{
    CEffectParam::vfunc_1(pNode);
    FUN_1408733e0(pNode, "texturePath", m_strTexturePath);
    FUN_1408733e0(pNode, "nifPath", m_strNifPath);
    FUN_1408733e0(pNode, "node1", m_strNode1);
    FUN_1408733e0(pNode, "node2", m_strNode2);
    FUN_140873360(pNode, "length", m_fLength);
    FUN_1408731e0(pNode, "quality", m_nQuality);
    FUN_1408731e0(pNode, "sampling", m_nSampling);
    m_nQuality = FUN_140ad02f0(m_nQuality, 4);
    m_nSampling = FUN_140ad02f0(m_nSampling, 0x3c);
    CString strAlpha(FUN_14086f4b0(pNode, "alphaMode"));
    if (strAlpha.GetLength() > 0)
    {
        if (strAlpha.CompareNoCase("SWOOSH") == 0)
            m_nAlphaMode = 0;
        if (strAlpha.CompareNoCase("STANDARD") == 0)
            m_nAlphaMode = 1;
        if (strAlpha.CompareNoCase("ADD") == 0)
            m_nAlphaMode = 2;
    }
}

// MS2-FUNCTIONAL: the exe computes the CString temp pointer before constructing the "Effect" literal; frame differs.
// @0x14181d1e0
bool CSwooshEffectParam::vfunc_3()
{
    if (m_strNifPath.IsEmpty())
        return true;
    CString strDir("Effect");
    return FUN_140a0afd0()->FUN_141551db0(FUN_140cc2ba0(strDir, m_strNifPath));
}

// MS2-FUNCTIONAL: same CString temporary ordering as vfunc_3; frame differs.
// @0x14181d290
void CSwooshEffectParam::vfunc_4()
{
    if (!m_strNifPath.IsEmpty())
    {
        CString strDir("Effect");
        FUN_140ab7a10()->FUN_141210ac0(FUN_140cc2ba0(strDir, m_strNifPath));
    }
}

// MS2-FUNCTIONAL: same CString temporary ordering as vfunc_3; frame differs.
// @0x14181d330
bool CSwooshEffectParam::vfunc_5(int n)
{
    if (!m_strNifPath.IsEmpty())
    {
        if (FUN_140a0afd0() != 0)
        {
            CString strDir("Effect");
            FUN_140a0afd0()->FUN_1415525d0(FUN_140cc2ba0(strDir, m_strNifPath), 0, n);
        }
    }
    return true;
}

// @0x14181d3f0
// Not hooked: constructs CSwooshEffect with its (exe) constructor.
CEffectPtr CSwooshEffectParam::vfunc_6()
{
    return new (efd::MemHint(efd::MemHint::NONE)) CSwooshEffect;
}

// @0x14181d490
CSwooshEffect::CSwooshEffect()
    : m_spRoot(0), m_spUnused38(0), m_spMesh(0), m_spTrail1(0), m_spTrail2(0), m_spTarget(0), m_nUVSets(1),
      m_dLastSample(0), m_fInterval(0.016666668f)
{
    m_kPointsA.reserve(0x28);
    m_kPointsB.reserve(0x28);
    m_kCurveA.reserve(0x28);
    m_kCurveB.reserve(0x28);
}

// MS2-FUNCTIONAL: the vector<Unk_StreamPoint> dtor instance is bound to another unit's copy (beameffect) in symbols.tsv.
// @0x14181d650
CSwooshEffect::~CSwooshEffect()
{
}

// MS2-FUNCTIONAL: 6 KB function: exe is 526 bytes smaller (property setup / temporaries differ).
// @0x14181d760
// Builds the ribbon: an EffectNode root holding a SeparateNode that holds the CMesh strip. The mesh is either a plain
// textured strip (param texturePath) or a copy of the first mesh of the param's nif (its properties, controllers and
// extra data are moved over). The sample rate follows the effect quality level and the frame rate.
bool CSwooshEffect::vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget)
{
    if (!CEffect::vfunc_3(pParam, pTarget))
        return false;
    const CSwooshEffectParam* pSwoosh = static_cast<const CSwooshEffectParam*>(pParam);
    NiNode* pNode = static_cast<NiNode*>(FUN_14098d8d0(&NiNode::ms_RTTI, FUN_1409849b0(&reinterpret_cast<Unk_SwooshTarget*>(pTarget)->m_hNode)));
    if (pNode == 0)
        return false;

    unsigned nSampling = pSwoosh->m_nSampling;
    unsigned nLevel = FUN_1403ed280()->FUN_1411a88c0();
    if (FUN_141820fa0(FUN_1403ed280()) != 0)
    {
        float fFps = FUN_14086d260()->FUN_141473210();
        int nPenalty = 0;
        if (m_unk_18 == 3 || m_unk_18 == 5)
        {
            if (50.0f < fFps)
            {
                if (55.0f < fFps)
                {
                    if (fFps <= 60.0f)
                        nPenalty = 1;
                }
                else
                {
                    nPenalty = 2;
                }
            }
            else
            {
                nPenalty = 3;
            }
            int nReduced = nLevel - nPenalty;
            int nZero = 0;
            nLevel = FUN_1404eb7e0(nZero, nReduced);
        }
    }
    unsigned nRate;
    if (nLevel == 3)
    {
        nRate = std::max(nSampling >> 1, 5u);
    }
    else
    {
        if (nLevel != 2)
            return false;
        nRate = std::max(nSampling >> 2, 5u);
    }
    m_nSegments = std::max(1u, (unsigned)(__int64)(pSwoosh->m_fLength * (float)nRate));
    m_nCurveSamples = m_nSegments * pSwoosh->m_nQuality;
    m_fInterval = 1.0f / (float)nRate;

    NiPointer<Unk_EffectNode> spRoot = new (efd::MemHint(efd::MemHint::NONE)) Unk_EffectNode(0, 0);
    spRoot->SetName("Effect Root");
    FUN_1409f76f0(&m_spRoot, spRoot);
    NiPointer<Unk_SeparateNode> spSeparate = new (efd::MemHint(efd::MemHint::NONE)) Unk_SeparateNode(0, 0, 0);
    FUN_1409f76f0(&m_spTarget, pNode);
    m_strNode1 = pSwoosh->m_strNode1;
    m_strNode2 = pSwoosh->m_strNode2;
    m_spTrail1 = static_cast<NiNode*>(FUN_14098d8d0(&NiNode::ms_RTTI, pNode->GetObjectByName(NiFixedString((const char*)pSwoosh->m_strNode1))));
    m_spTrail2 = static_cast<NiNode*>(FUN_14098d8d0(&NiNode::ms_RTTI, pNode->GetObjectByName(NiFixedString((const char*)pSwoosh->m_strNode2))));

    if (pSwoosh->m_strNifPath.GetLength() < 1)
    {
        int nVerts = m_nCurveSamples << 1;
        int nTris = m_nCurveSamples * 2 + 2;
        m_spMesh = new (efd::MemHint(efd::MemHint::NONE)) CMesh(false, true, m_nUVSets, nTris, nVerts, 0x15);
        m_spMesh->GetMesh()->SetName("SwooshEffect");
        NiPointer<NiTexturingProperty> spTexture = new (efd::MemHint(efd::MemHint::NONE)) NiTexturingProperty;
        FUN_1409807b0(spTexture.operator->(), 0);
        FUN_1409805c0(spTexture.operator->(), 1);
        FUN_1409806e0(spTexture.operator->(), 0);
        {
            CString strDir("Effect/Textures");
            Unk_PPSmartC spImage = FUN_140a0afd0()->FUN_141552f90(CString((const char*)FUN_140cc2ba0(strDir, pSwoosh->m_strTexturePath)), 5);
            FUN_140980880(spTexture.operator->(), spImage.Get());
        }
        FUN_140980200(m_spMesh->GetMesh(), spTexture);

        NiPointer<NiVertexColorProperty> spVertexColor = new (efd::MemHint(efd::MemHint::NONE)) NiVertexColorProperty;
        FUN_140980f20(spVertexColor.operator->(), 1);
        FUN_140980e60(spVertexColor.operator->(), 0);
        FUN_140980200(m_spMesh->GetMesh(), spVertexColor);

        NiPointer<NiAlphaProperty> spAlpha = new (efd::MemHint(efd::MemHint::NONE)) NiAlphaProperty;
        FUN_140980560(spAlpha.operator->(), true);
        int nAlphaMode = pSwoosh->m_nAlphaMode;
        if (nAlphaMode == 0)
        {
            FUN_140980f60(spAlpha.operator->(), 6);
            FUN_140980af0(spAlpha.operator->(), 0);
        }
        else if (nAlphaMode == 1)
        {
            FUN_140980f60(spAlpha.operator->(), 6);
            FUN_140980af0(spAlpha.operator->(), 7);
        }
        else if (nAlphaMode == 2)
        {
            FUN_140980f60(spAlpha.operator->(), 0);
            FUN_140980af0(spAlpha.operator->(), 0);
        }
        FUN_140980200(m_spMesh->GetMesh(), spAlpha);

        NiPointer<NiFogProperty> spFog = new (efd::MemHint(efd::MemHint::NONE)) NiFogProperty;
        FUN_1409a9b90(spFog.operator->(), 0);
        FUN_140980200(m_spMesh->GetMesh(), spFog);

        NiPointer<NiWireframeProperty> spWireframe = new (efd::MemHint(efd::MemHint::NONE)) NiWireframeProperty;
        FUN_140a0b6c0(spWireframe.operator->(), false);
        FUN_140980200(m_spMesh->GetMesh(), spWireframe);

        NiPointer<NiStencilProperty> spStencil = new (efd::MemHint(efd::MemHint::NONE)) NiStencilProperty;
        spStencil->SetDrawMode(NiStencilProperty::DRAW_BOTH);
        FUN_140980200(m_spMesh->GetMesh(), spStencil);

        NiPointer<NiZBufferProperty> spZBuffer = new (efd::MemHint(efd::MemHint::NONE)) NiZBufferProperty;
        FUN_140981100(spZBuffer.operator->(), 0);
        FUN_140980200(m_spMesh->GetMesh(), spZBuffer);
    }
    else
    {
        CString strDir("Effect");
        NiAVObjectPtr spModel = FUN_140a0afd0()->FUN_141551ea0(FUN_140cc2ba0(strDir, pSwoosh->m_strNifPath), false, 5, 0, 0);
        NiMesh* pFound = 0;
        {
            Unk_SceneWalker kWalker(static_cast<NiObject*>(FUN_1409849b0(&spModel)));
            for (;;)
            {
                NiAVObject* pObj = kWalker.Next(true);
                if (pObj == 0)
                    break;
                if (FUN_14109a9a0(&NiMesh::ms_RTTI, pObj))
                {
                    pFound = static_cast<NiMesh*>(pObj);
                    break;
                }
            }
            if (pFound == 0)
                return false;
            int nVerts = m_nCurveSamples << 1;
            int nTris = m_nCurveSamples * 2 + 2;
            m_nUVSets = pFound->GetSemanticCount(NiCommonSemantics::TEXCOORD());
            m_spMesh = new (efd::MemHint(efd::MemHint::NONE)) CMesh(false, true, m_nUVSets, nTris, nVerts, 0x15);
            NiAVObject* pMeshObj = m_spMesh->GetMesh();
            pMeshObj->SetName("SwooshEffect");
            Unk_PropList* pList = FUN_14127cc40(pFound);
            void* pPos = FUN_14098ddb0(pList);
            while (pPos != 0)
            {
                NiProperty* pProp = FUN_140993f00(FUN_14098de00(pList, &pPos));
                bool bMaterial = FUN_14109a9a0(&NiMaterialProperty::ms_RTTI, pProp);
                if (bMaterial || FUN_14109a9a0(&NiTexturingProperty::ms_RTTI, pProp))
                {
                    for (NiTimeController* pCtrl = FUN_14098dc80(pProp); pCtrl != 0; pCtrl = FUN_14098de40(pCtrl))
                    {
                        if (!bMaterial)
                            FUN_1416f18b0(pCtrl, 0);
                        pCtrl->Update(FUN_1415467d0(pCtrl));
                    }
                }
                FUN_140980200(pMeshObj, pProp);
            }
            if (pMeshObj->GetProperty(7) == 0)
            {
                NiPointer<NiStencilProperty> spStencil = new (efd::MemHint(efd::MemHint::NONE)) NiStencilProperty;
                spStencil->SetDrawMode(NiStencilProperty::DRAW_BOTH);
                FUN_140980200(pMeshObj, spStencil);
            }
            if (pMeshObj->GetProperty(0xb) == 0)
            {
                NiPointer<NiZBufferProperty> spZBuffer = new (efd::MemHint(efd::MemHint::NONE)) NiZBufferProperty;
                FUN_140981100(spZBuffer.operator->(), 0);
                FUN_140980200(pMeshObj, spZBuffer);
            }
            unsigned short nExtra = FUN_14106bc50(pFound);
            for (unsigned short i = 0; i < nExtra; ++i)
            {
                NiExtraData* pExtra = FUN_14106bc30(pFound, i);
                m_spMesh->GetMesh()->AddExtraData(pExtra);
            }
            FUN_141d18aa0(m_spMesh->GetMesh(), FUN_14098dc80(pFound));
        }
    }
    m_spMesh->UpdateBound();
    FUN_1415672e0(m_spMesh->GetMesh(), 0);
    spSeparate->AttachChild(m_spMesh->GetMesh(), false);
    static_cast<NiNode*>(FUN_1409475f0(&m_spRoot))->AttachChild(spSeparate, false);
    if (FUN_14028d470(pSwoosh->m_fStartDelay, 0.0f))
        vfunc_4();
    return true;
}

// @0x14181ecd0
bool CSwooshEffect::vfunc_9()
{
    if (CEffect::vfunc_9())
    {
        if ((FUN_1409475d0(&m_spRoot) ? true : false) && FUN_14098dad0(FUN_1409475f0(&m_spRoot)))
            return true;
        if (m_b2e)
            UpdateTrail();
        return true;
    }
    return false;
}

// @0x14181ed70
void CSwooshEffect::vfunc_4()
{
    if (FUN_1409475d0(&m_spTarget) != 0)
    {
        m_b2e = true;
        static_cast<NiNode*>(FUN_1409475f0(&m_spTarget))->AttachChild(static_cast<NiAVObject*>(FUN_1409475d0(&m_spRoot)), true);
        static_cast<NiAVObject*>(FUN_1409475f0(&m_spRoot))->UpdateEffects();
        static_cast<NiAVObject*>(FUN_1409475f0(&m_spRoot))->UpdateProperties();
        FUN_141d16040(FUN_1409475f0(&m_spRoot), (float)FUN_14086d260()->FUN_141473280(), true);
        {
            NiFixedString kName((const char*)m_strNode1);
            m_spTrail1 = static_cast<NiNode*>(FUN_14098d8d0(&NiNode::ms_RTTI, static_cast<NiNode*>(FUN_1409475f0(&m_spTarget))->GetObjectByName(kName)));
        }
        if (FUN_1409a7f70(&m_spTrail1, 0))
        {
            m_b2d = true;
            m_b2e = false;
            const char* pszName = m_strNode1;
            CString* pstrId = &m_str10;
            FUN_140b850d0(FUN_140166440(), 1, 0x133, L"CSwooshEffect can't find TrailNode1 [{0}] effectID:{1}", pszName, pstrId);
        }
        {
            NiFixedString kName((const char*)m_strNode2);
            m_spTrail2 = static_cast<NiNode*>(FUN_14098d8d0(&NiNode::ms_RTTI, static_cast<NiNode*>(FUN_1409475f0(&m_spTarget))->GetObjectByName(kName)));
        }
        if (FUN_1409a7f70(&m_spTrail2, 0))
        {
            m_b2d = true;
            m_b2e = false;
            const char* pszName = m_strNode2;
            CString* pstrId = &m_str10;
            FUN_140b850d0(FUN_140166440(), 1, 0x133, L"CSwooshEffect can't find TrailNode2 [{0}] effectID:{1}", pszName, pstrId);
        }
    }
}

// @0x14181f0c0
void CSwooshEffect::vfunc_7()
{
    FUN_140a0b2a0(static_cast<NiAVObject*>(FUN_1409475d0(&m_spRoot)));
}

// @0x14181f0f0
void CSwooshEffect::vfunc_10(bool bVisible)
{
    FUN_140a0b300(static_cast<NiAVObject*>(FUN_1409475f0(&m_spRoot)), !bVisible);
}

// @0x14181f140
int CSwooshEffect::vfunc_8(void* p)
{
    if (m_b2e)
    {
        *static_cast<Unk_StreamPoint*>(p) = FUN_140947900(FUN_1409475f0(&m_spRoot));
    }
    else
    {
        if (FUN_1409475d0(&m_spTarget) != 0)
            *static_cast<Unk_StreamPoint*>(p) = FUN_140947900(FUN_1409475f0(&m_spTarget));
    }
    return 1;
}

// MS2-FUNCTIONAL: exe spills the trail positions through extra temporaries; frame differs by 16 bytes.
#ifndef MS2_HOOK_DLL
// @0x14181f1d0
// Appends the current positions of the two trail nodes, smooths the control points into curve samples, writes the
// two vertex rows of the strip (one per trail, same colour) with the texture coordinates along its length, and
// drops the oldest control point once enough are kept.
void CSwooshEffect::UpdateTrail()
{
    double dNow = FUN_14086d260()->FUN_141473280();
    double dElapsed = dNow - m_dLastSample;
    if (dElapsed >= (double)m_fInterval)
    {
        m_dLastSample = m_dLastSample + dElapsed;
        m_kPointsA.push_back(FUN_140947900(FUN_14098d0f0(&m_spTrail1)));
        m_kPointsB.push_back(FUN_140947900(FUN_14098d0f0(&m_spTrail2)));
        unsigned short nPoints = (unsigned short)m_kPointsA.size();
        if (nPoints < 4)
            return;
        {
            float fPerSegment = (float)(unsigned)m_nCurveSamples / (float)(unsigned)m_nSegments;
            unsigned nSteps = (unsigned)(__int64)fPerSegment;
            for (int i = 0; i < (int)(nPoints - 3); ++i)
            {
                for (unsigned j = 0; j < nSteps; ++j)
                {
                    float fT = (float)j / fPerSegment;
                    m_kCurveA.push_back(reinterpret_cast<Unk_StreamPoint&&>(static_cast<NiPoint3&&>(FUN_141820e00(m_kPointsA[i], m_kPointsA[i + 1], m_kPointsA[i + 2], m_kPointsA[i + 3], fT))));
                    m_kCurveB.push_back(reinterpret_cast<Unk_StreamPoint&&>(static_cast<NiPoint3&&>(FUN_141820e00(m_kPointsB[i], m_kPointsB[i + 1], m_kPointsB[i + 2], m_kPointsB[i + 3], fT))));
                }
            }
            m_kCurveA.push_back(m_kPointsA[m_kPointsA.size() - 1]);
            m_kCurveB.push_back(m_kPointsB[m_kPointsB.size() - 1]);
            unsigned short nCurve = (unsigned short)m_kCurveA.size();
            static NiColorA kWhite(1.0f, 1.0f, 1.0f, 1.0f);
            NiPoint3* pPos = (NiPoint3*)m_spMesh->Lock(NiCommonSemantics::POSITION(), 0, 2);
            if (pPos != 0)
            {
                NiColorA* pCol = (NiColorA*)m_spMesh->Lock(NiCommonSemantics::COLOR(), 0, 2);
                if (pCol != 0)
                {
                    for (int nSet = 0; nSet < m_nUVSets; ++nSet)
                    {
                        NiPoint2* pUV = (NiPoint2*)m_spMesh->Lock(NiCommonSemantics::TEXCOORD(), nSet, 2);
                        if (pUV != 0)
                        {
                            for (int k = 0; k < (int)nCurve; ++k)
                            {
                                float fV = (float)k / (float)(int)(nCurve - 1);
                                NiPoint2 kTop(fV, 0.0f);
                                NiPoint2 kBottom(fV, 1.0f);
                                pUV[k] = kTop;
                                pUV[k + nCurve] = kBottom;
                                FUN_14097fad0(&pPos[k], &m_kCurveA[k]);
                                pCol[k] = kWhite;
                                FUN_14097fad0(&pPos[k + nCurve], &m_kCurveB[k]);
                                pCol[k + nCurve] = kWhite;
                            }
                            m_spMesh->Unlock(NiCommonSemantics::TEXCOORD(), nSet, 2);
                        }
                    }
                    m_spMesh->Unlock(NiCommonSemantics::COLOR(), 0, 2);
                }
                m_spMesh->Unlock(NiCommonSemantics::POSITION(), 0, 2);
                m_spMesh->SetVertexCount((unsigned int)nCurve << 1);
            }
            unsigned short nQuads = nCurve - 1;
            unsigned short* pIdx = (unsigned short*)m_spMesh->Lock(NiCommonSemantics::INDEX(), 0, 2);
            if (pIdx != 0)
            {
                for (unsigned short i = 0; i < nQuads; ++i)
                {
                    unsigned int nBase = (unsigned int)i * 3;
                    pIdx[nBase] = i;
                    pIdx[nBase + 1] = i + nCurve;
                    pIdx[nBase + 2] = i + 1;
                    nBase = ((unsigned int)i + (unsigned int)nQuads) * 3;
                    pIdx[nBase] = i + 1;
                    pIdx[nBase + 1] = i + nCurve;
                    pIdx[nBase + 2] = i + 1 + nCurve;
                }
                m_spMesh->Unlock(NiCommonSemantics::INDEX(), 0, 2);
                m_spMesh->SetTriangleCount((unsigned int)nQuads * 6);
            }
            m_spMesh->UpdateBound();
            if (m_nSegments + 3 <= m_kPointsA.size())
            {
                m_kPointsA.erase(m_kPointsA.begin());
                m_kPointsB.erase(m_kPointsB.begin());
            }
            m_kCurveA.clear();
            m_kCurveB.clear();
        }
    }
}
#endif

// FUN_141820e00 builds its result with NiPoint3(x,y,z) (0x14097f250); the curve vectors store it as Unk_StreamPoint.
// @0x141820e00
NiPoint3 FUN_141820e00(const Unk_StreamPoint& p0, const Unk_StreamPoint& p1, const Unk_StreamPoint& p2, const Unk_StreamPoint& p3, float fT)
{
    D3DXVECTOR3 v0(p0.x, p0.y, p0.z), v1(p1.x, p1.y, p1.z), v2(p2.x, p2.y, p2.z), v3(p3.x, p3.y, p3.z), kOut(0, 0, 0);
    D3DXVec3CatmullRom(&kOut, &v0, &v1, &v2, &v3, fT);
    return NiPoint3(kOut.x, kOut.y, kOut.z);
}

// @0x141820f80
int CSwooshEffect::vfunc_12()
{
    return 7;
}

// @0x141820fa0
int FUN_141820fa0(const Unk_EffectMgr* pMgr)
{
    return pMgr->m_nTrailMode;
}

// ---- typed stand-ins for the small std::vector<Unk_StreamPoint> glue the toolchain's STL does not produce ----
typedef std::vector<Unk_StreamPoint, efd::CustomAllocator<Unk_StreamPoint> > Unk_PointVec;

// @0x14181fd60 max by value
unsigned FUN_14181fd60(unsigned nA, unsigned nB)
{
    unsigned nResult = nB;
    if (nB < nA)
        nResult = nA;
    return nResult;
}

// @0x1418205a0 identity (pointer unwrap)
Unk_StreamPoint* FUN_1418205a0(Unk_StreamPoint* pPoint)
{
    return pPoint;
}

// @0x141820700 store pointer
void FUN_141820700(Unk_StreamPoint** ppDst, Unk_StreamPoint* pPoint)
{
    *ppDst = pPoint;
}

// @0x141820bf0 empty
void FUN_141820bf0()
{
}

// @0x141820c00
void FUN_141820c00(void* pObj)
{
    FUN_141820bf0();
}

// @0x141820ca0
// MS2-FUNCTIONAL: stand-in for the std::vector destructor body (_Tidy + proxy release).
void FUN_141820ca0(Unk_PointVec* pVec)
{
    pVec->clear();
    pVec->shrink_to_fit();
}

// @0x141821210 identity
void* FUN_141821210(void* p)
{
    return p;
}

// @0x1418217d0 allocator construct (placement copy)
void FUN_1418217d0(void* pAlloc, Unk_StreamPoint* pDst, const Unk_StreamPoint* pSrc)
{
    if (pDst != 0)
        new (pDst) Unk_StreamPoint(*pSrc);
}

// @0x141821880 empty
void FUN_141821880()
{
}

// @0x141821ad0
MS2_EMIT_CRT_MEMMOVE_S();
