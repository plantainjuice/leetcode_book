/*
 * @lc app=leetcode id=1207 lang=cpp
 *
 * [1207] Unique Number of Occurrences
 */

// @lc code=start
class Solution {
 public:
  bool uniqueOccurrences(vector<int>& arr) {
    map<int, int> counter;
    for (int n : arr) counter[n]++;

    set<int> s;
    for (auto& kv : counter) {
      if (s.count(kv.second) == 0)
        s.insert(kv.second);
      else
        return false;
    }

    return true;
  }
};
// @lc code=end

