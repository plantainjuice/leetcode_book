/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
class Solution {
public:
    // bool isIsomorphic(string s, string t) {
    bool isIsomorphic(const string& s, const string& t) {
        int l1 = s.size();
        int l2 = t.size();
        if(l1 != l2) return false;

        unordered_map<char, char> m1;
        unordered_map<char, char> m2;

        for(int i = 0; i < l1; ++i) {
            char c1 = s[i];
            char c2 = t[i];

            if(m1.find(c1) == m1.end() && m2.find(c2) == m2.end()) {
                m1[c1] = c2;
                m2[c2] = c1;
                continue;
            }

            if(m1[c1] != c2 || m2[c2] != c1) return false;
        }

        return true;
    }
};
// @lc code=end

