/*
 * @lc app=leetcode id=1703 lang=cpp
 *
 * [1703] Minimum Adjacent Swaps for K Consecutive Ones
 */

// @lc code=start
class Solution {
 public:
  int minMoves(vector<int>& n, int k) {
    if (k == 1) return 0;

    vector<int> v;
    for (int i = 0; i < n.size(); i++) {
      if (n[i] == 1) v.push_back(i);
    }

    long ret = 1e18;
    long presum = 0, postsum = 0;
    for (int i = 0; i < k / 2; i++) {
      presum += v[i];
    }
    for (int i = k / 2; i < k; i++) {
      postsum += v[i];
    }

    if (k % 2) postsum -= v[k / 2];
    ret = min(ret, (postsum - presum));
    for (int i = k; i < v.size(); i++) {
      int mid = (i - k + 1 + i) / 2;
      postsum += v[i];
      presum -= v[i - k];
      if (k % 2) {
        presum += v[mid - 1];
        postsum -= v[mid];
      } else {
        presum += v[mid];
        postsum -= v[mid];
      }
      ret = min(ret, postsum - presum);
    }

    while (k > 1) {
      ret -= (k - 1);
      k -= 2;
    }

    return ret;
  }
};
;
// @lc code=end
