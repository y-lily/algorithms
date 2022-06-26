/**
 * @file soe.hpp
 * @brief Implementation of the Sieve of Eratosthenes (SoE) algorithm.
 * @details (https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes)
 * SoE is an algorithm for finding prime numbers up to a specific limit.
 * The algorithm:
 * - in a bit array of length n, set every bit to 1, except for 0 and 1;
 * - starting from p = 2, for each p set to 1, set to 0 all bits which are
 * multiples of p, except for p itself.
 * The result is an array of length n, where an index i is set to 1 if and
 * only if an integer number i is prime.
 *
 * ### Time complexity
 * O(n log log n)
 *
 * ### Space complexity
 * O(n)
 *
 * @author y-lily
 * @version 0.3
 * @date 2022-06-26
 */

#include <bitset>
#include <cmath>

using std::bitset;


template <uint64_t N>
inline void set_each(bitset<N>& numbers, uint64_t start, uint64_t step, bool value) {
    for (auto i = start; i < N; i += step) {
        numbers.set(i, value);
    }
}


/**
 * @brief Within a bitset with indices representing integer numbers, sets the
 * indices corresponding to prime numbers true and the indices corresponding
 * to non-prime numbers false.
 *
 * @tparam N The size of the bitset and the (excluded) upper limit of the
 * search range.
 * @param numbers The bitset with indices representing integers [0; N - 1].
 */
template <uint64_t N>
void set_primes(bitset<N>& numbers) {
    numbers.set(0, false);
    numbers.set(1, false);
    set_each(numbers, 2, 1, true);

    for (uint64_t p = 2; p <= std::sqrt(N); ++p) {
        if (numbers[p]) {
            set_each(numbers, p + p, p, false);
        }
    }
}
