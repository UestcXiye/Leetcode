/*
 * @lc app=leetcode.cn id=1422 lang=cpp
 *
 * [1422] 分割字符串的最大得分
 */

// @lc code=start
class Solution
{
public:
    int maxScore(string s)
    {
        int n = s.size(), max_score = 0;
        for (int i = 1; i < n; i++)
        {
            string leftStr = s.substr(0, i), rightStr = s.substr(i, n - i);
            int score = countZero(leftStr) + countOne(rightStr);
            max_score = max(max_score, score);
        }
        return max_score;
    }
    // 辅函数 - 计算字符串 s 中 0 的数量
    int countZero(const string &s)
    {
        int count = 0;
        for (const char &c : s)
            if (c == '0')
                count++;
        return count;
    }
    // 辅函数 - 计算字符串 s 中 1 的数量
    int countOne(const string &s)
    {
        int count = 0;
        for (const char &c : s)
            if (c == '1')
                count++;
        return count;
    }
};
// @lc code=end
