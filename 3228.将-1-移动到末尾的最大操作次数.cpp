/*
 * @lc app=leetcode.cn id=3228 lang=cpp
 *
 * [3228] 将 1 移动到末尾的最大操作次数
 */

// @lc code=start
class Solution
{
public:
    int maxOperations(string s)
    {
        int n = s.length();
        int ans = 0, cnt1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                cnt1++;
            else if (i > 0 && s[i - 1] == '1')
                ans += cnt1;
        }
        return ans;
    }
};
// @lc code=end
