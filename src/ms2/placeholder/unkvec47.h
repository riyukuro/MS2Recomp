#pragma once
// Small float records of the data tables, also used as PCBase members (+0x180/+0x190 Unk_Vec4, +0x1a0 Unk_Vec7).
// Ctors 0x140266620 / 0x1402666f0 and Unk_Vec7::operator!= 0x140266790 are defined in commonfiles/commonstringtable.cpp.
struct Unk_Vec4
{
    float m_x;
    float m_y;
    float m_z;
    float m_w;
    Unk_Vec4();
};

// The 7 floats of <distance>.
struct Unk_Vec7
{
    float m_a, m_b, m_c, m_d, m_e, m_f, m_g;
    Unk_Vec7();
    bool operator!=(const Unk_Vec7& other) const;
};
