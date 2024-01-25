/*
 * @lc app=leetcode.cn id=2855 lang=cpp
 *
 * [2855] 使数组成为递增数组的最少右移次数
 */

// @lc code=start

// 暴力

class Solution
{
public:
    int minimumRightShifts(vector<int> &nums)
    {
        // 特判
        if (is_sorted(nums.begin(), nums.end()))
            return 0;

        int n = nums.size();

        // 枚举右移次数
        for (int i = 1; i < n; i++)
        {
            int x = nums.back();
            nums.pop_back();
            nums.insert(nums.begin(), x);
            if (is_sorted(nums.begin(), nums.end()))
                return i;
        }
        
        return -1;
    }
};

// 一次遍历

// class Solution
// {
// public:
//     int minimumRightShifts(vector<int> &nums)
//     {
//         int n = nums.size();
//         int k = -1;
//         for (int i = 0; i < n; i++)
//         {
//             if (nums[(i + 1) % n] < nums[i])
//             {
//                 if (k == -1)
//                     k = i;
//                 else
//                     return -1;
//             }
//         }
//         return k == -1 ? 0 : n - k - 1;
//     }
// };
// @lc code=end
