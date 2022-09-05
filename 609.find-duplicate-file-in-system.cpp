/*
 * @lc app=leetcode id=609 lang=cpp
 *
 * [609] Find Duplicate File in System
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> files; // content -> files

        for (string& path : paths) {
            int i = 0;
            string dir = "";
            while(path[i] != ' ') dir += path[i++];
            while(i < path.size()) {
                string filename;
                string content;
                ++i;  // skip ' '
                while(path[i] != '(') filename += path[i++];
                ++i;  // skip '('
                while(path[i] != ')') content += path[i++];
                ++i;  // skip ')'

                files[content].push_back(dir + "/" + filename);
            }
        }

        vector<vector<string>> ans;
        for (auto& kv : files) {
          if (kv.second.size() > 1) ans.push_back(move(kv.second));
        }

        return ans;
    }
};
// @lc code=end

