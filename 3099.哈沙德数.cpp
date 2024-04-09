/*
 * @lc app=leetcode.cn id=3099 lang=cpp
 *
 * [3099] 哈沙德数
 */

// @lc code=start
class Solution
{
private:
    int sumOfTheDigits(int x)
    {
        int sum = 0;
        while (x)
        {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

public:
    int sumOfTheDigitsOfHarshadNumber(int x)
    {
        int dsum = sumOfTheDigits(x);
        if (x % dsum == 0)
            return dsum;
        return -1;
    }
};
// @lc code=end
