/*
 * @lc app=leetcode.cn id=762 lang=cpp
 *
 * [762] 二进制表示中质数个计算置位
 */

// @lc code=start
class Solution
{
public:
    int countPrimeSetBits(int left, int right)
    {
        int count = 0;
        for (int i = left; i <= right; i++)
            if (isPrime(countOne(i)))
                count++;
        return count;
    }
    // 辅函数 - 计算置位位数
    int countOne(int x)
    {
        int count = 0;
        while (x)
        {
            count += x % 2;
            x /= 2;
        }
        return count;
    }
    // 辅函数 - 判断质数
    bool isPrime(int x)
    {
        if (x < 2)
            return false;
        for (int i = 2; i * i <= x; i++)
            if (x % i == 0)
                return false;
        return true;
    }
};
// @lc code=end
