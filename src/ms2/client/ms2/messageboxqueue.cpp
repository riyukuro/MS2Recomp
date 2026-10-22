// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The message box queue: boxes that cannot be shown yet
// wait in a locked list until the UIMessageBox layer (UI id 0x4e48) is free.
// MS2-UNIT: ?\messageboxqueue.cpp
// MS2-RANGE: 0x14151f150-0x141520680 .text$mn
// MS2-RANGE: 0x1400f9ac0-0x1400f9b20 .text$di
// MS2-RANGE: 0x142cb3400-0x142cb3440 .text$yd
// The first obj inside the units.tsv range of client\ms2\mypc.cpp (its own COMDAT tail ends with memmove_s at
// 0x141520560, MyPC::MyPC starts the next obj at 0x141520680). CU name assumed; function names are the exe VAs.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\messageboxqueue.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/client/ms2/uimessagebox.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Scoped lock (ctor 0x1401b4ec0, dtor 0x1401b5120).
class Unk_1401b4ec0 { public: Unk_1401b4ec0(CLockCriticalSection&, int); ~Unk_1401b4ec0(); private: void* m_p; };

// The UI manager (singleton behind FUN_1403ed2b0): a dialog by its UI id.
class Unk_MsgQueueUIMgr
{
public:
    MS2Ptr<UIObject> FUN_141adcea0(int nId);
};
Unk_MsgQueueUIMgr* FUN_1403ed2b0();

UIMessageBox* FUN_14151f890();
int FUN_14151fad0(MS2Ptr<CMsgBoxData> spData);
MS2Ptr<CMsgBoxData> FUN_14151f820();
void FUN_14151fb60(CStringW strTag, MS2Ptr<CMsgBoxData> spData);
UIMessageBox* FUN_14151fcb0(int nId);

static CLockCriticalSection s_lock;                                         // @0x1400f9ac0
static ATL::CAtlList<MS2Ptr<CMsgBoxData> > s_queue(10);                     // @0x1400f9af0

// Show spData now; a box it replaces goes back to the queue.
// @0x14151f150
void FUN_14151f150(MS2Ptr<CMsgBoxData> spData)
{
    Unk_1401b4ec0 lock(s_lock, 1);
    MS2Ptr<CMsgBoxData> spCur = FUN_14151f820();
    if (FUN_14151fad0(spData) != 0)
    {
        if (spCur.get() != 0)
            s_queue.AddTail(spCur);
    }
}

// Show the newest queued box whose countdown is still running; close the layer when none is left.
// @0x14151f200
void FUN_14151f200()
{
    Unk_1401b4ec0 lock(s_lock, 1);
    if (s_queue.IsEmpty())
    {
        UIMessageBox* pBox = FUN_14151f890();
        if (pBox != 0)
            pBox->FUN_1419f8120();
        return;
    }
    MS2Ptr<CMsgBoxData> spData = s_queue.RemoveTail();
    while (spData.get() != 0)
    {
        if (spData->FUN_141a04900() != 0)
        {
            if (FUN_14151fad0(spData) != 0)
                return;
        }
        else if (spData->FUN_141a049a0() != 0)
        {
            spData->FUN_141a04a30();
        }
        spData = s_queue.IsEmpty() ? MS2Ptr<CMsgBoxData>(0) : s_queue.RemoveTail();
    }
    if (spData.IsNull())
    {
        UIMessageBox* pBox = FUN_14151f890();
        if (pBox != 0)
            pBox->FUN_1419f8120();
    }
}

// Drop the queue and close every box with nResult.
// @0x14151f460
void FUN_14151f460(int nResult)
{
    Unk_1401b4ec0 lock(s_lock, 1);
    s_queue.RemoveAll();
    UIMessageBox* pBox = FUN_14151f890();
    if (pBox != 0)
    {
        if (pBox->FUN_1419f8270() == 0)
            pBox->FUN_1419f8170(nResult);
    }
}

// Show spData when the layer is idle, or replace the queued box with the same tag.
// @0x14151f4e0
void FUN_14151f4e0(CStringW strTag, MS2Ptr<CMsgBoxData> spData)
{
    UIMessageBox* pBox = FUN_14151f890();
    if (pBox == 0)
        return;
    MS2Ptr<CMsgBoxData> spCur = pBox->FUN_1419f8470();
    if (spCur == 0 || spCur->FUN_141a02b90() != strTag)
    {
        FUN_14151fb60(strTag, spData);
        return;
    }
    pBox->FUN_1419f81f0(spData);
}

// No box is shown.
// @0x14151f6e0
int FUN_14151f6e0()
{
    UIMessageBox* pBox = FUN_14151f890();
    if (pBox != 0)
        return pBox->FUN_1419f8270();
    return 1;
}
MS2_REPLACE(0x14151F6E0, FUN_14151f6e0, 44, 0xD5CDF260);

// Remove spData from the queue.
// @0x14151f720
void FUN_14151f720(MS2Ptr<CMsgBoxData> spData)
{
    Unk_1401b4ec0 lock(s_lock, 1);
    for (POSITION pos = s_queue.GetHeadPosition(); pos != 0; s_queue.GetNext(pos))
    {
        MS2Ptr<CMsgBoxData> spItem = s_queue.GetAt(pos);
        if (spItem == spData.get())
        {
            s_queue.RemoveAt(pos);
            return;
        }
    }
}

// The box currently shown (null without the layer).
// @0x14151f820
MS2Ptr<CMsgBoxData> FUN_14151f820()
{
    UIMessageBox* pBox = FUN_14151f890();
    if (pBox != 0)
        return pBox->FUN_1419f8470();
    return MS2Ptr<CMsgBoxData>(0);
}
MS2_REPLACE(0x14151F820, FUN_14151f820, 101, 0x20BC56CE);

// The message box layer.
// @0x14151f890
UIMessageBox* FUN_14151f890()
{
    return FUN_14151fcb0(0x4e48);
}
MS2_REPLACE(0x14151F890, FUN_14151f890, 19, 0x2C2012DD);

// Every queued box passes FUN_141a03050.
// @0x14151f8b0
int FUN_14151f8b0()
{
    Unk_1401b4ec0 lock(s_lock, 1);
    if (!s_queue.IsEmpty())
    {
        for (POSITION pos = s_queue.GetHeadPosition(); pos != 0; s_queue.GetNext(pos))
        {
            MS2Ptr<CMsgBoxData> spItem = s_queue.GetAt(pos);
            if (spItem.get() != 0)
            {
                if (!spItem->FUN_141a03050())
                    return 0;
            }
        }
    }
    return 1;
}

// Every queued box passes FUN_141a03070.
// @0x14151f9c0
int FUN_14151f9c0()
{
    Unk_1401b4ec0 lock(s_lock, 1);
    if (!s_queue.IsEmpty())
    {
        for (POSITION pos = s_queue.GetHeadPosition(); pos != 0; s_queue.GetNext(pos))
        {
            MS2Ptr<CMsgBoxData> spItem = s_queue.GetAt(pos);
            if (spItem.get() != 0)
            {
                if (!spItem->IsModaless())
                    return 0;
            }
        }
    }
    return 1;
}

// Show spData now (0 without the layer).
// @0x14151fad0
int FUN_14151fad0(MS2Ptr<CMsgBoxData> spData)
{
    UIMessageBox* pBox = FUN_14151f890();
    if (pBox != 0)
        return pBox->FUN_1419f7ff0(spData);
    return 0;
}
MS2_REPLACE(0x14151FAD0, FUN_14151fad0, 128, 0x35EF421F);

// Replace the queued box tagged strTag with spData.
// @0x14151fb60
void FUN_14151fb60(CStringW strTag, MS2Ptr<CMsgBoxData> spData)
{
    Unk_1401b4ec0 lock(s_lock, 1);
    for (POSITION pos = s_queue.GetHeadPosition(); pos != 0; s_queue.GetNext(pos))
    {
        MS2Ptr<CMsgBoxData> spItem = s_queue.GetAt(pos);
        if (spItem.get() != 0)
        {
            if (spItem->FUN_141a02b90() == strTag)
            {
                s_queue.SetAt(pos, spData);
                return;
            }
        }
    }
}

// A dialog by UI id, as a message box layer.
// @0x14151fcb0
UIMessageBox* FUN_14151fcb0(int nId)
{
    if (FUN_1403ed2b0() != 0)
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (p.get() != 0)
            return dynamic_cast<UIMessageBox*>((UIObject*)p);
    }
    return 0;
}
MS2_REPLACE(0x14151FCB0, FUN_14151fcb0, 147, 0xF40E6F7E);

MS2_EMIT_CRT_MEMMOVE_S();
