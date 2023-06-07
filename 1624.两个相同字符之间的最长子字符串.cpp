/*
 * @lc app=leetcode.cn id=1624 lang=cpp
 *
 * [1624] 两个相同字符之间的最长子字符串
 */

// @lc code=start
class Solution
{
public:
    int maxLengthBetweenEqualCharacters(string s)
    {
        int n = s.size();
        vector<int> firstIndex(26, -1);
        int maxLength = -1;
        for (int i = 0; i < n; i++)
        {
            if (firstIndex[s[i] - 'a'] == -1)
                firstIndex[s[i] - 'a'] = i;
            else
                maxLength = max(maxLength, i - firstIndex[s[i] - 'a'] - 1);
        }
        return maxLength;
    }
};
// @lc code=end
