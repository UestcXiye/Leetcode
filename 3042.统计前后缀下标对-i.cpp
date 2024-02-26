/*
 * @lc app=leetcode.cn id=3042 lang=cpp
 *
 * [3042] 统计前后缀下标对 I
 */

// @lc code=start
class Solution
{
public:
    int countPrefixSuffixPairs(vector<string> &words)
    {
        if (words.empty())
            return 0;

        int n = words.size(), count = 0;
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
            {
                int len1 = words[i].size(), len2 = words[j].size();
                if (len1 <= len2)
                    if (words[i] == words[j].substr(0, len1) &&
                        words[i] == words[j].substr(len2 - len1))
                        count++;
            }
        return count;
    }
};
// @lc code=end
