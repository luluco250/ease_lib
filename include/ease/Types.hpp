#ifndef EASE_LIBRARY_TYPES_HEADER
#define EASE_LIBRARY_TYPES_HEADER

#include <cstdint>

namespace ease {
	// Shorthands for native types
	using llong   = long long;
	using uchar   = unsigned char;
	using ushort  = unsigned short;
	using uint    = unsigned int;
	using ulong   = unsigned long;
	using ullong  = unsigned long long;
	using ldouble = long double;

	using I8  = int8_t;
	using I16 = int16_t;
	using I32 = int32_t;
	using I64 = int64_t;
	
	using U8  = uint8_t;
	using U16 = uint16_t;
	using U32 = uint32_t;
	using U64 = uint64_t;

	using Byte  = U8;
	using Word  = U16;
	using Dword = U32;
	using Qword = U64;

	using Size = std::size_t;
}

#endif