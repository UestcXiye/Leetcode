/*
 * @lc app=leetcode.cn id=3110 lang=cpp
 *
 * [3110] 字符串的分数
 */

// @lc code=start
class Solution
{
public:
    int scoreOfString(string s)
    {
        int n = s.length();
        int sum = 0;
        for (int i = 0; i < n - 1; i++)
            sum += abs(s[i + 1] - s[i]);
        return sum;
    }
};
// @lc code=end
