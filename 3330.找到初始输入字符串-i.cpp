/*
 * @lc app=leetcode.cn id=3330 lang=cpp
 *
 * [3330] 找到初始输入字符串 I
 */

// @lc code=start
class Solution
{
public:
    int possibleStringCount(string word)
    {
        int ans = 1;
        for (int i = 1; i < word.length(); i++)
            if (word[i - 1] == word[i])
                ans++;

        return ans;
    }
};
// @lc code=end
