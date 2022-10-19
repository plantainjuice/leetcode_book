/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */

// @lc code=start
class Solution {
 public:
  vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> m;
    for (string& word : words) m[word] += 1;

    auto cmp = [](const pair<int, string>& a,
                  const pair<int, string>& b) -> bool {
      if (a.first != b.first) return a.first > b.first;
      return a.second < b.second;
    };

    priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> pq(cmp);
    for (auto it = m.begin(); it != m.end(); ++it) {
      pq.push(make_pair(it->second, it->first));
      if (pq.size() > k) pq.pop();
    }
    vector<string> res;
    while (!pq.empty()) {
      res.insert(res.begin(), pq.top().second);
      pq.pop();
    }
    return res;
  }
};
// @lc code=end

