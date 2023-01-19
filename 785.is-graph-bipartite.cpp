/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 */

// @lc code=start
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        // 0: no color
        // 1: A color
        // -1: B color
        vector<int> colors(n);

        function<bool(int, int)> coloring = [&] (int node, int c) -> bool {
            // check whether color is right if has been colored
            if(colors[node]) return colors[node] == c;

            colors[node] = c;

            for(int neigh : graph[node])
                if(!coloring(neigh, -c)) return false;
            
            return true;
        };

        for(int i = 0; i < n; ++i) {
            if(colors[i] == 0 && !coloring(i, 1)) return false;
        }

        return true;
    }
};
// @lc code=end

