/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

// @lc code=start
class Solution {
public:
    // vector<string> restoreIpAddresses(string s) {
    vector<string> restoreIpAddresses(const string& s) {
      vector<string> ans;

      vector<int> path;
      backtrace(s, 0, path, ans);

      return ans;
    }
private:
  void backtrace(const string& s, int index, vector<int>& path, vector<string>& ans) {
    if(path.size() == 4 && index >= s.size()) {
      string ip = "";
      for (int n : path) ip += to_string(n) + ".";

      ip.pop_back(); // `.`

      ans.push_back(ip);
      return;
    }

    for (int i = index; i < s.size() && i < index + 3; ++i) {
      if (i == index && s[i] == '0') {
        path.push_back(0);
        backtrace(s, i + 1, path, ans);
        path.pop_back();

        return;
      }

      int n = stoi(s.substr(index, i - index + 1));
      if (n <= 255) {
        path.push_back(n);
        backtrace(s, i + 1, path, ans);
        path.pop_back();
      }
    }
  }
};
// @lc code=end

