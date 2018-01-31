#ifndef EASE_LIBRARY_RANGED_HEADER
#define EASE_LIBRARY_RANGED_HEADER

#include <stdexcept>

namespace ease {
	template<class T, T Min, T Max>
	class Ranged {
	public:
		T _value;

		inline virtual void _assign(T arg) {
			_value = arg > Max ? Max : arg < Min ? Min : arg;
		}

		Ranged() { _assign(T()); }
		Ranged(T arg) { _assign(arg); }
		Ranged(const Ranged& other) : _value(other._value) {}

		inline operator T() const { return _value; }

		inline Ranged& operator =(T arg) {
			_assign(arg);
			return *this;
		}
		inline Ranged& operator +=(T arg) {
			_assign(_value + arg);
			return *this;
		}
		inline Ranged& operator -=(T arg) {
			_assign(_value - arg);
			return *this;
		}
		inline Ranged& operator *=(T arg) {
			_assign(_value * arg);
			return *this;
		}
		inline Ranged& operator /=(T arg) {
			_assign(_value / arg);
			return *this;
		}
		inline Ranged& operator %=(T arg) {
			_assign(_value % arg);
			return *this;
		}
		inline Ranged& operator &=(T arg) {
			_assign(_value & arg);
			return *this;
		}
		inline Ranged& operator |=(T arg) {
			_assign(_value | arg);
			return *this;
		}
		inline Ranged& operator ^=(T arg) {
			_assign(_value ^ arg);
			return *this;
		}
		inline Ranged& operator <<=(T arg) {
			_assign(_value << arg);
			return *this;
		}
		inline Ranged& operator >>=(T arg) {
			_assign(_value >> arg);
			return *this;
		}
		inline Ranged& operator ++() {
			_assign(++_value);
			return *this;
		}
		inline Ranged& operator --() {
			_assign(--_value);
			return *this;
		}
		inline Ranged operator ++(int) {
			Ranged original = *this;
			_assign(++_value);
			return original;
		}
		inline Ranged operator --(int) {
			Ranged original = *this;
			_assign(--_value);
			return original;
		}
	};

	template<class T, T Min, T Max>
	class HardRanged : public Ranged<T, Min, Max> {
	public:
		inline virtual void _assign(T arg) {
			if (arg < Min || arg > Max)
				throw std::out_of_range("Value outside of range.");
			else
				this->_value = arg;
		}
		
		HardRanged() { _assign(T()); }
		HardRanged(T arg) { _assign(arg); }
		HardRanged(const HardRanged& other) : _value(other._value) {}
		HardRanged(const Ranged<T, Min, Max>& other) : _value(other._value) {}

		inline operator Ranged<T, Min, Max>() const {
			return Ranged<T, Min, Max>{this->_value};
		}
	};
}

#endif