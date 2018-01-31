#ifndef EASE_LIBRARY_PRINT_HEADER
#define EASE_LIBRARY_PRINT_HEADER

#include <iostream>

namespace ease {
	template<char End = '\n', char Sep = ' ', class T>
	inline void print(const T& arg) {
		std::cout << arg;
		if constexpr (End != 0)
			std::cout << End;
	}

	template<char End = '\n', char Sep = ' ', class T, class... Args>
	inline void print(const T& arg, const Args&... others) {
		std::cout << arg;
		if constexpr (Sep != 0)
			std::cout << Sep;
		print<End, Sep>(others...);
	}
}

#endif