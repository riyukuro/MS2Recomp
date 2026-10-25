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
#pragma comment(linker, "/alternatename:?DAT_14311e038@@3PADA=??_7AuthenticatedEncryptionFilter@CryptoPP@@6BAlgorithm@1@@")
#pragma comment(linker, "/alternatename:?DAT_14311e200@@3PADA=??_7AuthenticatedEncryptionFilter@CryptoPP@@6BWaitable@1@@")
#pragma comment(linker, "/alternatename:?DAT_14311e220@@3PADA=??_7AuthenticatedDecryptionFilter@CryptoPP@@6BAlgorithm@1@@")
#pragma comment(linker, "/alternatename:?DAT_14311e3e8@@3PADA=??_7AuthenticatedDecryptionFilter@CryptoPP@@6BWaitable@1@@")
#pragma comment(linker, "/alternatename:?DAT_14311ee90@@3PADA=??_7?$AlgorithmParametersTemplate@W4BlockPaddingScheme@BlockPaddingSchemeDef@CryptoPP@@@CryptoPP@@6B@")
#pragma comment(linker, "/alternatename:?DAT_14312d848@@3PADA=??_7OpenPGPDecodeErr@Integer@CryptoPP@@6B@")
#pragma comment(linker, "/alternatename:?DAT_14312dbf8@@3PADA=??_7?$AlgorithmParametersTemplate@W4RandomNumberType@Integer@CryptoPP@@@CryptoPP@@6B@")
#pragma comment(linker, "/alternatename:?DAT_143130c18@@3PADA=??_7DivideByZero@PolynomialMod2@CryptoPP@@6B@")

// RTTI type descriptors: typeid(T)
#pragma comment(linker, "/alternatename:?DAT_143a57d68@@3Vtype_info@@B=??_R0H@8")
#pragma comment(linker, "/alternatename:?DAT_143aa1220@@3Vtype_info@@B=??_R0?AW4BlockPaddingScheme@BlockPaddingSchemeDef@CryptoPP@@@8")
#pragma comment(linker, "/alternatename:?DAT_143aa1768@@3Vtype_info@@B=??_R0?AVDL_GroupParameters_GFP@CryptoPP@@@8")
#pragma comment(linker, "/alternatename:?DAT_143aa1d00@@3Vtype_info@@B=??_R0?AVDL_GroupParameters_IntegerBased@CryptoPP@@@8")
#pragma comment(linker, "/alternatename:?DAT_143aa1de0@@3Vtype_info@@B=??_R0?AV?$DL_PublicKey@VInteger@CryptoPP@@@CryptoPP@@@8")
#pragma comment(linker, "/alternatename:?DAT_143aa1e90@@3Vtype_info@@B=??_R0?AV?$DL_PrivateKey@VInteger@CryptoPP@@@CryptoPP@@@8")
#pragma comment(linker, "/alternatename:?DAT_143aa3860@@3Vtype_info@@B=??_R0?AVDL_GroupParameters_GFP_DefaultSafePrime@CryptoPP@@@8")
#pragma comment(linker, "/alternatename:?DAT_143aa7a80@@3Vtype_info@@B=??_R0?AW4RandomNumberType@Integer@CryptoPP@@@8")
#pragma comment(linker, "/alternatename:?DAT_143aa7e20@@3Vtype_info@@B=??_R0?AV?$DL_PublicKeyImpl@VDL_GroupParameters_GFP_DefaultSafePrime@CryptoPP@@@CryptoPP@@@8")
#pragma comment(linker, "/alternatename:?DAT_143aa7e90@@3Vtype_info@@B=??_R0?AV?$DL_PrivateKeyImpl@VDL_GroupParameters_GFP_DefaultSafePrime@CryptoPP@@@CryptoPP@@@8")

// 0x143b0dc48 CryptoPP::AAD_CHANNEL (its ??__E 0x14013b180 constructs "AAD" there)
#pragma comment(linker, "/alternatename:?DAT_143b0dc48@@3PADA=?AAD_CHANNEL@CryptoPP@@3V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@B")
// 0x143b10184 CryptoPP::g_powerUpSelfTestStatus (fips140: GetPowerUpSelfTestStatus 0x142353790 reads it,
// SimulatePowerUpSelfTestFailure 0x1423537d0 stores POWER_UP_SELF_TEST_FAILED)
#pragma comment(linker, "/alternatename:?DAT_143b10184@@3HA=?g_powerUpSelfTestStatus@CryptoPP@@3W4PowerUpSelfTestStatus@1@A")

// CEF wrapper (lib_cef_tail ctors / scalar deleting dtors): the vbtable and the vftables of each construction stage
// (X, CefCToCppRefCounted<XCToCpp>, XCToCpp; main and CefBaseRefCounted virtual-base subobject). The wrapper has no
// RTTI; each name was paired by slot contents (method and adjustor-thunk bytes). The exe folds identical vftables
// (ICF), so a dtor thunk shared by several classes names one of them.
#pragma comment(linker, "/alternatename:?DAT_1431d9618@@3PADA=??_8CefBinaryValueCToCpp@@7B@")
#pragma comment(linker, "/alternatename:?DAT_1431d9568@@3PADA=??_7CefBinaryValue@@6B0@@")
#pragma comment(linker, "/alternatename:?DAT_1431d95a0@@3PADA=??_7CefBinaryValue@@6BCefBaseRefCounted@@@")
#pragma comment(linker, "/alternatename:?DAT_1431d6fc8@@3PADA=??_7?$CefCToCppRefCounted@VCefBinaryValueCToCpp@@VCefBinaryValue@@U_cef_binary_value_t@@@@6BCefBinaryValue@@@")
#pragma comment(linker, "/alternatename:?DAT_1431d7000@@3PADA=??_7?$CefCToCppRefCounted@VCefBinaryValueCToCpp@@VCefBinaryValue@@U_cef_binary_value_t@@@@6BCefBaseRefCounted@@@")
#pragma comment(linker, "/alternatename:?DAT_1431d95c0@@3PADA=??_7CefBinaryValueCToCpp@@6BCefBinaryValue@@@")
#pragma comment(linker, "/alternatename:?DAT_1431d95f8@@3PADA=??_7CefBinaryValueCToCpp@@6BCefBaseRefCounted@@@")
#pragma comment(linker, "/alternatename:?DAT_1431da2a8@@3PADA=??_8CefTaskRunnerCToCpp@@7B@")
#pragma comment(linker, "/alternatename:?DAT_1431da218@@3PADA=??_7CefTaskRunner@@6B0@@")
#pragma comment(linker, "/alternatename:?DAT_1431da240@@3PADA=??_7CefTaskRunner@@6BCefBaseRefCounted@@@")
#pragma comment(linker, "/alternatename:?DAT_1431d75e8@@3PADA=??_7?$CefCToCppRefCounted@VCefTaskRunnerCToCpp@@VCefTaskRunner@@U_cef_task_runner_t@@@@6BCefTaskRunner@@@")
#pragma comment(linker, "/alternatename:?DAT_1431d7610@@3PADA=??_7?$CefCToCppRefCounted@VCefTaskRunnerCToCpp@@VCefTaskRunner@@U_cef_task_runner_t@@@@6BCefBaseRefCounted@@@")
#pragma comment(linker, "/alternatename:?DAT_1431da260@@3PADA=??_7CefTaskRunnerCToCpp@@6BCefTaskRunner@@@")
#pragma comment(linker, "/alternatename:?DAT_1431da288@@3PADA=??_7CefTaskRunnerCToCpp@@6BCefBaseRefCounted@@@")
#pragma comment(linker, "/alternatename:?DAT_1431df490@@3PADA=??_8CefDOMNodeCToCpp@@7B@")
#pragma comment(linker, "/alternatename:?DAT_1431df2b0@@3PADA=??_7CefDOMNode@@6B0@@")
#pragma comment(linker, "/alternatename:?DAT_1431df380@@3PADA=??_7CefDOMNode@@6BCefBaseRefCounted@@@")
#pragma comment(linker, "/alternatename:?DAT_1431dc138@@3PADA=??_7?$CefCToCppRefCounted@VCefDOMNodeCToCpp@@VCefDOMNode@@U_cef_domnode_t@@@@6BCefDOMNode@@@")
#pragma comment(linker, "/alternatename:?DAT_1431dc208@@3PADA=??_7?$CefCToCppRefCounted@VCefDOMNodeCToCpp@@VCefDOMNode@@U_cef_domnode_t@@@@6BCefBaseRefCounted@@@")
#pragma comment(linker, "/alternatename:?DAT_1431df3a0@@3PADA=??_7CefDOMNodeCToCpp@@6BCefDOMNode@@@")
#pragma comment(linker, "/alternatename:?DAT_1431df470@@3PADA=??_7CefDOMNodeCToCpp@@6BCefBaseRefCounted@@@")
#pragma comment(linker, "/alternatename:?DAT_1431e03e8@@3PADA=??_8CefMenuModelCToCpp@@7B@")
#pragma comment(linker, "/alternatename:?DAT_1431e0028@@3PADA=??_7CefMenuModel@@6B0@@")
#pragma comment(linker, "/alternatename:?DAT_1431e01e8@@3PADA=??_7CefMenuModel@@6BCefBaseRefCounted@@@")
#pragma comment(linker, "/alternatename:?DAT_1431dcf48@@3PADA=??_7?$CefCToCppRefCounted@VCefMenuModelCToCpp@@VCefMenuModel@@U_cef_menu_model_t@@@@6BCefMenuModel@@@")
#pragma comment(linker, "/alternatename:?DAT_1431dd108@@3PADA=??_7?$CefCToCppRefCounted@VCefMenuModelCToCpp@@VCefMenuModel@@U_cef_menu_model_t@@@@6BCefBaseRefCounted@@@")
#pragma comment(linker, "/alternatename:?DAT_1431e0208@@3PADA=??_7CefMenuModelCToCpp@@6BCefMenuModel@@@")
#pragma comment(linker, "/alternatename:?DAT_1431e03c8@@3PADA=??_7CefMenuModelCToCpp@@6BCefBaseRefCounted@@@")
#pragma comment(linker, "/alternatename:?DAT_1431e09b0@@3PADA=??_8CefAuthCallbackCToCpp@@7B@")
#pragma comment(linker, "/alternatename:?DAT_1431e0950@@3PADA=??_7CefAuthCallback@@6B0@@")
#pragma comment(linker, "/alternatename:?DAT_1431e0960@@3PADA=??_7CefAuthCallback@@6BCefBaseRefCounted@@@")
#pragma comment(linker, "/alternatename:?DAT_1431de378@@3PADA=??_7?$CefCToCppRefCounted@VCefAuthCallbackCToCpp@@VCefAuthCallback@@U_cef_auth_callback_t@@@@6BCefAuthCallback@@@")
#pragma comment(linker, "/alternatename:?DAT_1431de388@@3PADA=??_7?$CefCToCppRefCounted@VCefAuthCallbackCToCpp@@VCefAuthCallback@@U_cef_auth_callback_t@@@@6BCefBaseRefCounted@@@")
#pragma comment(linker, "/alternatename:?DAT_1431e0980@@3PADA=??_7CefAuthCallbackCToCpp@@6BCefAuthCallback@@@")
#pragma comment(linker, "/alternatename:?DAT_1431e0990@@3PADA=??_7CefAuthCallbackCToCpp@@6BCefBaseRefCounted@@@")
#pragma comment(linker, "/alternatename:?DAT_1431e1418@@3PADA=??_8CefPrintSettingsCToCpp@@7B@")
#pragma comment(linker, "/alternatename:?DAT_1431e1268@@3PADA=??_7CefPrintSettings@@6B0@@")
#pragma comment(linker, "/alternatename:?DAT_1431e1320@@3PADA=??_7CefPrintSettings@@6BCefBaseRefCounted@@@")
#pragma comment(linker, "/alternatename:?DAT_1431df048@@3PADA=??_7?$CefCToCppRefCounted@VCefPrintSettingsCToCpp@@VCefPrintSettings@@U_cef_print_settings_t@@@@6BCefPrintSettings@@@")
#pragma comment(linker, "/alternatename:?DAT_1431df100@@3PADA=??_7?$CefCToCppRefCounted@VCefPrintSettingsCToCpp@@VCefPrintSettings@@U_cef_print_settings_t@@@@6BCefBaseRefCounted@@@")
#pragma comment(linker, "/alternatename:?DAT_1431e1340@@3PADA=??_7CefPrintSettingsCToCpp@@6BCefPrintSettings@@@")
#pragma comment(linker, "/alternatename:?DAT_1431e13f8@@3PADA=??_7CefPrintSettingsCToCpp@@6BCefBaseRefCounted@@@")
#pragma comment(linker, "/alternatename:?DAT_1431de6c8@@3PADA=??_7?$CefCToCppRefCounted@VCefProcessMessageCToCpp@@VCefProcessMessage@@U_cef_process_message_t@@@@6BCefProcessMessage@@@")
#pragma comment(linker, "/alternatename:?DAT_1431de6f0@@3PADA=??_7?$CefCToCppRefCounted@VCefProcessMessageCToCpp@@VCefProcessMessage@@U_cef_process_message_t@@@@6BCefBaseRefCounted@@@")
#pragma comment(linker, "/alternatename:?DAT_1431de3d8@@3PADA=??_7?$CefCToCppRefCounted@VCefBeforeDownloadCallbackCToCpp@@VCefBeforeDownloadCallback@@U_cef_before_download_callback_t@@@@6BCefBeforeDownloadCallback@@@")
#pragma comment(linker, "/alternatename:?DAT_1431de3e0@@3PADA=??_7?$CefCToCppRefCounted@VCefBeforeDownloadCallbackCToCpp@@VCefBeforeDownloadCallback@@U_cef_before_download_callback_t@@@@6BCefBaseRefCounted@@@")
#pragma comment(linker, "/alternatename:?DAT_1431de400@@3PADA=??_7?$CefCToCppRefCounted@VCefRunContextMenuCallbackCToCpp@@VCefRunContextMenuCallback@@U_cef_run_context_menu_callback_t@@@@6BCefRunContextMenuCallback@@@")
#pragma comment(linker, "/alternatename:?DAT_1431de410@@3PADA=??_7?$CefCToCppRefCounted@VCefRunContextMenuCallbackCToCpp@@VCefRunContextMenuCallback@@U_cef_run_context_menu_callback_t@@@@6BCefBaseRefCounted@@@")
#pragma comment(linker, "/alternatename:?DAT_1431df020@@3PADA=??_7?$CefCToCppRefCounted@VCefJSDialogCallbackCToCpp@@VCefJSDialogCallback@@U_cef_jsdialog_callback_t@@@@6BCefJSDialogCallback@@@")
#pragma comment(linker, "/alternatename:?DAT_1431df028@@3PADA=??_7?$CefCToCppRefCounted@VCefJSDialogCallbackCToCpp@@VCefJSDialogCallback@@U_cef_jsdialog_callback_t@@@@6BCefBaseRefCounted@@@")

#endif // MS2_HOOK_DLL
