/*
 * @lc app=leetcode.cn id=942 lang=cpp
 *
 * [942] 增减字符串匹配
 */

// @lc code=start
class Solution
{
public:
    vector<int> diStringMatch(string s)
    {
        int n = s.length();
        vector<int> perm(n + 1, 0);
        int low = 0, high = n;
        for (int i = 0; i < n; i++)
            perm[i] = s[i] == 'I' ? low++ : high--;
        perm[n] = low;
        return perm;
    }
};
// @lc code=end
