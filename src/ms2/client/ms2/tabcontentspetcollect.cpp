// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The pet collection tab of the pet system dialog: see tabcontentspetcollect.h.
// MS2-UNIT: ?\tabcontentspetcollect.cpp
// MS2-RANGE: 0x1400cfa40-0x1400cfbb0 .text$di
// MS2-RANGE: 0x140cac530-0x140cb1d90 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??C?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@IV?$allocator@I@std@@@std@@@std@@@std@@@std@@@std@@QEBAPEAU?$pair@$$CBHV?$vector@IV?$allocator@I@std@@@std@@@1@XZ 0x140cb1710
// MS2-PIN: ??C?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@QEBAPEAU?$pair@$$CBII@1@XZ 0x140cb1730
// MS2-PIN: ??$?RAEAIAEAI@?$less@X@std@@QEBA_NAEAI0@Z 0x140caef70 ; prop
// MS2-PIN: ??$?RAEAIAEBI@?$less@X@std@@QEBA_NAEAIAEBI@Z 0x140caefb0 ; prop
// MS2-PIN: ??$?RAEBIAEAI@?$less@X@std@@QEBA_NAEBIAEAI@Z 0x140caeff0 ; prop
// MS2-PIN: ??$_Buffered_inplace_merge_divide_and_conquer2@PEAIU?$less@X@std@@@std@@YAXPEAI00_J1QEAI_JU?$less@X@0@0011@Z 0x140caf2d0 ; unique
// MS2-PIN: ??$_Buffered_inplace_merge_divide_and_conquer@PEAIU?$less@X@std@@@std@@YAXPEAI00_J1QEAI_JU?$less@X@0@@Z 0x140caf410 ; unique
// MS2-PIN: ??$_Buffered_inplace_merge_unchecked@PEAIU?$less@X@std@@@std@@YAXPEAI00_J1QEAI_JU?$less@X@0@@Z 0x140caf620 ; unique
// MS2-PIN: ??$_Buffered_inplace_merge_unchecked_impl@PEAIU?$less@X@std@@@std@@YAXPEAI00_J1QEAI_JU?$less@X@0@@Z 0x140caf7b0 ; unique
// MS2-PIN: ??$_Buffered_merge_sort_unchecked@PEAIU?$less@X@std@@@std@@YAXQEAI0_J0U?$less@X@0@@Z 0x140caf890 ; unique
// MS2-PIN: ??$_Buffered_rotate_unchecked@PEAI@std@@YAPEAIQEAI00_J101@Z 0x140caf9f0 ; unique
// MS2-PIN: ??$_Chunked_merge_unchecked@PEAIPEAIU?$less@X@std@@@std@@YAXPEAIQEAI0_J_JU?$less@X@0@@Z 0x140cafb80 ; unique
// MS2-PIN: ??$_Construct_in_place@II@std@@YAXAEAI$$QEAI@Z 0x140cafc80 ; unique
// MS2-PIN: ??$_Emplace_back@I@?$_Uninitialized_backout@PEAI@std@@QEAAX$$QEAI@Z 0x140cafd10 ; unique
// MS2-PIN: ??$_Inplace_merge_buffer_left@PEAIU?$less@X@std@@@std@@YAXPEAI00QEAIU?$less@X@0@@Z 0x140cafe20 ; unique
// MS2-PIN: ??$_Inplace_merge_buffer_right@PEAIU?$less@X@std@@@std@@YAXPEAI00QEAIU?$less@X@0@@Z 0x140caffc0 ; unique
// MS2-PIN: ??$_Insertion_sort_isort_max_chunks@PEAIU?$less@X@std@@@std@@YAXPEAIQEAI_JU?$less@X@0@@Z 0x140cb01b0 ; unique
// MS2-PIN: ??$_Insertion_sort_unchecked@PEAIU?$less@X@std@@@std@@YAPEAIPEAIQEAIU?$less@X@0@@Z 0x140cb0230 ; unique
// MS2-PIN: ??$_Insertion_sort_unchecked@V?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@I@std@@@std@@@std@@U?$less@X@2@@std@@YA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@I@std@@@std@@@0@V10@V10@U?$less@X@0@@Z 0x140cb0360 ; unique
// MS2-PIN: ??$_Merge_move@PEAIPEAIU?$less@X@std@@@std@@YAPEAIPEAIQEAI10U?$less@X@0@@Z 0x140cb0510 ; unique
// MS2-PIN: ??$_Move_backward_unchecked1@V?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@I@std@@@std@@@std@@V12@@std@@YA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@I@std@@@std@@@0@V10@00U_General_ptr_iterator_tag@0@@Z 0x140cb0650 ; unique
// MS2-PIN: ??$_Move_backward_unchecked@V?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@I@std@@@std@@@std@@V12@@std@@YA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@I@std@@@std@@@0@V10@00@Z 0x140cb06e0 ; unique
// MS2-PIN: ??$_Next_iter@PEAI@std@@YAPEAIPEAI@Z 0x140cb07d0 ; unique
// MS2-PIN: ??$_Prev_iter@PEAI@std@@YAPEAIPEAI@Z 0x140cb07f0 ; unique
// MS2-PIN: ??$_Ptr_move_cat@V?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@I@std@@@std@@@std@@V12@@std@@YA?AU_General_ptr_iterator_tag@0@AEBV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@I@std@@@std@@@0@0@Z 0x140cb0810 ; unique
// MS2-PIN: ??$_Reverse_unchecked1@PEAI@std@@YAXQEAI0U?$integral_constant@_K$03@0@@Z 0x140cb0860 ; unique
// MS2-PIN: ??$_Reverse_unchecked@PEAI@std@@YAXQEAI0@Z 0x140cb0890 ; unique
// MS2-PIN: ??$_Rotate_one_left@PEAI@std@@YAXPEAI00@Z 0x140cb08e0 ; unique
// MS2-PIN: ??$_Rotate_one_right@PEAI@std@@YAXPEAI00@Z 0x140cb0940 ; unique
// MS2-PIN: ??$_Rotate_unchecked1@PEAI@std@@YAPEAIPEAI00Urandom_access_iterator_tag@0@@Z 0x140cb0990 ; unique
// MS2-PIN: ??$_Rotate_unchecked@PEAI@std@@YAPEAIPEAI00@Z 0x140cb0a00 ; unique
// MS2-PIN: ??$_Stable_sort_unchecked@PEAIU?$less@X@std@@@std@@YAXQEAI0_J01U?$less@X@0@@Z 0x140cb0a60 ; unique
// MS2-PIN: ??$_Uninitialized_chunked_merge_unchecked@PEAIIU?$less@X@std@@@std@@YAXPEAIQEAI0_J_JU?$less@X@0@@Z 0x140cb0c30 ; unique
// MS2-PIN: ??$_Uninitialized_merge_move@PEAIIU?$less@X@std@@@std@@YAPEAIPEAIQEAI11U?$less@X@0@@Z 0x140cb0d70 ; unique
// MS2-PIN: ??$_Uninitialized_move_unchecked1@PEAIPEAI@std@@YAPEAIQEAI00U_Really_trivial_ptr_iterator_tag@0@@Z 0x140cb0ec0 ; prop
// MS2-PIN: ??$_Uninitialized_move_unchecked@PEAIPEAI@std@@YAPEAIQEAI00@Z 0x140cb0f00 ; unique
// MS2-PIN: ??$lower_bound@PEAIIU?$less@X@std@@@std@@YAPEAIPEAIQEAIAEBIU?$less@X@0@@Z 0x140cb0fa0 ; unique
// MS2-PIN: ??$stable_sort@V?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@I@std@@@std@@@std@@U?$less@X@2@@std@@YAXV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@I@std@@@std@@@0@0U?$less@X@0@@Z 0x140cb10c0 ; unique
// MS2-PIN: ??$upper_bound@PEAIIU?$less@X@std@@@std@@YAPEAIPEAI0AEBIU?$less@X@0@@Z 0x140cb1210 ; unique
// MS2-PIN: ??8?$MS2Ptr@VUIAvatarPet@@@@QEBA_NPEAVUIAvatarPet@@@Z 0x140cb16b0 ; unique
// MS2-PIN: ?_Release@?$_Uninitialized_backout@PEAI@std@@QEAAPEAIXZ 0x140cb1960 ; unique
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@HV?$vector@IV?$allocator@I@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@IV?$allocator@I@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@IV?$allocator@I@std@@@std@@@std@@@std@@@std@@@2@AEBH@Z 0x140cb1af0 ; unique
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@HV?$vector@IV?$allocator@I@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@IV?$allocator@I@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@IV?$allocator@I@std@@@std@@@std@@@std@@@std@@@2@AEBH@Z 0x140cb1bd0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\tabcontentspetcollect.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"
#include <algorithm>
#include <map>
#include <vector>
#include "tabcontentspetcollect.h"
#include "uiavatarbase.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/commonfiles/fieldmetatable.h"
#include "ms2/commonfiles/petgroupinfo.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cpetdatatable.h"
#include "ms2/placeholder/cpetmanager.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- statics (the .di of this unit constructs them) ----
#include "ms2/placeholder/header_statics_a.h"

// MS2Ptr<ASUIComponent>: the exe shares every member of it (see tabcontentspetevolution.cpp).
extern template class MS2Ptr<ASUIComponent>;
extern template class MS2Ptr<CItemData>;

// ---- unit-local views of exe objects (names invented; the FUN_ names are exe addresses) ----

// A component of the page with the Invoke helpers of this unit (COMDATs, one per argument list).
class Unk_PcComp : public ASUIComponent
{
public:
    Scaleform::GFx::Value FUN_140caf030(const char* szMethod, int a1, AScript a2);      // Invoke(int, AS object)
    Scaleform::GFx::Value FUN_140caf140(const char* szMethod, ASArray a1);              // Invoke(AS array)
    Scaleform::GFx::Value FUN_140caf230(const char* szMethod, int a1);                  // Invoke(int)
};
#define PC(p) static_cast<Unk_PcComp*>((p).operator->())

void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
void FUN_1422bcc70(Scaleform::GFx::Value* pValue, Scaleform::GFx::Value v);
void FUN_1409b4bc0(Scaleform::GFx::Value* pDst, const Scaleform::GFx::Value& src);

// The pet table singleton and the pet collect table inside it.
CPetDataTable* FUN_14052d210();
CPetManager* FUN_140535320();
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
CStringTable* GetStringTable();
CStringW GetStringCommonByKey(const CStringW& str);
CStringW FUN_14062b4f0(CStringW fmt, const int& n);
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);
CStringW FUN_140938ae0(CStringW strKey, const unsigned& n);
CStringW FUN_14183e9c0(CStringW str, int n);
bool FUN_140184310(const CString& str, const char* psz);        // str == psz
class Unk_PcNpcData : public CPtred { };
MS2Ptr<Unk_PcNpcData> FUN_1406cd330(int nNpcId);                 // the npc table row of an id

// The map record behind a field id: the flag at +0x9c is cleared for fields that are not shown.
struct Unk_PcMapData
{
    unsigned char m_pad_00[0x9c];
    bool m_b9c;
};
MS2_CHECK_OFFSET(Unk_PcMapData, m_b9c, 0x9c);
class Unk_PcMapPtr
{
public:
    ~Unk_PcMapPtr();                                            // 0x1408850f0
    bool FUN_140965240(int n) const;                            // is null
    Unk_PcMapData* FUN_140885340() const;                       // operator->
private:
    void* m_pad_00;
    Unk_PcMapData* m_p;
};
Unk_PcMapPtr FUN_140a55460(int nMapId);

// The field record (the table behind DAT_143abfb18 hands them out by key).
class Unk_PcFieldInfo : public CPtred { };
class Unk_PcFieldTable { public: MS2Ptr<Unk_PcFieldInfo> FUN_141b978e0(unsigned nFieldId); };
extern Unk_PcFieldTable* DAT_143abfb18;
Unk_PcFieldTable* FUN_140cb17d0();

// The event value manager's battle pet spawn table.
class Unk_PcBattleSpawn { public: void FUN_140426bc0(unsigned nPet, ATL::CAtlArray<unsigned>& fields); };
class Unk_PcEventManager { public: Unk_PcBattleSpawn* FUN_1403ed040(); };
Unk_PcEventManager* FUN_140302b00();

CFieldMetaTable* FUN_140700390();

// Camera of the pet preview (see uiitempetboxdialog.cpp): the position and target are built from an efd::Point3.
struct Unk_PetBoxVector
{
    Unk_PetBoxVector(const Vector3& pt);                        // 0x14027dcf0
    float x, y, z;
};
struct Unk_PetBoxCameraData
{
    Unk_PetBoxCameraData();                                             // 0x140cb13b0
    void FUN_141b48670();
    Unk_PetBoxVector eye, target;
    float f18, f1c, f20;
    int n24, n28, n2c;
};
MS2_CHECK_SIZE(Unk_PetBoxCameraData, 0x30);
float FUN_141b48480(int a, int b);
class Unk_PcActor
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4();
    virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14();
    virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17();
    virtual Unk_PetBoxVector vfunc_18();
};
class Unk_PcCamera
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4();
    virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12();
    virtual void vfunc_13(const Unk_PetBoxCameraData&);
};

extern Vector3 DAT_143b01a60;

// ---- TabContentsPetCollect ----

// @0x140cac530
TabContentsPetCollect::TabContentsPetCollect()
    : m_nGroup(0)
{
}

// @0x140cac5c0
void TabContentsPetCollect::vfunc_3(MS2Ptr<ASUIComponent> ui)
{
    m_ui = ui;
    FUN_140cac8a0();
    FUN_140cacc30();
    FUN_140cac6a0();
    m_ui->Invoke("gotoIndexFromGroupId", m_nGroup);
}
MS2_EMIT_CRT_MEMMOVE_S();

MS2_REPLACE_METHOD(0x140cac5c0, TabContentsPetCollect, vfunc_3, 147, 0x6C27E07A);

// @0x140cac660
void TabContentsPetCollect::vfunc_1()
{
    m_ui = 0;
    m_nGroup = 0;
}
MS2_REPLACE_METHOD(0x140cac660, TabContentsPetCollect, vfunc_1, 45, 0x6E5BA69C);

// @0x140cac6a0
// MS2-FUNCTIONAL: frame/temporary layout and std-glue ordering differ from the exe (semantics recovered, bytes not identical)
void TabContentsPetCollect::FUN_140cac6a0()
{
    if (m_ui == 0)
        return;
    {
        std::map<unsigned, unsigned>& rPets = FUN_14052d210()->GetCollect()->PetGroups();
        int nCount = 0;
        std::map<unsigned, unsigned>::iterator it = rPets.begin();
        std::map<unsigned, unsigned>::iterator itEnd = rPets.end();
        while (it != itEnd)
        {
            int nGrade = FUN_140535320()->FUN_140c8b220(it->first);
            if (nGrade != 0)
                nCount = nCount + 1;
            ++it;
        }
        CStringW strTotal = FUN_14062b4f0(CStringW(L"s_pet_collect_collect_total_cout"), nCount);
        ASObj obj(2);
        obj.FUN_1407cbb20("total", strTotal);
        m_ui->FUN_140acd1f0("setTotalCount", AScript(obj));
    }
}
MS2_REPLACE_METHOD(0x140cac6a0, TabContentsPetCollect, FUN_140cac6a0, 499, 0x720B4B54);

// @0x140cac8a0
// MS2-FUNCTIONAL: frame/temporary layout and std-glue ordering differ from the exe (semantics recovered, bytes not identical)
void TabContentsPetCollect::FUN_140cac8a0()
{
    if (m_ui == 0)
        return;
    {
        ASArray arrTabs(2);
        ASObj objAll(2);
        objAll.FUN_1407cbb20("tabName", GetStringCommonByKey(CStringW(L"s_pet_collect_total_category")));
        objAll.FUN_1407cb9c0("groupId", 0);
        arrTabs.FUN_1422bc050(Scaleform::GFx::Value(objAll.FUN_1422bb870()));
        std::map<int, std::vector<unsigned> >& rGroups = FUN_14052d210()->GetCollect()->GroupPets();
        std::map<int, std::vector<unsigned> >::iterator it = rGroups.begin();
        std::map<int, std::vector<unsigned> >::iterator itEnd = rGroups.end();
        while (it != itEnd)
        {
            PetGroupInfoPtr spInfo = FUN_14052d210()->GetCollect()->Find(it->first);
            if (!(spInfo == 0))
            {
                ASObj objTab(2);
                objTab.FUN_1407cbb20("tabName", GetStringTable()->FUN_141811980(0x41, it->first));
                objTab.FUN_1407cb9c0("groupId", it->first);
                arrTabs.FUN_1422bc050(Scaleform::GFx::Value(objTab.FUN_1422bb870()));
            }
            ++it;
        }
        PC(m_ui)->FUN_140caf140("setupGroup", ASArray(arrTabs));
    }
}
MS2_REPLACE_METHOD(0x140cac8a0, TabContentsPetCollect, FUN_140cac8a0, 900, 0x331C65CF);

// @0x140cacc30
// MS2-FUNCTIONAL: frame/temporary layout and std-glue ordering differ from the exe (semantics recovered, bytes not identical)
void TabContentsPetCollect::FUN_140cacc30()
{
    if (m_ui == 0)
        return;
    {
        FUN_140cacce0();
        std::map<int, std::vector<unsigned> >& rGroups = FUN_14052d210()->GetCollect()->GroupPets();
        std::map<int, std::vector<unsigned> >::iterator it = rGroups.begin();
        std::map<int, std::vector<unsigned> >::iterator itEnd = rGroups.end();
        while (it != itEnd)
        {
            FUN_140cad2b0(it->first);
            ++it;
        }
    }
}
MS2_REPLACE_METHOD(0x140cacc30, TabContentsPetCollect, FUN_140cacc30, 166, 0xC8B4D928);

// One row of the pet list: the pet's icon, number and grade (an empty icon when the item data is missing). Rows of pets
// without an npc entry, or that are neither owned nor previewable, are left out.
#define PC_PET_ROW(vec, i, arrPets) \
        ASObj objPet(2); \
        const unsigned* pPet = &(vec)[i]; \
        MS2Ptr<CPetData> spPet = FUN_14052d210()->Find(*pPet); \
        if (!(spPet == 0)) \
        { \
            MS2Ptr<Unk_PcNpcData> spNpc = FUN_1406cd330(spPet->GetId()); \
            if (!(spNpc == 0)) \
            { \
                int nGrade = FUN_140535320()->FUN_140c8b220(*pPet); \
                if (nGrade < 1 && !spPet->m_bCollectPreview) \
                { \
                } \
                else \
                { \
                    CString strIcon; \
                    MS2Ptr<CItemData> spData = FUN_14053f870(spPet->GetItemId(1)); \
                    if (spData.get() != 0) \
                        strIcon = spData->FUN_14053fdd0(); \
                    objPet.FUN_1407cba60("iconPath", strIcon); \
                    objPet.FUN_1409c0d20("petID", *pPet); \
                    objPet.FUN_1407cb9c0("grade", nGrade); \
                    arrPets.FUN_1422bc050(Scaleform::GFx::Value(objPet.FUN_1422bb870())); \
                } \
            } \
        }

// @0x140cacce0
// MS2-FUNCTIONAL: frame/temporary layout and std-glue ordering differ from the exe (semantics recovered, bytes not identical)
void TabContentsPetCollect::FUN_140cacce0()
{
    if (m_ui == 0)
        return;
    {
        std::map<int, std::vector<unsigned> >& rGroups = FUN_14052d210()->GetCollect()->GroupPets();
        std::map<int, std::vector<unsigned> >::iterator it = rGroups.begin();
        std::map<int, std::vector<unsigned> >::iterator itEnd = rGroups.end();
        if (it == itEnd)
            return;
        {
            ASObj objData(2);
            objData.FUN_1407cb9c0("groupId", 0);
            objData.FUN_1407cbb20("name", GetStringCommonByKey(CStringW(L"s_pet_collect_total_category")));
            ASArray arrPets(2);
            while (it != itEnd)
            {
                std::vector<unsigned> vecPets(it->second);
                std::stable_sort(vecPets.begin(), vecPets.end());
                for (size_t i = 0; i < vecPets.size(); i++)
                {
                    PC_PET_ROW(vecPets, i, arrPets)
                }
                ++it;
            }
            objData.FUN_140c16160("petArray", ASArray(arrPets));
            PC(m_ui)->FUN_140caf030("setGroupData", 0, AScript(objData));
        }
    }
}
MS2_REPLACE_METHOD(0x140cacce0, TabContentsPetCollect, FUN_140cacce0, 1482, 0xE2EFEB51);

// @0x140cad2b0
// MS2-FUNCTIONAL: frame/temporary layout and std-glue ordering differ from the exe (semantics recovered, bytes not identical)
void TabContentsPetCollect::FUN_140cad2b0(int nGroup)
{
    if (m_ui == 0 || nGroup == 0)
        return;
    {
        std::map<int, std::vector<unsigned> >& rGroups = FUN_14052d210()->GetCollect()->GroupPets();
        std::map<int, std::vector<unsigned> >::iterator it = rGroups.find(nGroup);
        if (!(it == rGroups.end()))
        {
            std::vector<unsigned> vecPets(it->second);
            std::stable_sort(vecPets.begin(), vecPets.end());
            ASObj objData(2);
            objData.FUN_1407cb9c0("groupId", nGroup);
            objData.FUN_1407cbb20("name", GetStringTable()->FUN_141811980(0x41, it->first));
            ASArray arrPets(2);
            for (size_t i = 0; i < vecPets.size(); i++)
            {
                PC_PET_ROW(vecPets, i, arrPets)
            }
            objData.FUN_140c16160("petArray", ASArray(arrPets));
            PC(m_ui)->FUN_140caf030("setGroupData", nGroup, AScript(objData));
        }
    }
}
MS2_REPLACE_METHOD(0x140cad2b0, TabContentsPetCollect, FUN_140cad2b0, 1499, 0x426002DC);

// @0x140cad8a0
// MS2-FUNCTIONAL: frame/temporary layout and std-glue ordering differ from the exe (semantics recovered, bytes not identical)
void TabContentsPetCollect::FUN_140cad8a0(int nGroup)
{
    if (m_ui.get() == 0)
        m_nGroup = nGroup;
    else
        m_ui->Invoke("gotoIndexFromGroupId", nGroup);
}
MS2_REPLACE_METHOD(0x140cad8a0, TabContentsPetCollect, FUN_140cad8a0, 106, 0x791F2E75);

// @0x140cad910
void TabContentsPetCollect::vfunc_4()
{
    FUN_140caeda0();
    m_avatar = 0;
    if (m_ui.get() != 0)
        m_ui->Invoke("OnLeaveTap");
    m_ui = 0;
}
MS2_REPLACE_METHOD(0x140cad910, TabContentsPetCollect, vfunc_4, 131, 0xAF0C3814);

// @0x140cad9a0
// The pet tooltip: name and grade, kind, level limit, where the pet is caught and its bag size.
// MS2-FUNCTIONAL: frame/temporary layout and std-glue ordering differ from the exe (semantics recovered, bytes not identical)
void TabContentsPetCollect::vfunc_5(void* pOut, void* pName, void* pData)
{
    if (!FUN_140184310(*static_cast<const CString*>(pName), "getTooltip"))
        return;
    ASData* pArgs = static_cast<ASData*>(pData);
    CString strType = pArgs->FUN_1422b8d30();
    if (FUN_140184310(strType, "collect_pet"))
    {
        int nPet = pArgs->FUN_1422b8a10();
        MS2Ptr<CPetData> spPet = FUN_14052d210()->Find(nPet);
        if (spPet == 0)
            return;
        MS2Ptr<CItemData> spData = FUN_14053f870(spPet->GetItemId(1));
        if (spData == 0)
            return;
        int nGrade = FUN_140535320()->FUN_140c8b220(nPet);
        int nShown = nGrade;
        if (nGrade == 0)
            nShown = 1;
        CStringW strTip = FUN_14183e9c0(FUN_1405c2690(CStringW(L"s_pet_collect_pet_tooltip_pet_name"),
            GetStringTable()->FUN_141811980(0x3b, spPet->GetId())), nShown);
        if (spPet->m_nType == 1)
            strTip += GetStringCommonByKey(CStringW(L"s_pet_collect_pet_tooltip_battle_pet"));
        else if (spPet->m_nType == 0)
            strTip += GetStringCommonByKey(CStringW(L"s_pet_collect_pet_tooltip_default_pet"));
        if (0 < nGrade)
            strTip += FUN_1405c2690(CStringW(L"s_pet_collect_pet_tooltip_my_grade"), GetStringTable()->FUN_141813150(nGrade));
        strTip += FUN_140938ae0(CStringW(L"s_pet_collect_pet_tooltip_limit_level"), spData->limit.levelLimit);
        {
            CStringW strPlace;
            ATL::CAtlArray<unsigned> arrFields;
            FUN_140700390()->FUN_1406fb060(nPet, arrFields);
            for (size_t i = 0; i < arrFields.GetCount(); i++)
            {
                const unsigned* pField = &arrFields[i];
                Unk_PcMapPtr spMap = FUN_140a55460(*pField);
                if (!spMap.FUN_140965240(0))
                {
                    if (spMap.FUN_140885340()->m_b9c != 0)
                    {
                        unsigned nOut = 0;
                        unsigned nKey = *pField;
                        if (FUN_140700390()->FUN_1406fc110(*pField, &nOut) != 0)
                            nKey = nOut;
                        MS2Ptr<Unk_PcFieldInfo> spField = FUN_140cb17d0()->FUN_141b978e0(nKey);
                        if (!(spField == 0))
                        {
                            if (!strPlace.IsEmpty())
                                strPlace += ", ";
                            strPlace += GetStringTable()->FUN_141811980(3, *pField);
                        }
                    }
                }
            }
            if (0 < strPlace.GetLength())
                strTip += FUN_1405c2690(CStringW(L"s_pet_collect_pet_tooltip_capture_place"), strPlace);
        }
        {
            CStringW strPlace;
            ATL::CAtlArray<unsigned> arrFields;
            FUN_140302b00()->FUN_1403ed040()->FUN_140426bc0(nPet, arrFields);
            for (size_t i = 0; i < arrFields.GetCount(); i++)
            {
                const unsigned* pField = &arrFields[i];
                Unk_PcMapPtr spMap = FUN_140a55460(*pField);
                if (!spMap.FUN_140965240(0))
                {
                    if (spMap.FUN_140885340()->m_b9c != 0)
                    {
                        unsigned nOut = 0;
                        unsigned nKey = *pField;
                        if (FUN_140700390()->FUN_1406fc110(*pField, &nOut) != 0)
                            nKey = nOut;
                        MS2Ptr<Unk_PcFieldInfo> spField = FUN_140cb17d0()->FUN_141b978e0(nKey);
                        if (!(spField == 0))
                        {
                            if (!strPlace.IsEmpty())
                                strPlace += ", ";
                            strPlace += GetStringTable()->FUN_141811980(3, *pField);
                        }
                    }
                }
            }
            if (0 < strPlace.GetLength())
                strTip += FUN_1405c2690(CStringW(L"s_pet_collect_pet_tooltip_event_capture_place"), strPlace);
        }
        if (spPet->m_nSlotNum != 0)
            strTip += FUN_140938ae0(CStringW(L"s_pet_collect_pet_tooltip_bag_size"), spPet->m_nSlotNum);
        ASTooltip tip(1, 2);
        tip.FUN_1409c6dc0(5);
        if (tip.FUN_1409e26b0(strTip) != 0)
            FUN_1409b4bc0(static_cast<Scaleform::GFx::Value*>(pOut), tip.FUN_1422bb870());
    }
}
MS2_REPLACE_METHOD(0x140cad9a0, TabContentsPetCollect, vfunc_5, 3002, 0x2BD75153);

// @0x140cae560
// MS2-FUNCTIONAL: frame/temporary layout and std-glue ordering differ from the exe (semantics recovered, bytes not identical)
int TabContentsPetCollect::vfunc_6(const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned nArgs)
{
    ASData data;
    if (_stricmp("OnCollectAvatar", szEvent) == 0)
    {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            int nPet = data.FUN_1422b8b10();
            MS2Ptr<CPetData> spPet = FUN_14052d210()->Find(nPet);
            if (spPet == 0)
                return 0;
            MS2Ptr<CItemData> spData = FUN_14053f870(spPet->GetItemId(1));
            if (spData.get() != 0)
            {
                if (spData->FUN_14053cc40())
                {
                    if (m_avatar == 0)
                    {
                        UIAvatarPet* pAvatar = new UIAvatarPet(spData.get());
                        m_avatar.AssignRaw(pAvatar);
                        m_avatar->vfunc_1(static_cast<IUIAvatarEventListener*>(this));
                    }
                    else
                    {
                        m_avatar->FUN_1418bebd0(spData.get());
                    }
                    PC(m_ui)->FUN_140caf230("setAvatarGrade", FUN_140535320()->FUN_140c8b220(nPet));
                }
            }
            return 1;
        }
    }
    else
    {
        if (_stricmp("onGotoCollect", szEvent) == 0 && data.FUN_1422b9620(pArgs, nArgs) != 0)
            m_ui->Invoke("gotoIndexFromGroupId", data.FUN_1422b8b10());
    }
    if (m_avatar.get() != 0)
    {
        if (m_avatar->vfunc_27(szEvent, pArgs, nArgs) != 0)
            return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140cae560, TabContentsPetCollect, vfunc_6, 1032, 0x1B875610);

// @0x140cae970
// MS2-FUNCTIONAL: frame/temporary layout and std-glue ordering differ from the exe (semantics recovered, bytes not identical)
void TabContentsPetCollect::vfunc_7(void* a1, TPtr<Unk_UISwfEntity_25> a2, void* a3, void* a4)
{
    if (a2.get() == 0 || a3 == 0)
        return;
    if (m_avatar == 0)
        return;
    Unk_PcActor* pActor = reinterpret_cast<Unk_PcActor*>(m_avatar->vfunc_24());
    if (pActor == 0)
        return;
    m_avatar->vfunc_28(a1, a2, a3);
    Unk_PetBoxCameraData kCamera;
    kCamera.FUN_141b48670();
    kCamera.n28 = 5;
    kCamera.f20 = 100.0f;
    kCamera.f1c = 500.0f;
    kCamera.eye = pActor->vfunc_18();
    reinterpret_cast<Unk_PcCamera*>(m_avatar->m_spView.operator->())->vfunc_13(kCamera);
    m_avatar->vfunc_19(FUN_141b48480(0xb, 0), 0);
}
MS2_REPLACE_METHOD(0x140cae970, TabContentsPetCollect, vfunc_7, 654, 0x0C22A2BD);

// @0x140caec10
int TabContentsPetCollect::vfunc_o178_1(void* pAvatar)
{
    if (pAvatar == 0)
        return 0;
    FUN_140caed40();
    return 1;
}

// @0x140caec50
int TabContentsPetCollect::vfunc_o178_0(void* pAvatar)
{
    if (pAvatar == 0)
        return 0;
    if (m_avatar == 0)
        return 0;
    Unk_PcActor* pActor = reinterpret_cast<Unk_PcActor*>(m_avatar->vfunc_24());
    if (pActor == 0)
        return 0;
    float fScale = FUN_141b48480(0xb, 0);
    m_avatar->vfunc_19(fScale, 1);
    return 1;
}

// @0x140caed20
int TabContentsPetCollect::vfunc_8()
{
    return 2;
}

// @0x140caed40
void TabContentsPetCollect::FUN_140caed40()
{
    if (m_ui == 0)
        return;
    m_ui->Invoke("loadRenderTarget");
}

// @0x140caeda0
void TabContentsPetCollect::FUN_140caeda0()
{
    if (m_ui == 0)
        return;
    m_ui->Invoke("unloadRenderTarget");
}

// ---- Invoke helpers (COMDATs of this unit) ----

// @0x140caf030 Invoke(name, int, AS object): the by-value object is destroyed by the callee
inline Scaleform::GFx::Value Unk_PcComp::FUN_140caf030(const char* szMethod, int a1, AScript a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bccb0(args.FUN_1409b1f70(0), a1);
    FUN_1422bcc70(args.FUN_1409b1f70(1), Scaleform::GFx::Value(a2.FUN_1422bb890()));
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140caf140 Invoke(name, AS array): the by-value array is destroyed by the callee
inline Scaleform::GFx::Value Unk_PcComp::FUN_140caf140(const char* szMethod, ASArray a1)
{
    ASArgList args;
    args.FUN_1409b2800(1);
    FUN_1422bcc70(args.FUN_1409b1f70(0), Scaleform::GFx::Value(a1.FUN_1422bb890()));
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140caf230 Invoke(name, int)
inline Scaleform::GFx::Value Unk_PcComp::FUN_140caf230(const char* szMethod, int a1)
{
    ASArgList args;
    args.FUN_1409b2800(1);
    FUN_1422bccb0(args.FUN_1409b1f70(0), a1);
    return FUN_1422bb8f0(szMethod, args);
}

// ---- smaller COMDATs ----

// @0x140cb13b0
// MS2-FUNCTIONAL: frame/temporary layout and std-glue ordering differ from the exe (semantics recovered, bytes not identical)
Unk_PetBoxCameraData::Unk_PetBoxCameraData()
    : eye(DAT_143b01a60)
    , target(DAT_143b01a60)
{
    f18 = 0.0f;
    f1c = 0.0f;
    f20 = 0.0f;
    n24 = 0;
    n28 = 1;
    n2c = 0;
}

// @0x140cb1440
IUIAvatarEventListener::IUIAvatarEventListener()
{
}

// @0x140cb1800
int IUIAvatarEventListener::vfunc_o178_0(void*) { return 1; }

// @0x140cb1810
int IUIAvatarEventListener::vfunc_o178_2(void*) { return 1; }

// @0x140cb1820
int IUIAvatarEventListener::vfunc_o178_3(void*) { return 1; }

// @0x140cb1830
int IUIAvatarEventListener::vfunc_o178_1(void*) { return 1; }

// @0x140cb17d0
Unk_PcFieldTable* FUN_140cb17d0()
{
    return DAT_143abfb18;
}


// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca3c20-0x142ca3cb0 .text$yd
