/*
 * @lc app=leetcode id=218 lang=cpp
 *
 * [218] The Skyline Problem
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    // step 1: sort
    multimap<int, int> lines;
    for (const vector<int>& building : buildings) {
      lines.emplace(building[0], building[2]);   // in
      lines.emplace(building[1], -building[2]);  // out
    }

    // step 2: sweeping with the lines
    multiset<int> heights = {0};
    map<int, int> corners;

    for (const pair<int, int>& line : lines) {
      if (line.second > 0) {
        heights.insert(line.second);
      } else {
        // heights.erase(-line.second); // can not erase this, it will erase all val equals `-line.second`
        heights.erase(heights.find(-line.second));
      }

      int cur_max_y = *heights.rbegin();
      corners[line.first] = cur_max_y;
    }

    // step 3: remove the duplication
    vector<vector<int>> ans;
    map<int, int>::iterator it = corners.begin();
    ans.push_back({it->first, it->second});

    map<int, int>::iterator last_it = it++;
    while (it != corners.end()) {
      if (it->second != last_it->second) {
        ans.push_back({it->first, it->second});
      } 

      last_it = it;
      ++it;
    }
    return ans;
  }
};
// @lc code=end

