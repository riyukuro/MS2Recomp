// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Unnamed unit unit_1408e1840: the ATL::CAtlMap
// SetOptimalLoad and UpdateRehashThresholds COMDATs of CUserEventManager's seven int -> MS2Ptr<context> maps
// (cusereventmanager.h), emitted through explicit instantiations. PickSize and Rehash are the COMDATs of the unit before
// (?\usereventmanager.cpp, 0x1408de580-0x1408dfb60), declared here as explicit specializations so this unit does not
// carry copies of them.
// MS2-UNIT: unit_1408e1840
// MS2-RANGE: 0x1408e1840-0x1408e2330 .text$mn
#define MS2_THIS_FILE ""

#include "ms2/placeholder/ms2stdafx.h"
#include <afx.h>
#include <atlcoll.h>
#include "ms2/placeholder/cusereventmanager.h"

#include "ms2/ms2recover.h"

template <> UINT ATL::CAtlMap<int, MS2Ptr<CUserEventManager::Context1A0> >::PickSize(size_t nElements) const throw();
template <> void ATL::CAtlMap<int, MS2Ptr<CUserEventManager::Context1A0> >::Rehash(UINT nBins);
template <> UINT ATL::CAtlMap<int, MS2Ptr<CommonUserEvent::DTRewardEventContext> >::PickSize(size_t nElements) const throw();
template <> void ATL::CAtlMap<int, MS2Ptr<CommonUserEvent::DTRewardEventContext> >::Rehash(UINT nBins);
template <> UINT ATL::CAtlMap<int, MS2Ptr<CUserEventManager::Context350> >::PickSize(size_t nElements) const throw();
template <> void ATL::CAtlMap<int, MS2Ptr<CUserEventManager::Context350> >::Rehash(UINT nBins);
template <> UINT ATL::CAtlMap<int, MS2Ptr<CUserEventManager::Context38> >::PickSize(size_t nElements) const throw();
template <> void ATL::CAtlMap<int, MS2Ptr<CUserEventManager::Context38> >::Rehash(UINT nBins);
template <> UINT ATL::CAtlMap<int, MS2Ptr<CUserEventManager::ContextMentoring> >::PickSize(size_t nElements) const throw();
template <> void ATL::CAtlMap<int, MS2Ptr<CUserEventManager::ContextMentoring> >::Rehash(UINT nBins);
template <> UINT ATL::CAtlMap<int, MS2Ptr<CUserEventManager::Context2D8> >::PickSize(size_t nElements) const throw();
template <> void ATL::CAtlMap<int, MS2Ptr<CUserEventManager::Context2D8> >::Rehash(UINT nBins);
template <> UINT ATL::CAtlMap<int, MS2Ptr<CUserEventManager::ContextB0> >::PickSize(size_t nElements) const throw();
template <> void ATL::CAtlMap<int, MS2Ptr<CUserEventManager::ContextB0> >::Rehash(UINT nBins);

// @0x1408e1840
template void ATL::CAtlMap<int, MS2Ptr<CUserEventManager::Context1A0> >::SetOptimalLoad(float, float, float, bool);
// @0x1408e18f0
template void ATL::CAtlMap<int, MS2Ptr<CommonUserEvent::DTRewardEventContext> >::SetOptimalLoad(float, float, float, bool);
// @0x1408e19a0
template void ATL::CAtlMap<int, MS2Ptr<CUserEventManager::Context350> >::SetOptimalLoad(float, float, float, bool);
// @0x1408e1a50
template void ATL::CAtlMap<int, MS2Ptr<CUserEventManager::Context38> >::SetOptimalLoad(float, float, float, bool);
// @0x1408e1b00
template void ATL::CAtlMap<int, MS2Ptr<CUserEventManager::ContextMentoring> >::SetOptimalLoad(float, float, float, bool);
// @0x1408e1bb0
template void ATL::CAtlMap<int, MS2Ptr<CUserEventManager::Context2D8> >::SetOptimalLoad(float, float, float, bool);
// @0x1408e1c60
template void ATL::CAtlMap<int, MS2Ptr<CUserEventManager::ContextB0> >::SetOptimalLoad(float, float, float, bool);
// @0x1408e1d10
template void ATL::CAtlMap<int, MS2Ptr<CUserEventManager::Context1A0> >::UpdateRehashThresholds() throw();
// @0x1408e1df0
template void ATL::CAtlMap<int, MS2Ptr<CommonUserEvent::DTRewardEventContext> >::UpdateRehashThresholds() throw();
// @0x1408e1ed0
template void ATL::CAtlMap<int, MS2Ptr<CUserEventManager::Context350> >::UpdateRehashThresholds() throw();
// @0x1408e1fb0
template void ATL::CAtlMap<int, MS2Ptr<CUserEventManager::Context38> >::UpdateRehashThresholds() throw();
// @0x1408e2090
template void ATL::CAtlMap<int, MS2Ptr<CUserEventManager::ContextMentoring> >::UpdateRehashThresholds() throw();
// @0x1408e2170
template void ATL::CAtlMap<int, MS2Ptr<CUserEventManager::Context2D8> >::UpdateRehashThresholds() throw();
// @0x1408e2250
template void ATL::CAtlMap<int, MS2Ptr<CUserEventManager::ContextB0> >::UpdateRehashThresholds() throw();
