/*
 * @lc app=leetcode id=781 lang=cpp
 *
 * [781] Rabbits in Forest
 */

// @lc code=start
class Solution {
 public:
  int numRabbits(vector<int>& answers) {
    unordered_map<int, int> m;

    int total = 0;
    for (int ans : answers) {
      if (m[ans] == 0) {
        m[ans] = ans;
        total += ans + 1;
      } else {
        m[ans] -= 1;
      }
    }

    return total;
  }
};
// @lc code=end
