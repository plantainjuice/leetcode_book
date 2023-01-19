/*
 * @lc app=leetcode id=1239 lang=cpp
 *
 * [1239] Maximum Length of a Concatenated String with Unique Characters
 */

// @lc code=start
class Solution {
 public:
  int maxLength(vector<string>& arr) {
    int ans = 0;

    backtrack(arr, 0, "", ans);

    return ans;
  }

 private:
  void backtrack(vector<string>& arr, int index, string cur, int& max_len) {
    // prune
    if (!isUnique(cur)) return;

    max_len = max(max_len, int(cur.size()));

    for (int i = index; i < arr.size(); ++i) {
    //   backtrack(arr, i+1, cur, max_len);
      backtrack(arr, i+1, cur + arr[i], max_len);
    }
  }

  bool isUnique(const string& s) {
    if(s.size() > 26) return false;

    vector<int> m(26);
    for(char c : s)
      if(++m[c-'a'] == 2) return false;

    return true;
  }
};
// @lc code=end

