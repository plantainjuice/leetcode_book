/*
 * @lc app=leetcode id=842 lang=cpp
 *
 * [842] Split Array into Fibonacci Sequence
 */

// @lc code=start
class Solution {
 public:
  vector<int> splitIntoFibonacci(string num) {
    int n = num.size();
    vector<int> ans;
    vector<int> path;

    function<void(int)> dfs = [&](int index) -> void {
      // has been found
      if (ans.size() > 0) return;

      if (index == n) {
        if (path.size() >= 3) ans = path;
        return;
      }

      for (int i = index; i < n; ++i) {
        // special process for 0
        if (num[index] == '0' && i > index) break;

        long cur = stoll(num.substr(index, i - index + 1));
        if(cur > INT_MAX) return;

        if (path.size() == 0 || path.size() == 1) {
          path.push_back(cur);
          dfs(i + 1);
          path.pop_back();
        } else {
          int sz = path.size();
          long last1 = path[sz - 1];
          long last2 = path[sz - 2];

          if (last1 + last2 == cur) {
            path.push_back(cur);
            dfs(i + 1);
            path.pop_back();
          }
        }
      }
    };

    dfs(0);

    return ans;
  }
};
// @lc code=end

