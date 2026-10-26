// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Tail of the ms2.cpp object: a SceneGraphCacheData smart-pointer
// release helper, three virtual-delete helpers, a destructor thunk for the magicdata table, and 78 singleton destroy
// helpers `if (instance) { delete GetInstance(); instance = 0; }` (one per TSingleton-style class; the class names are not
// recoverable from the bodies, so instance pointers and getters are typed void* and the virtual destructor call goes
// through the unit-local Unk_VirtualDtor).
// MS2-UNIT: unit_14149fd50
// MS2-RANGE: 0x14149fd50-0x1414a1c30 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <efd/MemObject.h>
#include <efd/RefCount.h>
#include "ms2/ms2layout.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Unit-local declarations; the unidentified names describe uses rather than original class names.
// Release target of the scene graph cache smart pointer (ecr::SceneGraphCache::SceneGraphCacheData in the exe: the reference
// count is the first member and the destructor is non-virtual, deleted through the MemObject operator delete). The sized
// delete hands the block back to the efd pool by size, so the stand-in keeps the exe's sizeof (0x90): a smaller one returns
// the 0x90 block to the wrong FixedSizeAllocator.
struct Unk_SceneCacheData : public efd::MemObject
{
    ~Unk_SceneCacheData();
    efd::AtomicRefCount m_refCount;
    char m_aRest[0x8c];             // status, llid/physicalID/filePath, objects, request list (not touched here)
};
MS2_CHECK_SIZE(Unk_SceneCacheData, 0x90);
// Class whose virtual destructor sits in vftable slot 8.
struct Unk_Slot8Delete
{
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual ~Unk_Slot8Delete();
};
// Singleton class with a virtual destructor in slot 0.
struct Unk_VirtualDtor
{
    virtual ~Unk_VirtualDtor();
};
// Singleton class whose TSingleton base (virtual destructor) is a secondary base at +8.
struct Unk_PrimaryBase
{
    virtual void vfunc_0();
};
struct Unk_SecondaryDtorBase
{
    virtual ~Unk_SecondaryDtorBase();
};
struct Unk_SecondaryDtorSingleton : public Unk_PrimaryBase, public Unk_SecondaryDtorBase
{
};
// Static table of the magic data (FUN_14146a6a0 = its destructor).
struct Unk_MagicTable
{
    void FUN_14146a6a0();
};
extern Unk_MagicTable DAT_143adca50;

// Singleton instance pointers and instance getters (exe data/functions; bound through progress/symbols).
extern void* DAT_143aab388;
extern void* DAT_143aab398;
extern void* DAT_143aab4f8;
extern void* DAT_143aac278;
extern void* DAT_143aac280;
extern void* DAT_143aac2a8;
extern void* DAT_143aac2b0;
extern void* DAT_143aac3c8;
extern void* DAT_143aac4d0;
extern void* DAT_143aac5b8;
extern void* DAT_143aac640;
extern void* DAT_143aac648;
extern void* DAT_143aac658;
extern void* DAT_143aac6f8;
extern void* DAT_143aacd08;
extern void* DAT_143aacd90;
extern void* DAT_143aad148;
extern void* DAT_143aad158;
extern void* DAT_143aad180;
extern void* DAT_143aad188;
extern void* DAT_143aad288;
extern void* DAT_143aad290;
extern void* DAT_143aaeb00;
extern void* DAT_143aaeb10;
extern void* DAT_143aaec48;
extern void* DAT_143aaecb0;
extern void* DAT_143aaece0;
extern void* DAT_143aaee00;
extern void* DAT_143aaef58;
extern void* DAT_143aaf098;
extern void* DAT_143aaf1a8;
extern void* DAT_143aaf1b0;
extern void* DAT_143aaf1b8;
extern void* DAT_143aaf1c0;
extern void* DAT_143aaf1e0;
extern void* DAT_143aaf300;
extern void* DAT_143aaf308;
extern void* DAT_143aafb40;
extern void* DAT_143aafb50;
extern void* DAT_143aafb98;
extern void* DAT_143aafd08;
extern void* DAT_143aafd18;
extern void* DAT_143aafd98;
extern void* DAT_143aafde0;
extern void* DAT_143aaff10;
extern void* DAT_143aaff58;
extern void* DAT_143aaffd8;
extern void* DAT_143ab0668;
extern void* DAT_143ab0a08;
extern void* DAT_143ab3330;
extern void* DAT_143ab3848;
extern void* DAT_143ab3920;
extern void* DAT_143ab3aa0;
extern void* DAT_143ab3be0;
extern void* DAT_143ab3d88;
extern void* DAT_143ab3da8;
extern void* DAT_143ab4148;
extern void* DAT_143ab4798;
extern void* DAT_143ab5b98;
extern void* DAT_143ab5c68;
extern void* DAT_143ab5c70;
extern void* DAT_143ab5cb8;
extern void* DAT_143ab5cc8;
extern void* DAT_143ab7808;
extern void* DAT_143ab8f50;
extern void* DAT_143ab9658;
extern void* DAT_143ab9d18;
extern void* DAT_143aba268;
extern void* DAT_143abad48;
extern void* DAT_143abafd8;
extern void* DAT_143abf720;
extern void* DAT_143ac1b80;
extern void* DAT_143ac5c38;
extern void* DAT_143aca188;
extern void* DAT_143ace478;
extern void* DAT_143ace480;
extern void* DAT_143ad8960;
extern void* DAT_143ad8ba8;
void* FUN_140166410();
void* FUN_140166420();
void* FUN_140166430();
void* FUN_1401958a0();
void* FUN_1401b59c0();
void* FUN_1401c0d80();
void* FUN_1401c0d90();
void* FUN_1401d31e0();
void* FUN_14025e7b0();
void* FUN_140281980();
void* FUN_140302b00();
void* FUN_140302b10();
void* FUN_14034f780();
void* FUN_1403782c0();
void* FUN_1403a9410();
void* FUN_1403b4740();
void* FUN_1403ed290();
void* FUN_1403fc330();
void* FUN_1404a1bb0();
void* FUN_1404f4530();
void* FUN_14052d1d0();
void* FUN_14052d1e0();
void* FUN_14052d1f0();
void* FUN_14052d200();
void* FUN_140535300();
void* FUN_140535310();
void* FUN_1405934c0();
void* FUN_1405a96f0();
void* FUN_14062c280();
void* FUN_1406c7600();
void* FUN_140700390();
void* FUN_140764010();
void* FUN_1409331e0();
void* FUN_140953f20();
void* FUN_14097a780();
void* FUN_1409995c0();
void* FUN_1409a8b00();
void* FUN_1409a8b10();
void* FUN_1409c1730();
void* FUN_1409c4b20();
void* FUN_1409c4b30();
void* FUN_1409eecd0();
void* FUN_1409eece0();
void* FUN_1409eecf0();
void* FUN_1409eed00();
void* FUN_1409fb930();
void* FUN_140a5af70();
void* FUN_140a6a830();
void* FUN_140ab7a10();
void* FUN_140ae1c00();
void* FUN_140b05bf0();
void* FUN_140b1a4e0();
void* FUN_140b2e980();
void* FUN_140b86180();
void* FUN_140ba4fa0();
void* FUN_140c8dac0();
void* FUN_140d294c0();
void* FUN_140d738f0();
void* FUN_140d8ee90();
void* FUN_140e09140();
void* FUN_140e0a9f0();
void* FUN_140e0d900();
void* FUN_140e37aa0();
void* FUN_140f17d40();
void* FUN_140f2d240();
void* FUN_140f2d250();
void* FUN_140f56960();
void* FUN_140f64150();
void* FUN_140f688a0();
void* FUN_14109a6f0();
void* FUN_14109a700();
void* FUN_1411f91b0();
void* FUN_14123ee80();
void* FUN_1412787a0();
void* FUN_1412818c0();
void* FUN_141371b20();
void* FUN_141484720();
void* FUN_1414a56d0();

void FUN_14149fe70(Unk_SceneCacheData* p);

// @0x14149fd50
void FUN_14149fd50(Unk_SceneCacheData* p)
{
    if (--p->m_refCount == 0)
        FUN_14149fe70(p);
}
MS2_REPLACE(0x14149FD50, FUN_14149fd50, 41, 0x0E2FCD50);

// @0x14149fd80
void FUN_14149fd80(Unk_Slot8Delete* p)
{
    delete p;
}
MS2_REPLACE(0x14149FD80, FUN_14149fd80, 79, 0x0838999B);

// @0x14149fdd0
void FUN_14149fdd0(Unk_Slot8Delete* p)
{
    delete p;
}
MS2_REPLACE(0x14149FDD0, FUN_14149fdd0, 79, 0x0838999B);

// @0x14149fe20
void FUN_14149fe20(Unk_Slot8Delete* p)
{
    delete p;
}
MS2_REPLACE(0x14149FE20, FUN_14149fe20, 79, 0x0838999B);

// @0x14149fe70
void FUN_14149fe70(Unk_SceneCacheData* p)
{
    delete p;
}
MS2_REPLACE(0x14149FE70, FUN_14149fe70, 73, 0x032D49BB);

// @0x14149fec0
void FUN_14149fec0()
{
    DAT_143adca50.FUN_14146a6a0();
}
MS2_REPLACE(0x14149FEC0, FUN_14149fec0, 21, 0xC697E12D);

// @0x14149fee0
void FUN_14149fee0()
{
    if (DAT_143ab3be0 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_1409995c0();
        DAT_143ab3be0 = 0;
    }
}
MS2_REPLACE(0x14149FEE0, FUN_14149fee0, 94, 0x7F62458B);

// @0x14149ff40
void FUN_14149ff40()
{
    if (DAT_143ab3d88 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_1409a8b00();
        DAT_143ab3d88 = 0;
    }
}
MS2_REPLACE(0x14149FF40, FUN_14149ff40, 94, 0x92787D34);

// @0x14149ffa0
void FUN_14149ffa0()
{
    if (DAT_143aac2a8 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_1403fc330();
        DAT_143aac2a8 = 0;
    }
}
MS2_REPLACE(0x14149FFA0, FUN_14149ffa0, 94, 0x5475E1A5);

// @0x1414a0000
void FUN_1414a0000()
{
    if (DAT_143ab5c68 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_14123ee80();
        DAT_143ab5c68 = 0;
    }
}
MS2_REPLACE(0x1414A0000, FUN_1414a0000, 94, 0x3E19299D);

// @0x1414a0060
void FUN_1414a0060()
{
    if (DAT_143ab4148 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_1409c1730();
        DAT_143ab4148 = 0;
    }
}
MS2_REPLACE(0x1414A0060, FUN_1414a0060, 94, 0x6273A9F4);

// @0x1414a00c0
void FUN_1414a00c0()
{
    if (DAT_143ab0668 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_1406c7600();
        DAT_143ab0668 = 0;
    }
}
MS2_REPLACE(0x1414A00C0, FUN_1414a00c0, 94, 0x4A6BE7CF);

// @0x1414a0120
void FUN_1414a0120()
{
    if (DAT_143ab3920 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_1409fb930();
        DAT_143ab3920 = 0;
    }
}
MS2_REPLACE(0x1414A0120, FUN_1414a0120, 94, 0xB97A7C60);

// @0x1414a0180
void FUN_1414a0180()
{
    if (DAT_143aac278 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_1401958a0();
        DAT_143aac278 = 0;
    }
}
MS2_REPLACE(0x1414A0180, FUN_1414a0180, 94, 0x24B54FB7);

// @0x1414a01e0
void FUN_1414a01e0()
{
    if (DAT_143aac280 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_140ba4fa0();
        DAT_143aac280 = 0;
    }
}
MS2_REPLACE(0x1414A01E0, FUN_1414a01e0, 94, 0x434DD445);

// @0x1414a0240
void FUN_1414a0240()
{
    if (DAT_143ac5c38 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_140e37aa0();
        DAT_143ac5c38 = 0;
    }
}
MS2_REPLACE(0x1414A0240, FUN_1414a0240, 94, 0xB9BB425B);

// @0x1414a02a0
void FUN_1414a02a0()
{
    if (DAT_143ab7808 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_140a5af70();
        DAT_143ab7808 = 0;
    }
}
MS2_REPLACE(0x1414A02A0, FUN_1414a02a0, 94, 0x8D2FCE7D);

// @0x1414a0300
void FUN_1414a0300()
{
    if (DAT_143ab4798 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_1412787a0();
        DAT_143ab4798 = 0;
    }
}
MS2_REPLACE(0x1414A0300, FUN_1414a0300, 94, 0x23417763);

// @0x1414a0360
void FUN_1414a0360()
{
    if (DAT_143aac2b0 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_1401b59c0();
        DAT_143aac2b0 = 0;
    }
}
MS2_REPLACE(0x1414A0360, FUN_1414a0360, 94, 0x1909B041);

// @0x1414a03c0
void FUN_1414a03c0()
{
    if (DAT_143ab5b98 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_140e09140();
        DAT_143ab5b98 = 0;
    }
}
MS2_REPLACE(0x1414A03C0, FUN_1414a03c0, 94, 0xC1E87E13);

// @0x1414a0420
void FUN_1414a0420()
{
    if (DAT_143ab5c70 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_140d8ee90();
        DAT_143ab5c70 = 0;
    }
}
MS2_REPLACE(0x1414A0420, FUN_1414a0420, 94, 0x739F711F);

// @0x1414a0480
void FUN_1414a0480()
{
    if (DAT_143ab5cb8 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_140f17d40();
        DAT_143ab5cb8 = 0;
    }
}
MS2_REPLACE(0x1414A0480, FUN_1414a0480, 94, 0x8D0D1F3E);

// @0x1414a04e0
void FUN_1414a04e0()
{
    if (DAT_143aac3c8 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_1401c0d80();
        DAT_143aac3c8 = 0;
    }
}
MS2_REPLACE(0x1414A04E0, FUN_1414a04e0, 94, 0x6D588353);

// @0x1414a0540
void FUN_1414a0540()
{
    if (DAT_143ab5cc8 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_140a6a830();
        DAT_143ab5cc8 = 0;
    }
}
MS2_REPLACE(0x1414A0540, FUN_1414a0540, 94, 0xA92456EA);

// @0x1414a05a0
void FUN_1414a05a0()
{
    if (DAT_143ab3aa0 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_14097a780();
        DAT_143ab3aa0 = 0;
    }
}
MS2_REPLACE(0x1414A05A0, FUN_1414a05a0, 94, 0x9630DAEE);

// @0x1414a0600
void FUN_1414a0600()
{
    if (DAT_143ab9d18 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_140d294c0();
        DAT_143ab9d18 = 0;
    }
}
MS2_REPLACE(0x1414A0600, FUN_1414a0600, 94, 0xA03ED1FF);

// @0x1414a0660
void FUN_1414a0660()
{
    if (DAT_143aba268 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_140b05bf0();
        DAT_143aba268 = 0;
    }
}
MS2_REPLACE(0x1414A0660, FUN_1414a0660, 94, 0xD1BE3873);

// @0x1414a06c0
void FUN_1414a06c0()
{
    if (DAT_143aac640 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_140e0a9f0();
        DAT_143aac640 = 0;
    }
}
MS2_REPLACE(0x1414A06C0, FUN_1414a06c0, 94, 0x1EB76F19);

// @0x1414a0720
void FUN_1414a0720()
{
    if (DAT_143aca188 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_140f2d240();
        DAT_143aca188 = 0;
    }
}
MS2_REPLACE(0x1414A0720, FUN_1414a0720, 94, 0xA84F0957);

// @0x1414a0780
void FUN_1414a0780()
{
    if (DAT_143aac648 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_140f2d250();
        DAT_143aac648 = 0;
    }
}
MS2_REPLACE(0x1414A0780, FUN_1414a0780, 94, 0x609BF47E);

// @0x1414a07e0
void FUN_1414a07e0()
{
    if (DAT_143aac658 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_1409eecd0();
        DAT_143aac658 = 0;
    }
}
MS2_REPLACE(0x1414A07E0, FUN_1414a07e0, 94, 0xE9648A44);

// @0x1414a0840
void FUN_1414a0840()
{
    if (DAT_143abad48 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_140e0d900();
        DAT_143abad48 = 0;
    }
}
MS2_REPLACE(0x1414A0840, FUN_1414a0840, 94, 0x2EF1C062);

// @0x1414a08a0
void FUN_1414a08a0()
{
    if (DAT_143aac6f8 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_140b1a4e0();
        DAT_143aac6f8 = 0;
    }
}
MS2_REPLACE(0x1414A08A0, FUN_1414a08a0, 94, 0x1C5A456E);

// @0x1414a0900
void FUN_1414a0900()
{
    if (DAT_143aacd08 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_14025e7b0();
        DAT_143aacd08 = 0;
    }
}
MS2_REPLACE(0x1414A0900, FUN_1414a0900, 94, 0x710BAE1E);

// @0x1414a0960
void FUN_1414a0960()
{
    if (DAT_143aad148 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_1403782c0();
        DAT_143aad148 = 0;
    }
}
MS2_REPLACE(0x1414A0960, FUN_1414a0960, 94, 0x6CD131BB);

// @0x1414a09c0
void FUN_1414a09c0()
{
    if (DAT_143aad158 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_140b86180();
        DAT_143aad158 = 0;
    }
}
MS2_REPLACE(0x1414A09C0, FUN_1414a09c0, 94, 0x0C860B3D);

// @0x1414a0a20
void FUN_1414a0a20()
{
    if (DAT_143ace480 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_14109a6f0();
        DAT_143ace480 = 0;
    }
}
MS2_REPLACE(0x1414A0A20, FUN_1414a0a20, 94, 0xE0AFA01D);

// @0x1414a0a80
void FUN_1414a0a80()
{
    if (DAT_143aac5b8 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_1401d31e0();
        DAT_143aac5b8 = 0;
    }
}
MS2_REPLACE(0x1414A0A80, FUN_1414a0a80, 94, 0x1B9DDC8E);

// @0x1414a0ae0
void FUN_1414a0ae0()
{
    if (DAT_143aad288 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_1414a56d0();
        DAT_143aad288 = 0;
    }
}
MS2_REPLACE(0x1414A0AE0, FUN_1414a0ae0, 94, 0x68B35DB4);

// @0x1414a0b40
void FUN_1414a0b40()
{
    if (DAT_143aad290 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_14034f780();
        DAT_143aad290 = 0;
    }
}
MS2_REPLACE(0x1414A0B40, FUN_1414a0b40, 94, 0x7F79D7DE);

// @0x1414a0ba0
void FUN_1414a0ba0()
{
    if (DAT_143aaeb00 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_1404a1bb0();
        DAT_143aaeb00 = 0;
    }
}
MS2_REPLACE(0x1414A0BA0, FUN_1414a0ba0, 94, 0x79D06837);

// @0x1414a0c00
void FUN_1414a0c00()
{
    if (DAT_143aaeb10 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_140764010();
        DAT_143aaeb10 = 0;
    }
}
MS2_REPLACE(0x1414A0C00, FUN_1414a0c00, 94, 0x6985980E);

// @0x1414a0c60
void FUN_1414a0c60()
{
    if (DAT_143aab388 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_140166410();
        DAT_143aab388 = 0;
    }
}
MS2_REPLACE(0x1414A0C60, FUN_1414a0c60, 94, 0x39C29BB3);

// @0x1414a0cc0
void FUN_1414a0cc0()
{
    if (DAT_143ace478 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_14109a700();
        DAT_143ace478 = 0;
    }
}
MS2_REPLACE(0x1414A0CC0, FUN_1414a0cc0, 94, 0xBD69728F);

// @0x1414a0d20
void FUN_1414a0d20()
{
    if (DAT_143ab0a08 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_140700390();
        DAT_143ab0a08 = 0;
    }
}
MS2_REPLACE(0x1414A0D20, FUN_1414a0d20, 94, 0x1CA2C135);

// @0x1414a0d80
void FUN_1414a0d80()
{
    if (DAT_143aaec48 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_140d738f0();
        DAT_143aaec48 = 0;
    }
}
MS2_REPLACE(0x1414A0D80, FUN_1414a0d80, 94, 0xA8361B64);

// @0x1414a0de0
void FUN_1414a0de0()
{
    if (DAT_143ab8f50 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_140ab7a10();
        DAT_143ab8f50 = 0;
    }
}
MS2_REPLACE(0x1414A0DE0, FUN_1414a0de0, 94, 0xE4E04C53);

// @0x1414a0e40
void FUN_1414a0e40()
{
    if (DAT_143aab398 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_140166420();
        DAT_143aab398 = 0;
    }
}
MS2_REPLACE(0x1414A0E40, FUN_1414a0e40, 94, 0x202E0165);

// @0x1414a0ea0
void FUN_1414a0ea0()
{
    if (DAT_143ab3848 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_140953f20();
        DAT_143ab3848 = 0;
    }
}
MS2_REPLACE(0x1414A0EA0, FUN_1414a0ea0, 94, 0xB7401BE9);

// @0x1414a0f00
void FUN_1414a0f00()
{
    if (DAT_143aaece0 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_1403b4740();
        DAT_143aaece0 = 0;
    }
}
MS2_REPLACE(0x1414A0F00, FUN_1414a0f00, 94, 0xBDEB2E52);

// @0x1414a0f60
void FUN_1414a0f60()
{
    if (DAT_143ad8960 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_141371b20();
        DAT_143ad8960 = 0;
    }
}
MS2_REPLACE(0x1414A0F60, FUN_1414a0f60, 94, 0x48576B5C);

// @0x1414a0fc0
void FUN_1414a0fc0()
{
    if (DAT_143aad188 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_140302b00();
        DAT_143aad188 = 0;
    }
}
MS2_REPLACE(0x1414A0FC0, FUN_1414a0fc0, 94, 0xE6F93524);

// @0x1414a1020
void FUN_1414a1020()
{
    if (DAT_143ab3da8 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_1409a8b10();
        DAT_143ab3da8 = 0;
    }
}
MS2_REPLACE(0x1414A1020, FUN_1414a1020, 94, 0x9550C27E);

// @0x1414a1080
void FUN_1414a1080()
{
    if (DAT_143abafd8 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_140b2e980();
        DAT_143abafd8 = 0;
    }
}
MS2_REPLACE(0x1414A1080, FUN_1414a1080, 94, 0x3ED50C0D);

// @0x1414a10e0
void FUN_1414a10e0()
{
    if (DAT_143aac4d0 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_1401c0d90();
        DAT_143aac4d0 = 0;
    }
}
MS2_REPLACE(0x1414A10E0, FUN_1414a10e0, 94, 0x369666FE);

// @0x1414a1140
void FUN_1414a1140()
{
    if (DAT_143aad180 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_140302b10();
        DAT_143aad180 = 0;
    }
}
MS2_REPLACE(0x1414A1140, FUN_1414a1140, 94, 0x5ABEE7B5);

// @0x1414a11a0
void FUN_1414a11a0()
{
    if (DAT_143ab9658 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_140ae1c00();
        DAT_143ab9658 = 0;
    }
}
MS2_REPLACE(0x1414A11A0, FUN_1414a11a0, 94, 0xCE57F242);

// @0x1414a1200
void FUN_1414a1200()
{
    if (DAT_143ad8ba8 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_141484720();
        DAT_143ad8ba8 = 0;
    }
}
MS2_REPLACE(0x1414A1200, FUN_1414a1200, 94, 0xC35E3377);

// @0x1414a1260
void FUN_1414a1260()
{
    if (DAT_143ab3330 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_1409331e0();
        DAT_143ab3330 = 0;
    }
}
MS2_REPLACE(0x1414A1260, FUN_1414a1260, 94, 0x9D746BE4);

// @0x1414a12c0
void FUN_1414a12c0()
{
    if (DAT_143aaee00 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_1403ed290();
        DAT_143aaee00 = 0;
    }
}
MS2_REPLACE(0x1414A12C0, FUN_1414a12c0, 94, 0x02A9F0AB);

// @0x1414a1320
void FUN_1414a1320()
{
    if (DAT_143aaef58 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_1404f4530();
        DAT_143aaef58 = 0;
    }
}
MS2_REPLACE(0x1414A1320, FUN_1414a1320, 94, 0x70F05971);

// @0x1414a1380
void FUN_1414a1380()
{
    if (DAT_143aaecb0 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_1403a9410();
        DAT_143aaecb0 = 0;
    }
}
MS2_REPLACE(0x1414A1380, FUN_1414a1380, 94, 0xFA35C5CC);

// @0x1414a13e0
void FUN_1414a13e0()
{
    if (DAT_143aaf098 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_1412818c0();
        DAT_143aaf098 = 0;
    }
}
MS2_REPLACE(0x1414A13E0, FUN_1414a13e0, 94, 0x8254972E);

// @0x1414a1440
void FUN_1414a1440()
{
    if (DAT_143aaf1a8 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_14052d1d0();
        DAT_143aaf1a8 = 0;
    }
}
MS2_REPLACE(0x1414A1440, FUN_1414a1440, 94, 0x76043011);

// @0x1414a14a0
void FUN_1414a14a0()
{
    if (DAT_143abf720 != 0)
    {
        delete (Unk_SecondaryDtorSingleton*)FUN_140c8dac0();
        DAT_143abf720 = 0;
    }
}
MS2_REPLACE(0x1414A14A0, FUN_1414a14a0, 112, 0xD1224E15);

// @0x1414a1510
void FUN_1414a1510()
{
    if (DAT_143aaf1e0 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_140535300();
        DAT_143aaf1e0 = 0;
    }
}
MS2_REPLACE(0x1414A1510, FUN_1414a1510, 94, 0x2E8D4F9A);

// @0x1414a1570
void FUN_1414a1570()
{
    if (DAT_143aaf300 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_1409c4b20();
        DAT_143aaf300 = 0;
    }
}
MS2_REPLACE(0x1414A1570, FUN_1414a1570, 94, 0xAD79A55F);

// @0x1414a15d0
void FUN_1414a15d0()
{
    if (DAT_143aacd90 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_140281980();
        DAT_143aacd90 = 0;
    }
}
MS2_REPLACE(0x1414A15D0, FUN_1414a15d0, 94, 0xFA6A5F70);

// @0x1414a1630
void FUN_1414a1630()
{
    if (DAT_143aafb40 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_1409eece0();
        DAT_143aafb40 = 0;
    }
}
MS2_REPLACE(0x1414A1630, FUN_1414a1630, 94, 0xF129029F);

// @0x1414a1690
void FUN_1414a1690()
{
    if (DAT_143aafb50 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_1405934c0();
        DAT_143aafb50 = 0;
    }
}
MS2_REPLACE(0x1414A1690, FUN_1414a1690, 94, 0xE0C48CD7);

// @0x1414a16f0
void FUN_1414a16f0()
{
    if (DAT_143aaf1b0 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_14052d1e0();
        DAT_143aaf1b0 = 0;
    }
}
MS2_REPLACE(0x1414A16F0, FUN_1414a16f0, 94, 0x32423A9E);

// @0x1414a1750
void FUN_1414a1750()
{
    if (DAT_143aafb98 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_140f56960();
        DAT_143aafb98 = 0;
    }
}
MS2_REPLACE(0x1414A1750, FUN_1414a1750, 94, 0xC3EC3C3B);

// @0x1414a17b0
void FUN_1414a17b0()
{
    if (DAT_143aaf1b8 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_14052d1f0();
        DAT_143aaf1b8 = 0;
    }
}
MS2_REPLACE(0x1414A17B0, FUN_1414a17b0, 94, 0x5E92DE06);

// @0x1414a1810
void FUN_1414a1810()
{
    if (DAT_143aafd08 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_1405a96f0();
        DAT_143aafd08 = 0;
    }
}
MS2_REPLACE(0x1414A1810, FUN_1414a1810, 94, 0x9763F4D6);

// @0x1414a1870
void FUN_1414a1870()
{
    if (DAT_143aafd18 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_14062c280();
        DAT_143aafd18 = 0;
    }
}
MS2_REPLACE(0x1414A1870, FUN_1414a1870, 94, 0xFCC9E551);

// @0x1414a18d0
void FUN_1414a18d0()
{
    if (DAT_143aafd98 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_1409c4b30();
        DAT_143aafd98 = 0;
    }
}
MS2_REPLACE(0x1414A18D0, FUN_1414a18d0, 94, 0x28B27944);

// @0x1414a1930
void FUN_1414a1930()
{
    if (DAT_143ac1b80 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_1411f91b0();
        DAT_143ac1b80 = 0;
    }
}
MS2_REPLACE(0x1414A1930, FUN_1414a1930, 94, 0x643605B0);

// @0x1414a1990
void FUN_1414a1990()
{
    if (DAT_143aaf308 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_140535310();
        DAT_143aaf308 = 0;
    }
}
MS2_REPLACE(0x1414A1990, FUN_1414a1990, 94, 0x29EECA1E);

// @0x1414a19f0
void FUN_1414a19f0()
{
    if (DAT_143aafde0 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_1409eecf0();
        DAT_143aafde0 = 0;
    }
}
MS2_REPLACE(0x1414A19F0, FUN_1414a19f0, 94, 0x0A71209E);

// @0x1414a1a50
void FUN_1414a1a50()
{
    if (DAT_143aab4f8 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_140166430();
        DAT_143aab4f8 = 0;
    }
}
MS2_REPLACE(0x1414A1A50, FUN_1414a1a50, 94, 0x3B2AB468);

// @0x1414a1ab0
void FUN_1414a1ab0()
{
    if (DAT_143aaff58 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_140f64150();
        DAT_143aaff58 = 0;
    }
}
MS2_REPLACE(0x1414A1AB0, FUN_1414a1ab0, 94, 0x37F4881A);

// @0x1414a1b10
void FUN_1414a1b10()
{
    if (DAT_143aaff10 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_1409eed00();
        DAT_143aaff10 = 0;
    }
}
MS2_REPLACE(0x1414A1B10, FUN_1414a1b10, 94, 0x164B42F5);

// @0x1414a1b70
void FUN_1414a1b70()
{
    if (DAT_143aaffd8 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_140f688a0();
        DAT_143aaffd8 = 0;
    }
}
MS2_REPLACE(0x1414A1B70, FUN_1414a1b70, 94, 0xE10587C9);

// @0x1414a1bd0
void FUN_1414a1bd0()
{
    if (DAT_143aaf1c0 != 0)
    {
        delete (Unk_VirtualDtor*)FUN_14052d200();
        DAT_143aaf1c0 = 0;
    }
}
MS2_REPLACE(0x1414A1BD0, FUN_1414a1bd0, 94, 0x927F4412);
