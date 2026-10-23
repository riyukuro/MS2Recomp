// Nexon Messenger stream utility bodies; the stream and codec layouts are being recovered in nmstream.h.
// MS2-UNIT: unit_14156a020
// MS2-RANGE: 0x14156a020-0x14156f7e0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

extern void FUN_14156a5a0(void*);
extern int FUN_14156a0b0(void*);
extern int FUN_14156a320(void*);
extern int FUN_14156a450(long long*);
extern int FUN_14156a640(long long*, int);
extern void* FUN_1415fa310();
extern void* FUN_1415caaa0(void*, unsigned int);
extern void* FUN_1415cab60(void*, unsigned char);
extern void FUN_1415fa380(void*);

// MS2-FUNCTIONAL 0x14156a0d0: codec operations use recovered vtable slots; their opaque interface prevents an exact call-frame match.
// @0x14156a0d0
unsigned int FUN_14156a0d0(long long* p, const unsigned int* data, int owned)
{
    if (!data)
        return 0;
    FUN_14156a5a0(p);
    const unsigned int codecId = data[0];
    void* manager = FUN_1415fa310();
    void** codec = static_cast<void**>(FUN_1415caaa0(manager, codecId));
    if (!codec)
        goto fail;
    reinterpret_cast<unsigned int*>(p)[3] = data[1];
    const int size = *reinterpret_cast<const int*>(reinterpret_cast<const char*>(data) +
                         reinterpret_cast<unsigned int*>(p)[3] + 8);
    using SizeMethod = int(__fastcall*)(void*);
    if (size != reinterpret_cast<SizeMethod>(codec[5])(codec))
        goto fail;
    reinterpret_cast<int*>(p)[2] = owned;
    if (owned == 0) {
        const int length = reinterpret_cast<int*>(p)[3] + 0xc;
        void* buffer = HeapAlloc(GetProcessHeap(), 0, static_cast<SIZE_T>(length));
        *p = reinterpret_cast<long long>(buffer);
        if (!buffer)
            goto fail;
        const unsigned char* src = reinterpret_cast<const unsigned char*>(data);
        unsigned char* dst = static_cast<unsigned char*>(buffer);
        for (int i = 0; i < length; ++i)
            dst[i] = src[i];
        reinterpret_cast<int*>(p)[4] = length;
    }
    else {
        *p = reinterpret_cast<long long>(data);
    }
    reinterpret_cast<unsigned int*>(p)[5] = 8;
    using CodePageMethod = unsigned char(__fastcall*)(void*);
    reinterpret_cast<unsigned char*>(p)[0x1c] = reinterpret_cast<CodePageMethod>(codec[3])(codec);
    reinterpret_cast<int*>(p)[6] = 1;
    if (FUN_14156a450(p))
        return 1;
fail:
    FUN_14156a5a0(p);
    return 0;
}

// MS2-FUNCTIONAL 0x14156a290: codec metadata is recovered through opaque vtable slots, preserving serialized buffer contents.
// @0x14156a290
long long FUN_14156a290(long long* p)
{
    void** codec = static_cast<void**>(FUN_1415cab60(FUN_1415fa310(),
                                  reinterpret_cast<unsigned char*>(p)[0x1c]));
    if (codec) {
        using Method = unsigned int(__fastcall*)(void*);
        const unsigned int codecId = reinterpret_cast<Method>(codec[4])(codec);
        *reinterpret_cast<unsigned int*>(*p) = codecId;
        *reinterpret_cast<unsigned int*>(*p + 4) = reinterpret_cast<unsigned int*>(p)[3];
        const unsigned int size = reinterpret_cast<Method>(codec[5])(codec);
        *reinterpret_cast<unsigned int*>(*p + 8 + reinterpret_cast<unsigned int*>(p)[3]) = size;
    }
    return *p;
}

// MS2-FUNCTIONAL 0x14156a340: forwards through the codec-manager singleton helper with equivalent reset behavior.
// @0x14156a340
void FUN_14156a340()
{
    FUN_1415fa380(FUN_1415fa310());
}

// MS2-FUNCTIONAL 0x14156a370: invokes the codec's recovered decode slots with the reconstructed stream buffer layout.
// @0x14156a370
int FUN_14156a370(long long* p, unsigned char codecId)
{
    reinterpret_cast<unsigned char*>(p)[0x1c] = codecId;
    void** codec = static_cast<void**>(FUN_1415cab60(FUN_1415fa310(), codecId));
    if (!codec)
        return 0;
    using CountMethod = int(__fastcall*)(void*, unsigned int);
    using DecodeMethod = int(__fastcall*)(void*, void*, int, void*);
    const int needed = reinterpret_cast<CountMethod>(codec[6])(codec, reinterpret_cast<unsigned int*>(p)[3]) -
                       reinterpret_cast<int*>(p)[3];
    if (!FUN_14156a640(p, needed))
        return 0;
    if (reinterpret_cast<DecodeMethod>(codec[1])(codec, reinterpret_cast<void*>(*p + 8),
            reinterpret_cast<int*>(p)[4], reinterpret_cast<char*>(p) + 0xc) != 0)
        return 0;
    reinterpret_cast<unsigned int*>(p)[5] = reinterpret_cast<unsigned int*>(p)[3] + 8;
    return 1;
}

// MS2-FUNCTIONAL 0x14156a450: uses recovered codec vtable slots and heap growth logic; indirect call frame differs from the image.
// @0x14156a450
int FUN_14156a450(long long* p)
{
    if (reinterpret_cast<unsigned char*>(p)[0x1c] == 0)
        return 1;
    void** codec = static_cast<void**>(FUN_1415cab60(FUN_1415fa310(), 0));
    if (!codec)
        return 0;
    if (reinterpret_cast<int*>(p)[2] != 0) {
        const unsigned int length = static_cast<unsigned int>(FUN_14156a320(p));
        const unsigned int capacity = (length / 0x1000 + 1) * 0x1000;
        void* buffer = HeapAlloc(GetProcessHeap(), 0, capacity);
        if (!buffer)
            return 0;
        const unsigned char* src = reinterpret_cast<const unsigned char*>(*p);
        unsigned char* dst = static_cast<unsigned char*>(buffer);
        for (unsigned int i = 0; i < length; ++i)
            dst[i] = src[i];
        *p = reinterpret_cast<long long>(buffer);
        reinterpret_cast<unsigned int*>(p)[4] = capacity;
        reinterpret_cast<int*>(p)[2] = 0;
    }
    using Method = int(__fastcall*)(void*, void*, int, void*);
    return reinterpret_cast<Method>(codec[2])(codec, reinterpret_cast<void*>(*p + 8),
        reinterpret_cast<int*>(p)[4], reinterpret_cast<char*>(p) + 0xc) == 0;
}

// MS2-FUNCTIONAL 0x14156a640: preserves stream capacity and heap ownership behavior; compiler lowering differs around heap operations.
// @0x14156a640
int FUN_14156a640(long long* p, int amount)
{
    if (reinterpret_cast<int*>(p)[2] != 0 || reinterpret_cast<int*>(p)[6] == 0)
        FUN_14156a5a0(p);
    if (*p == 0) {
        const unsigned int capacity = (static_cast<unsigned int>(amount + 0xc) / 0x1000 + 1) * 0x1000;
        void* buffer = HeapAlloc(GetProcessHeap(), 0, capacity);
        *p = reinterpret_cast<long long>(buffer);
        reinterpret_cast<unsigned int*>(p)[4] = capacity;
        reinterpret_cast<unsigned int*>(p)[3] = 0;
        reinterpret_cast<unsigned int*>(p)[6] = 1;
        if (!buffer) {
            FUN_14156a5a0(p);
            return 0;
        }
        reinterpret_cast<unsigned int*>(p)[5] = 8;
        return 1;
    }
    if (reinterpret_cast<unsigned int*>(p)[4] - 4U <
        static_cast<unsigned int>(reinterpret_cast<int*>(p)[5] + amount)) {
        const unsigned int capacity = (static_cast<unsigned int>(reinterpret_cast<int*>(p)[5] + 4 + amount) /
                                       0x1000 + 1) * 0x1000;
        void* buffer = HeapAlloc(GetProcessHeap(), 0, capacity);
        if (!buffer) {
            FUN_14156a5a0(p);
            return 0;
        }
        const unsigned int used = reinterpret_cast<unsigned int*>(p)[5];
        const unsigned char* src = reinterpret_cast<const unsigned char*>(*p);
        unsigned char* dst = static_cast<unsigned char*>(buffer);
        for (unsigned int i = 0; i < used; ++i)
            dst[i] = src[i];
        HeapFree(GetProcessHeap(), 0, reinterpret_cast<void*>(*p));
        *p = reinterpret_cast<long long>(buffer);
        reinterpret_cast<unsigned int*>(p)[4] = capacity;
    }
    return 1;
}

// @0x14156a810
long long* FUN_14156a810(long long* p, long long value)
{
    *p = value;
    return p;
}

// MS2-FUNCTIONAL 0x14156a840: empty helper behavior is preserved; compiler emits a different return sequence.
// @0x14156a840
void FUN_14156a840() {}

// MS2-FUNCTIONAL 0x14156a850: preserves compact integer encoding and stream cursor updates; recovered pointer layout changes codegen.
// @0x14156a850
void FUN_14156a850(long long* p, unsigned int value)
{
    if (!*p || FUN_14156a0b0(reinterpret_cast<void*>(*p)) == 0)
        return;
    unsigned char* data = reinterpret_cast<unsigned char*>(*p);
    if (value < 0x40) {
        if (FUN_14156a640(reinterpret_cast<long long*>(*p), 1)) {
            data[reinterpret_cast<unsigned int*>(data)[5]] = static_cast<unsigned char>(value << 2);
            ++reinterpret_cast<unsigned int*>(data)[5]; ++reinterpret_cast<unsigned int*>(data)[3];
        }
    }
    else if (value < 0x4000) {
        if (FUN_14156a640(reinterpret_cast<long long*>(*p), 2)) {
            *reinterpret_cast<unsigned short*>(data + reinterpret_cast<unsigned int*>(data)[5]) =
                static_cast<unsigned short>((value << 2) | 1);
            reinterpret_cast<unsigned int*>(data)[5] += 2; reinterpret_cast<unsigned int*>(data)[3] += 2;
        }
    }
    else if (value < 0x40000000) {
        if (FUN_14156a640(reinterpret_cast<long long*>(*p), 4)) {
            *reinterpret_cast<unsigned int*>(data + reinterpret_cast<unsigned int*>(data)[5]) = (value << 2) | 2;
            reinterpret_cast<unsigned int*>(data)[5] += 4; reinterpret_cast<unsigned int*>(data)[3] += 4;
        }
    }
    else if (FUN_14156a640(reinterpret_cast<long long*>(*p), 5)) {
        data[reinterpret_cast<unsigned int*>(data)[5]++] = 3;
        ++reinterpret_cast<unsigned int*>(data)[3];
        *reinterpret_cast<unsigned int*>(data + reinterpret_cast<unsigned int*>(data)[5]) = value;
        reinterpret_cast<unsigned int*>(data)[5] += 4; reinterpret_cast<unsigned int*>(data)[3] += 4;
    }
}

// MS2-FUNCTIONAL 0x14156ab00: preserves byte-write semantics; recovered stream pointer types produce different codegen.
// @0x14156ab00
void FUN_14156ab00(long long* stream, unsigned char value)
{
    if (!*stream)
        return;
    long long* p = reinterpret_cast<long long*>(*stream);
    if (FUN_14156a640(p, 1)) {
        auto* data = reinterpret_cast<unsigned char*>(*p + reinterpret_cast<unsigned int*>(p)[5]);
        *data = value;
        ++reinterpret_cast<unsigned int*>(p)[5];
        ++reinterpret_cast<unsigned int*>(p)[3];
    }
}

// MS2-FUNCTIONAL 0x14156ab90: preserves 16-bit write semantics; recovered stream pointer types produce different codegen.
// @0x14156ab90
void FUN_14156ab90(long long* stream, unsigned short value)
{
    if (!*stream)
        return;
    long long* p = reinterpret_cast<long long*>(*stream);
    if (FUN_14156a640(p, 2)) {
        *reinterpret_cast<unsigned short*>(*p + reinterpret_cast<unsigned int*>(p)[5]) = value;
        reinterpret_cast<unsigned int*>(p)[5] += 2;
        reinterpret_cast<unsigned int*>(p)[3] += 2;
    }
}

// MS2-FUNCTIONAL 0x14156ac20: preserves 32-bit write semantics; recovered stream pointer types produce different codegen.
// @0x14156ac20
void FUN_14156ac20(long long* stream, unsigned int value)
{
    if (!*stream)
        return;
    long long* p = reinterpret_cast<long long*>(*stream);
    if (FUN_14156a640(p, 4)) {
        *reinterpret_cast<unsigned int*>(*p + reinterpret_cast<unsigned int*>(p)[5]) = value;
        reinterpret_cast<unsigned int*>(p)[5] += 4;
        reinterpret_cast<unsigned int*>(p)[3] += 4;
    }
}

// MS2-FUNCTIONAL 0x14156acb0: preserves 64-bit write semantics; recovered stream pointer types produce different codegen.
// @0x14156acb0
void FUN_14156acb0(long long* stream, unsigned long long value)
{
    if (!*stream)
        return;
    long long* p = reinterpret_cast<long long*>(*stream);
    if (FUN_14156a640(p, 8)) {
        *reinterpret_cast<unsigned long long*>(*p + reinterpret_cast<unsigned int*>(p)[5]) = value;
        reinterpret_cast<unsigned int*>(p)[5] += 8;
        reinterpret_cast<unsigned int*>(p)[3] += 8;
    }
}

// MS2-FUNCTIONAL 0x14156af60: preserves length-prefix and byte-copy behavior; recovered stream pointer types change codegen.
// @0x14156af60
void FUN_14156af60(long long* stream, const unsigned char* bytes, unsigned int count)
{
    if (!*stream || !bytes)
        return;
    FUN_14156a850(stream, count);
    long long* p = reinterpret_cast<long long*>(*stream);
    if (!FUN_14156a640(p, static_cast<int>(count)))
        return;
    unsigned char* dst = reinterpret_cast<unsigned char*>(*p + reinterpret_cast<unsigned int*>(p)[5]);
    for (unsigned int i = 0; i < count; ++i)
        dst[i] = bytes[i];
    reinterpret_cast<unsigned int*>(p)[5] += count;
    reinterpret_cast<unsigned int*>(p)[3] += count;
}

// @0x14156b020
void FUN_14156b020(long long* stream, unsigned long long value)
{
    FUN_14156acb0(stream, value);
}

// MS2-FUNCTIONAL: delegates to the stream reset implementation at 0x14156a5a0.
// @0x14156a080
void FUN_14156a080(void* p)
{
    FUN_14156a5a0(p);
}

// MS2-FUNCTIONAL: clears the stream fields and frees owned storage; remaining difference is code generation around HeapFree.
// @0x14156a5a0
void FUN_14156a5a0(long long* p)
{
    if (reinterpret_cast<int*>(p)[2] == 0 && p[0] != 0)
        HeapFree(GetProcessHeap(), 0, reinterpret_cast<void*>(p[0]));
    p[0] = 0;
    reinterpret_cast<unsigned int*>(p)[2] = 0;
    reinterpret_cast<unsigned int*>(p)[3] = 0;
    reinterpret_cast<unsigned int*>(p)[4] = 0;
    reinterpret_cast<unsigned int*>(p)[5] = 0;
    reinterpret_cast<unsigned int*>(p)[6] = 0;
    reinterpret_cast<unsigned char*>(p)[0x1c] = 0;
}

// @0x14156a0b0
int FUN_14156a0b0(void* p)
{
    return *reinterpret_cast<int*>(static_cast<char*>(p) + 0x18);
}

// @0x14156a260
void FUN_14156a260(void* p, int clearSize)
{
    *reinterpret_cast<int*>(static_cast<char*>(p) + 0x14) = 8;
    if (clearSize != 0)
        *reinterpret_cast<int*>(static_cast<char*>(p) + 0x0c) = 0;
}

// @0x14156a320
int FUN_14156a320(void* p)
{
    return *reinterpret_cast<int*>(static_cast<char*>(p) + 0x0c) + 0x0c;
}
