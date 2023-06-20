/*
 * @lc app=leetcode.cn id=1528 lang=cpp
 *
 * [1528] 重新排列字符串
 */

// @lc code=start
class Solution
{
public:
    string restoreString(string s, vector<int> &indices)
    {
        int n = s.size();
        string ans(n, 0);
        for (int i = 0; i < n; i++)
            ans[indices[i]] = s[i];
        return ans;
    }
};
// @lc code=end
