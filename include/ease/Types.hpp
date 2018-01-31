#ifndef EASE_LIBRARY_TYPES_HEADER
#define EASE_LIBRARY_TYPES_HEADER

#include <cstdint>

namespace ease {
	using SChar  = signed char;
	using SShort = signed short;
	using SInt   = signed int;
	using SLong  = signed long;
	using SLLong = signed long long;

	using UChar  = unsigned char;
	using UShort = unsigned short;
	using UInt   = unsigned int;
	using ULong  = unsigned long;
	using ULLong = unsigned long long;

	using Float   = float;
	using Double  = double;
	using LDouble = long double;

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

	using Size = size_t;
}

#endif