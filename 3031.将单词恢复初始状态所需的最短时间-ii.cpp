/*
 * @lc app=leetcode.cn id=3031 lang=cpp
 *
 * [3031] 将单词恢复初始状态所需的最短时间 II
 */

// @lc code=start

// 暴力

// class Solution
// {
// public:
//     int minimumTimeToInitialState(string word, int k)
//     {
//         string_view s = word; // 内存不溢出和不超时的关键
//         int n = s.size();
//         for (int t = 1, i = k; true; t++, i += k)
//             if (i >= n || s.substr(i) == s.substr(0, n - i))
//                 return t;
//         return -1;
//     }
// };

// Z 函数算法（拓展 KMP）

class Solution
{
public:
    int minimumTimeToInitialState(string s, int k)
    {
        int n = s.size();
        vector<int> z(n);
        int l = 0, r = 0; // Z box 的左右边界
        for (int i = 1; i < n; i++)
        {
            if (i <= r) // i 在 Z box 内
            {
                z[i] = min(z[i - l], r - i + 1);
            }
            // 继续向后暴力匹配
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            {
                l = i;
                r = i + z[i];
                z[i]++;
            }
            if (i % k == 0 && z[i] >= n - i)
            {
                return i / k;
            }
        }
        return ceil(1.0 * n / k);
    }
};
// @lc code=end
