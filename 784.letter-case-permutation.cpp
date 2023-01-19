/*
 * @lc app=leetcode id=784 lang=cpp
 *
 * [784] Letter Case Permutation
 */

// @lc code=start
class Solution {
 public:
  vector<string> letterCasePermutation(string s) {
    vector<string> ans;

    function<void(int)> dfs = [&](int index) -> void {
      if (index == s.size()) {
        ans.push_back(s);
        return;
      };

      if (!isalpha(s[index])) return dfs(index + 1);

      // 1. lower
      s[index] = tolower(s[index]);
      dfs(index + 1);

      // 2. upper
      s[index] = toupper(s[index]);
      dfs(index + 1);
    };

    dfs(0);

    return ans;
  }
};
// @lc code=end

