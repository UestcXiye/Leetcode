/*
 * @lc app=leetcode.cn id=2210 lang=cpp
 *
 * [2210] 统计数组中峰和谷的数量
 */

// @lc code=start
class Solution
{
public:
    int countHillValley(vector<int> &nums)
    {
        vector<int> vec;
        // 去除连续重复元素去重
        vec.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] != nums[i - 1])
                vec.push_back(nums[i]);
        int ans = 0;
        // 统计峰和谷的数量
        for (int i = 1; i < vec.size() - 1; i++)
            if ((vec[i] > vec[i - 1] && vec[i] > vec[i + 1]) ||
                (vec[i] < vec[i - 1] && vec[i] < vec[i + 1]))
                ans++;
        return ans;
    }
};
// @lc code=end
