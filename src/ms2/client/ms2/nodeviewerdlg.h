// nodeviewerdlg.h - CNodeViewerDlg (RTTI .?AVCNodeViewerDlg@@): the tool dialog (resource 0x9f) that shows the scene-graph
// tree of the entity under the camera and marks one node. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the
// unit is `?\nodeviewerdlg.cpp` (0x140c7eea0-0x140c7fc20). Header name assumed. Member names are invented.
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/placeholder/tfunctor_small.h"
#include <NiNode.h>

// The tree dialog (unrecovered CToolTreeNodesDialog, 0x228 bytes, ctor 0x1418589d0).
class CToolTreeNodesDialog : public CDialog
{
public:
    CToolTreeNodesDialog(TFunctor<void, ParamList<CString, EmptyParam> > kOnSelect, CWnd* pParent);
    void FUN_141858b50(class Unk_TreeNode* pRoot);                  // show the hierarchy of a node
    afx_msg void OnClose();                                         // 0x141858d20
    char m_pad_tree[0x228 - sizeof(CDialog)];
};

class CNodeViewerDlg : public CDialog
{
    DECLARE_DYNAMIC(CNodeViewerDlg)
public:
    CNodeViewerDlg(CWnd* pParent);                                  // 0x140c7eec0
    virtual ~CNodeViewerDlg();                                      // 0x140c7ef70 (deleting dtor 0x140c7fb70)

    void FUN_140c7f0f0();                                           // find the node named m_strNode and mark it
    void SetNodeName(CString kName);                              // tree selection callback
public:
    virtual void DoDataExchange(CDataExchange* pDX);                // slot 66
    virtual BOOL OnInitDialog();                                    // slot 96
    afx_msg void FUN_140c7f680();                                   // IDCANCEL
    afx_msg void FUN_140c7f770();                                   // IDOK: open the tree
    afx_msg void FUN_140c7f810();                                   // 0x4e3: apply the typed name
    DECLARE_MESSAGE_MAP()

public:
    CToolTreeNodesDialog* m_pTree;                                  // +0x130
    CString m_strNode;                                              // +0x138
    CString m_strInput;                                             // +0x140 (DDX edit 0x4e2)
    NiNodePtr m_node;                                               // +0x148 the marker node
};
MS2_CHECK_SIZE(CNodeViewerDlg, 0x150);
