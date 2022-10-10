/*
 * @lc app=leetcode id=1105 lang=cpp
 *
 * [1105] Filling Bookcase Shelves
 */

// @lc code=start
class Solution {
 public:
  int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
    memo_ = vector<vector<int>>(books.size(), vector<int>(shelfWidth + 1, -1));

    return dp(books, shelfWidth, 0, 0, 0);
  }

 private:
  vector<vector<int>> memo_;

  int dp(vector<vector<int>>& books, int shelfWidth, int i, int cur_w, int cur_h) {
    if (i == books.size()) return cur_h;

    if (memo_[i][cur_w] != -1) return memo_[i][cur_w];

    int res = 1e6;

    int w = books[i][0];
    int h = books[i][1];

    // op1
    if (cur_w + w <= shelfWidth) {
      res = min(res, dp(books, shelfWidth, i + 1, cur_w + w, max(cur_h, h)));
    }

    // op2
    if (cur_w != 0) {
      res = min(res, dp(books, shelfWidth, i + 1, w, h) + cur_h);
    }

    return memo_[i][cur_w] = res;
  }
};
// @lc code=end

