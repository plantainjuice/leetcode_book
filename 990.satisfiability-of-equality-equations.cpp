/*
 * @lc app=leetcode id=990 lang=cpp
 *
 * [990] Satisfiability of Equality Equations
 */

// @lc code=start
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> us(26); // union set
        iota(us.begin(), us.end(), 0); // key point

        function<int(int)> find = [&] (int x) -> int {
            return us[x] == x ? x : us[x] = find(us[x]);
        };

        for(const string& e : equations) {
            if(e[1] == '=') us[find(e[0] - 'a')] = find(e[3] - 'a');
        }

        for(const string& e : equations) {
            if(e[1] == '!' && find(e[0] - 'a') == find(e[3] - 'a')) return false;
        }

        return true;
    }
};
// @lc code=end

