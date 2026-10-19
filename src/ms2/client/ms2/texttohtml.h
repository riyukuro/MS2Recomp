// texttohtml.h - the chat text to Scaleform HTML converter (RTTI TextToHtml, a bare NiRefObject: the constructor loads the chat
// colour table; the formatting helpers are unit-local free functions in texttohtml.cpp). NOT an original header (the unit is
// ?\texttohtml.cpp). Member and helper names are invented from use.
#pragma once
#include <afx.h>
#include <NiRefObject.h>

#include "ms2/ms2layout.h"

class TextToHtml : public NiRefObject
{
public:
    TextToHtml();                                       // 0x14183e640
    virtual ~TextToHtml();                              // 0x141847300 (deleting 0x141847340)
};
MS2_CHECK_SIZE(TextToHtml, 0x10);
