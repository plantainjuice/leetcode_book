/*
 * @lc app=leetcode id=948 lang=cpp
 *
 * [948] Bag of Tokens
 */

// @lc code=start
class Solution {
 public:
  int bagOfTokensScore(vector<int>& tokens, int power) {
    int i = 0, j = tokens.size() - 1;

    sort(tokens.begin(), tokens.end());

    int ans = 0;
    while (i <= j) {
      if (power >= tokens[i]) {
        power -= tokens[i++];
        ++ans;
      } else if (ans > 0 && j > i + 1) {
        power += tokens[j--];
        --ans;
      } else {
        break;
      }
    }

    return ans;
  }
};
// @lc code=end

