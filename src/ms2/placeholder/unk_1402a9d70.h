// unk_1402a9d70.h - the class of the condition-table static: ATL::CAtlMap<UINT, CString> (ctor 0x1402a9d70, dtor
// 0x1402aa1d0, pinned in commonfiles\conditionutil.cpp). The name stays for the includers' statics.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"

typedef ATL::CAtlMap<unsigned int, CString> Unk_1402a9d70;
MS2_CHECK_SIZE(Unk_1402a9d70, 0x48);   // the exe ctor fills up to m_pFree at +0x40; the old char[0x50] stand-in was rounded up
