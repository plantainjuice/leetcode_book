/*
 * @lc app=leetcode id=433 lang=cpp
 *
 * [433] Minimum Genetic Mutation
 */

// @lc code=start
class Solution {
 public:
  int minMutation(string start, string end, vector<string>& bank) {
    auto is_valid = [&](const string& a, const string& b) -> bool {
      int count = 0;
      for (int i = 0; i < a.size(); ++i)
        if (a[i] != b[i] && count++) return false;

      return true;
    };

    unordered_set<string> v;
    queue<string> q;

    v.insert(start);
    q.push(start);

    int mutations = 0;
    while (!q.empty()) {
      int l = q.size();

      while (l--) {
        string cur = std::move(q.front());
        q.pop();

        if (cur == end) return mutations;

        for (const string& b : bank) {
          if (v.count(b) || !is_valid(b, cur)) continue;
          v.insert(b);
          q.push(b);
        }
      }

      ++mutations;
    }

    return -1;
  }
};
// @lc code=end

