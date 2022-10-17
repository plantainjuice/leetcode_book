/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 */

// @lc code=start
class Solution {
 public:
  int totalFruit(vector<int>& fruits) {
    int total = 0;
    int l = 0, h = 1;
    int last = 0;

    set<int> baskets;
    baskets.insert(fruits[0]);

    for (; h < fruits.size(); ++h) {
      if (baskets.size() < 2) {
        if (baskets.find(fruits[h]) == baskets.end()) {
          baskets.insert(fruits[h]);
        }

        if(fruits[h] != fruits[last]) last = h;

        continue;
      }

      if(baskets.find(fruits[h]) == baskets.end()) {
        total = max(total, h - l);

        baskets.clear();
        baskets.insert(fruits[last]);
        baskets.insert(fruits[h]);

        l = last;
      }

      if (fruits[h] != fruits[last]) last = h;
    }

    total = max(total, h - l);

    return total;
  }
};
// @lc code=end

