/*
 * @lc app=leetcode.cn id=1736 lang=cpp
 *
 * [1736] 替换隐藏数字得到的最晚时间
 */

// @lc code=start
class Solution
{
public:
    string maximumTime(string time)
    {
        for (int i = 0; i < 5; i++)
        {
            if (time[i] == '?')
            {
                if (i == 0)
                {
                    if (time[1] >= '4' && time[1] <= '9')
                        time[i] = '1';
                    else if (time[1] >= 0 && time[1] <= '3')
                        time[i] = '2';
                    else
                        time[i] = '2';
                }
                else if (i == 1)
                {
                    if (time[0] == '2' || time[0] == '?')
                        time[i] = '3';
                    else
                        time[i] = '9';
                }
                else if (i == 3)
                    time[i] = '5';
                else
                    time[i] = '9';
            }
        }
        return time;
    }
};
// @lc code=end
