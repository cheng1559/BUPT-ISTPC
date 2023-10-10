#include "testlib.h"
#include <cassert>
#include <cstdint>
#include <ctime>
#include <vector>

namespace cave {
using BigUnsigned = std::vector<uint32_t>;

// Strip leading zeros in a big integer.
static void b_strip(BigUnsigned &i) {
	while (!i.empty() && !i.back()) {
		i.pop_back();
	}
}

// Compare two big integers.
static int b_cmp(const BigUnsigned &lhs, const BigUnsigned &rhs) {
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

// Add src to dest.
static void b_add(BigUnsigned &dest, const BigUnsigned &src) {
	uint32_t carry = 0;
	if (dest.size() < src.size() + 1) {
		dest.resize(src.size() + 1);
	}
	for (int i = 0; i < (int)src.size() || carry; i++) {
		uint64_t tmp = (uint64_t)dest[i] + carry + (i < (int)src.size() ? src[i] : 0);
		dest[i] = tmp & 0xffffffff;
		carry = tmp >> 32;
	}
	assert(carry == 0);
	b_strip(dest);
}

// Multiply src to dest.
static void b_mul(BigUnsigned &dest, const BigUnsigned &src) {
	std::vector<uint64_t> tmp(dest.size() + src.size() + 1);
	for (int i = 0; i < (int)dest.size(); i++) {
		for (int j = 0; j < (int)src.size(); j++) {
			uint64_t t = (uint64_t)dest[i] * src[j];
			tmp[i + j] += t & 0xffffffff;
			tmp[i + j + 1] += t >> 32;
		}
	}
	uint32_t carry = 0;
	dest.resize(tmp.size());
	for (int i = 0; i < (int)tmp.size() || carry; i++) {
		uint64_t t = tmp[i] + carry;
		dest[i] = t & 0xffffffff;
		carry = t >> 32;
	}
	assert(carry == 0);
	b_strip(dest);
}
} // namespace cave

// Information about this problem.
#define INPUT_MAX_LEN 50
#define INPUT_MAX_VAL 10000
#define OUTPUT_MAX_LEN 100
#define OUTPUT_MAX_VAL 1000000000