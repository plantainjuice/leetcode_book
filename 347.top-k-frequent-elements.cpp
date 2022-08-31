/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
#include <vector>
#include <unordered_map>

class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> cnt;
    int max_freq = 1;
    for (const int num : nums) max_freq = max(max_freq, ++cnt[num]);
    unordered_map<int, vector<int>> buckets;
    for (const auto& kv : cnt) buckets[kv.second].push_back(kv.first);

    vector<int> ans;
    for (int i = max_freq; i >= 1; --i) {
      auto it = buckets.find(i);
      if (it == buckets.end()) continue;

      ans.insert(ans.end(), it->second.begin(), it->second.end());

      // it is guarantee by description
      if (ans.size() == k) break;
    }

    return ans;
  }
};
// @lc code=end

