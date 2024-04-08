/*
 * @lc app=leetcode.cn id=3097 lang=cpp
 *
 * [3097] 或值至少为 K 的最短子数组 II
 */

// @lc code=start
// class Solution
// {
// public:
//     int minimumSubarrayLength(vector<int> &nums, int k)
//     {
//         int ans = INT_MAX;
//         vector<pair<int, int>> ors; // 保存 (右端点为 i 的子数组 OR, 该子数组左端点的最大值)
//         for (int i = 0; i < nums.size(); i++)
//         {
//             ors.emplace_back(0, i);
//             int j = 0;
//             for (auto &p : ors)
//             {
//                 auto &[or_, left] = p;
//                 or_ |= nums[i];
//                 if (or_ >= k)
//                     ans = min(ans, i - left + 1);
//                 if (ors[j].first == or_)
//                 {
//                     // 原地去重：合并相同值，左端点取靠右的
//                     ors[j].second = left;
//                 }
//                 else
//                 {
//                     ors[++j] = p;
//                 }
//             }
//             ors.resize(j + 1); // 去重：移除多余元素
//         }
//         return ans == INT_MAX ? -1 : ans;
//     }
// };

class Solution
{
public:
    int minimumSubarrayLength(vector<int> &nums, int k)
    {
        int ans = INT_MAX;
        unordered_map<int, int> d; // key 是右端点为 i 的子数组 OR, value 是该子数组左端点的最大值
        for (int i = 0; i < nums.size(); i++)
        {
            unordered_map<int, int> temp;
            for (auto &[or_, left] : d)
            {
                int new_or = or_ | nums[i];
                temp[new_or] = max(temp[new_or], left);
            }
            temp[nums[i]] = i;
            swap(d, temp);
            for (auto &[or_, left] : d)
                if (or_ >= k)
                    ans = min(ans, i - left + 1);
        }
        return ans != INT_MAX ? ans : -1;
    }
};
// @lc code=end
