/*
 * @lc app=leetcode.cn id=3254 lang=cpp
 *
 * [3254] 长度为 K 的子数组的能量值 I
 */

// @lc code=start
class Solution
{
public:
    vector<int> resultsArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i <= n - k; i++)
        {
            bool flag = true;
            for (int j = i + 1; j < i + k && flag; j++)
                if (nums[j] != nums[j - 1] + 1)
                    flag = false;
            if (flag)
                ans.push_back(nums[i + k - 1]);
            else
                ans.push_back(-1);
        }
        return ans;
    }
};
// @lc code=end
