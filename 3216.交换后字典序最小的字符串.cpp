/*
 * @lc app=leetcode.cn id=3216 lang=cpp
 *
 * [3216] 交换后字典序最小的字符串
 */

// @lc code=start
class Solution
{
public:
    string getSmallestString(string s)
    {
        int n = s.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] > s[i + 1] && check(s[i] - '0', s[i + 1] - '0'))
            {
                swap(s[i], s[i + 1]);
                return s;
            }
        }
        return s;
    }
    // 辅函数
    bool check(int a, int b)
    {
        return a % 2 == b % 2;
    }
};
// @lc code=end
