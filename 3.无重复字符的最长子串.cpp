/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start

// 滑动窗口

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.empty())
            return 0;
        int n = s.size(), maxLen = 0, left = 0;
        unordered_set<char> occurred;
        for (int i = 0; i < n; i++)
        {
            while (occurred.find(s[i]) != occurred.end()) // s[i] 在哈希表中存在
            {
                occurred.erase(s[left]);
                left++;
            }
            maxLen = max(maxLen, i - left + 1);
            occurred.insert(s[i]);
        }
        return maxLen;
    }
};
// @lc code=end
