// Output prime numbers to an ostream using the Sieve of Eratosthenes.
// The algorithm's description:
//   1. Create a list of N elements with all elements initially enabled.
//   2. Start with P = 2 (the smallest prime number).
//   3. If P is enabled, write it down (as it is a prime number) and disable every Pth element.
//   4. If P is not greater than N, increment it by 1 and return to the step 3.
#include <bitset>
#include <ostream>
#include <string>


using ul = unsigned long;
using std::bitset, std::ostream, std::string;

const auto mask_size = 60'000'000;


inline void set_each(ul start, ul end, ul step, bitset<mask_size>& mask, bool value = true) {
  for (auto i = start; i <= end && i >= step; i += step) {
    mask.set(i, value);
  }
}

/**
 * @brief Outputs a sequence of the prime numbers within a specific range.
 *
 * @param os The output stream which recieves the result numbers.
 * @param limit An upper bound of the search range; should be less than mask_size.
 * @param delim A delimiter sent to the ostream after every found prime.
 */
void generate_primes(ostream& os, ul limit, const string& delim = "\n") {
  bitset<mask_size> mask;
  set_each(2, limit, 1, mask);

  for (ul i = 2; i <= limit && i >= 2; ++i) {
    if (mask[i] == true) {
      os << i << delim;
      set_each(i, limit, i, mask, false);
    }
  }
}
