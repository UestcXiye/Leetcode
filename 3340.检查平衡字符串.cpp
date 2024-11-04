/*
 * @lc app=leetcode.cn id=3340 lang=cpp
 *
 * [3340] 检查平衡字符串
 */

// @lc code=start
class Solution
{
public:
    bool isBalanced(string num)
    {
        int oddSum = 0, evenSum = 0;
        for (int i = 0; i < num.length(); i++)
            (i % 2 ? oddSum : evenSum) += (num[i] - '0');

        return oddSum == evenSum;
    }
};
// @lc code=end
