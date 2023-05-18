/*
 * @lc app=leetcode.cn id=2027 lang=cpp
 *
 * [2027] 转换字符串的最少操作次数
 */

// @lc code=start
class Solution
{
public:
    int minimumMoves(string s)
    {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (s[i] == 'X')
            {
                ans++;
                i += 2;
            }
        return ans;
    }
};
// @lc code=end
