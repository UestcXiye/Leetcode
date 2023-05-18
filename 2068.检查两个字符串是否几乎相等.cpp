/*
 * @lc app=leetcode.cn id=2068 lang=cpp
 *
 * [2068] 检查两个字符串是否几乎相等
 */

// @lc code=start
class Solution
{
public:
    bool checkAlmostEquivalent(string word1, string word2)
    {
        int alpha1[26], alpha2[26];
        memset(alpha1, 0, 26 * sizeof(int));
        memset(alpha2, 0, 26 * sizeof(int));
        for (char c : word1)
            alpha1[c - 'a']++;
        for (char c : word2)
            alpha2[c - 'a']++;
        for (int i = 0; i < 26; i++)
            if (abs(alpha1[i] - alpha2[i]) > 3)
                return false;
        return true;
    }
};
// @lc code=end
