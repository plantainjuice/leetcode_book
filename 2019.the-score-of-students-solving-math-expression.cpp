/*
 * @lc app=leetcode id=2019 lang=cpp
 *
 * [2019] The Score of Students Solving Math Expression
 */

// @lc code=start
class Solution {
 public:
  int scoreOfStudents(string s, vector<int>& answers) {
    // 1. parse
    vector<string> tokens;
    int last = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '+' || s[i] == '*') {
        tokens.push_back(s.substr(last, i - last));
        tokens.push_back(string(1, s[i]));
        last = i + 1;
      }
    }
    tokens.push_back(s.substr(last));

    // 2.1 find correct answer
    int corr_ans = 0;
    {
      stack<int> st;
      st.push(stoi(tokens[0]));
      int i = 1;
      while (i < tokens.size()) {
        if (tokens[i] == "+") {
          st.push(stoi(tokens[i + 1]));
          i += 2;
        } else if (tokens[i] == "*") {
          int top = st.top();
          st.pop();
          st.push(top * stoi(tokens[i + 1]));
          i += 2;
        }
      }

      while (!st.empty()) {
        int top = st.top();
        st.pop();
        corr_ans += top;
      }
    }

    // 2.2 find might correct answer
    unordered_set<int> memo[32][32];
    {
      function<void(int, int)> dfs = [&](int lo, int hi) -> void {
        if (!memo[lo][hi].empty()) return;

        if (hi == lo) memo[lo][hi].insert(stoi(tokens[lo]));

        for (int i = lo + 1; i < hi; i += 2) {
          dfs(lo, i - 1);
          dfs(i + 1, hi);
          for (int n1 : memo[lo][i - 1]) {
            for (int n2 : memo[i + 1][hi]) {
              int n = tokens[i] == "*" ? n1 * n2 : n1 + n2;
              if (n <= 1000) memo[lo][hi].insert(n);
            }
          }
        }
      };

      dfs(0, s.size() - 1);
    }

    // 3. calculate score
    int score = 0;
    for (int ans : answers) {
      if (ans == corr_ans)
        score += 5;
      else if (memo[0][tokens.size() - 1].count(ans))
        score += 2;
    }

    return score;
  }
};
// @lc code=end
