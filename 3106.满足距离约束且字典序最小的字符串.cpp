/*
 * @lc app=leetcode.cn id=3106 lang=cpp
 *
 * [3106] 满足距离约束且字典序最小的字符串
 */

// @lc code=start
class Solution
{
public:
    string getSmallestString(string s, int k)
    {
        // 特判
        if (k == 0)
            return s;

        for (char &c : s)
        {
            if (c == 'a')
                continue;
            int minD = min(c - 'a', 'a' + 26 - c);
            if (k >= minD)
            {
                c = 'a';
                k -= minD;
            }
            else
            {
                c -= k;
                break;
            }
        }
        return s;
    }
};
// @lc code=end
