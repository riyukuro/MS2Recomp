// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASVideoPlayer, the ActionScript video player clip wrapper of the
// GFx UI library (declared as Unk_ASVideoPlayer in src/ms2/placeholder/uivideocontents.h, the name its callers use).
// MS2-UNIT: ?\asvideoplayer.cpp
// MS2-RANGE: 0x1422e92e0-0x1422e9a40 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). The
// four empty / constant members 0x1422e9440-0x1422e9480 are what the exe has between the "scaleMode" and "volume"
// accessors. The unsigned setSize / setScale go through the unsigned two-argument Invoke 0x140acd070 (ascript.h
// declares it as Invoke(const char*, int, int)).
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/uivideocontents.h"

#include "hook/ms2hook.h"

// @0x1422e92e0
Unk_ASVideoPlayer::Unk_ASVideoPlayer(const Scaleform::GFx::Value& v, int nMovieId)
    : ASVideo(v, nMovieId)
{
}

// @0x1422e9330
Unk_ASVideoPlayer::~Unk_ASVideoPlayer()
{
}

// @0x1422e9360
void Unk_ASVideoPlayer::FUN_1422e9360(const CString& strMode)
{
    FUN_1407cba60("scaleMode", strMode);
}
MS2_REPLACE_METHOD(0x1422E9360, Unk_ASVideoPlayer, FUN_1422e9360, 72, 0x1D863DFF);

// @0x1422e93b0
CString Unk_ASVideoPlayer::FUN_1422e93b0()
{
    return FUN_1422baa20("scaleMode").GetString();
}
MS2_REPLACE_METHOD(0x1422E93B0, Unk_ASVideoPlayer, FUN_1422e93b0, 123, 0xFB2B0BF2);

// @0x1422e9440
void Unk_ASVideoPlayer::FUN_1422e9440(int n)
{
}

// @0x1422e9450
int Unk_ASVideoPlayer::FUN_1422e9450()
{
    return 0;
}

// @0x1422e9460
void Unk_ASVideoPlayer::FUN_1422e9460(float f)
{
}

// @0x1422e9480
float Unk_ASVideoPlayer::FUN_1422e9480()
{
    return 0.0f;
}

// @0x1422e9490
void Unk_ASVideoPlayer::FUN_1422e9490(float fVolume)
{
    FUN_1409c4a30("volume", fVolume);
}
MS2_REPLACE_METHOD(0x1422E9490, Unk_ASVideoPlayer, FUN_1422e9490, 43, 0x955DA732);

// @0x1422e94d0
float Unk_ASVideoPlayer::FUN_1422e94d0()
{
    return (float)FUN_1422baa20("volume").GetNumber();
}
MS2_REPLACE_METHOD(0x1422E94D0, Unk_ASVideoPlayer, FUN_1422e94d0, 96, 0xFD47CBEC);

// @0x1422e9540
float Unk_ASVideoPlayer::FUN_1422e9540()
{
    return (float)FUN_1422baa20("time").GetNumber();
}
MS2_REPLACE_METHOD(0x1422E9540, Unk_ASVideoPlayer, FUN_1422e9540, 96, 0xB48BC3FE);

// @0x1422e95b0
void Unk_ASVideoPlayer::FUN_1422e95b0(const CString& strPath)
{
    Invoke("play", strPath);
}
MS2_REPLACE_METHOD(0x1422E95B0, Unk_ASVideoPlayer, FUN_1422e95b0, 87, 0xAE7AB17C);

// @0x1422e9610
void Unk_ASVideoPlayer::FUN_1422e9610()
{
    Invoke("rePlay");
}
MS2_REPLACE_METHOD(0x1422E9610, Unk_ASVideoPlayer, FUN_1422e9610, 46, 0x9E0E218C);

// @0x1422e9650
void Unk_ASVideoPlayer::FUN_1422e9650()
{
    Invoke("stop");
}
MS2_REPLACE_METHOD(0x1422E9650, Unk_ASVideoPlayer, FUN_1422e9650, 46, 0x7E914F1C);

// @0x1422e9690
void Unk_ASVideoPlayer::FUN_1422e9690(float fTime)
{
    Invoke("seek", fTime);
}
MS2_REPLACE_METHOD(0x1422E9690, Unk_ASVideoPlayer, FUN_1422e9690, 58, 0xA8F19610);

// @0x1422e96d0
void Unk_ASVideoPlayer::FUN_1422e96d0()
{
    Invoke("pause");
}
MS2_REPLACE_METHOD(0x1422E96D0, Unk_ASVideoPlayer, FUN_1422e96d0, 46, 0x614CB80C);

// @0x1422e9710
int Unk_ASVideoPlayer::FUN_1422e9710()
{
    return Invoke("isPlay").GetBool();
}
MS2_REPLACE_METHOD(0x1422E9710, Unk_ASVideoPlayer, FUN_1422e9710, 91, 0x47E6A167);

// @0x1422e9780
void Unk_ASVideoPlayer::FUN_1422e9780(int bLoop)
{
    FUN_1409ba030("setLoop", bLoop);
}
MS2_REPLACE_METHOD(0x1422E9780, Unk_ASVideoPlayer, FUN_1422e9780, 55, 0x5B74F970);

// @0x1422e97c0
void Unk_ASVideoPlayer::FUN_1422e97c0(int nWidth, int nHeight)
{
    FUN_1409ba0d0("setAspectRatio", nWidth, nHeight);
}
MS2_REPLACE_METHOD(0x1422E97C0, Unk_ASVideoPlayer, FUN_1422e97c0, 68, 0x52E7E502);

// @0x1422e9810
void Unk_ASVideoPlayer::FUN_1422e9810(int nWidth, int nHeight)
{
    FUN_1409ba0d0("setSize", nWidth, nHeight);
}
MS2_REPLACE_METHOD(0x1422E9810, Unk_ASVideoPlayer, FUN_1422e9810, 68, 0x60807F15);

// @0x1422e9860
void Unk_ASVideoPlayer::FUN_1422e9860(unsigned nWidth, unsigned nHeight)
{
    Invoke("setSize", (int)nWidth, (int)nHeight);
}
MS2_REPLACE_METHOD(0x1422E9860, Unk_ASVideoPlayer, FUN_1422e9860, 68, 0x8761DC47);

// @0x1422e98b0
void Unk_ASVideoPlayer::FUN_1422e98b0(float fWidth, float fHeight)
{
    FUN_140e5bf20("setSize", fWidth, fHeight);
}
MS2_REPLACE_METHOD(0x1422E98B0, Unk_ASVideoPlayer, FUN_1422e98b0, 76, 0xB8AD68EE);

// @0x1422e9910
void Unk_ASVideoPlayer::FUN_1422e9910(int nX, int nY)
{
    FUN_1409ba0d0("setScale", nX, nY);
}
MS2_REPLACE_METHOD(0x1422E9910, Unk_ASVideoPlayer, FUN_1422e9910, 68, 0x094A7D9E);

// @0x1422e9960
void Unk_ASVideoPlayer::FUN_1422e9960(unsigned nX, unsigned nY)
{
    Invoke("setScale", (int)nX, (int)nY);
}
MS2_REPLACE_METHOD(0x1422E9960, Unk_ASVideoPlayer, FUN_1422e9960, 68, 0x5DCC61CE);

// @0x1422e99b0
void Unk_ASVideoPlayer::FUN_1422e99b0(float fX, float fY)
{
    FUN_140e5bf20("setScale", fX, fY);
}
MS2_REPLACE_METHOD(0x1422E99B0, Unk_ASVideoPlayer, FUN_1422e99b0, 76, 0x47D95E0F);

// MS2-PIN: ??_GUnk_ASVideoPlayer@@UEAAPEAXI@Z 0x1422e9a00
// MS2-PIN: ??_7Unk_ASVideoPlayer@@6B@ 0x143116770
