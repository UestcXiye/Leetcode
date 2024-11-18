/*
 * @lc app=leetcode.cn id=3345 lang=cpp
 *
 * [3345] 最小可整除数位乘积 I
 */

// @lc code=start
class Solution
{
public:
    int smallestNumber(int n, int t)
    {
        for (int i = n; i <= n + 10; i++)
            if (digitMultSum(i) % t == 0)
                return i;
        return -1;
    }
    // 辅函数 - 求数字 x 的各数位之积
    int digitMultSum(int x)
    {
        int res = 1;
        while (x)
        {
            res *= (x % 10);
            x /= 10;
        }
        return res;
    }
};
// @lc code=end
