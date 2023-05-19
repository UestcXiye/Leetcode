/*
 * @lc app=leetcode.cn id=1974 lang=cpp
 *
 * [1974] 使用特殊打字机键入单词的最少时间
 */

// @lc code=start
class Solution
{
public:
    int minTimeToType(string word)
    {
        int n = word.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                ans += min(abs(word[0] - 'a'), 26 - abs(word[0] - 'a'));
            else
                ans += min(abs(word[i] - word[i - 1]), 26 - abs(word[i] - word[i - 1]));
            ans += 1; // 键入指针当前指向的字符耗时1s
        }
        return ans;
    }
};
// @lc code=end
