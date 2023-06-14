/*
 * @lc app=leetcode.cn id=1360 lang=cpp
 *
 * [1360] 日期之间隔几天
 */

// @lc code=start
class Solution
{
private:
    bool leap_year(int year)
    {
        return ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0));
    }
    int date_to_int(string date)
    {
        int year, month, day;
        sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
        int month_length[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int ans = day - 1;
        while (month != 0)
        {
            --month;
            ans += month_length[month];
            if (month == 2 && leap_year(year))
                ans += 1;
        }
        ans += 365 * (year - 1971);
        ans += (year - 1) / 4 - 1971 / 4;
        ans -= (year - 1) / 100 - 1971 / 100;
        ans += (year - 1) / 400 - 1971 / 400;
        return ans;
    }

public:
    int daysBetweenDates(string date1, string date2)
    {
        return abs(date_to_int(date1) - date_to_int(date2));
    }
};
// @lc code=end
