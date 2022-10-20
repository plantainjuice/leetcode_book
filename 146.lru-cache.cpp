/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
class LRUCache {
 public:
  LRUCache(int capacity) : capacity_(capacity) {
     ios_base::sync_with_stdio(false);
     cin.tie(nullptr);
     cout.tie(nullptr);
  }

  int get(int key) {
    // 1. try get from map
    if (m_.find(key) == m_.end()) return -1;

    // 2. update list
    auto iter = m_[key];
    int val = iter->second;
    l_.erase(iter);
    iter = l_.insert(l_.begin(), {key, val});
    m_[key] = iter;

    return val;
  }

  void put(int key, int value) {
    // 1. check existence
    if (m_.find(key) == m_.end()) {

      // 2 check capacity, if full, erase the oldest one
      if (l_.size() == capacity_) {
        m_.erase(l_.back().first);
        l_.pop_back();
      }

      auto iter = l_.insert(l_.begin(), {key, value});
      m_[key] = iter;

      return;
    }

    // 3. if exist
    auto iter = m_[key];
    l_.erase(iter);
    iter = l_.insert(l_.begin(), {key, value});
    m_[key] = iter;
  }

 private:
  int capacity_;
  list<pair<int, int>> l_;
  unordered_map<int, list<pair<int, int>>::iterator> m_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

