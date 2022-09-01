/*
 * @lc app=leetcode id=313 lang=cpp
 *
 * [313] Super Ugly Number
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  // https://leetcode.com/problems/super-ugly-number/discuss/76298/7-line-consice-O(kn)-c%2B%2B-solution
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    vector<long> index(primes.size(), 0), ugly(n, INT_MAX);
    ugly[0] = 1;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < primes.size(); j++)
        ugly[i] = min(ugly[i], ugly[index[j]] * primes[j]);

      for (int j = 0; j < primes.size(); j++)
        index[j] += (ugly[i] == ugly[index[j]] * primes[j]);
    }
    return ugly[n - 1];
  }
};
// @lc code=end

