// Executable-derived adapters for two Crypto++ private-key property queries.
// MS2-UNIT: lib_cryptopp_fipstest_cx13
// MS2-RANGE: 0x1423781c0-0x1423781ff .text$mn
// MS2-RANGE: 0x142378240-0x14237827f .text$mn
// MS2-FLAGS: gamebryo
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

#include <cstdint>

#include <new>
#include <typeinfo>

namespace CryptoPP   // C3: views of the GetValueHelperClass members these adapters call
{
class Integer;
class NameValuePairs;
class DL_GroupParameters_DSA;
template <class T> class DL_PrivateKey;
template <class T> class DL_PublicKey;
template <class GP> class DL_PrivateKeyImpl;
template <class GP> class DL_PublicKeyImpl;
template <class T, class BASE> class GetValueHelperClass
{
public:
    GetValueHelperClass(const T* pObject, const char* name, const std::type_info& valueType, void* pValue, const NameValuePairs* searchFirst);
    GetValueHelperClass& Assignable();
};
}
typedef CryptoPP::GetValueHelperClass<CryptoPP::DL_PrivateKeyImpl<CryptoPP::DL_GroupParameters_DSA>, CryptoPP::DL_PrivateKey<CryptoPP::Integer>> Cx13PrivateKeyHelper;
typedef CryptoPP::GetValueHelperClass<CryptoPP::DL_PublicKeyImpl<CryptoPP::DL_GroupParameters_DSA>, CryptoPP::DL_PublicKey<CryptoPP::Integer>> Cx13PublicKeyHelper;

namespace {
// GetValueHelperClass-shaped temporary: object, name, type, value pointers, then the found flag at 0x20.
struct Cx13GetValueTemp
{
    Cx13GetValueTemp() {}
    std::uint64_t w0, w1, w2, w3, w4, w5;
};
}

// @0x1423781c0
bool GetVoidValueCx13Ec2n(void* self, void* name, void* valueType, void* output)
{
    Cx13GetValueTemp temporary;
    new (&temporary) Cx13PrivateKeyHelper(reinterpret_cast<const CryptoPP::DL_PrivateKeyImpl<CryptoPP::DL_GroupParameters_DSA>*>(static_cast<std::uint8_t*>(self) - 0x178),
                  static_cast<const char*>(name), *static_cast<const std::type_info*>(valueType), output, nullptr);
    auto* result = reinterpret_cast<std::uint8_t*>(&reinterpret_cast<Cx13PrivateKeyHelper*>(&temporary)->Assignable());
    return *reinterpret_cast<bool*>(result + 0x20);
}

// @0x142378240
bool GetVoidValueCx13Ecp(void* self, void* name, void* valueType, void* output)
{
    Cx13GetValueTemp temporary;
    new (&temporary) Cx13PublicKeyHelper(reinterpret_cast<const CryptoPP::DL_PublicKeyImpl<CryptoPP::DL_GroupParameters_DSA>*>(static_cast<std::uint8_t*>(self) - 0x170),
                  static_cast<const char*>(name), *static_cast<const std::type_info*>(valueType), output, nullptr);
    auto* result = reinterpret_cast<std::uint8_t*>(&reinterpret_cast<Cx13PublicKeyHelper*>(&temporary)->Assignable());
    return *reinterpret_cast<bool*>(result + 0x20);
}
