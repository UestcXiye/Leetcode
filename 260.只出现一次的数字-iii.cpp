/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start

// 哈希

// class Solution
// {
// public:
//     vector<int> singleNumber(vector<int> &nums)
//     {
//         // 特判
//         if (nums.size() == 2)
//             return nums;
//         unordered_map<int, int> hash;
//         for (int &num : nums)
//             hash[num]++;
//         vector<int> ans;
//         for (auto &[num, count] : hash)
//         {
//             if (count == 1)
//                 ans.push_back(num);
//             if (ans.size() == 2)
//                 break;
//         }
//         return ans;
//     }
// };

// 位运算

// 性质1: x ^ x = 0
// 性质2: x ^ 0 = x
// 性质3: n & (-n) 可以得到 n 的位级表示中最低的那一位 1（其余都为 0）

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        // 特判
        if (nums.size() == 2)
            return nums;
        // 设数组 nums 中只出现一次的两个元素分别为 x1  和 x2，
        // 如果把数组 nums 的所有元素全部异或，得到结果 x = x1 ^ x2。
        int xorSum = 0;
        for (int &num : nums)
            xorSum ^= num;
        // 使用位运算 x & -x 取出 x 的二进制表示中最低位那个 1，设其为第 l 位，
        // 那么 x1 和 x2 中的某一个数的二进制表示的第 l 位为 0，另一个数的二进制表示的第 l 位为 1。
        int lsb = (xorSum == INT_MIN ? xorSum : xorSum & (-xorSum)); // 防止溢出
        // 这样一来，我们就可以把数组 nums 中的所有元素分成两类，
        // 其中一类包含所有二进制表示的第 l 位为 0 的数，另一类包含所有二进制表示的第 l 位为 1 的数。
        int x1 = 0, x2 = 0;
        // 可以发现：
        // 1. 对于任意一个在数组 nums 中出现两次的元素，该元素的两次出现会被包含在同一类中；
        // 2. 对于任意一个在数组 nums 中只出现了一次的元素，即 x1 和 x2，它们会被包含在不同类中。
        // 如果我们将每一类的元素全部异或起来，那么其中一类会得到 x1，另一类会得到 x2
        for (int &num : nums)
        {
            if (num & lsb)
                x1 ^= num;
            else
                x2 ^= num;
        }
        return {x1, x2};
    }
};
// @lc code=end
