/*
 * @lc app=leetcode id=1830 lang=cpp
 *
 * [1830] Minimum Number of Operations to Make String Sorted
 */

// @lc code=start

class Solution {
 public:
  const int MOD = 1e9 + 7;

  long modpow(long b, long p) {
    long ans = 1;
    for (; p; p >>= 1) {
      if (p & 1) ans = ans * b % MOD;
      b = b * b % MOD;
    }
    return ans;
  }

  int makeStringSorted(string s) {
    long ans = 0;
    map<int, long> freq;
    for (char& c : s) {
      freq[c - 'a']++;
    }

    vector<long> fact(s.size() + 1, 1ll);
    for (int i = 1; i <= s.size(); i++) {
      fact[i] = (fact[i - 1] * i) % MOD;
    }

    int l = s.size();
    for (char c : s) {
      l--;
      long t = 0, rev = 1;
      for (int i = 0; i < 26; i++) {
        if (i < c - 'a') t += freq[i];
        rev = (rev * fact[freq[i]]) % MOD;
      }
      ans += (t * fact[l] % MOD) * modpow(rev, MOD - 2);

      ans %= MOD;

      freq[c - 'a']--;
    }
    return ans;
  }
};
;
// @lc code=end
