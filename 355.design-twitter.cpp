/*
 * @lc app=leetcode id=355 lang=cpp
 *
 * [355] Design Twitter
 */

// @lc code=start
#include <set>

class Twitter {
 public:
  Twitter() {}

  void postTweet(int userId, int tweetId) {
    tweets_[userId].push_back({global_time++, tweetId});

    if (tweets_[userId].size() > 10) tweets_[userId].pop_front();
  }

  vector<int> getNewsFeed(int userId) {
    vector<int> feeds;

    // sort by time
    priority_queue<pair<int, int>> filter;

    // self tweets
    for (auto& kv : tweets_[userId]) {
      filter.push(kv);
    }

    // followers tweets
    for (int followeeId : follow_relation_[userId]) {
      for (auto& kv : tweets_[followeeId]) {
        filter.push(kv);
      }
    }

    // get newest 10 posts
    while (!filter.empty()) {
      int post = filter.top().second;
      filter.pop();

      feeds.push_back(post);
      if (feeds.size() >= 10) break;
    }

    return feeds;
  }

  void follow(int followerId, int followeeId) {
    follow_relation_[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    follow_relation_[followerId].erase(followeeId);
  }

 private:
  int global_time = 0;
  map<int, deque<pair<int, int>>> tweets_;
  map<int, set<int>> follow_relation_;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end

