/*
 * @lc app=leetcode.cn id=2824 lang=cpp
 *
 * [2824] 统计和小于目标的下标对数目
 */

// @lc code=start

// 遍历

// class Solution
// {
// public:
//     int countPairs(vector<int> &nums, int target)
//     {
//         int n = nums.size();
//         int count = 0;
//         for (int i = 0; i < n - 1; i++)
//             for (int j = i + 1; j < n; j++)
//                 if (nums[i] + nums[j] < target)
//                     count++;
//         return count;
//     }
// };

// 排序 + 双指针

class Solution
{
public:
    int countPairs(vector<int> &nums, int target)
    {
        // 特判
        if (nums.empty())
            return 0;

        int left = 0, right = nums.size() - 1;
        sort(nums.begin(), nums.end());
        int count = 0;
        while (left < right)
        {
            if (nums[left] + nums[right] < target)
            {
                count += right - left;
                left++;
            }
            else
                right--;
        }
        return count;
    }
};
// @lc code=end
