/*
 * @lc app=leetcode id=1962 lang=cpp
 *
 * [1962] Remove Stones to Minimize the Total
 */

// @lc code=start
class Solution {
 public:
  int minStoneSum(vector<int>& piles, int k) {
    priority_queue<int> pq(piles.begin(), piles.end());

    while (k--) {
      int pile = pq.top();
      if (pile == 1) break;
      pq.pop();

      pile -= pile / 2;
      pq.push(pile);
    }

    int ans = 0;

    while (!pq.empty()) {
      int i = pq.top();
      pq.pop();

      ans += i;
    }

    return ans;
  }
};
// @lc code=end
