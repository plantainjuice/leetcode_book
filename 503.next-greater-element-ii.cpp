/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 */

// @lc code=start
class Solution {
 public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    // double the nums
    vector<int> N(nums);
    N.insert(N.end(), nums.begin(), nums.end());

    stack<int> st;
    vector<int> result(N.size(), -1);

    for (int i = 0; i < N.size(); ++i) {
      while(!st.empty() && N[i] > N[st.top()]) {
        int index = st.top();
        st.pop();
        result[index] = N[i];
      }

      st.push(i);
    }

    result.resize(N.size() / 2);
    return result;
  }
};
// @lc code=end

