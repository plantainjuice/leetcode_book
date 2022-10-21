/*
 * @lc app=leetcode id=901 lang=cpp
 *
 * [901] Online Stock Span
 */

// @lc code=start
class StockSpanner {
 public:
  StockSpanner() {}

  int next(int price) {
    int span = 1;
    while (!st_.empty() && price >= st_.top().first) {
      span += st_.top().second;
      st_.pop();
    }

    if (st_.empty() || price < st_.top().first) {
      st_.push({price, span});
    }

    return span;
  }

 private:
  stack<pair<int, int>> st_;  // price, span
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end

