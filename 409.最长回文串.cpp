/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */

// @lc code=start
class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> hash;
        bool used = false;
        for (char &c : s)
            hash[c]++;
        int len = 0;
        for (auto it = hash.begin(); it != hash.end(); it++)
        {
            if (it->second % 2 == 1)
            {
                if (used == false)
                {
                    len += it->second;
                    used = true;
                }
                else
                {
                    len += it->second - 1;
                }
            }
            else
                len += it->second;
        }
        return len;
    }
};
// @lc code=end
