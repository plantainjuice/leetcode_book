/*
 * @lc app=leetcode id=1710 lang=cpp
 *
 * [1710] Maximum Units on a Truck
 */

// @lc code=start
class Solution {
public:
    int maximumUnits(vector<vector<int>>& B, int T) {
        int ans = 0;

        auto cmp = [] (vector<int>& lhs, vector<int>& rhs) -> bool {
            return lhs[1] > rhs[1];
        };

        sort(B.begin(), B.end(), cmp);

        int i = 0;
        while(T && i < B.size()) {
            int c = min(T, B[i][0]);
            ans += c * B[i][1];

            T -= c;
            i++;
        }

        return ans;
    }
};
// @lc code=end

