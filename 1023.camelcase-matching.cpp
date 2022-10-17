/*
 * @lc app=leetcode id=1023 lang=cpp
 *
 * [1023] Camelcase Matching
 */

// @lc code=start
class Solution {
 public:
  vector<bool> camelMatch(vector<string>& queries, string pattern) {
    vector<bool> ans;

    for (const string& q : queries)
      ans.push_back(match(q, pattern));

    return ans;
  }

 private:
  bool match(const string& Q, const string& P) {
    int i = 0;
    int j = 0;

    auto is_upper = [](char c) -> bool { return c == toupper(c); };

    while(i < Q.size() || j < P.size()) {
      if(i == Q.size()) return false;
      if(j == P.size()) {
        while(i < Q.size()) {
          if(is_upper(Q[i])) return false;
          ++i;
        }
        return true;
      }

      if(is_upper(Q[i]) && is_upper(P[j])) {
        if(Q[i] != P[j]) return false;
        ++j;
      } else if(!is_upper(Q[i]) && !is_upper(P[j])) {
        if (Q[i] == P[j]) ++j;
      } else if(is_upper(Q[i]) && !is_upper(P[j])) {
        return false;
      }
      ++i;
    }

    return true;
  }
};
// @lc code=end

