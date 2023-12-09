/*
 * @lc app=leetcode.cn id=2048 lang=cpp
 *
 * [2048] 下一个更大的数值平衡数
 */

// @lc code=start
class Solution
{
public:
    int nextBeautifulNumber(int n)
    {
        for (int i = n + 1; i <= 1000000000; i++)
            if (isBalancedNumber(i))
                return i;
        return -1;
    }
    // 辅函数 - 判断一个数是否是数值平衡数
    bool isBalancedNumber(int x)
    {
        vector<int> digitCount(10, 0);
        while (x)
        {
            digitCount[x % 10]++;
            x /= 10;
        }
        for (int i = 0; i < 10; i++)
            if (digitCount[i] && digitCount[i] != i)
                return false;
        return true;
    }
};
// @lc code=end
