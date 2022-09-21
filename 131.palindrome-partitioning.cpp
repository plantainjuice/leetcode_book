/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution {
public:
    // vector<vector<string>> partition(string s) {
    vector<vector<string>> partition(const string& s) {
      vector<vector<string>> ans;

      vector<string> path;
      backtrack(s, 0, path ,ans);

      return ans;
    }

private:
  // [start, end]
 bool is_palindrome(const string& s, int start, int end) {
   for (int i = start, j = end; i < j; ++i, --j) {
     if (s[i] != s[j]) return false;
   }
   return true;
 }

 void backtrack(const string& s, int index, vector<string>& path,
                vector<vector<string>>& ans) {
   if (index >= s.size()) {
     ans.push_back(path);
     return;
   }

   for (int i = index; i < s.size(); ++i) {
     if (is_palindrome(s, index, i)) {
       path.push_back(s.substr(index, i - index + 1));
       backtrack(s, i + 1, path, ans);
       path.pop_back();
     }
   }

 }
};
// @lc code=end

