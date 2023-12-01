/*
 * @lc app=leetcode.cn id=1657 lang=cpp
 *
 * [1657] 确定两个字符串是否接近
 */

// @lc code=start
class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        // 特判
        if (word1.size() != word2.size())
            return false;
        int mask1 = 0, mask2 = 0;
        vector<int> cnt1(26, 0), cnt2(26, 0);
        for (const char &c : word1)
        {
            mask1 |= 1 << (c - 'a');
            cnt1[c - 'a']++;
        }
        for (const char &c : word2)
        {
            mask2 |= 1 << (c - 'a');
            cnt2[c - 'a']++;
        }
        sort(cnt1.begin(), cnt1.end());
        sort(cnt2.begin(), cnt2.end());
        return mask1 == mask2 && cnt1 == cnt2;
    }
};
// @lc code=end
