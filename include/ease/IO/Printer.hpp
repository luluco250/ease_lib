#ifndef EASE_LIBRARY_PRINTER_HEADER
#define EASE_LIBRARY_PRINTER_HEADER

namespace ease {
	template<class Stream>
	struct Printer {
		Stream& stream;

		Printer(Stream& stream) : stream(stream) {}

		template<char End = '\n', char Sep = ' ', class T>
		inline void print(const T& arg) {
			stream << arg;
			if constexpr (End != 0)
				stream << End;
		}
		template<char End = '\n', char Sep = ' ', class T, class... Args>
		inline void print(const T& arg, const Args&... others) {
			stream << arg;
			if constexpr (Sep != 0)
				stream << Sep;
			print(others...);
		}

		template<size_t InitSize = 1024, class... Args>
		void printf(const char* format, const Args&... args) {
			std::vector<char> buffer(InitSize);

			while (true) {
				int written = std::snprintf(buffer.data(), buffer.size(), format, args...);

				if (written <= buffer.size() && written >= 0) {
					stream << buffer.data();
					return;
				}
				
				buffer.resize((written > 0) ? written + 1 : buffer.size() * 2);
			}
		}
	};

	template<class Stream>
	inline Printer<Stream> make_printer(Stream& stream) {
		return Printer<Stream>(stream);
	}
}

#endif