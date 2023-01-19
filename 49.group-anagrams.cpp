/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<string, vector<string>> M;

    for (string& s : strs) {
      string t = s;
      sort(t.begin(), t.end());
      M[t].push_back(s);
    }

    vector<vector<string>> ans;
    for (auto& kv : M) {
      ans.push_back(move(M.second));
    }

    return ans;
  }
};
// @lc code=end

