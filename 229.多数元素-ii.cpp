/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 多数元素 II
 */

// @lc code=start
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        ranges::sort(nums);
        vector<int> ans;
        int i = 0;
        while (i < n)
        {
            int j = i + 1;
            while (j < n && nums[j] == nums[i])
                j++;
            // [i, j-1] 是一个区间
            if (j - i > n / 3)
                ans.push_back(nums[i]);
            i = j;
        }
        return ans;
    }
};
// @lc code=end
