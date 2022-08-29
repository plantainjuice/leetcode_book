/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
#include <deque>
#include <vector>

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;

        for (int i = 0; i < nums.size(); ++i) {
            while(!q.empty() && nums[i] >= nums[q.back()]) q.pop_back();
            q.push_back(i);
            if (i - k + 1 >= 0) ans.push_back(nums[q.front()]);
            if (i - k + 1 >= q.front()) q.pop_front();
        }

        return ans;
    }
};
// @lc code=end

