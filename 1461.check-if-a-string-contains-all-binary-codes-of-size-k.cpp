/*
 * @lc app=leetcode id=1461 lang=cpp
 *
 * [1461] Check If a String Contains All Binary Codes of Size K
 */

// @lc code=start
class Solution {
 public:
  bool hasAllCodes(string S, int K) {
    if (K > S.size()) return false;

    unordered_set<string> s;

    for (int i = 0; i <= S.size() - K; ++i) s.insert(S.substr(i, K));

    return s.size() == pow(2, K);
  }
};
// @lc code=end

