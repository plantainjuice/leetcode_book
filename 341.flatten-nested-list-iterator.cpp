/*
 * @lc app=leetcode id=341 lang=cpp
 *
 * [341] Flatten Nested List Iterator
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

#include <stack>

class NestedIterator {
 public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    int size = nestedList.size();
    for (int i = size - 1; i >= 0; --i) {
      nodes_.push(nestedList[i]);
    }
  }

  int next() {
    int res = nodes_.top().getInteger();
    nodes_.pop();

    return res;
  }

  bool hasNext() {
    while (nodes_.size() != 0) {
      NestedInteger node = nodes_.top();
      if (node.isInteger()) {
        return true;
      }

      nodes_.pop();

      vector<NestedInteger>& list = node.getList();
      for (int i = list.size() - 1; i >= 0; --i) {
        nodes_.push(list[i]);
      }
    }

    return false;
  }

 private:
  stack<NestedInteger> nodes_;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end

