#ifndef EASE_IO_STREAMOVERLOADS_HEADER
#define EASE_IO_STREAMOVERLOADS_HEADER

#include <iostream>
#include "../Math/Vectors.hpp"

namespace ease {
	template<class T>
	inline std::ostream& operator <<(std::ostream& stream, const Vector4<T>& v) {
		return stream << '(' << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ')';
	}
}

#endif