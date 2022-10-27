/*
 * @lc app=leetcode id=721 lang=cpp
 *
 * [721] Accounts Merge
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> parents;
        unordered_map<string, string> owners;

        for(auto& act : accounts) {
            for(int i = 1; i < act.size(); ++i) {
                parents[act[i]] = act[i];
                owners[act[i]] = act[0];
            }
        }

        function<string(const string&)> find = [&] (const string& s) -> string {
            return parents[s] == s ? s : find(parents[s]);
        };

        // build union set
        for(auto& act : accounts) {
            string p = find(act[1]);
            for(int i = 2; i < act.size(); ++i) {
                parents[find(act[i])] = p;
            }
        }

        map<string, set<string>> unions;
        for(auto& act : accounts) {
            for (int i = 1; i < act.size(); i++) {
                unions[find(act[i])].insert(act[i]);
            }
        }

        // make return
        vector<vector<string>> ans;
        for(auto kv : unions) {
            vector<string> emails = {kv.second.begin(), kv.second.end()};
            emails.insert(emails.begin(), owners[kv.first]);
            ans.push_back(emails);
        }

        return ans;
    }
};
// @lc code=end

