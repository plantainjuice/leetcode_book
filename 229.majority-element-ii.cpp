/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */

// @lc code=start
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n1 = 0, n2 = 1;
        int c1 = 0, c2 = 0;

        for (int num : nums) {
            if (num == n1) {
                ++c1;
            } else if (num == n2) {
                ++c2;
            } else if (c1 == 0) {
                n1 = num;
                c1 = 1;
            } else if (c2 == 0) {
                n2 = num;
                c2 = 1;
            } else {
                --c1;
                --c2;
            }
        }

        c1 = c2 = 0;
        for (int num : nums) {
            if (num == n1) ++c1;
            if (num == n2) ++c2;
        }

        const int c = nums.size() / 3;

        vector<int> res;
        if (c1 > c) res.push_back(n1);
        if (c2 > c) res.push_back(n2);

        return res;
    }
};
// @lc code=end

