/*
 * @lc app=leetcode.cn id=1837 lang=cpp
 *
 * [1837] K 进制表示下的各位数字总和
 */

// @lc code=start
class Solution
{
public:
    int sumBase(int n, int k)
    {
        int sum = 0;
        while (n)
        {
            sum += n % k;
            n /= k;
        }
        return sum;
    }
};
// @lc code=end
