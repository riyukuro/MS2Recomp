// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The client's nodeviewerdlg.cpp: the scene-node viewer tool dialog.
// MS2-UNIT: ?\nodeviewerdlg.cpp
// MS2-RANGE: 0x140c7eea0-0x140c7fc20 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\nodeviewerdlg.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "nodeviewerdlg.h"
#include "uiservice.h"
#include <NiTransform.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local placeholders ----
class Unk_CameraManager   // C3: member view for the former free stand-ins
{
public:
    class Unk_CameraTargetEntity* FUN_140a38d60();
};
void* FUN_1409478c0();                                              // camera manager
namespace egf { class Entity; }
class GameObject { public: egf::Entity* FUN_14123c410(); };   // C3: unit-local view
NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);                                 // scene root of an entity

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
    if ((NiNode*)m_node != 0)
    {
        NiNode* pParent = m_node->GetParent();
        if (pParent != 0)
            pParent->DetachChild(m_node);
        m_node = 0;
    }
}

// @0x140c7f0f0
void CNodeViewerDlg::FUN_140c7f0f0()
{
    NiNode* pRoot = 0;
    void* pEntity = ((void*)((class Unk_CameraManager*)(void*)(FUN_1409478c0()))->FUN_140a38d60());
    if (pEntity != 0)
    {
        pRoot = static_cast<NiNode*>(NiObject::DynamicCast(&NiNode::ms_RTTI, (class NiObject const*)(FUN_141b6efc0(reinterpret_cast<GameObject*>(pEntity)->FUN_14123c410()))));
        if (pRoot != 0)
        {
            NiFixedString kName((const char*)m_strNode);
            NiAVObject* pFound = pRoot->GetObjectByName(kName);
            if (pFound != 0)
            {
                if ((NiNode*)m_node != 0)
                {
                    NiNode* pParent = m_node->GetParent();
                    if (pParent != 0)
                        pParent->DetachChild(m_node);
                }
                else
                {
                    m_node = new (efd::MemHint(efd::MemHint::NONE)) NiNode(0);
                    {
                        NiFixedString kNodeName("NodeViewer");
                        m_node->SetName(kNodeName);
                    }
                    NiTransform kXf;
                    kXf.MakeIdentity();
                    m_node->SetLocalTransform(kXf);
                }
                NiNode* pTarget = static_cast<NiNode*>(NiObject::DynamicCast(&NiNode::ms_RTTI, pFound));
                if (pTarget != 0)
                {
                    pTarget->AttachChild(m_node, false);
                    TSingleton<CUIService>::GetInstance()->FUN_141aec8f0(true, m_node);
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
        m_pTree = new CToolTreeNodesDialog(Unk_NvSelectFunctor(this, &CNodeViewerDlg::SetNodeName), this);
        m_pTree->Create(0x80, this);
        m_pTree->ShowWindow(0);
    }
    return 1;
}

// @0x140c7f5b0
void CNodeViewerDlg::SetNodeName(CString kName)
{
    if (kName == "NodeViewer")
        return;
    m_strNode = kName;
    m_strInput = kName;
    if (!m_strNode.IsEmpty())
        FUN_140c7f0f0();
    else
        TSingleton<CUIService>::GetInstance()->FUN_141aec8f0(false, 0);
    UpdateData(0);
}

// @0x140c7f680
void CNodeViewerDlg::FUN_140c7f680()
{
    TSingleton<CUIService>::GetInstance()->FUN_141aec8f0(false, 0);
    if (m_pTree != 0)
        m_pTree->OnClose();
    if ((NiNode*)m_node != 0)
    {
        NiNode* pParent = m_node->GetParent();
        if (pParent != 0)
            pParent->DetachChild(m_node);
        m_node = 0;
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
        pNode = ((void*)NiObject::DynamicCast(&NiNode::ms_RTTI, (class NiObject const*)(FUN_141b6efc0(reinterpret_cast<GameObject*>(pEntity)->FUN_14123c410()))));
        if (pNode != 0)
        {
            m_pTree->FUN_141858b50((class Unk_TreeNode*)pNode);
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
