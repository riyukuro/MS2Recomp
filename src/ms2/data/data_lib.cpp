// Data unit (sfr22): the library globals the recovered lib_cryptopp_* / lib_small_tail code names by exe address
// (DAT_<va>) and that no TU defines. The string literals are defined here with the exe's bytes; the Crypto++ class
// objects behind the other names (vftables, RTTI type descriptors, AAD_CHANNEL, g_powerUpSelfTestStatus) are the
// gb:CryptoPP objects' own definitions, so those names are mapped to them with /alternatename instead of copied.
// One definition per exe address (tools/datacheck.py checks address, size and initializer).
// The hook DLL binds every name to the exe's own global (symbols table), so nothing here is compiled into it
// (docs/RECOVERY.md sec. 9).
// MS2-UNIT: data_lib
// MS2-RANGE: 0x14311c1e0-0x14311c1ea .rdata
// MS2-RANGE: 0x14311c638-0x14311c640 .rdata
// MS2-RANGE: 0x14312b860-0x14312b86c .rdata
// MS2-RANGE: 0x14312d8d8-0x14312d8ed .rdata
// MS2-RANGE: 0x143130c28-0x143130c49 .rdata
// MS2-RANGE: 0x143196858-0x14319694f .rdata

#ifndef MS2_HOOK_DLL
#pragma warning(disable : 4483)   // __identifier("<mangled name>")

// Crypto++ 5.6.2 literals (lib_cryptopp_code)
extern const char DAT_14311c1e0[] = "BitBucket";                            // BitBucket::AlgorithmName
extern const char DAT_14311c638[] = "NullRNG";                              // NullRNG().AlgorithmName
extern const char DAT_14312b860[] = "ThisObject:";                          // GetValueHelperClass prefix
extern const char DAT_14312d8d8[] = "OpenPGP decode error";                 // Integer::OpenPGPDecodeErr
extern const char DAT_143130c28[] = "PolynomialMod2: division by zero";     // PolynomialMod2::DivideByZero

// libpng png_zstream_error messages (lib_small_tail)
extern const char DAT_143196858[] = "unexpected zlib return code";
extern const char DAT_143196878[] = "unexpected end of LZ stream";
extern const char DAT_143196898[] = "missing LZ dictionary";
extern const char DAT_1431968b0[] = "zlib IO error";
extern const char DAT_1431968c0[] = "bad parameters to zlib";
extern const char DAT_1431968d8[] = "damaged LZ stream";
extern const char DAT_1431968f0[] = "insufficient memory";
extern const char DAT_143196908[] = "truncated";
extern const char DAT_143196918[] = "unsupported zlib version";
extern const char DAT_143196938[] = "unexpected zlib return";

// vftables (the RTTI complete-object locator before each names the class and subobject)

// RTTI type descriptors: typeid(T)

// 0x143b0dc48 CryptoPP::AAD_CHANNEL (its ??__E 0x14013b180 constructs "AAD" there)
// ?DAT_143b0dc48: lib_cryptopp_filters_cx13 names CryptoPP::AAD_CHANNEL directly
// 0x143b10184 CryptoPP::g_powerUpSelfTestStatus (fips140: GetPowerUpSelfTestStatus 0x142353790 reads it,
// SimulatePowerUpSelfTestFailure 0x1423537d0 stores POWER_UP_SELF_TEST_FAILED)
// ?DAT_143b10184: lib_cryptopp_code names CryptoPP::g_powerUpSelfTestStatus directly

#endif // MS2_HOOK_DLL
