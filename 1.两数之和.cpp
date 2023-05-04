/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
            {
                if (i != j && nums[i] + nums[j] == target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        return ans;
    }
};
// @lc code=end
