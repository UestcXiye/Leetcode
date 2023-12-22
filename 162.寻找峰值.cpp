/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start

// 二分查找

// class Solution
// {
// public:
//     int findPeakElement(vector<int> &nums)
//     {
//         int n = nums.size();
//         int left = 0, right = n - 1;
//         int ans = -1;
//         while (left <= right)
//         {
//             int mid = (left + right) / 2;
//             // 辅助函数，输入下标 i，返回一个二元组 (0/1, nums[i])
//             // 方便处理 nums[-1] 以及 nums[n] 的边界情况
//             function<pair<int, int>(int)> get = [&](int index) -> pair<int, int>
//             {
//                 if (index == -1 || index == n)
//                     return {0, 0};
//                 return {1, nums[index]};
//             };
//             if (get(mid - 1) < get(mid) && get(mid) > get(mid + 1))
//             {
//                 ans = mid;
//                 break;
//             }
//             if (get(mid) < get(mid + 1))
//                 left = mid + 1;
//             else
//                 right = mid - 1;
//         }
//         return ans;
//     }
// };

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[mid + 1])
                right = mid; // 峰顶行号 <= i
            else
                left = mid + 1; // 峰顶行号 > i
        }
        return left;
    }
};
// @lc code=end
