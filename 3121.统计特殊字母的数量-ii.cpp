/*
 * @lc app=leetcode.cn id=3121 lang=cpp
 *
 * [3121] 统计特殊字母的数量 II
 */

// @lc code=start
class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
        vector<bool> lower(26, 0), upper(26, 0);
        vector<int> lowerLastIdx(26, -1), upperFirstIdx(26, -1);
        for (int i = 0; i < word.size(); i++)
        {
            char c = word[i];
            if (islower(c))
            {
                lower[c - 'a'] = true;
                lowerLastIdx[c - 'a'] = i;
            }
            else
            {
                upper[c - 'A'] = true;
                if (upperFirstIdx[c - 'A'] == -1)
                    upperFirstIdx[c - 'A'] = i;
            }
        }
        int cnt = 0;
        for (int i = 0; i < 26; i++)
            if (lower[i] && upper[i] && lowerLastIdx[i] < upperFirstIdx[i])
                cnt++;
        return cnt;
    }
};
// @lc code=end
