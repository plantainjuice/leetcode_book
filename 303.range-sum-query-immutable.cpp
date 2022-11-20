/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */

// @lc code=start
class NumArray {
 public:
  NumArray(vector<int>& nums) {
    int sum = 0;

    for (int i = 0; i < nums.size(); ++i) sums_.push_back(sum += nums[i]);
  }

  int sumRange(int left, int right) {
    if (left == 0) return sums_[right];

    return sums_[right] - sums_[left - 1];
  }

 private:
  vector<int> sums_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end
