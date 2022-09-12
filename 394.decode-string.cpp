/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
class Solution {
public:
  string decodeString(string s) {
    if (s.empty()) return "";    
    string ans;
    int i = 0;
    int n = s.length();
    int c = 0;
    while (isdigit(s[i]) && i < n) 
      c = c * 10 + (s[i++] - '0');
    
    int j = i;
    if (i < n && s[i] == '[') {      
      int open = 1;
      while (++j < n && open) {
        if (s[j] == '[') ++open;
        if (s[j] == ']') --open;
      }
    } else {
      while (j < n && isalpha(s[j])) ++j;
    }    
    
    // "def2[ac]" => "def" + decodeString("2[ac]")
    //  |  |
    //  i  j
    if (i == 0)
      return s.substr(0, j) + decodeString(s.substr(j));
    
    // "3[a2[c]]ef", ss = decodeString("a2[c]") = "acc"
    //   |      |
    //   i      j
    string ss = decodeString(s.substr(i + 1, j - i - 2));    
    while (c--)
      ans += ss;
    // "3[a2[c]]ef", ans = "abcabcabc", ans += decodeString("ef")
    ans += decodeString(s.substr(j));
    return ans;
  }
};
// @lc code=end

