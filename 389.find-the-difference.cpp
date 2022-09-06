/*
 * @lc app=leetcode id=389 lang=cpp
 *
 * [389] Find the Difference
 */

// @lc code=start
class Solution {
public:
 char findTheDifference(string s, string t) {
   int diff = 0;
   for (int i = 0; i < s.size(); i++)
     diff += t[i] - s[i];  // Passing the diff: (t[i]-s[i]) to t[i+1]

   return static_cast<char>(diff +
                            t[t.size() - 1]);  // The diff will be carried over
                                               // to the last element eventually
 }
};
// @lc code=end

