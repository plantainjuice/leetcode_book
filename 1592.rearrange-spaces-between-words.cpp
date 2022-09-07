/*
 * @lc app=leetcode id=1592 lang=cpp
 *
 * [1592] Rearrange Spaces Between Words
 */

// @lc code=start
class Solution {
 public:
  // string reorderSpaces(string text) {
  string reorderSpaces(const string& text) {
    int space_cnt = 0;
    int word_cnt = 0;
    char last = ' ';
    for (char c : text) {
      if (c == ' ') ++space_cnt;
      else if (c != ' ' && last == ' ') ++word_cnt;
      last = c;
    }
    // edge case
    if (space_cnt == 0 || word_cnt == 0) return text;
    int inter_space_num = (word_cnt == 1 ? 0 : space_cnt / (word_cnt - 1));
    int tail_space_num = (word_cnt == 1 ? space_cnt : space_cnt % (word_cnt - 1));

    string ans;
    ans.resize(text.size());

    int cur = 0;
    int next_letter = 0;
    while (next_letter < text.size()) {
      // find next word
      if (text[next_letter] == ' ') {
        ++next_letter;
        continue;
      }

      // copy word
      while (next_letter < text.size() && text[next_letter] != ' ') {
        ans[cur++] = text[next_letter++];
      }

      if ((cur + inter_space_num) >= ans.size()) break;

      // padding spaces
      for (int i = 0; i < inter_space_num; ++i) ans[cur++] = ' ';
    }
    // tail spaces
    for (int i = 0; i < tail_space_num; ++i) ans[cur++] = ' ';
    return ans;
  }
};
// @lc code=end

