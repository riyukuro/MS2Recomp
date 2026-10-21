// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). FieldProperty and its subclasses (server-side record: serialisation + type id).
// MS2-UNIT: ?\fieldproperty.cpp
// MS2-RANGE: 0x140380840-0x1403820e0 .text$mn
// MS2-PIN: ??_GFieldProperty@@UEAAPEAXI@Z 0x140381de0
// MS2-PIN: ??_GFieldPropertyHideMyPC@@UEAAPEAXI@Z 0x140381f20
// MS2-PIN: ??_GFieldPropertyLockMyPC@@UEAAPEAXI@Z 0x140381f60
// MS2-PIN: ??_GFieldPropertySightRange@@UEAAPEAXI@Z 0x140382020
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\fieldproperty.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2layout.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/fieldproperty.h"

// ---- unrecovered neighbours: the packet writer / reader primitives ---------------------------------------------------
void FUN_14070fa60(Unk_PktOut*, float);                 // write float
void FUN_14070f820(Unk_PktOut*, unsigned char);         // write byte
void FUN_14070f860(Unk_PktOut*, unsigned char);         // write byte (second flavour)
void FUN_14070f9e0(Unk_PktOut*, __int64);               // write int64
void FUN_14070f920(Unk_PktOut*, int);                   // write int
void FUN_1406c3700(Unk_Rgb3b*);                          // Unk_Rgb3b default init (zero)
void FUN_14070fae0(Unk_PktOut*, CStringW*);             // write wide string
void FUN_1406c38b0(Unk_PktOut*, Unk_Rgb3b*);            // write rgb
void FUN_14070f540(Unk_PktStream*, float*);             // read float
void FUN_14070f300(Unk_PktStream*, unsigned char*);     // read byte
void FUN_14070f340(Unk_PktStream*, unsigned char*);     // read byte (second flavour)
void FUN_14070f4c0(Unk_PktStream*, __int64*);           // read int64
void FUN_14070f400(Unk_PktStream*, int*);               // read int
void FUN_14070f5f0(Unk_PktStream*, CStringW*);          // read wide string
void FUN_1406c3850(Unk_PktStream*, Unk_Rgb3b*);         // read rgb

// @0x140380840
FieldProperty::FieldProperty() {}

// @0x140380880
void FieldProperty::vfunc_1(Unk_PktOut* out) {}

// @0x1403808a0
void FieldProperty::vfunc_2(Unk_PktIn* in) {}

// @0x1403808c0
void FieldProperty::vfunc_4() {}

// @0x1403808d0
void FieldProperty::vfunc_5() {}

// @0x1403808e0
FieldPropertyGravity::FieldPropertyGravity() { m_fGravity = 0; }

// @0x140380920
FieldPropertyGravity::FieldPropertyGravity(float fGravity) { m_fGravity = fGravity; }

// @0x140380970
void FieldPropertyGravity::vfunc_1(Unk_PktOut* out)
{
    FieldProperty::vfunc_1(out);
    FUN_14070fa60(out, m_fGravity);
}

// @0x1403809b0
void FieldPropertyGravity::vfunc_2(Unk_PktIn* in)
{
    FieldProperty::vfunc_2(in);
    FUN_14070f540(&in->m_stream, &m_fGravity);
}

// @0x140380a00
int FieldPropertyGravity::vfunc_3() { return 1; }

// @0x140380a20
FieldPropertyMusicConcert::FieldPropertyMusicConcert() { m_i64 = 0; m_n = 0; }

// @0x140380a70
FieldPropertyMusicConcert::FieldPropertyMusicConcert(__int64 a, int b) { m_i64 = a; m_n = b; }

// @0x140380ad0
void FieldPropertyMusicConcert::vfunc_1(Unk_PktOut* out)
{
    FieldProperty::vfunc_1(out);
    FUN_14070f9e0(out, m_i64);
    FUN_14070f920(out, m_n);
}

// @0x140380b20
void FieldPropertyMusicConcert::vfunc_2(Unk_PktIn* in)
{
    FieldProperty::vfunc_2(in);
    FUN_14070f4c0(&in->m_stream, &m_i64);
    FUN_14070f400(&in->m_stream, &m_n);
}

// @0x140380b80
int FieldPropertyMusicConcert::vfunc_3() { return 2; }

// @0x140380ba0
FieldPropertyHideMyPC::FieldPropertyHideMyPC() {}

// @0x140380be0
void FieldPropertyHideMyPC::vfunc_1(Unk_PktOut* out) { FieldProperty::vfunc_1(out); }

// @0x140380c10
void FieldPropertyHideMyPC::vfunc_2(Unk_PktIn* in) { FieldProperty::vfunc_2(in); }

// @0x140380c40
int FieldPropertyHideMyPC::vfunc_3() { return 3; }

// @0x140380c60
FieldPropertyLockMyPC::FieldPropertyLockMyPC() {}

// @0x140380ca0
void FieldPropertyLockMyPC::vfunc_1(Unk_PktOut* out) { FieldProperty::vfunc_1(out); }

// @0x140380cd0
void FieldPropertyLockMyPC::vfunc_2(Unk_PktIn* in) { FieldProperty::vfunc_2(in); }

// @0x140380d00
int FieldPropertyLockMyPC::vfunc_3() { return 4; }

// @0x140380d20
FieldPropertyUserTagSymbol::FieldPropertyUserTagSymbol() {}

// @0x140380d80
FieldPropertyUserTagSymbol::FieldPropertyUserTagSymbol(CStringW a, CStringW b) : m_strA(a), m_strB(b) {}

// @0x140380e10
void FieldPropertyUserTagSymbol::vfunc_1(Unk_PktOut* out)
{
    FieldProperty::vfunc_1(out);
    FUN_14070fae0(out, &m_strA);
    FUN_14070fae0(out, &m_strB);
}

// @0x140380e70
void FieldPropertyUserTagSymbol::vfunc_2(Unk_PktIn* in)
{
    FieldProperty::vfunc_2(in);
    FUN_14070f5f0(&in->m_stream, &m_strA);
    FUN_14070f5f0(&in->m_stream, &m_strB);
}

// @0x140380ed0
int FieldPropertyUserTagSymbol::vfunc_3() { return 5; }

// @0x140380ef0
FieldPropertySightRange::FieldPropertySightRange()
{
    m_f18 = 60000.0f;
    m_f1c = 30000.0f;
    m_f20 = 30000.0f;
    m_f24 = 115.0f;
    m_b28 = 1;
    m_b29 = 45;
    m_b2a = 0;
}

// @0x140380f90
FieldPropertySightRange::FieldPropertySightRange(float fRange)
{
    m_f18 = fRange;
    m_f1c = fRange;
    m_f20 = fRange;
    m_f24 = 115.0f;
    m_b28 = 1;
    m_b29 = 45;
    m_b2a = 0;
}

// @0x140381030
FieldPropertySightRange::FieldPropertySightRange(float a, float b, float c, float d, unsigned char e, unsigned char f, unsigned char g)
{
    m_f18 = a;
    m_f1c = b;
    m_f20 = c;
    m_f24 = d;
    m_b28 = e;
    m_b29 = f;
    m_b2a = g;
}

// @0x1403810e0
void FieldPropertySightRange::vfunc_1(Unk_PktOut* out)
{
    FieldProperty::vfunc_1(out);
    FUN_14070fa60(out, m_f18);
    FUN_14070fa60(out, m_f1c);
    FUN_14070fa60(out, m_f20);
    FUN_14070fa60(out, m_f24);
    FUN_14070f820(out, m_b28);
    FUN_14070f860(out, m_b29);
    FUN_14070f820(out, m_b2a);
}

// @0x1403811a0
void FieldPropertySightRange::vfunc_2(Unk_PktIn* in)
{
    FieldProperty::vfunc_2(in);
    FUN_14070f540(&in->m_stream, &m_f18);
    FUN_14070f540(&in->m_stream, &m_f1c);
    FUN_14070f540(&in->m_stream, &m_f20);
    FUN_14070f540(&in->m_stream, &m_f24);
    FUN_14070f300(&in->m_stream, &m_b28);
    FUN_14070f340(&in->m_stream, &m_b29);
    FUN_14070f300(&in->m_stream, &m_b2a);
}

// @0x140381280
int FieldPropertySightRange::vfunc_3() { return 6; }

// @0x1403812a0   SightRange accessors
float FUN_1403812a0(FieldPropertySightRange* p) { return p->m_f18; }
// @0x1403812c0
float FUN_1403812c0(FieldPropertySightRange* p) { return p->m_f1c; }
// @0x1403812e0
float FUN_1403812e0(FieldPropertySightRange* p) { return p->m_f20; }
// @0x140381300
float FUN_140381300(FieldPropertySightRange* p) { return p->m_f24; }
// @0x140381320
unsigned char FUN_140381320(FieldPropertySightRange* p) { return p->m_b28; }
// @0x140381340
float FUN_140381340(FieldPropertySightRange* p) { return (float)p->m_b29 * 0.01f; }
// @0x140381370
unsigned char FUN_140381370(FieldPropertySightRange* p) { return p->m_b2a; }

// @0x140381390
FieldPropertyWeather::FieldPropertyWeather() { m_nWeather = 0; }

// @0x1403813d0
FieldPropertyWeather::FieldPropertyWeather(int nWeather) { m_nWeather = nWeather; }

// @0x140381420
void FieldPropertyWeather::vfunc_1(Unk_PktOut* out)
{
    FieldProperty::vfunc_1(out);
    out->WriteU8(m_nWeather);
}

// @0x140381470
void FieldPropertyWeather::vfunc_2(Unk_PktIn* in)
{
    FieldProperty::vfunc_2(in);
    m_nWeather = (&in->m_stream)->ReadU8();
}

// @0x1403814d0
int FieldPropertyWeather::vfunc_3() { return 7; }

// @0x1403814f0
int FUN_1403814f0(FieldPropertyWeather* p) { return p->m_nWeather; }

// @0x140381510
FieldPropertyAmbientLight::FieldPropertyAmbientLight() { FUN_1406c3700(&m_color); m_bFlag = false; m_fValue = 0; }

// @0x140381580
FieldPropertyAmbientLight::FieldPropertyAmbientLight(const Unk_Rgb3b& color, bool bFlag, float fValue)
{
    m_color = color;
    m_bFlag = bFlag;
    m_fValue = fValue;
}

// @0x140381600
void FieldPropertyAmbientLight::vfunc_1(Unk_PktOut* out)
{
    FieldProperty::vfunc_1(out);
    FUN_1406c38b0(out, &m_color);
    FUN_14070f820(out, m_bFlag);
    FUN_14070fa60(out, m_fValue);
}

// @0x140381670
void FieldPropertyAmbientLight::vfunc_2(Unk_PktIn* in)
{
    FieldProperty::vfunc_2(in);
    FUN_1406c3850(&in->m_stream, &m_color);
    FUN_14070f300(&in->m_stream, (unsigned char*)&m_bFlag);
    FUN_14070f540(&in->m_stream, &m_fValue);
}

// @0x1403816f0
int FieldPropertyAmbientLight::vfunc_3() { return 8; }

// @0x140381710
bool FUN_140381710(FieldPropertyAmbientLight* p) { return p->m_bFlag; }

// @0x140381730
float FUN_140381730(FieldPropertyAmbientLight* p) { return p->m_fValue; }

// @0x140381750
FieldPropertyDirectionalLight::FieldPropertyDirectionalLight() { FUN_1406c3700(&m_color1); FUN_1406c3700(&m_color2); m_bFlag = false; m_fValue = 0; }

// @0x1403817d0
FieldPropertyDirectionalLight::FieldPropertyDirectionalLight(const Unk_Rgb3b& c1, const Unk_Rgb3b& c2, bool bFlag, float fValue)
{
    m_color1 = c1;
    m_color2 = c2;
    m_bFlag = bFlag;
    m_fValue = fValue;
}

// @0x140381860
void FieldPropertyDirectionalLight::vfunc_1(Unk_PktOut* out)
{
    FieldProperty::vfunc_1(out);
    FUN_1406c38b0(out, &m_color1);
    FUN_1406c38b0(out, &m_color2);
    FUN_14070f820(out, m_bFlag);
    FUN_14070fa60(out, m_fValue);
}

// @0x1403818e0
void FieldPropertyDirectionalLight::vfunc_2(Unk_PktIn* in)
{
    FieldProperty::vfunc_2(in);
    FUN_1406c3850(&in->m_stream, &m_color1);
    FUN_1406c3850(&in->m_stream, &m_color2);
    FUN_14070f300(&in->m_stream, (unsigned char*)&m_bFlag);
    FUN_14070f540(&in->m_stream, &m_fValue);
}

// @0x140381970
int FieldPropertyDirectionalLight::vfunc_3() { return 9; }

// @0x140381990
bool FUN_140381990(FieldPropertyDirectionalLight* p) { return p->m_bFlag; }

// @0x1403819b0
float FUN_1403819b0(FieldPropertyDirectionalLight* p) { return p->m_fValue; }

// @0x1403819d0
FieldPropertyEnableLocalCamera::FieldPropertyEnableLocalCamera() { m_b = false; }

// @0x140381a10
FieldPropertyEnableLocalCamera::FieldPropertyEnableLocalCamera(bool b) { m_b = b; }

// @0x140381a60
void FieldPropertyEnableLocalCamera::vfunc_1(Unk_PktOut* out)
{
    FieldProperty::vfunc_1(out);
    FUN_14070f820(out, m_b);
}

// @0x140381aa0
void FieldPropertyEnableLocalCamera::vfunc_2(Unk_PktIn* in)
{
    FieldProperty::vfunc_2(in);
    FUN_14070f300(&in->m_stream, (unsigned char*)&m_b);
}

// @0x140381af0
int FieldPropertyEnableLocalCamera::vfunc_3() { return 10; }

// @0x140381b10
FieldPropertyPhotoStudio::FieldPropertyPhotoStudio() { m_b = false; }

// @0x140381b50
FieldPropertyPhotoStudio::FieldPropertyPhotoStudio(bool b) { m_b = b; }

// @0x140381ba0
void FieldPropertyPhotoStudio::vfunc_1(Unk_PktOut* out)
{
    FieldProperty::vfunc_1(out);
    FUN_14070f820(out, m_b);
}

// @0x140381be0
void FieldPropertyPhotoStudio::vfunc_2(Unk_PktIn* in)
{
    FieldProperty::vfunc_2(in);
    FUN_14070f300(&in->m_stream, (unsigned char*)&m_b);
}

// @0x140381c30
int FieldPropertyPhotoStudio::vfunc_3() { return 11; }

// ---- destructors: the exe's bodies only call the base destructor (no vptr store), so they are written as free functions
// bound to the class dtor symbols through progress/symbols-manual.tsv.
// @0x140381c40
void FUN_140381c40(FieldProperty* p) { p->CPtred::~CPtred(); }
// @0x140381c60
void FUN_140381c60(FieldPropertyAmbientLight* p) { p->FieldProperty::~FieldProperty(); }
// @0x140381c80
void FUN_140381c80(FieldPropertyDirectionalLight* p) { p->FieldProperty::~FieldProperty(); }
// @0x140381ca0
void FUN_140381ca0(FieldPropertyEnableLocalCamera* p) { p->FieldProperty::~FieldProperty(); }
// @0x140381cc0
void FUN_140381cc0(FieldPropertyGravity* p) { p->FieldProperty::~FieldProperty(); }
// @0x140381ce0
void FUN_140381ce0(FieldPropertyHideMyPC* p) { p->FieldProperty::~FieldProperty(); }
// @0x140381d00
void FUN_140381d00(FieldPropertyLockMyPC* p) { p->FieldProperty::~FieldProperty(); }
// @0x140381d20
void FUN_140381d20(FieldPropertyMusicConcert* p) { p->FieldProperty::~FieldProperty(); }
// @0x140381d40
void FUN_140381d40(FieldPropertyPhotoStudio* p) { p->FieldProperty::~FieldProperty(); }
// @0x140381d60
void FUN_140381d60(FieldPropertySightRange* p) { p->FieldProperty::~FieldProperty(); }
// @0x140381d80
// MS2-FUNCTIONAL: CStringW dtor call encoding differs
void FUN_140381d80(FieldPropertyUserTagSymbol* p)
{
    p->m_strB.~CStringW();
    p->m_strA.~CStringW();
    p->FieldProperty::~FieldProperty();
}
// @0x140381dc0
void FUN_140381dc0(FieldPropertyWeather* p) { p->FieldProperty::~FieldProperty(); }

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE_METHOD(0x140380880, FieldProperty, vfunc_1, 11, 0x02239C70);
MS2_REPLACE_METHOD(0x1403808a0, FieldProperty, vfunc_2, 11, 0x02239C70);
MS2_REPLACE_METHOD(0x1403808c0, FieldProperty, vfunc_4, 6, 0xA9AF6E37);
MS2_REPLACE_METHOD(0x1403808d0, FieldProperty, vfunc_5, 6, 0xA9AF6E37);
MS2_REPLACE_METHOD(0x140380970, FieldPropertyGravity, vfunc_1, 54, 0xE67D87DC);
MS2_REPLACE_METHOD(0x1403809b0, FieldPropertyGravity, vfunc_2, 60, 0x04E593FF);
MS2_REPLACE_METHOD(0x140380a00, FieldPropertyGravity, vfunc_3, 11, 0x30025ED0);
MS2_REPLACE_METHOD(0x140380ad0, FieldPropertyMusicConcert, vfunc_1, 71, 0x3A115D9C);
MS2_REPLACE_METHOD(0x140380b20, FieldPropertyMusicConcert, vfunc_2, 86, 0xC697BAFF);
MS2_REPLACE_METHOD(0x140380b80, FieldPropertyMusicConcert, vfunc_3, 11, 0x620C90F9);
MS2_REPLACE_METHOD(0x140380be0, FieldPropertyHideMyPC, vfunc_1, 34, 0x2E3016A5);
MS2_REPLACE_METHOD(0x140380c10, FieldPropertyHideMyPC, vfunc_2, 34, 0x58FF6875);
MS2_REPLACE_METHOD(0x140380c40, FieldPropertyHideMyPC, vfunc_3, 11, 0xA6B3D596);
MS2_REPLACE_METHOD(0x140380ca0, FieldPropertyLockMyPC, vfunc_1, 34, 0xE157C8DA);
MS2_REPLACE_METHOD(0x140380cd0, FieldPropertyLockMyPC, vfunc_2, 34, 0xAB53A4AA);
MS2_REPLACE_METHOD(0x140380d00, FieldPropertyLockMyPC, vfunc_3, 11, 0x85F76FBF);
MS2_REPLACE_METHOD(0x140380e10, FieldPropertyUserTagSymbol, vfunc_1, 78, 0x4A48A9D5);
MS2_REPLACE_METHOD(0x140380e70, FieldPropertyUserTagSymbol, vfunc_2, 86, 0xBA44733D);
MS2_REPLACE_METHOD(0x140380ed0, FieldPropertyUserTagSymbol, vfunc_3, 11, 0xCA9EB45C);
MS2_REPLACE_METHOD(0x1403810e0, FieldPropertySightRange, vfunc_1, 171, 0x6267A61D);
MS2_REPLACE_METHOD(0x1403811a0, FieldPropertySightRange, vfunc_2, 216, 0xEEF83217);
MS2_REPLACE_METHOD(0x140381280, FieldPropertySightRange, vfunc_3, 11, 0xFCA8E685);
MS2_REPLACE(0x1403812a0, FUN_1403812a0, 16, 0x3C5A885E);
MS2_REPLACE(0x1403812c0, FUN_1403812c0, 16, 0x5463A882);
MS2_REPLACE(0x1403812e0, FUN_1403812e0, 16, 0x4C93A5B6);
MS2_REPLACE(0x140381300, FUN_140381300, 16, 0x649FEBDA);
MS2_REPLACE(0x140381320, FUN_140381320, 15, 0x32C862F5);
MS2_REPLACE(0x140381340, FUN_140381340, 27, 0x097A8DDD);
MS2_REPLACE(0x140381370, FUN_140381370, 15, 0x7ACD517B);
MS2_REPLACE_METHOD(0x140381420, FieldPropertyWeather, vfunc_1, 59, 0xA883D884);
MS2_REPLACE_METHOD(0x140381470, FieldPropertyWeather, vfunc_2, 79, 0xDFE864B6);
MS2_REPLACE_METHOD(0x1403814d0, FieldPropertyWeather, vfunc_3, 11, 0x41502B22);
MS2_REPLACE(0x1403814f0, FUN_1403814f0, 14, 0x72E52537);
MS2_REPLACE_METHOD(0x140381600, FieldPropertyAmbientLight, vfunc_1, 95, 0x90E3C1EB);
MS2_REPLACE_METHOD(0x140381670, FieldPropertyAmbientLight, vfunc_2, 112, 0x3CCD197C);
MS2_REPLACE_METHOD(0x1403816f0, FieldPropertyAmbientLight, vfunc_3, 11, 0x2093C54B);
MS2_REPLACE(0x140381710, FUN_140381710, 15, 0x82F83F1A);
MS2_REPLACE(0x140381730, FUN_140381730, 16, 0x5463A882);
MS2_REPLACE_METHOD(0x140381860, FieldPropertyDirectionalLight, vfunc_1, 117, 0x0CD7634D);
MS2_REPLACE_METHOD(0x1403818e0, FieldPropertyDirectionalLight, vfunc_2, 138, 0x68D1736B);
MS2_REPLACE_METHOD(0x140381970, FieldPropertyDirectionalLight, vfunc_3, 11, 0x653B09E8);
MS2_REPLACE(0x140381990, FUN_140381990, 15, 0x42EB0E67);
MS2_REPLACE(0x1403819b0, FUN_1403819b0, 16, 0x4C93A5B6);
MS2_REPLACE_METHOD(0x140381a60, FieldPropertyEnableLocalCamera, vfunc_1, 53, 0xFF87421D);
MS2_REPLACE_METHOD(0x140381aa0, FieldPropertyEnableLocalCamera, vfunc_2, 60, 0x662499FB);
MS2_REPLACE_METHOD(0x140381af0, FieldPropertyEnableLocalCamera, vfunc_3, 11, 0x97453C11);
MS2_REPLACE_METHOD(0x140381ba0, FieldPropertyPhotoStudio, vfunc_1, 53, 0xC9A5CC96);
MS2_REPLACE_METHOD(0x140381be0, FieldPropertyPhotoStudio, vfunc_2, 60, 0x2C00C7B0);
MS2_REPLACE_METHOD(0x140381c30, FieldPropertyPhotoStudio, vfunc_3, 11, 0xDBEC80AE);
MS2_REPLACE(0x140381c40, FUN_140381c40, 24, 0x45893F6C);
MS2_REPLACE(0x140381c60, FUN_140381c60, 24, 0x797F65C6);
MS2_REPLACE(0x140381c80, FUN_140381c80, 24, 0xB80E0BA6);
MS2_REPLACE(0x140381ca0, FUN_140381ca0, 24, 0xF3438306);
MS2_REPLACE(0x140381cc0, FUN_140381cc0, 24, 0xF2B3A7E6);
MS2_REPLACE(0x140381ce0, FUN_140381ce0, 24, 0xAD5FE546);
MS2_REPLACE(0x140381d00, FUN_140381d00, 24, 0xEBEE8B26);
MS2_REPLACE(0x140381d20, FUN_140381d20, 24, 0xB748DA86);
MS2_REPLACE(0x140381d40, FUN_140381d40, 24, 0x6CE15FA7);
MS2_REPLACE(0x140381d60, FUN_140381d60, 24, 0x15896987);
MS2_REPLACE(0x140381d80, FUN_140381d80, 60, 0xCA8F9059);
MS2_REPLACE(0x140381dc0, FUN_140381dc0, 24, 0xB8C95127);

