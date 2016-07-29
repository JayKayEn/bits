#include <cstddef>

#include "TestCases.hh"

#include "../bits.hh"
#include "../inc/extint.hh"
#include "../util/Random.hh"

// TODO: Add in random test values

static const size_t rand_values = 128;

static const uint128_t VALUES[] = {
    U128(0x0000000000000000, 0x0000000000000000),
    U128(0x1111111111111111, 0x1111111111111111),
    U128(0x2222222222222222, 0x2222222222222222),
    U128(0x3333333333333333, 0x3333333333333333),
    U128(0x4444444444444444, 0x4444444444444444),
    U128(0x5555555555555555, 0x5555555555555555),
    U128(0x6666666666666666, 0x6666666666666666),
    U128(0x7777777777777777, 0x7777777777777777),
    U128(0x8888888888888888, 0x8888888888888888),
    U128(0x9999999999999999, 0x9999999999999999),
    U128(0xAAAAAAAAAAAAAAAA, 0xAAAAAAAAAAAAAAAA),
    U128(0xBBBBBBBBBBBBBBBB, 0xBBBBBBBBBBBBBBBB),
    U128(0xCCCCCCCCCCCCCCCC, 0xCCCCCCCCCCCCCCCC),
    U128(0xDDDDDDDDDDDDDDDD, 0xDDDDDDDDDDDDDDDD),
    U128(0xEEEEEEEEEEEEEEEE, 0xEEEEEEEEEEEEEEEE),
    U128(0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF),
    U128(0xFEDCBA9876543210, 0x0123456789ABCDEF),
    U128(0xEDCBA9876543210F, 0xF0123456789ABCDE),
    U128(0xDCBA9876543210FE, 0xEF0123456789ABCD),
    U128(0xCBA9876543210FED, 0xDEF0123456789ABC),
    U128(0xBA9876543210FEDC, 0xCDEF0123456789AB),
    U128(0xA9876543210FEDCB, 0xBCDEF0123456789A),
    U128(0x9876543210FEDCBA, 0xABCDEF0123456789),
    U128(0x876543210FEDCBA9, 0x9ABCDEF012345678),
    U128(0x76543210FEDCBA98, 0x89ABCDEF01234567),
    U128(0x6543210FEDCBA987, 0x789ABCDEF0123456),
    U128(0x543210FEDCBA9876, 0x6789ABCDEF012345),
    U128(0x43210FEDCBA98765, 0x56789ABCDEF01234),
    U128(0x3210FEDCBA987654, 0x456789ABCDEF0123),
    U128(0x210FEDCBA9876543, 0x3456789ABCDEF012),
    U128(0x10FEDCBA98765432, 0x23456789ABCDEF01),
    U128(0x0FEDCBA987654321, 0x123456789ABCDEF0),
    U128(0x0123456789ABCDEF, 0xFEDCBA9876543210),
    U128(0xF0123456789ABCDE, 0xEDCBA9876543210F),
    U128(0xEF0123456789ABCD, 0xDCBA9876543210FE),
    U128(0xDEF0123456789ABC, 0xCBA9876543210FED),
    U128(0xCDEF0123456789AB, 0xBA9876543210FEDC),
    U128(0xBCDEF0123456789A, 0xA9876543210FEDCB),
    U128(0xABCDEF0123456789, 0x9876543210FEDCBA),
    U128(0x9ABCDEF012345678, 0x876543210FEDCBA9),
    U128(0x89ABCDEF01234567, 0x76543210FEDCBA98),
    U128(0x789ABCDEF0123456, 0x6543210FEDCBA987),
    U128(0x6789ABCDEF012345, 0x543210FEDCBA9876),
    U128(0x56789ABCDEF01234, 0x43210FEDCBA98765),
    U128(0x456789ABCDEF0123, 0x3210FEDCBA987654),
    U128(0x3456789ABCDEF012, 0x210FEDCBA9876543),
    U128(0x23456789ABCDEF01, 0x10FEDCBA98765432),
    U128(0x123456789ABCDEF0, 0x0FEDCBA987654321)
};

template<class T, size_t N>
static size_t array_size(T(&)[N]) {
    return N;
}

TestCases::TestCases() {
    test_case_ = 0;
    size_t selected_values = array_size(VALUES);
    test_size_ = selected_values + rand_values;
    test_cases_ = new uint128_t[test_size_];
    for (size_t i = 0; i < selected_values; ++i)
        test_cases_[i] = VALUES[i];
    Random random;
    for (size_t i = selected_values; i < test_size_; ++i)
        test_cases_[i] = random.rand<uint128_t>();
}

TestCases::~TestCases() {
    delete[] test_cases_;
    test_cases_ = nullptr;
    test_size_ = -1;
    test_case_ = -1;
}

bool TestCases::more() {
    return test_case_ < test_size_;
}

template <typename T>
T TestCases::next() {
    return test_cases_[test_case_++];
}

#define TESTCASES_NEXT_TEMPLATE(T) template T TestCases::next<T>();
TEMPLIFY(TESTCASES_NEXT_TEMPLATE)
