/*
 * @lc app=leetcode id=1552 lang=cpp
 *
 * [1552] Magnetic Force Between Two Balls
 */

// @lc code=start
class Solution {
 public:
  int maxDistance(vector<int>& position, int m) {
    sort(position.begin(), position.end());

    int l = 1, r = position.back() - position.front();

    while (l < r) {
      int mid = (l + r) / 2 + 1;
      if (count(position, mid) >= m) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }

    return l;
  }

  int count(vector<int>& position, int force) {
    int cnt = 1;
    int last = position[0];

    for (int i = 1; i < position.size(); ++i) {
      if (position[i] - last >= force) {
        ++cnt;
        last = position[i];
      }
    }

    return cnt;
  }
};
// @lc code=end

