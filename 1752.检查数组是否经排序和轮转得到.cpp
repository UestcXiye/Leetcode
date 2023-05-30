/*
 * @lc app=leetcode.cn id=1752 lang=cpp
 *
 * [1752] 检查数组是否经排序和轮转得到
 */

// @lc code=start
class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int t = 0;
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (t > 1)
                return false; // 如果出现超过1次的“非递增”情况，则直接返回false
            if (nums[i - 1] > nums[i])
                t++; // 如果出现“非递增”情况，则t加1
        }
        return t == 0 || (t == 1 && nums[0] >= nums[n - 1]);
    }
};
// @lc code=end
