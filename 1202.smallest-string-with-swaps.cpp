/*
 * @lc app=leetcode id=1202 lang=cpp
 *
 * [1202] Smallest String With Swaps
 */

// @lc code=start
//https://leetcode.com/problems/smallest-string-with-swaps/discuss/388257/C%2B%2B-with-picture-union-find
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();

        // union set
        vector<int> ds(n, -1);
        function<int(int)> find = [&] (int i) -> int {
            return ds[i] == -1 ? i : ds[i] = find(ds[i]);
        };

        for(auto& p : pairs) {
            int i = find(p[0]);
            int j = find(p[1]);

            if(i != j) ds[i] = j;
        }

        map<int, vector<int>> m;
        for(int i = 0; i < s.size(); ++i) {
            m[find(i)].push_back(i);
        }

        for(const auto& kv : m) {
            const vector<int>& is = kv.second;
            string tmp;
            for(auto i : is)
                tmp += s[i];

            sort(tmp.begin(), tmp.end());

            for(int i = 0; i < is.size(); ++i)
                s[is[i]] = tmp[i];
        }

        return s;
    }
};
// @lc code=end

