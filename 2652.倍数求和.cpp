/*
 * @lc app=leetcode.cn id=2652 lang=cpp
 *
 * [2652] 倍数求和
 */

// @lc code=start
class Solution
{
public:
    int sumOfMultiples(int n)
    {
        int sum = 0;
        for (int i = 1; i <= n; i++)
            if (i % 3 == 0 || i % 5 == 0 || i % 7 == 0)
                sum += i;
        return sum;
    }
};
// @lc code=end
