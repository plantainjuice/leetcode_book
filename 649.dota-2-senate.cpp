/*
 * @lc app=leetcode id=649 lang=cpp
 *
 * [649] Dota2 Senate
 */

// @lc code=start
class Solution {
 public:
  string predictPartyVictory(string senate) {
    bool D = true;  // still has Dire
    bool R = true;  // still has Radiant

    int D_disabled = 0;
    int R_disabled = 0;

    while (D && R) {
      D = false;
      R = false;

      for (int i = 0; i < senate.size(); ++i) {
        if (senate[i] == 'D') {
          if (D_disabled > 0) {
            senate[i] = '#';  // mark as disabled
            --D_disabled;
          } else {
            ++R_disabled;
            D = true;
          }
        }

        if (senate[i] == 'R') {
          if (R_disabled > 0) {
            senate[i] = '#';  // mark as disabled
            --R_disabled;
          } else {
            ++D_disabled;
            R = true;
          }
        }
      }
    }

    return R == true ? "Radiant" : "Dire";
  }
};
// @lc code=end

