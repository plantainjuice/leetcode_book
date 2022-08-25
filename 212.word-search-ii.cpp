/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

// @lc code=start
#include <unordered_set>
#include <vector>
#include <functional>

struct TrieNode  {
    vector<TrieNode*> nodes;
    const string* word;
    TrieNode() : nodes(26), word(nullptr) {}
    ~TrieNode() {
      if (word != nullptr) delete word;
    }
};

class Solution {
 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    unordered_set<string> unq_words(words.begin(), words.end());

    // build the trie
    TrieNode root;
    for (const auto& word : unq_words) {
      TrieNode* cur = &root;
      for (const char& c : word) {
        auto& next = cur->nodes[c - 'a'];
        if (next == nullptr) next = new TrieNode();
        cur = next;
      }

      cur->word = &word;
    }

    const int h = board.size();
    const int w = board[0].size();
    vector<string> ans;

    function<void(TrieNode*, int, int)> walk;
    walk = [&](TrieNode* node, int x, int y) {
      if (x < 0 || y < 0 || x == h || y == w || board[x][y] == '?') return;

      const char cur = board[x][y];
      auto next = node->nodes[cur - 'a'];

      // pruning
      if(next == nullptr) return;

      if (next->word != nullptr) {
        ans.push_back(*next->word);
        next->word = nullptr;
      }

      board[x][y] = '?';

      walk(next, x, y + 1);
      walk(next, x + 1, y);
      walk(next, x, y - 1);
      walk(next, x - 1, y);

      board[x][y] = cur;
    };

    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        walk(&root,  i, j);
      }
    }

    return ans;
  }
};
// @lc code=end

