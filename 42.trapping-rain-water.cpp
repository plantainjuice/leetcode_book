/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
 public:
  int trap(vector<int>& height) {
    stack<int> st;
    int sum = 0;
    for (int i = 0; i < height.size(); ++i) {
      while (!st.empty() && height[i] > height[st.top()]) {
        int mid = st.top();
        st.pop();

        if (!st.empty()) {
          int h = min(height[st.top()], height[i]) - height[mid];
          int w = i - st.top() - 1;
          sum += h * w;
        }
      }
      st.push(i);
    }

    return sum;
  }
};
// @lc code=end

