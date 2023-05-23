/*
 * @lc app=leetcode.cn id=665 lang=cpp
 *
 * [665] 非递减数列
 */

// @lc code=start
class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        if (nums.size() <= 2)
            return true;
        int n = nums.size();
        bool flag = nums[0] <= nums[1] ? true : false; // 标识是否还能修改
        // 遍历时，每次需要看连续的三个元素
        for (int i = 1; i < n - 1; i++)
        {
            if (nums[i] > nums[i + 1]) // 出现递减
            {
                if (flag) // 如果还有修改机会，进行修改
                {
                    if (nums[i + 1] >= nums[i - 1])
                    { // 修改方案1：将nums[i]缩小至nums[i + 1]
                        nums[i] = nums[i + 1];
                    }
                    else
                    { // 修改方案2：将nums[i + 1]放大至nums[i]
                        nums[i + 1] = nums[i];
                    }
                    flag = false; // 用掉唯一的修改机会
                }
                else // 没有修改机会，直接结束
                    return false;
            }
        }
        return true;
    }
};
// class Solution
// {
// public:
//     bool checkPossibility(vector<int> &nums)
//     {
//         int n = nums.size();
//         for (int i = 0; i < n - 1; i++)
//         {
//             int x = nums[i], y = nums[i + 1];
//             if (x > y)
//             {
//                 nums[i] = y;
//                 if (is_sorted(nums.begin(), nums.end()))
//                 {
//                     return true;
//                 }
//                 nums[i] = x; // 复原
//                 nums[i + 1] = x;
//                 return is_sorted(nums.begin(), nums.end());
//             }
//         }
//         return true;
//     }
// };
// @lc code=end
