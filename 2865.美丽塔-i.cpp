/*
 * @lc app=leetcode.cn id=2865 lang=cpp
 *
 * [2865] 美丽塔 I
 */

// @lc code=start
class Solution
{
public:
    long long maximumSumOfHeights(vector<int> &maxHeights)
    {
        int n = maxHeights.size();
        long long max_sum = 0;
        // 枚举峰值的位置
        for (int i = 0; i < n; i++)
        {
            long long cur_sum = maxHeights[i];
            // 向左求和
            int left_height = maxHeights[i];
            for (int j = i - 1; j >= 0; j--)
            {
                left_height = min(left_height, maxHeights[j]);
                cur_sum += left_height;
            }
            // 向右求和
            int right_height = maxHeights[i];
            for (int j = i + 1; j < n; j++)
            {
                right_height = min(right_height, maxHeights[j]);
                cur_sum += right_height;
            }
            // 更新答案
            max_sum = max(max_sum, cur_sum);
        }
        return max_sum;
    }
};
// @lc code=end
