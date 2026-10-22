// commonutil.h - PLACEHOLDER: declarations of commonfiles\commonutil.cpp helpers that other units call. NOT an original
// header. Include it instead of re-declaring these locally: a local by-value spelling changes the caller's argument
// passing (the callee would destroy a caller temp) and stops the call sites from matching.
#pragma once

#include <afx.h>

// Looks a key up in the localized string table; empty when the table is not up yet. The key is taken by const& (exe).
CStringW GetStringCommonByKey(const CStringW& strKey);         // @0x14028b8e0
