/*
 * @lc app=leetcode id=299 lang=cpp
 *
 * [299] Bulls and Cows
 */

// @lc code=start
#include <string>
#include <vector>

class Solution {
 public:
  string getHint(string secret, string guess) {
    int A = 0, B = 0;
    vector<int> cnt(10, 0);

    for (int i = 0; i < secret.size(); ++i) {
      const char s = secret[i];
      const char g = guess[i];

      if (s == g) {
        ++A;
        continue;
      }

      ++cnt[s - '0'];
    }

    for (int i = 0; i < secret.size(); ++i) {
      const char s = secret[i];
      const char g = guess[i];

      if(s == g) continue;

      if (cnt[g - '0']) {
        ++B;
		--cnt[g - '0'];
      }
    }

	return to_string(A) + "A" + to_string(B) + "B";
  }
};
// @lc code=end

