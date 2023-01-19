/*
 * @lc app=leetcode id=2250 lang=cpp
 *
 * [2250] Count Number of Rectangles Containing Each Point
 */

// @lc code=start
class Solution {
 public:
  vector<int> countRectangles(vector<vector<int>>& rectangles,
                              vector<vector<int>>& points) {
    vector<int> ans;
    map<int, vector<int>> mappa;
    sort(rectangles.begin(), rectangles.end());
    for (auto& r : rectangles) mappa[r[1]].push_back(r[0]);

    for (auto& p : points) {
      int cnt = 0;

      auto it = mappa.lower_bound(p[1]);

      while (it != mappa.end()) {
        auto it1 = lower_bound((*it).second.begin(), (*it).second.end(), p[0]);

        cnt += (*it).second.end() - it1;
        it++;
      }

      ans.push_back(cnt);
    }

    return ans;
  }
};
// @lc code=end

