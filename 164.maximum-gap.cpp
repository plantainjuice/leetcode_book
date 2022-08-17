/*
 * @lc app=leetcode id=164 lang=cpp
 *
 * [164] Maximum Gap
 */

// @lc code=start
#include <vector>

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        const auto mm = minmax_element(nums.begin(), nums.end());
        int max_distance = *mm.second - *mm.first;
        int bucket_size = max_distance / n + 1;
        int bucket_num = n;
        // int bucket_num = max_distance / bucket_size + 1; // less memo

        // use max-min bucket to record
        vector<int> bucket_max(bucket_num, INT_MIN);
        vector<int> bucket_min(bucket_num, INT_MAX);

        for (auto& num : nums) {
            const int index = (num - *mm.first) / bucket_size;
            bucket_max[index] = max(bucket_max[index], num);
            bucket_min[index] = min(bucket_min[index], num);
        }

        int max_gap = 0;
        int prev_max = bucket_max[0];
        for (int i = 1; i < bucket_num; ++i) {
            if (bucket_min[i] != INT_MAX) {
                max_gap = max(max_gap, bucket_min[i] - prev_max);
                prev_max = bucket_max[i];
            }
        }

        return max_gap;
    }
};
// @lc code=end

