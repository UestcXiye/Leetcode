/*
 * @lc app=leetcode.cn id=3091 lang=cpp
 *
 * [3091] 执行操作使数据元素之和大于等于 K
 */

// @lc code=start
class Solution
{
public:
    int minOperations(int k)
    {
        // 特判
        if (k <= 1)
            return 0;

        int minOps = INT_MAX;
        for (int num = 1; num <= k; num++)
        {
            int add = num - 1;
            int copy = ceil(1.0 * k / num) - 1;
            minOps = min(minOps, add + copy);
        }
        return minOps;
    }
};
// @lc code=end
