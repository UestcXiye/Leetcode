/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start

// 1. 左闭右开写法

// class Solution
// {
// private:
//     // 辅函数
//     int lower_bound(vector<int> &nums, int target)
//     {
//         int n = nums.size();
//         int left = 0, right = n;
//         while (left < right)
//         {
//             int mid = left + (right - left) / 2;
//             if (nums[mid] >= target)
//                 right = mid;
//             else
//                 left = mid + 1;
//         }
//         return left; // right 也行
//     }
//     // 辅函数
//     int upper_bound(vector<int> &nums, int target)
//     {
//         int n = nums.size();
//         int left = 0, right = n;
//         while (left < right)
//         {
//             int mid = left + (right - left) / 2;
//             if (nums[mid] > target)
//                 right = mid;
//             else
//                 left = mid + 1;
//         }
//         return left;
//     }

// public:
//     // 主函数
//     vector<int> searchRange(vector<int> &nums, int target)
//     {
//         if (nums.empty())
//             return {-1, -1};
//         int lower = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
//         int upper = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
//         // int lower = lower_bound(nums, target);
//         // int upper = upper_bound(nums, target) - 1; // 这里需要减 1 位
//         if (lower == nums.size() || nums[lower] != target)
//             return {-1, -1};
//         return {lower, upper};
//     }
// };

// 2. 左闭右闭写法

// class Solution
// {
// private:
//     // 辅函数
//     int lower_bound(vector<int> &nums, int target)
//     {
//         int n = nums.size();
//         int left = 0, right = n - 1;
//         while (left <= right)
//         {
//             int mid = left + (right - left) / 2;
//             if (nums[mid] >= target)
//                 right = mid - 1;
//             else
//                 left = mid + 1;
//         }
//         return left;
//     }

// public:
//     // 主函数
//     vector<int> searchRange(vector<int> &nums, int target)
//     {
//         int lower = lower_bound(nums, target);

//         if (lower == nums.size() || nums[lower] != target)
//             return {-1, -1};

//         int upper = lower_bound(nums, target + 1) - 1; // 这里需要减 1 位

//         return {lower, upper};
//     }
// };

// 3. 左开右开写法

class Solution
{
private:
    // 辅函数
    int lower_bound(vector<int> &nums, int target)
    {
        int n = nums.size();
        int left = -1, right = n;
        while (left + 1 < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid;
            else
                right = mid;
        }
        return right;
    }

public:
    // 主函数
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int lower = lower_bound(nums, target);

        if (lower == nums.size() || nums[lower] != target)
            return {-1, -1};

        int upper = lower_bound(nums, target + 1) - 1; // 这里需要减 1 位

        return {lower, upper};
    }
};
// @lc code=end
