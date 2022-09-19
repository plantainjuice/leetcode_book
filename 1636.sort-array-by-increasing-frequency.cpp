/*
 * @lc app=leetcode id=1636 lang=cpp
 *
 * [1636] Sort Array by Increasing Frequency
 */

// @lc code=start
class Solution {
 public:
  vector<int> frequencySort(vector<int>& nums) {
    // 1. count
    map<int, int> cnt;
    for (int n : nums) ++cnt[n];

    // 2. sort
    vector<pair<int, int>> v;
    for(auto& kv : cnt) v.push_back(kv);

    auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
      if (a.second == b.second) return a.first > b.first;
      return a.second < b.second;
    };

    sort(v.begin(), v.end(), cmp);

    // 3. rebuild answer
    vector<int> ans;
    for(auto kv : v) {
      for(int i = 0; i < kv.second; ++i)
      ans.push_back(kv.first);
    }
    return ans;
  }
};
// @lc code=end

