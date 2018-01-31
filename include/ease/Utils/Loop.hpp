#ifndef EASE_LIBRARY_LOOP_HEADER
#define EASE_LIBRARY_LOOP_HEADER

#include <type_traits>

namespace ease {
	template<class T, T... Args> struct basic_loop;

	template<class T, T Begin, T End, T Step>
	struct basic_loop<T, Begin, End, Step> {
		struct iterator {
			T i;

			inline T operator *() const {
				return i;
			}

			inline bool operator !=(iterator other) const {
				if constexpr (Begin < End)
					return i < other.i;
				else
					return i > other.i;
			}

			inline void operator ++() {
				i += Step;
			}
		};

		inline iterator begin() {
			return iterator{Begin};
		}
		inline iterator end() {
			return iterator{End};
		}
	};

	template<class T, T Begin, T End>
	struct basic_loop<T, Begin, End> :
	public basic_loop<T, Begin, End, 1> {};

	template<class T, T Count>
	struct basic_loop<T, Count> :
	public basic_loop<T, 0, Count, 1> {};

	template<class T>
	struct basic_loop<T> {
		const T _begin, _end, _step;

		struct iterator {
			const basic_loop& parent;
			T i;

			inline T operator *() const {
				return i;
			}

			inline bool operator !=(const iterator& other) const {
				return (parent._begin < parent._end) ? i < other.i : i > other.i;
			}

			inline void operator ++() {
				i += parent._step;
			}
		};

		basic_loop(T begin, T end, T step = 1) :
		_begin(begin), _end(end), _step(step) {}

		basic_loop(T count) :
		_begin(0), _end(count), _step(1) {}

		inline iterator begin() {
			return iterator{*this, _begin};
		}
		inline iterator end() {
			return iterator{*this, _end};
		}
	};

	/*template<int... Args> struct loop;

	template<int First, int... Args>
	struct loop<First, Args...> :
	public basic_loop<int, First, Args...> {};

	template<>
	struct loop<> : public basic_loop<int> {
		loop(int _begin, int _end, int _step) {}
	};*/

	template<int... Args>
	struct loop : public basic_loop<int, Args...> {};

	template<unsigned... Args>
	struct uloop : public basic_loop<unsigned, Args...> {};
	template<long... Args>
	struct lloop : public basic_loop<long, Args...> {};
	template<unsigned long... Args>
	struct ulloop : public basic_loop<unsigned long, Args...> {};
	template<long long... Args>
	struct llloop : public basic_loop<long long, Args...> {};
	template<unsigned long long... Args>
	struct ullloop : public basic_loop<unsigned long long, Args...> {};
}

#endif