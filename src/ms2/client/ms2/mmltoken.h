// mmltoken.h - MMLToken / MMLParser: the Music Macro Language (instrument play mode) text parser. MMLParser turns an MML
// string ("T120 O4 L8 CDEFGAB>C ...") into a list of MMLToken (note, rest, tempo/volume/instrument controls); MMLToken is a
// refcounted record of one event. Owning unit: ?\mmltoken.cpp (0x140d7e660-0x140d81400). The parser's class name has no RTTI
// (it has no vtable): "MMLParser" is invented, so are the member names (taken from the commands each branch handles).
#pragma once
#include <afx.h>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"

// 0x30 bytes. vftable (1 slot, ??_G 0x140d80cf0 sized delete 0x30).
class MMLToken : public CPtred
{
public:
    MMLToken();                                         // 0x140d80bc0 (inline)
    // ~MMLToken: implicit (0x140d80c30): the exe dtor only calls ~CPtred

public:
    MS2_LAYOUT_FRIEND;
    int m_nType;                                        // +0x18 0 note, 1 rest, 2 control, 4 / 5 other controls
    int m_nPitch;                                       // +0x1c pitch (0xc + semitone) or the control id
    int m_nValue;                                       // +0x20 volume << 3 or the control value
    int m_pad_24;
    double m_dTime;                                     // +0x28 duration in ms
};
MS2_CHECK_SIZE(MMLToken, 0x30);
MS2_CHECK_OFFSET(MMLToken, m_nType, 0x18);
MS2_CHECK_OFFSET(MMLToken, m_dTime, 0x28);

// 0x40 bytes.
class MMLParser
{
public:
    MMLParser();                                        // 0x140d7e600
    explicit MMLParser(const CString& strMml);          // 0x140d7e660
    void Reset();                                       // 0x140d7e6d0 default octave / tempo / length / volume, drops the tokens
    void SetText(const CString& strMml);                // 0x140d7e730
    void SetFixedTempo(bool b);                         // 0x140d7e760
    void Parse();                                       // 0x140d7e780 fills m_tokens from m_strMml
    int Classify(char c);                               // 0x140d7faf0 the command class of a character (0 = ignored)
    int ParseNumber(const char* p, int* pnValue);       // 0x140d7fc50 reads the digits at p, returns their count
    int ParseNote(const char* p, int* pnNote);          // 0x140d7fd80 a note letter with + / -, returns its length
    int FUN_140d7ff40(int nVolume);                     // nVolume * 8
    int FUN_140d7ff60(int nNote);                       // m_nOctave * 12 + nNote
    double FUN_140d7ff80(int nLength, bool bDotted);    // the duration in ms of a note length

public:
    MS2_LAYOUT_FRIEND;
    int m_nOctave;                                      // +0x00 'O' 0..8 (4)
    int m_nTempo;                                       // +0x04 'T' 32..255 (120)
    bool m_bDotted;                                     // +0x08 'L' with a dot
    int m_nVolume;                                      // +0x0c 'V' 0..15 (8)
    int m_nLength;                                      // +0x10 'L' 1..64 (4)
    int m_pad_14;
    CString m_strMml;                                   // +0x18
    bool m_bFixedTempo;                                 // +0x20
    std::vector<MS2Ptr<MMLToken> > m_tokens;            // +0x28
};
MS2_CHECK_SIZE(MMLParser, 0x40);
MS2_CHECK_OFFSET(MMLParser, m_strMml, 0x18);
MS2_CHECK_OFFSET(MMLParser, m_tokens, 0x28);
