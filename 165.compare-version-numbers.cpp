/*
 * @lc app=leetcode id=165 lang=cpp
 *
 * [165] Compare Version Numbers
 */

// @lc code=start
#include <vector>

class Solution {
public:
    int compareVersion(string version1, string version2) {
      auto split_version_into_vec = [](const string& ver, vector<int>* output) {
        string tmp = "";
        for (auto c : ver) {
          if (c == '.') {
            output->push_back(stoi(tmp));
            tmp = "";
            continue;
          }

          tmp += c;
        }

        if (tmp != "") {
          output->push_back(stoi(tmp));
        }
      };

      vector<int> v1;
      vector<int> v2;
      split_version_into_vec(version1, &v1);
      split_version_into_vec(version2, &v2);

      int diff = v1.size() - v2.size();

      if (diff > 0)
        while (diff--) v2.push_back(0);
      else
        while (diff++) v1.push_back(0);

      for (int i = 0; i < v1.size(); ++i) {
        if (v1[i] > v2[i]) return 1;
        if (v1[i] < v2[i]) return -1;
      }

      return 0;
    }
};
// @lc code=end

