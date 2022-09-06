/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 */

// @lc code=start
// binary index tree
class BIT {
 public:
  BIT(int n) : sum_(n + 1, 0) {}

  void update(int i, int delta) {
    while (i < sum_.size()) {
      sum_[i] += delta;
      i += lower_bit(i);
    }
  }

  int query(int i) {
    int res = 0;
    while (i > 0) {
      res += sum_[i];
      i -= lower_bit(i);
    }

    return res;
  }

 private:
  int lower_bit(int i) { return i & (-i); }

 private:
  vector<int> sum_;
};

class NumArray {
 public:
  NumArray(vector<int>& nums) : tree_(nums.size() + 1) {
    for (int i = 0; i < nums.size(); ++i) tree_.update(i + 1, nums[i]);
  }

  void update(int index, int value) {
    int delta = value - sumRange(index, index);
    tree_.update(index + 1, delta);
  }

  int sumRange(int left, int right) {
    return tree_.query(right + 1) - tree_.query(left);
  }

 private:
  BIT tree_;
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end

