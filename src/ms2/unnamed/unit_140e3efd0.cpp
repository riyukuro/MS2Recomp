// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIAdPushDialog and its entities (the advertisement push dialog
// that stacks the limited-time bundle badges). See unit_140e3efd0.h. w175.
// MS2-UNIT: unit_140e3efd0
// MS2-RANGE: 0x140e3efd0-0x140e47540 .text$mn
// MS2-RANGE: 0x1400d7e80-0x1400d81b0 .text$di
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?FUN_140e42540@AdPushEntityBase@@QEAAHXZ 0x140e42540 ; unique
// MS2-PIN: ?FUN_140e42560@AdPushEntityBase@@QEAAHXZ 0x140e42560 ; unique
// MS2-PIN: ?FUN_140e42580@AdPushEntityBase@@QEAA_NXZ 0x140e42580 ; unique
// MS2-PIN: ??$?0AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@AEAV01@$0A@@?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@V12@@std@@QEAA@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@1@0@Z 0x140e43bf0 ; unique
// MS2-PIN: ??$?0VAdPushEntityLimitedBundle@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@QEAA@AEBQEAVAdPushEntityLimitedBundle@@AEBQ81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@Z 0x140e43c80 ; unique
// MS2-PIN: ??$?0VUIAdPushDialog@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@QEAA@AEBQEAVUIAdPushDialog@@AEBQ81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@Z 0x140e43d50 ; unique
// MS2-PIN: ??$?8PEAVUIAdPushDialog@@P80@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@YA_NAEBU?$pair@PEAVUIAdPushDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@0@0@Z 0x140e43f00 ; prop
// MS2-PIN: ??$?8PEAVUIAdPushDialog@@P80@EAAXPEAVNotifyObject@@@Z@std@@YA_NAEBU?$pair@PEAVUIAdPushDialog@@P81@EAAXPEAVNotifyObject@@@Z@0@0@Z 0x140e43f70 ; prop
// MS2-PIN: ??$StringFormat@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HH@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEBV01@AEBH2@Z 0x140e44090 ; unique
// MS2-PIN: ??$_Distance1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@@std@@YA_JV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@0@0Uinput_iterator_tag@0@@Z 0x140e444d0 ; unique
// MS2-PIN: ??$_Eqrange@H@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@V12@@1@AEBH@Z 0x140e44530 ; unique
// MS2-PIN: ??$_Eqrange@H@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEBA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@V12@@1@AEBH@Z 0x140e445c0 ; unique
// MS2-PIN: ??$distance@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@@std@@YA_JV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@0@0@Z 0x140e44800 ; unique
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIAdPushDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@QEAA@AEBV01@@Z 0x140e44b40 ; unique
// MS2-PIN: ??0?$MS2Ptr@VAdPushEntityBase@@@@QEAA@PEAVAdPushEntityBase@@@Z 0x140e44d20 ; prop
// MS2-PIN: ?get@?$MS2Ptr@VUIAdPushLimitedDialog@@@@QEBAPEAVUIAdPushLimitedDialog@@XZ 0x140e452b0 ; unique
// MS2-PIN: ?CompareElements@?$CDefaultCompareTraits@H@ATL@@SA_NAEBH0@Z 0x140e45500 ; unique
// MS2-PIN: ?CompareElementsOrdered@?$CDefaultCompareTraits@H@ATL@@SAHAEBH0@Z 0x140e45550 ; unique
// MS2-PIN: ?Find@?$CRBTree@HV?$MS2Ptr@VAdPushEntityBase@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAdPushEntityBase@@@@@3@@ATL@@IEBAPEAVCNode@12@H@Z 0x140e45590 ; unique
// MS2-PIN: ?vfunc_8@AdPushEntityBase@@UEAAXPEAVValue@GFx@Scaleform@@PEAVASData@@@Z 0x140e457b0 ; unique
// MS2-PIN: ?vfunc_48@UIAdPushDialog@@UEAAHXZ 0x140e457c0 ; unique
// MS2-PIN: ?vfunc_6@AdPushEntityBase@@UEAA?AV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@XZ 0x140e45830 ; unique
// MS2-PIN: ?InsertImpl@?$CRBTree@HV?$MS2Ptr@VAdPushEntityBase@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VAdPushEntityBase@@@@@3@@ATL@@AEAAPEAVCNode@12@HAEBV?$MS2Ptr@VAdPushEntityBase@@@@@Z 0x140e45870 ; unique
// MS2-PIN: ?vfunc_10@AdPushEntityBase@@UEAA_NXZ 0x140e459e0 ; unique
// MS2-PIN: ?vfunc_7@AdPushEntityBase@@UEAA_NXZ 0x140e459f0 ; unique
// MS2-PIN: ?vfunc_1@AdPushEntityBase@@UEAA_NXZ 0x140e45ed0 ; unique
// MS2-PIN: ?vfunc_11@AdPushEntityBase@@UEAA_NXZ 0x140e45fb0 ; unique
// MS2-PIN: ?vfunc_3@AdPushEntityBase@@UEAAXXZ 0x140e46880 ; unique
// MS2-PIN: ?vfunc_4@AdPushEntityBase@@UEAAXPEAVUnk_AdXmlNode@@0@Z 0x140e469a0 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIAdPushDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140e47060 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIAdPushDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140e470c0 ; unique
// MS2-PIN: ?equal_range@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@V12@@2@AEBH@Z 0x140e47120 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA_KAEBH@Z 0x140e47160 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVAdPushEntityLimitedBundle@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x140e471c0 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIAdPushDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x140e471f0 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIAdPushDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAXPEAVNotifyObject@@@Z 0x140e47220 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVAdPushEntityLimitedBundle@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140e47300 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIAdPushDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140e47360 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIAdPushDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140e473c0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "unit_140e3efd0.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/placeholder/notifygameeventchanged.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/client/ms2/uiadpushlimiteddialog.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- statics of the unit's header (init order: a path key, sort names, skill, stun, a condition object, the key
// controller, then three more attribute names) ----

static CString s_strIconPath = "iconPath";
static CString s_strSortTypeNames[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
static CString s_strSortTypeNamesLike[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyInput;
static CString s_strJobCode = "jobCode";
static CString s_strSortValue = "sortValue";
static CString s_strTabIndex = "tabIndex";

// ---- unit-local views of exe types ----

// The movie root of the "limitedbundle" child (RTTI .?AVASDialog@@).
class ASDialog : public ASDisplayObjectContainer {
public:
    ASDialog(const Scaleform::GFx::Value& v, int nMovieId);        // 0x1422e63e0
    void FUN_1422c0f60(float* pX, float* pY);                      // get the position
    int FUN_1422c1500();                                           // width
    int FUN_1422c1530();                                           // height
    float FUN_1422c10a0();                                         // x
    float FUN_1422c1110();                                         // y
private:
    void* m_unrecovered_80;
};
MS2_CHECK_SIZE(ASDialog, 0x88);
class Unk_AdWorld {
public:
    void FUN_140d543c0(int n);
    bool FUN_140d5b370(MS2Ptr<Unk_AdMarketItem> item);
    MS2Ptr<Unk_AdMarketItem> FUN_140d578d0(const Unk_AdSn& id);
};
UIAdPushDialog* FUN_140d61c00(eUIClassID nClass);
void FUN_1409e3190(ASTooltip* p, Unk_AdItemInfo* pInfo, bool b, ASData* pData);
Unk_AdWorld* FUN_140939a00();
class Unk_AdNotices {
public:
    void FUN_140da4e40(CStringW strName, Delegate<void(NotifyObject*)> cb);    // subscribe
    void FUN_140da4eb0(CStringW strName, Delegate<void(NotifyObject*)> cb);    // unsubscribe
};
Unk_AdNotices* FUN_140939a10();
class Unk_McInput { public: void FUN_1422b06e0(int nMovie, unsigned* pWidth, unsigned* pHeight); };
Unk_McInput* FUN_14025e7a0();
int FUN_1422db730();
class Unk_AdPlayerMgr;
class Unk_AdActor : public PCBase { public: int FUN_14123bea0(); };
Unk_AdPlayerMgr* FUN_1403ed2d0();
Unk_AdActor* FUN_141bd0cc0(Unk_AdPlayerMgr* pMgr);
void* FUN_14041beb0();
int FUN_1408d7e60(void* p, unsigned short n);
class Unk_140e45740 { public: int FUN_1422e6bf0(UIDialog* p, int n); void FUN_1422e6d00(int n); };
UIObject* FUN_140c9b540(int nClass);
UIObject* FUN_140ce8270(int nClass);
int FUN_1422dc430(UIObject* p);
Unk_140e45740* FUN_140e45740();
bool FUN_1418ffe80(int, int);
void FUN_1418ffec0(int*, int);
void FUN_1418ffef0(int*, int);
__int64 FUN_140869440();
CStringA FUN_1412755f0();
CStringA FUN_141275640();
CString FUN_14038f6d0(const CString&, const char*);
CStringA FUN_140cc2a00(const CStringA& strRoot, const CStringA& strFile);   // path join
bool FUN_140164830(const CStringW& a, const CStringW& b);
bool FUN_140e45240(const CStringW& s, const char* c);
extern Unk_140e45740* DAT_143ac5d88;
bool FUN_1409c1720(const Scaleform::GFx::Value& v);
int FUN_1422b8a10(ASData* p);
bool FUN_1406c4cc0(const CMsTime& a, const CMsTime& b);
unsigned __int64 FUN_140282020(const CMsTime& t);
CStringA FUN_140e01de0(MS2Ptr<Unk_AdMarketItem> item);
void FUN_1422c3600(ASDisplayObject* p, const char* szName, Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> cb, int a, int b, int c, int d);
int FUN_1422e6310(ASDisplayObject* p);
int FUN_1422e6270(ASDisplayObject* p);
int FUN_1422c2510(ASMovieClip* p, double* pX, void* pY);
void FUN_1422c8120(ASMovieClip* p, bool b);
void FUN_1407cba60(AScript* p, const CString& szName, const CStringA& v);
void FUN_1407cbbe0(AScript* p, const char* szName, bool v);
void FUN_1407cb9c0(AScript* p, const char* szName, int v);
// Bit flags of the XML/refresh state (m_nFlags): 1 default loaded, 2 my-pc complete, 4 swf loaded.
extern long DAT_1439f60ac;              // the next entity id

// The child-control creators (the same shapes as uicashattenddialog.cpp's COMDATs).
template<class T> MS2Ptr<T> Unk_ASCreate(int nMovieId, const Scaleform::GFx::Value& v)
{
    MS2Ptr<T> sp(new T(v, nMovieId));
    return sp;
}
template<class T> MS2Ptr<T> AScript::FUN_140e159f0(const CString& strName)
{
    Scaleform::GFx::Value v = FUN_1422baa20(strName);
    if (v.IsObject())
        return Unk_ASCreate<T>(m_nMovieId, v);
    return MS2Ptr<T>(0);
}

// ---- AdPushEntityBase / AdPushEntityLimitedBundle ----

// @0x140e424e0
AdPushEntityBase::AdPushEntityBase(const int& nId)
{
    m_nId = nId;
    m_bTick = false;
    m_nKind = 0;
}

// The XML helpers (TinyXML calls the exe resolves to these addresses).
class Unk_AdXmlNode;
void FUN_14086ddc0(TiXmlDocument* pDoc);                                // Clear
Unk_AdXmlNode* FUN_14081b310(TiXmlDocument* pDoc);                      // RootElement
bool FUN_1408710c0(TiXmlDocument* pDoc, const char* szFile);            // SaveFile
bool FUN_14086e090(TiXmlDocument* pDoc, void* pNode);                   // LinkEndChild
Unk_AdXmlNode* FUN_140165cf0(void* pParent, const char* szName);        // FirstChildElement
Unk_AdXmlNode* FUN_140345b40(Unk_AdXmlNode* pParent);                   // FirstChild
Unk_AdXmlNode* FUN_1403f0510(Unk_AdXmlNode* pNode);                     // NextSibling
const char* FUN_140189180(Unk_AdXmlNode* pNode);                        // Value
void FUN_14086e580(Unk_AdXmlNode* pParent, Unk_AdXmlNode* pChild);      // RemoveChild
Unk_AdXmlNode* FUN_140872ec0(Unk_AdXmlNode* pParent, const char* szName, bool bCreate);
bool FUN_140870fc0(TiXmlDocument* pDoc, const char* szFile, int n);     // LoadFile
void FUN_140870cf0(TiXmlDocument* pDst, TiXmlDocument* pSrc);           // copy
int FUN_1408732e0(Unk_AdXmlNode* pNode, const char* szName, __int64& v);
int FUN_1408730a0(Unk_AdXmlNode* pNode, const char* szName, bool& v);
void FUN_1408744b0(Unk_AdXmlNode* pNode, const char* szGroup, const char* szName, float f, int bCreate);
void FUN_140874210(Unk_AdXmlNode* pNode, const char* szGroup, const char* szName, float* pf);
void FUN_1408740a0(Unk_AdXmlNode* pNode, const char* szName, const CStringW& v);
void FUN_140873bc0(Unk_AdXmlNode* pNode, const char* szName, bool v);
void FUN_140873eb0(Unk_AdXmlNode* pNode, const char* szName, __int64& v);
class TiXmlElement { public: TiXmlElement(const char* szName); };
class Unk_AdXmlNode {};

// UIAdPushDialog
// @0x140e3efd0
UIAdPushDialog::UIAdPushDialog()
    : m_entities(10), m_pending(10), m_nFlags(0), m_nShowState(1)
{
    m_2c = 0x19;
    FUN_141925e70(0, 1);
}

// @0x140e3f140
UIAdPushDialog::~UIAdPushDialog()
{
    UISwfEntity::vfunc_3();
    FUN_14086ddc0(&m_xmlSave);
    FUN_14086ddc0(&m_xmlAccountSave);
    FUN_14086ddc0(&m_xmlLoaded);
    FUN_14086ddc0(&m_xmlAccountLoaded);
    m_entities.RemoveAll();
    m_pending.RemoveAll();
    m_sns.clear();
}

// @0x140e3f2f0
CString UIAdPushDialog::vfunc_1()
{
    return "AdPushDialog";
}
MS2_REPLACE_METHOD(0x140E3F2F0, UIAdPushDialog, vfunc_1, 61, 0xE7B3DBF2);

// @0x140e3f340
int UIAdPushDialog::vfunc_65()
{
    if (!UIDialog::vfunc_65())
        return 0;
    FUN_140939a10()->FUN_140da4e40(L"NotifyCompleteMyPC", Delegate<void(NotifyObject*)>(this, &UIAdPushDialog::OnNotifyCompleteMyPC));
    FUN_140939a00()->FUN_140d543c0(1);
    return 1;
}

// @0x140e3f450
// MS2-FUNCTIONAL: behaviour-equivalent; branch/temporary layout differs from the exe
void UIAdPushDialog::vfunc_72()
{
    UIDialog::vfunc_72();
    if (!(m_30 == 0) && !m_entities.IsEmpty())
    {
        if (FUN_1418ffe80(m_nShowState, 1))
            FixPosition();
        if (m_tick.FUN_140268870(1000))
        {
            POSITION pos = m_entities.GetHeadPosition();
            while (pos)
            {
                POSITION cur = pos;
                m_entities.GetNext(pos);
                AdPushEntityBase* p = m_entities.GetValueAt(cur);
                if (p && p->FUN_140e42580())
                    p->vfunc_9();
            }
        }
    }
}

// @0x140e3f590
// MS2-FUNCTIONAL: behaviour-equivalent; branch/temporary layout differs from the exe
int UIAdPushDialog::vfunc_4()
{
    bool bSaved = false;
    Unk_AdXmlNode* pRoot = FUN_14081b310(&m_xmlSave);
    if (pRoot)
    {
        MS2Ptr<ASDialog> dlg(m_limitedBundle);
        if (dlg.get())
        {
            unsigned nWidth = 0, nHeight = 0;
            FUN_14025e7a0()->FUN_1422b06e0(FUN_1422db730(), &nWidth, &nHeight);
            float x = 0.0f, y = 0.0f;
            dlg->FUN_1422c0f60(&x, &y);
            CStringA strKey("limitedbundle");
            FUN_1408744b0(pRoot, strKey, "rateX", x / (float)nWidth, 1);
            FUN_1408744b0(pRoot, strKey, "rateY", y / (float)nHeight, 1);
            bSaved = FUN_1408710c0(&m_xmlSave, GetStatePath());
        }
    }
    if (FUN_14081b310(&m_xmlAccountSave))
    {
        Unk_AdXmlNode* pAccount = FUN_14081b310(&m_xmlAccountSave);
        if (pAccount)
        {
            __int64 tNow = FUN_140869440();
            CMsTime now(tNow);
            for (Unk_AdXmlNode* pNode = FUN_140345b40(pAccount); pNode;)
            {
                Unk_AdXmlNode* pCur = pNode;
                pNode = FUN_1403f0510(pNode);
                __int64 nSaleEnd = 0;
                FUN_1408732e0(pCur, "saleEndTime", nSaleEnd);
                CMsTime saleEnd(nSaleEnd);
                if (nSaleEnd != 0 && FUN_1406c4cc0(saleEnd, now))
                    FUN_14086e580(pAccount, pCur);
            }
        }
        bSaved |= FUN_1408710c0(&m_xmlAccountSave, GetAccountStatePath());
    }
    FUN_14086ddc0(&m_xmlSave);
    FUN_14086ddc0(&m_xmlLoaded);
    FUN_14086ddc0(&m_xmlAccountSave);
    FUN_14086ddc0(&m_xmlAccountLoaded);
    return bSaved;
}

// @0x140e3f9b0
// MS2-FUNCTIONAL: behaviour-equivalent; branch/temporary layout differs from the exe
int UIAdPushDialog::vfunc_5()
{
    FUN_14086ddc0(&m_xmlLoaded);
    m_78 = 0;
    if (FUN_140870fc0(&m_xmlLoaded, GetStatePath(), 0))
    {
        Unk_AdXmlNode* pNode = FUN_140165cf0(&m_xmlLoaded, CStringA(vfunc_1()));
        if (!pNode)
            return 0;
        MS2Ptr<ASDialog> dlg(m_limitedBundle);
        if (dlg.get())
        {
            float rateX = 0.0f, rateY = 0.0f;
            CStringA strKey("limitedbundle");
            FUN_140874210(pNode, strKey, "rateX", &rateX);
            FUN_140874210(pNode, strKey, "rateY", &rateY);
            unsigned nWidth = 0, nHeight = 0;
            FUN_14025e7a0()->FUN_1422b06e0(FUN_1422db730(), &nWidth, &nHeight);
            dlg->FUN_1422c00f0((float)nWidth * rateX, (float)nHeight * rateY);
        }
        m_78 = 1;
    }
    if (FUN_14081b310(&m_xmlSave))
        FUN_14086ddc0(&m_xmlSave);
    TiXmlElement* pElem = new TiXmlElement(vfunc_1());
    FUN_14086e090(&m_xmlSave, pElem);
    FUN_140870fc0(&m_xmlAccountLoaded, GetAccountStatePath(), 0);
    if (FUN_14081b310(&m_xmlAccountSave))
        FUN_14086ddc0(&m_xmlAccountSave);
    if (FUN_14081b310(&m_xmlAccountLoaded))
        FUN_140870cf0(&m_xmlAccountSave, &m_xmlAccountLoaded);
    else
    {
        TiXmlElement* pAccountElem = new TiXmlElement(vfunc_1());
        FUN_14086e090(&m_xmlAccountSave, pAccountElem);
    }
    return 1;
}

// @0x140e3ff00
// MS2-FUNCTIONAL: behaviour-equivalent; branch/temporary layout differs from the exe
void UIAdPushDialog::OnLoadComplete()
{
    m_limitedBundle = m_30->FUN_140e159f0<ASDialog>("m_limitedBundle");
    UIDialog::OnLoadComplete();
    if (m_limitedBundle.get())
        FUN_1422c3600(m_limitedBundle.get(), "dirtyPos", Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIAdPushDialog::OnDirtyPos), 0, 0, 0, 0);
    Refresh(4);
    FUN_140939a10()->FUN_140da4e40(L"NotifyGameEventChanged", Delegate<void(NotifyObject*)>(this, &UIAdPushDialog::OnNotifyGameEventChanged));
}

// @0x140e401b0
void UIAdPushDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_nFlags = 0;
    m_entities.RemoveAll();
    m_pending.RemoveAll();
    m_sns.clear();
    m_limitedBundle = 0;
    m_tick.FUN_140268840();
    FUN_140939a10()->FUN_140da4eb0(L"NotifyCompleteMyPC", Delegate<void(NotifyObject*)>(this, &UIAdPushDialog::OnNotifyCompleteMyPC));
    FUN_140939a10()->FUN_140da4eb0(L"NotifyGameEventChanged", Delegate<void(NotifyObject*)>(this, &UIAdPushDialog::OnNotifyGameEventChanged));
}

// @0x140e403f0
void UIAdPushDialog::vfunc_76()
{
}

// @0x140e40400
void UIAdPushDialog::vfunc_49(Scaleform::GFx::Value* pValue, ASData* pData)
{
    UIObject::vfunc_49(pValue, pData);
    int nId = FUN_1422b8a10(pData);
    MS2Ptr<AdPushEntityBase> entity(0);
    if (m_entities.Lookup(nId, entity))
    {
        if (entity.get())
            entity->vfunc_8(pValue, pData);
    }
}

// @0x140e404c0
void UIAdPushDialog::vfunc_43()
{
    if (m_90 == 0)
    {
    }
    else
    {
        m_90->vfunc_2(5, 0, 0);
        if (m_60 != 0)
            ShowOrRetry();
        FixPosition();
    }
}

// @0x140e40550
// MS2-FUNCTIONAL: behaviour-equivalent; branch/temporary layout differs from the exe
void UIAdPushDialog::vfunc_44(int a1, int a2, int a3, int* pWidth, int* pHeight)
{
    if (FUN_1422dc430() != 0 && !(m_limitedBundle == 0))
    {
        MS2Ptr<ASDisplayObject> root = FUN_1422dba50();
        if (root.get())
            root->vfunc_2(5, 0, 0);
        m_limitedBundle->vfunc_2(a1, a2, a3);
        *pWidth = FUN_1422e6310(m_limitedBundle.get());
        *pHeight = FUN_1422e6270(m_limitedBundle.get());
    }
}

// @0x140e40690
void UIAdPushDialog::vfunc_67()
{
    CloseAll();
    UIDialog::vfunc_67();
}

// @0x140e406c0
// MS2-FUNCTIONAL: behaviour-equivalent; branch/temporary layout differs from the exe
bool UIAdPushDialog::AddBundle(MS2Ptr<Unk_AdMarketItem> item, int n4c, int n50, bool bMinimized)
{
    if (item == 0 || item->m_nB8 != 3)
        return false;
    if (item->m_n124 == 0)
        return false;
    if (m_sns.find(item->m_nSn) != m_sns.end())
        return false;
    if (!FUN_140939a00()->FUN_140d5b370(item))
        return false;
    int nId = CPtred::InterlockedInc(&DAT_1439f60ac);
    MS2Ptr<AdPushEntityLimitedBundle> bundle(new AdPushEntityLimitedBundle(nId));
    bundle->m_item = item;
    bundle->m_n50 = n50;
    bundle->m_n4c = n4c;
    bundle->m_bMinimized = bMinimized;
    m_sns.insert(item->m_nSn);
    m_pending.SetAt(nId, MS2Ptr<AdPushEntityBase>(bundle.get()));
    return true;
}

// @0x140e409b0
bool UIAdPushDialog::RemoveEntityKey(const int& nId)
{
    if (!m_entities.IsEmpty())
    {
        m_entities.RemoveKey(nId);
        if (m_entities.IsEmpty())
            DAT_1439f60ac = 1;
    }
    return true;
}

// @0x140e40a30
bool UIAdPushDialog::RemoveBundle(MS2Ptr<AdPushEntityLimitedBundle> bundle)
{
    if (bundle == 0)
        return false;
    int nId = bundle->FUN_140e42560();
    RemoveEntityKey(nId);
    int nSn = 0;
    if (bundle->m_item.get())
        nSn = bundle->m_item->m_nSn;
    if (0 < nSn)
        m_sns.erase(nSn);
    return true;
}

// @0x140e40b20
// MS2-FUNCTIONAL: behaviour-equivalent; branch/temporary layout differs from the exe
bool UIAdPushDialog::Refresh(unsigned nFlags)
{
    m_nFlags |= nFlags;
    if ((m_nFlags & 2) == 0)
    {
        Unk_AdPlayerMgr* pPlayer = FUN_1403ed2d0();
        Unk_AdActor* pActor = FUN_141bd0cc0(pPlayer);
        if (pActor && pActor->FUN_14123bea0() == 1)
            m_nFlags |= 2;
    }
    if (m_nFlags < 7)
        return false;
    if (m_30 == 0)
        return false;
    if (m_pending.IsEmpty())
        return true;
    POSITION pos = m_pending.GetHeadPosition();
    while (pos)
    {
        POSITION cur = pos;
        m_pending.GetNext(pos);
        MS2Ptr<AdPushEntityBase> entity = m_pending.GetValueAt(cur);
        if (entity.get())
        {
            bool bAccount = entity->vfunc_7();
            Unk_AdXmlNode* pNode = FindLoadedEntry(entity->vfunc_6(), bAccount);
            entity->vfunc_5(pNode);
            entity->vfunc_1();
            m_entities.SetAt(entity->FUN_140e42560(), entity);
        }
    }
    m_pending.RemoveAll();
    return true;
}

// @0x140e40de0
// MS2-FUNCTIONAL: behaviour-equivalent; branch/temporary layout differs from the exe
void UIAdPushDialog::UpdateBundles(MS2Ptr<Unk_AdMarketItem> item)
{
    if (!(m_30 == 0) && !m_entities.IsEmpty() && !(item == 0))
    {
        POSITION pos = m_entities.GetHeadPosition();
        while (pos)
        {
            MS2Ptr<AdPushEntityBase> entity = m_entities.GetValueAt(pos);
            if (!(entity == 0) && entity->FUN_140e42540() == 1)
            {
                MS2Ptr<AdPushEntityLimitedBundle> bundle(dynamic_cast<AdPushEntityLimitedBundle*>(m_entities.GetValueAt(pos).get()));
                if (bundle.get())
                    bundle->Update(item);
            }
            m_entities.GetNext(pos);
        }
    }
}

// @0x140e41000
// MS2-FUNCTIONAL: behaviour-equivalent; branch/temporary layout differs from the exe
void UIAdPushDialog::OnNotifyGameEventChanged(NotifyObject* pNotify)
{
    if (m_limitedBundle == 0)
        return;
    NotifyGameEventChanged* pEvent = dynamic_cast<NotifyGameEventChanged*>(pNotify);
    if (pEvent && !FUN_140e45240(pEvent->m_eventName, "DTReward"))
    {
        if (pEvent->m_type == 0)
        {
            Unk_AdActor* pActor = FUN_141bd0cc0(FUN_1403ed2d0());
            if (pActor && FUN_1408d7e60(FUN_14041beb0(), pActor->vfunc_78()))
                ShowOrRetry();
        }
        else if (pEvent->m_type == 1)
            ShowOrRetry();
    }
}

// @0x140e41110
bool UIAdPushDialog::IsAnyAnimating()
{
    if (m_entities.IsEmpty())
        return false;
    for (POSITION pos = m_entities.GetHeadPosition(); pos; m_entities.GetNext(pos))
    {
        AdPushEntityBase* p = m_entities.GetValueAt(pos).get();
        if (p && p->vfunc_10())
            return true;
    }
    return false;
}

// @0x140e411d0
bool UIAdPushDialog::MaximizeAll()
{
    if (m_entities.IsEmpty())
        return false;
    for (POSITION pos = m_entities.GetHeadPosition(); pos; m_entities.GetNext(pos))
    {
        AdPushEntityBase* p = m_entities.GetValueAt(pos).get();
        if (p)
            p->vfunc_11();
    }
    return false;
}

// @0x140e41280
// MS2-FUNCTIONAL: behaviour-equivalent; branch/temporary layout differs from the exe
Unk_AdXmlNode* UIAdPushDialog::FindLoadedEntry(const CStringA& strName, bool bAccount)
{
    if (strName.IsEmpty())
        return 0;
    Unk_AdXmlNode* pRoot = GetLoadedRoot(bAccount);
    if (!bAccount)
        return FindByName(pRoot, strName);
    Unk_AdXmlNode* pNode = FindByName(pRoot, strName);
    if (!pNode)
        pNode = FindByName(GetLoadedRoot(false), strName);
    return pNode;
}

// @0x140e41350
// MS2-FUNCTIONAL: behaviour-equivalent; branch/temporary layout differs from the exe
Unk_AdXmlNode* UIAdPushDialog::GetLoadedRoot(bool bAccount)
{
    return bAccount ? FUN_14081b310(&m_xmlAccountLoaded) : FUN_14081b310(&m_xmlLoaded);
}

// @0x140e413c0
Unk_AdXmlNode* UIAdPushDialog::FindSaveEntry(const CStringA& strName, bool bAccount)
{
    if (strName.IsEmpty())
        return 0;
    Unk_AdXmlNode* pRoot = GetSaveRoot(bAccount);
    if (!pRoot)
        return 0;
    return FUN_140872ec0(pRoot, strName, 1);
}

// @0x140e41430
// MS2-FUNCTIONAL: behaviour-equivalent; branch/temporary layout differs from the exe
Unk_AdXmlNode* UIAdPushDialog::GetSaveRoot(bool bAccount)
{
    return bAccount ? FUN_14081b310(&m_xmlAccountSave) : FUN_14081b310(&m_xmlSave);
}

// @0x140e414a0
Unk_AdXmlNode* UIAdPushDialog::FindByName(Unk_AdXmlNode* pRoot, const CStringA& strName)
{
    if (!pRoot)
        return 0;
    for (Unk_AdXmlNode* pNode = FUN_140345b40(pRoot); pNode; pNode = FUN_1403f0510(pNode))
    {
        if (strName.CompareNoCase(FUN_140189180(pNode)) == 0)
            return pNode;
    }
    return 0;
}

// @0x140e41520
CStringA UIAdPushDialog::GetStatePath()
{
    return FUN_140cc2a00(FUN_1412755f0(), FUN_14038f6d0(vfunc_1(), ".xml"));
}

// @0x140e41610
// MS2-FUNCTIONAL: behaviour-equivalent; branch/temporary layout differs from the exe
CStringA UIAdPushDialog::GetAccountStatePath()
{
    CStringA strFile;
    StringFormat(strFile, "{0}{1}", vfunc_1(), "Account.xml");
    return FUN_140cc2a00(FUN_141275640(), strFile);
}

// @0x140e416f0
void UIAdPushDialog::OnNotifyCompleteMyPC(NotifyObject*)
{
    Refresh(2);
}

// @0x140e41720
// MS2-FUNCTIONAL: behaviour-equivalent; branch/temporary layout differs from the exe
MS2Ptr<ASMovieClip> UIAdPushDialog::AddBadge(MS2Ptr<AScript> value)
{
    if (m_30 == 0 || value == 0)
        return MS2Ptr<ASMovieClip>(0);
    Scaleform::GFx::Value v = m_30->Invoke("addLimitedBundle", value->FUN_1422bb870());
    MS2Ptr<ASMovieClip> clip(new ASMovieClip(v, 2));
    if (clip == 0 || value->FUN_1422ba9a0())
        return MS2Ptr<ASMovieClip>(0);
    return clip;
}

// @0x140e41940
bool UIAdPushDialog::RemoveBadge(MS2Ptr<ASMovieClip> badge)
{
    if (m_30 == 0 || badge == 0)
        return false;
    Scaleform::GFx::Value v = m_30->Invoke("removeLimitedBundle", badge->FUN_1422bb870());
    return FUN_1409c1720(v);
}

// @0x140e41a50
// MS2-FUNCTIONAL: behaviour-equivalent; branch/temporary layout differs from the exe
bool UIAdPushDialog::RemoveEntityById(const int& nId)
{
    MS2Ptr<AdPushEntityBase> entity(0);
    if (!m_entities.Lookup(nId, entity))
        return false;
    return LoadEntity(entity);
}

// @0x140e41b00
bool UIAdPushDialog::LoadEntity(MS2Ptr<AdPushEntityBase> entity)
{
    if (entity == 0)
        return false;
    bool bAccount = entity->vfunc_7();
    Unk_AdXmlNode* pRoot = GetSaveRoot(bAccount);
    Unk_AdXmlNode* pNode = FindSaveEntry(entity->vfunc_6(), bAccount);
    if (!pNode)
        return false;
    entity->vfunc_4(pRoot, pNode);
    return true;
}

// @0x140e41c60
void UIAdPushDialog::ShowOrRetry()
{
    if (FUN_140e45740()->FUN_1422e6bf0(this, 0))
        FUN_140e45740()->FUN_1422e6d00(0);
    else
        FUN_1418ffec0(&m_nShowState, 1);
}

// @0x140e41cc0
void UIAdPushDialog::CloseAll()
{
    if (m_entities.IsEmpty())
        return;
    POSITION pos = m_entities.GetHeadPosition();
    while (pos)
    {
        POSITION cur = pos;
        m_entities.GetNext(pos);
        AdPushEntityBase* p = m_entities.GetValueAt(cur).get();
        if (!p)
            continue;
        p->vfunc_2(true);
    }
}

// @0x140e41d80
// MS2-FUNCTIONAL: behaviour-equivalent; branch/temporary layout differs from the exe
void UIAdPushDialog::FindDirtyPos(float* pX, float* pY)
{
    UIObject* pObj = FUN_140c9b540(0x4e29);
    if (pObj && pObj->FUN_1422dc430() != 0)
    {
        MS2Ptr<ASMovieClip> clip(dynamic_cast<ASMovieClip*>(pObj->FUN_1422dba00().get()));
        if (!(clip == 0) && !(m_limitedBundle == 0))
        {
            double dX = 0.0;
            __int64 n = 0;
            if (FUN_1422c2510(clip.get(), &dX, &n))
            {
                *pX = (float)(dX - (double)m_limitedBundle->FUN_1422c1340());
                *pY = 0.0f;
            }
        }
    }
}

// @0x140e41f30
// MS2-FUNCTIONAL: behaviour-equivalent; branch/temporary layout differs from the exe
bool UIAdPushDialog::FindMinimizePos(float* pX)
{
    if (m_limitedBundle == 0)
        return false;
    UIObject* pObj = FUN_140ce8270(0x4f01);
    if (!pObj)
        return false;
    bool bLoaded = false;
    if (pObj->FUN_1422dc430() != 0 && pObj->FUN_1422dba00().get())
        bLoaded = true;
    if (bLoaded)
    {
        MS2Ptr<ASMovieClip> clip(dynamic_cast<ASMovieClip*>(pObj->FUN_1422dba00().get()));
        if (clip.get() && clip->FUN_1422c1340() > 10)
        {
            double dX = 0.0;
            __int64 n = 0;
            FUN_1422c2510(clip.get(), &dX, &n);
            if ((float)fabs(dX - (double)*pX) < (float)clip->FUN_1422c1340())
            {
                *pX = (float)dX;
                return true;
            }
        }
        return false;
    }
    Unk_AdActor* pActor = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pActor && FUN_1408d7e60(FUN_14041beb0(), pActor->vfunc_78()))
        ShowOrRetry();
    return false;
}

// @0x140e42210
void UIAdPushDialog::OnDirtyPos(const Scaleform::GFx::FunctionHandler::Params&)
{
    if (m_30 == 0)
    {
    }
    else
        ShowOrRetry();
}

// @0x140e42250
// MS2-FUNCTIONAL: behaviour-equivalent; branch/temporary layout differs from the exe
void UIAdPushDialog::FixPosition()
{
    if (m_limitedBundle == 0)
        return;
    MS2Ptr<ASDialog> dlg(m_limitedBundle);
    bool bRetry = FUN_1418ffe80(m_nShowState, 1);
    FUN_1418ffef0(&m_nShowState, 1);
    bool bReset = false;
    int bFixed = (m_60 == 0 && m_78 != 0) ? 1 : 0;
    if (bFixed == 0)
        bReset = true;
    else
    {
        float x = dlg->FUN_1422c10a0();
        float y = dlg->FUN_1422c1110();
        float fMargin = 100.0f;
        if (!(x <= (float)dlg->FUN_1422c1500() + fMargin && y <= (float)dlg->FUN_1422c1530() && fMargin <= x && 0.0f <= y))
            bReset = true;
    }
    if (bReset)
    {
        float x = (float)dlg->FUN_1422c1500() * 0.83f;
        float y = 28.0f;
        FindDirtyPos(&x, &y);
        FindMinimizePos(&x);
        dlg->FUN_1422c00f0(x, y);
    }
    else if (bRetry)
    {
        float x = 0.0f, y = 0.0f;
        dlg->FUN_1422c0f60(&x, &y);
        if (FindMinimizePos(&x))
            dlg->FUN_1422c00f0(x, y);
    }
}

// @0x140e425a0
AdPushEntityLimitedBundle::AdPushEntityLimitedBundle(const int& nId)
    : AdPushEntityBase(nId)
{
    m_nKind = 1;
    m_bTick = true;
    Reset();
}

// @0x140e42670
// MS2-FUNCTIONAL: behaviour-equivalent; branch/temporary layout differs from the exe
void AdPushEntityLimitedBundle::Reset()
{
    m_bMinimized = false;
    m_n4c = 0;
    m_n50 = 0;
    m_endTime = 0;
    m_n78 = 0;
    m_saleEndTime = 0;
    m_bShowRemain = false;
    m_dlg = 0;
    m_badge = 0;
    m_item = 0;
    m_remain = 0;
    m_max = NiPoint2(efd::Point2::ZERO);
}

// @0x140e42740
// MS2-FUNCTIONAL: behaviour-equivalent; branch/temporary layout differs from the exe
void AdPushEntityLimitedBundle::Update(MS2Ptr<Unk_AdMarketItem> item)
{
    if (item == 0)
        return;
    if (m_item->m_nSn == item->m_nSn)
    {
        SetMarketItem(item);
        if (item->m_info.FUN_1406a0cc0())
            vfunc_3();
    }
}

// @0x140e42830
void AdPushEntityLimitedBundle::OnMaximize(const Scaleform::GFx::FunctionHandler::Params&)
{
    SetMinimized(false);
}

// @0x140e42860
// MS2-FUNCTIONAL: behaviour-equivalent; branch/temporary layout differs from the exe
void AdPushEntityLimitedBundle::SetBadge(MS2Ptr<ASMovieClip> badge)
{
    m_badge = badge;
    if (!(m_badge == 0))
    {
        m_remain = m_badge->FUN_1409b4620("m_remainTime");
        FUN_1422c3600(m_badge.get(), "clickMaximize", Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &AdPushEntityLimitedBundle::OnMaximize), 0, 0, 0, 0);
    }
}

// @0x140e42a20
void AdPushEntityLimitedBundle::SetMinimized(bool b)
{
    m_bMinimized = b;
    vfunc_1();
}

// @0x140e42a60
// MS2-FUNCTIONAL: behaviour-equivalent; branch/temporary layout differs from the exe
bool AdPushEntityLimitedBundle::UpdateRemainTime()
{
    if (m_remain == 0 || m_item == 0)
        return false;
    if (!m_bShowRemain)
        return true;
    ATL::CTimeSpan left(m_endTime - FUN_140869440());
    if (left < ATL::CTimeSpan(0))
        return vfunc_3(), false;
    int nSeconds = left.GetSeconds();
    __int64 nHours = left.GetTotalHours();
    CStringW strHours;
    if (nHours < 100)
        strHours = StringFormat(L"{0:02d}", nHours);
    else
        strHours = StringFormat(L"{0}", nHours);
    int nMinutes = left.GetMinutes();
    m_remain->FUN_1422c4cd0(StringFormat(L"{0}:{1:02d}:{2:02d}", strHours, nMinutes, nSeconds));
    return true;
}

// @0x140e42c90
void AdPushEntityLimitedBundle::SetMaximizePos(float x, float y)
{
    m_max.x = x;
    m_max.y = y;
}

// @0x140e42cf0
void AdPushEntityLimitedBundle::SetMarketItem(MS2Ptr<Unk_AdMarketItem> p)
{
    m_item = p;
}

// @0x140e42d40
// MS2-FUNCTIONAL: behaviour-equivalent; branch/temporary layout differs from the exe
bool AdPushEntityLimitedBundle::vfunc_1()
{
    int nRemain = m_item->m_nRemain;
    if (m_endTime == 0)
    {
        if (0 < nRemain)
            m_endTime = FUN_140869440() + nRemain;
    }
    else if (nRemain == 0)
        m_endTime = 0;
    m_bShowRemain = 0 < m_endTime;
    UIAdPushDialog* pDlg = FUN_140d61c00(eUI_4f34);
    if (!pDlg)
        return false;
    if (!m_bMinimized)
    {
        if (m_dlg == 0)
            m_dlg.AssignRaw(new UIAdPushLimitedDialog());
        if (m_dlg.get())
        {
            if (m_item.get())
            {
                MS2Ptr<Unk_AdMarketItem> fresh = FUN_140939a00()->FUN_140d578d0(m_item->m_id);
                if (fresh.get())
                    SetMarketItem(fresh);
            }
            m_dlg->FUN_140e03440(MS2Ptr<AdPushEntityLimitedBundle>(this));
            if (!m_dlg->FUN_140e044b0())
                return false;
        }
    }
    else
    {
        if (m_badge == 0)
        {
            MS2Ptr<AScript> script(new AScript(2));
            if (script.get())
            {
                CStringA strIcon = m_item->m_info.FUN_1406a0160();
                FUN_1407cba60(script.get(), s_strIconPath, CStringA(strIcon));
                FUN_1407cbbe0(script.get(), "visible", true);
                FUN_1407cb9c0(script.get(), "id", m_nId);
                FUN_1407cbbe0(script.get(), "showRemainTime", m_bShowRemain);
                SetBadge(pDlg->AddBadge(script));
            }
        }
        UpdateRemainTime();
        if (m_dlg.get())
        {
            m_dlg->vfunc_68();
            m_dlg = 0;
        }
    }
    if (m_badge.get())
    {
        m_badge->vfunc_4(m_bMinimized);
        FUN_1422c8120(m_badge.get(), m_bMinimized);
    }
    return true;
}

// @0x140e43340
void AdPushEntityLimitedBundle::vfunc_2(bool bRemove)
{
    UIAdPushDialog* pDlg = FUN_140d61c00(eUI_4f34);
    if (!pDlg)
        return;
    if (!bRemove)
    {
        if (m_badge.get())
            pDlg->vfunc_8(0);
    }
    else
        m_badge = 0;
    if (m_dlg.get())
        m_dlg->vfunc_68();
    pDlg->LoadEntity(MS2Ptr<AdPushEntityBase>(this));
}

// @0x140e43430
void AdPushEntityLimitedBundle::vfunc_3()
{
    UIAdPushDialog* pDlg = FUN_140d61c00(eUI_4f34);
    if (!pDlg)
        return;
    pDlg->LoadEntity(MS2Ptr<AdPushEntityBase>(this));
    if (m_badge.get())
        pDlg->RemoveBadge(MS2Ptr<ASMovieClip>(m_badge));
    m_badge = 0;
    if (m_dlg.get())
        m_dlg->vfunc_68();
    m_dlg = 0;
    pDlg->RemoveBundle(MS2Ptr<AdPushEntityLimitedBundle>(this));
}

// @0x140e43590
// MS2-FUNCTIONAL: behaviour-equivalent; branch/temporary layout differs from the exe
void AdPushEntityLimitedBundle::vfunc_4(Unk_AdXmlNode* pRoot, Unk_AdXmlNode* pNode)
{
    if (pNode)
    {
        if (m_item.get() && m_item->m_info.FUN_1406a0cc0())
        {
            if (pRoot)
                FUN_14086e580(pRoot, pNode);
            return;
        }
        FUN_1408740a0(pNode, "marketSN", m_item->m_id.FUN_1409b0470());
        FUN_140873bc0(pNode, "minimize", m_bMinimized);
        FUN_140873eb0(pNode, "endTime", m_endTime);
        __int64 nSaleEnd = FUN_140282020(m_item->m_info.FUN_1406a1a70(0));
        FUN_140873eb0(pNode, "saleEndTime", nSaleEnd);
        unsigned nWidth = 0, nHeight = 0;
        FUN_14025e7a0()->FUN_1422b06e0(2, &nWidth, &nHeight);
        FUN_1408744b0(pNode, "transform", "rateX_maximize", m_max.x / (float)nWidth, 1);
        FUN_1408744b0(pNode, "transform", "rateY_maximize", m_max.y / (float)nHeight, 1);
    }
}

// @0x140e437f0
// MS2-FUNCTIONAL: behaviour-equivalent; branch/temporary layout differs from the exe
void AdPushEntityLimitedBundle::vfunc_5(Unk_AdXmlNode* pNode)
{
    if (pNode)
    {
        FUN_1408730a0(pNode, "minimize", m_bMinimized);
        FUN_1408732e0(pNode, "endTime", m_endTime);
        FUN_1408732e0(pNode, "saleEndTime", m_saleEndTime);
        unsigned nWidth = 0, nHeight = 0;
        FUN_14025e7a0()->FUN_1422b06e0(2, &nWidth, &nHeight);
        NiPoint2 rate = NiPoint2(efd::Point2::ZERO);
        FUN_140874210(pNode, "transform", "rateX_maximize", &rate.x);
        FUN_140874210(pNode, "transform", "rateY_maximize", &rate.y);
        m_max.x = rate.x * (float)nWidth;
        m_max.y = rate.y * (float)nHeight;
    }
}

// @0x140e43930
CStringA AdPushEntityLimitedBundle::vfunc_6()
{
    return FUN_140e01de0(MS2Ptr<Unk_AdMarketItem>(m_item));
}

// @0x140e439a0
// MS2-FUNCTIONAL: behaviour-equivalent; branch/temporary layout differs from the exe
bool AdPushEntityLimitedBundle::vfunc_7()
{
    return m_item.get() && m_item->m_nB8 == 1;
}

// @0x140e43a00
// MS2-FUNCTIONAL: behaviour-equivalent; branch/temporary layout differs from the exe
void AdPushEntityLimitedBundle::vfunc_8(Scaleform::GFx::Value* pValue, ASData* pData)
{
    if (!(m_item == 0))
    {
        ASTooltip tip(4, 2);
        FUN_1409e3190(&tip, &m_item->m_info, m_bMinimized, pData);
        *pValue = tip.FUN_1422bb870();
    }
}

// @0x140e43ad0
// MS2-FUNCTIONAL: behaviour-equivalent; branch/temporary layout differs from the exe
void AdPushEntityLimitedBundle::vfunc_9()
{
    if (m_bMinimized && !(m_remain == 0) && m_badge.get())
        UpdateRemainTime();
}

// @0x140e43b30
// MS2-FUNCTIONAL: behaviour-equivalent; branch/temporary layout differs from the exe
bool AdPushEntityLimitedBundle::vfunc_10()
{
    if (!m_bMinimized && m_dlg.get())
        return m_dlg->FUN_IsFloating() == 1;
    return false;
}

// @0x140e43bc0
bool AdPushEntityLimitedBundle::vfunc_11()
{
    if (m_bMinimized)
        return true;
    SetMinimized(true);
    return true;
}

// @0x140e42cd0
NiPoint2* AdPushEntityLimitedBundle::GetMaximizePos()
{
    return &m_max;
}

// @0x140e45240
// MS2-FUNCTIONAL: behaviour-equivalent; branch/temporary layout differs from the exe
bool FUN_140e45240(const CStringW& s, const char* c)
{
    CStringW t(c, s.GetManager());
    return FUN_140164830(s, t);
}

// @0x140e45740
Unk_140e45740* FUN_140e45740()
{
    return DAT_143ac5d88;
}

// @0x140e44fb0
// MS2-FUNCTIONAL: behaviour-equivalent; branch/temporary layout differs from the exe
AdPushEntityBase::~AdPushEntityBase()
{
}

// @0x140e44fd0
// MS2-FUNCTIONAL: behaviour-equivalent; branch/temporary layout differs from the exe
AdPushEntityLimitedBundle::~AdPushEntityLimitedBundle()
{
}

// @0x140e47420
// MS2-FUNCTIONAL: the CRT inline memmove_s, emitted here as a COMDAT copy that nothing in this unit calls
unsigned long long FUN_140e47420(void* pDst, unsigned long long nDstSize, void* pSrc, unsigned long long nCount)
{
    if (nCount == 0)
        return 0;
    if (pDst == 0)
    {
        *_errno() = 0x16;
        _invalid_parameter_noinfo();
        return 0x16;
    }
    if (pSrc == 0)
    {
        *_errno() = 0x16;
        _invalid_parameter_noinfo();
        return 0x16;
    }
    if (nDstSize < nCount)
    {
        *_errno() = 0x22;
        _invalid_parameter_noinfo();
        return 0x22;
    }
    memmove(pDst, pSrc, nCount);
    return 0;
}
