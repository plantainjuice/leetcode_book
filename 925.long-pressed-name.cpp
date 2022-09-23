/*
 * @lc app=leetcode id=925 lang=cpp
 *
 * [925] Long Pressed Name
 */

// @lc code=start
class Solution {
public:
    // bool isLongPressedName(string name, string typed) {
    bool isLongPressedName(const string& name, const string& typed) {
      if(typed.size() < name.size()) return false;

      int i = 0;
      int j = 0;
      while(i < name.size() && j < typed.size()) {
        if (name[i] == typed[j]) {
          ++i, ++j;
          continue;
        }

        if(i == 0 || typed[j] != name[i-1]) {
          return false;
        }

        ++j;
      }

      if(i != name.size()) return false;

      while(j < typed.size()) {
        if(name[i - 1] != typed[j]) return false;
        ++j;
      }

      return true;
    }
};
// @lc code=end

