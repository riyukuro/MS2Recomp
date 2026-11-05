// podarray.h - Unk_PodArray<T>: the growable array of trivially constructible elements that COutPacket keeps at +0x18
// (data +0, size +8, max +0x10, grow-by int +0x18). It has CAtlArray's members and the same operator[] guard, but
// SetCount / GrowBuffer / destructor carry no constructor or destructor loops (exe 0x14020bfa0 / 0x14020ba50 /
// 0x14020a580), and memory comes from the imported calloc / free. NOT an original name.
// GrowBuffer relocates with ATL::CElementTraitsBase<unsigned char>::RelocateElements (0x1401c2a80, Checked::memmove_s).
#pragma once

#include <stddef.h>
#include <afx.h>
#include <atlcoll.h>

// The static-CRT headers declare calloc/free without dllimport; the exe calls the IAT slots.
extern "C" void* (__cdecl* __imp_calloc)(size_t, size_t);
extern "C" void (__cdecl* __imp_free)(void*);
// 0x1401c2a80 = ATL::CElementTraitsBase<unsigned char>::RelocateElements (atlcoll.h inline, C3: was FUN_1401c2a80)

template <class T>
class Unk_PodArray
{
public:
    Unk_PodArray() : m_pData(NULL), m_nSize(0), m_nMaxSize(0), m_nGrowBy(0) {}
    // @0x14020a580
    ~Unk_PodArray() throw() { if (m_pData != NULL) __imp_free(m_pData); }

    // @0x14020b800
    size_t GetCount() const { return m_nSize; }
    // @0x14020b810
    const T* GetData() const { return m_pData; }
    T* GetData() { return m_pData; }
    // @0x14020a740
    const T& operator[](size_t iElement) const { if (iElement >= m_nSize) AtlThrow(E_INVALIDARG); return m_pData[iElement]; }
    // @0x14020a700
    T& operator[](size_t iElement) { if (iElement >= m_nSize) AtlThrow(E_INVALIDARG); return m_pData[iElement]; }

    // @0x140715210
    void RemoveAll() { SetCount(0, -1); }

    // @0x14020bfa0
    bool SetCount(size_t nNewSize, int nGrowBy = -1)
    {
        if (nGrowBy != -1) m_nGrowBy = nGrowBy;
        if (nNewSize == 0) {
            if (m_pData != NULL) { __imp_free(m_pData); m_pData = NULL; }
            m_nSize = 0;
            m_nMaxSize = 0;
        } else if (nNewSize <= m_nMaxSize) {
            m_nSize = nNewSize;
        } else {
            bool bSuccess;
            bSuccess = GrowBuffer(nNewSize);
            if (!bSuccess) return false;
            m_nSize = nNewSize;
        }
        return true;
    }

private:
    // @0x14020ba50
    bool GrowBuffer(size_t nNewSize)
    {
        if (nNewSize > m_nMaxSize) {
            if (m_pData == NULL) {
                size_t nAllocSize = ((size_t)m_nGrowBy > nNewSize) ? (size_t)m_nGrowBy : nNewSize;
                m_pData = static_cast<T*>(__imp_calloc(nAllocSize, 1));
                if (m_pData == NULL) return false;
                m_nMaxSize = nAllocSize;
            } else {
                size_t nGrowBy = (size_t)m_nGrowBy;
                if (nGrowBy == 0) {
                    nGrowBy = m_nSize / 8;
                    nGrowBy = (nGrowBy < 4) ? 4 : ((nGrowBy > 1024) ? 1024 : nGrowBy);
                }
                size_t nNewMax;
                if (nNewSize < (m_nMaxSize + nGrowBy)) nNewMax = m_nMaxSize + nGrowBy;
                else nNewMax = nNewSize;
                T* pNewData = static_cast<T*>(__imp_calloc(nNewMax, 1));
                if (pNewData == NULL) return false;
                ATL::CElementTraitsBase<unsigned char>::RelocateElements(reinterpret_cast<unsigned char*>(pNewData), reinterpret_cast<unsigned char*>(m_pData), m_nSize);
                __imp_free(m_pData);
                m_pData = pNewData;
                m_nMaxSize = nNewMax;
            }
        }
        return true;
    }

    T* m_pData;
    size_t m_nSize;
    size_t m_nMaxSize;
    int m_nGrowBy;
};
