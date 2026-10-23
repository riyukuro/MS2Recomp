// Recovered Nexon Messenger stream and decoder declarations.
#pragma once

#include "ms2/placeholder/nmfunc.h"

class CNMSimpleStreamDecoder
{
public:
    CNMSimpleStreamDecoder(CNMStream* pStream);
    ~CNMSimpleStreamDecoder();

    virtual unsigned int ReadCount();
    virtual unsigned char ReadU8();
    virtual unsigned short ReadU16();
    virtual unsigned int ReadU32();
    virtual unsigned long long ReadU64();
    virtual wchar_t* ReadWStringBuf(wchar_t* pBuffer, unsigned int capacity);
    virtual wchar_t* ReadWString();
    virtual char* ReadStringBuf(char* pBuffer, int capacity);
    virtual char* ReadString();
    virtual void ReadStringBufAlias(char* pBuffer, int capacity);
    virtual void ReadStringAlias();
    virtual unsigned int ReadBytes(unsigned char* pBuffer, unsigned int count);
    virtual unsigned long long ReadU64Alias();

    CNMStream* m_pStream;     // +0x08
    wchar_t* m_pWide;         // +0x10
    char* m_pAnsi;            // +0x18
};
MS2_CHECK_SIZE(CNMSimpleStreamDecoder, 0x20);

class CNMSerializableDecoder : public CNMSimpleStreamDecoder
{
public:
    CNMSerializableDecoder(CNMStream* pStream, CNMSerializable* pObject);
    ~CNMSerializableDecoder();

    unsigned int ReadCount() override;
    unsigned char ReadU8() override;
    unsigned short ReadU16() override;
    unsigned int ReadU32() override;
    unsigned long long ReadU64() override;
    wchar_t* ReadWStringBuf(wchar_t* pBuffer, unsigned int capacity) override;
    wchar_t* ReadWString() override;
    unsigned int ReadBytes(unsigned char* pBuffer, unsigned int count) override;
    unsigned long long ReadU64Alias() override;

    int m_nStart;               // +0x20
    int m_bValid;               // +0x24
    unsigned char m_bVersion;   // +0x28
    unsigned char m_pad[3];     // +0x29
    unsigned int m_nEnd;        // +0x2c
};
MS2_CHECK_SIZE(CNMSerializableDecoder, 0x30);
