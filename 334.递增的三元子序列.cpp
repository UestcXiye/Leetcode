/*
 * @lc app=leetcode.cn id=334 lang=cpp
 *
 * [334] 递增的三元子序列
 */

//@lc code = start
// class Solution
// {
// public:
//     bool increasingTriplet(vector<int> &nums)
//     {
//         if (nums.size() < 3)
//             return false;
//         int n = nums.size();
//         // leftMin[i] 表示 nums[0,...,i] 的最小值
//         vector<int> leftMin(n);
//         leftMin[0] = nums[0];
//         for (int i = 1; i < n; i++)
//             leftMin[i] = min(leftMin[i - 1], nums[i]);
//         // rightMax[i] 表示 nums[i,...,n-1] 的最大值
//         vector<int> rightMax(n);
//         rightMax[n - 1] = nums[n - 1];
//         for (int i = n - 2; i >= 0; i--)
//             rightMax[i] = max(rightMax[i + 1], nums[i]);

//         for (int i = 1; i < n - 1; i++)
//         {
//             // 找到一个递增三元组
//             if (nums[i] > leftMin[i - 1] && nums[i] < rightMax[i + 1])
//                 return true;
//         }
//         return false;
//     }
// };

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        if (nums.size() < 3)
            return false;
        // 递增子序列的第一个数和第二个数
        int first = INT_MAX, second = INT_MAX;
        for (int &num : nums)
        {
            if (num > second) // 找到了三元组
                return true;
            else if (num <= first)
            { // 帮我们扩大了 second 的可选择范围
                first = num;
            }
            else // num 位于 (first, second]
            {    // 帮我们扩大了 third 的可选择范围
                second = num;
            }
        }
        return false;
    }
};
// @lc code=end
