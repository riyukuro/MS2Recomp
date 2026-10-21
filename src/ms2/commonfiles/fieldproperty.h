// FieldProperty: the per-map "field property" records (gravity, concert, hide/lock PC, sight range, weather, light ...).
// NOT an original header (names inferred from RTTI; member names are guesses). The server-side base classes live in
// fieldproperty.cpp (0x140380840-0x1403820e0); client/ms2/fieldpropertycli.cpp derives the *Cli classes (Apply/Unapply).
// Layout: CPtred (0x18, ref counted) + the record's data from +0x18. vftable slots: 0 dtor (CPtred), 1 Write(packet out),
// 2 Read(packet in), 3 Type() (pure in FieldProperty), 4 Apply (client), 5 Unapply (client).
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

// Packet halves as seen by the vfunc_1/vfunc_2 serialisers (writer: free functions + one virtual; reader: a stream at +8).
struct Unk_PktOut { virtual void s0(); virtual void WriteU8(unsigned char v); };
struct Unk_PktStream { virtual void s0(); virtual unsigned char ReadU8(); };
struct Unk_PktIn { void* m_pad_00; Unk_PktStream m_stream; };

struct Unk_Rgb3b { unsigned char r, g, b; };   // 3 byte colour (POD; default-init by the free function FUN_1406c3700)
struct Unk_Vec3f { Unk_Vec3f(float x, float y, float z); float x, y, z; };   // ctor 0x1406c4340

class FieldProperty : public CPtred {
public:
    FieldProperty();                                    // 0x140380840
    virtual ~FieldProperty();                           // 0x140381c40, scalar deleting 0x140381de0
    virtual void vfunc_1(Unk_PktOut* out);              // 0x140380880 (empty)
    virtual void vfunc_2(Unk_PktIn* in);                // 0x1403808a0 (empty)
    virtual int vfunc_3() = 0;                          // property type id
    virtual void vfunc_4();                             // 0x1403808c0 (empty): apply
    virtual void vfunc_5();                             // 0x1403808d0 (empty): unapply
};
MS2_CHECK_SIZE(FieldProperty, 0x18);

class FieldPropertyGravity : public FieldProperty {
public:
    FieldPropertyGravity();                             // 0x1403808e0
    FieldPropertyGravity(float fGravity);               // 0x140380920
    virtual ~FieldPropertyGravity();
    virtual void vfunc_1(Unk_PktOut* out);
    virtual void vfunc_2(Unk_PktIn* in);
    virtual int vfunc_3();                              // 1
    float m_fGravity;                                   // +0x18
};
MS2_CHECK_SIZE(FieldPropertyGravity, 0x20);

class FieldPropertyMusicConcert : public FieldProperty {
public:
    FieldPropertyMusicConcert();                        // 0x140380a20
    FieldPropertyMusicConcert(__int64 a, int b);        // 0x140380a70
    virtual ~FieldPropertyMusicConcert();
    virtual void vfunc_1(Unk_PktOut* out);
    virtual void vfunc_2(Unk_PktIn* in);
    virtual int vfunc_3();                              // 2
    __int64 m_i64;                                      // +0x18
    int m_n;                                            // +0x20
};
MS2_CHECK_SIZE(FieldPropertyMusicConcert, 0x28);

class FieldPropertyHideMyPC : public FieldProperty {
public:
    FieldPropertyHideMyPC();                            // 0x140380ba0
    virtual ~FieldPropertyHideMyPC();
    virtual void vfunc_1(Unk_PktOut* out);
    virtual void vfunc_2(Unk_PktIn* in);
    virtual int vfunc_3();                              // 3
};
MS2_CHECK_SIZE(FieldPropertyHideMyPC, 0x18);

class FieldPropertyLockMyPC : public FieldProperty {
public:
    FieldPropertyLockMyPC();                            // 0x140380c60
    virtual ~FieldPropertyLockMyPC();
    virtual void vfunc_1(Unk_PktOut* out);
    virtual void vfunc_2(Unk_PktIn* in);
    virtual int vfunc_3();                              // 4
};
MS2_CHECK_SIZE(FieldPropertyLockMyPC, 0x18);

class FieldPropertyUserTagSymbol : public FieldProperty {
public:
    FieldPropertyUserTagSymbol();                       // 0x140380d20
    FieldPropertyUserTagSymbol(CStringW a, CStringW b); // 0x140380d80
    virtual ~FieldPropertyUserTagSymbol();
    virtual void vfunc_1(Unk_PktOut* out);
    virtual void vfunc_2(Unk_PktIn* in);
    virtual int vfunc_3();                              // 5
    CStringW m_strA;                                    // +0x18
    CStringW m_strB;                                    // +0x20
};
MS2_CHECK_SIZE(FieldPropertyUserTagSymbol, 0x28);

class FieldPropertySightRange : public FieldProperty {
public:
    FieldPropertySightRange();                          // 0x140380ef0
    FieldPropertySightRange(float fRange);              // 0x140380f90
    FieldPropertySightRange(float a, float b, float c, float d, unsigned char e, unsigned char f, unsigned char g);   // 0x140381030
    virtual ~FieldPropertySightRange();
    virtual void vfunc_1(Unk_PktOut* out);
    virtual void vfunc_2(Unk_PktIn* in);
    virtual int vfunc_3();                              // 6
    float m_f18, m_f1c, m_f20, m_f24;
    unsigned char m_b28, m_b29, m_b2a;
};
MS2_CHECK_SIZE(FieldPropertySightRange, 0x30);

class FieldPropertyWeather : public FieldProperty {
public:
    FieldPropertyWeather();                             // 0x140381390
    FieldPropertyWeather(int nWeather);                 // 0x1403813d0
    virtual ~FieldPropertyWeather();
    virtual void vfunc_1(Unk_PktOut* out);
    virtual void vfunc_2(Unk_PktIn* in);
    virtual int vfunc_3();                              // 7
    int m_nWeather;                                     // +0x18
};
MS2_CHECK_SIZE(FieldPropertyWeather, 0x20);

class FieldPropertyAmbientLight : public FieldProperty {
public:
    FieldPropertyAmbientLight();                        // 0x140381510
    FieldPropertyAmbientLight(const Unk_Rgb3b& color, bool bFlag, float fValue);   // 0x140381580
    virtual ~FieldPropertyAmbientLight();
    virtual void vfunc_1(Unk_PktOut* out);
    virtual void vfunc_2(Unk_PktIn* in);
    virtual int vfunc_3();                              // 8
    Unk_Rgb3b m_color;                                  // +0x18
    bool m_bFlag;                                       // +0x1b
    float m_fValue;                                     // +0x1c
};
MS2_CHECK_SIZE(FieldPropertyAmbientLight, 0x20);

class FieldPropertyDirectionalLight : public FieldProperty {
public:
    FieldPropertyDirectionalLight();                    // 0x140381750
    FieldPropertyDirectionalLight(const Unk_Rgb3b& c1, const Unk_Rgb3b& c2, bool bFlag, float fValue);   // 0x1403817d0
    virtual ~FieldPropertyDirectionalLight();
    virtual void vfunc_1(Unk_PktOut* out);
    virtual void vfunc_2(Unk_PktIn* in);
    virtual int vfunc_3();                              // 9
    Unk_Rgb3b m_color1;                                 // +0x18
    Unk_Rgb3b m_color2;                                 // +0x1b
    bool m_bFlag;                                       // +0x1e
    float m_fValue;                                     // +0x20
};
MS2_CHECK_SIZE(FieldPropertyDirectionalLight, 0x28);

class FieldPropertyEnableLocalCamera : public FieldProperty {
public:
    FieldPropertyEnableLocalCamera();                   // 0x1403819d0
    FieldPropertyEnableLocalCamera(bool b);             // 0x140381a10
    virtual ~FieldPropertyEnableLocalCamera();
    virtual void vfunc_1(Unk_PktOut* out);
    virtual void vfunc_2(Unk_PktIn* in);
    virtual int vfunc_3();                              // 10
    bool m_b;                                           // +0x18
};
MS2_CHECK_SIZE(FieldPropertyEnableLocalCamera, 0x20);

class FieldPropertyPhotoStudio : public FieldProperty {
public:
    FieldPropertyPhotoStudio();                         // 0x140381b10
    FieldPropertyPhotoStudio(bool b);                   // 0x140381b50
    virtual ~FieldPropertyPhotoStudio();
    virtual void vfunc_1(Unk_PktOut* out);
    virtual void vfunc_2(Unk_PktIn* in);
    virtual int vfunc_3();                              // 11
    bool m_b;                                           // +0x18
};
MS2_CHECK_SIZE(FieldPropertyPhotoStudio, 0x20);
