/*
 * @lc app=leetcode id=738 lang=cpp
 *
 * [738] Monotone Increasing Digits
 */

// @lc code=start
class Solution {
 public:
  int monotoneIncreasingDigits(int n) {
    string strN = to_string(n);
    int flag = strN.size();

    for (int i = strN.size() - 1; i > 0; --i) {
      if(strN[i-1] > strN[i]) {
        flag = i;
        strN[i-1]--;
      }
    }

    for(int i = flag; i < strN.size(); ++i) {
        strN[i] = '9';
    }

    return stoi(strN);
  }
};
// @lc code=end

