/*
 * @lc app=leetcode id=828 lang=cpp
 *
 * [828] Count Unique Characters of All Substrings of a Given String
 */

// @lc code=start
class Solution {
 public:
  int uniqueLetterString(string S) {
    int ans = 0;
    const int N = S.size();
    constexpr int MOD = 1e9 + 7;
    vector<int> first_last(26, -1);   // last index
    vector<int> second_last(26, -1);  // last of the last index

    for (int i = 0; i < N; ++i) {
      int c = S[i] - 'A';
      int& l1 = first_last[c];
      int& l2 = second_last[c];
      ans = (ans + (i - l1) * (l1 - l2) % MOD) % MOD;

      l2 = l1;
      l1 = i;
    }

    for (int c = 0; c < 26; ++c) {
      int& l1 = first_last[c];
      int& l2 = second_last[c];
      ans = (ans + (N - l1) * (l1 - l2) % MOD) % MOD;
    }

    return ans;
  }
};
// @lc code=end

