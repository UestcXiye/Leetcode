/*
 * @lc app=leetcode.cn id=3034 lang=cpp
 *
 * [3034] 匹配模式数组的子数组数目 I
 */

// @lc code=start

class Solution
{
public:
    int countMatchingSubarrays(vector<int> &nums, vector<int> &pattern)
    {
        // 特判
        if (nums.empty() || pattern.empty())
            return 0;
        if (nums.size() <= pattern.size())
            return 0;

        int count = 0;
        int m = nums.size(), n = pattern.size();

        for (int i = 0; i < m - n; i++)
        {
            bool flag = true;
            for (int k = 0; k < n && flag; k++)
            {
                int diff = nums[i + k + 1] - nums[i + k];
                int p = getPattern(diff);
                if (p != pattern[k])
                    flag = false;
            }
            if (flag)
                count++;
        }

        return count;
    }
    // 辅函数 - 计算 pattern
    int getPattern(int diff)
    {
        if (diff == 0)
            return 0;
        return diff > 0 ? 1 : -1;
    }
};

// class Solution
// {
// public:
//     int countMatchingSubarrays(vector<int> &nums, vector<int> &pattern)
//     {
//         // 特判
//         if (nums.empty() || pattern.empty())
//             return 0;
//         if (nums.size() <= pattern.size())
//             return 0;

//         int count = 0;
//         int m = nums.size(), n = pattern.size();

//         vector<int> patterns;
//         for (int i = 0; i < m - 1; i++)
//         {
//             int diff = nums[i + 1] - nums[i];
//             int p = getPattern(diff);
//             patterns.push_back(p);
//         }

//         for (int i = 0; i < m - n; i++)
//         {
//             vector<int> temp(patterns.begin() + i, patterns.begin() + i + n);
//             if (temp == pattern)
//                 count++;
//         }

//         return count;
//     }
//     // 辅函数 - 计算 pattern
//     int getPattern(int diff)
//     {
//         if (diff == 0)
//             return 0;
//         return diff > 0 ? 1 : -1;
//     }
// };
// @lc code=end
