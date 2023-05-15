/*
 * @lc app=leetcode.cn id=2224 lang=cpp
 *
 * [2224] 转化时间需要的最少操作数
 */

// @lc code=start
// class Solution
// {
// public:
//     int turnToMinute(string time)
//     {
//         const int MINUTE = 60;
//         int hour = stoi(time.substr(0, 2));
//         int minute = stoi(time.substr(3, 2));
//         return MINUTE * hour + minute;
//     }
//     int convertTime(string current, string correct)
//     {
//         if (correct == current)
//             return 0;
//         int ans = 0;
//         int diff = turnToMinute(correct) - turnToMinute(current);
//         while (diff >= 60)
//         {
//             diff -= 60;
//             ans++;
//         }
//         while (diff >= 15)
//         {
//             diff -= 15;
//             ans++;
//         }
//         while (diff >= 5)
//         {
//             diff -= 5;
//             ans++;
//         }
//         while (diff >= 1)
//         {
//             diff -= 1;
//             ans++;
//         }
//         return ans;
//     }
// };
class Solution
{
public:
    int convertTime(string current, string correct)
    {
        int time1 = stoi(current.substr(0, 2)) * 60 + stoi(current.substr(3, 2));
        int time2 = stoi(correct.substr(0, 2)) * 60 + stoi(correct.substr(3, 2));
        int diff = time2 - time1; // 需要增加的分钟数
        int res = 0;
        // 尽可能优先使用增加数值更大的操作
        vector<int> ops = {60, 15, 5, 1};
        for (int t : ops)
        {
            res += diff / t;
            diff %= t;
        }
        return res;
    }
};
// @lc code=end
