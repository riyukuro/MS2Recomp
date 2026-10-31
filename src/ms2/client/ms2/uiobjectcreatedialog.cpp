// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIObjectCreateDialog: see uiobjectcreatedialog.h.
// MS2-UNIT: ?\uiobjectcreatedialog.cpp
// MS2-RANGE: 0x14131f690-0x141320660 .text$mn
// MS2-RANGE: 0x1400ef360-0x1400ef700 .text$di
// MS2-PIN: ??1UIObjectCreateDialog@@UEAA@XZ 0x1413203e0
// MS2-PIN: ?vfunc_48@UIObjectCreateDialog@@UEAAHXZ 0x141320530
#define NOMINMAX
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiobjectcreatedialog.cpp"    // assumed
// The ASUIComponent slot list (validateNow = 24, ASCoreList's dataProvider setter = 25) for the list calls.
#define MS2_ASUICOMPONENT_SLOTS
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/ascorelist.h"

#include "uiobjectcreatedialog.h"

#include <atlcoll.h>

#include "ms2/client/ms2/interactobject.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cinteractobjectdata.h"
#include "ms2/placeholder/unk_1402a9d70.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cstringtable.h"

MS2_EMIT_CRT_MEMMOVE_S();

// The statics of header_statics_a.h (included twice by the original) around the unit's own copy of the sort names.
static CString s_strSortTypeNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill1 = "skill";
static CString s_strStun1 = "stun";
static Unk_1402a9d70 s_condition1(17, 0.75f, 0.25f, 2.25f, 10);
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSortTypeNames3[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);

// ---- unit-local placeholders (unrecovered helpers) ----

// The text input control of the movie.
class Unk_ObjectCreateInput : public AScript
{
public:
    CStringW FUN_1422e0b00();                           // the text
};

// The exe inlines MS2Ptr<T>'s dtor / conversion / arrow for these two unit-local controls; the generic bodies of
// ms2ptr_impl.h cannot be included here (they would instantiate every other MS2Ptr<T> of mypc.h), so write these three
// (inline for ASScrollingList: other units instantiate the same COMDATs).
template <> inline MS2Ptr<ASScrollingList>::~MS2Ptr()
{
    if (m_p)
    {
        if (CPtred::ReleasePtred(m_p) == 0)
        {
            CPtred::AddRefPtred(m_p);
            CPtred::DeletePtred(m_p);
        }
        m_p = 0;
    }
}
template <> inline MS2Ptr<ASScrollingList>::operator ASScrollingList*() const { return m_p; }
template <> inline ASScrollingList* MS2Ptr<ASScrollingList>::operator->() const { return m_p; }
template <> MS2Ptr<Unk_ObjectCreateInput>::~MS2Ptr()
{
    if (m_p)
    {
        if (CPtred::ReleasePtred(m_p) == 0)
        {
            CPtred::AddRefPtred(m_p);
            CPtred::DeletePtred(m_p);
        }
        m_p = 0;
    }
}
template <> MS2Ptr<Unk_ObjectCreateInput>::operator Unk_ObjectCreateInput*() const { return m_p; }
template <> Unk_ObjectCreateInput* MS2Ptr<Unk_ObjectCreateInput>::operator->() const { return m_p; }

// The key input state (singleton).
class Unk_14025e7c0 { public: bool FUN_14116d9c0(int nKey, int a, int b); };
void* FUN_14025e7c0();   // C3: was FUN_14025e7c0

// The world manager (singleton): the local player and the interact objects of the field.
class Unk_ObjectCreateWorld
{
public:
    MyPC* FUN_141bd0cc0();
    void FUN_141bc5f10(ATL::CAtlArray<MS2Ptr<CInteractObject> >& aObjects);     // every interact object of the field
};
class WorldService   // C3: member view for the former free stand-ins
{
public:
    static class WorldService* GetInstance();
};

MS2Ptr<CInteractObjectData> FUN_14051f670(int nIndex);                              // a row by index
int FUN_1407181d0(const CString& str);                                              // text to number
void FUN_14020af60_ref(COutPacket* pPacket, const Vector3& pt);             // FUN_14020af60: encode a point

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x14131f690
UIObjectCreateDialog::UIObjectCreateDialog()
{
    m_40 = 1;
    FUN_1422dc3b0(1);
}

// @0x14131f700
CString UIObjectCreateDialog::GetTypeName()
{
    return "ObjectCreateDialog";
}

// @0x14131f750
void UIObjectCreateDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    FUN_14131ff70();
}

// @0x14131f780
void UIObjectCreateDialog::vfunc_26()
{
    UIDialog::vfunc_26();
}

// @0x14131f7a0
int UIObjectCreateDialog::vfunc_13()
{
    if (UIDialog::vfunc_13() != 0)
        return 1;
    if (((class Unk_14025e7c0*)FUN_14025e7c0())->FUN_14116d9c0(0x1c, 0, 0))
        FUN_14131ff70();
    return 0;
}

// @0x14131f800
int UIObjectCreateDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    UIDialog::vfunc_28(szMethod, pArgs, nArgs);
    ASData data;
    if (_stricmp("OnObjectCreate", szMethod) == 0)
    {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            MyPC* pPlayer = ((class Unk_ObjectCreateWorld*)WorldService::GetInstance())->FUN_141bd0cc0();
            if (pPlayer == 0)
                return 0;
            int nKind = data.FUN_1422b8a10();
            CString str1 = data.FUN_1422b8d30();
            CString str2 = data.FUN_1422b8d30();
            CString str3 = data.FUN_1422b8d30();
            CString str4 = data.FUN_1422b8d30();
            int nCount = FUN_1407181d0(data.FUN_1422b8d30());
            COutPacket packet(static_cast<int>(SendOp::InteractObject), 0);
            packet.Encode1(9);
            packet.Encode4(nKind);
            packet.WriteUnicodeStringA(str1);
            packet.WriteUnicodeStringA(str2);
            packet.WriteUnicodeStringA(str3);
            packet.WriteUnicodeStringA(str4);
            packet.Encode4(nCount);
            FUN_14020af60_ref(&packet, reinterpret_cast<const Vector3&>(static_cast<const NiPoint3&>(pPlayer->vfunc_18())));
            FUN_14020af60_ref(&packet, reinterpret_cast<const Vector3&>(static_cast<const NiPoint3&>(pPlayer->vfunc_20())));
            FUN_140710590(packet);
        }
        return 1;
    }
    else if (_stricmp("onIndexChange", szMethod) == 0)
    {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            int nIndex = data.FUN_1422b8a10();
            if (FUN_14051f670(nIndex).IsNull())
                return 0;
            if (MS2Ptr<ASScrollingList> list = FUN_140c02900("m_position"))
            {
                list->FUN_1422dd1d0();
                ATL::CAtlArray<MS2Ptr<CInteractObject> > aObjects;
                ((class Unk_ObjectCreateWorld*)WorldService::GetInstance())->FUN_141bc5f10(aObjects);
                for (size_t i = 0; i < aObjects.GetCount(); i++)
                {
                    MS2Ptr<CInteractObject> obj = aObjects[i];
                    if (obj->GetRowId() == nIndex)
                    {
                        Vector3 kPoint = obj->GetPos();
                        ASObj row(2);
                        row.FUN_1409c4a30("xpos", kPoint.x);
                        row.FUN_1409c4a30("ypos", kPoint.y);
                        row.FUN_1409c4a30("zpos", kPoint.z);
                        row.FUN_1407cbb20("label", StringFormat(L"{0}, {1}, {2}", (int)kPoint.x, (int)kPoint.y, (int)kPoint.z));
                        list->FUN_1422dd230(row);
                    }
                }
                list->vfunc_24(true);
            }
        }
    }
    else if (_stricmp("OnMove", szMethod) == 0 && data.FUN_1422b9620(pArgs, nArgs) != 0)
    {
        Vector3 kPoint;
        kPoint.x = data.FUN_1422b8c10();
        kPoint.y = data.FUN_1422b8c10();
        kPoint.z = data.FUN_1422b8c10();
        COutPacket packet(static_cast<int>(SendOp::SetDebugMode), 0);
        packet.Encode1(2);
        packet.WriteVector3Short(kPoint);
        FUN_140710590(packet);
    }
    return 0;
}

// @0x14131ff70
void UIObjectCreateDialog::FUN_14131ff70()
{
    CStringW strSearch;
    if (MS2Ptr<Unk_ObjectCreateInput> input = FUN_140e35bd0("m_search"))
        strSearch = input->FUN_1422e0b00();
    if (MS2Ptr<ASScrollingList> list = FUN_140c02900("m_objects"))
    {
        list->FUN_1422dd1d0();
        ATL::CAtlArray<MS2Ptr<CInteractObjectData> > aData;
        CInteractObjectData::GetAll(aData);
        for (size_t i = 0; i < aData.GetCount(); i++)
        {
            MS2Ptr<CInteractObjectData> data = aData[i];
            CStringW strName = TSingleton<CStringTable>::GetInstance()->FUN_141811980(11, data->m_nId);
            if (strSearch.GetLength() != 0)
            {
                CStringW strId = StringFormat(L"{0}", data->m_nId);
                if (strName.Find(strSearch, 0) == -1 && strId.Find(strSearch, 0) == -1)
                    continue;
            }
            ASObj row(2);
            row.FUN_1407cbb20("label", StringFormat(L"{0} \t{1}", data->m_nId, strName));
            row.FUN_1409c0d20("code", data->m_nId);
            list->FUN_1422dd230(row);
        }
        list->vfunc_24(true);
    }
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cafe70-0x142caffc0 .text$yd
