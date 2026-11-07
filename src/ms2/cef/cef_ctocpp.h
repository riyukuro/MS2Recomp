// cef_ctocpp.h - the libcef_dll_wrapper C-to-C++ wrapper class headers (libcef_dll/ctocpp/*_ctocpp.h of the same CEF
// 3.3396.1786 SDK as cef.h) for game-side units that need the real CefCToCppRefCounted<..> instantiations (their
// vftables, AddRef/Release/HasOneRef and the vtordisp thunks). `libcef_dll` next to this file is a symlink to the SDK's
// libcef_dll dir; like cef.h's `include`, it resolves the headers' "libcef_dll/..." and "include/..." paths. The
// wrapper itself is linked from the lib-cef objs. Not an original header.
#pragma once

#include "cef.h"

#ifndef WRAPPING_CEF_SHARED
#define WRAPPING_CEF_SHARED   // the wrapper-side guard of the ctocpp headers
#endif
// NDEBUG as in cef.h: the exe's wrapper instantiations have DCHECK_IS_ON() == 0
#ifndef NDEBUG
#define MS2_CEF_UNDEF_NDEBUG
#define NDEBUG
#endif
#include "libcef_dll/ctocpp/callback_ctocpp.h"
#include "libcef_dll/ctocpp/v8stack_frame_ctocpp.h"
#include "libcef_dll/ctocpp/process_message_ctocpp.h"
#include "libcef_dll/ctocpp/before_download_callback_ctocpp.h"
#include "libcef_dll/ctocpp/run_context_menu_callback_ctocpp.h"
#include "libcef_dll/ctocpp/jsdialog_callback_ctocpp.h"

#ifdef MS2_CEF_UNDEF_NDEBUG
#undef MS2_CEF_UNDEF_NDEBUG
#undef NDEBUG
#include <assert.h>
#endif
