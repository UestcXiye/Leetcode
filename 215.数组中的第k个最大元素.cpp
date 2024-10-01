/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start

// 排序

// class Solution
// {
// public:
//     int findKthLargest(vector<int> &nums, int k)
//     {
//         if (k > nums.size())
//             return -1;

//         sort(nums.begin(), nums.end(), greater<int>());
//         return nums[k - 1];
//     }
// };

// 堆

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int> pq;
        for (int &num : nums)
            pq.push(num);
        for (int i = 0; i < k - 1; i++)
            pq.pop();
        return pq.top();
    }
};

// 快速选择

// class Solution
// {
// public:
//     int findKthLargest(vector<int> &nums, int k)
//     {
//         int n = nums.size();
//         int l = 0, r = n - 1, target = n - k;
//         while (l < r)
//         {
//             int mid = quickSelection(nums, l, r);
//             if (mid == target)
//                 return nums[mid];
//             if (mid < target)
//                 l = mid + 1;
//             else
//                 r = mid - 1;
//         }
//         return nums[l];
//     }
//     // 辅函数- 快速选择
//     int quickSelection(vector<int> &nums, int l, int r)
//     {
//         int i = l + 1, j = r;
//         while (true)
//         {
//             while (i < r && nums[i] <= nums[l])
//                 i++;
//             while (j > l && nums[j] >= nums[l])
//                 j--;
//             if (i >= j)
//                 break;
//             swap(nums[i], nums[j]);
//         }
//         swap(nums[l], nums[j]);
//         return j;
//     }
// };
// @lc code=end
