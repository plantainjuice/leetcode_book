/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    vector<int> H(heights);
    H.insert(H.begin(), 0);
    H.push_back(0);

    stack<int> st;
    st.push(0);

    int ans = 0;
    for(int i = 1; i < H.size(); ++i) {
      while(H[i] < H[st.top()]) {
        int mid = st.top();
        st.pop();

        int w = i - st.top() - 1;
        int h = H[mid];
        ans = max(ans, w * h);
      }

      st.push(i);
    }

    return ans;
  }
};
// @lc code=end

