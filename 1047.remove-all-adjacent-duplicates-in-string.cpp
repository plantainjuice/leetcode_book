/*
 * @lc app=leetcode id=1047 lang=cpp
 *
 * [1047] Remove All Adjacent Duplicates In String
 */

// @lc code=start
class Solution {
 public:
  // string removeDuplicates(string s) {
  string removeDuplicates(const string& s) {
    stack<char> st;
    for (char c : s) {
      if (st.empty()) {
        st.push(c);
        continue;
      }

      if (c != st.top())
        st.push(c);
      else
        st.pop();
    }

    string ans;
    while (!st.empty()) {
      ans += st.top();
      st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
  }
};
// @lc code=end

