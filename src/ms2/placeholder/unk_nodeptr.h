// unk_nodeptr.h - Unk_NodePtr: the game's 8-byte smart pointer to a scene-graph node (NiAVObject / NiNode). NOT an
// original header (name assumed; the exe symbol table calls it Unk_NodePtr). Out-of-line members live in the
// exe: ctor 0x1409f7170, dtor 0x1409f74b0, IsEqual 0x1409f77a0; the accessors are free functions in the symbol table.
#pragma once

void FUN_1405a93d0(void* p);            // NiRefObject::DecRefCount
void FUN_140980460(void* p);            // NiRefObject::IncRefCount

struct Unk_NodePtr
{
    Unk_NodePtr(void* p = 0);           // 0x1409f7170  m_p = p, adds a reference (the default: an implicit owner ctor passes 0)
    ~Unk_NodePtr();                     // 0x1409f74b0  drops the reference
    bool FUN_1409f77a0(int nNull);      // 0x1409f77a0  m_p == (void*)nNull
    // Inline members (COMDATs emitted by the first unit that uses them: 0x140aac240 / 0x140aac3e0 in randomtargeteffect).
    // Copy (the exe's is 0x1409f7130): the implicit memberwise copy would skip the reference, so returning a local by
    // value (no NRVO at /Od) left the result dangling once the local's destructor dropped the only reference.
    Unk_NodePtr(const Unk_NodePtr& o) : m_p(o.m_p)
    {
        if (m_p)
            FUN_140980460(m_p);
    }
    Unk_NodePtr& operator=(const Unk_NodePtr& o)
    {
        if (m_p != o.m_p)
        {
            if (m_p)
                FUN_1405a93d0(m_p);
            m_p = o.m_p;
            if (m_p)
                FUN_140980460(m_p);
        }
        return *this;
    }
    bool operator!=(int nNull) const { return m_p != (void*)(__int64)nNull; }
    void* m_p;
};

void* FUN_1409475d0(Unk_NodePtr* p);    // non-const get
void* FUN_1409475f0(Unk_NodePtr* p);    // const get (same body)
void FUN_1409f76f0(void* pSelf, void* pNew);   // Unk_NodePtr::Reset(pNew)
