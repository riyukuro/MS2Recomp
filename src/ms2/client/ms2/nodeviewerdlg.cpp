// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The client's nodeviewerdlg.cpp: the scene-node viewer tool dialog.
// MS2-UNIT: ?\nodeviewerdlg.cpp
// MS2-RANGE: 0x140c7eea0-0x140c7fc20 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\nodeviewerdlg.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "nodeviewerdlg.h"
#include <NiTransform.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local placeholders ----
// The scene-graph node (NiNode-like): the slots used here.
class Unk_NvNode { public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6();
    virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13();
    virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void* vfunc_20(const struct Unk_NvName& kName);         // 0xa0 GetObjectByName
    virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27();
    virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34();
    virtual void s35();
    virtual void vfunc_36(void* child, int flag);                   // 0x120 AttachChild
    virtual void vfunc_37(void* out, void* child); };               // 0x128 DetachChild

// A NiFixedString-like name (ctor 0x140984450, dtor 0x1409845a0).
struct Unk_NvName { Unk_NvName(const char* psz); ~Unk_NvName(); void* m_p; };

extern char DAT_143afa4d8;                                          // NiNode RTTI cast table
class NiObject   // C3: member view for the former free stand-ins
{
public:
    static class NiObject* DynamicCast(class NiRTTI const*, class NiObject const*);
};
void* FUN_1409478c0();                                              // camera manager
class Unk_CameraManager   // C3: member view for the former free stand-ins
{
public:
    class Unk_CameraTargetEntity* FUN_140a38d60();
};
void* FUN_14123c410(void* pEntity);
void* FUN_141b6efc0(void* pEntity);                                 // scene root of an entity
void* FUN_1409475d0(Unk_NodePtr* p);
void* FUN_1409475f0(Unk_NodePtr* p);
void FUN_1409f76f0(Unk_NodePtr* p, void* pNode);
class NiAVObject   // C3: member view for the former free stand-ins
{
public:
    class NiNode* GetParent();
    void SetLocalTransform(class NiTransform const&);
};
void FUN_1405a85c0(void* p);                                        // release a SmartPointer
void* FUN_140876480(void* pOut, int nCategory);                     // memory hint for new
void* FUN_14208a860(unsigned __int64 nSize, unsigned nCategory);
// The marker NiNode (0x130 bytes; ctor 0x141d19760, operator new 0x14208a860 with a memory category).
struct Unk_NvNiNode
{
    Unk_NvNiNode(int n);
    static void* operator new(size_t nSize, unsigned nCategory) throw();
    static void operator delete(void* p, unsigned nCategory);
    char m_pad[0x130];
};
class NiObjectNET   // C3: member view for the former free stand-ins
{
public:
    void SetName(class NiFixedString const&);
};
void* FUN_1403ed2b0();                                              // the UI service
class CUIService   // C3: member view for the former free stand-ins
{
public:
    void FUN_141aec8f0(bool, class NiAVObject*);
};
void FUN_141858d20(CToolTreeNodesDialog* pDlg);
void FUN_141858b50(CToolTreeNodesDialog* pDlg, void* pNode);

typedef TFunctor<void, ParamList<CString, EmptyParam> > Unk_NvSelectFunctor;


// @0x140c7eea0
CRuntimeClass* CNodeViewerDlg::GetRuntimeClass() const
{
    return (CRuntimeClass*)(&CNodeViewerDlg::classCNodeViewerDlg);
}

// @0x140c7eec0
CNodeViewerDlg::CNodeViewerDlg(CWnd* pParent)
    : CDialog(0x9f, pParent), m_pTree(0), m_strInput(""), m_node(0)
{
}

// @0x140c7ef70
CNodeViewerDlg::~CNodeViewerDlg()
{
    if (m_pTree != 0)
    {
        delete m_pTree;
        m_pTree = 0;
    }
    if (FUN_1409475d0(&m_node) != 0)
    {
        Unk_NvNode* pParent = (Unk_NvNode*)((void*)((class NiAVObject*)(void*)(FUN_1409475f0(&m_node)))->GetParent());
        if (pParent != 0)
        {
            void* out;
            pParent->vfunc_37(&out, FUN_1409475d0(&m_node));
            FUN_1405a85c0(&out);
        }
        FUN_1409f76f0(&m_node, 0);
    }
}

// @0x140c7f0f0
void CNodeViewerDlg::FUN_140c7f0f0()
{
    Unk_NvNode* pRoot = 0;
    void* pEntity = ((void*)((class Unk_CameraManager*)(void*)(FUN_1409478c0()))->FUN_140a38d60());
    if (pEntity != 0)
    {
        pRoot = (Unk_NvNode*)((void*)NiObject::DynamicCast((class NiRTTI const*)(&DAT_143afa4d8), (class NiObject const*)(FUN_141b6efc0(FUN_14123c410(pEntity)))));
        if (pRoot != 0)
        {
            Unk_NvName kName((const char*)m_strNode);
            void* pFound = pRoot->vfunc_20(kName);
            if (pFound != 0)
            {
                if (FUN_1409475d0(&m_node) != 0)
                {
                    Unk_NvNode* pParent = (Unk_NvNode*)((void*)((class NiAVObject*)(void*)(FUN_1409475f0(&m_node)))->GetParent());
                    if (pParent != 0)
                    {
                        void* out;
                        pParent->vfunc_37(&out, FUN_1409475d0(&m_node));
                        FUN_1405a85c0(&out);
                    }
                }
                else
                {
                    int catTmp;
                    int* pCat = (int*)FUN_140876480(&catTmp, 0);
                    FUN_1409f76f0(&m_node, new (*pCat) Unk_NvNiNode(0));
                    {
                        Unk_NvName kNodeName("NodeViewer");
                        ((class NiObjectNET*)(void*)(FUN_1409475f0(&m_node)))->SetName(*(class NiFixedString const*)&(kNodeName));
                    }
                    NiTransform kXf;
                    kXf.MakeIdentity();
                    ((class NiAVObject*)(void*)(FUN_1409475f0(&m_node)))->SetLocalTransform(kXf);
                }
                Unk_NvNode* pTarget = (Unk_NvNode*)((void*)NiObject::DynamicCast((class NiRTTI const*)(&DAT_143afa4d8), (class NiObject const*)(pFound)));
                if (pTarget != 0)
                {
                    pTarget->vfunc_36(FUN_1409475d0(&m_node), 0);
                    ((class CUIService*)(void*)(FUN_1403ed2b0()))->FUN_141aec8f0(true, (class NiAVObject*)(FUN_1409475d0(&m_node)));
                }
            }
        }
    }
}

MS2_REPLACE_METHOD(0x140C7F0F0, CNodeViewerDlg, FUN_140c7f0f0, 789, 0xBCDE9F41);

// @0x140c7f410
const AFX_MSGMAP* PASCAL CNodeViewerDlg::GetThisMessageMap()
{
    typedef CNodeViewerDlg ThisClass;
    typedef CDialog TheBaseClass;
    static const AFX_MSGMAP_ENTRY _messageEntries[] =
    {
        ON_COMMAND(IDCANCEL, &CNodeViewerDlg::FUN_140c7f680)
        ON_COMMAND(IDOK, &CNodeViewerDlg::FUN_140c7f770)
        ON_COMMAND(0x4e3, &CNodeViewerDlg::FUN_140c7f810)
        {0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0}
    };
    static const AFX_MSGMAP messageMap = {&TheBaseClass::GetThisMessageMap, &_messageEntries[0]};
    return &messageMap;
}

// @0x140c7f420
const AFX_MSGMAP* CNodeViewerDlg::GetMessageMap() const
{
    return GetThisMessageMap();
}

// @0x140c7f440
void CNodeViewerDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Text(pDX, 0x4e2, m_strInput);
}

MS2_REPLACE_METHOD(0x140C7F440, CNodeViewerDlg, DoDataExchange, 63, 0x43E30418);

// @0x140c7f490
BOOL CNodeViewerDlg::OnInitDialog()
{
    if (CDialog::OnInitDialog() == 0)
        return 0;
    ShowWindow(5);
    if (m_pTree == 0)
    {
        m_pTree = new CToolTreeNodesDialog(Unk_NvSelectFunctor(this, &CNodeViewerDlg::FUN_140c7f5b0), this);
        m_pTree->Create(0x80, this);
        m_pTree->ShowWindow(0);
    }
    return 1;
}

// @0x140c7f5b0
void CNodeViewerDlg::FUN_140c7f5b0(CString kName)
{
    if (kName == "NodeViewer")
        return;
    m_strNode = kName;
    m_strInput = kName;
    if (!m_strNode.IsEmpty())
        FUN_140c7f0f0();
    else
        ((class CUIService*)(void*)(FUN_1403ed2b0()))->FUN_141aec8f0(false, (class NiAVObject*)(0));
    UpdateData(0);
}

// @0x140c7f680
void CNodeViewerDlg::FUN_140c7f680()
{
    ((class CUIService*)(void*)(FUN_1403ed2b0()))->FUN_141aec8f0(false, (class NiAVObject*)(0));
    if (m_pTree != 0)
        FUN_141858d20(m_pTree);
    if (FUN_1409475d0(&m_node) != 0)
    {
        Unk_NvNode* pParent = (Unk_NvNode*)((void*)((class NiAVObject*)(void*)(FUN_1409475f0(&m_node)))->GetParent());
        if (pParent != 0)
        {
            void* out;
            pParent->vfunc_37(&out, FUN_1409475d0(&m_node));
            FUN_1405a85c0(&out);
        }
        FUN_1409f76f0(&m_node, 0);
    }
    CDialog::OnCancel();
}

MS2_REPLACE_METHOD(0x140C7F680, CNodeViewerDlg, FUN_140c7f680, 225, 0x7CAC0EBA);

// @0x140c7f770
void CNodeViewerDlg::FUN_140c7f770()
{
    void* pNode = 0;
    void* pEntity = ((void*)((class Unk_CameraManager*)(void*)(FUN_1409478c0()))->FUN_140a38d60());
    if (pEntity != 0)
    {
        pNode = ((void*)NiObject::DynamicCast((class NiRTTI const*)(&DAT_143afa4d8), (class NiObject const*)(FUN_141b6efc0(FUN_14123c410(pEntity)))));
        if (pNode != 0)
        {
            FUN_141858b50(m_pTree, pNode);
            m_pTree->ShowWindow(5);
        }
    }
}

MS2_REPLACE_METHOD(0x140C7F770, CNodeViewerDlg, FUN_140c7f770, 139, 0x0D8A30C0);

// @0x140c7f810
void CNodeViewerDlg::FUN_140c7f810()
{
    UpdateData(1);
    if (!m_strInput.IsEmpty())
    {
        m_strNode = m_strInput;
        FUN_140c7f0f0();
    }
}
MS2_REPLACE_METHOD(0x140C7F810, CNodeViewerDlg, FUN_140c7f810, 98, 0xC5B3B0FA);
