/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start

// 双指针

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        if (nums.size() < 3)
            return {};
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> ans_set;
        for (int i = 0; i < n - 2; i++)
        {
            int target = -nums[i];
            int left = i + 1, right = n - 1;
            while (left < right)
            {
                if (nums[left] + nums[right] > target)
                    right--;
                else if (nums[left] + nums[right] < target)
                    left++;
                else
                {
                    vector<int> combine = {nums[i], nums[left], nums[right]};
                    ans_set.insert(combine);
                    left++;
                    right--;
                }
            }
        }
        vector<vector<int>> ans(ans_set.begin(), ans_set.end());
        return ans;
    }
};
// @lc code=end
