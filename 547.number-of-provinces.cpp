/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int color = 0;

        function<void(int, int)> dfs = [&] (int i, int c) -> void {
            // has been visited
            if(isConnected[i][i] < 0) return;

            isConnected[i][i] = c;

            for(int j = 0; j < n; ++j) {
                if(isConnected[i][j] != 1) continue;
                dfs(j, c);
            }
        };

        for (int i = 0; i < n; ++i) {
            if(isConnected[i][i] == 1) {
                dfs(i, --color);
            }
        }

        return -color;
    }
};
// @lc code=end

