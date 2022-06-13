#include <array>

using std::array;


// Just showing off here; compilers do the same or better.
constexpr bool divisible_by_two(int n) {
  return !(n & 0b1);
}


// The idea is to manually cut the amount of checks performed to the minimum. 
// Using divisibility rules, we can remove all numbers divisible by 2 or 5 
// and see the following prime candidates left:
//  2     3     5     7
//  11    13    17    19
//  21    23    27    29
//  ...   ...   ...   ...
//  101   103   107   109
//  ...   ...   ...   ...
// a...1 a...3 a...7 a...9
// With the repeating pattern, we can apply the rule for divisibility by 3.
// If we look at the row { 1a, 2a, 3a, 4a, 5a, ..., 8a, 9a, 10a, 11a, ...},
// we can see that, starting from some position, every third number will be
// divisible by three.
// Here, we gonna use a helper function, which will generate prime candidates
// from a sequence and tell whether any of them is a divisor to n.
bool divisor_in_sequence(int n, int sequenceStart) {
  int limit = n / 2;
  int prime = sequenceStart;

  // Find the first element to skip. 
  while (prime % 3 != 0 && prime < limit) {
    if (n % prime == 0) { return true; }
    limit = n / prime;
    prime += 10;
  }

  // Now, prime|3, so we can skip this step and launch a cycle.
  prime += 10;

  while (prime < limit) {
    for (int i = 0; i < 2 && prime < limit; ++i) {
      if (n % prime == 0) { return true; }
      limit = n / prime;
      prime += 10;
    }

    prime += 20;  // Skip the prime|3 step. 
  }

  return false;
}


bool is_prime(int n) {
  if (n < 2) { return false; }

  array<int, 6> firstPrimes { 2, 3, 5, 7, 9, 11 };
  for (int prime : firstPrimes) {
    if (n == prime) { return true; }
    if (n % prime == 0) { return false; }
  }

  array<int, 4> base { 3, 7, 9, 11 };

  for (int prime : base) {
    if (divisor_in_sequence(n, prime)) { return false; }
  }

  return true;
}
