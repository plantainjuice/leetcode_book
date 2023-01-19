/*
 * @lc app=leetcode id=535 lang=cpp
 *
 * [535] Encode and Decode TinyURL
 */

// @lc code=start
class Solution {
 public:
  Solution()
      : base_("https://tinyurl.com/"),
        dict_(
            "abcdefghijklmnopqrstuvwxyzAbCDEFGHIJKLMNOPQRSTUVWXYZ0123456789") {
    srand(time(0));
  }

  string getCode() {
    string code = "";

    while (1) {
      for (int i = 0; i < 6; i++) code += dict_[rand() % 62];
      if (!codeToUrl_.count(code)) break;
      code = "";
    }

    return code;
  }

  // Encodes a URL to a shortened URL.
  string encode(string longUrl) {
    if (UrlToCode_.count(longUrl)) return base_ + UrlToCode_[longUrl];

    string code = getCode();

    string encoded = base_ + code;

    UrlToCode_[longUrl] = code;
    codeToUrl_[encoded] = longUrl;
    return encoded;
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) { return codeToUrl_[shortUrl]; }

 private:
  unordered_map<string, string> UrlToCode_, codeToUrl_;
  string dict_, base_;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
// @lc code=end
