/*
 * @lc app=leetcode id=886 lang=cpp
 *
 * [886] Possible Bipartition
 */

// @lc code=start
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // 0: unknown
        // 1: group 1
        // -1: group 2
        vector<int> colors(n + 1);

        // build graph
        vector<vector<int>> graph(n + 1);
        for(auto& r : dislikes) {
            graph[r[0]].push_back(r[1]);
            graph[r[1]].push_back(r[0]);
        }

        function<bool(int, int)> coloring = [&] (int node, int c) -> bool {
            // check whether color is right if has been colored
            if(colors[node]) return colors[node] == c;

            colors[node] = c;

            for(int neigh : graph[node])
                if(!coloring(neigh, -c)) return false;

            return true;
        };

        for(int i = 1; i <= n; ++i) {
            if(colors[i] == 0 && !coloring(i, 1)) return false;
        }

        return true;
    }
};
// @lc code=end

