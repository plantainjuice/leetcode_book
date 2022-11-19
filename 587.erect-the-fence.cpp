/*
 * @lc app=leetcode id=587 lang=cpp
 *
 * [587] Erect the Fence
 */

// @lc code=start
// https://leetcode.com/problems/erect-the-fence/discuss/1442271/Day-3-or-Erect-the-Fence-or-Convex-Hull-Algorithm-or-C%2B%2B-or-With-graphical-explanation
class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& T) {
        if(T.size() <= 3) return T;

        sort(T.begin(), T.end());

        // < 0: convex
        // > 0: concave
        auto curve = [&](vector<int>& i, vector<int>& j,
                         vector<int>& k) -> int {
          int x1 = i[0];
          int y1 = i[1];
          int x2 = j[0];
          int y2 = j[1];
          int x3 = k[0];
          int y3 = k[1];

          return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
        };

        // 1. find concave points
        vector<vector<int>> concave;
        concave.push_back(T[0]);
        concave.push_back(T[1]);
        for(int i = 2; i < T.size(); ++i) {
            int sz = concave.size();
            while(concave.size() >=2 && curve(concave[sz-2], concave[sz-1], T[i]) > 0) {
                concave.pop_back();
                --sz;
            }

            concave.push_back(T[i]);
        }

        // 2. find convex points
        int n = T.size();
        vector<vector<int>> convex;
        convex.push_back(T[0]);
        convex.push_back(T[1]);
        for(int i = 2; i < n; ++i) {
            int sz = convex.size();
            while(convex.size() >=2 && curve(convex[sz-2], convex[sz-1], T[i]) < 0) {
                convex.pop_back();
                --sz;
            }

            convex.push_back(T[i]);
        }

        // 3. merge it, remove duplicate
        set<vector<int>> ans = {concave.begin(), concave.end()};
        for(int i = 0; i < convex.size(); ++i) ans.insert(convex[i]);

        return {ans.begin(), ans.end()};
    }
};
// @lc code=end

