/*
 * @lc app=leetcode.cn id=2427 lang=cpp
 *
 * [2427] 公因子的数目
 */

// @lc code=start
class Solution
{
public:
    int commonFactors(int a, int b)
    {
        int count = 0;
        int n = min(a, b);
        while (n)
        {
            if (a % n == 0 && b % n == 0)
                count++;
            n--;
        }
        return count;
    }
};
// @lc code=end
