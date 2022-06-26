/**
 * @file binary-search.hpp
 * @brief Implementation of the binary search algorithm.
 * @details (https://en.wikipedia.org/wiki/Binary_search_algorithm)
 * Binary search is an algorithm for finding a target value within a sorted
 * array.
 * The algorithm:
 * - in a sorted array of length n, compare an element in the middle (n // 2)
 * with the searched value;
 * - if the element is greater than the value, search in the lower half;
 * - if the element is less than the value, search in the upper half;
 * - repeat until the target value is found or there is no place left to search
 * in (this means the array doesn't contain the value).
 *
 * ### Time complexity
 * best case: O(1)
 * worst case: O(log n)
 *
 * ### Space complexity
 * O(1)
 *
 * @author y-lily
 * @version 0.1
 * @date 2022-06-27
 */

#include <vector>

using std::vector;


/**
 * @brief Finds a target value within a vector using binary search.
 *
 * @param tgt The searched value.
 * @param src The place to search in.
 * @return int index of the target value within the vector or -1 if the value
 * is not present.
 */
int binary_search(int tgt, const vector<int>& src) {
    const int NOT_FOUND = -1;

    if (src.empty()) { return NOT_FOUND; }

    int left = 0;
    int right = src.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (src[mid] == tgt) { return mid; }

        if (src[mid] > tgt) { right = mid - 1; }
        else { left = mid + 1; }
    }

    return NOT_FOUND;
}
