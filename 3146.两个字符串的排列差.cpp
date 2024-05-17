/*
 * @lc app=leetcode.cn id=3146 lang=cpp
 *
 * [3146] 两个字符串的排列差
 */

// @lc code=start
class Solution
{
public:
    int findPermutationDifference(string s, string t)
    {
        int n = s.length();
        int diff = 0;
        unordered_map<char, int> idx;
        for (int i = 0; i < n; i++)
            idx[s[i]] = i;
        for (int i = 0; i < n; i++)
            diff += abs(i - idx[t[i]]);
        return diff;
    }
};
// @lc code=end
