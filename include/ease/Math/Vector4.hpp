#ifndef EASE_LIBRARY_VECTOR4_HEADER
#define EASE_LIBRARY_VECTOR4_HEADER

#include "../Types.hpp"
#include "Common.hpp"

namespace ease {
	template<class T>
	class Vector4 {
	public:
		T x, y, z, w;

		Vector4() :
		x(T()), y(T()), z(T()), w(T()) {}

		Vector4(T arg) :
		x(arg), y(arg), z(arg), w(arg) {}

		Vector4(T x, T y, T z, T w) :
		x(x), y(y), z(z), w(w) {}

		template<class To>
		Vector4(const Vector4<To>& other) :
		x(other.x), y(other.y), z(other.z), w(other.w) {}

		template<class Ti = size_t>
		inline T& operator [](Ti i) {
			return (&x)[i];
		}
		template<class Ti = size_t>
		inline const T& operator [](Ti i) const {
			return (&x)[i];
		}
		inline T* begin() {
			return &x;
		};
		inline T* end() {
			return &(begin()[4]);
		};
		inline const T* cbegin() const {
			return &x;
		};
		inline const T* cend() const {
			return &(cbegin()[4]);
		};

		inline auto lengthsqr() const {
			return dot(*this, *this);
		}
		inline auto length() const {
			return std::sqrt(lengthsqr());
		}
		inline auto magnitude() const {
			return length();
		}
		inline Vector4 normalized() const {
			return *this / length();
		}

		template<class To>
		inline bool operator ==(const Vector4<To>& other) const {
			return x == other.x && y == other.y && z == other.z && w == other.w;
		}
		template<class To>
		inline bool operator <(const Vector4<To>& other) const {
			return lengthsqr() < other.lengthsqr();
		}
		template<class To>
		inline bool operator >(const Vector4<To>& other) const {
			return lengthsqr() > other.lengthsqr();
		}
		template<class To>
		inline bool operator <=(const Vector4<To>& other) const {
			return lengthsqr() <= other.lengthsqr();
		}
		template<class To>
		inline bool operator >=(const Vector4<To>& other) const {
			return lengthsqr() >= other.lengthsqr();
		}

		inline Vector4& operator ++() {
			++x; ++y; ++z; ++w;
			return *this;
		}
		inline Vector4& operator --() {
			--x; --y; --z; --w;
			return *this;
		}
		inline Vector4 operator ++(int) {
			Vector4 original(*this);
			++x; ++y; ++z; ++w;
			return original;
		}
		inline Vector4 operator --(int) {
			Vector4 original(*this);
			--x; --y; --z; --w;
			return original;
		}

		#define _EASE_LIBRARY_VECTOR4_ASSIGN_OP(OP) \
		template<class To> \
		inline Vector4& operator OP(const To& arg) { \
			x OP arg; \
			y OP arg; \
			z OP arg; \
			w OP arg; \
			return *this; \
		} \
		template<class To> \
		inline Vector4<T>& operator OP(const Vector4<To>& other) { \
			x OP other.x; \
			y OP other.y; \
			z OP other.z; \
			w OP other.w; \
			return *this; \
		}

		#define _EASE_LIBRARY_VECTOR4_OPERATOR(OP) \
		template<class To> \
		inline Vector4<T> operator OP(To arg) const { \
			return { x OP arg, y OP arg, z OP arg, w OP arg }; \
		} \
		template<class To> \
		inline Vector4<T> operator OP(const Vector4<To>& other) const { \
			return { x OP other.x, y OP other.y, z OP other.z, w OP other.w };\
		}

		_EASE_LIBRARY_VECTOR4_ASSIGN_OP(=)
		_EASE_LIBRARY_VECTOR4_ASSIGN_OP(+=)
		_EASE_LIBRARY_VECTOR4_ASSIGN_OP(-=)
		_EASE_LIBRARY_VECTOR4_ASSIGN_OP(*=)
		_EASE_LIBRARY_VECTOR4_ASSIGN_OP(/=)
		_EASE_LIBRARY_VECTOR4_ASSIGN_OP(%=)
		_EASE_LIBRARY_VECTOR4_ASSIGN_OP(&=)
		_EASE_LIBRARY_VECTOR4_ASSIGN_OP(|=)
		_EASE_LIBRARY_VECTOR4_ASSIGN_OP(^=)
		_EASE_LIBRARY_VECTOR4_ASSIGN_OP(<<=)
		_EASE_LIBRARY_VECTOR4_ASSIGN_OP(>>=)

		_EASE_LIBRARY_VECTOR4_OPERATOR(+)
		_EASE_LIBRARY_VECTOR4_OPERATOR(-)
		_EASE_LIBRARY_VECTOR4_OPERATOR(*)
		_EASE_LIBRARY_VECTOR4_OPERATOR(/)
		_EASE_LIBRARY_VECTOR4_OPERATOR(%)
		_EASE_LIBRARY_VECTOR4_OPERATOR(&)
		_EASE_LIBRARY_VECTOR4_OPERATOR(|)
		_EASE_LIBRARY_VECTOR4_OPERATOR(^)
		_EASE_LIBRARY_VECTOR4_OPERATOR(<<)
		_EASE_LIBRARY_VECTOR4_OPERATOR(>>)

		#undef _EASE_LIBRARY_VECTOR4_ASSIGN_OP
		#undef _EASE_LIBRARY_VECTOR4_OPERATOR
	};

	template<class T>
	inline auto dot(const Vector4<T>& a, const Vector4<T>& b) {
		return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
	}

	template<class T>
	inline auto distance(const Vector4<T>& a, const Vector4<T>& b) {
		return magnitude(a - b);
	}

	template<class T>
	inline Vector4<T> clamp(
		const Vector4<T>& vec,
		T min, T max
	) {
		return {
			clamp(vec.x, min, max),
			clamp(vec.y, min, max),
			clamp(vec.z, min, max),
			clamp(vec.w, min, max)
		};
	}

	template<class T>
	inline Vector4<T> saturate(const Vector4<T>& vec) {
		return clamp(vec, T(0), T(1));
	}
}

#endif