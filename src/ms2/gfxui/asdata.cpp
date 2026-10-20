// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASData, the argument FIFO of the GFx UI messages (UIMsg) and
// the ExternalInterface callbacks: appenders AddTail one GFx value, readers RemoveHead the next one and convert it.
// MS2-UNIT: ?\asdata.cpp
// MS2-RANGE: 0x1422b7f20-0x1422b9cd0 .text$mn
// MS2-PIN: ??_GASData@@UEAAPEAXI@Z 0x1422b9730
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). Unit
// boundaries: the previous obj's COMDAT tail ends at 0x1422b7f20; ASData's ctor starts this one. The class is declared in
// src/ms2/placeholder/asdata.h (method names are Ghidra's). ASData::~ASData (0x1406147b0) is emitted with
// unit_1406125d0. The COMDAT tail holds the CAtlList<Value> members (ctor, AddTail, GetAt, GetCount, GetFreeNode, GetHead,
// GetHeadPosition, GetNext, IsEmpty, NewNode, RemoveHead, CNode ctor), the scalar deleting dtor and the inline SDK Value
// setters SetBoolean / SetNumber / SetUInt.
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/ascript.h"

#include "hook/ms2hook.h"

CStringW FUN_1408767c0(const char* sz);                                 // CStringW from a narrow string
CString FUN_14016a600(const wchar_t* sz, int n);                        // wide -> narrow
CString FUN_1409a23d0(const char* sz, int n);                           // CString from a narrow string

// @0x1422b7f20
ASData::ASData()
    : m_args(10)
{
}

// @0x1422b7f70
void ASData::FUN_1422b7f70(int n)
{
    Scaleform::GFx::Value v;
    v.SetInt(n);
    m_args.AddTail(v);
}
MS2_REPLACE_METHOD(0x1422B7F70, ASData, FUN_1422b7f70, 85, 0x5C0E688E);

// @0x1422b7fd0
void ASData::FUN_1422b7fd0(bool b)
{
    Scaleform::GFx::Value v;
    v.SetBoolean(b);
    m_args.AddTail(v);
}
MS2_REPLACE_METHOD(0x1422B7FD0, ASData, FUN_1422b7fd0, 86, 0xD74909A1);

// @0x1422b8030
void ASData::FUN_1422b8030(unsigned int n)
{
    Scaleform::GFx::Value v;
    v.SetUInt(n);
    m_args.AddTail(v);
}
MS2_REPLACE_METHOD(0x1422B8030, ASData, FUN_1422b8030, 85, 0xF7B8A73C);

// @0x1422b8090
void ASData::FUN_1422b8090(unsigned long n)
{
    Scaleform::GFx::Value v;
    v.SetUInt(n);
    m_args.AddTail(v);
}
MS2_REPLACE_METHOD(0x1422B8090, ASData, FUN_1422b8090, 85, 0x6071F6C8);

// @0x1422b80f0
void ASData::FUN_1422b80f0(float f)
{
    Scaleform::GFx::Value v;
    v.SetNumber(f);
    m_args.AddTail(v);
}
MS2_REPLACE_METHOD(0x1422B80F0, ASData, FUN_1422b80f0, 92, 0xA653EA98);

// @0x1422b8160
void ASData::FUN_1422b8160(double d)
{
    Scaleform::GFx::Value v;
    v.SetNumber(d);
    m_args.AddTail(v);
}
MS2_REPLACE_METHOD(0x1422B8160, ASData, FUN_1422b8160, 89, 0xEB77A1F4);

// @0x1422b81c0
void ASData::FUN_1422b81c0(__int64 n)
{
    Scaleform::GFx::Value v;
    v.SetNumber((double)n);
    m_args.AddTail(v);
}
MS2_REPLACE_METHOD(0x1422B81C0, ASData, FUN_1422b81c0, 92, 0xBE5630E6);

// @0x1422b8230
void ASData::FUN_1422b8230(ASData* pOther)
{
    if (pOther != NULL)
        pOther->FUN_1422b9580(m_args);
}
MS2_REPLACE_METHOD(0x1422B8230, ASData, FUN_1422b8230, 49, 0x732ACD52);

// @0x1422b8270
void ASData::FUN_1422b8270(const AScript& obj)
{
    if (&obj != NULL)
        FUN_1422b83f0(const_cast<AScript&>(obj).FUN_1422bb870());
}
MS2_REPLACE_METHOD(0x1422B8270, ASData, FUN_1422b8270, 50, 0x247FE890);

// @0x1422b82b0
void ASData::FUN_1422b82b0(const char* sz)
{
    Scaleform::GFx::Value v;
    v.SetString(sz);
    m_args.AddTail(v);
}
MS2_REPLACE_METHOD(0x1422B82B0, ASData, FUN_1422b82b0, 87, 0x804F3DC2);

// @0x1422b8310
void ASData::FUN_1422b8310(const wchar_t* sz)
{
    Scaleform::GFx::Value v;
    v.SetStringW(sz);
    m_args.AddTail(v);
}
MS2_REPLACE_METHOD(0x1422B8310, ASData, FUN_1422b8310, 87, 0xDC102A34);

// @0x1422b8370
void ASData::FUN_1422b8370(size_t n)
{
    Scaleform::GFx::Value v;
    v.SetNumber((double)n);
    m_args.AddTail(v);
}
MS2_REPLACE_METHOD(0x1422B8370, ASData, FUN_1422b8370, 108, 0x02724AB7);

// @0x1422b83f0
void ASData::FUN_1422b83f0(const Scaleform::GFx::Value& v)
{
    m_args.AddTail(v);
}
MS2_REPLACE_METHOD(0x1422B83F0, ASData, FUN_1422b83f0, 41, 0x3427F45B);

// @0x1422b8420
void ASData::FUN_1422b8420(int* pOut)
{
    if (m_args.GetCount() > 0)
        *pOut = m_args.RemoveHead().GetInt();
}
MS2_REPLACE_METHOD(0x1422B8420, ASData, FUN_1422b8420, 114, 0x6E08547E);

// @0x1422b84a0
void ASData::FUN_1422b84a0(bool* pOut)
{
    if (m_args.GetCount() > 0)
        *pOut = m_args.RemoveHead().GetBool();
}
MS2_REPLACE_METHOD(0x1422B84A0, ASData, FUN_1422b84a0, 114, 0x8528F3FD);

// @0x1422b8520
void ASData::FUN_1422b8520(unsigned int* pOut)
{
    if (m_args.GetCount() > 0)
        *pOut = m_args.RemoveHead().GetUInt();
}
MS2_REPLACE_METHOD(0x1422B8520, ASData, FUN_1422b8520, 114, 0xEAE566E5);

// @0x1422b85a0
void ASData::FUN_1422b85a0(unsigned long* pOut)
{
    if (m_args.GetCount() > 0)
        *pOut = m_args.RemoveHead().GetUInt();
}
MS2_REPLACE_METHOD(0x1422B85A0, ASData, FUN_1422b85a0, 114, 0x0909B330);

// @0x1422b8620
void ASData::FUN_1422b8620(float* pOut)
{
    if (m_args.GetCount() > 0)
        *pOut = (float)m_args.RemoveHead().GetNumber();
}
MS2_REPLACE_METHOD(0x1422B8620, ASData, FUN_1422b8620, 120, 0x05F25E65);

// @0x1422b86a0
void ASData::FUN_1422b86a0(double* pOut)
{
    if (m_args.GetCount() > 0)
        *pOut = m_args.RemoveHead().GetNumber();
}
MS2_REPLACE_METHOD(0x1422B86A0, ASData, FUN_1422b86a0, 116, 0x19BC633A);

// @0x1422b8720
void ASData::FUN_1422b8720(__int64* pOut)
{
    if (m_args.GetCount() > 0)
        *pOut = (__int64)m_args.RemoveHead().GetNumber();
}
MS2_REPLACE_METHOD(0x1422B8720, ASData, FUN_1422b8720, 120, 0xCCCE6FEE);

// @0x1422b87a0
void ASData::FUN_1422b87a0(CString& strOut)
{
    if (m_args.GetCount() > 0)
        strOut = FUN_1409a23d0(m_args.RemoveHead().GetString(), 0);
}
MS2_REPLACE_METHOD(0x1422B87A0, ASData, FUN_1422b87a0, 176, 0x1D9F2174);

// @0x1422b8860
void ASData::FUN_1422b8860(CStringW& strOut)
{
    if (m_args.GetCount() > 0)
        strOut = m_args.RemoveHead().GetStringW();
}
MS2_REPLACE_METHOD(0x1422B8860, ASData, FUN_1422b8860, 122, 0x76BD877B);

// @0x1422b88e0
void ASData::FUN_1422b88e0(unsigned __int64* pOut)
{
    if (m_args.GetCount() > 0)
        *pOut = (unsigned __int64)m_args.RemoveHead().GetNumber();
}
MS2_REPLACE_METHOD(0x1422B88E0, ASData, FUN_1422b88e0, 169, 0xEE2F7113);

// @0x1422b8990
void ASData::FUN_1422b8990(Scaleform::GFx::Value& vOut)
{
    if (m_args.GetCount() > 0)
        vOut = m_args.RemoveHead();
}
MS2_REPLACE_METHOD(0x1422B8990, ASData, FUN_1422b8990, 113, 0xF9310785);

// @0x1422b8a10
int ASData::FUN_1422b8a10()
{
    int n = 0;
    if (m_args.GetCount() > 0)
        n = m_args.RemoveHead().GetInt();
    return n;
}
MS2_REPLACE_METHOD(0x1422B8A10, ASData, FUN_1422b8a10, 118, 0x268CC9E9);

// @0x1422b8a90
bool ASData::FUN_1422b8a90()
{
    bool b = false;
    if (m_args.GetCount() > 0)
        b = m_args.RemoveHead().GetBool();
    return b;
}
MS2_REPLACE_METHOD(0x1422B8A90, ASData, FUN_1422b8a90, 116, 0x81CA83A0);

// @0x1422b8b10
int ASData::FUN_1422b8b10()
{
    unsigned int n = 0;
    if (m_args.GetCount() > 0)
        n = m_args.RemoveHead().GetUInt();
    return n;
}
MS2_REPLACE_METHOD(0x1422B8B10, ASData, FUN_1422b8b10, 118, 0x1792AF1E);

// @0x1422b8b90
unsigned long ASData::FUN_1422b8b90()
{
    unsigned long n = 0;
    if (m_args.GetCount() > 0)
        n = m_args.RemoveHead().GetUInt();
    return n;
}
MS2_REPLACE_METHOD(0x1422B8B90, ASData, FUN_1422b8b90, 118, 0xF7AE0274);

// @0x1422b8c10
float ASData::FUN_1422b8c10()
{
    float f = 0.0f;
    if (m_args.GetCount() > 0)
        f = (float)m_args.RemoveHead().GetNumber();
    return f;
}
MS2_REPLACE_METHOD(0x1422B8C10, ASData, FUN_1422b8c10, 127, 0x840657A8);

// @0x1422b8ca0
double ASData::FUN_1422b8ca0()
{
    double d = 0.0;
    if (m_args.GetCount() > 0)
        d = m_args.RemoveHead().GetNumber();
    return d;
}
MS2_REPLACE_METHOD(0x1422B8CA0, ASData, FUN_1422b8ca0, 123, 0xACBBEEB3);

// @0x1422b8d30
CString ASData::FUN_1422b8d30()
{
    CString str("");
    if (m_args.GetCount() > 0) {
        if (m_args.GetHead().IsString())
            str = FUN_1409a23d0(m_args.RemoveHead().GetString(), 0);
        else if (m_args.GetHead().IsStringW())
            str = FUN_14016a600(m_args.RemoveHead().GetStringW(), 0);
        else
            m_args.RemoveHead();
    }
    return str;
}
MS2_REPLACE_METHOD(0x1422B8D30, ASData, FUN_1422b8d30, 520, 0x815442F6);

// @0x1422b8f40
CStringW ASData::FUN_1422b8f40()
{
    CStringW str(L"");
    if (m_args.GetCount() > 0) {
        if (m_args.GetHead().IsString())
            str = FUN_1408767c0(m_args.RemoveHead().GetString());
        else if (m_args.GetHead().IsStringW())
            str = m_args.RemoveHead().GetStringW();
        else
            m_args.RemoveHead();
    }
    return str;
}
MS2_REPLACE_METHOD(0x1422B8F40, ASData, FUN_1422b8f40, 455, 0xBDEEFC16);

// @0x1422b9110
__int64 ASData::FUN_1422b9110()
{
    __int64 n = 0;
    if (m_args.GetCount() > 0)
        n = (__int64)m_args.RemoveHead().GetNumber();
    return n;
}
MS2_REPLACE_METHOD(0x1422B9110, ASData, FUN_1422b9110, 126, 0xCFB41D83);

// @0x1422b91a0
unsigned __int64 ASData::FUN_1422b91a0()
{
    unsigned __int64 n = 0;
    if (m_args.GetCount() > 0)
        n = (unsigned __int64)m_args.RemoveHead().GetNumber();
    return n;
}
MS2_REPLACE_METHOD(0x1422B91A0, ASData, FUN_1422b91a0, 175, 0x1382280E);

// @0x1422b9260
Scaleform::GFx::Value ASData::FUN_1422b9260()
{
    Scaleform::GFx::Value v;
    if (m_args.GetCount() > 0)
        v = m_args.RemoveHead();
    return v;
}
MS2_REPLACE_METHOD(0x1422B9260, ASData, FUN_1422b9260, 191, 0x4EC70087);

// @0x1422b9330
bool ASData::FUN_1422b9330()
{
    return m_args.IsEmpty();
}
MS2_REPLACE_METHOD(0x1422B9330, ASData, FUN_1422b9330, 31, 0xB32D2D98);

// @0x1422b9360
int ASData::FUN_1422b9360()
{
    return (int)m_args.GetCount();
}
MS2_REPLACE_METHOD(0x1422B9360, ASData, FUN_1422b9360, 31, 0x0FDF48C6);

// @0x1422b9390
int FUN_1422b9390(const Scaleform::GFx::Value& v)
{
    return v.GetInt();
}
MS2_REPLACE(0x1422B9390, FUN_1422b9390, 24, 0x28F9630A);

// @0x1422b93b0
unsigned int FUN_1422b93b0(const Scaleform::GFx::Value& v)
{
    return v.GetUInt();
}
MS2_REPLACE(0x1422B93B0, FUN_1422b93b0, 24, 0xC44D9159);

// @0x1422b93d0
bool FUN_1422b93d0(const Scaleform::GFx::Value& v)
{
    return v.GetBool();
}
MS2_REPLACE(0x1422B93D0, FUN_1422b93d0, 24, 0x602B071A);

// @0x1422b93f0
float FUN_1422b93f0(const Scaleform::GFx::Value& v)
{
    return (float)v.GetNumber();
}
MS2_REPLACE(0x1422B93F0, FUN_1422b93f0, 28, 0x83643697);

// @0x1422b9420
double FUN_1422b9420(const Scaleform::GFx::Value& v)
{
    return v.GetNumber();
}
MS2_REPLACE(0x1422B9420, FUN_1422b9420, 24, 0xBB825C40);

// @0x1422b9440
CString FUN_1422b9440(const Scaleform::GFx::Value& v)
{
    return FUN_1409a23d0(v.GetString(), 0);
}
MS2_REPLACE(0x1422B9440, FUN_1422b9440, 69, 0xE66ABB60);

// @0x1422b9490
CStringW FUN_1422b9490(const Scaleform::GFx::Value& v)
{
    if (v.IsString())
        return FUN_1408767c0(v.GetString());
    else if (v.IsStringW())
        return CStringW(v.GetStringW());
    return CStringW(L"");
}
MS2_REPLACE(0x1422B9490, FUN_1422b9490, 178, 0xCC118658);

// @0x1422b9550
__int64 FUN_1422b9550(const Scaleform::GFx::Value& v)
{
    return (__int64)v.GetNumber();
}
MS2_REPLACE(0x1422B9550, FUN_1422b9550, 29, 0xFE531800);

// @0x1422b9580
int ASData::FUN_1422b9580(ATL::CAtlList<Scaleform::GFx::Value>& dst)
{
    for (POSITION pos = m_args.GetHeadPosition(); pos != NULL; m_args.GetNext(pos))
        dst.AddTail(m_args.GetAt(pos));
    return dst.GetCount() > 0;
}
MS2_REPLACE_METHOD(0x1422B9580, ASData, FUN_1422b9580, 147, 0xDFAF04B0);

// @0x1422b9620
int ASData::FUN_1422b9620(const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (nArgs > 0) {
        m_args.RemoveAll();
        for (unsigned int i = 0; i < nArgs; i++)
            m_args.AddTail(pArgs[i]);
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1422B9620, ASData, FUN_1422b9620, 125, 0xCE5FD531);
