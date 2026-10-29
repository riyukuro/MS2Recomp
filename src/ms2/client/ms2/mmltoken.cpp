// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MMLToken and MMLParser (the instrument MML text parser).
// MS2-UNIT: ?\mmltoken.cpp
// MS2-RANGE: 0x140d7e660-0x140d81400 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\mmltoken.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "mmltoken.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "hook/ms2hook.h"

// @0x140d7e660
MMLParser::MMLParser(const CString& strMml)
{
    Reset();
    SetText(strMml);
    m_bFixedTempo = false;
}

// @0x140d7e6d0
void MMLParser::Reset()
{
    m_nTempo = 0x78;
    m_nOctave = 4;
    m_nLength = 4;
    m_nVolume = 8;
    m_bDotted = false;
    m_tokens.clear();
}

// @0x140d7e730
void MMLParser::SetText(const CString& strMml)
{
    m_strMml = strMml;
}

// @0x140d7e760
void MMLParser::SetFixedTempo(bool b)
{
    m_bFixedTempo = b;
}

// MS2-FUNCTIONAL: Parse is op-identical, but several locals sit in different frame slots (EH state at rsp+0x238 vs ours 0x230), left for the permuter
// @0x140d7e780
void MMLParser::Parse()
{
    Reset();
    if (m_strMml.IsEmpty())
        return;
    m_tokens.reserve(m_strMml.GetLength());
    const char* pText = m_strMml.GetBuffer();
    int nLen = m_strMml.GetLength();
    bool bTie = false;
    int nPos = 0;
    while (nPos < nLen)
    {
        int nClass = Classify(pText[nPos]);
        if (nClass == 1 || nClass == 4)
        {
            int nNote = 0xc;
            bool bDotted = m_bDotted;
            int nLength = 0;
            if (nClass == 1)
            {
                int nUsed = ParseNote(pText + nPos, &nNote);
                if (nUsed == 0)
                {
                    nPos = nPos + 1;
                    continue;
                }
                nPos = nPos + nUsed;
            }
            else if (nClass == 4)
            {
                nPos = nPos + 1;
                nNote = 0xc;
            }
            int nDigits = ParseNumber(pText + nPos, &nLength);
            if (nDigits == 0)
                nLength = m_nLength;
            else
                bDotted = false;
            nPos = nPos + nDigits;
            if (pText + nPos != 0 && pText[nPos] == '.')
            {
                nPos = nPos + 1;
                bDotted = true;
            }
            MS2Ptr<MMLToken> spToken(new MMLToken());
            double dTime = FUN_140d7ff80(nLength, bDotted);
            spToken->m_dTime = dTime;
            if (nClass == 1)
            {
                spToken->m_nType = 0;
                int nPitch = FUN_140d7ff60(nNote);
                spToken->m_nPitch = nPitch;
                int nVolume = FUN_140d7ff40(m_nVolume);
                spToken->m_nValue = nVolume;
            }
            else if (nClass == 4)
            {
                spToken->m_nType = 1;
                spToken->m_nPitch = 0xc;
                spToken->m_nValue = 0;
            }
            if (bTie && !m_tokens.empty())
            {
                MS2Ptr<MMLToken> spPrev = *m_tokens.rbegin();
                if (spPrev->m_nPitch == spToken->m_nPitch)
                {
                    if (spPrev->m_nValue == spToken->m_nValue)
                    {
                        double* pdTime = &spPrev->m_dTime;
                        *pdTime = *pdTime + spToken->m_dTime;
                        bTie = false;
                        continue;
                    }
                }
            }
            m_tokens.push_back(spToken);
        }
        else if (nClass == 2)
        {
            nPos = nPos + 1;
            int nValue = 0;
            int nUsed = ParseNumber(pText + nPos, &nValue);
            if (nUsed == 0)
                continue;
            nPos = nPos + nUsed;
            int nPitch = nValue + 0xc;
            if (nPitch < 0xc || 0x77 < nPitch)
                continue;
            MS2Ptr<MMLToken> spToken(new MMLToken());
            double dTime = FUN_140d7ff80(m_nLength, m_bDotted);
            spToken->m_dTime = dTime;
            spToken->m_nType = 0;
            spToken->m_nPitch = nPitch;
            int nVolume = FUN_140d7ff40(m_nVolume);
            spToken->m_nValue = nVolume;
            if (bTie && !m_tokens.empty())
            {
                MS2Ptr<MMLToken> spPrev = *m_tokens.rbegin();
                if (spPrev->m_nPitch == spToken->m_nPitch)
                {
                    if (spPrev->m_nValue == spToken->m_nValue)
                    {
                        double* pdTime = &spPrev->m_dTime;
                        *pdTime = *pdTime + spToken->m_dTime;
                        bTie = false;
                        continue;
                    }
                }
            }
            m_tokens.push_back(spToken);
        }
        else if (nClass == 5)
        {
            nPos = nPos + 1;
            int nValue = m_nOctave;
            int nUsed = ParseNumber(pText + nPos, &nValue);
            if (nUsed == 0)
                continue;
            nPos = nPos + nUsed;
            if (nValue >= 0 && nValue <= 8)
                m_nOctave = nValue;
        }
        else if (nClass == 6)
        {
            nPos = nPos + 1;
            int nValue = m_nLength;
            int nUsed = ParseNumber(pText + nPos, &nValue);
            if (nUsed == 0)
                continue;
            nPos = nPos + nUsed;
            if (pText + nPos != 0 && pText[nPos] == '.')
            {
                nPos = nPos + 1;
                m_bDotted = true;
            }
            else
            {
                m_bDotted = false;
            }
            if (nValue >= 1 && nValue <= 0x40)
                m_nLength = nValue;
        }
        else if (nClass == 7)
        {
            nPos = nPos + 1;
            int nValue = m_nVolume;
            int nUsed = ParseNumber(pText + nPos, &nValue);
            if (nUsed == 0)
                continue;
            nPos = nPos + nUsed;
            if (nValue >= 0 && nValue <= 0xf)
                m_nVolume = nValue;
        }
        else if (nClass == 8)
        {
            nPos = nPos + 1;
            int nValue = m_nTempo;
            int nUsed = ParseNumber(pText + nPos, &nValue);
            if (nUsed == 0)
                continue;
            nPos = nPos + nUsed;
            if (m_bFixedTempo == false && nValue >= 0x20 && nValue <= 0xff)
                m_nTempo = nValue;
        }
        else if (nClass == 9)
        {
            nPos = nPos + 1;
            m_nOctave = m_nOctave + 1;
            if (m_nOctave < 0)
                m_nOctave = 0;
            if (8 < m_nOctave)
                m_nOctave = 8;
        }
        else if (nClass == 10)
        {
            nPos = nPos + 1;
            m_nOctave = m_nOctave + -1;
            if (m_nOctave < 0)
                m_nOctave = 0;
            if (8 < m_nOctave)
                m_nOctave = 8;
        }
        else
        {
            if (nClass == 0xb)
            {
                nPos = nPos + 1;
                bTie = true;
                continue;
            }
            else if (nClass == 0xe)
            {
                nPos = nPos + 1;
                int nValue = 0;
                int nUsed = ParseNumber(pText + nPos, &nValue);
                if (nUsed == 0)
                    continue;
                nPos = nPos + nUsed;
                MS2Ptr<MMLToken> spToken(new MMLToken());
                spToken->m_nType = 2;
                spToken->m_dTime = 0;
                spToken->m_nPitch = 0x40;
                if (nValue > 0)
                    spToken->m_nValue = 0x7f;
                else
                    spToken->m_nValue = 0;
                m_tokens.push_back(spToken);
            }
            else if (nClass == 0x10)
            {
                nPos = nPos + 1;
                int nValue = 0;
                int nUsed = ParseNumber(pText + nPos, &nValue);
                if (nUsed == 0)
                    continue;
                nPos = nPos + nUsed;
                MS2Ptr<MMLToken> spToken(new MMLToken());
                spToken->m_nType = 5;
                spToken->m_dTime = 0;
                spToken->m_nPitch = 1;
                spToken->m_nValue = nValue;
                m_tokens.push_back(spToken);
            }
            else if (nClass == 0x11)
            {
                nPos = nPos + 1;
                int nValue = 0;
                int nUsed = ParseNumber(pText + nPos, &nValue);
                if (nUsed == 0)
                    continue;
                nPos = nPos + nUsed;
                if (nValue >= 0x20 && nValue <= 0xff)
                {
                    MS2Ptr<MMLToken> spToken(new MMLToken());
                    spToken->m_nType = 5;
                    spToken->m_dTime = 0;
                    spToken->m_nPitch = 0;
                    spToken->m_nValue = nValue;
                    m_tokens.push_back(spToken);
                }
            }
            else if (nClass == 0xd)
            {
                nPos = nPos + 1;
                int nFirst = 0;
                int nUsed = ParseNumber(pText + nPos, &nFirst);
                if (nUsed == 0)
                    continue;
                nPos = nPos + nUsed;
                if (pText + nPos == 0 || pText[nPos] != ',')
                    continue;
                nPos = nPos + 1;
                int nSecond = 0;
                nUsed = ParseNumber(pText + nPos, &nSecond);
                if (nUsed == 0)
                    continue;
                nPos = nPos + nUsed;
                MS2Ptr<MMLToken> spToken(new MMLToken());
                spToken->m_nType = 2;
                spToken->m_dTime = 0;
                spToken->m_nPitch = nFirst;
                spToken->m_nValue = nSecond;
                m_tokens.push_back(spToken);
            }
            else if (nClass == 0xf)
            {
                nPos = nPos + 1;
                int nFirst = 0;
                int nUsed = ParseNumber(pText + nPos, &nFirst);
                if (nUsed == 0)
                    continue;
                nPos = nPos + nUsed;
                if (pText + nPos == 0 || pText[nPos] != ',')
                    continue;
                nPos = nPos + 1;
                int nSecond = 0;
                nUsed = ParseNumber(pText + nPos, &nSecond);
                if (nUsed == 0)
                    continue;
                nPos = nPos + nUsed;
                MS2Ptr<MMLToken> spToken(new MMLToken());
                spToken->m_nType = 4;
                spToken->m_dTime = 0;
                spToken->m_nPitch = nFirst;
                spToken->m_nValue = nSecond;
                m_tokens.push_back(spToken);
            }
            else
            {
                nPos = nPos + 1;
            }
        }
        bTie = false;
    }
}

// @0x140d7faf0
int MMLParser::Classify(char c)
{
    switch (c)
    {
    case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G':
    case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g':
        return 1;
    case 'N': case 'n':
        return 2;
    case 'R': case 'r':
        return 4;
    case 'O': case 'o':
        return 5;
    case 'L': case 'l':
        return 6;
    case 'V': case 'v':
        return 7;
    case 'T': case 't':
        return 8;
    case '>':
        return 9;
    case '<':
        return 10;
    case '&':
        return 0xb;
    case 'Y': case 'y':
        return 0xd;
    case 'I': case 'i':
        return 0xf;
    case 'S': case 's':
        return 0xe;
    case 'M': case 'm':
        return 0x10;
    case 'P': case 'p':
        return 0x11;
    }
    return 0;
}

// @0x140d7fc50
int MMLParser::ParseNumber(const char* p, int* pnValue)
{
    int nCount;
    for (nCount = 0; p[nCount] != '\0'; nCount++)
    {
        if (!(p[nCount] == '0' || p[nCount] == '1' || p[nCount] == '2' || p[nCount] == '3' || p[nCount] == '4' ||
              p[nCount] == '5' || p[nCount] == '6' || p[nCount] == '7' || p[nCount] == '8' || p[nCount] == '9'))
            break;
    }
    *pnValue = atoi(p);
    return nCount;
}

// @0x140d7fd80
int MMLParser::ParseNote(const char* p, int* pnNote)
{
    if (*p == 'C' || *p == 'c')
    {
        *pnNote = 0xc;
    }
    else if (*p == 'D' || *p == 'd')
    {
        *pnNote = 0xe;
    }
    else if (*p == 'E' || *p == 'e')
    {
        *pnNote = 0x10;
    }
    else if (*p == 'F' || *p == 'f')
    {
        *pnNote = 0x11;
    }
    else if (*p == 'G' || *p == 'g')
    {
        *pnNote = 0x13;
    }
    else if (*p == 'A' || *p == 'a')
    {
        *pnNote = 0x15;
    }
    else if (*p == 'B' || *p == 'b')
    {
        *pnNote = 0x17;
    }
    else
    {
        *pnNote = -1;
        return 0;
    }
    if (p[1] != '\0')
    {
        if (p[1] == '+')
        {
            *pnNote = *pnNote + 1;
            return 2;
        }
        else if (p[1] == '-')
        {
            *pnNote = *pnNote - 1;
            return 2;
        }
    }
    return 1;
}

// @0x140d7ff40
int MMLParser::FUN_140d7ff40(int nVolume)
{
    return nVolume << 3;
}

// @0x140d7ff60
int MMLParser::FUN_140d7ff60(int nNote)
{
    return m_nOctave * 0xc + nNote;
}

// @0x140d7ff80
double MMLParser::FUN_140d7ff80(int nLength, bool bDotted)
{
    if (nLength == 0)
        return 0.0;
    double dTime = 60000.0;
    dTime = dTime / (double)m_nTempo;
    dTime = dTime / (double)nLength;
    dTime = dTime * 4.0;
    if (bDotted)
        dTime = dTime * 1.5;
    return dTime;
}

// @0x140d80bc0
MMLToken::MMLToken()
{
}

MS2_EMIT_CRT_MEMMOVE_S();

// The default constructor sits just before this TU's range start in the exe.
// MS2-RANGE: 0x140d7e600-0x140d7e660 .text$mn
// @0x140d7e600
MMLParser::MMLParser()
{
    Reset();
    m_bFixedTempo = false;
}
