/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

// @lc code=start

// class Solution
// {
// public:
//     int missingNumber(vector<int> &nums)
//     {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         for (int i = 0; i < n; i++)
//             if (nums[i] != i)
//                 return i;
//         return n;
//     }
// };

// class Solution
// {
// public:
//     int missingNumber(vector<int> &nums)
//     {
//         unordered_set<int> uset;
//         int n = nums.size();
//         for (int i = 0; i < n; i++)
//             uset.insert(nums[i]);
//         for (int i = 0; i < n; i++)
//             if(!uset.count(i))
//                 return i;
//         return n;
//     }
// };

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        return n * (n + 1) / 2 - accumulate(nums.begin(), nums.end(), 0);
    }
};
// @lc code=end
