/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
 public:
  int maxArea(vector<int>& height) {
    int l = 0, r = height.size() - 1;

    int ans = 0;
    while (l < r) {
      int h = min(height[l], height[r]);
      int w = r - l;

      ans = max(ans, h * w);

      if (height[l] > height[r])
        --r;
      else
        ++l;
    }

    return ans;
  }
};
// @lc code=end

