/*
 * @lc app=leetcode.cn id=2856 lang=cpp
 *
 * [2856] 删除数对后的最小数组长度
 */

// @lc code=start

// 哈希 + 分类讨论

// class Solution
// {
// public:
//     int minLengthAfterRemovals(vector<int> &nums)
//     {
//         // 特判
//         if (nums.empty())
//             return 0;

//         int n = nums.size();
//         // 统计数组 nums 中各元素的出现次数
//         unordered_map<int, int> cnt;
//         for (int &num : nums)
//             cnt[num]++;

//         int maxCount = 0;
//         for (auto &[_, c] : cnt)
//             maxCount = max(maxCount, c);

//         if (maxCount > n / 2)
//             return 2 * maxCount - n;
//         return n % 2;
//     }
// };

// 二分查找 + 分类讨论

class Solution
{
public:
    int minLengthAfterRemovals(vector<int> &nums)
    {
        // 特判
        if (nums.empty())
            return 0;

        int n = nums.size();
        int x = nums[n / 2];
        int maxCount = upper_bound(nums.begin(), nums.end(), x) -
                       lower_bound(nums.begin(), nums.end(), x);
        if (maxCount > n / 2)
            return 2 * maxCount - n;
        return n % 2;
    }
};
// @lc code=end
