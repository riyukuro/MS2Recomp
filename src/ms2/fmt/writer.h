// fmt/writer.h - RECREATED BasicWriter / Array (cppformat 1.x era) as the game links them for wchar_t. NOT original.
// Layout proven from 0x1401d0c40 (fmt::format for wide strings): the writer is the 0x400-byte inline Array<wchar_t, 500>
// {size_ 0, capacity_ 8, ptr_ 0x10, data_ 0x18}. Instances: Array() 0x1401cfc20, BasicWriter() 0x1401cfcc0,
// ~Array 0x1401d0d20, write() 0x1401d0ea0, size() 0x1401d0e20, str() 0x1401d0e30, format() 0x1401d0c40.
#pragma once
#include <memory>
#include <string>
#include "ms2/fmt/format.h"

namespace fmt {
namespace internal {

template <typename T, std::size_t SIZE, typename Allocator = std::allocator<T> >
class Array : private Allocator
{
public:
    explicit Array(const Allocator& alloc = Allocator()) : Allocator(alloc), size_(0), capacity_(SIZE), ptr_(data_) {}
    ~Array() { Free(); }
    std::size_t size() const { return size_; }
    T& operator[](std::size_t index) const { return ptr_[index]; }

private:
    void Free() { if (ptr_ != data_) Allocator::deallocate(ptr_, capacity_); }

    std::size_t size_;
    std::size_t capacity_;
    T* ptr_;
    T data_[SIZE];
};

enum { INLINE_BUFFER_SIZE = 500 };

}  // namespace internal

template <typename Char, typename Allocator>
class BasicWriter
{
public:
    explicit BasicWriter(const Allocator& alloc = Allocator()) : buffer_(alloc) {}
    std::size_t size() const { return buffer_.size(); }
    std::basic_string<Char> str() const { return std::basic_string<Char>(&buffer_[0], buffer_.size()); }
    void write(BasicStringRef<Char> format, ArgList args) { BasicFormatter<Char>(*this).format(format, args); }

private:
    internal::Array<Char, internal::INLINE_BUFFER_SIZE, Allocator> buffer_;
};

typedef BasicWriter<char, std::allocator<char> > Writer;
typedef BasicWriter<wchar_t, std::allocator<wchar_t> > WWriter;

std::wstring format(WStringRef format, ArgList args);

}  // namespace fmt
