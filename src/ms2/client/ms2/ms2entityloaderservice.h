// ms2entityloaderservice.h - MS2EntityLoaderService: egf::EntityLoaderService subclass (0xd0) that, while a load flag (+0xc8)
// is set, polls a manager each tick and clears the flag once loading has finished.
// Owning unit: ?\ms2entityloaderservice.cpp (0x1414b3ee0-0x1414b4a90, dir client\ms2).
#pragma once
#include "ms2/ms2layout.h"
#include <egf/EntityLoaderService.h>

class MS2EntityLoaderService : public egf::EntityLoaderService
{
public:
    MS2EntityLoaderService();                       // 0x1414b3ee0
    virtual ~MS2EntityLoaderService();              // 0x1414b3f20, ??_G 0x1414b4520
    virtual efd::AsyncResult OnTick();              // 0x1414b41a0
    // Instantiated by EntityWorldManager.
    // @0x1411d8980
    void SetLoading(bool loading) { m_bLoading = loading; }

public:
    bool m_bLoading;   // +0xc8
};
MS2_CHECK_SIZE(MS2EntityLoaderService, 0xd0);
