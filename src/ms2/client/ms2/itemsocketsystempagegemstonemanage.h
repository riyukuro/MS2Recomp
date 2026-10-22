#pragma once
#include "itemsocketsystempagebase.h"
#include "itemsocketsystempagecontrols.h"
#include "ms2/placeholder/uiitemeventlistener.h"
#include "ms2/placeholder/cgemstoneitem.h"
class ASSlot;
class CMsgBoxData;
class Unk_SocketPageButton : public ASUIComponent {};

class ItemSocketSystemPageGemStoneManage : public ItemSocketSystemPageBase, public UIItemEventListener {
public:
    using ItemSocketSystemPageBase::vfunc_8;
    ItemSocketSystemPageGemStoneManage();
    virtual ~ItemSocketSystemPageGemStoneManage();
    void vfunc_1() override;
    void vfunc_2() override;
    int vfunc_3(const char*, const Scaleform::GFx::Value*, int) override;
    void vfunc_5(CInPacket*) override;
    void vfunc_7(MS2Ptr<AScript>) override;
    void vfunc_2(void*) override;
    void vfunc_3(void*, bool) override;
    void vfunc_4(void*, int) override;
    void FUN_140f70620();
    void FUN_140f70770();
    void FUN_140f70ad0();
    void FUN_140f70c70();
    void FUN_140f70f90(MS2Ptr<CItem>);
    void FUN_140f71330(MS2Ptr<CItem>);
    void FUN_140f71530(int);
    MS2Ptr<CItem> FUN_140f71e10(const CAtlArray<MS2Ptr<CItem>>&, int);
    void FUN_140f71ea0(ASObj&);
    void FUN_140f72460(CInPacket*);
    void FUN_140f727e0(CInPacket*);
    void SendItemSocketSystemMode16(const Scaleform::GFx::FunctionHandler::Params&);
    bool FUN_140f72bc0(int, const CMsgBoxData&);
    bool FUN_140f72c80(int, const CMsgBoxData&);
    void FUN_140f72e60(ItemInfoSlot&, ASSlot&);
    MS2Ptr<CGemStoneItem> FUN_140f733a0(CAtlArray<MS2Ptr<CGemStoneItem>>&, unsigned);

    int m_state;
    CString m_equipmentName, m_gemName, m_selectedName, m_socketName;
    MS2Ptr<CItem> m_selected;
    CAtlArray<MS2Ptr<CItem>> m_equipment;
    CAtlMap<__int64, MS2Ptr<CItem>> m_gemsByUid;   // keyed by the item uid (SetAt 0x140cd6c10 takes the 64-bit key)
    CAtlArray<MS2Ptr<CItem>> m_gems;
    CAtlArray<MS2Ptr<CGemStoneItem>> m_sockets;
    MS2Ptr<Unk_SocketPageBag> m_equipmentControl, m_gemControl;
    MS2Ptr<Unk_SocketPageButton> m_debugButton;
    int m_selectedType;
};
MS2_CHECK_SIZE(ItemSocketSystemPageGemStoneManage, 0x150);
MS2_CHECK_OFFSET(ItemSocketSystemPageGemStoneManage, m_state, 0x38);
MS2_CHECK_OFFSET(ItemSocketSystemPageGemStoneManage, m_gemsByUid, 0x90);
MS2_CHECK_OFFSET(ItemSocketSystemPageGemStoneManage, m_sockets, 0xf8);
MS2_CHECK_OFFSET(ItemSocketSystemPageGemStoneManage, m_debugButton, 0x138);
