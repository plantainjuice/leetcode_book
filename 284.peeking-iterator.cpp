/*
 * @lc app=leetcode id=284 lang=cpp
 *
 * [284] Peeking Iterator
 */

// @lc code=start
/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
 public:
  PeekingIterator(const vector<int>& nums) : Iterator(nums) {
    has_next_ = Iterator::hasNext();
    if (has_next_) next_ = Iterator::next();
  }

  // Returns the next element in the iteration without advancing the iterator.
  int peek() {
	return next_;
  }

  // hasNext() and next() should behave the same as in the Iterator interface.
  // Override them if needed.
  int next() {
	int tmp = next_;
    has_next_ = Iterator::hasNext();
    if (has_next_) next_ = Iterator::next();
	return tmp;
  }

  bool hasNext() const {
	return has_next_;
  }

 private:
  int next_;
  bool has_next_;
};
// @lc code=end

