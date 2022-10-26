/*
 * @lc app=leetcode id=887 lang=cpp
 *
 * [887] Super Egg Drop
 */

// @lc code=start
class Solution {
 public:
  int superEggDrop(int K, int N) {
    vector<vector<int>> memo(K + 1, vector<int>(N + 1, -1));

    function<int(int, int)> D = [&](int k, int n) -> int {
      if (k == 1) return n;
      if (n <= 1) return n;

      if (memo[k][n] != -1) return memo[k][n];

      int l = 1, r = n;
      while (l < r) {
        int mid = (r - l) / 2 + l;
        if (D(k - 1, n - mid) > D(k, mid - 1)) {
          l = mid + 1;
        } else {
          r = mid;
        }
      }

      return memo[k][n] = (1 + max(D(k - 1, n - l), D(k, l - 1)));
    };

    return D(K, N);
  }
};
// @lc code=end

