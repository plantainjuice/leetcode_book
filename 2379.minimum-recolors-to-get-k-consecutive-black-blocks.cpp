/*
 * @lc app=leetcode id=2379 lang=cpp
 *
 * [2379] Minimum Recolors to Get K Consecutive Black Blocks
 */

// @lc code=start
class Solution {
 public:
  int minimumRecolors(string blocks, int k) {
    int b = 0;
    int mb = 0;

    // sliding window
    for (int i = 0; i < blocks.size(); ++i) {
      b += (blocks[i] == 'B');
      if (i >= k) b -= (blocks[i - k] == 'B');
      mb = max(mb, b);
    }

    return k - mb;
  }
};
// @lc code=end
