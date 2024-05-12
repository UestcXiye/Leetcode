/*
 * @lc app=leetcode.cn id=371 lang=cpp
 *
 * [371] 两整数之和
 */

// @lc code=start
class Solution
{
public:
    int getSum(int a, int b)
    {
        while (b)
        {
            // 相加各位的值，不算进位
            int temp = a ^ b;
            // 计算进位值
            b = (a & b) << 1;
            a = temp;
        }
        // 进位为 0，即 a 为最终的求和结果
        return a;
    }
};
// @lc code=end
