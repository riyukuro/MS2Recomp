// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CToolTreeNodesDialog: see tooltreenodesdialog.h.
// MS2-UNIT: ?\tooltreenodesdialog.cpp
// MS2-RANGE: 0x1418589b0-0x141859130 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\tooltreenodesdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "tooltreenodesdialog.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local placeholders (the node hierarchy is unrecovered) ----

class Unk_TreeNode
{
public:
    unsigned FUN_14098daf0();                                   // the child count
    Unk_TreeNode* FUN_14098db40(unsigned nIndex);               // the nIndex-th child entry
};
class Unk_NodeManager { public: Unk_TreeNode* FUN_14098d8d0(Unk_TreeNode* pEntry); };   // the node of an entry (NULL: gone)
extern int DAT_143afa4d8;                                       // the global node manager
void* FUN_1409a8b90(Unk_TreeNode* pNode);                       // the node's name object
const char* FUN_142087e50(void* pName);                         // its text

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
CToolTreeNodesDialog::CToolTreeNodesDialog(Unk_ToolCallback callback, CWnd* pParent)
    : CDialog(0x80, pParent)
    , m_callback(callback)
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
    ON_NOTIFY(TVN_SELCHANGED, 0x458, &CToolTreeNodesDialog::OnTvnSelchangedTree)
END_MESSAGE_MAP()

// @0x141858b50
void CToolTreeNodesDialog::FUN_141858b50(Unk_TreeNode* pRoot)
{
    m_pNode = pRoot;
    TVINSERTSTRUCT tvis;
    tvis.hParent = TVI_ROOT;
    tvis.hInsertAfter = TVI_LAST;
    tvis.item.mask = TVIF_TEXT;
    tvis.item.pszText = (LPSTR)FUN_142087e50(FUN_1409a8b90(pRoot));
    HTREEITEM hItem = m_treeNodes.InsertItem(&tvis);
    FUN_141858c00(hItem, pRoot);
}

// @0x141858c00
void CToolTreeNodesDialog::FUN_141858c00(HTREEITEM hParent, Unk_TreeNode* pNode)
{
    for (unsigned i = 0; i < pNode->FUN_14098daf0(); ++i) {
        Unk_TreeNode* pEntry = pNode->FUN_14098db40(i);
        if (((Unk_NodeManager*)&DAT_143afa4d8)->FUN_14098d8d0(pEntry) != 0) {
            TVINSERTSTRUCT tvis;
            tvis.hParent = hParent;
            tvis.hInsertAfter = TVI_LAST;
            tvis.item.mask = TVIF_TEXT;
            tvis.item.pszText = (LPSTR)FUN_142087e50(FUN_1409a8b90(pEntry));
            FUN_141858c00(m_treeNodes.InsertItem(&tvis), ((Unk_NodeManager*)&DAT_143afa4d8)->FUN_14098d8d0(pEntry));
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
void CToolTreeNodesDialog::OnTvnSelchangedTree(NMHDR* pNMHDR, LRESULT* pResult)
{
    LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
    CString strText = m_treeNodes.GetItemText(pNMTreeView->itemNew.hItem);
    if (!m_callback.IsEmpty())
        m_callback.Call(strText);
    *pResult = 0;
}
