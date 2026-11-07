// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CEF 3.x wrapper stream/refcount thunks that the gb:cef TUs
// leave as stubs (ICF-folded bodies and this-adjusting scalar deleting destructors of std::ostringstream-style classes
// with a virtual base), written out over raw object bytes.
// MS2-UNIT: lib_cef_tail
// MS2-RANGE: 0x14279ff00-0x14279ff2b .text$mn
// MS2-RANGE: 0x1427a54d0-0x1427a552f .text$mn
// MS2-RANGE: 0x1427aac20-0x1427aac7f .text$mn
// MS2-RANGE: 0x1427b0250-0x1427b027b .text$mn
// MS2-RANGE: 0x1427b0280-0x1427b02ab .text$mn
// MS2-RANGE: 0x1427b0d40-0x1427b0d9f .text$mn
// MS2-RANGE: 0x1427b10a0-0x1427b10ff .text$mn
// MS2-RANGE: 0x1427b3720-0x1427b377f .text$mn
// MS2-RANGE: 0x1427b4640-0x1427b469f .text$mn
// MS2-RANGE: 0x1427976a0-0x1427976ab .text$mn
// MS2-RANGE: 0x142797948-0x142797953 .text$mn
// MS2-RANGE: 0x14279785c-0x142797867 .text$mn
// MS2-RANGE: 0x1427979ec-0x1427979f7 .text$mn
// MS2-RANGE: 0x1427aa710-0x1427aa71b .text$mn
// MS2-RANGE: 0x1427aa820-0x1427aa82b .text$mn
// MS2-RANGE: 0x1427aa928-0x1427aa933 .text$mn
// MS2-RANGE: 0x1427aa9a4-0x1427aa9af .text$mn
// MS2-RANGE: 0x1427a5530-0x1427a553b .text$mn
// MS2-RANGE: 0x1427a5794-0x1427a579f .text$mn
// MS2-RANGE: 0x1427a5720-0x1427a572b .text$mn
// MS2-RANGE: 0x1427a5420-0x1427a542b .text$mn
// MS2-RANGE: 0x1427a2694-0x1427a269f .text$mn
// MS2-RANGE: 0x1427a2af0-0x1427a2afb .text$mn
// MS2-RANGE: 0x1427a286c-0x1427a2877 .text$mn
// MS2-RANGE: 0x1427a2378-0x1427a2383 .text$mn
// MS2-RANGE: 0x1427a2654-0x1427a265f .text$mn
// MS2-RANGE: 0x1427a2a50-0x1427a2a5b .text$mn
// MS2-RANGE: 0x1427a282c-0x1427a2837 .text$mn
// MS2-RANGE: 0x1427a236c-0x1427a2377 .text$mn
// MS2-RANGE: 0x1427a88e4-0x1427a88ef .text$mn
// MS2-RANGE: 0x1427a8b60-0x1427a8b6b .text$mn
// MS2-RANGE: 0x1427a8a1c-0x1427a8a27 .text$mn
// MS2-RANGE: 0x1427a86fc-0x1427a8707 .text$mn
// MS2-FLAGS: gamebryo
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

void operator delete(void* p, size_t size);   // sized operator delete (the CRT's)
#include "ms2/cef/cef.h"   // CefBaseRefCounted, the (virtual) base whose vftable these objects get back
struct Unk_CefBaseReset : CefBaseRefCounted { static __forceinline void Reset(void* p) { static_cast<Unk_CefBaseReset*>(p)->CefBaseRefCounted::~CefBaseRefCounted(); } };
#include "ms2/cef/cef_ctocpp.h"   // the real CefCToCppRefCounted<..>: its vftables are emitted here
// ~CefCToCppRefCounted<..> (protected) run on a wrapper as the exe's inlined base-dtor step
template <class C, class B, class S> struct Unk_CefCToCppReset : CefCToCppRefCounted<C, B, S>
{
    typedef CefCToCppRefCounted<C, B, S> Base;
    static __forceinline void Reset(void* p) { static_cast<Unk_CefCToCppReset*>(p)->Base::~Base(); }
};

// @0x1427b0250
void* FUN_1427b0250(char* self, unsigned flags)
{
    Unk_CefBaseReset::Reset(self);   // CefBaseRefCounted vptr
    if (flags & 1)
        operator delete(self, 0x58);
    return self;
}

// @0x1427b0280
void* FUN_1427b0280(char* self, unsigned flags)
{
    Unk_CefBaseReset::Reset(self);   // CefBaseRefCounted vptr
    if (flags & 1)
        operator delete(self, 0x58);
    return self;
}

// @0x1427a54d0
void* FUN_1427a54d0(char* self, unsigned flags)
{
    Unk_CefCToCppReset<CefProcessMessageCToCpp, CefProcessMessage, cef_process_message_t>::Reset(self - 0x20);
    Unk_CefBaseReset::Reset(self);   // CefBaseRefCounted vptr
    char* base = self - 0x20;
    if (flags & 1)
        operator delete(base, 0x28);
    return base;
}

// @0x1427aac20
// a CToCpp wrapper's deleting dtor (self = its CefBaseRefCounted subobject): ~CefCToCppRefCounted<..> stores the
// wrapper base's two vftables and the vtordisp. The exe folds the identical 2-slot (all-_purecall) primary vftables of
// the 2-method wrappers into one; CefCallbackCToCpp's names it.
void* FUN_1427aac20(char* self, unsigned flags)
{
    Unk_CefCToCppReset<CefCallbackCToCpp, CefCallback, cef_callback_t>::Reset(self - 0x20);
    Unk_CefBaseReset::Reset(self);   // CefBaseRefCounted vptr
    char* base = self - 0x20;
    if (flags & 1)
        operator delete(base, 0x28);
    return base;
}

// @0x1427b0d40
void* FUN_1427b0d40(char* self, unsigned flags)
{
    Unk_CefCToCppReset<CefBeforeDownloadCallbackCToCpp, CefBeforeDownloadCallback, cef_before_download_callback_t>::Reset(self - 0x20);
    Unk_CefBaseReset::Reset(self);   // CefBaseRefCounted vptr
    char* base = self - 0x20;
    if (flags & 1)
        operator delete(base, 0x28);
    return base;
}

// @0x1427b10a0
void* FUN_1427b10a0(char* self, unsigned flags)
{
    Unk_CefCToCppReset<CefRunContextMenuCallbackCToCpp, CefRunContextMenuCallback, cef_run_context_menu_callback_t>::Reset(self - 0x20);
    Unk_CefBaseReset::Reset(self);   // CefBaseRefCounted vptr
    char* base = self - 0x20;
    if (flags & 1)
        operator delete(base, 0x28);
    return base;
}

// @0x1427b3720
void* FUN_1427b3720(char* self, unsigned flags)
{
    Unk_CefCToCppReset<CefJSDialogCallbackCToCpp, CefJSDialogCallback, cef_jsdialog_callback_t>::Reset(self - 0x20);
    Unk_CefBaseReset::Reset(self);   // CefBaseRefCounted vptr
    char* base = self - 0x20;
    if (flags & 1)
        operator delete(base, 0x28);
    return base;
}

// @0x1427b4640
// CefV8StackFrameCToCpp's deleting dtor: the 8-slot primary vftable (0x1431df560) is CefV8StackFrame's (8 methods);
// its derived vftable 0x1431e14f8 shares the vbase thunks 0x1427aa820.. with 0x1431df5a0.
void* FUN_1427b4640(char* self, unsigned flags)
{
    Unk_CefCToCppReset<CefV8StackFrameCToCpp, CefV8StackFrame, cef_v8stack_frame_t>::Reset(self - 0x20);
    Unk_CefBaseReset::Reset(self);   // CefBaseRefCounted vptr
    char* base = self - 0x20;
    if (flags & 1)
        operator delete(base, 0x28);
    return base;
}

// CefCppToCRefCounted<..>::struct_release (cpptoc_ref_counted.h), ICF-folded over every instantiation: the dead
// DCHECK / DCHECK_EQ LogMessage temporaries give the exe frame its unwind state slot (-2)
struct CefCppToCWrapperStructView
{
    int type_;
    CefBaseRefCounted* wrapper_;
};
// @0x14279ff00
int CEF_CALLBACK FUN_14279ff00(cef_base_ref_counted_t* base)
{
    DCHECK(base);
    if (!base)
        return 0;

    CefCppToCWrapperStructView* wrapperStruct =
        reinterpret_cast<CefCppToCWrapperStructView*>(reinterpret_cast<char*>(base) - sizeof(CefCppToCWrapperStructView));
    // Verify that the wrapper offset was calculated correctly.
    DCHECK_EQ(0, wrapperStruct->type_);   // kWrapperType differs per instantiation; dead with DCHECK_IS_ON() == 0

    return wrapperStruct->wrapper_->Release();
}

//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//

// MS2-PIN: ??_7?$CefCToCppRefCounted@VCefCallbackCToCpp@@VCefCallback@@U_cef_callback_t@@@@6BCefCallback@@@ 0x1431dc618
// MS2-PIN: ??_7?$CefCToCppRefCounted@VCefCallbackCToCpp@@VCefCallback@@U_cef_callback_t@@@@6BCefBaseRefCounted@@@ 0x1431dc628
// MS2-PIN: ??_7?$CefCToCppRefCounted@VCefV8StackFrameCToCpp@@VCefV8StackFrame@@U_cef_v8stack_frame_t@@@@6BCefV8StackFrame@@@ 0x1431df560
// MS2-PIN: ??_7?$CefCToCppRefCounted@VCefV8StackFrameCToCpp@@VCefV8StackFrame@@U_cef_v8stack_frame_t@@@@6BCefBaseRefCounted@@@ 0x1431df5a0
// MS2-PIN: ?AddRef@?$CefCToCppRefCounted@VCefCallbackCToCpp@@VCefCallback@@U_cef_callback_t@@@@$4PPPPPPPM@A@EBAXXZ 0x14279785c
// MS2-PIN: ?Release@?$CefCToCppRefCounted@VCefCallbackCToCpp@@VCefCallback@@U_cef_callback_t@@@@$4PPPPPPPM@A@EBA_NXZ 0x1427979ec
// MS2-PIN: ?HasOneRef@?$CefCToCppRefCounted@VCefCallbackCToCpp@@VCefCallback@@U_cef_callback_t@@@@$4PPPPPPPM@A@EBA_NXZ 0x142797948
// MS2-PIN: ??_E?$CefCToCppRefCounted@VCefCallbackCToCpp@@VCefCallback@@U_cef_callback_t@@@@$2PPPPPPPM@A@EAAPEAXI@Z 0x1427976a0
// MS2-PIN: ?AddRef@?$CefCToCppRefCounted@VCefV8StackFrameCToCpp@@VCefV8StackFrame@@U_cef_v8stack_frame_t@@@@$4PPPPPPPM@A@EBAXXZ 0x1427aa820
// MS2-PIN: ?Release@?$CefCToCppRefCounted@VCefV8StackFrameCToCpp@@VCefV8StackFrame@@U_cef_v8stack_frame_t@@@@$4PPPPPPPM@A@EBA_NXZ 0x1427aa9a4
// MS2-PIN: ?HasOneRef@?$CefCToCppRefCounted@VCefV8StackFrameCToCpp@@VCefV8StackFrame@@U_cef_v8stack_frame_t@@@@$4PPPPPPPM@A@EBA_NXZ 0x1427aa928
// MS2-PIN: ??_E?$CefCToCppRefCounted@VCefV8StackFrameCToCpp@@VCefV8StackFrame@@U_cef_v8stack_frame_t@@@@$2PPPPPPPM@A@EAAPEAXI@Z 0x1427aa710
// MS2-PIN: ??_7?$CefCToCppRefCounted@VCefProcessMessageCToCpp@@VCefProcessMessage@@U_cef_process_message_t@@@@6BCefProcessMessage@@@ 0x1431de6c8
// MS2-PIN: ??_7?$CefCToCppRefCounted@VCefProcessMessageCToCpp@@VCefProcessMessage@@U_cef_process_message_t@@@@6BCefBaseRefCounted@@@ 0x1431de6f0
// MS2-PIN: ??_7?$CefCToCppRefCounted@VCefBeforeDownloadCallbackCToCpp@@VCefBeforeDownloadCallback@@U_cef_before_download_callback_t@@@@6BCefBeforeDownloadCallback@@@ 0x1431de3d8
// MS2-PIN: ??_7?$CefCToCppRefCounted@VCefBeforeDownloadCallbackCToCpp@@VCefBeforeDownloadCallback@@U_cef_before_download_callback_t@@@@6BCefBaseRefCounted@@@ 0x1431de3e0
// MS2-PIN: ??_7?$CefCToCppRefCounted@VCefRunContextMenuCallbackCToCpp@@VCefRunContextMenuCallback@@U_cef_run_context_menu_callback_t@@@@6BCefRunContextMenuCallback@@@ 0x1431de400
// MS2-PIN: ??_7?$CefCToCppRefCounted@VCefRunContextMenuCallbackCToCpp@@VCefRunContextMenuCallback@@U_cef_run_context_menu_callback_t@@@@6BCefBaseRefCounted@@@ 0x1431de410
// MS2-PIN: ??_7?$CefCToCppRefCounted@VCefJSDialogCallbackCToCpp@@VCefJSDialogCallback@@U_cef_jsdialog_callback_t@@@@6BCefJSDialogCallback@@@ 0x1431df020
// MS2-PIN: ??_7?$CefCToCppRefCounted@VCefJSDialogCallbackCToCpp@@VCefJSDialogCallback@@U_cef_jsdialog_callback_t@@@@6BCefBaseRefCounted@@@ 0x1431df028
// MS2-PIN: ?AddRef@?$CefCToCppRefCounted@VCefProcessMessageCToCpp@@VCefProcessMessage@@U_cef_process_message_t@@@@$4PPPPPPPM@A@EBAXXZ 0x1427a5530
// MS2-PIN: ?Release@?$CefCToCppRefCounted@VCefProcessMessageCToCpp@@VCefProcessMessage@@U_cef_process_message_t@@@@$4PPPPPPPM@A@EBA_NXZ 0x1427a5794
// MS2-PIN: ?HasOneRef@?$CefCToCppRefCounted@VCefProcessMessageCToCpp@@VCefProcessMessage@@U_cef_process_message_t@@@@$4PPPPPPPM@A@EBA_NXZ 0x1427a5720
// MS2-PIN: ??_E?$CefCToCppRefCounted@VCefProcessMessageCToCpp@@VCefProcessMessage@@U_cef_process_message_t@@@@$2PPPPPPPM@A@EAAPEAXI@Z 0x1427a5420
// MS2-PIN: ?AddRef@?$CefCToCppRefCounted@VCefBeforeDownloadCallbackCToCpp@@VCefBeforeDownloadCallback@@U_cef_before_download_callback_t@@@@$4PPPPPPPM@A@EBAXXZ 0x1427a2694
// MS2-PIN: ?Release@?$CefCToCppRefCounted@VCefBeforeDownloadCallbackCToCpp@@VCefBeforeDownloadCallback@@U_cef_before_download_callback_t@@@@$4PPPPPPPM@A@EBA_NXZ 0x1427a2af0
// MS2-PIN: ?HasOneRef@?$CefCToCppRefCounted@VCefBeforeDownloadCallbackCToCpp@@VCefBeforeDownloadCallback@@U_cef_before_download_callback_t@@@@$4PPPPPPPM@A@EBA_NXZ 0x1427a286c
// MS2-PIN: ??_E?$CefCToCppRefCounted@VCefBeforeDownloadCallbackCToCpp@@VCefBeforeDownloadCallback@@U_cef_before_download_callback_t@@@@$2PPPPPPPM@A@EAAPEAXI@Z 0x1427a2378
// MS2-PIN: ?AddRef@?$CefCToCppRefCounted@VCefRunContextMenuCallbackCToCpp@@VCefRunContextMenuCallback@@U_cef_run_context_menu_callback_t@@@@$4PPPPPPPM@A@EBAXXZ 0x1427a2654
// MS2-PIN: ?Release@?$CefCToCppRefCounted@VCefRunContextMenuCallbackCToCpp@@VCefRunContextMenuCallback@@U_cef_run_context_menu_callback_t@@@@$4PPPPPPPM@A@EBA_NXZ 0x1427a2a50
// MS2-PIN: ?HasOneRef@?$CefCToCppRefCounted@VCefRunContextMenuCallbackCToCpp@@VCefRunContextMenuCallback@@U_cef_run_context_menu_callback_t@@@@$4PPPPPPPM@A@EBA_NXZ 0x1427a282c
// MS2-PIN: ??_E?$CefCToCppRefCounted@VCefRunContextMenuCallbackCToCpp@@VCefRunContextMenuCallback@@U_cef_run_context_menu_callback_t@@@@$2PPPPPPPM@A@EAAPEAXI@Z 0x1427a236c
// MS2-PIN: ?AddRef@?$CefCToCppRefCounted@VCefJSDialogCallbackCToCpp@@VCefJSDialogCallback@@U_cef_jsdialog_callback_t@@@@$4PPPPPPPM@A@EBAXXZ 0x1427a88e4
// MS2-PIN: ?Release@?$CefCToCppRefCounted@VCefJSDialogCallbackCToCpp@@VCefJSDialogCallback@@U_cef_jsdialog_callback_t@@@@$4PPPPPPPM@A@EBA_NXZ 0x1427a8b60
// MS2-PIN: ?HasOneRef@?$CefCToCppRefCounted@VCefJSDialogCallbackCToCpp@@VCefJSDialogCallback@@U_cef_jsdialog_callback_t@@@@$4PPPPPPPM@A@EBA_NXZ 0x1427a8a1c
// MS2-PIN: ??_E?$CefCToCppRefCounted@VCefJSDialogCallbackCToCpp@@VCefJSDialogCallback@@U_cef_jsdialog_callback_t@@@@$2PPPPPPPM@A@EAAPEAXI@Z 0x1427a86fc
