// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CImageHttpClient (screenshot upload over WinHTTP), the JSON
// DOM/reader/writer it links (names invented, see imagejson.h) and the CByteBuffer/IntPair-style leaf functions the TU emits.
// MS2-UNIT: ?\imagehttpclient.cpp
// MS2-RANGE: 0x1400b9090-0x1400b9150 .text$di
// MS2-RANGE: 0x140511030-0x14051a170 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$StringFormat@V?$basic_string@_WU?$char_traits@_W@std@@V?$allocator@_W@2@@std@@I_KV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEBV?$basic_string@_WU?$char_traits@_W@std@@V?$allocator@_W@2@@std@@AEBIAEB_KAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@@Z 0x140513620 ; unique
// MS2-PIN: ?Parse@ImageJsonDocument@@QEAAAEAV1@PEBD@Z 0x1405139e0 ; unique
// MS2-PIN: ??$Parse@$0A@@ImageJsonReader@@QEAA_NAEAVImageJsonStringStream@@AEAVImageJsonDocument@@@Z 0x140513a10 ; unique
// MS2-PIN: ??$Parse@$0A@@ImageJsonDocument@@QEAAAEAV0@PEBD@Z 0x140513bd0 ; unique
// MS2-PIN: ??$ParseArray@$0A@@ImageJsonReader@@AEAAXAEAVImageJsonStringStream@@AEAVImageJsonDocument@@@Z 0x140513c10 ; unique
// MS2-PIN: ??$ParseNumber@$0A@@ImageJsonReader@@AEAAXAEAVImageJsonStringStream@@AEAVImageJsonDocument@@@Z 0x140513ff0 ; unique
// MS2-PIN: ??$ParseObject@$0A@@ImageJsonReader@@AEAAXAEAVImageJsonStringStream@@AEAVImageJsonDocument@@@Z 0x140514950 ; unique
// MS2-PIN: ??$ParseStream@$0A@@ImageJsonDocument@@QEAAAEAV0@AEAVImageJsonStringStream@@@Z 0x140514b40 ; unique
// MS2-PIN: ??$ParseString@$0A@@ImageJsonReader@@AEAAXAEAVImageJsonStringStream@@AEAVImageJsonDocument@@@Z 0x140514c70 ; unique
// MS2-PIN: ??$ParseStringToStream@$0A@VImageJsonStringStream@@@ImageJsonReader@@AEAAXAEAVImageJsonStringStream@@0@Z 0x140514d90 ; prop
// MS2-PIN: ??$ParseStringToStream@$0A@UStackStream@ImageJsonReader@@@ImageJsonReader@@AEAAXAEAVImageJsonStringStream@@AEAUStackStream@0@@Z 0x140515150 ; prop
// MS2-PIN: ??$ParseValue@$0A@@ImageJsonReader@@AEAAXAEAVImageJsonStringStream@@AEAVImageJsonDocument@@@Z 0x1405155c0 ; unique
// MS2-PIN: ??$Pop@D@?$ImageJsonStack@VImageJsonAllocator@@@@QEAAPEAD_K@Z 0x140515740 ; unique
// MS2-PIN: ??$ImageJsonValidateInput@VImageJsonStringStream@@@@YA_NAEAVImageJsonStringStream@@0@Z 0x140515ef0 ; prop
// MS2-PIN: ??$ImageJsonValidateInput@UStackStream@ImageJsonReader@@@@YA_NAEAVImageJsonStringStream@@AEAUStackStream@ImageJsonReader@@@Z 0x140516580 ; prop
// MS2-PIN: ??$ImageJsonValidateUtf8@UStackStream@ImageJsonReader@@@@YA_NAEAVImageJsonStringStream@@AEAUStackStream@ImageJsonReader@@@Z 0x1405165b0 ; unique
// MS2-PIN: ??_G?$TPtredDummy@VCWinHttpClient@@@@UEAAPEAXI@Z 0x140518120 ; unique
// MS2-PIN: ??_GCImageHttpClient@@UEAAPEAXI@Z 0x140518160 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\imagehttpclient.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include <string>

#include "ms2/commonfiles/imagehttpclient.h"
#include "ms2/commonfiles/imagejson.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// inferred: fixed-size JSON raw transfers use REP MOVSB/STOSB at 0x1405190b0 / 0x140517280; keep the intrinsic form.
#pragma intrinsic(memcpy, memset)

// @0x1400b9090
static CString s_strSortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};   // header-static name table of a market sort enum

// ---- unit-local views of callees emitted in other units ----

CFeatureManager* FUN_140166410();                                   // the feature manager singleton
extern int DAT_143ab2830;                                           // WorldId
extern unsigned __int64 DAT_143ab2828;                              // CharacterSn
std::string CaptureRegionJpg(int iX, int iY, int iWidth, int iHeight);   // 0x141851040 (textureutil.cpp)
std::string CaptureClientAreaJpg();                                 // 0x141850df0
void FUN_141b6de20();                                               // thread start-up (util.cpp)
// util.cpp: logs the thread's entry/exit by name (ctor 0x141b721f0 takes the name by value, dtor 0x141b722b0).
class Unk_UtilLogScope
{
public:
    Unk_UtilLogScope(CString strName);
    ~Unk_UtilLogScope();

private:
    unsigned m_nThreadId;
    CString m_strName;
};
MS2_CHECK_SIZE(Unk_UtilLogScope, 0x10);

// @0x140511030
CImageHttpClient::CImageHttpClient()
    : m_nMode(0)
    , m_pImageThread(0)
    , m_pUploadThread(0)
    , m_request(0)
{
}

// @0x1405110d0
CImageHttpClient::~CImageHttpClient()
{
    ClearRequest();
    if (m_pImageThread != 0)
    {
        WaitForSingleObject(m_pImageThread->m_hThread, 1000);
        m_pImageThread = 0;
    }
    if (m_pUploadThread != 0)
    {
        WaitForSingleObject(m_pUploadThread->m_hThread, 1000);
        m_pUploadThread = 0;
    }
}

// @0x140511190
void CImageHttpClient::SetMode(int nMode)
{
    m_nMode = nMode;
}

// @0x1405111b0
void CImageHttpClient::SetImage(int x, int y, int nWidth, int nHeight)
{
    m_rect.left = x;
    m_rect.top = y;
    m_rect.right = x + nWidth;
    m_rect.bottom = y + nHeight;
}

// @0x140511210
bool CImageHttpClient::RequestKey()
{
    if (CanSend())
    {
        if (IsRequestPending())
            return false;
        std::wstring strUrl((const wchar_t*)StringFormat(L"{0}?WorldId={1}&CharacterSn={2}&ImageType={3}", GetUrl(), DAT_143ab2830, DAT_143ab2828, GetImageType()));
        const TPtrValue<CWinHttpClient> request = CreateRequest(strUrl);
        request->FUN_140920cf0(L"GET", false);
        SetRequest(request);
        if (request->FUN_140922f20() != 0)
            return false;
    }
    return true;
}

// @0x140511450
bool CImageHttpClient::UploadTemporaryKey(std::string strKey)
{
    if (CanSend())
    {
        if (IsRequestPending())
            return false;
        CByteBuffer buffer;
        if (BuildTemporaryKey(buffer, strKey))
        {
            const TPtrValue<CWinHttpClient> request = CreateRequest(GetUrl());
            request->FUN_140922b90(buffer.FUN_140204eb0(), buffer.GetLength());
            request->FUN_140922d20(MakeHeaders(buffer));
            SetRequest(request);
            m_pUploadThread = AfxBeginThread(ResponseServer, this);
            return true;
        }
    }
    return false;
}

// @0x1405116c0
bool CImageHttpClient::BeginImage()
{
    if (CanSend())
    {
        if (IsRequestPending())
            return false;
        CByteBuffer buffer;
        if (BuildImage(buffer))
        {
            const TPtrValue<CWinHttpClient> request = CreateRequest(GetUrl());
            request->FUN_140922b90(buffer.FUN_140204eb0(), buffer.GetLength());
            request->FUN_140922d20(MakeHeaders(buffer));
            SetRequest(request);
            m_pImageThread = AfxBeginThread(ResponseClient, this);
            return true;
        }
    }
    return false;
}

// MS2-FUNCTIONAL: EH unwind/string temporaries differ from exe
// @0x1405118f0
unsigned CImageHttpClient::SendWebScreenshot()
{
    TPtrValue<CWinHttpClient> request = GetRequest();
    if (request.get() != 0 && request->FUN_140920cf0(L"POST", false))
    {
        if (request->FUN_140922f20() != 0)
            return 0;
        std::string strKey = ParseTemporaryKey(request->GetResponseContent());
        COutPacket packet(static_cast<int>(SendOp::WebScreenshot), 0);
        packet.WriteUInt8((unsigned char)m_nMode);
        packet.WriteString(CString(strKey.c_str()));
        FUN_140710590(packet);
    }
    ClearRequest();
    return 0;
}

// @0x140511b30
unsigned CImageHttpClient::SendTemporaryKey()
{
    if (CanSend())
    {
        TPtrValue<CWinHttpClient> request = GetRequest();
        if (request == 0)
            return 0;
        request->FUN_140920cf0(L"PUT", false);
        ClearRequest();
    }
    return 0;
}

// @0x140511c10
bool CImageHttpClient::CanSend()
{
    if (!FUN_140166410()->FUN_14036e5b0())
        return false;
    if (!FUN_140166410()->FUN_14036d570(0xf7))
        return false;
    if (m_timer.FUN_140268870(3000) == 0)
        return false;
    return true;
}

// @0x140511c80
void CImageHttpClient::ClearRequest()
{
    if (Unk_LockGuard guard = m_lock) { __assume(0); } else
    {
        m_request = 0;
    }
}

// MS2-FUNCTIONAL: JSON writer temporaries ordering differs from exe
// @0x140511cf0
bool CImageHttpClient::BuildImage(CByteBuffer& data)
{
    std::string strImage = CaptureImage();
    if (strImage.empty())
        return false;
    std::string strType = GetImageType();
    ImageJsonBuffer buffer(0, 0x100);
    {
        ImageJsonDocument document(0, 0x400);
        document.SetObject();
        document.AddMember("WorldId", DAT_143ab2830, document.GetAllocator());
        document.AddMember("CharacterSn", DAT_143ab2828, document.GetAllocator());
        document.AddMember("Base64Image", strImage.c_str(), document.GetAllocator());
        document.AddMember("ImageType", strType.c_str(), document.GetAllocator());
        ImageJsonWriter writer(buffer, 0, 0x20);
        document.Accept(writer);
    }
    data.WriteBytes(buffer.GetString(), (int)buffer.GetSize());
    return true;
}

// @0x140511f80
bool CImageHttpClient::BuildTemporaryKey(CByteBuffer& data, const std::string& strKey)
{
    if (strKey.empty())
        return false;
    ImageJsonBuffer buffer(0, 0x100);
    {
        ImageJsonDocument document(0, 0x400);
        document.SetObject();
        document.AddMember("temporaryKey", strKey.c_str(), document.GetAllocator());
        ImageJsonWriter writer(buffer, 0, 0x20);
        document.Accept(writer);
    }
    data.WriteBytes(buffer.GetString(), (int)buffer.GetSize());
    return true;
}

// @0x140512100
std::wstring CImageHttpClient::GetUrl()
{
    return std::wstring(L"");
}

// @0x140512150
std::wstring CImageHttpClient::MakeHeaders(CByteBuffer& data)
{
    const char* szContentType = "Content-Type: application/json\r\n";
    const char* szConnection = "Connection: close\r\n";
    unsigned nLength = data.GetLength();
    CString strLength = Unk_SocketFormat("Content-Length: {0}\r\n", nLength);
    std::wstring strHeaders((const wchar_t*)StringFormat(L"{0}{1}{2}", szContentType, strLength, szConnection));
    return strHeaders;
}

// @0x140512280
std::string CImageHttpClient::GetImageType()
{
    if (m_nMode == 1)
        return std::string("character");
    return std::string("housing");
}

// @0x1405122f0
std::string CImageHttpClient::CaptureImage()
{
    if (m_nMode == 1)
        return CaptureRegionJpg(m_rect.left, m_rect.top, m_rect.Width(), m_rect.Height());
    return CaptureClientAreaJpg();
}

// MS2-FUNCTIONAL: JSON parse temporaries ordering differs from exe
// @0x1405123a0
std::string CImageHttpClient::ParseTemporaryKey(const std::wstring& strResponse)
{
    std::string strText;
    strText.assign(strResponse.begin(), strResponse.end());
    ImageJsonDocument document(0, 0x400);
    if (document.Parse(strText.c_str()).HasParseError())
        return std::string("");
    if (!document.HasMember("temporaryKey"))
        return std::string("");
    if (!document["temporaryKey"].IsString())
        return std::string("");
    std::string strKey(document["temporaryKey"].GetString());
    return strKey;
}

// @0x1405125f0
TPtrValue<CWinHttpClient> CImageHttpClient::CreateRequest(const std::wstring& strUrl)
{
    TPtrValue<CWinHttpClient> request;
    request = Unk_GrNewTag(0);
    request->SetRequestURL(strUrl);
    if (Unk_LockGuard guard = m_lock) { __assume(0); } else
    {
        m_request = request;
    }
    return request;
}

// @0x1405126d0
TPtrValue<CWinHttpClient> CImageHttpClient::GetRequest()
{
    if (Unk_LockGuard guard = m_lock) { __assume(0); } else
    {
        return static_cast<const TPtrValue<CWinHttpClient>&>(m_request);
    }
}

// @0x140512760
void CImageHttpClient::SetRequest(TPtrValue<CWinHttpClient> request)
{
    if (Unk_LockGuard guard = m_lock) { __assume(0); } else
    {
        m_request = request;
    }
}

// @0x1405127e0
bool CImageHttpClient::IsRequestPending()
{
    if (Unk_LockGuard guard = m_lock) { __assume(0); } else
    {
        return m_request.get() != 0;
    }
}

// @0x140512880
unsigned __cdecl CImageHttpClient::ResponseClient(void* pParam)
{
    FUN_141b6de20();
    Unk_UtilLogScope scope(CString(__FUNCTION__));
    CImageHttpClient* pClient = static_cast<CImageHttpClient*>(pParam);
    if (pClient == 0)
        return 0;
    return pClient->SendWebScreenshot();
}

// @0x140512920
unsigned __cdecl CImageHttpClient::ResponseServer(void* pParam)
{
    FUN_141b6de20();
    Unk_UtilLogScope scope(CString(__FUNCTION__));
    CImageHttpClient* pClient = static_cast<CImageHttpClient*>(pParam);
    if (pClient == 0)
        return 0;
    return pClient->SendTemporaryKey();
}

// @0x140517950
CByteBuffer::CByteBuffer()
{
    m_aByteBuff.SetCount(0x100);
    FUN_140518490();
}

// @0x140517e50
CByteBuffer::~CByteBuffer()
{
}

// @0x140518490
void CByteBuffer::FUN_140518490()
{
    m_uLength = 0;
    m_uOffset = 0;
}

// @0x140518920
unsigned CByteBuffer::vfunc_0()
{
    return m_uOffset;
}

// @0x140518a50
short CByteBuffer::vfunc_1()
{
    return *reinterpret_cast<const short*>(&static_cast<const ATL::CAtlArray<unsigned char>&>(m_aByteBuff)[0]);
}

// @0x140517b00
Unk_ImageTimer::Unk_ImageTimer()
    : m_nTick(0)
    , m_nLast(0)
{
}

ImageJsonAllocator::ImageJsonAllocator(size_t chunkSize, ImageJsonCrtAllocator* allocator)
    : m_head(0), m_chunkSize(chunkSize), m_userBuffer(0), m_allocator(allocator), m_ownAllocator(0) {
    if (!m_allocator) {
        m_ownAllocator = m_allocator = new ImageJsonCrtAllocator();
    }
    AddChunk(m_chunkSize);
}

ImageJsonAllocator::~ImageJsonAllocator() {
    Clear();
    delete m_ownAllocator;
}

void ImageJsonAllocator::Clear() {
    while (m_head && m_head != m_userBuffer) {
        Chunk* next = m_head->next;
        ImageJsonCrtAllocator::Free(m_head);
        m_head = next;
    }
}

void ImageJsonAllocator::AddChunk(size_t capacity) {
    Chunk* chunk = static_cast<Chunk*>(m_allocator->Malloc(sizeof(Chunk) + capacity));
    chunk->capacity = capacity;
    chunk->size = 0;
    chunk->next = m_head;
    m_head = chunk;
}

void* ImageJsonAllocator::Malloc(size_t size) {
    size = (size + 3) & ~size_t(3);
    if (m_head->size + size > m_head->capacity)
        AddChunk(m_chunkSize > size ? m_chunkSize : size);
    void* result = reinterpret_cast<char*>(m_head) + sizeof(Chunk) + m_head->size;
    m_head->size += size;
    return result;
}

void* ImageJsonAllocator::Realloc(void* original, size_t originalSize, size_t newSize) {
    if (!original) return Malloc(newSize);
    if (originalSize >= newSize) return original;
    if (original == reinterpret_cast<char*>(m_head) + sizeof(Chunk) + m_head->size - originalSize) {
        size_t increment = newSize - originalSize;
        increment = (increment + 3) & ~size_t(3);
        if (m_head->size + increment <= m_head->capacity) {
            m_head->size += increment;
            return original;
        }
    }
    void* result = Malloc(newSize);
    memcpy(result, original, originalSize);
    return result;
}

ImageJsonValue::ImageJsonValue() : m_flags(0) {}

ImageJsonValue::ImageJsonValue(Type type) {
    // inferred: seven dwords at 0x142d55118.
    static const unsigned flags[] = {0, 0x101, 0x102, 3, 4, 0x100005, 0x7e00};
    m_flags = flags[type];
    memset(&m_data, 0, sizeof(m_data));
}

ImageJsonValue::ImageJsonValue(int value) : m_flags(0x1606) {
    m_data.number.i64 = value;
    if (value >= 0) m_flags |= 0x2800;
}

ImageJsonValue::ImageJsonValue(unsigned __int64 value) : m_flags(0x2206) {
    m_data.number.u64 = value;
    if (!(value & 0x8000000000000000ULL)) m_flags |= 0x1000;
    if (!(value & 0xffffffff00000000ULL)) m_flags |= 0x800;
    if (!(value & 0xffffffff80000000ULL)) m_flags |= 0x400;
}

ImageJsonValue::ImageJsonValue(double value) : m_flags(0x4206) { m_data.number.d = value; }
ImageJsonValue::ImageJsonValue(bool value) { m_flags = value ? 0x102 : 0x101; }
ImageJsonValue::ImageJsonValue(const char* str) { SetStringRaw(str, StringLength(str)); }
ImageJsonValue::ImageJsonValue(const char* str, unsigned length) : m_flags(0x100005) {
    m_data.string.str = str;
    m_data.string.length = length;
}

ImageJsonValue::~ImageJsonValue() {
    if (ImageJsonAllocator::kNeedFree) {
        switch (m_flags) {
        case Array:
            for (ImageJsonValue* v = m_data.array.elements; v != m_data.array.elements + m_data.array.size; ++v)
                v->~ImageJsonValue();
            ImageJsonAllocator::Free(m_data.array.elements);
            break;
        case Object:
            for (Member* m = m_data.object.members; m != m_data.object.members + m_data.object.size; ++m) {
                m->name.~ImageJsonValue();
                m->value.~ImageJsonValue();
            }
            ImageJsonAllocator::Free(m_data.object.members);
            break;
        case 0x300005:
            ImageJsonAllocator::Free(const_cast<char*>(m_data.string.str));
            break;
        }
    }
}

size_t ImageJsonValue::StringLength(const char* str) {
    const char* p;
    p = str;
    while (*p) ++p;
    return p - str;
}

void ImageJsonValue::SetStringRaw(const char* str, unsigned length) {
    m_flags = 0x100005;
    m_data.string.str = str;
    m_data.string.length = length;
}

void ImageJsonValue::RawAssign(ImageJsonValue& rhs) {
    memcpy(this, &rhs, sizeof(ImageJsonValue));
    rhs.m_flags = 0;
}

ImageJsonValue& ImageJsonValue::SetObject() {
    this->~ImageJsonValue();
    new (this) ImageJsonValue(Object);
    return *this;
}

ImageJsonValue& ImageJsonValue::AddMember(ImageJsonValue& name, ImageJsonValue& value, ImageJsonAllocator& allocator) {
    Data::ObjectData& object = m_data.object;
    if (object.size >= object.capacity) {
        if (object.capacity == 0) {
            object.capacity = 16;
            object.members = static_cast<Member*>(allocator.Malloc(object.capacity * sizeof(Member)));
        } else {
            unsigned oldCapacity = object.capacity;
            object.capacity *= 2;
            object.members = static_cast<Member*>(allocator.Realloc(object.members,
                oldCapacity * sizeof(Member), object.capacity * sizeof(Member)));
        }
    }
    object.members[object.size].name.RawAssign(name);
    object.members[object.size].value.RawAssign(value);
    ++object.size;
    return *this;
}

ImageJsonValue& ImageJsonValue::AddMember(const char* name, int value, ImageJsonAllocator& allocator) {
    ImageJsonValue n(name, StringLength(name));
    ImageJsonValue v(value);
    return AddMember(n, v, allocator);
}
ImageJsonValue& ImageJsonValue::AddMember(const char* name, const char* value, ImageJsonAllocator& allocator) {
    ImageJsonValue n(name, StringLength(name));
    ImageJsonValue v(value);
    return AddMember(n, v, allocator);
}
ImageJsonValue& ImageJsonValue::AddMember(const char* name, unsigned __int64 value, ImageJsonAllocator& allocator) {
    ImageJsonValue n(name, StringLength(name));
    ImageJsonValue v(value);
    return AddMember(n, v, allocator);
}

ImageJsonValue::Member* ImageJsonValue::FindMember(const char* name) {
    Data::ObjectData& object = m_data.object;
    for (Member* m = object.members; m != m_data.object.members + m_data.object.size; ++m)
        if (name[m->name.m_data.string.length] == '\0' &&
            memcmp(m->name.m_data.string.str, name, m->name.m_data.string.length) == 0) return m;
    return 0;
}
const ImageJsonValue::Member* ImageJsonValue::FindMember(const char* name) const {
    return const_cast<ImageJsonValue*>(this)->FindMember(name);
}
bool ImageJsonValue::HasMember(const char* name) const { return FindMember(name) != 0; }
ImageJsonValue& ImageJsonValue::operator[](const char* name) {
    if (Member* member = FindMember(name)) return member->value;
    else {
        static ImageJsonValue nullValue;
        return nullValue;
    }
}

ImageJsonDocument::ImageJsonDocument(ImageJsonAllocator* allocator, size_t stackCapacity)
    : m_stack(allocator, stackCapacity), m_parseError(0), m_errorOffset(0) {}
ImageJsonDocument::~ImageJsonDocument() {}

ImageJsonDocument& ImageJsonDocument::Parse(const char* str) { return Parse<0>(str); }

ImageJsonBuffer::ImageJsonBuffer(ImageJsonCrtAllocator* allocator, size_t capacity)
    : m_stack(allocator, capacity) {}
ImageJsonBuffer::~ImageJsonBuffer() {}

ImageJsonWriter::ImageJsonWriter(ImageJsonBuffer& output, ImageJsonAllocator* allocator, size_t levelDepth)
    : m_output(output), m_levels(allocator, levelDepth * sizeof(Level)) {}
ImageJsonWriter::~ImageJsonWriter() {}

ImageJsonWriter& ImageJsonWriter::Null() { Prefix(ImageJsonValue::Null); WriteNull(); return *this; }
ImageJsonWriter& ImageJsonWriter::Bool(bool value) { Prefix(value ? ImageJsonValue::True : ImageJsonValue::False); WriteBool(value); return *this; }
ImageJsonWriter& ImageJsonWriter::Int(int value) { Prefix(ImageJsonValue::Number); WriteInt(value); return *this; }
ImageJsonWriter& ImageJsonWriter::Uint(unsigned value) { Prefix(ImageJsonValue::Number); WriteUint(value); return *this; }
ImageJsonWriter& ImageJsonWriter::Int64(__int64 value) { Prefix(ImageJsonValue::Number); WriteInt64(value); return *this; }
ImageJsonWriter& ImageJsonWriter::Uint64(unsigned __int64 value) { Prefix(ImageJsonValue::Number); WriteUint64(value); return *this; }
ImageJsonWriter& ImageJsonWriter::Double(double value) { Prefix(ImageJsonValue::Number); WriteDouble(value); return *this; }
ImageJsonWriter& ImageJsonWriter::String(const char* str, unsigned length, bool) {
    Prefix(ImageJsonValue::String);
    WriteString(str, length);
    return *this;
}
ImageJsonWriter& ImageJsonWriter::StartObject() {
    Prefix(ImageJsonValue::Object);
    new (m_levels.Push<Level>()) Level(false);
    WriteStartObject();
    return *this;
}
ImageJsonWriter& ImageJsonWriter::StartArray() {
    Prefix(ImageJsonValue::Array);
    new (m_levels.Push<Level>()) Level(true);
    WriteStartArray();
    return *this;
}
ImageJsonWriter& ImageJsonWriter::EndObject(unsigned) {
    m_levels.Pop<Level>(1);
    WriteEndObject();
    if (m_levels.Empty()) m_output.Flush();
    return *this;
}
ImageJsonWriter& ImageJsonWriter::EndArray(unsigned) {
    m_levels.Pop<Level>(1);
    WriteEndArray();
    if (m_levels.Empty()) m_output.Flush();
    return *this;
}

void ImageJsonWriter::Prefix(ImageJsonValue::Type) {
    if (m_levels.GetSize() != 0) {
        Level* level = m_levels.Top<Level>();
        if (level->valueCount > 0) {
            if (level->inArray) m_output.Put(',');
            else m_output.Put(level->valueCount % 2 == 0 ? ',' : ':');
        }
        // inferred: retained validation expression at 0x140518fcf..0x140518ff1.
        (void)(level->inArray || level->valueCount % 2 == 0);
        ++level->valueCount;
    }
}
void ImageJsonWriter::WriteNull() { m_output.Put('n'); m_output.Put('u'); m_output.Put('l'); m_output.Put('l'); }
void ImageJsonWriter::WriteBool(bool value) {
    if (value) { m_output.Put('t'); m_output.Put('r'); m_output.Put('u'); m_output.Put('e'); }
    else { m_output.Put('f'); m_output.Put('a'); m_output.Put('l'); m_output.Put('s'); m_output.Put('e'); }
}
void ImageJsonWriter::WriteInt(int value) {
    if (value < 0) { m_output.Put('-'); value = -value; }
    WriteUint(static_cast<unsigned>(value));
}
void ImageJsonWriter::WriteInt64(__int64 value) {
    if (value < 0) { m_output.Put('-'); value = -value; }
    WriteUint64(static_cast<unsigned __int64>(value));
}
void ImageJsonWriter::WriteUint(unsigned value) {
    char buffer[10];
    char* p = buffer;
    do { *p++ = static_cast<char>(value % 10 + '0'); value /= 10; } while (value > 0);
    do { m_output.Put(*--p); } while (p != buffer);
}
void ImageJsonWriter::WriteUint64(unsigned __int64 value) {
    char buffer[20];
    char* p = buffer;
    do { *p++ = static_cast<char>(value % 10) + '0'; value /= 10; } while (value > 0);
    do { m_output.Put(*--p); } while (p != buffer);
}
void ImageJsonWriter::WriteDouble(double value) {
    char buffer[100];
    int length = sprintf_s(buffer, 100, "%g", value);
    for (int i = 0; i < length; ++i) m_output.Put(buffer[i]);
}

// inferred: UTF-8 to UTF-8 transcode at 0x140515e90 forwards one code unit.
static bool ImageJsonTranscode(ImageJsonStringStream& input, ImageJsonBuffer& output) {
    output.Put(input.Take());
    return true;
}
void ImageJsonWriter::WriteString(const char* str, unsigned length) {
    static const char escape[256] = {
        'u','u','u','u','u','u','u','u','b','t','n','u','f','r','u','u',
        'u','u','u','u','u','u','u','u','u','u','u','u','u','u','u','u',
        0,0,'"',0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,'\\',0,0,0
    };
    static const char hex[] = "0123456789ABCDEF";
    m_output.Put('"');
    ImageJsonStringStream input(str);
    while (input.Tell() < length) {
        unsigned char c = static_cast<unsigned char>(input.Peek());
        if ((sizeof(char) == 1 || static_cast<unsigned>(c) < 256) && escape[c]) {
            input.Take();
            m_output.Put('\\');
            m_output.Put(escape[c]);
            if (escape[c] == 'u') {
                m_output.Put('0'); m_output.Put('0');
                m_output.Put(hex[c >> 4]); m_output.Put(hex[c & 15]);
            }
        } else ImageJsonTranscode(input, m_output);
    }
    m_output.Put('"');
}

const ImageJsonValue& ImageJsonValue::Accept(ImageJsonWriter& writer) const {
    switch (GetType()) {
    case Null: writer.Null(); break;
    case False: writer.Bool(false); break;
    case True: writer.Bool(true); break;
    case Object:
        writer.StartObject();
        for (Member* m = m_data.object.members; m != m_data.object.members + m_data.object.size; ++m) {
            writer.String(m->name.m_data.string.str, m->name.m_data.string.length);
            m->value.Accept(writer);
        }
        writer.EndObject(m_data.object.size);
        break;
    case Array:
        writer.StartArray();
        for (ImageJsonValue* v = m_data.array.elements; v != m_data.array.elements + m_data.array.size; ++v)
            v->Accept(writer);
        writer.EndArray(m_data.array.size);
        break;
    case String: writer.String(m_data.string.str, m_data.string.length); break;
    case Number:
        if (IsInt()) writer.Int(m_data.number.i.value);
        else if (IsUint()) writer.Uint(m_data.number.u.value);
        else if (IsInt64()) writer.Int64(m_data.number.i64);
        else if (IsUint64()) writer.Uint64(m_data.number.u64);
        else writer.Double(m_data.number.d);
    }
    return *this;
}

ImageJsonValue::ImageJsonValue(unsigned value) : m_flags(0x3a06) {
    m_data.number.u64 = value;
    if (!(value & 0x80000000)) m_flags |= 0x1400;
}
ImageJsonValue::ImageJsonValue(__int64 value) : m_flags(0x1206) {
    m_data.number.i64 = value;
    if (value >= 0) {
        m_flags |= 0x2206;
        if (!(value & 0xffffffff00000000ULL)) m_flags |= 0x800;
        if (!(value & 0xffffffff80000000ULL)) m_flags |= 0x400;
    } else {
        if (value >= -2147483647LL - 1) m_flags |= 0x400;
    }
}
ImageJsonValue::ImageJsonValue(const char* str, unsigned length, ImageJsonAllocator& allocator) {
    SetStringRaw(str, length, allocator);
}
void ImageJsonValue::SetStringRaw(const char* str, unsigned length, ImageJsonAllocator& allocator) {
    m_flags = 0x300005;
    m_data.string.str = static_cast<char*>(allocator.Malloc(length + 1));
    m_data.string.length = length;
    memcpy(const_cast<char*>(m_data.string.str), str, length);
    const_cast<char*>(m_data.string.str)[length] = '\0';
}
void ImageJsonValue::SetArrayRaw(ImageJsonValue* elements, unsigned count, ImageJsonAllocator& allocator) {
    m_flags = Array;
    m_data.array.elements = static_cast<ImageJsonValue*>(allocator.Malloc(count * sizeof(ImageJsonValue)));
    memcpy(m_data.array.elements, elements, count * sizeof(ImageJsonValue));
    m_data.array.size = m_data.array.capacity = count;
}
void ImageJsonValue::SetObjectRaw(Member* members, unsigned count, ImageJsonAllocator& allocator) {
    m_flags = Object;
    m_data.object.members = static_cast<Member*>(allocator.Malloc(count * sizeof(Member)));
    memcpy(m_data.object.members, members, count * sizeof(Member));
    m_data.object.size = m_data.object.capacity = count;
}
ImageJsonValue& ImageJsonValue::SetNull() {
    this->~ImageJsonValue();
    new (this) ImageJsonValue();
    return *this;
}

void ImageJsonDocument::Null() { new (m_stack.Push<ImageJsonValue>()) ImageJsonValue(); }
void ImageJsonDocument::Bool(bool value) { new (m_stack.Push<ImageJsonValue>()) ImageJsonValue(value); }
void ImageJsonDocument::Int(int value) { new (m_stack.Push<ImageJsonValue>()) ImageJsonValue(value); }
void ImageJsonDocument::Uint(unsigned value) { new (m_stack.Push<ImageJsonValue>()) ImageJsonValue(value); }
void ImageJsonDocument::Int64(__int64 value) { new (m_stack.Push<ImageJsonValue>()) ImageJsonValue(value); }
void ImageJsonDocument::Uint64(unsigned __int64 value) { new (m_stack.Push<ImageJsonValue>()) ImageJsonValue(value); }
void ImageJsonDocument::Double(double value) { new (m_stack.Push<ImageJsonValue>()) ImageJsonValue(value); }
void ImageJsonDocument::String(const char* str, unsigned length, bool copy) {
    if (copy) new (m_stack.Push<ImageJsonValue>()) ImageJsonValue(str, length, GetAllocator());
    else new (m_stack.Push<ImageJsonValue>()) ImageJsonValue(str, length);
}
void ImageJsonDocument::StartArray() { new (m_stack.Push<ImageJsonValue>()) ImageJsonValue(ImageJsonValue::Array); }
void ImageJsonDocument::StartObject() { new (m_stack.Push<ImageJsonValue>()) ImageJsonValue(ImageJsonValue::Object); }
void ImageJsonDocument::EndArray(unsigned count) {
    ImageJsonValue* elements = m_stack.Pop<ImageJsonValue>(count);
    m_stack.Top<ImageJsonValue>()->SetArrayRaw(elements, count, GetAllocator());
}
void ImageJsonDocument::EndObject(unsigned count) {
    ImageJsonValue::Member* members = m_stack.Pop<ImageJsonValue::Member>(count);
    m_stack.Top<ImageJsonValue>()->SetObjectRaw(members, count, GetAllocator());
}
void ImageJsonDocument::ClearStack() {
    if (ImageJsonAllocator::kNeedFree) {
        while (m_stack.GetSize() > 0) m_stack.Pop<ImageJsonValue>(1)->~ImageJsonValue();
    } else m_stack.Clear();
}
template<unsigned flags> ImageJsonDocument& ImageJsonDocument::Parse(const char* str) {
    ImageJsonStringStream stream(str);
    return ParseStream<flags>(stream);
}
template<unsigned flags> ImageJsonDocument& ImageJsonDocument::ParseStream(ImageJsonStringStream& stream) {
    SetNull();
    ImageJsonReader reader;
    if (reader.Parse<flags>(stream, *this)) {
        RawAssign(*m_stack.Pop<ImageJsonValue>(1));
        m_parseError = 0;
        m_errorOffset = 0;
    } else {
        m_parseError = reader.GetParseError();
        m_errorOffset = reader.GetErrorOffset();
        ClearStack();
    }
    return *this;
}

ImageJsonReader::ImageJsonReader(ImageJsonAllocator* allocator, size_t capacity)
    : m_stack(allocator, capacity), m_parseError(0), m_errorOffset(0) {}
ImageJsonReader::~ImageJsonReader() {}

// inferred: parser errors store these two fields and longjmp to the reader's
// own 256-byte buffer (0x140513a10 and each error site in the starter-kit ASM).
#define IMAGE_JSON_ERROR(message, offset) do { m_parseError = (message); m_errorOffset = (offset); longjmp(m_jump, 1); } while (false)

void ImageJsonReader::SkipWhitespace(ImageJsonStringStream& input) {
    ImageJsonStringStream stream = input;
    while (stream.Peek() == ' ' || stream.Peek() == '\n' || stream.Peek() == '\r' || stream.Peek() == '\t')
        stream.Take();
    input = stream;
}

template<unsigned flags> bool ImageJsonReader::Parse(ImageJsonStringStream& stream, ImageJsonDocument& handler) {
    m_parseError = 0;
    m_errorOffset = 0;
    if (setjmp(m_jump)) { m_stack.Clear(); return false; }
    SkipWhitespace(stream);
    if (stream.Peek() == '\0') IMAGE_JSON_ERROR("Text only contains white space(s)", stream.Tell());
    else {
        switch (stream.Peek()) {
        case '{': ParseObject<flags>(stream, handler); break;
        case '[': ParseArray<flags>(stream, handler); break;
        default: IMAGE_JSON_ERROR("Expect either an object or array at root", stream.Tell());
        }
        SkipWhitespace(stream);
        if (stream.Peek() != '\0') IMAGE_JSON_ERROR("Nothing should follow the root object or array.", stream.Tell());
    }
    return true;
}

void ImageJsonReader::ParseNull(ImageJsonStringStream& stream, ImageJsonDocument& handler) {
    stream.Take();
    if (stream.Take() == 'u' && stream.Take() == 'l' && stream.Take() == 'l') handler.Null();
    else IMAGE_JSON_ERROR("Invalid value", stream.Tell() - 1);
}
void ImageJsonReader::ParseTrue(ImageJsonStringStream& stream, ImageJsonDocument& handler) {
    stream.Take();
    if (stream.Take() == 'r' && stream.Take() == 'u' && stream.Take() == 'e') handler.Bool(true);
    else IMAGE_JSON_ERROR("Invalid value", stream.Tell());
}
void ImageJsonReader::ParseFalse(ImageJsonStringStream& stream, ImageJsonDocument& handler) {
    stream.Take();
    if (stream.Take() == 'a' && stream.Take() == 'l' && stream.Take() == 's' && stream.Take() == 'e') handler.Bool(false);
    else IMAGE_JSON_ERROR("Invalid value", stream.Tell() - 1);
}

template<unsigned flags> void ImageJsonReader::ParseArray(ImageJsonStringStream& stream, ImageJsonDocument& handler) {
    stream.Take();
    handler.StartArray();
    SkipWhitespace(stream);
    if (stream.Peek() == ']') { stream.Take(); handler.EndArray(0); return; }
    for (unsigned count = 0;;) {
        ParseValue<flags>(stream, handler);
        ++count;
        SkipWhitespace(stream);
        switch (stream.Take()) {
        case ',': SkipWhitespace(stream); break;
        case ']': handler.EndArray(count); return;
        default: IMAGE_JSON_ERROR("Must be a comma or ']' after an array element.", stream.Tell());
        }
    }
}
template<unsigned flags> void ImageJsonReader::ParseObject(ImageJsonStringStream& stream, ImageJsonDocument& handler) {
    stream.Take();
    handler.StartObject();
    SkipWhitespace(stream);
    if (stream.Peek() == '}') { stream.Take(); handler.EndObject(0); return; }
    for (unsigned count = 0;;) {
        if (stream.Peek() != '"') IMAGE_JSON_ERROR("Name of an object member must be a string", stream.Tell());
        ParseString<flags>(stream, handler);
        SkipWhitespace(stream);
        if (stream.Take() != ':') IMAGE_JSON_ERROR("There must be a colon after the name of object member", stream.Tell());
        SkipWhitespace(stream);
        ParseValue<flags>(stream, handler);
        SkipWhitespace(stream);
        ++count;
        switch (stream.Take()) {
        case ',': SkipWhitespace(stream); break;
        case '}': handler.EndObject(count); return;
        default: IMAGE_JSON_ERROR("Must be a comma or '}' after an object member", stream.Tell());
        }
    }
}

unsigned ImageJsonReader::ParseHex4(ImageJsonStringStream& input) {
    ImageJsonStringStream stream = input;
    unsigned codepoint = 0;
    for (int i = 0; i < 4; ++i) {
        char c = stream.Take();
        codepoint <<= 4;
        codepoint += c;
        if (c >= '0' && c <= '9') codepoint -= '0';
        else if (c >= 'A' && c <= 'F') codepoint -= 'A' - 10;
        else if (c >= 'a' && c <= 'f') codepoint -= 'a' - 10;
        else IMAGE_JSON_ERROR("Incorrect hex digit after \\u escape", stream.Tell() - 1);
    }
    input = stream;
    return codepoint;
}

template<class Output> static void ImageJsonEncodeUtf8(Output& output, unsigned codepoint) {
    if (codepoint <= 0x7f) output.Put(static_cast<char>(codepoint & 0xff));
    else if (codepoint <= 0x7ff) {
        output.Put(static_cast<char>(0xc0 | ((codepoint >> 6) & 0xff)));
        output.Put(static_cast<char>(0x80 | (codepoint & 0x3f)));
    } else if (codepoint <= 0xffff) {
        output.Put(static_cast<char>(0xe0 | ((codepoint >> 12) & 0xff)));
        output.Put(static_cast<char>(0x80 | ((codepoint >> 6) & 0x3f)));
        output.Put(static_cast<char>(0x80 | (codepoint & 0x3f)));
    } else {
        output.Put(static_cast<char>(0xf0 | ((codepoint >> 18) & 0xff)));
        output.Put(static_cast<char>(0x80 | ((codepoint >> 12) & 0x3f)));
        output.Put(static_cast<char>(0x80 | ((codepoint >> 6) & 0x3f)));
        output.Put(static_cast<char>(0x80 | (codepoint & 0x3f)));
    }
}
template<class Output> static bool ImageJsonTranscodeInput(ImageJsonStringStream& input, Output& output) {
    output.Put(input.Take());
    return true;
}
// inferred: validating backends 0x140515f20 / 0x1405165b0 remain separate
// reconstruction work; wrappers 0x140515ef0 / 0x140516580 forward to them.
// inferred: byte-class table at 0x142d55770 (continuation classes 0x10/0x40/0x20).
static unsigned char ImageJsonUtf8Range(unsigned char c) {
    static const unsigned char type[256] = {
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
        0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
        0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,
        0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,
        0x08,0x08,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x0a,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x04,0x03,0x03,
        0x0b,0x06,0x06,0x06,0x05,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,
    };
    return type[c];
}
template<class Output> bool ImageJsonValidateUtf8(ImageJsonStringStream& input, Output& output) {
    char c = input.Take();
    output.Put(c);
    if (!(c & 0x80)) return true;
    bool result = true;
#define IMAGE_JSON_COPY_RANGE(mask) c = input.Take(); output.Put(c); result &= (ImageJsonUtf8Range(static_cast<unsigned char>(c)) & (mask)) != 0
    switch (ImageJsonUtf8Range(static_cast<unsigned char>(c))) {
    case 2:
        IMAGE_JSON_COPY_RANGE(0x70);
        return result;
    case 3:
        IMAGE_JSON_COPY_RANGE(0x70); IMAGE_JSON_COPY_RANGE(0x70);
        return result;
    case 4:
        IMAGE_JSON_COPY_RANGE(0x50); IMAGE_JSON_COPY_RANGE(0x70);
        return result;
    case 5:
        IMAGE_JSON_COPY_RANGE(0x10); IMAGE_JSON_COPY_RANGE(0x70); IMAGE_JSON_COPY_RANGE(0x70);
        return result;
    case 6:
        IMAGE_JSON_COPY_RANGE(0x70); IMAGE_JSON_COPY_RANGE(0x70); IMAGE_JSON_COPY_RANGE(0x70);
        return result;
    case 10:
        IMAGE_JSON_COPY_RANGE(0x20); IMAGE_JSON_COPY_RANGE(0x70);
        return result;
    case 11:
        IMAGE_JSON_COPY_RANGE(0x60); IMAGE_JSON_COPY_RANGE(0x70); IMAGE_JSON_COPY_RANGE(0x70);
        return result;
    default: return false;
    }
#undef IMAGE_JSON_COPY_RANGE
}
template<class Output> static bool ImageJsonValidateInput(ImageJsonStringStream& input, Output& output) {
    return ImageJsonValidateUtf8(input, output);
}
template<unsigned flags, class Output> void ImageJsonReader::ParseStringToStream(ImageJsonStringStream& stream, Output& output) {
    static const char escape[256] = {
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,'"',0,0,0,0,0,0,0,0,0,0,0,0,'/',
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,'\\',0,0,0,
        0,0,'\b',0,0,0,'\f',0,0,0,0,0,0,0,'\n',0,
        0,0,'\r',0,'\t',0,0,0,0,0,0,0,0,0,0,0
    };
    stream.Take();
    for (;;) {
        char c = stream.Peek();
        if (c == '\\') {
            stream.Take();
            char e = stream.Take();
            if ((sizeof(char) == 1 || static_cast<unsigned>(e) < 256) && escape[static_cast<unsigned char>(e)])
                output.Put(escape[static_cast<unsigned char>(e)]);
            else if (e == 'u') {
                unsigned codepoint = ParseHex4(stream);
                if (codepoint >= 0xd800 && codepoint <= 0xdbff) {
                    if (stream.Take() != '\\' || stream.Take() != 'u')
                        IMAGE_JSON_ERROR("Missing the second \\u in surrogate pair", stream.Tell() - 2);
                    unsigned low = ParseHex4(stream);
                    if (low < 0xdc00 || low > 0xdfff)
                        IMAGE_JSON_ERROR("The second \\u in surrogate pair is invalid", stream.Tell() - 2);
                    codepoint = (((codepoint - 0xd800) << 10) | (low - 0xdc00)) + 0x10000;
                }
                ImageJsonEncodeUtf8(output, codepoint);
            } else IMAGE_JSON_ERROR("Unknown escape character", stream.Tell() - 1);
        } else if (c == '"') {
            stream.Take(); output.Put('\0'); return;
        } else if (c == '\0') IMAGE_JSON_ERROR("lacks ending quotation before the end of string", stream.Tell() - 1);
        else if (static_cast<unsigned>(c) < 0x20) IMAGE_JSON_ERROR("Incorrect unescaped character in string", stream.Tell() - 1);
        else if ((flags & 2) ? !ImageJsonValidateInput(stream, output) : !ImageJsonTranscodeInput(stream, output))
            IMAGE_JSON_ERROR("Invalid encoding", stream.Tell());
    }
}

template<unsigned flags> void ImageJsonReader::ParseString(ImageJsonStringStream& input, ImageJsonDocument& handler) {
    ImageJsonStringStream stream = input;
    if (flags & 1) {
        char* head = stream.PutBegin();
        ParseStringToStream<flags>(stream, stream);
        size_t length = stream.PutEnd(head) - 1;
        handler.String(head, static_cast<unsigned>(length), false);
    } else {
        StackStream output(m_stack);
        ParseStringToStream<flags>(stream, output);
        handler.String(m_stack.Pop<char>(output.length), output.length - 1, true);
    }
    input = stream;
}
template<unsigned flags> void ImageJsonReader::ParseValue(ImageJsonStringStream& stream, ImageJsonDocument& handler) {
    switch (stream.Peek()) {
    case 'n': ParseNull(stream, handler); break;
    case 't': ParseTrue(stream, handler); break;
    case 'f': ParseFalse(stream, handler); break;
    case '"': ParseString<flags>(stream, handler); break;
    case '{': ParseObject<flags>(stream, handler); break;
    case '[': ParseArray<flags>(stream, handler); break;
    default: ParseNumber<flags>(stream, handler);
    }
}

// inferred: decimal power table 0x142d53dc0, exponents -308..308; helper 0x140518ee0.
double ImageJsonReader::Pow10(int n) {
    static const double powers[] = {
        1e-308, 1e-307, 1e-306, 1e-305, 1e-304, 1e-303, 1e-302, 1e-301, 1e-300, 1e-299, 1e-298, 1e-297,
        1e-296, 1e-295, 1e-294, 1e-293, 1e-292, 1e-291, 1e-290, 1e-289, 1e-288, 1e-287, 1e-286, 1e-285,
        1e-284, 1e-283, 1e-282, 1e-281, 1e-280, 1e-279, 1e-278, 1e-277, 1e-276, 1e-275, 1e-274, 1e-273,
        1e-272, 1e-271, 1e-270, 1e-269, 1e-268, 1e-267, 1e-266, 1e-265, 1e-264, 1e-263, 1e-262, 1e-261,
        1e-260, 1e-259, 1e-258, 1e-257, 1e-256, 1e-255, 1e-254, 1e-253, 1e-252, 1e-251, 1e-250, 1e-249,
        1e-248, 1e-247, 1e-246, 1e-245, 1e-244, 1e-243, 1e-242, 1e-241, 1e-240, 1e-239, 1e-238, 1e-237,
        1e-236, 1e-235, 1e-234, 1e-233, 1e-232, 1e-231, 1e-230, 1e-229, 1e-228, 1e-227, 1e-226, 1e-225,
        1e-224, 1e-223, 1e-222, 1e-221, 1e-220, 1e-219, 1e-218, 1e-217, 1e-216, 1e-215, 1e-214, 1e-213,
        1e-212, 1e-211, 1e-210, 1e-209, 1e-208, 1e-207, 1e-206, 1e-205, 1e-204, 1e-203, 1e-202, 1e-201,
        1e-200, 1e-199, 1e-198, 1e-197, 1e-196, 1e-195, 1e-194, 1e-193, 1e-192, 1e-191, 1e-190, 1e-189,
        1e-188, 1e-187, 1e-186, 1e-185, 1e-184, 1e-183, 1e-182, 1e-181, 1e-180, 1e-179, 1e-178, 1e-177,
        1e-176, 1e-175, 1e-174, 1e-173, 1e-172, 1e-171, 1e-170, 1e-169, 1e-168, 1e-167, 1e-166, 1e-165,
        1e-164, 1e-163, 1e-162, 1e-161, 1e-160, 1e-159, 1e-158, 1e-157, 1e-156, 1e-155, 1e-154, 1e-153,
        1e-152, 1e-151, 1e-150, 1e-149, 1e-148, 1e-147, 1e-146, 1e-145, 1e-144, 1e-143, 1e-142, 1e-141,
        1e-140, 1e-139, 1e-138, 1e-137, 1e-136, 1e-135, 1e-134, 1e-133, 1e-132, 1e-131, 1e-130, 1e-129,
        1e-128, 1e-127, 1e-126, 1e-125, 1e-124, 1e-123, 1e-122, 1e-121, 1e-120, 1e-119, 1e-118, 1e-117,
        1e-116, 1e-115, 1e-114, 1e-113, 1e-112, 1e-111, 1e-110, 1e-109, 1e-108, 1e-107, 1e-106, 1e-105,
        1e-104, 1e-103, 1e-102, 1e-101, 1e-100, 1e-99, 1e-98, 1e-97, 1e-96, 1e-95, 1e-94, 1e-93,
        1e-92, 1e-91, 1e-90, 1e-89, 1e-88, 1e-87, 1e-86, 1e-85, 1e-84, 1e-83, 1e-82, 1e-81,
        1e-80, 1e-79, 1e-78, 1e-77, 1e-76, 1e-75, 1e-74, 1e-73, 1e-72, 1e-71, 1e-70, 1e-69,
        1e-68, 1e-67, 1e-66, 1e-65, 1e-64, 1e-63, 1e-62, 1e-61, 1e-60, 1e-59, 1e-58, 1e-57,
        1e-56, 1e-55, 1e-54, 1e-53, 1e-52, 1e-51, 1e-50, 1e-49, 1e-48, 1e-47, 1e-46, 1e-45,
        1e-44, 1e-43, 1e-42, 1e-41, 1e-40, 1e-39, 1e-38, 1e-37, 1e-36, 1e-35, 1e-34, 1e-33,
        1e-32, 1e-31, 1e-30, 1e-29, 1e-28, 1e-27, 1e-26, 1e-25, 1e-24, 1e-23, 1e-22, 1e-21,
        1e-20, 1e-19, 1e-18, 1e-17, 1e-16, 1e-15, 1e-14, 1e-13, 1e-12, 1e-11, 1e-10, 1e-9,
        1e-8, 1e-7, 1e-6, 1e-5, 1e-4, 1e-3, 1e-2, 1e-1, 1e0, 1e1, 1e2, 1e3,
        1e4, 1e5, 1e6, 1e7, 1e8, 1e9, 1e10, 1e11, 1e12, 1e13, 1e14, 1e15,
        1e16, 1e17, 1e18, 1e19, 1e20, 1e21, 1e22, 1e23, 1e24, 1e25, 1e26, 1e27,
        1e28, 1e29, 1e30, 1e31, 1e32, 1e33, 1e34, 1e35, 1e36, 1e37, 1e38, 1e39,
        1e40, 1e41, 1e42, 1e43, 1e44, 1e45, 1e46, 1e47, 1e48, 1e49, 1e50, 1e51,
        1e52, 1e53, 1e54, 1e55, 1e56, 1e57, 1e58, 1e59, 1e60, 1e61, 1e62, 1e63,
        1e64, 1e65, 1e66, 1e67, 1e68, 1e69, 1e70, 1e71, 1e72, 1e73, 1e74, 1e75,
        1e76, 1e77, 1e78, 1e79, 1e80, 1e81, 1e82, 1e83, 1e84, 1e85, 1e86, 1e87,
        1e88, 1e89, 1e90, 1e91, 1e92, 1e93, 1e94, 1e95, 1e96, 1e97, 1e98, 1e99,
        1e100, 1e101, 1e102, 1e103, 1e104, 1e105, 1e106, 1e107, 1e108, 1e109, 1e110, 1e111,
        1e112, 1e113, 1e114, 1e115, 1e116, 1e117, 1e118, 1e119, 1e120, 1e121, 1e122, 1e123,
        1e124, 1e125, 1e126, 1e127, 1e128, 1e129, 1e130, 1e131, 1e132, 1e133, 1e134, 1e135,
        1e136, 1e137, 1e138, 1e139, 1e140, 1e141, 1e142, 1e143, 1e144, 1e145, 1e146, 1e147,
        1e148, 1e149, 1e150, 1e151, 1e152, 1e153, 1e154, 1e155, 1e156, 1e157, 1e158, 1e159,
        1e160, 1e161, 1e162, 1e163, 1e164, 1e165, 1e166, 1e167, 1e168, 1e169, 1e170, 1e171,
        1e172, 1e173, 1e174, 1e175, 1e176, 1e177, 1e178, 1e179, 1e180, 1e181, 1e182, 1e183,
        1e184, 1e185, 1e186, 1e187, 1e188, 1e189, 1e190, 1e191, 1e192, 1e193, 1e194, 1e195,
        1e196, 1e197, 1e198, 1e199, 1e200, 1e201, 1e202, 1e203, 1e204, 1e205, 1e206, 1e207,
        1e208, 1e209, 1e210, 1e211, 1e212, 1e213, 1e214, 1e215, 1e216, 1e217, 1e218, 1e219,
        1e220, 1e221, 1e222, 1e223, 1e224, 1e225, 1e226, 1e227, 1e228, 1e229, 1e230, 1e231,
        1e232, 1e233, 1e234, 1e235, 1e236, 1e237, 1e238, 1e239, 1e240, 1e241, 1e242, 1e243,
        1e244, 1e245, 1e246, 1e247, 1e248, 1e249, 1e250, 1e251, 1e252, 1e253, 1e254, 1e255,
        1e256, 1e257, 1e258, 1e259, 1e260, 1e261, 1e262, 1e263, 1e264, 1e265, 1e266, 1e267,
        1e268, 1e269, 1e270, 1e271, 1e272, 1e273, 1e274, 1e275, 1e276, 1e277, 1e278, 1e279,
        1e280, 1e281, 1e282, 1e283, 1e284, 1e285, 1e286, 1e287, 1e288, 1e289, 1e290, 1e291,
        1e292, 1e293, 1e294, 1e295, 1e296, 1e297, 1e298, 1e299, 1e300, 1e301, 1e302, 1e303,
        1e304, 1e305, 1e306, 1e307, 1e308,
    };
    return n < -308 ? 0.0 : powers[n + 308];
}

template<unsigned flags> void ImageJsonReader::ParseNumber(ImageJsonStringStream& input, ImageJsonDocument& handler) {
    ImageJsonStringStream stream = input;
    bool minus = false;
    if (stream.Peek() == '-') { minus = true; stream.Take(); }
    unsigned i;
    bool use64bit = false;
    if (stream.Peek() == '0') { i = 0; stream.Take(); }
    else if (stream.Peek() >= '1' && stream.Peek() <= '9') {
        i = stream.Take() - '0';
        if (minus) {
            while (stream.Peek() >= '0' && stream.Peek() <= '9') {
                if (i >= 0xccccccc && (i != 0xccccccc || stream.Peek() > '8')) {
                    use64bit = true; break;
                }
                i = i * 10 + (stream.Take() - '0');
            }
        } else {
            while (stream.Peek() >= '0' && stream.Peek() <= '9') {
                if (i >= 0x19999999 && (i != 0x19999999 || stream.Peek() > '5')) {
                    use64bit = true; break;
                }
                i = i * 10 + (stream.Take() - '0');
            }
        }
    } else IMAGE_JSON_ERROR("Expect a value here.", input.Tell());

    unsigned __int64 i64 = 0;
    bool useDouble = false;
    if (use64bit) {
        i64 = i;
        if (minus) {
            while (stream.Peek() >= '0' && stream.Peek() <= '9') {
                if (i64 >= 0xcccccccccccccccULL && (i64 != 0xcccccccccccccccULL || stream.Peek() > '8')) {
                    useDouble = true; break;
                }
                i64 = i64 * 10 + (stream.Take() - '0');
            }
        } else {
            while (stream.Peek() >= '0' && stream.Peek() <= '9') {
                if (i64 >= 0x1999999999999999ULL && (i64 != 0x1999999999999999ULL || stream.Peek() > '5')) {
                    useDouble = true; break;
                }
                i64 = i64 * 10 + (stream.Take() - '0');
            }
        }
    }
    double d = 0.0;
    if (useDouble) {
        d = static_cast<double>(i64);
        while (stream.Peek() >= '0' && stream.Peek() <= '9') {
            if (d >= 1e307) IMAGE_JSON_ERROR("Number too big to store in double", input.Tell());
            d = d * 10 + (stream.Take() - '0');
        }
    }
    int expFrac = 0;
    if (stream.Peek() == '.') {
        if (!useDouble) { d = use64bit ? static_cast<double>(i64) : i; useDouble = true; }
        stream.Take();
        if (stream.Peek() >= '0' && stream.Peek() <= '9') {
            d = d * 10 + (stream.Take() - '0');
            --expFrac;
        } else IMAGE_JSON_ERROR("At least one digit in fraction part", input.Tell());
        while (stream.Peek() >= '0' && stream.Peek() <= '9') {
            if (expFrac > -16) { d = d * 10 + (stream.Peek() - '0'); --expFrac; }
            stream.Take();
        }
    }
    int exp = 0;
    if (stream.Peek() == 'e' || stream.Peek() == 'E') {
        if (!useDouble) { d = use64bit ? static_cast<double>(i64) : i; useDouble = true; }
        stream.Take();
        bool expMinus = false;
        if (stream.Peek() == '+') stream.Take();
        else if (stream.Peek() == '-') { stream.Take(); expMinus = true; }
        if (stream.Peek() >= '0' && stream.Peek() <= '9') {
            exp = stream.Take() - '0';
            while (stream.Peek() >= '0' && stream.Peek() <= '9') {
                exp = exp * 10 + (stream.Take() - '0');
                if (exp > 308) IMAGE_JSON_ERROR("Number too big to store in double", input.Tell());
            }
        } else IMAGE_JSON_ERROR("At least one digit in exponent", stream.Tell());
        if (expMinus) exp = -exp;
    }
    if (useDouble) {
        d *= Pow10(exp + expFrac);
        handler.Double(minus ? -d : d);
    } else if (use64bit) {
        if (minus) handler.Int64(-static_cast<__int64>(i64));
        else handler.Uint64(i64);
    } else if (minus) handler.Int(-static_cast<int>(i));
    else handler.Uint(i);
    input = stream;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9aa50-0x142c9aaa0 .text$yd
