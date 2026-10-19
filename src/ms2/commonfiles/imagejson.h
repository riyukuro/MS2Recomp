// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The JSON DOM/reader/writer (a RapidJSON 0.x derivative with a
// 0x14-byte packed value) linked into commonfiles\imagehttpclient.cpp. Class names are INVENTED (no RTTI/strings name them);
// the layouts are proven from the exe (MS2_CHECK_SIZE). Original header name assumed.
#pragma once
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <new>
#include <setjmp.h>
#include "ms2/ms2layout.h"

class ImageJsonWriter;
class ImageJsonStringStream;
class ImageJsonDocument;


// inferred: stateless allocator constructed by 0x1405174f0/0x1405176f0;
// malloc/free wrappers at 0x140518e30 / 0x140518870.
class ImageJsonCrtAllocator {
public:
    static const bool kNeedFree = true;
    void* Malloc(size_t size) { return malloc(size); }
    void* Realloc(void* p, size_t, size_t size) { return realloc(p, size); }
    static void Free(void* p) { free(p); }
};


// inferred: pool allocator, ctor 0x1405174f0 (0x28-byte allocation).
class ImageJsonAllocator {
public:
    static const bool kNeedFree = false;
    explicit ImageJsonAllocator(size_t chunkSize = 0x10000, ImageJsonCrtAllocator* allocator = 0);
    ~ImageJsonAllocator();
    void Clear();
    void* Malloc(size_t);
    void* Realloc(void*, size_t originalSize, size_t newSize);
    static void Free(void*) {} // inferred: 0x140518860, pool allocations are freed together.
private:
    struct Chunk {
        size_t capacity;
        size_t size;
        Chunk* next;
    };
    void AddChunk(size_t);
    Chunk* m_head;
    size_t m_chunkSize;
    void* m_userBuffer;
    ImageJsonCrtAllocator* m_allocator;
    ImageJsonCrtAllocator* m_ownAllocator;
};
MS2_CHECK_SIZE(ImageJsonAllocator, 0x28);


// inferred: six pointer-sized fields, ctors 0x1405175c0 (pool) and
// 0x1405176f0 (CRT); stack growth at 0x140515980.
template<class Allocator> class ImageJsonStack {
public:
    ImageJsonStack(Allocator* allocator, size_t capacity)
        : m_allocator(allocator), m_ownAllocator(0), m_stack(0), m_top(0), m_end(0), m_capacity(capacity) {
        if (!m_allocator) {
            m_ownAllocator = m_allocator = new Allocator();
        }
        m_top = m_stack = static_cast<char*>(m_allocator->Malloc(m_capacity));
        m_end = m_stack + m_capacity;
    }
    ~ImageJsonStack() {
        Allocator::Free(m_stack);
        delete m_ownAllocator;
    }
    Allocator& GetAllocator() { return *m_allocator; }
    size_t GetSize() const { return m_top - m_stack; }
    bool Empty() const { return m_top == m_stack; }
    void Clear() { m_top = m_stack; }
    template<class T> T* Bottom() { return reinterpret_cast<T*>(m_stack); }
    template<class T> T* Push(size_t count = 1) {
        if (m_top + sizeof(T) * count >= m_end) {
            size_t capacity = m_capacity * 2;
            size_t size = GetSize();
            size_t required = GetSize() + sizeof(T) * count;
            if (capacity < required) capacity = required;
            m_stack = static_cast<char*>(m_allocator->Realloc(m_stack, m_capacity, capacity));
            m_capacity = capacity;
            m_top = m_stack + size;
            m_end = m_stack + m_capacity;
        }
        T* result = reinterpret_cast<T*>(m_top);
        m_top += sizeof(T) * count;
        return result;
    }
    template<class T> T* Pop(size_t count) { m_top -= count * sizeof(T); return reinterpret_cast<T*>(m_top); }
    template<class T> T* Top() { return reinterpret_cast<T*>(m_top - sizeof(T)); }
private:
    Allocator* m_allocator;
    Allocator* m_ownAllocator;
    char* m_stack;
    char* m_top;
    char* m_end;
    size_t m_capacity;
};


// inferred JSON value layout. The target allocates 0x14 bytes at 0x1405192e0,
// and member pairs have stride 0x28 at 0x140518210 / 0x140518780. Four-byte
// packing is required for this pointer-bearing union to have that exact extent.
#pragma pack(push, 4)
class ImageJsonValue {
public:
    enum Type { Null = 0, False = 1, True = 2, Object = 3, Array = 4, String = 5, Number = 6 };
    template<class Value> struct MemberStorage { Value name; Value value; };
    typedef MemberStorage<ImageJsonValue> Member;
    ImageJsonValue(); // 0x1405172c0
    explicit ImageJsonValue(Type); // 0x140517280
    explicit ImageJsonValue(int); // 0x1405170f0
    explicit ImageJsonValue(unsigned); // 0x140517140
    explicit ImageJsonValue(__int64); // 0x1405172e0
    explicit ImageJsonValue(unsigned __int64); // 0x1405173a0
    explicit ImageJsonValue(double); // 0x140517190
    explicit ImageJsonValue(bool); // 0x140517450
    explicit ImageJsonValue(const char*); // 0x1405171c0
    ImageJsonValue(const char*, unsigned); // 0x140517200
    ImageJsonValue(const char*, unsigned, ImageJsonAllocator&); // 0x140517240
    ~ImageJsonValue(); // 0x140517ba0
    ImageJsonValue& SetObject(); // 0x1405192e0
    ImageJsonValue& SetNull(); // 0x1405192a0
    ImageJsonValue& AddMember(ImageJsonValue&, ImageJsonValue&, ImageJsonAllocator&); // 0x140518210
    ImageJsonValue& AddMember(const char*, int, ImageJsonAllocator&); // 0x140512d10
    ImageJsonValue& AddMember(const char*, const char*, ImageJsonAllocator&); // 0x140512dd0
    ImageJsonValue& AddMember(const char*, unsigned __int64, ImageJsonAllocator&); // 0x140512e90
    Member* FindMember(const char*); // 0x140518780
    const Member* FindMember(const char*) const; // 0x140518820
    bool HasMember(const char*) const; // 0x140518a80
    ImageJsonValue& operator[](const char*); // 0x140517f90
    const ImageJsonValue& Accept(ImageJsonWriter&) const; // inferred: 0x140512ab0
    Type GetType() const { return static_cast<Type>(m_flags & 0xff); } // 0x140518a30
    const char* GetString() const { return m_data.string.str; } // 0x140518a20
    bool IsString() const { return (m_flags & 0x100000) != 0; } // 0x140518cb0
    bool IsUint() const { return (m_flags & 0x800) != 0; } // 0x140518d30
    bool IsInt() const { return (m_flags & 0x400) != 0; } // 0x140518c70
    bool IsInt64() const { return (m_flags & 0x1000) != 0; } // 0x140518c30
    bool IsUint64() const { return (m_flags & 0x2000) != 0; } // 0x140518cf0
    static size_t StringLength(const char*); // 0x140515d70 returns pointer difference in RAX
private:
    friend class ImageJsonDocument;
    void SetStringRaw(const char*, unsigned); // 0x1405193b0
    void SetStringRaw(const char*, unsigned, ImageJsonAllocator&); // 0x1405193f0
    void SetArrayRaw(ImageJsonValue*, unsigned, ImageJsonAllocator&); // 0x140519220
    void SetObjectRaw(Member*, unsigned, ImageJsonAllocator&); // 0x140519330
    void RawAssign(ImageJsonValue&); // 0x1405190b0
    union Data {
        struct StringData { const char* str; unsigned length; unsigned hash; } string;
        struct ObjectData { Member* members; unsigned size; unsigned capacity; } object;
        struct ArrayData { ImageJsonValue* elements; unsigned size; unsigned capacity; } array;
        // inferred: 32-bit numeric views occupy the low half of the shared
        // 64-bit slot. Preserve their explicit padding in this union model.
        union NumberData {
            struct SignedData { int value; char padding[4]; } i;
            struct UnsignedData { unsigned value; char padding[4]; } u;
            __int64 i64;
            unsigned __int64 u64;
            double d;
        } number;
    } m_data;
    unsigned m_flags;
};
#pragma pack(pop)
MS2_CHECK_SIZE(ImageJsonValue, 0x14);
MS2_CHECK_SIZE(ImageJsonValue::Member, 0x28);


// inferred: two-pointer read-only string stream, ctor 0x1405170c0,
// Peek/Take/Tell at 0x140518ec0 / 0x1405196d0 / 0x140519710.
class ImageJsonStringStream {
public:
    explicit ImageJsonStringStream(const char* str) : m_src(str), m_head(str) {}
    char Peek() const { return *m_src; }
    char Take() { return *m_src++; }
    size_t Tell() const { return m_src - m_head; }
    void Put(char) {} // inferred: read-only stream, 0x140519040
    char* PutBegin() { return 0; } // inferred: 0x140519090
    size_t PutEnd(char*) { return 0; } // inferred: 0x1405190a0
private:
    const char* m_src;
    const char* m_head;
};
MS2_CHECK_SIZE(ImageJsonStringStream, 0x10);


// inferred: string buffer ctor 0x140517080 and dtor 0x140517b80 wrap
// the six-field CRT stack; Put/GetString/GetSize at 0x140519010/0x1405189d0/0x140518970.
class ImageJsonBuffer {
public:
    ImageJsonBuffer(ImageJsonCrtAllocator* allocator = 0, size_t capacity = 0x100);
    ~ImageJsonBuffer();
    void Put(char c) { *m_stack.Push<char>() = c; }
    void Flush() {} // inferred: 0x140518850
    const char* GetString() {
        *m_stack.Push<char>() = '\0';
        m_stack.Pop<char>(1);
        return m_stack.Bottom<char>();
    }
    size_t GetSize() const { return m_stack.GetSize(); }
private:
    ImageJsonStack<ImageJsonCrtAllocator> m_stack;
};
MS2_CHECK_SIZE(ImageJsonBuffer, 0x30);


// inferred: ctor 0x140516fb0, value base +0, pool stack +0x18,
// parse-error pointer +0x48 and error offset +0x50.
class ImageJsonDocument : public ImageJsonValue {
public:
    ImageJsonDocument(ImageJsonAllocator* = 0, size_t stackCapacity = 0x400);
    ~ImageJsonDocument();
    ImageJsonDocument& Parse(const char*); // inferred: 0x1405139e0, parser not yet reconstructed.
    template<unsigned flags> ImageJsonDocument& Parse(const char*); // zero-flag body 0x140513bd0
    template<unsigned flags> ImageJsonDocument& ParseStream(ImageJsonStringStream&); // 0x140514b40
    bool HasParseError() const { return m_parseError ? 1 : 0; } // 0x140518ac0
    ImageJsonAllocator& GetAllocator() { return m_stack.GetAllocator(); } // 0x1405188d0
    void Null();
    void Bool(bool);
    void Int(int);
    void Uint(unsigned);
    void Int64(__int64);
    void Uint64(unsigned __int64);
    void Double(double);
    void String(const char*, unsigned, bool copy);
    void StartArray();
    void EndArray(unsigned);
    void StartObject();
    void EndObject(unsigned);
private:
    void ClearStack(); // 0x1405184b0
    ImageJsonStack<ImageJsonAllocator> m_stack;
    const char* m_parseError;
    size_t m_errorOffset;
};
MS2_CHECK_SIZE(ImageJsonDocument, 0x58);


// inferred: ctor 0x140517020 / dtor 0x140517b60. Pool stack +0,
// x64 jmp_buf +0x30, parse-error pointer +0x130, error offset +0x138.
class ImageJsonReader {
public:
    ImageJsonReader(ImageJsonAllocator* = 0, size_t stackCapacity = 0x100);
    ~ImageJsonReader();
    template<unsigned flags> bool Parse(ImageJsonStringStream&, ImageJsonDocument&); // 0x140513a10
    const char* GetParseError() const { return m_parseError; } // 0x140518930
    size_t GetErrorOffset() const { return m_errorOffset; } // 0x140518900
    struct StackStream {
        explicit StackStream(ImageJsonStack<ImageJsonAllocator>& s) : stack(s), length(0) {}
        void Put(char c) { *stack.Push<char>() = c; ++length; }
        ImageJsonStack<ImageJsonAllocator>& stack;
        unsigned length;
    };
private:
    static void SkipWhitespace(ImageJsonStringStream&); // 0x140515ce0
    unsigned ParseHex4(ImageJsonStringStream&); // 0x140513df0
    static double Pow10(int); // 0x140518ee0
    template<unsigned flags> void ParseValue(ImageJsonStringStream&, ImageJsonDocument&); // 0x1405155c0
    template<unsigned flags> void ParseArray(ImageJsonStringStream&, ImageJsonDocument&); // 0x140513c10
    template<unsigned flags> void ParseObject(ImageJsonStringStream&, ImageJsonDocument&); // 0x140514950
    template<unsigned flags> void ParseString(ImageJsonStringStream&, ImageJsonDocument&); // 0x140514c70
    template<unsigned flags> void ParseNumber(ImageJsonStringStream&, ImageJsonDocument&); // 0x140513ff0
    void ParseNull(ImageJsonStringStream&, ImageJsonDocument&); // 0x140513f40
    void ParseTrue(ImageJsonStringStream&, ImageJsonDocument&); // 0x140515510
    void ParseFalse(ImageJsonStringStream&, ImageJsonDocument&); // 0x140513d30
    template<unsigned flags, class Output> void ParseStringToStream(ImageJsonStringStream&, Output&);
    ImageJsonStack<ImageJsonAllocator> m_stack;
    jmp_buf m_jump;
    const char* m_parseError;
    size_t m_errorOffset;
};
MS2_CHECK_SIZE(ImageJsonReader, 0x140);


// inferred: output reference at +0, pool stack at +8, ctor 0x140517900.
class ImageJsonWriter {
public:
    ImageJsonWriter(ImageJsonBuffer&, ImageJsonAllocator* = 0, size_t levelDepth = 0x20);
    ~ImageJsonWriter();
    ImageJsonWriter& Null();
    ImageJsonWriter& Bool(bool);
    ImageJsonWriter& Int(int);
    ImageJsonWriter& Uint(unsigned);
    ImageJsonWriter& Int64(__int64);
    ImageJsonWriter& Uint64(unsigned __int64);
    ImageJsonWriter& Double(double);
    ImageJsonWriter& String(const char*, unsigned length, bool copy = false);
    ImageJsonWriter& StartObject();
    ImageJsonWriter& EndObject(unsigned);
    ImageJsonWriter& StartArray();
    ImageJsonWriter& EndArray(unsigned);
private:
    struct Level {
        explicit Level(bool inArray_) : inArray(inArray_), valueCount(0) {}
        bool inArray;
        size_t valueCount;
    };
    void Prefix(ImageJsonValue::Type);
    void WriteNull();
    void WriteBool(bool);
    void WriteInt(int);
    void WriteUint(unsigned);
    void WriteInt64(__int64);
    void WriteUint64(unsigned __int64);
    void WriteDouble(double);
    void WriteString(const char*, unsigned);
    void WriteStartObject() { m_output.Put('{'); }
    void WriteEndObject() { m_output.Put('}'); }
    void WriteStartArray() { m_output.Put('['); }
    void WriteEndArray() { m_output.Put(']'); }
    ImageJsonBuffer& m_output;
    ImageJsonStack<ImageJsonAllocator> m_levels;
};
MS2_CHECK_SIZE(ImageJsonWriter, 0x38);
