// Recovered UISkillPreviewDialog; names except RTTI class names and slots are invented.
#pragma once
#include "ms2/placeholder/uidialog.h"

class IUIAvatarEventListener
{
public:
    IUIAvatarEventListener();
    virtual int vfunc_o178_0(void*);
    virtual int vfunc_o178_1(void*);
    virtual int vfunc_o178_2(void*);
    virtual int vfunc_o178_3(void*);
};
MS2_CHECK_SIZE(IUIAvatarEventListener, 8);
class Unk_SkillPreviewAvatar;
// The avatar's 16-byte owning pointer; its null predicate is instantiated in this unit.
template<class T> class Unk_SkillPreviewPtr
{
public:
    Unk_SkillPreviewPtr();
    ~Unk_SkillPreviewPtr();
    Unk_SkillPreviewPtr& operator=(T*);
    void Reset(int);
    bool operator==(T*) const;
    T* get() const;
    T* operator->() const;
    bool operator!() const { return m_p == 0; }
private:
    void* m_0;
    T* m_p;
};
MS2_CHECK_SIZE(Unk_SkillPreviewPtr<Unk_SkillPreviewAvatar>, 0x10);

class UISkillPreviewDialog : public UIDialog, public IUIAvatarEventListener
{
public:
    UISkillPreviewDialog();
    virtual ~UISkillPreviewDialog();
    virtual CString GetTypeName();
    virtual void vfunc_26();
    virtual void vfunc_67();
    virtual int vfunc_65();
    virtual void OnLoadComplete();
    virtual void vfunc_15();
    virtual int vfunc_28(const char*, const Scaleform::GFx::Value*, unsigned int);
    virtual void vfunc_25(void*, TPtr<Unk_UISwfEntity_25>, void*, void*);
    virtual void vfunc_16();
    virtual bool vfunc_17();
    virtual int vfunc_o178_1(void*);
    virtual int vfunc_o178_0(void*);
    virtual int vfunc_o178_2(void*);
    void FUN_140e93e70(int, unsigned short);
    void FUN_140e93ff0();
    void FUN_140e94150();
    void FUN_140e941b0();
    virtual int vfunc_48() { return 20163; }
private:
    MS2_LAYOUT_FRIEND;
    Unk_SkillPreviewPtr<Unk_SkillPreviewAvatar> m_avatar;
    int m_skill;
    unsigned short m_level;
};
MS2_CHECK_SIZE(UISkillPreviewDialog, 0x198);
MS2_CHECK_OFFSET(UISkillPreviewDialog, m_avatar, 0x180);
MS2_CHECK_OFFSET(UISkillPreviewDialog, m_skill, 0x190);
MS2_CHECK_OFFSET(UISkillPreviewDialog, m_level, 0x194);
