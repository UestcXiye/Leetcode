/*
 * @lc app=leetcode.cn id=2490 lang=cpp
 *
 * [2490] 回环句
 */

// @lc code=start
class Solution
{
public:
    bool isCircularSentence(string sentence)
    {
        int n = sentence.size();
        if (sentence[0] != sentence[n - 1])
            return false;
        for (int i = 0; i < n; i++)
            if (sentence[i] == ' ')
                if (sentence[i - 1] != sentence[i + 1])
                    return false;
        return true;
    }
};
// @lc code=end
