/*
 * @lc app=leetcode id=838 lang=cpp
 *
 * [838] Push Dominoes
 */

// @lc code=start
class Solution {
 public:
  string pushDominoes(string dominoes) {
    int n = dominoes.size();
    if (n <= 1) return dominoes;

    bool finish = false;
    while (!finish) {
      finish = true;

      string t = dominoes;

      for (int i = 0; i < n; ++i) {
        if (t[i] == '.') {
          if (i == 0 && dominoes[1] == 'L') {
            t[i] = 'L';
            finish = false;
            continue;
          }

          if (i == n - 1 && dominoes[n - 2] == 'R') {
            t[i] = 'R';
            finish = false;
            continue;
          }

          if (i == 0 || i == n - 1) continue;

          if (dominoes[i - 1] == 'R' && dominoes[i + 1] != 'L') {
            t[i] = 'R';
            finish = false;
            continue;
          }

          if (dominoes[i + 1] == 'L' && dominoes[i - 1] != 'R') {
            t[i] = 'L';
            finish = false;
            continue;
          }
        }
      }

      dominoes = move(t);
    }

    return dominoes;
  }
};
// @lc code=end

