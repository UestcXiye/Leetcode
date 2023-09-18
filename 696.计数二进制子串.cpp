/*
 * @lc app=leetcode.cn id=696 lang=cpp
 *
 * [696] 计数二进制子串
 */

// @lc code=start
class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        int n = s.size();
        vector<int> counts;
        int index = 0;
        while (index < n)
        {
            char c = s[index];
            int count = 0;
            while (index < n && s[index] == c)
            {
                index++;
                count++;
            }
            counts.push_back(count);
        }
        int ans = 0;
        for (int i = 1; i < counts.size(); i++)
            ans += min(counts[i], counts[i - 1]);
        return ans;
    }
};
// @lc code=end
