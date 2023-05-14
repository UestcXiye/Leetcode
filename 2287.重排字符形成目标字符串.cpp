/*
 * @lc app=leetcode.cn id=2287 lang=cpp
 *
 * [2287] 重排字符形成目标字符串
 */

// @lc code=start
class Solution
{
public:
    int rearrangeCharacters(string s, string target)
    {
        unordered_map<char, int> sCounts, targetCounts;
        int n = s.size(), m = target.size();
        for (int i = 0; i < m; i++)
            targetCounts[target[i]]++;
        for (int i = 0; i < n; i++)
            sCounts[s[i]]++;
        int ans = __INT_MAX__;
        for (auto &[c, count] : targetCounts)
        {
            int totalCount = sCounts[c];
            ans = min(ans, totalCount / count);
        }
        return ans;
    }
};
// @lc code=end
