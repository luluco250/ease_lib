#ifndef EASE_LIBRARY_STATIC_LOOP_HEADER
#define EASE_LIBRARY_STATIC_LOOP_HEADER

#include <cstdint>

namespace ease {
	template<size_t N>
	struct StaticRecurse {
		template<class Func>
		inline void operator ()(const Func& func) const {
			func();
			StaticRecurse<N - 1>()(func);
		}
	};

	template<>
	struct StaticRecurse<1> {
		template<class Func>
		inline void operator ()(const Func& func) const {
			func();
		}
	};

	template<size_t... Args> struct StaticLoop;

	template<size_t Begin, size_t End, size_t Step>
	struct StaticLoop<Begin, End, Step> {
		template<class Func>
		inline void operator ()(const Func& func) const {
			if constexpr (Begin < End) {
				func(Begin);
				StaticLoop<Begin + Step, End, Step>()(func);
			}
		}
	};

	template<size_t Begin, size_t End>
	struct StaticLoop<Begin, End> {
		template<class Func>
		inline void operator ()(const Func& func) const {
			if constexpr (Begin < End) {
				func(Begin);
				StaticLoop<Begin + 1, End>()(func);
			}
		}
	};

	template<size_t N>
	struct StaticLoop<N> {
		template<class Func>
		inline void operator ()(const Func& func) const {
			func(0);
			StaticLoop<1, N>()(func);
		}
	};
}

#endif