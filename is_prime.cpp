#include <bitset>
#include <cmath>
#include <limits>
#include <vector>

using std::bitset;
using std::vector;

constexpr int maxInt { std::numeric_limits<int>::max() };
constexpr int maskSize { (int) std::sqrt(maxInt) + 1 };


void setEach(int step, int limit, bitset<maskSize>& mask, bool value = true) {
  for (int i = step; i <= limit; i += step) {
    mask.set(i, value);
  }
}

void generatePrimes(vector<int>& storage, int limit) {
  bitset<maskSize> mask;
  setEach(1, limit, mask);

  for (int i = 2; i <= limit; ++i) {
    if (mask[i] == 0) { continue; }

    // Skip factors of every prime we meet.
    storage.emplace_back(i);
    setEach(i, limit, mask, false);
  }
}


bool isPrime(int n) {
  if (n < 2) { return false; }

  const int limit { (int) std::sqrt(n) };
  vector<int> primes;

  generatePrimes(primes, limit);

  for (auto prime : primes) {
    if (n % prime == 0) { return false; }
  }

  return true;
}
