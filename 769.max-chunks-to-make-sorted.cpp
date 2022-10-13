/*
 * @lc app=leetcode id=769 lang=cpp
 *
 * [769] Max Chunks To Make Sorted
 */

// @lc code=start
class Solution {
 public:
   int maxChunksToSorted(vector<int>& arr) {
    int n = arr.size();

    int chunks = 0;
    int mx = 0;

    for (int i = 0; i < n; ++i) {
      mx = max(mx, arr[i]);
      if (mx == i) ++chunks;
    }

    return chunks;
  }

//   int maxChunksToSorted(vector<int>& arr) {
//     int n = arr.size();

//     vector<int> partitions(n, 1);
//     auto merge = [&](int l, int h) {
//       for (int i = l + 1; i <= h; ++i) partitions[i] = 0;
//     };

//     for (int i = 0; i < n; ++i) {
//       if (arr[i] != i) {
//         int l = min(arr[i], i);
//         int h = max(arr[i], i);
//         merge(l, h);
//       }
//     }

//     return accumulate(partitions.begin(), partitions.end(), 0);
//   }
};
// @lc code=end

