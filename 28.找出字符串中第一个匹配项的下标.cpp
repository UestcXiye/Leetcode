/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start

// 暴力

// class Solution
// {
// public:
//     int strStr(string haystack, string needle)
//     {
//         // 特判
//         if (haystack == needle)
//             return 0;
//         if (haystack.size() < needle.size())
//             return -1;
//         int n = haystack.size();
//         for (int i = 0; i <= n - needle.size(); i++)
//             if (haystack.substr(i, needle.size()) == needle)
//                 return i;
//         return -1;
//     }
// };

// KMP算法

class Solution
{
private:
    // 辅函数 - 计算 p 在 t 中第一次出现的位置
    int KMP(string &t, string &p)
    {
        int k = -1;
        vector<int> next(p.size(), -1); // -1 表示不存在相同的最大前缀和后缀
        getNext(p, next);               // 计算 next 数组
        for (int i = 0; i < t.size(); i++)
        {
            while (k > -1 && p[k + 1] != t[i])
                k = next[k]; // 有部分匹配，往前回溯
            if (p[k + 1] == t[i])
                k++;
            if (k == p.size() - 1)
                return i - p.size() + 1; // 说明 k 移动到 p 的最末端，返回相应的位置
        }
        return -1;
    }
    // 辅函数 - 计算 next 数组
    void getNext(const string &s, vector<int> &next)
    {
        for (int j = 1, p = -1; j < s.size(); j++)
        {
            while (p > -1 && s[p + 1] != s[j])
                p = next[p]; // 如果下一位不同，往前回溯
            if (s[p + 1] == s[j])
                p++; // 如果下一位相同，更新相同的最大前缀和最大后缀长
            next[j] = p;
        }
    }

public:
    int strStr(string haystack, string needle)
    {
        return KMP(haystack, needle);
    }
};
// @lc code=end
