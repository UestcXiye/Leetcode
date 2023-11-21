/*
 * @lc app=leetcode.cn id=2216 lang=cpp
 *
 * [2216] 美化数组的最少删除数
 */

// @lc code=start
class Solution
{
public:
    int minDeletion(vector<int> &nums)
    {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n - 1; i++)
            if ((i - count) % 2 == 0 && nums[i] == nums[i + 1])
                count++;
        return (n - count) % 2 == 0 ? count : count + 1;
    }
};
// @lc code=end
