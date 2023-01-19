/*
 * @lc app=leetcode id=895 lang=cpp
 *
 * [895] Maximum Frequency Stack
 */

// @lc code=start
class FreqStack {
 public:
  FreqStack() : max_freq_(0) {}

  void push(int val) {
    int freq = ++counter_[val];

    if(freq > max_freq_) max_freq_ = freq;

    group_[freq].push_back(val);
  }

  int pop() {
    int val = group_[max_freq_].back();
    group_[max_freq_].pop_back();

    --counter_[val];

    if (group_[max_freq_].empty()) max_freq_--;

    return val;
  }

 private:
  unordered_map<int, int> counter_;
  unordered_map<int, vector<int>> group_;
  int max_freq_;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
// @lc code=end
