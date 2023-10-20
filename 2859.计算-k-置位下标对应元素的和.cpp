/*
 * @lc app=leetcode.cn id=2859 lang=cpp
 *
 * [2859] 计算 K 置位下标对应元素的和
 */

// @lc code=start
class Solution
{
public:
    int sumIndicesWithKSetBits(vector<int> &nums, int k)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            if (countOne(i) == k)
                sum += nums[i];
        return sum;
    }
    // 辅函数 - 求整数 x 的置位（1）的个数
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
};
// @lc code=end
