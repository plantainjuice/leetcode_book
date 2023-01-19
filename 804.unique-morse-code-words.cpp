/*
 * @lc app=leetcode id=804 lang=cpp
 *
 * [804] Unique Morse Code Words
 */

// @lc code=start
class Solution {
 public:
  vector<string> V = {".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",
                      "....", "..",   ".---", "-.-",  ".-..", "--",   "-.",
                      "---",  ".--.", "--.-", ".-.",  "...",  "-",    "..-",
                      "...-", ".--",  "-..-", "-.--", "--.."};

  int uniqueMorseRepresentations(vector<string>& W) {
    auto morse_enc = [&](const string& s) -> string {
      string r;
      for (char c : s) r += V[c - 'a'];
      return r;
    };

    unordered_set<string> S;
    for (string& w : W) S.insert(morse_enc(w));

    return S.size();
  }
};
// @lc code=end

