// Forced in by tools/msvc9v/cl (the `// MS2-TOOLSET: vc9v` units). cl 15 is C++03, and the shared SF headers use a few
// C++11 keywords, so they are defined away here. Codegen is unchanged: they carry no code (nullptr is 0).
#if defined(_MSC_VER) && _MSC_VER < 1600 && !defined(__clang__)
#define static_assert(a, b)
#define override
#define final
#define nullptr 0
#define constexpr const
#endif
