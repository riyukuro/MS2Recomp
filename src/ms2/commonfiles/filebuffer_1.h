// CFileBuffer layout from ctor 0x14038b7c0 and its buffer accessors.
#pragma once
#include <afx.h>
#include <list>
#include <string>
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/conlinepatchfilebuffer.h"
class CFileBuffer : public CPtred {
public:
    CFileBuffer();
    virtual ~CFileBuffer();
    void Allocate(unsigned size);
    void Adopt(void* data, unsigned size);
    void SetText(const CStringW& text);
    unsigned GetSize();
    void* GetBuffer();
    int m_ownership;
    void* m_pBuffer;
    unsigned m_nSize;
    int m_field2c, m_field30, m_field34, m_field38, m_field3c;
    union {
        unsigned char m_key[8];
        __time64_t m_tLastAccess;   // CFileSystem cache timestamp (FUN_1403a9480/FUN_1403ab1a0)
    };
};
MS2_CHECK_SIZE(CFileBuffer, 0x48);
MS2_CHECK_OFFSET(CFileBuffer,m_ownership,0x18);
MS2_CHECK_OFFSET(CFileBuffer,m_pBuffer,0x20);
MS2_CHECK_OFFSET(CFileBuffer,m_nSize,0x28);
MS2_CHECK_OFFSET(CFileBuffer,m_key,0x40);
void ListFilesRecursive(const char*, const char*, std::list<CString>&);
COnlinePatchFileBuffer* FUN_14038bf20(const char*,const char*);
std::string ComputeSha1Hex(const void*,size_t);
