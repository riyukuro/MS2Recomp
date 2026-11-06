// RTTI TUserCommandInfo, source field names inferred from chatCommand.xml.
#pragma once
#include <afx.h>
#include "ms2/placeholder/cptred.h"
class TUserCommandInfo : public CPtred {
public:
    TUserCommandInfo();
    virtual ~TUserCommandInfo() = default;
    CStringW function;
    int chatType,stringId;
    int GetChatType() const { return chatType; }   // 0x141a1cae0
    CStringW suffix,firstAlias;
};
MS2_CHECK_SIZE(TUserCommandInfo,0x38);
MS2_CHECK_OFFSET(TUserCommandInfo,function,0x18);
MS2_CHECK_OFFSET(TUserCommandInfo,suffix,0x28);

#include "ms2/placeholder/ascript.h"
template<> class MS2Ptr<TUserCommandInfo> {
public:
    MS2Ptr(int) { m_p=0; }
    MS2Ptr() { m_p=0; }
    MS2Ptr(TUserCommandInfo* p) { m_p=p; AddRef(); }
    MS2Ptr(const MS2Ptr& p) { m_p=p.m_p; AddRef(); }
    MS2Ptr(MS2Ptr&& p) { m_p=p.m_p; p.m_p=0; }
    ~MS2Ptr() { Release(); }
    MS2Ptr& operator=(const MS2Ptr& p) { p.AddRef(); Release(); m_p=p.m_p; return *this; }
    TUserCommandInfo* get() const { return m_p; }
    TUserCommandInfo* operator->() const { return m_p; }
    bool operator==(TUserCommandInfo* p) const { return m_p==p; }
private:
    void AddRef() const { if(m_p) AddRefImpl(0); }
    void AddRefImpl(void*) const { Reference(m_p); }
    static void Reference(TUserCommandInfo* p) { CPtred::AddRefPtred(p); }
    void Release() { if(m_p) { ReleaseImpl(0); m_p=0; } }
    void ReleaseImpl(void*) { if(CPtred::ReleasePtred(m_p)==0) { Reference(m_p); CPtred::DeletePtred(m_p); } }
    void* m_unknown;
    TUserCommandInfo* m_p;
};
MS2_CHECK_SIZE(MS2Ptr<TUserCommandInfo>,0x10);
