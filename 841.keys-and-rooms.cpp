/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 */

// @lc code=start
class Solution {
 public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    vector<bool> visited(rooms.size(), false);

    dfs(rooms, 0, visited);

    for (bool v : visited) {
      if (v == false) return false;
    }

    return true;
  }

 private:
  void dfs(vector<vector<int>>& rooms, int key, vector<bool>& visited) {
    // has been visited
    if(visited[key] == true) return;

    visited[key] = true;

    for(int k : rooms[key]) {
      dfs(rooms, k, visited);
    }
  }
};
// @lc code=end

