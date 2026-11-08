// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CToolTreeNodesDialog: see tooltreenodesdialog.h.
// MS2-UNIT: ?\tooltreenodesdialog.cpp
// MS2-RANGE: 0x1418589b0-0x141859130 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\tooltreenodesdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "tooltreenodesdialog.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <NiFixedString.h>

// ---- unit-local placeholders (the node hierarchy is unrecovered) ----

class Unk_TreeNode;
class NiAVObject;
class NiRTTI;
class NiObject   // C3: member view
{
public:
    static NiObject* DynamicCast(const NiRTTI* pRTTI, const NiObject* pObject);
};
class NiNode   // C3: member view
{
public:
    static const NiRTTI ms_RTTI;
    unsigned int GetArrayCount() const;
    NiAVObject* GetAt(unsigned int i) const;
};
class NiObjectNET   // C3: member view for the former free stand-ins
{
public:
    class NiFixedString const& GetName() const;
};

IMPLEMENT_DYNAMIC(CToolTreeNodesDialog, CDialog)

// @0x141858e30
static Unk_ToolCallbackImpl* FUN_141858e30(Unk_ToolCallbackImpl* pImpl)
{
    if (pImpl == 0)
        return 0;
    Unk_ToolCallbackImpl* pClone = pImpl->Clone();
    return pClone;
}

// @0x141858e70
Unk_ToolCallback::Unk_ToolCallback(const Unk_ToolCallback& other)
{
    m_pImpl = FUN_141858e30(other.m_pImpl);
}

// @0x141858ed0
Unk_ToolCallback::~Unk_ToolCallback()
{
    Reset();
}

// @0x141858f00
void Unk_ToolCallback::Call(CString strText)
{
    m_pImpl->Call(strText);
}

// @0x141859060
bool Unk_ToolCallback::IsEmpty() const
{
    return m_pImpl == 0;
}

// @0x1418590c0
void Unk_ToolCallback::Reset()
{
    if (m_pImpl != 0) {
        delete m_pImpl;
        m_pImpl = 0;
    }
}

// @0x1418589d0
CToolTreeNodesDialog::CToolTreeNodesDialog(TFunctor<void, ParamList<CString, EmptyParam> > callback, CWnd* pParent)
    : CDialog(0x80, pParent)
    , m_callback(reinterpret_cast<Unk_ToolCallback&>(callback))
    , m_pNode(0)
{
}

// @0x141858a70
CToolTreeNodesDialog::~CToolTreeNodesDialog()
{
}

// @0x141858ad0
void CToolTreeNodesDialog::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, 0x458, m_treeNodes);
}

BEGIN_MESSAGE_MAP(CToolTreeNodesDialog, CDialog)
    ON_COMMAND(IDOK, &CToolTreeNodesDialog::OnBnClickedOk)
    ON_COMMAND(IDCANCEL, &CToolTreeNodesDialog::OnBnClickedCancel)
    ON_WM_CLOSE()
    ON_NOTIFY(TVN_SELCHANGING, 0x458, &CToolTreeNodesDialog::OnTvnSelchangingTree)   // exe code 0xfe6f (TVN_SELCHANGINGA)
END_MESSAGE_MAP()

// @0x141858b50
void CToolTreeNodesDialog::FUN_141858b50(Unk_TreeNode* pRoot)
{
    m_pNode = pRoot;
    TVINSERTSTRUCT tvis;
    tvis.hParent = TVI_ROOT;
    tvis.hInsertAfter = TVI_LAST;
    tvis.item.mask = TVIF_TEXT;
    tvis.item.pszText = (LPSTR)((class NiObjectNET*)(class Unk_TreeNode*)(pRoot))->GetName().operator const char*();
    HTREEITEM hItem = m_treeNodes.InsertItem(&tvis);
    FUN_141858c00(hItem, pRoot);
}

// @0x141858c00
void CToolTreeNodesDialog::FUN_141858c00(HTREEITEM hParent, Unk_TreeNode* pNode)
{
    for (unsigned i = 0; i < reinterpret_cast<NiNode*>(pNode)->GetArrayCount(); ++i) {
        Unk_TreeNode* pEntry = reinterpret_cast<Unk_TreeNode*>(reinterpret_cast<NiNode*>(pNode)->GetAt(i));
        if (reinterpret_cast<Unk_TreeNode*>(NiObject::DynamicCast(&NiNode::ms_RTTI, reinterpret_cast<NiObject*>(pEntry))) != 0) {
            TVINSERTSTRUCT tvis;
            tvis.hParent = hParent;
            tvis.hInsertAfter = TVI_LAST;
            tvis.item.mask = TVIF_TEXT;
            tvis.item.pszText = (LPSTR)((class NiObjectNET*)(class Unk_TreeNode*)(pEntry))->GetName().operator const char*();
            FUN_141858c00(m_treeNodes.InsertItem(&tvis), reinterpret_cast<Unk_TreeNode*>(NiObject::DynamicCast(&NiNode::ms_RTTI, reinterpret_cast<NiObject*>(pEntry))));
        }
    }
}

// @0x141858d00
void CToolTreeNodesDialog::OnBnClickedOk()
{
}

// @0x141858d10
void CToolTreeNodesDialog::OnBnClickedCancel()
{
}

// @0x141858d20
void CToolTreeNodesDialog::OnClose()
{
    Default();
    m_pNode = 0;
    m_treeNodes.DeleteAllItems();
    EndDialog(2);
}

// @0x141858d70
void CToolTreeNodesDialog::OnTvnSelchangingTree(NMHDR* pNMHDR, LRESULT* pResult)
{
    LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
    CString strText = m_treeNodes.GetItemText(pNMTreeView->itemNew.hItem);
    if (!m_callback.IsEmpty())
        m_callback.Call(strText);
    *pResult = 0;
}
