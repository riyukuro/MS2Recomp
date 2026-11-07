// Nexon Messenger's server-address and server-request list element constructors.
// MS2-UNIT: unit_1415eb4d0
// MS2-RANGE: 0x1415eb4d0-0x1415eb6c0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/ms2recover.h"

// @0x1415eb4d0
CNMSetServerInfoFunc::ServerAddress::ServerAddress(const ServerAddress& r)
    : m_host(r.m_host), m_port(r.m_port)
{
}

// @0x1415eb510
CNMSetServerInfoFunc::ServerAddress::ServerAddress()
    : m_host(), m_port(0)
{
}

// @0x1415eb540
CNMSetServerInfoFunc::RequestInfo::RequestInfo(const RequestInfo& r)
    : m_kind(r.m_kind), m_flags(r.m_flags), m_address(r.m_address), m_info(r.m_info)
{
}

// @0x1415eb5c0
CNMSetServerInfoFunc::RequestInfo::RequestInfo()
    : m_kind(0), m_flags(0), m_address(), m_info()
{
}

class CNMCOClientObject;
template <class T>
class CNMSingleton
{
public:
    virtual ~CNMSingleton();
};
template <class T>
CNMSingleton<T>::~CNMSingleton()
{
}

// @0x1415eb620
template CNMSingleton<CNMCOClientObject>::~CNMSingleton();

// @0x1415eb640
template CNMSingleton<CNMManager>::~CNMSingleton();

extern void FUN_1415f9bd0(void**);   // CNMStr<0x40>::Free (unit_1415f9410)
extern void FUN_1415f9c30(void*);    // CNMStr<0x800>::Free (unit_1415f9410)

// CNMStr<0x40>'s destructor body: frees the string (CNMStr<0x40>::Free, 0x1415f9bd0); noexcept, as a destructor
// @0x1415eb660
void FUN_1415eb660(void* p) noexcept
{
    FUN_1415f9bd0(static_cast<void**>(p));
}

// CNMStr<0x800>'s destructor body: frees the string (CNMStr<0x800>::Free, 0x1415f9c30); noexcept, as a destructor
// @0x1415eb690
void FUN_1415eb690(void* p) noexcept
{
    FUN_1415f9c30(p);
}
