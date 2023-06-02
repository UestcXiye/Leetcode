/*
 * @lc app=leetcode.cn id=1716 lang=cpp
 *
 * [1716] 计算力扣银行的钱
 */

// @lc code=start
class Solution
{
public:
    int totalMoney(int n)
    {
        int sum = 0;
        int week = 0, day = 1;
        while (n--)
        {
            sum += week + day;
            day++;
            if (day == 8)
            {
                day = 1;
                week++;
            }
        }
        return sum;
    }
};
// @lc code=end
