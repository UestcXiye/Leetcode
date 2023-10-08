/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start

// 回溯

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> comb;
        backtracking(ans, nums, 0, n, comb);
        return ans;
    }
    // 辅函数 - 回溯
    void backtracking(vector<vector<int>> &ans, vector<int> &nums, int level, int n, vector<int> &comb)
    {
        if (level == n)
        {
            ans.push_back(comb);
            return;
        }
        comb.push_back(nums[level]);
        backtracking(ans, nums, level + 1, n, comb);
        comb.pop_back();
        backtracking(ans, nums, level + 1, n, comb);
    }
};

// 二进制数枚举

// class Solution
// {
// public:
//     vector<vector<int>> subsets(vector<int> &nums)
//     {
//         int n = nums.size();
//         vector<vector<int>> ans;
//         for (int mask = 0; mask < (1 << n); mask++)
//         {
//             vector<int> v;
//             for (int i = 0; i < n; i++)
//                 if (mask & (1 << i))
//                     v.push_back(nums[i]);
//             ans.push_back(v);
//         }
//         return ans;
//     }
// };

// @lc code=end
