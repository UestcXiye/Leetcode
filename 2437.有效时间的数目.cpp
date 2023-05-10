/*
 * @lc app=leetcode.cn id=2437 lang=cpp
 *
 * [2437] 有效时间的数目
 */

// @lc code=start
class Solution
{
public:
    int countTime(string time)
    {
        int answer = 1;

        if (time[0] == '?' && time[1] == '?')
            answer *= 24;
        if (time[0] != '?' && time[1] == '?')
        {
            if (time[0] == '2')
                answer *= 4;
            else
                answer *= 10;
        }
        if (time[0] == '?' && time[1] != '?')
        {
            if (time[1] >= '0' && time[1] <= '3')
                answer *= 3;
            else
                answer *= 2;
        }

        // if (time[3] == '?' && time[4] == '?')
        //     answer *= 60;
        // if (time[3] != '?' && time[4] == '?')
        //     answer *= 10;
        // if (time[3] == '?' && time[4] != '?')
        //     answer *= 6;

        if (time[3] == '?') answer *= 6;
        if (time[4] == '?') answer *= 10;

        return answer;
    }
};
// @lc code=end
