/*
 * @lc app=leetcode.cn id=441 lang=cpp
 *
 * [441] 排列硬币
 */

// @lc code=start
class Solution
{
public:
    int arrangeCoins(int n)
    {
        int col = 0;
        long long sum = 0;
        while (sum < n)
        {
            col++;
            sum += col;
        }
        if (n < sum)
            col--;
        return col;
    }
};
// @lc code=end
