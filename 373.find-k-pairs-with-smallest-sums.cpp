/*
 * @lc app=leetcode id=373 lang=cpp
 *
 * [373] Find K Pairs with Smallest Sums
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                     int k) {
    priority_queue<pair<int, pair<int, int>>> heap;
    vector<vector<int>> ans;

    for (int i = 0; i < nums1.size(); ++i) {
      for (int j = 0; j < nums2.size(); ++j) {
        pair<int, pair<int, int>> t = {nums1[i] + nums2[j],
                                       {nums1[i], nums2[j]}};
        if (heap.size() < k) {
          heap.push(t);
          continue;
        }

        if (t.first < heap.top().first) {
          heap.pop();
          heap.push(t);
          continue;
        }

        break;
      }
    }

    while (!heap.empty()) {
      auto& top = heap.top().second;
      ans.push_back({top.first, top.second});
      heap.pop();
    }

    return ans;
  }
};
// @lc code=end

