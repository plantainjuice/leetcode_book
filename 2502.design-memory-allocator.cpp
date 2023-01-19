/*
 * @lc app=leetcode id=2502 lang=cpp
 *
 * [2502] Design Memory Allocator
 */

// @lc code=start
class Allocator {
 public:
  Allocator(int n) : mem_(n) {}

  int allocate(int size, int mID) {
    int j = 0;
    int count = 0;
    bool find = false;

    for (int i = 0; i < mem_.size(); ++i) {
      if (mem_[i] != 0) {
        j = i + 1;
        count = 0;
        continue;
      }

      ++count;

      if (count == size) {
        find = true;
        break;
      }
    }

    if (find == false) return -1;

    for (int k = j; k < j + size; ++k) mem_[k] = mID;

    return j;
  }

  int free(int mID) {
    int count = 0;
    for (int i = 0; i < mem_.size(); ++i) {
      if (mem_[i] == mID) {
        ++count;
        mem_[i] = 0;
      }
    }

    return count;
  }

 private:
  vector<int> mem_;
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */
// @lc code=end
