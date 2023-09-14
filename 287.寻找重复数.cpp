/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start

// 哈希

// class Solution
// {
// public:
//     int findDuplicate(vector<int> &nums)
//     {
//         unordered_map<int, int> hash;
//         for (int &num : nums)
//         {
//             hash[num]++;
//             if (hash[num] >= 2)
//                 return num;
//         }
//         return -1;
//     }
// };

// 二分查找

// class Solution
// {
// public:
//     int findDuplicate(vector<int> &nums)
//     {
//         int n = nums.size();
//         int left = 1, right = n - 1;
//         int ans = -1;
//         while (left <= right)
//         {
//             int mid = (left + right) / 2;
//             int count = 0;
//             for (int i = 0; i < n; i++)
//                 count += nums[i] <= mid;
//             if (count <= mid)
//                 left = mid + 1;
//             else
//             {
//                 right = mid - 1;
//                 ans = mid;
//             }
//         }
//         return ans;
//     }
// };

// 快慢指针

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = 0, fast = 0;
        do
        {
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
        } while (slow != fast);
        slow = 0;
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
// @lc code=end
