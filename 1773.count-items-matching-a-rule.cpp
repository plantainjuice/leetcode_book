/*
 * @lc app=leetcode id=1773 lang=cpp
 *
 * [1773] Count Items Matching a Rule
 */

// @lc code=start
class Solution {
 public:
  int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
    int index = 0;
    if (ruleKey == "type")
      index = 0;
    else if (ruleKey == "color")
      index = 1;
    else if (ruleKey == "name")
      index = 2;

    int cnt = 0;
    for(int i = 0; i < items.size(); ++i)
        if(items[i][index] == ruleValue) ++cnt;

    return cnt;
  }
};
// @lc code=end

