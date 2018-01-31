#ifndef EASE_MATH_COMMON_HEADER
#define EASE_MATH_COMMON_HEADER

#include <cmath>
#include <algorithm>

namespace ease {
	/*template<class T>
	inline auto sqrt(T x) {
		print("Calling ease::sqrt");
		return std::sqrt(x);
	}

	template<class Tx, class Te>
	inline auto pow(Tx x, Te e) {
		return std::pow(x, e);
	}

	template<class T>
	inline auto min(T a, T b) {
		return std::min(a, b);
	}*/

	template<class Tx, class Tm>
	inline Tx clamp(Tx x, Tm min, Tm max) {
		return x < min ? min : x > max ? max : x;
	}

	template<class T>
	inline T saturate(T x) {
		return clamp(x, T(0), T(1));
	}
}

#endif