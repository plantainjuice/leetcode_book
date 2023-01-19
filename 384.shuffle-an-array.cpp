/*
 * @lc app=leetcode id=384 lang=cpp
 *
 * [384] Shuffle an Array
 */

// @lc code=start
class Solution {
 public:
  Solution(vector<int>& nums) : ori_(nums), nums_(nums) {}

  vector<int> reset() { return ori_; }

  vector<int> shuffle() {
    for (int i = 0; i < nums_.size(); ++i) {
      int tmp = i + (rand() % (nums_.size() - i));
      swap(nums_[tmp], nums_[i]);
    }

    return nums_;
  }

 private:
  vector<int> ori_;
  vector<int> nums_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end
