/*
 * @lc app=leetcode id=1805 lang=cpp
 *
 * [1805] Number of Different Integers in a String
 */

// @lc code=start
class Solution {
 public:
  int numDifferentIntegers(string W) {
    unordered_set<string> S;

    int idx = -1;
    int last = -1;
    while (++idx <= W.size()) {
      if (idx == W.size() || !isdigit(W[idx])) {
        if (last == -1) {
          // remove head 0
          while (W[last] == '0' && (idx - last) > 1) ++last;

          S.insert(W.substr(last, idx - last));
          last = -1;
        }

        continue;
      }

      last = last == -1 ? idx : last;
    }

    return S.size();
  }
};
// @lc code=end
