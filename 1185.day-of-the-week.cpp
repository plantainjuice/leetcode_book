/*
 * @lc app=leetcode id=1185 lang=cpp
 *
 * [1185] Day of the Week
 */

// @lc code=start
class Solution {
public:
 vector<string> days = {"Thursday", "Friday",  "Saturday", "Sunday",
                        "Monday",   "Tuesday", "Wednesday"};

 vector<int> month_days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

 string dayOfTheWeek(int day, int month, int year) {
  int d_day = day - 1;
  int d_month = month - 1;
  int d_year = year - 1970;

  // since 1970.1.1 is thursday
  int total_day = 0;

  // day
  total_day += d_day;

  // month
  for (int i = 0; i < d_month; ++i)
    total_day += month_days[i];

  // year
  total_day += 365 * d_year;

  auto is_leap_year = [] (int year) -> bool {
    if(year % 400 == 0) return true;
    if(year % 100 == 0) return false;
    if(year % 4 == 0) return true;
    return false;
  };

  // leap year
  for (int y = 1970; y < year; ++y)
    if (is_leap_year(y)) total_day += 1;

  if(is_leap_year(year) && month >= 3) total_day += 1;

  return days[total_day % 7];
 }
};
// @lc code=end

