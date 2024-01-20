/*
 * @lc app=leetcode.cn id=2824 lang=cpp
 *
 * [2824] 统计和小于目标的下标对数目
 */

// @lc code=start

// 遍历

class Solution
{
public:
    int countPairs(vector<int> &nums, int target)
    {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (nums[i] + nums[j] < target)
                    count++;
        return count;
    }
};
// @lc code=end
