/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
#include <vector>

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;

        vector<int> in(n, 0);
        vector<vector<int>> frees(n);
        vector<int> next;

        for (auto& prereq : prerequisites) {
            in[prereq[0]]++;
            frees[prereq[1]].push_back(prereq[0]);
        }

        for (int c = 0; c < in.size(); ++c) {
          if (in[c] == 0) {
            next.push_back(c);
          }
        }

        int i = 0;
        while (i < next.size()) {
          int c = next[i];

          for (int v : frees[c]) {
            in[v]--;

            if (in[v] == 0) {
              next.push_back(v);
            }
          }

          ++i;
        }

        return next.size() == n;
    }
};
// @lc code=end

