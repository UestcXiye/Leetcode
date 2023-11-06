/*
 * @lc app=leetcode.cn id=1399 lang=cpp
 *
 * [1399] 统计最大组的数目
 */

// @lc code=start
class Solution
{
public:
    int countLargestGroup(int n)
    {
        unordered_map<int, int> hash;
        int maxGroupSize = 0;
        for (int x = 1; x <= n; x++)
        {
            int key = digitSum(x);
            hash[key]++;
            maxGroupSize = max(maxGroupSize, hash[key]);
        }
        int count = 0;
        for (auto &[key, value] : hash)
            if (value == maxGroupSize)
                count++;
        return count;
    }
    // 辅函数 - 计算 x 的数位和
    int digitSum(int x)
    {
        int sum = 0;
        while (x)
        {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
};
// @lc code=end
