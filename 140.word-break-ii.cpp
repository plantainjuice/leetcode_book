/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */

// @lc code=start
class Solution {
 public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    int n = wordDict.size();
    vector<string> ans;

    function<void(int, vector<string>&)> dfs = [&](int index, vector<string>& path) -> void {
      // found
      if (index == s.size()) {
        string t;
        for (string& s : path) t += s + " ";
        t.pop_back();

        ans.push_back(t);
        return;
      }

      // recursively find
      for (int i = 0; i < n; ++i) {
        string& w = wordDict[i];

        if (index + w.size() > s.size()) continue;
        if (s.substr(index, w.size()) != w) continue;

        path.push_back(w);
        dfs(index + w.size(), path);
        path.pop_back();
      }
    };

    vector<string> path;
    dfs(0, path);

    return ans;
  }
};
// @lc code=end
