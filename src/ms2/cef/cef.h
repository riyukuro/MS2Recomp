// cef.h - the CEF 3.3396.1786 C++ wrapper headers (third_party/src/cef_binary_3.3396.1786.gd3e36d0_windows64_minimal,
// the version the exe links: NOTES.md "Middleware"). CEF's headers include each other as "include/...", so this shim
// sits next to an `include` symlink to the SDK's include dir: MSVC (and clang-cl) search the directories of the open
// includers for quoted includes, and this file's directory resolves every "include/..." path. Not an original header.
#pragma once

// The exe's CEF wrapper instantiations (scoped_refptr::operator-> 0x141b7b9c0: LAZY_STREAM with a constant-false
// condition, no GetMinLogLevel call) were compiled with NDEBUG, i.e. DCHECK_IS_ON() == 0, while the game code around
// them keeps its asserts: NDEBUG is defined only around the SDK headers and <assert.h> is re-included afterwards.
#ifndef NDEBUG
#define MS2_CEF_UNDEF_NDEBUG
#define NDEBUG
#endif
#include "include/cef_app.h"
#include "include/cef_browser.h"
#include "include/cef_client.h"
#include "include/cef_process_message.h"
#include "include/cef_values.h"
#include "include/cef_v8.h"

#ifdef MS2_CEF_UNDEF_NDEBUG
#undef MS2_CEF_UNDEF_NDEBUG
#undef NDEBUG
#include <assert.h>
#endif
