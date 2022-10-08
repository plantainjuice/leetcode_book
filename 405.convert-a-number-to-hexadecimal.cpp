/*
 * @lc app=leetcode id=405 lang=cpp
 *
 * [405] Convert a Number to Hexadecimal
 */

// @lc code=start
class Solution {
 public:
  vector<char> v = {'0', '1', '2', '3', '4', '5', '6', '7',
                    '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
  string toHex(int num) {
    string hex;

    for(int i = 0; i < 32; i += 4) {
      int n = (num >> i) & 0xf;
      hex.push_back(v[n]);
    }

    // trim
    for (int i = 7; i > 0; i--) {
      if (hex[i] == '0')
        hex.pop_back();
      else
        break;
    }

    reverse(hex.begin(), hex.end());

    return hex;
  }
};
// @lc code=end

