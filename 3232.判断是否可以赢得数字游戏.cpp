/*
 * @lc app=leetcode.cn id=3232 lang=cpp
 *
 * [3232] 判断是否可以赢得数字游戏
 */

// @lc code=start
class Solution
{
public:
    bool canAliceWin(vector<int> &nums)
    {
        int sum1 = 0, sum2 = 0;
        for (int &num : nums)
        {
            if (num / 10)
                sum2 += num;
            else
                sum1 += num;
        }
        return sum1 != sum2;
    }
};
// @lc code=end
