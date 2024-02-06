/*
 * @lc app=leetcode.cn id=3028 lang=cpp
 *
 * [3028] 边界上的蚂蚁
 */

// @lc code=start
// class Solution
// {
// public:
//     int returnToBoundaryCount(vector<int> &nums)
//     {
//         int count = 0;
//         int sum = 0;
//         for (int &num : nums)
//         {
//             sum += num;
//             if (!sum)
//                 count++;
//         }
//         return count;
//     }
// };

class Solution
{
public:
    int returnToBoundaryCount(vector<int> &nums)
    {
        int count = 0;
        for (int i = 1; i <= nums.size(); i++)
            if (accumulate(nums.begin(), nums.begin() + i, 0) == 0)
                count++;
        return count;
    }
};
// @lc code=end
