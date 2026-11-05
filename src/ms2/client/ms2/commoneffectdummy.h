// commoneffectdummy.h - CommonEffectDummy (RTTI name): the shared effect dummy table read from
// Table/defaultEffectDummy.xml. Header name assumed. Member and helper names are invented from use.
#pragma once
#include <afx.h>
#include <typeinfo>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/ms2svrptr.h"
#include "ms2/commonfiles/os.h"
#include "ms2/client/ms2/effectdummy.h"

class CommonEffectDummy : public TSingleton<CommonEffectDummy>, public CValidData<CommonEffectDummy>
{
public:
    typedef MS2SvrPtr<EffectDummyGroup> GroupPtr;
    typedef MS2SvrPtr<CEffectDummy> DummyPtr;

    CommonEffectDummy();                    // 0x140a40060

    bool Load();                            // 0x140a400d0 (name invented)
    CEffectDummy* Find(const CString& name);// 0x140a40180 (arg type unverified)
    size_t Clear();                         // 0x140a40200 (returns the row count; the callers use it)
    bool Get(unsigned int idx, void* pOut); // 0x140a40230
    bool LoadFile(const char* path);        // 0x140a40280

    static void CheckInit();                // 0x140a406c0
    static void SetInit(bool b);            // 0x140a40770

    static bool s_bInit;                    // 0x143ab6710

private:
    MS2_LAYOUT_FRIEND;
    GroupPtr m_pGroup;                      // +0x10
};
MS2_CHECK_SIZE(CommonEffectDummy, 0x20);
MS2_CHECK_OFFSET(CommonEffectDummy, m_pGroup, 0x10);
