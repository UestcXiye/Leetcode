/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start

// 性质1：x ^ x = 0
// 性质2：x ^ 0s = x

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (int &num : nums)
            ans ^= num;
        return ans;
    }
};

// 哈希

// class Solution
// {
// public:
//     int singleNumber(vector<int> &nums)
//     {
//         unordered_map<int, int> umap;
//         for (int &num : nums)
//             umap[num]++;
//         int ans = 0;
//         for (auto &[num, count] : umap)
//             if (count == 1)
//                 ans = num;
//         return ans;
//     }
// };
// @lc code=end
