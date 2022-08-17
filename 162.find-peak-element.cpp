/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
#include <vector>

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return search(nums, 0, nums.size() - 1);
    }

    int search(vector<int>& nums, int lo, int hi) {
        if (lo == hi) return lo;

        int mid = (lo + hi) / 2;
        if (nums[mid] > nums[mid + 1]) {
            return search(nums, lo, mid);
        }

        return search(nums, mid+1, hi);
    }

    // int findPeakElement(vector<int>& nums) {
    //     for(int i = 0; i < nums.size() - 1; ++i) {
    //       if (nums[i] > nums[i + 1]) {
    //         return i;
    //       }
    //     }

    //     return nums.size() - 1;
    // }
};
// @lc code=end

