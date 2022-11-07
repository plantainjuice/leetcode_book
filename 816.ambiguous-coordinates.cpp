/*
 * @lc app=leetcode id=816 lang=cpp
 *
 * [816] Ambiguous Coordinates
 */

// @lc code=start
class Solution {
 public:
  vector<string> ambiguousCoordinates(string s) {
    string S = s.substr(1, s.size() - 2);

    auto permutate = [&](int i, int j, vector<string>& res) -> void {
      string ss = S.substr(i, j - i + 1);

      if (ss.size() == 1) {
        res.push_back(ss);
        return;
      }

      if(ss[0] != '0') {
        res.push_back(ss);
      }

      if (ss.back() == '0') return;

      if (ss[0] == '0') {
        res.push_back("0." + ss.substr(1));
        return;
      }

      for(int i = 1; i < ss.size(); ++i) {
        res.push_back(ss.substr(0, i) + "." + ss.substr(i));
      }
    };

    int n = S.size();
    vector<string> ans;
    for (int i = 0; i < n - 1; ++i) {
      vector<string> p1, p2;
      permutate(0, i, p1);
      permutate(i + 1, n - 1, p2);

      // zip
      for (const string& s1 : p1)
        for (const string& s2 : p2) ans.push_back("(" + s1 + ", " + s2 + ")");
    }

    return ans;
  }
};
// @lc code=end

