#include "testlib.h"
#include "decimal.hh"
#include <assert.h>
#include <functional>
#include <string>
#include <vector>
#include <regex>

static std::regex decimalFixedRegex("[-]?[0-9]+(\\.[0-9]+)?");

static inline cave::DecimalFixed readDecimalFixed(InStream &inf) {
	std::string s = inf.readToken();
	if (!std::regex_match(s, decimalFixedRegex)) {
		inf.quitf(_wa, "Invalid decimal fixed: %s", s.c_str());
	}
	cave::DecimalFixed ret = cave::DecimalFixed(s);
	return ret;
}

static inline std::string to_string(cave::DecimalFixed x) {
	return x.to_string();
}

class Polynomial {
  private:
	std::vector<cave::DecimalFixed> a;

  public:
	Polynomial() {}
	Polynomial(std::vector<cave::DecimalFixed> a) : a(a) {}

	cave::DecimalFixed operator()(cave::DecimalFixed x) const {
		cave::DecimalFixed ret;
		for (int i = (int)a.size() - 1; i >= 0; i--) {
			ret = ret * x + a[i];
		}
		return ret;
	}
};

class Test {
  private:
	Polynomial f;
	cave::DecimalFixed k;
	cave::DecimalFixed t; // The answer

  public:
	Test(Polynomial f, cave::DecimalFixed k) : f(f), k(k) {
		cave::DecimalFixed l = 0, r = 100;
		cave::DecimalFixed fl = f(l), fr = f(r);
		if (testlibMode == _validator) { // Run validation only in validator
			quitif(fl > fr, _fail, "f(0) > f(100)");
			quitif(!(fl >= 0 && fl < k), _fail, "f(0) is not in [0, k)");
			quitif(!(fr <= 1000 && fr > k), _fail, "f(100) is not in (k, 1000]");
			// Assert that f is strictly increasing. We only check a nessary condition.
			cave::DecimalFixed prev = fl;
			cave::DecimalFixed step("0.005");
			for (cave::DecimalFixed i = step; i < 100; i = i + step) {
				cave::DecimalFixed cur = f(i);
				quitif(cur <= prev, _fail, "f is not strictly increasing");
				prev = cur;
			}
			quitif(prev >= fr, _fail, "f is not strictly increasing");
		}
		// Then we use binary search to find the root.
		for (int i = 0; i < 210; i++) {
			cave::DecimalFixed mid = (l + r).divide_by_two();
			cave::DecimalFixed fmid = f(mid);
			quitif((fl >= fmid || fmid >= fr) && (r - l) > cave::DecimalFixed("0.00000000000000000001"), _fail, "f is not strictly increasing");
			if (fmid <= k) {
				l = mid;
				fl = fmid;
			} else {
				r = mid;
				fr = fmid;
			}
		}
		t = l;
	}

	// Check if x is a valid answer.
	bool verify(cave::DecimalFixed x) const {
		cave::DecimalFixed eps("0.0001");
		return (x - t).abs() <= eps || (x - t).abs() <= eps * t.abs() || (f(x) - k).abs() <= eps || (f(x) - k).abs() <= eps * k.abs();
	}

	cave::DecimalFixed answer() const { return t; }

	cave::DecimalFixed operator()(cave::DecimalFixed x) const { return f(x); }
};