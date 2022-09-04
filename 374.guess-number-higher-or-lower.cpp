/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
 public:
  int guessNumber(int n) {
    int l = 1;
    int h = n;

    while (true) {
      int mid = (h - l) / 2 + l;

      int g = guess(mid);

      if (g == 0)
        return mid;
      else if (g == -1)
        h = mid - 1;
      else
        l = mid + 1;
    }

    // never arrive
    return -1;
  }
};
// @lc code=end

