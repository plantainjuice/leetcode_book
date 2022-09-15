/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

// @lc code=start
class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> st;  // monotonic stack
    vector<int> ans(nums1.size(), -1);
    unordered_map<int, int> n2i;

    // num -> index
    for (int i = 0; i < nums1.size(); ++i) n2i[nums1[i]] = i;

    st.push(0);
    for (int i = 1; i < nums2.size(); ++i) {
      while (!st.empty() && nums2[i] > nums2[st.top()]) {
        // can find in nums1
        if (n2i.find(nums2[st.top()]) != n2i.end()) {
          ans[n2i[nums2[st.top()]]] = nums2[i];
        }

        st.pop();
      }

      st.push(i);
    }

    return ans;
  }
};
// @lc code=end

