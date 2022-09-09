/*
 * @lc app=leetcode id=398 lang=cpp
 *
 * [398] Random Pick Index
 */

// @lc code=start
class Solution {
 private:
  unordered_map<int, vector<int>> map;

 public:
  Solution(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
      map[nums[i]].push_back(i);
    }
  }

  int pick(int target) {
    vector<int> random = map[target];
    return random[rand() % random.size()];
  }
};
// class Solution {
//  // https://leetcode.com/problems/random-pick-index/discuss/88071/C%2B%2B_Time%3A-O(n)-Space%3A-O(n)_116ms_96.41_with-clear-explanation-by-probability
//  public:
//   Solution(vector<int>& nums) : nums_(nums) {}

//   int pick(int target) {
//     int c = 0, ans = 0;

//     for (int i = 0; i < nums_.size(); ++i) {
//       if (nums_[i] != target) continue;

//       ++c;
//       if (random() % c == 0)  // prob: 1 / c
//         ans = i;
//     }

//     return ans;
//   }

//  private:
//   const vector<int>& nums_;
// };

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end

