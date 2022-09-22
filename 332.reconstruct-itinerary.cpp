/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */

// @lc code=start
class Solution {
 public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    // <from, <to, cnt>>
    map<string, map<string, int>> targets;

    for (vector<string>& t : tickets) targets[t[0]][t[1]]++;

    vector<string> path;
    path.push_back("JFK");
    backtrack(tickets.size(), targets, path);

    return path;
  }

 private:
  bool backtrack(const int N, map<string, map<string, int>>& targets,
                 vector<string>& path) {
    if (path.size() == N + 1) return true;

    for (pair<const string, int>& target : targets[path[path.size() - 1]]) {
      if (target.second > 0) {
        target.second--;
        path.push_back(target.first);
        if (backtrack(N, targets, path)) return true;
        path.pop_back();
        target.second++;
      }
    }
    return false;
  }
};
// @lc code=end

