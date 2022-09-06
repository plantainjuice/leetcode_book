/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 */

// @lc code=start
class BIT {
 public:
  BIT(int n) : bit_(n + 1, 0) {}

  void update(int i, int val) {
    while (i <= bit_.size()) {
      bit_[i] += val;
      i += lower_bit(i);
    }
  }

  int query(int i) {  // returns number of elements in [0...i]
    int res = 0;
    while (i > 0) {
      res += bit_[i];
      i -= lower_bit(i);
    }
    return res;
  }

 private:
  int lower_bit(int i){return i & -i;}

  vector<int> bit_;
};
class Solution {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    const int MAX = 1e4 + 1;  // max range
    for_each(begin(nums), end(nums), [](int& n) {
      n += MAX;
    });  // converting range from [-10^4,10^4] to [0,2*10^4]
    BIT T(2 * MAX);
    for (int i = nums.size() - 1; ~i; i--) {
      T.update(nums[i], 1);
      nums[i] = T.query(nums[i] - 1);
    }
    return nums;
  }
};
// @lc code=end

