/*
 * @lc app=leetcode id=385 lang=cpp
 *
 * [385] Mini Parser
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer
 * to it. void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
 public:
  // NestedInteger deserialize(string s) {
  NestedInteger deserialize(const string& s) {
    if (s == "[]") return NestedInteger();

    if (s[0] != '[') return NestedInteger(stoi(s));

    NestedInteger nested;
    int cnt = 0;
    vector<int> dotIndex;
    for (int i = 1; i < s.size(); ++i) {
      if (s[i] == ',' && cnt == 0) dotIndex.push_back(i);

      if (s[i] == '[')
        ++cnt;
      else if (s[i] == ']')
        --cnt;
    }
    dotIndex.push_back(s.size() - 1);

    int last = 0;
    for (int dot : dotIndex) {
      nested.add(deserialize(s.substr(last + 1, dot - last - 1)));
      last = dot;
    }

    return nested;
  }
};
// @lc code=end
