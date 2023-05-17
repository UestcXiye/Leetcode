/*
 * @lc app=leetcode.cn id=2180 lang=cpp
 *
 * [2180] 统计各位数字之和为偶数的整数个数
 */

// @lc code=start
class Solution
{
public:
    int countEven(int num)
    {
        int ans = 0;
        for (int i = 1; i <= num; i++)
        {
            int number = i;
            int sum = 0;
            while (number > 0)
            {
                sum += number % 10;
                number /= 10;
            }
            if (sum % 2 == 0)
                ans++;
        }
        return ans;
    }
};
// @lc code=end
