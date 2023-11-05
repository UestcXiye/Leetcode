/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start

// 哈希

// class Solution
// {
// public:
//     int singleNumber(vector<int> &nums)
//     {
//         unordered_map<int, int> hash;
//         for (const int &num : nums)
//             hash[num]++;
//         int ans = 0;
//         for (auto it = hash.begin(); it != hash.end(); it++)
//             if (it->second == 1)
//             {
//                 ans = it->first;
//                 break;
//             }
//         return ans;
//     }
// };

// 位运算

class Solution
{
private:
    const int BITS = 32;

public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < BITS; i++)
        {
            int cnt1 = 0;
            for (const int &num : nums)
                cnt1 += (num >> i) & 01;
            if (cnt1 % 3 == 1)
                ans |= (1 << i);
        }
        return ans;
    }
};
// @lc code=end
