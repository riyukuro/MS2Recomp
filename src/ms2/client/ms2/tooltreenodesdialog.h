// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\tooltreenodesdialog.h (name assumed).
//
// CToolTreeNodesDialog (RTTI .?AVCToolTreeNodesDialog@@, 0x228 bytes = CDialog 0x130 + CTreeCtrl 0xe8 + a callback
// holder + a node pointer): the tool dialog of resource 0x80 that shows a node hierarchy (children looked up by id in the
// global node manager) in a tree control (0x458) and reports the text of the node the user selects through a polymorphic
// callback. Member and handler names invented from use.
#pragma once
#include <afxcmn.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/tfunctor_small.h"
class Unk_TreeNode;

// The callback implementation object: a clone-able polymorphic function (slot 0 deleting dtor, 1 clone, 2 call).
class Unk_ToolCallbackImpl
{
public:
    virtual ~Unk_ToolCallbackImpl();
    virtual Unk_ToolCallbackImpl* Clone();
    virtual void Call(CString strText);
};

// The holder: owns one implementation (copy = clone).
class Unk_ToolCallback
{
public:
    Unk_ToolCallback(const Unk_ToolCallback& other);        // 0x141858e70
    ~Unk_ToolCallback();                                    // 0x141858ed0
    bool IsEmpty() const;                                   // 0x141859060
    void Reset();                                           // 0x1418590c0
    void Call(CString strText);                             // 0x141858f00
    Unk_ToolCallbackImpl* m_pImpl;
};
MS2_CHECK_SIZE(Unk_ToolCallback, 8);

class CToolTreeNodesDialog : public CDialog
{
    DECLARE_DYNAMIC(CToolTreeNodesDialog)
public:
    CToolTreeNodesDialog(TFunctor<void, ParamList<CString, EmptyParam> > callback, CWnd* pParent);   // 0x1418589d0
    virtual ~CToolTreeNodesDialog();                                  // 0x141858a70 (deleting dtor 0x141858f70)

    virtual void DoDataExchange(CDataExchange* pDX);                  // slot 66, 0x141858ad0

    void FUN_141858b50(Unk_TreeNode* pRoot);                          // show the hierarchy of a node
    void FUN_141858c00(HTREEITEM hParent, Unk_TreeNode* pNode);       // insert the children recursively
    afx_msg void OnBnClickedOk();                                     // 0x141858d00
    afx_msg void OnBnClickedCancel();                                 // 0x141858d10
    afx_msg void OnClose();                                           // 0x141858d20
    afx_msg void OnTvnSelchangingTree(NMHDR* pNMHDR, LRESULT* pResult);   // 0x141858d70
    DECLARE_MESSAGE_MAP()

public:
    CTreeCtrl m_treeNodes;                                            // +0x130 DDX 0x458
    Unk_ToolCallback m_callback;                                      // +0x218
    Unk_TreeNode* m_pNode;                                            // +0x220
};
MS2_CHECK_SIZE(CToolTreeNodesDialog, 0x228);
