/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */

// @lc code=start
class Solution {
 public:
  int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> candys(n, 1);

    for(int i = 1; i < n; ++i) {
      if (ratings[i] > ratings[i - 1]) candys[i] = candys[i - 1] + 1;
    }

    for (int i = n - 2; i >= 0; --i) {
      if (ratings[i] > ratings[i + 1]) candys[i] = max(candys[i], candys[i + 1] + 1);
    }

    int sum = accumulate(candys.begin(), candys.end(), 0);
    return sum;
  }
};
// @lc code=end

