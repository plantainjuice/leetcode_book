/*
 * @lc app=leetcode id=667 lang=cpp
 *
 * [667] Beautiful Arrangement II
 */

// @lc code=start
class Solution {
 public:
  vector<int> constructArray(int n, int k) {
    vector<int> ans(n);
    int l = 1, r = k + 1, i = 0;

    while (l < r) ans[i++] = l++, ans[i++] = r--;

    // `k` is even
    if (l == r) ans[i++] = r;

    while (i < n) ans[i++] = i + 1;

    return ans;
  }
};
// @lc code=end

