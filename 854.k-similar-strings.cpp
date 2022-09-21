/*
 * @lc app=leetcode id=854 lang=cpp
 *
 * [854] K-Similar Strings
 */

// @lc code=start
// https://leetcode.com/problems/k-similar-strings/discuss/2273878/BFS-and-Logical-Thinking-Applied-or-Fully-Explained
class Solution {
 public:
//   int kSimilarity(string s1, string s2) {
  int kSimilarity(const string& s1, const string& s2) {
    int n = s1.size();
    queue<pair<string, int>> Q; // <string, steps>
    unordered_set<string> S;
    S.insert(s1);
    Q.push({s1, 0});

    while (!Q.empty()) {
      pair<string, int> kv = Q.front();
      Q.pop();

      string curr = kv.first;
      int steps = kv.second;

      if (curr == s2) return steps;

      int i = 0;
      while (i < n && curr[i] == s2[i]) ++i;
      for (int j = i + 1; j < n; ++j) {
        if (curr[j] == s2[i]) {
          swap(curr[i], curr[j]);
          if (S.count(curr) == 0) Q.push({curr, steps + 1}), S.insert(curr);
          swap(curr[i], curr[j]);
        }
      }
    }

    return 0;
  }
};
// @lc code=end

