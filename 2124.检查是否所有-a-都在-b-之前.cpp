/*
 * @lc app=leetcode.cn id=2124 lang=cpp
 *
 * [2124] 检查是否所有 A 都在 B 之前
 */

// @lc code=start
class Solution
{
public:
    bool checkString(string s)
    {
        int n = s.size();
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (s[i] == 'b' && s[j] == 'a')
                    return false;
        return true;
    }
};
// @lc code=end
