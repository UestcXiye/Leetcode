/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start

// 滑动窗口

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        // 特判
        if (s1.size() > s2.size())
            return false;
        int len1 = s1.size(), len2 = s2.size();
        vector<int> cnt1(26, 0), cnt2(26, 0);
        for (int i = 0; i < len1; i++)
        {
            cnt1[s1[i] - 'a']++;
            cnt2[s2[i] - 'a']++;
        }
        if (cnt1 == cnt2)
            return true;
        for (int i = len1; i < len2; i++)
        {
            cnt2[s2[i] - 'a']++;
            cnt2[s2[i - len1] - 'a']--;
            if (cnt1 == cnt2)
                return true;
        }
        return false;
    }
};
// @lc code=end
