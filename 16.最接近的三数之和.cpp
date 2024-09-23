/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int n = nums.size();
        int ans = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            int l = i + 1, r = n - 1;
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == target)
                    return sum;
                if (abs(sum - target) < abs(ans - target))
                    ans = sum;
                if (sum < target)
                    l++;
                else
                    r--;
            }
        }
        return ans;
    }
};

// class Solution
// {
// public:
//     int threeSumClosest(vector<int> &nums, int target)
//     {
//         int n = nums.size();
//         int closest_sum = 1e8;
//         sort(nums.begin(), nums.end());
//         for (int i = 0; i < n; i++)
//         {
//             // 优化 1：保证和上一次枚举的元素不相等
//             if (i > 0 && nums[i] == nums[i - 1])
//                 continue;
//             // 优化 2：当 nums[i] + nums[i + 1] + nums[i + 2] > target 时，不必再继续遍历下去
//             if (i < n - 2 && nums[i] + nums[i + 1] + nums[i + 2] > target)
//             {
//                 int cur_sum = nums[i] + nums[i + 1] + nums[i + 2];
//                 if (abs(cur_sum - target) < abs(closest_sum - target))
//                     closest_sum = cur_sum;
//                 break;
//             }
//             int cur_target = target - nums[i];
//             int left = i + 1, right = n - 1;
//             while (left < right)
//             {
//                 if (nums[left] + nums[right] > cur_target)
//                 {
//                     int cur_sum = nums[i] + nums[left] + nums[right];
//                     if (abs(cur_sum - target) < abs(closest_sum - target))
//                         closest_sum = cur_sum;
//                     right--;
//                 }
//                 else if (nums[left] + nums[right] < cur_target)
//                 {
//                     int cur_sum = nums[i] + nums[left] + nums[right];
//                     if (abs(cur_sum - target) < abs(closest_sum - target))
//                         closest_sum = cur_sum;
//                     left++;
//                 }
//                 else
//                     return target;
//             }
//         }
//         return closest_sum;
//     }
// };
// @lc code=end
