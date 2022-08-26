/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
#include <queue>

class MyStack {
 public:
  MyStack() {}

  void push(int x) {
    q_.push(x);
    for (int i = 1; i < q_.size(); ++i) {
      q_.push(q_.front());
      q_.pop();
    }
  }

  int pop() {
    int r = q_.front();
    q_.pop();
    return r;
  }

  int top() { return q_.front(); }

  bool empty() { return q_.empty(); }

 private:
  queue<int> q_;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

