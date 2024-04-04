/*
 * @lc app=leetcode.cn id=442 lang=cpp
 *
 * [442] 数组中重复的数据
 */

// @lc code=start
// class Solution
// {
// public:
//     vector<int> findDuplicates(vector<int> &nums)
//     {
//         int n = nums.size();
//         for (int i = 0; i < n; i++)
//             while (nums[i] != nums[nums[i] - 1])
//                 swap(nums[i], nums[nums[i] - 1]);
//         vector<int> ans;
//         for (int i = 0; i < n; i++)
//             if (nums[i] - 1 != i)
//                 ans.push_back(nums[i]);
//         return ans;
//     }
// };

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            int x = abs(nums[i]);
            if (nums[x - 1] > 0)
                nums[x - 1] = -nums[x - 1]; // 取反，做标记
            else
                ans.push_back(x);
        }
        return ans;
    }
};

// @lc code=end
