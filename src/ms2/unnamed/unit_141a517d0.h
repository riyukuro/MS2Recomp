// unit_141a517d0.h - the alignment-info pointer of the minimap COMDAT tail (unit_141a517d0 / unit_141a51a30). w535.
// NOT an original header. UIMinimapDialog::m_alignment (+0x480) is spelled SnowmanPtr<UICommon::CAlignmentInfo> in
// uiminimapentity.h, but the exe keeps a second, byte-identical set of its glue for this TU (AddRef 0x141a51890,
// Reference 0x141a51920, AddRefImpl 0x141a51a00, Release 0x141a51af0, ReleaseImpl 0x141a51c20) next to the
// uisnowmaneventdialog.cpp copies (0x140e97430...). Two copies mean two different names, and the mangled-name order of
// the tail puts this one after MS2Ptr<UIMinimapEntityTaxi> in every group, so its real template name sorts after
// "MS2Ptr" (unknown; invented name below). Same 16-byte shape and bodies as SnowmanPtr<>.
#pragma once

#include "ms2/client/ms2/uicommon.h"

template <class T> class Unk_AlignInfoPtr
{
public:
    Unk_AlignInfoPtr(T* p) : m_p(p) { AddRef(); }
    ~Unk_AlignInfoPtr() { Release(); }
private:
    void AddRef() const { if (m_p) AddRefImpl(0); }
    static void Reference(T* p) { p->FUN_14015b020(); }
    void AddRefImpl(void*) const { Reference(m_p); }
    void Release() { if (m_p) { ReleaseImpl(0); m_p = 0; } }
    void ReleaseImpl(void*) {
        if (m_p->FUN_140159bc0() == 0) {
            Reference(m_p);
            m_p->FUN_140159ba0();
        }
    }
    void* m_unused;
    T* m_p;
};
