/*
 * @lc app=leetcode.cn id=3019 lang=cpp
 *
 * [3019] 按键变更的次数
 */

// @lc code=start
class Solution
{
public:
    int countKeyChanges(string s)
    {
        // 特判
        if (s.empty())
            return 0;

        int n = s.length();
        int count = 0;
        for (int i = 0, j = 1; i < n && j < n; i++, j++)
            if (tolower(s[i]) != tolower(s[j]))
                count++;
        return count;
    }
};
// @lc code=end

