/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
// class Solution
// {
// public:
//     vector<int> twoSum(vector<int> &numbers, int target)
//     {
//         int n = numbers.size();
//         int left = 0, right = n - 1;
//         while (left < right)
//         {
//             if (numbers[left] + numbers[right] == target)
//                 break;
//             else if (numbers[left] + numbers[right] < target)
//                 left++;
//             else
//                 right--;
//         }
//         return vector<int>{left + 1, right + 1};
//     }
// };
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int n = numbers.size();
        vector<int> ans(2, 0);
        for (int i = 0; i < n; i++)
        {
            int left = i + 1, right = n - 1;
            while (left <= right)
            {
                int mid = (left + right) / 2;
                if (numbers[i] + numbers[mid] > target)
                    right = mid - 1;
                else if (numbers[i] + numbers[mid] < target)
                    left = mid + 1;
                else
                {
                    ans[0] = i + 1;
                    ans[1] = mid + 1;
                    return ans;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
