/*
 * @lc app=leetcode id=1640 lang=cpp
 *
 * [1640] Check Array Formation Through Concatenation
 */

// @lc code=start
class Solution {
 public:
  bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
    int i = 0;

    while (i < arr.size()) {
      bool found = false;

      for (vector<int>& piece : pieces) {
        if (piece[0] == arr[i]) {
          found = true;

          for (int j = 0; j < piece.size(); ++j)
            if (i < arr.size() && piece[j] != arr[i++]) return false;

          break;
        }
      }

      // can not find
      if (!found) return false;
    }

    return true;
  }
};
// @lc code=end

