/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
class MedianFinder {
 public:
  MedianFinder() {}

  void addNum(int num) {
    small.push(num);
    large.push(small.top());
    small.pop();

    if (small.size() < large.size()) {
      small.push(large.top());
      large.pop();
    }
  }

  double findMedian() {
    if (small.size() > large.size()) {
      return small.top();
    }

    return double(small.top() + large.top()) / 2;
  }

 private:
  priority_queue<int> small;
  priority_queue<int, vector<int>, greater<int>> large;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
