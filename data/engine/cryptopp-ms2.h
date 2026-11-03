// MS2: forced include of the lib-cryptopp units on flag set 1 (units-lib-cryptopp.json; dll and asn stay on set 0,
// the exe copies they own inline the ctor). The exe's Crypto++ calls
// std::string(const char*) out of line (0x1401d2620) where cl 19.14 inlines it; declaring the specialization
// without a body makes cl emit the call. The definition is the implicit instantiation from the other TUs.
#pragma once
#include <xstring>  // not <string>: its inline non-templates instantiate the ctor first (C2908)
namespace std { template<> basic_string<char, char_traits<char>, allocator<char>>::basic_string(const char* const _Ptr); }
