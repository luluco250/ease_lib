#ifndef EASE_LIBRARY_INPUT_HEADER
#define EASE_LIBRARY_INPUT_HEADER

#include <iostream>
#include "../Text/String.hpp"

namespace ease {
	inline String get_input() {
		String text;
		getline(std::cin, text);
		return text;
	}
}

#endif