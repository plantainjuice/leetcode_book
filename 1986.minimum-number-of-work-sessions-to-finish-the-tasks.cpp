/*
 * @lc app=leetcode id=1986 lang=cpp
 *
 * [1986] Minimum Number of Work Sessions to Finish the Tasks
 */

// @lc code=start
class Solution {
 public:
  int ans = INT_MAX;
  int minSessions(vector<int>& v, int target) {
    vector<int> path;
    backtrack(0, v, target, path);
    return ans;
  }

 private:
  void backtrack(int start, vector<int>& v, int target, vector<int>& path) {
    if(start >= v.size()) {
      ans = min(ans, int(path.size()));
      return;
    }

    // prune
    if(path.size() > ans) return;

    // case1
    for(int i = 0; i < path.size(); ++i) {
      if(path[i] + v[start] <= target) {
        path[i] += v[start];
        backtrack(start+1, v, target, path);
        path[i] -= v[start];
      }
    }

    // case2
    path.push_back(v[start]);
    backtrack(start+1, v, target, path);
    path.pop_back();
  }
};
// @lc code=end

