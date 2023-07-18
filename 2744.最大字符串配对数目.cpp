/*
 * @lc app=leetcode.cn id=2744 lang=cpp
 *
 * [2744] 最大字符串配对数目
 */

// @lc code=start
class Solution
{
public:
    int maximumNumberOfStringPairs(vector<string> &words)
    {
        int n = words.size();
        int ans = 0;
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
            {
                string rev = words[i];
                reverse(rev.begin(), rev.end());
                if (rev == words[j])
                    ans++;
            }
        return ans;
    }
};
// @lc code=end
