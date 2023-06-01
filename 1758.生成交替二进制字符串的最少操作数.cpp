/*
 * @lc app=leetcode.cn id=1758 lang=cpp
 *
 * [1758] 生成交替二进制字符串的最少操作数
 */

// @lc code=start
class Solution
{
public:
    int minOperations(string s)
    {
        int n = s.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != ('0' + i % 2))
                cnt++;
        }
        return min(cnt, n - cnt);
    }
};
// @lc code=end
