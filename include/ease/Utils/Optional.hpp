#ifndef EASE_LIBRARY_OPTIONAL_HEADER
#define EASE_LIBRARY_OPTIONAL_HEADER

namespace ease {
	template<class T>
	class Optional {
	public:
		T* _object = nullptr;

		const T& operator =(const T* p) {
			_object = p;
		}

		const T* operator ->() {
			return _object;
		}
	};
}

#endif