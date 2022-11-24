/*
 * @lc app=leetcode id=1652 lang=cpp
 *
 * [1652] Defuse the Bomb
 */

// @lc code=start
class Solution {
 public:
  vector<int> decrypt(vector<int>& code, int k) {
    int n = code.size();

    vector<int> ans(n, 0);

    if (k == 0) return ans;

    if (k > 0) {
      int sum = accumulate(code.begin(), code.begin() + k, 0);

      for (int i = 0; i < n; ++i) {
        sum -= code[i];
        sum += code[(i + k) % n];

        ans[i] = sum;
      }
    } else {
      k = -k;
      int sum = accumulate(code.rbegin(), code.rbegin() + k, 0);

      for (int i = n - 1; i >= 0; --i) {
        sum -= code[i];
        sum += code[(n - k + i) % n]; // n + (n - k) - (n - i)

        ans[i] = sum;
      }
    }

    return ans;
  }
};
// @lc code=end
