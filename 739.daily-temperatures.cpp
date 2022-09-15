/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& T) {
    stack<int> st;
    vector<int> ans(T.size(), 0);
    st.push(0);

    for (int i = 1; i < T.size(); ++i) {
      while (!st.empty() && T[i] > T[st.top()]) {
        ans[st.top()] = i - st.top();
        st.pop();
      }

      st.push(i);
    }

    return ans;
  }
};
// @lc code=end

