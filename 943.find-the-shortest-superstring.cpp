/*
 * @lc app=leetcode id=943 lang=cpp
 *
 * [943] Find the Shortest Superstring
 */

// @lc code=start
class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        int n = A.size(); 
        order = vector<int>(n);
        overlap = vector<vector<int>>(n, vector<int>(n));

        // Step1: preprocessing to get the overlapping matrix info for every pair of strings.
        calculateOverlapInfo(A, n);
        
        // Step2: dfs enumerate of the n! different combinations to get the minimum length possible
        dfsHelper(A, 0, 0, 0);

        // Step3: construct the shortest super string using info calculated before
        string shortestSuperStr = constructShortestSuperStr(A, n);

        return shortestSuperStr;
    }

private:
    int mn = INT_MAX;
    vector<vector<int>> overlap;
    vector<int> order;
    vector<int> best_order;

    void calculateOverlapInfo(vector<string>& A, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue; // no need to consider two same words
                }
                for (int k = min(A[i].size(), A[j].size()); k > 0; k--) {
                    // Check A[i]'s last k chars are same with the first k chars of A[j] or not
                    if (A[i].substr(A[i].size() - k) == A[j].substr(0, k)) {
                        overlap[i][j] = k;
                        break;
                    }
                }
            }
        }
    }
    
    void dfsHelper(vector<string>& A, int cur, int used, int curLen) {
        // Pruning, large total len cannot be an answer, early abort
        if (curLen >= mn) {
            return;
        }
        // Note: here only smaller total len combination reach here, so we can replace with new curLen directly
        if (cur == A.size()) {
            mn = curLen;
            best_order = order;
            return;
        }

        for (int i = 0; i < A.size(); i++) {
            if (used & (1 << i)) {
                continue;
            }
            order[cur] = i;
            int nextLen = (cur == 0) ? A[i].size() : curLen + A[i].size() - overlap[order[cur - 1]][i];
            dfsHelper(A, cur + 1, used | (1 << i), nextLen);
        }
    }

    string constructShortestSuperStr(vector<string>& A, int n) {
        string res = A[best_order[0]];
        for (int k = 1; k < n; k++) {
            int i = best_order[k - 1];
            int j = best_order[k];
            // Only add the non-overlapping substr of A[j] to res, since
            // the prefix has been added previously
            res += A[j].substr(overlap[i][j]);
        }

        return res;
    }
};
// @lc code=end

