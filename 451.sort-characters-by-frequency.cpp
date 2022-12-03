/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 */

// @lc code=start
class Solution {
 public:
  string frequencySort(string s) {
    unordered_map<char, int> m;
    for (char c : s) ++m[c];

    auto cmp = [](pair<char, int>& a, pair<char, int>& b) -> bool {
      return a.second < b.second;
    };

    priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(cmp);

    for (auto kv : m) {
      pq.push(kv);
    }

    stringstream ss;
    while (!pq.empty()) {
      pair<char, int> it = pq.top();
      pq.pop();

      ss << string(it.second, it.first);
    }

    return ss.str();
  }
};
// @lc code=end
