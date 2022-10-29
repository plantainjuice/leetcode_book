/*
 * @lc app=leetcode id=2136 lang=cpp
 *
 * [2136] Earliest Possible Day of Full Bloom
 */

// @lc code=start
class Solution {
  // https://leetcode.com/problems/earliest-possible-day-of-full-bloom/discuss/1676837/Grow-then-plant
 public:
  int earliestFullBloom(vector<int>& P, vector<int>& G) {
    vector<pair<int, int>> zip;
    for (int i = 0; i < P.size(); ++i) 
      zip.push_back({G[i], P[i]});

    sort(zip.begin(), zip.end());

    int res = 0;
    for (pair<int, int>& kv : zip) {
      int g = kv.first, p = kv.second;
      res = max(res, g) + p;
    }

    return res;
  }
};
// @lc code=end

