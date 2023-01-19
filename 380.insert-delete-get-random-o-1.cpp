/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */

// @lc code=start
class RandomizedSet {
 public:
  RandomizedSet() {}

  bool insert(int val) {
    if (elem_2_index_.find(val) != elem_2_index_.end()) return false;

    elem_.push_back(val);
    elem_2_index_[val] = elem_.size() - 1;

    return true;
  }

  bool remove(int val) {
    if (elem_2_index_.find(val) == elem_2_index_.end()) return false;

    int index = elem_2_index_[val];

    int last = elem_.back();
    elem_[index] = last;
    elem_.pop_back();

    elem_2_index_[last] = index;

    elem_2_index_.erase(val);

    return true;
  }

  int getRandom() { return elem_[rand() % elem_.size()]; }

 private:
  vector<int> elem_;
  unordered_map<int, int> elem_2_index_;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end
