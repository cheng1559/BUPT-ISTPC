#ifndef __decimal_hh__
#define __decimal_hh__
#include <algorithm>
#include <string>
#include <vector>

// CaveNightingale's Decimal number library. Used for checkers and validators.
namespace cave {
// Actually, this class only need to implement addition and multiplication.
class DecimalInt {
	// The sign of the number.
	bool neg;
	// The digits of the number. 4 digits per element.
	std::vector<int> a;
	std::vector<int> strip(std::vector<int> &&a) const {
		while (!a.empty() && !a.back()) {
			a.pop_back();
		}
		return a;
	}
	std::vector<int> add_abs(const std::vector<int> &lhs, const std::vector<int> &rhs) const {
		std::vector<int> ret(std::max(lhs.size(), rhs.size()) + 1);
		int carry = 0;
		for (int i = 0; i < (int)ret.size(); i++) {
			int t = carry;
			if (i < (int)lhs.size()) {
				t += lhs[i];
			}
			if (i < (int)rhs.size()) {
				t += rhs[i];
			}
			ret[i] = t % 10000;
			carry = t / 10000;
		}
		return strip(std::move(ret));
	}
	std::vector<int> sub_abs(const std::vector<int> &lhs, const std::vector<int> &rhs) const {
		std::vector<int> ret(lhs.size());
		int carry = 0;
		for (int i = 0; i < (int)ret.size(); i++) {
			int t = carry + lhs[i];
			if (i < (int)rhs.size()) {
				t -= rhs[i];
			}
			if (t < 0) {
				t += 10000;
				carry = -1;
			} else {
				carry = 0;
			}
			ret[i] = t;
		}
		return strip(std::move(ret));
	}
	int compare_abs(const std::vector<int> &lhs, const std::vector<int> &rhs) const {
		if (lhs.size() != rhs.size()) {
			return lhs.size() > rhs.size() ? 1 : -1;
		}
		for (int i = lhs.size() - 1; i >= 0; --i) {
			if (lhs[i] != rhs[i]) {
				return lhs[i] > rhs[i] ? 1 : -1;
			}
		}
		return 0;
	}
	std::vector<int> mul_abs(const std::vector<int> &lhs, const std::vector<int> &rhs) const {
		std::vector<int> ret(lhs.size() + rhs.size() + 1);
		for (int i = 0; i < (int)lhs.size(); i++) {
			for (int j = 0; j < (int)rhs.size(); j++) {
				int t = lhs[i] * rhs[j];
				ret[i + j] += t % 10000;
				ret[i + j + 1] += t / 10000;
			}
		}
		int carry = 0;
		for (int i = 0; i < (int)ret.size(); i++) {
			int t = ret[i] + carry;
			ret[i] = t % 10000;
			carry = t / 10000;
		}
		return strip(std::move(ret));
	}
	int compare_to(const DecimalInt &rhs) const {
		if (neg != rhs.neg) {
			return neg ? -1 : 1;
		}
		if (neg) {
			return -compare_abs(a, rhs.a);
		} else {
			return compare_abs(a, rhs.a);
		}
	}
	DecimalInt add(const DecimalInt &rhs) const {
		if (neg != rhs.neg) {
			int cmp = compare_abs(a, rhs.a);
			bool neg = cmp < 0 ? rhs.neg : this->neg;
			if (cmp < 0) {
				return DecimalInt(sub_abs(rhs.a, a), neg);
			} else {
				return DecimalInt(sub_abs(a, rhs.a), neg);
			}
		}
		return DecimalInt(add_abs(a, rhs.a), neg);
	}
	DecimalInt mul(const DecimalInt &rhs) const { return DecimalInt(mul_abs(a, rhs.a), neg ^ rhs.neg); }

  public:
	DecimalInt() : neg(false) {}
	DecimalInt(std::vector<int> a, bool neg) : neg(neg), a(a) {}
	DecimalInt(const std::string &s) {
		neg = false;
		int i = 0;
		if (s[0] == '-') {
			neg = true;
			i++;
		}
		for (int i = (int)s.size() - 1; i >= (int)neg; i -= 4) {
			int t = 0;
			for (int j = std::max((int)neg, i - 3); j <= i; j++) {
				t = t * 10 + s[j] - '0';
			}
			a.push_back(t);
		}
		while (!a.empty() && !a.back()) {
			a.pop_back();
		}
		if (a.empty()) {
			neg = false;
		}
	}

	DecimalInt operator+(const DecimalInt &rhs) const { return add(rhs); }
	DecimalInt operator-(const DecimalInt &rhs) const { return add(DecimalInt(rhs.a, !rhs.neg)); }
	DecimalInt operator*(const DecimalInt &rhs) const { return mul(rhs); }
	bool operator<(const DecimalInt &rhs) const { return compare_to(rhs) < 0; }
	bool operator>(const DecimalInt &rhs) const { return compare_to(rhs) > 0; }
	bool operator==(const DecimalInt &rhs) const { return compare_to(rhs) == 0; }
	bool operator!=(const DecimalInt &rhs) const { return compare_to(rhs) != 0; }
	bool operator<=(const DecimalInt &rhs) const { return compare_to(rhs) <= 0; }
	bool operator>=(const DecimalInt &rhs) const { return compare_to(rhs) >= 0; }
	DecimalInt rounded_shift_right(int ele) {
		if (ele > (int)a.size()) {
			return DecimalInt(std::vector<int>(0), false);
		}
		std::vector<int> rem(a.begin(), a.begin() + ele), zero_point_five(ele);
		zero_point_five[ele - 1] = 5000;
		DecimalInt ret(std::vector<int>(a.begin() + ele, a.end()), false);
		int cmp = compare_abs(rem, zero_point_five);
		if (cmp > 0 || (cmp == 0 && (a[ele] & 1))) {
			ret = ret + DecimalInt(std::vector<int>(1, 1), false);
		}
		ret.neg = neg;
		return ret;
	}
	DecimalInt ten_thousand_power(int ele) const {
		std::vector<int> ret(a.size() + ele);
		for (int i = 0; i < (int)a.size(); i++) {
			ret[i + ele] = a[i];
		}
		return DecimalInt(ret, neg);
	}
	DecimalInt abs() const { return DecimalInt(a, false); }
	std::string to_string() const {
		std::string ret;
		for (int i = 0; i < (int)a.size(); i++) {
			std::string t = std::to_string(a[i]);
			std::reverse(t.begin(), t.end());
			ret += t + std::string(4 - t.size(), '0');
		}
		while (ret.size() != 1 && ret.back() == '0') {
			ret.pop_back();
		}
		if (neg) {
			ret += '-';
		}
		std::reverse(ret.begin(), ret.end());
		return ret;
	}
	DecimalInt divide_by_two() const {
		std::vector<int> ret(a.size());
		int carry = 0;
		for (int i = a.size() - 1; i >= 0; i--) {
			int t = a[i] + carry * 10000;
			ret[i] = t / 2;
			carry = t & 1;
		}
		if (carry && (ret[0] & 1)) {
			ret = add_abs(ret, std::vector<int>(1, 1));
		}
		return DecimalInt(strip(std::move(ret)), neg);
	}
};

// Fixed point decimal.
class DecimalFixed {
  private:
	static constexpr int DIGITS = 80;
	DecimalInt a;
	DecimalInt round(DecimalInt x) const {
		return x.rounded_shift_right(DIGITS / 4);
	}

  public:
	DecimalFixed() {}
	DecimalFixed(int x) : DecimalFixed(std::to_string(x)) {}
	DecimalFixed(std::string s) {
		if (s.find('.') == std::string::npos) {
			s += '.';
		}
		int digit = s.end() - std::find(s.begin(), s.end(), '.') - 1;
		s.erase(std::find(s.begin(), s.end(), '.'));
		bool add_one = false;
		if (digit > DIGITS) {
			std::string rem = s.substr(s.size() - digit + DIGITS);
			s = s.substr(0, s.size() - digit + DIGITS);
			if (rem[0] > '5') {
				add_one = true;
			} else if (rem[0] == '5') {
				for (int i = 1; i < (int)rem.size(); i++) {
					if (rem[i] != '0') {
						add_one = true;
						break;
					}
				}
				add_one = add_one || (s.back() - '0') & 1;
			}
			digit = DIGITS;
		}
		s += std::string(DIGITS - digit, '0');
		a = DecimalInt(s);
		if (add_one) {
			a = a + DecimalInt(std::vector<int>(1, 1), false);
		}
	}
	DecimalFixed(DecimalInt a) : a(a) {}
	DecimalFixed operator+(const DecimalFixed &rhs) const { return DecimalFixed(a + rhs.a); }
	DecimalFixed operator-(const DecimalFixed &rhs) const { return DecimalFixed(a - rhs.a); }
	DecimalFixed operator*(const DecimalFixed &rhs) const { return DecimalFixed(round(a * rhs.a)); }
	bool operator<(const DecimalFixed &rhs) const { return a < rhs.a; }
	bool operator>(const DecimalFixed &rhs) const { return a > rhs.a; }
	bool operator==(const DecimalFixed &rhs) const { return a == rhs.a; }
	bool operator!=(const DecimalFixed &rhs) const { return a != rhs.a; }
	bool operator<=(const DecimalFixed &rhs) const { return a <= rhs.a; }
	bool operator>=(const DecimalFixed &rhs) const { return a >= rhs.a; }
	DecimalFixed abs() const { return DecimalFixed(a.abs()); }
	DecimalFixed ten_thousand_power(int ele) const { return DecimalFixed(a.ten_thousand_power(ele)); }
	std::string to_string() const {
		std::string ret = a.to_string();
		if (ret.size() <= DIGITS) {
			ret = std::string(DIGITS - ret.size() + 1, '0') + ret;
		}
		ret.insert(ret.end() - DIGITS, '.');
		while (ret.back() == '0') {
			ret.pop_back();
		}
		if (ret.back() == '.') {
			ret.pop_back();
		}
		return ret;
	}
	DecimalFixed divide_by_two() const { return DecimalFixed(a.divide_by_two()); }
};
} // namespace cave

#endif