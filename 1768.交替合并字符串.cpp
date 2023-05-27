/*
 * @lc app=leetcode.cn id=1768 lang=cpp
 *
 * [1768] 交替合并字符串
 */

// @lc code=start
class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string ans;
        int p1 = 0, p2 = 0;
        int len1 = word1.size(), len2 = word2.size();
        while (p1 < len1 || p2 < len2)
        {
            if (p1 < len1)
                ans += word1[p1++];
            if (p2 < len2)
                ans += word2[p2++];
        }
        return ans;
    }
};
// @lc code=end
