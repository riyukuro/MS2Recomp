/* Build glue: the exe's libpng was compiled against the zlib 1.2.5 header. Its png_inflate_claim (0x14271ce40) and
   png_deflate_claim (0x14271e240) pass "1.2.5" as the version to inflateInit2_ / deflateInit2_, while the zlib the
   exe links is 1.2.3 (gb:ZLib). Only the version string differs: libpng 1.6.17 branches on PNG_ZLIB_VERNUM (unset
   here, as before) and on ZLIB_VERNUM < 0x1260, which 1.2.3 and 1.2.5 both satisfy. The two units define
   MS2_PNG_ZLIB_1_2_5 (data/engine/units-lib-png.json), which also changes their compile key so cached objs rebuild. */
#include "../../../third_party/src/zlib-1.2.3/zlib.h"
#if defined(MS2_PNG_ZLIB_1_2_5)
#undef ZLIB_VERSION
#define ZLIB_VERSION "1.2.5"
#endif
