/*
 * @lc app=leetcode.cn id=1342 lang=cpp
 *
 * [1342] 将数字变成 0 的操作次数
 */

// @lc code=start
class Solution
{
public:
    int numberOfSteps(int num)
    {
        int steps = 0;
        while (num)
        {
            if (num % 2)
                num--;
            else
                num /= 2;
            steps++;
        }
        return steps;
    }
};
// @lc code=end
