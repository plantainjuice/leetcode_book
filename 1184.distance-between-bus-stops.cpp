/*
 * @lc app=leetcode id=1184 lang=cpp
 *
 * [1184] Distance Between Bus Stops
 */

// @lc code=start
class Solution {
 public:
  int distanceBetweenBusStops(vector<int>& distance, int start,
                              int destination) {
    if (start == destination) return 0;

    int n = distance.size();
    if (start > destination) swap(start, destination);

    int sum = accumulate(distance.begin(), distance.end(), 0);
    int part1 = sumOfArray(distance, start, destination);
    int part2 = sum - part1;
    return min(part1, part2);
  }

 private:
  int sumOfArray(vector<int>& distance, int begin, int end) {
    int sum = 0;
    for(int i = begin; i < end; ++i) {
        sum += distance[i];
    }

    return sum;
  }
};
// @lc code=end

