// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). A small zone of COMDATs: two container copy assignments
// (clear, then assign the element range through opaque exe helpers), the implicit copy assignments of three value types
// (CPtred-derived camera-style row + container, a string-normalised row with a 12-byte block and a Point3) and six
// pointer-wrapper iterator comparisons. The element/iterator types are unit-local stand-ins (Unk_*): their template
// argument lists are not recoverable from the byte-identical bodies; callers only use them as opaque values.
// MS2-UNIT: unit_1411267c0
// MS2-RANGE: 0x1411267c0-0x141126bd0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??4?$vector@V?$SmartPointer@VEntity@egf@@@efd@@V?$CustomAllocator@V?$SmartPointer@VEntity@egf@@@efd@@@2@@std@@QEAAAEAV01@AEBV01@@Z 0x1411267f0
// MS2-PIN: ??4?$vector@VEntityID@egf@@V?$CustomAllocator@VEntityID@egf@@@efd@@@std@@QEAAAEAV01@AEBV01@@Z 0x1411268a0
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/cptred.h"
#include <efd/utf8string.h>   // C3: efd::utf8string::operator= (0x1409a10d0)
#include "ms2/client/ms2/cubemapinformationservice_tail.h"  // the two element vectors the range assigns take
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- container copy assignments (two exe copies, each with its own helper set) ----
class Unk_ContA
{
public:
    // @0x1411267c0
    Unk_ContA& operator=(const Unk_ContA& o)
    {
        reinterpret_cast<std::vector<efd::SmartPointer<egf::Entity>, efd::CustomAllocator<efd::SmartPointer<egf::Entity>>>*>(this)->operator=(reinterpret_cast<const std::vector<efd::SmartPointer<egf::Entity>, efd::CustomAllocator<efd::SmartPointer<egf::Entity>>>&>(o));   // C3: the real vector copy assignment
        return *this;
    }
    // (0x1411267f0 is std::vector<egf::EntityPtr, efd::CustomAllocator>::operator=, instantiated below)
    //
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_p4;
    void* m_p5;
    void* m_p6;
};
// @0x1411267f0
template std::vector<efd::SmartPointer<egf::Entity>, efd::CustomAllocator<efd::SmartPointer<egf::Entity>>>& std::vector<efd::SmartPointer<egf::Entity>, efd::CustomAllocator<efd::SmartPointer<egf::Entity>>>::operator=(const std::vector<efd::SmartPointer<egf::Entity>, efd::CustomAllocator<efd::SmartPointer<egf::Entity>>>&);   // C3: was the Assign stand-in (FUN_ helpers, a dead FUN_ _Tidy call)
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//

class Unk_ContB
{
public:
    // @0x141126870
    Unk_ContB& operator=(const Unk_ContB& o)
    {
        reinterpret_cast<std::vector<egf::EntityID, efd::CustomAllocator<egf::EntityID>>*>(this)->operator=(reinterpret_cast<const std::vector<egf::EntityID, efd::CustomAllocator<egf::EntityID>>&>(o));   // C3: the real vector copy assignment
        return *this;
    }
    // (0x1411268a0 is std::vector<egf::EntityID, efd::CustomAllocator>::operator=, instantiated below)
    //
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_p4;
    void* m_p5;
    void* m_p6;
};
// @0x1411268a0
template std::vector<egf::EntityID, efd::CustomAllocator<egf::EntityID>>& std::vector<egf::EntityID, efd::CustomAllocator<egf::EntityID>>::operator=(const std::vector<egf::EntityID, efd::CustomAllocator<egf::EntityID>>&);   // C3: was the Assign stand-in (FUN_ helpers, a dead FUN_ _Tidy call)
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//

// ---- implicit copy assignments ----

// 0x38 bytes: CPtred, five ints and a pointer-sized field.
class Unk_Row38 : public CPtred
{
public:
    // @0x1411269e0
    Unk_Row38& operator=(const Unk_Row38& o)
    {
        CPtred::operator=(o);
        m_18 = o.m_18;
        m_1c = o.m_1c;
        m_20 = o.m_20;
        m_24 = o.m_24;
        m_28 = o.m_28;
        m_30 = o.m_30;
        return *this;
    }
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    float m_28;
    void* m_30;
};
MS2_CHECK_SIZE(Unk_Row38, 0x38);

class Unk_RowWithCont
{
public:
    // @0x141126920
    Unk_RowWithCont& operator=(const Unk_RowWithCont& o)
    {
        m_row = o.m_row;
        m_cont = o.m_cont;
        return *this;
    }
    Unk_Row38 m_row;
    Unk_ContA m_cont;
};
MS2_CHECK_OFFSET(Unk_RowWithCont, m_cont, 0x38);

struct Unk_Block12
{
    char m_b[12];
};

class Unk_Row3c
{
public:
    // @0x141126970
    Unk_Row3c& operator=(const Unk_Row3c& o)
    {
        *reinterpret_cast<efd::utf8string*>(&m_base) = *reinterpret_cast<const efd::utf8string*>(&o.m_base);   // C3: was free FUN_1409a10d0
        m_block = o.m_block;
        *reinterpret_cast<efd::Point3*>(&m_pos) = *reinterpret_cast<const efd::Point3*>(&o.m_pos);
        return *this;
    }
    char m_base[0x20];
    Unk_Block12 m_block;
    char m_pos[12];
};

// ---- pointer-wrapper iterator comparisons ----
template <int N>
class Unk_Wrap
{
public:
    bool IsNull() const { return (m_ptr == 0); }
    bool IsPtr(long long p) const { return (m_ptr == (void*)p); }
    void* m_head;
    void* m_ptr;
};
template bool Unk_Wrap<1>::IsNull() const;
template bool Unk_Wrap<2>::IsNull() const;
template bool Unk_Wrap<1>::IsPtr(long long) const;
template bool Unk_Wrap<2>::IsPtr(long long) const;
template bool Unk_Wrap<3>::IsPtr(long long) const;
template bool Unk_Wrap<4>::IsPtr(long long) const;

// Nothing in this obj calls the assignments (their callers are other units' opaque code), so they are odr-used through
// member-function pointer constants.
__declspec(selectany) extern Unk_ContA& (Unk_ContA::* const ms2_contAAssign)(const Unk_ContA&) = &Unk_ContA::operator=;
__declspec(selectany) extern Unk_ContB& (Unk_ContB::* const ms2_contBAssign)(const Unk_ContB&) = &Unk_ContB::operator=;
__declspec(selectany) extern Unk_RowWithCont& (Unk_RowWithCont::* const ms2_rowContAssign)(const Unk_RowWithCont&) =
    &Unk_RowWithCont::operator=;
__declspec(selectany) extern Unk_Row38& (Unk_Row38::* const ms2_row38Assign)(const Unk_Row38&) = &Unk_Row38::operator=;
__declspec(selectany) extern Unk_Row3c& (Unk_Row3c::* const ms2_row3cAssign)(const Unk_Row3c&) = &Unk_Row3c::operator=;
