/*
 * @lc app=leetcode id=2491 lang=cpp
 *
 * [2491] Divide Players Into Teams of Equal Skill
 */

// @lc code=start
class Solution {
 public:
  long long dividePlayers(vector<int>& skill) {
    sort(skill.begin(), skill.end());

    int n = skill.size();
    int total_skill = skill[0] + skill[n - 1];
    long long chemistry = 0;
    for (int i = 0; i < n / 2; ++i) {
      int p1 = skill[i];
      int p2 = skill[n - i - 1];

      if (p1 + p2 != total_skill) return -1;

      chemistry += p1 * p2;
    }

    return chemistry;
  }
};
// @lc code=end
