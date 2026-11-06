// cubeheightindex.h - the cube terrain height index of CubeMapInformationService (+0x2a8, FUN_1410b9e70 returns it).
// One efd::map<int, int> keyed by Key(x, y) (x and y masked to a byte each) whose value is the top height of the column
// (FUN_1410b24b0 gives INT_MIN for an empty column). The real class name is not recovered.
//   ctor 0x141123030 (defined in unit_141121cf0, which builds the map through its 0x141122050 ctor wrapper)
//   dtor 0x141125ea0 (defined in cubemapinformationservice_tail15, ~efd::map<int, int> 0x141125210)
//   FUN_1410b24b0 (cubecraft_3), FUN_1410b2510 / FUN_1410b25a0 / Clear (cubemapinformationservice_1)
#pragma once
#include <efd/StdContainers.h>
#include "ms2/ms2layout.h"

class Unk_CubeHeightIndex {
public:
    Unk_CubeHeightIndex();
    ~Unk_CubeHeightIndex();
    int FUN_1410b24b0(unsigned, unsigned);
    void FUN_1410b2510(int,int,int);
    void FUN_1410b25a0(int,int,int);
    void Clear();
    static inline int Key(int x,int y) { return (x&0xff)+((y&0xff)<<8); }
    // In a union so that the out-of-line ctor / dtor build and free it by hand: the exe ctor calls the 0x141122050
    // efd::map<int, int> ctor, and our ??0 of efd::map<int, int> is bound one layer down (0x141122070, std::map).
    union { efd::map<int,int> m_heights; };
};

MS2_CHECK_SIZE(Unk_CubeHeightIndex,0x10);
