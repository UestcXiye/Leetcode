/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start

// 双指针

// class Solution
// {
// public:
//     int removeDuplicates(vector<int> &nums)
//     {
//         // 特判
//         if (nums.size() <= 2)
//             return nums.size();
//         int n = nums.size();
//         // 慢指针表示经过处理的数组的长度，快指针表示已经检查过的数组的长度
//         int slow = 2, fast = 2;
//         while (fast < n)
//         {
//             if (nums[slow - 2] != nums[fast])
//             {
//                 nums[slow] = nums[fast];
//                 slow++;
//             }
//             fast++;
//         }
//         return slow;
//     }
// };

class Solution
{
public:
    int work(vector<int> &nums, int k)
    {
        int len = 0;
        for (auto num : nums)
            if (len < k || nums[len - k] != num)
                nums[len++] = num;
        return len;
    }
    int removeDuplicates(vector<int> &nums)
    {
        return work(nums, 2);
    }
};

// @lc code=end
