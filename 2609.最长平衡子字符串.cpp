/*
 * @lc app=leetcode.cn id=2609 lang=cpp
 *
 * [2609] 最长平衡子字符串
 */

// @lc code=start
class Solution
{
public:
    int findTheLongestBalancedSubstring(string s)
    {
        int n = s.size();
        int zero = 0, one = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                if (one != 0)
                {
                    one = 0;
                    zero = 1;
                }
                else
                    zero++;
            }
            else
            {
                one++;
                ans = max(ans, min(zero, one));
            }
        }
        return 2 * ans;
    }
};
// @lc code=end
