/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */

// @lc code=start

// 公式法
// g(i) = i ⊕ ⌊ i/2 ⌋

class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> gray_code(pow(2, n), 0);
        for (int i = 0; i < gray_code.size(); i++)
            gray_code[i] = i ^ (i / 2);
        return gray_code;
    }
};

// 归纳法

// class Solution
// {
// public:
//     vector<int> grayCode(int n)
//     {
//         vector<int> ret;
//         ret.reserve(1 << n);
//         ret.push_back(0);
//         for (int i = 1; i <= n; i++)
//         {
//             int m = ret.size();
//             for (int j = m - 1; j >= 0; j--)
//             {
//                 ret.push_back(ret[j] | (1 << (i - 1)));
//             }
//         }
//         return ret;
//     }
// };

// @lc code=end
