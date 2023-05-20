/*
 * @lc app=leetcode.cn id=1897 lang=cpp
 *
 * [1897] 重新分配字符使所有字符串都相等
 */

// @lc code=start
class Solution
{
public:
    bool makeEqual(vector<string> &words)
    {
        int n = words.size();
        int alpha[26];
        memset(alpha, 0, 26 * sizeof(int));
        for (string word : words)
            for (char c : word)
                alpha[c - 'a']++;
        for (int i = 0; i < 26; i++)
            if (alpha[i] % n != 0)
                return false;
        return true;
    }
};
// @lc code=end
