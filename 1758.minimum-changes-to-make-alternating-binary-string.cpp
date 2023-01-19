/*
 * @lc app=leetcode id=1758 lang=cpp
 *
 * [1758] Minimum Changes To Make Alternating Binary String
 */

// @lc code=start
class Solution {
 public:
  // int minOperations(string s) {
  int minOperations(const string& s, int op = -1) {
    int sz = s.size();
    if (sz == 0) return 0;

    if (op == 0) return (s[0] == '0') + minOperations(s.substr(1), 1);
    if (op == 1) return (s[0] == '1') + minOperations(s.substr(1), 0);

    // if (op == -1)
    int r0 = (s[0] == '0') + minOperations(s.substr(1), 1);
    int r1 = (s[0] == '1') + minOperations(s.substr(1), 0);
    return min(r0, r1);
  }
};
// @lc code=end
