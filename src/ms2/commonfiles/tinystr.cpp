// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). TinyXML's tinystr.cpp (TiXmlString out-of-line members),
// the first of the objects the unit map merged into commonfiles\tinyxmlhelper.cpp (tinystr, tinyxml, tinyxmlhelper,
// tinyxmlparser, titletable link in name order). Text from the local TinyXML 2.5.3 sources.
// MS2-UNIT: commonfiles\tinyxmlhelper.cpp#1
// MS2-RANGE: 0x14086d350-0x14086d9b0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinystr.cpp"
#include "tinystr.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Error value for find primitive
const TiXmlString::size_type TiXmlString::npos = static_cast< TiXmlString::size_type >(-1);

// Null rep. The hook DLL must share the exe's (0x143ab1fb0): quit() compares rep_ against it.
#ifndef MS2_HOOK_DLL
TiXmlString::Rep TiXmlString::nullrep_ = { 0, 0, { '\0' } };
#endif

// @0x14086d350
void TiXmlString::reserve (size_type cap)
{
	if (cap > capacity())
	{
		TiXmlString tmp;
		tmp.init(length(), cap);
		memcpy(tmp.start(), data(), length());
		swap(tmp);
	}
}
MS2_REPLACE_METHOD(0x14086d350, TiXmlString, reserve, 175, 0xB96E3D63);

// @0x14086d410
TiXmlString& TiXmlString::assign(const char* str, size_type len)
{
	size_type cap = capacity();
	if (len > cap || cap > 3*(len + 8))
	{
		TiXmlString tmp;
		tmp.init(len);
		memcpy(tmp.start(), str, len);
		swap(tmp);
	}
	else
	{
		memmove(start(), str, len);
		set_size(len);
	}
	return *this;
}
MS2_REPLACE_METHOD(0x14086d410, TiXmlString, assign, 211, 0xC5015544);

// @0x14086d4f0
TiXmlString& TiXmlString::append(const char* str, size_type len)
{
	size_type newsize = length() + len;
	if (newsize > capacity())
	{
		reserve (newsize + capacity());
	}
	memmove(finish(), str, len);
	set_size(newsize);
	return *this;
}
MS2_REPLACE_METHOD(0x14086d4f0, TiXmlString, append, 143, 0x2B298C79);

// @0x14086d590
TiXmlString operator + (const TiXmlString & a, const TiXmlString & b)
{
	TiXmlString tmp;
	tmp.reserve(a.length() + b.length());
	tmp += a;
	tmp += b;
	return tmp;
}

// @0x14086d650
TiXmlString operator + (const TiXmlString & a, const char* b)
{
	TiXmlString tmp;
	TiXmlString::size_type b_len = static_cast<TiXmlString::size_type>( strlen(b) );
	tmp.reserve(a.length() + b_len);
	tmp += a;
	tmp.append(b, b_len);
	return tmp;
}

// @0x14086d730
TiXmlString operator + (const char* a, const TiXmlString & b)
{
	TiXmlString tmp;
	TiXmlString::size_type a_len = static_cast<TiXmlString::size_type>( strlen(a) );
	tmp.reserve(a_len + b.length());
	tmp.append(a, a_len);
	tmp += b;
	return tmp;
}
MS2_REPLACE_OVERLOAD(0x14086d590, TiXmlString(const TiXmlString&, const TiXmlString&), operator+, 172, 0xA50F5A29);
MS2_REPLACE_OVERLOAD(0x14086d650, TiXmlString(const TiXmlString&, const char*), operator+, 206, 0x67952575);
MS2_REPLACE_OVERLOAD(0x14086d730, TiXmlString(const char*, const TiXmlString&), operator+, 212, 0xE7A4ECD8);
