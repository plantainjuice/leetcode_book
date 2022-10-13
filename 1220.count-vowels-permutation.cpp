/*
 * @lc app=leetcode id=1220 lang=cpp
 *
 * [1220] Count Vowels Permutation
 */

// @lc code=start
class Solution {
 public:
  int countVowelPermutation(int n) {
    constexpr int MOD = 1e9 + 7;
    array<long, 5> vowels = {1, 1, 1, 1, 1};

    while (--n) {
      array<long, 5> tmp = {0, 0, 0, 0, 0};

      tmp[1] += (vowels[0] % MOD);

      tmp[0] += (vowels[1] % MOD);
      tmp[2] += (vowels[1] % MOD);

      tmp[0] += (vowels[2] % MOD);
      tmp[1] += (vowels[2] % MOD);
      tmp[3] += (vowels[2] % MOD);
      tmp[4] += (vowels[2] % MOD);

      tmp[2] += (vowels[3] % MOD);
      tmp[4] += (vowels[3] % MOD);

      tmp[0] += (vowels[4] % MOD);

      vowels = tmp;
    }

    int ans = 0;
    for(int i = 0; i < 5; ++i) {
        ans += (vowels[i] % MOD);
        ans = (ans % MOD);
    }

    return ans;
  }
};
// @lc code=end

