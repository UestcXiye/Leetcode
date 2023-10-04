/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start

// Runtime Error

// class Solution
// {
// public:
//     vector<vector<int>> fourSum(vector<int> &nums, int target)
//     {
//         int n = nums.size();
//         set<vector<int>> ans_set;
//         for (int i = 0; i < n - 3; i++)
//             for (int j = i + 1; j < n - 2; j++)
//                 for (int k = j + 1; k < n - 1; k++)
//                     for (int l = k + 1; l < n; l++)
//                         if (nums[i] + nums[j] + nums[k] + nums[l] == target)
//                         {
//                             vector<int> comb{nums[i], nums[j], nums[k], nums[l]};
//                             sort(comb.begin(), comb.end());
//                             ans_set.insert(comb);
//                         }
//         vector<vector<int>> ans(ans_set.begin(), ans_set.end());
//         return ans;
//     }
// };

// 双指针

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        if (nums.size() < 4)
            return {};
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> ans_set;
        for (int i = 0; i < n - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            if ((long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
                break;
            if ((long)nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target)
                continue;
            for (int j = i + 1; j < n - 2; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                if ((long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
                    break;
                if ((long)nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target)
                    continue;
                int cur_target = target - nums[i] - nums[j];
                int left = j + 1, right = n - 1;
                while (left < right)
                {
                    if (nums[left] + nums[right] > cur_target)
                        right--;
                    else if (nums[left] + nums[right] < cur_target)
                        left++;
                    else
                    {
                        vector<int> combine = {nums[i], nums[j], nums[left], nums[right]};
                        ans_set.insert(combine);
                        left++;
                        right--;
                    }
                }
            }
        }
        vector<vector<int>> ans(ans_set.begin(), ans_set.end());
        return ans;
    }
};
// @lc code=end
