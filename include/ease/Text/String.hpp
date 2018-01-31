#ifndef EASE_LIBRARY_STRING_HEADER
#define EASE_LIBRARY_STRING_HEADER

#include <string>

namespace ease {
	template<class T>
	class BasicString;

	template<class T>
	bool char_equals(T c, const T* s) {
		for (T* p = const_cast<T*>(s); *p != 0; ++p)
			if (c == *p)
				return true;
		return false;
	}

	template<class T>
	bool char_equals(T c, const BasicString<T>& s) {
		if (s.empty())
			return false;
		else
			return char_equals(c, s.data());
	}

	template<class T>
	class BasicString : public std::basic_string<T> {
	public:
		using StrType = std::basic_string<T>;
		using SizeType = typename StrType::size_type;

		// Inherit std::basic_string constructors.
		using StrType::StrType;

		/**
		 * Equivalent to what isspace looks for.
		 */
		static constexpr const char* whitespace = " \t\n\v\f\r";

		/**
		 * Construct BasicString from a std::basic_string.
		 */
		BasicString(const StrType& str) : StrType(str) {}

		/**
		 * Returns a copy of this string with
		 * leading whitespace removed.
		 */
		BasicString ltrim(
			const BasicString& whitespace = BasicString::whitespace
		) const {
			return StrType::substr(find_first_not_of(whitespace), StrType::length() - 1);
		}

		/**
		 * Returns a copy of this string with
		 * trailing whitespace removed.
		 */
		BasicString rtrim(
			const BasicString& whitespace = BasicString::whitespace
		) const {
			return StrType::substr(0, find_last_not_of(whitespace));
		}

		/**
		 * Returns a copy of this string with both
		 * leading and trailing whitespace removed.
		 */
		BasicString trim(
			const BasicString& whitespace = BasicString::whitespace
		) const {
			SizeType first = StrType::find_first_not_of(whitespace);
			if (first == StrType::npos)
				return *this;

			SizeType last = StrType::find_last_not_of(whitespace);
			return StrType::substr(first, last - first + 1);
		}

		/**
		 * Returns a copy of this string with
		 * all whitespace replaced with the
		 * specified replacement string.
		 */
		BasicString reduce(
			const BasicString& whitespace = " \t",
			const BasicString& replacement = BasicString(1, ' ')
		) const {
			BasicString result = *this;
			SizeType end = result.length();

			for (SizeType start = 0; start < end; ++start) {
				if (char_equals(result[start], whitespace)) {
					SizeType pos = start;

					while (pos < end && char_equals(result[pos], whitespace))
						++pos;
					
					if (start != pos) {
						BasicString reduced = result.replace(start, pos - start, replacement);
						result = reduced;
						end -= pos - start - 1;
					}
				}
			}

			return result;
		}

		/**
		 * Returns a copy of this string after
		 * trim() and reduce().
		 */
		BasicString trim_reduce(
			const BasicString& whitespace = " \t",
			const BasicString& replacement = BasicString(1, ' ')
		) const {
			auto trimmed = trim();
			auto reduced = trimmed.reduce();
			return reduced;
		}
	};

	class String : public BasicString<char> {
	public:
		using BasicString<char>::BasicString;
	};

	class WString : public BasicString<wchar_t> {
	public:
		using BasicString<wchar_t>::BasicString;
	};
}

#endif