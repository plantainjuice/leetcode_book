/*
 * @lc app=leetcode id=306 lang=cpp
 *
 * [306] Additive Number
 */

// @lc code=start
class Solution {
 public:
  bool isAdditiveNumber(string num) {
    for (int i = 1; i <= num.size(); ++i) {
      for (int j = 1; i + j <= num.size(); ++j) {
        if (additive(num.substr(0, i), num.substr(i, j), num.substr(i + j)))
          return true;
      }
    }

    return false;
  }

 private:
  bool additive(const string& s1, const string& s2, const string& rest) {
    auto isValid = [](const string& s) {
      if (s.length() > 1 && s[0] == '0') return false;
      return true;
    };

    if (!isValid(s1) || !isValid((s2))) return false;

    string s3 = add(s1, s2);
    const int l3 = s3.size();

    if (rest.substr(0, l3) != s3) return false;
    if (rest.size() == l3) return true;

    return additive(s2, s3, rest.substr(l3));
  }

  string add(const string& s1, const string& s2) {
    const int l1 = s1.size(), l2 = s2.size();
    string s3(max(l1, l2) + 1, '0');
    for (int i = 0; i < s3.size(); ++i) {
      int n1 = i < l1 ? s1[l1 - i - 1] - '0' : 0;
      int n2 = i < l2 ? s2[l2 - i - 1] - '0' : 0;
      s3[i] += n1 + n2;
      if (s3[i] > '9') {
        s3[i] -= 10;
        s3[i + 1] += 1;
      }
    }

    while (s3.back() == '0' && s3.size() > 1) s3.pop_back();
    return string{s3.rbegin(), s3.rend()};
  }
};
// @lc code=end

