// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Parses a "name.<n>_" style token and returns the part after '_'.
// MS2-UNIT: unit_141421740
// MS2-RANGE: 0x141421740-0x1414218b3 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"


// @0x141421740
CString GetModelVariant(const CString& text, int* pOutIndex)
{
    int start = 0;
    CString token = text.Tokenize(".", start);
    if ((token == "")) {
        return CString("");
    }
    int idx = token.GetLength() - 2;
    CString tail = token.Mid(idx);
    if (tail.Find("_", 0) != -1) {
        tail.Trim("_");
        if (pOutIndex != 0) {
            *pOutIndex = idx + 1;
        }
        return CString(tail);
    }
    return CString("A");
}
